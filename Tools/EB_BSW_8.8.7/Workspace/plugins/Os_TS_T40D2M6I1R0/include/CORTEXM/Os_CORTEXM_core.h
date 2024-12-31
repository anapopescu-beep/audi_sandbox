/* Os_CORTEXM_core.h - CORTEXM core header
 *
 * This file contains definitions for features that are common across all
 * the CORTEXM devices.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: Os_CORTEXM_core.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_CORTEXM_CORE_H
#define OS_CORTEXM_CORE_H

#include <Os_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * xPSR (APSR (rw), EPSR (ro), IPSR (ro)) masks for Cortex-M CORTEXM cores
 * Note: EPSR and IPSR are read-only.
 *       Writes to EPSR and IPSR are ignored.
*/

/* Thumb mode flag (ro) */
#define OS_CORTEXM_EPSR_T					(OS_U(1) << 24)

/* Exception number in IPSR for the system call. */
#define OS_IPSR_SVC							11

/*
 * CONTROL control register masks (rw)
 * Note: Unprivileged writes are ignored.
 *       Writing this flags is ignored in handler mode.
*/

/* Thread mode unprivileged access flag (0= privileged; 1= unprivileged)
** Note: Thread mode can NOT use this flag to get privileged accesss!
*/
/* Thread stack usage flag (0= main stack; 1= process stack) */
#define OS_CORTEXM_CONTROL_SP_PROCESS		0x00000002

/* CONTROL bit FPCA floating point extension active in current
 * context. This means, the floating point context is automatically
 * saved on exceptoin entry.
*/
#define OS_CORTEXM_CONTROL_FPCA				0x00000004

/* CONTROL bit nPRIV: Thread mode is non-privleged if set,
 * thread mode is privileged if cleared.
*/
#define OS_CORTEXM_CONTROL_NPRIV			0x00000001

/*
 * ICSR interrupt control and state
*/
#define OS_CORTEXM_ICSR						0xE000ED04

/*
 *ICSR PENDSVSET: Set the pending state of PENDSV.
*/
#define OS_CORTEXM_ICSR_PENDSVSET			(OS_U(1) << 28)

/*
** SHCSR system handler control and state register address (rw)
*/
#define OS_CORTEXM_SHCSR					0xE000ED24

/*
** HFSR hard fault status register register address (r)
*/
#define OS_CORTEXM_HFSR						0xE000ED2C

/*
** CFSR configurable fault status register address (r)
*/
#define OS_CORTEXM_CFSR						0xE000ED28

/*
** MMFAR mem manage fault address register address (r)
*/
#define OS_CORTEXM_MMFAR					0xE000ED34

/*
** BFAR bus fault address register address (r)
*/
#define OS_CORTEXM_BFAR						0xE000ED38


/*
 * SHCSR system handler control and state register masks (rw)
 * Note: The active bit of the current handler must never be cleared,
 *       because the IPSR is not changed to reflect this.
 *       Only use it to change stacked active handlers.
*/

/* Supervisor call exception active flag (0= not active; 1= active) */
#define OS_CORTEXM_SHCSR_SVCALLACT			(OS_U(1) << 7)

/*
** Definition of values for EXC_RETURN (the exception return value)
** On exception exit the CPU does the following:
** - switch to the encoded CPU mode (handler/thread mode)
** - use the specified stack pointer (main/process sp)
** - restores the CPU context (PC,xPSR,LR,r12,r3,r2,r1,r0)
** - restores the FP context or not (FP/-)
**
** Note: Any EXC_RETURN value not listed in the Cortex-M manuals is reserved.
**       Using a reserved EXC_RETURN value causes a chained UsageFault exception.
**
** Note2: Beginning with ARMv8, the stack selection bit is set according to the
**        current value in CONTROL regardless of handler mode vs. thread mode.
**        Thus, we cannot just use it to destinguish between the two stacks but
**        have to check the mode bit, too.
*/
/* mask for the used stack pointer at the time of exception */
#define OS_CORTEXM_EXC_RETURN_STACK_PSP			0x00000004
/* mask for the active processor mode at the time of exception */
#define OS_CORTEXM_EXC_RETURN_MODE_THREAD		0x00000008

#if (OS_CORTEXM_VARIANT == OS_CORTEXM_ARMV7)

/* MODE: handler mode; SP: main stack;    FP: - */
#define OS_CORTEXM_EXC_RETURN_HANDLER_MSP		0xfffffff1
/* MODE: thread mode;  SP: process stack; FP: - */
#define OS_CORTEXM_EXC_RETURN_THREAD_PSP		0xfffffffd

#elif (OS_CORTEXM_VARIANT == OS_CORTEXM_ARMV8)

/* MODE: handler mode; SP: main stack;    FP: - */
#define OS_CORTEXM_EXC_RETURN_HANDLER_MSP		0xffffffb0
/* MODE: thread mode;  SP: process stack; FP: - */
#define OS_CORTEXM_EXC_RETURN_THREAD_PSP		0xffffffbc

#else
#error "Unknown OS_CORTEXM_VARIANT, check your header files"
#endif

/*
** Definition of exception codes
*/
/* reset stack pointer */	/*	0x00 */
/* reset entry */			/*	0x04 */
#define OS_CORTEXM_EX_NMI			0x08
#define OS_CORTEXM_EX_HARD_FAULT	0x0c
#define OS_CORTEXM_EX_MEM_MANAGE	0x10
#define OS_CORTEXM_EX_BUS_FAULT		0x14
#define OS_CORTEXM_EX_USAGE_FAULT	0x18
#define OS_CORTEXM_EX_RESERVED_1	0x1c
#define OS_CORTEXM_EX_RESERVED_2	0x20
#define OS_CORTEXM_EX_RESERVED_3	0x24
#define OS_CORTEXM_EX_RESERVED_4	0x28
#define OS_CORTEXM_EX_SVC			0x2c
#define OS_CORTEXM_EX_DEBUG			0x30
#define OS_CORTEXM_EX_RESERVED_5	0x34
#define OS_CORTEXM_EX_PEND_SV		0x38
#define OS_CORTEXM_EX_SYS_TICK		0x3c

/* Position of link register (magic return from exception value)
 * in non-volatile context on kernel stack.
 *
 * Normal stack consists of MPU state (2 regs), gap, r4-r11, lr.
 * Current stack pointer points to begin of MPU state.
*/
#define OS_CORTEXM_POS_LR		(44)

#ifdef __cplusplus
}
#endif

#endif

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
