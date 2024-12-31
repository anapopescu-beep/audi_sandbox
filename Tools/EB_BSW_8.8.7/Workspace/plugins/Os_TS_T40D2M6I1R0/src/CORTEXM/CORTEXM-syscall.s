/* CORTEXM-syscall.asm
 *
 * This file contains the system call handler for CORTEXM.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: CORTEXM-syscall.s 1.1 2023/04/18 07:06:17CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_ASM
#define OS_ASM
#endif

#include <Os_asm_common.h>
#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <Os_configuration.h>
#include <CORTEXM/Os_asm_CORTEXM.h>
#include <CORTEXM/Os_asm_CORTEXM_cfg.h>
#include <Os_kernel.h>
#include <Os_syscalls.h>
#include <CORTEXM/Os_CORTEXM_cpu.h>

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB
	OS_align(4, 2)

	/* export functions */
	OS_global OS_SystemCall

	/* Sybols defined somewhere else but referenced here: */
	OS_extern OS_CheckForDispatch
	OS_extern OS_syscallTable
	OS_extern OS_CORTEXM_Dispatch
	OS_extern OS_Dispatch
	OS_extern OS_TaskSpOutOfBounds
	OS_extern OS_IntDisableConditionalX
	OS_extern OS_kernel_ptr

	/* Data label: cover the following OS_ASM_LABEL declaration */
	OS_ASM_DATALABEL

	/* The address of the OS_syscallTable variable */
OS_ASM_LABEL(OS_syscallTableAddr)
	OS_word OS_syscallTable

	/* The address of the kernel data */
OS_ASM_LABEL(OS_kernelDataAddr)
	OS_word	OS_kernel_ptr

	OS_GENLIT_ACTIVATE_SVC

/* Offset of r0 in saved context on kernel stack.
 * Syscall handler stores 12 registers
 * Hardware stores r0, r1... with r0 at lowest postion.
 * = 12 * 4 + 0
*/
#define OS_CORTEXM_CONTEXT_POS_R0_MSP			48
/* Position of interrupt lock level */
#define OS_CORTEXM_CONTEXT_POS_LEVEL			0
/* Offset of r0 in saved context on process stack.
 * r0 is lowest element, so offset is 0.
*/
#define OS_CORTEXM_CONTEXT_POS_R0_PSP			0

/*
 * OS_SystemCall
 *
 * This is the system call handler.
 *
 * The exception handler is called in supervisor mode.
 *
 * The xPSR has been saved to the stack by the hardware.
 * In handler mode the stack pointer SP is the main stack pointer MSP.
 *
 * The SP of the handler mode points to the kernel stack.
 *
 * r0-r3 and r12 are volatile and are already saved on the stack.
 * If any other registers are used, these registers must be preserved by the
 * system call handler.
 *
 * r12 contains the system call number
 *
 * r0-r3 are used for passing arguments on function call, we must preserve
 * them as up to the point when the system call is dispatched.
 * After dispatching the system call, r0 is used as return value on function return.
*/
	OS_ASM_FUNC(OS_SystemCall)
OS_ASM_LABEL(OS_SystemCall)
	/* Disable all interrupts (exceptions do not disable interrupts) */
	cpsid	f

	/* Store the first few non-volatile registers on main stack. */
	push	{r9-r11,lr}

	/* Disable the MPU */
	OS_LEAVE_NON_TRUSTED	r9, r10, r11

	/* Store the remaining non-volatile registers. */
	push	{r4-r8}
	mov		r6, r11

	/* Disable the FPU */
	OS_DISABLE_FPU r4, r5, r7

	/* Save
	 * - old FPU state or gap for alignment (r7)
	 * - old MPU state (r6)
	 * - gap for old interrupt level (r5)
	*/
	push	{r5, r6, r7}

/*- deactivate SVC exception ---------------------*/
	/* mark SVC exception as NOT active to allow interrupts in system calls */
	ldr		r10, OS_SHCSR_Addr
	ldr		r8, [r10]
	bic		r8, r8, #OS_CORTEXM_SHCSR_SVCALLACT
	str		r8, [r10]
	dsb
	isb


/*------------------------------------------------*/

	/* OS_GetKernelData()->inKernel = 1; */
	OS_GET_KERNEL_PTR	OS_kernelDataAddr, r5, r6
	ldrb	r6, [r5, #OS_T_INKERNEL]
	mov		r7, #0x1
	strb	r7, [r5, #OS_T_INKERNEL]

	mov		r9, lr							/* temp save EXC_RETURN value */

	cpsie	f								/* now it's safe to re-enable all interrupts */

	cmp		r12, #OS_N_SYSCALL				/* check if system call number is valid */

	ldr		r7, OS_syscallTableAddr			/* load the address of the system call table */

	bge		GetScEntry						/* invalid system calls use first entry of the system */

	add		r7, r7, r12, LSL #2				/* calculate address of entry in system call table */

OS_ASM_LABEL(GetScEntry)
	ldr		r7,[r7]							/* load address of kernel function */
	blx		r7								/* call kernel function */

	cpsid	f

/*- save return value ----------------------------*/
	/* check if we came from thread mode */
	tst		r9, #OS_CORTEXM_EXC_RETURN_MODE_THREAD
	it		NE
	/* check which stack was used to save the context */
	tstne	r9, #OS_CORTEXM_EXC_RETURN_STACK_PSP

	ittee	NE
	/* itt.. [THEN] interrupted context saved on process stack */
	mrsne	r8, psp
	strne	r0, [r8,#OS_CORTEXM_CONTEXT_POS_R0_PSP]
	/* i..ee [ELSE] interrupted context saved on main stack */
	mrseq	r8, msp
	streq	r0, [r8,#OS_CORTEXM_CONTEXT_POS_R0_MSP]
/*------------------------------------------------*/

	ldrb	r7, [r5, #OS_T_INFUNCTION]		/* get OS_inFunction */

	cmp		r7, #OS_INBOOT					/* if the system is still booting, i.e. the OS is not yet */
	beq		JustReturn						/* started, we just return, no dispatcher call */

	/* Note: The dispatcher may call the PreTaskHook directly. In the
	 *       PretaskHook, system calls may occur. Therefore, the
	 *       dispatcher is called with deactivated system calls.
	 *       Therefore, each way out of the kernel must re-activate
	 *       the SVC active flag if ipsr contains the value for the
	 *       system call, i.e. if it came from a system call.
	*/

	/* dispatch = OS_CheckForDispatch(old_inKernel); */
	mov		r0, r6							/* 1st argument: value of the old_inKernel */
	bl		OS_CheckForDispatch

	mov		r7, r0							/* put return value of OS_CheckForDispatch in r7 */

	cmp		r7, #OS_NO_DISP
	beq		JustReturn						/* do not dispatch, just return from the exception */

	bl		OS_IntDisableConditionalX		/* set kernel level, returns previous level */
	str		r0, [sp, #OS_CORTEXM_CONTEXT_POS_LEVEL]	/* Store previous level at its position on stack */

	cpsie	f								/* enable all interrupts; but still locked on kernel level */

	cmp		r7, #OS_DISP_WITHOUT_SAVE
	beq		WithoutSave						/* dispatch without saving the context */

/* dispatch and save context */
	mov		r0, sp
	mrs		r1, psp							/* get current task stack pointer */
	bl		OS_CORTEXM_Dispatch				/* call OS_CORTEXM_Dispatch(sp, task_sp) */
	/* dispatch now, see below. */

OS_ASM_LABEL(WithoutSave)
	/* no need to restore registers here since we dispatch */
	mov		r0, #OS_TS_READY_SYNC
	bl		OS_Dispatch						/* call OS_Dispatch(OS_TS_READY_SYNC) */

OS_ASM_LABEL(JustReturn)
	cpsid	f
	/* OS_GetKernelData()->inKernel = old_inKernel; */
	strb	r6, [r5, #OS_T_INKERNEL]

	/* Mark SVC as active again to return from system call. */
	OS_ACTIVATE_SVC	r0, r1

	/* Restore
	 * - old interrupt lock level (gap) (r0)
	 * - old MPU state (r1),
	 * - old FPU state or gap for alignment (r2) */
	pop		{r0, r1, r2}

#if ((OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) && !defined(OS_EXCLUDE_HW_FP))
	tst		r2, #0x00f00000
	beq		OS_Syscall_SkipEnableFpu

	OS_ENABLE_FPU	r0, r2, r2
OS_ASM_LABEL(OS_Syscall_SkipEnableFpu)
#endif

	OS_RESTORE_NON_TRUSTED	r0, r2, r1

	/* restore context */
	pop		{r4-r11,lr}

#if (OS_CORTEXM_HAS_ERRATA_838869 == 1)
	/* workaround ARM Erratum 838869 (see ASCOS-5685) on all Cortex-M4/M4F */
	dsb
#endif

	/* return from exception (pc=EXC_RETURN) */
	bx		lr
	/* Note: return from exception AUTOMATICALLY restores (xPSR,..,r0) from the interrupted stack */

	OS_ASM_END_FUNC(OS_SystemCall)


	OS_ASM_SRC_END

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
 */
