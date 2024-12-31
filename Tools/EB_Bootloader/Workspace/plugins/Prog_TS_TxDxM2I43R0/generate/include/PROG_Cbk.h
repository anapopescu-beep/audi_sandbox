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
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.43.0 BL3              */
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

[!AUTOSPACING!]


#ifndef PROG_CBK_H
#define PROG_CBK_H

#if (PROG_CRY_PRESENT == STD_ON)
#include "Csm.h"
#endif /* (PROG_CRY_PRESENT == STD_ON) */
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
#include "PROG_Encrypt.h"
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON) */

#if ((PROG_IMPL_VARIANT == PROG_IMPL_4) || (PROG_IMPL_VARIANT == PROG_IMPL_5))
extern tProgBoolean m_aubBlockDownloadStatus[PROG_SEGMENT_NB]; /* status of the logical download block downloded */
#endif /*((PROG_IMPL_VARIANT == PROG_IMPL_4)) */

/*------------------------------{PROG_SwitchApplicationModeInd}-----------------*/
extern void PROG_SwitchApplicationModeInd(void);

/*--------------------------{PROG_DisableECCCheck}------------------------------*/
extern void PROG_DisableECCCheck(void);

/*--------------------------{PROG_EnableECCCheck}-------------------------------*/
extern void PROG_EnableECCCheck(void);

[!IF "Decryption/Enable_Decryption = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:53:IF1 osc_PROG main ', $project))"!][!ENDSELECT!]
/*--------------------------------{PROG_CustomDecryptData}------------------------*/
extern tProgStatus PROG_CustomDecryptData(u8 ubEncryptionMethod, u8 * pubData, PduLengthType DataLength);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:56:DUMMYELSE2 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('ProgJLR')) and as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL'
    or node:exists(as:modconf('ProgJLR')) and as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='OneLevelBL'
    or node:exists(as:modconf('ProgGM')) or node:exists(as:modconf('ProgFCA')) or node:exists(as:modconf('ProgVCC'))
    or node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgDAG'))
    or node:exists(as:modconf('ProgOEMInd')) or node:exists(as:modconf('ProgFord'))
    or node:exists(as:modconf('ProgPSA'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:63:IF3 osc_PROG main ', $project))"!][!ENDSELECT!]

/*--------------------------------{PROG_CheckProgRequest}------------------------*/
extern u8 PROG_CheckProgRequest(void);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:67:DUMMYELSE4 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "node:exists(as:modconf('ProgJLR')) and as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL'
    or (node:exists(as:modconf('ProgFord')) and as:modconf('ProgFord')/General/PROG_FORD_VARIANT='PBL')
    or (node:exists(as:modconf('ProgJLR')) and as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='OneLevelBL')
    or node:exists(as:modconf('ProgGM')) or node:exists(as:modconf('ProgFCA'))
    or node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgDAG'))
    or node:exists(as:modconf('ProgOEMInd'))
    or node:exists(as:modconf('ProgPSA'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:74:IF5 osc_PROG main ', $project))"!][!ENDSELECT!]

/*--------------------------{PROG_JumpToApplication}-----------------------------*/
extern void PROG_JumpToApplication(void);
/*--------------------------------{PROG_ReturnsIsReProgRequestFromAppli}------------------------*/
extern tProgBoolean PROG_ReturnsIsReProgRequestFromAppli(void);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:80:DUMMYELSE6 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('ProgJLR')) and as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:81:IF7 osc_PROG main ', $project))"!][!ENDSELECT!]

/*--------------------------{PROG_CustomGetSBLStartAddress}-----------------------------*/
extern u32 PROG_CustomGetSBLStartAddress(void);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:85:DUMMYELSE8 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('ProgJLR'))
    and (as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL' or as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='SBL' or
    as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='OneLevelBL'))or (node:exists(as:modconf('ProgFord'))
    and (as:modconf('ProgFord')/General/PROG_FORD_VARIANT='PBL' or as:modconf('ProgFord')/General/PROG_FORD_VARIANT='SBL'))
    or node:exists(as:modconf('ProgFCA'))
    or node:exists(as:modconf('ProgVAG'))
    or (node:exists(as:modconf('ProgOEMInd')) and (./OemInd/Application_Validity_Algo='Custom'))
    or node:exists(as:modconf('ProgDAG'))
    or node:exists(as:modconf('ProgPSA'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:94:IF9 osc_PROG main ', $project))"!][!ENDSELECT!]

/*------------------------------{PROG_IsValidApplication}-----------------------*/
extern tProgBoolean PROG_IsValidApplication(void);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:98:DUMMYELSE10 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('ProgJLR'))
    and (as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL' or as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='SBL'
    or as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='OneLevelBL'))
    or (node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_Mid')
    or node:exists(as:modconf('ProgVAG'))
    or node:exists(as:modconf('ProgDAG'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:104:IF11 osc_PROG main ', $project))"!][!ENDSELECT!]

/*------------------------------{PROG_VerifySectionCrc}--------------------------*/
extern tProgCompleteStatus PROG_VerifySectionCrc(void);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:108:DUMMYELSE12 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('ProgJLR')) and (as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='SBL' or as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='OneLevelBL'))
    or (node:exists(as:modconf('ProgOEMInd')) and (./OemInd/Application_Validity_Algo='Custom') and (./OemInd/Erase_Mode = 'Address'))
    or (node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_Mid')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:111:IF13 osc_PROG main ', $project))"!][!ENDSELECT!]

/*------------------------------{PROG_InvalidateSection}------------------------*/
extern tProgStatus PROG_InvalidateSection(tProgAddressType ulStartAddress, u32 ulEraseLength, tUdsStatus * ErrorCode);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:115:DUMMYELSE14 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgDAG')) or
    (node:exists(as:modconf('ProgOEMInd')) and ((./OemInd/Erase_Mode = 'All') or (./OemInd/Erase_Mode = 'LogicalBlock'))) or
    (node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:118:IF15 osc_PROG main ', $project))"!][!ENDSELECT!]

/*------------------------------{PROG_InvalidateSection_BlockID}----------------*/
extern tProgStatus PROG_InvalidateSection_BlockID(u8 ubBlockId);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:122:DUMMYELSE16 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('ProgJLR'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:124:IF17 osc_PROG main ', $project))"!][!ENDSELECT!]
/*------------------------------{PROG_CustomSetOpenProgSession}---------------------------*/
extern void PROG_CustomSetOpenProgSession(void);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:127:DUMMYELSE18 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('ProgGM'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:129:IF19 osc_PROG main ', $project))"!][!ENDSELECT!]

/*------------------------------{PROG_GetKeyNBIDValue}--------------------------*/
extern u16 PROG_GetKeyNBIDValue(void);


/*------------------------------{PROG_GetNBIDValue}-----------------------------*/
extern u16 PROG_GetNBIDValue(void);


/*------------------------------{PROG_SetKeyNBIDValue}--------------------------*/
extern void PROG_SetKeyNBIDValue(u16 uwKeyNBID);

/*------------------------------{PROG_SetNBIDValue}-----------------------------*/
extern void PROG_SetNBIDValue(u16 uwNBID);
/*------------------------------{PROG_GetSBIFlagValue}-----------------------------*/
extern u8 PROG_GetSBIFlagValue(void);
/*------------------------------{PROG_SetSBIFlagValue}-----------------------------*/
extern void PROG_SetSBIFlagValue(u8 ubSBI);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:148:DUMMYELSE20 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "not(node:exists(as:modconf('ProgVCC'))) and General/Dsc_Prog_Response = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:149:IF21 osc_PROG main ', $project))"!][!ENDSELECT!]
/*--------------------------{PROG_GetSuppressBitFromAppli}--------------------*/
extern u8 PROG_GetSuppressBitFromAppli(void);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:152:DUMMYELSE22 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "General/Erase_Check = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:153:IF23 osc_PROG main ', $project))"!][!ENDSELECT!]
/*------------------------------{PROG_GetEraseStateStatus}----------------------*/
extern void PROG_GetEraseStateStatus(tProgEraseStatus * eEraseStatus);

[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:157:DUMMYELSE24 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "node:exists(as:modconf('ProgGM'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:158:IF25 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CopySBATicket}-----------------------------*/
extern tProgStatus PROG_CopySBATicket(u8 * pubRamBuffer);
extern void Prog_CustomGetAdditionalProgrammingConditionalFlags(u8 * pubFlag);
extern void Prog_CustomGetECUInternalProgrammingFlag(u8 * pubFlag);
extern void Prog_CustomGetProgrammingTolerantConditionsFlag(u8 * pubFlag);
extern void Prog_CustomGetProgrammingConditionsFlag(u8 * pubFlag);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:165:DUMMYELSE26 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "node:exists(as:modconf('Uds'))
    and  ( (node:exists(as:modconf('ProgOEMInd')) and ./OemInd/Application_Validity_Algo='Custom')
    or not(node:exists(as:modconf('ProgOEMInd'))) )"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:168:IF27 osc_PROG main ', $project))"!][!ENDSELECT!]
[!VAR "FINGERPRINT_USE" = "0"!]
    [!LOOP " as:modconf('Uds')/Service_DID/*"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:170:LOOP28 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!IF "Callback = 'PROG_WriteFingerprint'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:171:IF29 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "FINGERPRINT_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:173:DUMMYELSE30 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ENDLOOP!]
    [!IF "$FINGERPRINT_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:175:IF31 osc_PROG main ', $project))"!][!ENDSELECT!]

/*------------------------{PROG_CustomWriteFingerprint}-----------------------------*/
extern tProgStatus PROG_CustomWriteFingerprint(u8 * pubRamBuffer);

/*------------------------{PROG_CustomGetWriteFingerprintStatus}--------------------*/
extern tProgStatus PROG_CustomGetWriteFingerprintStatus(void);
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:182:DUMMYELSE32 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:183:DUMMYELSE33 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_Mid')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:184:IF34 osc_PROG main ', $project))"!][!ENDSELECT!]

/*---------------------------{PROG_CustomStartChecksumCalc}-------------------------*/
extern void PROG_CustomStartChecksumCalc(void);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:188:DUMMYELSE35 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_Mid')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:189:IF36 osc_PROG main ', $project))"!][!ENDSELECT!]

/*---------------------------{PROG_CustomChecksumCalc}------------------------------*/
extern tProgStatus PROG_CustomChecksumCalc(u16* puwCalculatedCks);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:193:DUMMYELSE37 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_Mid')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:194:IF38 osc_PROG main ', $project))"!][!ENDSELECT!]

/*---------------------------{PROG_CustomUpdateChecksumCalc}------------------------*/
extern void PROG_CustomUpdateChecksumCalc(u8* pubData, u32 ulDataSize);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:198:DUMMYELSE39 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_Mid')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:199:IF40 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomSetAppValidity}----------------------------*/
extern void PROG_CustomSetAppValidity(u32 ulAddress, u32 ulEndAddress);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:202:DUMMYELSE41 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "node:exists(as:modconf('ProgVAG'))
    or node:exists(as:modconf('ProgDAG'))
        or node:exists(as:modconf('ProgVCC'))
        or node:exists(as:modconf('ProgFord'))
        or (node:exists(as:modconf('ProgJLR')) and (as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='SBL'
		or as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='OneLevelBL'))
    or (node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High')
    or (node:exists(as:modconf('ProgOEMInd')) and (./OemInd/Application_Validity_Algo='Custom'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:210:IF42 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomSetDownloadVerificationSuccess}----------------------*/
extern tProgStatus PROG_CustomSetDownloadVerificationSuccess(u8 ubLogicalBlockId, u8 ubLogicalSegmentId, tProgBoolean ubCompareSuccess);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:213:DUMMYELSE43 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('ProgVAG')) and General/Expected_Crc_Location = 'Application')
    or (node:exists(as:modconf('ProgOEMInd')) and (./OemInd/Application_Validity_Algo='Custom'))
    or (node:exists(as:modconf('ProgDAG')) and General/Expected_Crc_Location = 'Application')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:216:IF44 osc_PROG main ', $project))"!][!ENDSELECT!]

/*---------------------------{PROG_CustomGetExpectedCrc}----------------------------*/
extern void PROG_CustomGetExpectedCrc(u8 ubLogicalBlockId, u32* pulExpectedCrc);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:220:DUMMYELSE45 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_Mid')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:221:IF46 osc_PROG main ', $project))"!][!ENDSELECT!]

/*---------------------------{PROG_CustomWriteProgStatus}---------------------------*/
extern void PROG_CustomWriteProgStatus(u32 ulProgrammingStatus);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:225:DUMMYELSE47 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!] /* PROG_REQ_PROGRAMMING_STATUS_ENABLE == STD_ON */
[!IF "(node:exists(as:modconf('ProgVAG'))) or (node:exists(as:modconf('ProgDAG'))) or (node:exists(as:modconf('ProgJLR')) and as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL') or (node:exists(as:modconf('ProgFord')) and as:modconf('ProgFord')/General/PROG_FORD_VARIANT='PBL') or (as:modconf('Prog')/General/Transmit_Response_Before_Reset = 'false')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:226:IF48 osc_PROG main ', $project))"!][!ENDSELECT!]

/*---------------------------{PROG_CustomGetResetCause}-----------------------------*/
extern void PROG_CustomGetResetCause(tProgResCause* pubResetCause, tProgBoolean* pubSendResp);

/*---------------------------{PROG_CustomStoreResetCause}---------------------------*/
extern void PROG_CustomStoreResetCause(tProgResCause ubResetCause, tProgBoolean ubSendResp);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:233:DUMMYELSE49 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgDAG'))
    or node:exists(as:modconf('ProgOEMInd')) or node:exists(as:modconf('ProgPSA'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:236:IF50 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "General/Check_Programming_PreConditions = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:237:IF51 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustCheckProgPrecond}----------------------------*/
extern tProgStatus PROG_CustCheckProgPrecond(tUdsStatus * ubDiagStatus);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:240:DUMMYELSE52 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:241:DUMMYELSE53 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "(node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High') or (node:exists(as:modconf('ProgDAG'))) "!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:243:IF54 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "General/Check_Programming_PreConditions = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:244:IF55 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustCheckProgPrecond}----------------------------*/
extern void PROG_CustCheckProgPrecondList(u8 * pubProgrammingConditionNumber, u8 * paubConditionList);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:247:DUMMYELSE56 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:248:DUMMYELSE57 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]


#ifdef NCS_UNITARY_TEST
extern void PROG_RamRead(tProgAddressType uMemAddress, tDataLength ulLength, tDataBufferType PROG_FAR_POINTER paubDataBuffer);
extern void PROG_RamWrite(tProgAddressType uMemAddress, tDataLength ulLength, tDataBufferType PROG_FAR_POINTER paubDataBuffer);
#endif     /* NCS_UNITARY_TEST */
[!IF "(node:exists(as:modconf('ProgVAG')) )
    or (node:exists(as:modconf('ProgDAG')))
    or (node:exists(as:modconf('ProgOEMInd')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:257:IF58 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomWriteCRC}-----------------------------*/
extern void PROG_CustomWriteCRC(u32 ulCrcVal);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:260:DUMMYELSE59 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "DownloadVerification/CVN_Verification = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:262:IF60 osc_PROG main ', $project))"!][!ENDSELECT!]
extern tProgStatus PROG_CustomCvnVerification(u8 ubLogicalBlockId, const u8* paubExpectedCvn);
extern tProgStatus PROG_CustomCvnVerificationStatus(void);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:265:DUMMYELSE61 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "(node:exists(as:modconf('ProgVAG'))
    or (node:exists(as:modconf('ProgDAG')))
    or (node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High')
    or (node:exists(as:modconf('ProgOEMInd'))))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:270:IF62 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomCoherencyCheck}-----------------------------*/
extern tProgStatus PROG_CustomCoherencyCheck(tProgCohChkResult* eCohChkResult);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:273:DUMMYELSE63 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('Uds'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:275:IF64 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!VAR "COHERENCY_PRE_CHECK_USE" = "0"!]
    [!LOOP " as:modconf('Uds')/Routine_Control/*"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:277:LOOP65 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!IF "Callback = 'PROG_CoherencyPreCheck'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:278:IF66 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "COHERENCY_PRE_CHECK_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:280:DUMMYELSE67 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ENDLOOP!]
    [!IF "$COHERENCY_PRE_CHECK_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:282:IF68 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomComputeCoherencyPreCheck}-----------------------------*/
extern tProgCohChkResult PROG_CustomComputeCoherencyPreCheck(u8* paubUdsData, PduLengthType pulLen, tUdsStatus* eUdsStatus);
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:285:DUMMYELSE69 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:286:DUMMYELSE70 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "(node:exists(as:modconf('ProgJLR')) and (as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='SBL' or as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='OneLevelBL'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:288:IF71 osc_PROG main ', $project))"!][!ENDSELECT!]
extern tProgStatus PROG_CustomCompatibilityCheck(void);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:290:DUMMYELSE72 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('ProgGM'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:292:IF73 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "GM/EcuId_Source = 'User_Callback'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:293:IF74 osc_PROG main ', $project))"!][!ENDSELECT!]
extern void PROG_CustomGetEcuId(u8* paubEcuId);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:295:DUMMYELSE75 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:296:DUMMYELSE76 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "(node:exists(as:modconf('ProgVAG'))
    or (node:exists(as:modconf('ProgDAG')))
    or ( (node:exists(as:modconf('ProgOEMInd'))) and ( (as:modconf('Prog')/OemInd/Request_Download_Address_Mode = 'Download by logical block') 
    or (as:modconf('Prog')/OemInd/Request_Download_Address_Mode = 'Download by logical block and segment') ) )
    or ( (node:exists(as:modconf('ProgFCA'))) and (as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High')) )"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:302:IF77 osc_PROG main ', $project))"!][!ENDSELECT!]
extern u16 PROG_CustomGetProgCounter(u8 ubBlockId);

extern tProgStatus PROG_CustomIncrementProgCounter(u8 ubBlockId);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:306:DUMMYELSE78 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('Uds'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:308:IF79 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!VAR "PARTIAL_VERIFY_CRC_USE" = "0"!]
    [!LOOP " as:modconf('Uds')/Routine_Control/*"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:310:LOOP80 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!IF "(Callback = 'PROG_PartialVerificationCrc') or (Callback = 'PROG_LogicalBlockHash')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:311:IF81 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "PARTIAL_VERIFY_CRC_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:313:DUMMYELSE82 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ENDLOOP!]
    [!IF "$PARTIAL_VERIFY_CRC_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:315:IF83 osc_PROG main ', $project))"!][!ENDSELECT!]
extern void PROG_CustomGetPartProgSegList(u8 ubBlockId,u32* aulSegProgSize,u8* ubSegNbr);
extern void PROG_CustomSetPartProgSegList(u8 ubBlockId,u32* aulSegProgSize,u8* ubSegNbr);
extern void PROG_CustomClearPartProgSegList(u8 ubBlockId);
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:319:DUMMYELSE84 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:320:DUMMYELSE85 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('Csm'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:322:IF86 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "(node:exists(as:modconf('ProgGM'))
    or (node:exists(as:modconf('ProgDAG')))
    or (node:exists(as:modconf('ProgVCC')))
    or (node:exists(as:modconf('ProgFord')))
    or (node:exists(as:modconf('ProgJLR')))
    or (node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High')
    or (node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_Mid')
    or (node:exists(as:modconf('ProgVAG')))
    or (node:exists(as:modconf('ProgOEMInd'))))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:331:IF87 osc_PROG main ', $project))"!][!ENDSELECT!]
extern void PROG_CustomGetAsymPublicKey(const u8** paubPublicModulus, u32* pulPublicExponent);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:333:DUMMYELSE88 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:334:DUMMYELSE89 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "(as:modconf('BM')/Security/SecureBoot/SECURE_AUTHENTICATED_BOOT='Authenticated')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:336:IF90 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomInvalidateBootloaderChecksum}-----------------------------*/
extern void PROG_CustomInvalidateBootloaderChecksum(void);

/*---------------------------{PROG_CustomValidateBootloaderChecksum}-----------------------------*/
extern void PROG_CustomValidateBootloaderChecksum(void);

/*---------------------------{PROG_CustomSetBootloaderChecksum}-----------------------------*/
extern void PROG_CustomSetBootloaderChecksum(u8 * pubComputedChecksum);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:345:DUMMYELSE91 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "(as:modconf('BM')/Security/SecureBoot/SECURE_AUTHENTICATED_BOOT ='Authenticated') and
    (as:modconf('BM')/Security/SecureBoot/BOOT_VERIFICATION ='ON')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:348:IF92 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomGetComputedBootloaderChecksum}-----------------------------*/
extern void PROG_CustomGetComputedBootloaderChecksum(u8 * pubComputedChecksum);

/*---------------------------{PROG_CustomIsValidBootloaderChecksum}-----------------------------*/
extern tProgStatus PROG_CustomIsValidBootloaderChecksum(void);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:354:DUMMYELSE93 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

 [!IF "((not((as:modconf('BM')/Security/SecureBoot/SECURE_AUTHENTICATED_BOOT = 'OFF') and (as:modconf('Prog')/Security/Secure_Checksum_computation = 'false')))
         and (node:exists(as:modconf('ProgDAG'))
         or node:exists(as:modconf('ProgJLR'))
         or node:exists(as:modconf('ProgFCA'))
         or node:exists(as:modconf('ProgOEMInd'))))
         or ((as:modconf('Prog')/Security/Secure_Checksum_computation = 'true') and (node:exists(as:modconf('ProgVCC'))) and (as:modconf('ProgVCC')/General/PROG_VCC_VARIANT='SBL'))
         or ((as:modconf('Prog')/Security/Secure_Checksum_computation = 'true') and (node:exists(as:modconf('ProgFord'))) and (as:modconf('ProgFord')/General/PROG_FORD_VARIANT='SBL'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:362:IF94 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "(not(node:exists(as:modconf('BM')/Security/SecureBoot/BMSecureBootWithHsm)) or (as:modconf('BM')/Security/SecureBoot/BMSecureBootWithHsm = 'false'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:363:IF95 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "(node:exists(as:modconf('Prog')/Security/ProgCsmSecureConfigId))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:364:IF96 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "(not(node:exists(as:modconf('CryIf'))) and (contains(as:modconf('Prog')/Security/ProgCsmSecureConfigId, '/Csm/Csm/CsmMacGenerate/') =  'true')) or
    (node:exists(as:modconf('CryIf')) and (node:exists(node:ref(node:ref(as:modconf('Prog')/Security/ProgCsmSecureConfigId)/CsmJobPrimitiveRef)/CsmMacGenerate)) )"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:366:IF97 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomGetMacKey}-----------------------------*/
extern void PROG_CustomGetMacKey(const u8** paubKeyData, u32* pulKeyLength);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:369:DUMMYELSE98 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:370:DUMMYELSE99 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:371:DUMMYELSE100 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
/*---------------------------{PROG_CustomSetApplicationChecksum}-----------------------------*/
extern void PROG_CustomSetApplicationChecksum(u8 * pubComputedChecksum, u16 uwBlockIdentifier);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:374:DUMMYELSE101 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]





[!IF "(node:exists(as:modconf('ProgVAG'))
    or (node:exists(as:modconf('ProgDAG'))))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:381:IF102 osc_PROG main ', $project))"!][!ENDSELECT!]

    [!VAR "UPDATE_TP_PARAM_USED" = "0"!]
    [!IF "node:exists(as:modconf('Uds'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:384:IF103 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!LOOP " as:modconf('Uds')/Service_DID/*"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:385:LOOP104 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!IF "(DID = num:hextoint('0x010B') and (node:exists(as:modconf('ProgDAG')))) or
            (DID = num:hextoint('0x0410') and (node:exists(as:modconf('ProgVAG'))))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:387:IF105 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "UPDATE_TP_PARAM_USED" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:389:DUMMYELSE106 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ENDLOOP!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:391:DUMMYELSE107 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!IF "$UPDATE_TP_PARAM_USED = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:392:IF108 osc_PROG main ', $project))"!][!ENDSELECT!]

extern tProgStatus PROG_CustomGetTpBsValue(u8* ubTpBsValue);
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:395:DUMMYELSE109 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:396:DUMMYELSE110 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "(node:exists(as:modconf('ProgDAG')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:398:IF111 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!VAR "UPDATE_TP_PARAM_USED" = "0"!]
    [!IF "node:exists(as:modconf('Uds'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:400:IF112 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!LOOP " as:modconf('Uds')/Service_DID/*"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:401:LOOP113 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!IF "DID = num:hextoint('0x010B')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:402:IF114 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "UPDATE_TP_PARAM_USED" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:404:DUMMYELSE115 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ENDLOOP!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:406:DUMMYELSE116 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!IF "$UPDATE_TP_PARAM_USED = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:407:IF117 osc_PROG main ', $project))"!][!ENDSELECT!]
extern tProgStatus PROG_CustomGetTpStminValue(u8* ubTpStminValue);
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:409:DUMMYELSE118 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:410:DUMMYELSE119 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "General/Erase_Check = 'First Programming Check'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:412:IF120 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomIsFirstProgramming}-----------------------------*/
extern tProgBoolean PROG_CustomIsFirstProgramming(void);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:415:DUMMYELSE121 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

/*---------------------------{PROG_CustomDownloadNotification}-----------------------------*/
extern tProgStatus PROG_CustomDownloadNotification(u32 ulStartAddress, u32 ulMemorySize);

[!IF "General/Erase_Check = 'Memory Block Erased Check'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:420:IF122 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomGetEraseStatus}-----------------------------*/
extern tProgEraseStatus PROG_CustomGetEraseStatus(u8 ubBlockId);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:423:DUMMYELSE123 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "General/Erase_Check = 'Memory Block Erased Check'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:425:IF124 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomSetEraseStatus}-----------------------------*/
extern tProgStatus PROG_CustomSetEraseStatus(u8 ubBlockId,tProgEraseStatus eEraseStatus);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:428:DUMMYELSE125 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

/*---------------------------{PROG_CustomMemoryAccessNotification}-------------------*/
extern tProgStatus PROG_CustomMemoryAccessNotification
(
    tProgMemType eMemType,
    tOperationType eOperationType,
    tProgAddressType uMemAddress,
    tDataLength ulLength,
    tDataBufferType PROG_FAR_POINTER paubDataBuffer
);

[!VAR "CUSTOM_MEMORY_USE" = "0"!]
[!VAR "CUSTOM_MEMORY_ASYN" = "0"!]
[!LOOP "Segments/*"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:442:LOOP126 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!VAR "Memory_Type" = "node:ref(Memory)/Memory_Type"!]
    [!IF "$Memory_Type = 'CUSTOM'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:444:IF127 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "CUSTOM_MEMORY_USE" = "1"!]
        [!VAR "MEMORY_MODE_CUSTOM_MEM" = "node:ref(Memory)/Memory_Mode"!]
        [!IF "$MEMORY_MODE_CUSTOM_MEM = 'asynchronous'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:447:IF128 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "CUSTOM_MEMORY_ASYN" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:449:DUMMYELSE129 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:450:DUMMYELSE130 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ENDLOOP!]

[!IF "$CUSTOM_MEMORY_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:453:IF131 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomMemoryErase}-------------------*/
extern tProgStatus PROG_CustomMemoryErase
(
    tProgAddressType uMemAddress,
    tDataLength ulLength
);

/*---------------------------{PROG_CustomMemoryWrite}-------------------*/
extern tProgStatus PROG_CustomMemoryWrite
(
    tProgAddressType uMemAddress,
    tDataLength ulLength,
    tDataBufferType PROG_FAR_POINTER paubDataBuffer
);

/*---------------------------{PROG_CustomMemoryRead}-------------------*/
extern tProgStatus PROG_CustomMemoryRead
(
    tProgAddressType uMemAddress,
    tDataLength ulLength,
    tDataBufferType PROG_FAR_POINTER paubDataBuffer
);

[!IF "$CUSTOM_MEMORY_ASYN = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:477:IF132 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomMemGetJobStatus}-------------------*/
extern tProgStatus PROG_CustomMemGetJobStatus(void);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:480:ELSE133 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomGetNextSextorAddr}-------------------*/
extern tProgAddressType PROG_CustomGetNextSectorAddr(tProgAddressType uMemAddress);
[!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:484:DUMMYELSE134 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "General/ResumableReprog = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:486:IF135 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomGetSegmentList}-------------------*/
extern void PROG_CustomGetSegmentList(tSegmentListType * pstSegList);

extern void PROG_CustomStoreSegmentList(tSegmentListType * pstSegList);

extern void PROG_CustomStoreResumeAddress(u8 ubBlockId, u32 ulAddress);

extern u32 PROG_CustomGetResumeAddress(u8 ubBlockId);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:495:DUMMYELSE136 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:497:IF137 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomCheckTargetName}-----------------------------*/
extern tProgStatus PROG_CustomCheckTargetName(u8* pubTargetNameAddress,u8 ubLen);
/*------------------------{end PROG_CustomCheckTargetName}--------------------------*/

/*---------------------------{PROG_CustomCheckRollbackId}-----------------------------*/
extern tProgStatus PROG_CustomCheckRollbackId(u8* pubRollbackIdAddress,u8 ubLen);
/*------------------------{end PROG_CustomCheckRollbackId}--------------------------*/

/*---------------------------{PROG_CustomCheckCompatibilityId}-----------------------------*/
extern tProgStatus PROG_CustomCheckCompatibilityId(u8* pubCompatibilityIdAddress,u8 ubLen);
/*------------------------{end PROG_CustomCheckCompatibilityId}--------------------------*/

/*---------------------------{PROG_CustomCheckUuid}-----------------------------*/
extern tProgStatus PROG_CustomCheckUuid(u8* pubUuidAddress,u8 ubLen);
/*------------------------{end PROG_CustomCheckUuid}--------------------------*/

/*---------------------------{PROG_CustomCheckSigningInfo}-----------------------------*/
extern tProgStatus PROG_CustomCheckSigningInfo(u8* pubSigningInfoAddress,u8 ubLen);
/*------------------------{end PROG_CustomCheckSigningInfo}--------------------------*/
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:517:DUMMYELSE138 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('ProgVCC'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:519:IF139 osc_PROG main ', $project))"!][!ENDSELECT!]
extern tProgStatus Prog_GetEssValidityStatus(void);
extern tProgStatus Prog_GetEssLogicalBlockNbr(u8* pubBlockNbr);
extern tProgStatus Prog_GetEssLogicalBlockId(u8 ubBlockIndex, u16* pulBlockIdent);
extern tProgStatus Prog_GetEssLogicalBlockStartAddr(u8 ubBlockIndex, u32* pulBlockAddr);
extern tProgStatus Prog_GetEssLogicalBlockLength(u8 ubBlockIndex, u32* pulBlockLength);
extern tProgStatus Prog_GetEssLogicalBlockVerifTable(u8 ubBlockIndex, u32* pulVBTAddress);
extern tProgStatus Prog_GetEss_VBTLength(u32* pulVBTLength);
extern tProgStatus Prog_GetAPPL_VBTLength(u8 ubBlockIndex, u32* pulVBTLength);
extern tProgStatus Prog_GetEssVerifTable(u32* pulVBTAddress);
extern tProgStatus PROG_InvalidateBlock(u8 ubBlockId);
extern void Prog_GetEssApplicationStartAddress(u32* ulApplicationStartAddress);
extern void Prog_GetEssStartAddr(u32* ulEssStartAddress);
extern void Prog_GetEssLength(u32* ulEssLength);
extern boolean Prog_CustomIsProdKeyPresent(void);
extern void Prog_CustomReadKeyChecksum(u8* aubKeyChecksum);
extern void Prog_CustomWriteKey(u32 ulExponent, u8* aubModulus, u8* aubKeyChecksum);
extern tProgStatus PROG_CustomCheckCertificateVerification(void);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:537:DUMMYELSE140 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('ProgFord'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:539:IF141 osc_PROG main ', $project))"!][!ENDSELECT!]
extern tProgStatus Prog_GetLogicalBlockVerifStructure(u8 ubBlockIndex, u32* pulVSAddress);
extern tProgStatus Prog_GetLogicalBlockSignature(u8 ubBlockIndex, u32* pulSignatureAddress);
extern tProgStatus PROG_InvalidateBlock(u8 ubBlockId);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:543:DUMMYELSE142 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "as:modconf('BM')/Security/SecureBoot/BMSecureBootWithHsm = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:545:IF143 osc_PROG main ', $project))"!][!ENDSELECT!]
 extern tProgStatus PROG_CustomHsmUpdateInitBlock(u16 uwBlockId, u8 *pubMemoryAddress, u32 ulMemorySize);
 extern tProgStatus PROG_CustomHsmUpdateBlock(u16 uwBlockId, u8 *pubMemoryAddress, u32 ulMemorySize);
extern void        PROG_CustomHsmUpdateFinish(tProgStatus ubJobResult);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:549:DUMMYELSE144 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "(node:exists(as:modconf('ProgGM')) and (as:modconf('Prog')/Segments/*/Partition_Type='PROG_HSM_PARTITION'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:551:IF145 osc_PROG main ', $project))"!][!ENDSELECT!]
extern tProgStatus PROG_HSMRequestUpdate(void);
extern tProgStatus Prog_HSMTransferData(u8* paubHsmBuffer,PduLengthType ulHsmBufferLength, u16* uwHsmPEC);
extern tProgPECError PROG_HSMLastDataReceived(void);

[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:556:DUMMYELSE146 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "General/Dual_Memory_Bank_Used = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:558:IF147 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomCalcInactiveBankWriteAddr}-----------------------------*/
extern u32 PROG_CustomCalcInactiveBankWriteAddr(u32 ulAddr);
/*------------------------{end PROG_CustomCalcInactiveBankWriteAddr}--------------------------*/

/*---------------------------{PROG_CustomCalcInactiveBankReadAddr}-----------------------------*/
extern u32 PROG_CustomCalcInactiveBankReadAddr(u32 ulAddr);
/*------------------------{end PROG_CustomCalcInactiveBankReadAddr}--------------------------*/
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:566:DUMMYELSE148 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_Mid'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:568:IF149 osc_PROG main ', $project))"!][!ENDSELECT!]
[!VAR "SIGNATUREVERIFCATIONENABLED"="'false'"!]
[!LOOP "Segments/*"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:570:LOOP150 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!IF "SignatureVerification = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:571:IF151 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "SIGNATUREVERIFCATIONENABLED"="'true'"!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:573:DUMMYELSE152 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ENDLOOP!]
[!IF "(not((as:modconf('BM')/Security/SecureBoot/SECURE_AUTHENTICATED_BOOT = 'OFF') and (as:modconf('Prog')/Security/Secure_Checksum_computation = 'false'))) or ($SIGNATUREVERIFCATIONENABLED = 'true')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:575:IF153 osc_PROG main ', $project))"!][!ENDSELECT!]
extern void PROG_CustomGetVerificationParameters(u32 * m_ulStartAddress, u32 * m_ulEndAddress ,u32 * m_ubSignatureStartAddress);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:577:DUMMYELSE154 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:578:DUMMYELSE155 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
#if (PROG_CSM_DECRYPTION_ENABLE == STD_ON)
extern void PROG_CustomGetSymDecryptionKey(const u8** pubKey, u32 * pulKeyLength);
extern void PROG_CustomDecryptGetInitVector(const u8** pubInitVect, u32 * pulInitVectLength);
#endif /* (PROG_CSM_DECRYPTION_ENABLE == STD_ON) */

[!IF "(node:exists(as:modconf('ProgJLR')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:584:IF156 osc_PROG main ', $project))"!][!ENDSELECT!]
extern tUdsStatus PROG_CustomUpdateCertAsymPublicKey(u16 *puwLen, u8 *aubUdsData);
extern tProgStatus PROG_CustomVDStable_update(tVDSlayout * pstVDSlayout, u8 * pubSegmentId, u8 ubVDSaccesstype);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:587:DUMMYELSE157 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "as:modconf('Prog')/Segments/*/Partition_Type = 'PROG_BLU_APP_PARTITION' 
   or as:modconf('Prog')/Segments/*/Partition_Type = 'PROG_BLU_CAL_PARTITION'
   or as:modconf('Prog')/Segments/*/Partition_Type = 'PROG_BLU_PARTITION'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:591:IF158 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomSetBLUDownloadInProgress}----------------------------*/
extern void PROG_CustomSetBLUDownloadInProgress(tProgBoolean ubBLUDownload);
/*---------------------------{PROG_CustomIsBLUDownloadInProgress}----------------------------*/
extern tProgBoolean PROG_CustomIsBLUDownloadInProgress(void);
/*---------------------------{PROG_CustomIsBLUPatternPresent}----------------------------*/
extern tProgBoolean PROG_CustomIsBLUPatternPresent(u8 ubLogicalBlockId, u8 ubLogicalSegmentId);
[!IF "node:exists(as:modconf('ProgOEMInd'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:598:IF159 osc_PROG main ', $project))"!][!ENDSELECT!]
/*---------------------------{PROG_CustomSetBLUVerificationSuccess}----------------------------*/
extern tProgStatus PROG_CustomSetBLUVerificationSuccess(tProgBoolean ubCompareSuccess);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:601:DUMMYELSE160 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:602:DUMMYELSE161 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('ProgPSA'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:604:IF162 osc_PROG main ', $project))"!][!ENDSELECT!]
/*--------------------------{PROG_CustomSetECUStatus}-----------------------------*/
extern void PROG_CustomSetECUStatus(u8 ubEcuStatusValue);

/*--------------------------{PROG_CustomGetECUStatus}-----------------------------*/
extern void PROG_CustomGetECUStatus(u8 *ubEcuStatus);

/*--------------------------{PROG_CustomWriteKeyAppli}-----------------------------*/
extern tProgStatus PROG_CustomWriteKeyAppli(u8 * pubData, u8 ubDataLength);

/*--------------------------{PROG_CustomWriteZI}-----------------------------*/
extern tProgStatus PROG_CustomWriteZI(u8 * pubData, u8 ubDataLength);

/*--------------------------{PROG_CustomGetWriteJobResult}-----------------------------*/
extern tProgStatus PROG_CustomGetWriteJobResult(u8 ubLogicalMarker);

/*--------------------------{PROG_CustomCheckZIAvailableSpace}-----------------------------*/
extern tProgStatus PROG_CustomCheckZIAvailableSpace(void);

/*--------------------------{PROG_CustomUpdateLogSaveMarkingByte}-----------------------------*/
extern tProgStatus PROG_CustomUpdateLogSaveMarkingByte(u8 ubNewLogSaveMarkingByte);

/*--------------------------{PROG_CustomReadKeyAppli}-----------------------------*/
extern tProgStatus PROG_CustomReadKeyAppli(u16 * aubKeyAppli);

/*--------------------------{PROG_CustomStoreDownloadedSegmentSize}-----------------------------*/
extern void PROG_CustomStoreDownloadedSegmentSize(u32 * pulSegSize, u8 ubSegmentId);

/*--------------------------{PROG_CustomGetDownloadedSegmentSize}-----------------------------*/
extern void PROG_CustomGetDownloadedSegmentSize(u32 * pulSegSize, u8 ubSegmentId);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:634:DUMMYELSE163 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
 [!IF "((node:exists(Security/ProgCsmReferences/SignatureVerification/Allow2CustomCsmStartPreprocess)) and (node:value(Security/ProgCsmReferences/SignatureVerification/Allow2CustomCsmStartPreprocess) = 'true')) or
((node:exists(Security/Allow2CustomCsmStartPreprocess)) and (node:value(Security/Allow2CustomCsmStartPreprocess) = 'true')) or
((node:exists(Decryption/Allow2CustomCsmStartPreprocess)) and (node:value(Decryption/Allow2CustomCsmStartPreprocess) = 'true')) or
((node:exists(GM/ProgCsmReferences/Allow2CustomCsmStartPreprocess)) and (node:value(Allow2CustomCsmStartPreprocess) = 'true'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:638:IF164 osc_PROG main ', $project))"!][!ENDSELECT!]
extern Csm_ReturnType PROG_CustomCsmStrtPreproc(const u8** ubKeyPtr, u32 ulCsmJobId);
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cbk.h:640:DUMMYELSE165 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
#endif     /* PROG_CBK_H */
