/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Ftm Lpit Lptmr Port_Ci LpCmp
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

#ifndef LPTMR_ICU_IP_H
#define LPTMR_ICU_IP_H

/**
 *     @file       Lptmr_Icu_Ip.h
 *     @brief      Header file of Low Power Timer module.
 *     @details    This file contains signatures for all the functions which are related to Lptmr 
 *                 module.
 *     @addtogroup lptmr_icu_ip LPTMR IPL
 *     @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lptmr_Icu_Ip_Types.h"
#include "Lptmr_Icu_Ip_Cfg.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPTMR_ICU_IP_VENDOR_ID                    43
#define LPTMR_ICU_IP_AR_RELEASE_MAJOR_VERSION     4
#define LPTMR_ICU_IP_AR_RELEASE_MINOR_VERSION     4
#define LPTMR_ICU_IP_AR_RELEASE_REVISION_VERSION  0
#define LPTMR_ICU_IP_SW_MAJOR_VERSION             1
#define LPTMR_ICU_IP_SW_MINOR_VERSION             0
#define LPTMR_ICU_IP_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (LPTMR_ICU_IP_VENDOR_ID != LPTMR_ICU_IP_TYPES_VENDOR_ID)
    #error "Lptmr_Icu_Ip.h and Lptmr_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((LPTMR_ICU_IP_AR_RELEASE_MAJOR_VERSION != LPTMR_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LPTMR_ICU_IP_AR_RELEASE_MINOR_VERSION != LPTMR_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LPTMR_ICU_IP_AR_RELEASE_REVISION_VERSION != LPTMR_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lptmr_Icu_Ip.h and Lptmr_Icu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((LPTMR_ICU_IP_SW_MAJOR_VERSION != LPTMR_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (LPTMR_ICU_IP_SW_MINOR_VERSION != LPTMR_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (LPTMR_ICU_IP_SW_PATCH_VERSION != LPTMR_ICU_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Lptmr_Icu_Ip.h and Lptmr_Icu_Ip_Types.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (LPTMR_ICU_IP_VENDOR_ID != LPTMR_ICU_IP_CFG_VENDOR_ID)
    #error "Lptmr_Icu_Ip.h and Lptmr_Icu_Ip_Cfg.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((LPTMR_ICU_IP_AR_RELEASE_MAJOR_VERSION != LPTMR_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LPTMR_ICU_IP_AR_RELEASE_MINOR_VERSION != LPTMR_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LPTMR_ICU_IP_AR_RELEASE_REVISION_VERSION != LPTMR_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lptmr_Icu_Ip.h and Lptmr_Icu_Ip_Cfg.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((LPTMR_ICU_IP_SW_MAJOR_VERSION != LPTMR_ICU_IP_CFG_SW_MAJOR_VERSION) || \
     (LPTMR_ICU_IP_SW_MINOR_VERSION != LPTMR_ICU_IP_CFG_SW_MINOR_VERSION) || \
     (LPTMR_ICU_IP_SW_PATCH_VERSION != LPTMR_ICU_IP_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Lptmr_Icu_Ip.h and Lptmr_Icu_Ip_Cfg.h are different"
#endif

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
#if (defined LPTMR_ICU_CONFIG_EXT)
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/* Macro used to import Lptmr generated configurations. */
LPTMR_ICU_CONFIG_EXT

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
#endif /*LPTMR_ICU_CONFIG_EXT */

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @brief
 *
 *
 * @param[in]  instance - Hardware instance of LPTMR used.
 * @param[in]  param    - Configuration of the input capture channel.
 * @return     void
 *
 *
 */
Lptmr_Icu_Ip_StatusType Lptmr_Icu_Ip_Init(uint8 instance, const Lptmr_Icu_Ip_ConfigType *userConfig);

#if (STD_ON == LPTMR_ICU_DEINIT_API)
/**
 * @brief      Disables input capture mode and clears LPTMR instance configuration
 *
 * @param[in]  instance   - Hardware instance of LPTMR used.
 * @param[in]  ipConfig   - Configuration of the input capture channel.
 */
Lptmr_Icu_Ip_StatusType Lptmr_Icu_Ip_Deinit(uint8 instance);

#endif /* LPTMR_ICU_DEINIT_API  */

#if (STD_ON == LPTMR_ICU_SET_MODE_API)
/**
 * @brief      Driver function sets LPTMR hardware channel into SLEEP mode.
 *
 * @param[in]  instance  - Hardware instance of LPTMR used. 
 * @return     void
 */
void Lptmr_Icu_Ip_SetSleepMode(uint8 instance);

/**
 * @brief      Driver function sets LPTMR hardware channel into NORMAL mode.
 *
 * @param[in]  instance  - Hardware instance of LPTMR used.
 * @return     void
 */
void Lptmr_Icu_Ip_SetNormalMode(uint8 instance);

#endif  /* LPTMR_ICU_SET_MODE_API  */

/**
 * @brief     This function enables the requested activation condition(rising, falling or both
 *            edges) for corresponding LPTMR channels.
 * 
 * @param[in] instance - Hardware instance of LPTMR used. 
 * @param[in] activation Edge activation type used.
 *           - LPTMR_ICU_RISING_EDGE : count pulse on Rising Edge
 *           - LPTMR_ICU_FALLING_EDGE: count pulse on Falling Edge
 * @return    void
 */
void Lptmr_Icu_Ip_SetActivationCondition(uint8 instance, Lptmr_Icu_Ip_EdgeType activation);

#if (STD_ON == LPTMR_ICU_EDGE_DETECT_API)
/**
 * @brief     LPTMR IP layer function which enable edge detection measure mode for a given instance and channel.
 * 
 * @param[in] instance - Hardware instance of LPTMR used.
 * @return    void
 */
void Lptmr_Icu_Ip_EnableEdgeDetection(uint8 instance);

/**
 * @brief     LPTMR IP layer function which disable edge detection measure mode for a given instance and channel.
 * 
 * @param[in] instance  - Hardware instance of LPTMR used.
 * @return    void
 */
void Lptmr_Icu_Ip_DisableDetection(uint8 instance);

#endif /* LPTMR_ICU_EDGE_DETECT_API */

#if (STD_ON == LPTMR_ICU_EDGE_COUNT_API)
/**
 * @brief     LPTMR IP layer function which reset edge count measure mode for a given instance and channel.
 * 
 * @param[in] instance  - Hardware instance of LPTMR used.
 * @return    void
 */
void Lptmr_Icu_Ip_ResetEdgeCount(uint8 instance);

/**
 * @brief     LPTMR IP layer function which enable edge count measure mode for a given instance and channel.
 * 
 * @param[in] instance  - Hardware instance of LPTMR used.
 * @return    void
 */
void Lptmr_Icu_Ip_EnableEdgeCount(uint8 instance);

/**
 * @brief     LPTMR IP layer function which disable edge count measure mode for a given instance and channel.
 * 
 * @param[in] instance  - Hardware instance of LPTMR used.
 * @return    Lptmr_Icu_Ip_StatusType
 */ 
Lptmr_Icu_Ip_StatusType Lptmr_Icu_Ip_DisableEdgeCount(uint8 instance);

/**
 * @brief     LPTMR IP layer function which gets the number of edges for a given instance and channel.
 * 
 * @param[in] instance  - Hardware instance of LPTMR used.
 * @return    uint16
 */
uint16 Lptmr_Icu_Ip_GetEdgeNumbers(uint8 instance);

#endif  /* LPTMR_ICU_EDGE_COUNT_API */

#if (STD_ON == LPTMR_ICU_GET_INPUT_STATE_API)
/**
 * @brief Return input state of the channel.
 * 
 * @param[in] instance  - Hardware instance of LPTMR used. ype.
 */
boolean Lptmr_Icu_Ip_GetInputState(uint8 instance);

#endif  /* LPTMR_ICU_GET_INPUT_STATE_API */

void Lptmr_Icu_Ip_EnableInterrupt(uint8 instance);

void Lptmr_Icu_Ip_DisableInterrupt(uint8 instance);

/**
 * @brief      Driver function Enable Notification for timestamp.
 */
void Lptmr_Icu_Ip_EnableNotification(uint8 instance);

/**
 * @brief      Driver function Disable Notification for timestamp.
 */
void Lptmr_Icu_Ip_DisableNotification(uint8 instance);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LPTMR_ICU_IP_H */
