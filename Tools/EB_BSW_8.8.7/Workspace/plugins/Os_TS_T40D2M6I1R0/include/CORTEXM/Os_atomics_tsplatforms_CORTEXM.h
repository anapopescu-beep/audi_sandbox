/* Os_atomics_tsplatforms_CORTEXM.h
 *
 * This file is the CORTEXM header file for the set of atomic functions and types,
 * which are provided for reasons of backward compatibility with the
 * asc_Platforms module. That module offered a set of types and functions for
 * atomic bit-manipulation and interrupt control.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_atomics_tsplatforms_CORTEXM.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#ifndef OS_ATOMICS_TSPLATFORMS_CORTEXM_H
#define OS_ATOMICS_TSPLATFORMS_CORTEXM_H

#include <Os_defs.h>
#include <Os_panic.h>
#include <CORTEXM/Os_tool_CORTEXM.h>
#include <CORTEXM/Os_CORTEXM_core.h>

#if (OS_HAS_EXACCESS_MONITOR == 1)
#include <Os_atomics_tsplatforms_generic_bits_reservations.h>
#elif (OS_HAS_SEMA4 == 1)
#include <Os_atomics_tsplatforms_generic_bits_hwlock.h>
#else
#error "Underlying mechanism to implement legacy atomic functions unspecified."
#endif


/* Introduce declarations of Enable/DisableAllInterrupts()
 * depending on kernel type.
 */
#if OS_KERNEL_TYPE == OS_MICROKERNEL
#include <Os_atomics_tsplatforms_generic_intlocks.h>

#else /* OS_KERNEL_TYPE != OS_MICROKERNEL */
#include <Os_api_cfg.h>

/* !LINKSTO Kernel.Atomics.TSFunctionsIntCtrl, 1
*/

static OS_TOOL_INLINE_KEYWORD os_intstatus_t OS_UserAtomicTSIntDisable(void)
{
	os_intstatus_t state;
	os_uint32_t control = OS_CORTEXM_GetControl();

	if ((control & OS_CORTEXM_CONTROL_NPRIV) == OS_CORTEXM_CONTROL_NPRIV)
	{
		/* non priviledged mode: fall back to slower ASR IRQ locking */
		SuspendAllInterrupts();
		state = 0u;
	}
	else
	{
		state = (os_intstatus_t)OS_CORTEXM_DisableIRQGetState();
	}
	return state;
}

static OS_TOOL_INLINE_KEYWORD void OS_UserAtomicTSIntRestore(os_intstatus_t state)
{
	os_uint32_t control = OS_CORTEXM_GetControl();

	if ((control & OS_CORTEXM_CONTROL_NPRIV) == OS_CORTEXM_CONTROL_NPRIV)
	{
		if (state != 0u)
		{
			(void)OS_PANIC(OS_PANIC_ATOMICS_InvalidInterruptStatus);
		}
		ResumeAllInterrupts();
	}
	else
	{
		OS_CORTEXM_SetState((os_uint32_t)state);
	}
}

#endif /* OS_KERNEL_TYPE == OS_MICROKERNEL */
#endif /* OS_ATOMICS_TSPLATFORMS_CORTEXM_H */
