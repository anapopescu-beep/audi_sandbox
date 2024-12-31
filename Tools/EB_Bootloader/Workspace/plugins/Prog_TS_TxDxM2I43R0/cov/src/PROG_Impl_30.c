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
/*%%   _____________________________   %%  \file PROG_Impl_30.c                  */
/*%%  |                             |  %%  \brief Impl30 SignatureCheck Feature  */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.15.255 BL-3.X */
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
 *
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
#include "board.h"
#include <PROG_Trace.h>                              /* Dbg related macros for EB */

#if (PROG_CRY_PRESENT == STD_ON)
#include "PROG_Cry.h"
#endif
#if ((PROG_IMPL_VARIANT == PROG_IMPL_30) || (PROG_IMPL_VARIANT == PROG_IMPL_31))
/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Function Prototypes                                                  */

/*-------------------------------------------------------------------------------*/
/* - Public Callback Prototypes                                                  */

/*                                                                               */
/*===============================================================================*/

/*============================ PRIVATE DEFINITIONS ==============================*/

/*-------------------------------------------------------------------------------*/
/* - Private Variables                                                           */
/*                                                                               */
#if (PROG_IMPL_VARIANT == PROG_IMPL_30)
#if ((PROG_SIGNATURE_CALCULATION == STD_ON) || (PROG_SECURE_APPLI_CHECKSUM_COMPUTATION == STD_ON))
NCS_PRI_VAR u8 m_ubSegmentID;
NCS_PRI_VAR u32 m_ubSignatureStartAddress;
#endif /* ((PROG_SIGNATURE_CALCULATION == STD_ON) || (PROG_SECURE_APPLI_CHECKSUM_COMPUTATION == STD_ON)) */
#if (PROG_SIGNATURE_CALCULATION == STD_ON)
NCS_PRI_VAR u8 m_aubSignature[PROG_SIGNATURE_LENGTH];
#endif /* (PROG_SIGNATURE_CALCULATION == STD_ON)*/
NCS_PRI_VAR u32 m_ulStartAddress;
NCS_PRI_VAR u32 m_ulEndAddress;
NCS_PRI_VAR tProgStatus m_ubSignatureCheckFinish;
#endif

/*===============================================================================*/

/*-------------------------------------------------------------------------------*/
/* - Private Macros                                                              */
/*                                                                               */
/*===============================================================================*/

/*-------------------------------------------------------------------------------*/
/* - Private Function Prototypes                                                 */
/*                                                                               */

/*===============================================================================*/

/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */

void PROG_IMPL30_SignatureHandling(tSignatureHandlingstatus m_setCHSstatus)
{
#if (PROG_IMPL_VARIANT == PROG_IMPL_30)
    u8 eProgStatus = PROG_E_OK;
#if (PROG_SIGNATURE_CALCULATION == STD_ON)
    tProgCryState eState;
#endif /*(PROG_SIGNATURE_CALCULATION == STD_ON)*/
    ICOV(1207);switch (m_setCHSstatus)
    {
    case PROG_CRCDONE:

        /* Retrieve address */
        ICOV(1208);m_ulStartAddress = PROG_RetrieveRequestData32(&m_stDiagMessageInfo.pubData[PROG_CPD_STARTADDR_OFFSET]);

        /* Retrieve and store the EndAddress */
        m_ulEndAddress = PROG_RetrieveRequestData32(&m_stDiagMessageInfo.pubData[PROG_CPD_ENDADDR_OFFSET]);

        /* Reset the flag to start the Signature verification for this segment*/
        m_ubSignatureCheckFinish = PROG_E_BUSY;

#if ((PROG_SIGNATURE_CALCULATION == STD_ON) || (PROG_SECURE_APPLI_CHECKSUM_COMPUTATION == STD_ON))
        /* Initialize before fetching from the callout*/
        m_ubSegmentID = 0xFF;
        /* Get the the parameters for the SecureBoot Checksum and Signature Verification */
        PROG_CustomGetVerificationParameters(&m_ulStartAddress, &m_ulEndAddress ,&m_ubSignatureStartAddress);

        /* Get the Segment ID for the received address that is configured */
        eProgStatus = PROG_GetSegmentByAddress(m_ulStartAddress, (m_ulEndAddress - m_ulStartAddress + 1u), PROG_MEM_OPERATION_TYPE_READ ,&m_ubSegmentID);

        if(((eProgStatus != PROG_E_OK) \
            && (stConfigSegment[0u].ulStartAddress <= m_ulStartAddress) && (stConfigSegment[PROG_SEGMENT_NB - 1u].ulEndAddress >= m_ulEndAddress))?BCOV(1209):!BCOV(1210))
        {
            /* This is a Check programming Dependency request not for a Single segment */
            m_ubSegmentID = PROG_SEGMENT_NB;
            eProgStatus = PROG_E_OK;
        }
#endif /* ((PROG_SIGNATURE_CALCULATION == STD_ON) || (PROG_SECURE_APPLI_CHECKSUM_COMPUTATION == STD_ON)) */
#if (PROG_SIGNATURE_CALCULATION == STD_ON)
        if((eProgStatus == PROG_E_OK)?BCOV(1211):!BCOV(1212))
        {
            if(((m_ubSegmentID == PROG_SEGMENT_NB) || (stConfigSegment[m_ubSegmentID].eVerifySignature == PROG_FALSE))?BCOV(1213):!BCOV(1214))
            {
                /* Either the Signature verification is not configured to be performed for this segment
                 * or this is Check programming Dependency request not for a particular single segment,
                 * so bypass Signature Verification. */
                /* PROG_E_OK already set, nothing to do*/
            }
            else
            {
                /* Wait to start Verification*/
                eProgStatus = PROG_E_BUSY;
            }
        }
        else
        {
            /*Send NRC*/
            eProgStatus = PROG_E_NOT_OK;
        }
#else
        /*Signature Check Feature is Disabled*/
        eProgStatus = PROG_E_OK;
#endif /* (PROG_SIGNATURE_CALCULATION == STD_ON) */
        break;

#if (PROG_SIGNATURE_CALCULATION == STD_ON)
    case PROG_CRYPTOSTARTUPDATEINPROGRESS:
        ICOV(1215);eState = PROG_GetCryptoState();
        if(((eState == PROG_IDLE) && (m_ubSignatureCheckFinish == PROG_E_BUSY))?BCOV(1216):!BCOV(1217))
        {
            /* Start the Signature verification for the current Segment*/
            eProgStatus = PROG_MemDataAccess(m_astCfgMemory[stConfigSegment[m_ubSegmentID].ubMemoryIdx].eMemoryType,
            PROG_MEM_OPERATION_TYPE_READ, m_ubSignatureStartAddress, PROG_SIGNATURE_LENGTH, (tDataBufferType *)&m_aubSignature[0]);

            if ((eProgStatus == PROG_E_OK)?BCOV(1218):!BCOV(1219))
            {
                /* ---  This call should be done only for the ASR Cry 4.0.3 --- */
                PROG_GetPublicKey(&m_stProgAsymPublicKey);

                eProgStatus = PROG_VerifySignatureStart(&m_stProgAsymPublicKey, (u8*)m_aubSignature);

                /*Reset the Variables for Signature Update Operation*/
                m_stDataProgVerification.ulAdd = m_ulStartAddress;
                m_stReprogInfo.ulReceivedSizeOfData = m_ulEndAddress - m_ulStartAddress  +1U;
                m_stDataProgVerification.ubAlgo = PROG_VERIFY_SIGNATURE;
                m_stDataProgVerification.ulCnt = 0u;
            }
            else
            {
                /* Error during Obtaining Signature for the Segment*/
                eProgStatus = PROG_E_NOT_OK;
            }
        }
        else if (((eState == PROG_SIGNATURE_CHECK_UPDATE) || (eState == PROG_SIGNATURE_CHECK_UPDATE_END) \
        || (eState == PROG_SIGNATURE_CHECK_START_END) || (eState == PROG_SIGNATURE_CHECK_START))?BCOV(1220):!BCOV(1221))
        {
            (void)PROG_CRC();
            eProgStatus = PROG_E_BUSY;
        }
        else
        {
           /*Process is still running*/
           eProgStatus = PROG_E_BUSY;
        }
        break;

    case PROG_CRYPTOUPDATEDONE:
        /*Start Finish-Signature operation*/
        ICOV(1222);PROG_VerifySignatureFinish((u8*)m_aubSignature);
        eProgStatus = PROG_E_BUSY;
        break;

    case PROG_CRYPTOFINISHDONE:
        /*Signature verification passed */
        ICOV(1223);eProgStatus = PROG_E_OK;
        break;

    case PROG_ERASESTART:
        /* Signature verification failed so start to erase the downloaded segment */
        ICOV(1224);m_stCurrentSegment.ubSegmentNbr = 0x01;

        /* NRC shall be sent after the current Invalid Segment Erase */
        eProgStatus = PROG_E_BUSY;
        break;

    case PROG_ERASEDONE:
        /* Erase Operation complete */
        ICOV(1225);eProgStatus = PROG_E_NOT_OK;
        break;

#endif /*(PROG_SIGNATURE_CALCULATION == STD_ON) */
    default:
        /* Unexpected Case */
        ICOV(1226);eProgStatus = PROG_E_NOT_OK;
        break;
    }
    if ((eProgStatus == PROG_E_OK)?BCOV(1227):!BCOV(1228))
    {
      /* Indicate Signature Processing Completion */
      PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);

      /* Update the Variables for the next operation */
      m_stDataProgVerification.ubAlgo = PROG_VERIFY_CRC;
      m_ubSignatureCheckFinish = PROG_E_OK;
    }
    else if((eProgStatus == PROG_E_NOT_OK)?BCOV(1229):!BCOV(1230))
    {
      /*Report error or failure*/

      /* When the Erase is finished, the Finish event is already emitted so avoid re-emitting */
      if((m_setCHSstatus != PROG_ERASEDONE)?BCOV(1231):!BCOV(1232))
      {
          /* Indicate Signature Processing Completion */
          PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
      }
      /* Update the Variables for the next operation */
      m_stDataProgVerification.ubAlgo = PROG_VERIFY_CRC;
      m_ubSignatureCheckFinish = PROG_E_CHECK_FAILED;
    }
    else
    {
        /* Nothing to do, busy processing */
    }
#else
    ICOV(1233);OSC_PARAM_UNUSED(m_setCHSstatus);
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_30)*/
ICOV(1233);}

void PROG_IMPL30_HSMEntry(void)
{
#if (PROG_IMPL_VARIANT == PROG_IMPL_30)
#if (PROG_SECURE_APPLI_CHECKSUM_COMPUTATION == STD_ON)

    ICOV(1234);if(((m_ubSegmentID < PROG_SEGMENT_NB) && (PROG_E_CHECK_FAILED != m_ubSignatureCheckFinish))?BCOV(1235):!BCOV(1236))
    {
        /* If authenticated or secure Boot feature is used and current block is authenticated one, delay response
        until application checksum is finished */
        if ((PROG_TRUE != stCfgBlockSecureBootInfo[m_ubSegmentID].ubBlockVerifiedInSecure)?BCOV(1237):!BCOV(1238))
        {
            /*Bypass Secure Boot Verification*/
            PROG_SecurityChecksumNotification();
        }
        else
        {
            /*Start Secure Boot Verification*/
            PROG_SecurityComputeAppChecksum();
        }
    }
    else if(((PROG_SEGMENT_NB == m_ubSegmentID) && (PROG_E_CHECK_FAILED != m_ubSignatureCheckFinish))?BCOV(1239):!BCOV(1240))
    {
        /* This is a Check programming Dependency request not for a Single segment so skip the SecureBoot verification */
        PROG_SecurityChecksumNotification();
    }
    else
    {
        /*Invalid Signature or Invalid Segment Id*/
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
    }
#else
    /*Bypass Secure Application Checksum Update*/
    ICOV(1241);if ((PROG_E_OK == m_ubSignatureCheckFinish)?BCOV(1242):!BCOV(1243))
    {
        /* Secure Appl checksum bypassed and Signature verification success reported*/
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);

        /* send positive response only when SecureBoot operations need not be performed*/
        UDS_LongRequestEnd(PROG_CHK_PROG_DEP_POS_RESPONSE_SIZE, m_stDiagMessageInfo.pubTxData, UDS_ACK);

#if (PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)
        /* Good Checksum/Signature, update ProgrammingStatus */
        PROG_SetProgrammingStatus(PROG_RC_CHECKSUM_VERIFY, PROG_TRUE);
#endif /*(PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)*/

        /* Set validity flag */
        PROG_CustomSetAppValidity(PROG_RetrieveRequestData32(&m_stDiagMessageInfo.pubData[PROG_CPD_STARTADDR_OFFSET]), PROG_RetrieveRequestData32(&m_stDiagMessageInfo.pubData[PROG_CPD_ENDADDR_OFFSET]));
    }
    else
    {
        /* Secure Appl. checksum bypassed and Signature verification failure reported*/
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
    }
#endif
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_30)*/
ICOV(1241);}
#endif /*((PROG_IMPL_VARIANT == PROG_IMPL_30) || (PROG_IMPL_VARIANT == PROG_IMPL_31)) */
