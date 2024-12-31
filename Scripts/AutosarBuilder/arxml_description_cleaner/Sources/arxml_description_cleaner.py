# =========================================================== #
#      ARXML_duplicate_description_deleter                    #
#   Written by: David Puscasu                                 #
#   Date: 1 March 2023                                        #
#   Copyright Autoliv, RBE, 2023                              #
# =========================================================== #

import yaml
import argparse
import os

parser = argparse.ArgumentParser()
parser.add_argument('-f', '--config-file-path', help="pass the config file path", required=True)
args = parser.parse_args()
file_path = args.config_file_path
yamlConfig = yaml.safe_load(open(file_path))

projectPath = yamlConfig['projectPath']
componentsRelativePath = 'Components\\Application\\Autoliv\\'
descriptionARXMLRelativePath = 'Config\\ARXML\\Description\\'
componentsPath = os.path.join(projectPath, componentsRelativePath)

listOfComponents = yamlConfig['sw_components_list']
listOfIgnoreComponents = yamlConfig['ignore_sw_components_list']

WINDOWS_LINE_ENDING = b'\r\n'

testfolder = 'Out'

for swComponent in os.listdir(componentsPath):
    if ((swComponent in listOfComponents) or ('all' in listOfComponents)) and (swComponent not in listOfIgnoreComponents):
        descriptionARXMLPath = os.path.join(componentsPath, swComponent, descriptionARXMLRelativePath)
        for ARXMLFile in os.listdir(descriptionARXMLPath):
            if '.arxml' in ARXMLFile:
                ARXMLFilePath = os.path.join(descriptionARXMLPath, ARXMLFile)
                inARXMLFileObject = open(ARXMLFilePath, 'rb')
                ARXMLFileContentLines = inARXMLFileObject.readlines()
                inARXMLFileObject.close()
                finalARXMLFileContentBinary = b''

                startDescSection = False
                startL2Section = False
                for line in ARXMLFileContentLines:
                    if not startDescSection:
                        finalARXMLFileContentBinary += line

                        if b'<DESC' in line:
                            startDescSection = True
                            listOfL2Contents = []
                            L2Id = 0

                    else:
                        if b'</DESC>' in line:
                            finalARXMLFileContentBinary += listOfL2Contents[-1]
                            finalARXMLFileContentBinary += line

                            startDescSection = False

                        else:
                            if not startL2Section:
                                if b'<L-2' in line:
                                    L2Id += 1
                                    startL2Section = True
                                    L2Contentlines = []
                                    L2Content = b''

                            if startL2Section:
                                # if L2Id == 1:
                                #     finalARXMLFileContentBinary += line

                                # L2Contentlines.append(line)
                                L2Content += line
                                if b'</L-2>' in line:
                                    startL2Section = False
                                    listOfL2Contents.append(L2Content)

                outARXMLFileObject = open(ARXMLFilePath, 'wb')
                outARXMLFileObject.write(finalARXMLFileContentBinary)
                outARXMLFileObject.close()
                print('File "' + ARXMLFilePath + '" was edited!')