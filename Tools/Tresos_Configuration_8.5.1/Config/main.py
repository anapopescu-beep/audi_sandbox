import os

scriptLocation = os.path.dirname(os.path.realpath(__file__))

WINDOWS_LINE_ENDING = b'\r\n'
UNIX_LINE_ENDING = b'\n'

def main():
    RteFile = scriptLocation + "\..\..\..\..\Components\Application\Supplier\Tresos_Configuration_8.5.1\Workspace\Application\Tresos_BSW_generated\src\Rte.c"
    includeFolder = scriptLocation + "\..\..\..\..\Components\Application\Supplier\Tresos_Configuration_8.5.1\Workspace\Application\Tresos_BSW_generated\include"

    # replace text in Rte.c file
    file_content = open(RteFile, 'rb').read()
    file_content = file_content.replace(b'STATIC VAR(uint8, RTE_VAR) SchM_State = SCHM_PARTITION_UNINITIALIZED;', b'VAR(uint8, RTE_VAR) SchM_State = SCHM_PARTITION_UNINITIALIZED;')
    file = open(RteFile, 'wb')
    file.write(file_content)
    file.close()


    # replace text in include files
    for file in os.listdir(includeFolder):
        if file.endswith('.h'):
            path = includeFolder + '\\' + file
            file_content = open(path, 'rb').read()
            file_content = file_content.replace(b'(P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, RTE_APPL_DATA))(P2VAR(void, AUTOMATIC, RTE_APPL_DATA))(EventStatusExtended))', b'EventStatusExtended)')
            file = open(path, 'wb')
            file.write(file_content)
            file.close()


if __name__ == "__main__":
    main()
    