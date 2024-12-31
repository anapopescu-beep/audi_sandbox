/* Os_tool_CORTEXM.h - CORTEXM definitions for IAR tool chain.
 *
 * This file encapsulates toolchain abstraction for IAR tool chain.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: Os_tool_CORTEXM_iar.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_TOOL_CORTEXM_IAR_H
#define OS_TOOL_CORTEXM_IAR_H

#ifndef OS_ASM
#include <intrinsics.h>
#endif
#include <CORTEXM/Os_types_CORTEXM.h>

#define OS_DSB()						do { __DSB(); } while (0)

#define OS_ISB()						do { __ISB(); } while (0)

#define OS_TOOL_INLINE_KEYWORD			inline

#define OS_TOOL_ASM_KEYWORD				__asm

/* Macro that evaluates to the symbol at the beginning of the initialized data
 * section. It is used as the destination to initialize the data section in the
 * board file.
*/
#define OS_TOOL_STARTDATA				(DATA$$Base)

/* Macro that evaluates to the symbol one byte beyond of the initialized data
 * section. It is used to mark the end of data initialization in the board
 * file.
*/
#define OS_TOOL_ENDDATA					(DATA$$Limit)

/* Macro that evaluates to the symbol at the beginning of the initialized data
 * section in ROM. It is used as the source for the initialization of the data
 * section in the board file.
*/
#define OS_TOOL_INITDATA				(DATA_init$$Base)

/* Macro that evaluates to the symbol at the beginning of the (anonymous)
 * uninitialized data section. It is used to clear the anonymous bss section in
 * the board file.
*/
#define OS_TOOL_STARTBSS				(BSS$$Base)

/* Macro that evaluates to the symbol one byte beyond the (anonymous)
 * uninitialized data section. It is used to clear the anonymous bss in the
 * board file.
*/
#define OS_TOOL_ENDBSS					(BSS$$Limit)

/* Macro that evaluates to the name of the linker generated symbol referring
 * to the start of the ROM memory
*/
#define OS_TOOL_ROM_START				(__GLBL_ROM_START)

/* Macro that evaluates to the name of the linker generated symbol referring
 * to the end of the ROM memory
*/
#define OS_TOOL_ROM_END					(__GLBL_ROM_END)

/* Macro that evaluates to the name of the linker generated symbol referring
 * to the start of the RAM memory
*/
#define OS_TOOL_RAM_START				(__GLBL_RAM_START)

/* Macro that evaluates to the name of the linker generated symbol referring
 * to the end of the RAM memory
*/
#define OS_TOOL_RAM_END					(__GLBL_RAM_END)

/* Macro that evaluates to the name of the linker generated symbol referring
 * to the start of the I/O region
*/
#define OS_TOOL_IO_START				(__GLBL_IO_START)

/* Macro that evaluates to the name of the linker generated symbol referring
 * to the end of the I/O region
*/
#define OS_TOOL_IO_END					(__GLBL_IO_END)

/* OS_TOOL_MR_* macros are emitted by the generator to refer to private memory
 * sections of applications, tasks and isrs.
*/

/* Macro that evaluates to the name of the linker generated symbol referring
 * to the Start-VMA of memory region <region>.
*/
#define OS_TOOL_MR_START(region)		(data_ ## region ## $$Base)

/* Macro that evaluates to the name of the linker generated symbol referring
 * to the virtual memory address one byte beyond memory region <region>.
*/
#define OS_TOOL_MR_END(region)			(bss_ ## region ## $$Limit)

/* Macro that evaluates to the name of the linker generated symbol referring
 * to the LMA of the data portion of memory region <region>.
*/
#define OS_TOOL_MR_LMA_START(region)	(data_ ## region ## _init$$Base)

/* Macro that evaluates to the name of the linker generated symbol referring
 * to the LMA one byte beyond the initialized data portion of memory region
 * <region>.
*/
#define OS_TOOL_MR_LMA_END(region)		(data_ ## region ## _init$$Limit)

/* Implementation of OS_CORTEXM_GetSP() */
#define OS_TOOL_GETSP_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_GetSP()				((os_stackelement_t *)__get_SP())

/* Implementation of OS_CORTEXM_DisableIRQGetState() */
#define OS_TOOL_DISABLE_IRQ_GET_STATE_IMPLEMENTATION OS_TOOL_ASM_INLINE
#ifndef OS_ASM
static inline os_uint32_t
OS_CORTEXM_DisableIRQGetState(void)
{
	os_uint32_t tmp = (os_uint32_t)__get_PRIMASK();
	__set_PRIMASK(1u);

	return tmp;
}
#endif

/* Implementation of OS_CORTEXM_SetState() */
#define OS_TOOL_SET_STATE_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_SetState(val)		__set_PRIMASK(val)

/* Implementation of OS_CORTEXM_GetIRQPrio() */
#define OS_TOOL_GET_IRQ_PRIO_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_GetIRQPrio()			((os_oldlevel_t)(__get_BASEPRI() >> OS_CORTEXM_INT_PRIO_SHIFT))

/* Implementation of OS_CORTEXM_SetIRQPrio() */
#define OS_TOOL_SET_IRQ_PRIO_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_SetIRQPrio(prio)		__set_BASEPRI((prio) << OS_CORTEXM_INT_PRIO_SHIFT)

/* Implementation of OS_CORTEXM_GetCurIRQSource() */
#define OS_TOOL_GET_CUR_IRQ_SOURCE_IMPLEMENTATION OS_TOOL_ASM_INLINE
#define OS_CORTEXM_GetCurIRQSource()	(__get_IPSR() - 16u)


/* OS_PARAM_UNUSED(p) - mark parameter p as unused parameter (or variable).
 * Usage: Function-like.
*/
#define OS_PARAM_UNUSED(p) /* nothing */

#endif
/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
