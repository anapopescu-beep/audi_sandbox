[!AUTOSPACING!]
[!NOCODE!]
    [!IF "var:defined('postBuildVariant')"!]
        [!VAR "VS_number" = "concat('_',$postBuildVariant)"!]
    [!ELSE!]
        [!VAR "VS_number" = "''"!]
    [!ENDIF!]
[!ENDNOCODE!]
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

#ifndef FTM_OCU_IP[!"$VS_number"!]_PBCFG_H
#define FTM_OCU_IP[!"$VS_number"!]_PBCFG_H

/**
*   @file           Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.h
*
*   @addtogroup     ocu_ip Ocu IPL
*   @brief          Ocu IP - driver configuration header file.
*   @details        
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

#include "Ftm_Ocu_Ip_Types.h"

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_OCU_IP[!"$VS_number"!]_PBCFG_VENDOR_ID                       43
#define FTM_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION        4
#define FTM_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION        4
#define FTM_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION     0
#define FTM_OCU_IP[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION                1
#define FTM_OCU_IP[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION                0
#define FTM_OCU_IP[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION                1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (FTM_OCU_IP[!"$VS_number"!]_PBCFG_VENDOR_ID != FTM_OCU_IP_TYPES_VENDOR_ID)
    #error "Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.h and Ftm_Ocu_Ip_Types.h have different vendor ids"
#endif

/* Check if  header file and Ftm_Ocu_Ip_Types.h file are of the same Autosar version */
#if ((FTM_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION != FTM_OCU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION != FTM_OCU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FTM_OCU_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION != FTM_OCU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.h and Ftm_Ocu_Ip_Types.h are different"
#endif

/* Check if header file and Ftm_Ocu_Ip_Types.h file are of the same Software version */
#if ((FTM_OCU_IP[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION != FTM_OCU_IP_TYPES_SW_MAJOR_VERSION) || \
     (FTM_OCU_IP[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION != FTM_OCU_IP_TYPES_SW_MINOR_VERSION) || \
     (FTM_OCU_IP[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION != FTM_OCU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ftm_Ocu_Ip[!"$VS_number"!]_PBcfg.h and Ftm_Ocu_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

#define OCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

[!NOCODE!]
[!VAR "OcuConfiguredPartitions" = "num:i((count(OcuGeneral/OcuEcucPartitionRef/*)))"!][!//
[!VAR "IndexPartitions" = "0"!][!//
[!IF "$OcuConfiguredPartitions > 0"!][!//
    [!LOOP "OcuGeneral/OcuEcucPartitionRef/*"!][!//
        [!VAR "concatCurrentPartition" = "concat('_P',num:i($IndexPartitions))"!]
        [!CODE!][!WS "0"!]extern const Ftm_Ocu_Ip_ModuleConfigType Ftm_Ocu_Ip_ModuleCfgPB[!"$VS_number"!][!"$concatCurrentPartition"!]; [!IF "$IndexPartitions < ($OcuConfiguredPartitions - 1)"!]\[!ENDIF!][!CR!][!ENDCODE!]
        [!VAR "IndexPartitions" = "$IndexPartitions + 1"!][!//
    [!ENDLOOP!][!//
[!ELSE!][!//
        [!CODE!][!WS "0"!]extern const Ftm_Ocu_Ip_ModuleConfigType Ftm_Ocu_Ip_ModuleCfgPB[!"$VS_number"!];[!CR!][!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!]

#define OCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* FTM_OCU_IP[!"$VS_number"!]_PBCFG_H */
