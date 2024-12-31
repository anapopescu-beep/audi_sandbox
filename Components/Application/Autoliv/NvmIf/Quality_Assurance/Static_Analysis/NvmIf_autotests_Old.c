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
$Revision: 1.10.1.8 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/NvmIf/Quality_Assurance/Static_Analysis/project.pj $
*/
/*****************************************************************************

details
   File containing the NvmIf component autotest.
******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_NvmIf.h"
#include "NvmIf.h"
#include "Nvp_Cfg.h"
#include "NvM.h"
#include "Common.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *       Max length of NVP Block to parse.
 */
#define NVMIF_KU16_MAX_BLOCK_LEN_TO_PARSE ((uint16) 32)
/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

#define NvmIf_START_SEC_VAR_INIT_16_ASIL_A
#include "NvmIf_MemMap.h"
/**
 * \brief
 *       Current Nvp Block ID.
 * \initialization
 *       NA.
 * \range
 *       NA.
 */

LOCAL uint16 nvmif_u16BlockId = KU16_ZERO;


#define NvmIf_STOP_SEC_VAR_INIT_16_ASIL_A
#include "NvmIf_MemMap.h"

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
#define NvmIf_START_SEC_CODE_ASIL_A
#include "NvmIf_MemMap.h"

/**
* \brief
*     This autotest checks if one or more EEPROM blocks are not programmed (Manufacture).
* \outputparam
*     Name: pu8TestResult;
*     Type: u8TestResultType *;
*     Description: The result of test;
*     Range:
*        KU8_ATM_TEST_OK;
*        KU8_ATM_TEST_NOK; 
*        KU8_ATM_TEST_NOT_DECIDED;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     ATM module.
* \dynamicaspectdescription
*     Called in other SW components through RTE layer.
* \ddesignrequirement
*		DSG_NvmIf_Autotest_RunEepromMemoryNotProgrammed
* \archrequirement
*     ARCH_SW_NvmIf_pseRunEepromMemoryNotProgrammed
**/
EXPORTED void NvmIf_Autotest_RunEepromMemoryNotProgrammed (u8TestResultType * pu8TestResult)
{
   NvM_ASR42_RequestResultType u8BlockStatus = KU8_ATM_TEST_NOK;
   uint8 * pu8NvM_DstPtr;
   uint8 u8NvmNotProgBlockFound = KU8_FALSE;
   volatile uint8 u8ParseSize = KU8_ZERO;
   volatile uint16 u16SegmentLenght = KU16_ZERO;
   volatile boolean bMemoryResult = B_FALSE;
   uint16 u16Length = KU16_ZERO;
   volatile uint16 u16BlockIndex = KU16_ZERO;
   volatile uint8 u8MaxSizeToParseExceeded = KU8_FALSE;
   uint16 u16CurrentParsedLength = KU16_ZERO;

   u8MaxSizeToParseExceeded = KU8_FALSE;

   do {
      /* Parse NvM Blocks one by one and check if current block shall be tested */
      if ((NVP_KU8_E2P_NOT_PROGRAMMED_AT_MASK == NVP_kastBlockConfig[nvmif_u16BlockId].u8AutotestFlag)
            && (NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS > nvmif_u16BlockId))
      {
         bMemoryResult = B_FALSE;
         u8NvmNotProgBlockFound = KU8_TRUE;

         pu8NvM_DstPtr = (uint8*)NVP_kastBlockConfig[nvmif_u16BlockId].u32BlockRamStartAddress;
         NvmIf_GetNvmBlockLength(nvmif_u16BlockId, &u16Length);

         if (((NVMIF_KU16_MAX_BLOCK_LEN_TO_PARSE >= (u16CurrentParsedLength + u16Length)) || (NVMIF_KU16_MAX_BLOCK_LEN_TO_PARSE < u16Length)) 
            && (B_FALSE == u8MaxSizeToParseExceeded))
         {
            u16CurrentParsedLength += u16Length;

            if (NVMIF_KU16_MAX_BLOCK_LEN_TO_PARSE <= u16CurrentParsedLength)
            {
               u8MaxSizeToParseExceeded = KU8_TRUE;
            }

            NvmIf_GetNvmBlockStatus(nvmif_u16BlockId, &u8BlockStatus);

            if (NVM_REQ_OK == u8BlockStatus)
            {
               u8ParseSize = KU8_ZERO;
               u16SegmentLenght = KU16_ZERO;

               if  (KU16_ZERO == (u16Length % KU16_EIGHT))
               {
                  /* parse whole block as u64 */
                     u8ParseSize = KU8_EIGHT;
               }
               else if (KU16_ZERO == (u16Length % KU16_FOUR))
               {
                  /* parse whole block as u32 */
                  u8ParseSize = KU8_FOUR;
               }
               else
               {
                  if (u16Length > KU8_EIGHT)
                  {
                     /* parse as much as possible as u32 */
                     u16Length = u16Length - (u16Length % KU8_EIGHT);
                     u8ParseSize = KU8_EIGHT;
                     u16SegmentLenght = u16Length % KU8_EIGHT;
                  }
                  else if (u16Length > KU16_FOUR)
                  {
                     /* parse as much as possible as u32 */
                     u16Length = u16Length - (u16Length % KU16_FOUR);
                     u8ParseSize = KU8_FOUR;
                     u16SegmentLenght = u16Length % KU16_FOUR;
                  }
                  else if(u16Length > KU16_ONE)
                  {
                     /* parse as much as possible as u16 */
                     u16Length = u16Length - (u16Length % KU16_TWO);
                     u8ParseSize = KU8_TWO;
                     u16SegmentLenght = u16Length % KU16_TWO;
                  }
                  else
                  {
                     /* parse as u8 */
                     u8ParseSize = KU8_ONE;
                  }
               }

               for (u16BlockIndex = KU16_ZERO; ((u16BlockIndex < u16Length) && (B_FALSE == bMemoryResult)); u16BlockIndex += ((uint16)u8ParseSize))
               {
                  if (KU8_EIGHT == u8ParseSize)
                  {
                     if (KU64_MAX != *((const uint64 *)&pu8NvM_DstPtr[u16BlockIndex]))
                     {
                        bMemoryResult = B_TRUE;
                     }
                  }
                  else if (KU8_FOUR == u8ParseSize)
                  {
                     if (KU32_MAX != *((const uint32 *)&pu8NvM_DstPtr[u16BlockIndex]))
                     {
                        bMemoryResult = B_TRUE;
                     }
                  }
                  else if (KU8_TWO == u8ParseSize)
                  {
                     if (KU16_MAX != *((const uint16 *)&pu8NvM_DstPtr[u16BlockIndex]))
                     {
                        bMemoryResult = B_TRUE;
                     }
                  }
                  else
                  {
                     if (KU8_MAX != pu8NvM_DstPtr[u16BlockIndex])
                     {
                        bMemoryResult = B_TRUE;
                     }
                  }
               }

               if (KU16_ZERO != u16SegmentLenght)
               {
                  for (u16BlockIndex = KU16_ZERO; ((u16BlockIndex < u16SegmentLenght) && (B_FALSE == bMemoryResult)); u16BlockIndex++)
                  {
                     if (KU8_MAX != pu8NvM_DstPtr[u16BlockIndex])
                     {
                        bMemoryResult = B_TRUE;
                     }
                  }
               }

               if (B_TRUE == bMemoryResult)
               {
                  *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;
               }
               else
               {
                  *pu8TestResult = KU8_ATM_TEST_NOK;
               }

               nvmif_u16BlockId++;
            }
            else if (((uint8)NVM_REQ_RESTORED_FROM_ROM) == u8BlockStatus)
            {
               if (B_TRUE == bMemoryResult)
               {
                  *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;
               }
               else
               {
                  *pu8TestResult = KU8_ATM_TEST_NOK;
               }
            }
            else if ((((uint8)NVM_REQ_INTEGRITY_FAILED) == u8BlockStatus) || (((uint8)NVM_REQ_NOT_OK) == u8BlockStatus))
            {
               *pu8TestResult = KU8_ATM_TEST_NOK;
            }
            else
            {
               /* do nothing */
            }
         }
         else
         {
            u8MaxSizeToParseExceeded = KU8_TRUE;
         }
      }
      else
      {
         nvmif_u16BlockId++;
         if (nvmif_u16BlockId >= ((uint16)NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS))
         {
            *pu8TestResult = KU8_ATM_TEST_OK;
            bMemoryResult  = B_FALSE;
         }
      }

   } while (((KU8_FALSE == u8MaxSizeToParseExceeded) || (KU8_FALSE == u8NvmNotProgBlockFound)) &&
               (((uint16)NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS) > nvmif_u16BlockId) && 
               (((uint8)KU8_ATM_TEST_NOK) != *pu8TestResult));

   /* If the total number of block is reached and all the parameters
      of the block are not equal to 0xFF then the test is ok*/
   if ((((uint16)NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS) == nvmif_u16BlockId) && (((uint8)KU8_ATM_TEST_NOT_DECIDED) == *pu8TestResult))
   {
       *pu8TestResult = KU8_ATM_TEST_OK;
       bMemoryResult  = B_FALSE;
   }
}

#define NvmIf_STOP_SEC_CODE_ASIL_A
#include "NvmIf_MemMap.h"

/******************************************************************************
End Of File
*****************************************************************************/
