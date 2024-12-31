/* Os_CORTEXM_S32K14X.h - Description of CORTEXM variant S32K14X
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_CORTEXM_S32K14X.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/


#ifndef OS_S32K14X_H
#define OS_S32K14X_H

/*
 * This derivative has the following features:
*/

/* This derivate has max 8 number of FTM timer modules.
 * S32K144 - 4 FTM timer modules available
 * S32K146 - 6 FTM timer modules available
 * S32K148 - 8 FTM timer modules available
 *
 * Note: FTM modules that are not configured will not get accessed by the driver.
*/
#define OS_CORTEXM_TIMER				OS_CORTEXM_TIMER_FS_FTM
#define OS_MAX_FTM						8u

/* This is an ARMv7-M core */
#define OS_CORTEXM_VARIANT				OS_CORTEXM_ARMV7

/* This derivative has a floating-point unit */
#ifndef OS_CORTEXM_FPU
#define OS_CORTEXM_FPU					OS_CORTEXM_FPU_ARMV7
#endif

/* Features related the generic part of the kernel:
 *
 * - OS_STACKGROWS:		either OS_STACKGROWSDOWN or OS_STACKGROWSUP as necessary
 * - OS_STACKFILL:		0xebe..b, enough to fill an os_stackelement_t with bytes of 0xeb
 * - OS_HWT_POWEROF2:	1 if all supported hardware timers wrap cleanly on the (2**n)th tick, 0 otherwise.
*/
#define OS_STACKGROWS				OS_STACKGROWSDOWN
#define OS_STACKFILL				OS_U(0xebebebeb)
#define OS_HWT_POWEROF2				1
#define OS_USE_MMU					0
#define OS_USE_MPU					1
#define OS_CORTEXM_MPU_TYPE			OS_CORTEXM_MPU_NXP

/* Caches are only relevant for cross-core communication.
 * Use arbitrary values.
*/
#define OS_CACHE_MODE		OS_CACHE_MODE_NONE
#define OS_CACHE_LINE_LEN	32

/* Multicore support: Device is a single-core. */
#define OS_N_CORES_MAX				1

/* NVIC number of interrupt sources */
#define OS_CORTEXM_NUM_SOURCES		147

/* NVIC lowest interrupt locking level.
 * One lower than the lowest possible priority an IRQ request can have,
 * so that all interrupts are enabled.
*/
#define OS_CORTEXM_ALL_INT_ENABLED_LEVEL	OS_U(16)

/* NVIC number of bits to shift the interrupt priority to the left */
/* Note: An NVIC implementation may use a sub-range of the architectural priority range.
 * Example: If the architectural priority range is 8 bit and an implementation
 *          uses only 6 bit the priorities have to be shifted by 2 bit to the left.
*/
#define OS_CORTEXM_INT_PRIO_SHIFT		4

/* S32K14X has a CORTEX-M4F core (see ASCOS-5685) */
#define OS_CORTEXM_HAS_ERRATA_838869	1

/*
 * If we need a CPU related initialization this can be done
 * by refining the OS_CORTEXM_CpuInitArch macro.
*/
#define OS_CORTEXM_CpuInitArch()				\
	do											\
	{											\
		OS_CORTEXM_SetupVFPCoprocessor();		\
	} while(0)

#endif
/* Editor settings: DO NOT DELETE
 * vi: set ts=4:
*/
