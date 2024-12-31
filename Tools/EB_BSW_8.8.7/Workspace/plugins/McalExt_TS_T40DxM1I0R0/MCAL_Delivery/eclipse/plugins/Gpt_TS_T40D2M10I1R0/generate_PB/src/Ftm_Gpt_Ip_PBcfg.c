[!CODE!][!//
[!AUTOSPACING!]
/*==================================================================================================
* Project :             RTD AUTOSAR 4.4
* Platform :            CORTEXM
* Peripheral :          Ftm_Srtc_Lptmr_LPit
* Dependencies :        none
*
* Autosar Version :     4.4.0
* Autosar Revision :    ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version :          1.0.1
* Build Version :       S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224
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
 *   @file          Ftm_Gpt_Ip_PBcfg.c
 *
 *   @addtogroup    Ftm_Gpt_Ip Ftm_Gpt_Ip IPL
 *
 *   @{
 */

[!NOCODE!]
/*==================================================================================================
 *                              GENERATION MACRO DEFINTION
 *================================================================================================*/

[!// MACRO for creating the IP configuration structure(s)
[!MACRO "GENERATE_FTM_GPT_IP_CONFIGURATION","VARIANT"="'PB'"!][!//
[!NOCODE!]

[!SELECT "./GptChannelConfigSet"!]
[!IF "count(GptFtm/*) > '0'"!]
    [!LOOP "GptFtm/*"!]
[!CODE!]const Ftm_Gpt_Ip_InstanceConfigType [!"node:value(./GptFtmModule)"!]_InitConfig_[!"$VARIANT"!] = [!CR!]{[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]/** @brief Freeze bit */[!CR!][!ENDCODE!]
        [!IF "FtmFreezeEnable"!][!//
            [!CODE!][!WS"4"!](boolean)TRUE, /**< @brief Freeze Enable */[!CR!][!ENDCODE!]
        [!ELSE!][!//
            [!CODE!][!WS"4"!](boolean)(FALSE), /**< @brief Freeze Disable */[!CR!][!ENDCODE!]
        [!ENDIF!][!//
        [!CODE!][!WS "4"!]/** @brief FTM clock source  */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!][!"node:value(./GptFtmChannelClkSrc)"!],[!CR!][!ENDCODE!]
        [!CODE!]#if (FTM_GPT_IP_SET_CLOCK_MODE == STD_ON)[!CR!][!ENDCODE!][!//
        [!FOR "macIndex" = "0" TO "7"!][!//
        [!VAR "macTemp" = "bit:shr(num:i(number(./GptFtmAlternatePrescaler)),num:i($macIndex))"!][!//
        [!IF "$macTemp < 2"!]
        [!CODE!][!WS "4"!]/** @brief GptFtmAlternatePrescaler Value */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!][!"num:i(number($macIndex))"!]U, /*Value PS bit:[!"num:i(number($macIndex))"!] */[!CR!][!ENDCODE!][!//
        [!BREAK!][!//
        [!ENDIF!][!//
        [!ENDFOR!][!//
        [!CODE!]#endif[!CR!][!ENDCODE!][!//
        [!FOR "macIndex" = "0" TO "7"!][!//
        [!VAR "macTemp" = "bit:shr(num:i(number(./GptFtmPrescaler)),num:i($macIndex))"!][!//
        [!IF "$macTemp < 2"!]
        [!CODE!][!WS "4"!]/** @brief GptFtmPrescaler Value */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!][!"num:i(number($macIndex))"!]U, /*Value PS bit:[!"num:i(number($macIndex))"!] */[!CR!][!ENDCODE!][!//
        [!BREAK!][!//
        [!ENDIF!][!//
        [!ENDFOR!][!//
        [!CODE!][!WS "4"!]/** @brief GptFtmCountingMode */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!][!"node:value(./GptFtmCountingMode)"!][!CR!][!ENDCODE!]
[!CODE!]
};[!CR!][!CR!]
[!ENDCODE!]
    [!ENDLOOP!]
[!ENDIF!]
[!ENDSELECT!]

[!SELECT "./GptChannelConfigSet"!]
[!IF "count(GptFtm/*) > '0'"!]
    [!LOOP "GptFtm/*"!]
        [!CODE!]const Ftm_Gpt_Ip_ChannelConfigType [!"node:value(./GptFtmModule)"!]_ChannelConfig_[!"$VARIANT"!][[!"num:i(count(GptFtmChannels/*))"!]U] = [!ENDCODE!]
        [!CODE!][!CR!]{[!CR!][!ENDCODE!]
        [!VAR "comma" = "num:i(count(GptFtmChannels/*))"!]
            [!LOOP "GptFtmChannels/*"!]
            [!CODE!][!WS "4"!]/** @brief [!"node:name(.)"!] */[!CR!][!ENDCODE!]
            [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!]
            [!CODE!][!WS "8"!]/** @brief Ftm Channel Id */[!CR!][!ENDCODE!]
            [!CODE!][!WS "8"!][!"substring-after(substring-after(node:value(./GptFtmChannel), substring-before(node:value(./GptFtmChannel),'CH_')),'_')"!]U,[!CR!][!ENDCODE!]
            [!CODE!][!WS "8"!]/** @brief Ftm callback name */[!CR!][!ENDCODE!]
            [!CODE!][!WS "8"!]&Gpt_ProcessCommonInterrupt,[!CR!][!ENDCODE!]
            [!CODE!][!WS "8"!]/** @brief Ftm callbackparam */[!CR!][!ENDCODE!]
            [!CODE!][!WS "8"!](uint8)[!"../../../../GptChannelConfiguration/*[as:path(node:ref(GptModuleRef)) = as:path(node:current())]/GptChannelId"!]U,[!CR!][!ENDCODE!]
            [!CODE!][!WS "8"!]/** @brief Ftm channel mode */[!CR!][!ENDCODE!]
            [!VAR "channelMode" = "../../../../GptChannelConfiguration/*[as:path(node:ref(GptModuleRef)) = as:path(node:current())]/GptChannelMode"!]
            [!CODE!][!WS "8"!]FTM_GPT_IP_[!"substring-after($channelMode, '_')"!][!CR!][!ENDCODE!]
            [!CODE!][!WS "4"!]}[!CR!][!ENDCODE!]
            [!IF "(num:i($comma))>1"!][!CODE!][!WS "4"!],[!CR!][!ENDCODE!][!VAR "comma"="$comma - 1"!][!ENDIF!]
            [!ENDLOOP!]
        [!CODE!]};[!CR!][!CR!][!ENDCODE!]
    [!ENDLOOP!]
[!ENDIF!]
[!ENDSELECT!]


[!ENDNOCODE!]
[!ENDMACRO!][!// End of Macro GENERATE_FTM_GPT_IP_CONFIGURATION

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
#include "Ftm_Gpt_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h"
#include "Gpt_Irq.h"
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define FTM_GPT_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                    43
#define FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C     4
#define FTM_GPT_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C     4
#define FTM_GPT_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C  0
#define FTM_GPT_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C             1
#define FTM_GPT_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C             0
#define FTM_GPT_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C             1
/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#if (FTM_GPT_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != FTM_GPT_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H)
    #error "Ftm_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ftm_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (FTM_GPT_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != FTM_GPT_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (FTM_GPT_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != FTM_GPT_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Ftm_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ftm_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((FTM_GPT_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != FTM_GPT_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (FTM_GPT_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != FTM_GPT_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (FTM_GPT_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != FTM_GPT_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) \
    )
    #error "Software Version Numbers of Ftm_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ftm_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif

#if (FTM_GPT_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != GPT_IRQ_VENDOR_ID)
    #error "Ftm_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Gpt_Irq.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != GPT_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_GPT_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != GPT_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (FTM_GPT_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != GPT_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ftm_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Gpt_Irq.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((FTM_GPT_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != GPT_IRQ_SW_MAJOR_VERSION) || \
     (FTM_GPT_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != GPT_IRQ_SW_MINOR_VERSION) || \
     (FTM_GPT_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != GPT_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ftm_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Gpt_Irq.h are different"
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

[!CALL "GENERATE_FTM_GPT_IP_CONFIGURATION","VARIANT"="$PBCfg_Variant"!]
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
#endif

[!ENDCODE!]
/** @} */
