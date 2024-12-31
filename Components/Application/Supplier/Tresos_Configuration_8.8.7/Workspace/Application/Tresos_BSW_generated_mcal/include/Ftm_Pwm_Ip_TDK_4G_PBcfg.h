/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Ftm Flexio
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

#ifndef FTM_PWM_IP_TDK_4G_PBCFG_H
#define FTM_PWM_IP_TDK_4G_PBCFG_H

/**
*   @file       Ftm_Pwm_Ip_PBcfg.h
*
*   @addtogroup ftm_pwm_ip Ftm Pwm IPL
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

#include "Ftm_Pwm_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_PWM_IP_TDK_4G_PB_CFG_VENDOR_ID                       43
#define FTM_PWM_IP_TDK_4G_PB_CFG_AR_RELEASE_MAJOR_VERSION        4
#define FTM_PWM_IP_TDK_4G_PB_CFG_AR_RELEASE_MINOR_VERSION        4
#define FTM_PWM_IP_TDK_4G_PB_CFG_AR_RELEASE_REVISION_VERSION     0
#define FTM_PWM_IP_TDK_4G_PB_CFG_SW_MAJOR_VERSION                1
#define FTM_PWM_IP_TDK_4G_PB_CFG_SW_MINOR_VERSION                0
#define FTM_PWM_IP_TDK_4G_PB_CFG_SW_PATCH_VERSION                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same vendor */
#if (FTM_PWM_IP_TDK_4G_PB_CFG_VENDOR_ID != FTM_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip_TDK_4G_PBcfg.h and Ftm_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_TDK_4G_PB_CFG_AR_RELEASE_MAJOR_VERSION    != FTM_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_TDK_4G_PB_CFG_AR_RELEASE_MINOR_VERSION    != FTM_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_TDK_4G_PB_CFG_AR_RELEASE_REVISION_VERSION != FTM_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip_TDK_4G_PBcfg.h and Ftm_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same software version */
#if ((FTM_PWM_IP_TDK_4G_PB_CFG_SW_MAJOR_VERSION != FTM_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_TDK_4G_PB_CFG_SW_MINOR_VERSION != FTM_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_TDK_4G_PB_CFG_SW_PATCH_VERSION != FTM_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip_TDK_4G_PBcfg.h and Ftm_Pwm_Ip_Types.h are different."
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/* Ftm instance index for configuration PwmFtm1_Ch_0 */
#define FTM_PWM_IP_TDK_4G_I1_CH0_CFG      (1U)
/* Ftm instance index for configuration PwmFtm1_Ch_5 */
#define FTM_PWM_IP_TDK_4G_I1_CH5_CFG      (1U)
/* Ftm instance index for configuration PwmFtm1_Ch_6 */
#define FTM_PWM_IP_TDK_4G_I1_CH6_CFG      (1U)
/* Ftm instance index for configuration PwmFtm1_Ch_7 */
#define FTM_PWM_IP_TDK_4G_I1_CH7_CFG      (1U)
/* Ftm instance index for configuration PwmFtm3_Ch_6 */
#define FTM_PWM_IP_TDK_4G_I3_CH6_CFG      (3U)
/* Ftm instance index for configuration PwmFtm3_Ch_7 */
#define FTM_PWM_IP_TDK_4G_I3_CH7_CFG      (3U)

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#ifndef FTM_PWM_IP_PRECOMPILE_SUPPORT
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/*================================================================================================*/
/* Ftm instance 1 User configuration structure */
extern const Ftm_Pwm_Ip_UserCfgType Ftm_Pwm_Ip_TDK_4G_UserCfg1;

/* Ftm instance 1 configuration structure */
extern const Ftm_Pwm_Ip_InstanceCfgType Ftm_Pwm_Ip_TDK_4G_InstCfg1;

/* Ftm instance 1 synchronization configuration structure */
extern const Ftm_Pwm_Ip_SyncCfgType Ftm_Pwm_Ip_TDK_4G_SyncCfg1;

/* Channel configurations for Ftm instance 1 */
/* Ftm channel 0 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_TDK_4G_I1_Ch0;

/* Ftm channel 5 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_TDK_4G_I1_Ch5;

/* Ftm channel 6 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_TDK_4G_I1_Ch6;

/* Ftm channel 7 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_TDK_4G_I1_Ch7;

/*================================================================================================*/
/* Ftm instance 3 User configuration structure */
extern const Ftm_Pwm_Ip_UserCfgType Ftm_Pwm_Ip_TDK_4G_UserCfg3;

/* Ftm instance 3 configuration structure */
extern const Ftm_Pwm_Ip_InstanceCfgType Ftm_Pwm_Ip_TDK_4G_InstCfg3;

/* Ftm instance 3 synchronization configuration structure */
extern const Ftm_Pwm_Ip_SyncCfgType Ftm_Pwm_Ip_TDK_4G_SyncCfg3;

/* Channel configurations for Ftm instance 3 */
/* Ftm channel 6 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_TDK_4G_I3_Ch6;

/* Ftm channel 7 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_TDK_4G_I3_Ch7;


#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
#endif  /* FTM_PWM_IP_PRECOMPILE_SUPPORT */


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTM_PWM_IP_TDK_4G_PBCFG_H */

