/* kern-timestampupdate.c
 *
 * This file contains the OS_TimestampUpdate function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-timestampupdate.c 1.1 2023/04/18 07:06:23CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_timestamp.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_TimestampUpdate
 *
 * This is called when the hardware timer for the timestamp generates an interrupt.
 * It is used when the hardware timer is solely used for timestamp generation.
 *
 * Internal timestamp timers are not expected to generate an interrupt, so
 * this function is empty in this case.
 *
 * This is an internal function that is only ever called from kernel or
 * generated code.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_TimestampUpdate(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
#if OS_USE_GLOBAL_GENERICTIMESTAMP
	os_hwt_t const * const ptimeStampTimer = OS_timeStampTimer;
#else
	os_hwt_t const * const ptimeStampTimer = OS_GetKernelData()->timeStampTimer;
#endif

	os_intstatus_t is;
	os_timervalue_t current;

	/* COVPT-1 */
	is = OS_IntDisableMax();

	/* Clear the timer interrupt
	*/
	OS_HwtStop(ptimeStampTimer);

	/* Read the timer and advance the timestamp
	*/
	current = OS_HwtRead(ptimeStampTimer);
	OS_AdvanceTimeStamp(current);

	/* Set the next time. We assume that this is always in the future, so the
	 * return value of OS_HwtStart() is not tested.
	*/
	OS_HwtStart(ptimeStampTimer, current, ptimeStampTimer->maxDelta);

	OS_IntRestoreMax(is);
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_timestampupdate_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
