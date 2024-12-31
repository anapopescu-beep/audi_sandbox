/* CORTEXM-int-nvic.c
 *
 * This file contains the interrupt routines for the CORTEXM NVIC interrupt controller
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: CORTEXM-int-nvic.c 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <CORTEXM/Os_proto_CORTEXM.h>

/*
 * Base of NVIC's memory mapped IO space. Helper macro to access registers.
*/

/* extract the 32-bit enable-bit number part from the interrupt source number. */
#define OS_CORTEXM_NVIC_SRC_TO_BIT(source)	((source) & 0x1fu)

/* extract the enable-register number part from the interrupt souce number. */
#define OS_CORTEXM_NVIC_SRC_TO_REG(source)	(((source) >> 5u) & 0xfu)

#include <memmap/Os_mm_code_begin.h>

/*
 * OS_CORTEXM_IntSetupIsr(const os_archisr_t *isr)
 *
 * Setup a specific ISR.
 *
 * Parameters:
 * isr	the internal architecture-specific data structure of the ISR
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_CORTEXM_IntSetupIsr(const os_archisr_t *isr)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	OS_CORTEXM_IRQ_ROUTE_EN(isr->source, isr->targetCore);
	/* map priority to source */
	OS_cortexm_int_nvic.ipr[isr->source] =
		(os_uint8_t)(((os_uint32_t)isr->priority) << OS_CORTEXM_INT_PRIO_SHIFT);
}

/*
 * OS_CORTEXM_IntEnableIsr(const os_archisr_t *isr)
 *
 * Enables the ISR by setting the corresponding bit in the
 * interrupt enable set register.
 *
 * Parameters:
 * isr		the internal architecture-specific ISR data structure
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_CORTEXM_IntEnableIsr(const os_archisr_t *isr)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	OS_cortexm_int_nvic.iser[OS_CORTEXM_NVIC_SRC_TO_REG(isr->source)] =
		((os_uint32_t)1u) << OS_CORTEXM_NVIC_SRC_TO_BIT(isr->source);
}

/*
 * OS_CORTEXM_IntDisableIsr(const os_archisr_t *isr)
 *
 * Disables the ISR by setting the corresponding bit in the
 * interrupt enable clear register.
 *
 * Parameters:
 * isr		the internal architecture-specific ISR data structure
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_CORTEXM_IntDisableIsr(const os_archisr_t *isr)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	OS_cortexm_int_nvic.icer[OS_CORTEXM_NVIC_SRC_TO_REG(isr->source)] =
		((os_uint32_t)1u) << OS_CORTEXM_NVIC_SRC_TO_BIT(isr->source);
}

/*
 * OS_CORTEXM_IntClearIsr(const os_archisr_t *isr)
 *
 * Clears the ISR by setting the corresponding bit in the
 * interrupt clear pending register.
 *
 * Parameters:
 * isr		the internal architecture-specific ISR data structure
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_CORTEXM_IntClearIsr(const os_archisr_t *isr)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	OS_cortexm_int_nvic.icpr[OS_CORTEXM_NVIC_SRC_TO_REG(isr->source)] =
		((os_uint32_t)1u) << OS_CORTEXM_NVIC_SRC_TO_BIT(isr->source);
}

/*
 * OS_CORTEXM_IntSetDisablingLevel(os_intstatus_t level)
 *
 * Sets the interrupt level in the NVIC.
 *
 * The function sets the global interrupt level to the specified level.
 * Disables all interrupt sources with a lower or equal priority then level.
 * and enables all interrupt sources with a higher priority then level.
 * Note: For NVIC higher priority then level means priority < level!
 *       E.g. level 0 means highest priority and 255 means lowest priority!
 *
 * Parameters:
 * level	the disabling level to set
 *
 * Return value:
 * The previous disabling level
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_oldlevel_t OS_CORTEXM_IntSetDisablingLevel(os_oldlevel_t level)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	/* disable all interrupts */
	const os_intstatus_t old_state = OS_CORTEXM_DisableIRQGetState();
	const os_oldlevel_t prevDisablingLevel = OS_CORTEXM_GetIRQPrio();

	OS_CORTEXM_SetIRQPrio(level);

	OS_CORTEXM_SetState(old_state);

	return prevDisablingLevel;
}

/*
 * OS_IntDisableConditional()
 *
 * Sets the disabling level to kernel level when it is not already on or above kernel level.
 * Note: For NVIC higher priority then level means priority < level!
 *       E.g. level 0 means highest priority and 255 means lowest priority!
 *
 * Return value:
 * The previous disabling level
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_oldlevel_t OS_IntDisableConditional(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_oldlevel_t prevDisablingLevel = OS_CORTEXM_GetIRQPrio();

	if ((prevDisablingLevel > OS_kernDisableLevel) || (prevDisablingLevel == 0))
	{
		/* OS_kernDisableLevel is of higher priority then previous level */
		prevDisablingLevel = OS_CORTEXM_IntSetDisablingLevel(OS_kernDisableLevel);
	}

	return prevDisablingLevel;
}

/*
 * OS_IntDisableConditionalX()
 *
 * Sets the disabling level to kernel level when it is not already on or above kernel level.
 * Note: For NVIC higher priority then level means priority < level!
 *       E.g. level 0 means highest priority and 255 means lowest priority!
 *
 * Return value:
 * The previous disabling level
 *
 * Prerequisite:
 * The interrupts must already be disabled by setting the I flag (e.g. by OS_CORTEXM_DisableIRQGetState()).
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
os_oldlevel_t OS_IntDisableConditionalX(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_oldlevel_t prevDisablingLevel = OS_CORTEXM_GetIRQPrio();

	if ((prevDisablingLevel > OS_kernDisableLevel) || (prevDisablingLevel == 0))
	{
		/* OS_kernDisableLevel is of higher priority then previous level */
		OS_CORTEXM_SetIRQPrio(OS_kernDisableLevel);
	}

	return prevDisablingLevel;
}

/*
 * void OS_CORTEXM_IntDisableUnknownInterrupt(void)
 *
 * Disable the currently serviced interrupt in an implementation defined manner
 * (e.g. reading the source from an interrupt controller register and adjusting
 * the disable mask).
 *
 * Preconditions:
 * - The interrupt to disable is currently in service.
 * - Interrupts are locked with the interrupt disable flag.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_CORTEXM_IntDisableUnknownInterrupt(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	/* get interrupt source of currently active interrupt (e.g. IPSR, etc.) */
	os_uint32_t curSource = OS_CORTEXM_GetCurIRQSource();
	if (curSource < OS_CORTEXM_NUM_SOURCES)
	{
		OS_cortexm_int_nvic.icer[OS_CORTEXM_NVIC_SRC_TO_REG(curSource)] =
				((os_uint32_t)1u) << OS_CORTEXM_NVIC_SRC_TO_BIT(curSource);
	}
	else
	{
		(void)OS_Panic(OS_PANIC_InvalidIrqSource);
		/* NOT REACHED */
	}
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_CORTEXM_int_nvic_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
