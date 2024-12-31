/*===============================================================================*/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                               PROG layer                                      */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file PROG_Impl_90.c                  */
/*%%  |                             |  %%  \brief PROG layer source plugin file  */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.48.0 BL3 */
/*%%  |   &       &    &            |  %%                                        */
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
/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 11.4 (advisory)
 * A conversion should not be performed between a pointer to object
 * and an integer type.
 *
 *   Reason:
 * The memory routines are optimized for dealing with aligned memory
 * sections and need to check the correct alignment before the operation.
 */
/* NOCOV List
 *
 *
 */

/*=============================== FILE INCLUSION ================================*/
/*                                                                               */
#include "EB_Prj.h"
#include "PROG_Priv.h"
#include "PROG_Hsm.h"
#include "PROG_HsmPROG.h"
#include <PROG_Trace.h>                        /* Dbg related macros for EB */
#if (PROG_COMPRESSION_ENABLE == STD_ON)
#include "PROG_Decomp.h"
#endif
#include "board.h"
#if ((PROG_IMPL_VARIANT == PROG_IMPL_90) || (PROG_IMPL_VARIANT == PROG_IMPL_91))
/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */

/* Validate Application routine status */
u8 m_ubValidateMemoryStatus;


/*-------------------------------------------------------------------------------*/
/* - Public Function Prototypes                                                  */

/*-------------------------------------------------------------------------------*/
/* - Public Callback Prototypes                                                  */

/*                                                                               */
/*===============================================================================*/

/*============================ PRIVATE DEFINITIONS ==============================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/

#define PROG_DATA_BLOCKS_COUNT_MSB_OFFSET   2U
#define PROG_DATA_BLOCKS_COUNT_LSB_OFFSET   3U
#define PROG_DATA_BLOCKS_USEFUL_DATA_OFFSET 4U
#define PROG_DATA_BLOCKS_HASH_OFFSET        8U
#define PROG_DATA_BLOCKS_USEFUL_DATA_SIZE   40U
#define PROG_DATA_BLOCKS_COUNT_SIZE         2U
#define PROG_VS_VERSION_SIZE             2U
#define PROG_VERIFICATION_PASSED            0x02U
#define PROG_VERIFICATION_FAILED            0x01U
#define PROG_SIGNATURE_SIZE                 0x100
#define PROG_SIGNATURE_OFFSET               0x100
/*-------------------------------------------------------------------------------*/
/* - Private Types                                                               */

/*-------------------------------------------------------------------------------*/
/* - Private Variables                                                           */

/* Hash value for each data block */
NCS_PRI_VAR tDataBlockType m_aubHashValueBlock[PROG_MAX_RD_PER_BLOCK];
/* Data block block which is being downloaded */
NCS_PRI_VAR u16 m_uwCurrentDataBlock;
/* Digest compuated by crypto for the data block */
NCS_PRI_VAR u8 m_aubComputedDigest[PROG_DIGEST_LENGTH];
/* Added 8 to include start address and length */
#if (PROG_IMPL_VARIANT == PROG_IMPL_90)
NCS_PRI_VAR u8 m_aubDataToBeSigned[PROG_SBL_VS_LENGTH + PROG_ERASE_ADDR_LEN + PROG_ERASE_SIZE_LEN];
#else
NCS_PRI_VAR u8 m_aubDataToBeSigned[(PROG_MAX_RD_PER_BLOCK*PROG_DATA_BLOCKS_USEFUL_DATA_SIZE) + 4U + PROG_ERASE_ADDR_LEN + PROG_ERASE_SIZE_LEN];
#endif
/* This variable will hold the Signature*/
NCS_PRI_VAR u8 m_aubSignature[PROG_SIGNATURE_SIZE];
/* This variable will hold the value of the actual length of the data written for the VS, to be checked later with the expected length of VS */
NCS_PRI_VAR u32 m_ulVSWrittenData;
/*===============================================================================*/

/*-------------------------------------------------------------------------------*/
/* - Private Macros                                                              */

/*-------------------------------------------------------------------------------*/
/* - Private Function Prototypes                                                 */

/** \brief extracts the data block digest from the verification Structure
 **
 ** \param[out] u8* digest values of the data block
 **
 ** \return void
 **/
NCS_PRI_VAR void PROG_GetDigestFromVS(u16 uwDataBlockIndex,u8*aubDigest);


/** \brief provide the verification Structure address
 **
 ** \param[out] u32* address of VS
 **
 ** \return void
 **/
NCS_PRI_VAR void PROG_GetVSAddress(u32 * pulVSAddress);

/** \brief provide the Signature address
 **
 ** \param[out] u32* address of VS
 **
 ** \return void
 **/
NCS_PRI_VAR void PROG_GetSignatureAddress(u32 * pulSignatureAddress);

#if (PROG_IMPL_VARIANT == PROG_IMPL_91)
/** \brief Do the check that the 'not-downloaded' areas are erased or set to a known value (for SBL)
 **
 ** \return tProgStatus
 **/
/** \brief extracts the data block number from the verification Structure
 **
 ** \param[in] void
 **
 ** \return void
 **/
NCS_PRI_VAR void PROG_GetDataBlockNbrFromVS(u16 *uwBlockNumber);
#endif

/** \brief checks on the Version and the length of the verification Structure
 **
 ** \param[in] void
 **
 ** \return tProgStatus
 **/
NCS_PRI_VAR tProgStatus PROG_VerifyVSVersionAndLength(void);

/** \brief checks on the array containing the results of hash comparison for each data block
 **
 ** \param[in] void
 **
 ** \return tProgStatus
 **/
NCS_PRI_VAR tProgStatus PROG_CheckHashResults(void);

/** \brief reads the Version of the verification Structure of the currently downloaded block
 **
 ** \param[out] u16 Version
 **
 ** \return void
 **/
NCS_PRI_VAR void PROG_GetVSVersion(u16 *uwVersion);
/*                                                                               */
/*===============================================================================*/

/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */

void PROG_Init_Impl90(void)
{
  u8 ubIdx;
  u8 ubIndex;

  for(ubIdx = 0; ubIdx < PROG_MAX_RD_PER_BLOCK; ubIdx++)
  {
    for(ubIndex = 0; ubIndex < PROG_DIGEST_LENGTH; ubIndex++)
    {
        m_aubHashValueBlock[ubIdx].aubDigest[ubIndex] = 0x00;
    }
  }

  m_ubValidateMemoryStatus        = PROG_VALIDITY_ROUTINE_NOTEXEC;
}


/*----------------------------{PROG_Impl90_Entry_ValidateFinish}-------------------------*/
void PROG_Impl90_Entry_ValidateFinish(void)
{

    m_ubValidateMemoryStatus = PROG_SIGNATURE_PASSED;

#if (PROG_IMPL_VARIANT == PROG_IMPL_91)
    (void)PROG_CustomSetDownloadVerificationSuccess(0, m_stCurrentSegment.ubSegmentId, PROG_TRUE);

    m_stDiagMessageInfo.pubTxData[PROG_RC_VAL_MEMORY_STATUS_INDEX]                = (u8) (PROG_ROUTINE_FINISHED_OK | PROG_ROUTINE_TYPE_1);
    m_stDiagMessageInfo.pubTxData[PROG_RC_VAL_MEMORY_RESULT_INDEX]                = (u8) PROG_VERIFICATION_PASSED;
    m_stDiagMessageInfo.ulLength = PROG_VAL_MEMORY_RESPONSE_SIZE;
    m_stDiagMessageInfo.ubDiagStatus = UDS_ACK;
    UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);
#endif
}
/*----------------------------{end PROG_Impl90_Entry_ValidateFinish}-------------------------*/

void PROG_Impl90_Entry_ValidateFailed(void)
{
#if (PROG_IMPL_VARIANT == PROG_IMPL_91)

  (void)PROG_CustomSetDownloadVerificationSuccess(0, m_stCurrentSegment.ubSegmentId,PROG_FALSE);

  m_stDiagMessageInfo.pubTxData[PROG_RC_VAL_MEMORY_STATUS_INDEX]                = (u8) (PROG_ROUTINE_FINISHED_OK | PROG_ROUTINE_TYPE_1);
  m_stDiagMessageInfo.pubTxData[PROG_RC_VAL_MEMORY_RESULT_INDEX]                = (u8) PROG_VERIFICATION_FAILED;
  m_stDiagMessageInfo.ulLength = PROG_VAL_MEMORY_RESPONSE_SIZE;
#else
  m_stDiagMessageInfo.pubTxData[PROG_RC_VAL_MEMORY_STATUS_INDEX]                = (u8) (PROG_ROUTINE_FINISHED_NOK | PROG_ROUTINE_TYPE_1);
  m_stDiagMessageInfo.ulLength = PROG_ACTIVE_SBL_RESPONSE_SIZE;
#endif
  m_stDiagMessageInfo.ubDiagStatus = UDS_ACK;

  /* Send response */
  UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);


}

void PROG_Impl90_FinalizeHash(void)
{

  tProgBoolean eProgBoolean_VS;
  tProgBoolean eProgBoolean_Sig;

#if (PROG_CRY_PRESENT == STD_ON)
  tProgStatus eProgStatus = PROG_E_OK;
#endif

  eProgBoolean_VS  = PROG_Impl90_IsSignatureAddress(m_stCurrentSegment.ulStartAddress);
  eProgBoolean_Sig = PROG_Impl90_IsVerificationStructureAddress(m_stCurrentSegment.ulStartAddress);

  if((FALSE == eProgBoolean_VS) && (FALSE == eProgBoolean_Sig))
  {
        PROG_ComputeHashFinish(&m_aubComputedDigest[0]);
#if (PROG_CRY_PRESENT == STD_ON)
        eProgStatus = PROG_GetCryptoStatus();

        /* If errors occurred */
        if (PROG_E_NOT_OK == eProgStatus)
        {
            m_stDiagMessageInfo.ulLength = PROG_NRC_SIZE;
            m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_72;
            /* Go to RTE error state, emit event PROG_EVENT_FAILED*/
            PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
        }
        else
        {
            /* If Crypto return ok, event  PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH will be sent */
            /* If Crypto is busy, nothing to do */
        }
#endif
  }
  else
  {
    /* emit event PROG_EVENT_CRYPTO_FINISH, go to RTE finished */
    PROG_HsmEmit (&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH);
  }
}

void PROG_Impl90_CompareDataBlockHash(void)
{
  u8 ubIdx;
  u8 ubLoopIndex;
  tProgBoolean eProgBoolean_VS;
  tProgBoolean eProgBoolean_Sig;

  eProgBoolean_VS = PROG_Impl90_IsVerificationStructureAddress(m_stCurrentSegment.ulStartAddress);
  eProgBoolean_Sig = PROG_Impl90_IsSignatureAddress(m_stCurrentSegment.ulStartAddress);

  if((FALSE == eProgBoolean_VS) && (FALSE == eProgBoolean_Sig))
  {

      for (ubLoopIndex = 0; (ubLoopIndex < PROG_DIGEST_LENGTH); ubLoopIndex++)
      {
          m_aubHashValueBlock[m_uwCurrentDataBlock].aubDigest[ubLoopIndex] = m_aubComputedDigest[ubLoopIndex];
      }
      /* Current data block is finished, move to the next data block */
      m_uwCurrentDataBlock++;
  }
  else if (TRUE == PROG_Impl90_IsVerificationStructureAddress(m_stCurrentSegment.ulStartAddress))
  {
    /* VS is now downloaded */
    /* reset data block index */
    m_uwCurrentDataBlock = 0;

    /* VS is now downloaded, set all hash status to not ok */
    for(ubIdx = 0; ubIdx < PROG_MAX_RD_PER_BLOCK; ubIdx++)
    {
      for(ubLoopIndex = 0; ubLoopIndex < PROG_DIGEST_LENGTH; ubLoopIndex++)
      {
          m_aubHashValueBlock[ubIdx].aubDigest[ubLoopIndex] = 0x00;
      }
    }
  }
  else
  {
      /* Do nothing Signature is downloaded */
  }
}

void PROG_Impl90_CheckDataBlocksResult(void)
{
   tProgStatus ubProgStatus = PROG_E_OK;

   /* Check length and Version of verification Structure */
   ubProgStatus = PROG_VerifyVSVersionAndLength();

   /* Length and Version are ok */
   if(PROG_E_OK == ubProgStatus)
   {
     /* Check if any of data blocks failed the hash test */
    ubProgStatus = PROG_CheckHashResults();
   }

   /* Hash comparison is ok */
   if(PROG_E_OK == ubProgStatus)
   {
     /* Emit event PROG_EVENT_FINISHED*/
     PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
   }
   else
   {
     /* emit event PROG_EVENT_FAILED*/
     PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
   }

}

tProgBoolean PROG_Impl90_IsVerificationStructureAddress(tProgAddressType ulAddress)
{
  tProgBoolean eProgBoolean;
  u32 ulVSAddress;

   /* Get Address of VS  */
  (void)PROG_GetVSAddress(&ulVSAddress);
  if(ulAddress == ulVSAddress)
  {
    eProgBoolean = TRUE;
    /* This function is called from RD context which means that a new VS will be downloaded */
    /* save the length to be written of VS */
    m_ulVSWrittenData = m_stReprogInfo.ulMemorySizeExpected;
  }
  else
  {
    eProgBoolean = FALSE;
  }

  return eProgBoolean;
}

tProgBoolean PROG_Impl90_IsSignatureAddress(tProgAddressType ulAddress)
{
  tProgBoolean eProgBoolean;
  u32 ulSignatureAddress;

   /* Get Address of Signature  */
   (void)PROG_GetSignatureAddress(&ulSignatureAddress);
  if(ulAddress == ulSignatureAddress)
  {
    eProgBoolean = TRUE;
  }
  else
  {
    eProgBoolean = FALSE;
  }

  return eProgBoolean;
}

void PROG_Impl90_Entry_SignatureCheck(void)
{
    u32 ulVSAddress;
    u32 ulSignatureAddress;
    u32 ulVSSize;

    /* Get Address of VS */
    (void)PROG_GetVSAddress(&ulVSAddress);
    (void)PROG_GetSignatureAddress(&ulSignatureAddress);


    ulVSSize = m_ulVSWrittenData;

    /* Initialize the status of check memory to "Failed" */
    m_ubValidateMemoryStatus = PROG_WRONG_SIGNATURE;

    /* Start Address */
    m_aubDataToBeSigned[0] = (u8)((ulVSAddress & 0xFF000000U) >> 24U);
    m_aubDataToBeSigned[1] = (u8)((ulVSAddress & 0x00FF0000U) >> 16U);
    m_aubDataToBeSigned[2] = (u8)((ulVSAddress & 0x0000FF00U) >> 8U);
    m_aubDataToBeSigned[3] = (u8)(ulVSAddress & 0x000000FFU);

    /* Length */
    m_aubDataToBeSigned[4] = (u8)((ulVSSize & 0xFF000000U) >> 24U);
    m_aubDataToBeSigned[5] = (u8)((ulVSSize & 0x00FF0000U) >> 16U);
    m_aubDataToBeSigned[6] = (u8)((ulVSSize & 0x0000FF00U) >> 8U);
    m_aubDataToBeSigned[7] = (u8)(ulVSSize & 0x000000FFU);

    /* Read VS */
    (void)PROG_MemDataAccess( m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,PROG_MEM_OPERATION_TYPE_READ, ulVSAddress,ulVSSize, &m_aubDataToBeSigned[8]);
    /*Read Signature*/
    (void)PROG_MemDataAccess( m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,PROG_MEM_OPERATION_TYPE_READ, ulSignatureAddress, PROG_SIGNATURE_SIZE, &m_aubSignature[0]);

    /* One step signature calculation on the actual data of VS (without padding) */
    PROG_GetPublicKey(&m_stProgAsymPublicKey);
    (void)PROG_VerifySignature
    (
        &m_stProgAsymPublicKey,
        m_aubDataToBeSigned,
        ulVSSize + PROG_ERASE_ADDR_LEN + PROG_ERASE_SIZE_LEN,
        &m_aubSignature[0]
    );

}


NCS_PRI_VAR void PROG_GetVSAddress(u32 * pulVSAddress)
{
#if (PROG_IMPL_VARIANT == PROG_IMPL_90)
  /* Read VS from Memory  */
  /* SBL is always in the RAM */
  *pulVSAddress = PROG_SBL_VS_START_ADDRESS;
#else
       /* SBL variant */
       /* Get Address of VS  */
       (void)Prog_GetLogicalBlockVerifStructure(m_stCurrentSegment.ubSegmentId, pulVSAddress);
#endif
}

NCS_PRI_VAR void PROG_GetSignatureAddress(u32 * pulSignatureAddress)
{
#if (PROG_IMPL_VARIANT == PROG_IMPL_90)
  /* Read VS from Memory  */
  /* SBL is always in the RAM */
  *pulSignatureAddress = PROG_SBL_VS_START_ADDRESS - PROG_SIGNATURE_OFFSET;
#else
       /* SBL variant */
       /* Get Address of Signature  */
       (void)Prog_GetLogicalBlockSignature(m_stCurrentSegment.ubSegmentId, pulSignatureAddress);
#endif
}


NCS_PRI_VAR void PROG_GetDigestFromVS(u16 uwDataBlockIndex,u8*aubDigest)
{
  u8 aubData[PROG_DIGEST_LENGTH];
  u8 ubIdx;

  u32 ulVSAddress;

  PROG_GetVSAddress(&ulVSAddress);

   ulVSAddress += PROG_DATA_BLOCKS_USEFUL_DATA_OFFSET + PROG_DATA_BLOCKS_HASH_OFFSET + (PROG_DATA_BLOCKS_USEFUL_DATA_SIZE * (u32)uwDataBlockIndex);

   /* Read hash value from memory */

  (void)PROG_MemDataAccess(m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,PROG_MEM_OPERATION_TYPE_READ, ulVSAddress, PROG_DIGEST_LENGTH, aubData);

  /* Hash value */
  for(ubIdx = 0; ubIdx <PROG_DIGEST_LENGTH; ubIdx++)
  {
    aubDigest[ubIdx] = aubData[ubIdx];

  }

}

#if (PROG_IMPL_VARIANT == PROG_IMPL_91)
NCS_PRI_VAR void PROG_GetDataBlockNbrFromVS(u16 *uwBlockNumber)
{
  u8 aubData[PROG_DATA_BLOCKS_COUNT_SIZE];
  u32 ulVSAddress;

   /* SBL variant */
   /* Get Address of VS  */
   (void)Prog_GetLogicalBlockVerifStructure(m_stCurrentSegment.ubSegmentId, &ulVSAddress);
   ulVSAddress += PROG_DATA_BLOCKS_COUNT_MSB_OFFSET;
  (void)PROG_MemDataAccess( m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,PROG_MEM_OPERATION_TYPE_READ, ulVSAddress, PROG_DATA_BLOCKS_COUNT_SIZE, aubData);
  (*uwBlockNumber)  = (u16)((u16)(aubData[0]) << 8);
  (*uwBlockNumber) |= (u16)(aubData[1]);
}

NCS_PRI_VAR void PROG_GetVSVersion(u16 *uwVersion)
{
  u8 aubData[PROG_DATA_BLOCKS_COUNT_SIZE];
  u32 ulVSAddress;

   /* SBL variant */
   (void)Prog_GetLogicalBlockVerifStructure(m_stCurrentSegment.ubSegmentId, &ulVSAddress);
  (void)PROG_MemDataAccess( m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,PROG_MEM_OPERATION_TYPE_READ, ulVSAddress, PROG_VS_VERSION_SIZE, aubData);
  (*uwVersion)  = (u16)((u16)(aubData[0]) << 8);
  (*uwVersion) |= (u16)(aubData[1]);
}
#endif

NCS_PRI_VAR tProgStatus PROG_VerifyVSVersionAndLength(void)
{
  u16 uwDataBlockNbr = 0U;
  /* value different than 0 because the current version ID is already 0 */
  u16 uwVSVersion = 0xEBEBU;
  tProgStatus ubProgStatus = PROG_E_OK;
  u32 ulExpectedLength;
#if (PROG_IMPL_VARIANT == PROG_IMPL_90)
  u8 aubData[2];
#endif

  /* Check Version */
#if (PROG_IMPL_VARIANT == PROG_IMPL_91)
  /* SBL variant */
    PROG_GetVSVersion(&uwVSVersion);
#else
  ubProgStatus = PROG_MemDataAccess(PROG_MEM_TYPE_RAM ,PROG_MEM_OPERATION_TYPE_READ, PROG_SBL_VS_START_ADDRESS, PROG_VS_VERSION_SIZE, aubData);
  if(PROG_E_OK == ubProgStatus)
  {
    uwVSVersion = (u16)((u16)aubData[0] << 8);
    uwVSVersion |= (u16)aubData[1];
  }
#endif
  if(PROG_E_OK == ubProgStatus)
  {
    if(uwVSVersion != (u16)PROG_EXPECTED_VS_VERSION)
    {
      ubProgStatus = PROG_E_NOT_OK;
      m_ubValidateMemoryStatus = PROG_INVALID_VS_VERSION;
    }
  }

  /* Version is ok, check length  */
  if(PROG_E_OK == ubProgStatus)
  {
    /* Check Length */
#if (PROG_IMPL_VARIANT == PROG_IMPL_91)
    /* SBL variant */
      PROG_GetDataBlockNbrFromVS(&uwDataBlockNbr);
#else
    ubProgStatus = PROG_MemDataAccess(PROG_MEM_TYPE_RAM ,PROG_MEM_OPERATION_TYPE_READ, PROG_SBL_VS_START_ADDRESS + PROG_DATA_BLOCKS_COUNT_MSB_OFFSET, PROG_DATA_BLOCKS_COUNT_SIZE, aubData);
    if(PROG_E_OK == ubProgStatus)
    {
      uwDataBlockNbr = (u16)((u16)aubData[0] << 8);
      uwDataBlockNbr |= (u16)aubData[1];
    }
    if(PROG_E_OK == ubProgStatus)
#endif
    {
      ulExpectedLength = PROG_VS_VERSION_SIZE + PROG_DATA_BLOCKS_COUNT_SIZE + ((u32)uwDataBlockNbr*PROG_DATA_BLOCKS_USEFUL_DATA_SIZE);

      if(m_ulVSWrittenData != ulExpectedLength)
      {
        ubProgStatus = PROG_E_NOT_OK;
        m_ubValidateMemoryStatus = PROG_INVALID_VS_BLKNBR;
      }
    }
  }

  return ubProgStatus;
}

NCS_PRI_VAR tProgStatus PROG_CheckHashResults(void)
{
   tProgStatus ubProgStatus = PROG_E_OK;
   u16 uwIdx;
   u16 uwDataBlockNbr = 0;
   u8 ubLoopIndex;
   u8 aubDigest[PROG_DIGEST_LENGTH];
   tProgStatus ubDataBlockStatus = PROG_E_OK;

#if (PROG_IMPL_VARIANT == PROG_IMPL_90)
   u8 aubData[PROG_DATA_BLOCKS_COUNT_SIZE];
#endif

#if (PROG_IMPL_VARIANT == PROG_IMPL_91)
   /* SBL variant */
    PROG_GetDataBlockNbrFromVS(&uwDataBlockNbr);

#else
   ubProgStatus = PROG_MemDataAccess(PROG_MEM_TYPE_RAM ,PROG_MEM_OPERATION_TYPE_READ, PROG_SBL_VS_START_ADDRESS + PROG_DATA_BLOCKS_COUNT_MSB_OFFSET, PROG_DATA_BLOCKS_COUNT_SIZE, aubData);
   if(PROG_E_OK == ubProgStatus)
   {
     uwDataBlockNbr = (u16)((u16)aubData[0] << 8);
     uwDataBlockNbr |= (u16)aubData[1];
   }
   else
   {
     m_ubValidateMemoryStatus = PROG_WRONG_HASH;
   }

   if(PROG_E_OK == ubProgStatus)
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_91)*/
   {
     /* Check that all data blocks are downloaded and their hash is correct */
     for(uwIdx = 0; uwIdx < uwDataBlockNbr; uwIdx++)
     {
          /*Get the current blocks Digest from VS*/
          PROG_GetDigestFromVS(uwIdx , &aubDigest[0]);

          for (ubLoopIndex = 0; ((ubLoopIndex < PROG_DIGEST_LENGTH)&&(PROG_E_OK == ubDataBlockStatus)); ubLoopIndex++)
          {
               /* Compare with stored Digest value from RTE */
               if (m_aubHashValueBlock[uwIdx].aubDigest[ubLoopIndex] != aubDigest[ubLoopIndex])
               {
                  ubDataBlockStatus = PROG_E_NOT_OK;
               }
          }
          /* update the hash status in the data block array */
          ubProgStatus |= ubDataBlockStatus;

     }

     if(PROG_E_NOT_OK == ubProgStatus)
     {
       m_ubValidateMemoryStatus = PROG_WRONG_HASH;
     }
   }

   return ubProgStatus;
}
#endif
