/* CORTEXM-atomicclearflag.s
 *
 * This file contains the function OS_AtomicClearFlag().
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: CORTEXM-atomicclearflag.s 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#include <CORTEXM/Os_asm_CORTEXM.h>		/* Must be first! */
#include <Os_kernel.h>

	OS_file(CORTEXM-atomicclearflag.s)

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB

	OS_global OS_AtomicClearFlag

	OS_align(4, 2)

	/* void OS_AtomicClearFlag(os_atomic_t volatile *object,
	 *   os_atomic_value_t flagSelectionMask)
	 *
	 * !LINKSTO Kernel.Atomics.FlagOps, 1
	 */
	OS_ASM_FUNC(OS_AtomicClearFlag)
OS_ASM_LABEL(OS_AtomicClearFlag)
	dsb						/* ensure sequential consistency */
OS_ASM_LABEL(_retry)
	ldrex r2, [r0]			/* r2 = *object */
	bic r2, r2, r1			/* r2 &= ~flagSelectionMask */
	strex r3, r2, [r0]		/* *object &= ~flagSelectionMask,
								r3 = success_indicator */
	cmp r3, #0				/* was store successful? */
	bne _retry				/* retry operation if store failed */
	dsb						/* ensure sequential consistency */
	bx lr
	OS_ASM_END_FUNC(OS_AtomicClearFlag)

	OS_ASM_SRC_END

/* Editor settings: DO NOT DELETE
 * vi:set ts=4:
*/
