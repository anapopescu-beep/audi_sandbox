/* CORTEXM-getirqprio.asm
 *
 * This file contains the function OS_CORTEXM_GetIRQPrio.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: CORTEXM-getirqprio.s 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ASM
#define OS_ASM
#endif

#include <CORTEXM/Os_asm_CORTEXM.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_kernel.h>

	OS_ASM_SECTION_TEXT

/*
 * os_uint32_t OS_CORTEXM_GetIRQPrio (void)
 *
 * This function returns the value of the current interrupt priority barrier.
 * All Interrupts with lower or same priority than the priority barrier will only be pending.
 * If the priority barrier is lowered below the priority of a pending interrupt this interrupt
 * becomes active and interrupts the CPU.
 * Return value:
 * The current value of the interrupt priority barrier (BASEPRI)
 *
*/
#if (OS_TOOL_GET_IRQ_PRIO_IMPLEMENTATION == OS_TOOL_ASM_FUNC)
	OS_global OS_CORTEXM_GetIRQPrio

	OS_ASM_CODE_THUMB
	OS_align(4, 2)

	OS_ASM_FUNC(OS_CORTEXM_GetIRQPrio)
OS_ASM_LABEL(OS_CORTEXM_GetIRQPrio)
	mrs		r0, basepri
	lsr		r0, r0, #OS_CORTEXM_INT_PRIO_SHIFT
	bx		lr
	OS_ASM_END_FUNC(OS_CORTEXM_GetIRQPrio)
#endif /* (OS_TOOL_GET_IRQ_PRIO_IMPLEMENTATION == OS_TOOL_ASM_FUNC) */

	OS_ASM_SRC_END

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
