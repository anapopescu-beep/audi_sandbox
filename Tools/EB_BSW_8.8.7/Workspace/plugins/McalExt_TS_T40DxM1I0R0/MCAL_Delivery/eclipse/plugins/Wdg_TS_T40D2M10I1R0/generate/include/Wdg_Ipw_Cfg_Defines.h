/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Wdog,Ewm
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


#ifndef WDG_IPW_CFG_DEFINES_H
#define WDG_IPW_CFG_DEFINES_H

/**
*   @file
*
*   @addtogroup  Wdg
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isWdogAvailable" = "0"!]
[!VAR "isEwmAvailable" = "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
        [!IF "num:i($i) > 0"!]
            [!IF "$isEwmAvailable = 0"!]
                [!VAR "isEwmAvailable" = "1"!]
                [!CODE!]#include "Ewm_Ip_Cfg_Defines.h"[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ELSE!]
            [!IF "$isWdogAvailable = 0"!]
                [!VAR "isWdogAvailable" = "1"!]
                [!CODE!]#include "Wdog_Ip_Cfg_Defines.h"[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//
/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_IPW_CFG_DEFINES_VENDOR_ID                    43
#define WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     4
#define WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION             1
#define WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION             0
#define WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION             1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isWdogAvailable" = "0"!]
[!VAR "isEwmAvailable" = "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
        [!IF "num:i($i) > 0"!]
            [!IF "$isEwmAvailable = 0"!]
                [!VAR "isEwmAvailable" = "1"!]
                [!CODE!]
                #if (WDG_IPW_CFG_DEFINES_VENDOR_ID != EWM_IP_CFG_DEFINES_VENDOR_ID)
                #error "Wdg_Ipw_Cfg_Defines.h and Ewm_Ip_Cfg_Defines.h have different vendor ids"
                #endif

                /* Check if current file and Ewm_Ip_Cfg_Defines header file are of the same Autosar version */
                #if ((WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION   != EWM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION    != EWM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != EWM_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
                #error "AutoSar Version Numbers of Wdg_Ipw_Cfg_Defines.h and Ewm_Ip_Cfg_Defines.h are different"
                #endif

                /* Check if current file and Ewm_Ip_Cfg_Defines header file are of the same software version */
                #if ((WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION != EWM_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION  != EWM_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION  != EWM_IP_CFG_DEFINES_SW_PATCH_VERSION))
                #error "Software Version Numbers of Wdg_Ipw_Cfg_Defines.h and Ewm_Ip_Cfg_Defines.h are different"
                #endif
                [!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ELSE!]
            [!IF "$isWdogAvailable = 0"!]
                [!VAR "isWdogAvailable" = "1"!]
                [!CODE!]
                #if (WDG_IPW_CFG_DEFINES_VENDOR_ID != WDOG_IP_CFG_DEFINES_VENDOR_ID)
                #error "Wdg_Ipw_Cfg_Defines.h and Wdog_Ip_Cfg_Defines.h have different vendor ids"
                #endif
                
                /* Check if current file and Wdog_Ip_Cfg_Defines header file are of the same Autosar version */
                #if ((WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION   != WDOG_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION    != WDOG_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != WDOG_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
                #error "AutoSar Version Numbers of Wdg_Ipw_Cfg_Defines.h and Wdog_Ip_Cfg_Defines.h are different"
                #endif
                
                /* Check if current file and Wdog_Ip_Cfg_Defines header file are of the same software version */
                #if ((WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION != WDOG_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION  != WDOG_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
                    (WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION  != WDOG_IP_CFG_DEFINES_SW_PATCH_VERSION))
                #error "Software Version Numbers of Wdg_Ipw_Cfg_Defines.h and Wdog_Ip_Cfg_Defines.h are different"
                #endif
                [!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

[!VAR "WdgInstanceCount" = "0"!][!//
/**
  * @brief  This constant specifies if the instance of the WDG is selected or not
  */
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isWdogAvailable" = "0"!]
[!VAR "isEwmAvailable" = "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
        [!IF "num:i($i) > 0"!]
            [!IF "$isEwmAvailable = 0"!]
                [!VAR "isEwmAvailable" = "1"!]
                [!CODE!]#define WDG_IPW_ENABLE_INSTANCE1      (EWM_IP_ENABLE)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ELSE!]
            [!IF "$isWdogAvailable = 0"!]
                [!VAR "isWdogAvailable" = "1"!]
                [!CODE!]#define WDG_IPW_ENABLE_INSTANCE0      (WDOG_IP_ENABLE)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
  * @brief  This constant specifies the hardware used or not.
  */
[!NOCODE!]
[!INDENT "0"!]
[!VAR "isWdogAvailable" = "0"!]
[!VAR "isEwmAvailable" = "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
        [!IF "num:i($i) > 0"!]
            [!IF "$isEwmAvailable = 0"!]
                [!VAR "isEwmAvailable" = "1"!]
                [!CODE!]#define EWM_IP_USED      (STD_ON)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ELSE!]
            [!IF "$isWdogAvailable = 0"!]
                [!VAR "isWdogAvailable" = "1"!]
                [!CODE!]#define WDOG_IP_USED      (STD_ON)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ELSE!]
        [!IF "num:i($i) > 0"!]
            [!IF "$isEwmAvailable = 0"!]
                [!VAR "isEwmAvailable" = "1"!]
                [!CODE!]#define EWM_IP_USED      (STD_OFF)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ELSE!]
            [!IF "$isWdogAvailable = 0"!]
                [!VAR "isWdogAvailable" = "1"!]
                [!CODE!]#define WDOG_IP_USED      (STD_OFF)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
    [!IF "$isEwmAvailable = 0"!]
        [!CODE!]#define EWM_IP_USED      (STD_OFF)[!ENDCODE!][!CR!]
    [!ENDIF!]
    [!IF "$isWdogAvailable = 0"!]
        [!CODE!]#define WDOG_IP_USED      (STD_OFF)[!ENDCODE!][!CR!]
    [!ENDIF!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
* @brief  Compile switch to allow/forbid disabling the watchdog driver during runtime
*/
[!NOCODE!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
        [!IF "num:i($i) = 0"!]
            [!CODE!]#define WDG_IPW_DEINIT    (WDOG_IP_DEINIT)[!ENDCODE!][!CR!]
            [!BREAK!]
        [!ENDIF!]
    [!ELSE!]
        [!IF "num:i($i) = 0"!]
            [!CODE!]#define WDG_IPW_DEINIT    (STD_OFF)[!ENDCODE!][!CR!]
            [!BREAK!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
* @brief  Defines indicating for which Wdg instances the ISR for is supported
*/
[!NOCODE!]
[!INDENT "0"!]
[!VAR "enableISR" = "0"!]
    [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
        [!IF "num:i($i) > 0"!]
            [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
        [!ELSE!]
            [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
        [!ENDIF!]
        [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
            [!IF "num:i($i) > 0"!]
                [!CODE!]#define WDG_IPW_ISR[!"$i"!]_USED (EWM_IP_ISR0_USED)[!ENDCODE!][!CR!]
            [!ELSE!]
                [!CODE!]#define WDG_IPW_ISR[!"$i"!]_USED (WDOG_IP_ISR0_USED)[!ENDCODE!][!CR!]
            [!ENDIF!]
        [!ELSE!]
            [!CODE!]#define WDG_IPW_ISR[!"$i"!]_USED (STD_OFF)[!ENDCODE!][!CR!]
        [!ENDIF!]
    [!ENDFOR!]
    [!IF "num:i(ecu:get('Wdg.Num.Of.Instances')) = 1"!]
        [!CODE!]#define WDG_IPW_ISR1_USED (STD_OFF)[!ENDCODE!][!CR!]
    [!ENDIF!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
* @brief  Defines indicating for which Wdg instances the Direct Service Mode is supported
*/
[!NOCODE!]
[!VAR "isEnableDirectService"     = "0"!]
[!VAR "isDisableDirectService"    = "0"!]
[!INDENT "0"!]
[!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
    [!IF "num:i($i) > 0"!]
        [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
    [!ELSE!]
        [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
    [!ENDIF!]
    [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
        [!IF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgEnableDirectService'))"!]
            [!VAR "isEnableDirectService"     = "1"!]
            [!CODE!]#define WDG_IPW_ENABLE_DIRECT_SERVICE_INSTANCE[!"$i"!] (STD_ON)[!ENDCODE!][!CR!]
            [!IF "num:i($isDisableDirectService) = 1"!]
                [!ERROR!]The "Wdg Enable Direct Service" node must be enabled or disabled for all instances[!ENDERROR!]
                [!BREAK!]
            [!ENDIF!]
        [!ELSE!]
            [!VAR "isDisableDirectService" = "1"!]
            [!CODE!]#define WDG_IPW_ENABLE_DIRECT_SERVICE_INSTANCE[!"$i"!] (STD_OFF)[!ENDCODE!][!CR!]
            [!IF "num:i($isEnableDirectService) = 1"!]
                [!ERROR!]The "Wdg Enable Direct Service" node must be enabled or disabled for all instances[!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ELSE!]
        [!CODE!]#define WDG_IPW_ENABLE_DIRECT_SERVICE_INSTANCE[!"$i"!] (STD_OFF)[!ENDCODE!][!CR!]
    [!ENDIF!]
[!ENDFOR!]
[!CODE!]
/**
* @brief  This variable will indicate if the Wdg Direct Service feature is activated
*/

#define WDG_IPW_DIRECT_SERVICE ([!IF "$isEnableDirectService = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])[!ENDCODE!][!CR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

[!NOCODE!][!//
[!INDENT "0"!]
    [!VAR "isDirectServiceAvailable" = "1"!]
    [!VAR "checkVersionInforAPI" = "1"!]
    [!FOR "i" = "0" TO "num:i(ecu:get('Wdg.Num.Of.Instances'))-1"!]
        [!IF "num:i($i) > 0"!]
            [!VAR "xPathModule" = "concat('./../../../Wdg','_43_Instance',$i)"!]
        [!ELSE!]
            [!VAR "xPathModule" = "concat('./../../../','Wdg')"!]
        [!ENDIF!]
        [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg'))"!]
            [!IF "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgVersionInfoApi'))"!]
                [!VAR "checkVersionInforAPI" = "0"!]
            [!ENDIF!]

            [!VAR "getInitialTimeoutValue" = "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgInitialTimeout'))"!]
            [!VAR "getTimeoutMaxValue" = "node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgMaxTimeout'))"!]

            [!IF "node:exists(concat($xPathModule,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgExternalTriggerCounterRef'))"!]
                [!IF "node:ref(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgEnableDirectService'))='false'"!]
                    [!VAR "isDirectServiceAvailable" = "0"!]
                    [!VAR "GptChannelInitialTickValue" = "(node:ref(node:value(node:ref(concat($xPathModule,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgExternalTriggerCounterRef'))))/GptChannelTickFrequency)"!]
                    [!VAR "GptChannelTickValueMax" = "(node:ref(node:value(node:ref(concat($xPathModule,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgExternalTriggerCounterRef'))))/GptChannelTickValueMax)"!]
                    [!IF "$getTimeoutMaxValue > ($GptChannelTickValueMax div $GptChannelInitialTickValue)"!]
                        [!ERROR!][!//
                        [!"'Must set Wdg Max Timeout [s] lest than or equal to '"!][!"$GptChannelTickValueMax div $GptChannelInitialTickValue"!]
                        [!ENDERROR!][!//
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
            [!CODE!]
            /**
            * @brief  These variables will indicate the Wdg Initial Timeout and Wdg Max Timeout parameters in miliseconds for Wdg module [!"$i"!]
            */
            #define WDG_IPW_INSTANCE[!"$i"!]_INITIAL_TIMEOUT_U16 ((uint16)[!"num:i(node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgInitialTimeout')) * 1000)"!])
            #define WDG_IPW_INSTANCE[!"$i"!]_MAX_TIMEOUT_U16 ((uint16)[!"num:i(node:value(concat($xPathModule,'/ELEMENTS/Wdg/WdgGeneral/WdgMaxTimeout')) * 1000)"!])
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDINDENT!]
[!ENDNOCODE!][!//

/**
* @brief  This define will indicate if the "Fixed Execution" and "Incremental Execution" for Wdg instances is used
*/

#define WDG_IPW_SUPPORT_IACR  (STD_OFF)

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* WDG_IPW_CFG_DEFINES_H */
