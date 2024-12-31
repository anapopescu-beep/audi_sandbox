1. Example Description
    - This application demonstrates the usage of a subset of Real Time Drivers that are included in this code drop. It is not part of the production code deliverables.
    - The application includes an EB Tresos project that configures the Base, Dem, EcuC, Os, Platform, Fls, Rte, Memif and Resource drivers.
    1.1 The application software functionalities
            - Fls_ClockSetup
                    Initialize Qspi's Clocks
            - Fls_PinSetup
                    Initialize the pins which are used by application.
            - Fls_CacheSetup
                    Disable cache on Region 2
            - Fls_Init
                    Initialize the Fls driver.
            - Fls_Erase, Fls_MainFunction, Fls_GetStatus
                    Erase entire the flash sectors configured.
                    Fls_Erase is used to set job erase,
                    Fls_MainFunction to start executing erase job
                    Fls_GetStatus checks status of erase execution.
            - Fls_Write, Fls_MainFunction, Fls_GetStatus
                    Write data to flash.
            - Fls_Read, Fls_MainFunction, Fls_GetStatus
                    Read data from flash memory.
            - Fls_Compare, Fls_MainFunction, Fls_GetStatus
                    Compare data from flash memory with source data.

    Note:
        - PCCRMR[R2] should be programmed as 00b (NonCacheable) as S32K148 FlexNVMs region is not cacheable
        - For more information, please refer to the LMEM chapter in the Reference manual and "Data Cache Restrictions" chapter in the Integration Manual

2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - S32K148EVB-Q176 PCB 29644 RevX1 SCH RevB
        2.1.2 Connections
            The following Connections must be done to for this example application to work:
            - The external flash is by default not connected to the MCU. Therefore, in order to run this example some hardware changes are required to the board
            - Power Adapter 12V
            - Use the externel power source: J8 - Set to position 1-2
            - In order to run this example some Resistors (R) changes are required to the board:
                Remove | Connect |
                -------|---------|
                 R212  |  R213   |
                 R210  |  R211   |
                 R208  |  R209   |
                 R250  |  R244   |
                 R260  |  R254   |
                 R272  |  R271   |
        2.1.3 Debugger
            - The debugger must be connected to the J10 20-pin JTAG Cortex Debug connector
    2.2 Software installation
        2.2.1 Tresos Project Installation
            The following procedure requires that the user has EB Tresos Studio installed and it is only needed for viewing, updating and generating the driver's configuration.
            Procedure:
                1. Make sure that all RTD plugins are already installed in the Tresos Studio plugins directory
                2. Open Tresos Studio
                3. Import example application project
                    a. Click on "File" and select "Import"
                    b. Select "Existing Projects into Workspace" and click on "Next" button
                    c. Select "Select root directory" and click on "Browse"
                    d. Select the location of the [project] folder in the installed example application package folder
                    e. Optional* - Select "Copy projects into workspace"
                    f. Click on "Finish" button
        2.2.2 Example configuration
            The following procedure requires that the user has EB Tresos Studio installed and the toolchains versions specified in the Release Notes.
            The toolchain that will be used needs to be installed for correct operation and the path to the installation location shall be added into the system environment variable(s):
            - TRESOS_DIR the installation path of Electrobit Tresos (used for generating the project from command line)
                Ex: TRESOS_DIR = C:/EB/tresos27.1.0
            - GCC_DIR The path to the GCC installation dir
                Ex: GCC_DIR = C:/NXP/S32DS.3.3/S32DS/build_tools/gcc_v9.2/gcc-9.2-arm32-eabi
            - PLUGINS_DIR The path to the Tresos plugins directory
                Ex: PLUGINS_DIR = C:/EB/tresos27.1.0/plugins
            - T32_DIR The path to the T32 directory
                Ex: T32_DIR = C:/T32
            Procedure:
                1. Open project_parameters.mk file in a text editor and update the variables mentioned above with the correct paths

3. Building the example application
    For using the command line, a make tool needs to be installed on your machine. For full functionality from command line sed is also required.
    3.1 Generating the Tresos project
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To generate the Tresos project of the example, execute the following command to build: make generate
            4. The output files of the generation shall be generated in the /generate subdirectory
    3.2 Compiling the application
        Procedure:
            1. Open the Windows command prompt window
            2. Change the current directory to the example application folder
            3. To build the example, execute the following command to build: make build
            4. The object files and linker output file (main.elf) shall be generated in the /out subdirectory
    3.3 Running the application on the board
        For executing the script in a T32 window already you can run the run.cmm script as is.
        To execute the example application from your command line execute make run.
        Note: to be able to run this command a sed package needs to be installed on your machine as it is used for dynamically updating some paths in the files that are used by this step.
    3.4 Modifying the configuration in Tresos and generating the code
        Users may change the application configuration according to their needs.
        Procedure:
            1. Open the EB Tresos Studio GUI
            2. Open previously imported Example Application project
            3. Use the Tresos Studio GUI to modify configuration parameter values and save the changes.
            4. Select the Example Application project and click on "Generate" button to generate the configuration files.