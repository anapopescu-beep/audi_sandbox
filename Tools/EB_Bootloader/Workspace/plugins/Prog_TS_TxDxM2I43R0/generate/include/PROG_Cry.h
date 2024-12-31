#ifndef PROG_CRY_H
#define PROG_CRY_H

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
/*%%   _____________________________   %%  \file PROG_Cry.h                      */
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
/* Copyright 2010 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*===============================================================================*/
[!AUTOSPACING!]
#if (PROG_CRY_PRESENT == STD_ON)
#include "Csm.h"

/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */

/*-------------------------------------------------------------------------------*/
/* - Public Function Prototypes                                                  */
typedef u8 tProgCryState;
#define PROG_IDLE                          0x00U
#define PROG_SIGNATURE_CHECK_START         0x01U
#define PROG_SIGNATURE_CHECK_UPDATE        0x02U
#define PROG_SIGNATURE_CHECK_UPDATE_END    0x03U
#define PROG_SIGNATURE_CHECK_FINISH        0x04U
#define PROG_HASH_START                    0x05U
#define PROG_HASH_START_END                0x06U
#define PROG_HASH_UPDATE                   0x07U
#define PROG_HASH_END                      0x08U
#define PROG_HASH_FINISH                   0x09U
#define PROG_SIGNATURE_CHECK_START_END     0x0AU
#define PROG_MAC_GENERATE_START            0x0BU
#define PROG_MAC_GENERATE_START_END        0x0CU
#define PROG_MAC_GENERATE_UPDATE           0x0DU
#define PROG_MAC_GENERATE_UPDATE_END       0x0EU
#define PROG_MAC_GENERATE_FINISH           0x0FU
#define PROG_CSM_JOBCANCEL_INPROGRESS      0x10U
#define PROG_SIGNATURE_CHECK_STREAMSTART   0x11U
#define PROG_SIGNATURE_CHECK_STREAMSTART_DONE   0x91U
[!IF "node:exists(as:modconf('CryIf'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:60:IF1 osc_PROG main ', $project))"!][!ENDSELECT!]
/* Macros needed when Csm ASR v4.3 or higher stack is used.
 * The values represented by the macros below are generated
 * as a result of the bitwise operations performed during the
 * Prog-Crypto job execution */
#define PROG_SIGNATURE_CHECK_START_DONE    0x81U
#define PROG_SIGNATURE_CHECK_UPDATE_DONE   0x82U
#define PROG_SIGNATURE_CHECK_FINISH_DONE   0x84U
#define PROG_SIGNATURE_CHECK_FINISH_TXCONF 0x44U
#define PROG_HASH_START_DONE               0x85U
#define PROG_HASH_UPDATE_DONE              0x87U
#define PROG_HASH_FINISH_DONE              0x89U
#define PROG_HASH_FINISH_TXCONF            0x49U
#define PROG_MAC_GENERATE_START_DONE       0x8BU
#define PROG_MAC_GENERATE_UPDATE_DONE      0x8DU
#define PROG_MAC_GENERATE_FINISH_DONE      0x8FU
#define PROG_CSM_JOBCANCEL_DONE            0x90U
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:77:DUMMYELSE2 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
/* Define the structure of a public key used for signature verification */
typedef struct
{
    const u8* pubKeyModulus;
    uint32 ulKeyModulusSize;
    const u8* pubKeyExponent;
    uint32 ulKeyExponentSize;
}tKeyStructure;

[!IF "node:exists(as:modconf('Csm'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:87:IF3 osc_PROG main ', $project))"!][!ENDSELECT!]

[!VAR "SIGNATUREVERIFCATIONENABLED"="'false'"!]
[!IF "(node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_Mid')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:90:IF4 osc_PROG main ', $project))"!][!ENDSELECT!]
  [!VAR "SEGMENT_MAX"="num:dectoint(count(Segments/*))"!]
  [!FOR "SEGMENT_IDX" = "1" TO "$SEGMENT_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:92:FOR5 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!IF "Segments/*[number($SEGMENT_IDX)]/SignatureVerification = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:93:IF6 osc_PROG main ', $project))"!][!ENDSELECT!]
      [!VAR "SIGNATUREVERIFCATIONENABLED"="'true'"!]
      [!VAR "SEGMENT_IDX"="$SEGMENT_MAX"!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:96:DUMMYELSE7 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
  [!ENDFOR!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:98:DUMMYELSE8 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('ProgGM'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:100:IF9 osc_PROG main ', $project))"!][!ENDSELECT!]
/* define the ID of each configuration */
#define PROG_CSM_SIG_VERIFY_ID            CSM_INDEX([!"name(as:ref(as:modconf('Prog')/GM/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId))"!])
#define PROG_CSM_HASH_FOR_SIGNATURE_ID    CSM_INDEX([!"name(as:ref(as:modconf('Prog')/GM/ProgCsmReferences/HashVerification/ProgCsmHashConfigId))"!])
[!ELSEIF "node:exists(as:modconf('ProgVCC'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:104:ELSEIF10 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CSM_SIG_VERIFY_ID            CSM_INDEX([!"name(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId))"!])
#define PROG_CSM_HASH_ID                  CSM_INDEX([!"name(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/HashVerification/ProgCsmHashConfigId))"!])
[!ELSEIF "node:exists(as:modconf('ProgFord'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:107:ELSEIF11 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CSM_SIG_VERIFY_ID            CSM_INDEX([!"name(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId))"!])
#define PROG_CSM_HASH_ID                  CSM_INDEX([!"name(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/HashVerification/ProgCsmHashConfigId))"!])
[!ELSEIF "node:exists(as:modconf('ProgJLR'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:110:ELSEIF12 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CSM_SIG_VERIFY_ID            CSM_INDEX([!"name(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId))"!])
#define PROG_CSM_HASH_FOR_SIGNATURE_ID    CSM_INDEX([!"name(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/HashVerification/ProgCsmHashConfigId))"!])
[!ELSEIF "((node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_Mid') and ($SIGNATUREVERIFCATIONENABLED = 'true'))
       or  (node:exists(as:modconf('ProgOEMInd')) and (OemInd/Checksum_Algo = 'Signature'))
       or ((node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High'))
       or   node:exists(as:modconf('ProgVAG'))
       or   node:exists(as:modconf('ProgDAG'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:117:ELSEIF13 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CSM_SIG_VERIFY_ID            CSM_INDEX([!"name(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId))"!])
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:119:DUMMYELSE14 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "node:exists(as:modconf('ProgDAG')) or (node:exists(as:modconf('ProgOEMInd')) and (OemInd/Checksum_Algo = 'Hash256' or OemInd/Checksum_Algo = 'Hash512')) or (node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:121:IF15 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CSM_HASH_FOR_SIGNATURE_ID    CSM_INDEX([!"name(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/HashVerification/ProgCsmHashConfigId))"!])
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:123:DUMMYELSE16 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:125:DUMMYELSE17 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

/* Define the size of the modulus and exponent used for signature verification */
#define PROG_MODULUS_SIZE                 256U
#define PROG_EXPONENT_SIZE                3U

[!IF "Decryption/Enable_Csm_Decryption = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:131:IF18 osc_PROG main ', $project))"!][!ENDSELECT!]
/* Encryption-Decryption state */
extern tProgCryState m_eEncryptDecryptState;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cry.h:134:DUMMYELSE19 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
/*                                                                               */
/*-------------------------------------------------------------------------------*/

#endif /* (PROG_CRY_PRESENT == STD_ON) */
#endif      /* PROG_CRY_H */
