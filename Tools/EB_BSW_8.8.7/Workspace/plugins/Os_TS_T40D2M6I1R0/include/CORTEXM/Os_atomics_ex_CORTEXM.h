/* Os_atomics_ex_CORTEXM.h
 *
 * This file contains the type definitions and declarations for the atomic
 * functions for CORTEXM, based on the load and store exclusive instructions.
 * Please see Os_atomics.h for further details.
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_atomics_ex_CORTEXM.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#ifndef OS_ATOMICS_EX_CORTEXM_H
#define OS_ATOMICS_EX_CORTEXM_H

extern void OS_AtomicThreadFence(void);

/* !LINKSTO Kernel.Atomics.Init, 1
 */
static OS_TOOL_INLINE_KEYWORD void OS_AtomicInit(
	os_atomic_t volatile *object,
	os_atomic_value_t initValue)
{
	*object = initValue;
}

/* !LINKSTO Kernel.Atomics.LoadStore, 1
 */
static OS_TOOL_INLINE_KEYWORD void OS_AtomicStore(
	os_atomic_t volatile *object,
	os_atomic_value_t newValue)
{
	OS_AtomicThreadFence();
	*object = newValue;
	OS_AtomicThreadFence();
}

/* !LINKSTO Kernel.Atomics.LoadStore, 1
 */
static OS_TOOL_INLINE_KEYWORD os_atomic_value_t OS_AtomicLoad(
	os_atomic_t const volatile *object)
{
	os_atomic_value_t value;

	OS_AtomicThreadFence();
	value = *object;
	OS_AtomicThreadFence();

	return value;
}

extern os_atomic_value_t OS_AtomicExchange(os_atomic_t volatile *,
	os_atomic_value_t);
extern os_boolean_t OS_AtomicCompareExchange(os_atomic_t volatile *,
	os_atomic_value_t *, os_atomic_value_t);
extern os_atomic_value_t OS_AtomicFetchAdd(os_atomic_t volatile *, os_atomic_value_t);
extern os_atomic_value_t OS_AtomicFetchSub(os_atomic_t volatile *, os_atomic_value_t);
extern os_atomic_value_t OS_AtomicFetchOr(os_atomic_t volatile *, os_atomic_value_t);
extern os_atomic_value_t OS_AtomicFetchAnd(os_atomic_t volatile *, os_atomic_value_t);
extern os_atomic_value_t OS_AtomicFetchXor(os_atomic_t volatile *, os_atomic_value_t);
extern os_boolean_t OS_AtomicTestAndSetFlag(os_atomic_t volatile *,
	os_atomic_value_t);
extern void OS_AtomicClearFlag(os_atomic_t volatile *, os_atomic_value_t);

#endif /* OS_ATOMICS_EX_CORTEXM_H */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
