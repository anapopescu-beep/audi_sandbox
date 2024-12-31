import zipfile
import re
import os.path

def zip_install(zip_file, install_path, verbose):
    try:
        if (not os.path.exists(install_path)):
            os.makedirs(install_path)        
        
        with zipfile.ZipFile(zip_file, 'r') as zip_ref:
            if (len(zip_ref.namelist()) > 0):
                fullname = os.path.join(install_path, zip_ref.namelist()[0])
                if (os.path.exists(fullname)):
                    if (verbose == True):
                        print("  - Unpacking %s is skipped" % zip_file)
                    return
            if (verbose == True):
                print('  - Unpacking %s into %s' % (zip_file, install_path))
            zip_ref.extractall(install_path)
    except IOError as err:
        print(str(err))

def zip_files_install(zip_files, install_path, verbose = False):
    pattern = re.compile("[,;]")
    all_zip_file = pattern.split(zip_files)
    for zip_file in all_zip_file:
        zip_file = zip_file.strip()
        zip_install(zip_file, install_path, verbose = verbose)

 