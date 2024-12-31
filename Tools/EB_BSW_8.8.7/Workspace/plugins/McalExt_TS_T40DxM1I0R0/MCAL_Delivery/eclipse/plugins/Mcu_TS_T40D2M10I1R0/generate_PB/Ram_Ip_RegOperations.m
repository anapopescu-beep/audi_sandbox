[!NOCODE!]
/**
    @file    Ram_Ip_RegOperations.m
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
[!MACRO "Ram_Ip_LinkerSymbols","Type"!][!//
[!NOCODE!][!//
    [!VAR "SymbolTable" = "''"!]
    [!LOOP "McuModuleConfiguration/McuRamSectorSettingConf/*"!]
        [!IF "McuRamSectionSizeLinkerSym != ''"!]
            [!VAR "Externs_SL" = "concat('extern uint32 ',McuRamSectionSizeLinkerSym,'[1U];')"!]
            [!IF "not(text:contains(text:split($SymbolTable), McuRamSectionSizeLinkerSym))"!]
[!CODE!][!//
[!"$Externs_SL"!]
[!ENDCODE!][!//
            [!VAR "SymbolTable" = "concat($SymbolTable, ' ', McuRamSectionSizeLinkerSym)"!]
            [!ENDIF!]
        [!ENDIF!][!//McuRamSectionSizeLinkerSym != ''

        [!IF "McuRamSectionBaseAddrLinkerSym != ''"!]
            [!VAR "Externs_BAL" = "concat('extern uint8 ',McuRamSectionBaseAddrLinkerSym,'[1U];')"!]
            [!IF "not(text:contains(text:split($SymbolTable), McuRamSectionBaseAddrLinkerSym))"!]
[!CODE!][!//
[!"$Externs_BAL"!]
[!ENDCODE!][!//
            [!VAR "SymbolTable" = "concat($SymbolTable, ' ', McuRamSectionSizeLinkerSym)"!]
            [!ENDIF!]
        [!ENDIF!][!//McuRamSectionBaseAddrLinkerSym != ''
    [!ENDLOOP!][!//McuRamSectorSettingConf/*
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Ram_Ip_Ram_Config","Type"!][!//
[!NOCODE!]
    [!IF "num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))>0"!]
        [!VAR "RamSector"= "num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))-1"!]
[!CODE!]
#ifndef MCU_MAX_NORAMCONFIGS
[!ENDCODE!]


[!CODE!]
/**
* @brief        Definition of RAM sections within the configuration structure.
* @details      Blocks of memory are initialized with a default data.
*               Configuration set by calling Mcu_InitRamSection() API.
*
*/
const Ram_Ip_RamConfigType Mcu_aRamConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))"!]] =
{
[!ENDCODE!]
    [!LOOP "McuModuleConfiguration/McuRamSectorSettingConf/*"!]
        [!VAR "PCindex" = "@index"!]
[!CODE!]
    {
        /* The ID for Ram Sector configuration. */
        (Ram_Ip_RamSectionType)[!"num:i(McuRamSectorId)"!]U,

        /* RAM section base address: Start of Mcu_aRamConfig[[!"@index"!]]. */

        [!IF "McuRamSectionBaseAddrLinkerSym = ''"!](uint8 (*)[1U])[!"num:inttohex(McuRamSectionBaseAddress,8)"!]U[!ELSE!](uint8 (*)[1U])[!"McuRamSectionBaseAddrLinkerSym"!][!ENDIF!],

        /* RAM section size: Section base address (must be aligned to 4 bytes). */

        [!IF "McuRamSectionSizeLinkerSym = ''"!](Ram_Ip_RamSizeType *)[!"num:inttohex(McuRamSectionSize,8)"!]U,[!ELSE!][!"McuRamSectionSizeLinkerSym"!],[!ENDIF!]

        /* RAM default value. */
[!ENDCODE!]
        [!VAR "FirstByte" = "1"!]
        [!CODE!][!WS "8"!](uint64) ( [!ENDCODE!]
        [!FOR "i" = "0" TO "node:fallback(McuRamSectionWriteSize, 8) - 1"!][!//
            [!CODE!][!IF "num:i($FirstByte)=0"!] | [!ENDIF!][!VAR "FirstByte"="0"!]((uint64)[!"num:inttohex(McuRamDefaultValue, 2)"!]U << [!"num:i($i * 8)"!]U)[!ENDCODE!]
        [!ENDFOR!]
        [!CODE!] ),[!ENDCODE!]
[!CODE!]

        /* RAM section write size (maximum allowed: 8). */
        (Ram_Ip_RamWriteSizeType)[!"num:i(McuRamSectionWriteSize)"!]U

    }[!IF "$PCindex < $RamSector"!],[!ENDIF!] /* End of Mcu_aRamConfig[!"$Type"!][[!"@index"!]]. */
[!ENDCODE!]
    [!ENDLOOP!][!//McuRamSectorSettingConf/*
[!CODE!]
};
#endif /* ifndef MCU_MAX_NORAMCONFIGS */
[!ENDCODE!]
    [!ENDIF!][!//num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))>0
[!ENDNOCODE!]
[!ENDMACRO!][!//




[!ENDNOCODE!]