[!AUTOSPACING!]
[!CODE!]
/*==================================================================================================
* Project              : RTD AUTOSAR 4.4
* Platform             : CORTEXM
* Peripheral           : Ftm Flexio
* Dependencies         : none
*
* Autosar Version      : 4.4.0
* Autosar Revision     : ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version           : 1.0.1
* Build Version        : S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224
*
* (c) Copyright 2020-2022 NXP Semiconductors
* All Rights Reserved.
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef PWM_IPW_CFG_H
#define PWM_IPW_CFG_H

/**
*   @file       Pwm_Ipw_Cfg.h
*
*   @addtogroup pwm_driver Pwm Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

[!NOCODE!]
    /* TODO: revert include file to Pwm_VersionCheck_Inc.m */
    [!INCLUDE "Pwm_VersionCheck_Inc.m"!]

    /* Check if Ftm is used */
    [!IF "(node:exists(PwmChannelConfigSet/PwmFtm) and (count(PwmChannelConfigSet/PwmFtm/*) > 0)) = 'true'"!]
        [!VAR "FtmIsUsed" = "'true'"!]
    [!ELSE!]
        [!VAR "FtmIsUsed" = "'false'"!]
    [!ENDIF!]
    
    /* Check if Flexio is used */
    [!IF "(node:exists(PwmChannelConfigSet/PwmFlexio) and (count(PwmChannelConfigSet/PwmFlexio/*) > 0)) = 'true'"!]
        [!VAR "FlexioIsUsed" = "'true'"!]
    [!ELSE!]
        [!VAR "FlexioIsUsed" = "'false'"!]
    [!ENDIF!]
    
        /* Find the offset for hw to logic mapping for flexio channels */
    [!IF "ecu:has('Pwm.FtmSupported') and (ecu:get('Pwm.FtmSupported') = 'true')"!]
        [!VAR "FlexioChannelOffset" = "number(ecu:get('Pwm.FtmInstanceCount')) * number(ecu:get('Pwm.FtmChannelsCount'))"!]
    [!ELSE!]
        [!VAR "FlexioChannelOffset" = "0"!]
    [!ENDIF!]

[!ENDNOCODE!]
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Ftm_Pwm_Ip_Cfg.h"
[!IF "$FlexioIsUsed = 'true'"!]
#include "Flexio_Pwm_Ip_Cfg.h"
[!ENDIF!]

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_IPW_CFG_VENDOR_ID                         43
#define PWM_IPW_CFG_MODULE_ID                         121
#define PWM_IPW_CFG_AR_RELEASE_MAJOR_VERSION          4
#define PWM_IPW_CFG_AR_RELEASE_MINOR_VERSION          4
#define PWM_IPW_CFG_AR_RELEASE_REVISION_VERSION       0
#define PWM_IPW_CFG_SW_MAJOR_VERSION                  1
#define PWM_IPW_CFG_SW_MINOR_VERSION                  0
#define PWM_IPW_CFG_SW_PATCH_VERSION                  1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and StandardTypes.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((PWM_IPW_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_IPW_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Pwm_Ipw_Cfg.h and StandardTypes.h are different."
    #endif
#endif

/* Check if header file and Ftm_Pwm_Ip_Cfg.h header file are of the same vendor */
#if (PWM_IPW_CFG_VENDOR_ID != FTM_PWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of Pwm_Ipw_Cfg.h and Ftm_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Cfg.h header file are of the same AUTOSAR version */
#if ((PWM_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_CFG_AR_RELEASE_MINOR_VERSION    != FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_CFG_AR_RELEASE_REVISION_VERSION != FTM_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw_Cfg.h and Ftm_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Cfg.h header file are of the same software version */
#if ((PWM_IPW_CFG_SW_MAJOR_VERSION != FTM_PWM_IP_CFG_SW_MAJOR_VERSION) || \
     (PWM_IPW_CFG_SW_MINOR_VERSION != FTM_PWM_IP_CFG_SW_MINOR_VERSION) || \
     (PWM_IPW_CFG_SW_PATCH_VERSION != FTM_PWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw_Cfg.h and Ftm_Pwm_Ip_Cfg.h are different."
#endif

[!IF "$FlexioIsUsed = 'true'"!]
/* Check if source file and Flexio_Pwm_Ip_Cfg.h header file are of the same vendor */
#if (PWM_IPW_CFG_VENDOR_ID != FLEXIO_PWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of Pwm_Ipw.c and Flexio_Pwm_Ip_Cfg.h are different."
#endif

/* Check if source file and Flexio_Pwm_Ip_Cfg.h header file are of the same AUTOSAR version */
#if ((PWM_IPW_CFG_AR_RELEASE_MAJOR_VERSION    != FLEXIO_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_CFG_AR_RELEASE_MINOR_VERSION    != FLEXIO_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_CFG_AR_RELEASE_REVISION_VERSION != FLEXIO_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw.c and Flexio_Pwm_Ip_Cfg.h are different."
#endif

/* Check if source file and Flexio_Pwm_Ip_Cfg.h header file are of the same software version */
#if ((PWM_IPW_CFG_SW_MAJOR_VERSION != FLEXIO_PWM_IP_CFG_SW_MAJOR_VERSION) || \
     (PWM_IPW_CFG_SW_MINOR_VERSION != FLEXIO_PWM_IP_CFG_SW_MINOR_VERSION) || \
     (PWM_IPW_CFG_SW_PATCH_VERSION != FLEXIO_PWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw.c and Flexio_Pwm_Ip_Cfg.h are different."
#endif
[!ENDIF!]

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @brief        Switch to enable the development error detection. */
#define PWM_DEV_ERROR_DETECT                    ([!IF "PwmGeneral/PwmDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Switch to indicate that Pwm_DeInit API is supported */
#define PWM_DE_INIT_API                         ([!IF "PwmConfigurationOfOptApiServices/PwmDeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Switch to indicate that Pwm_GetOutputState API is supported */
#define PWM_GET_OUTPUT_STATE_API                ([!IF "PwmConfigurationOfOptApiServices/PwmGetOutputState"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Switch to indicate that Pwm_SetDutyCycle API is supported */
#define PWM_SET_DUTY_CYCLE_API                  ([!IF "PwmConfigurationOfOptApiServices/PwmSetDutyCycle"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Switch to indicate that Pwm_SetPeriodAndDuty API is supported */
#define PWM_SET_PERIOD_AND_DUTY_API             ([!IF "PwmConfigurationOfOptApiServices/PwmSetPeriodAndDuty"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Switch to indicate that Pwm_SetOutputToIdle API is supported */
#define PWM_SET_OUTPUT_TO_IDLE_API              ([!IF "PwmConfigurationOfOptApiServices/PwmSetOutputToIdle"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Switch to indicate that Pwm_GetChannelState API is supported */
#define PWM_GET_CHANNEL_STATE_API               ([!IF "PwmConfigurationOfOptApiServices/PwmGetChannelStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Switch to indicate that the notifications are supported */
#define PWM_NOTIFICATION_SUPPORTED              ([!IF "PwmGeneral/PwmNotificationSupported"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Switch to enable the dual clock feature (Pwm_SetClockMode API) */
#define PWM_SET_CLOCK_MODE_API                  ([!IF "PwmGeneral/PwmEnableDualClockMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Switch to indicate that Pwm_SetCounterBus API is supported */
#define PWM_SET_COUNTER_BUS_API                 ([!IF "node:when(node:exists(PwmConfigurationOfOptApiServices/PwmSetCounterBusApi), PwmConfigurationOfOptApiServices/PwmSetCounterBusApi, false())"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Switch to indicate that Pwm_SetChannelOutput API is supported */
#define PWM_SET_CHANNEL_OUTPUT_API              ([!IF "node:when(node:exists(PwmConfigurationOfOptApiServices/PwmSetChannelOutputApi), PwmConfigurationOfOptApiServices/PwmSetChannelOutputApi, false())"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Switch to indicate that Pwm_SetTriggerDelay API is supported */
#define PWM_SET_TRIGGER_DELAY_API               ([!IF "node:when(node:exists(PwmConfigurationOfOptApiServices/PwmSetTriggerDelayApi), PwmConfigurationOfOptApiServices/PwmSetTriggerDelayApi, false())"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Switch to enable that power state mode is supported */
#define PWM_POWER_STATE_SUPPORTED               ([!IF "node:exists(PwmGeneral/PwmLowPowerStatesSupport)"!][!IF "PwmGeneral/PwmLowPowerStatesSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Switch to enable that power state mode is supported */
#define PWM_POWER_STATE_ASYNCH_MODE_SUPPORTED   ([!IF "node:exists(PwmGeneral/PwmPowerStateAsynchTransitionMode)"!][!IF "PwmGeneral/PwmPowerStateAsynchTransitionMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Switch to indicate that platform-specific validations of the notification function are supported */
#define PWM_NOTIFICATION_PLAUSABILITY           (STD_ON)

/** @brief        Switch to indicate that platform-specific validation of the offset (phase shift) of duty-cycle is supported */
#define PWM_OFFSET_PLAUSABILITY                 (STD_OFF)

/** @brief        Switch to indicate that platform-specific validation of the period is supported */
#define PWM_MAX_PERIOD_PLAUSABILITY             (STD_ON)

/** @brief       Switch to indicate that platform-specific validation of the Pwm_SetOutputToIdle is supported */
#define PWM_SETOUTPUTTOIDLE_PLAUSABILITY        (STD_ON)

/** @brief        Switch to indicate that Hw instance common configuration done by the PWM driver */
#define PWM_HW_INSTANCE_USED                    ([!IF "ecu:has('Pwm.ExclusiveHwInstance') and (ecu:get('Pwm.ExclusiveHwInstance') = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Maximum number of all hardware Ftm modules available on this platform */
#define PWM_HW_MODULE_FTM_NO                    ((uint8)[!IF "$FtmIsUsed = 'true'"!][!"ecu:get('Pwm.FtmInstanceCount')"!][!ELSE!]0[!ENDIF!]U)

/** @brief        Maximum number of all hardware FlexIO modules available on this platform */
#define PWM_HW_MODULE_FLEXIO_NO                 ((uint8)[!IF "$FlexioIsUsed = 'true'"!][!"ecu:get('Pwm.FlexioInstanceCount')"!][!ELSE!]0[!ENDIF!]U)

/** @brief        Maximum number of all hardware modules available on this platform */
#define PWM_HW_MODULE_NO                        (PWM_HW_MODULE_FTM_NO + PWM_HW_MODULE_FLEXIO_NO)

/** @brief        Switch to indicate that Ftm is used */
#define PWM_FTM_USED                            ([!IF "$FtmIsUsed = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Switch to indicate that Flexio is used */
#define PWM_FLEXIO_USED                         ([!IF "$FlexioIsUsed = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Offset to indicate Flexio channel location in hw to logic channel mapping */
#define PWM_IPW_FLEXIO_CHANNEL_OFFSET           ([!"num:i($FlexioChannelOffset)"!]U)

[!IF "$FtmIsUsed = 'true'"!]
/** @brief        ID of all FTM hardware modules available on this platform */
[!FOR "instance" = "0" TO "number(ecu:get('Pwm.FtmInstanceCount')) - 1"!]
#define PWM_FTM_INSTANCE_[!"$instance"!]                (uint8)([!"$instance"!]U)
[!ENDFOR!]
[!ENDIF!]

[!IF "$FlexioIsUsed = 'true'"!]
/** @brief        ID of all FLEXIO hardware modules available on this platform */
[!FOR "instance" = "0" TO "number(ecu:get('Pwm.FlexioInstanceCount')) - 1"!]
#define PWM_FLEXIO_INSTANCE_[!"$instance"!]              (PWM_HW_MODULE_FTM_NO + (uint8)[!"$instance"!]U)
[!ENDFOR!]
[!ENDIF!]
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief        PWM Period type (the value of the period is platform dependent and thus configurable)
*/
typedef [!"ecu:get('Pwm.TimerPrecision')"!] Pwm_Ipw_PeriodType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PWM_IPW_CFG_H */

[!ENDCODE!]
