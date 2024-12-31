[!CODE!][!//
[!AUTOSPACING!]
/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : Ftm_Srtc_Lptmr_LPit
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

/**
 *   @file          LPit_Gpt_Ip_PBcfg.c
 *
 *   @addtogroup    lpit_ip LPit IPL
 *
 *   @{
 */

 [!NOCODE!]
/*==================================================================================================
 *                              GENERATION MACRO DEFINTION
 *================================================================================================*/
[!// MACRO for creating the IP configuration structure(s)
[!MACRO "GENERATE_LPIT_GPT_IP_CONFIGURATION","VARIANT"="'PB'"!][!//
[!NOCODE!]

[!SELECT "./GptChannelConfigSet"!]
[!IF "count(GptLpit/*) > '0'"!]
    [!LOOP "GptLpit/*"!]
        [!CODE!]const Lpit_Gpt_Ip_InstanceConfigType [!"node:value(./GptLpitModule)"!]_InitConfig_[!"$VARIANT"!] = [!CR!]{[!CR!][!ENDCODE!]
        [!CODE!][!WS "0"!]#if (LPIT_GPT_IP_DOZE_MODE_SUPPORT == STD_ON)[!CR!][!ENDCODE!]
        [!CODE!][!WS "8"!]/** @brief DOZE Mode Enable Bit */[!CR!][!ENDCODE!]
        [!CODE!][!WS "8"!](boolean)[!"text:toupper(node:value(LpitDozeEnable))"!],[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#endif[!CR!][!ENDCODE!]
        [!CODE!][!WS "8"!]/** @brief LPIT Debug Mode */[!CR!][!ENDCODE!]
        [!CODE!][!WS "8"!](boolean)[!"text:toupper(node:value(LpitFreezeEnable))"!][!CR!][!ENDCODE!][!//
[!CODE!]
};[!CR!][!CR!]
[!ENDCODE!]
    [!ENDLOOP!]
[!ENDIF!]
[!ENDSELECT!]

[!SELECT "./GptChannelConfigSet"!]
[!IF "count(GptLpit/*) > '0'"!]
    [!LOOP "GptLpit/*"!]
        [!CODE!]const Lpit_Gpt_Ip_ChannelConfigType [!"node:value(./GptLpitModule)"!]_ChannelConfig_[!"$VARIANT"!][[!"num:i(count(GptLpitChannels/*))"!]U] = [!ENDCODE!]
        [!CODE!][!CR!]{[!CR!][!ENDCODE!]
        [!VAR "comma" = "num:i(count(GptLpitChannels/*))"!]
            [!LOOP "GptLpitChannels/*"!]
            [!CODE!][!WS "4"!]/** @brief [!"node:name(.)"!] */[!CR!][!ENDCODE!]
            [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!]
            [!CODE!][!WS "8"!]/** @brief Lpit Channel Id */[!CR!][!ENDCODE!]
            [!VAR "channelName" = "node:value(./GptLpitChannel)"!]
            [!VAR "chShortName" = "substring-after($channelName, substring-before($channelName,'CH_'))"!]
            [!CODE!][!WS "8"!][!"substring-after($chShortName, '_')"!]U,[!CR!][!ENDCODE!]
            [!CODE!][!WS "8"!]/** @brief Lpit callback name */[!CR!][!ENDCODE!]
            [!CODE!][!WS "8"!]&Gpt_ProcessCommonInterrupt,[!CR!][!ENDCODE!]
            [!CODE!][!WS "8"!]/** @brief Lpit callback param */[!CR!][!ENDCODE!]
            [!CODE!][!WS "8"!](uint8)[!"../../../../GptChannelConfiguration/*[as:path(node:ref(GptModuleRef)) = as:path(node:current())]/GptChannelId"!]U,[!CR!][!ENDCODE!]
            [!CODE!][!WS "8"!]#if (LPIT_GPT_IP_ENABLE_EXT_TRIGGERS == STD_ON)[!CR!][!ENDCODE!]
            [!CODE!][!WS "8"!]/* LPIT External/Internal Trigger Configuration */[!CR!][!ENDCODE!]
            [!CODE!][!WS "8"!](uint32)[!IF "node:exists(LPitTriggerChannels)"!]((uint32)[!"text:split(node:value(LPitTriggerChannels), '_')[2]"!]U << LPIT_TMR_TCTRL_TRG_SEL_SHIFT)[!ELSE!]0U[!ENDIF!] | \[!CR!][!ENDCODE!]
            [!IF "node:value(LPitExternalTrigger)"!][!//
            [!CODE!][!WS "8"!](uint32)((uint32)0U << LPIT_TMR_TCTRL_TRG_SRC_SHIFT) | \[!CR!][!ENDCODE!]
            [!ELSE!][!//
            [!CODE!][!WS "8"!](uint32)((uint32)1U << LPIT_TMR_TCTRL_TRG_SRC_SHIFT) | \[!CR!][!ENDCODE!]
            [!ENDIF!][!//
            [!IF "node:value(LPitReloadOnTrigger)"!][!//
            [!CODE!][!WS "8"!](uint32)((uint32)1U << LPIT_TMR_TCTRL_TROT_SHIFT) | \[!CR!][!ENDCODE!]
            [!ELSE!][!//
            [!CODE!][!WS "8"!](uint32)((uint32)0U << LPIT_TMR_TCTRL_TROT_SHIFT) | \[!CR!][!ENDCODE!]
            [!ENDIF!][!//
            [!IF "node:value(LPitStopOnInterrupt)"!][!//
            [!CODE!][!WS "8"!](uint32)((uint32)1U << LPIT_TMR_TCTRL_TSOI_SHIFT) | \[!CR!][!ENDCODE!]
            [!ELSE!][!//
            [!CODE!][!WS "8"!](uint32)((uint32)0U << LPIT_TMR_TCTRL_TSOI_SHIFT) | \[!CR!][!ENDCODE!]
            [!ENDIF!][!//
            [!IF "node:value(LPitStartOnTrigger)"!][!//
            [!CODE!][!WS "8"!](uint32)((uint32)1U << LPIT_TMR_TCTRL_TSOT_SHIFT),[!CR!][!ENDCODE!]
            [!ELSE!][!//
            [!CODE!][!WS "8"!](uint32)((uint32)0U << LPIT_TMR_TCTRL_TSOT_SHIFT),[!CR!][!ENDCODE!]
            [!ENDIF!][!//
            [!CODE!][!WS "8"!]#endif[!CR!][!ENDCODE!]
            [!CODE!][!WS "8"!]/** @brief Lpit channel mode */[!CR!][!ENDCODE!]
            [!VAR "channelMode" = "../../../../GptChannelConfiguration/*[as:path(node:ref(GptModuleRef)) = as:path(node:current())]/GptChannelMode"!]
            [!CODE!][!WS "8"!]LPIT_GPT_IP_[!"substring-after($channelMode, '_')"!][!CR!][!ENDCODE!]
            [!CODE!][!WS "4"!]}[!CR!][!ENDCODE!]
            [!IF "(num:i($comma))>1"!][!CODE!][!WS "4"!],[!CR!][!ENDCODE!][!VAR "comma"="$comma - 1"!][!ENDIF!]
            [!ENDLOOP!]
        [!CODE!]};[!CR!][!CR!][!ENDCODE!]
    [!ENDLOOP!]
[!ENDIF!]
[!ENDSELECT!]

[!ENDNOCODE!]
[!ENDMACRO!][!// End of Macro GENERATE_LPIT_GPT_IP_CONFIGURATION

[!ENDNOCODE!][!//

[!NOCODE!][!//
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "VS_number" = "concat('_',$postBuildVariant,'_')"!]
    [!ELSE!]
        [!VAR "VS_number" = "'_'"!]
    [!ENDIF!]
[!ENDNOCODE!][!//

#ifdef __cplusplus
extern "C"{
#endif

 /*==================================================================================================
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 *================================================================================================*/
#include "LPit_Gpt_Ip[!"$VS_number"!]PBcfg.h"
#include "Gpt_Irq.h"
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define LPIT_GPT_IP_VENDOR_ID[!"$VS_number"!]PBCFG_C                    43
#define LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION[!"$VS_number"!]PBCFG_C     4
#define LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION[!"$VS_number"!]PBCFG_C     4
#define LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION[!"$VS_number"!]PBCFG_C  0
#define LPIT_GPT_IP_SW_MAJOR_VERSION[!"$VS_number"!]PBCFG_C             1
#define LPIT_GPT_IP_SW_MINOR_VERSION[!"$VS_number"!]PBCFG_C             0
#define LPIT_GPT_IP_SW_PATCH_VERSION[!"$VS_number"!]PBCFG_C             1
/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#if (LPIT_GPT_IP_VENDOR_ID[!"$VS_number"!]PBCFG_C != LPIT_GPT_IP_VENDOR_ID[!"$VS_number"!]PBCFG_H)
    #error "LPit_Gpt_Ip[!"$VS_number"!]PBcfg.c and LPit_Gpt_Ip_Types.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION[!"$VS_number"!]PBCFG_C != LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION[!"$VS_number"!]PBCFG_H) || \
     (LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION[!"$VS_number"!]PBCFG_C != LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION[!"$VS_number"!]PBCFG_H) || \
     (LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION[!"$VS_number"!]PBCFG_C != LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION[!"$VS_number"!]PBCFG_H) \
    )
    #error "AutoSar Version Numbers of LPit_Gpt_Ip[!"$VS_number"!]PBcfg.c and LPit_Gpt_Ip_Types.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((LPIT_GPT_IP_SW_MAJOR_VERSION[!"$VS_number"!]PBCFG_C != LPIT_GPT_IP_SW_MAJOR_VERSION[!"$VS_number"!]PBCFG_H) || \
     (LPIT_GPT_IP_SW_MINOR_VERSION[!"$VS_number"!]PBCFG_C != LPIT_GPT_IP_SW_MINOR_VERSION[!"$VS_number"!]PBCFG_H) || \
     (LPIT_GPT_IP_SW_PATCH_VERSION[!"$VS_number"!]PBCFG_C != LPIT_GPT_IP_SW_PATCH_VERSION[!"$VS_number"!]PBCFG_H) \
    )
    #error "Software Version Numbers of LPit_Gpt_Ip[!"$VS_number"!]PBcfg.c and LPit_Gpt_Ip_Types.h are different"
#endif

#if (LPIT_GPT_IP_VENDOR_ID[!"$VS_number"!]PBCFG_C != GPT_IRQ_VENDOR_ID)
    #error "LPit_Gpt_Ip[!"$VS_number"!]PBcfg.c and Gpt_Irq.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION[!"$VS_number"!]PBCFG_C != GPT_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION[!"$VS_number"!]PBCFG_C != GPT_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION[!"$VS_number"!]PBCFG_C != GPT_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of LPit_Gpt_Ip[!"$VS_number"!]PBcfg.c and Gpt_Irq.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((LPIT_GPT_IP_SW_MAJOR_VERSION[!"$VS_number"!]PBCFG_C != GPT_IRQ_SW_MAJOR_VERSION) || \
     (LPIT_GPT_IP_SW_MINOR_VERSION[!"$VS_number"!]PBCFG_C != GPT_IRQ_SW_MINOR_VERSION) || \
     (LPIT_GPT_IP_SW_PATCH_VERSION[!"$VS_number"!]PBCFG_C != GPT_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of LPit_Gpt_Ip[!"$VS_number"!]PBcfg.c and Gpt_Irq.h are different"
#endif
/*================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "PBCfg_Variant" = "concat('PB_', $postBuildVariant)"!]
[!ELSE!]
    [!VAR "PBCfg_Variant" = "'PB'"!]
[!ENDIF!]

[!CALL "GENERATE_LPIT_GPT_IP_CONFIGURATION","VARIANT"="$PBCfg_Variant"!]
[!ENDNOCODE!]
#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
 *================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
 *================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
 *================================================================================================*/

#ifdef __cplusplus
}
#endif /* LPIT_GPT_IP_PBCFG_C*/

[!ENDCODE!]
/** @} */
