/* kern-hwcountertimestampupdate.c
 *
 * This file contains the OS_HwCounterTimestampUpdate function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-hwcountertimestampupdate.c 1.1 2023/04/18 07:06:23CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#include <Os_kernel.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_HwCounterTimestampUpdate
 *
 * This function is called whenver a HARDWARE counter needs to be updated. This happens when
 * the interrupt occurs. This function is used when the counter's timer is also selected
 * as the timer for the generic timestamp.
 *
 * This is an internal function that is only ever called from kernel or
 * generated code, so no parameter checking is done.
 *
 * !LINKSTO Kernel.Autosar.Counter.Types.HARDWARE, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_HwCounterTimestampUpdate(const os_counter_t *cs)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	const os_hwt_t *hwt;
	os_timervalue_t current;
	os_tick_t delta;
	os_tick_t nTicks;
	os_boolean_t again;
	os_intstatus_t is;
	os_counterdynamic_t *cd;

	cd = cs->dynamic;
	hwt = cs->hwt;

	is = OS_IntDisable();

	/* Clear the timer interrupt
	*/
	OS_HwtStop(hwt);

	/* Read the current timer value
	*/
	current = OS_HwtRead(hwt);

	/* Advance the timestamp
	*/
	OS_AdvanceTimeStamp(current);

	/* Repeat: advance the counter until the next alarm is in the future
	*/
	do {
		/* Calculate number of ticks since last time we looked
		 * Remember current timer value for the next update.
		*/
		nTicks = OS_HwtSub(hwt, current, *hwt->lastValue);
		*hwt->lastValue = current;

		/* Advance the counter by that number of ticks. The function returns the delta
		 * of the first alarm in the queue, or zero if there isn't one.
		*/
		delta = OS_AdvanceCounter(cs, cd, nTicks, is);

		/* Force a non-zero delta for the timestamp timer and limit the delta to what the timer can manage.
		*/
		if ( delta == 0 )
		{
			delta = hwt->maxDelta;
		}
		else
		if ( delta > hwt->maxDelta )
		{
			delta = hwt->defDelta;
		}
		else
		{
			/* MISRA */
		}

		/* Loop stops when if delta is zero (no more alarms in queue)
		 * Loop stops when OS_HwtStart reports that it has set a time in the future.
		 * Delta is never zero here, so we don't test before restarting the timer.
		*/
		if ( OS_HwtStart(hwt, *hwt->lastValue, delta) )
		{
			/* Re-read the timer if we're going round again
			*/
			again = OS_TRUE;
			current = OS_HwtRead(hwt);
		}
		else
		{
			again = OS_FALSE;
		}
	} while ( again );

	OS_IntRestore(is);
}

#include <memmap/Os_mm_code_end.h>

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
