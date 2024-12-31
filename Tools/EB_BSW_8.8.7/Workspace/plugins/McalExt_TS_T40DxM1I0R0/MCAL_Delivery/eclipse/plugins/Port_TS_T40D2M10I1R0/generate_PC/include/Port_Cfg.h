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
#ifndef PORT_CFG_H
#define PORT_CFG_H

/**
*   @file    Port_Cfg.h
*
*   @implements Port_Cfg.h_Artifact
*   @defgroup   Port_CFG Port CFG
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
=================================================================================================*/
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
#include "Port_[!"."!]_PBcfg.h"
[!ENDLOOP!]
[!ELSE!]
#include "Port_PBcfg.h"
[!ENDIF!]
#include "Port_Ci_Port_Ip_Types.h"
[!NOCODE!][!//
[!INCLUDE "Port_VersionCheck_Inc.m"!][!//
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
#define PORT_CFG_VENDOR_ID_H                       43
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION_H        4
#define PORT_CFG_AR_RELEASE_MINOR_VERSION_H        4
#define PORT_CFG_AR_RELEASE_REVISION_VERSION_H     0
#define PORT_CFG_SW_MAJOR_VERSION_H                1
#define PORT_CFG_SW_MINOR_VERSION_H                0
#define PORT_CFG_SW_PATCH_VERSION_H                1

/*=================================================================================================
*                                      FILE VERSION CHECKS
=================================================================================================*/
[!IF "var:defined('postBuildVariant')"!]
[!LOOP "variant:all()"!]
/* Check if the files Port_Cfg.h and Port_[!"."!]_PBcfg.h are of the same version */
#if (PORT_CFG_VENDOR_ID_H != PORT_VENDOR_ID_[!"."!]_PBCFG_H)
    #error "Port_Cfg.h and Port_[!"."!]_PBcfg.h have different vendor IDs"
#endif
/* Check if the files Port_Cfg.h and Port_[!"."!]_PBcfg.h are of the same Autosar version */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION_H != PORT_AR_RELEASE_MAJOR_VERSION_[!"."!]_PBCFG_H) ||    \
     (PORT_CFG_AR_RELEASE_MINOR_VERSION_H != PORT_AR_RELEASE_MINOR_VERSION_[!"."!]_PBCFG_H) ||    \
     (PORT_CFG_AR_RELEASE_REVISION_VERSION_H != PORT_AR_RELEASE_REVISION_VERSION_[!"."!]_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Port_[!"."!]_PBcfg.h are different"
#endif
/* Check if the files Port_Cfg.h and Port_[!"."!]_PBcfg.h are of the same software version */
#if ((PORT_CFG_SW_MAJOR_VERSION_H != PORT_SW_MAJOR_VERSION_[!"."!]_PBCFG_H) ||  \
     (PORT_CFG_SW_MINOR_VERSION_H != PORT_SW_MINOR_VERSION_[!"."!]_PBCFG_H) ||  \
     (PORT_CFG_SW_PATCH_VERSION_H != PORT_SW_PATCH_VERSION_[!"."!]_PBCFG_H)     \
    )
    #error "Software Version Numbers of Port_Cfg.h and Port_[!"."!]_PBcfg.h are different"
#endif
[!ENDLOOP!]
[!ELSE!]
/* Check if the files Port_Cfg.h and Port_PBcfg.h are of the same version */
#if (PORT_CFG_VENDOR_ID_H != PORT_VENDOR_ID_PBCFG_H)
    #error "Port_Cfg.h and Port_PBcfg.h have different vendor IDs"
#endif
/* Check if the files Port_Cfg.h and Port_PBcfg.h are of the same Autosar version */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION_H != PORT_AR_RELEASE_MAJOR_VERSION_PBCFG_H) ||    \
     (PORT_CFG_AR_RELEASE_MINOR_VERSION_H != PORT_AR_RELEASE_MINOR_VERSION_PBCFG_H) ||    \
     (PORT_CFG_AR_RELEASE_REVISION_VERSION_H != PORT_AR_RELEASE_REVISION_VERSION_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Port_PBcfg.h are different"
#endif
/* Check if the files Port_Cfg.h and Port_PBcfg.h are of the same software version */
#if ((PORT_CFG_SW_MAJOR_VERSION_H != PORT_SW_MAJOR_VERSION_PBCFG_H) ||  \
     (PORT_CFG_SW_MINOR_VERSION_H != PORT_SW_MINOR_VERSION_PBCFG_H) ||  \
     (PORT_CFG_SW_PATCH_VERSION_H != PORT_SW_PATCH_VERSION_PBCFG_H)     \
    )
    #error "Software Version Numbers of Port_Cfg.h and Port_PBcfg.h are different"
#endif
[!ENDIF!]
/* Check if the files Port_Cfg.h and Port_Ci_Port_Ip_Types.h are of the same version */
#if (PORT_CFG_VENDOR_ID_H != PORT_CI_PORT_IP_VENDOR_ID_TYPES_H)
    #error "Port_Cfg.h and Port_Ci_Port_Ip_Types.h have different vendor IDs"
#endif
/* Check if the files Port_Cfg.h and Port_Ci_Port_Ip_Types.h are of the same Autosar version */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION_H != PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_TYPES_H) ||    \
     (PORT_CFG_AR_RELEASE_MINOR_VERSION_H != PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_TYPES_H) ||    \
     (PORT_CFG_AR_RELEASE_REVISION_VERSION_H != PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_TYPES_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Port_Ci_Port_Ip_Types.h are different"
#endif
/* Check if the files Port_Cfg.h and Port_Ci_Port_Ip_Types.h are of the same software version */
#if ((PORT_CFG_SW_MAJOR_VERSION_H != PORT_CI_PORT_IP_SW_MAJOR_VERSION_TYPES_H) ||  \
     (PORT_CFG_SW_MINOR_VERSION_H != PORT_CI_PORT_IP_SW_MINOR_VERSION_TYPES_H) ||  \
     (PORT_CFG_SW_PATCH_VERSION_H != PORT_CI_PORT_IP_SW_PATCH_VERSION_TYPES_H)     \
    )
    #error "Software Version Numbers of Port_Cfg.h and Port_Ci_Port_Ip_Types.h are different"
#endif
/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/
/* @implements Port_PinType_typedef */
typedef uint32 Port_PinType;

/**
* @brief Different port pin modes.
* @details A port pin shall be configurable with a number of port pin modes (type Port_PinModeType).
*        The type Port_PinModeType shall be used with the function call Port_SetPinMode
* @implements Port_PinModeType_typedef
*/
typedef uint8 Port_PinModeType;

/**
* @brief Possible directions of a port pin.
* @implements Port_PinDirectionType_enumeration
*/
typedef enum
{
    PORT_PIN_DISABLED = 0,         /**< @brief Sets port pin as bidirectional. */
    PORT_PIN_IN,                   /**< @brief Sets port pin as input. */
    PORT_PIN_OUT,                  /**< @brief Sets port pin as output. */
    PORT_PIN_HIGH_Z                /**< @brief Sets port pin as high_z. */
} Port_PinDirectionType;

/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/
#define PORT_CONFIG_EXT \
[!IF "var:defined('postBuildVariant')"!][!//
[!LOOP "variant:all()"!][!//
PORT_CONFIG_[!"."!]_PB \
[!ENDLOOP!][!//
[!ELSE!][!//
PORT_CONFIG_PB
[!ENDIF!]

/**
* @brief       Ensure better readability of the configuration
* @note
*/
#define SHL_PAD_U16(x)                      ((uint16)(((uint16)1) << (x)))

/** @brief Port Alternate 0 Mode */
#define PORT_ALT0_FUNC_MODE             ((Port_PinModeType)0)
/** @brief Port GPIO Mode */
#define PORT_GPIO_MODE                  ((Port_PinModeType)1)
/** @brief Port Alternate 2 Mode */
#define PORT_ALT2_FUNC_MODE             ((Port_PinModeType)2)
/** @brief Port Alternate 3 Mode */
#define PORT_ALT3_FUNC_MODE             ((Port_PinModeType)3)
/** @brief Port Alternate 4 Mode */
#define PORT_ALT4_FUNC_MODE             ((Port_PinModeType)4)
/** @brief Port Alternate 5 Mode */
#define PORT_ALT5_FUNC_MODE             ((Port_PinModeType)5)
/** @brief Port Alternate 6 Mode */
#define PORT_ALT6_FUNC_MODE             ((Port_PinModeType)6)
/** @brief Port Alternate 7 Mode */
#define PORT_ALT7_FUNC_MODE             ((Port_PinModeType)7)

[!IF "((ecu:get('Port.Package'))='Port_32QFN')"!][!//
    [!"$PinAbstractionModes_1"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='Port_48LQFP')"!][!//
    [!"$PinAbstractionModes_2"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='Port_64LQFP')"!][!//
    [!"$PinAbstractionModes_3"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='Port_100LQFP')"!][!//
    [!"$PinAbstractionModes_4"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='Port_100MAPBGA')"!][!//
    [!"$PinAbstractionModes_5"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='Port_144LQFP')"!][!//
    [!"$PinAbstractionModes_6"!][!//
[!ELSEIF "((ecu:get('Port.Package'))='Port_176LQFP')"!][!//
    [!"$PinAbstractionModes_7"!][!//
[!ENDIF!][!//

/**
* @brief Enable/Disable Development Error Detection
*
* @implements   PORT_DEV_ERROR_DETECT_define
*/
#define PORT_DEV_ERROR_DETECT           [!IF "PortGeneral/PortDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief Use/remove Port_SetPinDirection function from the compiled driver
*
* @implements   PORT_SET_PIN_DIRECTION_API_define
*/
[!IF "node:exists(PortGeneral/PortSetPinDirectionApi)"!][!//
#define PORT_SET_PIN_DIRECTION_API      [!IF "PortGeneral/PortSetPinDirectionApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!ELSE!][!//
#define PORT_SET_PIN_DIRECTION_API      (STD_OFF)
[!ENDIF!][!//

[!IF "ecu:has('Port.Set2PinsDirectionApiAvailable') and ecu:get('Port.Set2PinsDirectionApiAvailable') = 'true'"!][!//
/**
* @brief Use/remove Port_Set2PinsDirection function from the compiled driver
*
* PORT_SET_2_PINS_DIRECTION_API_define
*/
[!IF "PortGeneral/PortSet2PinsDirectionApi"!][!//
#define PORT_SET_2_PINS_DIRECTION_API   (STD_ON)[!//
[!ELSE!][!//
#define PORT_SET_2_PINS_DIRECTION_API   (STD_OFF)[!//
[!ENDIF!][!//
[!ENDIF!][!//

/**
* @brief Enable/Disable multicore function from the driver
*/
#define PORT_MULTICORE_ENABLED          [!IF "(PortGeneral/PortMulticoreSupport)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief Use/remove Port_SetPinMode function from the compiled driver
*
* @implements   PORT_SET_PIN_MODE_API_define
*/
[!IF "node:exists(PortGeneral/PortSetPinModeApi)"!][!//
#define PORT_SET_PIN_MODE_API           [!IF "PortGeneral/PortSetPinModeApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!ELSE!][!//
#define PORT_SET_PIN_MODE_API           (STD_OFF)
[!ENDIF!][!//

/**
* @brief Use/remove Port_SetAsUnusedPin/Port_SetAsUsedPin function from the compiled driver.
*
*/
#define PORT_SET_AS_UNUSED_PIN_API           [!IF "PortGeneral/PortSetAsUnusedPinApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief Use/remove Port_ResetPinMode function from the compiled driver.
*
*/
#define PORT_RESET_PIN_MODE_API           [!IF "PortGeneral/PortResetPinModeApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief Enable/Disable Port_SetPinMode function updating the output level of the pins configured at runtime as GPIO
*/
#define PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL           [!IF "PortGeneral/PortSetPinModeDoesNotTouchGpioLevel"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief Use/remove Port_GetVersionInfo function from the compiled driver
*
* @implements   PORT_VERSION_INFO_API_define
*/
#define PORT_VERSION_INFO_API           [!IF "PortGeneral/PortVersionInfoApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief The number of configured partition on the platform
*/
[!NOCODE!][!//
[!VAR "maxPartition" = "num:i(0)"!][!//
[!IF "node:value(PortGeneral/PortMulticoreSupport)='true'"!]
    [!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!][!//
        [!VAR "maxPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!IF "$maxPartition = 0"!][!//
    [!VAR "maxPartition" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define PORT_MAX_PARTITION              ([!"num:i($maxPartition)"!]U)

[!NOCODE!][!//
[!SELECT "PortConfigSet"!]
    [!VAR "OuterLoopCounter" = "0"!][!//
    [!VAR "InnerLoopCounter" = "0"!][!//
    [!LOOP "PortContainer/*"!][!//
        [!LOOP "PortPin/*"!][!//
            [!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
            [!VAR "InnerLoopCounter" = "0"!]
            [!VAR "MatchCounter" = "0"!]
            [!VAR "Id" = "PortPinPcr"!]
            [!VAR "Name" = "node:name(.)"!]
            [!LOOP "../../../../PortContainer/*"!][!//
                [!LOOP "PortPin/*"!][!//
                    [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
                    [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
                        [!IF "($Id = PortPinPcr)"!]
                            [!VAR "MatchCounter" = "$MatchCounter + 1"!]
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
            [!ENDLOOP!][!//
            [!IF "$MatchCounter = 1"!]
            [!ELSE!]
                [!ERROR!][!//
                    Error in PortPin list: [!"PortPinPcr is repeated for two or more ports."!][!//
                [!ENDERROR!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
    [!LOOP "PortContainer/*"!][!//
        [!LOOP "PortPin/*"!][!//
            [!VAR "PortPinPcrVar" = "PortPinPcr"!][!//
            [!IF "($PortPinPcrVar > ecu:list('Port.MaxPinNumber')[1])"!][!//
                [!ERROR!][!//
                [!"name(.)"!] [!"': PortPinPcr '"!] [!"string($PortPinPcrVar)"!] [!"concat('- Physical pin numbers greater then ',ecu:list('Port.MaxPinNumber')[1],' are not available in this package')"!][!//
                [!ENDERROR!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
    [!// Check if the PCRs in UnTouchedPins are unique
    [!VAR "OuterLoopCounter" = "0"!][!//
    [!VAR "InnerLoopCounter" = "0"!][!//
    [!LOOP "UnTouchedPortPin/*"!][!//
        [!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
        [!VAR "InnerLoopCounter" = "0"!]
        [!VAR "MatchCounter" = "0"!]
        [!VAR "OuterPortPinPcr" = "./PortPinPcr"!]
        [!LOOP "../../UnTouchedPortPin/*"!][!//
            [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
            [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
                [!IF "($OuterPortPinPcr = ./PortPinPcr)"!]
                    [!VAR "MatchCounter" = "$MatchCounter + 1"!]
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!IF "$MatchCounter > 1"!]
            [!ERROR!][!//
                Error in UnTouchedPortPin list: [!"name(.)"!] with [!"'PortPin Pcr'"!] set to [!"string($OuterPortPinPcr)"!] [!"Pcr is repeated for two or more ports."!][!//
            [!ENDERROR!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!// Check if the configured PCRs in UnTouchedPortPin list are in range
    [!LOOP "UnTouchedPortPin/*"!][!//
        [!VAR "PortPinPcrVar" = "PortPinPcr"!][!//
        [!IF "($PortPinPcrVar > ecu:list('Port.MaxPinNumber')[1])"!][!//
            [!ERROR!][!//
                Error in UnTouchedPortPin list: [!"name(.)"!] [!"': PortPinPcr '"!] [!"string($PortPinPcrVar)"!] [!"concat('- Physical pin numbers greater then ',ecu:list('Port.MaxPinNumber')[1],' are not available in this package')"!][!//
            [!ENDERROR!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!// Check if the configured PCRs are not available
    [!VAR "resourceName" = "'Port.NotAvailablePins'"!][!//
    [!LOOP "UnTouchedPortPin/*"!][!//
        [!VAR "PortPinPcrVar" = "PortPinPcr"!][!//
        [!IF "contains(concat(',',string(ecu:get($resourceName)),','), concat(',',$PortPinPcrVar,','))"!][!//
            [!ERROR!][!//
                Error in UnTouchedPortPin list: [!"name(.)"!] with [!"'PortPin Pcr'"!] set to [!"string($PortPinPcrVar)"!] [!"Pcr not available in this package."!][!//
            [!ENDERROR!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!// Check if there is no PCR that appears both in list of configured pins and in the list of UnTouchedPortPins
    [!LOOP "PortContainer/*"!][!//
        [!VAR "PortContainerName" = "name(.)"!]
        [!LOOP "PortPin/*"!][!//
            [!VAR "MatchCounter" = "0"!]
            [!VAR "ConfiguredPortPinPcr" = "./PortPinPcr"!]
            [!LOOP "../../../../UnTouchedPortPin/*"!][!//
                [!IF "($ConfiguredPortPinPcr = ./PortPinPcr)"!]
                    [!ERROR!][!//
                    Error: PCR [!"string($ConfiguredPortPinPcr)"!] appears in the UnTouchedPortPin list and also in the list of configured pins in Port container [!"string($PortContainerName)"!]. Please remove it from one of the 2 lists[!//
                    [!ENDERROR!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!][!//

/**
* @brief Port Pin symbolic names
* @details Get All Symbolic Names from configuration tool
*
*/
[!NOCODE!]
    [!VAR "OutConfigLoopCounter" = "0"!][!//
    [!VAR "ConfigSetIndex"="0"!]
    [!SELECT "PortConfigSet"!][!//
        [!VAR "ConfigSetName" = "as:name(.)"!][!//
        [!VAR "OutConfigLoopCounter" = "$OutConfigLoopCounter + 1"!][!//
        [!VAR "OutPinLoopCounter" = "0"!][!//
        [!LOOP "PortContainer/*"!][!//
            [!VAR "ContName" = "node:name(.)"!][!//
            [!LOOP "PortPin/*"!][!//
                [!VAR "OutPinLoopCounter" = "$OutPinLoopCounter + 1"!][!//
                [!VAR "Name" = "node:name(.)"!][!//
                [!VAR "MatchCounter" = "0"!][!//
                [!VAR "InConfigLoopCounter" = "0"!][!//
                [!VAR "MatchConfigSet" = "0"!][!//
                [!SELECT "../../../../../PortConfigSet"!][!//
                    [!VAR "InConfigLoopCounter" = "$InConfigLoopCounter + 1"!][!//
                    [!VAR "InPinLoopCounter" = "0"!][!//
                    [!LOOP "PortContainer/*"!][!//
                        [!VAR "ContNameNew" = "node:name(.)"!][!//
                        [!LOOP "PortPin/*"!][!//
                            [!VAR "InPinLoopCounter" = "$InPinLoopCounter + 1"!][!//
                            [!IF "$InConfigLoopCounter < $OutConfigLoopCounter"!][!//
                                [!IF "($ContName = $ContNameNew)"!][!//
                                    [!IF "($Name = node:name(.))"!][!//
                                        [!IF "$InPinLoopCounter = $OutPinLoopCounter"!][!//
                                            [!IF "$MatchConfigSet = $ConfigSetIndex"!][!//
                                                [!VAR "MatchCounter" = "$MatchCounter + 1"!][!//
                                            [!ENDIF!][!//
                                        [!ELSE!][!//
                                            [!ERROR!][!//
                                                [!"concat('- The same Abstract Name ',($Name),' is used for different index values')"!][!//
                                            [!ENDERROR!][!//
                                        [!ENDIF!][!//
                                    [!ENDIF!][!//
                                [!ENDIF!][!//
                            [!ENDIF!][!//
                        [!ENDLOOP!][!//
                    [!ENDLOOP!][!//
                    [!VAR "$MatchConfigSet" = "$MatchConfigSet+1"!][!//
                [!ENDSELECT!][!//
                [!IF "$MatchCounter = 0"!][!//
                    [!VAR "PortPinIdVar"="PortPinId"!][!//
[!CODE!][!//
#define [!"$ConfigSetName"!]_[!"$ContName"!]_[!"node:name(.)"!]  [!"num:i($PortPinIdVar - 1)"!]
[!ENDCODE!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDLOOP!][!//
    [!ENDSELECT!][!//
[!ENDNOCODE!]

/**
* @brief Number of available pad modes options
* @details Platform constant
*/
#define PAD_MODE_OPTIONS_U8         ((uint8)[!"ecu:list('Port.PadModeNumber')[1]"!])
/**
* @brief Number of pad 16 blocks
* @details Platform constant
*/
#define PAD_16BLOCK_NO_U8           ((uint8)[!"ecu:list('Port.Pin16BlocksNo')[1]"!])
/**
 * @brief The last supported pin number
 */
#define PORT_MAX_PIN_PACKAGE_U16    ((uint16)[!"ecu:list('Port.MaxPinNumber')[1]"!])

/**
* @brief The maximum number of configured pins
*/
#define PORT_MAX_CONFIGURED_PADS_U16                        ((uint16)[!"num:i(count(PortConfigSet/PortContainer/*/PortPin/*))"!])

/**
 * @brief Number of UnUsed pin array
*/
[!NOCODE!]
    [!SELECT "PortConfigSet"!][!//
        [!VAR "MaxNoOfPins" = "num:i(ecu:list('Port.MaxPinNumber')[1] + 1)"!][!//
        [!VAR "UnimplementedPadsNumber" = "num:i(count(ecu:list('Port.UnimplementedPAD')))"!][!//
        [!VAR "UserPadsNumber" = "num:i(count(PortContainer/*/PortPin/*))"!][!//
        [!VAR "NoOfUntouchedPortPin" = "num:i(count(UnTouchedPortPin/*))"!][!//
        [!LOOP "PortContainer/*/PortPin/*"!][!//
            [!IF "contains(concat(',',string(ecu:get('Port.UnimplementedPAD')),','),concat(',',PortPinPcr,','))"!][!//
                [!VAR "UnimplementedPadsNumber"= "$UnimplementedPadsNumber - 1"!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!VAR "DefaultPinNumber" = "$UnimplementedPadsNumber + $UserPadsNumber"!][!//
        [!VAR "NoOfUnusedPins" = "num:i($MaxNoOfPins - $DefaultPinNumber - $NoOfUntouchedPortPin)"!][!//
[!CODE!][!//
#define PORT_MAX_UNUSED_PADS_U16   ([!"$NoOfUnusedPins"!]U)
[!ENDCODE!][!//
    [!ENDSELECT!][!//
[!ENDNOCODE!][!//

/**
* @brief Port driver Pre-Compile configuration switch
*/
[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile' and variant:size()<=1"!][!//
#define PORT_PRECOMPILE_SUPPORT     (STD_ON)
[!ELSE!][!//
#define PORT_PRECOMPILE_SUPPORT     (STD_OFF)
[!ENDIF!][!//

/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/
typedef struct
{
    uint32   u32PCR;                          /**< Content of Mscr Register */
    Port_PinDirectionType ePadDir;            /**< @brief Pad Data Direction */
    uint8    u8PDO;                           /**< Pad Data Output */
} Port_UnUsedPinConfigType;

/**
* @brief   Single pin configuration.
* @details This structure contains all configuration parameters of a single pin
*          identified by @p SIUPin.
*/
typedef struct
{
    uint16 Pin;                               /**< @brief Index of the pin's Mscr */
    uint32 u32PCR;                            /**< @brief Pad Control Register */
    uint8 u8PDO;                              /**< @brief Pad Data Output */
    Port_PinDirectionType ePadDir;            /**< @brief Pad Data Direction */
    boolean bGPIO;                            /**< @brief GPIO initial mode*/
    boolean bDC;                              /**< @brief Direction changebility*/
    boolean bMC;                              /**< @brief Mode changebility*/
} Port_PinConfigType;

/**
* @brief   Structure needed by @p Port_Init().
* @details The structure @p Port_ConfigType is a type for the external data
*          structure containing the initialization data for the PORT Driver.
* @note    The user must use the symbolic names defined in the configuration
*          tool.
*
* @implements Port_ConfigType_struct
*/
typedef struct
{
    uint16 u16NumPins;                                                       /**< @brief Number of used pads (to be configured) */
    uint16 u16NumUnusedPins;                                                 /**< @brief Number of unused pads */
    const uint16 * pUnusedPads;                                              /**< @brief Unused pad id's array */
    const Port_UnUsedPinConfigType * pUnusedPadConfig;                       /**< @brief Unused pad configuration */
    const Port_PinConfigType * pUsedPadConfig;                               /**< @brief Used pads data configuration */
    uint8  u8NumDigitalFilterPorts;                                          /**< @brief Number of configured digital filter ports */
    const Port_Ci_Port_Ip_DigitalFilterConfigType * pDigitalFilterConfig;    /**< @brief Digital filter ports configuration */
    const uint32 *pau32Port_PinToPartitionMap;                               /**< @brief Pointer to pin partition mapping */
    const uint8 *pau8Port_PartitionList;                                     /**< @brief Pointer to used partitions */
    const Port_Ci_Port_Ip_PinSettingsConfig *IpConfigPtr;                    /**< @brief Ip configuration */
} Port_ConfigType;

/*=================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief External declaration of the Port pin description array
*/
extern const uint16 Port_au16PinDescription[[!"ecu:list('Port.PadModeNumber')[1]"!]][[!"ecu:list('Port.Pin16BlocksNo')[1]"!]];

#endif

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"

/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PORT_CFG_H */

/* End of File */
[!NOCODE!][!//
[!ENDNOCODE!][!//
[!ENDCODE!][!//
