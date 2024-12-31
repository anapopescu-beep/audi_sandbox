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
#include "LPit_Gpt_Ip.h"
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
/* LPIT instance used - 0 */
#define LPIT_INST_0 0U
/* LPIT Channel used - 0 */
#define CH_0 0U
/* LPIT time-out period - equivalent to 1s */
#define LPIT_PERIOD 48000000

#define clockConfig &Clock_Ip_aClockConfig[0]

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
/* Global flag updated in interrupt */
volatile uint8 toggleLed = 0U;

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Lpit notification called by the configured channel periodically
* @details      Used to blink a led
*/
void LpitNotification(void)
{
    toggleLed = 1U;
}


/**
* @brief        Main function of the example
* @details      Initialize the used drivers and uses the Pit
*               and Dio drivers to toggle a LED periodically
*/
int main (void)
{
    /* Initial Clock */
    Clock_Ip_Init(clockConfig);
    /* Initial Pin */
    Port_Ci_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
    /* Initial ISR */
#if (LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT == STD_ON)
    IntCtrl_Ip_InstallHandler(LPIT_IRQn, &LPIT_0_ISR, NULL_PTR);
    IntCtrl_Ip_EnableIrq(LPIT_IRQn);
#else
    IntCtrl_Ip_InstallHandler(LPIT0_Ch0_IRQn, &LPIT_0_CH_0_ISR, NULL_PTR);
    IntCtrl_Ip_EnableIrq(LPIT0_Ch0_IRQn);
#endif
    /* Initial LPIT instance 0 - Channel 0 */
    Lpit_Gpt_Ip_Init(LPIT_INST_0, &LPIT_0_InitConfig_PB);
    /* Initial channel 0 */
    Lpit_Gpt_Ip_InitChannel(LPIT_INST_0, LPIT_0_CH_0);
    /* Enable channel interrupt LPIT_0 - CH_0 */
    Lpit_Gpt_Ip_EnableChInterrupt(LPIT_INST_0, CH_0);
    /* Start channel CH_0 */
    Lpit_Gpt_Ip_StartTimer(LPIT_INST_0, CH_0, LPIT_PERIOD);
    /* Waiting for Interrupt occurred */
    while (TRUE)
    {
        /* Toggle the LED RGB_RED when the LPit notification is called */
        if (toggleLed == 1U)
        {
            /* Led toggle - blink a led */
            Gpio_Dio_Ip_TogglePins(LED_PORT, (1 << LED_PIN));
            toggleLed = 0U;
        }
    }
    return 0;
}


#ifdef __cplusplus
}
#endif

/** @} */
