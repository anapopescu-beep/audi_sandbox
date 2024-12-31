# This file is generated automatically. DO NOT EDIT!!
# 
# EB tresos AutoCore OS 6.0.180 CORTEXM/S32K14X
# (Build 20180906)
# 
# (c) 1998-2023 Elektrobit Automotive GmbH
# Am Wolfsmantel 46
# 91058 Erlangen
# GERMANY
# 
# http://www.automotive.elektrobit.com
# 
# Date         : 6/9/23 3:47 PM           !!!IGNORE-LINE!!!

ifndef OS_OBJECTS_MAKE_INCLUDED
OS_OBJECTS_MAKE_INCLUDED := 1

OS_GENERATED_APPL_FILES +=$(AutosarOS_OUTPUT_PATH)\src\OsApplication_0_gen.c
OS_CORE_OsApplication_0 = 0
OS_GENERATED_APPL_FILES +=$(AutosarOS_OUTPUT_PATH)\src\OS_SYSTEM_0_gen.c
OS_CORE_OS_SYSTEM_0 = 0
# OS_OPTIMIZED_LIB_ID tells the build process the name of the optimized library
OS_OPTIMIZED_LIB_ID = a001af5b88

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
ISRS_OsApplication_0 = Can_IsrFCA_BO Can_IsrFCA_ERR Can_IsrFCA_MB_00_15 Can_IsrFCA_MB_16_31 FTM_0_CH_0_CH_1_ISR LPTMR_ISR PORTD_ISR FTM_0_CH_2_CH_3_ISR PORTE_ISR
TASKS_OS_SYSTEM_0 = 
ISRS_OS_SYSTEM_0 = 

#####################################################################
# CORTEXM memory region sizes for MPU
#####################################################################

OS_CORTEXM_GBL_ROM_SIZE = 0x200000
OS_CORTEXM_GBL_RAM_SIZE = 0x40000
OS_CORTEXM_REGION_SIZE_OsApplication_0 = 0x0
OS_CORTEXM_REGION_SIZE_OS_SYSTEM_0 = 0x0
OS_CORTEXM_REGION_SIZE_OsTask_Bsw_ReadWrite_AllProcess = 0x0
OS_CORTEXM_REGION_SIZE_OsTask_AppIdle = 0x0
OS_CORTEXM_REGION_SIZE_OsTask_Bsw_ComServices = 0x0
OS_CORTEXM_REGION_SIZE_OsTask_Bsw_SysServices = 0x0
OS_CORTEXM_REGION_SIZE_OsTask_Bsw_MemServices = 0x0
OS_CORTEXM_REGION_SIZE_OsTask_Alv_ComHwAbs = 0x0
OS_CORTEXM_REGION_SIZE_OsTask_Bsw_Init = 0x0
OS_CORTEXM_REGION_SIZE_OsTask_Bsw_Events = 0x0
OS_CORTEXM_REGION_SIZE_OsTask_Alv_eCSApp = 0x0
OS_CORTEXM_REGION_SIZE_OsTask_Alv_Autotests = 0x0
OS_CORTEXM_REGION_SIZE_OsTask_Alv_ComServices = 0x0
OS_CORTEXM_REGION_SIZE_OsTask_Alv_EcuHwAbs = 0x0
OS_CORTEXM_REGION_SIZE_OsTask_Alv_ModeMngmt = 0x0
OS_CORTEXM_REGION_SIZE_OsTask_Bsw_ComEvents = 0x0
OS_CORTEXM_REGION_SIZE_os_taskstack0_slot0 = 0x0
OS_CORTEXM_REGION_SIZE_os_taskstack0_slot1 = 0x0
OS_CORTEXM_REGION_SIZE_os_taskstack0_slot2 = 0x0
OS_CORTEXM_REGION_SIZE_os_taskstack0_slot3 = 0x0
OS_CORTEXM_REGION_SIZE_os_taskstack0_slot4 = 0x0
OS_CORTEXM_REGION_SIZE_os_taskstack0_slot5 = 0x0
OS_CORTEXM_REGION_SIZE_os_taskstack0_slot6 = 0x0
OS_CORTEXM_REGION_SIZE_os_taskstack0_slot7 = 0x0
OS_CORTEXM_REGION_SIZE_os_taskstack0_slot8 = 0x0
OS_CORTEXM_REGION_SIZE_os_taskstack0_slot9 = 0x0
OS_CORTEXM_REGION_SIZE_os_taskstack0_slot10 = 0x0
OS_CORTEXM_REGION_SIZE_os_taskstack0_slot11 = 0x0
OS_CORTEXM_REGION_SIZE_os_taskstack0_slot12 = 0x0
OS_CORTEXM_REGION_SIZE_os_taskstack0_slot13 = 0x0
OS_CORTEXM_REGION_SIZE_Can_IsrFCA_BO = 0x0
OS_CORTEXM_REGION_SIZE_Can_IsrFCA_ERR = 0x0
OS_CORTEXM_REGION_SIZE_Can_IsrFCA_MB_00_15 = 0x0
OS_CORTEXM_REGION_SIZE_Can_IsrFCA_MB_16_31 = 0x0
OS_CORTEXM_REGION_SIZE_FTM_0_CH_0_CH_1_ISR = 0x0
OS_CORTEXM_REGION_SIZE_LPTMR_ISR = 0x0
OS_CORTEXM_REGION_SIZE_PORTD_ISR = 0x0
OS_CORTEXM_REGION_SIZE_FTM_0_CH_2_CH_3_ISR = 0x0
OS_CORTEXM_REGION_SIZE_PORTE_ISR = 0x0
OS_CORTEXM_REGION_SIZE_Os_Counter_LPIT0_0 = 0x0
OS_CORTEXM_REGION_SIZE_os_kernstack0 = 0x0

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
# Hook Functions
#####################################################################

# Defines which trapping mechanism the OS shall use.
OS_KERNEL_TYPE = SYSTEM_CALL
#####################################################################
# Interrupts
#####################################################################

# This variable tells the build process the number of stack slots that are generated
# for the stack type kernStack
OS_NUM_KERNSTACK_SLOTS = 1
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
# Scheduling algorithm
#####################################################################

# tells the build process which scheduling algorithm to use
OS_SCHEDULING_ALGORITHM = CLZ_QUEUE
#####################################################################
# Stacks
#####################################################################

# This variable tells the build process the name of the task stack sections
OS_STACKS = os_taskstack0_slot0 os_taskstack0_slot1 os_taskstack0_slot2 os_taskstack0_slot3 os_taskstack0_slot4 os_taskstack0_slot5 os_taskstack0_slot6 os_taskstack0_slot7 os_taskstack0_slot8 os_taskstack0_slot9 os_taskstack0_slot10 os_taskstack0_slot11 os_taskstack0_slot12 os_taskstack0_slot13 
# This variable tells the build process the name of the kernel stack sections
OS_STACKS += os_kernstack0 
# CORTEXM MPU region sizes for stacks. Useful to align the linker sections.
MK_THREAD_STACK_0 = 1024
MK_THREAD_STACK_1 = 1024
MK_THREAD_STACK_2 = 1024
MK_THREAD_STACK_3 = 1024
MK_THREAD_STACK_4 = 1024
MK_THREAD_STACK_5 = 1024
MK_THREAD_STACK_6 = 256
MK_THREAD_STACK_7 = 1024
MK_THREAD_STACK_8 = 1024
MK_THREAD_STACK_9 = 2048
MK_THREAD_STACK_10 = 2048
MK_THREAD_STACK_11 = 512
MK_THREAD_STACK_12 = 1024
MK_THREAD_STACK_13 = 1024
# All stack sizes (ordered as list)
MK_THREAD_STACK_ALL = $(MK_THREAD_STACK_0) $(MK_THREAD_STACK_1) $(MK_THREAD_STACK_2) $(MK_THREAD_STACK_3) $(MK_THREAD_STACK_4) $(MK_THREAD_STACK_5) $(MK_THREAD_STACK_6) $(MK_THREAD_STACK_7) $(MK_THREAD_STACK_8) $(MK_THREAD_STACK_9) $(MK_THREAD_STACK_10) $(MK_THREAD_STACK_11) $(MK_THREAD_STACK_12) $(MK_THREAD_STACK_13)

#####################################################################
# Tasks
#####################################################################

# This variable tells the build process the number of stack slots that are generated
# for the stack type taskStack
OS_NUM_TASKSTACK_SLOTS = 14
#####################################################################
# Threads
#####################################################################

# This variable tells the build process the number of stack slots that are generated
# for the stack type threadStack
MK_NUM_THREADSTACK_SLOTS = 14
endif

