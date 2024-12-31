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

#ifndef ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_H
#define ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_H

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
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID                     43
#define ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION      4
#define ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION      4
#define ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION   0
#define ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION              1
#define ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION              0
#define ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION              1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
[!NOCODE!]
[!IF "var:defined('postBuildVariant')"!][!//
  [!VAR "postBuildVariantNameUnderscore" = "concat('_',$postBuildVariant)"!][!//
[!CODE!]#define ENET_CONFIG_[!"$postBuildVariant"!]_PB \[!CR!][!ENDCODE!]
[!ELSE!][!//
  [!VAR "postBuildVariantNameUnderscore" = "string(null)"!][!//
[!CODE!]#define ENET_CONFIG_PB \[!CR!][!ENDCODE!]
[!ENDIF!][!//
    [!CODE!][!WS "4"!]extern const Enet_CtrlConfigType Enet_aCtrlConfigPB[!"$postBuildVariantNameUnderscore"!][];[!ENDCODE!]
[!ENDNOCODE!]

/*! @brief Device instance number */
[!NOCODE!]
[!LOOP "EthConfigSet/EthCtrlConfig/*"!]
[!CODE!][!//
#ifndef INST_ENET_[!"num:i(EthCtrlIdx)"!]
    #define INST_ENET_[!"num:i(EthCtrlIdx)"!]    ([!"num:i(EthCtrlIdx)"!]U)
#elif (INST_ENET_[!"num:i(EthCtrlIdx)"!] != [!"num:i(EthCtrlIdx)"!])
    #error "[TPS_ECUC_06074] Invalid configuration due to symbolic name values"
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ENDNOCODE!]


/* Used for allocation of TX buffers */
[!NOCODE!]
[!LOOP "EthConfigSet/EthCtrlConfig/*"!]
    [!VAR "CtrlIdx" = "node:value(EthCtrlIdx)"!]
    [!LOOP "EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*"!]
        [!VAR "RingIdx" = "node:value(EthCtrlConfigEgressFifoIdx)"!]
[!CODE!][!//
#ifndef ENET_[!"num:i($CtrlIdx)"!]_TXRING_[!"num:i($RingIdx)"!]_DESCR
    #define ENET_[!"num:i($CtrlIdx)"!]_TXRING_[!"num:i($RingIdx)"!]_DESCR
#endif
#ifndef ENET_[!"num:i($CtrlIdx)"!]_TXRING_[!"num:i($RingIdx)"!]_DATA
    #define ENET_[!"num:i($CtrlIdx)"!]_TXRING_[!"num:i($RingIdx)"!]_DATA
#endif
[!ENDCODE!]
    [!ENDLOOP!]
[!ENDLOOP!]
[!ENDNOCODE!]

/* Used for allocation of RX buffers */
[!NOCODE!]
[!LOOP "EthConfigSet/EthCtrlConfig/*"!]
    [!VAR "CtrlIdx" = "node:value(EthCtrlIdx)"!]
    [!LOOP "EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*"!]
        [!VAR "RingIdx" = "node:value(EthCtrlConfigIngressFifoIdx)"!]
[!CODE!][!//
#ifndef ENET_[!"num:i($CtrlIdx)"!]_RXRING_[!"num:i($RingIdx)"!]_DESCR
    #define ENET_[!"num:i($CtrlIdx)"!]_RXRING_[!"num:i($RingIdx)"!]_DESCR
#endif
#ifndef ENET_[!"num:i($CtrlIdx)"!]_RXRING_[!"num:i($RingIdx)"!]_DATA
    #define ENET_[!"num:i($CtrlIdx)"!]_RXRING_[!"num:i($RingIdx)"!]_DATA
#endif
[!ENDCODE!]
    [!ENDLOOP!]
[!ENDLOOP!]
[!ENDNOCODE!]

/* Maximum number of configured buffers for a Tx Ring */
[!NOCODE!]
[!LOOP "EthConfigSet/EthCtrlConfig/*"!]
    [!VAR "MaxCtrlTxBuffersSupported" = "num:i(node:fallback('->num:max(EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*/EthCtrlConfigEgressFifoBufTotal)', 0))"!]
[!CODE!][!//
#ifndef ENET_[!"num:i(EthCtrlIdx)"!]_MAX_TXBUFF_SUPPORTED
    #define ENET_[!"num:i(EthCtrlIdx)"!]_MAX_TXBUFF_SUPPORTED    ([!"num:i($MaxCtrlTxBuffersSupported)"!]U)
#elif (ENET_[!"num:i(EthCtrlIdx)"!]_MAX_TXBUFF_SUPPORTED < [!"num:i($MaxCtrlTxBuffersSupported)"!])
    #undef ENET_[!"num:i(EthCtrlIdx)"!]_MAX_TXBUFF_SUPPORTED
    #define ENET_[!"num:i(EthCtrlIdx)"!]_MAX_TXBUFF_SUPPORTED    ([!"num:i($MaxCtrlTxBuffersSupported)"!]U) 
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ENDNOCODE!]

/* Maximum number of configured buffers for an Rx Ring */
[!NOCODE!]
[!LOOP "EthConfigSet/EthCtrlConfig/*"!]
    [!VAR "MaxCtrlRxBuffersSupported" = "num:i(node:fallback('->num:max(EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*/EthCtrlConfigIngressFifoBufTotal)', 0))"!]
[!CODE!][!//
#ifndef ENET_[!"num:i(EthCtrlIdx)"!]_MAX_RXBUFF_SUPPORTED
    #define ENET_[!"num:i(EthCtrlIdx)"!]_MAX_RXBUFF_SUPPORTED    ([!"num:i($MaxCtrlRxBuffersSupported)"!]U)
#elif (ENET_[!"num:i(EthCtrlIdx)"!]_MAX_RXBUFF_SUPPORTED < [!"num:i($MaxCtrlRxBuffersSupported)"!])
    #undef ENET_[!"num:i(EthCtrlIdx)"!]_MAX_RXBUFF_SUPPORTED
    #define ENET_[!"num:i(EthCtrlIdx)"!]_MAX_RXBUFF_SUPPORTED    ([!"num:i($MaxCtrlRxBuffersSupported)"!]U) 
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ENDNOCODE!]

/* Maximum length of a single buffer across all Tx Rings */
[!NOCODE!]
[!LOOP "EthConfigSet/EthCtrlConfig/*"!]
    [!VAR "MaxCtrlTxBufferLengthSupported" = "num:i(node:fallback('->num:max(EthCtrlConfigEgress/EthCtrlConfigEgressFifo/*/EthCtrlConfigEgressFifoBufLenByte)', 64))"!]
[!CODE!][!//
#ifndef ENET_[!"num:i(EthCtrlIdx)"!]_MAX_TXBUFFLEN_SUPPORTED
    #define ENET_[!"num:i(EthCtrlIdx)"!]_MAX_TXBUFFLEN_SUPPORTED    ([!"num:i($MaxCtrlTxBufferLengthSupported)"!]U)
#elif (ENET_[!"num:i(EthCtrlIdx)"!]_MAX_TXBUFFLEN_SUPPORTED < [!"num:i($MaxCtrlTxBufferLengthSupported)"!])
    #undef ENET_[!"num:i(EthCtrlIdx)"!]_MAX_TXBUFFLEN_SUPPORTED
    #define ENET_[!"num:i(EthCtrlIdx)"!]_MAX_TXBUFFLEN_SUPPORTED    ([!"num:i($MaxCtrlTxBufferLengthSupported)"!]U) 
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ENDNOCODE!]

/* Maximum length of a single buffer across all Rx Rings */
[!NOCODE!]
[!LOOP "EthConfigSet/EthCtrlConfig/*"!]
    [!VAR "MaxCtrlRxBufferLengthSupported" = "num:i(node:fallback('->num:max(EthCtrlConfigIngress/EthCtrlConfigIngressFifo/*/EthCtrlConfigIngressFifoBufLenByte)', 64))"!]
[!CODE!][!//
#ifndef ENET_[!"num:i(EthCtrlIdx)"!]_MAX_RXBUFFLEN_SUPPORTED
    #define ENET_[!"num:i(EthCtrlIdx)"!]_MAX_RXBUFFLEN_SUPPORTED    ([!"num:i($MaxCtrlRxBufferLengthSupported)"!]U)
#elif (ENET_[!"num:i(EthCtrlIdx)"!]_MAX_RXBUFFLEN_SUPPORTED < [!"num:i($MaxCtrlRxBufferLengthSupported)"!])
    #undef ENET_[!"num:i(EthCtrlIdx)"!]_MAX_RXBUFFLEN_SUPPORTED
    #define ENET_[!"num:i(EthCtrlIdx)"!]_MAX_RXBUFFLEN_SUPPORTED    ([!"num:i($MaxCtrlRxBufferLengthSupported)"!]U) 
#endif
[!ENDCODE!]
[!ENDLOOP!]
[!ENDNOCODE!]

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ENET_IP_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_H */

