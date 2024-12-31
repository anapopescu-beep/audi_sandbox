/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
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

#ifndef POWER_IP_CFG_DEFINES_H
#define POWER_IP_CFG_DEFINES_H

/**
*   @file       Power_Ip_Cfg_Defines.h
*   @version    1.0.1
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup POWER_DRIVER_CONFIGURATION Power Ip Driver
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
#include "StandardTypes.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_CFG_DEFINES_VENDOR_ID                       43
#define POWER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        4
#define POWER_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_CFG_DEFINES_SW_MAJOR_VERSION                1
#define POWER_IP_CFG_DEFINES_SW_MINOR_VERSION                0
#define POWER_IP_CFG_DEFINES_SW_PATCH_VERSION                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Power_Ip_Cfg_Defines.h file and StandardTypes.h file are of the same Autosar version */
#if ((POWER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION    != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Power_Ip_Cfg_Defines.h and StandardTypes.h are different"
#endif
#endif
/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/
/**
* @brief            Derivative used.
*/
#define POWER_IP_[!"ecu:get('MCU.Derivative')"!]

#if (defined(POWER_IP_S32K148) || defined(POWER_IP_S32K146) || defined(POWER_IP_S32K144) || defined(POWER_IP_S32K142))
  #define POWER_IP_HSRUN_SUPPORT    STD_ON
#else
  #define POWER_IP_HSRUN_SUPPORT    STD_OFF
#endif

/**
* @brief            Support for Low Power mode.
*/
#define POWER_IP_ENTER_LOW_POWER_MODE   [!IF "McuGeneralConfiguration/McuEnterLowPowerMode = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/**
* @brief
*/
#define POWER_IP_PERFORM_RESET_API   [!IF "McuGeneralConfiguration/McuPerformResetApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/**
* @brief            ISR Mcu_ResetAlternate_ISR is/isn't available (STD_ON/STD_OFF)
*/
#define POWER_IP_RESET_ALTERNATE_ISR_USED            [!IF "McuModuleConfiguration/McuInterruptEvents/McuAlternateResetEvent = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/**
* @brief            ISR Mcu_PMC_UnderOverVoltage_ISR is/isn't available (STD_ON/STD_OFF)
*/
#define POWER_IP_VOLTAGE_ERROR_ISR_USED              [!IF "McuModuleConfiguration/McuInterruptEvents/McuVoltageErrorEvent = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable the usage of Non-Autosar Peripheral CMU.
*/
#define MCU_ENABLE_CMU_PERIPHERAL    [!IF "McuDebugConfiguration/McuEnablePeripheralCMU = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            This parameter shall be set True, if the H/W does not have a PLL or the PLL circuitry is enabled after the power on without S/W intervention.
*/
#define POWER_IP_NO_PLL   [!IF "McuGeneralConfiguration/McuNoPll = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!IF "ecu:get('MCU.SLEEPONEXIT.SUPPORT') = 'true'"!]
/**
* @brief           This define controls the availability of function Mcu_SleepOnExit
*/
#define POWER_IP_SLEEPONEXIT_SUPPORT    (STD_ON)
[!ENDIF!]

/**
* @brief            Low Voltage Detect Status and Control 1 Register support (PMC_LVDSC1).
*/
#define POWER_IP_PMC_LVDSC1_SUPPORT     [!IF "text:tolower(ecu:get('MCU.PMC.LVDSC1.SUPPORT')) = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable the usage of Non-Autosar API Mcu_GetPowerMode_State() for getting infos system platform configuration.
*/
#define POWER_IP_POWERMODE_STATE_API   [!IF "McuDebugConfiguration/McuGetPowerModeStatetApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            If this parameter is set to TRUE, the System Mode Controller (SMC) initialization has to be disabled in the MCU driver.
*/
#define POWER_MODE_CHANGE_NOTIFICATION   [!IF "McuGeneralConfiguration/McuEnableModeChangeNotification = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable the usage of Non-Autosar API  Power_Ip_SRAMRetentionConfig().
*/
#define POWER_IP_SRAM_RETEN_CONFIG_API    [!IF "McuDebugConfiguration/McuSRAMRetentionConfigApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!IF "node:exists(McuGeneralConfiguration/McuVeryLowPowerStopAbortNotification)"!]
/**
* @brief            The notification procedure configured by the user.
*/
#define POWER_IP_VLPSA_NOTIFICATION
[!ENDIF!]

/**
* @brief            If this parameter is set to TRUE, the Reset Control Module (RMC) initialization has to be disabled from the MCU driver.
*/
#define POWER_IP_DISABLE_RCM_INIT   [!IF "McuGeneralConfiguration/McuDisableRcmInit = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            If this parameter is set to TRUE, the Power Management Controller (PMC) initialization has to be disabled from the MCU driver.
*/
#define POWER_IP_DISABLE_PMC_INIT      [!IF "McuGeneralConfiguration/McuDisablePmcInit = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            If this parameter is set to TRUE, the System Mode Controller (SMC) initialization has to be disabled from the MCU driver.
*/
#define POWER_IP_DISABLE_SMC_INIT   [!IF "McuGeneralConfiguration/McuDisableSmcInit = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/



#ifdef __cplusplus
}
#endif

/** @} */
#endif /* #ifndef POWER_IP_CFG_DEFINES_H */


