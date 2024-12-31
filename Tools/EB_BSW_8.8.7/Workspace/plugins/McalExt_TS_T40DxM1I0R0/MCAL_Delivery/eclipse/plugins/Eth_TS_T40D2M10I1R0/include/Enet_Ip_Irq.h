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
 
#ifndef ENET_IP_IRQ_H
#define ENET_IP_IRQ_H

/**
*   @file
*
*   @addtogroup ENET_DRIVER ENET Driver
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif
 
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Enet_Ip_Features.h"
#include "OsIf.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ENET_IP_IRQ_VENDOR_ID                      43
#define ENET_IP_IRQ_AR_RELEASE_MAJOR_VERSION       4
#define ENET_IP_IRQ_AR_RELEASE_MINOR_VERSION       4
#define ENET_IP_IRQ_AR_RELEASE_REVISION_VERSION    0
#define ENET_IP_IRQ_SW_MAJOR_VERSION               1
#define ENET_IP_IRQ_SW_MINOR_VERSION               0
#define ENET_IP_IRQ_SW_PATCH_VERSION               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Enet_Ip_Features.h */
#if (ENET_IP_IRQ_VENDOR_ID != ENET_IP_FEATURES_VENDOR_ID)
    #error "Enet_Ip_Irq.h and Enet_Ip_Features.h have different vendor ids"
#endif
#if (( ENET_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != ENET_IP_FEATURES_AR_RELEASE_MAJOR_VERSION) || \
     ( ENET_IP_IRQ_AR_RELEASE_MINOR_VERSION    != ENET_IP_FEATURES_AR_RELEASE_MINOR_VERSION) || \
     ( ENET_IP_IRQ_AR_RELEASE_REVISION_VERSION != ENET_IP_FEATURES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip_Irq.h and Enet_Ip_Features.h are different"
#endif
#if (( ENET_IP_IRQ_SW_MAJOR_VERSION != ENET_IP_FEATURES_SW_MAJOR_VERSION) || \
     ( ENET_IP_IRQ_SW_MINOR_VERSION != ENET_IP_FEATURES_SW_MINOR_VERSION) || \
     ( ENET_IP_IRQ_SW_PATCH_VERSION != ENET_IP_FEATURES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Enet_Ip_Irq.h and Enet_Ip_Features.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against OsIf.h */
    #if (( ENET_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        ( ENET_IP_IRQ_AR_RELEASE_MINOR_VERSION     != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Enet_Ip_Irq.h and OsIf.h are different"
    #endif
#endif

/*******************************************************************************
 * API
 ******************************************************************************/
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"

#if (FEATURE_ENET_NUM_INSTANCES > 0U)
    
    #if (FEATURE_ENET_NUM_RINGS > 0U)
        
    ISR(ENET0_RING0_TX_IRQHandler);
    ISR(ENET0_RING0_RX_IRQHandler);
    ISR(ENET0_ERR_IRQHandler);
  #if FEATURE_ENET_HAS_SLEEP_WAKEUP
    ISR(ENET0_WAKEUP_IRQHandler);
  #endif
    ISR(ENET0_TIMESTAMP_IRQHandler);
    
    #endif /* (FEATURE_ENET_NUM_RINGS > 0U) */

#endif /* (FEATURE_ENET_NUM_INSTANCES > 0U) */

#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ENET_IP_IRQ_H */
