/*
*   (c) Copyright 2020 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
*/

/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including necessary configuration files. */
#include "Mcal.h"
#include "Clock_Ip.h"
#include "Clock_Ip_Cfg.h"
#include "check_example.h"

#define CLOCKOUT_FREQ   48000000U



/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    Clock_Ip_StatusType clockStatus;
    uint32 Frequency;

    /* Write your code here */
    clockStatus = Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

#if defined (CLOCK_IP_HAS_SPLL_CLK)
    while ( CLOCK_IP_PLL_LOCKED != Clock_Ip_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }

    Clock_Ip_DistributePll();
#endif
    if (clockStatus != CLOCK_IP_SUCCESS)
    {
        Exit_Example(FALSE);
    }
    else
    {
        Frequency = Clock_Ip_GetClockFrequency(CLKOUT0_CLK);
        if (Frequency != CLOCKOUT_FREQ)
        {
            Exit_Example(FALSE);
        }
        else
        {
            Exit_Example(TRUE);
        }
    }

    return (0U);
}

/* END main */
/*!
** @}
*/
