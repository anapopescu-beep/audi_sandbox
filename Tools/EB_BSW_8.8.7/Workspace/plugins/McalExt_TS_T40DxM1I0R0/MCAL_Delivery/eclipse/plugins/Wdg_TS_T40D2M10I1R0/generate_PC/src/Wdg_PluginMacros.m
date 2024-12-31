[!NOCODE!][!//
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
/**
*   @file
*
*   @addtogroup Wdg
*   @{
*/

[!// MACRO for defining mode configuration
[!MACRO "WdogConfig","WdgMode","WdgNo"!][!//
[!NOCODE!]
[!VAR "TimeoutPeriod" = "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgTimeoutPeriod'))"!]
[!VAR "WindowPeriod" = "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgWindowPeriod'))"!]
[!VAR "WdgClockValue" = "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgClockValue'))"!]
[!ENDNOCODE!]
    (Wdog_Ip_ClkSourceType)[!IF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgClockSelection')) = 'Bus_Clock'"!]WDOG_IP_BUS_CLOCK[!/*
            */!][!ELSEIF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgClockSelection')) = 'LPO_Clock'"!]WDOG_IP_LPO_CLOCK[!/*
            */!][!ELSEIF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgClockSelection')) = 'SOSC_Clock'"!]WDOG_IP_SOSC_CLOCK[!/*
            */!][!ELSEIF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgClockSelection')) = 'SIRC_Clock'"!]WDOG_IP_SIRC_CLOCK[!ENDIF!],       /* .clkSource */[!/*
            */!] 
    {[!CR!]
             (boolean)[!IF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgRunsInWaitMode'))"!]TRUE[!ELSE!]FALSE[!ENDIF!],         /* .bWait */
             (boolean)[!IF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgRunsInStopMode'))"!]TRUE[!ELSE!]FALSE[!ENDIF!],         /* .bStop */            
             (boolean)[!IF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgRunsInDebugMode'))"!]TRUE[!ELSE!]FALSE[!ENDIF!]         /* .bDebug */
    },
    (boolean)[!IF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgAllowUpdates'))"!]TRUE[!ELSE!]FALSE[!ENDIF!],                   /* .UpdateEnable */
    (boolean)[!IF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgOperationMode')) = 'Interrupt'"!]TRUE[!ELSE!]FALSE[!ENDIF!],                   /* .IntEnable */
    (boolean)[!IF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgWindowMode'))"!]TRUE[!ELSE!]FALSE[!ENDIF!],                   /* .WinEnable */
    (uint16) [!IF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgWindowMode'))"!][!/*
                */!][!IF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgPrescalerEnabled'))"!][!/*
                    */!][!"num:inttohex(num:i((($TimeoutPeriod - $WindowPeriod) * $WdgClockValue * 1000) div 256),4)"!]U[!/*
                */!][!ELSE!][!/*
                    */!][!"num:inttohex(num:i(($TimeoutPeriod - $WindowPeriod) * $WdgClockValue * 1000),4)"!]U[!/*
                */!][!ENDIF!][!/*
            */!][!ELSE!]0x00U[!ENDIF!],                   /* .WindowValue */
    (uint16) [!IF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgPrescalerEnabled'))"!][!/*
    */!][!"num:inttohex(num:i((node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgTimeoutPeriod')) * node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgClockValue')) * 1000) div 256),4)"!]U,                   /* .TimeoutValue */[!/*
    */!][!ELSE!][!"num:inttohex(num:i(node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgTimeoutPeriod')) * node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgClockValue')) * 1000),4)"!]U,                   /* .TimeoutValue */[!ENDIF!]
    (boolean)[!IF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgPrescalerEnabled'))"!]TRUE[!ELSE!]FALSE[!ENDIF!],                   /* .PrescalerEnable */  
[!ENDMACRO!]

[!MACRO "EwmConfig","WdgNo"!][!//
[!NOCODE!]
[!VAR "WdgClockVal" = "num:i(node:value(./../../../Wdg_43_Instance1/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration/WdgClockValue))"!]
[!VAR "Prescaler" = "num:i(node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration'),'/WdgPrescalerValue')))"!]
[!VAR "TimeoutPeriod" = "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration'),'/WdgTimeoutPeriod'))"!]
[!VAR "WindowPeriod" = "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration'),'/WdgWindowPeriod'))"!]
[!VAR "CompareHigh" = "num:inttohex(num:i(($TimeoutPeriod * $WdgClockVal * 1000) div ($Prescaler + 1)),2)"!]
[!VAR "CompareLow" = "num:inttohex(num:i((($TimeoutPeriod - $WindowPeriod) * $WdgClockVal * 1000) div ($Prescaler + 1)),2)"!]
[!ENDNOCODE!]
    [!IF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration'),'/WdgAssertLogic')) = 'Assert_Disabled'"!]EWM_IN_ASSERT_DISABLED[!/*
            */!][!ELSEIF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration'),'/WdgAssertLogic')) = 'Assert_OnLogicZero'"!]EWM_IN_ASSERT_ON_LOGIC_ZERO[!/*
            */!][!ELSEIF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration'),'/WdgAssertLogic')) = 'Assert_OnLogicOne'"!]EWM_IN_ASSERT_ON_LOGIC_ONE[!ENDIF!], /*.assertLogic */[!/*
            */!] 
    (boolean)          [!IF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration'),'/WdgInterruptEnable'))"!]TRUE[!ELSE!]FALSE[!ENDIF!],                   /*.InterruptEnable */
    (uint8)          [!"num:i(node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration'),'/WdgPrescalerValue')))"!],                   /*.u8Prescaler */
    (uint8)         [!IF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration'),'/WdgWindowMode'))"!][!"$CompareLow"!][!ELSE!]0x00[!ENDIF!],                   /*.u8CompareLow */
    (uint8)         [!"$CompareHigh"!],                   /*.u8CompareHigh */
[!ENDMACRO!]


[!ENDNOCODE!]
[!// MACRO for calculating the trigger period
[!MACRO "WdgTriggerPeriod","WdgMode","WdgNo"!][!//
[!NOCODE!]
    [!VAR "WdgTimeoutPeriod" = "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgTimeoutPeriod'))"!]
    [!IF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgWindowMode'))"!]
        [!VAR "WdgWindowPeriod" = "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgWindowPeriod'))"!]
    [!ELSE!]
        [!VAR "WdgWindowPeriod" = "num:i(0)"!]
    [!ENDIF!]
    [!VAR "WdgInternalClockVal" = "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgClockValue'))"!]
    [!VAR "WdgTriggerSourceClock" = "node:value(node:ref(./../../../Wdg/ELEMENTS/Wdg/WdgSettingsConfig/WdgExternalTriggerCounterRef)/GptChannelTickFrequency)div 1000"!]
    [!IF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgPrescalerEnabled'))"!]
        [!VAR "Prescaler" = "num:i(256)"!]
    [!ELSE!]
        [!VAR "Prescaler" = "num:i(1)"!]
    [!ENDIF!]

    [!IF "node:value(concat(concat('./../../../Wdg',$WdgNo,'/ELEMENTS/Wdg/WdgSettingsConfig/',$WdgMode),'/WdgWindowMode'))"!]
        [!VAR "WdgWindowVal" = "(($WdgTimeoutPeriod - $WdgWindowPeriod) * $WdgInternalClockVal * 1000) div $Prescaler"!]
    [!ELSE!]
        [!VAR "WdgWindowVal" = "num:i(0)"!]
    [!ENDIF!]
    [!VAR "WdgTimeoutVal" = "($WdgTimeoutPeriod * $WdgInternalClockVal * 1000) div $Prescaler"!]

[!CODE!][!//
    (uint32) [!"num:inttohex(num:i((($WdgTimeoutVal - (($WdgTimeoutVal - $WdgWindowVal) div 2)) div ($WdgInternalClockVal div $Prescaler)) * $WdgTriggerSourceClock))"!],[!//
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!MACRO "WdgEwmTriggerPeriod","WdgNo"!][!//
[!NOCODE!]
    [!VAR "WdgInternalClockVal" = "node:value(./../../../Wdg_43_Instance1/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration/WdgClockValue)"!]
    [!VAR "WdgTriggerSourceClock" = "node:value(node:ref(./../../../Wdg_43_Instance1/ELEMENTS/Wdg/WdgSettingsConfig/WdgExternalTriggerCounterRef)/GptChannelTickFrequency) div 1000"!]
    [!VAR "Prescaler" = "num:i(num:i(node:value(./../../../Wdg_43_Instance1/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration/WdgPrescalerValue)) + 1)"!]
    [!VAR "TimeoutPeriod" = "node:value(./../../../Wdg_43_Instance1/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration/WdgTimeoutPeriod)"!]

    [!IF "node:value(./../../../Wdg_43_Instance1/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration/WdgWindowMode)"!]
        [!VAR "WindowPeriod" = "node:value(./../../../Wdg_43_Instance1/ELEMENTS/Wdg/WdgSettingsConfig/WdgSettingsConfiguration/WdgWindowPeriod)"!]
        [!VAR "CompareLow" = "(($TimeoutPeriod - $WindowPeriod) * $WdgInternalClockVal * 1000) div $Prescaler"!]
    [!ELSE!]
        [!VAR "CompareLow" = "num:i(0)"!]
    [!ENDIF!]
    [!VAR "CompareHigh" = "($TimeoutPeriod * $WdgInternalClockVal * 1000) div $Prescaler"!]

[!CODE!][!//
    (uint32) [!"num:inttohex(num:i((($CompareHigh - (($CompareHigh - $CompareLow) div 2)) div ($WdgInternalClockVal div $Prescaler)) * $WdgTriggerSourceClock))"!],
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!]