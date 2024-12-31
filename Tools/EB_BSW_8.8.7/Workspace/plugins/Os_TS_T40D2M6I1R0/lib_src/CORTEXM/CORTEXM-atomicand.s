/* CORTEXM-atomicand.s
 *
 * This file contains the function OS_AtomicFetchAnd().
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: CORTEXM-atomicand.s 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#include <CORTEXM/Os_asm_CORTEXM.h>		/* Must be first! */
#include <Os_kernel.h>

	OS_file(CORTEXM-atomicand.s)

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB

	OS_global OS_AtomicFetchAnd

	OS_align(4, 2)

	/* os_atomic_value_t OS_AtomicFetchAnd(os_atomic_t volatile *object,
	 *   os_atomic_value_t operand)
	 *
	 * !LINKSTO Kernel.Atomics.BoolOps, 1
	 */
	OS_ASM_FUNC(OS_AtomicFetchAnd)
OS_ASM_LABEL(OS_AtomicFetchAnd)
	dsb						/* ensure sequential consistency */
	stmfd r13!, {r4}		/* backup r4 */
OS_ASM_LABEL(_retry)
	ldrex r2, [r0]			/* r2 = *object */
	and r3, r2, r1			/* r3 = r2 & operand */
	strex r4, r3, [r0]		/* *object &= operand, r4 = success_indicator */
	cmp r4, #0				/* was store successful? */
	bne _retry				/* retry operation if store failed */
	mov r0, r2				/* return previous value */
	ldmfd r13!, {r4}		/* restore r4 */
	dsb						/* ensure sequential consistency */
	bx lr
	OS_ASM_END_FUNC(OS_AtomicFetchAnd)

	OS_ASM_SRC_END

/* Editor settings: DO NOT DELETE
 * vi:set ts=4:
*/
