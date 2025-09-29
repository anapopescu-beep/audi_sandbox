/* kern-activateautoalarms.c
 *
 * This file contains the OS_ActivateAutoAlarms function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-activateautoalarms.c 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
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

/* OS_ActivateAutoAlarms()
 *
 * Activate all alarms that are specified for the requested mode
 *
 * !LINKSTO Kernel.Autosar.Autostart, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_ActivateAutoAlarms(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_uint16_t idx;
	const os_autoalarm_t *aa;
	os_alarmid_t a;
	os_coreid_t const myCoreId = OS_GetMyCoreId();

	idx = OS_startModeAlarms[OS_GetAppMode()];
	aa = &OS_autoStartAlarms[idx];
	a = aa->alarm;

	while ( a < OS_nAlarms )
	{
		/* COVPT-1 +3 */
		/* Possible diagnostic TOOLDIAG-1 <+2> */
		/* Deviation MISRAC2012-1 */
		if(OS_GetCoreIdFromAlarmId(a) == myCoreId)
		{
			if ( aa->method == OS_STARTMETHOD_ABS )
			{
				/* !LINKSTO Kernel.Autosar.OSEK.Differences.AlarmAutostartAbs, 1
				*/
				/* no way to propagate errors (and, unless there's an error in the
				 * configuration, none are expected anyways) -> ignore return value */
				(void) OS_KernSetAbsAlarm(a, aa->interval, aa->cycle);
			}
			else
			{
				/* An incorrectly generated method will start "relative".
				*/
				/* no way to propagate errors, see above -> ignore return value */
				(void) OS_KernSetRelAlarm(a, aa->interval, aa->cycle);
			}
		}
		idx++;
		aa = &OS_autoStartAlarms[idx];
		a = aa->alarm;
	}
}

#include <memmap/Os_mm_code_end.h>

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
