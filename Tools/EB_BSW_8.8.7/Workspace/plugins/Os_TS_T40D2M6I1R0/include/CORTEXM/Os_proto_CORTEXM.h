/* Os_proto_CORTEXM.h
 *
 * This file is the architecture-dependent prototype file for CORTEXM
 *
 * The prototypes of kernel functions are in a separate file because they
 * are included in the kernel/os-kernel.h file AFTER the generic types
 * have been defined, whereas the architecture-dependent types file is
 * included BEFORE the generic types are defined.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_proto_CORTEXM.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#ifndef OS_PROTO_CORTEXM_H
#define OS_PROTO_CORTEXM_H

/* General functions */


#ifndef OS_ASM

/* required for Os_configuration.c */
extern void OS_UserReturnFromCall(void);

/* Type definition for function pointer required in declaration of
 * OS_CORTEXM_Call.
 *
 * Functions called by OS_CORTEXM_Call either take no parameters or one
 * parameter of type os_result_t.
*/
typedef void (*os_vfuncu_t)(os_result_t);

/* General IRQ / FIQ functions */
extern void OS_CORTEXM_IntInit(void);
#if (OS_TOOL_DISABLE_IRQ_GET_STATE_IMPLEMENTATION == OS_TOOL_ASM_FUNC)
extern os_intstatus_t OS_CORTEXM_DisableIRQGetState(void);
#endif

#if (OS_TOOL_SET_STATE_IMPLEMENTATION == OS_TOOL_ASM_FUNC)
/*
 * OS_CORTEXM_SetState - set PRIMASK to the passed value.
*/
extern void OS_CORTEXM_SetState(os_intstatus_t);
#endif

/* OS_CORTEXM_GetIRQPrio - return the interrupt lock priority, i.e.
 * the content of the BASEPRI register shifted by the correct amount.
*/
#if (OS_TOOL_GET_IRQ_PRIO_IMPLEMENTATION == OS_TOOL_ASM_FUNC)
extern os_oldlevel_t OS_CORTEXM_GetIRQPrio(void);
#endif

/* OS_CORTEXM_SetIRQPrio - set the interrupt priority, i.e.
 * set the content of the BASEPRI register by the parameter
 * shifted by the correct amount.
*/
#if (OS_TOOL_SET_IRQ_PRIO_IMPLEMENTATION == OS_TOOL_ASM_FUNC)
extern void OS_CORTEXM_SetIRQPrio(os_oldlevel_t);
#endif

/* OS_CORTEXM_GetCurIRQSource - return the content of the IPSR subtracted
 * by 16.
*/
#if (OS_TOOL_GET_CUR_IRQ_SOURCE_IMPLEMENTATION == OS_TOOL_ASM_FUNC)
extern os_uint32_t OS_CORTEXM_GetCurIRQSource(void);
#endif

/* Stack handling */
#if (OS_TOOL_GETSP_IMPLEMENTATION == OS_TOOL_ASM_FUNC)
extern os_stackelement_t * OS_CORTEXM_GetSP(void);
#endif
extern void OS_CORTEXM_Idle(void);

/* FPU handling */
#if (OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE)
extern void OS_CORTEXM_SetupVFPCoprocessor(void);
extern os_stackelement_t * OS_CORTEXM_SaveVFPFullContext(os_stackelement_t *);
#endif /* (OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) */

/* Context handling context load */
extern void OS_CORTEXM_ContextLoad(os_stackelement_t *);
#if (OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE)
extern void OS_CORTEXM_FPContextLoad(os_stackelement_t *);
#endif

/* Start task */
extern void OS_CORTEXM_StartTask(os_entry_t, os_stackelement_t *, os_uint16_t, os_entry_t);

/* Save context and jump */
extern void OS_CORTEXM_SaveContextAndDispatch(os_uint32_t, os_stackelement_t **);
#if (OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE)
extern void OS_CORTEXM_SaveFPContextAndDispatch(os_uint32_t, os_stackelement_t **);
#endif

/* Timestamp init */
extern void OS_CORTEXM_InitTimeStamp(void);

/* Get Timestamp */
extern void OS_CORTEXM_GetTimeStamp(os_timestamp_t *);

/*
 * OS_CORTEXM_Call		(	os_intstatus_t level,
 *						os_vfuncu_t function,
 *						os_stackelement_t **savedsp,
 *						os_stackelement_t *sp,
 *						os_uint8_t flags,
 *						os_result_t argument)
 *
 * This routine calls the given hook or ISR, but saves the
 * context before. If the hook or the ISR cause a protection fault,
 * the system can return to the saved context.
 *
 * Parameters:
 * level			interrupt disabling level to set (r0).
 * function			hook service or ISR to be called (r1)
 * savedsp			A pointer to a variable where the kernel stack pointer shall be
 *					saved from which the context can be restored (r2)
 * sp				The stack pointer of the hook or ISR (r3)
 * flags			The flags of the OS application (stack)
 * argument			argument of the hook function (stack)
 *
 * Precondition:	mode is SVC
 */
extern void
OS_CORTEXM_Call(
	os_intstatus_t level,
	os_vfuncu_t function,
	os_stackelement_t **savedsp,
	os_stackelement_t *sp,
	os_uint8_t flags,
	os_result_t argument
);

/* Exception routines */
extern os_uint32_t OS_Exception(os_uint32_t, os_uint32_t, os_uint32_t, os_uint32_t);

/* Context as stored by the interrupt, exception and syscall handlers.
 * Only needed for prototype of function. Otherwise only assembly
 * knows about this.
 */
typedef struct
{
	os_uint32_t level;		/* Interrupt lock level */
	os_uint32_t mpuCtrl;	/* old state of MPU_CTRL (MPU enable/disable) */
	os_uint32_t fpuState;	/* old state of FPU (enabled/disabled) or gap for alignment */
	os_uint32_t regs[8];	/* r4-r11 */
	os_uint32_t lr;			/* exception return value (lr) */
} os_cortexm_context_t;

/* Perform a stack check and move the context around. */
extern void OS_CORTEXM_Dispatch(const os_cortexm_context_t *, os_cortexm_context_t *);

/* Set the CONTROL register. */
extern void OS_CORTEXM_SetControl(os_uint32_t);

/* Get the CONTROL register. */
extern os_uint32_t OS_CORTEXM_GetControl(void);

#if (OS_HASMEMPROT == 1)
#if (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARM)
/* OS_CORTEXM_SetRegion - Program a single region in the CORTEXM MPU.
*/
extern void OS_CORTEXM_SetRegion(os_uint32_t, os_uint32_t, os_uint32_t);
/* OS_CORTEXM_ResetKernStackRw - Reset kernel stack region settings.
 *
 * This function is used to reset the kernel stack region access settings back to
 * RW for privileged accesses after an ISR or application hook has been executed.
*/
extern void OS_CORTEXM_ResetKernStackRw(const os_appcontext_t *);
#elif (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_NXP)
/* OS_NXPMPU_SetRegion - program one MPU region.
*/
extern void OS_NXPMPU_SetRegion(os_uint32_t, os_uint32_t, os_uint32_t, os_uint32_t, os_uint32_t);
#elif (OS_CORTEXM_MPU_TYPE == OS_CORTEXM_MPU_ARMV8)
/* OS_CORTEXM_MpuV8DisableRegion - Disables an MPU region.
*/
extern void OS_CORTEXM_MpuV8DisableRegion(os_uint32_t);
#endif
#endif /* (OS_HASMEMPROT == 1) */

#endif /* OS_ASM */

#endif /* OS_PROTO_CORTEXM_H */

/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
