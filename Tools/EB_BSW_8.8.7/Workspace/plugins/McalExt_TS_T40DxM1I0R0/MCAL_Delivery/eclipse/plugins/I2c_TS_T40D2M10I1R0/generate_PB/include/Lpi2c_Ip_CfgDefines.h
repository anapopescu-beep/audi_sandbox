/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : LPI2C
* Dependencies : none
*
* Autosar Version : 4.4.0
* Autosar Revision : ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version : 1.0.1
* Build Version : S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224
*
* (c) Copyright 2020-2022 NXP Semiconductors
* All Rights Reserved.
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef LPI2C_IP_CFGDEFINES_H
#define LPI2C_IP_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup LPI2C_DRIVER_CONFIGURATION LPI2C Driver Configurations
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k3')"!][!//
        [!VAR "I2cDerivative" = "as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative"!]
        [!VAR "I2cDerivative" = "substring-before($I2cDerivative, '_')"!]
[!CODE!][!WS "0"!]#include "[!"text:toupper($I2cDerivative)"!]_LPI2C.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k1')"!][!//
        [!VAR "I2cDerivative" = "as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative"!]
        [!VAR "I2cDerivative" = "substring-before($I2cDerivative, '_')"!]
[!CODE!][!WS "0"!]#include "[!"text:toupper($I2cDerivative)"!]_LPI2C.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPI2C_IP_CFGDEFINES_VENDOR_ID                     43
#define LPI2C_IP_CFGDEFINES_MODULE_ID                     255
#define LPI2C_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION      4
#define LPI2C_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION      4
#define LPI2C_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION   0
#define LPI2C_IP_CFGDEFINES_SW_MAJOR_VERSION              1
#define LPI2C_IP_CFGDEFINES_SW_MINOR_VERSION              0
#define LPI2C_IP_CFGDEFINES_SW_PATCH_VERSION              1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LPI2C_IP_CFGDEFINES_H */
