/* CORTEXM-dispatchunknowninterrupt.s
 *
 * This file contains the function to dispatch unknown interrupt.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: CORTEXM-dispatchunknowninterrupt.s 1.1 2023/04/18 07:06:17CEST Dan Dustinta (dan.dustinta) in_work  $
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
#include <CORTEXM/Os_CORTEXM_cpu.h>

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB
	OS_global DispatchUnknownInterrupt
	OS_extern OS_kernel_ptr
	OS_extern OS_CORTEXM_IntDisableUnknownInterrupt
	OS_extern OS_IntDisableConditional
	OS_extern OS_CORTEXM_UNKNOWN_INTERRUPT
	OS_extern OS_CORTEXM_IntReturnFromInterrupt

	/* The address of the OS_iSpInitial variable */
	OS_align(4, 2)

	/* Data label: cover the following OS_ASM_LABEL declarations */
	OS_ASM_DATALABEL

	/* Address of the kernel pointer */
OS_ASM_LABEL(OS_kernelDataAddr)
	OS_word OS_kernel_ptr


/* dispatcher for unknown interrupts */
	OS_ASM_FUNC(DispatchUnknownInterrupt)
OS_ASM_LABEL(DispatchUnknownInterrupt)
	/* partial context already saved by CPU on interrupted stack */

	/* disable interrupts */
	cpsid	i

	OS_LEAVE_NON_TRUSTED	r0, r1, r2
	OS_DISABLE_FPU			r0, r1, r3
	/* Save non-volatile registers */
	push	{r4-r11, lr}
	/* Save
	 * - old FPU state or gap for alignment (r3)
	 * - old MPU state (r2)
	 * - gap for old interrupt level (r1)
	*/
	push	{r1, r2, r3}

	/* OS_inKernel = 1; */
	OS_GET_KERNEL_PTR	OS_kernelDataAddr, r7, r0

	mov		r0, #1
	/* r6 = old OS_inKernel */
	ldrb	r6, [r7, #OS_T_INKERNEL]
	strb	r0, [r7, #OS_T_INKERNEL]

	/* lock interrupts on kernel level (unless higher already) */
	bl		OS_IntDisableConditional

	/* Store old lock level in r0 on gap on stack */
	str		r0, [sp]

	/* disable the unknown interrupt */
	bl		OS_CORTEXM_IntDisableUnknownInterrupt
	/* it is safe to reenable interrupts now */
	cpsie	i

	/* branch to entry routine */
	bl		OS_CORTEXM_UNKNOWN_INTERRUPT

	/* disable interrupts again to restore the context */
	cpsid	i

	/* OS_inKernel = old_inKernel; */
	strb	r6, [r7, #OS_T_INKERNEL]

	/* just return from interrupt */
	bl		OS_CORTEXM_IntReturnFromInterrupt

	OS_ASM_END_FUNC(DispatchUnknownInterrupt)

	OS_ASM_SRC_END

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
