
#ifndef PROG_HSMPROGINT_H
#define PROG_HSMPROGINT_H

/* --------{ EB Automotive C Source File }-------- */

/* Internal interface for the PROG state
 * machine.
 *
 * This header must only be included by
 * PROG_HsmPROGData.c and PROG_HsmPROGFnct.c.
 */

/* CHECK: RULE 301 OFF (this file is generated, some lines may be longer then
 * 100 characters) */
/* CHECK: RULE 505 OFF (Type definitions may not start with 't') */


/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

/* include state machine driver interface */
#include <PROG_Hsm.h>

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/* *** State indices and IDs for states *** */
typedef enum
{
  PROG_HSM_PROG_SIDX_TOP,
  PROG_HSM_PROG_SIDX_ALIVE,
  PROG_HSM_PROG_SIDX_CHECK_MEMORY_TOP,
  PROG_HSM_PROG_SIDX_BLU_PRE_RESET,
  PROG_HSM_PROG_SIDX_BLU_RESUME,
  PROG_HSM_PROG_SIDX_CHECK_MEMORY,
  PROG_HSM_PROG_SIDX_CHECK_MEMORY_FINISH,
  PROG_HSM_PROG_SIDX_SIGNATURE_CHECK,
  PROG_HSM_PROG_SIDX_COHERENCY_CHECK_TOP,
  PROG_HSM_PROG_SIDX_COHERENCY_CHECK,
  PROG_HSM_PROG_SIDX_COHERENCY_CHECK_FINISH,
  PROG_HSM_PROG_SIDX_COMPARE_KEY,
  PROG_HSM_PROG_SIDX_DEFAULT_SESSION,
  PROG_HSM_PROG_SIDX_ECU_RESET,
  PROG_HSM_PROG_SIDX_ERASE_TOP,
  PROG_HSM_PROG_SIDX_ERASE,
  PROG_HSM_PROG_SIDX_ERASE_CHECK,
  PROG_HSM_PROG_SIDX_ERASE_FINISH,
  PROG_HSM_PROG_SIDX_ERASE_NRC78,
  PROG_HSM_PROG_SIDX_ERASE_TRANSMITNRC78,
  PROG_HSM_PROG_SIDX_EXT_SESSION,
  PROG_HSM_PROG_SIDX_GET_SEED,
  PROG_HSM_PROG_SIDX_INIT,
  PROG_HSM_PROG_SIDX_LOCKED,
  PROG_HSM_PROG_SIDX_PROG_SESSION,
  PROG_HSM_PROG_SIDX_REPROG,
  PROG_HSM_PROG_SIDX_RD_TOP,
  PROG_HSM_PROG_SIDX_RD,
  PROG_HSM_PROG_SIDX_RD_FINISH,
  PROG_HSM_PROG_SIDX_RD_SIGNATURE,
  PROG_HSM_PROG_SIDX_RTE_TOP,
  PROG_HSM_PROG_SIDX_RTE,
  PROG_HSM_PROG_SIDX_RTE_DECOMP,
  PROG_HSM_PROG_SIDX_RTE_DECOMP_FINISH,
  PROG_HSM_PROG_SIDX_RTE_DECOMP_WRITE,
  PROG_HSM_PROG_SIDX_RTE_DECOMP_WRITE_CHECK,
  PROG_HSM_PROG_SIDX_RTE_DECRYPT,
  PROG_HSM_PROG_SIDX_RTE_DECRYPT_FINISH,
  PROG_HSM_PROG_SIDX_RTE_WRITE,
  PROG_HSM_PROG_SIDX_RTE_WRITE_CHECK,
  PROG_HSM_PROG_SIDX_RTE_FAILED,
  PROG_HSM_PROG_SIDX_RTE_FINISH,
  PROG_HSM_PROG_SIDX_TD_TOP,
  PROG_HSM_PROG_SIDX_TD,
  PROG_HSM_PROG_SIDX_TD_CRC,
  PROG_HSM_PROG_SIDX_TD_FAILED,
  PROG_HSM_PROG_SIDX_TD_STREAMING,
  PROG_HSM_PROG_SIDX_TD_WRITE,
  PROG_HSM_PROG_SIDX_DECRYPT_FINISH,
  PROG_HSM_PROG_SIDX_DECRYPT_UPDATE,
  PROG_HSM_PROG_SIDX_WRITE,
  PROG_HSM_PROG_SIDX_WRITE_CHECK,
  PROG_HSM_PROG_SIDX_RESET,
  PROG_HSM_PROG_SIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP,
  PROG_HSM_PROG_SIDX_VERIFY_PARTIAL_SW_CHECKSUM,
  PROG_HSM_PROG_SIDX_VERIFY_PARTIAL_SW_CHECKSUM_FINISH,
  PROG_HSM_PROG_SIDX_WRITE_FINGERPRINT,
  PROG_HSM_PROG_SIDX_WFP_FINISHED,
  PROG_HSM_PROG_SIDX_WFP_INPROGRESS,
  PROG_HSM_PROG_SIDX_PRE_INIT,
  PROG_HSM_PROG_SIDX_SLEEP,
  PROG_HSM_PROG_NO_OF_STATES
} PROG_HsmPROGStateIdType;
/* typedefed type only used for debugging */

/* *** IDs for entry/do/exit and transition actions *** */
typedef enum
{
  PROG_HSM_PROG_AIDX_ALIVE_ACTION_5,
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_TOP_ACTION_1,
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_TOP_ACTION_2,
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_TOP_ACTION_4,
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_TOP_ACTION_5,
  PROG_HSM_PROG_AIDX_BLU_PRE_RESET_ENTRY,
  PROG_HSM_PROG_AIDX_BLU_RESUME_ENTRY,
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_ENTRY,
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_DO,
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_ACTION_2,
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_ACTION_3,
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_FINISH_ENTRY,
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_FINISH_EXIT,
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_FINISH_ACTION_1,
  PROG_HSM_PROG_AIDX_SIGNATURE_CHECK_ENTRY,
  PROG_HSM_PROG_AIDX_SIGNATURE_CHECK_EXIT,
  PROG_HSM_PROG_AIDX_COHERENCY_CHECK_TOP_ACTION_1,
  PROG_HSM_PROG_AIDX_COHERENCY_CHECK_TOP_ACTION_3,
  PROG_HSM_PROG_AIDX_COHERENCY_CHECK_TOP_ACTION_6,
  PROG_HSM_PROG_AIDX_COHERENCY_CHECK_TOP_ACTION_7,
  PROG_HSM_PROG_AIDX_COHERENCY_CHECK_DO,
  PROG_HSM_PROG_AIDX_COHERENCY_CHECK_FINISH_ACTION_1,
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ENTRY,
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ACTION_1,
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ACTION_2,
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ACTION_3,
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ACTION_4,
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ACTION_5,
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ACTION_7,
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ACTION_8,
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ACTION_9,
  PROG_HSM_PROG_AIDX_DEFAULT_SESSION_ENTRY,
  PROG_HSM_PROG_AIDX_ECU_RESET_ENTRY,
  PROG_HSM_PROG_AIDX_ERASE_TOP_ACTION_1,
  PROG_HSM_PROG_AIDX_ERASE_TOP_ACTION_2,
  PROG_HSM_PROG_AIDX_ERASE_TOP_ACTION_3,
  PROG_HSM_PROG_AIDX_ERASE_TOP_ACTION_4,
  PROG_HSM_PROG_AIDX_ERASE_TOP_ACTION_5,
  PROG_HSM_PROG_AIDX_ERASE_TOP_ACTION_6,
  PROG_HSM_PROG_AIDX_ERASE_TOP_ACTION_7,
  PROG_HSM_PROG_AIDX_ERASE_TOP_ACTION_8,
  PROG_HSM_PROG_AIDX_ERASE_ENTRY,
  PROG_HSM_PROG_AIDX_ERASE_DO,
  PROG_HSM_PROG_AIDX_ERASE_CHECK_ENTRY,
  PROG_HSM_PROG_AIDX_ERASE_FINISH_ENTRY,
  PROG_HSM_PROG_AIDX_ERASE_NRC78_ENTRY,
  PROG_HSM_PROG_AIDX_ERASE_TRANSMITNRC78_ENTRY,
  PROG_HSM_PROG_AIDX_EXT_SESSION_ENTRY,
  PROG_HSM_PROG_AIDX_GET_SEED_ENTRY,
  PROG_HSM_PROG_AIDX_GET_SEED_ACTION_1,
  PROG_HSM_PROG_AIDX_GET_SEED_ACTION_2,
  PROG_HSM_PROG_AIDX_GET_SEED_ACTION_4,
  PROG_HSM_PROG_AIDX_GET_SEED_ACTION_5,
  PROG_HSM_PROG_AIDX_GET_SEED_ACTION_6,
  PROG_HSM_PROG_AIDX_INIT_ENTRY,
  PROG_HSM_PROG_AIDX_INIT_EXIT,
  PROG_HSM_PROG_AIDX_LOCKED_ACTION_1,
  PROG_HSM_PROG_AIDX_LOCKED_ACTION_2,
  PROG_HSM_PROG_AIDX_LOCKED_ACTION_3,
  PROG_HSM_PROG_AIDX_LOCKED_ACTION_5,
  PROG_HSM_PROG_AIDX_LOCKED_ACTION_6,
  PROG_HSM_PROG_AIDX_PROG_SESSION_ENTRY,
  PROG_HSM_PROG_AIDX_PROG_SESSION_ACTION_2,
  PROG_HSM_PROG_AIDX_PROG_SESSION_ACTION_3,
  PROG_HSM_PROG_AIDX_PROG_SESSION_ACTION_4,
  PROG_HSM_PROG_AIDX_PROG_SESSION_ACTION_6,
  PROG_HSM_PROG_AIDX_PROG_SESSION_ACTION_7,
  PROG_HSM_PROG_AIDX_REPROG_ACTION_1,
  PROG_HSM_PROG_AIDX_REPROG_ACTION_2,
  PROG_HSM_PROG_AIDX_REPROG_ACTION_3,
  PROG_HSM_PROG_AIDX_REPROG_ACTION_4,
  PROG_HSM_PROG_AIDX_REPROG_ACTION_5,
  PROG_HSM_PROG_AIDX_REPROG_ACTION_6,
  PROG_HSM_PROG_AIDX_REPROG_ACTION_7,
  PROG_HSM_PROG_AIDX_RD_TOP_ACTION_1,
  PROG_HSM_PROG_AIDX_RD_TOP_ACTION_2,
  PROG_HSM_PROG_AIDX_RD_TOP_ACTION_3,
  PROG_HSM_PROG_AIDX_RD_ENTRY,
  PROG_HSM_PROG_AIDX_RD_FINISH_ENTRY,
  PROG_HSM_PROG_AIDX_RD_SIGNATURE_ENTRY,
  PROG_HSM_PROG_AIDX_RTE_TOP_ACTION_1,
  PROG_HSM_PROG_AIDX_RTE_TOP_ACTION_2,
  PROG_HSM_PROG_AIDX_RTE_ENTRY,
  PROG_HSM_PROG_AIDX_RTE_DO,
  PROG_HSM_PROG_AIDX_RTE_DECOMP_EXIT,
  PROG_HSM_PROG_AIDX_RTE_DECOMP_FINISH_ENTRY,
  PROG_HSM_PROG_AIDX_RTE_DECOMP_WRITE_ENTRY,
  PROG_HSM_PROG_AIDX_RTE_DECOMP_WRITE_DO,
  PROG_HSM_PROG_AIDX_RTE_DECOMP_WRITE_CHECK_ENTRY,
  PROG_HSM_PROG_AIDX_RTE_DECRYPT_EXIT,
  PROG_HSM_PROG_AIDX_RTE_DECRYPT_FINISH_ENTRY,
  PROG_HSM_PROG_AIDX_RTE_DECRYPT_FINISH_DO,
  PROG_HSM_PROG_AIDX_RTE_WRITE_ENTRY,
  PROG_HSM_PROG_AIDX_RTE_WRITE_DO,
  PROG_HSM_PROG_AIDX_RTE_WRITE_CHECK_DO,
  PROG_HSM_PROG_AIDX_RTE_FAILED_ENTRY,
  PROG_HSM_PROG_AIDX_RTE_FAILED_ACTION_1,
  PROG_HSM_PROG_AIDX_RTE_FINISH_ENTRY,
  PROG_HSM_PROG_AIDX_RTE_FINISH_ACTION_2,
  PROG_HSM_PROG_AIDX_TD_TOP_ACTION_2,
  PROG_HSM_PROG_AIDX_TD_TOP_ACTION_3,
  PROG_HSM_PROG_AIDX_TD_ENTRY,
  PROG_HSM_PROG_AIDX_TD_CRC_DO,
  PROG_HSM_PROG_AIDX_TD_CRC_ACTION_1,
  PROG_HSM_PROG_AIDX_TD_FAILED_ENTRY,
  PROG_HSM_PROG_AIDX_TD_STREAMING_ENTRY,
  PROG_HSM_PROG_AIDX_TD_WRITE_EXIT,
  PROG_HSM_PROG_AIDX_TD_WRITE_ACTION_1,
  PROG_HSM_PROG_AIDX_TD_WRITE_ACTION_2,
  PROG_HSM_PROG_AIDX_DECRYPT_FINISH_ENTRY,
  PROG_HSM_PROG_AIDX_DECRYPT_FINISH_DO,
  PROG_HSM_PROG_AIDX_DECRYPT_UPDATE_ENTRY,
  PROG_HSM_PROG_AIDX_DECRYPT_UPDATE_DO,
  PROG_HSM_PROG_AIDX_WRITE_ENTRY,
  PROG_HSM_PROG_AIDX_WRITE_DO,
  PROG_HSM_PROG_AIDX_WRITE_CHECK_DO,
  PROG_HSM_PROG_AIDX_RESET_ENTRY,
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_EXIT,
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_ACTION_1,
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_ACTION_3,
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_ACTION_6,
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_ACTION_7,
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_ACTION_8,
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_ENTRY,
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_DO,
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_ACTION_1,
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_ACTION_2,
  PROG_HSM_PROG_AIDX_WRITE_FINGERPRINT_ACTION_1,
  PROG_HSM_PROG_AIDX_WRITE_FINGERPRINT_ACTION_2,
  PROG_HSM_PROG_AIDX_WRITE_FINGERPRINT_ACTION_3,
  PROG_HSM_PROG_AIDX_WRITE_FINGERPRINT_ACTION_4,
  PROG_HSM_PROG_AIDX_WRITE_FINGERPRINT_ACTION_6,
  PROG_HSM_PROG_AIDX_WRITE_FINGERPRINT_ACTION_7,
  PROG_HSM_PROG_AIDX_WFP_INPROGRESS_ENTRY,
  PROG_HSM_PROG_AIDX_WFP_INPROGRESS_DO,
  PROG_HSM_PROG_AIDX_PRE_INIT_ENTRY,
  PROG_HSM_PROG_AIDX_PRE_INIT_DO,
  PROG_HSM_PROG_AIDX_SLEEP_ENTRY,
  PROG_HSM_PROG_NO_OF_ACTIONS
} PROG_HsmPROGActionIdType;
/* typedefed type only used for debugging */

/* *** IDs for guards *** */
typedef enum
{
  PROG_HSM_PROG_GIDX_CHECK_MEMORY_FINISH_GUARD_3,
  PROG_HSM_PROG_GIDX_CHECK_MEMORY_FINISH_GUARD_4,
  PROG_HSM_PROG_GIDX_COHERENCY_CHECK_TOP_GUARD_2,
  PROG_HSM_PROG_GIDX_COHERENCY_CHECK_TOP_GUARD_5,
  PROG_HSM_PROG_GIDX_ERASE_FINISH_GUARD_1,
  PROG_HSM_PROG_GIDX_ERASE_FINISH_GUARD_2,
  PROG_HSM_PROG_GIDX_RTE_FAILED_GUARD_2,
  PROG_HSM_PROG_GIDX_RTE_FAILED_GUARD_3,
  PROG_HSM_PROG_GIDX_RTE_FINISH_GUARD_3,
  PROG_HSM_PROG_GIDX_TD_FAILED_GUARD_1,
  PROG_HSM_PROG_GIDX_TD_FAILED_GUARD_2,
  PROG_HSM_PROG_GIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_GUARD_4,
  PROG_HSM_PROG_GIDX_WFP_FINISHED_GUARD_1,
  PROG_HSM_PROG_GIDX_WFP_FINISHED_GUARD_2,
  PROG_HSM_PROG_NO_OF_GUARDS
} PROG_HsmPROGGuardIdType;
/* typedefed type only used for debugging */

/*==================[external function declarations]========================*/

#define PROG_START_SEC_CODE
#include <MemMap.h>

/* function declarations of state entry, exit, guard, action functions
 * defined in PROG_fnct.c */


/* implements action '(void)PROG_CheckProgrammingPreCondition();' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfALIVEAction5(
  PROG_PDL_SF(const uint8 instIdx));

/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCHECK_MEMORY_TOPAction1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_GetSeed_Unlocked();' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCHECK_MEMORY_TOPAction2(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCHECK_MEMORY_TOPAction4(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCHECK_MEMORY_TOPAction5(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfBLU_PRE_RESETEntry(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfBLU_RESUMEEntry(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCHECK_MEMORYEntry(
  PROG_PDL_SF(const uint8 instIdx));
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCHECK_MEMORYDo(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_CheckSegmentListCrc();' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCHECK_MEMORYAction2(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action '(void)PROG_CRC_Compare();' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCHECK_MEMORYAction3(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCHECK_MEMORY_FINISHEntry(
  PROG_PDL_SF(const uint8 instIdx));
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCHECK_MEMORY_FINISHExit(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_AnswerSuccesiveCheckMemoryRequests();' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCHECK_MEMORY_FINISHAction1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements guard '(PROG_E_OK==PROG_Erase_Guard())' */
extern FUNC(boolean, PROG_CODE)
 PROG_HsmPROGSfCHECK_MEMORY_FINISHGuard3(
  PROG_PDL_SF(const uint8 instIdx));
/* implements guard '(PROG_E_OK==PROG_RD_Check())' */
extern FUNC(boolean, PROG_CODE)
 PROG_HsmPROGSfCHECK_MEMORY_FINISHGuard4(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfSIGNATURE_CHECKEntry(
  PROG_PDL_SF(const uint8 instIdx));
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfSIGNATURE_CHECKExit(
  PROG_PDL_SF(const uint8 instIdx));

/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCOHERENCY_CHECK_TOPAction1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements guard '(PROG_E_OK==PROG_Erase_Guard())' */
extern FUNC(boolean, PROG_CODE)
 PROG_HsmPROGSfCOHERENCY_CHECK_TOPGuard2(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_GetSeed_Unlocked();' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCOHERENCY_CHECK_TOPAction3(
  PROG_PDL_SF(const uint8 instIdx));
/* implements guard '(PROG_E_OK==PROG_RD_Check())' */
extern FUNC(boolean, PROG_CODE)
 PROG_HsmPROGSfCOHERENCY_CHECK_TOPGuard5(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCOHERENCY_CHECK_TOPAction6(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCOHERENCY_CHECK_TOPAction7(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCOHERENCY_CHECKDo(
  PROG_PDL_SF(const uint8 instIdx));

/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCOHERENCY_CHECK_FINISHAction1(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCOMPARE_KEYEntry(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCOMPARE_KEYAction1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCOMPARE_KEYAction2(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCOMPARE_KEYAction3(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCOMPARE_KEYAction4(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_GetSeed_Unlocked();' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCOMPARE_KEYAction5(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_22);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCOMPARE_KEYAction7(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCOMPARE_KEYAction8(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfCOMPARE_KEYAction9(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfDEFAULT_SESSIONEntry(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfECU_RESETEntry(
  PROG_PDL_SF(const uint8 instIdx));

/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfERASE_TOPAction1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfERASE_TOPAction2(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfERASE_TOPAction3(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_GetSeed_Unlocked();' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfERASE_TOPAction4(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfERASE_TOPAction5(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfERASE_TOPAction6(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfERASE_TOPAction7(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_22);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfERASE_TOPAction8(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfERASEEntry(
  PROG_PDL_SF(const uint8 instIdx));
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfERASEDo(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfERASE_CHECKEntry(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfERASE_FINISHEntry(
  PROG_PDL_SF(const uint8 instIdx));
/* implements guard '(PROG_E_OK==PROG_Guard_Erase_Check_EraseFinish())' */
extern FUNC(boolean, PROG_CODE)
 PROG_HsmPROGSfERASE_FINISHGuard1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements guard '(PROG_E_OK==PROG_RD_Check())' */
extern FUNC(boolean, PROG_CODE)
 PROG_HsmPROGSfERASE_FINISHGuard2(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfERASE_NRC78Entry(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfERASE_TRANSMITNRC78Entry(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfEXT_SESSIONEntry(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfGET_SEEDEntry(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfGET_SEEDAction1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfGET_SEEDAction2(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Entry_GetSeed();' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfGET_SEEDAction4(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfGET_SEEDAction5(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfGET_SEEDAction6(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfINITEntry(
  PROG_PDL_SF(const uint8 instIdx));
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfINITExit(
  PROG_PDL_SF(const uint8 instIdx));

/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfLOCKEDAction1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfLOCKEDAction2(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfLOCKEDAction3(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfLOCKEDAction5(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfLOCKEDAction6(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfPROG_SESSIONEntry(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfPROG_SESSIONAction2(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfPROG_SESSIONAction3(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfPROG_SESSIONAction4(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfPROG_SESSIONAction6(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfPROG_SESSIONAction7(
  PROG_PDL_SF(const uint8 instIdx));

/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfREPROGAction1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfREPROGAction2(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfREPROGAction3(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfREPROGAction4(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfREPROGAction5(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfREPROGAction6(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_22);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfREPROGAction7(
  PROG_PDL_SF(const uint8 instIdx));

/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRD_TOPAction1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRD_TOPAction2(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRD_TOPAction3(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRDEntry(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRD_FINISHEntry(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRD_SIGNATUREEntry(
  PROG_PDL_SF(const uint8 instIdx));

/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTE_TOPAction1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTE_TOPAction2(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTEEntry(
  PROG_PDL_SF(const uint8 instIdx));
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTEDo(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTE_DECOMPExit(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTE_DECOMP_FINISHEntry(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTE_DECOMP_WRITEEntry(
  PROG_PDL_SF(const uint8 instIdx));
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTE_DECOMP_WRITEDo(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTE_DECOMP_WRITE_CHECKEntry(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTE_DECRYPTExit(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTE_DECRYPT_FINISHEntry(
  PROG_PDL_SF(const uint8 instIdx));
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTE_DECRYPT_FINISHDo(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTE_WRITEEntry(
  PROG_PDL_SF(const uint8 instIdx));
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTE_WRITEDo(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTE_WRITE_CHECKDo(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTE_FAILEDEntry(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTE_FAILEDAction1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements guard '(PROG_E_OK==PROG_Erase_Guard())' */
extern FUNC(boolean, PROG_CODE)
 PROG_HsmPROGSfRTE_FAILEDGuard2(
  PROG_PDL_SF(const uint8 instIdx));
/* implements guard '(PROG_E_OK==PROG_RD_Check())' */
extern FUNC(boolean, PROG_CODE)
 PROG_HsmPROGSfRTE_FAILEDGuard3(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTE_FINISHEntry(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRTE_FINISHAction2(
  PROG_PDL_SF(const uint8 instIdx));
/* implements guard '(PROG_E_OK==PROG_Guard_RD_Check_RTEFinish())' */
extern FUNC(boolean, PROG_CODE)
 PROG_HsmPROGSfRTE_FINISHGuard3(
  PROG_PDL_SF(const uint8 instIdx));

/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfTD_TOPAction2(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_22);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfTD_TOPAction3(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfTDEntry(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfTD_CRCDo(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfTD_CRCAction1(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfTD_FAILEDEntry(
  PROG_PDL_SF(const uint8 instIdx));
/* implements guard '(PROG_E_OK==PROG_Erase_Guard())' */
extern FUNC(boolean, PROG_CODE)
 PROG_HsmPROGSfTD_FAILEDGuard1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements guard '(PROG_E_OK==PROG_RD_Check())' */
extern FUNC(boolean, PROG_CODE)
 PROG_HsmPROGSfTD_FAILEDGuard2(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfTD_STREAMINGEntry(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfTD_WRITEExit(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action '(void)PROG_TD();' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfTD_WRITEAction1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Streaming();' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfTD_WRITEAction2(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfDECRYPT_FINISHEntry(
  PROG_PDL_SF(const uint8 instIdx));
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfDECRYPT_FINISHDo(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfDECRYPT_UPDATEEntry(
  PROG_PDL_SF(const uint8 instIdx));
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfDECRYPT_UPDATEDo(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfWRITEEntry(
  PROG_PDL_SF(const uint8 instIdx));
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfWRITEDo(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfWRITE_CHECKDo(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfRESETEntry(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPExit(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPAction1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPAction3(
  PROG_PDL_SF(const uint8 instIdx));
/* implements guard '(PROG_E_OK==PROG_Erase_Guard())' */
extern FUNC(boolean, PROG_CODE)
 PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPGuard4(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPAction6(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPAction7(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPAction8(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUMEntry(
  PROG_PDL_SF(const uint8 instIdx));
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUMDo(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_CheckPartialSegmentListCrc();' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUMAction1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action '(void)PROG_CRC_Compare();' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUMAction2(
  PROG_PDL_SF(const uint8 instIdx));


/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfWRITE_FINGERPRINTAction1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfWRITE_FINGERPRINTAction2(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfWRITE_FINGERPRINTAction3(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_GetSeed_Unlocked();' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfWRITE_FINGERPRINTAction4(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfWRITE_FINGERPRINTAction6(
  PROG_PDL_SF(const uint8 instIdx));
/* implements action 'PROG_Send_NRC(UDS_NRC_24);' */
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfWRITE_FINGERPRINTAction7(
  PROG_PDL_SF(const uint8 instIdx));

/* implements guard '(PROG_E_OK==PROG_Erase_Guard())' */
extern FUNC(boolean, PROG_CODE)
 PROG_HsmPROGSfWFP_FINISHEDGuard1(
  PROG_PDL_SF(const uint8 instIdx));
/* implements guard '(PROG_E_OK==PROG_RD_Check())' */
extern FUNC(boolean, PROG_CODE)
 PROG_HsmPROGSfWFP_FINISHEDGuard2(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfWFP_INPROGRESSEntry(
  PROG_PDL_SF(const uint8 instIdx));
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfWFP_INPROGRESSDo(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfPRE_INITEntry(
  PROG_PDL_SF(const uint8 instIdx));
extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfPRE_INITDo(
  PROG_PDL_SF(const uint8 instIdx));

extern FUNC(void, PROG_CODE)
 PROG_HsmPROGSfSLEEPEntry(
  PROG_PDL_SF(const uint8 instIdx));


#define PROG_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/
#endif /* defined PROG_HSMPROGINT_H */
/*==================[end of file]===========================================*/
