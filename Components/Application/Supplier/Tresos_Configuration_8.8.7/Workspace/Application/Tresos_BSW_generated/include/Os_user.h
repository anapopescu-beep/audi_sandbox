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

#ifndef OS_USER_H
#define OS_USER_H
#ifdef __cplusplus
extern "C" {
#endif

#define OS_GENERATION_ID_OS_H    0x1905575eUL

#define OS_AUTOSAROS_VER         6

#define OS_AUTOSAROS_REV         1

#define OS_AUTOSAROS_CORE_BUILD  20230308

#define OS_AUTOSAROS_ARCH_BUILD  20230308

#ifndef OS_INTERRUPT_KEYWORD
#define OS_INTERRUPT_KEYWORD
#endif

#include <Os_api.h>

/*===================================================================
 * Alarms
 *==================================================================*/

/*===================================================================
 * Application modes
 *==================================================================*/
#define OSDEFAULTAPPMODE  0

/*===================================================================
 * Applications
 *==================================================================*/
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsApplication_0  0
#endif
/* Application Hooks */
/* Trusted Functions */

/*===================================================================
 * CPU Core configuration
 *==================================================================*/
#define OS_CORE_ID_0  0

/*===================================================================
 * Core Mapping
 *==================================================================*/
#define RES_SCHEDULER  0u

/*===================================================================
 * Counters
 *==================================================================*/
/* Macros for the configured counter values and time conversions */
#define OSMAXALLOWEDVALUE_OsCounter_HARDWARE  OS_U(65535)
#define OSTICKSPERBASE_OsCounter_HARDWARE  OS_U(1)
#define OSMINCYCLE_OsCounter_HARDWARE  OS_U(1)
#ifndef OS_ASM
extern void OS_CounterIsr_OsCounter_HARDWARE(void);
#endif  /* OS_ASM */
#define OS_NsToTicks_OsCounter_HARDWARE(x)  OS_NsToTicks_FTM0_0((x))
#define OS_TicksToNs_OsCounter_HARDWARE(x)  OS_TicksToNs_FTM0_0((x))
#define OS_TICKS2NS_OsCounter_HARDWARE(x)   (OS_TicksToNs_FTM0_0((x)))
#define OS_TICKS2US_OsCounter_HARDWARE(x)   (OS_TicksToNs_FTM0_0((x))/1000u)
#define OS_TICKS2MS_OsCounter_HARDWARE(x)   (OS_TicksToNs_FTM0_0((x))/1000000u)
#define OS_TICKS2SEC_OsCounter_HARDWARE(x)  (OS_TicksToNs_FTM0_0((x))/1000000000u)

/* Non-Internal Counter Ids */
#define OsCounter_HARDWARE  0


/* System Counter Macros */
#define OSMAXALLOWEDVALUE  OSMAXALLOWEDVALUE_OsCounter_HARDWARE
#define OSTICKSPERBASE     OSTICKSPERBASE_OsCounter_HARDWARE
#define OSMINCYCLE         OSMINCYCLE_OsCounter_HARDWARE
#define OSTICKDURATION     OS_TicksToNs_OsCounter_HARDWARE(1u)

/*===================================================================
 * Events
 *==================================================================*/
#define SchM_OSShutdownEvent  0x0001u
#define OsEvent_ReadWriteAllProcess  0x0001u

/*===================================================================
 * Interrupts
 *==================================================================*/
#ifndef OS_ASM
extern void OS_ISR_CAN0_ORED_IRQHandler(void);
#endif  /* OS_ASM */
#define CAN0_ORED_IRQHandler_ISR_CATEGORY  2
#define CAN0_ORED_IRQHandler_ISR_VECTOR    78
#define CAN0_ORED_IRQHandler_ISR_LEVEL     7
#ifndef OS_ASM
extern void OS_ISR_CAN0_Error_IRQHandler(void);
#endif  /* OS_ASM */
#define CAN0_Error_IRQHandler_ISR_CATEGORY  2
#define CAN0_Error_IRQHandler_ISR_VECTOR    79
#define CAN0_Error_IRQHandler_ISR_LEVEL     7
#ifndef OS_ASM
extern void OS_ISR_CAN0_ORED_0_15_MB_IRQHandler(void);
#endif  /* OS_ASM */
#define CAN0_ORED_0_15_MB_IRQHandler_ISR_CATEGORY  2
#define CAN0_ORED_0_15_MB_IRQHandler_ISR_VECTOR    81
#define CAN0_ORED_0_15_MB_IRQHandler_ISR_LEVEL     7
#ifndef OS_ASM
extern void OS_ISR_CAN0_ORED_16_31_MB_IRQHandler(void);
#endif  /* OS_ASM */
#define CAN0_ORED_16_31_MB_IRQHandler_ISR_CATEGORY  2
#define CAN0_ORED_16_31_MB_IRQHandler_ISR_VECTOR    82
#define CAN0_ORED_16_31_MB_IRQHandler_ISR_LEVEL     7
#ifndef OS_ASM
extern void OS_ISR_LPIT_0_CH_1_ISR(void);
#endif  /* OS_ASM */
#define LPIT_0_CH_1_ISR_ISR_CATEGORY  2
#define LPIT_0_CH_1_ISR_ISR_VECTOR    49
#define LPIT_0_CH_1_ISR_ISR_LEVEL     6
#ifndef OS_ASM
extern void OS_ISR_LPTMR_ISR(void);
#endif  /* OS_ASM */
#define LPTMR_ISR_ISR_CATEGORY  1
#define LPTMR_ISR_ISR_VECTOR    58
#define LPTMR_ISR_ISR_LEVEL     3
#ifndef OS_ASM
extern void OS_ISR_PORTD_ISR(void);
#endif  /* OS_ASM */
#define PORTD_ISR_ISR_CATEGORY  1
#define PORTD_ISR_ISR_VECTOR    62
#define PORTD_ISR_ISR_LEVEL     2
#ifndef OS_ASM
extern void OS_ISR_PORTE_ISR(void);
#endif  /* OS_ASM */
#define PORTE_ISR_ISR_CATEGORY  2
#define PORTE_ISR_ISR_VECTOR    63
#define PORTE_ISR_ISR_LEVEL     5
#ifndef OS_ASM
extern void OS_ISR_LPIT_0_CH_2_ISR(void);
#endif  /* OS_ASM */
#define LPIT_0_CH_2_ISR_ISR_CATEGORY  2
#define LPIT_0_CH_2_ISR_ISR_VECTOR    50
#define LPIT_0_CH_2_ISR_ISR_LEVEL     5
#define Os_Counter_FTM0_0_ISR_CATEGORY  2
#define Os_Counter_FTM0_0_ISR_VECTOR    99
#define Os_Counter_FTM0_0_ISR_LEVEL     4
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN0_ORED_IRQHandler  0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN0_Error_IRQHandler  1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN0_ORED_0_15_MB_IRQHandler  2
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define CAN0_ORED_16_31_MB_IRQHandler  3
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define LPIT_0_CH_1_ISR  4
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define LPTMR_ISR  5
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define PORTD_ISR  6
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define PORTE_ISR  7
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define LPIT_0_CH_2_ISR  8
#endif

/*===================================================================
 * Resources
 *==================================================================*/
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define RES_SCHEDULER_0  0
#endif

/*===================================================================
 * Schedule Tables
 *==================================================================*/
#define SchM_DefaultScheduleTable  0
#define Rte_DefaultScheduleTable  1
#define Rte_PostRunScheduleTable  2

/*===================================================================
 * Spinlocks
 *==================================================================*/

/*===================================================================
 * Tasks
 *==================================================================*/
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_Bsw_ReadWrite_AllProcess  0
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_AppIdle  1
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_Bsw_ComServices  2
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_Bsw_SysServices  3
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_Bsw_MemServices  4
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_Alv_ComHwAbs  5
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_Bsw_Init  6
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_Bsw_Events  7
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_Alv_eCSApp  8
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_Alv_Autotests  9
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_Alv_ComServices  10
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_Alv_EcuHwAbs  11
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_Alv_ModeMngmt  12
#endif
#if OS_KERNEL_TYPE != OS_MICROKERNEL
#define OsTask_Bsw_ComEvents  13
#endif

/*===================================================================
 * Time-stamp timer
 *==================================================================*/
#ifdef __cplusplus
}
#endif
#endif  /* OS_USER_H */
