# --------------------------------------------- MAIN OF DD Gen ---------------------------------------------------------
# Written for Enterprise Architect Detailed Design Generator
#
# ----------------------------------------------------------------------------------------------------------------------

# -------------------------------------------------- IMPORTS -----------------------------------------------------------
from DoxyParser import Prepare_Local_Env, Doxygen_GenerateReports, Doxygen_XML_To_Dict, YFLOWGEN_GenerateGraphics, Doxy_Dict_Parser
from YFLOWGEN_swg_parser import get_data_from_YFLOWGEN_Generated_SVG_files, yflowgen_xml_to_dict
import yaml
import os
from ea_assist.ea_assist.lib.ea_generator import EAGenerator

# -------------------------------------------------- VARIABLES ---------------------------------------------------------

# Define path to config file
path_to_YAML_file = 'Detailed_Design_Generator_Config_File.yaml'

# ---------------------------------------------------- API -------------------------------------------------------------

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

    print('------------ Detailed Design Generator ------------')

    # Load YAML Config file
    yaml_config_file = YAML_Load(path_to_YAML_file)

    ea_generator = EAGenerator()

    # Call API to prepare local env
    for swComponent in os.listdir(yaml_config_file['Path to Application Folder']):
        if os.path.isdir(os.path.join(yaml_config_file['Path to Application Folder'], swComponent)):
            if swComponent in yaml_config_file['List Of Components to be analysed'] or 'all' in yaml_config_file['List Of Components to be analysed'] and swComponent not in yaml_config_file['List Of Components to be ignored']:
                print('================================================')
                print('Parsing module ' + swComponent + ' ...')
                print('================================================')
                Prepare_Local_Env(applicaton_path=yaml_config_file['Path to Application Folder'], component_name=swComponent)

                # Call API to call Doxygen Executable to generate documentation
                Doxygen_GenerateReports(tag_dict=yaml_config_file['New Tags'])

                # Call API to parse generated documentation from doxygen API
                Doxygen_Dictionary = Doxygen_XML_To_Dict()
                Parsed_Doxygen_Dictionary = Doxy_Dict_Parser(Doxygen_Dictionary, yaml_config_file)

                # Call API to generate graphics of module
                YFLOWGEN_GenerateGraphics()
                yFlowgen_Dictionary = get_data_from_YFLOWGEN_Generated_SVG_files(Parsed_Doxygen_Dictionary, swComponent)
                Parsed_yFlowgen_Dictionary = yflowgen_xml_to_dict(yFlowgen_Dictionary)

                ea_generator.sw_components_instance(swComponent, Parsed_Doxygen_Dictionary, Parsed_yFlowgen_Dictionary, yaml_config_file)


if __name__ == "__main__":
    main()
