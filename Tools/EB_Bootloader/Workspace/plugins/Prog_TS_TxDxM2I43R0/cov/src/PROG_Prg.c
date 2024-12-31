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
/*%%   _____________________________   %%  \file PROG_Prg.c                      */
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
/* NOCOV List
 *
 * NOCOV-FEATURE_NOT_USED:
 *   certain features are implemented but not yet used.
 *
 * Reason:
 * We assume that they are not tested for the moment (will be done later).
 * In order to not impact the coverage, the NOCOV is used.
 *
 * NOCOV-NCS_UNITARY_TEST:
 *   code is deactivated for test.
 *
 * Reason:
 * Test are performed under WINDOWS environment.
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
#include <PROG_Trace.h>                        /* Dbg related macros for EB */
#if (PROG_CRY_PRESENT == STD_ON)
#include "PROG_Cry.h"
#endif /* (PROG_CRY_PRESENT == STD_ON) */
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
#include "PROG_Encrypt.h"
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON) */
#if (PROG_COMPRESSION_ENABLE == STD_ON)
#include "PROG_Decomp.h"
#endif
#if (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON)
#include "PROG_DowngradeProtection.h"
#endif /* (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON) */

/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */
#if ( ((PROG_IMPL_VARIANT == PROG_IMPL_20) || (PROG_IMPL_VARIANT == PROG_IMPL_60) || (PROG_IMPL_VARIANT == PROG_IMPL_10) || (PROG_IMPL_VARIANT == PROG_IMPL_90) || (PROG_IMPL_VARIANT == PROG_IMPL_40) )&& (PROG_RESPOND_TO_PROG_SESSION == STD_ON))
tProgBoolean m_ubSendResponsetoOpenProgramming;
#endif

#if (PROG_RESET_CAUSE_ENABLE == STD_ON)
tProgBoolean m_ubSendResponseafterReset;
#endif

tDiagMessageInfo m_stDiagMessageInfo; /* Contains request information */
u8 * m_pubLastBufTxData;  /* Pointer to last Tp buffer used for transmission*/
tSegmentType m_stCurrentSegment; /* Information concerning the current transfer data operation */
tProgVerificationInfo m_stDataProgVerification; /* Information for the programming verification */
#if PROG_SIGNATURE_CALCULATION == STD_ON
u8 m_aubExpectedSignature[PROG_SIGNATURE_LENGTH];
#endif

#if (PROG_CRY_PRESENT == STD_ON)
#if ((PROG_HASH_CALCULATION == STD_ON) || ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_STANDARD_REPROG)))
u8 m_aubComputedMessageDigest[PROG_DIGEST_LENGTH];
#endif
#endif /* #if (PROG_CRY_PRESENT == STD_ON) */

#if (PROG_SLEEP_MANAGEMENT_TYPE == PROG_SLEEP_MANAGEMENT_TIMEOUT)
tProgBoolean m_ubBootInDefaultSession; /* Flag to indicate if the bootloader is in default session */
#endif

u8 m_ubProgIsInit = FALSE;

#if(PROG_CRC_CALCULATION == PROG_TD_CRC32)
/* Flag indicating the start of the CRC computation */
tProgBoolean m_ubCrcStart;
#endif

/* Flag indicating if Response to Prog session from appli shall be done */
u8 m_ubSimulateProgSessionWithResponse;

#if (PROG_BLOCKID_IN_FINGERPRINT == STD_ON)
u8 m_ubFpBlockId;
#endif /*(PROG_BLOCKID_IN_FINGERPRINT == STD_ON)*/

/* Information concerning the full download process */
tReprogInfo m_stReprogInfo;
/* Information concerning the current transfer data operation */
tWriteInfo m_stWriteInfo;
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
/* Allow to finish decryption operation */
tProgBoolean m_ubFinishDecryption;
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
#if (PROG_BLU_ACTIVE == STD_ON)
tProgBoolean m_ubBLUPattern;
#endif /*(PROG_BLU_ACTIVE == STD_ON)*/
/* Flag to indicate the Prog Verification method */
u8 m_ubVerificationMethod = 0xFFU;
/* Flag to indicate the CRC calculation method */
u8 m_ubCRC_Calculation;
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
#if (((PROG_IMPL_VARIANT == PROG_IMPL_40) || (PROG_IMPL_VARIANT == PROG_IMPL_50) || (PROG_IMPL_VARIANT == PROG_IMPL_60)) && (PROG_CHECK_MEMORY_ENABLE == STD_ON))
/* Contains first Check Memory answer information */
NCS_PRI_VAR tFirstCheckMemoryAnswerInfo m_stFirstCheckMemoryAnswerInfo;
/* Flag which mentions if the first Check Memory request has been received */
NCS_PRI_VAR u8 m_ubCheckMemoryFinishState;
/* Mentions if the content of the current Check Memory request is the same that the first frame received */
NCS_PRI_VAR u8 m_ubSameRequest;
#elif (((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_STANDARD_REPROG)) && (PROG_CHECK_MEMORY_ENABLE == STD_ON))
/* Flag which mentions if the first Check Memory request has been received */
NCS_PRI_VAR u8 m_ubCheckMemoryFinishState;
/* Mentions if the content of the current Check Memory request is the same that the first frame received */
NCS_PRI_VAR u8 m_ubSameRequest;
#endif
#if(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)
NCS_PRI_VAR u8 m_ubPendingNRC78;
NCS_PRI_VAR u8 m_ubPendingSendNRC78;
#endif
/* variable storing the length of streaming data received */
NCS_PRI_VAR u16 m_uwStreamingLength;

/* Use to avoid having streaming after TD has been received */
NCS_PRI_VAR u8 m_ubTDReceive;

/* Flag checking if first call is done after initialization */
NCS_PRI_VAR u8 m_ubProgFirstCall;

#if ((PROG_CSM_DECRYPTION_ENABLE == STD_ON)&& (PROG_COMPRESSION_ENABLE == STD_ON))
/* Flag to check if RTE has been received */
NCS_PRI_VAR u8 m_ubRTEReceived;
#endif

/* Information concerning the page buffer used if the TD are not aligned on flash page size */
NCS_PRI_VAR tPageBuffer m_stPageBuffer;

#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
/* Data structure for decrypted data */
NCS_PRI_VAR tCryptoData m_stCryptoData;
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/

#if(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)
tMultipleBuffReprogInfo m_stMultipleBuffers;
tEventInfo m_stEventInfo;
#endif

/* Local buffer */
NCS_PRI_VAR u8 m_aubUdsData[8];

#if(PROG_SEG_LIST_CKS == STD_ON)
tSegmentListType m_stSegList;
#endif

#if (PROG_SLEEP_MANAGEMENT_TYPE == PROG_SLEEP_MANAGEMENT_TIMEOUT)
/* Timer managing the go to sleep function */
NCS_PRI_VAR u32 m_ulSleepTimeout;
#endif

#if (PROG_SECURITY_ENABLE == STD_ON)
#if (PROG_NORESET_SECURITYLEVEL==STD_ON)
#define PROG_REPROG_FLAG_START_SEC_VAR_NO_INIT_8
#include <MemMap.h>
/* Current security level stored in the No-init exchange RAM area */
NCS_PRI_VAR u8 m_ubProgSecurityLevel;
#define PROG_REPROG_FLAG_STOP_SEC_VAR_NO_INIT_8
#include <MemMap.h>
#else
/* Current security level */
NCS_PRI_VAR u8 m_ubProgSecurityLevel;
#endif /*(PROG_NORESET_SECURITYLEVEL==STD_ON)*/
#endif /*(PROG_SECURITY_ENABLE == STD_ON)*/

#if (PROG_NETWORK_MANAGEMENT_ENABLE == STD_ON)
/* Current network status */
NCS_PRI_VAR u16 m_uwNetworkStatus;
#endif

#if (PROG_UPDATE_PSI_ENABLE == STD_ON)
NCS_PRI_VAR u8 m_aubPSIValue[PROG_PSI_SIZE];
#endif

#if PROG_PEC_ENABLE == STD_ON
tProgPECError m_uwPEC;
#endif

#if PROG_TRANSFER_DATA_ENABLE == STD_ON
#if ((PROG_CRC_CALCULATION != PROG_NO_CRC) || (PROG_SIGNATURE_CALCULATION == STD_ON) || (PROG_HASH_CALCULATION == STD_ON))
NCS_PRI_VAR tDataBufferType m_aubCrcData[PROG_CRC_CALC_SIZE];
#endif
#endif


#if (PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON)
/* Counter for number of sector to erased before sending NRC78 */
NCS_PRI_VAR u8 m_ubNbSectEraseCnt;
#endif /* PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON */

#if (PROG_REQUEST_SEED_DELAY_TIMER_ENABLED == STD_ON)
#define PROG_REPROG_FLAG_START_SEC_VAR_NO_INIT_8
#include <MemMap.h>
NCS_PRI_VAR u32 m_ulRsDelayTimer;
#define PROG_REPROG_FLAG_STOP_SEC_VAR_NO_INIT_8
#include <MemMap.h>
#endif/*(PROG_REQUEST_SEED_DELAY_TIMER_ENABLED == STD_ON)*/


#if (PROG_IMPL_VARIANT == PROG_IMPL_31)
#if (PROG_REPROG_TYPE == PROG_STANDARD_REPROG)
NCS_PRI_VAR u8 m_aubExpectedCrc[PROG_CRC_BYTE_LENGTH];
#elif (PROG_REPROG_TYPE == PROG_AUTHENTICATED_REPROG)
NCS_PRI_VAR u8 m_aubMessageDigest[PROG_DIGEST_LENGTH];
NCS_PRI_VAR u8 m_aubBlockHeader[PROG_IMPL31_HEADER_SIZE];
NCS_PRI_VAR u8 m_aubBlockHeaderSignature[PROG_IMPL31_HEADER_SIGNATURE_SIZE];
NCS_PRI_VAR u8 m_aubBlockHeaderSigningInfo[PROG_IMPL31_SIGNING_INFO_SIZE];
NCS_PRI_VAR u8 m_ubBlockHeaderCheckFailed;
#endif
#elif ((PROG_IMPL_VARIANT == PROG_IMPL_60) && (PROG_HASH_CALCULATION == STD_ON))
NCS_PRI_VAR u8 m_aubMessageDigest[PROG_DIGEST_LENGTH];
#endif

#if ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_60))
NCS_PRI_VAR tWfSuccess m_stWfSuccess;
#endif /*(PROG_WRITE_FINGERPRINT_ENABLE == STD_ON)*/
#if (PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)
NCS_PRI_VAR u32 m_ulProgrammingStatus;
#endif

#if (((PROG_CRC_COMPUTE_COMPARE_ENABLE == STD_ON) || (PROG_SEG_LIST_CKS == STD_ON)) && (PROG_CHECK_MEMORY_ENABLE == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_10) && (PROG_IMPL_VARIANT != PROG_IMPL_90) && (PROG_IMPL_VARIANT != PROG_IMPL_11)&& (PROG_IMPL_VARIANT != PROG_IMPL_91))
#if (PROG_CRC_CALCULATION == PROG_TD_CRC32)
u32 m_ulExpectedCks;
#elif (PROG_CRC_CALCULATION == PROG_TD_CRC16)
u16 m_uwExpectedCks;
#endif
#endif

#if (PROG_VERIFICATION_ON_THE_FLY == STD_ON) || (PROG_SIGNATURE_CALCULATION == STD_ON)
#if (PROG_CRY_PRESENT == STD_ON)
Csm_AsymPublicKeyType m_stProgAsymPublicKey;
#endif
#endif

#if (PROG_DECRYPTION_ENABLE == STD_ON)
NCS_PRI_VAR u8 m_ubEncryptionMethod;
#endif

#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
#if (PROG_BOOT_PROT_PARTITIONS == STD_ON)
NCS_PRI_VAR u8 m_aubModuleCCID[PROG_MODULE_INFO_CCID_SIZE];
/* Flag indicating the state of the partition compatibility */
u8 ubPartitionCompatibilityState;
#endif
#endif

u8 m_ubWaitCryptoBeforeTdEnd;
u8 m_ubDecompNotWritten = PROG_FALSE;

/*===============================================================================*/

/*-------------------------------------------------------------------------------*/
/* - Private Macros                                                              */
#define PROG_NORMAL_COMMUNICATION_MESSAGES 0x01

/*-------------------------------------------------------------------------------*/
/* - Private Function Prototypes                                                */


#if (PROG_NETWORK_MANAGEMENT_ENABLE == STD_ON)
/** \brief Called periodically to check network status **/
INLINE void PROG_NetworkStatusManage(void);
#endif
#if PROG_REQUEST_DOWNLOAD_ENABLE == STD_ON
/** \brief Perform data extract for RequestDownload request
 **
 ** This function is called to extract all data containing in
 ** RequestDownload request and set them in data structure
 **
 ** \param[in] pubUdsData Request data
 ** \param[in] ulDataLength Request data length
 ** \param[in] pstRDParam Pointer to RequestDownload structure
 ** \param[out] eUdsStatus Contain UDS error code in case of NOK status
 **
 ** \return Result of treatment
 ** \retval PROG_E_OK  Extraction succeed
 ** \retval PROG_E_NOT_OK  Extraction failed
 **
 **/
NCS_PRI_FCT tProgStatus PROG_ExtractRDParameter(const u8 * pubUdsData,
         PduLengthType ulDataLength, tRDParam* pstRDParam, tUdsStatus* eUdsStatus);
/** \brief Check DFI parameter from RequestDownload request
 **
 ** \param[in] ubDFIvalue DFI value from the request
 **
 ** \return Result of treatment
 ** \retval PROG_E_OK  Check succeed
 ** \retval PROG_E_NOT_OK  Check failed
 **
 **/
NCS_PRI_FCT tProgStatus PROG_CheckDFI(u8 ubDFIvalue);
#endif
#if PROG_ERASE_MEMORY_ENABLE == STD_ON
/** \brief Perform data extract for EraseMemory request
 **
 ** This function is called to extract all data containing in
 ** RequestDownload request and set them in data structure
 **
 ** \param[in] pubUdsData Request data
 ** \param[in] pstSegment Current segment information
 ** \param[out] eUdsStatus Contains UDS error code in case of NOK status
 ** \param[out] pubBlockId Contains Block Index
 **
 ** \return Result of treatment
 ** \retval PROG_E_OK  Extraction succeed
 ** \retval PROG_E_NOT_OK  Extraction failed
 **
 **/
NCS_PRI_FCT tProgStatus PROG_ExtractEraseParameters(const u8 * pubUdsData,
        tSegmentType * pstSegment, tUdsStatus * eUdsStatus, u8 * pubBlockId);
/** \brief Check the erase status of the current operation
 **
 ** \param[out] eProgStatus contains the memory job status
 **
 **
 **/
NCS_PRI_FCT void PROG_EraseStatusCheck(tProgStatus eProgStatus);
#endif
#if PROG_TRANSFER_DATA_ENABLE == STD_ON
/** \brief Check the write status of the current operation
 **
 ** \param[in] eProgStatus contains the memory job status
 **
 **/
NCS_PRI_FCT void PROG_WriteStatusCheck(tProgStatus eProgStatus);

/** \brief Update write info parameters  **/
NCS_PRI_FCT void PROG_WriteStatusCheck_SubFunction(void);



#endif /* PROG_TRANSFER_DATA_ENABLE == STD_ON */
#if (PROG_SLEEP_MANAGEMENT_TYPE == PROG_SLEEP_MANAGEMENT_TIMEOUT)
/** \brief Periodic function managing the sleep timeout **/
INLINE void PROG_ReadyToSleepManage(void);
#endif
#if ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_60))
/** \brief Periodic function managing the sleep timeout **/
NCS_PRI_FCT void PROG_UpdateWfSuccessFlag(tProgBoolean ubValue);
#endif /*PROG_WRITE_FINGERPRINT_ENABLE == STD_ON*/

#if (PROG_TUNABLE_PARAMETERS == PROG_TUNABLE_PARAMETERS_ACTIVATED)
/** \brief Copy the configure const parameter into the RAM tunable variable **/
NCS_PRI_FCT void PROG_ParametersInit(void);
#endif /* (PROG_TUNABLE_PARAMETERS == PROG_TUNABLE_PARAMETERS_ACTIVATED) */

#if ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_60) && (PROG_APPLI_CHECK_ALGO_EB == STD_ON))
/** \brief write fingerPrint in Memory **/
NCS_PRI_FCT tProgStatus PROG_CustomWriteFingerprint(u8 * pubRamBuffer);
/** \brief Get writing fingerprint status **/
NCS_PRI_FCT tProgStatus PROG_CustomGetWriteFingerprintStatus(void);
#endif

#if ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_AUTHENTICATED_REPROG))
/** \brief Check the block header custom data (TargetName, RollbackId, CompatibilityId and Uuid)
 **
 ** \param[in]  pubHeaderAddress Block Header address
 ** \param[out] eProgStatus contains the memory job status
 **
 **/
NCS_PRI_FCT tProgStatus PROG_CheckBlockHeaderCustomData(u8 * pubHeaderAddress);

/** \brief Get the Block Header and extract the HeaderSize, FileSize, the SigningInfos and the HeaderSignature
 **
 ** \param[out]  pulHeaderSize Block Header Size pointer
 ** \param[out]  pulFileSize FileSize pointer
 ** \param[out]  paubSigningInfos SigningInfo pointer
 ** \param[out]  paubHeaderSignature HeaderSignature pointer
 **
 **/
NCS_PRI_FCT void PROG_ExtractDataFromBlockHeader(u32* pulHeaderSize, u32* pulFileSize, u8* paubSigningInfos, u8* paubHeaderSignature);

/** \brief Extract and Check the HeaderSize, the SigningInfos and the HeaderSignature **/
NCS_PRI_FCT void PROG_StartBlockHeaderCheck(void);
#endif /*((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_AUTHENTICATED_REPROG))*/

#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
NCS_PRI_FCT void PROG_CheckCalibrationPartitions(void);
#endif

#if (PROG_IMPL_VARIANT == PROG_IMPL_40)
/** \brief Called to extract Block ID from erase request
 **
 ** \param[in] pubUdsData Request data
 ** \param[out] pubBlockId index of the matching segment in configuration
 **
 ** \return Result of check
 ** \retval PROG_E_OK Block ID from erase request extracted.
 ** \retval PROG_E_NOT_OK Erase request incorrect.
 **
 **/
NCS_PRI_FCT tProgStatus PROG_Erase_ExtractBlockID(const u8 * pubUdsData, u8 * pubBlockId);
#endif
/*                                                                               */
/*===============================================================================*/

/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */

/*--------------------------------{PROG_Init}------------------------------------*/
void PROG_Init(void)
{
    ICOV(1742);DBG_PROG_INIT_ENTRY();

#if (((PROG_IMPL_VARIANT == PROG_IMPL_20) || (PROG_IMPL_VARIANT == PROG_IMPL_60) || (PROG_IMPL_VARIANT == PROG_IMPL_10) || (PROG_IMPL_VARIANT == PROG_IMPL_90) || (PROG_IMPL_VARIANT == PROG_IMPL_40))&& (PROG_RESPOND_TO_PROG_SESSION == STD_ON))
    m_ubSendResponsetoOpenProgramming = PROG_FALSE;
#endif

#if (PROG_RESET_CAUSE_ENABLE == STD_ON)
    m_ubSendResponseafterReset = PROG_FALSE;
#endif

    m_stDiagMessageInfo.pubData = NULL_PTR;
    m_stDiagMessageInfo.ulLength = 0U;
    m_stDiagMessageInfo.ubDiagStatus = UDS_ACK;

    m_ubWaitCryptoBeforeTdEnd = PROG_FALSE;

#if(PROG_CSM_DECRYPTION_ENABLE == STD_ON)
    m_stCryptoData.ubOperationInProgress = PROG_NO_OPERATION_IN_PROGRESS;
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/

#if (((PROG_IMPL_VARIANT == PROG_IMPL_40) || (PROG_IMPL_VARIANT == PROG_IMPL_50) || (PROG_IMPL_VARIANT == PROG_IMPL_60)) && (PROG_CHECK_MEMORY_ENABLE == STD_ON))
    m_stFirstCheckMemoryAnswerInfo.ulLength = 0U;
    m_stFirstCheckMemoryAnswerInfo.ubDiagStatus = UDS_ACK;
    m_stFirstCheckMemoryAnswerInfo.aubData[0U] = 0x31U;
    m_stFirstCheckMemoryAnswerInfo.aubData[1U] = 0x01U;
    m_stFirstCheckMemoryAnswerInfo.aubData[2U] = 0x02U;
    m_stFirstCheckMemoryAnswerInfo.aubData[3U] = 0x02U;
    m_ubCheckMemoryFinishState = FALSE;
    m_ubSameRequest = TRUE;
#elif (((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_STANDARD_REPROG)) && (PROG_CHECK_MEMORY_ENABLE == STD_ON))
    m_ubCheckMemoryFinishState = FALSE;
    m_ubSameRequest = TRUE;
#endif

    m_stReprogInfo.ubRDReceived = FALSE;

    m_ubTDReceive = PROG_FALSE;
#if ((PROG_SEG_LIST_CKS == STD_ON) && (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID))
    /* !!! Value of initialisation of this variable shall not be changed !!! */
    /* It is used when Erase State is not executed and RD is called immediately after states: */
    /* - WRITE_FINGERPRINT */
    /* - COMPARE_KEY */
    /* It allows that PROG_Entry_RD to launch PROG_VerifySignatureStart and PROG_ComputeHashStart */
    /* Collateral effect is that block index PROG_LOGICAL_BLOCK_VALUE_INIT cannot be configured */
    /* under Tresos because it becomes reserved */
    m_stDataProgVerification.ubLogicalBlockId = PROG_LOGICAL_BLOCK_VALUE_INIT;
#endif

    m_ubProgFirstCall = TRUE;
    m_ubSimulateProgSessionWithResponse = FALSE;

#if PROG_PEC_ENABLE == STD_ON
    m_uwPEC = PROG_PEC_NO_ERROR;
    m_stBootStatus.ubSignatureBypass = 0U;
    m_stBootStatus.ubBootIntegrity = 0U;
#endif

#if (PROG_TUNABLE_PARAMETERS == PROG_TUNABLE_PARAMETERS_ACTIVATED)
    PROG_ParametersInit();
#endif
    PROG_MemInit();

#if ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_60))
    m_stWfSuccess.ubAppFingerprintWriten = PROG_FALSE;
    m_stWfSuccess.ubCalFingerprintWriten = PROG_FALSE;
    m_stWfSuccess.ubBluFingerprintWriten = PROG_FALSE;
#endif /*PROG_WRITE_FINGERPRINT_ENABLE == STD_ON*/

#if (PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)
    /*Initialize the Programming status to no fault*/
    m_ulProgrammingStatus = 0xFFFFFFFFU;
#endif

#if (PROG_SECURITY_ENABLE == STD_ON)
#if (PROG_NORESET_SECURITYLEVEL==STD_OFF)
    m_ubProgSecurityLevel = PROG_SEC_LEVEL_LOCK;
#endif
#endif

#if (PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON)
    m_ubNbSectEraseCnt = 0U;
#endif /* PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON */

#if (PROG_SIGNATURE_CALCULATION == STD_ON)
#if (PROG_CRY_PRESENT == STD_ON)
    PROG_GetPublicKey(&m_stProgAsymPublicKey);
#endif
#endif

#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
    /* Init variables of profile 20 only */
    PROG_Init_Impl20();
    /* Normal Communication is enabled(no reception of CommunicationControl request) */
    m_ubNormComEnabled = 0x01;
    /* Information if ECU is locked(no reception of SecurityAccess request) */
    m_ubIsLocked = 0x01;
#endif

#if ((PROG_IMPL_VARIANT == PROG_IMPL_10) || (PROG_IMPL_VARIANT == PROG_IMPL_11))
    PROG_Init_Impl10();
#endif

#if (PROG_IMPL_VARIANT == PROG_IMPL_80)
    PROG_Init_Impl80();
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_80) */

#if ((PROG_IMPL_VARIANT == PROG_IMPL_90) || (PROG_IMPL_VARIANT == PROG_IMPL_91))
    PROG_Init_Impl90();
#endif

#if(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)
    m_stEventInfo.Event = PROG_NO_EVENT;
    m_ubPendingNRC78 = FALSE;
    m_ubPendingSendNRC78 = FALSE;
#endif

#if (PROG_PARTIAL_VERIFY_CRC == STD_ON)
    m_ubActivePartialVerifyCrc = FALSE;
#endif

#if(PROG_CRC_CALCULATION == PROG_TD_CRC32)
    m_ubCrcStart = PROG_FALSE;
#endif

#if (PROG_CVN_CHECK == STD_ON)
    m_eCvnCheckInProgress = PROG_FALSE;
#endif /* PROG_CVN_CHECK == STD_ON */

#if ((PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON) || (PROG_DECOMP_FLASH_ROUTINES == STD_ON))
    PROG_DrvDown_SetFlashRoutinesPresence(PROG_FALSE);
#endif /* PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON */
#if PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON
    PROG_DrvDown_SetFlashRoutinesCorruption(PROG_FALSE);
#endif /* PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON */

#if ((PROG_CSM_MAC_USED == STD_ON) || (PROG_CSM_HASH_USED == STD_ON))
    PROG_SecurityInit();
#endif

#if (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON)
    PROG_DowngradeProtection_ResetPFTStatus_Impl40();
#endif /* (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON) */
    PROG_HsmInit (&PROG_HsmScPROG);
    DBG_PROG_INIT_EXIT();
}
/*------------------------------{end PROG_Init}----------------------------------*/

#if (PROG_TUNABLE_PARAMETERS == PROG_TUNABLE_PARAMETERS_ACTIVATED)
/*--------------------------{PROG_ParametersInit}--------------------------------*/
NCS_PRI_FCT void PROG_ParametersInit(void)
{
    u8 ubIdx;
    /* initialize the tunable DTC configurable tab */
    ICOV(1743);for (ubIdx = 0U; (ubIdx < PROG_SEGMENT_NB)?BCOV(1744):!BCOV(1745); ubIdx++)
    {
        stConfigSegment[ubIdx].ubMemoryIdx = stConstConfigSegment[ubIdx].ubMemoryIdx;
        stConfigSegment[ubIdx].eSegAccessType = stConstConfigSegment[ubIdx].eSegAccessType;
        stConfigSegment[ubIdx].ulStartAddress = stConstConfigSegment[ubIdx].ulStartAddress;
        stConfigSegment[ubIdx].ulEndAddress = stConstConfigSegment[ubIdx].ulEndAddress;
        stConfigSegment[ubIdx].ulEraseStartAddress = stConstConfigSegment[ubIdx].ulEraseStartAddress;
        stConfigSegment[ubIdx].ulEraseEndAddress = stConstConfigSegment[ubIdx].ulEraseEndAddress;
    }
}
/*-------------------------{end PROG_ParametersInit}-----------------------------*/
#endif

/*------------------------------{PROG_TpTxConf}----------------------------------*/
void PROG_TpTxConf(tTpMsgIdx uMsgIdx, u8 ebStatus)
{
    ICOV(1746);DBG_PROG_TPTXCONF_ENTRY(uMsgIdx,ebStatus );
    if ((ebStatus == TP_MSG_STATUS_OK)?BCOV(1747):!BCOV(1748))
    {
        /* Post Event in state machine */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF);
#if(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)
    m_ubPendingNRC78 = FALSE;
#endif
#if(PROG_SA_AUTHENTICATION_METHOD == PROG_SA_AUTHENTICATION_0001 )
        if((SA_SEND_SA1RES_AWAIT_TXCONF == SA_AM0001_GetState())?BCOV(1749):!BCOV(1750))
        {
            /*Msg sent successfully, so start to Await SA2 request*/
            SA_AM0001_SetStatus(SA_E_OK);
        }
#endif
    }
    else
    {
#if(PROG_SA_AUTHENTICATION_METHOD == PROG_SA_AUTHENTICATION_0001 )
        if((SA_SEND_SA1RES_AWAIT_TXCONF == SA_AM0001_GetState())?BCOV(1751):!BCOV(1752))
        {
            /* Error during Tx, msg was not sent successfully*/
            SA_AM0001_SetStatus(SA_E_NOT_OK);
        }
#endif
    }
#if ((PROG_SIGNFIN_SENDFRP == STD_ON) || (PROG_HASHFIN_SENDFRP == STD_ON))
    PROG_TxConfNotification();
#endif
    OSC_PARAM_UNUSED(uMsgIdx);
    DBG_PROG_TPTXCONF_EXIT();
}
/*----------------------------{end PROG_TpTxConf}--------------------------------*/


/*------------------------------{PROG_TpRxInd}-----------------------------------*/
void PROG_TpRxInd(tTpMsgIdx uMsgIdx, u8 ebStatus)
{
    ICOV(1753);DBG_PROG_TPRXIND_ENTRY(uMsgIdx,ebStatus );
    OSC_PARAM_UNUSED(uMsgIdx);

    OSC_PARAM_UNUSED(ebStatus);

#if (PROG_SLEEP_MANAGEMENT_TYPE == PROG_SLEEP_MANAGEMENT_TIMEOUT)
    PROG_SetSleepTimeout(PROG_SLEEP_TIMEOUT);
#endif
    DBG_PROG_TPRXIND_EXIT();
}
/*-----------------------------{end PROG_TpRxInd}--------------------------------*/


/*------------------------------{PROG_TpStartOfReceptionInd}-----------------------------------*/
void PROG_TpStartOfReceptionInd(u8 ubStatus)
{
    ICOV(1754);DBG_PROG_TPSTARTOFRECEPTIONIND_ENTRY(ubStatus);
    OSC_PARAM_UNUSED(ubStatus);

#if (PROG_SLEEP_MANAGEMENT_TYPE == PROG_SLEEP_MANAGEMENT_TIMEOUT)
    if((ubStatus == TP_MSG_STATUS_OK)?BCOV(1755):!BCOV(1756))
    {
        PROG_SetSleepTimeout(0U);
    }
    else
    {
        PROG_SetSleepTimeout(PROG_SLEEP_TIMEOUT);
    }
#endif
    DBG_PROG_TPSTARTOFRECEPTIONIND_EXIT();
}
/*-----------------------------{end PROG_TpStartOfReceptionInd}--------------------------------*/


/*----------------------------{PROG_GenericRequest}------------------------------*/
tUdsStatus PROG_GenericRequest(PduLengthType *pulLen, u8 *aubUdsData,
        u8 EventToPost)
{
    tUdsStatus eUdsStatus;
#if(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)
    u8 ubProcessEvent = PROG_TRUE;
#endif

    ICOV(1757);if (((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))?BCOV(1758):!BCOV(1759))
    {
#if(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)
        /* no processing of new request shall be done if a multiple buffer processing is in progress */

        /* Check pending operation */
        if ((m_stMultipleBuffers.eBufferProcessing == TRUE)?BCOV(1760):!BCOV(1761))
        {
            /* Store event information */
            m_stEventInfo.Data = aubUdsData;
            m_stEventInfo.Length = *pulLen;
            m_stEventInfo.Event = EventToPost;
            ubProcessEvent = PROG_FALSE;
            /*Send immediately NRC78 response*/

            m_ubPendingSendNRC78 = TRUE;
        }
        else
        {
            /* Nothing to do */
        }

        if (( ubProcessEvent == PROG_TRUE)?BCOV(1762):!BCOV(1763))
#endif
        {
            /* event can be processed */

            /* Store request information */
            m_stDiagMessageInfo.pubData = aubUdsData;
            m_stDiagMessageInfo.pubTxData = aubUdsData;
            m_stDiagMessageInfo.ulLength = *pulLen;

            /* Initialize request status */
#if (PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)
        /* for RTE we shall check the status of the previous, so status shall not be reset */
        if ((PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE != EventToPost)?BCOV(1764):!BCOV(1765))
#endif
        {
            m_stDiagMessageInfo.ubDiagStatus = UDS_ACK;
        }
#if (PROG_SECURE_BOOT_CHECKSUM_COMPUTATION == STD_ON)
            /* Block request using crypto if Boot Authentication is in progress */
            if (((PROG_TRUE == PROG_SecurityPendingOperation()) &&
                ((PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED == EventToPost)
                ||  (PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD == EventToPost)))?BCOV(1766):!BCOV(1767))
            {
                PROG_SecurityStorePendingEvent(EventToPost);
            }
            else
#endif
            {
                /* Post Event in state machine */
                PROG_HsmEmit(&PROG_HsmScPROG, EventToPost);
            }
        }
        /* Pending status is returned as action will be performed asynchronously */
        eUdsStatus = UDS_NRC_78;
    }
    else
    {
        eUdsStatus = UDS_ERR_COHE;
    }
    /* Return status to lower layer */
    return (eUdsStatus);
}
/*-------------------------{end PROG_GenericRequest}-----------------------------*/

#if (PROG_SA_SEED_ENABLE == STD_ON)
/*-----------------------------{PROG_RequestSeed}--------------------------------*/
tUdsStatus PROG_RequestSeed(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1768);DBG_PROG_REQUESTSEED_ENTRY(pulLen,aubUdsData );

    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED);

#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
#if (PROG_SOURCE_ADDRESS_CHECK_ENABLE == STD_ON)
    /* save the tester address to be able to perform tester filtering */
    BlPduR_SaveTesterAddress();
#endif
#endif

    DBG_PROG_REQUESTSEED_EXIT(eStatus);
    return (eStatus);
}
/*---------------------------{end PROG_RequestSeed}------------------------------*/
#endif /*(PROG_SA_SEED_ENABLE == STD_ON) */

#if (PROG_SA_KEY_ENABLE == STD_ON)
/*-------------------------------{PROG_SendKey}----------------------------------*/
tUdsStatus PROG_SendKey(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1769);DBG_PROG_SENDKEY_ENTRY(pulLen,aubUdsData );

    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY);

    DBG_PROG_SENDKEY_EXIT(eStatus);
    return (eStatus);
}
/*-----------------------------{end PROG_SendKey}--------------------------------*/
#endif /* (PROG_SA_KEY_ENABLE == STD_ON) */

#if PROG_REQUEST_DOWNLOAD_ENABLE == STD_ON
/*---------------------------{PROG_RequestDownload}------------------------------*/
tUdsStatus PROG_RequestDownload(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1770);DBG_PROG_REQUESTDOWNLOAD_ENTRY(pulLen,aubUdsData );

    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD);

    DBG_PROG_REQUESTDOWNLOAD_EXIT(eStatus );
    return (eStatus);
}
/*-------------------------{end PROG_RequestDownload}----------------------------*/
#endif /* PROG_REQUEST_DOWNLOAD_ENABLE == STD_ON */

#if PROG_TRANSFER_DATA_ENABLE == STD_ON
/*-----------------------------{PROG_TransferData}-------------------------------*/
tUdsStatus PROG_TransferData(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    u8 ubMinTDSize = PROG_TD_MIN_SIZE;

    ICOV(1771);if (((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))?BCOV(1772):!BCOV(1773))
    {
        if((m_stReprogInfo.ubRDReceived == TRUE)?BCOV(1774):!BCOV(1775))
        {
            /* Increase minimum size for TD in RD context */
            ubMinTDSize = PROG_TD_MIN_SIZE_RD;
        }

        /* Check min length */
        if ((*pulLen >= ubMinTDSize)?BCOV(1776):!BCOV(1777))
        {
#if(PROG_MULTIPLE_BUFFERS_ENABLE == STD_OFF)
            DBG_PROG_TRANSFERDATA_ENTRY(pulLen,aubUdsData );
            m_ubTDReceive = PROG_TRUE;
            eStatus = PROG_GenericRequest(pulLen, aubUdsData,
                    PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD);
#else
            u8 ubIsLastBuffer;
            PduLengthType ulLentemp;

            DBG_PROG_TRANSFERDATA_ENTRY(pulLen,aubUdsData );

            m_ubTDReceive = PROG_TRUE;
            ulLentemp = *pulLen;
            /* There is no failure on previous TD writing */
            if((UDS_ACK == m_stDiagMessageInfo.ubDiagStatus)?BCOV(1778):!BCOV(1779))
            {
                m_stMultipleBuffers.ulBufferedSizeOfData += (u32)((u32)*pulLen - 2U);
                /* Lock the receive buffer */
                BlPduR_LockBuffer(&ubIsLastBuffer);

                if((PROG_TRUE == ubIsLastBuffer)?BCOV(1780):!BCOV(1781))
                {
                    /* No more Rx Buffers available, response will be sent after unlocking a Rx buffer */
                    m_stMultipleBuffers.eResponsePending = PROG_TRUE;
                    eStatus = UDS_NRC_78;

                    /* Store pointer to the last buffer*/
                    m_pubLastBufTxData = aubUdsData;
                }
                else
                {
                    /* Send positive response */
                    eStatus = UDS_ACK;
                    *pulLen = PROG_TD_RESPONSE_SIZE;
                }

                if((PROG_TRUE == m_stMultipleBuffers.eBufferProcessing)?BCOV(1782):!BCOV(1783))
                {
                    /*a buffer processing is already in progress. This new buffer will be manage after*/
                }
                else
                {
                    m_stMultipleBuffers.eBufferProcessing  = PROG_TRUE;
                    m_stDiagMessageInfo.pubData = aubUdsData;
                    m_stDiagMessageInfo.ulLength = ulLentemp;
                    PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD);
                }
            }
            /* case where a previous TD writing has failed */
            else
            {
                /* Send negative response */
                eStatus = m_stDiagMessageInfo.ubDiagStatus ;
                m_stDiagMessageInfo.ubDiagStatus = UDS_ACK;
            }
#endif
        } /* if (m_stDiagMessageInfo.ulLenght >= 2 or 3) */
        else
        {
#if (PROG_IMPL_VARIANT == PROG_IMPL_40)
          /*Store NRC_31 as error value*/
          m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_31;
          eStatus = m_stDiagMessageInfo.ubDiagStatus ;
#else
            /*Store NRC_13 as error value*/
            m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_13;
            eStatus = m_stDiagMessageInfo.ubDiagStatus ;
#endif
        }
    }
    else
    {
        eStatus = UDS_ERR_COHE;
    }

    DBG_PROG_TRANSFERDATA_EXIT(eStatus);
    return (eStatus);
}
/*---------------------------{end PROG_TransferData}-----------------------------*/
#endif /* PROG_TRANSFER_DATA_ENABLE == STD_ON */

#if PROG_REQUEST_TRANSFER_EXIT_ENABLE == STD_ON
/*-------------------------{PROG_RequestTransferExit}----------------------------*/
tUdsStatus PROG_RequestTransferExit(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1784);DBG_PROG_REQUESTTRANSFEREXIT_ENTRY(pulLen,aubUdsData );

    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE);

    DBG_PROG_REQUESTTRANSFEREXIT_EXIT(eStatus);
    return (eStatus);
}
/*-----------------------{end PROG_RequestTransferExit}--------------------------*/
#endif /* PROG_REQUEST_TRANSFER_EXIT_ENABLE == STD_ON */

#if (PROG_ERASE_MEMORY_REQUEST_ENABLE == STD_ON)
/*-----------------------------{PROG_EraseMemory}--------------------------------*/
tUdsStatus PROG_EraseMemory(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1785);DBG_PROG_ERASEMEMORY_ENTRY(pulLen,aubUdsData );
#if (PROG_ERASE_MEMORY_ENABLE == STD_ON)
    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE);
#else
    if (((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))?BCOV(1786):!BCOV(1787))
    {
        /* Positive response with StatusRoutine NOK */
        eStatus = UDS_ACK;
        *pulLen = 5U;
        /* Positive response for Routine type 1 with StatusRoutine NOK */
        aubUdsData[4] = (u8)(PROG_ROUTINE_FINISHED_NOK | PROG_ROUTINE_TYPE_1);
    }
    else
    {
        eStatus = UDS_ERR_COHE;
    }
#endif /* ((PROG_ERASE_MEMORY_ENABLE == STD_ON) */

    DBG_PROG_ERASEMEMORY_EXIT(eStatus);
    return (eStatus);
}
/*---------------------------{end PROG_EraseMemory}------------------------------*/
#endif /* (PROG_ERASE_MEMORY_REQUEST_ENABLE) */


#if PROG_WRITE_FINGERPRINT_ENABLE == STD_ON
/*------------------------------{PROG_WriteFingerprint}----------------------------------*/
tUdsStatus PROG_WriteFingerprint(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1788);DBG_PROG_WRITEFINGERPRINT_ENTRY(pulLen,aubUdsData );
    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP);
    DBG_PROG_WRITEFINGERPRINT_EXIT(eStatus );
    return (eStatus);
}
/*----------------------------{end PROG_WriteFingerprint}--------------------------------*/
#endif /* PROG_WRITE_FINGERPRINT_ENABLE == STD_ON */

#if (PROG_PRECOND_CHECK_ENABLE == STD_ON)
/*------------------------------{PROG_ReqCheckProgPreCondition}--------------------------*/
tUdsStatus PROG_ReqCheckProgPreCondition(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1789);DBG_PROG_REQCHECKPROGPRECONDITION_ENTRY(pulLen,aubUdsData );
    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK);
    DBG_PROG_REQCHECKPROGPRECONDITION_EXIT(eStatus);
    return (eStatus);
}
/*----------------------------{end PROG_ReqCheckProgPreCondition}------------------------*/
#endif /* (PROG_PRECOND_CHECK_ENABLE == STD_ON) */

/*---------------------------{PROG_CheckProgrammingPreCondition}--------------------------*/
tProgStatus PROG_CheckProgrammingPreCondition(void)
{
    tProgStatus eProgStatus = PROG_E_NOT_OK;
#if (PROG_PRECOND_CHECK_ENABLE == STD_ON)
    tUdsStatus  eUdsStatus;
#endif /* (PROG_PRECOND_CHECK_ENABLE == STD_ON) */

    ICOV(1790);DBG_PROG_CHECKPROGRAMMINGPRECONDITION_ENTRY( );
#if (PROG_PRECOND_CHECK_ENABLE == STD_ON)
    /*Check programming pre-conditions*/
#if (PROG_IMPL_VARIANT == PROG_IMPL_31)
    PROG_CustCheckProgPrecondList(&m_stDiagMessageInfo.pubTxData[4U],&m_stDiagMessageInfo.pubTxData[5U]);
    m_stDiagMessageInfo.ulLength = PROG_CHK_PROG_PRECOND_SIZE + (PduLengthType)(m_stDiagMessageInfo.pubTxData[4U]);
    /* Send response */
    eUdsStatus = UDS_ACK;
    UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, eUdsStatus);
#elif (PROG_IMPL_VARIANT == PROG_IMPL_50)
    /* Set Routine Info to "Routine successfully completed" */
    m_stDiagMessageInfo.pubTxData[4U] = 0x00U;

    /* Collect PreCondition List Information which will be sent in the Response  */
    PROG_CustCheckProgPrecondList(&m_stDiagMessageInfo.pubTxData[5U],&m_stDiagMessageInfo.pubTxData[6U]);

    /* Compute the length of the Response */
    m_stDiagMessageInfo.ulLength = PROG_CHK_PROG_PRECOND_SIZE + (PduLengthType)(m_stDiagMessageInfo.pubTxData[5U]);
    /* Send response */
    eUdsStatus = UDS_ACK;
    UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, eUdsStatus);
#else

        eProgStatus = PROG_CustCheckProgPrecond(&eUdsStatus);
        if((PROG_E_NOT_OK == eProgStatus)?BCOV(1791):!BCOV(1792))
        {
            /* Send NEGATIVE RESPONSE*/
            m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_22;
            m_stDiagMessageInfo.ulLength = PROG_CHK_PROG_PRECOND_SIZE;
#if ((PROG_IMPL_VARIANT == PROG_IMPL_60) || (PROG_IMPL_VARIANT == PROG_IMPL_40))
            /* Allow integration code to manage the response */
            PROG_Custom_PreCondCheckRoutine_Failed(m_stDiagMessageInfo.pubTxData,&m_stDiagMessageInfo.ulLength,&m_stDiagMessageInfo.ubDiagStatus);
#endif
            UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);
        }
        else
        {
            /* Send POSITIVE RESPONSE*/
            m_stDiagMessageInfo.ulLength = PROG_CHK_PROG_PRECOND_SIZE;
#if ((PROG_IMPL_VARIANT == PROG_IMPL_60) || (PROG_IMPL_VARIANT == PROG_IMPL_40))
            /* Allow integration code to manage the response */
            PROG_Custom_PreCondCheckRoutine_Succeed(m_stDiagMessageInfo.pubTxData,&m_stDiagMessageInfo.ulLength);
#endif
            UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, UDS_ACK);
        }

#endif /*else (PROG_IMPL_VARIANT == PROG_IMPL_31) */
#endif /* (PROG_PRECOND_CHECK_ENABLE == STD_ON) */
    DBG_PROG_CHECKPROGRAMMINGPRECONDITION_EXIT( eProgStatus);
    return eProgStatus;
}
/*--------------------------{end PROG_CheckProgrammingPreCondition}-----------------------*/

#if ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_STANDARD_REPROG))
/*----------------------------{PROG_LogicalBlockHash}-------------------------*/
tUdsStatus PROG_LogicalBlockHash(PduLengthType *pulLen, u8 *aubUdsData)
{
  tUdsStatus eStatus;
  ICOV(1793);DBG_PROG_LOGICALBLOCKHASH_ENTRY(pulLen, aubUdsData);

  eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_LB_VERIF);

  DBG_PROG_LOGICALBLOCKHASH_EXIT(eStatus);
  return eStatus;
}
/*----------------------------{end PROG_LogicalBlockHash}-------------------------*/
#endif

/*---------------------------{PROG_SetProgrammingStatus}----------------------*/
void PROG_SetProgrammingStatus(u32 ulProgrammingStatusMask, tProgBoolean ubStatus)
{
    ICOV(1794);DBG_PROG_SETPROGRAMMINGSTATUS_ENTRY(ulProgrammingStatusMask, ubStatus );
#if (PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)
    /*Update the status*/
    if ((PROG_FALSE == ubStatus)?BCOV(1795):!BCOV(1796))
    {
        NCS_RESET_BIT(m_ulProgrammingStatus,ulProgrammingStatusMask,u32);
        /*Send NRC_24 for Wrong Sequences*/
        if(( (PROG_TD_SEQUENCE              == ulProgrammingStatusMask)  || /* Data Transfer error (Wrong total length) */
            (PROG_SEQUENCE_WDBI            == ulProgrammingStatusMask)  || /* WDBI not done before erasing request */
            (PROG_SEQUENCE_ERASE           == ulProgrammingStatusMask)  || /* Wrong erasing sequence */
            (PROG_SEQUENCE_BLOCK_TRANSFFER == ulProgrammingStatusMask)  || /* Wrong BlockSequenceCounter received */
            (PROG_SEQUENCE_CHECKSUM        == ulProgrammingStatusMask))?BCOV(1797):!BCOV(1798))    /* Wrong CheckSum sequence */
        {
            UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, UDS_NRC_24);
        }
    }
    else
    {
        NCS_SET_BIT(m_ulProgrammingStatus,ulProgrammingStatusMask,u32);
    }
    /*Store the Programming status*/
    PROG_CustomWriteProgStatus(m_ulProgrammingStatus);
#else
    OSC_PARAM_UNUSED(ulProgrammingStatusMask);
    if ((PROG_FALSE == ubStatus)?BCOV(1799):!BCOV(1800))
    {
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, UDS_NRC_24);
    }
#endif /*  (PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON) */
    DBG_PROG_SETPROGRAMMINGSTATUS_EXIT();
}
/*--------------------------{end PROG_SetProgrammingStatus}-------------------*/

#if PROG_ECU_RESET_ENABLE == STD_ON
/*------------------------------{PROG_EcuReset}----------------------------------*/
tUdsStatus PROG_EcuReset(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1801);DBG_PROG_ECURESET_ENTRY(pulLen, aubUdsData);

    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER);

    DBG_PROG_ECURESET_EXIT(eStatus );
    return (eStatus);
}
/*----------------------------{end PROG_EcuReset}--------------------------------*/
#endif /* PROG_ECU_RESET_ENABLE == STD_ON */

#if ((PROG_AUTOCONTROL_ENABLE == STD_ON)\
    && (PROG_AUTO_CONTROL_REQUEST_ENABLE == STD_ON))
/*-----------------------------{PROG_AutoControl}--------------------------------*/
tUdsStatus PROG_AutoControl(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1802);DBG_PROG_AUTOCONTROL_ENTRY(pulLen, aubUdsData );

    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_AUTOCONTROL);

    DBG_PROG_AUTOCONTROL_EXIT(eStatus);
    return (eStatus);
}
/*---------------------------{end PROG_AutoControl}------------------------------*/
#endif /* ((PROG_AUTOCONTROL_ENABLE == STD_ON)\
    && (PROG_AUTO_CONTROL_REQUEST_ENABLE == STD_ON)) */

#if (PROG_ACTIVE_SBL_REQUEST_ENABLE == STD_ON)
/*------------------------------{PROG_ActiveSBL}---------------------------------*/
tUdsStatus PROG_ActiveSBL(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1803);DBG_PROG_ACTIVESBL_ENTRY(pulLen, aubUdsData );

#if (PROG_ACTIVE_SBL_ENABLE == STD_ON)
    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_ACTIVESBL);
#else /* ((PROG_ACTIVE_SBL_ENABLE == STD_ON) */
    if (((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))?BCOV(1804):!BCOV(1805))
    {
        /* Positive response */
        eStatus = UDS_ACK;
        *pulLen = 5U;
#if (PROG_IMPL_VARIANT == PROG_IMPL_11)
        /* Positive response for Routine type 1 */
        aubUdsData[4] = (u8)(PROG_ROUTINE_FINISHED_OK | PROG_ROUTINE_TYPE_1);
#endif
#if (PROG_IMPL_VARIANT == PROG_IMPL_91)
        /* Positive response for Routine type 1 */
        aubUdsData[4] = (u8)(PROG_ROUTINE_FINISHED_OK | PROG_ROUTINE_TYPE_1);
#endif
#if ((PROG_IMPL_VARIANT == PROG_IMPL_2) || (PROG_IMPL_VARIANT == PROG_IMPL_4))
        /* Positive response for Routine type 1 */
        aubUdsData[4] = (u8)(PROG_ROUTINE_SELFTERM | PROG_ROUTINE_PREDIF);
#endif /* #if ((PROG_IMPL_VARIANT == PROG_IMPL_2) || (PROG_IMPL_VARIANT == PROG_IMPL_4))*/
    }
    else
    {
        eStatus = UDS_ERR_COHE;
    }

#endif /* ((PROG_ACTIVE_SBL_ENABLE == STD_ON) */
    DBG_PROG_ACTIVESBL_EXIT(eStatus );
    return (eStatus);
}
/*----------------------------{end PROG_ActiveSBL}-------------------------------*/
#endif /* (PROG_ACTIVE_SBL_REQUEST_ENABLE == STD_ON) */
#if (PROG_CHECK_VALID_APPLICATION_ENABLE == STD_ON)
/*-----------------------------{PROG_CheckValidApplication}--------------------------------*/
tUdsStatus PROG_CheckValidApplication(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1806);DBG_PROG_CHECKVALIDAPPLICATION_ENTRY(pulLen, aubUdsData );
    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECK_VALIDAPPLICATION);
    DBG_PROG_CHECKVALIDAPPLICATION_EXIT(eStatus);
    return (eStatus);
}
/*---------------------------{end PROG_CheckValidApplication}------------------------------*/
#endif /* (PROG_VALIDATE_APPLICATION_ENABLE == STD_ON) */

#if (PROG_SUBMITSIGNATURE_ENABLE == STD_ON)
/*-----------------------------{PROG_SubmitSignature}--------------------------------*/
tUdsStatus PROG_SubmitSignature(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1807);DBG_PROG_SUBMITSIGNATURE_ENTRY(pulLen, aubUdsData );
    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_SUBMITSIGNATURE);
    DBG_PROG_SUBMITSIGNATURE_EXIT(eStatus);
    return (eStatus);
}
/*---------------------------{end PROG_SubmitSignature}------------------------------*/
#endif /* (PROG_SUBMITSIGNATURE_ENABLE == STD_ON) */

#if (PROG_VALIDATE_APPLICATION_ENABLE == STD_ON)
/*-----------------------------{PROG_ValidateApplication}--------------------------------*/
tUdsStatus PROG_ValidateApplication(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1808);DBG_PROG_VALIDATEAPPLICATION_ENTRY(pulLen, aubUdsData );
    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_VALIDATEAPPLICATION);
    DBG_PROG_VALIDATEAPPLICATION_EXIT(eStatus);
    return (eStatus);
}
/*---------------------------{end PROG_ValidateApplication}------------------------------*/
#endif /* (PROG_VALIDATE_APPLICATION_ENABLE == STD_ON) */

#if (((PROG_IMPL_VARIANT == PROG_IMPL_40) || (PROG_IMPL_VARIANT == PROG_IMPL_50) || (PROG_IMPL_VARIANT == PROG_IMPL_60)) && (PROG_CHECK_MEMORY_ENABLE == STD_ON))
/*----------------------------{PROG_AnswerSuccesiveCheckMemoryRequests}-------------------------------*/
void PROG_AnswerSuccesiveCheckMemoryRequests(void)
{
    u8 ubIdx;

    ICOV(1809);DBG_PROG_ANSWERSUCCESIVECHECKMEMORYREQUESTS_ENTRY();
#if (PROG_BLU_ACTIVE == STD_ON)
    /* Check the presence of BLUpdater pattern in the current segment/block */
    if ((PROG_FALSE == m_ubBLUPattern)?BCOV(1810):!BCOV(1811))
#endif /* (PROG_BLU_ACTIVE == STD_ON) */
    {
        /* Collect and compare the content of the received Check Memory request to the first one */
        PROG_Entry_CheckMemory();
    }

    /* The content of the received Check Memory request is the same that the content of the */
    /* first received Check Memory request */
    if ((TRUE == m_ubSameRequest)?BCOV(1812):!BCOV(1813))
    {
        /* Copy the first answer in the current physical buffer */
        for (ubIdx = 0U; (ubIdx < PROG_MAX_LENGTH_CHECKMEMORY_ANSWER)?BCOV(1814):!BCOV(1815); ubIdx++)
        {
            m_stDiagMessageInfo.pubTxData[ubIdx] = m_stFirstCheckMemoryAnswerInfo.aubData[ubIdx];
        }
        m_stDiagMessageInfo.ubDiagStatus = m_stFirstCheckMemoryAnswerInfo.ubDiagStatus;
        m_stDiagMessageInfo.ulLength     = m_stFirstCheckMemoryAnswerInfo.ulLength;
    }
    /* Two contents are different */
    else
    {
        /* Transition is rejected, NRC 24 shall be sent */
        m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_24;
    }

    /* Send the response */
    UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);


    DBG_PROG_ANSWERSUCCESIVECHECKMEMORYREQUESTS_EXIT();
}
/*----------------------------{end PROG_AnswerSuccesiveCheckMemoryRequests}-------------------------------*/
#endif

#if PROG_UPDATE_PSI_ENABLE == STD_ON
/*------------------------------{PROG_UpdatePSI}---------------------------------*/
tUdsStatus PROG_UpdatePSI(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1816);DBG_PROG_UPDATEPSI_ENTRY(pulLen, aubUdsData);

    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_UPDATEPSI);

    DBG_PROG_UPDATEPSI_EXIT(eStatus);
    return (eStatus);
}
/*----------------------------{end PROG_UpdatePSI}-------------------------------*/
#endif /* PROG_UPDATE_PSI_ENABLE == STD_ON */



#if PROG_CONTROL_DTC_SETTING_ENABLE == STD_ON
/*-------------------------{PROG_ControlDTCSetting}------------------------------*/
tUdsStatus PROG_ControlDTCSetting(PduLengthType *pulLen, u8 *aubUdsData)
{

    tUdsStatus eStatus;
    ICOV(1817);DBG_PROG_CONTROLDTCSETTING_ENTRY(pulLen, aubUdsData );
#if(PROG_IMPL_VARIANT == PROG_IMPL_40)
    if((m_stReprogInfo.ubRDReceived == TRUE)?BCOV(1818):!BCOV(1819))
    {
        eStatus = UDS_NRC_22;
    }
    else
#endif
    {
    if (((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))?BCOV(1820):!BCOV(1821))
    {
        /* Set length to 2 */
        *pulLen = 2U;
        eStatus = UDS_ACK;
    }
    else
    {
        eStatus = UDS_ERR_COHE;
        }
    }
    DBG_PROG_CONTROLDTCSETTING_EXIT(eStatus );
    return (eStatus);
}
/*-----------------------{end PROG_ControlDTCSetting}----------------------------*/
#endif /* PROG_CONTROL_DTC_SETTING_ENABLE == STD_ON */



#if PROG_COMMUNICATION_CONTROL_ENABLE == STD_ON
/*------------------------{PROG_CommunicationControl}----------------------------*/
tUdsStatus PROG_CommunicationControl(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1822);DBG_PROG_COMMUNICATIONCONTROL_ENTRY(pulLen, aubUdsData );

#if(PROG_IMPL_VARIANT == PROG_IMPL_40)
    if((m_stReprogInfo.ubRDReceived == TRUE)?BCOV(1823):!BCOV(1824))
    {
        eStatus = UDS_NRC_22;
    }
    else
#endif
    {
    if (((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))?BCOV(1825):!BCOV(1826))
    {
        /* Set length to 2 */
        *pulLen = 2U;
#if(PROG_IMPL_VARIANT == PROG_IMPL_40)
        if ((aubUdsData[2U] == PROG_NORMAL_COMMUNICATION_MESSAGES)?BCOV(1827):!BCOV(1828))
        {
            eStatus = UDS_ACK;
        }
        else
        {
            eStatus = UDS_NRC_31;
        }
#else
        eStatus = UDS_ACK;
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_40)*/
#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
        /* Normal Communication is disabled  */
        m_ubNormComEnabled = 0x00;
#endif
    }
    else
    {
        eStatus = UDS_ERR_COHE;
        }
    }
    DBG_PROG_COMMUNICATIONCONTROL_EXIT(eStatus );
    return (eStatus);
}
/*----------------------{end PROG_CommunicationControl}--------------------------*/
#endif /* PROG_COMMUNICATION_CONTROL_ENABLE == STD_ON */


#if PROG_CHECK_MEMORY_ENABLE == STD_ON
/*----------------------------{PROG_CheckMemory}---------------------------------*/
tUdsStatus PROG_CheckMemory(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1829);DBG_PROG_CHECKMEMORY_ENTRY(pulLen, aubUdsData );

#if (PROG_IMPL_VARIANT == PROG_IMPL_80)
    eStatus = PROG_ControlSelfCheckParameters_Impl80(pulLen, aubUdsData);
#elif ((PROG_VERIFICATION_METHOD == PROG_VERIFICATION_IN_DFI) && (PROG_SIGNATURE_CALCULATION == STD_ON))
    if ((((m_ubVerificationMethod == PROG_VERIFICATION_SIGNATURE_AND_CRC) && (*pulLen != (PROG_SIGNATURE_LENGTH + PROG_CRC_LENGTH + PROG_RC_ROUTINE_INFO_BASE_INDEX))) || ((m_ubVerificationMethod == PROG_VERIFICATION_SIGNATURE) && (*pulLen != (PROG_SIGNATURE_LENGTH + PROG_RC_ROUTINE_INFO_BASE_INDEX))))?BCOV(1830):!BCOV(1831))
    {
        eStatus = UDS_NRC_13;
    }
    else
    {
        eStatus = PROG_GenericRequest(pulLen, aubUdsData,
                PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY);
    }
#else
    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY);
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_80) */

    DBG_PROG_CHECKMEMORY_EXIT(eStatus );
    return (eStatus);
}
/*--------------------------{end PROG_CheckMemory}-------------------------------*/
#endif /* PROG_CHECK_MEMORY_ENABLE == STD_ON */


/*-------------------{PROG_CheckProgrammingDependencies}-----------------------*/
#if (PROG_CHECK_PROGRAMMING_DEPENDENCIES_REQUEST_ENABLE == STD_ON)
tUdsStatus PROG_CheckProgrammingDependencies(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;

    ICOV(1832);DBG_PROG_CHECKPROGRAMMINGDEPENDENCIES_ENTRY(pulLen, aubUdsData );

#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
    eStatus = PROG_CheckProgrammingDependencies_Impl20(pulLen, aubUdsData);
#else
    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECK_PRG_DEP);
#endif


    DBG_PROG_CHECKPROGRAMMINGDEPENDENCIES_EXIT(eStatus );
    return (eStatus);
}
#endif /* ((PROG_CHECK_PROGRAMMING_DEPENDENCIES_ENABLE == STD_ON)\
    && (PROG_CHECK_PROGRAMMING_DEPENDENCIES_REQUEST_ENABLE)) */
/*-----------------{end PROG_CheckProgrammingDependencies}----------------------*/

#if ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_60) && (PROG_APPLI_CHECK_ALGO_EB == STD_ON))
/*--------------------{PROG_ReadFingerPrint}-------------------------*/
tUdsStatus PROG_ReadFingerPrint(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus   eUdsStatus;
    tProgStatus  eProgStatus;
    tProgMemType eMemoryType;
    u8           ubSectionIdx;
    u16          uwFingerPrintPageSize;
    u32          ulAddress;


    ICOV(1833);DBG_PROG_READFINGERPRINT_ENTRY(pulLen,aubUdsData);
    eProgStatus = PROG_E_OK;

    for (ubSectionIdx = 0U; ((ubSectionIdx < PROG_SEGMENT_NB) && (PROG_E_OK == eProgStatus))?BCOV(1834):!BCOV(1835); ubSectionIdx++)
    {
        eMemoryType = m_astCfgMemory[stConfigSegment[ubSectionIdx].ubMemoryIdx].eMemoryType;

        if ((eMemoryType == PROG_MEM_TYPE_FLASH)?BCOV(1836):!BCOV(1837))
        {
            uwFingerPrintPageSize = PROG_FINGERPRINT_FLASH_PAGE_SIZE;
        }
        else if ((eMemoryType == PROG_MEM_TYPE_FLASH_EXT)?BCOV(1838):!BCOV(1839))
        {
            uwFingerPrintPageSize = PROG_FINGERPRINT_FLASH_EXT_PAGE_SIZE;
        }
        else if ((eMemoryType == PROG_MEM_TYPE_CUSTOM)?BCOV(1840):!BCOV(1841))
        {
            uwFingerPrintPageSize = PROG_FINGERPRINT_CUSTOM_MEM_PAGE_SIZE;
        }
        else
        {
#if (STD_ON==PROG_RAMSEG_FINGERPRINT_SUPPORT)
/* CHECK: NOPARSE */
/* NOCOV-FEATURE_NOT_USED */
/*This part of the code is not considered for code coverage as the else can never be reached because
the current memory configuration cannot support the memory types other than Flash/Flash-Ext/RAM/Custom*/
            if(PROG_MEM_TYPE_RAM==eMemoryType)
            {
                uwFingerPrintPageSize=PROG_FINGERPRINT_SIZE;
            }
            else
#endif
            {
            /*For OEM_IND this code cannot be reached practically*/
                uwFingerPrintPageSize = 0U;
            }
/* CHECK: PARSE */
        }
#if (STD_ON==PROG_RAMSEG_FINGERPRINT_SUPPORT)
/* CHECK: NOPARSE */
/* NOCOV-FEATURE_NOT_USED */
/*This part of the code is not considered for code coverage as the else part can never be executed because
the current memory configuration cannot support the memory types other than Flash/Flash-Ext/RAM/Custom.
Therefore, uwFingerPrintPageSize= 0 condition cannot be reached for OEM-Ind variant*/
#endif
        if(uwFingerPrintPageSize != 0U)
        {
            /* FingerPrintStartAddr = FlsEndAddr - 2 * FlagSize - FlsPageSize */
            ulAddress = (u32)( ( (stConfigSegment[ubSectionIdx].ulEraseEndAddress
                            - (2U * m_astCfgMemory[stConfigSegment[ubSectionIdx].ubMemoryIdx].ulMinValueToWrite))
                            - uwFingerPrintPageSize)
                            + 1U);

            /* read finger print */
            eProgStatus = PROG_MemDataAccess(m_astCfgMemory[stConfigSegment[ubSectionIdx].ubMemoryIdx].eMemoryType,
                                            PROG_MEM_OPERATION_TYPE_READ,
                                            ulAddress,
                                            PROG_FINGERPRINT_SIZE,
                                            &aubUdsData[4U + (PROG_FINGERPRINT_SIZE * ubSectionIdx)]);
        }
        else
        {
            eProgStatus = PROG_E_NOT_OK;
        }
/* CHECK: PARSE */

    }

    if ((PROG_E_OK == eProgStatus)?BCOV(1842):!BCOV(1843))
    {
        eUdsStatus = UDS_ACK;
        aubUdsData[3] = PROG_SEGMENT_NB;
        /* Set length to 3(request func + DID) + 1 Number of section + 2 bytes per section */
        *pulLen = 4U + (PROG_FINGERPRINT_SIZE*PROG_SEGMENT_NB);
    }
    else
    {
        /* error during erasing */
        eUdsStatus = UDS_NRC_72;
    }

    DBG_PROG_READFINGERPRINT_EXIT(eUdsStatus);
    return(eUdsStatus);
}
/*------------------{end PROG_ReadFingerPrint}-----------------------*/
#endif /* ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_60)) */

#if PROG_TRANSFER_DATA_ENABLE == STD_ON
/*------------------------{PROG_StreamingFrameReceived}--------------------------*/
void PROG_StreamingFrameReceived(u16 ulReceivedDataLength, u8* aubData)
{
    ICOV(1844);DBG_PROG_STREAMINGFRAMERECEIVED_ENTRY(ulReceivedDataLength, aubData );
    /* This function can be called under interruption and shall not modify variable that can be in used in Prog module */

    if ((NULL_PTR != aubData)?BCOV(1845):!BCOV(1846))
    {

        if ((aubData[0] == 0x36U)?BCOV(1847):!BCOV(1848))
        {
            m_uwStreamingLength = ulReceivedDataLength;

            /* Store request information */

            m_stDiagMessageInfo.pubData = aubData;
            m_stDiagMessageInfo.pubTxData = aubData;
            /* Initialize request status */

            m_stDiagMessageInfo.ubDiagStatus = UDS_ACK;

            /* Post Event in state machine */
            PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_STREAMING);

        }
    }
    DBG_PROG_STREAMINGFRAMERECEIVED_EXIT();

}
/*----------------------{end PROG_StreamingFrameReceived}------------------------*/
#endif /* PROG_TRANSFER_DATA_ENABLE == STD_ON */

/*------------------------{PROG_OpenProgrammingSession}--------------------------*/
void PROG_OpenProgrammingSession(void)
{
    ICOV(1849);DBG_PROG_OPENPROGRAMMINGSESSION_ENTRY( );
    /* Post Event in state machine */
    PROG_HsmEmit(&PROG_HsmScPROG,
            PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION);

#if (PROG_PEC_ENABLE == STD_ON)
    /* Reset PEC */
    m_uwPEC = PROG_PEC_NO_ERROR;
#endif
    DBG_PROG_OPENPROGRAMMINGSESSION_EXIT( );
}
/*----------------------{end PROG_OpenProgrammingSession}------------------------*/

/*-------------------------------{PROG_Dsc01Cbk}---------------------------------*/
tUdsStatus PROG_Dsc01Cbk(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;

#if (PROG_RESET_AFTER_DSC01_IN_DEFAULT_SESSION == STD_OFF)
    tUdsSessionType CurrentSession;
#endif /* (PROG_RESET_AFTER_DSC01_IN_DEFAULT_SESSION == STD_OFF) */

    ICOV(1850);DBG_PROG_DSC01CBK_ENTRY(pulLen, aubUdsData );

#if (PROG_RESET_AFTER_DSC01_IN_DEFAULT_SESSION == STD_ON)
    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01);
#else
    /* If the current session is programming */
    CurrentSession = UDS_GetCurrentSession();
    if ((UDS_SESSION_DEFAULT != CurrentSession)?BCOV(1851):!BCOV(1852))
    {
        /* Reset performed */
        eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01);
    }
    else
    {
        /* Reset not performed */
        eStatus = UDS_ACK;
        PROG_SetSecurityLevel (PROG_SEC_LEVEL_LOCK);
    }

#endif /* (RESET_FROM_DEFAULT_TO_DEFAULT_SESSION == STD_ON) */

    DBG_PROG_DSC01CBK_EXIT(eStatus );
    return (eStatus);

}
/*-----------------------------{end PROG_Dsc01Cbk}-------------------------------*/

#if ((((PROG_IMPL_VARIANT == PROG_IMPL_20) || (PROG_IMPL_VARIANT == PROG_IMPL_40)) || (PROG_IMPL_VARIANT == PROG_IMPL_80)) && ((PROG_RESPOND_TO_PROG_SESSION == STD_ON)))
/*-------------------------------{PROG_Dsc02Cbk}---------------------------------*/
tUdsStatus PROG_Dsc02Cbk
(
    PduLengthType *pulLen,
    u8 *aubUdsData
)
{
    tUdsStatus eStatus;

#if (PROG_IMPL_VARIANT == PROG_IMPL_80)
    tUdsSessionType CurrentSession;
#else
#if (PROG_PRECOND_CHECK_ENABLE == STD_ON)
    tProgStatus eProgPrecondStatus;
#endif /*(PROG_PRECOND_CHECK_ENABLE == STD_ON)*/
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_80)*/

    ICOV(1853);DBG_PROG_DSC02CBK_ENTRY(pulLen, aubUdsData);

    if (((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))?BCOV(1854):!BCOV(1855))
    {
#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
        if ((0x01U == m_ubIsLocked )?BCOV(1856):!BCOV(1857))
        {
            eStatus = UDS_NRC_33;
        }
        else
        {
            m_ubIsLocked = 0x01U;
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_20) */
            if ((m_ubSimulateProgSessionWithResponse == TRUE)?BCOV(1858):!BCOV(1859))
            {
#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
                eStatus = UDS_NRC_78;
                /*Store buffer address */
                m_stDiagMessageInfo.pubData = aubUdsData;
                m_stDiagMessageInfo.pubTxData = aubUdsData;
#else
                eStatus = UDS_ACK;
#if (PROG_IMPL_VARIANT == PROG_IMPL_80)
                m_ubSimulateProgSessionWithResponse = FALSE;
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_80) */
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_20) */
            }
            else
            {
                if((m_ubProgIsInit == TRUE)?BCOV(1860):!BCOV(1861))
                {
#if (PROG_IMPL_VARIANT == PROG_IMPL_80)
                    /* Get the UDS current session */
                    CurrentSession = UDS_GetCurrentSession();
                    /* If UDS current session is different from programming then send positive response */
                    if((UDS_SESSION_PROGRAMMING != CurrentSession)?BCOV(1862):!BCOV(1863))
                    {
                        eStatus = UDS_ACK;
                    }
                    else
                    {
                        eStatus = UDS_NRC_22;
                    }
#elif (PROG_PRECOND_CHECK_ENABLE == STD_ON)
                    /*call pre-condition check*/
                    eProgPrecondStatus = PROG_CustCheckProgPrecond(&eStatus);
                    if((PROG_E_OK == eProgPrecondStatus)?BCOV(1864):!BCOV(1865))
                    {
                        eStatus = UDS_ACK;
                    }
                    else
                    {
                        eStatus = UDS_NRC_22;
                    }
#else
                    eStatus = UDS_ACK;
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_80) */
                }
                else
                {
                    eStatus = UDS_NRC_21;
                }
            }
#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
        }
#endif
    }
    else
    {
        eStatus = UDS_ERR_COHE;
    }
    DBG_PROG_DSC02CBK_EXIT( eStatus);
    return (eStatus);
}
/*-----------------------------{end PROG_Dsc02Cbk}-------------------------------*/
#endif /* ((((PROG_IMPL_VARIANT == PROG_IMPL_20) || (PROG_IMPL_VARIANT == PROG_IMPL_40)) || (PROG_IMPL_VARIANT == PROG_IMPL_80)) && ((PROG_RESPOND_TO_PROG_SESSION == STD_ON))) */

#if (PROG_EXTENDED_SESSION_MANAGED == STD_ON)
/*-------------------------------{PROG_Dsc03Cbk}---------------------------------*/
tUdsStatus PROG_Dsc03Cbk(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1866);DBG_PROG_DSC03CBK_ENTRY(pulLen, aubUdsData);

    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03);

    /* Force status to Acknowledge if no error occurred */
    if ((UDS_ERR_COHE != eStatus)?BCOV(1867):!BCOV(1868))
    {
        eStatus = UDS_ACK;
    }

    DBG_PROG_DSC03CBK_EXIT(eStatus);
    return (eStatus);
}
/*-----------------------------{end PROG_Dsc03Cbk}-------------------------------*/
#endif

#if PROG_ACTIVE_CURRENT_SESSION_REQUEST_ENABLE == STD_ON
/*---------------------------{PROG_GetActiveCurrentSession}----------------------*/
tUdsStatus PROG_GetActiveCurrentSession(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1869);DBG_PROG_GETACTIVECURRENTSESSION_ENTRY(pulLen, aubUdsData );

#if(PROG_IMPL_VARIANT == PROG_IMPL_40)
    if((m_stReprogInfo.ubRDReceived == TRUE)?BCOV(1870):!BCOV(1871))
    {
        eStatus = UDS_NRC_22;
    }
    else
#endif
    {
    if (((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))?BCOV(1872):!BCOV(1873))
    {
        aubUdsData[3] = UDS_GetCurrentSession();
        *pulLen = 4U;
        eStatus = UDS_ACK;
    }
    else
    {
        eStatus = UDS_ERR_COHE;
        }
    }
    DBG_PROG_GETACTIVECURRENTSESSION_EXIT(eStatus );
    return eStatus;
}
/*--------------------------{end PROG_GetActiveCurrentSession}-------------------*/
#endif /* PROG_ACTIVE_CURRENT_SESSION_REQUEST_ENABLE == STD_ON */

#if PROG_CURRENT_DIAG_APPLICATION_REQUEST_ENABLE == STD_ON
/*----------------------------{PROG_GetCurrentDiagApp}---------------------------*/
tUdsStatus PROG_GetCurrentDiagApp(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1874);DBG_PROG_GETCURRENTDIAGAPP_ENTRY(pulLen, aubUdsData );

    if (((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))?BCOV(1875):!BCOV(1876))
    {
        aubUdsData[3] = (u8)(PROG_CURRENT_DIAG_APP);
        *pulLen = 4U;
        eStatus = UDS_ACK;
    }
    else
    {
        eStatus = UDS_ERR_COHE;
    }
    DBG_PROG_GETCURRENTDIAGAPP_EXIT(eStatus);
    return eStatus;
}
/*---------------------------{end PROG_GetCurrentDiagApp}------------------------*/
#endif /* PROG_CURRENT_DIAG_APPLICATION_REQUEST_ENABLE == STD_ON */

#if PROG_GET_BOOT_STATUS_REQUEST_ENABLE == STD_ON
/*----------------------------{PROG_GetBootStatus}---------------------------*/
tUdsStatus PROG_GetBootStatus(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1877);DBG_PROG_GETBOOTSTATUS_ENTRY(pulLen, aubUdsData );

    if (((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))?BCOV(1878):!BCOV(1879))
    {
        /* Set boot status in response */
        aubUdsData[3] = m_stBootStatus.ubBootIntegrity;
        aubUdsData[4] = m_stBootStatus.ubSignatureBypass;

        *pulLen = 5U;
        eStatus = UDS_ACK;
    }
    else
    {
        eStatus = UDS_ERR_COHE;
    }
    DBG_PROG_GETBOOTSTATUS_EXIT(eStatus );
    return eStatus;
}
/*---------------------------{end PROG_GetBootStatus}------------------------*/
#endif /* PROG_BOOT_STATUS_REQUEST_ENABLE == STD_ON */

#if PROG_GET_PEC_REQUEST_ENABLE == STD_ON
/*----------------------------{PROG_GetPEC}---------------------------*/
tUdsStatus PROG_GetPEC(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1880);DBG_PROG_GETPEC_ENTRY(pulLen, aubUdsData );

    if (((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))?BCOV(1881):!BCOV(1882))
    {
        aubUdsData[3] = (u8)((u16)(m_uwPEC >> 8U) & 0x00FFU);
        aubUdsData[4] = (u8)(m_uwPEC & 0x00FFU);

        *pulLen = 5U;
        eStatus = UDS_ACK;
    }
    else
    {
        eStatus = UDS_ERR_COHE;
    }
    DBG_PROG_GETPEC_EXIT(eStatus );
    return eStatus;
}
/*---------------------------{end PROG_GetPEC}------------------------*/
#endif /* PROG_GET_PEC_REQUEST_ENABLE == STD_ON */

#if PROG_GET_ECU_ID_REQUEST_ENABLE == STD_ON
/*----------------------------{PROG_GetEcuID}---------------------------*/
tUdsStatus PROG_GetEcuID(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1883);DBG_PROG_GETECUID_ENTRY(pulLen, aubUdsData );

    if (((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))?BCOV(1884):!BCOV(1885))
    {

        PROG_GetDidF0F3(&aubUdsData[3]);

        *pulLen = 3U + PROG_ECU_ID_SIZE;
        eStatus = UDS_ACK;
    }
    else
    {
        eStatus = UDS_ERR_COHE;
    }
    DBG_PROG_GETECUID_EXIT(eStatus );
    return eStatus;
}
/*---------------------------{end PROG_GetEcuID}------------------------*/


/*----------------------------{PROG_GetDidF0F3}-------------------------*/
#define PROG_GET_DID_F0F3_START_SEC_CODE
#include <MemMap.h>
void PROG_GetDidF0F3(u8 *aubData)
{
#if (PROG_USE_ECUID_CALLBACK == STD_OFF)
    u8 ubIdx;
#endif
    ICOV(1886);DBG_PROG_GETDIDF0F3_ENTRY(aubData );

    if ((NULL_PTR != aubData)?BCOV(1887):!BCOV(1888))
    {
#if (PROG_USE_ECUID_CALLBACK == STD_OFF)
        for(ubIdx = 0U; (ubIdx < PROG_ECU_ID_SIZE)?BCOV(1889):!BCOV(1890); ubIdx++)
        {
            aubData[ubIdx] = m_stBootInfoBlock.aubEcuId[ubIdx];
        }
#else
        PROG_CustomGetEcuId(&aubData[0]);
#endif

    }
    DBG_PROG_GETDIDF0F3_EXIT( );
}
#define PROG_GET_DID_F0F3_STOP_SEC_CODE
#include <MemMap.h>
/*-------------------------{end PROG_GetDidF0F3}------------------------*/
#endif /* PROG_GET_ECU_ID_REQUEST_ENABLE == STD_ON */

#if PROG_GET_ECU_ADDR_REQUEST_ENABLE == STD_ON
/*----------------------------{PROG_GetEcuAddr}---------------------------*/
tUdsStatus PROG_GetEcuAddr(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1891);DBG_PROG_GETECUADDR_ENTRY(pulLen, aubUdsData );

    if (((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))?BCOV(1892):!BCOV(1893))
    {
        aubUdsData[3] = PROG_ECU_ADDR;

        *pulLen = 4U;
        eStatus = UDS_ACK;
    }
    else
    {
        eStatus = UDS_ERR_COHE;
    }
    DBG_PROG_GETECUADDR_EXIT(eStatus );
    return eStatus;
}
/*---------------------------{end PROG_GetEcuAddr}------------------------*/
#endif /* PROG_GET_ECU_ADDR_REQUEST_ENABLE == STD_ON */

#if PROG_GET_ECU_NAME_REQUEST_ENABLE == STD_ON
/*----------------------------{PROG_GetEcuName}---------------------------*/
tUdsStatus PROG_GetEcuName(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eStatus;
    ICOV(1894);DBG_PROG_GETECUNAME_ENTRY(pulLen, aubUdsData );

    if (((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))?BCOV(1895):!BCOV(1896))
    {

        PROG_GetDidF0F6(&aubUdsData[3]);

        *pulLen = 3U + PROG_SUBJECT_NAME_SIZE + PROG_ECU_NAME_SIZE;
        eStatus = UDS_ACK;
    }
    else
    {
        eStatus = UDS_ERR_COHE;
    }
    DBG_PROG_GETECUNAME_EXIT(eStatus );
    return eStatus;
}
/*---------------------------{end PROG_GetEcuName}------------------------*/
/*----------------------------{PROG_GetDidF0F6}-------------------------*/
#define PROG_GET_DID_F0F6_START_SEC_CODE
#include <MemMap.h>
void PROG_GetDidF0F6(u8 *aubData)
{
    u8 ubIdx;
    ICOV(1897);DBG_PROG_GETDIDF0F6_ENTRY(aubData );

    if ((NULL_PTR != aubData)?BCOV(1898):!BCOV(1899))
    {

        for(ubIdx = 0U; (ubIdx < PROG_SUBJECT_NAME_SIZE)?BCOV(1900):!BCOV(1901); ubIdx++)
        {
            aubData[ubIdx] = m_stBootInfoBlock.aubSubjectName[ubIdx];
        }

        for(ubIdx = 0U; (ubIdx < PROG_ECU_NAME_SIZE)?BCOV(1902):!BCOV(1903); ubIdx++)
        {
            aubData[PROG_SUBJECT_NAME_SIZE + ubIdx] = m_stBootInfoBlock.aubEcuName[ubIdx];
        }
    }
    DBG_PROG_GETDIDF0F6_EXIT();
}
#define PROG_GET_DID_F0F6_STOP_SEC_CODE
#include <MemMap.h>
/*------------------------{end PROG_GetDidF0F6}------------------------*/
#endif /* PROG_GET_ECU_NAME_REQUEST_ENABLE == STD_ON */

#if PROG_GET_SBA_TICKET_REQUEST_ENABLE == STD_ON
/*----------------------------{PROG_GetSbaTicket}---------------------------*/
tUdsStatus PROG_GetSbaTicket(PduLengthType *pulLen, u8 *aubUdsData)
{
    tProgStatus eProgStatus;
    tUdsStatus eUdsStatus;
    u16 uwLoopIndex;
    ICOV(1904);DBG_PROG_GETSBATICKET_ENTRY(pulLen, aubUdsData );

    if (((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))?BCOV(1905):!BCOV(1906))
    {

        /* copy the SBA ticket buffer to send it back */
        eProgStatus = PROG_CopySBATicket(m_aubSwInfo);

        /* copy the sba ticket including the first 2 bytes representing the data type */
        for (uwLoopIndex = 0; (uwLoopIndex < PROG_SBA_TICKET_SIZE)?BCOV(1907):!BCOV(1908); uwLoopIndex++)
        {
            aubUdsData[3U + uwLoopIndex] = m_aubSwInfo[uwLoopIndex];
        }

        if((eProgStatus == PROG_E_OK)?BCOV(1909):!BCOV(1910))
        {
            eUdsStatus = UDS_ACK;

            *pulLen = 3U + PROG_SBA_TICKET_SIZE;
        }
        else
        {
            eUdsStatus = UDS_NRC_31;
        }

    }
    else
    {
        eUdsStatus = UDS_ERR_COHE;
    }
    DBG_PROG_GETSBATICKET_EXIT(eStatus);
    return eUdsStatus;
}
/*---------------------------{end PROG_GetSbaTicket}------------------------*/
#endif /* PROG_GET_SBA_TICKET_REQUEST_ENABLE == STD_ON */

#if PROG_GET_BOOT_INFO_REQUEST_ENABLE == STD_ON
/*----------------------------{PROG_GetBootInfo}---------------------------*/
tUdsStatus PROG_GetBootInfo(PduLengthType *pulLen, u8 *aubUdsData)
{
    u8 ubIdx;
    tUdsStatus eStatus;
    ICOV(1911);DBG_PROG_GETBOOTINFO_ENTRY(pulLen, aubUdsData );

    if (((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))?BCOV(1912):!BCOV(1913))
    {
        /* Boot Number of Modules */
        aubUdsData[3] = PROG_BOOT_NUMBER_OF_MODULES;

        /* Boot Module ID is always set to Primary Micro ID */
        aubUdsData[3 + PROG_BOOT_NB_MODULE_SIZE] = PROG_BOOT_PRIMARY_MICRO_ID;

        /* Boot Part Number */
        for(ubIdx = 0U; (ubIdx < PROG_BOOT_PART_NUMBER_SIZE)?BCOV(1914):!BCOV(1915); ubIdx++)
        {
            aubUdsData[3 + PROG_BOOT_NB_MODULE_SIZE + PROG_BOOT_MODULE_ID_SIZE + ubIdx] = m_stBootInfoBlock.aubBootPartNumber[ubIdx];
        }

        /* Boot DLS */
        for(ubIdx = 0U; (ubIdx < PROG_BOOT_DLS_SIZE)?BCOV(1916):!BCOV(1917); ubIdx++)
        {
            aubUdsData[3 + PROG_BOOT_NB_MODULE_SIZE + PROG_BOOT_MODULE_ID_SIZE + PROG_BOOT_PART_NUMBER_SIZE + ubIdx] = \
            m_stBootInfoBlock.aubBootDLS[ubIdx];
        }

        /* Update length */
        *pulLen = 3U + PROG_BOOT_NB_MODULE_SIZE + PROG_BOOT_MODULE_ID_SIZE + PROG_BOOT_PART_NUMBER_SIZE + PROG_BOOT_DLS_SIZE;

        /* Acknowledgment */
        eStatus = UDS_ACK;
    }
    else
    {
        /* Error */
        eStatus = UDS_ERR_COHE;
    }
    DBG_PROG_GETBOOTINFO_EXIT(eStatus);
    return eStatus;
}
/*---------------------------{end PROG_GetBootInfo}------------------------*/
#endif /* PROG_GET_BOOT_INFO_REQUEST_ENABLE == STD_ON */

#if PROG_GET_PSI_REQUEST_ENABLE == STD_ON
/*----------------------------{PROG_GetPSIValues}--------------------------------*/
tUdsStatus PROG_GetPSIValues(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eUdsStatus;
    tProgStatus eProgStatus;
    u8 ubPartitionId;
    u8 ubPartitionIdIdx;
    ICOV(1918);DBG_PROG_GETPSIVALUES_ENTRY(pulLen, aubUdsData );

    eProgStatus = PROG_E_OK;
    eUdsStatus = UDS_ACK;

/*If the Current segement is HSM, then reset the patition to Application in order to start read PSI from Application Segment and
  there is not PSI value for HSM*/
#if(PROG_HSM_UPDATE_ENABLE == STD_ON)
    if((stConfigSegment[m_stCurrentSegment.ubSegmentId].ePartitionType == PROG_HSM_PARTITION)?BCOV(1919):!BCOV(1920))
    {
        m_stCurrentSegment.ubSegmentId = PROG_APP_SEGMENT_ID;
    }
#endif

    if(((pulLen != NULL_PTR) && (aubUdsData != NULL_PTR))?BCOV(1921):!BCOV(1922))
    {
        ubPartitionId = 1U;
        ubPartitionIdIdx = 1U;

        while((eProgStatus != PROG_E_NOT_OK)?BCOV(1923):!BCOV(1924))
        {
            /* Check if partition is revoked */
            eProgStatus = PROG_CheckPSIValue(ubPartitionId,PROG_PSI_REVOKED);

            if((eProgStatus == PROG_E_OK)?BCOV(1925):!BCOV(1926))
            {
                aubUdsData[3U + ((ubPartitionIdIdx - 1U) * 2U)] = ubPartitionId;
                aubUdsData[4U + ((ubPartitionIdIdx - 1U) * 2U)] = PROG_PSI_DID_REVOKED;

                if (( 1 == ubPartitionId)?BCOV(1927):!BCOV(1928))
                {
                    /* application is not valid, PSI from calibration cannot be get and it is set to INVALID */
                    eProgStatus = PROG_E_NOT_OK;

                    aubUdsData[5U] = 2U;
                    aubUdsData[6U] = PROG_PSI_DID_INVALID;

                    *pulLen = 7;

                }
            }
            else if((eProgStatus == PROG_E_CHECK_FAILED)?BCOV(1929):!BCOV(1930))
            {
                /* if not revoked check if PSI is programmed */
                eProgStatus = PROG_CheckPSIValue(ubPartitionId,PROG_PSI_PROGRAMMED);

                if((eProgStatus == PROG_E_OK)?BCOV(1931):!BCOV(1932))
                {
                    aubUdsData[3U + ((ubPartitionIdIdx - 1U) * 2U)] = ubPartitionId;
                    aubUdsData[4U + ((ubPartitionIdIdx - 1U) * 2U)] = PROG_PSI_DID_PROGRAMMED;
                }
                else
                {
                    aubUdsData[3U + ((ubPartitionIdIdx - 1U) * 2U)] = ubPartitionId;
                    aubUdsData[4U + ((ubPartitionIdIdx - 1U) * 2U)] = PROG_PSI_DID_INVALID;

                    if (( 1 == ubPartitionId)?BCOV(1933):!BCOV(1934))
                    {
                        /* application is not valid, PSI from calibration cannot be get and it is set to INVALID */
                        eProgStatus = PROG_E_NOT_OK;

                        aubUdsData[5U] = 2U;
                        aubUdsData[6U] = PROG_PSI_DID_INVALID;

                        *pulLen = 7;
                    }
                }
            }
            /* If return NOK all partition has been checked */
            else
            {
                *pulLen = (u16)(3U + (((u16)ubPartitionIdIdx - 1U) * 2U));
            }

            ubPartitionId++;
            ubPartitionIdIdx++;

#if(PROG_HSM_UPDATE_ENABLE == STD_ON)
            /*If the partition ID equal to HSM, then skip from CheckPSI for HSM, as it not support the PSI*/
            if((ubPartitionId == PROG_HSM_PARTITION_ID)?BCOV(1935):!BCOV(1936))
            {
                ubPartitionId++;
            }
#endif
        }
    }
    else
    {
        eUdsStatus = UDS_ERR_COHE;
    }
    DBG_PROG_GETPSIVALUES_EXIT(eUdsStatus);
    return eUdsStatus;
}
/*---------------------------{end PROG_GetPSIValues}-----------------------------*/
#endif /* PROG_GET_PSI_REQUEST_ENABLE == STD_ON */


/*--------------------------{PROG_SetSleepTimeout}-------------------------------*/
#if (PROG_SLEEP_MANAGEMENT_TYPE == PROG_SLEEP_MANAGEMENT_TIMEOUT)
void PROG_SetSleepTimeout(u32 ulTimeoutValue)
{
    ICOV(1937);DBG_PROG_SETSLEEPTIMEOUT_ENTRY(ulTimeoutValue );
    if((PROG_TRUE == m_ubBootInDefaultSession)?BCOV(1938):!BCOV(1939))
    {
      m_ulSleepTimeout = ulTimeoutValue;
    }
    DBG_PROG_SETSLEEPTIMEOUT_EXIT( );
}
#endif /* (PROG_SLEEP_MANAGEMENT_TYPE == PROG_SLEEP_MANAGEMENT_TIMEOUT) */
/*------------------------{end PROG_SetSleepTimeout}-----------------------------*/

/*-----------------------------{PROG_Entry_Sleep}--------------------------------*/
void PROG_Entry_Sleep(void)
{
    ICOV(1940);DBG_PROG_ENTRY_SLEEP_ENTRY();
#if PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON
    /* Clear Flash routines */
    PROG_DrvDown_EraseFlashRoutines();
    PROG_DrvDown_SetFlashRoutinesCorruption(PROG_FALSE);
#endif
#if (PROG_DECOMP_FLASH_ROUTINES == STD_ON)
    /* Clear Flash routines and mention that they are not present */
    (void)PROG_Drv_ClearFlashRoutines();
#endif
#if (PROG_SLEEP_MANAGEMENT_TYPE == PROG_SLEEP_MANAGEMENT_TIMEOUT)
    /* Request go to sleep mode of the hardware */
    BoardSetSleepState();
    /* Function doesn't return */
#endif /* (PROG_SLEEP_MANAGEMENT_TYPE == PROG_SLEEP_MANAGEMENT_TIMEOUT) */
    DBG_PROG_ENTRY_SLEEP_EXIT();
}
/*---------------------------{end PROG_Entry_Sleep}------------------------------*/
#if ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_60))
/*------------------------------{PROG_UpdateWfSuccessFlag}----------------------------------*/
NCS_PRI_FCT void PROG_UpdateWfSuccessFlag(tProgBoolean ubValue)
{
    /*if Application Fingerprint*/
    ICOV(1941);if (((PROG_WF_DID_1ST_BYTE == m_stDiagMessageInfo.pubData[1]) &&
        (PROG_WF_DID_2ND_BYTE_APP == m_stDiagMessageInfo.pubData[2]))?BCOV(1942):!BCOV(1943))
    {
        m_stWfSuccess.ubAppFingerprintWriten = ubValue;
#if ((PROG_IMPL_VARIANT == PROG_IMPL_40)|| (PROG_IMPL_VARIANT == PROG_IMPL_50))
        /*Only one fingerprint id*/
        m_stWfSuccess.ubCalFingerprintWriten = ubValue;
        m_stWfSuccess.ubBluFingerprintWriten = ubValue;
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_50)*/
    }
    /*if Calibration Fingerprint*/
#if ((PROG_IMPL_VARIANT != PROG_IMPL_40) && (PROG_IMPL_VARIANT != PROG_IMPL_50))
    else if(((PROG_WF_DID_1ST_BYTE == m_stDiagMessageInfo.pubData[1]) &&
            (PROG_WF_DID_2ND_BYTE_CALIB == m_stDiagMessageInfo.pubData[2]))?BCOV(1944):!BCOV(1945))
    {
        m_stWfSuccess.ubCalFingerprintWriten = ubValue;
    }
#endif
    else
    {
        /*do nothing*/
    }
}
/*----------------------------{end PROG_UpdateWfSuccessFlag}--------------------------------*/
#endif /* PROG_WRITE_FINGERPRINT_ENABLE == STD_ON */
#if ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) || (PROG_IMPL_VARIANT == PROG_IMPL_60))
/*---------------------------{PROG_Entry_WriteFingerprint}-------------------------------*/
void PROG_Entry_WriteFingerprint(void)
{
#if (PROG_WRITE_FINGERPRINT_ENABLE == STD_ON)
    tProgStatus eProgStatus;

#if (PROG_BLOCKID_IN_FINGERPRINT == STD_ON)
    u8 ubFpBlockId;
#endif /* (PROG_BLOCKID_IN_FINGERPRINT == STD_ON) */

    ICOV(1946);DBG_PROG_ENTRY_WRITEFINGERPRINT_ENTRY();

#if (PROG_BLOCKID_IN_FINGERPRINT == STD_ON)
    ubFpBlockId = m_stDiagMessageInfo.pubData[PROG_BLOCKID_INDEX_IN_FINGREPRINT];

    /* Find the corresponding FP block Id to the configured index in FP */
    eProgStatus = PROG_FindBlockIndexInTable(ubFpBlockId, &m_ubFpBlockId);

    if ((PROG_E_NOT_OK == eProgStatus)?BCOV(1947):!BCOV(1948))
    {
        /* Send negative response when index is not found */
        UDS_LongRequestEnd(PROG_NRC_SIZE, m_stDiagMessageInfo.pubTxData, UDS_NRC_31);
        PROG_UpdateWfSuccessFlag(PROG_FALSE);
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
    }
    else
#endif /* (PROG_BLOCKID_IN_FINGERPRINT == STD_ON) */
    {
        /*The fingerprint writing shall be implemented in PROG_Customer module*/
        eProgStatus = PROG_CustomWriteFingerprint(&m_stDiagMessageInfo.pubData[1]);
        if((PROG_E_OK == eProgStatus)?BCOV(1949):!BCOV(1950))
        {
            /* Send positive response with same data than request*/
            UDS_LongRequestEnd(PROG_WF_RESPONSE_SIZE, m_stDiagMessageInfo.pubTxData, UDS_ACK);
            /*Send WriteFingerprintOK event for the state machine*/
#if (PROG_IMPL_VARIANT != PROG_IMPL_60)
            PROG_UpdateWfSuccessFlag(PROG_TRUE);
#endif
            PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
        }
        else if ((PROG_E_BUSY == eProgStatus)?BCOV(1951):!BCOV(1952))
        {
            /*do nothing*/
        }
        else
        {
            /* Send negative response with same data than request*/
            UDS_LongRequestEnd(PROG_NRC_SIZE, m_stDiagMessageInfo.pubTxData, UDS_NRC_72);
#if (PROG_IMPL_VARIANT != PROG_IMPL_31)
            PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
#else
            PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
#endif /*(PROG_IMPL_VARIANT != PROG_IMPL_31)*/
#if (PROG_IMPL_VARIANT != PROG_IMPL_60)
            PROG_UpdateWfSuccessFlag(PROG_FALSE);
#endif
        }
        DBG_PROG_ENTRY_WRITEFINGERPRINT_EXIT();
    }
#endif    /*#if (PROG_WRITE_FINGERPRINT_ENABLE == STD_ON)*/
ICOV(1946);}
/*-------------------------{end PROG_Entry_WriteFingerprint}-----------------------------*/
#endif /* #if PROG_WRITE_FINGERPRINT_ENABLE == STD_ON */
#if ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) || (PROG_IMPL_VARIANT == PROG_IMPL_60))
/*---------------------------{PROG_WriteFingerprintCheck}-------------------------------*/
void PROG_WriteFingerprintCheck(void)
{
#if (PROG_WRITE_FINGERPRINT_ENABLE == STD_ON)
    tProgStatus eProgStatus;
    ICOV(1953);DBG_PROG_WRITEFINGERPRINTCHECK_ENTRY();
    /* The fingerprint writing shall be implemented in PROG_Customer module */
    eProgStatus = PROG_CustomGetWriteFingerprintStatus();
    if((PROG_E_OK == eProgStatus)?BCOV(1954):!BCOV(1955))
    {
        /*Send write OK event for the stat emachine*/
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
#if (PROG_IMPL_VARIANT != PROG_IMPL_60)
        PROG_UpdateWfSuccessFlag(PROG_TRUE);
#endif /* (PROG_IMPL_VARIANT != PROG_IMPL_60) */

        /* Send positive response with same data than request*/
        UDS_LongRequestEnd(PROG_WF_RESPONSE_SIZE, m_stDiagMessageInfo.pubTxData, UDS_ACK);
    }
    else if ((PROG_E_BUSY == eProgStatus)?BCOV(1956):!BCOV(1957))
    {
        /*do nothing*/
    }
    else
    {
#if (PROG_IMPL_VARIANT == PROG_IMPL_31)
        /*Send write NOK event for the state machine*/
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
#else
        /*Send write NOK event for the state machine*/
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_31) */

        /* Send positive response with same data than request*/
        UDS_LongRequestEnd(PROG_WF_RESPONSE_SIZE,
        m_stDiagMessageInfo.pubTxData, UDS_NRC_72);
    }
    DBG_PROG_WRITEFINGERPRINTCHECK_EXIT();
#endif/*#if (PROG_WRITE_FINGERPRINT_ENABLE == STD_ON)*/
ICOV(1953);}
/*-------------------------{end PROG_WriteFingerprintCheck}-----------------------------*/
#endif /* #if PROG_WRITE_FINGERPRINT_ENABLE == STD_ON */

#if ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_60) && (PROG_APPLI_CHECK_ALGO_EB == STD_ON))
/*---------------------------{PROG_CustomWriteFingerprint}-------------------------------*/
tProgStatus PROG_CustomWriteFingerprint(u8 * pubRamBuffer)
{
    tProgStatus eProgStatus;
    u32 ulAddress;
    u16 uwFingerPrintPageSize;
    u8 ubMemoryType;

    ICOV(1958);DBG_PROG_CUSTOMWRITEFINGERPRINT_ENTRY(pubRamBuffer);

    ubMemoryType = m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType;
    if((ubMemoryType == PROG_MEM_TYPE_FLASH)?BCOV(1959):!BCOV(1960))
    {
        uwFingerPrintPageSize = PROG_FINGERPRINT_FLASH_PAGE_SIZE;
    }
    else if ((ubMemoryType == PROG_MEM_TYPE_FLASH_EXT)?BCOV(1961):!BCOV(1962))
    {
        uwFingerPrintPageSize = PROG_FINGERPRINT_FLASH_EXT_PAGE_SIZE;
    }
    else
    {
#if (STD_ON==PROG_RAMSEG_FINGERPRINT_SUPPORT)
        if((PROG_MEM_TYPE_RAM==ubMemoryType)?BCOV(1963):!BCOV(1964))
        {
            uwFingerPrintPageSize=PROG_FINGERPRINT_SIZE;
        }
        else
#endif
        {
            uwFingerPrintPageSize = 0U;
        }
    }

    if((uwFingerPrintPageSize != 0U)?BCOV(1965):!BCOV(1966))
#if (PROG_ERASE_TYPE != PROG_ERASE_BY_BLOCK_ID)
    {
        /* Retrieve address of the beginning of the fingerprint area */
        ulAddress = (u32) ( ((stConfigSegment[m_stCurrentSegment.ubSegmentId].ulEraseEndAddress
                                - (2U * m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].ulMinValueToWrite)) /* remove validity flag size */
                                - uwFingerPrintPageSize /* remove fingerprint page size   */
                            )
                            + 1U);
#else
    {
        /* Retrieve address of the beginning of the fingerprint area */
        ulAddress = (u32)((stConfigSegment[stCfgBlock[m_stCurrentSegment.ubLogicalBlockId].ubFirstSegmentId + stCfgBlock[m_stCurrentSegment.ubLogicalBlockId].ubSegmentNbr - 1u].ulEraseEndAddress
                           - (2U * m_astCfgMemory[stConfigSegment[stCfgBlock[m_stCurrentSegment.ubLogicalBlockId].ubFirstSegmentId + stCfgBlock[m_stCurrentSegment.ubLogicalBlockId].ubSegmentNbr - 1u].ubMemoryIdx].ulMinValueToWrite)
                           - uwFingerPrintPageSize /* remove fingerprint page size   */
                           )
                           + 1U);
#endif
        /* Write fingerprint in reserved memory area */

        /* Calculate the write address                   */
        /* The Write/Erase is done with physical address */
#if (PROG_OTA_DUALBANK_USED == STD_ON)
        ulAddress = PROG_CustomCalcInactiveBankWriteAddr(ulAddress);
#endif /*(PROG_OTA_DUALBANK_USED == STD_ON)*/
        eProgStatus = PROG_MemDataAccess(
                m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,
                PROG_MEM_OPERATION_TYPE_WRITE,
                ulAddress,
                uwFingerPrintPageSize,
                &pubRamBuffer[2]);
    }
    else
    {
        eProgStatus = PROG_E_NOT_OK;
    }

    DBG_PROG_CUSTOMWRITEFINGERPRINT_EXIT(eProgStatus);
    return eProgStatus;
}
/*-------------------------{end PROG_CustomWriteFingerprint}-----------------------------*/
#endif /* #if PROG_WRITE_FINGERPRINT_ENABLE == STD_ON */

#if ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_60) && (PROG_APPLI_CHECK_ALGO_EB == STD_ON))
/*---------------------------{PROG_CustomGetWriteFingerprintStatus}-------------------------------*/
tProgStatus PROG_CustomGetWriteFingerprintStatus(void)
{
#if ( (PROG_REPROGMEMM_ENABLED == STD_ON)\
    ||((PROG_FLASHWRAPPER_ENABLED == STD_ON) &&((PROG_FLASH_MODE == PROG_MEMORY_ASYNCHRONOUS) || (PROG_FLASH_EXT_MODE == PROG_MEMORY_ASYNCHRONOUS) || (PROG_CUSTOM_MEMORY_MODE == PROG_MEMORY_ASYNCHRONOUS))))
    tProgStatus eProgStatus;
    ICOV(1967);DBG_PROG_CUSTOMGETWRITEFINGERPRINTSTATUS_ENTRY();
    eProgStatus = PROG_MemJobResult(m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType);

    DBG_PROG_CUSTOMGETWRITEFINGERPRINTSTATUS_EXIT(eProgStatus);
    return eProgStatus;
#else
    ICOV(1968);DBG_PROG_CUSTOMGETWRITEFINGERPRINTSTATUS_ENTRY();
    DBG_PROG_CUSTOMGETWRITEFINGERPRINTSTATUS_EXIT(PROG_E_OK);
    return PROG_E_OK;
#endif
ICOV(1968);}
/*-------------------------{end PROG_CustomGetWriteFingerprintStatus}-----------------------------*/
#endif /* #if PROG_WRITE_FINGERPRINT_ENABLE == STD_ON */
#if (PROG_ECU_RESET_ENABLE == STD_ON)
/*---------------------------{PROG_Entry_EcuReset}-------------------------------*/
void PROG_Entry_EcuReset(void)
{
    ICOV(1969);DBG_PROG_ENTRY_ECURESET_ENTRY();

#if (PROG_BLPDUR_SUPPORT_ENABLE == STD_ON)
    /* Save Connection Info for Appli */
    BlPduR_StoreConnectionInfo();
#endif /*(PROG_BLPDUR_SUPPORT_ENABLE == STD_ON)*/

#if (PROG_RESPOND_BEFORE_RESET == STD_ON)
    /* Send positive response with same data than request*/
    UDS_LongRequestEnd(PROG_ECU_RESET_RESPONSE_SIZE, m_stDiagMessageInfo.pubTxData, UDS_ACK);

#if (PROG_RESET_CAUSE_ENABLE == STD_ON)
    /* Set Reset Cause and indicate that response shall be not sent after reset */
    PROG_CustomStoreResetCause(PROG_RESET_CAUSE_ER, PROG_FALSE);
#endif

    if (((m_stDiagMessageInfo.pubData[1] & 0x80U) != 0x00U)?BCOV(1970):!BCOV(1971))
    {
        /* Simulate Tx confirmation to allow triggering the reset */
        /* Post event in state machine to trig the reset mode */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF);
    }
    else
    {
        /* Do nothing */
        /* TX_CONF event will be pushed when the positive response is sent */
    }
#else /* PROG_RESPOND_BEFORE_RESET == STD_OFF */

#if (PROG_RESET_CAUSE_ENABLE == STD_ON)
    /* Set Reset Cause and indicate that response shall be sent after reset */
    PROG_CustomStoreResetCause(PROG_RESET_CAUSE_ER, PROG_TRUE);
#endif
    /* Stop timer and NRC78 will be sent */
    UDS_StopNRC78Timer();

#endif /* PROG_RESPOND_BEFORE_RESET == STD_OFF */

    DBG_PROG_ENTRY_ECURESET_EXIT();
}
/*-------------------------{end PROG_Entry_EcuReset}-----------------------------*/
#endif /* #if PROG_ECU_RESET_ENABLE == STD_ON */

/*-----------------------------{PROG_Entry_Reset}--------------------------------*/
void PROG_Entry_Reset(void)
{
    ICOV(1972);DBG_PROG_ENTRY_RESET_ENTRY();

#if PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON
    /* Clear Flash routines */
    PROG_DrvDown_EraseFlashRoutines();
    PROG_DrvDown_SetFlashRoutinesCorruption(PROG_FALSE);
#endif

#if (PROG_DECOMP_FLASH_ROUTINES == STD_ON)
    /* Clear Flash routines and mention that they are not present */
    (void)PROG_Drv_ClearFlashRoutines();
#endif

#if (PROG_IMPL_VARIANT == PROG_IMPL_3)
    PROG_ClearVerificationDataStructure(0U);
#endif
#if (PROG_SECURITY_ENABLE == STD_ON)
#if (PROG_NORESET_SECURITYLEVEL==STD_ON)
    /*When this feature is ON, SecurityLevel reset shall be done here for the S3 timeout, reset due to DSC01 or ER requests.*/
    PROG_SetSecurityLevel (PROG_SEC_LEVEL_LOCK);
#endif
#endif
#if (PROG_REQUEST_SEED_DELAY_TIMER_ENABLED == STD_ON)
    /*Rearm request seed delay timer*/
    PROG_SetRsDelayTimer(SA_RS_DELAY_TIMER);
#endif /*(PROG_REQUEST_SEED_DELAY_TIMER_ENABLED == STD_ON)*/
    /* Reset is hardware specific and shall be implemented in PROG_Customer module */
    BoardPerformSwReset();
    /* Function will not return */
    DBG_PROG_ENTRY_RESET_EXIT();
}
/*---------------------------{end PROG_Entry_Reset}------------------------------*/

/*------------------------{PROG_Entry_DefaultSession}----------------------------*/
void PROG_Entry_DefaultSession(void)
{
    ICOV(1973);DBG_PROG_ENTRY_DEFAULTSESSION_ENTRY();

#if (PROG_BLPDUR_SUPPORT_ENABLE == STD_ON)
    /* Save Connection Info for Appli */
    BlPduR_StoreConnectionInfo();
#endif /*(PROG_BLPDUR_SUPPORT_ENABLE == STD_ON)*/

#if (PROG_RESPOND_BEFORE_RESET == STD_ON)
    /* Send positive response with same data than request*/
    UDS_LongRequestEnd(PROG_DSC_RESPONSE_SIZE, m_stDiagMessageInfo.pubTxData, UDS_ACK);

    #if (PROG_RESET_CAUSE_ENABLE == STD_ON)
    /* Set Reset Cause and indicate that response shall be not sent after reset */
    PROG_CustomStoreResetCause(PROG_RESET_CAUSE_DSC01, PROG_FALSE);
    #endif

    if (((m_stDiagMessageInfo.pubData[1] & 0x80U) != 0x00U)?BCOV(1974):!BCOV(1975))
    {
        /* Simulate Tx confirmation to allow triggering the reset */
        /* Post event in state machine to trig the reset mode */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF);
    }
    else
    {
        /* Do nothing */
        /* TX_CONF event will be pushed when the positive response is sent */
    }
#else /* PROG_RESPOND_BEFORE_RESET == STD_OFF */

    #if (PROG_RESET_CAUSE_ENABLE == STD_ON)
    /* Set Reset Cause and indicate that response shall be sent after reset */
    PROG_CustomStoreResetCause(PROG_RESET_CAUSE_DSC01, PROG_TRUE);
    #endif
    /* Stop timer and NRC78 will be sent */
    UDS_StopNRC78Timer();

#endif /* PROG_RESPOND_BEFORE_RESET == STD_OFF */

    DBG_PROG_ENTRY_DEFAULTSESSION_EXIT();
}
/*----------------------{end PROG_Entry_DefaultSession}--------------------------*/

/*---------------------{PROG_Entry_ProgrammingSession}---------------------------*/
void PROG_Entry_ProgrammingSession(void)
{
    ICOV(1976);DBG_PROG_ENTRY_PROGRAMMINGSESSION_ENTRY();
    /* Reset security level */
#if ((PROG_SECURITY_ENABLE == STD_ON) && (PROG_DSC_02_PROTECTED_BY_SA == STD_OFF))
#if (PROG_NORESET_SECURITYLEVEL==STD_OFF)
    PROG_SetSecurityLevel (PROG_SEC_LEVEL_LOCK);
#endif
#endif
#if (PROG_PEC_ENABLE == STD_ON)
    m_uwPEC = PROG_PEC_NO_ERROR;
#endif
#if (PROG_BLU_ACTIVE == STD_ON)
    if((PROG_TRUE == PROG_CustomIsBLUDownloadInProgress())?BCOV(1977):!BCOV(1978))
    {
        /*Go directly to Check Memory Finish state to resume BLU download*/
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS);
    }
#endif /* (PROG_BLU_ACTIVE == STD_ON) */

    DBG_PROG_ENTRY_PROGRAMMINGSESSION_EXIT();
}
/*-------------------{end PROG_Entry_ProgrammingSession}-------------------------*/

/*---------------------{PROG_Entry_ExtendedSession}---------------------------*/
void PROG_Entry_ExtendedSession(void)
{
    ICOV(1979);DBG_PROG_ENTRY_EXTENDEDSESSION_ENTRY();
    /* Reset security level */
#if (PROG_SECURITY_ENABLE == STD_ON)
#if (PROG_NORESET_SECURITYLEVEL==STD_OFF)
    PROG_SetSecurityLevel (PROG_SEC_LEVEL_LOCK);
#endif
#endif
    DBG_PROG_ENTRY_EXTENDEDSESSION_EXIT();
}
/*-------------------{end PROG_Entry_ExtendedSession}-------------------------*/

/*----------------------{PROG_CloseProgrammingSession}---------------------------*/
void PROG_CloseProgrammingSession(tUdsChangeReason eUdsChangeReason)
{
#if ((PROG_APPLI_CHECK_ENABLE == STD_ON) && (PROG_APPLI_CHECK_ON_S3TIMEOUT_ENABLE == STD_ON) && (PROG_RESET_AFTER_S3_TIMEOUT_IN_PROG_SESSION == STD_ON))
    tProgBoolean eProgStatus;
#endif
    ICOV(1980);DBG_PROG_CLOSEPROGRAMMINGSESSION_ENTRY(eUdsChangeReason );

#if (PROG_RESET_AFTER_S3_TIMEOUT_IN_PROG_SESSION == STD_ON)
    if ((UDS_SESSION_TIMEOUT == eUdsChangeReason)?BCOV(1981):!BCOV(1982))
    {
#if ((PROG_APPLI_CHECK_ENABLE == STD_ON) && (PROG_APPLI_CHECK_ON_S3TIMEOUT_ENABLE == STD_ON))
        eProgStatus = PROG_CheckValidAppl();

        if ((PROG_TRUE != eProgStatus)?BCOV(1983):!BCOV(1984))
        {
            /* simulate open programming session */
            m_ubProgFirstCall = TRUE;
            PROG_SimulateOpenProgSessionNoResponse();
        }
        else
#endif /* ((PROG_APPLI_CHECK_ENABLE == STD_ON) && (PROG_APPLI_CHECK_ON_S3TIMEOUT_ENABLE == STD_ON))*/
        {
#if (PROG_RESET_CAUSE_ENABLE == STD_ON)
            /*Set Reset Cause and indicate that response shall not be sent after reset*/
            PROG_CustomStoreResetCause(PROG_RESET_CAUSE_S3_TIMEOUT, PROG_FALSE);
#endif /*(PROG_RESET_CAUSE_ENABLE == STD_ON)*/
            /*Reset shall be performed to go to application*/
            /* Emit event PROG_EVENT_S3_TIMEOUT*/
            PROG_HsmEmit(&PROG_HsmScPROG,
                    PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT);
        }
    }
#endif /*(PROG_RESET_AFTER_S3_TIMEOUT_IN_PROG_SESSION == STD_ON)*/
    DBG_PROG_CLOSEPROGRAMMINGSESSION_EXIT();
}
/*--------------------{end PROG_CloseProgrammingSession}-------------------------*/

/*----------------------{PROG_CloseExtendedSession}---------------------------*/
void PROG_CloseExtendedSession(tUdsChangeReason eUdsChangeReason)
{
#if ((PROG_APPLI_CHECK_ENABLE == STD_ON) && (PROG_APPLI_CHECK_ON_S3TIMEOUT_ENABLE == STD_ON) && (PROG_RESET_AFTER_S3_TIMEOUT_IN_EXT_SESSION == STD_ON))
    tProgBoolean eProgStatus;
#endif
    ICOV(1985);DBG_PROG_CLOSEEXTENDEDSESSION_ENTRY(eUdsChangeReason );
#if (PROG_RESET_AFTER_S3_TIMEOUT_IN_EXT_SESSION == STD_ON)
    if ((UDS_SESSION_TIMEOUT == eUdsChangeReason)?BCOV(1986):!BCOV(1987))
    {
#if ((PROG_APPLI_CHECK_ENABLE == STD_ON) && (PROG_APPLI_CHECK_ON_S3TIMEOUT_ENABLE == STD_ON))
        eProgStatus = PROG_CheckValidAppl();

        if ((PROG_TRUE != eProgStatus)?BCOV(1988):!BCOV(1989))
        {
            /* simulate extended session */
            m_ubProgFirstCall = TRUE;
#if (PROG_DSC02_DENIED_IN_DEF_SESSION == STD_ON)
            PROG_SimulateExtendedSessionNoResponse();
#endif /* (PROG_DSC02_DENIED_IN_DEF_SESSION == STD_ON)*/
        }
        else
#endif /* ((PROG_APPLI_CHECK_ENABLE == STD_ON) && (PROG_APPLI_CHECK_ON_S3TIMEOUT_ENABLE == STD_ON))*/
        {
#if (PROG_RESET_CAUSE_ENABLE == STD_ON)
            /*Set Reset Cause and indicate that response shall not be sent after reset*/
            PROG_CustomStoreResetCause(PROG_RESET_CAUSE_S3_TIMEOUT, PROG_FALSE);
#endif /*(PROG_RESET_CAUSE_ENABLE == STD_ON)*/
            /*Reset shall be performed to go to application*/
            /* Emit event PROG_EVENT_S3_TIMEOUT*/
            PROG_HsmEmit(&PROG_HsmScPROG,
                    PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT);
        }
    }
#endif /*(PROG_RESET_AFTER_S3_TIMEOUT_IN_EXT_SESSION == STD_ON)*/
    DBG_PROG_CLOSEEXTENDEDSESSION_EXIT();
}
/*--------------------{end PROG_CloseExtendedSession}-------------------------*/

/*-------------------------{PROG_Entry_GetSeedCheck}-------------------------------*/
#if ((PROG_SA_SEED_ENABLE == STD_ON) && (PROG_SECURITY_ENABLE == STD_ON))
void PROG_Entry_GetSeedCheck(void)
{
    ICOV(1990);DBG_PROG_ENTRY_GETSEEDCHECK_ENTRY();

#if PROG_NRC78_ON_SA_ENABLE == STD_ON
    /*Send NRC78 response*/
    PROG_SendNRC78();
#else
    /*Simulate Tx confirmation*/
    /*Emit event PROG_EVENT_TX_CONF)*/
    PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF);
#endif

    DBG_PROG_ENTRY_GETSEEDCHECK_EXIT();
}
#endif /* ((PROG_SA_SEED_ENABLE == STD_ON) && (PROG_SECURITY_ENABLE == STD_ON)) */
/*-----------------------{end PROG_Entry_GetSeedCheck}-----------------------------*/

#if (PROG_REQUEST_SEED_DELAY_TIMER_ENABLED == STD_ON)
/*---------------------------{PROG_SetRsDelayTimer}-----------------------------*/
void PROG_SetRsDelayTimer(u32 ulRsDelayTimer)
{
    ICOV(1991);DBG_PROG_SETRSDELAYTIMER_ENTRY(ulRsDelayTimer);
    m_ulRsDelayTimer = ulRsDelayTimer;
    DBG_PROG_SETRSDELAYTIMER_EXIT();
}
/*-------------------------{end PROG_SetRsDelayTimer}---------------------------*/
/*-------------------------{PROG_GetRsDelayTimer}-------------------------------*/
u32 PROG_GetRsDelayTimer(void)
{
    u32 ulRsDelayTimer;

    ICOV(1992);DBG_PROG_GETRSDELAYTIMER_ENTRY();
    ulRsDelayTimer = m_ulRsDelayTimer;
    DBG_PROG_GETRSDELAYTIMER_EXIT(ulRsDelayTimer);

    return ulRsDelayTimer;

}
/*-----------------------{end PROG_GetRsDelayTimer}-----------------------------*/
#endif /*(PROG_REQUEST_SEED_DELAY_TIMER_ENABLED == STD_ON)*/
/*---------------------------{PROG_Entry_GetSeed}--------------------------------*/
#if ((PROG_SA_SEED_ENABLE == STD_ON) && (PROG_SECURITY_ENABLE == STD_ON))
void PROG_Entry_GetSeed(void)
{
#if ((PROG_ANTISCANNING_ENABLED == STD_ON) || (PROG_USE_SA_WITH_CRYPTO == STD_ON)|| (PROG_LIMIT_NB_REQUEST_SEED_ENABLED ==STD_ON) || (PROG_REQUEST_SEED_DELAY_TIMER_ENABLED == STD_ON))
    tSaStatus eSaStatus;
#endif
#if (PROG_LIMIT_NB_REQUEST_SEED_ENABLED ==STD_ON)
    u8 RequestSeedCounter;
    ICOV(1993);RequestSeedCounter = PROG_GetRequestSeedCounter();
#endif /*(PROG_LIMIT_NB_REQUEST_SEED_ENABLED ==STD_ON)*/
    ICOV(1993);DBG_PROG_ENTRY_GETSEED_ENTRY();
#if ((PROG_ANTISCANNING_ENABLED == STD_ON) || (PROG_USE_SA_WITH_CRYPTO == STD_ON) || (PROG_LIMIT_NB_REQUEST_SEED_ENABLED ==STD_ON) || (PROG_REQUEST_SEED_DELAY_TIMER_ENABLED == STD_ON))
#if(PROG_SA_AUTHENTICATION_METHOD == PROG_SA_AUTHENTICATION_0001 )
    /*Get seed from SA module*/
    eSaStatus = SA_GetSeed(&m_stDiagMessageInfo.pubTxData[0U]);
#else
    /*Get seed from SA module*/
    eSaStatus = SA_GetSeed(&m_stDiagMessageInfo.pubTxData[2U]);
#endif
    if((SA_E_OK == eSaStatus)?BCOV(1994):!BCOV(1995))
    {
        /*Send positive response*/
        m_stDiagMessageInfo.ulLength = PROG_SA_SEED_LEN + 2U;
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, UDS_ACK);
#if (PROG_LIMIT_NB_REQUEST_SEED_ENABLED ==STD_ON)
        /*Increment limit request seed counter */
        RequestSeedCounter ++ ;
        PROG_SetRequestSeedCounter(RequestSeedCounter);
#endif /*(PROG_LIMIT_NB_REQUEST_SEED_ENABLED ==STD_ON)*/
        /* Emit event PROG_EVENT_FINISHED */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
    }
#if (PROG_ANTISCANNING_ENABLED == STD_ON)
    else if((SA_E_NOK_AS_LOCKED == eSaStatus)?BCOV(1996):!BCOV(1997))
    {
        /*SA Anti-scanning Locked, send negative response*/
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, UDS_NRC_37);
#if (PROG_LIMIT_NB_REQUEST_SEED_ENABLED ==STD_ON)
        /*Increment limit request seed counter */
        RequestSeedCounter ++ ;
        PROG_SetRequestSeedCounter(RequestSeedCounter);
#endif /*(PROG_LIMIT_NB_REQUEST_SEED_ENABLED ==STD_ON)*/
        /* Emit event PROG_EVENT_UNLOCK_FAILED */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED);
    }
#endif /*(PROG_ANTISCANNING_ENABLED == STD_ON)*/
    else if((SA_E_NOT_OK == eSaStatus)?BCOV(1998):!BCOV(1999))
    {
        /*Crypto configuration problem, send negative response (FailurePreventsExecutionOfRequestedAction)*/
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, UDS_NRC_26);
#if (PROG_LIMIT_NB_REQUEST_SEED_ENABLED ==STD_ON)
        /*Increment limit request seed counter */
        RequestSeedCounter ++ ;
        PROG_SetRequestSeedCounter(RequestSeedCounter);
#endif /*(PROG_LIMIT_NB_REQUEST_SEED_ENABLED ==STD_ON)*/
    }
#if (PROG_LIMIT_NB_REQUEST_SEED_ENABLED ==STD_ON)
    else if ((SA_E_NOK_AS_LIMIT_RS == eSaStatus)?BCOV(2000):!BCOV(2001))
    {
        /*SA request seed limit reached, send negative response)*/
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, UDS_NRC_22);
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
    }
#endif /*(PROG_LIMIT_NB_REQUEST_SEED_ENABLED ==STD_ON)*/
#if (PROG_REQUEST_SEED_DELAY_TIMER_ENABLED == STD_ON)
    else if ((SA_E_NOK_RS_DELAY_LOCKED == eSaStatus)?BCOV(2002):!BCOV(2003))
    {
        /*SA request seed delay timer Locked, send negative response*/
        m_stDiagMessageInfo.ulLength = PROG_NRC_SIZE;
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, UDS_NRC_37);
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED);
    }
#endif /*(PROG_REQUEST_SEED_DELAY_TIMER_ENABLED == STD_ON)*/
    else
    {
        /*do nothing*/
    }
#else
#if(PROG_SA_AUTHENTICATION_METHOD == PROG_SA_AUTHENTICATION_0001 )
    /*Get seed from SA module*/
    (void) SA_GetSeed(&m_stDiagMessageInfo.pubTxData[0U]);
#else
    /*Get seed from SA module*/
    (void) SA_GetSeed(&m_stDiagMessageInfo.pubTxData[2U]);
#endif
    /*Send positive response*/
    m_stDiagMessageInfo.ulLength = PROG_SA_SEED_LEN + 2U;
    UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, UDS_ACK);
    /* Emit event PROG_EVENT_FINISHED */
    PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
#endif /*((PROG_ANTISCANNING_ENABLED == STD_ON) || (PROG_USE_SA_WITH_CRYPTO == STD_ON))*/
    DBG_PROG_ENTRY_GETSEED_EXIT();
}
#endif /* (PROG_SA_SEED_ENABLE == STD_ON) && (PROG_SECURITY_ENABLE == STD_ON) */
/*-------------------------{end PROG_Entry_GetSeed}------------------------------*/

/*---------------------------{PROG_Do_GetSeed}--------------------------------*/
#if ((PROG_SA_SEED_ENABLE == STD_ON) && (PROG_SECURITY_ENABLE == STD_ON))
void PROG_Do_GetSeed(void)
{
#if (PROG_USE_SA_WITH_CRYPTO == STD_ON)
    tSaStatus eSaStatus;
    ICOV(2004);DBG_PROG_DO_GETSEED_ENTRY();
#if(PROG_SA_AUTHENTICATION_METHOD == PROG_SA_AUTHENTICATION_0001 )
    /*SA AM0001 Processing*/
    SA_AuthMethod0001();
#endif
    eSaStatus = SA_GetStatus();
    if ((SA_E_OK == eSaStatus)?BCOV(2005):!BCOV(2006))
    {
        /*Send positive response*/
        m_stDiagMessageInfo.ulLength = PROG_SA_SEED_LEN + 2U;
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,m_stDiagMessageInfo.pubTxData, UDS_ACK);
        /* Emit event PROG_EVENT_FINISHED */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
    }
#if (PROG_ANTISCANNING_ENABLED == STD_ON)
    else if((SA_E_NOK_AS_LOCKED == eSaStatus)?BCOV(2007):!BCOV(2008))
    {
        /*SA Anti-scanning Locked, send negative response*/
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,m_stDiagMessageInfo.pubTxData, UDS_NRC_37);
        /* Emit event PROG_EVENT_UNLOCK_FAILED */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED);
    }
#endif /*(PROG_ANTISCANNING_ENABLED == STD_ON)*/
    else if((SA_E_NOT_OK == eSaStatus)?BCOV(2009):!BCOV(2010))
    {
        /*Crypto configuration problem, send negative response (FailurePreventsExecutionOfRequestedAction)*/
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,m_stDiagMessageInfo.pubTxData, UDS_NRC_26);
    }
#if(PROG_SA_AUTHENTICATION_METHOD == PROG_SA_AUTHENTICATION_0001 )
    else if((SA_AM0001_PROCESSING_FAILED == eSaStatus)?BCOV(2011):!BCOV(2012))
    {
        /*Failure during SA AM0001 SA1 processing, send negative response (Request Out Of Range)*/
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,m_stDiagMessageInfo.pubTxData, UDS_NRC_31);

        /* Emit event PROG_EVENT_UNLOCK_FAILED to stay out of SA1 GetSeed State*/
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED);
    }
#endif
    else /* (SA_E_BUSY == eSaStatus)*/
    {
        /*Do nothing (waiting for an answer from SA)*/
    }

    DBG_PROG_DO_GETSEED_EXIT();
#endif /* (PROG_USE_SA_WITH_CRYPTO == STD_ON) */
ICOV(2004);}
#endif /* (PROG_SA_SEED_ENABLE == STD_ON) && (PROG_SECURITY_ENABLE == STD_ON) */
/*-------------------------{end PROG_Do_GetSeed}------------------------------*/

#if (PROG_LIMIT_NB_REQUEST_SEED_ENABLED ==STD_ON)
/*---------------------------{PROG_SetRequestSeedCounter}-----------------------------*/
void PROG_SetRequestSeedCounter(u8 ubRequestSeedCounter)
{
    ICOV(2013);DBG_PROG_SETREQUESTSEEDCOUNTER_ENTRY(ubRequestSeedCounter);
    m_stLimitReqSeed.ubRequestCounter = ubRequestSeedCounter;
    DBG_PROG_SETREQUESTSEEDCOUNTER_EXIT();
}
/*-------------------------{end SetRequestSeedCounter}---------------------------*/
/*-------------------------{PROG_GetRequestSeedCounter}-------------------------------*/
u8 PROG_GetRequestSeedCounter(void)
{
    u8 ubReqSeedCter;

    ICOV(2014);DBG_PROG_GETREQUESTSEEDCOUNTER_ENTRY();
    ubReqSeedCter = m_stLimitReqSeed.ubRequestCounter;
    DBG_PROG_GETREQUESTSEEDCOUNTER_EXIT(ubReqSeedCter);

    return ubReqSeedCter;

}
/*-----------------------{end PROG_GetRequestSeedCounter}-----------------------------*/
/*---------------------------{PROG_SetRequestSeedTimer}-----------------------------*/
void PROG_SetRequestSeedTimer(u32 ulRequestSeedTimer)
{
    ICOV(2015);DBG_PROG_SETREQUESTSEEDTIMER_ENTRY(ulRequestSeedTimer);
    m_stLimitReqSeed.ulTimer = ulRequestSeedTimer;
    DBG_PROG_SETREQUESTSEEDTIMER_EXIT();
}
/*-------------------------{end SetRequestSeedTimer}---------------------------*/
/*-------------------------{PROG_GetRequestSeedTimer}-------------------------------*/
u32 PROG_GetRequestSeedTimer(void)
{
    u32 ulReqSeedTimer;

    ICOV(2016);DBG_PROG_GETREQUESTSEEDTIMER_ENTRY();
    ulReqSeedTimer = m_stLimitReqSeed.ulTimer;
    DBG_PROG_GETREQUESTSEEDTIMER_EXIT(ulReqSeedTimer);

    return ulReqSeedTimer;

}
/*-----------------------{end PROG_GetRequestSeedTimer}-----------------------------*/
#endif /* if PROG_LIMIT_NB_REQUEST_SEED_ENABLED ==STD_ON */

/*-------------------------{PROG_GetSeed_Unlocked}-------------------------------*/
#if (PROG_SA_SEED_ENABLE == STD_ON)
void PROG_GetSeed_Unlocked(void)
{
#if (PROG_LIMIT_NB_REQUEST_SEED_ENABLED ==STD_ON)
    u8 RequestSeedCounter;
    u32 RequestSeedTimer;
#endif /*(PROG_LIMIT_NB_REQUEST_SEED_ENABLED ==STD_ON)*/
    u8 LoopIndex;
    ICOV(2017);DBG_PROG_GETSEED_UNLOCKED_ENTRY();

    /*Provide 0 as seed value*/
    for (LoopIndex = 0; (LoopIndex < PROG_SA_SEED_LEN)?BCOV(2018):!BCOV(2019); LoopIndex++)
    {
        m_stDiagMessageInfo.pubTxData[2 + LoopIndex] = 0U;
    }

#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
    /* Information ECU is unlocked */
    m_ubIsLocked = 0x00;
#endif
    m_stDiagMessageInfo.ulLength = PROG_SA_SEED_LEN + 2U;
#if (PROG_LIMIT_NB_REQUEST_SEED_ENABLED ==STD_ON)
    RequestSeedTimer = PROG_GetRequestSeedTimer();
    RequestSeedCounter = PROG_GetRequestSeedCounter();
    if ((RequestSeedCounter < SA_RS_LIMIT_COUNTER)?BCOV(2020):!BCOV(2021))
    {
        /* Request seed is the first one*/
        if ((RequestSeedCounter == 0U)?BCOV(2022):!BCOV(2023))
        {
            /*Resert Timer*/
          RequestSeedTimer = SA_RS_LIMIT_TIMER;
          PROG_SetRequestSeedTimer(RequestSeedTimer);
        }
        /*Send positive response*/
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
                m_stDiagMessageInfo.pubTxData, UDS_ACK);
    }
    else
    {
        /*SA request seed limit reached, send negative response)*/
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, UDS_NRC_22);
    }
    /*Increment Request Seed Counter*/
    RequestSeedCounter ++;
    PROG_SetRequestSeedCounter(RequestSeedCounter);
#else
    /*Send positive response*/
    UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
            m_stDiagMessageInfo.pubTxData, UDS_ACK);
#endif /*(SA_LIMIT_NB_REQUEST_SEED_ENABLED == STD_ON)*/

    DBG_PROG_GETSEED_UNLOCKED_EXIT();
}
#endif /* if PROG_SA_SEED_ENABLE == STD_ON */
/*-----------------------{end PROG_GetSeed_Unlocked}-----------------------------*/

/*-------------------------{PROG_Entry_CompareKeyCheck}-------------------------------*/
#if (PROG_SA_KEY_ENABLE == STD_ON)
void PROG_Entry_CompareKeyCheck(void)
{
    ICOV(2024);DBG_PROG_ENTRY_COMPAREKEYCHECK_ENTRY();

#if PROG_NRC78_ON_SA_ENABLE == STD_ON
    /*Send NRC78 response*/
    PROG_SendNRC78();
#else
    /*Simulate Tx confirmation*/
    /*Emit event PROG_EVENT_TX_CONF)*/
    PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF);
#endif

    DBG_PROG_ENTRY_COMPAREKEYCHECK_EXIT();
}
#endif /* (PROG_SA_KEY_ENABLE == STD_ON) */
/*-----------------------{end PROG_Entry_CompareKeyCheck}-----------------------------*/

/*-------------------------{PROG_Entry_CompareKey}-------------------------------*/
#if (PROG_SA_KEY_ENABLE == STD_ON)
void PROG_Entry_CompareKey(void)
{
#if (PROG_IMPL_VARIANT == PROG_IMPL_80) && (PROG_BYPASS_SA_COMPARE_KEY == STD_OFF)
    /* Declare the buffer that will contain the Key Appli*/
    u16 aubKeyAppli;
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_80) && (PROG_BYPASS_SA_COMPARE_KEY == STD_OFF) */
    tSaStatus eSaStatus;
    u8 ubSecurityLevel;
#if (PROG_LIMIT_NB_REQUEST_SEED_ENABLED)
    u8 RequestSeedCounter;
    u32 RequestSeedTimer;
#endif /*(PROG_LIMIT_NB_REQUEST_SEED_ENABLED)*/
#if ((PROG_DECOMP_FLASH_ROUTINES == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_60))
    tProgStatus eProgStatus;
#endif
    ICOV(2025);DBG_PROG_ENTRY_COMPAREKEY_ENTRY();

#if (PROG_BYPASS_SA_COMPARE_KEY == STD_ON)
    /* Bypass the SA compare key */
    eSaStatus = SA_E_OK;
#elif(PROG_SA_AUTHENTICATION_METHOD == PROG_SA_AUTHENTICATION_0001 )
    /* Request SA module to verify the received key */
    eSaStatus = SA_CompareKey(&m_stDiagMessageInfo.pubData[0U]);
#else
#if (PROG_IMPL_VARIANT == PROG_IMPL_80)
    /* Read the Key Appli from NVM */
    (void) PROG_CustomReadKeyAppli(&aubKeyAppli);
    /* Check if we are not in development mode */
    if(( PROG_IMPL80_DEFAULT_APPLI_KEY != aubKeyAppli )?BCOV(2026):!BCOV(2027))
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_80) */
    {
        /* Request SA module to verify the received key */
        eSaStatus = SA_CompareKey(&m_stDiagMessageInfo.pubData[2U]);
    }
#if (PROG_IMPL_VARIANT == PROG_IMPL_80)
    else
    {
        /* Set status to Ok */
        eSaStatus = SA_E_OK;
    }
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_80) */
#endif /* (PROG_BYPASS_SA_COMPARE_KEY == STD_ON) */

    if ((SA_E_OK == eSaStatus)?BCOV(2028):!BCOV(2029))
    {
        /*Set new security level (mask the SuppressPositiveResponseBit) */
        ubSecurityLevel = ((m_stDiagMessageInfo.pubData[1U] & 0x7FU) / 2U);
        PROG_SetSecurityLevel(ubSecurityLevel);
#if ((PROG_DECOMP_FLASH_ROUTINES == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_60))
        /* Decompress Flash driver routine */
        eProgStatus = PROG_Drv_DecompressFlashRoutines();

        if ((PROG_E_OK == eProgStatus)?BCOV(2030):!BCOV(2031))
        {
            /* Mention the Flash Driver Routines are present in RAM */
            PROG_DrvDown_SetFlashRoutinesPresence(PROG_TRUE);
        }
        /* Decompression of Flash driver routines in RAM has failed */
        else
        {
            /* Clear Flash driver routines in RAM and mention that */
            /* Flash Driver Routines are no more present */
            (void)PROG_Drv_ClearFlashRoutines();
        }

#endif
        /*Positive response shall be sent*/
        m_stDiagMessageInfo.ulLength = PROG_COMPARE_KEY_RESPONSE_SIZE;
#if (PROG_IMPL_VARIANT == PROG_IMPL_30)
        /*Set the Programming status: Good SA*/
        PROG_SetProgrammingStatus(PROG_SA_VERIFY, PROG_TRUE);
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_30) */
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
            m_stDiagMessageInfo.pubTxData, UDS_ACK);
#if (PROG_LIMIT_NB_REQUEST_SEED_ENABLED)
        /* Reset request seed counter and Timer*/
        RequestSeedCounter = 0U;
        PROG_SetRequestSeedCounter(RequestSeedCounter);
        RequestSeedTimer = 0U;
        PROG_SetRequestSeedTimer(RequestSeedTimer);
#endif /*(PROG_LIMIT_NB_REQUEST_SEED_ENABLED)*/
        /* Emit event PROG_EVENT_FINISHED */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
    }
#if (PROG_ANTISCANNING_ENABLED == STD_ON)
    else if ((SA_E_NOK_AS_LOCKED == eSaStatus)?BCOV(2032):!BCOV(2033))
    {
        /* Wrong key has been provided, SA anti-scanning locked, negative response shall be sent */

        /* Emit event PROG_EVENT_UNCLOCK_FAILED */
        PROG_HsmEmit(&PROG_HsmScPROG,
                PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED);
    /*Send response*/
        m_stDiagMessageInfo.ulLength = PROG_NRC_SIZE;
#if (PROG_IMPL_VARIANT == PROG_IMPL_30)
        /*Set the Programming status: Wrong SA*/
        PROG_SetProgrammingStatus(PROG_SA_VERIFY, PROG_FALSE);
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_30) */
#if (PROG_IMPL_VARIANT == PROG_IMPL_80)
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
        m_stDiagMessageInfo.pubTxData, UDS_NRC_35);
#else
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
        m_stDiagMessageInfo.pubTxData, UDS_NRC_36);
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_80) */
    }
#endif /*(PROG_ANTISCANNING_ENABLED == STD_ON)*/
#if (PROG_USE_SA_WITH_CRYPTO == STD_ON)
    else if ((SA_E_BUSY == eSaStatus)?BCOV(2034):!BCOV(2035))
    {
        /*Do nothing (waiting for an answer from SA)*/
    }
#endif /*(PROG_USE_SA_WITH_CRYPTO == STD_ON)*/
#if(PROG_SA_AUTHENTICATION_METHOD == PROG_SA_AUTHENTICATION_0001 )
    else if((SA_SA2AWATINGTIME_EXPIRED == eSaStatus)?BCOV(2036):!BCOV(2037))
    {
        /*Send response*/
        m_stDiagMessageInfo.ulLength = PROG_NRC_SIZE;

        /* Emit event PROG_EVENT_UNCLOCK_FAILED to allow next SA1 reception*/
        PROG_HsmEmit(&PROG_HsmScPROG,
                PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED);

        /*SA2 not received in the given SA2 wait time post SA1 response*/
        /*send negative response (Conditions Not correct)*/
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,m_stDiagMessageInfo.pubTxData, UDS_NRC_22);
    }
#endif
    else /* SA_E_NOK_INVALID_KEY == eSaStatus */
    {
        /* Wrong key has been provided, negative response shall be sent */

        /* Emit event PROG_EVENT_UNCLOCK_FAILED */
        PROG_HsmEmit(&PROG_HsmScPROG,
                PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED);

        /*Send response*/
        m_stDiagMessageInfo.ulLength = PROG_NRC_SIZE;
#if (PROG_IMPL_VARIANT == PROG_IMPL_30)
        /*Set the Programming status: Wrong SA*/
        PROG_SetProgrammingStatus(PROG_SA_VERIFY, PROG_FALSE);
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_30) */
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
            m_stDiagMessageInfo.pubTxData, UDS_NRC_35);
    }
    DBG_PROG_ENTRY_COMPAREKEY_EXIT();
}
#endif /* (PROG_SA_KEY_ENABLE == STD_ON) */
/*-----------------------{end PROG_Entry_CompareKey}-----------------------------*/

/*-------------------------{PROG_Do_CompareKey}-------------------------------*/
#if(PROG_SA_KEY_ENABLE == STD_ON)
void PROG_Do_CompareKey(void)
{
#if (PROG_USE_SA_WITH_CRYPTO == STD_ON)
#if (PROG_LIMIT_NB_REQUEST_SEED_ENABLED)
    u8 RequestSeedCounter;
    u32 RequestSeedTimer;
#endif /*(PROG_LIMIT_NB_REQUEST_SEED_ENABLED)*/
    tSaStatus eSaStatus;
    u8 ubSecurityLevel;
#if (PROG_DECOMP_FLASH_ROUTINES == STD_ON)
    tProgStatus eProgStatus;
#endif
    ICOV(2038);DBG_PROG_DO_COMPAREKEY_ENTRY();
#if(PROG_SA_AUTHENTICATION_METHOD == PROG_SA_AUTHENTICATION_0001 )
    /*AM0001 Processing*/
    SA_AuthMethod0001();
#endif
    eSaStatus = SA_GetStatus();
    if ((SA_E_OK == eSaStatus)?BCOV(2039):!BCOV(2040))
    {
        /*Set new security level (mask the SuppressPositiveResponseBit) */
        ubSecurityLevel = ((m_stDiagMessageInfo.pubData[1U] & 0x7FU) / 2U);
        PROG_SetSecurityLevel(ubSecurityLevel);

#if (PROG_DECOMP_FLASH_ROUTINES == STD_ON)
        /* Decompress Flash driver routine */
        eProgStatus = PROG_Drv_DecompressFlashRoutines();

        if ((PROG_E_OK == eProgStatus)?BCOV(2041):!BCOV(2042))
        {
            /* Mention the Flash Driver Routines are present in RAM */
            PROG_DrvDown_SetFlashRoutinesPresence(PROG_TRUE);
        }
        /* Decompression of Flash driver routines in RAM has failed */
        else
        {
            /* Clear Flash driver routines in RAM and mention that */
            /* Flash Driver Routines are no more present */
            (void)PROG_Drv_ClearFlashRoutines();
        }
#endif
        /* Positive response shall be sent */
        m_stDiagMessageInfo.ulLength = PROG_COMPARE_KEY_RESPONSE_SIZE;

        /* Send response */
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, UDS_ACK);
#if (PROG_LIMIT_NB_REQUEST_SEED_ENABLED)
        /* Reset request seed counter and Timer */
        RequestSeedCounter = 0U;
        PROG_SetRequestSeedCounter(RequestSeedCounter);
        RequestSeedTimer = 0U;
        PROG_SetRequestSeedTimer(RequestSeedTimer);
#endif /*(PROG_LIMIT_NB_REQUEST_SEED_ENABLED)*/
        /* Emit event PROG_EVENT_FINISHED */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
    }
#if (PROG_ANTISCANNING_ENABLED == STD_ON)
    else if ((SA_E_NOK_AS_LOCKED == eSaStatus)?BCOV(2043):!BCOV(2044))
    {
        /* Wrong key has been provided, SA anti-scanning locked, negative response shall be sent */

        /* Emit event PROG_EVENT_UNCLOCK_FAILED */
        PROG_HsmEmit(&PROG_HsmScPROG,
                PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED);
    /*Send response*/
        m_stDiagMessageInfo.ulLength = PROG_NRC_SIZE;

    UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
            m_stDiagMessageInfo.pubTxData, UDS_NRC_36);
    }
#endif /*(PROG_ANTISCANNING_ENABLED == STD_ON)*/
    else if ((SA_E_BUSY == eSaStatus)?BCOV(2045):!BCOV(2046))
    {
        /*Do nothing (waiting for an answer from SA)*/
    }
    else /* SA_E_NOK_INVALID_KEY == eSaStatus */
    {
        /* Wrong key has been provided, negative response shall be sent */

        /* Emit event PROG_EVENT_UNCLOCK_FAILED */
        PROG_HsmEmit(&PROG_HsmScPROG,
                PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED);

        /*Send response*/
        m_stDiagMessageInfo.ulLength = PROG_NRC_SIZE;

        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
            m_stDiagMessageInfo.pubTxData, UDS_NRC_35);
    }
    DBG_PROG_DO_COMPAREKEY_EXIT();
#endif /* (PROG_USE_SA_WITH_CRYPTO == STD_ON) */
ICOV(2038);}
#endif /* ((PROG_SA_KEY_ENABLE == STD_ON) */
/*-----------------------{end PROG_Do_CompareKey}-----------------------------*/

#if PROG_SECURITY_ENABLE == STD_ON
/*-------------------------{PROG_GetSecurityLevel}-------------------------------*/
u8 PROG_GetSecurityLevel(void)
{
    u8 ubSecLev;

    ICOV(2047);DBG_PROG_GETSECURITYLEVEL_ENTRY();
    ubSecLev = m_ubProgSecurityLevel;
    DBG_PROG_GETSECURITYLEVEL_EXIT(ubSecLev);

    return ubSecLev;

}
/*-----------------------{end PROG_GetSecurityLevel}-----------------------------*/
#endif /* if PROG_SECURITY_ENABLE == STD_ON */


/*-------------------------{PROG_Entry_EraseCheck}-------------------------------*/
void PROG_Entry_EraseCheck(void)
{
#if (PROG_ERASE_MEMORY_ENABLE == STD_ON)
    tProgStatus eProgStatus;
    tUdsStatus eUdsStatus;
#if (PROG_IMPL_VARIANT != PROG_IMPL_80)
    u8 ubBlockId;
#endif /* (PROG_IMPL_VARIANT != PROG_IMPL_80) */
#if (PROG_ERASE_CHECK_TYPE == PROG_1ST_PROGRAMMING_ERASE_CHECK)
    /* This variable is used to tell if this is the first ECU programming. */
    /* When TRUE the memory is considered already erased and the erase action is skipped.*/
    tProgBoolean ubIsFirstProgramming;
#endif

    ICOV(2048);DBG_PROG_ENTRY_ERASECHECK_ENTRY();

#if (PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON)
    /* Reset the sector erase counters */
    m_ubNbSectEraseCnt = 0U;
#endif
#if (PROG_ERASE_ALL == STD_OFF)
#if (PROG_IMPL_VARIANT == PROG_IMPL_80)
    eUdsStatus = PROG_ControlEraseParameters_Impl80(
                &m_stDiagMessageInfo.ulLength,
                &m_stDiagMessageInfo.pubData[0]);
#else
    /* Extract address and size of data to be erased */
    eProgStatus = PROG_ExtractEraseParameters(
                &m_stDiagMessageInfo.pubData[PROG_ERASE_REQUEST_DATA],
                &m_stCurrentSegment, &eUdsStatus, &ubBlockId);
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_80) */
#else
    /* Extract address and size of data to be erased */
    (void) PROG_ExtractEraseParameters(
                    &m_stDiagMessageInfo.pubData[PROG_ERASE_REQUEST_DATA],
                    &m_stCurrentSegment, &eUdsStatus, &ubBlockId);
#endif /* (PROG_ERASE_ALL == STD_OFF) */

#if (PROG_IMPL_VARIANT == PROG_IMPL_80)
    if((UDS_ACK == eUdsStatus)?BCOV(2049):!BCOV(2050))
    {
        eProgStatus = PROG_EraseFirstCheck_Impl80();
        if ((PROG_E_BYPASS == eProgStatus)?BCOV(2051):!BCOV(2052))
        {
            /* No erase to perform areas are blank. Update status to success */
            PROG_UpdateRequestRoutineResult_Impl80(m_uwRoutineId, PROG_REQUEST_ROUTINE_RESULT_SUCCESS);
        }
        else
        {
             /* Do nothing */
        }
    }
    else
    {
        eProgStatus = PROG_E_NOT_OK;
    }
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_80) */

#if (PROG_ERASE_CHECK_TYPE == PROG_1ST_PROGRAMMING_ERASE_CHECK)
    /* Check if is the first ECU programming */
    ubIsFirstProgramming = PROG_CustomIsFirstProgramming();
    if (((PROG_TRUE == ubIsFirstProgramming) && (PROG_E_NOT_OK != eProgStatus))?BCOV(2053):!BCOV(2054))
    {
        /*no need to erase the memory, bypass and send positive response*/
#if (PROG_IMPL_VARIANT == PROG_IMPL_60)
        /* Allow integration code to manage the response */
        PROG_Custom_EraseRoutine_Succeed (m_stDiagMessageInfo.pubTxData, &m_stDiagMessageInfo.ulLength);
#endif

        /* Send positive response */
#if ((PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_2) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
        m_stDiagMessageInfo.pubTxData[4] = (u8)(PROG_ROUTINE_SELFTERM | PROG_ROUTINE_PREDIF | PROG_ROUTINE_RESAVAILABLE);
#if (PROG_HASH_CALCULATION == STD_ON)
        /* Call crypto library to start the hash computation */
        (void)PROG_ComputeHashStart(PROG_CSM_HASH_FOR_SIGNATURE_ID,NULL_PTR,0U,NULL_PTR);
#endif
#else
        m_stDiagMessageInfo.pubTxData[4] = (u8)(PROG_ROUTINE_FINISHED_OK | PROG_ROUTINE_TYPE_1);
#endif
        m_stDiagMessageInfo.ulLength = PROG_ERASE_POS_RESPONSE_SIZE;

        /* Positive response for Routine type 1 */
        PROG_HsmEmit(&PROG_HsmScPROG,PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);

        /* return status OK*/
        UDS_LongRequestEnd(PROG_ERASE_POS_RESPONSE_SIZE,m_stDiagMessageInfo.pubTxData, UDS_ACK);

        /*Set the status to BYPASS to skip the erase*/
        eProgStatus = PROG_E_BYPASS;
    }
    else
    {
        /*continue the checks for erase*/
    }
#endif /*(PROG_ERASE_CHECK_TYPE == PROG_1ST_PROGRAMMING_ERASE_CHECK)*/

#if (PROG_ERASE_ALL == STD_OFF)
    if ((PROG_E_NOT_OK == eProgStatus)?BCOV(2055):!BCOV(2056))
    {
#if (PROG_IMPL_VARIANT == PROG_IMPL_60)
        /* Allow integration code to manage the response */
        PROG_Custom_EraseRoutine_Failed(m_stDiagMessageInfo.pubTxData,&m_stDiagMessageInfo.ulLength,&eUdsStatus);
#endif

        /* Erase parameters from request are not correct */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);

#if (PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)
        /* Wrong Erase address/size, update ProgrammingStatus */
        PROG_SetProgrammingStatus( PROG_RC_ERASE_ADDRESS, PROG_FALSE);
        PROG_SetProgrammingStatus( PROG_RC_ERASE_SIZE,    PROG_FALSE);
#endif  /* (PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON) */

        /* Send negative response */
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, eUdsStatus);

    } /* if ( PROG_E_NOT_OK == eProgStatus) */
    else if ((PROG_E_BYPASS == eProgStatus)?BCOV(2057):!BCOV(2058))
    {
#if ((PROG_ERASE_CHECK_TYPE != PROG_DISABLED_ERASE_CHECK) && (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID))
#if ((PROG_SEG_LIST_CKS == STD_ON) && (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID))
        /* reset Logical block Id for download verification*/
        m_stDataProgVerification.ubLogicalBlockId = 0U;
#endif
#if(PROG_SEG_LIST_CKS == STD_ON)
        /*Init Segment list for CRC calculation */
        m_stSegList.ubSegNbr = 0;
#endif /*(PROG_SEG_LIST_CKS == STD_ON)*/

#if ((PROG_VERIFICATION_ON_THE_FLY == STD_ON) && (PROG_CRY_PRESENT == STD_ON))
#if ((PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_SIGNATURE_CALCULATION_OVER_HASH == STD_OFF) && (PROG_IMPL_VARIANT != PROG_IMPL_31))
/* Call crypto library to start the signature verification */
        (void)PROG_VerifySignatureStart
        (
            &m_stProgAsymPublicKey,
            NULL_PTR
        );
#if ((PROG_SEG_LIST_CKS == STD_ON) && (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID))
        m_stDataProgVerification.ubLogicalBlockId = m_stCurrentSegment.ubLogicalBlockId;
#endif
#endif /* #if ((PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_SIGNATURE_CALCULATION_OVER_HASH == STD_OFF)) */
#if (PROG_HASH_CALCULATION == STD_ON)
/* Call crypto library to start the hash computation */
        (void)PROG_ComputeHashStart(PROG_CSM_HASH_FOR_SIGNATURE_ID,NULL_PTR,0U,NULL_PTR);
#if ((PROG_SEG_LIST_CKS == STD_ON) && (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID))
        m_stDataProgVerification.ubLogicalBlockId = m_stCurrentSegment.ubLogicalBlockId;
#endif
#endif /* #if (PROG_HASH_CALCULATION == STD_ON) */

#endif /* #if ((PROG_VERIFICATION_ON_THE_FLY == STD_ON) && (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID)) */



        /*Send positive response*/
#if (PROG_IMPL_VARIANT == PROG_IMPL_60)
        /* Allow integration code to manage the response */
        PROG_Custom_EraseRoutine_Succeed(m_stDiagMessageInfo.pubTxData,&m_stDiagMessageInfo.ulLength);
#elif (PROG_IMPL_VARIANT == PROG_IMPL_50)
        m_stDiagMessageInfo.pubData[PROG_RC_ROUTINE_INFO_BASE_INDEX]             = (u8)PROG_ROUTINE_FINISHED_OK; /* routineInfo : Routine successfully completed */
        m_stDiagMessageInfo.pubData[PROG_RC_STATUS_RECORD_ERASEVERIF_BASE_INDEX] = (u8)PROG_RC_STATUS_RECORD_ERASEVERIF_OK; /* routineStatusRecord : Erase completed successfully */
        m_stDiagMessageInfo.ulLength = PROG_ERASE_POS_RESPONSE_SIZE;
#elif (PROG_IMPL_VARIANT == PROG_IMPL_80)
        m_stDiagMessageInfo.pubData[4] = (u8)PROG_REQUEST_ROUTINE_RESULT_SUCCESS;
        m_stDiagMessageInfo.ulLength = PROG_ERASE_POS_RESPONSE_SIZE;
#elif (PROG_IMPL_VARIANT != PROG_IMPL_80)
        m_stDiagMessageInfo.pubData[4] = (u8)PROG_ROUTINE_FINISHED_OK;
        m_stDiagMessageInfo.ulLength = PROG_ERASE_POS_RESPONSE_SIZE;
#endif

        /* Erase not needed, send Finished event */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED); /*Status has already been provided in eUdsStatus*/

        UDS_LongRequestEnd(PROG_ERASE_POS_RESPONSE_SIZE, m_stDiagMessageInfo.pubTxData, UDS_ACK);
#endif  /*((PROG_ERASE_CHECK_TYPE != PROG_DISABLED_ERASE_CHECK) && (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID))*/
    } /* if ( PROG_E_BYPASS == eProgStatus) */
    else
#endif /*if (PROG_ERASE_ALL == STD_OFF)*/
    {
#if PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR
        /* Call a callback if some checks must be done before the erasing */
        eProgStatus = PROG_MemStartErasing(m_stCurrentSegment.ulStartAddress, m_stCurrentSegment.ulSize, &eUdsStatus);
#elif PROG_ERASE_TYPE == PROG_ERASE_BY_DYNAMIC_PARTITION_ID
#if (PROG_HSM_UPDATE_ENABLE == STD_ON)
        if ((m_stDiagMessageInfo.pubData[PROG_ERASE_REQUEST_DATA] == PROG_HSM_PARTITION_ID)?BCOV(2059):!BCOV(2060))
        {
            /* Call the API PROG_HSMRequestUpdate to read the HSM update request status */
            eProgStatus = PROG_HSMRequestUpdate();

            if ((PROG_E_OK == eProgStatus)?BCOV(2061):!BCOV(2062))
            {
                eUdsStatus = UDS_ACK;
                m_stDiagMessageInfo.ulLength = PROG_ERASE_POS_RESPONSE_SIZE;
            }
            else
            {
                m_uwPEC = PROG_ERR_PER_DATA_TX_NOT_ALLOW;
                eUdsStatus = UDS_NRC_33;
            }

            /* Emit Event PROG_HSM_PROG_EV_PROG_EVENT_FINISHED */
            PROG_HsmEmit(&PROG_HsmScPROG,PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);

            /* Send response */
            UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,m_stDiagMessageInfo.pubTxData, eUdsStatus);
        }
        else
#endif
        {
            /* Call a callback if some checks must be done before the erasing */
            eProgStatus = PROG_MemStartErasing(m_stDiagMessageInfo.pubData[PROG_ERASE_REQUEST_DATA],&eUdsStatus);
        }
#elif PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID
#if (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON)
        /* Check the downgrade protection for erase */
        eProgStatus = PROG_DowngradeProtection_CheckForEraseAndRD_Impl40(ubBlockId);
        if ((PROG_E_OK == eProgStatus)?BCOV(2063):!BCOV(2064))
#endif /* (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON) */
        {
#if (PROG_IMPL_VARIANT != PROG_IMPL_80)
            /* Call a callback if some checks must be done before the erasing */
            eProgStatus = PROG_MemStartErasing(ubBlockId,&eUdsStatus);
#endif
        }
#endif
        if ((PROG_E_NOT_OK == eProgStatus)?BCOV(2065):!BCOV(2066))
        {
            /* Erase parameters from request are not correct */
            PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
            /* Send negative response */
            UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, eUdsStatus);
            /* Error Code has already been provided in eUdsStatus */
        }
#if (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON)
        else if ((PROG_E_RFS_DRIVER_FAIL == eProgStatus)?BCOV(2067):!BCOV(2068))
        {
            /* Missing RFS driver, send finish event */
            PROG_HsmEmit(&PROG_HsmScPROG,
                    PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
            m_stDiagMessageInfo.pubData[PROG_RC_ROUTINE_INFO_BASE_INDEX] = (u8)PROG_ROUTINE_RFS_DRV_INVALID_OR_MISSING;

            /* Send positive response with status routine 0x80 */
            UDS_LongRequestEnd(PROG_ERASE_POS_RESPONSE_SIZE,
                    m_stDiagMessageInfo.pubTxData, UDS_ACK);
        }
        else if ((PROG_E_RFS_VERSION_FAIL == eProgStatus)?BCOV(2069):!BCOV(2070))
        {
            /* Invalid RFS block ID, send finish event */
            PROG_HsmEmit(&PROG_HsmScPROG,
                    PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
            m_stDiagMessageInfo.pubData[PROG_RC_ROUTINE_INFO_BASE_INDEX] = (u8)PROG_ROUTINE_RFS_VER_OR_BID_INVALID;

            /* Send positive response with status routine 0x81 */
            UDS_LongRequestEnd(PROG_ERASE_POS_RESPONSE_SIZE,
                    m_stDiagMessageInfo.pubTxData, UDS_ACK);
        }
#endif/* #if (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON) */
        else
        {
#if ((PROG_SEG_LIST_CKS == STD_ON) && (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID))
            /* reset Logical block Id for download verification*/
            m_stDataProgVerification.ubLogicalBlockId = 0U;
#endif
#if (PROG_SEG_LIST_CKS == STD_ON)
            /* Init Segment list for CRC calculation */
            m_stSegList.ubSegNbr = 0;
#endif
#if PROG_RESUM_REPROG == STD_ON
            /* Store segment list for hash recomputation in case of resume */
            PROG_CustomStoreSegmentList(&m_stSegList);
#endif

#if ((PROG_VERIFICATION_ON_THE_FLY == STD_ON) && (PROG_CRY_PRESENT == STD_ON))
/* for profile 11, signature is calculated at check memory request in 1 step */
#if ((PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_SIGNATURE_CALCULATION_OVER_HASH == STD_OFF) && \
    (PROG_IMPL_VARIANT != PROG_IMPL_11) && (PROG_IMPL_VARIANT != PROG_IMPL_91) && (PROG_IMPL_VARIANT != PROG_IMPL_31) && \
    (PROG_IMPL_VARIANT != PROG_IMPL_4) && (PROG_IMPL_VARIANT != PROG_IMPL_5))
            /* Call crypto library to start the signature verification */
            (void)PROG_VerifySignatureStart
            (
                &m_stProgAsymPublicKey,
                NULL_PTR
            );
#if ((PROG_SEG_LIST_CKS == STD_ON) && (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID))
            m_stDataProgVerification.ubLogicalBlockId = m_stCurrentSegment.ubLogicalBlockId;
#endif
#endif

/* Exclude profile 11 because the hash computation is started when the VBT is downloaded */
#if ((PROG_HASH_CALCULATION == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_11) && (PROG_IMPL_VARIANT != PROG_IMPL_91))
            /* Call crypto library to start the hash computation */
            (void)PROG_ComputeHashStart(PROG_CSM_HASH_FOR_SIGNATURE_ID,NULL_PTR,0U,NULL_PTR);
#if ((PROG_SEG_LIST_CKS == STD_ON) && (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID))
            m_stDataProgVerification.ubLogicalBlockId = m_stCurrentSegment.ubLogicalBlockId;
#endif
#endif /* #if ((PROG_HASH_CALCULATION == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_11) && (PROG_IMPL_VARIANT != PROG_IMPL_91)) */

#endif /* #if ((PROG_VERIFICATION_ON_THE_FLY == STD_ON) && (PROG_CRY_PRESENT == STD_ON)) */

#if PROG_NRC78_ON_ERASE_ENABLE == STD_ON
            /* Send NRC78 response */
            PROG_SendNRC78();
#else
#if (PROG_IMPL_VARIANT == PROG_IMPL_80)
           /* Send positive response */
           UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
                m_stDiagMessageInfo.pubTxData, UDS_ACK);
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_80) */
            /* Simulate Tx confirmation */
            /* Emit event PROG_EVENT_TX_CONF) */
            PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF);
#endif
        }
    }
    DBG_PROG_ENTRY_ERASECHECK_EXIT();
#endif /* (PROG_ERASE_MEMORY_ENABLE == STD_ON) */
ICOV(2048);}
/*-----------------------{end PROG_Entry_EraseCheck}-----------------------------*/

/*----------------------------{PROG_Erase_Guard}---------------------------------*/
tProgStatus PROG_Erase_Guard(void)
{
    tProgStatus eProgStatus;

    ICOV(2071);DBG_PROG_ERASE_GUARD_ENTRY();

#if ((PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON) || (PROG_DECOMP_FLASH_ROUTINES == STD_ON))
    eProgStatus = PROG_DrvDown_VerifyTransition();

    if ((PROG_E_NOT_OK == eProgStatus)?BCOV(2072):!BCOV(2073))
    {
#if (PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON)
        /* Transition is rejected, negative response shall be sent */
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
                m_stDiagMessageInfo.pubTxData, UDS_NRC_24);
#endif
#if (PROG_DECOMP_FLASH_ROUTINES == STD_ON)
        /* Transition is rejected, negative response shall be sent */
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
                m_stDiagMessageInfo.pubTxData, UDS_NRC_72);
#endif
    }
    else
    {
        /* Do nothing */
    }
#else
    eProgStatus = PROG_E_OK;
#endif

    DBG_PROG_ERASE_GUARD_EXIT(eProgStatus);
    return eProgStatus;
}
/*-----------------------{end PROG_Erase_Guard}-----------------------------*/

#if (PROG_IMPL_VARIANT == PROG_IMPL_40)
/*----------------------------{PROG_Guard_Erase_Check_EraseFinish}---------------------------------*/
tProgStatus PROG_Guard_Erase_Check_EraseFinish(void)
{

    /*Define local Context*/
    tProgStatus eProgStatus;
    u8 ubBlockId;

    ICOV(2074);DBG_PROG_GUARD_ERASE_CHECK_ERASEFINISH_ENTRY();

    /* Extract Block ID of data to be erased */
    eProgStatus = PROG_Erase_ExtractBlockID(
                &m_stDiagMessageInfo.pubData[PROG_ERASE_REQUEST_DATA],
                &ubBlockId);

    if (((PROG_E_NOT_OK == eProgStatus) || (ubBlockId != m_stCurrentSegment.ubLogicalBlockId))?BCOV(2075):!BCOV(2076))
    {

        /* Repeated Erase for different block or invalid request : Send negative response */
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, UDS_NRC_24);

        /* Return status NOT_OK */
        eProgStatus = PROG_E_NOT_OK;
    }
    else
    {

        /* Return status OK (Further processing by PROG_Entry_EraseCheck)*/
        eProgStatus = PROG_E_OK;

    }

    DBG_PROG_GUARD_ERASE_CHECK_ERASEFINISH_EXIT(eProgStatus);

    return eProgStatus;
}
/*-----------------------{end PROG_Guard_Erase_Check_EraseFinish}-----------------------------*/

/*----------------------------{PROG_Erase_ExtractBlockID}---------------------------------*/
NCS_PRI_FCT tProgStatus PROG_Erase_ExtractBlockID(const u8 * pubUdsData, u8 * pubBlockId)
{

    /*Define local Context*/
    tProgStatus eProgStatus;
    u8 ubBlockIdLength;
    u8 ubLoopIndex;
    u16 uwBlockIdent = 0U;
    tProgStatus eIndexFound = PROG_E_NOT_OK;

    ICOV(2077);DBG_PROG_ERASE_EXTRACTBLOCKID_ENTRY(pubUdsData, pubBlockId);

    /* Initialize the Transition to refused */
    eProgStatus = PROG_E_NOT_OK;

    /* Retrieve AddressAndLengthFormatIdenfier */
    ubBlockIdLength = (u8)(pubUdsData[0] & (u8)0x0F);

    /* Check ALFID is correct */
    if (((PROG_MAX_BYTE_ERASE_BLOCK_LENGTH >= ubBlockIdLength) && (0U < ubBlockIdLength))?BCOV(2078):!BCOV(2079))
    {
        /* Check if enough data are received */
        if ((ubBlockIdLength <= (m_stDiagMessageInfo.ulLength - 5U))?BCOV(2080):!BCOV(2081))
        {
            /* Retrieve BlockId */
            for (ubLoopIndex = 0U; (ubLoopIndex < ubBlockIdLength)?BCOV(2082):!BCOV(2083); ubLoopIndex++)
            {
                uwBlockIdent |= (uint16) ( (uint16)(pubUdsData[ubLoopIndex + 1U]) <<  (uint8)(((ubBlockIdLength - 1U - ubLoopIndex) * 8U)));
            }

            /* Find the index table from block identifier */
            eIndexFound = PROG_FindBlockIndexInTable(uwBlockIdent, pubBlockId);

            if ((PROG_E_OK == eIndexFound)?BCOV(2084):!BCOV(2085))
            {
                eProgStatus = PROG_E_OK;
            }
            else
            {
                eProgStatus = PROG_E_NOT_OK;
            }
        }
        else
        {
            eProgStatus = PROG_E_NOT_OK;
        }
    }
    else
    {
        eProgStatus = PROG_E_NOT_OK;
    }

    DBG_PROG_ERASE_EXTRACTBLOCKID_EXIT(eProgStatus);

    return eProgStatus;
}
/*-----------------------{end PROG_Erase_ExtractBlockID}-----------------------------*/
#endif /* if PROG_IMPL_VARIANT == PROG_IMPL_40 */


/*----------------------------{PROG_Entry_Erase}---------------------------------*/
void PROG_Entry_Erase(void)
{
#if PROG_ERASE_MEMORY_ENABLE == STD_ON
    tProgStatus eProgStatus;
    u32 ulStartAddress;
    ICOV(2086);DBG_PROG_ENTRY_ERASE_ENTRY();

    /* Perform erasing of the first block */

    /* Calculate the start address                   */
    /* The Write/Erase is done with phisical address */
#if (PROG_OTA_DUALBANK_USED == STD_ON)
    ulStartAddress = PROG_CustomCalcInactiveBankWriteAddr(m_stCurrentSegment.ulStartAddress);
#else
    ulStartAddress = m_stCurrentSegment.ulStartAddress;
#endif /*(PROG_OTA_DUALBANK_USED == STD_ON)*/

    eProgStatus = PROG_MemDataAccess(
        m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,
        PROG_MEM_OPERATION_TYPE_ERASE, ulStartAddress,
        m_stCurrentSegment.ulSize, NULL_PTR);
#if ((PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
    PROG_ClearVerificationDataStructure(m_stCurrentSegment.ubSegmentId);
#endif
#if (PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON)
    /* Increment counter of number sector to erase */
    m_ubNbSectEraseCnt++;
#endif /* PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON */
#if (PROG_IMPL_VARIANT == PROG_IMPL_80)
    PROG_EraseStatusCheck_Impl80(eProgStatus);
#else
    PROG_EraseStatusCheck(eProgStatus);
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_80) */
#else
    ICOV(2087);DBG_PROG_ENTRY_ERASE_ENTRY();
#endif /* if PROG_ERASE_MEMORY_ENABLE == STD_ON */
    ICOV(2087);DBG_PROG_ENTRY_ERASE_EXIT();
}

/*--------------------------{end PROG_Entry_Erase}-------------------------------*/

/*----------------------------{PROG_Entry_EraseTransmitNRC78}----------------------------*/
void PROG_Entry_EraseTransmitNRC78(void)
{
    ICOV(2088);DBG_PROG_ENTRY_ERASETRANSMITNRC78_ENTRY();
#if PROG_NRC78_BEFORE_ERASECHECK == STD_ON
    /*Send NRC78 response*/
    PROG_SendNRC78();
#else
    /* Post Event in state machine */
    PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF);
#endif
    DBG_PROG_ENTRY_ERASETRANSMITNRC78_EXIT();
}
/*--------------------------{end PROG_Entry_EraseTransmitNRC78}--------------------------*/

/*----------------------------{PROG_Entry_EraseNRC78}----------------------------*/
void PROG_Entry_EraseNRC78(void)
{
    ICOV(2089);DBG_PROG_ENTRY_ERASENRC78_ENTRY();
#if ((PROG_FLASH_MEMORY_USE == PROG_TRUE) || (PROG_FLASH_EXT_MEMORY_USE == PROG_TRUE) || (PROG_CUSTOM_MEMORY_USE == PROG_TRUE))
#if ((PROG_ERASE_MEMORY_ENABLE == STD_ON) && (PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON))
    /*Send NRC78 response*/
    PROG_SendNRC78();
#endif
#endif
    DBG_PROG_ENTRY_ERASENRC78_EXIT();
}
/*--------------------------{end PROG_Entry_EraseNRC78}--------------------------*/

/*----------------------------{PROG_SendNRC78}----------------------------*/
void PROG_SendNRC78(void)
{
    ICOV(2090);DBG_PROG_SENDNRC78_ENTRY();
    UDS_StopNRC78Timer();
    DBG_PROG_SENDNRC78_EXIT();
}
/*--------------------------{end PROG_SendNRC78}--------------------------*/

/*-------------------------{PROG_Entry_EraseFinish}------------------------------*/
void PROG_Entry_EraseFinish(void)
{
    ICOV(2091);DBG_PROG_ENTRY_ERASEFINISH_ENTRY();
    /* Nothing to do */
    DBG_PROG_ENTRY_ERASEFINISH_EXIT();
}
/*-----------------------{end PROG_Entry_EraseFinish}----------------------------*/

#if PROG_ERASE_MEMORY_ENABLE == STD_ON
/*------------------------{PROG_EraseStatusCheck}--------------------------------*/
NCS_PRI_FCT void PROG_EraseStatusCheck(tProgStatus eProgStatus)
{
    tUdsStatus eUdsStatus;
#if ((PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON) || (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID) || (PROG_ERASE_TYPE == PROG_ERASE_BY_DYNAMIC_PARTITION_ID))
    u32 ulStartAddress;
#endif /*((PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON) || (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID)  || (PROG_ERASE_TYPE == PROG_ERASE_BY_DYNAMIC_PARTITION_ID))*/
#if (PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON)
    u32 ulNextAddress=0U;
#endif /* PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON */

    ICOV(2092);eUdsStatus = UDS_ACK;

    while(((PROG_E_OK == eProgStatus) && (m_stCurrentSegment.ubSegmentNbr >= 1U))?BCOV(2093):!BCOV(2094))
    {
#if (PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON)
        /* Perform Erase status check only if the Memory type is not RAM, as erase sector by sector operation is not meant for RAM */
        if ((PROG_MEM_TYPE_RAM!=m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType)?BCOV(2095):!BCOV(2096))
        {
            ulNextAddress = PROG_MemGetNextSectorAddr
                    (m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,
                            m_stCurrentSegment.ulStartAddress);
        }
        else
        {
            /*Nothing to Do*/
        }
        if(((ulNextAddress < (m_stCurrentSegment.ulStartAddress + m_stCurrentSegment.ulSize)) && \
           (PROG_MEM_TYPE_RAM!=m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType))?BCOV(2097):!BCOV(2098))
        {
            m_stCurrentSegment.ulSize -= ulNextAddress-m_stCurrentSegment.ulStartAddress;
            m_stCurrentSegment.ulStartAddress = ulNextAddress;

            if ((m_ubNbSectEraseCnt < PROG_NB_OF_SECTOR_TO_ERASE_BEFORE_SENDING_NRC78)?BCOV(2099):!BCOV(2100))
            {
                m_ubNbSectEraseCnt++;
                /* Perform erasing of the current block */
#if (PROG_OTA_DUALBANK_USED == STD_ON)
                ulStartAddress = PROG_CustomCalcInactiveBankWriteAddr(m_stCurrentSegment.ulStartAddress);
#else
                ulStartAddress = m_stCurrentSegment.ulStartAddress;
#endif /*(PROG_OTA_DUALBANK_USED == STD_ON)*/
                eProgStatus = PROG_MemDataAccess(
                    m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,
                    PROG_MEM_OPERATION_TYPE_ERASE, ulStartAddress,
                    m_stCurrentSegment.ulSize, NULL_PTR);
            }
            else
            {
                /* Reset counter of number sector to erase */
                m_ubNbSectEraseCnt = 0U;
                /* Emit event PROG_EVENT_WAIT_NRC78 */
                PROG_HsmEmit (&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78);

                /* Set Status to BUSY to leave the loop */
                eProgStatus = PROG_E_BUSY;
                /* Do Nothing here, execute directly RQD_PROG_Erase_037 */
            }
        }
        else
#endif /* PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON */
        {

#if PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID
            if((m_stCurrentSegment.ubSegmentNbr > 1U)?BCOV(2101):!BCOV(2102))
            {
                /* Set next segment to be erased */
                m_stCurrentSegment.ubSegmentId++;

                /* get next segment address*/
                m_stCurrentSegment.ulStartAddress =
                        stConfigSegment[m_stCurrentSegment.ubSegmentId].ulEraseStartAddress;

                /*get next segment size*/
                m_stCurrentSegment.ulSize =
                        stConfigSegment[m_stCurrentSegment.ubSegmentId].ulEraseEndAddress
                                - stConfigSegment[m_stCurrentSegment.ubSegmentId].ulEraseStartAddress;

                /* Perform erasing of the current block */

                /* Calculate the start address                   */
                /* The Write/Erase is done with physical address */
#if (PROG_OTA_DUALBANK_USED == STD_ON)
                ulStartAddress = PROG_CustomCalcInactiveBankWriteAddr(m_stCurrentSegment.ulStartAddress);
#else
                ulStartAddress = m_stCurrentSegment.ulStartAddress;
#endif /*(PROG_OTA_DUALBANK_USED == STD_ON)*/

                eProgStatus = PROG_MemDataAccess(
                    m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,
                    PROG_MEM_OPERATION_TYPE_ERASE, ulStartAddress,
                    m_stCurrentSegment.ulSize, NULL_PTR);

#if (PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON)
                m_ubNbSectEraseCnt++;
#endif
            }
/* end of PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID */
#elif PROG_ERASE_TYPE == PROG_ERASE_BY_DYNAMIC_PARTITION_ID
            if((m_stCurrentSegment.ubSegmentNbr > 1U)?BCOV(2103):!BCOV(2104))
            {
                /* get address of next region*/
                m_stCurrentSegment.pubRegionPtr = &m_stCurrentSegment.pubRegionPtr[PROG_REGION_INFO_SIZE];
                m_stCurrentSegment.ulStartAddress = (u32)((u32)((u32)m_stCurrentSegment.pubRegionPtr[0U] << 24U) & 0xFF000000U);
                m_stCurrentSegment.ulStartAddress += (u32)((u32)((u32)m_stCurrentSegment.pubRegionPtr[1U] << 16U) & 0x00FF0000U);
                m_stCurrentSegment.ulStartAddress += (u32)((u32)((u32)m_stCurrentSegment.pubRegionPtr[2U] << 8U) & 0x0000FF00U);
                m_stCurrentSegment.ulStartAddress += (u32)((u32)m_stCurrentSegment.pubRegionPtr[3U] & 0x000000FFU);

                /*get size of the next region*/
                m_stCurrentSegment.ulSize = (u32)((u32)((u32)m_stCurrentSegment.pubRegionPtr[4U] << 24U) & 0xFF000000U);
                m_stCurrentSegment.ulSize += (u32)((u32)((u32)m_stCurrentSegment.pubRegionPtr[5U] << 16U) & 0x00FF0000U);
                m_stCurrentSegment.ulSize += (u32)((u32)((u32)m_stCurrentSegment.pubRegionPtr[6U] << 8U) & 0x0000FF00U);
                m_stCurrentSegment.ulSize += (u32)((u32)m_stCurrentSegment.pubRegionPtr[7U] & 0x000000FFU);

                /* Perform erasing of the current block */

                /* Calculate the start address                   */
                /* The Write/Erase is done with phisical address */
#if (PROG_OTA_DUALBANK_USED == STD_ON)
                ulStartAddress = PROG_CustomCalcInactiveBankWriteAddr(m_stCurrentSegment.ulStartAddress);
#else
                ulStartAddress = m_stCurrentSegment.ulStartAddress;
#endif /*(PROG_OTA_DUALBANK_USED == STD_ON)*/


                eProgStatus = PROG_MemDataAccess(
                    m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,
                    PROG_MEM_OPERATION_TYPE_ERASE, ulStartAddress,
                    m_stCurrentSegment.ulSize, NULL_PTR);

#if (PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON)
                m_ubNbSectEraseCnt++;
#endif
            }
#endif /* end of PROG_ERASE_TYPE == PROG_ERASE_BY_DYNAMIC_PARTITION_ID  */
            m_stCurrentSegment.ubSegmentNbr--;
        }
    }

    if ((PROG_E_OK == eProgStatus)?BCOV(2105):!BCOV(2106))
    {
#if (PROG_RESUM_REPROG == STD_ON)
        /* If resume is in progress, erase response shall not be sent as erasing is done in RequestDownload request */
        if ((m_stDiagMessageInfo.pubTxData[0] != UDS_SRV_RD)?BCOV(2107):!BCOV(2108))
#endif
        {
            /*Erase is finish, send positive response*/
            m_stDiagMessageInfo.ulLength = PROG_ERASE_POS_RESPONSE_SIZE;
#if ((PROG_ERASE_CHECK_TYPE == PROG_BLOCK_ERASE_CHECK) &&  (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID))
        /*Set logical block as successfully erased */
        (void)PROG_CustomSetEraseStatus(m_stCurrentSegment.ubLogicalBlockId,PROG_E_ERASED);
#endif /*((PROG_ERASE_CHECK_TYPE == PROG_BLOCK_ERASE_CHECK) &&(PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID))*/


#if (PROG_IMPL_VARIANT == PROG_IMPL_60)
            /* Allow integration code to manage the response */
            PROG_Custom_EraseRoutine_Succeed(m_stDiagMessageInfo.pubTxData,&m_stDiagMessageInfo.ulLength);
#elif (PROG_IMPL_VARIANT == PROG_IMPL_40)
        m_stDiagMessageInfo.pubTxData[4]=(u8)PROG_ROUTINE_FINISHED_OK;
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_40)*/
#if (PROG_IMPL_VARIANT == PROG_IMPL_11) || (PROG_IMPL_VARIANT == PROG_IMPL_91)
        /* Positive response for Routine type */
        m_stDiagMessageInfo.pubTxData[4] = (u8)(PROG_ROUTINE_FINISHED_OK | PROG_ROUTINE_TYPE_1);
#endif
#if ((PROG_IMPL_VARIANT == PROG_IMPL_2) || (PROG_IMPL_VARIANT == PROG_IMPL_4)|| (PROG_IMPL_VARIANT == PROG_IMPL_5))
        /* Positive response for Routine type */
        m_stDiagMessageInfo.pubTxData[4] = (u8)(PROG_ROUTINE_SELFTERM | PROG_ROUTINE_PREDIF | PROG_ROUTINE_RESAVAILABLE );
#endif
#if (PROG_IMPL_VARIANT == PROG_IMPL_50)
        /* Send positive response */
         m_stDiagMessageInfo.pubTxData[PROG_RC_ROUTINE_INFO_BASE_INDEX]             = PROG_ROUTINE_FINISHED_OK;
         m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_ERASEVERIF_BASE_INDEX] = PROG_RC_STATUS_RECORD_ERASEVERIF_OK;
#endif

#if (PROG_RESUM_REPROG == STD_ON)
        /* Notification of erasing success to update resume information */
        PROG_ResReprog_EraseStatusCheck(m_stCurrentSegment.ubLogicalBlockId);
#endif
        }

        eUdsStatus = UDS_ACK;
    }
    else if ((PROG_E_BUSY != eProgStatus)?BCOV(2109):!BCOV(2110))
    {
#if (PROG_RESUM_REPROG == STD_ON)
        /* If resume is in progress, erase response shall not be sent as erasing is done in RequestDownload request */
        if ((m_stDiagMessageInfo.pubTxData[0] != UDS_SRV_RD)?BCOV(2111):!BCOV(2112))
#endif
        {
#if PROG_PEC_ENABLE == STD_ON
            if((m_stCurrentSegment.uwModuleId == PROG_SW_APP_ID)?BCOV(2113):!BCOV(2114))
            {
                /* Set error in PEC */
                m_uwPEC = PROG_ERR_ERASE_SW;
            }
            else
            {
                /* Set error in PEC */
                m_uwPEC = PROG_ERR_ERASE_CAL;
            }
#endif
            /* Erase failed, send negative response*/
#if (PROG_IMPL_VARIANT == PROG_IMPL_50)
            /* routineInfo : Routine successfully completed */
            m_stDiagMessageInfo.pubData[PROG_RC_ROUTINE_INFO_BASE_INDEX]             = (u8)PROG_ROUTINE_FINISHED_OK;
            /* routineStatusRecord : Erase failed - General Failure */
            m_stDiagMessageInfo.pubData[PROG_RC_STATUS_RECORD_ERASEVERIF_BASE_INDEX] = (u8)PROG_RC_STATUS_RECORD_ERASEVERIF_GENFAIL;
            m_stDiagMessageInfo.ulLength = PROG_ERASE_POS_RESPONSE_SIZE;
            /* Send positive response */
            eUdsStatus = UDS_ACK;
#else /* #if (PROG_IMPL_VARIANT == PROG_IMPL_50) */
            eUdsStatus = UDS_NRC_72;
#if (PROG_IMPL_VARIANT == PROG_IMPL_60)
            /* Allow integration code to manage the response */
            PROG_Custom_EraseRoutine_Failed(m_stDiagMessageInfo.pubTxData,&m_stDiagMessageInfo.ulLength,&eUdsStatus);
#endif /* #if (PROG_IMPL_VARIANT == PROG_IMPL_60) */
#endif /* #else if (PROG_IMPL_VARIANT == PROG_IMPL_50) */
        }
#if (PROG_RESUM_REPROG == STD_ON)
        else
        {
            m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_72;
        }
#endif
    }
    else
    {
        /* Nothing to do */
    }

    if ((PROG_E_BUSY != eProgStatus)?BCOV(2115):!BCOV(2116))
    {
#if (PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON)
        /* Reset counter of number sector to erase */
        m_ubNbSectEraseCnt = 0U;
#endif /* PROG_SLICED_ERASING_FOR_NRC78_SENDING == STD_ON */
        /* Emit event PROG_EVENT_FINISHED */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
#if ((PROG_SEG_LIST_CKS == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_11))
    /* Init the segment list CRC index */
    m_stSegList.ubSegListCrcIndex = 0;
#endif
#if ((PROG_SEG_LIST_CKS == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_91))
    /* Init the segment list CRC index */
    m_stSegList.ubSegListCrcIndex = 0;
#endif
#if (PROG_RESUM_REPROG == STD_ON)
        /* If resume is in progress, erase response shall not be sent as erasing is done in RequestDownload request */
        if ((m_stDiagMessageInfo.pubTxData[0] != UDS_SRV_RD)?BCOV(2117):!BCOV(2118))
#endif
#if (PROG_IMPL_VARIANT == PROG_IMPL_30)
        /* Response for the Erase of the Invalid Segment shall be sent later */
        if ((!((m_stDiagMessageInfo.pubTxData[0] == UDS_SRV_RC) && (m_stDiagMessageInfo.pubTxData[2] == 0xFF) && (m_stDiagMessageInfo.pubTxData[3] == 0x01)))?BCOV(2119):!BCOV(2120))
#endif
        {
        /* Response shall be sent */
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
                m_stDiagMessageInfo.pubTxData, eUdsStatus);
        }
    }
}
/*-----------------------{end PROG_EraseStatusCheck}----------------------------*/
#endif /* if PROG_ERASE_MEMORY_ENABLE == STD_ON */


/*-------------------------------{PROG_Erase}------------------------------------*/
void PROG_Erase(void)
{
#if PROG_ERASE_MEMORY_ENABLE == STD_ON
#if ( (PROG_REPROGMEMM_ENABLED == STD_ON) \
      ||((PROG_FLASHWRAPPER_ENABLED == STD_ON) &&((PROG_FLASH_MODE == PROG_MEMORY_ASYNCHRONOUS) || (PROG_FLASH_EXT_MODE == PROG_MEMORY_ASYNCHRONOUS) || (PROG_CUSTOM_MEMORY_MODE == PROG_MEMORY_ASYNCHRONOUS))))
    tProgStatus eProgStatus;

    ICOV(2121);DBG_PROG_ERASE_ENTRY();

    /* Get Job result */
    eProgStatus = PROG_MemJobResult(
        m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType);
#if (PROG_IMPL_VARIANT == PROG_IMPL_80)
    PROG_EraseStatusCheck_Impl80(eProgStatus);
#else
    PROG_EraseStatusCheck(eProgStatus);
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_80) */
#else
/* CHECK: NOPARSE */
/* NOCOV-FEATURE_NOT_USED */
    DBG_PROG_ERASE_ENTRY();
/* CHECK: PARSE */
#endif
#else
    ICOV(2122);DBG_PROG_ERASE_ENTRY();
#endif

    ICOV(2122);DBG_PROG_ERASE_EXIT();
}
/*-----------------------------{end PROG_Erase}----------------------------------*/


#if PROG_REQUEST_DOWNLOAD_ENABLE == STD_ON
/*-----------------------------{PROG_RD_Check}----------------------------------*/
tProgStatus PROG_RD_Check(void)
{
    tProgStatus eProgStatus;
    tUdsStatus eUdsStatus;

#if ((PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK) || (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT))
    tProgStatus eIndexFound = PROG_E_NOT_OK;
#endif

#if ((PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK) || (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT))
    /* Index in the stCfgBlock table */
    u8 ubBlockTableId = 0U;
#endif
    tRDParam stRDParam;
    u8 ubLocalSegmentId;

    ICOV(2123);ubLocalSegmentId = 0;
    eUdsStatus = UDS_ACK;

    DBG_PROG_RD_CHECK_ENTRY();

    /* Extract address and size of data to be downloaded */
    eProgStatus = PROG_ExtractRDParameter(&m_stDiagMessageInfo.pubData[1],
            (m_stDiagMessageInfo.ulLength - 1U), &stRDParam, &eUdsStatus);

    if ((PROG_E_OK == eProgStatus)?BCOV(2124):!BCOV(2125))
    {
        /* Check DFI param */
        eProgStatus = PROG_CheckDFI(stRDParam.ubDataFormatId);

        if ((PROG_E_OK == eProgStatus)?BCOV(2126):!BCOV(2127))
        {
#if ((PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK) || (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT))
                /* Find the index table from block index */
                eIndexFound = PROG_FindBlockIndexInTable(stRDParam.uwBlockIdentifier, &ubBlockTableId);

                if ((PROG_E_OK == eIndexFound)?BCOV(2128):!BCOV(2129))
                {
                        /* Check logical block */
                        eProgStatus = PROG_GetSegmentBySegmentId(ubBlockTableId, stRDParam.ubSegmentId, stRDParam.ulMemorySize, \
                                                              &stRDParam.ulStartAddress,  &ubLocalSegmentId);
#if (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON)

                    if ((PROG_E_OK == eProgStatus)?BCOV(2130):!BCOV(2131))
                    {
                        /* Check the downgrade protection for RD */
                        eProgStatus = PROG_DowngradeProtection_CheckForEraseAndRD_Impl40(ubBlockTableId);
                    }
#endif /* (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON) */
                }
                else
                {
                    eProgStatus = PROG_E_NOT_OK;
                }
#else
            /* Check address */
            eProgStatus = PROG_GetSegmentByAddress(stRDParam.ulStartAddress,
                    stRDParam.ulMemorySize, PROG_MEM_OPERATION_TYPE_WRITE,
                    &ubLocalSegmentId);
#if (PROG_IMPL_VARIANT == PROG_IMPL_11)
            if ((PROG_E_OK == eProgStatus)?BCOV(2132):!BCOV(2133))
            {
                eProgStatus = PROG_RD_Check_Impl11( stRDParam.ulStartAddress,
                            stRDParam.ulMemorySize, ubLocalSegmentId, &m_stCurrentSegment.ubLogicalBlockId);
            }
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_11) */
#if (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID)
            if ((PROG_E_OK == eProgStatus)?BCOV(2134):!BCOV(2135))
            {
                /* Update Block index information */
                m_stCurrentSegment.ubLogicalBlockId = stConfigSegment[ubLocalSegmentId].ubBlockIndex;
            }
#endif
#endif /*((PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK) || (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT))*/
            if ((PROG_E_OK == eProgStatus)?BCOV(2136):!BCOV(2137))
            {
#if ((PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON) || (PROG_DECOMP_FLASH_ROUTINES == STD_ON))
                eProgStatus = PROG_DrvDown_RD_Check(ubLocalSegmentId);
                if((PROG_E_NOT_OK == eProgStatus)?BCOV(2138):!BCOV(2139))
                {
                    /* Send negative response */
                    eUdsStatus = UDS_NRC_70;
                }
                else
#endif /* #if ((PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON) || (PROG_DECOMP_FLASH_ROUTINES == STD_ON)) */
                {
#if(PROG_SEG_LIST_CKS == STD_ON)
                    if  ((   (m_stSegList.ubSegNbr == 0) || \
                            (stRDParam.ulStartAddress >=
                            (   m_stSegList.astSeg[m_stSegList.ubSegNbr-1].ulStartAddress + \
                                m_stSegList.astSeg[m_stSegList.ubSegNbr-1].ulSize)
                            )
                        )?BCOV(2140):!BCOV(2141))
                    {
#endif /*(PROG_SEG_LIST_CKS == STD_ON)*/
#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
#if(PROG_HSM_UPDATE_ENABLE == STD_ON)
                    if((stConfigSegment[ubLocalSegmentId].ePartitionType == PROG_HSM_PARTITION )?BCOV(2142):!BCOV(2143))
                    {
                       /* Write received Address and size in current segment */
                       m_stCurrentSegment.ulStartAddress = stRDParam.ulStartAddress;
                       m_stCurrentSegment.ulSize = stRDParam.ulMemorySize;
                       m_stCurrentSegment.ubSegmentId = ubLocalSegmentId;
                    }
                    else
                    {
#endif
                        if(( stConfigSegment[ubLocalSegmentId].ePartitionType != PROG_APPLICATION_PARTITION )?BCOV(2144):!BCOV(2145))
                        {
                            /* Check if Application is valid, set segment to Application segment */
                            m_stCurrentSegment.ubSegmentId = PROG_APP_SEGMENT_ID;
                            /* Check PSI value of the application */
                            eProgStatus = PROG_CheckPSIValue(PROG_SW_APP_ID,PROG_PSI_PROGRAMMED);

                            if((eProgStatus!= PROG_E_OK )?BCOV(2146):!BCOV(2147))
                            {
#if (PROG_PEC_ENABLE == STD_ON)
                                /* Set error in PEC */
                                m_uwPEC = PROG_ERR_SW_NOT_PRESENT;
#endif
                                /* Set negative status */
                                eUdsStatus = UDS_NRC_70;
                                eProgStatus = PROG_E_NOT_OK;
                            }
                        }
                        else
                        {
                            /*update status in order to continue with the erase check*/
                            eProgStatus = PROG_E_OK;
                        }

                        if ((PROG_E_OK == eProgStatus)?BCOV(2148):!BCOV(2149))
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_20) */
                        {
                            eProgStatus = PROG_CustomDownloadNotification(stRDParam.ulStartAddress, stRDParam.ulMemorySize);

                            if ((PROG_E_OK == eProgStatus)?BCOV(2150):!BCOV(2151))
                            {
                                /* Write received Address and size in current segment */
                                m_stCurrentSegment.ulStartAddress = stRDParam.ulStartAddress;
                                m_stCurrentSegment.ulSize = stRDParam.ulMemorySize;
                                m_stCurrentSegment.ubSegmentId = ubLocalSegmentId;

#if (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT)
                                m_stCurrentSegment.ubLogicalBlockId = ubBlockTableId;
                                m_stCurrentSegment.ubLogicalSegmentId= stRDParam.ubSegmentId;
#endif /*(PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT)*/

#if (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK)
                                m_stCurrentSegment.ubLogicalBlockId = ubBlockTableId;
                                /* setting logical segment ID to ubLocalSegmentId; one segment per block */
                                m_stCurrentSegment.ubLogicalSegmentId = ubLocalSegmentId;
#endif /*(PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK)*/
                            }
                            else
                            {
                                /* set return NRC */
                                eUdsStatus = UDS_NRC_70;
                            }
#if ((PROG_PEC_ENABLE == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_20))
                            if((UDS_NRC_70 == eUdsStatus)?BCOV(2152):!BCOV(2153))
                            {
                                if((stConfigSegment[ubLocalSegmentId].ePartitionType == PROG_APPLICATION_PARTITION)?BCOV(2154):!BCOV(2155))
                                {
                                    /* Set error in PEC */
                                    m_uwPEC = PROG_ERR_GET_APP_INFO;
                                }
                                else
                                {
                                    /* Set error in PEC */
                                    m_uwPEC = PROG_ERR_GET_CAL_INFO;
                                }
                            }
#endif /* ((PROG_PEC_ENABLE == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_20)) */
                        }
#if(PROG_HSM_UPDATE_ENABLE == STD_ON)
                    }
#endif
#if (PROG_SEG_LIST_CKS == STD_ON)
                    }
                    else
                    {
                        /* Set negative status */
                        eUdsStatus = UDS_NRC_31;
                        eProgStatus = PROG_E_NOT_OK;
#if (PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)
                        /*Update programming status*/
                        PROG_SetProgrammingStatus( PROG_RD_SIZE, PROG_FALSE);
                        PROG_SetProgrammingStatus( PROG_RD_AREA, PROG_FALSE);
#endif /*(PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)*/
                    }
#endif /*(PROG_SEG_LIST_CKS == STD_ON)*/
                }
            } /* if ( PROG_E_OK == eProgStatus) / PROG_GetSegmentByAddress */
            else
            {
#if (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON)
                if (( (PROG_E_RFS_DRIVER_FAIL  == eProgStatus)
                   ||(PROG_E_RFS_VERSION_FAIL == eProgStatus) )?BCOV(2156):!BCOV(2157))
                {
                    /* Set negative status */
                    eUdsStatus = UDS_NRC_70;
                }
                else
                {
                    /* Set negative status */
                    eUdsStatus = UDS_NRC_31;
                }
#else
                {
                    /* Set negative status */
                    eUdsStatus = UDS_NRC_31;
                }
#endif /* (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON) */
#if (PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)
                /*Update programming status*/
                PROG_SetProgrammingStatus( PROG_RD_SIZE, PROG_FALSE);
                PROG_SetProgrammingStatus( PROG_RD_AREA, PROG_FALSE);
#endif /*(PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)*/
            }
        } /* if ( PROG_E_OK == eProgStatus) / PROG_CheckDFI */
        else
        {
            /* Set negative status */
            eUdsStatus = UDS_NRC_31;
        }

    } /* if ( PROG_E_OK == eProgStatus) / PROG_ExtractRDParameter*/
    else
    {
#if (PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)
        /*Update programming status*/
        PROG_SetProgrammingStatus( PROG_RD_TYPE, PROG_FALSE);
#endif /*(PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)*/
    }
    if ((PROG_E_OK != eProgStatus)?BCOV(2158):!BCOV(2159))
    {
        /* Send negative response */
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
                m_stDiagMessageInfo.pubTxData, eUdsStatus);

    }
    DBG_PROG_RD_CHECK_EXIT(eProgStatus);
    return eProgStatus;
}
/*---------------------------{end PROG_RD_Check}--------------------------------*/

#if (PROG_IMPL_VARIANT == PROG_IMPL_40)
/*-----------------------------{PROG_Guard_RD_Check_RTEFinish}----------------------------------*/
tProgStatus PROG_Guard_RD_Check_RTEFinish(void)
{
    tProgStatus eProgStatus;
#if (PROG_DECRYPTION_ENABLE == STD_ON)
    u8 ubEncryptionMethodPreviousContext;
#endif
#if (PROG_COMPRESSION_ENABLE == STD_ON)
    u8 ubCompRequiredPreviousContext;
#endif
#if(PROG_SEG_LIST_CKS == STD_ON)
    u8 ubSegNbrPreviousContext;
#endif
    u32 ulStartAddressPreviousContext;
    u32 ulSizePreviousContext;
    u8 ubSegmentIdPreviousContext;
#if (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK) || (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT)
    u8 ubLogicalBlockIdPreviousContext;
    u8 ubLogicalSegmentIdPreviousContext;
#endif

    ICOV(2160);DBG_PROG_GUARD_RD_CHECK_RTEFINISH_ENTRY();

    /* Initialize the Transition to refused */
    eProgStatus = PROG_E_NOT_OK;

    /* Store the previous context */
#if (PROG_DECRYPTION_ENABLE == STD_ON)
    ubEncryptionMethodPreviousContext = m_ubEncryptionMethod;
#endif
#if (PROG_COMPRESSION_ENABLE == STD_ON)
    ubCompRequiredPreviousContext = m_stReprogInfo.ubCompRequired;
#endif
#if(PROG_SEG_LIST_CKS == STD_ON)
    ubSegNbrPreviousContext = m_stSegList.ubSegNbr;
#endif
    ulStartAddressPreviousContext = m_stCurrentSegment.ulStartAddress;
    ulSizePreviousContext = m_stCurrentSegment.ulSize;
    ubSegmentIdPreviousContext = m_stCurrentSegment.ubSegmentId;
#if (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK) || (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT)
    ubLogicalBlockIdPreviousContext = m_stCurrentSegment.ubLogicalBlockId;
    ubLogicalSegmentIdPreviousContext = m_stCurrentSegment.ubLogicalSegmentId;
#endif

    eProgStatus = PROG_RD_Check();

    if (((PROG_E_OK == eProgStatus) && (ubLogicalBlockIdPreviousContext != m_stCurrentSegment.ubLogicalBlockId))?BCOV(2161):!BCOV(2162))
    {
        /* Return status NOT_OK */
        eProgStatus = PROG_E_NOT_OK;

        /* Send negative response */
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, UDS_NRC_22);
    }

    if ((PROG_E_OK != eProgStatus)?BCOV(2163):!BCOV(2164))
    {
        /* Restore the previous context */
#if (PROG_DECRYPTION_ENABLE == STD_ON)
        m_ubEncryptionMethod = ubEncryptionMethodPreviousContext;
#endif
#if (PROG_COMPRESSION_ENABLE == STD_ON)
        m_stReprogInfo.ubCompRequired = ubCompRequiredPreviousContext;
#endif
#if(PROG_SEG_LIST_CKS == STD_ON)
        m_stSegList.ubSegNbr = ubSegNbrPreviousContext;
#endif
        m_stCurrentSegment.ulStartAddress = ulStartAddressPreviousContext;
        m_stCurrentSegment.ulSize = ulSizePreviousContext;
        m_stCurrentSegment.ubSegmentId = ubSegmentIdPreviousContext;
#if (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK) || (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT)
        m_stCurrentSegment.ubLogicalBlockId = ubLogicalBlockIdPreviousContext;
        m_stCurrentSegment.ubLogicalSegmentId = ubLogicalSegmentIdPreviousContext;
#endif
    }

    DBG_PROG_GUARD_RD_CHECK_RTEFINISH_EXIT(eProgStatus);

    return eProgStatus;
}
/*---------------------------{end PROG_Guard_RD_Check_RTEFinish}---------------------------------*/
#endif /* if PROG_IMPL_VARIANT == PROG_IMPL_40 */
#endif /* if PROG_REQUEST_DOWNLOAD_ENABLE == STD_ON */

#if PROG_REQUEST_DOWNLOAD_ENABLE == STD_ON
/*-----------------------------{PROG_Entry_RD}-----------------------------------*/
void PROG_Entry_RD(void)
{
#if ( (PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_40) )
    u8 ubSegmentId;
    u8 ubSegmentNbr;
#endif
#if (((PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CAL_PRESENT == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_20)) || (PROG_RESUM_REPROG == STD_ON) || (PROG_ERASE_CHECK_TYPE == PROG_BLOCK_ERASE_CHECK))
    tProgStatus eProgStatus = PROG_E_OK;
#endif
#if PROG_RESUM_REPROG == STD_ON
    u8 eResumeNeed;
#endif

#if ((PROG_IMPL_VARIANT == PROG_IMPL_90) || (PROG_IMPL_VARIANT == PROG_IMPL_91))
    tProgBoolean eProgBoolean_VS;
    tProgBoolean eProgBoolean_Sig;
#endif

    ICOV(2165);DBG_PROG_ENTRY_RD_ENTRY();
    /* Set Reprog variable */
    m_stReprogInfo.ulMemorySizeExpected = m_stCurrentSegment.ulSize;
    m_stReprogInfo.ulReceivedSizeOfData = 0U;
    m_stReprogInfo.ubBlockSequenceCounter = 1U;
    m_stReprogInfo.ubRDReceived = TRUE;

#if ( (PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_40) )
    (void)PROG_GetSegmentByBlockId(m_stCurrentSegment.ubLogicalBlockId, &ubSegmentId, &ubSegmentNbr);
    if ((stConfigSegment[ubSegmentId].ePartitionType == PROG_FLASH_ROUTINES_PARTITION)?BCOV(2166):!BCOV(2167))
    {
#if ((PROG_SEG_LIST_CKS == STD_ON) && (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID))
      /* Update the DataProgVerification */
      m_stDataProgVerification.ubLogicalBlockId = PROG_LOGICAL_BLOCK_VALUE_INIT;

      /* Init Segment list for CRC calculation */
      m_stSegList.ubSegNbr = 0;
#endif

#if ((PROG_CRY_PRESENT == STD_ON) && (PROG_VERIFICATION_ON_THE_FLY == STD_ON))
#if ((PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_SIGNATURE_CALCULATION_OVER_HASH == STD_OFF) )
/* Call crypto library to start the signature verification */
      (void)PROG_VerifySignatureStart
      (
            &m_stProgAsymPublicKey,
            NULL_PTR
      );
#endif
#endif
    }
#endif

#if (PROG_COMPRESSION_ENABLE == STD_ON)
    if ((TRUE == m_stReprogInfo.ubCompRequired)?BCOV(2168):!BCOV(2169))
    {
        /* Set Reprog compress variable */
        m_stReprogInfo.ulTotalDecompDataWrite = 0U;
        m_stWriteInfo.ulInDecompDataLength = 0U;

#if PROG_CAL_PRESENT == STD_OFF
        /* decompression init */
        SA_DecompressInit();
#elif ((PROG_CAL_PRESENT == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_20))
        eProgStatus = PROG_DecompressInit(m_stReprogInfo.ulMemorySizeExpected);

        if((eProgStatus != PROG_E_OK)?BCOV(2170):!BCOV(2171))
        {
            /* Send negative response NRC31 */
            m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_31;
        }
#endif
    }
    else
    {
        /* Nothing to do */
    }
#endif /* if (PROG_COMPRESSION_ENABLE == STD_ON) */

    /* Reset all variable of TD */
    m_stWriteInfo.ulDataToBeWritten = 0U;
    m_stWriteInfo.ulWriteLength = 0U;
    m_stWriteInfo.ulWrittenData = 0U;
    m_stWriteInfo.ubTDReceived = FALSE;
    m_stWriteInfo.ulAddressToWrite = m_stCurrentSegment.ulStartAddress;

    m_stPageBuffer.ulOldDataLength = 0U;
    m_stPageBuffer.ulNewDataLength = 0U;

#if (PROG_CRC_CALCULATION == PROG_TD_CRC16)
    m_stDataProgVerification.uwVal = PROG_CRC16_INIT_VAL;

#elif (PROG_CRC_CALCULATION == PROG_TD_CRC32)
    m_stDataProgVerification.ulVal = PROG_CRC32_INIT_VAL;
#endif

    /* Reset Prog verification variable */
#if ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_AUTHENTICATED_REPROG))
    m_stDataProgVerification.ubAlgo = PROG_VERIFY_HASH;
    /* For Impl31 the first segment of the block contains a header that shall be excluded for the verification */
    if (((stConfigSegment[stCfgBlock[m_stCurrentSegment.ubLogicalBlockId].ubFirstSegmentId].ulStartAddress) == m_stCurrentSegment.ulStartAddress)?BCOV(2172):!BCOV(2173))
    {
        m_stDataProgVerification.ulCnt = PROG_IMPL31_HEADER_SIZE;
        m_stDataProgVerification.ulAdd = m_stCurrentSegment.ulStartAddress+PROG_IMPL31_HEADER_SIZE;
    }
    else
    {
        m_stDataProgVerification.ulCnt = 0U;
        m_stDataProgVerification.ulAdd = m_stCurrentSegment.ulStartAddress;
    }
#else /*((PROG_IMPL_VARIANT != PROG_IMPL_31) || (PROG_REPROG_TYPE != PROG_AUTHENTICATED_REPROG))*/
    m_stDataProgVerification.ulCnt = 0U;
    m_stDataProgVerification.ulAdd = m_stCurrentSegment.ulStartAddress;

#if ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_STANDARD_REPROG))
    /* For Impl31 with Standard Reprogramming */
    m_stDataProgVerification.ubAlgo = PROG_VERIFY_CRC;
    /*Default algorithm set*/
#elif (PROG_IMPL_VARIANT == PROG_IMPL_20)
    m_stDataProgVerification.ubAlgo = PROG_VERIFY_HASH;
#elif (PROG_IMPL_VARIANT == PROG_IMPL_50)
    m_stDataProgVerification.ubAlgo = PROG_VERIFY_HASH;
#elif ((PROG_IMPL_VARIANT == PROG_IMPL_10) || (PROG_IMPL_VARIANT == PROG_IMPL_11))
    m_stDataProgVerification.ubAlgo = PROG_VERIFY_HASH;
    /* Compare number of segments to be downloaded is less than the max configured RD value */
    if((PROG_SEGMENT_NB <= PROG_MAX_RD_PER_BLOCK)?BCOV(2174):!BCOV(2175))
    {
        /* Start hash computation only if it is not an RD for verification block table */
        if((FALSE == PROG_Impl10_IsVerificationTableAddress(m_stCurrentSegment.ulStartAddress))?BCOV(2176):!BCOV(2177))
        {
            /* VBT is present, start hash computation */
            if((TRUE == PROG_Impl10_IsVerificationTablePresent())?BCOV(2178):!BCOV(2179))
            {
                if((PROG_E_OK == PROG_Impl10_ValidateDataBlockAddress(m_stCurrentSegment.ulStartAddress))?BCOV(2180):!BCOV(2181))
                {
                    PROG_Impl10_AdjustAddressForHash(&(m_stDataProgVerification.ulAdd));
                    (void)PROG_ComputeHashStart(PROG_CSM_HASH_ID,NULL_PTR,0U,NULL_PTR);
                }
            }
            /* VBT is not downloaded first, reject the request */
            else
            {
                /* Send negative response NRC24 */
                m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_24;
            }
        }
    }
    else
    {
        /* Send negative response NRC70 */
        m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_70;
    }
#elif ((PROG_IMPL_VARIANT == PROG_IMPL_90) || (PROG_IMPL_VARIANT == PROG_IMPL_91))

    eProgBoolean_VS = PROG_Impl90_IsVerificationStructureAddress(m_stCurrentSegment.ulStartAddress);
    eProgBoolean_Sig = PROG_Impl90_IsSignatureAddress(m_stCurrentSegment.ulStartAddress);

    /* Start hash computation only if it is not an RD for verification block table and Signature */
    if(((FALSE == eProgBoolean_VS) && (FALSE == eProgBoolean_Sig))?BCOV(2182):!BCOV(2183))
    {
      /* Start hash computation */
      m_stDataProgVerification.ubAlgo = PROG_VERIFY_HASH;
      (void)PROG_ComputeHashStart(PROG_CSM_HASH_ID,NULL_PTR,0U,NULL_PTR);
    }
    else
    {
        m_stDataProgVerification.ubAlgo = PROG_VERIFY_CRC;
    }
#elif (PROG_IMPL_VARIANT == PROG_IMPL_40)
#if PROG_SIGNATURE_CALCULATION == STD_ON
    m_stDataProgVerification.ubAlgo = PROG_VERIFY_SIGNATURE;
#else
    m_stDataProgVerification.ubAlgo = PROG_VERIFY_CRC;
#endif
#elif (PROG_IMPL_VARIANT == PROG_IMPL_60)
#if PROG_SIGNATURE_CALCULATION == STD_ON
    m_stDataProgVerification.ubAlgo = PROG_VERIFY_SIGNATURE;
#elif (PROG_HASH_CALCULATION == STD_ON)
    m_stDataProgVerification.ubAlgo = PROG_VERIFY_HASH;
#else
    m_stDataProgVerification.ubAlgo = PROG_VERIFY_CRC;
#endif
#elif ((PROG_IMPL_VARIANT == PROG_IMPL_3) || (PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
    m_stDataProgVerification.ubAlgo = PROG_VERIFY_HASH;
#if (PROG_IMPL_VARIANT == PROG_IMPL_3)
    (void)PROG_ComputeHashStart(PROG_CSM_HASH_FOR_SIGNATURE_ID,NULL_PTR,0U,NULL_PTR);
#endif
#else
    m_stDataProgVerification.ubAlgo = PROG_VERIFY_CRC;
#endif
#endif

#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
    if ((m_ubEncryptionMethod != PROG_NODECRYPTION_NOCOMPRESSION)?BCOV(2184):!BCOV(2185))
    {
        m_ubFinishDecryption   = PROG_FALSE;
        m_stCryptoData.ulTotDecryptedWrittenSize = 0U;
        m_stCryptoData.ubOperationInProgress = PROG_DECRYPTION_IN_PROGRESS;
        /* Start decryption */
        PROG_DecryptionStart();
    }
    else
    {
        m_stCryptoData.ubOperationInProgress = PROG_NO_OPERATION_IN_PROGRESS;
    }
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/


#if (((PROG_SEG_LIST_CKS == STD_ON) || (PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON)) && (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID))
    /* If received BlockId is different from the current one, we restart the signature computation */
    if ((m_stCurrentSegment.ubLogicalBlockId != m_stDataProgVerification.ubLogicalBlockId)?BCOV(2186):!BCOV(2187))
    {
        /* Update the DataProgVerification */
        m_stDataProgVerification.ubLogicalBlockId = m_stCurrentSegment.ubLogicalBlockId;

        /* Init Segment list for CRC calculation */
        m_stSegList.ubSegNbr = 0;
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
        if ((m_stCryptoData.ubOperationInProgress == PROG_NO_OPERATION_IN_PROGRESS)?BCOV(2188):!BCOV(2189))
        {
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON) */
            if (((m_stDataProgVerification.ubAlgo == PROG_VERIFY_SIGNATURE) || (m_stDataProgVerification.ubAlgo == PROG_VERIFY_HASH))?BCOV(2190):!BCOV(2191))
            {
#if ((PROG_CRY_PRESENT == STD_ON) && (PROG_VERIFICATION_ON_THE_FLY == STD_ON))
#if ((PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_SIGNATURE_CALCULATION_OVER_HASH == STD_OFF))
                /* Call crypto library to start the signature verification */
                (void)PROG_VerifySignatureStart
                    (
                        &m_stProgAsymPublicKey,
                        NULL_PTR
                    );
#endif /* #if ((PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_SIGNATURE_CALCULATION_OVER_HASH == STD_OFF))*/
#if ((PROG_HASH_CALCULATION ==  STD_ON) || ((PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_SIGNATURE_CALCULATION_OVER_HASH == STD_ON)))
                /* Call crypto library to start the hash  computation*/
                (void)PROG_ComputeHashStart(PROG_CSM_HASH_FOR_SIGNATURE_ID,NULL_PTR,0U,NULL_PTR);
#endif
#endif /* #if (PROG_CRY_PRESENT == STD_ON) */
            }
            else
            {
#if (PROG_IMPL_VARIANT == PROG_IMPL_40)
                /* Simulate crypto finish to go to state RD_SIGNATURE */
                PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY);
#endif
            }
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
        }
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON) */
    }
    else
    {
#if (PROG_IMPL_VARIANT == PROG_IMPL_40)
        /* Simulate crypto finish to go to state RD_SIGNATURE */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY);
#endif
    }
#endif /* #if ((PROG_SEG_LIST_CKS == STD_ON) && (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID)) */

#if PROG_RESUM_REPROG == STD_ON
    eProgStatus = PROG_ResReprog_CheckResume(m_stCurrentSegment.ulStartAddress, m_stCurrentSegment.ubLogicalBlockId, &eResumeNeed);

    if ((PROG_E_OK != eProgStatus)?BCOV(2192):!BCOV(2193))
    {
        /* Send negative response */
        m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_70;
    }
    else
    {
        /* Nothing to do */
    }
#endif
#if (PROG_ERASE_CHECK_TYPE == PROG_BLOCK_ERASE_CHECK)
#if (PROG_RESUM_REPROG == STD_ON) || ((PROG_CAL_PRESENT == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_20))
    if ((PROG_E_OK ==eProgStatus)?BCOV(2194):!BCOV(2195))
#endif /* (PROG_RESUM_REPROG != STD_ON) || ((PROG_CAL_PRESENT == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_20)) */
    {
        /* write the already erase flag */
        eProgStatus = PROG_CustomSetEraseStatus(m_stCurrentSegment.ubLogicalBlockId, PROG_E_NOT_ERASED);
        if ((PROG_E_OK == eProgStatus)?BCOV(2196):!BCOV(2197))
        {
            m_stDiagMessageInfo.ubDiagStatus = UDS_ACK;
        }
        else
        {
            m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_70;
        }
    }
#endif /*(PROG_ERASE_CHECK_TYPE == PROG_BLOCK_ERASE_CHECK)*/

#if PROG_RESUM_REPROG == STD_ON
    if (((PROG_E_OK !=eProgStatus) || (FALSE==eResumeNeed))?BCOV(2198):!BCOV(2199))
#endif
    {    /* prepare response */
        if ((PROG_SIZE_OF_NB_BLOCK_LEN == 0x20U)?BCOV(2200):!BCOV(2201))
        {
            m_stDiagMessageInfo.pubTxData[1] = PROG_SIZE_OF_NB_BLOCK_LEN;
            m_stDiagMessageInfo.pubTxData[2] = (u8)((u16)(PROG_MAX_BYTE_IN_TD >> 8U) & 0x00FFU);
            m_stDiagMessageInfo.pubTxData[3] = (u8)(PROG_MAX_BYTE_IN_TD & 0x00FFU);
        }
        else
        {
            m_stDiagMessageInfo.pubTxData[1] = PROG_SIZE_OF_NB_BLOCK_LEN;
            m_stDiagMessageInfo.pubTxData[2] = (u8)((u32)(PROG_MAX_BYTE_IN_TD >> 16U) & 0x0000FFU);
            m_stDiagMessageInfo.pubTxData[3] = (u8)((u16)(PROG_MAX_BYTE_IN_TD >> 8U) & 0x00FFU);
            m_stDiagMessageInfo.pubTxData[4] = (u8)(PROG_MAX_BYTE_IN_TD & 0x00FFU);
        }

/* Send the response for other implementation that 40 */
#if (PROG_IMPL_VARIANT != PROG_IMPL_40)
        if ((m_stDiagMessageInfo.ubDiagStatus == UDS_ACK)?BCOV(2202):!BCOV(2203))
        {
            /* Send positive response*/
            UDS_LongRequestEnd(PROG_RD_RESPONSE_SIZE,
                m_stDiagMessageInfo.pubTxData, UDS_ACK);
        }
        else
        {
            /* Send negative response*/
            UDS_LongRequestEnd(PROG_RD_RESPONSE_SIZE,
                m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);
        }
#endif
    }

#if (PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)
    m_stMultipleBuffers.ulBufferedSizeOfData = 0U;
    m_stMultipleBuffers.eResponsePending     = PROG_FALSE;
    m_stMultipleBuffers.eBufferProcessing    = PROG_FALSE;
    BlPduR_UnlockBuffer(BLPDUR_ALL_BUFFER);
#endif /*(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)*/

    DBG_PROG_ENTRY_RD_EXIT();
}
/*---------------------------{end PROG_Entry_RD}---------------------------------*/
#endif /* if PROG_REQUEST_DOWNLOAD_ENABLE == STD_ON */

/*-----------------------------{PROG_Entry_RD_Signature}-----------------------------------*/
#if (PROG_IMPL_VARIANT == PROG_IMPL_40)
void PROG_Entry_RD_Signature(void)
{
    ICOV(2204);DBG_PROG_ENTRY_RD_SIGNATURE_ENTRY();

#if ((PROG_COMPUTE_HASH_WITH_ADDR_LEN == STD_ON) && (PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_CRY_PRESENT == STD_ON))
    /* Concatenate Address (4 bytes) and length (4 bytes) extracted in the Request Download */
    /* !!! Only two bytes expected for Address (2 bytes padded to 0) as only Block Id is expected in RD !!! */
    /* !!! Parameter 'Request_Download_Address_Mode' is expected to be set to 'Download by logical block' !!!*/
    m_aubUdsData[0U] = (u8)(0x00U);
    m_aubUdsData[1U] = (u8)(0x00U);
    m_aubUdsData[2U] = (u8)(stCfgBlock[m_stCurrentSegment.ubLogicalBlockId].uwBlockIdentifier >> 8U);
    m_aubUdsData[3U] = (u8)(stCfgBlock[m_stCurrentSegment.ubLogicalBlockId].uwBlockIdentifier);
    m_aubUdsData[4U] = (u8)(m_stCurrentSegment.ulSize >> 24U);
    m_aubUdsData[5U] = (u8)(m_stCurrentSegment.ulSize >> 16U);
    m_aubUdsData[6U] = (u8)(m_stCurrentSegment.ulSize >> 8U);
    m_aubUdsData[7U] = (u8)(m_stCurrentSegment.ulSize);

    /* In case of verification on received data */
    if ((PROG_VERIFY_SIGNATURE == m_stDataProgVerification.ubAlgo)?BCOV(2205):!BCOV(2206))
    {
        /* Include those information in the verification signature */
        PROG_VerifySignatureUpdate(&m_aubUdsData[0U], (u32)8U);
    }
#else
    /* Simulate crypto finish to go to state RD_FINISH state */
    PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY);
#endif

    DBG_PROG_ENTRY_RD_SIGNATURE_EXIT();
}
#endif
/*---------------------------{end PROG_Entry_RD_Signature}---------------------------------*/


/*-----------------------------{PROG_Entry_RD_Finish}-----------------------------------*/
#if (PROG_IMPL_VARIANT == PROG_IMPL_40)
void PROG_Entry_RD_Finish(void)
{

#if PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON
    u8 ubSegmentId;
    u8 ubSegmentNbr;
#endif
    ICOV(2207);DBG_PROG_ENTRY_RD_FINISH_ENTRY();

    if ((m_stDiagMessageInfo.ubDiagStatus == UDS_ACK)?BCOV(2208):!BCOV(2209))
    {
        /* Send positive response*/
        UDS_LongRequestEnd(PROG_RD_RESPONSE_SIZE,
            m_stDiagMessageInfo.pubTxData, UDS_ACK);
    }
    else
    {
        /* Send negative response*/
        UDS_LongRequestEnd(PROG_RD_RESPONSE_SIZE,
            m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);
    }

#if PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON
    (void)PROG_GetSegmentByBlockId(m_stCurrentSegment.ubLogicalBlockId, &ubSegmentId, &ubSegmentNbr);
    if ((stConfigSegment[ubSegmentId].ePartitionType == PROG_FLASH_ROUTINES_PARTITION)?BCOV(2210):!BCOV(2211))
    {
        PROG_DrvDown_SetFlashRoutinesCorruption(PROG_TRUE);
    }
    OSC_PARAM_UNUSED(ubSegmentNbr);
#endif

    DBG_PROG_ENTRY_RD_FINISH_EXIT();
}
#endif
/*---------------------------{end PROG_Entry_RD_Finish}---------------------------------*/


#if PROG_TRANSFER_DATA_ENABLE == STD_ON
/*-----------------------------{PROG_Entry_TD}-----------------------------------*/
void PROG_Entry_TD(void)
{
    tProgStatus eProgStatus;

    ICOV(2212);DBG_PROG_ENTRY_TD_ENTRY();
    eProgStatus = PROG_TD();

    if ((PROG_E_OK == eProgStatus)?BCOV(2213):!BCOV(2214))
    {
#if (PROG_SIGNATURE_VERIFICATION_ON_FLASHED_DATA == STD_OFF)
/* CHECK: NOPARSE */
/* NOCOV-FEATURE_NOT_USED */
/*This part of the code is not considered for code coverage because the SignatureVerificationOnFlashData configuration is not supported.
Therefore, PROG_SIGNATURE_VERIFICATION_ON_FLASHED_DATA = STD_OFF condition cannot be reached*/
#if ((PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_CRY_PRESENT == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_40))
        /* In case of verification on received data */
        if (m_stDiagMessageInfo.pubData[1] == m_stReprogInfo.ubBlockSequenceCounter)
        {
           if (PROG_VERIFY_SIGNATURE == m_stDataProgVerification.ubAlgo)
           {
               /* Launch the verification signature on received data in TD */
               /* Don't take in account the two first bytes of the requests */
               PROG_VerifySignatureUpdate(&m_stDiagMessageInfo.pubData[2U], (u32)((u32)m_stDiagMessageInfo.ulLength - 2U));
           }
        }
#endif
/* CHECK: PARSE */
#endif
#if  ((PROG_VERIFICATION_METHOD == PROG_VERIFICATION_IN_DFI) && (PROG_SIGNATURE_CALCULATION == STD_ON) && ((PROG_CRY_PRESENT == STD_ON) || ((PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CAL_PRESENT == STD_ON))))
    if((m_ubVerificationMethod == PROG_VERIFICATION_SIGNATURE_AND_CRC)?BCOV(2215):!BCOV(2216))
    {
        /* In case of verification on received data */
        if ((m_stDiagMessageInfo.pubData[1] == m_stReprogInfo.ubBlockSequenceCounter)?BCOV(2217):!BCOV(2218))
        {
           if ((PROG_VERIFY_SIGNATURE == m_stDataProgVerification.ubAlgo)?BCOV(2219):!BCOV(2220))
           {
               /* Launch the verification signature on received data in TD */
               /* Don't take in account the two first bytes of the requests */
               PROG_VerifySignatureUpdate(&m_stDiagMessageInfo.pubData[2U], (u32)((u32)m_stDiagMessageInfo.ulLength - 2U));
           }
           else
           {
               /* Do nothing */
           }
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }
#endif /* (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_IN_DFI) && (PROG_SIGNATURE_CALCULATION == STD_ON) && ((PROG_CRY_PRESENT == STD_ON) || ((PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CAL_PRESENT == STD_ON))) */
#if (PROG_HSM_UPDATE_ENABLE == STD_ON)
        if((stConfigSegment[m_stCurrentSegment.ubSegmentId].ePartitionType == PROG_HSM_PARTITION)?BCOV(2221):!BCOV(2222))
        {
          /*Reset the HSM Timeout counter before transferring the TD block to the HSM*/
          m_uwHSMTimeoutCnt = 0x00U;
          /* Emit event PROG_EVENT_HSMUPDATE_WRITE_TD */
          PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_HSMUPDATE_WRITE_TD);
        }
        else
#endif
        {
          /* Emit event PROG_EVENT_WRITE_CHECK */
          PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK);
        }
    }
    else
    {
        /* Nothing to do */
    }
    DBG_PROG_ENTRY_TD_EXIT();
}
/*---------------------------{end PROG_Entry_TD}---------------------------------*/
#endif /* if PROG_TRANSFER_DATA_ENABLE == STD_ON */



#if PROG_TRANSFER_DATA_ENABLE == STD_ON
/*-------------------------{PROG_Entry_Streaming}--------------------------------*/
void PROG_Entry_Streaming(void)
{
    ICOV(2223);DBG_PROG_ENTRY_STREAMING_ENTRY();
    PROG_Streaming();

    /* Emit event PROG_EVENT_WRITE_CHECK */
    PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK);

    DBG_PROG_ENTRY_STREAMING_EXIT();
}
/*-----------------------{end PROG_Entry_Streaming}------------------------------*/
#endif /* if PROG_TRANSFER_DATA_ENABLE == STD_ON */

#if PROG_TRANSFER_DATA_ENABLE == STD_ON
/*----------------------------{PROG_Streaming}-----------------------------------*/
void PROG_Streaming(void)
{
#if ((PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CAL_PRESENT == STD_ON))
    tProgStatus eProgStatus;
#endif
    ICOV(2224);if((m_ubTDReceive == PROG_FALSE)?BCOV(2225):!BCOV(2226))
    {
      DBG_PROG_STREAMING_ENTRY();
      /* Update message length */
      m_stDiagMessageInfo.ulLength = m_uwStreamingLength;

      /*Check Sequence Counter */
      if ((m_stDiagMessageInfo.pubData[1] == m_stReprogInfo.ubBlockSequenceCounter)?BCOV(2227):!BCOV(2228))
      {
          if (((m_stReprogInfo.ulReceivedSizeOfData
                  + (u32)((u32)m_stDiagMessageInfo.ulLength - 2U))
                  <= m_stReprogInfo.ulMemorySizeExpected)?BCOV(2229):!BCOV(2230))
          {
#if (PROG_COMPRESSION_ENABLE == STD_ON)
              if ((m_stReprogInfo.ubCompRequired == TRUE)?BCOV(2231):!BCOV(2232))
              {
                  if (((m_stDiagMessageInfo.ulLength - 2U) >
                      (u16)(m_stWriteInfo.ulInDecompDataLength & 0x0000FFFFU))?BCOV(2233):!BCOV(2234))
                  {
#if PROG_CAL_PRESENT == STD_OFF
                      SA_DecompressData(&m_stDiagMessageInfo.pubData[2U],
                              (u16)((m_stDiagMessageInfo.ulLength - 2U)
                                      - (u16)(m_stWriteInfo.ulInDecompDataLength & 0x0000FFFFU)));
#else
                      eProgStatus = PROG_DecompressData (&m_stDiagMessageInfo.pubData[2U],
                                      (u16)((m_stDiagMessageInfo.ulLength - 2U)
                                      - (u16)(m_stWriteInfo.ulInDecompDataLength & 0x0000FFFFU)));

                      if((eProgStatus != PROG_E_OK)?BCOV(2235):!BCOV(2236))
                      {
#if PROG_PEC_ENABLE == STD_ON
                          /* set error in PEC */
                          m_uwPEC = PROG_ERR_COMPRESSION;
#endif
                          /* Send negative response NRC31 */
                          m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_31;
                      }
                      else
#endif
                      {
                          /* Increment the number of data ask for decompression */
                          m_stWriteInfo.ulInDecompDataLength = (u32)((u32)m_stDiagMessageInfo.ulLength - 2U);
                      }
                  }
              }
              else
 #endif /* (PROG_COMPRESSION_ENABLE == STD_ON)*/
              {
                  if (((m_stDiagMessageInfo.ulLength - 2U)
                          > (u16)(m_stWriteInfo.ulDataToBeWritten & 0x0000FFFFU))?BCOV(2237):!BCOV(2238))
                  {
                      /* Increment the number of data to be written */
                      m_stWriteInfo.ulDataToBeWritten = (u32)((u32)m_stDiagMessageInfo.ulLength - 2U);
                  }
                  else
                  {
                      /* Nothing to do */
                  }
              }
          }
          else
          {
              /* Set negative response to NRC_71 */
              m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_71;
          }
      }
      else
      {
          /*Nothing to do */
      }
      DBG_PROG_STREAMING_EXIT();
    }
}
/*--------------------------{end PROG_Streaming}---------------------------------*/
#endif /* if PROG_TRANSFER_DATA_ENABLE == STD_ON */

#if PROG_TRANSFER_DATA_ENABLE == STD_ON
/*-------------------------{PROG_Entry_TD_Failed}--------------------------------*/
void PROG_Entry_TD_Failed(void)
{
#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
    u8 ubPartitionId = 0U;
    u8 ubModuleIndex;
    tProgStatus eProgStatus;
#endif

    ICOV(2239);DBG_PROG_ENTRY_TD_FAILED_ENTRY();

    PROG_Send_NRC(m_stDiagMessageInfo.ubDiagStatus);
#if (PROG_MULTIPLE_BUFFERS_ENABLE == STD_OFF)
    /* Reset Error status*/
    m_stDiagMessageInfo.ubDiagStatus = UDS_ACK;
#endif /*(PROG_MULTIPLE_BUFFERS_ENABLE == STD_OFF)*/
    /* Reset TD received flag*/
    m_stWriteInfo.ubTDReceived = FALSE;

    /* Reset RD received flag*/
    m_stReprogInfo.ubRDReceived = FALSE;

#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
    /* Get the partition ID */
    /* Check if Application or calibration programming */
    if(((m_stCurrentSegment.uwModuleId != PROG_SW_APP_ID)
#if(PROG_HSM_UPDATE_ENABLE == STD_ON)
        && (stConfigSegment[m_stCurrentSegment.ubSegmentId].ePartitionType != PROG_HSM_PARTITION)
#endif
        )?BCOV(2240):!BCOV(2241))
    {
        eProgStatus = PROG_GetModulePartition(m_stCurrentSegment.uwModuleId, &ubPartitionId, &ubModuleIndex);

        if ((PROG_E_OK == eProgStatus)?BCOV(2242):!BCOV(2243))
        {
            /* Reset expectedModuleId for calibration programming */
            m_stReprogInfo.uwExpectedModuleId[ubPartitionId - 1U] = PROG_GET_CALIB_SW_FIRST_MODULE_ID(ubPartitionId);
        }
        else
        {
            /* Nothing to do */
        }
    }
#endif

    DBG_PROG_ENTRY_TD_FAILED_EXIT();
}
/*-----------------------{end PROG_Entry_TD_Failed}------------------------------*/
#endif /* if PROG_TRANSFER_DATA_ENABLE == STD_ON */

/*-----------------------------{PROG_Send_NRC}-----------------------------------*/
void PROG_Send_NRC(tUdsStatus eUdsStatus)
{
    ICOV(2244);DBG_PROG_SEND_NRC_ENTRY();
#if PROG_PEC_ENABLE == STD_ON
    if(((eUdsStatus == UDS_NRC_24) && (m_uwPEC == PROG_PEC_NO_ERROR))?BCOV(2245):!BCOV(2246))
    {
        m_uwPEC = PROG_ERR_MSG_OUT_OF_SEQUENCE;
    }
#endif

#if (PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)
    /* As the feature "Multiple buffers" is activated, the negative response of a TD shall always be sent at an odd TD sequence number */
    /* So if for example, we need to send NRC24 for TD[0], */
    /* the negative response shall be sent at the reception of TD[1] and positive response shall be sent for TD[0] */
    /* The condition below is done with 0x76 (Service 0x36 + Positive Response 0x40) because the first TD is always Acknowledged in Prog_TransferData */
    if (((UDS_SRV_TD + UDS_ACK) == m_stDiagMessageInfo.pubData[0U])?BCOV(2247):!BCOV(2248))
    {
        m_stMultipleBuffers.ulBufferedSizeOfData = 0U;
        m_stMultipleBuffers.eBufferProcessing  = PROG_FALSE;
        BlPduR_UnlockBuffer(BLPDUR_ALL_BUFFER);

        if ((PROG_TRUE == m_stMultipleBuffers.eResponsePending)?BCOV(2249):!BCOV(2250))
        {
            /* Reset Error status*/
            UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
            m_stDiagMessageInfo.pubTxData, eUdsStatus);
            m_stDiagMessageInfo.ubDiagStatus = UDS_ACK;
        }
        else
        {
            m_stDiagMessageInfo.ubDiagStatus = eUdsStatus;

            /* Look if there was a pending event for another request */
            if ((m_stEventInfo.Event != PROG_NO_EVENT)?BCOV(2251):!BCOV(2252))
            {
                /* Store request information */
                m_stDiagMessageInfo.pubData = m_stEventInfo.Data;
                m_stDiagMessageInfo.pubTxData = m_stEventInfo.Data;
                m_stDiagMessageInfo.ulLength = m_stEventInfo.Length;

                /* Post Event in state machine */
                PROG_HsmEmit(&PROG_HsmScPROG, m_stEventInfo.Event);
                m_stEventInfo.Event = PROG_NO_EVENT;
            }

        }
    }
    /* For all other services than Transfer Data, NRC shall be sent */
    /* on the current service request (no shift to the next same service */
    /* request) */
    else
    {
        /* Send negative response */
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
        m_stDiagMessageInfo.pubTxData, eUdsStatus);
    }
#else
    /* Send negative response */
    UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
            m_stDiagMessageInfo.pubTxData, eUdsStatus);
#endif /*(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)*/

    DBG_PROG_SEND_NRC_EXIT();
}
/*-----------------------------{PROG_Send_NRC}-----------------------------------*/

#if PROG_TRANSFER_DATA_ENABLE == STD_ON
/*----------------------------{PROG_Entry_Write}---------------------------------*/
void PROG_Entry_Write(void)
{
    u32 ulPageToWrite;
    u8 * pubDataToWrite;
    u32 ulMinValueToWrite = m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].ulMinValueToWrite;
    tProgStatus eProgStatus;
    u32 ulStartAddress;

#if (PROG_COMPRESSION_ENABLE == STD_ON)
    u8* pubdata;
    PduLengthType ulLength;

#if ( PROG_CAL_PRESENT == STD_OFF)
    tDecompressStateType eCompStatus = SA_DECOMP_FINISH;
#else
    tProgDecompressStateType eCompStatus = PROG_DECOMP_FINISH;
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
    tProgCryState eDecryptState;
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
#endif /* ( PROG_CAL_PRESENT == STD_OFF) */
#endif

    ICOV(2253);DBG_PROG_ENTRY_WRITE_ENTRY();

    if ((0U < m_stPageBuffer.ulNewDataLength)?BCOV(2254):!BCOV(2255))
    {
        pubDataToWrite = &m_stPageBuffer.aubData[0];
        m_stWriteInfo.ulWriteLength = (u32)m_stPageBuffer.ulNewDataLength + (u32)m_stPageBuffer.ulOldDataLength;
    }
    else
    {
        if (((((m_stReprogInfo.ulReceivedSizeOfData + m_stDiagMessageInfo.ulLength) - 2U)
                == (m_stReprogInfo.ulMemorySizeExpected))
#if((PROG_CSM_DECRYPTION_ENABLE == STD_ON)&& (PROG_COMPRESSION_ENABLE == STD_ON))
        || (m_ubRTEReceived == TRUE)
#endif
#if((PROG_COMPRESSION_ENABLE == STD_ON))
        || ( m_ubDecompNotWritten == TRUE)
#endif
            )?BCOV(2256):!BCOV(2257))
        {
#if (PROG_COMPRESSION_ENABLE == STD_ON)
            if ((TRUE == m_stReprogInfo.ubCompRequired)?BCOV(2258):!BCOV(2259))
            {
                /* Call decompression API to get the status of decompression process */
                /* The data and length are not used at all here */
#if ( PROG_CAL_PRESENT == STD_OFF)
                eCompStatus = SA_GetDecompressedData(&pubdata, &ulLength);
                if ((SA_DECOMP_FINISH == eCompStatus)?BCOV(2260):!BCOV(2261))
#else
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
                eDecryptState = PROG_IDLE;
                if ((m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)?BCOV(2262):!BCOV(2263))
                {
                    eDecryptState = PROG_GetDecryptionState();
                }
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
                eCompStatus = PROG_GetDecompressedData(&pubdata, &ulLength);
                if(((PROG_DECOMP_FINISH == eCompStatus)
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
                  && ((eDecryptState == PROG_DECRYPTION_FINISH_END) || (m_stCryptoData.ubOperationInProgress != PROG_DECRYPTION_IN_PROGRESS))
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
                  )?BCOV(2264):!BCOV(2265))
#endif
                {
                    /* Store length to write with all data */
                    m_stWriteInfo.ulWriteLength = m_stWriteInfo.ulDataToBeWritten
                            - m_stWriteInfo.ulWrittenData;
                }
                else
                {
                    /* calculate number of page to write */
                    ulPageToWrite = ((m_stWriteInfo.ulDataToBeWritten
                            - m_stWriteInfo.ulWrittenData) / PROG_MIN_VAL_TO_WRITE);

                    /* Store length to write align data */
                    m_stWriteInfo.ulWriteLength = ulPageToWrite * PROG_MIN_VAL_TO_WRITE;
                }
            }
            else
#endif
            {
                /* Store length to write with all data */
                m_stWriteInfo.ulWriteLength = m_stWriteInfo.ulDataToBeWritten
                    - m_stWriteInfo.ulWrittenData;
            }
        }
        else
        {
            /* calculate number of page to write */
            ulPageToWrite = (u32) ((m_stWriteInfo.ulDataToBeWritten - m_stWriteInfo.ulWrittenData) / ulMinValueToWrite);

            /* Store length to write align data */
            m_stWriteInfo.ulWriteLength = (u32) (ulPageToWrite * ulMinValueToWrite);
        }
        /* Assumption here is that decompression is always done after decryption if both are enabled */
#if (PROG_COMPRESSION_ENABLE == STD_ON)
        if ((TRUE == m_stReprogInfo.ubCompRequired)?BCOV(2266):!BCOV(2267))
        {
            /* set the data to be written value to exact number of data that will be written */
            m_stWriteInfo.ulDataToBeWritten = (m_stWriteInfo.ulWrittenData + m_stWriteInfo.ulWriteLength);
            pubDataToWrite = m_stWriteInfo.pubDecompData;
        }
        else
#endif
        {
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
            if ((m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)?BCOV(2268):!BCOV(2269))
            {
                pubDataToWrite = &m_stCryptoData.aubCryptoBuffer[m_stWriteInfo.ulWrittenData];
            }
            else
#endif
            {
                pubDataToWrite = &m_stDiagMessageInfo.pubData[2U + m_stWriteInfo.ulWrittenData];
            }
        }
    }
#if (PROG_COMPRESSION_ENABLE == STD_ON)
#if (PROG_RD_DATA_SIZE_TYPE == PROG_DECOMPRESSED_DATA_SIZE)
    if((((m_stWriteInfo.ulWrittenData+ m_stWriteInfo.ulWriteLength +m_stReprogInfo.ulTotalDecompDataWrite)> m_stReprogInfo.ulMemorySizeExpected) && (TRUE == m_stReprogInfo.ubCompRequired))?BCOV(2270):!BCOV(2271))
    {
        /* Send NEGATIVE RESPONSE*/
        m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_71;
#if PROG_PEC_ENABLE == STD_ON
       /* set error in PEC */
        m_uwPEC = PROG_ERR_COMPRESSION;
#endif /* PROG_PEC_ENABLE == STD_ON*/
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);

        /* Send failed event PROG_HSM_PROG_EV_PROG_EVENT_FAILED */
        PROG_HsmEmit(&PROG_HsmScPROG,
                PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
    }
#else
    if(((m_stWriteInfo.ulWrittenData+ m_stWriteInfo.ulWriteLength +m_stReprogInfo.ulTotalDecompDataWrite)> ((stConfigSegment[m_stCurrentSegment.ubSegmentId].ulEraseEndAddress
                            - stConfigSegment[m_stCurrentSegment.ubSegmentId].ulEraseStartAddress)
                            + 1U) && (TRUE == m_stReprogInfo.ubCompRequired))?BCOV(2272):!BCOV(2273))
    {

        /* Send NEGATIVE RESPONSE*/
        m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_72;
#if PROG_PEC_ENABLE == STD_ON
       /* set error in PEC */
        m_uwPEC = PROG_ERR_COMPRESSION;
#endif /* PROG_PEC_ENABLE == STD_ON*/
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);

        /* Send failed event PROG_HSM_PROG_EV_PROG_EVENT_FAILED */
        PROG_HsmEmit(&PROG_HsmScPROG,
                PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
    }
#endif /*(PROG_RD_DATA_SIZE_TYPE == PROG_DECOMPRESSED_DATA_SIZE)*/
    else
#endif /* (PROG_COMPRESSION_ENABLE == STD_ON)*/
    {
#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
        if ((1U == m_stCurrentSegment.uwModuleId)?BCOV(2274):!BCOV(2275))
        {
            /* Start write operation */

            /* Calculate the write address                   */
            /* The Write/Erase is done with physical address */
#if (PROG_OTA_DUALBANK_USED == STD_ON)
            ulStartAddress = PROG_CustomCalcInactiveBankWriteAddr(m_stWriteInfo.ulAddressToWrite);
#else
            ulStartAddress = m_stWriteInfo.ulAddressToWrite;
#endif /*(PROG_OTA_DUALBANK_USED == STD_ON)*/

            eProgStatus = PROG_MemDataAccessByRegion(
                    m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,
                    PROG_MEM_OPERATION_TYPE_WRITE, ulStartAddress,
                    &m_stWriteInfo.ulWriteLength,
                    pubDataToWrite);
            /* Maybe not all data have been written */
#if (PROG_COMPRESSION_ENABLE == STD_ON)
            if ((TRUE == m_stReprogInfo.ubCompRequired)?BCOV(2276):!BCOV(2277))
            {
                /* set the data to be written value to exact number of data that will be written */
                m_stWriteInfo.ulDataToBeWritten = (m_stWriteInfo.ulWrittenData + m_stWriteInfo.ulWriteLength);
            }
#endif
        }
        else
#endif
        {
            /* Start write operation */

            /* Calculate the write address                   */
            /* The Write/Erase is done with physical address */
#if (PROG_OTA_DUALBANK_USED == STD_ON)
            ulStartAddress = PROG_CustomCalcInactiveBankWriteAddr(m_stWriteInfo.ulAddressToWrite);
#else
            ulStartAddress = m_stWriteInfo.ulAddressToWrite;
#endif /*(PROG_OTA_DUALBANK_USED == STD_ON)*/

            eProgStatus = PROG_MemDataAccess(
                    m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,
                    PROG_MEM_OPERATION_TYPE_WRITE, ulStartAddress,
                    m_stWriteInfo.ulWriteLength,
                    pubDataToWrite);
        }
        PROG_WriteStatusCheck(eProgStatus);
    }
    DBG_PROG_ENTRY_WRITE_EXIT();
}
/*--------------------------{end PROG_Entry_Write}-------------------------------*/
#endif /* if PROG_TRANSFER_DATA_ENABLE == STD_ON */

#if PROG_TRANSFER_DATA_ENABLE == STD_ON
/*-------------------------------{PROG_Write}------------------------------------*/
void PROG_Write(void)
{
#if ( (PROG_REPROGMEMM_ENABLED == STD_ON) \
      ||((PROG_FLASHWRAPPER_ENABLED == STD_ON) &&((PROG_FLASH_MODE == PROG_MEMORY_ASYNCHRONOUS) || (PROG_FLASH_EXT_MODE == PROG_MEMORY_ASYNCHRONOUS) || (PROG_CUSTOM_MEMORY_MODE == PROG_MEMORY_ASYNCHRONOUS))))
    tProgStatus eProgStatus;

    ICOV(2278);DBG_PROG_WRITE_ENTRY();

    /* Get Job result */
    eProgStatus = PROG_MemJobResult(
        m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType);

    PROG_WriteStatusCheck(eProgStatus);
#else
    ICOV(2279);DBG_PROG_WRITE_ENTRY();
#endif
    ICOV(2279);DBG_PROG_WRITE_EXIT();
}
/*-----------------------------{end PROG_Write}----------------------------------*/
#endif /* if PROG_TRANSFER_DATA_ENABLE == STD_ON */

#if PROG_TRANSFER_DATA_ENABLE == STD_ON
/*----------------------------{PROG_WriteCheck}----------------------------------*/
void PROG_WriteCheck(void)
{
    PduLengthType ulIdx;
    u32 ulMinValueToWrite;

#if (PROG_SIGNATURE_VERIFICATION_ON_FLASHED_DATA == STD_OFF)
#if ( (PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_CRY_PRESENT == STD_ON))
    tProgCryState eCryState;
#endif
#endif

#if ((PROG_SIGNATURE_VERIFICATION_ON_FLASHED_DATA == STD_OFF) && (PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_CRY_PRESENT == STD_ON))
    tProgStatus eProgCryptoFinished = PROG_E_OK;
#endif

#if (PROG_COMPRESSION_ENABLE == STD_ON)
#if (PROG_CAL_PRESENT == STD_OFF)
    tDecompressStateType eCompStatus = SA_DECOMP_FINISH;
#else
    tProgDecompressStateType eCompStatus = PROG_DECOMP_FINISH;
#endif
    PduLengthType ulDecompLength = 0U;
    u8 ubDecompNotWritten = FALSE;
#endif

#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
    tProgCryState eDecryptState;
    u32           ulMemoryEncryptedSizeExpected;
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/

    ICOV(2280);DBG_PROG_WRITECHECK_ENTRY();

    /* In case of verification on received data in the fly we must check if crypto finished */
    /* its computation on signature launched in PROG_Entry_TD before accepting the transition to TD_CRC state */
#if ((PROG_SIGNATURE_VERIFICATION_ON_FLASHED_DATA == STD_OFF) && (PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_CRY_PRESENT == STD_ON))
    if ((PROG_VERIFY_SIGNATURE == m_stDataProgVerification.ubAlgo)?BCOV(2281):!BCOV(2282))
    {
        eCryState = PROG_GetCryptoState();

        /* If crypto library finished its work */
        if (((eCryState != PROG_HASH_START) &&
            (eCryState != PROG_HASH_UPDATE) &&
            (eCryState != PROG_SIGNATURE_CHECK_START) &&
            (eCryState != PROG_SIGNATURE_CHECK_UPDATE) &&
            (eCryState != PROG_SIGNATURE_CHECK_FINISH))?BCOV(2283):!BCOV(2284))
        {
            /* Nothing to do as eProgCryptoFinished is already set to PROG_E_OK */
        }
        /* If crypto library didn't finish its work */
        else
        {
            /* Set the flag which mentions that the work is not finished  */
            eProgCryptoFinished = PROG_E_NOT_OK;
        }
    }
    /* For other Algo (Hash/CRC), no job has been launched so work is considered as finished */
    else
    {
        /* Nothing to do as eProgCryptoFinished is already set to PROG_E_OK */
    }
#endif

if (((m_ubWaitCryptoBeforeTdEnd != PROG_FALSE)
#if (PROG_COMPRESSION_ENABLE == STD_ON)
   || (m_ubDecompNotWritten == PROG_TRUE)
#endif
    )?BCOV(2285):!BCOV(2286))
    {
#if ((PROG_SIGNATURE_VERIFICATION_ON_FLASHED_DATA == STD_OFF) && (PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_CRY_PRESENT == STD_ON))
        /* crypto finished its work (signature) */
        if ((PROG_E_OK == eProgCryptoFinished)?BCOV(2287):!BCOV(2288))
#endif
        {
            m_ubDecompNotWritten = PROG_FALSE;
            m_ubWaitCryptoBeforeTdEnd = PROG_FALSE;
            /* emit event PROG_EVENT_TD_END now */
            PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_TD_END);
        }
    }
    /* Check if no error happened */
    else if ((UDS_ACK == m_stDiagMessageInfo.ubDiagStatus)?BCOV(2289):!BCOV(2290))
    {
#if (PROG_COMPRESSION_ENABLE == STD_ON)
        if ((TRUE == m_stReprogInfo.ubCompRequired)?BCOV(2291):!BCOV(2292))
        {
            /* Get Decompressed Data */
#if (PROG_CAL_PRESENT == STD_OFF)
            eCompStatus = SA_GetDecompressedData(&m_stWriteInfo.pubDecompData, &ulDecompLength);
#else
            eCompStatus = PROG_GetDecompressedData(&m_stWriteInfo.pubDecompData, &ulDecompLength);
#endif
            /* Increment the number of data to be written*/
            m_stWriteInfo.ulDataToBeWritten += (u32)ulDecompLength;
        }
        else
        {
            /* Nothing */
        }
#endif  /* (PROG_COMPRESSION_ENABLE == STD_ON) */

        /* Is there enough data to write */
        ulMinValueToWrite = m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].ulMinValueToWrite;

        if ((m_stWriteInfo.ulDataToBeWritten >= m_stWriteInfo.ulWrittenData)?BCOV(2293):!BCOV(2294))
        {
            if (((u16)((m_stWriteInfo.ulDataToBeWritten
                            - m_stWriteInfo.ulWrittenData)
                            + m_stPageBuffer.ulOldDataLength)
                            >= ulMinValueToWrite)?BCOV(2295):!BCOV(2296))
            {
                if ((0U < m_stPageBuffer.ulOldDataLength)?BCOV(2297):!BCOV(2298))
                {
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
                        if ((m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)?BCOV(2299):!BCOV(2300))
                        {
                            /* Data are present in Page buffer, it shall be completed and written*/
                            for (ulIdx = 0U; (ulIdx <(ulMinValueToWrite - m_stPageBuffer.ulOldDataLength))?BCOV(2301):!BCOV(2302); ulIdx++)
                            {
                                m_stPageBuffer.aubData[m_stPageBuffer.ulOldDataLength + ulIdx] = m_stCryptoData.aubCryptoBuffer[ulIdx];
                            }
                        }
                        else
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
                        {
                            /* Data are present in Page buffer, it shall be completed and written*/
                            for (ulIdx = 0U; (ulIdx <(ulMinValueToWrite - m_stPageBuffer.ulOldDataLength))?BCOV(2303):!BCOV(2304); ulIdx++)
                            {
                                m_stPageBuffer.aubData[m_stPageBuffer.ulOldDataLength + ulIdx] = m_stDiagMessageInfo.pubData[2U + ulIdx];
                            }
                        }

                    /* Update NewDataLength added in the buffer */
                    m_stPageBuffer.ulNewDataLength = (u16)(ulMinValueToWrite - m_stPageBuffer.ulOldDataLength);
                }

                /* Emit event PROG_EVENT_WRITE */
                PROG_HsmEmit(&PROG_HsmScPROG,
                        PROG_HSM_PROG_EV_PROG_EVENT_WRITE);
            }
            else
            {
#if (PROG_COMPRESSION_ENABLE == STD_ON)
                /* Is decompression fully finished*/
#if  (PROG_CAL_PRESENT == STD_OFF)
                if ((eCompStatus != SA_DECOMP_FINISH)?BCOV(2305):!BCOV(2306))
#else
                if ((eCompStatus != PROG_DECOMP_FINISH)?BCOV(2307):!BCOV(2308))
#endif
                {
                    ubDecompNotWritten = TRUE;
                }
                else
#endif  /* (PROG_COMPRESSION_ENABLE == STD_ON) */
                {
                    /* Is TD received */
                    if ((m_stWriteInfo.ubTDReceived == TRUE)?BCOV(2309):!BCOV(2310))
                    {
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
                        PROG_ComputeTotalEncryptedDataWithAesCbcPkcs7(m_stReprogInfo.ulMemorySizeExpected, &ulMemoryEncryptedSizeExpected);
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON) */

#if ((PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CSM_DECRYPTION_ENABLE == STD_ON))
                        if ((  ((((m_stReprogInfo.ulReceivedSizeOfData + m_stDiagMessageInfo.ulLength) - 2U) == m_stReprogInfo.ulMemorySizeExpected))
                            ||((TRUE == m_stReprogInfo.ubCompRequired) &&
                               (m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)  &&
                               (m_ubFinishDecryption == PROG_TRUE))
                            ||((FALSE == m_stReprogInfo.ubCompRequired) &&
                               (m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)  &&
                               (((m_stReprogInfo.ulReceivedSizeOfData + m_stDiagMessageInfo.ulLength) - 2U) == ulMemoryEncryptedSizeExpected)))?BCOV(2311):!BCOV(2312))
#elif (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
                        if ((  ((((m_stReprogInfo.ulReceivedSizeOfData + m_stDiagMessageInfo.ulLength) - 2U) == m_stReprogInfo.ulMemorySizeExpected))
                            ||((m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)  &&
                               (((m_stReprogInfo.ulReceivedSizeOfData + m_stDiagMessageInfo.ulLength) - 2U) == ulMemoryEncryptedSizeExpected)))?BCOV(2313):!BCOV(2314))
#else
                            if (((((m_stReprogInfo.ulReceivedSizeOfData + m_stDiagMessageInfo.ulLength) - 2U) == m_stReprogInfo.ulMemorySizeExpected))?BCOV(2315):!BCOV(2316))
#endif
                        {
                            /* There is still data to write */
                            if ((m_stWriteInfo.ulDataToBeWritten > m_stWriteInfo.ulWrittenData)?BCOV(2317):!BCOV(2318))
                            {
                                if((m_stPageBuffer.ulOldDataLength > 0U)?BCOV(2319):!BCOV(2320))
                                {
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
                                        if ((m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)?BCOV(2321):!BCOV(2322))
                                        {
                                    /* Data are present in Page buffer, it shall be completed and written*/
                                    for(ulIdx = 0U; (ulIdx < (m_stWriteInfo.ulDataToBeWritten - m_stWriteInfo.ulWrittenData))?BCOV(2323):!BCOV(2324); ulIdx++)
                                    {
                                        m_stPageBuffer.aubData[m_stPageBuffer.ulOldDataLength + ulIdx]
                                                                    = m_stCryptoData.aubCryptoBuffer[m_stWriteInfo.ulWrittenData + ulIdx];
                                            }
                                        }
                                        else
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
                                        {
                                            /* Data are present in Page buffer, it shall be completed and written*/
                                            for(ulIdx = 0U; (ulIdx < (m_stWriteInfo.ulDataToBeWritten - m_stWriteInfo.ulWrittenData))?BCOV(2325):!BCOV(2326); ulIdx++)
                                            {
                                                m_stPageBuffer.aubData[m_stPageBuffer.ulOldDataLength + ulIdx]
                                                                    = m_stDiagMessageInfo.pubData[2U + m_stWriteInfo.ulWrittenData + ulIdx];
                                            }
                                        }

                                    m_stPageBuffer.ulNewDataLength = (u16)(m_stWriteInfo.ulDataToBeWritten - m_stWriteInfo.ulWrittenData);
                                }
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
                                    if ((m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)?BCOV(2327):!BCOV(2328))
                                    {
                                        eDecryptState = PROG_GetDecryptionState();
                                        if ((eDecryptState == PROG_DECRYPTION_FINISH_END)?BCOV(2329):!BCOV(2330))
                                        {
                                            /* Emit event PROG_EVENT_WRITE */
                                            PROG_HsmEmit(&PROG_HsmScPROG,
                                                         PROG_HSM_PROG_EV_PROG_EVENT_WRITE);
                                        }
                                        else
                                        {
#if (PROG_COMPRESSION_ENABLE == STD_ON)
                                            ubDecompNotWritten = TRUE;
#endif  /* (PROG_COMPRESSION_ENABLE == STD_ON) */
                                            /* Emit event PROG_EVENT_CRYPTO_FINISH */
                                            PROG_HsmEmit(&PROG_HsmScPROG,
                                                    PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH);
                                        }
                                    }
                                    else
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
                                    {
#if (PROG_COMPRESSION_ENABLE == STD_ON)
                                            ubDecompNotWritten = TRUE;
#endif  /* (PROG_COMPRESSION_ENABLE == STD_ON) */
                                        /* Emit event PROG_EVENT_WRITE */
                                        PROG_HsmEmit(&PROG_HsmScPROG,
                                                PROG_HSM_PROG_EV_PROG_EVENT_WRITE);
                                    }
                                }
                            /* There are no more data to write */
                            else
                            {
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
                                    if ((m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)?BCOV(2331):!BCOV(2332))
                                    {
                                        eDecryptState = PROG_GetDecryptionState();
                                        if ((eDecryptState == PROG_DECRYPTION_FINISH_END)?BCOV(2333):!BCOV(2334))
                                        {
                                              /* wait crypto to finish its work before sending TD END event */
                                              m_ubWaitCryptoBeforeTdEnd = PROG_TRUE;
                                        }
                                        else
                                        {
#if (PROG_COMPRESSION_ENABLE == STD_ON)
                                ubDecompNotWritten = TRUE;
#endif  /* (PROG_COMPRESSION_ENABLE == STD_ON) */
                                            /* Emit event PROG_EVENT_CRYPTO_FINISH */
                                            PROG_HsmEmit(&PROG_HsmScPROG,
                                                    PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH);
                                        }
                                    }
                                    else
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
                                    {
#if (PROG_COMPRESSION_ENABLE == STD_ON)
                                        ubDecompNotWritten = TRUE;
#endif  /* (PROG_COMPRESSION_ENABLE == STD_ON) */

                                /* wait crypto to finish its work before sending TD END event */
                                m_ubWaitCryptoBeforeTdEnd = PROG_TRUE;
                                    }
                            }
                        } /* if ((m_stReprogInfo.ulReceivedSizeOfData + m_stDiagMessageInfo.ulLength - 2)  ==  m_stReprogInfo.ulMemorySizeExpected)*/
                        /* There are no more data to write, and crypto finished its work (signature or Hash) */
                        else
                        {
#if (PROG_COMPRESSION_ENABLE == STD_ON)
                            ubDecompNotWritten = TRUE;
                            if ((FALSE == m_stReprogInfo.ubCompRequired)?BCOV(2335):!BCOV(2336))
#endif
                            {
                                /* Is there data to write */
                                if ((m_stWriteInfo.ulDataToBeWritten > m_stWriteInfo.ulWrittenData)?BCOV(2337):!BCOV(2338))
                                {
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
                                        if ((m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)?BCOV(2339):!BCOV(2340))
                                        {
                                            /* Data are present in Page buffer, it shall be completed and written*/
                                            for (ulIdx = 0U; (ulIdx < (m_stWriteInfo.ulDataToBeWritten-m_stWriteInfo.ulWrittenData))?BCOV(2341):!BCOV(2342); ulIdx++)
                                            {
                                                m_stPageBuffer.aubData[ulIdx] = m_stCryptoData.aubCryptoBuffer[m_stWriteInfo.ulWrittenData + ulIdx];
                                            }
                                        }
                                        else
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
                                        {
                                            /* Data are present in Page buffer, it shall be completed and written*/
                                            for (ulIdx = 0U; (ulIdx < (m_stWriteInfo.ulDataToBeWritten-m_stWriteInfo.ulWrittenData))?BCOV(2343):!BCOV(2344); ulIdx++)
                                            {
                                                m_stPageBuffer.aubData[ulIdx] = m_stDiagMessageInfo.pubData[2U + m_stWriteInfo.ulWrittenData + ulIdx];
                                            }
                                    }

                                    m_stPageBuffer.ulOldDataLength = (u16)(m_stWriteInfo.ulDataToBeWritten - m_stWriteInfo.ulWrittenData);
                                }
                            }

                            /* wait crypto to finish its work before sending TD END event */
                            m_ubWaitCryptoBeforeTdEnd = PROG_TRUE;
                        } /* else ((m_stReprogInfo.ulReceivedSizeOfData + m_stDiagMessageInfo.ulLength - 2)
                            ==  m_stReprogInfo.ulMemorySizeExpected) */
                    } /* if (m_stWriteInfo.ubTDReceived == TRUE) */
                    else
                    {
#if (PROG_COMPRESSION_ENABLE == STD_ON)
                        ubDecompNotWritten = TRUE;
#endif
                    }
                } /* else ( eCompStatus != SA_DECOMP_FINISH) */
            } /* else ((m_stWriteInfo.ulDataToBeWritten - m_stWriteInfo.ulWrittenData) >= PROG_MIN_VAL_TO_WRITE ) */
        } /* if (m_stWriteInfo.ulDataToBeWritten > m_stWriteInfo.ulWrittenData) */
        else
        {
#if (PROG_COMPRESSION_ENABLE == STD_ON)
            ubDecompNotWritten = TRUE;
#endif
        }
    } /* if (m_stCryptoData.ubOperationInProgress == PROG_NO_OPERATION_IN_PROGRESS) */
    else
    {
        if ((m_stWriteInfo.ubTDReceived == TRUE)?BCOV(2345):!BCOV(2346))
        {
            /* Emit event PROG_EVENT_FAILED*/
            PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
        }
        else
        {
            /* nothing to do, wait for TD transfer to finish */
        }
    }
#if (PROG_COMPRESSION_ENABLE == STD_ON)
    if (( (TRUE == ubDecompNotWritten) && (TRUE == m_stReprogInfo.ubCompRequired))?BCOV(2347):!BCOV(2348))
    {
        /* Decrement the number of data not written to avoid counting them twice */
        m_stWriteInfo.ulDataToBeWritten -= ulDecompLength;
    }
#endif
    DBG_PROG_WRITECHECK_EXIT();
}
/*--------------------------{end PROG_WriteCheck}--------------------------------*/
#endif /* if PROG_TRANSFER_DATA_ENABLE == STD_ON */

#if PROG_TRANSFER_DATA_ENABLE == STD_ON
/*--------------------------{PROG_Exit_TD_Write}---------------------------------*/
void PROG_Exit_TD_Write(void)
{
#if(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)
    u8* paubData;
    PduLengthType ulLen;
#endif

    ICOV(2349);DBG_PROG_EXIT_TD_WRITE_ENTRY();

    if (((PROG_TRUE == m_stWriteInfo.ubTDReceived) && (m_stDiagMessageInfo.ubDiagStatus == UDS_ACK))?BCOV(2350):!BCOV(2351))
    {
#if(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)
        if((PROG_TRUE == m_stMultipleBuffers.eResponsePending)?BCOV(2352):!BCOV(2353))
        {
            /* Send positive response */
            UDS_LongRequestEnd(PROG_TD_RESPONSE_SIZE, m_pubLastBufTxData, UDS_ACK);
        }
#else /*(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)*/
        {
            /* Send positive response */
            UDS_LongRequestEnd(PROG_TD_RESPONSE_SIZE, m_stDiagMessageInfo.pubTxData, UDS_ACK);
        }
#endif /*(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)*/
#if (PROG_COMPRESSION_ENABLE == STD_ON)
        /* Reset Decom variable of current TD */
        m_stWriteInfo.ulInDecompDataLength = 0;
#if ( PROG_CAL_PRESENT == STD_OFF)
        SA_DecompInputParamInit();
#else
        PROG_DecompInputParamInit();
#endif
#endif /* (PROG_COMPRESSION_ENABLE == STD_ON) */

        if ((m_stDiagMessageInfo.pubData[1] == m_stReprogInfo.ubBlockSequenceCounter)?BCOV(2354):!BCOV(2355))
        {
            PROG_IncrementBlockSequenceCounter();

            /* Increment total number of data received */
            m_stReprogInfo.ulReceivedSizeOfData += (u32)((u32)m_stDiagMessageInfo.ulLength - 2U);

#if (PROG_COMPRESSION_ENABLE == STD_ON)
            /* Increment total number decompress data written */
            m_stReprogInfo.ulTotalDecompDataWrite += m_stWriteInfo.ulWrittenData;
#endif /* (PROG_COMPRESSION_ENABLE == STD_ON) */
        }
        else
        {
            /* nothing to do */
            /* Same block sequence counter received */
            /* it shall not be changed */
        }
    }
    else
    {
        /* Nothing to do */
        /* TD request has not be fully received */
    }

    /* Reset all variable of current TD */
    m_stWriteInfo.ulDataToBeWritten = 0U;
    m_stWriteInfo.ulWriteLength = 0U;
    m_stWriteInfo.ulWrittenData = 0U;
    m_stWriteInfo.ubTDReceived = PROG_FALSE;
#if (PROG_COMPRESSION_ENABLE == STD_ON)
    /* Reset Decom variable of current TD */
    m_stWriteInfo.ulInDecompDataLength = 0;
#endif /* (PROG_COMPRESSION_ENABLE == STD_ON) */

    m_ubTDReceive = PROG_FALSE;
#if(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)
    m_stMultipleBuffers.eResponsePending = PROG_FALSE;
    BlPduR_UnlockBuffer(BLPDUR_OLD_BUFFER);
    BlPduR_GetNextBuffer(&ulLen,&paubData);

    if((paubData != NULL_PTR)?BCOV(2356):!BCOV(2357))
    {
        m_stDiagMessageInfo.pubData = paubData;
        m_stDiagMessageInfo.ulLength = ulLen;
        PROG_HsmEmit (&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD);
    }
    else
    {
        m_stMultipleBuffers.eBufferProcessing  = PROG_FALSE;

        /* Look if there was a pending event for another request */
        if ((m_stEventInfo.Event != PROG_NO_EVENT)?BCOV(2358):!BCOV(2359))
        {
            /* Store request information */
            m_stDiagMessageInfo.pubData = m_stEventInfo.Data;
            m_stDiagMessageInfo.pubTxData = m_stEventInfo.Data;
            m_stDiagMessageInfo.ulLength = m_stEventInfo.Length;

            /* Post Event in state machine */
            PROG_HsmEmit(&PROG_HsmScPROG, m_stEventInfo.Event);
            m_stEventInfo.Event = PROG_NO_EVENT;
        }

    }
#endif /*(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)*/

    DBG_PROG_EXIT_TD_WRITE_EXIT();
}
#endif /* if PROG_TRANSFER_DATA_ENABLE == STD_ON */
/*------------------------{end PROG_Exit_TD_Write}-------------------------------*/

#if PROG_REQUEST_TRANSFER_EXIT_ENABLE == STD_ON
/*-------------------------{PROG_Entry_RTEFailed}--------------------------------*/
void PROG_Entry_RTEFailed(void)
{
#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
    u8 ubPartitionId = 0U;
    u8 ubModuleIndex;
    tProgStatus eProgStatus;
#endif

#if (PROG_CRY_PRESENT == STD_ON)
#if ((PROG_IMPL_VARIANT == PROG_IMPL_3) || (PROG_IMPL_VARIANT == PROG_IMPL_4)||(PROG_IMPL_VARIANT == PROG_IMPL_90) || \
    (PROG_IMPL_VARIANT == PROG_IMPL_91) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
    tProgStatus eProgStatus;
#endif
#endif
    ICOV(2360);DBG_PROG_ENTRY_RTEFAILED_ENTRY();

#if (PROG_CRY_PRESENT == STD_ON)
#if ((PROG_IMPL_VARIANT == PROG_IMPL_3) || (PROG_IMPL_VARIANT == PROG_IMPL_4)||(PROG_IMPL_VARIANT == PROG_IMPL_90) || \
    (PROG_IMPL_VARIANT == PROG_IMPL_91) || (PROG_IMPL_VARIANT == PROG_IMPL_5))

    eProgStatus = PROG_GetCryptoStatus();
    if ((eProgStatus == PROG_E_NOT_OK)?BCOV(2361):!BCOV(2362))
    {
        m_stDiagMessageInfo.ulLength = PROG_NRC_SIZE;
        m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_72;
    }
    else
    {
       /* If Crypto return ok, nothing to do */
       /* If Crypto is busy, nothing to do */
    }
#endif
#endif
    /* return status */
    UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
            m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);

#if ((PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
    (void)PROG_CustomSetDownloadVerificationSuccess(0U, m_stCurrentSegment.ubSegmentId, PROG_FALSE);
#endif
#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
    /* Get the partition ID */
    /* Check if Application or calibration programming */
#if (PROG_BOOT_PROT_PARTITIONS == STD_ON)
    /* Emit event PROG_EVENT_PARTITION_COMPLETE in case of protected calibration*/
    if((m_stCurrentSegment.uwModuleId == PROG_SW_APP_ID)?BCOV(2363):!BCOV(2364))
    {
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_PARTITION_COMPLETE);
    }
#endif
    if((m_stCurrentSegment.uwModuleId != PROG_SW_APP_ID)?BCOV(2365):!BCOV(2366))
    {
        eProgStatus = PROG_GetModulePartition(m_stCurrentSegment.uwModuleId, &ubPartitionId, &ubModuleIndex);

        if ((PROG_E_OK == eProgStatus)?BCOV(2367):!BCOV(2368))
        {
            /* Reset expectedModuleId for calibration programming */
            m_stReprogInfo.uwExpectedModuleId[ubPartitionId - 1U] = PROG_GET_CALIB_SW_FIRST_MODULE_ID(ubPartitionId);
        }
        else
        {
            /* Nothing to do */
        }
    }
#endif

    DBG_PROG_ENTRY_RTEFAILED_EXIT();
}
/*-------------------------{PROG_Entry_RTEFailed}--------------------------------*/

#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
/*-------------------------{PROG_CheckCalibrationPartitions}--------------------------------*/
void PROG_CheckCalibrationPartitions(void)
{
    tProgStatus eProgStatus = PROG_E_OK;
    u8 ubPartitionId;
    u8 ubModuleIndex;
    u32 ulStartAddress;
    u32 ulMemorySize;
    u8 ubLocalSegmentId;
    u8 ubRTEFailed = FALSE;
    u8 ubStoredSBIFlag;

#if (PROG_BOOT_PROT_PARTITIONS == STD_ON)
    u8 ubIdx;
    u8 ubcurrentSegmentId;
    u32 ulcurrentAddress;
    u8 ubProtectedCalibNotDefined = TRUE;
    u8 ubCCIDRecovered = FALSE;
    u16 uwModuleCCID;
    tUdsStatus eUdsStatus;
#endif

    ICOV(2369);if((m_stCurrentSegment.uwModuleId == PROG_SW_APP_ID)?BCOV(2370):!BCOV(2371))
    {
        for(ubPartitionId = 2U; (((ubPartitionId < (PROG_GET_CALIB_PARTITION_NB + 2U))
                && (eProgStatus == PROG_E_OK)))?BCOV(2372):!BCOV(2373); ubPartitionId++)
        {
#if (PROG_BOOT_PROT_PARTITIONS == STD_ON)
            /* Initialize the compatibility state variable */
            ubPartitionCompatibilityState = FALSE;
            /* Get Expected start adress for the first region of the current partition */
            ulcurrentAddress = PROG_GET_CALIB_SW_FIRST_REGION_ADDR_START(ubPartitionId);
            /* Call GetSegmentByAddress API to get the SegmentId of the current partition */
            eProgStatus = PROG_GetSegmentByAddress(ulcurrentAddress, 0U, PROG_MEM_OPERATION_TYPE_READ,  &ubcurrentSegmentId);
            if(((PROG_PROT_CALIBRATION_PARTITION == stConfigSegment[ubcurrentSegmentId].ePartitionType) && (eProgStatus == PROG_E_OK))?BCOV(2374):!BCOV(2375))
            {
                /* Check if the protected calibrations are defined*/
                for(ubIdx = 0U; ((ubIdx < PROG_BOOT_MAX_PROT_PARTITIONS) && (TRUE == ubProtectedCalibNotDefined))?BCOV(2376):!BCOV(2377); ubIdx++)
                {
                    if((m_stBootInfoBlock.aubProtectedCalibPartitionID[ubIdx] == ubPartitionId)?BCOV(2378):!BCOV(2379))
                    {
                        ubProtectedCalibNotDefined = FALSE;
                        ubRTEFailed = FALSE;
                     }
               }
                if ((ubProtectedCalibNotDefined == FALSE)?BCOV(2380):!BCOV(2381))
                {
                    eProgStatus = PROG_CheckPSIValue(ubPartitionId,PROG_PSI_PROGRAMMED);
                    if ((eProgStatus != PROG_E_OK)?BCOV(2382):!BCOV(2383))
                    {
                        /* Invalid or revoked PSI State : Nothing to do. The compatibility check is not done */
                    }
                    else
                    {
                        /* PSI state is Programmed : Set Partition Compatible state to TRUE for the current Protected Calibration in order to only perfom
                        * compatibility check for programmed partitions
                        */
                        ubPartitionCompatibilityState = TRUE;
                    }
                }
                else
                {
#if PROG_PEC_ENABLE == STD_ON
                    /*Protected calibration is not defined*/
                    m_uwPEC = PROG_ERR_PROTECTEDCAL_NOT_DEFINED;
#endif
                    ubRTEFailed = TRUE;
                }
            }
#endif
            for(ubModuleIndex = 0U; (((ubModuleIndex < PROG_GET_CALIB_SW_MODULE_NBR(ubPartitionId))
                    && (eProgStatus == PROG_E_OK)))?BCOV(2384):!BCOV(2385); ubModuleIndex++)
            {
                /* Check Cal SW Location Info */
                ulStartAddress = PROG_GET_CALIB_SW_MODULE_ADDR(ubPartitionId,ubModuleIndex);

                ulMemorySize = PROG_GET_CALIB_SW_MODULE_SIZE(ubPartitionId,ubModuleIndex);
                /* Check address */
                eProgStatus = PROG_GetSegmentByAddress
                                (ulStartAddress, ulMemorySize,
                                    PROG_MEM_OPERATION_TYPE_WRITE,
                                    &ubLocalSegmentId);

                if((eProgStatus != PROG_E_OK)?BCOV(2386):!BCOV(2387))
                {
#if PROG_PEC_ENABLE == STD_ON
                    m_uwPEC = PROG_ERR_CAL_REGION;
#endif
                    ubRTEFailed = TRUE;
                }
                else
                {
#if (PROG_BOOT_PROT_PARTITIONS == STD_ON)
                    /* Check Partition compatibility in case of Protected Calibration. Check is only performed for partitions with PSI = Programmed */
                    if(((PROG_PROT_CALIBRATION_PARTITION == stConfigSegment[ubcurrentSegmentId].ePartitionType) && (ubPartitionCompatibilityState == TRUE))?BCOV(2388):!BCOV(2389))
                    {
                        /* Extract the current module CCID value (The CCID is always written at the beginning of each module) */
                        eProgStatus = PROG_MemDataAccess( m_astCfgMemory[stConfigSegment[ubcurrentSegmentId].ubMemoryIdx].eMemoryType,
                                                        PROG_MEM_OPERATION_TYPE_READ, ulStartAddress + PROG_MODULE_CCID_ADDR_OFFSET,
                                                        PROG_MODULE_INFO_CCID_SIZE, m_aubModuleCCID);
                        if ((PROG_E_OK == eProgStatus)?BCOV(2390):!BCOV(2391))
                        {
                            /* Able to recover CCID value */
                            ubCCIDRecovered = TRUE;
                        }
                        else
                        {
                            /* Unable to recover CCID : Revoke the partition */
                            PROG_WritePSIValue(ubPartitionId, PROG_PSI_REVOKED, &eUdsStatus);
                            /*Error during PSI write*/
                            if((eUdsStatus != UDS_ACK)?BCOV(2392):!BCOV(2393))
                            {
#if PROG_PEC_ENABLE == STD_ON
                                /* Set error in PEC */
                                m_uwPEC = PROG_ERR_REVOKE_CAL;
#endif
                                ubRTEFailed = TRUE;
                            }
                        }
                        if ((TRUE == ubCCIDRecovered)?BCOV(2394):!BCOV(2395))
                        {
                           /* Get the module CCID received in the Application SW Info */
                           uwModuleCCID = PROG_GET_CALIB_SW_MODULE_CCID(ubPartitionId,ubModuleIndex);
                           /* Compare module CCID with App SW Info value */
                           if ((( 0xFFFFU == uwModuleCCID)
                               || ((m_aubModuleCCID[0] == 0xFFU) && (m_aubModuleCCID[1] == 0xFFU))
                               || ((m_aubModuleCCID[0] == (u8) ((uwModuleCCID >> 8U))) && (m_aubModuleCCID[1] == (u8)(uwModuleCCID))))?BCOV(2396):!BCOV(2397))
                            {
                                /* Protected Calibration module is compatible*/
                            }
                            else
                            {
                                /* Protected Calibration module is NOT compatible : Set Partition Compatible state to False for the current Protected Calibration*/
                                ubPartitionCompatibilityState = FALSE;
                                /* Revoke the not compatible partition */
                                PROG_WritePSIValue(ubPartitionId, PROG_PSI_REVOKED, &eUdsStatus);
                                /*Error during PSI write*/
                                if((eUdsStatus != UDS_ACK)?BCOV(2398):!BCOV(2399))
                                {
#if PROG_PEC_ENABLE == STD_ON
                                    /* Set error in PEC */
                                    m_uwPEC = PROG_ERR_REVOKE_CAL;
#endif
                                    ubRTEFailed = TRUE;
                                }
                            }
                        }
                    }
#endif
                }
                if ((TRUE == ubRTEFailed)?BCOV(2400):!BCOV(2401))
                {
                    m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_24;
                    /* Go to RTE error state, emit event PROG_EVENT_FAILED*/
                    PROG_HsmEmit (&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
                }
            }
        }
    }

    if((FALSE == ubRTEFailed)?BCOV(2402):!BCOV(2403))
    {
        ubStoredSBIFlag = PROG_GetSBIFlagValue();
        if((ubStoredSBIFlag == FALSE)?BCOV(2404):!BCOV(2405))
        {
            /* Go to VALIDATE_MESSAGE_DIGEST state, emit event PROG_EVENT_VALIDATE_MESSAGE_DIGEST*/
            PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_VALIDATE_MESSAGE_DIGEST);
        }
        else
        {
            /* emit event PROG_EVENT_FINISHED*/
            PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
        }
    }
}
#endif
/*-------------------------{PROG_CheckCalibrationPartitions}--------------------------------*/

#if (PROG_IMPL_VARIANT == PROG_IMPL_40)
/*----------------------------{PROG_Exit_RTE_Decrypt}-----------------------------------*/
void PROG_Exit_RTE_Decrypt(void)
{
    ICOV(2406);DBG_PROG_EXIT_RTE_DECRYPT_ENTRY();

#if (PROG_COMPRESSION_ENABLE == STD_ON)
    /* Increment total number decompress data written */
    m_stReprogInfo.ulTotalDecompDataWrite += m_stWriteInfo.ulWrittenData;
    m_stWriteInfo.ulInDecompDataLength = 0;

#if (PROG_CAL_PRESENT == STD_ON)
    PROG_DecompInputParamInit();
#endif

#endif /*(PROG_COMPRESSION_ENABLE == STD_ON) */

    /* Reset all variable of current TD */
    m_stWriteInfo.ulDataToBeWritten = 0U;
    m_stWriteInfo.ulWriteLength = 0U;
    m_stWriteInfo.ulWrittenData = 0U;
    m_stWriteInfo.ubTDReceived = PROG_FALSE;
    m_ubTDReceive = PROG_FALSE;

    DBG_PROG_EXIT_RTE_DECRYPT_EXIT();
}
#endif
/*-------------------------{PROG_Exit_RTE_Decrypt}--------------------------------*/

/*----------------------------{PROG_Entry_RTE}-----------------------------------*/
void PROG_Entry_RTE(void)
{

    u8 ubRTEFailed;
#if(PROG_HSM_UPDATE_ENABLE == STD_ON)
    tProgPECError uwHsmPEC;
#endif

#if  (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
    u32 ulMemoryEncryptedSizeExpected;
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON) */
    ICOV(2407);DBG_PROG_ENTRY_RTE_ENTRY();

    ubRTEFailed= TRUE;

#if  (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
    PROG_ComputeTotalEncryptedDataWithAesCbcPkcs7(m_stReprogInfo.ulMemorySizeExpected, &ulMemoryEncryptedSizeExpected);
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON) */

    /* Check request length*/
    if ((m_stDiagMessageInfo.ulLength == PROG_RTE_SIZE)?BCOV(2408):!BCOV(2409))
    {
#if(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)
        if ((UDS_ACK == m_stDiagMessageInfo.ubDiagStatus)?BCOV(2410):!BCOV(2411))
#endif
        {
            /* Check if all data have been received */
#if (PROG_COMPRESSION_ENABLE == STD_ON)
#if (PROG_RD_DATA_SIZE_TYPE == PROG_DECOMPRESSED_DATA_SIZE)
            if ((TRUE == m_stReprogInfo.ubCompRequired)?BCOV(2412):!BCOV(2413))
            {
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
                if ((m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)?BCOV(2414):!BCOV(2415))
                {
                    if((m_ubFinishDecryption == PROG_TRUE)?BCOV(2416):!BCOV(2417))
                    {
                        /* compare to decompressed data size */
                        if ((m_stReprogInfo.ulTotalDecompDataWrite == m_stReprogInfo.ulMemorySizeExpected)?BCOV(2418):!BCOV(2419))
                         {
                             ubRTEFailed = FALSE;
                         }
                         else
                         {
                              /* Nothing to do*/
                         }
                    }
                    else
                    {
#if((PROG_CSM_DECRYPTION_ENABLE == STD_ON)&& (PROG_COMPRESSION_ENABLE == STD_ON))
                        m_ubRTEReceived = TRUE;
#endif
                        m_stWriteInfo.ubTDReceived = TRUE;
                        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH);
                    }
                }
                else
#endif /*(PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
                {
                     /* compare to decompressed data size */
                     if ((m_stReprogInfo.ulTotalDecompDataWrite == m_stReprogInfo.ulMemorySizeExpected)?BCOV(2420):!BCOV(2421))
                     {
                          ubRTEFailed = FALSE;
                     }
                     else
                     {
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
                        m_stWriteInfo.ubTDReceived = TRUE;
                        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH);
#elif ((PROG_CSM_DECRYPTION_ENABLE != STD_ON) && (PROG_COMPRESSION_ENABLE == STD_ON))
                        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_WRITE);
#endif
                     }

                }
            }
            else
            {
                /* compare to size of the data transferred using TD service */
                if (( (m_stReprogInfo.ulReceivedSizeOfData
                          == m_stReprogInfo.ulMemorySizeExpected)
#if  (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
                   ||( (m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS) &&
                       (m_stReprogInfo.ulReceivedSizeOfData  == ulMemoryEncryptedSizeExpected)
                     )
#endif /* #if  (PROG_CSM_DECRYPTION_ENABLE == STD_ON) */
                   )?BCOV(2422):!BCOV(2423))
                {
                    ubRTEFailed = FALSE;
                }
                else
                {
                     m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_24;
                     /* emit event PROG_EVENT_FAILED*/
                     PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
                }
            }
#else /*(PROG_RD_DATA_SIZE_TYPE != PROG_DECOMPRESSED_DATA_SIZE)*/
            /* compare to size of the data transferred using TD service */
            if (( (m_stReprogInfo.ulReceivedSizeOfData == m_stReprogInfo.ulMemorySizeExpected)
#if  (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
               ||( (m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS) &&
                   (m_stReprogInfo.ulReceivedSizeOfData  == ulMemoryEncryptedSizeExpected)
                 )
#endif /*  (PROG_CSM_DECRYPTION_ENABLE == STD_ON)  */
                  )?BCOV(2424):!BCOV(2425))
                 {
                      ubRTEFailed = FALSE;
                 }
                 else
                 {
                     m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_24;
                     /* emit event PROG_EVENT_FAILED*/
                     PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
                 }
#endif /*(PROG_RD_DATA_SIZE_TYPE == PROG_DECOMPRESSED_DATA_SIZE)*/
#else  /*(PROG_COMPRESSION_ENABLE != STD_ON)*/
            /* compare to size of the data transferred using TD service */
            if ((  (m_stReprogInfo.ulReceivedSizeOfData
                    == m_stReprogInfo.ulMemorySizeExpected)
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
                   ||( (m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS) &&
                       (m_stReprogInfo.ulReceivedSizeOfData == ulMemoryEncryptedSizeExpected)
                      )

#endif /*  (PROG_CSM_DECRYPTION_ENABLE == STD_ON)  */
                   )?BCOV(2426):!BCOV(2427))
            {
                ubRTEFailed = FALSE;
            }
            else
            {
                /* Nothing to do */
            }
#endif /*(PROG_COMPRESSION_ENABLE == STD_ON)*/
            if ((m_ubTDReceive == PROG_FALSE)?BCOV(2428):!BCOV(2429))
            {
                 ubRTEFailed = FALSE;
            }
            if((FALSE == ubRTEFailed)?BCOV(2430):!BCOV(2431))
            {
#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
#if(PROG_HSM_UPDATE_ENABLE == STD_ON)
                if((stConfigSegment[m_stCurrentSegment.ubSegmentId].ePartitionType == PROG_HSM_PARTITION)?BCOV(2432):!BCOV(2433))
                {
                    /*Call the API PROG_HSM_RTEUpdate to read the HSM update request status*/
                    uwHsmPEC = PROG_HSMLastDataReceived();

                    if((uwHsmPEC == PROG_PEC_NO_ERROR)?BCOV(2434):!BCOV(2435))
                    {
                        m_stDiagMessageInfo.ubDiagStatus = UDS_ACK;
                    }
                    else
                    {
                        m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_72;
                        m_uwPEC = uwHsmPEC;
                    }
                    /* emit event PROG_EVENT_FINISHED*/
                    PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
                }
                else
#endif
                {
                    PROG_CheckCalibrationPartitions();
                }

#elif (PROG_VERIFICATION_ON_THE_FLY == STD_OFF)
                /* emit event PROG_EVENT_FINISHED as no checksum computation is required here*/
                PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
#else
            /* Nothing to do */
#endif
            }
#if ((PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CSM_DECRYPTION_ENABLE == STD_ON))
            else if (((TRUE == m_stReprogInfo.ubCompRequired) &&
                    (m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)  &&
                    (m_ubFinishDecryption == PROG_FALSE))?BCOV(2436):!BCOV(2437))
                {
                    /* Nothing to do */
                }
#endif /* ((PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CSM_DECRYPTION_ENABLE == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_40))*/

            else
            {
#if ( (PROG_IMPL_VARIANT == PROG_IMPL_20) && (PROG_PEC_ENABLE == STD_ON) )
                m_uwPEC = PROG_ERR_MORE_DATA_EXPECTED;
#endif
                m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_24;

                /* Go to RTE error state, emit event PROG_EVENT_FAILED*/
                PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
            }
        }
#if(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)
        else
        {
            /* Go to RTE error state, emit event PROG_EVENT_FAILED*/
            PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
        }
#endif
    }
    else
    {
        m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_13;

        /* Go to RTE error state, emit event PROG_EVENT_FAILED*/
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
    }

    /* Reset RD received flag*/
    m_stReprogInfo.ubRDReceived = FALSE;

    DBG_PROG_ENTRY_RTE_EXIT();
}
/*--------------------------{end PROG_Entry_RTE}---------------------------------*/
#endif /* if PROG_REQUEST_TRANSFER_EXIT_ENABLE == STD_ON */


#if PROG_REQUEST_TRANSFER_EXIT_ENABLE == STD_ON
#if ((PROG_IMPL_VARIANT == PROG_IMPL_1)  || (PROG_IMPL_VARIANT == PROG_IMPL_2) || \
     (PROG_IMPL_VARIANT == PROG_IMPL_3)  || (PROG_IMPL_VARIANT == PROG_IMPL_4) || \
     (PROG_IMPL_VARIANT == PROG_IMPL_10) || (PROG_IMPL_VARIANT == PROG_IMPL_11)|| \
     (PROG_IMPL_VARIANT == PROG_IMPL_90) || (PROG_IMPL_VARIANT == PROG_IMPL_91)|| \
     (PROG_IMPL_VARIANT == PROG_IMPL_60) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
/*-------------------------------{PROG_RTE}--------------------------------------*/
void PROG_RTE(void)
{
#if ((PROG_CRC_CALCULATION == PROG_TD_CRC16) || (PROG_IMPL_VARIANT == PROG_IMPL_3) || \
    (PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
    tProgStatus eProgStatus = PROG_E_NOT_OK;
#endif

    ICOV(2438);DBG_PROG_RTE_ENTRY();

#if ((PROG_CRC_CALCULATION == PROG_TD_CRC16) || (PROG_IMPL_VARIANT == PROG_IMPL_3) || (PROG_IMPL_VARIANT == PROG_IMPL_4) || \
    (PROG_IMPL_VARIANT == PROG_IMPL_90)||(PROG_IMPL_VARIANT == PROG_IMPL_91) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
    eProgStatus = PROG_CRC();

    if((eProgStatus == PROG_E_OK)?BCOV(2439):!BCOV(2440))
    {
#if (PROG_CRC_CALCULATION == PROG_TD_CRC16)
#if ((PROG_IMPL_VARIANT != PROG_IMPL_90)&&(PROG_IMPL_VARIANT != PROG_IMPL_91))
        /* prepare response */
        m_stDiagMessageInfo.pubData[1] = (u8)(
                (u16)(m_stDataProgVerification.uwVal >> 8U) & 0x00FFU);
        m_stDiagMessageInfo.pubData[2] = (u8)(
                m_stDataProgVerification.uwVal & 0x00FFU);

        /* Go to RTE FINISH state, emit event PROG_HSM_PROG_EV_PROG_EVENT_FINISHED*/
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
#endif/*((PROG_IMPL_VARIANT != PROG_IMPL_90)&&(PROG_IMPL_VARIANT != PROG_IMPL_91))*/
#elif ((PROG_IMPL_VARIANT == PROG_IMPL_3) || (PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
        /* Send Event Finished event */
        PROG_ComputeHashFinish(&m_aubComputedMessageDigest[0]);
#if (PROG_CRY_PRESENT == STD_ON)
        eProgStatus = PROG_GetCryptoStatus();
#endif
        /* If errors occurred */
        if ((PROG_E_NOT_OK == eProgStatus)?BCOV(2441):!BCOV(2442))
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
    else if((eProgStatus == PROG_E_BUSY)?BCOV(2443):!BCOV(2444))
    {
        /* CRC or Hash in progress nothing to do */
    }
    else
    {

#if((PROG_IMPL_VARIANT == PROG_IMPL_90)||(PROG_IMPL_VARIANT == PROG_IMPL_91))
        m_stDiagMessageInfo.ulLength = PROG_NRC_SIZE;
        m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_72;
#endif
        /* Go to RTE error state, emit event PROG_EVENT_FAILED*/
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
    }
#endif /*((PROG_CRC_CALCULATION == PROG_TD_CRC16) || (PROG_IMPL_VARIANT == PROG_IMPL_3) || (PROG_IMPL_VARIANT == PROG_IMPL_4)
         ||(PROG_IMPL_VARIANT == PROG_IMPL_5))*/
    DBG_PROG_RTE_EXIT();
}
/*-----------------------------{end PROG_RTE}-------------------------------------*/
#endif /* if PROG_REQUEST_TRANSFER_EXIT_ENABLE == STD_ON */
#endif /* (PROG_IMPL_VARIANT != PROG_IMPL_20) && (PROG_IMPL_VARIANT != PROG_IMPL_30) &&
    (PROG_IMPL_VARIANT != PROG_IMPL_40) && (PROG_IMPL_VARIANT != PROG_IMPL_50) */



#if PROG_REQUEST_TRANSFER_EXIT_ENABLE == STD_ON
/*-------------------------{PROG_Entry_RTEFinish}--------------------------------*/
void PROG_Entry_RTEFinish(void)
{
#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
    u8 ubPartitionId;
    u8 ubModuleIndex;
#elif ((PROG_IMPL_VARIANT == PROG_IMPL_3) || (PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
    u8 ubLoopIndex;
#endif
    ICOV(2445);DBG_PROG_ENTRY_RTEFINISH_ENTRY();
#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
    ubPartitionId = 0U;
    ubModuleIndex = 0U;
    DBG_PROG_ENTRY_RTEFINISH_ENTRY();

#if(PROG_HSM_UPDATE_ENABLE == STD_ON)
    /* Check if Application or calibration programming */
    if((stConfigSegment[m_stCurrentSegment.ubSegmentId].ePartitionType == PROG_HSM_PARTITION)?BCOV(2446):!BCOV(2447))
    {
        /* Emit event PROG_EVENT_PARTITION_COMPLETE*/
        PROG_HsmEmit (&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_PARTITION_COMPLETE);
        /* return status */
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);
    }
    else
#endif
    {
        /* Check if Application or calibration programming */
        if((m_stCurrentSegment.uwModuleId != PROG_SW_APP_ID)?BCOV(2448):!BCOV(2449))
        {
            (void)PROG_GetModulePartition( m_stCurrentSegment.uwModuleId, &ubPartitionId, &ubModuleIndex);

            if((ubModuleIndex == ((PROG_GET_CALIB_SW_MODULE_NBR(ubPartitionId))-1U) )?BCOV(2450):!BCOV(2451))
            {
                /* Emit event PROG_EVENT_PARTITION_COMPLETE*/
                PROG_HsmEmit (&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_PARTITION_COMPLETE);
            }
            else
            {
                /* Update next expected module */
                m_stReprogInfo.uwExpectedModuleId[ubPartitionId - 1U] = PROG_GET_CALIB_SW_MODULE_ID(ubPartitionId,(ubModuleIndex+1U));
            }
        }
        else
        {
            /* Emit event PROG_EVENT_PARTITION_COMPLETE*/
            PROG_HsmEmit (&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_PARTITION_COMPLETE);
        }
    }
#else
    DBG_PROG_ENTRY_RTEFINISH_ENTRY();
#endif

#if (PROG_SEG_LIST_CKS == STD_ON)
    /*Update Segment list for CRC calculation */
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
      if ((m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)?BCOV(2452):!BCOV(2453))
      {
#if(PROG_COMPRESSION_ENABLE == STD_ON)
          if((m_stReprogInfo.ubCompRequired == TRUE)?BCOV(2454):!BCOV(2455))
          {
              m_ubFinishDecryption = PROG_FALSE;
              m_stSegList.astSeg[m_stSegList.ubSegNbr].ulSize = m_stReprogInfo.ulTotalDecompDataWrite;
          }
          else
#endif /*(PROG_COMPRESSION_ENABLE == STD_ON)*/
          {
              m_stSegList.astSeg[m_stSegList.ubSegNbr].ulSize = m_stCryptoData.ulTotDecryptedWrittenSize;
          }
      }
      else
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
      {
#if(PROG_COMPRESSION_ENABLE == STD_ON)
          if((m_stReprogInfo.ubCompRequired == TRUE)?BCOV(2456):!BCOV(2457))
          {
               m_stSegList.astSeg[m_stSegList.ubSegNbr].ulSize = m_stReprogInfo.ulTotalDecompDataWrite;
          }
          else
#endif /*(PROG_COMPRESSION_ENABLE == STD_ON)*/
          {
              m_stSegList.astSeg[m_stSegList.ubSegNbr].ulSize = m_stCurrentSegment.ulSize;
          }
      }

#if (PROG_IMPL_VARIANT == PROG_IMPL_11) || (PROG_IMPL_VARIANT == PROG_IMPL_91)
    m_stSegList.ubSegListCrcIndex++;
    m_stSegList.astSeg[m_stSegList.ubSegListCrcIndex].ubSegmentId = m_stSegList.ubSegListCrcIndex;
#else
    m_stSegList.astSeg[m_stSegList.ubSegNbr].ubSegmentId = m_stCurrentSegment.ubSegmentId;
#endif

    m_stSegList.astSeg[m_stSegList.ubSegNbr].ulStartAddress = m_stCurrentSegment.ulStartAddress;
    m_stSegList.ubSegNbr++;

#endif /*(PROG_SEG_LIST_CKS == STD_ON)*/
#if ((PROG_IMPL_VARIANT == PROG_IMPL_3) || (PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
    for (ubLoopIndex = 0; (((ubLoopIndex < PROG_DIGEST_LENGTH)))?BCOV(2458):!BCOV(2459);  ubLoopIndex++)
    {
        /* update RTE response with the calculated hash value */
        m_stDiagMessageInfo.pubTxData[PROG_RTE_RESPONSE_BASE_INDEX + ubLoopIndex] = m_aubComputedMessageDigest[ubLoopIndex];
    }
    UDS_LongRequestEnd(PROG_RTE_RESPONSE_BASE_INDEX + PROG_DIGEST_LENGTH, m_stDiagMessageInfo.pubTxData,
                UDS_ACK);
    PROG_StoreVerificationDataStructure(&m_stCurrentSegment, m_aubComputedMessageDigest);
#elif ((PROG_IMPL_VARIANT == PROG_IMPL_90) || (PROG_IMPL_VARIANT == PROG_IMPL_91))
    /* update RTE response with the calculated CRC value */
    m_stDiagMessageInfo.pubTxData[PROG_RTE_RESPONSE_BASE_INDEX] = (u8)(m_stDataProgVerification.uwVal >> 8U);
    m_stDiagMessageInfo.pubTxData[PROG_RTE_RESPONSE_BASE_INDEX +1U] = (u8)(m_stDataProgVerification.uwVal);
    UDS_LongRequestEnd(PROG_RTE_RESPONSE_SIZE, m_stDiagMessageInfo.pubTxData,
                UDS_ACK);
#else
    /* return status */
    UDS_LongRequestEnd(PROG_RTE_RESPONSE_SIZE, m_stDiagMessageInfo.pubTxData,
            UDS_ACK);
#endif /*((PROG_IMPL_VARIANT == PROG_IMPL_3) || (PROG_IMPL_VARIANT == PROG_IMPL_4) ||(PROG_IMPL_VARIANT == PROG_IMPL_5))*/
#if PROG_RESUM_REPROG == STD_ON
    /* Store segment list for hash recomputation in case of resume */
    PROG_CustomStoreSegmentList(&m_stSegList);
#endif
    DBG_PROG_ENTRY_RTEFINISH_EXIT();
}
#endif /* if PROG_REQUEST_TRANSFER_EXIT_ENABLE == STD_ON */
/*-----------------------{end PROG_Entry_RTEFinish}------------------------------*/

#if (PROG_UPDATE_PSI_ENABLE == STD_ON)
/*-----------------------{PROG_Entry_UpdatePSI}----------------------------------*/
void PROG_Entry_UpdatePSI(void)
{
    tUdsStatus eUdsStatus;
    u8 ubPartitionId;
    u8 ubCurrentPartitionId = 0U;
    u8 ubModuleIndex = 0U;

    ICOV(2460);DBG_PROG_ENTRY_UPDATEPSI_ENTRY();

    ubPartitionId = m_stDiagMessageInfo.pubData[4];
#if(PROG_HSM_UPDATE_ENABLE == STD_ON)
    if((ubPartitionId == PROG_HSM_PARTITION_ID)?BCOV(2461):!BCOV(2462))
    {
        eUdsStatus = UDS_ACK;
        m_stDiagMessageInfo.ulLength = 4U;
    }
    else
#endif
    {
        if((m_stCurrentSegment.uwModuleId != PROG_SW_APP_ID)?BCOV(2463):!BCOV(2464))
        {
            (void)PROG_GetModulePartition(m_stCurrentSegment.uwModuleId, &ubCurrentPartitionId, &ubModuleIndex);
        }
        else
        {
            ubCurrentPartitionId = PROG_SW_APP_ID;
        }

        if(((ubPartitionId == ubCurrentPartitionId) && (m_uwPEC == PROG_PEC_NO_ERROR))?BCOV(2465):!BCOV(2466))
        {

            PROG_WritePSIValue(ubPartitionId, PROG_PSI_PROGRAMMED, &eUdsStatus);

            if((eUdsStatus == UDS_ACK)?BCOV(2467):!BCOV(2468))
            {
                /* prepare length for the response */
                m_stDiagMessageInfo.ulLength = 4U;

                if((ubPartitionId == PROG_SW_APP_ID)?BCOV(2469):!BCOV(2470))
                {
                    /* Update NBID */
                    PROG_SetNBIDValue(PROG_GET_U16_VAL(PROG_GET_APP_SW_NBID_ADDR));

                    PROG_SetKeyNBIDValue(m_uwKeyNBID);
                }
            }
        }
        else
        {
            eUdsStatus = UDS_NRC_22;
        }

#if (PROG_PEC_ENABLE == STD_ON)
    if((eUdsStatus == UDS_ACK)?BCOV(2471):!BCOV(2472))
    {
        /*Clear PEC */
        m_uwPEC = PROG_PEC_NO_ERROR;
    }
    else
    {
        /* Set PEC */
        m_uwPEC = PROG_ERR_UPDATE_PSI;
    }
#endif
    }
    UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength,
                                m_stDiagMessageInfo.pubTxData, eUdsStatus);

    DBG_PROG_ENTRY_UPDATEPSI_EXIT();
}
/*---------------------{end PROG_Entry_UpdatePSI}--------------------------------*/

/*-----------------------{PROG_WritePSIValue}----------------------------------*/
void PROG_WritePSIValue(u8 ubPartitionId, tProgPsiValue ePsiValue, tUdsStatus* peUdsStatus)
{
    tProgStatus eProgStatus;
    u32 ulPSIAddress;
    u8 ubLoop;
    u32 ulMinValueToWrite = m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].ulMinValueToWrite;
    u32 ulStartAddress;

    ICOV(2473);DBG_PROG_WRITEPSIVALUE_ENTRY(ubPartitionId, ePsiValue, peUdsStatus);

    *peUdsStatus = UDS_ACK;

    /* Get PSI Address */
    eProgStatus = PROG_GetPSIAddress(ubPartitionId, &ulPSIAddress);

    if((eProgStatus == PROG_E_OK)?BCOV(2474):!BCOV(2475))
    {
        /* Check if the Revoked or Programmed PSI area shall be written */
        if((ePsiValue == PROG_PSI_REVOKED)?BCOV(2476):!BCOV(2477))
        {
            /* Copy revoked PSI in buffer to write */
            for(ubLoop = 0U; (ubLoop < PROG_PSI_VAL_SIZE)?BCOV(2478):!BCOV(2479); ubLoop++)
            {
                m_aubPSIValue[ubLoop]= m_aCfgPSIRevokedValue[ubLoop];
            }

            /* Increment the address by one page to write the revoked page */
            ulPSIAddress += ulMinValueToWrite;
        }
        else
        {
            /* Copy programmed PSI in buffer to write */
            for(ubLoop = 0U; (ubLoop < PROG_PSI_VAL_SIZE)?BCOV(2480):!BCOV(2481); ubLoop++)
            {
                m_aubPSIValue[ubLoop]= m_aCfgPSIProgrammedValue[ubLoop];
            }
        }

        eProgStatus = PROG_MemCheckPageErasing(
                        m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,
                        ulPSIAddress);

        if((eProgStatus == PROG_E_OK)?BCOV(2482):!BCOV(2483))
        {
            /* Write PSI in Flash */
#if (PROG_OTA_DUALBANK_USED == STD_ON)
            /* The Write/Erase is done with physical address */
            ulStartAddress = PROG_CustomCalcInactiveBankWriteAddr(ulPSIAddress);
#else
            ulStartAddress = ulPSIAddress;
#endif /*(PROG_OTA_DUALBANK_USED == STD_ON)*/

            eProgStatus = PROG_MemDataAccess(
                    m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,
                    PROG_MEM_OPERATION_TYPE_WRITE,
                    ulStartAddress,
                    PROG_PSI_VAL_SIZE,
                    m_aubPSIValue);

            if((eProgStatus == PROG_E_OK)?BCOV(2484):!BCOV(2485))
            {
                eProgStatus = PROG_CheckPSIValue(ubPartitionId,ePsiValue);

                if((eProgStatus != PROG_E_OK)?BCOV(2486):!BCOV(2487))
                {
                    *peUdsStatus = UDS_NRC_72;
                }
            }
            else
            {
                *peUdsStatus = UDS_NRC_72;
            }
        }
    }
    else
    {
        *peUdsStatus = UDS_NRC_31;
    }

    DBG_PROG_WRITEPSIVALUE_EXIT();
}
/*---------------------{end PROG_WritePSIValue}--------------------------------*/
#endif /* (PROG_UPDATE_PSI_ENABLE == STD_ON) */


/*-------------------------------{PROG_CRC_Compare}--------------------------------------*/
tProgStatus PROG_CRC_Compare(void)
{
    tProgStatus eProgStatus = PROG_E_OK;
#if ((PROG_CRC_COMPUTE_COMPARE_ENABLE == STD_ON) || ((PROG_SEG_LIST_CKS == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_10) && (PROG_IMPL_VARIANT != PROG_IMPL_11) && (PROG_IMPL_VARIANT != PROG_IMPL_90) && (PROG_IMPL_VARIANT != PROG_IMPL_91)))
#if (((PROG_IMPL_VARIANT == PROG_IMPL_40) || (PROG_IMPL_VARIANT == PROG_IMPL_50) || (PROG_IMPL_VARIANT == PROG_IMPL_60)) && (PROG_CHECK_MEMORY_ENABLE == STD_ON))
    u8 ubIdx;
#endif
#if (PROG_RESUM_REPROG == STD_ON)
    u32 ulVerAddress;
#endif
#if (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON)
    u8 ubDgpStatus;
#endif /* (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON) */

#if(PROG_PARTIAL_VERIFY_CRC == STD_ON)
    u32 aulSegProgSize[PROG_MAX_RD_PER_BLOCK];
    u8 ubSegIndex;
#endif
#if (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_HASH)
    u8 ubLoopIndex;
#if ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_AUTHENTICATED_REPROG))
    u8 ubHashVerificationPerformed = PROG_FALSE;
#endif
#endif /*(PROG_VERIFICATION_METHOD == PROG_VERIFICATION_HASH)*/

    ICOV(2488);DBG_PROG_CRC_COMPARE_ENTRY();

#if ((PROG_VERIFICATION_METHOD == PROG_VERIFICATION_SIGNATURE) || (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_SIGNATURE_WITH_HASH))
    /* Signature verification */
#if (PROG_CRY_PRESENT == STD_ON)
    eProgStatus = PROG_GetCryptoStatus();
#endif
    if ((PROG_E_OK == eProgStatus)?BCOV(2489):!BCOV(2490))
#elif (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_IN_DFI)
    if ((m_ubVerificationMethod == PROG_VERIFICATION_SIGNATURE)?BCOV(2491):!BCOV(2492))
    {
      /* Signature verification */
  #if (PROG_CRY_PRESENT == STD_ON)
      eProgStatus = PROG_GetCryptoStatus();
  #endif
    }
    if ((PROG_E_OK == eProgStatus)?BCOV(2493):!BCOV(2494))
    {
      if (((m_ubVerificationMethod == PROG_VERIFICATION_SIGNATURE_AND_CRC)
#if (PROG_PARTIAL_VERIFY_CRC == STD_ON)
           || (m_ubActivePartialVerifyCrc == TRUE)
#endif
         )?BCOV(2495):!BCOV(2496))
      {
#if (PROG_CRC_CALCULATION == PROG_TD_CRC32)
        if((m_ulExpectedCks != m_stDataProgVerification.ulVal)?BCOV(2497):!BCOV(2498))
        {
             eProgStatus = E_NOT_OK;
        }
#endif
       }
    }
    if ((PROG_E_OK == eProgStatus)?BCOV(2499):!BCOV(2500))
#elif (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_HASH)
#if ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_AUTHENTICATED_REPROG))
    /* If the Block Headers check operation didn't return any error */
    if ((PROG_FALSE == m_ubBlockHeaderCheckFailed)?BCOV(2501):!BCOV(2502))
    {
#endif
        /* Signature verification */
#if (PROG_CRY_PRESENT == STD_ON)
        eProgStatus = PROG_GetCryptoStatus();
#endif
        if ((PROG_E_OK == eProgStatus)?BCOV(2503):!BCOV(2504))
        {
#if ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_AUTHENTICATED_REPROG))
            /* In case of Signature verification performed before */
            /* this flag is set to prepare the correct response in case of failure */
            /* Signature verification failure and Hash verification failure shall clearly identified */
            ubHashVerificationPerformed = PROG_TRUE;

            /* Check the remaining header data: TargetName, RollbackId, CompatibilityId and Uuid*/
            eProgStatus = PROG_CheckBlockHeaderCustomData(m_aubBlockHeader);

            if ((PROG_E_OK == eProgStatus)?BCOV(2505):!BCOV(2506))
#endif
            {
                for (ubLoopIndex = 0; (((ubLoopIndex < PROG_DIGEST_LENGTH)&&(PROG_E_OK == eProgStatus)))?BCOV(2507):!BCOV(2508); ubLoopIndex++)
                {
                    /* compare hash */
                    if ((m_aubComputedMessageDigest[ubLoopIndex] != m_aubMessageDigest[ubLoopIndex])?BCOV(2509):!BCOV(2510))
                    {
                        eProgStatus = PROG_E_NOT_OK;
                    }
                }
            }
        }
#if ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_AUTHENTICATED_REPROG))
    }
    /* If the Block Headers check operation returned any error */
    else
    {
        eProgStatus = PROG_E_NOT_OK;
    }
#endif

    /* If no errors occurred */
    if ((PROG_E_OK == eProgStatus)?BCOV(2511):!BCOV(2512))
#elif (PROG_CRC_CALCULATION == PROG_TD_CRC32)
    if((m_ulExpectedCks == m_stDataProgVerification.ulVal)?BCOV(2513):!BCOV(2514))
#elif (PROG_CRC_CALCULATION == PROG_TD_CRC16)
    if((m_uwExpectedCks == m_stDataProgVerification.uwVal)?BCOV(2515):!BCOV(2516))
#endif
    {
        m_stDiagMessageInfo.ulLength = PROG_CRC_COMP_RESPONSE_SIZE;
        m_stDiagMessageInfo.ubDiagStatus = UDS_ACK;
#if (PROG_IMPL_VARIANT == PROG_IMPL_40)
        /* Send POSITIVE RESPONSE with same data than request*/
        m_stDiagMessageInfo.pubTxData[4] = PROG_ROUTINE_FINISHED_OK;
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_40)*/
#if (PROG_IMPL_VARIANT == PROG_IMPL_50)
        /* Send POSITIVE RESPONSE */
        m_stDiagMessageInfo.pubTxData[PROG_RC_ROUTINE_INFO_BASE_INDEX]                = PROG_ROUTINE_FINISHED_OK;
        m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_VERIF_RESULTS_BASE_INDEX] = PROG_RC_STATUS_RECORD_VERIF_RESULTS_OK;
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_50)*/
#if (PROG_IMPL_VARIANT == PROG_IMPL_31)
        /* Correct header data, Send POSITIVE RESPONSE */
        m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_VERIF_RESULTS_BASE_INDEX] = PROG_RC_STATUS_RECORD_VERIF_RESULTS_OK;
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_31)*/
#if (PROG_IMPL_VARIANT == PROG_IMPL_60)
        /* Allow integration to modify response */
        PROG_Custom_CheckMemoryRoutine_Succeed(m_stDiagMessageInfo.pubTxData, &m_stDiagMessageInfo.ulLength);
#if (PROG_BLU_ACTIVE == STD_ON)
        if ((PROG_TRUE == m_ubBLUPattern)?BCOV(2517):!BCOV(2518))
        {
            eProgStatus = PROG_CustomSetBLUVerificationSuccess(PROG_TRUE);
        }
        else
#endif /* (PROG_BLU_ACTIVE == STD_ON) */
        {
#if (PROG_ERASE_TYPE != PROG_ERASE_BY_BLOCK_ID)
            eProgStatus = PROG_CustomSetDownloadVerificationSuccess(0U, m_stCurrentSegment.ubSegmentId, PROG_TRUE);
#else
            eProgStatus = PROG_CustomSetDownloadVerificationSuccess(m_stCurrentSegment.ubLogicalBlockId, m_stCurrentSegment.ubSegmentId, PROG_TRUE);
#endif
        }
        if((eProgStatus == PROG_E_OK)?BCOV(2519):!BCOV(2520))
        {
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_60)*/

#if(PROG_PARTIAL_VERIFY_CRC == STD_ON)
            if ((m_ubActivePartialVerifyCrc == FALSE)?BCOV(2521):!BCOV(2522))
            {
                /*Update Segment list for Partial CRC calculation */
                for (ubSegIndex = 0U; (ubSegIndex < PROG_MAX_RD_PER_BLOCK)?BCOV(2523):!BCOV(2524); ubSegIndex++)
                {
                    aulSegProgSize[ubSegIndex] = m_stSegList.astSeg[ubSegIndex].ulSize;
                }
                PROG_CustomSetPartProgSegList(m_stCurrentSegment.ubLogicalBlockId,
                                                aulSegProgSize,
                                                &m_stSegList.ubSegNbr);
            }
#endif /* #if(PROG_PARTIAL_VERIFY_CRC == STD_ON) */
#if ((PROG_SECURE_APPLI_CHECKSUM_COMPUTATION == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_60))
            /* Send Event Checksum Update event */
            PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_CHECKSUM_UPDATE);
#else
#if (PROG_BLU_ACTIVE == STD_ON)
            if ((PROG_TRUE == m_ubBLUPattern)?BCOV(2525):!BCOV(2526))
            {
                PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS);
            }
            else
#endif /* (PROG_BLU_ACTIVE == STD_ON) */
            {
                /* Send Event Finished event */
                PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
            }
#endif /*((PROG_SECURE_APPLI_CHECKSUM_COMPUTATION == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_60))*/

#if (PROG_SET_CRC_COMPARE_RESULT_ENABLE == STD_ON)
#if (PROG_PARTIAL_VERIFY_CRC == STD_ON)
            if ((m_ubActivePartialVerifyCrc == FALSE)?BCOV(2527):!BCOV(2528))
#endif
            {
#if (PROG_IMPL_VARIANT != PROG_IMPL_60)
/* PROG_IMPL_60 has already called that function above. */
#if (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON)
                /* Verification of downgrade protection */
                eProgStatus = PROG_DowngradeProtection_CheckForCheckMemory_Impl40(m_stCurrentSegment.ubLogicalBlockId, &ubDgpStatus);
                /* Invalid downgrade */
                if ((PROG_E_OK != eProgStatus)?BCOV(2529):!BCOV(2530))
                {
                    m_stDiagMessageInfo.pubTxData[PROG_RC_ROUTINE_INFO_BASE_INDEX] = (u8)ubDgpStatus;
                    /* Notify failure */
                    eProgStatus = PROG_CustomSetDownloadVerificationSuccess(m_stCurrentSegment.ubLogicalBlockId, \
                                                                            m_stCurrentSegment.ubLogicalSegmentId, FALSE);
                }
                else
#endif /* (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON) */
                {
                    /* Send CRC Compare Result: Success*/
                    eProgStatus = PROG_CustomSetDownloadVerificationSuccess(m_stCurrentSegment.ubLogicalBlockId, \
                                                                            m_stCurrentSegment.ubLogicalSegmentId, TRUE);
                }
#endif /* PROG_IMPL_VARIANT != PROG_IMPL_60 */
            }

#endif /*(PROG_SET_CRC_COMPARE_RESULT_ENABLE == STD_ON)*/


            if ((PROG_E_OK == eProgStatus)?BCOV(2531):!BCOV(2532))
            {
#if (PROG_SECURE_APPLI_CHECKSUM_COMPUTATION == STD_ON)
                /* If authenticated or secure Boot feature is used and current block is authenticated one, delay response
                until application checksum is finished */
                if ((
#if (PROG_ERASE_TYPE != PROG_ERASE_BY_BLOCK_ID)
                    (PROG_TRUE != stCfgBlockSecureBootInfo[m_stCurrentSegment.ubSegmentId].ubBlockVerifiedInSecure)
#else
                    (PROG_TRUE != stCfgBlockSecureBootInfo[m_stCurrentSegment.ubLogicalBlockId].ubBlockVerifiedInSecure)
#endif
#if (PROG_BLU_ACTIVE == STD_ON)
                    && (PROG_FALSE == m_ubBLUPattern)
#endif /* (PROG_BLU_ACTIVE == STD_ON) */
                )?BCOV(2533):!BCOV(2534))
                {
                    UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);
                }
                else
                {
                    PROG_SecurityComputeAppChecksum();
                }
#else
#if (PROG_BLU_ACTIVE == STD_ON)
                if ((PROG_FALSE == m_ubBLUPattern)?BCOV(2535):!BCOV(2536))
#endif /* (PROG_BLU_ACTIVE == STD_ON) */
                {
                    UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);
                }
#endif
            }
            else
            {
                /* Error happens */
#if (PROG_IMPL_VARIANT == PROG_IMPL_60)
/* CHECK: NOPARSE */
/* NOCOV-FEATURE_NOT_USED */
                m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_72;
                PROG_Custom_CheckMemoryRoutine_Failed(m_stDiagMessageInfo.pubTxData, &m_stDiagMessageInfo.ulLength, &m_stDiagMessageInfo.ubDiagStatus);
                UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);
#if PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON
                if(stConfigSegment[m_stCurrentSegment.ubSegmentId].ePartitionType == PROG_FLASH_ROUTINES_PARTITION)
                {
                    PROG_DrvDown_SetFlashRoutinesCorruption(PROG_TRUE);
                    PROG_DrvDown_EraseFlashRoutines();
                }
#endif /* PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON */
/* CHECK: PARSE */
#elif (PROG_IMPL_VARIANT == PROG_IMPL_40)
#if PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON
                if((stConfigSegment[m_stCurrentSegment.ubSegmentId].ePartitionType == PROG_FLASH_ROUTINES_PARTITION)?BCOV(2537):!BCOV(2538))
                {
                    PROG_DrvDown_SetFlashRoutinesCorruption(PROG_TRUE);
                    PROG_DrvDown_EraseFlashRoutines();
                }
#endif /* PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON */
                UDS_LongRequestEnd(PROG_CRC_COMP_RESPONSE_SIZE, m_stDiagMessageInfo.pubTxData, UDS_ACK);
#elif (PROG_IMPL_VARIANT == PROG_IMPL_50)
                m_stDiagMessageInfo.pubTxData[PROG_RC_ROUTINE_INFO_BASE_INDEX]                = PROG_ROUTINE_FINISHED_OK;

#if ((PROG_VERIFICATION_ON_THE_FLY == STD_OFF) && (PROG_CRC_CALCULATION == PROG_NO_CRC) && (PROG_SIGNATURE_CALCULATION == STD_ON))
                /* Signature verification has failed */
                m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_VERIF_RESULTS_BASE_INDEX] =
                    (u8) (PROG_RC_STATUS_RECORD_VERIF_RESULTS_SIG_FAILED);
#else
                /* CRC verification has failed */
                m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_VERIF_RESULTS_BASE_INDEX] =
                    (u8) (PROG_RC_STATUS_RECORD_VERIF_RESULTS_CRC_FAILED);
#endif /*((PROG_VERIFICATION_ON_THE_FLY == STD_OFF) && (PROG_CRC_CALCULATION == PROG_NO_CRC) && (PROG_SIGNATURE_CALCULATION == STD_ON))*/
                UDS_LongRequestEnd(PROG_CRC_COMP_RESPONSE_SIZE, m_stDiagMessageInfo.pubTxData, UDS_ACK);
#elif (PROG_IMPL_VARIANT == PROG_IMPL_31)
                /* Hash verification has failed */
                m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_VERIF_RESULTS_BASE_INDEX] =
                    (u8) (PROG_RC_STATUS_RECORD_VERIF_RESULTS_GEN_FAILURE);
#else
                UDS_LongRequestEnd(PROG_CRC_COMP_RESPONSE_SIZE, m_stDiagMessageInfo.pubTxData, UDS_NRC_72);
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_40)*/
            }



#if PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON
            if((stConfigSegment[m_stCurrentSegment.ubSegmentId].ePartitionType == PROG_FLASH_ROUTINES_PARTITION)?BCOV(2539):!BCOV(2540))
            {
                /* Indicate that the flash routines are now present in RAM */
                PROG_DrvDown_SetFlashRoutinesPresence(PROG_TRUE);
                PROG_DrvDown_SetFlashRoutinesCorruption(PROG_FALSE);
            }
#endif /* PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON */
            eProgStatus = PROG_E_OK;
#if (PROG_IMPL_VARIANT == PROG_IMPL_60)
        }
        else
        {
            m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_72;
            PROG_Custom_CheckMemoryRoutine_Failed(m_stDiagMessageInfo.pubTxData, &m_stDiagMessageInfo.ulLength, &m_stDiagMessageInfo.ubDiagStatus);
            UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);

            /* Send Event Failed event to go to error state */
            PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
        }
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_60)*/
#if (PROG_BLU_ACTIVE == STD_ON)
        if ((PROG_TRUE == m_ubBLUPattern)?BCOV(2541):!BCOV(2542))
        {
            PROG_CustomSetBLUDownloadInProgress(PROG_TRUE);
#if (PROG_RESET_CAUSE_ENABLE == STD_ON)
            /* Set Reset Cause and indicate that response shall be not sent after reset */
            PROG_CustomStoreResetCause(PROG_RESET_CAUSE_BLU, PROG_FALSE);
#endif
        }
#endif /* (PROG_BLU_ACTIVE == STD_ON) */
    }
    /* If some errors occurred */
    else
    {
#if ((PROG_PARTIAL_VERIFY_CRC == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_STANDARD_REPROG))
        if ((m_ubActivePartialVerifyCrc == FALSE)?BCOV(2543):!BCOV(2544))
        {
            /*if check memory failed, set the number of segment to 0 */
            m_stSegList.ubSegNbr = 0;
            PROG_CustomSetPartProgSegList(m_stCurrentSegment.ubLogicalBlockId,
                                            NULL_PTR,
                                              &m_stSegList.ubSegNbr);
        }
#endif /* #if((PROG_PARTIAL_VERIFY_CRC == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_STANDARD_REPROG)) */
#if (PROG_IMPL_VARIANT != PROG_IMPL_60)
        /* Send Event Finished event */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
#else
        /* Send Event Failed event */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
#endif

        /* Send NEGATIVE RESPONSE with same data than request*/
#if (PROG_IMPL_VARIANT == PROG_IMPL_60)
        m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_72;
        PROG_Custom_CheckMemoryRoutine_Failed(m_stDiagMessageInfo.pubTxData, &m_stDiagMessageInfo.ulLength, &m_stDiagMessageInfo.ubDiagStatus);
#if PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON
        if((stConfigSegment[m_stCurrentSegment.ubSegmentId].ePartitionType == PROG_FLASH_ROUTINES_PARTITION)?BCOV(2545):!BCOV(2546))
        {
            PROG_DrvDown_SetFlashRoutinesCorruption(PROG_TRUE);
            PROG_DrvDown_EraseFlashRoutines();
        }
#endif /* PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON */
#elif (PROG_IMPL_VARIANT == PROG_IMPL_40)
#if PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON
        if((stConfigSegment[m_stCurrentSegment.ubSegmentId].ePartitionType == PROG_FLASH_ROUTINES_PARTITION)?BCOV(2547):!BCOV(2548))
        {
            PROG_DrvDown_SetFlashRoutinesCorruption(PROG_TRUE);
            PROG_DrvDown_EraseFlashRoutines();
        }
#endif /* PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON */
        m_stDiagMessageInfo.pubTxData[PROG_RC_ROUTINE_INFO_BASE_INDEX]                = PROG_ROUTINE_FINISHED_NOK;
        m_stDiagMessageInfo.ulLength                                                  = PROG_CRC_COMP_RESPONSE_SIZE;
        m_stDiagMessageInfo.ubDiagStatus                                              = UDS_ACK;
#elif (PROG_IMPL_VARIANT == PROG_IMPL_50)
        m_stDiagMessageInfo.pubTxData[PROG_RC_ROUTINE_INFO_BASE_INDEX]                = PROG_ROUTINE_FINISHED_OK;
        m_stDiagMessageInfo.ulLength                                                  = PROG_CRC_COMP_RESPONSE_SIZE;
        m_stDiagMessageInfo.ubDiagStatus                                              = UDS_ACK;
#if ((PROG_VERIFICATION_ON_THE_FLY == STD_OFF) && (PROG_CRC_CALCULATION == PROG_NO_CRC) && (PROG_SIGNATURE_CALCULATION == STD_ON))
    /* Signature verification has failed */
        m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_VERIF_RESULTS_BASE_INDEX] =
                (u8) (PROG_RC_STATUS_RECORD_VERIF_RESULTS_SIG_FAILED);
#else
    /* CRC verification has failed */
        m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_VERIF_RESULTS_BASE_INDEX] =
                (u8) (PROG_RC_STATUS_RECORD_VERIF_RESULTS_CRC_FAILED);
#endif /*((PROG_VERIFICATION_ON_THE_FLY == STD_OFF) && (PROG_CRC_CALCULATION == PROG_NO_CRC) && (PROG_SIGNATURE_CALCULATION == STD_ON))*/

#elif (PROG_IMPL_VARIANT == PROG_IMPL_31)
        m_stDiagMessageInfo.ulLength     = PROG_CRC_COMP_RESPONSE_SIZE;
        m_stDiagMessageInfo.ubDiagStatus = UDS_ACK;
#if (PROG_REPROG_TYPE == PROG_AUTHENTICATED_REPROG)
        /* Signature verification or Hash verification has failed */
        /* Hash verification has failed or Block Header Check operation returned issues */
        if (((PROG_TRUE == ubHashVerificationPerformed) || (PROG_TRUE == m_ubBlockHeaderCheckFailed))?BCOV(2549):!BCOV(2550))
        {
            m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_VERIF_RESULTS_BASE_INDEX] =
            (u8) (PROG_RC_STATUS_RECORD_VERIF_RESULTS_GEN_FAILURE);
        }
        else
        {
            /* Signature verification has failed */
            m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_VERIF_RESULTS_BASE_INDEX] =
            (u8) (PROG_RC_STATUS_RECORD_VERIF_RESULTS_SIG_FAILED);
        }
#elif (PROG_REPROG_TYPE == PROG_STANDARD_REPROG)
        /* CRC verification has failed */
        m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_VERIF_RESULTS_BASE_INDEX] =
                (u8) (PROG_RC_STATUS_RECORD_VERIF_RESULTS_CRC_FAILED);
#endif /*(PROG_REPROG_TYPE == PROG_AUTHENTICATED_REPROG)*/
#else
        m_stDiagMessageInfo.ulLength     = PROG_CRC_COMP_RESPONSE_SIZE;
        m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_72;
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_60) */

#if (PROG_SET_CRC_COMPARE_RESULT_ENABLE == STD_ON)
#if (PROG_PARTIAL_VERIFY_CRC == STD_ON)
        if ((m_ubActivePartialVerifyCrc == FALSE)?BCOV(2551):!BCOV(2552))
#endif
        {
#if (PROG_IMPL_VARIANT != PROG_IMPL_40)
#if (PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR)
            (void) PROG_CustomSetDownloadVerificationSuccess(0U, m_stCurrentSegment.ubSegmentId, PROG_FALSE);
#else
            /* Send CRC Compare Result: Failed*/
            (void) PROG_CustomSetDownloadVerificationSuccess(m_stCurrentSegment.ubLogicalBlockId, \
                                                                    m_stCurrentSegment.ubLogicalSegmentId, PROG_FALSE);
#endif /* PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR */
        }
#endif /*(PROG_IMPL_VARIANT != PROG_IMPL_40)*/

#if (PROG_IMPL_VARIANT == PROG_IMPL_40)
#if (PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR)
            eProgStatus = PROG_CustomSetDownloadVerificationSuccess(0U, m_stCurrentSegment.ubSegmentId, PROG_FALSE);
#else
            /* Send CRC Compare Result: Failed*/
            eProgStatus = PROG_CustomSetDownloadVerificationSuccess(m_stCurrentSegment.ubLogicalBlockId, \
                                                                    m_stCurrentSegment.ubLogicalSegmentId, PROG_FALSE);
#endif /* PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR */
        }
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_40)*/
#endif /*(PROG_SET_CRC_COMPARE_RESULT_ENABLE == STD_ON)*/

        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);
        eProgStatus = PROG_E_NOT_OK;
    }

#if (PROG_RESUM_REPROG == STD_ON)
    /*Store the last written address (last verified)*/
    ulVerAddress = m_stDataProgVerification.ulAdd-1U;
    PROG_CustomStoreResumeAddress(m_stCurrentSegment.ubLogicalBlockId, ulVerAddress);
#endif/*(PROG_RESUM_REPROG == STD_ON)*/

#if (((PROG_IMPL_VARIANT == PROG_IMPL_40) || (PROG_IMPL_VARIANT == PROG_IMPL_50) || (PROG_IMPL_VARIANT == PROG_IMPL_60)) && (PROG_CHECK_MEMORY_ENABLE == STD_ON))
    /* Save the response sent to first Check Memory request */
    m_stFirstCheckMemoryAnswerInfo.ulLength = PROG_CRC_COMP_RESPONSE_SIZE;
    m_stFirstCheckMemoryAnswerInfo.ubDiagStatus = m_stDiagMessageInfo.ubDiagStatus;
    for (ubIdx = 4U; ubIdx < PROG_CRC_COMP_RESPONSE_SIZE; ubIdx++)
    {
        m_stFirstCheckMemoryAnswerInfo.aubData[ubIdx] = m_stDiagMessageInfo.pubTxData[ubIdx];
    }
#endif

    DBG_PROG_CRC_COMPARE_EXIT(eProgStatus);
#endif /*#if ((PROG_CRC_COMPUTE_COMPARE_ENABLE == STD_ON) || ((PROG_SEG_LIST_CKS == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_10) && (PROG_IMPL_VARIANT != PROG_IMPL_11)&& (PROG_IMPL_VARIANT != PROG_IMPL_90) && (PROG_IMPL_VARIANT != PROG_IMPL_91)))*/
    return eProgStatus;
}
/*-------------------------------{end PROG_CRC_Compare}----------------------------------*/

#if PROG_TRANSFER_DATA_ENABLE == STD_ON
#if ((PROG_CRC_CALCULATION != PROG_NO_CRC) || (PROG_SIGNATURE_CALCULATION == STD_ON) || (PROG_HASH_CALCULATION == STD_ON))

/*----------------------------{PROG_VerificationOnTheFly}------------------------------------*/
tProgStatus PROG_VerificationOnTheFly(void)
{
    tProgStatus eProgStatus = PROG_E_OK;

    DBG_PROG_VERIFICATIONONTHEFLY_ENTRY();
#if ((PROG_IMPL_VARIANT == PROG_IMPL_10) || (PROG_IMPL_VARIANT == PROG_IMPL_11))
    /* Verification block table is present which means that it a normal data block, call prog_crc */
    if(TRUE == PROG_Impl10_IsVerificationTablePresent())
    {
      eProgStatus = PROG_CRC();
    }
    /* VBT is being downloaded and this is an RTE state */
    else
    {
      /* simualte the event of finishing all data computation */
      PROG_HsmEmit (&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH);
    }
#elif ((PROG_IMPL_VARIANT == PROG_IMPL_90) || (PROG_IMPL_VARIANT == PROG_IMPL_91))

      eProgStatus = PROG_CRC();

#else

/* In case that verification shall be done on data passed through Transfer Data */
#if (PROG_SIGNATURE_VERIFICATION_ON_FLASHED_DATA == STD_OFF)
    /* Only verification not related to signature shall be done here */
    /* Verification on signature has been previously done in WRITE state on the state machine */
    if (PROG_VERIFY_SIGNATURE != m_stDataProgVerification.ubAlgo)
    {
        eProgStatus = PROG_CRC();
    }
#endif
#if ((PROG_VERIFICATION_ON_THE_FLY == STD_ON) && (PROG_SIGNATURE_VERIFICATION_ON_FLASHED_DATA == STD_ON))
    eProgStatus = PROG_CRC();
#endif
#if (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_IN_DFI)
    if ((m_ubVerificationMethod == PROG_VERIFICATION_SIGNATURE) || (m_ubVerificationMethod == PROG_VERIFICATION_SIGNATURE_AND_CRC))
    {
        eProgStatus = PROG_CRC();
    }
#endif /* (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_IN_DFI) */
#if (PROG_SIGNATURE_VERIFICATION_ON_FLASHED_DATA == STD_OFF) || ((PROG_VERIFICATION_ON_THE_FLY == STD_ON) && (PROG_SIGNATURE_VERIFICATION_ON_FLASHED_DATA == STD_ON)) || ((PROG_IMPL_VARIANT == PROG_IMPL_10) || (PROG_IMPL_VARIANT == PROG_IMPL_11))
    if (PROG_E_OK == eProgStatus)
#endif /*#if (PROG_SIGNATURE_VERIFICATION_ON_FLASHED_DATA == STD_OFF)*/
    {
        /* emit event PROG_HSM_PROG_EV_PROG_EVENT_FINISHED */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
    }
#endif

    DBG_PROG_VERIFICATIONONTHEFLY_EXIT(eProgStatus);
    return eProgStatus;
}


/*----------------------------{end PROG_VerificationOnTheFly}--------------------------------*/

/*----------------------------{PROG_Do_CheckHash}------------------------------------*/
void PROG_Do_CheckHash(void)
{
    DBG_PROG_DO_CHECKHASH_ENTRY();

#if ((PROG_VERIFICATION_ON_THE_FLY == STD_OFF) && (PROG_HASH_CALCULATION == STD_ON))
    (void)PROG_CRC();
#endif

    DBG_PROG_DO_CHECKHASH_EXIT();
}


/*----------------------------{end PROG_Do_CheckHash}--------------------------------*/

/*----------------------------{PROG_Entry_CheckHash}------------------------------------*/
void PROG_Entry_CheckHash(void)
{
    DBG_PROG_ENTRY_CHECKHASH_ENTRY();

#if ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_STANDARD_REPROG))

    /* Simulate crypto finish to go to CRC computation */
    PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH);

#elif ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_AUTHENTICATED_REPROG))

    /* Finalize Hash computation */
    PROG_ComputeHashFinish(&m_aubComputedMessageDigest[0]);
#endif
    DBG_PROG_ENTRY_CHECKHASH_EXIT();
}
/*----------------------------{end PROG_Entry_CheckHash}--------------------------------*/

/*----------------------------{PROG_Do_CheckSignature}------------------------------------*/
void PROG_Do_CheckSignature(void)
{
    DBG_PROG_DO_CHECKSIGNATURE_ENTRY();

#if ((PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_SIGNATURE_VERIFICATION_ON_FLASHED_DATA == STD_ON))
    (void)PROG_CRC();
#endif

    DBG_PROG_DO_CHECKSIGNATURE_EXIT();
}


/*----------------------------{end PROG_Do_CheckSignature}--------------------------------*/

/*-------------------------------{PROG_CRC}--------------------------------------*/
tProgStatus PROG_CRC(void)
{
    tProgStatus eProgStatus = PROG_E_BUSY;
    u32 ulWriteSizeOfData;
    u32 ulReadLength;
    u32 ulStartAddress;
#if(PROG_IMPL_20 == PROG_IMPL_VARIANT)
    u8 ubStoredSBIFlag;
#endif
#if (((PROG_SIGNATURE_CALCULATION == STD_ON) || (PROG_HASH_CALCULATION == STD_ON)) && (PROG_CRY_PRESENT == STD_ON))
    tProgCryState eCryState;
#endif

    u8 ubAddressShift = 0;

#if ((PROG_COMPUTE_HASH_WITH_ADDR_LEN == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_50))
    u32 ulAddr;
#endif

#if ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_STANDARD_REPROG))
    u32 ulCrcAddress;
    u32 ulSkipCrcLength = 0;
#endif

    DBG_PROG_CRC_ENTRY();
#if (PROG_CVN_CHECK == STD_ON)
    if (m_eCvnCheckInProgress != PROG_TRUE)
    {
#endif /* PROG_CVN_CHECK == STD_ON */

/* Get SBI flag value */
#if(PROG_IMPL_20 == PROG_IMPL_VARIANT)
        ubStoredSBIFlag = PROG_GetSBIFlagValue();
#endif
#if (PROG_COMPRESSION_ENABLE == STD_ON)
        if (TRUE == m_stReprogInfo.ubCompRequired)
        {
            ulWriteSizeOfData = m_stReprogInfo.ulTotalDecompDataWrite;
        }
        else
#endif /* (PROG_COMPRESSION_ENABLE == STD_ON) */
        {
#if ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_STANDARD_REPROG))
            ulWriteSizeOfData = m_stReprogInfo.ulReceivedSizeOfData - PROG_CRC_BYTE_LENGTH;
#else
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
            if (m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)
            {
                ulWriteSizeOfData = m_stCryptoData.ulTotDecryptedWrittenSize;
            }
            else
#endif /* (PROG_DECRYPTION_ENABLE == STD_ON) */
            {
                ulWriteSizeOfData = m_stReprogInfo.ulReceivedSizeOfData;
            }
#endif
        }

#if (   ((PROG_SIGNATURE_CALCULATION == STD_ON) || (PROG_HASH_CALCULATION == STD_ON)) && (PROG_CRY_PRESENT == STD_ON))
        if ((PROG_VERIFY_HASH == m_stDataProgVerification.ubAlgo) || (PROG_VERIFY_SIGNATURE == m_stDataProgVerification.ubAlgo))
        {
            eCryState = PROG_GetCryptoState();
        }
        else
        {
            eCryState = PROG_IDLE;
        }

        if ((PROG_HASH_START             != eCryState) &&
            (PROG_HASH_UPDATE            != eCryState) &&
            (PROG_SIGNATURE_CHECK_START  != eCryState) &&
            (PROG_SIGNATURE_CHECK_UPDATE != eCryState) &&
#if (PROG_CSMASR43_USED == STD_ON)
            (PROG_SIGNATURE_CHECK_UPDATE_DONE != eCryState) &&
            (PROG_HASH_UPDATE_DONE != eCryState) &&
#endif/*(PROG_CSMASR43_USED == STD_ON)*/
            (PROG_SIGNATURE_CHECK_FINISH != eCryState))
#endif
        {
            /* Is there still data to use for programming verification */
            if (m_stDataProgVerification.ulCnt < (ulWriteSizeOfData - m_stPageBuffer.ulOldDataLength))
            {
/* Specific case to manage: For some OEM, hash shall be computed also on Address and Length of the received segment
    => Add address and Length on the first Prog_CRC call for this segment */
#if ((PROG_COMPUTE_HASH_WITH_ADDR_LEN == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_50))
                if ((0U == m_stDataProgVerification.ulCnt) && (PROG_VERIFY_HASH == m_stDataProgVerification.ubAlgo))
                {
#if PROG_COMPUTE_HASH_WITH_PHYS_ADDR == STD_ON
                    /* Apply offset on address */
                    if (PROG_MEM_TYPE_FLASH == m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType)
                    {
                        /* Internal Flash */
                        ulAddr = (u32)(m_stDataProgVerification.ulAdd + PROG_FLASH_ADDR_OFFSET);
                    }
#if (PROG_FLASH_EXT_MEMORY_USE == PROG_TRUE)
                    else if (PROG_MEM_TYPE_FLASH_EXT == m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType)
                    {
                        /* external Flash */
                        ulAddr = (u32)(m_stDataProgVerification.ulAdd - PROG_FLASH_EXT_ADDR_OFFSET);
                    }
#endif
#if (PROG_CUSTOM_MEMORY_USE == PROG_TRUE)
                    else if (PROG_MEM_TYPE_CUSTOM == m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType)
                    {
                        /* Custom Memory */
                        ulAddr = (u32)(m_stDataProgVerification.ulAdd - PROG_CUSTOM_MEMORY_ADDR_OFFSET);
                    }
#endif
                    else
#endif /* PROG_COMPUTE_HASH_WITH_PHYS_ADDR == STD_ON */
                    {
                        /* RAM */
                        ulAddr = m_stDataProgVerification.ulAdd;
                    }
                    m_aubCrcData[0U] = (u8)(ulAddr >> 24U);
                    m_aubCrcData[1U] = (u8)(ulAddr >> 16U);
                    m_aubCrcData[2U] = (u8)(ulAddr >> 8U);
                    m_aubCrcData[3U] = (u8)(ulAddr);
                    m_aubCrcData[4U] = (u8)(m_stCurrentSegment.ulSize >> 24U);
                    m_aubCrcData[5U] = (u8)(m_stCurrentSegment.ulSize >> 16U);
                    m_aubCrcData[6U] = (u8)(m_stCurrentSegment.ulSize >> 8U);
                    m_aubCrcData[7U] = (u8)(m_stCurrentSegment.ulSize);

                    ubAddressShift = 8U;
                }
                else
                {
                    /* Nothing to do */
                }
#endif
                if (((ulWriteSizeOfData - m_stPageBuffer.ulOldDataLength) - m_stDataProgVerification.ulCnt) >= (PROG_CRC_CALC_SIZE - (u32)ubAddressShift))
                {
                    ulReadLength = PROG_CRC_CALC_SIZE - (u32)ubAddressShift;
                }
                else
                {
                    ulReadLength = ((ulWriteSizeOfData - m_stPageBuffer.ulOldDataLength) - m_stDataProgVerification.ulCnt - (u32)ubAddressShift);
                }

                /* Calculate the read address                    */
                /* The read is done using the logical address */
                ulStartAddress = m_stDataProgVerification.ulAdd;

#if (PROG_OTA_DUALBANK_USED == STD_ON)
                ulStartAddress = PROG_CustomCalcInactiveBankReadAddr(ulStartAddress);
#endif /*(PROG_OTA_DUALBANK_USED == STD_ON)*/

#if ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_STANDARD_REPROG))
                ulCrcAddress = stCfgBlock[m_stCurrentSegment.ubLogicalBlockId].ulCrcAddress;
                if ((ulCrcAddress < (ulStartAddress + ulReadLength)) && (ulStartAddress < (ulCrcAddress + PROG_CRC_BYTE_LENGTH)))
                {
                  ulReadLength = ulCrcAddress - ulStartAddress;
                  ulSkipCrcLength = PROG_CRC_BYTE_LENGTH;
                }
                else
                {
                  /* Nothing to do */
                }
#endif /*((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_STANDARD_REPROG))*/

#if(PROG_IMPL_20 != PROG_IMPL_VARIANT)
#if ((PROG_IMPL_VARIANT == PROG_IMPL_10) || (PROG_IMPL_VARIANT == PROG_IMPL_11))
                PROG_Impl10_AdjustLengthForHash(&ulReadLength);
                if( 0 == ulReadLength)
                {
                  /* Emit event PROG_EVENT_CRC_FINISH*/
                  PROG_HsmEmit (&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH);
                }
                else
#endif
                {
                    eProgStatus = PROG_MemDataAccess(
                            m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,
                    PROG_MEM_OPERATION_TYPE_READ, ulStartAddress,
                            ulReadLength,&m_aubCrcData[ubAddressShift]);
                }
#else
                if(m_stCurrentSegment.uwModuleId == PROG_SW_APP_ID)
                {
                    eProgStatus = PROG_MemDataAccessByRegion(
                                    m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,
                                PROG_MEM_OPERATION_TYPE_READ, ulStartAddress,
                                    &ulReadLength, m_aubCrcData);
                }
                else
                {
                    eProgStatus = PROG_MemDataAccess(
                            m_astCfgMemory[stConfigSegment[m_stCurrentSegment.ubSegmentId].ubMemoryIdx].eMemoryType,
                        PROG_MEM_OPERATION_TYPE_READ, ulStartAddress,
                            ulReadLength, m_aubCrcData);
                }
#endif
                if (PROG_E_NOT_OK != eProgStatus)
                {
#if((PROG_CRC_CALCULATION == PROG_NO_CRC) && ((PROG_IMPL_VARIANT == PROG_IMPL_3) || \
    (PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_5)))
                  /* If no error occurred during data access */
                  if (PROG_VERIFY_CRC == m_stDataProgVerification.ubAlgo)
                  {
                      PROG_CalcCrc16(m_aubCrcData, ulReadLength, &m_stDataProgVerification.uwVal);
                  }
#endif
#if (PROG_CRC_CALCULATION == PROG_TD_CRC16)
#if((PROG_IMPL_VARIANT == PROG_IMPL_90)||(PROG_IMPL_VARIANT == PROG_IMPL_91))
                    PROG_CalcCrc16(m_aubCrcData, ulReadLength, &m_stDataProgVerification.uwVal);
#else
                    /* If no error occurred during data access */
                    if (PROG_VERIFY_CRC == m_stDataProgVerification.ubAlgo)
                    {
                        PROG_CalcCrc16(m_aubCrcData, ulReadLength, &m_stDataProgVerification.uwVal);
                    }
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_90)||(PROG_IMPL_VARIANT == PROG_IMPL_91)*/
#elif (PROG_CRC_CALCULATION == PROG_TD_CRC32)
                    /* For Verification method based on DFI CRC shall be done later */
#if (PROG_VERIFICATION_METHOD != PROG_VERIFICATION_IN_DFI)
                    /* If no error occurred during data access */
                    if (PROG_VERIFY_CRC == m_stDataProgVerification.ubAlgo)
                    {
                        PROG_CalcCrc32(m_aubCrcData, ulReadLength, &m_stDataProgVerification.ulVal);
                    }
#endif /* (PROG_VERIFICATION_METHOD != PROG_VERIFICATION_IN_DFI) */
#elif (PROG_CRC_CALCULATION == PROG_TD_CRC_CUST)
                    if (PROG_VERIFY_CRC == m_stDataProgVerification.ubAlgo)
                    {
                        /* Call custom callback for Checksum calculation update */
                        PROG_CustomUpdateChecksumCalc(m_aubCrcData, ulReadLength);
                    }
#endif
#if (PROG_HASH_CALCULATION == STD_ON)
#if(PROG_IMPL_20 == PROG_IMPL_VARIANT)
                    if (ubStoredSBIFlag == FALSE)
#endif
                    {
                        if (PROG_VERIFY_HASH == m_stDataProgVerification.ubAlgo)
                        {
                            PROG_ComputeHashUpdate(m_aubCrcData, (u32)(ulReadLength + (u32)ubAddressShift));
                        }
                    }
#endif
#if ((PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_CRY_PRESENT == STD_ON) && (PROG_VERIFICATION_METHOD != PROG_VERIFICATION_IN_DFI))
                    if ((PROG_VERIFY_SIGNATURE == m_stDataProgVerification.ubAlgo))
                    {
                        PROG_VerifySignatureUpdate(m_aubCrcData, ulReadLength);
                    }
#elif(PROG_VERIFICATION_METHOD == PROG_VERIFICATION_IN_DFI)
                    if ((PROG_VERIFY_SIGNATURE == m_stDataProgVerification.ubAlgo) && (m_ubVerificationMethod != PROG_VERIFICATION_SIGNATURE_AND_CRC))
                    {
                        PROG_VerifySignatureUpdate(m_aubCrcData, ulReadLength);
                    }
                    else
                    {
                        PROG_CalcCrc32(m_aubCrcData, ulReadLength, &m_stDataProgVerification.ulVal);
                    }
#endif
#if(PROG_IMPL_20 == PROG_IMPL_VARIANT)
                    if (ubStoredSBIFlag == FALSE)
#endif
                    {
                        /* increment CRC calculated length */
#if ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_STANDARD_REPROG))
                        m_stDataProgVerification.ulAdd += ulReadLength + ulSkipCrcLength;
#else
                        m_stDataProgVerification.ulAdd += ulReadLength;
#endif
                        m_stDataProgVerification.ulCnt += ulReadLength;

                        /* return status BUSY */
                        eProgStatus = PROG_E_BUSY;
                    }
                }
#if(PROG_IMPL_30 == PROG_IMPL_VARIANT)
                else
                {
                    /* Error during memory read operation */
                    PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
                    UDS_LongRequestEnd(PROG_CHK_PROG_DEP_POS_RESPONSE_SIZE, m_stDiagMessageInfo.pubTxData, UDS_NRC_72);
#if (PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)
                    /*Error during downloaded data read operation, update ProgrammingStatus*/
                    PROG_SetProgrammingStatus( PROG_RC_CHECKSUM_VERIFY, PROG_FALSE);
#endif /*(PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)*/
                }
#endif
            }
            else
            {
#if (PROG_IMPL_20 != PROG_IMPL_VARIANT) && (PROG_IMPL_31 != PROG_IMPL_VARIANT) && (PROG_IMPL_3 != PROG_IMPL_VARIANT) && \
    (PROG_IMPL_4 != PROG_IMPL_VARIANT) && (PROG_IMPL_VARIANT != PROG_IMPL_5)
                /* Emit event PROG_EVENT_CRC_FINISH*/
                PROG_HsmEmit (&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH);
                /* return status OK */
                eProgStatus = PROG_E_OK;
#else
                /* return status OK */
                eProgStatus = PROG_E_OK;
#endif

            }
        }
#if (((PROG_SIGNATURE_CALCULATION == STD_ON) || (PROG_HASH_CALCULATION == STD_ON)) && (PROG_CRY_PRESENT == STD_ON))
        else
        {
            eProgStatus = PROG_E_BUSY;
        }
#endif
#if (PROG_CVN_CHECK == STD_ON)
    }
    else
    {
        /* Check CVN status */
        eProgStatus = PROG_CustomCvnVerificationStatus();
        eProgStatus = PROG_CheckPartialSwCvnStatus(eProgStatus);
    }
#endif /* PROG_CVN_CHECK == STD_ON */
    DBG_PROG_CRC_EXIT(eProgStatus);
    /* return status */
    return (eProgStatus);
}
/*-----------------------------{end PROG_CRC}------------------------------------*/
#endif /* ((PROG_CRC_CALCULATION != PROG_NO_CRC) || (PROG_SIGNATURE_CALCULATION == STD_ON) || (PROG_HASH_CALCULATION == STD_ON)) */
#endif /* if PROG_TRANSFER_DATA_ENABLE == STD_ON */

#if PROG_TRANSFER_DATA_ENABLE == STD_ON
/*-------------------------------{PROG_TD}---------------------------------------*/
tProgStatus PROG_TD(void)
{
    tProgStatus eProgStatus;

    DBG_PROG_TD_ENTRY();

    eProgStatus = PROG_E_NOT_OK;

#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
    if (m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)
    {
        /* Initialization of decryption variables */
        m_stCryptoData.ulCryptoBufferSize  = PROG_DECRYPT_BUFFER_SIZE;
        m_stCryptoData.ulNextWritePosition = 0U;
    }
#endif /*(PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
    /* Check Sequence Counter */
    if (m_stDiagMessageInfo.pubData[1] == m_stReprogInfo.ubBlockSequenceCounter)
    {
        /* Check if no error happened */
        if (m_stDiagMessageInfo.ubDiagStatus == UDS_ACK)
        {
            if (m_stReprogInfo.ulReceivedSizeOfData != m_stReprogInfo.ulMemorySizeExpected)
            {
                if ( ((m_stReprogInfo.ulReceivedSizeOfData
                          + (u32)((u32)m_stDiagMessageInfo.ulLength - 2U))
                          <= m_stReprogInfo.ulMemorySizeExpected)
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
                   ||(  (m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)
                         &&((m_stReprogInfo.ulReceivedSizeOfData
                          + (u32)((u32)m_stDiagMessageInfo.ulLength - 2U))
                          <= m_stReprogInfo.ulMemorySizeExpected + PROG_AES_BLOCK_SIZE) )
#endif /* #if (PROG_CSM_DECRYPTION_ENABLE == STD_ON) */
                    )
                {
#if ((PROG_DECRYPTION_ENABLE == STD_ON) && (PROG_CSM_DECRYPTION_ENABLE == STD_OFF))
                    eProgStatus = PROG_CustomDecryptData(m_ubEncryptionMethod,
                            &m_stDiagMessageInfo.pubData[2U], (m_stDiagMessageInfo.ulLength - 2U));

                    if(eProgStatus != PROG_E_OK)
                    {
                        /* Send negative response NRC31 */
                        m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_31;
                    }
                    else
#endif /*((PROG_DECRYPTION_ENABLE == STD_ON) && (PROG_CSM_DECRYPTION_ENABLE == STD_OFF))*/
                    {
#if ((PROG_DECRYPTION_ENABLE == STD_OFF) || \
        ((PROG_DECRYPTION_ENABLE == STD_ON) && (PROG_CSM_DECRYPTION_ENABLE == STD_OFF)))
#if (PROG_COMPRESSION_ENABLE == STD_ON)
                        if (m_stReprogInfo.ubCompRequired == TRUE)
                        {
                            /* Call SA decompression module */
#if ( PROG_CAL_PRESENT == STD_OFF)
                            SA_DecompressData(&m_stDiagMessageInfo.pubData[2U],
                                    (m_stDiagMessageInfo.ulLength - 2U)
                                            - (u16)(m_stWriteInfo.ulInDecompDataLength & 0x0000FFFFU));

#else
                            eProgStatus = PROG_DecompressData(&m_stDiagMessageInfo.pubData[2U],
                                    (m_stDiagMessageInfo.ulLength - 2U)
                                            - (u16)(m_stWriteInfo.ulInDecompDataLength & 0x0000FFFFU));

                            if(eProgStatus != PROG_E_OK)
                            {
#if PROG_PEC_ENABLE == STD_ON
                                /* set error in PEC */
                                m_uwPEC = PROG_ERR_COMPRESSION;
#endif
                                /* Send negative response NRC31 */
                                m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_31;
                            }
                            else
#endif
                            {
                                /* Increment the number of data ask for decompression */
                                m_stWriteInfo.ulInDecompDataLength = (u32)((u32)m_stDiagMessageInfo.ulLength - 2U);

                                /*Set flag TD received*/
                                m_stWriteInfo.ubTDReceived = TRUE;

                                eProgStatus = PROG_E_OK;
                            }
                        }
                        else
#endif /* (PROG_COMPRESSION_ENABLE == STD_ON) */
#endif /* ((PROG_DECRYPTION_ENABLE == STD_OFF) || \
                ((PROG_DECRYPTION_ENABLE == STD_ON) && (PROG_CSM_DECRYPTION_ENABLE == STD_OFF)))*/
                        {
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
                            if (m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)
                            {
                                /* Store the length of encrypted data */
                                m_stCryptoData.ulEncryptDataSize = (u32)((u32)m_stDiagMessageInfo.ulLength - 2U);
                                /* Data to be written are decrypted ones, then set to 0 here */
                                m_stWriteInfo.ulDataToBeWritten   = 0U;

                                /*Set flag TD received*/
                                m_stWriteInfo.ubTDReceived = TRUE;

                                eProgStatus = PROG_E_OK;
                            }
                            else
                            {
#if (PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CAL_PRESENT == STD_ON)
                                if (m_stReprogInfo.ubCompRequired == TRUE)
                                {
                                    eProgStatus = PROG_DecompressData(&m_stDiagMessageInfo.pubData[2U],
                                            (m_stDiagMessageInfo.ulLength - 2U)
                                                    - (u16)(m_stWriteInfo.ulInDecompDataLength & 0x0000FFFFU));

                                    if(eProgStatus != PROG_E_OK)
                                    {
                                        /* Send negative response NRC31 */
                                        m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_31;
                                    }
                                    else
                                    {
                                        /* Increment the number of data ask for decompression */
                                        m_stWriteInfo.ulInDecompDataLength = (u32)((u32)m_stDiagMessageInfo.ulLength - 2U);

                                        /*Set flag TD received*/
                                        m_stWriteInfo.ubTDReceived = TRUE;

                                        eProgStatus = PROG_E_OK;
                                    }
                                }
                                else
#endif /* (PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CAL_PRESENT == STD_OFF) */
                                {
                                    /* Increment the number of data to be written */
                                    m_stWriteInfo.ulDataToBeWritten = (u32)((u32)m_stDiagMessageInfo.ulLength - 2U);

                                    /*Set flag TD received*/
                                    m_stWriteInfo.ubTDReceived = TRUE;

                                    eProgStatus = PROG_E_OK;
                                }
                            }
#else /*(PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/

                            /* Increment the number of data to be written */
                            m_stWriteInfo.ulDataToBeWritten = (u32)((u32)m_stDiagMessageInfo.ulLength - 2U);

                            /*Set flag TD received*/
                            m_stWriteInfo.ubTDReceived = TRUE;

                            eProgStatus = PROG_E_OK;
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
                        }
                    }
                }
                else
                {
#if PROG_PEC_ENABLE == STD_ON
                    /* Set error in PEC */
                    m_uwPEC = PROG_ERR_LENGTH_EXCEEDED;
#endif
#if (PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)
                    /*Set the Programming status: TD incompatible Size*/
                    PROG_SetProgrammingStatus(PROG_TD_BLOCK_SIZE, PROG_FALSE);
#endif
                    /*Store NRC_71 as error value*/
                    m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_71;
                } /* else if ( (m_stReprogInfo.ulReceivedSizeOfData + m_stDiagMessageInfo.ulLength) <=  m_stReprogInfo.ulMemorySizeExpected) */
            } /* if (m_stReprogInfo.ulReceivedSizeOfData ==  m_stReprogInfo.ulMemorySizeExpected) */
            else
            {
#if PROG_PEC_ENABLE == STD_ON
                /* Set error in PEC */
                m_uwPEC = PROG_ERR_LENGTH_EXCEEDED;
#endif
                /*Store NRC_24 as error value*/
                m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_24;
            } /* else if (m_stReprogInfo.ulReceivedSizeOfData ==  m_stReprogInfo.ulMemorySizeExpected) */

        } /* if (m_stDiagMessageInfo.ubDiagStatus == UDS_ACK) */
        else
        {
            /* Nothing to do here*/
        } /* else if (m_stDiagMessageInfo.ubDiagStatus == UDS_ACK) */

    } /* if( m_stDiagMessageInfo.pubData[1] == m_stReprogInfo.ubBlockSequenceCounter) */
    else
    {
        /* Is the sequence counter equal to previous TD and that data has already been received*/
        if (( (u8)m_stDiagMessageInfo.pubData[1]
                == (u8)(m_stReprogInfo.ubBlockSequenceCounter - 1U))
                && (m_stReprogInfo.ulReceivedSizeOfData > 0U))
        {
            /*Set flag TD received*/
            m_stWriteInfo.ubTDReceived = TRUE;

            eProgStatus = PROG_E_OK;
        }
        else
        {
            if (m_stReprogInfo.ulReceivedSizeOfData == m_stReprogInfo.ulMemorySizeExpected)
            {
#if PROG_PEC_ENABLE == STD_ON
                /* Set error in PEC */
                m_uwPEC = PROG_ERR_LENGTH_EXCEEDED;
#endif
                /*Store NRC_24 as error value*/
                m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_24;
            }
            else if((m_stReprogInfo.ulReceivedSizeOfData
                        + (u32)((u32)m_stDiagMessageInfo.ulLength - 2U))
                        > m_stReprogInfo.ulMemorySizeExpected)
            {
#if PROG_PEC_ENABLE == STD_ON
                /* Set error in PEC */
                m_uwPEC = PROG_ERR_LENGTH_EXCEEDED;
#endif
#if (PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)
                /*Set the Programming status: TD incompatible Size*/
                PROG_SetProgrammingStatus(PROG_TD_BLOCK_SIZE, PROG_FALSE);
#endif
                /*Store NRC_71 as error value*/
                m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_71;
            }
            else
            {
                /*Store NRC_73 as error value*/
                m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_73;
#if (PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)
               /*Set the Programming status: Wrong Seq. BlockTransfer*/
               PROG_SetProgrammingStatus(PROG_SEQUENCE_BLOCK_TRANSFFER, PROG_FALSE);
#endif
            }
        }
    } /* else if( m_stDiagMessageInfo.pubData[1] == m_stReprogInfo.ubBlockSequenceCounter) */

    if (UDS_ACK != m_stDiagMessageInfo.ubDiagStatus)
    {
        /* Emit event PROG_EVENT_FAILED*/
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
    }

    DBG_PROG_TD_EXIT(eProgStatus);
    return eProgStatus;
}
/*-----------------------------{end PROG_TD}-------------------------------------*/
#endif /* PROG_TRANSFER_DATA_ENABLE == STD_ON */

/*---------------------------{PROG_CRCSetParam}-----------------------------*/
void PROG_CRCSetParam(u32 ulAddress, u32 ulSize, tProgVerifAlgo ubAlgo, u8 ubContinue)
{
    DBG_PROG_CRCSETPARAM_ENTRY(ulAddress, ulSize, ubAlgo, ubContinue);

    /* Retrieve address to check */
    m_stDataProgVerification.ulAdd = ulAddress;
    m_stDataProgVerification.ulCnt = 0U;
    m_stDataProgVerification.ubAlgo = ubAlgo;

    if(PROG_FALSE == ubContinue)
    {
    /* Reset CRC variable */
#if((PROG_CRC_CALCULATION==PROG_TD_CRC16) || ((PROG_IMPL_VARIANT == PROG_IMPL_3) || \
    (PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_5)))
        m_stDataProgVerification.uwVal = PROG_CRC16_INIT_VAL;
#elif ((PROG_CRC_CALCULATION==PROG_TD_CRC32))
        /*set CRC flag to true */
        m_ubCrcStart = PROG_TRUE;
        m_stDataProgVerification.ulVal = PROG_CRC32_INIT_VAL;
#endif/*#elif ((PROG_CRC_CALCULATION==PROG_TD_CRC32)) */
    }
    else
    {
        /* Do nothing */
    }

    /* retrieve and store the length to calculate the CRC */
    m_stReprogInfo.ulReceivedSizeOfData = ulSize;
    m_stCurrentSegment.ulSize = ulSize;
#if (PROG_COMPRESSION_ENABLE == STD_ON)
    /* reset compression flag to make sure the correct length will be use for CRC calculation */
    m_stReprogInfo.ubCompRequired = FALSE;
#endif/*(PROG_COMPRESSION_ENABLE == STD_ON)*/

    DBG_PROG_CRCSETPARAM_EXIT();
}
/*---------------------------{end PROG_CRCSetParam}-------------------------*/


/*---------------------------{PROG_GetCrcValue}-----------------------------*/
#if (((PROG_CRC_CALCULATION == PROG_TD_CRC16) || (PROG_CRC_CALCULATION == PROG_TD_CRC_CUST)) || \
    ((PROG_IMPL_VARIANT == PROG_IMPL_3) || (PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_5)))
void PROG_GetCrcValue(u16* puwCrcVal)
{
    DBG_PROG_GETCRCVALUE_ENTRY(puwCrcVal);
    *puwCrcVal = m_stDataProgVerification.uwVal;
    DBG_PROG_GETCRCVALUE_EXIT();
}
/* CHECK: NOPARSE */
/* NOCOV-FEATURE_NOT_USED */
#elif (PROG_CRC_CALCULATION == PROG_TD_CRC32)
void PROG_GetCrcValue(u32* pulCrcVal)
{
    DBG_PROG_GETCRCVALUE_ENTRY(pulCrcVal);
    *pulCrcVal = m_stDataProgVerification.ulVal;
    DBG_PROG_GETCRCVALUE_EXIT();
}
/* CHECK: PARSE */
#endif
/*---------------------------{end PROG_GetCrcValue}-------------------------*/

/*---------------------------{PROG_SetNetworkStatus}-----------------------------*/
#if (PROG_NETWORK_MANAGEMENT_ENABLE == STD_ON)
void PROG_SetNetworkStatus(u16 uwNetworkStatus)
{
    DBG_PROG_SETNETWORKSTATUS_ENTRY(uwNetworkStatus);
    m_uwNetworkStatus = uwNetworkStatus;

    if(PROG_FR_NS_BOOT == m_uwNetworkStatus)
    {
        /* Reload timer*/
        UDS_ReloadTStopDiag();
    }
    DBG_PROG_SETNETWORKSTATUS_EXIT();
}
#endif
/*---------------------------{end PROG_SetNetworkStatus}-------------------------*/




/*---------------------------{PROG_SimulateOpenProgSessionNoResponse}----------------------*/
void PROG_SimulateOpenProgSessionNoResponse(void)
{
    PduLengthType ulLen;
    DBG_PROG_SIMULATEOPENPROGSESSIONNORESPONSE_ENTRY();

    if (TRUE == m_ubProgFirstCall)
    {

#if (PROG_DSC02_DENIED_IN_DEF_SESSION == STD_ON)
        PROG_SimulateExtendedSessionNoResponse();
#endif /*(PROG_DSC02_DENIED_IN_DEF_SESSION == STD_ON)*/

#if ((PROG_SECURITY_ENABLE == STD_ON) && (PROG_DSC_02_PROTECTED_BY_SA == STD_ON))
#if (PROG_NORESET_SECURITYLEVEL==STD_OFF)
        /* Set the SecurityLevel requested by ProgrammingSession*/
        PROG_SetSecurityLevel (PROG_SEC_LEVEL_PROGRAMMINGSESSION);
#endif
#endif

        ulLen = 2U;
        /* Open Diag Active Diagnostic session at the first APP_manage*/
        m_aubUdsData[0] = (u8) UDS_SRV_DSC;
        m_aubUdsData[1] = (u8) UDS_SESSION_PROGRAMMING;
        (void)EB_SimulateRxRequest(ulLen, m_aubUdsData, FALSE);
        m_ubProgFirstCall = FALSE;
    }
    DBG_PROG_SIMULATEOPENPROGSESSIONNORESPONSE_EXIT();
}
/*--------------------------{end PROG_SimulateOpenProgSessionNoResponse}-------------------*/


/*---------------------------{PROG_SimulateExtendedSessionNoResponse}----------------------*/
void PROG_SimulateExtendedSessionNoResponse(void)
{
#if (PROG_DSC02_DENIED_IN_DEF_SESSION == STD_ON)
    PduLengthType ulLen;

    ulLen = 2U;
    /* Open Extended Session */
    m_aubUdsData[0] = (u8) UDS_SRV_DSC;
    m_aubUdsData[1] = (u8) UDS_SESSION_EXTENDED_DIAG;
    (void)EB_SimulateRxRequest(ulLen, m_aubUdsData, FALSE);
#endif /*(PROG_DSC02_DENIED_IN_DEF_SESSION == STD_ON)*/
}
/*--------------------------{end PROG_SimulateExtendedSessionNoResponse}-------------------*/



/*---------------------------{PROG_SimulateCloseProgSession}----------------------*/
#if (PROG_RESET_CAUSE_ENABLE == STD_ON)
void PROG_SimulateCloseProgSession(void)
{
    PduLengthType ulLen;
    DBG_PROG_SIMULATECLOSEPROGSESSION_ENTRY();

    if (TRUE == m_ubProgFirstCall)
    {
#if (PROG_BLPDUR_SUPPORT_ENABLE == STD_ON)
        /* Retrieve connection information needed to send the response */
        BlPduR_RetrieveConnectionInfo();
#endif /*(PROG_BLPDUR_SUPPORT_ENABLE == STD_ON)*/

        /* Prepare the sending of response to DSC01 */
        ulLen = 6U;

        m_aubUdsData[0U]=(u8)(UDS_SRV_DSC + UDS_ACK);
        m_aubUdsData[1U]=(u8)(UDS_SESSION_DEFAULT);
        m_aubUdsData[2U]=(u8)((u16)(PROG_P2_DEFAULT_SESSION_VAL) >> 8U);
        m_aubUdsData[3U]=(u8) (PROG_P2_DEFAULT_SESSION_VAL);
        m_aubUdsData[4U]=(u8)((u16)((PROG_P2STAR_DEFAULT_SESSION_VAL) / 10U) >> 8U);
        m_aubUdsData[5U]=(u8)((PROG_P2STAR_DEFAULT_SESSION_VAL) / 10U);

        /* Send Message */
        EB_Send_TPFrame(ulLen, m_aubUdsData);
    }
    DBG_PROG_SIMULATECLOSEPROGSESSION_EXIT();
}
#endif /*(PROG_RESET_CAUSE_ENABLE == STD_ON)*/
/*--------------------------{end PROG_SimulateCloseProgSession}-------------------*/

/*----------------------------------{PROG_SimulateER}-----------------------------*/
void PROG_SimulateER(void)
{
#if (PROG_RESPOND_TO_PROG_SESSION == STD_ON)
    PduLengthType ulLen;
    DBG_PROG_SIMULATEER_ENTRY();

    if (TRUE == m_ubProgFirstCall)
    {
#if (PROG_BLPDUR_SUPPORT_ENABLE == STD_ON)
        /* Retrieve connection information needed to send the response */
        BlPduR_RetrieveConnectionInfo();
#endif /*(PROG_BLPDUR_SUPPORT_ENABLE == STD_ON)*/

        /* Prepare the sending of response to ER */
        ulLen = PROG_ECU_RESET_RESPONSE_SIZE;

        /* Reset type: HW */
        m_aubUdsData[0U]=(u8)(UDS_SRV_ER + UDS_ACK);
        m_aubUdsData[1U]=(u8)(UDS_SESSION_DEFAULT);

        /* Send Message */
        EB_Send_TPFrame(ulLen, m_aubUdsData);
    }
#else
    DBG_PROG_SIMULATEER_ENTRY();
#endif /*(PROG_RESPOND_TO_PROG_SESSION == STD_ON)*/
    DBG_PROG_SIMULATEER_EXIT();
}
/*--------------------------------{end PROG_SimulateER}---------------------------*/

/*---------------------------{PROG_SimulateOpenProgSession}----------------------*/
void PROG_SimulateOpenProgSession(void)
{
#if((PROG_BLPDUR_NETWORK_ETH_SUPPORTED != STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_10) && (PROG_IMPL_VARIANT != PROG_IMPL_11) && (PROG_IMPL_VARIANT != PROG_IMPL_90) && (PROG_IMPL_VARIANT != PROG_IMPL_91) && (PROG_RESPOND_TO_PROG_SESSION == STD_ON))
    u8 ubBitStatus;
    u16 uwLen;
#endif
#if (PROG_UPDATE_TP_PARAM_ENABLE == STD_ON)
    tProgStatus eProgStatus;
    u8 ubTpBsValue;
#if (PROG_IMPL_VARIANT == PROG_IMPL_50)
    u8 ubTpStminValue;
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_50)*/
#endif /*(PROG_UPDATE_TP_PARAM_ENABLE == STD_ON)*/
    DBG_PROG_SIMULATEOPENPROGSESSION_ENTRY();

    if (TRUE == m_ubProgFirstCall)
    {
#if (PROG_BLPDUR_SUPPORT_ENABLE == STD_ON)
        /* Retrieve connection information needed to send the response */
        BlPduR_RetrieveConnectionInfo();
#endif /*(PROG_BLPDUR_SUPPORT_ENABLE == STD_ON)*/

#if (PROG_DSC02_DENIED_IN_DEF_SESSION == STD_ON)
        PROG_SimulateExtendedSessionNoResponse();
#endif /*(PROG_DSC02_DENIED_IN_DEF_SESSION == STD_ON)*/

#if ((PROG_SECURITY_ENABLE == STD_ON) && (PROG_DSC_02_PROTECTED_BY_SA == STD_ON))
#if (PROG_NORESET_SECURITYLEVEL==STD_OFF)
        /* Set the SecurityLevel requested by ProgrammingSession*/
        PROG_SetSecurityLevel (PROG_SEC_LEVEL_PROGRAMMINGSESSION);
#endif
#endif

#if ((PROG_RESPOND_TO_PROG_SESSION == STD_ON) && (PROG_BLPDUR_NETWORK_ETH_SUPPORTED != STD_ON))
        m_ubSimulateProgSessionWithResponse = TRUE;
#else
        m_ubSimulateProgSessionWithResponse = FALSE;
#if (PROG_RESPOND_TO_PROG_SESSION == STD_OFF)
        /* Open Diag Active Diagnostic session at the first APP_manage*/
        m_aubUdsData[0] = (u8) UDS_SRV_DSC;
        m_aubUdsData[1] = (u8) UDS_SESSION_PROGRAMMING;
        (void)EB_SimulateRxRequest(2U, m_aubUdsData, m_ubSimulateProgSessionWithResponse);
#endif
#endif

#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
        /* SecurityAccess and CommunicationControl requests have been received in application mode */
        m_ubNormComEnabled = 0x00;
        m_ubIsLocked = 0x00;
#endif

#if (PROG_UPDATE_TP_PARAM_ENABLE == STD_ON)
        eProgStatus= PROG_CustomGetTpBsValue(&ubTpBsValue);
        if (PROG_E_OK == eProgStatus)
        {
            (void)BlPduR_TpChangeParameter(BLPDUR_TP_BS, (u16)ubTpBsValue);
#if (PROG_IMPL_VARIANT == PROG_IMPL_50)
            eProgStatus= PROG_CustomGetTpStminValue(&ubTpStminValue);
            if (PROG_E_OK == eProgStatus)
            {
                (void)BlPduR_TpChangeParameter(BLPDUR_TP_STMIN, (u16)ubTpStminValue);
            }
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_50)*/
        }
#endif /* (PROG_UPDATE_TP_PARAM_ENABLE == STD_ON) */

#if((PROG_BLPDUR_NETWORK_ETH_SUPPORTED != STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_10) && (PROG_IMPL_VARIANT != PROG_IMPL_11) && (PROG_IMPL_VARIANT != PROG_IMPL_90) && (PROG_IMPL_VARIANT != PROG_IMPL_91) && (PROG_RESPOND_TO_PROG_SESSION == STD_ON))

        /* Call callback to get SuppressPositiveResponse value from the DSC02 request */
        ubBitStatus = PROG_GetSuppressBitFromAppli();
        if (ubBitStatus == TRUE)
        {
            m_ubSimulateProgSessionWithResponse = FALSE;
        }
        /* Open Diag Active Diagnostic session at the first APP_manage*/
        m_aubUdsData[0] = (u8) UDS_SRV_DSC;
        m_aubUdsData[1] = (u8) UDS_SESSION_PROGRAMMING;
        (void)EB_SimulateRxRequest(2U, m_aubUdsData, m_ubSimulateProgSessionWithResponse);

        /* If positive response is not suppress */
        if (ubBitStatus == FALSE)
        {
#if (PROG_UDS_SPREC == STD_ON)
            uwLen = 6U;
            /* Prepare the sending of response to DSC02 */
            m_aubUdsData[2U] = (u8)((u16)(PROG_P2_PROG_SESSION_VAL) >> 8U);
            m_aubUdsData[3U] = (u8)(PROG_P2_PROG_SESSION_VAL);
            m_aubUdsData[4U] = (u8)((u16)((PROG_P2STAR_PROG_SESSION_VAL) / 10U) >> 8U);
            m_aubUdsData[5U] = (u8)((PROG_P2STAR_PROG_SESSION_VAL) / 10U);
#else
            uwLen = 2U;
#endif /* PROG_UDS_SPREC == STD_ON */
#if (PROG_IMPL_VARIANT != PROG_IMPL_20)
            /* Send Message */
            EB_Send_TPFrame(uwLen, m_aubUdsData);
#else
            OSC_PARAM_UNUSED(uwLen);
#endif
        }
#endif

        m_ubProgFirstCall = FALSE;

/* Set the information that response to 10 02 shall be answered */
/* It will be done later in PROG_SendDsc02Resp */
#if ((PROG_RESPOND_TO_PROG_SESSION == STD_ON) && ( (PROG_IMPL_VARIANT == PROG_IMPL_10) || (PROG_IMPL_VARIANT == PROG_IMPL_20) || (PROG_IMPL_VARIANT == PROG_IMPL_40) || (PROG_IMPL_VARIANT == PROG_IMPL_60) || (PROG_IMPL_VARIANT == PROG_IMPL_90) ))
        m_ubSendResponsetoOpenProgramming = PROG_TRUE;
#endif
    }
    DBG_PROG_SIMULATEOPENPROGSESSION_EXIT();
}
/*--------------------------{end PROG_SimulateOpenProgSession}-------------------*/

#if ( ((PROG_IMPL_VARIANT == PROG_IMPL_20) || (PROG_IMPL_VARIANT == PROG_IMPL_40) || (PROG_IMPL_VARIANT == PROG_IMPL_60) ) && (PROG_RESPOND_TO_PROG_SESSION == STD_ON))
/*---------------------------{PROG_SendDsc02Resp}-----------------------------*/
void PROG_SendDsc02Resp(void)
{
#if(PROG_BLPDUR_NETWORK_ETH_SUPPORTED == STD_ON)
    u8 ubBitStatus;
    u16 uwLen;

    DBG_PROG_SENDDSC02RESP_ENTRY();

    uwLen = 2U;
    /* Open Diag Active Diagnostic session at the first APP_manage*/
    m_aubUdsData[0] = (u8) UDS_SRV_DSC;
    m_aubUdsData[1] = (u8) UDS_SESSION_PROGRAMMING;
    m_ubSimulateProgSessionWithResponse = PROG_TRUE;
    (void)EB_SimulateRxRequest(uwLen, m_aubUdsData, m_ubSimulateProgSessionWithResponse);

    /* Call callback to get SuppressPositiveResponse value from the DSC02 request */
    ubBitStatus = PROG_GetSuppressBitFromAppli();
    if (ubBitStatus == FALSE)
    {
#if (PROG_UDS_SPREC == STD_ON)
        uwLen = 6U;
        m_aubUdsData[2U] = (u8)((u16)(PROG_P2_PROG_SESSION_VAL) >> 8U);
        m_aubUdsData[3U] = (u8)(PROG_P2_PROG_SESSION_VAL);
        m_aubUdsData[4U] = (u8)((u16)((PROG_P2STAR_PROG_SESSION_VAL) / 10U) >> 8U);
        m_aubUdsData[5U] = (u8)((PROG_P2STAR_PROG_SESSION_VAL) / 10U);
#endif /* PROG_UDS_SPREC == STD_ON */
#if (PROG_IMPL_VARIANT != PROG_IMPL_20)
    /* Send Message */
        EB_Send_TPFrame(uwLen, m_aubUdsData);
#endif
    }
#endif

    m_ubSimulateProgSessionWithResponse = PROG_FALSE;

    /* No more answer to Open Programming session must be answered */
    m_ubSendResponsetoOpenProgramming = PROG_FALSE;

#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
/* Only send the response to DSC02 if not in default session */
#if (PROG_DSC02_DENIED_IN_DEF_SESSION == STD_ON)
    if (UDS_GetCurrentSession() == UDS_SESSION_EXTENDED_DIAG)
#endif
    {
        /*The function EB_Send_TPFrame is used to send the NRC78, Actual data is sent by the this function*/
        UDS_LongRequestEnd(2U, &m_aubUdsData[0U], UDS_ACK);
    }
 
#endif

    DBG_PROG_SENDDSC02RESP_EXIT();
}
/*---------------------------{end PROG_SendDsc02Resp}-------------------------*/

#endif  /* (PROG_RESPOND_TO_PROG_SESSION == STD_ON) */

/*-----------------------------{PROG_Manage}-------------------------------------*/
void PROG_Manage(void)
{
    DBG_PROG_MANAGE_ENTRY();
#if (PROG_SLEEP_MANAGEMENT_TYPE == PROG_SLEEP_MANAGEMENT_TIMEOUT)
    /* Manage the Ready to Sleep state */
    PROG_ReadyToSleepManage();
#endif /* (PROG_SLEEP_MANAGEMENT_TYPE == PROG_SLEEP_MANAGEMENT_TIMEOUT) */

#if (PROG_NETWORK_MANAGEMENT_ENABLE == STD_ON)
    /*  Manage the network status */
    PROG_NetworkStatusManage();
#endif /* (PROG_NETWORK_MANAGEMENT_ENABLE == STD_ON) */

#if (PROG_HSM_UPDATE_ENABLE == STD_ON)
    /*Manage the Timeout Counter if Enable*/
    PROG_HSMStatusManage();
#endif

    DBG_PROG_MANAGE_EXIT();
}
/*---------------------------{end PROG_Manage}-----------------------------------*/

/*---------------------------{PROG_BckdManage}-----------------------------------*/
void PROG_BckdManage(void)
{
    DBG_PROG_BCKDMANAGE_ENTRY();
#if (PROG_CSMASR43_USED == STD_ON)
    /* Manages the ongoing Asynchronous Crypto operation */
    PROG_CsmManage();
#endif
#if(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)
    if (m_ubPendingSendNRC78 == TRUE)
    {
        /* A request to send a NRC78 is pending, send the NRC78 and wait TxConf before
        executing PROG_HsmMain */
        m_ubPendingSendNRC78 = FALSE;
        PROG_SendNRC78();
        m_ubPendingNRC78 = TRUE;
    }
    else if (m_ubPendingNRC78 == FALSE)
#endif
    {
        PROG_HsmMain (&PROG_HsmScPROG);
    }
#if(PROG_MULTIPLE_BUFFERS_ENABLE == STD_ON)
    else
    {
        /* Nothing to do */
    }
#endif
    DBG_PROG_BCKDMANAGE_EXIT();
}
/*-------------------------{end PROG_BckdManage}---------------------------------*/

#if (PROG_SLEEP_MANAGEMENT_TYPE == PROG_SLEEP_MANAGEMENT_TIMEOUT)
/*-----------------------{PROG_ReadyToSleepManage}-------------------------------*/
INLINE void PROG_ReadyToSleepManage(void)
{
    /* FAFO  "To be checked if the following is maintained ! JLR specs have changed: sleep is done only from default session !" */

    /* Check if bootloader is in Ready to sleep mode */
    if (0U < m_ulSleepTimeout)
    {
        /* Check the Ready to sleep timeout */
        if (1U == m_ulSleepTimeout)
        {
            /* Post event in state machine to trig the got to sleep mode */
            PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_SLEEP);
        }

        /* Decremented counter*/
        m_ulSleepTimeout--;
    }
}
/*---------------------{end PROG_ReadyToSleepManage}-----------------------------*/
#endif /* (PROG_SLEEP_MANAGEMENT_TYPE == PROG_SLEEP_MANAGEMENT_TIMEOUT) */

#if (PROG_NETWORK_MANAGEMENT_ENABLE == STD_ON)
/*----------------------{PROG_NetworkStatusManage}-------------------------------*/
INLINE void PROG_NetworkStatusManage(void)
{
    tUdsSessionType CurrentSession;
    u16 uwNetworkStatus;

    /* If the current session is programming */
    CurrentSession = UDS_GetCurrentSession();
    if (UDS_SESSION_PROGRAMMING == CurrentSession)
    {
        /* Read the NetworkStatus */
        uwNetworkStatus = PROG_GetNetworkStatus();

        /* if NetworkStatus is different than "boot" trigger a reset */
        if (uwNetworkStatus != PROG_FR_NS_BOOT)
        {
            /* Post event in state machine to perform a reset */
            PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_RESET);
        }
    }
}
/*--------------------{end PROG_NetworkStatusManage}-----------------------------*/
#endif /* PROG_NETWORK_MANAGEMENT_ENABLE */

/*----------------------{PROG_GetSegmentBySegmentId}-------------------------------*/
#if (((PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK) || (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT)) && (PROG_REQUEST_DOWNLOAD_ENABLE == STD_ON))
tProgStatus PROG_GetSegmentBySegmentId(u8 ubBlockId, u8 ubSegmentId, u32 ulMemoryLength, u32* pulMemoryAddress, u8 * pubSegmentId)
{
    u32 ulMemoryMaxLength;
    tProgStatus eProgStatus;
    eProgStatus = PROG_E_NOT_OK;

    DBG_PROG_GETSEGMENTBYSEGMENTID_ENTRY(ubBlockId, ubSegmentId, ulMemoryLength, pulMemoryAddress, pubSegmentId);

    if (ubBlockId < PROG_BLOCK_NB)
    {
#if (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT)
        if (ubSegmentId <= stCfgBlock[ubBlockId].ubSegmentNbr)
        {
            *pubSegmentId = (stCfgBlock[ubBlockId].ubFirstSegmentId + ubSegmentId) - 1U;

            /* Compute the maximum length acceptable in the request */
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
            if(PROG_NODECRYPTION_NOCOMPRESSION != m_ubEncryptionMethod)
            {
                ulMemoryMaxLength = (stConfigSegment[*pubSegmentId].ulEndAddress - stConfigSegment[*pubSegmentId].ulStartAddress) + 1U + PROG_AES_BLOCK_SIZE;
            }
            else
#endif
            {
                ulMemoryMaxLength = (stConfigSegment[*pubSegmentId].ulEndAddress - stConfigSegment[*pubSegmentId].ulStartAddress) + 1U;
            }

            /* If the length retrieved from the request is in the acceptable range */
            if (ulMemoryLength <= ulMemoryMaxLength)
            {
                if ((stConfigSegment[*pubSegmentId].eSegAccessType == PROG_MEM_ACCESS_TYPE_READ_WRITE) || \
                    (stConfigSegment[*pubSegmentId].eSegAccessType == PROG_MEM_ACCESS_TYPE_WRITE))
                {
                    eProgStatus = PROG_E_OK;

                    /* Update address with segment address */
                    *pulMemoryAddress = stConfigSegment[*pubSegmentId].ulStartAddress;
                }
            }
        }
#endif /* (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT) */
#if (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK)
        OSC_PARAM_UNUSED(ubSegmentId);

        /* Collect the segment Identifier */
        *pubSegmentId = stCfgBlock[ubBlockId].ubFirstSegmentId;

        /* Compute the maximum length acceptable in the request */
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
            if(PROG_NODECRYPTION_NOCOMPRESSION != m_ubEncryptionMethod)
            {
                ulMemoryMaxLength = (stConfigSegment[*pubSegmentId].ulEndAddress - stConfigSegment[*pubSegmentId].ulStartAddress) + 1U + PROG_AES_BLOCK_SIZE;
            }
            else
#endif
            {
                ulMemoryMaxLength = (stConfigSegment[*pubSegmentId].ulEndAddress - stConfigSegment[*pubSegmentId].ulStartAddress) + 1U;
            }

        /* If the length retrieved from the request is in the acceptable range */
        if (ulMemoryLength <= ulMemoryMaxLength)
        {
            if ((stConfigSegment[*pubSegmentId].eSegAccessType == PROG_MEM_ACCESS_TYPE_READ_WRITE) || \
                (stConfigSegment[*pubSegmentId].eSegAccessType == PROG_MEM_ACCESS_TYPE_WRITE))
            {
                eProgStatus = PROG_E_OK;

                /* Update address with segment address */
                *pulMemoryAddress = stConfigSegment[*pubSegmentId].ulStartAddress;
            }
        }
#endif
    }

    OSC_PARAM_UNUSED(pubSegmentId);
    DBG_PROG_GETSEGMENTBYSEGMENTID_EXIT(eProgStatus);
    return eProgStatus;
}
#endif /* (((PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK) || (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT)) && (PROG_REQUEST_DOWNLOAD_ENABLE == STD_ON)) */
/*--------------------{end PROG_GetSegmentBySegmentId}-----------------------------*/
#if (((PROG_ERASE_MEMORY_ENABLE == STD_ON)&&(PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR))||(PROG_REQUEST_DOWNLOAD_ENABLE == STD_ON))
#define PROG_MEMORY_END_ADDRESS (ulMemoryAddress + ulMemoryLength)
#define PROG_MEMORY_START_ADDRESS  ulMemoryAddress
/*----------------------{PROG_GetSegmentByAddress}-------------------------------*/
tProgStatus PROG_GetSegmentByAddress(u32 ulMemoryAddress, u32 ulMemoryLength, tOperationType eOperationType, u8 * pubSegmentId)
{
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
    u32 ulMemoryMaxLength;
#endif
    u8 iSegment;
    tProgStatus eProgStatus;

    DBG_PROG_GETSEGMENTBYADDRESS_ENTRY(ulMemoryAddress, ulMemoryLength, eOperationType, pubSegmentId);

    eProgStatus = PROG_E_NOT_OK;

    /* Check if there is no overflow */
    if(PROG_MEMORY_START_ADDRESS <= (0xFFFFFFFFU - ulMemoryLength))
    {
        /* Look in configuration for the segment matching the provided address and length */

        for (iSegment = 0U;
                (iSegment < PROG_SEGMENT_NB) && (PROG_E_NOT_OK == eProgStatus);
                iSegment++)
        {
            if((stConfigSegment[iSegment].eSegAccessType == PROG_MEM_ACCESS_TYPE_READ_WRITE)
            || ((stConfigSegment[iSegment].eSegAccessType == PROG_MEM_ACCESS_TYPE_WRITE) && ((eOperationType==PROG_MEM_OPERATION_TYPE_ERASE)
            || (eOperationType==PROG_MEM_OPERATION_TYPE_WRITE)))
            || ((stConfigSegment[iSegment].eSegAccessType == PROG_MEM_ACCESS_TYPE_READ) && (eOperationType==PROG_MEM_OPERATION_TYPE_READ)))
            {
                if (PROG_MEM_OPERATION_TYPE_ERASE == eOperationType)
                {
                    if ((PROG_MEMORY_START_ADDRESS
                                    >= stConfigSegment[iSegment].ulEraseStartAddress)
                                    && (PROG_MEMORY_END_ADDRESS
                                    <= (stConfigSegment[iSegment].ulEraseEndAddress + 1U)))
                    {
                        /* Segment is found */
                        *pubSegmentId = iSegment;
                        eProgStatus = PROG_E_OK;
                    }
                }
                else
                {
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
                if(PROG_NODECRYPTION_NOCOMPRESSION != m_ubEncryptionMethod)
                {
                  ulMemoryMaxLength = stConfigSegment[iSegment].ulEndAddress + PROG_AES_BLOCK_SIZE + 1;
                }
                else
                {
                  ulMemoryMaxLength = stConfigSegment[iSegment].ulEndAddress + 1;
                }
#endif
#if (PROG_IMPL_VARIANT == PROG_IMPL_20)
#if (PROG_HSM_UPDATE_ENABLE == STD_ON)
                    /* Check if the area is included in a HSM configured segment*/
                    if( (stConfigSegment[iSegment].ePartitionType == PROG_HSM_PARTITION) && ((PROG_MEMORY_START_ADDRESS >= stConfigSegment[iSegment].ulStartAddress)
                                                && (PROG_MEMORY_END_ADDRESS <= (stConfigSegment[iSegment].ulEndAddress + 1U))) )
                    {
                        /* Segment is found */
                        *pubSegmentId = iSegment;
                        eProgStatus = PROG_E_OK;
                    }
                    /* Check if the area is included in a configured segment without overlapping the PSI area */
                    else if ((PROG_MEMORY_START_ADDRESS >= stConfigSegment[iSegment].ulStartAddress)
#else
                    if ((PROG_MEMORY_START_ADDRESS >= stConfigSegment[iSegment].ulStartAddress)
#endif
                            && (PROG_MEMORY_END_ADDRESS <= ((stConfigSegment[iSegment].ulEndAddress + 1U) - PROG_PSI_SIZE)))
#else
                    /* Check if the area is included in a configured segment*/
                    if ((PROG_MEMORY_START_ADDRESS >= stConfigSegment[iSegment].ulStartAddress)
                            && (PROG_MEMORY_END_ADDRESS
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
                                <= ulMemoryMaxLength))
#else
                                    <= (stConfigSegment[iSegment].ulEndAddress + 1U)))
#endif
#endif
                    {
                        /* Segment is found */
                        *pubSegmentId = iSegment;
                        eProgStatus = PROG_E_OK;
                    }
                    else
                    {
                        /*Do Nothing*/
                    }
                }
            }
        }
    }

    DBG_PROG_GETSEGMENTBYADDRESS_EXIT(eProgStatus);
    return eProgStatus;
}
/*--------------------{end PROG_GetSegmentByAddress}-----------------------------*/
#undef PROG_MEMORY_END_ADDRESS
#undef PROG_MEMORY_START_ADDRESS
#endif /* (((PROG_ERASE_MEMORY_ENABLE == STD_ON)&&(PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR))||(PROG_REQUEST_DOWNLOAD_ENABLE == STD_ON)) */

#if ((PROG_ERASE_MEMORY_ENABLE == STD_ON)&&(PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID))
/*----------------------{PROG_GetSegmentByBlockId}-------------------------------*/
tProgStatus PROG_GetSegmentByBlockId(u8 ubBlockId,
        u8 * pubSegmentId, u8 * pubSegmentNbr)
{
    tProgStatus eProgStatus;

    eProgStatus = PROG_E_NOT_OK;

    /* Look in configuration for the segments matching the provided address and length */
    if(ubBlockId < PROG_BLOCK_NB)
    {
        /* Block exists in configuration */
        *pubSegmentId = stCfgBlock[ubBlockId].ubFirstSegmentId;
        *pubSegmentNbr = stCfgBlock[ubBlockId].ubSegmentNbr;
        eProgStatus = PROG_E_OK;
    }
    return eProgStatus;
}
/*--------------------{end PROG_GetSegmentByBlockId}-----------------------------*/
#endif /* ((PROG_ERASE_MEMORY_ENABLE == STD_ON)&&(PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID)) */

#if PROG_REQUEST_DOWNLOAD_ENABLE == STD_ON
/*-----------------------{PROG_ExtractRDParameter}-------------------------------*/
NCS_PRI_FCT tProgStatus PROG_ExtractRDParameter(const u8 * pubUdsData,
        PduLengthType ulDataLength, tRDParam* pstRDParam, tUdsStatus* eUdsStatus)
{
    u8 ubLoopIndex;
    u8 ubMemoryAddressLength;
    u8 ubMemorySizeByteLength;
    tProgStatus eProgStatus;

    eProgStatus = PROG_E_NOT_OK;

    /* Retrieve Data format identifier */
    pstRDParam->ubDataFormatId = pubUdsData[0];

    /* Retrieve AddressAndLengthFormatIdenfier */
    ubMemoryAddressLength = (u8)(pubUdsData[1] & 0x0FU);
    ubMemorySizeByteLength = (u8)((u8)(pubUdsData[1] & 0xF0U) >> 4U);

    /* Check ALFID is correct < PROG_MAX_RD_ADDRESS_LENGTH */
    if ((ubMemoryAddressLength > 0U) && (ubMemorySizeByteLength > 0U) && (ubMemoryAddressLength <= PROG_MAX_RD_ADDRESS_LENGTH) && (ubMemorySizeByteLength <= 4U))
    {
        /* Check if enough data are received */
        if ((u16)((u16)ubMemoryAddressLength + (u16)ubMemorySizeByteLength)
                == (ulDataLength - 2U))
        {
            pstRDParam->ulStartAddress = 0U;
            pstRDParam->ulMemorySize   = 0U;
            pstRDParam->uwBlockIdentifier = 0U;
            pstRDParam->ubSegmentId    = 0U;

            /* Retrieve Address */
            for (ubLoopIndex = 0U; ubLoopIndex < ubMemoryAddressLength; ubLoopIndex++)
            {
                pstRDParam->ulStartAddress |= (uint32)(
                        (uint32)(pubUdsData[ubLoopIndex + 2U])
                        << (uint8)(
                                ((ubMemoryAddressLength - 1U
                                                - ubLoopIndex) * 8U)));
            }

            /* Retrieve Length */
            for (/*NoInit*/; ubLoopIndex < (ubMemoryAddressLength + ubMemorySizeByteLength); ubLoopIndex++)
            {
                pstRDParam->ulMemorySize |=
                (uint32)(
                        (uint32)(pubUdsData[ubLoopIndex + 2U])
                        << (uint8)(
                                (ubMemorySizeByteLength - 1U
                                        - (ubLoopIndex
                                                - ubMemoryAddressLength)) * 8U));
            }

#if (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT)
            /* Separate block info and segment info */
            /* For Block index, keep only up to two bytes after the LSB */
            pstRDParam->uwBlockIdentifier = (uint16)(pstRDParam->ulStartAddress >> 8U);
            /* For segment index, always keep the LSB */
            pstRDParam->ubSegmentId = (u8)(pstRDParam->ulStartAddress);
#endif /* (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT) */

#if (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK)
            /* get block info */
            pstRDParam->uwBlockIdentifier = (uint16)(pstRDParam->ulStartAddress);
#endif /* (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK) */

            /* Prepare positive return status */
            eProgStatus = PROG_E_OK;
        }
        else
        {
            /* Set negative status */
            *eUdsStatus = UDS_NRC_13;
        }
    }
    else
    {
        /* Set negative status */
        *eUdsStatus = UDS_NRC_31;
    }
    return eProgStatus;
}
/*---------------------{end PROG_ExtractRDParameter}-----------------------------*/
#endif /* PROG_REQUEST_DOWNLOAD_ENABLE == STD_ON */

#if PROG_REQUEST_DOWNLOAD_ENABLE == STD_ON
/*----------------------------{PROG_CheckDFI}------------------------------------*/
NCS_PRI_FCT tProgStatus PROG_CheckDFI(u8 ubDFIvalue)
{
    tProgStatus eProgStatus;
#if (PROG_DECRYPTION_ENABLE == STD_ON)
    m_ubEncryptionMethod = ubDFIvalue & 0x0FU;
#endif

    eProgStatus = PROG_E_NOT_OK;

    switch (ubDFIvalue)
    {

        case PROG_DFI_COMPRESSED_ENCRYPTED_VAL:
#if((PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_IN_DFI))
            m_ubVerificationMethod = PROG_VERIFICATION_SIGNATURE_AND_CRC;
#endif
#if ((PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_DECRYPTION_ENABLE == STD_ON))
            m_stReprogInfo.ubCompRequired = TRUE;
            eProgStatus = PROG_E_OK;
#endif
            break;

        case PROG_DFI_COMPRESSED_VAL:
#if((PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_IN_DFI))
            m_ubVerificationMethod = PROG_VERIFICATION_SIGNATURE_AND_CRC;
#endif
#if (PROG_COMPRESSION_ENABLE == STD_ON)
            m_stReprogInfo.ubCompRequired = TRUE;
            eProgStatus = PROG_E_OK;
#endif
            break;

        case PROG_DFI_ENCRYPTED_VAL:
#if((PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_IN_DFI))
            m_ubVerificationMethod = PROG_VERIFICATION_SIGNATURE_AND_CRC;
#endif
#if (PROG_DECRYPTION_ENABLE == STD_ON)
            eProgStatus = PROG_E_OK;
#endif
            break;

        case 0x00U:
#if((PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_IN_DFI))
            m_ubVerificationMethod = PROG_VERIFICATION_SIGNATURE;
            m_ubCRC_Calculation = PROG_NO_CRC;
#endif

#if (PROG_COMPRESSION_ENABLE == STD_ON)
            m_stReprogInfo.ubCompRequired = FALSE;
#endif
            eProgStatus = PROG_E_OK;
            break;

        default:
            /* Nothing, eProgStatus already set to NOT_OK */
            break;
    }
#if (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_IN_DFI)
    if (m_ubVerificationMethod == PROG_VERIFICATION_SIGNATURE_AND_CRC)
    {
            m_ubCRC_Calculation = PROG_TD_CRC32;
    }
#endif
    return eProgStatus;
}
/*--------------------------{end PROG_CheckDFI}----------------------------------*/
#endif /* PROG_REQUEST_DOWNLOAD_ENABLE == STD_ON */

#if PROG_TRANSFER_DATA_ENABLE == STD_ON
/*--------------------{PROG_IncrementBlockSequenceCounter}-----------------------*/
void PROG_IncrementBlockSequenceCounter(void)
{
    if (m_stReprogInfo.ubBlockSequenceCounter == PROG_BLOCK_SEQU_MAX)
    {
        m_stReprogInfo.ubBlockSequenceCounter = 0x0;
    }
    else
    {
        m_stReprogInfo.ubBlockSequenceCounter++;
    }
}
/*------------------{end PROG_IncrementBlockSequenceCounter}---------------------*/
#endif /* PROG_TRANSFER_DATA_ENABLE == STD_ON */

#if PROG_TRANSFER_DATA_ENABLE == STD_ON
/*---------------------------{PROG_WriteStatusCheck}-----------------------------*/
NCS_PRI_FCT void PROG_WriteStatusCheck(tProgStatus eProgStatus)
{
    switch (eProgStatus)
    {
        case PROG_E_OK:
#if (PROG_COMPRESSION_ENABLE == STD_ON)
            if (m_stReprogInfo.ubCompRequired == TRUE)
            {
                /* Notify SA decompression module that writing is finished */
#if (PROG_CAL_PRESENT == STD_OFF)
                SA_DecompWriteDataConfirmation((u16)(m_stWriteInfo.ulWriteLength & 0x0000FFFFU));
                PROG_WriteStatusCheck_SubFunction();
#else
                PROG_DecompWriteDataConfirmation((u16)(m_stWriteInfo.ulWriteLength & 0x0000FFFFU));
                /* Request decompression of remaining compress data if needed */
                eProgStatus = PROG_DecompressData (NULL_PTR,0);

                if(eProgStatus != PROG_E_OK)
                {
#if PROG_PEC_ENABLE == STD_ON
                    /* set error in PEC */
                    m_uwPEC = PROG_ERR_COMPRESSION;
#endif
                    /* Send negative response NRC31 */
                    m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_31;
                }
                else
                {
                    PROG_WriteStatusCheck_SubFunction();
                }
#endif
            }
            else
            {
                PROG_WriteStatusCheck_SubFunction();
            }
#else
            PROG_WriteStatusCheck_SubFunction();

#endif /*(PROG_COMPRESSION_ENABLE == STD_ON)        */
            /* Emit event PROG_EVENT_WRITE_CHECK */
            PROG_HsmEmit(&PROG_HsmScPROG,
                    PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK);
            break;
        case PROG_E_BUSY:
            /* Nothing to do */
            break;
        default:
#if PROG_PEC_ENABLE == STD_ON
            /* Set error in PEC */
            m_uwPEC = PROG_ERR_FLASH_WRITE;
#endif
            /*Store NRC_72 as error value*/
            m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_72;

            /* Emit event PROG_EVENT_WRITE_CHECK */
            PROG_HsmEmit(&PROG_HsmScPROG,
                    PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK);
            break;
    }
}
/*-------------------------{end PROG_WriteStatusCheck}---------------------------*/

/*-------------------{PROG_WriteStatusCheck_SubFunction}---------------------------*/
NCS_PRI_FCT void PROG_WriteStatusCheck_SubFunction(void)
{
    /*Increase number of data written*/
    m_stWriteInfo.ulWrittenData += (m_stWriteInfo.ulWriteLength - m_stPageBuffer.ulOldDataLength);

    /*Reset Page Buffer variable*/
    m_stPageBuffer.ulOldDataLength = 0U;
    m_stPageBuffer.ulNewDataLength = 0U;

    /* increase next address to write */
    m_stWriteInfo.ulAddressToWrite += m_stWriteInfo.ulWriteLength;

#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
    if (m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)
    {
        /* Increment the total decrypted and written data */
        m_stCryptoData.ulTotDecryptedWrittenSize += m_stWriteInfo.ulWriteLength;
    }
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
}
/*-----------------{end PROG_WriteStatusCheck_SubFunction}-------------------------*/
#endif /* if PROG_TRANSFER_DATA_ENABLE == STD_ON */

#if PROG_SECURITY_ENABLE == STD_ON
/*---------------------------{PROG_SetSecurityLevel}-----------------------------*/
void PROG_SetSecurityLevel(u8 ubSecurityLevel)
{
    DBG_PROG_SETSECURITYLEVEL_ENTRY(ubSecurityLevel);
    m_ubProgSecurityLevel = ubSecurityLevel;
    DBG_PROG_SETSECURITYLEVEL_EXIT();
}
#endif /* if PROG_SECURITY_ENABLE == STD_ON */
/*-------------------------{end PROG_SetSecurityLevel}---------------------------*/

#if ((PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK) || (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT) || ((PROG_ERASE_ALL == STD_OFF) && (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID)))
/*------------------------{PROG_FindBlockIndexInTable}--------------------------*/
tProgStatus PROG_FindBlockIndexInTable(u16 uwBlockIdent, u8 * pubBlockId)
{
    u8 ubLoopIndex;
    tProgStatus eIndexFound = PROG_E_NOT_OK;

    DBG_PROG_FINDBLOCKINDEXINTABLE_ENTRY(uwBlockIdent, pubBlockId);

    for (ubLoopIndex = 0U; (ubLoopIndex < PROG_BLOCK_NB) && (PROG_E_NOT_OK == eIndexFound); ubLoopIndex++)
    {
        /* Find the corresponding index of block in the table */
        if (stCfgBlock[ubLoopIndex].uwBlockIdentifier == uwBlockIdent)
        {
            /* Index has been found, parsing of index will stop here */
            eIndexFound = PROG_E_OK;

            /* Update the block index with the stCfgBlock table index */
            *pubBlockId = ubLoopIndex;
        }
    }

    DBG_PROG_FINDBLOCKINDEXINTABLE_EXIT(eIndexFound);

    return eIndexFound;
}
/*-------------------------{end PROG_FindBlockIndexInTable}---------------------------*/
#endif /* ((PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK) || (PROG_DOWNLOAD_TYPE == PROG_DOWNLOAD_BY_LOGICAL_BLOCK_SEGMENT) || ((PROG_ERASE_ALL == STD_OFF) && (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID))) */

#if PROG_ERASE_MEMORY_ENABLE == STD_ON
/*------------------------{PROG_ExtractEraseParameters}--------------------------*/
NCS_PRI_FCT tProgStatus PROG_ExtractEraseParameters(const u8 * pubUdsData,
        tSegmentType * pstSegment, tUdsStatus * eUdsStatus, u8 * pubBlockId)
{
    tProgStatus eProgStatus = PROG_E_NOT_OK;
#if ((PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR) || (PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID))
#if (PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR) || ((PROG_ERASE_ALL == STD_OFF) && (PROG_BLOCKID_IN_FINGERPRINT == STD_OFF))
    u8 ubLoopIndex;
#endif /* (PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR) || ((PROG_ERASE_ALL == STD_OFF) && (PROG_BLOCKID_IN_FINGERPRINT == STD_OFF)) */
#if PROG_USE_START_ADDR_END_ADDR == STD_ON
    u32 ulEndAddress;
#endif /*PROG_USE_START_ADDR_END_ADDR == STD_ON*/
#endif /*PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR*/
#if PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID
#if (PROG_ERASE_ALL == STD_OFF)
#if PROG_BLOCKID_IN_FINGERPRINT == STD_OFF
    u8 ubBlockIdLength;
#endif
    u16 uwBlockIdent = 0U;
    tProgStatus eIndexFound = PROG_E_NOT_OK;
#endif /*PROG_ERASE_ALL == STD_OFF*/
#if (PROG_ERASE_CHECK_TYPE != PROG_DISABLED_ERASE_CHECK)
    tProgEraseStatus eEraseStatus;
#endif /*(PROG_ERASE_CHECK_TYPE != PROG_DISABLED_ERASE_CHECK)*/
#endif /*PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID*/
#if PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR
    u8 ubMemoryAddressLength;
    u8 ubMemorySizeByteLength;
#endif /*PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR*/

#if PROG_BLOCKID_IN_FINGERPRINT == STD_ON
    OSC_PARAM_UNUSED(pubUdsData);
#endif

    *pubBlockId = 0xFFU;

#if ((PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID) && (PROG_ERASE_ALL == STD_OFF))
    eProgStatus = PROG_E_NOT_OK;
#endif /*if ((PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID) && (PROG_ERASE_ALL == STD_OFF))*/

#if PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR

#if PROG_ERASE_ALFI == STD_ON
    /* Retrieve AddressAndLengthFormatIdenfier */
    ubMemoryAddressLength = (u8)(pubUdsData[0U] & 0x0FU);
    ubMemorySizeByteLength = (u8)((u8)(pubUdsData[0U] & 0xF0U) >> 4U);

    /* Check ALFID is correct < 4 */
    if ((ubMemoryAddressLength > 0U) && (ubMemorySizeByteLength > 0U) && (ubMemoryAddressLength <= 4U) && (ubMemorySizeByteLength <= 4U))
#else /* PROG_ERASE_ALFI == STD_ON  */
        ubMemoryAddressLength = PROG_ERASE_ADDR_LEN;
        ubMemorySizeByteLength = PROG_ERASE_SIZE_LEN;

#endif /* PROG_ERASE_ALFI == STD_ON  */
    {
        /* Check if enough data are received */
        if ((u16)((u16)ubMemoryAddressLength + (u16)ubMemorySizeByteLength + 4U)
                <= m_stDiagMessageInfo.ulLength)
        {
            pstSegment->ulStartAddress = 0U;
            /* Retrieve Address*/
            for (ubLoopIndex = 0U; ubLoopIndex < ubMemoryAddressLength; ubLoopIndex++)
            {
#if PROG_ERASE_ALFI == STD_ON
            pstSegment->ulStartAddress |= (uint32)(
                    (uint32)(pubUdsData[ubLoopIndex + 1U])
                    << (uint8)(
                            ((ubMemoryAddressLength - (ubLoopIndex + 1U))
                                    * 8U)));
#else /* PROG_ERASE_ALFI == STD_ON  */
            pstSegment->ulStartAddress |= (uint32)(
                    (uint32)(pubUdsData[ubLoopIndex])
                    << (uint8)(
                            ((ubMemoryAddressLength - 1U - ubLoopIndex)
                                    * 8U)));
#endif /* PROG_ERASE_ALFI == STD_ON  */
            }
            pstSegment->ulSize = 0U;
        /* Retrieve Length */
#if PROG_USE_START_ADDR_END_ADDR == STD_OFF
            for (ubLoopIndex = ubMemoryAddressLength;
                    ubLoopIndex < (ubMemoryAddressLength + ubMemorySizeByteLength);
                    ubLoopIndex++)
            {
#if PROG_ERASE_ALFI == STD_ON
                pstSegment->ulSize |=   (uint32)(
                                        (uint32)(pubUdsData[ubLoopIndex+1U])
                                        << (uint8)(
                                                    ((ubMemoryAddressLength + ubMemorySizeByteLength)
                                                    - (ubLoopIndex + 1U))
                                                    * 8U));
#else /* PROG_ERASE_ALFI == STD_ON */
                pstSegment->ulSize |=   (uint32)(
                                        (uint32)(pubUdsData[ubLoopIndex])
                                        << (uint8)(
                                                    ((ubMemoryAddressLength + ubMemorySizeByteLength) - 1U
                                                    - ubLoopIndex)
                                                    * 8U));
#endif /* PROG_ERASE_ALFI == STD_ON  */
            }
#elif PROG_USE_START_ADDR_END_ADDR == STD_ON
            ulEndAddress = 0U;
            for (/*NoInit*/;
                    ubLoopIndex < (ubMemoryAddressLength + ubMemorySizeByteLength);
                    ubLoopIndex++)
            {
                ulEndAddress |= (uint32)(
                        (uint32)(pubUdsData[ubLoopIndex])
                                << (uint8)(
                                        (ubMemorySizeByteLength - 1U
                                                - (ubLoopIndex - ubMemoryAddressLength))
                                                * 8U));
            }
            /*Calculate Length*/
            if(ulEndAddress > pstSegment->ulStartAddress)
            {
                pstSegment->ulSize = (ulEndAddress - pstSegment->ulStartAddress) + 1U;
            }
            else
            {
                /*invalid end address, return length 0*/
                /*This will generate a NRC_31 after the call of PROG_GetSegmentByAddress*/
                pstSegment->ulSize = 0U;
            }
#endif

            /* Check address*/
            eProgStatus = PROG_GetSegmentByAddress(pstSegment->ulStartAddress,
                    pstSegment->ulSize, PROG_MEM_OPERATION_TYPE_ERASE,
                    &pstSegment->ubSegmentId);
            pstSegment->ubSegmentNbr = 1U;

#if (PROG_IMPL_VARIANT == PROG_IMPL_11)
    if (PROG_E_OK == eProgStatus)
    {
        eProgStatus = PROG_ExtractEraseParameters_Impl11(pstSegment);
    }
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_11) */
#if ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_60))
            /* Check if the fingerprint for the current partition type was written*/
            if (((stConfigSegment[pstSegment->ubSegmentId].ePartitionType == PROG_APPLICATION_PARTITION) &&
                (m_stWfSuccess.ubAppFingerprintWriten == PROG_TRUE))                                     ||
                ((stConfigSegment[pstSegment->ubSegmentId].ePartitionType == PROG_CALIBRATION_PARTITION) &&
                (m_stWfSuccess.ubCalFingerprintWriten == PROG_TRUE)))
#endif /* ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_60)) */
            {
                if ((PROG_E_OK == eProgStatus) || (PROG_E_BYPASS == eProgStatus))
                {
                    /* Prepare positive return status */
                    *eUdsStatus = UDS_ACK;
                }
                else
                {
                    /* Set negative status */
                    *eUdsStatus = UDS_NRC_31;
                }
            }
#if ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_60))
            else
            {
                /* Set negative status */
                *eUdsStatus = UDS_NRC_24;
                eProgStatus = PROG_E_NOT_OK;
            }
#endif /* ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_60)) */
        }
        else
        {
            /* Set negative status */
            *eUdsStatus = UDS_NRC_13;
        }
    }
#if PROG_ERASE_ALFI == STD_ON
    else
    {
        /* Set negative status */
        *eUdsStatus = UDS_NRC_31;
    }
#endif
#endif /* PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR */

#if PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID
#if PROG_ERASE_ALL == STD_OFF
#if PROG_BLOCKID_IN_FINGERPRINT == STD_ON
    uwBlockIdent = m_ubFpBlockId;
#else /*#if PROG_BLOCKID_IN_FINGERPRINT == STD_OFF*/
    /* Retrieve AddressAndLengthFormatIdenfier */
    ubBlockIdLength = (u8)(pubUdsData[0] & (u8)0x0F);

    /* Check ALFID is correct */
    if ((PROG_MAX_BYTE_ERASE_BLOCK_LENGTH >= ubBlockIdLength) && (0U < ubBlockIdLength))
    {
        /* Check if enough data are received */
        if (ubBlockIdLength <= (m_stDiagMessageInfo.ulLength - 5U))
        {
            /* Retrieve BlockId */
            for (ubLoopIndex = 0U; ubLoopIndex < ubBlockIdLength; ubLoopIndex++)
            {
                uwBlockIdent |= (uint16) ( (uint16)(pubUdsData[ubLoopIndex + 1U]) <<  (uint8)(((ubBlockIdLength - 1U - ubLoopIndex) * 8U)));
            }
#endif /*PROG_BLOCKID_IN_FINGERPRINT == STD_ON*/

            /* Find the index table from block identifier */
            eIndexFound = PROG_FindBlockIndexInTable(uwBlockIdent, pubBlockId);

            if (PROG_E_OK == eIndexFound)
            {
#if(PROG_PRELIM_ERASING_ENABLE == STD_ON)
                if(uwBlockIdent != PROG_MAX_BLOCK_ID)
                {
#endif /* (PROG_PRELIM_ERASING_ENABLE == STD_ON) */
#if (PROG_PROGRAMMING_CNTR_ENABLE != STD_ON)
                eProgStatus = PROG_E_OK;
#endif /* (PROG_PROGRAMMING_CNTR_ENABLE != STD_ON) */
                /* Check address */
                (void)PROG_GetSegmentByBlockId(*pubBlockId, &pstSegment->ubSegmentId, &pstSegment->ubSegmentNbr);

#if ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_60) && \
    (PROG_BLOCKID_IN_FINGERPRINT == STD_OFF))
                /* Check if the fingerprint for the current partition type was written*/
                if (((((u32)stConfigSegment[pstSegment->ubSegmentId].ePartitionType & (~PROG_BLU_PARTITION_MASK)) == PROG_APPLICATION_PARTITION) &&
                    (m_stWfSuccess.ubAppFingerprintWriten == PROG_TRUE))                                     ||
                    ((((u32)stConfigSegment[pstSegment->ubSegmentId].ePartitionType & (~PROG_BLU_PARTITION_MASK)) == PROG_CALIBRATION_PARTITION) &&
                    (m_stWfSuccess.ubCalFingerprintWriten == PROG_TRUE))                                     ||
                    ((((u32)stConfigSegment[pstSegment->ubSegmentId].ePartitionType &   PROG_BLU_PARTITION_MASK ) == PROG_BLU_PARTITION_MASK)    &&
                    (m_stWfSuccess.ubBluFingerprintWriten == PROG_TRUE)))
#endif /* ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_60)) */
                {
#if (PROG_ERASE_CHECK_TYPE == PROG_BLOCK_ERASE_CHECK)
                    /* Check if logical block is already erased */
                    eEraseStatus = PROG_CustomGetEraseStatus(*pubBlockId);

                    if(PROG_E_ERASED == eEraseStatus)
                    {
#if (PROG_SEG_LIST_CKS == STD_ON)
                        /*Init Segment list for CRC calculation*/
                        m_stSegList.ubSegNbr = 0;
#endif /*(PROG_SEG_LIST_CKS == STD_ON)*/
                        pstSegment->ubLogicalBlockId = *pubBlockId;
                        eProgStatus = PROG_E_BYPASS;
                    }
                    else
#endif /*(PROG_ERASE_CHECK_TYPE == PROG_BLOCK_ERASE_CHECK)*/
                    {
#if (PROG_PROGRAMMING_CNTR_ENABLE == STD_ON)
                        eProgStatus = PROG_CheckProgrammingCounter(*pubBlockId);

                        if(PROG_E_OK == eProgStatus)
#endif /* (PROG_PROGRAMMING_CNTR_ENABLE == STD_ON) */
                        {
                            /* Construct Segment Structure (Address)*/
                            pstSegment->ulStartAddress = stConfigSegment[pstSegment->ubSegmentId].ulEraseStartAddress;
                            pstSegment->ubLogicalBlockId = *pubBlockId;

                            /* Construct Segment Structure (Size)*/
                            pstSegment->ulSize = (stConfigSegment[pstSegment->ubSegmentId].ulEraseEndAddress -
                                                stConfigSegment[pstSegment->ubSegmentId].ulEraseStartAddress) + 1U;

                            /* Prepare positive return status */
                            *eUdsStatus = UDS_ACK;
                        }
#if (PROG_PROGRAMMING_CNTR_ENABLE == STD_ON)
                        else /* (PROG_E_OK == eProgStatus) */
                        {
#if (PROG_IMPL_VARIANT == PROG_IMPL_50)
                            /* Maximum programming attempts has been reached, programming is rejected */
                            /* Send Negative response */
                            *eUdsStatus = UDS_NRC_22;
#else
                            /* Set negative status */
                            *eUdsStatus = UDS_NRC_72;
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_50) */
                        }
#endif /* (PROG_PROGRAMMING_CNTR_ENABLE == STD_ON) */
                    }
                }
#if ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_60) && \
    (PROG_BLOCKID_IN_FINGERPRINT == STD_OFF))
                else
                {
                    /* Set negative status */
                    *eUdsStatus = UDS_NRC_24;
                    eProgStatus = PROG_E_NOT_OK;
                }
#endif /* ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_60) && \
            (PROG_BLOCKID_IN_FINGERPRINT == STD_OFF))*/
#if (PROG_PRELIM_ERASING_ENABLE == STD_ON)
                }
                else
                {
                    eProgStatus = PROG_PrelimErasing(pstSegment);

                    if(PROG_E_OK == eProgStatus)
                    {
                        *eUdsStatus = UDS_ACK;
                    }
                    else
                    {
                        *eUdsStatus = UDS_NRC_72;
                    }
                }
#endif /* (PROG_PRELIM_ERASING_ENABLE == STD_ON) */
            }
            else /*(PROG_E_NOT_OK == eIndexFound)*/
            {
                /* Set negative status */
                *eUdsStatus = UDS_NRC_31;
            }
#if PROG_BLOCKID_IN_FINGERPRINT == STD_OFF
        }
        else
        {
            /* Set negative status */
            *eUdsStatus=UDS_NRC_13;
        }
    }
    else
    {
        /* Set negative status */
        *eUdsStatus = UDS_NRC_31;
    }
#endif /*PROG_BLOCKID_IN_FINGERPRINT == STD_ON*/
#else /*#if PROG_ERASE_ALL == STD_OFF */
    OSC_PARAM_UNUSED(pubUdsData);
    /* Erase all shall be done, use Block 0 that contains all segments*/
    /* Check address */
    *pubBlockId = 0U;
    (void)PROG_GetSegmentByBlockId(0U, &pstSegment->ubSegmentId, &pstSegment->ubSegmentNbr);
    /* Construct Segment Structure (Address)*/
    pstSegment->ulStartAddress = stConfigSegment[pstSegment->ubSegmentId].ulEraseStartAddress;
    pstSegment->ubLogicalBlockId = 0U;

    /* Construct Segment Structure (Size)*/
    pstSegment->ulSize = (stConfigSegment[pstSegment->ubSegmentId].ulEraseEndAddress -
                        stConfigSegment[pstSegment->ubSegmentId].ulEraseStartAddress) + 1U;

    /* Prepare positive return status */
    eProgStatus = PROG_E_OK;
    *eUdsStatus = UDS_ACK;

#endif
#endif /* PROG_ERASE_TYPE == PROG_ERASE_BY_BLOCK_ID */


#if PROG_ERASE_TYPE == PROG_ERASE_BY_DYNAMIC_PARTITION_ID
    /* Check if enough data are received */
    if(1U <= m_stDiagMessageInfo.ulLength)
    {
#if(PROG_HSM_UPDATE_ENABLE == STD_ON)
        if(pubUdsData[0U] == PROG_HSM_PARTITION_ID)
        {
            /*Prepare the positive return status*/
            *eUdsStatus = UDS_ACK;
            eProgStatus = PROG_E_OK;
        }
        else if(pubUdsData[0U] == PROG_SW_APP_ID)
#else
        if(pubUdsData[0U] == PROG_SW_APP_ID)
#endif
        {
#if (PROG_WRITE_FINGERPRINT_ENABLE == STD_ON)
/* CHECK: NOPARSE */
/* NOCOV-FEATURE_NOT_USED */
            /* Check if the fingerprint for the Application Partition was written*/
            if ((stConfigSegment[pstSegment->ubSegmentId].ePartitionType == PROG_APPLICATION_PARTITION) &&
                (m_stWfSuccess.ubAppFingerprintWriten == PROG_TRUE))
/* CHECK: PARSE */
#endif /* (PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) */
            {
                /* Application partition shall be erased */
                pstSegment->uwModuleId = PROG_SW_APP_ID;
                pstSegment->ubSegmentId = PROG_APP_SEGMENT_ID;

                /* Get number of region for this partition */
                pstSegment->ubSegmentNbr = 1U;

                /* Construct Segment Structure (Address)*/
                pstSegment->ulStartAddress = stConfigSegment[PROG_APP_SEGMENT_ID].ulEraseStartAddress;

                /* Construct Segment Structure (Size)*/
                pstSegment->ulSize = (stConfigSegment[PROG_APP_SEGMENT_ID].ulEraseEndAddress
                        - stConfigSegment[PROG_APP_SEGMENT_ID].ulEraseStartAddress) + 1U;

                /* Prepare positive return status */
                eProgStatus = PROG_E_OK;
            }
#if (PROG_WRITE_FINGERPRINT_ENABLE == STD_ON)
            else
            {
                /* Set negative status */
                *eUdsStatus = UDS_NRC_24;
            }
#endif /* (PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) */
        }
        else
        {
            /* Check if Application is valid, set segment to Application segment */
            pstSegment->ubSegmentId = PROG_APP_SEGMENT_ID;
            eProgStatus = PROG_CheckPSIValue(PROG_SW_APP_ID,PROG_PSI_PROGRAMMED);

            if(eProgStatus == PROG_E_OK)
            {
                /* Get address where is set the number of calibration partitions */
                if((u16)((u16)pubUdsData[0U] & 0x00FFU) <= (PROG_GET_CALIB_PARTITION_NB + 1U))
                {
#if (PROG_WRITE_FINGERPRINT_ENABLE == STD_ON)
/* CHECK: NOPARSE */
/* NOCOV-FEATURE_NOT_USED */
                    /* Check if the fingerprint for the calibration partition was written*/
                    if ((stConfigSegment[pstSegment->ubSegmentId].ePartitionType == PROG_CALIBRATION_PARTITION) &&
                        (m_stWfSuccess.ubCalFingerprintWriten == PROG_TRUE))
/* CHECK: PARSE */
#endif /* (PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) */
                    {
                        /* Calibration partition shall be erased */
                        pstSegment->uwModuleId = (u16)pubUdsData[0];

                        /* Get number of region for this partition */
                        pstSegment->ubSegmentNbr = (u8)PROG_GET_CALIB_SW_REGION_NBR((u8)pstSegment->uwModuleId);
                        pstSegment->pubRegionPtr = (u8*)PROG_GET_CALIB_SW_FIRST_REGION_ADDR_START_ADDR((u8)pstSegment->uwModuleId);

                        /* Construct Segment Structure (Address)*/
                        pstSegment->ulStartAddress = PROG_GET_CALIB_SW_FIRST_REGION_ADDR_START((u8)pstSegment->uwModuleId);

                        /* Construct Segment Structure (Size)*/
                        pstSegment->ulSize = PROG_GET_CALIB_SW_FIRST_REGION_SIZE_START((u8)pstSegment->uwModuleId);

                        /* Get associated segment in configuration */
                        eProgStatus = PROG_GetSegmentByAddress
                                (pstSegment->ulStartAddress, pstSegment->ulSize,PROG_MEM_OPERATION_TYPE_ERASE, &pstSegment->ubSegmentId);

                        if ( eProgStatus != PROG_E_OK)
                        {
#if (PROG_PEC_ENABLE == STD_ON)
                            /* Set error in PEC */
                            m_uwPEC = PROG_ERR_PARTITION_ID;
#endif
                            *eUdsStatus = UDS_NRC_72;
                        }
                    }
#if (PROG_WRITE_FINGERPRINT_ENABLE == STD_ON)
                    else
                    {
                        /* Set negative status */
                        *eUdsStatus = UDS_NRC_24;
                        eProgStatus = PROG_E_NOT_OK;
                    }
#endif /* (PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) */
                }
                else
                {
#if (PROG_PEC_ENABLE == STD_ON)
                    /* Set error in PEC */
                    m_uwPEC = PROG_ERR_PARTITION_ID;
#endif
                    *eUdsStatus = UDS_NRC_72;
                    eProgStatus = PROG_E_NOT_OK;
                }
            }
            else
            {
#if (PROG_PEC_ENABLE == STD_ON)
                /* Set error in PEC */
                m_uwPEC = PROG_ERR_SW_NOT_PRESENT;
#endif
                *eUdsStatus = UDS_NRC_72;
                eProgStatus = PROG_E_NOT_OK;
            }
        }
    }
    else
    {
        *eUdsStatus = UDS_NRC_13;
    }
#endif /* PROG_ERASE_TYPE == PROG_ERASE_BY_DYNAMIC_PARTITION_ID */

    return eProgStatus;
}
/*----------------------{end PROG_ExtractEraseParameters}------------------------*/
#endif /* if PROG_ERASE_MEMORY_ENABLE == STD_ON */

/*----------------------------{PROG_GetNetworkStatus}-----------------------------*/
#if (PROG_NETWORK_MANAGEMENT_ENABLE == STD_ON)
u16 PROG_GetNetworkStatus(void)
{
    u16 uwNetworkStatus;

    DBG_PROG_GETNETWORKSTATUS_ENTRY();
    /*return networkstatus stored through reception of Master frame*/
    uwNetworkStatus = m_uwNetworkStatus;

    DBG_PROG_GETNETWORKSTATUS_EXIT(uwNetworkStatus);
    return uwNetworkStatus;
}
#endif
/*----------------------------{end PROG_GetNetworkStatus}-------------------------*/


/*----------------------------{PROG_SendrespAfterReset}--------------------*/
#if ((PROG_RESET_CAUSE_ENABLE == STD_ON) || ((PROG_IMPL_VARIANT == PROG_IMPL_3) && (PROG_ACTIVE_SBL_RESPONSE_ENABLE == STD_OFF)) || ((PROG_IMPL_VARIANT == PROG_IMPL_90) && (PROG_ACTIVE_SBL_RESPONSE_ENABLE == STD_OFF)))
void PROG_SendRespAfterReset(tProgResCause ubResetCause, tProgBoolean ubSendResp)
{
    DBG_PROG_SENDRESPAFTERRESET_ENTRY(ubResetCause,ubSendResp);
#if ((PROG_IMPL_VARIANT == PROG_IMPL_3) && (PROG_ACTIVE_SBL_RESPONSE_ENABLE == STD_OFF)) || ((PROG_IMPL_VARIANT == PROG_IMPL_90) && (PROG_ACTIVE_SBL_RESPONSE_ENABLE == STD_OFF))
    OSC_PARAM_UNUSED(ubSendResp);
    switch(ubResetCause)
    {
        case PROG_RESET_CAUSE_SBLACTIVEFAIL:
            {
                /*Simulate OpenProgramming Session*/
                PROG_SimulateOpenProgSession();
                break;
            }
        default:
            {
                /*do nothing*/
                break;
            }
    }
#else
    if(PROG_TRUE == ubSendResp)
    {
        /*Response needed, check the reset cause*/
        switch(ubResetCause)
        {
            case PROG_RESET_CAUSE_ER:
                {
                    /*Send Positive Response to ER*/
                    PROG_SimulateER();
                    break;
                }
            case PROG_RESET_CAUSE_DSC01:
                {
                    /*Send Positive Response to DSC01*/
                    PROG_SimulateCloseProgSession();
                    break;
                }
            case PROG_RESET_CAUSE_DSC02:
                {
                    /*Send Positive Response to DSC02*/
                    PROG_SimulateOpenProgSession();
                    break;
                }
            case PROG_RESET_CAUSE_S3_TIMEOUT:
            case PROG_RESET_CAUSE_BLU:
            default:
                {
                    /*do nothing*/
                    break;
                }
        }
    }
    else
    {
        /*Do Nothing*/
    }
#endif
    DBG_PROG_SENDRESPAFTERRESET_EXIT();
}
#endif /* (PROG_RESET_CAUSE_ENABLE == STD_ON) */
/*----------------------------{end PROG_SendrespAfterReset}----------------*/


/*----------------------------{PROG_Entry_CheckMemory}-----------------------------*/
void PROG_Entry_CheckMemory(void)
{
#if (PROG_CHECK_MEMORY_ENABLE == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_80)

#if (PROG_CRC_CALCULATION == PROG_TD_CRC32)
    u32 ulExpectedCks;
#elif (PROG_CRC_CALCULATION == PROG_TD_CRC16)
    u16 uwExpectedCks;
#endif
#if (((PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_SIGNATURE_CALCULATION_OVER_HASH == STD_ON)) \
  || ((PROG_HASH_CALCULATION == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_60)))
    u16 uwIdx;
#endif
#if ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_AUTHENTICATED_REPROG))
    u32 ulStartAddress;
#endif

    DBG_PROG_ENTRY_CHECKMEMORY_ENTRY();

#if (((PROG_IMPL_VARIANT == PROG_IMPL_40) || (PROG_IMPL_VARIANT == PROG_IMPL_50) || (PROG_IMPL_VARIANT == PROG_IMPL_60)) && (PROG_CHECK_MEMORY_ENABLE == STD_ON))
    /* Initialize for the next time we receive Check Memory request */
    m_ubSameRequest = TRUE;
#endif
#if (PROG_BLU_ACTIVE == STD_ON)
#if (PROG_CHECKMEMORY_TYPE == PROG_CHECKMEMORY_BY_BLOCK)
    /* Get the presence of BLUpdater pattern in the current block */
    m_ubBLUPattern = PROG_CustomIsBLUPatternPresent(m_stCurrentSegment.ubLogicalBlockId, m_stCurrentSegment.ubSegmentId);
#else
    /* Get the presence of BLUpdater pattern in the current segment */
    m_ubBLUPattern = PROG_CustomIsBLUPatternPresent(0U, m_stCurrentSegment.ubSegmentId);
#endif /*(PROG_CHECKMEMORY_TYPE == PROG_CHECKMEMORY_BY_BLOCK)*/
#endif /*(PROG_BLU_ACTIVE == STD_ON)*/

#if ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_AUTHENTICATED_REPROG))
#if (PROG_OTA_DUALBANK_USED == STD_ON)
    /* The read is done using the logical address */
    ulStartAddress = PROG_CustomCalcInactiveBankReadAddr(stConfigSegment[stCfgBlock[m_ubFpBlockId].ubFirstSegmentId].ulStartAddress);
#else
    ulStartAddress = stConfigSegment[stCfgBlock[m_ubFpBlockId].ubFirstSegmentId].ulStartAddress;
#endif /*(PROG_OTA_DUALBANK_USED == STD_ON)*/

    /* Extract the expected Hash from the Header (The block header is always written into the first segment from each logical block). */
    (void)PROG_MemDataAccess( m_astCfgMemory[stConfigSegment[stCfgBlock[m_ubFpBlockId].ubFirstSegmentId].ubMemoryIdx].eMemoryType,
    PROG_MEM_OPERATION_TYPE_READ, ulStartAddress + PROG_FILE_DIGEST_OFFSET,
    PROG_DIGEST_LENGTH, m_aubMessageDigest);
    /* Extract and Check the HeaderSize, the SigningInfos and the HeaderSignature */
    PROG_StartBlockHeaderCheck();
#endif /*((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_AUTHENTICATED_REPROG))*/

/* possible cases:
- Only CRC computation is performed
- Only Signature with Hash computation is performed
- Only signature or Signature and CRC computation is performed
- Signature with Hash and CRC computation is performed
- Only Hash verification is performed
*/

/* Only CRC computation is performed */
#if (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_CRC)
    /*Extract expected CRC*/
#if (PROG_CRC_CALCULATION == PROG_TD_CRC32)
    /* Extract expected CRC */
    ulExpectedCks = PROG_RetrieveRequestData32(&m_stDiagMessageInfo.pubData[PROG_RC_OPTION_RECORD_CRC_VAL_BASE_INDEX]);

    /* Save the content of the request of the first received Check Memory request */
    if (FALSE == m_ubCheckMemoryFinishState)
    {
        m_ulExpectedCks = ulExpectedCks;
    }
    /* Compare the current content with the first received content */
    else
    {
        if (m_ulExpectedCks != ulExpectedCks)
        {
            m_ubSameRequest = FALSE;
        }
        else
        {
            /* Do nothing */
        }
    }
#endif /*(PROG_CRC_CALCULATION == PROG_TD_CRC32)*/

#if (PROG_CRC_CALCULATION == PROG_TD_CRC16)
#if ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_STANDARD_REPROG))
    /*Extract expected CRC from Block memory*/
    (void)PROG_MemDataAccess( m_astCfgMemory[stConfigSegment[stCfgBlock[m_ubFpBlockId].ubFirstSegmentId].ubMemoryIdx].eMemoryType,
    PROG_MEM_OPERATION_TYPE_READ, stCfgBlock[m_ubFpBlockId].ulCrcAddress,
    PROG_CRC_BYTE_LENGTH, m_aubExpectedCrc);
    uwExpectedCks = PROG_RetrieveRequestData16(m_aubExpectedCrc);
#else
    uwExpectedCks = PROG_RetrieveRequestData16(&m_stDiagMessageInfo.pubData[PROG_RC_OPTION_RECORD_CRC_VAL_BASE_INDEX]);
#endif

    /* Save the content of the request of the first received Check Memory request */
    if (FALSE == m_ubCheckMemoryFinishState)
    {
        m_uwExpectedCks = uwExpectedCks;
    }
    /* Compare the current content with the first received content */
    else
    {
        if (m_uwExpectedCks != uwExpectedCks)
        {
            m_ubSameRequest = FALSE;
        }
        else
        {
            /* Do nothing */
        }
    }
#endif /*(PROG_CRC_CALCULATION == PROG_TD_CRC16)*/

#if ((PROG_GET_EXPECTED_CRC_ENABLED == STD_ON) && (PROG_CRC_CALCULATION == PROG_TD_CRC32))
    if (0U == ulExpectedCks)
    {
        /* Expected CRC not in the request, use callback to get it */
        PROG_CustomGetExpectedCrc(m_stCurrentSegment.ubLogicalBlockId, &ulExpectedCks);

        /* Save the content of the request of the first received Check Memory request */
        if (FALSE == m_ubCheckMemoryFinishState)
        {
            m_ulExpectedCks = ulExpectedCks;
        }
        /* Compare the current content with the first received content */
        else
        {
            if (m_ulExpectedCks != ulExpectedCks)
            {
                m_ubSameRequest = FALSE;
            }
            else
            {
                /* Do nothing */
            }
        }
    }
    else
    {
        /* Do nothing */
    }
#endif /*((PROG_GET_EXPECTED_CRC_ENABLED == STD_ON) && (PROG_CRC_CALCULATION == PROG_TD_CRC32))*/
    if (FALSE == m_ubCheckMemoryFinishState)
    {
        /* Simulate crypto finish to go to CRC computation check */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH);
    }
    else
    {
        /* Do nothing */
    }
/* endif((PROG_VERIFICATION_ON_THE_FLY == STD_OFF) && (PROG_CRC_CALCULATION != PROG_NO_CRC) && (PROG_SIGNATURE_CALCULATION == STD_OFF)) */

/* Only Signature with Hash computation is performed */
#elif (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_SIGNATURE_WITH_HASH)
    /* Call crypto library to start the signature verification */
#if (PROG_CRY_PRESENT == STD_ON)
#if (((PROG_IMPL_VARIANT == PROG_IMPL_40) || (PROG_IMPL_VARIANT == PROG_IMPL_50) || (PROG_IMPL_VARIANT == PROG_IMPL_60)) && (PROG_CHECK_MEMORY_ENABLE == STD_ON))
    if (FALSE == m_ubCheckMemoryFinishState)
    {
        (void)PROG_ComputeHashStart(PROG_CSM_HASH_FOR_SIGNATURE_ID,NULL_PTR,0U,NULL_PTR);
    }
#endif
#endif /*(PROG_CRY_PRESENT == STD_ON)*/

#if (((PROG_IMPL_VARIANT == PROG_IMPL_40) || (PROG_IMPL_VARIANT == PROG_IMPL_50) || (PROG_IMPL_VARIANT == PROG_IMPL_60)) && (PROG_CHECK_MEMORY_ENABLE == STD_ON))
    /* Extract expected signature */
    for (uwIdx = 0U; (uwIdx < PROG_SIGNATURE_LENGTH) && (TRUE == m_ubSameRequest); uwIdx++)
    {
        /* Save the content of the request of the first received Check Memory request */
        if (FALSE == m_ubCheckMemoryFinishState)
        {
            m_aubExpectedSignature[uwIdx] = m_stDiagMessageInfo.pubData[PROG_RC_OPTION_RECORD_SIGVAL_BASE_INDEX + uwIdx];
        }
        /* Compare the current content with the first received content */
        else
        {
            if (m_aubExpectedSignature[uwIdx] != m_stDiagMessageInfo.pubData[PROG_RC_OPTION_RECORD_SIGVAL_BASE_INDEX + uwIdx])
            {
                m_ubSameRequest = FALSE;
            }
            else
            {
                /* Do nothing */
            }
        }
    }
#endif
#if (PROG_SEG_LIST_CKS == STD_ON)
    if (FALSE == m_ubCheckMemoryFinishState)
    {
        /* Init CRC calculation for first segment */
        PROG_CRCSetParam(m_stSegList.astSeg[0].ulStartAddress, m_stSegList.astSeg[0].ulSize, PROG_VERIFY_HASH, PROG_FALSE);
        m_stCurrentSegment.ubSegmentId = m_stSegList.astSeg[0].ubSegmentId;
        /* Init the segment list CRC index */
        m_stSegList.ubSegListCrcIndex = 0;
    }
#endif /*(PROG_SEG_LIST_CKS == STD_ON)*/
/* endif ((PROG_VERIFICATION_ON_THE_FLY == STD_OFF) && (PROG_CRC_CALCULATION == PROG_NO_CRC) && (PROG_SIGNATURE_CALCULATION == STD_ON) && (PROG_SIGNATURE_CALCULATION_OVER_HASH == STD_ON)) */


/* Only signature or Signature and CRC computation is performed */
#elif ((PROG_VERIFICATION_METHOD == PROG_VERIFICATION_SIGNATURE) || (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_SIGNATURE_AND_CRC))
#if (PROG_CRC_CALCULATION == PROG_TD_CRC32)
    /* Extract expected CRC */
    ulExpectedCks = PROG_RetrieveRequestData32(&m_stDiagMessageInfo.pubData[PROG_RC_OPTION_RECORD_CRC_VAL_BASE_INDEX]);

    /* Save the content of the request of the first received Check Memory request */
    if (FALSE == m_ubCheckMemoryFinishState)
    {
        m_ulExpectedCks = ulExpectedCks;
    }
    /* Compare the current content with the first received content */
    else
    {
        if (m_ulExpectedCks != ulExpectedCks)
        {
            m_ubSameRequest = FALSE;
        }
        else
        {
            /* Do nothing */
        }
    }
#endif /*(PROG_CRC_CALCULATION == PROG_TD_CRC32)*/

#if (PROG_CRY_PRESENT == STD_ON)
    if (FALSE == m_ubCheckMemoryFinishState)
    {
        /* Finalize signature computation */
        PROG_VerifySignatureFinish(&m_stDiagMessageInfo.pubData[PROG_RC_OPTION_RECORD_SIGVAL_BASE_INDEX]);
    }
#endif /*(PROG_CRY_PRESENT == STD_ON)*/

#elif (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_IN_DFI)
    if((m_ubVerificationMethod == PROG_VERIFICATION_SIGNATURE) || (m_ubVerificationMethod == PROG_VERIFICATION_SIGNATURE_AND_CRC))
    {
        if(m_ubCRC_Calculation == PROG_TD_CRC32)
        {
            /* Extract expected CRC */
            ulExpectedCks = PROG_RetrieveRequestData32(&m_stDiagMessageInfo.pubData[PROG_RC_OPTION_RECORD_CRC_VAL_BASE_INDEX]);
            
            /* Save the content of the request of the first received Check Memory request */
            if (FALSE == m_ubCheckMemoryFinishState)
            {
                m_ulExpectedCks = ulExpectedCks;
            }
            /* Compare the current content with the first received content */
            else
            {
                if (m_ulExpectedCks != ulExpectedCks)
                {
                    m_ubSameRequest = FALSE;
                }
                else
                {
                    /* Do nothing */
                }
            }
        }
#if (PROG_CRY_PRESENT == STD_ON)
        if (FALSE == m_ubCheckMemoryFinishState)
        {
            /* Finalize signature computation */
            PROG_VerifySignatureFinish(&m_stDiagMessageInfo.pubData[PROG_RC_OPTION_RECORD_SIGVAL_BASE_INDEX]);
        }
#endif /*(PROG_CRY_PRESENT == STD_ON)*/
    }
    /* CRC computation will be done after signature verification has ended */

/* Signature with Hash and CRC computation is performed */
#elif (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_SIGNATURE_WITH_HASH_AND_CRC)
#if (PROG_CRY_PRESENT == STD_ON)
#if (PROG_CRC_CALCULATION == PROG_TD_CRC32)
    /* Extract expected CRC */
    ulExpectedCks = PROG_RetrieveRequestData32(&m_stDiagMessageInfo.pubData[PROG_RC_OPTION_RECORD_CRC_VAL_BASE_INDEX]);

    /* Save the content of the request of the first received Check Memory request */
    if (FALSE == m_ubCheckMemoryFinishState)
    {
        m_ulExpectedCks = ulExpectedCks;
    }
    /* Compare the current content with the first received content */
    else
    {
        if (m_ulExpectedCks != ulExpectedCks)
        {
            m_ubSameRequest = FALSE;
        }
        else
        {
            /* Do nothing */
        }
    }
#endif /*(PROG_CRC_CALCULATION == PROG_TD_CRC32)*/

#if (PROG_CRC_CALCULATION == PROG_TD_CRC16)
/* CHECK: NOPARSE */
/* NOCOV-NCS_UNITARY_TEST*/
    uwExpectedCks = PROG_RetrieveRequestData16(&m_stDiagMessageInfo.pubData[PROG_RC_OPTION_RECORD_CRC_VAL_BASE_INDEX]);

    /* Save the content of the request of the first received Check Memory request */
    if (FALSE == m_ubCheckMemoryFinishState)
    {
        m_uwExpectedCks = uwExpectedCks;
    }
    /* Compare the current content with the first received content */
    else
    {
        if (m_uwExpectedCks != uwExpectedCks)
        {
            m_ubSameRequest = FALSE;
        }
        else
        {
            /* Do nothing */
        }
    }
/* CHECK: PARSE */
#endif /*(PROG_CRC_CALCULATION == PROG_TD_CRC16)*/

    /* Extract expected signature */
    for(uwIdx = 0U; (uwIdx < PROG_SIGNATURE_LENGTH) && (TRUE == m_ubSameRequest); uwIdx++)
    {
        /* Save the content of the request of the first received Check Memory request */
        if (FALSE == m_ubCheckMemoryFinishState)
        {
            m_aubExpectedSignature[uwIdx] = m_stDiagMessageInfo.pubData[PROG_RC_OPTION_RECORD_SIGVAL_BASE_INDEX + uwIdx];
        }
        /* Compare the current content with the first received content */
        else
        {
            if (m_aubExpectedSignature[uwIdx] != m_stDiagMessageInfo.pubData[PROG_RC_OPTION_RECORD_SIGVAL_BASE_INDEX + uwIdx])
            {
                m_ubSameRequest = FALSE;
            }
            else
            {
                /* Do nothing */
            }
        }
    }

    if (FALSE == m_ubCheckMemoryFinishState)
    {
        /* Finalize Hash computation */
        PROG_ComputeHashFinish(&m_aubComputedMessageDigest[0]);
    }

    /* CRC computation will be done after signature verification has ended */
#endif /*(PROG_CRY_PRESENT == STD_ON)*/
/* Only Hash verification is performed */
#elif (PROG_VERIFICATION_METHOD == PROG_VERIFICATION_HASH)
#if (PROG_HASH_CALCULATION == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_60)
    /* Extract expected Hash */
    for(uwIdx = 0U; (uwIdx < PROG_DIGEST_LENGTH) && (TRUE == m_ubSameRequest); uwIdx++)
    {
        /* Save the content of the request of the first received Check Memory request */
        if (FALSE == m_ubCheckMemoryFinishState)
        {
            m_aubMessageDigest[uwIdx] = m_stDiagMessageInfo.pubData[PROG_RC_ROUTINE_STATUS_BASE_INDEX + uwIdx];
        }
        /* Compare the current content with the first received content */
        else
        {
            if (m_aubMessageDigest[uwIdx] != m_stDiagMessageInfo.pubData[PROG_RC_ROUTINE_STATUS_BASE_INDEX + uwIdx])
            {
                m_ubSameRequest = FALSE;
            }
            else
            {
                /* Do nothing */
            }
        }
    }
#endif /*(PROG_HASH_CALCULATION == STD_ON) && (PROG_IMPL_VARIANT == PROG_IMPL_60)*/
#if (PROG_IMPL_VARIANT != PROG_IMPL_31)
    /* Finalize Hash computation */
    PROG_ComputeHashFinish(&m_aubComputedMessageDigest[0]);
#endif /*(PROG_IMPL_VARIANT != PROG_IMPL_31)*/
#endif /*((PROG_VERIFICATION_METHOD == PROG_VERIFICATION_HASH) && (PROG_IMPL_VARIANT != PROG_IMPL_31) && (PROG_IMPL_VARIANT != PROG_IMPL_60))*/

    DBG_PROG_ENTRY_CHECKMEMORY_EXIT();
#endif /*(PROG_CHECK_MEMORY_ENABLE == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_80)*/
}
/*----------------------------{end PROG_Entry_CheckMemory}-------------------------*/


/*----------------------------{PROG_Entry_BLU_Resume}-------------------------*/
void PROG_Entry_BLU_Resume(void)
{
#if (PROG_BLU_ACTIVE == STD_ON)
    /* Restore security level*/
    PROG_SetSecurityLevel(stBLUContextRestore.ubProgSecurityLevel);
#if ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_60))
    m_stWfSuccess.ubAppFingerprintWriten = PROG_TRUE;
    m_stWfSuccess.ubCalFingerprintWriten = PROG_TRUE;
    m_stWfSuccess.ubBluFingerprintWriten = PROG_TRUE;
#endif /* ((PROG_WRITE_FINGERPRINT_ENABLE == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_60)) */

    /* Simulate Check memory request to be able to answer the requested BLU Check memory */
    (void)EB_SimulateRxRequest(stBLUContextRestore.stBLUCheckMemoryRequestInfo.ulLength,
                               stBLUContextRestore.stBLUCheckMemoryRequestInfo.aubData, FALSE);

    BlPduR_RetrieveConnectionInfo();

    m_stDiagMessageInfo.pubTxData = m_aubUdsData;
    /* Set the BLU answer in the current physical buffer */
    m_aubUdsData[0] = stBLUContextRestore.stBLUCheckMemoryRequestInfo.aubData[0];
    m_aubUdsData[1] = stBLUContextRestore.stBLUCheckMemoryRequestInfo.aubData[1];
    m_aubUdsData[2] = stBLUContextRestore.stBLUCheckMemoryRequestInfo.aubData[2];
    m_aubUdsData[3] = stBLUContextRestore.stBLUCheckMemoryRequestInfo.aubData[3];
#if ((PROG_CRC_COMPUTE_COMPARE_ENABLE == STD_ON) || ((PROG_SEG_LIST_CKS == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_10) && (PROG_IMPL_VARIANT != PROG_IMPL_11) && (PROG_IMPL_VARIANT != PROG_IMPL_90) && (PROG_IMPL_VARIANT != PROG_IMPL_91)))
    m_stDiagMessageInfo.ulLength = PROG_CRC_COMP_RESPONSE_SIZE;
    m_stDiagMessageInfo.ubDiagStatus = UDS_ACK;
#if (PROG_IMPL_VARIANT == PROG_IMPL_40)
    /* Send POSITIVE RESPONSE with same data than request*/
    m_aubUdsData[4] = PROG_ROUTINE_FINISHED_OK;
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_40) */
#if (PROG_IMPL_VARIANT == PROG_IMPL_60)
        /* Allow integration to modify response */
        PROG_Custom_CheckMemoryRoutine_Succeed(m_stDiagMessageInfo.pubTxData, &m_stDiagMessageInfo.ulLength);
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_60) */
#endif /* ((PROG_CRC_COMPUTE_COMPARE_ENABLE == STD_ON) || ((PROG_SEG_LIST_CKS == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_10) && (PROG_IMPL_VARIANT != PROG_IMPL_11) && (PROG_IMPL_VARIANT != PROG_IMPL_90) && (PROG_IMPL_VARIANT != PROG_IMPL_91))) */

    /* BLU download is no longer in progress*/
    PROG_CustomSetBLUDownloadInProgress(PROG_FALSE);
    /* Send Event Finished event */
    PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
    /* Answer to the check memory request of the BLU*/
    UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);
#endif /* (PROG_BLU_ACTIVE == STD_ON) */
}
/*----------------------------{end PROG_Entry_BLU_Resume}-------------------------*/


#if (PROG_CHECK_MEMORY_ENABLE == STD_ON)
/*----------------------------{PROG_Entry_CheckMemoryFinish}-------------------------*/
void PROG_Entry_CheckMemoryFinish(void)
{
#if (PROG_IMPL_VARIANT == PROG_IMPL_11)
    tProgStatus eProgStatus;
#endif
    DBG_PROG_ENTRY_CHECKMEMORYFINISH_ENTRY();
#if (((PROG_IMPL_VARIANT == PROG_IMPL_40) || (PROG_IMPL_VARIANT == PROG_IMPL_50) || (PROG_IMPL_VARIANT == PROG_IMPL_60)) && (PROG_CHECK_MEMORY_ENABLE == STD_ON))
    m_ubCheckMemoryFinishState = TRUE;
#elif ((PROG_IMPL_VARIANT == PROG_IMPL_10) || (PROG_IMPL_VARIANT == PROG_IMPL_11))
    m_ubFailedCheckMemoryCount = 0;
    m_ubVerificationTablePresent = 0;


#if (PROG_IMPL_VARIANT == PROG_IMPL_11)
    eProgStatus = PROG_CustomSetDownloadVerificationSuccess(m_stCurrentSegment.ubLogicalBlockId, m_stCurrentSegment.ubSegmentId, PROG_TRUE);
    PROG_Impl10_SoftwarePartFinished();
    if (PROG_E_NOT_OK == eProgStatus)
    {
        m_ubCheckMemoryStatus = PROG_VALIDITY_STORAGE_FAIL;
    }
#else
    m_ubSblVerficationStatus = PROG_E_OK;
#endif
    m_stDiagMessageInfo.pubTxData[PROG_RC_CHK_MEMORY_STATUS_INDEX]                = (u8) (PROG_ROUTINE_FINISHED_OK | PROG_ROUTINE_TYPE_1);
    m_stDiagMessageInfo.pubTxData[PROG_RC_CHK_MEMORY_RESULT_INDEX]                = (u8) m_ubCheckMemoryStatus;
    m_stDiagMessageInfo.ulLength = PROG_CHK_MEMORY_RESPONSE_SIZE;
    m_stDiagMessageInfo.ubDiagStatus = UDS_ACK;
    UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);
#endif
    DBG_PROG_ENTRY_CHECKMEMORYFINISH_EXIT();
}
/*----------------------------{end PROG_Entry_CheckMemoryFinish}-------------------------*/

#if (((PROG_IMPL_VARIANT == PROG_IMPL_40) || (PROG_IMPL_VARIANT == PROG_IMPL_50) || (PROG_IMPL_VARIANT == PROG_IMPL_60)) && (PROG_CHECK_MEMORY_ENABLE == STD_ON))
/*----------------------------{PROG_Exit_CheckMemoryFinish}-------------------------*/
void PROG_Exit_CheckMemoryFinish(void)
{
    DBG_PROG_EXIT_CHECKMEMORYFINISH_ENTRY();

    m_ubCheckMemoryFinishState = FALSE;

    DBG_PROG_EXIT_CHECKMEMORYFINISH_EXIT();
}
#endif
/*----------------------------{end PROG_Exit_CheckMemoryFinish}-------------------------*/
#endif

/*----------------------------{PROG_Exit_CheckMemory}-----------------------------*/
#if (((PROG_IMPL_VARIANT == PROG_IMPL_40) || (PROG_IMPL_VARIANT == PROG_IMPL_50) || (PROG_IMPL_VARIANT == PROG_IMPL_60) || (PROG_IMPL_VARIANT == PROG_IMPL_10) || (PROG_IMPL_VARIANT == PROG_IMPL_11)) && (PROG_CHECK_MEMORY_ENABLE == STD_ON))
void PROG_Exit_CheckMemory(void)
{
#if ((PROG_IMPL_VARIANT == PROG_IMPL_10) || (PROG_IMPL_VARIANT == PROG_IMPL_11))
    if (m_ubCheckMemoryStatus == PROG_VERIFICATION_PASSED)
    {
        /* Update the error status only if there was no error previously */
        m_ubCheckMemoryStatus = PROG_WRONG_SIGNATURE;
    }
#elif ((PROG_SIGNATURE_CALCULATION == STD_ON) || (PROG_HASH_CALCULATION == STD_ON))
    tProgStatus eProgStatus;
    u8 ubIdx;

    DBG_PROG_EXIT_CHECKMEMORY_ENTRY();

    /* Check is signature check succeed */

    eProgStatus = PROG_GetCryptoStatus();
    if (PROG_E_NOT_OK == eProgStatus)
    {
#if (PROG_IMPL_VARIANT == PROG_IMPL_60)
#if PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON
        if(stConfigSegment[m_stCurrentSegment.ubSegmentId].ePartitionType == PROG_FLASH_ROUTINES_PARTITION)
        {
            PROG_DrvDown_EraseFlashRoutines();
        }
#endif /* PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON */
        m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_72;
        PROG_Custom_CheckMemoryRoutine_Failed(m_stDiagMessageInfo.pubTxData, &m_stDiagMessageInfo.ulLength, &m_stDiagMessageInfo.ubDiagStatus);
#elif (PROG_IMPL_VARIANT == PROG_IMPL_50)
        m_stDiagMessageInfo.pubTxData[PROG_RC_ROUTINE_INFO_BASE_INDEX]                = PROG_ROUTINE_FINISHED_OK;
        m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_VERIF_RESULTS_BASE_INDEX] =
                (u8) (PROG_RC_STATUS_RECORD_VERIF_RESULTS_SIG_FAILED);
        m_stDiagMessageInfo.ulLength                                                  = PROG_CRC_COMP_RESPONSE_SIZE;
        m_stDiagMessageInfo.ubDiagStatus                                              = UDS_ACK;
#else
#if PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON
        if(stConfigSegment[m_stCurrentSegment.ubSegmentId].ePartitionType == PROG_FLASH_ROUTINES_PARTITION)
        {
            PROG_DrvDown_SetFlashRoutinesCorruption(PROG_TRUE);
            PROG_DrvDown_EraseFlashRoutines();
        }
#endif /* PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE == STD_ON */
        m_stDiagMessageInfo.pubTxData[PROG_RC_ROUTINE_INFO_BASE_INDEX]                = PROG_ROUTINE_FINISHED_NOK;
        m_stDiagMessageInfo.ulLength                                                  = PROG_CRC_COMP_RESPONSE_SIZE;
        m_stDiagMessageInfo.ubDiagStatus                                              = UDS_ACK;
#endif


#if (PROG_SET_CRC_COMPARE_RESULT_ENABLE == STD_ON)
#if (PROG_PARTIAL_VERIFY_CRC == STD_ON)
        if (m_ubActivePartialVerifyCrc == FALSE)
#endif
        {
#if (PROG_IMPL_VARIANT != PROG_IMPL_40)
#if (PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR)
            (void) PROG_CustomSetDownloadVerificationSuccess(0U, m_stCurrentSegment.ubSegmentId, PROG_FALSE);
#else
            /* Send CRC Compare Result: Failed*/
            (void) PROG_CustomSetDownloadVerificationSuccess(m_stCurrentSegment.ubLogicalBlockId, \
                                                                    m_stCurrentSegment.ubLogicalSegmentId, PROG_FALSE);
#endif /* PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR */
#endif /* (PROG_IMPL_VARIANT != PROG_IMPL_40) */
#if (PROG_IMPL_VARIANT == PROG_IMPL_40)
#if (PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR)
            eProgStatus = PROG_CustomSetDownloadVerificationSuccess(0U, m_stCurrentSegment.ubSegmentId, PROG_FALSE);
#else
            /* Send CRC Compare Result: Failed*/
            eProgStatus = PROG_CustomSetDownloadVerificationSuccess(m_stCurrentSegment.ubLogicalBlockId, \
                                                                    m_stCurrentSegment.ubLogicalSegmentId, PROG_FALSE);
#endif /* PROG_ERASE_TYPE == PROG_ERASE_BY_ADDR */
#endif /* (PROG_IMPL_VARIANT == PROG_IMPL_40) */
        }
#endif /*(PROG_SET_CRC_COMPARE_RESULT_ENABLE == STD_ON)*/

        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);

#if (((PROG_IMPL_VARIANT == PROG_IMPL_40) || (PROG_IMPL_VARIANT == PROG_IMPL_50) || (PROG_IMPL_VARIANT == PROG_IMPL_60)) && (PROG_CHECK_MEMORY_ENABLE == STD_ON))
        /* Save the response sent to first Check Memory request */
        m_stFirstCheckMemoryAnswerInfo.ulLength = PROG_CRC_COMP_RESPONSE_SIZE;
        m_stFirstCheckMemoryAnswerInfo.ubDiagStatus = m_stDiagMessageInfo.ubDiagStatus;
        for (ubIdx = 4U; ubIdx < PROG_CRC_COMP_RESPONSE_SIZE; ubIdx++)
        {
            m_stFirstCheckMemoryAnswerInfo.aubData[ubIdx] = m_stDiagMessageInfo.pubTxData[ubIdx];
        }
#endif
    }

    DBG_PROG_EXIT_CHECKMEMORY_EXIT();
#endif /* (PROG_SIGNATURE_CALCULATION == STD_ON) */
}
#endif
/*----------------------------{end PROG_Exit_CheckMemory}-------------------------*/

/*--------------------------{PROG_Entry_SignatureCheck}---------------------------*/
#if (PROG_IMPL_VARIANT == PROG_IMPL_50)
void PROG_Entry_SignatureCheck(void)
{

    DBG_PROG_ENTRY_SIGNATURECHECK_ENTRY();

    /* Start Signature computation based on previously computed hash */
    /* Call crypto library to start the signature verification */
    (void)PROG_VerifySignature
    (
        &m_stProgAsymPublicKey,
        &m_aubComputedMessageDigest[0],
        PROG_DIGEST_LENGTH,
        &m_aubExpectedSignature[0]
    );


    DBG_PROG_ENTRY_SIGNATURECHECK_EXIT();
}
#endif
/*--------------------------{end PROG_Entry_SignatureCheck}-----------------------*/

/*----------------------------{entry PROG_Entry_CheckMemoryCompute}-------------------------*/
#if (((PROG_IMPL_VARIANT == PROG_IMPL_40) || (PROG_IMPL_VARIANT == PROG_IMPL_50) || (PROG_IMPL_VARIANT == PROG_IMPL_60))  && (PROG_CHECK_MEMORY_ENABLE == STD_ON))
void PROG_Entry_CheckMemoryCompute(void)
{
    DBG_PROG_ENTRY_CHECKMEMORYCOMPUTE_ENTRY();


/* 2 possible cases:
- Signature computation is finish or only CRC has to be done => start CRC computation
- Signature computation has been started
*/

/* Signature computation is finish or only CRC has to be done => start CRC computation */
#if (PROG_CRC_CALCULATION != PROG_NO_CRC)

#if (PROG_SEG_LIST_CKS == STD_ON)
    /*Init CRC calculation for first segment*/
    PROG_CRCSetParam(m_stSegList.astSeg[0].ulStartAddress, m_stSegList.astSeg[0].ulSize, PROG_VERIFY_CRC, PROG_FALSE);
    m_stCurrentSegment.ubSegmentId=m_stSegList.astSeg[0].ubSegmentId;
    /*Init the segment list CRC index*/
    m_stSegList.ubSegListCrcIndex = 0;
#endif /*(PROG_CRC_CALCULATION == PROG_SEG_LIST_CRC32)*/

/* Signature computation has been performed */
#else
    /* Send response */
    (void)PROG_CRC_Compare();

#endif


    DBG_PROG_ENTRY_CHECKMEMORYCOMPUTE_EXIT();
}
#endif
/*----------------------------{end PROG_Entry_CheckMemoryCompute}-------------------------*/



/*---------------------------{PROG_CheckSegmentListCrc}-----------------------------*/
void PROG_CheckSegmentListCrc(void)
{

    DBG_PROG_CHECKSEGMENTLISTCRC_ENTRY();
#if((PROG_SEG_LIST_CKS == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_10) && (PROG_IMPL_VARIANT != PROG_IMPL_11) && (PROG_IMPL_VARIANT != PROG_IMPL_90) && (PROG_IMPL_VARIANT != PROG_IMPL_91))
    /*If not the last segment*/
    if(m_stSegList.ubSegListCrcIndex < (m_stSegList.ubSegNbr-1U))
    {
        m_stSegList.ubSegListCrcIndex++;
        PROG_CRCSetParam(m_stSegList.astSeg[m_stSegList.ubSegListCrcIndex].ulStartAddress,
                        m_stSegList.astSeg[m_stSegList.ubSegListCrcIndex].ulSize,
                        m_stDataProgVerification.ubAlgo,
                        PROG_TRUE);

        m_stCurrentSegment.ubSegmentId = m_stSegList.astSeg[m_stSegList.ubSegListCrcIndex].ubSegmentId;
    }
    else
    {
#if((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_STANDARD_REPROG))

      /* Send Event Finished event */
      PROG_ComputeHashFinish(&m_aubComputedMessageDigest[0]);

#else
        /* Computation is finished */
        switch (m_stDataProgVerification.ubAlgo)
        {
#if PROG_HASH_CALCULATION == STD_ON
            case PROG_VERIFY_HASH:
                PROG_ComputeHashFinish(&m_aubComputedMessageDigest[0]);
                break;
#endif
#if PROG_SIGNATURE_CALCULATION == STD_ON
            case PROG_VERIFY_SIGNATURE:
                /* Finalize signature computation */
                PROG_VerifySignatureFinish(&m_aubExpectedSignature[0]);
                break;
#endif
#if PROG_CRC_CALCULATION != PROG_NO_CRC
            case PROG_VERIFY_CRC:

#if (PROG_CRC_CALCULATION == PROG_TD_CRC32)
        /* Store calculated CRC */
        PROG_CustomWriteCRC(m_stDataProgVerification.ulVal);
#else
        /* Store calculated CRC */
        PROG_CustomWriteCRC((u32)m_stDataProgVerification.uwVal);
#endif

        /* Compare the CRCs*/
        /* the return code is not needed because the result of the compare is
        treated using events by the Prog<OEM> state machine*/
        (void)PROG_CRC_Compare();


                break;
#endif
            default:
                /* couldn't happen, error case */
                break;
        } /*switch (ubAlgo)*/
#endif /*((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_STANDARD_REPROG))*/
    }
#endif /*((PROG_SEG_LIST_CKS == STD_ON) && (PROG_IMPL_VARIANT != PROG_IMPL_10) && (PROG_IMPL_VARIANT != PROG_IMPL_11)&& (PROG_IMPL_VARIANT != PROG_IMPL_90) && (PROG_IMPL_VARIANT != PROG_IMPL_91))*/
    DBG_PROG_CHECKSEGMENTLISTCRC_EXIT();
}
/*------------------------{end PROG_CheckSegmentListCrc}--------------------------*/


/*---------------------------{PROG_Do_CoherencyCheck}-----------------------------*/
void PROG_Do_CoherencyCheck(void)
{
#if (PROG_COHERENCY_CHECK_ENABLE == STD_ON)
    tProgStatus eCoherencyStatus;
    tProgCohChkResult eCohChkResult;
#endif
#if (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON)
    u8 ubDgpStatus;
#endif /* (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON) */
    DBG_PROG_DO_COHERENCYCHECK_ENTRY();

#if (PROG_COHERENCY_CHECK_ENABLE == STD_ON)
#if (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON)
    /* Check downgrade protection */
    eCoherencyStatus = PROG_DowngradeProtection_CompareRfsForCoherencyCheck_Impl40(&ubDgpStatus);

    if (PROG_E_OK != eCoherencyStatus)
    {
        /* Missing Rfs driver */
        m_stDiagMessageInfo.pubTxData[PROG_RC_ROUTINE_STATUS_BASE_INDEX] = (u8)ubDgpStatus;

        /*Send positive response*/
        m_stDiagMessageInfo.ulLength = PROG_COH_CHK_RESP_SIZE;
        UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, UDS_ACK);
    }
    else
#endif /* (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON) */
    {
        eCoherencyStatus = PROG_CustomCoherencyCheck(&eCohChkResult);
        if(PROG_E_OK == eCoherencyStatus)
        {
#if(PROG_IMPL_VARIANT == PROG_IMPL_50)
            /* Set the routineInfo */
            m_stDiagMessageInfo.pubTxData[PROG_RC_ROUTINE_INFO_BASE_INDEX] = PROG_ROUTINE_FINISHED_OK;
#endif
            /*Get the coherency check result*/
            m_stDiagMessageInfo.pubTxData[PROG_RC_ROUTINE_STATUS_BASE_INDEX] = (u8)eCohChkResult;
            /*Send positive response*/
            m_stDiagMessageInfo.ulLength = PROG_COH_CHK_RESP_SIZE;
#if(PROG_IMPL_VARIANT == PROG_IMPL_60)
            /* Allow integration code to manage the response */
            PROG_Custom_CheckProgDepRoutine_Succeed(m_stDiagMessageInfo.pubTxData,&m_stDiagMessageInfo.ulLength);
#endif
            UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, UDS_ACK);
            /*Send finished event*/
            PROG_HsmEmit (&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);
        }
        else if (PROG_E_BUSY == eCoherencyStatus)
        /* the PROG_CustomCoherencyCheck API shall not return PROG_E_NOT_OK */
        {
            /*wait the end of the check*/
        }
        else
        {
            m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_72;
#if(PROG_IMPL_VARIANT == PROG_IMPL_60)
            /* Allow integration code to manage the response */
            PROG_Custom_CheckProgDepRoutine_Failed(m_stDiagMessageInfo.pubTxData,&m_stDiagMessageInfo.ulLength,&m_stDiagMessageInfo.ubDiagStatus);
#endif
            UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);
        }
    }
#endif /*#if (PROG_COHERENCY_CHECK_ENABLE == STD_ON)*/
    DBG_PROG_DO_COHERENCYCHECK_EXIT();
}
/*------------------------{end PROG_Do_CoherencyCheck}--------------------------*/



#if (PROG_COHERENCY_CHECK_ENABLE == STD_ON)
/*---------------------------{PROG_CoherencyCheck}-----------------------------*/
tUdsStatus PROG_CoherencyCheck(PduLengthType *pulLen,u8* aubUdsData)
{
    tUdsStatus eStatus;
    DBG_PROG_COHERENCYCHECK_ENTRY(pulLen,aubUdsData);

    eStatus = PROG_GenericRequest(pulLen, aubUdsData,
            PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK);

    DBG_PROG_COHERENCYCHECK_EXIT(eStatus);
    return eStatus;
}
/*------------------------{end PROG_CoherencyCheck}--------------------------*/
#endif /*#if (PROG_COHERENCY_CHECK_ENABLE == STD_ON)*/

#if PROG_IMPL_VARIANT == PROG_IMPL_50
/*---------------------------{PROG_Entry_CoherencyPreCheck}-----------------------------*/
void PROG_Entry_CoherencyPreCheck(void)
{
#if (PROG_COHERENCY_PRE_CHECK_ENABLE == STD_ON)
    tProgCohPreChkResult eCoherencyPreCheckStatus;
    tUdsStatus eUdsStatus;
#endif

    DBG_PROG_ENTRY_COHERENCYPRECHECK_ENTRY();

#if (PROG_COHERENCY_PRE_CHECK_ENABLE == STD_ON)
    eCoherencyPreCheckStatus = PROG_CustomComputeCoherencyPreCheck(m_stDiagMessageInfo.pubData, m_stDiagMessageInfo.ulLength, &eUdsStatus);

    /* In case of a positive Response */
    if (UDS_ACK == eUdsStatus)
    {
        /* Set the routineInfo */
        m_stDiagMessageInfo.pubTxData[PROG_RC_ROUTINE_INFO_BASE_INDEX] = PROG_ROUTINE_FINISHED_OK;

        /* Send the coherency check result in the response */
        m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_COHPRECHK_RESULTS_BASE_INDEX] = (u8)eCoherencyPreCheckStatus;
    }

    /* Send response */
    UDS_LongRequestEnd(PROG_COH_PRE_CHK_RESP_SIZE, m_stDiagMessageInfo.pubTxData, eUdsStatus);
#endif

    DBG_PROG_ENTRY_COHERENCYPRECHECK_EXIT();
}
/*------------------------{end PROG_Entry_CoherencyPreCheck}--------------------------*/
#endif

#if (PROG_COHERENCY_PRE_CHECK_ENABLE == STD_ON)
/*---------------------------{PROG_CoherencyPreCheck}-----------------------------*/
tUdsStatus PROG_CoherencyPreCheck(PduLengthType *pulLen,u8* paubUdsData)
{
    tUdsStatus eStatus;
    DBG_PROG_COHERENCYPRECHECK_ENTRY(pulLen,paubUdsData);

    eStatus = PROG_GenericRequest(pulLen, paubUdsData, PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_PRE_CHECK);

    DBG_PROG_COHERENCYPRECHECK_EXIT(eStatus);
    return eStatus;
}
/*------------------------{end PROG_CoherencyPreCheck}--------------------------*/
#endif /* #if (PROG_COHERENCY_PRE_CHECK_ENABLE == STD_ON) */

#if (PROG_PROGRAMMING_CNTR_ENABLE == STD_ON)
/*---------------------------{PROG_CheckProgrammingCounter}-----------------------------*/
tProgStatus PROG_CheckProgrammingCounter(u8 ubBlockId)
{
    tProgStatus eProgStatus = PROG_E_OK;
    u16 uwProgCntr = 0U;

    uwProgCntr = PROG_CustomGetProgCounter(ubBlockId);

    if ((0U == stCfgBlock[ubBlockId].uwProgCntrMax))
    {
        if (uwProgCntr < 0xFFFFU)
        {
            eProgStatus = PROG_CustomIncrementProgCounter(ubBlockId);
        }
        else
        {
            /* Nothing to Do : eStatus = PROG_E_OK */
        }
    }
    else
    {
        if (uwProgCntr < stCfgBlock[ubBlockId].uwProgCntrMax)
        {
            eProgStatus = PROG_CustomIncrementProgCounter(ubBlockId);
        }
        else
        {
            eProgStatus = PROG_E_NOT_OK;
        }
    }

    return eProgStatus;
}
/*------------------------{end PROG_CheckProgrammingCounter}--------------------------*/
#endif /*#if (PROG_PROGRAMMING_CNTR_ENABLE == STD_ON)*/

#if (PROG_PROGRAMMING_CNTR_ENABLE == STD_ON)
/*---------------------------{PROG_GetProgCntrLockVal}-----------------------------*/
tProgStatus PROG_GetProgCntrLockVal(u8 ubBlockId, u16* puwProgCntMax)
{
    tProgStatus eProgStatus;

    eProgStatus = PROG_E_NOT_OK;

#if (PROG_PRELIM_ERASING_ENABLE == STD_ON)
    if (((PROG_BLOCK_NB-1U) > ubBlockId) && (NULL_PTR != puwProgCntMax))
#else
    if ((PROG_BLOCK_NB > ubBlockId) && (NULL_PTR != puwProgCntMax))
#endif
    {
        *puwProgCntMax = stCfgBlock[ubBlockId].uwProgCntrMax;
        eProgStatus = PROG_E_OK;
    }

    return eProgStatus;
}
/*------------------------{end PROG_GetProgCntrLockVal}--------------------------*/
#endif /*#if (PROG_PROGRAMMING_CNTR_ENABLE == STD_ON )*/


#if ((PROG_PROGRAMMING_CNTR_ENABLE == STD_ON) && (PROG_CNTR_GET_TYPE == PROG_GET_PROG_CNTR_ENABLE))
/*---------------------------{PROG_GetAllProgCntrLockVals}-----------------------------*/
tUdsStatus PROG_GetAllProgCntrLockVals(PduLengthType *pulLen, u8 *aubUdsData)
{
    tUdsStatus eUdsStatus;
    u8 ubBlockId;
    u16 uwProgCntrMax;

#if(PROG_IMPL_VARIANT == PROG_IMPL_40)
    if(m_stReprogInfo.ubRDReceived == TRUE)
    {
        eUdsStatus = UDS_NRC_22;
    }
    else
#endif
    {
    if ((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))
    {
#if (PROG_PRELIM_ERASING_ENABLE == STD_ON)
        for(ubBlockId = 0U; ubBlockId < (PROG_BLOCK_NB-1U); ubBlockId++)
#else
        for(ubBlockId = 0U; ubBlockId < PROG_BLOCK_NB; ubBlockId++)
#endif
        {
            uwProgCntrMax = stCfgBlock[ubBlockId].uwProgCntrMax;
            aubUdsData[3U+(2*ubBlockId)] = (u8)((uwProgCntrMax >> 8U) & 0x00FFU);
            aubUdsData[4U+(2*ubBlockId)] = (u8)((uwProgCntrMax) & 0x00FFU);
        }
        eUdsStatus = UDS_ACK;

#if (PROG_PRELIM_ERASING_ENABLE == STD_ON)
        /* Set length to 3(request func + DID) + 2 lock val */
        *pulLen = (u16) (3U + (u16)(2U * (PROG_BLOCK_NB-1U)));
#else
        /* Set length to 3(request func + DID) + 2 lock val */
        *pulLen = (u16) (3U + (u16)(2U * PROG_BLOCK_NB));
#endif
    }
    else
    {
        eUdsStatus = UDS_ERR_COHE;
    }
    }
    return(eUdsStatus);
}
/*------------------------{end PROG_GetAllProgCntrLockVals}--------------------------*/
#endif /*#if (PROG_PROGRAMMING_CNTR_ENABLE == STD_ON && (PROG_CNTR_GET_TYPE == PROG_GET_PROG_CNTR_ENABLE))*/


#if (PROG_UPDATE_TP_PARAM_ENABLE == STD_ON)
/*---------------------------{PROG_GetTpParam}-----------------------------*/
tUdsStatus PROG_GetTpParam(PduLengthType *pulLen,u8* aubUdsData)
{
    tUdsStatus eUdsStatus;

#if(PROG_IMPL_VARIANT == PROG_IMPL_40)
    if(m_stReprogInfo.ubRDReceived == TRUE)
    {
        eUdsStatus = UDS_NRC_22;
    }
    else
#endif
    {
    if ((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))
    {
        aubUdsData[PROG_DID_BS_VALUE_BASE_INDEX] = (u8)BlPduR_GetTpParameter(BLPDUR_TP_BS);

#if(PROG_IMPL_VARIANT == PROG_IMPL_50)
        aubUdsData[PROG_DID_STMIN_VALUE_BASE_INDEX] = (u8)BlPduR_GetTpParameter(BLPDUR_TP_STMIN);
#endif
        *pulLen = PROG_UPDATE_TP_PARAM_RESPONSE_SIZE;
        eUdsStatus = UDS_ACK;
    }
    else
    {
        eUdsStatus = UDS_ERR_COHE;
    }
    }
    return(eUdsStatus);
}
/*------------------------{end PROG_GetTpParam}--------------------------*/
#endif /*#if (PROG_UPDATE_TP_PARAM_ENABLE == STD_ON) */


#if (PROG_UPDATE_TP_PARAM_ENABLE == STD_ON)
/*---------------------------{PROG_SetTpParam}-----------------------------*/
tUdsStatus PROG_SetTpParam(PduLengthType *pulLen,u8* aubUdsData)
{
    tBlPduRStatus eBlpdurStatus;
    tUdsStatus eUdsStatus;

#if(PROG_IMPL_VARIANT == PROG_IMPL_40)
    if(m_stReprogInfo.ubRDReceived == TRUE)
    {
        eUdsStatus = UDS_NRC_22;
    }
    else
#endif
    {
    eUdsStatus = UDS_ACK;
    if ((NULL_PTR != pulLen) && (NULL_PTR != aubUdsData))
    {
#if(PROG_IMPL_VARIANT != PROG_IMPL_50)
        eBlpdurStatus = BlPduR_TpChangeParameter(BLPDUR_TP_BS, (u16)aubUdsData[PROG_DID_BS_VALUE_BASE_INDEX]);

        if(eBlpdurStatus == BLPDUR_E_OK)
        {
#endif
#if(PROG_IMPL_VARIANT == PROG_IMPL_50)
            if(((aubUdsData[PROG_DID_STMIN_VALUE_BASE_INDEX] > 0x7FU) && (aubUdsData[PROG_DID_STMIN_VALUE_BASE_INDEX] < 0xF1U)) ||
                (aubUdsData[PROG_DID_STMIN_VALUE_BASE_INDEX] > 0xF9U))
            {
                eUdsStatus = UDS_NRC_31;
            }
            else
            {
                eBlpdurStatus = BlPduR_TpChangeParameter(BLPDUR_TP_STMIN, (u16)aubUdsData[PROG_DID_STMIN_VALUE_BASE_INDEX]);
                if(eBlpdurStatus == BLPDUR_E_OK)
                {
                    eBlpdurStatus = BlPduR_TpChangeParameter(BLPDUR_TP_BS, (u16)aubUdsData[PROG_DID_BS_VALUE_BASE_INDEX]);
                    if(eBlpdurStatus == BLPDUR_E_NOT_OK)
                    {
                        eUdsStatus = UDS_NRC_22;
                    }
                    else
                    {
                        /* do nothing */
                    }
                }
                else
                {
                    eUdsStatus = UDS_NRC_22;
                }
            }
#endif
#if(PROG_IMPL_VARIANT != PROG_IMPL_50)
        }
        else
        {
            eUdsStatus = UDS_NRC_22;
        }
#endif
    }
    else
    {
        eUdsStatus = UDS_ERR_COHE;
    }

    if (UDS_ACK == eUdsStatus)
    {
        *pulLen = 3U;
    }
    }
    return(eUdsStatus);
}
/*------------------------{end PROG_SetTpParam}--------------------------*/
#endif /*#if (PROG_UPDATE_TP_PARAM_ENABLE == STD_ON) */


#if (PROG_RESUM_REPROG == STD_ON)
/*----------------------{PROG_RestoreResumeInfo}------------------------*/
void PROG_RestoreResumeInfo(void)
{
    PROG_CustomGetSegmentList(&m_stSegList);
}
/*--------------------{end PROG_RestoreResumeInfo}----------------------*/
#endif /*#if (PROG_RESUM_REPROG == STD_ON) */


#if ((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_AUTHENTICATED_REPROG))
NCS_PRI_FCT tProgStatus PROG_CheckBlockHeaderCustomData(u8 * pubHeaderAddress)
{
    tProgStatus eProgStatusTargetName;
    tProgStatus eProgStatusRollbackId;
    tProgStatus eProgStatusCompatibilityId;
    tProgStatus eProgStatusUuid;
    tProgStatus eReturnProgStatus;

    eProgStatusTargetName      = PROG_CustomCheckTargetName(&pubHeaderAddress[PROG_BLOCK_HEADER_TARGETNAME_OFFSET], PROG_BLOCK_HEADER_TARGETNAME_SIZE);
    eProgStatusRollbackId      = PROG_CustomCheckRollbackId(&pubHeaderAddress[PROG_BLOCK_HEADER_ROLLBACKID_OFFSET], PROG_BLOCK_HEADER_ROLLBACKID_SIZE);
    eProgStatusCompatibilityId = PROG_CustomCheckCompatibilityId(&pubHeaderAddress[PROG_BLOCK_HEADER_COMPATIBILITYID_OFFSET], PROG_BLOCK_HEADER_COMPATIBILITYID_SIZE);
    eProgStatusUuid            = PROG_CustomCheckUuid(&pubHeaderAddress[PROG_BLOCK_HEADER_UUID_OFFSET], PROG_BLOCK_HEADER_UUID_SIZE);

    if( (PROG_E_NOT_OK == eProgStatusTargetName) ||
        (PROG_E_NOT_OK == eProgStatusRollbackId) ||
        (PROG_E_NOT_OK == eProgStatusCompatibilityId) ||
        (PROG_E_NOT_OK == eProgStatusUuid))
    {
        eReturnProgStatus = PROG_E_NOT_OK;
    }
    else
    {
        eReturnProgStatus = PROG_E_OK;
    }

    return eReturnProgStatus;
}

NCS_PRI_FCT void PROG_ExtractDataFromBlockHeader(u32* pulHeaderSize, u32* pulFileSize, u8* paubSigningInfos, u8* paubHeaderSignature)
{
    u16 uwIdxTemp;
    u16 uwIdx;
    u32 ulStartAddress;

    /* Extract the Block Header (The block header is always written into the first segment from each logical block). */

    /* Calculate the read address                    */
    /* The read is done using the logical address    */
#if (PROG_OTA_DUALBANK_USED == STD_ON)
    ulStartAddress = PROG_CustomCalcInactiveBankReadAddr(stConfigSegment[stCfgBlock[m_ubFpBlockId].ubFirstSegmentId].ulStartAddress);
#else
    ulStartAddress = stConfigSegment[stCfgBlock[m_ubFpBlockId].ubFirstSegmentId].ulStartAddress;
#endif /*(PROG_OTA_DUALBANK_USED == STD_ON)*/
    (void)PROG_MemDataAccess( m_astCfgMemory[stConfigSegment[stCfgBlock[m_ubFpBlockId].ubFirstSegmentId].ubMemoryIdx].eMemoryType,
   PROG_MEM_OPERATION_TYPE_READ, ulStartAddress,
    PROG_IMPL31_HEADER_SIZE, m_aubBlockHeader);

    /* Get the HeaderSize field*/
    *pulHeaderSize = ((u32)m_aubBlockHeader[0] << 24) | ((u32)m_aubBlockHeader[1] << 16) | ((u32)m_aubBlockHeader[2] << 8) | ((u32)m_aubBlockHeader[3]);

    /* Get the FileSize field*/
    *pulFileSize= (((u32)m_aubBlockHeader[4] << 24) | ((u32)m_aubBlockHeader[5] << 16) | ((u32)m_aubBlockHeader[6] << 8) | ((u32)m_aubBlockHeader[7]));

    /* Get the SigningInfos and the HeaderSignature */
    for (uwIdx=0; uwIdx<PROG_IMPL31_SIGNING_INFO_SIZE; uwIdx++)
    {
        uwIdxTemp= PROG_SIGNING_INFO_OFFSET + uwIdx;
        paubSigningInfos[uwIdx] = m_aubBlockHeader[uwIdxTemp];
    }

    for (uwIdx=0; uwIdx<PROG_IMPL31_HEADER_SIGNATURE_SIZE; uwIdx++)
    {
        uwIdxTemp= PROG_BLOCK_HEADER_SIZE + uwIdx;
        paubHeaderSignature[uwIdx] = m_aubBlockHeader[uwIdxTemp];
    }
}

NCS_PRI_FCT void PROG_StartBlockHeaderCheck(void)
{
    tProgStatus eProgStatus;
    u32 ulHeaderSize = 0u;
    u32 ulFileSize = 0u;
    /*Variable to store the Programmed data size*/
    u32 ulProgrammedDataSize = m_stReprogInfo.ulReceivedSizeOfData;
    m_ubBlockHeaderCheckFailed = PROG_FALSE;

    /* Get the Block header and extract the HeaderSize and FileSize, the SigningInfos and the HeaderSignature */
    PROG_ExtractDataFromBlockHeader(&ulHeaderSize, &ulFileSize, m_aubBlockHeaderSigningInfo, m_aubBlockHeaderSignature);

#if (PROG_COMPRESSION_ENABLE == STD_ON)
    if (TRUE == m_stReprogInfo.ubCompRequired)
    {
        ulProgrammedDataSize = m_stReprogInfo.ulTotalDecompDataWrite;
    }
    else
    {
        /*Nothing to do*/
    }
#endif /*(PROG_COMPRESSION_ENABLE == STD_ON)*/

    /* Check that the HeaderSize(=176bytes) and FileSize(=Flashed File data size) are OK  */
    if ((ulHeaderSize != ((u32)PROG_BLOCK_HEADER_SIZE)) || (ulFileSize != (ulProgrammedDataSize - (u32)PROG_IMPL31_HEADER_SIZE)))
    {
        /* Block header operation revealed an issue in the Block header */
        m_ubBlockHeaderCheckFailed = PROG_TRUE;
        /* Send failed event */
        PROG_HsmEmit (&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
    }
    else
    {
        /* Check the SigningInfo */
        eProgStatus = PROG_CustomCheckSigningInfo(&m_aubBlockHeaderSigningInfo[0], PROG_BLOCK_HEADER_SIGNINGINFO_SIZE);
        if (PROG_E_OK == eProgStatus)
        {
            /* ---  This call should be done only for the ASR Cry 4.0.3 --- */
            PROG_GetPublicKey(&m_stProgAsymPublicKey);
            /* ------------------------------------------------------------ */

            /* start signature check */
            eProgStatus = PROG_VerifySignature
                (
                    &m_stProgAsymPublicKey,
                    m_aubBlockHeader,
                    PROG_BLOCK_HEADER_SIZE,
                    m_aubBlockHeaderSignature
                );

            if (PROG_E_NOT_OK == eProgStatus)
            {
                /* wrong signature */
                /* Block header operation revealed an issue in the Block header */
                m_ubBlockHeaderCheckFailed = PROG_TRUE;
                /* Send failed event */
                PROG_HsmEmit (&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
            }
            else
            {
                /* the Signature verification is driven by the PROG_CsmSignatureCheckNotification and */
                /* at the end PROG_EVENT_FAILED or PROG_EVENT_CRYPTO_FINISH event will be pushed */
            }
        }
        else
        {
            /* wrong signing info */
            /* Block header operation revealed an issue in the Block header */
            m_ubBlockHeaderCheckFailed = PROG_TRUE;
            /* Send failed event */
            PROG_HsmEmit (&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
        }
    }
}
#endif /*((PROG_IMPL_VARIANT == PROG_IMPL_31) && (PROG_REPROG_TYPE == PROG_AUTHENTICATED_REPROG))*/




/*----------------------------{PROG_Entry_SecureChecksumFailed}-----------------------------*/
void PROG_Entry_SecureChecksumFailed(void)
{

#if (((PROG_IMPL_VARIANT == PROG_IMPL_31) || (PROG_IMPL_VARIANT == PROG_IMPL_50)) && (PROG_CHECK_MEMORY_ENABLE == STD_ON))
    DBG_PROG_ENTRY_SECURECHECKSUMFAILED_ENTRY();

    /* Secure checksum calculation failed,
    send positive response with general failure status */

    m_stDiagMessageInfo.ulLength     = PROG_CRC_COMP_RESPONSE_SIZE;
    m_stDiagMessageInfo.ubDiagStatus = UDS_ACK;
    m_stDiagMessageInfo.pubTxData[PROG_RC_STATUS_RECORD_VERIF_RESULTS_BASE_INDEX] =
        (u8) (PROG_RC_STATUS_RECORD_VERIF_RESULTS_GEN_FAILURE);

    UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);


    DBG_PROG_ENTRY_SECURECHECKSUMFAILED_EXIT();
#endif /*(((PROG_IMPL_VARIANT == PROG_IMPL_31) || (PROG_IMPL_VARIANT == PROG_IMPL_50)) && (PROG_CHECK_MEMORY_ENABLE == STD_ON))*/
#if (PROG_IMPL_VARIANT == PROG_IMPL_60)
    m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_72;
    PROG_Custom_CheckMemoryRoutine_Failed(m_stDiagMessageInfo.pubTxData, &m_stDiagMessageInfo.ulLength, &m_stDiagMessageInfo.ubDiagStatus);
    UDS_LongRequestEnd(m_stDiagMessageInfo.ulLength, m_stDiagMessageInfo.pubTxData, m_stDiagMessageInfo.ubDiagStatus);
#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_60)*/
#if (PROG_IMPL_VARIANT == PROG_IMPL_30)
    /* send negative response */
    UDS_LongRequestEnd(PROG_CHK_PROG_DEP_POS_RESPONSE_SIZE, m_stDiagMessageInfo.pubTxData, UDS_NRC_72);

    /* Indicate CPD request processing is complete */
    PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FINISHED);

#if (PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)
    /*Error during secureboot/Appl checksum calc., update ProgrammingStatus*/
    PROG_SetProgrammingStatus(PROG_RC_CHECKSUM_VERIFY, PROG_FALSE);
#endif /*(PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON)*/

#endif /*(PROG_IMPL_VARIANT == PROG_IMPL_30)*/
}
/*----------------------------{end PROG_Entry_SecureChecksumFailed}-------------------------*/

/*------------------------{PROG_Entry_DecryptionFinish}--------------------------*/
void PROG_Entry_DecryptionFinish(void)
{
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
    tProgCryState eCryState;
    u32           ulIdx;
    u32           ulDataLength;
#if ((PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CAL_PRESENT == STD_ON)) 
    u32           ulsize;
#endif
    /* Get crypto state */
    eCryState = PROG_GetDecryptionState();

    if (PROG_DECRYPTION_UPDATE_END == eCryState)
    {
        m_ubFinishDecryption                 = PROG_TRUE;
        m_stCryptoData.ulNextWritePosition   = 0U;
        m_stCryptoData.ulCryptoBufferSize    = PROG_DECRYPT_BUFFER_SIZE;
        ulDataLength = m_stPageBuffer.ulNewDataLength;

        /* Is there data not written previously */
        if (ulDataLength != 0U)
        {
            /* Fill the buffer with remaining data not written previously */
            for (ulIdx = 0U; ulIdx < ulDataLength; ulIdx++)
            {
                m_stCryptoData.aubCryptoBuffer[ulIdx] = m_stPageBuffer.aubData[ulIdx];
            }
            m_stCryptoData.ulCryptoBufferSize -= ulDataLength;
        }
        /* Finish the decryption */
        PROG_DecryptionFinish(&m_stCryptoData.aubCryptoBuffer[m_stPageBuffer.ulNewDataLength],
                                &m_stCryptoData.ulCryptoBufferSize);
    }
    else
    {
#if (PROG_COMPRESSION_ENABLE == STD_ON)
        if ((TRUE == m_stReprogInfo.ubCompRequired)
#if (PROG_CAL_PRESENT == STD_ON)
        && ( m_uProgDecompStatus == PROG_DECOMP_FINISH))

        {
            ulsize = m_stWriteInfo.ulAddressToWrite - m_stCurrentSegment.ulStartAddress ;
            m_stWriteInfo.ulDataToBeWritten = m_stReprogInfo.ulMemorySizeExpected - ulsize ;
            /* Data are present in Page buffer, it shall be completed and written*/
            for (ulIdx = 0U; ulIdx <(m_stWriteInfo.ulDataToBeWritten); ulIdx++)
            {
                m_stPageBuffer.aubData[ulIdx] = m_stWriteInfo.pubDecompData[2U + ulIdx];
            }
            /* Emit event PROG_EVENT_WRITE */
            if (ulsize != 0U)
            {
                m_stPageBuffer.ulNewDataLength =  (u16)(m_stWriteInfo.ulDataToBeWritten);
                /* Emit event PROG_EVENT_WRITE */
                PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_WRITE);
            }
            else
            {
                /* Emit event PROG_EVENT_WRITE_CHECK */
                PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK);
            }
        }
        else
        {
            /* do nothing*/
        }
#endif /*(PROG_CAL_PRESENT == STD_ON*/
#endif
    }
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
}
/*-------------------------{end PROG_Entry_DecryptionFinish}---------------------------*/

/*------------------------{PROG_Do_DecryptionFinish}--------------------------*/
void PROG_Do_DecryptionFinish(void)
{
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
    tProgStatus eCryStatus;
    u32         ulDecryptedLength;
#if (PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CAL_PRESENT == STD_ON)
     tProgStatus eProgStatus;
#endif /* (PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CAL_PRESENT == STD_ON)*/

    /* Get crypto Status */
    eCryStatus = PROG_GetDecryptionStatus();

    if (PROG_E_OK == eCryStatus)
    {
#if (PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CAL_PRESENT == STD_ON)
        if (TRUE == m_stReprogInfo.ubCompRequired)
        {
            if (m_stCryptoData.ulCryptoBufferSize != 0U)
            {
                /* Need to decompress before writing */
                /* Call decompression module */
                PROG_DecompInputParamInit();
                eProgStatus = PROG_DecompressData(&m_stCryptoData.aubCryptoBuffer[0U],
                                                        (u16)(m_stCryptoData.ulCryptoBufferSize & 0x0000FFFFU));
                if(eProgStatus != PROG_E_OK)
                {
                    /* Send negative response NRC31 */
                    m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_31;
                }
            }
            /* Emit event PROG_EVENT_WRITE_CHECK */
            PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK);
        }
        else
#endif /* (PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CAL_PRESENT == STD_ON) */
        {
            ulDecryptedLength = (m_stCryptoData.ulCryptoBufferSize + (u32)m_stPageBuffer.ulNewDataLength);
            m_stPageBuffer.ulNewDataLength        = 0U;
            m_ubWaitCryptoBeforeTdEnd             = PROG_TRUE;
            if (ulDecryptedLength != 0U)
            {
                m_stWriteInfo.ulDataToBeWritten += ulDecryptedLength;
                /* Emit event PROG_EVENT_WRITE */
                PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_WRITE);
            }
            else
            {
                /* Emit event PROG_EVENT_WRITE_CHECK */
                PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK);
            }
        }
    }
    else if (PROG_E_NOT_OK == eCryStatus)
    {
        /* Emit event PROG_EVENT_FAILED */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_FAILED);
    }
    else
    {
      /* Nothing to do */
    }
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
}
/*-------------------------{end PROG_Do_DecryptionFinish}---------------------------*/

/*------------------------{PROG_Entry_DecryptionUpdate}--------------------------*/
void PROG_Entry_DecryptionUpdate(void)
{
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
    tProgCryState eCryState;
    u8           *pubDataToDecrypt;
    u16           uwlFillPosition;

    if (m_stCryptoData.ubOperationInProgress == PROG_DECRYPTION_IN_PROGRESS)
    {
        /* Get crypto state */
        eCryState = PROG_GetDecryptionState();

        if ((PROG_DECRYPTION_START  != eCryState) &&
            (PROG_DECRYPTION_UPDATE != eCryState) &&
            (PROG_DECRYPTION_FINISH != eCryState)  )
        {
            m_stCryptoData.ulNextWritePosition   = 0U;
            uwlFillPosition = 0U;

            pubDataToDecrypt = &m_stDiagMessageInfo.pubData[2U];

            /* Update decryption */
            PROG_DecryptionUpdate(pubDataToDecrypt,
                                  m_stCryptoData.ulEncryptDataSize,
                                  &m_stCryptoData.aubCryptoBuffer[uwlFillPosition],
                                  &m_stCryptoData.ulCryptoBufferSize);
        }
        else
        {
            /* Nothing to do */
        }
    }
    else
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
    {
        /* Emit event PROG_EVENT_WRITE_CHECK */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK);
    }
}
/*-------------------------{end PROG_Entry_DecryptionUpdate}---------------------------*/

/*------------------------{PROG_Do_DecryptionUpdate}--------------------------*/
void PROG_Do_DecryptionUpdate(void)
{
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
    tProgCryState eCryState;

#if (PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CAL_PRESENT == STD_ON)
    tProgStatus eProgStatus;
#endif /* (PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CAL_PRESENT == STD_ON) */

    /* Get crypto state */
    eCryState = PROG_GetDecryptionState();

    if (PROG_DECRYPTION_UPDATE_END == eCryState)
    {
        /* Decryption done first */

#if (PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CAL_PRESENT == STD_ON)
        if (TRUE == m_stReprogInfo.ubCompRequired)
        {
            /* Need to decompress before writing */
            /* Call decompression module */
            eProgStatus = PROG_DecompressData(&m_stCryptoData.aubCryptoBuffer[0U],
                                                    (u16)(m_stCryptoData.ulCryptoBufferSize & 0x0000FFFFU));
            if(eProgStatus != PROG_E_OK)
            {
                /* Send negative response NRC31 */
                m_stDiagMessageInfo.ubDiagStatus = UDS_NRC_31;
            }
            else
            {
                /*Set flag TD received*/
                m_stWriteInfo.ubTDReceived = TRUE;
            }
        }
        else
#endif /* (PROG_COMPRESSION_ENABLE == STD_ON) && (PROG_CAL_PRESENT == STD_ON) */
        {
            /* Update total data decrypted */
            m_stWriteInfo.ulDataToBeWritten += m_stCryptoData.ulCryptoBufferSize;
        }
        /* Emit event PROG_EVENT_WRITE */
        PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK);
    }
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON)*/
}
/*-------------------------{end PROG_Do_DecryptionUpdate}---------------------------*/

/*------------------------{PROG_Entry_RTEDecompFinish}--------------------------*/
void PROG_Entry_RTEDecompFinish(void)
{
#if (PROG_CSM_DECRYPTION_ENABLE == STD_OFF)
#if (PROG_COMPRESSION_ENABLE == STD_ON)
    PduLengthType ulLength;
#if ( PROG_CAL_PRESENT == STD_OFF)
    tDecompressStateType eCompStatus = SA_DECOMP_FINISH;
#else
    tProgDecompressStateType eCompStatus = PROG_DECOMP_FINISH;
#endif
        if (TRUE == m_stReprogInfo.ubCompRequired)
        {
            m_ubDecompNotWritten             = PROG_TRUE;
            /* Get Decompressed Data */
#if (PROG_CAL_PRESENT == STD_OFF)
            eCompStatus = SA_GetDecompressedData(&m_stWriteInfo.pubDecompData, &ulLength);
            if (SA_DECOMP_FINISH == eCompStatus)
#else
            eCompStatus = PROG_GetDecompressedData(&m_stWriteInfo.pubDecompData, &ulLength);
            if(PROG_DECOMP_FINISH == eCompStatus)
#endif

            {
                m_stWriteInfo.ulDataToBeWritten  = ulLength;

                /* Emit event PROG_EVENT_WRITE */
                if (m_stWriteInfo.ulDataToBeWritten != 0U)
                {
                    /* Emit event PROG_EVENT_WRITE */
                    PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_WRITE);
                }
                else
                {
#if (PROG_CAL_PRESENT == STD_ON)
                    /* Check if there is remaining data by calling Decomp Finish */
                     (void)PROG_DecompressData(NULL_PTR,0);
#endif
#if (PROG_CAL_PRESENT == STD_OFF)
                     eCompStatus = SA_GetDecompressedData(&m_stWriteInfo.pubDecompData, &ulLength);
                     if (SA_DECOMP_FINISH == eCompStatus)
#else
                     eCompStatus = PROG_GetDecompressedData(&m_stWriteInfo.pubDecompData, &ulLength);
                     if(PROG_DECOMP_FINISH == eCompStatus)
#endif
                    {
                          m_stWriteInfo.ulDataToBeWritten  = ulLength;
                            /* Check if there is data to be written */
                            if (m_stWriteInfo.ulDataToBeWritten != 0U)
                            {
                                /* Emit event PROG_EVENT_WRITE */
                                PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_WRITE);
                            }
                            else
                            {
                                /* Check if all data had been written */
                                /* Emit event PROG_EVENT_WRITE_CHECK */
                                PROG_HsmEmit(&PROG_HsmScPROG, PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK);
                            }
                    }
                }
            }
            else
            {
                /* do nothing*/
            }
        }
        else
        {
                /* do nothing*/
        }

#endif /* (PROG_COMPRESSION_ENABLE == STD_ON)*/
#endif /*(PROG_CSM_DECRYPTION_ENABLE == STD_OFF)*/
}
/*-------------------------{end PROG_Entry_RTEDecompFinish}---------------------------*/

#if (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON)
/*------------------------{PROG_GetPseudoFlashDriverAddress}--------------------------*/
tProgAddressType PROG_GetPseudoFlashDriverAddress(void)
{
    return (stConfigSegment[stCfgBlock[PROG_PFT_BLOCK].ubFirstSegmentId].ulStartAddress);
}
/*-------------------------{end PROG_GetPseudoFlashDriverAddress}---------------------------*/
#endif /* (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON) */

#if (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON)
/*------------------------{PROG_GetBlockIdByIndex}--------------------------*/
u16 PROG_GetBlockIdByIndex(u8 ubLogicalBlockIndex)
{
    u16 uwBlockId;

    uwBlockId = 0xFFFFU;

    if (ubLogicalBlockIndex < PROG_BLOCK_NB)
    {
        uwBlockId = stCfgBlock[ubLogicalBlockIndex].uwBlockIdentifier;
    }
    return uwBlockId;
}
/*-------------------------{end PROG_GetBlockIdByIndex}---------------------------*/

/*------------------------{PROG_GetBlockDowngradeFlagByIndex}--------------------------*/
tProgBoolean PROG_GetBlockDowngradeFlagByIndex(u8 ubLogicalBlockIndex)
{
    tProgBoolean ubBlockDowngradeFlag;
    DBG_PROG_GETBLOCKDOWNGRADEFLAGBYINDEX_ENTRY(ubLogicalBlockIndex );

    ubBlockDowngradeFlag = PROG_FALSE;

    if (ubLogicalBlockIndex < PROG_BLOCK_NB)
    {
        ubBlockDowngradeFlag = stCfgBlock[ubLogicalBlockIndex].ubDwngrdProtected;
    }
    DBG_PROG_GETBLOCKDOWNGRADEFLAGBYINDEX_EXIT(ubBlockDowngradeFlag );
    return ubBlockDowngradeFlag;
}
/*-------------------------{end PROG_GetBlockDowngradeFlagByIndex}---------------------------*/
#endif /* (PROG_ENABLE_DOWNGRADE_PROTECTION == STD_ON) */

