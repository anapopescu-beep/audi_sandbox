/* Os_atomics_tsplatforms_intlock_CORTEXM.h
 *
 * This file contains macros that disable and enable interrupts
 * to support the implementation of atomic functions. These definitions are
 * meant for internal use only.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_atomics_tsplatforms_intlock_CORTEXM.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ATOMICS_TSPLATFORMS_INTLOCK_CORTEXM_H
#define OS_ATOMICS_TSPLATFORMS_INTLOCK_CORTEXM_H

#include <Os_tool.h>

#define OS_AtomicsIntDisable()					OS_CORTEXM_DisableIRQGetState();
#define OS_AtomicsIntRestore(savedIntState)		OS_CORTEXM_SetState((savedIntState));

#endif /* OS_ATOMICS_TSPLATFORMS_INTLOCK_CORTEXM_H */
