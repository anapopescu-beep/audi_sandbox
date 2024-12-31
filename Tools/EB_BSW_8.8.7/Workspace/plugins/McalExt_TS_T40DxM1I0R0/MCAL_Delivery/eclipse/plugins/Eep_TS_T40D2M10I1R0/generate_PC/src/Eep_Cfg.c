[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : IPV_FTFC
*   Dependencies         : 
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
* @file Eep_Cfg.c
*
* @addtogroup EEP
* @{
*/

#ifdef __cplusplus
extern "C"{
#endif

[!INDENT "0"!]
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Eep.h"
[!IF "AutosarExt/EepDisableDemReportErrorStatus ='false'"!][!//
    #include "Dem.h"
[!ENDIF!][!//
[!ENDINDENT!][!//
#ifdef EEP_PRECOMPILE_SUPPORT

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_VENDOR_ID_CFG_C                      43
#define EEP_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define EEP_AR_RELEASE_MINOR_VERSION_CFG_C       4
#define EEP_AR_RELEASE_REVISION_VERSION_CFG_C    0
#define EEP_SW_MAJOR_VERSION_CFG_C               1
#define EEP_SW_MINOR_VERSION_CFG_C               0
#define EEP_SW_PATCH_VERSION_CFG_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Eep header file are of the same vendor */
#if (EEP_VENDOR_ID_CFG_C != EEP_VENDOR_ID)
    #error "Eep_Cfg.c and Eep.h have different vendor ids"
#endif
/* Check if current file and Eep header file are of the same Autosar version */
#if ((EEP_AR_RELEASE_MAJOR_VERSION_CFG_C    != EEP_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_AR_RELEASE_MINOR_VERSION_CFG_C    != EEP_AR_RELEASE_MINOR_VERSION) || \
     (EEP_AR_RELEASE_REVISION_VERSION_CFG_C != EEP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep_Cfg.c and Eep.h are different"
#endif
/* Check if current file and Eep header file are of the same Software version */
#if ((EEP_SW_MAJOR_VERSION_CFG_C != EEP_SW_MAJOR_VERSION) || \
     (EEP_SW_MINOR_VERSION_CFG_C != EEP_SW_MINOR_VERSION) || \
     (EEP_SW_PATCH_VERSION_CFG_C != EEP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep_Cfg.c and Eep.h are different"
#endif

[!INDENT "0"!][!//
[!IF "AutosarExt/EepDisableDemReportErrorStatus ='false'"!][!//
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    [!WS "1"!]/* Check if source file and Dem header file are of the same version */
    [!WS "1"!]#if ((EEP_AR_RELEASE_MAJOR_VERSION_CFG_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
    [!WS "1"!]     (EEP_AR_RELEASE_MINOR_VERSION_CFG_C != DEM_AR_RELEASE_MINOR_VERSION) \
    [!WS "1"!]    )
    [!WS "1"!]#error "AutoSar Version Numbers of Eep_Cfg.c and Dem.h are different"
    [!WS "1"!]#endif
    #endif
[!ENDIF!][!//
[!ENDINDENT!][!//

[!INCLUDE "Eep_VersionCheck.m"!][!//

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


[!ENDCODE!]


#endif /* EEP_PRECOMPILE_SUPPORT */
#ifdef __cplusplus
}
#endif

/** @}*/
