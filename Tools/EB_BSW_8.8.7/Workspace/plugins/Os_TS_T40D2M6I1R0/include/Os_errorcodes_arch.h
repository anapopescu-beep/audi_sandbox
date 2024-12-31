/* Os_errorcodes_arch.h
 *
 * Architecture-dependent error-codes are included from the appropriate
 * ARCH/Os_errorcodes_arch.h include file depending on the chosen architecture.
 *
 * The Makefiles must ensure that the OS_ARCH and OS_CPU macros are
 * defined appropriately on the command line.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_errorcodes_arch.h 1.1 2023/04/18 07:06:17CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#ifndef OS_ERRORCODES_ARCH_H
#define OS_ERRORCODES_ARCH_H

#include <Os_defs.h>

#include <Os_hwsel.h>
#include OS_HWSEL_ERRORCODES

#endif
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
