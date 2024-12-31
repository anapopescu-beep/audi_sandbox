[!CODE!][!//
[!AUTOSPACING!][!//
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

#ifndef FTM_QDEC_IP_CFGDEFINES_H
#define FTM_QDEC_IP_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup group_name
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
#include "StandardTypes.h"

[!NOCODE!][!// Include specific header file
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!CODE!][!WS "0"!]/* Include platform header file. */[!CR!][!ENDCODE!][!//
    [!IF "contains($DerivativeName, 'S32G2')"!][!//
        [!CODE!][!WS "0"!]#include "S32G274A_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32G3')"!][!//
        [!CODE!][!WS "0"!]#include "S32G399A_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'SAF85')"!][!//
        [!CODE!][!WS "0"!]#include "SAF85XX_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32K1')"!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains($DerivativeName, 'S32R41')"!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_FTM.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FTM_QDEC_IP_CFGDEFINES_VENDOR_ID                     43
#define FTM_QDEC_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION      4
#define FTM_QDEC_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION      4
#define FTM_QDEC_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION   0
#define FTM_QDEC_IP_CFGDEFINES_SW_MAJOR_VERSION              1
#define FTM_QDEC_IP_CFGDEFINES_SW_MINOR_VERSION              0
#define FTM_QDEC_IP_CFGDEFINES_SW_PATCH_VERSION              1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and StandardTypes.h are of the same AUTOSAR version */
    #if ((FTM_QDEC_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_QDEC_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Ftm_Qdec_Ip_CfgDefines.h and StandardTypes.h are different."
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/** @brief Support for User mode.
*          If this parameter has been configured to STD_ON,
*          the FTM driver code can be executed from both supervisor and user mode.
*/
#define FTM_QDEC_ENABLE_USER_MODE_SUPPORT   ([!IF "QdecGeneral/QdecEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Verification for user mode support. */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #if (defined (FTM_QDEC_ENABLE_USER_MODE_SUPPORT) && (STD_ON == FTM_QDEC_ENABLE_USER_MODE_SUPPORT))
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Qdec in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
 #endif
#endif

#ifndef FTM_QDEC_SET_CLOCK_MODE_API
/** @brief  Switch for enabling the dual clock functionality (Qdec_SetClockMode() API) */
#define FTM_QDEC_SET_CLOCK_MODE_API      ([!IF "QdecGeneral/QdecEnableDualClockMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#endif

#define FTM_QDEC_NOTIFICATION_SUPPORTED  ([!IF "QdecGeneral/QdecOverFlowNotificationSupported"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!LOOP "QdecInstanceConfig/*"!]
[!VAR "HwInstance" = "substring-after(./QdecFtmModule,'FTM_')"!]
[!IF "(./QdecEnTofIsr = 'true') or (../../QdecGeneral/QdecOverFlowNotificationSupported = 'true')"!]
#define FTM_QDEC_[!"$HwInstance"!]_ISR_USED

[!ENDIF!]
[!ENDLOOP!]

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/**@}*/

#endif /* FTM_QDEC_IP_CFGDEFINES_H */
[!ENDCODE!][!//