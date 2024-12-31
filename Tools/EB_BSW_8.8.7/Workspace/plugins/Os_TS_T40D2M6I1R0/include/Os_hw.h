/* Os_hw.h
 *
 * This file defines the architecture and derivative
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_hw.h 1.1 2023/04/18 07:06:17CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#ifndef OS_HW_H
#define OS_HW_H

#define OS_ARCH	OS_CORTEXM
#define OS_CPU	OS_S32K14X

/*
 * Those are defined in asc_PluginBuildEnv/common/Include/Base_BuildEnvironment/util/common.mak
*/
#ifndef TS_ARCH_FAMILY
#define TS_ARCH_FAMILY		OS_CORTEXM
#endif
#ifndef TS_ARCH_DERIVATE
#define TS_ARCH_DERIVATE	OS_S32K14X
#endif

/* Architecture specific defines */
#include <CORTEXM/Os_hw_CORTEXM.h>

#endif /* OS_HW_H */
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/

