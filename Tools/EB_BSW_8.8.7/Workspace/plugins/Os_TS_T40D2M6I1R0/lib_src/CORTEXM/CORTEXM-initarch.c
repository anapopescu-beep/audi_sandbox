/* CORTEXM-initarch.c
 *
 * This file contains architecture-specific initialization code for CORTEXM
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: CORTEXM-initarch.c 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#include <Os_types.h>
#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <CORTEXM/Os_CORTEXM_cpu.h>
#include <Os_kernel.h>

#include <memmap/Os_mm_code_begin.h>

OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_CORTEXM_InitArch(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	/* Call derivate-specific init function */

	OS_CORTEXM_CpuInitArch();
	/* Set CONTROL:
	 * Thread mode is privileged,
	 * Thread mode uses PSP
	 * FP extensions (automatic save of FP context) disabled.
	*/
	OS_CORTEXM_SetControl(OS_CORTEXM_CONTROL_SP_PROCESS);
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_CORTEXM_initarch_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
