/* CORTEXM-disableirqgetstate.asm
 *
 * This file contains the function OS_CORTEXM_DisableIRQGetState.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: CORTEXM-disableirqgetstate.s 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ASM
#define OS_ASM
#endif

#include <CORTEXM/Os_asm_CORTEXM.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_kernel.h>

	OS_ASM_SECTION_TEXT

/*
 * os_reg32_t OS_CORTEXM_DisableIRQGetState (void)
 *
 * This function disables the IRQ interrupts.
 * Return value:
 * The previous value of the CPU state register (e.g. CPSR, PRIMASK etc.)
 *
 */
#if (OS_TOOL_DISABLE_IRQ_GET_STATE_IMPLEMENTATION == OS_TOOL_ASM_FUNC)
	OS_global OS_CORTEXM_DisableIRQGetState
	OS_ASM_CODE_THUMB
	OS_align(4, 2)

	OS_ASM_FUNC(OS_CORTEXM_DisableIRQGetState)
OS_ASM_LABEL(OS_CORTEXM_DisableIRQGetState)
	mrs		r0, primask
	cpsid	i
	bx		lr
	OS_ASM_END_FUNC(OS_CORTEXM_DisableIRQGetState)
#endif /* (OS_TOOL_DISABLE_IRQ_GET_STATE_IMPLEMENTATION == OS_TOOL_ASM_FUNC) */

	OS_ASM_SRC_END

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
 */
