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
/*%%   _____________________________   %%  \file PROG_Cfg_Impl0.h                */
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
#ifndef PROG_CFG_IMPL0_H
#define PROG_CFG_IMPL0_H

[!NOCODE!]
[!IF "not(node:exists(as:modconf('ProgJLR')))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:31:IF1 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!SKIPFILE!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:33:DUMMYELSE2 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ENDNOCODE!]

[!IF "node:exists(as:modconf('ProgJLR'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:36:IF3 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_ACTIVE_SBL_RESPONSE_SIZE                   5U
#define PROG_ECU_RESET_RESPONSE_SIZE                    2U
#define PROG_DSC_RESPONSE_SIZE                          2U
#define PROG_TD_RESPONSE_SIZE                           2U
#define PROG_RTE_RESPONSE_SIZE                          3U
#define PROG_COMPARE_KEY_RESPONSE_SIZE                  2U
#define PROG_ERASE_POS_RESPONSE_SIZE                    5U
#define PROG_CHK_PROG_DEP_POS_RESPONSE_SIZE             7U
#define PROG_ERASE_REQUEST_DATA                         4U
#define PROG_RD_RESPONSE_SIZE                           4U
#define PROG_TD_MIN_SIZE                                2U
#define PROG_TD_MIN_SIZE_RD                             3U
#define PROG_NRC_SIZE                                   3U
#define PROG_RTE_SIZE                                   1U

#define PROG_ERASE_ADDR_LEN                             4U
#define PROG_ERASE_SIZE_LEN                             4U

#define PROG_RESPONSE_PARAMETERS_OFFSET                 (u8) (1U)/* This define is used because the tables in C starts from 0 and not 1
                                                                    and the indexes in the specifications starts sometimes from 1 */

#define PROG_RTE_RESPONSE_BASE_INDEX                    PROG_MSG_BYTE_INDEX(2U)
#define PROG_RC_ROUTINE_STATUS_BASE_INDEX               PROG_MSG_BYTE_INDEX(5U)
#define PROG_RC_STATUS_RECORD_VERIF_RESULTS_BASE_INDEX  PROG_RC_ROUTINE_STATUS_BASE_INDEX
 
#define PROG_RC_STATUS_RECORD_VERIF_RESULTS_SIZE        6U
 
#define PROG_RC_STATUS_RECORD_VERIF_RESULTS_OK          1U
#define PROG_RC_STATUS_RECORD_VERIF_RESULTS_NOT_OK      2U

#define PROG_SBL_VALIDITY_FLAG_OFF                      120U
#define PROG_SBL_VALIDITY_FLAG                          0xAF5A50A5U

#define PROG_SBL_SOFTWARE_VERSION                       0x00000004U

#define PROG_ERASE_TYPE                                 PROG_ERASE_BY_ADDR
/* Data verification */
#define PROG_RANGE_CKS                                  STD_OFF
#define PROG_SEG_LIST_CKS                               STD_OFF
#define PROG_GET_EXPECTED_CRC_ENABLED                   STD_OFF
#define PROG_CRC_COMPUTE_COMPARE_ENABLE                 STD_OFF
#define PROG_VERIFICATION_ON_THE_FLY                    STD_ON
#define PROG_SIGNATURE_VERIFICATION_ON_FLASHED_DATA     STD_ON
#define PROG_CVN_CHECK                                  STD_OFF

#define PROG_DOWNLOAD_TYPE                              PROG_DOWNLOAD_BY_ADDR
#define PROG_MAX_RD_ADDRESS_LENGTH                      4U
/* Maximum Number of byte on which Block is coded in the Erase request */
#define PROG_MAX_BYTE_ERASE_BLOCK_LENGTH                1U

 [!IF "node:exists(as:modconf('Csm'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:87:IF4 osc_PROG main ', $project))"!][!ENDSELECT!]
/* !!!! To Be Generated once Csm stub will be available !!!!*/
#define PROG_CRY_PRESENT                                STD_ON
  [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:90:ELSE5 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CRY_PRESENT                                STD_OFF
  [!ENDIF!]
 [!IF "node:exists(as:modconf('CryShe'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:93:IF6 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CRYSHE_PRESENT                                STD_ON
  [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:95:ELSE7 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CRYSHE_PRESENT                                STD_OFF
  [!ENDIF!]
[!IF "node:exists(as:modconf('Cal'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:98:IF8 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CAL_PRESENT                                   STD_ON
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:100:ELSE9 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CAL_PRESENT                                   STD_OFF
[!ENDIF!]

/* specific routine result value */
#define PROG_ROUTINE_ACTIVE                             0x01U
#define PROG_ROUTINE_RESAVAILABLE                       0x02U
#define PROG_ROUTINE_PREDIF                             0x08U
#define PROG_ROUTINE_STOP_SUBFUNC                       0x10U
#define PROG_ROUTINE_RES_SUBFUNC                        0x20U
#define PROG_ROUTINE_SELFTERM                           0x40U
#define PROG_ROUTINE_AUTONOMOUS                         0x80U

#define PROG_APPL_VALID                                 0x00000002U
#define PROG_APPL_INVALID                               0x00000001U

#define PROG_AUTOCONTROL_POS_RESPONSE_SIZE              6U

/* Dynamic reconfiguration of TP parameters: BS and STmin */
#define PROG_UPDATE_TP_PARAM_ENABLE                     STD_OFF

#define PROG_GET_PROG_CNTR_ENABLE                       1U
#define PROG_GET_PROG_CNTR_DISABLE                      0U
#define PROG_CNTR_GET_TYPE                              PROG_GET_PROG_CNTR_DISABLE

/* Block Id in Fingerprint */
#define PROG_BLOCKID_IN_FINGERPRINT                     STD_OFF

#define PROG_DECOMP_FLASH_ROUTINES                      STD_OFF

#define PROG_SIGNATURE_CALCULATION_OVER_HASH            STD_OFF
#define PROG_COMPUTE_HASH_WITH_ADDR_LEN                 STD_OFF
#define PROG_RESUM_REPROG                               STD_OFF

#define PROG_REPROG_TYPE                                PROG_NO_REPROG_TYPE

#define PROG_CHECKVALIDATEAPPLICATION_POS_RESPONSE_SIZE 6U

 [!IF "(node:exists(as:modconf('Prog')/Security/ProgCsmSecureConfigId))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:138:IF10 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "not((as:modconf('BM')/Security/SecureBoot/SECURE_AUTHENTICATED_BOOT = 'OFF') and (as:modconf('Prog')/Security/Secure_Checksum_computation = 'false')) and
   (not(node:exists(as:modconf('BM')/Security/SecureBoot/BMSecureBootWithHsm)) or (as:modconf('BM')/Security/SecureBoot/BMSecureBootWithHsm = 'false')) "!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:140:IF11 osc_PROG main ', $project))"!][!ENDSELECT!]
 #define PROG_SECURE_CHECKSUM_SIZE_IN_BITS               [!"num:dectoint((as:modconf('BM')/Security/SecureBoot/CHECKSUM_LENGTH) * 8)"!]U
 #define PROG_SECURE_CHECKSUM_SIZE_IN_BYTES              [!"num:dectoint(as:modconf('BM')/Security/SecureBoot/CHECKSUM_LENGTH)"!]U

 [!IF "(not(node:exists(as:modconf('CryIf'))) and (contains(as:modconf('Prog')/Security/ProgCsmSecureConfigId, '/Csm/Csm/CsmHash/') =  'true')) or
     ((node:exists(as:modconf('CryIf'))) and (node:exists(node:ref(node:ref(as:modconf('Prog')/Security/ProgCsmSecureConfigId)/CsmJobPrimitiveRef)/CsmHash)) )"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:145:IF12 osc_PROG main ', $project))"!][!ENDSELECT!]
/* Secure Boot Algorithm used */
 #define PROG_CSM_SECURE_HASH_ID                         CSM_INDEX([!"name(as:ref(as:modconf('Prog')/Security/ProgCsmSecureConfigId))"!])
 #define PROG_CSM_HASH_USED                              STD_ON
 #define PROG_CSM_MAC_USED                               STD_OFF
 [!ELSEIF "(not(node:exists(as:modconf('CryIf'))) and (contains(as:modconf('Prog')/Security/ProgCsmSecureConfigId, '/Csm/Csm/CsmMacGenerate/') =  'true')) or
     ((node:exists(as:modconf('CryIf'))) and (node:exists(node:ref(node:ref(as:modconf('Prog')/Security/ProgCsmSecureConfigId)/CsmJobPrimitiveRef)/CsmMacGenerate)) )"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:151:ELSEIF13 osc_PROG main ', $project))"!][!ENDSELECT!]
/* Secure Boot Algorithm used */
#define PROG_CSM_SECURE_MAC_ID                          CSM_INDEX([!"name(as:ref(as:modconf('Prog')/Security/ProgCsmSecureConfigId))"!])
 #define PROG_CSM_HASH_USED                              STD_OFF
 #define PROG_CSM_MAC_USED                               STD_ON
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:156:ELSE14 osc_PROG main ', $project))"!][!ENDSELECT!]
 #define PROG_CSM_HASH_USED                              STD_OFF
 #define PROG_CSM_MAC_USED                               STD_OFF
 [!ENDIF!]
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:160:ELSE15 osc_PROG main ', $project))"!][!ENDSELECT!]
 #define PROG_CSM_HASH_USED                              STD_OFF
 #define PROG_CSM_MAC_USED                               STD_OFF
 [!ENDIF!]
  [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:164:ELSE16 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CSM_HASH_USED                              STD_OFF
#define PROG_CSM_MAC_USED                               STD_OFF
[!ENDIF!]
 [!IF "(as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL') or (as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='SBL') or 
       (as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='OneLevelBL') "!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:169:IF17 osc_PROG main ', $project))"!][!ENDSELECT!]
/* Macros to indicate operation type for the VDS table callback operations */
#define PROG_VDSUPDATE_CLEAR                            0U
#define PROG_VDSUPDATE_STORE                            1U
#define PROG_VDSUPDATE_GETSEGID_BYADR                   2U
#define PROG_VDSUPDATE_READVDS                          3U
  [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:175:DUMMYELSE18 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL_WITH_EB_FRAMEWORK'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:176:IF19 osc_PROG main ', $project))"!][!ENDSELECT!]
[!/********************* Feature configuration for JLR PBL with framework ************************/!]

#define PROG_IMPL_VARIANT           PROG_IMPL_1

#define PROG_WATCHDOG_ENABLE                            STD_ON
#define PROG_REQUEST_DOWNLOAD_ENABLE                    STD_ON
#define PROG_SECURITY_ENABLE                            STD_ON
#define PROG_SA_SEED_ENABLE                             STD_ON
#define PROG_SA_KEY_ENABLE                              STD_ON
#define PROG_ERASE_MEMORY_ENABLE                        STD_OFF
#define PROG_TRANSFER_DATA_ENABLE                       STD_ON
#define PROG_REQUEST_TRANSFER_EXIT_ENABLE               STD_ON
#define PROG_ECU_RESET_ENABLE                           STD_ON
#define PROG_ACTIVE_SBL_ENABLE                          STD_ON
#define PROG_UPDATE_PSI_ENABLE                          STD_OFF
#define PROG_CONTROL_DTC_SETTING_ENABLE                 STD_OFF
#define PROG_COMMUNICATION_CONTROL_ENABLE               STD_OFF
#define PROG_CHECK_MEMORY_ENABLE                        STD_OFF
#define PROG_CONTROL_FAIL_SAFE_REACTION_START_ENABLE    STD_OFF
#define PROG_CONTROL_FAIL_SAFE_REACTION_STOP_ENABLE     STD_OFF
#define PROG_CHECK_PROGRAMMING_DEPENDENCIES_ENABLE      STD_ON
#define PROG_NETWORK_MANAGEMENT_ENABLE                  STD_OFF
#define PROG_APPLI_CHECK_ON_S3TIMEOUT_ENABLE            STD_OFF
#define PROG_APPLI_CHECK_ENABLE                         STD_ON
#define PROG_RESPOND_TO_PROG_SESSION                    [!WS "20"!][!IF "General/Dsc_Prog_Response = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:201:IF20 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:201:ELSE21 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
#define PROG_PEC_ENABLE                                 STD_OFF
#define PROG_MULTIPLE_BUFFERS_ENABLE                    [!WS "20"!][!IF "as:modconf('BlPduR')/General/MultipleRxBuffer = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:203:IF22 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:203:ELSE23 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
#define PROG_BYPASS_SA_COMPARE_KEY                      [!WS "25"!][!IF "General/BypassSACompareKey = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:204:IF24 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:204:ELSE25 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]

#define PROG_SBL_HEADER_DEFINE                          STD_OFF

#define PROG_SWITCH_APPLICATION_MODE_ENABLE             STD_ON
#define PROG_CHECK_PROGRAMMING_REQUEST_ENABLE           STD_ON
#define PROG_CAL_CRC_ENABLE                             STD_ON
#define PROG_ACTIVE_SBL_RESPONSE_ENABLE                 STD_OFF
#define PROG_PRE_INIT_ENABLE                            STD_ON
#define PROG_EXTENDED_SESSION_MANAGED                   STD_OFF
#define PROG_ERASE_ALL                                  STD_OFF

#define PROG_ENABLE_DOWNGRADE_PROTECTION                STD_OFF

#define PROG_AUTHENTICATED_BOOT_ENABLE                  STD_OFF
#define PROG_BOOT_VERIFICATION                          STD_OFF
#define PROG_SECURE_BOOT_CHECKSUM_COMPUTATION           STD_OFF
#define PROG_SECURE_APPLI_CHECKSUM_COMPUTATION          STD_OFF
#define PROG_SINGLE_STEP_SIGNATURE_CHECK                STD_OFF

#define PROG_HASH_CALCULATION                           STD_OFF
#define PROG_SIGNATURE_CALCULATION                      STD_OFF

#define PROG_VERIFICATION_METHOD                        PROG_VERIFICATION_CRC
#define PROG_CRC_CALCULATION                            PROG_TD_CRC16

#define PROG_SLEEP_MANAGEMENT_TYPE [!WS "22"!][!IF "General/Sleep_Management_Type = 'Timeout'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:230:IF26 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_SLEEP_MANAGEMENT_TIMEOUT[!ELSEIF "General/Sleep_Management_Type = 'I/O'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:230:ELSEIF27 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_SLEEP_MANAGEMENT_IO[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:230:ELSE28 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_SLEEP_MANAGEMENT_OFF[!ENDIF!][!CR!]
[!IF "General/Sleep_Management_Type = 'Timeout'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:231:IF29 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SLEEP_TIMEOUT   [!WS "30"!]([!"num:dectoint(General/Sleep_Timeout)"!]U/PROG_MANAGE_PERIOD)
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:233:DUMMYELSE30 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
#define PROG_CURRENT_DIAG_APP        1U

#define PROG_FRAMEWORK_PARTID_1                         0xA5F0BBBBU
#define PROG_FRAMEWORK_PARTID_2                         0xA0F5CCCCU

#define PROG_BOOT_REPROG                                1U
#define PROG_BOOT_NOREPROG                              0U

#define PROG_CheckProgRequest()                         checkProgrammingRequest()
#define PROG_JumpToApplication()                        jumpToApplication()

[!ELSEIF "as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='SBL_WITH_EB_FRAMEWORK'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:245:ELSEIF31 osc_PROG main ', $project))"!][!ENDSELECT!]
[!/********************* Feature configuration for JLR SBL with framework ************************/!]
#define PROG_IMPL_VARIANT           PROG_IMPL_2

#define PROG_WATCHDOG_ENABLE                            STD_ON
#define PROG_REQUEST_DOWNLOAD_ENABLE                    STD_ON
#define PROG_SECURITY_ENABLE                            STD_ON
#define PROG_SA_SEED_ENABLE                             STD_ON
#define PROG_SA_KEY_ENABLE                              STD_ON
#define PROG_ERASE_MEMORY_ENABLE                        STD_ON
#define PROG_TRANSFER_DATA_ENABLE                       STD_ON
#define PROG_REQUEST_TRANSFER_EXIT_ENABLE               STD_ON
#define PROG_ECU_RESET_ENABLE                           STD_ON
#define PROG_ACTIVE_SBL_ENABLE                          STD_OFF
#define PROG_UPDATE_PSI_ENABLE                          STD_OFF
#define PROG_CONTROL_DTC_SETTING_ENABLE                 STD_OFF
#define PROG_COMMUNICATION_CONTROL_ENABLE               STD_OFF
#define PROG_CHECK_MEMORY_ENABLE                        STD_OFF
#define PROG_CONTROL_FAIL_SAFE_REACTION_START_ENABLE    STD_OFF
#define PROG_CONTROL_FAIL_SAFE_REACTION_STOP_ENABLE     STD_OFF
#define PROG_CHECK_PROGRAMMING_DEPENDENCIES_ENABLE      STD_ON
#define PROG_NETWORK_MANAGEMENT_ENABLE                  STD_OFF
#define PROG_APPLI_CHECK_ON_S3TIMEOUT_ENABLE            STD_OFF
#define PROG_APPLI_CHECK_ENABLE                         STD_ON
#define PROG_RESPOND_TO_PROG_SESSION                    [!WS "20"!][!IF "General/Dsc_Prog_Response = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:269:IF32 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:269:ELSE33 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
#define PROG_PEC_ENABLE                                 STD_OFF
#define PROG_MULTIPLE_BUFFERS_ENABLE                    [!WS "20"!][!IF "as:modconf('BlPduR')/General/MultipleRxBuffer = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:271:IF34 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:271:ELSE35 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
#define PROG_BYPASS_SA_COMPARE_KEY                      [!WS "25"!][!IF "General/BypassSACompareKey = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:272:IF36 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:272:ELSE37 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]

#define PROG_SBL_HEADER_DEFINE                          STD_ON

#define PROG_SWITCH_APPLICATION_MODE_ENABLE             STD_OFF
#define PROG_CHECK_PROGRAMMING_REQUEST_ENABLE           STD_OFF
#define PROG_CAL_CRC_ENABLE                             STD_ON
#define PROG_ACTIVE_SBL_RESPONSE_ENABLE                 STD_ON
#define PROG_PRE_INIT_ENABLE                            STD_ON
#define PROG_EXTENDED_SESSION_MANAGED                   STD_OFF
#define PROG_ERASE_ALL                                  STD_OFF
#define PROG_AUTHENTICATED_BOOT_ENABLE                  STD_OFF
#define PROG_BOOT_VERIFICATION                          STD_OFF
#define PROG_SECURE_BOOT_CHECKSUM_COMPUTATION           STD_OFF
#define PROG_SECURE_APPLI_CHECKSUM_COMPUTATION          STD_OFF
#define PROG_SINGLE_STEP_SIGNATURE_CHECK                STD_OFF

#define PROG_ENABLE_DOWNGRADE_PROTECTION                STD_OFF

#define PROG_HASH_CALCULATION                           STD_OFF
#define PROG_SIGNATURE_CALCULATION                      STD_OFF

#define PROG_VERIFICATION_METHOD                        PROG_VERIFICATION_CRC
#define PROG_CRC_CALCULATION                            PROG_TD_CRC16

#define PROG_SLEEP_MANAGEMENT_TYPE                      [!WS "22"!][!IF "General/Sleep_Management_Type = 'Timeout'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:297:IF38 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_SLEEP_MANAGEMENT_TIMEOUT[!ELSEIF "General/Sleep_Management_Type = 'I/O'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:297:ELSEIF39 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_SLEEP_MANAGEMENT_IO[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:297:ELSE40 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_SLEEP_MANAGEMENT_OFF[!ENDIF!][!CR!]
[!IF "General/Sleep_Management_Type = 'Timeout'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:298:IF41 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SLEEP_TIMEOUT                              [!WS "30"!]([!"num:dectoint(General/Sleep_Timeout)"!]U/PROG_MANAGE_PERIOD)
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:300:DUMMYELSE42 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
#define PROG_CURRENT_DIAG_APP                           2U

#define PROG_FRAMEWORK_PARTID_1                         0xA5F0BBBBU
#define PROG_FRAMEWORK_PARTID_2                         0xA0F5CCCCU
#define PROG_FLASH_PAGE_E_NOT_OK                        0U
#define PROG_FLASH_PAGE_E_OK                            1U
#define PROG_NO_SKIP_PAGE                               0U
#define PROG_SKIP_PAGE                                  1U

[!ELSEIF "as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:310:ELSEIF43 osc_PROG main ', $project))"!][!ENDSELECT!]
[!/********************* Feature configuration for JLR PBL ************************/!]

#define PROG_IMPL_VARIANT                               PROG_IMPL_3

#define PROG_WATCHDOG_ENABLE                            STD_ON
#define PROG_REQUEST_DOWNLOAD_ENABLE                    STD_ON
#define PROG_SECURITY_ENABLE                            STD_ON
#define PROG_SA_SEED_ENABLE                             STD_ON
#define PROG_SA_KEY_ENABLE                              STD_ON
#define PROG_ERASE_MEMORY_ENABLE                        STD_OFF
#define PROG_TRANSFER_DATA_ENABLE                       STD_ON
#define PROG_REQUEST_TRANSFER_EXIT_ENABLE               STD_ON
#define PROG_ECU_RESET_ENABLE                           STD_ON
#define PROG_ACTIVE_SBL_ENABLE                          STD_ON
#define PROG_UPDATE_PSI_ENABLE                          STD_OFF
#define PROG_CONTROL_DTC_SETTING_ENABLE                 STD_OFF
#define PROG_COMMUNICATION_CONTROL_ENABLE               STD_OFF
#define PROG_CHECK_MEMORY_ENABLE                        STD_OFF
#define PROG_CONTROL_FAIL_SAFE_REACTION_START_ENABLE    STD_OFF
#define PROG_CONTROL_FAIL_SAFE_REACTION_STOP_ENABLE     STD_OFF
#define PROG_CHECK_PROGRAMMING_DEPENDENCIES_ENABLE      STD_ON
#define PROG_NETWORK_MANAGEMENT_ENABLE                  STD_OFF
#define PROG_APPLI_CHECK_ON_S3TIMEOUT_ENABLE            STD_OFF
#define PROG_APPLI_CHECK_ENABLE                         STD_ON
#define PROG_RESPOND_TO_PROG_SESSION                    [!WS "20"!][!IF "General/Dsc_Prog_Response = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:335:IF44 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:335:ELSE45 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
#define PROG_PEC_ENABLE                                 STD_OFF
#define PROG_MULTIPLE_BUFFERS_ENABLE                    [!WS "20"!][!IF "as:modconf('BlPduR')/General/MultipleRxBuffer = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:337:IF46 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:337:ELSE47 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
#define PROG_BYPASS_SA_COMPARE_KEY                      [!WS "25"!][!IF "General/BypassSACompareKey = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:338:IF48 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:338:ELSE49 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]

#define PROG_SBL_HEADER_DEFINE                          STD_OFF

#define PROG_ENABLE_DOWNGRADE_PROTECTION                STD_OFF

#define PROG_SWITCH_APPLICATION_MODE_ENABLE             STD_ON
#define PROG_CHECK_PROGRAMMING_REQUEST_ENABLE           STD_ON
#define PROG_CAL_CRC_ENABLE                             STD_ON
#define PROG_ACTIVE_SBL_RESPONSE_ENABLE                 STD_OFF
#define PROG_PRE_INIT_ENABLE                            STD_ON
#define PROG_EXTENDED_SESSION_MANAGED                   STD_OFF
#define PROG_ERASE_ALL                                  STD_OFF
#define PROG_AUTHENTICATED_BOOT_ENABLE                  STD_OFF
#define PROG_BOOT_VERIFICATION                          STD_OFF
#define PROG_SECURE_BOOT_CHECKSUM_COMPUTATION           STD_OFF
[!IF "(node:exists(as:modconf('Prog')/Security/ProgCsmSecureConfigId))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:354:IF50 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "not((as:modconf('BM')/Security/SecureBoot/SECURE_AUTHENTICATED_BOOT = 'OFF') and (as:modconf('Prog')/Security/Secure_Checksum_computation = 'false'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:355:IF51 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SECURE_APPLI_CHECKSUM_COMPUTATION          STD_ON
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:357:ELSE52 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SECURE_APPLI_CHECKSUM_COMPUTATION          STD_OFF
 [!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:360:ELSE53 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SECURE_APPLI_CHECKSUM_COMPUTATION          STD_OFF
[!ENDIF!]
#define PROG_SINGLE_STEP_SIGNATURE_CHECK                 STD_ON

#define PROG_HASH_CALCULATION                            STD_ON
#define PROG_SIGNATURE_CALCULATION                       STD_ON

#define PROG_VERIFICATION_METHOD                         0xFFU

/* !!!! To Be Generated once Csm stub will be available !!!!*/
[!IF "node:exists(as:modconf('Csm'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:371:IF54 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "node:exists(as:modconf('CryIf'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:372:IF55 osc_PROG main ', $project))"!][!ENDSELECT!]
	[!VAR "AlgoMode" = "(as:ref(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId)/CsmJobPrimitiveRef)/CsmSignatureVerify/*/CsmSignatureVerifyAlgorithmMode)"!]
	[!VAR "Key_Length" = "(as:ref(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId)/CsmJobPrimitiveRef)/CsmSignatureVerify/*/CsmSignatureVerifyKeyLength)"!]
	[!VAR "Signature_Length" = "(as:ref(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId)/CsmJobPrimitiveRef)/CsmSignatureVerify/*/CsmSignatureVerifyCompareLength)"!]

/* Key Length shall be configured based on the value provided in the Csm job conf paramater- CsmSignatureVerifyKeyLength */
#define PROG_KEY_LENGTH                                    [!WS "34"!][!"$Key_Length"!]U /* In bytes */
/* Signature Length shall be configured based on the value provided in the Csm job conf paramater- CsmSignatureVerifyCompareLength */
#define PROG_SIGNATURE_LENGTH                              [!WS "28"!][!"$Signature_Length"!]U
    [!IF "$AlgoMode = 'CRYPTO_ALGOMODE_RSASSA_PSS'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:381:IF56 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CRY_EXPONENT_ENABLED                          STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:383:ELSE57 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CRY_EXPONENT_ENABLED                          STD_OFF
    [!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:386:ELSE58 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!IF "((as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId))/CsmSignatureVerifyPrimitiveName) = 'EdDSAVrfy'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:387:IF59 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_KEY_LENGTH                                    32U /* In bytes */
#define PROG_SIGNATURE_LENGTH                              64U
#define PROG_CRY_EXPONENT_ENABLED                          STD_OFF
	[!ELSEIF "((as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId))/CsmSignatureVerifyPrimitiveName) = 'RsaSsaPssVerify'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:391:ELSEIF60 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_KEY_LENGTH                                    256U /* In bytes */
#define PROG_SIGNATURE_LENGTH                              256U
#define PROG_CRY_EXPONENT_ENABLED                          STD_ON
	 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:395:ELSE61 osc_PROG main ', $project))"!][!ENDSELECT!]
/* Default Config for all the unsupported algorithms configured */
#define PROG_KEY_LENGTH                                    256U /* In bytes */
#define PROG_SIGNATURE_LENGTH                              256U
#define PROG_CRY_EXPONENT_ENABLED                          STD_OFF
	[!ENDIF!]
[!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:402:DUMMYELSE62 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

#define PROG_CRC_CALCULATION                            PROG_NO_CRC
 
#define PROG_RC_OPTION_RECORD_SIGNATURE_BASE_INDEX      PROG_MSG_BYTE_INDEX(5U)

#define PROG_SLEEP_MANAGEMENT_TYPE                      [!WS "22"!][!IF "General/Sleep_Management_Type = 'Timeout'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:408:IF63 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_SLEEP_MANAGEMENT_TIMEOUT[!ELSEIF "General/Sleep_Management_Type = 'I/O'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:408:ELSEIF64 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_SLEEP_MANAGEMENT_IO[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:408:ELSE65 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_SLEEP_MANAGEMENT_OFF[!ENDIF!][!CR!]
[!IF "General/Sleep_Management_Type = 'Timeout'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:409:IF66 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SLEEP_TIMEOUT                              [!WS "30"!]([!"num:dectoint(General/Sleep_Timeout)"!]U/PROG_MANAGE_PERIOD)
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:411:DUMMYELSE67 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
#define PROG_CURRENT_DIAG_APP                           1U

#define PROG_BOOT_REPROG                                1U
#define PROG_BOOT_NOREPROG                              0U

#define PROG_FRAMEWORK_PARTID_1                         0xA5F0BBBBU
#define PROG_FRAMEWORK_PARTID_2                         0xA0F5CCCCU
[!IF "not((as:modconf('BM')/Security/SecureBoot/SECURE_AUTHENTICATED_BOOT = 'OFF') and (as:modconf('Prog')/Security/Secure_Checksum_computation = 'false'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:419:IF68 osc_PROG main ', $project))"!][!ENDSELECT!]
  extern const tProg_BlockSecureBootInfo stCfgBlockSecureBootInfo[[!"num:dectoint(count(Segments/*))"!]];
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:421:DUMMYELSE69 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSEIF "as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='SBL'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:422:ELSEIF70 osc_PROG main ', $project))"!][!ENDSELECT!]
[!/********************* Feature configuration for JLR SBL ************************/!]
#define PROG_IMPL_VARIANT                               PROG_IMPL_4

#define PROG_WATCHDOG_ENABLE                            STD_ON
#define PROG_REQUEST_DOWNLOAD_ENABLE                    STD_ON
#define PROG_SECURITY_ENABLE                            STD_ON
#define PROG_SA_SEED_ENABLE                             STD_ON
#define PROG_SA_KEY_ENABLE                              STD_ON
#define PROG_ERASE_MEMORY_ENABLE                        STD_ON
#define PROG_TRANSFER_DATA_ENABLE                       STD_ON
#define PROG_REQUEST_TRANSFER_EXIT_ENABLE               STD_ON
#define PROG_ECU_RESET_ENABLE                           STD_ON
#define PROG_ACTIVE_SBL_ENABLE                          STD_OFF
#define PROG_UPDATE_PSI_ENABLE                          STD_OFF
#define PROG_CONTROL_DTC_SETTING_ENABLE                 STD_OFF
#define PROG_COMMUNICATION_CONTROL_ENABLE               STD_OFF
#define PROG_CHECK_MEMORY_ENABLE                        STD_OFF
#define PROG_SET_CRC_COMPARE_RESULT_ENABLE              STD_OFF
#define PROG_CONTROL_FAIL_SAFE_REACTION_START_ENABLE    STD_OFF
#define PROG_CONTROL_FAIL_SAFE_REACTION_STOP_ENABLE     STD_OFF
#define PROG_CHECK_PROGRAMMING_DEPENDENCIES_ENABLE      STD_ON
#define PROG_NETWORK_MANAGEMENT_ENABLE                  STD_OFF
#define PROG_APPLI_CHECK_ON_S3TIMEOUT_ENABLE            STD_OFF
#define PROG_APPLI_CHECK_ENABLE                         STD_ON
#define PROG_RESPOND_TO_PROG_SESSION                    [!WS "20"!][!IF "General/Dsc_Prog_Response = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:447:IF71 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:447:ELSE72 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
#define PROG_PEC_ENABLE                                 STD_OFF
#define PROG_MULTIPLE_BUFFERS_ENABLE                    [!WS "20"!][!IF "as:modconf('BlPduR')/General/MultipleRxBuffer = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:449:IF73 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:449:ELSE74 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
#define PROG_BYPASS_SA_COMPARE_KEY                      [!WS "25"!][!IF "General/BypassSACompareKey = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:450:IF75 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:450:ELSE76 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]

#define PROG_SBL_HEADER_DEFINE                          STD_ON

#define PROG_ENABLE_DOWNGRADE_PROTECTION                STD_OFF

#define PROG_SWITCH_APPLICATION_MODE_ENABLE             STD_OFF
#define PROG_CHECK_PROGRAMMING_REQUEST_ENABLE           STD_OFF
#define PROG_CAL_CRC_ENABLE                             STD_ON
#define PROG_ACTIVE_SBL_RESPONSE_ENABLE                 STD_ON
#define PROG_PRE_INIT_ENABLE                            STD_ON
#define PROG_EXTENDED_SESSION_MANAGED                   STD_OFF

#define PROG_ERASE_ALL                                  STD_OFF
#define PROG_AUTHENTICATED_BOOT_ENABLE                  STD_OFF
#define PROG_BOOT_VERIFICATION                          STD_OFF
#define PROG_SECURE_BOOT_CHECKSUM_COMPUTATION           STD_OFF
 [!IF "(node:exists(as:modconf('Prog')/Security/ProgCsmSecureConfigId))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:467:IF77 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "not((as:modconf('BM')/Security/SecureBoot/SECURE_AUTHENTICATED_BOOT = 'OFF') and (as:modconf('Prog')/Security/Secure_Checksum_computation = 'false'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:468:IF78 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SECURE_APPLI_CHECKSUM_COMPUTATION          STD_ON
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:470:ELSE79 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SECURE_APPLI_CHECKSUM_COMPUTATION          STD_OFF
 [!ENDIF!]
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:473:ELSE80 osc_PROG main ', $project))"!][!ENDSELECT!]
  #define PROG_SECURE_APPLI_CHECKSUM_COMPUTATION          STD_OFF
 [!ENDIF!]
#define PROG_SINGLE_STEP_SIGNATURE_CHECK                STD_ON
[!IF "(as:modconf('Prog')/Security/Submit_signature_request='With Address')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:477:IF81 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SUBMITSIGNATURE_WITH_ADDRESS               STD_ON
#define PROG_RC_OPTION_RECORD_HASH_TAB_ADD_BASE_INDEX   PROG_MSG_BYTE_INDEX(5U)
#define PROG_RC_OPTION_RECORD_SIGNATURE_BASE_INDEX      PROG_MSG_BYTE_INDEX(9U)
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:481:ELSE82 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SUBMITSIGNATURE_WITH_ADDRESS               STD_OFF
#define PROG_RC_OPTION_RECORD_SIGNATURE_BASE_INDEX      PROG_MSG_BYTE_INDEX(5U)
[!ENDIF!]

#define PROG_HASH_CALCULATION                           STD_ON
#define PROG_SIGNATURE_CALCULATION                      STD_ON

#define PROG_VERIFICATION_METHOD                        0xFFU

/* !!!! To Be Generated once Csm stub will be available !!!!*/
[!IF "node:exists(as:modconf('Csm'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:492:IF83 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "node:exists(as:modconf('CryIf'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:493:IF84 osc_PROG main ', $project))"!][!ENDSELECT!]
	[!VAR "AlgoMode" = "(as:ref(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId)/CsmJobPrimitiveRef)/CsmSignatureVerify/*/CsmSignatureVerifyAlgorithmMode)"!]
	[!VAR "Key_Length" = "(as:ref(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId)/CsmJobPrimitiveRef)/CsmSignatureVerify/*/CsmSignatureVerifyKeyLength)"!]
	[!VAR "Signature_Length" = "(as:ref(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId)/CsmJobPrimitiveRef)/CsmSignatureVerify/*/CsmSignatureVerifyCompareLength)"!]


/* Key Length shall be configured based on the value provided in the Csm job conf paramater- CsmSignatureVerifyKeyLength */
#define PROG_KEY_LENGTH                                    [!WS "34"!][!"$Key_Length"!]U /* In bytes */
/* Signature Length shall be configured based on the value provided in the Csm job conf paramater- CsmSignatureVerifyCompareLength */
#define PROG_SIGNATURE_LENGTH                              [!WS "28"!][!"$Signature_Length"!]U

    [!IF "$AlgoMode = 'CRYPTO_ALGOMODE_RSASSA_PSS'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:504:IF85 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CRY_EXPONENT_ENABLED                          STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:506:ELSE86 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CRY_EXPONENT_ENABLED                          STD_OFF
    [!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:509:ELSE87 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!IF "((as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId))/CsmSignatureVerifyPrimitiveName) = 'EdDSAVrfy'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:510:IF88 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_KEY_LENGTH                                    32U /* In bytes */
#define PROG_SIGNATURE_LENGTH                              64U
#define PROG_CRY_EXPONENT_ENABLED                          STD_OFF
	[!ELSEIF "((as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId))/CsmSignatureVerifyPrimitiveName) = 'RsaSsaPssVerify'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:514:ELSEIF89 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_KEY_LENGTH                                    256U /* In bytes */
#define PROG_SIGNATURE_LENGTH                              256U
#define PROG_CRY_EXPONENT_ENABLED                          STD_ON
	 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:518:ELSE90 osc_PROG main ', $project))"!][!ENDSELECT!]
/* Default Config for all the unsupported algorithms configured */
#define PROG_KEY_LENGTH                                    256U /* In bytes */
#define PROG_SIGNATURE_LENGTH                              256U
#define PROG_CRY_EXPONENT_ENABLED                          STD_OFF
	[!ENDIF!]
[!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:525:DUMMYELSE91 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

#define PROG_CRC_CALCULATION                            PROG_NO_CRC

#define PROG_SLEEP_MANAGEMENT_TYPE                      [!WS "22"!][!IF "General/Sleep_Management_Type = 'Timeout'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:529:IF92 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_SLEEP_MANAGEMENT_TIMEOUT[!ELSEIF "General/Sleep_Management_Type = 'I/O'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:529:ELSEIF93 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_SLEEP_MANAGEMENT_IO[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:529:ELSE94 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_SLEEP_MANAGEMENT_OFF[!ENDIF!][!CR!]
[!IF "General/Sleep_Management_Type = 'Timeout'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:530:IF95 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SLEEP_TIMEOUT                              [!WS "30"!]([!"num:dectoint(General/Sleep_Timeout)"!]U/PROG_MANAGE_PERIOD)
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:532:DUMMYELSE96 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
#define PROG_CURRENT_DIAG_APP                           2U

#define PROG_FRAMEWORK_PARTID_1                         0xA5F0BBBBU
#define PROG_FRAMEWORK_PARTID_2                         0xA0F5CCCCU

[!IF "not((as:modconf('BM')/Security/SecureBoot/SECURE_AUTHENTICATED_BOOT = 'OFF') and (as:modconf('Prog')/Security/Secure_Checksum_computation = 'false'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:538:IF97 osc_PROG main ', $project))"!][!ENDSELECT!]
extern const tProg_BlockSecureBootInfo stCfgBlockSecureBootInfo[[!"num:dectoint(count(Segments/*))"!]];
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:540:DUMMYELSE98 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!ELSEIF "as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='OneLevelBL'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:541:ELSEIF99 osc_PROG main ', $project))"!][!ENDSELECT!]
/* One Level Bootloader Architecture selected */
#define PROG_IMPL_VARIANT                               PROG_IMPL_5

#define PROG_WATCHDOG_ENABLE                            STD_ON
#define PROG_REQUEST_DOWNLOAD_ENABLE                    STD_ON
#define PROG_SECURITY_ENABLE                            STD_ON
#define PROG_SA_SEED_ENABLE                             STD_ON
#define PROG_SA_KEY_ENABLE                              STD_ON
#define PROG_ERASE_MEMORY_ENABLE                        STD_ON
#define PROG_TRANSFER_DATA_ENABLE                       STD_ON
#define PROG_REQUEST_TRANSFER_EXIT_ENABLE               STD_ON
#define PROG_ECU_RESET_ENABLE                           STD_ON
#define PROG_ACTIVE_SBL_ENABLE                          STD_OFF
#define PROG_UPDATE_PSI_ENABLE                          STD_OFF
#define PROG_CONTROL_DTC_SETTING_ENABLE                 STD_OFF
#define PROG_COMMUNICATION_CONTROL_ENABLE               STD_OFF
#define PROG_CHECK_MEMORY_ENABLE                        STD_OFF
#define PROG_CONTROL_FAIL_SAFE_REACTION_START_ENABLE    STD_OFF
#define PROG_CONTROL_FAIL_SAFE_REACTION_STOP_ENABLE     STD_OFF
#define PROG_CHECK_PROGRAMMING_DEPENDENCIES_ENABLE      STD_ON
#define PROG_NETWORK_MANAGEMENT_ENABLE                  STD_OFF
#define PROG_APPLI_CHECK_ON_S3TIMEOUT_ENABLE            STD_OFF
#define PROG_APPLI_CHECK_ENABLE                         STD_ON
#define PROG_RESPOND_TO_PROG_SESSION                    [!WS "20"!][!IF "General/Dsc_Prog_Response = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:565:IF100 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:565:ELSE101 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
#define PROG_PEC_ENABLE                                 STD_OFF
#define PROG_MULTIPLE_BUFFERS_ENABLE                    [!WS "20"!][!IF "as:modconf('BlPduR')/General/MultipleRxBuffer = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:567:IF102 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:567:ELSE103 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]
#define PROG_BYPASS_SA_COMPARE_KEY                      [!WS "25"!][!IF "General/BypassSACompareKey = 'true'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:568:IF104 osc_PROG main ', $project))"!][!ENDSELECT!]STD_ON[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:568:ELSE105 osc_PROG main ', $project))"!][!ENDSELECT!]STD_OFF[!ENDIF!][!CR!]

#define PROG_SBL_HEADER_DEFINE                          STD_OFF

#define PROG_ENABLE_DOWNGRADE_PROTECTION                STD_OFF

#define PROG_SWITCH_APPLICATION_MODE_ENABLE             STD_ON
#define PROG_CHECK_PROGRAMMING_REQUEST_ENABLE           STD_ON
#define PROG_CAL_CRC_ENABLE                             STD_ON
#define PROG_ACTIVE_SBL_RESPONSE_ENABLE                 STD_OFF
#define PROG_PRE_INIT_ENABLE                            STD_ON
#define PROG_EXTENDED_SESSION_MANAGED                   STD_OFF
#define PROG_ERASE_ALL                                  STD_OFF
#define PROG_AUTHENTICATED_BOOT_ENABLE                  STD_OFF
#define PROG_BOOT_VERIFICATION                          STD_OFF
#define PROG_SECURE_BOOT_CHECKSUM_COMPUTATION           STD_OFF
[!IF "(node:exists(as:modconf('Prog')/Security/ProgCsmSecureConfigId))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:584:IF106 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "not((as:modconf('BM')/Security/SecureBoot/SECURE_AUTHENTICATED_BOOT = 'OFF') and (as:modconf('Prog')/Security/Secure_Checksum_computation = 'false'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:585:IF107 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SECURE_APPLI_CHECKSUM_COMPUTATION          STD_ON
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:587:ELSE108 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SECURE_APPLI_CHECKSUM_COMPUTATION          STD_OFF
 [!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:590:ELSE109 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SECURE_APPLI_CHECKSUM_COMPUTATION          STD_OFF
[!ENDIF!]
#define PROG_SINGLE_STEP_SIGNATURE_CHECK                 STD_ON

#define PROG_HASH_CALCULATION                            STD_ON
#define PROG_SIGNATURE_CALCULATION                       STD_ON

#define PROG_VERIFICATION_METHOD                         0xFFU

/* !!!! To Be Generated once Csm stub will be available !!!!*/
[!IF "node:exists(as:modconf('Csm'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:601:IF110 osc_PROG main ', $project))"!][!ENDSELECT!]
[!IF "node:exists(as:modconf('CryIf'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:602:IF111 osc_PROG main ', $project))"!][!ENDSELECT!]
	[!VAR "AlgoMode" = "(as:ref(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId)/CsmJobPrimitiveRef)/CsmSignatureVerify/*/CsmSignatureVerifyAlgorithmMode)"!]
	[!VAR "Key_Length" = "(as:ref(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId)/CsmJobPrimitiveRef)/CsmSignatureVerify/*/CsmSignatureVerifyKeyLength)"!]
	[!VAR "Signature_Length" = "(as:ref(as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId)/CsmJobPrimitiveRef)/CsmSignatureVerify/*/CsmSignatureVerifyCompareLength)"!]

/* Key Length shall be configured based on the value provided in the Csm job conf paramater- CsmSignatureVerifyKeyLength */
#define PROG_KEY_LENGTH                                    [!WS "34"!][!"$Key_Length"!]U /* In bytes */
/* Signature Length shall be configured based on the value provided in the Csm job conf paramater- CsmSignatureVerifyCompareLength */
#define PROG_SIGNATURE_LENGTH                              [!WS "28"!][!"$Signature_Length"!]U
    [!IF "$AlgoMode = 'CRYPTO_ALGOMODE_RSASSA_PSS'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:611:IF112 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CRY_EXPONENT_ENABLED                          STD_ON
    [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:613:ELSE113 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_CRY_EXPONENT_ENABLED                          STD_OFF
    [!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:616:ELSE114 osc_PROG main ', $project))"!][!ENDSELECT!]
    [!IF "((as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId))/CsmSignatureVerifyPrimitiveName) = 'EdDSAVrfy'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:617:IF115 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_KEY_LENGTH                                    32U /* In bytes */
#define PROG_SIGNATURE_LENGTH                              64U
#define PROG_CRY_EXPONENT_ENABLED                          STD_OFF
	[!ELSEIF "((as:ref(as:modconf('Prog')/Security/ProgCsmReferences/SignatureVerification/ProgCsmSignatureVerifyConfigId))/CsmSignatureVerifyPrimitiveName) = 'RsaSsaPssVerify'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:621:ELSEIF116 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_KEY_LENGTH                                    256U /* In bytes */
#define PROG_SIGNATURE_LENGTH                              256U
#define PROG_CRY_EXPONENT_ENABLED                          STD_ON
	 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:625:ELSE117 osc_PROG main ', $project))"!][!ENDSELECT!]
/* Default Config for all the unsupported algorithms configured */
#define PROG_KEY_LENGTH                                    256U /* In bytes */
#define PROG_SIGNATURE_LENGTH                              256U
#define PROG_CRY_EXPONENT_ENABLED                          STD_OFF
	[!ENDIF!]
[!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:632:DUMMYELSE118 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

#define PROG_CRC_CALCULATION                            PROG_NO_CRC

#define PROG_SLEEP_MANAGEMENT_TYPE                      [!WS "22"!][!IF "General/Sleep_Management_Type = 'Timeout'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:636:IF119 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_SLEEP_MANAGEMENT_TIMEOUT[!ELSEIF "General/Sleep_Management_Type = 'I/O'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:636:ELSEIF120 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_SLEEP_MANAGEMENT_IO[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:636:ELSE121 osc_PROG main ', $project))"!][!ENDSELECT!]PROG_SLEEP_MANAGEMENT_OFF[!ENDIF!][!CR!]
[!IF "General/Sleep_Management_Type = 'Timeout'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:637:IF122 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SLEEP_TIMEOUT                              [!WS "30"!]([!"num:dectoint(General/Sleep_Timeout)"!]U/PROG_MANAGE_PERIOD)
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:639:DUMMYELSE123 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
#define PROG_CURRENT_DIAG_APP                           1U

#define PROG_BOOT_REPROG                                1U
#define PROG_BOOT_NOREPROG                              0U

#define PROG_FRAMEWORK_PARTID_1                         0xA5F0BBBBU
#define PROG_FRAMEWORK_PARTID_2                         0xA0F5CCCCU
 [!IF "not((as:modconf('BM')/Security/SecureBoot/SECURE_AUTHENTICATED_BOOT = 'OFF') and (as:modconf('Prog')/Security/Secure_Checksum_computation = 'false'))"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:647:IF124 osc_PROG main ', $project))"!][!ENDSELECT!]
extern const tProg_BlockSecureBootInfo stCfgBlockSecureBootInfo[[!"num:dectoint(count(Segments/*))"!]];
 [!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:649:DUMMYELSE125 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]
[!IF "(as:modconf('Prog')/Security/Submit_signature_request='With Address')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:650:IF126 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SUBMITSIGNATURE_WITH_ADDRESS               STD_ON
#define PROG_RC_OPTION_RECORD_HASH_TAB_ADD_BASE_INDEX   PROG_MSG_BYTE_INDEX(5U)
#define PROG_RC_OPTION_RECORD_SIGNATURE_BASE_INDEX      PROG_MSG_BYTE_INDEX(9U)
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:654:ELSE127 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_SUBMITSIGNATURE_WITH_ADDRESS               STD_OFF
#define PROG_RC_OPTION_RECORD_SIGNATURE_BASE_INDEX      PROG_MSG_BYTE_INDEX(5U)
[!ENDIF!]
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:658:ELSE128 osc_PROG main ', $project))"!][!ENDSELECT!]
[!ERROR "The JLR variant configured in ProgJLR is unknown"!]
[!ENDIF!][!/* as:modconf('ProgJLR')/General/PROG_JLR_VARIANT='PBL_WITH_EB_FRAMEWORK'' */!]

/* Security access limit request seed */
[!IF "(as:modconf('SA')/General/Enable_Request_Seed_Limit = 'true')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:663:IF129 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_LIMIT_NB_REQUEST_SEED_ENABLED              STD_ON
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:665:ELSE130 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_LIMIT_NB_REQUEST_SEED_ENABLED              STD_OFF
[!ENDIF!]

/*Use of StartAddress - EndAddress instead of StartAddress-Length*/
#define PROG_USE_START_ADDR_END_ADDR                    STD_OFF
/*Programming Status usage*/
#define PROG_REQ_PROGRAMMING_STATUS_ENABLE              STD_OFF
/*Security access antiscanning*/
[!IF "(as:modconf('SA')/General/Enable_Antiscanning = 'true')"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:674:IF131 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_ANTISCANNING_ENABLED                       STD_ON
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:676:ELSE132 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_ANTISCANNING_ENABLED                       STD_OFF
[!ENDIF!]

/*Enable the response after reset in function of reset cause*/
#define PROG_RESET_CAUSE_ENABLE                         STD_OFF
/* Programming pre-conditions check */
#define PROG_PRECOND_CHECK_ENABLE                       STD_OFF

/*Use Coherency check*/
#define PROG_COHERENCY_CHECK_ENABLE                     STD_OFF

/* Use Programming counter */
#define PROG_PROGRAMMING_CNTR_ENABLE                    STD_OFF

/* Use partial checksum verification */
#define PROG_PARTIAL_VERIFY_CRC                         STD_OFF

#define PROG_USE_ECUID_CALLBACK                         STD_OFF

/* Define if NRC78 shall be sent before SecurityAccess */
#define PROG_NRC78_ON_SA_ENABLE                         STD_OFF

[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:699:DUMMYELSE133 osc_PROG main ', $project))"!][!ENDSELECT!][!ENDIF!]

/* Downloading Flash driver feature activation */
#define PROG_DOWNLOAD_FLASH_ROUTINES_ENABLE             STD_OFF

/*Securiy access request seed delay timer*/
[!IF "as:modconf('SA')/General/Security_Access_Rs_Delay_Timer != '0'"!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:705:IF134 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_REQUEST_SEED_DELAY_TIMER_ENABLED            STD_ON
[!ELSE!][!SELECT "asc:writeToFile('coverage_gen.log', concat('Prog_TS_TxDxM2I43R0/generate/include/PROG_Cfg_Impl0.h:707:ELSE135 osc_PROG main ', $project))"!][!ENDSELECT!]
#define PROG_REQUEST_SEED_DELAY_TIMER_ENABLED            STD_OFF
[!ENDIF!]

/*Introduced below the compiler switch to support Fingerprint for the Segments in RAM*/
#ifndef PROG_RAMSEG_FINGERPRINT_SUPPORT
#define PROG_RAMSEG_FINGERPRINT_SUPPORT                 STD_OFF
#endif

#ifndef PROG_SUBMITSIGNATURE_WITH_ADDRESS
#define PROG_SUBMITSIGNATURE_WITH_ADDRESS               STD_OFF
#endif

#endif /* PROG_CFG_IMPL0_H */
