/* Os_tool_CORTEXM_ghs.h - CORTEXM macros for Greenhills Multi compiler.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_tool_CORTEXM_ghs.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_TOOL_CORTEXM_GHS_H
#define OS_TOOL_CORTEXM_GHS_H

#ifndef OS_ASM
#include <arm_ghs.h>
#endif /* ! OS_ASM */

/* OS_DSB() - Issue a dsb instruction.
*/
#define OS_DSB()									\
	do												\
	{												\
		__asm ("dsb");	\
	} while (0)

/* OS_ISB() - Issue an isb instruction.
*/
#define OS_ISB()									\
	do												\
	{												\
		__asm ("isb");	\
	} while (0)

/* OS_CORTEXM_DisableIRQGetState Disable IRQs and return previous CPU state (e.g. CPSR) */
#define OS_TOOL_DISABLE_IRQ_GET_STATE_IMPLEMENTATION OS_TOOL_ASM_FUNC

/* OS_CORTEXM_SetState Set new value of the CPU state (e.g. CPSR, PRIMASK, etc.) */
#define OS_TOOL_SET_STATE_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_SetState(val)	__MSR(__PRIMASK, val)

/* OS_CORTEXM_GetIRQPrio Return current interrupt priority barrier (e.g. BASEPRI, etc.) */
#define OS_TOOL_GET_IRQ_PRIO_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_GetIRQPrio()	(__MRS(__BASEPRI) >> OS_CORTEXM_INT_PRIO_SHIFT)

/* OS_CORTEXM_SetIRQPrio Set new interrupt priority barrier (e.g. BASEPRI, etc.) */
#define OS_TOOL_SET_IRQ_PRIO_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_SetIRQPrio(val)	__MSR(__BASEPRI, ((val) << OS_CORTEXM_INT_PRIO_SHIFT))

/* OS_CORTEXM_GetCurIRQSource Return source of current interrupt (e.g. IPSR, etc.) */
#define OS_TOOL_GET_CUR_IRQ_SOURCE_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_GetCurIRQSource()	(__MRS(__IPSR) - 16U)


/* OS_PARAM_UNUSED(p) - mark parameter p as unused parameter (or variable).
 * Usage: Function-like.
*/
#define OS_PARAM_UNUSED(p) ((void)(p))

#define OS_TOOL_INLINE_KEYWORD __inline

#define OS_TOOL_ASM_KEYWORD __asm

#endif /* OS_TOOL_CORTEXM_GHS_H */
/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
