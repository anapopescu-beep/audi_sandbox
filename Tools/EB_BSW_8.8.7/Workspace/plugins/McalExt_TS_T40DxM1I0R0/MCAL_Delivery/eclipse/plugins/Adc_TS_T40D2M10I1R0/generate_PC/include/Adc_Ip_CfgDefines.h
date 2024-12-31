[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : ADC
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

#ifndef ADC_IP_CFGDEFINES_H
#define ADC_IP_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup adc_ip_config Adc IPL Configuration
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
==================================================================================================*/

/* Important Note: The header warapper file depends on header platform and can not be used independently.
*  Do not change #include order in this file */
[!INDENT "0"!][!//
[!NOCODE!][!//
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!][!//
    [!VAR "ShortDerivative" = "'X'"!][!//
    [!IF "contains($DerivativeName, 'S32K1')"!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_ADC.h"[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_SIM.h"[!CR!][!ENDCODE!][!//
        [!IF "contains($DerivativeName, 'S32K146') or contains($DerivativeName, 'S32K148')"!][!//
            [!VAR "ShortDerivative" = "'S32K14x_Extended'"!][!//
            [!CODE!][!WS "0"!]#include "Adc_Ip_HeaderWrapper_S32K14x_Extended.h"[!CR!][!ENDCODE!][!//
        [!ELSE!][!//
            [!VAR "ShortDerivative" = "'S32K1xx'"!][!//
            [!CODE!][!WS "0"!]#include "Adc_Ip_HeaderWrapper_S32K1xx.h"[!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ELSE!][!//
        [!CODE!][!WS "0"!]#error "Unknown platform!"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!CODE!][!WS "0"!]#error "Unknown platform!"[!CR!][!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDINDENT!][!//
#include "OsIf.h"

[!NOCODE!][!//
[!INCLUDE "Adc_VersionCheck_Src.m"!][!//
[!INCLUDE "Adc_RegOperations.m"!][!//
[!ENDNOCODE!][!//
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IP_VENDOR_ID_CFGDEFINES                      43
#define ADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES       4
#define ADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES       4
#define ADC_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES    0
#define ADC_IP_SW_MAJOR_VERSION_CFGDEFINES               1
#define ADC_IP_SW_MINOR_VERSION_CFGDEFINES               0
#define ADC_IP_SW_PATCH_VERSION_CFGDEFINES               1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if Adc_Ip_CfgDefines.h file and Adc_Ip_HeaderWrapper_[!"$ShortDerivative"!].h file are of the same vendor */
#if (ADC_IP_VENDOR_ID_CFGDEFINES != ADC_IP_VENDOR_ID_HEADERWRAPPER_[!"text:toupper($ShortDerivative)"!])
    #error "Adc_Ip_CfgDefines.h and Adc_Ip_HeaderWrapper_[!"$ShortDerivative"!].h have different vendor ids"
#endif

/* Check if Adc_Ip_CfgDefines.h file and Adc_Ip_HeaderWrapper_[!"$ShortDerivative"!].h file are of the same Autosar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES != ADC_IP_AR_RELEASE_MAJOR_VERSION_HEADERWRAPPER_[!"text:toupper($ShortDerivative)"!]) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES != ADC_IP_AR_RELEASE_MINOR_VERSION_HEADERWRAPPER_[!"text:toupper($ShortDerivative)"!]) || \
     (ADC_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES != ADC_IP_AR_RELEASE_REVISION_VERSION_HEADERWRAPPER_[!"text:toupper($ShortDerivative)"!]) \
    )
    #error "AutoSar Version Numbers of Adc_Ip_CfgDefines.h and Adc_Ip_HeaderWrapper_[!"$ShortDerivative"!].h are different"
#endif

/* Check if Adc_Ip_CfgDefines.h file and Adc_Ip_HeaderWrapper_[!"$ShortDerivative"!].h file are of the same Software version */
#if ((ADC_IP_SW_MAJOR_VERSION_CFGDEFINES != ADC_IP_SW_MAJOR_VERSION_HEADERWRAPPER_[!"text:toupper($ShortDerivative)"!]) || \
     (ADC_IP_SW_MINOR_VERSION_CFGDEFINES != ADC_IP_SW_MINOR_VERSION_HEADERWRAPPER_[!"text:toupper($ShortDerivative)"!]) || \
     (ADC_IP_SW_PATCH_VERSION_CFGDEFINES != ADC_IP_SW_PATCH_VERSION_HEADERWRAPPER_[!"text:toupper($ShortDerivative)"!]) \
    )
  #error "Software Version Numbers of Adc_Ip_CfgDefines.h and Adc_Ip_HeaderWrapper_[!"$ShortDerivative"!].h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check AutoSar version */
#if ((ADC_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES != OSIF_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Ip_CfgDefines.h and OsIf.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

[!CALL "Adc_Ip_CfgDefines"!][!//

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ADC_IP_CFGDEFINES_H */
[!ENDCODE!]
