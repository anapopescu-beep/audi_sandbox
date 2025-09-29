/* kern-initalarms.c
 *
 * This file contains the OS_InitAlarms() function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-initalarms.c 1.1 2023/04/18 07:06:23CEST Dan Dustinta (dan.dustinta) in_work  $
*/

/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: PointlessComparison
 *   Comparison with constant compile-time result
 *
 * Reason: In single-core configurations, the result is compile-time constant.
 */

/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 14.3 (required)
 * Controlling expressions shall not be invariant.
 *
 * Reason:
 * The invariance depends on the configuration. In single-core systems,
 * for example, the expression is always true.
*/

#include <Os_kernel.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_InitAlarms
 *
 * The 'next' of each alarm needs to be set to NULLALARM.
 * This is because the default bss value (0) is a valid alarm id.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_InitAlarms(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_alarmid_t i;
	os_coreid_t const myCoreId = OS_GetMyCoreId();

	for (i = 0; i < OS_totalAlarms; ++i)
	{
		os_alarm_t const * const as = &OS_alarmTableBase[i];
		/* COVPT-1 +3 */
		/* Deviation MISRAC2012-1 */
		/* Possible diagnostic TOOLDIAG-1 <1> */
		if (OS_GetCoreIdFromAlarmId(i) == myCoreId)
		{
			as->dynamic->next = OS_NULLALARM;
		}
	}
}

#include <memmap/Os_mm_code_end.h>

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
