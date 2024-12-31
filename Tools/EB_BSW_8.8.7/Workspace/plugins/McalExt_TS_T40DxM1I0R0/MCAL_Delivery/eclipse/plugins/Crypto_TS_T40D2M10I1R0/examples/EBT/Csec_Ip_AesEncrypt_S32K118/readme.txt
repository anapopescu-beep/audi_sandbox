1. Example Description
        Imports an AES key in the RAM key slot and sends synchronous and asynchronous encryption requests to Csec Ip layer
    1.1 The application software functionality
        The code in the main function of the application performs the following steps:
         - Initializes the CSEc hardware
         - Initializes the OsiIf component. It is used by Csec Ip layer to determine the timeout while waiting for responses from CSEc for synchronous requests
         - Initializes the Csec Ip layer
         - Sets the timeout for synchronous requests
         - Imports the material of the ASE128 key in the RAM keys slot
         - Initiates a synchronous AES128 encryption request and checks that the cipherText is the expected one
         - Initiates an asynchronous using polling AES128 encryption request and checks that the cipherText is the expected one
         - At the end of the example run, the Csec keys are erased in order to restore the device to its original state

        The configuration of the drivers used by this example are done like below:
         - Csec component
            - Timeout Counter Type set to OSIF_COUNTER_DUMMY, such that the time passed from the moment a request is made from Csec Ip layer to CSEc Hw till
              the response is received is measured in ticks

2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - S32K118EVB2-Q048
        2.1.2 Connections
            No special wiring connections are needed for this example.
        2.1.3 Debugger
            The debugger must be connected to J14 10-pin JTAG Cortex Debug connector.
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
            - TRESOS_DIR the installation path of Elektrobit Tresos (used for generating the project from command line)
                Ex: TRESOS_DIR = C:/EB/tresos27.1.0
            - GCC_DIR The path to the GCC installation dir
                Ex: GCC_DIR = C:/NXP/S32DS.3.4/S32DS/build_tools/gcc_v9.2/gcc-9.2-arm32-eabi
            - T32_DIR The path to the T32 directory
                Ex: T32_DIR = C:/T32

            Procedure:
                1. Open project_parameters.mk file in a text editor and update the variables mentioned above with the correct paths
3. Building the example application
    For using the command line a make tool needs to be installed on your machine. For full functionality from command line sed is also required.
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
        To execute the example application from your command line execute make run. Note: to be able to run this command a sed package needs to be installed on your machine as it is used for dynamically updating some paths in the files that are used by this step.
    3.4 Modifying the configuration in Tresos and generating the code
        Users may change the application configuration according to their needs.
        Procedure:
            1. Open the EB Tresos Studio GUI
            2. Open previously imported Example Application project
            3. Use the Tresos Studio GUI to modify configuration parameter values and save the changes.
            4. Select the Example Application project and click on "Generate" button to generate the configuration files.
