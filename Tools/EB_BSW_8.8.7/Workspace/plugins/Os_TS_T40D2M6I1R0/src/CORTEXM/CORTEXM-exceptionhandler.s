/* CORTEXM-exceptionhandler.s
 *
 * This file contains the exception handlers.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: CORTEXM-exceptionhandler.s 1.1 2023/04/18 07:06:17CEST Dan Dustinta (dan.dustinta) in_work  $
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

/* Bits in CFSR */

/* Derived memmanage fault occured on exception entry. */
#define OS_MSTKERR	((1 << 4) << 0)
/* Derived bus fault occured on exception entry. */
#define OS_STKERR	((1 << 4) << 8)

	OS_ASM_SECTION_TEXT
	OS_ASM_CODE_THUMB

	OS_global OS_ExceptionNMIHandler
	OS_global OS_ExceptionHardFaultHandler
	OS_global OS_ExceptionMemManageHandler
	OS_global OS_ExceptionBusFaultHandler
	OS_global OS_ExceptionUsageFaultHandler
	OS_global OS_ExceptionReservedHandler_1
	OS_global OS_ExceptionReservedHandler_2
	OS_global OS_ExceptionReservedHandler_3
	OS_global OS_ExceptionReservedHandler_4
	OS_global OS_ExceptionDebugHandler
	OS_global OS_ExceptionReservedHandler_5
	OS_global OS_ExceptionPendSVHandler
	OS_global OS_ExceptionSysTickHandler
	OS_global OS_ExceptionHandler
	OS_global OS_CORTEXM_K_Exception

	OS_extern OS_Exception
	OS_extern OS_CheckForDispatch
	OS_extern OS_CORTEXM_Dispatch
	OS_extern OS_Dispatch
	OS_extern OS_kernel_ptr
	OS_extern boardNmiCallBack


	OS_align(4, 2)

	/* The address of the system handler control and status register */
	OS_GENLIT_ACTIVATE_SVC

	/* Data label: cover the following OS_ASM_LABEL declarations */
	OS_ASM_DATALABEL

OS_ASM_LABEL(OS_CORTEXM_EXC_RETURN_Value)
	OS_word OS_CORTEXM_EXC_RETURN_HANDLER_MSP

	/* The address of the kernel data */
OS_ASM_LABEL(OS_kernelDataAddr)
	OS_word	OS_kernel_ptr

	/* The address of the hard fault status register register */
OS_ASM_LABEL(HFSR_Addr)
	OS_word OS_CORTEXM_HFSR

	/* The address of the configurable fault status register */
OS_ASM_LABEL(CFSR_Addr)
	OS_word OS_CORTEXM_CFSR

	/* The address of the mem manage fault address register */
OS_ASM_LABEL(MMFAR_Addr)
	OS_word OS_CORTEXM_MMFAR

	/* The address of the bus fault address register */
OS_ASM_LABEL(BFAR_Addr)
	OS_word OS_CORTEXM_BFAR

OS_ASM_LABEL(OS_ExceptionHandlerSvcAddr)
	OS_word	OS_ExceptionHandlerSvc

/* CFSR bits that indicate a derived fault on exception entry.
 * IOW, the saved context is not usable and must not get accessed.
*/
OS_ASM_LABEL(OS_CFSR_DerivedFault)
#if (OS_TOOL==OS_arm5)
	OS_word (OS_MSTKERR :OR: OS_STKERR)
#else /* (OS_TOOL!=OS_arm5) */
	OS_word (OS_MSTKERR | OS_STKERR)
#endif /* (OS_TOOL==OS_arm5) */

/* Comment: This routine is called for reserved exceptions, which cannot
 * happen by hardware.
 * (However, a wayward jump might land there)
*/
	OS_ASM_FUNC(OS_CORTEXM_PanicStop)
OS_ASM_LABEL(OS_CORTEXM_PanicStop)
	b		OS_CORTEXM_PanicStop
	OS_ASM_END_FUNC(OS_CORTEXM_PanicStop)

/*
 * OS_ExceptionNMIHandler
 *
 * This is a handler for the non maskable interrupt exception.
 * The NMI is the highest priority exception other than reset.
 * It is permanently enabled with a fixed priority of -2.
 * Hardware can generate an NMI, or software can set the NMI exception to the Pending state,
 * see Interrupt Control and State Register, ICSR in the Cortex-M manual.
*/
	OS_ASM_FUNC(OS_ExceptionNMIHandler)
OS_ASM_LABEL(OS_ExceptionNMIHandler)
	cpsid	f								/* Lock all interrupts */
	OS_LEAVE_NON_TRUSTED	r0, r2, r1
	push	{r1,lr}
	bl		boardNmiCallBack
	pop		{r1,lr}
	mov		r0, #OS_CORTEXM_EX_NMI
	ldr		r12, OS_SHCSR_Addr				/* system handler control and status register */
	ldr		r2, [r12]
	mov		r3, #0							/* no NMI address register available */
	b		OS_ExceptionHandler				/* branch to the generic handler */
	OS_ASM_END_FUNC(OS_ExceptionNMIHandler)


/*
 * OS_ExceptionHardFaultHandler
 *
 * This is a handler for the hard fault exception.
 * The HardFault is the generic fault that exists for all classes of fault that cannot be handled
 * by any of the other exception mechanisms. Typically, HardFault is used for unrecoverable system
 * failures, although this is not required and some uses of HardFault might be recoverable.
 * HardFault is permanently enabled with a fixed priority of -1.
 * HardFault is used for fault escalation, see Priority escalation in the Cortex-M manual.
*/
	OS_ASM_FUNC(OS_ExceptionHardFaultHandler)
OS_ASM_LABEL(OS_ExceptionHardFaultHandler)
	cpsid	f								/* Lock all interrupts */
	OS_LEAVE_NON_TRUSTED	r0, r2, r1
	mov		r0, #OS_CORTEXM_EX_HARD_FAULT
	ldr		r12, HFSR_Addr					/* hard fault status register */
	ldr		r2, [r12]
	str		r2, [r12]						/* writing back value to reset exception status in HFSR */
	mov		r3, #0							/* no hard fault address register available */
	b		OS_ExceptionHandler				/* branch to the generic handler */
	OS_ASM_END_FUNC(OS_ExceptionHardFaultHandler)


/*
 * OS_ExceptionMemManageHandler
 *
 * This is a handler for the memory management exception.
 * The MemManage fault handles memory protection faults that are determined by the Memory Protection Unit
 * or by fixed memory protection constraints, for both instruction and data memory transactions.
 * Software can disable this fault. If it does, a MemManage fault escalates to HardFault.
 * MemManage has a configurable priority.
*/
	OS_ASM_FUNC(OS_ExceptionMemManageHandler)
OS_ASM_LABEL(OS_ExceptionMemManageHandler)
	cpsid	f								/* Lock all interrupts */
	OS_LEAVE_NON_TRUSTED	r0, r2, r1
	ldr		r12, CFSR_Addr					/* configurable fault status register */
	ldr		r2, [r12]
	ldr		r3, MMFAR_Addr					/* mem manage fault address register */
	ldr		r3, [r3]
	and 	r0, r2, #0xFF						/* masking MMFSR bits for CFSR register */
	str		r0, [r12]						/* writing back value to reset exception status in CFSR */
	mov		r0, #OS_CORTEXM_EX_MEM_MANAGE
	ldr		r12, OS_CFSR_DerivedFault
	tst		r2, r12
	bne		OS_NoContext
	b		OS_ExceptionHandler				/* branch to the generic handler */
	OS_ASM_END_FUNC(OS_ExceptionMemManageHandler)


/*
 * OS_ExceptionBusFaultHandler
 *
 * This is a handler for the bus fault exception.
 * The BusFault fault handles memory-related faults, other than those handled by the
 * MemManage fault, for both instruction and data memory transactions.
 * Typically these faults arise from errors detected on the system buses.
 * The architecture permits an implementation to report synchronous or asynchronous
 * BusFaults according to the circumstances that trigger the exceptions.
 * Software can disable this fault. If it does, a BusFault escalates to HardFault.
 * BusFault has a configurable priority.
*/
	OS_ASM_FUNC(OS_ExceptionBusFaultHandler)
OS_ASM_LABEL(OS_ExceptionBusFaultHandler)
	cpsid	f								/* Lock all interrupts */
	OS_LEAVE_NON_TRUSTED	r0, r2, r1
	ldr		r12, CFSR_Addr					/* configurable fault status register */
	ldr		r2, [r12]
	ldr		r3, BFAR_Addr					/* bus fault address register */
	ldr		r3, [r3]
	and		r0, r2, #0xFF00					/* masking BFSR bits for CFSR register */
	str		r0, [r12]						/* writing back value to reset exception status in CFSR */
	mov		r0, #OS_CORTEXM_EX_BUS_FAULT
	ldr		r12, OS_CFSR_DerivedFault
	tst		r2, r12
	bne		OS_NoContext
	b		OS_ExceptionHandler				/* branch to the generic handler */
	OS_ASM_END_FUNC(OS_ExceptionBusFaultHandler)


/*
 * OS_ExceptionUsageFaultHandler
 *
 * This is a handler for the usage fault exception.
 * The UsageFault fault handles non-memory related faults caused by instruction execution.
 * A number of different situations cause usage faults, including:
 * - Undefined Instruction
 * - invalid state on instruction execution
 * - error on exception return
 * - attempting to access a disabled or unavailable coprocessor.
 * The following can cause usage faults when the processor is configured to report them:
 * - a word or halfword memory accesses to an unaligned address
 * - division by zero.
 * Software can disable this fault. If it does, a UsageFault escalates to HardFault.
 * UsageFault has a configurable priority.
*/
	OS_ASM_FUNC(OS_ExceptionUsageFaultHandler)
OS_ASM_LABEL(OS_ExceptionUsageFaultHandler)
	cpsid	f								/* Lock all interrupts */
	OS_LEAVE_NON_TRUSTED	r0, r2, r1
	mov		r0, #OS_CORTEXM_EX_USAGE_FAULT
	ldr		r12, CFSR_Addr					/* configurable fault status register */
	ldr		r2, [r12]
	lsr		r3, r2, #16						/* masking USFR bits for CFSR register (0xFFFF0000) */
	lsl		r3, r3, #16
	str		r3, [r12]						/* writing back value to reset exception status in CFSR */
	mov		r3, #0							/* no usage fault address register available */
	b		OS_ExceptionHandler				/* branch to the generic handler */
	OS_ASM_END_FUNC(OS_ExceptionUsageFaultHandler)


/*
 * OS_ExceptionReservedHandler_1
 *
 * This is a handler for the 1st reserved exception and should normally not be called
 *
 * There is no return instruction here
 *
*/
	OS_ASM_FUNC(OS_ExceptionReservedHandler_1)
OS_ASM_LABEL(OS_ExceptionReservedHandler_1)
	b		OS_CORTEXM_PanicStop
	OS_ASM_END_FUNC(OS_ExceptionReservedHandler_1)


/*
 * OS_ExceptionReservedHandler_2
 *
 * This is a handler for the 2nd reserved exception and should normally not be called
*/
	OS_ASM_FUNC(OS_ExceptionReservedHandler_2)
OS_ASM_LABEL(OS_ExceptionReservedHandler_2)
	b		OS_CORTEXM_PanicStop
	OS_ASM_END_FUNC(OS_ExceptionReservedHandler_2)


/*
 * OS_ExceptionReservedHandler_3
 *
 * This is a handler for the 3rd reserved exception and should normally not be called
*/
	OS_ASM_FUNC(OS_ExceptionReservedHandler_3)
OS_ASM_LABEL(OS_ExceptionReservedHandler_3)
	b		OS_CORTEXM_PanicStop
	OS_ASM_END_FUNC(OS_ExceptionReservedHandler_3)


/*
 * OS_ExceptionReservedHandler_4
 *
 * This is a handler for the 4th reserved exception and should normally not be called
*/
	OS_ASM_FUNC(OS_ExceptionReservedHandler_4)
OS_ASM_LABEL(OS_ExceptionReservedHandler_4)
	b		OS_CORTEXM_PanicStop
	OS_ASM_END_FUNC(OS_ExceptionReservedHandler_4)


/*
 * OS_ExceptionSVCallHandler
 *
 * This is a handler for the SVCall exception.
 * The supervisor call handles the exception caused by the SVC instruction.
 * SVCall is permanently enabled and has a configurable priority.
 * In a function call kernel this exception should normally not be called.
 * In case of a system call kernel this handler is replaced
 * by a special OS handler to call the specified system service.
*/
#if (OS_KERNEL_TYPE==OS_FUNCTION_CALL)
#error "Function call kernel not supported."
#endif


/*
 * OS_ExceptionDebugHandler
 *
 * This is a handler for the debug monitor exception.
 * In general, this exception is a synchronous exception and classified as a fault.
 * This exception occurs when halting debug is disabled, and debug monitor support is enabled.
 * The DebugMonitor exception has a configurable priority.
 * See Priority escalation and Debug event behavior in the Cortex-M manual.
 *
 * There is no return instruction here
 *
*/
	OS_ASM_FUNC(OS_ExceptionDebugHandler)
OS_ASM_LABEL(OS_ExceptionDebugHandler)
	cpsid	f								/* Lock all interrupts */
	OS_LEAVE_NON_TRUSTED	r0, r2, r1
	mov		r0, #OS_CORTEXM_EX_DEBUG
	ldr		r12, OS_SHCSR_Addr				/* system handler control and status register */
	ldr		r2, [r12]
	mov		r3, #0							/* no fault address register available */
	b		OS_ExceptionHandler				/* branch to the generic handler */
	OS_ASM_END_FUNC(OS_ExceptionDebugHandler)


/*
 * OS_ExceptionReservedHandler_5
 *
 * This is a handler for the 5th reserved exception and should normally not be called.
*/
	OS_ASM_FUNC(OS_ExceptionReservedHandler_5)
OS_ASM_LABEL(OS_ExceptionReservedHandler_5)
	b		OS_CORTEXM_PanicStop
	OS_ASM_END_FUNC(OS_ExceptionReservedHandler_5)


/*
 * OS_ExceptionPendSVHandler
 *
 * This is a handler for the pend supervisor call exception.
 * This is a system-level interrupt used for software-generated system calls.
 * For a Supervisor call that executes synchronously with program execution,
 * software must use the SVC instruction. This generates an SVCall exception.
 * PendSV is permanently enabled, and is controlled using the ICSR.PENDSVSET and ICSR.PENDSVCLR bits.
*/
	OS_ASM_FUNC(OS_ExceptionPendSVHandler)
OS_ASM_LABEL(OS_ExceptionPendSVHandler)
	cpsid	f								/* Lock all interrupts */
	OS_LEAVE_NON_TRUSTED	r0, r2, r1
	mov		r0, #OS_CORTEXM_EX_PEND_SV
	ldr		r12, OS_SHCSR_Addr				/* system handler control and status register */
	ldr		r2, [r12]
	mov		r3, #0							/* no pend SVCall address register available */
	b		OS_ExceptionHandler				/* branch to the generic handler */
	OS_ASM_END_FUNC(OS_ExceptionPendSVHandler)


/*
 * OS_ExceptionSysTickHandler
 *
 * This is a handler for the system tick timer exception.
 * This is a system-level interrupt generated by the SysTick timer.
 * The SysTick is an integral component of an CORTEXMv7-M processor.
 * SysTick is permanently enabled, it is controlled by ICSR.PENDSTSET and ICSR.PENDSTCLR.
 * Software can suppress hardware generation of the SysTick event.
*/
	OS_ASM_FUNC(OS_ExceptionSysTickHandler)
OS_ASM_LABEL(OS_ExceptionSysTickHandler)
	cpsid	f								/* Lock all interrupts */
	OS_LEAVE_NON_TRUSTED	r0, r2, r1
	mov		r0, #OS_CORTEXM_EX_SYS_TICK
	ldr		r12, OS_SHCSR_Addr				/* system handler control and status register */
	ldr		r2, [r12]
	mov		r3, #0							/* no sys tick address register available */
	b		OS_ExceptionHandler				/* branch to the generic handler */
	OS_ASM_END_FUNC(OS_ExceptionSysTickHandler)


/* OS_NoContext
 *
 * This is the exception entry handler in case the context could not get
 * saved. It must fake a context to continue with the exception handler.
 * It may overwrite any register, since the context is already kaput.
 *
 * The exception number is stored in r0.
 * Old MPU state is stored in r1.
 * The fault status register is stored in r2.
 * The fault address register is stored in r3.
*/
	OS_ASM_FUNC(OS_NoContext)
OS_ASM_LABEL(OS_NoContext)
	/* Save non-volatile context */
	push	{ r4-r11, lr }
	OS_DISABLE_FPU r5, r6, r7
	/* Save old MPU state and FPU state or alignment gap */
	push	{ r1, r7 }

	/* Store old interrupt lock level and lock on maximum level */
	mov		r10, #1
	OS_SETLEVEL	r10, r11
	push	{ r11 }

	/* We can re-enable interrupts now, since they are locked
	 * with FAULTMASK
	*/
	cpsie	f

	/* Modify control to have thread mode privileged. Otherwise, when
	 * we fake our return to task level, we may not be able to do a system
	 * call because we cannot write to the main stack.
	 */
	mrs		r4, CONTROL

	/* Save a few things on the stack that we need later on */
	/* exception number, fault status, fault address, old CONTROL, dummy
	 * for alignment and exception return value. */
	push	{r0, r2, r3, r4, r5, lr}

	/* Clear the NPRIV bit so that thread mode is privileged. */
	bic		r4, r4, #OS_CORTEXM_CONTROL_NPRIV
	msr		CONTROL, r4

	/* check which stack was used to save the context and load
	 * top address of context to r0.
	*/
	tst		lr, #OS_CORTEXM_EXC_RETURN_MODE_THREAD
	it		NE
	tstne	lr, #OS_CORTEXM_EXC_RETURN_STACK_PSP
	itee	NE
	/* Process stack. */
	mrsne	r0, psp
	/* Main stack: We just pushed 18 words, adjust pointer to context
	 * accordingly.
	*/
	mrseq	r0, msp
	addeq	r0, r0, #(18 * 4)

	/* r1 := top of our stack (to later get hold of what we just saved.) */
	mov		r1, sp

	/* Perform a return from exception to "acknowledge" the
	 * exception.
	 * Since we call the ProtectionHook later on, the exception must
	 * be inactive, otherwise we cannot make supervisor calls.
	 * Simply clearing the active flag would do as well, but we would
	 * need to restore it on various ways that leave the kernel. It's
	 * more straightforward to just return from exception here.
	*/

	/* Prepare return address and xPSR */
	ldr		r2, OS_ExceptionHandlerSvcAddr
	/* Fake XPSR: Thread mode, and no conditional execution.
	 * (We know where we are jumping to!
	 * -> Only T bit required.
	*/
	mov		r3, #OS_CORTEXM_EPSR_T

	/* When returning to handler mode, set the exception number to something
	 * not zero in XPSR. Otherwise there will be a INVPC UsageFault when
	 * nesting on the activation of the exception handler happens.
	*/
	ldr		r6, OS_CORTEXM_EXC_RETURN_Value
	cmp		lr, r6
	it		EQ
	orreq	r3, r3, #4			/* Set exception number to 4 (MemManageFault) */

	push	{r2, r3}

	/* Volatile registers */
	push	{r0, r1, r2, r3, r12, lr}

	/* Return to original mode but use main stack (in case we came here
	 * by a stack overflow!)
	*/
	bic		lr, lr, #(1 << 2)
#if (OS_CORTEXM_HAS_ERRATA_838869 == 1)
	/* workaround ARM Erratum 838869 (see ASCOS-5685) on all Cortex-M4/M4F */
	dsb
#endif
	/* And return from exception to get rid of the exception active flags.
	*/
	bx		lr
	/* NOT REACHED */
	b		OS_CORTEXM_PanicStop

	OS_ASM_END_FUNC(OS_NoContext)

/*
 * OS_ExceptionHandler
 *
 * This is the common exception handler for all exceptions.
 * It is called by the specific exception handlers.
 *
 * The exception number is stored in r0.
 * Old MPU state is stored in r1.
 * The fault status register is stored in r2.
 * The fault address register is stored in r3.
*/
	OS_ASM_FUNC(OS_ExceptionHandler)
OS_ASM_LABEL(OS_ExceptionHandler)
	/* Save non-volatile context */
	push	{r4-r11, lr}
	OS_DISABLE_FPU r5, r6, r7
	/* Save old MPU state and FPU state or alignment gap */
	push	{ r1, r7 }

	/* Store old interrupt lock level and lock on maximum level via BASEPRI */
	mov		r10, #1
	OS_SETLEVEL	r10, r11
	push	{ r11 }

	/* We can re-enable interrupts now, since they are disabled with BASEPRI
	*/
	cpsie	f
	cpsie	i

	/* Modify control to have thread mode privileged. Otherwise, when
	 * we fake our return to task level, we may not be able to do a system
	 * call because we cannot write to the main stack.
	 */
	mrs		r4, CONTROL

	/* Save a few things on the stack that we need later on */
	/* exception number, fault status, fault address, old CONTROL, dummy
	 * for alignment and exception return value. */
	push	{r0, r2, r3, r4, r5, lr}

	/* Clear the NPRIV bit so that thread mode is privileged. */
	bic		r4, r4, #OS_CORTEXM_CONTROL_NPRIV
	msr		CONTROL, r4

	/* check which stack was used to save the context and load
	 * top address of context to r0.
	*/
	tst		lr, #OS_CORTEXM_EXC_RETURN_MODE_THREAD
	it		NE
	tstne	lr, #OS_CORTEXM_EXC_RETURN_STACK_PSP
	itee	NE
	/* Process stack. */
	mrsne	r0, psp
	/* Main stack: We just pushed 18 words, adjust pointer to context
	 * accordingly.
	*/
	mrseq	r0, msp
	addeq	r0, r0, #(18 * 4)

	/* r1 := top of our stack (to later get hold of what we just saved.) */
	mov		r1, sp

	/* Perform a return from exception to "acknowledge" the
	 * exception.
	 * Since we call the ProtectionHook later on, the exception must
	 * be inactive, otherwise we cannot make supervisor calls.
	 * Simply clearing the active flag would do as well, but we would
	 * need to restore it on various ways that leave the kernel. It's
	 * more straightforward to just return from exception here.
	*/

	/* Prepare return address and xPSR
	 * We jump to a known function, so the conditional execution bits can be
	 * ignored. We only need to set the T bit.
	*/
	ldr		r2, OS_ExceptionHandlerSvcAddr
	mov		r3, #OS_CORTEXM_EPSR_T

	/* If the original mode was handler mode, we need to set the exception
	 * number to something to prevent causing INVPC exception with our faked
	 * exception return. We use the SVCall vector number for this.
	*/
	tst		lr, #OS_CORTEXM_EXC_RETURN_MODE_THREAD
	it		EQ
	orreq	r3, r3, #0xb

	push	{r2, r3}

	/* Volatile registers */
	push	{r0, r1, r2, r3, r12, lr}

	/* Return to original mode but use main stack (in case we came here
	 * by a stack overflow!)
	*/
	bic		lr, lr, #(1 << 2)
#if (OS_CORTEXM_HAS_ERRATA_838869 == 1)
	/* workaround ARM Erratum 838869 (see ASCOS-5685) on all Cortex-M4/M4F */
	dsb
#endif
	/* And return from exception to get rid of the exception active flags.
	*/
	bx		lr
	/* NOT REACHED */
	b		OS_CORTEXM_PanicStop
	OS_ASM_END_FUNC(OS_ExceptionHandler)


/* OS_ExceptionHandlerSvc - continuation of OS_ExceptionHandler.
 * This function is "called" by a return from exception from OS_ExceptionHandler.
 * Therefore it runs in the context of the object that caused the exception.

 * It performs a SVC (to re-enter the kernel) that will land here again.
 *
 * r0 - contains the bottom address of the context.
 * r1 - contains the bottom address of our stored exception number, fault status,
 *		fault address, control register and exception return value.
*/
	OS_ASM_FUNC(OS_ExceptionHandlerSvc)
OS_ASM_LABEL(OS_ExceptionHandlerSvc)
	mov		r12, #OS_SC_CPUFAMILY_1
	svc		#0
	/* NOT REACHED */
	b		OS_CORTEXM_PanicStop
	OS_ASM_END_FUNC(OS_ExceptionHandlerSvc)

/* OS_CORTEXM_K_Exception - continuation of OS_ExceptionHandlerSvc.
 * This function is called by the system call handler (so that we are back
 * in the kernel and can use our standard procedure to return from it).
 *
 * It is executed in handler mode on the main stack, always!
 * It requires:
 * - r0 points to the bottom of the context
 * - r1 points to the bottom of the stored information.
 *
 * Attention: This system call is not exactly security proof, since an
 * attacker could forge a manipulated context. (But even then there's still
 * the hardware checks on exception return.)
*/
	OS_ASM_FUNC(OS_CORTEXM_K_Exception)
OS_ASM_LABEL(OS_CORTEXM_K_Exception)
	mov		r4, r0			/* r4 := bottom of context */
	mov		r5, r1			/* r5 := bottom of stored stuff */

	ldr		r0, [r5, #0]	/* r0 := exception number */
	ldr		r2, [r5, #4]	/* r2 := fault status */
	ldr		r3, [r5, #8]	/* r3 := fault address */
	ldr		r7, [r5, #12]	/* r7 := old CONTROL value */
	ldr		r6, [r5, #20]	/* r6 := exception return value */

	/* Switch back to old CONTROL value */
	msr		CONTROL, r7

	ldr		r1, [r4, #(0x18)]				/* r1 := return address */

	bl		OS_Exception					/* branch to exception */


	/* Check which stack was used to save the original context to
	 * determine the value of the old inKernel-flag.
	*/
	tst		r6, #OS_CORTEXM_EXC_RETURN_MODE_THREAD
	it		NE
	tstne	r6, #OS_CORTEXM_EXC_RETURN_STACK_PSP
	ite		NE
	movne	r7, #0	/* old_inKernel = 0; */
	moveq	r7, #1	/* old_inKernel = 1; */

	/* Check, if we have to dispatch */
	mov		r0, r7
	bl		OS_CheckForDispatch		/* OS_CheckForDispatch(old_inKernel) */

	cmp		r0, #OS_NO_DISP
	beq		OS_Exc_JustReturn

	cmp		r0, #OS_DISP_WITHOUT_SAVE
	beq		OS_Exc_WithoutSave

	/* Dispatch and save context.
	 * Note: r4 is always the process stack pointer, since tasks run
	 * on the process stack.
	*/
	add		r0, sp, #(6 * 4)	/* our stuff=6 words, context starts above */
	mov		r1, r4
	bl		OS_CORTEXM_Dispatch

	/* We don't care about
	 * - the stack, since dispatching resets the kernel stack
	 * - the lock level, since dispatching changes the lock level.
	*/
	bl		OS_Dispatch
	/* NOT REACHED */
	b		OS_CORTEXM_PanicStop

OS_ASM_LABEL(OS_Exc_WithoutSave)
	/* No need to save anything, the caller is no more. */
	mov		r0, #OS_TS_READY_SYNC
	bl		OS_Dispatch					/* call OS_Dispatch(OS_TS_READY_SYNC) */
	/* NOT REACHED */
	b		OS_CORTEXM_PanicStop

OS_ASM_LABEL(OS_Exc_JustReturn)
	/* Activate SVC in SHCSR */
	OS_ACTIVATE_SVC		r1, r2

	/* Restore inKernel flag. */
	OS_GET_KERNEL_PTR	OS_kernelDataAddr, r8, r0
	str		r7, [r8, #OS_T_INKERNEL]

	/* Restore (main) stack pointer */
	mov		sp, r5
	/* Restore our stored stuff (actually only lr is required) */
	pop		{r0, r2, r3, r4, r5, lr}

	/* Load
	 * - old interrupt lock level (r0)
	 * - old MPU state (r1)
	 * - old FPU state or gap (r2)
	*/
	pop		{r0, r1, r2}

#if ((OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE) && !defined(OS_EXCLUDE_HW_FP))
	/* Restore old FPU state */
	tst		r2, #0x00f00000
	beq		OS_ExceptionHandler_SkipEnableFpu

	OS_ENABLE_FPU	r5, r2, r2
OS_ASM_LABEL(OS_ExceptionHandler_SkipEnableFpu)
#endif

	OS_SETLEVEL	r0, r2

	cpsid	f
	/* Restore old MPU state */
	OS_RESTORE_NON_TRUSTED	r0, r2, r1

	/* Restore non-volatile context */
	pop		{r4-r11}
	sub		sp, sp, #4

#if (OS_CORTEXM_HAS_ERRATA_838869 == 1)
	/* workaround ARM Erratum 838869 (see ASCOS-5685) on all Cortex-M4/M4F */
	dsb
#endif

	/* And return from exception */
	bx		lr
	OS_ASM_END_FUNC(OS_CORTEXM_K_Exception)

	OS_ASM_SRC_END

#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
