/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Wdog,Ewm
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
*   @file
*
*   @addtogroup Wdog_Ip
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

[!INCLUDE "Wdg_PluginMacros.m"!][!//
/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Wdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDOG_IP_PBCFG_VENDOR_ID_C                      43
#define WDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define WDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C       4
#define WDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C    0
#define WDOG_IP_PBCFG_SW_MAJOR_VERSION_C               1
#define WDOG_IP_PBCFG_SW_MINOR_VERSION_C               0
#define WDOG_IP_PBCFG_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/* Check if current file and Wdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h header file are of the same vendor */
#if (WDOG_IP_PBCFG_VENDOR_ID_C != WDOG_IP_PBCFG_VENDOR_ID)
#error "Wdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Wdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h have different vendor ids"
#endif

/* Check if current file and Wdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg header file are of the same Autosar version */
#if ((WDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != WDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION   ) || \
     (WDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C    != WDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION   ) || \
     (WDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != WDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Wdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
#endif

/* Check if current file and Wdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg header file are of the same software version */
#if ((WDOG_IP_PBCFG_SW_MAJOR_VERSION_C != WDOG_IP_PBCFG_SW_MAJOR_VERSION) || \
     (WDOG_IP_PBCFG_SW_MINOR_VERSION_C != WDOG_IP_PBCFG_SW_MINOR_VERSION) || \
     (WDOG_IP_PBCFG_SW_PATCH_VERSION_C != WDOG_IP_PBCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Wdog_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.h are different"
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
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

[!AUTOSPACING!]
[!IF "node:exists(./../../../Wdg/ELEMENTS/Wdg)"!]
[!IF "(normalize-space(node:value(./../../../Wdg/ELEMENTS/Wdg/WdgGeneral/WdgCallbackNotification)) !='NULL_PTR') and (normalize-space(node:value(./../../../Wdg/ELEMENTS/Wdg/WdgGeneral/WdgCallbackNotification)) !='NULL')"!]
/**
 *   @brief External Notifications for Wdg Interrupt
 */[!CR!]
extern void [!"node:value(./../../../Wdg/ELEMENTS/Wdg/WdgGeneral/WdgCallbackNotification)"!](void);
[!VAR "WdgCbkFunc" = "node:value(./../../../Wdg/ELEMENTS/Wdg/WdgGeneral/WdgCallbackNotification)"!]
[!ELSE!]
[!VAR "WdgCbkFunc" = "'NULL_PTR'"!]
[!ENDIF!]
[!ENDIF!]

[!IF "node:exists(./../../../Wdg/ELEMENTS/Wdg)"!][!//
const Wdog_Ip_ConfigType Wdog_Ip_OffModeSettings[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
{
    (Wdog_Ip_ClkSourceType) WDOG_IP_LPO_CLOCK, /* .clkSource */
    {
                (boolean) FALSE, /*.bWait */
                (boolean) FALSE, /*.bStop */
                (boolean) FALSE  /*.bDebug */
    },
    (boolean) [!IF "node:value(concat(concat('./../../../Wdg','/ELEMENTS/Wdg/WdgSettingsConfig/','WdgSettingsOff'),'/WdgAllowUpdates'))"!]TRUE[!ELSE!]FALSE[!ENDIF!], /* .UpdateEnable */
    (boolean)TRUE, /* .IntEnable */
    (boolean)FALSE, /* .WinEnable */
    (uint16)0x00U, /* .WindowValue */
    (uint16)0x400U, /* .TimeoutValue */
    (boolean)FALSE, /* .PrescalerEnable */
    (Wdog_Ip_CallbackPtrType) NULL_PTR /*.pfWdogCallback */
};

const Wdog_Ip_ConfigType Wdog_Ip_SlowModeSettings[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
{
[!CALL "WdogConfig","WdgMode" = "'WdgSettingsSlow'","WdgNo" = "''"!]
    [!IF "$WdgCbkFunc != 'NULL_PTR'"!]
    (Wdog_Ip_CallbackPtrType) &[!"$WdgCbkFunc"!] /*.pfWdogCallback */
    [!ELSE!]
    (Wdog_Ip_CallbackPtrType) NULL_PTR /*.pfWdogCallback */
    [!ENDIF!]
};

const Wdog_Ip_ConfigType Wdog_Ip_FastModeSettings[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]= 
{
[!CALL "WdogConfig","WdgMode" = "'WdgSettingsFast'","WdgNo" = "''"!]
    [!IF "$WdgCbkFunc != 'NULL_PTR'"!]
    (Wdog_Ip_CallbackPtrType) &[!"$WdgCbkFunc"!] /*.pfWdogCallback */
    [!ELSE!]
    (Wdog_Ip_CallbackPtrType) NULL_PTR /*.pfWdogCallback */
    [!ENDIF!]
};

[!ENDIF!][!//

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

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
