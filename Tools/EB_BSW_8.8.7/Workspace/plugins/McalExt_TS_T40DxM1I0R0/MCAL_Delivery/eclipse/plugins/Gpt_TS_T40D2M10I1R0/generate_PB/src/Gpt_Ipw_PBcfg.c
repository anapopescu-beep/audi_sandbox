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
*   @file         Gpt_Ipw_PBcfg.c
*
*   @internal
*   @addtogroup   gpt gpt_ipw
*
*   @{
*/
/*==================================================================================================
 *                              GENERATION MACRO DEFINTION
 *================================================================================================*/
[!INCLUDE "Gpt_Ipw_PluginMacros.m"!]

[!NOCODE!][!//
[!VAR "GptConfiguredPartitions" = "num:i((count(GptDriverConfiguration/GptEcucPartitionRef/*)))"!][!//
[!VAR "GptEcucPartitionRefCount" = "num:i(count(as:modconf('Gpt')[1]/GptDriverConfiguration/GptEcucPartitionRef/*))"!]
[!IF "$GptEcucPartitionRefCount != 0 "!]
    [!VAR "GptEcucPartitionRefNum" = "$GptEcucPartitionRefCount"!]
[!ELSE!]
    [!VAR "GptEcucPartitionRefNum" = "1"!]
[!ENDIF!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "PBCfg_Variant" = "concat('PB_', $postBuildVariant)"!]
[!ELSE!]
    [!VAR "PBCfg_Variant" = "'PB'"!]
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
#include "Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h"
#include "SRtc_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h"
#include "Ftm_Gpt_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h"
#include "Lptmr_Gpt_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h"
#include "LPit_Gpt_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define GPT_IPW_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                    43
#define GPT_IPW_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C     4
#define GPT_IPW_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C     4
#define GPT_IPW_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C  0
#define GPT_IPW_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C             1
#define GPT_IPW_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C             0
#define GPT_IPW_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C             1

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#if (GPT_IPW_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H != GPT_IPW_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C)
    #error "Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H != GPT_IPW_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H != GPT_IPW_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H != GPT_IPW_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H != GPT_IPW_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C) || \
     (GPT_IPW_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H != GPT_IPW_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C) || \
     (GPT_IPW_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H != GPT_IPW_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C) \
    )
    #error "Software Version Numbers of Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h and Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c are different"
#endif

#if (GPT_IPW_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != LPIT_GPT_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H)
    #error "Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and LPit_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and LPit_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != LPIT_GPT_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (GPT_IPW_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != LPIT_GPT_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (GPT_IPW_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != LPIT_GPT_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) \
    )
    #error "Software Version Numbers of Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and LPit_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif

#if (GPT_IPW_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != LPTMR_GPT_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H)
    #error "Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Lptmr_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != LPTMR_GPT_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Lptmr_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != LPTMR_GPT_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (GPT_IPW_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != LPTMR_GPT_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (GPT_IPW_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != LPTMR_GPT_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) \
    )
    #error "Software Version Numbers of Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Lptmr_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif

#if (GPT_IPW_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SRTC_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H)
    #error "Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and SRtc_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SRTC_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SRTC_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SRTC_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and SRtc_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SRTC_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (GPT_IPW_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SRTC_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (GPT_IPW_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != SRTC_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) \
    )
    #error "Software Version Numbers of Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and SRtc_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif

#if (GPT_IPW_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != FTM_GPT_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H)
    #error "Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ftm_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != FTM_GPT_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != FTM_GPT_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ftm_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != FTM_GPT_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (GPT_IPW_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != FTM_GPT_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) || \
     (GPT_IPW_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != FTM_GPT_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_H) \
    )
    #error "Software Version Numbers of Gpt_Ipw_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Ftm_Gpt_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif
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
 *                                       LOCAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/

 /*==================================================================================================
 *                                       GLOBAL VARIABLES
 *================================================================================================*/
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

[!NOCODE!][!//
/*instance*/
[!FOR "PartitionIdx" = "1" TO "$GptEcucPartitionRefNum"!]
    [!IF "$GptEcucPartitionRefCount != 0 "!]
        [!VAR "PartitionIndex" = "node:name(node:value(GptDriverConfiguration/GptEcucPartitionRef/*[num:i($PartitionIdx)]))"!]
        [!VAR "GptEcucPartitionRefName" = "node:value(GptDriverConfiguration/GptEcucPartitionRef/*[num:i($PartitionIdx)])"!]
    [!ENDIF!]
    [!SELECT "GptChannelConfigSet"!][!//
        [!CALL "GPT_VARIABLES"!]
        [!CODE!]Gpt_Ipw_HwInstanceConfigType Gpt_Ipw_HwInstanceConfig_[!"$PBCfg_Variant"!][!IF "$GptEcucPartitionRefCount != 0 "!]_P_[!"$PartitionIndex"!][!ENDIF!][[!"num:i($OutNumInstancesInPartition)"!]U]=[!CR!]{[!CR!][!ENDCODE!]
            /*FTM MODULE*/
            [!IF "$OutNumGptChannelsUsingFtm > 0"!]
                [!FOR "Instance" = "0" TO "num:i(ecu:list('Gpt.Num_Ftm_Hw_Modules')) - 1"!]
                    [!IF "$GptEcucPartitionRefCount = 0 and node:exists(GptFtm/*/GptFtmModule[contains(., num:i($Instance))])"!][!//
                [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!][!//
                        [!CODE!][!WS "8"!]/** @brief IP type  */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]GPT_FTM_MODULE,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!][!"$Instance"!]U,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance pointer */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]{[!CR!][!ENDCODE!]
                        [!CODE!][!WS "12"!]&FTM_[!"$Instance"!]_InitConfig_[!"$PBCfg_Variant"!],[!CR!][!ENDCODE!]
                        [!CODE!][!WS "12"!]NULL_PTR[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]}[!CR!][!ENDCODE!][!//
                [!CODE!][!WS "4"!]}[!CR!][!ENDCODE!]
                        [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!][!WS "4"!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                    [!ELSE!]
                    [!IF "node:exists(GptFtm/*/GptFtmModule[contains(., concat('FTM_',$Instance))]) and
                    (node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(node:refs(GptModuleRef)/../../GptFtmModule = concat('FTM_',$Instance)) and (node:value(./GptChannelEcucPartitionRef/*[1]) = $GptEcucPartitionRefName)]))"!]
                [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!][!//
                        [!CODE!][!WS "8"!]/** @brief IP type  */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]GPT_FTM_MODULE,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!][!"$Instance"!]U,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance pointer */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]{[!CR!][!ENDCODE!]
                        [!CODE!][!WS "12"!]&FTM_[!"$Instance"!]_InitConfig_[!"$PBCfg_Variant"!],[!CR!][!ENDCODE!]
                        [!CODE!][!WS "12"!]NULL_PTR[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]}[!CR!][!ENDCODE!]
                [!CODE!][!WS "4"!]}[!CR!][!ENDCODE!][!//
                        [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!][!WS "4"!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                    [!ENDIF!]
                    [!ENDIF!]
                [!ENDFOR!]
            [!ENDIF!]
            /*SRTC MODULE*/
            [!IF "$OutNumGptChannelsUsingSRtc > 0"!]
                [!VAR "Instance" = "0"!][!//
                    [!IF "$GptEcucPartitionRefCount = 0"!][!//
                [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!][!//
                        [!CODE!][!WS "8"!]/** @brief IP type  */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]GPT_SRTC_MODULE,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!][!"num:i($Instance)"!]U,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance pointer */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]{[!CR!][!ENDCODE!]
                        [!CODE!][!WS "12"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "12"!]NULL_PTR[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]}[!CR!][!ENDCODE!][!//
                [!CODE!][!WS "4"!]}[!CR!][!ENDCODE!]
                        [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!][!WS "4"!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                    [!ELSE!]
                [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*/GptChannelEcucPartitionRef/*[1][node:value(.) = $GptEcucPartitionRefName])"!]
                [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!][!//
                        [!CODE!][!WS "8"!]/** @brief IP type  */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]GPT_SRTC_MODULE,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!][!"num:i($Instance)"!]U,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance pointer */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]{[!CR!][!ENDCODE!]
                        [!CODE!][!WS "12"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "12"!]NULL_PTR[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]}[!CR!][!ENDCODE!]
                [!CODE!][!WS "4"!]}[!CR!][!ENDCODE!][!//
                        [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!][!WS "4"!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                    [!ENDIF!]
                    [!ENDIF!]
            [!ENDIF!]
            
            /* LPtimer MODULE*/
            [!IF "$OutNumGptChannelsUsingLptmr > 0"!]
                [!VAR "Instance" = "0"!][!//
                    [!IF "$GptEcucPartitionRefCount = 0"!][!//
                [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!][!//
                        [!CODE!][!WS "8"!]/** @brief IP type  */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]GPT_LPTMR_MODULE,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!][!"num:i($Instance)"!]U,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance pointer */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]{[!CR!][!ENDCODE!]
                        [!CODE!][!WS "12"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "12"!]NULL_PTR[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]}[!CR!][!ENDCODE!][!//
                [!CODE!][!WS "4"!]}[!CR!][!ENDCODE!]
                        [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!][!WS "4"!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                    [!ELSE!]
                [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*/GptChannelEcucPartitionRef/*[1][node:value(.) = $GptEcucPartitionRefName])"!]
                [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!][!//
                        [!CODE!][!WS "8"!]/** @brief IP type  */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]GPT_LPTMR_MODULE,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!][!"num:i($Instance)"!]U,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance pointer */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]{[!CR!][!ENDCODE!]
                        [!CODE!][!WS "12"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "12"!]NULL_PTR[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]}[!CR!][!ENDCODE!]
                [!CODE!][!WS "4"!]}[!CR!][!ENDCODE!][!//
                        [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!][!WS "4"!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                    [!ENDIF!]
                    [!ENDIF!]
            [!ENDIF!]
            /* LPIT MODULE */
            [!IF "$OutNumGptChannelsUsingLPit > 0"!]
                [!FOR "Instance" = "0" TO "num:i(ecu:list('Gpt.Num_Lpit_Hw_Modules')) - 1"!]
                    [!IF "$GptEcucPartitionRefCount = 0 and node:exists(GptLpit/*/GptLpitModule[contains(., num:i($Instance))])"!]
            [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!][!//
                        [!CODE!][!WS "8"!]/** @brief IP type  */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]GPT_LPIT_MODULE,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!][!"$Instance"!]U,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance pointer */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]{[!CR!][!ENDCODE!]
                        [!CODE!][!WS "12"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "12"!]&LPIT_[!"$Instance"!]_InitConfig_[!"$PBCfg_Variant"!][!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]}[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "4"!]}[!CR!][!ENDCODE!]
                        [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                    [!ELSE!]
                    [!IF "node:exists(GptLpit/*/GptLpitModule[contains(., concat('LPIT_',$Instance))]) and 
                         (node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(node:refs(GptModuleRef)/../../GptLPiModule = concat('LPIT_',$Instance)) and (node:value(./GptChannelEcucPartitionRef/*[1]) = $GptEcucPartitionRefName)]))"!][!//
            [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!][!//
                        [!CODE!][!WS "8"!]/** @brief IP type  */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]GPT_LPIT_MODULE,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!][!"$Instance"!]U,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]/** @brief IP instance pointer */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]{[!CR!][!ENDCODE!]
                        [!CODE!][!WS "12"!]NULL_PTR,[!CR!][!ENDCODE!]
                        [!CODE!][!WS "12"!]&LPIT_[!"$Instance"!]_InitConfig_[!"$PBCfg_Variant"!][!CR!][!ENDCODE!]
                        [!CODE!][!WS "8"!]}[!CR!][!ENDCODE!][!//
            [!CODE!][!WS "4"!]}[!CR!][!ENDCODE!][!//
                        [!IF "num:i($OutNumInstancesInPartition) > 1"!][!CODE!],[!CR!][!ENDCODE!][!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition - 1"!][!ENDIF!]
                    [!ENDIF!]
                    [!ENDIF!]
                [!ENDFOR!]
            [!ENDIF!]            
        [!CODE!]};[!CR!][!CR!][!ENDCODE!]
    [!ENDSELECT!][!//
[!ENDFOR!]
[!ENDNOCODE!][!//

/*channels*/
 [!FOR "PartitionIdx" = "1" TO "$GptEcucPartitionRefNum"!]
    [!IF "$GptEcucPartitionRefCount != 0 "!]
        [!VAR "PartitionIndex" = "node:name(node:value(GptDriverConfiguration/GptEcucPartitionRef/*[num:i($PartitionIdx)]))"!]
        [!VAR "GptEcucPartitionRefName" = "node:value(GptDriverConfiguration/GptEcucPartitionRef/*[num:i($PartitionIdx)])"!]
    [!ENDIF!]
    [!SELECT "GptChannelConfigSet"!][!//
        [!CALL "GPT_VARIABLES"!]
        [!IF "num:i($OutNumChannelInPartition)!=0"!]
            [!CODE!]/** [!CR!][!ENDCODE!]
            [!CODE!] * @brief   Gpt channels IP related configuration array[!CR!][!ENDCODE!]
            [!CODE!] */[!CR!][!ENDCODE!]
            [!CODE!]Gpt_Ipw_HwChannelConfigType Gpt_Ipw_ChannelConfig_[!"$PBCfg_Variant"!][!IF "$GptEcucPartitionRefCount != 0 "!]_P_[!"$PartitionIndex"!][!ENDIF!][[!"num:i($OutNumChannelInPartition)"!]U] =[!CR!]{[!CR!][!ENDCODE!]
            [!VAR "comma" = "1"!]
                [!LOOP "GptChannelConfiguration/*"!]
                    [!IF "(($GptEcucPartitionRefCount = 0) or (node:value(./GptChannelEcucPartitionRef/*[1]) = $GptEcucPartitionRefName))"!]
                        [!CODE!][!WS "4"!]/** @brief [!"@name"!] */[!CR!][!ENDCODE!]
                        [!CODE!][!WS "4"!]{[!CR!][!ENDCODE!]
                            [!IF "contains(GptHwIp,'FTM')"!]
                                [!CODE!][!WS "8"!]/** @brief IP type  */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]GPT_FTM_MODULE,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]/** @brief IP instance */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!][!"substring-after(node:value(node:ref(./GptModuleRef)/../../GptFtmModule), '_')"!]U,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]/** @brief IP channel */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!][!"substring-after(substring-after((node:ref(./GptModuleRef)/GptFtmChannel), substring-before(node:value(node:ref(./GptModuleRef)/GptFtmChannel),'CH_')),'_')"!]U,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]/** @brief IP instance config pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]{[!CR!][!ENDCODE!]
                                [!CODE!][!WS "12"!]&[!"node:value(node:ref(./GptModuleRef)/../../GptFtmModule)"!]_ChannelConfig_[!"$PBCfg_Variant"!][[!"node:ref(./GptModuleRef)/@index"!]U],[!CR!][!ENDCODE!]
                                [!CODE!][!WS "12"!]NULL_PTR,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "12"!]NULL_PTR,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "12"!]NULL_PTR[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]}[!CR!][!ENDCODE!]
                            [!ELSEIF "contains(GptHwIp,'SRTC')"!]
                                [!CODE!][!WS "8"!]/** @brief IP type  */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]GPT_SRTC_MODULE,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]/** @brief IP instance */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]0U,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]/** @brief IP channel */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]0U,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]/** @brief IP instance config pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]{[!CR!][!ENDCODE!]
                                [!CODE!][!WS "12"!]NULL_PTR,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "12"!]&[!"substring-before(node:value(node:ref(./GptModuleRef)/GptSRtcModule),'_CH')"!]_InitConfig_[!"$PBCfg_Variant"!],[!CR!][!ENDCODE!]
                                [!CODE!][!WS "12"!]NULL_PTR,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "12"!]NULL_PTR[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]}[!CR!][!ENDCODE!]
                            [!ELSEIF "contains(GptHwIp,'LPTMR')"!]
                                [!CODE!][!WS "8"!]/** @brief IP type  */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]GPT_LPTMR_MODULE,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]/** @brief IP instance */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]0U,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]/** @brief IP channel */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]0U,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]/** @brief IP instance config pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]{[!CR!][!ENDCODE!]
                                [!CODE!][!WS "12"!]NULL_PTR,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "12"!]NULL_PTR,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "12"!]&[!"substring-before(node:value(node:ref(./GptModuleRef)/GptLptmrModule),'_CH')"!]_InitConfig_[!"$PBCfg_Variant"!],[!CR!][!ENDCODE!]
                                [!CODE!][!WS "12"!]NULL_PTR[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]}[!CR!][!ENDCODE!]
                            [!ELSEIF "contains(GptHwIp,'LPIT')"!]
                                [!CODE!][!WS "8"!]/** @brief IP type  */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]GPT_LPIT_MODULE,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]/** @brief IP instance */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!][!"substring-after(node:value(node:ref(./GptModuleRef)/../../GptLpitModule), '_')"!]U,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]/** @brief IP channel */[!CR!][!ENDCODE!]
                                [!VAR "chShortName" = "substring-after((node:ref(./GptModuleRef)/GptLpitChannel), substring-before(node:value(node:ref(./GptModuleRef)/GptLpitChannel),'CH_'))"!]
                                [!CODE!][!WS "8"!][!"substring-after($chShortName, '_')"!]U,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]/** @brief IP channel pointer */[!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]{[!CR!][!ENDCODE!]
                                [!CODE!][!WS "12"!]NULL_PTR,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "12"!]NULL_PTR,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "12"!]NULL_PTR,[!CR!][!ENDCODE!]
                                [!CODE!][!WS "12"!]&[!"node:value(node:ref(./GptModuleRef)/../../GptLpitModule)"!]_ChannelConfig_[!"$PBCfg_Variant"!][[!"node:ref(./GptModuleRef)/@index"!]U][!CR!][!ENDCODE!]
                                [!CODE!][!WS "8"!]}[!CR!][!ENDCODE!]
                            [!ENDIF!]
                        [!CODE!][!WS "4"!]}[!CR!][!ENDCODE!]
                        [!IF "(num:i($comma))<(num:i($OutNumChannelInPartition))"!]
                            [!CODE!][!WS "4"!],[!CR!][!ENDCODE!]
                        [!ENDIF!]
                        [!VAR "comma"="$comma + 1"!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!CODE!][!CR!]};[!CR!][!CR!][!ENDCODE!]
        [!ENDIF!]
    [!ENDSELECT!]
[!ENDFOR!]
#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
 *================================================================================================*/


/*==================================================================================================
 *                                       LOCAL FUNCTIONS
 *================================================================================================*/


/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
 *================================================================================================*/

#ifdef __cplusplus
}
#endif/*GPT_IPW_PBCFG_C*/

[!ENDCODE!]
/** @} */
