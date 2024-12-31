/* CORTEXM-exceptions.c
 *
 * This file contains the OS_Exception*X functions.
 * They are the trap handlers for CORTEXM
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: CORTEXM-exceptions.c 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
 */

#define OS_SID OS_SID_ArchTrapHandler
#define OS_SIF OS_svc_ArchTrapHandler

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <memmap/Os_mm_code_begin.h>

/*
 * OS_Exception()
 *
 * This function is called by the exception handler. It evaluates the
 * exception id and then calls the error handler.
 *
 * Parameters:
 * id		The id of the exception
 * pc		The instruction address where the exception occurred
 * status	The fault status register (optional)
 * addr		The fault address register (optional)
 *
 * Return value:
 * the old value of the inKernel flag
 */
OS_TOOL_FUNCTION_ATTRIB_PRE
os_uint32_t OS_Exception(os_uint32_t id, os_uint32_t pc, os_uint32_t status, os_uint32_t addr)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_uint8_t inKernel;
	OS_PH_PARAMETERACCESS_DECL

	inKernel = OS_GetKernelData()->inKernel;
	OS_GetKernelData()->inKernel = 1;

	OS_PH_SAVE_PARAMETER_N(0,pc);
	OS_PH_SAVE_PARAMETER_N(1,status);
	OS_PH_SAVE_PARAMETER_N(2,addr);

	switch (id)
	{
	case OS_CORTEXM_EX_NMI:
		/* can't propagate the return value of OS_ERROR -> ignore it */
		(void) OS_ERROR(OS_ERROR_NonMaskableInterrupt, OS_PH_GET_PARAMETER_VAR());
		break;

	case OS_CORTEXM_EX_HARD_FAULT:
		/* can't propagate the return value of OS_ERROR -> ignore it */
		(void) OS_ERROR(OS_ERROR_HardFault, OS_PH_GET_PARAMETER_VAR());
		break;

	case OS_CORTEXM_EX_MEM_MANAGE:
		/* can't propagate the return value of OS_ERROR -> ignore it */
		(void) OS_ERROR(OS_ERROR_MemoryManagement, OS_PH_GET_PARAMETER_VAR());
		break;

	case OS_CORTEXM_EX_BUS_FAULT:
		/* can't propagate the return value of OS_ERROR -> ignore it */
		(void) OS_ERROR(OS_ERROR_BusFault, OS_PH_GET_PARAMETER_VAR());
		break;

	case OS_CORTEXM_EX_USAGE_FAULT:
		/* can't propagate the return value of OS_ERROR -> ignore it */
		(void) OS_ERROR(OS_ERROR_UsageFault, OS_PH_GET_PARAMETER_VAR());
		break;

	case OS_CORTEXM_EX_RESERVED_1:
		/* can't propagate the return value of OS_ERROR -> ignore it */
		(void) OS_ERROR(OS_ERROR_ReservedException_1, OS_PH_GET_PARAMETER_VAR());
		break;

	case OS_CORTEXM_EX_RESERVED_2:
		/* can't propagate the return value of OS_ERROR -> ignore it */
		(void) OS_ERROR(OS_ERROR_ReservedException_2, OS_PH_GET_PARAMETER_VAR());
		break;

	case OS_CORTEXM_EX_RESERVED_3:
		/* can't propagate the return value of OS_ERROR -> ignore it */
		(void) OS_ERROR(OS_ERROR_ReservedException_3, OS_PH_GET_PARAMETER_VAR());
		break;

	case OS_CORTEXM_EX_RESERVED_4:
		/* can't propagate the return value of OS_ERROR -> ignore it */
		(void) OS_ERROR(OS_ERROR_ReservedException_4, OS_PH_GET_PARAMETER_VAR());
		break;

	case OS_CORTEXM_EX_SVC:
		/* can't propagate the return value of OS_ERROR -> ignore it */
		/* Note: This is unreachable. */
		(void) OS_ERROR(OS_ERROR_SupervisorCall, OS_PH_GET_PARAMETER_VAR());
		break;

	case OS_CORTEXM_EX_DEBUG:
		/* can't propagate the return value of OS_ERROR -> ignore it */
		(void) OS_ERROR(OS_ERROR_DebugMonitor, OS_PH_GET_PARAMETER_VAR());
		break;

	case OS_CORTEXM_EX_RESERVED_5:
		/* can't propagate the return value of OS_ERROR -> ignore it */
		(void) OS_ERROR(OS_ERROR_ReservedException_5, OS_PH_GET_PARAMETER_VAR());
		break;

	case OS_CORTEXM_EX_PEND_SV:
		/* can't propagate the return value of OS_ERROR -> ignore it */
		/* Note: This is unreachable. */
		(void) OS_ERROR(OS_ERROR_PendingSupervisorCall, OS_PH_GET_PARAMETER_VAR());
		break;

	case OS_CORTEXM_EX_SYS_TICK:
		/* can't propagate the return value of OS_ERROR -> ignore it */
		(void) OS_ERROR(OS_ERROR_SystemTick, OS_PH_GET_PARAMETER_VAR());
		break;

	default: /* OS_Exception() was called with an unknown/invalid exception id */
		/* can't propagate the return value of OS_ERROR -> ignore it */
		(void) OS_ERROR(OS_ERROR_UnknownException,OS_NULL);
		break;

	}

	return inKernel;
}
#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_CORTEXM_exceptions_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
 */
