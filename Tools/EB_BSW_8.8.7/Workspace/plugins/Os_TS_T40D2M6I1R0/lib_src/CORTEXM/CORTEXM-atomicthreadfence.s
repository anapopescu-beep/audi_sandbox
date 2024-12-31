/* CORTEXM-atomicthreadfence.s
 *
 * This file contains the function OS_AtomicThreadFence()
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: CORTEXM-atomicthreadfence.s 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#include <CORTEXM/Os_asm_CORTEXM.h>		/* Must be first! */
#include <Os_kernel.h>

	OS_file(CORTEXM-atomicthreadfence.s)

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB

	OS_global OS_AtomicThreadFence

	OS_align(4, 2)

/* !LINKSTO Kernel.Atomics.Fence, 1
 */ 
	OS_ASM_FUNC(OS_AtomicThreadFence)
OS_ASM_LABEL(OS_AtomicThreadFence)
	dsb
	bx		lr
	OS_ASM_END_FUNC(OS_AtomicThreadFence)

	OS_ASM_SRC_END

/* Editor settings: DO NOT DELETE
 * vi:set ts=4:
*/
