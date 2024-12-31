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
#include "Mcal.h"
#include "Qdec.h"
#include "Mcu.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

uint32 countInstanceConfig_0 = 0U;

/*==================================================================================================
*                                       Defines
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      Initializez the used drivers and change mode for Qdec
*/

int main(void)
{

	/* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);
    /* Initialize the clock tree */
    Mcu_InitClock(McuClockSettingConfig_0);
    /* Apply a mode configuration */
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize Qdec driver */
    Qdec_Init(&Qdec_Config_VS_0);

    /* Set mode sleep for Qdec instance 0 */
    Qdec_SetMode(QdecInstanceConfig_0, QDEC_MODE_SLEEP);

    /* Loop until variable countInstanceConfig_0 = 100 */
    while(countInstanceConfig_0 < (uint32)100U)
    {
        countInstanceConfig_0++;
    }
    /* Set mode normal for Qdec instance 0 */
    Qdec_SetMode(QdecInstanceConfig_0, QDEC_MODE_NORMAL);
    
    /* De-initialize Qdec driver */
    Qdec_DeInit();
    
    return (0);
}

#ifdef __cplusplus
}
#endif

/** @} */
