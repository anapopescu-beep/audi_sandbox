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
#include "Port_Ci_Port_Ip.h"
#include "Gpio_Dio_Ip.h"
#include "Ftm_Icu_Ip.h"

#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
volatile uint8 UserCountIrqCH0;
volatile uint8 BlinkCount;

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
void delay(void)
{
    volatile uint32 count = 4200000U;
    while(count > 0)
    {
        count--;
    }
}
void User_EdgeDetect0(void)
{
    /* increment IRQ counter */
    UserCountIrqCH0++;
    if(UserCountIrqCH0 % 2 == 0)
    {
    	Gpio_Dio_Ip_WritePin(Digital_Output_LED_PORT, Digital_Output_LED_PIN, 1);
    }
    else
    {
    	Gpio_Dio_Ip_WritePin(Digital_Output_LED_PORT, Digital_Output_LED_PIN, 0);
    }
}
/**
* @brief        Main function of the example
* @details      Initializez the used drivers and uses the Icu
*               and Dio drivers to toggle a LED on a push button
*/
int main(void)
{
    /* Initial Clock */
    Clock_Ip_Init(Clock_Ip_aClockConfig);

    /* Initial Pin */
    Port_Ci_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* Initialize the Ftm Icu IP. */
    Ftm_Icu_Ip_Init(0U, &Ftm_Icu_Ip_0_Config_PB_VS_0);

    /* Install FTM ISR. */
    IntCtrl_Ip_Init(&IntCtrlConfig_0);
    IntCtrl_Ip_ConfigIrqRouting(&intRouteConfig);

    /* Configure the Ftm IP channel mode. */
    Ftm_Icu_Ip_EnableEdgeDetection(0U, 1U);
    Ftm_Icu_Ip_EnableNotification(0U, 1U);
    
    UserCountIrqCH0 = 0U;
    BlinkCount = 0U;

    while (TRUE)
    {
        if(BlinkCount % 2 == 0)
        {
        	Gpio_Dio_Ip_WritePin(Port_pin_InputForIcuChannel0_PORT, Port_pin_InputForIcuChannel0_PIN, 1);
        }
        else
        {
        	Gpio_Dio_Ip_WritePin(Port_pin_InputForIcuChannel0_PORT, Port_pin_InputForIcuChannel0_PIN, 0);
        }
        delay();
        BlinkCount++;
    }

    Exit_Example(TRUE);

    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
