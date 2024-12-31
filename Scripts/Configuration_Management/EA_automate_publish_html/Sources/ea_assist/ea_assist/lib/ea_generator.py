import time
from shutil import Error

import re
import sys

import xml.etree.ElementTree as ET
import base64
import pyodbc
import subprocess
import os, signal
import shutil

from ..model.ea_model import (
    Package,
    EAInstance,
    Parameter,
    TaggedValue,
    PropertyType,
    Element,
    Connector,
    Diagram,
)

class EAGenerator:
    def __init__(self) -> None:
        self._pkg_interfaces_mapping = {}
        self._instance = None  # EAInstance
        self._interface_mapping = {}  # Dict[str, int]

    def kill_EA_process(self):
        call = 'TASKLIST', '/FI', 'imagename eq %s' % 'EA.exe'
        # use buildin check_output right away
        output = subprocess.check_output(call).decode()
        # check in last line for process name
        last_line = output.strip().split('\r\n')[-1]
        last_line_split = last_line.split(' ')
        last_line_words = []
        for word in last_line_split:
            if not word == '':
                last_line_words.append(word)
        PID = int(last_line_words[1])
        os.kill(PID, signal.SIGTERM)


    def sw_components_instance(self, yaml_config_file: dict):
        project_open_in_background = False
        self._instance = EAInstance()
        repository = self._instance._app.Repository
        try:
            models = repository.Models
        except:
            repository.OpenFile(yaml_config_file['EA_project_path'])
            project_open_in_background = True
            models = repository.Models

        project = repository.GetProjectInterface()

        exportTempFolder = yaml_config_file['Output_folder']
        if os.path.isdir(exportTempFolder):
            shutil.rmtree(exportTempFolder)
        os.mkdir(exportTempFolder)

        for modelIndex in range(models.Count):
            model = models.GetAt(modelIndex)
            if 'all' in yaml_config_file['EA_models_to_publish'] \
                    or model.Name in yaml_config_file['EA_models_to_publish']:
                print('Export model "' + model.Name + '" ...')

                exportPath = os.path.join(os.getcwd(), exportTempFolder, model.Name)
                os.mkdir(exportPath)

                assert isinstance(model.PackageGUID, object)
                packageGUID = project.GUIDtoXML(model.PackageGUID)
                project.RunHTMLReport(packageGUID, exportPath, '.png', '<default>', '.html')

        if project_open_in_background:
            self.kill_EA_process()
