/* CORTEXM-returnfrominterrupt.asm
 *
 * Functionality to return from an interrupt or exception without dispatch.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: CORTEXM-returnfrominterrupt.s 1.1 2023/04/18 07:06:17CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ASM
#define OS_ASM
#endif

#include <Os_asm_common.h>
#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_configuration.h>
#include <CORTEXM/Os_asm_CORTEXM.h>
#include <CORTEXM/Os_asm_CORTEXM_cfg.h>
#include <CORTEXM/Os_CORTEXM_int.h>
#include <CORTEXM/Os_CORTEXM_cpu.h>

/* void OS_CORTEXM_IntReturnFromInterrupt()
 *
 * Returns from an interrupt and restores the previous context.
 *
 * Preconditions:
 * Interrupts are locked on ISR level for category 1 ISRs
 * Interrupts are locked on kernel level for category 2 ISRs
*/
	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB
	OS_align(4, 2)
	OS_global OS_CORTEXM_IntReturnFromInterrupt

	OS_ASM_FUNC(OS_CORTEXM_IntReturnFromInterrupt)
OS_ASM_LABEL(OS_CORTEXM_IntReturnFromInterrupt)
	clrex								/* clear exclusive monitor */
	/* disable up to hardfault level, it gets enabled again on return-from-exception */
	/* Note: This avoids interrupts between enabling interrupts and
	 * the return-from-exception.
	*/
	cpsid	f							/* disable all interrupts */

	/* Load
	 * - old interrupt lock level (r0)
	 * - old MPU state (r1)
	 * - old FPU state or gap for alignment (r3)
	*/
	pop		{ r0, r1, r3 }
	/* Set old level */
	OS_SETLEVEL	r0, r2

#if ((OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) && !defined(OS_EXCLUDE_HW_FP))
	tst		r3, #0x00f00000
	beq		OS_ReturnFromInterrupt_SkipEnableFpu

	OS_ENABLE_FPU	r0, r3, r3
OS_ASM_LABEL(OS_ReturnFromInterrupt_SkipEnableFpu)
#endif

	/* Set old MPU state */
	OS_RESTORE_NON_TRUSTED	r0, r2, r1

	/* restore software saved context (r4-r11,lr) */
	pop		{r4-r11,lr}

	/* enable all interrupts (return from exception does not enable interrupts) */
	cpsie	i

#if (OS_CORTEXM_HAS_ERRATA_838869 == 1)
	/* workaround ARM Erratum 838869 (see ASCOS-5685) on all Cortex-M4/M4F */
	dsb
#endif

	/* return from exception (pc=EXC_RETURN) */
	bx		lr

	OS_ASM_END_FUNC(OS_CORTEXM_IntReturnFromInterrupt)

	OS_ASM_SRC_END

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
