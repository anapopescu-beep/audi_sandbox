#ifndef FLASH_PUB_H
#define FLASH_PUB_H

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
/*%%   _____________________________   %%  \file FLASH_Pub.h                     */
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

/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Constants                                                            */

/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */
extern const tFLASHSectorsTable FlashSectorsTable[];

/*-------------------------------------------------------------------------------*/
/* - Public Function Prototypes                                                  */
/** \brief Initialize layer
 **
 ** This function initializes the FLASH layer, shall be called only once at ECU startup
 **
 **/
extern eFlashStatus FLASH_Init(void);

/** \brief Write buffer of data to flash memory
 **
 ** This function allows to write a buffer of data in flash memory at the address
 ** specified in input parameter
 **
 ** \param[in] uAddr Memory address where the data shall be written
 ** \param[in] uwLen Length of the data to be written
 ** \param[in] aubData Buffer of data to be written
 **
 ** \return Result of operation
 ** \retval FLASH_ACCESS_ERROR An error occurred during writing operations. The data have not been written correctly.
 ** \retval FLASH_NO_ERROR     No problem, the data have been written correctly
 **
 **/
extern eFlashStatus FLASH_Write(uint32 uAddr, 
                                uint32 uwLen,
                                uint8* aubData);

/** \brief Erase one or several sectors of flash memory
 **
 ** This function allows to erase one or several sectors of the flash memory, starting from the address
 ** specified in input parameter.
 **
 ** \param[in] uAddr Memory address of the first sector to be erased
 ** \param[in] uwLen Length of the data to be erased
 **
 ** \return Result of operation
 ** \retval FLASH_ACCESS_ERROR An error occurred during erasing operations. The data have not been written correctly.
 ** \retval FLASH_NO_ERROR     No problem, the sector(s) have been correctly erased
 **
 **/
extern eFlashStatus FLASH_Erase(uint32 uAddr,
                                uint32 uwLen);

/** \brief Read the flash memory
 **
 ** This function allows to read the data located to the address specified in input parameter.
 **
 ** \param[in] uAddr Memory address in flash to read
 ** \param[in] uwLen Length of the data to read
 ** \param[in] aubData Buffer where to store the read data
 **
 ** \return Result of operation
 ** \retval FLASH_ACCESS_ERROR An error occurred during check operations.
 ** \retval FLASH_NO_ERROR     No problem, the memory has been checked correctly
 **
 **/
extern eFlashStatus FLASH_Read(uint32 uAddr, 
                               uint32 uwLen, 
                               uint8* aubData);


/** \brief Flash main function
 **
 ** This function allows to manage the flash actions
 **
 ** \return Result of operation
 ** \retval FLASH_ACCESS_ERROR An error occurred during check operations.
 ** \retval FLASH_NO_ERROR     No problem, the memory has been checked correctly
 **
 **/
extern void FLASH_MainFunction(void);


/** \brief Flash get job status function
 **
 ** This function allows to retrieve the current job status
 **
 ** \return Result of operation
 ** \retval FLASH_ACCESS_ERROR An error occurred during check operations.
 ** \retval FLASH_NO_ERROR     No problem, the memory has been checked correctly
 **
 **/
extern eFlashStatus FLASH_GetJobStatus(void);

/****************************************************/
/*TEMP CODE WHICH SHALL DISAPEAR ON THE RELEASE STEP*/
/****************************************************/
extern eFlashStatus FLASH_EraseSector(uint32 uAddr);
extern eFlashStatus FLASH_WriteBuffer(uint32 uAddr, uint32 uwLen, uint8* aubData);
extern uint32 FLASH_GetNextSectorAddr(uint32 uAddr);

/*-------------------------------------------------------------------------------*/
/* - Public Callback Prototypes                                                  */

/*                                                                               */
/*===============================================================================*/


#endif      /* FLASH_PUB_H */

