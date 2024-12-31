/*********************************************************************************/
/*                                                                               */
/*                                  CAN Stack                                    */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                                 APP configuration                             */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file APP_Types.h                     */
/*%%  |                             |  %%  \brief APP layer types  */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 3.6.255 OSC_BOOT                */
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

#ifndef APP_TYPES_H
#define APP_TYPES_H

#include "Target_Specific_Definition.h"

/** \brief Define APP_FALSE */
#define APP_FALSE               0U
/** \brief Define APP_TRUE */
#define APP_TRUE                1U
/** \brief definition of the tAppBoolean */
typedef u8 tAppBoolean;

/** \brief Define SOFT_RESET */
#define SOFT_RESET 0x00U
/** \brief Define POWER_ON */
#define POWER_ON   0x01U

#define PROG_FINGERPRINT_LENGTH             9U
#define PROG_MAX_NBR_SEG                    5U
#define PROG_BLOCK_NBR                      2U
#define NVM_INIT_PATTERN                    0x494E4954U
#define BL_RAM_INIT_VALUE                   0x2Du
#define PROG_COHERENCY_OK                   0U
#define PROG_COHERENCY_ERR                  1U
#define PROG_COHERENCY_ERR_HW_SW            2U
#define PROG_COHERENCY_ERR_SW_SW            3U
#define PROG_COHERENCY_ERR_INVALID_BLOCK    4U
#define PROG_INFO_PROGR_AND_VALID           0x01U
#define PROG_INFO_SW_SW_MISMATCH            0x02U
#define PROG_INFO_SW_HW_MISMATCH            0x04U
#define PROG_INFO_MEMORY_STATUS             0x08U

/* Define the value of ECU Programming Info */
#define PROG_ECUPROGINFO_CONSISTENT     0x40U
#define PROG_ECUPROGINFO_INCONSISTENT   0x44U

#define PROG_BLOCK_VALID                0x01U
#define PROG_BLOCK_INVALID              0x00U
#define PROG_INFO_REPROG_STATE_VALID        0x00U
#define PROG_INFO_REPROG_STATE_ERASED_START 0x10U
#define PROG_INFO_REPROG_STATE_ERASED_END   0x20U
#define PROG_INFO_REPROG_STATE_REPROG_START 0x30U
#define PROG_INFO_REPROG_STATE_CHECK_OK     0x40U
#define PROG_INFO_REPROG_STATE_CHECK_NOK    0x50U
#define PROG_INFO_REPROG_STATE_CHECK_SW_NOK 0x60U

#define PROG_INFO_REPROG_STATE_MASK         0x70U
typedef void (*ptAPPL_START_ADDR)(void);


typedef struct
{                              
    u8 ubECUProgInfo;                               /* Represent the application coherency */
    u8 aubRandom[SA_RANDOM_NUMBER_LENGTH];          /* Last random value use for security access */
    u8 ubAsRetryCnt;                                /* Counter of failed security access error   */
} tNVMEcuData;

typedef struct
{
  u32 aulSegProgSize[PROG_MAX_NBR_SEG];
  u8 ubNbSegNbr;
}tSegmentList;

typedef struct
{
    tSegmentList stSegmentList;     /* List of segment flashed during last block reprogramming */    
    u16 uwProgCounter;              /* Programming counter of the block */
    u8 ubStatusInformation;
    u8 aubFingerPrintInfo[PROG_FINGERPRINT_LENGTH]; /* Finger print of the block */
} tNVMBlockData;

typedef struct
{
    uint32 ulInitPattern;
    tNVMBlockData stNVMBlockData[PROG_BLOCK_NBR];
    tNVMEcuData stNVMEcuData;
} tNVMBootloaderData;

typedef struct
{
    uint32 ulProgSig;
    u8 ubResponseRequired;
    u8 ubResetCause;
    u8 ubRxPduId;
} tNoInitShareVar;

#define PROG_REPROG_FLAG_START_SEC_VAR_NO_INIT_8
#include <MemMap.h>
/*
 * Shared variable between bootlaoder and application
 * Shall be stored in a NoInit area known by both software
 */
extern tNoInitShareVar stNoIntShareVar;
#define PROG_REPROG_FLAG_STOP_SEC_VAR_NO_INIT_8
#include <MemMap.h>

#define PROG_START_SEC_VAR_RAM_NO_INIT
#include <MemMap.h>
/* RAM structure of NVM mirror */
extern tNVMBootloaderData stNVMBootloaderData;
#define PROG_STOP_SEC_VAR_RAM_NO_INIT
#include <MemMap.h>

#endif      /* APP_TYPES_H */
