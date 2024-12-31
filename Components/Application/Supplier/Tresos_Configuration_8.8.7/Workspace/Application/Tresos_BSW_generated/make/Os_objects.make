# This file is generated automatically. DO NOT EDIT!!
# 
# EB tresos AutoCore OS 6.1.144 CORTEXM/S32K14X
# (Build 20230308)
# 
# (c) 1998-2023 Elektrobit Automotive GmbH
# Am Wolfsmantel 46
# 91058 Erlangen
# GERMANY
# 
# Date         : 8/30/23 2:42 PM           !!!IGNORE-LINE!!!

ifndef OS_OBJECTS_MAKE_INCLUDED
OS_OBJECTS_MAKE_INCLUDED := 1

OS_GENERATED_APPL_FILES +=$(AutosarOS_OUTPUT_PATH)\src\OsApplication_0_gen.c
OS_CORE_OsApplication_0 = 0
OS_GENERATED_APPL_FILES +=$(AutosarOS_OUTPUT_PATH)\src\OS_SYSTEM_0_gen.c
OS_CORE_OS_SYSTEM_0 = 0
# OS_OPTIMIZED_LIB_ID tells the build process the name of the optimized library
OS_OPTIMIZED_LIB_ID = 2001af5b88

#####################################################################
# Advanced Logical Core Interface
#####################################################################
# OS_ALCI tells the build process whether to enable ALCI feature.
OS_ALCI = FALSE

#####################################################################
# Applications
#####################################################################
# The APPLICATIONS macro tells the build process the names
# of all the application objects
APPLICATIONS = OsApplication_0 OS_SYSTEM_0

# For each application XXX in the APPLICATIONS macro:
# - the macro TASKS_XXX tells the build process the names of all the tasks
#   that belong to the application XXX
# - the macro ISRS_XXX tells the build process the names of all the ISRs
#   that belong to the application XXX

TASKS_OsApplication_0 = OsTask_Bsw_ComServices OsTask_Bsw_MemServices OsTask_Bsw_SysServices OsTask_Bsw_Init OsTask_Bsw_Events OsTask_Alv_ComHwAbs OsTask_Bsw_ReadWrite_AllProcess OsTask_Alv_eCSApp OsTask_Alv_Autotests OsTask_Alv_ComServices OsTask_AppIdle OsTask_Alv_EcuHwAbs OsTask_Alv_ModeMngmt OsTask_Bsw_ComEvents
ISRS_OsApplication_0 = CAN0_ORED_IRQHandler CAN0_Error_IRQHandler CAN0_ORED_0_15_MB_IRQHandler CAN0_ORED_16_31_MB_IRQHandler LPIT_0_CH_1_ISR LPTMR_ISR PORTD_ISR PORTE_ISR LPIT_0_CH_2_ISR
TASKS_OS_SYSTEM_0 =
ISRS_OS_SYSTEM_0 =

#####################################################################
# Configured Modes
#####################################################################
# OS_CONFIG_EXTENDED_STATUS tells the build process which error library to use.
OS_CONFIG_EXTENDED_STATUS = TRUE
# The OS TRACER is configured as follows:
OS_TRACE = TRUE

#####################################################################
# Core Mapping
#####################################################################
# OS_INITCORE tells the build process which core the OS uses (singlecore).
OS_INITCORE = 0

#####################################################################
# Counters
#####################################################################

#####################################################################
# Interrupts
#####################################################################
# This variable tells the build process the number of stack slots that are generated
# for the stack type kernStack
OS_NUM_KERNSTACK_SLOTS = 1

#####################################################################
# Kernel Type
#####################################################################
# Defines which trapping mechanism the OS shall use.
OS_KERNEL_TYPE = SYSTEM_CALL

#####################################################################
# Memory Regions
#####################################################################

#####################################################################
# Multicore
#####################################################################
# Defines the number of CPU cores assigned to EB tresos AutoCore OS.
OS_N_CORES := 1
# Defines the maximum number of CPU cores supported.
OS_N_CORES_MAX := 1

#####################################################################
# Optimization
#####################################################################
# Defines if library shall be optimized according to configuration
OS_BUILD_OPTIMIZED_LIB_FROM_SOURCE = TRUE

#####################################################################
# Tasks
#####################################################################
# This variable tells the build process the number of stack slots that are generated
# for the stack type taskStack
OS_NUM_TASKSTACK_SLOTS = 14





endif
