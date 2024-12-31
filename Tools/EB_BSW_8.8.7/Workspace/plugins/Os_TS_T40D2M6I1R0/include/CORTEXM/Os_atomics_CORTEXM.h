/* Os_atomics_CORTEXM.h
 *
 * This file contains the common part of the atomic functions for CORTEXM.
 * It mainly selects between the load/store-exclusive and the hardware-semaphore
 * variants.
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_atomics_CORTEXM.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#ifndef OS_ATOMICS_CORTEXM_H
#define OS_ATOMICS_CORTEXM_H

#include <Os_types.h>
#include <Os_tool.h>
#include <CORTEXM/Os_CORTEXM_cpu.h>

typedef os_uint32_t os_atomic_t;
typedef os_uint32_t os_atomic_value_t;
#define OS_ATOMICS_VALUE_MAX OS_U(0xFFFFFFFF)


#if (OS_HAS_EXACCESS_MONITOR == 1)
#include <CORTEXM/Os_atomics_ex_CORTEXM.h>
#elif (OS_HAS_SEMA4 == 1)
#include <CORTEXM/Os_atomics_sema4_CORTEXM.h>
#else
#error "No valid atomics implementation found."
#endif

#endif /* OS_ATOMICS_CORTEXM_H */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
