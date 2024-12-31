/* kern-exectimertimestampinterrupt.c
 *
 * This file contains the OS_ExecTimerTimestampInterrupt function
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-exectimertimestampinterrupt.c 1.1 2023/04/18 07:06:23CEST Dan Dustinta (dan.dustinta) in_work  $
*/
/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: UnusedVariable
 *   Variable is never used.
 *
 * Reason: Not an issue, variable will be used if timing protection is enabled.
 *
 * TOOLDIAG-2) Possible diagnostic: ControllingExpressionIsConstant
 *   Controlling expression is constant.
 *
 * Reason: Not an issue, controlling expression is not a constant if
 * timing protection is enabled.

 */
/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 20.7 (required)
 * Expressions resulting from the expansion of macro parameters shall be
 * enclosed in parentheses.
 *
 * Reason:
 * If the parameter was enclosed in parentheses, this would result in a
 * C language syntax error. Hence, this isn't viable.
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_ExecTimerTimestampInterrupt
 *
 * This function handles the interrupt that occurs when the execution-time
 * timeout interrupt occurs. It must calculate the time used and update
 * the appropriate etMax and perform execution-time aggregation.
 * Then it calls OS_ExceedExecTime() to kill the offending task or ISR.
 *
 * This function is used when the timestamp is attached to the execution timer.
 * See also OS_ExecTimerInterrupt() in kern-exectimerinterrupt.c
 *
 * !LINKSTO Kernel.Autosar.Protection.TimingProtection.ExecutionTime, 2
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_ExecTimerTimestampInterrupt(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_kerneldata_t * const kernel_data = OS_GetKernelData();
	os_coreid_t const myCoreId = OS_GetMyCoreId();
	os_tick_t used, remaining;

	/* Clear the timer interrupt
	*/
	OS_HwtStop(OS_executionTimer[myCoreId]);

	/* Get time used since last call. This updates kernel_data->accounting.frc, which we can then
	 * give to the timestamp.
	*/
	used = OS_GetTimeUsed();

	/* Advance the time stamp
	*/
	OS_AdvanceTimeStamp(kernel_data->accounting.frc);

	/* Check if there's an execution timer running
	*/
	/* COVPT-1 */
	if ( kernel_data->accounting.etType == OS_ACC_NONE )
	{
		/* No timing in progress - just set the timer interrupt for the
		 * slow tickover time.
		*/
		OS_HwtStart(
				OS_executionTimer[myCoreId],
				kernel_data->accounting.frc,
				OS_executionTimer[myCoreId]->maxDelta);
	}
	else
	{
		/* Add 'used' onto the current accounting sum, with saturation!
		*/
		/* COVPT-2 */
		if ( used > (OS_MAXTICK - kernel_data->accounting.etUsed) )
		{
			kernel_data->accounting.etUsed = OS_MAXTICK;
		}
		else
		{
			kernel_data->accounting.etUsed += used;
		}

		if ( kernel_data->accounting.etUsed >= kernel_data->accounting.etLimit )
		{
			if ( kernel_data->inFunction == OS_INTASK )
			{
				kernel_data->accounting.taskTimingNesting = 1;

				/* Possible diagnostic TOOLDIAG-2 <1> */
				if ( OS_GET_ACCT(((kernel_data->taskCurrent->flags & OS_TF_MEASUREEXEC) != 0)
						&& (kernel_data->taskCurrent->accounting->etMax < kernel_data->accounting.etUsed)) )
				{
					/* Deviation MISRAC2012-1 <1> */
					OS_SET_ACCT(kernel_data->taskCurrent->accounting->etMax = kernel_data->accounting.etUsed);
				}
			}
			/* COVPT-3 +2 */
			else
			if ( kernel_data->inFunction == OS_INCAT2 )
			{	/* Possible diagnostic TOOLDIAG-1 <1> */
				const os_isr_t *isr = &OS_isrTableBase[kernel_data->isrCurrent];

				/* Possible diagnostic TOOLDIAG-2 <1> */
				if ( OS_GET_ACCT(((isr->flags & OS_ISRF_MEASUREEXEC) != 0)
						&& (isr->accounting->etMax < kernel_data->accounting.etUsed)) )
				{
					/* Deviation MISRAC2012-1 <1> */
					OS_SET_ACCT(isr->accounting->etMax = kernel_data->accounting.etUsed);
				}
			}
			else
			{
				/* MISRA */
			}

			OS_ExceedExecTime();

			OS_HwtStart(
					OS_executionTimer[myCoreId],
					kernel_data->accounting.frc,
					OS_executionTimer[myCoreId]->maxDelta);
		}
		else
		{
			remaining = kernel_data->accounting.etLimit - kernel_data->accounting.etUsed;

			OS_CtrStart(
					OS_executionTimer[myCoreId],
					kernel_data->accounting.frc,
					remaining);
		}
	}
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_exectimertimestampinterrupt_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
