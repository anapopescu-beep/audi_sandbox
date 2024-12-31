[!CODE!][!//
[!AUTOSPACING!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Ftm Lpit Lptmr Port_Ci LpCmp
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

#ifndef PORT_CI_ICU_IP_DEFINES_H
#define PORT_CI_ICU_IP_DEFINES_H

/**
 *   @file       Port2_Icu_Ip_Defines.h
 *   @version    1.0.1
 *
 *   @brief      AUTOSAR Icu - contains the data exported by the Icu module
 *   @details    Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup port2_icu_ip PORT_CI IPL
 *   @{
 */

#ifdef __cplusplus
extern "C"{
#endif

 /*==================================================================================================
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 *================================================================================================*/
#include "StandardTypes.h"
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!][!//
    [!CODE!][!WS "0"!]/* Include platform header file. */[!CR!][!ENDCODE!][!//
    [!IF "contains($DerivativeName, 'S32K1')"!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_PORT.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define PORT_CI_ICU_IP_DEFINES_VENDOR_ID                      43
#define PORT_CI_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION       4
#define PORT_CI_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION       4
#define PORT_CI_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION    0
#define PORT_CI_ICU_IP_DEFINES_SW_MAJOR_VERSION               1
#define PORT_CI_ICU_IP_DEFINES_SW_MINOR_VERSION               0
#define PORT_CI_ICU_IP_DEFINES_SW_PATCH_VERSION               1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and StandardTypes.h file are of the same Autosar version */
    #if ((PORT_CI_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PORT_CI_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Port_Ci_Icu_Ip_Defines.h and StandardTypes.h are different"
    #endif
#endif

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//
[!CODE!][!WS "0"!]/* Macros that indicate PORT instances used by ICU. */[!CR!][!ENDCODE!][!//
[!SELECT "./IcuConfigSet"!][!//
[!IF "count(IcuPort/*) > '0'"!][!//
    [!IF "contains($DerivativeName, 'S32K14')"!][!//
    [!LOOP "IcuPort/*"!][!//
    [!CODE!]/** @brief PORT [!"node:value(./IcuPortModule)"!] ISR enable/disable */[!CR!][!ENDCODE!][!//
    [!CODE!]#define PORT_CI_ICU_IP_PORT_[!"node:value(./IcuPortModule)"!]_ISR_USED        (STD_ON)[!CR!][!ENDCODE!][!//
    [!ENDLOOP!][!//
    [!ELSE!][!//
    [!CODE!]/** @brief PORT single ISR enable/disable */[!CR!][!ENDCODE!][!//
    [!CODE!]#define PORT_CI_ICU_IP_SINGLE_INTERRUPT    (STD_ON)[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!][!//

/**
* @brief PORT CI channels defines
*/
/*
 * PORT CI channel encoding
 *
 * [              4 bit | 5 bit                ]
 * [ module id: 15 ... 0 | channel id: 31 ... 0 ]
 */
#define ICU_PORT_CI_MOD_MASK_U16                                      ((uint16)0x1E0)
#define ICU_PORT_CI_MOD_SHIFT                                         ((uint16)5U)
#define ICU_PORT_CI_CH_MASK_U16                                       ((uint16)0x1F)
#define ICU_PORT_CI_CH_SHIFT                                          ((uint16)0U)

/* PORT CI module and channel decoding */
#define ICU_PORT_CI_MODULE_INDEX_U8(ch)      ((uint8)(((ch) & ICU_PORT_CI_MOD_MASK_U16) >> ICU_PORT_CI_MOD_SHIFT))
#define ICU_PORT_CI_CHANNEL_INDEX_U8(ch)     ((uint8)(((ch) & ICU_PORT_CI_CH_MASK_U16)  >> ICU_PORT_CI_CH_SHIFT))

/** @brief   Get A number of PORT_CI hardware modules from resource file*/
#define ICU_NUM_PORT_CI_HW_MODULE_U8  ((uint8)[!"ecu:get('Icu.Num_Port_Hw_Modules')"!]U)

/** @brief Switches the Development Error Detection and Notification on or off.  */
#define PORT_CI_ICU_IP_DEV_ERROR_DETECT        ([!IF "IcuGeneral/IcuDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to mode set functionality. */
#define PORT_CI_ICU_IP_SET_MODE_API               ([!IF "IcuOptionalApis/IcuSetModeApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Add or remove all functions related to input state. */
#define PORT_CI_ICU_IP_GET_INPUT_STATE_API        ([!IF "IcuOptionalApis/IcuGetInputStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the edge detect functionality. */
#define PORT_CI_ICU_IP_EDGE_DETECT_API              ([!IF "IcuOptionalApis/IcuEdgeDetectApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the deinitialization functionality. */
#define PORT_CI_ICU_IP_DEINIT_API              ([!IF "IcuOptionalApis/IcuDeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Support for User mode. If this parameter has been configured to 'STD_ON', the FTM driver 
 *         code can be executed from both supervisor and user mode. */
#define PORT_CI_ICU_IP_ENABLE_USER_MODE_SUPPORT   ([!IF "IcuGeneral/IcuEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (defined (PORT_CI_ICU_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == PORT_CI_ICU_IP_ENABLE_USER_MODE_SUPPORT))
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Icu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* PORT_CI_ICU_IP_DEFINES_H */
[!ENDCODE!]
