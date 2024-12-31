[!AUTOSPACING!][!//
[!NOCODE!][!//

[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "PBCfg_Variant" = "concat('PB_', $postBuildVariant)"!][!//
[!ELSE!][!//
    [!VAR "PBCfg_Variant" = "'PB'"!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//
[!CODE!][!//
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

/**
 * @file    Lpit_Icu_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c
 * @version 1.0.1
 *
 * @brief   AUTOSAR Icu - contains the data exported by the ICU module.
 * @details Contains the information that will be exported by the module, as requested by AUTOSAR.
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
#include "Lpit_Icu_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPIT_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID_C                    43
#define LPIT_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C     4
#define LPIT_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C     4
#define LPIT_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION_C  0
#define LPIT_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION_C             1
#define LPIT_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION_C             0
#define LPIT_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU Lpit_Icu_Ip_Types.h file are of the same vendor */
#if (LPIT_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID_C != LPIT_ICU_IP_TYPES_VENDOR_ID)
    #error "Lpit_Icu_Ip[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Lpit_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU Lpit_Icu_Ip_Types.h file are of the same AutoSar version */
#if ((LPIT_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C    != LPIT_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LPIT_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C    != LPIT_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LPIT_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION_C != LPIT_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lpit_Icu_Ip[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Lpit_Icu_Ip_Types.h are different"
#endif
/* Check if source file and ICU Lpit_Icu_Ip_Types.h file are of the same Software version */
#if ((LPIT_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION_C != LPIT_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (LPIT_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION_C != LPIT_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (LPIT_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION_C != LPIT_ICU_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Lpit_Icu_Ip[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Lpit_Icu_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/** @brief Signature of report events interrupt function. */
extern void Icu_ReportEvents(uint16 Channel, boolean bOverflow);

/** @brief Signature of wakeup and overflow interrupt function. */
extern void Icu_ReportWakeupAndOverflow(uint16 Channel, boolean bOverflow);

/** @brief Signature of change logic channel state function. */
extern void Icu_LogicChStateCallback(uint16 logicChannel, uint8 mask, boolean set);

[!NOCODE!]
    [!SELECT "IcuConfigSet"!]
     [!LOOP "./IcuLpit/*"!]
     [!LOOP "./IcuLpitChannels/*"!]
        [!IF "(contains(node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode),'ICU_MODE_TIMESTAMP') and node:exists(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuTimestampMeasurement/IcuTimestampNotification) and (node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuTimestampMeasurement/IcuTimestampNotification) != 'NULL_PTR') and (node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuTimestampMeasurement/IcuTimestampNotification) != 'NULL'))"!]
[!CODE!]/**
* @brief External Notifications for Timestamp
*
*/
extern void [!"node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuTimestampMeasurement/IcuTimestampNotification)"!](void);
[!ENDCODE!][!//
        [!ENDIF!]

        [!IF "(contains(node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode),'ICU_MODE_SIGNAL_EDGE_DETECT') and node:exists(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuSignalEdgeDetection/IcuSignalNotification) and (node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuSignalEdgeDetection/IcuSignalNotification) != 'NULL_PTR') and (node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuSignalEdgeDetection/IcuSignalNotification) != 'NULL'))"!]
[!CODE!]/**
* @brief External Notifications for Signal Edge Detection
*
*/
extern void [!"node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuSignalEdgeDetection/IcuSignalNotification)"!](void);
[!ENDCODE!][!//
        [!ENDIF!]
     [!ENDLOOP!]
     [!ENDLOOP!]
    [!ENDSELECT!]
[!ENDNOCODE!][!//
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

[!NOCODE!][!//

[!// Generate LPIT channels configuration
[!SELECT "./IcuConfigSet"!][!//
[!IF "count(IcuLpit/*) > '0'"!][!//
    [!LOOP "IcuLpit/*"!][!//
        [!CODE!][!WS "0"!]/** @brief LPIT instance [!"node:value(./IcuLpitModule)"!] channels configuration. */[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]const Lpit_Icu_Ip_ChannelConfigType Lpit_Icu_Ip_[!"node:value(./IcuLpitModule)"!]_ChannelConfig_[!"$PBCfg_Variant"!][[!"num:i(count(IcuLpitChannels/*))"!]U] = [!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]{[!CR!][!ENDCODE!][!//
        [!VAR "comma" = "num:i(count(IcuLpitChannels/*))"!][!//
        [!LOOP "IcuLpitChannels/*"!][!//
            [!CODE!][!WS "4"!]/** @brief [!"node:name(.)"!] */[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "8"!]/** @brief Index of LPIT hardware channel used. */[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "8"!](uint8)[!"node:value(IcuLpitChannel)"!]U,[!CR!][!ENDCODE!][!//

            [!CODE!][!WS "8"!]/** @brief LPIT channel trigger select. */[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "8"!][!"node:value(IcuLpitTriggerSelect)"!],[!CR!][!ENDCODE!][!//

            [!CODE!][!WS "8"!]/** @brief LPIT channel trigger source. */[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "8"!]LPIT_ICU_CH_[!"node:value(IcuLpitTriggerSource)"!],[!CR!][!ENDCODE!][!//

            [!CODE!][!WS "0"!]#if (STD_ON == LPIT_ICU_TIMESTAMP_API)[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "8"!]/** @brief Timestamp buffer mode. */[!CR!][!ENDCODE!][!//
            [!IF "node:exists(../../../../IcuChannel/*[contains(node:value(IcuChannelRef), as:path(node:current()))]/IcuTimestampMeasurement)"!][!//
                [!VAR "nodeMeasType" = "node:value(../../../../IcuChannel/*[contains(node:value(IcuChannelRef), as:path(node:current()))]/IcuTimestampMeasurement/IcuTimestampMeasurementProperty)"!][!//
                [!CODE!][!WS "8"!][!"text:replace($nodeMeasType, 'ICU_', 'LPIT_ICU_IP_')"!],[!CR!][!ENDCODE!][!//
            [!ELSE!][!//
                [!CODE!][!WS "8"!]LPIT_ICU_IP_NO_BUFFER,[!CR!][!ENDCODE!][!//
            [!ENDIF!][!//
            [!CODE!][!WS "0"!]#endif[!CR!][!ENDCODE!][!//

            [!CODE!][!WS "8"!]/** @brief Callback function for channels. */[!CR!][!ENDCODE!][!//
            [!IF "(node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode) = 'ICU_MODE_SIGNAL_EDGE_DETECT') or
                    ((node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode) = 'ICU_MODE_TIMESTAMP') and
                     (node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuOverflowNotification) != 'NULL_PTR'))"!][!//
                [!CODE!][!WS "8"!]&Icu_ReportEvents,[!CR!][!ENDCODE!][!//
            [!ELSEIF "node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode) = 'ICU_MODE_EDGE_COUNTER'"!][!//
                [!CODE!][!WS "8"!]&Icu_ReportWakeupAndOverflow,[!CR!][!ENDCODE!][!//
            [!ELSE!][!//
                [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!][!//
            [!ENDIF!][!//

            [!CODE!][!WS "8"!]/** @brief Parameters used by callback function. */[!CR!][!ENDCODE!]
            [!CODE!][!WS "8"!](uint8)[!"node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(IcuChannelRef)) = as:path(node:current())]/IcuChannelId)"!]U,[!CR!][!ENDCODE!]

            [!CODE!][!WS "8"!]/** @brief Address of function used to change logic channel state in HLD. */[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "8"!]&Icu_LogicChStateCallback,[!CR!][!ENDCODE!][!//

            [!CODE!][!WS "8"!]/** @brief Pointer to the user notification function. */[!CR!][!ENDCODE!][!//
            [!IF "(contains(node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode),'ICU_MODE_TIMESTAMP') and node:exists(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuTimestampMeasurement/IcuTimestampNotification) and (node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuTimestampMeasurement/IcuTimestampNotification) != 'NULL_PTR') and (node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuTimestampMeasurement/IcuTimestampNotification) != 'NULL'))"!][!//
                [!CODE!][!WS "8"!]&[!"node:value(../../../../IcuChannel/*[contains(node:value(IcuChannelRef), as:path(node:current()))]/IcuTimestampMeasurement/IcuTimestampNotification)"!][!CR!][!ENDCODE!][!//
            [!ELSEIF "(contains(node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode),'ICU_MODE_SIGNAL_EDGE_DETECT') and node:exists(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuSignalEdgeDetection/IcuSignalNotification) and (node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuSignalEdgeDetection/IcuSignalNotification) != 'NULL_PTR') and (node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuSignalEdgeDetection/IcuSignalNotification) != 'NULL'))"!][!//
                [!CODE!][!WS "8"!]&[!"node:value(../../../../IcuChannel/*[contains(node:value(IcuChannelRef), as:path(node:current()))]/IcuSignalEdgeDetection/IcuSignalNotification)"!][!CR!][!ENDCODE!][!//
            [!ELSE!][!//
                    [!CODE!][!WS "8"!]NULL_PTR[!CR!][!ENDCODE!][!//
            [!ENDIF!][!//
            
            [!CODE!][!WS "4"!]}[!ENDCODE!][!//
            [!IF "(num:i($comma))>1"!][!CODE!],[!CR!][!CR!][!ENDCODE!][!VAR "comma"="$comma - 1"!][!ELSE!][!CR!][!ENDIF!][!//
        [!ENDLOOP!][!//
        [!CODE!][!WS "0"!]};[!CR!][!ENDCODE!][!//
    [!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

[!ENDNOCODE!][!//

[!NOCODE!][!//

[!// Generate LPIT instance configuration
[!SELECT "./IcuConfigSet"!][!//
[!IF "count(IcuLpit/*) > '0'"!][!//
    [!LOOP "IcuLpit/*"!][!//
        [!CODE!][!WS "0"!]/** @brief LPIT instance [!"node:value(./IcuLpitModule)"!] configuration. */[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]const Lpit_Icu_Ip_ConfigType Lpit_Icu_Ip_[!"node:value(./IcuLpitModule)"!]_InstanceConfig_[!"$PBCfg_Variant"!] = [!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]{[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "4"!]/** @brief Index of LPIT hardware instance used. */[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "4"!](uint8)[!"node:value(IcuLpitModule)"!]U,[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "4"!]/** @brief Enable/disable debug mode. */[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "4"!](boolean)[!"text:toupper(node:value(IcuLpitDebugEnable))"!],[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "4"!]/** @brief Number of channels on current instance. */[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "4"!](uint8)[!"num:i(count(IcuLpitChannels/*))"!]U,[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "4"!]/** @brief Pointer to channels configuration. */[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "4"!]&Lpit_Icu_Ip_[!"node:value(./IcuLpitModule)"!]_ChannelConfig_[!"$PBCfg_Variant"!][!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]};[!CR!][!ENDCODE!][!//
    [!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

[!ENDNOCODE!][!//

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!][!//
