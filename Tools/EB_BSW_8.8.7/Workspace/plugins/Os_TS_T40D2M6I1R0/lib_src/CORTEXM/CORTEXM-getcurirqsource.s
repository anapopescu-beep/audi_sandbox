/* CORTEXM-getcurirqsource.asm
**
** This file contains the function OS_CORTEXM_GetCurIRQSource.
**
** CHECK: TABS 4 (see editor commands at end of file)
**
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
**
** $Id: CORTEXM-getcurirqsource.s 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ASM
#define OS_ASM
#endif

#include <CORTEXM/Os_asm_CORTEXM.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_kernel.h>

	OS_ASM_SECTION_TEXT

/*
** os_reg32_t OS_CORTEXM_GetCurIRQSource (void)
**
** This function returns the interrupt source of the currently active interrupt.
** Return value:
** The interrupt source of the currently active interrupt (e.g. IPSR, etc.).
** A positive value or zero signals an interrupt.
** A negative value signals an exception.
**
*/
#if (OS_TOOL_GET_CUR_IRQ_SOURCE_IMPLEMENTATION == OS_TOOL_ASM_FUNC)
	OS_global OS_CORTEXM_GetCurIRQSource

	OS_ASM_CODE_THUMB
	OS_align(4, 2)

	OS_ASM_FUNC(OS_CORTEXM_GetCurIRQSource)
OS_ASM_LABEL(OS_CORTEXM_GetCurIRQSource)
	mrs		r0, ipsr	/* get active exception/interrupt source */
	sub		r0, r0, #16	/* interrupts start at 16 (1-15 are exceptions) */
	bx		lr
	OS_ASM_END_FUNC(OS_CORTEXM_GetCurIRQSource)
#endif /* (OS_TOOL_GET_CUR_IRQ_SOURCE_IMPLEMENTATION == OS_TOOL_ASM_FUNC) */

	OS_ASM_SRC_END

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
** vi:set ts=4:
*/
