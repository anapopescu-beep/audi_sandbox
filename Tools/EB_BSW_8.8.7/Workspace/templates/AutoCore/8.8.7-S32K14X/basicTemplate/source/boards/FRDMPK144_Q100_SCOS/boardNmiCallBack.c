/* boardNmiCallBack.c - board specific code.
 *
 * This file contains call back function from NMI handling.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: boardNmiCallBack.c 1.1 2023/04/18 07:06:27CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#include <board.h>
#include <Os.h>
#include <Os_tool.h>
#include <Os_kernel.h>

void boardNmiCallBack(void)
{
	/* This is the default handling of NMI call back. */
#ifdef  TESTCASE_ExceptionHandlingCortexM
	/* For testing the common exception handling of OS for NMI */
	return;
#else
	OS_ENDLESSLOOP();
#endif /* TESTCASE_ExceptionHandlingCortexM */
	return;
}


/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
