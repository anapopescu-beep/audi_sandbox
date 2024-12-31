# --------------------------------------------- DoxyParser.py Lib ------------------------------------------------------
# Doxygen Parser Library
# Written for Enterprise Architect Detailed Design Generator
#
# ----------------------------------------------------------------------------------------------------------------------

# -------------------------------------------------- IMPORTS -----------------------------------------------------------
import os
import shutil
import subprocess

import xmltodict

# -------------------------------------------------- VARIABLES ---------------------------------------------------------

# Current directory path
CURRENT_DIRECTORY = os.getcwd()

# Path to the directory containing Doxygen output folder
PATH_TO_DOXYGEN_OUTPUT = os.path.join(CURRENT_DIRECTORY, r'Tools\doxygen\OUTPUT')

# Path to the directory containing Doxygen XML files
PATH_TO_DOXYGEN_XML_FOLDER = os.path.join(PATH_TO_DOXYGEN_OUTPUT, r'xml')

# Path to the directory containing Doxygen output folder
PATH_TO_DOXYGEN_CONFIG = os.path.join(CURRENT_DIRECTORY, r'Tools\doxygen\DOXYGEN_CONFIG_FILE')

# Path to the directory containing Doxygen executable
PATH_TO_DOXYGEN_TOOL = os.path.join(CURRENT_DIRECTORY, r'Tools\doxygen\bin\doxygen.exe')

# Temporary directory created in order to
temp_directory_path = os.path.join(os.getcwd(), 'Temp')

# yflowgen TOOL:
path_to_yflowgen_tool = os.getcwd() + r'\Tools\yFlowGen\yFlowGen.exe'
path_to_yflowgen_folder_src = os.getcwd() + r'\Tools\yFlowGen\src_code/'
path_to_yflowgen_folder_html = os.getcwd() + r'\result_yFlowGen\src_code/'

# ---------------------------------------------------- API -------------------------------------------------------------

def YFLOWGEN_GenerateGraphics():

    # COPY SOURCE FILES TO YFlowGen FOLDER TO GENERATE GRAPHICS
    # =================================================================
    # Delete all existing files from yflowgen src
    for file in os.listdir(path_to_yflowgen_folder_src):
        os.remove(os.path.join(path_to_yflowgen_folder_src, file))

    # Copy source file into mortiz folder src
    for file in os.listdir(temp_directory_path):

        # Set source and destination path
        source_path = os.path.join(temp_directory_path, file)
        destination_path = path_to_yflowgen_folder_src + file

        # Copy files with shutil
        shutil.copy(source_path, destination_path)
    # =================================================================

    print('================================================')
    print('Call yFlowGen files in order to generate graphics')
    subprocess.run(path_to_yflowgen_tool + ' -d ' + path_to_yflowgen_folder_src + ' -format dot -no_comment -true_false -no_compact', shell=False)
    print('================================================')

    # Remove temp directory
    shutil.rmtree(temp_directory_path)
    os.remove(os.path.join(CURRENT_DIRECTORY, 'result_yFlowGen.html'))
    os.remove(os.path.join(CURRENT_DIRECTORY, 'log_yFlowGen.txt'))

def Prepare_Local_Env(applicaton_path, component_name):

    component_directory = os.path.join(applicaton_path, component_name)
    design_directory = os.path.join(component_directory, "Design")
    implementation_directory = os.path.join(component_directory, "Implementation")

    # ==================================================
    # CREATE TEMPORARY DIRECTORY TO STORE SOURCE FILES
    # ==================================================
    # If directory already exist
    if os.path.exists(temp_directory_path):
        for root, dirs, files in os.walk(temp_directory_path):

            # Remove all of it's contents
            for f in files:
                os.unlink(os.path.join(root, f))
            for d in dirs:
                shutil.rmtree(os.path.join(root, d))
    else:
        # Otherwise, create it
        os.mkdir(temp_directory_path)
    # ========================================================

    # ========================================================================
    # COPY SOURCE CODE FILES FROM COMPONENT IN TEMP DIRECTORY
    # ========================================================================

    # Define flag used to check if a c_template file has been found
    template_found_flag = False

    # For every file in implementation dir
    for root, dirs, files in os.walk(design_directory):
        for file in files:

            # if a c_template file has been found
            if file.endswith('c_template'):
                print('File:', file, 'has been found, it will be proceseed.')

                # Change flag
                template_found_flag = True

                # copy only c_template files in temp folder
                source_file_path = os.path.join(root, file)
                destination_file_path = os.path.join(temp_directory_path, file)
                shutil.copy(source_file_path, destination_file_path)

                # Rename c_template file to c file
                os.rename(destination_file_path, destination_file_path.replace('c_template', 'c'))

            # if a c_template file has been found
            if file.endswith('h_template'):
                print('File:', file, 'has been found, it will be proceseed.')

                # Change flag
                template_found_flag = True

                # copy only c_template files in temp folder
                source_file_path = os.path.join(root, file)
                destination_file_path = os.path.join(temp_directory_path, file)
                shutil.copy(source_file_path, destination_file_path)

                # Rename c_template file to c file
                os.rename(destination_file_path, destination_file_path.replace('h_template', 'h'))

    # if no c_template file has been found
    if template_found_flag == False:

        print('No c_template or h_template files has been found, c and h files will be processed!')

        # for every file in implementation directory
        for root, dirs, files in os.walk(implementation_directory):
            for file in files:

                # copy c and h files in temp directory
                if file.endswith('.c') or file.endswith('.h'):
                    source_file_path = os.path.join(root, file)
                    destination_file_path = os.path.join(temp_directory_path, file)
                    shutil.copy(source_file_path, destination_file_path)

    # =============================================================================

# ==========================================================
#                   Doxygen_GenerateReports API
# Description: Doxygen runnable to generate reports
# INPUT ARGUMENT: NONE
# OUTPUT ARGUMENT: NONE ( runnable to execute doxygen.exe )
# ==========================================================
def Doxygen_GenerateReports(tag_dict):

    # RUN DOXYGEN FOR CURRENT MODULE
    # ====================================================================
    # Clear entire output folder of doxygen
    for root, dirs, files in os.walk(PATH_TO_DOXYGEN_OUTPUT):
        for f in files:
            os.unlink(os.path.join(root, f))
        for d in dirs:
            shutil.rmtree(os.path.join(root, d))

    # ----------------- MODIFY THE DOXYGEN CONFIG FILE ----------------
    # Open DOXYGEN_CONFIG_FILE to write component to analyze and read file
    f = open(PATH_TO_DOXYGEN_CONFIG, "r")
    output_config_doxygen = f.readlines()
    f.close()

    # Set in config file input path of component and output path
    new_config_output = []
    for line in output_config_doxygen:
        # Add input path
        if 'INPUT                  = ' in line:
            new_config_output.append('INPUT                  = ' + temp_directory_path + '\n')

        # Add Output path
        elif 'OUTPUT_DIRECTORY       = ' in line:
            new_config_output.append('OUTPUT_DIRECTORY       = ' + PATH_TO_DOXYGEN_OUTPUT + '\n')

        # Add new Aliases
        elif 'ALIASES                += ' in line:
            for tag_key, tag_value in tag_dict.items():

                # Construct string per every alias
                string_to_append = 'ALIASES                += ' + tag_key + '="\par ' + tag_value +  '^^"'  + '\n'

                # append string in config file
                if string_to_append not in new_config_output:
                    new_config_output.append(string_to_append)

        # Append rest of lines
        else:
            new_config_output.append(line)

    # Open DOXYGEN_CONFIG_FILE to write modified values
    f = open(PATH_TO_DOXYGEN_CONFIG, "w")
    f.writelines(new_config_output)
    f.close()

    print('================================================')
    print('Call Doxygen.exe in order to generate XML files')

    # # ----------------- RUN DOXYGEN  ----------------
    subprocess.run(PATH_TO_DOXYGEN_TOOL + ' ' + PATH_TO_DOXYGEN_CONFIG + ' > ' + PATH_TO_DOXYGEN_OUTPUT.replace('OUTPUT', '') + '\log_doxygen.txt  2>&1', shell=True)

    print('Doxygen.exe has been successfully executed!')
    print('================================================')

    # ----------------- REMODIFY THE DOXYGEN CONFIG FILE ----------------
    # Open DOXYGEN_CONFIG_FILE to write component to analyze and read file
    f = open(PATH_TO_DOXYGEN_CONFIG, "r")
    output_config_doxygen = f.readlines()
    f.close()

    # Set in config file input path of component and output path
    new_config_output = []
    for line in output_config_doxygen:
        # Add input path
        if 'INPUT                  = ' in line:
            new_config_output.append('INPUT                  = ' + '\n')

        # Add Output path
        elif 'OUTPUT_DIRECTORY       = ' in line:
            new_config_output.append('OUTPUT_DIRECTORY       = ' + '\n')

        # Add new Aliases
        elif 'ALIASES                += ' in line:
            # Construct string per every alias
            string_to_append = 'ALIASES                += ' + '\n'

            # append string in config file
            if string_to_append not in new_config_output:
                new_config_output.append(string_to_append)

        # Append rest of lines
        else:
            new_config_output.append(line)

    # Open DOXYGEN_CONFIG_FILE to write modified values
    f = open(PATH_TO_DOXYGEN_CONFIG, "w")
    f.writelines(new_config_output)
    f.close()

# ===============================================================
#                   Doxygen_XML_To_DICT API
# Description: XML parser of all doxygen dictionaries
# INPUT ARGUMENT: NONE
# OUTPUT ARGUMENT: Dict with data generated by doxygen
# ===============================================================
def Doxygen_XML_To_Dict():

    dictionary_from_xml = {}

    dictionary_from_xml['defines'] = []
    dictionary_from_xml['variables'] = []
    dictionary_from_xml['functions'] = []

    # Loop through all files and directories in the directory
    for root_dir_path, dirs, files in os.walk(PATH_TO_DOXYGEN_XML_FOLDER):
        for filename in files:
            if filename.endswith('.xml'):
                xml_file_path = os.path.join(root_dir_path, filename)

                # Open the file and read the contents
                with open(xml_file_path, 'r', encoding='utf-8', errors='ignore') as file:
                    my_xml = file.read()

                # Use xmltodict to parse and convert
                my_dict = xmltodict.parse(my_xml)

                try:
                    for doxygen_key, doxygen_value in my_dict.items():
                        for doxygen_prop_key, doxygen_prop_value in doxygen_value.items():
                            if doxygen_prop_key == 'compounddef':
                                for doxy_descrip_key, doxy_descrip_value in doxygen_prop_value.items():
                                    if 'sectiondef' in doxy_descrip_key:
                                        if type(doxy_descrip_value) is dict:
                                            for doxy_entity_key, doxy_entity_value in doxy_descrip_value.items():

                                                # MACRO PARSING
                                                if doxy_entity_key == '@kind' and doxy_entity_value == 'define':
                                                    if type(doxy_descrip_value['memberdef']) is list:
                                                        for macro_entity_data in doxy_descrip_value['memberdef']:
                                                            dictionary_from_xml['defines'].append(macro_entity_data)
                                                    else:
                                                        dictionary_from_xml['defines'].append(doxy_descrip_value['memberdef'])

                                                # FUNCTION PARSING
                                                elif doxy_entity_key == '@kind' and doxy_entity_value == 'func':
                                                    if type(doxy_descrip_value['memberdef']) is list:
                                                        for func_entity_data in doxy_descrip_value['memberdef']:
                                                            dictionary_from_xml['functions'].append(func_entity_data)
                                                    else:
                                                        dictionary_from_xml['functions'].append(doxy_descrip_value['memberdef'])

                                                # VAR PARSING
                                                elif doxy_entity_key == '@kind' and doxy_entity_value == 'var':

                                                    if type(doxy_descrip_value['memberdef']) is list:
                                                        for var_entity_data in doxy_descrip_value['memberdef']:
                                                            dictionary_from_xml['variables'].append(var_entity_data)
                                                    else:
                                                        dictionary_from_xml['functions'].append(doxy_descrip_value['memberdef'])

                                        elif type(doxy_descrip_value) is list:
                                            for entity_kind in doxy_descrip_value:
                                                for doxy_entity_key, doxy_entity_value in entity_kind.items():

                                                    # MACRO PARSING
                                                    if doxy_entity_key == '@kind' and doxy_entity_value == 'define':
                                                        if type(entity_kind['memberdef']) is list:
                                                            for macro_entity_data in entity_kind['memberdef']:
                                                                dictionary_from_xml['defines'].append(macro_entity_data)
                                                        else:
                                                            dictionary_from_xml['defines'].append(entity_kind['memberdef'])

                                                    # FUNCTION PARSING
                                                    elif doxy_entity_key == '@kind' and doxy_entity_value == 'func':
                                                        if type(entity_kind['memberdef']) is list:
                                                            for func_entity_data in entity_kind['memberdef']:
                                                                dictionary_from_xml['functions'].append(func_entity_data)
                                                        else:
                                                            dictionary_from_xml['functions'].append(entity_kind['memberdef'])

                                                    # VAR PARSING
                                                    elif doxy_entity_key == '@kind' and doxy_entity_value == 'var':
                                                        if type(entity_kind['memberdef']) is list:
                                                            for var_entity_data in entity_kind['memberdef']:
                                                                dictionary_from_xml['variables'].append(var_entity_data)
                                                        else:
                                                            dictionary_from_xml['variables'].append(entity_kind['memberdef'])
                except:
                    pass
    return dictionary_from_xml

def Doxy_Dict_Parser(dictionary_from_xml, yaml_config_file):
    parsed_defines = {}
    parsed_functions = {}
    parsed_variables = {}

    if 'defines' in dictionary_from_xml.keys():
        for define in dictionary_from_xml['defines']:
            parsed_item = {}
            parsed_item['name'] = define['name']
            try:
                if isinstance(define['initializer'], str):
                    parsed_item['initializer'] = define['initializer']
                elif isinstance(define['initializer'], dict):
                    if '#text' in define['initializer'].keys():
                        parsed_item['initializer'] = define['initializer']['#text']
                    else:
                        parsed_item['initializer'] = ''
                        print('WARN -> Define "' + define['name'] + '" initializer section was not correctly parsed!!')
                else:
                    parsed_item['initializer'] = ''
                    print('WARN -> Define "' + define['name'] + '" initializer section was not correctly parsed!!')
            except:
                parsed_item['initializer'] = ''
                print('WARN -> Define "' + define['name'] + '" has no initializer!')
            try:
                if isinstance(define['briefdescription']['para'], dict):
                    parsed_item['briefdescription'] = define['briefdescription']['para']['#text']
                    if 'ref' in define['briefdescription']['para'].keys():
                        if '#text' in define['briefdescription']['para']['ref'].keys():
                            if isinstance(define['briefdescription']['para']['ref']['#text'], str):
                                parsed_item['briefdescription'] += ' ' + define['briefdescription']['para']['ref']['#text']
                else:
                    parsed_item['briefdescription'] = define['briefdescription']['para']
            except:
                parsed_item['briefdescription'] = 'NA.'
                print('WARN -> Define "' + define['name'] + '" has no briefdescription!')
            parsed_item['briefdescription'] = processTextField(parsed_item['briefdescription'])
            parsed_defines[define['name']] = parsed_item

    if 'variables' in dictionary_from_xml.keys():
        for variable in dictionary_from_xml['variables']:
            parsed_item = {}
            parsed_item['name'] = variable['name']
            if isinstance(variable['type'], dict):
                if '#text' in variable['type'].keys():
                    parsed_item['type'] = variable['type']['#text']
                elif 'ref' in variable['type'].keys():
                    if '#text' in variable['type']['ref'].keys():
                        parsed_item['type'] = variable['type']['ref']['#text']
                    else:
                        parsed_item['type'] = 'unknownType'
                        print('WARN -> Variable "' + variable['name'] + '" has an unknown type!')
            else:
                parsed_item['type'] = variable['type']
            parsed_item['prot'] = variable['@prot']
            parsed_item['static'] = variable['@static']

            try:
                if isinstance(variable['initializer'], dict):
                    parsed_item['initializer'] = variable['initializer']['#text']
                else:
                    parsed_item['initializer'] = variable['initializer']
            except:
                parsed_item['initializer'] = ''
                print('WARN -> Variable "' + variable['name'] + '" has no initializer!')

            try:
                if isinstance(variable['definition'], dict):
                    parsed_item['definition'] = variable['definition']['#text']
                else:
                    parsed_item['definition'] = variable['definition']
            except:
                parsed_item['definition'] = ''
                print('WARN -> Variable "' + variable['name'] + '" has no definition!')

            try:
                if isinstance(variable['briefdescription']['para'], dict):
                    parsed_item['briefdescription'] = variable['briefdescription']['para']['#text']
                else:
                    parsed_item['briefdescription'] = variable['briefdescription']['para']
            except:
                parsed_item['briefdescription'] = 'NA.'
                print('WARN -> Variable "' + variable['name'] + '" has no brief description!')

            if variable['detaileddescription'] != None:
                if isinstance(variable['detaileddescription']['para'], dict):
                    if 'simplesect' in variable['detaileddescription']['para'].keys():
                        if isinstance(variable['detaileddescription']['para']['simplesect'], list):
                            for elm in variable['detaileddescription']['para']['simplesect']:
                                if elm['@kind'] == 'par':
                                    if elm['title'] == 'Initialization':
                                        try:
                                            if isinstance(elm['para']['verbatim'], dict):
                                                parsed_item['initialization'] = elm['para']['verbatim']['#text']
                                            else:
                                                parsed_item['initialization'] = elm['para']['verbatim']
                                        except:
                                            if isinstance(elm['para'], dict):
                                                parsed_item['initialization'] = elm['para']['#text']
                                            else:
                                                parsed_item['initialization'] = elm['para']
                                    if elm['title'] == 'Range':
                                        try:
                                            if isinstance(elm['para']['verbatim'], dict):
                                                parsed_item['range'] = elm['para']['verbatim']['#text']
                                            else:
                                                parsed_item['range'] = elm['para']['verbatim']
                                        except:
                                            if isinstance(elm['para'], dict):
                                                parsed_item['range'] = elm['para']['#text']
                                            else:
                                                parsed_item['range'] = elm['para']
                        else:
                            elm = variable['detaileddescription']['para']['simplesect']
                            if elm['@kind'] == 'par':
                                if elm['title'] == 'Initialization':
                                    try:
                                        if isinstance(elm['para']['verbatim'], dict):
                                            parsed_item['initialization'] = elm['para']['verbatim']['#text']
                                        else:
                                            parsed_item['initialization'] = elm['para']['verbatim']
                                    except:
                                        if isinstance(elm['para'], dict):
                                            parsed_item['initialization'] = elm['para']['#text']
                                        else:
                                            parsed_item['initialization'] = elm['para']
                                if elm['title'] == 'Range':
                                    try:
                                        if isinstance(elm['para']['verbatim'], dict):
                                            parsed_item['range'] = elm['para']['verbatim']['#text']
                                        else:
                                            parsed_item['range'] = elm['para']['verbatim']
                                    except:
                                        if isinstance(elm['para'], dict):
                                            parsed_item['range'] = elm['para']['#text']
                                        else:
                                            parsed_item['range'] = elm['para']
                    else:
                        print('WARN -> Variable "' + variable['name'] + '" has no detailed description (or some errors are present in /brief, e.g. do not use the "-" character in /brief)!')
                elif isinstance(variable['detaileddescription']['para'], list):
                    for elm1 in variable['detaileddescription']['para']:
                        if isinstance(elm1, str):
                            parsed_item['briefdescription'] += '\n' + elm1
                        elif isinstance(elm1, dict):
                            if 'simplesect' in elm1.keys():
                                for elm in elm1['simplesect']:
                                    if isinstance(elm, dict):
                                        if elm['title'] == 'Initialization':
                                            try:
                                                parsed_item['initialization'] = elm['para']['verbatim']
                                            except:
                                                parsed_item['initialization'] = elm['para']
                                        if elm['title'] == 'Range':
                                            try:
                                                parsed_item['range'] = elm['para']['verbatim']
                                            except:
                                                parsed_item['range'] = elm['para']
            else:
                print('WARN -> Variable "' + variable['name'] + '" has no detailed description (Initialization or Range)!')

            if not 'initialization' in parsed_item.keys():
                parsed_item['initialization'] = 'NA.'
            if not 'range' in parsed_item.keys():
                parsed_item['range'] = 'NA.'

            parsed_item['briefdescription'] = processTextField(parsed_item['briefdescription'])
            parsed_item['initialization'] = processTextField(parsed_item['initialization'])
            parsed_item['range'] = processTextField(parsed_item['range'])
            parsed_variables[variable['name']] = parsed_item

    if 'functions' in dictionary_from_xml.keys():
        for function in dictionary_from_xml['functions']:
            if function['name'] == "FUNC":
                if '@bodyfile' in function['location'].keys():
                    print('TODO -> Function type must be replaced with specific datatype in function "' + function['definition'] + function['argsstring'] + '" and RUN AGAIN! (file:"' + function['location']['@bodyfile'] + '" at line:"' + function['location']['@bodystart'] + '")')
                else:
                    print('TODO -> Function type must be replaced with specific datatype in function "' + function['definition'] + function['argsstring'] + '" and RUN AGAIN!')
            else:
                parsed_item = {}
                parsed_item['name'] = function['name']
                parsed_item['type'] = function['type']
                parsed_item['prot'] = function['@prot']
                parsed_item['static'] = function['@static']
                if '@explicit' in function.keys():
                    parsed_item['explicit'] = function['@explicit']
                else:
                    parsed_item['explicit'] = 'NA.'
                    print('WARN -> Function "' + function['name'] + '" has no explicit description!')
                if '@inline' in function.keys():
                    parsed_item['inline'] = function['@inline']
                else:
                    parsed_item['inline'] = 'NA.'
                    print('WARN -> Function "' + function['name'] + '" has no inline description!')
                # parsed_item['inline'] = function['@inline']
                if '@const' in function.keys():
                    parsed_item['const'] = function['@const']
                else:
                    parsed_item['const'] = 'NA.'
                    print('WARN -> Function "' + function['name'] + '" has no const description!')
                # parsed_item['const'] = function['@const']

                parsed_item['definition'] = function['definition']
                parsed_item['argsstring'] = function['argsstring']

                try:
                    if isinstance(function['briefdescription']['para'], dict):
                        parsed_item['briefdescription'] = function['briefdescription']['para']['#text']
                    else:
                        parsed_item['briefdescription'] = function['briefdescription']['para']
                except:
                    parsed_item['briefdescription'] = 'NA.'
                    print('WARN -> Function "' + function['name'] + '" has no brief description!')

                functionSimpleSect = None
                functionParameterSect = None
                if function['detaileddescription'] != None:
                    if isinstance(function['detaileddescription']['para'], dict):
                        if 'simplesect' in function['detaileddescription']['para'].keys():
                            functionSimpleSect = function['detaileddescription']['para']['simplesect']
                        if 'parameterlist' in function['detaileddescription']['para'].keys():
                            functionSimpleSect = function['detaileddescription']['para']['parameterlist']
                    elif isinstance(function['detaileddescription']['para'], list):
                        for elm in function['detaileddescription']['para']:
                            if isinstance(elm, dict):
                                if 'simplesect' in elm.keys():
                                    functionSimpleSect = elm['simplesect']
                                if 'parameterlist' in elm.keys():
                                    functionParameterSect = elm['parameterlist']
                    else:
                        print('WARN -> In function "' + function['name'] + '" the detailed description section was not correctly parsed!')
                else:
                    print('WARN -> Function "' + function['name'] + '" has no detailed description!')
                if functionSimpleSect != None:
                    inputParamsDict = {}
                    outputParamsDict = {}
                    for tag in functionSimpleSect:
                        if isinstance(tag, dict):
                            if tag['@kind'] == 'par':
                                if tag['title'] == 'InputParameters':
                                    inputParametersStr = None
                                    if isinstance(tag['para'], dict):
                                        if 'verbatim' in tag['para']:
                                            inputParametersStr = tag['para']['verbatim']
                                    elif isinstance(tag['para'], str):
                                        inputParametersStr = tag['para']

                                    if inputParametersStr != None:
                                        parametersList = inputParametersStr.split('Name:')
                                        inputParametersList = []
                                        for paramStr in parametersList:
                                            if paramStr != '':
                                                inputParametersList.append('Name:'+ paramStr)

                                        for inputParameterStr in inputParametersList:
                                            inputParamDict = {}

                                            if 'Name:' in inputParameterStr:
                                                inputParamDict['name'] = inputParameterStr.split('Name:')[1].split(';')[0].strip()
                                            else:
                                                print('WARN -> In Function "' + function['name'] + '", InputParameters tag has no attribute "Name:" !')
                                                inputParamDict['name'] = 'NA.'

                                            if 'Type:' in inputParameterStr:
                                                inputParamDict['type'] = inputParameterStr.split('Type:')[1].split(';')[0].strip()
                                            else:
                                                print('WARN -> In Function "' + function['name'] + '", InputParameters tag has no attribute "Type:" !')
                                                inputParamDict['type'] = 'NA.'

                                            if 'Description:' in inputParameterStr:
                                                inputParamDict['description'] = inputParameterStr.split('Description:')[1].split(';')[0].strip()
                                            else:
                                                print('WARN -> In Function "' + function['name'] + '", InputParameters tag has no attribute "Description:" !')
                                                inputParamDict['description'] = 'NA.'

                                            if 'Range:' in inputParameterStr:
                                                inputParamDict['range'] = inputParameterStr.split('Range:')[1].split(';')[0].strip()
                                            else:
                                                print('WARN -> In Function "' + function['name'] + '", InputParameters tag has no attribute "Range:" !')
                                                inputParamDict['range'] = 'NA.'

                                            inputParamsDict[inputParamDict['name']] = inputParamDict

                                if tag['title'] == 'OutputParameters':
                                    outputParametersStr = None
                                    if isinstance(tag['para'], dict):
                                        if 'verbatim' in tag['para']:
                                            outputParametersStr = tag['para']['verbatim']
                                    elif isinstance(tag['para'], str):
                                        outputParametersStr = tag['para']

                                    if outputParametersStr != None:
                                        parametersList = outputParametersStr.split('Name:')
                                        outputParametersList = []
                                        for paramStr in parametersList:
                                            if paramStr != '':
                                                outputParametersList.append('Name:' + paramStr)

                                        for outputParameterStr in outputParametersList:
                                            outputParamDict = {}
                                            if 'Name:' in outputParameterStr:
                                                outputParamDict['name'] = outputParameterStr.split('Name:')[1].split(';')[0].strip()
                                            else:
                                                print('WARN -> In Function "' + function['name'] + '", OutputParameters tag has no attribute "Name:" !')
                                                outputParamDict['name'] = 'NA.'

                                            if 'Type:' in outputParameterStr:
                                                outputParamDict['type'] = outputParameterStr.split('Type:')[1].split(';')[0].strip()
                                            else:
                                                print('WARN -> In Function "' + function['name'] + '", OutputParameters tag has no attribute "Type:" !')
                                                outputParamDict['type'] = 'NA.'

                                            if 'Description:' in outputParameterStr:
                                                outputParamDict['description'] = outputParameterStr.split('Description:')[1].split(';')[0].strip()
                                            else:
                                                print('WARN -> In Function "' + function['name'] + '", OutputParameters tag has no attribute "Description:" !')
                                                outputParamDict['description'] = 'NA.'

                                            if 'Range:' in outputParameterStr:
                                                outputParamDict['range'] = outputParameterStr.split('Range:')[1].split(';')[0].strip()
                                                outputParamDict['range'] = processTextField(outputParameterStr.split('Range:')[1].split(';')[0])
                                            else:
                                                print('WARN -> In Function "' + function['name'] + '", OutputParameters tag has no attribute "Range:" !')
                                                outputParamDict['range'] = 'NA.'

                                            outputParamsDict[outputParamDict['name']] = outputParamDict

                                elif tag['title'] == yaml_config_file['New Tags']['dynamicaspectcaller']:
                                    try:
                                        parsed_item['dynamicAspectCaller'] = tag['para']['verbatim']
                                    except Exception as e:
                                        parsed_item['dynamicAspectCaller'] = tag['para']
                                elif tag['title'] == yaml_config_file['New Tags']['dynamicaspectdescription']:
                                    try:
                                        parsed_item['dynamicAspectDescription'] = tag['para']['verbatim']
                                    except Exception as e:
                                        parsed_item['dynamicAspectDescription'] = tag['para']
                                elif tag['title'] == yaml_config_file['New Tags']['ddesignrequirement']:
                                    try:
                                        parsed_item['ddesignrequirement'] = tag['para']['verbatim']
                                    except Exception as e:
                                        parsed_item['ddesignrequirement'] = tag['para']
                                elif tag['title'] == yaml_config_file['New Tags']['archrequirement']:
                                    try:
                                        parsed_item['archrequirement'] = tag['para']['verbatim']
                                    except Exception as e:
                                        parsed_item['archrequirement'] = tag['para']
                                elif tag['title'] == yaml_config_file['New Tags']['constrains']:
                                    try:
                                        parsed_item['constrains'] = tag['para']['verbatim']
                                    except Exception as e:
                                        parsed_item['constrains'] = tag['para']
                                elif tag['title'] == yaml_config_file['New Tags']['exception']:
                                    try:
                                        parsed_item['exception'] = tag['para']['verbatim']
                                    except Exception as e:
                                        parsed_item['exception'] = tag['para']
                                elif tag['title'] == yaml_config_file['New Tags']['staticaspect']:
                                    try:
                                        parsed_item['staticAspect'] = tag['para']['verbatim']
                                    except Exception as e:
                                        parsed_item['staticAspect'] = tag['para']

                            elif tag['@kind'] == 'return':
                                if isinstance(tag['para'], dict):
                                    parsed_item['return'] = tag['para']['#text']
                                elif isinstance(tag['para'], str):
                                    parsed_item['return'] = tag['para']

                            elif tag['@kind'] == 'pre':
                                if isinstance(tag['para'], dict):
                                    parsed_item['precondition'] = tag['para']['#text']
                                elif isinstance(tag['para'], str):
                                    parsed_item['precondition'] = tag['para']

                            elif tag['@kind'] == 'post':
                                if isinstance(tag['para'], dict):
                                    parsed_item['postcondition'] = tag['para']['#text']
                                elif isinstance(tag['para'], str):
                                    parsed_item['postcondition'] = tag['para']

                    parsed_item['inputParameters'] = inputParamsDict
                    parsed_item['outputParameters'] = outputParamsDict

                # check if function dict have all data
                if not 'briefdescription' in parsed_item.keys():
                    parsed_item['briefdescription'] = 'NA.'
                    print('WARN -> Function "' + parsed_item['name'] + '" has no brief description!')
                if 'inputParameters' in parsed_item.keys():
                    if isinstance(parsed_item['inputParameters'], dict):
                        if len(parsed_item['inputParameters']) > 0:
                            parsedItemKeys = list(parsed_item['inputParameters'].keys())
                            for param in parsedItemKeys:
                                if 'name' not in parsed_item['inputParameters'][param]:
                                    parsed_item['inputParameters'][param]['name'] = 'NA.'
                                if 'type' not in parsed_item['inputParameters'][param]:
                                    parsed_item['inputParameters'][param]['type'] = 'NA.'
                                if 'description' not in parsed_item['inputParameters'][param]:
                                    parsed_item['inputParameters'][param]['description'] = 'NA.'
                                if 'range' not in parsed_item['inputParameters'][param]:
                                    parsed_item['inputParameters'][param]['range'] = 'NA.'
                        else:
                            parsed_item['inputParameters'] = {'NA.': {'name': 'NA.', 'type': 'NA.', 'description': 'NA.', 'range': 'NA.'}}
                else:
                    parsed_item['inputParameters'] = {'NA.': {'name': 'NA.', 'type': 'NA.', 'description': 'NA.', 'range': 'NA.'}}
                if 'outputParameters' in parsed_item.keys():
                    if isinstance(parsed_item['outputParameters'], dict):
                        if len(parsed_item['outputParameters']) > 0:
                            parsedItemKeys = list(parsed_item['outputParameters'].keys())
                            for param in parsedItemKeys:
                                if 'name' not in parsed_item['outputParameters'][param]:
                                    parsed_item['outputParameters']['name'] = 'NA.'
                                if 'type' not in parsed_item['outputParameters'][param]:
                                    parsed_item['outputParameters']['type'] = 'NA.'
                                if 'description' not in parsed_item['outputParameters'][param]:
                                    parsed_item['outputParameters']['description'] = 'NA.'
                                if 'range' not in parsed_item['outputParameters'][param]:
                                    parsed_item['outputParameters']['range'] = 'NA.'
                        else:
                            parsed_item['outputParameters'] = {'NA.': {'name': 'NA.', 'type': 'NA.', 'description': 'NA.', 'range': 'NA.'}}
                else:
                    parsed_item['outputParameters'] = {'NA.': {'name': 'NA.', 'type': 'NA.', 'description': 'NA.', 'range': 'NA.'}}

                if 'exception' not in parsed_item.keys():
                    parsed_item['exception'] = 'NA.'
                if 'precondition' not in parsed_item.keys():
                    parsed_item['precondition'] = 'NA.'
                if 'postcondition' not in parsed_item.keys():
                    parsed_item['postcondition'] = 'NA.'
                if 'return' not in parsed_item.keys():
                    parsed_item['return'] = 'NA.'
                if 'dynamicAspectCaller' not in parsed_item.keys():
                    parsed_item['dynamicAspectCaller'] = 'NA.'
                    print('WARN -> Function "' + parsed_item['name'] + '" has no dynamic aspect caller!')
                if 'dynamicAspectDescription' not in parsed_item.keys():
                    parsed_item['dynamicAspectDescription'] = 'NA.'
                    print('WARN -> Function "' + parsed_item['name'] + '" has no dynamic aspect description!')
                if 'constrains' not in parsed_item.keys():
                    parsed_item['constrains'] = 'NA.'
                if 'staticAspect' not in parsed_item.keys():
                    parsed_item['staticAspect'] = 'NA.'
                if 'ddesignrequirement' not in parsed_item.keys():
                    parsed_item['ddesignrequirement'] = 'NA.'
                    print('WARN -> Function "' + parsed_item['name'] + '" has no detailed design requirement!')
                elif parsed_item['ddesignrequirement'] == None:
                    parsed_item['ddesignrequirement'] = 'NA.'
                    print('WARN -> Function "' + parsed_item['name'] + '" has no detailed design requirement!')
                if 'archrequirement' not in parsed_item.keys():
                    parsed_item['archrequirement'] = 'NA.'
                    print('WARN -> Function "' + parsed_item['name'] + '" has no architecture requirement!')
                elif parsed_item['archrequirement'] == None:
                    parsed_item['archrequirement'] = 'NA.'
                    print('WARN -> Function "' + parsed_item['name'] + '" has no architecture design requirement!')

                if parsed_item['type'] == None:
                    definitionWords = parsed_item['definition'].split(' ')
                    typeStr = ''
                    if len(definitionWords) == 1:
                        typeStr = parsed_item['definition']
                    else:
                        for idx, word in enumerate(definitionWords):
                            if idx < len(definitionWords) - 1:
                                typeStr += word + ' '
                    parsed_item['type'] = typeStr.strip()

                parsed_item['briefdescription'] = processTextField(parsed_item['briefdescription'])
                parsed_item['exception'] =processTextField(parsed_item['exception'])
                parsed_item['precondition'] = processTextField(parsed_item['precondition'])
                parsed_item['postcondition'] = processTextField(parsed_item['postcondition'])
                parsed_item['return'] = processTextField(parsed_item['return'])
                parsed_item['staticAspect'] = processTextField(parsed_item['staticAspect'])
                parsed_item['constrains'] = processTextField(parsed_item['constrains'])
                parsed_item['dynamicAspectDescription'] = processTextField(parsed_item['dynamicAspectDescription'])
                parsed_item['dynamicAspectCaller'] = processTextField(parsed_item['dynamicAspectCaller'])
                parsed_item['ddesignrequirement'] = processTextField(parsed_item['ddesignrequirement'])
                parsed_item['archrequirement'] = processTextField(parsed_item['archrequirement'])
                parsed_functions[function['name']] = parsed_item

    return {'defines': parsed_defines, 'variables': parsed_variables, 'functions': parsed_functions}


def processTextField(text):
    textLines = text.split('\n')
    finalStr = ''
    for idx, line in enumerate(textLines):
        line = line.strip()
        if idx < (len(textLines) - 1):
            line += '\n'
        finalStr += line
    finalStr = finalStr.replace('; ', ';\n').replace(': ', ':\n')

    return finalStr