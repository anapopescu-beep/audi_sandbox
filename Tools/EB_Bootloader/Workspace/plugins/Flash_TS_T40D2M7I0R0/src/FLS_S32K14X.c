/* CHECK: NOPARSE (turn off the CheckC coverage because of some tests can not be covered*/
/* CHECK: RULE 502 OFF */
/* CHECK: RULE 203 OFF */
/* CHECK: RULE 205 OFF */
/* CHECK: RULE 306 OFF */
/* CHECK: RULE 506 OFF */

/*
===============================================================================

                               BOOT layers

 -----------------------------------------------------------------------------

                                 FLASH configuration

===============================================================================
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%   _____________________________   %%  File: FLS_S32K14X.c
%%  |                             |  %%  Purpose: FLASH Driver APIs
%%  |   &&&&&   &&&&&             |  %%  Module version: 7.0.2
%%  |   &       &    &            |  %%  Target: CORTEXM
%%  |   &&&&    &&&&&             |  %%  Derivate: S32K14X
%%  |   &       &    &            |  %%  Variant: OsekCore
%%  |   &       &    &            |  %%
%%  |   &&&&&   &&&&&             |  %%
%%  |_____________________________|  %%
%%                                   %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
===============================================================================
 Copyright 2010 by Elektrobit Automotive GmbH
 All rights exclusively reserved for Elektrobit Automotive GmbH,
 unless expressly agreed to otherwise.
===============================================================================
*/

/*  MISRA-C:2004 Deviation List
 *
 *  MISRA-1) Deviated Rule: 17.4 (required)
 *   "Array indexing shall be the only allowed form of pointer arithmetic."
 *
 *   Reason:
 *   The pointer is a void type, we can not declare it as an array.
 *
 *  MISRA-2) Deviated Rule: 10.3 (required)
 *   "The value of a complex expression of integer type may only be cast to
 *    a type that is narrower and of the same signedness as the underlying
 *    type of the expression."
 *
 *   Reason:
 *   Code provided by NXP.
 *
 *  MISRA-3) Deviated Rule: 11.4 (advisory)
 *   "A cast should not be performed between a pointer to object type and
 *    a different pointer to object type."
 *
 *   Reason:
 *   Code provided by NXP.
 *
 *  MISRA-4) Deviated Rule: 17.2 (required)
 *   "Pointer subtraction shall only be applied to pointers that address
 *    elements of the same array."
 *
 *   Reason:
 *   Code provided by NXP.
 *
 *  MISRA-5) Deviated Rule: 12.1 (advisory)
 *   "Limited dependence should be placed on C’s operator precedence
 *    rules in expressions."
 *
 *   Reason:
 *   Code provided by NXP.
 *
 *  MISRA-6) Deviated Rule: 11.3 (advisory)
 *   "A cast should not be performed between a pointer type and an
 *    integral type."
 *
 *   Reason:
 *   We need the integer value and not the pointer for our using.
 *   Code provided by NXP
 *
 *  MISRA-7) Deviated Rule: 10.1 (advisory)
 *   "The value of an expression of integer type shall not be implicitly
 *    converted to a different underlying type."
 *
 *   Reason:
 *   The pointer is a void type, we can not declare it as an array.
 */

/*
 Remarks:
 All the public FLS functions SHALL be called through a RAM function pointer.
 There is a risk of RWW (Read While Write) exception if there is a PFlash bus access
during a PFlash operation
*/

/*=============================== FILE INCLUSION ================================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Header Files:                                                               */
#include "ncs.h"
#include "S32K144_features.h"
#include "S32K144.h"
#include "FLS_S32K14X.h"
#include "FLASH_Types.h"
#include "FLASH_Cfg.h"
#include "FLASH_LLD.h"

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
  u32 StartAddress_U32;
  u32 EndAddress_U32;
}tForbidAddrAccess;


/*-------------------------------------------------------------------------------*/
/* - Private Variables                                                           */
/* This array contains all forbidden address to access */
const tForbidAddrAccess FlsForbidAddr_AT[] =
{
/*  StartAddress_U32    EndAddress_U32 */
/* Sector 0 shall not be access because of CENSORSHIP area. Please refer to "33.4.1 Flash configuration field description" of S32K1xx Reference Manual*/
  { 0x00000000,         0x00000FFF},
};

/*-------------------------------------------------------------------------------*/
/* - Private Macros                                                              */


/*-------------------------------------------------------------------------------*/
/* - Private Function Prototypes                                                 */
/*Prototype of the Fls_InitStructure function */
NCS_PRI_FCT bool Fls_InitStructure(void* FlsStruct_T, uint32 FlsSize_U32);

/*Prototype of the Fls_CopyDatas function */
NCS_PRI_FCT void Fls_CopyDatas(const u8* FlsSourceData_U8P,
                               u8* FlsDestinationData_U8P,
                               u32 FlsNbBytes_U32);


/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */
/*Define FlsStatus structure*/
tFLS_Status FLS_Status_T;

/*Define FLS_EraseSector structure*/
tEraseSector_Infos FLS_EraseSector_Infos;

/*Define FLS_ProgramPhrase structure*/
tProgramPhrase_Infos FLS_ProgramPhrase_Infos;

/*-------------------------------------------------------------------------------*/
/* - Public Function Prototypes                                                  */


/*-------------------------------------------------------------------------------*/
/* - Public Callback Prototypes                                                  */

/*                                                                               */
/*===============================================================================*/

/*                                                                               */
/*===============================================================================*/

/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Private Functions                                                            */
NCS_PRI_FCT bool Fls_InitStructure(void* FlsStruct_T, uint32 FlsSize_U32)
{
  bool Returned_B;
  	u32 i_U32 = 0x00000000;
  u8* Fls_U8P = (u8*)(FlsStruct_T);
  
  /*Check if the tFLS_Status respect an alignment on 4 bytes*/
  if((FlsSize_U32%0x04) == 0x00)
  {
    /* For all bytes of the tFlsStatus structure */

    for(i_U32 = 0x00000000; i_U32 < FlsSize_U32; i_U32++)
    {
      /* Reset the correspondant byte */
      /* Deviation MISRA-1,MISRA-7 */
      *(Fls_U8P + i_U32) = (u8)(0x00);
    }

    /*Set to true the returned value*/
    Returned_B = TRUE;
  }
  else
  {
    /*Set to false the returned value*/
    Returned_B = FALSE;
  }

  /*Return false*/
  return(Returned_B);
}


NCS_PRI_FCT void Fls_CopyDatas(const u8* FlsSourceData_U8P, u8* FlsDestinationData_U8P, u32 FlsNbBytes_U32)
{
  /* Copy from source address to destination address */
  u32 i_U32 = 0x00000000;
  for(i_U32 = 0x00000000; i_U32 < FlsNbBytes_U32; i_U32++)
  {
    /* Retrieve the ID the frame */
    FlsDestinationData_U8P[i_U32] = FlsSourceData_U8P[i_U32];
  }
}


/*-------------------------------------------------------------------------------*/
/* - Public Functions                                                            */
/*-------------------------------{FLS_Init}--------------------------------*/
void FLS_Init(void)
{
  /*Declare local variable*/
  u8 Fls_Status_U8;
  
  /*Initialise the FLS_Status_T structure*/
  Fls_Status_U8 = (u8)(Fls_InitStructure(&FLS_Status_T, sizeof(tFLS_Status)));
  FLS_Status_T.IsUnalignedFLSStatus_BF1 = ~Fls_Status_U8;

  /*Initialise the FLS_Status_T structure*/
  Fls_Status_U8 = (u8)(Fls_InitStructure(&FLS_EraseSector_Infos, sizeof(tEraseSector_Infos)));
  FLS_Status_T.IsUnalignedEraseSectorInfos_BF1 = ~Fls_Status_U8;

  /*Initialise the FLS_Status_T structure*/
  Fls_Status_U8 = (u8)(Fls_InitStructure(&FLS_ProgramPhrase_Infos, sizeof(tProgramPhrase_Infos)));
  FLS_Status_T.IsUnalignedProgramPhraseInfos_BF1 = ~Fls_Status_U8;

  /*Retrieve the low layer APIs flash code size*/
  /* Deviation MISRA-3,MISRA-4,MISRA-5 */
  FLS_Status_T.CodeSize_U16 = (u16)(mFLSGetSectionSize(ROM));

  /*Set the low layer APIs Flash ROM pointer on the dedicated section*/
  /* Deviation MISRA-3,MISRA-6 */
  FLS_Status_T.ROMStartAddr_U32 = (u32)(mFLSGetSectionAddr(ROM,START));

  /*Set the low layer APIs Flash RAM pointer on the dedicated section*/
  /* Deviation MISRA-3,MISRA-6 */
  FLS_Status_T.RAMStartAddr_U32 = (u32)(mFLSGetSectionAddr(RAM,START));

  /*Copy the whole "Flash_API_ROM" ROM section to "Flash_API_RAM" RAM section*/
  /* Deviation MISRA-6 */
  Fls_CopyDatas((u8*)(FLS_Status_T.ROMStartAddr_U32),
  /* Deviation MISRA-6 */
                (u8*)(FLS_Status_T.RAMStartAddr_U32),
                (u32)(FLS_Status_T.CodeSize_U16));

  /*Set the RAM pointer function which shall point on the image's code of FLS_EraseSector function into the RAM*/
  /* Deviation MISRA-3,MISRA-6 */
  FLS_Status_T.EraseSectorCbInRAM = mFLSComputeFctAddrInRAM(FLS_EraseSector);

  /*Set the RAM pointer function which shall point on the image's code of FLS_ProgramPhrase function into the RAM*/
  /* Deviation MISRA-3,MISRA-6 */
  FLS_Status_T.ProgramPhraseCbInRAM = mFLSComputeFctAddrInRAM(FLS_ProgramPhrase);

#ifdef FLASH_OPERATION_CBK
  /*Set the RAM pointer function which shall point on the image's code of ProgramPhraseCbInRAM function into the RAM*/
  /* Deviation MISRA-3,MISRA-6 */
  FLS_Status_T.FLASH_OperationCbkCbInRAM = mFLSComputeFctAddrInRAM(FLASH_OperationCbk);
#endif

  /* Set the FLS driver initialization to true */
  FLS_Status_T.IsInitialized_BF1 = TRUE;  
}
/*--------------------------------{end FLS_Init}---------------------------*/

/*-------------------------------{FLS_Start}--------------------------------*/
void FLS_Start(void)
{
  /* Set the FLS driver start to true  */
  FLS_Status_T.IsStarted_BF1 = TRUE;
}
/*--------------------------------{end FLS_Start}---------------------------*/

/*-------------------------------{FLS_Stop}--------------------------------*/
void FLS_Stop(void)
{
  /* Set the FLS driver start to false */
  FLS_Status_T.IsStarted_BF1 = FALSE;

  /* Set the FLS driver initialization to false */
  FLS_Status_T.IsInitialized_BF1 = FALSE;
}
/*--------------------------------{end FLS_Stop}---------------------------*/

#define FLASH_FLS_START_SEC_CODE
#include <MemMap.h>
/*----------------------------{FLS_EraseSector}----------------------------*/
tFlashStatus FLS_EraseSector(u16 SectorNb_U16)
{
  /* Declare local variable */
  u32 SectorToAddress_U32 = 0x00000000;
  u16 i_U16 = 0x0000;
  tFlashStatus eStatus;

  /* If the FLS driver is initialized and started */
  if((FLS_Status_T.IsInitialized_BF1 == TRUE) && (FLS_Status_T.IsStarted_BF1 == TRUE))
  {
    /* Set the FLS driver busy to true */
    FLS_Status_T.IsBusy_BF1 = TRUE;

    /* Set the FLS driver operation to EraseSector */
    FLS_Status_T.OperationInProgress = EraseSector;

    /* Retrieve SectorNb_U16 info */
    FLS_EraseSector_Infos.SectorNb_U16 = SectorNb_U16;

    /* Check if the sector number exists */
    if(SectorNb_U16 < FEATURE_FLS_PF_NB_OF_BLOCK_SECTORS)
    {
      /*Retrieve the PFlash start address to erase according the sector number*/
      /* Deviation MISRA-2 */
      SectorToAddress_U32 = (u32)(mFLSSectorToAddress(SectorNb_U16));

      /* Store the SectorToAddress_U32 info */
      FLS_EraseSector_Infos.SectorToAddress_U32 = SectorToAddress_U32;

      /* For each range address which are forbidden to access */
      for(i_U16 = 0x0000; i_U16 < (sizeof(FlsForbidAddr_AT)/sizeof(tForbidAddrAccess)); i_U16++)
      {
        /* If the SectorToAddress_U32 is into a forbidden range to access */
        if((FlsForbidAddr_AT[i_U16].StartAddress_U32 <= SectorToAddress_U32) && (SectorToAddress_U32 <= FlsForbidAddr_AT[i_U16].EndAddress_U32))
        {
          /* Check if the address to access is allowed */
          FLS_Status_T.IsAttemptEraseForbidSector_BF1 = TRUE;
        }
      }

      /* If the sector to erase is allowed */
      if(FLS_Status_T.IsAttemptEraseForbidSector_BF1 == FALSE)
      {
        /* Call the Flash operation callback in order to release cpu time to the system */
        do
        {
#ifdef FLASH_OPERATION_CBK
          FLS_Status_T.FLASH_OperationCbkCbInRAM();
#endif
        }
        /* Wait while the flash operation is in progress */
        /* Deviation MISRA-6 */
        while(mFLSWaitOperationInProgress());

        /* Clear needed flags */
        /* Deviation MISRA-6 */
        mFLSClearFlags();

        /* Erase flash sector by address */
        /* Deviation MISRA-6 */
        mFLSEraseSectorByAddr(SectorToAddress_U32);

        /* Launch command */
        /* Deviation MISRA-6 */
        mFLSLaunchCommand();

        /* Call the Flash operation callback in order to release cpu time to the system */
        do
        {
#ifdef FLASH_OPERATION_CBK
          FLS_Status_T.FLASH_OperationCbkCbInRAM();
#endif
        }
        /* Wait while the flash operation is in progress */
        /* Deviation MISRA-6 */
        while(mFLSWaitOperationInProgress());

        /* Retrieve Flash driver error status */
        /* Deviation MISRA-2,MISRA-6 */
        FLS_Status_T.IsErrorOnFLSDriver_BF1 = mFLSIsRegisterError();
      }
    }
    else
    {
      /* Set the status of an erasing attempt of forbid sector */
      FLS_Status_T.IsAttemptEraseUnexistSector_BF1 = TRUE;
    }
  }

  /* Set the FLS driver busy to false */
  FLS_Status_T.IsBusy_BF1 = FALSE;

  /* Set the FLS driver operation to "None" */
  FLS_Status_T.OperationInProgress = None;

  /* If the caller try to erase an unexist sector OR try to erase a forbiden sector */
  if((FLS_Status_T.IsAttemptEraseUnexistSector_BF1 == TRUE) ||
     (FLS_Status_T.IsAttemptEraseForbidSector_BF1 == TRUE))
  {
    /* return no error status */
    eStatus = FLASH_SECTOR_ERROR;
  }
  /* If a error has been catch by the HW flash driver */
  else if(FLS_Status_T.IsErrorOnFLSDriver_BF1 == TRUE)
  {
    /* return access error */
    eStatus = FLASH_ACCESS_ERROR;
  }
  /* No error */
  else
  {
    /* return no error status */
    eStatus = FLASH_NO_ERROR;
  }
  
  /* return no error status */
  return(eStatus);  
}
/*--------------------------------end FLS_EraseSector-----------------------*/
#define FLASH_FLS_STOP_SEC_CODE
#include <MemMap.h>

#define FLASH_FLS_START_SEC_CODE
#include <MemMap.h>
/*---------------------------{FLASH_ProgramPhrase}-----------------------------*/
tFlashStatus FLS_ProgramPhrase(tFlashAddress uAddr,
                               u16 uwLen,
                               const u8 FLASH_FAR_POINTER aubData)
{
  /* Declare local variables */
  u8 i_U8=0x00; /*Used by mFLSProgramPhrase macro*/
  tFlashStatus eStatus;

  /* If the FLS driver is initialized and started */
  if((FLS_Status_T.IsInitialized_BF1 == TRUE) && (FLS_Status_T.IsStarted_BF1 == TRUE))
  {
    /*Set the status of FLS driver busy*/
    FLS_Status_T.IsBusy_BF1 = TRUE;

    /* Set the FLS driver operation to ProgramPhrase */
    FLS_Status_T.OperationInProgress = ProgramPhrase;

    /*Check if the address to program is aligned to a page size*/
    if((uAddr%FEATURE_FLS_PF_BLOCK_WRITE_UNIT_SIZE) == 0x00)
    {
      /* Set the address to program into the FLS_ProgramPhrase_Infos */
      FLS_ProgramPhrase_Infos.AddrToProgram_U32 = uAddr;

      /*Check if the lenght of data to program is a factor of the page size*/
      if((uwLen%FEATURE_FLS_PF_BLOCK_WRITE_UNIT_SIZE) == 0x00)
      {
        /* Set the lenght of data to program into the FLS_ProgramPhrase_Infos */
        FLS_ProgramPhrase_Infos.LenghtData_U16 = uwLen;

        /*Ckeck if the source pointer data is not null*/
        if(aubData != NULL)
        {
          /* Set the pointer of data to program into the FLS_ProgramPhrase_Infos */
          FLS_ProgramPhrase_Infos.DataToProgram_U8P = (const u8*)(aubData);

          /* Call the Flash operation callback in order to release cpu time to the system */
          do
          {
#ifdef FLASH_OPERATION_CBK
            FLS_Status_T.FLASH_OperationCbkCbInRAM();
#endif
          }
          /* Wait while the flash operation is in progress */
          /* Deviation MISRA-6 */
          while(mFLSWaitOperationInProgress());

          /* Clear needed flags */
          /* Deviation MISRA-6 */
          mFLSClearFlags();

          /* Program phrase */
          /* Deviation MISRA-6 */
          mFLSProgramPhrase(uAddr,aubData);

          /* Launch command */
          /* Deviation MISRA-6 */
          mFLSLaunchCommand();

          /* Call the Flash operation callback in order to release cpu time to the system */
          do
          {
#ifdef FLASH_OPERATION_CBK
            FLS_Status_T.FLASH_OperationCbkCbInRAM();
#endif
          }
          /* Wait while the flash operation is in progress */
          /* Deviation MISRA-6 */
          while(mFLSWaitOperationInProgress());

          /* Retrieve Flash driver error status */
          /* Deviation MISRA-6 */
          FLS_Status_T.IsErrorOnFLSDriver_BF1 = mFLSIsRegisterError();
        }
        else
        {
          /* Set the flag of uninitialize pointer of data to program to true */
          FLS_Status_T.IsUninitializePointerDataToProgram_BF1 = TRUE;
        }
      }
      else
      {
        /* Set the flag of lenght data to program unaligned to true */
        FLS_Status_T.IsAttemptProgramUnalignedLenght_BF1 = TRUE;
      }
    }
    else
    {
      /* Set the flag of unaligned page programming attempt to true */
      FLS_Status_T.IsAttemptProgramUnalignedPage_BF1 = TRUE;
    }
  }

  /*Set the status of FLS driver not busy*/
  FLS_Status_T.IsBusy_BF1 = FALSE;

  /* Set the FLS driver operation to "None" */
  FLS_Status_T.OperationInProgress = None;

  /* If the caller try to program an unaligned page
  * OR
  * Try to program an unaligned lenght
  * OR
  * The pointer data source to program is not initialise
  */
  if((FLS_Status_T.IsAttemptProgramUnalignedPage_BF1 == TRUE) ||
     (FLS_Status_T.IsAttemptProgramUnalignedLenght_BF1 == TRUE) ||
     (FLS_Status_T.IsUninitializePointerDataToProgram_BF1 == TRUE))
  {
    /* return page error status */
    eStatus = FLASH_PAGE_ERROR;
  }
  /* No error */
  else
  {
    /* return no error status */
    eStatus = FLASH_NO_ERROR;
  }
  
  /* return no error status */
  return(eStatus);
}
#define FLASH_FLS_STOP_SEC_CODE
#include <MemMap.h>
/*---------------------------{End FLASH_ProgramPhrase}-----------------------------*/

/* CHECK: PARSE (turn off the CheckC coverage because of some tests can not be covered*/
/* CHECK: RULE 506 ON */
/* CHECK: RULE 306 ON */
/* CHECK: RULE 205 ON */
/* CHECK: RULE 203 ON */
/* CHECK: RULE 502 ON */

