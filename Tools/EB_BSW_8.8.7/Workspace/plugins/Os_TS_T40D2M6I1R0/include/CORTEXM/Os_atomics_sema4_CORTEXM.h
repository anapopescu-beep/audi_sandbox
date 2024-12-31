/* Os_atomics_sema4_CORTEXM.h
 *
 * This file contains the type definitions and declarations for the atomic
 * functions for CORTEXM, based on the SEMA42 hardware semaphore unit.
 * Please see Os_atomics.h for further details.
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_atomics_sema4_CORTEXM.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#ifndef OS_ATOMICS_SEMA4_CORTEXM_H
#define OS_ATOMICS_SEMA4_CORTEXM_H

/* This implementation of the atomic functions is based on the SEMA4 hardware module.
 * For EB tresos AutoCore OS it doesn't pose a severe problem, because there are no
 * safety requirements. For EB tresos Safety OS the situation is different, because
 * the microkernel has to use the same hardware, and must prohibit interferences.
 * Hence, it requires exclusive access.
*/
#if (OS_KERNEL_TYPE == OS_MICROKERNEL)
#error "The atomic functions are not available for this derivate in combination with EB tresos Safety OS. Please use the generic implementation of the Atomics module instead."
#endif

#include <CORTEXM/Os_atomics_tsplatforms_sema4_hwlock_CORTEXM.h>

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
	os_uint32_t oldState;

	oldState = OS_CORTEXM_DisableIRQGetState();
	OS_AtomicsTakeHardwareLock(oldState);

	OS_AtomicThreadFence();

	*object = newValue;

	OS_AtomicThreadFence();

	OS_AtomicsDropHardwareLock();
	OS_CORTEXM_SetState(oldState);
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

/* !LINKSTO Kernel.Atomics.Exchange, 1
 */
static OS_TOOL_INLINE_KEYWORD os_atomic_value_t OS_AtomicExchange(
	os_atomic_t volatile *object, os_atomic_value_t newValue)
{
	os_uint32_t oldState;
	os_atomic_value_t tmp;

	oldState = OS_CORTEXM_DisableIRQGetState();
	OS_AtomicsTakeHardwareLock(oldState);

	OS_AtomicThreadFence();

	tmp = *object;
	*object = newValue;

	OS_AtomicThreadFence();

	OS_AtomicsDropHardwareLock();
	OS_CORTEXM_SetState(oldState);

	return tmp;
}

/* !LINKSTO Kernel.Atomics.CompareExchange, 1
 */
static OS_TOOL_INLINE_KEYWORD os_boolean_t OS_AtomicCompareExchange(
	os_atomic_t volatile *object,
	os_atomic_value_t *expected,
	os_atomic_value_t newValue)
{
	os_uint32_t oldState;
	os_atomic_value_t tmp;
	os_boolean_t updated;
	os_atomic_value_t const exp = *expected;

	oldState = OS_CORTEXM_DisableIRQGetState();
	OS_AtomicsTakeHardwareLock(oldState);

	OS_AtomicThreadFence();

	tmp = *object;
	updated = (tmp == exp);
	if (updated)
	{
		*object = newValue;
	}

	OS_AtomicThreadFence();

	OS_AtomicsDropHardwareLock();
	OS_CORTEXM_SetState(oldState);

	if (!updated)
	{
		*expected = tmp;
	}

	return updated;
}

/* !LINKSTO Kernel.Atomics.ArithmeticOps, 1
 */
static OS_TOOL_INLINE_KEYWORD os_atomic_value_t OS_AtomicFetchAdd(
	os_atomic_t volatile *object, os_atomic_value_t operand)
{
	os_uint32_t oldState;
	os_atomic_value_t old;

	oldState = OS_CORTEXM_DisableIRQGetState();
	OS_AtomicsTakeHardwareLock(oldState);

	OS_AtomicThreadFence();

	old = *object;
	*object = old + operand;

	OS_AtomicThreadFence();

	OS_AtomicsDropHardwareLock();
	OS_CORTEXM_SetState(oldState);

	return old;
}

/* !LINKSTO Kernel.Atomics.ArithmeticOps, 1
 */
static OS_TOOL_INLINE_KEYWORD os_atomic_value_t OS_AtomicFetchSub(
	os_atomic_t volatile *object, os_atomic_value_t operand)
{
	os_uint32_t oldState;
	os_atomic_value_t old;

	oldState = OS_CORTEXM_DisableIRQGetState();
	OS_AtomicsTakeHardwareLock(oldState);

	OS_AtomicThreadFence();

	old = *object;
	*object = old - operand;

	OS_AtomicThreadFence();

	OS_AtomicsDropHardwareLock();
	OS_CORTEXM_SetState(oldState);

	return old;
}

/* !LINKSTO Kernel.Atomics.BoolOps, 1
 */
static OS_TOOL_INLINE_KEYWORD os_atomic_value_t OS_AtomicFetchOr(
	os_atomic_t volatile *object, os_atomic_value_t operand)
{
	os_uint32_t oldState;
	os_atomic_value_t old;

	oldState = OS_CORTEXM_DisableIRQGetState();
	OS_AtomicsTakeHardwareLock(oldState);

	OS_AtomicThreadFence();

	old = *object;
	*object = old | operand;

	OS_AtomicThreadFence();

	OS_AtomicsDropHardwareLock();
	OS_CORTEXM_SetState(oldState);

	return old;
}

/* !LINKSTO Kernel.Atomics.BoolOps, 1
 */
static OS_TOOL_INLINE_KEYWORD os_atomic_value_t OS_AtomicFetchAnd(
	os_atomic_t volatile *object, os_atomic_value_t operand)
{
	os_uint32_t oldState;
	os_atomic_value_t old;

	oldState = OS_CORTEXM_DisableIRQGetState();
	OS_AtomicsTakeHardwareLock(oldState);

	OS_AtomicThreadFence();

	old = *object;
	*object = old & operand;

	OS_AtomicThreadFence();

	OS_AtomicsDropHardwareLock();
	OS_CORTEXM_SetState(oldState);

	return old;
}

/* !LINKSTO Kernel.Atomics.BoolOps, 1
 */
static OS_TOOL_INLINE_KEYWORD os_atomic_value_t OS_AtomicFetchXor(
	os_atomic_t volatile *object, os_atomic_value_t operand)
{
	os_uint32_t oldState;
	os_atomic_value_t old;

	oldState = OS_CORTEXM_DisableIRQGetState();
	OS_AtomicsTakeHardwareLock(oldState);

	OS_AtomicThreadFence();

	old = *object;
	*object = old ^ operand;

	OS_AtomicThreadFence();

	OS_AtomicsDropHardwareLock();
	OS_CORTEXM_SetState(oldState);

	return old;
}

/* !LINKSTO Kernel.Atomics.FlagOps, 1
 */
static OS_TOOL_INLINE_KEYWORD os_boolean_t OS_AtomicTestAndSetFlag(
	os_atomic_t volatile *object, os_atomic_value_t flagSelectionMask)
{
	os_uint32_t oldState;
	os_atomic_value_t old;

	oldState = OS_CORTEXM_DisableIRQGetState();
	OS_AtomicsTakeHardwareLock(oldState);

	OS_AtomicThreadFence();

	old = *object;
	*object = old | flagSelectionMask;

	OS_AtomicThreadFence();

	OS_AtomicsDropHardwareLock();
	OS_CORTEXM_SetState(oldState);

	return (old & flagSelectionMask) != 0;
}

/* !LINKSTO Kernel.Atomics.FlagOps, 1
 */
static OS_TOOL_INLINE_KEYWORD void OS_AtomicClearFlag(
	os_atomic_t volatile *object, os_atomic_value_t flagSelectionMask)
{
	os_uint32_t oldState;

	oldState = OS_CORTEXM_DisableIRQGetState();
	OS_AtomicsTakeHardwareLock(oldState);

	OS_AtomicThreadFence();

	*object &= (os_atomic_value_t)~flagSelectionMask;

	OS_AtomicThreadFence();

	OS_AtomicsDropHardwareLock();
	OS_CORTEXM_SetState(oldState);
}

#endif /* OS_ATOMICS_SEMA4_CORTEXM_H */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
