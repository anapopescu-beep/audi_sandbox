/*==================================================================================================
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
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Pwm.h"
#include "Mcu.h"
#include "Port.h"
#include "Platform.h"

#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define NUM_BLINK_LED     (uint32)20U
#define DELAY_TIMER       (uint32)5000000U
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


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

void TestDelay(uint32 delay);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
void TestDelay(uint32 delay)
{
    static volatile uint32 DelayTimer = 0;
    while(DelayTimer<delay)
    {
        DelayTimer++;
    }
    DelayTimer=0;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


/**
* @brief        Main function of the example
* @details      Initialize the used drivers and uses the Pwm driver to control the led brightness
*               and blink this Led.
*/
int main(void)
{
    uint8 num_blink = 0U;

    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);

    /* Initialize the clock tree */
    Mcu_InitClock(McuClockSettingConfig_0);

    /* Apply a mode configuration */
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize Platform driver */
    Platform_Init(NULL_PTR);

    /* Initialize all pins using the Port driver */
    Port_Init(&Port_Config_VS_0);

    /* Initialize PWM driver */
    Pwm_Init(&Pwm_Config_VS_0);

    /* Set new period and duty cycle*/
    Pwm_SetPeriodAndDuty(PwmChannel_0, 0x5000, 0x2000);

    /* Decreasing LED brightness, using Pwm_SetDutyCycle*/
    Pwm_SetDutyCycle(PwmChannel_0, 0x7000);

    /* Increasing LED brightness, using Pwm_SetDutyCycle*/
    Pwm_SetDutyCycle(PwmChannel_0, 0x200);

    /* Using duty cycle 0% and 100% to Blink LED */
    while(num_blink < NUM_BLINK_LED)
    {
        /* Led off when duty cycle is 100% */
        Pwm_SetDutyCycle(PwmChannel_0, 0x8000);
        TestDelay(DELAY_TIMER);

        /* Led on when duty cycle is 0% */
        Pwm_SetDutyCycle(PwmChannel_0, 0x0000);
        TestDelay(DELAY_TIMER);
        num_blink++;
    }

    /* De-initialize the PWM module. */
    Pwm_DeInit();

    Exit_Example(TRUE);

    return (0);
}

#ifdef __cplusplus
}
#endif

/** @} */
