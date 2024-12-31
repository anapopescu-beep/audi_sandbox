/*********************************************************************************/
/*                                                                               */
/*                                BOOT Layers                                    */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                                 PROG configuration                            */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file PROG_Cbk.h                      */
/*%%  |                             |  %%  \brief PROG layer include plugin file */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.14.0 BL-3.X              */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*********************************************************************************/
/* Copyright 2010 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*********************************************************************************/



#ifndef PROG_CBK_H
#define PROG_CBK_H

#if (PROG_CRY_PRESENT == STD_ON)
#include "Csm.h"
#endif /* (PROG_CRY_PRESENT == STD_ON) */

/*------------------------------{PROG_SwitchApplicationModeInd}-----------------*/
extern void PROG_SwitchApplicationModeInd(void);

/*--------------------------{PROG_DisableECCCheck}------------------------------*/
extern void PROG_DisableECCCheck(void);

/*--------------------------{PROG_EnableECCCheck}-------------------------------*/
extern void PROG_EnableECCCheck(void);



/*--------------------------------{PROG_CheckProgRequest}------------------------*/
extern u8 PROG_CheckProgRequest(void);

/*--------------------------{PROG_JumpToApplication}-----------------------------*/
extern void PROG_JumpToApplication(void);

/*------------------------------{PROG_IsValidApplication}-----------------------*/
extern tProgBoolean PROG_IsValidApplication(void);

/*------------------------------{PROG_VerifySectionCrc}--------------------------*/
extern tProgCompleteStatus PROG_VerifySectionCrc(void);

/*------------------------------{PROG_InvalidateSection_BlockID}----------------*/
extern tProgStatus PROG_InvalidateSection_BlockID(u8 ubBlockId);
/*--------------------------{PROG_GetSuppressBitFromAppli}--------------------*/
extern u8 PROG_GetSuppressBitFromAppli(void);

/*------------------------{PROG_CustomWriteFingerprint}-----------------------------*/
extern tProgStatus PROG_CustomWriteFingerprint(u8 * pubRamBuffer);

/*------------------------{PROG_CustomGetWriteFingerprintStatus}--------------------*/
extern tProgStatus PROG_CustomGetWriteFingerprintStatus(void);
/*---------------------------{PROG_CustomSetDownloadVerificationSuccess}----------------------*/
extern tProgStatus PROG_CustomSetDownloadVerificationSuccess(u8 ubLogicalBlockId, u8 ubLogicalSegmentId, tProgBoolean ubCompareSuccess);
/* PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON */

/*---------------------------{PROG_CustomGetResetCause}-----------------------------*/
extern void PROG_CustomGetResetCause(tProgResCause* pubResetCause, tProgBoolean* pubSendResp);

/*---------------------------{PROG_CustomStoreResetCause}---------------------------*/
extern void PROG_CustomStoreResetCause(tProgResCause ubResetCause, tProgBoolean ubSendResp);

/*---------------------------{PROG_CustCheckProgPrecond}----------------------------*/
extern tProgStatus PROG_CustCheckProgPrecond(void);



#ifdef NCS_UNITARY_TEST
extern void PROG_RamRead(tProgAddressType uMemAddress, tDataLength uLength, tDataBufferType PROG_FAR_POINTER paubDataBuffer);
extern void PROG_RamWrite(tProgAddressType uMemAddress, tDataLength uLength, tDataBufferType PROG_FAR_POINTER paubDataBuffer);
#endif     /* NCS_UNITARY_TEST */
/*---------------------------{PROG_CustomWriteCRC}-----------------------------*/
extern void PROG_CustomWriteCRC(u32 ulCrcVal);


/*---------------------------{PROG_CustomCoherencyCheck}-----------------------------*/
extern tProgStatus PROG_CustomCoherencyCheck(tProgCohChkResult* eCohChkResult);



extern u16 PROG_CustomGetProgCounter(u8 ubBlockId);

extern tProgStatus PROG_CustomIncrementProgCounter(u8 ubBlockId);

extern void PROG_CustomGetPartProgSegList(u8 ubBlockId,u32* aulSegProgSize,u8* ubSegNbr);
extern void PROG_CustomSetPartProgSegList(u8 ubBlockId,u32* aulSegProgSize,u8* ubSegNbr);
extern void PROG_CustomClearPartProgSegList(u8 ubBlockId);

extern void PROG_CustomGetAsymPublicKey(const u8** paubPublicModulus, u32* pulPublicExponent);




 





                                                                                                                                                                
extern tProgStatus PROG_CustomGetTpBsValue(u8* ubTpBsValue);



/*---------------------------{PROG_CustomDownloadNotification}-----------------------------*/
extern tProgStatus PROG_CustomDownloadNotification(u32 ulStartAddress, u32 ulMemorySize);

/*---------------------------{PROG_CustomGetEraseStatus}-----------------------------*/
extern tProgEraseStatus PROG_CustomGetEraseStatus(u8 ubBlockId);

/*---------------------------{PROG_CustomSetEraseStatus}-----------------------------*/
extern tProgStatus PROG_CustomSetEraseStatus(u8 ubBlockId,tProgEraseStatus eEraseStatus);

/*---------------------------{PROG_CustomMemoryAccessNotification}-------------------*/
extern tProgStatus PROG_CustomMemoryAccessNotification
(
    tProgMemType eMemType,
    tOperationType eOperationType,
    tProgAddressType uMemAddress,
    tDataLength uLength,
    tDataBufferType PROG_FAR_POINTER paubDataBuffer
);





#endif     /* PROG_CBK_H */
