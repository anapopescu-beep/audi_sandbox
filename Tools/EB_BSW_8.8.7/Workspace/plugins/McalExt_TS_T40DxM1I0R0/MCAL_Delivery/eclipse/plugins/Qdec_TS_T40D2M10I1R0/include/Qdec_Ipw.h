/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Ftm
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

#ifndef QDEC_IPW_H
#define QDEC_IPW_H

/**
*     @file       Qdec_Ipw.h
*
*     @internal
*     @addtogroup qdec_ipw Qdec_Ipw Driver
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

#include "StandardTypes.h"
#include "Qdec_Ipw_Types.h"
#include "Qdec_Types.h"
#include "Qdec_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define QDEC_IPW_VENDOR_ID                          43
#define QDEC_IPW_AR_RELEASE_MAJOR_VERSION           4
#define QDEC_IPW_AR_RELEASE_MINOR_VERSION           4
#define QDEC_IPW_AR_RELEASE_REVISION_VERSION        0
#define QDEC_IPW_SW_MAJOR_VERSION                   1
#define QDEC_IPW_SW_MINOR_VERSION                   0
#define QDEC_IPW_SW_PATCH_VERSION                   1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and StandardTypes.h are of the same AUTOSAR version */
    #if ((QDEC_IPW_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (QDEC_IPW_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Qdec_Ipw.h and StandardTypes.h are different."
    #endif
#endif

/* Check if header file and Qdec_Ipw_Types header file are of the same vendor */
#if (QDEC_IPW_VENDOR_ID != QDEC_IPW_TYPES_VENDOR_ID)
#error "Qdec_Ipw.h and Qdec_Ipw_Types.h have different vendor IDs"
#endif
/* Check if header file and Qdec_Ipw_Types header file are of the same Autosar version */
#if ((QDEC_IPW_AR_RELEASE_MAJOR_VERSION != QDEC_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (QDEC_IPW_AR_RELEASE_MINOR_VERSION != QDEC_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (QDEC_IPW_AR_RELEASE_REVISION_VERSION != QDEC_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of Qdec_Ipw.h and Qdec_Ipw_Types.h are different"
#endif
/* Check if header file and Qdec_Ipw_Types header file are of the same Software Version */
#if ((QDEC_IPW_SW_MAJOR_VERSION != QDEC_IPW_TYPES_SW_MAJOR_VERSION) || \
     (QDEC_IPW_SW_MINOR_VERSION != QDEC_IPW_TYPES_SW_MINOR_VERSION) || \
     (QDEC_IPW_SW_PATCH_VERSION != QDEC_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Qdec_Ipw.h and Qdec_Ipw_Types.h are different"
#endif

/* Check if header file and Qdec_Types header file are of the same vendor */
#if (QDEC_IPW_VENDOR_ID != QDEC_TYPES_VENDOR_ID)
#error "Qdec_Ipw.h and Qdec_Types.h have different vendor IDs"
#endif
/* Check if header file and Qdec_Types header file are of the same Autosar version */
#if ((QDEC_IPW_AR_RELEASE_MAJOR_VERSION != QDEC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (QDEC_IPW_AR_RELEASE_MINOR_VERSION != QDEC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (QDEC_IPW_AR_RELEASE_REVISION_VERSION != QDEC_TYPES_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of Qdec_Ipw.h and Qdec_Types.h are different"
#endif
/* Check if header file and Qdec_Types header file are of the same Software Version */
#if ((QDEC_IPW_SW_MAJOR_VERSION != QDEC_TYPES_SW_MAJOR_VERSION) || \
     (QDEC_IPW_SW_MINOR_VERSION != QDEC_TYPES_SW_MINOR_VERSION) || \
     (QDEC_IPW_SW_PATCH_VERSION != QDEC_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Qdec_Ipw.h and Qdec_Types.h are different"
#endif

/* Check if header file and Qdec_Cfg header file are of the same vendor */
#if (QDEC_IPW_VENDOR_ID != QDEC_CFG_VENDOR_ID)
#error "Qdec_Ipw.h and Qdec_Cfg.h have different vendor IDs"
#endif
/* Check if header file and Qdec_Cfg header file are of the same Autosar version */
#if ((QDEC_IPW_AR_RELEASE_MAJOR_VERSION != QDEC_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (QDEC_IPW_AR_RELEASE_MINOR_VERSION != QDEC_CFG_AR_RELEASE_MINOR_VERSION) || \
     (QDEC_IPW_AR_RELEASE_REVISION_VERSION != QDEC_CFG_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of Qdec_Ipw.h and Qdec_Cfg.h are different"
#endif
/* Check if header file and Qdec_Cfg header file are of the same Software Version */
#if ((QDEC_IPW_SW_MAJOR_VERSION != QDEC_CFG_SW_MAJOR_VERSION) || \
     (QDEC_IPW_SW_MINOR_VERSION != QDEC_CFG_SW_MINOR_VERSION) || \
     (QDEC_IPW_SW_PATCH_VERSION != QDEC_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Qdec_Ipw.h and Qdec_Cfg.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#define QDEC_START_SEC_CODE
#include "Qdec_MemMap.h"

/**
* @brief Configures the quadrature mode and starts measurement.
*
* @param [in] count     Number Qdec Instance.
* @param [in] Config    Configuration structure(Quadrature Decoder Mode, polarity for both phases,
*                       minimum and maximum value for the counter, filter configuration).
* @return None.
*/
void Qdec_Ipw_Init(uint8 count, const Qdec_Ipw_ConfigType *Config);

/**
* @brief Disable the Quadrature Decoder Mode.
*
* @param [in] count     Number Qdec Instance.
* @param [in] Config    Configuration structure(Quadrature Decoder Mode, polarity for both phases,
*                       minimum and maximum value for the counter, filter configuration).
* @return None.
*/
void Qdec_Ipw_DeInit(uint8 count, const Qdec_Ipw_ConfigType *Config);

/**
* @brief Get the current quadrature decoder state (counter value and flags).
*
* @param [in] module Qdec hardware instance used;
* @param [in] Config The current quadrature configuration used.
*
* @return Pointer to the current state of module.
*/
Qdec_Ipw_State Qdec_Ipw_GetState(uint8 module, const Qdec_Ipw_ConfigType *Config);

#if (QDEC_SET_CLOCK_MODE_API == STD_ON)
/**
* @brief        Qdec_Ipw_SetClockMode
* @details      This function will call SetClockMode function of all configured hardware Ftm modules.
*
* @param [in] Config        The current quadrature configuration used.
* @param [in] moduleId      Qdec instance ID used;
* @param [in] prescaler     Pre-scaler type
*
* @return       void
*
*/
void Qdec_Ipw_SetClockMode(const Qdec_Ipw_ConfigType *Config, uint8 moduleId, Qdec_SelectPrescalerType prescaler);

#endif /* QDEC_SET_CLOCK_MODE_API == STD_ON */

/**
* @brief Set the state of counter
*
* @param [in] module Qdec instance ID used;
* @param [in] Config The current quadrature configuration used.
*
* @return void.
*/
void Qdec_Ipw_CounterState(const uint8 module, const Qdec_Ipw_ConfigType *Config);

/**
* @brief Reset to default current state of the QDEC module
*
* @param [in] module Qdec instance ID used.
* @param [in] Config The current quadrature configuration used.
*
* @return void.
*/
void Qdec_Ipw_ResetState(const uint8 module, const Qdec_Ipw_ConfigType *Config);

#if (QDEC_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Qdec_Ipw_DisableOverFlowNotification
*
* @param [in] module        Qdec instance ID used.
* @param [in] Config        The current quadrature configuration used.
*
* @return       void
*
*/
void Qdec_Ipw_DisableOverFlowNotification(const uint8 module, const Qdec_Ipw_ConfigType *Config);

/**
* @brief        Qdec_Ipw_EnableOverFlowNotification
*
* @param [in] module        Qdec instance ID used.
* @param [in] Config        The current quadrature configuration used.
*
* @return       void
*
*/
void Qdec_Ipw_EnableOverFlowNotification(const uint8 module, const Qdec_Ipw_ConfigType *Config);
#endif

/**
* @brief Set mode of Qdec module
*
* @param [in] module Qdec instance ID used.
* @param [in] Config The current quadrature configuration used.
* @param [in] mode The given mode
*
* @return void.
*/
void Qdec_Ipw_SetMode(const uint8 module, const Qdec_Ipw_ConfigType *Config, Qdec_ModeType mode);

#define QDEC_STOP_SEC_CODE
#include "Qdec_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* QDEC_IPW_H */
