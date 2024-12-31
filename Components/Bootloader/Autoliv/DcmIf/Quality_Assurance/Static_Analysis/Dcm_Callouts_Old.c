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
$Revision: 1.6.1.10 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader/Autoliv/DcmIf/Quality_Assurance/Static_Analysis/project.pj $
 */
/*!****************************************************************************
details
   High level module used for memory management.
   In charge of:
      o Write memory
      o Read memory
      o Request confirmation
      o Set/Get programming conditions

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_DcmIf.h"
#include "Dcm.h"
#include "Dcm_Dsp_MemoryServices.h"
#include "Dcm_Callouts.h"
#include "Dcm_User.h"
#include "Nvp_Cfg.h"
#include "EcuM_BSW.h"
#include "NvmIf.h"
#include "Dia.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *       Define for invalid memory block.
 */
#define  KU8_DCMIF_BLOCK_NOT_PRESENT                        ((uint8) 0xFFU)

/**
 * \brief
 *      Define used to indicate memory block ID.
 */
#define  KU32_DCMIF_MASK_BLOCK_ID                           ((uint32) 0x00FF0000)

/**
 * \brief
 *       Define used to indicate the position of low to middle bytes.
 */
#define  KU32_DCMIF_K_POS_L_LOW_MIDDLE_BYTE                 ((uint32) 16)

/**
 * \brief
 *       Define used to indicate the start memory address.
 */
#define  KU32_DCMIF_START_MEMORY_ADDRESS_MASK               ((uint32) 0xFFFF)

/* Diagnostic Services */
/**
 * \brief
 *       Define used to indicate the ECU reset diagnostic service.
 */
#define KU8_DCMIF_SID11_ECU_RESET                           ((uint8) 0x11)

/**
 * \brief
 *       Define used to indicate the diagnostic session control service.
 */
#define KU8_DCMIF_SID10_DIAGNOSTIC_SESSION_CONTROL          ((uint8) 0x10)

/**
 * \brief
 *       Define used to indicate the hard reset diagnostic subfunction.
 */
#define KU8_DCMIF_SID11_SUBF_HARD_RESET                     ((uint8) 0x01)

/**
 * \brief
 *       Define used to indicate the default session.
 */
#define KU8_DCMIF_SID10_SUBF_DEFAULT_SESSION                ((uint8) 0x01)

/**
 * \brief
 *       Diagnostic Request.
 */
#define KU32_DCMIF_PROG_REQUEST_FROM_APP                    ((uint32) 0x55AA55AA)

/**
 * \brief
 *       Reset Cause DSC02.
 */
#define KU8_DCMIF_PROG_RESET_CAUSE_DSC02                    ((uint8) 0x02)

/**
 * \brief
 *       Reset Cause from Programming.
 */
#define KU8_DCMIF_PROG_RESET_CAUSE_ER                       ((uint8) 0x00)

/**
 * \brief
 *       Reset Cause DSC01.
 */
#define KU8_DCMIF_PROG_RESET_CAUSE_DSC01                    ((uint8) 0x01)

/**
 * \brief
 *       RAM Start Address.
 */
#define KU32_DCMIF_ECU_UNLOCK_RAM_START_ADDR                ((uint32)0x14000000)

/**
 * \brief
 *       Maximum memory size.
 */
#define  KU32_DCMIF_MAX_MEMORY_SIZE_VALUE                   ((uint32)0x00000100)

/**
 * \brief
 *       EEPROM address.
 */
#define  KU32_DCMIF_EEPROM_ADDRESS                          ((uint32)0xEE000000)

/**
 * \brief
 *       Define used to indicate EEPROM address.
 */
#define  KU32_DCMIF_MASK_EEPROM                             ((uint32)0xFF000000)

/******************************************************************************
MODULE TYPES
******************************************************************************/
/**
 * \brief
 *       Typedef for shared variable between bootloader and application.
 */
typedef struct
{
   uint32 u32ProgSig;
   uint8 u8ResponseRequired;
   uint8 u8ResetCause;
   uint8 u8RxPduId;
   uint8 u8Side;
   uint8 u8TpSize;
} dcmif_stNoInitShareVarType;
/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
LOCAL boolean dcmif_bForbidData(const uint32 u32DestAddressToBeChecked, const uint32 u32LengthToBeChecked);

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#define DcmIf_START_SEC_VAR_INIT_8
#include "DcmIf_MemMap.h"
/**
 * \brief
 *       This variable is used to store the read status.
 * \initialization 
 *       NVM_REQ_NOT_OK.
 * \range
 *       NVM_REQ_NOT_OK;
 *       NVM_REQ_NV_INVALIDATED;
 *       NVM_REQ_RESTORED_FROM_ROM;
 *       NVM_REQ_OK;
 *       NVM_REQ_PENDING;
 */
LOCAL uint8 dcmif_u8ReadBlockByAddressResult = NVM_REQ_NOT_OK;

/**
 * \brief
 *       This variable is used to store the write status.
 * \initialization 
 *       NVM_REQ_NOT_OK.
 * \range
 *       NVM_REQ_NOT_OK;
 *       NVM_REQ_OK;
 *       NVM_REQ_PENDING;
 */
LOCAL uint8 dcmif_u8WriteBlockByAddressResult = NVM_REQ_NOT_OK;

#define DcmIf_STOP_SEC_VAR_INIT_8
#include "DcmIf_MemMap.h"

#define DcmIf_START_SEC_VAR_NO_INIT_32
#include "DcmIf_MemMap.h"

/**
 * \brief
 *       This variable is used to store the last memory address used.
 * \initialization 
 *       No initialization.
 * \range
 *       NA.
 */
LOCAL uint32 dcm_u32SavedMemoryAddress;

/**
 * \brief
 *       This variable is used to store the size of the last memory block used.
 * \initialization 
 *       No initialization.
 * \range
 *       NA.
 */
LOCAL uint32 dcm_u32SavedMemorySize;

#define DcmIf_STOP_SEC_VAR_NO_INIT_32
#include "DcmIf_MemMap.h"

#ifndef TESSY
#define DcmIf_START_SEC_VAR_POWER_ON_CLEARED
#include "DcmIf_MemMap.h"

/**
 * \brief
 *       Shared variable between bootloader and application.
 *       Shall be stored in a NoInit area known by both software.
 * \initialization 
 *       No initialization.
 * \range
 *       NA.
 */
LOCAL dcmif_stNoInitShareVarType stNoInitShareVar __AT 0x20006f00;

#define DcmIf_STOP_SEC_VAR_POWER_ON_CLEARED
#include "DcmIf_MemMap.h"
#else
dcmif_stNoInitShareVarType stNoInitShareVar;
#endif
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
/**
 * \brief
 *       The function is used to check if a memory area contains forbidden data or not.
 * \inputparam
 *       Name: u32DestAddressToBeChecked;
 *       Type: uint32;
 *       Description: Address to be checked.;
 *       Range: NA.;
 * \inputparam
 *       Name: u32LengthToBeChecked;
 *       Type: uint32;
 *       Description: Memory block length.;
 *       Range: NA.;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       bReturnedStatus:
 *       o  B_TRUE - Memory area is forbidden because it contains a forbidden data;
 *       o  B_FALSE - Memory area is authorized because it does not contain any forbidden data;
 * \dynamicaspectcaller
 *       Dcm_WriteMemory.
 * \dynamicaspectdescription
 *       The function is used to check if a memory area is forbidden or not.
 * \constraints
 *       NA.
 * \ddesignrequirement
 *       DSG_dcmif_dcmif_bForbidData
 * \archrequirement
 *       ARCH_SW_DcmIf_ptrpAsrDcmServices_WriteMemory
 **/
LOCAL boolean dcmif_bForbidData(const uint32 u32DestAddressToBeChecked, const uint32 u32LengthToBeChecked)
{
   uint16 u16TempBlockId;
   uint32 u32BlockRamAdressToBeChecked;
   boolean bReturnedStatus;

   /* Get the block Id */
   if(KU32_DCMIF_EEPROM_ADDRESS == (u32DestAddressToBeChecked & KU32_DCMIF_MASK_EEPROM))
   {
      u16TempBlockId = (uint16)((((u32DestAddressToBeChecked & KU32_DCMIF_MASK_BLOCK_ID) >> KU32_DCMIF_K_POS_L_LOW_MIDDLE_BYTE)) - KU32_ONE);

      Rte_Call_pclNvmIfServices_NvmIf_GetRamAddressByBlockId(u16TempBlockId, &u32BlockRamAdressToBeChecked);
      /* Check if the forbidden data are not included in the area to write */
      /* Forbidden data : Factory lock status */
      /* NVP_BLOCK_ID_ECU_UNLOCK = E2P block */
      /* NVP_u8ECUUnlock = RAM alias */
      /* K_NVP_u8ECUUnlock = default ROM address */
      /* QAC_WARNING S 0306 5 */ /* Cast in order to get address value */
      if((u32BlockRamAdressToBeChecked <= (uint32)&NVP_u8ECUUnlock) && (((uint32)&NVP_u8ECUUnlock) < (u32BlockRamAdressToBeChecked + (uint32)u32LengthToBeChecked)))
      {
         /* This area is forbidden because it contains a forbidden data */
         bReturnedStatus = B_TRUE;
      }
      else
      {
         /* This area is authorized because it does not contain any forbidden data */
         bReturnedStatus = B_FALSE;
      }
   }
   else
   {
      /* This area is authorized because it does not contain any forbidden data */
      bReturnedStatus = B_FALSE;
   }
   
   return bReturnedStatus;
}
/**************************************************************************
Private Functions
**************************************************************************/

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
#define DcmIf_START_SEC_CODE
#include "DcmIf_MemMap.h"

/**
 * \brief
 *       Callout to write memory by address (Diagnostic request)
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType;
 *       Description: Operation status.;
 *       Range: NA.;
 * \inputparam
 *       Name: MemoryIdentifier;
 *       Type: uint8;
 *       Description: EEPROM Memory Block ID.;
 *       Range: NA.;
 * \inputparam
 *       Name: MemoryAddress;
 *       Type: uint32;
 *       Description: The address of EEPROM memory block ID.;
 *       Range: NA.;
 * \inputparam
 *       Name: MemorySize;
 *       Type: uint32;
 *       Description: The size of EEPROM memory block ID.;
 *       Range: NA.;
 * \outputparam
 *       Name: MemoryData;
 *       Type: uint8;
 *       Description: Pointer to the data buffer that contains data to be written in EEPROM memory.;
 *       Range: NA.;
 * \return:
 *       Dcm_ReturnWriteMemoryType:
 *       o  DCM_WRITE_OK - Writing has been done;
 *       o  DCM_WRITE_PENDING - Writing is pending, another called is requested;
 *       o  DCM_WRITE_FAILED - The writing has failed;
 * \constrains
 *       NA.
 * \dynamicaspectcaller
 *       RTE SW layer.
 * \dynamicaspectdescription
 *       API called in other SW components via RTE layer.
 * \ddesignrequirement
 *       DSG_DCM_Dcm_WriteMemory
 * \archrequirement
 *       ARCH_SW_DcmIf_ptrpAsrDcmServices_WriteMemory;
 *       ARCH_SW_DcmIf_pclNvmIfServices_WriteBlockByAddress;
 *       ARCH_SW_DcmIf_pclNvmIfServices_GetNvmBlockStatus_Dcm_WriteMemory;
 *       ARCH_SW_DcmIf_pclNvmIfServices_GetRamAddressByBlockId_Dcm_WriteMemory;
 **/
Dcm_ReturnWriteMemoryType Dcm_WriteMemory(
      Dcm_OpStatusType OpStatus,
      uint8 MemoryIdentifier,
      uint32 MemoryAddress,
      uint32 MemorySize,
      P2CONST(uint8, AUTOMATIC, DCM_VAR) MemoryData,
      Dcm_NegativeResponseCodeType* ErrorCode)
{
   uint32 u32TempBlockId;
   uint32 u32BlockLength;
   uint32 u32LoopIndex;
   uint8 *pu8Data;
   boolean bForbidStatus;
   Dcm_ReturnWriteMemoryType u8WriteMemoryResult;

   u8WriteMemoryResult = DCM_WRITE_FAILED;

   /* Save MemoryAddress and MemorySize - Otherwise variables are erased at each call */
   if(DCM_INITIAL == OpStatus)
   {
      dcm_u32SavedMemoryAddress = MemoryAddress;
      dcm_u32SavedMemorySize = MemorySize;
   }

   /* Check if ECU is locked */
   if(KU8_ECU_UNLOCK == NVP_u8ECUUnlock)
   {
      bForbidStatus = dcmif_bForbidData(dcm_u32SavedMemoryAddress, MemorySize);
      /* Check which kind of memory shall be read :
       * - RAM:  Direct write in the DIA
       * - Data Flash (FEE): Address Pattern -> NvmIf_WriteBlockByAddress */

      if(KU32_DCMIF_MAX_MEMORY_SIZE_VALUE < MemorySize)
      {
         *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      }
      else
      {
         /* Write EEPROM (Data FLASH) */
         if(B_FALSE == bForbidStatus)
         {
            if((dcm_u32SavedMemoryAddress >= (Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_WRITE_MEMORY_ID_INDEX].WriteMemoryRangeInfo[KU8_DCM_E2P_MEMORY_ID_INDEX]).MemoryRangeLow) &&
                  (dcm_u32SavedMemoryAddress <= (Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_WRITE_MEMORY_ID_INDEX].WriteMemoryRangeInfo[KU8_DCM_E2P_MEMORY_ID_INDEX]).MemoryRangeHigh) &&
                  (((dcm_u32SavedMemoryAddress + dcm_u32SavedMemorySize) - KU32_ONE) <= (Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_WRITE_MEMORY_ID_INDEX].WriteMemoryRangeInfo[KU8_DCM_E2P_MEMORY_ID_INDEX]).MemoryRangeHigh))
            {
               u32TempBlockId = ((dcm_u32SavedMemoryAddress & KU32_DCMIF_MASK_BLOCK_ID) >> KU32_DCMIF_K_POS_L_LOW_MIDDLE_BYTE) - KU32_ONE;
               u32BlockLength = (uint32)NVP_kastBlockConfig[u32TempBlockId].u16BlockLength;

               /* Check if the the NVM block length is correct, MemoryAddress is a start address and BlockId is lower than the maximum value supported*/
               if((u32BlockLength == dcm_u32SavedMemorySize) && ((dcm_u32SavedMemoryAddress & KU32_DCMIF_START_MEMORY_ADDRESS_MASK) == KU8_ZERO) && (u32TempBlockId <= NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS))
               {
                  if(NVM_REQ_PENDING != dcmif_u8WriteBlockByAddressResult)
                  {
                     Rte_Call_pclNvmIfServices_WriteBlockByAddress(dcm_u32SavedMemoryAddress, (void *)MemoryData);

                     Rte_Call_pclNvmIfServices_GetNvmBlockStatus(u32TempBlockId, &dcmif_u8WriteBlockByAddressResult);

                     if(NVM_REQ_PENDING == dcmif_u8WriteBlockByAddressResult)
                     {
                        u8WriteMemoryResult = DCM_WRITE_PENDING;
                     }
                  }
                  else
                  {
                     Rte_Call_pclNvmIfServices_GetNvmBlockStatus(u32TempBlockId, &dcmif_u8WriteBlockByAddressResult);

                     if (NVM_REQ_PENDING == dcmif_u8WriteBlockByAddressResult)
                     {
                        u8WriteMemoryResult = DCM_WRITE_PENDING;
                     }
                     else if (NVM_REQ_OK == dcmif_u8WriteBlockByAddressResult)
                     {
                        u8WriteMemoryResult = DCM_WRITE_OK;
                     }
                     else
                     {
                        u8WriteMemoryResult = DCM_WRITE_FAILED;
                        *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                     }
                  }
               }
               else
               {
                  *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
               }
            }
            else if((dcm_u32SavedMemoryAddress >= (Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_WRITE_MEMORY_ID_INDEX].WriteMemoryRangeInfo[KU8_DCM_RAM_SHADOW_MEMORY_ID_INDEX]).MemoryRangeLow) &&
                  (dcm_u32SavedMemoryAddress <= (Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_WRITE_MEMORY_ID_INDEX].WriteMemoryRangeInfo[KU8_DCM_RAM_SHADOW_MEMORY_ID_INDEX]).MemoryRangeHigh) &&
                  (((dcm_u32SavedMemoryAddress + dcm_u32SavedMemorySize) - KU32_ONE) <= (Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_WRITE_MEMORY_ID_INDEX].WriteMemoryRangeInfo[KU8_DCM_RAM_SHADOW_MEMORY_ID_INDEX]).MemoryRangeHigh))
            {
               pu8Data = (uint8 *)dcm_u32SavedMemoryAddress; /* Access to direct memory */

               for (u32LoopIndex = KU32_ZERO; u32LoopIndex < dcm_u32SavedMemorySize; u32LoopIndex++)
               {
                  pu8Data[u32LoopIndex] = MemoryData[u32LoopIndex];
               }
               u8WriteMemoryResult = DCM_WRITE_OK;
            }
            /* Write RAM */
            else if((dcm_u32SavedMemoryAddress >= (Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_WRITE_MEMORY_ID_INDEX].WriteMemoryRangeInfo[KU8_DCM_RAM_APPLI_MEMORY_ID_INDEX]).MemoryRangeLow) &&
                  (dcm_u32SavedMemoryAddress <= (Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_WRITE_MEMORY_ID_INDEX].WriteMemoryRangeInfo[KU8_DCM_RAM_APPLI_MEMORY_ID_INDEX]).MemoryRangeHigh) &&
                  (((dcm_u32SavedMemoryAddress + dcm_u32SavedMemorySize) - KU32_ONE) <= (Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_WRITE_MEMORY_ID_INDEX].WriteMemoryRangeInfo[KU8_DCM_RAM_APPLI_MEMORY_ID_INDEX]).MemoryRangeHigh))
            {
               pu8Data = (uint8 *)dcm_u32SavedMemoryAddress; /* Access to direct memory */

               for(u32LoopIndex = KU32_ZERO; u32LoopIndex < dcm_u32SavedMemorySize; u32LoopIndex++)
               {
                  pu8Data[u32LoopIndex] = MemoryData[u32LoopIndex];
               }
               u8WriteMemoryResult = DCM_WRITE_OK;
            }
            else
            {
               *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
         }
         else
         {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
         }
      }
   }
   else
   {
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   return u8WriteMemoryResult;
}

/**
 * \brief
 *       Callout to read memory by address (Diagnostic request).
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType;
 *       Description: Operation status.;
 *       Range: NA.;
 * \inputparam
 *       Name: MemoryIdentifier;
 *       Type: uint8;
 *       Description: EEPROM Memory Block ID.;
 *       Range: NA.;
 * \inputparam
 *       Name: MemoryAddress;
 *       Type: uint8;
 *       Description: The address of EEPROM memory block ID.;
 *       Range: NA.;
 * \inputparam
 *       Name: MemorySize;
 *       Type: uint32;
 *       Description: The size of EEPROM memory block ID.;
 *       Range: NA.;
 * \outputparam
 *       Name: MemoryData;
 *       Type: uint8;
 *       Description: Pointer to the data buffer that contains data to be read.;
 *       Range: NA.;
 * \return
 *       Dcm_ReturnReadMemoryType:
 *       o  DCM_READ_OK - Reading has been done;
 *       o  DCM_READ_PENDING - Reading is pending, another call is request to finalize the reading;
 *       o  DCM_READ_FAILED - Reading has failed;
 * \constrains
 *       NA.
 * \dynamicaspectcaller
 *       RTE SW layer.
 * \dynamicaspectdescription
 *       API called in other SW components via RTE layer.
 * \ddesignrequirement
 *       DSG_DCM_Dcm_ReadMemory
 * \archrequirement
 *       ARCH_SW_DcmIf_ptrpAsrDcmServices_ReadMemory;
 *       ARCH_SW_DcmIf_pclNvmIfServices_ReadBlockByAddress;
 *       ARCH_SW_DcmIf_pclNvmIfServices_GetNvmBlockStatus_Dcm_ReadMemory;
 **/
Dcm_ReturnReadMemoryType Dcm_ReadMemory(
      Dcm_OpStatusType  OpStatus,
      uint8 MemoryIdentifier,
      uint32 MemoryAddress,
      uint32 MemorySize,
      P2VAR(uint8, AUTOMATIC, DCM_VAR) MemoryData,
      Dcm_NegativeResponseCodeType* ErrorCode)
{
   uint32 u32LoopIndex;
   uint32 u32TempBlockId;
   uint8 *pu8Data;
   Dcm_ReturnReadMemoryType u8ReadMemoryResult;

   u8ReadMemoryResult = DCM_READ_FAILED;

   /* Check which kind of memory shall be read :
    * o Program Flash or RAM:  Direct read in the DIA;
    * o Data Flash (FEE): BlockId in the Address Pattern -> NvmIf_ReadBlockByAddress */

   /* Save MemoryAddress and MemorySize - Otherwise variables are erased at each call */
   if (DCM_INITIAL == OpStatus)
   {
      dcm_u32SavedMemoryAddress = MemoryAddress;
      dcm_u32SavedMemorySize = MemorySize;
   }
   else
   {
      /* Do nothing */
   }

   /* Read EEPROM/FEE (Data FLASH) */
   if ((dcm_u32SavedMemoryAddress >=(Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_E2P_MEMORY_ID_INDEX].ReadMemoryRangeInfo[KU8_DCM_E2P_MEMORY_RANGE_INDEX]).MemoryRangeLow) &&
         (dcm_u32SavedMemoryAddress <= (Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_E2P_MEMORY_ID_INDEX].ReadMemoryRangeInfo[KU8_DCM_E2P_MEMORY_RANGE_INDEX]).MemoryRangeHigh) &&
         (((dcm_u32SavedMemoryAddress + dcm_u32SavedMemorySize) - 1U) <= (Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_E2P_MEMORY_ID_INDEX ].ReadMemoryRangeInfo[KU8_DCM_E2P_MEMORY_RANGE_INDEX]).MemoryRangeHigh))
   {
      u32TempBlockId = ((dcm_u32SavedMemoryAddress & KU32_DCMIF_MASK_BLOCK_ID) >> KU32_DCMIF_K_POS_L_LOW_MIDDLE_BYTE) - KU32_ONE;

      if((NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS <= u32TempBlockId)  || (KU32_ZERO == u32TempBlockId))
      {
         *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      }
      else
      {

         if (NVM_REQ_PENDING != dcmif_u8ReadBlockByAddressResult)
         {
            Rte_Call_pclNvmIfServices_ReadBlockByAddress(dcm_u32SavedMemoryAddress, (void*)MemoryData);

            Rte_Call_pclNvmIfServices_GetNvmBlockStatus(u32TempBlockId, &dcmif_u8ReadBlockByAddressResult);

            if (NVM_REQ_PENDING == dcmif_u8ReadBlockByAddressResult)
            {
               u8ReadMemoryResult = DCM_READ_PENDING;
            }
         }
         else
         {
            Rte_Call_pclNvmIfServices_GetNvmBlockStatus(u32TempBlockId, &dcmif_u8ReadBlockByAddressResult);

            if (NVM_REQ_PENDING == dcmif_u8ReadBlockByAddressResult)
            {
               u8ReadMemoryResult = DCM_READ_PENDING;
            }
            else if (NVM_REQ_OK == dcmif_u8ReadBlockByAddressResult)
            {
               u8ReadMemoryResult = DCM_READ_OK;
            }
            /* Block exists but not written in EEPROM or Block is invalidated ->  0xFF - response */
            else if ( (NVM_REQ_RESTORED_FROM_ROM == dcmif_u8ReadBlockByAddressResult) || (NVM_REQ_NV_INVALIDATED == dcmif_u8ReadBlockByAddressResult) )
            {
               /* Write Response with 0xFF */
               for(u32LoopIndex = KU32_ZERO; u32LoopIndex < dcm_u32SavedMemorySize; u32LoopIndex++)
               {
                  MemoryData[u32LoopIndex] = KU8_DCMIF_BLOCK_NOT_PRESENT;
               }
               u8ReadMemoryResult = DCM_READ_OK;
            }
            else
            {
               u8ReadMemoryResult = DCM_READ_FAILED;
            }
         }
      }
   }

   /* Read Program FLASH  or RAM */
   else
   {
      /* Access to direct memory */
      pu8Data = (uint8 *)dcm_u32SavedMemoryAddress;
      for(u32LoopIndex = KU32_ZERO; u32LoopIndex < dcm_u32SavedMemorySize; u32LoopIndex++)
      {
         MemoryData[u32LoopIndex] = pu8Data[u32LoopIndex];
      }
      u8ReadMemoryResult = DCM_READ_OK;
   }

   return u8ReadMemoryResult;
}

/**
 * \brief
 *       Callout used to confirm services requests.
 * \inputparam
 *       Name: SID;
 *       Type: uint8;
 *       Description: The Id of service.;
 *       Range: NA.;
 * \inputparam
 *       Name: ReqType;
 *       Type: uint8;
 *       Description: Request type.;
 *       Range: NA.;
 * \inputparam
 *       Name: SourceAddress;
 *       Type: uint16;
 *       Description: Address of request source.;
 *       Range: NA.;
 * \inputparam
 *       Name: ConfirmationStatus;
 *       Type: Dcm_ConfirmationStatusType (uint8);
 *       Description: Confirmation status.;
 *       Range: NA.;
 * \constrains
 *       None.
 * \dynamicaspectcaller
 *       This function is not called.
 * \dynamicaspectdescription
 *       NA.
 * \ddesignrequirement
 *       DSG_DCM_Rte_DcmConfirmation
 * \archrequirement
 *       ARCH_SW_DcmIf_ptrpAsrDcmServices_Rte_DcmConfirmation
 **/
void Rte_DcmConfirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress,  Dcm_ConfirmationStatusType ConfirmationStatus)
{
   (void)SID; /* to avoid compiler warning */
   (void)ReqType; /* to avoid compiler warning */
   (void)SourceAddress; /* to avoid compiler warning */
   (void)ConfirmationStatus; /* to avoid compiler warning */
}

/**
 * \brief
 *       Callout used to set the programming conditions.
 * \inputparam
 *       Name: ProgConditions;
 *       Type: Dcm_ProgConditionsType (struct[uint16, uint8, uint8, uint8, boolean, boolean, boolean]);
 *       Description: Programming conditions.;
 *       Range: None;
 * \constrains
 *       None.
 * \dynamicaspectcaller
 *       RTE SW layer.
 * \dynamicaspectdescription
 *       API called in other SW components via RTE layer.
 * \ddesignrequirement
 *       DSG_DCM_Dcm_SetProgConditions
 * \archrequirement
 *       ARCH_SW_DcmIf_ptrpAsrDcmServices_Dcm_SetProgConditions
 **/
Std_ReturnType Dcm_SetProgConditions(P2VAR(Dcm_ProgConditionsType, AUTOMATIC, DCM_APPL_DATA) ProgConditions)
{
   if((NULL_PTR != ProgConditions) && (ProgConditions->ReprogramingRequest == TRUE))
   {
      stNoInitShareVar.u32ProgSig = KU32_DCMIF_PROG_REQUEST_FROM_APP;
      stNoInitShareVar.u8ResponseRequired = TRUE;
      stNoInitShareVar.u8ResetCause = KU8_DCMIF_PROG_RESET_CAUSE_DSC02;
      stNoInitShareVar.u8RxPduId = KU8_ZERO;
      stNoInitShareVar.u8TpSize = DIA_u8BootTpSize;
      stNoInitShareVar.u8Side = KU8_ZERO;
   }
   return E_OK;
}

/**
 * \brief
 *       Callout used to get the programming conditions.
 * \inputparam
 *       Name: ProgConditions;
 *       Type: Dcm_ProgConditionsType (struct[uint16, uint8, uint8, uint8, boolean, boolean, boolean]);
 *       Description: Programming conditions.;
 *       Range: NA.;
 * \constrains
 *       NA.
 * \dynamicaspectcaller
 *       RTE SW layer.
 * \dynamicaspectdescription
 *       API called in other SW components via RTE layer.
 * \ddesignrequirement
 *       DSG_DCM_GetProgConditions
 * \archrequirement
 *       ARCH_SW_DcmIf_pseNvpBlockData_Dcm_GetProgConditions
 *       ARCH_SW_DcmIf_ptrpAsrDcmServices_Dcm_GetProgConditions
 **/
Dcm_EcuStartModeType Dcm_GetProgConditions(P2VAR(Dcm_ProgConditionsType, AUTOMATIC, DCM_APPL_DATA) ProgConditions)
{
   Dcm_EcuStartModeType sReturn;
   sReturn = DCM_COLD_START;

   if ((ProgConditions != NULL_PTR) && (stNoInitShareVar.u8ResponseRequired == TRUE)
         && (stNoInitShareVar.u8ResetCause != KU8_DCMIF_PROG_RESET_CAUSE_DSC02))
   {
      sReturn = DCM_WARM_START;
      stNoInitShareVar.u8ResponseRequired = FALSE;

      ProgConditions->ResponseRequired = TRUE;

      switch (stNoInitShareVar.u8ResetCause)
      {
      case KU8_DCMIF_PROG_RESET_CAUSE_ER:
         ProgConditions->Sid = KU8_DCMIF_SID11_ECU_RESET;
         ProgConditions->SubFncId = KU8_DCMIF_SID11_SUBF_HARD_RESET;
         break;
      case KU8_DCMIF_PROG_RESET_CAUSE_DSC01:
         ProgConditions->Sid = KU8_DCMIF_SID10_DIAGNOSTIC_SESSION_CONTROL;
         ProgConditions->SubFncId = KU8_DCMIF_SID10_SUBF_DEFAULT_SESSION;
         break;
      default:
         break;
      }
   }
   return sReturn;
}

#define DcmIf_STOP_SEC_CODE
#include "DcmIf_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
