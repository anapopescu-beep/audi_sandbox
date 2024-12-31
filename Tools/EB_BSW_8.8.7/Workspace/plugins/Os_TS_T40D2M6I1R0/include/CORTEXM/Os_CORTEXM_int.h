/* Os_CORTEXM_int.h
 *
 * This file defines the generic interface for CORTEXM family interrupt
 * controllers.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_CORTEXM_int.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_CORTEXM_INT_H
#define OS_CORTEXM_INT_H

#include <Os_defs.h>

/* the microkernel handles interrupts on its own. None of this functionality
 * is required here.
 */
#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <CORTEXM/Os_CORTEXM_cpu.h>
#include <Os_types.h>
#include <Os_panic.h>

/* sanity check */
#ifndef OS_CORTEXM_NUM_SOURCES
#error "OS_CORTEXM_NUM_SOURCES not defined, please check/include derivative header."
#endif

/* NVIC lowest interrupt locking level.
 * One lower than the lowest possible priority an IRQ request can have,
 * so that all interrupts are enabled.
*/
#ifndef OS_CORTEXM_ALL_INT_ENABLED_LEVEL
#error "OS_CORTEXM_ALL_INT_ENABLED_LEVEL not defined, please check/include derivative header."
#endif

/* ----------------- Definitions ---------------- */


/*!
 * os_archisr_t
 *
 * A structure describing an ISR to the kernel.
 *
 * For the CORTEXM VIM, the following fields are added to the ROM structure:
 *   source             - the number of the interrupt request of the
 *                        peripheriphal (interrupt source).
 *   priority           - the priority the request is mapped to
 *                        (0=highest priority).
 *   mpuSizeData        - size of the region for the ISR's private data
 *                        (ARMv7 memory protection systems only)
 *   mpuSizeStack       - size of the region for the ISR stack
 *                        (ARMv7 memory protection systems only)
*/

#if (OS_HASMEMPROT == 1)

#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARM)
#define OS_CORTEXM_MPU_SIZE_FIELDS_REQ 1
#elif (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_NXP)
#define OS_CORTEXM_MPU_SIZE_FIELDS_REQ 0
#elif (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)
#define OS_CORTEXM_MPU_SIZE_FIELDS_REQ 0
#else
#error "OS_ARCHISR_INIT needs adjustment for this MPU Type."
#endif

#else /* (OS_HASMEMPROT == 1) */
#define OS_CORTEXM_MPU_SIZE_FIELDS_REQ 0
#endif /* (OS_HASMEMPROT == 1) */

#ifndef OS_ASM
typedef struct os_archisr_s os_archisr_t;

struct os_archisr_s
{
	os_uint16_t source;
	os_oldlevel_t priority;
#if (OS_N_CORES_MAX > 1)
	os_uint8_t targetCore;
#endif
#if (OS_CORTEXM_MPU_SIZE_FIELDS_REQ == 1)
	os_uint8_t mpuSizeData;	/* size of the region for the ISR's private data */
	os_uint8_t mpuSizeStack;	/* size of the region for the task stack */
#endif /* #if OS_CORTEXM_MPU_SIZE_FIELDS_REQ == 1 */
};
#endif /* ! OS_ASM */

#if (OS_CORTEXM_MPU_SIZE_FIELDS_REQ == 1) && (OS_N_CORES_MAX <= 1)
#define OS_ARCHISR_INIT( source, priority, targetCore, mpuSizeData, mpuSizeStack )	\
	{																				\
		(source),																	\
		(priority),																	\
		(mpuSizeData),																\
		(mpuSizeStack)																\
	}
#elif (OS_CORTEXM_MPU_SIZE_FIELDS_REQ == 1) && (OS_N_CORES_MAX > 1)
#define OS_ARCHISR_INIT( source, priority, targetCore, mpuSizeData, mpuSizeStack )	\
	{																				\
		(source),																	\
		(priority),																	\
		(targetCore),																\
		(mpuSizeData),																\
		(mpuSizeStack)																\
	}
#elif (OS_CORTEXM_MPU_SIZE_FIELDS_REQ == 0) && (OS_N_CORES_MAX <= 1)
#define OS_ARCHISR_INIT( source, priority, targetCore )								\
	{																				\
		(source),																	\
		(priority),																	\
	}
#elif (OS_CORTEXM_MPU_SIZE_FIELDS_REQ == 0) && (OS_N_CORES_MAX > 1)
#define OS_ARCHISR_INIT( source, priority, targetCore )								\
	{																				\
		(source),																	\
		(priority)																	\
		(targetCore)																\
	}
#else
#error "Unsupported combination of memory protection support and core number"
#endif

#if (OS_HASMEMPROT == 1)
#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)

#define OS_HAVE_ARCHISRDYN_T    1

#ifndef OS_ASM
typedef struct os_archisrdynamic_s os_archisrdynamic_t;

struct os_archisrdynamic_s
{
	os_cortexm_region_t regions[OS_MPU_DYNAMIC_REGIONS];	/* task-specific regions */
};
#endif

#endif /* (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8) */
#endif /* (OS_HASMEMPROT == 1) */

/* ---------------------------------------------- */

/*!
 * OS_SetupIsr(), OS_EnableIsr(), OS_DisableIsr() and OS_ClearIsr();
 *
 * Setup/enable/disable/clear a specific ISR.
*/
#define OS_SetupIsr(isr)	OS_CORTEXM_IntSetupIsr(&((isr)->arch))
#define OS_EnableIsr(isr)	OS_CORTEXM_IntEnableIsr(&((isr)->arch))
#define OS_DisableIsr(isr)	OS_CORTEXM_IntDisableIsr(&((isr)->arch))
#define OS_ClearIsr(isr)	OS_CORTEXM_IntClearIsr(&((isr)->arch))

/*!
 * OS_IntEnable(), OS_IntDisable(), OS_IntRestore(),
 * OS_IntDisableAll()
 *
 * These routines enable, disable and restore previous state of interrupts.
 * IntEnable and IntDisable both return the old value of the interrupt
 * state for use in a later IntRestore().
 * OS_IntDisableConditional() is the same as OS_IntDisable(), except that it must ensure
 * that the interrupt level is not reduced.
 *
*/
/* disable all interrupts by means of some kind of interrupt level/priority mask/barrier */
#define OS_IntEnable()					OS_CORTEXM_IntSetDisablingLevel(OS_CORTEXM_ALL_INT_ENABLED_LEVEL)
#define OS_IntDisable()					OS_CORTEXM_IntSetDisablingLevel(OS_kernDisableLevel)
#define OS_IntDisableAll()				OS_CORTEXM_IntSetDisablingLevel(OS_intDisableLevelAll)
#define OS_IntRestore(p)				(void) OS_CORTEXM_IntSetDisablingLevel(p)

/* Disable / Restore all interrupts, even cross core ones. */
#define OS_IntDisableMax()				OS_CORTEXM_IntSetDisablingLevel(OS_intDisableLevelMax)

/* A special setting for the default core mapping used by the generator in case
 * of only one core is just needed by some interrupt controllers and should be
 * defined in the interrupt controller's header or in the derivative header. In
 * all other cases, this value will be ignored, so we can safely fall back to 0.
 */
#ifndef OS_CORTEXM_INT_TARGET_DEFAULT
#define OS_CORTEXM_INT_TARGET_DEFAULT 0
#endif

/*!
 * OS_SuspendInterrupts()
 * OS_SuspendInterruptsX()
 *
 * This macro is used by OS_KernSuspendInterrupts()
 *
 * It disables at the specified level, both in the calling context and
 * in the current context.
 *
 * No special mechanism is in place to avoid multiple evaluations of the
 * parameters. However, in practice each parameter is only used once.
 *
 * The normal version is used where interrupts have not been disabled in the
 * kernel function. In this version we save the current PSW and then disable.
 *
 * The X version is used where interrupts have already been disabled in the
 * kernel function.
*/
#define OS_SuspendInterrupts(olp, lvl)							\
		do {													\
			*(olp) = OS_CORTEXM_IntSetDisablingLevel(lvl);		\
		} while(0)

#define OS_SuspendInterruptsX(olp, lvl, is)					\
		do {												\
			*(olp) = (os_oldlevel_t) (is);					\
			(void) OS_CORTEXM_IntSetDisablingLevel(lvl);	\
		} while(0)

/*!
 * OS_ResumeInterrupts()
 *
 * This macro is used by OS_KernResumeInterrupts()
 *
 * It disables at the specified level, both in the calling context and
 * in the current context.
 *
 * No special mechanism is in place to avoid multiple evaluations of the
 * parameters. However, in practice the parameter is only used once.
*/
#define OS_ResumeInterrupts(olp)	(void)OS_CORTEXM_IntSetDisablingLevel(*(olp))


/*!
 * OS_CallIsrDirect()
 *
 * This macro calls an ISR directly.
 *
 * The macro's parameters must be simple variables, not expressions.
 * This should not be a problem, however, because it's only used in the
 * Cat2Entry and Cat2KEntry routines.
 *
*/
#define OS_CallIsrDirect(isr, id)											\
	do {																	\
		os_intstatus_t level;												\
		(id)->c.sp = OS_NULL;												\
		level = OS_CORTEXM_IntSetDisablingLevel((isr)->arch.priority);		\
		(*( (isr)->func))();												\
		(void) OS_CORTEXM_IntSetDisablingLevel(level);						\
	} while(0)


/*!
 * OS_CallIsrIndirect()
 *
 * This macro calls an ISR.
 *
 * If OSEK ISR semantics are specified, the ISR is called directly. In this
 * case an ISR cannot be killed, so an exception trapped in an ISR will
 * cause a shutdown.
 *
 * If Autosar semantics are specified, the ISR is called via a special
 * mechanism that saves the context (typically a stack pointer and other
 * registers, cf. setjmp/longjmp) so that a killed ISR can appear to
 * return correctly.
 * The "special mechanism" is responsible for enabling and disabling
 * nested interrupts. It is important to ensure that the mechanism for
 * detecting a "killed" interrupt (typically the stackLimit in the
 * context) is initialized (possibly to some safe value) before enabling
 * interrupts, otherwise a nested interrupt could kill off this ISR on
 * exit. It is also an error to postpone disabling interrupts on return
 * until after the stackLimit is cleared down.
 *
 * The macro's parameters must be simple variables, not expressions. This
 * should not be a problem, however, because it's only used in the
 * Cat2Entry routine.
 *
*/
#define OS_CallIsrIndirect(isr, id)											\
	do {																	\
		(id)->c.stackLimit =												\
			(os_stackelement_t *)											\
				(															\
					OS_GET_ALIGNED_SP((isr)->arch.mpuSizeStack)				\
				);															\
		OS_SETISRPROTECTION((isr), (id));									\
		OS_CORTEXM_Call(	(isr)->arch.priority,							\
							(os_vfuncu_t) (isr)->func,						\
							&((id)->c.sp),									\
							(id)->c.stackLimit,								\
							OS_CORTEXM_GetTaskIsrAppFlags((isr)),			\
							0												\
					);														\
		OS_CORTEXM_RESETKERNSTACKRW(OS_GET_APP(isr->app));					\
		(id)->c.sp = OS_NULL;												\
		(id)->c.stackLimit = OS_NULL;										\
	} while (0)


/*!
 * void OS_SetIsrResourceLevel(os_prio_t prio)
 *
 * OS_SetIsrResourceLevel() is called by GetResource() and ReleaseResource()
 * to disable interrupts up to the ceiling level of the resource, for
 * a resource that is used in ISRs.
 * It disables at the specified level, both in the current context and
 * in the context that called the system service.
 *
 * We have to compute the locking level from the resource priority.
*/
#define OS_SetIsrResourceLevel(prio)									\
	do																	\
	{																	\
		/* Calculate and set new interrupt lock level. */				\
		os_prio_t newLevel =											\
			( OS_NULLISRPRIO + OS_CORTEXM_ALL_INT_ENABLED_LEVEL )		\
			- (prio);													\
		(void) OS_CORTEXM_IntSetDisablingLevel(newLevel);				\
	}																	\
	while (0)

/*!
 * OS_GetInterruptPriority()
 *
 * This macro returns the current interrupt-locking level. It is used in
 * GetResource() to save the old level before setting the new.
 * Therefore we reverse the channel value.
*/
#define OS_GetInterruptPriority(is)  \
		OS_IsrLevelToPrio(OS_CORTEXM_ALL_INT_ENABLED_LEVEL - (is))

/*!
 * OS_GetIsrResPrio()
 *
 * Return the ISR's priority for use in GetResource. The priority
 * returned assumes that higher numbers are a higher priority.
 * Therefore we reverse the channel value.
 */
#define OS_GetIsrResPrio(isrp)	\
		((os_prio_t)OS_CORTEXM_ALL_INT_ENABLED_LEVEL - (isrp)->arch.priority)

#ifdef OS_EXCLUDE_ERRORHANDLING
#define OS_CORTEXM_UNKNOWN_INTERRUPT boardInvalidInterrupt
#else
#define OS_CORTEXM_UNKNOWN_INTERRUPT OS_UnknownInterrupt
#endif /* OS_EXCLUDE_ERRORHANDLING */

#ifndef OS_ASM

/* NVIC Interrupt Memory Mapped IO Space definition (registers). */
typedef struct os_cortexm_int_nvic_reg_s os_cortexm_int_nvic_reg_t;
struct os_cortexm_int_nvic_reg_s
{
	os_reg32_t	iser[16];	/* 0x000-0x03f interrupt set enable register (rw) */
	os_uint32_t	reserved1[16];	/* 0x040-0x07f reserved */
	os_reg32_t	icer[16];	/* 0x080-0x0bf interrupt clear enable register (rw) */
	os_uint32_t	reserved2[16];	/* 0x0c0-0x0ff reserved */
	os_reg32_t	ispr[16];	/* 0x100-0x13f interrupt set pending register (rw) */
	os_uint32_t	reserved3[16];	/* 0x140-0x17f reserved */
	os_reg32_t	icpr[16];	/* 0x180-0x1bf interrupt clear pending register (rw) */
	os_uint32_t	reserved4[16];	/* 0x1c0-0x1ff reserved */
	os_reg32_t	iabr[16];	/* 0x200-0x23f interrupt active bit register (ro) */
	os_uint32_t	reserved5[48];	/* 0x240-0x2ff reserved */
	os_reg8_t	ipr[496];	/* 0x300-0x4ef interrupt priority register (rw) */
};

/* CHECK: RULE 402 OFF (not a "constant like" macro) */
#define OS_cortexm_int_nvic \
	(*(os_cortexm_int_nvic_reg_t *)(0xe000e100u))
/* CHECK: RULE 402 ON */

/*!
 * OS_CORTEXM_IntReturnFromInterrupt(void);
 *
 * Return from an Interrupt.
*/
extern void OS_CORTEXM_IntReturnFromInterrupt(void);

/*!
 * OS_CORTEXM_IntCat1Exit(void);
 *
 * Set OS_GetKernelData()->inKernel to appropriate value
 * and return from Interrupt.
 */
extern void OS_CORTEXM_IntCat1Exit(void);

/*!
 * OS_CORTEXM_IntCat2Exit
 *
 * Return from category 2 interrupt.
*/
extern void OS_CORTEXM_IntCat2Exit(void);

/*!
 * OS_CORTEXM_IntSetupIsr(const os_archisr_t *isr)
 *
 * Setup a specific ISR.
 *
 * Parameters:
 * isr	the internal architecture-specific data structure of the ISR
 */
extern void OS_CORTEXM_IntSetupIsr(const os_archisr_t *);

/*!
 * OS_CORTEXM_IntEnableIsr(const os_archisr_t *isr)
 *
 * Enables given ISR by setting the enable mask. The IRQ must have
 * been setup before with OS_CORTEXM_IntSetupIsr.
 *
 * Parameters:
 * isr		the internal architecture-specific ISR data structure
 */
extern void OS_CORTEXM_IntEnableIsr(const os_archisr_t *);

/*!
 * OS_CORTEXM_IntDisableIsr(const os_archisr_t *isr)
 *
 * Disables the ISR by deleting the corresponding bit
 * in the internal enable mask.
 *
 * Parameters:
 * isr		the internal architecture-specific ISR data structure
 */
extern void OS_CORTEXM_IntDisableIsr(const os_archisr_t *);

/*!
 * OS_CORTEXM_IntClearIsr(const os_archisr_t *isr)
 *
 * Clears the ISR by setting the corresponding bit in the
 * interrupt clear pending register.
 *
 * Parameters:
 * isr		the internal architecture-specific ISR data structure
*/
extern void OS_CORTEXM_IntClearIsr(const os_archisr_t *);

/*!
 * OS_CORTEXM_IntSetDisablingLevel(os_intstatus_t level)
 *
 * Sets the disabling level in the interrupt controller.
 *
 * The function disables all interrupts with priority <= level
 * and enables all configured interrupts with priority > level.
 *
 * Parameters:
 * level	the disabling level to set
 *
 * Return value:
 * The previous disabling level
 */
extern os_oldlevel_t OS_CORTEXM_IntSetDisablingLevel(os_oldlevel_t);

/*!
 * OS_IntDisableConditional()
 *
 * Sets the disabling level to kernel level when it is not already on or above
 * kernel level.
 *
 * Return value:
 * The previous disabling level.
 */
extern os_oldlevel_t OS_IntDisableConditional(void);

/*!
 * OS_IntDisableConditionalX()
 *
 * Sets the disabling level to kernel level when it is not already on or above
 * kernel level.
 *
 * Return value:
 * The previous disabling level.
 *
 * Prerequisite:
 * The interrupts must already be disabled by setting the I flag (e.g. by OS_CORTEXM_DisableIRQGetState()).
 */
extern os_oldlevel_t OS_IntDisableConditionalX(void);

/*!
 * void OS_CORTEXM_IntDisableUnknownInterrupt(void)
 *
 * Disable the currently serviced interrupt in an implementation defined
 * manner (e.g. reading the source from an interrupt controller register
 * and adjusting the disable mask).
 *
 * Preconditions:
 * - The interrupt to disable is currently in service.
 * - Interrupts are locked with the interrupt disable flag.
 */
extern void OS_CORTEXM_IntDisableUnknownInterrupt(void);

#if (OS_CORTEXM_INT_MUX == OS_CORTEXM_INT_MUX_CPUSS)
/*!
 * void OS_CORTEXM_IntSetupMux(void)
 *
 * Enables the CPU interrupts used for the interrupt multiplexer and
 * assigns each of them a fixed priority. Multiplexed system interrupts
 * will configure their priority by choosing the CPU interrupt accordingly.
 */
extern void OS_CORTEXM_IntSetupMux(void);

/*!
 * void OS_CORTEXM_IntClearIcpr(os_uint32_t)
 *
 * Directly clears an interrupt pending bit for the provided CPU IRQ.
 */
extern void OS_CORTEXM_IntClearIcpr(os_uint32_t);
#endif


/* Interrupt vectors. */
#if (0 < OS_CORTEXM_NUM_SOURCES)
extern void OS_CORTEXM_IRQ_00(void);
extern void OS_CORTEXM_IRQ_01(void);
extern void OS_CORTEXM_IRQ_02(void);
extern void OS_CORTEXM_IRQ_03(void);
extern void OS_CORTEXM_IRQ_04(void);
extern void OS_CORTEXM_IRQ_05(void);
extern void OS_CORTEXM_IRQ_06(void);
extern void OS_CORTEXM_IRQ_07(void);
extern void OS_CORTEXM_IRQ_08(void);
extern void OS_CORTEXM_IRQ_09(void);
extern void OS_CORTEXM_IRQ_0a(void);
extern void OS_CORTEXM_IRQ_0b(void);
extern void OS_CORTEXM_IRQ_0c(void);
extern void OS_CORTEXM_IRQ_0d(void);
extern void OS_CORTEXM_IRQ_0e(void);
extern void OS_CORTEXM_IRQ_0f(void);
#endif /* (0 < OS_CORTEXM_NUM_SOURCES) */

#if (16 < OS_CORTEXM_NUM_SOURCES)
extern void OS_CORTEXM_IRQ_10(void);
extern void OS_CORTEXM_IRQ_11(void);
extern void OS_CORTEXM_IRQ_12(void);
extern void OS_CORTEXM_IRQ_13(void);
extern void OS_CORTEXM_IRQ_14(void);
extern void OS_CORTEXM_IRQ_15(void);
extern void OS_CORTEXM_IRQ_16(void);
extern void OS_CORTEXM_IRQ_17(void);
extern void OS_CORTEXM_IRQ_18(void);
extern void OS_CORTEXM_IRQ_19(void);
extern void OS_CORTEXM_IRQ_1a(void);
extern void OS_CORTEXM_IRQ_1b(void);
extern void OS_CORTEXM_IRQ_1c(void);
extern void OS_CORTEXM_IRQ_1d(void);
extern void OS_CORTEXM_IRQ_1e(void);
extern void OS_CORTEXM_IRQ_1f(void);
#endif /* (16 < OS_CORTEXM_NUM_SOURCES) */

#if (32 < OS_CORTEXM_NUM_SOURCES)
extern void OS_CORTEXM_IRQ_20(void);
extern void OS_CORTEXM_IRQ_21(void);
extern void OS_CORTEXM_IRQ_22(void);
extern void OS_CORTEXM_IRQ_23(void);
extern void OS_CORTEXM_IRQ_24(void);
extern void OS_CORTEXM_IRQ_25(void);
extern void OS_CORTEXM_IRQ_26(void);
extern void OS_CORTEXM_IRQ_27(void);
extern void OS_CORTEXM_IRQ_28(void);
extern void OS_CORTEXM_IRQ_29(void);
extern void OS_CORTEXM_IRQ_2a(void);
extern void OS_CORTEXM_IRQ_2b(void);
extern void OS_CORTEXM_IRQ_2c(void);
extern void OS_CORTEXM_IRQ_2d(void);
extern void OS_CORTEXM_IRQ_2e(void);
extern void OS_CORTEXM_IRQ_2f(void);
extern void OS_CORTEXM_IRQ_30(void);
extern void OS_CORTEXM_IRQ_31(void);
extern void OS_CORTEXM_IRQ_32(void);
extern void OS_CORTEXM_IRQ_33(void);
extern void OS_CORTEXM_IRQ_34(void);
extern void OS_CORTEXM_IRQ_35(void);
extern void OS_CORTEXM_IRQ_36(void);
extern void OS_CORTEXM_IRQ_37(void);
extern void OS_CORTEXM_IRQ_38(void);
extern void OS_CORTEXM_IRQ_39(void);
extern void OS_CORTEXM_IRQ_3a(void);
extern void OS_CORTEXM_IRQ_3b(void);
extern void OS_CORTEXM_IRQ_3c(void);
extern void OS_CORTEXM_IRQ_3d(void);
extern void OS_CORTEXM_IRQ_3e(void);
extern void OS_CORTEXM_IRQ_3f(void);
#endif /* (32 < OS_CORTEXM_NUM_SOURCES) */

#if (64 < OS_CORTEXM_NUM_SOURCES)
extern void OS_CORTEXM_IRQ_40(void);
extern void OS_CORTEXM_IRQ_41(void);
extern void OS_CORTEXM_IRQ_42(void);
extern void OS_CORTEXM_IRQ_43(void);
extern void OS_CORTEXM_IRQ_44(void);
extern void OS_CORTEXM_IRQ_45(void);
extern void OS_CORTEXM_IRQ_46(void);
extern void OS_CORTEXM_IRQ_47(void);
extern void OS_CORTEXM_IRQ_48(void);
extern void OS_CORTEXM_IRQ_49(void);
extern void OS_CORTEXM_IRQ_4a(void);
extern void OS_CORTEXM_IRQ_4b(void);
extern void OS_CORTEXM_IRQ_4c(void);
extern void OS_CORTEXM_IRQ_4d(void);
extern void OS_CORTEXM_IRQ_4e(void);
extern void OS_CORTEXM_IRQ_4f(void);
extern void OS_CORTEXM_IRQ_50(void);
extern void OS_CORTEXM_IRQ_51(void);
extern void OS_CORTEXM_IRQ_52(void);
extern void OS_CORTEXM_IRQ_53(void);
extern void OS_CORTEXM_IRQ_54(void);
extern void OS_CORTEXM_IRQ_55(void);
extern void OS_CORTEXM_IRQ_56(void);
extern void OS_CORTEXM_IRQ_57(void);
extern void OS_CORTEXM_IRQ_58(void);
extern void OS_CORTEXM_IRQ_59(void);
extern void OS_CORTEXM_IRQ_5a(void);
extern void OS_CORTEXM_IRQ_5b(void);
extern void OS_CORTEXM_IRQ_5c(void);
extern void OS_CORTEXM_IRQ_5d(void);
extern void OS_CORTEXM_IRQ_5e(void);
extern void OS_CORTEXM_IRQ_5f(void);
extern void OS_CORTEXM_IRQ_60(void);
extern void OS_CORTEXM_IRQ_61(void);
extern void OS_CORTEXM_IRQ_62(void);
extern void OS_CORTEXM_IRQ_63(void);
extern void OS_CORTEXM_IRQ_64(void);
extern void OS_CORTEXM_IRQ_65(void);
extern void OS_CORTEXM_IRQ_66(void);
extern void OS_CORTEXM_IRQ_67(void);
extern void OS_CORTEXM_IRQ_68(void);
extern void OS_CORTEXM_IRQ_69(void);
extern void OS_CORTEXM_IRQ_6a(void);
extern void OS_CORTEXM_IRQ_6b(void);
extern void OS_CORTEXM_IRQ_6c(void);
extern void OS_CORTEXM_IRQ_6d(void);
extern void OS_CORTEXM_IRQ_6e(void);
extern void OS_CORTEXM_IRQ_6f(void);
extern void OS_CORTEXM_IRQ_70(void);
extern void OS_CORTEXM_IRQ_71(void);
extern void OS_CORTEXM_IRQ_72(void);
extern void OS_CORTEXM_IRQ_73(void);
extern void OS_CORTEXM_IRQ_74(void);
extern void OS_CORTEXM_IRQ_75(void);
extern void OS_CORTEXM_IRQ_76(void);
extern void OS_CORTEXM_IRQ_77(void);
extern void OS_CORTEXM_IRQ_78(void);
extern void OS_CORTEXM_IRQ_79(void);
extern void OS_CORTEXM_IRQ_7a(void);
extern void OS_CORTEXM_IRQ_7b(void);
extern void OS_CORTEXM_IRQ_7c(void);
extern void OS_CORTEXM_IRQ_7d(void);
extern void OS_CORTEXM_IRQ_7e(void);
extern void OS_CORTEXM_IRQ_7f(void);
#endif /* (64 < OS_CORTEXM_NUM_SOURCES) */

#if (128 < OS_CORTEXM_NUM_SOURCES)
extern void OS_CORTEXM_IRQ_80(void);
extern void OS_CORTEXM_IRQ_81(void);
extern void OS_CORTEXM_IRQ_82(void);
extern void OS_CORTEXM_IRQ_83(void);
extern void OS_CORTEXM_IRQ_84(void);
extern void OS_CORTEXM_IRQ_85(void);
extern void OS_CORTEXM_IRQ_86(void);
extern void OS_CORTEXM_IRQ_87(void);
extern void OS_CORTEXM_IRQ_88(void);
extern void OS_CORTEXM_IRQ_89(void);
extern void OS_CORTEXM_IRQ_8a(void);
extern void OS_CORTEXM_IRQ_8b(void);
extern void OS_CORTEXM_IRQ_8c(void);
extern void OS_CORTEXM_IRQ_8d(void);
extern void OS_CORTEXM_IRQ_8e(void);
extern void OS_CORTEXM_IRQ_8f(void);
extern void OS_CORTEXM_IRQ_90(void);
extern void OS_CORTEXM_IRQ_91(void);
extern void OS_CORTEXM_IRQ_92(void);
extern void OS_CORTEXM_IRQ_93(void);
extern void OS_CORTEXM_IRQ_94(void);
extern void OS_CORTEXM_IRQ_95(void);
extern void OS_CORTEXM_IRQ_96(void);
extern void OS_CORTEXM_IRQ_97(void);
extern void OS_CORTEXM_IRQ_98(void);
extern void OS_CORTEXM_IRQ_99(void);
extern void OS_CORTEXM_IRQ_9a(void);
extern void OS_CORTEXM_IRQ_9b(void);
extern void OS_CORTEXM_IRQ_9c(void);
extern void OS_CORTEXM_IRQ_9d(void);
extern void OS_CORTEXM_IRQ_9e(void);
extern void OS_CORTEXM_IRQ_9f(void);
extern void OS_CORTEXM_IRQ_a0(void);
extern void OS_CORTEXM_IRQ_a1(void);
extern void OS_CORTEXM_IRQ_a2(void);
extern void OS_CORTEXM_IRQ_a3(void);
extern void OS_CORTEXM_IRQ_a4(void);
extern void OS_CORTEXM_IRQ_a5(void);
extern void OS_CORTEXM_IRQ_a6(void);
extern void OS_CORTEXM_IRQ_a7(void);
extern void OS_CORTEXM_IRQ_a8(void);
extern void OS_CORTEXM_IRQ_a9(void);
extern void OS_CORTEXM_IRQ_aa(void);
extern void OS_CORTEXM_IRQ_ab(void);
extern void OS_CORTEXM_IRQ_ac(void);
extern void OS_CORTEXM_IRQ_ad(void);
extern void OS_CORTEXM_IRQ_ae(void);
extern void OS_CORTEXM_IRQ_af(void);
extern void OS_CORTEXM_IRQ_b0(void);
extern void OS_CORTEXM_IRQ_b1(void);
extern void OS_CORTEXM_IRQ_b2(void);
extern void OS_CORTEXM_IRQ_b3(void);
extern void OS_CORTEXM_IRQ_b4(void);
extern void OS_CORTEXM_IRQ_b5(void);
extern void OS_CORTEXM_IRQ_b6(void);
extern void OS_CORTEXM_IRQ_b7(void);
extern void OS_CORTEXM_IRQ_b8(void);
extern void OS_CORTEXM_IRQ_b9(void);
extern void OS_CORTEXM_IRQ_ba(void);
extern void OS_CORTEXM_IRQ_bb(void);
extern void OS_CORTEXM_IRQ_bc(void);
extern void OS_CORTEXM_IRQ_bd(void);
extern void OS_CORTEXM_IRQ_be(void);
extern void OS_CORTEXM_IRQ_bf(void);
extern void OS_CORTEXM_IRQ_c0(void);
extern void OS_CORTEXM_IRQ_c1(void);
extern void OS_CORTEXM_IRQ_c2(void);
extern void OS_CORTEXM_IRQ_c3(void);
extern void OS_CORTEXM_IRQ_c4(void);
extern void OS_CORTEXM_IRQ_c5(void);
extern void OS_CORTEXM_IRQ_c6(void);
extern void OS_CORTEXM_IRQ_c7(void);
extern void OS_CORTEXM_IRQ_c8(void);
extern void OS_CORTEXM_IRQ_c9(void);
extern void OS_CORTEXM_IRQ_ca(void);
extern void OS_CORTEXM_IRQ_cb(void);
extern void OS_CORTEXM_IRQ_cc(void);
extern void OS_CORTEXM_IRQ_cd(void);
extern void OS_CORTEXM_IRQ_ce(void);
extern void OS_CORTEXM_IRQ_cf(void);
extern void OS_CORTEXM_IRQ_d0(void);
extern void OS_CORTEXM_IRQ_d1(void);
extern void OS_CORTEXM_IRQ_d2(void);
extern void OS_CORTEXM_IRQ_d3(void);
extern void OS_CORTEXM_IRQ_d4(void);
extern void OS_CORTEXM_IRQ_d5(void);
extern void OS_CORTEXM_IRQ_d6(void);
extern void OS_CORTEXM_IRQ_d7(void);
extern void OS_CORTEXM_IRQ_d8(void);
extern void OS_CORTEXM_IRQ_d9(void);
extern void OS_CORTEXM_IRQ_da(void);
extern void OS_CORTEXM_IRQ_db(void);
extern void OS_CORTEXM_IRQ_dc(void);
extern void OS_CORTEXM_IRQ_dd(void);
extern void OS_CORTEXM_IRQ_de(void);
extern void OS_CORTEXM_IRQ_df(void);
extern void OS_CORTEXM_IRQ_e0(void);
extern void OS_CORTEXM_IRQ_e1(void);
extern void OS_CORTEXM_IRQ_e2(void);
extern void OS_CORTEXM_IRQ_e3(void);
extern void OS_CORTEXM_IRQ_e4(void);
extern void OS_CORTEXM_IRQ_e5(void);
extern void OS_CORTEXM_IRQ_e6(void);
extern void OS_CORTEXM_IRQ_e7(void);
extern void OS_CORTEXM_IRQ_e8(void);
extern void OS_CORTEXM_IRQ_e9(void);
extern void OS_CORTEXM_IRQ_ea(void);
extern void OS_CORTEXM_IRQ_eb(void);
extern void OS_CORTEXM_IRQ_ec(void);
extern void OS_CORTEXM_IRQ_ed(void);
extern void OS_CORTEXM_IRQ_ee(void);
extern void OS_CORTEXM_IRQ_ef(void);
extern void OS_CORTEXM_IRQ_f0(void);
extern void OS_CORTEXM_IRQ_f1(void);
extern void OS_CORTEXM_IRQ_f2(void);
extern void OS_CORTEXM_IRQ_f3(void);
extern void OS_CORTEXM_IRQ_f4(void);
extern void OS_CORTEXM_IRQ_f5(void);
extern void OS_CORTEXM_IRQ_f6(void);
extern void OS_CORTEXM_IRQ_f7(void);
extern void OS_CORTEXM_IRQ_f8(void);
extern void OS_CORTEXM_IRQ_f9(void);
extern void OS_CORTEXM_IRQ_fa(void);
extern void OS_CORTEXM_IRQ_fb(void);
extern void OS_CORTEXM_IRQ_fc(void);
extern void OS_CORTEXM_IRQ_fd(void);
extern void OS_CORTEXM_IRQ_fe(void);
extern void OS_CORTEXM_IRQ_ff(void);
#endif /* (128 < OS_CORTEXM_NUM_SOURCES) */

#if (256 < OS_CORTEXM_NUM_SOURCES)
extern void OS_CORTEXM_IRQ_100(void);
extern void OS_CORTEXM_IRQ_101(void);
extern void OS_CORTEXM_IRQ_102(void);
extern void OS_CORTEXM_IRQ_103(void);
extern void OS_CORTEXM_IRQ_104(void);
extern void OS_CORTEXM_IRQ_105(void);
extern void OS_CORTEXM_IRQ_106(void);
extern void OS_CORTEXM_IRQ_107(void);
extern void OS_CORTEXM_IRQ_108(void);
extern void OS_CORTEXM_IRQ_109(void);
extern void OS_CORTEXM_IRQ_10a(void);
extern void OS_CORTEXM_IRQ_10b(void);
extern void OS_CORTEXM_IRQ_10c(void);
extern void OS_CORTEXM_IRQ_10d(void);
extern void OS_CORTEXM_IRQ_10e(void);
extern void OS_CORTEXM_IRQ_10f(void);
extern void OS_CORTEXM_IRQ_110(void);
extern void OS_CORTEXM_IRQ_111(void);
extern void OS_CORTEXM_IRQ_112(void);
extern void OS_CORTEXM_IRQ_113(void);
extern void OS_CORTEXM_IRQ_114(void);
extern void OS_CORTEXM_IRQ_115(void);
extern void OS_CORTEXM_IRQ_116(void);
extern void OS_CORTEXM_IRQ_117(void);
extern void OS_CORTEXM_IRQ_118(void);
extern void OS_CORTEXM_IRQ_119(void);
extern void OS_CORTEXM_IRQ_11a(void);
extern void OS_CORTEXM_IRQ_11b(void);
extern void OS_CORTEXM_IRQ_11c(void);
extern void OS_CORTEXM_IRQ_11d(void);
extern void OS_CORTEXM_IRQ_11e(void);
extern void OS_CORTEXM_IRQ_11f(void);
extern void OS_CORTEXM_IRQ_120(void);
extern void OS_CORTEXM_IRQ_121(void);
extern void OS_CORTEXM_IRQ_122(void);
extern void OS_CORTEXM_IRQ_123(void);
extern void OS_CORTEXM_IRQ_124(void);
extern void OS_CORTEXM_IRQ_125(void);
extern void OS_CORTEXM_IRQ_126(void);
extern void OS_CORTEXM_IRQ_127(void);
extern void OS_CORTEXM_IRQ_128(void);
extern void OS_CORTEXM_IRQ_129(void);
extern void OS_CORTEXM_IRQ_12a(void);
extern void OS_CORTEXM_IRQ_12b(void);
extern void OS_CORTEXM_IRQ_12c(void);
extern void OS_CORTEXM_IRQ_12d(void);
extern void OS_CORTEXM_IRQ_12e(void);
extern void OS_CORTEXM_IRQ_12f(void);
extern void OS_CORTEXM_IRQ_130(void);
extern void OS_CORTEXM_IRQ_131(void);
extern void OS_CORTEXM_IRQ_132(void);
extern void OS_CORTEXM_IRQ_133(void);
extern void OS_CORTEXM_IRQ_134(void);
extern void OS_CORTEXM_IRQ_135(void);
extern void OS_CORTEXM_IRQ_136(void);
extern void OS_CORTEXM_IRQ_137(void);
extern void OS_CORTEXM_IRQ_138(void);
extern void OS_CORTEXM_IRQ_139(void);
extern void OS_CORTEXM_IRQ_13a(void);
extern void OS_CORTEXM_IRQ_13b(void);
extern void OS_CORTEXM_IRQ_13c(void);
extern void OS_CORTEXM_IRQ_13d(void);
extern void OS_CORTEXM_IRQ_13e(void);
extern void OS_CORTEXM_IRQ_13f(void);
extern void OS_CORTEXM_IRQ_140(void);
extern void OS_CORTEXM_IRQ_141(void);
extern void OS_CORTEXM_IRQ_142(void);
extern void OS_CORTEXM_IRQ_143(void);
extern void OS_CORTEXM_IRQ_144(void);
extern void OS_CORTEXM_IRQ_145(void);
extern void OS_CORTEXM_IRQ_146(void);
extern void OS_CORTEXM_IRQ_147(void);
extern void OS_CORTEXM_IRQ_148(void);
extern void OS_CORTEXM_IRQ_149(void);
extern void OS_CORTEXM_IRQ_14a(void);
extern void OS_CORTEXM_IRQ_14b(void);
extern void OS_CORTEXM_IRQ_14c(void);
extern void OS_CORTEXM_IRQ_14d(void);
extern void OS_CORTEXM_IRQ_14e(void);
extern void OS_CORTEXM_IRQ_14f(void);
extern void OS_CORTEXM_IRQ_150(void);
extern void OS_CORTEXM_IRQ_151(void);
extern void OS_CORTEXM_IRQ_152(void);
extern void OS_CORTEXM_IRQ_153(void);
extern void OS_CORTEXM_IRQ_154(void);
extern void OS_CORTEXM_IRQ_155(void);
extern void OS_CORTEXM_IRQ_156(void);
extern void OS_CORTEXM_IRQ_157(void);
extern void OS_CORTEXM_IRQ_158(void);
extern void OS_CORTEXM_IRQ_159(void);
extern void OS_CORTEXM_IRQ_15a(void);
extern void OS_CORTEXM_IRQ_15b(void);
extern void OS_CORTEXM_IRQ_15c(void);
extern void OS_CORTEXM_IRQ_15d(void);
extern void OS_CORTEXM_IRQ_15e(void);
extern void OS_CORTEXM_IRQ_15f(void);
extern void OS_CORTEXM_IRQ_160(void);
extern void OS_CORTEXM_IRQ_161(void);
extern void OS_CORTEXM_IRQ_162(void);
extern void OS_CORTEXM_IRQ_163(void);
extern void OS_CORTEXM_IRQ_164(void);
extern void OS_CORTEXM_IRQ_165(void);
extern void OS_CORTEXM_IRQ_166(void);
extern void OS_CORTEXM_IRQ_167(void);
extern void OS_CORTEXM_IRQ_168(void);
extern void OS_CORTEXM_IRQ_169(void);
extern void OS_CORTEXM_IRQ_16a(void);
extern void OS_CORTEXM_IRQ_16b(void);
extern void OS_CORTEXM_IRQ_16c(void);
extern void OS_CORTEXM_IRQ_16d(void);
extern void OS_CORTEXM_IRQ_16e(void);
extern void OS_CORTEXM_IRQ_16f(void);
extern void OS_CORTEXM_IRQ_170(void);
extern void OS_CORTEXM_IRQ_171(void);
extern void OS_CORTEXM_IRQ_172(void);
extern void OS_CORTEXM_IRQ_173(void);
extern void OS_CORTEXM_IRQ_174(void);
extern void OS_CORTEXM_IRQ_175(void);
extern void OS_CORTEXM_IRQ_176(void);
extern void OS_CORTEXM_IRQ_177(void);
extern void OS_CORTEXM_IRQ_178(void);
extern void OS_CORTEXM_IRQ_179(void);
extern void OS_CORTEXM_IRQ_17a(void);
extern void OS_CORTEXM_IRQ_17b(void);
extern void OS_CORTEXM_IRQ_17c(void);
extern void OS_CORTEXM_IRQ_17d(void);
extern void OS_CORTEXM_IRQ_17e(void);
extern void OS_CORTEXM_IRQ_17f(void);
extern void OS_CORTEXM_IRQ_180(void);
extern void OS_CORTEXM_IRQ_181(void);
extern void OS_CORTEXM_IRQ_182(void);
extern void OS_CORTEXM_IRQ_183(void);
extern void OS_CORTEXM_IRQ_184(void);
extern void OS_CORTEXM_IRQ_185(void);
extern void OS_CORTEXM_IRQ_186(void);
extern void OS_CORTEXM_IRQ_187(void);
extern void OS_CORTEXM_IRQ_188(void);
extern void OS_CORTEXM_IRQ_189(void);
extern void OS_CORTEXM_IRQ_18a(void);
extern void OS_CORTEXM_IRQ_18b(void);
extern void OS_CORTEXM_IRQ_18c(void);
extern void OS_CORTEXM_IRQ_18d(void);
extern void OS_CORTEXM_IRQ_18e(void);
extern void OS_CORTEXM_IRQ_18f(void);
extern void OS_CORTEXM_IRQ_190(void);
extern void OS_CORTEXM_IRQ_191(void);
extern void OS_CORTEXM_IRQ_192(void);
extern void OS_CORTEXM_IRQ_193(void);
extern void OS_CORTEXM_IRQ_194(void);
extern void OS_CORTEXM_IRQ_195(void);
extern void OS_CORTEXM_IRQ_196(void);
extern void OS_CORTEXM_IRQ_197(void);
extern void OS_CORTEXM_IRQ_198(void);
extern void OS_CORTEXM_IRQ_199(void);
extern void OS_CORTEXM_IRQ_19a(void);
extern void OS_CORTEXM_IRQ_19b(void);
extern void OS_CORTEXM_IRQ_19c(void);
extern void OS_CORTEXM_IRQ_19d(void);
extern void OS_CORTEXM_IRQ_19e(void);
extern void OS_CORTEXM_IRQ_19f(void);
extern void OS_CORTEXM_IRQ_1a0(void);
extern void OS_CORTEXM_IRQ_1a1(void);
extern void OS_CORTEXM_IRQ_1a2(void);
extern void OS_CORTEXM_IRQ_1a3(void);
extern void OS_CORTEXM_IRQ_1a4(void);
extern void OS_CORTEXM_IRQ_1a5(void);
extern void OS_CORTEXM_IRQ_1a6(void);
extern void OS_CORTEXM_IRQ_1a7(void);
extern void OS_CORTEXM_IRQ_1a8(void);
extern void OS_CORTEXM_IRQ_1a9(void);
extern void OS_CORTEXM_IRQ_1aa(void);
extern void OS_CORTEXM_IRQ_1ab(void);
extern void OS_CORTEXM_IRQ_1ac(void);
extern void OS_CORTEXM_IRQ_1ad(void);
extern void OS_CORTEXM_IRQ_1ae(void);
extern void OS_CORTEXM_IRQ_1af(void);
extern void OS_CORTEXM_IRQ_1b0(void);
extern void OS_CORTEXM_IRQ_1b1(void);
extern void OS_CORTEXM_IRQ_1b2(void);
extern void OS_CORTEXM_IRQ_1b3(void);
extern void OS_CORTEXM_IRQ_1b4(void);
extern void OS_CORTEXM_IRQ_1b5(void);
extern void OS_CORTEXM_IRQ_1b6(void);
extern void OS_CORTEXM_IRQ_1b7(void);
extern void OS_CORTEXM_IRQ_1b8(void);
extern void OS_CORTEXM_IRQ_1b9(void);
extern void OS_CORTEXM_IRQ_1ba(void);
extern void OS_CORTEXM_IRQ_1bb(void);
extern void OS_CORTEXM_IRQ_1bc(void);
extern void OS_CORTEXM_IRQ_1bd(void);
extern void OS_CORTEXM_IRQ_1be(void);
extern void OS_CORTEXM_IRQ_1bf(void);
extern void OS_CORTEXM_IRQ_1c0(void);
extern void OS_CORTEXM_IRQ_1c1(void);
extern void OS_CORTEXM_IRQ_1c2(void);
extern void OS_CORTEXM_IRQ_1c3(void);
extern void OS_CORTEXM_IRQ_1c4(void);
extern void OS_CORTEXM_IRQ_1c5(void);
extern void OS_CORTEXM_IRQ_1c6(void);
extern void OS_CORTEXM_IRQ_1c7(void);
extern void OS_CORTEXM_IRQ_1c8(void);
extern void OS_CORTEXM_IRQ_1c9(void);
extern void OS_CORTEXM_IRQ_1ca(void);
extern void OS_CORTEXM_IRQ_1cb(void);
extern void OS_CORTEXM_IRQ_1cc(void);
extern void OS_CORTEXM_IRQ_1cd(void);
extern void OS_CORTEXM_IRQ_1ce(void);
extern void OS_CORTEXM_IRQ_1cf(void);
extern void OS_CORTEXM_IRQ_1d0(void);
extern void OS_CORTEXM_IRQ_1d1(void);
extern void OS_CORTEXM_IRQ_1d2(void);
extern void OS_CORTEXM_IRQ_1d3(void);
extern void OS_CORTEXM_IRQ_1d4(void);
extern void OS_CORTEXM_IRQ_1d5(void);
extern void OS_CORTEXM_IRQ_1d6(void);
extern void OS_CORTEXM_IRQ_1d7(void);
extern void OS_CORTEXM_IRQ_1d8(void);
extern void OS_CORTEXM_IRQ_1d9(void);
extern void OS_CORTEXM_IRQ_1da(void);
extern void OS_CORTEXM_IRQ_1db(void);
extern void OS_CORTEXM_IRQ_1dc(void);
extern void OS_CORTEXM_IRQ_1dd(void);
extern void OS_CORTEXM_IRQ_1de(void);
extern void OS_CORTEXM_IRQ_1df(void);
extern void OS_CORTEXM_IRQ_1e0(void);
extern void OS_CORTEXM_IRQ_1e1(void);
extern void OS_CORTEXM_IRQ_1e2(void);
extern void OS_CORTEXM_IRQ_1e3(void);
extern void OS_CORTEXM_IRQ_1e4(void);
extern void OS_CORTEXM_IRQ_1e5(void);
extern void OS_CORTEXM_IRQ_1e6(void);
extern void OS_CORTEXM_IRQ_1e7(void);
extern void OS_CORTEXM_IRQ_1e8(void);
extern void OS_CORTEXM_IRQ_1e9(void);
extern void OS_CORTEXM_IRQ_1ea(void);
extern void OS_CORTEXM_IRQ_1eb(void);
extern void OS_CORTEXM_IRQ_1ec(void);
extern void OS_CORTEXM_IRQ_1ed(void);
extern void OS_CORTEXM_IRQ_1ee(void);
extern void OS_CORTEXM_IRQ_1ef(void);
extern void OS_CORTEXM_IRQ_1f0(void);
extern void OS_CORTEXM_IRQ_1f1(void);
extern void OS_CORTEXM_IRQ_1f2(void);
extern void OS_CORTEXM_IRQ_1f3(void);
extern void OS_CORTEXM_IRQ_1f4(void);
extern void OS_CORTEXM_IRQ_1f5(void);
extern void OS_CORTEXM_IRQ_1f6(void);
extern void OS_CORTEXM_IRQ_1f7(void);
extern void OS_CORTEXM_IRQ_1f8(void);
extern void OS_CORTEXM_IRQ_1f9(void);
extern void OS_CORTEXM_IRQ_1fa(void);
extern void OS_CORTEXM_IRQ_1fb(void);
extern void OS_CORTEXM_IRQ_1fc(void);
extern void OS_CORTEXM_IRQ_1fd(void);
extern void OS_CORTEXM_IRQ_1fe(void);
extern void OS_CORTEXM_IRQ_1ff(void);
#endif /* (256 < OS_CORTEXM_NUM_SOURCES) */

#endif /* ! OS_ASM */

#endif /* ! OS_MICROKERNEL */

#endif /* OS_CORTEXM_INT_H */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
