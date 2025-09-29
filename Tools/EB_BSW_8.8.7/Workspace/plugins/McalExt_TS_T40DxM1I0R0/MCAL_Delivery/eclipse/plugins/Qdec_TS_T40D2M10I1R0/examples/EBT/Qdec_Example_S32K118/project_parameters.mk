#The path to the GCC installation dir
GCC_DIR = C:/gcc/bin

#The path to the EB Tresos installation dir
TRESOS_DIR = D:/Build_tools/EB/tresos_27_1_0

#The path to the T32 installation dir
T32_DIR = C:Build_tools

#The path to the VDK installation dir
VDK_DIR = 

#The path to the Tresos plugins directory
PLUGINS_DIR = ../../../../

#The path to the Tresos add-on plugins directory
PLUGINS_DIR_ADDON = ../../../../

#The paths to the additional directories to be included at build phase
ADDITIONAL_INCLUDE_DIRS = 

#Loading project to ram or flash
LOAD_TO=

# ------------------------------------------------------------------------------------
#Example specific parameters - do not modify 

#MCAL modules used
MCAL_MODULE_LIST := Resource Base Det EcuC Os Platform Port Qdec Mcu

#MCAL modules used - only for examples based on 2 software products
MCAL_MODULE_LIST_ADDON := 

#The package name for the MCAL release
AR_PKG_NAME = TS_T40D2M10I1R0

#The package name for the MCAL release - only for examples based on 2 software products
AR_PKG_NAME_ADDON = 

#The derivative of the device
EXAMPLE_DERIVATIVE = S32K118

#The core type of the device
EXAMPLE_CORE_TYPE = M0P

#The name of the elf file
ELFNAME = main

#The test base address 
TEST_BASE_ADDR = 0x1FFFFC00

# The test block size
TEST_BLOCK_SIZE = 255

#The name of the Tresos project 
TRESOS_PROJECT_NAME = Qdec_Example_S32K118

#The number of variants for the Tresos project 
VARIANT_NO = 1

#Connection type of lauterbach
PBI = replace_pbi
