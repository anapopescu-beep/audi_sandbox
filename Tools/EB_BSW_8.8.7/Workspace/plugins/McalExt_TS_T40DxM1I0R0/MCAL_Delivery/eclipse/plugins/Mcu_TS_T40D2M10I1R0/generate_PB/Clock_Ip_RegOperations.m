[!NOCODE!]
/**
    @file    Clock_Ip_RegOperations.m
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

[!NOCODE!]
[!VAR "HwpIrcoscCount" = "count(ecu:list('MCU.IRCOSC.List'))"!]
[!VAR "HwpXoscsCount" = "count(ecu:list('MCU.XOSC.List'))"!]
[!VAR "HwpllsCount" = "count(ecu:list('MCU.PLL.List'))"!]
[!VAR "HwSelectorCount" = "count(ecu:list('MCU.SELECTOR.Names.List'))"!]
[!VAR "NrOfCSG_SCS" = "count(ecu:list('MCU.SystemClk.List'))"!]
[!VAR "NrOfCSG_DIV" = "count(ecu:list('MCU.SystemClk.DIV.List'))"!]
[!VAR "NrOfIRC_DIV" = "count(ecu:list('MCU.IRCOSC.DIV.List'))"!]
[!VAR "NrOfXOSC_DIV" = "count(ecu:list('MCU.XOSC.DIV.List'))"!]
[!VAR "NrOfPLL_DIV" = "count(ecu:list('MCU.PLL.DIV.List'))"!]
[!VAR "NrOfSIM_DIV" = "count(ecu:list('MCU.SIM.DIV.List'))"!]
[!VAR "NrOfSIM_CHIPCTL" = "count(ecu:list('MCU.SIM.CHIPCTL.List'))"!]
[!VAR "NrOfSIM_LPOCLKS" = "count(ecu:list('MCU.SIM.LPOCLKS.List'))"!]
[!VAR "NrOfSIM_FTMOPT0" = "count(ecu:list('MCU.SIM.FTMOPT0.List'))"!]
[!VAR "NrOfPCC" = "count(ecu:list('MCU.PerSource.List'))"!]
[!VAR "NrOfPCC_Plat" = "count(ecu:list('MCU.PerSourceWithPcsFromPlat.List'))"!]
[!VAR "NrOfPCC_Slow" = "count(ecu:list('MCU.PerSourceWithPcsFromSlow.List'))"!]
[!VAR "NrOfPCC_WithPcd" = "count(ecu:list('MCU.PerSourceWithPcd.List'))"!]
[!VAR "HwDividerCount" = "count(ecu:list('MCU.DIVIDER.Names.List'))"!]
[!VAR "NrOfClkExternal" = "count(ecu:list('MCU.ExtClock.List'))"!]
[!VAR "HwGatesCount" = "count(ecu:list('MCU.GATE.Names.List'))"!]
[!VAR "NrOfClkMonitor" = "count(ecu:list('MCU.CMU_FC.List'))"!]
[!ENDNOCODE!][!//

[!MACRO "Count_Ircoscs","Config"!][!//
[!NOCODE!]
    [!VAR "ircoscsCount" = "0"!]
    [!IF "node:exists("McuFIRCClockConfig")"!]
        [!IF "node:value("McuFIRCClockConfig/McuFIRCUnderMcuControl")"!]
            [!VAR "ircoscsCount" = "$ircoscsCount + 1"!]
        [!ENDIF!]
    [!ENDIF!]
    [!IF "node:exists("McuSIRCClockConfig")"!]
        [!IF "node:value("McuSIRCClockConfig/McuSIRCUnderMcuControl")"!]
            [!VAR "ircoscsCount" = "$ircoscsCount + 1"!]
        [!ENDIF!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($ircoscsCount)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Xoscs","Config"!][!//
[!NOCODE!]
    [!VAR "xoscsCount" = "0"!]
    [!IF "node:exists("McuSystemOSCClockConfig")"!]
        [!IF "node:value("McuSystemOSCClockConfig/McuSOSCUnderMcuControl")"!]
            [!VAR "xoscsCount" = "$xoscsCount + 1"!]
        [!ENDIF!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($xoscsCount)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Plls","Config"!][!//
[!NOCODE!]
    [!VAR "NumOfPllUnderMcuCtr" = "0"!]
    [!FOR "PllCount" = "1" TO "num:i($HwpllsCount)"!][!//
        [!VAR "Name" = "ecu:list('MCU.PLL.List')[number($PllCount)]"!][!//
        [!VAR "capitalPLL" = "text:replace($Name,substring($Name,1),'SystemPll')"!][!//
        [!VAR "PllPath" = "concat('Mcu',$capitalPLL)"!]
        [!IF "node:exists($PllPath)"!]
            [!VAR "McuControlPllPath" = "concat($PllPath,'/',$PllPath,'UnderMcuControl')"!]
            [!IF "node:value($McuControlPllPath)"!]
                [!VAR "NumOfPllUnderMcuCtr" = "$NumOfPllUnderMcuCtr  + 1"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDFOR!]
[!CODE!][!//
[!"num:i($NumOfPllUnderMcuCtr)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Selectors","Config"!][!//
[!NOCODE!]
    [!VAR "selectorsCount" = "0"!]
        [!FOR "SelectorCSG_SCS" = "1" TO "num:i($NrOfCSG_SCS)"!]
            [!VAR "NameSelector" = "ecu:list('MCU.SystemClk.List')[number($SelectorCSG_SCS)]"!][!//
            [!VAR "capitalNameSelector" = "text:replace($NameSelector,substring($NameSelector,2),text:tolower(substring($NameSelector,2)))"!]
            [!VAR "SelectorPath" = "concat('Mcu',$capitalNameSelector,'ClockConfig/McuSystemClockSwitch')"!]
            [!IF "node:exists($SelectorPath)"!]
                [!VAR "ControlPath" = "'./McuSysClockUnderMcuControl'"!]
                [!IF "node:value($ControlPath)"!]
                    [!VAR "selectorsCount" = "$selectorsCount + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
        
        [!VAR "SelectorSCG_CLKOUTPath" = "'./McuScgClkOutSelect'"!]
        [!IF "node:exists($SelectorSCG_CLKOUTPath)"!]
            [!VAR "ControlPath" = "'./McuSysClockUnderMcuControl'"!]
            [!IF "node:value($ControlPath)"!]
                [!VAR "selectorsCount" = "$selectorsCount + 1"!]
            [!ENDIF!]
        [!ENDIF!]
        
        [!FOR "SelectorSIM_CHIPCTL" = "1" TO "num:i($NrOfSIM_CHIPCTL)"!]
            [!VAR "NameSelector" = "ecu:list('MCU.SIM.CHIPCTL.List')[number($SelectorSIM_CHIPCTL)]"!][!//
            [!VAR "SelectorPath" = "concat('McuSIMClockConfig/McuSimChipConfiguration/Mcu',$NameSelector,'Select')"!]
            [!IF "node:exists($SelectorPath)"!]
                [!VAR "ControlPath" = "'./McuSIMClockConfig/McuSIMUnderMcuControl'"!]
                [!IF "node:value($ControlPath)"!]
                    [!VAR "selectorsCount" = "$selectorsCount + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
        
        [!FOR "SelectorSIM_LPOCLKS" = "1" TO "num:i($NrOfSIM_LPOCLKS)"!]
            [!VAR "NameSelector" = "ecu:list('MCU.SIM.LPOCLKS.List')[number($SelectorSIM_LPOCLKS)]"!][!//
            [!VAR "SelectorPath" = "concat('McuSIMClockConfig/McuSimLpoConfiguration/Mcu',$NameSelector,'ClkSelect')"!]
            [!IF "node:exists($SelectorPath)"!]
                [!VAR "ControlPath" = "'./McuSIMClockConfig/McuSIMUnderMcuControl'"!]
                [!IF "node:value($ControlPath)"!]
                    [!VAR "selectorsCount" = "$selectorsCount + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
        
        [!FOR "SelectorSIM_FTMOPT0" = "1" TO "num:i($NrOfSIM_FTMOPT0)"!]
            [!VAR "NameSelector" = "ecu:list('MCU.SIM.FTMOPT0.List')[number($SelectorSIM_FTMOPT0)]"!][!//
            [!VAR "SelectorPath" = "concat('McuSIMClockConfig/McuSimFtmConfiguration/Mcu',$NameSelector,'ExternalClockPinSelect')"!]
            [!IF "node:exists($SelectorPath)"!]
                [!VAR "ControlPath" = "'./McuSIMClockConfig/McuSIMUnderMcuControl'"!]
                [!IF "node:value($ControlPath)"!]
                    [!VAR "selectorsCount" = "$selectorsCount + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
        
        [!FOR "IndexPCC" = "1" TO "num:i($NrOfPCC)"!]
            [!VAR "SelectorPath" = "concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',$IndexPCC - 1,'/McuPerName')"!]
            [!VAR "SelectorClock" = "concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',$IndexPCC - 1,'/McuPeripheralClockSelect')"!]
            [!VAR "NamePCC" = "ecu:list('MCU.PerSource.List')[number($IndexPCC)]"!][!//
            [!FOR "IndexPCC_Plat" = "1" TO "num:i($NrOfPCC_Plat)"!]
                [!VAR "NamePCC_Plat" = "ecu:list('MCU.PerSourceWithPcsFromPlat.List')[number($IndexPCC_Plat)]"!][!//
                [!IF "$NamePCC_Plat= $NamePCC"!]
                    [!VAR "ControlPath" = "concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',num:i($IndexPCC - 1),'/McuPeripheralClockUnderMcuControl')"!]
                    [!IF "node:value($ControlPath)"!]
                        [!VAR "selectorsCount" = "$selectorsCount + 1"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
            
            [!FOR "IndexPCC_Slow" = "1" TO "num:i($NrOfPCC_Slow)"!]
                [!VAR "NamePCC_Slow" = "ecu:list('MCU.PerSourceWithPcsFromSlow.List')[number($IndexPCC_Slow)]"!][!//
                [!IF "$NamePCC_Slow= $NamePCC"!]
                    [!VAR "ControlPath" = "concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',num:i($IndexPCC - 1),'/McuPeripheralClockUnderMcuControl')"!]
                    [!IF "node:value($ControlPath)"!]
                        [!VAR "selectorsCount" = "$selectorsCount + 1"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
        [!ENDFOR!]

[!CODE!][!//
[!"num:i($selectorsCount)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Dividers","Config"!][!//
[!NOCODE!]
    [!VAR "NumOfDivUnderMcuCtr" = "0"!]
    [!FOR "DividerCSG" = "1" TO "num:i($NrOfCSG_SCS)"!]
        [!VAR "NameSystemClk" = "ecu:list('MCU.SystemClk.List')[number($DividerCSG)]"!][!//
        [!VAR "capitalNameSystemClk" = "text:replace($NameSystemClk,substring($NameSystemClk,2),text:tolower(substring($NameSystemClk,2)))"!]
        [!FOR "DividerCSG_DIV" = "1" TO "num:i($NrOfCSG_DIV)"!]
            [!IF "node:exists($SelectorPath)"!]
                [!VAR "ControlPath" = "'./McuSysClockUnderMcuControl'"!]
                [!IF "node:value($ControlPath)"!]
                    [!VAR "NumOfDivUnderMcuCtr" = "$NumOfDivUnderMcuCtr + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDFOR!]
    
    [!FOR "IndexIRC" = "1" TO "num:i($HwpIrcoscCount)"!]
        [!VAR "NameIRC" = "ecu:list('MCU.IRCOSC.List')[number($IndexIRC)]"!][!//
        [!FOR "IndexDividerIRC" = "1" TO "num:i($NrOfIRC_DIV)"!]
            [!VAR "DividerIRC" = "ecu:list('MCU.IRCOSC.DIV.List')[number($IndexDividerIRC)]"!][!//
            [!VAR "DividerIRCPath" = "concat('Mcu',$NameIRC,'ClockConfig/Mcu',$NameIRC,$DividerIRC)"!]
            [!IF "node:exists($DividerIRCPath)"!]
                [!VAR "ControlPath" = "concat('./Mcu',$NameIRC,'ClockConfig/Mcu',$NameIRC,'UnderMcuControl')"!]
                [!IF "node:value($ControlPath)"!]
                    [!VAR "NumOfDivUnderMcuCtr" = "$NumOfDivUnderMcuCtr + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDFOR!]
    
    [!FOR "IndexXOSC" = "1" TO "num:i($HwpXoscsCount)"!]
        [!VAR "NameXOSC" = "ecu:list('MCU.XOSC.List')[number($IndexXOSC)]"!][!//
        [!VAR "capitalNameXOSC" = "text:replace($NameXOSC,substring($NameXOSC,1),'SystemOSC')"!][!//
        [!FOR "IndexDividerXOSC" = "1" TO "num:i($NrOfXOSC_DIV)"!]
            [!VAR "DividerXOSC" = "ecu:list('MCU.XOSC.DIV.List')[number($IndexDividerXOSC)]"!][!//
            [!VAR "DividerXOSCPath" = "concat('Mcu',$capitalNameXOSC,'ClockConfig/Mcu',$NameXOSC,$DividerXOSC)"!]
            [!IF "node:exists($DividerXOSCPath)"!]
                [!VAR "ControlPath" = "concat('./Mcu',$capitalNameXOSC,'ClockConfig/Mcu',$NameXOSC,'UnderMcuControl')"!]
                [!IF "node:value($ControlPath)"!]
                    [!VAR "NumOfDivUnderMcuCtr" = "$NumOfDivUnderMcuCtr + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDFOR!]
    
    [!FOR "IndexPLL" = "1" TO "num:i($HwpllsCount)"!]
        [!VAR "NamePLL" = "ecu:list('MCU.PLL.List')[number($IndexPLL)]"!][!//
        [!VAR "capitalNamePLL" = "text:replace($NamePLL,substring($NamePLL,1),'SystemPll')"!][!//
        [!FOR "IndexDividerPLL" = "1" TO "num:i($NrOfPLL_DIV)"!]
            [!VAR "DividerPLL" = "ecu:list('MCU.PLL.DIV.List')[number($IndexDividerPLL)]"!][!//
            [!VAR "DividerPLLPath" = "concat('Mcu',$capitalNamePLL,'/Mcu',$NamePLL,$DividerPLL)"!]
            [!IF "node:exists($DividerPLLPath)"!]
                [!VAR "ControlPath" = "concat('./Mcu',$capitalNamePLL,'/Mcu',$capitalNamePLL,'UnderMcuControl')"!]
                [!IF "node:value($ControlPath)"!]
                    [!VAR "NumOfDivUnderMcuCtr" = "$NumOfDivUnderMcuCtr + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDFOR!]

    [!FOR "IndexDividerSIM" = "1" TO "num:i($NrOfSIM_DIV)"!]
        [!VAR "DividerSIM" = "ecu:list('MCU.SIM.DIV.List')[number($IndexDividerSIM)]"!][!//
        [!VAR "DividerSIMPath" = "concat('McuSIMClockConfig/McuSimChipConfiguration/Mcu',$DividerSIM,'Divider')"!]
        [!IF "node:exists($DividerSIMPath)"!]
            [!VAR "ControlPath" = "'McuSIMClockConfig/McuSIMUnderMcuControl'"!]
            [!IF "node:value($ControlPath)"!]
                [!VAR "NumOfDivUnderMcuCtr" = "$NumOfDivUnderMcuCtr + 1"!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDFOR!]

    [!FOR "IndexDividerPer" = "1" TO "num:i($NrOfPCC)"!] 
        [!VAR "DividerPer" = "ecu:list('MCU.PerSource.List')[number($IndexDividerPer)]"!][!//
        [!FOR "IndexDividerPerWithPcd" = "1" TO "num:i($NrOfPCC_WithPcd)"!]
            [!VAR "NamePCC_WithPcd" = "ecu:list('MCU.PerSourceWithPcd.List')[number($IndexDividerPerWithPcd)]"!][!//
            [!IF "$DividerPer = $NamePCC_WithPcd"!]
                [!VAR "ControlPath" = "concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',num:i($IndexDividerPer - 1),'/McuPeripheralClockUnderMcuControl')"!]
                [!IF "node:value($ControlPath)"!]
                    [!VAR "NumOfDivUnderMcuCtr" = "$NumOfDivUnderMcuCtr + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDFOR!]

[!CODE!][!//
[!"num:i($NumOfDivUnderMcuCtr)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Clk_Monitor","Config"!][!//
[!NOCODE!]
    [!VAR "NumOfClkMonitor" = "0"!]
    [!IF "node:exists("McuClkMonitor")"!]
        [!LOOP "./McuClkMonitor/*"!]
            [!IF "node:value(./McuClockMonitorUnderMcuControl)"!]
                [!VAR "NumOfClkMonitor" = "$NumOfClkMonitor + 1"!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($NumOfClkMonitor)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetCmuEnable"!][!//
[!NOCODE!]
    [!VAR "CmuEn"!][!IF "node:value('./McuClkMonitorEn')"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
[!CODE!][!//
[!"num:i($CmuEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetCmuInterruptEnable"!][!//
[!NOCODE!]
[!VAR "CmuInterruptEn" = "0"!][!//
[!IF "node:value('./McuMonitorInterruptEn')"!][!//
[!VAR "CmuInterruptEn" = "1"!][!//
[!ENDIF!][!//
[!CODE!][!//
[!"num:i($CmuInterruptEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_ExtClks","Config"!][!//
[!NOCODE!][!//
    [!VAR "extClksCount" = "count(ecu:list('MCU.ExtClock.List'))"!][!//
[!CODE!][!//
[!"num:i($extClksCount)"!][!//
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_Gates","Config"!][!//
[!NOCODE!]
    [!VAR "NumOfGateUnderMcuCtr" = "0"!]
    [!VAR "McuControlSimGatePath" = "'./McuSIMClockConfig/McuSIMUnderMcuControl'"!]
    [!FOR "GateCount" = "1" TO "num:i($HwGatesCount)"!][!//
        [!VAR "Name" = "ecu:list('MCU.GATE.Names.List')[number($GateCount)]"!][!//
        
[!FOR "PCCCount" = "1" TO "num:i($NrOfPCC)"!][!//
[!IF "node:value(concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',$PCCCount - 1,'/McuPerName')) = substring-before($Name,'_')"!][!//
        [!VAR "McuControlGatePath" = "concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',$PCCCount - 1,'/McuPeripheralClockUnderMcuControl')"!]
[!// Check clock gate PCC_[peripheral][CGC]
        [!IF "node:exists(concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',$PCCCount - 1,'/McuPerName'))"!]
            [!IF "node:value($McuControlGatePath)"!]
                [!VAR "NumOfGateUnderMcuCtr" = "$NumOfGateUnderMcuCtr  + 1"!]
            [!ENDIF!]
        [!ENDIF!]
[!ENDIF!]  
[!ENDFOR!]

        [!IF "node:value($McuControlSimGatePath)"!]
[!// Check clock gate SIM_PLATCGC[]
            [!IF "node:exists(concat('./McuSIMClockConfig/Mcu',substring-before($Name,'0_'),'ClockGatingEnable'))"!]
                    [!VAR "NumOfGateUnderMcuCtr" = "$NumOfGateUnderMcuCtr  + 1"!]
            [!ENDIF!]
[!// Check clock gate SIM_CHIPCTL[]
            [!IF "node:exists(concat('./McuSIMClockConfig/McuSimChipConfiguration/Mcu',substring-before($Name,'0_'),'Enable'))"!]
                    [!VAR "NumOfGateUnderMcuCtr" = "$NumOfGateUnderMcuCtr  + 1"!]
            [!ENDIF!]
[!// Check clock gate SIM_LPOCLKS[]
            [!IF "node:exists(concat('./McuSIMClockConfig/McuSimLpoConfiguration/Mcu',substring-before($Name,'_CLK'),'ClockEnable'))"!]
                    [!VAR "NumOfGateUnderMcuCtr" = "$NumOfGateUnderMcuCtr  + 1"!]
            [!ENDIF!]
        [!ENDIF!] 
        
    [!ENDFOR!]
[!CODE!][!//
[!"num:i($NumOfGateUnderMcuCtr)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Count_configureFrequencies","Config"!][!//
[!NOCODE!][!//
    [!VAR "configureFrequenciesCount" = "count(ecu:list('MCU.ConfiguredFrequency.List'))"!][!//
[!CODE!][!//
[!"num:i($configureFrequenciesCount)"!][!//
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetIrcoscEn","Name"!][!//
[!NOCODE!]
    [!VAR "enPath" = "concat('Mcu',$Name,'ClockConfig/Mcu',$Name,'Enable')"!]
    [!VAR "ircoscEn"!][!IF "node:value($enPath)"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
[!CODE!][!//
[!"num:i($ircoscEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetIrcoscRegulatorEn","Name"!][!//
[!NOCODE!]
    [!VAR "enRegulatorPath" = "concat('Mcu',$Name,'ClockConfig/Mcu',$Name,'RegulatorEnable')"!]
    [!IF "node:exists($enRegulatorPath)"!]
        [!VAR "ircoscRegulatorEn"!][!IF "node:value($enRegulatorPath)"!]0[!ELSE!]1[!ENDIF!][!ENDVAR!]
    [!ELSE!]
        [!VAR "ircoscRegulatorEn" = "0"!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($ircoscRegulatorEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetIrcoscRange","Name"!][!//
[!NOCODE!]
    [!VAR "RangePath" = "concat('Mcu',$Name,'ClockConfig/Mcu',$Name,'RangeSelect')"!]
    [!IF "node:value($RangePath) = 'TRIMMED_TO_48MHZ'"!]
        [!VAR "ircoscRange" = "num:i(0)"!]
    [!ELSE!]
        [!IF "node:value($RangePath) = 'HIGH_RANGE_CLOCK'"!]
            [!VAR "ircoscRange" = "num:i(1)"!]
        [!ELSE!]
            [!VAR "ircoscRange" = "num:i(0)"!]
        [!ENDIF!]
    [!ENDIF!]
[!CODE!][!//
[!"($ircoscRange)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetIrcoscLowPowerModeEnable","Name"!][!//
[!NOCODE!]
    [!VAR "enLowPowerEnablePath" = "concat('Mcu',$Name,'ClockConfig/Mcu',$Name,'LowPowerEnable')"!]
    [!IF "node:exists($enLowPowerEnablePath)"!]
        [!VAR "ircoscLowPowerEn"!][!IF "node:value($enLowPowerEnablePath)"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
    [!ELSE!]
        [!VAR "ircoscLowPowerEn" = "0"!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($ircoscLowPowerEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetIrcoscStopModeEnable","Name"!][!//
[!NOCODE!]
    [!VAR "enStopEnablePath" = "concat('Mcu',$Name,'ClockConfig/Mcu',$Name,'StopEnable')"!]
    [!IF "node:exists($enLowPowerEnablePath)"!]
        [!VAR "ircoscStopEn"!][!IF "node:value($enStopEnablePath)"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
    [!ELSE!]
        [!VAR "ircoscStopEn" = "0"!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($ircoscStopEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetXoscFrequency","Name"!][!//
[!NOCODE!]
    [!VAR "capitalXosc" = "text:replace($Name,substring($Name,1),'SystemOSC')"!][!//
    [!VAR "freqPath" = "concat('Mcu',$capitalXosc,'ClockConfig/Mcu',$Name,'Frequency')"!]
    [!VAR "xoscFreq" = "num:i(node:value($freqPath))"!]
[!CODE!][!//
[!"num:i($xoscFreq)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetXoscEn","Name"!][!//
[!NOCODE!]
    [!VAR "capitalXosc" = "text:replace($Name,substring($Name,1),'SystemOSC')"!][!//
    [!VAR "enPath" = "concat('Mcu',$capitalXosc,'ClockConfig/Mcu',$Name,'Enable')"!]
    [!VAR "xoscEn"!][!IF "node:value($enPath)"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
[!CODE!][!//
[!"num:i($xoscEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetXoscHighGainOscillatorSelectEn","Name"!][!//
[!NOCODE!]
    [!VAR "capitalXoscHighGainOscillatorSelect" = "text:replace($Name,substring($Name,1),'SystemOSC')"!][!//
    [!VAR "enHighGainOscillatorSelectPath" = "concat('Mcu',$capitalXoscHighGainOscillatorSelect,'ClockConfig/Mcu',$Name,'HighGainOscillatorSelect')"!]
    [!VAR "xoscHighGainOscillatorSelect"!][!IF "node:value($enHighGainOscillatorSelectPath)"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
[!CODE!][!//
[!"num:i($xoscHighGainOscillatorSelect)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetXoscSelectExternalReferenceClockEn","Name"!][!//
[!NOCODE!]
    [!VAR "capitalXoscSelectExternalReferenceClock" = "text:replace($Name,substring($Name,1),'SystemOSC')"!][!//
    [!VAR "enXoscSelectExternalReferenceClockPath" = "concat('Mcu',$capitalXoscSelectExternalReferenceClock,'ClockConfig/Mcu',$Name,'ExternalReferenceSelect')"!]
    [!VAR "xoscSelectExternalReferenceClock"!][!IF "node:value($enXoscSelectExternalReferenceClockPath)"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
[!CODE!][!//
[!"num:i($xoscSelectExternalReferenceClock)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetClockConfiguredFrequency","Name"!][!//
[!NOCODE!]
[!VAR "clockConfiguredfrequency" = "0"!]

[!IF "$Name = 'FIRC_CLK'"!][!//
    [!VAR "clockConfiguredfrequency" = "node:value(McuFIRCClockConfig/McuFIRCFrequency)"!][!//
[!ENDIF!][!//
[!IF "$Name = 'SIRC_CLK'"!][!//
    [!VAR "clockConfiguredfrequency" = "node:value(McuSIRCClockConfig/McuSIRCFrequency)"!][!//
[!ENDIF!][!//
[!IF "$Name = 'BUS_RUN_CLK'"!][!//
    [!VAR "clockConfiguredfrequency" = "node:value(McuRunClockConfig/McuBusClockFrequency)"!][!//
[!ENDIF!][!//
[!IF "$Name = 'BUS_VLPR_CLK'"!][!//
    [!VAR "clockConfiguredfrequency" = "node:value(McuVlprClockConfig/McuBusClockFrequency)"!][!//
[!ENDIF!][!//
[!CODE!][!//
[!"num:i($clockConfiguredfrequency)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetXoscClockMonitorType","Name"!][!//
[!NOCODE!]
    [!VAR "xoscClockMonitorType"="'CLOCK_IP_HAS_MONITOR_DISABLE'"!]
    [!VAR "capitalXoscClockMonitor" = "text:replace($Name,substring($Name,1),'SystemOSC')"!][!//
    [!VAR "ClockMonitorEnablePath" = "concat('Mcu',$capitalXoscClockMonitor,'ClockConfig/Mcu',$Name,'ClockMonitorEnable')"!][!//
    [!VAR "ClockMonitorResetEnablePath" = "concat('Mcu',$capitalXoscClockMonitor,'ClockConfig/Mcu',$Name,'ClockMonitorResetEnable')"!][!//
    [!IF "node:value($ClockMonitorEnablePath)"!][!//
        [!IF "node:value($ClockMonitorResetEnablePath)"!][!//
            [!VAR "xoscClockMonitorType"="'CLOCK_IP_HAS_MONITOR_RESET'"!][!//
        [!ELSE!][!//
            [!VAR "xoscClockMonitorType"="'CLOCK_IP_HAS_MONITOR_INT'"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!CODE!][!//
[!"($xoscClockMonitorType)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetPllEnable","Name"!][!//
[!NOCODE!]
    [!VAR "capitalPLL" = "text:replace($Name,substring($Name,1),'SystemPll')"!][!//
    [!VAR "pllEn"!][!IF "node:value(concat('Mcu',$capitalPLL,'/McuSPLLEnable'))"!]1[!ELSE!]0[!ENDIF!][!ENDVAR!]
[!CODE!][!//
[!"num:i($pllEn)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetSpllClockMonitorType","Name"!][!//
[!NOCODE!]
    [!VAR "spllClockMonitorType"="'CLOCK_IP_HAS_MONITOR_DISABLE'"!]
    [!VAR "capitalSpllClockMonitorEnable" = "text:replace($Name,substring($Name,1),'SystemPll')"!][!//
    [!VAR "ClockMonitorEnablePath" = "concat('Mcu',$capitalSpllClockMonitorEnable,'/McuSPLLClockMonitorEnable')"!][!//
    [!VAR "ClockMonitorResetEnablePath" = "concat('Mcu',$capitalSpllClockMonitorEnable,'/McuSPLLClockMonitorResetEnable')"!][!//
    [!IF "node:value($ClockMonitorEnablePath)"!][!//
        [!IF "node:value($ClockMonitorResetEnablePath)"!][!//
            [!VAR "spllClockMonitorType"="'CLOCK_IP_HAS_MONITOR_RESET'"!][!//
        [!ELSE!][!//
            [!VAR "spllClockMonitorType"="'CLOCK_IP_HAS_MONITOR_INT'"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!CODE!][!//
[!"($spllClockMonitorType)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetPllClockSelection","Name"!][!//
[!NOCODE!]
    [!VAR "capitalPLL" = "text:replace($Name,substring($Name,1),'SystemPll')"!][!//
    [!VAR "pllclockselectionPath" = "concat('Mcu',$capitalPLL,'/McuSPLLSelectSourceClock')"!]
    [!IF "node:exists($pllclockselectionPath)"!]
        [!VAR "pllclockselection" = "node:value(concat('Mcu',$capitalPLL,'/McuSPLLSelectSourceClock'))"!]
    [!ELSE!]
        [!VAR "pllclockselection" = "'RESERVED_CLK'"!]
    [!ENDIF!]
[!CODE!][!//
[!"($pllclockselection)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetPllPrediv","Name"!][!//
[!NOCODE!]
    [!VAR "capitalPLL" = "text:replace($Name,substring($Name,1),'SystemPll')"!][!//
    [!VAR "pllPrediv" = "node:value(concat('Mcu',$capitalPLL,'/McuSPLLInputClkPreDivider'))"!]
[!CODE!][!//
[!"num:i($pllPrediv)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetPllMultiplier","Name"!][!//
[!NOCODE!]
    [!VAR "capitalPLL" = "text:replace($Name,substring($Name,1),'SystemPll')"!][!//
    [!VAR "pllMul" = "node:value(concat('Mcu',$capitalPLL,'/McuSPLLMultiplier'))"!]
[!CODE!][!//
[!"num:i($pllMul)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "GetClockExternal","Name"!][!//
[!NOCODE!]
    [!VAR "externalPath" = "concat('../../Mcu',$Name,'FrequencyHz')"!]
    [!IF "node:exists($externalPath)"!]
        [!VAR "valueclockexternal" = "node:value(concat('../../Mcu',$Name,'FrequencyHz'))"!]
    [!ENDIF!]
[!CODE!][!//
[!"num:i($valueclockexternal)"!][!//
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Clock_Ip_Clock_Config","Type"!][!//
[!NOCODE!]
[!CODE!]
/* *************************************************************************
 * Configuration structure for Clock Configuration 0
 * ************************************************************************* */
 /*! @brief User Configuration structure clock_Cfg_0 */
const Clock_Ip_ClockConfigType Mcu_aClockConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(McuModuleConfiguration/McuClockSettingConfig/*))"!]U] = {
[!ENDCODE!]
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
    [!VAR "ClockConfig" = "0"!]
    [!VAR "ircoscsCount"!][!CALL "Count_Ircoscs",Config="$ClockConfig"!][!ENDVAR!]
    [!VAR "xoscsCount"!][!CALL "Count_Xoscs",Config="$ClockConfig"!][!ENDVAR!]
    [!VAR "NumOfPllUnderMcuCtr"!][!CALL "Count_Plls",Config="$ClockConfig"!][!ENDVAR!]
    [!VAR "selectorsCount"!][!CALL "Count_Selectors",Config="$ClockConfig"!][!ENDVAR!]
    [!VAR "NumOfDivUnderMcuCtr"!][!CALL "Count_Dividers",Config="$ClockConfig"!][!ENDVAR!]
    [!VAR "extClksCount"!][!CALL "Count_ExtClks",Config="$ClockConfig"!][!ENDVAR!]
    [!VAR "NumOfGateUnderMcuCtr"!][!CALL "Count_Gates",Config="$ClockConfig"!][!ENDVAR!]
    [!VAR "NumOfUnderClkMonitor"!][!CALL "Count_Clk_Monitor",Config="$ClockConfig"!][!ENDVAR!]
    [!VAR "configureFrequenciesCount"!][!CALL "Count_configureFrequencies",Config="$ClockConfig"!][!ENDVAR!]  
    [!CODE!]
    {
        [!"num:i(num:i(McuClockSettingId))"!]U,                                 /* clkConfigId */
        [!"$ircoscsCount"!]U,                                 /* ircoscsCount */
        [!"$xoscsCount"!]U,                                 /* xoscsCount */
        [!"$NumOfPllUnderMcuCtr"!]U,                                 /* pllsCount */
        [!"$selectorsCount"!]U,                                /* selectorsCount */
        [!"$NumOfDivUnderMcuCtr"!]U,                                /* dividersCount */
        0U,                                 /* dividerTriggersCount */
        0U,                                /* fracDivsCount */
        [!"$extClksCount"!]U,                                /* extClksCount */
        [!"$NumOfGateUnderMcuCtr"!]U,                                 /* gatesCount */
        0U,                                 /* pcfsCount */
        [!"$NumOfUnderClkMonitor"!]U,                                /* cmusCount */
        [!"$configureFrequenciesCount"!]U,                                /* configureFrequenciesCount */

        /* IRCOSC initialization. */
        {
[!IF "$ircoscsCount > num:i(0)"!][!//
[!FOR "IrcoscsIterator" = "1" TO "num:i($HwpIrcoscCount)"!][!//
[!VAR "Ircoscs" = "ecu:list('MCU.IRCOSC.List')[num:i($IrcoscsIterator)]"!][!//
[!VAR "IrcoscsPath" = "concat('Mcu',$Ircoscs,'ClockConfig/Mcu',$Ircoscs,'UnderMcuControl')"!][!//
[!IF "node:value($IrcoscsPath)"!][!//
            #if CLOCK_IP_IRCOSCS_NO > [!"num:i($IrcoscsIterator - 1)"!]U
[!VAR "Ircosc" = "ecu:list('MCU.IRCOSC.List')[num:i($IrcoscsIterator)]"!][!//
            {
                [!"ecu:list('MCU.IRCOSC.Names')[num:i($IrcoscsIterator)]"!],    /* Clock name associated to Ircosc */
                [!CALL "GetIrcoscEn","Name"="$Ircosc"!]U,                       /* Enable ircosc */
                [!CALL "GetIrcoscRegulatorEn","Name"="$Ircosc"!]U,              /* Enable regulator */
                [!CALL "GetIrcoscRange","Name"="$Ircosc"!]U,                     /* Ircosc range  */
                [!CALL "GetIrcoscLowPowerModeEnable","Name"="$Ircosc"!]U,        /* Ircosc enable in VLP mode  */
                [!CALL "GetIrcoscStopModeEnable","Name"="$Ircosc"!]U,                     /* Ircosc enable in STOP mode  */
            },
            #endif
[!ENDIF!][!//
[!ENDFOR!][!//
[!FOR "IrcoscsIterator" = "$ircoscsCount" TO "num:i($HwpIrcoscCount - 1)"!][!//
            {
                RESERVED_CLK,           /* Clock name associated to Ircosc */
                0U,                     /* Enable ircosc */
                0U,                     /* Enable regulator */
                0U,                     /* Ircosc range  */
                0U,                     /* Ircosc enable in VLP mode */
                0U,                     /* Ircosc enable in STOP mode */
            },
[!ENDFOR!][!//
[!ELSE!][!//
    [!FOR "IrcoscsIterator" = "1" TO "num:i($HwpIrcoscCount)"!]
           #if CLOCK_IP_IRCOSCS_NO > [!"num:i($IrcoscsIterator - 1)"!]U
           {
                RESERVED_CLK,           /* Clock name associated to Ircosc */
                0U,                     /* Enable ircosc */
                0U,                     /* Enable regulator */
                0U,                     /* Ircosc range  */
                0U,                     /* Ircosc enable in VLP mode */
                0U,                     /* Ircosc enable in STOP mode */
           },
           #endif
    [!ENDFOR!]
[!ENDIF!][!//
        },

        /* XOSC initialization. */
        {
[!IF "$xoscsCount > num:i(0)"!][!//
[!FOR "XoscsIterator" = "1" TO "num:i($HwpXoscsCount)"!][!//
[!VAR "Xosc" = "ecu:list('MCU.XOSC.List')[num:i($XoscsIterator)]"!][!//
[!VAR "capitalXosc" = "text:replace($Xosc,substring($Xosc,1),'SystemOSC')"!][!//
[!VAR "XoscPath" = "concat('Mcu',$capitalXosc,'ClockConfig/Mcu',$Xosc,'UnderMcuControl')"!][!//
[!IF "node:value($XoscPath)"!][!//
            #if CLOCK_IP_XOSCS_NO > [!"num:i($XoscsIterator - 1)"!]U
[!VAR "Xosc" = "ecu:list('MCU.XOSC.List')[num:i($XoscsIterator)]"!][!//
            {
                [!"ecu:list('MCU.XOSC.Names')[num:i($XoscsIterator)]"!],                    /* Clock name associated to xosc */
                [!CALL "GetXoscFrequency","Name"="$Xosc"!]U,                    /* External oscillator frequency. */
                [!CALL "GetXoscEn","Name"="$Xosc"!]U,                           /* Enable xosc. */
                0U,                         /* Startup stabilization time. */
                [!CALL "GetXoscSelectExternalReferenceClockEn","Name"="$Xosc"!]U,                           /* XOSC bypass option */
                0U,                           /* Comparator enable */
                0U,                          /* Crystal overdrive protection */
                [!CALL "GetXoscHighGainOscillatorSelectEn","Name"="$Xosc"!]U,                    /* High gain value */
                [!CALL "GetXoscClockMonitorType","Name"="$Xosc"!],       /* Monitor type */
            },
            #endif
[!ENDIF!][!//
[!ENDFOR!][!//
[!FOR "XoscsIterator" = "$xoscsCount" TO "num:i($HwpXoscsCount - 1)"!][!//
            {
                RESERVED_CLK,           /* Clock name associated to xosc */
                0U,                     /* External oscillator frequency. */
                0U,                     /* Enable xosc. */
                0U,                     /* Startup stabilization time. */
                0U,                     /* XOSC bypass option */
                0U,                     /* Comparator enable */
                0U,                     /* Crystal overdrive protection */
                0U,                     /* High gain value */
                0U,                     /* Monitor type */
            },
[!ENDFOR!][!//
[!ELSE!][!//
[!FOR "XoscsIterator" = "1" TO "num:i($HwpXoscsCount)"!][!//
            #if CLOCK_IP_XOSCS_NO > [!"num:i($XoscsIterator - 1)"!]U
            {
                RESERVED_CLK,           /* Clock name associated to xosc */
                0U,                     /* External oscillator frequency. */
                0U,                     /* Enable xosc. */
                0U,                     /* Startup stabilization time. */
                0U,                     /* XOSC bypass option */
                0U,                     /* Comparator enable */
                0U,                     /* Crystal overdrive protection */
                0U,                     /* High gain value */
                0U,                     /* Monitor type */
            },
            #endif
[!ENDFOR!][!//
[!ENDIF!]
        },

        /* PLL initialization. */
        {
[!IF "$NumOfPllUnderMcuCtr > num:i(0)"!][!//
[!FOR "PllIterator" = "1" TO "num:i($HwpllsCount)"!][!//
[!IF "node:value('McuSystemPll/McuSystemPllUnderMcuControl')"!][!//
[!VAR "Pll" = "ecu:list('MCU.PLL.List')[num:i($PllIterator)]"!][!//
            #if CLOCK_IP_PLLS_NO > [!"num:i($PllIterator - 1)"!]U
            {
                [!"ecu:list('MCU.PLL.Names.List')[num:i($PllIterator)]"!],                  /*!<     name;                    */
                [!CALL "GetPllEnable","Name"="$Pll"!]U,                           /*!<     enable;                  */
                [!CALL "GetPllClockSelection","Name"="$Pll"!],                    /*!<     inputReference           */
                0U,                           /*!<     bypass;                  */
                [!CALL "GetPllPrediv","Name"="$Pll"!]U,                           /*!<     predivider;              */
                0U,                           /*!<     numeratorFracLoopDiv;    */
                [!CALL "GetPllMultiplier","Name"="$Pll"!]U,                          /*!<     mulFactorDiv;            */
                0U,                           /*!<     modulation;              */
                0U,                           /*!<     modulationType;          */
                0U,                           /*!<     modulationPeriod;        */
                0U,                           /*!<     incrementStep;           */
                0U,                           /*!<     sigmaDelta;              */
                0U,                           /*!<     ditherControl;           */
                0U,                           /*!<     ditherControlValue;      */
                [!CALL "GetSpllClockMonitorType","Name"="$Pll"!],        /*!<     Monitor type             */
                {                             /*!<     Dividers */
                        0U,
                        0U,
                        0U,
                },
            },
            #endif
[!ENDIF!][!//
[!ENDFOR!][!//
[!FOR "PllIterator" = "$NumOfPllUnderMcuCtr" TO "num:i($HwpllsCount - 1)"!][!//
            {
                RESERVED_CLK,           /* name */
                0U,                     /* enable */
                RESERVED_CLK,           /* inputReference */
                0U,                     /* Bypass */
                0U,                     /* predivider */
                0U,                     /* numeratorFracLoopDiv */
                0U,                     /* mulFactorDiv */
                0U,                     /* modulation */
                0U,                     /* Modulaton type: Spread spectrum modulation bypassed */
                0U,                     /* modulationPeriod */
                0U,                     /* incrementStep */
                0U,                     /* sigmaDelta */
                0U,                     /* ditherControl */
                0U,                     /* ditherControlValue */
                0U,                     /* Monitor type  */
                {                             /*!<     Dividers */
                        0U,
                        0U,
                        0U,
                },
            },
[!ENDFOR!][!//
[!ELSE!][!//
[!IF "$HwpllsCount > num:i(0)"!][!//
    [!VAR "PllsCount" = "num:i($HwpllsCount)"!][!//
[!ELSE!][!//
    [!VAR "PllsCount" = "num:i(1)"!][!//
[!ENDIF!][!//
[!FOR "PllIterator" = "1" TO "num:i($PllsCount)"!][!//
            #if CLOCK_IP_PLLS_NO > [!"num:i($PllIterator - 1)"!]U
            {
                RESERVED_CLK,           /* name */
                0U,                     /* enable */
                RESERVED_CLK,           /* inputReference */
                0U,                     /* Bypass */
                0U,                     /* predivider */
                0U,                     /* numeratorFracLoopDiv */
                0U,                     /* mulFactorDiv */
                0U,                     /* modulation */
                0U,                     /* Modulaton type: Spread spectrum modulation bypassed */
                0U,                     /* modulationPeriod */
                0U,                     /* incrementStep */
                0U,                     /* sigmaDelta */
                0U,                     /* ditherControl */
                0U,                     /* ditherControlValue */
                0U,                     /* Monitor type  */
                {                             /*!<     Dividers */
                        0U,
                        0U,
                        0U,
                },
            },
            #endif
[!ENDFOR!][!//
[!ENDIF!]
        },

        /* SELECTOR initialization. */
        {
[!ENDCODE!]
[!IF "$selectorsCount > num:i(0)"!][!//
[!VAR "CurrentSelector" = "0"!]
[!FOR "SelectorIndex" = "1" TO "num:i($HwSelectorCount)"!][!//
[!// Selector of CSG_SCS
        [!FOR "SelectorCSG_SCS" = "1" TO "num:i($NrOfCSG_SCS)"!]
            [!VAR "NameSelector" = "ecu:list('MCU.SystemClk.List')[number($SelectorCSG_SCS)]"!][!//
            [!VAR "capitalNameSelector" = "text:replace($NameSelector,substring($NameSelector,2),text:tolower(substring($NameSelector,2)))"!]
            [!VAR "SelectorPath" = "concat('Mcu',$capitalNameSelector,'ClockConfig/McuSystemClockSwitch')"!]
            [!IF "node:exists($SelectorPath)"!]
                [!VAR "ControlPath" = "'./McuSysClockUnderMcuControl'"!]
                [!IF "node:value($ControlPath)"!]
                    [!IF "ecu:list('MCU.SELECTOR.Names.List')[number($SelectorIndex)] = (concat('SCS_',$NameSelector,'_CLK'))"!]
        [!CODE!]
            #if CLOCK_IP_SELECTORS_NO > [!"num:i($CurrentSelector)"!]U
            {
                [!"concat('SCS_',$NameSelector,'_CLK')"!],                     /* Clock name associated to selector */
                [!"node:value($SelectorPath)"!],                       /* Name of the selected input source */
            },
            #endif
        [!ENDCODE!]
                    [!VAR "CurrentSelector" = "$CurrentSelector + 1"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
[!// Selector of SCG_CLKOUT
            [!VAR "SelectorSCG_CLKOUTPath" = "'./McuScgClkOutSelect'"!]
            [!IF "node:exists($SelectorSCG_CLKOUTPath)"!]
                [!VAR "ControlPath" = "'./McuSysClockUnderMcuControl'"!]
                [!IF "node:value($ControlPath)"!]
                    [!IF "ecu:list('MCU.SELECTOR.Names.List')[number($SelectorIndex)] = 'SCG_CLKOUT_CLK'"!]
        [!CODE!]
            #if CLOCK_IP_SELECTORS_NO > [!"num:i($CurrentSelector)"!]U
            {
                SCG_CLKOUT_CLK,                     /* Clock name associated to selector */
                [!"node:value($SelectorSCG_CLKOUTPath)"!],                       /* Name of the selected input source */
            },
            #endif
        [!ENDCODE!]
                    [!VAR "CurrentSelector" = "$CurrentSelector + 1"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
[!// Selector of SIM_CHIPCTL
        [!FOR "SelectorSIM_CHIPCTL" = "1" TO "num:i($NrOfSIM_CHIPCTL)"!]
            [!VAR "NameSelector" = "ecu:list('MCU.SIM.CHIPCTL.List')[number($SelectorSIM_CHIPCTL)]"!][!//
            [!VAR "SelectorPath" = "concat('McuSIMClockConfig/McuSimChipConfiguration/Mcu',$NameSelector,'Select')"!]
            [!IF "node:exists($SelectorPath)"!]
                [!VAR "ControlPath" = "'./McuSIMClockConfig/McuSIMUnderMcuControl'"!]
                [!IF "node:value($ControlPath)"!]
                    [!IF "ecu:list('MCU.SELECTOR.Names.List')[number($SelectorIndex)] = ecu:list('MCU.SIM.CHIPCTL.Names.List')[number($SelectorSIM_CHIPCTL)]"!]
        [!CODE!]
            #if CLOCK_IP_SELECTORS_NO > [!"num:i($CurrentSelector)"!]U
            {
                [!"ecu:list('MCU.SIM.CHIPCTL.Names.List')[number($SelectorSIM_CHIPCTL)]"!],                     /* Clock name associated to selector */
                [!"node:value($SelectorPath)"!],                       /* Name of the selected input source */
            },
            #endif
        [!ENDCODE!]
                    [!VAR "CurrentSelector" = "$CurrentSelector + 1"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
[!// Selector of SIM_LPOCLKS
        [!FOR "SelectorSIM_LPOCLKS" = "1" TO "num:i($NrOfSIM_LPOCLKS)"!]
            [!VAR "NameSelector" = "ecu:list('MCU.SIM.LPOCLKS.List')[number($SelectorSIM_LPOCLKS)]"!][!//
            [!VAR "SelectorPath" = "concat('McuSIMClockConfig/McuSimLpoConfiguration/Mcu',$NameSelector,'ClkSelect')"!]
            [!IF "node:exists($SelectorPath)"!]
                [!VAR "ControlPath" = "'./McuSIMClockConfig/McuSIMUnderMcuControl'"!]
                [!IF "node:value($ControlPath)"!]
                    [!IF "ecu:list('MCU.SELECTOR.Names.List')[number($SelectorIndex)] = ecu:list('MCU.SIM.LPOCLKS.Names.List')[number($SelectorSIM_LPOCLKS)]"!]
        [!CODE!]
            #if CLOCK_IP_SELECTORS_NO > [!"num:i($CurrentSelector)"!]U
            {
                [!"ecu:list('MCU.SIM.LPOCLKS.Names.List')[number($SelectorSIM_LPOCLKS)]"!],                     /* Clock name associated to selector */
                [!"node:value($SelectorPath)"!],                       /* Name of the selected input source */
            },
            #endif
        [!ENDCODE!]
                    [!VAR "CurrentSelector" = "$CurrentSelector + 1"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
[!// Selector of SIM_FTMOPT0
        [!FOR "SelectorSIM_FTMOPT0" = "1" TO "num:i($NrOfSIM_FTMOPT0)"!]
            [!VAR "NameSelector" = "ecu:list('MCU.SIM.FTMOPT0.List')[number($SelectorSIM_FTMOPT0)]"!][!//
            [!VAR "SelectorPath" = "concat('McuSIMClockConfig/McuSimFtmConfiguration/Mcu',$NameSelector,'ExternalClockPinSelect')"!]
            [!IF "node:exists($SelectorPath)"!]
                [!VAR "NameInPutSelector" = "node:value($SelectorPath)"!][!//
                [!IF "$NameInPutSelector = 'NO_CLOCK'"!]
                    [!VAR "capitalSIM_FTMOPT0" = "CLOCK_IS_OFF"!][!//
                [!ELSE!]
                    [!VAR "capitalSIM_FTMOPT0" = "text:replace($NameInPutSelector,substring($NameInPutSelector,7),'REF_CLK')"!][!//
                [!ENDIF!]
                [!VAR "ControlPath" = "'./McuSIMClockConfig/McuSIMUnderMcuControl'"!]
                [!IF "node:value($ControlPath)"!]
                    [!IF "ecu:list('MCU.SELECTOR.Names.List')[number($SelectorIndex)] = ecu:list('MCU.SIM.FTMOPT0.Names.List')[number($SelectorSIM_FTMOPT0)]"!]
        [!CODE!]
            #if CLOCK_IP_SELECTORS_NO > [!"num:i($CurrentSelector)"!]U
            {
                [!"ecu:list('MCU.SIM.FTMOPT0.Names.List')[number($SelectorSIM_FTMOPT0)]"!],                     /* Clock name associated to selector */
                [!"$capitalSIM_FTMOPT0"!],                       /* Name of the selected input source */
            },
            #endif
        [!ENDCODE!]
                    [!VAR "CurrentSelector" = "$CurrentSelector + 1"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDFOR!]
[!// Selector of PCC
        [!FOR "IndexPCC" = "1" TO "num:i($NrOfPCC)"!]
            [!VAR "NamePCC" = "ecu:list('MCU.PerSource.List')[number($IndexPCC)]"!][!//
            [!VAR "SelectorPath" = "concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',num:i($IndexPCC - 1),'/McuPerName')"!]
            [!VAR "SelectorClock" = "concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',num:i($IndexPCC - 1),'/McuPeripheralClockSelect')"!]
            
            [!FOR "IndexPCC_Plat" = "1" TO "num:i($NrOfPCC_Plat)"!]
                [!VAR "NamePCC_Plat" = "ecu:list('MCU.PerSourceWithPcsFromPlat.List')[number($IndexPCC_Plat)]"!][!//
                [!IF "$NamePCC_Plat = $NamePCC"!]
                    [!IF "node:value($SelectorClock) = 'CLOCK_IS_OFF'"!]
                        [!VAR "SelectorClockPlat" = "node:value($SelectorClock)"!]
                    [!ELSE!]
                        [!VAR "SelectorClockPlat" = "concat(node:value($SelectorClock),'DIV1_CLK')"!]
                    [!ENDIF!]
                    [!VAR "ControlPath" = "concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',num:i($IndexPCC - 1),'/McuPeripheralClockUnderMcuControl')"!]
                    [!IF "node:value($ControlPath)"!]
                        [!IF "ecu:list('MCU.SELECTOR.Names.List')[number($SelectorIndex)] = concat(node:value($SelectorPath),'_CLK')"!]
        [!CODE!]
            #if CLOCK_IP_SELECTORS_NO > [!"num:i($CurrentSelector)"!]U
            {
                [!"concat(node:value($SelectorPath),'_CLK')"!],                     /* Clock name associated to selector */
                [!"($SelectorClockPlat)"!],                       /* Name of the selected input source */
            },
            #endif
        [!ENDCODE!]
                        [!VAR "CurrentSelector" = "$CurrentSelector + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
            
            [!FOR "IndexPCC_Slow" = "1" TO "num:i($NrOfPCC_Slow)"!]
                [!VAR "NamePCC_Slow" = "ecu:list('MCU.PerSourceWithPcsFromSlow.List')[number($IndexPCC_Slow)]"!][!//
                [!IF "$NamePCC_Slow = $NamePCC"!]
                    [!IF "node:value($SelectorClock) = 'CLOCK_IS_OFF'"!]
                        [!VAR "SelectorClockSlow" = "node:value($SelectorClock)"!]
                    [!ELSE!]
                        [!VAR "SelectorClockSlow" = "concat(node:value($SelectorClock),'DIV2_CLK')"!]
                    [!ENDIF!]
                    [!VAR "ControlPath" = "concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',num:i($IndexPCC - 1),'/McuPeripheralClockUnderMcuControl')"!]
                    [!IF "node:value($ControlPath)"!]
                         [!IF "ecu:list('MCU.SELECTOR.Names.List')[number($SelectorIndex)] = concat(node:value($SelectorPath),'_CLK')"!]
        [!CODE!]
            #if CLOCK_IP_SELECTORS_NO > [!"num:i($CurrentSelector)"!]U
            {
                [!"concat(node:value($SelectorPath),'_CLK')"!],                     /* Clock name associated to selector */
                [!"($SelectorClockSlow)"!],                       /* Name of the selected input source */
            },
            #endif
        [!ENDCODE!]
                        [!VAR "CurrentSelector" = "$CurrentSelector + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
        [!ENDFOR!]
[!ENDFOR!] [!// "SelectorIndex"

[!FOR "SelectorIterator" = "$selectorsCount" TO "num:i($HwSelectorCount - 1)"!][!//
        [!CODE!]
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
        [!ENDCODE!]
[!ENDFOR!][!//
[!ELSE!][!//
[!FOR "SelectorIterator" = "1" TO "num:i($HwSelectorCount)"!][!//
        [!CODE!]
            #if CLOCK_IP_SELECTORS_NO > [!"num:i($SelectorIterator - 1)"!]U
            {
                RESERVED_CLK,           /* Clock name associated to selector */
                RESERVED_CLK,           /* Name of the selected input source */
            },
            #endif
        [!ENDCODE!]
[!ENDFOR!][!//
[!ENDIF!]
        [!CODE!]
        },

        /* DIVIDER initialization. */
        {
        [!ENDCODE!]
[!IF "$NumOfDivUnderMcuCtr > num:i(0)"!][!//
    [!VAR "CurrentDivider" = "0"!]
    [!VAR "DivValue" = "0"!]
[!FOR "DividerIndex" = "1" TO "num:i($HwDividerCount)"!][!//
[!// Divider of CSG_DIV
        [!FOR "DividerCSG" = "1" TO "num:i($NrOfCSG_SCS)"!]
            [!VAR "NameSystemClk" = "ecu:list('MCU.SystemClk.List')[number($DividerCSG)]"!][!//
            [!VAR "capitalNameSystemClk" = "text:replace($NameSystemClk,substring($NameSystemClk,2),text:tolower(substring($NameSystemClk,2)))"!]
            [!FOR "DividerCSG_DIV" = "1" TO "num:i($NrOfCSG_DIV)"!]
                [!VAR "NameSystemClkDiv" = "ecu:list('MCU.SystemClk.DIV.List')[number($DividerCSG_DIV)]"!][!//
                [!VAR "capitalNameSystemClkDiv" = "text:replace($NameSystemClkDiv,substring($NameSystemClkDiv,2),text:tolower(substring($NameSystemClkDiv,2)))"!]
                [!VAR "DividerPath" = "concat('Mcu',$capitalNameSystemClk,'ClockConfig/Mcu',$capitalNameSystemClkDiv,'ClockDivider')"!]
                [!VAR "DivName" = "concat($NameSystemClkDiv,'_',$NameSystemClk,'_CLK')"!]
                [!IF "node:exists($DividerPath)"!]
                    [!VAR "DivValue" = "num:i(node:value($DividerPath))"!]
                    [!VAR "ControlPath" = "'./McuSysClockUnderMcuControl'"!]
                    [!IF "node:value($ControlPath)"!]
                        [!IF "ecu:list('MCU.DIVIDER.Names.List')[number($DividerIndex)] = ($DivName)"!]
        [!CODE!]
            #if CLOCK_IP_DIVIDERS_NO > [!"num:i($CurrentDivider)"!]U
            {
                [!"($DivName)"!],
                [!"num:i($DivValue)"!]U,
                {
                    0U,
                }
            },
            #endif
        [!ENDCODE!]
                        [!VAR "CurrentDivider" = "$CurrentDivider + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
        [!ENDFOR!]
[!// Divider of IRC
        [!FOR "IndexIRC" = "1" TO "num:i($HwpIrcoscCount)"!]
            [!VAR "NameIRC" = "ecu:list('MCU.IRCOSC.List')[number($IndexIRC)]"!][!//
            [!FOR "IndexDividerIRC" = "1" TO "num:i($NrOfIRC_DIV)"!]
                [!VAR "DividerIRC" = "ecu:list('MCU.IRCOSC.DIV.List')[number($IndexDividerIRC)]"!][!//
                [!VAR "capitalDividerIRC" = "text:replace($DividerIRC,substring($DividerIRC,2),text:toupper(substring($DividerIRC,2)))"!]
                [!VAR "DividerIRCPath" = "concat('Mcu',$NameIRC,'ClockConfig/Mcu',$NameIRC,$DividerIRC)"!]
                [!VAR "DivName" = "concat($NameIRC,$capitalDividerIRC,'_CLK')"!]
                [!IF "node:exists($DividerIRCPath)"!]
                    [!VAR "DivValue" = "num:i(node:value($DividerIRCPath))"!]
                    [!VAR "ControlPath" = "concat('./Mcu',$NameIRC,'ClockConfig/Mcu',$NameIRC,'UnderMcuControl')"!]
                    [!IF "node:value($ControlPath)"!]
                        [!IF "ecu:list('MCU.DIVIDER.Names.List')[number($DividerIndex)] = ($DivName)"!]
        [!CODE!]
            #if CLOCK_IP_DIVIDERS_NO > [!"num:i($CurrentDivider)"!]U
            {
                [!"($DivName)"!],
                [!"num:i($DivValue)"!]U,
                {
                    0U,
                }
            },
            #endif
        [!ENDCODE!]
                        [!VAR "CurrentDivider" = "$CurrentDivider + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
        [!ENDFOR!]
        
[!// Divider of XOSC
        [!FOR "IndexXOSC" = "1" TO "num:i($HwpXoscsCount)"!]
            [!VAR "NameXOSC" = "ecu:list('MCU.XOSC.List')[number($IndexXOSC)]"!][!//
            [!VAR "capitalNameXOSC" = "text:replace($NameXOSC,substring($NameXOSC,1),'SystemOSC')"!][!//
            [!FOR "IndexDividerXOSC" = "1" TO "num:i($NrOfXOSC_DIV)"!]
                [!VAR "DividerXOSC" = "ecu:list('MCU.XOSC.DIV.List')[number($IndexDividerXOSC)]"!][!//
                [!VAR "capitalDividerXOSC" = "text:replace($DividerXOSC,substring($DividerXOSC,2),text:toupper(substring($DividerXOSC,2)))"!]
                [!VAR "DividerXOSCPath" = "concat('Mcu',$capitalNameXOSC,'ClockConfig/Mcu',$NameXOSC,$DividerXOSC)"!]
                [!VAR "DivName" = "concat($NameXOSC,$capitalDividerXOSC,'_CLK')"!]
                [!IF "node:exists($DividerXOSCPath)"!]
                    [!VAR "DivValue" = "num:i(node:value($DividerXOSCPath))"!]
                    [!VAR "ControlPath" = "concat('./Mcu',$capitalNameXOSC,'ClockConfig/Mcu',$NameXOSC,'UnderMcuControl')"!]
                    [!IF "node:value($ControlPath)"!]
                        [!IF "ecu:list('MCU.DIVIDER.Names.List')[number($DividerIndex)] = ($DivName)"!]
        [!CODE!]
            #if CLOCK_IP_DIVIDERS_NO > [!"num:i($CurrentDivider)"!]U
            {
                [!"($DivName)"!],
                [!"num:i($DivValue)"!]U,
                {
                    0U,
                }
            },
            #endif
        [!ENDCODE!]
                        [!VAR "CurrentDivider" = "$CurrentDivider + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
        [!ENDFOR!]

[!// Divider of PLL
        [!FOR "IndexPLL" = "1" TO "num:i($HwpllsCount)"!]
            [!VAR "NamePLL" = "ecu:list('MCU.PLL.List')[number($IndexPLL)]"!][!//
            [!VAR "capitalNamePLL" = "text:replace($NamePLL,substring($NamePLL,1),'SystemPll')"!][!//
            [!FOR "IndexDividerPLL" = "1" TO "num:i($NrOfPLL_DIV)"!]
                [!VAR "DividerPLL" = "ecu:list('MCU.PLL.DIV.List')[number($IndexDividerPLL)]"!][!//
                [!VAR "capitalDividerPLL" = "text:replace($DividerPLL,substring($DividerPLL,2),text:toupper(substring($DividerPLL,2)))"!]
                [!VAR "DividerPLLPath" = "concat('Mcu',$capitalNamePLL,'/Mcu',$NamePLL,$DividerPLL)"!]
                [!VAR "DivName" = "concat($NamePLL,$capitalDividerPLL,'_CLK')"!]
                [!IF "node:exists($DividerPLLPath)"!]
                    [!VAR "DivValue" = "num:i(node:value($DividerPLLPath))"!]
                    [!VAR "ControlPath" = "concat('./Mcu',$capitalNamePLL,'/Mcu',$capitalNamePLL,'UnderMcuControl')"!]
                    [!IF "node:value($ControlPath)"!]
                        [!IF "ecu:list('MCU.DIVIDER.Names.List')[number($DividerIndex)] = ($DivName)"!]
        [!CODE!]
            #if CLOCK_IP_DIVIDERS_NO > [!"num:i($CurrentDivider)"!]U
            {
                [!"($DivName)"!],
                [!"num:i($DivValue)"!]U,
                {
                    0U,
                }
            },
            #endif
        [!ENDCODE!]
                        [!VAR "CurrentDivider" = "$CurrentDivider + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]
        [!ENDFOR!]

[!// Divider of SIM
            [!FOR "IndexDividerSIM" = "1" TO "num:i($NrOfSIM_DIV)"!] 
                [!VAR "DividerSIM" = "ecu:list('MCU.SIM.DIV.List')[number($IndexDividerSIM)]"!][!//
                [!VAR "DividerSIMPath" = "concat('McuSIMClockConfig/McuSimChipConfiguration/Mcu',$DividerSIM,'Divider')"!]
                [!VAR "FractionSIMPath" = "concat('McuSIMClockConfig/McuSimChipConfiguration/Mcu',$DividerSIM,'Fraction')"!]
                [!IF "node:exists($FractionSIMPath)"!]
                    [!VAR "FracValue" = "num:i(node:value($FractionSIMPath))"!]
                [!ELSE!]
                    [!VAR "FracValue" = "num:i(0)"!]
                [!ENDIF!]
                [!VAR "DivName" = "ecu:list('MCU.SIM.CHIPCTL.Names.List')[number($IndexDividerSIM)]"!][!//
                [!IF "node:exists($DividerSIMPath)"!]
                    [!VAR "DivValue" = "num:i(node:value($DividerSIMPath))"!]
                    [!VAR "ControlPath" = "'McuSIMClockConfig/McuSIMUnderMcuControl'"!]
                    [!IF "node:value($ControlPath)"!]
                        [!IF "ecu:list('MCU.DIVIDER.Names.List')[number($DividerIndex)] = ($DivName)"!]
        [!CODE!]
            #if CLOCK_IP_DIVIDERS_NO > [!"num:i($CurrentDivider)"!]U
            {
                [!"($DivName)"!],
                [!"num:i($DivValue)"!]U,
                {
                    [!"num:i($FracValue)"!]U,
                }
            },
            #endif
        [!ENDCODE!]
                        [!VAR "CurrentDivider" = "$CurrentDivider + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDFOR!]

[!// Divider of Peripheral Clock
            [!FOR "IndexDividerPer" = "1" TO "num:i($NrOfPCC)"!] 
                [!VAR "DividerPer" = "ecu:list('MCU.PerSource.List')[number($IndexDividerPer)]"!][!//
                [!FOR "IndexDividerPerWithPcd" = "1" TO "num:i($NrOfPCC_WithPcd)"!]
                    [!VAR "NamePCC_WithPcd" = "ecu:list('MCU.PerSourceWithPcd.List')[number($IndexDividerPerWithPcd)]"!][!//
                    [!IF "$DividerPer = $NamePCC_WithPcd"!]
                        [!VAR "ControlPath" = "concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',num:i($IndexDividerPer - 1),'/McuPeripheralClockUnderMcuControl')"!]
                        [!IF "node:value($ControlPath)"!]
                            [!VAR "DividerPerPath" = "concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',num:i($IndexDividerPer - 1),'/McuPeripheralClockDivider')"!]
                            [!VAR "FractionPerPath" = "concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',num:i($IndexDividerPer - 1),'/McuPeripheralFractionalDivider')"!]
                            [!VAR "DivName" = "concat($DividerPer,'_CLK')"!][!//
                            [!VAR "DivValue" = "num:i(node:value($DividerPerPath))"!]
                            [!VAR "FracValue" = "num:i(node:value($FractionPerPath))"!]
                            [!IF "ecu:list('MCU.DIVIDER.Names.List')[number($DividerIndex)] = ($DivName)"!]
        [!CODE!]
            #if CLOCK_IP_DIVIDERS_NO > [!"num:i($CurrentDivider)"!]U
            {
                [!"($DivName)"!],
                [!"num:i($DivValue)"!]U,
                {
                    [!"num:i($FracValue)"!]U,
                }
            },
            #endif
        [!ENDCODE!]
                            [!VAR "CurrentDivider" = "$CurrentDivider + 1"!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDFOR!]
            [!ENDFOR!]
[!ENDFOR!] [!// "DividerIndex"
[!FOR "PllDivIterator" = "$NumOfDivUnderMcuCtr" TO "num:i($HwDividerCount - 1)"!][!//
        [!CODE!]
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
        [!ENDCODE!]
[!ENDFOR!][!//
[!ELSE!][!//
[!FOR "PllDivIterator" = "1" TO "num:i($HwDividerCount)"!][!//
        [!CODE!]
            #if CLOCK_IP_DIVIDERS_NO > [!"num:i($PllDivIterator - 1)"!]U
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                },
            },
            #endif
        [!ENDCODE!]
[!ENDFOR!][!//
[!ENDIF!]
        [!CODE!]
        },

        /* DIVIDER TRIGGER Initialization. */
        {
            {
                RESERVED_CLK,               /* divider name */
                IMMEDIATE_DIVIDER_UPDATE,   /* trigger value */
                RESERVED_CLK,               /* input source name */
            },
        },

        /* FRACTIONAL DIVIDER initialization. */
        {
            {
                RESERVED_CLK,
                0U,
                {
                    0U,
                    0U,
                },
            },
        },

        /* EXTERNAL CLOCKS initialization. */
        {
[!FOR "ClkExternal" = "1" TO "num:i($NrOfClkExternal)"!][!//
[!VAR "ClkExternalname" = "ecu:list('MCU.ExtClock.List')[num:i($ClkExternal)]"!][!//
[!CODE!][!//
            #if CLOCK_IP_EXT_CLKS_NO  > [!"num:i($ClkExternal - 1)"!]U
            {
                [!"($ClkExternalname)"!],
                [!CALL "GetClockExternal","Name"="$ClkExternalname"!]U,
            },
            #endif
[!ENDCODE!]
[!ENDFOR!][!//
        },

        /* CLOCK GATE initialization. */
        {
[!IF "$NumOfGateUnderMcuCtr > num:i(0)"!][!//
[!VAR "CurrentGate" = "0"!][!//
[!VAR "McuControlSimGatePath" = "'./McuSIMClockConfig/McuSIMUnderMcuControl'"!]
[!FOR "GateIterator" = "1" TO "num:i($HwGatesCount)"!][!//
[!VAR "Name" = "ecu:list('MCU.GATE.Names.List')[number($GateIterator)]"!][!//
[!FOR "PCCCount" = "1" TO "num:i($NrOfPCC)"!][!//
[!IF "node:value(concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',$PCCCount - 1,'/McuPerName')) = substring-before($Name,'_')"!][!//
[!VAR "McuControlGatePath" = "concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',$PCCCount - 1,'/McuPeripheralClockUnderMcuControl')"!][!//
[!VAR "McuControlGateEnablePath" = "concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',$PCCCount - 1,'/McuPeripheralClockEnable')"!][!//
[!IF "node:exists(concat('./McuPeripheralClockConfig/McuPeripheralClockConfig_',$PCCCount - 1,'/McuPerName'))"!][!//
[!IF "node:value($McuControlGatePath)"!][!//
[!CODE!][!//
            #if CLOCK_IP_GATES_NO > [!"num:i($CurrentGate)"!]U
            {
                [!"ecu:list('MCU.GATE.Names.List')[num:i($GateIterator)]"!],                  /*!<     name;                    */
                [!IF "node:value($McuControlGateEnablePath)"!]1[!ELSE!]0[!ENDIF!]U,                           /*!<     enable;                  */
            },
            #endif
[!ENDCODE!][!//
[!VAR "CurrentGate" = "$CurrentGate + 1"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!IF "node:value($McuControlSimGatePath)"!][!//
[!IF "node:exists(concat('./McuSIMClockConfig/Mcu',substring-before($Name,'0_'),'ClockGatingEnable'))"!][!//
[!VAR "McuControlSimGateEnablePath" = "concat('./McuSIMClockConfig/Mcu',substring-before($Name,'0_'),'ClockGatingEnable')"!][!//
[!CODE!][!//
            #if CLOCK_IP_GATES_NO > [!"num:i($CurrentGate)"!]U
            {
                [!"ecu:list('MCU.GATE.Names.List')[num:i($GateIterator)]"!],                  /*!<     name;                    */
                [!IF "node:value($McuControlSimGateEnablePath)"!]1[!ELSE!]0[!ENDIF!]U,                           /*!<     enable;                  */
            },
            #endif
[!ENDCODE!][!//
[!VAR "CurrentGate" = "$CurrentGate + 1"!][!//
[!ENDIF!][!//
[!IF "node:exists(concat('./McuSIMClockConfig/McuSimChipConfiguration/Mcu',substring-before($Name,'0_'),'Enable'))"!][!//
[!VAR "McuControlSimGateEnablePath" = "concat('./McuSIMClockConfig/McuSimChipConfiguration/Mcu',substring-before($Name,'0_'),'Enable')"!][!//
[!CODE!][!//
            #if CLOCK_IP_GATES_NO > [!"num:i($CurrentGate)"!]U
            {
                [!"ecu:list('MCU.GATE.Names.List')[num:i($GateIterator)]"!],                  /*!<     name;                    */
                [!IF "node:value($McuControlSimGateEnablePath)"!]1[!ELSE!]0[!ENDIF!]U,                           /*!<     enable;                  */
            },
            #endif
[!ENDCODE!][!//
[!VAR "CurrentGate" = "$CurrentGate + 1"!][!//
[!ENDIF!][!//
[!IF "node:exists(concat('./McuSIMClockConfig/McuSimLpoConfiguration/Mcu',substring-before($Name,'_CLK'),'ClockEnable'))"!][!//
[!VAR "McuControlSimGateEnablePath" = "concat('./McuSIMClockConfig/McuSimLpoConfiguration/Mcu',substring-before($Name,'_CLK'),'ClockEnable')"!][!//
[!CODE!][!//
            #if CLOCK_IP_GATES_NO > [!"num:i($CurrentGate)"!]U
            {
                [!"ecu:list('MCU.GATE.Names.List')[num:i($GateIterator)]"!],                  /*!<     name;                    */
                [!IF "node:value($McuControlSimGateEnablePath)"!]1[!ELSE!]0[!ENDIF!]U,                           /*!<     enable;                  */
            },
            #endif
[!ENDCODE!][!//
[!VAR "CurrentGate" = "$CurrentGate + 1"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!FOR "GateIterator" = "$NumOfGateUnderMcuCtr" TO "num:i($HwGatesCount - 1)"!][!//
            {
                RESERVED_CLK,           /* name */
                0U,                     /* enable */
            },
[!ENDFOR!][!//
[!ELSE!][!//
[!FOR "GateIterator" = "1" TO "num:i($HwGatesCount)"!][!//
            #if CLOCK_IP_GATES_NO > [!"num:i($GateIterator - 1)"!]U
            {
                RESERVED_CLK,
                0U,
            },
            #endif
[!ENDFOR!][!//
[!ENDIF!][!//
        },

        /* PCFS initialization. */
        {
            {
                RESERVED_CLK,
                0U,
                0U,
                RESERVED_CLK,
                0U,
            },
        },

        /* Clock monitor */ 
        {     
[!IF "$NumOfUnderClkMonitor > num:i(0)"!][!//
[!IF "node:exists("McuClkMonitor")"!][!//
[!VAR "ClkMonitorIterator" = "0"!][!//
[!VAR "ClkMonitorName" = "0"!][!//
[!LOOP "./McuClkMonitor/*"!][!//
[!VAR "ClkMonitorName" = "$ClkMonitorName + 1"!][!//
[!VAR "cmuName" = "ecu:list('MCU.CMU_FC.List')[num:i($ClkMonitorName)]"!][!//
[!IF "node:value(./McuClockMonitorUnderMcuControl)"!][!//
[!VAR "ClkMonitorIterator" = "$ClkMonitorIterator + 1"!][!//
            #if CLOCK_IP_CMUS_NO > [!"num:i($ClkMonitorIterator - 1)"!]U
            {
                [!"($cmuName)"!],            /* Clock name associated to clock monitor. */
                [!CALL "GetCmuEnable"!]U,                   /*Enable/disable clock monitor [!"($cmuName)"!] */
                (                                           /* IER for [!"($cmuName)"!] */
                CMU_IER_FLLIE([!IF "./McuSyncFLLInterruptEn = 'true'"!]1U[!ELSE!]0U[!ENDIF!]) |
                CMU_IER_FHHIE([!IF "./McuSyncFHHInterruptEn = 'true'"!]1U[!ELSE!]0U[!ENDIF!]) |
                CMU_IER_FLLAIE([!IF "./McuAsyncFLLInterruptEn = 'true'"!]1U[!ELSE!]0U[!ENDIF!]) |
                CMU_IER_FHHAIE([!IF "./McuAsyncFHHInterruptEn = 'true'"!]1U[!ELSE!]0U[!ENDIF!])
                ),
                48000000U,
            },
            #endif
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!FOR "ClkMonitorIterator" = "$NumOfUnderClkMonitor" TO "num:i($NrOfClkMonitor - 1)"!][!//
            #if CLOCK_IP_CMUS_NO > [!"num:i($ClkMonitorIterator)"!]U
            {
                RESERVED_CLK,
                0U,
                0U,
                0U,
            },
            #endif
[!ENDFOR!][!//
[!ELSE!][!//
           {
               RESERVED_CLK,
               0U,
               0U,
               0U,
           },
[!ENDIF!][!//
        },

        /* Specific peripheral initialization. */
        {
            0U,
            {
                {
                    RESERVED_VALUE,
                    0U,
                },
            },
        },
    
    
        /* Configured frequency values. */
        {
[!IF "$configureFrequenciesCount > num:i(0)"!][!//
[!FOR "ClkConfiguredFrequency" = "1" TO "num:i($configureFrequenciesCount)"!][!//
[!VAR "ClkConfiguredFrequencyname" = "ecu:list('MCU.ConfiguredFrequency.List')[num:i($ClkConfiguredFrequency)]"!][!//
[!CODE!][!//
            #if CLOCK_IP_CONFIGURED_FREQUENCIES_NO > [!"num:i($ClkConfiguredFrequency - 1)"!]U
            {
                [!"($ClkConfiguredFrequencyname)"!],
                [!CALL "GetClockConfiguredFrequency","Name"="$ClkConfiguredFrequencyname"!]U,
            },
            #endif
[!ENDCODE!]
[!ENDFOR!][!//
[!ELSE!][!//
            {
                RESERVED_CLK,
                0U,
            },
[!ENDIF!][!//
        },

    },
[!ENDCODE!]
[!ENDLOOP!][!// "McuModuleConfiguration/McuClockSettingConfig/*"
[!CODE!]
};
[!ENDCODE!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!ENDNOCODE!]
