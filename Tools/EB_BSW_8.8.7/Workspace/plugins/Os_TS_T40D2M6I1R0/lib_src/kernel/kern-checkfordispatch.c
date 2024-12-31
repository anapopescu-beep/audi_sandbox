/* kern_checkfordispatch.c
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-checkfordispatch.c 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/

/* TOOLDIAG List of possible tool diagnostics
 *
 * TOOLDIAG-1) Possible diagnostic: StatementIsUnreachable
 *   statement not reached
 *
 * Reason:
 *  This warning depends on the OS configuration and library optimization.
 *  The statement can be reached, if extra runtime checks are turned on.
*/

#define OS_SID	OS_SID_Dispatch
#define OS_SIF	OS_svc_Dispatch

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_panic.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * CheckForDispatch
 *
 * called from asm handler
 * Isr's must be locked when calling this function
 * OS_GetKernelData()->inKernel is set back with old_inKernel, if no dispatching is done.
 * In case of dispatching OS_Dispatch sets OS_GetKernelData()->inKernel back.
 *
 * returns
 *  OS_NO_DISP           0: no dispatching
 *  OS_DISP_WITHOUT_SAVE 1: dispatch without save old context
 *  OS_DISP_WITH_SAVE    2: save old and dispatch
*/

OS_TOOL_FUNCTION_ATTRIB_PRE
os_unsigned_t OS_CheckForDispatch( os_uint8_t old_inKernel )
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_kerneldata_t * const kernel_data = OS_GetKernelData();
	os_unsigned_t disp = OS_NO_DISP;

	/* COVPT-1 */
	if ( OS_ExtraCheck(kernel_data->inKernel == 0) )
	{
		/* Serious kernel error
		*/
		/* can't propagate the return value of OS_PANIC -> ignore it */
		/* Possible diagnostic TOOLDIAG-1 <+1> */
		(void) OS_PANIC(OS_PANIC_IncorrectKernelNesting);
	}
	else
	if ( old_inKernel == 0 )
	{
		os_task_t const * const current_task = kernel_data->taskCurrent;

		if ( kernel_data->taskQueueHead == current_task )
		{
			if ( current_task == OS_NULL )
			{
				/* Nothing to do - will end in idle task
				*/
				disp = OS_DISP_WITHOUT_SAVE;
			}
			else
			{
				/* Three possibilities for current task's state here:
				 *  RUNNING - no task switch, just return to caller
				 *  READY_SYNC - task waited for an event which was set in an ISR
				 *  NEW - task has chained self, or terminated with 2nd activation queued, or been killed & reactivated
				*/
				if ( current_task->dynamic->state == OS_TS_RUNNING )
				{
					/* No task switch - return to caller.
					 * But first set the task's running priority if necessary.
					*/
					if ( current_task->dynamic->prio < kernel_data->taskCurrent->runPrio )
					{
						current_task->dynamic->prio = kernel_data->taskCurrent->runPrio;
					}
					/* need to continue timing supervision */
					OS_ARCH_STARTTASKEXECTIMING(current_task, OS_TS_RUNNING);
				}
				/* COVPT-2 */
				else if ( current_task->dynamic->state > OS_TS_MAX_TERMINATING )
				{
					disp = OS_DISP_WITH_SAVE;
				}
				else
				{
					/* Current task is terminating and restarting
					*/
					disp = OS_DISP_WITHOUT_SAVE;
				}
			}
		}
		else
		{
			if ((current_task == OS_NULL) || (current_task->dynamic->state <= OS_TS_MAX_TERMINATING))
			{
				disp = OS_DISP_WITHOUT_SAVE;
			}
			else
			{
				/* ASCOS-2610 */
				disp = OS_DISP_WITH_SAVE;
			}
		}
	}
	else
	{
		/* MISRA-C */
	}

	/* Trapping kernel use OS_GetKernelData()->inKernel as flag -> don't need to restore !
	 * Non-systemcall kernel use OS_GetKernelData()->inKernel as counter and need restore
	*/
#if (OS_KERNEL_TYPE==OS_FUNCTION_CALL)
	if( disp == OS_NO_DISP )
	{
		kernel_data->inKernel = old_inKernel;
	}
#endif

	return disp;
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_checkfordispatch_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
