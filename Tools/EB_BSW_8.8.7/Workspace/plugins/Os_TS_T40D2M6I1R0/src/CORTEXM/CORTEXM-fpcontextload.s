/* CORTEXM-fpcontextload.asm
 *
 * This file contains the function for restoring the
 * asynchronous context of a task with FPU support
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: CORTEXM-fpcontextload.s 1.1 2023/04/18 07:06:17CEST Dan Dustinta (dan.dustinta) in_work  $
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
	OS_global OS_CORTEXM_FPContextLoad

	OS_extern OS_kernel_ptr

	/*  The address of the OS_iSpInitial variable */
	OS_align(4, 2)

	OS_GENLIT_ACTIVATE_SVC

	/* Data label: cover the following OS_ASM_LABEL declaration */
	OS_ASM_DATALABEL

	/* Address of the kernel pointer */
OS_ASM_LABEL(OS_kernelDataAddr)
	OS_word OS_kernel_ptr

/*
 * void OS_CORTEXM_FPContextLoad ( os_stackelement_t * sp )
 *
 * This routine restores the context of a
 * preempted task which supports floating point. The argument is the stackpointer of
 * task. It also enables the interrupts in the
 * interrupt controller.
*/
	OS_ASM_FUNC(OS_CORTEXM_FPContextLoad)
OS_ASM_LABEL(OS_CORTEXM_FPContextLoad)
	/*  clear exclusive monitor */
	clrex

	/* disable all interrupts */
	cpsid	f

	/* set stack pointer to task stack to restore non-volatile context */
	mov		sp, r0

	OS_ENABLE_FPU	r0, r1, r1
	dsb
	isb
	/* Restore FPU context. */
	vldmia.64	sp!,{d0-d15}			/* load floating point registers from stack */
	ldmia		sp!, { r0, r1 }
	vmsr		fpscr, r0				/* restore floating point status register */

	/* Load
	 * - old interrupt lock level (r0)
	 * - old MPU state (r1)
	 * - gap (r2)
	*/
	pop		{ r0, r1, r2 }
	OS_SETLEVEL	r0, r2

	/* get kernel stack pointer here because it might not be accessible on some derivatives afterwards */
	OS_GET_KERNEL_PTR	OS_kernelDataAddr, r0, r3
	ldr		r3, [r0, #OS_T_ISPINITIAL]

	OS_RESTORE_NON_TRUSTED	r0, r2, r1

	/* restore non-volatile context */
	pop		{r4-r11,lr}

	/* If from system call, re-enable the SVC active flag. */
	mrs		r0, ipsr
	cmp		r0, #OS_IPSR_SVC
	bne		OS_SkipActivateSVC
	OS_ACTIVATE_SVC	r0, r1

OS_ASM_LABEL(OS_SkipActivateSVC)
	/* adjust task stack pointer for automatic context restore on return from exception */
	mov		r0,	sp
	msr		psp, r0

	/* reset kernel stack pointer because we are leaving handler mode */
	mov		sp, r3

#if (OS_CORTEXM_HAS_ERRATA_838869 == 1)
	/* workaround ARM Erratum 838869 (see ASCOS-5685) on all Cortex-M4/M4F */
	dsb
#endif

	/* return from exception (pc=EXC_RETURN) */
	bx		lr
	/* Note: return from exception AUTOMATICALLY restores (xPSR,..,r0) from the process stack */
	OS_ASM_END_FUNC(OS_CORTEXM_FPContextLoad)

	OS_ASM_SRC_END

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
