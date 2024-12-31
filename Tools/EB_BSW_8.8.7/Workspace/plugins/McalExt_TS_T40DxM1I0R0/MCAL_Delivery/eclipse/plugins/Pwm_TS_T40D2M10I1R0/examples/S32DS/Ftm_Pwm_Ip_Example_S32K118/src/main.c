/*==================================================================================================
*   (c) Copyright 2020-2021 NXP
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

#include "Clock_Ip.h"
#include "Ftm_Pwm_Ip.h"
#include "Port_Ci_Port_Ip.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define NUM_BLINK_LED     (uint32)20U
#define DELAY_TIMER       (uint32)5000000U
#define FTM_INSTANCE_0    (uint8)0U /* FTM_0 */
#define FTM_CH_0          (uint8)0U /* Channel_0*/

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
*
*/
int main(void)
{

    uint8 num_blink = 0U;
    /* Init clock () */
    Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

    /* Initialize all pins using the Port driver */
    Port_Ci_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* Initialize PWM driver */
    Ftm_Pwm_Ip_Init(FTM_INSTANCE_0, &Ftm_Pwm_Ip_VS_0_UserCfg0);

    /* Set new period for Edge-Align Pwm */
    Ftm_Pwm_Ip_UpdatePwmPeriod(FTM_INSTANCE_0, 0x5000, TRUE);

    /* Setup new duty cycle to increasing LED brightness */
    Ftm_Pwm_Ip_UpdatePwmChannel(FTM_INSTANCE_0, FTM_CH_0, 0x4000, 0x000, TRUE);

    /* Setup new duty cycle to decreasing LED brightness */
    Ftm_Pwm_Ip_UpdatePwmChannel(FTM_INSTANCE_0, FTM_CH_0, 0x200, 0x000, TRUE);

    /* Using duty 0% and 100% to blink led */
    while(num_blink < NUM_BLINK_LED)
    {
        /* Led on when duty cycle is 100% */
        Ftm_Pwm_Ip_UpdatePwmChannel(FTM_INSTANCE_0, FTM_CH_0, 0x5000, 0x000, TRUE);
        TestDelay(DELAY_TIMER);

        /* Led off when duty cycle is 0% */
        Ftm_Pwm_Ip_UpdatePwmChannel(FTM_INSTANCE_0, FTM_CH_0, 0x0000, 0x000, TRUE);
        TestDelay(DELAY_TIMER);
        num_blink++;
    }

    /* De-initialize PWM driver */
    Ftm_Pwm_Ip_DeInit(FTM_INSTANCE_0);

    return (0);
}

#ifdef __cplusplus
}
#endif

/** @} */
