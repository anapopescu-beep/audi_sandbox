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

#ifndef CLOCK_IP_CFG_DEFINES_H
#define CLOCK_IP_CFG_DEFINES_H


/**
*   @file       Clock_Ip_Cfg_Defines.h
*   @version    1.0.1
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup CLOCK_DRIVER_CONFIGURATION Clock Ip Driver
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
#define CLOCK_IP_CFG_DEFINES_VENDOR_ID                       43
#define CLOCK_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define CLOCK_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        4
#define CLOCK_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define CLOCK_IP_CFG_DEFINES_SW_MAJOR_VERSION                1
#define CLOCK_IP_CFG_DEFINES_SW_MINOR_VERSION                0
#define CLOCK_IP_CFG_DEFINES_SW_PATCH_VERSION                1

/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/
/**
* @brief            Derivative used.
*/
#define CLOCK_IP_[!"ecu:get('MCU.Derivative')"!]

/**
* @brief            HW sseries used.
*/
#define CLOCK_IP_S32K1

/**
* @brief            Max number of internal oscillators
*/
#define CLOCK_IP_IRCOSCS_COUNT       ([!"num:i( count( ecu:list('MCU.IRCOSC.List') ) )"!]U)

/**
* @brief            Max number of external oscillators
*/
#define CLOCK_IP_XOSCS_COUNT       ([!"num:i( count( ecu:list('MCU.XOSC.List') ) )"!]U)

/**
* @brief            Max number of pll devices
*/
#define CLOCK_IP_PLLS_COUNT       ([!"num:i( count( ecu:list('MCU.PLL.List') ) )"!]U)

/**
* @brief            Max number of selectors
*/
#define CLOCK_IP_SELECTORS_COUNT       ([!"num:i( count( ecu:list('MCU.SELECTOR.Names.List') ) )"!]U)

/**
* @brief            Max number of dividers
*/
#define CLOCK_IP_DIVIDERS_COUNT       ([!"num:i( count( ecu:list('MCU.DIVIDER.Names.List') ) )"!]U)

/**
* @brief            Max number of divider triggers
*/
#define CLOCK_IP_DIVIDER_TRIGGERS_COUNT       ([!"num:i( count( ecu:list('MCU.DIVIDER.TRIGGER.Names.List') ) )"!]U)

/**
* @brief            Max number of fractional dividers
*/
#define CLOCK_IP_FRACTIONAL_DIVIDERS_COUNT       ([!"num:i( count( ecu:list('MCU.ClockDFS.List') ) )"!]U)

/**
* @brief            Max number of external clocks
*/
#define CLOCK_IP_EXT_CLKS_COUNT       ([!"num:i( count( ecu:list('MCU.ExtClock.List') ) )"!]U)

/**
* @brief            Max number of pcfs
*/
#define CLOCK_IP_PCFS_COUNT       ([!"num:i( count( ecu:list('MCU.CGM.CgmPcfs.List') ))"!]U)

/**
* @brief            Max number of clock gates
*/
#define CLOCK_IP_GATES_COUNT       ([!"num:i( count( ecu:list('MCU.GATE.Names.List') ) )"!]U)

/**
* @brief            Max number of clock monitoring units
*/
#define CLOCK_IP_CMUS_COUNT       ([!"num:i( count( ecu:list('MCU.CMU_FC.List') ) )"!]U)

/**
* @brief            Max number of configured frequencies values
*/
#define CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT       ([!"num:i( count( ecu:list('MCU.ConfiguredFrequency.List') ) )"!]U)

/**
* @brief            Max number of specific peripheral (eMIOS) units
*/
#define CLOCK_IP_SPECIFIC_PERIPH_COUNT       ([!"num:i( count( ecu:list('MCU.SPECIFIC_PERIPHERAL_PRAMs.List') ) )"!]U)

/**
* @brief            Supported power mode.
*/

#define CLOCK_IP_HAS_RUN_MODE                0U

#define CLOCK_IP_LPO_128K_FREQUENCY          128000

#define CLOCK_IP_FIRC_FREQUENCY              48000000

#define CLOCK_IP_SIRC_FREQUENCY              8000000

#define CLOCK_IP_DEFAULT_SOSC_FREQUENCY      40000000

#define CLOCK_IP_HAS_LOW_GAIN                         0U

#define CLOCK_IP_HAS_HIGH_GAIN                        1U

#define CLOCK_IP_HAS_MONITOR_DISABLE                  0U

#define CLOCK_IP_HAS_MONITOR_INT                      1U

#define CLOCK_IP_HAS_MONITOR_RESET                    2U

#define CLOCK_IP_HAS_SAFE_CLOCK_DISABLEMENT           1U

#if CLOCK_IP_CMUS_COUNT > 0U
/**
* @brief            Cmu formula constant values.
*/
#define CLOCK_IP_FEATURE_OFFSET_REFERENCE_COUNT_FORMULA1               1U
#define CLOCK_IP_FEATURE_MULTIPLIER_REFERENCE_COUNT_FORMULA1           3U
#define CLOCK_IP_FEATURE_OFFSET_REFERENCE_COUNT_FORMULA2               7U
#define CLOCK_IP_FEATURE_MULTIPLIER_REFERENCE_COUNT_FORMULA2           3U
#endif

/**
* @brief            Clock ip supports clock frequency
*/
#define CLOCK_IP_GET_FREQUENCY_API              [!IF "McuDebugConfiguration/McuGetClockFrequencyApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/**
* @brief            Clock ip supports ram wait states
*/
[!IF "McuGeneralConfiguration/McuDisableRamWaitStatesConfig = 'false'"!]
#define CLOCK_IP_HAS_RAM_WAIT_STATES
[!ENDIF!]

/**
* @brief            Clock ip supports flash wait states
*/
[!IF "McuGeneralConfiguration/McuDisableFlashWaitStatesConfig = 'false'"!]
#define CLOCK_IP_HAS_FLASH_WAIT_STATES
[!ENDIF!]

/**
* @brief            Supports wait states configuration
*/
#define CLOCK_IP_SUPPORTS_WAIT_STATES       STD_OFF

/**
* @brief            Clock ip supports power mode change notification
*/
#define CLOCK_IP_POWER_MODE_CHANGE_NOTIFICATION         STD_ON

/**
* @brief            Supported clocks.
*/
[!FOR "Index" = "1" TO "num:i( count( ecu:list('MCU.ProducerClocks.List') ) )"!][!//
#define CLOCK_IP_HAS_[!"ecu:list('MCU.ProducerClocks.List')[num:i($Index)]"!]         [!"num:i($Index)"!]U
[!ENDFOR!][!//
#define CLOCK_IP_FEATURE_PRODUCERS_NO         [!"num:i( count( ecu:list('MCU.ProducerClocks.List') ) )"!]U
[!FOR "Index" = "1" TO "num:i( count( ecu:list('MCU.ConsumerClocks.List') ) )"!][!//
#define CLOCK_IP_HAS_[!"ecu:list('MCU.ConsumerClocks.List')[num:i($Index)]"!]         [!"num:i(num:i($Index) + num:i(count(ecu:list('MCU.ProducerClocks.List'))) + 1)"!]U
[!ENDFOR!][!//
#define CLOCK_IP_FEATURE_NAMES_NO         [!"num:i(num:i(count(ecu:list('MCU.ProducerClocks.List'))) + num:i(count(ecu:list('MCU.ConsumerClocks.List'))) + 2)"!]U

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
#endif /* #ifndef CLOCK_IP_CFG_DEFINES_H */

