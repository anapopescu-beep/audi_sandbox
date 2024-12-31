/* CORTEXM-atomicxor.s
 *
 * This file contains the function OS_AtomicFetchXor().
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: CORTEXM-atomicxor.s 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#include <CORTEXM/Os_asm_CORTEXM.h>		/* Must be first! */
#include <Os_kernel.h>

	OS_file(CORTEXM-atomicxor.s)

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB

	OS_global OS_AtomicFetchXor

	OS_align(4, 2)

	/* os_atomic_value_t OS_AtomicFetchXor(os_atomic_t volatile *object,
	 *   os_atomic_value_t operand)
	 *
	 * !LINKSTO Kernel.Atomics.BoolOps, 1
	 */
	OS_ASM_FUNC(OS_AtomicFetchXor)
OS_ASM_LABEL(OS_AtomicFetchXor)
	dsb						/* ensure sequential consistency */
OS_ASM_LABEL(_retry)
	ldrex r2, [r0]			/* r2 = *object */
	eor r2, r2, r1			/* r2 ^= operand */
	strex r3, r2, [r0]		/* *object ^= operand, r3 = success_indicator */
	cmp r3, #0				/* was store successful? */
	bne _retry				/* retry operation if store failed */
	eor r0, r2, r1			/* return previous value */
	dsb						/* ensure sequential consistency */
	bx lr
	OS_ASM_END_FUNC(OS_AtomicFetchXor)

	OS_ASM_SRC_END

/* Editor settings: DO NOT DELETE
 * vi:set ts=4:
*/
