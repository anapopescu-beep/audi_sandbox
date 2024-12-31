/* CHECK: RULE 502 OFF */
/* CHECK: RULE 203 OFF */
/* CHECK: RULE 501 OFF */
/* CHECK: RULE 505 OFF */
/* CHECK: RULE 506 OFF */
/* CHECK: RULE 205 OFF */

#ifndef FLS_S32K14X_H
#define FLS_S32K14X_H

/*
===============================================================================

                               BOOT layers

 -----------------------------------------------------------------------------

                                 FLASH configuration

===============================================================================
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%   _____________________________   %%  File: FLS_S32K14X.h
%%  |                             |  %%  Purpose: FLASH Driver APIs
%%  |   &&&&&   &&&&&             |  %%  Module version: 7.0.2
%%  |   &       &    &            |  %%  Target: CORTEXM
%%  |   &&&&    &&&&&             |  %%  Derivate: S32K14X
%%  |   &       &    &            |  %%  Variant: OsekCore
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
 *  MISRA-1) Deviated Rule: 6.4 (required)
 *   "Bit fields shall only be defined to be of type unsigned int or signed int."
 *
 *   Reason:
 *   The structure works by 8bits and not 16bits.
 *
 *  MISRA-2) Deviated Rule: 8.9 (required)
 *   "An identifier with external linkage shall have exactly one external definition."
 *
 *   Reason:
 *   The declaration of the variable come from the linker file through label. 
 *
 *  MISRA-3) Deviated Rule: 19.13 (advisory)
 *   "The # and # preprocessor operators should not be used."
 *
 *   Reason:
 *   In order to have flexible code, we need to use the # operator.
 *
 *  MISRA-4) Deviated Rule: 19.12 (required)
 *   "There shall be at most one occurrence of the # or # preprocessor operators in a single macro definition."
 *
 *   Reason:
 *   In order to have flexible code, we need to use the ## operator.
 */

/*============================= FILE INCLUSION ==================================*/
/* Header files */
#include "FLASH_Types.h"

/*===============================================================================*/

/*============================= PUBLIC DEFINITIONS ==============================*/


/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Types                                                                */
/*Define bool type */
typedef u8 bool;

/* Enum flash operations */
typedef enum
{
  None, /*"None" shall be in the first enumerate position*/
  EraseSector,
  ProgramPhrase
} eFLS_Operations;

/***************************************/
/*Declare the typedef pointer functions*/
/***************************************/
/*Declare the typedef pointer function with the signature of FLS_EraseSector function*/
typedef
  tFlashStatus (*tFLS_EraseSectorCbInRAM) (u16 ulSectorNo);

/*Declare the typedef pointer function with the signature of FLS_ProgramPhrase function*/
typedef
  tFlashStatus (*tFLS_ProgramPhraseCbInRAM) (tFlashAddress uAddr,
                                     u16 uwLen,
                                     const u8 FLASH_FAR_POINTER aubData);

/*Declare the typedef pointer function with the signature of FLS_ProgramPhrase function*/
typedef
  void (*tFLASH_OperationCbkCbInRAM) (void);

/*Declare a structure which contains EraseSector information*/
typedef struct
{
  /* Byte [0:1] */
  u16 SectorNb_U16; /* Sector number to erase */

  /* Byte [2:3]*/
  /* Deviation MISRA-1 */
  u8 Unused_Byte2_BF0_7: 8;
  /* Deviation MISRA-1 */
  u8 Unused_Byte3_BF0_7: 8;

  /* Byte [4:7]*/
  u32 SectorToAddress_U32; /* Convertion from sector number to address */
}tEraseSector_Infos; /* Be careful!!! you have to respect an alignment on 4 bytes */


/*Declare a structure which contains ProgramPhrase information*/
typedef struct
{
  /* Byte [0:3]*/
  u32 AddrToProgram_U32; /* Page address to program */

  /* Byte [4:5]*/
  u16 LenghtData_U16; /* Lenght of data to program */

  /* Byte [6:7]*/
  /* Deviation MISRA-1 */
  u8 Unused_Byte6_BF0_7: 8;
  /* Deviation MISRA-1 */
  u8 Unused_Byte7_BF0_7: 8;

  /* Byte [8:11]*/
  /* Deviation MISRA-1 */
  const u8* DataToProgram_U8P; /* Pointer on the data to program */
}tProgramPhrase_Infos; /* Be careful!!! you have to respect an alignment on 4 bytes */


/****************************************/
/*Declare the general FLS status typedef*/
/****************************************/
typedef struct
{
  /* Byte [0]*/
  /* Deviation MISRA-1 */
  bool IsInitialized_BF1: 1; /* Status of FLS driver initialization*/
  /* Deviation MISRA-1 */
  bool IsStarted_BF1: 1; /* Status of FLS driver start*/
  /* Deviation MISRA-1 */
  bool IsBusy_BF1: 1; /* Status of FLS driver busy*/
  /* Deviation MISRA-1 */
  bool IsUnalignedFLSStatus_BF1: 1; /* Status of FLS driver structure is unaligned */
  /* Deviation MISRA-1 */
  bool IsUnalignedEraseSectorInfos_BF1: 1; /* Status of EraseSectorInfos structure is unaligned*/
  /* Deviation MISRA-1 */
  bool IsUnalignedProgramPhraseInfos_BF1: 1; /* Status of ProgramPhraseInfos structure is unaligned */
  /* Deviation MISRA-1 */
  bool IsAttemptEraseForbidSector_BF1 :1; /* Status of an erasing attempt of forbid sector */
  /* Deviation MISRA-1 */
  bool IsAttemptEraseUnexistSector_BF1 :1; /* Status of an erasing attempt of unexist sector */

  /* Byte [1]*/
  /* Deviation MISRA-1 */
  bool IsAttemptProgramUnalignedPage_BF1 :1; /* Status of a program attempt of unaligned page */
  /* Deviation MISRA-1 */
  bool IsAttemptProgramUnalignedLenght_BF1 :1; /* Status of a program attempt of unaligned lenght */
  /* Deviation MISRA-1 */
  bool IsUninitializePointerDataToProgram_BF1 :1; /* Status of uninitialize pointer of data to program */
  /* Deviation MISRA-1 */
  bool IsErrorOnFLSDriver_BF1 :1; /* Status of error on Flash driver */
  /* Deviation MISRA-1 */
  u8 Unused_Byte1_BF4_7: 4;

  /* Byte [2:3]*/
  u16 CodeSize_U16; /* Status of FLS code size */

  /* Byte [4:7]*/
  u32 ROMStartAddr_U32; /* FLS ROM start code address */

  /* Byte [8:11]*/
  u32 RAMStartAddr_U32; /* FLS RAM start code address */

  /* Byte [12:15]*/
  tFLS_EraseSectorCbInRAM EraseSectorCbInRAM;

  /* Byte [16:19]*/
  tFLS_ProgramPhraseCbInRAM ProgramPhraseCbInRAM;

  /* Byte [20:23]*/
  tFLASH_OperationCbkCbInRAM FLASH_OperationCbkCbInRAM;

  /* Byte [24:27]*/
  eFLS_Operations OperationInProgress; /*(from eFLS_Operations)*/
}tFLS_Status; /* Be careful!!! you have to respect an alignment on 4 bytes */


/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */
/*ROM*/
/* Deviation MISRA-2 */
extern u32 __Flash_API_ROM_SECTION_START_ADDR;
/* Deviation MISRA-2 */
extern u32 __Flash_API_ROM_SECTION_END_ADDR;

/*RAM*/
/* Deviation MISRA-2 */
extern u32 __Flash_API_RAM_SECTION_START_ADDR;
/* Deviation MISRA-2 */
extern u32 __Flash_API_RAM_SECTION_END_ADDR;

/*Global FLS status structure info*/
extern tFLS_Status FLS_Status_T;

/*Global FLS_EraseSector function structure info*/
extern tEraseSector_Infos FLS_EraseSector_Infos;

/*Declare variable into desired section*/
#define mFLSUseSection(Sectionname)         __attribute__((section (Sectionname)))

/*Retrieve the desired address of the desired memory*/
/* Deviation MISRA-3,MISRA-4 */
#define mFLSGetSectionAddr(type,side)               (u32)((u8*)(&__Flash_API_##type##_SECTION_##side##_ADDR))

/*Retrieve a flash section size*/
/* Deviation MISRA-3,MISRA-4 */
#define mFLSGetSectionSize(type)     ((u32)(((u8*)(&__Flash_API_##type##_SECTION_END_ADDR)) - ((u8*)(&__Flash_API_##type##_SECTION_START_ADDR)) + 1))

/*Retrieve the pointer type function according the function name*/
/* Deviation MISRA-3,MISRA-4 */
#define mFLSGetPointerTypeFctInRAM(romfct)      t##romfct##CbInRAM

/*
*Compute the RAM image function address according the ROM function address
*Formula:
*<FctAddrInRAM> = __Flash_API_RAM_SECTION_START_ADDR + (<FctAddrInROM> - __Flash_API_ROM_SECTION_START_ADDR)
*Finally, we have to cast the computed address according the right function pointer type
*/
#define mFLSComputeFctAddrInRAM(romfct)   (mFLSGetPointerTypeFctInRAM(romfct))\
                                          ((u32)(mFLSGetSectionAddr(RAM,START)) +\
                                           ((u32)(&(romfct)) - (u32)(mFLSGetSectionAddr(ROM,START))))

/*Macro which convert a sector to address */
#define mFLSSectorToAddress(Sector)       (FEATURE_FLS_PF_START_ADDRESS + (FEATURE_FLS_PF_BLOCK_SECTOR_SIZE * (Sector)))


/*Macro which enables to wait while a flash operation is in progress */
#define mFLSWaitOperationInProgress()      ((FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK) == 0)

/*Macro whic enables to clear the ACCERR/FPVIOL flags */
#define mFLSClearFlags()     FTFC->FSTAT = FTFC_FSTAT_ACCERR_MASK | FTFC_FSTAT_FPVIOL_MASK


/*Define of flash commands */
#define cFLSCmdEraseSector_U8     (u8)(0x09)
#define cFLSCmdProgramPhrase_U8   (u8)(0x07)

/* Macro which enables to set the address to access through the flash registers
*FTFC->FCCOB[2] = Flash address [23:16]
*FTFC->FCCOB[1] = Flash address [15:08]
*FTFC->FCCOB[0] = Flash address [7:0]
*/
#define  mFLSSetFlashAddressToAccess(Address)      FTFC->FCCOB[2] = (u8)((Address)>>16);\
                                                   FTFC->FCCOB[1] = (u8)((Address)>>8);\
                                                   FTFC->FCCOB[0] = (u8)((Address)>>0)

/*Macro which enables to perform the erasing task */
#define mFLSEraseSectorByAddr(Address)             FTFC->FCCOB[3] = cFLSCmdEraseSector_U8;\
                                                   mFLSSetFlashAddressToAccess((Address))


/*Macro which enables to perform the programming phrase task */
#define mFLSProgramPhrase(Address,PointerData)     FTFC->FCCOB[3] = cFLSCmdProgramPhrase_U8;\
                                                   mFLSSetFlashAddressToAccess((Address));\
                                                   for(i_U8 = 0; i_U8 <8 ;i_U8++)\
                                                   {\
                                                     FTFC->FCCOB[0x04 + i_U8] = (PointerData)[i_U8];\
                                                   }

/*Macro which enables to launch the flash command */
#define mFLSLaunchCommand()                        FTFC->FSTAT = FTFC_FSTAT_CCIF_MASK

/*Macro which enables to check if there is an error on the Flash driver */
#define mFLSIsRegisterError()                      (((FTFC->FSTAT &\
                                                   (FTFC_FSTAT_MGSTAT0_MASK | FTFC_FSTAT_FPVIOL_MASK | FTFC_FSTAT_ACCERR_MASK | FTFC_FSTAT_RDCOLERR_MASK)) != 0U) ? (TRUE) : (FALSE))

/*-------------------------------------------------------------------------------*/
/* - Public Function Prototypes                                                  */
/** \brief Initialisation of the FLS driver
 **
 ** This function allows to initialise the FLS driver
 **
 ** \return Result of operation
 **
 **
 **/
extern void FLS_Init(void);

/** \brief Start of the FLS driver
 **
 ** This function allows to start the FLS driver
 **
 ** \return Result of operation
 **
 **
 **/
extern void FLS_Start(void);


/** \brief Stop of the FLS driver
 **
 ** This function allows to stop the FLS driver
 **
 ** \return Result of operation
 **
 **
 **/
extern void FLS_Stop(void);


/** \brief Erase flash sector
 **
 ** This function allows to erase a flash sector
 **
 ** \param[in] SectorNb_U16 Sector number to erase
 **
 ** \return Result of operation
 **
 **
 **/
extern tFlashStatus FLS_EraseSector(u16 SectorNb_U16);

/** \brief Program flash phrase
 **
 ** This function allows to program the flash with a number of bytes from 1 to 8
 **
 ** \param[in] uAddr Sector address to program
 ** \param[in] uwLen Number of bytes to program (from 1 to 8)
 ** \param[in] aubData Pointer on bytes to program
 **
 ** \return Result of operation
 **
 **
 **/
extern tFlashStatus FLS_ProgramPhrase(tFlashAddress uAddr,
                                      u16 uwLen,
                                      const u8 FLASH_FAR_POINTER aubData);


/* - Public Callback Prototypes                                                  */

/*                                                                               */
/*===============================================================================*/



#endif      /* FLASH_FLS_H */

/* CHECK: RULE 205 ON */
/* CHECK: RULE 506 ON */
/* CHECK: RULE 505 ON */
/* CHECK: RULE 501 ON */
/* CHECK: RULE 203 ON */
/* CHECK: RULE 502 ON */
