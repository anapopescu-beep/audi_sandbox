/* kern-starttimestamptimergeneric.c
 *
 * This file contains the OS_StartTimestampTimerGeneric function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-starttimestamptimergeneric.c 1.1 2023/04/18 07:06:23CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#include <Os_kernel.h>
#include <Os_config.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <memmap/Os_mm_code_begin.h>

/* OS_StartTimeStampTimerGeneric
 *
 * The timestamp timer is started with an interrupt duration of its max delta.
 *
 * This function must be called during OS_KernStartOs(), after OS_InitTimers() and OS_InitInterrupts().
 * It must be called before any auto-activated alarms are started, in case the same timer is being
 * used to drive a hardware counter.
 * If the timestamp timer shares its timer with a HWCounter an internal periodic alarm is set.
 * This no-op alarm ensures that the timestamp value increases with time consistently.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_StartTimeStampTimerGeneric(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
#if (OS_NSHAREDHWCOUNTERTIMESTAMP != 0)
	const os_alarm_t * as = &OS_alarmTableBase[OS_SHAREDHWCOUNTERTIMESTAMP_ALARMID];
	const os_counter_t * cs = &OS_counterTableBase[as->counter];
	os_tick_t alarm_cyc = 0;
#endif

#if OS_USE_GLOBAL_GENERICTIMESTAMP
	os_coreid_t const myCoreId = OS_GetMyCoreId();
	/* COVPT-1 */
	if ( myCoreId == OS_INITCORE )
	{
		if ( OS_timeStampTimer != OS_NULL )
		{
			OS_HwtStart(OS_timeStampTimer, OS_lastTimeStampTime, OS_timeStampTimer->maxDelta);
#if (OS_NSHAREDHWCOUNTERTIMESTAMP != 0)
			alarm_cyc = OS_timeStampTimer->maxDelta - 1;
#endif
		}
	}
#else /* OS_USE_GLOBAL_GENERICTIMESTAMP == 0 */
	os_kerneldata_t * const kernel_data = OS_GetKernelData();
	/* COVPT-2 */
	if ( kernel_data->timeStampTimer != OS_NULL )
	{
		OS_HwtStart(kernel_data->timeStampTimer, kernel_data->lastTimeStampTime, kernel_data->timeStampTimer->maxDelta);
#if (OS_NSHAREDHWCOUNTERTIMESTAMP != 0)
		alarm_cyc = kernel_data->timeStampTimer->maxDelta - 1;
#endif

	}
#endif /* OS_USE_GLOBAL_GENERICTIMESTAMP != 0 */

#if (OS_NSHAREDHWCOUNTERTIMESTAMP != 0)
	OS_LocalSetAlarm(OS_SHAREDHWCOUNTERTIMESTAMP_ALARMID, as, cs, alarm_cyc, alarm_cyc, OS_TRUE);
#endif
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_starttimestamptimergeneric_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
