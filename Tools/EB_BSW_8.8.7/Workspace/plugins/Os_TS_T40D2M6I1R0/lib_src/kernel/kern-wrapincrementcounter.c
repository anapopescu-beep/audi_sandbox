/* kern-wrapincrementcounter.c
 *
 * This file contains the OS_WrapIncrementCounter wrapper function
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-wrapincrementcounter.c 1.1 2023/04/18 07:06:23CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE==OS_MICROKERNEL)
#include <public/Mk_public_api.h>
#endif

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_WrapIncrementCounter
 *
 * This function calls the kernel OS_KernIncrementCounter function with
 * a counter id as specified in the counter part of the alarm parameter union.
 *
 * !LINKSTO Kernel.Autosar.OSEK.Differences.AlarmActionIncrementCounter, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_WrapIncrementCounter(const os_alarm_t *a)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_intstatus_t is;
	const os_counter_t *cp;
	os_counterdynamic_t *cd;
	os_counterid_t c;

#if OS_KERNEL_TYPE!=OS_MICROKERNEL
	os_uint8_t save;
	os_kerneldata_t * const kernel_data = OS_GetKernelData();

	save = kernel_data->inFunction;
	kernel_data->inFunction = OS_ININTERNAL;
#endif
	c = (os_counterid_t)a->object;
	cp = &OS_counterTableBase[c];
	cd = cp->dynamic;

	/* Cross core IncrementCounter is not allowed, according to AUTOSAR 4.0, 7.9.8. */
#if (OS_N_CORES == 1)
	is = OS_IntDisable();
	/* no way to propagate errors -> ignore return value */
	(void) OS_AdvanceCounter(cp, cd, 1, is);
	OS_IntRestore(is);
#else
	/* COVPT-1 */
	if ( OS_GetCoreIdFromCounterId(c) == OS_GetMyCoreId() )
	{
		is = OS_IntDisable();
		/* no way to propagate errors -> ignore return value */
		(void) OS_AdvanceCounter(cp, cd, 1, is);
		OS_IntRestore(is);
	}
	else
	{
#if (OS_KERNEL_TYPE == OS_MICROKERNEL)
		(void)MK_AsyncIncrementCounter(c);
#else
		/* no way to propagate errors -> ignore return value */
		(void)OS_SendAdvanceCounter(c, cp, 1);
#endif
	}
#endif

#if OS_KERNEL_TYPE!=OS_MICROKERNEL
	kernel_data->inFunction = save;
#endif
}

#include <memmap/Os_mm_code_end.h>

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
