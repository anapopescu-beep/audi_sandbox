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
/*%%   _____________________________   %%  \file PROG_Cfg.h                      */
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
#ifndef PROG_CFG_H
#define PROG_CFG_H

/* to support ASR 4.3 CSM-Demo wrapper for the BL */
 [!IF "node:exists(as:modconf('CryIf'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:31:IF1 osc_PROG main ', $project))"!][!ENDSELECT!]
 /* Prog table Index of the jobs configured */
 [!VAR "ProgCsmJobIndex" = "0"!]
 [!IF "(node:exists(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:34:IF2 osc_PROG main ', $project))"!][!ENDSELECT!]
[!WS "0"!]#define PROG_CSMSIGNATUREJOBINDEX[!WS "23"!][!"num:dectoint(number($ProgCsmJobIndex))"!]U
[!WS "0"!]#define PROG_CSMTABID_[!"name(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId))"!][!WS "15"!][!"num:dectoint(number($ProgCsmJobIndex))"!]U
 [!VAR "ProgCsmJobIndex"= "num:dectoint(number($ProgCsmJobIndex + 1))"!]
  [!IF "(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/Allow2SetCryptoKey) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:38:IF3 osc_PROG main ', $project))"!][!ENDSELECT!]
     [!//The position of the key element in the crypto driver shall be fixed(default index) and shall be double-checked by the integrator, especially when using more than 1 key element ID for a single key type!]
	 [!VAR "KEYELEPOSNUM"="1"!]
/*Signature Verification Key Parameters*/
#define PROG_CSM_SIGN_KEYID[!WS "29"!][!"node:value(as:ref(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId)/CsmJobKeyRef)/CsmKeyId)"!]U
#define PROG_CRYPTO_SIGN_KEYELEID[!WS "23"!][!"(as:ref(as:ref(as:ref(as:ref(as:ref(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId)/CsmJobKeyRef)/CsmKeyRef)/CryIfKeyRef)/CryptoKeyTypeRef)/CryptoKeyElementRef/*[number($KEYELEPOSNUM)])/CryptoKeyElementId)"!]U
#define PROG_CRYPTO_SIGN_KEYSIZE[!WS "24"!][!"(as:ref(as:ref(as:ref(as:ref(as:ref(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId)/CsmJobKeyRef)/CsmKeyRef)/CryIfKeyRef)/CryptoKeyTypeRef)/CryptoKeyElementRef/*[number($KEYELEPOSNUM)])/CryptoKeyElementSize)"!]U
   [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:45:DUMMYELSE4 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:46:DUMMYELSE5 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('Prog')/Security/ProgCsmReferences/HashVerification/ProgCsmHashConfigId))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:47:IF6 osc_PROG main ', $project))"!][!ENDSELECT!]
[!WS "0"!]#define PROG_CSMHASHJOBINDEX[!WS "24"!][!"num:dectoint(number($ProgCsmJobIndex))"!]U
[!WS "0"!]#define PROG_CSMTABID_[!"name(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/HashVerification/ProgCsmHashConfigId))"!][!WS "23"!][!"num:dectoint(number($ProgCsmJobIndex))"!]U
 [!VAR "ProgCsmJobIndex" = "$ProgCsmJobIndex + 1"!]
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:51:DUMMYELSE7 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('Prog')/Security/ProgCsmSecureConfigId))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:52:IF8 osc_PROG main ', $project))"!][!ENDSELECT!]
[!WS "0"!]#define PROG_CSMSECUREJOBINDEX[!WS "22"!][!"num:dectoint(number($ProgCsmJobIndex))"!]U
[!WS "0"!]#define PROG_CSMTABID_[!"name(as:ref(as:modconf('Prog')/Security/ProgCsmSecureConfigId))"!][!WS "23"!][!"num:dectoint(number($ProgCsmJobIndex))"!]U
 [!VAR "ProgCsmJobIndex" = "$ProgCsmJobIndex + 1"!]
 	 [!IF "(as:modconf('Prog')/Security/Allow2SetCryptoKey) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:56:IF9 osc_PROG main ', $project))"!][!ENDSELECT!]
/* Secure Checksum Key Parameters */
	     [!//The position of the key element in the crypto driver shall be fixed(default index) and shall be double-checked by the integrator, especially when using more than 1 key element ID for a single key type!]
[!VAR "KEYELEPOSNUM"="1"!]
#define PROG_CSM_SECURE_KEYID[!WS "18"!][!"node:value(as:ref(as:ref(as:modconf('Prog')/Security/ProgCsmSecureConfigId)/CsmJobKeyRef)/CsmKeyId)"!]U
#define PROG_CRYPTO_SECURE_KEYELEID[!WS "13"!][!"(as:ref(as:ref(as:ref(as:ref(as:ref(as:ref(as:modconf('Prog')/Security/ProgCsmSecureConfigId)/CsmJobKeyRef)/CsmKeyRef)/CryIfKeyRef)/CryptoKeyTypeRef)/CryptoKeyElementRef/*[number($KEYELEPOSNUM)])/CryptoKeyElementId)"!]U
#define PROG_CRYPTO_SECURE_KEYSIZE[!WS "15"!][!"(as:ref(as:ref(as:ref(as:ref(as:ref(as:ref(as:modconf('Prog')/Security/ProgCsmSecureConfigId)/CsmJobKeyRef)/CsmKeyRef)/CryIfKeyRef)/CryptoKeyTypeRef)/CryptoKeyElementRef/*[number($KEYELEPOSNUM)])/CryptoKeyElementSize)"!]U
     [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:63:DUMMYELSE10 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:64:DUMMYELSE11 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(node:exists(as:modconf('Prog')/Decryption/ProgCsmDecryptionConfigId))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:65:IF12 osc_PROG main ', $project))"!][!ENDSELECT!]
[!WS "0"!]#define PROG_CSMDECRYPTIONJOBINDEX[!WS "22"!][!"num:dectoint(number($ProgCsmJobIndex))"!]U
[!WS "0"!]#define PROG_CSMTABID_[!"name(as:ref(as:modconf('Prog')/Decryption/ProgCsmDecryptionConfigId))"!][!WS "22"!][!"num:dectoint(number($ProgCsmJobIndex))"!]U
[!VAR "ProgCsmJobIndex" = "$ProgCsmJobIndex + 1"!]

[!IF "((as:modconf('Prog')/Decryption/Allow2SetCryptoKey) = 'true') or ((as:modconf('Prog')/Decryption/Allow2SetIV) = 'true')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:70:IF13 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CSM_DECRYPTION_KEYID[!WS "23"!][!"node:value(as:ref(as:ref(as:modconf('Prog')/Decryption/ProgCsmDecryptionConfigId)/CsmJobKeyRef)/CsmKeyId)"!]U
/* The position of the key element in the crypto driver table shall be fixed(default index) as per defined in the userguide and shall be double-checked 
 * by the integrator, especially when using more than 1 key element ID for a single key type (eg.: IV key and Cipher Key for Decryption using AES-CBC)*/
        [!IF "(as:modconf('Prog')/Decryption/Allow2SetCryptoKey) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:74:IF14 osc_PROG main ', $project))"!][!ENDSELECT!]
[!VAR "KEYELEPOSNUM"="2"!]
/*  Decryption Key shall be configured at the 2nd positon in the Crypto config table CryptoKeyType(CryptoKeyType_CIPHER) */
#define PROG_CRYPTO_DECRYPTION_KEYELEID[!WS "17"!][!"(as:ref(as:ref(as:ref(as:ref(as:ref(as:ref(as:modconf('Prog')/Decryption/ProgCsmDecryptionConfigId)/CsmJobKeyRef)/CsmKeyRef)/CryIfKeyRef)/CryptoKeyTypeRef)/CryptoKeyElementRef/*[number($KEYELEPOSNUM)])/CryptoKeyElementId)"!]U
#define PROG_CRYPTO_DECRYPTION_KEYSIZE[!WS "18"!][!"(as:ref(as:ref(as:ref(as:ref(as:ref(as:ref(as:modconf('Prog')/Decryption/ProgCsmDecryptionConfigId)/CsmJobKeyRef)/CsmKeyRef)/CryIfKeyRef)/CryptoKeyTypeRef)/CryptoKeyElementRef/*[number($KEYELEPOSNUM)])/CryptoKeyElementSize)"!]U
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:79:DUMMYELSE15 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(as:modconf('Prog')/Decryption/Allow2SetIV) = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:80:IF16 osc_PROG main ', $project))"!][!ENDSELECT!]
[!VAR "KEYELEPOSNUM"="1"!]
/* Decryption IV shall be configured at the 1st positon in the Crypto config table CryptoKeyType(CryptoKeyType_CIPHER) */
#define PROG_CRYPTO_DECRYPTION_IV_ELEID[!WS "17"!][!"(as:ref(as:ref(as:ref(as:ref(as:ref(as:ref(as:modconf('Prog')/Decryption/ProgCsmDecryptionConfigId)/CsmJobKeyRef)/CsmKeyRef)/CryIfKeyRef)/CryptoKeyTypeRef)/CryptoKeyElementRef/*[number($KEYELEPOSNUM)])/CryptoKeyElementId)"!]U
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:84:DUMMYELSE17 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:85:DUMMYELSE18 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:86:DUMMYELSE19 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!WS "0"!]#define PROG_CSM_NUMCONF_JOBS[!WS "27"!][!"num:dectoint($ProgCsmJobIndex)"!]U
[!IF "num:dectoint($ProgCsmJobIndex) > 0"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:88:IF20 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CSMASR43_USED                              STD_ON
#define CSM_INDEX(job_name)                             PROG_CSMTABID_##job_name
#define PROG_CSM_ALLJOBS_COUNT[!WS "26"!][!"num:i(count(as:modconf('Csm')/CsmJobs/CsmJob/*))"!]U
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:92:ELSE21 osc_PROG main ', $project))"!][!ENDSELECT!]
/* No Csm Jobs configured for the Prog module */
#define PROG_CSMASR43_USED                              STD_OFF
#define CSM_INDEX(job_name)                             0U
 [!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:97:ELSE22 osc_PROG main ', $project))"!][!ENDSELECT!]
/* ASR 4.3 Crypto stack is absent */
#define PROG_CSMASR43_USED                              STD_OFF
#define CSM_INDEX(job_name)                             job_name
[!ENDIF!]
[!IF "((node:exists(Security/ProgCsmReferences/SignatureVerification/Allow2SetCryptoKey)) and (node:value(Security/ProgCsmReferences/SignatureVerification/Allow2SetCryptoKey) = 'true')) or
 ((node:exists(Security/Allow2SetCryptoKey)) and (node:value(Security/Allow2SetCryptoKey) = 'true')) or
 ((node:exists(GM/ProgCsmReferences/SignatureVerification/Allow2SetCryptoKey)) and (node:value(GM/ProgCsmReferences/SignatureVerification/Allow2SetCryptoKey) = 'true')) or
 ((node:exists(Decryption/Allow2SetCryptoKey)) and (node:value(Decryption/Allow2SetCryptoKey) = 'true')) "!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:105:IF23 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CSM_SETKEY_ENABLED                         STD_ON
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:107:ELSE24 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CSM_SETKEY_ENABLED                         STD_OFF
   [!ENDIF!]
[!IF "((node:exists(Security/ProgCsmReferences/SignatureVerification/Allow2Cancel_OngoingJobs)) and (node:value(Security/ProgCsmReferences/SignatureVerification/Allow2Cancel_OngoingJobs) = 'true')) or
 ((node:exists(Security/Allow2Cancel_OngoingJobs)) and (node:value(Security/Allow2Cancel_OngoingJobs) = 'true')) or
 ((node:exists(Security/ProgCsmReferences/HashVerification/Allow2Cancel_OngoingJobs)) and (node:value(Security/ProgCsmReferences/HashVerification/Allow2Cancel_OngoingJobs) = 'true')) or
 ((node:exists(Decryption/Allow2Cancel_OngoingJobs)) and (node:value(Decryption/Allow2Cancel_OngoingJobs) = 'true')) or
 ((node:exists(GM/ProgCsmReferences/SignatureVerification/Allow2Cancel_OngoingJobs)) and (node:value(GM/ProgCsmReferences/SignatureVerification/Allow2Cancel_OngoingJobs) = 'true')) or
 ((node:exists(GM/ProgCsmReferences/HashVerification/Allow2Cancel_OngoingJobs)) and (node:value(GM/ProgCsmReferences/HashVerification/Allow2Cancel_OngoingJobs) = 'true'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:115:IF25 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CSM_CANCELJOB_ENABLED                      STD_ON
  [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:117:ELSE26 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CSM_CANCELJOB_ENABLED                      STD_OFF
[!ENDIF!]

[!IF "((node:exists(Security/ProgCsmReferences/SignatureVerification/Allow2CustomCsmStartPreprocess)) and (node:value(Security/ProgCsmReferences/SignatureVerification/Allow2CustomCsmStartPreprocess) = 'true')) or
 ((node:exists(Security/Allow2CustomCsmStartPreprocess)) and (node:value(Security/Allow2CustomCsmStartPreprocess) = 'true')) or
 ((node:exists(Decryption/Allow2CustomCsmStartPreprocess)) and (node:value(Decryption/Allow2CustomCsmStartPreprocess) = 'true')) or
 ((node:exists(GM/ProgCsmReferences/SignatureVerification/Allow2CustomCsmStartPreprocess)) and (node:value(GM/ProgCsmReferences/SignatureVerification/Allow2CustomCsmStartPreprocess) = 'true'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:124:IF27 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CUSTOM_CSMSTARTPREPROCESS_ENABLED          STD_ON
  [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:126:ELSE28 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CUSTOM_CSMSTARTPREPROCESS_ENABLED          STD_OFF
   [!ENDIF!]

[!IF " ((node:exists(Security/ProgCsmReferences/HashVerification/HashFinSendFRP)) and (node:value(Security/ProgCsmReferences/HashVerification/HashFinSendFRP) = 'true')) or
 ((node:exists(GM/ProgCsmReferences/HashVerification/HashFinSendFRP)) and (node:value(GM/ProgCsmReferences/HashVerification/HashFinSendFRP) = 'true'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:131:IF29 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_HASHFIN_SENDFRP                            STD_ON
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:133:ELSE30 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_HASHFIN_SENDFRP                            STD_OFF
[!ENDIF!]
[!IF " ((node:exists(Security/ProgCsmReferences/SignatureVerification/SignFinSendFRP)) and (node:value(Security/ProgCsmReferences/SignatureVerification/SignFinSendFRP) = 'true')) or
  ((node:exists(GM/ProgCsmReferences/SignatureVerification/SignFinSendFRP)) and (node:value(GM/ProgCsmReferences/SignatureVerification/SignFinSendFRP) = 'true'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:137:IF31 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SIGNFIN_SENDFRP                            STD_ON
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:139:ELSE32 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SIGNFIN_SENDFRP                            STD_OFF
[!ENDIF!]
[!IF " ((node:exists(Security/ProgCsmReferences/SignatureVerification/AllowStreamStart)) and (node:value(Security/ProgCsmReferences/SignatureVerification/AllowStreamStart) = 'true')) or
  ((node:exists(GM/ProgCsmReferences/SignatureVerification/AllowStreamStart)) and (node:value(GM/ProgCsmReferences/SignatureVerification/AllowStreamStart) = 'true'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:143:IF33 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_STREAMSTART_ENABLE                         STD_ON
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:145:ELSE34 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_STREAMSTART_ENABLE                         STD_OFF
[!ENDIF!]

[!IF "(node:exists(as:modconf('ReProgMemM')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:149:IF35 osc_PROG main ', $project))"!][!ENDSELECT!]
[!VAR "MEMORY_MAX"="num:dectoint(count(as:modconf('ReProgMemM')/MemoryConfig/Memory/*))"!]
#define PROG_REPROGMEMM_ENABLED        STD_ON
#define PROG_FLASHWRAPPER_ENABLED      STD_OFF
[!ELSEIF "node:exists(as:modconf('Flash')) or (node:exists(as:modconf('ProgFord')) and as:modconf('ProgFord')/General/PROG_FORD_VARIANT='PBL') or (node:exists(as:modconf('ProgJLR')) and as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL') or (node:exists(as:modconf('ProgVCC')) and as:modconf('ProgVCC')/General/PROG_VCC_VARIANT='PBL')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:153:ELSEIF36 osc_PROG main ', $project))"!][!ENDSELECT!]
[!VAR "MEMORY_MAX"="num:dectoint(count(Memory/*))"!]
#define PROG_FLASHWRAPPER_ENABLED      STD_ON
#define PROG_REPROGMEMM_ENABLED        STD_OFF
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:157:DUMMYELSE37 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!VAR "SEGMENT_MAX"="num:dectoint(count(Segments/*))"!]

#define PROG_IMPL_0                                     0U
#define PROG_IMPL_1                                     1U
#define PROG_IMPL_2                                     2U
#define PROG_IMPL_3                                     3U
#define PROG_IMPL_4                                     4U
#define PROG_IMPL_5                                     5U
#define PROG_IMPL_10                                    10U
#define PROG_IMPL_11                                    11U
#define PROG_IMPL_20                                    20U
#define PROG_IMPL_30                                    30U
#define PROG_IMPL_31                                    31U
#define PROG_IMPL_40                                    40U
#define PROG_IMPL_50                                    50U
#define PROG_IMPL_60                                    60U
#define PROG_IMPL_80                                    80U
#define PROG_IMPL_90                                    90U
#define PROG_IMPL_91                                    91U


#define PROG_MSG_BYTE_INDEX(x)                          (u8) (x - PROG_RESPONSE_PARAMETERS_OFFSET)


/* Feature default configuration */
#define PROG_ERASE_ALFI                                 STD_OFF

/* Default compression algo value */
#define PROG_DFI_COMPRESSED_VAL                         [!"(num:inttohex(General/Compression_Algorithm))"!]0U

/* Default encryption algo value */
#define PROG_DFI_ENCRYPTED_VAL                          [!"(num:inttohex(Decryption/Decryption_Algorithm))"!]U

/* Default compression and encryption algo value */
#define PROG_DFI_COMPRESSED_ENCRYPTED_VAL               0x[!"substring(num:inttohex(General/Compression_Algorithm),3,1)"!][!"substring(num:inttohex(Decryption/Decryption_Algorithm),3,1)"!]U

#define PROG_NODECRYPTION_NOCOMPRESSION 0x00
/* Verification variant define */

#define PROG_VERIFICATION_CRC                           0U
#define PROG_VERIFICATION_SIGNATURE_WITH_HASH           1U
#define PROG_VERIFICATION_SIGNATURE                     2U
#define PROG_VERIFICATION_SIGNATURE_AND_CRC             3U
#define PROG_VERIFICATION_SIGNATURE_WITH_HASH_AND_CRC   4U
#define PROG_VERIFICATION_HASH                          5U
#define PROG_VERIFICATION_IN_DFI                        6U


[!IF "node:exists(as:modconf('ProgJLR'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:207:IF38 osc_PROG main ', $project))"!][!ENDSELECT!]
#include "PROG_Cfg_Impl0.h"
[!ELSEIF "node:exists(as:modconf('ProgVCC'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:209:ELSEIF39 osc_PROG main ', $project))"!][!ENDSELECT!]
#include "PROG_Cfg_Impl10.h"
[!ELSEIF "node:exists(as:modconf('ProgFord'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:211:ELSEIF40 osc_PROG main ', $project))"!][!ENDSELECT!]
#include "PROG_Cfg_Impl90.h"
[!ELSEIF "node:exists(as:modconf('ProgGM'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:213:ELSEIF41 osc_PROG main ', $project))"!][!ENDSELECT!]
#include "PROG_Cfg_Impl20.h"
[!ELSEIF "node:exists(as:modconf('ProgFCA'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:215:ELSEIF42 osc_PROG main ', $project))"!][!ENDSELECT!]
#include "PROG_Cfg_Impl30.h"
[!ELSEIF "node:exists(as:modconf('ProgVAG'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:217:ELSEIF43 osc_PROG main ', $project))"!][!ENDSELECT!]
#include "PROG_Responses.h"
#include "PROG_Cfg_Impl40.h"
[!ELSEIF "node:exists(as:modconf('ProgDAG'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:220:ELSEIF44 osc_PROG main ', $project))"!][!ENDSELECT!]
#include "PROG_Cfg_Impl50.h"
[!ELSEIF "node:exists(as:modconf('ProgOEMInd'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:222:ELSEIF45 osc_PROG main ', $project))"!][!ENDSELECT!]
#include "PROG_Responses.h"
#include "PROG_Cfg_Impl60.h"
[!ELSEIF "node:exists(as:modconf('ProgPSA'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:225:ELSEIF46 osc_PROG main ', $project))"!][!ENDSELECT!]
#include "PROG_Cfg_Impl80.h"
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:227:ELSE47 osc_PROG main ', $project))"!][!ENDSELECT!]
[!ERROR "no ProgOem module has been found in the project."!]
[!ENDIF!] [!/* IF "node:exists(as:modconf('ProgJLR')) */!]

[!IF "node:exists(as:modconf('ProgFCA'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:231:IF48 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!IF "(as:modconf('Prog')/General/NO_SECURITYLEVEL_RESET_ON_SESSIONCHANGE='true')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:232:IF49 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_NORESET_SECURITYLEVEL        STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:234:ELSE50 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_NORESET_SECURITYLEVEL        STD_OFF
    [!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:237:ELSE51 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_NORESET_SECURITYLEVEL        STD_OFF
[!ENDIF!]

[!VAR "MEMORY_MAX"="num:dectoint(count(as:modconf('ReProgMemM')/MemoryConfig/Memory/*))"!]
[!IF "(node:exists(as:modconf('ReProgMemM')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:242:IF52 osc_PROG main ', $project))"!][!ENDSELECT!]
[!VAR "MEMORY_MAX"="num:dectoint(count(as:modconf('ReProgMemM')/MemoryConfig/Memory/*))"!]
[!ELSEIF "node:exists(as:modconf('Flash'))  or (node:exists(as:modconf('ProgFord')) and as:modconf('ProgFord')/General/PROG_FORD_VARIANT='PBL') or (node:exists(as:modconf('ProgJLR')) and as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL') or (node:exists(as:modconf('ProgVCC')) and as:modconf('ProgVCC')/General/PROG_VCC_VARIANT='PBL')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:244:ELSEIF53 osc_PROG main ', $project))"!][!ENDSELECT!]
[!VAR "MEMORY_MAX"="num:dectoint(count(Memory/*))"!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:246:DUMMYELSE54 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "(node:exists(as:modconf('Cal')) and as:modconf('Prog')/General/Enable_Compression='true')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:248:IF55 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CALDECOMPRESS_CFGID                        [!"name(as:ref(as:modconf('Prog')/General/ProgCalReferences/ProgCalDecompressConfigId))"!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:250:DUMMYELSE56 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]


[!VAR "SEGMENT_MAX"="num:dectoint(count(Segments/*))"!]


#define PROG_SEC_LEVEL_LOCK                             0U

#define PROG_CRC16_INIT_VAL                             0xFFFFU
#define PROG_CRC32_INIT_VAL                             0xFFFFFFFFU

#define PROG_CRC_CALC_SIZE                              [!"num:dectoint(DownloadVerification/Verification_Buffer_size)"!]U

/* max block length for TransferData */
#define PROG_MAX_BYTE_IN_TD                             [!"num:dectoint(General/Max_Bytes_in_TD)"!]UL


#define PROG_HSM_UPDATE_ENABLE                         [!WS "25"!][!IF "Segments/*/Partition_Type = 'PROG_HSM_PARTITION'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:267:IF57 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:267:ELSE58 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]

[!IF "(as:modconf('Prog')/Segments/*/Partition_Type='PROG_HSM_PARTITION')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:269:IF59 osc_PROG main ', $project))"!][!ENDSELECT!]
/*HSM Partition ID if the HSM programming is enabled*/
#define PROG_HSM_PARTITION_ID                           [!"(num:dectoint(Segments/*/HSM_PartitionID))"!]U
#define PROG_HSM_BUFFER_LENGTH                          [!"(num:dectoint(Segments/*/HSM_RAM_Buffer))"!]U
#define PROG_HSM_TIMEOUT                                [!"(num:dectoint(Segments/*/PROG_HSM_Timeout))"!]U
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:274:DUMMYELSE60 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

/* ISO 14 229 : */
/* This parameter is used by the requestDownload positive response message to */
/* inform the client how many data bytes (maxNumberOfBlockLength) shall be */
/* included in each TransferData request message from the client. This length */
/* reflects the complete message length, including the service identifier and */
/* the data parameters present in the TransferData request message. This */
/* parameter allows the client to adapt to the receive buffer size of the server */
/* before it starts transferring data to the server. */
[!IF "num:dectoint(General/Max_Bytes_in_TD) <= 65535"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:284:IF61 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SIZE_OF_NB_BLOCK_LEN                       0x20U
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:286:ELSE62 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SIZE_OF_NB_BLOCK_LEN                       0x30U
[!ENDIF!]


#define PROG_MAX_WRITE_SIZE                             0x20U

/* Polynomial for the CRC calculation */
#define PROG_CRC_TAB_SIZE                               256U

#define PROG_FLASH_CONTEXT_OK                           0x01U
#define PROG_FLASH_CONTEXT_NOT_OK                       0x00U

#define PROG_UDS_SESSION_DEFAULT                        UDS_SESSION_DEFAULT
#define PROG_UDS_SESSION_PROGRAMMING                    UDS_SESSION_PROGRAMMING

/* UDS Session parameter record */
#define PROG_UDS_SPREC                                  UDS_SPREC

/* ISO 14229 : The blockSequenceCounter parameter value starts at 01 hex with    */
/* the first TransferData request that follows the RequestDownload (34 hex) or   */
/* RequestUpload (35 hex) service. Its value is incremented by 1 for each        */
/* subsequent TransferData request. At the value of FF hex the                   */
/* blockSequenceCounter rolls over and starts at 00 hex with the next            */
/* TransferData request message.*/
#define PROG_BLOCK_SEQU_REINIT                          0x00U
#define PROG_BLOCK_SEQU_INIT                            0x01U
#define PROG_BLOCK_SEQU_MAX                             0xFFU

#define PROG_ERASE_BY_ADDR                              0x01U
#define PROG_ERASE_BY_BLOCK_ID                          0x02U
#define PROG_ERASE_BY_DYNAMIC_PARTITION_ID              0x03U

#define PROG_CHECKMEMORY_BY_SEGMENT                     0x01U
#define PROG_CHECKMEMORY_BY_BLOCK                       0x02U

/* Define if the sleep management type */
#define PROG_SLEEP_MANAGEMENT_OFF                       0U
#define PROG_SLEEP_MANAGEMENT_TIMEOUT                   1U
#define PROG_SLEEP_MANAGEMENT_IO                        2U

/* PROG_CRC_CALCULATION values */
#define PROG_NO_CRC                                     0x00U
#define PROG_TD_CRC16                                   0x01U
#define PROG_TD_CRC32                                   0x02U
#define PROG_TD_CRC_CUST                                0x03U
#define PROG_CRC32_LENGTH                               0x04U
#define PROG_PARTIAL_SW_ROUTINE_CRC_LEN                 0x0BU

/* PROG_CRC_ALGO values */
#define PROG_CRC32_ETHERNET                             0x00U
#define PROG_CRC32_INT_STD                              0x01U
#define PROG_CRC16                                      0x02U

#define PROG_MANAGE_PERIOD                              [!"num:dectoint(General/MANAGE_PERIOD)"!]U

#define PROG_TUNABLE_PARAMETERS_DEACTIVATED             0x00U
#define PROG_TUNABLE_PARAMETERS_ACTIVATED               0x01U
#define PROG_TUNABLE_PARAMETERS                         [!WS "25"!][!IF "General/Tunable_Parameters = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:344:IF63 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TUNABLE_PARAMETERS_ACTIVATED[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:344:ELSE64 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_TUNABLE_PARAMETERS_DEACTIVATED[!ENDIF!][!CR!]
#define PROG_SA_AUTHENTICATION_OFF                      0x00U
#define PROG_SA_AUTHENTICATION_0001                     0x01U
[!IF "node:exists(as:modconf('SA'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:347:IF65 osc_PROG main ', $project))"!][!ENDSELECT!]
 [!IF "(node:exists(as:modconf('SA')/General/SA_AM_TYPE)) and (as:modconf('SA')/General/SA_AM_TYPE = 'Authentication Method 0001')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:348:IF66 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SA_SEED_LEN                                SA_SEED_LEN_AM0001
#define PROG_SA_KEY_LEN                                 SA_KEY_LEN_AM0001
#define PROG_USE_SA_WITH_CRYPTO                         STD_ON

#define PROG_SA_AUTHENTICATION_METHOD                   PROG_SA_AUTHENTICATION_0001

[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:355:ELSE67 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SA_SEED_LEN                                ([!"num:dectoint(as:modconf('SA')/General/Security_Access_Seed_Length)"!]U)
#define PROG_SA_KEY_LEN                                 ([!"num:dectoint(as:modconf('SA')/General/Security_Access_Key_Length)"!]U)

#define PROG_USE_SA_WITH_CRYPTO                         [!WS "25"!][!IF "(as:modconf('SA')/General/Seed_Type = 'Cryptographic_Random') or (as:modconf('SA')/General/Seed_Type = 'Cryptographic_PUN') or (as:modconf('SA')/General/Compare_Key_Type = 'Verify_Signature')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:359:IF68 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:359:ELSE69 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!]

#define PROG_SA_AUTHENTICATION_METHOD                   PROG_SA_AUTHENTICATION_OFF
   [!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:363:ELSE70 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!IF "as:modconf('ProgJLR')/General/PROG_JLR_VARIANT!='SBL'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:364:IF71 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SA_SEED_LEN                                ([!"GM/Security_Access_Seed_Length"!]U)
#define PROG_USE_SA_WITH_CRYPTO                         STD_OFF
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:367:DUMMYELSE72 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
#define PROG_SA_AUTHENTICATION_METHOD                   PROG_SA_AUTHENTICATION_OFF
[!ENDIF!]

[!VAR "SERVICE_IDX" = "0"!]
[!VAR "DSC_02_DENIED_IN_DEF_SESSION" = "0"!]
[!VAR "DSC_02_PROTECTED_BY_SA" = "0"!]
[!FOR "SERVICE_IDX" = "1" TO "num:dectoint(count(as:modconf('Uds')/Service/*))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:374:FOR73 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!IF "as:modconf('Uds')/Service/*[number($SERVICE_IDX)]/Service = 'DSC' and as:modconf('Uds')/Service/*[number($SERVICE_IDX)]/SubService = '2' and as:modconf('Uds')/Service/*[number($SERVICE_IDX)]/Default = 'false'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:375:IF74 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "DSC_02_DENIED_IN_DEF_SESSION" = "1"!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:377:DUMMYELSE75 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!IF "as:modconf('Uds')/Service/*[number($SERVICE_IDX)]/Service = 'DSC' and as:modconf('Uds')/Service/*[number($SERVICE_IDX)]/SubService = '2' and as:modconf('Uds')/Service/*[number($SERVICE_IDX)]/SecurityLevel != '0'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:378:IF76 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "DSC_02_PROTECTED_BY_SA" = "1"!]
#define PROG_SEC_LEVEL_PROGRAMMINGSESSION               [!"num:dectoint(as:modconf('Uds')/Service/*[number($SERVICE_IDX)]/SecurityLevel)"!]U
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:381:DUMMYELSE77 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ENDFOR!]
[!IF "$DSC_02_DENIED_IN_DEF_SESSION = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:383:IF78 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_DSC02_DENIED_IN_DEF_SESSION                STD_ON
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:385:ELSE79 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_DSC02_DENIED_IN_DEF_SESSION                STD_OFF
[!ENDIF!]
[!IF "$DSC_02_PROTECTED_BY_SA = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:388:IF80 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_DSC_02_PROTECTED_BY_SA                     STD_ON
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:390:ELSE81 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_DSC_02_PROTECTED_BY_SA                     STD_OFF
[!ENDIF!]

#define PROG_DECRYPTION_ENABLE                          [!WS "26"!][!IF "Decryption/Enable_Decryption = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:394:IF82 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:394:ELSE83 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
#define PROG_CSM_DECRYPTION_ENABLE                      [!WS "26"!][!IF "Decryption/Enable_Csm_Decryption = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:395:IF84 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:395:ELSE85 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
[!IF "Decryption/Enable_Decryption = 'true' or Encryption/Enable_Encryption = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:396:IF86 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgOEMInd')) "!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:397:IF87 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "node:exists(as:modconf('Csm'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:398:IF88 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "node:exists(as:modconf('CryIf'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:399:IF89 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_AES_BLOCK_SIZE                             [!WS "31"!][!"num:dectoint(as:modconf('Csm')/CsmGeneral/CsmSymKeyMaxLength)"!]U
/* Compute the size of the encrypted text from the size of plain text */
#define PROG_CIPHERED_TEXT_SIZE(x)                      (x + (PROG_AES_BLOCK_SIZE- (x % PROG_AES_BLOCK_SIZE)))
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:403:ELSE90 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_AES_BLOCK_SIZE                             [!WS "31"!][!"num:dectoint(as:modconf('Csm')/CsmSymDecrypt/CsmSymDecryptMaxKeySize)"!]U
/* Compute the size of the encrypted text from the size of plain text */
#define PROG_CIPHERED_TEXT_SIZE(x)                      (x + (PROG_AES_BLOCK_SIZE- (x % PROG_AES_BLOCK_SIZE)))
[!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:408:DUMMYELSE91 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:409:DUMMYELSE92 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:410:DUMMYELSE93 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

#define PROG_COMPRESSION_ENABLE                         [!WS "25"!][!IF "General/Enable_Compression = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:412:IF94 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:412:ELSE95 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
#define PROG_DECOMP_SLICING_ENABLE                      [!WS "22"!][!IF "General/Enable_Compression = 'true' and General/Enable_Decompression_Slicing = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:413:IF96 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:413:ELSE97 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
[!IF "General/Enable_Compression = 'true' and General/Enable_Decompression_Slicing = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:414:IF98 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_DECOMP_SLICE_SIZE                          [!"num:dectoint(General/Decomp_Slice_size)"!]U
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:416:DUMMYELSE99 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "General/Enable_Compression = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:417:IF100 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_COMPRESSED_DATA_SIZE                       0x01U
#define PROG_DECOMPRESSED_DATA_SIZE                     0x02U
#define PROG_RD_DATA_SIZE_TYPE                          [!WS "26"!][!IF "General/Data_Size_In_RD = 'compressed'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:420:IF101 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_COMPRESSED_DATA_SIZE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:420:ELSE102 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_DECOMPRESSED_DATA_SIZE[!ENDIF!][!CR!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:421:DUMMYELSE103 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

#define PROG_BLPDUR_SUPPORT_ENABLE                      [!WS "22"!][!IF "node:exists(as:modconf('BlPduR'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:423:IF104 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:423:ELSE105 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]

[!IF "node:exists(as:modconf('DoIP'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:425:IF106 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_DOIP_SUPPORT_ENABLE [!WS "24"!]STD_ON
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:427:ELSE107 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_DOIP_SUPPORT_ENABLE [!WS "24"!]STD_OFF
[!ENDIF!]
[!CR!]

#define PROG_MEMORY_NB                                  [!"$MEMORY_MAX"!]U
#define PROG_SEGMENT_NB                                 [!"$SEGMENT_MAX"!]U

/* Define if the auto-control is used or not */
#define PROG_AUTOCONTROL_ENABLE                         [!WS "25"!][!IF "General/Auto_Control = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:436:IF108 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:436:ELSE109 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]

/* Define if NRC78 shall be sent before starting erasing */
#define PROG_NRC78_ON_ERASE_ENABLE                      [!WS "22"!][!IF "General/Transmit_Nrc78_On_Erase = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:439:IF110 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:439:ELSE111 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]

/* Define if an NRC78 response shall be systematically sent receiving the Erase request */
#define PROG_NRC78_BEFORE_ERASECHECK                    [!WS "20"!][!IF "General/Transmit_Nrc78_Before_EraseCheck = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:442:IF112 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:442:ELSE113 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]

/* Define if Preliminary Erasing is activated or not */
#define PROG_PRELIM_ERASING_ENABLE                      [!WS "22"!][!IF "General/PreliminaryErasing = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:445:IF114 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:445:ELSE115 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]

/* Define if software shall check if memory is already erased before doing an erase */
[!IF "General/Erase_Check = 'First Programming Check'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:448:IF116 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_ERASE_CHECK_TYPE                           [!WS "27"!]PROG_1ST_PROGRAMMING_ERASE_CHECK[!CR!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:450:ELSE117 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!IF "General/Erase_Check = 'Memory Block Erased Check'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:451:IF118 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_ERASE_CHECK_TYPE                           [!WS "27"!]PROG_BLOCK_ERASE_CHECK[!CR!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:453:ELSE119 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_ERASE_CHECK_TYPE                           [!WS "27"!]PROG_DISABLED_ERASE_CHECK[!CR!]
    [!ENDIF!]
[!ENDIF!]

[!IF "(node:exists(as:modconf('Flash')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:458:IF120 osc_PROG main ', $project))"!][!ENDSELECT!]                                 
/* Define number of sector to erase before sending NRC78 */
#define PROG_NB_OF_SECTOR_TO_ERASE_BEFORE_SENDING_NRC78 [!"num:dectoint(as:modconf('Prog')/General/Number_Of_Sector_To_Erase_Before_Sending_NRC78)"!]U

/* Enable and disable erasing by sector */
[!VAR "SLICED_ERASING_FOR_NRC78_SENDING" = "1"!]
[!IF "as:modconf('Prog')/General/Number_Of_Sector_To_Erase_Before_Sending_NRC78 = '0'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:464:IF121 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!VAR "SLICED_ERASING_FOR_NRC78_SENDING" = "0"!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:466:DUMMYELSE122 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!IF "$SLICED_ERASING_FOR_NRC78_SENDING = 0"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:468:IF123 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SLICED_ERASING_FOR_NRC78_SENDING STD_OFF
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:470:ELSE124 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SLICED_ERASING_FOR_NRC78_SENDING STD_ON
[!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:473:ELSE125 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SLICED_ERASING_FOR_NRC78_SENDING STD_OFF
[!ENDIF!]                              

/* Define if response shall be sent before resetting software */
#define PROG_RESPOND_BEFORE_RESET                       [!WS "23"!][!IF "General/Transmit_Response_Before_Reset = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:478:IF126 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:478:ELSE127 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]

/* Define if reset is required while switching from default to default session */
#define PROG_RESET_AFTER_DSC01_IN_DEFAULT_SESSION       [!WS "7"!][!IF "General/ResetAfterDsc01InDefaultSession = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:481:IF128 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:481:ELSE129 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]

/*Enable the reset after S3 timeout coming from the programming session */
#define PROG_RESET_AFTER_S3_TIMEOUT_IN_PROG_SESSION     [!WS "5"!][!IF "General/ResetAfterS3TimeoutInProgrammingSession = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:484:IF130 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:484:ELSE131 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
/*Enable the reset after S3 timeout coming from the extended session */
#define PROG_RESET_AFTER_S3_TIMEOUT_IN_EXT_SESSION      [!WS "6"!][!IF "General/ResetAfterS3TimeoutInExtendedSession = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:486:IF132 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:486:ELSE133 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]

[!IF "node:exists(as:modconf('EB')) and (as:modconf('EB')/Communication/EnableMultipleTpConnection='true')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:488:IF134 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_MULTIPLE_TP_CONNECTIONS_ENABLE             STD_ON
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:490:ELSE135 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_MULTIPLE_TP_CONNECTIONS_ENABLE             STD_OFF
[!ENDIF!]

[!VAR "ERASE_MEMORY_USE" = "0"!]
[!VAR "ACTIVE_SBL_USE" = "0"!]
[!VAR "CHECK_VALID_APPLICATION_USE" = "0"!]
[!VAR "SUBMIT_SIGNATURE_USE" = "0"!]
[!VAR "VALIDATE_APPLICATION_USE" = "0"!]
[!VAR "CHECK_PROG_DEP_USE" = "0"!]
[!VAR "AUTO_CONTROL_USE" = "0"!]
[!VAR "COHERENCY_PRE_CHECK_USE" = "0"!]
[!VAR "ACTIVE_CURRENT_SESSION_USE" = "0"!]
[!VAR "CURRENT_DIAG_APP_USE" = "0"!]
[!VAR "GET_PSI_USE" = "0"!]
[!VAR "GET_BOOT_STATUS_USE" = "0"!]
[!VAR "GET_PEC_USE" = "0"!]
[!VAR "GET_ECU_ID_USE" = "0"!]
[!VAR "GET_ECU_ADDR_USE" = "0"!]
[!VAR "GET_ECU_NAME_USE" = "0"!]
[!VAR "GET_SBA_TICKET_USE" = "0"!]
[!VAR "GET_BOOT_INFO_USE" = "0"!]
[!VAR "FINGERPRINT_USE" = "0"!]
[!IF "node:exists(as:modconf('Uds'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:513:IF136 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!/* Check if service are configured */!]
    [!LOOP " as:modconf('Uds')/Service/*"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:515:LOOP137 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!ENDLOOP!]
    [!/* Check if service DID are configured */!]
    [!LOOP " as:modconf('Uds')/Service_DID/*"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:518:LOOP138 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!IF "Callback = 'PROG_GetActiveCurrentSession'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:519:IF139 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "ACTIVE_CURRENT_SESSION_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:521:DUMMYELSE140 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!IF "Callback = 'PROG_GetCurrentDiagApp'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:522:IF141 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "CURRENT_DIAG_APP_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:524:DUMMYELSE142 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!IF "Callback = 'PROG_GetPSIValues'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:525:IF143 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "GET_PSI_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:527:DUMMYELSE144 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!IF "Callback = 'PROG_GetBootStatus'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:528:IF145 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "GET_BOOT_STATUS_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:530:DUMMYELSE146 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!IF "Callback = 'PROG_GetPEC'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:531:IF147 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "GET_PEC_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:533:DUMMYELSE148 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!IF "Callback = 'PROG_GetEcuID'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:534:IF149 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "GET_ECU_ID_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:536:DUMMYELSE150 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!IF "Callback = 'PROG_GetEcuAddr'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:537:IF151 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "GET_ECU_ADDR_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:539:DUMMYELSE152 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!IF "Callback = 'PROG_GetEcuName'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:540:IF153 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "GET_ECU_NAME_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:542:DUMMYELSE154 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!IF "Callback = 'PROG_GetSbaTicket'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:543:IF155 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "GET_SBA_TICKET_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:545:DUMMYELSE156 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!IF "Callback = 'PROG_WriteFingerprint'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:546:IF157 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "FINGERPRINT_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:548:DUMMYELSE158 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!IF "Callback = 'PROG_GetBootInfo'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:549:IF159 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "GET_BOOT_INFO_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:551:DUMMYELSE160 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ENDLOOP!]
    [!/* Check if Routine controle are configured */!]
    [!LOOP " as:modconf('Uds')/Routine_Control/*"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:554:LOOP161 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!IF "Callback = 'PROG_EraseMemory'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:555:IF162 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "ERASE_MEMORY_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:557:DUMMYELSE163 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!IF "Callback = 'PROG_ActiveSBL'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:558:IF164 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "ACTIVE_SBL_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:560:DUMMYELSE165 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!IF "Callback = 'PROG_CheckValidApplication'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:561:IF166 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "CHECK_VALID_APPLICATION_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:563:DUMMYELSE167 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!IF "Callback = 'PROG_SubmitSignature'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:564:IF168 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "SUBMIT_SIGNATURE_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:566:DUMMYELSE169 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!IF "Callback = 'PROG_ValidateApplication'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:567:IF170 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "VALIDATE_APPLICATION_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:569:DUMMYELSE171 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!IF "Callback = 'PROG_CheckProgrammingDependencies'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:570:IF172 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "CHECK_PROG_DEP_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:572:DUMMYELSE173 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!IF "Callback = 'PROG_AutoControl'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:573:IF174 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "AUTO_CONTROL_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:575:DUMMYELSE175 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!IF "Callback = 'PROG_CoherencyPreCheck'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:576:IF176 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "COHERENCY_PRE_CHECK_USE" = "1"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:578:DUMMYELSE177 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ENDLOOP!]
[!/* SERVICE DID */!]
    [!IF "$ACTIVE_CURRENT_SESSION_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:581:IF178 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_ACTIVE_CURRENT_SESSION_REQUEST_ENABLE              STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:583:ELSE179 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_ACTIVE_CURRENT_SESSION_REQUEST_ENABLE              STD_OFF
    [!ENDIF!]
    [!IF "$CURRENT_DIAG_APP_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:586:IF180 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CURRENT_DIAG_APPLICATION_REQUEST_ENABLE            STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:588:ELSE181 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CURRENT_DIAG_APPLICATION_REQUEST_ENABLE            STD_OFF
    [!ENDIF!]
    [!IF "$GET_PSI_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:591:IF182 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_GET_PSI_REQUEST_ENABLE                             STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:593:ELSE183 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_GET_PSI_REQUEST_ENABLE                             STD_OFF
    [!ENDIF!]
    [!IF "$GET_BOOT_STATUS_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:596:IF184 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_GET_BOOT_STATUS_REQUEST_ENABLE                     STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:598:ELSE185 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_GET_BOOT_STATUS_REQUEST_ENABLE                     STD_OFF
    [!ENDIF!]
    [!IF "$GET_PEC_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:601:IF186 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_GET_PEC_REQUEST_ENABLE                             STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:603:ELSE187 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_GET_PEC_REQUEST_ENABLE                             STD_OFF
    [!ENDIF!]
    [!IF "$GET_ECU_ID_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:606:IF188 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_GET_ECU_ID_REQUEST_ENABLE                          STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:608:ELSE189 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_GET_ECU_ID_REQUEST_ENABLE                          STD_OFF
    [!ENDIF!]
    [!IF "$GET_ECU_ADDR_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:611:IF190 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_GET_ECU_ADDR_REQUEST_ENABLE                        STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:613:ELSE191 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_GET_ECU_ADDR_REQUEST_ENABLE                        STD_OFF
    [!ENDIF!]
    [!IF "$GET_ECU_NAME_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:616:IF192 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_GET_ECU_NAME_REQUEST_ENABLE                        STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:618:ELSE193 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_GET_ECU_NAME_REQUEST_ENABLE                        STD_OFF
    [!ENDIF!]
    [!IF "$GET_SBA_TICKET_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:621:IF194 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_GET_SBA_TICKET_REQUEST_ENABLE                      STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:623:ELSE195 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_GET_SBA_TICKET_REQUEST_ENABLE                      STD_OFF
    [!ENDIF!]
    [!IF "$FINGERPRINT_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:626:IF196 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_WRITE_FINGERPRINT_ENABLE                           STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:628:ELSE197 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_WRITE_FINGERPRINT_ENABLE                           STD_OFF
    [!ENDIF!]
    [!IF "$GET_BOOT_INFO_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:631:IF198 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_GET_BOOT_INFO_REQUEST_ENABLE                       STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:633:ELSE199 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_GET_BOOT_INFO_REQUEST_ENABLE                       STD_OFF
    [!ENDIF!]
[!/* END SERVICE DID */!]

[!/* ROUTINE CONTROLE */!]
    [!IF "$ERASE_MEMORY_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:639:IF200 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_ERASE_MEMORY_REQUEST_ENABLE                        STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:641:ELSE201 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_ERASE_MEMORY_REQUEST_ENABLE                        STD_OFF
    [!ENDIF!]
    [!IF "$ACTIVE_SBL_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:644:IF202 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_ACTIVE_SBL_REQUEST_ENABLE                          STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:646:ELSE203 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_ACTIVE_SBL_REQUEST_ENABLE                          STD_OFF
    [!ENDIF!]
      [!IF "$CHECK_VALID_APPLICATION_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:649:IF204 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CHECK_VALID_APPLICATION_ENABLE                        STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:651:ELSE205 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CHECK_VALID_APPLICATION_ENABLE                        STD_OFF
    [!ENDIF!]
    [!IF "$SUBMIT_SIGNATURE_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:654:IF206 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SUBMITSIGNATURE_ENABLE                        STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:656:ELSE207 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SUBMITSIGNATURE_ENABLE                        STD_OFF
    [!ENDIF!]
    [!IF "$VALIDATE_APPLICATION_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:659:IF208 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_VALIDATE_APPLICATION_ENABLE                        STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:661:ELSE209 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_VALIDATE_APPLICATION_ENABLE                        STD_OFF
    [!ENDIF!]
    [!IF "$CHECK_PROG_DEP_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:664:IF210 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CHECK_PROGRAMMING_DEPENDENCIES_REQUEST_ENABLE      STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:666:ELSE211 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CHECK_PROGRAMMING_DEPENDENCIES_REQUEST_ENABLE      STD_OFF
    [!ENDIF!]
    [!IF "$AUTO_CONTROL_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:669:IF212 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_AUTO_CONTROL_REQUEST_ENABLE                        STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:671:ELSE213 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_AUTO_CONTROL_REQUEST_ENABLE                        STD_OFF
    [!ENDIF!]
    [!IF "$COHERENCY_PRE_CHECK_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:674:IF214 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_COHERENCY_PRE_CHECK_ENABLE                         STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:676:ELSE215 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_COHERENCY_PRE_CHECK_ENABLE                         STD_OFF
    [!ENDIF!]
[!/*END ROUTINE CONTROLE */!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:680:DUMMYELSE216 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!VAR "FLASH_USE" = "0"!]
[!VAR "FLASH_ACCESS" = "0"!]
[!VAR "FLASH_EXT_USE" = "0"!]
[!VAR "FLASH_EXT_ACCESS" = "0"!]
[!VAR "RAM_USE" = "0"!]
[!VAR "RAM_ACCESS" = "0"!]
[!VAR "CUSTOM_MEMORY_USE" = "0"!]
[!VAR "CUSTOM_MEMORY_ACCESS" = "0"!]
[!VAR "FLASH_ROUTINES_INRAM_USED" = "0"!]
[!LOOP "Segments/*"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:691:LOOP217 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!VAR "Memory_Type" = "node:ref(Memory)/Memory_Type"!]
    [!IF "as:modconf('Prog')/DownloadFlashRoutines/Download_Flash_Routines='true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:693:IF218 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "Partition_Type" = "./Partition_Type"!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:695:DUMMYELSE219 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!IF "$Memory_Type = 'FLASH'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:696:IF220 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "FLASH_USE" = "1"!]
        [!IF "(node:exists(as:modconf('Flash')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:698:IF221 osc_PROG main ', $project))"!][!ENDSELECT!]
           [!VAR "MEMORY_MODE_FLASH" = "node:ref(Memory)/Memory_Mode"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:700:DUMMYELSE222 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!VAR "MEMORY_ADDRESS_OFFSET_FLASH"="node:ref(Memory)/Addr_Offset"!]
        [!VAR "ERASE_VALUE_FLASH"="node:ref(Memory)/Erase_Value"!]
        [!VAR "MIN_VAL_TO_WRITE_FOR_FLASH"="node:ref(Memory)/Min_Value_To_Write"!]
        [!IF "Access_Type = 'READ'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:704:IF223 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!IF "$FLASH_ACCESS = 0"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:705:IF224 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "FLASH_ACCESS" = "'READ'"!]
            [!ELSEIF "$FLASH_ACCESS = 'WRITE'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:707:ELSEIF225 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "FLASH_ACCESS" = "'READ_WRITE'"!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:709:DUMMYELSE226 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!ELSEIF "Access_Type = 'WRITE'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:710:ELSEIF227 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!IF "$FLASH_ACCESS = 0"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:711:IF228 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "FLASH_ACCESS" = "'WRITE'"!]
            [!ELSEIF "$FLASH_ACCESS = 'READ'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:713:ELSEIF229 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "FLASH_ACCESS" = "'READ_WRITE'"!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:715:DUMMYELSE230 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:716:ELSE231 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "FLASH_ACCESS" = "'READ_WRITE'"!]
        [!ENDIF!]
    [!ELSEIF "$Memory_Type = 'FLASH_EXT'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:719:ELSEIF232 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "FLASH_EXT_USE" = "1"!]
	[!IF "(node:exists(as:modconf('Flash')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:721:IF233 osc_PROG main ', $project))"!][!ENDSELECT!]
           [!VAR "MEMORY_MODE_FLASH_EXT" = "node:ref(Memory)/Memory_Mode"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:723:DUMMYELSE234 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!VAR "MEMORY_ADDRESS_OFFSET_FLASH_EXT"="node:ref(Memory)/Addr_Offset"!]
        [!VAR "ERASE_VALUE_FLASH_EXT"="node:ref(Memory)/Erase_Value"!]
        [!VAR "MIN_VAL_TO_WRITE_FOR_FLASH_EXT"="node:ref(Memory)/Min_Value_To_Write"!]
        [!IF "Access_Type = 'READ'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:727:IF235 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!IF "$FLASH_EXT_ACCESS = 0"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:728:IF236 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "FLASH_EXT_ACCESS" = "'READ'"!]
            [!ELSEIF "$FLASH_EXT_ACCESS = 'WRITE'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:730:ELSEIF237 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "FLASH_EXT_ACCESS" = "'READ_WRITE'"!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:732:DUMMYELSE238 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!ELSEIF "Access_Type = 'WRITE'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:733:ELSEIF239 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!IF "$FLASH_EXT_ACCESS = 0"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:734:IF240 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "FLASH_EXT_ACCESS" = "'WRITE'"!]
            [!ELSEIF "$FLASH_EXT_ACCESS = 'READ'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:736:ELSEIF241 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "FLASH_EXT_ACCESS" = "'READ_WRITE'"!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:738:DUMMYELSE242 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:739:ELSE243 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "FLASH_EXT_ACCESS" = "'READ_WRITE'"!]
        [!ENDIF!]
    [!ELSEIF "$Memory_Type = 'RAM'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:742:ELSEIF244 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "RAM_USE" = "1"!]
[!IF "not(node:exists(as:modconf('ReProgMemM')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:744:IF245 osc_PROG main ', $project))"!][!ENDSELECT!]
           [!VAR "MEMORY_MODE_RAM" = "node:ref(Memory)/Memory_Mode"!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:746:DUMMYELSE246 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!VAR "MEMORY_ADDRESS_OFFSET_RAM"="node:ref(Memory)/Addr_Offset"!]
        [!VAR "ERASE_VALUE_RAM"="node:ref(Memory)/Erase_Value"!]
        [!IF "Access_Type = 'READ'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:749:IF247 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!IF "$RAM_ACCESS = 0"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:750:IF248 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "RAM_ACCESS" = "'READ'"!]
            [!ELSEIF "$RAM_ACCESS = 'WRITE'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:752:ELSEIF249 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "RAM_ACCESS" = "'READ_WRITE'"!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:754:DUMMYELSE250 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!ELSEIF "Access_Type = 'WRITE'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:755:ELSEIF251 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!IF "$RAM_ACCESS = 0"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:756:IF252 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "RAM_ACCESS" = "'WRITE'"!]
            [!ELSEIF "$RAM_ACCESS = 'READ'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:758:ELSEIF253 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "RAM_ACCESS" = "'READ_WRITE'"!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:760:DUMMYELSE254 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:761:ELSE255 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "RAM_ACCESS" = "'READ_WRITE'"!]
        [!ENDIF!]
    [!ELSEIF "$Memory_Type = 'CUSTOM'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:764:ELSEIF256 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "CUSTOM_MEMORY_USE" = "1"!]
        [!IF "(node:exists(as:modconf('Flash')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:766:IF257 osc_PROG main ', $project))"!][!ENDSELECT!]
           [!VAR "MEMORY_MODE_CUSTOM_MEM" = "node:ref(Memory)/Memory_Mode"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:768:DUMMYELSE258 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!VAR "MEMORY_ADDRESS_OFFSET_CUSTOM_MEM"="node:ref(Memory)/Addr_Offset"!]
        [!VAR "ERASE_VALUE_CUSTOM_MEM"="node:ref(Memory)/Erase_Value"!]
        [!IF "Access_Type = 'READ'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:771:IF259 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!IF "$CUSTOM_MEMORY_ACCESS = 0"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:772:IF260 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "CUSTOM_MEMORY_ACCESS" = "'READ'"!]
            [!ELSEIF "$CUSTOM_MEMORY_ACCESS = 'WRITE'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:774:ELSEIF261 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "CUSTOM_MEMORY_ACCESS" = "'READ_WRITE'"!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:776:DUMMYELSE262 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!ELSEIF "Access_Type = 'WRITE'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:777:ELSEIF263 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!IF "$CUSTOM_MEMORY_ACCESS = 0"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:778:IF264 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "CUSTOM_MEMORY_ACCESS" = "'WRITE'"!]
            [!ELSEIF "$CUSTOM_MEMORY_ACCESS = 'READ'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:780:ELSEIF265 osc_PROG main ', $project))"!][!ENDSELECT!]
                [!VAR "CUSTOM_MEMORY_ACCESS" = "'READ_WRITE'"!]
            [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:782:DUMMYELSE266 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:783:ELSE267 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "CUSTOM_MEMORY_ACCESS" = "'READ_WRITE'"!]
        [!ENDIF!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:786:DUMMYELSE268 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!IF "as:modconf('Prog')/DownloadFlashRoutines/Download_Flash_Routines='true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:787:IF269 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!IF "$Partition_Type = 'PROG_FLASH_ROUTINES_PARTITION'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:788:IF270 osc_PROG main ', $project))"!][!ENDSELECT!]
            [!VAR "Flash_Routines_StartAdd" = "./Erase_Start_Address"!]
            [!VAR "Flash_Routines_EndAdd" = "./Erase_End_Address"!]
            [!VAR "Flash_Routines_EraseVal" = "node:ref(Memory)/Erase_Value"!]
        [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:792:DUMMYELSE271 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:793:DUMMYELSE272 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ENDLOOP!]


[!IF "General/Dsc_Prog_Response = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:797:IF273 osc_PROG main ', $project))"!][!ENDSELECT!]
[!VAR "SESSION_IDX" = "0"!]
[!FOR "SESSION_IDX" = "1" TO "num:dectoint(count(as:modconf('Uds')/Session/*))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:799:FOR274 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!IF "as:modconf('Uds')/Session/*[number($SESSION_IDX)]/@name = 'PROGRAMMING'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:800:IF275 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "P2VAL" = "as:modconf('Uds')/Session/*[number($SESSION_IDX)]/UDS_P2"!]
        [!VAR "P2STARVAL" = "as:modconf('Uds')/Session/*[number($SESSION_IDX)]/UDS_P2STAR"!]
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:803:DUMMYELSE276 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ENDFOR!]
#define PROG_P2_PROG_SESSION_VAL                        [!WS "24"!](u16)[!"$P2VAL"!]U
#define PROG_P2STAR_PROG_SESSION_VAL                    [!WS "20"!](u16)[!"$P2STARVAL"!]U
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:807:DUMMYELSE277 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!VAR "FAR_POINTER"="General/FAR_POINTER_Definition"!]
#define PROG_FAR_POINTER                                *[!"$FAR_POINTER"!]

extern const tCfgMemorytType m_astCfgMemory[PROG_MEMORY_NB];
[!IF "General/Tunable_Parameters = 'false'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:813:IF278 osc_PROG main ', $project))"!][!ENDSELECT!]
extern const tCfgSegmentType stConfigSegment[PROG_SEGMENT_NB];
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:815:ELSE279 osc_PROG main ', $project))"!][!ENDSELECT!]
extern const tCfgSegmentType stConstConfigSegment[PROG_SEGMENT_NB];
extern tCfgSegmentType stConfigSegment[PROG_SEGMENT_NB];
[!ENDIF!]
 
[!IF "as:modconf('Prog')/Segments/*/Partition_Type = 'PROG_BLU_APP_PARTITION' 
   or as:modconf('Prog')/Segments/*/Partition_Type = 'PROG_BLU_CAL_PARTITION'
   or as:modconf('Prog')/Segments/*/Partition_Type = 'PROG_BLU_PARTITION'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:822:IF280 osc_PROG main ', $project))"!][!ENDSELECT!]
extern tContextRestore stBLUContextRestore;
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:824:DUMMYELSE281 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

/* Algorithm to be used for OemInd implementation: EB/Custom */
#define PROG_APPLI_CHECK_ALGO_EB                        [!WS "24"!][!IF "OemInd/Application_Validity_Algo = 'EB'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:827:IF282 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:827:ELSE283 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]

[!IF "$FLASH_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:829:IF284 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_FLASH_MEMORY_USE                           PROG_TRUE
#define PROG_FLASH_ERASE_VALUE                          [!"$ERASE_VALUE_FLASH"!]U
#define PROG_FLASH_ADDR_OFFSET                          [!"$MEMORY_ADDRESS_OFFSET_FLASH"!]U
#define PROG_FLASH_ACCESS_TYPE                          [!WS "26"!][!IF "$FLASH_ACCESS = 'READ'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:833:IF285 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEM_ACCESS_TYPE_READ[!ELSEIF "$FLASH_ACCESS = 'WRITE'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:833:ELSEIF286 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEM_ACCESS_TYPE_WRITE[!ELSEIF "$FLASH_ACCESS = 'READ_WRITE'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:833:ELSEIF287 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEM_ACCESS_TYPE_READ_WRITE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:833:ELSE288 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEM_ACCESS_TYPE_NONE[!ENDIF!][!CR!]
[!IF "(node:exists(as:modconf('Flash')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:834:IF289 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!IF "$MEMORY_MODE_FLASH = 'asynchronous'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:835:IF290 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_FLASH_MODE                                 PROG_MEMORY_ASYNCHRONOUS
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:837:ELSE291 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_FLASH_MODE                                 PROG_MEMORY_SYNCHRONOUS
    [!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:840:ELSE292 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_FLASH_MODE                                 PROG_MEMORY_NOTUSED
[!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:843:ELSE293 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_FLASH_MEMORY_USE                           PROG_FALSE
#define PROG_FLASH_MODE                                 PROG_MEMORY_NOTUSED
#define PROG_FLASH_ACCESS_TYPE                          PROG_MEMORY_NOTUSED
[!ENDIF!]

[!IF "$FLASH_EXT_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:849:IF294 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_FLASH_EXT_MEMORY_USE                       PROG_TRUE
#define PROG_FLASH_EXT_ERASE_VALUE                      [!"$ERASE_VALUE_FLASH_EXT"!]U
#define PROG_FLASH_EXT_ADDR_OFFSET                      [!"$MEMORY_ADDRESS_OFFSET_FLASH_EXT"!]U
#define PROG_FLASH_EXT_ACCESS_TYPE                      [!WS "2"!][!IF "$FLASH_EXT_ACCESS = 'READ'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:853:IF295 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEM_ACCESS_TYPE_READ[!ELSEIF "$FLASH_EXT_ACCESS = 'WRITE'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:853:ELSEIF296 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEM_ACCESS_TYPE_WRITE[!ELSEIF "$FLASH_EXT_ACCESS ='READ_WRITE'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:853:ELSEIF297 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEM_ACCESS_TYPE_READ_WRITE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:853:ELSE298 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEM_ACCESS_TYPE_NONE[!ENDIF!][!CR!]
[!IF "(node:exists(as:modconf('Flash')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:854:IF299 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!IF "$MEMORY_MODE_FLASH_EXT = 'asynchronous'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:855:IF300 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_FLASH_EXT_MODE                             PROG_MEMORY_ASYNCHRONOUS
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:857:ELSE301 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_FLASH_EXT_MODE                             PROG_MEMORY_SYNCHRONOUS
    [!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:860:ELSE302 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_FLASH_EXT_MODE                             PROG_MEMORY_NOTUSED
[!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:863:ELSE303 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_FLASH_EXT_MEMORY_USE                       PROG_FALSE
#define PROG_FLASH_EXT_MODE                             PROG_MEMORY_NOTUSED
#define PROG_FLASH_EXT_ACCESS_TYPE                      PROG_MEMORY_NOTUSED
[!ENDIF!]

[!IF "$RAM_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:869:IF304 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_RAM_MEMORY_USE                             PROG_TRUE
#define PROG_RAM_ERASE_VALUE                            [!"$ERASE_VALUE_RAM"!]U
[!IF "not(node:exists(as:modconf('ReProgMemM')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:872:IF305 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_RAM_MODE                                   PROG_MEMORY_SYNCHRONOUS
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:874:DUMMYELSE306 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
#define PROG_RAM_ACCESS_TYPE                            [!WS "28"!][!IF "$RAM_ACCESS = 'READ'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:875:IF307 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEM_ACCESS_TYPE_READ[!ELSEIF "$RAM_ACCESS = 'WRITE'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:875:ELSEIF308 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEM_ACCESS_TYPE_WRITE[!ELSEIF "$RAM_ACCESS = 'READ_WRITE'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:875:ELSEIF309 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEM_ACCESS_TYPE_READ_WRITE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:875:ELSE310 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEM_ACCESS_TYPE_NONE[!ENDIF!][!CR!]


[!IF "as:modconf('Prog')/DownloadFlashRoutines/Download_Flash_Routines='true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:878:IF311 osc_PROG main ', $project))"!][!ENDSELECT!]
/* These macros are used to define the address of the Flash routine in RAM memory */
#define PROG_FLASH_ROUTINES_RAM_ADDR_START              [!"$Flash_Routines_StartAdd"!]U
#define PROG_FLASH_ROUTINES_RAM_ADDR_END                [!"$Flash_Routines_EndAdd"!]U
#define PROG_FLASH_ROUTINES_RAM_ERASE_VALUE             [!"$Flash_Routines_EraseVal"!]U
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:883:DUMMYELSE312 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:884:ELSE313 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_RAM_MEMORY_USE                             PROG_FALSE
#define PROG_RAM_MODE                                   PROG_MEMORY_NOTUSED
#define PROG_RAM_ERASE_VALUE                            0U
[!ENDIF!]

[!IF "$CUSTOM_MEMORY_USE = 1"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:890:IF314 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CUSTOM_MEMORY_USE                          PROG_TRUE
#define PROG_CUSTOM_MEMORY_ERASE_VALUE                  [!"$ERASE_VALUE_CUSTOM_MEM"!]U
#define PROG_CUSTOM_MEMORY_ADDR_OFFSET                  [!"$MEMORY_ADDRESS_OFFSET_CUSTOM_MEM"!]U
#define PROG_CUSTOM_MEMORY_ACCESS_TYPE                  [!WS "18"!][!IF "$CUSTOM_MEMORY_ACCESS = 'READ'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:894:IF315 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEM_ACCESS_TYPE_READ[!ELSEIF "$CUSTOM_MEMORY_ACCESS = 'WRITE'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:894:ELSEIF316 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEM_ACCESS_TYPE_WRITE[!ELSEIF "$CUSTOM_MEMORY_ACCESS ='READ_WRITE'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:894:ELSEIF317 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEM_ACCESS_TYPE_READ_WRITE[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:894:ELSE318 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_MEM_ACCESS_TYPE_NONE[!ENDIF!][!CR!]
[!IF "(node:exists(as:modconf('Flash')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:895:IF319 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!IF "$MEMORY_MODE_CUSTOM_MEM = 'asynchronous'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:896:IF320 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CUSTOM_MEMORY_MODE                         PROG_MEMORY_ASYNCHRONOUS
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:898:ELSE321 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CUSTOM_MEMORY_MODE                         PROG_MEMORY_SYNCHRONOUS
    [!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:901:ELSE322 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CUSTOM_MEMORY_MODE                         PROG_MEMORY_NOTUSED
[!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:904:ELSE323 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CUSTOM_MEMORY_USE                          PROG_FALSE
#define PROG_CUSTOM_MEMORY_MODE                         PROG_MEMORY_NOTUSED
#define PROG_CUSTOM_MEMORY_ACCESS_TYPE                  PROG_MEMORY_NOTUSED
[!ENDIF!]

[!IF "General/Tunable_Parameters = 'false'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:910:IF324 osc_PROG main ', $project))"!][!ENDSELECT!]
/* Segment Index */
[!FOR "SEGMENT_IDX" = "1" TO "$SEGMENT_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:912:FOR325 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "SEGMENT_NAME"="text:toupper(name(Segments/*[number($SEGMENT_IDX)]))"!]
        [!VAR "SEGMENT_ID"="num:inttohex(($SEGMENT_IDX)-1)"!]
#define PROG_SEG_[!"$SEGMENT_NAME"!]                    [!"$SEGMENT_ID"!]
[!ENDFOR!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:917:DUMMYELSE326 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

[!FOR "MEMORY_IDX" = "1" TO "$MEMORY_MAX"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:919:FOR327 osc_PROG main ', $project))"!][!ENDSELECT!]
        [!VAR "MEMORY_NAME"="text:toupper(name(Memory/*[number($MEMORY_IDX)]))"!]
        [!VAR "MEMORY_ID"="num:inttohex(($MEMORY_IDX)-1)"!]
#define PROG_MEMORY_[!"$MEMORY_NAME"!]                  [!"$MEMORY_ID"!]
[!ENDFOR!]

[!IF "General/Dual_Memory_Bank_Used = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:925:IF328 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_OTA_DUALBANK_USED                          STD_ON
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:927:ELSE329 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_OTA_DUALBANK_USED                          STD_OFF
[!ENDIF!]

/* Network use definition */
#define PROG_BLPDUR_NETWORK_CAN_SUPPORTED      [!WS "6"!][!IF "as:modconf('BlPduR')/General/Can_Protocol_Supported = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:932:IF330 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:932:ELSE331 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
#define PROG_BLPDUR_NETWORK_FLEXRAY_SUPPORTED  [!WS "2"!][!IF "as:modconf('BlPduR')/General/FlexRay_Protocol_Supported = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:933:IF332 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:933:ELSE333 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
#define PROG_BLPDUR_NETWORK_ETH_SUPPORTED      [!WS "6"!][!IF "as:modconf('BlPduR')/General/Eth_Protocol_Supported = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:934:IF334 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:934:ELSE335 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
#define PROG_BLPDUR_NETWORK_LIN_SUPPORTED      [!WS "6"!][!IF "as:modconf('BlPduR')/General/Lin_Protocol_Supported = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:935:IF336 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:935:ELSE337 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
#define PROG_BLPDUR_ASR_NETWORK_PRESENT        [!WS "8"!][!IF "as:modconf('BlPduR')/General/Can_Protocol_Supported = 'true'
                                                          or as:modconf('BlPduR')/General/FlexRay_Protocol_Supported = 'true'
                                                          or as:modconf('BlPduR')/General/Eth_Protocol_Supported = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:938:IF338 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:938:ELSE339 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]

/* use HSM or not */
[!IF "as:modconf('BM')/Security/SecureBoot/BMSecureBootWithHsm = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:941:IF340 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_HSM_MAC_USED                               STD_ON
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:943:ELSE341 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_HSM_MAC_USED                               STD_OFF
[!ENDIF!]

[!IF "as:modconf('Prog')/Segments/*/Partition_Type = 'PROG_BLU_APP_PARTITION' 
   or as:modconf('Prog')/Segments/*/Partition_Type = 'PROG_BLU_CAL_PARTITION'
   or as:modconf('Prog')/Segments/*/Partition_Type = 'PROG_BLU_PARTITION'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:949:IF342 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_BLU_ACTIVE                                 STD_ON
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:951:ELSE343 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_BLU_ACTIVE                                 STD_OFF
[!ENDIF!]

[!IF "(node:exists(as:modconf('ProgFCA')) and as:modconf('ProgFCA')/General/PROG_FCA_VARIANT='Atlantis_High')
 or node:exists(as:modconf('ProgVAG')) or node:exists(as:modconf('ProgDAG')) or node:exists(as:modconf('ProgVCC'))
    or (node:exists(as:modconf('ProgOEMInd')) and OemInd/Erase_Mode = 'All')
    or (node:exists(as:modconf('ProgOEMInd')) and OemInd/Erase_Mode = 'LogicalBlock')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:958:IF344 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CHECKMEMORY_TYPE                           PROG_CHECKMEMORY_BY_BLOCK
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg.h:960:ELSE345 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CHECKMEMORY_TYPE                           PROG_CHECKMEMORY_BY_SEGMENT
[!ENDIF!]
#endif /* PROG_CFG_H */
