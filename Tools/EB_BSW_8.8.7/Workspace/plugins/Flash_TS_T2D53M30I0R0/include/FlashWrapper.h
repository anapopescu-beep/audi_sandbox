#ifndef FLASHWRAPPER_H
#define FLASHWRAPPER_H
/*===============================================================================*/
/*                                                                               */
/*                               FLASH layers                                    */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                              FLASH  configuration                             */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file FlashWrapper.h                  */
/*%%  |                             |  %%  \brief FLASH layer implementation     */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 30.0.2                 */
/*%%  |   &       &    &            |  %%  Variant: Autosar                  */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*===============================================================================*/
/* Copyright 2015 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*===============================================================================*/

/***************/
/*Include files*/
/***************/
#include "FlashWrapper_Types.h"
#include "FlashWrapper_Macros.h"
#include "FlashWrapper_Generated.h"
#include "FlsLoaderWrapper.h"

/***************************************/
/*Declare the typedef pointer functions*/
/***************************************/
/*Declare the typedef pointer function with the Init function signature*/
typedef
  FLW_INIT_ROUTINE_RETURN (*FLW_INIT_ROUTINE_TYPEDEF) FLW_INIT_ROUTINE_SIGNATURE;

/*Declare the typedef pointer function with the Erase function signature */
typedef
  FLW_ERASE_ROUTINE_RETURN (*FLW_ERASE_ROUTINE_TYPEDEF) FLW_ERASE_ROUTINE_SIGNATURE;

/*Declare the typedef pointer function with the Write function signature*/
typedef
  FLW_WRITE_ROUTINE_RETURN (*FLW_WRITE_ROUTINE_TYPEDEF) FLW_WRITE_ROUTINE_SIGNATURE;

/*Declare the typedef pointer function with the Read function signature*/
typedef
  FLW_READ_ROUTINE_RETURN (*FLW_READ_ROUTINE_TYPEDEF) FLW_READ_ROUTINE_SIGNATURE;

/*Declare the typedef pointer function with the Main function signature*/
typedef
  FLW_MAIN_ROUTINE_RETURN (*FLW_MAIN_ROUTINE_TYPEDEF) FLW_MAIN_ROUTINE_SIGNATURE;

/*Declare the typedef pointer function with the JobStatus function signature*/
typedef
  FLW_JOBSTATUS_ROUTINE_RETURN (*FLW_JOBSTATUS_ROUTINE_TYPEDEF) FLW_JOBSTATUS_ROUTINE_SIGNATURE;
/*********************/
/*Typedef definitions*/
/*********************/
typedef struct
{
  /*Byte [0:3]*/
  FLW_INIT_ROUTINE_TYPEDEF InitRoutine;

  /*Byte [4:7]*/
  FLW_ERASE_ROUTINE_TYPEDEF EraseRoutine;
  
  /*Byte [8:11]*/
  FLW_WRITE_ROUTINE_TYPEDEF WriteRoutine;

  /*Byte [12:15]*/
  FLW_READ_ROUTINE_TYPEDEF ReadRoutine;

  /*Byte [16:19]*/
  FLW_MAIN_ROUTINE_TYPEDEF MainRoutine;

  /*Byte [20:23]*/
  FLW_JOBSTATUS_ROUTINE_TYPEDEF JobStatusRoutine;
}tFLW_CbInROM; /* Be careful!!! you have to respect an alignment on 4 bytes */


/*********************/
/*External prototypes*/
/*********************/
extern eFLWStatus FLW_Init(void);
extern eFLWStatus FLW_InitRoutine(void* Ptr);
extern eFLWStatus FLW_EraseRoutine(uint32 uAddr, uint32 uwLen);
extern eFLWStatus FLW_WriteRoutine(uint32 uAddr, uint32 uwLen, const uint8* aubData);
extern eFLWStatus FLW_ReadRoutine(uint32 uAddr, uint32 uwLen, const uint8* aubData);
extern eFLWStatus FLW_MainRoutine(void);
extern eFLWStatus FLW_JobStatusRoutine(void);

/********************/
/*External variables*/
/********************/
/*ROM*/
extern uint32 __Flash_API_ROM_SECTION_START_ADDR[];
extern uint32 __Flash_API_ROM_SECTION_END_ADDR[];

/*RAM*/
extern uint32 __Flash_API_RAM_SECTION_START_ADDR[];
extern uint32 __Flash_API_RAM_SECTION_END_ADDR[];

/*Global FLS status structure info*/
extern tFLW_Status FLWStatus_T;

/*Define FLWCbInRAM structure*/
extern tFLW_CbInROM FLWCbInROM_T;

#endif /*#ifndef FLASHWRAPPER_H*/

