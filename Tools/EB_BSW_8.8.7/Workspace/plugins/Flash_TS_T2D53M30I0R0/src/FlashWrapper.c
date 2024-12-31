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
#include "board.h"


/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */
/*Define FLW_Status structure*/
tFLW_Status FLWStatus_T;

/*Define FLWCbInRAM structure*/
tFLW_CbInROM FLWCbInROM_T;

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

/*-------------------------------------------------------------------------------*/
/* - Private Variables                                                           */

/*-------------------------------------------------------------------------------*/
/* - Private Macros                                                              */

/*-------------------------------------------------------------------------------*/
/* - Private Function Prototypes                                                 */
/*Prototype of the Flw_InitStructure function */
NCS_PRI_FCT boolean Flw_InitStructure(uint8* FlwStruct_T, 
                                      uint32 FlwSize_U32);

#ifdef FLW_INIT_IS_COPY_ROM_TO_RAM
/*Prototype of the Flw_CopyDatas function */
NCS_PRI_FCT void Flw_CopyDatas(const uint8* FlsSourceData_U8P,
                               uint8* FlsDestinationData_U8P,
                               uint32 FlsNbBytes_U32);
#endif
/*                                                                               */
/*===============================================================================*/

/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */

/*-------------------------------------------------------------------------------*/
/* - Private Functions                                                           */
/*----------------------------------{Flw_InitStructure}--------------------------------*/
NCS_PRI_FCT boolean Flw_InitStructure(uint8* FlwStruct_T, uint32 FlwSize_U32)
{
  /*Declare local variables*/
  boolean Returned_B;
  uint32 i_U32;

  /*Check if the FlwStruct_T respect an alignment on 4 bytes*/
  if((FlwSize_U32%0x04) == 0x00)
  {
    /* For all bytes of the tFlsStatus structure */
    for(i_U32 = (uint32)(0x0); i_U32 < FlwSize_U32; i_U32++)
    {
      /* Reset the correspondent byte */
      FlwStruct_T[i_U32] = (uint8)(0x00);
    }

    /*Set to true the returned value*/
    Returned_B = FLW_TRUE;
  }
  else
  {
    /*Set to false the returned value*/
    Returned_B = FLW_FALSE;
  }

  /*Return false*/
  return(Returned_B);
}
/*----------------------------------{end Flw_InitStructure}----------------------------*/

#ifdef FLW_INIT_IS_COPY_ROM_TO_RAM
/*----------------------------------{Flw_CopyDatas}--------------------------------*/
/*Function which enables to perform a copy of datas from source to destination addresses */
NCS_PRI_FCT void Flw_CopyDatas(const uint8* FlsSourceData_U8P, uint8* FlsDestinationData_U8P, uint32 FlsNbBytes_U32)
{
  /*Declare local variables*/
  uint32 i_U32;
    
  /* Copy from source address to destination address */
  for(i_U32 = (uint32)(0x0); i_U32 < FlsNbBytes_U32; i_U32++)
  {
    /* Copy from source to destination */
    FlsDestinationData_U8P[i_U32] = FlsSourceData_U8P[i_U32];
  }
}
/*----------------------------------{end Flw_CopyDatas}----------------------------*/
#endif

/*-------------------------------------------------------------------------------*/
/* - Public Functions                                                            */

/*----------------------------------{FLW_Init}----------------------------------*/
eFLWStatus FLW_Init(void)
{
  /*Declare local flash status variable*/
  eFLWStatus FLWStatus = FLW_NO_ERROR;
  
  /*Initialize the FLWStatus_T structure*/
  FLWStatus_T.IsAlignedFLWStatus = (uint8)(Flw_InitStructure((uint8*)(&FLWStatus_T), (uint32)(sizeof(tFLW_Status))));

  /*Initialize the FLWCbInROM_T structure*/
  FLWStatus_T.IsAlignedFLWCbInROM = (uint8)(Flw_InitStructure((uint8*)(&FLWCbInROM_T), (uint32)(sizeof(tFLW_CbInROM))));

  /*Set the RAM pointer function which shall point on the image's code of Init routine function into the ROM*/
  FLWCbInROM_T.InitRoutine = FLW_COMPUTE_FCT_ADDR_IN_ROM(FLW_INIT_ROUTINE_NAME);
  
  /*Set the RAM pointer function which shall point on the image's code of Erase routine function into the ROM*/
  FLWCbInROM_T.EraseRoutine = FLW_COMPUTE_FCT_ADDR_IN_ROM(FLW_ERASE_ROUTINE_NAME);

  /*Set the RAM pointer function which shall point on the image's code of Write routine function into the ROM*/
  FLWCbInROM_T.WriteRoutine = FLW_COMPUTE_FCT_ADDR_IN_ROM(FLW_WRITE_ROUTINE_NAME);
  
  /*Set the RAM pointer function which shall point on the image's code of Read routine function into the ROM*/
  FLWCbInROM_T.ReadRoutine = FLW_COMPUTE_FCT_ADDR_IN_ROM(FLW_READ_ROUTINE_NAME);
  
  /*Set the RAM pointer function which shall point on the image's code of Main routine function into the ROM*/
  FLWCbInROM_T.MainRoutine = FLW_COMPUTE_FCT_ADDR_IN_ROM(FLW_MAIN_ROUTINE_NAME);

  /*Set the RAM pointer function which shall point on the image's code of JobStatus routine function into the ROM*/
  FLWCbInROM_T.JobStatusRoutine = FLW_COMPUTE_FCT_ADDR_IN_ROM(FLW_JOBSTATUS_ROUTINE_NAME);

#ifdef FLW_INIT_IS_COPY_ROM_TO_RAM
  /*Set the Copy Rom to Ram request to true*/
  FLWStatus_T.CopyRomToRamRequested = TRUE;
  
  /*Retrieve the low layer APIs flash code size*/
  FLWStatus_T.CodeSize = (uint16)(FLW_GET_SECTION_SIZE(ROM));

  /*Set the low layer APIs Flash ROM pointer on the dedicated section*/
  FLWStatus_T.ROMStartAddr = (uint32)(FLW_GET_SECTION_ADDR(ROM,START));

  /*Set the low layer APIs Flash RAM pointer on the dedicated section*/
  FLWStatus_T.RAMStartAddr = (uint32)(FLW_GET_SECTION_ADDR(RAM,START));
  
  /*Copy the whole "Flash_API_ROM" ROM section to "Flash_API_RAM" RAM section*/
  Flw_CopyDatas((uint8*)(FLWStatus_T.ROMStartAddr),
                (uint8*)(FLWStatus_T.RAMStartAddr),
                (uint32)(FLWStatus_T.CodeSize));
#else
  /*Set the Copy Rom to Ram request to false*/
  FLWStatus_T.CopyRomToRamRequested = FALSE;
  
  /*Set all FLWStatus_T.CodeSize to 0 */
  FLWStatus_T.CodeSize = 0x0000;;

  /*Set all FLWStatus_T.ROMStartAddr to 0 */
  FLWStatus_T.ROMStartAddr = 0x00000000;

  /*Set all FLWStatus_T.RAMStartAddr to 0 */
  FLWStatus_T.RAMStartAddr = 0x00000000;
#endif
  
  /*Initialization through the dedicated low layer API*/
  FLWStatus = FLW_InitRoutine(NULL_PTR);
  
  /*If the low layer initialization has been successfully done*/
  if(FLW_NO_ERROR == FLWStatus)
  {
    /*Set the initialization flag*/
    FLWStatus_T.IsInitialized = TRUE;
  }

  /*Return status*/
  return(FLWStatus);
}
/*----------------------------------{End FLW_Init}----------------------------------*/

/*----------------------------------{Flw_InitRoutine}--------------------------------*/
eFLWStatus FLW_InitRoutine(void* Ptr)
{
  /*Declare local flash status variable*/
  eFLWStatus FLWStatus = FLW_NO_ERROR;

  /* Set the FLW driver operation to Init */
  FLWStatus_T.OperationInProgress = Init;

  /*Set the busy status to TRUE*/
  FLWStatus_T.IsBusy = TRUE;

  /*Call specific wrapper initialization*/
  FLW_WRAPPER_INIT(Ptr);

#ifdef FLW_INIT_ROUTINE_IS_RETURN_EXIST
  /*Perform the initialization through the dedicated low layer API*/
  FLWStatus = (eFLWStatus)(FLW_INIT_ROUTINE_CB_IN_ROM(Ptr));
#else
  /*Perform the initialization through the dedicated low layer API*/
  FLW_INIT_ROUTINE_CB_IN_ROM(Ptr);
#endif

  /*Set the busy status to FALSE*/
  FLWStatus_T.IsBusy = FALSE;

  /*Return initialization status*/
  return(FLWStatus);
}
/*----------------------------------{end Flw_InitRoutine}----------------------------*/

/*----------------------------------{FLW_EraseRoutine}--------------------------------*/
eFLWStatus FLW_EraseRoutine(uint32 uAddr, uint32 uwLen)
{
  /*Declare local flash status variable*/
  eFLWStatus FLWStatus = FLW_NO_ERROR;

  /* Set the FLW driver operation to Erase */
  FLWStatus_T.OperationInProgress = Erase;

  /*Set the busy status to TRUE*/
  FLWStatus_T.IsBusy = TRUE;

#ifdef FLW_ERASE_IS_CRITICAL_SECTION_MNGT
  /*Start critical section*/
  FLW_START_CRITICAL_SECTION();
#endif

#ifdef FLW_ERASE_ROUTINE_IS_RETURN_EXIST
  /*Perform the erasing through the dedicated low layer API*/
  FLWStatus = (eFLWStatus)(FLW_ERASE_ROUTINE_CB_IN_ROM(uAddr,uwLen));
#else
  /*Perform the erasing through the dedicated low layer API*/
  FLW_ERASE_ROUTINE_CB_IN_ROM(uAddr,uwLen);
#endif
  
#ifdef FLW_ERASE_IS_CRITICAL_SECTION_MNGT
  /*End critical section*/
  FLW_END_CRITICAL_SECTION();
#endif

  /*Set the busy status to FALSE*/
  FLWStatus_T.IsBusy = FALSE;

  /*If an error occurs on the Erase attempt*/
  if(FLW_NO_ERROR != FLWStatus)
  {
     /***************************/
     /*Error data logger (TO DO)*/
     /***************************/
  }

  /*Return erase status*/
  return(FLWStatus);
}
/*----------------------------------{end FLW_EraseRoutine}----------------------------*/

/*----------------------------------{FLW_WriteRoutine}--------------------------------*/
eFLWStatus FLW_WriteRoutine(uint32 uAddr, uint32 uwLen, const uint8* aubData)
{
  /*Declare local flash status variable*/
  eFLWStatus FLWStatus = FLW_NO_ERROR;

  /* Set the FLW driver operation to Write */
  FLWStatus_T.OperationInProgress = Write;

  /*Set the busy status to TRUE*/
  FLWStatus_T.IsBusy = TRUE;

#ifdef FLW_WRITE_IS_CRITICAL_SECTION_MNGT
  /*Start critical section*/
  FLW_START_CRITICAL_SECTION();  
#endif
  
#ifdef FLW_WRITE_ROUTINE_IS_RETURN_EXIST
  /*Perform the writing through the dedicated low layer API*/
  FLWStatus = (eFLWStatus)(FLW_WRITE_ROUTINE_CB_IN_ROM(uAddr,uwLen,aubData));
#else
  /*Perform the writing through the dedicated low layer API*/
  FLW_WRITE_ROUTINE_CB_IN_ROM(uAddr,uwLen,aubData);
#endif
  
#ifdef FLW_WRITE_IS_CRITICAL_SECTION_MNGT
  /*End critical section*/
  FLW_END_CRITICAL_SECTION();
#endif

  /*Set the busy status to FALSE*/
  FLWStatus_T.IsBusy = FALSE;

  /*If an error occurs on the Write attempt*/
  if(FLW_NO_ERROR != FLWStatus)
  {
     /***************************/
     /*Error data logger (TO DO)*/
     /***************************/
  }

  /*Return write status*/
  return(FLWStatus);
}
/*----------------------------------{end FLW_WriteRoutine}----------------------------*/

/*----------------------------------{FLW_ReadRoutine}--------------------------------*/
eFLWStatus FLW_ReadRoutine(uint32 uAddr, uint32 uwLen, const uint8* aubData)
{
  /*Declare local flash status variable*/
  eFLWStatus FLWStatus = FLW_NO_ERROR;

  /* Set the FLW driver operation to Read */
  FLWStatus_T.OperationInProgress = Read;

  /*Set the busy status to TRUE*/
  FLWStatus_T.IsBusy = TRUE;

#ifdef FLW_READ_ROUTINE_IS_RETURN_EXIST
  /*Perform the reading through the dedicated low layer API*/
  FLWStatus = (eFLWStatus)(FLW_READ_ROUTINE_CB_IN_ROM(uAddr,uwLen,aubData));
#else
  /*Perform the reading through the dedicated low layer API*/
  FLW_READ_ROUTINE_CB_IN_ROM(uAddr,uwLen,aubData);
#endif

  /*Set the busy status to FALSE*/
  FLWStatus_T.IsBusy = FALSE;

  /*If an error occurs on the Read attempt*/
  if(FLW_NO_ERROR != FLWStatus)
  {
     /***************************/
     /*Error data logger (TO DO)*/
     /***************************/
  }

  /*Return read status*/
  return(FLWStatus);
}
/*----------------------------------{end FLW_ReadRoutine}----------------------------*/

/*----------------------------------{FLW_MainRoutine}--------------------------------*/
eFLWStatus FLW_MainRoutine(void)
{
  /*Declare local flash status variable*/
  eFLWStatus FLWStatus = FLW_NO_ERROR;

  /* Set the FLW driver operation to Main */
  FLWStatus_T.OperationInProgress = Main;

  /*Set the busy status to TRUE*/
  FLWStatus_T.IsBusy = TRUE;

#ifdef FLW_MAIN_ROUTINE_IS_RETURN_EXIST
  /*Perform the main through the dedicated low layer API*/
  FLWStatus = (eFLWStatus)(FLW_READ_ROUTINE_CB_IN_ROM());
#else
  /*Perform the main through the dedicated low layer API*/
  FLW_MAIN_ROUTINE_CB_IN_ROM();
#endif

  /*Set the busy status to FALSE*/
  FLWStatus_T.IsBusy = FALSE;

  /*If an error occurs on the Read attempt*/
  if(FLW_NO_ERROR != FLWStatus)
  {
     /***************************/
     /*Error data logger (TO DO)*/
     /***************************/
  }

  /*Return read status*/
  return(FLWStatus);
}
/*----------------------------------{end FLW_MainRoutine}----------------------------*/

/*----------------------------------{FLW_JobStatusRoutine}--------------------------------*/
eFLWStatus FLW_JobStatusRoutine(void)
{
  /*Declare local flash status variable*/
  eFLWStatus FLWStatus = FLW_NO_ERROR;

  /* Set the FLW driver operation to Main */
  FLWStatus_T.OperationInProgress = JobStatus;

  /*Set the busy status to TRUE*/
  FLWStatus_T.IsBusy = TRUE;

#ifdef FLW_JOBSTATUS_ROUTINE_IS_RETURN_EXIST
  /*Perform the job status through the dedicated low layer API*/
  FLWStatus = (eFLWStatus)(FLW_JOBSTATUS_ROUTINE_CB_IN_ROM());
#else
  /*Perform the job status through the dedicated low layer API*/
  FLW_JOBSTATUS_ROUTINE_CB_IN_ROM();
#endif

  /*Set the busy status to FALSE*/
  FLWStatus_T.IsBusy = FALSE;

  /*If an error occurs on the Read attempt*/
  if(FLW_NO_ERROR != FLWStatus)
  {
     /***************************/
     /*Error data logger (TO DO)*/
     /***************************/
  }

  /*Return read status*/
  return(FLWStatus);
}
/*----------------------------------{end FLW_JobStatusRoutine}----------------------------*/

