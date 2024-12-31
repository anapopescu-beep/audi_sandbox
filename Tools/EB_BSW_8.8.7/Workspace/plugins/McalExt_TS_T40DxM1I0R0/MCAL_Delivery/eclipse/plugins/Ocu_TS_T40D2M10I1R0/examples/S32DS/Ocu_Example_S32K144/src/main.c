/*==================================================================================================
*   (c) Copyright 2020 - 2022 NXP Semiconductors
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

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ocu.h"
#include "Port.h"
#include "Dio.h"
#include "Mcu.h"
#include "Platform.h"

#include "check_example.h"

/*==================================================================================================
*                                     EXTERNAL FUNCTION PROTOTYPES
==================================================================================================*/

/*===============================================================================================
*                                       LOCAL MACROS
===============================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
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
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)

/**
* @brief    Ftm notification periodically called by the configured channel
* @details  Used to blink a led
*/
void OcuChannel_0_notification(void);

#endif /* OCU_NOTIFICATION_SUPPORTED */

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*================================================================================================*/
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)

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

#endif /* OCU_NOTIFICATION_SUPPORTED */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      Initializes the used drivers and uses the Ocu
*               and Dio drivers to toggle a LED periodically
*/
int main(void) 
{
    /* state of output Led*/
    uint8 state = 0U;

    /* Initialize the Mcu driver */
#if (STD_ON == MCU_PRECOMPILE_SUPPORT)
    Mcu_Init(NULL_PTR);
#else
    Mcu_Init(&Mcu_Config_VS_0);
#endif

#if (STD_ON == MCU_INIT_CLOCK)
    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuClockSettingConfig_0);
#if (MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
#endif
    Mcu_SetMode(McuModeSettingConf_0);
#else
    #error "The Mcu Init Clock API should be enabled from the Mcu driver"
#endif

    /* Initialize Platform driver */
    Platform_Init(NULL_PTR);

    /* Initialize all pins using the Port driver */
#if (STD_ON == PORT_PRECOMPILE_SUPPORT)
    Port_Init(NULL_PTR);
#else
    Port_Init(&Port_Config_VS_0);
#endif

    /* Initialize the high level configuration structure of Ocu driver */
#if (STD_ON == OCU_PRECOMPILE_SUPPORT)
    Ocu_Init(NULL_PTR);
#else
    Ocu_Init(&Ocu_Config_VS_0);
#endif

    /* Start Ftm Ocu Channel */
    Ocu_StartChannel(OcuChannel_0);

    /* Enable Ftm Ocu channel notification */
    Ocu_EnableNotification(OcuChannel_0);

    /* Wait for Ftm channel ISR to change */
    while (1U) 
    {
        /* Toggle the LED when the Ocu notification is called */
        if (1U == Toggle_Led)
        {
            Toggle_Led = 0U;
            Dio_WriteChannel(DioConf_DioChannel_DioChannel_0,state);
            /* toggle current state of Led*/
            state = state ^ 1U;
        }
    }
    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
