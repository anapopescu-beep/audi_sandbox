[!CODE!][!//
[!AUTOSPACING!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Ftm Lpit Lptmr Port_Ci LpCmp
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

#ifndef LPTMR_ICU_IP_CFG_H
#define LPTMR_ICU_IP_CFG_H

/**
 *   @file    Lptmr_Icu_Ip_Cfg.h
 *   @version 1.0.1
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the ICU module.
 *   @details Contains the information that will be exported by the module, as requested by AUTOSAR.
 *
 *   @addtogroup lptmr_icu_ip LPTMR IPL
 *   @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* Include all variants header files. */
#include "StandardTypes.h"
[!NOCODE!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!LOOP "variant:all()"!][!//
        [!CODE!][!WS "0"!]#include "Lptmr_Icu_Ip_[!"."!]_PBcfg.h"[!CR!][!ENDCODE!][!//
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS "0"!]#include "Lptmr_Icu_Ip_PBcfg.h"[!CR!][!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPTMR_ICU_IP_CFG_VENDOR_ID                    43
#define LPTMR_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define LPTMR_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION     4
#define LPTMR_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define LPTMR_ICU_IP_CFG_SW_MAJOR_VERSION             1
#define LPTMR_ICU_IP_CFG_SW_MINOR_VERSION             0
#define LPTMR_ICU_IP_CFG_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and StandardTypes.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((LPTMR_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (LPTMR_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Lptmr_Icu_Ip_Cfg.h and StandardTypes.h are different"
    #endif
#endif

[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
/* Check if source file and ICU configuration header file are of the same vendor */
#if (LPTMR_ICU_IP_[!"."!]_PBCFG_VENDOR_ID != LPTMR_ICU_IP_CFG_VENDOR_ID)
    #error "Lptmr_Icu_Ip_[!"."!]_PBcfg.h and Lptmr_Icu_Ip_Cfg.h have different vendor IDs"
#endif
    /* Check if header file and Icu configuration header file are of the same Autosar version */
#if ((LPTMR_ICU_IP_[!"."!]_PBCFG_AR_RELEASE_MAJOR_VERSION != LPTMR_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LPTMR_ICU_IP_[!"."!]_PBCFG_AR_RELEASE_MINOR_VERSION != LPTMR_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LPTMR_ICU_IP_[!"."!]_PBCFG_AR_RELEASE_REVISION_VERSION != LPTMR_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Lptmr_Icu_Ip_[!"."!]_PBcfg.h and Lptmr_Icu_Ip_Cfg.h are different"
#endif
/* Check if header file and Icu configuration header file are of the same software version */
#if ((LPTMR_ICU_IP_[!"."!]_PBCFG_SW_MAJOR_VERSION != LPTMR_ICU_IP_CFG_SW_MAJOR_VERSION) || \
     (LPTMR_ICU_IP_[!"."!]_PBCFG_SW_MINOR_VERSION != LPTMR_ICU_IP_CFG_SW_MINOR_VERSION) || \
     (LPTMR_ICU_IP_[!"."!]_PBCFG_SW_PATCH_VERSION != LPTMR_ICU_IP_CFG_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Lptmr_Icu_Ip_[!"."!]_PBcfg.h and Lptmr_Icu_Ip_Cfg.h are different"
#endif
[!ENDLOOP!][!//
[!ELSE!][!//
/* Check if source file and Icu configuration header file are of the same vendor */
#if (LPTMR_ICU_IP_PBCFG_VENDOR_ID != LPTMR_ICU_IP_CFG_VENDOR_ID)
    #error "Lptmr_Icu_Ip_PBcfg.h and Lptmr_Icu_Ip_Cfg.h have different vendor IDs"
#endif
    /* Check if header file and Icu configuration header file are of the same Autosar version */
#if ((LPTMR_ICU_IP_PBCFG_AR_RELEASE_MAJOR_VERSION != LPTMR_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LPTMR_ICU_IP_PBCFG_AR_RELEASE_MINOR_VERSION != LPTMR_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LPTMR_ICU_IP_PBCFG_AR_RELEASE_REVISION_VERSION != LPTMR_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Lptmr_Icu_Ip_PBcfg.h and Lptmr_Icu_Ip_Cfg.h are different"
#endif
/* Check if header file and Icu configuration header file are of the same software version */
#if ((LPTMR_ICU_IP_PBCFG_SW_MAJOR_VERSION != LPTMR_ICU_IP_CFG_SW_MAJOR_VERSION) || \
     (LPTMR_ICU_IP_PBCFG_SW_MINOR_VERSION != LPTMR_ICU_IP_CFG_SW_MINOR_VERSION) || \
     (LPTMR_ICU_IP_PBCFG_SW_PATCH_VERSION != LPTMR_ICU_IP_CFG_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Lptmr_Icu_Ip_PBcfg.h and Lptmr_Icu_Ip_Cfg.h are different"
#endif
[!ENDIF!][!//

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!//

[!IF "count(./IcuConfigSet/IcuLptmr/*) > '0'"!]
[!CODE!]#define LPTMR_ICU_CONFIG_EXT \[!CR!][!ENDCODE!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!LOOP "variant:all()"!][!//
        [!CODE!][!WS4!]LPTMR_ICU_CONFIG_[!"."!]_PB \[!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS4!]LPTMR_ICU_CONFIG_PB[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LPTMR_ICU_IP_CFG_H */

[!ENDCODE!]
