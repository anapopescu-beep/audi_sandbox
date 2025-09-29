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

#ifndef ICU_IPW_TYPES_H
#define ICU_IPW_TYPES_H

/**
 *     @file
 *
 *     @internal
 *     @addtogroup icu_ipw Icu_Ipw Driver
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
/* Supported platforms includes. */
#include "Ftm_Icu_Ip_Types.h"
#include "Lpit_Icu_Ip_Types.h"
#include "Lptmr_Icu_Ip_Types.h"
#include "Port_Ci_Icu_Ip_Types.h"
#include "Cmp_Ip_Types.h"

#include "Icu_Cfg.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_IPW_TYPES_VENDOR_ID                    43
#define ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION     4
#define ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION  0
#define ICU_IPW_TYPES_SW_MAJOR_VERSION             1
#define ICU_IPW_TYPES_SW_MINOR_VERSION             0
#define ICU_IPW_TYPES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_TYPES_VENDOR_ID != FTM_ICU_IP_TYPES_VENDOR_ID)
    #error "Icu_Ipw_Types.h and Ftm_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != FTM_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != FTM_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != FTM_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_Types.h and Ftm_Icu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_TYPES_SW_MAJOR_VERSION != FTM_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_SW_MINOR_VERSION != FTM_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_TYPES_SW_PATCH_VERSION != FTM_ICU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw_Types.h and Ftm_Icu_Ip_Types.h are different"
#endif

/* Check if header file and ICU Lpit_Icu_Ip_Types.h header file are of the same vendor. */
#if (ICU_IPW_TYPES_VENDOR_ID != LPIT_ICU_IP_TYPES_VENDOR_ID)
    #error "Icu_Ipw_Types.h and Lpit_Icu_Ip_Types.h have different vendor IDs!"
#endif
/* Check if header file and ICU Lpit_Icu_Ip_Types.h header file are of the same AutoSar version */
#if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != LPIT_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != LPIT_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != LPIT_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_Types.h and Lpit_Icu_Ip_Types.h are different!"
#endif
/* Check if heder file and ICU Lpit_Icu_Ip_Types.h header file are of the same Software version */
#if ((ICU_IPW_TYPES_SW_MAJOR_VERSION != LPIT_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_SW_MINOR_VERSION != LPIT_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_TYPES_SW_PATCH_VERSION != LPIT_ICU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw_Types.h and Lpit_Icu_Ip_Types.h are different!"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_IPW_TYPES_VENDOR_ID != LPTMR_ICU_IP_TYPES_VENDOR_ID)
    #error "Icu_Ipw_Types.h and Lptmr_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != LPTMR_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != LPTMR_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != LPTMR_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_Types.h and Lptmr_Icu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_TYPES_SW_MAJOR_VERSION != LPTMR_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_SW_MINOR_VERSION != LPTMR_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_TYPES_SW_PATCH_VERSION != LPTMR_ICU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw_Types.h and Lptmr_Icu_Ip_Types.h are different"
#endif

#if (ICU_IPW_TYPES_VENDOR_ID != PORT_CI_ICU_IP_TYPES_VENDOR_ID)
    #error "Icu_Ipw_Types.h and Port_Ci_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != PORT_CI_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != PORT_CI_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != PORT_CI_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_Types.h and Port_Ci_Icu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_TYPES_SW_MAJOR_VERSION != PORT_CI_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_SW_MINOR_VERSION != PORT_CI_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_TYPES_SW_PATCH_VERSION != PORT_CI_ICU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw_Types.h and Port_Ci_Icu_Ip_Types.h are different"
#endif

#if (ICU_IPW_TYPES_VENDOR_ID != CMP_IP_TYPES_VENDOR_ID)
    #error "Icu_Ipw_Types.h and Cmp_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != CMP_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != CMP_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != CMP_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_Types.h and Cmp_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_IPW_TYPES_SW_MAJOR_VERSION != CMP_IP_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_SW_MINOR_VERSION != CMP_IP_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_TYPES_SW_PATCH_VERSION != CMP_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw_Types.h and Cmp_Ip_Types.h are different"
#endif

/* Check if source file and Icu_Cfg.h header file are of the same vendor */
#if (ICU_IPW_TYPES_VENDOR_ID != ICU_CFG_VENDOR_ID)
    #error "Icu_Ipw_Types.h and Icu_Cfg.h have different vendor IDs"
#endif
/* Check if source file and Icu_Cfg.h header file are of the same AutoSar version */
#if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != ICU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != ICU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != ICU_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_Types.h and Icu_Cfg.h are different"
#endif
/* Check if source file and Icu_Cfg.h header file are of the same Software version */
#if ((ICU_IPW_TYPES_SW_MAJOR_VERSION != ICU_CFG_SW_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_SW_MINOR_VERSION != ICU_CFG_SW_MINOR_VERSION) || \
     (ICU_IPW_TYPES_SW_PATCH_VERSION != ICU_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw_Types.h and Icu_Cfg.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Wakeup feature is currently enabled
*/
#define ICU_CHANNEL_STATE_WKUP                  (1U)

/**
* @brief The current channel status - IDLE / ACTIVE
*/
#define ICU_CHANNEL_STATE_IDLE                  (1U<<1)

/**
* @brief Notification is enabled
*/
#define ICU_CHANNEL_STATE_NOTIFICATION          (1U<<2)

/**
* @brief The current channel state
*/
#define ICU_CHANNEL_STATE_RUNNING               (1U<<3)

/**
* @brief Overflow flag
*/
#define ICU_CHANNEL_STATE_OVERFLOW              (1U<<4)

/**
* @brief Wakeup source
*/
#define ICU_CHANNEL_IS_WAKEUP_SOURCE            (1U<<7)


#if (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON)
/**
 * @brief  Definition majorloop count for dma
 */
#define ICU_DMA_MAJORLOOP_COUNT    ((uint32)2U)

/**
 * @brief  Definition majorloop count for dma
 */
#define ICU_DMA_MAJORLOOP_FIRST_COUNT    ((uint32)1U)
#endif
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
#if ((ICU_DEV_ERROR_DETECT == STD_ON) && (ICU_GET_INPUT_LEVEL_API == STD_ON))
/**
 * @internal
 * @brief       Icu_Ipw_StatusType
 * @details     This indicates the operation success or fail
 */
typedef enum
{
    ICU_IPW_SUCCESS     = 0x0U,
    ICU_IPW_ERROR       = 0x1U
}Icu_Ipw_StatusType;
#endif

typedef enum
{
    ICU_FTM_MODULE      = 0U,
    ICU_LPIT_MODULE     = 1U,
    ICU_LPTMR_MODULE    = 2U,
    ICU_PORT_CI_MODULE  = 3U,
    ICU_CMP_MODULE      = 4U
} Icu_Ipw_ModuleType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/** 
 * @internal
 * @brief Icu channel low level configuration mapping.
 *        Members aligned to respect MISRA 11.5 
 */
typedef struct
{
    Icu_Ipw_ModuleType                      channelIp;           /** @brief The IP used to implement this specific Icu channel */
    uint8                                   instanceNo;          /** @brief The instance index used for the configuration of channel */
    const Ftm_Icu_Ip_ChannelConfigType*     pFtmHwChannelConfig; /** @brief FTM channels configuration for current instance. */
    const Lpit_Icu_Ip_ChannelConfigType*    pLpitHwChannelConfig; /** @brief LPIT channels configuration for current instance. */
    const Lptmr_Icu_Ip_ChannelConfigType*   pLptmrHwChannelConfig;
    const Port_Ci_Icu_Ip_ChannelConfigType* pPortCiHwChannelConfig;
    const Cmp_Ip_ConfigType*                pCmpHwChannelConfig; /** @brief CMP channels configuration for current instance. */
    uint8                                   index;               /** @brief Index in the Ip configuration array */  
} Icu_Ipw_ChannelConfigType;

/** 
 * @internal
 * @brief      Icu instance low level configuration mapping.
 *             Members aligned to respect MISRA 11.5 
 */
typedef struct
{
    Icu_Ipw_ModuleType                      instanceIp;           /** @brief The IP type used. */
    uint8                                   instanceNo;           /** @brief The instance number used. */
    const Ftm_Icu_Ip_ConfigType*            pFtmHwIpConfig;       /** @brief Pointer to FTM instance specific configuration. */
    const Lpit_Icu_Ip_ConfigType*           pLpitHwInstanceConfig; /** @brief Pointer to LPIT instance specific configuration. */
    const Lptmr_Icu_Ip_ConfigType*          pLptmrHwIpConfig;     /** @brief Pointer to Lptmr IP specific configuration */    
    const Port_Ci_Icu_Ip_ConfigType*        pPortCiHwIpConfig;    /** @brief Pointer to Port Ci IP specific configuration */
    const Cmp_Ip_ConfigType*                pCmpHwIpConfig;       /** @brief Pointer to Cmp IP specific configuration */
} Icu_Ipw_IpConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* ICU_IPW_TYPES_H */
