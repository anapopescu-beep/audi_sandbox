/*===============================================================================*/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                               FlashWrapper layer                              */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file FlashWrapper.c                  */
/*%%  |                             |  %%  \brief Flas hWrapper layer source plugin file  */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 30.0.2                 */
/*%%  |   &       &    &            |  %%  Variant: Autosar                          */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*===============================================================================*/
/* Copyright 2010 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*===============================================================================*/
/*=============================== FILE INCLUSION ================================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Header Files: Variable Types                                                */


/*-------------------------------------------------------------------------------*/
/* - Header Files:                                                               */

#include "EB_Prj.h"
#include "FlashWrapper.h"

#ifdef FLW_CUSTOM_WRAPPER_USED

#ifdef NCS_UNITARY_TEST
#include "FlsLoader_Stub_Callout.h"
#endif

/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */


/*-------------------------------------------------------------------------------*/
/* - Public Function Prototypes                                                  */

/*-------------------------------------------------------------------------------*/
/* - Public Callback Prototypes                                                  */

/*                                                                               */
/*===============================================================================*/

/*============================ PRIVATE DEFINITIONS ==============================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Private Constants                                                           */

/*-------------------------------------------------------------------------------*/
/* - Private Types                                                               */
typedef struct
{
  /* Byte [0:3]*/
  FLW_ERASE_ROUTINE_TYPEDEF EraseRoutine;

  /* Byte [4:7]*/
  FLW_WRITE_ROUTINE_TYPEDEF WriteRoutine;
}tCbInRAM; /* Be careful!!! you have to respect an alignment on 4 bytes */

/*-------------------------------------------------------------------------------*/
/* - Private Variables                                                           */
tCbInRAM FLWCbInRAM_T;

/*-------------------------------------------------------------------------------*/
/* - Private Macros                                                              */

/*-------------------------------------------------------------------------------*/
/* - Private Function Prototypes                                                 */


/*                                                                               */
/*===============================================================================*/

/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */

/*-------------------------------------------------------------------------------*/
/* - Private Functions                                                           */

/*-------------------------------------------------------------------------------*/
/* - Public Functions                                                            */

/*----------------------------------{FlsLoaderWrapper_Init}-----------------------------*/
FLW_INIT_ROUTINE_RETURN FlsLoaderWrapper_Init FLW_INIT_ROUTINE_SIGNATURE
{
  /*Declare local FlashLoaderWrapper status variable*/
  eFlsLoaderWrapperStatus FlsLoaderWrapperStatus = FLASH_LOADER_WRAPPER_NO_ERROR;

  /*Overwrite the Erasing function name put through Tresos for the Erasing operation*/
  FLWCbInROM_T.EraseRoutine = FLW_COMPUTE_FCT_ADDR_IN_ROM(FLW_WRAPPER_ERASE_ROUTINE_NAME);

  /*Overwrite the Erasing function name put through Tresos for the Writing operation*/
  FLWCbInROM_T.WriteRoutine = FLW_COMPUTE_FCT_ADDR_IN_ROM(FLW_WRAPPER_WRITE_ROUTINE_NAME);

#ifndef NCS_UNITARY_TEST
  /*Set the RAM pointer function which shall point on the image's code of Erase routine function into the RAM*/
  FLWCbInRAM_T.EraseRoutine = FLW_COMPUTE_FCT_ADDR_IN_RAM(FLW_ERASE_ROUTINE_NAME);

  /*Set the RAM pointer function which shall point on the image's code of Write routine function into the RAM*/
  FLWCbInRAM_T.WriteRoutine = FLW_COMPUTE_FCT_ADDR_IN_RAM(FLW_WRITE_ROUTINE_NAME);
#else
  /*Set the RAM pointer function which shall point on the image's code of Erase routine function into the ROM*/
  FLWCbInRAM_T.EraseRoutine = FLW_COMPUTE_FCT_ADDR_IN_ROM(FLW_ERASE_ROUTINE_NAME);

  /*Set the RAM pointer function which shall point on the image's code of Write routine function into the ROM*/
  FLWCbInRAM_T.WriteRoutine = FLW_COMPUTE_FCT_ADDR_IN_ROM(FLW_WRITE_ROUTINE_NAME);
#endif
  
  /*Return Init status operation*/
  return((FLW_INIT_ROUTINE_RETURN)(FlsLoaderWrapperStatus));
}
/*----------------------------------{end FlsLoaderWrapper_Init}----------------------------*/


/*----------------------------------{FlsLoaderWrapper_Erase}-----------------------------*/
FLW_ERASE_ROUTINE_RETURN FlsLoaderWrapper_Erase FLW_ERASE_ROUTINE_SIGNATURE
{
  /*Declare local FlashLoaderWrapper status variable*/
  eFlsLoaderWrapperStatus FlsLoaderWrapperStatus = FLASH_LOADER_WRAPPER_NO_ERROR;
  
  /*Perform the erasing through the dedicated low layer API in RAM*/
  FlsLoaderWrapperStatus = (eFlsLoaderWrapperStatus)(FLW_ERASE_ROUTINE_CB_IN_RAM(ARG1,ARG2));

  /*If an error occurs on the Erasing attempt*/
  if(FLASH_LOADER_WRAPPER_NO_ERROR != FlsLoaderWrapperStatus)
  {
     /***************************/
     /*Error data logger (TO DO)*/
     /***************************/
  }

  /*Return Erase status operation*/
  return((FLW_ERASE_ROUTINE_RETURN)(FlsLoaderWrapperStatus));
}
/*----------------------------------{end FlsLoaderWrapper_Erase}----------------------------*/

/*----------------------------------{FlsLoaderWrapper_Write}-----------------------------*/
FLW_WRITE_ROUTINE_RETURN FlsLoaderWrapper_Write FLW_WRITE_ROUTINE_SIGNATURE
{
  /*Declare local FlashLoaderWrapper status variable*/
  eFlsLoaderWrapperStatus FlsLoaderWrapperStatus = FLASH_LOADER_WRAPPER_NO_ERROR;
  
  /*Perform the writing through the dedicated low layer API in RAM*/
  FlsLoaderWrapperStatus = (eFlsLoaderWrapperStatus)(FLW_WRITE_ROUTINE_CB_IN_RAM(ARG1,ARG2,ARG3));

  /*If an error occurs on the Write attempt*/
  if(FLASH_LOADER_WRAPPER_NO_ERROR != FlsLoaderWrapperStatus)
  {
     /***************************/
     /*Error data logger (TO DO)*/
     /***************************/
  }

  /*Return Write status operation*/
  return((FLW_WRITE_ROUTINE_RETURN)(FlsLoaderWrapperStatus));
}
/*----------------------------------{end FlsLoaderWrapper_Write}----------------------------*/


/*----------------------------------{FlsLoader_Read}-----------------------------*/
FLW_READ_ROUTINE_RETURN FlsLoader_Read FLW_READ_ROUTINE_SIGNATURE
{
  /*Declare local FlashLoaderWrapper status variable*/
  eFlsLoaderWrapperStatus FlsLoaderWrapperStatus = FLASH_LOADER_WRAPPER_NO_ERROR;
  uint32 loop = 0U;
    
#ifndef NCS_UNITARY_TEST
  uint8* AddressPtr = (uint8*)(FLW_READ_ROUTINE_ADDRESS_ARG);
#endif

  /*If the pointer data is not NULL*/
  if(NULL_PTR != FLW_READ_ROUTINE_POINTER_DATA_ARG)
  {
    /*Foreach bytes to read*/
    for (loop = (uint32)(0x00); loop < FLW_READ_ROUTINE_LENGHT_ARG; loop++)
    {
#ifdef NCS_UNITARY_TEST
      /*Store the read byte simulation into the dedicated table*/
      FLW_READ_ROUTINE_POINTER_DATA_ARG[loop] = FlashAreasSimulation[loop];
#else
      /*Store the read byte into the dedicated table*/
      FLW_READ_ROUTINE_POINTER_DATA_ARG[loop] = AddressPtr[loop];
#endif
    }
  }
  else
  {
    /*Return Flash access error*/
    FlsLoaderWrapperStatus = FLASH_LOADER_WRAPPER_READ_ERROR;
  }

  /*If an error occurs on the Read attempt*/
  if(FLASH_LOADER_WRAPPER_NO_ERROR != FlsLoaderWrapperStatus)
  {
     /***************************/
     /*Error data logger (TO DO)*/
     /***************************/
  }

  /*Return Read status operation*/
  return((FLW_READ_ROUTINE_RETURN)(FlsLoaderWrapperStatus));
}
/*----------------------------------{end FlsLoader_Read}----------------------------*/

#endif /*#ifndef FLW_CUSTOM_WRAPPER_USE*/














