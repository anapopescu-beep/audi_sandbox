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

#ifndef MPU_IP_CFG_H_
#define MPU_IP_CFG_H_

/**
*   @file Mpu_Ip_Cfg.h
*
*   @addtogroup MPU_IP MPU IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Mpu_Ip_TypesDef.h"
#include "Mpu_Ip_Cfg_Defines.h"
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!]#include "Mpu_Ip_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!]#include "Mpu_Ip_PBcfg.h"[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_MPU_IP_CFG_VENDOR_ID                    43
#define RM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define RM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION     4
#define RM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define RM_MPU_IP_CFG_SW_MAJOR_VERSION             1
#define RM_MPU_IP_CFG_SW_MINOR_VERSION             0
#define RM_MPU_IP_CFG_SW_PATCH_VERSION             1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Mpu_Ip_TypesDef.h */
#if (RM_MPU_IP_CFG_VENDOR_ID != RM_MPU_IP_TYPES_DEF_VENDOR_ID)
    #error "Mpu_Ip_Cfg.h and Mpu_Ip_TypesDef.h have different vendor ids"
#endif
#if (( RM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_MPU_IP_TYPES_DEF_AR_RELEASE_MAJOR_VERSION) || \
     ( RM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_MPU_IP_TYPES_DEF_AR_RELEASE_MINOR_VERSION) || \
     ( RM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_MPU_IP_TYPES_DEF_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Mpu_Ip_Cfg.h and Mpu_Ip_TypesDef.h are different"
#endif
#if (( RM_MPU_IP_CFG_SW_MAJOR_VERSION != RM_MPU_IP_TYPES_DEF_SW_MAJOR_VERSION) || \
     ( RM_MPU_IP_CFG_SW_MINOR_VERSION != RM_MPU_IP_TYPES_DEF_SW_MINOR_VERSION) || \
     ( RM_MPU_IP_CFG_SW_PATCH_VERSION != RM_MPU_IP_TYPES_DEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mpu_Ip_Cfg.h and Mpu_Ip_TypesDef.h are different"
#endif

/* Checks against Mpu_Ip_Cfg_Defines.h */
#if (RM_MPU_IP_CFG_VENDOR_ID != RM_MPU_IP_CFG_DEFINES_VENDOR_ID)
    #error "Mpu_Ip_Cfg.h and Mpu_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if (( RM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_MPU_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     ( RM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_MPU_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     ( RM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_MPU_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Mpu_Ip_Cfg.h and Mpu_Ip_Cfg_Defines.h are different"
#endif
#if (( RM_MPU_IP_CFG_SW_MAJOR_VERSION != RM_MPU_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     ( RM_MPU_IP_CFG_SW_MINOR_VERSION != RM_MPU_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     ( RM_MPU_IP_CFG_SW_PATCH_VERSION != RM_MPU_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mpu_Ip_Cfg.h and Mpu_Ip_Cfg_Defines.h are different"
#endif

[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
[!CODE!][!//
/* Checks against Mpu_Ip_[!"."!]_PBcfg.h */
#if (RM_MPU_IP_CFG_VENDOR_ID != RM_MPU_IP_[!"."!]_PBCFG_VENDOR_ID)
    #error "Mpu_Ip_Cfg.h and Mpu_Ip_[!"."!]_PBcfg.h have different vendor ids"
#endif
#if (( RM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_MPU_IP_[!"."!]_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     ( RM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_MPU_IP_[!"."!]_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     ( RM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_MPU_IP_[!"."!]_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Mpu_Ip_Cfg.h and Mpu_Ip_[!"."!]_PBcfg.h are different"
#endif
#if (( RM_MPU_IP_CFG_SW_MAJOR_VERSION != RM_MPU_IP_[!"."!]_PBCFG_SW_MAJOR_VERSION) || \
     ( RM_MPU_IP_CFG_SW_MINOR_VERSION != RM_MPU_IP_[!"."!]_PBCFG_SW_MINOR_VERSION) || \
     ( RM_MPU_IP_CFG_SW_PATCH_VERSION != RM_MPU_IP_[!"."!]_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mpu_Ip_Cfg.h and Mpu_Ip_[!"."!]_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ELSE!]
[!CODE!][!//
/* Checks against Mpu_Ip_PBcfg.h */
#if (RM_MPU_IP_CFG_VENDOR_ID != RM_MPU_IP_PBCFG_VENDOR_ID)
    #error "Mpu_Ip_Cfg.h and Mpu_Ip_PBcfg.h have different vendor ids"
#endif
#if ((RM_MPU_IP_CFG_AR_RELEASE_MAJOR_VERSION    != RM_MPU_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_MPU_IP_CFG_AR_RELEASE_MINOR_VERSION    != RM_MPU_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_MPU_IP_CFG_AR_RELEASE_REVISION_VERSION != RM_MPU_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Mpu_Ip_Cfg.h and Mpu_Ip_PBcfg.h are different"
#endif
#if ((RM_MPU_IP_CFG_SW_MAJOR_VERSION != RM_MPU_IP_PBCFG_SW_MAJOR_VERSION) || \
     (RM_MPU_IP_CFG_SW_MINOR_VERSION != RM_MPU_IP_PBCFG_SW_MINOR_VERSION) || \
     (RM_MPU_IP_CFG_SW_PATCH_VERSION != RM_MPU_IP_PBCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mpu_Ip_Cfg.h and Mpu_Ip_PBcfg.h are different"
#endif
[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
/**
* @brief   Collection of all configuration structures declarations.
*/
[!NOCODE!]
[!CODE!]
#define MPU_CONFIG_EXT \[!CR!][!ENDCODE!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
[!LOOP "variant:all()"!][!//
    [!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!CODE!][!WS "4"!]MPU_CONFIG_[!"."!]_PB[!IF "$variantIndex < $variantNumber"!] \[!CR!][!ENDIF!][!ENDCODE!]
[!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS "4"!]MPU_CONFIG_PB[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MPU_IP_CFG_H_ */



