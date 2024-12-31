/* CORTEXM-cat2exit.asm
 *
 * Contains funtionality to return from a category 2 interrupt
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: CORTEXM-cat2exit.s 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ASM
#define OS_ASM
#endif

#include <CORTEXM/Os_asm_CORTEXM.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <CORTEXM/Os_CORTEXM_cpu.h>
#include <Os_kernel.h>

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB

	OS_global OS_CORTEXM_IntCat2Exit

	OS_extern OS_CheckForDispatch
	OS_extern OS_Dispatch
	OS_extern OS_CORTEXM_Dispatch
	OS_extern OS_TaskSpOutOfBounds
	OS_extern OS_inKernel
	OS_extern OS_taskCurrent
	OS_extern OS_CORTEXM_IntReturnFromInterrupt
	OS_extern OS_kernel_ptr

	OS_align(4, 2)

	/* Data label: cover the following OS_ASM_LABEL declaration */
	OS_ASM_DATALABEL

	/* Address of the kernel pointer */
OS_ASM_LABEL(OS_kernelDataAddr)
	OS_word OS_kernel_ptr


/* void OS_CORTEXM_IntCat2Exit(os_uint8_t inKernel)
 *
 * Exit from a category 2 interrupt
 * This function does NOT return to the caller!
 *
 * Preconditions:
 * Interrupts are locked on kernel level
 *
 * old inKernel flag is passed as an argument
 * (aligned IF with OS_CORTEXM_IntCat1Exit()) 
 * but ignored as it might provide incorrect
 * nesting information
 */
	OS_ASM_FUNC(OS_CORTEXM_IntCat2Exit)
OS_ASM_LABEL(OS_CORTEXM_IntCat2Exit)
	/* Check magic return from exception value, if we
	 * return to a task (thread mode, psp). If so, we need
	 * to dispatch, otherwise we don't. This equals an old inKernel
	 * flag of 0 (need to dispatch) or 1 (don't dispatch).
	 *
	 * if (stack[OS_CORTEXM_POS_LR] == OS_CORTEXM_EXC_RETURN_THREAD_PSP)
	 * {
	 *'    r0 = 0;
	 * }
	 * else
	 * {
	 *     r0 = 1;
	 * }
	*/
	ldr		r12,	[sp, #OS_CORTEXM_POS_LR]
	cmn		r12,	#-OS_CORTEXM_EXC_RETURN_THREAD_PSP
	ite		EQ
	moveq	r0, #0
	movne	r0, #1

	OS_GET_KERNEL_PTR	OS_kernelDataAddr, r5, r4

	/* Keep nesting level flag ("corrected" old inKernel) */
	mov		r4, r0

	/* action = OS_CheckForDispatch(old_inKernel); */
	bl		OS_CheckForDispatch

	cmp		r0, #OS_DISP_WITHOUT_SAVE
	beq		Cat2ExitWithoutSave

	cmp		r0, #OS_DISP_WITH_SAVE
	beq		Cat2ExitWithSave

	/* OS_inKernel = old_inKernel; */
	strb	r4, [r5, #OS_T_INKERNEL]
	/* just return from interrupt */
	bl		OS_CORTEXM_IntReturnFromInterrupt

OS_ASM_LABEL(Cat2ExitWithSave)			/* dispatch with save */
	/* ret = OS_TaskSpOutOfBounds(task_sp, OS_taskCurrent); */

	/* move async context from kernel stack to task stack */
	mov		r0, sp
	mrs		r1, psp						/* get current task stack pointer */
	bl		OS_CORTEXM_Dispatch			/* call OS_CORTEXM_Dispatch(sp, task_sp) */

	/* no need to restore the stack since we dispatch. */

OS_ASM_LABEL(Cat2ExitWithoutSave)
	/* leaving kernel stack as is, will be set in OS_Dispatch */

	/* make asynchronous context switch */
	mov		r0, #OS_TS_READY_ASYNC
	bl		OS_Dispatch					/* OS_Dispatch(OS_TS_READY_ASYNC) */

	OS_ASM_END_FUNC(OS_CORTEXM_IntCat2Exit)

	OS_ASM_SRC_END

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
