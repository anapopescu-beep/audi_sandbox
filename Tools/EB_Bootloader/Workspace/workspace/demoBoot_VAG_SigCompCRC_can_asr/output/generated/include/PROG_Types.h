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
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.14.0 BL-3.X              */
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

#include <Std_Types.h>          /* AUTOSAR standard types */



#define PROG_MIN_VAL_TO_WRITE            8U

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

#define PROG_E_RFS_DRIVER_FAIL           0x05U
#define PROG_E_RFS_VERSION_FAIL          0x06U

typedef u8 tProgResCause;
#define PROG_RESET_CAUSE_ER              0x00U
#define PROG_RESET_CAUSE_DSC01           0x01U
#define PROG_RESET_CAUSE_DSC02           0x02U
#define PROG_RESET_CAUSE_S3_TIMEOUT      0x03U
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

typedef u8 tProgDownloadType;
#define PROG_DOWNLOAD_BY_ADDR            0x01U
#define PROG_DOWNLOAD_BY_LOGICAL_BLOCK   0x02U
#define PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT   0x03U

/* Size of the maximum length of the answer to Check Memory request */
/* between the Implementation 40,50 and 60 */
#define PROG_MAX_LENGTH_CHECKMEMORY_ANSWER 6U




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


#define PROG_SEGMENT_NB 2U
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
    u16 uwLength;    /* Length of request/response */
    u8 ubDiagStatus; /* Status of the request management */
}tDiagMessageInfo;

typedef struct
{
    u8 aubData[PROG_MAX_LENGTH_CHECKMEMORY_ANSWER];    /* Contains data of the answer */
    u16 uwLength;    /* Length of request/response */
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
    u32 ulBufferedSizeOfData;
    u8 eResponsePending;
    u8 eBufferProcessing;
}tMultipleBuffReprogInfo;

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
    u16 uwOldDataLength;
    u16 uwNewDataLength;
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
}tWfSuccess;

typedef u8 tProgCohChkResult;
#define PROG_E_COHCHK_CORRECT             0x00U
#define PROG_E_COHCHK_INCORRECT           0x01U
#define PROG_E_COHCHK_INCORRECT_SW_HW     0x02U
#define PROG_E_COHCHK_INCORRECT_SW_SW     0x03U
#define PROG_E_COHCHK_INCORRECT_OTHER     0x04U


typedef struct
{
    u16 Length;    /* Length of request */
    u8 * Data;    /* Pointer to Tp buffer use for reception*/
    u8 Event;  /* Stored event */
}tEventInfo;

#endif /* PROG_TYPES_H */
