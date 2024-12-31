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

/**
 *   @file       Ftm_Icu_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c
 *   @version    1.0.1
 *
 *   @brief      AUTOSAR Icu - contains the data exported by the ICU module.
 *   @details    Contains the information that will be exported by the module, as requested by AUTOSAR.
 *
 *   @addtogroup ftm_icu_ip FTM IPL
 *   @{
 */

#ifdef __cplusplus
extern "C"{
#endif

[!// MACRO for creating the IP configuration structure(s)
[!MACRO "ICU_GENERATE_IP_CONFIGURATION","VARIANT"="'PB'"!][!//
[!NOCODE!]

/*==================================================================================================
 *                              GENERATION MACRO DEFINTION 
 *================================================================================================*/

[!SELECT "./IcuConfigSet"!]
[!IF "count(IcuFtm/*) > '0'"!]
    [!LOOP "IcuFtm/*"!]

        [!CODE!][!CR!]/**[!CR!][!ENDCODE!]
        [!CODE!] *  @brief    [!"$VARIANT"!] FTM Channels Configuration[!CR!][!ENDCODE!]
        [!CODE!] */[!CR!][!ENDCODE!]
        [!CODE!][!WS "0"!]const Ftm_Icu_Ip_ChannelConfigType Ftm_Icu_Ip_[!"node:value(./IcuFtmModule)"!]_ChannelConfig_[!"$PBCfg_Variant"!][[!"num:i(count(IcuFtmChannels/*))"!]U] = [!CR!][!ENDCODE!]
        [!CODE!]{[!CR!][!ENDCODE!]                        
        [!VAR "comma" = "num:i(count(IcuFtmChannels/*))"!]
            [!LOOP "IcuFtmChannels/*"!]
                [!CODE!][!WS "4"!]/** @brief [!"node:name(.)"!] */[!CR!][!ENDCODE!]
                [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!]
                [!CODE!][!WS "8"!]/** @brief ID of FTM hardware channel used. */[!CR!][!ENDCODE!]
                [!CODE!][!WS "8"!](uint8)[!"node:value(IcuFtmChannel)"!],[!CR!][!ENDCODE!]

                [!CODE!][!WS "8"!]/** @brief FTM IP layer mode of operation. */[!CR!][!ENDCODE!]
                [!CODE!][!WS "8"!]FTM_[!"node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode)"!],[!CR!][!ENDCODE!]

                [!CODE!][!WS "8"!]/** @brief DMA support for timestamp measurement. */[!CR!][!ENDCODE!]
                /* TODO: Ask for the correct way */
                [!IF "node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuDMAChannelEnable)"!]
                    [!CODE!][!WS "8"!]FTM_ICU_MODE_WITH_DMA,[!CR!][!ENDCODE!]
                [!ELSE!]
                    [!CODE!][!WS "8"!]FTM_ICU_MODE_WITHOUT_DMA,[!CR!][!ENDCODE!]
                [!ENDIF!]

                [!CODE!][!WS "8"!]/** @brief Measurement mode for signal measurement. */[!CR!][!ENDCODE!]
                [!IF "node:exists(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuSignalMeasurement) and
                      (text:split(node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode), 'MODE_')[2] = 'SIGNAL_MEASUREMENT')"!]
                    [!CODE!][!WS "8"!]FTM_[!"node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuSignalMeasurement/IcuSignalMeasurementProperty)"!],[!CR!][!ENDCODE!]
                [!ELSE!]
                    [!CODE!][!WS "8"!]FTM_ICU_NO_MEASUREMENT,[!CR!][!ENDCODE!]
                [!ENDIF!]

                [!CODE!][!WS "8"!]/** @brief Edge alignment for signal measurement. */[!CR!][!ENDCODE!]
                [!CODE!][!WS "8"!]FTM_[!"node:value(../../../../IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuDefaultStartEdge)"!],[!CR!][!ENDCODE!]

                [!CODE!][!WS "8"!]/** @brief Continuos measurement enable/disable. */[!CR!][!ENDCODE!]
                /* TODO: Remove hardcodeed, put the checkbox in Tresos. */
                [!CODE!][!WS "8"!](boolean)FALSE,[!CR!][!ENDCODE!]

                [!CODE!][!WS "8"!]/** @brief FTM Channel Input Filter value */[!CR!][!ENDCODE!]
                [!CODE!][!WS "8"!](uint8)[!"node:value(IcuFtmFilter)"!],[!CR!][!ENDCODE!]

                [!CODE!][!WS "8"!]/** @brief Callback function for channels. */[!CR!][!ENDCODE!]
                [!IF "(node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode) = 'ICU_MODE_SIGNAL_EDGE_DETECT') or
                        (((node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode) = 'ICU_MODE_SIGNAL_MEASUREMENT') or
                         (node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode) = 'ICU_MODE_TIMESTAMP')) and
                         (node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuOverflowNotification) != 'NULL_PTR'))"!]
                    [!CODE!][!WS "8"!]&Icu_ReportEvents,[!CR!][!ENDCODE!]
                [!ELSEIF "node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode) = 'ICU_MODE_EDGE_COUNTER'"!]
                    [!CODE!][!WS "8"!]&Icu_ReportWakeupAndOverflow,[!CR!][!ENDCODE!][!//
                [!ELSE!][!//
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!][!//
                [!ENDIF!][!//

                [!CODE!][!WS "8"!]/** @brief Parameters used by callback function. */[!CR!][!ENDCODE!]
                [!CODE!][!WS "8"!](uint8)[!"node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(IcuChannelRef)) = as:path(node:current())]/IcuChannelId)"!],[!CR!][!ENDCODE!][!//

                [!CODE!][!WS "0"!]#if (STD_ON == FTM_ICU_TIMESTAMP_API)[!CR!][!ENDCODE!][!//
                [!CODE!][!WS "8"!]/** @brief Timestamp buffer used. */[!CR!][!ENDCODE!][!//
                [!IF "(node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode) = 'ICU_MODE_TIMESTAMP')"!]
                    [!CODE!][!WS "8"!]FTM_[!"node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(IcuChannelRef)) = as:path(node:current())]/IcuTimestampMeasurement/IcuTimestampMeasurementProperty)"!],[!CR!][!ENDCODE!]
                [!ELSE!]
                    [!CODE!][!WS "8"!]FTM_ICU_NO_TIMESTAMP,[!CR!][!ENDCODE!]
                [!ENDIF!]
                [!CODE!][!WS "0"!]#endif[!CR!][!ENDCODE!][!//
                
                [!CODE!][!WS "8"!]&Icu_LogicChStateCallback,[!ENDCODE!]
                [!CODE!][!WS "4"!]/** @brief Address of function used to change logic channel state in HLD. */[!CR!][!ENDCODE!][!//
                
                [!CODE!][!WS "8"!]/** @brief Channel specific notification(e.g timestamp). */[!CR!][!ENDCODE!][!//
                [!IF "(node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode) = 'ICU_MODE_TIMESTAMP')"!][!//
                    [!IF "contains(node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(IcuChannelRef)) = as:path(node:current())]/IcuTimestampMeasurement/IcuTimestampNotification), 'NULL_PTR')"!][!//
                        [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!][!//
                    [!ELSE!][!//
                        [!CODE!][!WS "8"!]&[!"node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(IcuChannelRef)) = as:path(node:current())]/IcuTimestampMeasurement/IcuTimestampNotification)"!],[!CR!][!ENDCODE!][!//
                    [!ENDIF!][!//
                [!ELSE!][!//
                    [!CODE!][!WS "8"!]NULL_PTR,[!CR!][!ENDCODE!][!//
                [!ENDIF!][!//

                [!CODE!][!WS "8"!]/** @brief Logic channel overflow notification. */[!CR!][!ENDCODE!][!//
                [!CODE!][!WS "8"!][!"node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(IcuChannelRef)) = as:path(node:current())]/IcuOverflowNotification)"!][!CR!][!ENDCODE!][!//

                [!CODE!][!WS "4"!]}[!ENDCODE!]
                [!IF "(num:i($comma))>1"!][!CODE!],[!CR!][!ENDCODE!][!VAR "comma"="$comma - 1"!][!ELSE!][!CR!][!ENDIF!]
            [!ENDLOOP!]
        [!CODE!]};[!CR!][!ENDCODE!]
    
        [!CODE!][!CR!]/**[!CR!][!ENDCODE!]
        [!CODE!] *  @brief [!"$VARIANT"!] FTM [!"node:value(./IcuFtmModule)"!] Instance Configuration[!CR!][!ENDCODE!]
        [!CODE!] */[!CR!][!ENDCODE!]
        [!CODE!]const Ftm_Icu_Ip_InstanceConfigType Ftm_Icu_Ip_[!"node:value(./IcuFtmModule)"!]_InstanceConfig_[!"$VARIANT"!] = [!CR!]{[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]/** @brief FTM clock source */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]FTM_[!"node:value(./IcuFtmClockSource)"!],[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]/** @brief FTM instance prescaler  */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!](uint8)[!"num:i(node:value(./IcuFtmPrescaler))"!],[!CR!][!ENDCODE!]
        [!CODE!][!WS "0"!]#if (FTM_ICU_DUAL_CLOCK_MODE_API == STD_ON)[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]/** @brief FTM instance alternate prescaler  */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!](uint8)[!"num:i(node:value(./IcuFtmPrescalerAlternate))"!],[!CR!][!ENDCODE!]
        [!CODE!][!WS "0"!]#endif[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]/** @brief FTM debug mode  */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!][!"node:value(./IcuFtmDebugMode)"!],[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]/** @brief FTM maxim counter value */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!](uint16)[!"num:i(node:value(./IcuFtmModValue))"!][!CR!][!ENDCODE!]
        [!CODE!]};[!CR!][!ENDCODE!]

        [!CODE!][!CR!]/**[!CR!][!ENDCODE!]
        [!CODE!] *  @brief    [!"$VARIANT"!] Default FTM IP Configuration[!CR!][!ENDCODE!]
        [!CODE!] */[!CR!][!ENDCODE!]
        [!CODE!]const Ftm_Icu_Ip_ConfigType Ftm_Icu_Ip_[!"node:value(./IcuFtmModule)"!]_Config_[!"$VARIANT"!] = [!CR!]{[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]/** @brief Number of FTM channels in the Icu configuration */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!](uint8)[!"num:i(count(IcuFtmChannels/*))"!],[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]/** @brief The FTM instance configuration */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]&Ftm_Icu_Ip_[!"node:value(./IcuFtmModule)"!]_InstanceConfig_[!"$VARIANT"!],[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]/** @brief Pointer to the array of FTM channel configurations */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]&Ftm_Icu_Ip_[!"node:value(./IcuFtmModule)"!]_ChannelConfig_[!"$VARIANT"!][!CR!][!ENDCODE!]
        [!CODE!]};[!CR!][!ENDCODE!] 

    [!ENDLOOP!]

[!ENDIF!]
[!ENDSELECT!]
[!ENDNOCODE!]
[!ENDMACRO!][!// End of Macro ICU_GENERATE_FTM_IP_CONFIGURATION
/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ftm_Icu_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID_C                    43
#define FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C     4
#define FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C     4
#define FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION_C  0
#define FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION_C             1
#define FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION_C             0
#define FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID_C != FTM_ICU_IP_TYPES_VENDOR_ID)
    #error "Ftm_Icu_Ip[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ftm_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C != FTM_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C != FTM_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION_C != FTM_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ftm_Icu_Ip[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ftm_Icu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION_C != FTM_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION_C != FTM_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (FTM_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION_C != FTM_ICU_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Ftm_Icu_Ip[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ftm_Icu_Ip_Types.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

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

[!SELECT "./IcuConfigSet"!][!//
[!IF "count(IcuFtm/*) > '0'"!][!//
    [!LOOP "IcuFtm/*"!][!//
        [!LOOP "IcuFtmChannels/*"!][!//
            [!IF "(node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode) = 'ICU_MODE_TIMESTAMP')"!][!//
                [!IF "not(contains(node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(IcuChannelRef)) = as:path(node:current())]/IcuTimestampMeasurement/IcuTimestampNotification), 'NULL_PTR'))"!][!//
                    [!CODE!][!WS "0"!]/** @brief External Notifications for Timestamp function. */[!CR!][!ENDCODE!][!//
                    [!CODE!][!WS "0"!]extern void [!"node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(IcuChannelRef)) = as:path(node:current())]/IcuTimestampMeasurement/IcuTimestampNotification)"!](void);[!CR!][!ENDCODE!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
            
            [!IF "(node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode) = 'ICU_MODE_TIMESTAMP') or (node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode) = 'ICU_MODE_SIGNAL_MEASUREMENT') or (node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(./IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode) = 'ICU_MODE_EDGE_COUNTER')"!][!//
                [!IF "not(contains(node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(IcuChannelRef)) = as:path(node:current())]/IcuOverflowNotification), 'NULL_PTR'))"!][!//
                    [!CODE!][!WS "0"!]/** @brief The overflow notification functions. */[!CR!][!ENDCODE!][!//
                    [!CODE!][!WS "0"!]extern void [!"node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(IcuChannelRef)) = as:path(node:current())]/IcuOverflowNotification)"!](void);[!CR!][!ENDCODE!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

[!ENDNOCODE!]

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "PBCfg_Variant" = "concat('PB_', $postBuildVariant)"!]
[!ELSE!]
    [!VAR "PBCfg_Variant" = "'PB'"!]
[!ENDIF!]

[!CALL "ICU_GENERATE_IP_CONFIGURATION","VARIANT"="$PBCfg_Variant"!]

[!ENDNOCODE!]
#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!]
