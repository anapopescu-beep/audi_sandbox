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

#ifndef FTM_ICU_IP_DEFINES_H
#define FTM_ICU_IP_DEFINES_H

/**
*   @file
*
*   @addtogroup ftm_icu_ip FTM IPL
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
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32R41')"!][!//
        [!CODE!][!WS "0"!]#include "S32R41_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'SAF85')"!][!//
        [!CODE!][!WS "0"!]#include "SAF85XX_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32R45')"!][!//
        [!CODE!][!WS "0"!]#include "S32R45_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32G2')"!][!//
        [!CODE!][!WS "0"!]#include "S32G274A_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32G3')"!][!//
        [!CODE!][!WS "0"!]#include "S32G399A_FTM.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define FTM_ICU_IP_DEFINES_VENDOR_ID                       43
#define FTM_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define FTM_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION        4
#define FTM_ICU_IP_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define FTM_ICU_IP_DEFINES_SW_MAJOR_VERSION                1
#define FTM_ICU_IP_DEFINES_SW_MINOR_VERSION                0
#define FTM_ICU_IP_DEFINES_SW_PATCH_VERSION                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FTM_ICU_IP_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_ICU_IP_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Ftm_Icu_Ip_Defines.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//

[!CODE!][!WS "0"!]/* Macros that indicate FTM instances used by ICU. */[!CR!][!ENDCODE!][!//
[!SELECT "./IcuConfigSet"!][!//
[!IF "count(IcuFtm/*) > '0'"!][!//
    [!LOOP "IcuFtm/*"!][!//

    [!CODE!][!WS "0"!]#ifndef FTM_[!"node:value(./IcuFtmModule)"!]_USED[!CR!][!ENDCODE!][!//
    [!CODE!][!WS "4"!]#define FTM_[!"node:value(./IcuFtmModule)"!]_USED[!CR!][!ENDCODE!][!//
    [!CODE!][!WS "0"!]#else[!CR!][!ENDCODE!][!//
    [!CODE!][!WS "4"!]#error "FTM_[!"node:value(./IcuFtmModule)"!] instance cannot be used by ICU. Instance locked by another driver!"[!CR!][!ENDCODE!][!//
    [!CODE!][!WS "0"!]#endif[!CR!][!CR!][!ENDCODE!][!//
    
    [!VAR "ovfIsrUsed" = "../../../IcuAutosarExt/IcuOverflowNotificationApi"!][!//
    [!IF "contains($DerivativeName, 'S32K14')"!][!//
    [!VAR "Ch0Ch1Used" = "0"!][!//
    [!VAR "Ch2Ch3Used" = "0"!][!//
    [!VAR "Ch4Ch5Used" = "0"!][!//
    [!VAR "Ch6Ch7Used" = "0"!][!//
    [!LOOP "IcuFtmChannels/*"!][!//
    [!VAR "ChIntegerDivisionBy2"  = "floor(num:i(IcuFtmChannel) div 2)"!][!//
    [!IF "$ChIntegerDivisionBy2 = num:i(0)"!][!//
    [!VAR "Ch0Ch1Used" = "$Ch0Ch1Used + 1"!][!//
    [!ELSEIF "$ChIntegerDivisionBy2 = num:i(1)"!][!//
    [!VAR "Ch2Ch3Used" = "$Ch0Ch1Used + 1"!][!//
    [!ELSEIF "$ChIntegerDivisionBy2 = num:i(2)"!][!//
    [!VAR "Ch4Ch5Used" = "$Ch0Ch1Used + 1"!][!//
    [!ELSEIF "$ChIntegerDivisionBy2 = num:i(3)"!][!//
    [!VAR "Ch6Ch7Used" = "$Ch0Ch1Used + 1"!][!//
    [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$Ch0Ch1Used != num:i(0)"!][!//
    [!CODE!]/** @brief FTM [!"node:value(./IcuFtmModule)"!] CH0 CH1 ISR enable/disable */[!CR!][!ENDCODE!][!//
    [!CODE!]#define FTM_ICU_[!"node:value(./IcuFtmModule)"!]_CH_0_CH_1_ISR_USED        (STD_ON)[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "$Ch2Ch3Used != num:i(0)"!][!//
    [!CODE!]/** @brief FTM [!"node:value(./IcuFtmModule)"!] CH2 CH3 ISR enable/disable */[!CR!][!ENDCODE!][!//
    [!CODE!]#define FTM_ICU_[!"node:value(./IcuFtmModule)"!]_CH_2_CH_3_ISR_USED        (STD_ON)[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "$Ch4Ch5Used != num:i(0)"!][!//
    [!CODE!]/** @brief FTM [!"node:value(./IcuFtmModule)"!] CH4 CH5 ISR enable/disable */[!CR!][!ENDCODE!][!//
    [!CODE!]#define FTM_ICU_[!"node:value(./IcuFtmModule)"!]_CH_4_CH_5_ISR_USED        (STD_ON)[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "$Ch6Ch7Used != num:i(0)"!][!//
    [!CODE!]/** @brief FTM [!"node:value(./IcuFtmModule)"!] CH6 CH7 ISR enable/disable */[!CR!][!ENDCODE!][!//
    [!CODE!]#define FTM_ICU_[!"node:value(./IcuFtmModule)"!]_CH_6_CH_7_ISR_USED        (STD_ON)[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "$ovfIsrUsed"!][!//
    [!CODE!]/** @brief FTM [!"node:value(./IcuFtmModule)"!] OVF interrupt service enable/disable */[!CR!][!ENDCODE!][!//
    [!CODE!]#define FTM_ICU_[!"node:value(./IcuFtmModule)"!]_OVF_ISR_USED        (STD_ON)[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!ELSE!][!//
    [!CODE!]/** @brief FTM [!"node:value(./IcuFtmModule)"!] ISR enable/disable */[!CR!][!ENDCODE!][!//
    [!CODE!]#define FTM_ICU_[!"node:value(./IcuFtmModule)"!]_ISR_USED        (STD_ON)[!CR!][!ENDCODE!][!//
    [!IF "$ovfIsrUsed"!][!//
    [!CODE!]/** @brief FTM [!"node:value(./IcuFtmModule)"!] OVF interrupt service enable/disable */[!CR!][!ENDCODE!][!//
    [!CODE!]#define FTM_ICU_[!"node:value(./IcuFtmModule)"!]_OVF_ISR_USED        (STD_ON)[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

[!ENDNOCODE!][!//

/** @brief Switches the Development Error Detection and Notification on or off.  */
#define FTM_ICU_IP_DEV_ERROR_DETECT        ([!IF "IcuGeneral/IcuDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#if (STD_ON == FTM_ICU_IP_DEV_ERROR_DETECT)
/** @brief The number of FTM instances available on platform */
#define FTM_ICU_IP_NUM_OF_MODULES          ([!"ecu:get('Icu.Num_Ftm_Hw_Modules')"!]U)
#endif

/** @brief The number of channels available on each FTM instance */
#define FTM_ICU_IP_NUM_OF_CHANNELS         ([!"ecu:get('Icu.Num_Ftm_Hw_Channels')"!]U)

/** TODO:Generate @brief The number of channels with filter on each FTM instance */
#define FTM_FILTER_MAX_NO_CH               (4U)

/** @brief Adds or removes all services related to the timestamp functionality. */
#define FTM_ICU_TIMESTAMP_API              ([!IF "IcuOptionalApis/IcuTimestampApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the edge detect functionality. */
#define FTM_ICU_EDGE_DETECT_API            ([!IF "IcuOptionalApis/IcuEdgeDetectApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the signal mesurement functionality. */
#define FTM_ICU_SIGNAL_MEASUREMENT_API     ([!IF "IcuOptionalApis/IcuSignalMeasurementApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the input level. */
#define FTM_ICU_GET_INPUT_LEVEL_API        ([!IF "IcuAutosarExt/IcuGetInputLevelApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to the deinitialization functionality. */
#define FTM_ICU_DEINIT_API                 ([!IF "IcuOptionalApis/IcuDeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to mode set functionality. */
#define FTM_ICU_SET_MODE_API               ([!IF "IcuOptionalApis/IcuSetModeApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to edge count functionality. */
#define FTM_ICU_EDGE_COUNT_API             ([!IF "IcuOptionalApis/IcuEdgeCountApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief  Adds or removes the service Icu_GetTimeElapsed() from the code. */
#define FTM_ICU_GET_TIME_ELAPSED_API        ([!IF "IcuOptionalApis/IcuGetTimeElapsedApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief  Adds or removes the service Icu_GetDutyCycleValues() from the code. */
#define FTM_ICU_GET_DUTY_CYCLE_VALUES_API   ([!IF "IcuOptionalApis/IcuGetDutyCycleValuesApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to input state functionality. */
#define FTM_ICU_GET_INPUT_STATE_API        ([!IF "IcuOptionalApis/IcuGetInputStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or removes all services related to dual clock edge functionality. */
#define FTM_ICU_DUAL_CLOCK_MODE_API        ([!IF "IcuAutosarExt/IcuEnableDualClockMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Support for User mode.If this parameter has been configured to 'STD_ON',
 *  the FTM driver code can be executed from both supervisor and user mode. */
#define FTM_ICU_ENABLE_USER_MODE_SUPPORT   ([!IF "IcuGeneral/IcuEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define FTM_ICU_CAPTURERGISTER_API         ([!IF "node:exists(IcuAutosarExt/IcuGetCaptureRegisterValueApi)"!][!IF "IcuAutosarExt/IcuGetCaptureRegisterValueApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ELSE!]STD_OFF[!ENDIF!])

/** @brief Adds or Removes the code related to overflow notification */
#define FTM_ICU_OVERFLOW_NOTIFICATION_API  ([!IF "IcuAutosarExt/IcuOverflowNotificationApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #if (defined (FTM_ICU_ENABLE_USER_MODE_SUPPORT) && (STD_ON == FTM_ICU_ENABLE_USER_MODE_SUPPORT))
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Icu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
 #endif
#endif

[!VAR "TimestampDmaEnable" = "0"!][!/*
*/!][!VAR "MeasurementDmaEnable" = "0"!][!/*
*/!][!SELECT "IcuConfigSet"!][!/*
    */!][!LOOP "./IcuChannel/*"!][!/*
    */!][!IF "IcuDMAChannelEnable = 'true'"!][!/*
        */!][!IF "IcuMeasurementMode='ICU_MODE_TIMESTAMP'"!][!/*
            */!][!VAR "TimestampDmaEnable" = "$TimestampDmaEnable + 1"!][!/*
        */!][!ENDIF!][!/*
        */!][!IF "IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT'"!][!/*
            */!][!VAR "MeasurementDmaEnable" = "$MeasurementDmaEnable + 1"!][!/*
        */!][!ENDIF!][!/*
    */!][!ENDIF!][!/*
    */!][!ENDLOOP!][!/*
 */!][!ENDSELECT!]
/**
 * @brief Adds or removes the support for TimeStamp Measurement with DMA.
 *        STD_ON:  DMA in TS measurement can be used.
 *        STD_OFF: DMA in TS measurement can not be used.
 */
#define FTM_ICU_TIMESTAMP_USES_DMA            ([!IF "$TimestampDmaEnable != 0"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief Get FTM type for each platform. */
#define Ftm_Icu_Ip_BaseType                   FTM_Type

[!IF "contains($DerivativeName, 'S32K1')"!][!//
    [!CODE!][!WS "0"!]/* Define used for FTM instance with distinct lines for overflow IRQ and event IRQ. */[!ENDCODE!][!//
    [!CODE!][!WS "0"!]#define FTM_ICU_TOF_DISTINCT_LINE             (STD_ON)[!CR!][!ENDCODE!][!//
[!ENDIF!][!//

#ifdef __cplusplus
}
#endif

#endif  /* FTM_ICU_IP_DEFINES_H */

/** @} */

[!ENDCODE!][!//
