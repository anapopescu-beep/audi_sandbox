/* Os_tool_CORTEXM_ticgt.h - CORTEXM macros for ticgt toolchain
 *
 * This file contains macros (C and assembler) for use with CORTEXM
 * and the ticgt compiler.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: Os_tool_CORTEXM_ticgt.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_TOOL_CORTEXM_TICGT_H
#define OS_TOOL_CORTEXM_TICGT_H

/* OS_DSB() - Issue a dsb instruction.
*/
#define OS_DSB()		\
	do					\
	{					\
		asm ("	dsb");	\
	} while (0)

/* OS_ISB() - Issue an isb instruction.
*/
#define OS_ISB()		\
	do					\
	{					\
		asm ("	isb");	\
	} while (0)


/* os_stackelement_t OS_GetSP(void)
 *
 * Get the stackpointer
*/
#define OS_TOOL_GETSP_IMPLEMENTATION OS_TOOL_ASM_FUNC

/* void OS_CORTEXM_DisableIRQ(void)
 * Disable the IRQ-Flag.
 */
#define OS_TOOL_DISABLE_IRQ_IMPLEMENTATION OS_TOOL_ASM_FUNC

/* os_uint32_t OS_CORTEXM_DisableIRQGetState(void)
 * Disable IRQs and return old CPU state (PRIMASK)
 */
#define OS_TOOL_DISABLE_IRQ_GET_STATE_IMPLEMENTATION OS_TOOL_ASM_FUNC

/* void OS_CORTEXM_SetState(os_uint32_t)
 * Set new value of the CPU state (PRIMASK)
 */
#define OS_TOOL_SET_STATE_IMPLEMENTATION OS_TOOL_ASM_FUNC

/* OS_CORTEXM_GetIRQPrio Return current interrupt priority barrier (BASEPRI) */
#define OS_TOOL_GET_IRQ_PRIO_IMPLEMENTATION OS_TOOL_ASM_FUNC

/* OS_CORTEXM_GetCurIRQSource Return source of current interrupt (IPSR) */
#define OS_TOOL_GET_CUR_IRQ_SOURCE_IMPLEMENTATION OS_TOOL_ASM_FUNC

/* OS_PARAM_UNUSED(p) - mark parameter p as unused parameter (or variable).
 * Usage: Function-like.
 */
#define OS_PARAM_UNUSED(p) ((void)(p))

#endif

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
