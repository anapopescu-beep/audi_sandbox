[!NOCODE!][!//
/**
    @file    Trgmux_Ip_RegOperations.m
    @version 1.0.1

    @brief   AUTOSAR Mcl - Register operations.
    @details Register operations.

    Project RTD AUTOSAR 4.4
    Platform CORTEXM
    Peripheral DMA,CACHE,TRGMUX,FLEXIO
    Dependencies none

    ARVersion 4.4.0
    ARRevision ASR_REL_4_4_REV_0000
    ARConfVariant
    SWVersion 1.0.1
    BuildVersion S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224

    (c) Copyright 2020-2022 NXP Semiconductors
    All Rights Reserved.
 */
[!//
[!MACRO "Trgmux_Ip_GetNrOfLogicGroups"!][!//
[!NOCODE!][!//
[!VAR "NrOfLogicGroups" = "0"!][!//
[!LOOP "./MclConfig/trgmuxLogicGroup/*"!][!//
[!VAR "NrOfLogicGroups" = "num:i($NrOfLogicGroups + 1)"!][!//
[!ENDLOOP!][!//
[!CODE!][!"num:i($NrOfLogicGroups)"!][!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//
[!//
[!//
[!MACRO "Trgmux_Ip_GetNrOfLogicTriggers"!][!//
[!NOCODE!][!//
[!VAR "NrOfLogicTriggers" = "0"!][!//
[!LOOP "./MclConfig/trgmuxLogicGroup/*"!][!//
[!LOOP "./trgmuxLogicTrigger/*"!][!//
[!VAR "NrOfLogicTriggers" = "num:i($NrOfLogicTriggers + 1)"!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!CODE!][!"num:i($NrOfLogicTriggers)"!][!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//
[!//
[!//
[!MACRO "Trgmux_Ip_LogicTriggerConfig","Type"!][!//
[!NOCODE!][!//
[!CODE!]
/* TRGMUX Logic Trigger Configuration */
[!VAR "NrOfLogicTriggers" = "0"!][!//
[!VAR "LogicGroupLock" = "0"!][!//
[!LOOP "./MclConfig/trgmuxLogicGroup/*"!][!//
[!VAR "LogicGroupLock" = "node:value(trgmuxLogicGroup_Lock)"!][!//
[!LOOP "./trgmuxLogicTrigger/*"!][!//
[!VAR "NrOfLogicTriggers" = "num:i($NrOfLogicTriggers + 1)"!][!//
const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger[!"num:i($NrOfLogicTriggers - 1)"!]Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* uint8 LogicChannel; */         [!"node:value(trgmuxLogicTrigger_Name)"!],
    /* uint8 Output; */               [!"node:value(trgmuxLogicTrigger_Output)"!],
    /* uint8 Input; */                [!"node:value(trgmuxLogicTrigger_Input)"!],
    /* uint8 HwInstId; */             TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */               (boolean)[!"text:toupper($LogicGroupLock)"!],
};
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//
[!//
[!//
[!MACRO "Trgmux_Ip_Init","Type"!][!//
[!NOCODE!][!//
[!VAR "NrOfLogicTriggers"!][!CALL "Trgmux_Ip_GetNrOfLogicTriggers"!][!ENDVAR!][!//
[!CODE!]
/* TRGMUX Initialization Structure */
const Trgmux_Ip_InitType Trgmux_Ip_xTrgmuxInit[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!ENDCODE!][!//
    [!IF "$NrOfLogicTriggers > num:i(0)"!][!//
[!CODE!][!//
    /* Trgmux_Ip_LogicTriggerType * paxLogicTrigger[] */
    {
[!VAR "LogicTriggerIndex" = "0"!][!//
[!LOOP "./MclConfig/trgmuxLogicGroup/*"!][!//
[!LOOP "./trgmuxLogicTrigger/*"!][!//
[!VAR "LogicTriggerIndex" = "num:i($LogicTriggerIndex + 1)"!][!//
        &Trgmux_Ip_LogicTrigger[!"num:i($LogicTriggerIndex - 1)"!]Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
[!ENDLOOP!][!//
[!ENDLOOP!][!//
    }
[!ENDCODE!][!//
    [!ELSE!][!//
[!CODE!][!//
    /* Trgmux_Ip_LogicTriggerType * paxLogicTrigger[] */                       NULL_PTR,
[!ENDCODE!][!//
    [!ENDIF!][!//
[!CODE!][!//
};
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!ENDNOCODE!]
