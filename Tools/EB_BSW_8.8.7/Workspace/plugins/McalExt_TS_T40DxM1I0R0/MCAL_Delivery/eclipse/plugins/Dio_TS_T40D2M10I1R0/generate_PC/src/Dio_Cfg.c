[!CODE!][!//
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : GPIO
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
*   @file Dio_Cfg.c
*   @implements Dio_Cfg.c_Artifact
*
*   @addtogroup DIO_CFG
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

#include "Dio.h"

[!NOCODE!][!//
[!INCLUDE "Dio_VersionCheck_Src.m"!][!//
[!ENDNOCODE!][!//

#if (defined(DIO_PRECOMPILE_SUPPORT) || defined(DIO_LINKTIME_SUPPORT))
/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define DIO_VENDOR_ID_CFG_C                   43
#define DIO_AR_RELEASE_MAJOR_VERSION_CFG_C    4
#define DIO_AR_RELEASE_MINOR_VERSION_CFG_C    4
#define DIO_AR_RELEASE_REVISION_VERSION_CFG_C 0
#define DIO_SW_MAJOR_VERSION_CFG_C            1
#define DIO_SW_MINOR_VERSION_CFG_C            0
#define DIO_SW_PATCH_VERSION_CFG_C            1

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
#if (((DIO_AR_RELEASE_MAJOR_VERSION_CFG_C != DIO_AR_RELEASE_MAJOR_VERSION)  ||  \
      (DIO_AR_RELEASE_MINOR_VERSION_CFG_C != DIO_AR_RELEASE_MINOR_VERSION)) ||  \
      (DIO_AR_RELEASE_REVISION_VERSION_CFG_C != DIO_AR_RELEASE_REVISION_VERSION)\
    )
    #error "AutoSar Version Numbers of Dio_Cfg.c and Dio.h are different"
#endif
#if ((DIO_SW_MAJOR_VERSION_CFG_C != DIO_SW_MAJOR_VERSION) || \
     (DIO_SW_MINOR_VERSION_CFG_C != DIO_SW_MINOR_VERSION) || \
     (DIO_SW_PATCH_VERSION_CFG_C != DIO_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Dio_Cfg.c and Dio.h are different"
#endif
#if ((DIO_VENDOR_ID_CFG_C != DIO_VENDOR_ID))
    #error "VENDOR ID for Dio_Cfg.c and Dio.h is different"
#endif
/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
#define DIO_START_SEC_CONST_32
#include "Dio_MemMap.h"

[!SELECT "DioConfig"!][!//
/**
* @brief Array containing list of mapping channel for partition
*/
const uint32 Dio_au32ChannelToPartitionMap[DIO_CHANNEL_PARTITION_U16] =
{
[!NOCODE!][!//
[!FOR "x" = "0" TO "num:i(ecu:list('Dio.LastPinAvailable')[1])"!][!//
    [!VAR "CounterDioEcucPartitionRef"="num:i(count(../DioGeneral/DioEcucPartitionRef/*))"!][!//
    [!VAR "PartitionChannelValue"="0"!][!//
    [!VAR "GetThePartitionNumber"="0"!][!//
    [!LOOP "./DioPort/*"!][!//
        [!VAR "PortId" = "num:i(node:fallback(./DioPortId,0))"!][!//
        [!LOOP "./DioChannel/*"!][!//
            [!VAR "PortChannelId" = "num:i(node:fallback(./DioChannelId,0))"!][!//
            [!VAR "ChannelId" = "num:i(32*$PortId + $PortChannelId)"!][!//
            [!IF "$ChannelId = $x"!][!//
                [!LOOP "DioChannelEcucPartitionRef/*"!][!//
                    [!VAR "DioCrtPart" = "node:value(.)"!][!//
                    [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                        [!IF "$DioCrtPart = node:value(./OsAppEcucPartitionRef)"!][!//
                            [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                                [!VAR "GetThePartitionNumber"="node:value(./EcucCoreId)"!][!//
                                [!VAR "PartitionChannelValue"="bit:or($PartitionChannelValue,(bit:shl(1,$GetThePartitionNumber)))"!][!//
                            [!ENDSELECT!][!//
                        [!ENDIF!][!//
                    [!ENDLOOP!][!//
                [!ENDLOOP!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
    [!IF "$CounterDioEcucPartitionRef = 0"!][!//
        [!VAR "PartitionChannelValue"="1"!][!//
        [!VAR "CounterDioEcucPartitionRef"="num:i($CounterDioEcucPartitionRef + 1)"!][!//
    [!ENDIF!][!//
[!CODE!][!//
    (uint32)[!"num:inttohex($PartitionChannelValue, 16)"!][!IF "$x < num:i(ecu:list('Dio.LastPinAvailable')[1])"!],[!ENDIF!]
[!ENDCODE!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
};

/**
* @brief Array containing list of mapping port for partition
*/
const uint32 Dio_au32PortToPartitionMap[DIO_PORT_PARTITION_U16] =
{
[!NOCODE!][!//
[!FOR "x" = "0" TO "num:i(count(ecu:list('Dio.AvailablePortPinsForWrite'))-1)"!][!//
    [!VAR "CounterDioEcucPartitionRef"="num:i(count(../DioGeneral/DioEcucPartitionRef/*))"!][!//
    [!VAR "PartitionPortValue"="0"!][!//
    [!VAR "GetThePartitionNumber"="0"!][!//
    [!LOOP "./DioPort/*"!][!//
        [!IF "num:i(node:fallback(./DioPortId,0)) = $x"!][!//
            [!LOOP "DioPortEcucPartitionRef/*"!][!//
                [!VAR "DioCrtPart" = "node:value(.)"!][!//
                [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                    [!IF "$DioCrtPart = node:value(./OsAppEcucPartitionRef)"!][!//
                        [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                            [!VAR "GetThePartitionNumber"="node:value(./EcucCoreId)"!][!//
                            [!VAR "PartitionPortValue"="bit:or($PartitionPortValue,(bit:shl(1,$GetThePartitionNumber)))"!][!//
                        [!ENDSELECT!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
            [!ENDLOOP!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$CounterDioEcucPartitionRef = 0"!][!//
        [!VAR "PartitionPortValue"="1"!][!//
        [!VAR "CounterDioEcucPartitionRef"="num:i($CounterDioEcucPartitionRef + 1)"!][!//
    [!ENDIF!][!//
[!CODE!][!//
    (uint32)[!"num:inttohex($PartitionPortValue, 16)"!][!IF "$x < num:i(count(ecu:list('Dio.AvailablePortPinsForWrite'))-1)"!],[!ENDIF!]
[!ENDCODE!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
};

[!ENDSELECT!][!//

/**
* @brief          Platform implemented port pins representation.
* @details        Array of bit maps reflecting the available pins in each port.
*                 The number of elements in the array corresponds to the number of
*                 ports implemented in the platform package. Rightmost bit of each
*                 array element corresponds to channel 0 of the associated port,
*                 while leftmost bit of each array element corresponds to channel 31
*                 of the associated port. A 0 bit means that the correspondent channel
*                 is not available in the platform package, while a bit of 1 means
*                 that the correspondent channel is available in the platform package.
*
* @api
*/
[!VAR "NumPorts"="count(ecu:list('Dio.AvailablePortPinsForWrite'))"!][!//
const Dio_PortLevelType Dio_aAvailablePinsForWrite[DIO_NUM_PORTS_U16] =
{
[!FOR "Loop" = "1" TO "$NumPorts"!][!//
    (Dio_PortLevelType)[!"ecu:list('Dio.AvailablePortPinsForWrite')[num:dectoint($Loop)]"!]UL[!//
[!IF "$Loop < $NumPorts "!],[!ENDIF!]
[!ENDFOR!][!//
};

[!VAR "NumPorts"="count(ecu:list('Dio.AvailablePortPinsForRead'))"!][!//
const Dio_PortLevelType Dio_aAvailablePinsForRead[DIO_NUM_PORTS_U16] =
{
[!FOR "Loop" = "1" TO "$NumPorts"!][!//
    (Dio_PortLevelType)[!"ecu:list('Dio.AvailablePortPinsForRead')[num:dectoint($Loop)]"!]UL[!//
[!IF "$Loop < $NumPorts "!],[!ENDIF!]
[!ENDFOR!][!//
};

[!//
[!MACRO "reverse_bits"!][!//
[!NOCODE!]
    [!VAR "Orig_mask"="DioPortMask"!]
    [!VAR "Orig_offset"="DioPortOffset"!]
    [!IF "../../../../../DioGeneral/DioReversePortBits"!]
        [!VAR "Reversed_mask"="0"!]
        [!VAR "Found_1"="0"!]
        [!FOR "Loop" = "0" TO "31"!]
            [!VAR "crt_bit" = "bit:shr($Orig_mask,$Loop)"!]
            [!VAR "crt_bit"="bit:and($crt_bit, 1)"!]
            [!VAR "Reversed_mask"="bit:or($Reversed_mask,$crt_bit)"!]
            [!IF "$Loop != 31"!][!//
                [!VAR "Reversed_mask"="bit:shl($Reversed_mask, 1)"!]
            [!ENDIF!]
            [!IF "$Found_1=1 and $crt_bit=0"!]
                [!VAR "right_bits"="$Loop"!]
                [!VAR "Found_1"="0"!]
            [!ENDIF!]
            [!IF "$crt_bit = 1"!]
                [!VAR "Found_1"="1"!]
            [!ENDIF!][!//
        [!ENDFOR!]
    [!ELSE!]
        [!VAR "Reversed_mask"="DioPortMask"!]
    [!ENDIF!]
    [!VAR "Reversed_offset"="DioPortOffset"!]
[!ENDNOCODE!][!//
(uint8)[!"num:inttohex($Reversed_offset,2)"!], (Dio_PortLevelType)[!"num:inttohex($Reversed_mask,8)"!]UL}[!//
[!ENDMACRO!][!//

#define DIO_STOP_SEC_CONST_32
#include "Dio_MemMap.h"

#define DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dio_MemMap.h"

[!SELECT "DioConfig"!][!//
/* ========== [!"as:name(.)"!] ========== */
[!VAR "numChannelGroupsInConfig" = "count(DioPort/*/DioChannelGroup/*)"!][!//
/**
* @brief          Data structure for configuration [!"as:name(.)"!].
*/
[!INDENT "0"!][!//
const Dio_ConfigType Dio_Config =
{
[!INDENT "4"!][!//
(uint8)[!"num:inttohex($numChannelGroupsInConfig)"!],
[!IF "$numChannelGroupsInConfig != 0"!][!//
    &[!"as:name(.)"!]_aChannelGroupList[0],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
Dio_au32ChannelToPartitionMap,
Dio_au32PortToPartitionMap
[!ENDINDENT!][!//
};

[!IF "$numChannelGroupsInConfig != 0"!][!//
[!VAR "nameConfigGroups" = "as:name(.)"!][!//
/**
* @brief          List of channel groups in configuration [!"as:name(.)"!].
*/
const Dio_ChannelGroupType [!"as:name(.)"!]_aChannelGroupList[[!"num:dectoint($numChannelGroupsInConfig)"!]] =
{
[!INDENT "4"!][!//
[!VAR "i" = "0"!][!//
[!LOOP "DioPort/*"!][!//
    [!LOOP "DioChannelGroup/*"!][!//
        { DioConf_DioPort_[!"node:name(./../..)"!], [!CALL "reverse_bits"!][!//
        [!VAR "i"="$i+1"!][!//
        [!IF "$i != $numChannelGroupsInConfig"!],[!ENDIF!]
    [!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDINDENT!][!//
};[!//

[!NOCODE!][!//
[!VAR "maxPartition" = "num:i(0)"!][!//
[!IF "node:value(../DioGeneral/DioMulticoreSupport)='true'"!]
    [!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!][!//
        [!VAR "maxPartition" = "num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!IF "$maxPartition = 0"!][!//
    [!VAR "maxPartition" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/**
* @brief          List of channel groups mapping with partition in configuration [!"as:name(.)"!].
*/
const Dio_ChannelGroupType * const Dio_pxChannelGroupsListForEachPartition[[!"num:i($maxPartition)"!]][[!"num:i($numChannelGroupsInConfig)"!]] =
{
[!INDENT "4"!][!//
[!VAR "CounterDioEcucPartitionRef"="num:i(count(../DioGeneral/DioEcucPartitionRef/*))"!][!//
[!FOR "x" = "0" TO "num:i($maxPartition - 1)"!][!//
{
    [!VAR "ChannelGroupCounter" = "0"!][!//
    [!LOOP "DioPort/*/DioChannelGroup/*"!][!//
        [!VAR "Counter" = "0"!][!//
        [!LOOP "DioChannelGroupEcucPartitionRef/*"!][!//
            [!VAR "DioCrtPart" = "node:value(.)"!][!//
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                [!IF "$DioCrtPart = node:value(./OsAppEcucPartitionRef)"!][!//
                    [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                        [!IF "$x = node:value(./EcucCoreId)"!][!//
                            [!VAR "Counter" = "$Counter + 1"!][!//
                        [!ENDIF!][!//
                    [!ENDSELECT!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDLOOP!][!//
        [!IF "$CounterDioEcucPartitionRef = 0"!][!//
            &[!"$nameConfigGroups"!]_aChannelGroupList[[!"num:i($ChannelGroupCounter)"!]][!IF "$ChannelGroupCounter < num:i($numChannelGroupsInConfig - 1)"!],[!ENDIF!]
        [!ELSE!][!//
            [!IF "$Counter = 0"!][!//
                NULL_PTR[!IF "$ChannelGroupCounter < num:i($numChannelGroupsInConfig - 1)"!],[!ENDIF!]
            [!ELSE!][!//
                &[!"$nameConfigGroups"!]_aChannelGroupList[[!"num:i($ChannelGroupCounter)"!]][!IF "$ChannelGroupCounter < num:i($numChannelGroupsInConfig - 1)"!],[!ENDIF!]
            [!ENDIF!][!//
        [!ENDIF!][!//
        [!VAR "ChannelGroupCounter" = "$ChannelGroupCounter + 1"!][!//
    [!ENDLOOP!][!//
    [!VAR "CounterDioEcucPartitionRef"="num:i($CounterDioEcucPartitionRef + 1)"!][!//
}[!IF "$x < ($maxPartition -1)"!],[!ENDIF!]
[!ENDFOR!][!//
[!ENDINDENT!][!//
};
[!//
[!ENDIF!][!//
[!ENDINDENT!][!//
[!ENDSELECT!][!//
#define DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dio_MemMap.h"

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

#endif /* (defined(DIO_PRECOMPILE_SUPPORT) || defined(DIO_LINKTIME_SUPPORT))  */

#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!][!//
