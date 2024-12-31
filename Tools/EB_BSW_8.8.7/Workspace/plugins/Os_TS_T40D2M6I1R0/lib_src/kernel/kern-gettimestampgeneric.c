/* kern-gettimestampgeneric.c
 *
 * This file contains the OS_GetTimeStampGeneric() function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-gettimestampgeneric.c 1.1 2023/04/18 07:06:23CEST Dan Dustinta (dan.dustinta) in_work  $
*/

/*
 * TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: UnusedVariable
 *   unused parameter 'out'
 *
 * Reason:
 * For some architectures, function implementation may be empty as the function
 * is not used. For all others, the pointer is used to modify the addressed
 * object.
 */

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE == OS_MICROKERNEL) || (OS_USEGENERICTIMESTAMP==0)
const os_uint8_t OS_dummy_kern_gettimestampgeneric_c = 0xeb;
#else


#include <Os_timestamp.h>

#include <memmap/Os_mm_code_begin.h>

/* OS_GetTimeStampGeneric
 *
 * This function puts a timestamp value into the indicated "out" location.
 *
 * The value stored is the sum of the last updated time stamp and the number of ticks that
 * have occurred since then. The global time stamp value is *not* updated!
*/
/* Possible diagnostic TOOLDIAG-1 */
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_GetTimeStampGeneric(os_timestamp_t *out)
OS_TOOL_FUNCTION_ATTRIB_POST
{
#if OS_USE_GLOBAL_GENERICTIMESTAMP
	os_hwt_t const * const ptimeStampTimer = OS_timeStampTimer;
#else
	os_kerneldata_t * const kernel_data = OS_GetKernelData();
	os_hwt_t const * const ptimeStampTimer = kernel_data->timeStampTimer;
#endif

	if ( ptimeStampTimer != OS_NULL )
	{
		os_timervalue_t newTmrVal;
		os_timervalue_t diff;

		os_timestamp_t timeStampValue1, timeStampValue2;
		os_timervalue_t localLastTimeStampTime;

#if OS_USE_GLOBAL_GENERICTIMESTAMP
		volatile os_timervalue_t* const plastTimeStampTime = 
			&OS_lastTimeStampTime;
		volatile os_timestamp_t* const ptimeStampValue = 
			(volatile os_timestamp_t*)&OS_timeStampValue;
#else
		volatile os_timervalue_t* const plastTimeStampTime = 
			&kernel_data->lastTimeStampTime;
		volatile os_timestamp_t* const ptimeStampValue = 
			(volatile os_timestamp_t*)&kernel_data->timeStampValue;
#endif

		do {
			timeStampValue1 = *ptimeStampValue;
			newTmrVal = OS_HwtRead(ptimeStampTimer);
			localLastTimeStampTime = *plastTimeStampTime;
			timeStampValue2 = *ptimeStampValue;
		} 
		while ((timeStampValue1.tsHi != timeStampValue2.tsHi) ||
				(timeStampValue1.tsLo != timeStampValue2.tsLo));

		diff = OS_HwtSub(ptimeStampTimer, newTmrVal, localLastTimeStampTime);
		OS_TimeAdd32(out, timeStampValue2, diff);
	}
}


#include <memmap/Os_mm_code_end.h>

#endif
/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
