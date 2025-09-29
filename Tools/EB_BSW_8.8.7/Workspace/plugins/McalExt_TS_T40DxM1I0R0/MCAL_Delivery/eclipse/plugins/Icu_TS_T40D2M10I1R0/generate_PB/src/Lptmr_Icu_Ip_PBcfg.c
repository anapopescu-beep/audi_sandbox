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

/**
 *   @file       Lptmr_Icu_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c
 *   @version    1.0.1
 *
 *   @brief      AUTOSAR Icu - contains the data exported by the ICU module.
 *   @details    Contains the information that will be exported by the module, as requested by AUTOSAR.
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
#include "Lptmr_Icu_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPTMR_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID_C                    43
#define LPTMR_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C     4
#define LPTMR_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C     4
#define LPTMR_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION_C  0
#define LPTMR_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION_C             1
#define LPTMR_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION_C             0
#define LPTMR_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (LPTMR_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_VENDOR_ID_C != LPTMR_ICU_IP_TYPES_VENDOR_ID)
    #error "Lptmr_Icu_Ip[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Lptmr_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((LPTMR_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MAJOR_VERSION_C != LPTMR_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LPTMR_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_MINOR_VERSION_C != LPTMR_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LPTMR_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_AR_RELEASE_REVISION_VERSION_C != LPTMR_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lptmr_Icu_Ip[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Lptmr_Icu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((LPTMR_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MAJOR_VERSION_C != LPTMR_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (LPTMR_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_MINOR_VERSION_C != LPTMR_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (LPTMR_ICU_IP_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_SW_PATCH_VERSION_C != LPTMR_ICU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lptmr_Icu_Ip[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Lptmr_Icu_Ip_Types.h are different"
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
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"
/** @brief Signature of report events interrupt function. */
extern void Icu_ReportEvents(uint16 Channel, boolean bOverflow);
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "PBCfg_Variant" = "concat('PB_', $postBuildVariant)"!]
[!ELSE!]
    [!VAR "PBCfg_Variant" = "'PB'"!]
[!ENDIF!]
[!SELECT "./IcuConfigSet"!]
[!IF "count(IcuLptmr/*) > '0'"!]
[!LOOP "IcuLptmr/*"!]
    [!VAR "IcuLptmrChannelsNum" = "num:i(count(IcuLptmrChannels/*))"!]
    
const Lptmr_Icu_Ip_ChannelConfigType Lptmr_Icu_Ip_[!"node:value(./IcuLptmrModule)"!]_ChannelConfig_[!"$PBCfg_Variant"!][[!"num:i(count(IcuLptmrChannels/*))"!]U] =
{
[!VAR "comma" = "$IcuLptmrChannelsNum"!]
[!VAR "callback" = "'NULL_PTR'"!]
[!LOOP "IcuLptmrChannels/*"!]
[!VAR "IcuMeasurementMode" = "node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(IcuChannelRef)) = as:path(node:current())]/IcuMeasurementMode)"!]
[!VAR "IcuDefaultStartEdge" = "node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(IcuChannelRef)) = as:path(node:current())]/IcuDefaultStartEdge)"!]
[!VAR "IcuOverflowNotification" = "node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(IcuChannelRef)) = as:path(node:current())]/IcuOverflowNotification)"!]
[!IF "($IcuMeasurementMode = 'ICU_MODE_SIGNAL_EDGE_DETECT')"!]
[!VAR "callback" = "'&Icu_ReportEvents'"!]
[!ENDIF!]
[!VAR "callbackParam" = "node:value(../../../../../IcuConfigSet/IcuChannel/*[as:path(node:ref(IcuChannelRef)) = as:path(node:current())]/IcuChannelId)"!]
   /** @brief [!"node:name(.)"!] */
   {
       /** @brief ID of LPTMR HW Channel used */
       (uint8)[!"node:value(IcuLptmrChannel)"!]U,
       /** @brief Lptmr Default Start Edge */
       LPTMR_[!"$IcuDefaultStartEdge"!],
       /** @brief Lptmr MeasurementMode */
       LPTMR_[!"$IcuMeasurementMode"!],
       /** @brief interrupt callback function. */
       NULL_PTR,
       [!"$callback"!],
       /** @brief The parameters of callback functions for channels events */
       (uint16)[!"$callbackParam"!]
   }[!IF "(num:i($comma))>1"!][!CODE!],[!CR!][!ENDCODE!][!VAR "comma"="$comma - 1"!][!ELSE!][!CR!][!ENDIF!]
[!ENDLOOP!]
};

const Lptmr_Icu_Ip_ConfigType Lptmr_Icu_Ip_[!"node:value(./IcuLptmrModule)"!]_Config_[!"$PBCfg_Variant"!] =
{
   /** @brief Number of Lptmr channels in the Icu configuration */
   (uint8)[!"num:i($IcuLptmrChannelsNum)"!]U,
   /** @brief Lptmr channel configuration parameters */
   [!"node:value('IcuLptmrPinSelect')"!],
   /** @brief Configured Lptmr clock source */
   [!"node:value(./IcuLptmrChannelClkSrc)"!],
   /** @brief Configured Lptmr Prescale */
   [!"node:value('IcuLptmrPrescaler')"!],
   /** @brief Configured Lptmr enable prescale */
   (boolean)[!"text:toupper(node:value(./PrescalerEnable))"!],
   /** @brief Pointer to the array of Lptmr enabled Icu channel configurations */
   &Lptmr_Icu_Ip_[!"node:value(./IcuLptmrModule)"!]_ChannelConfig_[!"$PBCfg_Variant"!]
};

[!ENDLOOP!]
[!ENDIF!]
[!ENDSELECT!]


#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!]
