#ifndef FLASH_TYPES_H_
#define FLASH_TYPES_H_

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
/*%%   _____________________________   %%  \file FLASH_Types.h                   */
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

/*==================[macros]=====================================================*/
/*Enum which represent the different Flash action requests*/
typedef enum
{
  cNoRequest,
  cErasingRequest,
  cWritingRequest,
  cReadingRequest
}eFlashRequest;

/* Different flash status */
typedef enum
{
  FLASH_NO_ERROR=0x00U,  
  FLASH_ERASE_ERROR,
  FLASH_WRITE_ERROR,
  FLASH_READ_ERROR,  
  FLASH_PROT_ERROR,  
  FLASH_BUSY,
  FLASH_INIT_FAILED,
  FLASH_ADDR_NOT_ALLOWED,
  FLASH_ADDR_NOT_PROGRAMMABLE,
  FLASH_ADDR_NOT_ALIGNED_ON_PAGE,
  FLASH_ADDR_NOT_ALIGNED_ON_SECTOR,
  FLASH_ADDR_RANGE_NOT_ALLOWED,
  FLASH_PTR_IS_NULL,
  FLASH_NO_FILTERED_ELEMENT_FOUND,
  FLASH_NO_ADDR_TABLE_INFO_FOUND,
  FLASH_END_OF_ERASING,
  FLASH_ADDR_ROLLING_BACK,
  FLASH_NO_NEXT_ADDR,
  FLASH_SECTOR_NB_NOT_FOUND,
  FLASH_JOB_STATUS_ERROR,
  FLASH_PHYSICAL_TO_LOGICAL_ERROR,
  FLASH_UNEXPECTED_REQUEST,

  FLASH_ENUM_STATUS_NB_OF_ELEMENTS/*Shall always be the last element of the enum*/
} eFlashStatus;

#define FLASH_SYNCHRONE_MODE    0
#define FLASH_ASYNCHRONE_MODE   1

/** \brief FLASH layer FALSE define used for boolean actions in the layer*/
#define FLASH_FALSE   0U
/** \brief FLASH layer TRUE define used for boolean actions in the layer*/
#define FLASH_TRUE    1U

/*==================[type definitions]===========================================*/

/** \brief Structure of flash sector containing address, length and programmability information*/
typedef struct
{
  uint32    StartAddress;         /* Start Address of the sector */
  uint32    Length;               /* Length of the sector */
  uint32    SectorSize;           /* Sector size */
  boolean   Programmable;         /* Sector reprogramable or not */
  /*uint8     UnusedBytes_13_15[3]; Unused bytes to ensure the alignment*/
}tFLASHSectorsTable;


/*==================[external function declarations]============================*/

/*==================[internal function declarations]============================*/

/*==================[external constants]========================================*/

/*==================[internal constants]========================================*/

/*==================[external data]=============================================*/

/*==================[internal data]=============================================*/

/*==================[external function definitions]=============================*/

/*==================[internal function definitions]=============================*/

#endif
/* FLASH_TYPES_H_ */
