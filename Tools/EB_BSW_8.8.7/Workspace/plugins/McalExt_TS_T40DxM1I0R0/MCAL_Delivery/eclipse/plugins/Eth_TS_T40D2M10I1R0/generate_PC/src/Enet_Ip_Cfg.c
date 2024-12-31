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

#ifndef ENET_IP_CFG_C
#define ENET_IP_CFG_C

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
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ENET_IP_CFG_VENDOR_ID_C                     43
#define ENET_IP_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define ENET_IP_CFG_AR_RELEASE_MINOR_VERSION_C      4
#define ENET_IP_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define ENET_IP_CFG_SW_MAJOR_VERSION_C              1
#define ENET_IP_CFG_SW_MINOR_VERSION_C              0
#define ENET_IP_CFG_SW_PATCH_VERSION_C              1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Enet_Ip_Types.h */
#if (ENET_IP_CFG_VENDOR_ID_C != ENET_IP_TYPES_VENDOR_ID)
    #error "Enet_Ip_Cfg.c and Enet_Ip_Types.h have different vendor ids"
#endif
#if ((ENET_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != ENET_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ENET_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != ENET_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ENET_IP_CFG_AR_RELEASE_REVISION_VERSION_C != ENET_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip_Cfg.h and Enet_Ip_Types.h are different"
#endif
#if ((ENET_IP_CFG_SW_MAJOR_VERSION_C != ENET_IP_TYPES_SW_MAJOR_VERSION) || \
     (ENET_IP_CFG_SW_MINOR_VERSION_C != ENET_IP_TYPES_SW_MINOR_VERSION) || \
     (ENET_IP_CFG_SW_PATCH_VERSION_C != ENET_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Enet_Ip_Cfg.c and Enet_Ip_Types.h are different"
#endif

/* Checks against Enet_Ip_Cfg.h */
#if (ENET_IP_CFG_VENDOR_ID_C != ENET_IP_CFG_VENDOR_ID)
    #error "Enet_Ip_Cfg.c and Enet_Ip_Cfg.h have different vendor ids"
#endif
#if ((ENET_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != ENET_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ENET_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != ENET_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ENET_IP_CFG_AR_RELEASE_REVISION_VERSION_C != ENET_IP_CFG_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip_Cfg.h and Enet_Ip_Cfg.h are different"
#endif
#if ((ENET_IP_CFG_SW_MAJOR_VERSION_C != ENET_IP_CFG_SW_MAJOR_VERSION) || \
     (ENET_IP_CFG_SW_MINOR_VERSION_C != ENET_IP_CFG_SW_MINOR_VERSION) || \
     (ENET_IP_CFG_SW_PATCH_VERSION_C != ENET_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Enet_Ip_Cfg.c and Enet_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((ENET_IP_CFG_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ENET_IP_CFG_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Enet_Ip_Cfg.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define ETH_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_MemMap.h"

[!NOCODE!]
    [!VAR "MaxCtrlIdx" = "count(ecu:list('Eth.EthGeneral.EthController.List')) - 1"!]
    [!FOR "CtrlIdx" = "0" TO "$MaxCtrlIdx"!]

        [!VAR "MaxCtrlRxRingIdx" = "ecu:list('Eth.EthCtrlConfig.ENET.MaxRxQueueSupport.List')[num:i($CtrlIdx + 1)] - 1"!]
        [!FOR "RingIdx" = "0" TO "$MaxCtrlRxRingIdx"!]
[!CODE!]
#ifdef ENET_[!"num:i($CtrlIdx)"!]_RXRING_[!"num:i($RingIdx)"!]_DESCR
    /*! @brief Reception buffer descriptors for Rx Ring [!"num:i($RingIdx)"!] */
    VAR_ALIGN(Enet_Ip_BufferDescriptorType ENET_[!"num:i($CtrlIdx)"!]_RxRing_[!"num:i($RingIdx)"!]_DescBuffer[ENET_[!"num:i($CtrlIdx)"!]_MAX_RXBUFF_SUPPORTED], FEATURE_ENET_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef ENET_[!"num:i($CtrlIdx)"!]_RXRING_[!"num:i($RingIdx)"!]_DATA
    /*! @brief Reception data buffers for Rx Ring [!"num:i($RingIdx)"!] */
    VAR_ALIGN(uint8 ENET_[!"num:i($CtrlIdx)"!]_RxRing_[!"num:i($RingIdx)"!]_DataBuffer[ENET_[!"num:i($CtrlIdx)"!]_MAX_RXBUFF_SUPPORTED * ENET_[!"num:i($CtrlIdx)"!]_MAX_RXBUFFLEN_SUPPORTED], FEATURE_ENET_BUFFDATA_ALIGNMENT_BYTES)
#endif
[!ENDCODE!]
        [!ENDFOR!][!// RingIdx

        [!VAR "MaxCtrlTxRingIdx" = "ecu:list('Eth.EthCtrlConfig.ENET.MaxTxQueueSupport.List')[num:i($CtrlIdx + 1)] - 1"!]
        [!FOR "RingIdx" = "0" TO "$MaxCtrlTxRingIdx"!]
[!CODE!]
#ifdef ENET_[!"num:i($CtrlIdx)"!]_TXRING_[!"num:i($RingIdx)"!]_DESCR
    /*! @brief Transmission buffer descriptors for Tx Ring [!"num:i($RingIdx)"!] */
    VAR_ALIGN(Enet_Ip_BufferDescriptorType ENET_[!"num:i($CtrlIdx)"!]_TxRing_[!"num:i($RingIdx)"!]_DescBuffer[ENET_[!"num:i($CtrlIdx)"!]_MAX_TXBUFF_SUPPORTED], FEATURE_ENET_BUFFDESCR_ALIGNMENT_BYTES)
#endif
#ifdef ENET_[!"num:i($CtrlIdx)"!]_TXRING_[!"num:i($RingIdx)"!]_DATA
    /*! @brief Transmission data buffers for Tx Ring [!"num:i($RingIdx)"!] */
    VAR_ALIGN(uint8 ENET_[!"num:i($CtrlIdx)"!]_TxRing_[!"num:i($RingIdx)"!]_DataBuffer[ENET_[!"num:i($CtrlIdx)"!]_MAX_TXBUFF_SUPPORTED * ENET_[!"num:i($CtrlIdx)"!]_MAX_TXBUFFLEN_SUPPORTED], FEATURE_ENET_BUFFDATA_ALIGNMENT_BYTES)
#endif
[!ENDCODE!]
        [!ENDFOR!][!// RingIdx

    [!ENDFOR!][!// CtrlIdx
[!ENDNOCODE!]

#define ETH_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Eth_MemMap.h"


#define ETH_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_MemMap.h"

/* Instance state structures used to hold driver runtime data */
[!NOCODE!]
    [!VAR "MaxCtrlIdx" = "count(ecu:list('Eth.EthGeneral.EthController.List')) - 1"!]
    [!FOR "CtrlIdx" = "0" TO "$MaxCtrlIdx"!]
[!CODE!]
#ifdef INST_ENET_[!"num:i($CtrlIdx)"!]
    Enet_Ip_StateType ENET_[!"num:i($CtrlIdx)"!]_StateStructure;
#endif
[!ENDCODE!]
    [!ENDFOR!][!// CtrlIdx
[!ENDNOCODE!][!//

#define ETH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
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

#endif /* ENET_IP_CFG_C */
