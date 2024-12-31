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

#ifndef WDOG_IP_CFG_DEFINES_H
#define WDOG_IP_CFG_DEFINES_H

/**
*   @file
*
*   @addtogroup Wdog_Ip
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
#define WDOG_IP_CFG_DEFINES_VENDOR_ID                    43
#define WDOG_IP_CFG_DEFINES_MODULE_ID                    102
#define WDOG_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define WDOG_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     4
#define WDOG_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define WDOG_IP_CFG_DEFINES_SW_MAJOR_VERSION             1
#define WDOG_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define WDOG_IP_CFG_DEFINES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((WDOG_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
        (WDOG_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wdog_Ip_Cfg_Defines.h and StandardTypes.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!IF "node:exists(./../../../Wdg/ELEMENTS/Wdg)"!][!//
[!NOCODE!]
[!INDENT "0"!]
[!VAR "WdogEnableDevErrorDetect" = "0"!][!//
[!IF "node:value(./../../../Wdg/ELEMENTS/Wdg/WdgGeneral/WdgDevErrorDetect)"!]
    [!VAR "WdogEnableDevErrorDetect" = "1"!]
[!ENDIF!]
[!CODE!]
/**
* @brief  Compile switch to enable development error detection
*/
#define WDOG_IP_DEV_ERROR_DETECT ([!IF "$WdogEnableDevErrorDetect = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])[!ENDCODE!][!CR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//
[!CODE!]
/**
* @brief  This constant specifies if the instance of the WDG is selected or not
*/[!ENDCODE!]
[!IF "node:exists(./../../../Wdg/ELEMENTS/Wdg)"!][!//
#define WDOG_IP_ENABLE           (STD_ON)
[!ELSE!]
#define WDOG_IP_ENABLE           (STD_OFF)
[!ENDIF!]

/**
* @brief  Compile switch to allow/forbid disabling the Wdog during runtime
*/
#define WDOG_IP_DEINIT ([!IF "node:value(./../../../Wdg/ELEMENTS/Wdg/WdgGeneral/WdgDisableAllowed)"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief Define Timeout Method.
* @details Define a certain timeout method from OsIf which will be used in the driver.
*/
#define WDOG_IP_TIMEOUT_METHOD       [!//
[!IF "node:value(./../../../Wdg/ELEMENTS/Wdg/WdgGeneral/WdgTimeoutMethod) = 'OSIF_COUNTER_DUMMY'"!][!//
    (OSIF_COUNTER_DUMMY)
[!ELSEIF "node:value(./../../../Wdg/ELEMENTS/Wdg/WdgGeneral/WdgTimeoutMethod) = 'OSIF_COUNTER_SYSTEM'"!][!//
    (OSIF_COUNTER_SYSTEM)
[!ELSEIF "node:value(./../../../Wdg/ELEMENTS/Wdg/WdgGeneral/WdgTimeoutMethod) = 'OSIF_COUNTER_CUSTOM'"!][!//
    (OSIF_COUNTER_CUSTOM)
[!ENDIF!][!//

/**
* @brief Define Timeout Value.
* @details Define a certain timeout value from OsIf which will be used in the driver.
*/
#define WDOG_IP_OSIF_TIMEOUT_VAL        ([!"num:i(node:value(./../../../Wdg/ELEMENTS/Wdg/WdgGeneral/WdgOsifTimeoutVal))"!])
[!ELSE!]
/**
* @brief  Compile switch to enable development error detection
*/
#define WDOG_IP_DEV_ERROR_DETECT (STD_OFF)
#define WDOG_IP_ENABLE           (STD_OFF)

/**
* @brief  Compile switch to allow/forbid disabling the Wdog during runtime
*/
#define WDOG_IP_DEINIT (STD_OFF)

#define WDOG_IP_TIMEOUT_METHOD   (OSIF_COUNTER_DUMMY)
#define WDOG_IP_OSIF_TIMEOUT_VAL (3000)
[!ENDIF!]


/**
* @brief  This variable will indicate if the ISR for WDOG instances is used
*/
[!NOCODE!]
[!IF "node:exists(./../../../Wdg/ELEMENTS/Wdg)"!]
[!IF "node:value(./../../../Wdg/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsFast/WdgOperationMode)= 'Interrupt'"!]
    [!CODE!]#define WDOG_IP_ISR0_USED (STD_ON)[!ENDCODE!][!CR!]
[!ELSEIF "node:value(./../../../Wdg/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsSlow/WdgOperationMode)= 'Interrupt'"!]
    [!CODE!]#define WDOG_IP_ISR0_USED (STD_ON)[!ENDCODE!][!CR!]
[!ELSE!]
    [!CODE!]#define WDOG_IP_ISR0_USED (STD_OFF)[!ENDCODE!][!CR!]
[!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!]


/**
* @brief  This variable will indicate if the WDOG test mode is enabled
* Note: This feature is not available in the Wdg High Level Driver
*/
#define WDOG_IP_ENABLE_TEST_MODE (STD_OFF)


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
 * @brief The 32-bit value used for unlocking the WDOG
 */
#define WDOG_IP_FEATURE_UNLOCK_VALUE_U32 ([!"ecu:get('Wdog.Ip.Feature.Unlock.Value.U32')"!])

/**
 * @brief The 32-bit value used for resetting the WDOG counter
 */
#define WDOG_IP_FEATURE_TRIGGER_VALUE_U32 ([!"ecu:get('Wdog.Ip.Feature.Trigger.Value.U32')"!])

/**
 * @brief The reset value of the timeout register
 */
#define WDOG_IP_FEATURE_TO_RESET_VALUE_U16 ([!"ecu:get('Wdog.Ip.Feature.To.Reset.Value.U16')"!])

/**
 * @brief The value minimum of the timeout register
 */
#define WDOG_IP_FEATURE_MINIMUM_TIMEOUT_VALUE_U16 ([!"ecu:get('Wdog.Ip.Feature.Minimum.Timeout.Value.U16')"!])

/**
 * @brief The reset value of the window register
 */
#define WDOG_IP_FEATURE_WIN_RESET_VALUE_U16 ([!"ecu:get('Wdog.Ip.Feature.Win.Reset.Value.U16')"!])

/**
 * @brief The first 16-bit value used for unlocking the WDOG
 */
#define WDOG_IP_FEATURE_UNLOCK16_FIRST_VALUE_U16 ([!"ecu:get('Wdog.Ip.Feature.Unlock16.First.Value.U16')"!])

/**
 * @brief The second 16-bit value used for unlocking the WDOG
 */
#define WDOG_IP_FEATURE_UNLOCK16_SECOND_VALUE_U16 ([!"ecu:get('Wdog.Ip.Feature.Unlock16.Second.Value.U16')"!])

/**
 * @brief The first 16-bit value used for resetting the WDOG counter
 */
#define WDOG_IP_FEATURE_TRIGGER16_FIRST_VALUE_U16 ([!"ecu:get('Wdog.Ip.Feature.Trigger16.First.Value.U16')"!])

/**
 * @brief The second 16-bit value used for resetting the WDOG counter
 */
#define WDOG_IP_FEATURE_TRIGGER16_SECOND_VALUE_U16 ([!"ecu:get('Wdog.Ip.Feature.Trigger16.Second.Value.U16')"!])

/**
 * @brief Default reset value of the CS register
 */
#define WDOG_IP_FEATURE_CS_RESET_VALUE_U16 ([!"ecu:get('Wdog.Ip.Feature.Cs.Reset.Value.U16')"!])

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

#endif /* WDOG_IP_CFG_DEFINES_H */
