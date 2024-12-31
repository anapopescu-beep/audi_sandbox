#ifndef FLASHWRAPPER_TYPES_H
#define FLASHWRAPPER_TYPES_H
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
/*%%   _____________________________   %%  \file FlashWrapper_Types.h            */
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
/*********************/
/*Typedef definitions*/
/* Different FLW status */
typedef enum
{
  FLW_NO_ERROR=0x00U,
  FLW_INIT_ERROR,
  FLW_ERASE_ERROR,
  FLW_WRITE_ERROR,
  FLW_READ_ERROR,
  FLW_MAIN_ERROR,
  FLW_JOBSTATUS_ERROR,
} eFLWStatus;

/*********************/
/* Enum flash operations */
typedef enum
{
  None, /*"None" shall be in the first enumerate position*/
  Init,
  Erase,
  Write,
  Read,
  Main,
  JobStatus
} eFLWOperations;

typedef struct
{
  uint8 IsAlignedFLWStatus; /* Status of FLWStatus_T structure alignement */
  uint8 IsAlignedFLWCbInROM; /* Status of FLWCbInROM_T structure alignement */
  uint8 IsInitialized; /* Status of Flash Wrapper initialization*/
  uint8 IsStarted; /* Status of Flash Wrapper starting*/
  uint8 IsBusy; /* Status of Flash Wrapper busy*/
  uint8 CopyRomToRamRequested; /*Status of Flash copy Rom to Ram*/
  uint16 CodeSize; /* Status of FLS code size */  
  uint32 ROMStartAddr; /* FLW ROM start code address */
  uint32 RAMStartAddr; /* FLW RAM start code address */  
  eFLWOperations OperationInProgress; /*(from eFLW_Operations)*/
}tFLW_Status; /* Be careful!!! you have to respect an alignment on 4 bytes */

/** \brief FLASH layer FALSE define used for boolean actions in the layer*/
#define FLW_FALSE   0U
/** \brief FLASH layer TRUE define used for boolean actions in the layer*/
#define FLW_TRUE    1U

#endif

