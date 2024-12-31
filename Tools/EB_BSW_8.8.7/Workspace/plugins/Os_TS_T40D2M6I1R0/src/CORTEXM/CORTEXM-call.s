/* CORTEXM-callapphook.asm
 *
 * This file contains the function for calling an application hook or an ISR
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: CORTEXM-call.s 1.1 2023/04/18 07:06:17CEST Dan Dustinta (dan.dustinta) in_work  $
 */

#ifndef OS_ASM
#define OS_ASM
#endif

#include <Os_asm_common.h>
#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_configuration.h>
#include <CORTEXM/Os_asm_CORTEXM.h>
#include <CORTEXM/Os_asm_CORTEXM_cfg.h>
#include <Os_kernel.h>
#include <Os_error.h>
#include <CORTEXM/Os_CORTEXM_int.h>

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB
	OS_global OS_CORTEXM_Call

	OS_extern OS_UserReturnFromCall
	OS_align(4, 2)

	/* Data label: cover the following OS_ASM_LABEL declarations */
	OS_ASM_DATALABEL

OS_ASM_LABEL(OS_ReturnFromCallAddr)
	OS_word	OS_UserReturnFromCall

/*
 * OS_CORTEXM_Call		(	os_intstatus_t level,
 *						os_vfuncu_t function,
 *						os_stackelement_t **savedsp,
 *						os_stackelement_t *sp,
 *						os_uint8_t flags,
 *						os_result_t argument)
 *
 * This routine calls the given hook or ISR, but saves the
 * context before. If the hook or the ISR cause a protection fault,
 * the system can return to the saved context.
 *
 * Parameters:
 * level			interrupt disabling level to set (r0).
 * function			hook service or ISR to be called (r1)
 * savedsp			A pointer to a variable where the kernel stack pointer shall be
 *					saved from which the context can be restored (r2)
 * sp				The stack pointer of the hook or ISR (r3)
 * flags			The flags of the OS application (stack)
 * argument			argument of the hook function (stack)
 */
	OS_ASM_FUNC(OS_CORTEXM_Call)
OS_ASM_LABEL(OS_CORTEXM_Call)

	cpsid	f					/* disable all interrupts */

	OS_SETLEVEL	r0, r12
	mov		r0, r12
	mov		r12, sp				/* r12 = frame pointer */

	push	{r0,r4-r11,lr}		/* save level, r4-r11, return address on kernel stack */
	mrs		r5, OS_ASM_XPSR
	/* EPSR portion always reads as zero. However, since we know that
	 * we have interrupts disabled, and we want to return to assembly
	 * (cf. CORTEXM-killcalledcontext) without conditional execution,
	 * we just need to set the THUMB bit and must leave the other bits
	 * from EPSR set to 0.
	*/
	orr		r5, r5, #OS_CORTEXM_EPSR_T
	push	{r5, r6}			/* Save old xPSR and a dummy (to keep alignment) on
								 * kernel stack.
								*/

	str		sp, [r2]			/* save stack pointer of kernel stack */
								/* this is required to later restore the context */

	/* If OS_NULL is passed as desired stack pointer, we remain on the
	 * kernel stack as is. Otherwise, we set the stack pointer to the hook
	 * or ISR stack (which may be an aligned portion of the kernel stack).
	*/
	cmp		r3, #0
	it		NE
	movne	sp, r3

	/* system call */
	ldr		lr, OS_ReturnFromCallAddr	/* set link register, return to special return function */
	ldr		r0, [r12, #4]				/* prepare argument for function */

	/* Check if non-trusted */
	ldr		r6, [r12, #0]
	tst		r6, #OS_APP_TRUSTED
	bne		OS_CallFunc

	/* Non-trusted -> enable MPU. */
	OS_ENTER_NON_TRUSTED	r2, r3

OS_ASM_LABEL(OS_CallFunc)
	cpsie	f
	bx		r1							/* simply call ISR or hook function */

	OS_ASM_END_FUNC(OS_CORTEXM_Call)

	OS_ASM_SRC_END

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
