[!AUTOSPACING!]
[!NOCODE!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "VS_number" = "concat('_',$postBuildVariant)"!]
    [!ELSE!]
        [!VAR "VS_number" = "''"!]
    [!ENDIF!]
[!ENDNOCODE!]
[!CODE!]
/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : Ftm
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

#ifndef FTM_OCU_IP_CFGDEFINES_H
#define FTM_OCU_IP_CFGDEFINES_H
/**
*   @file           Ftm_Ocu_Ip_CfgDefines.h
*
*   @addtogroup     ocu_ip Ocu IPL
*   @brief          Ocu IPL Precompile defines header file.
*   @details        Precompile defines.
*
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

#include "StandardTypes.h"

[!NOCODE!][!// Include specific header file
[!VAR "simAvailable" = "'STD_OFF'"!]
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!CODE!][!WS "0"!]/* Include platform header file. */[!CR!][!ENDCODE!][!//
    [!IF "contains($DerivativeName, 'S32G2')"!][!//
        [!CODE!][!WS "0"!]#include "S32G274A_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32G3')"!][!//
        [!CODE!][!WS "0"!]#include "S32G399A_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32R45') or contains($DerivativeName, 'S32R41')"!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32K1')"!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_FTM.h"[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_SIM.h"[!CR!][!ENDCODE!][!//
        [!VAR "simAvailable" = "'STD_ON'"!]
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_OCU_IP_CFGDEFINES_VENDOR_ID                       43
#define FTM_OCU_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION        4
#define FTM_OCU_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION        4
#define FTM_OCU_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION     0
#define FTM_OCU_IP_CFGDEFINES_SW_MAJOR_VERSION                1
#define FTM_OCU_IP_CFGDEFINES_SW_MINOR_VERSION                0
#define FTM_OCU_IP_CFGDEFINES_SW_PATCH_VERSION                1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this header file and StandardTypes.h file are of the same Autosar version */
    #if ((FTM_OCU_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (FTM_OCU_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Ftm_Ocu_Ip_CfgDefines.h and StandardTypes.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
    [!VAR "max_number_ocu_cfg" = "num:i(count(./OcuGeneral/OcuEcucPartitionRef/*))"!]

    /* Variable storing number of Ftm modules available on the current platform */
    [!VAR "numFtmHwModules" = "ecu:get('Ocu.Num_Ftm_Hw_Modules')"!]
    [!VAR "nameHwModule" = "'FTM'"!]

    /* Variable storing number of channels available on the current Ftm instance */
    [!VAR "numFtmChannelsPerInstance" = "ecu:get('Ocu.Num_Ftm_Hw_Channels')"!]
    
    /* Loop on all channels inside the same configuration Set */

    [!VAR "MacFtmUsed"="0"!]
    [!LOOP "OcuGeneral/OcuHwResourceConfig/*"!][!//
        [!IF "node:value(OcuChannelIsUsed) = 'true' and contains(OcuHwResourceId, $nameHwModule)"!][!//
            [!VAR "MacFtmUsed"="1"!]
        [!ENDIF!][!//
    [!ENDLOOP!][!//

    [!VAR "MacNumFtmChannels"="0"!]
    [!LOOP "OcuConfigSet/OcuChannel/*"!][!//
        [!IF "contains(HwChannel, $nameHwModule)"!][!//
            [!VAR "MacNumFtmChannels"="$MacNumFtmChannels + 1"!]
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//


#ifndef OCU_FTM_USED
/** @brief These defines indicate that at least one channel from each module is used in all configurations. */
#define OCU_FTM_USED    ([!IF "$MacFtmUsed=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

[!NOCODE!][!//
    [!IF "num:i($MacNumFtmChannels) != 0"!]
        [!CODE!]
#ifndef OCU_CONF_FTM_CHANNELS_PB
/** @brief Number of configured Ftm channels */
#define OCU_CONF_FTM_CHANNELS_PB      ([!"num:i($MacNumFtmChannels)"!]U)
        #endif
        [!ENDCODE!]
    [!ENDIF!]
[!ENDNOCODE!][!//

#ifndef OCU_CONF_FTM_MODULES_PB
/** @brief          Number of configured Ftm modules */
#define OCU_CONF_FTM_MODULES_PB     ([!"num:i(count(OcuConfigSet/OcuHWSpecificSettings/*))"!]U)
#endif

#ifndef OCU_NOTIFICATION_SUPPORTED
/** @brief   Switch to indicate if the notifications are supported */
#define OCU_NOTIFICATION_SUPPORTED      ([!IF "OcuConfigurationOfOptionalApis/OcuNotificationSupported"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_FTM_INSTANCE_COUNT
/** @brief  The number of Ftm instances available on platform */
#define OCU_FTM_INSTANCE_COUNT      ([!"$numFtmHwModules"!]U)
#endif

#ifndef OCU_FTM_CHANNEL_COUNT
/** @brief  The number of channels available on each Ftm instance */
#define OCU_FTM_CHANNEL_COUNT       ([!"$numFtmChannelsPerInstance"!]U)
#endif

#ifndef OCU_NUM_HW_CHANNELS
/** @brief maximum number of Ftm channels on this platform */
#define OCU_NUM_HW_CHANNELS   ((OCU_FTM_CHANNEL_COUNT) * (OCU_FTM_INSTANCE_COUNT))
#endif

#ifndef OCU_DEV_ERROR_DETECT
/** @brief   Switch for enabling the development error detection. */
#define OCU_DEV_ERROR_DETECT ([!IF "OcuGeneral/OcuDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_SET_CLOCK_MODE_API
/** @brief  Switch for enabling the dual clock functionality (Ocu_SetClockMode() API) */
#define OCU_SET_CLOCK_MODE_API      ([!IF "OcuGeneral/OcuEnableDualClockMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_ENABLE_USER_MODE_SUPPORT
/**
* @brief Support for User mode.
*        If this parameter has been configured to 'true' the Ocu driver code can be executed from both supervisor and user mode.
*/  
#define OCU_ENABLE_USER_MODE_SUPPORT    ([!IF "OcuGeneral/OcuEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (defined(OCU_ENABLE_USER_MODE_SUPPORT) && (STD_ON == OCU_ENABLE_USER_MODE_SUPPORT))
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running OCU in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif

/** @brief ISRs configured for Ocu  Ftm channels
*   @{
*/
[!NOCODE!]
[!IF "OcuConfigurationOfOptionalApis/OcuNotificationSupported"!]
[!IF "ecu:get('Ocu.OcuConfig.Ocu_FTM_ModuleSingleInterrupt')='STD_OFF'"!]
    [!FOR "ModuleIdx" = "0" TO "$numFtmHwModules - 1"!]
        [!FOR "ChannelIdx" = "0" TO "floor(num:i($numFtmChannelsPerInstance) div 2)"!]
        [!VAR "ChannelIsrUsed" = "'false'"!]
            [!LOOP "OcuGeneral/OcuHwResourceConfig/*"!]
                [!IF "OcuIsrEnable = 'true' and contains(OcuHwResourceId, concat('FTM_',$ModuleIdx)) and (contains(OcuHwResourceId, concat('CH_',num:i($ChannelIdx)*2)) or contains(OcuHwResourceId, concat('CH_',num:i($ChannelIdx)*2 + 1)))"!]
                    [!VAR "ChannelIsrUsed" = "'true'"!]
                    [!BREAK!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!IF "$ChannelIsrUsed = 'true'"!]
[!CODE!]
#define OCU_FTM_[!"$ModuleIdx"!]_CH_[!"num:i($ChannelIdx*2)"!]_CH_[!"num:i($ChannelIdx*2+1)"!]_ISR_USED
[!ENDCODE!]
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDFOR!]
[!ELSE!]
    [!FOR "ModuleIdx" = "0" TO "$numFtmHwModules - 1"!]
    [!VAR "ChannelIsrUsed" = "'false'"!]
    [!LOOP "OcuGeneral/OcuHwResourceConfig/*"!]
        [!IF "OcuIsrEnable = 'true' and contains(OcuHwResourceId, concat('FTM_',$ModuleIdx))"!]
            [!VAR "ChannelIsrUsed" = "'true'"!]
            [!BREAK!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$ChannelIsrUsed = 'true'"!]
[!CODE!]
#define OCU_FTM_[!"$ModuleIdx"!]_ISR_USED
[!ENDCODE!]
    [!ENDIF!]
    [!ENDFOR!]
[!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!]
/** @} */

#ifndef OCU_DEINIT_API
/** @brief      Switch to indicate that Ocu_DeInit() API is supported */
#define OCU_DEINIT_API      ([!IF "OcuConfigurationOfOptionalApis/OcuDeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_SET_PIN_STATE_API
/** @brief  Switch to indicate if Ocu_SetPinState() API is supported */
#define OCU_SET_PIN_STATE_API   ([!IF "OcuConfigurationOfOptionalApis/OcuSetPinStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_SET_PIN_ACTION_API
/** @brief  Switch to indicate if Ocu_SetPinAction() API is supported */
#define OCU_SET_PIN_ACTION_API  ([!IF "OcuConfigurationOfOptionalApis/OcuSetPinActionApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_GET_COUNTER_API
/** @brief   Switch to indicate if Ocu_GetCounter() API is supported */
#define OCU_GET_COUNTER_API     ([!IF "OcuConfigurationOfOptionalApis/OcuGetCounterApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_SET_ABSOLUTE_THRESHOLD_API
/** @brief  Switch to indicate if Ocu_SetAbsoluteThreshold() API is supported */
#define OCU_SET_ABSOLUTE_THRESHOLD_API  ([!IF "OcuConfigurationOfOptionalApis/OcuSetAbsoluteThresholdApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#ifndef OCU_SET_RELATIVE_THRESHOLD_API
/** @brief      Switch to indicate if Ocu_SetRelativeThreshold() API is supported */
#define OCU_SET_RELATIVE_THRESHOLD_API  ([!IF "OcuConfigurationOfOptionalApis/OcuSetRelativeThresholdApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

/** @brief    Support for Sim module is available */
#define OCU_SIM_AVAILABLE               ([!"$simAvailable"!])


#ifndef OCU_ENABLE_ISR_BY_EN_DIS_NOTIFICATION
/**
* @brief    Switch to indicate if channel interrupts are enabled/disabled by calling of EnableNotification()/DisableNotification() APIs
*           This feature is not supported for current implementation
*/
#define OCU_ENABLE_ISR_BY_EN_DIS_NOTIFICATION   (STD_OFF)
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif  /* FTM_OCU_IP_CFGDEFINES_H */

[!ENDCODE!]
