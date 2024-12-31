from ea_assist.ea_assist.lib.ea_generator import EAGenerator
import subprocess
import yaml

# -------------------------------------------------- VARIABLES ---------------------------------------------------------

# Define path to config file
path_to_YAML_file = 'Config_EA_automate_publish_html.yaml'


def YAML_Load(path_to_YAML_file):
    # Read yaml config file
    try:
        with open(path_to_YAML_file, 'r') as stream:
            yaml_config_file = yaml.load(stream, Loader=yaml.FullLoader)
    except Exception as exception:
        print('YAML Config file could not been loaded. Exception Occured:', exception)
        print('This API will exit now!')
        exit(1)
    return yaml_config_file


def main():
    ea_generator = EAGenerator()
    ea_generator.sw_components_instance(yaml_config_file)


# Load YAML Config file
yaml_config_file = YAML_Load(path_to_YAML_file)
main()