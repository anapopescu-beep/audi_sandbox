#ifndef APP_TYPES_H
#define APP_TYPES_H
/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------------------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
H-File Template Version: 
Template version: AEM_PROCESS_1.25.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2022-09
*******************************************************************************

Overview of the interfaces:
   This file defines the information (interfaces, definitions and data) provided
by the module APP_Prg, part of the component APP.

******************************************************************************/
/*
$Revision: 1.4 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader/Autoliv/APP/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/

/**
 * \brief  
 *      PROG_FINGERPRINT_LENGTH Value definition.
 *      
**/
#define PROG_FINGERPRINT_LENGTH               (9U)

/**
 * \brief  
 *       PROG_MAX_NBR_SEG Value definition.
 *      
**/
#define PROG_MAX_NBR_SEG                      (5U)

/**
 * \brief  
 *       PROG_BLOCK_NBR Value definition.
 *      
**/
#define PROG_BLOCK_NBR                        (3U)

/**
 * \brief  
 *       PROG_COHERENCY_OK Value definition.
 *      
**/
#define PROG_COHERENCY_OK                   (0U)

/**
 * \brief  
 *       PROG_COHERENCY_ERR_INVALID_BLOCK Value definition.
 *      
**/
#define PROG_COHERENCY_ERR_INVALID_BLOCK    (4U)

/**
 * \brief  
 *       PROG_INFO_MEMORY_STATUS Value definition.
 *      
**/
#define PROG_INFO_MEMORY_STATUS             (0x08U)

/* Define the value of ECU Programming Info */

/**
 * \brief  
 *       PROG_ECUPROGINFO_CONSISTENT Value definition.
 *      
**/
#define PROG_ECUPROGINFO_CONSISTENT     (0x40U)

/**
 * \brief  
 *       PROG_ECUPROGINFO_INCONSISTENT Value definition.
 *      
**/
#define PROG_ECUPROGINFO_INCONSISTENT   (0x44U)

/**
 * \brief  
 *       PROG_BLOCK_VALID Value definition.
 *      
**/
#define PROG_BLOCK_VALID                (0x01U)

/**
 * \brief  
 *       PROG_BLOCK_INVALID Value definition.
 *      
**/
#define PROG_BLOCK_INVALID              (0x00U)

/**
 * \brief  
 *       PROG_INFO_REPROG_STATE_ERASED_END Value definition.
 *      
**/
#define PROG_INFO_REPROG_STATE_ERASED_END   (0x20U)

/**
 * \brief  
 *       PROG_INFO_REPROG_STATE_REPROG_START Value definition.
 *      
**/
#define PROG_INFO_REPROG_STATE_REPROG_START (0x30U)

/**
 * \brief  
 *       PROG_INFO_REPROG_STATE_MASK Value definition.
 *      
**/
#define PROG_INFO_REPROG_STATE_MASK         (0x70U)
/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/
/**
 * \brief  
 *       Type Definition of void address.
 *      
**/
typedef void (*ptAPPL_START_ADDR)(void);

/**
 * \brief
 *       NVM ECU Data struct definition.
 *
**/
typedef struct
{                              
    uint8 ubECUProgInfo;                               /* Represent the application coherency */
    uint8 aubRandom[SA_RANDOM_NUMBER_LENGTH];          /* Last random value use for security access */
    uint8 ubAsRetryCnt;                                /* Counter of failed security access error   */
} tNVMEcuData;

/**
 * \brief
 *       Segment List struct definition.
 *
**/
typedef struct
{
  uint32 aulSegProgSize[PROG_MAX_NBR_SEG];
  uint8 ubNbSegNbr;
} tSegmentList;

/**
 * \brief
 *       NVM Block Data struct definition.
 *
**/
typedef struct
{
    tSegmentList stSegmentList;     /* List of segment flashed during last block reprogramming */    
    uint16 uwProgCounter;           /* Programming counter of the block */
    uint8 ubStatusInformation;
    uint8 aubFingerPrintInfo[PROG_FINGERPRINT_LENGTH]; /* Finger print of the block */
} tNVMBlockData;

/**
 * \brief
 *       NVM Bootloader Data struct definition.
 *
**/
typedef struct
{
    uint32 ulInitPattern;
    tNVMBlockData stNVMBlockData[PROG_BLOCK_NBR];
    tNVMEcuData stNVMEcuData;
} App_stNVMBootloaderDataType;

/**
 * \brief
 *       Shared variable between bootloader and application struct definition.
 *
**/
typedef struct
{
    uint32 ulProgSig;
    uint8 ubResponseRequired;
    uint8 ubResetCause;
    uint8 ubRxPduId;
    uint8 ubSide;
    uint8 ubTpSize;
} App_stNoInitShareVarType;

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/
#define PROG_REPROG_FLAG_START_SEC_VAR_NO_INIT_8
#include <MemMap.h>
/**
 * \brief
 *       Shared variable between bootloader and application.
 *       Shall be stored in a NoInit area known by both software.
 *
**/
extern App_stNoInitShareVarType Dcmif_stNoIntShareVar;

#define PROG_REPROG_FLAG_STOP_SEC_VAR_NO_INIT_8
#include <MemMap.h>

/**
 * \brief
 *       NVM Bootloader Data (RAM structure of NVM mirror).
 *
**/
extern App_stNVMBootloaderDataType Dcmif_stNVMBootloaderData;
/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/
#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/
#endif      /* APP_TYPES_H */








