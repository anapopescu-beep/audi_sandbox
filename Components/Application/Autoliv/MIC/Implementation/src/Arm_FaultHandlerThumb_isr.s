/**
    @file        Arm_FaultHandlerThumb_isr.s
    @version     1.0.1

    @brief       AUTOSAR - Autosar  Sample Application.
    @details     Sample application using AutoSar MCAL drivers.

    (c) Copyright 2017 NXP
    All Rights Reserved.

    This file contains sample code only. It is not part of the production code deliverables.

*/


    SECTION .text : CODE (2)
    THUMB


    PUBLIC Arm_FaultHandlerThumb
    EXTERN MIC_HardFaultHandlerHll

/******************************************************************************
Stack/Exception frame without floating-point storage:
           
 SP(R13)+0x00: R0  
 SP(R13)+0x04: R1
 SP(R13)+0x08: R2
 SP(R13)+0x0C: R3
 SP(R13)+0x10: R12
 SP(R13)+0x14: LR (R14)
 SP(R13)+0x18: PC (R15) - this address is used upon return from exception 
 SP(R13)+0x1C: xPSR
******************************************************************************/

 
 
Arm_FaultHandlerThumb:

  /* pointer to the location where the address of failing instruction 
    (PC at address SP(R13) + 0x18 - see above) is stored  */
  /*mov r0,r13*/          /* read stack pointer to r0 register */

  /* determine which stack was used by application (PSP or MSP stack),
     When exception is taken r14 (LR) contains EXC_RETURN value in which bit 2 (CONTROL.SPSEL) indicates if MSP or PSP stack is used (CONTROL.SPSEL)
     r14=0xFFFFFFF1 (MSP stack)
     r14=0xFFFFFFF9 (MSP stack)
     r14=0xFFFFFFFD (PSP stack)
     r14=0xFFFFFFE1 (MSP stack)
     r14=0xFFFFFFE9 (MSP stack)
     r14=0xFFFFFFED (PSP stack)
  */
  movs    r0,#0x4           /* prepare bit mask; */
  ands    r0,r0,r14         /* EXC_RETURN & 0x4; */
  beq     label_msp_stack   /* if (EXC_RETURN & 0x4) r0=PSP else r0=MSP; */

  mrs     r0,PSP            /* r0 = PSP; (PSP stack used) */
  b       label_end_stack

label_msp_stack:
  mrs     r0,MSP            /* r0 = MSP; (MSP stack used) */

label_end_stack:

  adds r0, r0, #0x18  
  
  /* Pointer in r0 is provided as an parameter to the HLL function */
  
  /* NOTE: HLL function is called by pure branch (b) without link (bl). 
     This will cause that, upon HLL exiting, the execution will continue directly 
     from the location pointed by the address provided in r0. */

    LDR   R3,=MIC_HardFaultHandlerHll
    bx    R3
    
    end
  
   
