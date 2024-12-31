/* CORTEXM-timer-nxp-ftm-config.c - Configuration file for NXP FlexTimer (FTM) driver
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: CORTEXM-timer-nxp-ftm-config.c 1.1 2023/04/18 07:06:17CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#include <Os_kernel.h>
#include <CORTEXM/Os_CORTEXM_cpu.h>
#include <CORTEXM/Os_CORTEXM_timer_nxp_ftm.h>
#include <board.h>

/* Base addresses taken from S32K1xx-RM_Rev_12.1_022020.pdf section 47.4.3.1
*/
#ifndef OS_CORTEXM_NXP_FTM0
#define OS_CORTEXM_NXP_FTM0		((os_ftm_t *)0x40038000)
#endif

#ifndef OS_CORTEXM_NXP_FTM1
#define OS_CORTEXM_NXP_FTM1		((os_ftm_t *)0x40039000)
#endif

#ifndef OS_CORTEXM_NXP_FTM2
#define OS_CORTEXM_NXP_FTM2		((os_ftm_t *)0x4003a000)
#endif

#ifndef OS_CORTEXM_NXP_FTM3
#define OS_CORTEXM_NXP_FTM3		((os_ftm_t *)0x40026000)
#endif

#ifndef OS_CORTEXM_NXP_FTM4
#define OS_CORTEXM_NXP_FTM4		((os_ftm_t *)0x4006e000)
#endif

#ifndef OS_CORTEXM_NXP_FTM5
#define OS_CORTEXM_NXP_FTM5		((os_ftm_t *)0x4006f000)
#endif

#ifndef OS_CORTEXM_NXP_FTM6
#define OS_CORTEXM_NXP_FTM6		((os_ftm_t *)0x40070000)
#endif

#ifndef OS_CORTEXM_NXP_FTM7
#define OS_CORTEXM_NXP_FTM7		((os_ftm_t *)0x40071000)
#endif

const os_ftmdescriptor_t OS_ftmDescriptor[OS_MAX_FTM] =
{	{	OS_CORTEXM_NXP_FTM0,
		OS_CORTEXM_NXP_FTM0_CLKSRC,
		OS_CORTEXM_NXP_FTM0_PRESCALER
	},
	{	OS_CORTEXM_NXP_FTM1,
		OS_CORTEXM_NXP_FTM1_CLKSRC,
		OS_CORTEXM_NXP_FTM1_PRESCALER
	},
#if OS_MAX_FTM > 2
	{	OS_CORTEXM_NXP_FTM2,
		OS_CORTEXM_NXP_FTM2_CLKSRC,
		OS_CORTEXM_NXP_FTM2_PRESCALER
	},
	{	OS_CORTEXM_NXP_FTM3,
		OS_CORTEXM_NXP_FTM3_CLKSRC,
		OS_CORTEXM_NXP_FTM3_PRESCALER
	},
#endif
#if OS_MAX_FTM > 4
	{	OS_CORTEXM_NXP_FTM4,
		OS_CORTEXM_NXP_FTM4_CLKSRC,
		OS_CORTEXM_NXP_FTM4_PRESCALER
	},
	{	OS_CORTEXM_NXP_FTM5,
		OS_CORTEXM_NXP_FTM5_CLKSRC,
		OS_CORTEXM_NXP_FTM5_PRESCALER
	},
#endif
#if OS_MAX_FTM > 6
	{	OS_CORTEXM_NXP_FTM6,
		OS_CORTEXM_NXP_FTM6_CLKSRC,
		OS_CORTEXM_NXP_FTM6_PRESCALER
	},
	{	OS_CORTEXM_NXP_FTM7,
		OS_CORTEXM_NXP_FTM7_CLKSRC,
		OS_CORTEXM_NXP_FTM7_PRESCALER
	}
#endif
};

/* Editor settings: DO NOT DELETE
 * vi: set ts=4:
*/
