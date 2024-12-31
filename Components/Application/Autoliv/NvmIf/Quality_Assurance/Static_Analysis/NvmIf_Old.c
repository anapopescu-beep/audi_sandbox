/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version: 
Template version: AEM_PROCESS_1.25.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2022-09
******************************************************************************/
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.5.1.9 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/NvmIf/Quality_Assurance/Static_Analysis/project.pj $
*/
/*!****************************************************************************

details
   Interface of the NvmIf package to modules below the RTE.

******************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_NvmIf.h"
#include "NvmIf.h"
#include "NvM_DataIntern.h"
#include "Nvp_Cfg.h"
#include "NvM.h"
#include "Common.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *       A mask to get the ID of an Nvp block from its address.
 */
#define NVMIF_KU32_MASK_BLOCK_ID                   ((uint32) 0x00FF0000)
/**
 * \brief
 *       A constant value used to shift a uint32 variable to middle.
 */
#define NVMIF_KU8_POS_L_LOW_MIDDLE_BYTE            ((uint8) 0x10)
/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
#define NvmIf_START_SEC_CODE
#include "NvmIf_MemMap.h"

#if (KU8_NVMIF_ENABLE_GET_CALIB_BLOCK_LENGTH_API == STD_ON)
/**
* \brief
*     Function used to get the length of a calibration specific block.
* \inputparam
*     Name: u16BlockId;
*     Type: u16CalibBlockIdType (uint16);
*     Description: The ID of calibration block;
*     Range: 0..(number of calibration blocks - 1);
* \outputparam
*     Name: pu16BlockLength;
*     Type: u16NvmBlockLengthType * (uint16);
*     Description: The length of calibration block;
*     Range: 0..KU16_MAX;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     This function is not called.
* \dynamicaspectdescription
*     N/A.
**/
EXPORTED void NvmIf_GetCalibBlockLength(u16CalibBlockIdType u16BlockId, u16NvmBlockLengthType * pu16BlockLength)
{
   if (((uint16) CALIB_TOTAL_NUMBER_OF_NVRAM_BLOCKS) > u16BlockId)
   {
      *pu16BlockLength = NVP_kastCalibBlockConfig[u16BlockId].u16BlockLength;
   }
   else
   {
      *pu16BlockLength = KU16_MAX;
   }
}
#endif

#if (KU8_NVMIF_ENABLE_GET_NVM_BLOCK_LENGTH_API == STD_ON)
/**
* \brief
*     Function called on event to get the length of a Nvm specific block.
* \inputparam
*     Name: u16BlockId;
*     Type: NvM_ASR42_BlockIdType (uint16);
*     Description: The ID of Nvm block;
*     Range: 0..(number of Nvm blocks - 1);
* \outputparam
*     Name: pu16BlockLength;
*     Type: u16NvmBlockLengthType * (uint16);
*     Description: The length of Nvm block;
*     Range: 0..KU16_MAX;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     DIA module.
* \dynamicaspectdescription
*     Called in other SW components through RTE layer.
* \ddesignrequirement
*     DSG_NvmIf_GetNvmBlockLength
* \archrequirement
*     ARCH_SW_NvmIf_pseNvmIfServices_GetNvmBlockLength
**/
EXPORTED void NvmIf_GetNvmBlockLength(NvM_ASR42_BlockIdType u16BlockId, u16NvmBlockLengthType * pu16BlockLength)
{
   if (((uint16)  NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS) > u16BlockId)
   {
      *pu16BlockLength = NVP_kastBlockConfig[u16BlockId].u16BlockLength;
   }
   else
   {
      *pu16BlockLength = KU16_MAX;
   }
}
#endif

#if (KU8_NVMIF_ENABLE_GET_NVM_BLOCKS_STATUS_API == STD_ON)
/**
* \brief
*     Function called on event to get the status of a Nvm specific block.
* \inputparam
*     Name: u16BlockId;
*     Type: NvM_ASR42_BlockIdType (uint16);
*     Description: The ID of Nvm block;
*     Range: 0..(number of Nvm blocks - 1);
* \outputparam
*     Name: pu8BlockStatus;
*     Type: NvM_ASR42_RequestResultType * (uint8);
*     Description: The status of Nvm block;
*     Range:
*         E_OK;
*         E_NOT_OK;
*         NVM_REQ_NOT_OK;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     BswMIf, DcmIf and DIA modules.
* \dynamicaspectdescription
*     Called in other SW components through RTE layer.
* \ddesignrequirement
*     DSG_NvmIf_GetNvmBlockStatus
* \archrequirement
*     ARCH_SW_NvmIf_pseNvmIfServices_GetNvmBlockStatus
**/
EXPORTED void NvmIf_GetNvmBlockStatus(NvM_ASR42_BlockIdType u16BlockId, NvM_ASR42_RequestResultType * pu8BlockStatus)
{
   if (((uint16) NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS) > u16BlockId)
   {
      (void)NvM_ASR42_GetErrorStatus(u16BlockId, pu8BlockStatus);
   }
   else
   {
      *pu8BlockStatus = NVM_REQ_NOT_OK;
   }
}
#endif

#if (KU8_NVMIF_ENABLE_READ_BLOCK_BY_ADDRESS_API == STD_ON)
/**
* \brief
*     Function called on event to read a block of a specific address.
* \inputparam
*     Name: u32DestAddress;
*     Type: uint32;
*     Description: The address of Nvm block;
*     Range: NA.;
* \outputparam
*     Name: pvData;
*     Type: NvM_ASR42_DstPtrType * (pointer to void);
*     Description: Data which is read from address;
*     Range: NA.;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     BswMIf, DcmIf and DIA modules.
* \dynamicaspectdescription
*     Called in other SW components through RTE layer.
* \ddesignrequirement
*     DSG_NvmIf_GetNvmBlockStatus
* \archrequirement
*     ARCH_SW_NvmIf_pseNvmIfServices_ReadBlockByAddress
**/
EXPORTED void NvmIf_ReadBlockByAddress(uint32 u32DestAddress, NvM_ASR42_DstPtrType * pvData)
{
   uint16 u16TempBlockId;

   /* Get the block ID from the address pattern */
   u16TempBlockId = (uint16)((((u32DestAddress & NVMIF_KU32_MASK_BLOCK_ID) >> NVMIF_KU8_POS_L_LOW_MIDDLE_BYTE)) - KU32_ONE);

   (void)NvM_ASR42_ReadBlock(u16TempBlockId, pvData);
}

#endif

#if (KU8_NVMIF_ENABLE_READ_NVM_BLOCK_API == STD_ON)
/**
* \brief
*     Function called to read a EEPROM block content.
* \inputparam
*     Name: u16BlockId;
*     Type: NvM_ASR42_BlockIdType (uint16);
*     Description: The ID of Nvm block;
*     Range: 0..(number of Nvm blocks - 1);
* \outputparam
*     Name: NvM_DstPtr;
*     Type: NvM_DstPtrType * (pointer to void);
*     Description: Block destination;
*     Range: NA.;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     This function is not called.
* \dynamicaspectdescription
*     N.A.
**/
EXPORTED void NvmIf_ReadNvmBlock(NvM_ASR42_BlockIdType u16BlockId, NvM_DstPtrType * NvM_DstPtr)
{
   (void)NvM_ASR42_ReadBlock(u16BlockId, NvM_DstPtr);
}
#endif

#if (KU8_NVMIF_ENABLE_WRITE_BLOCK_BY_ADDRESS_API == STD_ON)
/**
* \brief
*     Function called on event to write a block of a specific address.
* \inputparam
*     Name: u32DestAddress;
*     Type: uint32;
*     Description: The address where data shall be written;
*     Range: NA.;
* \outputparam
*     Name: pvData;
*     Type: NvM_ASR42_DstPtrType * (pointer to void);
*     Description: Pointer to the data buffer that contains the data that shall be written;
*     Range: NA.;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     DcmIf module.
* \dynamicaspectdescription
*     Called in other SW components through RTE layer.
* \ddesignrequirement
*     DSG_NvmIf_WriteBlockByAddress
* \archrequirement
*     ARCH_SW_NvmIf_pseNvmIfServices_WriteBlockByAddress
**/
EXPORTED void NvmIf_WriteBlockByAddress(uint32 u32DestAddress, NvM_ASR42_DstPtrType * pvData)
{
   uint16 u16TempBlockId;

   /* Get the block ID from the address pattern */
   u16TempBlockId = (uint16)((((u32DestAddress & NVMIF_KU32_MASK_BLOCK_ID) >> NVMIF_KU8_POS_L_LOW_MIDDLE_BYTE)) - KU32_ONE);

   (void)NvM_ASR42_WriteBlock(u16TempBlockId, pvData);
}
#endif

#if (KU8_NVMIF_ENABLE_WRITE_NVM_BLOCK_API == STD_ON)
/**
* \brief
*     Function called on event to write an Nvm block of a specific ID.
* \inputparam
*     Name: u16BlockId;
*     Type: NvM_ASR42_BlockIdType (uint16);
*     Description: The ID of Nvm block;
*     Range: 0..(number of Nvm blocks - 1);
* \outputparam
*     Name: pvNvM_SrcPtr;
*     Type: NvM_SrcPtrType * (pointer to void);
*     Description: Block source;
*     Range: NA.;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     DIA module.
* \dynamicaspectdescription
*     Called in other SW components through RTE layer.
* \ddesignrequirement
*     DSG_NvmIf_WriteNvmBlock
* \archrequirement
*     ARCH_SW_NvmIf_pseNvmIfServices_WriteNvmBlock
**/
EXPORTED void NvmIf_WriteNvmBlock (NvM_ASR42_BlockIdType u16BlockId, NvM_SrcPtrType * pvNvM_SrcPtr)
{
   (void)NvM_ASR42_WriteBlock(u16BlockId, pvNvM_SrcPtr);
}
#endif

#if (KU8_NVMIF_ENABLE_SYNCHRONOUS_RECORD_API == STD_ON)
/**
* \brief
*     Function used to check if job is pending or finished.
* \inputparam
*     Name: u16BlockId;
*     Type: NvM_ASR42_BlockIdType (uint16);
*     Description: The ID of Nvm block;
*     Range: 0..(number of Nvm blocks - 1);
* \outputparam
*     Name: pu8RequestResult;
*     Type: NvM_ASR42_RequestResultType * (uint8);
*     Description: The result of request;
*     Range: NA.;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     This function is not called.
* \dynamicaspectdescription
*     NA.
**/
EXPORTED void NvmIf_SynchronousRecord(NvM_ASR42_BlockIdType u16BlockId, NvM_ASR42_RequestResultType * pu8RequestResult)
{
   NvmIf_GetBlockStatus(ku16BlockId, pu8RequestResult);

   while (((uint8) NVM_REQ_PENDING) == *pu8RequestResult)
   {
      Fee_MainFunction();
      Fls_MainFunction();
      /* Check if job is pending or finished */
      NvmIf_GetBlockStatus(ku16BlockId, pu8RequestResult);
   }
}
#endif

#if (KU8_NVMIF_ENABLE_GET_RAM_ADDRESS_API == STD_ON)
/**
* \brief
*     Function called to get the RAM address of a block by its ID.
* \inputparam
*     Name: u16BlockId;
*     Type: NvM_ASR42_BlockIdType (uint16);
*     Description: The ID of Nvm block;
*     Range: 0..(number of Nvm blocks - 1);
* \outputparam
*     Name: pu32BlockRamAddress;
*     Type: uint32 *;
*     Description: The address of RAM Block;
*     Range: NA.;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     This function is not called.
* \dynamicaspectdescription
*     NA.
* \ddesignrequirement
*		DSG_NvmIf_GetRamAddressByBlockId
* \archrequirement
*     ARCH_SW_NvmIf_pseNvmIfServices_GetRamAddressByBlockId
**/
EXPORTED void NvmIf_GetRamAddressByBlockId(NvM_ASR42_BlockIdType u16BlockId, uint32 *pu32BlockRamAddress)
{
   *pu32BlockRamAddress = (uint32)NvM_BlockDescriptorTable[u16BlockId].ramBlockDataAddress;
}
#endif

#if (KU8_NVMIF_ENABLE_SET_RAM_BLOCK_STATUS_API == STD_ON)
/**
* \brief
*     Function called on event to set status of a Ram Block.
* \inputparam
*     Name: u16BlockId;
*     Type: NvM_ASR42_BlockIdType (uint16);
*     Description: The ID of Nvm block;
*     Range: 0..(number of Nvm blocks - 1);
*  \inputparam
*     Name: bBlockChanged;
*     Type: boolean;
*     Description: The status of RAM Block to set;
*     Range: TRUE, FALSE;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     BswMIf, DIA, MIC and RCM modules.
* \dynamicaspectdescription
*     Called in other SW components through RTE layer.
* \ddesignrequirement
*     DSG_NvmIf_SetRamBlockStatus
* \archrequirement
*     ARCH_SW_NvmIf_pseNvmIfServices_SetRamBlockStatus
**/
EXPORTED void NvmIf_SetRamBlockStatus(NvM_ASR42_BlockIdType u16BlockId, boolean bBlockChanged)
{
   (void)NvM_ASR42_SetRamBlockStatus(u16BlockId, bBlockChanged);
}
#endif

#if (KU8_NVMIF_ENABLE_RESTORE_PRAM_BLOCK_DEFAULTS_API == STD_ON)
/**
* \brief
*     The function will restore to default a RAM Block.
* \inputparam
*     Name: u16BlockId;
*     Type: NvM_ASR42_BlockIdType (uint16);
*     Description: The ID of Nvm block;
*     Range: 0..(number of Nvm blocks - 1);
* \return
*     This function has no return.
* \dynamicaspectcaller
*     BswMIf module.
* \dynamicaspectdescription
*     Called in other SW components through RTE layer.
* \ddesignrequirement
*     DSG_NvmIf_RestorePRAMBlockDefaults
* \archrequirement
*     ARCH_SW_NvmIf_pseNvmIfServices_RestorePRAMBlockDefaults
**/
EXPORTED void NvmIf_RestorePRAMBlockDefaults(NvM_ASR42_BlockIdType u16BlockId)
{
   (void)NvM_RestorePRAMBlockDefaults(u16BlockId);
}
#endif

#define NvmIf_STOP_SEC_CODE
#include "NvmIf_MemMap.h"

/******************************************************************************
End Of File
 *****************************************************************************/
