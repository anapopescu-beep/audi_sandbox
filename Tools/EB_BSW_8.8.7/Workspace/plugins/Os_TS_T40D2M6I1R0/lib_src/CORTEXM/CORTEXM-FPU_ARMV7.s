/* CORTEXM-FPU_ARMV7.s
 *
 * This file contains functions related to the floating point
 * unit VFPv5-D16 and FPv4-SP.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: CORTEXM-FPU_ARMV7.s 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef	OS_ASM
#define	OS_ASM
#endif

#include <CORTEXM/Os_asm_CORTEXM.h>
#include <CORTEXM/Os_asm_CORTEXM_cfg.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <CORTEXM/Os_CORTEXM_core.h>

/* FPCCR bit ASPEN: If 1, the CPU sets CONTROL.FPCA to 1 after
 * a FPU instruction was executed.
*/
#define OS_FPCCR_ASPEN		(1 << 31)
/* FPCCR bit LSPEN: If 1, the CPU enables lazy FPU context saving.
*/
#define OS_FPCCR_LSPEN		(1 << 30)

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB
	OS_global OS_CORTEXM_SaveVFPFullContext
	OS_global OS_CORTEXM_SetupVFPCoprocessor

	OS_align(4, 2)

	/* Data label: cover the following OS_ASM_LABEL declarations */
	OS_ASM_DATALABEL

/* Address of FPCCR */
OS_ASM_LABEL(OS_FPCCR_addr)
	OS_word 0xE000EF34

/* Address of CPACR */
OS_ASM_LABEL(OS_CPACR_addr)
	OS_word 0xE000ED88

/*
 * void OS_CORTEXM_SetupVFPCoprocessor(void)
 *
 * This routine setups the coprocessor for the FPU.
 * It enables the FPU in the control register and programs
 * the FPCCR to not save any floating point context.
 * Afterwards it disables access to the FPU,
 * since it should only be allowed for floting-point tasks.
 */
	OS_ASM_FUNC(OS_CORTEXM_SetupVFPCoprocessor)
OS_ASM_LABEL(OS_CORTEXM_SetupVFPCoprocessor)
	/* Disable automatic save of FPU context in CONTROL. */
	mrs		r0, control
	bic		r0, r0, #OS_CORTEXM_CONTROL_FPCA
	msr		control, r0
	isb								/* Make change to CONTROL visible. */

	/* Enable VFP coprocessor in CPACR */

	ldr		r1, OS_CPACR_addr
	ldr		r0, [r1]
	orr		r0, r0, #0xf00000		/*  Mask cp10, cp11 to o11 */
	str		r0, [r1]

	/* Disable automatic saving of FP context in FPCCR, as the OS does this
	 * manually.
	*/
	ldr		r1, OS_FPCCR_addr
	ldr		r0, [r1]
	bic		r0, r0, #(OS_FPCCR_LSPEN | OS_FPCCR_ASPEN)
	str		r0, [r1]

	/* Disable VFP coprocessor in CPACR */
	ldr		r1, OS_CPACR_addr
	ldr		r0, [r1]
	movw	r2, #0xffff
	movt	r2, #0xff0f
	and		r0, r0, r2		/*  Mask cp10, cp11 to o00 */
	str		r0, [r1]

	bx		lr						/*  return */
	OS_ASM_END_FUNC(OS_CORTEXM_SetupVFPCoprocessor)

/*
 * os_stackelement_t * OS_CORTEXM_SaveVFPFullContext(os_stackelement_t * sp)
 *
 * This routine saves the registers on the argument given and returns the
 * new value to the caller. Since the stack is temporarily set to the
 * argument a interruption of this routine shall not happen.
 *
 * Parameters:
 * sp	The stack pointer which points to the stack where the context shall be saved (r0)
 * Return value:
 * the new stack pointer
 */
	OS_ASM_FUNC(OS_CORTEXM_SaveVFPFullContext)
OS_ASM_LABEL(OS_CORTEXM_SaveVFPFullContext)
	/* Enable VFP coprocessor in CPACR */
	OS_ENABLE_FPU r1, r2, r3
	dsb
	isb
	/*  push FPSCR on stack, add alignment gap */
	vmrs		r2, fpscr
	stmdb		r0!, { r2, r3 }
	vstmdb.64	r0!, {d0-d15}			/*  push s0 .. s31 */
	/* After OS_ENABLE_FPU, r1 holds CPACR addr and r3 oldval */
	str		r3, [r1]

	bx		lr						/*  return */
	OS_ASM_END_FUNC(OS_CORTEXM_SaveVFPFullContext)

	OS_ASM_SRC_END
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
