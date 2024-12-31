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
#include "Ftm_Qdec_Ip.h"
#include "Clock_Ip.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/* FTM used - 0 */

#define MODULE_FTM_0        1

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       Defines
==================================================================================================*/

#define clockConfig Clock_Ip_aClockConfig

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Main function of the example
* @details      Initializez the used drivers and change mode for Ftm_Qdec_Ip
*/

int main(void)
{
    uint32 count = 0;

    /* Init clock */
    Clock_Ip_Init(clockConfig);

    /* Initialize Ftm_Qdec_Ip driver */
    Ftm_Qdec_Ip_Init(MODULE_FTM_0, Ftm_Qdec_Ip_InstanceConfig_VS_0);

    /* Set mode sleep for FTM hardware number */
    Ftm_Qdec_Ip_SetMode(MODULE_FTM_0, FTM_QDEC_MODE_SLEEP);

    /* Loop until variable count = 20 */
    while(count < (uint32)20U)
    {
        count++;
    }

    /* Set mode sleep for FTM hardware number */
    Ftm_Qdec_Ip_SetMode(MODULE_FTM_0, FTM_QDEC_MODE_NORMAL);
    
    /* De-initialize Ftm_Qdec_Ip driver */
    Ftm_Qdec_Ip_Deinit(MODULE_FTM_0);

    return (0);
}


#ifdef __cplusplus
}
#endif

/** @} */
