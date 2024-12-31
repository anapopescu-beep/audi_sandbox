/* CORTEXM-starttask.asm
 *
 * This file contains the function for starting a task
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: CORTEXM-starttask.s 1.1 2023/04/18 07:06:17CEST Dan Dustinta (dan.dustinta) in_work  $
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
	OS_global OS_CORTEXM_StartTask
	OS_extern OS_kernel_ptr

	/* The address of the OS_iSpInitial variable */
	OS_align(4, 2)

	OS_GENLIT_ACTIVATE_SVC

	/* Data label: cover the following OS_ASM_LABEL declarations */
	OS_ASM_DATALABEL

	/* Address of the kernel pointer */
OS_ASM_LABEL(OS_kernelDataAddr)
	OS_word OS_kernel_ptr


OS_ASM_LABEL(OS_CORTEXM_EPSR_T_Value)
	OS_word OS_CORTEXM_EPSR_T

OS_ASM_LABEL(OS_CORTEXM_EXC_RETURN_Value)
	OS_word OS_CORTEXM_EXC_RETURN_THREAD_PSP

/*
 * extern void OS_CORTEXM_StartTask (	os_entry_t entry,
 *									os_stackelement_t * sp,
 *									os_uint8_t flags,
 *									os_entry_t utr)
 *
 * Starts a new task.
 *
 * Parameters:
 * entry	The entry address of the task (r0)
 * sp		The stack pointer of the task (r1)
 * flags	Flags of the Os application ([7:0]), e.g. trusted or non-trusted,
 *			and flags of the task ([15:8]), e.g. use FP or don't use FP (r2)
 * utr		Address of the task's return function (r3)
 *
*/
	OS_ASM_FUNC(OS_CORTEXM_StartTask)
OS_ASM_LABEL(OS_CORTEXM_StartTask)

	cpsid	f								/* disable all interrupts */

	mov		sp, r1	/* switch to task stack */

	/* prepare task context for return from exception */
	ldr		r7, OS_CORTEXM_EPSR_T_Value				/* prepare xPSR (must be thumb mode) */
	mov		r6, r0								/* prepare return address (task function) */
	mov		r5, r3								/* prepare lr (user task return) */
	/* r0-r3,r12 are volatile and need no preparation */
	push	{r0-r7}

	mov		r0, sp
	msr		psp, r0	/* set task stack to prepared task context (task stack == psp) */

	/* reset kernel stack pointer because we are leaving handler mode */
	OS_GET_KERNEL_PTR	OS_kernelDataAddr, r0, r1
	ldr		sp, [r0, #OS_T_ISPINITIAL]

	mov		r0, #OS_CORTEXM_ALL_INT_ENABLED_LEVEL
	OS_SETLEVEL	r0, r1

	tst		r2, #OS_TF_USEFPU
	beq		OS_SkipEnableFpu

	OS_ENABLE_FPU	r0, r1, r1
OS_ASM_LABEL(OS_SkipEnableFpu)

	lsr		r2, r2, #8
	tst		r2, #OS_APP_TRUSTED
	bne		OS_SkipEnableMpu

	/* Non-Trusted -> Enable the MPU */
	OS_ENTER_NON_TRUSTED	r0, r1
OS_ASM_LABEL(OS_SkipEnableMpu)

	/* If from system call, re-enable the SVC active flag. */
	mrs		r0, ipsr
	cmp		r0, #OS_IPSR_SVC
	bne		OS_SkipActivateSVC
	OS_ACTIVATE_SVC	r0, r1

OS_ASM_LABEL(OS_SkipActivateSVC)
#if (OS_TOOL != OS_armkeil)

#if (OS_CORTEXM_HAS_ERRATA_838869 == 1)
	/* workaround ARM Erratum 838869 (see ASCOS-5685) on all Cortex-M4/M4F */
	dsb
#endif

	ldr		pc, OS_CORTEXM_EXC_RETURN_Value			/* start task by return from exception */
#else
	/* ARMKEIL 6.5 falsely cannot assemble ldr pc,=expression.
	 * Seems to be already fixed in LLVM, but not yet for the derived ARMKEIL toolchain.
	*/
	ldr		r0, OS_CORTEXM_EXC_RETURN_Value

#if (OS_CORTEXM_HAS_ERRATA_838869 == 1)
	/* workaround ARM Erratum 838869 (see ASCOS-5685) on all Cortex-M4/M4F */
	dsb
#endif

	bx		r0										/* start task by return from exception */
#endif

	OS_ASM_END_FUNC(OS_CORTEXM_StartTask)

	OS_ASM_SRC_END

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */
/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
