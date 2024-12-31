[!AUTOSPACING!]
[!// Section for macros used in this file
[!NOCODE!]
    [!MACRO "getPeriodInTicks", "instance"!]
        [!NOCODE!]
            [!VAR "varPeriodMax" = "65534"!]
            [!VAR "valuePeriod" = "''"!]
            [!LOOP "../../PwmChannel/*"!]
                [!IF "contains(PwmHwChannel,'Ftm')"!]
                    [!VAR "insId" = "num:i(substring-after(node:ref(PwmHwChannel)/../../PwmHwInstance, '_'))"!]
                    [!VAR "clockPrescaler" = "num:i(substring-after(node:ref(PwmHwChannel)/../../PwmFtmClkCfg/PwmFtmClockPrescaler, 'Divide_by_'))"!]
                    [!VAR "mcuClockRef" = "num:i(node:value(node:ref(./PwmMcuClockReferencePoint)/McuClockReferencePointFrequency))"!]
                    [!IF "($instance = $insId)"!]
                            [!IF "PwmPeriodInTicks"!]
                                [!VAR "valuePeriod" = "num:i(node:value(PwmPeriodDefault))"!]
                            [!ELSE!]
                                [!VAR "valuePeriod" = "num:i(node:value(PwmPeriodDefault) * ($mcuClockRef div $clockPrescaler))"!]
                            [!ENDIF!]
                            
                            [!IF "num:i($valuePeriod) > $varPeriodMax"!]
                                [!ERROR!]
[Error in variant: [!"variant:name()"!]] The configured period/ticks for PwmChannelId '[!"PwmChannelId"!]' is [!"$valuePeriod"!] ticks which is larger than the maximum allowed value for the period, which is [!"num:i($varPeriodMax)"!] ticks
The plugin performs the conversion from Period to ticks if requested.
To solve this problem change the configured Period/ticks or change the Pwm clock tree settings.
                                [!ENDERROR!]
                            [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDNOCODE!]
    [!ENDMACRO!]

    [!MACRO "getParamAsr", "instance", "channel"!]
        [!NOCODE!]
            [!VAR "valuePeriod" = "''"!]
            [!VAR "valueDutyCycle" = "''"!]
            [!VAR "valueOutputState" = "''"!]
            [!VAR "valuePolarity" = "''"!]
            [!VAR "checkValid" = "0"!]
            [!LOOP "../../../../PwmChannel/*"!]
                [!IF "contains(PwmHwChannel,'Ftm')"!]
                    [!VAR "instanceIdx" = "num:i(substring-after(node:ref(PwmHwChannel)/../../PwmHwInstance, '_'))"!]
                    [!VAR "channelIdx" = "num:i(substring-after(node:ref(PwmHwChannel)/PwmFtmChId, '_'))"!]
                    [!VAR "clockPrescaler" = "num:i(substring-after(node:ref(PwmHwChannel)/../../PwmFtmClkCfg/PwmFtmClockPrescaler, 'Divide_by_'))"!]
                    [!VAR "mcuClockRef" = "num:i(node:value(node:ref(./PwmMcuClockReferencePoint)/McuClockReferencePointFrequency))"!]
                    [!IF "($instance = $instanceIdx) and ($channel = $channelIdx)"!]
                            [!VAR "checkValid" = "1"!]
                            [!IF "PwmPeriodInTicks"!]
                                [!VAR "valuePeriod" = "num:i(node:value(PwmPeriodDefault))"!]
                            [!ELSE!]
                                [!VAR "valuePeriod" = "num:i(node:value(PwmPeriodDefault) * ($mcuClockRef div $clockPrescaler))"!]
                            [!ENDIF!]
                            [!VAR "valueDutyCycle" = "num:i(node:value(PwmDutycycleDefault))"!]
                            [!VAR "valueDutyCycle" = "num:i(($valuePeriod * $valueDutyCycle) div 32768)"!]

                            [!VAR "valuePolarity" = "substring-after(node:value(PwmPolarity), '_')"!]
                            [!VAR "valuePolarity" = "concat('FTM_PWM_IP_POLARITY_', $valuePolarity)"!]

                            [!VAR "valueOutputState" = "substring-after(PwmIdleState, '_')"!]
                            [!VAR "valueOutputState" = "concat('FTM_PWM_IP_OUTPUT_STATE_', $valueOutputState)"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!IF "$checkValid = 0"!]
                [!ERROR!] "FTM_[!"$instance"!]_CH_[!"$channel"!] did not reference by any channels in PwmChannel list, Please remove this channel in FtmChannel list"[!ENDERROR!]
            [!ENDIF!]
        [!ENDNOCODE!]
    [!ENDMACRO!]

    [!MACRO "getEnumIndex",
            "enumPath",
            "enumSelectedValue"!]
        [!NOCODE!]

        [!VAR "enumIndex" = "-1"!]
        [!FOR "i" = "1" TO "count(node:range($enumPath))"!]
            [!IF "node:range($enumPath)[num:i($i)] = $enumSelectedValue"!]
                [!VAR "enumIndex" = "num:i($i)"!]
            [!ENDIF!]
        [!ENDFOR!]

        [!IF "num:i($enumIndex) = '-1'"!]
            [!ERROR "Selected enum value $enumSelectedValue is not valid!"!]
        [!ENDIF!]

        [!ENDNOCODE!]
    [!ENDMACRO!]

    [!MACRO "getChannelMode"!]
        [!NOCODE!]

        [!VAR "ftmChMode" = "'FTM_PWM_IP_MODE_'"!]

        [!IF "(PwmFtmPairedCh/PwmFtmPairedChCombineMode != 'Combine_modes_disabled') and (PwmFtmPairChEnable = 'true')"!]
            [!CALL "getEnumIndex", "enumPath" = "'PwmFtmPairedCh/PwmFtmPairedChCombineMode'", "enumSelectedValue" = "PwmFtmPairedCh/PwmFtmPairedChCombineMode"!]
            [!VAR "ftmChMode" = "ecu:list('Pwm.FtmCHannelCombine')[num:i($enumIndex)]"!]
        [!ELSE!]
            [!CALL "getEnumIndex", "enumPath" = "'../../PwmFtmGlobalChCfg/PwmFtmCounterMode'", "enumSelectedValue" = "../../PwmFtmGlobalChCfg/PwmFtmCounterMode"!]
            [!VAR "ftmChMode" = "ecu:list('Pwm.PwmFtmChMode')[num:i($enumIndex)]"!]
        [!ENDIF!]

        [!IF "PwmFtmChPulseType = 'High_true_pulse'"!]
            [!VAR "ftmChMode" = "concat($ftmChMode, '_HIGH')"!]
        [!ELSE!]
            [!VAR "ftmChMode" = "concat($ftmChMode, '_LOW')"!]
        [!ENDIF!]

        [!CODE!][!"$ftmChMode"!][!ENDCODE!]

        [!ENDNOCODE!]
    [!ENDMACRO!]
[!ENDNOCODE!]
[!CODE!]
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

/**
*   @file       Ftm_Pwm_Ip_PBcfg.c
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
#include "Ftm_Pwm_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_VENDOR_ID_C                       43
#define FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MAJOR_VERSION_C        4
#define FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MINOR_VERSION_C        4
#define FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_REVISION_VERSION_C     0
#define FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_MAJOR_VERSION_C                1
#define FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_MINOR_VERSION_C                0
#define FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_PATCH_VERSION_C                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and Ftm_Pwm_Ip_Cfg.h header file are of the same vendor */
#if (FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_VENDOR_ID_C != FTM_PWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ftm_Pwm_Ip_Cfg.h are different."
#endif

/* Check if source file and Ftm_Pwm_Ip_Cfg.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MAJOR_VERSION_C    != FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_MINOR_VERSION_C    != FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_AR_RELEASE_REVISION_VERSION_C != FTM_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ftm_Pwm_Ip_Cfg.h are different."
#endif

/* Check if source file and Ftm_Pwm_Ip_Cfg.h header file are of the same software version */
#if ((FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_MAJOR_VERSION_C != FTM_PWM_IP_CFG_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_MINOR_VERSION_C != FTM_PWM_IP_CFG_SW_MINOR_VERSION) || \
     (FTM_PWM_IP[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PB_CFG_SW_PATCH_VERSION_C != FTM_PWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ftm_Pwm_Ip_Cfg.h are different."
#endif


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
[!IF "PwmGeneral/PwmNotificationSupported"!]
[!CODE!]
extern void Pwm_Notification(uint8 Channel);
[!ENDCODE!]
[!ELSE!]
[!VAR "MacOuterLoopCounter" = "0"!]
[!VAR "MacInnerLoopCounter" = "0"!]
[!LOOP "./PwmChannelConfigSet/PwmFtm/*"!]
    [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
    [!VAR "MacInnerLoopCounter" = "0"!]
    [!VAR "MacMatchcounter" = "0"!]
    [!IF "PwmFtmInstCfg/PwmFtmOverflowIrq"!]
        [!IF "((./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqFunctionCallback) != 'NULL_PTR') and ((./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqFunctionCallback) != 'NULL') and ((./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqFunctionCallback) != '"NULL"')"!]
            [!VAR "overflowfnc" = "./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqFunctionCallback"!]
            [!LOOP "./../../PwmFtm/*"!]
                [!IF "./PwmFtmInstCfg/PwmFtmOverflowIrq"!]
                    [!IF "(./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqFunctionCallback != 'NULL_PTR') and (./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqFunctionCallback != 'NULL') and (./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqFunctionCallback != '"NULL"')"!]
                        [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
                        [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                            [!IF "($overflowfnc = ./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqFunctionCallback)"!]
                                [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$MacMatchcounter = 1"!]
        [!CODE!]
extern void [!"$overflowfnc"!](void*);
        [!ENDCODE!]
    [!ENDIF!]
[!ENDLOOP!]
[!VAR "MacOuterLoopCounter" = "0"!]
[!VAR "MacInnerLoopCounter" = "0"!]
[!LOOP "./PwmChannelConfigSet/PwmFtm/*"!]
    [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
    [!VAR "MacInnerLoopCounter" = "0"!]
    [!VAR "MacMatchcounter" = "0"!]
    [!IF "PwmFtmInstCfg/PwmFtmOverflowIrq"!]
        [!IF "((./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqParameterCallback) != 'NULL_PTR') and ((./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqParameterCallback) != 'NULL') and ((./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqFunctionCallback) != '"NULL"')"!]
            [!VAR "overflowparam" = "./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqParameterCallback"!]
            [!LOOP "./../../PwmFtm/*"!]
                [!IF "./PwmFtmInstCfg/PwmFtmOverflowIrq"!]
                    [!IF "(./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqParameterCallback != 'NULL_PTR') and (./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqParameterCallback != 'NULL') and (./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqFunctionCallback != '"NULL"')"!]
                        [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
                        [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                            [!IF "($overflowparam = ./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqParameterCallback)"!]
                                [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$MacMatchcounter = 1"!]
        [!CODE!]
extern void* [!"$overflowparam"!];
        [!ENDCODE!]
    [!ENDIF!]
[!ENDLOOP!]
[!VAR "MacOuterLoopCounter" = "0"!]
[!VAR "MacInnerLoopCounter" = "0"!]
[!LOOP "./PwmChannelConfigSet/PwmFtm/*"!]
    [!VAR "MacMatchcounterbk" = "0"!]
    [!LOOP "./PwmFtmCh/*"!]
        [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
        [!VAR "MacInnerLoopCounter" = "0"!]
        [!VAR "MacMatchcounter" = "0"!]
            [!IF "./PwmFtmChInterrupt"!]
                [!IF "((./PwmFtmChInterruptCallback/PwmFtmChInterruptFunctionCallback) != 'NULL_PTR') and ((./PwmFtmChInterruptCallback/PwmFtmChInterruptFunctionCallback) != 'NULL') and ((./PwmFtmChInterruptCallback/PwmFtmChInterruptFunctionCallback) != '"NULL"')"!]
                    [!VAR "chCallfnc" = "./PwmFtmChInterruptCallback/PwmFtmChInterruptFunctionCallback"!]
                    [!LOOP "./../../../../PwmFtm/*"!]
                        [!VAR "overflowfnc" = "./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqFunctionCallback"!]
                        [!LOOP "./PwmFtmCh/*"!]
                            [!IF "./PwmFtmChInterrupt"!]
                                [!IF "((./PwmFtmChInterruptCallback/PwmFtmChInterruptFunctionCallback) != 'NULL_PTR') and ((./PwmFtmChInterruptCallback/PwmFtmChInterruptFunctionCallback) != 'NULL') and ((./PwmFtmChInterruptCallback/PwmFtmChInterruptFunctionCallback) != '"NULL"')"!]
                                    [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
                                    [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                                        [!IF "($chCallfnc = ./PwmFtmChInterruptCallback/PwmFtmChInterruptFunctionCallback)"!]
                                            [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
                                        [!ENDIF!]
                                    [!ENDIF!]
                                    [!IF " $chCallfnc = $overflowfnc"!]
                                        [!VAR "MacMatchcounterbk" = "$MacMatchcounterbk + 1"!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ENDLOOP!]
                    [!ENDLOOP!]
                [!ENDIF!]
            [!ENDIF!]
        [!IF "num:i($MacMatchcounter) = 1 and num:i($MacMatchcounterbk) = 0"!]
            [!CODE!]
extern void [!"$chCallfnc"!](void*);
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDLOOP!]
[!VAR "MacOuterLoopCounter" = "0"!]
[!VAR "MacInnerLoopCounter" = "0"!]
[!LOOP "./PwmChannelConfigSet/PwmFtm/*"!]
    [!LOOP "./PwmFtmCh/*"!]
        [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
        [!VAR "MacInnerLoopCounter" = "0"!]
        [!VAR "MacMatchcounter" = "0"!]
        [!VAR "MacMatchcounterbk" = "0"!]
             [!IF "./PwmFtmChInterrupt"!]
                [!IF "((./PwmFtmChInterruptCallback/PwmFtmChInterruptParameterCallback) != 'NULL_PTR') and ((./PwmFtmChInterruptCallback/PwmFtmChInterruptParameterCallback) != 'NULL') and ((./PwmFtmChInterruptCallback/PwmFtmChInterruptFunctionCallback) != '"NULL"')"!]
                    [!VAR "chCallparam" = "./PwmFtmChInterruptCallback/PwmFtmChInterruptParameterCallback"!]
                    [!LOOP "./../../../../PwmFtm/*"!]
                        [!VAR "overflowparam" = "./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqParameterCallback"!]
                        [!LOOP "./PwmFtmCh/*"!]
                            [!IF "./PwmFtmChInterrupt"!]
                                [!IF "((./PwmFtmChInterruptCallback/PwmFtmChInterruptParameterCallback) != 'NULL_PTR') and ((./PwmFtmChInterruptCallback/PwmFtmChInterruptParameterCallback) != 'NULL') and ((./PwmFtmChInterruptCallback/PwmFtmChInterruptFunctionCallback) != '"NULL"')"!]
                                    [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
                                    [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                                        [!IF "($chCallparam = ./PwmFtmChInterruptCallback/PwmFtmChInterruptParameterCallback) and $chCallparam != $overflowparam"!]
                                            [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
                                        [!ENDIF!]
                                    [!ENDIF!]
                                    [!IF " $chCallparam = $overflowparam"!]
                                        [!VAR "MacMatchcounterbk" = "$MacMatchcounterbk + 1"!]
                                    [!ENDIF!]
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ENDLOOP!]
                    [!ENDLOOP!]
                [!ENDIF!]
            [!ENDIF!]
         [!IF "num:i($MacMatchcounter) = 1 and num:i($MacMatchcounterbk) = 0"!]
            [!CODE!]
extern void* [!"$chCallparam"!];
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDLOOP!]
[!ENDIF!]
[!IF "ecu:get('Pwm.FTM_PWM_HAS_FAULT') = 'true'"!]
[!LOOP "as:modconf('Pwm')[1]/PwmChannelConfigSet/PwmFtm/*"!]
    [!VAR "HwInstance" = "substring-after(./PwmHwInstance,'Ftm_')"!]
    [!IF "(./FtmGlobalFaultCfg/FtmFaultFunctionality != 'FAULT_DISABLED')"!]
        [!IF "(./FtmGlobalFaultCfg/FtmFaultIrqUsed)"!]
            [!VAR "numFaultCfg" = "num:i(count(./FtmGlobalFaultCfg/FtmFaultSettings/*))"!]
            [!IF "$numFaultCfg > 0"!]
                [!LOOP "./FtmGlobalFaultCfg/FtmFaultSettings/*"!]
                  [!IF "((FtmFaultNotification != 'NULL_PTR') and (FtmFaultNotification != '"NULL"') and (FtmFaultNotification != 'NULL'))"!]
                    [!CODE!]
extern void [!"FtmFaultNotification"!](void);
                    [!ENDCODE!]
                  [!ENDIF!]
                [!ENDLOOP!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDIF!]
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#ifndef FTM_PWM_IP_PRECOMPILE_SUPPORT
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

[!LOOP "./PwmChannelConfigSet/PwmFtm/*"!]
    [!VAR "instanceId" = "substring-after(./PwmHwInstance, '_')"!]
    [!VAR "faultMode" = "node:value(FtmGlobalFaultCfg/FtmFaultFunctionality)"!]
    [!VAR "faultIsrUsed" = "node:value(FtmGlobalFaultCfg/FtmFaultIrqUsed)"!]
/*================================================================================================*/

/* Ftm instance [!"$instanceId"!] synchronization initialization configuration */
const Ftm_Pwm_Ip_SyncCfgType Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SyncCfg[!"$instanceId"!] =
{
[!CALL "getEnumIndex", "enumPath" = "'PwmFtmSyncCfg/PwmFtmSyncMode'", "enumSelectedValue" = "PwmFtmSyncCfg/PwmFtmSyncMode"!]
    /* SyncMode */              [!"ecu:list('Pwm.FtmSyncMode')[num:i($enumIndex)]"!],
    /* HwSync0 */               (boolean)[!"text:toupper(PwmFtmSyncCfg/PwmFtmHwTrig0)"!],
    /* HwSync1 */               (boolean)[!"text:toupper(PwmFtmSyncCfg/PwmFtmHwTrig1)"!],
    /* HwSync2 */               (boolean)[!"text:toupper(PwmFtmSyncCfg/PwmFtmHwTrig2)"!],
    /* HwTriggerAutoClear */    (boolean)[!"text:toupper(PwmFtmSyncCfg/PwmFtmAutoHwTrig)"!],
    /* MaxLoadPoint */          (boolean)[!"text:toupper(PwmFtmSyncCfg/PwmFtmMaxLoadPoint)"!],
    /* MinLoadPoint */          (boolean)[!"text:toupper(PwmFtmSyncCfg/PwmFtmMinLoadPoint)"!],
#if (defined(FTM_PWM_IP_HAS_HALF_CYCLE_RELOAD) && (FTM_PWM_IP_HAS_HALF_CYCLE_RELOAD == STD_ON))
    /* HalfCycleLoadPoint */    (boolean)[!"text:toupper(PwmFtmSyncCfg/PwmFtmHalfCycleLoadPoint)"!],
#endif
    /* LoadPointFreq */         [!"num:i(PwmFtmSyncCfg/PwmFtmReloadPointFrequency)"!]U,
[!CALL "getEnumIndex", "enumPath" = "'PwmFtmSyncCfg/PwmFtmInvertControl'", "enumSelectedValue" = "PwmFtmSyncCfg/PwmFtmInvertControl"!]
    /* InverterSync */          [!"ecu:list('Pwm.FtmSync')[num:i($enumIndex)]"!],
[!CALL "getEnumIndex", "enumPath" = "'PwmFtmSyncCfg/PwmFtmSwOutControl'", "enumSelectedValue" = "PwmFtmSyncCfg/PwmFtmSwOutControl"!]
    /* OutRegSync */            [!"ecu:list('Pwm.FtmSync')[num:i($enumIndex)]"!],
[!CALL "getEnumIndex", "enumPath" = "'PwmFtmSyncCfg/PwmFtmOutputMask'", "enumSelectedValue" = "PwmFtmSyncCfg/PwmFtmOutputMask"!]
    /* OutMaskSync */           [!"ecu:list('Pwm.FtmSync')[num:i($enumIndex)]"!],
[!CALL "getEnumIndex", "enumPath" = "'PwmFtmSyncCfg/PwmFtmCounterInitial'", "enumSelectedValue" = "PwmFtmSyncCfg/PwmFtmCounterInitial"!]
    /* InitCounterSync */       [!"ecu:list('Pwm.FtmSync')[num:i($enumIndex)]"!],
[!CALL "getEnumIndex", "enumPath" = "'PwmFtmSyncCfg/PwmFtmCounterSync'", "enumSelectedValue" = "PwmFtmSyncCfg/PwmFtmCounterSync"!]
    /* CounterSync */           [!"ecu:list('Pwm.FtmSync')[num:i($enumIndex)]"!]
};


/* Ftm instance [!"$instanceId"!] initialization configuration */
const Ftm_Pwm_Ip_InstanceCfgType Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_InstCfg[!"$instanceId"!] =
{
[!CALL "getEnumIndex", "enumPath" = "'PwmFtmClkCfg/PwmFtmClockSource'", "enumSelectedValue" = "PwmFtmClkCfg/PwmFtmClockSource"!]
    /* ClkSrc */                [!"ecu:list('Pwm.FtmClockSources')[num:i($enumIndex)]"!],
[!CALL "getEnumIndex", "enumPath" = "'PwmFtmClkCfg/PwmFtmClockPrescaler'", "enumSelectedValue" = "PwmFtmClkCfg/PwmFtmClockPrescaler"!]
    /* ClkPs */                 [!"ecu:list('Pwm.FtmClockPrescaler')[num:i($enumIndex)]"!],
[!CALL "getEnumIndex", "enumPath" = "'PwmFtmClkCfg/PwmFtmClockPrescalerAlternate'", "enumSelectedValue" = "PwmFtmClkCfg/PwmFtmClockPrescalerAlternate"!]
    /* AlternateclkPs */        [!"ecu:list('Pwm.FtmClockPrescaler')[num:i($enumIndex)]"!],
[!CALL "getEnumIndex", "enumPath" = "'PwmFtmGlobalChCfg/PwmFtmCounterMode'", "enumSelectedValue" = "PwmFtmGlobalChCfg/PwmFtmCounterMode"!]
    /* CntMode */               [!"ecu:list('Pwm.FtmMode')[num:i($enumIndex)]"!],
[!IF "./../../../PwmGeneral/PwmNotificationSupported"!][!//
    /* OverflowIrqEn */         (boolean)TRUE,
    /* OverflowCb */            {
        /* FunctionCallback */      &Pwm_Notification,
        /* CbParam */               0U
                                },
[!ELSE!][!//
    /* OverflowIrqEn */         (boolean)[!"text:toupper(PwmFtmInstCfg/PwmFtmOverflowIrq)"!],
    /* OverflowCb */            {
        /* FunctionCallback */      [!WS "6"!][!IF "PwmFtmInstCfg/PwmFtmOverflowIrq = 'true' and ((./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqFunctionCallback) != 'NULL_PTR') and ((./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqFunctionCallback) != 'NULL') and ((./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqFunctionCallback) != '"NULL"')"!]&[!"PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqFunctionCallback"!][!ELSE!]NULL_PTR[!ENDIF!],
        /* CbParam */               [!WS "15"!][!IF "PwmFtmInstCfg/PwmFtmOverflowIrq = 'true' and ((./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqParameterCallback) != 'NULL_PTR') and ((./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqParameterCallback) != 'NULL') and ((./PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqFunctionCallback) != '"NULL"')"!]&[!"PwmFtmInstCfg/PwmFtmOverflowIrqCallback/PwmFtmOverflowIrqParameterCallback"!][!ELSE!]NULL_PTR[!ENDIF!][!CR!]
                                },
[!ENDIF!]
#if (defined(FTM_PWM_IP_HAS_RELOAD_POINT) && (FTM_PWM_IP_HAS_RELOAD_POINT == STD_ON))
[!IF "./../../../PwmGeneral/PwmNotificationSupported"!][!//
    /* ReloadIrqEn */           (boolean)TRUE,
    /* ReloadCb */              {
        /* FunctionCallback */      &Pwm_Notification,
        /* CbParam */               0U
                                },
[!ELSE!][!//
    /* ReloadIrqEn */           (boolean)[!"text:toupper(PwmFtmInstCfg/PwmFtmReloadIrq)"!],
    /* ReloadCb */              {
        /* FunctionCallback */      [!WS "6"!][!IF "PwmFtmInstCfg/PwmFtmReloadIrq = 'true'"!][!"PwmFtmInstCfg/PwmFtmReloadIrqCallback/PwmFtmReloadIrqFunctionCallback"!][!ELSE!]NULL_PTR[!ENDIF!],
        /* CbParam */               [!WS "15"!][!IF "PwmFtmInstCfg/PwmFtmReloadIrq = 'true'"!][!"PwmFtmInstCfg/PwmFtmReloadIrqCallback/PwmFtmReloadIrqParameterCallback"!][!ELSE!]NULL_PTR[!ENDIF!][!CR!]
                                },
[!ENDIF!]
#endif
[!CALL "getEnumIndex", "enumPath" = "'PwmFtmInstCfg/PwmFtmDebugMode'", "enumSelectedValue" = "PwmFtmInstCfg/PwmFtmDebugMode"!]
    /* DebugMode */             [!"ecu:list('Pwm.FtmDebugMode')[num:i($enumIndex)]"!],
    /* WriteProtection */       (boolean)[!"text:toupper(PwmFtmInstCfg/PwmFtmWriteProtection)"!],
    /* InitTriggerEn */         (boolean)[!"text:toupper(PwmFtmInstCfg/PwmFtmInitTrigger)"!],
[!CALL "getEnumIndex", "enumPath" = "'PwmFtmInstCfg/PwmFtmInitTriggerMode'", "enumSelectedValue" = "PwmFtmInstCfg/PwmFtmInitTriggerMode"!]
    /* InitTrigMode */          [!"ecu:list('Pwm.FtmTrigger')[num:i($enumIndex)]"!],
[!CALL "getPeriodInTicks", "instance" = "$instanceId"!]
    /* PwmPeriod */             [!"$valuePeriod"!]U,
#if (defined(FTM_PWM_IP_HAS_DITHERING) && (FTM_PWM_IP_HAS_DITHERING == STD_ON))
    /* PwmPeriodDither */       [!"num:i(PwmFtmGlobalChCfg/PwmFtmPeriodDither)"!]U,
#endif
    /* DeadTimeValue */         [!"num:i(PwmFtmGlobalChCfg/PwmFtmDeadTime)"!]U,
[!CALL "getEnumIndex", "enumPath" = "'PwmFtmGlobalChCfg/PwmFtmDeadTimePrescaler'", "enumSelectedValue" = "PwmFtmGlobalChCfg/PwmFtmDeadTimePrescaler"!]
    /* DeadTimePs */            [!"ecu:list('Pwm.FtmDeadTimePrescaler')[num:i($enumIndex)]"!],
#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))
    /* FaultCtrMode */          FTM_PWM_IP_[!"node:value(FtmGlobalFaultCfg/FtmFaultFunctionality)"!],
    /* FaultOutState */         FTM_PWM_IP_OUT_[!"node:value(FtmGlobalFaultCfg/FtmFaultOutputState)"!],
    /* FaultInFilter */         [!"num:i(FtmGlobalFaultCfg/FtmFaultFilterValue)"!]U,
    /* FaultIrqEn */            (boolean)[!"text:toupper(FtmGlobalFaultCfg/FtmFaultIrqUsed)"!],
#endif
    /* SyncCfg */               &Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SyncCfg[!"$instanceId"!]
};


/* Ftm instance [!"$instanceId"!] paired channels initialization configuration */

    [!LOOP "./PwmFtmCh/*"!]
        [!IF "./PwmFtmPairChEnable = 'true'"!]
            [!VAR "channelPairId" = "num:i(num:div(substring-after(./PwmFtmChId, '_'), 2))"!]
            [!IF "PwmFtmPairedCh/PwmFtmDutyDitheringPaired"!]
                [!VAR "ditheringType" = "'FTM_PWM_IP_DITHER_TRAILING_EDGE'"!]
            [!ELSE!]
                [!VAR "ditheringType" = "'FTM_PWM_IP_DITHER_LEADING_EDGE'"!]
            [!ENDIF!]
            [!IF "num:i(num:mod(substring-after(./PwmFtmChId, '_'), 2)) = '1'"!]
                [!ERROR "Odd channel numbers cannot have pair configuration!"!]
            [!ENDIF!]
/* Ftm channel pair [!"$channelPairId"!] configuration */
const Ftm_Pwm_Ip_PairCfgType Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_ChPair[!"$channelPairId"!] =
{
    /* PairId */                [!"$channelPairId"!]U,
    /* DeadtimeEn */            (boolean)[!"text:toupper(PwmFtmPairedCh/PwmFtmPairedChDeadtimeEnable)"!],
    /* ComplementaryModeEn */   (boolean)[!"text:toupper(PwmFtmPairedCh/PwmFtmPairedChComplementary)"!],
[!CALL "getEnumIndex", "enumPath" = "'PwmFtmPairedCh/PwmFtmPairedChComplementaryMode'", "enumSelectedValue" = "PwmFtmPairedCh/PwmFtmPairedChComplementaryMode"!]
    /* PairChPolarity */        [!"ecu:list('Pwm.FtmPairPolarity')[num:i($enumIndex)]"!],
    /* PairExtTrigEn */         (boolean)[!"text:toupper(PwmFtmPairedCh/PwmFtmPairedChExtTrig)"!],
    /* PairSyncEn */            (boolean)[!"text:toupper(PwmFtmPairedCh/PwmFtmPairedChSync)"!],
    /* PhaseShiftValue */       [!"num:i(PwmFtmPairedCh/PwmFtmPairedChPhaseShift)"!]U,
#if (defined(FTM_PWM_IP_HAS_DITHERING) && (FTM_PWM_IP_HAS_DITHERING == STD_ON))
    /* DitherEdge */            [!"$ditheringType"!]
#endif
};
        [!ENDIF!]
    [!ENDLOOP!]


/* Ftm instance [!"$instanceId"!] channels initialization configuration */

    [!LOOP "./PwmFtmCh/*"!]
        [!VAR "channelId" = "substring-after(./PwmFtmChId, '_')"!]
/* Ftm channel [!"$channelId"!] configuration */
const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_Ch[!"$channelId"!] =
{
    /* ChannelId */             [!"$channelId"!]U,
    /* ChannelMode */           [!WS "11"!][!CALL "getChannelMode"!],
[!IF "./../../../../../PwmGeneral/PwmNotificationSupported"!][!//
    /* ChIrqEn */               (boolean)TRUE,
    /* ChannelCb */             {
        /* FunctionCallback */      &Pwm_Notification,
        /* CbParam */               [!"$channelId"!]U
                                },
[!ELSE!][!//
    /* ChIrqEn */               (boolean)[!"text:toupper(PwmFtmChInterrupt)"!],
    /* ChannelCb */             {
        /* FunctionCallback */      [!WS "7"!][!IF "PwmFtmChInterrupt = 'true' and ((./PwmFtmChInterruptCallback/PwmFtmChInterruptFunctionCallback) != 'NULL_PTR') and ((./PwmFtmChInterruptCallback/PwmFtmChInterruptFunctionCallback) != 'NULL') and ((./PwmFtmChInterruptCallback/PwmFtmChInterruptFunctionCallback) != '"NULL"')"!]&[!"PwmFtmChInterruptCallback/PwmFtmChInterruptFunctionCallback"!][!ELSE!]NULL_PTR[!ENDIF!],
        /* CbParam */               [!WS "16"!][!IF "PwmFtmChInterrupt = 'true' and ((./PwmFtmChInterruptCallback/PwmFtmChInterruptParameterCallback) != 'NULL_PTR') and ((./PwmFtmChInterruptCallback/PwmFtmChInterruptParameterCallback) != 'NULL') and ((./PwmFtmChInterruptCallback/PwmFtmChInterruptFunctionCallback) != '"NULL"')"!]&[!"PwmFtmChInterruptCallback/PwmFtmChInterruptParameterCallback"!][!ELSE!]NULL_PTR[!ENDIF!][!CR!]
                                },
[!ENDIF!]
    /* ChOutputEn */            (boolean)[!"text:toupper(PwmFtmChPwmOutputEnable)"!],
    /* SwControlEn */           (boolean)[!"text:toupper(PwmFtmChSwCtrlEnable)"!],
    /* SwControlVal */          (boolean)[!"text:toupper(PwmFtmChSwCtrlValue)"!],
    /* ExtTrigEn */             (boolean)[!"text:toupper(PwmFtmChExternTriggerEnable)"!],
    /* ChMatchLoadEn */         (boolean)[!"text:toupper(PwmFtmChMatchLoadPointEnable)"!],
[!CALL "getParamAsr", "instance" = "$instanceId", "channel" = "$channelId"!]
    /* DutyCycle */             [!"$valueDutyCycle"!]U,
#if (defined(FTM_PWM_IP_HAS_DITHERING) && (FTM_PWM_IP_HAS_DITHERING == STD_ON))
    /* DutyCycleDither */       [!"num:i(PwmFtmChDutyCycleDither)"!]U,
#endif
[!CALL "getParamAsr", "instance" = "$instanceId", "channel" = "$channelId"!]
    /* InitOut */               [!"$valueOutputState"!],
[!CALL "getParamAsr", "instance" = "$instanceId", "channel" = "$channelId"!]
    /* Polarity */              [!"$valuePolarity"!],
            [!IF "(./PwmFtmPairChEnable = 'true') and (num:i(num:mod(substring-after(./PwmFtmChId, '_'), 2)) = '0')"!]
                [!VAR "channelPairId" = "num:i(num:div(substring-after(./PwmFtmChId, '_'), 2))"!]
    /* PairCfg */               &Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_ChPair[!"$channelPairId"!]
            [!ELSE!]
    /* PairCfg */               NULL_PTR
            [!ENDIF!]
};
[!CR!]
    [!ENDLOOP!]

[!VAR "numFaultCfg" = "num:i(count(./FtmGlobalFaultCfg/FtmFaultSettings/*))"!]
[!IF "$numFaultCfg > 0"!]
#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))  
    [!LOOP "./FtmGlobalFaultCfg/FtmFaultSettings/*"!]
        [!VAR "faultId" = "substring-after(./FtmFaultId, '_')"!]
/* Ftm fault [!"$faultId"!] configuration */
const Ftm_Pwm_Ip_FaultChCfgType Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_Fault[!"$faultId"!] =
{
    /* FaultId */             [!"num:i($faultId)"!]U,
    /* FaultPol */            FTM_PWM_IP_[!"node:value(FtmFaultPolarity)"!],
    /* FaultFilEn */          (boolean)[!"text:toupper(FtmEnableFaultFilter)"!],
    /* FaultCb */             [!WS "13"!][!IF "((FtmFaultNotification != 'NULL_PTR') and (FtmFaultNotification != '"NULL"') and (FtmFaultNotification != 'NULL') and ($faultIsrUsed = 'true') and ($faultMode != 'FAULT_DISABLED'))"!]&[!"FtmFaultNotification"!][!ELSE!]NULL_PTR[!ENDIF!][!CR!]
};
[!CR!]
    [!ENDLOOP!]
/* Ftm fault configuration array */
const Ftm_Pwm_Ip_FaultChCfgType * const Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_FaultArray[[!"num:i($numFaultCfg)"!]U] =
{
    [!VAR "counter" = "num:i(count(./FtmGlobalFaultCfg/FtmFaultSettings/*))"!]
    [!LOOP "./FtmGlobalFaultCfg/FtmFaultSettings/*"!]
        [!VAR "faultIdx" = "substring-after(./FtmFaultId, '_')"!]
    &Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_Fault[!"$faultIdx"!][!IF "num:i($counter) > '1'"!],[!ENDIF!][!CR!]
        [!VAR "counter" = "$counter - 1"!]
    [!ENDLOOP!]
};
#endif
[!ENDIF!]

/* Ftm channels configuration array */
const Ftm_Pwm_Ip_ChannelConfigType * const Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_ChArray[[!"num:i(count(./PwmFtmCh/*))"!]U] =
{
    [!VAR "counter" = "num:i(count(./PwmFtmCh/*))"!]
    [!LOOP "./PwmFtmCh/*"!]
        [!VAR "channelId" = "substring-after(./PwmFtmChId, '_')"!]
    &Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_Ch[!"$channelId"!][!IF "num:i($counter) > '1'"!],[!ENDIF!][!CR!]
        [!VAR "counter" = "$counter - 1"!]
    [!ENDLOOP!]
};

/* Ftm instance [!"$instanceId"!] User configuration structure */
const Ftm_Pwm_Ip_UserCfgType Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_UserCfg[!"$instanceId"!] =
{
    /* InstanceCfg */           &Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_InstCfg[!"$instanceId"!],
    /* ConfiguredChArray */     Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_ChArray,
    /* NoOfConfiguredCh */      [!"num:i(count(./PwmFtmCh/*))"!]U
#if (defined(FTM_PWM_IP_HAS_FAULT) && (FTM_PWM_IP_HAS_FAULT == STD_ON))
    ,
[!IF "$numFaultCfg > 0"!]
    /* ConfiguredFaultArray */  Ftm_Pwm_Ip[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_I[!"$instanceId"!]_FaultArray,
    /* NoOfFaultCfg */          [!"num:i(count(./FtmGlobalFaultCfg/FtmFaultSettings/*))"!]U
[!ELSE!]
    /* ConfiguredFaultArray */  NULL_PTR,
    /* NoOfFaultCfg */          0U
[!ENDIF!]
#endif 
};
[!CR!]
[!ENDLOOP!]

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
#endif  /* FTM_PWM_IP_PRECOMPILE_SUPPORT */

#ifdef __cplusplus
}
#endif

/** @} */

[!ENDCODE!]
