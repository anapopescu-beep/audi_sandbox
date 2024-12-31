# ---------------------------------------
# Pre Process script of QAC Analisys tool
# Written by Lucian Ardeleanu
# ---------------------------------------

import os
import sys
import re

# Get current dir path
current_dir = os.getcwd()

# QAC config paths 
project_path = 'S:\\'
target_name = 'Application'

# ================ GENERATION OF PP4G_Ext_Appli.prj FILE =========================================

# LIST USED TO EXCLUDE DIRECTORIES FROM FILE PATHS
exclude_directories = ['Design', 'Quality_Assurance', 'NVP']

# LIST USED TO EXCLUDE FILES FROM FILE PATHS
exclude_files = []

list_string_PP4G_Ext_Appli = []
list_string_PP4G_Ext_Appli.append('VersionTag45')
list_string_PP4G_Ext_Appli.append('StartProjectMarker')
list_string_PP4G_Ext_Appli.append('OutputPath=temp')
list_string_PP4G_Ext_Appli.append('SubsPers=' + str(os.path.join(current_dir, 'AUTOLIV.p_s')))
list_string_PP4G_Ext_Appli.append('SubsPers=' + str(os.path.join(current_dir, 'PP4G_ERR.p_a')))
list_string_PP4G_Ext_Appli.append('SubsPers=' + str(os.path.join(current_dir, 'AUTOLIV.p_c')))
list_string_PP4G_Ext_Appli.append('EndContainedFilesMarker')

list_of_inc_paths = []

# THIS ROUTINE IS USED TO APPEND INTO A LIST ALL FILES FROM ENTIRE DRIVE


for root, dirs, files in os.walk(os.path.join(project_path, 'Components', target_name, 'Autoliv')):

    # HERE IS DEFINED HOW EXCLUDING MECHANISM WORKS
    dirs[:] = [d for d in dirs if d not in exclude_directories]
    files[:] = [d for d in files if d not in exclude_files]

    for file in files:
        if file.endswith('.c'):

            file_path = os.path.join(root, file)

            file_first_upper_path = os.path.abspath(os.path.join(file_path, os.pardir))
            file_first_upper_path_name = os.path.basename( file_first_upper_path)

            file_second_upper_path = os.path.abspath(os.path.join(file_first_upper_path, os.pardir))
            file_second_upper_path_name = os.path.basename(file_second_upper_path)

            component_path = os.path.abspath(os.path.join(file_second_upper_path, os.pardir))
            component_name = os.path.basename( component_path )

            list_string_PP4G_Ext_Appli.append('StartSubProjectMarker')
            list_string_PP4G_Ext_Appli.append('StartProjectMarker')
            list_string_PP4G_Ext_Appli.append('FolderName=' + component_name)
            list_string_PP4G_Ext_Appli.append('SourcePath=' + component_path)
            list_string_PP4G_Ext_Appli.append('OutputPath=temp')
            list_string_PP4G_Ext_Appli.append('SubsPers=' +  str(os.path.join(current_dir, 'AUTOLIV.p_s')) )
            list_string_PP4G_Ext_Appli.append('SubsPers=' + str(os.path.join(current_dir, 'PP4G_ERR.p_a')))
            list_string_PP4G_Ext_Appli.append('SubsPers=' + str(os.path.join(current_dir, 'AUTOLIV.p_c')))
            list_string_PP4G_Ext_Appli.append('EndContainedFilesMarker')

            list_string_PP4G_Ext_Appli.append('StartSubProjectMarker')
            list_string_PP4G_Ext_Appli.append('StartProjectMarker')
            list_string_PP4G_Ext_Appli.append('FolderName=' + file_second_upper_path_name)
            list_string_PP4G_Ext_Appli.append('SourcePath=' + file_second_upper_path)
            list_string_PP4G_Ext_Appli.append('OutputPath=temp')
            list_string_PP4G_Ext_Appli.append('SubsPers=' +  str(os.path.join(current_dir, 'AUTOLIV.p_s')) )
            list_string_PP4G_Ext_Appli.append('SubsPers=' + str(os.path.join(current_dir, 'PP4G_ERR.p_a')))
            list_string_PP4G_Ext_Appli.append('SubsPers=' + str(os.path.join(current_dir, 'AUTOLIV.p_c')))
            list_string_PP4G_Ext_Appli.append('EndContainedFilesMarker')

            list_string_PP4G_Ext_Appli.append('StartSubProjectMarker')
            list_string_PP4G_Ext_Appli.append('StartProjectMarker')
            list_string_PP4G_Ext_Appli.append('FolderName=' + file_first_upper_path_name)
            list_string_PP4G_Ext_Appli.append('SourcePath=' + file_first_upper_path)
            list_string_PP4G_Ext_Appli.append('OutputPath=temp')
            list_string_PP4G_Ext_Appli.append('SubsPers=' +  str(os.path.join(current_dir, 'AUTOLIV.p_s')) )
            list_string_PP4G_Ext_Appli.append('SubsPers=' + str(os.path.join(current_dir, 'PP4G_ERR.p_a')))
            list_string_PP4G_Ext_Appli.append('SubsPers=' + str(os.path.join(current_dir, 'AUTOLIV.p_c')))
            list_string_PP4G_Ext_Appli.append(file_path)
            list_string_PP4G_Ext_Appli.append('EndContainedFilesMarker')

            list_string_PP4G_Ext_Appli.append('EndSubProjectMarker')
            list_string_PP4G_Ext_Appli.append('EndSubProjectMarker')


list_string_PP4G_Ext_Appli.append('EndSubProjectMarker')
list_string_PP4G_Ext_Appli.append('EndSubProjectMarker')

# Write constructed content list in file
with open(r'PP4G_Ext_Appli.prj', 'w') as fp:
    fp.write("\n".join(str(item) for item in list_string_PP4G_Ext_Appli))

# ================ END OF GENERATION OF PP4G_Ext_Appli.prj FILE ==================================


# ================ GENERATION OF PP4G_ERR.p_a FILE =========================================


# LIST USED TO EXCLUDE DIRECTORIES FROM FILE PATHS
exclude_directories_inc = ['Design', 'Quality_Assurance', 'Scripts']

# LIST USED TO EXCLUDE FILES FROM FILE PATHS
exclude_files_inc = []

# THIS ROUTINE IS USED TO APPEND INTO A LIST ALL FILES FROM ENTIRE DRIVE
for root, dirs, files in os.walk(os.path.join(project_path, 'Components', target_name, 'Autoliv')):

    # HERE IS DEFINED HOW EXCLUDING MECHANISM WORKS
    dirs[:] = [d for d in dirs if d not in exclude_directories_inc]
    files[:] = [d for d in files if d not in exclude_files_inc]

    for file in files:
        if file.endswith('.h'):
            file_path = os.path.join(root, file)
            file_first_upper_path = os.path.abspath(os.path.join(file_path, os.pardir))

            list_of_inc_paths.append(file_first_upper_path)


# LIST USED TO EXCLUDE DIRECTORIES FROM FILE PATHS
exclude_directories_build = ['Design', 'TL_Lib', 'Quality_Assurance', 'NVP']

# LIST USED TO EXCLUDE FILES FROM FILE PATHS
exclude_files_build = []

makefile_eb_plugins_names = []
makefile_eb_path_to_plugins = ''
for root, dirs, files in os.walk(os.path.join(project_path, 'Tools\Build_Env\Workspace\Build')):

    # HERE IS DEFINED HOW EXCLUDING MECHANISM WORKS
    dirs[:] = [d for d in dirs if d not in exclude_directories_build]
    files[:] = [d for d in files if d not in exclude_files_build]

    for file in files:

        if file.endswith('Makefile.config.mk') and target_name in root:
           
            raw_file = open(os.path.join(root, file), "r")
            makefile_content = raw_file.readlines()

            for line in makefile_content:
                if '_VERSION :=' in line:
                    makefile_eb_plugins_names.append(line[line.find(':= ') + len(':= '): ].strip())
                    

                if 'NXPMCAL_INCLUDES_DIR =' in line:
                    makefile_eb_path_to_plugins = line[ line.find('NXPMCAL_INCLUDES_DIR =') + len('NXPMCAL_INCLUDES_DIR ='):].strip()

if len(makefile_eb_plugins_names) == 0:
    print('EB Tresos plugins has not found in file Makefile.config.mk from Build Env folder. Update script if makefile has been changed.')
    sys.exit()

list_of_tresos_plugins_inc_path = []
tools_path = ''

if len(makefile_eb_path_to_plugins) == 0:
    print('Paths of EB Tresos plugins has not found in file Makefile.config.mk from Build Env folder. Update script if makefile has been changed.')
    sys.exit()
else:
    tools_path = 'S:\Tools'

    if not os.path.isdir(tools_path):
        print('Tools_Platform_Git folder has not been found. Check script.')
        sys.exit()

    plugin_path_inc = makefile_eb_path_to_plugins.replace('$(TOOLS_DIR)', tools_path)

    for plugin in makefile_eb_plugins_names:
        plugin_path = os.path.normpath(plugin_path_inc.replace('$(1)', plugin))

        if os.path.isdir(plugin_path):
            list_of_tresos_plugins_inc_path.append(plugin_path)

list_string_PP4G_ERR = []
list_string_PP4G_ERR.append('-il 3')
list_string_PP4G_ERR.append(r'-i "S:\Components\Application\Supplier\T1\interface"')
list_string_PP4G_ERR.append(r'-i "S:\Components\Application\Supplier\T1\src"')
list_string_PP4G_ERR.append('-i "' + os.path.join(project_path, 'Components\Application\Supplier\Tresos_Configuration_8.5.1\Workspace\Application\Tresos_BSW_generated\include') + '"')


for plugin in list_of_tresos_plugins_inc_path:
    string_to_append = '-i "' + plugin + '"'
    list_string_PP4G_ERR.append(string_to_append)

    if 'Compiler' in plugin:
        string_to_append = '-i "' + plugin + '\CORTEXM"'
        list_string_PP4G_ERR.append(string_to_append)

        string_to_append = '-i "' + plugin + '\CORTEXM\iar"'
        list_string_PP4G_ERR.append(string_to_append)

    if 'Platforms' in plugin:
        string_to_append = '-i "' + plugin + '\CORTEXM"'
        list_string_PP4G_ERR.append(string_to_append)

        string_to_append = '-i "' + plugin + '\CORTEXM\S32K14X"'
        list_string_PP4G_ERR.append(string_to_append)

for comp in list_of_inc_paths:
    string_to_append = '-i "' + comp + '"'

    if string_to_append not in list_string_PP4G_ERR:
        list_string_PP4G_ERR.append(string_to_append)

list_string_PP4G_ERR.append('-i "' + os.path.join(project_path, 'Metrics\Static_Analysis\Stubs') + '"')
list_string_PP4G_ERR.append('-i "' + os.path.join(project_path, 'Components\Application\Supplier\SCST\src\h') + '"')
list_string_PP4G_ERR.append('-i "' + os.path.join(tools_path, r'EB_BSW_8.5.1\Workspace\plugins\Make_TS_TxDxM4I0R0\tools\gcc\include') + '"')
list_string_PP4G_ERR.append(r'-i "C:\Program Files (x86)\IAR Systems\Embedded Workbench 8.3\arm\inc\c"')
list_string_PP4G_ERR.append(r'-i "c:\Program Files (x86)\IAR Systems\Embedded Workbench 8.3\arm\inc"')
list_string_PP4G_ERR.append('-sty exdented')
list_string_PP4G_ERR.append('-tab 3')
list_string_PP4G_ERR.append('-en UTF')
list_string_PP4G_ERR.append('-maxerr 100')
list_string_PP4G_ERR.append('-ppl+')
list_string_PP4G_ERR.append('-ppf+')
list_string_PP4G_ERR.append('-met+')
list_string_PP4G_ERR.append('-ppm-')
list_string_PP4G_ERR.append('-co a')
list_string_PP4G_ERR.append('-ss+')
list_string_PP4G_ERR.append('-sr-')
list_string_PP4G_ERR.append('-mll 300')

# Write constructed content list in file
with open(r'PP4G_ERR.p_a', 'w') as fp:
    fp.write("\n".join(str(item) for item in list_string_PP4G_ERR))

print('Script QAC Pre Process run successfully!')
