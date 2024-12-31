/* Os_tool_CORTEXM_gnu.h - CORTEXM macros for GNU C Compiler.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_tool_CORTEXM_gnu.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_TOOL_CORTEXM_GNU_H
#define OS_TOOL_CORTEXM_GNU_H

#define OS_TOOL_INLINE_KEYWORD __inline__
#define OS_TOOL_ASM_KEYWORD __asm__

#define OS_TOOL_EXTENSION_KEYWORD __extension__

/* OS_DSB() - Issue a dsb instruction.
*/
#define OS_DSB()									\
	do												\
	{												\
		__asm__ volatile ("dsb"						\
						: /* no result */			\
						: /* no inputs */			\
						: "memory" /* do not reorder */	\
						);	\
	} while (0)

/* OS_ISB() - Issue an isb instruction.
*/
#define OS_ISB()									\
	do												\
	{												\
		__asm__ volatile ("isb"						\
						: /* no result */			\
						: /* no inputs */			\
						: /* nothing clobbered */	\
						);	\
	} while (0)


/* os_stackelement_t OS_GetSP(void)
 *
 * Get the stackpointer
*/
#define OS_TOOL_GETSP_IMPLEMENTATION OS_TOOL_ASM_INLINE

#define OS_CORTEXM_GetSP()								\
	OS_TOOL_EXTENSION_KEYWORD							\
	({													\
		register os_stackelement_t *OS_getSpResult;		\
		__asm__ volatile ("mov	%[result], r13"			\
		: [result] "=r" (OS_getSpResult)				\
		: /* no inputs */								\
		: /* nothing clobbered */);						\
		OS_getSpResult;									\
	})

/* OS_CORTEXM_DisableIRQ Disable the IRQ-Flag. */
#define OS_CORTEXM_DisableIRQ()	{ __asm__ volatile ("cpsid	i"); }

/* OS_CORTEXM_DisableIRQGetState Disable IRQs and return old CPU state (PRIMASK, etc.) */
#define OS_TOOL_DISABLE_IRQ_GET_STATE_IMPLEMENTATION OS_TOOL_ASM_INLINE

#define OS_CORTEXM_DisableIRQGetState()					\
	OS_TOOL_EXTENSION_KEYWORD							\
	({													\
		register os_uint32_t OS_DIRQResult;				\
		__asm__ volatile ("mrs	%[result], primask"		\
						: [result] "=r" (OS_DIRQResult)	\
						: /* no inputs */				\
						: /* nothing clobbered */);		\
		OS_CORTEXM_DisableIRQ();						\
		OS_DIRQResult;									\
	})

/* OS_CORTEXM_SetState Set new value of the CPU state (e.g. CPSR, PRIMASK, etc.) */
#define OS_TOOL_SET_STATE_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_SetState(val)		do {											\
										register os_uint32_t newPrimask = val;			\
										__asm__ volatile ("msr primask, %[input]"		\
														: /* no outputs */				\
														: [input] "r" (newPrimask)		\
														: /* nothing clobbered */);		\
									} while(0)


/* OS_CORTEXM_GetIRQPrio Return current interrupt priority barrier (e.g. BASEPRI, etc.) */
#define OS_TOOL_GET_IRQ_PRIO_IMPLEMENTATION OS_TOOL_ASM_INLINE

#define OS_CORTEXM_GetIRQPrio()							\
	OS_TOOL_EXTENSION_KEYWORD							\
	({													\
		register os_uint32_t OS_CurBasepri;				\
		__asm__ volatile ("mrs	%[result], basepri"		\
		: [result] "=r" (OS_CurBasepri)					\
		: /* no inputs */								\
		: /* nothing clobbered */);						\
		((os_oldlevel_t)(OS_CurBasepri >> OS_CORTEXM_INT_PRIO_SHIFT));	\
	})

/* OS_CORTEXM_SetIRQPrio Set new interrupt priority barrier (BASEPRI) */
#define OS_TOOL_SET_IRQ_PRIO_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_SetIRQPrio(val)		do {											\
										register os_uint32_t newBasepri = val << OS_CORTEXM_INT_PRIO_SHIFT;	\
										__asm__ volatile ("msr basepri, %[input]"		\
														: /* no outputs */				\
														: [input] "r" (newBasepri)		\
														: /* nothing clobbered */);		\
									} while(0)


/* OS_CORTEXM_GetCurIRQSource Return source of current interrupt (e.g. IPSR, etc.) */
#define OS_TOOL_GET_CUR_IRQ_SOURCE_IMPLEMENTATION OS_TOOL_ASM_INLINE

#define OS_CORTEXM_GetCurIRQSource()					\
	OS_TOOL_EXTENSION_KEYWORD							\
	({													\
		register os_uint32_t OS_CurIpsr;				\
		__asm__ volatile ("mrs	%[result], ipsr"		\
						: [result] "=r" (OS_CurIpsr)	\
						: /* no inputs */				\
						: /* nothing clobbered */);		\
		OS_CurIpsr - 16;								\
	})

/* OS_PARAM_UNUSED(p) - mark parameter p as unused parameter (or variable).
 * Usage: Function-like.
*/
#define OS_PARAM_UNUSED(p) ((void)(p))


/* FPU registers must not be used in OS functions since it is disabled when entering the kernel. */
#if (__GNUC__ >= 9)
#define OS_TOOL_FUNCTION_ATTRIB_PRE     __attribute__((target("general-regs-only")))
#else
#define OS_TOOL_FUNCTION_ATTRIB_PRE     /* nothing - not supported */
#endif

#endif /* __OS_TOOL_CORTEXM_GNU_H */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
