/* CORTEXM-atomicexchange.s
 *
 * This file contains the function OS_AtomicExchange().
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: CORTEXM-atomicexchange.s 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#include <CORTEXM/Os_asm_CORTEXM.h>		/* Must be first! */
#include <Os_kernel.h>

	OS_file(CORTEXM-atomicexchange.s)

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB

	OS_global OS_AtomicExchange

	OS_align(4, 2)

	/* os_atomic_value_t OS_AtomicExchange(os_atomic_t volatile *object,
	 *   os_atomic_value_t newValue)
	 *
	 * !LINKSTO Kernel.Atomics.Exchange, 1
	 */
	OS_ASM_FUNC(OS_AtomicExchange)
OS_ASM_LABEL(OS_AtomicExchange)
	dsb						/* ensure sequential consistency */
OS_ASM_LABEL(_retry)
	ldrex r2, [r0]			/* tmp(r2) = *object(r0) */
	strex r3, r1, [r0]		/* *object = newValue(r1), r3 = success_indicator */
	cmp r3, #0				/* check success of store */
	bne _retry				/* retry exhange if store failed */
	mov r0, r2				/* return tmp, i.e., previous value in *object */
	dsb						/* ensure sequential consistency */
	bx lr
	OS_ASM_END_FUNC(OS_AtomicExchange)

	OS_ASM_SRC_END

/* Editor settings: DO NOT DELETE
 * vi:set ts=4:
*/
