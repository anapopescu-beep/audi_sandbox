/*********************************************************************************/
/*                                                                               */
/*                                BOOT Layers                                    */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                                 PROG configuration                            */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file PROG_Types.h                    */
/*%%  |                             |  %%  \brief PROG layer include plugin file */
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


[!AUTOSPACING!]
#ifndef PROG_TYPES_H
#define PROG_TYPES_H
#include<ComStack_Cfg.h>

#include <Std_Types.h>          /* AUTOSAR standard types */
[!IF "as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='SBL_WITH_EB_FRAMEWORK'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:34:IF1 osc_PROG main ', $project))"!][!ENDSELECT!]
#include "fblFrameworkPublicApi.h"
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:36:DUMMYELSE2 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
 [!IF "node:exists(as:modconf('ProgJLR'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:37:IF3 osc_PROG main ', $project))"!][!ENDSELECT!]
 [!IF "node:exists(as:modconf('Cry'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:38:IF4 osc_PROG main ', $project))"!][!ENDSELECT!]
#include "Cry_SHA_Common.h"
  [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:40:DUMMYELSE5 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
   [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:41:DUMMYELSE6 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!VAR "SEGMENT_MAX"="num:dectoint(count(Segments/*))"!]
[!VAR "NBR_PROT_CAL"="0"!]
[!FOR "SEGMENT_IDX" = "1" TO "$SEGMENT_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:44:FOR7 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "'PROG_PROT_CALIBRATION_PARTITION' = as:modconf('Prog')/Segments/*[number($SEGMENT_IDX)]/Partition_Type"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:45:IF8 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!VAR "NBR_PROT_CAL" = "num:dectoint($NBR_PROT_CAL) + 1"!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:47:DUMMYELSE9 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ENDFOR!]


[!VAR "MIN_VAL_TO_WRITE_FOR_FLASH" = "0"!]
[!VAR "MIN_VAL_TO_WRITE_FOR_FLASH_EXT" = "0"!]
[!VAR "MIN_VAL_TO_WRITE_FOR_RAM" = "0"!]
[!VAR "MIN_VAL_TO_WRITE_FOR_CUSTOM_MEM" = "0"!]
[!VAR "MIN_VAL_TO_WRITE_FOR_ALL_MEMORIES" = "num:dectoint("0")"!]
[!LOOP "Segments/*"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:56:LOOP10 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!VAR "Memory_Type" = "node:ref(Memory)/Memory_Type"!]
    [!IF "$Memory_Type = 'FLASH'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:58:IF11 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!IF "(node:exists(as:modconf('Flash')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:59:IF12 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "MEMORY_MODE_FLASH" = "node:ref(Memory)/Memory_Mode"!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:61:DUMMYELSE13 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!VAR "MIN_VAL_TO_WRITE_FOR_FLASH"="node:ref(Memory)/Min_Value_To_Write"!]
        [!IF "$MIN_VAL_TO_WRITE_FOR_FLASH > $MIN_VAL_TO_WRITE_FOR_ALL_MEMORIES"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:63:IF14 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "MIN_VAL_TO_WRITE_FOR_ALL_MEMORIES" = "$MIN_VAL_TO_WRITE_FOR_FLASH"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:65:DUMMYELSE15 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ELSEIF "$Memory_Type = 'FLASH_EXT'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:66:ELSEIF16 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!IF "(node:exists(as:modconf('Flash')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:67:IF17 osc_PROG main ', $project))"!][!ENDSELECT!]
           [!VAR "MEMORY_MODE_FLASH_EXT" = "node:ref(Memory)/Memory_Mode"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:69:DUMMYELSE18 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!VAR "MIN_VAL_TO_WRITE_FOR_FLASH_EXT"="node:ref(Memory)/Min_Value_To_Write"!]
        [!IF "$MIN_VAL_TO_WRITE_FOR_FLASH_EXT > $MIN_VAL_TO_WRITE_FOR_ALL_MEMORIES"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:71:IF19 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "MIN_VAL_TO_WRITE_FOR_ALL_MEMORIES" = "$MIN_VAL_TO_WRITE_FOR_FLASH_EXT"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:73:DUMMYELSE20 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ELSEIF "$Memory_Type = 'RAM'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:74:ELSEIF21 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!IF "not(node:exists(as:modconf('ReProgMemM')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:75:IF22 osc_PROG main ', $project))"!][!ENDSELECT!]
         [!VAR "MEMORY_MODE_RAM" = "node:ref(Memory)/Memory_Mode"!]
		[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:77:DUMMYELSE23 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!VAR "MIN_VAL_TO_WRITE_FOR_RAM"="node:ref(Memory)/Min_Value_To_Write"!]
        [!IF "$MIN_VAL_TO_WRITE_FOR_RAM > $MIN_VAL_TO_WRITE_FOR_ALL_MEMORIES"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:79:IF24 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "MIN_VAL_TO_WRITE_FOR_ALL_MEMORIES" = "$MIN_VAL_TO_WRITE_FOR_RAM"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:81:DUMMYELSE25 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ELSEIF "$Memory_Type = 'CUSTOM'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:82:ELSEIF26 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!IF "(node:exists(as:modconf('Flash')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:83:IF27 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "MEMORY_MODE_CUSTOM_MEM" = "node:ref(Memory)/Memory_Mode"!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:85:DUMMYELSE28 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!VAR "MIN_VAL_TO_WRITE_FOR_CUSTOM_MEM"="node:ref(Memory)/Min_Value_To_Write"!]
        [!IF "$MIN_VAL_TO_WRITE_FOR_CUSTOM_MEM > $MIN_VAL_TO_WRITE_FOR_ALL_MEMORIES"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:87:IF29 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "MIN_VAL_TO_WRITE_FOR_ALL_MEMORIES" = "$MIN_VAL_TO_WRITE_FOR_CUSTOM_MEM"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:89:DUMMYELSE30 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:90:DUMMYELSE31 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ENDLOOP!]
[!IF "node:exists(as:modconf('CryIf'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:92:IF32 osc_PROG main ', $project))"!][!ENDSELECT!]
/* Below are the Csm ASR v4.3 depreciated typedefs that are needed for the PROG module */
typedef u8 Csm_ReturnType;
typedef u8 Csm_VerifyResultType;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:96:DUMMYELSE33 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
#define PROG_MIN_VAL_TO_WRITE            [!"$MIN_VAL_TO_WRITE_FOR_ALL_MEMORIES"!]U
[!IF "(node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgOEMInd')) or node:exists(as:modconf('ProgDAG')) or node:exists(as:modconf('ProgPSA')) or ((node:exists(as:modconf('ProgFCA'))) and (as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:98:IF34 osc_PROG main ', $project))"!][!ENDSELECT!]
[!VAR "BLOCK_IDX"="1"!]
[!VAR "BLOCK_MAX"="num:dectoint(count(Blocks/*))"!]
[!VAR "MAX_IDX"="0"!]
[!VAR "BLOCK_ID_FOUND"="0"!]
[!VAR "BLOCK_IDENTIFIER_VALUE"="0"!]

[!FOR "BLOCK_IDENTIFIER_VALUE" = "0" TO "65534"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:105:FOR35 osc_PROG main ', $project))"!][!ENDSELECT!]
[!VAR "BLOCK_ID_FOUND"="0"!]
[!FOR "BLOCK_IDX" = "1" TO "$BLOCK_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:107:FOR36 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "$BLOCK_IDENTIFIER_VALUE = num:hextoint(Blocks/*[number($BLOCK_IDX)]/Block_Identifier)"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:108:IF37 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!VAR "BLOCK_ID_FOUND" = "1"!]
    [!BREAK!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:111:DUMMYELSE38 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!ENDFOR!]

[!IF "($BLOCK_ID_FOUND = 0)"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:115:IF39 osc_PROG main ', $project))"!][!ENDSELECT!]
[!BREAK!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:117:DUMMYELSE40 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!ENDFOR!]
 
/* Block Identifier */
#define PROG_LOGICAL_BLOCK_VALUE_INIT    [!"$BLOCK_IDENTIFIER_VALUE"!]  
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:123:DUMMYELSE41 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
/* PROG boolean type */
#define PROG_FALSE                       0U
#define PROG_TRUE                        1U
typedef u8 tProgBoolean;

typedef u8 tProgStatus;
#define PROG_E_OK                        0x00U
#define PROG_E_NOT_OK                    0x01U
#define PROG_E_BUSY                      0x02U
#define PROG_E_CHECK_FAILED              0x03U
#define PROG_E_BYPASS                    0x04U
[!IF "node:exists(as:modconf('ProgVAG')) and (VAG/Downgrade_Protection = 'true')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:135:IF42 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_E_RFS_DRIVER_FAIL           0x05U
#define PROG_E_RFS_VERSION_FAIL          0x06U
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:138:DUMMYELSE43 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
#define PROG_E_NOT_BUSY                  0x80U
#define PROG_E_TXCONF_OK                 0x40U

typedef u8 tProgResCause;
#define PROG_RESET_CAUSE_ER              0x00U
#define PROG_RESET_CAUSE_DSC01           0x01U
#define PROG_RESET_CAUSE_DSC02           0x02U
#define PROG_RESET_CAUSE_S3_TIMEOUT      0x03U
#define PROG_RESET_CAUSE_SBLACTIVEFAIL   0x04U
#define PROG_RESET_CAUSE_BLU             0x05U
typedef u8  tProgMemType;
#define PROG_MEM_TYPE_INIT               0xFFU
#define PROG_MEM_TYPE_FLASH              0x00U
#define PROG_MEM_TYPE_EEPROM             0x01U
#define PROG_MEM_TYPE_RAM                0x02U
#define PROG_MEM_TYPE_SCRATCHPAD         0x03U
#define PROG_MEM_TYPE_FLASH_EXT          0x04U
#define PROG_MEM_TYPE_CUSTOM             0x05U
typedef u8  tProgMemIdx;
typedef u8  tProgMemMode;
#define PROG_MEMORY_SYNCHRONOUS          0x01U
#define PROG_MEMORY_ASYNCHRONOUS         0x02U
#define PROG_MEMORY_NOTUSED              0x03U

typedef u8 tProgAccessType;
#define PROG_MEM_ACCESS_TYPE_NONE        0x00U
#define PROG_MEM_ACCESS_TYPE_READ        0x01U
#define PROG_MEM_ACCESS_TYPE_WRITE       0x02U
#define PROG_MEM_ACCESS_TYPE_READ_WRITE  0x03U

typedef u32 tDataLength;
/* basic data is byte */

typedef u8 tDataBufferType;

typedef u32 tProgAddressType;

typedef u8 tOperationType;
#define PROG_MEM_OPERATION_TYPE_ERASE    0x01U
#define PROG_MEM_OPERATION_TYPE_WRITE    0x02U
#define PROG_MEM_OPERATION_TYPE_READ     0x03U

typedef u8 tProgCompTimeoutStatus;
#define PROG_COMPLETECOMPATIBLE_START    0x01U
#define PROG_COMPLETECOMPATIBLE_END      0x02U
#define PROG_COMPLETECOMPATIBLE_ERROR    0x03U

typedef u8 tProgPartitionType;
#define PROG_APPLICATION_PARTITION       0x01U
#define PROG_CALIBRATION_PARTITION       0x02U
#define PROG_PROT_CALIBRATION_PARTITION  0x03U
#define PROG_SBA_PARTITION               0x04U
#define PROG_BOOTLOADER_PARTITION        0x05U
#define PROG_FLASH_ROUTINES_PARTITION    0x06U
#define PROG_ESS_PARTITION               0x07U
#define PROG_HSM_PARTITION               0x08U
#define PROG_BLU_PARTITION               0x10U
#define PROG_BLU_APP_PARTITION           0x11U
#define PROG_BLU_CAL_PARTITION           0x12U
/* mask to combine all partitions which support BLU */
#define PROG_BLU_PARTITION_MASK          0x10U

typedef u8 tProgDownloadType;
#define PROG_DOWNLOAD_BY_ADDR            0x01U
#define PROG_DOWNLOAD_BY_LOGICAL_BLOCK   0x02U
#define PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT   0x03U

#define PROG_NO_REPROG_TYPE              0U
#define PROG_STANDARD_REPROG             1U
#define PROG_AUTHENTICATED_REPROG        2U

/* Size of the maximum length of the answer to Check Memory request */
/* between the Implementation 40,50 and 60 */
#define PROG_MAX_LENGTH_CHECKMEMORY_ANSWER  6U

#define PROG_RC_WITH_RI_LENGTH              4U


[!IF "node:exists(as:modconf('ProgGM'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:217:IF44 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "GM/PEC_Enable = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:218:IF45 osc_PROG main ', $project))"!][!ENDSELECT!]
typedef u16 tProgPECError;
#define PROG_PEC_NO_ERROR                 0x0000U
#define PROG_ERR_PARTITION_ID             0x0001U
#define PROG_ERR_SW_NOT_PRESENT           0x0002U
#define PROG_ERR_REVOKE_SW                0x0003U
#define PROG_ERR_ERASE_SW                 0x0004U
#define PROG_ERR_GET_APP_INFO             0x0005U
#define PROG_ERR_REVOKE_CAL               0x0006U
#define PROG_ERR_ERASE_CAL                0x0007U
#define PROG_ERR_GET_CAL_INFO             0x0008U
#define PROG_ERR_UPDATE_PSI               0x0009U
#define PROG_ERR_DATA_TYPE                0x000AU
#define PROG_ERR_COMPRESSION              0x000BU
#define PROG_ERR_LENGTH_EXCEEDED          0x000CU
#define PROG_ERR_MORE_DATA_EXPECTED       0x000DU
#define PROG_ERR_FLASH_WRITE              0x000EU
#define PROG_ERR_MODULE_ID                0x000FU
#define PROG_ERR_BCID                     0x0010U
#define PROG_ERR_CCID                     0x0011U
#define PROG_ERR_ECU_NAME                 0x0012U
#define PROG_ERR_ECU_ID                   0x0013U
#define PROG_ERR_SW_REGION                0x0014U
#define PROG_ERR_SIGNATURE                0x0015U
#define PROG_ERR_APP_NBID                 0x0016U
#define PROG_ERR_SUBJECT_NAME             0x0017U
#define PROG_ERR_KEY_NBID                 0x0018U
#define PROG_ERR_CERT                     0x0019U
#define PROG_ERR_CAL_REGION               0x001AU
#define PROG_ERR_MD                       0x001BU
#define PROG_ERR_ROOT_SIGNATURE           0x001CU
#define PROG_ERR_MSG_OUT_OF_SEQUENCE      0x001DU
#define PROG_ERR_UNDEFINED                0x0020U
#define PROG_ERR_PROTECTEDCAL_NOT_DEFINED 0x0035U
#define PROG_ERR_PER_DATA_TX_NOT_ALLOW    0x0037U

[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:254:DUMMYELSE46 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

typedef u8 tProgSigBypass;
#define PROG_ERR_SBA_ECU_NAME            0x01U
#define PROG_ERR_SBA_ECU_ID              0x02U
#define PROG_ERR_SBA_SIGNATURE           0x04U
#define PROG_ERR_SBA_CERT                0x08U
#define PROG_SBA_OK                      0x80U

typedef u8 tProgPsiValue;
#define PROG_PSI_PROGRAMMED              0x00U
#define PROG_PSI_REVOKED                 0x01U
#define PROG_PSI_INVALID                 0x02U

#define PROG_ECU_ID_SIZE                 16U
#define PROG_ECU_NAME_SIZE               8U
#define PROG_SUBJECT_NAME_SIZE           16U
#define PROG_BOOT_NB_MODULE_SIZE         1U
#define PROG_BOOT_MODULE_ID_SIZE         1U
#define PROG_BOOT_PART_NUMBER_SIZE       4U
#define PROG_BOOT_DLS_SIZE               2U
#define PROG_BOOT_PROT_CALIB_NUMBER_SIZE        1U
#define PROG_BOOT_PROT_CALIB_PARTITION_ID_SIZE  1U
#define PROG_BOOT_MAX_PROT_PARTITIONS           [!"num:dectoint($NBR_PROT_CAL)"!]U
#define PROG_BOOT_PRIMARY_MICRO_ID       0x47U
#define PROG_BOOT_NUMBER_OF_MODULES      0x01U
#define PROG_MAX_PARTITION               [!"num:dectoint(GM/MAX_PARTITION)"!]U
#define PROG_MAX_REGION_ALLOWED          [!"num:dectoint(GM/MAX_REGION_ALLOWED)"!]U
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:282:DUMMYELSE47 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "(as:modconf('ProgVAG')) or (as:modconf('ProgOEMInd')) and (as:modconf('Prog')/Decryption/Enable_Csm_Decryption='true')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:284:IF48 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CIPHERED_MIN_DATA_SIZE        256
#define PROG_DECRYPT_BUFFER_SIZE           4112U

typedef u8 tProgEncryptOperation;
#define PROG_NO_OPERATION_IN_PROGRESS      0x00U
#define PROG_DECRYPTION_IN_PROGRESS        0xAAU

typedef struct
{
  u8  aubCryptoBuffer[PROG_DECRYPT_BUFFER_SIZE];          /* Contains the decrpted data */
  u32 ulNextWritePosition;                                /* Position from where next writing shall be start */
  u32 ulCryptoBufferSize;                                 /* Size of decrypted data */
  u32 ulEncryptDataSize;                                  /* Size of data to be decrypted */
  u32 ulTotDecryptedWrittenSize;                          /* Stores the total length of decrypted and written data */
  u16 uwRemainNotWrittenLength;                           /* Stores the length of decrypted but not written data */
  tProgEncryptOperation  ubOperationInProgress;           /* Defines operation in progress: encryption, decryption or none of them */
}tCryptoData;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:302:DUMMYELSE49 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "as:modconf('ProgVCC')/General/PROG_VCC_VARIANT='PBL' or as:modconf('ProgVCC')/General/PROG_VCC_VARIANT='SBL'
    or as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL' or as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='SBL'
    or as:modconf('ProgFord')/General/PROG_FORD_VARIANT='PBL' or as:modconf('ProgFord')/General/PROG_FORD_VARIANT='SBL'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:305:IF50 osc_PROG main ', $project))"!][!ENDSELECT!]
typedef struct s_secondary_bootloader_interface
{
    u32 software_version;          /* meta data */
    u8  referenceString[16];       /* reference string of the SBL */
    void *ptr_function[25];        /* function pointer list */
    u32 ulSBLValidityFlagAddr;     /* SBL validity flag address */
}t_secondary_bootloader_interface;
[!IF "as:modconf('ProgVCC')/General/PROG_VCC_VARIANT='PBL' or as:modconf('ProgVCC')/General/PROG_VCC_VARIANT='SBL'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:313:IF51 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_DIGEST_LENGTH     32U    /* digest length for VCC and FORD */
 typedef struct
 {
    u32 ulStartAddress;          /* start address of the hashed data */
    u32 ulLength;       /* length of the hashed data */
    u8  aubDigest[PROG_DIGEST_LENGTH];        /* function pointer list */
 }tDataBlockType;
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:321:DUMMYELSE52 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:322:DUMMYELSE53 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('ProgFord'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:324:IF54 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "(as:modconf('ProgFord')/General/PROG_FORD_VARIANT='PBL') or (as:modconf('ProgFord')/General/PROG_FORD_VARIANT='SBL')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:325:IF55 osc_PROG main ', $project))"!][!ENDSELECT!]
 [!IF "node:exists(as:modconf('Csm'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:326:IF56 osc_PROG main ', $project))"!][!ENDSELECT!]
 [!IF "node:exists(as:modconf('CryIf'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:327:IF57 osc_PROG main ', $project))"!][!ENDSELECT!]
  [!VAR "DigestLength" = "(as:ref(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/HashVerification/ProgCsmHashConfigId)/CsmJobPrimitiveRef)/CsmHash/*/CsmHashResultLength)"!]
/* Digest Length shall be configured based on the value provided in the Csm job conf paramater- CsmHashResultLength */
#define PROG_DIGEST_LENGTH                                 [!WS "31"!][!"$DigestLength"!]U
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:331:ELSE58 osc_PROG main ', $project))"!][!ENDSELECT!]
   [!VAR "AlgoType" 	= "(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/HashVerification/ProgCsmHashConfigId)/CsmHashPrimitiveName)"!]
#ifndef CRY_[!"$AlgoType"!]_WORD_SIZE
#define CRY_[!"$AlgoType"!]_WORD_SIZE                      [!WS "9"!]32U
#endif
#define PROG_DIGEST_LENGTH                               CRY_[!"$AlgoType"!]_WORD_SIZE
 [!ENDIF!]
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:338:DUMMYELSE59 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
  [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:339:DUMMYELSE60 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
#ifndef PROG_DIGEST_LENGTH
#define PROG_DIGEST_LENGTH                                   32U
#endif
 typedef struct
 {
    u8  aubDigest[PROG_DIGEST_LENGTH];        /* function pointer list */
 }tDataBlockType;
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:347:DUMMYELSE61 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

typedef u32 tProgCompleteStatus;
[!IF "as:modconf('ProgVCC')/General/PROG_VCC_VARIANT='PBL'
    or as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL_WITH_EB_FRAMEWORK'
    or as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL'
	or as:modconf('ProgFord')/General/PROG_FORD_VARIANT='PBL'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:353:IF62 osc_PROG main ', $project))"!][!ENDSELECT!]

	[!IF "node:exists(as:modconf('EB')) and (as:modconf('EB')/Communication/EnableMultipleTpConnection='true')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:355:IF63 osc_PROG main ', $project))"!][!ENDSELECT!]
typedef void (*ptSBL_StartUp_Code)(u32 ulInfoSBL, u8 ubRxPduId);
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:357:ELSE64 osc_PROG main ', $project))"!][!ENDSELECT!]
typedef void (*ptSBL_StartUp_Code)(u32 ulInfoSBL);
    [!ENDIF!]
typedef void (*ptAPPL_START_ADDR)(void);
[!ELSEIF "as:modconf('ProgVCC')/General/PROG_VCC_VARIANT=''or as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='OneLevelBL'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:361:ELSEIF65 osc_PROG main ', $project))"!][!ENDSELECT!]
 typedef void (*ptAPPL_START_ADDR)(void);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:363:DUMMYELSE66 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
typedef tProgCompleteStatus (*ptCompleteCompatibleCallOut)(void);

[!IF "as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL_WITH_EB_FRAMEWORK' or as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='SBL_WITH_EB_FRAMEWORK'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:366:IF67 osc_PROG main ', $project))"!][!ENDSELECT!]
/* Function pointer type definition for ZF framework */
typedef u8 (*tpulVerifySectionCrc)(void);
typedef u8 (*tpulinvalidateSection)(u32);
typedef u8 (*tpulisValidApplication)(void);
typedef void* (*tpulGetAddress)(u8,u32);
[!IF "as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='SBL_WITH_EB_FRAMEWORK'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:372:IF68 osc_PROG main ', $project))"!][!ENDSELECT!]
/* Function pointer for skipPage Api */
typedef u8 (*tpulskipPage)(u32*);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:375:DUMMYELSE69 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:376:DUMMYELSE70 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

/* Type of algorithm used for programming verification */
typedef u8 tProgVerifAlgo;
#define PROG_VERIFY_CRC         0x00U
#define PROG_VERIFY_SIGNATURE   0x01U
#define PROG_VERIFY_HASH        0x02U

typedef struct
{
    u32 ulAdd; /*Address to read data*/
    u32 ulCnt; /*Number of data get to compute CRC */
[!IF "node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgDAG')) or OemInd/Checksum_Algo='CRC32 Ethernet' or OemInd/Checksum_Algo='CRC32 InternationalStandard'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:388:IF71 osc_PROG main ', $project))"!][!ENDSELECT!]
    u32 ulVal; /* CRC32 value */
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:390:ELSE72 osc_PROG main ', $project))"!][!ENDSELECT!]
    u16 uwVal; /* CRC16 value */
[!ENDIF!]
    tProgVerifAlgo ubAlgo;
[!IF "(node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High') or node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgDAG'))  or node:exists(as:modconf('ProgVCC')) or node:exists(as:modconf('ProgFord')) or (node:exists(as:modconf('ProgOEMInd')) and OemInd/Erase_Mode = 'LogicalBlock') or (node:exists(as:modconf('ProgOEMInd')) and OemInd/Erase_Mode = 'All')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:394:IF73 osc_PROG main ', $project))"!][!ENDSELECT!]
    u8  ubLogicalBlockId;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:396:DUMMYELSE74 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
}tProgVerificationInfo;

[!IF "node:exists(as:modconf('ProgGM'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:399:IF75 osc_PROG main ', $project))"!][!ENDSELECT!]
typedef struct
{
    u32 ulAddress;
    u32 ulSize;
}tRegiontype;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:405:DUMMYELSE76 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

typedef struct
{
    u32  ulStartAddress;   /*Start address of the segment*/
    u32  ulSize;           /*Size of the segment */
[!IF "node:exists(as:modconf('ProgGM'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:411:IF77 osc_PROG main ', $project))"!][!ENDSELECT!]
    tRegiontype astRegion[PROG_MAX_REGION_ALLOWED];
    u8   *pubRegionPtr;    /*Pointer to the current region*/
    u16  uwModuleId;       /* Current downloaded module ID */
    u8   ubRegionNbr;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:416:DUMMYELSE78 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High')
 or node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgDAG')) or node:exists(as:modconf('ProgVCC'))
    or (node:exists(as:modconf('ProgOEMInd')) and OemInd/Erase_Mode = 'All')
    or (node:exists(as:modconf('ProgOEMInd')) and OemInd/Erase_Mode = 'LogicalBlock')
    or (node:exists(as:modconf('ProgPSA')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:421:IF79 osc_PROG main ', $project))"!][!ENDSELECT!]
    u8  ubLogicalSegmentId;    /*Identifier for the logical segment*/
    u8  ubLogicalBlockId;      /*Identifier for the logical block*/
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:424:DUMMYELSE80 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    u8   ubSegmentId;      /*Identifier of the segment in segment configuration array */
    u8   ubSegmentNbr;     /*Remaining number of segment in the current block*/
}tSegmentType;

[!IF "(node:exists(as:modconf('ReProgMemM')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:429:IF81 osc_PROG main ', $project))"!][!ENDSELECT!]
[!VAR "MEMORY_MAX"="num:dectoint(count(as:modconf('ReProgMemM')/MemoryConfig/Memory/*))"!]
[!ELSEIF "node:exists(as:modconf('Flash')) or (node:exists(as:modconf('ProgFord')) and as:modconf('ProgFord')/General/PROG_FORD_VARIANT='PBL') or (node:exists(as:modconf('ProgJLR')) and as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL') or (node:exists(as:modconf('ProgVCC')) and as:modconf('ProgVCC')/General/PROG_VCC_VARIANT='PBL')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:431:ELSEIF82 osc_PROG main ', $project))"!][!ENDSELECT!]
[!VAR "MEMORY_MAX"="num:dectoint(count(Memory/*))"!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:433:DUMMYELSE83 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
#define PROG_MEMORY_NB [!"$MEMORY_MAX"!]U
[!IF "node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgVCC')) or node:exists(as:modconf('ProgFord')) or node:exists(as:modconf('ProgDAG')) or node:exists(as:modconf('ProgOEMInd'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:435:IF84 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SEGMENT_NB [!"$SEGMENT_MAX"!]U
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:437:DUMMYELSE85 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgVCC')) or node:exists(as:modconf('ProgFord')) or node:exists(as:modconf('ProgDAG')) or node:exists(as:modconf('ProgOEMInd'))
    or (node:exists(as:modconf('ProgFCA')) and (as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High') and (as:modconf('Prog')/DownloadVerification/FCA_Reprogramming = 'Standard'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:440:IF86 osc_PROG main ', $project))"!][!ENDSELECT!]

#define PROG_MAX_RD_PER_BLOCK   [!"num:dectoint(DownloadVerification/MaxNumberOfRDPerBlock)"!]U
typedef struct
{
    u8 ubSegNbr;
    tSegmentType astSeg[PROG_MAX_RD_PER_BLOCK];
    u8 ubSegListCrcIndex;
}tSegmentListType;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:449:DUMMYELSE87 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
 [!VAR "SIGNATUREVERIFCATIONENABLED"="'false'"!]
 [!IF "(node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_Mid')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:451:IF88 osc_PROG main ', $project))"!][!ENDSELECT!]
  [!FOR "SEGMENT_IDX" = "1" TO "$SEGMENT_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:452:FOR89 osc_PROG main ', $project))"!][!ENDSELECT!]
  [!IF "Segments/*[number($SEGMENT_IDX)]/SignatureVerification = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:453:IF90 osc_PROG main ', $project))"!][!ENDSELECT!]
   [!VAR "SIGNATUREVERIFCATIONENABLED"="'true'"!]
   [!VAR "SEGMENT_IDX"="$SEGMENT_MAX"!]
  [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:456:DUMMYELSE91 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
  [!ENDFOR!]
  [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:458:DUMMYELSE92 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
typedef struct
{
    tProgAddressType         ulStartAddress;
    tProgAddressType         ulEndAddress;
    tProgAddressType         ulEraseStartAddress;
    tProgAddressType         ulEraseEndAddress;
    tProgMemIdx              ubMemoryIdx;
    tProgAccessType          eSegAccessType;
[!IF "node:exists(as:modconf('ProgGM')) or node:exists(as:modconf('ProgFCA')) or node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgDAG')) or node:exists(as:modconf('ProgOEMInd')) or node:exists(as:modconf('ProgVCC')) or node:exists(as:modconf('ProgFord'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:467:IF93 osc_PROG main ', $project))"!][!ENDSELECT!]
    tProgPartitionType       ePartitionType;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:469:DUMMYELSE94 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('ProgOEMInd'))) or (node:exists(as:modconf('ProgJLR')) and ((as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='SBL') or
      (as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='OneLevelBL')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:471:IF95 osc_PROG main ', $project))"!][!ENDSELECT!]
    tProgBoolean            eValidityCheck;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:473:DUMMYELSE96 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgDAG')) or node:exists(as:modconf('ProgVCC')) or node:exists(as:modconf('ProgFord')) or (node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High') or (node:exists(as:modconf('ProgOEMInd')) and as:modconf('Prog')/OemInd/Erase_Mode != 'Address') or node:exists(as:modconf('ProgPSA'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:474:IF97 osc_PROG main ', $project))"!][!ENDSELECT!]
    u8                       ubBlockIndex;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:476:DUMMYELSE98 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
 [!IF "(node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_Mid') and ($SIGNATUREVERIFCATIONENABLED = 'true') "!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:477:IF99 osc_PROG main ', $project))"!][!ENDSELECT!]
    tProgBoolean             eVerifySignature;
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:479:DUMMYELSE100 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
}tCfgSegmentType;

typedef struct
{
    tProgMemType             eMemoryType;
[!IF "node:exists(as:modconf('Flash'))  or (node:exists(as:modconf('ProgFord')) and as:modconf('ProgFord')/General/PROG_FORD_VARIANT='PBL') or (node:exists(as:modconf('ProgJLR')) and as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL') or (node:exists(as:modconf('ProgVCC')) and as:modconf('ProgVCC')/General/PROG_VCC_VARIANT='PBL')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:485:IF101 osc_PROG main ', $project))"!][!ENDSELECT!]
    tProgMemMode             eMemoryMode;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:487:DUMMYELSE102 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    u32                      ulMinValueToWrite;
    tProgAddressType         ulAddressOffset;
    u8                       ubEraseValue;
}tCfgMemorytType;

typedef struct
{
    u16 uwBlockIdentifier;
    u8 ubFirstSegmentId;
    u8 ubSegmentNbr;
    u16 uwProgCntrMax;
[!IF "node:exists(as:modconf('ProgFCA')) and (as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High') and (as:modconf('Prog')/DownloadVerification/FCA_Reprogramming = 'Standard')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:499:IF103 osc_PROG main ', $project))"!][!ENDSELECT!]
    tProgAddressType ulCrcAddress;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:501:DUMMYELSE104 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "((node:exists(as:modconf('ProgVAG')))and (as:modconf('Prog')/VAG/Downgrade_Protection = 'true'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:502:IF105 osc_PROG main ', $project))"!][!ENDSELECT!]
    u8 ubDwngrdProtected;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:504:DUMMYELSE106 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
}tProg_Block;

[!IF "(not((as:modconf('BM')/Security/SecureBoot/SECURE_AUTHENTICATED_BOOT = 'OFF') and (as:modconf('Prog')/Security/Secure_Checksum_computation = 'false'))) and
    (node:exists(as:modconf('ProgDAG')) or node:exists(as:modconf('ProgJLR')) or node:exists(as:modconf('ProgFCA')) or node:exists(as:modconf('ProgOEMInd')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:508:IF107 osc_PROG main ', $project))"!][!ENDSELECT!]
typedef struct
{
    u32 ulStartAddressForSecureBoot;
    u32 ulLengthForSecureBoot;
    u16 uwBlockIdentifier;
    u8  ubBlockVerifiedInSecure;
    u8  ubBlockBlockerExecution;
}tProg_BlockSecureBootInfo;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:517:DUMMYELSE108 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

typedef struct
{
    u8 * pubData;    /* Pointer to Tp buffer use for reception*/
    u8 * pubTxData;  /* Pointer to Tp buffer use for transmission*/
    PduLengthType ulLength;    /* Length of request/response */
    u8 ubDiagStatus; /* Status of the request management */
}tDiagMessageInfo;

typedef struct
{
    u8 aubData[PROG_MAX_LENGTH_CHECKMEMORY_ANSWER];    /* Contains data of the answer */
    PduLengthType ulLength;    /* Length of request/response */
    u8 ubDiagStatus; /* Status of the request management */
}tFirstCheckMemoryAnswerInfo;

typedef struct
{
    u32 ulMemorySizeExpected;
    u32 ulReceivedSizeOfData; /* Number of data received and written */
[!IF "General/Enable_Compression = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:538:IF109 osc_PROG main ', $project))"!][!ENDSELECT!]
    u32 ulTotalDecompDataWrite;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:540:DUMMYELSE110 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "node:exists(as:modconf('ProgGM'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:541:IF111 osc_PROG main ', $project))"!][!ENDSELECT!]
    u16 uwExpectedModuleId[PROG_MAX_PARTITION];
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:543:DUMMYELSE112 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    u8 ubBlockSequenceCounter;
    u8 ubRDReceived;
[!IF "General/Enable_Compression = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:546:IF113 osc_PROG main ', $project))"!][!ENDSELECT!]
    u8 ubCompRequired;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:548:DUMMYELSE114 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
}tReprogInfo;

[!IF "as:modconf('BlPduR')/General/MultipleRxBuffer = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:551:IF115 osc_PROG main ', $project))"!][!ENDSELECT!]
typedef struct
{
    u32 ulBufferedSizeOfData;
    u8 eResponsePending;
    u8 eBufferProcessing;
}tMultipleBuffReprogInfo;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:558:DUMMYELSE116 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

typedef struct
{
[!IF "General/Enable_Compression = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:562:IF117 osc_PROG main ', $project))"!][!ENDSELECT!]
    u8 * pubDecompData; /*Pointer to buffer in COMP containing data to write*/
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:564:DUMMYELSE118 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    u32 ulAddressToWrite;
    u32 ulDataToBeWritten; /* Total number of data received */
    u32 ulWrittenData; /* Total number of data written */
    u32 ulWriteLength; /* Number of data written at last write */
[!IF "General/Enable_Compression = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:569:IF119 osc_PROG main ', $project))"!][!ENDSELECT!]
    u32 ulInDecompDataLength;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:571:DUMMYELSE120 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "node:exists(as:modconf('ProgPSA'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:572:IF121 osc_PROG main ', $project))"!][!ENDSELECT!]
    u32 ulNewAddressToWrite;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:574:DUMMYELSE122 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    u8 ubTDReceived;
}tWriteInfo;


typedef struct
{
    u32 ulStartAddress;
    u32 ulMemorySize;
    u16 uwBlockIdentifier;
    u8  ubSegmentId;
    u8  ubDataFormatId;
}tRDParam;

typedef P2FUNC (void*, EBSTUBS_APPL_CODE, t_PROG_fctptr)(void) ;

typedef struct
{
    u8 aubData[PROG_MIN_VAL_TO_WRITE];
    PduLengthType ulOldDataLength;
    PduLengthType ulNewDataLength;
}tPageBuffer;

[!VAR "SEGMENT_MAX"="num:dectoint(count(Segments/*))"!]
[!VAR "SEGMENT_IDX"="1"!]
[!VAR "PROT_CALIB_IDX"="1"!]
[!IF "node:exists(as:modconf('ProgGM'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:600:IF123 osc_PROG main ', $project))"!][!ENDSELECT!]
typedef struct
{
    u16 uwBCID;
[!IF "GM/EcuId_Source = 'Tresos_Configuration'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:604:IF124 osc_PROG main ', $project))"!][!ENDSELECT!]
    u8  aubEcuId[PROG_ECU_ID_SIZE];
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:606:DUMMYELSE125 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    u8  aubEcuName[PROG_ECU_NAME_SIZE];
    u8  aubSubjectName[PROG_SUBJECT_NAME_SIZE];
    u8  aubBootPartNumber[PROG_BOOT_PART_NUMBER_SIZE];
    u8  aubBootDLS[PROG_BOOT_DLS_SIZE];
    u8  aubProtectedCalibNumber;
[!IF "$NBR_PROT_CAL > 0"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:612:IF126 osc_PROG main ', $project))"!][!ENDSELECT!]
    u8  aubProtectedCalibPartitionID[PROG_BOOT_MAX_PROT_PARTITIONS];
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:614:DUMMYELSE127 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
}tBootInfoBlock;

typedef struct
{
    u8 ubBootIntegrity;
    tProgSigBypass ubSignatureBypass;
}tBootStatus;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:622:DUMMYELSE128 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

typedef u8 tProgEraseCheckType;
#define PROG_DISABLED_ERASE_CHECK        0x00U
#define PROG_1ST_PROGRAMMING_ERASE_CHECK 0x01U
#define PROG_BLOCK_ERASE_CHECK           0x02U


typedef u8 tProgEraseStatus;
#define PROG_E_NOT_ERASED        0x00U
#define PROG_E_ERASED            0x01U



typedef struct
{
    u8 ubAppFingerprintWriten; /*Application Fingerprint writing success flag*/
    u8 ubCalFingerprintWriten; /*Calibration Fingerprint writing success flag*/
    u8 ubBluFingerprintWriten; /*Blupdater Fingerprint writing success flag*/
}tWfSuccess;

typedef u8 tProgCohChkResult;
#define PROG_E_COHCHK_CORRECT             0x00U
#define PROG_E_COHCHK_INCORRECT           0x01U
#define PROG_E_COHCHK_INCORRECT_SW_HW     0x02U
#define PROG_E_COHCHK_INCORRECT_SW_SW     0x03U
#define PROG_E_COHCHK_INCORRECT_OTHER     0x04U

[!IF "node:exists(as:modconf('Uds'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:650:IF129 osc_PROG main ', $project))"!][!ENDSELECT!]
[!VAR "COHERENCY_PRE_CHECK_USE" = "0"!]
    [!LOOP " as:modconf('Uds')/Routine_Control/*"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:652:LOOP130 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!IF "Callback = 'PROG_CoherencyPreCheck'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:653:IF131 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "COHERENCY_PRE_CHECK_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:655:DUMMYELSE132 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ENDLOOP!]
    [!IF "$COHERENCY_PRE_CHECK_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:657:IF133 osc_PROG main ', $project))"!][!ENDSELECT!]
typedef u8 tProgCohPreChkResult;
#define PROG_E_COHPRECHK_CORRECT          0x00U
#define PROG_E_COHPRECHK_INTERNAL_ERROR   0x01U
#define PROG_E_COHPRECHK_INCORRECT_HW_SW  0x02U
#define PROG_E_COHPRECHK_INCORRECT_SW_SW  0x03U
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:663:DUMMYELSE134 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:664:DUMMYELSE135 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "as:modconf('BlPduR')/General/MultipleRxBuffer = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:666:IF136 osc_PROG main ', $project))"!][!ENDSELECT!]
typedef struct
{
    PduLengthType Length;    /* Length of request */
    u8 * Data;    /* Pointer to Tp buffer use for reception*/
    u8 Event;  /* Stored event */
}tEventInfo;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:673:DUMMYELSE137 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "(node:exists(as:modconf('ProgFCA')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:675:IF138 osc_PROG main ', $project))"!][!ENDSELECT!]
typedef u8 tSignatureHandlingstatus;

#define PROG_CRCDONE                     0U
#define PROG_CRYPTOSTARTUPDATEINPROGRESS 1U
#define PROG_CRYPTOUPDATEDONE            2U
#define PROG_CRYPTOFINISHDONE            3U
#define PROG_ERASESTART                  4U
#define PROG_ERASEDONE                   5U
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:684:DUMMYELSE139 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "as:modconf('Prog')/Segments/*/Partition_Type = 'PROG_BLU_APP_PARTITION' 
   or as:modconf('Prog')/Segments/*/Partition_Type = 'PROG_BLU_CAL_PARTITION'
   or as:modconf('Prog')/Segments/*/Partition_Type = 'PROG_BLU_PARTITION'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:688:IF140 osc_PROG main ', $project))"!][!ENDSELECT!]
typedef struct
{
    u8 aubData[PROG_RC_WITH_RI_LENGTH];    /* Contains received data of the request */
    PduLengthType ulLength;    /* Length of request */
}tCheckMemoryRequestInfo;
/* Struct containing required informations to resume BLU download after ECU Reset */
typedef struct
{
    u8 ubProgSecurityLevel;                 /* Current security level */
    tCheckMemoryRequestInfo stBLUCheckMemoryRequestInfo;    /* Contains BLU Check Memory request information */
}tContextRestore;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:700:DUMMYELSE141 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

 [!IF "node:exists(as:modconf('ProgJLR'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:702:IF142 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "(as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL') or (as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='SBL') or
      (as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='OneLevelBL')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:704:IF143 osc_PROG main ', $project))"!][!ENDSELECT!]
 [!IF "node:exists(as:modconf('Csm'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:705:IF144 osc_PROG main ', $project))"!][!ENDSELECT!]
 [!IF "node:exists(as:modconf('CryIf'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:706:IF145 osc_PROG main ', $project))"!][!ENDSELECT!]
  [!VAR "DigestLength" = "(as:ref(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/HashVerification/ProgCsmHashConfigId)/CsmJobPrimitiveRef)/CsmHash/*/CsmHashResultLength)"!]
/* Digest Length shall be configured based on the value provided in the Csm job conf paramater- CsmHashResultLength */
#define PROG_DIGEST_LENGTH                                 [!WS "31"!][!"$DigestLength"!]U
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:710:ELSE146 osc_PROG main ', $project))"!][!ENDSELECT!]
   [!VAR "AlgoType" 	= "(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/HashVerification/ProgCsmHashConfigId)/CsmHashPrimitiveName)"!]
#ifndef CRY_[!"$AlgoType"!]_WORD_SIZE
#define CRY_[!"$AlgoType"!]_WORD_SIZE                      [!WS "9"!]64U
#endif
#define PROG_DIGEST_LENGTH                               CRY_[!"$AlgoType"!]_WORD_SIZE
 [!ENDIF!]
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:717:DUMMYELSE147 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
  [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:718:DUMMYELSE148 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
#ifndef PROG_DIGEST_LENGTH
#define PROG_DIGEST_LENGTH                                   64U
#endif

#ifndef PROG_VDS_SIZE
#define PROG_VDS_SIZE                                        (PROG_ERASE_ADDR_LEN + PROG_ERASE_SIZE_LEN + PROG_DIGEST_LENGTH)
#endif
 typedef struct
 {
     u32 ulBlock_StartAddress;
 	 u32 ulBlock_Length;
     u8 aubBlockDigest[PROG_DIGEST_LENGTH];
 }tVDSlayout;
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:732:DUMMYELSE149 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "node:exists(as:modconf('ProgPSA'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:733:IF150 osc_PROG main ', $project))"!][!ENDSELECT!]
typedef struct
{
    u8 ubSeedSent;[!WS "11"!]/* Indicates the right catenation of diagnostic requests needed for ECU unlocking */
    u8 ubEcuUnlock;[!WS "10"!]/* Deny or allow the handling of the programming requests (clearing and writing) */
    u8 ubTunBlank;[!WS "11"!]/* Identifies if calibration zone has been erased or not */
    u8 ubGlobalBlank;[!WS "8"!]/* Identifies if global (calibration + application) zone has been erased or not */
    u8 ubProgInit;[!WS "11"!]/* Identifies the start of the ECU reprogramming */
    u8 ubAuthorizeLog;[!WS "7"!]/* Forbid or allow the log zone writing */
    u8 ubWriteOk;[!WS "12"!]/* Identifies writing fault */
    u8 ubRDOk;[!WS "15"!]/* Indicates the right catenation of requests needed for APPLI+CALIB or CALIB writing */
    u8 ubRDLogOk;[!WS "12"!]/* Indicates the right catenation of the diagnostic requests needed for log zone writing */
    u8 ubRDKeyAppliOk;[!WS "7"!]/* Indicates the right catenation of diagnostic requests needed for APPLI_KEY writing */
    u8 ubLCBaudOk;[!WS "11"!]/* Indicates the right catenation of the diagnostic requests needed for speed modification */
    u8 ubLCProgOk;[!WS "11"!]/* Indicates the right catenation of the diagnostic requests needed for programming scheduler switching */
}tProgrammingFlags;

typedef struct
{
    u16 uwRoutineId;
    u8  ubRoutineIndexList;
}tProgRoutineResultInfo;

typedef struct
{
    u8  aubRoutineData[20U];     /* Buffer used to store received RC buffer */
    u16 uwRoutineLength;         /* Length of the RC */
}tProgRequestRoutineData;

typedef u8 tProgRequestRoutineResult;
#define PROG_REQUEST_ROUTINE_RESULT_INIT        0x00
#define PROG_REQUEST_ROUTINE_RESULT_PENDING     0x01
#define PROG_REQUEST_ROUTINE_RESULT_SUCCESS     0x02
#define PROG_REQUEST_ROUTINE_RESULT_FAIL        0x03

[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:768:DUMMYELSE151 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
typedef void (*tProgCsmNotification)(u8 eCsmStatus);
[!IF "node:exists(as:modconf('CryIf'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:770:IF152 osc_PROG main ', $project))"!][!ENDSELECT!]
typedef struct
 {
	  u32 ulBSsize; /* Size of the Data Block Slicing */
	  u32 ulCsmJobId; /* Corresponding Csm Job ID */
	  tProgCsmNotification pfuProgCsmNotification; /* Callback handling API for the configured Algo */
	  u32 ulCsmKeyID; /* KeyID assigned by Crypto Driver */
	  u32 ulCryptoElementId; /* KeyElementID assigned by the Crypto Driver */
	  u32 ulCryptoKeyLength; /* KeyLength stored in the Crypto Driver */
	  tProgBoolean eAllowJobCancellation; /* Cancel all ongoing Csm Jobs */
	  tProgBoolean eAllowKeySet; /* Enable to set the key and the keystatus in the Crypto driver */
	  tProgBoolean eAllowCustCsmPreProc; /* TRUE if the Custom Preprocessing before the CsmStart is expected (eg.: DER Key encoding )*/
 }tProgCsmJobConf;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Types.h:783:DUMMYELSE153 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
#endif /* PROG_TYPES_H */
