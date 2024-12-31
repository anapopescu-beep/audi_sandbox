/* CORTEXM-helpers.asm
 *
 * This file contains helper functions
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: CORTEXM-helpers.s 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ASM
#define OS_ASM
#endif

#include <CORTEXM/Os_asm_CORTEXM.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_kernel.h>

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB
	OS_global OS_CORTEXM_SetControl
	OS_global OS_CORTEXM_GetControl

	OS_align(4, 2)

/*
 * os_stackelement_t * OS_CORTEXM_GetSP(void)
 *
 * Get the current stack pointer
 */
#if (OS_TOOL_GETSP_IMPLEMENTATION == OS_TOOL_ASM_FUNC)
	OS_global OS_CORTEXM_GetSP
	OS_ASM_FUNC(OS_CORTEXM_GetSP)
OS_ASM_LABEL(OS_CORTEXM_GetSP)
	mov		r0, sp
	bx		lr
	OS_ASM_END_FUNC(OS_CORTEXM_GetSP)
#endif /* (OS_TOOL_GETSP_IMPLEMENTATION == OS_TOOL_ASM_FUNC) */


/*
 * void OS_CORTEXM_SetControl(os_uint32_t control)
 *
 * Set the CONTROL register to control.
*/
	OS_ASM_FUNC(OS_CORTEXM_SetControl)
OS_ASM_LABEL(OS_CORTEXM_SetControl)
	msr		control, r0
	bx		lr
	OS_ASM_END_FUNC(OS_CORTEXM_SetControl)


/*
 * os_uint32_t OS_CORTEXM_GetControl(void)
 *
 * Get the CONTROL register contents.
*/
	OS_ASM_FUNC(OS_CORTEXM_GetControl)
OS_ASM_LABEL(OS_CORTEXM_GetControl)
	mrs		r0,control
	bx		lr
	OS_ASM_END_FUNC(OS_CORTEXM_GetControl)


	OS_ASM_SRC_END

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
 */
