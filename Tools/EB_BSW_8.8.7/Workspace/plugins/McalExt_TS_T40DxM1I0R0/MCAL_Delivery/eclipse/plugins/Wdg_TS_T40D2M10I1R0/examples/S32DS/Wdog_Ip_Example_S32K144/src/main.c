/*
*   (c) Copyright 2021 NXP
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

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Clock_Ip.h"

#include "IntCtrl_Ip.h"
#include "IntCtrl_Ip_Cfg.h"
#include "Mcal.h"
#include "Wdog_Ip_VS_0_PBcfg.h"
#include "Wdog_Ip.h"


/* Wdog instance used*/
#define WDOG_INST                     0U

#define NUM_OF_SERVICE_TIMES         50U

void Delay(volatile uint32 u32Count)
{
    while(u32Count--);
}

/**
* @brief        Main function of the example
* @details      Initializes the used drivers and uses Wdog driver
*/
int main (void)
{
    uint32 u32Count = 0U;
    Wdog_Ip_StatusType status = WDOG_IP_STATUS_SUCCESS;
    Clock_Ip_StatusType clockStatus = CLOCK_IP_SUCCESS;

    /* Initialize the clock tree */
    clockStatus = Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

    while (clockStatus != CLOCK_IP_SUCCESS)
    {
        clockStatus = Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);
    }
    
    /*Initialize Wdog */
    status = Wdog_Ip_Init(WDOG_INST, &Wdog_Ip_1_Cfg0);
    if(status != WDOG_IP_STATUS_SUCCESS)
    {
        /* Test is failed and the notification function has been called */
        DevAssert(FALSE);
    }

    for (u32Count = 0U; u32Count < NUM_OF_SERVICE_TIMES; u32Count ++)
    {
        /* Service Wdog */
        Wdog_Ip_Service(WDOG_INST);
        Delay(50000);
    }

    /* Stop wdog timer counter */
    Wdog_Ip_DeInit(WDOG_INST);

    /* Test passed without any error detected */
    DevAssert(TRUE);

    return 0;
}

#ifdef __cplusplus
}
#endif

/** @} */
