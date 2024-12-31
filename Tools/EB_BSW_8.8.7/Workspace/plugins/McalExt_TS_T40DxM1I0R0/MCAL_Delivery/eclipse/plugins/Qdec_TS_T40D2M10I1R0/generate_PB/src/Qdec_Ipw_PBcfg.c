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
 =================================================================================================*/

/**
 *   @file       Qdec_Ipw[!"$VS_number"!]_PBcfg.c
 *   @version    1.0.1
 *
 *   @brief      Qdec IPW
 *   @details    AUTOSAR Qdec - configuration structures generated for IPW layer
 *
 *   @addtogroup 
 *   @{
 */

#ifdef __cplusplus
extern "C"{
#endif

 /*==================================================================================================
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 *================================================================================================*/

#include "Qdec_Ipw.h"
#include "Qdec_Ipw[!"$VS_number"!]_PBcfg.h"
#include "Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/

#define QDEC_IPW[!"$VS_number"!]_PBCFG_VENDOR_ID_C                          43
#define QDEC_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C           4
#define QDEC_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C           4
#define QDEC_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C        0
#define QDEC_IPW[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION_C                   1
#define QDEC_IPW[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION_C                   0
#define QDEC_IPW[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION_C                   1

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/

/* Check if source file and Qdec_Ipw header file are of the same vendor */
#if (QDEC_IPW[!"$VS_number"!]_PBCFG_VENDOR_ID_C != QDEC_IPW_VENDOR_ID)
#error "Qdec_Ipw[!"$VS_number"!]_PBcfg.c and Qdec_Ipw.h have different vendor IDs"
#endif
/* Check if source file and Qdec_Ipw header file are of the same Autosar version */
#if ((QDEC_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != QDEC_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (QDEC_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != QDEC_IPW_AR_RELEASE_MINOR_VERSION) || \
     (QDEC_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != QDEC_IPW_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of Qdec_Ipw[!"$VS_number"!]_PBcfg.c and Qdec_Ipw.h are different"
#endif
/* Check if source file and Qdec_Ipw header file are of the same Software Version */
#if ((QDEC_IPW[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION_C != QDEC_IPW_SW_MAJOR_VERSION) || \
     (QDEC_IPW[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION_C != QDEC_IPW_SW_MINOR_VERSION) || \
     (QDEC_IPW[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION_C != QDEC_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Qdec_Ipw[!"$VS_number"!]_PBcfg.c and Qdec_Ipw.h are different"
#endif

/* Check if source file and Qdec_Ipw[!"$VS_number"!]_PBcfg header file are of the same vendor */
#if (QDEC_IPW[!"$VS_number"!]_PBCFG_VENDOR_ID_C != QDEC_IPW[!"$VS_number"!]_PBCFG_VENDOR_ID)
#error "Qdec_Ipw[!"$VS_number"!]_PBcfg.c and Qdec_Ipw[!"$VS_number"!]_PBcfg.h have different vendor IDs"
#endif
/* Check if source file and Qdec_Ipw[!"$VS_number"!]_PBcfg header file are of the same Autosar version */
#if ((QDEC_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != QDEC_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (QDEC_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != QDEC_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (QDEC_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != QDEC_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of Qdec_Ipw[!"$VS_number"!]_PBcfg.c and Qdec_Ipw[!"$VS_number"!]_PBcfg.h are different"
#endif
/* Check if source file and Qdec_Ipw[!"$VS_number"!]_PBcfg header file are of the same Software Version */
#if ((QDEC_IPW[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION_C != QDEC_IPW[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION) || \
     (QDEC_IPW[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION_C != QDEC_IPW[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION) || \
     (QDEC_IPW[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION_C != QDEC_IPW[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Qdec_Ipw[!"$VS_number"!]_PBcfg.c and Qdec_Ipw[!"$VS_number"!]_PBcfg.h are different"
#endif

/* Check if source file and Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg header file are of the same vendor */
#if (QDEC_IPW[!"$VS_number"!]_PBCFG_VENDOR_ID_C != FTM_QDEC_IP[!"$VS_number"!]_PBCFG_VENDOR_ID)
#error "Qdec_Ipw[!"$VS_number"!]_PBcfg.c and Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg.h have different vendor IDs"
#endif
/* Check if source file and Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg header file are of the same Autosar version */
#if ((QDEC_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != FTM_QDEC_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (QDEC_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != FTM_QDEC_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (QDEC_IPW[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != FTM_QDEC_IP[!"$VS_number"!]_PBCFG_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of Qdec_Ipw[!"$VS_number"!]_PBcfg.c and Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg.h are different"
#endif
/* Check if source file and Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg header file are of the same Software Version */
#if ((QDEC_IPW[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION_C != FTM_QDEC_IP[!"$VS_number"!]_PBCFG_SW_MAJOR_VERSION) || \
     (QDEC_IPW[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION_C != FTM_QDEC_IP[!"$VS_number"!]_PBCFG_SW_MINOR_VERSION) || \
     (QDEC_IPW[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION_C != FTM_QDEC_IP[!"$VS_number"!]_PBCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Qdec_Ipw[!"$VS_number"!]_PBcfg.c and Ftm_Qdec_Ip[!"$VS_number"!]_PBcfg.h are different"
#endif

/*================================================================================================*/

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

#define QDEC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Qdec_MemMap.h"

[!VAR "TotalResourcesUsed" = "num:i(count(QdecInstanceConfig/*))"!]

static const Qdec_Ipw_MapElType Logic2HwMap[!"$VS_number"!][[!"$TotalResourcesUsed"!]U] =
{
[!VAR "Comma" = "1"!]
[!LOOP "QdecInstanceConfig/*"!]
    [!IF "text:split(QdecFtmModule,'_')[1] = 'FTM'"!]
        [!CODE!][!WS "4"!]{QDEC_IPW_IPTYPE_FTM, (uint8) [!"text:split(QdecFtmModule,'_')[2]"!]}[!IF "(num:i($Comma))<(num:i($TotalResourcesUsed))"!],[!ENDIF!][!CR!][!ENDCODE!]
    [!ENDIF!]
    [!VAR "Comma"="$Comma + 1"!]
[!ENDLOOP!]
};

/**
* @brief    Configurations of QDEC Ipw layer
*/
[!VAR "QdecEcucPartitionRefCount" = "num:i(count(as:modconf('Qdec')[1]/QdecGeneral/QdecEcucPartitionRef/*))"!]
[!IF "$QdecEcucPartitionRefCount != 0 "!]
    [!VAR "QdecEcucPartitionRefNum" = "$QdecEcucPartitionRefCount"!] 
[!ELSE!]
    [!VAR "QdecEcucPartitionRefNum" = "1"!] 
[!ENDIF!]
[!FOR "PartitionIdx" = "1" TO "$QdecEcucPartitionRefNum"!]
    [!VAR "QdecInstOnPartition" = "num:i(count(QdecInstanceConfig/*))"!]
    [!VAR "NumberOfFtmUsed" = "0"!]
    [!IF "$QdecEcucPartitionRefCount != 0 "!]
        [!VAR "CurrentPartionName" = "node:name(node:value(QdecGeneral/QdecEcucPartitionRef/*[num:i($PartitionIdx)]))"!]
        [!VAR "QdecEcucPartitionRefName" = "node:value(QdecGeneral/QdecEcucPartitionRef/*[num:i($PartitionIdx)])"!]
        [!VAR "QdecInstOnPartition"  = "num:i(count(QdecInstanceConfig/*/QdecInstanceEcucPartitionRef/*[. = $QdecEcucPartitionRefName]))"!]
        [!LOOP "QdecInstanceConfig/*"!]
            [!IF "text:split(QdecFtmModule,'_')[1] = 'FTM' and node:name(node:value(QdecInstanceEcucPartitionRef/*)) = $CurrentPartionName"!]
                [!VAR "NumberOfFtmUsed"="$NumberOfFtmUsed + 1"!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ELSE!]
        [!LOOP "QdecInstanceConfig/*"!]
            [!IF "text:split(QdecFtmModule,'_')[1] = 'FTM' "!]
                [!VAR "NumberOfFtmUsed"="$NumberOfFtmUsed + 1"!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDIF!]
const Qdec_Ipw_ConfigType Qdec_Ipw_Config[!"$VS_number"!][!IF "$QdecEcucPartitionRefCount != 0 "!]_[!"$CurrentPartionName"!][!ENDIF!][[!"num:i($NumberOfFtmUsed)"!]U] =
{
    {
        /* FTM details */
        /* Number of FTMs used by current partition */
        (uint8) [!"num:i($NumberOfFtmUsed)"!],
        /* Refferenced FTM IP config structure array */
        Ftm_Qdec_Ip_InstanceConfig[!"$VS_number"!],

        Logic2HwMap[!"$VS_number"!]
    }
};
[!ENDFOR!]

#define QDEC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Qdec_MemMap.h"

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
#endif
/** @} */
[!ENDCODE!]