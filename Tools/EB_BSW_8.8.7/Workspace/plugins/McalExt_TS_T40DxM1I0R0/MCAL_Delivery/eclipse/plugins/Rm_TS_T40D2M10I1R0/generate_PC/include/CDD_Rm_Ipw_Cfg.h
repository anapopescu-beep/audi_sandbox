/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
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

#ifndef CDD_RM_IPW_CFG_H
#define CDD_RM_IPW_CFG_H

/**
*   @file CDD_Rm_Ipw_Cfg.h
*
*   @addtogroup RM_MODULE RM Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!]#include "CDD_Rm_Ipw_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "CDD_Rm_Ipw_PBcfg.h"[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
#include "Mpu_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_IPW_CFG_VENDOR_ID                    43
#define RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION     4
#define RM_IPW_CFG_AR_RELEASE_MINOR_VERSION     4
#define RM_IPW_CFG_AR_RELEASE_REVISION_VERSION  0
#define RM_IPW_CFG_SW_MAJOR_VERSION             1
#define RM_IPW_CFG_SW_MINOR_VERSION             0
#define RM_IPW_CFG_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!][!//
/* Checks against CDD_Rm_Ipw_[!"."!]_PBcfg.h */
#if (RM_IPW_CFG_VENDOR_ID != RM_IPW_PBCFG_[!"."!]_VENDOR_ID)
    #error "CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if ((RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != RM_IPW_PBCFG_[!"."!]_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_CFG_AR_RELEASE_MINOR_VERSION    != RM_IPW_PBCFG_[!"."!]_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_CFG_AR_RELEASE_REVISION_VERSION != RM_IPW_PBCFG_[!"."!]_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_[!"."!]_PBcfg.h are different"
#endif
#if ((RM_IPW_CFG_SW_MAJOR_VERSION != RM_IPW_PBCFG_[!"."!]_SW_MAJOR_VERSION) || \
     (RM_IPW_CFG_SW_MINOR_VERSION != RM_IPW_PBCFG_[!"."!]_SW_MINOR_VERSION) || \
     (RM_IPW_CFG_SW_PATCH_VERSION != RM_IPW_PBCFG_[!"."!]_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!][!//
/* Checks against CDD_Rm_Ipw_PBcfg.h */
#if (RM_IPW_CFG_VENDOR_ID != RM_IPW_PBCFG_VENDOR_ID)
    #error "CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_PBcfg.h have different vendor ids"
#endif
#if ((RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != RM_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_CFG_AR_RELEASE_MINOR_VERSION    != RM_IPW_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_CFG_AR_RELEASE_REVISION_VERSION != RM_IPW_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_PBcfg.h are different"
#endif
#if ((RM_IPW_CFG_SW_MAJOR_VERSION != RM_IPW_PBCFG_SW_MAJOR_VERSION) || \
     (RM_IPW_CFG_SW_MINOR_VERSION != RM_IPW_PBCFG_SW_MINOR_VERSION) || \
     (RM_IPW_CFG_SW_PATCH_VERSION != RM_IPW_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Rm_Ipw_Cfg.h and CDD_Rm_Ipw_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/* Checks against Mpu_Ip_Cfg.h */
#if (RM_IPW_CFG_VENDOR_ID != RM_MPU_IP_CFG_VENDOR_ID)
    #error "CDD_Rm_Ipw_Cfg.h and Mpu_Ip_Cfg.h have different vendor ids"
#endif
#if (( RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != RM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     ( RM_IPW_CFG_AR_RELEASE_MINOR_VERSION    != RM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     ( RM_IPW_CFG_AR_RELEASE_REVISION_VERSION != RM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_Cfg.h and Mpu_Ip_Cfg.h are different"
#endif
#if (( RM_IPW_CFG_SW_MAJOR_VERSION != RM_MPU_IP_CFG_SW_MAJOR_VERSION) || \
     ( RM_IPW_CFG_SW_MINOR_VERSION != RM_MPU_IP_CFG_SW_MINOR_VERSION) || \
     ( RM_IPW_CFG_SW_PATCH_VERSION != RM_MPU_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Rm_Ipw_Cfg.h and Mpu_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief   The structure contains the hardware controller configuration type.
*/
typedef struct
{
    const Mpu_Ip_ConfigType *Rm_Ipw_pMpuConfig;
} Rm_Ipw_ConfigType;


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/**
* @brief   Collection of all configuration structures declarations.
*/
#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
        [!CODE!]RM_IPW_CONFIG_[!"."!]_PB[!CR!][!ENDCODE!]
    [!ENDLOOP!]
[!ELSE!]
    [!CODE!]RM_IPW_CONFIG_PB[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!][!//

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif /* __cplusplus */

/** @} */

#endif /* CDD_RM_IPW_CFG_H */

