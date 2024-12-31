/* CORTEXM-atomiccompareexchange.s
 *
 * This file contains the function OS_AtomicCompareExchange().
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: CORTEXM-atomiccompareexchange.s 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#include <CORTEXM/Os_asm_CORTEXM.h>		/* Must be first! */
#include <Os_kernel.h>

	OS_file(CORTEXM-atomiccompareexchange.s)

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB

	OS_global OS_AtomicCompareExchange

	OS_align(4, 2)

	/* os_boolean_t OS_AtomicCompareExchange(os_atomic_t volatile *object,
	 *   os_atomic_value_t *expected, os_atomic_value_t newValue)
	 *
	 * !LINKSTO Kernel.Atomics.CompareExchange, 1
	 */
	OS_ASM_FUNC(OS_AtomicCompareExchange)
OS_ASM_LABEL(OS_AtomicCompareExchange)
	dsb						/* ensure sequential consistency */
	stmfd r13!, {r4}		/* backup r4 */
	ldr r4, [r1]			/* r4 = *expected */
OS_ASM_LABEL(_retry)
	ldrex r3, [r0]			/* r3 = *object */
	cmp r3, r4				/* shall exchange happen? */

	/* if *object != *expected then abort exchange */
	itttt ne				/* Start conditional block */
	strne r3, [r1]			/* *expected = *object */
	movne r0, #0			/* return FALSE */
	ldmfdne r13!, {r4}			/* restore r4 */
	bxne lr					/* abort exchange */

	/* else exchange */
	strex r3, r2, [r0]		/* *object = newValue, r3 = success_indicator */
	cmp r3, #0				/* was store successful? */
	bne _retry				/* retry exchange if store failed */
	mov r0, #1				/* return TRUE */
	ldmfd r13!, {r4}		/* restore r4 */
	dsb						/* ensure sequential consistency */
	bx lr
	OS_ASM_END_FUNC(OS_AtomicCompareExchange)

	OS_ASM_SRC_END

/* Editor settings: DO NOT DELETE
 * vi:set ts=4:
*/
