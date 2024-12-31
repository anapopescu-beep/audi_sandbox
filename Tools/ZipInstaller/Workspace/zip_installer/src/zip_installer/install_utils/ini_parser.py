import sys
import os
from  configparser import ConfigParser

def _print_usage():
    print("Please write down the installation information in the setup.ini. \n")
    print("[setup]")
    print("zip_file        =   zip_file.zip")
    print("install_path    =   x:\\install_path")
    sys.exit(1)

def _validate(config):
    if 'setup' not in config:
        print("The section [setup] can not be found.")
        _print_usage()
    if 'zip_file' not in config['setup']:
        print("The zip_file can not be found.")
        _print_usage()
    if 'install_path' not in config['setup']:
        print("The install_path can not be found.")
        _print_usage()

def read_ini(filename):
    config = ConfigParser()
    config.read('setup.ini')

    #_validate(config)
    
    return config

def search_for_ini_files(root_dir):
    results = []
    for dir_name, _, file_list in os.walk(root_dir):
        for file_name in file_list:
            if (file_name.lower() == "setup.ini"):
                results.append({"path": dir_name, "file": file_name})

    #for result in results:
    #    print("Path: %s, File: %s" % (result['path'], result['file']))
    return results