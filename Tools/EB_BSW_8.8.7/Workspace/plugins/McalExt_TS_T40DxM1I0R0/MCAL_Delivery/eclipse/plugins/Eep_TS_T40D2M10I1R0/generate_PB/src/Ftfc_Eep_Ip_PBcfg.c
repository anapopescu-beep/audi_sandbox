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
*   @file       Ftfc_Eep_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*
*   @addtogroup FTFC_EEP_IP
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
#include "Ftfc_Eep_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTFC_EEP_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C                      43
#define FTFC_EEP_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define FTFC_EEP_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C       4
#define FTFC_EEP_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C    0
#define FTFC_EEP_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C               1
#define FTFC_EEP_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C               0
#define FTFC_EEP_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Version checks for Ftfc_Eep_Ip_Cfg.h */
#if (FTFC_EEP_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != FTFC_EEP_IP_CFG_VENDOR_ID_H)
    #error "Ftfc_Eep_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ftfc_Eep_Ip_Cfg.h have different vendor IDs!"
#endif
#if ((FTFC_EEP_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != FTFC_EEP_IP_CFG_AR_RELEASE_MAJOR_VERSION_H) || \
     (FTFC_EEP_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != FTFC_EEP_IP_CFG_AR_RELEASE_MINOR_VERSION_H) || \
     (FTFC_EEP_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != FTFC_EEP_IP_CFG_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "Ftfc_Eep_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ftfc_Eep_Ip_Cfg.h are for different AUTOSAR versions!"
#endif
#if ((FTFC_EEP_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != FTFC_EEP_IP_CFG_SW_MAJOR_VERSION_H) || \
     (FTFC_EEP_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != FTFC_EEP_IP_CFG_SW_MINOR_VERSION_H) || \
     (FTFC_EEP_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != FTFC_EEP_IP_CFG_SW_PATCH_VERSION_H)    \
    )
    #error "Ftfc_Eep_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ftfc_Eep_Ip_Cfg.h have different SW versions!"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                        FUNCTION PROTOTYPES
==================================================================================================*/
[!NOCODE!][!//
[!VAR "acCallBackPtr" = "'NULL_PTR'"!]
[!VAR "startEepromAccessNotifPtr" = "'NULL_PTR'"!]
[!VAR "finishedEepromAccessNotifPtr" = "'NULL_PTR'"!]

[!SELECT "./EepFtfcCfg/*[1]"!][!//

    [!IF "node:value(./EepFtfcAcCallBack) != 'NULL_PTR'"!][!//
        [!VAR "acCallBackPtr" = "node:value(./EepFtfcAcCallBack)"!][!//
    [!ENDIF!][!//

    [!IF "node:exists(./EepStartEepromAccessNotif)"!][!//
        [!IF "node:value(./EepStartEepromAccessNotif) != 'NULL_PTR'"!]
            [!VAR "startEepromAccessNotifPtr" = "node:value(./EepStartEepromAccessNotif)"!]
        [!ENDIF!][!//
    [!ENDIF!][!//

    [!IF "node:exists(./EepFinishedEepromAccessNotif)"!][!//
        [!IF "node:value(./EepFinishedEepromAccessNotif) != 'NULL_PTR'"!]
            [!VAR "finishedEepromAccessNotifPtr" = "node:value(./EepFinishedEepromAccessNotif)"!]
        [!ENDIF!][!//
    [!ENDIF!][!//

[!ENDSELECT!][!//

    [!IF "($acCallBackPtr != 'NULL_PTR') or ($startEepromAccessNotifPtr != 'NULL_PTR') or ($finishedEepromAccessNotifPtr != 'NULL_PTR')"!][!//
[!CODE!][!//
#define EEP_START_SEC_CODE
#include "Eep_MemMap.h"

[!ENDCODE!][!//

        [!IF "$acCallBackPtr != 'NULL_PTR'"!][!//
            [!CODE!]extern void [!"$acCallBackPtr"!](void);[!CR!][!ENDCODE!][!//
            [!VAR "acCallBackPtr" = "concat('(Ftfc_Eep_Ip_Ac_Callback_Type)&', $acCallBackPtr)"!][!//
        [!ENDIF!][!//

        [!IF "$startEepromAccessNotifPtr != 'NULL_PTR'"!][!//
            [!CODE!]extern void [!"$startEepromAccessNotifPtr"!](void);[!CR!][!ENDCODE!][!//
            [!VAR "startEepromAccessNotifPtr" = "concat('(Ftfc_Eep_Ip_StartEepromAccessNotif_Type)&', $startEepromAccessNotifPtr)"!]
        [!ENDIF!][!//

        [!IF "$finishedEepromAccessNotifPtr != 'NULL_PTR'"!][!//
            [!CODE!]extern void [!"$finishedEepromAccessNotifPtr"!](void);[!CR!][!ENDCODE!][!//
            [!VAR "finishedEepromAccessNotifPtr" = "concat('(Ftfc_Eep_Ip_FinishedEepromAccessNotif_Type)&', $finishedEepromAccessNotifPtr)"!]
        [!ENDIF!][!//

[!CODE!][!//

#define EEP_STOP_SEC_CODE
#include "Eep_MemMap.h"
[!ENDCODE!][!//
    [!ENDIF!][!//

[!ENDNOCODE!][!//

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eep_Memmap.h"

const Ftfc_Eep_Ip_ConfigType EepFtfcCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /** acCallBackPtr                */ [!"$acCallBackPtr"!],
    /** startEepromAccessNotifPtr    */ [!"$startEepromAccessNotifPtr"!],
    /** finishedEepromAccessNotifPtr */ [!"$finishedEepromAccessNotifPtr"!]
};

#define EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eep_Memmap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
