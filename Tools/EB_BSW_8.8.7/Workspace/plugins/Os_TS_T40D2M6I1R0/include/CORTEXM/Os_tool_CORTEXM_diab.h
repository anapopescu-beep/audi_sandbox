/* Os_tool_CORTEXM_diab.h - CORTEXM macros for diab toolchain
 *
 * This file contains macros (C and assembler) for use with CORTEXM
 * and the diab compiler.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_tool_CORTEXM_diab.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_TOOL_CORTEXM_DIAB_H
#define OS_TOOL_CORTEXM_DIAB_H

#include <Os_arch.h>
#include <Os_types.h>

#define OS_TOOL_INLINE_KEYWORD __inline__
#define OS_TOOL_ASM_KEYWORD __asm

#if defined(__GNUC__)
#define OS_TOOL_EXTENSION_KEYWORD __extension__
#else
#define OS_TOOL_EXTENSION_KEYWORD
#endif

#ifndef OS_USE_DIAB_V7

#if !defined(OS_ASM)

/* CHECK: NOPARSE (assembler code) */

/* OS_DSB() - Issue a dsb instruction.
*/
__asm void volatile OS_DSB(void)
{
!
	dsb
}

/* OS_ISB() - Issue an isb instruction.
*/
__asm void volatile OS_ISB(void)
{
!
	isb
}

/* os_stackelement_t OS_CORTEXM_GetSP(void)
 *
 * Get the stackpointer
*/
#define OS_TOOL_GETSP_IMPLEMENTATION OS_TOOL_ASM_INLINE
__asm volatile os_stackelement_t *OS_CORTEXM_GetSP(void)
{
! "r0"
	mov	r0, r13
}

/* OS_CORTEXM_DisableIRQ Disable the IRQ-Flag. */
#define OS_TOOL_DISABLE_IRQ_IMPLEMENTATION OS_TOOL_ASM_INLINE
__asm volatile void OS_CORTEXM_DisableIRQ(void)
{
!
	cpsid	i
}

/* OS_CORTEXM_DisableIRQGetState Disable IRQs and return old CPU state (PRIMASK, etc.) */
#define OS_TOOL_DISABLE_IRQ_GET_STATE_IMPLEMENTATION OS_TOOL_ASM_INLINE
__asm volatile os_uint32_t OS_CORTEXM_DisableIRQGetState(void)
{
! "r0"
	mrs		r0, primask
	cpsid	i
}

/* OS_CORTEXM_SetState Set new value of the CPU state (e.g. CPSR, PRIMASK, etc.) */
#define OS_TOOL_SET_STATE_IMPLEMENTATION OS_TOOL_ASM_INLINE
__asm volatile void OS_CORTEXM_SetState(register os_uint32_t val)
{
%reg val
!
	msr primask, val
}

/* OS_CORTEXM_GetIRQPrio Return current interrupt priority barrier (e.g. BASEPRI, etc.) */
#define OS_TOOL_GET_IRQ_PRIO_IMPLEMENTATION OS_TOOL_ASM_INLINE
__asm volatile os_uint32_t OS_CORTEXM_GetIRQPrio(void)
{
! "r0"
	mrs	r0, basepri
	lsr r0, r0, #OS_CORTEXM_INT_PRIO_SHIFT
}

/* OS_CORTEXM_SetIRQPrio Set new interrupt priority barrier (BASEPRI) */
#define OS_TOOL_SET_IRQ_PRIO_IMPLEMENTATION OS_TOOL_ASM_INLINE
__asm volatile void OS_CORTEXM_SetIRQPrio(register os_uint32_t val)
{
%reg val
!
	lsl val, val, #OS_CORTEXM_INT_PRIO_SHIFT
	msr basepri, val
}

/* OS_CORTEXM_GetCurIRQSource Return source of current interrupt
 * (i.e. IPSR (=Exception number) - 16 (=Exception number of interrupt 0))
 */
#define OS_TOOL_GET_CUR_IRQ_SOURCE_IMPLEMENTATION OS_TOOL_ASM_INLINE
__asm volatile os_uint32_t OS_CORTEXM_GetCurIRQSource(void)
{
! "r0"
	mrs	r0, ipsr
	sub r0, r0, #16
}

/* OS_CORTEXM_CLZ Count leading zeros */
#define OS_TOOL_CLZ_IMPLEMENTATION OS_TOOL_ASM_INLINE
__asm volatile os_int_t OS_CORTEXM_CLZ(register os_uint32_t val)
{
%reg val
! "r0"
	clz r0, val
}

#endif /* !defined(OS_ASM) || !defined(__GNUC__) */

#else /* (OS_USE_DIAB_V7) */

/* CHECK: NOPARSE (assembler code) */

/* OS_DSB() - Issue a dsb instruction.
*/
#define OS_DSB()											\
	do														\
	{														\
		OS_TOOL_ASM_KEYWORD volatile ("dsb"					\
						: /* no result */					\
						: /* no inputs */					\
						: "memory" /* do not reorder */ );	\
	} while (0)

/* OS_ISB() - Issue an isb instruction.
*/
#define OS_ISB()									\
	do												\
	{												\
		OS_TOOL_ASM_KEYWORD volatile ("isb"			\
						: /* no result */			\
						: /* no inputs */			\
						: /* nothing clobbered */);	\
	} while (0)

/* os_stackelement_t OS_CORTEXM_GetSP(void)
 *
 * Get the stackpointer
*/
#define OS_TOOL_GETSP_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_GetSP()										\
	OS_TOOL_EXTENSION_KEYWORD									\
	({															\
		register os_stackelement_t *OS_getSpResult;				\
		OS_TOOL_ASM_KEYWORD volatile ("mov	%[result], r13"		\
							: [result] "=r" (OS_getSpResult)	\
							: /* no inputs */					\
							: /* nothing clobbered */);			\
		OS_getSpResult;											\
	})

/* OS_CORTEXM_DisableIRQ Disable the IRQ-Flag. */
#define OS_TOOL_DISABLE_IRQ_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_DisableIRQ()						\
	{												\
		OS_TOOL_ASM_KEYWORD volatile ("cpsid	i"	\
						: /* no result */			\
						: /* no inputs */			\
						: /* nothing clobbered */);	\
	}

/* OS_CORTEXM_DisableIRQGetState Disable IRQs and return old CPU state (PRIMASK, etc.) */
#define OS_TOOL_DISABLE_IRQ_GET_STATE_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_DisableIRQGetState()							\
	 OS_TOOL_EXTENSION_KEYWORD									\
	 ({															\
		register os_uint32_t OS_DIRQResult;						\
		OS_TOOL_ASM_KEYWORD volatile ("mrs	%[result], primask"	\
						: [result] "=r" (OS_DIRQResult)			\
						: /* no inputs */						\
						: /* nothing clobbered */);				\
		OS_CORTEXM_DisableIRQ();								\
		OS_DIRQResult;											\
	})

/* OS_CORTEXM_SetState Set new value of the CPU state (e.g. CPSR, PRIMASK, etc.) */
#define OS_TOOL_SET_STATE_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_SetState(val)								\
	do															\
	{															\
		register os_uint32_t newPrimask = val;					\
		OS_TOOL_ASM_KEYWORD volatile ("msr primask, %[input]"	\
						: /* no outputs */						\
						: [input] "r" (newPrimask)				\
						: /* nothing clobbered */);				\
	} while(0)

/* OS_CORTEXM_GetIRQPrio Return current interrupt priority barrier (e.g. BASEPRI, etc.) */
#define OS_TOOL_GET_IRQ_PRIO_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_GetIRQPrio()											\
	 OS_TOOL_EXTENSION_KEYWORD											\
	 ({																	\
		register os_uint32_t OS_CurBasepri;								\
		OS_TOOL_ASM_KEYWORD volatile ("mrs	%[result], basepri"			\
						: [result] "=r" (OS_CurBasepri)					\
						: /* no inputs */								\
						: /* nothing clobbered */);						\
		((os_oldlevel_t)(OS_CurBasepri >> OS_CORTEXM_INT_PRIO_SHIFT));	\
	})

/* OS_CORTEXM_SetIRQPrio Set new interrupt priority barrier (BASEPRI) */
#define OS_TOOL_SET_IRQ_PRIO_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_SetIRQPrio(val)											\
	do																		\
	{																		\
		register os_uint32_t newBasepri = val << OS_CORTEXM_INT_PRIO_SHIFT;	\
		OS_TOOL_ASM_KEYWORD volatile ("msr basepri, %[input]"				\
						: /* no outputs */									\
						: [input] "r" (newBasepri)							\
						: /* nothing clobbered */);							\
	} while(0)


/* OS_CORTEXM_GetCurIRQSource Return source of current interrupt
 * (i.e. IPSR (=Exception number) - 16 (=Exception number of interrupt 0))
 */
#define OS_TOOL_GET_CUR_IRQ_SOURCE_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_GetCurIRQSource()							\
	 OS_TOOL_EXTENSION_KEYWORD									\
	 ({															\
		register os_uint32_t OS_CurIpsr;						\
		OS_TOOL_ASM_KEYWORD volatile ("mrs	%[result], ipsr"	\
						: [result] "=r" (OS_CurIpsr)			\
						: /* no inputs */						\
						: /* nothing clobbered */);				\
		OS_CurIpsr - 16;										\
	})

/* OS_CORTEXM_CLZ Count leading zeros */
#define OS_TOOL_CLZ_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_CLZ(val)								\
	({													\
		register os_clzword_t number = val;				\
		register os_int_t zeros;						\
		OS_TOOL_ASM_KEYWORD ("clz %[output], %[input]"	\
				: [output] "=r" (zeros)					\
				: [input] "r" (number)					\
				: /* nothing clobbered */);				\
		zeros;											\
	})


#endif /* OS_USE_DIAB_V7 */

/* OS_PARAM_UNUSED(p) - mark parameter p as unused parameter (or variable).
 * Usage: Function-like.
 */
#define OS_PARAM_UNUSED(p) ((void)(p))


#endif
/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
