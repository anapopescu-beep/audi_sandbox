/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : ENET
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

#ifndef ENET_IP_CFG_H
#define ENET_IP_CFG_H

/**
*   @file
*
*   @addtogroup ENET_DRIVER_CONFIGURATION ENET Driver Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!]#include "Enet_Ip_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "Enet_Ip_PBcfg.h"[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#include "StandardTypes.h"
#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ENET_IP_CFG_VENDOR_ID                     43
#define ENET_IP_CFG_AR_RELEASE_MAJOR_VERSION      4
#define ENET_IP_CFG_AR_RELEASE_MINOR_VERSION      4
#define ENET_IP_CFG_AR_RELEASE_REVISION_VERSION   0
#define ENET_IP_CFG_SW_MAJOR_VERSION              1
#define ENET_IP_CFG_SW_MINOR_VERSION              0
#define ENET_IP_CFG_SW_PATCH_VERSION              1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!][!//
/* Checks against Enet_Ip_[!"."!]_PBcfg.h */
#if (ENET_IP_CFG_VENDOR_ID != ENET_IP_PBCFG_[!"."!]_VENDOR_ID)
    #error "Enet_Ip_Cfg.h and Enet_Ip_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if ((ENET_IP_CFG_AR_RELEASE_MAJOR_VERSION    != ENET_IP_PBCFG_[!"."!]_AR_RELEASE_MAJOR_VERSION) || \
     (ENET_IP_CFG_AR_RELEASE_MINOR_VERSION    != ENET_IP_PBCFG_[!"."!]_AR_RELEASE_MINOR_VERSION) || \
     (ENET_IP_CFG_AR_RELEASE_REVISION_VERSION != ENET_IP_PBCFG_[!"."!]_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip.h and Enet_Ip_[!"."!]_PBcfg.h are different"
#endif
#if ((ENET_IP_CFG_SW_MAJOR_VERSION != ENET_IP_PBCFG_[!"."!]_SW_MAJOR_VERSION) || \
     (ENET_IP_CFG_SW_MINOR_VERSION != ENET_IP_PBCFG_[!"."!]_SW_MINOR_VERSION) || \
     (ENET_IP_CFG_SW_PATCH_VERSION != ENET_IP_PBCFG_[!"."!]_SW_PATCH_VERSION))
    #error "Software Version Numbers of Enet_Ip_Cfg.h and Enet_Ip_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!][!//
/* Checks against Enet_Ip_PBcfg.h */
#if (ENET_IP_CFG_VENDOR_ID != ENET_IP_PBCFG_VENDOR_ID)
    #error "Enet_Ip_Cfg.h and Enet_Ip_PBcfg.h have different vendor ids"
#endif
#if ((ENET_IP_CFG_AR_RELEASE_MAJOR_VERSION    != ENET_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (ENET_IP_CFG_AR_RELEASE_MINOR_VERSION    != ENET_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (ENET_IP_CFG_AR_RELEASE_REVISION_VERSION != ENET_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip.h and Enet_Ip_PBcfg.h are different"
#endif
#if ((ENET_IP_CFG_SW_MAJOR_VERSION != ENET_IP_PBCFG_SW_MAJOR_VERSION) || \
     (ENET_IP_CFG_SW_MINOR_VERSION != ENET_IP_PBCFG_SW_MINOR_VERSION) || \
     (ENET_IP_CFG_SW_PATCH_VERSION != ENET_IP_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Enet_Ip_Cfg.h and Enet_Ip_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against StandardTypes.h */
    #if ((ENET_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (ENET_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Enet_Ip_Cfg.h and StandardTypes.h are different"
    #endif
    /* Checks against Reg_eSys.h */
    #if ((ENET_IP_CFG_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (ENET_IP_CFG_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Enet_Ip_Cfg.h and Reg_eSys.h are different"
    #endif
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!CODE!]#define ENET_CONFIG_EXT \[!CR!][!ENDCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!][!//
    [!CODE!][!WS "4"!]ENET_CONFIG_[!"."!]_PB \[!CR!][!ENDCODE!]
[!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS "4"!]ENET_CONFIG_PB[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#define ENET_DEV_ERROR_DETECT            ([!IF "EthGeneral/EthDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define ENET_TIMEOUT_TYPE                ([!"EthGeneral/EthGeneralVendorSpecific/EthTimeoutMethod"!])

#define ENET_TIMEOUT_VALUE_US            ([!"EthGeneral/EthGeneralVendorSpecific/EthTimeoutDuration"!]U)

/*! @brief Enables / Disables user mode support */
#define ENET_ENABLE_USER_MODE_SUPPORT    ([!IF "EthGeneral/EthGeneralVendorSpecific/EthEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == ENET_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running ENET in user mode, MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
    #endif /* (STD_ON == ENET_ENABLE_USER_MODE_SUPPORT */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

#if ((STD_ON == ENET_ENABLE_USER_MODE_SUPPORT) && defined(MCAL_ENET_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_ENET_REG_PROT_AVAILABLE)
        #define ENET_SET_USER_ACCESS_ALLOWED_AVAILABLE      (STD_ON)  
    #else
        #define ENET_SET_USER_ACCESS_ALLOWED_AVAILABLE      (STD_OFF)
    #endif
#else
    #define ENET_SET_USER_ACCESS_ALLOWED_AVAILABLE      (STD_OFF)    
#endif
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* Forward ENET structure declarations */
struct Enet_Ip_StateType;
struct Enet_Ip_ConfigType;
struct Enet_Ip_BufferConfigType;

/**
* @brief   The structure contains the hardware controller configuration type.
*/
typedef struct sEnet_CtrlConfigType
{
    struct Enet_Ip_StateType                 *Enet_pCtrlState;
    const struct Enet_Ip_ConfigType          *Enet_pCtrlConfig;
    const struct Enet_Ip_BufferConfigType    *Enet_paCtrlRxRingConfig;
    const struct Enet_Ip_BufferConfigType    *Enet_paCtrlTxRingConfig;
    const uint8                              *Enet_pau8CtrlPhysAddr;
} Enet_CtrlConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ENET_IP_CFG_H */
