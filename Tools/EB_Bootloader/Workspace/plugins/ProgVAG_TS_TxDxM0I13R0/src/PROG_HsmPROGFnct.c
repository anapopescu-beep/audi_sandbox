/* --------{ EB Automotive C Source File }-------- */

/* Implementation of the state handler functions of the state machine
 * PROG.
 *
 * This file contains the implementation of the state functions.  It
 * is generated but must be edited to implement the real actions.  If the
 * state machine model is updated and the code generator regenerates the
 * files the user must manually merge the changes with any existing hand
 * written code.
 */

/* CHECK: RULE 301 OFF (this file is partly generated, some lines may be
 * longer then 100 characters) */


/*==================[inclusions]============================================*/
#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <PROG_Hsm.h>  /* state machine driver interface */
#include <PROG_HsmPROG.h> /* public statechart model definitions */
#include <PROG_HsmPROGInt.h> /* internal statechart model definitions */


/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#define PROG_START_SEC_CODE
#include <MemMap.h>

/* ************************ state functions ******************************* */

/* ************************************************************************
 * State: TOP
 * Parent state: none
 * Init substate: PRE_INIT
 * Transitions originating from this state:
 */


/* ************************************************************************
 * State: ALIVE
 * Parent state: TOP
 * Init substate: INIT
 * Transitions originating from this state:
 * 1) ALIVE -> PROG_SESSION: PROG_EVENT_OPEN_PROG_SESSION[]/
 * 2) ALIVE -> DEFAULT_SESSION: PROG_EVENT_REQ_DSC01[]/
 * 3) ALIVE -> EXT_SESSION: PROG_EVENT_REQ_DSC03[]/
 * 4) ALIVE -> ECU_RESET: PROG_EVENT_REQ_ER[]/
 * 5) PROG_EVENT_REQ_PRECOND_CHECK[]/(void)PROG_CheckProgrammingPreCondition();
 * 6) ALIVE -> RESET: PROG_EVENT_RESET[]/
 * 7) ALIVE -> RESET: PROG_EVENT_S3_TIMEOUT[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfALIVEAction5(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action '(void)PROG_CheckProgrammingPreCondition();'
   * for PROG_EVENT_REQ_PRECOND_CHECK[]/...
   * internal transition */
  (void)PROG_CheckProgrammingPreCondition();
}

/* ************************************************************************
 * State: CHECK_MEMORY_TOP
 * Parent state: ALIVE
 * Init substate: SIGNATURE_CHECK
 * Transitions originating from this state:
 * 1) PROG_EVENT_REQ_COMPARE_KEY[]/PROG_Send_NRC(UDS_NRC_24);
 * 2) PROG_EVENT_REQ_GET_SEED[]/PROG_GetSeed_Unlocked();
 * 3) CHECK_MEMORY_TOP -> VERIFY_PARTIAL_SW_CHECKSUM_TOP: PROG_EVENT_REQ_PART_SW_VERIF[]/
 * 4) PROG_EVENT_REQ_RTE[]/PROG_Send_NRC(UDS_NRC_24);
 * 5) PROG_EVENT_REQ_TD[]/PROG_Send_NRC(UDS_NRC_24);
 * 6) CHECK_MEMORY_TOP -> WRITE_FINGERPRINT: PROG_EVENT_REQ_WRITE_FP[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfCHECK_MEMORY_TOPAction1(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_COMPARE_KEY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCHECK_MEMORY_TOPAction2(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_GetSeed_Unlocked();'
   * for PROG_EVENT_REQ_GET_SEED[]/...
   * internal transition */
  PROG_GetSeed_Unlocked();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCHECK_MEMORY_TOPAction4(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_RTE[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCHECK_MEMORY_TOPAction5(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_TD[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}

/* ************************************************************************
 * State: BLU_PRE_RESET
 * Parent state: CHECK_MEMORY_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) BLU_PRE_RESET -> RESET: PROG_EVENT_TX_CONF[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfBLU_PRE_RESETEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_SendNRC78();' */
  PROG_SendNRC78();
}

/* ************************************************************************
 * State: BLU_RESUME
 * Parent state: CHECK_MEMORY_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) BLU_RESUME -> CHECK_MEMORY_FINISH: PROG_EVENT_FINISHED[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfBLU_RESUMEEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_BLU_Resume();' */
  PROG_Entry_BLU_Resume();
}

/* ************************************************************************
 * State: CHECK_MEMORY
 * Parent state: CHECK_MEMORY_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) CHECK_MEMORY -> BLU_PRE_RESET: PROG_EVENT_BLU_PROGRESS[]/
 * 2) PROG_EVENT_CRC_FINISH[]/PROG_CheckSegmentListCrc();
 * 3) CHECK_MEMORY -> CHECK_MEMORY_FINISH: PROG_EVENT_CRYPTO_FINISH[]/(void)PROG_CRC_Compare();
 * 4) CHECK_MEMORY -> CHECK_MEMORY_FINISH: PROG_EVENT_FINISHED[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfCHECK_MEMORYEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_CheckMemoryCompute();' */
  PROG_Entry_CheckMemoryCompute();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCHECK_MEMORYDo(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* do action '(void)PROG_CRC();' */
  (void)PROG_CRC();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCHECK_MEMORYAction2(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_CheckSegmentListCrc();'
   * for PROG_EVENT_CRC_FINISH[]/...
   * internal transition */
  PROG_CheckSegmentListCrc();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCHECK_MEMORYAction3(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action '(void)PROG_CRC_Compare();'
   * for PROG_EVENT_CRYPTO_FINISH[]/...
   * external transition to state CHECK_MEMORY_FINISH */
  (void)PROG_CRC_Compare();
}

/* ************************************************************************
 * State: CHECK_MEMORY_FINISH
 * Parent state: CHECK_MEMORY_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) PROG_EVENT_REQ_CHECKMEMORY[]/PROG_AnswerSuccesiveCheckMemoryRequests();
 * 2) CHECK_MEMORY_FINISH -> COHERENCY_CHECK_TOP: PROG_EVENT_REQ_COHERENCY_CHECK[]/
 * 3) CHECK_MEMORY_FINISH -> ERASE_TOP: PROG_EVENT_REQ_ERASE[(PROG_E_OK==PROG_Erase_Guard())]/
 * 4) CHECK_MEMORY_FINISH -> REPROG: PROG_EVENT_REQ_RD[(PROG_E_OK==PROG_RD_Check())]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfCHECK_MEMORY_FINISHEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_CheckMemoryFinish();' */
  PROG_Entry_CheckMemoryFinish();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCHECK_MEMORY_FINISHExit(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* exit action 'PROG_Exit_CheckMemoryFinish();' */
  PROG_Exit_CheckMemoryFinish();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCHECK_MEMORY_FINISHAction1(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_AnswerSuccesiveCheckMemoryRequests();'
   * for PROG_EVENT_REQ_CHECKMEMORY[]/...
   * internal transition */
  PROG_AnswerSuccesiveCheckMemoryRequests();
}
FUNC(boolean, PROG_CODE) PROG_HsmPROGSfCHECK_MEMORY_FINISHGuard3(
  PROG_PDL_SF(const uint8 instIdx))
{
  boolean RetVal;
  /* guard condition '(PROG_E_OK==PROG_Erase_Guard())'
   * for PROG_EVENT_REQ_ERASE[...]/
   * external transition to state ERASE_TOP */
  if((PROG_E_OK==PROG_Erase_Guard()))
  {
    RetVal = TRUE;
  }
  else
  {
    RetVal = FALSE;
  }
  return RetVal;
}
FUNC(boolean, PROG_CODE) PROG_HsmPROGSfCHECK_MEMORY_FINISHGuard4(
  PROG_PDL_SF(const uint8 instIdx))
{
  boolean RetVal;
  /* guard condition '(PROG_E_OK==PROG_RD_Check())'
   * for PROG_EVENT_REQ_RD[...]/
   * external transition to state REPROG */
  if((PROG_E_OK==PROG_RD_Check()))
  {
    RetVal = TRUE;
  }
  else
  {
    RetVal = FALSE;
  }
  return RetVal;
}

/* ************************************************************************
 * State: SIGNATURE_CHECK
 * Parent state: CHECK_MEMORY_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) SIGNATURE_CHECK -> CHECK_MEMORY: PROG_EVENT_CRYPTO_FINISH[]/
 * 2) SIGNATURE_CHECK -> CHECK_MEMORY_FINISH: PROG_EVENT_FAILED[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfSIGNATURE_CHECKEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_CheckMemory();' */
  PROG_Entry_CheckMemory();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfSIGNATURE_CHECKExit(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* exit action 'PROG_Exit_CheckMemory();' */
  PROG_Exit_CheckMemory();
}

/* ************************************************************************
 * State: COHERENCY_CHECK_TOP
 * Parent state: ALIVE
 * Init substate: COHERENCY_CHECK
 * Transitions originating from this state:
 * 1) PROG_EVENT_REQ_COMPARE_KEY[]/PROG_Send_NRC(UDS_NRC_24);
 * 2) COHERENCY_CHECK_TOP -> ERASE_TOP: PROG_EVENT_REQ_ERASE[(PROG_E_OK==PROG_Erase_Guard())]/
 * 3) PROG_EVENT_REQ_GET_SEED[]/PROG_GetSeed_Unlocked();
 * 4) COHERENCY_CHECK_TOP -> VERIFY_PARTIAL_SW_CHECKSUM_TOP: PROG_EVENT_REQ_PART_SW_VERIF[]/
 * 5) COHERENCY_CHECK_TOP -> REPROG: PROG_EVENT_REQ_RD[(PROG_E_OK==PROG_RD_Check())]/
 * 6) PROG_EVENT_REQ_RTE[]/PROG_Send_NRC(UDS_NRC_24);
 * 7) PROG_EVENT_REQ_TD[]/PROG_Send_NRC(UDS_NRC_24);
 * 8) COHERENCY_CHECK_TOP -> WRITE_FINGERPRINT: PROG_EVENT_REQ_WRITE_FP[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfCOHERENCY_CHECK_TOPAction1(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_COMPARE_KEY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(boolean, PROG_CODE) PROG_HsmPROGSfCOHERENCY_CHECK_TOPGuard2(
  PROG_PDL_SF(const uint8 instIdx))
{
  boolean RetVal;
  /* guard condition '(PROG_E_OK==PROG_Erase_Guard())'
   * for PROG_EVENT_REQ_ERASE[...]/
   * external transition to state ERASE_TOP */
  if((PROG_E_OK==PROG_Erase_Guard()))
  {
    RetVal = TRUE;
  }
  else
  {
    RetVal = FALSE;
  }
  return RetVal;
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCOHERENCY_CHECK_TOPAction3(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_GetSeed_Unlocked();'
   * for PROG_EVENT_REQ_GET_SEED[]/...
   * internal transition */
  PROG_GetSeed_Unlocked();
}
FUNC(boolean, PROG_CODE) PROG_HsmPROGSfCOHERENCY_CHECK_TOPGuard5(
  PROG_PDL_SF(const uint8 instIdx))
{
  boolean RetVal;
  /* guard condition '(PROG_E_OK==PROG_RD_Check())'
   * for PROG_EVENT_REQ_RD[...]/
   * external transition to state REPROG */
  if((PROG_E_OK==PROG_RD_Check()))
  {
    RetVal = TRUE;
  }
  else
  {
    RetVal = FALSE;
  }
  return RetVal;
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCOHERENCY_CHECK_TOPAction6(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_RTE[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCOHERENCY_CHECK_TOPAction7(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_TD[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}

/* ************************************************************************
 * State: COHERENCY_CHECK
 * Parent state: COHERENCY_CHECK_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) COHERENCY_CHECK -> COHERENCY_CHECK_FINISH: PROG_EVENT_FINISHED[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfCOHERENCY_CHECKDo(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* do action 'PROG_Do_CoherencyCheck();' */
  PROG_Do_CoherencyCheck();
}

/* ************************************************************************
 * State: COHERENCY_CHECK_FINISH
 * Parent state: COHERENCY_CHECK_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) PROG_EVENT_REQ_CHECKMEMORY[]/PROG_Send_NRC(UDS_NRC_24);
 * 2) COHERENCY_CHECK_FINISH -> COHERENCY_CHECK_TOP: PROG_EVENT_REQ_COHERENCY_CHECK[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfCOHERENCY_CHECK_FINISHAction1(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_CHECKMEMORY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}

/* ************************************************************************
 * State: COMPARE_KEY
 * Parent state: ALIVE
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) PROG_EVENT_REQ_CHECKMEMORY[]/PROG_Send_NRC(UDS_NRC_24);
 * 2) PROG_EVENT_REQ_COHERENCY_CHECK[]/PROG_Send_NRC(UDS_NRC_24);
 * 3) PROG_EVENT_REQ_COMPARE_KEY[]/PROG_Send_NRC(UDS_NRC_24);
 * 4) PROG_EVENT_REQ_ERASE[]/PROG_Send_NRC(UDS_NRC_24);
 * 5) PROG_EVENT_REQ_GET_SEED[]/PROG_GetSeed_Unlocked();
 * 6) COMPARE_KEY -> VERIFY_PARTIAL_SW_CHECKSUM_TOP: PROG_EVENT_REQ_PART_SW_VERIF[]/
 * 7) PROG_EVENT_REQ_RD[]/PROG_Send_NRC(UDS_NRC_22);
 * 8) PROG_EVENT_REQ_RTE[]/PROG_Send_NRC(UDS_NRC_24);
 * 9) PROG_EVENT_REQ_TD[]/PROG_Send_NRC(UDS_NRC_24);
 * 10) COMPARE_KEY -> WRITE_FINGERPRINT: PROG_EVENT_REQ_WRITE_FP[]/
 * 11) COMPARE_KEY -> LOCKED: PROG_EVENT_UNLOCK_FAILED[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfCOMPARE_KEYEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_CompareKey();' */
  PROG_Entry_CompareKey();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCOMPARE_KEYAction1(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_CHECKMEMORY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCOMPARE_KEYAction2(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_COHERENCY_CHECK[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCOMPARE_KEYAction3(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_COMPARE_KEY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCOMPARE_KEYAction4(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_ERASE[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCOMPARE_KEYAction5(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_GetSeed_Unlocked();'
   * for PROG_EVENT_REQ_GET_SEED[]/...
   * internal transition */
  PROG_GetSeed_Unlocked();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCOMPARE_KEYAction7(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_22);'
   * for PROG_EVENT_REQ_RD[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_22);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCOMPARE_KEYAction8(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_RTE[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfCOMPARE_KEYAction9(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_TD[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}

/* ************************************************************************
 * State: DEFAULT_SESSION
 * Parent state: ALIVE
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) DEFAULT_SESSION -> RESET: PROG_EVENT_TX_CONF[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfDEFAULT_SESSIONEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_DefaultSession();' */
  PROG_Entry_DefaultSession();
}

/* ************************************************************************
 * State: ECU_RESET
 * Parent state: ALIVE
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) ECU_RESET -> RESET: PROG_EVENT_TX_CONF[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfECU_RESETEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_EcuReset();' */
  PROG_Entry_EcuReset();
}

/* ************************************************************************
 * State: ERASE_TOP
 * Parent state: ALIVE
 * Init substate: ERASE_TRANSMITNRC78
 * Transitions originating from this state:
 * 1) PROG_EVENT_REQ_CHECKMEMORY[]/PROG_Send_NRC(UDS_NRC_24);
 * 2) PROG_EVENT_REQ_COHERENCY_CHECK[]/PROG_Send_NRC(UDS_NRC_24);
 * 3) PROG_EVENT_REQ_COMPARE_KEY[]/PROG_Send_NRC(UDS_NRC_24);
 * 4) PROG_EVENT_REQ_GET_SEED[]/PROG_GetSeed_Unlocked();
 * 5) PROG_EVENT_REQ_PART_SW_VERIF[]/PROG_Send_NRC(UDS_NRC_24);
 * 6) PROG_EVENT_REQ_RTE[]/PROG_Send_NRC(UDS_NRC_24);
 * 7) PROG_EVENT_REQ_TD[]/PROG_Send_NRC(UDS_NRC_24);
 * 8) PROG_EVENT_REQ_WRITE_FP[]/PROG_Send_NRC(UDS_NRC_22);
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfERASE_TOPAction1(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_CHECKMEMORY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfERASE_TOPAction2(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_COHERENCY_CHECK[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfERASE_TOPAction3(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_COMPARE_KEY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfERASE_TOPAction4(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_GetSeed_Unlocked();'
   * for PROG_EVENT_REQ_GET_SEED[]/...
   * internal transition */
  PROG_GetSeed_Unlocked();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfERASE_TOPAction5(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_PART_SW_VERIF[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfERASE_TOPAction6(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_RTE[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfERASE_TOPAction7(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_TD[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfERASE_TOPAction8(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_22);'
   * for PROG_EVENT_REQ_WRITE_FP[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_22);
}

/* ************************************************************************
 * State: ERASE
 * Parent state: ERASE_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) ERASE -> ERASE_FINISH: PROG_EVENT_FINISHED[]/
 * 2) ERASE -> ERASE_NRC78: PROG_EVENT_WAIT_NRC78[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfERASEEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_Erase();' */
  PROG_Entry_Erase();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfERASEDo(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* do action 'PROG_Erase();' */
  PROG_Erase();
}

/* ************************************************************************
 * State: ERASE_CHECK
 * Parent state: ERASE_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) ERASE_CHECK -> ERASE_FINISH: PROG_EVENT_FINISHED[]/
 * 2) ERASE_CHECK -> ERASE: PROG_EVENT_TX_CONF[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfERASE_CHECKEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_EraseCheck();' */
  PROG_Entry_EraseCheck();
}

/* ************************************************************************
 * State: ERASE_FINISH
 * Parent state: ERASE_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) ERASE_FINISH -> ERASE_TOP: PROG_EVENT_REQ_ERASE[(PROG_E_OK==PROG_Guard_Erase_Check_EraseFinish())]/
 * 2) ERASE_FINISH -> REPROG: PROG_EVENT_REQ_RD[(PROG_E_OK==PROG_RD_Check())]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfERASE_FINISHEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_EraseFinish();' */
  PROG_Entry_EraseFinish();
}
FUNC(boolean, PROG_CODE) PROG_HsmPROGSfERASE_FINISHGuard1(
  PROG_PDL_SF(const uint8 instIdx))
{
  boolean RetVal;
  /* guard condition '(PROG_E_OK==PROG_Guard_Erase_Check_EraseFinish())'
   * for PROG_EVENT_REQ_ERASE[...]/
   * external transition to state ERASE_TOP */
  if((PROG_E_OK==PROG_Guard_Erase_Check_EraseFinish()))
  {
    RetVal = TRUE;
  }
  else
  {
    RetVal = FALSE;
  }
  return RetVal;
}
FUNC(boolean, PROG_CODE) PROG_HsmPROGSfERASE_FINISHGuard2(
  PROG_PDL_SF(const uint8 instIdx))
{
  boolean RetVal;
  /* guard condition '(PROG_E_OK==PROG_RD_Check())'
   * for PROG_EVENT_REQ_RD[...]/
   * external transition to state REPROG */
  if((PROG_E_OK==PROG_RD_Check()))
  {
    RetVal = TRUE;
  }
  else
  {
    RetVal = FALSE;
  }
  return RetVal;
}

/* ************************************************************************
 * State: ERASE_NRC78
 * Parent state: ERASE_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) ERASE_NRC78 -> ERASE: PROG_EVENT_TX_CONF[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfERASE_NRC78Entry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_EraseNRC78();' */
  PROG_Entry_EraseNRC78();
}

/* ************************************************************************
 * State: ERASE_TRANSMITNRC78
 * Parent state: ERASE_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) ERASE_TRANSMITNRC78 -> ERASE_CHECK: PROG_EVENT_TX_CONF[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfERASE_TRANSMITNRC78Entry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_EraseTransmitNRC78();' */
  PROG_Entry_EraseTransmitNRC78();
}

/* ************************************************************************
 * State: EXT_SESSION
 * Parent state: ALIVE
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) EXT_SESSION -> VERIFY_PARTIAL_SW_CHECKSUM_TOP: PROG_EVENT_REQ_PART_SW_VERIF[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfEXT_SESSIONEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_ExtendedSession();' */
  PROG_Entry_ExtendedSession();
}

/* ************************************************************************
 * State: GET_SEED
 * Parent state: ALIVE
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) PROG_EVENT_REQ_CHECKMEMORY[]/PROG_Send_NRC(UDS_NRC_24);
 * 2) PROG_EVENT_REQ_COHERENCY_CHECK[]/PROG_Send_NRC(UDS_NRC_24);
 * 3) GET_SEED -> COMPARE_KEY: PROG_EVENT_REQ_COMPARE_KEY[]/
 * 4) PROG_EVENT_REQ_GET_SEED[]/PROG_Entry_GetSeed();
 * 5) PROG_EVENT_REQ_RTE[]/PROG_Send_NRC(UDS_NRC_24);
 * 6) PROG_EVENT_REQ_TD[]/PROG_Send_NRC(UDS_NRC_24);
 * 7) GET_SEED -> LOCKED: PROG_EVENT_UNLOCK_FAILED[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfGET_SEEDEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_GetSeed();' */
  PROG_Entry_GetSeed();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfGET_SEEDAction1(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_CHECKMEMORY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfGET_SEEDAction2(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_COHERENCY_CHECK[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfGET_SEEDAction4(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Entry_GetSeed();'
   * for PROG_EVENT_REQ_GET_SEED[]/...
   * internal transition */
  PROG_Entry_GetSeed();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfGET_SEEDAction5(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_RTE[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfGET_SEEDAction6(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_TD[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}

/* ************************************************************************
 * State: INIT
 * Parent state: ALIVE
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) INIT -> SLEEP: PROG_EVENT_SLEEP[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfINITEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_INIT();' */
  PROG_Entry_INIT();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfINITExit(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* exit action 'PROG_Exit_INIT();' */
  PROG_Exit_INIT();
}

/* ************************************************************************
 * State: LOCKED
 * Parent state: ALIVE
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) PROG_EVENT_REQ_CHECKMEMORY[]/PROG_Send_NRC(UDS_NRC_24);
 * 2) PROG_EVENT_REQ_COHERENCY_CHECK[]/PROG_Send_NRC(UDS_NRC_24);
 * 3) PROG_EVENT_REQ_COMPARE_KEY[]/PROG_Send_NRC(UDS_NRC_24);
 * 4) LOCKED -> GET_SEED: PROG_EVENT_REQ_GET_SEED[]/
 * 5) PROG_EVENT_REQ_RTE[]/PROG_Send_NRC(UDS_NRC_24);
 * 6) PROG_EVENT_REQ_TD[]/PROG_Send_NRC(UDS_NRC_24);
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfLOCKEDAction1(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_CHECKMEMORY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfLOCKEDAction2(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_COHERENCY_CHECK[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfLOCKEDAction3(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_COMPARE_KEY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfLOCKEDAction5(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_RTE[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfLOCKEDAction6(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_TD[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}

/* ************************************************************************
 * State: PROG_SESSION
 * Parent state: ALIVE
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) PROG_SESSION -> BLU_RESUME: PROG_EVENT_BLU_PROGRESS[]/
 * 2) PROG_EVENT_REQ_CHECKMEMORY[]/PROG_Send_NRC(UDS_NRC_24);
 * 3) PROG_EVENT_REQ_COHERENCY_CHECK[]/PROG_Send_NRC(UDS_NRC_24);
 * 4) PROG_EVENT_REQ_COMPARE_KEY[]/PROG_Send_NRC(UDS_NRC_24);
 * 5) PROG_SESSION -> GET_SEED: PROG_EVENT_REQ_GET_SEED[]/
 * 6) PROG_EVENT_REQ_RTE[]/PROG_Send_NRC(UDS_NRC_24);
 * 7) PROG_EVENT_REQ_TD[]/PROG_Send_NRC(UDS_NRC_24);
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfPROG_SESSIONEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_ProgrammingSession();' */
  PROG_Entry_ProgrammingSession();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfPROG_SESSIONAction2(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_CHECKMEMORY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfPROG_SESSIONAction3(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_COHERENCY_CHECK[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfPROG_SESSIONAction4(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_COMPARE_KEY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfPROG_SESSIONAction6(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_RTE[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfPROG_SESSIONAction7(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_TD[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}

/* ************************************************************************
 * State: REPROG
 * Parent state: ALIVE
 * Init substate: RD_TOP
 * Transitions originating from this state:
 * 1) PROG_EVENT_REQ_COHERENCY_CHECK[]/PROG_Send_NRC(UDS_NRC_24);
 * 2) PROG_EVENT_REQ_COMPARE_KEY[]/PROG_Send_NRC(UDS_NRC_24);
 * 3) PROG_EVENT_REQ_ERASE[]/PROG_Send_NRC(UDS_NRC_24);
 * 4) PROG_EVENT_REQ_GET_SEED[]/PROG_Send_NRC(UDS_NRC_24);
 * 5) PROG_EVENT_REQ_PART_SW_VERIF[]/PROG_Send_NRC(UDS_NRC_24);
 * 6) PROG_EVENT_REQ_PRECOND_CHECK[]/PROG_Send_NRC(UDS_NRC_24);
 * 7) PROG_EVENT_REQ_WRITE_FP[]/PROG_Send_NRC(UDS_NRC_22);
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfREPROGAction1(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_COHERENCY_CHECK[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfREPROGAction2(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_COMPARE_KEY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfREPROGAction3(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_ERASE[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfREPROGAction4(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_GET_SEED[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfREPROGAction5(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_PART_SW_VERIF[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfREPROGAction6(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_PRECOND_CHECK[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfREPROGAction7(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_22);'
   * for PROG_EVENT_REQ_WRITE_FP[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_22);
}

/* ************************************************************************
 * State: RD_TOP
 * Parent state: REPROG
 * Init substate: RD
 * Transitions originating from this state:
 * 1) PROG_EVENT_REQ_CHECKMEMORY[]/PROG_Send_NRC(UDS_NRC_24);
 * 2) PROG_EVENT_REQ_ERASE[]/PROG_Send_NRC(UDS_NRC_24);
 * 3) PROG_EVENT_REQ_RTE[]/PROG_Send_NRC(UDS_NRC_24);
 * 4) RD_TOP -> TD_TOP: PROG_EVENT_REQ_TD[]/
 * 5) RD_TOP -> TD_STREAMING: PROG_EVENT_STREAMING[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfRD_TOPAction1(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_CHECKMEMORY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfRD_TOPAction2(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_ERASE[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfRD_TOPAction3(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_RTE[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}

/* ************************************************************************
 * State: RD
 * Parent state: RD_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) RD -> RD_SIGNATURE: PROG_EVENT_CRYPTO_NOTIFY[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfRDEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_RD();' */
  PROG_Entry_RD();
}

/* ************************************************************************
 * State: RD_FINISH
 * Parent state: RD_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) RD_FINISH -> RD_TOP: PROG_EVENT_REQ_RD[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfRD_FINISHEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_RD_Finish();' */
  PROG_Entry_RD_Finish();
}

/* ************************************************************************
 * State: RD_SIGNATURE
 * Parent state: RD_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) RD_SIGNATURE -> RD_FINISH: PROG_EVENT_CRYPTO_NOTIFY[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfRD_SIGNATUREEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_RD_Signature();' */
  PROG_Entry_RD_Signature();
}

/* ************************************************************************
 * State: RTE_TOP
 * Parent state: REPROG
 * Init substate: RTE
 * Transitions originating from this state:
 * 1) PROG_EVENT_REQ_RTE[]/PROG_Send_NRC(UDS_NRC_24);
 * 2) PROG_EVENT_REQ_TD[]/PROG_Send_NRC(UDS_NRC_24);
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfRTE_TOPAction1(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_RTE[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfRTE_TOPAction2(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_TD[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}

/* ************************************************************************
 * State: RTE
 * Parent state: RTE_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) RTE -> RTE_DECRYPT: PROG_EVENT_CRYPTO_FINISH[]/
 * 2) RTE -> RTE_FAILED: PROG_EVENT_FAILED[]/
 * 3) RTE -> RTE_FINISH: PROG_EVENT_FINISHED[]/
 * 4) RTE -> RTE_DECOMP: PROG_EVENT_WRITE[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfRTEEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_RTE();' */
  PROG_Entry_RTE();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfRTEDo(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* do action '(void)PROG_VerificationOnTheFly();' */
  (void)PROG_VerificationOnTheFly();
}

/* ************************************************************************
 * State: RTE_DECOMP
 * Parent state: RTE_TOP
 * Init substate: RTE_DECOMP_FINISH
 * Transitions originating from this state:
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfRTE_DECOMPExit(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* exit action 'PROG_Exit_RTE_Decrypt();' */
  PROG_Exit_RTE_Decrypt();
}

/* ************************************************************************
 * State: RTE_DECOMP_FINISH
 * Parent state: RTE_DECOMP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) RTE_DECOMP_FINISH -> RTE_DECOMP_WRITE: PROG_EVENT_WRITE[]/
 * 2) RTE_DECOMP_FINISH -> RTE_DECOMP_WRITE_CHECK: PROG_EVENT_WRITE_CHECK[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfRTE_DECOMP_FINISHEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_RTEDecompFinish();' */
  PROG_Entry_RTEDecompFinish();
}

/* ************************************************************************
 * State: RTE_DECOMP_WRITE
 * Parent state: RTE_DECOMP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) RTE_DECOMP_WRITE -> RTE_DECOMP_WRITE_CHECK: PROG_EVENT_WRITE_CHECK[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfRTE_DECOMP_WRITEEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_Write();' */
  PROG_Entry_Write();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfRTE_DECOMP_WRITEDo(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* do action 'PROG_Write();' */
  PROG_Write();
}

/* ************************************************************************
 * State: RTE_DECOMP_WRITE_CHECK
 * Parent state: RTE_DECOMP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) RTE_DECOMP_WRITE_CHECK -> RTE: PROG_EVENT_TD_END[]/
 * 2) RTE_DECOMP_WRITE_CHECK -> RTE_DECOMP_WRITE: PROG_EVENT_WRITE[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfRTE_DECOMP_WRITE_CHECKEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_WriteCheck();' */
  PROG_WriteCheck();
}

/* ************************************************************************
 * State: RTE_DECRYPT
 * Parent state: RTE_TOP
 * Init substate: RTE_DECRYPT_FINISH
 * Transitions originating from this state:
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfRTE_DECRYPTExit(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* exit action 'PROG_Exit_RTE_Decrypt();' */
  PROG_Exit_RTE_Decrypt();
}

/* ************************************************************************
 * State: RTE_DECRYPT_FINISH
 * Parent state: RTE_DECRYPT
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) RTE_DECRYPT_FINISH -> RTE_WRITE: PROG_EVENT_WRITE[]/
 * 2) RTE_DECRYPT_FINISH -> RTE_WRITE_CHECK: PROG_EVENT_WRITE_CHECK[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfRTE_DECRYPT_FINISHEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_DecryptionFinish();' */
  PROG_Entry_DecryptionFinish();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfRTE_DECRYPT_FINISHDo(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* do action 'PROG_Do_DecryptionFinish();' */
  PROG_Do_DecryptionFinish();
}

/* ************************************************************************
 * State: RTE_WRITE
 * Parent state: RTE_DECRYPT
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) RTE_WRITE -> RTE_WRITE_CHECK: PROG_EVENT_WRITE_CHECK[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfRTE_WRITEEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_Write();' */
  PROG_Entry_Write();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfRTE_WRITEDo(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* do action 'PROG_Write();' */
  PROG_Write();
}

/* ************************************************************************
 * State: RTE_WRITE_CHECK
 * Parent state: RTE_DECRYPT
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) RTE_WRITE_CHECK -> RTE: PROG_EVENT_TD_END[]/
 * 2) RTE_WRITE_CHECK -> RTE_WRITE: PROG_EVENT_WRITE[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfRTE_WRITE_CHECKDo(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* do action 'PROG_WriteCheck();' */
  PROG_WriteCheck();
}

/* ************************************************************************
 * State: RTE_FAILED
 * Parent state: RTE_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) PROG_EVENT_REQ_CHECKMEMORY[]/PROG_Send_NRC(UDS_NRC_24);
 * 2) RTE_FAILED -> ERASE_TOP: PROG_EVENT_REQ_ERASE[(PROG_E_OK==PROG_Erase_Guard())]/
 * 3) RTE_FAILED -> REPROG: PROG_EVENT_REQ_RD[(PROG_E_OK==PROG_RD_Check())]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfRTE_FAILEDEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_RTEFailed();' */
  PROG_Entry_RTEFailed();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfRTE_FAILEDAction1(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_CHECKMEMORY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(boolean, PROG_CODE) PROG_HsmPROGSfRTE_FAILEDGuard2(
  PROG_PDL_SF(const uint8 instIdx))
{
  boolean RetVal;
  /* guard condition '(PROG_E_OK==PROG_Erase_Guard())'
   * for PROG_EVENT_REQ_ERASE[...]/
   * external transition to state ERASE_TOP */
  if((PROG_E_OK==PROG_Erase_Guard()))
  {
    RetVal = TRUE;
  }
  else
  {
    RetVal = FALSE;
  }
  return RetVal;
}
FUNC(boolean, PROG_CODE) PROG_HsmPROGSfRTE_FAILEDGuard3(
  PROG_PDL_SF(const uint8 instIdx))
{
  boolean RetVal;
  /* guard condition '(PROG_E_OK==PROG_RD_Check())'
   * for PROG_EVENT_REQ_RD[...]/
   * external transition to state REPROG */
  if((PROG_E_OK==PROG_RD_Check()))
  {
    RetVal = TRUE;
  }
  else
  {
    RetVal = FALSE;
  }
  return RetVal;
}

/* ************************************************************************
 * State: RTE_FINISH
 * Parent state: RTE_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) RTE_FINISH -> CHECK_MEMORY_TOP: PROG_EVENT_REQ_CHECKMEMORY[]/
 * 2) PROG_EVENT_REQ_ERASE[]/PROG_Send_NRC(UDS_NRC_24);
 * 3) RTE_FINISH -> REPROG: PROG_EVENT_REQ_RD[(PROG_E_OK==PROG_Guard_RD_Check_RTEFinish())]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfRTE_FINISHEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_RTEFinish();' */
  PROG_Entry_RTEFinish();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfRTE_FINISHAction2(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_ERASE[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(boolean, PROG_CODE) PROG_HsmPROGSfRTE_FINISHGuard3(
  PROG_PDL_SF(const uint8 instIdx))
{
  boolean RetVal;
  /* guard condition '(PROG_E_OK==PROG_Guard_RD_Check_RTEFinish())'
   * for PROG_EVENT_REQ_RD[...]/
   * external transition to state REPROG */
  if((PROG_E_OK==PROG_Guard_RD_Check_RTEFinish()))
  {
    RetVal = TRUE;
  }
  else
  {
    RetVal = FALSE;
  }
  return RetVal;
}

/* ************************************************************************
 * State: TD_TOP
 * Parent state: REPROG
 * Init substate: TD
 * Transitions originating from this state:
 * 1) TD_TOP -> TD_FAILED: PROG_EVENT_FAILED[]/
 * 2) PROG_EVENT_REQ_CHECKMEMORY[]/PROG_Send_NRC(UDS_NRC_24);
 * 3) PROG_EVENT_REQ_RD[]/PROG_Send_NRC(UDS_NRC_22);
 * 4) TD_TOP -> RTE_TOP: PROG_EVENT_REQ_RTE[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfTD_TOPAction2(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_CHECKMEMORY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfTD_TOPAction3(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_22);'
   * for PROG_EVENT_REQ_RD[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_22);
}

/* ************************************************************************
 * State: TD
 * Parent state: TD_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) TD -> TD_WRITE: PROG_EVENT_WRITE_CHECK[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfTDEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_TD();' */
  PROG_Entry_TD();
}

/* ************************************************************************
 * State: TD_CRC
 * Parent state: TD_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) PROG_EVENT_REQ_ERASE[]/PROG_Send_NRC(UDS_NRC_24);
 * 2) TD_CRC -> TD: PROG_EVENT_REQ_TD[]/
 * 3) TD_CRC -> TD_STREAMING: PROG_EVENT_STREAMING[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfTD_CRCDo(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* do action '(void)PROG_VerificationOnTheFly();' */
  (void)PROG_VerificationOnTheFly();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfTD_CRCAction1(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_ERASE[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}

/* ************************************************************************
 * State: TD_FAILED
 * Parent state: TD_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) TD_FAILED -> ERASE_TOP: PROG_EVENT_REQ_ERASE[(PROG_E_OK==PROG_Erase_Guard())]/
 * 2) TD_FAILED -> REPROG: PROG_EVENT_REQ_RD[(PROG_E_OK==PROG_RD_Check())]/
 * 3) TD_FAILED -> TD: PROG_EVENT_REQ_TD[]/
 * 4) TD_FAILED -> TD_STREAMING: PROG_EVENT_STREAMING[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfTD_FAILEDEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_TD_Failed();' */
  PROG_Entry_TD_Failed();
}
FUNC(boolean, PROG_CODE) PROG_HsmPROGSfTD_FAILEDGuard1(
  PROG_PDL_SF(const uint8 instIdx))
{
  boolean RetVal;
  /* guard condition '(PROG_E_OK==PROG_Erase_Guard())'
   * for PROG_EVENT_REQ_ERASE[...]/
   * external transition to state ERASE_TOP */
  if((PROG_E_OK==PROG_Erase_Guard()))
  {
    RetVal = TRUE;
  }
  else
  {
    RetVal = FALSE;
  }
  return RetVal;
}
FUNC(boolean, PROG_CODE) PROG_HsmPROGSfTD_FAILEDGuard2(
  PROG_PDL_SF(const uint8 instIdx))
{
  boolean RetVal;
  /* guard condition '(PROG_E_OK==PROG_RD_Check())'
   * for PROG_EVENT_REQ_RD[...]/
   * external transition to state REPROG */
  if((PROG_E_OK==PROG_RD_Check()))
  {
    RetVal = TRUE;
  }
  else
  {
    RetVal = FALSE;
  }
  return RetVal;
}

/* ************************************************************************
 * State: TD_STREAMING
 * Parent state: TD_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) TD_STREAMING -> TD_WRITE: PROG_EVENT_WRITE_CHECK[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfTD_STREAMINGEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_Streaming();' */
  PROG_Entry_Streaming();
}

/* ************************************************************************
 * State: TD_WRITE
 * Parent state: TD_TOP
 * Init substate: DECRYPT_UPDATE
 * Transitions originating from this state:
 * 1) PROG_EVENT_REQ_TD[]/(void)PROG_TD();
 * 2) PROG_EVENT_STREAMING[]/PROG_Streaming();
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfTD_WRITEExit(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* exit action 'PROG_Exit_TD_Write();' */
  PROG_Exit_TD_Write();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfTD_WRITEAction1(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action '(void)PROG_TD();'
   * for PROG_EVENT_REQ_TD[]/...
   * internal transition */
  (void)PROG_TD();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfTD_WRITEAction2(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Streaming();'
   * for PROG_EVENT_STREAMING[]/...
   * internal transition */
  PROG_Streaming();
}

/* ************************************************************************
 * State: DECRYPT_FINISH
 * Parent state: TD_WRITE
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) DECRYPT_FINISH -> WRITE: PROG_EVENT_WRITE[]/
 * 2) DECRYPT_FINISH -> WRITE_CHECK: PROG_EVENT_WRITE_CHECK[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfDECRYPT_FINISHEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_DecryptionFinish();' */
  PROG_Entry_DecryptionFinish();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfDECRYPT_FINISHDo(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* do action 'PROG_Do_DecryptionFinish();' */
  PROG_Do_DecryptionFinish();
}

/* ************************************************************************
 * State: DECRYPT_UPDATE
 * Parent state: TD_WRITE
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) DECRYPT_UPDATE -> WRITE_CHECK: PROG_EVENT_WRITE_CHECK[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfDECRYPT_UPDATEEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_DecryptionUpdate();' */
  PROG_Entry_DecryptionUpdate();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfDECRYPT_UPDATEDo(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* do action 'PROG_Do_DecryptionUpdate();' */
  PROG_Do_DecryptionUpdate();
}

/* ************************************************************************
 * State: WRITE
 * Parent state: TD_WRITE
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) WRITE -> WRITE_CHECK: PROG_EVENT_WRITE_CHECK[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfWRITEEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_Write();' */
  PROG_Entry_Write();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfWRITEDo(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* do action 'PROG_Write();' */
  PROG_Write();
}

/* ************************************************************************
 * State: WRITE_CHECK
 * Parent state: TD_WRITE
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) WRITE_CHECK -> DECRYPT_FINISH: PROG_EVENT_CRYPTO_FINISH[]/
 * 2) WRITE_CHECK -> TD_CRC: PROG_EVENT_TD_END[]/
 * 3) WRITE_CHECK -> WRITE: PROG_EVENT_WRITE[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfWRITE_CHECKDo(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* do action 'PROG_WriteCheck();' */
  PROG_WriteCheck();
}

/* ************************************************************************
 * State: RESET
 * Parent state: ALIVE
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfRESETEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_Reset();' */
  PROG_Entry_Reset();
}

/* ************************************************************************
 * State: VERIFY_PARTIAL_SW_CHECKSUM_TOP
 * Parent state: ALIVE
 * Init substate: VERIFY_PARTIAL_SW_CHECKSUM
 * Transitions originating from this state:
 * 1) PROG_EVENT_REQ_CHECKMEMORY[]/PROG_Send_NRC(UDS_NRC_24);
 * 2) VERIFY_PARTIAL_SW_CHECKSUM_TOP -> COHERENCY_CHECK_TOP: PROG_EVENT_REQ_COHERENCY_CHECK[]/
 * 3) PROG_EVENT_REQ_COMPARE_KEY[]/PROG_Send_NRC(UDS_NRC_24);
 * 4) VERIFY_PARTIAL_SW_CHECKSUM_TOP -> ERASE_TOP: PROG_EVENT_REQ_ERASE[(PROG_E_OK==PROG_Erase_Guard())]/
 * 5) VERIFY_PARTIAL_SW_CHECKSUM_TOP -> GET_SEED: PROG_EVENT_REQ_GET_SEED[]/
 * 6) PROG_EVENT_REQ_RD[]/PROG_Send_NRC(UDS_NRC_24);
 * 7) PROG_EVENT_REQ_RTE[]/PROG_Send_NRC(UDS_NRC_24);
 * 8) PROG_EVENT_REQ_TD[]/PROG_Send_NRC(UDS_NRC_24);
 * 9) VERIFY_PARTIAL_SW_CHECKSUM_TOP -> WRITE_FINGERPRINT: PROG_EVENT_REQ_WRITE_FP[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPExit(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* exit action 'PROG_Exit_PartialVerificationCrc();' */
  PROG_Exit_PartialVerificationCrc();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPAction1(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_CHECKMEMORY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPAction3(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_COMPARE_KEY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(boolean, PROG_CODE) PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPGuard4(
  PROG_PDL_SF(const uint8 instIdx))
{
  boolean RetVal;
  /* guard condition '(PROG_E_OK==PROG_Erase_Guard())'
   * for PROG_EVENT_REQ_ERASE[...]/
   * external transition to state ERASE_TOP */
  if((PROG_E_OK==PROG_Erase_Guard()))
  {
    RetVal = TRUE;
  }
  else
  {
    RetVal = FALSE;
  }
  return RetVal;
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPAction6(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_RD[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPAction7(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_RTE[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPAction8(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_TD[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}

/* ************************************************************************
 * State: VERIFY_PARTIAL_SW_CHECKSUM
 * Parent state: VERIFY_PARTIAL_SW_CHECKSUM_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) PROG_EVENT_CRC_FINISH[]/PROG_CheckPartialSegmentListCrc();
 * 2) VERIFY_PARTIAL_SW_CHECKSUM -> VERIFY_PARTIAL_SW_CHECKSUM_FINISH: PROG_EVENT_CRYPTO_FINISH[]/(void)PROG_CRC_Compare();
 * 3) VERIFY_PARTIAL_SW_CHECKSUM -> VERIFY_PARTIAL_SW_CHECKSUM_FINISH: PROG_EVENT_FINISHED[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUMEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_PartialVerificationCrc();' */
  PROG_Entry_PartialVerificationCrc();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUMDo(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* do action '(void)PROG_CRC();' */
  (void)PROG_CRC();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUMAction1(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_CheckPartialSegmentListCrc();'
   * for PROG_EVENT_CRC_FINISH[]/...
   * internal transition */
  PROG_CheckPartialSegmentListCrc();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUMAction2(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action '(void)PROG_CRC_Compare();'
   * for PROG_EVENT_CRYPTO_FINISH[]/...
   * external transition to state VERIFY_PARTIAL_SW_CHECKSUM_FINISH */
  (void)PROG_CRC_Compare();
}

/* ************************************************************************
 * State: VERIFY_PARTIAL_SW_CHECKSUM_FINISH
 * Parent state: VERIFY_PARTIAL_SW_CHECKSUM_TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) VERIFY_PARTIAL_SW_CHECKSUM_FINISH -> VERIFY_PARTIAL_SW_CHECKSUM_TOP: PROG_EVENT_REQ_PART_SW_VERIF[]/
 */


/* ************************************************************************
 * State: WRITE_FINGERPRINT
 * Parent state: ALIVE
 * Init substate: WFP_INPROGRESS
 * Transitions originating from this state:
 * 1) PROG_EVENT_REQ_CHECKMEMORY[]/PROG_Send_NRC(UDS_NRC_24);
 * 2) PROG_EVENT_REQ_COHERENCY_CHECK[]/PROG_Send_NRC(UDS_NRC_24);
 * 3) PROG_EVENT_REQ_COMPARE_KEY[]/PROG_Send_NRC(UDS_NRC_24);
 * 4) PROG_EVENT_REQ_GET_SEED[]/PROG_GetSeed_Unlocked();
 * 5) WRITE_FINGERPRINT -> VERIFY_PARTIAL_SW_CHECKSUM_TOP: PROG_EVENT_REQ_PART_SW_VERIF[]/
 * 6) PROG_EVENT_REQ_RTE[]/PROG_Send_NRC(UDS_NRC_24);
 * 7) PROG_EVENT_REQ_TD[]/PROG_Send_NRC(UDS_NRC_24);
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfWRITE_FINGERPRINTAction1(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_CHECKMEMORY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfWRITE_FINGERPRINTAction2(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_COHERENCY_CHECK[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfWRITE_FINGERPRINTAction3(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_COMPARE_KEY[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfWRITE_FINGERPRINTAction4(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_GetSeed_Unlocked();'
   * for PROG_EVENT_REQ_GET_SEED[]/...
   * internal transition */
  PROG_GetSeed_Unlocked();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfWRITE_FINGERPRINTAction6(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_RTE[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfWRITE_FINGERPRINTAction7(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* action 'PROG_Send_NRC(UDS_NRC_24);'
   * for PROG_EVENT_REQ_TD[]/...
   * internal transition */
  PROG_Send_NRC(UDS_NRC_24);
}

/* ************************************************************************
 * State: WFP_FINISHED
 * Parent state: WRITE_FINGERPRINT
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) WFP_FINISHED -> ERASE_TOP: PROG_EVENT_REQ_ERASE[(PROG_E_OK==PROG_Erase_Guard())]/
 * 2) WFP_FINISHED -> REPROG: PROG_EVENT_REQ_RD[(PROG_E_OK==PROG_RD_Check())]/
 * 3) WFP_FINISHED -> WRITE_FINGERPRINT: PROG_EVENT_REQ_WRITE_FP[]/
 */

FUNC(boolean, PROG_CODE) PROG_HsmPROGSfWFP_FINISHEDGuard1(
  PROG_PDL_SF(const uint8 instIdx))
{
  boolean RetVal;
  /* guard condition '(PROG_E_OK==PROG_Erase_Guard())'
   * for PROG_EVENT_REQ_ERASE[...]/
   * external transition to state ERASE_TOP */
  if((PROG_E_OK==PROG_Erase_Guard()))
  {
    RetVal = TRUE;
  }
  else
  {
    RetVal = FALSE;
  }
  return RetVal;
}
FUNC(boolean, PROG_CODE) PROG_HsmPROGSfWFP_FINISHEDGuard2(
  PROG_PDL_SF(const uint8 instIdx))
{
  boolean RetVal;
  /* guard condition '(PROG_E_OK==PROG_RD_Check())'
   * for PROG_EVENT_REQ_RD[...]/
   * external transition to state REPROG */
  if((PROG_E_OK==PROG_RD_Check()))
  {
    RetVal = TRUE;
  }
  else
  {
    RetVal = FALSE;
  }
  return RetVal;
}

/* ************************************************************************
 * State: WFP_INPROGRESS
 * Parent state: WRITE_FINGERPRINT
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) WFP_INPROGRESS -> WFP_FINISHED: PROG_EVENT_FINISHED[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfWFP_INPROGRESSEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_WriteFingerprint();' */
  PROG_Entry_WriteFingerprint();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfWFP_INPROGRESSDo(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* do action 'PROG_WriteFingerprintCheck();' */
  PROG_WriteFingerprintCheck();
}

/* ************************************************************************
 * State: PRE_INIT
 * Parent state: TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) PRE_INIT -> ALIVE: PROG_EVENT_INIT[]/
 * 2) PRE_INIT -> SLEEP: PROG_EVENT_SLEEP[]/
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfPRE_INITEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_PreInit();' */
  PROG_Entry_PreInit();
}
FUNC(void, PROG_CODE) PROG_HsmPROGSfPRE_INITDo(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* do action 'PROG_PreInit();' */
  PROG_PreInit();
}

/* ************************************************************************
 * State: SLEEP
 * Parent state: TOP
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 */

FUNC(void, PROG_CODE) PROG_HsmPROGSfSLEEPEntry(
  PROG_PDL_SF(const uint8 instIdx))
{
  /* entry action 'PROG_Entry_Sleep();' */
  PROG_Entry_Sleep();
}


/*==================[internal function definitions]=========================*/


#define PROG_STOP_SEC_CODE
#include <MemMap.h>

/*==================[end of file]===========================================*/
