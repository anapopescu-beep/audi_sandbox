/* kern-returnfromcall.c
 *
 * This file contains the OS_KernReturnFromCall function
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-returnfromcall.c 1.1 2023/04/18 07:06:23CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_panic.h>

#include <memmap/Os_mm_code_begin.h>

/*
 * OS_KernReturnFromCall
 *
 * This function is the kernel function that is called in response to the ReturnFromCall system call.
 * If it is called in the context of a Category-2 ISR or an application hook function, it attempts
 * to kill the ISR or hook function. If that fails, the system gets shut down.
 *
 * If the system call is invoked from any other calling context it silently returns.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_KernReturnFromCall(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_kerneldata_t * const kernel_data = OS_GetKernelData();
	os_isrdynamic_t *isrDynamic;

	if ( kernel_data->inFunction == OS_INCAT2 )
	{
		isrDynamic = OS_isrTableBase[kernel_data->isrCurrent].dynamic;
		/* COVPT-1 */
		if ( OS_KillCalledContext(&isrDynamic->c) != OS_E_OK)
		{
			/* If the ISR cannot be killed for some reason we
			 * must shut down
			*/
			/* can't propagate the return value of OS_PANIC -> ignore it */
			(void) OS_PANIC(OS_PANIC_IsrCannotBeKilled);
		}
	}
	else
	if ( kernel_data->inFunction == OS_INSTARTUPHOOK )
	{
		/* COVPT-2 */
		if ( !OS_AppIsNull(kernel_data->hookApp) )
		{
			/* COVPT-3 */
			if ( OS_KillCalledContext(&kernel_data->sHookContext.c) != OS_E_OK)
			{
				/* If the hook cannot be killed for some reason we
				 * must shut down
				*/
				/* can't propagate the return value of OS_PANIC -> ignore it */
				(void) OS_PANIC(OS_PANIC_HookCannotBeKilled);
			}
		}
	}
	else
	if ( kernel_data->inFunction == OS_INSHUTDOWNHOOK )
	{
		/* COVPT-4 */
		if ( !OS_AppIsNull(kernel_data->hookApp) )
		{
			/* COVPT-5 */
			if ( OS_KillCalledContext(&kernel_data->sHookContext.c) != OS_E_OK)
			{
				/* If the hook cannot be killed for some reason we
				 * must shut down without calling any further hooks.
				*/
				OS_ShutdownNoHooks();
			}
		}
	}
	/* COVPT-6 +2 */
	else
	if ( kernel_data->inFunction == OS_INERRORHOOK )
	{
		/* COVPT-7 */
		if ( !OS_AppIsNull(kernel_data->hookApp) )
		{
			/* COVPT-8 */
			if ( OS_KillCalledContext(&kernel_data->eHookContext.c) != OS_E_OK)
			{
				/* If the hook cannot be killed for some reason we
				 * must shut down
				*/
				/* can't propagate the return value of OS_PANIC -> ignore it */
				(void) OS_PANIC(OS_PANIC_HookCannotBeKilled);
			}
		}
	}
	else
	{
		/* MISRA-C */
	}
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_kern_returnfromcall_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
