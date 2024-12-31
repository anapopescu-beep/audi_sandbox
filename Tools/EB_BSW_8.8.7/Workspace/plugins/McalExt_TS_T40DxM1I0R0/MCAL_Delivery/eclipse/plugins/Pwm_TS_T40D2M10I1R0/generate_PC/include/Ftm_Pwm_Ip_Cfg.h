[!CODE!][!//
[!AUTOSPACING!]
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

#ifndef FTM_PWM_IP_CFG_H
#define FTM_PWM_IP_CFG_H

/**
*   @file       Ftm_Pwm_Ip_Cfg.h
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
/* Standard Types */
#include "StandardTypes.h"
/* DevAssert implementation */
#include "Devassert.h"

/* Register definitions */
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!]
    [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g2')"!][!//
        [!CODE!][!WS "0"!]#include "S32G274A_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r45')"!][!//
        [!CODE!][!WS "0"!]#include "S32R45_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32g3')"!][!//
        [!CODE!][!WS "0"!]#include "S32G399A_FTM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k1')"!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_FTM.h"[!CR!][!ENDCODE!][!//
        [!CODE!][!WS "0"!]#include "[!"$DerivativeName"!]_SIM.h"[!CR!][!ENDCODE!][!//
    [!ELSEIF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32r41')"!][!//
        [!CODE!][!WS "0"!]#include "S32R41_FTM.h"[!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

/* Include all variants header files. */
[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
#include "Ftm_Pwm_Ip_[!"."!]_PBcfg.h"
    [!ENDLOOP!]
[!ELSE!]
#include "Ftm_Pwm_Ip_PBcfg.h"
[!ENDIF!]

/* Include Feature Defines */
#include "Ftm_Pwm_Ip_CfgDefines.h"
#include "Reg_eSys.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_PWM_IP_CFG_VENDOR_ID                    43
#define FTM_PWM_IP_CFG_MODULE_ID                    121
#define FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION     4
#define FTM_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define FTM_PWM_IP_CFG_SW_MAJOR_VERSION             1
#define FTM_PWM_IP_CFG_SW_MINOR_VERSION             0
#define FTM_PWM_IP_CFG_SW_PATCH_VERSION             1

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and StandardTypes.h are of the same AUTOSAR version */
    #if ((FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Cfg.h and StandardTypes.h are different."
    #endif
    
    /* Check if source file and Devassert.h are of the same AUTOSAR version */
    #if ((FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Cfg.h and Devassert.h are different."
    #endif
    
    /* Check if source file and Reg_eSys.h are of the same AUTOSAR version */
    #if ((FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Cfg.h and Reg_eSys.h are different."
    #endif
#endif

/* Check if header file and Ftm_Pwm_Ip_CfgDefines.h header file are of the same vendor */
#if (FTM_PWM_IP_CFG_VENDOR_ID != FTM_PWM_IP_CFGDEFINES_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip_Cfg.h and Ftm_Pwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_CfgDefines.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != FTM_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION    != FTM_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION != FTM_PWM_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Cfg.h and Ftm_Pwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_CfgDefines.h header file are of the same software version */
#if ((FTM_PWM_IP_CFG_SW_MAJOR_VERSION != FTM_PWM_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_CFG_SW_MINOR_VERSION != FTM_PWM_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_CFG_SW_PATCH_VERSION != FTM_PWM_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip_Cfg.h and Ftm_Pwm_Ip_CfgDefines.h are different."
#endif

[!IF "var:defined('postBuildVariant')"!]
    [!LOOP "variant:all()"!]
/* Check if header file and Ftm_Pwm_Ip_[!"."!]_Pbcfg header file are of the same vendor */
#if (FTM_PWM_IP_CFG_VENDOR_ID != FTM_PWM_IP_[!"."!]_PB_CFG_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip_Cfg.h and Ftm_Pwm_Ip_[!"."!]_Pbcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != FTM_PWM_IP_[!"."!]_PB_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION    != FTM_PWM_IP_[!"."!]_PB_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION != FTM_PWM_IP_[!"."!]_PB_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Cfg.h and Ftm_Pwm_Ip_[!"."!]_Pbcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same software version */
#if ((FTM_PWM_IP_CFG_SW_MAJOR_VERSION != FTM_PWM_IP_[!"."!]_PB_CFG_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_CFG_SW_MINOR_VERSION != FTM_PWM_IP_[!"."!]_PB_CFG_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_CFG_SW_PATCH_VERSION != FTM_PWM_IP_[!"."!]_PB_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip_Cfg.h and Ftm_Pwm_Ip_[!"."!]_Pbcfg.h are different."
#endif
    [!ENDLOOP!]
[!ELSE!]
/* Check if header file and Pwm_EnvCfg header file are of the same vendor */
#if (FTM_PWM_IP_CFG_VENDOR_ID != FTM_PWM_IP_PB_CFG_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip_Cfg.h and Ftm_Pwm_Ip_Pbcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != FTM_PWM_IP_PB_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION    != FTM_PWM_IP_PB_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION != FTM_PWM_IP_PB_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Cfg.h and Ftm_Pwm_Ip_Pbcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same software version */
#if ((FTM_PWM_IP_CFG_SW_MAJOR_VERSION != FTM_PWM_IP_PB_CFG_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_CFG_SW_MINOR_VERSION != FTM_PWM_IP_PB_CFG_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_CFG_SW_PATCH_VERSION != FTM_PWM_IP_PB_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip_Cfg.h and Ftm_Pwm_Ip_Pbcfg.h are different."
#endif
[!ENDIF!]

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @brief      Switch to enable the development error detection. */
#define FTM_PWM_IP_DEV_ERROR_DETECT           ([!IF "PwmGeneral/PwmDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief        Switch to enable the notifications feature */
#define FTM_PWM_IP_NOTIFICATION_SUPPORTED     ([!IF "PwmGeneral/PwmNotificationSupported"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief    Support for User mode */
#define FTM_PWM_IP_ENABLE_USER_MODE_SUPPORT   ([!IF "PwmGeneral/PwmEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** @brief    Support for Sim module is available */
#define FTM_PWM_IP_SIM_AVAILABLE              ([!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k1')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == FTM_PWM_IP_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running FTM in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif

#if ((STD_ON == FTM_PWM_IP_ENABLE_USER_MODE_SUPPORT) && defined(MCAL_FTM_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_FTM_REG_PROT_AVAILABLE)
        #define  FTM_PWM_IP_USER_ACCESS_ALLOWED_AVAILABLE     (STD_ON)
    #else
        #define  FTM_PWM_IP_USER_ACCESS_ALLOWED_AVAILABLE     (STD_OFF)
    #endif
#else
#define  FTM_PWM_IP_USER_ACCESS_ALLOWED_AVAILABLE     (STD_OFF)
#endif

/* Macros that indicate FTM instances used by Pwm */
[!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmFtm/*"!]
    [!VAR "HwInstance" = "substring-after(./PwmHwInstance,'Ftm_')"!]
#ifndef FTM_[!"$HwInstance"!]_USED
    #define FTM_[!"$HwInstance"!]_USED
#else
    #error "FTM_[!"$HwInstance"!] instance cannot be used by Pwm. Instance locked by another driver!"
#endif[!CR!]
[!ENDLOOP!]
/* FTM module features */

/* @brief Number of PWM channels */
#define FTM_PWM_IP_CHANNEL_COUNT                       (FTM_CONTROLS_COUNT)
#define FTM_PWM_IP_PAIR_COUNT                          (FTM_CONTROLS_COUNT >> 1U)

/** Number of interrupt vector arrays for the FTM module. */
#define FTM_PWM_IP_IRQS_ARR_COUNT                      (FTM_INSTANCE_COUNT)
/** Number of interrupt channels for the FTM module. */
#define FTM_PWM_IP_CHANNEL_IRQ_COUNT                   (FTM_CONTROLS_COUNT)

/** Interrupt vectors for the FTM peripheral type */
#define FTM_PWM_IP_IRQS                                {\
                                                        { FTM0_IRQn, FTM0_IRQn, FTM0_IRQn, FTM0_IRQn, FTM0_IRQn, FTM0_IRQn },\
                                                        { FTM1_IRQn, FTM1_IRQn, FTM1_IRQn, FTM1_IRQn, FTM1_IRQn, FTM1_IRQn }\
                                                    }
#define FTM_PWM_IP_OVERFLOW_IRQS                       { FTM0_IRQn, FTM1_IRQn }
#define FTM_PWM_IP_RELOAD_IRQS                         { FTM0_IRQn, FTM1_IRQn }

/* Mask for Software Output Control Value of all channel bits */
#define FTM_PWM_IP_SWOCTRL_CHOC_MASK                  (0x000000FFU)
/* Mask for Software Output Control Value of all channel bits */
#define FTM_PWM_IP_SWOCTRL_CHOCV_MASK                 (0x0000FF00U)

/* @brief Width of control channel */
#define FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH             (8U)

[!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k1')"!]
/** Number of instances of the SIM module. */
#define FTM_PWM_IP_SIM_INSTANCE_COUNT                  (SIM_INSTANCE_COUNT)
[!ENDIF!]

[!NOCODE!]
[!IF "ecu:get('Pwm.FTM_PWM_HAS_MODULE_SINGLE_INTERRUPT') = 'true'"!]
    [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmFtm/*"!]
        [!VAR "HwInstance" = "substring-after(./PwmHwInstance,'Ftm_')"!]
        [!IF "(./PwmFtmInstCfg/PwmFtmOverflowIrq = 'true') or (./../../../PwmGeneral/PwmNotificationSupported = 'true')"!]
            [!CODE!]
#define FTM_PWM_IP_[!"$HwInstance"!]_ISR_USED
            [!ENDCODE!]
            [!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k1')"!]
                [!CODE!]
#define FTM_PWM_IP_[!"$HwInstance"!]_OVF_ISR_USED
                [!ENDCODE!]
            [!ENDIF!]
        [!ELSE!]
            [!LOOP "./PwmFtmCh/*"!]
                [!IF "(./PwmFtmChInterrupt = 'true') or (./../../../../../PwmGeneral/PwmNotificationSupported = 'true')"!]
                    [!CODE!]
#define FTM_PWM_IP_[!"$HwInstance"!]_ISR_USED
                    [!ENDCODE!]
                    [!BREAK!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ELSE!]
    [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmFtm/*"!]
        [!VAR "HwInstance" = "substring-after(./PwmHwInstance,'Ftm_')"!]     
        [!IF "(./PwmFtmInstCfg/PwmFtmOverflowIrq = 'true') or (../../../PwmGeneral/PwmNotificationSupported = 'true')"!]
            [!CODE!]
#define FTM_PWM_IP_[!"$HwInstance"!]_OVF_ISR_USED
            [!ENDCODE!]
        [!ENDIF!]
 
        [!FOR "ChannelIdx" = "0" TO "3"!]
            [!VAR "CheckChannelIsrUsed" = "0"!]
            [!LOOP "./PwmFtmCh/*"!]
                [!VAR "ChannelIsrUsed" = "0"!]
                [!VAR "Channel" = "substring-after(./PwmFtmChId,'CH_')"!]
                [!VAR "FtmChIntegerDivisionBy2"  = "floor(number($Channel) div 2)"!]
                [!IF "(./PwmFtmChInterrupt = 'true') or (./../../../../../PwmGeneral/PwmNotificationSupported = 'true')"!]
                    [!IF "$ChannelIdx = num:i($FtmChIntegerDivisionBy2)"!]
                        [!VAR "ChannelIsrUsed" = "$ChannelIsrUsed + 1"!]
                        [!VAR "CheckChannelIsrUsed" = "$CheckChannelIsrUsed + 1"!]
                    [!ENDIF!]
                    [!IF "(num:i($ChannelIsrUsed) = 1) and (num:i($CheckChannelIsrUsed) = 1)"!]
                        [!CODE!]
#define FTM_PWM_IP_[!"$HwInstance"!]_CH_[!"num:i($FtmChIntegerDivisionBy2 * 2)"!]_CH_[!"num:i($FtmChIntegerDivisionBy2 * 2 + 1)"!]_ISR_USED
                        [!ENDCODE!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDFOR!]
    [!ENDLOOP!]

[!ENDIF!]
[!IF "ecu:get('Pwm.FTM_PWM_HAS_FAULT') = 'true'"!]
   [!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmFtm/*"!]
        [!VAR "HwInstance" = "substring-after(./PwmHwInstance,'Ftm_')"!]
        [!IF "(./FtmGlobalFaultCfg/FtmFaultFunctionality != 'FAULT_DISABLED')"!]
            [!IF "(./FtmGlobalFaultCfg/FtmFaultIrqUsed)"!]
                [!CODE!]
#define FTM_PWM_IP_[!"$HwInstance"!]_FAULT_ISR_USED
                [!ENDCODE!]
            [!ENDIF!]
        [!ENDIF!] 
   [!ENDLOOP!]
[!ENDIF!]
[!ENDNOCODE!]

[!IF "ecu:get('Pwm.FTM_PWM_HAS_FAULT') = 'true'"!]
#define FTM_PWM_IP_FAULT_NUMBER_CHANNELS                   ([!"ecu:get('Pwm.FtmFaultIdCount')"!]U)
[!ENDIF!]
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* Redefine FTM_Type from header file to comply with coding guidelines */
typedef FTM_Type Ftm_Pwm_Ip_HwAddrType;

[!IF "contains(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative, 's32k1')"!]
/* Redefine SIM_Type from header file to comply with coding guidelines */
typedef SIM_Type Ftm_Pwm_Ip_SimType;
[!ENDIF!]

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTM_PWM_IP_CFG_H */

[!ENDCODE!]
