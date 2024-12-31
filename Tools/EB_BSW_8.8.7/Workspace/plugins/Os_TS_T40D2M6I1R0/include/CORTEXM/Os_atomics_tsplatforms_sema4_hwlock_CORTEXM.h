/* Os_atomics_tsplatforms_sema4_hwlock_CORTEXM.h
 *
 * This file contains macros that take and drop a hardware lock in the SEMA4
 * module to support legacy atomic functions.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_atomics_tsplatforms_sema4_hwlock_CORTEXM.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ATOMICS_TSPLATFORMS_SEMA4_CORTEXM_H
#define OS_ATOMICS_TSPLATFORMS_SEMA4_CORTEXM_H

#include <Os_defs.h>
#include <Os_cpu.h>

#if (OS_N_CORES > 1)
#ifndef OS_HAS_SEMA4
#error "The macro OS_HAS_SEMA4 is not defined."
#endif
#if (OS_HAS_SEMA4 == 0)
#error "There must be a SEMA4 module in multi-core environments."
#endif

#define OS_AtomicsDropHardwareLock()			OS_SEMA42_Drop(OS_ATOMICS_HARDWARELOCK)
#define OS_AtomicsTakeHardwareLock(oldIState)	OS_SEMA42_Acquire_IState(OS_ATOMICS_HARDWARELOCK, oldIState)

#else /* (OS_N_CORES == 1) */
#define OS_AtomicsDropHardwareLock()			do { } while (0)
#define OS_AtomicsTakeHardwareLock(oldIState)	do { } while (0)

#endif /* (OS_N_CORES > 1) */
#endif /* OS_ATOMICS_TSPLATFORMS_SEMA4_CORTEXM_H */
