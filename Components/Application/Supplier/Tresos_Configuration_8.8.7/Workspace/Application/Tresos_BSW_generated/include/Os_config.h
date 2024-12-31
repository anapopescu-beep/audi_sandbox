/* This file is generated automatically. DO NOT EDIT!!
 * 
 * EB tresos AutoCore OS 6.1.144 CORTEXM/S32K14X
 * (Build 20230308)
 * 
 * (c) 1998-2023 Elektrobit Automotive GmbH
 * Am Wolfsmantel 46
 * 91058 Erlangen
 * GERMANY
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
#include <CORTEXM/Os_CORTEXM_timer_nxp_ftm.h>

#define OS_GENERATION_ID_OS_CONF_H  0x1905575eUL

#define OS_AUTOSAROS_VER            6

#define OS_AUTOSAROS_REV            1

#define OS_AUTOSAROS_CORE_BUILD     20230308

#define OS_AUTOSAROS_ARCH_BUILD     20230308

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
 * Advanced Logical Core Interface
 *==================================================================*/
/* Advanced Logical Core Interface preprocessor macros. */
#define OS_ALCI_LOG_TO_PHY_CORE0  0

#define OS_ALCI_PHY_TO_LOG_CORE0  0

/*===================================================================
 * Alarms
 *==================================================================*/
#define OS_NALARMS  0
#define OS_NALARMCALLBACKS  0

#define OS_SchM_DefaultScheduleTable  0
#define OS_Rte_DefaultScheduleTable  1
#define OS_Rte_PostRunScheduleTable  2

#define OS_ALARM  OS_ALARM_INIT(    /* OS_SchM_DefaultScheduleTable */  \
  /* Application id */                        OsApplication_0,  \
  /* Application pointer */                   &OS_appTable[OsApplication_0],  \
  /* Permissions */                           0x1u,  \
  /* Schedule table wrapper */                &OS_WrapRunSchedule,  \
  /* Not used */                              0,  \
  /* Schedule table */                        SchM_DefaultScheduleTable,  \
  /* Alarm counter */                         OsCounter_HARDWARE,  \
  /* dynamic data */                          &OS_alarmDynamic_core0[0]  \
),  \
OS_ALARM_INIT(    /* OS_Rte_DefaultScheduleTable */  \
  /* Application id */                        OsApplication_0,  \
  /* Application pointer */                   &OS_appTable[OsApplication_0],  \
  /* Permissions */                           0x1u,  \
  /* Schedule table wrapper */                &OS_WrapRunSchedule,  \
  /* Not used */                              0,  \
  /* Schedule table */                        Rte_DefaultScheduleTable,  \
  /* Alarm counter */                         OsCounter_HARDWARE,  \
  /* dynamic data */                          &OS_alarmDynamic_core0[1]  \
),  \
OS_ALARM_INIT(    /* OS_Rte_PostRunScheduleTable */  \
  /* Application id */                        OsApplication_0,  \
  /* Application pointer */                   &OS_appTable[OsApplication_0],  \
  /* Permissions */                           0x1u,  \
  /* Schedule table wrapper */                &OS_WrapRunSchedule,  \
  /* Not used */                              0,  \
  /* Schedule table */                        Rte_PostRunScheduleTable,  \
  /* Alarm counter */                         OsCounter_HARDWARE,  \
  /* dynamic data */                          &OS_alarmDynamic_core0[2]  \
)
#define OS_NALARMS_CORE0  0

/*===================================================================
 * Application modes
 *==================================================================*/
#define OS_NSTARTMODES  1
/* Autostart Tasks */
#define OS_AUTOSTARTTASKS  \
  OsTask_Bsw_Init,  \
  OS_NULLTASK

#define OS_STARTMODETASKS  \
  0

/* Autostart Alarms */


/* Autostart ScheduleTables */


/*===================================================================
 * Applications
 *==================================================================*/
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsApplication_0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsApplication_0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsApplication_0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsApplication_0);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#define OS_NAPPS        2
#define OS_NAPPSNONPRIV  0
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OS_SYSTEM_0  1
#endif

#define OS_APPCONFIG  OS_APPCONFIG_INIT(    /* OsApplication_0 */  \
  /* Build ID */                                    &OS_OsApplication_0GenBuildId,  \
  /* Startup Hook */                                OS_NULL,  \
  /* Shutdown Hook */                               OS_NULL,  \
  /* Error hook */                                  OS_NULL,  \
  /* start of data/bss */                           &OS_TOOL_MR_START(OsApplication_0),  \
  /* end of data/bss */                             &OS_TOOL_MR_END(OsApplication_0),  \
  /* start of initial data */                       &OS_TOOL_MR_LMA_START(OsApplication_0),  \
  /* end of initial data */                         &OS_TOOL_MR_LMA_END(OsApplication_0),  \
  /* Permission Bit */                              0x1,  \
  /* Accessing applications */                      0x1,  \
  /* Startup hook stack */                          0,  \
  /* Shutdown hook stack */                         0,  \
  /* Error hook stack */                            0,  \
  /* Restart Task */                                OS_NULLTASK,  \
  /* Flags */                                       (OS_APP_TRUSTED),  \
  /* Application ID */                              OsApplication_0,  \
  /* dynamic data */                                &OS_appDynamic_core0[0],  \
  /* CPU core */                                    0,  \
),  \
OS_APPCONFIG_INIT(    /* OS_SYSTEM_0 */  \
  /* Build ID */                                    &OS_OS_SYSTEM_0GenBuildId,  \
  /* Startup Hook */                                OS_NULL,  \
  /* Shutdown Hook */                               OS_NULL,  \
  /* Error hook */                                  OS_NULL,  \
  /* start of data/bss */                           OS_NULL,  \
  /* end of data/bss */                             OS_NULL,  \
  /* start of initial data */                       OS_NULL,  \
  /* end of initial data */                         OS_NULL,  \
  /* Permission Bit */                              0x3,  \
  /* Accessing applications */                      0x3,  \
  /* Startup hook stack */                          0,  \
  /* Shutdown hook stack */                         0,  \
  /* Error hook stack */                            0,  \
  /* Restart Task */                                OS_NULLTASK,  \
  /* Flags */                                       (OS_APP_TRUSTED|OS_APP_SYSTEM),  \
  /* Application ID */                              OS_SYSTEM_0,  \
  /* dynamic data */                                &OS_appDynamic_core0[1],  \
  /* CPU core */                                    0,  \
)

/* Trusted Functions */
#define OS_NFUNCTIONS  0

#define OS_SHOOKSTACKLEN  0
#define OS_EHOOKSTACKLEN  0
#define OS_NAPPS_CORE0    2

/*===================================================================
 * CPU Core configuration
 *==================================================================*/
#define OS_PROPERTIES_CORE0  (OS_U(0)|OS_COREPROP_USED_BIT)

/*===================================================================
 * Channel Initializers
 *==================================================================*/
#define OS_IOC_ENABLED  0

/*===================================================================
 * Configured Modes
 *==================================================================*/
#define OS_CONFIGMODE        (OS_ECC2|OS_SCHEDMIX|OS_EXTENDED|OS_TRACE|OS_STACKCHECK|OS_DBGPROT_FULL|OS_VOIDERROR)
#define OS_IECMODE           (OS_IEC_AUTOSAR)
#define OS_HOOKSELECTION     (OS_ACTION_PROTECTIONHOOK|OS_ACTION_ERRORHOOK|OS_ACTION_ERRORHOOK_EB)
#define OS_PERMITTEDCONTEXT  (OS_permittedContextAutosar)
#define OS_INCLUDE_RTE       0

/*===================================================================
 * Counters
 *==================================================================*/
#define OS_NSHAREDHWCOUNTERTIMESTAMP         0
#define OS_SHAREDHWCOUNTERTIMESTAMP_ALARMID  -1
#define OS_SHAREDHWCOUNTERTIMESTAMP_COREID   -1
#define OS_NCOUNTERS    1
#define OS_NSWCOUNTERS  0

#define OS_COUNTER  OS_COUNTER_INIT(    /* OsCounter_HARDWARE */  \
  /* Application id */       OsApplication_0,  \
  /* Application pointer */  &OS_appTable[OsApplication_0],  \
  /* Update function */      &OS_HwCounterUpdate,  \
  /* Permissions */          0x1u,  \
  /* Hardware timer */       &OS_hwTimer[0],  \
  /* Max allowed value */    (os_tick_t)65535u,  \
  /* Ticks per base */       (os_tick_t)1u,  \
  /* Min cycle */            (os_tick_t)1u,  \
  /* dynamic data */         &OS_counterDynamic_core0[0]  \
)

#define OS_NINTERNALTICKERS  0
/* Number of counters available on cores */
#define OS_NCOUNTERS_CORE0  1

/*===================================================================
 * Events
 *==================================================================*/
#define OS_NEVENTS  2

/*===================================================================
 * Execution timer
 *==================================================================*/
#define OS_EXECUTIONTIMER_INIT     /* Execution timer init */  \
  OS_NULL

/*===================================================================
 * Time-stamp timer
 *==================================================================*/

/*===================================================================
 * Hardware Timers
 *==================================================================*/
#define OS_NHWTIMERS        1
#define OS_NHWTIMERS_CORE0  1

#define OS_HWTIMER {    /* FTM0_0 */  \
  /* Driver table */                     &OS_timerFtmDriver,  \
  /* HwTimer Last Value */               &OS_hwtLastValue_core0[0],  \
  /* Max delta */                        49152u,  \
  /* Default delta if max exceeded */    32768u,  \
  /* Wrap mask */                        65535u,  \
  /* Driver number */                    0u,  \
  /* Driver channel */                   0u,  \
  /* core */                             0u,  \
}

/*===================================================================
 * Hook Functions
 *==================================================================*/
#define OS_ERRORHOOK       &ErrorHook
#define OS_SHUTDOWNHOOK    &ShutdownHook
#define OS_PROTECTIONHOOK  &ProtectionHook

/*===================================================================
 * Interrupts
 *==================================================================*/
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN0_ORED_IRQHandler);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN0_ORED_IRQHandler);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN0_ORED_IRQHandler);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN0_ORED_IRQHandler);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN0_Error_IRQHandler);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN0_Error_IRQHandler);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN0_Error_IRQHandler);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN0_Error_IRQHandler);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN0_ORED_0_15_MB_IRQHandler);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN0_ORED_0_15_MB_IRQHandler);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN0_ORED_0_15_MB_IRQHandler);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN0_ORED_0_15_MB_IRQHandler);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(CAN0_ORED_16_31_MB_IRQHandler);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(CAN0_ORED_16_31_MB_IRQHandler);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(CAN0_ORED_16_31_MB_IRQHandler);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(CAN0_ORED_16_31_MB_IRQHandler);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(LPIT_0_CH_1_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(LPIT_0_CH_1_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(LPIT_0_CH_1_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(LPIT_0_CH_1_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(LPTMR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(LPTMR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(LPTMR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(LPTMR_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(PORTD_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(PORTD_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(PORTD_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(PORTD_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(PORTE_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(PORTE_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(PORTE_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(PORTE_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(LPIT_0_CH_2_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(LPIT_0_CH_2_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(LPIT_0_CH_2_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(LPIT_0_CH_2_ISR);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */

#define OS_NINTERRUPTS         10
#define OS_NCAT1_INTERRUPTS    2
#define OS_NCAT2_INTERRUPTS    8
#define OS_NCATK_INTERRUPTS    0
#define OS_NCAT2K_INTERRUPTS   0
#define OS_NISRSEXECTIMELIMIT  0
#define OS_NISRSINTLOCKLIMIT   0
#define OS_NISRSRESLOCKLIMIT   0
#define OS_NISRACCOUNTING      0
#define OS_CAT1LOCK            2
#define OS_CAT2LOCK            4
#define OS_KERNLOCK            4
#define OS_XCOREUNLOCK         OS_KERNLOCK
#define OS_ENABLEALLLOCK       15

/* Internal Interrupt Ids */
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define Os_Counter_FTM0_0  9
#endif

/* Isr Config Struct Init Macros. */
#define OS_ISRCONFIG  OS_ISRCONFIG_INIT(    /* CAN0_ORED_IRQHandler */  \
  /* Application */                       &OS_appTable[OsApplication_0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(CAN0_ORED_IRQHandler),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(CAN0_ORED_IRQHandler),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(CAN0_ORED_IRQHandler),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(CAN0_ORED_IRQHandler),  \
  /* Interrupt entry */                   &OS_ISR_CAN0_ORED_IRQHandler,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        256u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CAN0_ORED_IRQHandler,  \
  /* dynamic data */                      &OS_isrDynamic_core0[0],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* ISR source */                                                 78,  \
      /* ISR priority */                                               7,  \
      /* Target core */                                                OS_CORTEXM_INT_TARGET_DEFAULT  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN0_Error_IRQHandler */  \
  /* Application */                       &OS_appTable[OsApplication_0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(CAN0_Error_IRQHandler),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(CAN0_Error_IRQHandler),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(CAN0_Error_IRQHandler),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(CAN0_Error_IRQHandler),  \
  /* Interrupt entry */                   &OS_ISR_CAN0_Error_IRQHandler,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        256u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CAN0_Error_IRQHandler,  \
  /* dynamic data */                      &OS_isrDynamic_core0[1],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* ISR source */                                                 79,  \
      /* ISR priority */                                               7,  \
      /* Target core */                                                OS_CORTEXM_INT_TARGET_DEFAULT  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN0_ORED_0_15_MB_IRQHandler */  \
  /* Application */                       &OS_appTable[OsApplication_0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(CAN0_ORED_0_15_MB_IRQHandler),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(CAN0_ORED_0_15_MB_IRQHandler),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(CAN0_ORED_0_15_MB_IRQHandler),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(CAN0_ORED_0_15_MB_IRQHandler),  \
  /* Interrupt entry */                   &OS_ISR_CAN0_ORED_0_15_MB_IRQHandler,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        256u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CAN0_ORED_0_15_MB_IRQHandler,  \
  /* dynamic data */                      &OS_isrDynamic_core0[2],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* ISR source */                                                 81,  \
      /* ISR priority */                                               7,  \
      /* Target core */                                                OS_CORTEXM_INT_TARGET_DEFAULT  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* CAN0_ORED_16_31_MB_IRQHandler */  \
  /* Application */                       &OS_appTable[OsApplication_0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(CAN0_ORED_16_31_MB_IRQHandler),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(CAN0_ORED_16_31_MB_IRQHandler),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(CAN0_ORED_16_31_MB_IRQHandler),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(CAN0_ORED_16_31_MB_IRQHandler),  \
  /* Interrupt entry */                   &OS_ISR_CAN0_ORED_16_31_MB_IRQHandler,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        256u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            CAN0_ORED_16_31_MB_IRQHandler,  \
  /* dynamic data */                      &OS_isrDynamic_core0[3],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* ISR source */                                                 82,  \
      /* ISR priority */                                               7,  \
      /* Target core */                                                OS_CORTEXM_INT_TARGET_DEFAULT  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* LPIT_0_CH_1_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(LPIT_0_CH_1_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(LPIT_0_CH_1_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(LPIT_0_CH_1_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(LPIT_0_CH_1_ISR),  \
  /* Interrupt entry */                   &OS_ISR_LPIT_0_CH_1_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        128u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            LPIT_0_CH_1_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[4],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* ISR source */                                                 49,  \
      /* ISR priority */                                               6,  \
      /* Target core */                                                OS_CORTEXM_INT_TARGET_DEFAULT  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* LPTMR_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(LPTMR_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(LPTMR_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(LPTMR_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(LPTMR_ISR),  \
  /* Interrupt entry */                   &OS_ISR_LPTMR_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        128u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            LPTMR_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[5],  \
  /* Flags */                             (OS_ISRF_CAT1|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* ISR source */                                                 58,  \
      /* ISR priority */                                               3,  \
      /* Target core */                                                OS_CORTEXM_INT_TARGET_DEFAULT  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* PORTD_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(PORTD_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(PORTD_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(PORTD_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(PORTD_ISR),  \
  /* Interrupt entry */                   &OS_ISR_PORTD_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        128u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            PORTD_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[6],  \
  /* Flags */                             (OS_ISRF_CAT1|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* ISR source */                                                 62,  \
      /* ISR priority */                                               2,  \
      /* Target core */                                                OS_CORTEXM_INT_TARGET_DEFAULT  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* PORTE_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(PORTE_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(PORTE_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(PORTE_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(PORTE_ISR),  \
  /* Interrupt entry */                   &OS_ISR_PORTE_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        128u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            PORTE_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[7],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* ISR source */                                                 63,  \
      /* ISR priority */                                               5,  \
      /* Target core */                                                OS_CORTEXM_INT_TARGET_DEFAULT  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* LPIT_0_CH_2_ISR */  \
  /* Application */                       &OS_appTable[OsApplication_0],  \
  /* Permissions */                       0x1u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 &OS_TOOL_MR_START(LPIT_0_CH_2_ISR),  \
  /* end of data/bss */                   &OS_TOOL_MR_END(LPIT_0_CH_2_ISR),  \
  /* start of initial data */             &OS_TOOL_MR_LMA_START(LPIT_0_CH_2_ISR),  \
  /* end of initial data */               &OS_TOOL_MR_LMA_END(LPIT_0_CH_2_ISR),  \
  /* Interrupt entry */                   &OS_ISR_LPIT_0_CH_2_ISR,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        128u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            LPIT_0_CH_2_ISR,  \
  /* dynamic data */                      &OS_isrDynamic_core0[8],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* ISR source */                                                 50,  \
      /* ISR priority */                                               5,  \
      /* Target core */                                                OS_CORTEXM_INT_TARGET_DEFAULT  \
    )  \
),  \
OS_ISRCONFIG_INIT(    /* Os_Counter_FTM0_0 */  \
  /* Application */                       &OS_appTable[OS_SYSTEM_0],  \
  /* Permissions */                       0x3u,  \
  /* Accounting structure */              OS_NULL,  \
  /* start of data/bss */                 OS_NULL,  \
  /* end of data/bss */                   OS_NULL,  \
  /* start of initial data */             OS_NULL,  \
  /* end of initial data */               OS_NULL,  \
  /* Interrupt entry */                   &OS_CounterIsr_OsCounter_HARDWARE,  \
  /* Execution budget */                  0u,  \
  /* Os interrupt lock budget */          0u,  \
  /* All interrupt lock budget */         0u,  \
  /* Resource lock budget */              OS_NULL,  \
  /* Stack size */                        512u,  \
  /* Rate monitor */                      OS_NULLRATEMONITOR,  \
  /* Isr id */                            Os_Counter_FTM0_0,  \
  /* dynamic data */                      &OS_isrDynamic_core0[9],  \
  /* Flags */                             (OS_ISRF_CAT2|OS_ISRF_ENABLE),  \
    OS_ARCHISR_INIT(  \
      /* ISR source */                                                 99,  \
      /* ISR priority */                                               4,  \
      /* Target core */                                                OS_CORTEXM_INT_TARGET_DEFAULT  \
    )  \
)

/* Stack Macros */
#define OS_ISTACKBASE_0          OS_kernStack0
#define OS_ISTACKLEN_0           OS_U( 5440 )
#define OS_NINTERRUPTS_CORE0     10
#define OS_NISRACCOUNTING_CORE0  0

/*===================================================================
 * Kernel data
 *==================================================================*/
#define OS_KERNELDATA_INIT_CORE0  /* kernel data core 0 */  \
  /* taskQueueHead */            OS_NULL,  \
  /* taskCurrent */              OS_NULL,  \
  /* iSpInitial */               OS_GetInitialStackPointer( OS_ISTACKBASE_0, OS_ISTACKLEN_0 ),  \
  /* hookApp */                  OS_NULL,  \
  /* inKernel */                 0,  \
  /* idleMode */                 IDLE_NO_HALT,  \
  /* inFunction */               0,  \
  /* tfCalledFrom */             0,  \
  /* iStackBase */               OS_ISTACKBASE_0,  \
  /* iStackLen */                OS_ISTACKLEN_0,  \
  /* isrCurrent */               OS_NULLISR,  \
  /* isrLastLock */              OS_NULLOBJECT,  \
  /* oldSuspendOs */             0,  \
  /* oldSuspendAll */            0,  \
  /* nestSuspendOs */            0,  \
  /* nestSuspendAll */           0,  \
  /* errorStatus */              OS_ERRORSTATUS_INIT,  \
  /* sHookContext */             OS_HOOKCONTEXT_INIT,  \
  /* eHookContext */             OS_HOOKCONTEXT_INIT,  \
  /* errorHookNesting */         0,  \
  /* accounting */               OS_ACCOUNTINGS_INIT,  \
  /* appsStarted */              0,  \
  /* panicCode */                OS_PANIC_NONE

/*===================================================================
 * Optimization
 *==================================================================*/
#define OS_CAT1_DIRECTCALL  0

/*===================================================================
 * Rate Monitor
 *==================================================================*/
#define OS_NRATEMONS  0
#define OS_NRATEMONS_CORE0  0

#define OS_NRATETIMERS    OS_NRATETIMERS_CORE0
#define OS_RATEMONCONFIG  OS_RATEMONCONFIG_CORE0

/*===================================================================
 * Resource Lock Timing
 *==================================================================*/
#define OS_NRESLOCKTIMES  0

/*===================================================================
 * Resources
 *==================================================================*/
#define OS_NRESOURCES  1


#define OS_RESOURCES  OS_RESOURCES_INIT(    /* RES_SCHEDULER_0 */  \
  /* Application */          &OS_appTable[OS_SYSTEM_0],  \
  /* Permissions */          0x3u,  \
  /* Priority */             12,  \
  /* dynamic data */         &OS_resourceDynamic_core0[0]  \
)
/* Number of Non-Internal Used resources on cores */
#define OS_NRESOURCES_CORE0  1

/*===================================================================
 * Schedule Tables
 *==================================================================*/
#define OS_NSCHEDULES      3
#define OS_NSCHEDULESSYNC  0

#define OS_STCONFIG  OS_STCONFIG_INIT(    /* SchM_DefaultScheduleTable */  \
  /* Application id */                OsApplication_0,  \
  /* Application pointer */           &OS_appTable[OsApplication_0], \
  /* Permissions */                   0x1u,  \
  /* Schedule table entries */        &OS_stEntries[0],  \
  /* Duration */                      50000,  \
  /* Cut off */                       0,  \
  /* Precision */                     0,  \
  /* Alarm ID */                      0,  \
  /* Number of expiry points */       4,  \
  /* Flags */                         (OS_ST_REPEATING),  \
  /* dynamic data */                  &OS_scheduleDynamic_core0[0]  \
),  \
OS_STCONFIG_INIT(    /* Rte_DefaultScheduleTable */  \
  /* Application id */                OsApplication_0,  \
  /* Application pointer */           &OS_appTable[OsApplication_0], \
  /* Permissions */                   0x1u,  \
  /* Schedule table entries */        &OS_stEntries[4],  \
  /* Duration */                      50000,  \
  /* Cut off */                       0,  \
  /* Precision */                     0,  \
  /* Alarm ID */                      1,  \
  /* Number of expiry points */       36,  \
  /* Flags */                         (OS_ST_REPEATING),  \
  /* dynamic data */                  &OS_scheduleDynamic_core0[1]  \
),  \
OS_STCONFIG_INIT(    /* Rte_PostRunScheduleTable */  \
  /* Application id */                OsApplication_0,  \
  /* Application pointer */           &OS_appTable[OsApplication_0], \
  /* Permissions */                   0x1u,  \
  /* Schedule table entries */        &OS_stEntries[40],  \
  /* Duration */                      50000,  \
  /* Cut off */                       0,  \
  /* Precision */                     0,  \
  /* Alarm ID */                      2,  \
  /* Number of expiry points */       5,  \
  /* Flags */                         (OS_ST_REPEATING),  \
  /* dynamic data */                  &OS_scheduleDynamic_core0[2]  \
)

/* ScheduleTables expiry points */
#define OS_NSTENTRIES  45
#define OS_STENTRIES  \
  /* OsScheduleTableExpiryPoint_1000 */  \
  {  \
    /* Offset */                      5000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Bsw_SysServices  \
  },  \
  /* OsScheduleTableExpiryPoint_3000 */  \
  {  \
    /* Offset */                      15000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Bsw_ComServices  \
  },  \
  /* OsScheduleTableExpiryPoint_8000 */  \
  {  \
    /* Offset */                      40000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Bsw_ComServices  \
  },  \
  /* OsScheduleTableExpiryPoint_9000 */  \
  {  \
    /* Offset */                      45000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_ComHwAbs  \
  },  \
  /* OsScheduleTableExpiryPoint_0000 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_EcuHwAbs  \
  },  \
  /* OsScheduleTableExpiryPoint_0000 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_Autotests  \
  },  \
  /* OsScheduleTableExpiryPoint_0000 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_eCSApp  \
  },  \
  /* OsScheduleTableExpiryPoint_1000 */  \
  {  \
    /* Offset */                      5000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_Autotests  \
  },  \
  /* OsScheduleTableExpiryPoint_1000 */  \
  {  \
    /* Offset */                      5000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_eCSApp  \
  },  \
  /* OsScheduleTableExpiryPoint_1000 */  \
  {  \
    /* Offset */                      5000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_ComServices  \
  },  \
  /* OsScheduleTableExpiryPoint_1000 */  \
  {  \
    /* Offset */                      5000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Bsw_SysServices  \
  },  \
  /* OsScheduleTableExpiryPoint_2000 */  \
  {  \
    /* Offset */                      10000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_EcuHwAbs  \
  },  \
  /* OsScheduleTableExpiryPoint_2000 */  \
  {  \
    /* Offset */                      10000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_Autotests  \
  },  \
  /* OsScheduleTableExpiryPoint_2000 */  \
  {  \
    /* Offset */                      10000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_eCSApp  \
  },  \
  /* OsScheduleTableExpiryPoint_3000 */  \
  {  \
    /* Offset */                      15000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_Autotests  \
  },  \
  /* OsScheduleTableExpiryPoint_3000 */  \
  {  \
    /* Offset */                      15000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_eCSApp  \
  },  \
  /* OsScheduleTableExpiryPoint_3000 */  \
  {  \
    /* Offset */                      15000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_ComServices  \
  },  \
  /* OsScheduleTableExpiryPoint_3000 */  \
  {  \
    /* Offset */                      15000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Bsw_ComServices  \
  },  \
  /* OsScheduleTableExpiryPoint_4000 */  \
  {  \
    /* Offset */                      20000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_EcuHwAbs  \
  },  \
  /* OsScheduleTableExpiryPoint_4000 */  \
  {  \
    /* Offset */                      20000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_Autotests  \
  },  \
  /* OsScheduleTableExpiryPoint_4000 */  \
  {  \
    /* Offset */                      20000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_eCSApp  \
  },  \
  /* OsScheduleTableExpiryPoint_4000 */  \
  {  \
    /* Offset */                      20000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_ModeMngmt  \
  },  \
  /* OsScheduleTableExpiryPoint_5000 */  \
  {  \
    /* Offset */                      25000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_Autotests  \
  },  \
  /* OsScheduleTableExpiryPoint_5000 */  \
  {  \
    /* Offset */                      25000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_eCSApp  \
  },  \
  /* OsScheduleTableExpiryPoint_5000 */  \
  {  \
    /* Offset */                      25000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_ComServices  \
  },  \
  /* OsScheduleTableExpiryPoint_6000 */  \
  {  \
    /* Offset */                      30000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_EcuHwAbs  \
  },  \
  /* OsScheduleTableExpiryPoint_6000 */  \
  {  \
    /* Offset */                      30000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_eCSApp  \
  },  \
  /* OsScheduleTableExpiryPoint_6000 */  \
  {  \
    /* Offset */                      30000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_Autotests  \
  },  \
  /* OsScheduleTableExpiryPoint_6000 */  \
  {  \
    /* Offset */                      30000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Bsw_MemServices  \
  },  \
  /* OsScheduleTableExpiryPoint_7000 */  \
  {  \
    /* Offset */                      35000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_Autotests  \
  },  \
  /* OsScheduleTableExpiryPoint_7000 */  \
  {  \
    /* Offset */                      35000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_eCSApp  \
  },  \
  /* OsScheduleTableExpiryPoint_7000 */  \
  {  \
    /* Offset */                      35000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_ComServices  \
  },  \
  /* OsScheduleTableExpiryPoint_8000 */  \
  {  \
    /* Offset */                      40000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_EcuHwAbs  \
  },  \
  /* OsScheduleTableExpiryPoint_8000 */  \
  {  \
    /* Offset */                      40000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_Autotests  \
  },  \
  /* OsScheduleTableExpiryPoint_8000 */  \
  {  \
    /* Offset */                      40000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_eCSApp  \
  },  \
  /* OsScheduleTableExpiryPoint_8000 */  \
  {  \
    /* Offset */                      40000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Bsw_ComServices  \
  },  \
  /* OsScheduleTableExpiryPoint_9000 */  \
  {  \
    /* Offset */                      45000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_Autotests  \
  },  \
  /* OsScheduleTableExpiryPoint_9000 */  \
  {  \
    /* Offset */                      45000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_eCSApp  \
  },  \
  /* OsScheduleTableExpiryPoint_9000 */  \
  {  \
    /* Offset */                      45000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_ComServices  \
  },  \
  /* OsScheduleTableExpiryPoint_9000 */  \
  {  \
    /* Offset */                      45000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_ComHwAbs  \
  },  \
  /* OsScheduleTableExpiryPoint_0000 */  \
  {  \
    /* Offset */                      0,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Bsw_SysServices  \
  },  \
  /* OsScheduleTableExpiryPoint_2000 */  \
  {  \
    /* Offset */                      10000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Bsw_ComServices  \
  },  \
  /* OsScheduleTableExpiryPoint_7000 */  \
  {  \
    /* Offset */                      35000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Bsw_ComServices  \
  },  \
  /* OsScheduleTableExpiryPoint_9000 */  \
  {  \
    /* Offset */                      45000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Alv_ComHwAbs  \
  },  \
  /* OsScheduleTableExpiryPoint_9000 */  \
  {  \
    /* Offset */                      45000,  \
    /* Max advance */                 0,  \
    /* Max retard */                  0,  \
    /* Event */                       0,  \
    /* Task */                        OsTask_Bsw_ReadWrite_AllProcess  \
  }

#define OS_NSCHEDULES_CORE0  3

/*===================================================================
 * Spinlocks
 *==================================================================*/
#define OS_NAUTOSARSPINLOCKS  0

/*===================================================================
 * Stacks
 *==================================================================*/
#define OS_STACK_REGION_ALIGNMENT  32
/* Task Stacks */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot0, .bss.core0.os_taskstack0_slot0, 168, 32 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot1, .bss.core0.os_taskstack0_slot1, 168, 32 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot2, .bss.core0.os_taskstack0_slot2, 232, 32 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot3, .bss.core0.os_taskstack0_slot3, 168, 32 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot4, .bss.core0.os_taskstack0_slot4, 232, 32 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot5, .bss.core0.os_taskstack0_slot5, 168, 32 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot6, .bss.core0.os_taskstack0_slot6, 72, 32 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot7, .bss.core0.os_taskstack0_slot7, 168, 32 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot8, .bss.core0.os_taskstack0_slot8, 168, 32 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot9, .bss.core0.os_taskstack0_slot9, 296, 32 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot10, .bss.core0.os_taskstack0_slot10, 296, 32 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot11, .bss.core0.os_taskstack0_slot11, 104, 32 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot12, .bss.core0.os_taskstack0_slot12, 104, 32 );
#endif
#endif  /* OS_ASM */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_taskStack0_slot13, .bss.core0.os_taskstack0_slot13, 168, 32 );
#endif
#endif  /* OS_ASM */
/* Interrupt Stacks */
#ifndef OS_ASM
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern OS_GEN_STACK_DECL( OS_kernStack0, .bss.core0.os_kernstack0, 1360, 32 );
#endif
#endif  /* OS_ASM */

/*===================================================================
 * Tasks
 *==================================================================*/
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_Bsw_ReadWrite_AllProcess);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_Bsw_ReadWrite_AllProcess);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Bsw_ReadWrite_AllProcess);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Bsw_ReadWrite_AllProcess);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Bsw_ReadWrite_AllProcess);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_AppIdle);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_AppIdle);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_AppIdle);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_AppIdle);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_AppIdle);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_Bsw_ComServices);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_Bsw_ComServices);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Bsw_ComServices);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Bsw_ComServices);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Bsw_ComServices);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_Bsw_SysServices);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_Bsw_SysServices);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Bsw_SysServices);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Bsw_SysServices);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Bsw_SysServices);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_Bsw_MemServices);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_Bsw_MemServices);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Bsw_MemServices);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Bsw_MemServices);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Bsw_MemServices);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_Alv_ComHwAbs);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_Alv_ComHwAbs);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Alv_ComHwAbs);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Alv_ComHwAbs);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Alv_ComHwAbs);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_Bsw_Init);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_Bsw_Init);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Bsw_Init);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Bsw_Init);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Bsw_Init);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_Bsw_Events);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_Bsw_Events);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Bsw_Events);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Bsw_Events);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Bsw_Events);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_Alv_eCSApp);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_Alv_eCSApp);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Alv_eCSApp);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Alv_eCSApp);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Alv_eCSApp);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_Alv_Autotests);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_Alv_Autotests);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Alv_Autotests);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Alv_Autotests);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Alv_Autotests);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_Alv_ComServices);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_Alv_ComServices);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Alv_ComServices);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Alv_ComServices);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Alv_ComServices);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_Alv_EcuHwAbs);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_Alv_EcuHwAbs);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Alv_EcuHwAbs);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Alv_EcuHwAbs);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Alv_EcuHwAbs);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_Alv_ModeMngmt);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_Alv_ModeMngmt);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Alv_ModeMngmt);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Alv_ModeMngmt);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Alv_ModeMngmt);
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_START(OsTask_Bsw_ComEvents);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_END(OsTask_Bsw_ComEvents);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_START(OsTask_Bsw_ComEvents);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
#ifndef EB_STATIC_CHECK
#if OS_KERNEL_TYPE != OS_MICROKERNEL
extern os_uint8_t OS_TOOL_MR_LMA_END(OsTask_Bsw_ComEvents);
#endif  /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#endif  /* EB_STATIC_CHECK */
#endif  /* OS_ASM */
#ifndef OS_ASM
DeclareTask(OsTask_Bsw_ComEvents);
#endif  /* OS_ASM */

#define OS_NTASKS               14
#define OS_NETASKS              2
#define OS_NTASKSEXECTIMELIMIT  0
#define OS_NTASKSINTLOCKLIMIT   0
#define OS_NTASKSRESLOCKLIMIT   0
#define OS_TASKCONFIG  OS_TASKCONFIG_INIT(    /* OsTask_Bsw_ReadWrite_AllProcess */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[0],  \
  /* Run priority */                   1u,  \
  /* Queuing priority */               1u,  \
  /* Activation index */               1,  \
  /* Task entry */                     &OS_TASK_OsTask_Bsw_ReadWrite_AllProcess,  \
  /* Stack base */                     &OS_taskStack0_slot0[0],  \
  /* Stack size */                     672u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_EXTENDED),  \
  /* Task ID */                        OsTask_Bsw_ReadWrite_AllProcess,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_Bsw_ReadWrite_AllProcess),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_Bsw_ReadWrite_AllProcess),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_Bsw_ReadWrite_AllProcess),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_Bsw_ReadWrite_AllProcess),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_0],  \
  /* Permissions */                    0x1u,  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_AppIdle */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[1],  \
  /* Run priority */                   0u,  \
  /* Queuing priority */               0u,  \
  /* Activation index */               2,  \
  /* Task entry */                     &OS_TASK_OsTask_AppIdle,  \
  /* Stack base */                     &OS_taskStack0_slot1[0],  \
  /* Stack size */                     672u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_EXTENDED),  \
  /* Task ID */                        OsTask_AppIdle,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_AppIdle),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_AppIdle),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_AppIdle),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_AppIdle),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_0],  \
  /* Permissions */                    0x1u,  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Bsw_ComServices */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[2],  \
  /* Run priority */                   8u,  \
  /* Queuing priority */               8u,  \
  /* Activation index */               3,  \
  /* Task entry */                     &OS_TASK_OsTask_Bsw_ComServices,  \
  /* Stack base */                     &OS_taskStack0_slot2[0],  \
  /* Stack size */                     928u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        OsTask_Bsw_ComServices,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_Bsw_ComServices),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_Bsw_ComServices),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_Bsw_ComServices),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_Bsw_ComServices),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_0],  \
  /* Permissions */                    0x1u,  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Bsw_SysServices */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[3],  \
  /* Run priority */                   6u,  \
  /* Queuing priority */               6u,  \
  /* Activation index */               4,  \
  /* Task entry */                     &OS_TASK_OsTask_Bsw_SysServices,  \
  /* Stack base */                     &OS_taskStack0_slot3[0],  \
  /* Stack size */                     672u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        OsTask_Bsw_SysServices,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_Bsw_SysServices),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_Bsw_SysServices),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_Bsw_SysServices),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_Bsw_SysServices),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_0],  \
  /* Permissions */                    0x1u,  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Bsw_MemServices */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[4],  \
  /* Run priority */                   12u,  \
  /* Queuing priority */               4u,  \
  /* Activation index */               5,  \
  /* Task entry */                     &OS_TASK_OsTask_Bsw_MemServices,  \
  /* Stack base */                     &OS_taskStack0_slot4[0],  \
  /* Stack size */                     928u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          (OS_TF_NONPREEMPT),  \
  /* Task ID */                        OsTask_Bsw_MemServices,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_Bsw_MemServices),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_Bsw_MemServices),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_Bsw_MemServices),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_Bsw_MemServices),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_0],  \
  /* Permissions */                    0x1u,  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Alv_ComHwAbs */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[5],  \
  /* Run priority */                   7u,  \
  /* Queuing priority */               7u,  \
  /* Activation index */               6,  \
  /* Task entry */                     &OS_TASK_OsTask_Alv_ComHwAbs,  \
  /* Stack base */                     &OS_taskStack0_slot5[0],  \
  /* Stack size */                     672u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        OsTask_Alv_ComHwAbs,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_Alv_ComHwAbs),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_Alv_ComHwAbs),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_Alv_ComHwAbs),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_Alv_ComHwAbs),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_0],  \
  /* Permissions */                    0x1u,  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Bsw_Init */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[6],  \
  /* Run priority */                   3u,  \
  /* Queuing priority */               3u,  \
  /* Activation index */               7,  \
  /* Task entry */                     &OS_TASK_OsTask_Bsw_Init,  \
  /* Stack base */                     &OS_taskStack0_slot6[0],  \
  /* Stack size */                     288u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        OsTask_Bsw_Init,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_Bsw_Init),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_Bsw_Init),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_Bsw_Init),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_Bsw_Init),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_0],  \
  /* Permissions */                    0x1u,  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Bsw_Events */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[7],  \
  /* Run priority */                   2u,  \
  /* Queuing priority */               2u,  \
  /* Activation index */               8,  \
  /* Task entry */                     &OS_TASK_OsTask_Bsw_Events,  \
  /* Stack base */                     &OS_taskStack0_slot7[0],  \
  /* Stack size */                     672u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        OsTask_Bsw_Events,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_Bsw_Events),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_Bsw_Events),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_Bsw_Events),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_Bsw_Events),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_0],  \
  /* Permissions */                    0x1u,  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Alv_eCSApp */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[8],  \
  /* Run priority */                   11u,  \
  /* Queuing priority */               11u,  \
  /* Activation index */               9,  \
  /* Task entry */                     &OS_TASK_OsTask_Alv_eCSApp,  \
  /* Stack base */                     &OS_taskStack0_slot8[0],  \
  /* Stack size */                     672u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        OsTask_Alv_eCSApp,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_Alv_eCSApp),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_Alv_eCSApp),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_Alv_eCSApp),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_Alv_eCSApp),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_0],  \
  /* Permissions */                    0x1u,  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Alv_Autotests */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[9],  \
  /* Run priority */                   10u,  \
  /* Queuing priority */               10u,  \
  /* Activation index */               10,  \
  /* Task entry */                     &OS_TASK_OsTask_Alv_Autotests,  \
  /* Stack base */                     &OS_taskStack0_slot9[0],  \
  /* Stack size */                     1184u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        OsTask_Alv_Autotests,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_Alv_Autotests),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_Alv_Autotests),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_Alv_Autotests),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_Alv_Autotests),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_0],  \
  /* Permissions */                    0x1u,  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Alv_ComServices */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[10],  \
  /* Run priority */                   9u,  \
  /* Queuing priority */               9u,  \
  /* Activation index */               11,  \
  /* Task entry */                     &OS_TASK_OsTask_Alv_ComServices,  \
  /* Stack base */                     &OS_taskStack0_slot10[0],  \
  /* Stack size */                     1184u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        OsTask_Alv_ComServices,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_Alv_ComServices),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_Alv_ComServices),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_Alv_ComServices),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_Alv_ComServices),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_0],  \
  /* Permissions */                    0x1u,  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Alv_EcuHwAbs */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[11],  \
  /* Run priority */                   12u,  \
  /* Queuing priority */               12u,  \
  /* Activation index */               12,  \
  /* Task entry */                     &OS_TASK_OsTask_Alv_EcuHwAbs,  \
  /* Stack base */                     &OS_taskStack0_slot11[0],  \
  /* Stack size */                     416u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        OsTask_Alv_EcuHwAbs,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_Alv_EcuHwAbs),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_Alv_EcuHwAbs),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_Alv_EcuHwAbs),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_Alv_EcuHwAbs),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_0],  \
  /* Permissions */                    0x1u,  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Alv_ModeMngmt */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[12],  \
  /* Run priority */                   5u,  \
  /* Queuing priority */               5u,  \
  /* Activation index */               13,  \
  /* Task entry */                     &OS_TASK_OsTask_Alv_ModeMngmt,  \
  /* Stack base */                     &OS_taskStack0_slot12[0],  \
  /* Stack size */                     416u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        OsTask_Alv_ModeMngmt,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_Alv_ModeMngmt),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_Alv_ModeMngmt),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_Alv_ModeMngmt),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_Alv_ModeMngmt),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_0],  \
  /* Permissions */                    0x1u,  \
),  \
OS_TASKCONFIG_INIT(    /* OsTask_Bsw_ComEvents */  \
  /* Dynamic task structure */         &OS_taskDynamic_core0[13],  \
  /* Run priority */                   2u,  \
  /* Queuing priority */               2u,  \
  /* Activation index */               14,  \
  /* Task entry */                     &OS_TASK_OsTask_Bsw_ComEvents,  \
  /* Stack base */                     &OS_taskStack0_slot13[0],  \
  /* Stack size */                     672u,  \
  /* Max. activations */               0u,  \
  /* Flags */                          0,  \
  /* Task ID */                        OsTask_Bsw_ComEvents,  \
  /* Accounting structure */           OS_NULL,  \
  /* start of data/bss */              &OS_TOOL_MR_START(OsTask_Bsw_ComEvents),  \
  /* end of data/bss */                &OS_TOOL_MR_END(OsTask_Bsw_ComEvents),  \
  /* start of initial data */          &OS_TOOL_MR_LMA_START(OsTask_Bsw_ComEvents),  \
  /* end of initial data */            &OS_TOOL_MR_LMA_END(OsTask_Bsw_ComEvents),  \
  /* Execution budget */               0u,  \
  /* Os interrupt lock budget */       0u,  \
  /* All interrupt lock budget */      0u,  \
  /* Resource lock budget */           OS_NULL,  \
  /* Rate monitor */                   OS_NULLRATEMONITOR,  \
  /* Application */                    &OS_appTable[OsApplication_0],  \
  /* Permissions */                    0x1u,  \
)
#define OS_NTASKS_CORE0  14

/*===================================================================
 * Tasks Common Scheduling
 *==================================================================*/
#define OS_NPRIORITIES_CORE0  13

/*===================================================================
 * Tasks Linked List Scheduling
 *==================================================================*/
#define OS_NTASKACCOUNTING  0
#define OS_NTASKACTIVATIONS  14
#define OS_NTASKACCOUNTING_CORE0   0
#define OS_NTASKACTIVATIONS_CORE0  14
#define OS_TASKACTIVATIONS_CORE0   \
  /* 0 */ &OS_taskTable[OsTask_Bsw_ReadWrite_AllProcess],    \
  /* 1 */ &OS_taskTable[OsTask_AppIdle],    \
  /* 2 */ &OS_taskTable[OsTask_Bsw_ComServices],    \
  /* 3 */ &OS_taskTable[OsTask_Bsw_SysServices],    \
  /* 4 */ &OS_taskTable[OsTask_Bsw_MemServices],    \
  /* 5 */ &OS_taskTable[OsTask_Alv_ComHwAbs],    \
  /* 6 */ &OS_taskTable[OsTask_Bsw_Init],    \
  /* 7 */ &OS_taskTable[OsTask_Bsw_Events],    \
  /* 8 */ &OS_taskTable[OsTask_Alv_eCSApp],    \
  /* 9 */ &OS_taskTable[OsTask_Alv_Autotests],    \
  /* 10 */ &OS_taskTable[OsTask_Alv_ComServices],    \
  /* 11 */ &OS_taskTable[OsTask_Alv_EcuHwAbs],    \
  /* 12 */ &OS_taskTable[OsTask_Alv_ModeMngmt],    \
  /* 13 */ &OS_taskTable[OsTask_Bsw_ComEvents]

/*===================================================================
 * CORTEXM memory region sizes for MPU
 *==================================================================*/

/*===================================================================
 * CORTEXM Interrupts
 *==================================================================*/
#define OS_SRC4e_C0_NAME                      _OS_VECTOR_I078_CAN0_OFF_WARN
#define OS_SRC4e_C0_ISRID                     CAN0_ORED_IRQHandler
#define OS_SRC4e_C0_ENTRY                     OS_Cat2Entry
#define OS_SRC4e_C0_EXIT                      OS_CORTEXM_IntCat2Exit
#define OS_SRC4e_C0_LOCKLEVEL                 OS_KERNLOCK
#define OS_SRC4f_C0_NAME                      _OS_VECTOR_I079_CAN0_ERR
#define OS_SRC4f_C0_ISRID                     CAN0_Error_IRQHandler
#define OS_SRC4f_C0_ENTRY                     OS_Cat2Entry
#define OS_SRC4f_C0_EXIT                      OS_CORTEXM_IntCat2Exit
#define OS_SRC4f_C0_LOCKLEVEL                 OS_KERNLOCK
#define OS_SRC51_C0_NAME                      _OS_VECTOR_I081_CAN0_MSGBUF_0_15
#define OS_SRC51_C0_ISRID                     CAN0_ORED_0_15_MB_IRQHandler
#define OS_SRC51_C0_ENTRY                     OS_Cat2Entry
#define OS_SRC51_C0_EXIT                      OS_CORTEXM_IntCat2Exit
#define OS_SRC51_C0_LOCKLEVEL                 OS_KERNLOCK
#define OS_SRC52_C0_NAME                      _OS_VECTOR_I082_CAN0_MSGBUF_16_31
#define OS_SRC52_C0_ISRID                     CAN0_ORED_16_31_MB_IRQHandler
#define OS_SRC52_C0_ENTRY                     OS_Cat2Entry
#define OS_SRC52_C0_EXIT                      OS_CORTEXM_IntCat2Exit
#define OS_SRC52_C0_LOCKLEVEL                 OS_KERNLOCK
#define OS_SRC31_C0_NAME                      _OS_VECTOR_I049_LPIT_C1
#define OS_SRC31_C0_ISRID                     LPIT_0_CH_1_ISR
#define OS_SRC31_C0_ENTRY                     OS_Cat2Entry
#define OS_SRC31_C0_EXIT                      OS_CORTEXM_IntCat2Exit
#define OS_SRC31_C0_LOCKLEVEL                 OS_KERNLOCK
#define OS_SRC3a_C0_NAME                      _OS_VECTOR_I058_LPTIMER
#define OS_SRC3a_C0_ISRID                     LPTMR_ISR
#define OS_SRC3a_C0_ENTRY                     OS_Cat1Entry
#define OS_SRC3a_C0_EXIT                      OS_CORTEXM_IntCat1Exit
#define OS_SRC3a_C0_LOCKLEVEL                 3
#define OS_SRC3e_C0_NAME                      _OS_VECTOR_I062_PCM_PIN_PD
#define OS_SRC3e_C0_ISRID                     PORTD_ISR
#define OS_SRC3e_C0_ENTRY                     OS_Cat1Entry
#define OS_SRC3e_C0_EXIT                      OS_CORTEXM_IntCat1Exit
#define OS_SRC3e_C0_LOCKLEVEL                 2
#define OS_SRC3f_C0_NAME                      _OS_VECTOR_I063_PCM_PIN_PE
#define OS_SRC3f_C0_ISRID                     PORTE_ISR
#define OS_SRC3f_C0_ENTRY                     OS_Cat2Entry
#define OS_SRC3f_C0_EXIT                      OS_CORTEXM_IntCat2Exit
#define OS_SRC3f_C0_LOCKLEVEL                 OS_KERNLOCK
#define OS_SRC32_C0_NAME                      _OS_VECTOR_I050_LPIT_C2
#define OS_SRC32_C0_ISRID                     LPIT_0_CH_2_ISR
#define OS_SRC32_C0_ENTRY                     OS_Cat2Entry
#define OS_SRC32_C0_EXIT                      OS_CORTEXM_IntCat2Exit
#define OS_SRC32_C0_LOCKLEVEL                 OS_KERNLOCK
#define OS_SRC63_C0_NAME                      _OS_VECTOR_I099_FTM0_CH01
#define OS_SRC63_C0_ISRID                     Os_Counter_FTM0_0
#define OS_SRC63_C0_ENTRY                     OS_Cat2Entry
#define OS_SRC63_C0_EXIT                      OS_CORTEXM_IntCat2Exit
#define OS_SRC63_C0_LOCKLEVEL                 OS_KERNLOCK

#ifdef __cplusplus
}
#endif
#endif  /* OS_CONFIG_H */
