/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LPI2C
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224
*
*   (c) Copyright 2020-2022 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef I2C_IPW_TYPES_H
#define I2C_IPW_TYPES_H

/**
*     @file
*
*     @addtogroup I2C_DRIVER I2c Driver
*     @{
*/

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lpi2c_Ip.h"
#include "CDD_I2c_Cfg.h"
#if (STD_ON == I2C_FLEXIO_USED)
#include "Flexio_I2c_Ip.h"
#endif
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define I2C_IPW_TYPES_VENDOR_ID                      43
#define I2C_IPW_TYPES_MODULE_ID                      255   
#define I2C_IPW_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define I2C_IPW_TYPES_AR_RELEASE_MINOR_VERSION       4
#define I2C_IPW_TYPES_AR_RELEASE_REVISION_VERSION    0
#define I2C_IPW_TYPES_SW_MAJOR_VERSION               1
#define I2C_IPW_TYPES_SW_MINOR_VERSION               0
#define I2C_IPW_TYPES_SW_PATCH_VERSION               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Lpi2c_Ip.h */
#if (I2C_IPW_TYPES_VENDOR_ID != LPI2C_IP_VENDOR_ID)
    #error "I2c_Ipw_Types.h and Lpi2c_Ip.h have different vendor ids"
#endif
#if ((I2C_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != LPI2C_IP_AR_RELEASE_MAJOR_VERSION) ||    \
     (I2C_IPW_TYPES_AR_RELEASE_MINOR_VERSION != LPI2C_IP_AR_RELEASE_MINOR_VERSION) ||    \
     (I2C_IPW_TYPES_AR_RELEASE_REVISION_VERSION != LPI2C_IP_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Lpi2c_Ip.h and I2c_Ipw_Types.h have different"
#endif

#if ((I2C_IPW_TYPES_SW_MAJOR_VERSION != LPI2C_IP_SW_MAJOR_VERSION) ||    \
     (I2C_IPW_TYPES_SW_MINOR_VERSION != LPI2C_IP_SW_MINOR_VERSION) ||    \
     (I2C_IPW_TYPES_SW_PATCH_VERSION != LPI2C_IP_SW_PATCH_VERSION) \
    )
     #error "Software Version Numbers of Lpi2c_Ip.h and I2c_Ipw_Types.h have different"
#endif

/* Checks against CDD_I2c_Cfg.h */

#if (I2C_IPW_TYPES_VENDOR_ID != I2C_VENDOR_ID_CFG)
    #error "I2c_Ipw_Types.h and CDD_I2c_Cfg.h have different vendor ids"
#endif

#if ((I2C_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != I2C_AR_RELEASE_MAJOR_VERSION_CFG) ||    \
     (I2C_IPW_TYPES_AR_RELEASE_MINOR_VERSION != I2C_AR_RELEASE_MINOR_VERSION_CFG) ||    \
     (I2C_IPW_TYPES_AR_RELEASE_REVISION_VERSION != I2C_AR_RELEASE_REVISION_VERSION_CFG) \
    )
     #error "AutoSar Version Numbers of CDD_I2c_Cfg.h and I2c_Ipw_Types.h are different"
#endif

#if ((I2C_IPW_TYPES_SW_MAJOR_VERSION != I2C_SW_MAJOR_VERSION_CFG) || \
     (I2C_IPW_TYPES_SW_MINOR_VERSION != I2C_SW_MINOR_VERSION_CFG) || \
     (I2C_IPW_TYPES_SW_PATCH_VERSION != I2C_SW_PATCH_VERSION_CFG)    \
    )
     #error "Software Version Numbers of CDD_I2c_Cfg.h and I2c_Ipw_Types.h are different"
#endif

/* Checks against Flexio_I2c_Ip.h */
#if (STD_ON == I2C_FLEXIO_USED)
    #if (I2C_IPW_TYPES_VENDOR_ID != FLEXIO_I2C_IP_VENDOR_ID)
        #error "I2c_Ipw_Types.h and Flexio_I2c_Ip.h have different vendor ids"
    #endif

    #if ((I2C_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != FLEXIO_I2C_IP_AR_RELEASE_MAJOR_VERSION) ||    \
         (I2C_IPW_TYPES_AR_RELEASE_MINOR_VERSION != FLEXIO_I2C_IP_AR_RELEASE_MINOR_VERSION ) ||    \
         (I2C_IPW_TYPES_AR_RELEASE_REVISION_VERSION != FLEXIO_I2C_IP_AR_RELEASE_REVISION_VERSION) \
        )
         #error "AutoSar Version Numbers of Flexio_I2c_Ip.h and I2c_Ipw_Types.h are different"
    #endif

    #if ((I2C_IPW_TYPES_SW_MAJOR_VERSION != FLEXIO_I2C_IP_SW_MAJOR_VERSION) || \
         (I2C_IPW_TYPES_SW_MINOR_VERSION != FLEXIO_I2C_IP_SW_MINOR_VERSION) || \
         (I2C_IPW_TYPES_SW_PATCH_VERSION != FLEXIO_I2C_IP_SW_PATCH_VERSION)    \
        )
         #error "Software Version Numbers of Flexio_I2c_Ip.h and I2c_Ipw_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief   The structure contains the hardware configuration for lpi2c module.
*/
typedef struct
{
    const Lpi2c_Ip_MasterConfigType * Master;
    const Lpi2c_Ip_SlaveConfigType  * Slave;

}Lpi2c_Ipw_HwChannelConfigType;

/**
* @brief   The structure contains the hardware channel configuration type.
*/
typedef struct
{
    const Lpi2c_Ipw_HwChannelConfigType * I2c_Ipw_Lpi2cHwConfig;

#if (STD_ON == I2C_FLEXIO_USED)
    const Flexio_I2c_Ip_MasterConfigType * I2c_Ipw_FlexioHwConfig;
#endif

} I2c_Ipw_HwChannelConfigType;



/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /*I2C_IPW_TYPES_H*/

