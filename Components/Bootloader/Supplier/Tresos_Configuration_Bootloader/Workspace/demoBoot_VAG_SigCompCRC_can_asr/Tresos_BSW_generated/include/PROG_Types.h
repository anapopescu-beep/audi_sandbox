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
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.48.0 BL3              */
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


#ifndef PROG_TYPES_H
#define PROG_TYPES_H
#include<ComStack_Cfg.h>

#include <Std_Types.h>          /* AUTOSAR standard types */


#define PROG_MIN_VAL_TO_WRITE            8U














 
/* Block Identifier */
#define PROG_LOGICAL_BLOCK_VALUE_INIT    3  
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


typedef u32 tProgCompleteStatus;
typedef tProgCompleteStatus (*ptCompleteCompatibleCallOut)(void);


/* Type of algorithm used for programming verification */
typedef u8 tProgVerifAlgo;
#define PROG_VERIFY_CRC         0x00U
#define PROG_VERIFY_SIGNATURE   0x01U
#define PROG_VERIFY_HASH        0x02U

typedef struct
{
    u32 ulAdd; /*Address to read data*/
    u32 ulCnt; /*Number of data get to compute CRC */
    u32 ulVal; /* CRC32 value */
    tProgVerifAlgo ubAlgo;
    u8  ubLogicalBlockId;
}tProgVerificationInfo;


typedef struct
{
    u32  ulStartAddress;   /*Start address of the segment*/
    u32  ulSize;           /*Size of the segment */
    u8  ubLogicalSegmentId;    /*Identifier for the logical segment*/
    u8  ubLogicalBlockId;      /*Identifier for the logical block*/
    u8   ubSegmentId;      /*Identifier of the segment in segment configuration array */
    u8   ubSegmentNbr;     /*Remaining number of segment in the current block*/
}tSegmentType;


#define PROG_MEMORY_NB 1U
#define PROG_SEGMENT_NB 3U


#define PROG_MAX_RD_PER_BLOCK   1U
typedef struct
{
    u8 ubSegNbr;
    tSegmentType astSeg[PROG_MAX_RD_PER_BLOCK];
    u8 ubSegListCrcIndex;
}tSegmentListType;
typedef struct
{
    tProgAddressType         ulStartAddress;
    tProgAddressType         ulEndAddress;
    tProgAddressType         ulEraseStartAddress;
    tProgAddressType         ulEraseEndAddress;
    tProgMemIdx              ubMemoryIdx;
    tProgAccessType          eSegAccessType;
    tProgPartitionType       ePartitionType;
    u8                       ubBlockIndex;
}tCfgSegmentType;

typedef struct
{
    tProgMemType             eMemoryType;
    tProgMemMode             eMemoryMode;
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
}tProg_Block;


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
    u32 ulTotalDecompDataWrite;
    u8 ubBlockSequenceCounter;
    u8 ubRDReceived;
    u8 ubCompRequired;
}tReprogInfo;


typedef struct
{
    u8 * pubDecompData; /*Pointer to buffer in COMP containing data to write*/
    u32 ulAddressToWrite;
    u32 ulDataToBeWritten; /* Total number of data received */
    u32 ulWrittenData; /* Total number of data written */
    u32 ulWriteLength; /* Number of data written at last write */
    u32 ulInDecompDataLength;
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





typedef void (*tProgCsmNotification)(u8 eCsmStatus);
#endif /* PROG_TYPES_H */
