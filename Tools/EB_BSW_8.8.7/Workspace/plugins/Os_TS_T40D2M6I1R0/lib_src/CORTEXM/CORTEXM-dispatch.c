/* CORTEXM-dispatch.c
 *
 * This file contains a CORTEXM-specific wrapper for OS_Dispatch which
 * performs a stack check, saves the registers and the
 * stack pointer of a task in the task dynamic data structure.
 * The caller should then call OS_Dispatch().
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: CORTEXM-dispatch.c 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 18.4 (advisory)
 * The +, -, += and -= operators should not be applied to an expression of
 * pointer type.
 *
 * Reason:
 * Pointer arithmetic is needed to calculate stack pointer values.
 *
 * MISRAC2012-2) Deviated Rule: 11.5 (advisory)
 * A conversion should not be performed from pointer to void into pointer
 * to object.
 *
 * Reason:
 * The objects reside on the stack. To perform stack calculations, the OS
 * uses os_stackelement_t. However we also need to work with the object,
 * so we need a pointer to object as well.
 *
 * MISRAC2012-3) Deviated Rule: 11.3 (advisory)
 * A cast shall not be performed between a pointer to object type
 * and a pointer to a different object type.
 *
 * Reason:
 * The tasksp is used to prerare space for the context to be saved.
 * Then, a pointer to the prepared space is passed to an assembly function,
 * where C-types don't play any role.
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <CORTEXM/Os_CORTEXM_cpu.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_CORTEXM_Dispatch
 *
 * called only from assembly. performs a stack-check, stores the context
 * from the kernel stack to the task stack and updates the stack pointer in
 * the task structure.
 *
 * @param context pointer to the source of the sync/async context
 * @param tasksp task stack pointer, where the context should be placed.
 *        This parameter should be accessed in a "decrement before" stack-like
 *        manner.
 *
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_CORTEXM_Dispatch
(
	const os_cortexm_context_t *context,
	os_cortexm_context_t *tasksp
)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	/* Deviation MISRAC2012-2 <1> */
	os_stackelement_t *checksp = (os_stackelement_t *)(void *)tasksp;
	os_task_t const * const current_task = OS_GetKernelData()->taskCurrent;
	/* Deviation MISRAC2012-1 <1> */
	checksp -= (os_int_t)(sizeof(os_cortexm_context_t) / sizeof(os_stackelement_t));

#if ((OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) && !defined(OS_EXCLUDE_HW_FP))
	if ((current_task->flags & (os_uint8_t)OS_TF_USEFPU) != 0U)
	{
		/* VFP5d16 has 16 double precision registers.
		 * Additional there is a status regsiter and alignment gap. */
		/* Deviation MISRAC2012-1 <1> */
		checksp -= 34;
	}
#else
	/* Nothing to save! */
#endif

	/* update stack pointer in dynamic task information */
	current_task->dynamic->context.sp = checksp;
	/* check, if there's room on the task stack left to save the context. */
	if (! OS_TaskSpOutOfBounds((os_address_t)checksp, current_task))
	{
		tasksp--;
		*tasksp = *context;

#if ((OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) && !defined(OS_EXCLUDE_HW_FP))
		if ((current_task->flags & (os_uint8_t)OS_TF_USEFPU) != 0U)
		{
			/* Deviation MISRAC2012-3 <1> */
			(void)OS_CORTEXM_SaveVFPFullContext((os_stackelement_t *)tasksp);
		}
#endif
	}

	#if (OS_CORTEXM_HAS_ERRATA_838869 == 1)
	/* workaround ARM Erratum 838869 (see ASCOS-5685) */
	OS_DSB();
	#endif
}


#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_CORTEXM_dispatch_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
