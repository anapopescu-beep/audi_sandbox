/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FTFC_FLS_IP IPV_QSPI
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
*   @file Ftfc_Fls_Ip_PBcfg.c
*
*   @addtogroup FLS
*   @{
*/

/* implements Ftfc_Fls_Ip_PBcfg.c_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ftfc_Fls_Ip_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTFC_FLS_IP_VENDOR_ID_CFG_C                          43
#define FTFC_FLS_IP_AR_RELEASE_MAJOR_VERSION_CFG_C           4
#define FTFC_FLS_IP_AR_RELEASE_MINOR_VERSION_CFG_C           4
#define FTFC_FLS_IP_AR_RELEASE_REVISION_VERSION_CFG_C        0
#define FTFC_FLS_IP_SW_MAJOR_VERSION_CFG_C                   1
#define FTFC_FLS_IP_SW_MINOR_VERSION_CFG_C                   0
#define FTFC_FLS_IP_SW_PATCH_VERSION_CFG_C                   1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Ftfc_Fls_Ip_Types header file are of the same vendor */
#if (FTFC_FLS_IP_VENDOR_ID_CFG_C != FTFC_FLS_IP_TYPES_VENDOR_ID)
    #error "Ftfc_Fls_Ip_PBCfg.c and Ftfc_Fls_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Ftfc_Fls_Ip_Types header file are of the same Autosar version */
#if ((FTFC_FLS_IP_AR_RELEASE_MAJOR_VERSION_CFG_C    != FTFC_FLS_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FTFC_FLS_IP_AR_RELEASE_MINOR_VERSION_CFG_C    != FTFC_FLS_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FTFC_FLS_IP_AR_RELEASE_REVISION_VERSION_CFG_C != FTFC_FLS_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ftfc_Fls_Ip_PBCfg.c and Ftfc_Fls_Ip_Types.h are different"
#endif
/* Check if current file and Ftfc_Fls_Ip_Types header file are of the same Software version */
#if ((FTFC_FLS_IP_SW_MAJOR_VERSION_CFG_C != FTFC_FLS_IP_TYPES_SW_MAJOR_VERSION) || \
     (FTFC_FLS_IP_SW_MINOR_VERSION_CFG_C != FTFC_FLS_IP_TYPES_SW_MINOR_VERSION) || \
     (FTFC_FLS_IP_SW_PATCH_VERSION_CFG_C != FTFC_FLS_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ftfc_Fls_Ip_PBCfg.c and Ftfc_Fls_Ip_Types.h are different"
#endif


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
[!INDENT "0"!] [!//
[!IF "node:exists(FlsConfigSet/FlsStartFlashAccessNotif) or node:exists(FlsConfigSet/FlsFinishedFlashAccessNotif)"!][!//
    #define FLS_START_SEC_CODE
    #include "Fls_MemMap.h"
    [!LOOP "text:order(text:split(normalize-space(text:join(FlsConfigSet/FlsStartFlashAccessNotif | FlsConfigSet/FlsFinishedFlashAccessNotif))))"!][!//
        /* Declaration of Fls notification function ([!"."!]())*/
        extern void [!"."!]( void );
    [!ENDLOOP!][!//
    #define FLS_STOP_SEC_CODE
    #include "Fls_MemMap.h"
[!ENDIF!][!//
[!ENDINDENT!][!//


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
[!VAR "configName" = "as:name(FlsConfigSet)"!][!//
#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

const Ftfc_ConfigType [!"$configName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_InitCfg =
{
    [!IF "node:exists(FlsConfigSet/FlsStartFlashAccessNotif)"!]&[!"FlsConfigSet/FlsStartFlashAccessNotif"!],[!ELSE!]NULL_PTR,[!ENDIF!]  /* FlsStartFlashAccessNotif */[!CR!][!//
    [!IF "node:exists(FlsConfigSet/FlsFinishedFlashAccessNotif)"!]&[!"FlsConfigSet/FlsFinishedFlashAccessNotif"!][!ELSE!]NULL_PTR[!ENDIF!]  /* FlsFinishedFlashAccessNotif */[!CR!][!//
};

#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @}*/
