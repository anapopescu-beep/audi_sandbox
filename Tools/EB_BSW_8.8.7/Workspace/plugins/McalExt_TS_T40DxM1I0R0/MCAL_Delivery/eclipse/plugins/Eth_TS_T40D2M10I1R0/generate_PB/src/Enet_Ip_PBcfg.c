/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : ENET
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

#ifndef ENET_IP_PBCFG_C
#define ENET_IP_PBCFG_C

/**
*   @file
*
*   @addtogroup ENET_DRIVER_CONFIGURATION ENET Driver Configuration
*   @{
*/
 
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Enet_Ip_Types.h"
#include "Enet_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C                     43
#define ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C      4
#define ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C      4
#define ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C   0
#define ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C              1
#define ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C              0
#define ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C              1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Enet_Ip_Types.h */
#if (ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C != ENET_IP_TYPES_VENDOR_ID)
    #error "Enet_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Enet_Ip_Types.h have different vendor ids"
#endif
#if ((ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C    != ENET_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C    != ENET_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C != ENET_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Enet_Ip_Types.h are different"
#endif
#if ((ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C != ENET_IP_TYPES_SW_MAJOR_VERSION) || \
     (ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C != ENET_IP_TYPES_SW_MINOR_VERSION) || \
     (ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C != ENET_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Enet_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Enet_Ip_Types.h are different"
#endif

/* Checks against Enet_Ip_Cfg.h */
#if (ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C != ENET_IP_CFG_VENDOR_ID)
    #error "Enet_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Enet_Ip_Cfg.h have different vendor ids"
#endif
#if ((ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C    != ENET_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C    != ENET_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C != ENET_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Enet_Ip_Cfg.h are different"
#endif
#if ((ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C != ENET_IP_CFG_SW_MAJOR_VERSION) || \
     (ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C != ENET_IP_CFG_SW_MINOR_VERSION) || \
     (ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C != ENET_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Enet_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Enet_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
[!MACRO "GetPhysicalAddress"!][!//
[!NOCODE!]
    [!VAR "PhysAddr" = "'00:00:00:00:00:00'"!]
    [!IF "node:exists(EthCtrlPhyAddress)"!]
        [!VAR "PhysAddr" = "node:value(EthCtrlPhyAddress)"!]
    [!ENDIF!]

    [!FOR "AddrByteIdx" = "1" TO "6"!]
        [!CODE!][!"concat('0x', text:split($PhysAddr, ':')[num:i($AddrByteIdx)])"!]U[!IF "$AddrByteIdx < 6"!], [!ENDIF!][!ENDCODE!]
    [!ENDFOR!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetMacLayerType"!][!//
[!NOCODE!]
    [!VAR "MacLayer" = "string(null)"!]

    [!IF "substring-after(EthCtrlMacLayerType, 'ETH_MAC_LAYER_TYPE_') = 'XMII'"!]
        [!IF "EthCtrlMacLayerSubType = 'STANDARD'"!]
            [!VAR "MacLayer" = "'MII'"!]
        [!ELSEIF "EthCtrlMacLayerSubType = 'SERIAL'"!]
            [!VAR "MacLayer" = "'SMII'"!]
        [!ELSEIF "EthCtrlMacLayerSubType = 'REDUCED'"!]
            [!VAR "MacLayer" = "'RMII'"!]
        [!ENDIF!]
    [!ELSEIF "substring-after(EthCtrlMacLayerType, 'ETH_MAC_LAYER_TYPE_') = 'XGMII'"!]
        [!IF "EthCtrlMacLayerSubType = 'STANDARD'"!]
            [!VAR "MacLayer" = "'GMII'"!]
        [!ELSEIF "EthCtrlMacLayerSubType = 'SERIAL'"!]
            [!VAR "MacLayer" = "'SGMII'"!]
        [!ELSEIF "EthCtrlMacLayerSubType = 'REDUCED'"!]
            [!VAR "MacLayer" = "'RGMII'"!]
        [!ENDIF!]
    [!ENDIF!]

    [!IF "$MacLayer = string(null)"!][!ERROR!]Unknown or unsupported media independent interface! ([!"EthCtrlMacLayerType"!], [!"EthCtrlMacLayerSubType"!])[!ENDERROR!][!ENDIF!]
    [!CODE!][!"$MacLayer"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "GetRxConfigMask"!][!//
[!NOCODE!]
    [!VAR "RxCfgMask" = "'0U'"!]

    [!LOOP "EthCtrlVendorSpecific/EthCtrlConfigReceptionOptions/*"!]
        [!IF "node:value(.) = 'true'"!]
            [!VAR "RxCfgMask" = "concat($RxCfgMask, ' | (uint32)', @name)"!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!CODE!][!"$RxCfgMask"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetInterruptConfigMask"!][!//
[!NOCODE!]
    [!VAR "IntCfgMask" = "'0U'"!]

    [!IF "EthCtrlVendorSpecific/EthCtrlConfigInterrupts/EthCtrlEnableErrorInterrupt = 'true'"!]
        [!VAR "IntCfgMask" = "concat($IntCfgMask, ' | (uint32)', 'ENET_BABR_INTERRUPT | (uint32)ENET_BABT_INTERRUPT | (uint32)ENET_UNDERRUN_INTERRUPT')"!]
        [!VAR "IntCfgMask" = "concat($IntCfgMask, ' | (uint32)', 'ENET_EBERR_INTERRUPT | (uint32)ENET_LATE_COLLISION_INTERRUPT | (uint32)ENET_RETRY_LIMIT_INTERRUPT')"!]
        [!VAR "IntCfgMask" = "concat($IntCfgMask, ' | (uint32)', 'ENET_PAYLOAD_RX_INTERRUPT')"!]
    [!ENDIF!]
    
    [!IF "EthCtrlVendorSpecific/EthCtrlConfigInterrupts/EthCtrlEnableWakeUpInterrupt = 'true'"!]
        [!VAR "IntCfgMask" = "concat($IntCfgMask, ' | (uint32)', 'ENET_WAKEUP_INTERRUPT')"!]
    [!ENDIF!]
    
    [!IF "EthCtrlVendorSpecific/EthCtrlConfigInterrupts/EthCtrlEnableTimerInterrupt = 'true'"!]
        [!VAR "IntCfgMask" = "concat($IntCfgMask, ' | (uint32)', 'ENET_TS_TIMER_INTERRUPT')"!]
    [!ENDIF!]
    
    [!IF "EthCtrlEnableTxInterrupt = 'true'"!]
        [!VAR "IntCfgMask" = "concat($IntCfgMask, ' | (uint32)', 'ENET_TX_FRAME_INTERRUPT | (uint32)ENET_TX_BUFFER_INTERRUPT')"!]
    [!ENDIF!]
    
    [!IF "EthCtrlEnableRxInterrupt = 'true'"!]
        [!VAR "IntCfgMask" = "concat($IntCfgMask, ' | (uint32)', 'ENET_RX_FRAME_INTERRUPT | (uint32)ENET_RX_BUFFER_INTERRUPT')"!]
    [!ENDIF!]
    [!CODE!][!"$IntCfgMask"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetRxAccelerConfig"!][!//
[!NOCODE!]
    [!VAR "RxAccelerCfgMask" = "'0U'"!]

    [!LOOP "EthCtrlVendorSpecific/EthCtrlConfigRxAcceleratorOptions/*"!]
        [!IF "node:value(.) = 'true'"!]
            [!VAR "RxAccelerCfgMask" = "concat($RxAccelerCfgMask, ' | (uint32)', @name)"!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!CODE!][!"$RxAccelerCfgMask"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetTxAccelerConfig"!][!//
[!NOCODE!]
    [!VAR "TxAccelerCfgMask" = "'0U'"!]

    [!LOOP "EthCtrlVendorSpecific/EthCtrlConfigTxAcceleratorOptions/*"!]
        [!IF "node:value(.) = 'true'"!]
            [!VAR "TxAccelerCfgMask" = "concat($TxAccelerCfgMask, ' | (uint32)', @name)"!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!CODE!][!"$TxAccelerCfgMask"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetTxConfigMask"!][!//
[!NOCODE!]
    [!VAR "TxCfgMask" = "'0U'"!]

    [!LOOP "EthCtrlVendorSpecific/EthCtrlConfigTransmissionOptions/*"!]
        [!IF "node:value(.) = 'true'"!]
            [!VAR "TxCfgMask" = "concat($TxCfgMask, ' | (uint32)', @name)"!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!CODE!][!"$TxCfgMask"!][!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define ENET_ADDR_LENGTH        (6U)

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"

/*! @brief Channel callbacks external declarations */
[!NOCODE!]
[!IF "EthConfigSet/EthCtrlConfig/*/EthCtrlEnableRxInterrupt"!]
[!CODE!]extern void Eth_RxIrqCallback(uint8 instance, uint8 channel);[!CR!][!ENDCODE!]
[!ENDIF!]

[!IF "EthConfigSet/EthCtrlConfig/*/EthCtrlEnableTxInterrupt"!]
[!CODE!]extern void Eth_TxIrqCallback(uint8 instance, uint8 channel);[!CR!][!ENDCODE!]
[!ENDIF!]

[!IF "EthGeneral/EthGlobalTimeSupport"!]
[!CODE!]extern void Eth_Ipw_TimeStampCallback(uint8 instance);[!CR!][!ENDCODE!]
[!ENDIF!]

[!IF "node:containsValue(EthConfigSet/EthCtrlConfig/*/EthCtrlVendorSpecific/EthCtrlConfigInterrupts/*, 'true')"!]
[!CODE!]extern void Eth_Ipw_EventIrqCallback(uint8 instance, Enet_Ip_EventType error);[!CR!][!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]


#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"

/*==================================================================================================
*                                      BUFFER DECLARATIONS
==================================================================================================*/
#define ETH_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_MemMap.h"

[!NOCODE!]
    [!LOOP "node:order(EthConfigSet/EthCtrlConfig/*, 'EthCtrlIdx')"!]
        [!VAR "CtrlIdx" = "node:value(EthCtrlIdx)"!]

        [!LOOP "node:order(EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*, 'EthCtrlConfigIngressFifoIdx')"!]
            [!VAR "RingIdx" = "node:value(EthCtrlConfigIngressFifoIdx)"!]
[!CODE!]
extern Enet_Ip_BufferDescriptorType ENET_[!"num:i($CtrlIdx)"!]_RxRing_[!"num:i($RingIdx)"!]_DescBuffer[];
extern uint8 ENET_[!"num:i($CtrlIdx)"!]_RxRing_[!"num:i($RingIdx)"!]_DataBuffer[];
[!ENDCODE!]
        [!ENDLOOP!][!// RingIdx

        [!LOOP "node:order(EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*, 'EthCtrlConfigEgressFifoIdx')"!]
            [!VAR "RingIdx" = "node:value(EthCtrlConfigEgressFifoIdx)"!]
[!CODE!]
extern Enet_Ip_BufferDescriptorType ENET_[!"num:i($CtrlIdx)"!]_TxRing_[!"num:i($RingIdx)"!]_DescBuffer[];
extern uint8 ENET_[!"num:i($CtrlIdx)"!]_TxRing_[!"num:i($RingIdx)"!]_DataBuffer[];
[!ENDCODE!]
        [!ENDLOOP!][!// RingIdx

    [!ENDLOOP!][!// CtrlIdx
[!ENDNOCODE!]

#define ETH_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_MemMap.h"

/*==================================================================================================
*                                   STATE STRUCTURE DECLARATIONS
==================================================================================================*/
#define ETH_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_MemMap.h"

[!NOCODE!]
    [!LOOP "node:order(EthConfigSet/EthCtrlConfig/*, 'EthCtrlIdx')"!]
        [!VAR "CtrlIdx" = "node:value(EthCtrlIdx)"!]
[!CODE!]
extern Enet_Ip_StateType ENET_[!"num:i($CtrlIdx)"!]_StateStructure;
[!ENDCODE!]
    [!ENDLOOP!][!// CtrlIdx
[!ENDNOCODE!]

#define ETH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_MemMap.h"

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ETH_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_MemMap.h"


/*! @brief The MAC address(es) of the configured controller(s) */
[!NOCODE!]
    [!VAR "NumOfEthCtrls" = "count(EthConfigSet/EthCtrlConfig/*)"!]
    [!IF "$NumOfEthCtrls > 0"!]
        [!LOOP "node:order(EthConfigSet/EthCtrlConfig/*, 'EthCtrlIdx')"!]
[!CODE!][!//
static const uint8 ENET_[!"num:i(EthCtrlIdx)"!]_au8MacAddrPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][ENET_ADDR_LENGTH] = { [!CALL "GetPhysicalAddress"!] };
[!ENDCODE!]
        [!ENDLOOP!][!// EthCtrlConfig/*
    [!ENDIF!][!// $NumOfEthCtrls > 0
[!ENDNOCODE!]

[!NOCODE!]
    [!VAR "NumOfEthCtrls" = "count(EthConfigSet/EthCtrlConfig/*)"!]
    [!IF "$NumOfEthCtrls > 0"!]
        [!LOOP "node:order(EthConfigSet/EthCtrlConfig/*, 'EthCtrlIdx')"!]
            [!VAR "CtrlIdx" = "node:value(EthCtrlIdx)"!]
            [!VAR "NumOfRxFifos" = "count(EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*)"!]
            [!IF "$NumOfRxFifos > 0"!]
[!CODE!]
/*! @brief Reception ring configuration structures */
static const Enet_Ip_BufferConfigType ENET_[!"num:i($CtrlIdx)"!]_aRxRingConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($NumOfRxFifos)"!]U] =
{
[!ENDCODE!]
    [!VAR "FirstFifo" = "1"!]
    [!LOOP "node:order(EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*, 'EthCtrlConfigIngressFifoIdx')"!]
[!CODE!][!//
    [!IF "num:i($FirstFifo)=0"!],[!ENDIF!][!VAR "FirstFifo"="0"!]
    /* The configuration structure for Rx Ring [!"num:i(EthCtrlConfigIngressFifoIdx)"!] */
    {
        /*.ringDesc = */ENET_[!"num:i($CtrlIdx)"!]_RxRing_[!"num:i(EthCtrlConfigIngressFifoIdx)"!]_DescBuffer,
        /*.callback = */[!IF "../../../EthCtrlEnableRxInterrupt"!]Eth_RxIrqCallback[!ELSE!]NULL_PTR[!ENDIF!],
        /*.buffer = */ENET_[!"num:i($CtrlIdx)"!]_RxRing_[!"num:i(EthCtrlConfigIngressFifoIdx)"!]_DataBuffer,
        /*.interrupts = */(uint32)[!IF "../../../EthCtrlEnableRxInterrupt"!]ENET_RX_FRAME_INTERRUPT[!ELSE!]0U[!ENDIF!],
        /*.bufferLen = */[!"num:i(EthCtrlConfigIngressFifoBufLenByte)"!]U,
        /*.ringSize = */[!"num:i(EthCtrlConfigIngressFifoBufTotal)"!]U
    }
[!ENDCODE!]
    [!ENDLOOP!][!// EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*
[!CODE!]
};
[!ENDCODE!]
            [!ENDIF!][!// $NumOfRxFifos > 0
        [!ENDLOOP!][!// EthCtrlConfig/*
    [!ENDIF!][!// $NumOfEthCtrls > 0
[!ENDNOCODE!]


[!NOCODE!]
    [!VAR "NumOfEthCtrls" = "count(EthConfigSet/EthCtrlConfig/*)"!]
    [!IF "$NumOfEthCtrls > 0"!]
        [!LOOP "node:order(EthConfigSet/EthCtrlConfig/*, 'EthCtrlIdx')"!]
            [!VAR "CtrlIdx" = "node:value(EthCtrlIdx)"!]
            [!VAR "NumOfTxFifos" = "count(EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*)"!]
            [!IF "$NumOfTxFifos > 0"!]
[!CODE!]
/*! @brief Transmission ring configuration structures */
static const Enet_Ip_BufferConfigType ENET_[!"num:i($CtrlIdx)"!]_aTxRingConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($NumOfTxFifos)"!]U] =
{
[!ENDCODE!]
    [!VAR "FirstFifo" = "1"!]
    [!LOOP "node:order(EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*, 'EthCtrlConfigEgressFifoIdx')"!]
[!CODE!][!//
    [!IF "num:i($FirstFifo)=0"!],[!ENDIF!][!VAR "FirstFifo"="0"!]
    /* The configuration structure for Tx Ring [!"num:i(EthCtrlConfigEgressFifoIdx)"!] */
    {
        /*.ringDesc = */ENET_[!"num:i($CtrlIdx)"!]_TxRing_[!"num:i(EthCtrlConfigEgressFifoIdx)"!]_DescBuffer,
        /*.callback = */[!IF "../../../EthCtrlEnableTxInterrupt"!]Eth_TxIrqCallback[!ELSE!]NULL_PTR[!ENDIF!],
        /*.buffer = */ENET_[!"num:i($CtrlIdx)"!]_TxRing_[!"num:i(EthCtrlConfigEgressFifoIdx)"!]_DataBuffer,
        /*.interrupts = */(uint32)[!IF "../../../EthCtrlEnableTxInterrupt"!]ENET_TX_FRAME_INTERRUPT[!ELSE!]0U[!ENDIF!],
        /*.bufferLen = */[!"num:i(EthCtrlConfigEgressFifoBufLenByte)"!]U,
        /*.ringSize = */[!"num:i(EthCtrlConfigEgressFifoBufTotal)"!]U
    }
[!ENDCODE!]
    [!ENDLOOP!][!// EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*
[!CODE!]
};
[!ENDCODE!]
            [!ENDIF!][!// $NumOfTxFifos > 0
        [!ENDLOOP!][!// EthCtrlConfig/*
    [!ENDIF!][!// $NumOfEthCtrls > 0
[!ENDNOCODE!]

/*! @brief Module configuration structure */
[!NOCODE!]
    [!VAR "NumOfEthCtrls" = "count(EthConfigSet/EthCtrlConfig/*)"!]
    [!IF "$NumOfEthCtrls > 0"!]
        [!LOOP "node:order(EthConfigSet/EthCtrlConfig/*, 'EthCtrlIdx')"!]
[!CODE!]
static const Enet_Ip_ConfigType ENET_[!"num:i(EthCtrlIdx)"!]_InitConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /*.rxRingCount = */[!"num:i(count(EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*))"!]U,
    /*.txRingCount = */[!"num:i(count(EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*))"!]U,
    /*.callback = */[!IF "../../../EthGeneral/EthGlobalTimeSupport"!]Eth_Ipw_TimeStampCallback[!ELSE!]NULL_PTR[!ENDIF!],
    /*.interrupts = */[!CALL "GetInterruptConfigMask"!],
    /*.callback = */[!IF "node:containsValue(EthCtrlVendorSpecific/EthCtrlConfigInterrupts/*, 'true')"!]Eth_Ipw_EventIrqCallback[!ELSE!]NULL_PTR[!ENDIF!],
    /*.maxFrameLen = */[!"num:i(EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthMaxFrameLength)"!]U,
    /*.miiMode = */ENET_[!CALL "GetMacLayerType"!]_MODE,
    /*.speed = */ENET_MII_SPEED_[!"substring-after(EthCtrlMacLayerSpeed, 'ETH_MAC_LAYER_SPEED_')"!],
    /*.duplex = */ENET_MII_[!"substring-after(EthCtrlVendorSpecific/EthCtrlConfigGeneral/EthDuplexMode, 'ETH_')"!],
    /*.rxConfig = */[!CALL "GetRxConfigMask"!],
    /*.txConfig = */[!CALL "GetTxConfigMask"!],
    /*.rxAccelerConfig = */[!CALL "GetRxAccelerConfig"!],
    /*.txAccelerConfig = */[!CALL "GetTxAccelerConfig"!],
    /*.enableCtrl = */FALSE
};
[!ENDCODE!]
        [!ENDLOOP!][!// EthCtrlConfig/*
    [!ENDIF!][!// $NumOfEthCtrls > 0
[!ENDNOCODE!]

#define ETH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_MemMap.h"

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define ETH_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_MemMap.h"

[!NOCODE!]
    [!VAR "NumOfEthCtrls" = "num:i(count(EthConfigSet/EthCtrlConfig/*))"!]
    [!IF "num:i($NumOfEthCtrls) > 0"!]
[!CODE!]
const Enet_CtrlConfigType Enet_aCtrlConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"$NumOfEthCtrls"!]U] =
{
[!ENDCODE!]
    [!VAR "FirstCtrl" = "1"!]
    [!LOOP "EthConfigSet/EthCtrlConfig/*"!]
        [!VAR "CtrlHwId"  = "num:i(EthCtrlIdx)"!]
[!CODE!][!//
    [!IF "num:i($FirstCtrl)=0"!],[!ENDIF!][!VAR "FirstCtrl"="0"!]
    /* The configuration structure for Enet_aCtrlConfig[[!"num:i(@index)"!]U] */
    {
        &ENET_[!"$CtrlHwId"!]_StateStructure,
        &ENET_[!"$CtrlHwId"!]_InitConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
        &ENET_[!"$CtrlHwId"!]_aRxRingConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][0U],
        &ENET_[!"$CtrlHwId"!]_aTxRingConfigPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][0U],
        &ENET_[!"$CtrlHwId"!]_au8MacAddrPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][0U]
    }
[!ENDCODE!]
    [!ENDLOOP!][!// EthCtrlConfig/*
[!CODE!][!//
};
[!ENDCODE!]
    [!ENDIF!][!// num:i($NumOfEthCtrls) > 0
[!ENDNOCODE!]

#define ETH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Eth_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ENET_IP_PBCFG_C */
