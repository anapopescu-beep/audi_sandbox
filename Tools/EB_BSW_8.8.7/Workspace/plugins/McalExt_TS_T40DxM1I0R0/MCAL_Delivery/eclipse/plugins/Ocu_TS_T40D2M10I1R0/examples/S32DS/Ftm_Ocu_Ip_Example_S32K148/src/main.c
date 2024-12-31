/*==================================================================================================
*   (c) Copyright 2020 - 2021 NXP Semiconductors
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
==================================================================================================*/

/**
*   @file main.c
*
*   @addtogroup main_module main module documentation
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ftm_Ocu_Ip.h"
#include "Ftm_Ocu_Ip_Irq.h"
#include "Clock_Ip.h"
#include "IntCtrl_Ip.h"
#include "Port_Ci_Port_Ip.h"
#include "Gpio_Dio_Ip.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


#define FTM_INSTANCE_0  (0U)
#define FTM_CH_0        (0U)

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/* Global flag updated in irq */
static volatile uint8 Toggle_Led = 0U;

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief    Ftm notification periodically called by the configured channel
* @details  Used to blink a led
*/
void OcuChannel_0_notification(void);

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief    Ftm notification periodically called by the configured channel
* @details  Used to blink a led
*/
void OcuChannel_0_notification()
{
    static uint16 count = 0U;
    if(++count >= 300U)
    {
        Toggle_Led = 1U;
        count = 0U;
    }
}


/**
* @brief    Main function of the example
* @details  Initializes the used drivers and uses the Ocu
*           and Dio drivers to toggle a LED periodically
*/
int main(void)
{
    /* Init clock () */
    Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

    /* Initialize all pins using the Port driver */
    Port_Ci_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* set FTM interupt */
    IntCtrl_Ip_Init(&IntCtrlConfig_0);
    IntCtrl_Ip_ConfigIrqRouting(&intRouteConfig);

    /* init channel Ftm_Ocu*/
    Ftm_Ocu_Ip_Init(&Ftm_Ocu_Ip_ModuleCfgPB_VS_0);

    /* Start channel and enable interrupt */
    Ftm_Ocu_Ip_StartChannel(FTM_INSTANCE_0, FTM_CH_0);
    Ftm_Ocu_Ip_EnableNotification(FTM_INSTANCE_0, FTM_CH_0);

    /* Wait for Ftm channel ISR to change */
    while (1U)
    {
        /* Toggle the LED when the Ocu notification is called */
        if (1U == Toggle_Led)
        {
            Toggle_Led = 0U;
            Gpio_Dio_Ip_TogglePins(LED_PORT, (1 << LED_PIN));
        }
    }
}

/** @} */
