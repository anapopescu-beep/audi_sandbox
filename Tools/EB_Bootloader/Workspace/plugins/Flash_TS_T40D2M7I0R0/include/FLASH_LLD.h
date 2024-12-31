#ifndef FLASH_LLD_H
#define FLASH_LLD_H

/*
===============================================================================

                               BOOT layers

 -----------------------------------------------------------------------------

                                 FLASH configuration

===============================================================================
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%   _____________________________   %%  File: FLASH_LLD.h
%%  |                             |  %%  Purpose: FLASH layer implementation
%%  |   &&&&&   &&&&&             |  %%  Module version: 7.0.2
%%  |   &       &    &            |  %%  Target: CORTEXM
%%  |   &&&&    &&&&&             |  %%  Derivate: S32K14X
%%  |   &       &    &            |  %%  Variant: OsekCore
%%  |   &&&&&   &&&&&             |  %%
%%  |_____________________________|  %%
%%                                   %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
===============================================================================
 Copyright 2018 by Elektrobit Automotive GmbH
 All rights exclusively reserved for Elektrobit Automotive GmbH,
 unless expressly agreed to otherwise.
===============================================================================
*/

/*============================= FILE INCLUSION ==================================*/
/* Header files */

/*===============================================================================*/

/*============================= PUBLIC DEFINITIONS ==============================*/


/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Types                                                                */

/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */

/*-------------------------------------------------------------------------------*/
/* - Public Function Prototypes                                                  */

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
 ** \retval FLASH_LLD_ACCESS_ERROR An error occurred during writing operations. The data have not been written correctly.
 ** \retval FLASH_LLD_NO_ERROR     No problem, the data have been written correctly
 ** \retval FLASH_PROT_ERROR       Data cannot be written because address is located in a protected memory area
 **
 **
 **/
extern tFlashStatus FLASH_LLD_WriteBuffer(tFlashAddress uAddr,u16 uwLen,const u8 FLASH_FAR_POINTER aubData);

/** \brief Erase sector of flash memory
 **
 ** This function allows to erase the sector of the flash memory, corresponding to the address
 ** specified in input parameter
 **
 ** \param[in] ulSectorNo Sector to erase
 **
 ** \return Result of operation
 ** \retval FLASH_LLD_ACCESS_ERROR An error occurred during erasing operations. The data have not been written correctly.
 ** \retval FLASH_LLD_NO_ERROR     No problem, the sector have been correctly erased
 ** \retval FLASH_PROT_ERROR       Data cannot be erased because address is located in a protected memory area
 **
 **/
extern tFlashStatus FLASH_LLD_EraseSector(u16 ulSectorNo);

/** \brief Erase one or several sectors of flash memory
 **
 ** This function allows to erase one or several sectors of the flash memory, starting from the address
 ** specified in input parameter.
 **
 ** \param[in] uAddr Memory address of the first sector to be erased
 ** \param[in] ulStartBlockNo First block to be erased
 ** \param[in] ulEndBlockNo Last block to be erased
 **
 ** \return Result of operation
 ** \retval FLASH_LLD_ACCESS_ERROR An error occurred during erasing operations. The data have not been written correctly.
 ** \retval FLASH_LLD_NO_ERROR     No problem, the sector(s) have been correctly erased
 ** \retval FLASH_PROT_ERROR       Data cannot be erased because address is located in a protected memory area
 **
 **
 **/
extern tFlashStatus FLASH_LLD_Erase(tFlashAddress uAddr, u16 ulStartBlockNo, u16 ulEndBlockNo);


/** \brief Initialize layer
 **
 ** This function initializes the FLASH layer, shall be called only once at ECU startup
 **
 **/
extern void FLASH_LLD_Init(void);

#ifdef FLASH_OPERATION_CBK
/** \brief Callback function on flash low layer operations
 **
 ** This function enbales to execute desired code during low layer operations
 **
 **/
extern void  FLASH_OperationCbk(void);
#endif


/* - Public Callback Prototypes                                                  */

/*                                                                               */
/*===============================================================================*/



#endif      /* FLASH_LLD_H */
