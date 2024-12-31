/* kern-wrapnoop.c
 *
 * This file contains the OS_WrapNoOp alarm wrapper function
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-wrapnoop.c 1.1 2023/04/18 07:06:23CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#include <Os_kernel.h>

#include <memmap/Os_mm_code_begin.h>
 
/*!
 * OS_WrapNoOp
 *
 * This function is a No-Op wrapper for the internal GenericTimestamp alarm.
 *
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_WrapNoOp(const os_alarm_t *a)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	OS_PARAM_UNUSED(a);
}

#include <memmap/Os_mm_code_end.h>

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
