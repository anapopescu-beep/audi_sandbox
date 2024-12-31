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
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Ftm
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
*   @file          Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.c
*                  
*   @addtogroup    ocu_ip Ocu IPL
*   @brief         Ocu IPL Postbuild configuration source file.
*   @details       Postbuild configuration structure instances.
*
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_OCU_IP[!"$VS_number"!]_PBCFG_VENDOR_ID_C                       43
#define FTM_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C        4
#define FTM_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C        4
#define FTM_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C     0
#define FTM_OCU_IP[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION_C                1
#define FTM_OCU_IP[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION_C                0
#define FTM_OCU_IP[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION_C                1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (FTM_OCU_IP[!"$VS_number"!]_PBCFG_VENDOR_ID_C != FTM_OCU_IP[!"$VS_number"!]_PBCFG_VENDOR_ID)
    #error "Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.c and Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.h have different vendor ids"
#endif

/* Check if  source file and Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.h file are of the same Autosar version */
#if ((FTM_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != FTM_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != FTM_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (FTM_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != FTM_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.c and Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.h are different"
#endif

/* Check if source file and Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.h file are of the same Software version */
#if ((FTM_OCU_IP[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION_C != FTM_OCU_IP[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION) || \
     (FTM_OCU_IP[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION_C != FTM_OCU_IP[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION) || \
     (FTM_OCU_IP[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION_C != FTM_OCU_IP[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.c and Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.h are different"
#endif

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*===============================================================================================
*                                       LOCAL MACROS
===============================================================================================*/
[!NOCODE!]
    [!VAR "numOcuChannels" = "num:i(count(OcuConfigSet/OcuChannel/*))"!]
    [!VAR "numOcuModules" = "num:i(count(OcuConfigSet/OcuHWSpecificSettings/*))"!]
    
    [!VAR "max_number_ocu_cfg" = "num:i(count(./OcuGeneral/OcuEcucPartitionRef/*))"!]

    [!VAR "MacNumFtmChannels"="0"!]
    /* Loop on all channels inside the same configuration Set */
    [!LOOP "OcuConfigSet/OcuChannel/*"!][!//
        [!IF "contains(HwChannel, 'FTM')"!][!//
            [!VAR "MacNumFtmChannels"="$MacNumFtmChannels + 1"!]
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!]

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                        GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
extern void Ocu_ProcessChannelNotification(uint16 Channel);
#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

#define OCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

[!NOCODE!]

[!SELECT "OcuConfigSet"!]

[!VAR "numOcuChannelsInCfg" = "num:i(count(OcuChannel/*))"!]
[!IF "$max_number_ocu_cfg = 0"!]
[!CODE!]
/** @brief Number of configured Ocu channels */
#define NUMBER_CHANNEL[!"$VS_number"!] [!"$numOcuChannelsInCfg"!]U
[!CR!][!ENDCODE!]
[!ENDIF!]

[!VAR "OcuPartitionId_temp" = "num:i(0)"!]

[!LOOP "../OcuGeneral/OcuEcucPartitionRef/*"!]
    [!VAR "OcuEcucPartitionRefName" = "node:value(.)"!]
    [!VAR "channelMatched" = "0"!]

    [!LOOP "../../../OcuConfigSet/OcuChannel/*"!]
        [!VAR "OcuEcucPartitionChannel" = "node:value(OcuChannelEcucPartitionRef/*[1])"!]

        [!IF "($OcuEcucPartitionRefName = $OcuEcucPartitionChannel)"!]
            [!VAR "channelMatched"="$channelMatched + 1"!]
        [!ENDIF!]
    [!ENDLOOP!]

[!CODE!]
/** @brief  Number of configured Ocu channels of Partition [!"$OcuPartitionId_temp"!] */ 
#define NUMBER_CHANNEL[!"$VS_number"!]_P[!"$OcuPartitionId_temp"!]  [!"num:i($channelMatched)"!]U
[!CR!][!ENDCODE!]

    [!VAR "OcuPartitionId_temp" = "num:i($OcuPartitionId_temp + 1)"!]
[!ENDLOOP!]

/** @brief counter direction */
[!IF "node:exists(OcuCountdirection)"!]
    [!IF "(OcuCountdirection = 'OCU_FTM_DOWNCOUNTING')"!]
        [!VAR "FtmCountDir" = "'((uint32)OCU_FTM_DOWNCOUNTING << OCU_FTM_COUNT_DIR_SHIFT)'"!]
    [!ELSE!]
        [!VAR "FtmCountDir" = "'((uint32)OCU_FTM_UPCOUNTING << OCU_FTM_COUNT_DIR_SHIFT)'"!]
    [!ENDIF!]
    [!ELSE!]
    [!VAR "FtmCountDir" = "'((uint32)OCU_FTM_UPCOUNTING << OCU_FTM_COUNT_DIR_SHIFT)'"!]
[!ENDIF!]

/* =====================================================================*/
[!MACRO "GENERATE_CHANNELCONFIG", "OcuEcucPartitionName", "OcuPartitionId"!]

[!IF "$max_number_ocu_cfg != 0"!]
    [!VAR "OcuPartitionIndex" = "concat('_P',$OcuPartitionId)"!]
[!ELSE!]
    [!VAR "OcuPartitionIndex" = "''"!]
[!ENDIF!]

[!IF "(num:i($MacNumFtmChannels)) != 0"!]

[!CODE!][!CR!]
/***************************** Configuration for Ftm ********************/

/** @brief    Configurations for OCU channels using Ftm */
static const Ftm_Ocu_Ip_ChannelConfigType Ftm_Ocu_Ip_ChannelConfig_PB[!"$VS_number"!][!"$OcuPartitionIndex"!][NUMBER_CHANNEL[!"$VS_number"!][!"$OcuPartitionIndex"!]] = {
[!ENDCODE!]

[!VAR "comma" = "1"!]
[!VAR "numOcuChannels" = "num:i(count(../../OcuConfigSet/OcuChannel/*))"!]
[!FOR "varCounter" = "0" TO "$numOcuChannels"!]
    [!LOOP "../../OcuConfigSet/OcuChannel/*"!]  
        [!IF "OcuChannelId = $varCounter"!]
            [!VAR "OcuEcucPartitionChannel" = "''"!]
            [!IF "$max_number_ocu_cfg != 0"!]
                [!VAR "OcuEcucPartitionChannel" = "node:value(OcuChannelEcucPartitionRef/*[1])"!]
            [!ENDIF!]

            [!VAR "DefaultThreshold" = "num:i(OcuDefaultThreshold)"!]
            [!VAR "PinUsed" = "OcuOuptutPinUsed"!]
            [!VAR "PinState" = "'(OCU_FTM_OUTPUTDISABLED)'"!]
            [!VAR "PinAction" = "'((uint8)(FTM_OCU_SET_DISABLE) << OCU_FTM_PIN_ACTION_SHIFT)'"!]

            [!IF "($PinUsed = 'true')"!]
                [!IF "(node:exists('OcuOutputPinDefaultState'))"!]
                    [!IF "(OcuOutputPinDefaultState = 'OCU_HIGH')"!]
                        [!VAR "PinState"= "'(1UL << OCU_FTM_OUTPIN_USED_SHIFT) | ((uint8)OCU_FTM_HIGH << OCU_FTM_PIN_STATE_SHIFT)'"!]
                    [!ELSE!]
                        [!VAR "PinState"= "'(1UL << OCU_FTM_OUTPIN_USED_SHIFT)'"!]
                    [!ENDIF!]
                [!ELSE!]
                    [!VAR "PinState"= "'(1UL << OCU_FTM_OUTPIN_USED_SHIFT)'"!]
                [!ENDIF!]

                [!IF "(node:exists('OcuOutputPinAction'))"!]
                    [!IF "(OcuOutputPinAction = 'OCU_SET_HIGH')"!]
                        [!VAR "PinAction"= "'((uint8)(FTM_OCU_SET_HIGH) << OCU_FTM_PIN_ACTION_SHIFT)'"!]
                    [!ELSEIF "(OcuOutputPinAction = 'OCU_TOGGLE')"!]
                        [!VAR "PinAction"= "'((uint8)(FTM_OCU_SET_TOGGLE) << OCU_FTM_PIN_ACTION_SHIFT)'"!]
                    [!ELSEIF "(OcuOutputPinAction = 'OCU_DISABLE')"!]
                        [!VAR "PinAction"= "'((uint8)(FTM_OCU_SET_DISABLE) << OCU_FTM_PIN_ACTION_SHIFT)'"!]
                    [!ELSE!]
                        [!VAR "PinAction"= "'((uint8)(FTM_OCU_SET_LOW) << OCU_FTM_PIN_ACTION_SHIFT)'"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]

            [!VAR "MacChannelId" = "num:i(./OcuChannelId)"!]
            [!VAR "LocalHardwareElements" = "node:value(./HwChannel)"!]
            [!LOOP "../../../OcuGeneral/OcuHwResourceConfig/*"!][!//
                [!IF "((node:value(OcuChannelIsUsed) = 'true') and contains(OcuHwResourceId, 'FTM')) and (not(OcuIsrEnable = 'true'))"!][!//
                    [!IF "node:value(./OcuHwResourceId) = $LocalHardwareElements"!]
                        [!VAR "MacChannelId" = "num:i(255)"!]
                    [!ENDIF!]
                [!ENDIF!][!//
            [!ENDLOOP!][!//

            [!IF "$OcuEcucPartitionName = $OcuEcucPartitionChannel"!]
            [!CODE!]
                /* [!"node:name(.)"!] -> [!"HwChannel"!] */
                {
                    /** @brief  Ftm hardware channel */
                    (uint16)[!"HwChannel"!],
                    /** @brief  Default threshold: [!"$DefaultThreshold"!] */
                    (uint16)[!"num:inttohex($DefaultThreshold,4)"!],
                    /** @brief  Ftm Control Value */
                    (uint8)
                    (
                    [!WS "12"!][!"$PinState"!] |    /* Output Pin Enable and default state */
                    [!WS "12"!][!"$PinAction"!]     /* Output Pin default action */
                    ),
            #if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
                    [!WS "8"!]/** @brief Ftm callback function name */[!CR!]
                    [!WS "8"!]&Ocu_ProcessChannelNotification,[!CR!]
                    [!WS "8"!]/** @brief Ftm callback param */[!CR!]
                    [!WS "8"!](uint16)[!"$MacChannelId"!]U[!CR!]
            #endif
                }[!IF "(num:i($comma))<(num:i($numOcuChannels))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!]
            [!ENDCODE!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDFOR!]
[!CODE!]
};
[!ENDCODE!]

[!CODE!][!CR!]
/** @brief    Configurations for OCU modules using Ftm */
static const Ftm_Ocu_Ip_SpecificIpConfigType Ftm_Ocu_Ip_SpecificIpConfig_PB[!"$VS_number"!][!"$OcuPartitionIndex"!][OCU_CONF_FTM_MODULES_PB] = {
[!ENDCODE!]

        [!VAR "comma" = "1"!]

        [!LOOP "../../OcuConfigSet/OcuHWSpecificSettings/*"!]
            /* Get hw information: clock source */
            [!IF "(node:exists('OcuClockSource'))"!]
                [!IF "node:value(OcuClockSource) = 'OCU_SYSTEM_CLOCK'"!]
                    [!VAR "SourceClock" = "'((uint8)(FTM_CLOCK_SOURCE_SYSTEMCLK) << OCU_FTM_CLOCK_SOURCE_SHIFT)'"!]
                [!ELSE!]
                    [!VAR "SourceClock" = "'((uint8)(FTM_CLOCK_SOURCE_EXTERNALCLK) << OCU_FTM_CLOCK_SOURCE_SHIFT)'"!]
                [!ENDIF!]
            [!ELSE!]
                [!VAR "SourceClock" = "'((uint8)(FTM_CLOCK_SOURCE_SYSTEMCLK) << OCU_FTM_CLOCK_SOURCE_SHIFT)'"!]
            [!ENDIF!]

            /* Get hw information: prescaler */
            [!IF "(node:exists('OcuPrescale'))"!]
                [!VAR "Prescaler" = "node:value(OcuPrescale)"!]
            [!ELSE!]
                [!VAR "Prescaler" = "'DIV1'"!]
            [!ENDIF!]

            [!VAR "Prescaler" = "concat('FTM_SC_PS_', $Prescaler,'_U32')"!]
            [!VAR "Prescaler" = "concat('(uint8)((uint32)(', $Prescaler, ') << OCU_FTM_CLOCK_DIV_SHIFT)')"!]

            /* Get hw information: alternate prescaler */
            [!IF "(node:exists('OcuPrescale_Alternate'))"!]
                [!VAR "AltPrescaler" = "OcuPrescale_Alternate"!]
            [!ELSE!]
                [!VAR "AltPrescaler" = "'DIV1'"!]
            [!ENDIF!]

            [!VAR "AltPrescaler" = "concat('FTM_SC_PS_', $AltPrescaler,'_U32')"!]
            [!VAR "AltPrescaler" = "concat('(uint8)((uint32)(', $AltPrescaler, ') << OCU_FTM_ALT_CLOCK_DIV_SHIFT)')"!]

            /* Get hw information: debug information */
            [!IF "OcuDebugMode = 'CNT_STOPED_FLAG_SET'"!]
                [!VAR "DebugCfg" = "'((uint8)(FTM_BDM_MODE_00) << FTM_CONF_BDMMODE_SHIFT_U8)'"!]
            [!ELSEIF "OcuDebugMode = 'CNT_STOPED_OUTPUTS_SAFE'"!]
                [!VAR "DebugCfg" = "'((uint8)(FTM_BDM_MODE_01) << FTM_CONF_BDMMODE_SHIFT_U8)'"!]
            [!ELSEIF "OcuDebugMode = 'CNT_STOPED_OUTPUTS_FROZEN'"!]
                [!VAR "DebugCfg" = "'((uint8)(FTM_BDM_MODE_10) << FTM_CONF_BDMMODE_SHIFT_U8)'"!]
            [!ELSE!]
                [!VAR "DebugCfg" = "'((uint8)(FTM_BDM_MODE_11) << FTM_CONF_BDMMODE_SHIFT_U8)'"!]
            [!ENDIF!]

            /* Process Max Couter Value */
            [!VAR "FtmModId" = "OcuFtmModule"!]
            [!VAR "ModuleMaxCounterValue" = "num:i(0)"!]

            [!VAR "OcuEcucPartitionChannel" = "''"!]
            [!LOOP "../../OcuChannel/*"!]
                [!IF "substring-before(HwChannel,'_CH') = $FtmModId"!]
                    [!IF "$max_number_ocu_cfg != 0"!]
                        [!VAR "OcuEcucPartitionChannel" = "node:value(OcuChannelEcucPartitionRef/*[1])"!]
                    [!ENDIF!]
                    [!IF "$ModuleMaxCounterValue = 0"!]
                        [!VAR "ModuleMaxCounterValue" = "OcuMaxCounterValue"!]
                    [!ELSEIF "$ModuleMaxCounterValue != OcuMaxCounterValue"!]
                        [!ERROR!]
[!"@name"!] uses [!"substring-before(HwChannel,'_CH')"!], has max counter value is [!"OcuMaxCounterValue"!] but
other OcuChannel using also [!"substring-before(HwChannel,'_CH')"!] has max counter value is [!"$ModuleMaxCounterValue"!].
They must have same max counter value since each Ftm module has only one counter.
                        [!ENDERROR!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
[!IF "$OcuEcucPartitionName = $OcuEcucPartitionChannel"!]
[!CODE!]
    /* [!"node:name(.)"!] -> [!"OcuFtmModule"!] */
    {
        /** @brief  Ftm hardware module index */
        (uint8)[!"text:split(OcuFtmModule,'_')[2]"!],
        /** @brief  Max Counter Value */
        (uint16)[!"$ModuleMaxCounterValue"!]U,
        /** @brief  Ftm Control Value */
        (uint8)
        (
        [!WS "12"!][!"$SourceClock"!] | /* Clock source */
        [!WS "12"!][!"$Prescaler"!] |   /* Timer clock prescaler configuration */
        [!WS "12"!][!"$DebugCfg"!]  /* Timer debug config */
        ),
#if (OCU_SET_CLOCK_MODE_API == STD_ON)
        /** @brief  Alternate prescaler */
        [!"$AltPrescaler"!]
#endif
    }[!IF "(num:i($comma))<(num:i($numOcuModules))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!]
[!ENDCODE!]
[!ENDIF!]
[!ENDLOOP!]

[!VAR "numOcuModules" = "$comma - 1"!]

[!CODE!]
};
[!ENDCODE!]

[!CODE!][!CR!]
/** @brief    Ftm IP configuration */
const Ftm_Ocu_Ip_ModuleConfigType Ftm_Ocu_Ip_ModuleCfgPB[!"$VS_number"!][!"$OcuPartitionIndex"!] = {
    /** @brief  Number of Ftm channels in the OCU configuration */
    (uint8)NUMBER_CHANNEL[!"$VS_number"!][!"$OcuPartitionIndex"!],
    /** @brief  Number of Ftm modules in the OCU configuration */
    (uint8)[!"num:i($numOcuModules)"!],
    /** @brief  Pointer to the array of Ftm channel enabled OCU channel configurations */
    &Ftm_Ocu_Ip_ChannelConfig_PB[!"$VS_number"!][!"$OcuPartitionIndex"!],[!CR!]
    /** @brief  Pointer to the array of Ftm module enabled OCU channel configurations */
    &Ftm_Ocu_Ip_SpecificIpConfig_PB[!"$VS_number"!][!"$OcuPartitionIndex"!][!CR!]
};
[!ENDCODE!]

[!ELSE!]
[!CODE!]
    /** @brief No Ftm channel configured */
[!ENDCODE!]
[!ENDIF!]

[!ENDMACRO!]
/*=========================================================================*/

[!IF "$max_number_ocu_cfg = 0"!]
    [!SELECT "../OcuGeneral/OcuEcucPartitionRef"!]
    [!CALL "GENERATE_CHANNELCONFIG", "OcuEcucPartitionName" = "''", "OcuPartitionId"="''"!]
    [!ENDSELECT!]
[!ENDIF!]

[!VAR "OcuPartitionId_temp" = "num:i(0)"!]
[!LOOP "../OcuGeneral/OcuEcucPartitionRef/*"!]
    [!VAR "OcuEcucPartitionRefName" = "node:value(.)"!]
    [!SELECT "../."!]   
    [!CALL "GENERATE_CHANNELCONFIG", "OcuEcucPartitionName" = "$OcuEcucPartitionRefName", "OcuPartitionId"="$OcuPartitionId_temp"!]
    [!VAR "OcuPartitionId_temp" = "num:i($OcuPartitionId_temp + 1)"!]
    [!ENDSELECT!]
[!ENDLOOP!]

/*======================================================================*/

[!ENDSELECT!]
[!ENDNOCODE!]


#define OCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!]
