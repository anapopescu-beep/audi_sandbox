import os
import re
import sys

def search_for_whl_files(root_dir):
    results = []
    for dir_name, _, file_list in os.walk(root_dir):
        if (re.match(r'.+python.+', dir_name, re.IGNORECASE)):
            continue
        if (re.match(r'.+zipinstaller.+', dir_name, re.IGNORECASE)):
            continue
        
        for file_name in file_list:
            _, ext = os.path.splitext(file_name)
            if (ext == ".whl"):
                results.append({"path": dir_name, "file": file_name})

    return results

def get_whl_package(name: str):
    match = re.match(r"(\w*)-([\d.]*)-.*.whl", name)
    if (match):
        return (match.group(1), match.group(2))

def uninstall_whl_package(package_name: str, verbose: bool):
    if (verbose):
        os.system("pip uninstall -y %s" % package_name)
    else:
        os.system("pip uninstall -y %s > NUL" % package_name)

def whl_files_install(pip_files: str, verbose: bool):
    pattern = re.compile("[,;]")
    all_whl_file = pattern.split(pip_files)
    for whl_file in all_whl_file:
        whl_file = whl_file.strip()
        package_name, version = get_whl_package(whl_file)
        uninstall_whl_package(package_name, verbose)
        print("  * Install Python Package %s (%s)" % (package_name, version))
        if (verbose):
            os.system("pip install %s" % whl_file)
        else:
            os.system("pip install %s > NUL" % whl_file)

