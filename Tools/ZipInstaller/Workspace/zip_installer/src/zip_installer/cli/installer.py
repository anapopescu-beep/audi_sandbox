from ..install_utils.ini_parser import read_ini, search_for_ini_files
from ..install_utils.installer import zip_files_install
from ..install_utils.setting import change_path_env
from ..install_utils.pip_package import whl_files_install
import getopt, sys, os

def _usage():
    print("Install the zip package")
    print("zip_installer [-d arg] [--zip arg] [--path arg] [-h|--help] [-v|--verbose]")
    print("   -d arg       : Root path for the installation")
    print("   -h           : Show this information")
    print("   -v           : Print verbose information")

    print("   --zip arg    : The zip file name")
    print("   --path arg   : The installation path name")
    print("   --verbose    : Print verbose information")
    print("   --help       : Show this information")
    sys.exit(2)

def install_ini_package(root_path: str, verbose):
    if (root_path == ""):
        results = [{"path": os.getcwd(), "file": "setup.ini"}]
    else:
        results = search_for_ini_files(root_path)

    current_path = os.getcwd()

    for result in results:
        print("=============================================================================")
        print("  Installing %s\\%s" % (result['path'], result['file']))
        print("=============================================================================")
        try:
            os.chdir(result['path'])
            config = read_ini(result['file'])
            if ('setup' in config):
                if ('zip_file' in config['setup'] and 'install_path' in config['setup']):
                    zip_files_install(config['setup']['zip_file'], config['setup']['install_path'])
            if ('python' in config):
                if ('whl_file' in config['python']):
                    whl_files_install(config['python']['whl_file'], verbose)
            if ('env' in config):
                if ('path' in config['env']):
                    change_path_env(config['env']['path'])
        except IOError as e:
            print("I/O Error: " + e.strerror)
    
    os.chdir(current_path)

def installer_cli():

    try:
        opts, _ = getopt.getopt(sys.argv[1:], "cd:v", ["help", "verbose", "zip=", "path="])
    except getopt.GetoptError as err:
        print(str(err))  
        _usage()
    
    root_path = ""
    verbose = False
    zip_file = ""
    dst_path = ""
    for o, arg in opts:
        if o in ("-h", "--help"):
            _usage()
        elif o in ("-v", "--verbose"):
            verbose = True
        elif o in ("--zip"):
            zip_file = arg
        elif o in ("--path"):
            dst_path = arg
        elif o in ("-d"):
            root_path = arg

    if (zip_file != "" and dst_path != ""):
        zip_files_install(zip_file, dst_path, verbose = verbose)
    elif (root_path != ""):
        install_ini_package(root_path = root_path, verbose = verbose)
    else:
        _usage()
    #install_pip_package(root_path)
    

if __name__ == "__main__":
    installer_cli()
