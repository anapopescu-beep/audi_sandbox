1. Example Description
    This application demonstrates the usage of a subset of Real Time Drivers that are included in this code drop.
    The application includes an EB Tresos project that configures the Base, Dem, EcuC, Ocu, Platform, Port, Mcu and Resource drivers.
    1.1 The aplication software functionality
       - Mcu_Init, Mcu_InitClock, Mcu_SetMode
          Initialize the clock sources, the clock tree and to configure the clock gating of the peripherals.
          The clock configuration that is used will enable and use the PLL as source clock.
        - Platform_Init
          Enable the interrupt used by the application and set the correct handler for it.
        - Port_Init
          Initialize the pins used by application using  Port driver
        - Ocu_Init, Ocu_StartChannel, Ocu_EnableNotification
          Initialize OCU, start the selected timer and enable its notification that will raise a notification
          After the initialization, 1 channel will start counting and 1 notification will be generated each compare match.
          Notification function will toggle the PTD15 pin and will increase a 'count' variable by 1; the API will toggle the PTD16 gpio pin every 300 increments of the counter using Dio driver.
2. Installation steps
    2.1 Hardware installation
        2.1.1 Supported boards
            - S32K118EVB2-Q048 (PCB 47530 RevX1, SCH RevA1)
        2.2.2 Connections
            A wire connection is required between the following:
                - pin J109.2    (PTD15 FTM0_CH0 output); 
                - close 2-3 slot on J110 jumper to wire PTD16 to RGB_RED LED and the example will blink the LED.
        2.2.3 Debugger
            - The debugger must be connected to J14 10-pin JTAG Cortex Debug connector.
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
                Ex: TRESOS_DIR = C:/EB/tresos_27.1
            - GCC_DIR The path to the GCC instalation dir
                Ex: GCC_DIR = C:/NXP/S32DS.3.3/S32DS/build_tools/gcc_v9.2/gcc-9.2-arm32-eabi
            - PLUGINS_DIR The path to the Tresos plugins directory
                Ex: PLUGINS_DIR = C:/EB/tresos_27.1/plugins
            Procedure:
                1. Open project_parameters.mk file in a text editor and update the variables mentioned above with the correct paths
3. Building the example application
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
        To execute the example application from your command line execute make run. For executing the script in a T32 window already open the paths from run.cmm need to be changed relative to the debug folder instead of the example root folder.
    3.4 Modifying the configuration in Tresos and generating the code
        Users may change the application configuration according to their needs.
        Procedure:
            1. Open the EB Tresos Studio GUI
            2. Open previously imported Example Application project
            3. Use the Tresos Studio GUI to modify configuration parameter values and save the changes.
            4. Select the Example Application project and click on "Generate" button to generate the configuration files.
