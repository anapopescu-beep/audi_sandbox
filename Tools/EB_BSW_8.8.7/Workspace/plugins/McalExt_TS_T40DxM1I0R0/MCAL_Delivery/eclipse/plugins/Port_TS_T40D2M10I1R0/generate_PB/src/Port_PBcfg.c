[!CODE!][!//
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
*   @file    Port_PBcfg.c
*
*   @implements Port_PBcfg.c_Artifact
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port.h"
[!NOCODE!][!//
[!INCLUDE "Port_VersionCheck_Src_PB.m"!][!//
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


/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module description file
* @details      The integration of incompatible files shall be avoided.
*
*/
#define PORT_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                       43
#define PORT_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C        4
#define PORT_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C        4
#define PORT_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C     0
#define PORT_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                1
#define PORT_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                0
#define PORT_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C                1

/*=================================================================================================
*                                      FILE VERSION CHECKS
=================================================================================================*/
/* Check if the files Port_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port.h are of the same vendor */
#if (PORT_VENDOR_ID_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != PORT_VENDOR_ID)
    #error "Port_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port.h have different vendor ids"
#endif
/* Check if the files Port_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C    != PORT_AR_RELEASE_MAJOR_VERSION)  || \
     (PORT_AR_RELEASE_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C    != PORT_AR_RELEASE_MINOR_VERSION)  || \
     (PORT_AR_RELEASE_REVISION_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != PORT_AR_RELEASE_REVISION_VERSION)  \
    )
    #error "AutoSar Version Numbers of Port_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port.h are different"
#endif
/* Check if the files Port_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBCFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!]_[!ENDIF!]PBcfg.c and Port.h are different"
#endif

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/
/**
* @brief The number of configured Digital Filter Ports
*/
[!SELECT "PortConfigSet"!][!//
#define PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_U8         ([!"num:i(count(DigitalFilter/*))"!]U)
[!ENDSELECT!][!//

/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
[!NOCODE!][!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetAltConf                                 */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the Alternative Mode configuration for selected pin */!][!//
[!MACRO "GetAltConf"!][!//
[!NOCODE!][!//
[!/* Alternative Mode 0 is the GPIO */!][!//
[!IF "text:match(./PortPinMode,'GPIO')"!][!//
    [!VAR "OutPinAltConf"="1"!]
[!ELSE!][!//
    [!VAR "MacPinMode"="concat(./PortPinMode,'_PORT',number(./PortPinPcr))"!][!//
    [!VAR "OutPinAltConf"="number(substring-after(substring-before((substring-after($PinMap,$MacPinMode)),':'),';'))"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetMSCR                                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Fill the MSCR register for the selected pin */!][!//
[!MACRO "GetMSCR"!][!//
[!NOCODE!][!//
[!VAR "MacPinMSCR"="num:i(0)"!][!//
[!/* Get the Alternative Mode configuration and fill the PCR */!][!//
[!CALL "GetAltConf"!][!//
[!/* Check if pin is disabled (analog) mode, meaning is configured in ALT0 */!][!//
[!IF "($OutPinAltConf = 0)"!][!//
    [!/* For Disabled (analog) mode, the Mux field value is zero */!][!//
[!ELSE!][!//
    [!/* Set the MUX field */!][!//
    [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl($OutPinAltConf,8))"!][!//
[!ENDIF!][!//

    [!/* Check what type of drive strength is set.*/!][!//
    [!IF "text:match(./PortPinDSE,'Low_Drive_Strength')"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(0,6))"!][!//
    [!ELSEIF "text:match(./PortPinDSE,'High_Drive_Strength')"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,6))"!][!//
    [!ENDIF!][!//

    [!/* Check if open port passive filter is enabled */!][!//
    [!IF "./PortPinPFE"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,4))"!][!//
    [!ENDIF!][!//

    [!/* Check whether pull-up or pull-down is enabled */!][!//
    [!IF "text:match(./PortPinPE,'PullEnabled')"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,1))"!][!//
        [!IF "text:match(./PortPinPS,'PullUp')"!][!//
            [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,0))"!][!//
        [!ELSEIF "text:match(./PortPinPS,'PullDown')"!][!//
            [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(0,0))"!][!//
        [!ENDIF!][!//
    [!ELSEIF "text:match(./PortPinPE,'PullDisabled')"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(0,1))"!][!//
    [!ENDIF!][!//

    [!/* Check if lock register is enabled */!][!//
    [!IF "./PortPinLK"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,15))"!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!"num:inttohex($MacPinMSCR,8)"!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetUnusedPCR                                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Fill the MSCR register for the unused pins */!][!//
[!MACRO "GetUnusedPCR"!][!//
[!NOCODE!][!//
[!VAR "MacUnusedPinPCR"="num:i(0)"!][!//
[!/* Check if the unused pins are configured as GPIOs or as Disabled */!][!//
[!IF "text:match(./PortPinMode,'GPIO')"!][!//
    [!/* Set the Mux field of the PCR to 001, configuring the pin as GPIO */!][!//
    [!VAR "MacUnusedPinPCR"="bit:or($MacUnusedPinPCR,bit:shl(1,8))"!][!//
[!ELSE!][!//
    [!/* Set the Mux field of the PCR to 000, configuring the pin as Disabled */!][!//
    [!VAR "MacUnusedPinPCR"="bit:or($MacUnusedPinPCR,bit:shl(0,8))"!][!//
[!ENDIF!][!//
    [!/* Check what type of drive strength is set.*/!][!//
    [!IF "text:match(./PortPinDSE,'Low_Drive_Strength')"!][!//
        [!VAR "MacUnusedPinPCR"="bit:or($MacUnusedPinPCR,bit:shl(0,6))"!][!//
    [!ELSEIF "text:match(./PortPinDSE,'High_Drive_Strength')"!][!//
        [!VAR "MacUnusedPinPCR"="bit:or($MacUnusedPinPCR,bit:shl(1,6))"!][!//
    [!ENDIF!][!//
    [!/* Check if PE is enabled */!][!//
    [!IF "text:match(./PortPinPE,'PullEnabled')"!][!//
        [!VAR "MacUnusedPinPCR"="bit:or($MacUnusedPinPCR,bit:shl(1,1))"!][!//
        [!/* Check if Pull-up is enabled.*/!][!//
        [!IF "text:match(./PortPinPS,'PullUp')"!][!//
            [!VAR "MacUnusedPinPCR"="bit:or($MacUnusedPinPCR,bit:shl(1,0))"!][!//
        [!ELSEIF "text:match(./PortPinPS,'PullDown')"!][!//
            [!VAR "MacUnusedPinPCR"="bit:or($MacUnusedPinPCR,bit:shl(0,0))"!][!//
        [!ENDIF!][!//
    [!ELSEIF "text:match(./PortPinPE,'PullDisabled')"!][!//
        [!VAR "MacUnusedPinPCR"="bit:or($MacUnusedPinPCR,bit:shl(0,1))"!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!"num:inttohex($MacUnusedPinPCR,8)"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetPDO                                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the output status for selected pin */!][!//
[!MACRO "GetPDO"!][!//
[!NOCODE!][!//
[!IF "not(contains(node:fallback(./PortPinMode,'ADC'),'ADC') or contains(node:fallback(./PortPinMode,'TAL'),'TAL') or contains(node:fallback(./PortPinMode,'ACMP'),'ACMP'))"!][!//
    [!IF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_LOW')"!][!//
        [!VAR "MacPinPDO"="num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_HIGH')"!][!//
        [!VAR "MacPinPDO"="num:i(1)"!][!//
    [!ENDIF!][!//
    [!IF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_NOTCHANGED')"!][!//
        [!VAR "MacPinPDO"="num:i(2)"!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "MacPinPDO"="num:i(2)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacPinPDO"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetPDDir                                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the direction to be set for selected pin */!][!//
[!MACRO "GetPDDir"!][!//
[!NOCODE!][!//
[!IF "text:match(./PortPinMode,'ADC')"!][!//
    [!VAR "MacPinPDDir"="num:i(0)"!][!//
[!ELSE!][!//
    [!IF "text:match(./PortPinDirection,'PORT_PIN_IN')"!][!//
        [!VAR "MacPinPDDir"="num:i(1)"!][!//
    [!ENDIF!][!//
    [!IF "text:match(./PortPinDirection,'PORT_PIN_OUT')"!][!//
        [!VAR "MacPinPDDir"="num:i(2)"!][!//
    [!ENDIF!][!//
    [!IF "text:match(./PortPinDirection,'PORT_PIN_HIGH_Z')"!][!//
        [!VAR "MacPinPDDir"="num:i(3)"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacPinPDDir"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetGPIO                                 */!][!//
[!/*****************************************************************************/!][!//
[!/* Set the initial GPIO Mode for selected pin */!][!//
[!MACRO "GetGPIO"!][!//
[!NOCODE!][!//
[!IF "text:match(./PortPinMode,'GPIO')"!][!//
    [!VAR "MacGPIOMode"= "string('(boolean)TRUE')"!][!//
[!ELSE!][!//
    [!VAR "MacGPIOMode"= "string('(boolean)FALSE')"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacGPIOMode"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetDirConf                                 */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the Alternative Mode configuration for selected pin */!][!//
[!MACRO "GetDirConf"!][!//
[!NOCODE!][!//
[!IF "(./PortPinMode = 'GPIO')"!][!//
    [!IF "./PortPinDirectionChangeable"!][!//
        [!VAR "MacDirection"= "string('(boolean)TRUE')"!][!//
    [!ELSE!][!//
        [!VAR "MacDirection"= "string('(boolean)FALSE')"!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "MacDirection"= "string('(boolean)FALSE')"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacDirection"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetModeChang                               */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "GetModeChang"!][!//
[!NOCODE!][!//
[!IF "./PortPinModeChangeable"!][!//
    [!VAR "MacModeChang"= "string('(boolean)TRUE')"!][!//
[!ELSE!][!//
    [!VAR "MacModeChang"= "string('(boolean)FALSE')"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacModeChang"!][!//
[!ENDMACRO!][!//
[!ENDNOCODE!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetDigitalFilterPort                     */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the direction to be set for selected pin */!][!//
[!MACRO "GetDigitalFilterPort"!][!//
[!NOCODE!][!//
    [!IF "text:match(./DigitalFilterPort,'PORT_A')"!][!//
        [!VAR "MacDigitalFilterPort"="num:i(0)"!][!//
    [!ELSEIF "text:match(./DigitalFilterPort,'PORT_B')"!][!//
        [!VAR "MacDigitalFilterPort"="num:i(1)"!][!//
    [!ELSEIF "text:match(./DigitalFilterPort,'PORT_C')"!][!//
        [!VAR "MacDigitalFilterPort"="num:i(2)"!][!//
    [!ELSEIF "text:match(./DigitalFilterPort,'PORT_D')"!][!//
        [!VAR "MacDigitalFilterPort"="num:i(3)"!][!//
    [!ELSEIF "text:match(./DigitalFilterPort,'PORT_E')"!][!//
        [!VAR "MacDigitalFilterPort"="num:i(4)"!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacDigitalFilterPort"!][!//
[!ENDMACRO!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetDigitalFilterClock                    */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the direction to be set for selected pin */!][!//
[!MACRO "GetDigitalFilterClock"!][!//
[!NOCODE!][!//
    [!IF "text:match(./DigitalFilterClock,'BUS_CLOCK')"!][!//
        [!VAR "MacDigitalFilterClock"="num:i(0)"!][!//
    [!ELSEIF "text:match(./DigitalFilterClock,'LPO_CLOCK')"!][!//
        [!VAR "MacDigitalFilterClock"="num:i(1)"!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacDigitalFilterClock"!][!//
[!ENDMACRO!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetDigitalFilterPinMask                  */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the direction to be set for selected pin */!][!//
[!MACRO "GetDigitalFilterPinMask"!][!//
[!NOCODE!][!//
[!VAR "MacDigitalFilterPinMask"="num:i(0)"!][!//
[!LOOP "DigitalFilterChannel/*"!][!//
    [!VAR "MacDigitalFilterPinMask"="bit:or($MacDigitalFilterPinMask,bit:shl(1,./DigitalFilterChannelIndex))"!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!"num:inttohex($MacDigitalFilterPinMask,8)"!][!//
[!ENDMACRO!][!//

[!//
[!SELECT "PortConfigSet"!][!//
[!//
#define PORT_START_SEC_CONFIG_DATA_8
#include "Port_MemMap.h"
[!/* The number of configured partition on the platform */!][!//
[!NOCODE!][!//
[!VAR "maxPartition" = "num:i(0)"!][!//
[!IF "node:value(../PortGeneral/PortMulticoreSupport)='true'"!]
    [!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!][!//
        [!VAR "maxPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!IF "$maxPartition = 0"!][!//
    [!VAR "maxPartition" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
/**
* @brief Array containing list of partition which used in driver
*/
static const uint8 au8Port_PartitionList[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_MAX_PARTITION] =
{
[!INDENT "4"!][!//
[!VAR "CounterPortEcucPartitionRef"="num:i(count(../PortGeneral/PortEcucPartitionRef/*))"!][!//
[!FOR "index" = "0" TO "num:i($maxPartition) - 1"!][!//
    [!VAR "PartitionExist"="0"!][!//
    [!LOOP "../PortGeneral/PortEcucPartitionRef/*"!][!//
        [!VAR "PortCrtPart" = "node:value(.)"!][!//
        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
            [!IF "$PortCrtPart = node:value(./OsAppEcucPartitionRef)"!][!//
                [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                [!IF "$index = node:value(./EcucCoreId)"!][!//
                    [!VAR "PartitionExist"="1"!][!//
                [!ENDIF!][!//
                [!ENDSELECT!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
    [!IF "$CounterPortEcucPartitionRef = 0"!][!//
        [!VAR "PartitionExist"="1"!][!//
        [!VAR "CounterPortEcucPartitionRef"="num:i($CounterPortEcucPartitionRef + 1)"!][!//
    [!ENDIF!][!//
    [!CODE!][!//
        (uint8)[!"num:i($PartitionExist)"!][!IF "$index < num:i($maxPartition) - 1"!],[!ENDIF!]
    [!ENDCODE!][!//
[!ENDFOR!][!//
[!ENDINDENT!][!//
};
#define PORT_STOP_SEC_CONFIG_DATA_8
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_32
#include "Port_MemMap.h"
/**
* @brief Array containing list of mapping information for mappable elements
*/
static const uint32 au32Port_PinToPartitionMap[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_MAX_CONFIGURED_PADS_U16] =
{
[!INDENT "4"!][!//
[!FOR "x" = "1" TO "num:i(count(PortContainer/*/PortPin/*))"!][!//
    [!VAR "CounterPortEcucPartitionRef"="num:i(count(../PortGeneral/PortEcucPartitionRef/*))"!][!//
    [!VAR "PartitionValue"="0"!][!//
    [!VAR "GetThePartitionNumber"="0"!][!//
    [!LOOP "PortContainer/*/PortPin/*"!][!//
        [!IF "PortPinId = $x"!][!//
            [!LOOP "PortPinEcucPartitionRef/*"!][!//
                [!VAR "PortCrtPart" = "node:value(.)"!][!//
                [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                    [!IF "$PortCrtPart = node:value(./OsAppEcucPartitionRef)"!][!//
                        [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                            [!VAR "GetThePartitionNumber"="node:value(./EcucCoreId)"!][!//
                            [!VAR "PartitionValue"="bit:or($PartitionValue,(bit:shl(1,$GetThePartitionNumber)))"!][!//
                        [!ENDSELECT!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
            [!ENDLOOP!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$CounterPortEcucPartitionRef = 0"!][!//
        [!VAR "PartitionValue"="1"!][!//
        [!VAR "CounterPortEcucPartitionRef"="num:i($CounterPortEcucPartitionRef + 1)"!][!//
    [!ENDIF!][!//
    [!CODE!][!//
        (uint32)[!"num:inttohex($PartitionValue, 8)"!][!IF "$x < num:i(count(PortContainer/*/PortPin/*))"!],[!ENDIF!]
    [!ENDCODE!][!//
[!ENDFOR!][!//
[!ENDINDENT!][!//
};
#define PORT_STOP_SEC_CONFIG_DATA_32
#include "Port_MemMap.h"
[!ENDSELECT!][!//

#define PORT_START_SEC_CONFIG_DATA_16
#include "Port_MemMap.h"

[!/*****************************************************************************/!][!//
[!/*                          MACRO Port_UnUsedPadsArrayDefault                */!][!//
[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "counter"="0"!][!//
#if (0UL != PORT_MAX_UNUSED_PADS_U16)
/**
* @brief NoDefaultPadsArray is an array containing Unimplemented pads and User pads
*/
static const uint16 Port_au16NoUnUsedPadsArrayDefault[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_MAX_UNUSED_PADS_U16]=
{
[!NOCODE!]
[!FOR "x" = "0" TO "ecu:list('Port.MaxPinNumber')[1]"!][!//
    [!VAR "PinUsed"="0"!][!//
    [!LOOP "PortContainer/*/PortPin/*"!][!//
        [!IF "$PinUsed=0"!][!//
            [!IF "num:i(./PortPinPcr)=$x"!][!//
                [!VAR "PinUsed"="$PinUsed + 1"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!LOOP "UnTouchedPortPin/*"!][!//
        [!IF "$PinUsed=0"!][!//
            [!IF "num:i(./PortPinPcr)=$x"!][!//
                [!VAR "PinUsed"="$PinUsed + 1"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$PinUsed=0"!][!//
        [!IF "contains(concat(',',string(ecu:get('Port.UnimplementedPAD')),','),concat(',',$x,','))"!][!//
            [!VAR "PinUsed"="$PinUsed + 1"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "$PinUsed=0"!][!//
        [!IF "$counter=0"!][!//
[!CODE!][!//
    (uint16)[!"$x"!][!//
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
,
    (uint16)[!"$x"!][!//
[!ENDCODE!][!//
        [!ENDIF!][!//
        [!VAR "counter"= "$counter+1"!][!//
    [!ENDIF!][!//
[!ENDFOR!][!//
[!ENDNOCODE!]
};
#endif
[!ENDSELECT!][!//

#define PORT_STOP_SEC_CONFIG_DATA_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"
[!/*****************************************************************************/!][!//
[!/*                          MACRO Port_UnUsedPin                             */!][!//
[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "counter"="0"!][!//
/**
 * @brief Default Configuration for Pins not initialized
 */
static const Port_UnUsedPinConfigType Port_UnUsedPin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* @note: Configuration of Default pin */
    [!LOOP "NotUsedPortPin"!][!/*
        */!](uint32)[!CALL "GetUnusedPCR"!], (Port_PinDirectionType)[!CALL "GetPDDir"!], (uint8)[!CALL "GetPDO"!][!/*
    */!][!ENDLOOP!]
};
[!ENDSELECT!][!//

[!/*****************************************************************************/!][!//
[!/*                          MACRO Port_aPinConfigDefault                     */!][!//
[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "count"= "1"!][!//
[!VAR "Maxcount"= "num:i(count(PortContainer/*/PortPin/*))-1"!][!//
[!VAR "LoopVar"="1"!][!//
[!VAR "counter"="0"!][!//
/**
* @brief Pin default configuration data for configPB
*/
static const Port_PinConfigType Port_aPinConfigDefault[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_MAX_CONFIGURED_PADS_U16]=
{
[!NOCODE!]
[!FOR "x" = "0" TO "num:i(count(PortContainer/*/PortPin/*))"!][!//
    [!LOOP "PortContainer/*/PortPin/*"!][!//
        [!VAR "Loop"="num:i($LoopVar)"!][!//
        [!IF "PortPinId = $Loop"!][!//
            [!IF "$Maxcount>=$count"!][!//
[!CODE!][!//
    /* PCR Id, PCR Value, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable */
    {(uint16)[!"./PortPinPcr"!], (uint32)[!CALL "GetMSCR"!], (uint8)[!CALL "GetPDO"!], (Port_PinDirectionType)[!CALL "GetPDDir"!], [!CALL "GetGPIO"!], [!CALL "GetDirConf"!], [!CALL "GetModeChang"!]},
[!ENDCODE!][!//
            [!ELSE!][!//
[!CODE!][!//
    /* PCR Id, PCR Value, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable */
    {(uint16)[!"./PortPinPcr"!], (uint32)[!CALL "GetMSCR"!], (uint8)[!CALL "GetPDO"!], (Port_PinDirectionType)[!CALL "GetPDDir"!], [!CALL "GetGPIO"!], [!CALL "GetDirConf"!], [!CALL "GetModeChang"!]}
[!ENDCODE!][!//
            [!ENDIF!][!//
            [!VAR "count"= "$count+1"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!VAR "LoopVar"="$LoopVar + 1"!][!//
[!ENDFOR!][!//
[!ENDNOCODE!]
};
[!ENDSELECT!][!//

[!/*****************************************************************************/!][!//
[!/*                                Port_aDigitalFilter                        */!][!//
[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
#if (0UL != PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_U8)
[!VAR "count"= "1"!][!//
[!VAR "Maxcount"= "num:i(count(DigitalFilter/*))-1"!][!//
static const Port_Ci_Port_Ip_DigitalFilterConfigType Port_aDigitalFilter[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_U8]=
{
[!NOCODE!]
[!LOOP "DigitalFilter/*"!][!//
    [!IF "$Maxcount>=$count"!][!//
[!CODE!][!//
    /* Digital Filter Port, Digital Filter Clock, Digital Filter Width, Digital Filter Port Pins */
    {(uint8)[!CALL "GetDigitalFilterPort"!], (uint8)[!CALL "GetDigitalFilterClock"!], (uint8)[!"./DigitalFilterWidth"!], (uint32)[!CALL "GetDigitalFilterPinMask"!]},
[!ENDCODE!][!//
    [!ELSE!][!//
[!CODE!][!//
    /* Digital Filter Port, Digital Filter Clock, Digital Filter Width, Digital Filter Port Pins */
    {(uint8)[!CALL "GetDigitalFilterPort"!], (uint8)[!CALL "GetDigitalFilterClock"!], (uint8)[!"./DigitalFilterWidth"!], (uint32)[!CALL "GetDigitalFilterPinMask"!]}
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!VAR "count"= "$count+1"!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!]
};
#endif /* (0UL != PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_U8) */
[!ENDSELECT!][!//

[!/*****************************************************************************/!][!//
[!/*                          MACRO Port_ConfigPinParameter                     */!][!//
[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "counter"="0"!][!//
/**
* @brief This table contains all the Configured Port Pin parameters and the
*        number of Port Pins configured by the tool for the post-build mode
* that will be used by the upper layers.
*/
[!/* VariantPreCompile and no more than 1 configured variant */!][!//
[!INDENT "0"!][!//
[!IF "((../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size()<=1))"!][!//
    const Port_ConfigType Port_Config =
[!/* VariantPostBuild */!][!//
[!ELSE!][!//
    [!/* If ECUC exists or there is at least one  */!][!//
    [!IF "variant:size()>0"!][!//
        const Port_ConfigType Port_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
    [!/* VariantPostBuild with no variants or no ECUC configured*/!][!//
    [!ELSE!][!//
        const Port_ConfigType Port_Config =
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDINDENT!][!//
{
    PORT_MAX_CONFIGURED_PADS_U16,
    PORT_MAX_UNUSED_PADS_U16,
#if (0UL != PORT_MAX_UNUSED_PADS_U16)
    Port_au16NoUnUsedPadsArrayDefault[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
#else
    NULL_PTR,
#endif
    &Port_UnUsedPin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    Port_aPinConfigDefault[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_U8,
#if (0UL != PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_U8)
    Port_aDigitalFilter[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
#else
    NULL_PTR,
#endif
    au32Port_PinToPartitionMap[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    au8Port_PartitionList[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    g_pin_mux_InitConfigArr[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDSELECT!][!//

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"
/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/


#ifdef __cplusplus
}
#endif
/** @} */

/* End of File */
[!ENDCODE!][!//
