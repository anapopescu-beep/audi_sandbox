/**
*   @file    Can_IPW_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface
*   @details Main header file - can include different IPV models.
*
*   @addtogroup CAN_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FLEXCAN
*   Dependencies         : 
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
/*==================================================================================================
==================================================================================================*/

#ifndef CAN_IPW_TYPES_H
#define CAN_IPW_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*
* @page misra_violations MISRA-C:2012 violations
* @section Can_IPW_Types_h_REF_1
* Violates MISRA 2012 Advisory Rule 2.5, A project should not contain unused macro declarations.
* Declaration is reserved for future feature.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_Ipw_Cfg.h"
#include "Can_Cfg.h"
#if (CAN_USE_FLEXCAN_IP  == STD_ON)
#include "FlexCAN_Ip.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Can_IPW_Types.h
*/
#define CAN_IPW_TYPES_VENDOR_ID_H                    43
/* @violates @ref Can_IPW_Types_h_REF_1 2012 Advisory Rule 2.5. */
#define CAN_IPW_TYPES_MODULE_ID_H                    80
#define CAN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION_H     4
#define CAN_IPW_TYPES_AR_RELEASE_MINOR_VERSION_H     4
#define CAN_IPW_TYPES_AR_RELEASE_REVISION_VERSION_H  0
#define CAN_IPW_TYPES_SW_MAJOR_VERSION_H             1
#define CAN_IPW_TYPES_SW_MINOR_VERSION_H             0
#define CAN_IPW_TYPES_SW_PATCH_VERSION_H             1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (CAN_USE_FLEXCAN_IP  == STD_ON)
/* Check if current file and FlexCAN_Ip.h are of the same vendor */
#if (CAN_IPW_TYPES_VENDOR_ID_H != FLEXCAN_IP_VENDOR_ID_H)
#error "Can_IPW_Types.h and FlexCAN_Ip.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip.h are of the same Autosar version */
#if ((CAN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION_H != FLEXCAN_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_IPW_TYPES_AR_RELEASE_MINOR_VERSION_H != FLEXCAN_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_IPW_TYPES_AR_RELEASE_REVISION_VERSION_H != FLEXCAN_IP_AR_RELEASE_REVISION_VERSION_H))
  #error "AutoSar Version Numbers of Can_IPW_Types.h and FlexCAN_Ip.h are different"
#endif

/* Check if current file and FlexCAN_Ip.h are of the same software version */
#if ((CAN_IPW_TYPES_SW_MAJOR_VERSION_H != FLEXCAN_IP_SW_MAJOR_VERSION_H) || \
     (CAN_IPW_TYPES_SW_MINOR_VERSION_H != FLEXCAN_IP_SW_MINOR_VERSION_H) || \
     (CAN_IPW_TYPES_SW_PATCH_VERSION_H != FLEXCAN_IP_SW_PATCH_VERSION_H))
  #error "Software Version Numbers of Can_IPW_Types.h and FlexCAN_Ip.h are different"
#endif
#endif /* (CAN_USE_FLEXCAN_IP  == STD_ON) */

/* Check if current file and Can_Ipw_Cfg.h are of the same vendor */
#if (CAN_IPW_TYPES_VENDOR_ID_H != CAN_IPW_CFG_VENDOR_ID)
#error "Can_IPW_Types.h and Can_Ipw_Cfg.h have different vendor ids"
#endif
/* Check if current file and Can_Ipw_Cfg.h are of the same Autosar version */
#if ((CAN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION_H !=    CAN_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_IPW_TYPES_AR_RELEASE_MINOR_VERSION_H !=    CAN_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CAN_IPW_TYPES_AR_RELEASE_REVISION_VERSION_H != CAN_IPW_CFG_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Can_IPW_Types.h and Can_Ipw_Cfg.h are different"
#endif
/* Check if current file and Can_Ipw_Cfg.h are of the same software version */
#if ((CAN_IPW_TYPES_SW_MAJOR_VERSION_H != CAN_IPW_CFG_SW_MAJOR_VERSION) || \
     (CAN_IPW_TYPES_SW_MINOR_VERSION_H != CAN_IPW_CFG_SW_MINOR_VERSION) || \
     (CAN_IPW_TYPES_SW_PATCH_VERSION_H != CAN_IPW_CFG_SW_PATCH_VERSION))
  #error "Software Version Numbers of Can_IPW_Types.h and Can_Ipw_Cfg.h are different"
#endif

/* Check if current file and Can_Cfg.h are of the same vendor */
#if (CAN_IPW_TYPES_VENDOR_ID_H != CAN_VENDOR_ID_CFG_H)
#error "Can_IPW_Types.h and Can_Cfg.h have different vendor ids"
#endif
/* Check if current file and Can_Cfg.h are of the same Autosar version */
#if ((CAN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION_H !=    CAN_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (CAN_IPW_TYPES_AR_RELEASE_MINOR_VERSION_H !=    CAN_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (CAN_IPW_TYPES_AR_RELEASE_REVISION_VERSION_H != CAN_AR_RELEASE_REVISION_VERSION_CFG_H))
  #error "AutoSar Version Numbers of Can_IPW_Types.h and Can_Cfg.h are different"
#endif
/* Check if current file and Can_Cfg.h are of the same software version */
#if ((CAN_IPW_TYPES_SW_MAJOR_VERSION_H != CAN_SW_MAJOR_VERSION_CFG_H) || \
     (CAN_IPW_TYPES_SW_MINOR_VERSION_H != CAN_SW_MINOR_VERSION_CFG_H) || \
     (CAN_IPW_TYPES_SW_PATCH_VERSION_H != CAN_SW_PATCH_VERSION_CFG_H))
  #error "Software Version Numbers of Can_IPW_Types.h and Can_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct {
const Flexcan_Ip_ConfigType * pFlexcanIpHwConfig;
} Can_Ipw_HwChannelConfigType;

#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
typedef struct {
const Flexcan_Ip_PnConfigType * pFlexcanIpPnConfig;
} Can_Ipw_IcomRxMessageConfigsType;
#endif /* (CAN_PUBLIC_ICOM_SUPPORT == STD_ON) */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*CAN_IPW_TYPES_H */

/** @} */
