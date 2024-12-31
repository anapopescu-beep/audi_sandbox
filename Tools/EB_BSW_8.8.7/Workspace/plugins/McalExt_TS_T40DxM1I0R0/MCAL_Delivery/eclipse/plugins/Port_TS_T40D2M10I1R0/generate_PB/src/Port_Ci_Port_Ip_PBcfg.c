/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : PORT_CI
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
*   @file    Port_Ci_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*
*   @addtogroup Port_CFG
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
#include "Port_Ci_Port_Ip.h"
[!//
[!NOCODE!][!//
[!/* Include package file in order to get valid Pins */!][!//
[!IF "((ecu:get('Port.Family'))=142)"!][!//
    [!INCLUDE "Port_S32K142_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=144)"!][!//
    [!INCLUDE "Port_S32K144_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=146)"!][!//
    [!INCLUDE "Port_S32K146_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=148)"!][!//
    [!INCLUDE "Port_S32K148_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=118)"!][!//
    [!INCLUDE "Port_S32K118_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=116)"!][!//
    [!INCLUDE "Port_S32K116_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=string('142w'))"!][!//
    [!INCLUDE "Port_S32K142w_Resource.m"!][!//
[!ELSEIF "((ecu:get('Port.Family'))=string('144w'))"!][!//
    [!INCLUDE "Port_S32K144w_Resource.m"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!//
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module description file
* @details      The integration of incompatible files shall be avoided.
*
*/
#define PORT_CI_PORT_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                       43
#define PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C        4
#define PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C        4
#define PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C     0
#define PORT_CI_PORT_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                1
#define PORT_CI_PORT_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                0
#define PORT_CI_PORT_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Port_Ci_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port_Ci_Port_Ip.h are of the same vendor */
#if (PORT_CI_PORT_IP_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != PORT_CI_PORT_IP_VENDOR_ID_H)
    #error "Port_Ci_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port_Ci_Port_Ip.h have different vendor ids"
#endif
/* Check if the files Port_Ci_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port_Ci_Port_Ip.h are of the same Autosar version */
#if ((PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C    != PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_H)  || \
     (PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C    != PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_H)  || \
     (PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_H)  \
    )
    #error "AutoSar Version Numbers of Port_Ci_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port_Ci_Port_Ip.h are different"
#endif
/* Check if the files Port_Ci_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port_Ci_Port_Ip.h are of the same software version */
#if ((PORT_CI_PORT_IP_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != PORT_CI_PORT_IP_SW_MAJOR_VERSION_H) || \
     (PORT_CI_PORT_IP_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != PORT_CI_PORT_IP_SW_MINOR_VERSION_H) || \
     (PORT_CI_PORT_IP_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != PORT_CI_PORT_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Port_Ci_Port_Ip_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port_Ci_Port_Ip.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
[!VAR "pinPortIdx_IP"    = "0"!][!//
[!VAR "mux_value_IP"     = "0"!][!//
[!VAR "mux_IP"           = "'PORT_MUX_ALT0'"!][!//
[!VAR "direction_IP"     = "'PORT_CI_PORT_PIN_DISABLED'"!][!//
[!VAR "pullConfig_IP"    = "'PORT_INTERNAL_PULL_NOT_ENABLED'"!][!//
[!VAR "driveStrength_IP" = "'PORT_DRIVE_STRENGTH_LOW'"!][!//
[!VAR "passiveFilter_IP" = "'(boolean)FALSE'"!][!//
[!VAR "lockRegister_IP"  = "'PORT_LOCK_REGISTER_DISABLED'"!][!//
[!VAR "digitalFilter_IP" = "'(boolean)FALSE'"!][!//
[!VAR "initValue_IP"     = "'0'"!][!//

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
[!MACRO "GetAltConf_IP"!][!//
[!NOCODE!][!//
[!/* Alternative Mode 0 is the GPIO */!][!//
[!IF "text:match(./PortPinMode,'GPIO')"!][!//
    [!VAR "OutPinAltFunc_IP"="1"!]!//
[!ELSE!][!//
    [!VAR "MacPinMode_IP"="concat(./PortPinMode,'_PORT',number(./PortPinPcr))"!][!//
    [!VAR "OutPinAltFunc_IP"="number(substring-after(substring-before((substring-after($PinMap,$MacPinMode_IP)),':'),';'))"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//
[!MACRO "CalculateSSS_IO_IP"!][!//
[!NOCODE!][!//
[!CALL "GetAltConf_IP"!][!//
[!VAR "mux_value_IP"="$OutPinAltFunc_IP"!][!//
[!/* Check if read status is enabled */!][!//
[!IF "($mux_value_IP = 0)"!][!//
    [!VAR "mux_IP" = "'PORT_MUX_ALT0'"!][!//
[!ELSEIF "($mux_value_IP = 1)"!][!//
    [!VAR "mux_IP" = "'PORT_MUX_AS_GPIO'"!][!//
[!ELSEIF "($mux_value_IP = 2)"!][!//
    [!VAR "mux_IP" = "'PORT_MUX_ALT2'"!][!//
[!ELSEIF "($mux_value_IP = 3)"!][!//
    [!VAR "mux_IP" = "'PORT_MUX_ALT3'"!][!//
[!ELSEIF "($mux_value_IP = 4)"!][!//
    [!VAR "mux_IP" = "'PORT_MUX_ALT4'"!][!//
[!ELSEIF "($mux_value_IP = 5)"!][!//
    [!VAR "mux_IP" = "'PORT_MUX_ALT5'"!][!//
[!ELSEIF "($mux_value_IP = 6)"!][!//
    [!VAR "mux_IP" = "'PORT_MUX_ALT6'"!][!//
[!ELSEIF "($mux_value_IP = 7)"!][!//
    [!VAR "mux_IP" = "'PORT_MUX_ALT7'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//
[!MACRO "GetPDO_IP"!][!//
[!NOCODE!][!//
[!IF "not(contains(node:fallback(./PortPinMode,'ADC'),'ADC') or contains(node:fallback(./PortPinMode,'TAL'),'TAL') or contains(node:fallback(./PortPinMode,'ACMP'),'ACMP'))"!][!//
    [!IF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_LOW')"!][!//
        [!VAR "MacPinPDO_IP"="num:i(0)"!][!//
    [!ELSEIF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_HIGH')"!][!//
        [!VAR "MacPinPDO_IP"="num:i(1)"!][!//
    [!ELSEIF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_NOTCHANGED')"!][!//
        [!VAR "MacPinPDO_IP"="num:i(2)"!][!//
    [!ELSE!][!//
        [!/*don't anything*/!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "MacPinPDO_IP"="num:i(2)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!VAR "initValue_IP" = "$MacPinPDO_IP"!][!//
[!ENDMACRO!][!//
[!//
[!MACRO "GetPinData_IP"!][!//
[!NOCODE!][!//
[!VAR "portBase_IP"   = "num:i(0)"!][!//
[!VAR "gpioBase_IP"   = "num:i(0)"!][!//
[!VAR "pinPortIdx_IP" = "num:i(./PortPinPcr mod 32)"!][!//
[!VAR "direction_IP"  = "./PortPinDirection"!][!//
[!/* Get Base Address*/!][!//
[!IF "(node:fallback(./PortPinPcr, 0) >= num:i(128))"!][!//
    [!VAR "portBase_IP" = "'IP_PORTE'"!][!//
    [!VAR "gpioBase_IP" = "'IP_PTE'"!][!//
[!ELSEIF "(node:fallback(./PortPinPcr, 0) >= num:i(96))"!][!//
    [!VAR "portBase_IP" = "'IP_PORTD'"!][!//
    [!VAR "gpioBase_IP" = "'IP_PTD'"!][!//
[!ELSEIF "(node:fallback(./PortPinPcr, 0) >= num:i(64))"!][!//
    [!VAR "portBase_IP" = "'IP_PORTC'"!][!//
    [!VAR "gpioBase_IP" = "'IP_PTC'"!][!//
[!ELSEIF "(node:fallback(./PortPinPcr, 0) >= num:i(32))"!][!//
    [!VAR "portBase_IP" = "'IP_PORTB'"!][!//
    [!VAR "gpioBase_IP" = "'IP_PTB'"!][!//
[!ELSEIF "(node:fallback(./PortPinPcr, 0) >= num:i(0))"!][!//
    [!VAR "portBase_IP" = "'IP_PORTA'"!][!//
    [!VAR "gpioBase_IP" = "'IP_PTA'"!][!//
[!ENDIF!][!//
[!IF "node:fallback(./PortPinMode, 'GPIO') != 'GPIO'"!][!//
    [!VAR "gpioBase_IP" = "'NULL_PTR'"!][!//
[!ENDIF!][!//
[!CALL "CalculateSSS_IO_IP"!][!//
[!IF "node:fallback(./PortPinPE, 'PullDisabled') = 'PullEnabled'"!][!//
    [!IF "node:fallback(./PortPinPS, 'PullDown') = 'PullUp'"!][!//
        [!VAR "pullConfig_IP" = "'PORT_INTERNAL_PULL_UP_ENABLED'"!][!//
    [!ELSE!][!//
        [!VAR "pullConfig_IP" = "'PORT_INTERNAL_PULL_DOWN_ENABLED'"!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "pullConfig_IP" = "'PORT_INTERNAL_PULL_NOT_ENABLED'"!][!//
[!ENDIF!][!//
[!IF "node:fallback(./PortPinDSE, 'Low_Drive_Strength') = 'High_Drive_Strength'"!][!//
    [!VAR "driveStrength_IP" = "'PORT_DRIVE_STRENGTH_HIGH'"!][!//
[!ELSE!][!//
    [!VAR "driveStrength_IP" = "'PORT_DRIVE_STRENGTH_LOW'"!][!//
[!ENDIF!][!//
[!/* Check if open port passive filter is enabled */!][!//
[!IF "./PortPinPFE"!][!//
    [!VAR "passiveFilter_IP" = "'(boolean)TRUE'"!][!//
[!ELSE!][!//
    [!VAR "passiveFilter_IP" = "'(boolean)FALSE'"!][!//
[!ENDIF!][!//
[!/* Check if lock register bitfield in PCRs is enabled */!][!//
[!IF "./PortPinLK"!][!//
    [!VAR "lockRegister_IP" = "'PORT_LOCK_REGISTER_ENABLED'"!][!//
[!ELSE!][!//
    [!VAR "lockRegister_IP" = "'PORT_LOCK_REGISTER_DISABLED'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//
[!MACRO "GetDigitalFilter_IP"!][!//
[!NOCODE!][!//
[!VAR "pcrIndex" = "node:value(./PortPinPcr)"!][!//
[!VAR "digitalFilter_IP"="'(boolean)FALSE'"!][!//
[!IF "num:i(count(../../../../DigitalFilter/*)) > 0"!][!//
    [!LOOP "../../../../DigitalFilter/*"!][!//
        [!IF "text:match(./DigitalFilterPort,'PORT_A')"!][!//
            [!VAR "DigitalFilterPort"="num:i(0)"!][!//
        [!ELSEIF "text:match(./DigitalFilterPort,'PORT_B')"!][!//
            [!VAR "DigitalFilterPort"="num:i(1)"!][!//
        [!ELSEIF "text:match(./DigitalFilterPort,'PORT_C')"!][!//
            [!VAR "DigitalFilterPort"="num:i(2)"!][!//
        [!ELSEIF "text:match(./DigitalFilterPort,'PORT_D')"!][!//
            [!VAR "DigitalFilterPort"="num:i(3)"!][!//
        [!ELSEIF "text:match(./DigitalFilterPort,'PORT_E')"!][!//
            [!VAR "DigitalFilterPort"="num:i(4)"!][!//
        [!ELSE!][!//
            [!/*don't anything*/!][!//
        [!ENDIF!][!//
        [!LOOP "./DigitalFilterChannel/*"!][!//
            [!VAR "DigitalFilterChannel"="($DigitalFilterPort * 32) + node:value(./DigitalFilterChannelIndex)"!][!//
            [!IF "num:i($DigitalFilterChannel) = $pcrIndex"!][!//
                [!VAR "digitalFilter_IP"="'(boolean)TRUE'"!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!VAR "digitalFilter_IP"="'(boolean)FALSE'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!VAR "initValue_IP" = "$MacPinPDO_IP"!][!//
[!ENDMACRO!][!//

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
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

[!INDENT "0"!][!//
    const Port_Ci_Port_Ip_PinSettingsConfig g_pin_mux_InitConfigArr[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][NUM_OF_CONFIGURED_PINS] =
[!ENDINDENT!][!//
{
[!SELECT "PortConfigSet"!][!//
[!VAR "count"= "1"!][!//
[!VAR "Maxcount"= "num:i(count(PortContainer/*/PortPin/*))-1"!][!//
[!LOOP "PortContainer/*/PortPin/*"!][!//
[!CALL "GetPinData_IP"!][!//
[!CALL "GetPDO_IP"!][!//
[!CALL "GetDigitalFilter_IP"!][!//
[!IF "$Maxcount>=$count"!][!//
    {
        .portBase                    = [!"$portBase_IP"!],
        .gpioBase                    = [!"$gpioBase_IP"!],
        .pinPortIdx                  = [!"$pinPortIdx_IP"!],
        .mux                         = [!"$mux_IP"!],
        .direction                   = [!"concat('PORT_CI','_',$direction_IP)"!],
        .pullConfig                  = [!"$pullConfig_IP"!],
        .driveStrength               = [!"$driveStrength_IP"!],
        .passiveFilter               = [!"$passiveFilter_IP"!],
        .lockRegister                = [!"$lockRegister_IP"!],
        .digitalFilter               = [!"$digitalFilter_IP"!][!//
[!IF "node:fallback(./PortPinMode, 'GPIO') = 'GPIO'"!][!//
,
        .initValue                   = [!"$initValue_IP"!]
    },
[!ELSE!][!//

    },
[!ENDIF!][!//
[!ELSE!][!//
    {
        .portBase                    = [!"$portBase_IP"!],
        .gpioBase                    = [!"$gpioBase_IP"!],
        .pinPortIdx                  = [!"$pinPortIdx_IP"!],
        .mux                         = [!"$mux_IP"!],
        .direction                   = [!"concat('PORT_CI','_',$direction_IP)"!],
        .pullConfig                  = [!"$pullConfig_IP"!],
        .driveStrength               = [!"$driveStrength_IP"!],
        .passiveFilter               = [!"$passiveFilter_IP"!],
        .lockRegister                = [!"$lockRegister_IP"!],
        .digitalFilter               = [!"$digitalFilter_IP"!][!//
[!IF "node:fallback(./PortPinMode, 'GPIO') = 'GPIO'"!][!//
,
        .initValue                   = [!"$initValue_IP"!]
    }
[!ELSE!][!//

    }
[!ENDIF!][!//
[!ENDIF!][!//
[!VAR "count"= "$count+1"!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

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
