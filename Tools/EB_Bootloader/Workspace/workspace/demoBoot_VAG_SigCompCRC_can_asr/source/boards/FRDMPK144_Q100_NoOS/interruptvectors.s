/* CORTEXM-interruptvectors.s
 *
 * Interrupt vector configuration. See also <include/CORTEXM/Os_CORTEXM_int.h>.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: interruptvectors.s 1.2.1.2 2022/09/01 06:53:04CEST Andrei Anca (andrei.anca) in_work  $
*/

#ifndef BOARD_ASM
#define BOARD_ASM
#endif

#include <Platforms_asm_CORTEXM.h>
#include <board.h>


/* IRQ entries for VIM must be encoded in CORTEXM instruction set */

    PLATFORMS_ASM_SECTION_INTTAB
    PLATFORMS_ASM_CODE_THUMB
    Platforms_global CORTEXMInterruptTable
    Platforms_extern BoardIsrHandler
    Platforms_extern OS_kernelData

    Platforms_align(4, 2)

    PLATFORMS_ASM_DATALABEL

/* The vector table contains both, exception and interrupt vectors.
 * The exception vector table with 16 entries precedes the interrupt table.
 * Only the size of the interrupt table is configurable and depends on the number
 * of NVIC sources.
*/
PLATFORMS_ASM_LABEL(CORTEXMInterruptTable)
#if (BOARD_CORTEXM_NUM_SOURCES > (16-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (32-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (48-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (64-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (80-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (96-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (112-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (128-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (144-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (160-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (176-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (192-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (208-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (224-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (240-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (256-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (272-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (288-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (304-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (320-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (336-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (352-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (368-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (384-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (400-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (416-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (432-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (448-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (464-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (480-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (496-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if (BOARD_CORTEXM_NUM_SOURCES > (512-16))
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
    Platforms_word BoardIsrHandler
#endif

#if 0
    OS_GENLIT_MPU

/* DispatchInterrupt: Macro to dispatch one interrupt.
 * isrid: number of ISR.
 * entry: address of entry function
 * exit: address of exit function
 * level: selected locking level
 * corevar: Label with address of kernel core variables.
 */
OS_MACRO_PREPARE_START()
OS_MACRO_START_P5(DispatchInterrupt, isrid, entry, exit, level, corevar)
    /* we are now in handler mode, interrupts still enabled */
    /* Disable interrupts */
    cpsid   i

    OS_DISABLE_MPU_GET_STATE    r0, r1, r2
    /* Save non-volatile registers */
    push    {r4-r11, lr}
    /* Save old MPU state and gap for alignment */
    push    {r2, r3}

    /* OS_inKernel = 1; */
    OS_GET_KERNEL_PTR   OS_PAR(corevar, 5), r1
    mov     r0, #1
    /* Note: No need to track the old inKernel value: We use the return
     * mode to track, if we return to a task and need to dispatch.
     * Tasks are executed in thread mode, anything else in handler mode.
    */
    strb    r0, [r1, #OS_T_INKERNEL]

    mov     r2, #OS_PAR(level, 4)           /* set interrupt disabling level */
    OS_SETLEVEL     r2, r0
    push    {r0}                            /* save previous lock level on stack */

#if (OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE)
    vstmdb  sp!, {s0-s15}           /* save volatile FPU context: Registers */
    vmrs    r0, fpscr
    push    {r0, r1}                /* FPSCR and alignment gap. */
#endif

    /* now it's safe to enable all interrupts */
    cpsie   i

    /* <entry>(<isrid>); call entry function with interrupt id */
    mov     r0, #OS_PAR(isrid, 1)
    bl      OS_PAR(entry, 2)

    /* <exit>(); call exit function. */
    bl      OS_PAR(exit, 3)
    /* NOT REACHED */

OS_MACRO_END()

PLATFORMS_ASM_LABEL(OS_kernelDataAddr)
    Platforms_word OS_kernelData

/* dispatcher for unknown interrupts */
    OS_ASM_FUNC(DispatchUnknownInterrupt)
PLATFORMS_ASM_LABEL(DispatchUnknownInterrupt)
    /* we are now in handler mode, with interrupts disabled */
    /* partial context already saved by CPU on interrupted stack */

    /* disable interrupts */
    cpsid   i

    OS_DISABLE_MPU_GET_STATE    r0, r1, r2
    /* Save non-volatile registers */
    push    {r4-r11, lr}
    /* Save
     * - gap for alignment (r3)
     * - old MPU state (r2)
     * - gap for old interrupt level (r1)
    */
    push    {r1, r2, r3}

    /* OS_inKernel = 1; */
    OS_GET_KERNEL_PTR   OS_kernelDataAddr, r7
    mov     r0, #1
    /* r6 = old OS_inKernel */
    ldrb    r6, [r7, #OS_T_INKERNEL]
    strb    r0, [r7, #OS_T_INKERNEL]

    /* lock interrupts on kernel level (unless higher already) */
    bl      OS_IntDisableConditional
    /* old lock level -> r5 */
    mov     r5, r0
    /* Store old lock level on gap on stack */
    str     r5, [sp]

#if (OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE)
    vstmdb  sp!, {s0-s15}           /* save volatile FPU context: Registers */
    vmrs    r0, fpscr
    push    {r0, r1}                /* FPSCR and alignment gap. */
#endif

    /* disable the unknown interrupt */
    bl      OS_CORTEXM_IntDisableUnknownInterrupt
    /* it is safe to reenable interrupts now */
    cpsie   i

    /* branch to entry routine */
    bl      OS_CORTEXM_UNKNOWN_INTERRUPT

    /* disable interrupts again, restore the old lock level from r5 */
    cpsid   i
    isb
    mov     r0, r5
    OS_SETLEVEL r0, r1
    /* restore context and return from exception */

    /* OS_inKernel = old_inKernel; */
    strb    r6, [r7, #OS_T_INKERNEL]

#if (OS_CORTEXM_FPU != OS_CORTEXM_FPU_NONE)
    /* Restore volatile FPU context. */
    pop     {r0, r1}
    vmsr    fpscr, r0               /*  restore floating point status register */
    vldmia  sp!, {s0-s15}           /* save volatile FPU context: Registers */
#endif

    OS_LEAVE_RESTORE_CONTEXT

    PLATFORMS_ASM_END_FUNC(DispatchUnknownInterrupt)

    /* OS_CORTEXM_IntCat1Exit(os_uint8_t inKernel)
     *
     * set OS_inKernel to old value and return from interrupt.
    */
    OS_ASM_FUNC(OS_CORTEXM_IntCat1Exit)
PLATFORMS_ASM_LABEL(OS_CORTEXM_IntCat1Exit)
    /* Check magic return from exception value, if we
     * return to a task (thread mode, psp).
     * This equals an old inKernel
     * flag of 0 (return to task) or 1 (return to interrupt).
     *
     * if (stack[OS_CORTEXM_POS_LR] == OS_CORTEXM_EXC_RETURN_THREAD_PSP)
     * {
     *'    r0 = 0;
     * }
     * else
     * {
     *     r0 = 1;
     * }
    */
    ldr     r12,    [sp, #OS_CORTEXM_POS_LR]
    cmn     r12,    #-OS_CORTEXM_EXC_RETURN_THREAD_PSP
    ite     EQ
    moveq   r0, #0
    movne   r0, #1

    /* OS_inKernel = inKernel */
    OS_GET_KERNEL_PTR   OS_kernelDataAddr, r1
    strb    r0, [r1, #OS_T_INKERNEL]
    /* just return from interrupt */
    bl      OS_CORTEXM_IntReturnFromInterrupt

    PLATFORMS_ASM_END_FUNC(OS_CORTEXM_IntCat1Exit)
#endif


    PLATFORMS_ASM_SRC_END

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
 */
