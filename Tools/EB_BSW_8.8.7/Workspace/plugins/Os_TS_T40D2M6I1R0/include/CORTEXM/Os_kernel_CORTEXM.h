/* Os_kernel_CORTEXM.h
 *
 * This file is the architecture-dependent include file for CORTEXM
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_kernel_CORTEXM.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#ifndef	OS_KERNEL_CORTEXM_H
#define	OS_KERNEL_CORTEXM_H

#include <CORTEXM/Os_tool_CORTEXM.h>
#include <CORTEXM/Os_CORTEXM_core.h>
#include <CORTEXM/Os_CORTEXM_cpu.h>

#ifndef OS_HASMEMPROT
#error "OS_HASMEMPROT is not defined for this derivate".
#endif
#ifndef OS_USE_MMU
#error "OS_USE_MMU is not defined for this derivate".
#endif
#ifndef OS_USE_MPU
#error "OS_USE_MPU is not defined for this derivate".
#endif

#if (OS_HASMEMPROT == 1)
#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARM)
#include <CORTEXM/Os_mpu_CORTEXM.h>
#elif (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_NXP)
#include <CORTEXM/Os_mpu_CORTEXM_NXP.h>
#elif (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)
#include <CORTEXM/Os_mpu_armv8_CORTEXM.h>
#else
#error "MPU not supported, check OS_CORTEXM_MPU_TYPE"
#endif /* OS_CORTEXM_MPU_TYPE */

#else /* !OS_HASMEMPROT */

/* Define necessary macros appropriately for non-memory-protection builds
 * (typically empty).
 */
#define OS_CORTEXM_RESETKERNSTACKRW(isr) do { } while (0)

#endif /* OS_HASMEMPROT */

#include <CORTEXM/Os_CORTEXM_int.h>

#if (OS_KERNEL_TYPE==OS_SYSTEM_CALL)
/* We need the Syscall for task, ISR and app-hook returns
*/
#define OS_K_TASKRETURN			(&OS_KernTaskReturn)
#define OS_K_RETURNFROMCALL		(&OS_KernReturnFromCall)
#endif

/*
 * OS_GET_ALIGNED_SP(mpuSize)
 *
 * Return a value of the kernel stack pointer, that is aligned to
 * the next mpuSize granule. mpuSize is one of the values defined in
 * Os_mpu_CORTEXM.h.
 *
 * Attention: We need to add the overhead of OS_CORTEXM_Call() to
 * the current stack, i.e. decrease the current kernel stack pointer
 * by AT LEAST this amount.
*/
/* When MPU is not in use (mpuSize == OS_CORTEXM_MPU_SIZE_DISABLED),
 * alignment to 8-byte boundary is performed to satisfy AAPCS stack alignment. */

#if (OS_HASMEMPROT == 1)

#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARM)
#define OS_GET_ALIGNED_SP(mpuSize)				\
	((os_uint32_t)								\
		((((os_uint32_t)OS_CORTEXM_GetSP()) - (os_int32_t)64) \
		& ~((((os_uint32_t)1u) << (((((os_uint32_t)(((mpuSize) != 0) ? (mpuSize) : 4u)) >> 1u) + (os_uint32_t)1u))) - (os_uint32_t)1u)))
#elif (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_NXP)
#define OS_GET_ALIGNED_SP(mpuSize)	\
	(((os_uint32_t)OS_CORTEXM_GetSP() - 64u) & (os_uint32_t)(~OS_NXPMPU_ALIGNMASK))
#elif (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)
#define OS_GET_ALIGNED_SP(mpuSize)	\
	(((os_uint32_t)OS_CORTEXM_GetSP() - 64u) & OS_MPU_RXAR_MASK)
#else
#error "MPU not supported, check OS_CORTEXM_MPU_TYPE"
#endif /* OS_CORTEXM_MPU_TYPE */

#else /* OS_HASMEMPROT */
/* No memory protection support -> simply obtain the current stack pointer
 * minus some overhead and perform 8-byte alignment to satisfy AAPCS stack alignment requirement.*/
#define OS_GET_ALIGNED_SP(mpuSize)	((os_uint32_t)(OS_CORTEXM_GetSP() - (os_int32_t)64) & (os_uint32_t)(~0x7u))
#endif /* OS_HASMEMPROT */


/*!
 * OS_intDisableLevel, OS_intDisableLevelAll, OS_kernDisableLevel
 *
 * The constant OS_intDisableLevel contains the level for disabling
 * OS (category 2) interrupts.
 * The constant OS_intDisableLevelAll contains the level for disabling
 * all (category 1 and 2) interrupts.
 * The constant OS_kernDisableLevel contains the level for disabling
 * OS (category 2) interrupts AND the timing protection interrupt(s), if any.
 * The constant OS_intDisableLevelMax contains the interrupt disable level to
 * disable ALL possible interrupts. This includes CAT2, CAT1 and OS interrupts,
 * i.e. the maximum of all lock levels.
 * The constant OS_kernOnlyXcoreLevel contains the level for disabling
 * all interrupts except for cross-core notifications.
*/
#ifndef OS_ASM
extern const os_intstatus_t OS_intDisableLevel;
extern const os_intstatus_t OS_intDisableLevelAll;
extern const os_intstatus_t OS_kernDisableLevel;
extern const os_intstatus_t OS_intDisableLevelMax;
#if (OS_N_CORES_MAX > 1)
extern const os_intstatus_t OS_kernOnlyXcoreLevel;
#endif /* OS_N_CORES_MAX > 1 */
#endif


/*!
 * os_archcontext_t
 *
 * This is the data type for the architecture-dependent task context.
 * It is typically a data structure	that contains fields for all the
 * registers that are not saved elsewhere (e.g. on the stack) during
 * a context switch.
 *
 * For CORTEXM it contains the saved SP of the task
 *
*/
#ifndef OS_ASM
typedef struct os_archcontext_s os_archcontext_t;

struct os_archcontext_s
{
	os_stackelement_t * sp;
#if (OS_HASMEMPROT == 1) && (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)
	os_cortexm_region_t regions[OS_MPU_DYNAMIC_REGIONS];	/* task-specific regions */
#endif
};
#endif

/* offset of SP in the context structure */
#define OS_CTXT_SP		0

/* size of the os_archcontext_s */
#if (OS_HASMEMPROT == 1) && (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)
#define OS_SIZEOF_CTXT (4+(OS_MPU_DYNAMIC_REGIONS*8))
#else
#define OS_SIZEOF_CTXT 4
#endif

/*
 * The macro OS_FreeTaskContext() releases any allocated resources
 * that are held in the task's context. For CORTEXM there is nothing to do.
 */
#define OS_FreeTaskContext(c)		\
			do{						\
			}while(0)

/*
 * The macro OS_FreeCurrentContext() releases any allocated resources
 * that are held by	the CPU	(i.e. for the currently-running thread).
 * For CORTEXM there is nothing to do.
 */
#define OS_FreeCurrentContext()	\
			do{					\
			}while(0)

/*!
 * OS_GetCurrentSp() returns the current value of the stack pointer.
 * It is used in the stack check code, and in the stack initialization
 * in OS_KernStartOs()
*/
#define OS_GetCurrentSp()	OS_CORTEXM_GetSP()

/*!
 * OS_StoreTaskSp()
 *
 * This macro stores the current stack pointer in the outgoing task's context.
 * It is used by OS_LeaveKernel() and only needs to do its job when stack-checking
 * is (possibly) enabled.
 *
 * For CORTEXM, it gets the current task pointer from the SP register of the current mode
*/
#ifdef OS_EXCLUDE_STACKCHECK
#define	OS_StoreTaskSp()
#else
#define	OS_StoreTaskSp()											\
	do {															\
		OS_GetKernelData()->taskCurrent->dynamic->context.sp = OS_GetCurrentSp();	\
	}	while(0)
#endif

/*! OS_GetTaskSp()
 * OS_GetTaskSpForce()
 *
 * This macro returns the	value of the stack pointer from a task's
 * saved context. The saved context is only valid if the task is in
 * one of the states OS_TS_READY_ASYNC, OS_TS_READY_SYNC or
 * OS_TS_WAITING. On some architectures the saved context might
 * be different depending on the task's state.
 * If the system-call handler and ISR handler save the task's SP in
 * its context as part of switching over to the	kernel stack, the
 * SP is also available when the task is RUNNING.
 *
 * The "Force" version is called (indirectly) from the dispatcher
 * before the task leaves the running state.
*/
#define OS_GetTaskSp(t)	\
	(	(	((t)->dynamic->state ==	OS_TS_WAITING) ||			\
		((t)->dynamic->state ==	OS_TS_READY_SYNC)	||			\
		((t)->dynamic->state ==	OS_TS_READY_ASYNC) )			\
		?	(t)->dynamic->context.sp							\
		:	OS_NULL	)

#define OS_GetTaskSpForce(tp,td)	((os_address_t)(td)->context.sp)

#if (OS_HASMEMPROT == 1)

#ifndef OS_ASM

/*!
 * os_archapp_s, os_archappdynamic_s
 *
 * This is the data structure for the architecture-specific application
 * context generated by the generator. It defines the architecture-specific
 * part of the environment an application's tasks/ISRs must run in.
 * For CORTEXM it contains the required value for the MPU registers
 * to configure the size of the application's private data.
*/

#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARM)
typedef struct os_archapp_s os_archapp_t;

struct os_archapp_s
{
	os_uint8_t mpuSizeData;
};

#define OS_HAVE_ARCHAPP_T 1
#define OS_ARCHAPP_INIT( mpuSizeData )		\
	{										\
	(mpuSizeData)							\
	}
#else
#define OS_HAVE_ARCHAPP_T 0
#endif

#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)
#define OS_ARCH_HAS_APPDYNAMIC  1
typedef struct os_archappdynamic_s os_archappdynamic_t;

struct os_archappdynamic_s
{
	os_cortexm_region_t regions[OS_MPU_DYNAMIC_REGIONS];	/* app-specific regions */
};
#endif /* (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8) */

/*!
 * os_archtask_t
 *
 * This is the data type for the architecture-dependent task configuration.
 * For CORTEXM, it contains the required values for the MPU registers
 * to configure the size of the task's private data and stack.
*/


#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARM)
typedef struct os_archtask_s os_archtask_t;

struct os_archtask_s
{
	os_uint8_t mpuSizeData;		/* size of the region for the task's private data */
	os_uint8_t mpuSizeStack;	/* size of the region for the task stack */
};

#define OS_HAVE_ARCHTASK_T 1
#define OS_ARCHTASK_INIT( mpuSizeData, mpuSizeStack )			\
	{															\
		(mpuSizeData),											\
		(mpuSizeStack)											\
	}
#else
#define OS_HAVE_ARCHTASK_T 0
#endif

#endif /* #ifndef OS_ASM */

#endif /* #if (OS_HASMEMPROT == 1) */


/*!
 * os_savedcontext_t
 *
 * This structure stores the current context so that an exception handler
 * can return to the kernel. It is used for interrupt handling and
 * application-specific hook functions.
*/
#ifndef OS_ASM
typedef struct os_savedcontext_s os_savedcontext_t;

struct os_savedcontext_s
{
	os_stackelement_t * sp;			/* The calling context's SP */
	os_stackelement_t * stackLimit;	/* Where the stack is at runtime */
};

#define OS_SAVEDCONTEXT_INIT	\
{								\
	OS_NULL,	/* SP */		\
	OS_NULL		/* stackLimit*/	\
}

#endif


/*!
 * OS_Idle()
 *
 * This macro is only used at a specific place in the dispatcher, so
 * no protection against use in conditionals etc. is needed.
 * It must present an optimization barrier to the compiler to
 * ensure that global variables get updated; this can sometimes
 * be achieved by special attributes on an assembler disable or
 * enable macro. Alternatively, call a function.
 *
 * This macro must never return to the caller. It
 * - sets OS_GetKernelData()->inKernel to 0
 * - switches to the SVC mode (only in the non-syscall variant,
 *   in the syscall variant, the CPU is already in the SVC mode)
 * - resets the kernel stack
 * - enables interrupts
 * - sits in an endless loop.
*/
#define OS_Idle()			\
	do {					\
		OS_CORTEXM_Idle();	\
	} while (0)


/*!
 * OS_CORTEXM_GetTaskIsrAppFlags(x)
 *
 * This macro returns the flags of an application of an task or ISR.
 *
 * Parameters:
 * x		The task or ISR data structure
 */
#define OS_CORTEXM_GetTaskIsrAppFlags(x) ( ((x)->app == OS_NULL) ? OS_APP_TRUSTED : (x)->app->flags )

/*!
 * OS_ResumeTaskSync()
 *
 * This macro resumes a task that voluntarily gave up the CPU by calling
 * Schedule, ActivateTask, WaitEvent etc.
 *
 * It restores the non-volatile registers and the CPSR from the stack and branches to the
 * address located in the link register.
 *
 * When the task uses the floating point unit, it also restores the floating point registers.
 *
 * For details, refer to OS_CORTEXM_ContextLoad or OS_CORTEXM_FPContextLoad
*/
#if ((OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) && !defined(OS_EXCLUDE_HW_FP))
#define OS_ResumeTaskSync(t)													\
	do {																		\
		((OS_GetKernelData()->taskCurrent->flags & OS_TF_USEFPU) != 0)			\
		?																		\
			OS_CORTEXM_FPContextLoad((os_uint32_t *)(t)->dynamic->context.sp)	\
		:																		\
			OS_CORTEXM_ContextLoad((os_uint32_t *)(t)->dynamic->context.sp);	\
	} while (0)
#else /* ((OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) && !defined(OS_EXCLUDE_HW_FP)) */
#define OS_ResumeTaskSync(t)												\
	do {																	\
		OS_CORTEXM_ContextLoad((os_uint32_t *)(t)->dynamic->context.sp);	\
	} while (0)
#endif /* ((OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) && !defined(OS_EXCLUDE_HW_FP)) */

/*!
 * OS_ResumeTaskAsync()
 *
 * This macro resumes a task that was preempted.
 *
 * It restores all registers and then returns from the exception.
 * For details, refer to OS_CORTEXM_ContextLoad or OS_CORTEXM_FPContextLoad.
 *
 */
#if ((OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) && !defined(OS_EXCLUDE_HW_FP))
#define OS_ResumeTaskAsync(t)													\
	do {																		\
		((OS_GetKernelData()->taskCurrent->flags & OS_TF_USEFPU) != 0)			\
		?																		\
			OS_CORTEXM_FPContextLoad((os_uint32_t *)(t)->dynamic->context.sp)	\
		:																		\
			OS_CORTEXM_ContextLoad((os_uint32_t *)(t)->dynamic->context.sp);	\
	} while (0)

#else /* ((OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) && !defined(OS_EXCLUDE_HW_FP)) */
#define OS_ResumeTaskAsync(t)												\
	do {																	\
		OS_CORTEXM_ContextLoad((os_uint32_t *)(t)->dynamic->context.sp);	\
	} while (0)
#endif /* ((OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) && !defined(OS_EXCLUDE_HW_FP)) */

/*!
 * OS_StartTask
 *
 * Starts the new task t. The task's dynamic state has already been set.
 * All that remains is for us to set up the registers for the task and then
 * "goto" the entry point.
 *
 * In case of returning without TerminateTask we provide the user function
 * OS_MissingTerminateTask which recovers the kernel.
 *
 * The following parameters are given to OS_CORTEXM_StartTask:
 * entry:	address of the task entry
 * sp:		stack pointer of the task
 * flags:	flags of the application to determine whether application is trusted or not,
 *			and flags of the task to determine whether it uses FPU or not
 * utr:		address of MissingTerminateTask
 */
#define OS_StartTask(t)															\
	OS_CORTEXM_StartTask(														\
		(t)->entry,																\
		(os_stackelement_t *)(((os_address_t)(t)->stackBase) + (t)->stackLen),	\
		(((OS_CORTEXM_GetTaskIsrAppFlags((t))) << 8 ) | ((t)->flags)),			\
		&OS_MissingTerminateTask												\
	)

/*!
 * OS_TaskMemoryAccess()
 * OS_IsrMemoryAccess()
 *
 * These two macros check whether a nontrusted task/ISR has access to the
 * specified memory region. The private data and stack areas are checked
 * by the architecture-independent code, so we're only interested in the
 * global areas, which are read-only or executable.
 *
 * On CORTEXM, these two areas are represented by the constants:
 *	- OS_romBase/OS_romLimit for execute access and read-only access
 *	- OS_ramBase/OS_ramLimit for read-only access to RAM
*/
#if (OS_HASMEMPROT == 0)
#define OS_GlobalMemoryAccess(f,l)		(OS_MA_EXEC | OS_MA_READ | OS_MA_WRITE)
#else
#define OS_GlobalMemoryAccess(f,l) \
	(	\
		( ((f) >= (os_address_t)OS_romBase) && ((l) <= (os_address_t)OS_romLimit) )  \
		? (OS_MA_EXEC | OS_MA_READ) \
	: \
	(	\
		( ((f) >= (os_address_t)OS_ramBase) && ((l) <= (os_address_t)OS_ramLimit) ) \
		? (OS_MA_READ) : (0u) \
	))
#endif

#define OS_TaskMemoryAccess(t,f,l)	OS_GlobalMemoryAccess(f,l)
#define OS_IsrMemoryAccess(i,f,l)	OS_GlobalMemoryAccess(f,l)

#if (OS_HASMEMPROT == 0)
#if (OS_KERNEL_TYPE != OS_MICROKERNEL)
/* If memory protection is not present, we need to take only the proper
 * alignment into account.
*/
#define OS_ArchCanWrite(b, l) (!OS_ArchMisalignedData(b, l))
#endif
#else
/* In case memory protection is present, we need to use the arch-independent
 * OS_CanWrite() function. Using this function is the default, so we do not
 * need to define anything here.
*/
#endif

/* While CORTEXM supports misaligned accesses for load/store instructions,
 * load multiple/store multiple need to be word-aligned.
 * Also, depending on CCR.UNALIGN_TRP settings, half-word load/store
 * instructions may provoke an exception if not half-word aligned.
*/
#define OS_ArchMisalignedData(b, l)						\
	(													\
		(												\
			((l) >= (os_uint32_t)4u)					\
			?	(((os_address_t)(b) & 3u) != 0)			\
			:	(										\
					((l) == (os_uint32_t)2u)			\
					?	(((os_address_t)(b) & 1u) != 0)	\
					:	OS_FALSE						\
				)										\
		) != 0											\
	)

/* OS_APPGETSUSOOKPROTSTACKSIZE(const os_appcontext_t *app)
 * Return the memory protection size of the applications specific startup
 * hook.
*/

#if (OS_HASMEMPROT == 1)
#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_NXP) || (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)
#define OS_APPGETSUHOOKPROTSTACKSIZE(app)		((app)->startupHookStack)
#endif /* OS_CORTEXM_MPU_TYPE */
#endif /* OS_HASMEMPROT */

#ifndef OS_APPGETSUHOOKPROTSTACKSIZE
#define OS_APPGETSUHOOKPROTSTACKSIZE(app)		(OS_sHookMpuSize)
#endif

/* OS_APPGETSDHOOKPROTSTACKSIZE(const os_appcontext_t *app)
 * Return the memory protection size of the applications specific startup
 * hook.
*/

#if (OS_HASMEMPROT == 1)
#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_NXP) || (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)
#define OS_APPGETSDHOOKPROTSTACKSIZE(app)		((app)->shutdownHookStack)
#endif /* OS_CORTEXM_MPU_TYPE */
#endif /* OS_HASMEMPROT */

#ifndef OS_APPGETSDHOOKPROTSTACKSIZE
#define OS_APPGETSDHOOKPROTSTACKSIZE(app)		(OS_sHookMpuSize)
#endif

/* OS_APPGETERHOOKPROTSTACKSIZE(const os_appcontext_t *app)
 * Return the memory protection size of the applications specific error
 * hook.
*/

#if (OS_HASMEMPROT == 1)
#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_NXP) || (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)
#define OS_APPGETERHOOKPROTSTACKSIZE(app)		((app)->errorHookStack)
#endif /* OS_CORTEXM_MPU_TYPE */
#endif /* OS_HASMEMPROT */

#ifndef OS_APPGETERHOOKPROTSTACKSIZE
#define OS_APPGETERHOOKPROTSTACKSIZE(app)		(OS_eHookMpuSize)
#endif

/*!
 * OS_ArchCallStartupHook()
 * OS_ArchCallShutdownHook()
 * OS_ArchCallErrorHook()
 *
 * These macros call application-specific hook functions when Autosar sematics are configured.
 *
 * The hook is called via OS_CallAppHook().
 * OS_CallAppHook() saves its context so that if the hook misbehaves
 * the error handler can kill it by appearing to return from the call to
 * OS_CallAppHook(). For this reason setting the hook's saved
 * context to null is done here rather than in OS_CallAppHook().
 *
 * The startup and shutdown hooks can safely share a return context because
 * the two will never be used simultaneously.
 *
 * The macros' parameters must be simple variables, not expressions. This
 * should not be a problem, however, because they are only used in internal
 * kernel functions.
 *
 * The used parameters for the calls:
 * - const os_appcontext_t * app
 * - os_result_t code: The argument for the hook call. (not for startup hook)
 */

#define OS_ArchCallStartupHook(app)													\
	do {																			\
		os_kerneldata_t * const k_data = OS_GetKernelData();						\
		k_data->sHookContext.c.sp =													\
			(os_stackelement_t *)													\
				(																	\
					OS_GET_ALIGNED_SP(OS_APPGETSUHOOKPROTSTACKSIZE(app))			\
				);																	\
		k_data->sHookContext.c.stackLimit =											\
						k_data->sHookContext.c.sp									\
							- (OS_sHookStackLen / (os_uint32_t)4u);					\
		OS_SETHOOKPROTECTION(app, &k_data->sHookContext.c,							\
								(os_size_t)OS_APPGETSUHOOKPROTSTACKSIZE(app));		\
		OS_CORTEXM_Call			(	OS_kernDisableLevel,							\
								(os_vfuncu_t) (app)->startupHook,					\
								&k_data->sHookContext.c.sp,							\
								k_data->sHookContext.c.sp,							\
								(((app) == OS_NULL) ? OS_APP_TRUSTED : (app)->flags),	\
								0													\
							);														\
		OS_CORTEXM_RESETKERNSTACKRW(app);											\
		k_data->sHookContext.c.sp = OS_NULL;										\
		k_data->sHookContext.c.stackLimit = OS_NULL;								\
	} while(0)

#define OS_ArchCallShutdownHook(app, code)											\
	do {																			\
		os_kerneldata_t * const k_data = OS_GetKernelData();						\
		k_data->sHookContext.c.sp =													\
			(os_stackelement_t *)													\
				(																	\
					OS_GET_ALIGNED_SP(OS_APPGETSDHOOKPROTSTACKSIZE(app))			\
				);																	\
		k_data->sHookContext.c.stackLimit =											\
						k_data->sHookContext.c.sp									\
							- (OS_sHookStackLen / (os_uint32_t)4u);					\
		OS_SETHOOKPROTECTION(app, &k_data->sHookContext.c,							\
								(os_size_t)OS_APPGETSDHOOKPROTSTACKSIZE(app));		\
		OS_CORTEXM_Call			(	OS_kernDisableLevel,							\
								(os_vfuncu_t) (app)->shutdownHook,					\
								&k_data->sHookContext.c.sp,							\
								k_data->sHookContext.c.sp,							\
								(((app) == OS_NULL) ? OS_APP_TRUSTED : (app)->flags),	\
								code												\
							);														\
		OS_CORTEXM_RESETKERNSTACKRW(app);											\
		k_data->sHookContext.c.sp = OS_NULL;										\
		k_data->sHookContext.c.stackLimit = OS_NULL;								\
	} while(0)

#define OS_ArchCallErrorHook(app, code)												\
	do {																			\
		os_kerneldata_t * const k_data = OS_GetKernelData();						\
		k_data->eHookContext.c.sp =													\
			(os_stackelement_t *)													\
				(																	\
					OS_GET_ALIGNED_SP(OS_APPGETERHOOKPROTSTACKSIZE(app))			\
				);																	\
		k_data->eHookContext.c.stackLimit =											\
						k_data->eHookContext.c.sp									\
							- (OS_eHookStackLen / (os_uint32_t)4u);					\
		OS_SETHOOKPROTECTION(app, &k_data->eHookContext.c,							\
								(os_size_t)OS_APPGETERHOOKPROTSTACKSIZE(app));		\
		OS_CORTEXM_Call			(	OS_kernDisableLevel,							\
								(os_vfuncu_t) (app)->errorHook,						\
								&k_data->eHookContext.c.sp,							\
								k_data->eHookContext.c.sp,							\
								(((app) == OS_NULL) ? OS_APP_TRUSTED : (app)->flags),	\
								code												\
							);														\
		OS_CORTEXM_RESETKERNSTACKRW(app);											\
		k_data->eHookContext.c.sp = OS_NULL;										\
		k_data->eHookContext.c.stackLimit = OS_NULL;								\
	} while(0)

#ifndef OS_ASM

extern const os_size_t OS_eHookStackLen;
extern const os_size_t OS_sHookStackLen;

#endif /* ! OS_ASM */

/*!
 * OS_GetIsrStackLimit()
 *
 * Returns the stack limit of the specified ISR, as set up by OS_CallIsr()
*/
#define OS_GetIsrStackLimit(id) ((id)->c.stackLimit)

/*!
 * OS_SaveTaskContextSync(a)
 *
 * needed for architectures without system call (leavekernel())
*/
#if ((OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) && !defined(OS_EXCLUDE_HW_FP))
#define OS_SaveTaskContextSync(a)											\
	do {																	\
		((OS_GetKernelData()->taskCurrent->flags & OS_TF_USEFPU) != 0)		\
		?																	\
			OS_CORTEXM_SaveFPContextAndDispatch(OS_TS_READY_SYNC, &((a)->sp))	\
		:																	\
			OS_CORTEXM_SaveContextAndDispatch(OS_TS_READY_SYNC, &((a)->sp));	\
	} while (0)
#else /* ((OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) && !defined(OS_EXCLUDE_HW_FP)) */
#define OS_SaveTaskContextSync(a)										\
	do {																\
		OS_CORTEXM_SaveContextAndDispatch(OS_TS_READY_SYNC, &((a)->sp));	\
	} while (0)

#endif /* ((OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) && !defined(OS_EXCLUDE_HW_FP)) */

/*!
 * OS_CFG_INITARCH
 *
 * This macro defines the architecture-specific initialization
 * function that gets called as the first initialization function
 * in StartOS.
*/
#define OS_CFG_INITARCH (&OS_CORTEXM_InitArch)
#ifndef OS_ASM
void OS_CORTEXM_InitArch(void);
#endif

/*!
 * os_timervalue_t
 *
 * How big is a hardware timer. This depends of the used timer and
 * is specified in the given timer header.
 */
#ifndef OS_ASM
typedef os_uint32_t os_timervalue_t;
#endif

#define OS_MAXTIMERVALUE  0xffffffff

/* OS_HAS_TB_INTERNAL is only defined for non-MK builds.
*/
#if OS_KERNEL_TYPE != OS_MICROKERNEL

#if (OS_HAS_TB_INTERNAL == 1)
/*
 * Timestamp driver
 *
 * Use an internal imestamp timer (derivative specific).
*/
#define OS_USEGENERICTIMESTAMP			0
#define OS_USE_GLOBAL_GENERICTIMESTAMP	0
#define OS_AdvanceTimeStamp(t)			do { } while(0)
#define OS_INITTIMESTAMP				(&OS_CORTEXM_InitTimeStamp)

#endif

#endif

/*!
 * OS_ArchGetCoreId()
 *
 * Return the core id.
*/
#if (OS_N_CORES > 1)
#define OS_ArchGetCoreId() OS_GetMyCoreId()
#else
#define OS_ArchGetCoreId() OS_INITCORE
#endif


/* Size of the stack for the idle loop. Must be at least large enough
 * to store an exception context.
*/
#define OS_IDLESTACK_SIZE	64

#endif


/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
