/* CORTEXM-idle.asm
 *
 * This file contains an architecure specific implementation of the OS idle function.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: CORTEXM-idle.s 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ASM
#define OS_ASM
#endif

#include <CORTEXM/Os_asm_CORTEXM.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_types.h>
#include <Os_kernel.h>
#include <Os_defs.h>

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB
	OS_global OS_CORTEXM_Idle
	OS_extern OS_idleStack
	OS_extern OS_kernel_ptr
	OS_align(4, 2)

	/* Data label: cover the following OS_ASM_LABEL declarations */
	OS_ASM_DATALABEL

OS_ASM_LABEL(OS_CORTEXM_EPSR_T_Value)
	OS_word OS_CORTEXM_EPSR_T

OS_ASM_LABEL(OS_CORTEXM_EXC_RETURN_Value)
	OS_word OS_CORTEXM_EXC_RETURN_THREAD_PSP

OS_ASM_LABEL(OS_idleStackAddr)
	OS_word OS_idleStack

	/* Address of the kernel pointer */
OS_ASM_LABEL(OS_kernelDataAddr)
	OS_word OS_kernel_ptr

	OS_GENLIT_ACTIVATE_SVC


OS_ASM_LABEL(IdleLoopHaltAddr)
	OS_word IdleLoopHalt

OS_ASM_LABEL(IdleLoopNoHaltAddr)
	OS_word IdleLoopNoHalt


/*
 * void OS_CORTEXM_Idle()
 *
 * This function is the CORTEXM specific implementation of the OS idle function.
 * Instead of just calling the idle function an exception stack frame is prepared and the idle loop
 * is "called" by returning from the underlying exception (either SVC or external interrupt).
 *
*/
	OS_ASM_FUNC(OS_CORTEXM_Idle)
OS_ASM_LABEL(OS_CORTEXM_Idle)
	cpsid	i							/* disable all interrupts */

	/* R5 = kernel pointer */
	OS_GET_KERNEL_PTR	OS_kernelDataAddr, r5, r7

	/* OS_inKernel = 0; */
	mov		r7, #0x0
	strb	r7, [r5, #OS_T_INKERNEL]

	/* use separate stack for idle loop (reusing reset stack) */
	ldr		sp, OS_idleStackAddr
	add		sp, sp, #(OS_IDLESTACK_SIZE * 4)

	/* prepare idle context for return from exception (r0-r3,r12,lr,return_address,xPSR) */
	ldr		r7, OS_CORTEXM_EPSR_T_Value				/* prepare xPSR (must be thumb mode) */

	ldrb	r6, [r5, #OS_T_IDLEMODE]				/* get the idle mode */
	cmp		r6, #OS_IDLE_WFI
	beq		OS_LoadIdleHaltAddr
	ldr		r6, IdleLoopNoHaltAddr					/* prepare exception return address (idle loop) */
	b		OS_PushIdleContext
OS_ASM_LABEL(OS_LoadIdleHaltAddr)
	ldr		r6, IdleLoopHaltAddr					/* prepare exception return address (idle loop with wfi) */

OS_ASM_LABEL(OS_PushIdleContext)
	/* lr needs no preparation, because idle loop does not return */
	/* r0-r3,r12 are volatile and need no preparation */
	push	{r0-r7}

	/* store stack pointer to saved idle context */
	mov		r0, sp
	msr		psp, r0

	/* reset kernel stack pointer because we are leaving handler mode */
	ldr		sp, [r5, #OS_T_ISPINITIAL]

	mov		r0, #OS_CORTEXM_ALL_INT_ENABLED_LEVEL
	OS_SETLEVEL	r0, r1

	/* disable up to hardfault level, it gets enabled again on return-from-exception */
	/* Note: This avoids interrupts between enabling interrupts and the return-from-exception. */
	cpsid	f
	/* enable all interrupts (return from exception does not enable interrupts) */
	cpsie	i

	/* If from system call, re-enable the SVC active flag. */
	mrs		r0, ipsr
	cmp		r0, #OS_IPSR_SVC
	bne		OS_SkipActivateSVC
	OS_ACTIVATE_SVC	r0, r1

OS_ASM_LABEL(OS_SkipActivateSVC)

#if (OS_CORTEXM_HAS_ERRATA_838869 == 1)
	/* workaround ARM Erratum 838869 (see ASCOS-5685) on all Cortex-M4/M4F */
	dsb
#endif

#if (OS_TOOL != OS_armkeil)
	ldr		pc, OS_CORTEXM_EXC_RETURN_Value			/* call idle loop by return from exception */
#else
	/* ARMKEIL 6.5 falsely cannot assemble ldr pc,=expression.
	 * Seems to be already fixed in LLVM, but not yet for the derived ARMKEIL toolchain.
	*/
	ldr		r0, OS_CORTEXM_EXC_RETURN_Value
	bx		r0										/* call idle loop by return from exception */
#endif

OS_ASM_LABEL(IdleLoopHalt)
	wfi
	b		IdleLoopHalt

OS_ASM_LABEL(IdleLoopNoHalt)
	b		IdleLoopNoHalt
	OS_ASM_END_FUNC(OS_CORTEXM_Idle)

	OS_ASM_SRC_END

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
