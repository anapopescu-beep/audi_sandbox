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
#include "Ewm_Ip_VS_0_PBcfg.h"
#include "Ewm_Ip.h"


/* Ewm instance used*/
#define EWM_INST                     0U

#define TIMEOUT                      100000000U
#define TIMEOUT_EXPIRED              0U
#define NUM_OF_SERVICE_TIMES         50U

volatile uint32 u32NumOfNotifications = 0U;

/**
* @brief        Ewm notification
*/
void Ewm_CallbackNotification(void)
{
    u32NumOfNotifications++;
}

/**
* @brief        Ewm Interrupt handler
* @details      Be used for calling Ewm_Ip_IrqHandler defined in Ewm_Ip.c
*/
extern void Ewm_Ip_Isr(void);

void Delay(volatile uint32 u32Count)
{
    while(u32Count--)
    {

    }
}

/**
* @brief        Main function of the example
* @details      Initializes the used drivers and uses Ewm driver
*/
int main (void)
{
    uint32 u32Count = 0U;
    uint32 u32Timeout = TIMEOUT;
    Ewm_Ip_StatusType status = EWM_IP_STATUS_SUCCESS;
    Clock_Ip_StatusType clockStatus = CLOCK_IP_SUCCESS;
    IntCtrl_Ip_StatusType intctrlStatus = INTCTRL_IP_STATUS_SUCCESS;

    /* Initialize the clock tree */
    clockStatus = Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

    while (clockStatus != CLOCK_IP_SUCCESS)
    {
        clockStatus = Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);
    }

    /* Enable EWM clock source */
    Clock_Ip_EnableModuleClock(EWM0_CLK);
    
    /*Enable the Ewm0 interrupt vector */
    intctrlStatus = IntCtrl_Ip_Init(&IntCtrlConfig_0);

    if (intctrlStatus != INTCTRL_IP_STATUS_SUCCESS)
    {
        DevAssert(FALSE);
    }
    else
    {
        IntCtrl_Ip_InstallHandler(WDOG_EWM_IRQn, &Ewm_Ip_Isr, NULL_PTR);
    }

    /*Initialize Ewm */
    status = Ewm_Ip_Init(EWM_INST, &Ewm_Ip_1_Cfg0);

    if(status != EWM_IP_STATUS_SUCCESS)
    {
        /* Initialize EWM failed */
        DevAssert(FALSE);
    }

    for(u32Count = 0; u32Count < NUM_OF_SERVICE_TIMES; u32Count++)
    {
        /* Service Ewm */
        Ewm_Ip_Service(EWM_INST);

        Delay(50000);
    }

    /* When the EWM_OUT_b pin is asserted, an interrupt request is generated to indicate the
    assertion of the EWM reset out signal. The EWM_OUT_b signal can be deasserted only by forcing 
    a system reset. */
    while ((u32NumOfNotifications == 0U) && (u32Timeout--))
    {

    }

    if(u32Timeout == TIMEOUT_EXPIRED)
    {
        /* Test is failed and the notification function has been called */
        DevAssert(FALSE);
    }

    /* Test passed without any error detected */
    DevAssert(TRUE);

    return 0;
}

#ifdef __cplusplus
}
#endif

/** @} */
