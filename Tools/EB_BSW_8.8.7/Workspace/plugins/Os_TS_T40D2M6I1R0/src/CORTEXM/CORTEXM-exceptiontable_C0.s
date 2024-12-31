/* CORTEXM-exceptiontable.s
 *
 * Contains the exception table for core0.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: CORTEXM-exceptiontable_C0.s 1.2 2023/08/31 12:32:26CEST Gabriel Brasoveanu (gabriel.brasoveanu) in_work  $
*/

#ifndef OS_ASM
#define OS_ASM
#endif

#include <CORTEXM/Os_asm_CORTEXM.h>
#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <board.h>
#include <Os_kernel.h>
#include <Os_libconfig.h>
#include <Os_configuration.h>

#if ((OS_PROPERTIES_CORE0 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT)

	OS_global CORTEXMExceptionTable_C0

	OS_extern boardResetStart
	OS_extern OS_kernStack0

	OS_extern OS_SystemCall

#ifndef OS_EXCLUDE_EXCEPTIONS
	OS_extern OS_ExceptionNMIHandler
	OS_extern OS_ExceptionHardFaultHandler
	OS_extern OS_ExceptionMemManageHandler
	OS_extern OS_ExceptionBusFaultHandler
	OS_extern OS_ExceptionUsageFaultHandler
	OS_extern OS_ExceptionReservedHandler_1
	OS_extern OS_ExceptionReservedHandler_2
	OS_extern OS_ExceptionReservedHandler_3
	OS_extern OS_ExceptionReservedHandler_4
	OS_extern OS_ExceptionDebugHandler
	OS_extern OS_ExceptionReservedHandler_5
	OS_extern OS_ExceptionPendSVHandler
	OS_extern OS_ExceptionSysTickHandler
	OS_extern T1_DebugMonitorHandler
	OS_extern T1_HardFaultHandler

#else /* ! OS_EXCLUDE_EXCEPTIONS */
	OS_extern boardInvalidException
#endif /* ! OS_EXCLUDE_EXCEPTIONS */

	OS_ASM_SECTION_EXCTAB(0)
	
	/* Data label: cover the following OS_ASM_LABEL declarations */
	OS_ASM_DATALABEL

	/* normal usage of exception table */
#ifdef OS_EXCLUDE_EXCEPTIONS
OS_ASM_LABEL(CORTEXMExceptionTable_C0)
	OS_word	(OS_kernStack0 + OS_ISTACKLEN_0)	/* reset value of main stack pointer (0x00) */
	OS_word	boardResetStart					/* reset vector (0x04) */
	OS_word	boardInvalidException			/* non maskable interrupt vector (0x08) */
	OS_word	boardInvalidException			/* hard fault vector (0x0c) */
	OS_word	boardInvalidException			/* memory management vector (0x10) */
	OS_word	boardInvalidException			/* bus fault vector (0x14) */
	OS_word	boardInvalidException			/* usage fault vector (0x18) */
	OS_word	boardInvalidException			/* reserved (0x1c) */
	OS_word	boardInvalidException			/* reserved (0x20) */
	OS_word	boardInvalidException			/* reserved (0x24) */
	OS_word	boardInvalidException			/* reserved (0x28) */
	OS_word	OS_SystemCall					/* supervisor call vector (0x2c) */
	OS_word	boardInvalidException			/* debug monitor vector (0x30) */
	OS_word	boardInvalidException			/* reserved (0x34) */
	OS_word	boardInvalidException			/* pending supervisor vector (0x38) */
	OS_word	boardInvalidException			/* system tick vector (0x3c) */

#else
OS_ASM_LABEL(CORTEXMExceptionTable_C0)
	OS_word	(OS_kernStack0 + OS_ISTACKLEN_0)	/* reset value of main stack pointer (0x00) */
	OS_word	boardResetStart					/* reset vector (0x04) */
	OS_word	OS_ExceptionNMIHandler			/* non maskable interrupt vector (0x08) */
	OS_word	T1_HardFaultHandler	/* hard fault vector (0x0c) */
	OS_word	OS_ExceptionMemManageHandler	/* memory management vector (0x10) */
	OS_word	OS_ExceptionBusFaultHandler		/* bus fault vector (0x14) */
	OS_word	OS_ExceptionUsageFaultHandler	/* usage fault vector (0x18) */
	OS_word	OS_ExceptionReservedHandler_1	/* reserved (0x1c) */
	OS_word	OS_ExceptionReservedHandler_2	/* reserved (0x20) */
	OS_word	OS_ExceptionReservedHandler_3	/* reserved (0x24) */
	OS_word	OS_ExceptionReservedHandler_4	/* reserved (0x28) */
	OS_word	OS_SystemCall					/* supervisor call vector (0x2c) */
	OS_word	T1_DebugMonitorHandler		/* debug monitor vector (0x30) */
	OS_word	OS_ExceptionReservedHandler_5	/* reserved (0x34) */
	OS_word	OS_ExceptionPendSVHandler		/* pending supervisor vector (0x38) */
	OS_word	OS_ExceptionSysTickHandler		/* system tick vector (0x3c) */

#endif/* #ifdef OS_EXCLUDE_EXCEPTIONS */

#endif /* ((OS_PROPERTIES_CORE0 & OS_COREPROP_USED_BIT) == OS_COREPROP_USED_BIT) */

	OS_ASM_SRC_END

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
