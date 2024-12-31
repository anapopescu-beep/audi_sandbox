/* Os_timers-configuration_CORTEXM.c
 *
 * This file provides architecture-specific kernel configuration data
 * for CORTEXM.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_timers_configuration_CORTEXM.c 1.1 2023/04/18 07:06:17CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#include <Os_configuration.h>
#include <Os_kernel.h>
#include <Os_tool.h>
#include <Os_configuration_decls.h>
#if ((OS_CORTEXM_TIMER & OS_CORTEXM_TIMER_FS_STM) != 0)
#include <CORTEXM/Os_CORTEXM_timer_fs_stm.h>
#endif /* (OS_CORTEXM_TIMER == OS_CORTEXM_TIMER_FS_STM) */
#if ((OS_CORTEXM_TIMER & OS_CORTEXM_TIMER_ARC) != 0)
#include <CORTEXM/Os_CORTEXM_timer_arc.h>
#endif /* (OS_CORTEXM_TIMER == OS_CORTEXM_TIMER_ARC) */

#include <memmap/Os_mm_const_begin.h>

#if ((OS_CORTEXM_TIMER & OS_CORTEXM_TIMER_FS_STM) != 0)
/* Set the global prescaler of the STM module(s) */
const os_uint8_t OS_stm_prescaler[OS_CORTEXM_STM_NMODULES] =
{
	OS_STM0_PRESCALER,
#if (OS_CORTEXM_STM_NMODULES >= 2)
	OS_STM1_PRESCALER,
#endif
#if (OS_CORTEXM_STM_NMODULES >= 3)
	OS_STM2_PRESCALER,
#endif
#if (OS_CORTEXM_STM_NMODULES >= 4)
	OS_STM3_PRESCALER,
#endif
#if (OS_CORTEXM_STM_NMODULES >= 5)
	OS_STM4_PRESCALER,
#endif
#if (OS_CORTEXM_STM_NMODULES >= 6)
	OS_STM5_PRESCALER,
#endif
#if (OS_CORTEXM_STM_NMODULES >= 7)
	OS_STM6_PRESCALER,
#endif
#if (OS_CORTEXM_STM_NMODULES >= 8)
	OS_STM7_PRESCALER,
#endif
#if (OS_CORTEXM_STM_NMODULES >= 9)
	OS_STM8_PRESCALER,
#endif
#if (OS_CORTEXM_STM_NMODULES >= 10)
	OS_STM9_PRESCALER,
#endif
#if (OS_CORTEXM_STM_NMODULES >= 11)
	OS_STM10_PRESCALER,
#endif
#if (OS_CORTEXM_STM_NMODULES >= 12)
	OS_STM11_PRESCALER,
#endif
#if (OS_CORTEXM_STM_NMODULES >= 13)
	OS_STM12_PRESCALER,
#endif
};
#if (OS_CORTEXM_STM_NMODULES >= 14)
#error "This file needs modification to support fourteen or more STMs!"
#endif
#ifdef OS_STM_DEBUG_MODE
const os_uint8_t OS_stm_debugmode = OS_STM_DEBUG_MODE;
#else
const os_uint8_t OS_stm_debugmode = 0;
#endif
#endif /* (OS_CORTEXM_TIMER == OS_CORTEXM_TIMER_FS_STM) */

#if ((OS_CORTEXM_TIMER & OS_CORTEXM_TIMER_FS_FTM) != 0)
/* No configuration of FTM timer needed here -- everything 
 * necessary is done in the FTM module specific source files
*/
#endif/* (OS_CORTEXM_TIMER == OS_CORTEXM_TIMER_FS_FTM) */

#if ((OS_CORTEXM_TIMER & OS_CORTEXM_TIMER_SAME5X_TC) != 0)
#if (defined(OS_CORTEXM_TC_NMODULES) \
	&&	defined(OS_TC0_PRESCALAR) \
	&&	defined(OS_TC2_PRESCALAR) \
	&&	defined(OS_TC4_PRESCALAR) \
	)
/* Set the global prescaler of the TC module(s) */
const os_uint8_t OS_same5x_tc_prescaler[OS_CORTEXM_TC_NMODULES] =
{
	OS_TC0_PRESCALAR,
#if (OS_CORTEXM_TC_NMODULES >= 2)
	OS_TC2_PRESCALAR,
#endif
#if (OS_CORTEXM_TC_NMODULES >= 3)
	OS_TC4_PRESCALAR,
#endif
};
#else
#error "Either the prescalar or the number of TCs is not defined. Check board.h and derivative header files!"
#endif /* OS_CORTEXM_TC_NMODULES */
#endif/* (OS_CORTEXM_TIMER == OS_CORTEXM_TIMER_SAME5X_TC) */

#if defined(OS_CORTEXM_PIT_NMODULES)
#if defined(OS_PIT_DEBUG_MODE)
const os_uint8_t OS_pit_debugmode = OS_PIT_DEBUG_MODE;
#else
const os_uint8_t OS_pit_debugmode = 0;
#endif /* OS_PIT_DEBUG_MODE */
#endif /* OS_CORTEXM_PIT_NMODULES */

#if ((OS_CORTEXM_TIMER & OS_CORTEXM_TIMER_ARC) != 0)
/* Set the global prescaler of the ARC module(s) */
const os_uint8_t OS_arc_prescaler[OS_CORTEXM_ARC_NMODULES] =
{
	OS_ARC0_PRESCALER,
#if (OS_CORTEXM_ARC_NMODULES >= 2)
	OS_ARC1_PRESCALER,
#endif
#if (OS_CORTEXM_ARC_NMODULES >= 3)
	OS_ARC2_PRESCALER,
#endif
#if (OS_CORTEXM_ARC_NMODULES >= 4)
	OS_ARC3_PRESCALER,
#endif
#if (OS_CORTEXM_ARC_NMODULES >= 5)
	OS_ARC4_PRESCALER,
#endif
#if (OS_CORTEXM_ARC_NMODULES >= 6)
	OS_ARC5_PRESCALER,
#endif
#if (OS_CORTEXM_ARC_NMODULES >= 7)
	OS_ARC6_PRESCALER,
#endif
#if (OS_CORTEXM_ARC_NMODULES >= 8)
	OS_ARC7_PRESCALER,
#endif
#if (OS_CORTEXM_ARC_NMODULES >= 9)
	OS_ARC8_PRESCALER,
#endif
#if (OS_CORTEXM_ARC_NMODULES >= 10)
	OS_ARC9_PRESCALER,
#endif
};
#if (OS_CORTEXM_ARC_NMODULES >= 11)
#error "This file needs modification to support eleven or more ARCs!"
#endif
#ifdef OS_ARC_DEBUG_MODE
const os_uint8_t OS_arc_debugmode = OS_ARC_DEBUG_MODE;
#else
const os_uint8_t OS_arc_debugmode = 0;
#endif
#endif /* (OS_CORTEXM_TIMER == OS_CORTEXM_TIMER_ARC) */

#include <memmap/Os_mm_const_end.h>

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
