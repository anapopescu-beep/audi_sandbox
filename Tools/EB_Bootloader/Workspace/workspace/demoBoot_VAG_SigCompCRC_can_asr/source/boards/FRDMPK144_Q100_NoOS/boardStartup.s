/* boardStartup.s - board specific assembly startup code.
 *
 * This file contains the early startup code implemented in assembly.
 * It exports the following functions:
 *  boardResetStart: Reset vector.
 *  boardInvalidInterrupt: Handler for invalid / spurious interrupts if
 *                         ErrorHandling is set to MINIMAL.
 *  boardInvalidException: Handler for exceptions if ExceptionHandling is
 *                         disabled.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: boardStartup.s 1.2.1.2 2022/09/01 06:53:04CEST Andrei Anca (andrei.anca) in_work  $
*/

#ifndef BOARD_ASM
#define BOARD_ASM
#endif

/* Must be first */
#include <Platforms_asm_CORTEXM.h>
#include <board.h>


    PLATFORMS_ASM_SECTION_TEXT
    PLATFORMS_ASM_CODE_THUMB

    Platforms_global boardResetStart
    Platforms_global boardInvalidInterrupt
    Platforms_global boardInvalidException
    Platforms_global boardDisableInterruptsAsm
    Platforms_global boardEnableInterruptsAsm
    Platforms_global Board_CORTEXM_EnableVFPCoprocessor
    Platforms_global BOARD_GET_ISR_SRC
    Platforms_extern BoardStart
    Platforms_extern CORTEXMExceptionTable
    Platforms_extern BoardStack

    PLATFORMS_ASM_FUNC(boardInvalidInterrupt)
PLATFORMS_ASM_LABEL(boardInvalidInterrupt)
    b       boardInvalidInterrupt
    PLATFORMS_ASM_END_FUNC(boardInvalidInterrupt)


/*
 * boardInvalidException()
 *
 * The boardInvalidException() routine is used for uninitialized
 * vectors of the exception table if Exception handling is off.
 *
*/
    PLATFORMS_ASM_FUNC(boardInvalidException)
PLATFORMS_ASM_LABEL(boardInvalidException)
    b       boardInvalidException
    PLATFORMS_ASM_END_FUNC(boardInvalidException)

    /* The value for the system handler control and status register */
PLATFORMS_ASM_LABEL(SHCSR_Value)
    Platforms_word 0x00070000

    /* The address of the system handler control and status register */
PLATFORMS_ASM_LABEL(SHCSR_Addr)
    Platforms_word 0xE000ED24

    /* Address of vector offset register */
PLATFORMS_ASM_LABEL(VTOR_Addr)
    Platforms_word 0xE000ED08

    /* Watchdog (WDOG) CS and TOVAL registers with initial values */
PLATFORMS_ASM_LABEL(WDOGCS_Addr)
    Platforms_word 0x40052000
PLATFORMS_ASM_LABEL(WDOGCS_InitVal)
    Platforms_word 0x000021A0
PLATFORMS_ASM_LABEL(WDOGTOVAL_Addr)
    Platforms_word 0x40052008
PLATFORMS_ASM_LABEL(WDOGTOVAL_InitVal)
    Platforms_word 0x00000500

    /* Address of exception table */
PLATFORMS_ASM_LABEL(ExceptionTableAddr)
    Platforms_word CORTEXMExceptionTable

PLATFORMS_ASM_LABEL(BoardspInitial)
    Platforms_word (BoardStack + ISTACKLEN*4)


/* Address of FPCCR */
PLATFORMS_ASM_LABEL(PLATFORMS_FPCCR_addr)
  Platforms_word 0xE000EF34

/* Address of CPACR */
PLATFORMS_ASM_LABEL(PLATFORMS_CPACR_addr)
  Platforms_word 0xE000ED88



/*
 * boardResetStart
 *
 * Startup routine, for hardware initialization in assembly (which cannot be done in C).
 *
*/
    PLATFORMS_ASM_FUNC(boardResetStart)
PLATFORMS_ASM_LABEL(boardResetStart)
    /* After reset this routine is called
     * - in privileged thread mode and
     * - with sp == msp (sp_main) already set to reset value
     * - with interrupt priority set to all enabled BASEPRI=0
     * - with interrupt flag set to all enabled PRIMASK=0
    */

    /* Global interrupt disable */
    cpsid   i

    /*  Set WDOG update flag to allow updates in the future.
     *  must be done during the first 8'd128 bus clocks.
     *  See chapter 21.4.3 - Configuring the Watchdog in S32K14x Reference Manual.
     */
    ldr     r0, WDOGTOVAL_Addr
    ldr     r1, WDOGTOVAL_InitVal
    str     r1, [r0]
    ldr     r0, WDOGCS_Addr
    ldr     r1, WDOGCS_InitVal
    str     r1, [r0]

    /* set sp to top of kernel stack. */
    ldr     sp, BoardspInitial
    
    /* Set VTOR to base of vector table address. */
    ldr     r0, VTOR_Addr
    ldr     r1, ExceptionTableAddr
    str     r1, [r0]

    /* enable bus fault, mem manage fault and usage fault to invoke separate exceptions */
    ldr     r0, SHCSR_Value
    ldr     r5, SHCSR_Addr                  /* system handler control and status register */
    ldr     r1, [r5]
    orr     r1, r0, r1
    str     r1, [r5]

    bl      BoardStart                  /* call C routine, never returns */
    PLATFORMS_ASM_END_FUNC(boardResetStart)

    
    PLATFORMS_ASM_FUNC(boardDisableInterruptsAsm)
PLATFORMS_ASM_LABEL(boardDisableInterruptsAsm)
    cpsid   i
    bx lr
    PLATFORMS_ASM_END_FUNC(boardDisableInterruptsAsm)


    PLATFORMS_ASM_FUNC(boardEnableInterruptsAsm)
PLATFORMS_ASM_LABEL(boardEnableInterruptsAsm)
    cpsie   i
    bx lr
    PLATFORMS_ASM_END_FUNC(boardEnableInterruptsAsm)

/*
 * void Board_CORTEXM_EnableVFPCoprocessor(void)
 *
 * This routine enables the coprocessor for the FPU.
 * It also enables the FPU in the control register and programs
 * the FPCCR to not save any floating point context.
 */
    PLATFORMS_ASM_FUNC(Board_CORTEXM_EnableVFPCoprocessor)
PLATFORMS_ASM_LABEL(Board_CORTEXM_EnableVFPCoprocessor)
    /* Disable automatic save of FPU context in CONTROL. */
    mrs     r0, control
    bic     r0, r0, #BOARD_CORTEXM_CONTROL_FPCA
    msr     control, r0
    isb                             /* Make change to CONTROL visible. */

    /* Enable VFP coprocessor in CPACR */

    ldr     r1, PLATFORMS_CPACR_addr
    ldr     r0, [r1]
    orr     r0, r0, #0xf00000       /*  Mask cp10, cp11 to o11 */
    str     r0, [r1]

    /* Disable automatic saving of FP context in FPCCR, as the OS does this
     * manually.
    */
    ldr     r1, PLATFORMS_FPCCR_addr
    ldr     r0, [r1]
    bic     r0, r0, #(BOARD_FPCCR_LSPEN | BOARD_FPCCR_ASPEN)
    str     r0, [r1]

    bx      lr                      /*  return */
    PLATFORMS_ASM_END_FUNC(Board_CORTEXM_EnableVFPCoprocessor)


  PLATFORMS_ASM_CODE_THUMB
  Platforms_align(4, 2)

  PLATFORMS_ASM_FUNC(BOARD_GET_ISR_SRC)
PLATFORMS_ASM_LABEL(BOARD_GET_ISR_SRC)
  mrs   r0, ipsr  /* get active exception/interrupt source */
  sub   r0, r0, #16 /* interrupts start at 16 (1-15 are exceptions) */
  bx    lr
  PLATFORMS_ASM_END_FUNC(BOARD_GET_ISR_SRC)


    PLATFORMS_ASM_SRC_END
/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/

