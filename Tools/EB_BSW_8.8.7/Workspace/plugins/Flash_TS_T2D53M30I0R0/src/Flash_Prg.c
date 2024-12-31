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
/*%%   _____________________________   %%  \file Flash_Prg.c                  */
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
#include "EB_Prj.h"
#include "FlashWrapper.h"

typedef struct
{
  eFlashRequest Request;
  eFlashStatus JobStatus;
  uint32 StartAddress;
  uint32 EndAddress;
  uint32 Length;
  uint32 AddressToTreat;
  uint32 AddressTreated;
  uint32 NbOfPagesToWrite;
  uint8* PtrData;
}tFlashMainFunction;


typedef struct
{
  uint32 StartAddress;
  uint32 Length;
  uint32 SectorSize;
  uint32 EndAddress;
  uint32 Element;
}tFlashTableInfo;

typedef struct
{
  uint32 NbElements;
  uint32 Elements[FLASH_SECTORS_TABLE_NB_ELEMENTS];
}tFlashFilteredElements;

/*Local prototypes*/
STATIC boolean Flash_IsAddressAlignedOnSector(uint32 uAddr);
STATIC boolean Flash_IsSectorsProgrammable(uint32 Address, 
                                           uint32 length);
STATIC boolean Flash_IsRangeAddressAllowed(uint32 Address, 
                                           uint32 length);
STATIC eFlashStatus Flash_MainFunctionMngt(void);
STATIC eFlashStatus Flash_MainFunctionErasingMngt(void);
STATIC eFlashStatus Flash_MainFunctionWritingMngt(void);
STATIC eFlashStatus Flash_MainFunctionReadingMngt(void);
STATIC eFlashStatus Flash_GetTableInfoByAddress(uint32 Address, 
                                                tFlashTableInfo* GetTableInfo);
STATIC eFlashStatus Flash_GetFilteredElements(uint32 Address,
                                              uint32 length, 
                                              tFlashFilteredElements* FilteredElements);
STATIC void Flash_MainFunctionSetInfo(uint32 uAddr, 
                                      uint32 uwLen,
                                      uint8* aubData,
                                      eFlashRequest Request);                                              

/*Local variables*/
STATIC tFlashMainFunction Flash_MainFunctionStatus;
STATIC uint8 DataToWrite[FLASH_PAGE_SIZE];

/*----------------------------{Flash_IsSectorsProgrammable}---------------------*/
STATIC boolean Flash_IsSectorsProgrammable(uint32 Address, uint32 length)
{
  /*Declare local variable*/
  boolean RetBoolVal = FLASH_FALSE;
  uint32 Loop;
  uint32 Loc_Element;
  tFlashFilteredElements LocFilteredElements;

  /*Get the useful table info elements*/ 
  if(FLASH_NO_ERROR == Flash_GetFilteredElements(Address, length, &LocFilteredElements))
  {
    /*Set the returned value as TRUE*/
    RetBoolVal = FLASH_TRUE;
    
    /*For each element which belong to range address*/
    for(Loop=(uint32)(0x0);
        Loop<LocFilteredElements.NbElements;
        Loop++)
    {
      /*Get the element from Flash_CandidateElementsTableInfo*/
      Loc_Element = LocFilteredElements.Elements[Loop];
    
      /*Check if the memory sectors are programmable*/
      if(FLASH_FALSE == FlashSectorsTable[Loc_Element].Programmable)
      {
        /*The sectors are not programmable*/
        RetBoolVal = FLASH_FALSE;
    
        /*Break the loop*/
        Loop = LocFilteredElements.NbElements;
      }
    }    
  }
  
  /*Return sector programmable status*/
  return(RetBoolVal);
}
/*----------------------------{End Flash_IsSectorsProgrammable}---------------------*/

/*----------------------------{Flash_IsAddressAlignedOnSector}---------------------*/
STATIC boolean Flash_IsAddressAlignedOnSector(uint32 Address)
{
  /*Declare local variable*/
  boolean RetBoolVal = FLASH_FALSE;
  tFlashTableInfo TableInfo;
  
  /*Get table info by address*/
  if(FLASH_NO_ERROR == Flash_GetTableInfoByAddress(Address,&TableInfo))
  {
    /*Check if the address is aligned on a sector address*/
    if((((uint32)(TableInfo.StartAddress - Address)) % TableInfo.SectorSize) == (uint32)(0x00))
    {
      /*Address is aligned on a sector address*/
      RetBoolVal = FLASH_TRUE;
    }
  }
   
  /*Return address sector alignment status*/
  return(RetBoolVal);
}
/*----------------------------{End Flash_IsAddressAlignedOnSector}-----------------*/

/*----------------------------{Flash_IsAddressAlignedOnPage}---------------------*/
STATIC boolean Flash_IsAddressAlignedOnPage(uint32 Address)
{
  /*Declare local variable*/
  boolean RetBoolVal = FLASH_FALSE;
  
  /*Check if the address is aligned on a page address*/
  if(Address%(uint32)(FLASH_PAGE_SIZE) == (uint32)(0x00))
  {
    /*Address is aligned on a page address*/
    RetBoolVal = FLASH_TRUE;
  }
   
  /*Return address page alignment status*/
  return(RetBoolVal);
}
/*----------------------------{End Flash_IsAddressAlignedOnPage}-----------------*/

/*----------------------------{End Flash_IsRangeAddressAllowed}-----------------*/
STATIC boolean Flash_IsRangeAddressAllowed(uint32 Address, uint32 length)
{
  /*Declare local variables*/
  boolean RetBoolVal = FLASH_FALSE;
  uint32 Loop;
  uint32 LocTableInfo_StartAddress;
  uint32 LocTableInfo_EndAddress;
  uint32 LocTableInfo_length = 0x00;
  uint32 LocEndAddress;
  
  /*If the length is null*/
  if((uint32)(0x00) == length)
  {
    /*Set the EndAddress to StartAddress*/
    LocEndAddress = Address;
  }
  else
  {
    /*Compute the requested end address*/
    LocEndAddress = Address +
                   (uint32)(length) - 
                   (uint32)(1U);
  }
  
  /*Get the first TableInfo StartAddress*/
  LocTableInfo_StartAddress = FlashSectorsTable[0].StartAddress;
  
  /*For each FlashSectorsTable element*/
  for(Loop=(uint32)(0x0); 
      Loop<FLASH_SECTORS_TABLE_NB_ELEMENTS;
      Loop++)
  {
    /*Compute the whole configured flash size*/
    LocTableInfo_length += FlashSectorsTable[Loop].Length;
  }
  
  /*Compute the configured end address*/
  LocTableInfo_EndAddress = LocTableInfo_StartAddress + 
                            (uint32)(LocTableInfo_length) - 
                            (uint32)(1U);
                            
  /*Check if the requested start address is into the configured flash area*/
  if((LocTableInfo_StartAddress <= Address) && (Address <= LocTableInfo_EndAddress))
  {
    /*Check if the requested end address is into the configured flash area*/
    if((LocTableInfo_StartAddress <= LocEndAddress) && (LocEndAddress <= LocTableInfo_EndAddress))
    {
      /*The requested range address is allowed*/
      RetBoolVal = FLASH_TRUE;
    }
  }
  
  /*Return range address allowing status*/
  return(RetBoolVal);
}
/*----------------------------{End Flash_IsRangeAddressAllowed}-----------------*/

/*----------------------------{Flash_GetFilteredElements}-------------------------*/
STATIC eFlashStatus Flash_GetFilteredElements(uint32 StartAddress,
                                              uint32 length, 
                                              tFlashFilteredElements* FilteredElements)
{
  /*Declare local variables*/
  eFlashStatus RetVal = FLASH_NO_ERROR;
  uint32 Loop;
  uint32 LocTableInfo_StartAddress;
  uint32 LocTableInfo_EndAddress;
  uint32 LocTableInfo_length;
  uint32 LocEndAddress;
  uint32 LocNumElementTableInfo = 0x0;
  boolean LocIsStoreCandidateElement=FLASH_FALSE;  
  
  /*Initialization of the FilteredElements.Elements table*/
  for(Loop=(uint32)(0x0);
      Loop<FLASH_SECTORS_TABLE_NB_ELEMENTS;
      Loop++)
  {
    /*Initialize the FilteredElements.Elements table*/
    FilteredElements->Elements[Loop] = (uint32)(0xFFFFFFFF);
  }
  
  /*If the length is null*/
  if((uint32)(0x00) == length)
  {
    /*Set the EndAddress to StartAddress*/
    LocEndAddress = StartAddress;
  }
  else
  {
    /*Compute the EndAddress*/
    LocEndAddress = StartAddress +
                   (uint32)(length) - 
                   (uint32)(1U);
  }

  /*For each FlashSectorsTable element*/
  for(Loop=(uint32)(0x0); 
      Loop<FLASH_SECTORS_TABLE_NB_ELEMENTS;
      Loop++)
  {
    /*Retrieve the start address from FlashSectorsTable*/
    LocTableInfo_StartAddress = FlashSectorsTable[Loop].StartAddress;
    
    /*Retrieve the current length from FlashSectorsTable*/
    LocTableInfo_length = FlashSectorsTable[Loop].Length;
    
    /*Compute the end address from FlashSectorsTable*/
    LocTableInfo_EndAddress = LocTableInfo_StartAddress + 
                              (uint32)(LocTableInfo_length) - 
                              (uint32)(1U);
                                  
    /*If the requested range address belong to the current range address*/
    if((LocTableInfo_StartAddress <= StartAddress) && (StartAddress <= LocTableInfo_EndAddress))
    {      
      /*Set that the address is into the current range address */
      LocIsStoreCandidateElement = FLASH_TRUE;
    }
    
    /*If the requested range address is out of range */
    if(LocTableInfo_StartAddress > LocEndAddress)
    {      
      /*Set that the address is out of the current range address */
      LocIsStoreCandidateElement = FLASH_FALSE;
    }
    
    /*If the current range address need to be stored*/
    if(FLASH_TRUE == LocIsStoreCandidateElement)
    {
      /*Set the current element into ElementTableInfos */
      FilteredElements->Elements[LocNumElementTableInfo] = (uint32)(Loop);
      
      /*Increase the LocNumElementTableInfo*/
      LocNumElementTableInfo++;
    }
  }
  
  /*Set the number of filtered range address*/
  FilteredElements->NbElements = LocNumElementTableInfo;
  
  /*If no element has been found*/
  if(0x00 == LocNumElementTableInfo)
  {
    /*The range address is not allowed*/
    RetVal = FLASH_ADDR_RANGE_NOT_ALLOWED; 
  }
  
  /*Return address allow status*/
  return(RetVal);  
}
/*----------------------------{End Flash_GetFilteredElements}-------------------------*/

/*----------------------------{Flash_GetTableInfoByAddress}-------------------------*/
STATIC eFlashStatus Flash_GetTableInfoByAddress(uint32 Address, tFlashTableInfo* TableInfo)
{
  /*Declare local variable*/
  eFlashStatus RetVal = FLASH_NO_ADDR_TABLE_INFO_FOUND;
  uint32 Loop;
  uint32 LocElement;
  uint32 LocStartAddress;
  uint32 Loclength;
  uint32 LocEndAddress;
  tFlashFilteredElements LocFilteredElements;
    
  /*Retrieve the useful table info elements*/
  if(FLASH_NO_ERROR == Flash_GetFilteredElements(Address, 0x00, &LocFilteredElements))
  {
    /*For each element which belong to range address*/
    for(Loop=(uint32)(0x0);
        Loop<LocFilteredElements.NbElements;
        Loop++)
    {
      /*Get the element from LocFilteredElements*/
      LocElement = LocFilteredElements.Elements[Loop];    
    
      /*Retrieve the start address from FlashSectorsTable*/
      LocStartAddress = FlashSectorsTable[LocElement].StartAddress;  
    
      /*Retrieve the sector size*/
      Loclength = FlashSectorsTable[LocElement].Length;
      
      /*Compute the end address from FlashSectorsTable*/
      LocEndAddress = LocStartAddress + 
                      (uint32)(Loclength) - 
                      (uint32)(1U);
    
      /*If the address belong to the current Flash sector table range address*/
      if((LocStartAddress <= Address) && (Address <= LocEndAddress))
      {
        /*Retrieve the start address from FlashSectorsTable*/
        TableInfo->StartAddress = FlashSectorsTable[LocElement].StartAddress;
          
        /*Retrieve the sector size*/
        TableInfo->Length = FlashSectorsTable[LocElement].Length;
    
        /*Retrieve the sector size*/
        TableInfo->SectorSize = FlashSectorsTable[LocElement].SectorSize;        
          
        /*Compute the end address from FlashSectorsTable*/
        TableInfo->EndAddress = LocStartAddress + 
                                (uint32)(Loclength) - 
                                (uint32)(1U);
          
        /*Get the Element from FlashSectorsTable*/
        TableInfo->Element = LocElement;
        
        /*Break the loop*/
        Loop=LocFilteredElements.NbElements;
        
        /*No error*/
        RetVal = FLASH_NO_ERROR;      
      }
    }    
  }
  
  /*Return status*/
  return(RetVal);
}
/*----------------------------{End Flash_GetTableInfoByAddress}-------------------------*/

/*----------------------------{Flash_GetNextSectorAddress}---------------------*/
STATIC eFlashStatus Flash_GetNextSectorAddress(uint32 Address, uint32* NextAddress)
{
  /*Declare local variable*/
  eFlashStatus RetVal = FLASH_NO_ERROR;
  uint32 LocNextAddress;
  tFlashTableInfo LocTableInfo;
  
  /*Get the address filtered information*/
  if(FLASH_NO_ERROR == Flash_GetTableInfoByAddress(Address,&LocTableInfo))
  {
    /*Compute the next address*/
    LocNextAddress = Address + (uint32)(LocTableInfo.SectorSize);
    
    /*If the computed LocNextAddress is inferior than the current Address, so rolling back*/
    if(LocNextAddress <= Address)
    {
      /*Set the rolling back status*/
      RetVal = FLASH_ADDR_ROLLING_BACK;
    }
    
    /*If the computed LocNextAddress is superior than the related TableInfo_EndAddress, so retrieve the next Table Info element*/
    if(LocNextAddress >= LocTableInfo.EndAddress)
    {
      /*Increase the TableInfo_Element*/
      LocTableInfo.Element++;
      
      /*if the TableInfo_Element is still into the FlashSectorsTable range*/
      if(LocTableInfo.Element < FLASH_SECTORS_TABLE_NB_ELEMENTS)
      {
        /*Set the NextSector address to the next FlashSectorsTable Start Address*/
        LocNextAddress = FlashSectorsTable[LocTableInfo.Element].StartAddress;
      }
      else
      {
        /*No more element into the FlashSectorsTable*/
        RetVal= FLASH_NO_NEXT_ADDR;
      }
    }
    
    /*Set the computed Next Sector Address*/
    *NextAddress = LocNextAddress;
  }
  
  /*Return the Next sector address*/
  return(RetVal);
}
/*---------------------------{end Flash_GetNextSectorAddress}------------------*/

#if 0
/*----------------------------{Flash_GetSectorNbByAddress}---------------------*/
STATIC eFlashStatus Flash_GetSectorNbByAddress(uint32 Address, uint32* SectorNumber)
{
  /*Declare local variable*/
  eFlashStatus RetVal = FLASH_SECTOR_NB_NOT_FOUND;
  uint32 Loop;
  tFlashTableInfo LocTableInfo;
  
  /*If the SectorNumber pointer is non-null*/
  if(NULL != SectorNumber)
  {
    /*Get the address filtered information*/
    if(FLASH_NO_ERROR == Flash_GetTableInfoByAddress(Address,&LocTableInfo))
    {
      /*Compute the related sector number according the Address*/
      *SectorNumber = (uint32)(Address - LocTableInfo.StartAddress) / LocTableInfo.SectorSize;
      
      /*For each range address which exist above the current range address*/
      for(Loop=(uint32)(0x0);
          Loop<LocTableInfo.Element;
          Loop++)
      {      
        /*Add the previous range address sector number*/
        *SectorNumber += (uint32)(FlashSectorsTable[Loop].Length) / FlashSectorsTable[Loop].SectorSize;
      }
      
      /*Set the status to no error*/
      RetVal = FLASH_NO_ERROR;      
    }
  }
  
  /*Return sector number retrieved status*/
  return(RetVal);
}
/*---------------------------{end Flash_GetSectorNbByAddress}------------------*/
#endif

/*------------------------------{Flash_MainFunctionSetInfo}--------------------*/
STATIC void Flash_MainFunctionSetInfo(uint32 uAddr,
                                      uint32 uwLen, 
                                      uint8* aubData, 
                                      eFlashRequest Request)
{
  /*Declare local variable*/
  uint32 NbOfPagesToWrite;
    
  /*Set Flash_MainFunction common information*/
  Flash_MainFunctionStatus.Request = Request;
  Flash_MainFunctionStatus.JobStatus = FLASH_BUSY;
  Flash_MainFunctionStatus.StartAddress = uAddr;
  Flash_MainFunctionStatus.Length = uwLen;
  Flash_MainFunctionStatus.EndAddress = uAddr + uwLen - (uint32)(1U);
  Flash_MainFunctionStatus.AddressToTreat = uAddr;
  Flash_MainFunctionStatus.AddressTreated = (uint32)(0x00);
  
  /*Depending to the request*/
  switch(Request)
  {
    /*No request*/
    case(cNoRequest):
      /***************/
      /*Nothing to do*/
      /***************/
      break;
    
    /*Erasing request*/
    case(cErasingRequest):
      /***************/
      /*Nothing to do*/
      /***************/
      break;
    
    /*Writing request*/
    case(cWritingRequest):
      /*Compute the number of pages to write*/
      NbOfPagesToWrite = uwLen/(uint32)(FLASH_PAGE_SIZE);
      
      /*Check if the requested length is not a factor of a configured page size*/
      if((uint32)(uwLen)%(uint32)(FLASH_PAGE_SIZE) != (uint32)(0x00))
      {
        /*One more page writing is needed*/
        NbOfPagesToWrite++;
      }
      
      /*Set the Flash_MainFunctionStatus information related to the write operation*/
      Flash_MainFunctionStatus.NbOfPagesToWrite = NbOfPagesToWrite;
      Flash_MainFunctionStatus.PtrData = aubData;
      break;
    
    /*Reading request*/
    case(cReadingRequest):
      /*Set the Flash_MainFunctionStatus information related to the read operation*/
      Flash_MainFunctionStatus.PtrData = aubData;
      break;
    
    
    /*Undef request*/
    default:
      /***************/
      /*Nothing to do*/
      /***************/
      break;    
  }
}
/*---------------------------{end Flash_MainFunctionSetInfo}------------------*/

/*----------------------------{Flash_MainFunctionMngt}---------------------*/
STATIC eFlashStatus Flash_MainFunctionMngt(void)
{
  /*Declare local variables*/
  eFlashStatus RetValMain;
  eFlashStatus RetValJobStatus;
  
  /*Loop on functions to execute*/
  do
  {
    /*Call the low layer Main function*/
    RetValMain = (eFlashStatus)(FLW_MainRoutine());

    /*Call the low layer JobStatus function*/
    RetValJobStatus = (eFlashStatus)(FLW_JobStatusRoutine());
  }
  /*While a low layer action need to be done AND the low layer Main function do not throw error*/
  while((FLASH_NO_ERROR == RetValMain) && (FLASH_NO_ERROR != RetValJobStatus));

  /*Return Main function status*/
  return(RetValJobStatus);
}
/*---------------------------{end Flash_MainFunctionMngt}------------------*/

/*----------------------------{Flash_MainFunctionErasingMngt}---------------------*/
STATIC eFlashStatus Flash_MainFunctionErasingMngt(void)
{
  /*Declare local variable*/
  eFlashStatus RetVal;
  uint32 LocPhysicalToLogicalAddress;

  /*Compute the Physical to Logical address to treat*/
  RetVal = FLASH_CustomGetPhysicalToLogicalAddress(Flash_MainFunctionStatus.AddressToTreat,&LocPhysicalToLogicalAddress);

  /*Prepare the erasing of the current sector address*/
  RetVal = (eFlashStatus)(FLW_EraseRoutine(LocPhysicalToLogicalAddress,(uint32)(0x1)));

  /*If no error on the low layer Erase function execution*/
  if(FLASH_NO_ERROR == RetVal)
  {
    /*Execute the low layer main functions*/
    RetVal = Flash_MainFunctionMngt();

    /*If no error*/
    if(FLASH_NO_ERROR == RetVal)
    {
      /*Push the AddressToTreat to AddressTreated*/
      Flash_MainFunctionStatus.AddressTreated = Flash_MainFunctionStatus.AddressToTreat;
      
      /*Get the Next sector address to treat*/
      if(FLASH_NO_ERROR == Flash_GetNextSectorAddress(Flash_MainFunctionStatus.AddressTreated,
                                                      &Flash_MainFunctionStatus.AddressToTreat))
      {
        /*Check if end of erasing*/
        if(Flash_MainFunctionStatus.AddressToTreat < Flash_MainFunctionStatus.EndAddress)
        {
          /*Set the status as busy*/
          RetVal = FLASH_BUSY;
        }
        else
        {
          /*Set the status as NoError*/
          RetVal = FLASH_NO_ERROR;
        }
      }
    }
  }
  
  /*Return main function erasing status*/
  return(RetVal);
}
/*---------------------------{end Flash_MainFunctionErasingMngt}------------------*/

/*----------------------------{Flash_MainFunctionWritingMngt}---------------------*/
STATIC eFlashStatus Flash_MainFunctionWritingMngt(void)
{
  /*Declare local variable*/
  eFlashStatus RetVal = FLASH_WRITE_ERROR;
  uint32 Loop;
  uint32 NbOfBytesOnLastPage;
  uint8* PtrDataToWrite;
  uint32 LocPhysicalToLogicalAddress;
  
  /*Compute the Physical to Logical address to treat*/
  RetVal = FLASH_CustomGetPhysicalToLogicalAddress(Flash_MainFunctionStatus.AddressToTreat,&LocPhysicalToLogicalAddress);

  /*Set the local data pointer to the desired source address where are stored the data to write*/
  PtrDataToWrite = Flash_MainFunctionStatus.PtrData;
    
  /*Check if the last page will be write*/
  if(Flash_MainFunctionStatus.NbOfPagesToWrite == (uint32)(0x01))
  {
    /*Compute the number of useful bytes which will be write on the last page*/
    NbOfBytesOnLastPage = (uint32)(Flash_MainFunctionStatus.Length)%(uint32)(FLASH_PAGE_SIZE);
    
    /*Check is a padding is needed*/
    if(NbOfBytesOnLastPage != (uint32)(0x00))
    {
      /*Prepare the table with the FLASH_PAGES_SIZE_BYTE size which will contains the payload + padding*/
      for(Loop=(uint32)(0x00);
          Loop<NbOfBytesOnLastPage;
          Loop++)
      {
        /*Copy the current payload byte*/
        DataToWrite[Loop] = Flash_MainFunctionStatus.PtrData[Loop];
      }
      
      /*Prepare the table with the FLASH_PAGES_SIZE_BYTE size which will contains the payload + padding*/
      for(Loop=(uint32)(NbOfBytesOnLastPage);
          Loop<(uint32)(FLASH_PAGE_SIZE);
          Loop++)
      {
        /*Set the padding value*/
        DataToWrite[Loop] = (uint8)(FLASH_PAGE_PADDING_VALUE);
      }
      
      /*Set the local data pointer on the builded payload + padding table adddress*/
      PtrDataToWrite = DataToWrite;
    }
  }

  /*Perform the writing of the current page address*/
  RetVal= (eFlashStatus)(FLW_WriteRoutine(LocPhysicalToLogicalAddress,
                                          FLASH_PAGE_SIZE,
                                          PtrDataToWrite));

  /*If no error on the low layer Erase function execution*/
  if(FLASH_NO_ERROR == RetVal)
  {
    /*Execute the low layer main functions*/
    RetVal = Flash_MainFunctionMngt();

    /*If no error*/
    if(FLASH_NO_ERROR == RetVal)
    {
      /*Push the AddressToTreat to AddressTreated*/
      Flash_MainFunctionStatus.AddressTreated = Flash_MainFunctionStatus.AddressToTreat;
      
      /*Decrease the number of pages to write*/
      Flash_MainFunctionStatus.NbOfPagesToWrite--;
      
      /*Compute the next page address to write*/
      Flash_MainFunctionStatus.AddressToTreat += FLASH_PAGE_SIZE;
        
      /*Put the pointer data to the next start address to write*/
      Flash_MainFunctionStatus.PtrData += FLASH_PAGE_SIZE;
        
      /*Check if there is remaining pages to write*/
      if(Flash_MainFunctionStatus.NbOfPagesToWrite != (uint32)(0x00))
      {
        /*Set the status as busy*/
        RetVal = FLASH_BUSY;
      }    
      /*All pages has been written, end of writing*/
      else
      {
        /*Set the status as no error*/
        RetVal = FLASH_NO_ERROR;
      }
    }
  }
  
  /*Return writing operation status*/
  return(RetVal);
}
/*---------------------------{end Flash_MainFunctionWritingMngt}------------------*/

/*----------------------------{Flash_MainFunctionReadingMngt}---------------------*/
STATIC eFlashStatus Flash_MainFunctionReadingMngt(void)
{
  /*Declare local variable*/
  eFlashStatus RetVal = FLASH_READ_ERROR;
  uint32 LocPhysicalToLogicalAddress;
  
  /*Compute the Physical to Logical address to treat*/
  RetVal = FLASH_CustomGetPhysicalToLogicalAddress(Flash_MainFunctionStatus.AddressToTreat,&LocPhysicalToLogicalAddress);

  /*Prepare the reading operation*/
  RetVal = (eFlashStatus)(FLW_ReadRoutine(LocPhysicalToLogicalAddress,
                                          Flash_MainFunctionStatus.Length,
                                          Flash_MainFunctionStatus.PtrData));

  /*If no error on the low layer Read function execution*/
  if(FLASH_NO_ERROR == RetVal)
  {
    /*Execute the low layer main functions*/
    RetVal = Flash_MainFunctionMngt();
  }
  
  /*Return read operation status*/
  return(RetVal);
}
/*---------------------------{end Flash_MainFunctionReadingMngt}------------------*/

/*----------------------------------{FLASH_Init}---------------------------------*/
eFlashStatus FLASH_Init(void)
{
  /*Declare local variable*/
  eFlashStatus RetVal = FLASH_NO_ERROR;
  
  /*Initialize the Flash_MainFunctionStatus request*/
  Flash_MainFunctionStatus.Request = cNoRequest;
  
  /*Initialization of the FlashWrapper*/
  RetVal = (eFlashStatus)(FLW_Init());

  /*Return initialization operation status*/
  return(RetVal);
}
/*----------------------------------{end FLASH_Init}-----------------------------*/

/*----------------------------------{FLASH_Erase}--------------------------------*/
eFlashStatus FLASH_Erase(uint32 uAddr, uint32 uwLen)
{
  /*Declare local variable*/
  eFlashStatus RetVal = FLASH_NO_ERROR;
  
  /*Check if the range address is allowed*/
  if(!Flash_IsRangeAddressAllowed(uAddr, uwLen))
  {
    /*Set error that range address is not allowed*/
    RetVal = FLASH_ADDR_RANGE_NOT_ALLOWED; 
  }
  
  /*Check if the address is aligned on a sector address*/
  if(!Flash_IsAddressAlignedOnSector(uAddr))
  {
    /*Set error that address not aligned on sector*/
    RetVal = FLASH_ADDR_NOT_ALIGNED_ON_SECTOR; 
  }
  
  /*Check if the range address is programmable*/
  if(!Flash_IsSectorsProgrammable(uAddr,uwLen))
  {
    /*Set error that address not programmable*/
    RetVal = FLASH_ADDR_NOT_PROGRAMMABLE;     
  }
  
  /*If all the check are OK*/
  if(FLASH_NO_ERROR == RetVal)
  {
    /*Store all the information into the Flash_MainFunctionStatus structure*/
    Flash_MainFunctionSetInfo(uAddr, uwLen, NULL_PTR, cErasingRequest);
                            
#if (FLASH_ERASE_MODE==FLASH_SYNCHRONE_MODE)
    /*While the job is BUSY*/
    while(FLASH_BUSY == Flash_MainFunctionStatus.JobStatus)
#endif	
    {
      /*Call the FLASH_MainFunction*/
      FLASH_MainFunction();
    }
    
    /*Update the RetVal*/
    RetVal = Flash_MainFunctionStatus.JobStatus;
  }

  /*Return request erase operation status*/
  return (RetVal);
}
/*-----------------------------{end FLASH_Erase}---------------------------------*/

/*--------------------------------{FLASH_WriteBuffer}----------------------------*/
eFlashStatus FLASH_Write(uint32 uAddr, uint32 uwLen, uint8* aubData)
{
  /*Declare local variable*/
  eFlashStatus RetVal = FLASH_NO_ERROR;
  
  /*Check if the range address is allowed*/
  if(!Flash_IsRangeAddressAllowed(uAddr, uwLen))
  {
    /*Set error that range address is not allowed*/
    RetVal = FLASH_ADDR_RANGE_NOT_ALLOWED; 
  }
  
  /*Check if the address is aligned on a page address*/
  if(!Flash_IsAddressAlignedOnPage(uAddr))
  {
    /*Set error that address not aligned on sector*/
    RetVal = FLASH_ADDR_NOT_ALIGNED_ON_PAGE; 
  }
  
  /*Check if the range address is programmable*/
  if(!Flash_IsSectorsProgrammable(uAddr,uwLen))
  {
    /*Set error that address not programmable*/
    RetVal = FLASH_ADDR_NOT_PROGRAMMABLE;
  }
  
  /*If all the check are OK, send the request to the FLASH_MainFunction*/
  if(FLASH_NO_ERROR == RetVal)
  {
    /*Store all the information into the Flash_MainFunctionStatus structure*/
    Flash_MainFunctionSetInfo(uAddr, uwLen, aubData, cWritingRequest);

#if (FLASH_WRITE_MODE==FLASH_SYNCHRONE_MODE)
    /*While the job is BUSY*/
    while(FLASH_BUSY == Flash_MainFunctionStatus.JobStatus)
#endif
    {
      /*Call the FLASH_MainFunction*/
      FLASH_MainFunction();
    }
    
    /*Update the RetVal*/
    RetVal = Flash_MainFunctionStatus.JobStatus;    
  }
    
  /*Return request erase operation status*/
  return (RetVal);
}
/*----------------------------{end FLASH_WriteBuffer}----------------------------*/

/*--------------------------------{FLASH_Read}-----------------------------------*/
eFlashStatus FLASH_Read(uint32 uAddr, uint32 uwLen, uint8* aubData)
{
  /*Declare local variable*/
  eFlashStatus RetVal = FLASH_NO_ERROR;
  
  /*Check if the range address is allowed*/
  if(!Flash_IsRangeAddressAllowed(uAddr, uwLen))
  {
    /*Set error that range address is not allowed*/
    RetVal = FLASH_ADDR_RANGE_NOT_ALLOWED; 
  }

  /*If all the check are OK, send the request to the FLASH_MainFunction*/
  if(FLASH_NO_ERROR == RetVal)
  {
    /*Store all the information into the Flash_MainFunctionStatus structure*/
    Flash_MainFunctionSetInfo(uAddr, uwLen, aubData, cReadingRequest);

#if (FLASH_READ_MODE==FLASH_SYNCHRONE_MODE)
    /*While the job is BUSY*/
    while(FLASH_BUSY == Flash_MainFunctionStatus.JobStatus)
#endif
    {
      /*Call the FLASH_MainFunction*/
      FLASH_MainFunction();
    }
    
    /*Update the RetVal*/
    RetVal = Flash_MainFunctionStatus.JobStatus;    
  }
  
  /*Return read operation status*/
  return (RetVal);
}
/*--------------------------------{End FLASH_Read}--------------------------------*/

/*--------------------------------{FLASH_MainFunction}----------------------------*/
void FLASH_MainFunction(void)
{
  /*Declare local variable*/
  eFlashStatus RetVal = FLASH_NO_ERROR;

  /*Depending the Flash request*/
  switch(Flash_MainFunctionStatus.Request)
  {
    /*No request*/
    case(cNoRequest):
      /***************/
      /*Nothing to do*/
      /***************/
      break;
    
    /*Erasing request*/
    case(cErasingRequest):
      /*Call the erase management function*/
      RetVal = Flash_MainFunctionErasingMngt();
      break;

    /*Writing request*/
    case(cWritingRequest):
      /*Call the write management function*/
      RetVal = Flash_MainFunctionWritingMngt();
      break;
    
    /*Reading request*/
    case(cReadingRequest):
      /*Call the read management function*/
      RetVal = Flash_MainFunctionReadingMngt();
      break;
    
    /*Undef request*/
    default:
      /*Set unexpected request error*/ 
      RetVal = FLASH_UNEXPECTED_REQUEST;
      break;
  }

  /*Check if end of action*/
  if(FLASH_BUSY != RetVal)
  {
    /*Set the Flash_MainFunctionStatus request the NoRequest*/
    Flash_MainFunctionStatus.Request = cNoRequest;
  }
  
  /*Update the job status*/
  Flash_MainFunctionStatus.JobStatus = RetVal;
}
/*-------------------------------{end FLASH_MainFunction}----------------------*/

/*--------------------------------{FLASH_GetJobStatus}-------------------------*/
eFlashStatus FLASH_GetJobStatus(void)
{
  /*Return the current job status*/
  return(Flash_MainFunctionStatus.JobStatus);  
}
/*-------------------------------{end FLASH_GetJobStatus}----------------------*/

/****************************************************/
/*TEMP CODE WHICH SHALL DISAPEAR ON THE RELEASE STEP*/
/****************************************************/
eFlashStatus FLASH_EraseSector(uint32 uAddr)
{
  /*Declare local variable*/
  eFlashStatus RetVal = FLASH_NO_ERROR;
  
  /*Execute the erasing function with a length of 1 to erase one sector*/
  RetVal = FLASH_Erase(uAddr,0x01);

  /*If some erasing actions are needed*/
  if(FLASH_BUSY == RetVal)
  {
    /*Call the final API in charge of the erasing operation*/
    while(FLASH_BUSY == Flash_MainFunctionStatus.JobStatus)
    {
      /*Call the FLASH_MainFunction*/
      FLASH_MainFunction();
    }
  }

  /*Return status*/
  return(RetVal);
}


eFlashStatus FLASH_WriteBuffer(uint32 uAddr, uint32 uwLen, uint8* aubData)
{
  /*Declare local variable*/
  eFlashStatus RetVal = FLASH_NO_ERROR;
  
  /*Execute the writing function */
  RetVal = FLASH_Write(uAddr, uwLen, aubData);  

  /*If the writing attempt is allowed*/
  if(FLASH_BUSY == RetVal)
  {
    /*Call the final API in charge of the erasing operation*/
    while(FLASH_BUSY == Flash_MainFunctionStatus.JobStatus)
    {
      /*Call the FLASH_MainFunction*/
      FLASH_MainFunction();
    }
  }

  /*Return status*/
  return(RetVal);
}

uint32 FLASH_GetNextSectorAddr(uint32 uAddr)
{
  uint32 uNextAddr;
  
  /*Call the final API in charge of the retrieving the next sector address operation*/
  Flash_GetNextSectorAddress(uAddr, &uNextAddr);  
  
  /*Call the final API in charge of the writing operation*/
  return(uNextAddr);
}
