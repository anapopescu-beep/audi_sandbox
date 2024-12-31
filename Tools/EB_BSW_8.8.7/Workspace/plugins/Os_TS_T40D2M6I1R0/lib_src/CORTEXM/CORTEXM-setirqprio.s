/* CORTEXM-setirqprio.asm
**
** This file contains the function OS_CORTEXM_SetIRQPrio.
**
** CHECK: TABS 4 (see editor commands at end of file)
**
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
**
** $Id: CORTEXM-setirqprio.s 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ASM
#define OS_ASM
#endif

#include <CORTEXM/Os_asm_CORTEXM.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_kernel.h>

	OS_ASM_SECTION_TEXT

/*
** void OS_CORTEXM_SetIRQPrio (os_reg32_t)
**
** This function sets the value of the current interrupt priority barrier.
** All Interrupts with lower or same priority then the priority barrier will only be pending.
** If the priority barrier is lowered below the priority of a pending interrupt this interrupt
** becomes active and interrupts the CPU.
**
*/
#if (OS_TOOL_SET_IRQ_PRIO_IMPLEMENTATION == OS_TOOL_ASM_FUNC)
	OS_global OS_CORTEXM_SetIRQPrio

	OS_ASM_CODE_THUMB
	OS_align(4, 2)

	OS_ASM_FUNC(OS_CORTEXM_SetIRQPrio)
OS_ASM_LABEL(OS_CORTEXM_SetIRQPrio)
	lsl		r0, r0, #OS_CORTEXM_INT_PRIO_SHIFT
	msr		basepri, r0
	bx		lr
	OS_ASM_END_FUNC(OS_CORTEXM_SetIRQPrio)
#endif /* (OS_TOOL_SET_IRQ_PRIO_IMPLEMENTATION == OS_TOOL_ASM_FUNC) */

	OS_ASM_SRC_END

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
** vi:set ts=4:
*/
