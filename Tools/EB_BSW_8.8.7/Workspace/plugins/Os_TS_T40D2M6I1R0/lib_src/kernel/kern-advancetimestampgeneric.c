/* kern-advancetimestampgeneric.c
 *
 * This file contains the OS_AdvanceTimeStampGeneric() function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-advancetimestampgeneric.c 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
 */

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 19.1 (mandatory)
 * An object shall not be assigned or copied to an overlapping object.
 *
 * Reason:
 * The exception 1 applies, because the objects overlap each other exactly.
*/

/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: PossibleRedundantExpression
 *   Possible redundant expression.
 *
 * Reason: Cause of this warning is the macro OS_TimeAdd32(). Because it is a
 *   generic macro for timestamp calculations, it contains, if called with the
 *   same structure as source and destination, an actually redundant assignment
 *   of the high word to itself. Using a common generic macro is preferable
 *   here, so this warning does not denote a problem.
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE == OS_MICROKERNEL) || (OS_USEGENERICTIMESTAMP==0)
const os_uint8_t OS_dummy_kern_advancetimestampgeneric_c = 0xeb;
#else

#include <Os_timestamp.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_AdvanceTimeStampGeneric
 *
 * This function advances the time stamp value by adding the number of ticks of the hardware
 * timestamp timer that have happened since "last time" to the global timestamp value.
 *
 * NOTE: we do not test the ptimeStampTimer for OS_NULL here, because this function
 * is only called when this is not the case. This is ensured by the OS generator.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_AdvanceTimeStampGeneric(os_timervalue_t newTmrVal)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_timervalue_t diff;
#if OS_USE_GLOBAL_GENERICTIMESTAMP
	os_hwt_t const * const ptimeStampTimer = OS_timeStampTimer;
	os_timervalue_t* const plastTimeStampTime = &OS_lastTimeStampTime;
	/* Possible diagnostic TOOLDIAG-1 <1> */
	os_timestamp_t* const ptimeStampValue = &OS_timeStampValue;
#else
	os_kerneldata_t * const kernel_data = OS_GetKernelData();
	os_hwt_t const * const ptimeStampTimer = kernel_data->timeStampTimer;
	os_timervalue_t* const plastTimeStampTime = &kernel_data->lastTimeStampTime;
	os_timestamp_t* const ptimeStampValue = &kernel_data->timeStampValue;
#endif

	os_intstatus_t const is = OS_IntDisableMax();

	diff = OS_HwtSub(ptimeStampTimer, newTmrVal, *plastTimeStampTime);
	/* Deviation MISRAC2012-1 <1> */
	OS_TimeAdd32(ptimeStampValue, *ptimeStampValue, diff);
	*plastTimeStampTime = newTmrVal;

	OS_IntRestoreMax(is);
}

#include <memmap/Os_mm_code_end.h>

#endif
/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
