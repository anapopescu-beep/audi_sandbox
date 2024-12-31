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
#include "Ftm_Gpt_Ip.h"
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
/* FTM instance used - 0 */
#define FTM_INSTACE_0 0U
/* FTM Channel used - 1 */
#define CH_1 1U
/* FTM time-out period - equivalent to 1s */
#define COUNTER_VALUE 4800

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
volatile uint16 index = 0U;
volatile boolean toggleLed = FALSE;
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
void FtmNotification(void)
{
    ++index;
    if (index >= 1000U)
    {
    	/*Blink a RGB_LED RED*/
    	toggleLed = TRUE;
    	index = 0;
    }
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
#if (FTM_GPT_IP_MODULE_SINGLE_INTERRUPT == STD_ON)
    IntCtrl_Ip_InstallHandler(FTM0_Ch0_Ch7_IRQn, &FTM_0_ISR, NULL_PTR);
    IntCtrl_Ip_EnableIrq(FTM0_Ch0_Ch7_IRQn);
#else
    IntCtrl_Ip_InstallHandler(FTM0_Ch0_Ch1_IRQn, &FTM_0_CH_0_CH_1_ISR, NULL_PTR);
    IntCtrl_Ip_EnableIrq(FTM0_Ch0_Ch1_IRQn);
#endif
    /* Initial FTM instance 0 - Channel 1 */
    Ftm_Gpt_Ip_Init(FTM_INSTACE_0, &FTM_0_InitConfig_PB);
    /* Initial channel 1 */
    Ftm_Gpt_Ip_InitChannel(FTM_INSTACE_0, FTM_0_CH_1);
    /* Enable channel interrupt FTM0 - CH_1 */
    Ftm_Gpt_Ip_EnableChannelInterrupt(FTM_INSTACE_0, CH_1);
    /* Start channel CH_1 */
    Ftm_Gpt_Ip_StartTimer(FTM_INSTACE_0, COUNTER_VALUE);
    /* Waiting for Interrupt occurred */
    while (TRUE)
    {
        /* Toggle the LED RED when the FTM notification is called */
        if (TRUE == toggleLed)
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
