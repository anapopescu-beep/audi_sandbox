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

#ifndef FTM_GPT_IP_CFG_DEFINES_H
#define FTM_GPT_IP_CFG_DEFINES_H

/**
*   @file           Ftm_Gpt_Ip_Cfg_Defines.h
*
*   @addtogroup     Ftm_Gpt_Ip Ftm_Gpt_Ip IPL
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
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g2')"!][!//
        [!CODE!][!WS "0"!]#include "S32G274A_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g3')"!][!//
        [!CODE!][!WS "0"!]#include "S32G399A_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r45')"!][!//
        [!CODE!][!WS "0"!]#include "S32R45_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r41')"!][!//
        [!CODE!][!WS "0"!]#include "S32R41_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k116')"!][!//
        [!CODE!][!WS "0"!]#include "S32K116_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k118')"!][!//
        [!CODE!][!WS "0"!]#include "S32K118_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k142') and not(contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k142w'))"!][!//
        [!CODE!][!WS "0"!]#include "S32K142_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k142w')"!][!//
        [!CODE!][!WS "0"!]#include "S32K142W_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k144') and not(contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k144w'))"!][!//
        [!CODE!][!WS "0"!]#include "S32K144_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k144w')"!][!//
        [!CODE!][!WS "0"!]#include "S32K144W_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k146')"!][!//
        [!CODE!][!WS "0"!]#include "S32K146_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k148')"!][!//
        [!CODE!][!WS "0"!]#include "S32K148_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 'saf85')"!][!//
        [!CODE!][!WS "0"!]#include "SAF85XX_FTM.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_GPT_IP_DEFINES_VENDOR_ID_CFG                    43
#define FTM_GPT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG     4
#define FTM_GPT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG     4
#define FTM_GPT_IP_DEFINES_AR_RELEASE_REVISION_VERSION_CFG  0
#define FTM_GPT_IP_DEFINES_SW_MAJOR_VERSION_CFG             1
#define FTM_GPT_IP_DEFINES_SW_MINOR_VERSION_CFG             0
#define FTM_GPT_IP_DEFINES_SW_PATCH_VERSION_CFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and StandardTypes.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FTM_GPT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_GPT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ftm_Gpt_Ip_Cfg_Defines.h and StandardTypes.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//
[!VAR "MacFtmUsed"="0"!][!//
    // Loop on all channels inside the same Configuration Set
    [!LOOP "GptHwConfiguration/*"!][!//
        [!IF "node:value(GptChannelIsUsed) = 'true' and contains(GptIsrHwId, 'FTM')"!][!//
            [!VAR "MacFtmUsed"="1"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//

/**
* @brief These defines indicate that at least one channel from each module is used in all configurations.
*/
#define FTM_GPT_IP_USED ([!IF "$MacFtmUsed=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/*================================================================================================*/

/**
* @brief This define is used to select between interrupt on each channel and source interrupt
*        on entire module sources hardware implementations.
*
*/
#define FTM_GPT_IP_MODULE_SINGLE_INTERRUPT [!IF "ecu:get('Gpt.GptConfig.Gpt_FTM_ModuleSingleInterrupt')='STD_ON'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*================================================================================================*/
/**
* @brief    FTN_GPT_IP_SET_CLOCK_MODE switch
* @details  Enable/disable API for Dual Mode support.
*/
#define FTM_GPT_IP_SET_CLOCK_MODE           ([!IF "GptAutosarExt/GptEnableDualClockMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*================================================================================================*/
/**
*
* @brief IRQ Defines for each channel used
*/
[!IF "ecu:get('Gpt.GptConfig.Gpt_FTM_ModuleSingleInterrupt')='STD_ON'"!][!//
[!NOCODE!][!//
[!VAR "AlreadyParsedModule"!][!ENDVAR!][!//
[!LOOP "GptHwConfiguration/*"!][!//
    [!IF "(GptChannelIsUsed = 'true') and (GptIsrEnable = 'true')"!][!//
        [!IF "contains(GptIsrHwId,"FTM")"!][!//
            [!IF "contains($AlreadyParsedModule, concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2])) = false()"!][!//
[!CODE!][!//
                    [!VAR "ModuleUsed"="concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2])"!][!//
#define [!"$ModuleUsed"!]_ISR_USED
[!ENDCODE!][!//
                [!VAR "AlreadyParsedModule"="concat($AlreadyParsedModule,text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2],'|')"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDIF!]//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!NOCODE!][!//
[!VAR "AlreadyParsedModule"!][!ENDVAR!][!//
[!LOOP "GptHwConfiguration/*"!][!//
    [!IF "(GptChannelIsUsed = 'true')"!][!//
        [!IF "contains(GptIsrHwId,"FTM")"!][!//
            [!IF "contains($AlreadyParsedModule, concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2])) = false()"!][!//
                [!VAR "ModuleUsed"="concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2])"!][!//
[!CODE!]
#ifndef [!"$ModuleUsed"!]_USED
    #define [!"$ModuleUsed"!]_USED
#else
    #error "[!"$ModuleUsed"!] instance cannot be used by GPT. Instance locked by another driver!"
#endif
[!ENDCODE!][!//
                [!VAR "AlreadyParsedModule"="concat($AlreadyParsedModule,text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2],'|')"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDIF!]//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!ELSE!]
[!FOR "Instance" = "0" TO "num:i(ecu:list('Gpt.Num_Ftm_Hw_Modules')) - 1"!][!//
    /* Channel per instance*/
    [!FOR "ChannelIdx" = "0" TO "floor(number(8) div 2)"!][!//
        [!VAR "GptChannelIsUsed" = "'false'"!][!//
        [!LOOP "GptHwConfiguration/*"!][!//
            [!IF "GptIsrEnable = 'true' and contains(GptIsrHwId, concat('FTM_',$Instance)) and (contains(GptIsrHwId, concat('CH_',num:i($ChannelIdx)*2)) or contains(GptIsrHwId, concat('CH_',num:i($ChannelIdx)*2 + 1)))"!][!//
                [!VAR "GptChannelIsUsed" = "'true'"!][!//
                [!BREAK!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        /* Generate ISR when check in GptHwConfiguration*/
        [!IF "$GptChannelIsUsed = 'true'"!][!//
[!CODE!]
#define FTM_[!"$Instance"!]_CH_[!"num:i($ChannelIdx*2)"!]_CH_[!"num:i($ChannelIdx*2+1)"!]_ISR_USED
[!ENDCODE!][!//
[!CODE!]
#ifndef FTM_[!"$Instance"!]_CH_[!"num:i($ChannelIdx*2)"!]_USED
    #define FTM_[!"$Instance"!]_CH_[!"num:i($ChannelIdx*2)"!]_USED
#else
    #error "FTM_[!"$Instance"!]_CH_[!"num:i($ChannelIdx*2)"!] cannot be used by GPT. Instance locked by another driver!"
#endif
[!ENDCODE!][!//
[!CODE!]
#ifndef FTM_[!"$Instance"!]_CH_[!"num:i($ChannelIdx*2+1)"!]_USED
    #define FTM_[!"$Instance"!]_CH_[!"num:i($ChannelIdx*2+1)"!]_USED
#else
    #error "FTM_[!"$Instance"!]_CH_[!"num:i($ChannelIdx*2+1)"!] cannot be used by GPT. Instance locked by another driver!"
#endif
[!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!//
[!ENDFOR!][!//
[!ENDIF!]
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

#endif  /* FTM_GPT_IP_CFG_DEFINES_H */
