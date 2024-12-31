/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FLEXCAN
*   Dependencies         : 
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

/**
*   @file    Can_Ipw_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!].c
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface
*   @details Configuration Structures for PostBuild
*
*   @addtogroup CAN_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_Ipw_Cfg.h"
#include "Can_Ipw_Types.h"
#include "FlexCAN_Ip.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           Can_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*/
#define CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C                     43
#define CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C      4
#define CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C      4
#define CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C   0
#define CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C              1
#define CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C              0
#define CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C              1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Can_Ipw_Cfg.h are of the same vendor */
#if (CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C != CAN_IPW_CFG_VENDOR_ID)
    #error "Can_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Can_Ipw_Cfg.h have different vendor ids"
#endif
/* Check if current file and Can_Ipw_Cfg.h are of the same Autosar version */
#if ((CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C    != CAN_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C    != CAN_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C != CAN_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Can_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Can_Ipw_Cfg.h are different"
#endif
/* Check if current file and Can_Ipw_Cfg.h are of the same Software version */
#if ((CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C != CAN_IPW_CFG_SW_MAJOR_VERSION) || \
     (CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C != CAN_IPW_CFG_SW_MINOR_VERSION) || \
     (CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C != CAN_IPW_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Can_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Can_Ipw_Cfg.h are different"
#endif

/* Check if current file and FlexCAN_Ip header file are of the same vendor */
#if (CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C != FLEXCAN_IP_VENDOR_ID_H)
    #error "Can_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and FlexCAN_Ip.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip header file are of the same Autosar version */
#if ((CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C     != FLEXCAN_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C     != FLEXCAN_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C  != FLEXCAN_IP_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of Can_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and FlexCAN_Ip.h are different"
#endif
/* Check if current file and FlexCAN_Ip header file are of the same Software version */
#if ((CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C != FLEXCAN_IP_SW_MAJOR_VERSION_H) || \
     (CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C != FLEXCAN_IP_SW_MINOR_VERSION_H) || \
     (CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C != FLEXCAN_IP_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and FlexCAN_Ip.h are different"
#endif

/* Check if current file and Can_Ipw_Types.h are of the same vendor */
#if (CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C != CAN_IPW_TYPES_VENDOR_ID_H)
    #error "Can_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Can_Ipw_Types.h have different vendor IDs"
#endif
/* Check if current file and Can_Ipw_Types.h are of the same Autosar version */
#if((CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C != CAN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
    (CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C != CAN_IPW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
    (CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C != CAN_IPW_TYPES_AR_RELEASE_REVISION_VERSION_H))
#error "AutoSar Version Numbers of Can_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Can_Ipw_Types.h are different"
#endif
/* Check if current file and Can_Ipw_Types.h are of the same software version */
#if((CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C != CAN_IPW_TYPES_SW_MAJOR_VERSION_H) || \
    (CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C != CAN_IPW_TYPES_SW_MINOR_VERSION_H) || \
    (CAN_IPW_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C != CAN_IPW_TYPES_SW_PATCH_VERSION_H))
#error "Software Version Numbers of Can_Ipw[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Can_Ipw_Types.h are different"
#endif

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

/**
* @brief   Export FLEXCAN configurations.
*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!]
[!ELSE!]
    [!VAR "postBuildVariantNameUnderscore" = "string(null)"!]
[!ENDIF!]
[!SELECT "CanConfigSet"!]
[!VAR "CtrlConfigCount" = "num:i(count(./CanController/*))"!]
[!VAR "CtrlIdx" = "num:i(0)"!]
[!VAR "CanGeneralPart" = "as:path(../CanGeneral, true())"!]
[!LOOP "node:order(./CanController/*, './CanControllerId')"!]
[!CODE!]
const Can_Ipw_HwChannelConfigType CanIpwHwChannelConfig[!"$postBuildVariantNameUnderscore"!][!"$CtrlIdx"!] =
{
    /* Here should be included the structure from FLEXCAN_IP_CFg*/
    &Flexcan_aCtrlConfigPB[!"$postBuildVariantNameUnderscore"!][[!"$CtrlIdx"!]U][!ENDCODE!]
    [!VAR "CtrlIdx" = "num:i($CtrlIdx + 1)"!]
[!CODE!]
};
[!ENDCODE!]
[!ENDLOOP!]

[!CODE!][!CR!]/* PN configuration wrapper */[!CR!][!ENDCODE!]
[!IF "(ecu:get('Can.CanConfigSet.CanPretendedNetworking') = 'STD_ON') and (../CanGeneral/CanPublicIcomSupport = 'true')"!]
[!VAR "numOfPnConfig" = "num:i(count(CanIcom/CanIcomConfig/*))"!]
[!VAR "Idx" = "0"!]
[!VAR "IdxRxMessage" = "0"!]
[!LOOP "CanIcom/CanIcomConfig/*"!]
[!CODE!]
const Can_Ipw_IcomRxMessageConfigsType CanIpwIcomRxMessageConfig[!"$postBuildVariantNameUnderscore"!]_[!"num:i($Idx)"!] =
{
    &Flexcan_aPnConfigPB[!"$postBuildVariantNameUnderscore"!][[!"num:i($IdxRxMessage)"!]U]
};
[!ENDCODE!]
[!VAR "Idx" = "$Idx + 1"!]
[!VAR "IdxRxMessage" = "num:i($IdxRxMessage + count(./CanIcomWakeupCauses/CanIcomRxMessage/*))"!]
[!ENDLOOP!]
[!ENDIF!]

[!ENDSELECT!]
[!ENDNOCODE!]
#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

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
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */
