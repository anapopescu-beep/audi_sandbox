/* CORTEXM-savefpcontextanddispatch.asm
 *
 * This file contains the function for saving the task context with FPU support
 * of a synchronously interrupted task and then calling the dispatcher.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: CORTEXM-savefpcontextanddispatch.s 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ASM
#define OS_ASM
#endif

#include <CORTEXM/Os_asm_CORTEXM.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_kernel.h>

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB
	OS_global OS_CORTEXM_SaveFPContextAndDispatch

/*
 * void OS_CORTEXM_SaveFPContextAndDispatch( os_uint32_t state, os_stackelement_t ** sp)
 *
 * Saves the context of a task with floating point support.
 *
 * When this function is called, the interrupts are locked on kernel level.
 *
 * Parameters:
 * state	The task state, not used directly but passed to OS_Dispatch
 * sp		The adresss of a variable in which the stackpointer shall be saved
 *
 */
	OS_ASM_FUNC(OS_CORTEXM_SaveFPContextAndDispatch)
OS_ASM_LABEL(OS_CORTEXM_SaveFPContextAndDispatch)
	/* Only needed for a function call kernel, which is currently not supported for Cortex-M */
OS_ASM_LABEL(loop)
	b		loop
	OS_ASM_END_FUNC(OS_CORTEXM_SaveFPContextAndDispatch)

	OS_ASM_SRC_END

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
