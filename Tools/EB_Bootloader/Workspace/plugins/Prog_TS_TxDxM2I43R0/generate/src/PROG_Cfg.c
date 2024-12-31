/*********************************************************************************/
/*                                                                               */
/*                                  BOOT Layers                                  */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                                 PROG configuration                            */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file PROG_Cfg.c                      */
/*%%  |                             |  %%  \brief PROG layer source plugin file  */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.43.0 BL3              */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*********************************************************************************/
/* Copyright 2010 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*********************************************************************************/
#include "EB_Prj.h"
[!AUTOSPACING!]

[!NOCODE!]
[!IF "(node:exists(as:modconf('ReProgMemM')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:30:IF1 osc_PROG main ', $project))"!][!ENDSELECT!]
[!VAR "MEMORY_MAX"="num:dectoint(count(as:modconf('ReProgMemM')/MemoryConfig/Memory/*))"!]
[!ELSEIF "node:exists(as:modconf('Flash')) or (node:exists(as:modconf('ProgFord')) and as:modconf('ProgFord')/General/PROG_FORD_VARIANT='PBL') or (node:exists(as:modconf('ProgJLR')) and as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL') or (node:exists(as:modconf('ProgVCC')) and as:modconf('ProgVCC')/General/PROG_VCC_VARIANT='PBL')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:32:ELSEIF2 osc_PROG main ', $project))"!][!ENDSELECT!]
[!VAR "MEMORY_MAX"="num:dectoint(count(Memory/*))"!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:34:DUMMYELSE3 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!VAR "SEGMENT_MAX"="num:dectoint(count(Segments/*))"!]
[!VAR "SEGMENT_IDX"="1"!]
[!VAR "SEGMENT_IDX_2"="1"!]
[!VAR "BLOCK_MAX"="num:dectoint(count(Blocks/*))"!]
[!VAR "BLOCK_IDX"="1"!]

[!VAR "SEGMENT_FOR_BOOTLOADER_PARTITION_IS_DEFINED" = "0"!]
[!/* Collect the information if a Bootloader Partition has been defined */!]
[!FOR "SEGMENT_IDX" = "1" TO "$SEGMENT_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:43:FOR4 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!IF "(Segments/*[number($SEGMENT_IDX)]/Partition_Type) = 'PROG_BOOTLOADER_PARTITION'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:44:IF5 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "SEGMENT_FOR_BOOTLOADER_PARTITION_IS_DEFINED" = "1"!]
        [!VAR "NAME_OF_SEGMENT_FOR_BOOTLOADER_PARTITION" = "text:toupper(name(as:modconf('Prog')/Segments/*[number($SEGMENT_IDX)]))"!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:47:DUMMYELSE6 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ENDFOR!]

[!/* In case that a segment has been defined for Bootloader partition, a block with index 0 shall refer to this segment */!]
[!IF "$SEGMENT_FOR_BOOTLOADER_PARTITION_IS_DEFINED = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:51:IF7 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!VAR "GOOD_ASSOCIATION" = "0"!]
    [!VAR "BLOCK_INDEX_0_IS_DEFINED" = "0"!]
    [!VAR "BLOCK_REFERENCING_SEGMENT_BOOTLOADER_EXISTS" = "0"!]
    [!VAR "NUMBER_OF_BLOCKS_WHICH_REFER_TO_BOOT_PARTITION_SEGMENT" = "0"!]
    [!FOR "BLOCK_IDX" = "1" TO "$BLOCK_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:56:FOR8 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!IF "(text:toupper(name(node:ref(as:modconf('Prog')/Blocks/*[number($BLOCK_IDX)]/First_Segment))) = $NAME_OF_SEGMENT_FOR_BOOTLOADER_PARTITION)"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:57:IF9 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "BLOCK_REFERENCING_SEGMENT_BOOTLOADER_EXISTS" = "1"!]
            [!VAR "NAME_OF_BLOCK_REFERENCING_BOOTLOADER_SEGMENT" = "name(as:modconf('Prog')/Blocks/*[number($BLOCK_IDX)])"!]
            [!VAR "NUMBER_OF_BLOCKS_WHICH_REFER_TO_BOOT_PARTITION_SEGMENT" = "$NUMBER_OF_BLOCKS_WHICH_REFER_TO_BOOT_PARTITION_SEGMENT + 1"!]
            [!IF "num:hextoint(as:modconf('Prog')/Blocks/*[number($BLOCK_IDX)]/Block_Identifier) = number('0')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:61:IF10 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "BLOCK_INDEX_0_IS_DEFINED" = "1"!]
                [!VAR "NAME_OF_BLOCK_INDEX_0" = "name(as:modconf('Prog')/Blocks/*[number($BLOCK_IDX)])"!]
                [!VAR "GOOD_ASSOCIATION" = "1"!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:65:DUMMYELSE11 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:66:ELSE12 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!IF "num:hextoint(as:modconf('Prog')/Blocks/*[number($BLOCK_IDX)]/Block_Identifier) = number('0')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:67:IF13 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "BLOCK_INDEX_0_IS_DEFINED" = "1"!]
                [!VAR "NAME_OF_BLOCK_INDEX_0" = "name(as:modconf('Prog')/Blocks/*[number($BLOCK_IDX)])"!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:70:DUMMYELSE14 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!ENDIF!]
    [!ENDFOR!]
    [!IF "$GOOD_ASSOCIATION = 0"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:73:IF15 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!IF "$BLOCK_INDEX_0_IS_DEFINED = 0"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:74:IF16 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!IF "$BLOCK_REFERENCING_SEGMENT_BOOTLOADER_EXISTS = 0"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:75:IF17 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!ERROR!]
                    No block with index 0 exists and no block refers to "[!"$NAME_OF_SEGMENT_FOR_BOOTLOADER_PARTITION"!]"
                [!ENDERROR!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:79:ELSE18 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!IF "$NUMBER_OF_BLOCKS_WHICH_REFER_TO_BOOT_PARTITION_SEGMENT = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:80:IF19 osc_PROG main ', $project))"!][!ENDSELECT!]
                    [!ERROR!]
                        Block "[!"$NAME_OF_BLOCK_REFERENCING_BOOTLOADER_SEGMENT"!]" which refers to "[!"$NAME_OF_SEGMENT_FOR_BOOTLOADER_PARTITION"!]" must have index 0
                    [!ENDERROR!]
                [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:84:ELSE20 osc_PROG main ', $project))"!][!ENDSELECT!]
                    [!ERROR!]
                        More than one block refers to "[!"$NAME_OF_SEGMENT_FOR_BOOTLOADER_PARTITION"!]" but none of them has index 0
                    [!ENDERROR!]
                [!ENDIF!]
            [!ENDIF!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:90:ELSE21 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!IF "$BLOCK_REFERENCING_SEGMENT_BOOTLOADER_EXISTS = 0"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:91:IF22 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!ERROR!]
                    No block refers to "[!"$NAME_OF_SEGMENT_FOR_BOOTLOADER_PARTITION"!]". Block with index 0 "[!"$NAME_OF_BLOCK_INDEX_0"!]" must refer to "[!"$NAME_OF_SEGMENT_FOR_BOOTLOADER_PARTITION"!]"
                [!ENDERROR!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:95:ELSE23 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!IF "$NUMBER_OF_BLOCKS_WHICH_REFER_TO_BOOT_PARTITION_SEGMENT = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:96:IF24 osc_PROG main ', $project))"!][!ENDSELECT!]
                    [!ERROR!]
                        Either Block with index 0 "[!"$NAME_OF_BLOCK_INDEX_0"!]" must refer to "[!"$NAME_OF_SEGMENT_FOR_BOOTLOADER_PARTITION"!]" or block "[!"$NAME_OF_BLOCK_REFERENCING_BOOTLOADER_SEGMENT"!]" which refers to "[!"$NAME_OF_SEGMENT_FOR_BOOTLOADER_PARTITION"!]" must have index 0
                    [!ENDERROR!]
                [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:100:ELSE25 osc_PROG main ', $project))"!][!ENDSELECT!]
                    [!ERROR!]
                        More than one block refers to "[!"$NAME_OF_SEGMENT_FOR_BOOTLOADER_PARTITION"!]" but none of them has index 0. Block with index 0 "[!"$NAME_OF_BLOCK_INDEX_0"!]" doesn't refer to "[!"$NAME_OF_SEGMENT_FOR_BOOTLOADER_PARTITION"!]"
                    [!ENDERROR!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:107:DUMMYELSE26 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:108:DUMMYELSE27 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!/*Check if two segment are not overlapping each other */!]
[!FOR "SEGMENT_IDX" = "1" TO "$SEGMENT_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:111:FOR28 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!FOR "SEGMENT_IDX_2" = "1" TO "$SEGMENT_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:112:FOR29 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!IF "$SEGMENT_IDX_2 != $SEGMENT_IDX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:113:IF30 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!IF "(num:dectoint(Segments/*[number($SEGMENT_IDX)]/Reprog_Start_Address) >= num:dectoint(Segments/*[number($SEGMENT_IDX_2)]/Reprog_Start_Address)
                    and num:dectoint(Segments/*[number($SEGMENT_IDX)]/Reprog_Start_Address) <= num:dectoint(Segments/*[number($SEGMENT_IDX_2)]/Reprog_End_Address))
                    and (num:dectoint(Segments/*[number($SEGMENT_IDX)]/Reprog_Start_Address) != 0 and num:dectoint(Segments/*[number($SEGMENT_IDX_2)]/Reprog_End_Address) != 0)"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:116:IF31 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!WARNING "The reprogramming start address of a segment shall not be inside an already configured one"!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:118:DUMMYELSE32 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
            [!IF "(num:dectoint(Segments/*[number($SEGMENT_IDX)]/Reprog_End_Address) >= num:dectoint(Segments/*[number($SEGMENT_IDX_2)]/Reprog_Start_Address)
                    and num:dectoint(Segments/*[number($SEGMENT_IDX)]/Reprog_End_Address) <= num:dectoint(Segments/*[number($SEGMENT_IDX_2)]/Reprog_End_Address))
                    and (num:dectoint(Segments/*[number($SEGMENT_IDX)]/Reprog_Start_Address) != 0 and num:dectoint(Segments/*[number($SEGMENT_IDX_2)]/Reprog_End_Address) != 0)"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:121:IF33 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!WARNING "The reprogramming end address of a segment shall not be inside an already configured one"!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:123:DUMMYELSE34 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
            [!IF "(num:dectoint(Segments/*[number($SEGMENT_IDX)]/Erase_Start_Address) >= num:dectoint(Segments/*[number($SEGMENT_IDX_2)]/Erase_Start_Address)
                    and num:dectoint(Segments/*[number($SEGMENT_IDX)]/Erase_Start_Address) <= num:dectoint(Segments/*[number($SEGMENT_IDX_2)]/Erase_End_Address))
                    and (num:dectoint(Segments/*[number($SEGMENT_IDX)]/Erase_Start_Address) != 0 and num:dectoint(Segments/*[number($SEGMENT_IDX_2)]/Erase_End_Address) != 0)"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:126:IF35 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!WARNING "The erasing start address of a segment shall not be inside an already configured one"!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:128:DUMMYELSE36 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
            [!IF "(num:dectoint(Segments/*[number($SEGMENT_IDX)]/Erase_End_Address) >= num:dectoint(Segments/*[number($SEGMENT_IDX_2)]/Erase_Start_Address)
                    and num:dectoint(Segments/*[number($SEGMENT_IDX)]/Erase_End_Address) <= num:dectoint(Segments/*[number($SEGMENT_IDX_2)]/Erase_End_Address))
                    and (num:dectoint(Segments/*[number($SEGMENT_IDX)]/Erase_Start_Address) != 0 and num:dectoint(Segments/*[number($SEGMENT_IDX_2)]/Erase_End_Address) != 0)"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:131:IF37 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!WARNING "The erasing end address of a segment shall not be inside an already configured one"!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:133:DUMMYELSE38 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:134:DUMMYELSE39 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ENDFOR!]
[!ENDFOR!]

[!IF "node:exists(as:modconf('ProgFCA')) and (as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High') and (as:modconf('Prog')/DownloadVerification/FCA_Reprogramming = 'Standard')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:138:IF40 osc_PROG main ', $project))"!][!ENDSELECT!]
[!/*Check if the CRC isn't outside of the block */!]
  [!VAR "START_ADD"="0"!]
  [!VAR "END_ADD"="0"!]
  [!VAR "BLOCK_FIRST_SEGMENT_INDEX"="0"!]
  [!FOR "BLOCK_IDX" = "1" TO "$BLOCK_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:143:FOR41 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!VAR "CRC_IS_IN_BLOCK"="0"!]
    [!VAR "BLOCK_FIRST_SEGMENT_NAME"="name(node:ref(Blocks/*[number($BLOCK_IDX)]/First_Segment))"!]
    [!VAR "CRC_ADDR"="num:dectoint(Blocks/*[number($BLOCK_IDX)]/Crc_Address)"!]
    [!FOR "SEGMENT_IDX" = "1" TO "$SEGMENT_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:147:FOR42 osc_PROG main ', $project))"!][!ENDSELECT!]
      [!VAR "CURRENT_SEGMENT_NAME" = "name(as:modconf('Prog')/Segments/*[number($SEGMENT_IDX)])"!]
      [!IF "$BLOCK_FIRST_SEGMENT_NAME = $CURRENT_SEGMENT_NAME"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:149:IF43 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "START_ADD"="num:dectoint(Segments/*[number($SEGMENT_IDX)]/Reprog_Start_Address)"!]
        [!VAR "END_ADD"="num:dectoint(Segments/*[number($SEGMENT_IDX)]/Reprog_End_Address)"!]
        [!VAR "PARTITION_TYPE" = "Segments/*[number($SEGMENT_IDX)]/Partition_Type"!]
        [!VAR "BLOCK_FIRST_SEGMENT_INDEX" = "$SEGMENT_IDX"!]
        [!IF "(num:i($CRC_ADDR) >= num:i($START_ADD)) and (num:i($CRC_ADDR) <= (num:i($END_ADD)-1))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:154:IF44 osc_PROG main ', $project))"!][!ENDSELECT!]
          [!VAR "CRC_IS_IN_BLOCK"="1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:156:DUMMYELSE45 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!BREAK!]
      [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:158:DUMMYELSE46 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ENDFOR!]
    [!IF "$SEGMENT_MAX > 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:160:IF47 osc_PROG main ', $project))"!][!ENDSELECT!]
      [!VAR "BLOCK_SEGMENT_NBR"="num:dectoint(Blocks/*[number($BLOCK_IDX)]/Segment_Number)"!]
      [!FOR "SEGMENT_IDX" = "1" TO "$BLOCK_SEGMENT_NBR - 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:162:FOR48 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!FOR "SEGMENT_IDX_2" = "1" TO "$SEGMENT_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:163:FOR49 osc_PROG main ', $project))"!][!ENDSELECT!]
          [!IF "$SEGMENT_IDX_2 != $BLOCK_FIRST_SEGMENT_INDEX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:164:IF50 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!IF "($PARTITION_TYPE = Segments/*[number($SEGMENT_IDX_2)]/Partition_Type)"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:165:IF51 osc_PROG main ', $project))"!][!ENDSELECT!]
              [!VAR "START_ADD"="num:dectoint(Segments/*[number($SEGMENT_IDX_2)]/Reprog_Start_Address)"!]
              [!VAR "END_ADD"="num:dectoint(Segments/*[number($SEGMENT_IDX_2)]/Reprog_End_Address)"!]
              [!IF "(num:i($CRC_ADDR) >= num:i($START_ADD)) and (num:i($CRC_ADDR) <= (num:i($END_ADD)-1))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:168:IF52 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "CRC_IS_IN_BLOCK"="1"!]
              [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:170:DUMMYELSE53 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:171:ELSE54 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!ENDIF!]
          [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:173:DUMMYELSE55 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!ENDFOR!]
      [!ENDFOR!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:176:DUMMYELSE56 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!IF "$CRC_IS_IN_BLOCK = 0"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:177:IF57 osc_PROG main ', $project))"!][!ENDSELECT!]
      [!ERROR!]
        Block [!"string($BLOCK_IDX - 1)"!] : The CRC is outside of the block
      [!ENDERROR!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:181:DUMMYELSE58 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
  [!ENDFOR!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:183:DUMMYELSE59 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
/*----------------------------------------------------------------------------------*/
[!ENDNOCODE!]

const tCfgMemorytType m_astCfgMemory[PROG_MEMORY_NB] =
{
    [!FOR "MEMORY_IDX" = "1" TO "$MEMORY_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:189:FOR60 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "(node:exists(as:modconf('ReProgMemM')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:190:IF61 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!VAR "MEMORY_TYPE"="text:toupper(as:modconf('ReProgMemM')/MemoryConfig/Memory/*[number($MEMORY_IDX)]/Memory_Type)"!]
    [!VAR "MEMORY_MIN_VALUE_TO_WRITE"="num:inttohex(as:modconf('ReProgMemM')/MemoryConfig/Memory/*[number($MEMORY_IDX)]/Min_Value_To_Write)"!]
    [!VAR "MEMORY_ADDRESS_OFFSET"="num:inttohex(as:modconf('ReProgMemM')/MemoryConfig/Memory/*[number($MEMORY_IDX)]/Addr_Offset)"!]
    [!VAR "MEMORY_ERASE_VALUE"="num:inttohex(as:modconf('ReProgMemM')/MemoryConfig/Memory/*[number($MEMORY_IDX)]/Erase_Value)"!]
[!ELSEIF "node:exists(as:modconf('Flash')) or (node:exists(as:modconf('ProgFord')) and as:modconf('ProgFord')/General/PROG_FORD_VARIANT='PBL') or (node:exists(as:modconf('ProgJLR')) and as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL') or (node:exists(as:modconf('ProgVCC')) and as:modconf('ProgVCC')/General/PROG_VCC_VARIANT='PBL')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:195:ELSEIF62 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!VAR "MEMORY_TYPE"="text:toupper(Memory/*[number($MEMORY_IDX)]/Memory_Type)"!]
    [!VAR "MEMORY_MODE"="(Memory/*[number($MEMORY_IDX)]/Memory_Mode)"!]
    [!VAR "MEMORY_MIN_VALUE_TO_WRITE"="num:inttohex(Memory/*[number($MEMORY_IDX)]/Min_Value_To_Write)"!]
    [!VAR "MEMORY_ADDRESS_OFFSET"="num:inttohex(Memory/*[number($MEMORY_IDX)]/Addr_Offset)"!]
    [!VAR "MEMORY_ERASE_VALUE"="num:inttohex(Memory/*[number($MEMORY_IDX)]/Erase_Value)"!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:201:DUMMYELSE63 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

    {
        PROG_MEM_TYPE_[!"$MEMORY_TYPE"!],
[!IF "node:exists(as:modconf('Flash'))  or (node:exists(as:modconf('ProgFord')) and as:modconf('ProgFord')/General/PROG_FORD_VARIANT='PBL') or (node:exists(as:modconf('ProgJLR')) and as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL') or (node:exists(as:modconf('ProgVCC')) and as:modconf('ProgVCC')/General/PROG_VCC_VARIANT='PBL')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:205:IF64 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!WS "8"!][!IF "$MEMORY_MODE = 'asynchronous'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:206:IF65 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEMORY_ASYNCHRONOUS[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:206:ELSE66 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEMORY_SYNCHRONOUS[!ENDIF!],
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:207:DUMMYELSE67 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!"$MEMORY_MIN_VALUE_TO_WRITE"!]U,
        [!"$MEMORY_ADDRESS_OFFSET"!]U,
        [!"$MEMORY_ERASE_VALUE"!]U,
    },
    [!ENDFOR!]
};

[!IF "General/Tunable_Parameters = 'false'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:215:IF68 osc_PROG main ', $project))"!][!ENDSELECT!]
 [!VAR "SIGNATUREVERIFCATIONENABLED"="'false'"!]
 [!IF "(node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_Mid')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:217:IF69 osc_PROG main ', $project))"!][!ENDSELECT!]
  [!FOR "SEGMENT_IDX" = "1" TO "$SEGMENT_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:218:FOR70 osc_PROG main ', $project))"!][!ENDSELECT!]
  [!IF "Segments/*[number($SEGMENT_IDX)]/SignatureVerification = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:219:IF71 osc_PROG main ', $project))"!][!ENDSELECT!]
   [!VAR "SIGNATUREVERIFCATIONENABLED"="'true'"!]
   [!VAR "SEGMENT_IDX"="$SEGMENT_MAX"!]
  [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:222:DUMMYELSE72 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
  [!ENDFOR!]
  [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:224:DUMMYELSE73 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
const tCfgSegmentType stConfigSegment[PROG_SEGMENT_NB] =
{
    [!FOR "SEGMENT_IDX" = "1" TO "$SEGMENT_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:227:FOR74 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "START_ADD"="num:inttohex(Segments/*[number($SEGMENT_IDX)]/Reprog_Start_Address)"!]
        [!VAR "END_ADD"="num:inttohex(Segments/*[number($SEGMENT_IDX)]/Reprog_End_Address)"!]
        [!VAR "ERASE_START_ADD"="num:inttohex(Segments/*[number($SEGMENT_IDX)]/Erase_Start_Address)"!]
        [!VAR "ERASE_END_ADD"="num:inttohex(Segments/*[number($SEGMENT_IDX)]/Erase_End_Address)"!]
        [!VAR "MEM_NAME" = "text:toupper(name(node:ref(Segments/*[number($SEGMENT_IDX)]/Memory)))"!]
        [!VAR "ACCESS_TYPE"="num:Segments/*[number($SEGMENT_IDX)]/Access_Type"!]

        [!FOR "MEMORY_IDX" = "1" TO "$MEMORY_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:235:FOR75 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "(node:exists(as:modconf('ReProgMemM')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:236:IF76 osc_PROG main ', $project))"!][!ENDSELECT!]
		 [!IF "$MEM_NAME = text:toupper(name(as:modconf('ReProgMemM')/MemoryConfig/Memory/*[number($MEMORY_IDX)]))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:237:IF77 osc_PROG main ', $project))"!][!ENDSELECT!][!//
		    [!VAR "SELECTED_MEM_IDX" = "num:dectoint($MEMORY_IDX - 1)"!][!//
         [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:239:DUMMYELSE78 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSEIF "node:exists(as:modconf('Flash')) or (node:exists(as:modconf('ProgFord')) and as:modconf('ProgFord')/General/PROG_FORD_VARIANT='PBL') or (node:exists(as:modconf('ProgJLR')) and as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL') or (node:exists(as:modconf('ProgVCC')) and as:modconf('ProgVCC')/General/PROG_VCC_VARIANT='PBL')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:240:ELSEIF79 osc_PROG main ', $project))"!][!ENDSELECT!]
                 [!IF "$MEM_NAME = text:toupper(name(Memory/*[number($MEMORY_IDX)]))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:241:IF80 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "SELECTED_MEM_IDX" = "num:dectoint($MEMORY_IDX - 1)"!][!//
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:243:DUMMYELSE81 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:244:DUMMYELSE82 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!ENDFOR!]
        [!VAR "LAST_LOWER_START_ADDRESS" = "0"!]
        [!IF "(((node:exists(as:modconf('ProgOEMInd')) and as:modconf('Prog')/OemInd/Erase_Mode = 'All') or node:exists(as:modconf('ProgVCC')) or node:exists(as:modconf('ProgFord'))) and $BLOCK_MAX=0)"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:247:IF83 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "BLOCK_INDEX" = "num:i(0)"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:249:DUMMYELSE84 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!FOR "BLOCK_IDX" = "1" TO "$BLOCK_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:250:FOR85 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "SEGMENT_REFERENCE" = "text:toupper(name(node:ref(as:modconf('Prog')/Blocks/*[number($BLOCK_IDX)]/First_Segment)))"!]
            [!FOR "SEGMENT_IDX1" = "1" TO "$SEGMENT_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:252:FOR86 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!IF "(text:toupper(name(as:modconf('Prog')/Segments/*[number($SEGMENT_IDX1)])) = $SEGMENT_REFERENCE)"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:253:IF87 osc_PROG main ', $project))"!][!ENDSELECT!]
                    [!VAR "CURRENT_START_ADDRESS" = "num:dectoint(as:modconf('Prog')/Segments/*[number($SEGMENT_IDX1)]/Reprog_Start_Address)"!]
                    [!IF "$CURRENT_START_ADDRESS <= num:dectoint(as:modconf('Prog')/Segments/*[number($SEGMENT_IDX)]/Reprog_Start_Address)"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:255:IF88 osc_PROG main ', $project))"!][!ENDSELECT!]
                        [!IF "$LAST_LOWER_START_ADDRESS <= $CURRENT_START_ADDRESS"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:256:IF89 osc_PROG main ', $project))"!][!ENDSELECT!]
                            [!VAR "BLOCK_INDEX" = "num:i(($BLOCK_IDX)-1)"!]
                            [!VAR "LAST_LOWER_START_ADDRESS" = "$CURRENT_START_ADDRESS"!]
                        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:259:DUMMYELSE90 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
                    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:260:DUMMYELSE91 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
                [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:261:DUMMYELSE92 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
            [!ENDFOR!]
        [!ENDFOR!]
    {
        [!"$START_ADD"!]U,[!WS "24"!]/* Start Address */
        [!"$END_ADD"!]U,[!WS "24"!]/* End Address */
        [!"$ERASE_START_ADD"!]U,[!WS "24"!]/* Erase Start Address */
        [!"$ERASE_END_ADD"!]U,[!WS "24"!]/* Erase End Address */
        [!"$SELECTED_MEM_IDX"!]U,[!WS "15"!]/* Selected Memory Index */
        PROG_MEM_ACCESS_TYPE_[!"$ACCESS_TYPE"!],[!WS "3"!]/* Memory Access Type */
[!IF "node:exists(as:modconf('ProgGM')) or node:exists(as:modconf('ProgFCA')) or node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgDAG')) or node:exists(as:modconf('ProgVCC')) or node:exists(as:modconf('ProgFord')) or node:exists(as:modconf('ProgOEMInd'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:271:IF93 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!"Segments/*[number($SEGMENT_IDX)]/Partition_Type"!][!IF "node:exists(as:modconf('ProgOEMInd')) or node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgDAG')) or node:exists(as:modconf('ProgVCC')) or node:exists(as:modconf('ProgFord')) or (node:exists(as:modconf('ProgFCA')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:272:IF94 osc_PROG main ', $project))"!][!ENDSELECT!],[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:272:DUMMYELSE95 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!][!WS "8"!]/* Partition Type */
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:273:DUMMYELSE96 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('ProgOEMInd'))) or (node:exists(as:modconf('ProgJLR')) and (as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='SBL') or ( as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='OneLevelBL'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:274:IF97 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!WS "8"!][!IF "Segments/*[number($SEGMENT_IDX)]/ValidityCheck = 'false'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:275:IF98 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:275:ELSE99 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE[!ENDIF!],/* Validity Check */
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:276:DUMMYELSE100 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgDAG')) or node:exists(as:modconf('ProgVCC')) or node:exists(as:modconf('ProgFord')) or (node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High') or (node:exists(as:modconf('ProgOEMInd')) and as:modconf('Prog')/OemInd/Erase_Mode != 'Address') or node:exists(as:modconf('ProgPSA'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:277:IF101 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!"$BLOCK_INDEX"!]U,[!WS "33"!]/* Corresponding Block Index */
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:279:DUMMYELSE102 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
 [!IF "(node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_Mid') and ($SIGNATUREVERIFCATIONENABLED = 'true')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:280:IF103 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!WS "8"!][!IF "Segments/*[number($SEGMENT_IDX)]/SignatureVerification = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:281:IF104 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE [!WS "18"!][!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:281:ELSE105 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE[!WS "17"!][!ENDIF!] /*Signature Verification to be done or not for this segment */
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:282:DUMMYELSE106 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    },
    [!ENDFOR!]
};

[!IF "node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgDAG')) or node:exists(as:modconf('ProgPSA'))
    or (node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High')
    or (node:exists(as:modconf('ProgOEMInd')) and OemInd/Erase_Mode = 'LogicalBlock')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:289:IF107 osc_PROG main ', $project))"!][!ENDSELECT!]
const tProg_Block    stCfgBlock[PROG_BLOCK_NB] =
{
    [!FOR "BLOCK_IDX" = "1" TO "$BLOCK_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:292:FOR108 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "BLOCK_IDENT"="num:inttohex(Blocks/*[number($BLOCK_IDX)]/Block_Identifier)"!]
        [!VAR "SEGMENT_NAME"="text:toupper(name(node:ref(Blocks/*[number($BLOCK_IDX)]/First_Segment)))"!]
        [!VAR "SEGMENT_NBR"="num:inttohex(Blocks/*[number($BLOCK_IDX)]/Segment_Number)"!]
        [!VAR "SEGMENT_PRG_CNT_MAX"="num:inttohex(Blocks/*[number($BLOCK_IDX)]/Block_Programming_Counter_Max)"!]
        [!VAR "SEGMENT_ID"="(Blocks/*[number($BLOCK_IDX)]/First_Segment)"!]
[!IF "node:exists(as:modconf('ProgFCA')) and (as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High') and (as:modconf('Prog')/DownloadVerification/FCA_Reprogramming = 'Standard')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:298:IF109 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "CRC_ADDR"="num:inttohex(Blocks/*[number($BLOCK_IDX)]/Crc_Address)"!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:300:DUMMYELSE110 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    {
        [!"$BLOCK_IDENT"!]U,[!WS "23"!]/* Block Identifier */
        PROG_SEG_[!"$SEGMENT_NAME"!],[!WS "2"!]/* Name of the first segment*/
        [!"$SEGMENT_NBR"!]U,[!WS "23"!]/* Number of segments contained in the block */
        [!"$SEGMENT_PRG_CNT_MAX"!]U,[!WS "23"!]/* Maximum number of programming allowed */
[!IF "node:exists(as:modconf('ProgFCA')) and (as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High') and (as:modconf('Prog')/DownloadVerification/FCA_Reprogramming = 'Standard')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:306:IF111 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!"$CRC_ADDR"!]U,[!WS "16"!]/* Address of the CRC in data*/
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:308:DUMMYELSE112 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "((node:exists(as:modconf('ProgVAG')))and (as:modconf('Prog')/VAG/Downgrade_Protection = 'true'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:309:IF113 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!WS "8"!][!IF "Blocks/*[number($BLOCK_IDX)]/Downgrade_Protected = 'false'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:310:IF114 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:310:ELSE115 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE[!ENDIF!],[!WS "18"!]/* Downgrade Protected */
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:311:DUMMYELSE116 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    },
    [!ENDFOR!]
    [!IF "General/PreliminaryErasing = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:314:IF117 osc_PROG main ', $project))"!][!ENDSELECT!]
    /* A virtual block containing all the segments in order to support preliminary erasing */
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:316:DUMMYELSE118 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
     [!IF "node:exists(as:modconf('ProgPSA'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:317:IF119 osc_PROG main ', $project))"!][!ENDSELECT!]
     /* A virtual block containing all the segments in order to search a segment ID */
     [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:319:DUMMYELSE120 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
     [!IF "General/PreliminaryErasing = 'true' or node:exists(as:modconf('ProgPSA'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:320:IF121 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "SEGMENT_NAME"="text:toupper(name(Segments/*[number(1)]))"!]
        [!VAR "SEGMENT_NBR"="num:dectoint(count(Segments/*))"!]
    {
        PROG_MAX_BLOCK_ID,[!WS "10"!]/* Block Identifier */
        PROG_SEG_[!"$SEGMENT_NAME"!],[!WS "11"!]/* Name of the first segment*/
        [!"$SEGMENT_NBR"!]U,[!WS "25"!]/* Number of segments contained in the block */
        0U,[!WS "25"!]/* Maximum number of programming allowed */
[!IF "((node:exists(as:modconf('ProgVAG')))and (as:modconf('Prog')/VAG/Downgrade_Protection = 'true'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:328:IF122 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!WS "8"!]PROG_TRUE,[!WS "18"!]/* Downgrade Protected */
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:330:DUMMYELSE123 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    }
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:332:DUMMYELSE124 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
};
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:334:DUMMYELSE125 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!/*All segments shall be erased on reception of EraseMemory so we generate a single block containing all segments */!]
[!IF "((node:exists(as:modconf('ProgOEMInd')) and OemInd/Erase_Mode = 'All') or (node:exists(as:modconf('ProgVCC'))) or (node:exists(as:modconf('ProgFord'))))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:337:IF126 osc_PROG main ', $project))"!][!ENDSELECT!]
const tProg_Block    stCfgBlock[PROG_BLOCK_NB] =
{
    [!VAR "SEGMENT_NAME"="text:toupper(name(Segments/*[number(1)]))"!]
    [!VAR "SEGMENT_NBR"="num:dectoint(count(Segments/*))"!]
    {
        0,/* Block Identifier */
        PROG_SEG_[!"$SEGMENT_NAME"!],/* Name of the first segment*/
        [!"$SEGMENT_NBR"!]U,/* Number of segments contained in the block */
        0,/* Maximum number of programming allowed */
    },
};
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:349:DUMMYELSE127 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "((as:modconf('BM')/Security/SecureBoot/SECURE_AUTHENTICATED_BOOT != 'OFF') or (as:modconf('Prog')/Security/Secure_Checksum_computation = 'true'))
       and (node:exists(as:modconf('ProgDAG'))
       or  (node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High')
       or  (node:exists(as:modconf('ProgOEMInd')) and as:modconf('Prog')/OemInd/Erase_Mode = 'LogicalBlock'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:354:IF128 osc_PROG main ', $project))"!][!ENDSELECT!]
const tProg_BlockSecureBootInfo    stCfgBlockSecureBootInfo[PROG_BLOCK_NB] =
{
    [!FOR "BLOCK_IDX" = "1" TO "$BLOCK_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:357:FOR129 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "BLOCK_IDENT"="num:inttohex(Blocks/*[number($BLOCK_IDX)]/Block_Identifier)"!]
        [!VAR "START_ADDRESS"="num:inttohex(Blocks/*[number($BLOCK_IDX)]/SecureBoot/Start_Address_Secure_Boot_Verification)"!]
        [!VAR "LENGTH"="num:inttohex(Blocks/*[number($BLOCK_IDX)]/SecureBoot/Length_Secure_Boot_Verification)"!]
    {
        [!WS "8"!][!"$START_ADDRESS"!]U,[!WS "17"!]/* Start Address for the Secure Boot Verification */
        [!WS "8"!][!"$LENGTH"!]U,[!WS "17"!]/* Length of the block for the Secure Boot Verification */
        [!"$BLOCK_IDENT"!]U,[!WS "23"!]/* Block Identifier */
        [!WS "8"!][!IF "Blocks/*[number($BLOCK_IDX)]/SecureBoot/Verified_For_Secure_Boot='Block will be verified'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:365:IF130 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE,[!WS "18"!][!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:365:ELSE131 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE,[!WS "17"!][!ENDIF!]/* Block will be verified by the Secure Boot */
        [!WS "8"!][!IF "Blocks/*[number($BLOCK_IDX)]/SecureBoot/Blocker_for_Software_execution='Will block software execution'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:366:IF132 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE,[!WS "18"!][!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:366:ELSE133 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE,[!WS "17"!][!ENDIF!]/* Block will prevent the execution of software if Secure Boot verification is failed */
    },
    [!ENDFOR!]
};
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:370:DUMMYELSE134 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "((as:modconf('BM')/Security/SecureBoot/SECURE_AUTHENTICATED_BOOT != 'OFF') or (as:modconf('Prog')/Security/Secure_Checksum_computation = 'true'))
       and ((node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_Mid') 
       or    node:exists(as:modconf('ProgJLR'))
       or   (node:exists(as:modconf('ProgOEMInd')) and as:modconf('Prog')/OemInd/Erase_Mode != 'LogicalBlock'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:374:IF135 osc_PROG main ', $project))"!][!ENDSELECT!]
const tProg_BlockSecureBootInfo    stCfgBlockSecureBootInfo[PROG_SEGMENT_NB] =
{
    [!FOR "SEGMENT_IDX" = "1" TO "$SEGMENT_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:377:FOR136 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "START_ADDRESS"="num:inttohex(Segments/*[number($SEGMENT_IDX)]/SecureBoot/Start_Address_Secure_Boot_Verification)"!]
        [!VAR "LENGTH"="num:inttohex(Segments/*[number($SEGMENT_IDX)]/SecureBoot/Length_Secure_Boot_Verification)"!]
    {
        [!WS "8"!][!"$START_ADDRESS"!]U,[!WS "17"!]/* Start Address for the Secure Boot Verification */
        [!WS "8"!][!"$LENGTH"!]U,[!WS "17"!]/* Memory size for the Secure Boot Verification */
        [!"$SEGMENT_IDX"!]U,[!WS "23"!]/* Segment Identifier */
        [!WS "8"!][!IF "Segments/*[number($SEGMENT_IDX)]/SecureBoot/Verified_For_Secure_Boot='Block will be verified'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:384:IF137 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE,[!WS "18"!][!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:384:ELSE138 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE,[!WS "17"!][!ENDIF!]/* if TRUE Segment will be verified by the Secure Boot else this will be excluded from the secure boot verification */
        [!WS "8"!][!IF "Segments/*[number($SEGMENT_IDX)]/SecureBoot/Blocker_for_Software_execution='Will block software execution'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:385:IF139 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE,[!WS "18"!][!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:385:ELSE140 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE,[!WS "17"!][!ENDIF!]/* if set to TRUE then on the failure of Secure Boot verification for this segment, execution of the software is halted*/
    },
    [!ENDFOR!]
};
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:389:DUMMYELSE141 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:390:ELSE142 osc_PROG main ', $project))"!][!ENDSELECT!]
const tCfgSegmentType stConstConfigSegment[PROG_SEGMENT_NB] =
{
    [!VAR "NBR_PROT_CAL"="0"!]
    [!FOR "SEGMENT_IDX" = "1" TO "$SEGMENT_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:394:FOR143 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "START_ADD"="num:inttohex(Segments/*[number($SEGMENT_IDX)]/Reprog_Start_Address)"!]
        [!VAR "END_ADD"="num:inttohex(Segments/*[number($SEGMENT_IDX)]/Reprog_End_Address)"!]
        [!VAR "ERASE_START_ADD"="num:inttohex(Segments/*[number($SEGMENT_IDX)]/Erase_Start_Address)"!]
        [!VAR "ERASE_END_ADD"="num:inttohex(Segments/*[number($SEGMENT_IDX)]/Erase_End_Address)"!]
        [!VAR "MEM_NAME" = "text:toupper(name(node:ref(Segments/*[number($SEGMENT_IDX)]/Memory)))"!]
        [!VAR "ACCESS_TYPE"="num:Segments/*[number($SEGMENT_IDX)]/Access_Type"!]
        [!FOR "MEMORY_IDX" = "1" TO "$MEMORY_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:401:FOR144 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!IF "$MEM_NAME = text:toupper(name(Memory/*[number($MEMORY_IDX)]))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:402:IF145 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "SELECTED_MEM_IDX" = "num:dectoint($MEMORY_IDX - 1)"!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:404:DUMMYELSE146 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!ENDFOR!]
    {
        [!"$START_ADD"!]U,
        [!"$END_ADD"!]U,
        [!"$ERASE_START_ADD"!]U,
        [!"$ERASE_END_ADD"!]U,
        [!"$SELECTED_MEM_IDX"!]U,
        PROG_MEM_ACCESS_TYPE_[!"$ACCESS_TYPE"!],
[!IF "node:exists(as:modconf('ProgGM'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:413:IF147 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!"Segments/*[number($SEGMENT_IDX)]/Partition_Type"!],
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:415:DUMMYELSE148 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
 [!IF "node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_Mid'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:416:IF149 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!WS "8"!][!IF "Segments/*[number($SEGMENT_IDX)]/SignatureVerification = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:417:IF150 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE,[!WS "18"!][!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:417:ELSE151 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE,[!WS "17"!][!ENDIF!] /*Signature Verification to be done or not for this segment */
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:418:DUMMYELSE152 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    },
    [!ENDFOR!]
};


tCfgSegmentType stConfigSegment[PROG_SEGMENT_NB];
[!ENDIF!]

[!IF "as:modconf('Prog')/Segments/*/Partition_Type = 'PROG_BLU_APP_PARTITION' 
   or as:modconf('Prog')/Segments/*/Partition_Type = 'PROG_BLU_CAL_PARTITION'
   or as:modconf('Prog')/Segments/*/Partition_Type = 'PROG_BLU_PARTITION'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:429:IF153 osc_PROG main ', $project))"!][!ENDSELECT!]
[!/* Get information about the Routine controle*/!]
    [!VAR "RC_TABLE_INDEX"="0"!]
    [!LOOP " as:modconf('Uds')/Routine_Control/*"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:432:LOOP154 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!IF "(node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgOEMInd'))) and Callback = 'PROG_CheckMemory'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:433:IF155 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "RC_TABLE_INDEX"="@index + 1"!]
tContextRestore stBLUContextRestore =
{
    [!"as:modconf('Uds')/Routine_Control/*[number($RC_TABLE_INDEX)]/SecurityLevel"!],
    {
        {
            0x31,
            [!"num:inttohex(as:modconf('Uds')/Routine_Control/*[number($RC_TABLE_INDEX)]/SubService)"!],
            [!"num:inttohex(bit:shr(bit:and(as:modconf('Uds')/Routine_Control/*[number($RC_TABLE_INDEX)]/Routine_Identifier, 65280), 8))"!],
            [!"num:inttohex(bit:and(as:modconf('Uds')/Routine_Control/*[number($RC_TABLE_INDEX)]/Routine_Identifier, 255))"!],
        },
        [!"num:inttohex(as:modconf('Uds')/Routine_Control/*[number($RC_TABLE_INDEX)]/Length)"!]
    }
};
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:448:DUMMYELSE156 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ENDLOOP!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:450:DUMMYELSE157 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "node:exists(as:modconf('ProgOEMInd'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:451:IF158 osc_PROG main ', $project))"!][!ENDSELECT!]
/* Programmed magic number value */
const u8 m_aCfgMagicNumProgrammedValue[PROG_MAGIC_NUM_SIZE] =
{
    /* PROGRAMM in ASCII */
    0x50U,
    0x52U,
    0x4FU,
    0x47U,
    0x52U,
    0x41U,
    0x4dU,
    0x4dU,
};
/* Revoked PSI value */
const u8 m_aCfgMagicNumRevokedValue[PROG_MAGIC_NUM_SIZE] =
{
    /* REVOKED in ASCII */
    0x56U,
    0x52U,
    0x45U,
    0x56U,
    0x4FU,
    0x4BU,
    0x45U,
    0x44U
};
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:478:DUMMYELSE159 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('ProgGM'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:480:IF160 osc_PROG main ', $project))"!][!ENDSELECT!]
/* Pointer to App Sw Info */
u8* m_pubAppSwInfo = (u8*)PROG_APP_SW_INFO_ADDR;
/* Programmed PSI value */
const u8 m_aCfgPSIProgrammedValue[PROG_PSI_VAL_SIZE] =
{
    0x[!"substring(GM//PSI_Programmed,1,2)"!],
    0x[!"substring(GM//PSI_Programmed,3,2)"!],
    0x[!"substring(GM//PSI_Programmed,5,2)"!],
    0x[!"substring(GM//PSI_Programmed,7,2)"!],
    0x[!"substring(GM//PSI_Programmed,9,2)"!],
    0x[!"substring(GM//PSI_Programmed,11,2)"!],
    0x[!"substring(GM//PSI_Programmed,13,2)"!],
    0x[!"substring(GM//PSI_Programmed,15,2)"!],
};
/* Revoked PSI value */
const u8 m_aCfgPSIRevokedValue[PROG_PSI_VAL_SIZE] =
{
    0x[!"substring(GM//PSI_Revoked,1,2)"!],
    0x[!"substring(GM//PSI_Revoked,3,2)"!],
    0x[!"substring(GM//PSI_Revoked,5,2)"!],
    0x[!"substring(GM//PSI_Revoked,7,2)"!],
    0x[!"substring(GM//PSI_Revoked,9,2)"!],
    0x[!"substring(GM//PSI_Revoked,11,2)"!],
    0x[!"substring(GM//PSI_Revoked,13,2)"!],
    0x[!"substring(GM//PSI_Revoked,15,2)"!],
};

/* Bootloader information */
#define PROG_BOOT_INFO_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>
const tBootInfoBlock m_stBootInfoBlock =
{
    [!"num:inttohex(GM//BCID)"!]U, /*  BICD value */
[!IF "GM/EcuId_Source = 'Tresos_Configuration'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:514:IF161 osc_PROG main ', $project))"!][!ENDSELECT!]
    /* ECU ID */
    {
        0x[!"substring(GM//ECU_ID,1,2)"!],
        0x[!"substring(GM//ECU_ID,3,2)"!],
        0x[!"substring(GM//ECU_ID,5,2)"!],
        0x[!"substring(GM//ECU_ID,7,2)"!],
        0x[!"substring(GM//ECU_ID,9,2)"!],
        0x[!"substring(GM//ECU_ID,11,2)"!],
        0x[!"substring(GM//ECU_ID,13,2)"!],
        0x[!"substring(GM//ECU_ID,15,2)"!],
        0x[!"substring(GM//ECU_ID,17,2)"!],
        0x[!"substring(GM//ECU_ID,19,2)"!],
        0x[!"substring(GM//ECU_ID,21,2)"!],
        0x[!"substring(GM//ECU_ID,23,2)"!],
        0x[!"substring(GM//ECU_ID,25,2)"!],
        0x[!"substring(GM//ECU_ID,27,2)"!],
        0x[!"substring(GM//ECU_ID,29,2)"!],
        0x[!"substring(GM//ECU_ID,31,2)"!],
    },
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:534:DUMMYELSE162 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    /* ECU name */
    {
        [!VAR "SEGMENT_MAX"="num:dectoint(string-length(GM/ECU_Name))"!]
        [!FOR "SEGMENT_IDX" = "1" TO "$SEGMENT_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:538:FOR163 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!WS "8"!]'[!"substring(GM//ECU_Name,$SEGMENT_IDX,1)"!]',
        [!ENDFOR!]
        [!FOR "SEGMENT_IDX" = "$SEGMENT_MAX" TO "7"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:541:FOR164 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!WS "8"!]0x00,
        [!ENDFOR!]
    },
    /* ECU subject name */
    {
        0x[!"substring(GM//Subject_Name,1,2)"!],
        0x[!"substring(GM//Subject_Name,3,2)"!],
        0x[!"substring(GM//Subject_Name,5,2)"!],
        0x[!"substring(GM//Subject_Name,7,2)"!],
        0x[!"substring(GM//Subject_Name,9,2)"!],
        0x[!"substring(GM//Subject_Name,11,2)"!],
        0x[!"substring(GM//Subject_Name,13,2)"!],
        0x[!"substring(GM//Subject_Name,15,2)"!],
        0x[!"substring(GM//Subject_Name,17,2)"!],
        0x[!"substring(GM//Subject_Name,19,2)"!],
        0x[!"substring(GM//Subject_Name,21,2)"!],
        0x[!"substring(GM//Subject_Name,23,2)"!],
        0x[!"substring(GM//Subject_Name,25,2)"!],
        0x[!"substring(GM//Subject_Name,27,2)"!],
        0x[!"substring(GM//Subject_Name,29,2)"!],
        0x[!"substring(GM//Subject_Name,31,2)"!],
    },
    /* Boot Part Number */
    {
        0x[!"substring(GM//BOOT_Part_Number,1,2)"!],
        0x[!"substring(GM//BOOT_Part_Number,3,2)"!],
        0x[!"substring(GM//BOOT_Part_Number,5,2)"!],
        0x[!"substring(GM//BOOT_Part_Number,7,2)"!],
    },
    /* Boot DLS */
    {
        '[!"substring(GM//BOOT_DLS,1,1)"!]',
        '[!"substring(GM//BOOT_DLS,2,1)"!]',
    },
    /* Number of Protected Calibrations*/
        [!VAR "NBR_PROT_CAL"="num:dectoint(0)"!]
[!FOR "SEGMENT_IDX" = "1" TO "$SEGMENT_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:578:FOR165 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "'PROG_PROT_CALIBRATION_PARTITION' = Segments/*[number($SEGMENT_IDX)]/Partition_Type"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:579:IF166 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "NBR_PROT_CAL" = "num:dectoint($NBR_PROT_CAL + 1)"!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:581:DUMMYELSE167 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ENDFOR!]
        [!"$NBR_PROT_CAL"!]U,
[!IF "$NBR_PROT_CAL > num:dectoint(0)"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:584:IF168 osc_PROG main ', $project))"!][!ENDSELECT!]
    /*Protected Partition IDs*/
    {
[!VAR "PROT_CAL_PARTITION_ID"="num:dectoint(0)"!]
[!FOR "SEGMENT_IDX" = "1" TO "$SEGMENT_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:588:FOR169 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "'PROG_PROT_CALIBRATION_PARTITION' = Segments/*[number($SEGMENT_IDX)]/Partition_Type"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:589:IF170 osc_PROG main ', $project))"!][!ENDSELECT!]
[!VAR "PROT_CAL_PARTITION_ID"="num:dectoint(Segments/*[number($SEGMENT_IDX)]/Protected_Partition_ID)"!]
        [!"$PROT_CAL_PARTITION_ID"!]U,
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:592:DUMMYELSE171 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ENDFOR!]
    },
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:595:DUMMYELSE172 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
};
#define PROG_BOOT_INFO_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:599:DUMMYELSE173 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('ProgPSA'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:601:IF174 osc_PROG main ', $project))"!][!ENDSELECT!]
/* Match table that contains for each routine associated index in request routine result list */
[!VAR "LIST_INDEX" = "num:i(0)"!]
const tProgRoutineResultInfo    stCfgRoutineResultTable[PROG_ROUTINE_RESULT_NB] = 
{
    [!FOR "ROUTINE_INDEX" = "1" TO "num:dectoint(count(as:modconf('Uds')/Routine_Control/*))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:606:FOR175 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!IF "as:modconf('Uds')/Routine_Control/*[number($ROUTINE_INDEX)]/SubService = '3'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:607:IF176 osc_PROG main ', $project))"!][!ENDSELECT!]
        {
            PROG_ROUTINE_ID_[!"translate(substring(num:inttohex(as:modconf('Uds')/Routine_Control/*[number($ROUTINE_INDEX)]/Routine_Identifier),3,6),'abcdef','ABCDEF')"!],[!WS "10"!]/* Routine identifier */
            [!"num:inttohex($LIST_INDEX)"!]U,[!WS "25"!]/* Index of routine identifier in the list */
            [!VAR "LIST_INDEX" = "($LIST_INDEX + 1)"!]
        },
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:613:DUMMYELSE177 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ENDFOR!]
};
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:616:DUMMYELSE178 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
 [!IF "node:exists(as:modconf('CryIf'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:617:IF179 osc_PROG main ', $project))"!][!ENDSELECT!]
/* Prog-Csm Job configurations */
  [!VAR "ProgCsmJobIndex" = "0"!]
  [!VAR "ProgCsmSignatureJobIndex" = "255"!]
  [!VAR "ProgCsmHashJobIndex" = "255"!]
  [!VAR "ProgCsmSecureJobIndex" = "255"!]
  [!VAR "ProgCsmDecryptionJobIndex" = "255"!]

[!IF "(node:exists(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:625:IF180 osc_PROG main ', $project))"!][!ENDSELECT!]
   [!VAR "ProgCsmSignatureJobIndex" = "num:dectoint(number($ProgCsmJobIndex))"!]
   [!VAR "ProgCsmJobIndex"= "$ProgCsmJobIndex + 1"!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:628:DUMMYELSE181 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('Prog')/Security/ProgCsmReferences/HashVerification/ProgCsmHashConfigId))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:629:IF182 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!VAR "ProgCsmHashJobIndex" = "num:dectoint(number($ProgCsmJobIndex))"!]
    [!VAR "ProgCsmJobIndex" = "$ProgCsmJobIndex + 1"!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:632:DUMMYELSE183 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('Prog')/Security/ProgCsmSecureConfigId))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:633:IF184 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!VAR "ProgCsmSecureJobIndex" = "num:dectoint(number($ProgCsmJobIndex))"!]
    [!VAR "ProgCsmJobIndex" = "$ProgCsmJobIndex + 1"!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:636:DUMMYELSE185 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('Prog')/Decryption/ProgCsmDecryptionConfigId))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:637:IF186 osc_PROG main ', $project))"!][!ENDSELECT!]
	[!VAR "ProgCsmDecryptionJobIndex" = "num:dectoint(number($ProgCsmJobIndex))"!]
[!VAR "ProgCsmJobIndex" = "$ProgCsmJobIndex + 1"!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:640:DUMMYELSE187 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "num:dectoint($ProgCsmJobIndex) > 0"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:641:IF188 osc_PROG main ', $project))"!][!ENDSELECT!]
const tProgCsmJobConf m_astProgCsmJobConf[PROG_CSM_NUMCONF_JOBS] =
{
[!IF "number($ProgCsmSignatureJobIndex) != 255"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:644:IF189 osc_PROG main ', $project))"!][!ENDSELECT!]
[!WS "4"!]{
[!WS "8"!][!"(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/BS_size)"!]U, /*Size of the Data Block Slicing*/
[!WS "8"!][!"(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId)/CsmJobId)"!]U, /*Corresponding Csm Job ID*/
[!WS "8"!]&PROG_CsmCheckResult, /*Callback handling API for the configured Algo*/
[!WS "8"!][!IF "(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/Allow2SetCryptoKey) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:649:IF190 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_CSM_SIGN_KEYID[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:649:ELSE191 osc_PROG main ', $project))"!][!ENDSELECT!]0U[!ENDIF!], /*KeyID assigned by Crypto Driver*/
[!WS "8"!][!IF "(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/Allow2SetCryptoKey) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:650:IF192 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_CRYPTO_SIGN_KEYELEID[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:650:ELSE193 osc_PROG main ', $project))"!][!ENDSELECT!]0U[!ENDIF!], /*KeyElementID assigned by the Crypto Driver*/
[!WS "8"!][!IF "(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/Allow2SetCryptoKey) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:651:IF194 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_CRYPTO_SIGN_KEYSIZE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:651:ELSE195 osc_PROG main ', $project))"!][!ENDSELECT!]0U[!ENDIF!], /*KeyLength stored in the Crypto Driver*/
[!WS "8"!][!IF "(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/Allow2Cancel_OngoingJobs) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:652:IF196 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:652:ELSE197 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE[!ENDIF!], /* Allow cancellation of ongoing Csm Job? */
[!WS "8"!][!IF "(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/Allow2SetCryptoKey) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:653:IF198 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:653:ELSE199 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE[!ENDIF!], /*Enable to set the key and the keystatus in the Crypto driver*/
[!WS "8"!][!IF "(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/Allow2CustomCsmStartPreprocess) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:654:IF200 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:654:ELSE201 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE[!ENDIF!], /*TRUE if the Custom Preprocessing before the CsmStart is expected (eg.: DER Key encoding )*/
[!WS "4"!]},
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:656:DUMMYELSE202 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "number($ProgCsmHashJobIndex) != 255"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:657:IF203 osc_PROG main ', $project))"!][!ENDSELECT!]
[!WS "4"!]{
[!WS "8"!][!"(as:modconf('Prog')/Security/ProgCsmReferences/HashVerification/BS_size)"!]U, /*Size of the Data Block Slicing*/
[!WS "8"!][!"(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/HashVerification/ProgCsmHashConfigId)/CsmJobId)"!]U, /*Corresponding Csm Job ID*/
[!WS "8"!]&PROG_CsmCheckResult, /*Callback handling API for the configured Algo*/
[!WS "8"!]0U, /*KeyID is not applicable for Hash jobs*/
[!WS "8"!]0U, /*KeyElementID is not applicable for Hash jobs*/
[!WS "8"!]0U, /*KeyLength is not applicable for Hash jobs*/
[!WS "8"!][!IF "(as:modconf('Prog')/Security/ProgCsmReferences/HashVerification/Allow2Cancel_OngoingJobs) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:665:IF204 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:665:ELSE205 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE[!ENDIF!], /*Allow cancellation of ongoing Csm Job? */
[!WS "8"!]PROG_FALSE, /*Allow keyset is not applicable for Hash job*/
[!WS "8"!]PROG_FALSE, /*Custom Preprocessing is not needed for Hash jobs*/
[!WS "4"!]},
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:669:DUMMYELSE206 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "number($ProgCsmSecureJobIndex) != 255"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:670:IF207 osc_PROG main ', $project))"!][!ENDSELECT!]
[!WS "4"!]{
[!WS "8"!][!"(as:modconf('Prog')/Security/BS_size)"!]U, /*Size of the Data Block Slicing*/
[!WS "8"!][!"(as:ref(as:modconf('Prog')/Security/ProgCsmSecureConfigId)/CsmJobId)"!]U, /*Corresponding Csm Job ID*/
[!WS "8"!]&PROG_CsmCheckResult, /*Callback handling API for the configured Algo*/
[!WS "8"!][!IF "(as:modconf('Prog')/Security/Allow2SetCryptoKey) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:675:IF208 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_CSM_SECURE_KEYID[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:675:ELSE209 osc_PROG main ', $project))"!][!ENDSELECT!]0U[!ENDIF!], /*KeyID assigned by Crypto Driver*/
[!WS "8"!][!IF "(as:modconf('Prog')/Security/Allow2SetCryptoKey) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:676:IF210 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_CRYPTO_SECURE_KEYELEID[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:676:ELSE211 osc_PROG main ', $project))"!][!ENDSELECT!]0U[!ENDIF!], /*KeyElementID assigned by the Crypto Driver*/
[!WS "8"!][!IF "(as:modconf('Prog')/Security/Allow2SetCryptoKey) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:677:IF212 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_CRYPTO_SECURE_KEYSIZE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:677:ELSE213 osc_PROG main ', $project))"!][!ENDSELECT!]0U[!ENDIF!], /*KeyLength stored in the Crypto Driver*/
[!WS "8"!][!IF "(as:modconf('Prog')/Security/Allow2Cancel_OngoingJobs) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:678:IF214 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:678:ELSE215 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE[!ENDIF!], /*Allow cancellation of ongoing Csm Job? */
[!WS "8"!][!IF "(as:modconf('Prog')/Security/Allow2SetCryptoKey) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:679:IF216 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:679:ELSE217 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE[!ENDIF!], /*Enable to set the key and the keystatus in the Crypto driver*/
[!WS "8"!][!IF "(as:modconf('Prog')/Security/Allow2CustomCsmStartPreprocess) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:680:IF218 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:680:ELSE219 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE[!ENDIF!], /*TRUE if the Custom Preprocessing before the CsmStart is expected (eg.: DER Key encoding )*/
[!WS "4"!]},
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:682:DUMMYELSE220 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "number($ProgCsmDecryptionJobIndex) != 255"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:683:IF221 osc_PROG main ', $project))"!][!ENDSELECT!]
[!WS "4"!]{
[!WS "8"!]0U, /* Block Slicing is not very effective for Streaming type jobs, hence not supported for Decryption */
[!WS "8"!][!"(as:ref(as:modconf('Prog')/Decryption/ProgCsmDecryptionConfigId)/CsmJobId)"!]U, /*Corresponding Csm Job ID*/
[!WS "8"!]&PROG_CsmDecryptionCheckResult, /*Callback handling API for the configured Algo*/
[!WS "8"!][!IF "(as:modconf('Prog')/Decryption/Allow2SetCryptoKey) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:688:IF222 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_CSM_DECRYPTION_KEYID[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:688:ELSE223 osc_PROG main ', $project))"!][!ENDSELECT!]0U[!ENDIF!], /*KeyID assigned by Crypto Driver*/
[!WS "8"!][!IF "(as:modconf('Prog')/Decryption/Allow2SetCryptoKey) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:689:IF224 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_CRYPTO_DECRYPTION_KEYELEID[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:689:ELSE225 osc_PROG main ', $project))"!][!ENDSELECT!]0U[!ENDIF!], /*KeyElementID assigned by the Crypto Driver*/
[!WS "8"!][!IF "(as:modconf('Prog')/Decryption/Allow2SetCryptoKey) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:690:IF226 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_CRYPTO_DECRYPTION_KEYSIZE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:690:ELSE227 osc_PROG main ', $project))"!][!ENDSELECT!]0U[!ENDIF!], /*KeyLength stored in the Crypto Driver*/
[!WS "8"!][!IF "(as:modconf('Prog')/Decryption/Allow2Cancel_OngoingJobs) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:691:IF228 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:691:ELSE229 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE[!ENDIF!], /*Allow cancellation of ongoing Csm Job? */
[!WS "8"!][!IF "(as:modconf('Prog')/Decryption/Allow2SetCryptoKey) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:692:IF230 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:692:ELSE231 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE[!ENDIF!], /*Enable to set the key and the keystatus in the Crypto driver*/
[!WS "8"!][!IF "(as:modconf('Prog')/Decryption/Allow2CustomCsmStartPreprocess) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:693:IF232 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TRUE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:693:ELSE233 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_FALSE[!ENDIF!], /*TRUE if the Custom Preprocessing before the CsmStart is expected (eg.: DER Key encoding )*/
[!WS "4"!]}
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:695:DUMMYELSE234 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
};
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:697:DUMMYELSE235 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/src/PROG_Cfg.c:698:DUMMYELSE236 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

