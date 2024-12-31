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

#ifndef EWM_IP_CFG_DEFINES_H
#define EWM_IP_CFG_DEFINES_H

/**
*   @file
*
*   @addtogroup Ewm_Ip
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

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EWM_IP_CFG_DEFINES_VENDOR_ID                    43
#define EWM_IP_CFG_DEFINES_MODULE_ID                    102
#define EWM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define EWM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     4
#define EWM_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define EWM_IP_CFG_DEFINES_SW_MAJOR_VERSION             1
#define EWM_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define EWM_IP_CFG_DEFINES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((EWM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
        (EWM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ewm_Ip_Cfg_Defines.h and StandardTypes.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!IF "node:exists(./../../../Wdg_43_Instance1/ELEMENTS/Wdg)"!][!//
[!NOCODE!]
[!INDENT "0"!]
[!VAR "EwmEnableDevErrorDetect" = "0"!][!//
[!IF "node:value(./../../../Wdg_43_Instance1/ELEMENTS/Wdg/WdgGeneral/WdgDevErrorDetect)"!]
    [!VAR "EwmEnableDevErrorDetect" = "1"!]
[!ENDIF!]
[!CODE!]
/**
* @brief  Compile switch to enable development error detection
*/
#define EWM_IP_DEV_ERROR_DETECT ([!IF "$EwmEnableDevErrorDetect = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])[!ENDCODE!][!CR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//
/**
* @brief  This constant specifies if the instance of the EWM is selected or not
*/
#define EWM_IP_ENABLE           (STD_ON)

[!ELSE!]
/**
* @brief  Compile switch to enable development error detection
*/
#define EWM_IP_DEV_ERROR_DETECT (STD_OFF)
/**
* @brief  This constant specifies if the instance of the EWM is selected or not
*/
#define EWM_IP_ENABLE           (STD_OFF)
[!ENDIF!]

[!IF "node:exists(./../../../Wdg_43_Instance1/ELEMENTS/Wdg)"!]
/**
* @brief  This variable will indicate if the ISR for EWM instances is used
*/
[!NOCODE!]
[!IF "node:value(./../../../Wdg_43_Instance1/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration/WdgInterruptEnable)"!]
    [!CODE!]#define EWM_IP_ISR0_USED (STD_ON)[!ENDCODE!][!CR!]
[!ELSE!]
    [!CODE!]#define EWM_IP_ISR0_USED (STD_OFF)[!ENDCODE!][!CR!]
[!ENDIF!]
[!ENDNOCODE!]
[!ENDIF!]
/**
* @brief  This variable will indicate RAM/ROM execution
*/
[!NOCODE!]
[!VAR "RunAreaROM" = "0"!]
[!VAR "RunAreaRAM" = "0"!]

[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
        [!IF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgRunArea')) = 'ROM'"!]
            [!VAR "RunAreaROM" = "1"!]
            [!IF "num:i($RunAreaRAM) = 1"!]
                [!ERROR!]The "WdgRunArea" must be either ROM or RAM for both enabled Wdg Instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ELSE!]
            [!VAR "RunAreaRAM" = "1"!]
            [!IF "num:i($RunAreaROM) = 1"!]
                [!ERROR!]The "WdgRunArea" must be either ROM or RAM for both enabled Wdg Instances[!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]

[!IF "num:i($RunAreaROM) = 1"!]
    [!CODE!]#define WDG_ROM (1U)[!ENDCODE!]
[!ELSE!]
    [!CODE!]#define WDG_RAM (0U)[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]

/**
 * @brief First byte of the EWM Service key
 */
#define EWM_IP_FEATURE_KEY_FIRST_BYTE_U8 ([!"ecu:get('Ewm.Ip.Feature.Key.First.Byte.U8')"!])

/**
 * @brief Second byte of the EWM Service key
 */
#define EWM_IP_FEATURE_KEY_SECOND_BYTE_U8 ([!"ecu:get('Ewm.Ip.Feature.Key.Second.Byte.U8')"!])

/**
 * @brief EWM Compare High register maximum value
 */
#define EWM_IP_FEATURE_CMPH_MAX_VALUE_U8 ([!"ecu:get('Ewm.Ip.Feature.Cmph.Max.Value.U8')"!])


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

/** @} */

#endif /* EWM_IP_CFG_DEFINES_H */
