/* This file is generated automatically. DO NOT EDIT!!
 * 
 * EB tresos AutoCore OS 6.0.180 CORTEXM/S32K14X
 * (Build 20180906)
 * 
 * (c) 1998-2023 Elektrobit Automotive GmbH
 * Am Wolfsmantel 46
 * 91058 Erlangen
 * GERMANY
 * 
 * http://www.automotive.elektrobit.com
 * 
 */

#ifndef OS_CONFIG_H
#define OS_CONFIG_H
#ifdef __cplusplus
extern "C" {
#endif

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 8.6 (required)
 * An identifier with external linkage shall have exactly one external definition.
 *
 * Reason:
 * These symbols are defined in assembly language files and hence,
 * are not visible to the MISRA-C analyzer.
*/
#include <Os.h>
#include <Os_tool.h>
#include <CORTEXM/Os_CORTEXM_timer_fs_lpit.h>

#define OS_GENERATION_ID_OS_CONF_H 0x21b85288UL

#define OS_AUTOSAROS_VER 6

#define OS_AUTOSAROS_REV 0

#define OS_AUTOSAROS_CORE_BUILD 20180906

#define OS_AUTOSAROS_ARCH_BUILD 20180906

#ifndef OS_ASM
extern const os_uint32_t OS_os_GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OsApplication_0GenBuildId;
#endif  /* OS_ASM */
#ifndef OS_ASM
extern const os_uint32_t OS_OS_SYSTEM_0GenBuildId;
#endif  /* OS_ASM */

/*===================================================================
 * Alarms
 *==================================================================*/

#define OS_NALARMS 0
#define OS_NALARMCALLBACKS 0
#define OS_SchM_DefaultScheduleTable 0
#define OS_Rte_DefaultScheduleTable 1
#define OS_Rte_PostRunScheduleTable 2
#define OS_ALARM OS_ALARM_INIT(    /* OS_SchM_DefaultScheduleTable */  \
  OsApplication_0,                                     /* Application id */  \
  &OS_appTable[OsApplication_0],                       /* Application pointer */  \
  0x1U,                                                /* Permissions */  \
  &OS_WrapRunSchedule,                                 /* Schedule table wrapper */  \
  0,                                                   /* Not used */  \
  SchM_DefaultScheduleTable,                           /* Schedule table */  \
  OsCounter_HARDWARE,                                  /* Alarm counter */  \
  &OS_alarmDynamic_core0[0]                            /* dynamic data */  \
),  \
OS_ALARM_INIT(    /* OS_Rte_DefaultScheduleTable */  \
  OsApplication_0,                                     /* Application id */  \
  &OS_appTable[OsApplication_0],                       /* Application pointer */  \
  0x1U,                                                /* Permissions */  \
  &OS_WrapRunSchedule,                                 /* Schedule table wrapper */  \
  0,                                                   /* Not used */  \
  Rte_DefaultScheduleTable,                            /* Schedule table */  \
  OsCounter_HARDWARE,                                  /* Alarm counter */  \
  &OS_alarmDynamic_core0[1]                            /* dynamic data */  \
),  \
OS_ALARM_INIT(    /* OS_Rte_PostRunScheduleTable */  \
  OsApplication_0,                                     /* Application id */  \
  &OS_appTable[OsApplication_0],                       /* Application pointer */  \
  0x1U,                                                /* Permissions */  \
  &OS_WrapRunSchedule,                                 /* Schedule table wrapper */  \
  0,                                                   /* Not used */  \
  Rte_PostRunScheduleTable,                            /* Schedule table */  \
  OsCounter_HARDWARE,                                  /* Alarm counter */  \
  &OS_alarmDynamic_core0[2]                            /* dynamic data */  \
),
#define OS_NALARMS_CORE0 0

/*===================================================================
 * Application modes
 *==================================================================*/

#define OS_NSTARTMODES 1
#define OS_AUTOSTARTTASKS   OsTask_Bsw_Init,                                     \
  OS_NULLTASK
#define OS_STARTMODETASKS   0

/*===================================================================
 * Applications
 *==================================================================*/

#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(OsApplication_0);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(OsApplication_0);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(OsApplication_0);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(OsApplication_0);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_NAPPS 2
#define OS_NAPPSNONPRIV 0
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OS_SYSTEM_0 1
#endif
#define OS_APPCONFIG OS_APPCONFIG_INIT(    /* OsApplication_0 */  \
  &OS_OsApplication_0GenBuildId,                       /* Build ID */  \
  OS_NULL,                                             /* Startup Hook */  \
  OS_NULL,                                             /* Shutdown Hook */  \
  OS_NULL,                                             /* Error hook */  \
  &OS_TOOL_MR_START(OsApplication_0),                  /* start of data/bss */  \
  &OS_TOOL_MR_END(OsApplication_0),                    /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsApplication_0),              /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsApplication_0),                /* end of initial data */  \
  0x1,                                                 /* Permission Bit */  \
  0x1,                                                 /* Accessing applications */  \
  0,                                                   /* Startup hook stack */  \
  0,                                                   /* Shutdown hook stack */  \
  0,                                                   /* Error hook stack */  \
  OS_NULLTASK,                                         /* Restart Task */  \
  (OS_APP_TRUSTED),                                    /* Flags */  \
  OsApplication_0,                                     /* Application ID */  \
  &OS_appDynamic_core0[0],                             /* dynamic data */  \
  0,                                                   /* CPU core */  \
    OS_ARCHAPP_INIT(  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the private data region for MPU */  \
    )  \
),  \
OS_APPCONFIG_INIT(    /* OS_SYSTEM_0 */  \
  &OS_OS_SYSTEM_0GenBuildId,                           /* Build ID */  \
  OS_NULL,                                             /* Startup Hook */  \
  OS_NULL,                                             /* Shutdown Hook */  \
  OS_NULL,                                             /* Error hook */  \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  OS_NULL,                                             \
  0x3,                                                 /* Permission Bit */  \
  0x3,                                                 /* Accessing applications */  \
  0,                                                   /* Startup hook stack */  \
  0,                                                   /* Shutdown hook stack */  \
  0,                                                   /* Error hook stack */  \
  OS_NULLTASK,                                         /* Restart Task */  \
  (OS_APP_TRUSTED|OS_APP_SYSTEM),                      /* Flags */  \
  OS_SYSTEM_0,                                         /* Application ID */  \
  &OS_appDynamic_core0[1],                             /* dynamic data */  \
  0,                                                   /* CPU core */  \
    OS_ARCHAPP_INIT(  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the private data region for MPU */  \
    )  \
),
#define OS_NFUNCTIONS 0
#define OS_SHOOKSTACKLEN 0
#define OS_EHOOKSTACKLEN 0
#define OS_NAPPS_CORE0 2

/*===================================================================
 * CORTEXM memory region sizes for MPU
 *==================================================================*/

#define OS_CORTEXM_MPU_GLOBAL_ROM_SIZE OS_CORTEXM_MPU_SIZE_2M
#define OS_CORTEXM_MPU_GLOBAL_RAM_SIZE OS_CORTEXM_MPU_SIZE_256K
#define OS_CORTEXM_MPU_SHOOK_SIZE OS_CORTEXM_MPU_SIZE_DISABLED
#define OS_CORTEXM_MPU_EHOOK_SIZE OS_CORTEXM_MPU_SIZE_DISABLED
#define OS_CORTEXM_MPU_SHOOK_SIZE OS_CORTEXM_MPU_SIZE_DISABLED
#define OS_CORTEXM_MPU_EHOOK_SIZE OS_CORTEXM_MPU_SIZE_DISABLED

/*===================================================================
 * CPU Core configuration
 *==================================================================*/

#define OS_PROPERTIES_CORE0 (OS_U(0)|OS_COREPROP_USED_BIT)
/*===================================================================
 * Channel Initializers
 *==================================================================*/

#define OS_IOC_ENABLED 0
/*===================================================================
 * Configured Modes
 *==================================================================*/

#define OS_CONFIGMODE (OS_ECC2|OS_SCHEDMIX|OS_EXTENDED|OS_TRACE|OS_STACKCHECK|OS_DBGPROT_FULL|OS_VOIDERROR)
#define OS_IECMODE (OS_IEC_AUTOSAR)
#define OS_HOOKSELECTION (OS_ACTION_PROTECTIONHOOK|OS_ACTION_ERRORHOOK|OS_ACTION_ERRORHOOK_EB)
#define OS_PERMITTEDCONTEXT (OS_permittedContextAutosar)
#define OS_INCLUDE_RTE 0

/*===================================================================
 * Counters
 *==================================================================*/

#define OS_NCOUNTERS 1
#define OS_NSWCOUNTERS 0
#define OS_NGPTTICKERS 0
#define OS_COUNTER OS_COUNTER_INIT(    /* OsCounter_HARDWARE */  \
  OsApplication_0,                                     /* Application id */  \
  &OS_appTable[OsApplication_0],                       /* Application pointer */  \
  &OS_HwCounterUpdate,                                 \
  0x1U,                                                /* Permissions */  \
  &OS_hwTimer[0],                                      /* Hardware timer */  \
  (os_tick_t)4294967295U,                              /* Max allowed value */  \
  (os_tick_t)1U,                                       /* Ticks per base */  \
  (os_tick_t)1U,                                       /* Min cycle */  \
  &OS_counterDynamic_core0[0]                          /* dynamic data */  \
),
#define OS_NINTERNALTICKERS 0
#define OS_NCOUNTERS_CORE0 1

/*===================================================================
 * Events
 *==================================================================*/

#define OS_NEVENTS 2
/*===================================================================
 * Execution timer
 *==================================================================*/

#define OS_EXECUTIONTIMER_INIT     /* Execution timer init */  \
  OS_NULL
/*===================================================================
 * Hardware Timers
 *==================================================================*/

#define OS_NHWTIMERS 1
#define OS_NHWTIMERS_CORE0 1
#define OS_HWTIMER {    /* LPIT0_0 */  \
  &OS_timerLPITdriver,                                 /* Driver table */  \
  &OS_hwtLastValue_core0[0],                           \
  3221225472U,                                         /* Max delta */  \
  2147483648U,                                         /* Default delta if max exceeded */  \
  4294967295U,                                         /* Wrap mask */  \
  0U,                                                  /* Driver number */  \
  0U,                                                  /* Driver channel */  \
  0U                                                   /* core */  \
},

/*===================================================================
 * Hook Functions
 *==================================================================*/

#define OS_ERRORHOOK &ErrorHook
#define OS_SHUTDOWNHOOK &ShutdownHook
#define OS_PROTECTIONHOOK &ProtectionHook
/*===================================================================
 * Interrupts
 *==================================================================*/

#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(Can_IsrFCA_BO);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(Can_IsrFCA_BO);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(Can_IsrFCA_BO);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(Can_IsrFCA_BO);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_SRC4e_C0_NAME _OS_VECTOR_I078_CAN0_OFF_WARN
#define OS_SRC4e_C0_ISRID Can_IsrFCA_BO
#define OS_SRC4e_C0_ENTRY OS_Cat2Entry
#define OS_SRC4e_C0_EXIT OS_CORTEXM_IntCat2Exit
#define OS_SRC4e_C0_LOCKLEVEL OS_KERNLOCK
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(Can_IsrFCA_ERR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(Can_IsrFCA_ERR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(Can_IsrFCA_ERR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(Can_IsrFCA_ERR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_SRC4f_C0_NAME _OS_VECTOR_I079_CAN0_ERR
#define OS_SRC4f_C0_ISRID Can_IsrFCA_ERR
#define OS_SRC4f_C0_ENTRY OS_Cat2Entry
#define OS_SRC4f_C0_EXIT OS_CORTEXM_IntCat2Exit
#define OS_SRC4f_C0_LOCKLEVEL OS_KERNLOCK
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(Can_IsrFCA_MB_00_15);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(Can_IsrFCA_MB_00_15);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(Can_IsrFCA_MB_00_15);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(Can_IsrFCA_MB_00_15);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_SRC51_C0_NAME _OS_VECTOR_I081_CAN0_MSGBUF_0_15
#define OS_SRC51_C0_ISRID Can_IsrFCA_MB_00_15
#define OS_SRC51_C0_ENTRY OS_Cat2Entry
#define OS_SRC51_C0_EXIT OS_CORTEXM_IntCat2Exit
#define OS_SRC51_C0_LOCKLEVEL OS_KERNLOCK
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(Can_IsrFCA_MB_16_31);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(Can_IsrFCA_MB_16_31);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(Can_IsrFCA_MB_16_31);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(Can_IsrFCA_MB_16_31);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_SRC52_C0_NAME _OS_VECTOR_I082_CAN0_MSGBUF_16_31
#define OS_SRC52_C0_ISRID Can_IsrFCA_MB_16_31
#define OS_SRC52_C0_ENTRY OS_Cat2Entry
#define OS_SRC52_C0_EXIT OS_CORTEXM_IntCat2Exit
#define OS_SRC52_C0_LOCKLEVEL OS_KERNLOCK
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(FTM_0_CH_0_CH_1_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(FTM_0_CH_0_CH_1_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(FTM_0_CH_0_CH_1_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(FTM_0_CH_0_CH_1_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_SRC63_C0_NAME _OS_VECTOR_I099_FTM0_CH01
#define OS_SRC63_C0_ISRID FTM_0_CH_0_CH_1_ISR
#define OS_SRC63_C0_ENTRY OS_Cat2Entry
#define OS_SRC63_C0_EXIT OS_CORTEXM_IntCat2Exit
#define OS_SRC63_C0_LOCKLEVEL OS_KERNLOCK
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(LPTMR_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(LPTMR_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(LPTMR_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(LPTMR_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_SRC3a_C0_NAME _OS_VECTOR_I058_LPTIMER
#define OS_SRC3a_C0_ISRID LPTMR_ISR
#define OS_SRC3a_C0_ENTRY OS_Cat1Entry
#define OS_SRC3a_C0_EXIT OS_CORTEXM_IntCat1Exit
#define OS_SRC3a_C0_LOCKLEVEL 3
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(PORTD_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(PORTD_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(PORTD_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(PORTD_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_SRC3e_C0_NAME _OS_VECTOR_I062_PCM_PIN_PD
#define OS_SRC3e_C0_ISRID PORTD_ISR
#define OS_SRC3e_C0_ENTRY OS_Cat1Entry
#define OS_SRC3e_C0_EXIT OS_CORTEXM_IntCat1Exit
#define OS_SRC3e_C0_LOCKLEVEL 2
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(FTM_0_CH_2_CH_3_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(FTM_0_CH_2_CH_3_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(FTM_0_CH_2_CH_3_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(FTM_0_CH_2_CH_3_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_SRC64_C0_NAME _OS_VECTOR_I100_FTM0_CH23
#define OS_SRC64_C0_ISRID FTM_0_CH_2_CH_3_ISR
#define OS_SRC64_C0_ENTRY OS_Cat2Entry
#define OS_SRC64_C0_EXIT OS_CORTEXM_IntCat2Exit
#define OS_SRC64_C0_LOCKLEVEL OS_KERNLOCK
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(PORTE_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(PORTE_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(PORTE_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(PORTE_ISR);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_SRC3f_C0_NAME _OS_VECTOR_I063_PCM_PIN_PE
#define OS_SRC3f_C0_ISRID PORTE_ISR
#define OS_SRC3f_C0_ENTRY OS_Cat2Entry
#define OS_SRC3f_C0_EXIT OS_CORTEXM_IntCat2Exit
#define OS_SRC3f_C0_LOCKLEVEL OS_KERNLOCK
#define OS_SRC30_C0_NAME _OS_VECTOR_I048_LPIT_C0
#define OS_SRC30_C0_ISRID Os_Counter_LPIT0_0
#define OS_SRC30_C0_ENTRY OS_Cat2Entry
#define OS_SRC30_C0_EXIT OS_CORTEXM_IntCat2Exit
#define OS_SRC30_C0_LOCKLEVEL OS_KERNLOCK
#define OS_NINTERRUPTS 10
#define OS_NCAT1_INTERRUPTS 2
#define OS_NCAT2_INTERRUPTS 8
#define OS_NCATK_INTERRUPTS 0
#define OS_NCAT2K_INTERRUPTS 0
#define OS_NISRSEXECTIMELIMIT 0
#define OS_NISRSINTLOCKLIMIT 0
#define OS_NISRSRESLOCKLIMIT 0
#define OS_NISRACCOUNTING 0
#define OS_CAT1LOCK 2
#define OS_CAT2LOCK 4
#define OS_KERNLOCK 4
#define OS_XCOREUNLOCK OS_KERNLOCK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Os_Counter_LPIT0_0 9
#endif
#define OS_ISRCONFIG OS_ISRCONFIG_INIT(    /* Can_IsrFCA_BO */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Can_IsrFCA_BO),                    /* start of data/bss */  \
  &OS_TOOL_MR_END(Can_IsrFCA_BO),                      /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Can_IsrFCA_BO),                /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Can_IsrFCA_BO),                  /* end of initial data */  \
  &OS_ISR_Can_IsrFCA_BO,                               /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  256U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  Can_IsrFCA_BO,                                       /* Isr id */  \
  &OS_isrDynamic_core0[0],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      78,                                                  /* ISR source */  \
      7,                                                   /* ISR priority */  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the ISR stack for MPU */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Can_IsrFCA_ERR */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Can_IsrFCA_ERR),                   /* start of data/bss */  \
  &OS_TOOL_MR_END(Can_IsrFCA_ERR),                     /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Can_IsrFCA_ERR),               /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Can_IsrFCA_ERR),                 /* end of initial data */  \
  &OS_ISR_Can_IsrFCA_ERR,                              /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  256U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  Can_IsrFCA_ERR,                                      /* Isr id */  \
  &OS_isrDynamic_core0[1],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      79,                                                  /* ISR source */  \
      7,                                                   /* ISR priority */  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the ISR stack for MPU */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Can_IsrFCA_MB_00_15 */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Can_IsrFCA_MB_00_15),              /* start of data/bss */  \
  &OS_TOOL_MR_END(Can_IsrFCA_MB_00_15),                /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Can_IsrFCA_MB_00_15),          /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Can_IsrFCA_MB_00_15),            /* end of initial data */  \
  &OS_ISR_Can_IsrFCA_MB_00_15,                         /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  256U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  Can_IsrFCA_MB_00_15,                                 /* Isr id */  \
  &OS_isrDynamic_core0[2],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      81,                                                  /* ISR source */  \
      7,                                                   /* ISR priority */  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the ISR stack for MPU */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Can_IsrFCA_MB_16_31 */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(Can_IsrFCA_MB_16_31),              /* start of data/bss */  \
  &OS_TOOL_MR_END(Can_IsrFCA_MB_16_31),                /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(Can_IsrFCA_MB_16_31),          /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(Can_IsrFCA_MB_16_31),            /* end of initial data */  \
  &OS_ISR_Can_IsrFCA_MB_16_31,                         /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  256U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  Can_IsrFCA_MB_16_31,                                 /* Isr id */  \
  &OS_isrDynamic_core0[3],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      82,                                                  /* ISR source */  \
      7,                                                   /* ISR priority */  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the ISR stack for MPU */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* FTM_0_CH_0_CH_1_ISR */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(FTM_0_CH_0_CH_1_ISR),              /* start of data/bss */  \
  &OS_TOOL_MR_END(FTM_0_CH_0_CH_1_ISR),                /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(FTM_0_CH_0_CH_1_ISR),          /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(FTM_0_CH_0_CH_1_ISR),            /* end of initial data */  \
  &OS_ISR_FTM_0_CH_0_CH_1_ISR,                         /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  128U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  FTM_0_CH_0_CH_1_ISR,                                 /* Isr id */  \
  &OS_isrDynamic_core0[4],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      99,                                                  /* ISR source */  \
      6,                                                   /* ISR priority */  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the ISR stack for MPU */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* LPTMR_ISR */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(LPTMR_ISR),                        /* start of data/bss */  \
  &OS_TOOL_MR_END(LPTMR_ISR),                          /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(LPTMR_ISR),                    /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(LPTMR_ISR),                      /* end of initial data */  \
  &OS_ISR_LPTMR_ISR,                                   /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  128U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  LPTMR_ISR,                                           /* Isr id */  \
  &OS_isrDynamic_core0[5],                             /* dynamic data */  \
  (OS_ISRF_CAT1|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      58,                                                  /* ISR source */  \
      3,                                                   /* ISR priority */  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the ISR stack for MPU */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* PORTD_ISR */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(PORTD_ISR),                        /* start of data/bss */  \
  &OS_TOOL_MR_END(PORTD_ISR),                          /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(PORTD_ISR),                    /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(PORTD_ISR),                      /* end of initial data */  \
  &OS_ISR_PORTD_ISR,                                   /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  128U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  PORTD_ISR,                                           /* Isr id */  \
  &OS_isrDynamic_core0[6],                             /* dynamic data */  \
  (OS_ISRF_CAT1|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      62,                                                  /* ISR source */  \
      2,                                                   /* ISR priority */  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the ISR stack for MPU */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* FTM_0_CH_2_CH_3_ISR */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(FTM_0_CH_2_CH_3_ISR),              /* start of data/bss */  \
  &OS_TOOL_MR_END(FTM_0_CH_2_CH_3_ISR),                /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(FTM_0_CH_2_CH_3_ISR),          /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(FTM_0_CH_2_CH_3_ISR),            /* end of initial data */  \
  &OS_ISR_FTM_0_CH_2_CH_3_ISR,                         /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  128U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  FTM_0_CH_2_CH_3_ISR,                                 /* Isr id */  \
  &OS_isrDynamic_core0[7],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      100,                                                 /* ISR source */  \
      6,                                                   /* ISR priority */  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the ISR stack for MPU */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* PORTE_ISR */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(PORTE_ISR),                        /* start of data/bss */  \
  &OS_TOOL_MR_END(PORTE_ISR),                          /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(PORTE_ISR),                    /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(PORTE_ISR),                      /* end of initial data */  \
  &OS_ISR_PORTE_ISR,                                   /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  128U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  PORTE_ISR,                                           /* Isr id */  \
  &OS_isrDynamic_core0[8],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      63,                                                  /* ISR source */  \
      5,                                                   /* ISR priority */  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the ISR stack for MPU */  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Os_Counter_LPIT0_0 */  \
  &OS_appTable[OS_SYSTEM_0],                           /* Application */  \
  0x3U,                                                /* Permissions */  \
  OS_NULL,                                             /* Accounting structure */  \
  OS_NULL,                                             /* start of data/bss */  \
  OS_NULL,                                             /* end of data/bss */  \
  OS_NULL,                                             /* start of initial data */  \
  OS_NULL,                                             /* start of initial data */  \
  &OS_CounterIsr_OsCounter_HARDWARE,                   /* Interrupt entry */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  512U,                                                /* Stack size */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  Os_Counter_LPIT0_0,                                  /* Isr id */  \
  &OS_isrDynamic_core0[9],                             /* dynamic data */  \
  (OS_ISRF_CAT2|OS_ISRF_ENABLE),                       /* Flags */  \
    OS_ARCHISR_INIT(  \
      48,                                                  /* ISR source */  \
      4,                                                   /* ISR priority */  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the ISR stack for MPU */  \
    )  \
),
#define OS_ISTACKBASE_0 OS_kernStack0
#define OS_ISTACKLEN_0 OS_U( 4864 )
#define OS_NINTERRUPTS_CORE0 10
#define OS_NISRACCOUNTING_CORE0 0

/*===================================================================
 * Kernel data
 *==================================================================*/

#define OS_KERNELDATA_INIT_CORE0     /* kernel data core 0 */  \
  OS_NULL,                                             /* taskQueueHead */  \
  OS_NULL,                                             /* taskCurrent */  \
  OS_GetInitialStackPointer(OS_ISTACKBASE_0, OS_ISTACKLEN_0),  /* iSpInitial */  \
  OS_NULL,                                             /* pointer to CPU load */  \
  OS_NULL,                                             /* hookApp */  \
  0,                                                   /* inKernel */  \
  0,                                                   /* inFunction */  \
  OS_ISTACKBASE_0,                                     /* iStackBase */  \
  OS_ISTACKLEN_0,                                      /* iStackLen */  \
  OS_NULLISR,                                          /* isrCurrent */  \
  OS_NULLOBJECT,                                       /* isrLastLock */  \
  0U,                                                  /* masterPrioWord */  \
  0,                                                   /* oldSuspendOs */  \
  0,                                                   /* oldSuspendAll */  \
  0,                                                   /* nestSuspendOs */  \
  0,                                                   /* nestSuspendAll */  \
  OS_ERRORSTATUS_INIT,                                 /* errorStatus */  \
  OS_FASTSUSPENDRESUMESTATUS_INIT,                     /* fastSuspendResumeStatus */  \
  OS_HOOKCONTEXT_INIT,                                 /* sHookContext */  \
  OS_HOOKCONTEXT_INIT,                                 /* eHookContext */  \
  0,                                                   /* errorHookNesting */  \
  OS_ACCOUNTINGS_INIT,                                 /* accounting */  \
  0,                                                   /* appsStarted */  \
  OS_PANIC_NONE                                        /* panicCode */

/*===================================================================
 * Optimization
 *==================================================================*/

#define OS_CAT1_DIRECTCALL 0
/*===================================================================
 * Rate Monitor
 *==================================================================*/

#define OS_NRATEMONS 0
#define OS_NRATEMONS_CORE0 0
#define OS_NRATETIMERS OS_NRATETIMERS_CORE0
#define OS_RATEMONCONFIG OS_RATEMONCONFIG_CORE0

/*===================================================================
 * Resource Lock Timing
 *==================================================================*/

#define OS_NRESLOCKTIMES 0
/*===================================================================
 * Resources
 *==================================================================*/

#define OS_NRESOURCES 1
#define OS_RESOURCES OS_RESOURCES_INIT(    /* RES_SCHEDULER_0 */  \
  &OS_appTable[OS_SYSTEM_0],                           /* Application */  \
  0x3U,                                                /* Permissions */  \
  12,                                                  /* Priority */  \
  &OS_resourceDynamic_core0[0]                         /* dynamic data */  \
),
#define OS_NRESOURCES_CORE0 1

/*===================================================================
 * Schedule Tables
 *==================================================================*/

#define OS_NSCHEDULES 3
#define OS_NSCHEDULESSYNC 0
#define OS_STCONFIG OS_STCONFIG_INIT(    /* SchM_DefaultScheduleTable */  \
  OsApplication_0,                                     /* Application id */  \
  &OS_appTable[OsApplication_0],                       /* Application pointer */  \
  0x1U,                                                /* Permissions */  \
  &OS_stEntries[0],                                    /* Schedule table entries */  \
  400000,                                              /* Duration */  \
  0,                                                   /* Cut off */  \
  0,                                                   /* Precision */  \
  0,                                                   /* Alarm ID */  \
  4,                                                   /* Number of expiry points */  \
  (OS_ST_REPEATING),                                   /* Flags */  \
  &OS_scheduleDynamic_core0[0]                         /* dynamic data */  \
),  \
OS_STCONFIG_INIT(    /* Rte_DefaultScheduleTable */  \
  OsApplication_0,                                     /* Application id */  \
  &OS_appTable[OsApplication_0],                       /* Application pointer */  \
  0x1U,                                                /* Permissions */  \
  &OS_stEntries[4],                                    /* Schedule table entries */  \
  400000,                                              /* Duration */  \
  0,                                                   /* Cut off */  \
  0,                                                   /* Precision */  \
  1,                                                   /* Alarm ID */  \
  36,                                                  /* Number of expiry points */  \
  (OS_ST_REPEATING),                                   /* Flags */  \
  &OS_scheduleDynamic_core0[1]                         /* dynamic data */  \
),  \
OS_STCONFIG_INIT(    /* Rte_PostRunScheduleTable */  \
  OsApplication_0,                                     /* Application id */  \
  &OS_appTable[OsApplication_0],                       /* Application pointer */  \
  0x1U,                                                /* Permissions */  \
  &OS_stEntries[40],                                   /* Schedule table entries */  \
  400000,                                              /* Duration */  \
  0,                                                   /* Cut off */  \
  0,                                                   /* Precision */  \
  2,                                                   /* Alarm ID */  \
  5,                                                   /* Number of expiry points */  \
  (OS_ST_REPEATING),                                   /* Flags */  \
  &OS_scheduleDynamic_core0[2]                         /* dynamic data */  \
),
#define OS_NSTENTRIES 45
#define OS_STENTRIES     /* OsScheduleTableExpiryPoint_1000 */  \
    {  \
      40000,                                               /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Bsw_SysServices                               /* Task */  \
    },  \
    /* OsScheduleTableExpiryPoint_3000 */  \
    {  \
      120000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Bsw_ComServices                               /* Task */  \
    },  \
    /* OsScheduleTableExpiryPoint_8000 */  \
    {  \
      320000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Bsw_ComServices                               /* Task */  \
    },  \
    /* OsScheduleTableExpiryPoint_9000 */  \
    {  \
      360000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_ComHwAbs                                  /* Task */  \
    },  \
    /* OsScheduleTableExpiryPoint_0000 */  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_EcuHwAbs                                  /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_Autotests                                 /* Task */  \
    },  \
    {  \
      0,                                                   /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_eCSApp                                    /* Task */  \
    },  \
    /* OsScheduleTableExpiryPoint_1000 */  \
    {  \
      40000,                                               /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_Autotests                                 /* Task */  \
    },  \
    {  \
      40000,                                               /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_eCSApp                                    /* Task */  \
    },  \
    {  \
      40000,                                               /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_ComServices                               /* Task */  \
    },  \
    {  \
      40000,                                               /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Bsw_SysServices                               /* Task */  \
    },  \
    /* OsScheduleTableExpiryPoint_2000 */  \
    {  \
      80000,                                               /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_EcuHwAbs                                  /* Task */  \
    },  \
    {  \
      80000,                                               /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_Autotests                                 /* Task */  \
    },  \
    {  \
      80000,                                               /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_eCSApp                                    /* Task */  \
    },  \
    /* OsScheduleTableExpiryPoint_3000 */  \
    {  \
      120000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_Autotests                                 /* Task */  \
    },  \
    {  \
      120000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_eCSApp                                    /* Task */  \
    },  \
    {  \
      120000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_ComServices                               /* Task */  \
    },  \
    {  \
      120000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Bsw_ComServices                               /* Task */  \
    },  \
    /* OsScheduleTableExpiryPoint_4000 */  \
    {  \
      160000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_EcuHwAbs                                  /* Task */  \
    },  \
    {  \
      160000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_Autotests                                 /* Task */  \
    },  \
    {  \
      160000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_eCSApp                                    /* Task */  \
    },  \
    {  \
      160000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_ModeMngmt                                 /* Task */  \
    },  \
    /* OsScheduleTableExpiryPoint_5000 */  \
    {  \
      200000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_Autotests                                 /* Task */  \
    },  \
    {  \
      200000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_eCSApp                                    /* Task */  \
    },  \
    {  \
      200000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_ComServices                               /* Task */  \
    },  \
    /* OsScheduleTableExpiryPoint_6000 */  \
    {  \
      240000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_EcuHwAbs                                  /* Task */  \
    },  \
    {  \
      240000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_eCSApp                                    /* Task */  \
    },  \
    {  \
      240000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_Autotests                                 /* Task */  \
    },  \
    {  \
      240000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Bsw_MemServices                               /* Task */  \
    },  \
    /* OsScheduleTableExpiryPoint_7000 */  \
    {  \
      280000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_Autotests                                 /* Task */  \
    },  \
    {  \
      280000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_eCSApp                                    /* Task */  \
    },  \
    {  \
      280000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_ComServices                               /* Task */  \
    },  \
    /* OsScheduleTableExpiryPoint_8000 */  \
    {  \
      320000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_EcuHwAbs                                  /* Task */  \
    },  \
    {  \
      320000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_Autotests                                 /* Task */  \
    },  \
    {  \
      320000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_eCSApp                                    /* Task */  \
    },  \
    {  \
      320000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Bsw_ComServices                               /* Task */  \
    },  \
    /* OsScheduleTableExpiryPoint_9000 */  \
    {  \
      360000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_Autotests                                 /* Task */  \
    },  \
    {  \
      360000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_eCSApp                                    /* Task */  \
    },  \
    {  \
      360000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_ComServices                               /* Task */  \
    },  \
    {  \
      360000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_ComHwAbs                                  /* Task */  \
    },  \
    /* OsScheduleTableExpiryPoint_1000 */  \
    {  \
      40000,                                               /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Bsw_SysServices                               /* Task */  \
    },  \
    /* OsScheduleTableExpiryPoint_3000 */  \
    {  \
      120000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Bsw_ComServices                               /* Task */  \
    },  \
    /* OsScheduleTableExpiryPoint_8000 */  \
    {  \
      320000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Bsw_ComServices                               /* Task */  \
    },  \
    /* OsScheduleTableExpiryPoint_9000 */  \
    {  \
      360000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Alv_ComHwAbs                                  /* Task */  \
    },  \
    {  \
      360000,                                              /* Offset */  \
      0,                                                   /* Max advance */  \
      0,                                                   /* Max retard */  \
      0,                                                   /* Event */  \
      OsTask_Bsw_ReadWrite_AllProcess                      /* Task */  \
    }
#define OS_NSCHEDULES_CORE0 3

/*===================================================================
 * Spinlocks
 *==================================================================*/

#define OS_NAUTOSARSPINLOCKS 0
/*===================================================================
 * Stacks
 *==================================================================*/

#define OS_STACK_REGION_ALIGNMENT 32
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot0, .bss.core0.os_taskstack0_slot0, 152, 32);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot1, .bss.core0.os_taskstack0_slot1, 152, 32);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot2, .bss.core0.os_taskstack0_slot2, 216, 32);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot3, .bss.core0.os_taskstack0_slot3, 152, 32);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot4, .bss.core0.os_taskstack0_slot4, 216, 32);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot5, .bss.core0.os_taskstack0_slot5, 152, 32);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot6, .bss.core0.os_taskstack0_slot6, 56, 32);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot7, .bss.core0.os_taskstack0_slot7, 152, 32);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot8, .bss.core0.os_taskstack0_slot8, 152, 32);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot9, .bss.core0.os_taskstack0_slot9, 280, 32);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot10, .bss.core0.os_taskstack0_slot10, 280, 32);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot11, .bss.core0.os_taskstack0_slot11, 88, 32);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot12, .bss.core0.os_taskstack0_slot12, 152, 32);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_taskStack0_slot13, .bss.core0.os_taskstack0_slot13, 152, 32);
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL(OS_kernStack0, .bss.core0.os_kernstack0, 1216, 32);
#endif
#endif  /* OS_ASM */

/*===================================================================
 * Tasks
 *==================================================================*/

#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(OsTask_Bsw_ReadWrite_AllProcess);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(OsTask_Bsw_ReadWrite_AllProcess);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Bsw_ReadWrite_AllProcess);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Bsw_ReadWrite_AllProcess);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Bsw_ReadWrite_AllProcess);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(OsTask_AppIdle);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(OsTask_AppIdle);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_AppIdle);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_AppIdle);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_AppIdle);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(OsTask_Bsw_ComServices);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(OsTask_Bsw_ComServices);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Bsw_ComServices);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Bsw_ComServices);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Bsw_ComServices);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(OsTask_Bsw_SysServices);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(OsTask_Bsw_SysServices);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Bsw_SysServices);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Bsw_SysServices);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Bsw_SysServices);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(OsTask_Bsw_MemServices);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(OsTask_Bsw_MemServices);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Bsw_MemServices);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Bsw_MemServices);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Bsw_MemServices);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(OsTask_Alv_ComHwAbs);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(OsTask_Alv_ComHwAbs);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Alv_ComHwAbs);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Alv_ComHwAbs);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Alv_ComHwAbs);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(OsTask_Bsw_Init);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(OsTask_Bsw_Init);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Bsw_Init);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Bsw_Init);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Bsw_Init);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(OsTask_Bsw_Events);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(OsTask_Bsw_Events);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Bsw_Events);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Bsw_Events);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Bsw_Events);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(OsTask_Alv_eCSApp);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(OsTask_Alv_eCSApp);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Alv_eCSApp);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Alv_eCSApp);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Alv_eCSApp);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(OsTask_Alv_Autotests);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(OsTask_Alv_Autotests);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Alv_Autotests);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Alv_Autotests);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Alv_Autotests);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(OsTask_Alv_ComServices);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(OsTask_Alv_ComServices);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Alv_ComServices);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Alv_ComServices);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Alv_ComServices);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(OsTask_Alv_EcuHwAbs);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(OsTask_Alv_EcuHwAbs);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Alv_EcuHwAbs);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Alv_EcuHwAbs);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Alv_EcuHwAbs);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(OsTask_Alv_ModeMngmt);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(OsTask_Alv_ModeMngmt);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Alv_ModeMngmt);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Alv_ModeMngmt);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Alv_ModeMngmt);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_START(OsTask_Bsw_ComEvents);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_END(OsTask_Bsw_ComEvents);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Bsw_ComEvents);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Bsw_ComEvents);
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Bsw_ComEvents);
#endif  /* OS_ASM */
#define OS_NTASKS 14
#define OS_NETASKS 2
#define OS_NTASKSEXECTIMELIMIT 0
#define OS_NTASKSINTLOCKLIMIT 0
#define OS_NTASKSRESLOCKLIMIT 0
#define OS_TASKCONFIG OS_TASKCONFIG_INIT(    /* OsTask_Bsw_ReadWrite_AllProcess */  \
  &OS_taskDynamic_core0[0],                            /* Dynamic task structure */  \
  1U,                                                  /* Run priority */  \
  1U,                                                  /* Queuing priority */  \
  1,                                                   /* Activation index */  \
  &OS_TASK_OsTask_Bsw_ReadWrite_AllProcess,            /* Task entry */  \
  &OS_taskStack0_slot0[0],                             /* Stack base */  \
  608U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  OsTask_Bsw_ReadWrite_AllProcess,                     /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(OsTask_Bsw_ReadWrite_AllProcess),  /* start of data/bss */  \
  &OS_TOOL_MR_END(OsTask_Bsw_ReadWrite_AllProcess),    /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsTask_Bsw_ReadWrite_AllProcess),  /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsTask_Bsw_ReadWrite_AllProcess),  /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the task stack for MPU */  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_AppIdle */  \
  &OS_taskDynamic_core0[1],                            /* Dynamic task structure */  \
  0U,                                                  /* Run priority */  \
  0U,                                                  /* Queuing priority */  \
  2,                                                   /* Activation index */  \
  &OS_TASK_OsTask_AppIdle,                             /* Task entry */  \
  &OS_taskStack0_slot1[0],                             /* Stack base */  \
  608U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_EXTENDED),                                    /* Flags */  \
  OsTask_AppIdle,                                      /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(OsTask_AppIdle),                   /* start of data/bss */  \
  &OS_TOOL_MR_END(OsTask_AppIdle),                     /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsTask_AppIdle),               /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsTask_AppIdle),                 /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the task stack for MPU */  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Bsw_ComServices */  \
  &OS_taskDynamic_core0[2],                            /* Dynamic task structure */  \
  8U,                                                  /* Run priority */  \
  8U,                                                  /* Queuing priority */  \
  3,                                                   /* Activation index */  \
  &OS_TASK_OsTask_Bsw_ComServices,                     /* Task entry */  \
  &OS_taskStack0_slot2[0],                             /* Stack base */  \
  864U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  OsTask_Bsw_ComServices,                              /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(OsTask_Bsw_ComServices),           /* start of data/bss */  \
  &OS_TOOL_MR_END(OsTask_Bsw_ComServices),             /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsTask_Bsw_ComServices),       /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsTask_Bsw_ComServices),         /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the task stack for MPU */  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Bsw_SysServices */  \
  &OS_taskDynamic_core0[3],                            /* Dynamic task structure */  \
  6U,                                                  /* Run priority */  \
  6U,                                                  /* Queuing priority */  \
  4,                                                   /* Activation index */  \
  &OS_TASK_OsTask_Bsw_SysServices,                     /* Task entry */  \
  &OS_taskStack0_slot3[0],                             /* Stack base */  \
  608U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  OsTask_Bsw_SysServices,                              /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(OsTask_Bsw_SysServices),           /* start of data/bss */  \
  &OS_TOOL_MR_END(OsTask_Bsw_SysServices),             /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsTask_Bsw_SysServices),       /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsTask_Bsw_SysServices),         /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the task stack for MPU */  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Bsw_MemServices */  \
  &OS_taskDynamic_core0[4],                            /* Dynamic task structure */  \
  12U,                                                 /* Run priority */  \
  4U,                                                  /* Queuing priority */  \
  5,                                                   /* Activation index */  \
  &OS_TASK_OsTask_Bsw_MemServices,                     /* Task entry */  \
  &OS_taskStack0_slot4[0],                             /* Stack base */  \
  864U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  (OS_TF_NONPREEMPT),                                  /* Flags */  \
  OsTask_Bsw_MemServices,                              /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(OsTask_Bsw_MemServices),           /* start of data/bss */  \
  &OS_TOOL_MR_END(OsTask_Bsw_MemServices),             /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsTask_Bsw_MemServices),       /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsTask_Bsw_MemServices),         /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the task stack for MPU */  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Alv_ComHwAbs */  \
  &OS_taskDynamic_core0[5],                            /* Dynamic task structure */  \
  7U,                                                  /* Run priority */  \
  7U,                                                  /* Queuing priority */  \
  6,                                                   /* Activation index */  \
  &OS_TASK_OsTask_Alv_ComHwAbs,                        /* Task entry */  \
  &OS_taskStack0_slot5[0],                             /* Stack base */  \
  608U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  OsTask_Alv_ComHwAbs,                                 /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(OsTask_Alv_ComHwAbs),              /* start of data/bss */  \
  &OS_TOOL_MR_END(OsTask_Alv_ComHwAbs),                /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsTask_Alv_ComHwAbs),          /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsTask_Alv_ComHwAbs),            /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the task stack for MPU */  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Bsw_Init */  \
  &OS_taskDynamic_core0[6],                            /* Dynamic task structure */  \
  3U,                                                  /* Run priority */  \
  3U,                                                  /* Queuing priority */  \
  7,                                                   /* Activation index */  \
  &OS_TASK_OsTask_Bsw_Init,                            /* Task entry */  \
  &OS_taskStack0_slot6[0],                             /* Stack base */  \
  224U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  OsTask_Bsw_Init,                                     /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(OsTask_Bsw_Init),                  /* start of data/bss */  \
  &OS_TOOL_MR_END(OsTask_Bsw_Init),                    /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsTask_Bsw_Init),              /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsTask_Bsw_Init),                /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the task stack for MPU */  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Bsw_Events */  \
  &OS_taskDynamic_core0[7],                            /* Dynamic task structure */  \
  2U,                                                  /* Run priority */  \
  2U,                                                  /* Queuing priority */  \
  8,                                                   /* Activation index */  \
  &OS_TASK_OsTask_Bsw_Events,                          /* Task entry */  \
  &OS_taskStack0_slot7[0],                             /* Stack base */  \
  608U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  OsTask_Bsw_Events,                                   /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(OsTask_Bsw_Events),                /* start of data/bss */  \
  &OS_TOOL_MR_END(OsTask_Bsw_Events),                  /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsTask_Bsw_Events),            /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsTask_Bsw_Events),              /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the task stack for MPU */  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Alv_eCSApp */  \
  &OS_taskDynamic_core0[8],                            /* Dynamic task structure */  \
  10U,                                                 /* Run priority */  \
  10U,                                                 /* Queuing priority */  \
  9,                                                   /* Activation index */  \
  &OS_TASK_OsTask_Alv_eCSApp,                          /* Task entry */  \
  &OS_taskStack0_slot8[0],                             /* Stack base */  \
  608U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  OsTask_Alv_eCSApp,                                   /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(OsTask_Alv_eCSApp),                /* start of data/bss */  \
  &OS_TOOL_MR_END(OsTask_Alv_eCSApp),                  /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsTask_Alv_eCSApp),            /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsTask_Alv_eCSApp),              /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the task stack for MPU */  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Alv_Autotests */  \
  &OS_taskDynamic_core0[9],                            /* Dynamic task structure */  \
  11U,                                                 /* Run priority */  \
  11U,                                                 /* Queuing priority */  \
  10,                                                  /* Activation index */  \
  &OS_TASK_OsTask_Alv_Autotests,                       /* Task entry */  \
  &OS_taskStack0_slot9[0],                             /* Stack base */  \
  1120U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  OsTask_Alv_Autotests,                                /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(OsTask_Alv_Autotests),             /* start of data/bss */  \
  &OS_TOOL_MR_END(OsTask_Alv_Autotests),               /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsTask_Alv_Autotests),         /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsTask_Alv_Autotests),           /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the task stack for MPU */  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Alv_ComServices */  \
  &OS_taskDynamic_core0[10],                           /* Dynamic task structure */  \
  9U,                                                  /* Run priority */  \
  9U,                                                  /* Queuing priority */  \
  11,                                                  /* Activation index */  \
  &OS_TASK_OsTask_Alv_ComServices,                     /* Task entry */  \
  &OS_taskStack0_slot10[0],                            /* Stack base */  \
  1120U,                                               /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  OsTask_Alv_ComServices,                              /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(OsTask_Alv_ComServices),           /* start of data/bss */  \
  &OS_TOOL_MR_END(OsTask_Alv_ComServices),             /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsTask_Alv_ComServices),       /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsTask_Alv_ComServices),         /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the task stack for MPU */  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Alv_EcuHwAbs */  \
  &OS_taskDynamic_core0[11],                           /* Dynamic task structure */  \
  12U,                                                 /* Run priority */  \
  12U,                                                 /* Queuing priority */  \
  12,                                                  /* Activation index */  \
  &OS_TASK_OsTask_Alv_EcuHwAbs,                        /* Task entry */  \
  &OS_taskStack0_slot11[0],                            /* Stack base */  \
  352U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  OsTask_Alv_EcuHwAbs,                                 /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(OsTask_Alv_EcuHwAbs),              /* start of data/bss */  \
  &OS_TOOL_MR_END(OsTask_Alv_EcuHwAbs),                /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsTask_Alv_EcuHwAbs),          /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsTask_Alv_EcuHwAbs),            /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the task stack for MPU */  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Alv_ModeMngmt */  \
  &OS_taskDynamic_core0[12],                           /* Dynamic task structure */  \
  5U,                                                  /* Run priority */  \
  5U,                                                  /* Queuing priority */  \
  13,                                                  /* Activation index */  \
  &OS_TASK_OsTask_Alv_ModeMngmt,                       /* Task entry */  \
  &OS_taskStack0_slot12[0],                            /* Stack base */  \
  608U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  OsTask_Alv_ModeMngmt,                                /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(OsTask_Alv_ModeMngmt),             /* start of data/bss */  \
  &OS_TOOL_MR_END(OsTask_Alv_ModeMngmt),               /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsTask_Alv_ModeMngmt),         /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsTask_Alv_ModeMngmt),           /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the task stack for MPU */  \
    )  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Bsw_ComEvents */  \
  &OS_taskDynamic_core0[13],                           /* Dynamic task structure */  \
  2U,                                                  /* Run priority */  \
  2U,                                                  /* Queuing priority */  \
  14,                                                  /* Activation index */  \
  &OS_TASK_OsTask_Bsw_ComEvents,                       /* Task entry */  \
  &OS_taskStack0_slot13[0],                            /* Stack base */  \
  608U,                                                /* Stack size */  \
  0U,                                                  /* Max. activations */  \
  0,                                                   /* Flags */  \
  OsTask_Bsw_ComEvents,                                /* Task ID */  \
  OS_NULL,                                             /* Accounting structure */  \
  &OS_TOOL_MR_START(OsTask_Bsw_ComEvents),             /* start of data/bss */  \
  &OS_TOOL_MR_END(OsTask_Bsw_ComEvents),               /* end of data/bss */  \
  &OS_TOOL_MR_LMA_START(OsTask_Bsw_ComEvents),         /* start of initial data */  \
  &OS_TOOL_MR_LMA_END(OsTask_Bsw_ComEvents),           /* end of initial data */  \
  0U,                                                  /* Execution budget */  \
  0U,                                                  /* Os interrupt lock budget */  \
  0U,                                                  /* All interrupt lock budget */  \
  OS_NULL,                                             /* Resource lock budget */  \
  OS_NULLRATEMONITOR,                                  /* Rate monitor */  \
  &OS_appTable[OsApplication_0],                       /* Application */  \
  0x1U,                                                /* Permissions */  \
    OS_ARCHTASK_INIT(  \
      OS_CORTEXM_MPU_SIZE_DISABLED,                        /* size of the private data region for MPU */  \
      OS_CORTEXM_MPU_SIZE_DISABLED                         /* size of the task stack for MPU */  \
    )  \
),
#define OS_NTASKS_CORE0 14

/*===================================================================
 * Tasks CLZ Scheduling
 *==================================================================*/

#define OS_NPRIORITYQUEUEDYNAMICS_CORE0 2
#define OS_NPRIORITYSLOTS_CORE0 15
#define OS_PRIORITYQUEUE_INIT_CORE0 {    /* Priority 0 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_PRIORITYSLOT_OBJ_CORE0[0U],                      \
  &OS_SLAVEPRIOWORD_OBJ_CORE0[0U],                     /* Priority slave word */  \
  0x80000U,                                            /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 1 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_PRIORITYSLOT_OBJ_CORE0[1U],                      \
  &OS_SLAVEPRIOWORD_OBJ_CORE0[0U],                     /* Priority slave word */  \
  0x100000U,                                           /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 2 */  \
  &OS_priorityQueueDynamic_core0[0U],                  /* Prio queue dynamic data */  \
  &OS_PRIORITYSLOT_OBJ_CORE0[2U],                      \
  &OS_SLAVEPRIOWORD_OBJ_CORE0[0U],                     /* Priority slave word */  \
  0x200000U,                                           /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  2U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 3 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_PRIORITYSLOT_OBJ_CORE0[4U],                      \
  &OS_SLAVEPRIOWORD_OBJ_CORE0[0U],                     /* Priority slave word */  \
  0x400000U,                                           /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 4 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_PRIORITYSLOT_OBJ_CORE0[5U],                      \
  &OS_SLAVEPRIOWORD_OBJ_CORE0[0U],                     /* Priority slave word */  \
  0x800000U,                                           /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 5 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_PRIORITYSLOT_OBJ_CORE0[6U],                      \
  &OS_SLAVEPRIOWORD_OBJ_CORE0[0U],                     /* Priority slave word */  \
  0x1000000U,                                          /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 6 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_PRIORITYSLOT_OBJ_CORE0[7U],                      \
  &OS_SLAVEPRIOWORD_OBJ_CORE0[0U],                     /* Priority slave word */  \
  0x2000000U,                                          /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 7 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_PRIORITYSLOT_OBJ_CORE0[8U],                      \
  &OS_SLAVEPRIOWORD_OBJ_CORE0[0U],                     /* Priority slave word */  \
  0x4000000U,                                          /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 8 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_PRIORITYSLOT_OBJ_CORE0[9U],                      \
  &OS_SLAVEPRIOWORD_OBJ_CORE0[0U],                     /* Priority slave word */  \
  0x8000000U,                                          /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 9 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_PRIORITYSLOT_OBJ_CORE0[10U],                     \
  &OS_SLAVEPRIOWORD_OBJ_CORE0[0U],                     /* Priority slave word */  \
  0x10000000U,                                         /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 10 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_PRIORITYSLOT_OBJ_CORE0[11U],                     \
  &OS_SLAVEPRIOWORD_OBJ_CORE0[0U],                     /* Priority slave word */  \
  0x20000000U,                                         /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 11 */  \
  OS_NULL,                                             /* Prio queue dynamic data */  \
  &OS_PRIORITYSLOT_OBJ_CORE0[12U],                     \
  &OS_SLAVEPRIOWORD_OBJ_CORE0[0U],                     /* Priority slave word */  \
  0x40000000U,                                         /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  1U                                                   /* Number of priority queue entries */  \
},  \
{    /* Priority 12 */  \
  &OS_priorityQueueDynamic_core0[1U],                  /* Prio queue dynamic data */  \
  &OS_PRIORITYSLOT_OBJ_CORE0[13U],                     \
  &OS_SLAVEPRIOWORD_OBJ_CORE0[0U],                     /* Priority slave word */  \
  0x80000000U,                                         /* Priority slave bit */  \
  0x80000000U,                                         /* Priority master bit */  \
  2U                                                   /* Number of priority queue entries */  \
}

/*===================================================================
 * Tasks Common Scheduling
 *==================================================================*/

#define OS_NPRIORITIES_CORE0 13
/*===================================================================
 * Tasks Linked List Scheduling
 *==================================================================*/

#define OS_NTASKACCOUNTING 0
#define OS_NTASKACTIVATIONS 14
#define OS_NTASKACCOUNTING_CORE0 0
#define OS_NTASKACTIVATIONS_CORE0 14
#define OS_TASKACTIVATIONS_CORE0   \
  /*  0 */ &OS_taskTable[OsTask_Bsw_ReadWrite_AllProcess],      \
  /*  1 */ &OS_taskTable[OsTask_AppIdle],                       \
  /*  2 */ &OS_taskTable[OsTask_Bsw_ComServices],               \
  /*  3 */ &OS_taskTable[OsTask_Bsw_SysServices],               \
  /*  4 */ &OS_taskTable[OsTask_Bsw_MemServices],               \
  /*  5 */ &OS_taskTable[OsTask_Alv_ComHwAbs],                  \
  /*  6 */ &OS_taskTable[OsTask_Bsw_Init],                      \
  /*  7 */ &OS_taskTable[OsTask_Bsw_Events],                    \
  /*  8 */ &OS_taskTable[OsTask_Alv_eCSApp],                    \
  /*  9 */ &OS_taskTable[OsTask_Alv_Autotests],                 \
  /* 10 */ &OS_taskTable[OsTask_Alv_ComServices],               \
  /* 11 */ &OS_taskTable[OsTask_Alv_EcuHwAbs],                  \
  /* 12 */ &OS_taskTable[OsTask_Alv_ModeMngmt],                 \
  /* 13 */ &OS_taskTable[OsTask_Bsw_ComEvents]

#ifdef __cplusplus
}
#endif
#endif  /* OS_CONFIG_H */
