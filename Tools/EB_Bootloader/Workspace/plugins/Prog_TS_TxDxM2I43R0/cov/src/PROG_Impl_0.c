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
/*%%   _____________________________   %%  \file PROG_Impl_0.c                  */
/*%%  |                             |  %%  \brief PROG layer source plugin file  */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.43.0 BL3 */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*===============================================================================*/
/* Copyright 2020 by Elektrobit Automotive GmbH                                  */
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

/*=============================== FILE INCLUSION ================================*/
/*                                                                               */
#define COV_BASE 0u /* COV_START_(FILE) */
#ifndef /*Prog*/_cov_h_
  #define /*Prog*/_cov_h_
  /* #include <Prog_cov.h> */
  extern volatile unsigned char /*Prog_*/coveragedata[];
  #define ICOV(x) /*Prog_*/coveragedata[(COV_BASE+(x))>>3u]|=1u<<((COV_BASE+(x))&7u)
  #define BCOV(x) (ICOV(x),1)
#endif /*Prog_cov_h_*/

#include "EB_Prj.h"
#include "PROG_Priv.h"
#include "PROG_Hsm.h"
#include "PROG_HsmPROG.h"
#include <PROG_Trace.h>                        /* Dbg related macros for EB */
#if (PROG_COMPRESSION_ENABLE == STD_ON)
#include "PROG_Decomp.h"
#endif
#include "board.h"
#if ((PROG_IMPL_VARIANT == PROG_IMPL_3) || (PROG_IMPL_VARIANT == PROG_IMPL_4)|| (PROG_IMPL_VARIANT == PROG_IMPL_5))
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

/*-------------------------------------------------------------------------------*/
/* - Private Types                                                               */

/*-------------------------------------------------------------------------------*/
/* - Private Variables                                                           */

NCS_PRI_VAR tProgStatus m_ubValidVDSAddress;
NCS_PRI_VAR tVDSlayout m_stVDSlayout;
/*===============================================================================*/

/*-------------------------------------------------------------------------------*/
/* - Private Macros                                                              */

/*-------------------------------------------------------------------------------*/
/* - Private Function Prototypes                                                 */
#if ((PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
#if PROG_SUBMITSIGNATURE_WITH_ADDRESS == STD_ON
NCS_PRI_FCT tProgStatus PROG_ReadAddressLengthOfVDS(u8 ubSegId, u32* pulStartAddress, u32* pulLength);
#endif /* PROG_SUBMITSIGNATURE_WITH_ADDRESS == STD_ON */
#endif /* PROG_IMPL_VARIANT == PROG_IMPL_4 */
/*                                                                               */
/*===============================================================================*/

/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */

#if ((PROG_IMPL_VARIANT == PROG_IMPL_4)|| (PROG_IMPL_VARIANT == PROG_IMPL_5))
#if (PROG_SUBMITSIGNATURE_WITH_ADDRESS == STD_ON)
NCS_PRI_FCT tProgStatus PROG_ReadAddressLengthOfVDS(u8 ubSegId, u32* pulStartAddress, u32* pulLength)
{
    tProgStatus eProgStatus;
    u8 ubSegmentIdLoc;
    ICOV(576);ubSegmentIdLoc = ubSegId;

    /* Fetch the VDS data from the callback */
    eProgStatus = PROG_CustomVDStable_update(&m_stVDSlayout, &ubSegmentIdLoc, PROG_VDSUPDATE_READVDS);

    /* Update Start address and Length to perform Signature verification on the VDS table*/
    /* Deviation MISRAC2012-1 */
    *pulStartAddress = (u32)&m_stVDSlayout;
    *pulLength       = PROG_VDS_SIZE;

    return eProgStatus;
}
#endif /* PROG_SUBMITSIGNATURE_WITH_ADDRESS == STD_ON */
#endif /* ((PROG_IMPL_VARIANT == PROG_IMPL_4 || (PROG_IMPL_VARIANT == PROG_IMPL_5))*/

void PROG_StoreVerificationDataStructure(const tSegmentType* pstCurrentSegment, const u8* aubDigest)
{
    u8 ubLoopIndex;
    u8 ubSegmentIdLoc;
    /* Store Length in Verification Data structure */
#if (PROG_COMPRESSION_ENABLE == STD_ON)
    ICOV(577);if ((TRUE == m_stReprogInfo.ubCompRequired)?BCOV(578):!BCOV(579))
    {
        m_stVDSlayout.ulBlock_Length = m_stReprogInfo.ulTotalDecompDataWrite;
    }
    else
    {
        m_stVDSlayout.ulBlock_Length = m_stReprogInfo.ulReceivedSizeOfData;
    }
#else
    ICOV(580);m_stVDSlayout.ulBlock_Length = m_stReprogInfo.ulReceivedSizeOfData;
#endif

    /* Store Start Address in Verification Data structure */
    ICOV(580);m_stVDSlayout.ulBlock_StartAddress = pstCurrentSegment->ulStartAddress;

    /* Store Calculated Hash in Verification Data structure */
    for (ubLoopIndex = 0; (((ubLoopIndex < PROG_DIGEST_LENGTH)))?BCOV(581):!BCOV(582);  ubLoopIndex++)
    {
        m_stVDSlayout.aubBlockDigest[ubLoopIndex] = aubDigest[ubLoopIndex];
    }
    ubSegmentIdLoc = pstCurrentSegment->ubSegmentId;
    /* Callback return value ignored as this is just a notification to the Custom callback
     * indicating VDS shall be updated in the desired memory type and the memory address*/
    (void)PROG_CustomVDStable_update(&m_stVDSlayout, &ubSegmentIdLoc, PROG_VDSUPDATE_STORE);
}

void PROG_ClearVerificationDataStructure(u8 ubSegId)
{
    u8 ubSegmentIdLoc;
    ICOV(583);ubSegmentIdLoc = ubSegId;

    /* Callback return value ignored as this is just a notification to the Custom callback indicating VDS shall be cleared */
    (void)PROG_CustomVDStable_update(&m_stVDSlayout, &ubSegmentIdLoc, PROG_VDSUPDATE_CLEAR);
}

void PROG_Entry_ValidationFailed(void)
{
    ICOV(584);DBG_PROG_ENTRY_VALIDATIONFAILED_ENTRY();
#if (PROG_IMPL_VARIANT == PROG_IMPL_3)
    (void)PROG_MemDataAccess(m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,
            PROG_MEM_OPERATION_TYPE_ERASE, m_stCurrentSegment.ulStartAddress, m_stCurrentSegment.ulSize, NULL_PTR);
    PROG_CustomStoreResetCause(PROG_RESET_CAUSE_SBLACTIVEFAIL, PROG_FALSE);
    PROG_CustomSetOpenProgSession();
#endif
#if ((PROG_IMPL_VARIANT == PROG_IMPL_4)|| (PROG_IMPL_VARIANT == PROG_IMPL_5))
    (void)PROG_CustomSetDownloadVerificationSuccess(0U, m_stCurrentSegment.ubSegmentId, PROG_FALSE);
#endif
    if ((m_ubValidVDSAddress ==PROG_E_OK)?BCOV(585):!BCOV(586))
    {
        m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_VERIF_RESULTS_BASE_INDEX] = (u8)(PROG_ROUTINE_SELFTERM | PROG_ROUTINE_PREDIF | PROG_ROUTINE_RESAVAILABLE);
        m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_VERIF_RESULTS_BASE_INDEX + 1U]= PROG_RC_STATUS_RECORD_VERIF_RESULTS_NOT_OK;
        UDS_LongRequestEnd(PROG_RC_STATUS_RECORD_VERIF_RESULTS_SIZE, m_stDiagMessageInfo.pubTxData, UDS_ACK);
    }
    else
    {
        UDS_LongRequestEnd(PROG_NRC_SIZE, m_stDiagMessageInfo.pubTxData, UDS_NRC_31);
    }

    DBG_PROG_ENTRY_VALIDATIONFAILED_EXIT();
}
void PROG_Entry_ValidationFinish(void)
{
    ICOV(587);DBG_PROG_ENTRY_VALIDATIONFINISH_ENTRY();
#if ((PROG_IMPL_VARIANT == PROG_IMPL_4)|| (PROG_IMPL_VARIANT == PROG_IMPL_5))
    (void)PROG_CustomSetDownloadVerificationSuccess(0U, m_stCurrentSegment.ubSegmentId, PROG_TRUE);
#endif
    m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_VERIF_RESULTS_BASE_INDEX] = (u8)(PROG_ROUTINE_SELFTERM | PROG_ROUTINE_PREDIF | PROG_ROUTINE_RESAVAILABLE);
    m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_VERIF_RESULTS_BASE_INDEX + 1U]= PROG_RC_STATUS_RECORD_VERIF_RESULTS_OK;
    UDS_LongRequestEnd(PROG_RC_STATUS_RECORD_VERIF_RESULTS_SIZE, m_stDiagMessageInfo.pubTxData, UDS_ACK);
    DBG_PROG_ENTRY_VALIDATIONFINISH_ENTRY();
}
void PROG_Entry_SignatureVerify(void)
{
    u8* pubStartAddress;
    u32 ulLength;
    tProgStatus eProgStatus;
#if PROG_SUBMITSIGNATURE_WITH_ADDRESS == STD_ON
    u32 ulStartAddress;
    u8 ubSignSegmentId;
#endif
    u16 uwLoopIndex;
    ICOV(588);DBG_PROG_ENTRY_VALIDATIONFINISH_EXIT();
    m_ubValidVDSAddress = PROG_E_OK;
    pubStartAddress = NULL_PTR;

    /*Extract the expected Signature parameter*/
    for (uwLoopIndex = 0; (((uwLoopIndex < PROG_SIGNATURE_LENGTH)))?BCOV(589):!BCOV(590);  uwLoopIndex++)
    {
        m_aubExpectedSignature[uwLoopIndex] = m_stDiagMessageInfo.pubData[PROG_RC_OPTION_RECORD_SIGNATURE_BASE_INDEX + uwLoopIndex];
    }
#if (PROG_SUBMITSIGNATURE_WITH_ADDRESS == STD_ON)
    /*Extract Hash table start address parameter*/
    ulStartAddress = PROG_RetrieveRequestData32(&m_stDiagMessageInfo.pubData[PROG_RC_OPTION_RECORD_HASH_TAB_ADD_BASE_INDEX]);

    /* Deviation MISRAC2012-1 */
    /* Fetch the Segment-Id for the VDS start address retrieved from the UDS request */
    eProgStatus = PROG_CustomVDStable_update((tVDSlayout *)ulStartAddress, &ubSignSegmentId, PROG_VDSUPDATE_GETSEGID_BYADR);

    if ((PROG_E_OK == eProgStatus)?BCOV(591):!BCOV(592))
    {
        /* Read the Start address and Length of the VDS table */
        eProgStatus = PROG_ReadAddressLengthOfVDS(ubSignSegmentId, &ulStartAddress, &ulLength);
        if ((PROG_E_OK == eProgStatus)?BCOV(593):!BCOV(594))
        {
            /* Deviation MISRAC2012-1 */
            pubStartAddress = (u8*) ulStartAddress;
        }
        else
        {
            /* Emit event PROG_HSM_PROG_EV_PROG_EVENT_FAILED to send */
            PROG_HsmEmit (&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
        }
    }

#else
    /* Read Start address and Length to perform Signature verification on the VDS table*/
    /* Deviation MISRAC2012-1 */
    eProgStatus = PROG_CustomVDStable_update(&m_stVDSlayout, &(m_stCurrentSegment.ubSegmentId), PROG_VDSUPDATE_READVDS);
    pubStartAddress = (u8*)&m_stVDSlayout;
    ulLength        = PROG_VDS_SIZE;
#endif /* (PROG_SUBMITSIGNATURE_WITH_ADDRESS == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_4) */

    if(((eProgStatus == PROG_E_OK) && (pubStartAddress != NULL_PTR))?BCOV(595):!BCOV(596))
    {
        PROG_GetPublicKey(&m_stProgAsymPublicKey);
        /* Start Signature computation on the flashed data */
        /* Call crypto library to start the signature verification */
        (void)PROG_VerifySignature
                (
                        &m_stProgAsymPublicKey,
                        pubStartAddress,
                        ulLength,
                        &m_aubExpectedSignature[0]
                );

    }
    else
    {
        m_ubValidVDSAddress = PROG_E_NOT_OK;
        /* Emit event PROG_HSM_PROG_EV_PROG_EVENT_FAILED to send */
        PROG_HsmEmit (&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
    }
    DBG_PROG_ENTRY_VALIDATIONFINISH_EXIT();
}
/*-----------------------------{PROG_ERASE_Check}--------------------------------*/
tProgStatus PROG_ERASE_Check (void)
{
    tProgStatus eProgStatus;
#if (PROG_IMPL_VARIANT == PROG_IMPL_5)
    ICOV(597);eProgStatus = PROG_E_OK;
#else
    ICOV(598);eProgStatus = PROG_E_NOT_OK;
    PROG_Send_NRC(UDS_NRC_31);
#endif
    ICOV(598);return eProgStatus;
}
/*-----------------------------{end PROG_ERASE_Check}---------------------------*/
/*-----------------------------{PROG_SA2_RD_Check}------------------------------*/
tProgStatus PROG_SA2_RD_Check(void)
{
    tProgStatus eProgStatus;
#if (PROG_IMPL_VARIANT == PROG_IMPL_5)
    ICOV(599);eProgStatus = PROG_E_NOT_OK;
    PROG_Send_NRC(UDS_NRC_24);
#else
    ICOV(600);eProgStatus = PROG_RD_Check();
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_5)*/
    ICOV(600);return eProgStatus;
}
/*-----------------------------{end PROG_SA2_RD_Check}--------------------------*/
#endif /*((PROG_IMPL_VARIANT == PROG_IMPL_3) || (PROG_IMPL_VARIANT == PROG_IMPL_4)|| (PROG_IMPL_VARIANT == PROG_IMPL_5))*/

/*-----------------------{PROG_Entry_Validate_Application}--------------------------------*/
void PROG_Entry_Validate_Application(void)
{
#if ((PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
    u16 uwIdx;
    tProgBoolean eProgValidityStatus = PROG_TRUE;
    ICOV(601);DBG_PROG_ENTRY_VALIDATE_APPLICATION_ENTRY();

    for(uwIdx = 0; (((uwIdx < PROG_SEGMENT_NB) && (eProgValidityStatus == PROG_TRUE)))?BCOV(602):!BCOV(603); uwIdx++)
    {
        if (( stConfigSegment[uwIdx].eValidityCheck == PROG_TRUE)?BCOV(604):!BCOV(605))
        {
                eProgValidityStatus = m_aubBlockDownloadStatus[uwIdx];
        }
    }

    if ((eProgValidityStatus == PROG_FALSE)?BCOV(606):!BCOV(607))
    {
        /* Emit event PROG_HSM_PROG_EV_PROG_EVENT_FAILED to send */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
    }
#else
    ICOV(608);DBG_PROG_ENTRY_VALIDATE_APPLICATION_ENTRY();
#endif
    ICOV(608);DBG_PROG_ENTRY_VALIDATE_APPLICATION_EXIT();
}
/*-----------------------{End PROG_Entry_Validate_Application}----------------------------------*/

/*-----------------------{PROG_Do_CheckValidateApplication}--------------------------------*/
void PROG_Do_CheckValidateApplication(void)
{
#if ((PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
    tProgStatus eProgStatus;
    ICOV(609);DBG_PROG_DO_CHECKVALIDATEAPPLICATION_ENTRY();

    /* Check if the Compatibility of SW parts present is correct */
    eProgStatus = PROG_CustomCompatibilityCheck();

    if ((PROG_E_OK == eProgStatus)?BCOV(610):!BCOV(611))
    {
        /* Emit event PROG_EVENT_FINISH */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
    }
    else if ((PROG_E_NOT_OK == eProgStatus)?BCOV(612):!BCOV(613))
    {
        /* Emit event PROG_EVENT_FAILED */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);

    }
    else
    {
        /*Nothing to do*/
    }
#else
    ICOV(614);DBG_PROG_DO_CHECKVALIDATEAPPLICATION_ENTRY();

#endif
    ICOV(614);DBG_PROG_DO_CHECKVALIDATEAPPLICATION_EXIT();
}
/*-----------------------{End PROG_Do_CheckValidateApplication}----------------------------------*/

/*-----------------------{PROG_CheckValidateApplicationFinish}--------------------------------*/
void PROG_CheckValidateApplicationFinish(void)
{

    ICOV(615);DBG_PROG_CHECKVALIDATEAPPLICATIONFINISH_ENTRY();
#if ((PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
    m_stDiagMessageInfo.pubData[4] = (u8)(PROG_ROUTINE_SELFTERM | PROG_ROUTINE_PREDIF | PROG_ROUTINE_RESAVAILABLE); /* Positive response */
    m_stDiagMessageInfo.pubData[5] = (u8)(PROG_APPL_VALID);

    UDS_LongRequestEnd(PROG_CHECKVALIDATEAPPLICATION_POS_RESPONSE_SIZE, m_stDiagMessageInfo.pubData, UDS_ACK);
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_4) */
    DBG_PROG_CHECKVALIDATEAPPLICATIONFINISH_EXIT();
}
/*-----------------------{End PROG_CheckValidateApplicationFinish}----------------------------------*/

/*-----------------------{PROG_CheckValidateApplicationFailed}--------------------------------*/
void PROG_CheckValidateApplicationFailed(void)
{

    ICOV(616);DBG_PROG_CHECKVALIDATEAPPLICATIONFAILED_ENTRY();
#if ((PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
    m_stDiagMessageInfo.pubData[4] = (u8)(PROG_ROUTINE_SELFTERM | PROG_ROUTINE_PREDIF | PROG_ROUTINE_RESAVAILABLE); /* Positive response */
    m_stDiagMessageInfo.pubData[5] = (u8)(PROG_APPL_INVALID);

    UDS_LongRequestEnd(PROG_CHECKVALIDATEAPPLICATION_POS_RESPONSE_SIZE, m_stDiagMessageInfo.pubData, UDS_ACK);
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_4) */
    DBG_PROG_CHECKVALIDATEAPPLICATIONFAILED_EXIT();
}
/*-----------------------{End PROG_CheckValidateApplicationFinish}----------------------------------*/

