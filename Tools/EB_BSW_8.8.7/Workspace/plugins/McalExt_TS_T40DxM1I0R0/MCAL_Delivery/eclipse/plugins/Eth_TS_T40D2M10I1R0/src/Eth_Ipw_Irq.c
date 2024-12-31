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

/**
*   @file
*
*   @addtogroup ETH_DRIVER Ethernet Driver
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
#include "Eth_Ipw.h"

#include "Enet_Ip_Types.h"

#if (STD_ON == ETH_DEM_EVENT_DETECT)
#include "Dem.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_IPW_IRQ_VENDOR_ID_C                      43
#define ETH_IPW_IRQ_MODULE_ID_C                      88
#define ETH_IPW_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_IPW_IRQ_AR_RELEASE_MINOR_VERSION_C       4
#define ETH_IPW_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define ETH_IPW_IRQ_SW_MAJOR_VERSION_C               1
#define ETH_IPW_IRQ_SW_MINOR_VERSION_C               0
#define ETH_IPW_IRQ_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Eth_Ipw.h */
#if (ETH_IPW_IRQ_VENDOR_ID_C != ETH_IPW_VENDOR_ID)
    #error "Eth_Ipw_Irq.c and Eth_Ipw.h have different vendor ids"
#endif
#if ((ETH_IPW_IRQ_AR_RELEASE_MAJOR_VERSION_C    != ETH_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_IPW_IRQ_AR_RELEASE_MINOR_VERSION_C    != ETH_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ETH_IPW_IRQ_AR_RELEASE_REVISION_VERSION_C != ETH_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_Ipw_Irq.c and Eth_Ipw.h are different"
#endif
#if ((ETH_IPW_IRQ_SW_MAJOR_VERSION_C != ETH_IPW_SW_MAJOR_VERSION) || \
     (ETH_IPW_IRQ_SW_MINOR_VERSION_C != ETH_IPW_SW_MINOR_VERSION) || \
     (ETH_IPW_IRQ_SW_PATCH_VERSION_C != ETH_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_Ipw_Irq.c and Eth_Ipw.h are different"
#endif

/* Checks against Enet_Ip_Types.h */
#if (ETH_IPW_IRQ_VENDOR_ID_C != ENET_IP_TYPES_VENDOR_ID)
    #error "Eth_Ipw_Irq.c and Enet_Ip_Types.h have different vendor ids"
#endif
#if ((ETH_IPW_IRQ_AR_RELEASE_MAJOR_VERSION_C    != ENET_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_IPW_IRQ_AR_RELEASE_MINOR_VERSION_C    != ENET_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ETH_IPW_IRQ_AR_RELEASE_REVISION_VERSION_C != ENET_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_Ipw_Irq.c and Enet_Ip_Types.h are different"
#endif
#if ((ETH_IPW_IRQ_SW_MAJOR_VERSION_C != ENET_IP_TYPES_SW_MAJOR_VERSION) || \
     (ETH_IPW_IRQ_SW_MINOR_VERSION_C != ENET_IP_TYPES_SW_MINOR_VERSION) || \
     (ETH_IPW_IRQ_SW_PATCH_VERSION_C != ENET_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_Ipw_Irq.c and Enet_Ip_Types.h are different"
#endif

#if (STD_ON == ETH_DEM_EVENT_DETECT)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Dem.h */
    #if ((ETH_IPW_IRQ_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_IPW_IRQ_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Eth_Ipw_Irq.c and Dem.h are different"
    #endif
#endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"

void Eth_Ipw_EventIrqCallback(const uint8 CtrlIdx, const Enet_Ip_EventType Event);

#if (STD_ON == ETH_GLOBAL_TIME_API)
void Eth_Ipw_TimeStampCallback(const uint8 CtrlIdx);
void Eth_Ipw_TimeStampCallback(const uint8 CtrlIdx)
{
    /* No action taken */
    (void)CtrlIdx;
}
#endif

void Eth_Ipw_EventIrqCallback(const uint8 CtrlIdx, const Enet_Ip_EventType Event)
{
    /* Check whether Dem Event is ON then report it */
#if (STD_ON == ETH_DEM_EVENT_DETECT)
    if (((Enet_Ip_EventType)ENET_ERR_EVENT == Event) && ((uint32)STD_ON == (uint32)(Eth_Ipw_apxInternalCfg[CtrlIdx]->Eth_Ipw_DemEventsList.ETH_IPW_ETH_E_ERR_Cfg.state)))
    {
        (void)Dem_SetEventStatus((Dem_EventIdType)(Eth_Ipw_apxInternalCfg[CtrlIdx]->Eth_Ipw_DemEventsList.ETH_IPW_ETH_E_ERR_Cfg.id), DEM_EVENT_STATUS_FAILED);
    }
#endif
    (void)CtrlIdx;
    (void)Event;
}


#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
