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

#ifndef LPIT_ICU_IP_DEFINES
#define LPIT_ICU_IP_DEFINES

/**
 * @file    Lpit_Icu_Ip_Defines.h
 * @version 1.0.1
 *
 * @addtogroup lpit_icu_ip LPIT IPL
 * @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!][!//
    [!CODE!][!WS "0"!]/* Include platform header file. */[!CR!][!ENDCODE!][!//
    [!IF "contains($DerivativeName, 'S32K1')"!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_LPIT.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPIT_ICU_IP_DEFINES_VENDOR_ID                    43
#define LPIT_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define LPIT_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION     4
#define LPIT_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define LPIT_ICU_IP_DEFINES_SW_MAJOR_VERSION             1
#define LPIT_ICU_IP_DEFINES_SW_MINOR_VERSION             0
#define LPIT_ICU_IP_DEFINES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
===================================================================================================*/
/* Check if header file and StandardTypes.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((LPIT_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (LPIT_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Lpit_Icu_Ip.h and StandardTypes.h are different."
    #endif
#endif

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//

[!CODE!][!WS "0"!]/* Macros that indicate LPIT instances used by ICU. */[!CR!][!ENDCODE!][!//
[!SELECT "./IcuConfigSet"!][!//
[!IF "count(IcuLpit/*) > '0'"!][!//
    [!LOOP "IcuLpit/*"!][!//

    [!CODE!][!WS "0"!]#ifndef LPIT_[!"node:value(./IcuLpitModule)"!]_USED[!CR!][!ENDCODE!][!//
    [!CODE!][!WS "4"!]#define LPIT_[!"node:value(./IcuLpitModule)"!]_USED[!CR!][!ENDCODE!][!//
    [!CODE!][!WS "0"!]#else[!CR!][!ENDCODE!][!//
    [!CODE!][!WS "4"!]#error "LPIT_[!"node:value(./IcuLpitModule)"!] instance cannot be used by ICU. Instance locked by another driver!"[!CR!][!ENDCODE!][!//
    [!CODE!][!WS "0"!]#endif[!CR!][!CR!][!ENDCODE!][!//
    
    [!IF "contains($DerivativeName, 'S32K14')"!][!//
    [!LOOP "IcuLpitChannels/*"!][!//
    [!CODE!]/** @brief LPIT [!"node:value(../../IcuLpitModule)"!] CH[!"node:value(./IcuLpitChannel)"!] ISR enable/disable */[!CR!][!ENDCODE!][!//
    [!CODE!]#define LPIT_ICU_[!"node:value(../../IcuLpitModule)"!]_CH_[!"node:value(./IcuLpitChannel)"!]_ISR_USED        (STD_ON)[!CR!][!ENDCODE!][!//
    [!ENDLOOP!][!//
    [!ELSE!][!//
    [!CODE!]/** @brief LPIT [!"node:value(./IcuLpitModule)"!] ISR enable/disable */[!CR!][!ENDCODE!][!//
    [!CODE!]#define LPIT_ICU_[!"node:value(./IcuLpitModule)"!]_ISR_USED        (STD_ON)[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

[!ENDNOCODE!][!//

/* MIER start bit mask. */
#define LPIT_MIER_TIE_START_MASK                (uint32)0x1U

/* MSR start bit mask. */
#define LPIT_MSR_TIF_START_MASK                 (uint32)0x1U

/* Channels trigger select defines. */
#define LPIT_ICU_TRG_CH0                        ((uint8)0U)
#define LPIT_ICU_TRG_CH1                        ((uint8)1U)
#define LPIT_ICU_TRG_CH2                        ((uint8)2U)
#define LPIT_ICU_TRG_CH3                        ((uint8)3U)

/* Channels trigger source defines. */
#define LPIT_ICU_CH_INTERNAL_TRIGGER            ((uint8)1U)
#define LPIT_ICU_CH_EXTERNAL_TRIGGER            ((uint8)0U)

/** @brief Switches the Development Error Detection and Notification on or off.  */
#define LPIT_ICU_IP_DEV_ERROR_DETECT            ([!IF "IcuGeneral/IcuDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the deinitialization functionality. */
#define LPIT_ICU_DEINIT_API                     ([!IF "IcuOptionalApis/IcuDeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to edge detect functionality. */
#define LPIT_ICU_EDGE_DETECT_API                ([!IF "IcuOptionalApis/IcuEdgeDetectApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the timestamp functionality. */
#define LPIT_ICU_TIMESTAMP_API                  ([!IF "IcuOptionalApis/IcuTimestampApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to input state functionality. */
#define LPIT_ICU_GET_INPUT_STATE_API            ([!IF "IcuOptionalApis/IcuGetInputStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#ifdef __cplusplus
}
#endif

#endif  /* LPIT_ICU_IP_DEFINES */

/** @} */

[!ENDCODE!][!//
