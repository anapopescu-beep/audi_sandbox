[!NOCODE!]
/**
    @file    Power_Ip_RegOperations.m
    @version 1.0.1

    @brief   AUTOSAR Mcu - Register operations.
    @details Register operations.

    Project RTD AUTOSAR 4.4
    Platform CORTEXM
    Peripheral 
    Dependencies none

    ARVersion 4.4.0
    ARRevision ASR_REL_4_4_REV_0000
    ARConfVariant
    SWVersion 1.0.1
    BuildVersion S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224

    (c) Copyright 2020-2022 NXP Semiconductors
    All Rights Reserved.
 */



[!MACRO "Power_Ip_Mode_Config","Type"!][!//
[!NOCODE!][!//
[!CODE!][!//
/**
* @brief          Initialization mode data.
* @details        Static configuration realized by calling Mcu_SetMode() API.
*
*/
const Power_Ip_ModeConfigType Power_Ip_aModeConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(McuModuleConfiguration/McuModeSettingConf/*))"!]U] =
{
[!ENDCODE!][!//
    [!IF "num:i(count(McuModuleConfiguration/McuModeSettingConf/*))>0"!]
        [!VAR "ModeConfigs"= "num:i(count(McuModuleConfiguration/McuModeSettingConf/*))-1"!]
        [!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!]
[!CODE!][!//
    /* Start of Mcu_aModeConfig[[!"@index"!]] */
    {
[!ENDCODE!][!//
        [!VAR "PCindex" = "@index"!]
[!CODE!][!//
        /* Mode Configuration ID. */
        (Power_Ip_ModeType)[!"num:i(McuMode)"!]U,

        /* The Power Mode name (code). */
        POWER_IP_[!"McuPowerMode"!]_MODE,

        /* The Sleep On Exit configuration */
        [!IF "McuEnableSleepOnExit='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    }[!IF "$PCindex < $ModeConfigs"!],[!ENDIF!] /* End of Mcu_aModeConfig[[!"@index"!]] */
[!ENDCODE!][!//
        [!ENDLOOP!][!//McuModeSettingConf/*
    [!ENDIF!][!//
[!CODE!][!//
};
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Power_Ip_PMC_Config","Type"!][!//
[!NOCODE!]
[!SELECT "McuModuleConfiguration"!]
[!CODE!]
/**
* @brief          Initialization data for PMC hw IP.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static const Power_Ip_PMC_ConfigType Power_Ip_PMC_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    [!IF "(ecu:get('MCU.PMC.LVDSC1.SUPPORT') = 'true')"!]
    /* Low Voltage Detect Status and Control 1 Register (PMC_LVDSC1). This register only exist on 1xx series of devices */
    (
        [!IF "McuPowerControl/McuLowVoltageDetectInterruptEnable='true'"!]PMC_LVDSC1_LVD_ENABLE_U8[!ELSE!]PMC_LVDSC1_LVD_DISABLE_U8[!ENDIF!] |
        [!IF "McuPowerControl/McuLowVoltageDetectResetEnable='true'"!]PMC_LVDSC1_LVDRE_ENABLE_U8[!ELSE!]PMC_LVDSC1_LVDRE_DISABLE_U8[!ENDIF!]
    ),
    [!ENDIF!]
    /* Low Voltage Detect Status and Control 2 Register (PMC_LVDSC2) */
    (
        [!IF "McuPowerControl/McuLowVoltageWarningInterruptEnable = 'true'"!]PMC_LVDSC2_LVW_ENABLE_U8[!ELSE!]PMC_LVDSC2_LVW_DISABLE_U8[!ENDIF!]
    ),
    /* Regulator Status and Control Register (PMC_REGSC) */
    (
        [!IF "McuPowerControl/McuLPODisable = 'true'"!]PMC_REGSC_LPO_DISABLE_U8[!ELSE!]PMC_REGSC_LPO_ENABLE_U8[!ENDIF!] |
        [!IF "McuPowerControl/McuClockBiasDisable = 'true'"!]PMC_REGSC_CLKBIAS_DISABLE_U8[!ELSE!]PMC_REGSC_CLKBIAS_ENABLE_U8[!ENDIF!] |
        [!IF "McuPowerControl/McuLowPowerBiasEnable = 'true'"!]PMC_REGSC_BIAS_ENABLE_U8[!ELSE!]PMC_REGSC_BIAS_DISABLE_U8[!ENDIF!]
    )
};
[!ENDCODE!]
[!ENDSELECT!][!//McuModuleConfiguration
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "Power_Ip_RCM_Config","Type"!][!//
[!NOCODE!]
[!SELECT "McuModuleConfiguration"!]
[!CODE!]
/**
* @brief          Initialization data for RCM hw IP.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/

static const Power_Ip_RCM_ConfigType Power_Ip_RCM_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Reset Pin Control register (RCM_RPC) */
    (
        RCM_RPC_STOP_[!"McuResetConfig/McuResetPinFilterInStopMode"!]_U32 |
        RCM_RPC_NORMAL_[!"McuResetConfig/McuResetPinFilterInRunAndWait"!]_U32 |
        RCM_RPC_RSTFLTSEL((uint32)([!"num:i(McuResetConfig/McuResetPinFilterBusClockSelect)"!]U))
    ),
    /* System Reset Interrupt Enable Register (RCM_SRIE) */
    (
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuStopAcknowledgeErrorInterrupt"!]RCM_SRIE_SACKERR_INT_EN_U32[!ELSE!]RCM_SRIE_SACKERR_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuMDMAPSystemResetInterrupt"!]RCM_SRIE_MDM_AP_INT_EN_U32[!ELSE!]RCM_SRIE_MDM_AP_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuSoftwareInterrupt"!]RCM_SRIE_SW_INT_EN_U32[!ELSE!]RCM_SRIE_SSW_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuCoreLockupInterrupt"!]RCM_SRIE_LOCKUP_INT_EN_U32[!ELSE!]RCM_SRIE_LOCKUP_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuJTAGResetInterrupt"!]RCM_SRIE_JTAG_INT_EN_U32[!ELSE!]RCM_SRIE_JTAG_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuGlobalInterrupt"!]RCM_SRIE_GIE_INT_EN_U32[!ELSE!]RCM_SRIE_GIE_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuExternalResetPinInterrupt"!]RCM_SRIE_PIN_INT_EN_U32[!ELSE!]RCM_SRIE_PIN_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuWatchdogInterrupt"!]RCM_SRIE_WDOG_INT_EN_U32[!ELSE!]RCM_SRIE_WDOG_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuCMULossOfClockResetInterrupt"!]RCM_SRIE_CMU_INT_EN_U32[!ELSE!]RCM_SRIE_CMU_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuLossOfLockInterrupt"!]RCM_SRIE_LOL_INT_EN_U32[!ELSE!]RCM_SRIE_LOL_INT_DIS_U32[!ENDIF!] |
        [!IF "McuResetConfig/McuSystemInterruptEnable/McuLossOfClockInterrupt"!]RCM_SRIE_LOC_INT_EN_U32[!ELSE!]RCM_SRIE_LOC_INT_DIS_U32[!ENDIF!] |
        RCM_SRIE_[!"McuResetConfig/McuSystemInterruptEnable/McuResetDelayTime"!]_U32
    )
};
[!ENDCODE!]
[!ENDSELECT!][!//McuModuleConfiguration
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "Power_Ip_SMC_Config","Type"!][!//
[!NOCODE!]
[!SELECT "McuModuleConfiguration"!]
[!CODE!]
/**
* @brief          Initialization data for SMC hw IP.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static const Power_Ip_SMC_ConfigType Power_Ip_SMC_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Allowed modes */
    (
        [!IF "McuAllowedModes/McuAllowHighSpeedRunMode = 'true'"!]SMC_PMPROT_HSRUN_ALLOWED_U32[!ELSE!]SMC_PMPROT_HSRUN_NOT_ALLOWED_U32[!ENDIF!] |
        [!IF "McuAllowedModes/McuAllowVeryLowPowerModes = 'true'"!]SMC_PMPROT_VLP_ALLOWED_U32[!ELSE!]SMC_PMPROT_VLP_NOT_ALLOWED_U32[!ENDIF!]
    ),
};
[!ENDCODE!]
[!ENDSELECT!][!//McuModuleConfiguration
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "Power_Ip_HwIPs_Config","Type"!][!//
[!NOCODE!]
[!CODE!]
/**
* @brief          Initialization data for different hw IPs.
* @details        Static configuration realized at startup by calling Mcu_Init() API.
*
*/
const Power_Ip_HwIPsConfigType Power_Ip_HwIPsConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Configuration for RCM (Reset Control Module) hardware IP. */
    &Power_Ip_RCM_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],

    /* Configuration for PMC (Power Management Controller) hardware IP */
    &Power_Ip_PMC_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],

    /* Configuration for SMC hardware IP. */
    &Power_Ip_SMC_Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!ENDNOCODE!][!//


