/* lib-stackcheck.c
 *
 * This file contains the OS_StackCheck function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: lib-stackcheck.c 1.1 2023/04/18 07:06:23CEST Dan Dustinta (dan.dustinta) in_work  $
*/

/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 12.3 (required)
 * The comma operator shall not be used.
 *
 * Reason:
 * For function-call kernels, OS API is wrapped in macros. The macro wrappers
 * need to use the comma operator to form an expression evaluating to the
 * correct result.
 *
 *
 * MISRAC2012-2) Deviated Rule: 13.3 (advisory)
 * The increment (++) and decrement (--) operators should not be mixed with
 * other operators in an expression.
 *
 * Reason:
 * For function-call kernels, OS API is wrapped in macros. The macro wrappers
 * need to handle an "in kernel" flag so that the increment operator has to be
 * used in combination with the comma operator.
*/

#include <Os_api.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_kernel.h>		/* For OS_GetCurrentSp() */

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_StackCheck implements the API stackCheck
 *
 * The system call OS_UserGetStackInfo is called, first putting the
 * current SP into the info structure. This will be overwritten if we are
 * in an ISR context, because in that case calling the function uses some
 * stack.
 *
 * !LINKSTO Kernel.Feature.StackCheck.API.stackCheck, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_int_t OS_StackCheck(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_int_t answer = 0;
	os_stackinfo_t info;

	info.stackPointer = (os_stackinfoptr_t)OS_GetCurrentSp();

	/* COVPT-1 +2 */
	/* Deviation MISRAC2012-1, MISRAC2012-2 <1> */
	if ( OS_UserGetStackInfo(OS_TOI_CURRENTCONTEXT, &info) == OS_E_OK )
	{
		answer = info.stackStatus;
	}

	return answer;
}


#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_lib_stackcheck_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
