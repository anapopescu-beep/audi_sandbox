/********************************************************************************
 *                                                                               *
 *                                 EB Layers                                     *
 *                                                                               *
 * ----------------------------------------------------------------------------- *
 *                                                                               *
 *                                   Board                                       *
 *                                                                               *
 *********************************************************************************
 *%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        *
 *%%   _____________________________   %%  \file Board.c                         *
 *%%  |                             |  %%                                        *
 *%%  |   &&&&&   &&&&&             |  %%  Module version: 1.0.0                 *
 *%%  |   &       &    &            |  %%                                        *
 *%%  |   &&&&    &&&&&             |  %%                                        *
 *%%  |   &       &    &            |  %%                                        *
 *%%  |   &&&&&   &&&&&             |  %%                                        *
 *%%  |_____________________________|  %%                                        *
 *%%                                   %%                                        *
 *%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        *
 *********************************************************************************
 * Copyright 2015 by Elektrobit Automotive GmbH                                  *
 * All rights exclusively reserved for Elektrobit Automotive GmbH,               *
 * unless expressly agreed to otherwise.                                         *
 ********************************************************************************/
/* Board_irq.c file */
/*
 * !LINKSTO OsekCore.Platforms.Board.001, 1
 */
/*
 * !LINKSTO OsekCore.Platforms.Board.101, 1
 */
/*
 * !LINKSTO OsekCore.Platforms.Board.012, 1
 */

#include "TSAutosar.h"
#include "board.h"

#ifdef BOARD_ISR_CAN0
#include "EB_Prj.h"
#include "Mcal.h"
#include "Can.h"
#endif

#if (PLATFORMS_TOOLCHAIN==PLATFORMS_multi)
#define ISR_HANDLER __interrupt void
#elif (PLATFORMS_TOOLCHAIN==PLATFORMS_gnu)
#define ISR_HANDLER void __attribute__ ((interrupt))
#elif (PLATFORMS_TOOLCHAIN==PLATFORMS_iar)
#define ISR_HANDLER
#else
#error "Unknown or unsupported toolchain. Check your Makefiles!"
#endif
#ifdef BOARD_ISR_CAN0
void BoardFlexCanErrorInterrupt(void);
void BoardFlexCanMailboxInterrupt(u32 ulInterruptNumber);
#endif


#ifdef BOARD_ISR_CAN0
ISR(Can_IsrFCA_ERR);

ISR(Can_IsrFCA_MB_00_15);

ISR(Can_IsrFCA_MB_16_31);
#endif

ISR_HANDLER void BoardIsrHandler(void);

#ifdef BOARD_ISR_TEST
void TestIsr (void);

volatile u32 isrCounter = 0U;
#endif

ISR_HANDLER void BoardIsrHandler(void)
{
#ifndef PLATFORMS_STUBS_ENABLED
    u32 ulInterruptNumber = BOARD_GET_ISR_SRC();
    /* Interrupt function shall call BoardEnableInterrupts/ BoardDisableInterrupts
     * !LINKSTO OsekCore.Platforms.Board.022, 1
     */
    m_ubBoardIntLockNestingCounter++;

    /*ulInterruptNumber = BoardGetIsrIndex();*/
    switch(ulInterruptNumber)
    {
#ifdef BOARD_ISR_TEST 
        case INTC_TESTISR:
            TestIsr();
            break;
#endif
#ifdef BOARD_ISR_CAN0
        case INTC_FLEXCAN_ESR_ERR  :
        case INTC_FLEXCAN_ESR_BOFF :
            BoardFlexCanErrorInterrupt();
            break;

        case INTC_FLEXCAN_BUF_00_15:
        case INTC_FLEXCAN_BUF_16_31:
            BoardFlexCanMailboxInterrupt(ulInterruptNumber);
            break;
#endif
        default :
            BoardInvalidInterrupt(ulInterruptNumber);
            break;
    }
    m_ubBoardIntLockNestingCounter--;
    EXIT_BOARD_INTERRUPT_HANDLER;
#endif
}

/*
 * Board_InvalidInterrupt(u32 id)
 *
 * The Board_InvalidInterrupt() routine is used for uninitialized
 * vectors of the vector table if errorhandling is set to minimal.
 * Parameter 'id' is containing the interrupt identification number.
 */
/*
 * !LINKSTO OsekCore.Platforms.Board.014, 1
 */
void BoardInvalidInterrupt(u32 id)
{
  /* remove unused parameter warning */
  (void) id;

  for (;;) { }
}

#ifdef BOARD_ISR_TEST
void TestIsr (void)
{
    isrCounter++;
    /* Todo :  THe interruption shall be cleared */
    /*BOARD_INTC_SSCIR_0 = BOARD_INTC_SSCIR_0_CLR0;*/

    /* In order to verify that ISR handler will not be lost
     * if during the interrupt routine, another ISR was triggered
     */
    if(isrCounter == 3U)
    {
        TRIGGER_INT();
    }
}
#endif

#ifdef BOARD_ISR_CAN0
/*
 * BoardFlexCanErrorInterrupt(u32 id)
 *
 * The BoardFlexCanErrorInterrupt() routine is called on CAN0 error event
 */
void BoardFlexCanErrorInterrupt(void)
{
    Can_IsrFCA_ERR();
}

/*
 * BoardFlexCanMailboxInterrupt(u32 id)
 *
 * The BoardFlexCanMailboxInterrupt() routine is called on CAN0 mailbox event
 */
void BoardFlexCanMailboxInterrupt(u32 ulInterruptNumber)
{
    switch(ulInterruptNumber)
    {
        case INTC_FLEXCAN_BUF_00_15: Can_IsrFCA_MB_00_15(); break;
        case INTC_FLEXCAN_BUF_16_31: Can_IsrFCA_MB_16_31(); break;
        default : for (;;);    /* undefined event has same effect than Invalid Interrupt */
    }

}
#endif
