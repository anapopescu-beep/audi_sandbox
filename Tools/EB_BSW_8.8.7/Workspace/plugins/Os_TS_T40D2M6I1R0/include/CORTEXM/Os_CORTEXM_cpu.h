/* Os_CORTEXM_cpu.h - CORTEXM CPU header file
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_CORTEXM_cpu.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_CORTEXM_CPU_H
#define OS_CORTEXM_CPU_H

#include <Os_defs.h>
#include <CORTEXM/Os_defs_CORTEXM.h>

/* Include the appropriate header file for the derivative.
 *
 * CAVEAT:
 * The presence here of an include directive for a particular derivative
 * does not imply support for that derivative, nor does it imply a
 * commitment or intention to support that derivative in the future.
*/
#if (OS_CPU == OS_MV88Q5050)
#include <CORTEXM/MV88Q5050/Os_CORTEXM_MV88Q5050.h>
#elif (OS_CPU == OS_MV88Q5072)
#include <CORTEXM/MV88Q5072/Os_CORTEXM_MV88Q5072.h>
#elif (OS_CPU == OS_S32K14X)
#include <CORTEXM/S32K14X/Os_CORTEXM_S32K14X.h>
#elif (OS_CPU == OS_BCM89107)
#include <CORTEXM/BCM89107/Os_CORTEXM_BCM89107.h>
#elif (OS_CPU == OS_CYT4BF)
#include <CORTEXM/CYT4BF/Os_CORTEXM_CYT4BF.h>
#elif (OS_CPU == OS_CYT4BB)
#include <CORTEXM/CYT4BB/Os_CORTEXM_CYT4BB.h>
#elif (OS_CPU == OS_CYT3DL)
#include <CORTEXM/CYT3DL/Os_CORTEXM_CYT3DL.h>
#elif (OS_CPU == OS_IMX8QMM4)
#include <CORTEXM/IMX8QMM4/Os_CORTEXM_IMX8QMM4.h>
#elif (OS_CPU == OS_CYT2B95)
#include <CORTEXM/CYT2B95/Os_CORTEXM_CYT2B95.h>
#elif (OS_CPU == OS_S32G27X)
#include <CORTEXM/S32G27X/Os_CORTEXM_S32G27X.h>
#elif (OS_CPU == OS_IMX8DXLM4)
#include <CORTEXM/IMX8DXLM4/Os_CORTEXM_IMX8DXLM4.h>
#elif (OS_CPU == OS_MV88Q6113)
#include <CORTEXM/MV88Q6113/Os_CORTEXM_MV88Q6113.h>
#elif (OS_CPU == OS_S32K34X)
#include <CORTEXM/S32K34X/Os_CORTEXM_S32K34X.h>
#elif (OS_CPU == OS_SAME5X)
#include <CORTEXM/SAME5X/Os_CORTEXM_SAME5X.h>
#elif (OS_CPU == OS_IMX8QXPM4)
#include <CORTEXM/IMX8QXPM4/Os_CORTEXM_IMX8QXPM4.h>
#elif (OS_CPU == OS_RTL90XXA)
#include <CORTEXM/RTL90XXA/Os_CORTEXM_RTL90XXA.h>
#elif (OS_CPU == OS_S32G399)
#include <CORTEXM/S32G399/Os_CORTEXM_S32G399.h>
#elif (OS_CPU == OS_S32K31X)
#include <CORTEXM/S32K31X/Os_CORTEXM_S32K31X.h>
#elif (OS_CPU == OS_S32Z27XM33)
#include <CORTEXM/S32Z27XM33/Os_CORTEXM_S32Z27XM33.h>
#elif (OS_CPU == OS_S32R45X)
#include <CORTEXM/S32R45X/Os_CORTEXM_S32R45X.h>
#elif (OS_CPU == OS_CYT2B75)
#include <CORTEXM/CYT2B75/Os_CORTEXM_CYT2B75.h>
#elif (OS_CPU == OS_SAF85XXM7)
#include <CORTEXM/SAF85XXM7/Os_CORTEXM_SAF85XXM7.h>
#elif (OS_CPU == OS_SR6P6M4)
#include <CORTEXM/SR6P6M4/Os_CORTEXM_SR6P6M4.h>
#else
#error "OS_CPU is not properly defined. Check your makefiles!"
#endif

#if (OS_KERNEL_TYPE==OS_SYSTEM_CALL) && ( (OS_USE_MMU==1) || (OS_USE_MPU==1) )
/* Memory protection is only supported if system call libraries are used and */
/* if the derivative has either a MMU or a MPU. */
#define OS_HASMEMPROT	1
#else
#define OS_HASMEMPROT	0
#endif

#ifndef OS_HAS_SEMA4
#define OS_HAS_SEMA4	0
#endif

#ifndef OS_HAS_EXACCESS_MONITOR
#define OS_HAS_EXACCESS_MONITOR	1
#endif

#ifndef OS_CORTEXM_IRQ_ROUTE_EN
#define OS_CORTEXM_IRQ_ROUTE_EN(_irqId, _targetCore)	do{} while(0)
#endif

#ifndef OS_CORTEXM_INT_MUX
#define OS_CORTEXM_INT_MUX	OS_CORTEXM_INT_MUX_NONE
#endif


#if (OS_N_CORES_MAX > 1)

/* CORTEXM does not require special handling when enabling the cross-core interrupt
 * during shutdown.
*/
#define OS_IntEnableXcoreFromShutdown()		\
	do {									\
		(void) OS_IntEnableXcore();			\
	} while(0)

#endif

#endif /* OS_CORTEXM_CPU_H */
/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
