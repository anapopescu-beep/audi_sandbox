    SECTION .startup :CODE
   
    PUBLIC boardResetStart
    PUBLIC boardInvalidInterrupt
    PUBLIC boardInvalidException
    PUBLIC boardDisableInterruptsAsm
    PUBLIC boardEnableInterruptsAsm
    PUBLIC Board_CORTEXM_EnableVFPCoprocessor
    PUBLIC BOARD_GET_ISR_SRC
    EXTERN BoardStart
    EXTERN CORTEXMExceptionTable
    EXTERN BoardStack
    THUMB
boardInvalidInterrupt
    b boardInvalidInterrupt
    DATA
    THUMB
boardInvalidException
    b boardInvalidException
    DATA
SHCSR_Value
    DC32 0x00070000
SHCSR_Addr
    DC32 0xE000ED24
VTOR_Addr
    DC32 0xE000ED08
WDOGCS_Addr
    DC32 0x40052000
WDOGCS_InitVal
    DC32 0x000021A0
WDOGTOVAL_Addr
    DC32 0x40052008
WDOGTOVAL_InitVal
    DC32 0x00000500
ExceptionTableAddr
    DC32 CORTEXMExceptionTable
BoardspInitial
    DC32 (BoardStack + 0x200U*4)
PLATFORMS_FPCCR_addr
  DC32 0xE000EF34
PLATFORMS_CPACR_addr
  DC32 0xE000ED88
    THUMB
boardResetStart
    cpsid i
    ldr r0, WDOGTOVAL_Addr
    ldr r1, WDOGTOVAL_InitVal
    str r1, [r0]
    ldr r0, WDOGCS_Addr
    ldr r1, WDOGCS_InitVal
    str r1, [r0]
    ldr sp, BoardspInitial
    ldr r0, VTOR_Addr
    ldr r1, ExceptionTableAddr
    str r1, [r0]
    ldr r0, SHCSR_Value
    ldr r5, SHCSR_Addr
    ldr r1, [r5]
    orr r1, r0, r1
    str r1, [r5]
    bl BoardStart
    DATA
    THUMB
boardDisableInterruptsAsm
    cpsid i
    bx lr
    DATA
    THUMB
boardEnableInterruptsAsm
    cpsie i
    bx lr
    DATA
    THUMB
Board_CORTEXM_EnableVFPCoprocessor
    mrs r0, control
    bic r0, r0, #0x00000004
    msr control, r0
    isb
    ldr r1, PLATFORMS_CPACR_addr
    ldr r0, [r1]
    orr r0, r0, #0xf00000
    str r0, [r1]
    ldr r1, PLATFORMS_FPCCR_addr
    ldr r0, [r1]
    bic r0, r0, #((1 << 30) | (1 << 31))
    str r0, [r1]
    bx lr
    DATA
 
  ALIGNROM 2
  THUMB
BOARD_GET_ISR_SRC
  mrs r0, ipsr
  sub r0, r0, #16
  bx lr
  DATA
    END
