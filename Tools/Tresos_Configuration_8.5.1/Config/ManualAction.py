import argparse
import os
import yaml
import re

scriptLocation = os.path.dirname(os.path.realpath(__file__))

WINDOWS_LINE_ENDING = b'\r\n'
UNIX_LINE_ENDING = b'\n'


def main():
    global yaml_config_file

    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--input_yaml-config-path', help="Path to yaml_config_path", required=True)
    args = parser.parse_args()

    yaml_config_path = os.path.join(args.input_yaml_config_path, "manual_action_config.yaml")

    print(yaml_config_path)
    print('Manual_Action_Config_Script')

    with open(yaml_config_path, 'r') as stream:
        try:
            yaml_config_file = yaml.load(stream, Loader=yaml.FullLoader)
        except Exception as e:
            print('No config file has been found. The program will now exit.')
            print('Error encoutered in reading yaml config file: ', e)
            return -1

    srcFolder = yaml_config_file['tresos_gen_src']
    includeFolder = yaml_config_file['tresos_gen_include']
    xgenFolder = yaml_config_file['tresos_gen_xgen']

    # replace text in include files
    for file in os.listdir(includeFolder):
        if file.endswith('.h'):
            path = includeFolder + '/' + file
            file_content = open(path, 'rb').readlines()
            out_file_content = b''
            for line in file_content:
                line = line.replace(b'(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA))(P2VAR(void, AUTOMATIC, RTE_APPL_DATA))(EventStatusExtended))', b'EventStatusExtended)')
                if  not WINDOWS_LINE_ENDING in line :
                    line = line.replace(UNIX_LINE_ENDING,WINDOWS_LINE_ENDING)
                # searches for lines in Rte_Dcm.h and Rte_Dem.h and removes "_ASR42_" from function parameters
                if b"#define"  not in line and b"#ifndef" not in line and b"typedef" not in line and (file == "Rte_Dcm.h" or file == "Rte_Dem.h"):
                    if(b'_ASR42' in line):
                        string_line = line.decode('utf-8')
                        pattern = "(.*[^\(\)]*RTE_CODE\)[^\(]*)(.*)(\n)"
                        m = re.search(pattern,string_line)
                        if m:
                            line=(m.group(0).replace(m.group(2), m.group(2).replace("_ASR42", "")))
                            line=bytes(line,encoding='utf8')
                        line = line
                if not b"!!!IGNORE-LINE!!!" in line:
                    out_file_content += line
            file = open(path, 'wb')
            file.write(out_file_content)
            file.close()

    for file in os.listdir(srcFolder):
        if file.endswith('.c'):
            path = srcFolder + '/' + file
            file_content = open(path, 'rb').readlines()
            out_file_content = b''
            for line in file_content:
                if  not WINDOWS_LINE_ENDING in line :
                    line = line.replace(UNIX_LINE_ENDING,WINDOWS_LINE_ENDING)
                if file == 'Rte.c' :
                    line = line.replace(
                        b'STATIC VAR(uint8, RTE_VAR) SchM_State = SCHM_PARTITION_UNINITIALIZED;',
                        b'VAR(uint8, RTE_VAR) SchM_State = SCHM_PARTITION_UNINITIALIZED;')
                if not b"!!!IGNORE-LINE!!!" in line:
                    out_file_content += line
            file = open(path, 'wb')
            file.write(out_file_content)
            file.close()

    for file in os.listdir(xgenFolder):
        if file.endswith('.xgen'):
            path = xgenFolder + '/' + file
            file_content = open(path, 'rb').readlines()
            out_file_content = b''
            for line in file_content:
                if not WINDOWS_LINE_ENDING in line:
                    line = line.replace(UNIX_LINE_ENDING,WINDOWS_LINE_ENDING)
                if not b"!!!IGNORE-LINE!!!" in line:
                    out_file_content += line
            file = open(path, 'wb')
            file.write(out_file_content)
            file.close()

if __name__ == "__main__":
    main()
    