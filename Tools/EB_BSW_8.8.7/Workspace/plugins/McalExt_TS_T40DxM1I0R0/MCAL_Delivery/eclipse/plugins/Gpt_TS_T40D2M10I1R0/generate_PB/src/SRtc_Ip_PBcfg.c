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
 *   @file          SRtc_Ip_PBcfg.c
 *
 *   @addtogroup    srtc_ip sRtc IPL
 *
 *   @{
 */

[!NOCODE!]
/*==================================================================================================
 *                              GENERATION MACRO DEFINTION
 *================================================================================================*/
[!// MACRO for creating the IP configuration structure(s)
[!MACRO "GENERATE_SRTC_IP_CONFIGURATION","VARIANT"="'PB'"!][!//
[!NOCODE!]

[!SELECT "./GptChannelConfigSet"!]
[!IF "count(GptSRtc/*) > '0'"!]
    [!LOOP "GptSRtc/*"!]
        [!CODE!]const Srtc_Ip_ConfigType [!"substring-before(node:value(./GptSRtcModule),'_CH')"!]_InitConfig_[!"$VARIANT"!] = [!CR!]{[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]/**< @brief sRtc clock source                   */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!][!"node:value(./GptSRtcChannelClkSrc)"!],[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]/**< @brief sRtc Clock Pin select - RTC_CLKOUT  */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]SRTC_IP_CLKOUT_DISABLED,[!CR!][!ENDCODE!]
        [!CODE!][!WS "0"!]#if (defined (SRTC_IP_ENABLE_COMPENSATION_SUPPORT) && (SRTC_IP_ENABLE_COMPENSATION_SUPPORT == STD_ON))[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]/**< @brief sRtc Compensation Interval          */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]0U,[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]/**< @brief sRtc Compensation Value             */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]0U,[!CR!][!ENDCODE!]
        [!CODE!][!WS "0"!]#endif[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]/**< @brief sRTC callback name                  */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]&Gpt_ProcessCommonInterrupt,[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]/** @brief sRTC callbackparam                   */[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!](uint8)[!"../../GptChannelConfiguration/*[as:path(node:ref(GptModuleRef)) = as:path(node:current())]/GptChannelId"!]U,[!CR!][!ENDCODE!]
        [!CODE!][!WS "4"!]/** @brief sRTC channel mode */[!CR!][!ENDCODE!]
        [!VAR "channelMode" = "../../GptChannelConfiguration/*[as:path(node:ref(GptModuleRef)) = as:path(node:current())]/GptChannelMode"!]
        [!CODE!][!WS "4"!]SRTC_IP_[!"substring-after($channelMode, '_')"!][!CR!][!ENDCODE!]
        [!CODE!]};[!CR!][!ENDCODE!]
    [!ENDLOOP!]
[!ENDIF!]
[!ENDSELECT!]
[!ENDNOCODE!]
[!ENDMACRO!][!// End of Macro GENERATE_SRTC_IP_CONFIGURATION
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
#include "SRtc_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h"
#include "Gpt_Irq.h"
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define SRTC_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                    43
#define SRTC_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C     4
#define SRTC_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C     4
#define SRTC_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C  0
#define SRTC_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C             1
#define SRTC_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C             0
#define SRTC_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C             1
/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#if (SRTC_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SRTC_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H)
    #error "SRtc_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and SRtc_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((SRTC_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SRTC_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (SRTC_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SRTC_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (SRTC_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SRTC_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) \
    )
    #error "AutoSar Version Numbers of SRtc_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and SRtc_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((SRTC_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SRTC_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (SRTC_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SRTC_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (SRTC_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SRTC_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) \
    )
    #error "Software Version Numbers of SRtc_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and SRtc_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif

#if (SRTC_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != GPT_IRQ_VENDOR_ID)
    #error "SRtc_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Gpt_Irq.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((SRTC_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != GPT_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (SRTC_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != GPT_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (SRTC_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != GPT_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of SRtc_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Gpt_Irq.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((SRTC_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != GPT_IRQ_SW_MAJOR_VERSION) || \
     (SRTC_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != GPT_IRQ_SW_MINOR_VERSION) || \
     (SRTC_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != GPT_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SRtc_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Gpt_Irq.h are different"
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

[!CALL "GENERATE_SRTC_IP_CONFIGURATION","VARIANT"="$PBCfg_Variant"!]
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
#endif/* SRTC_IP_PBCFG_C*/

[!ENDCODE!]
/** @} */
