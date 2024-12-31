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
#include "Mcu.h"
#include "Gpt.h"
#include "Mcal.h"
#include "Wdg_43_Instance0.h"

#ifdef WDG_INSTANCE1
#if (WDG_INSTANCE1 == STD_ON)
#include "Wdg_43_Instance1.h"
#endif
#endif

#include "Platform.h"
#include "Devassert.h"
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
/**
* @brief        Variables
* @details      The callback set a variable that was set to confirm the interrupt was triggered
*/
volatile uint8 notificationCount = 0;
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
* @brief        Delay function
* @details      Delay function to test the Wdg Trigger
*/
void delay(uint32 timeout)
{
    volatile uint32 i = timeout;
    
    while(i--);
}

/**
* @brief        LPIT_0 Interrupt handler
* @details      Defined in LPit_Gpt_Ip.c
*/
#if (LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT == STD_ON)
extern ISR(LPIT_0_ISR);
#else
extern ISR(LPIT_0_CH_0_ISR);

#endif

#ifdef WDG_INSTANCE1
#if (WDG_INSTANCE1 == STD_ON)
/**
* @brief        LPIT_1 Interrupt handler
* @details      Defined in LPit_Gpt_Ip.c
*/
#if (LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT == STD_ON)
extern ISR(LPIT_1_ISR);
#else
extern ISR(LPIT_0_CH_1_ISR);
#endif
#endif
#endif
/**
* @brief        Wdg Interrupt handler
* @details      Defined in Wdg_Ipw_Isr.c
*/
extern ISR(Wdg_Ipw_Isr);
/**
* @brief        Wdg callback notification called by the configured channel periodically
* @details      Increments the counter
*/
void Wdg_CallBackNotification1(void)
{
    notificationCount = 1U;
}

/**
* @brief        Main function of the example
* @details      Initializes the used drivers and uses Wdg driver
*/
int main(void) 
{
    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);
    Mcu_InitClock(McuClockSettingConfig_0);
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize Platform driver */
    Platform_Init(NULL_PTR);

    /* Install LPIT ISR */
#if (LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT == STD_ON)
    Platform_SetIrq(LPIT_IRQn, TRUE);
    Platform_InstallIrqHandler(LPIT_IRQn, &LPIT_0_ISR, NULL_PTR);
#else
    Platform_SetIrq(LPIT0_Ch0_IRQn, TRUE);
    Platform_InstallIrqHandler(LPIT0_Ch0_IRQn, &LPIT_0_CH_0_ISR, NULL_PTR);
#endif

#ifdef WDG_INSTANCE1
#if (WDG_INSTANCE1 == STD_ON)
    /* Install LPIT ISR */
#if (LPIT_GPT_IP_MODULE_SINGLE_INTERRUPT == STD_ON)
    Platform_SetIrq(LPIT_IRQn, TRUE);
    Platform_InstallIrqHandler(LPIT_IRQn, &LPIT_1_ISR, NULL_PTR);
#else
    Platform_SetIrq(LPIT0_Ch1_IRQn, TRUE);
    Platform_InstallIrqHandler(LPIT0_Ch1_IRQn, &LPIT_0_CH_1_ISR, NULL_PTR);  
#endif
    /* Install EWM ISR */
    Platform_SetIrq(WDOG_EWM_IRQn, TRUE);
    Platform_InstallIrqHandler(WDOG_EWM_IRQn, &Wdg_Ipw_Isr, NULL_PTR);
#endif
#endif

    /* Initialize the Gpt driver */
    Gpt_Init(&Gpt_Config_VS_0);
    
    /* Enable the Gpt notification to periodically service the Wdg */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_0);
    
    /* Initialize the Wdg driver */
    Wdg_43_Instance0_Init(&Wdg_Config_0_VS_0);

    /* Set the Wdg Trigger Condition in order to periodically service the Wdg */
    Wdg_43_Instance0_SetTriggerCondition(1000);

    /*Change the Wdg mode of operation */
    Wdg_43_Instance0_SetMode(WDGIF_FAST_MODE);

    /* Set the Wdg Trigger Condition in order to periodically service the Wdg */
    Wdg_43_Instance0_SetTriggerCondition(1000);

    /* Test that the Wdg will not expire while it is services */
    for (int index = 0; index < 10; index++)
    {
        delay(50000U);
        Wdg_43_Instance0_SetTriggerCondition(1000);
    }

    /* Disable the Wdg driver by changing the mode of operation to OFF_MODE */
    Wdg_43_Instance0_SetMode(WDGIF_OFF_MODE);

    /* Verify that Wdg timer is stopped after calling Wdg_43_Instance0_SetMode function */
    delay(5000000U);
    
#ifdef WDG_INSTANCE1
#if (WDG_INSTANCE1 == STD_ON)
    
    /* Enable the Gpt notification to periodically service the Wdg */
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_1);
    
    /* Initialize the Wdg driver */
    Wdg_43_Instance1_Init(&Wdg_Config_1_VS_0);
    
    /* Set the Wdg Trigger Condition in order to periodically service the Wdg */
    Wdg_43_Instance1_SetTriggerCondition(5);
    while(notificationCount == 0)
    {
        /* Wait for the interrupt */
    };
    /* Verify the callback setting a variable */
    DevAssert(notificationCount == 1);
#endif
#endif

    Exit_Example(TRUE);
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
