/* CORTEXM-killcalledcontext.asm
 *
 * This file contains the function for killing the context of an ISR or hook.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: CORTEXM-killcalledcontext.s 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ASM
#define OS_ASM
#endif

#include <CORTEXM/Os_asm_CORTEXM.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_kernel.h>
#include <Os_error.h>
#include <CORTEXM/Os_CORTEXM_int.h>
#include <CORTEXM/Os_CORTEXM_cpu.h>

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB
	OS_global OS_KillCalledContext
	OS_align(4, 2)

	OS_GENLIT_ACTIVATE_SVC

/* Data label: cover the following OS_ASM_LABEL declarations */
	OS_ASM_DATALABEL

OS_ASM_LABEL(OS_CORTEXM_EXC_RETURN_Value)
	OS_word OS_CORTEXM_EXC_RETURN_HANDLER_MSP

OS_ASM_LABEL(OS_KILLDONE_ADDR)
	OS_word OS_KillDone

/*
 * os_result_t OS_KillCalledContext(os_savedcontext_t * sp)
 *
 * This routine load the stored context and branches
 * to the "original" caller.
 *
 * Parameters:
 * sp		pointer to the stack where the context is saved
 *
 * Trapping kernel:
 * OS_KillCalledContext can be called by a system call
 * from OS_UserReturnFromCall or from an exception. Additionally, it
 * is called by the CatK interrupt for timing protection violations.
*/
	OS_ASM_FUNC(OS_KillCalledContext)
OS_ASM_LABEL(OS_KillCalledContext)

	cpsid	i						/* Disable all interrupts. */

	/* Restore stack pointer */
	ldr		r0, [r0, #OS_CTXT_SP]
	cmp		r0, #0
	beq		OS_noStack
	mov		sp, r0

	/* Check, if we came from an exception, interrupt or system call.
	 * If from system call, activate SVC in SHCSR.
	 *
	 * If called from a CatK interrupt, we just acknowledge the CatK interrupt.
	 * The interrupt to kill will get acknowledged from any other function that
	 * leaves the kernel.
	*/
	mrs		r1, ipsr
	cmp		r1, #OS_IPSR_SVC
	bne		OS_ReturnFromException

	/* Activate SVC in SHCSR again, since the system call handler
	 * disabled this flag.
	*/
	OS_ACTIVATE_SVC	r2, r3

OS_ASM_LABEL(OS_ReturnFromException)
	/* Restore context and perform a return from exception. */
	/* r1 = old xPSR, r2 = dummy, r3 = old interrupt level, old r4-r11,lr */
	pop		{r1, r2, r3, r4-r11, lr}

	/* Prepare basic frame for return from exception: */
	/* Return address and old xPSR */
	ldr		r0, OS_KILLDONE_ADDR
	push	{r0, r1}

	/* r0, r1, r2, r3, r12 and lr:
	 * r0-r3, r12 are volatile, so we use arbitrary values.
	*/
	push	{r0-r4, lr}

	/* Restore old disabling level. */
	lsl		r3, r3, #OS_CORTEXM_INT_PRIO_SHIFT
	msr		basepri, r3

	/* Perform return from exception. Destinaion is just below. */
	ldr		lr, OS_CORTEXM_EXC_RETURN_Value

	#if (OS_CORTEXM_HAS_ERRATA_838869 == 1)
	/* workaround ARM Erratum 838869 (see ASCOS-5685) on all Cortex-M4/M4F */
	dsb
	#endif

	bx		lr

OS_ASM_LABEL(OS_KillDone)
	/* Re-enable interrupts, return */
	cpsie	i
	bx		lr

OS_ASM_LABEL(OS_noStack)
	/* If the stack pointer is a null pointer, we cannot
	 * restore the context. Instead we return an error.
	 * The OS will shut down as a result.
	*/
	mov		r0, #OS_E_INTERNAL
	bx		lr

	OS_ASM_END_FUNC(OS_KillCalledContext)

	OS_ASM_SRC_END

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
