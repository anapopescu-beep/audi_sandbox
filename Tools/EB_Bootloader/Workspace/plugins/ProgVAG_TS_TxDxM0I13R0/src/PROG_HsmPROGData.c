/* --------{ EB Automotive C Source File }-------- */

/* Definition of the configuration data of the state machine
 * PROG.
 *
 * This file contains the definition of all used data structures of the state
 * machine model.  It is generated and must not be edited.
 */


/* CHECK: RULE 506 OFF (Variables may not start lower case) */
/* CHECK: RULE 902 OFF (Table may not start with a "a") */

/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */

#include <PROG_Hsm.h> /* state machine driver interface */
#include <PROG_HsmPROG.h> /* public statechart model definitions, */
#include <PROG_HsmPROGInt.h> /* internal statechart model definitions */

/*==================[macros]================================================*/

/** \brief Number of user events */
#define PROG_HSM_PROG_NUM_EVENTS 32U

/* Check if number of hsm instances is defined in the user's configuration */
#ifndef PROG_HSM_PROG_NUM_INST
#error PROG_HSM_PROG_NUM_INST must be defined in PROG_HsmCfg.h
#endif


/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

/*==================[external function declarations]========================*/

/*==================[internal data]=========================================*/

#define PROG_START_SEC_VAR_NO_INIT_8
#include <MemMap.h>

/* RAM data for event counters */
STATIC VAR(uint8, PROG_VAR_NOINIT)
  PROG_HsmEvCountersPROG[
    PROG_HSM_PROG_NUM_INST * PROG_HSM_PROG_NUM_EVENTS];

/* RAM data for event queues */
STATIC VAR(PROG_HsmEventType, PROG_VAR_NOINIT)
  PROG_HsmEvQueuesPROG[
    PROG_HSM_PROG_NUM_INST * PROG_HSM_PROG_NUM_EVENTS];

#define PROG_STOP_SEC_VAR_NO_INIT_8
#include <MemMap.h>


#define PROG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include <MemMap.h>

/* RAM data for instances */
STATIC VAR(PROG_HsmInstType, PROG_VAR_NOINIT)
  PROG_HsmInstPROG[PROG_HSM_PROG_NUM_INST];

#define PROG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include <MemMap.h>

/*==================[external data]=========================================*/

/*==================[internal constants]====================================*/

#define PROG_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/* *** array of entry/exit/do and transition actions *** */
STATIC CONST(PROG_HsmActionType, PROG_CONST)
  PROG_HsmPROGActions[PROG_HSM_PROG_NO_OF_ACTIONS] =
{
  &PROG_HsmPROGSfALIVEAction5,
  &PROG_HsmPROGSfCHECK_MEMORY_TOPAction1,
  &PROG_HsmPROGSfCHECK_MEMORY_TOPAction2,
  &PROG_HsmPROGSfCHECK_MEMORY_TOPAction4,
  &PROG_HsmPROGSfCHECK_MEMORY_TOPAction5,
  &PROG_HsmPROGSfBLU_PRE_RESETEntry,
  &PROG_HsmPROGSfBLU_RESUMEEntry,
  &PROG_HsmPROGSfCHECK_MEMORYEntry,
  &PROG_HsmPROGSfCHECK_MEMORYDo,
  &PROG_HsmPROGSfCHECK_MEMORYAction2,
  &PROG_HsmPROGSfCHECK_MEMORYAction3,
  &PROG_HsmPROGSfCHECK_MEMORY_FINISHEntry,
  &PROG_HsmPROGSfCHECK_MEMORY_FINISHExit,
  &PROG_HsmPROGSfCHECK_MEMORY_FINISHAction1,
  &PROG_HsmPROGSfSIGNATURE_CHECKEntry,
  &PROG_HsmPROGSfSIGNATURE_CHECKExit,
  &PROG_HsmPROGSfCOHERENCY_CHECK_TOPAction1,
  &PROG_HsmPROGSfCOHERENCY_CHECK_TOPAction3,
  &PROG_HsmPROGSfCOHERENCY_CHECK_TOPAction6,
  &PROG_HsmPROGSfCOHERENCY_CHECK_TOPAction7,
  &PROG_HsmPROGSfCOHERENCY_CHECKDo,
  &PROG_HsmPROGSfCOHERENCY_CHECK_FINISHAction1,
  &PROG_HsmPROGSfCOMPARE_KEYEntry,
  &PROG_HsmPROGSfCOMPARE_KEYAction1,
  &PROG_HsmPROGSfCOMPARE_KEYAction2,
  &PROG_HsmPROGSfCOMPARE_KEYAction3,
  &PROG_HsmPROGSfCOMPARE_KEYAction4,
  &PROG_HsmPROGSfCOMPARE_KEYAction5,
  &PROG_HsmPROGSfCOMPARE_KEYAction7,
  &PROG_HsmPROGSfCOMPARE_KEYAction8,
  &PROG_HsmPROGSfCOMPARE_KEYAction9,
  &PROG_HsmPROGSfDEFAULT_SESSIONEntry,
  &PROG_HsmPROGSfECU_RESETEntry,
  &PROG_HsmPROGSfERASE_TOPAction1,
  &PROG_HsmPROGSfERASE_TOPAction2,
  &PROG_HsmPROGSfERASE_TOPAction3,
  &PROG_HsmPROGSfERASE_TOPAction4,
  &PROG_HsmPROGSfERASE_TOPAction5,
  &PROG_HsmPROGSfERASE_TOPAction6,
  &PROG_HsmPROGSfERASE_TOPAction7,
  &PROG_HsmPROGSfERASE_TOPAction8,
  &PROG_HsmPROGSfERASEEntry,
  &PROG_HsmPROGSfERASEDo,
  &PROG_HsmPROGSfERASE_CHECKEntry,
  &PROG_HsmPROGSfERASE_FINISHEntry,
  &PROG_HsmPROGSfERASE_NRC78Entry,
  &PROG_HsmPROGSfERASE_TRANSMITNRC78Entry,
  &PROG_HsmPROGSfEXT_SESSIONEntry,
  &PROG_HsmPROGSfGET_SEEDEntry,
  &PROG_HsmPROGSfGET_SEEDAction1,
  &PROG_HsmPROGSfGET_SEEDAction2,
  &PROG_HsmPROGSfGET_SEEDAction4,
  &PROG_HsmPROGSfGET_SEEDAction5,
  &PROG_HsmPROGSfGET_SEEDAction6,
  &PROG_HsmPROGSfINITEntry,
  &PROG_HsmPROGSfINITExit,
  &PROG_HsmPROGSfLOCKEDAction1,
  &PROG_HsmPROGSfLOCKEDAction2,
  &PROG_HsmPROGSfLOCKEDAction3,
  &PROG_HsmPROGSfLOCKEDAction5,
  &PROG_HsmPROGSfLOCKEDAction6,
  &PROG_HsmPROGSfPROG_SESSIONEntry,
  &PROG_HsmPROGSfPROG_SESSIONAction2,
  &PROG_HsmPROGSfPROG_SESSIONAction3,
  &PROG_HsmPROGSfPROG_SESSIONAction4,
  &PROG_HsmPROGSfPROG_SESSIONAction6,
  &PROG_HsmPROGSfPROG_SESSIONAction7,
  &PROG_HsmPROGSfREPROGAction1,
  &PROG_HsmPROGSfREPROGAction2,
  &PROG_HsmPROGSfREPROGAction3,
  &PROG_HsmPROGSfREPROGAction4,
  &PROG_HsmPROGSfREPROGAction5,
  &PROG_HsmPROGSfREPROGAction6,
  &PROG_HsmPROGSfREPROGAction7,
  &PROG_HsmPROGSfRD_TOPAction1,
  &PROG_HsmPROGSfRD_TOPAction2,
  &PROG_HsmPROGSfRD_TOPAction3,
  &PROG_HsmPROGSfRDEntry,
  &PROG_HsmPROGSfRD_FINISHEntry,
  &PROG_HsmPROGSfRD_SIGNATUREEntry,
  &PROG_HsmPROGSfRTE_TOPAction1,
  &PROG_HsmPROGSfRTE_TOPAction2,
  &PROG_HsmPROGSfRTEEntry,
  &PROG_HsmPROGSfRTEDo,
  &PROG_HsmPROGSfRTE_DECOMPExit,
  &PROG_HsmPROGSfRTE_DECOMP_FINISHEntry,
  &PROG_HsmPROGSfRTE_DECOMP_WRITEEntry,
  &PROG_HsmPROGSfRTE_DECOMP_WRITEDo,
  &PROG_HsmPROGSfRTE_DECOMP_WRITE_CHECKEntry,
  &PROG_HsmPROGSfRTE_DECRYPTExit,
  &PROG_HsmPROGSfRTE_DECRYPT_FINISHEntry,
  &PROG_HsmPROGSfRTE_DECRYPT_FINISHDo,
  &PROG_HsmPROGSfRTE_WRITEEntry,
  &PROG_HsmPROGSfRTE_WRITEDo,
  &PROG_HsmPROGSfRTE_WRITE_CHECKDo,
  &PROG_HsmPROGSfRTE_FAILEDEntry,
  &PROG_HsmPROGSfRTE_FAILEDAction1,
  &PROG_HsmPROGSfRTE_FINISHEntry,
  &PROG_HsmPROGSfRTE_FINISHAction2,
  &PROG_HsmPROGSfTD_TOPAction2,
  &PROG_HsmPROGSfTD_TOPAction3,
  &PROG_HsmPROGSfTDEntry,
  &PROG_HsmPROGSfTD_CRCDo,
  &PROG_HsmPROGSfTD_CRCAction1,
  &PROG_HsmPROGSfTD_FAILEDEntry,
  &PROG_HsmPROGSfTD_STREAMINGEntry,
  &PROG_HsmPROGSfTD_WRITEExit,
  &PROG_HsmPROGSfTD_WRITEAction1,
  &PROG_HsmPROGSfTD_WRITEAction2,
  &PROG_HsmPROGSfDECRYPT_FINISHEntry,
  &PROG_HsmPROGSfDECRYPT_FINISHDo,
  &PROG_HsmPROGSfDECRYPT_UPDATEEntry,
  &PROG_HsmPROGSfDECRYPT_UPDATEDo,
  &PROG_HsmPROGSfWRITEEntry,
  &PROG_HsmPROGSfWRITEDo,
  &PROG_HsmPROGSfWRITE_CHECKDo,
  &PROG_HsmPROGSfRESETEntry,
  &PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPExit,
  &PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPAction1,
  &PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPAction3,
  &PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPAction6,
  &PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPAction7,
  &PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPAction8,
  &PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUMEntry,
  &PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUMDo,
  &PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUMAction1,
  &PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUMAction2,
  &PROG_HsmPROGSfWRITE_FINGERPRINTAction1,
  &PROG_HsmPROGSfWRITE_FINGERPRINTAction2,
  &PROG_HsmPROGSfWRITE_FINGERPRINTAction3,
  &PROG_HsmPROGSfWRITE_FINGERPRINTAction4,
  &PROG_HsmPROGSfWRITE_FINGERPRINTAction6,
  &PROG_HsmPROGSfWRITE_FINGERPRINTAction7,
  &PROG_HsmPROGSfWFP_INPROGRESSEntry,
  &PROG_HsmPROGSfWFP_INPROGRESSDo,
  &PROG_HsmPROGSfPRE_INITEntry,
  &PROG_HsmPROGSfPRE_INITDo,
  &PROG_HsmPROGSfSLEEPEntry,
};

/* *** array of guards *** */
STATIC CONST(PROG_HsmGuardType, PROG_CONST)
  PROG_HsmPROGGuards[PROG_HSM_PROG_NO_OF_GUARDS] =
{
  &PROG_HsmPROGSfCHECK_MEMORY_FINISHGuard3,
  &PROG_HsmPROGSfCHECK_MEMORY_FINISHGuard4,
  &PROG_HsmPROGSfCOHERENCY_CHECK_TOPGuard2,
  &PROG_HsmPROGSfCOHERENCY_CHECK_TOPGuard5,
  &PROG_HsmPROGSfERASE_FINISHGuard1,
  &PROG_HsmPROGSfERASE_FINISHGuard2,
  &PROG_HsmPROGSfRTE_FAILEDGuard2,
  &PROG_HsmPROGSfRTE_FAILEDGuard3,
  &PROG_HsmPROGSfRTE_FINISHGuard3,
  &PROG_HsmPROGSfTD_FAILEDGuard1,
  &PROG_HsmPROGSfTD_FAILEDGuard2,
  &PROG_HsmPROGSfVERIFY_PARTIAL_SW_CHECKSUM_TOPGuard4,
  &PROG_HsmPROGSfWFP_FINISHEDGuard1,
  &PROG_HsmPROGSfWFP_FINISHEDGuard2,
};

#define PROG_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

#define PROG_START_SEC_CONST_8
#include <MemMap.h>

/* *** exit/action/entry sequences for transitions *** */
/* trans sequence for transition #1 from state ALIVE */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrALIVESteps1[1] =
{
  PROG_HSM_PROG_AIDX_PROG_SESSION_ENTRY,
};
/* trans sequence for transition #2 from state ALIVE */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrALIVESteps2[1] =
{
  PROG_HSM_PROG_AIDX_DEFAULT_SESSION_ENTRY,
};
/* trans sequence for transition #3 from state ALIVE */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrALIVESteps3[1] =
{
  PROG_HSM_PROG_AIDX_EXT_SESSION_ENTRY,
};
/* trans sequence for transition #4 from state ALIVE */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrALIVESteps4[1] =
{
  PROG_HSM_PROG_AIDX_ECU_RESET_ENTRY,
};
/* trans sequence for transition #5 from state ALIVE */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrALIVESteps5[1] =
{
  PROG_HSM_PROG_AIDX_ALIVE_ACTION_5,
};
/* trans sequence for transition #6 from state ALIVE */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrALIVESteps6[1] =
{
  PROG_HSM_PROG_AIDX_RESET_ENTRY,
};
/* trans sequence for transition #7 from state ALIVE */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrALIVESteps7[1] =
{
  PROG_HSM_PROG_AIDX_RESET_ENTRY,
};
/* trans sequence for transition #1 from state CHECK_MEMORY_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCHECK_MEMORY_TOPSteps1[1] =
{
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_TOP_ACTION_1,
};
/* trans sequence for transition #2 from state CHECK_MEMORY_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCHECK_MEMORY_TOPSteps2[1] =
{
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_TOP_ACTION_2,
};
/* trans sequence for transition #4 from state CHECK_MEMORY_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCHECK_MEMORY_TOPSteps4[1] =
{
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_TOP_ACTION_4,
};
/* trans sequence for transition #5 from state CHECK_MEMORY_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCHECK_MEMORY_TOPSteps5[1] =
{
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_TOP_ACTION_5,
};
/* trans sequence for transition #1 from state BLU_PRE_RESET */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrBLU_PRE_RESETSteps1[1] =
{
  PROG_HSM_PROG_AIDX_RESET_ENTRY,
};
/* trans sequence for transition #1 from state BLU_RESUME */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrBLU_RESUMESteps1[1] =
{
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_FINISH_ENTRY,
};
/* trans sequence for transition #1 from state CHECK_MEMORY */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCHECK_MEMORYSteps1[1] =
{
  PROG_HSM_PROG_AIDX_BLU_PRE_RESET_ENTRY,
};
/* trans sequence for transition #2 from state CHECK_MEMORY */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCHECK_MEMORYSteps2[1] =
{
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_ACTION_2,
};
/* trans sequence for transition #3 from state CHECK_MEMORY */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCHECK_MEMORYSteps3[2] =
{
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_ACTION_3,
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_FINISH_ENTRY,
};
/* trans sequence for transition #4 from state CHECK_MEMORY */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCHECK_MEMORYSteps4[1] =
{
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_FINISH_ENTRY,
};
/* trans sequence for transition #1 from state CHECK_MEMORY_FINISH */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCHECK_MEMORY_FINISHSteps1[1] =
{
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_FINISH_ACTION_1,
};
/* trans sequence for transition #2 from state CHECK_MEMORY_FINISH */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCHECK_MEMORY_FINISHSteps2[1] =
{
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_FINISH_EXIT,
};
/* trans sequence for transition #3 from state CHECK_MEMORY_FINISH */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCHECK_MEMORY_FINISHSteps3[1] =
{
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_FINISH_EXIT,
};
/* trans sequence for transition #4 from state CHECK_MEMORY_FINISH */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCHECK_MEMORY_FINISHSteps4[1] =
{
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_FINISH_EXIT,
};
/* trans sequence for transition #1 from state SIGNATURE_CHECK */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrSIGNATURE_CHECKSteps1[2] =
{
  PROG_HSM_PROG_AIDX_SIGNATURE_CHECK_EXIT,
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_ENTRY,
};
/* trans sequence for transition #2 from state SIGNATURE_CHECK */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrSIGNATURE_CHECKSteps2[2] =
{
  PROG_HSM_PROG_AIDX_SIGNATURE_CHECK_EXIT,
  PROG_HSM_PROG_AIDX_CHECK_MEMORY_FINISH_ENTRY,
};
/* trans sequence for transition #1 from state COHERENCY_CHECK_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCOHERENCY_CHECK_TOPSteps1[1] =
{
  PROG_HSM_PROG_AIDX_COHERENCY_CHECK_TOP_ACTION_1,
};
/* trans sequence for transition #3 from state COHERENCY_CHECK_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCOHERENCY_CHECK_TOPSteps3[1] =
{
  PROG_HSM_PROG_AIDX_COHERENCY_CHECK_TOP_ACTION_3,
};
/* trans sequence for transition #6 from state COHERENCY_CHECK_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCOHERENCY_CHECK_TOPSteps6[1] =
{
  PROG_HSM_PROG_AIDX_COHERENCY_CHECK_TOP_ACTION_6,
};
/* trans sequence for transition #7 from state COHERENCY_CHECK_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCOHERENCY_CHECK_TOPSteps7[1] =
{
  PROG_HSM_PROG_AIDX_COHERENCY_CHECK_TOP_ACTION_7,
};
/* trans sequence for transition #1 from state COHERENCY_CHECK_FINISH */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCOHERENCY_CHECK_FINISHSteps1[1] =
{
  PROG_HSM_PROG_AIDX_COHERENCY_CHECK_FINISH_ACTION_1,
};
/* trans sequence for transition #1 from state COMPARE_KEY */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCOMPARE_KEYSteps1[1] =
{
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ACTION_1,
};
/* trans sequence for transition #2 from state COMPARE_KEY */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCOMPARE_KEYSteps2[1] =
{
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ACTION_2,
};
/* trans sequence for transition #3 from state COMPARE_KEY */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCOMPARE_KEYSteps3[1] =
{
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ACTION_3,
};
/* trans sequence for transition #4 from state COMPARE_KEY */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCOMPARE_KEYSteps4[1] =
{
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ACTION_4,
};
/* trans sequence for transition #5 from state COMPARE_KEY */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCOMPARE_KEYSteps5[1] =
{
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ACTION_5,
};
/* trans sequence for transition #7 from state COMPARE_KEY */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCOMPARE_KEYSteps7[1] =
{
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ACTION_7,
};
/* trans sequence for transition #8 from state COMPARE_KEY */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCOMPARE_KEYSteps8[1] =
{
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ACTION_8,
};
/* trans sequence for transition #9 from state COMPARE_KEY */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrCOMPARE_KEYSteps9[1] =
{
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ACTION_9,
};
/* trans sequence for transition #1 from state DEFAULT_SESSION */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrDEFAULT_SESSIONSteps1[1] =
{
  PROG_HSM_PROG_AIDX_RESET_ENTRY,
};
/* trans sequence for transition #1 from state ECU_RESET */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrECU_RESETSteps1[1] =
{
  PROG_HSM_PROG_AIDX_RESET_ENTRY,
};
/* trans sequence for transition #1 from state ERASE_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrERASE_TOPSteps1[1] =
{
  PROG_HSM_PROG_AIDX_ERASE_TOP_ACTION_1,
};
/* trans sequence for transition #2 from state ERASE_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrERASE_TOPSteps2[1] =
{
  PROG_HSM_PROG_AIDX_ERASE_TOP_ACTION_2,
};
/* trans sequence for transition #3 from state ERASE_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrERASE_TOPSteps3[1] =
{
  PROG_HSM_PROG_AIDX_ERASE_TOP_ACTION_3,
};
/* trans sequence for transition #4 from state ERASE_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrERASE_TOPSteps4[1] =
{
  PROG_HSM_PROG_AIDX_ERASE_TOP_ACTION_4,
};
/* trans sequence for transition #5 from state ERASE_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrERASE_TOPSteps5[1] =
{
  PROG_HSM_PROG_AIDX_ERASE_TOP_ACTION_5,
};
/* trans sequence for transition #6 from state ERASE_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrERASE_TOPSteps6[1] =
{
  PROG_HSM_PROG_AIDX_ERASE_TOP_ACTION_6,
};
/* trans sequence for transition #7 from state ERASE_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrERASE_TOPSteps7[1] =
{
  PROG_HSM_PROG_AIDX_ERASE_TOP_ACTION_7,
};
/* trans sequence for transition #8 from state ERASE_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrERASE_TOPSteps8[1] =
{
  PROG_HSM_PROG_AIDX_ERASE_TOP_ACTION_8,
};
/* trans sequence for transition #1 from state ERASE */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrERASESteps1[1] =
{
  PROG_HSM_PROG_AIDX_ERASE_FINISH_ENTRY,
};
/* trans sequence for transition #2 from state ERASE */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrERASESteps2[1] =
{
  PROG_HSM_PROG_AIDX_ERASE_NRC78_ENTRY,
};
/* trans sequence for transition #1 from state ERASE_CHECK */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrERASE_CHECKSteps1[1] =
{
  PROG_HSM_PROG_AIDX_ERASE_FINISH_ENTRY,
};
/* trans sequence for transition #2 from state ERASE_CHECK */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrERASE_CHECKSteps2[1] =
{
  PROG_HSM_PROG_AIDX_ERASE_ENTRY,
};
/* trans sequence for transition #1 from state ERASE_NRC78 */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrERASE_NRC78Steps1[1] =
{
  PROG_HSM_PROG_AIDX_ERASE_ENTRY,
};
/* trans sequence for transition #1 from state ERASE_TRANSMITNRC78 */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrERASE_TRANSMITNRC78Steps1[1] =
{
  PROG_HSM_PROG_AIDX_ERASE_CHECK_ENTRY,
};
/* trans sequence for transition #1 from state GET_SEED */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrGET_SEEDSteps1[1] =
{
  PROG_HSM_PROG_AIDX_GET_SEED_ACTION_1,
};
/* trans sequence for transition #2 from state GET_SEED */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrGET_SEEDSteps2[1] =
{
  PROG_HSM_PROG_AIDX_GET_SEED_ACTION_2,
};
/* trans sequence for transition #3 from state GET_SEED */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrGET_SEEDSteps3[1] =
{
  PROG_HSM_PROG_AIDX_COMPARE_KEY_ENTRY,
};
/* trans sequence for transition #4 from state GET_SEED */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrGET_SEEDSteps4[1] =
{
  PROG_HSM_PROG_AIDX_GET_SEED_ACTION_4,
};
/* trans sequence for transition #5 from state GET_SEED */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrGET_SEEDSteps5[1] =
{
  PROG_HSM_PROG_AIDX_GET_SEED_ACTION_5,
};
/* trans sequence for transition #6 from state GET_SEED */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrGET_SEEDSteps6[1] =
{
  PROG_HSM_PROG_AIDX_GET_SEED_ACTION_6,
};
/* trans sequence for transition #1 from state INIT */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrINITSteps1[2] =
{
  PROG_HSM_PROG_AIDX_INIT_EXIT,
  PROG_HSM_PROG_AIDX_SLEEP_ENTRY,
};
/* trans sequence for transition #1 from state LOCKED */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrLOCKEDSteps1[1] =
{
  PROG_HSM_PROG_AIDX_LOCKED_ACTION_1,
};
/* trans sequence for transition #2 from state LOCKED */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrLOCKEDSteps2[1] =
{
  PROG_HSM_PROG_AIDX_LOCKED_ACTION_2,
};
/* trans sequence for transition #3 from state LOCKED */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrLOCKEDSteps3[1] =
{
  PROG_HSM_PROG_AIDX_LOCKED_ACTION_3,
};
/* trans sequence for transition #4 from state LOCKED */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrLOCKEDSteps4[1] =
{
  PROG_HSM_PROG_AIDX_GET_SEED_ENTRY,
};
/* trans sequence for transition #5 from state LOCKED */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrLOCKEDSteps5[1] =
{
  PROG_HSM_PROG_AIDX_LOCKED_ACTION_5,
};
/* trans sequence for transition #6 from state LOCKED */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrLOCKEDSteps6[1] =
{
  PROG_HSM_PROG_AIDX_LOCKED_ACTION_6,
};
/* trans sequence for transition #1 from state PROG_SESSION */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrPROG_SESSIONSteps1[1] =
{
  PROG_HSM_PROG_AIDX_BLU_RESUME_ENTRY,
};
/* trans sequence for transition #2 from state PROG_SESSION */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrPROG_SESSIONSteps2[1] =
{
  PROG_HSM_PROG_AIDX_PROG_SESSION_ACTION_2,
};
/* trans sequence for transition #3 from state PROG_SESSION */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrPROG_SESSIONSteps3[1] =
{
  PROG_HSM_PROG_AIDX_PROG_SESSION_ACTION_3,
};
/* trans sequence for transition #4 from state PROG_SESSION */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrPROG_SESSIONSteps4[1] =
{
  PROG_HSM_PROG_AIDX_PROG_SESSION_ACTION_4,
};
/* trans sequence for transition #5 from state PROG_SESSION */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrPROG_SESSIONSteps5[1] =
{
  PROG_HSM_PROG_AIDX_GET_SEED_ENTRY,
};
/* trans sequence for transition #6 from state PROG_SESSION */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrPROG_SESSIONSteps6[1] =
{
  PROG_HSM_PROG_AIDX_PROG_SESSION_ACTION_6,
};
/* trans sequence for transition #7 from state PROG_SESSION */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrPROG_SESSIONSteps7[1] =
{
  PROG_HSM_PROG_AIDX_PROG_SESSION_ACTION_7,
};
/* trans sequence for transition #1 from state REPROG */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrREPROGSteps1[1] =
{
  PROG_HSM_PROG_AIDX_REPROG_ACTION_1,
};
/* trans sequence for transition #2 from state REPROG */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrREPROGSteps2[1] =
{
  PROG_HSM_PROG_AIDX_REPROG_ACTION_2,
};
/* trans sequence for transition #3 from state REPROG */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrREPROGSteps3[1] =
{
  PROG_HSM_PROG_AIDX_REPROG_ACTION_3,
};
/* trans sequence for transition #4 from state REPROG */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrREPROGSteps4[1] =
{
  PROG_HSM_PROG_AIDX_REPROG_ACTION_4,
};
/* trans sequence for transition #5 from state REPROG */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrREPROGSteps5[1] =
{
  PROG_HSM_PROG_AIDX_REPROG_ACTION_5,
};
/* trans sequence for transition #6 from state REPROG */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrREPROGSteps6[1] =
{
  PROG_HSM_PROG_AIDX_REPROG_ACTION_6,
};
/* trans sequence for transition #7 from state REPROG */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrREPROGSteps7[1] =
{
  PROG_HSM_PROG_AIDX_REPROG_ACTION_7,
};
/* trans sequence for transition #1 from state RD_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRD_TOPSteps1[1] =
{
  PROG_HSM_PROG_AIDX_RD_TOP_ACTION_1,
};
/* trans sequence for transition #2 from state RD_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRD_TOPSteps2[1] =
{
  PROG_HSM_PROG_AIDX_RD_TOP_ACTION_2,
};
/* trans sequence for transition #3 from state RD_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRD_TOPSteps3[1] =
{
  PROG_HSM_PROG_AIDX_RD_TOP_ACTION_3,
};
/* trans sequence for transition #5 from state RD_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRD_TOPSteps5[1] =
{
  PROG_HSM_PROG_AIDX_TD_STREAMING_ENTRY,
};
/* trans sequence for transition #1 from state RD */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRDSteps1[1] =
{
  PROG_HSM_PROG_AIDX_RD_SIGNATURE_ENTRY,
};
/* trans sequence for transition #1 from state RD_SIGNATURE */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRD_SIGNATURESteps1[1] =
{
  PROG_HSM_PROG_AIDX_RD_FINISH_ENTRY,
};
/* trans sequence for transition #1 from state RTE_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRTE_TOPSteps1[1] =
{
  PROG_HSM_PROG_AIDX_RTE_TOP_ACTION_1,
};
/* trans sequence for transition #2 from state RTE_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRTE_TOPSteps2[1] =
{
  PROG_HSM_PROG_AIDX_RTE_TOP_ACTION_2,
};
/* trans sequence for transition #2 from state RTE */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRTESteps2[1] =
{
  PROG_HSM_PROG_AIDX_RTE_FAILED_ENTRY,
};
/* trans sequence for transition #3 from state RTE */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRTESteps3[1] =
{
  PROG_HSM_PROG_AIDX_RTE_FINISH_ENTRY,
};
/* trans sequence for transition #1 from state RTE_DECOMP_FINISH */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRTE_DECOMP_FINISHSteps1[1] =
{
  PROG_HSM_PROG_AIDX_RTE_DECOMP_WRITE_ENTRY,
};
/* trans sequence for transition #2 from state RTE_DECOMP_FINISH */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRTE_DECOMP_FINISHSteps2[1] =
{
  PROG_HSM_PROG_AIDX_RTE_DECOMP_WRITE_CHECK_ENTRY,
};
/* trans sequence for transition #1 from state RTE_DECOMP_WRITE */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRTE_DECOMP_WRITESteps1[1] =
{
  PROG_HSM_PROG_AIDX_RTE_DECOMP_WRITE_CHECK_ENTRY,
};
/* trans sequence for transition #1 from state RTE_DECOMP_WRITE_CHECK */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRTE_DECOMP_WRITE_CHECKSteps1[2] =
{
  PROG_HSM_PROG_AIDX_RTE_DECOMP_EXIT,
  PROG_HSM_PROG_AIDX_RTE_ENTRY,
};
/* trans sequence for transition #2 from state RTE_DECOMP_WRITE_CHECK */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRTE_DECOMP_WRITE_CHECKSteps2[1] =
{
  PROG_HSM_PROG_AIDX_RTE_DECOMP_WRITE_ENTRY,
};
/* trans sequence for transition #1 from state RTE_DECRYPT_FINISH */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRTE_DECRYPT_FINISHSteps1[1] =
{
  PROG_HSM_PROG_AIDX_RTE_WRITE_ENTRY,
};
/* trans sequence for transition #1 from state RTE_WRITE_CHECK */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRTE_WRITE_CHECKSteps1[2] =
{
  PROG_HSM_PROG_AIDX_RTE_DECRYPT_EXIT,
  PROG_HSM_PROG_AIDX_RTE_ENTRY,
};
/* trans sequence for transition #2 from state RTE_WRITE_CHECK */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRTE_WRITE_CHECKSteps2[1] =
{
  PROG_HSM_PROG_AIDX_RTE_WRITE_ENTRY,
};
/* trans sequence for transition #1 from state RTE_FAILED */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRTE_FAILEDSteps1[1] =
{
  PROG_HSM_PROG_AIDX_RTE_FAILED_ACTION_1,
};
/* trans sequence for transition #2 from state RTE_FINISH */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrRTE_FINISHSteps2[1] =
{
  PROG_HSM_PROG_AIDX_RTE_FINISH_ACTION_2,
};
/* trans sequence for transition #1 from state TD_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrTD_TOPSteps1[1] =
{
  PROG_HSM_PROG_AIDX_TD_FAILED_ENTRY,
};
/* trans sequence for transition #2 from state TD_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrTD_TOPSteps2[1] =
{
  PROG_HSM_PROG_AIDX_TD_TOP_ACTION_2,
};
/* trans sequence for transition #3 from state TD_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrTD_TOPSteps3[1] =
{
  PROG_HSM_PROG_AIDX_TD_TOP_ACTION_3,
};
/* trans sequence for transition #1 from state TD_CRC */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrTD_CRCSteps1[1] =
{
  PROG_HSM_PROG_AIDX_TD_CRC_ACTION_1,
};
/* trans sequence for transition #2 from state TD_CRC */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrTD_CRCSteps2[1] =
{
  PROG_HSM_PROG_AIDX_TD_ENTRY,
};
/* trans sequence for transition #3 from state TD_CRC */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrTD_CRCSteps3[1] =
{
  PROG_HSM_PROG_AIDX_TD_STREAMING_ENTRY,
};
/* trans sequence for transition #3 from state TD_FAILED */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrTD_FAILEDSteps3[1] =
{
  PROG_HSM_PROG_AIDX_TD_ENTRY,
};
/* trans sequence for transition #4 from state TD_FAILED */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrTD_FAILEDSteps4[1] =
{
  PROG_HSM_PROG_AIDX_TD_STREAMING_ENTRY,
};
/* trans sequence for transition #1 from state TD_WRITE */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrTD_WRITESteps1[1] =
{
  PROG_HSM_PROG_AIDX_TD_WRITE_ACTION_1,
};
/* trans sequence for transition #2 from state TD_WRITE */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrTD_WRITESteps2[1] =
{
  PROG_HSM_PROG_AIDX_TD_WRITE_ACTION_2,
};
/* trans sequence for transition #1 from state DECRYPT_FINISH */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrDECRYPT_FINISHSteps1[1] =
{
  PROG_HSM_PROG_AIDX_WRITE_ENTRY,
};
/* trans sequence for transition #1 from state WRITE_CHECK */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrWRITE_CHECKSteps1[1] =
{
  PROG_HSM_PROG_AIDX_DECRYPT_FINISH_ENTRY,
};
/* trans sequence for transition #2 from state WRITE_CHECK */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrWRITE_CHECKSteps2[1] =
{
  PROG_HSM_PROG_AIDX_TD_WRITE_EXIT,
};
/* trans sequence for transition #3 from state WRITE_CHECK */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrWRITE_CHECKSteps3[1] =
{
  PROG_HSM_PROG_AIDX_WRITE_ENTRY,
};
/* trans sequence for transition #1 from state VERIFY_PARTIAL_SW_CHECKSUM_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps1[1] =
{
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_ACTION_1,
};
/* trans sequence for transition #2 from state VERIFY_PARTIAL_SW_CHECKSUM_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps2[1] =
{
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_EXIT,
};
/* trans sequence for transition #3 from state VERIFY_PARTIAL_SW_CHECKSUM_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps3[1] =
{
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_ACTION_3,
};
/* trans sequence for transition #4 from state VERIFY_PARTIAL_SW_CHECKSUM_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps4[1] =
{
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_EXIT,
};
/* trans sequence for transition #5 from state VERIFY_PARTIAL_SW_CHECKSUM_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps5[2] =
{
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_EXIT,
  PROG_HSM_PROG_AIDX_GET_SEED_ENTRY,
};
/* trans sequence for transition #6 from state VERIFY_PARTIAL_SW_CHECKSUM_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps6[1] =
{
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_ACTION_6,
};
/* trans sequence for transition #7 from state VERIFY_PARTIAL_SW_CHECKSUM_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps7[1] =
{
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_ACTION_7,
};
/* trans sequence for transition #8 from state VERIFY_PARTIAL_SW_CHECKSUM_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps8[1] =
{
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_ACTION_8,
};
/* trans sequence for transition #9 from state VERIFY_PARTIAL_SW_CHECKSUM_TOP */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps9[1] =
{
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_EXIT,
};
/* trans sequence for transition #1 from state VERIFY_PARTIAL_SW_CHECKSUM */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUMSteps1[1] =
{
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_ACTION_1,
};
/* trans sequence for transition #2 from state VERIFY_PARTIAL_SW_CHECKSUM */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUMSteps2[1] =
{
  PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_ACTION_2,
};
/* trans sequence for transition #1 from state WRITE_FINGERPRINT */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrWRITE_FINGERPRINTSteps1[1] =
{
  PROG_HSM_PROG_AIDX_WRITE_FINGERPRINT_ACTION_1,
};
/* trans sequence for transition #2 from state WRITE_FINGERPRINT */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrWRITE_FINGERPRINTSteps2[1] =
{
  PROG_HSM_PROG_AIDX_WRITE_FINGERPRINT_ACTION_2,
};
/* trans sequence for transition #3 from state WRITE_FINGERPRINT */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrWRITE_FINGERPRINTSteps3[1] =
{
  PROG_HSM_PROG_AIDX_WRITE_FINGERPRINT_ACTION_3,
};
/* trans sequence for transition #4 from state WRITE_FINGERPRINT */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrWRITE_FINGERPRINTSteps4[1] =
{
  PROG_HSM_PROG_AIDX_WRITE_FINGERPRINT_ACTION_4,
};
/* trans sequence for transition #6 from state WRITE_FINGERPRINT */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrWRITE_FINGERPRINTSteps6[1] =
{
  PROG_HSM_PROG_AIDX_WRITE_FINGERPRINT_ACTION_6,
};
/* trans sequence for transition #7 from state WRITE_FINGERPRINT */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrWRITE_FINGERPRINTSteps7[1] =
{
  PROG_HSM_PROG_AIDX_WRITE_FINGERPRINT_ACTION_7,
};
/* trans sequence for transition #2 from state PRE_INIT */
STATIC CONST(PROG_HsmActionIdxType, PROG_CONST)
  PROG_HsmTrPRE_INITSteps2[1] =
{
  PROG_HSM_PROG_AIDX_SLEEP_ENTRY,
};

#define PROG_STOP_SEC_CONST_8
#include <MemMap.h>

/* ****** */

#define PROG_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/* transitions from state ALIVE */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrALIVE[7] =
{
{
  PROG_HsmTrALIVESteps1,
  sizeof(PROG_HsmTrALIVESteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_PROG_SESSION /* target state */
},
{
  PROG_HsmTrALIVESteps2,
  sizeof(PROG_HsmTrALIVESteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_DEFAULT_SESSION /* target state */
},
{
  PROG_HsmTrALIVESteps3,
  sizeof(PROG_HsmTrALIVESteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_EXT_SESSION /* target state */
},
{
  PROG_HsmTrALIVESteps4,
  sizeof(PROG_HsmTrALIVESteps4)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_ECU_RESET /* target state */
},
{
  PROG_HsmTrALIVESteps5,
  sizeof(PROG_HsmTrALIVESteps5)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrALIVESteps6,
  sizeof(PROG_HsmTrALIVESteps6)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_RESET, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RESET /* target state */
},
{
  PROG_HsmTrALIVESteps7,
  sizeof(PROG_HsmTrALIVESteps7)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RESET /* target state */
},
};
/* transitions from state CHECK_MEMORY_TOP */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrCHECK_MEMORY_TOP[6] =
{
{
  PROG_HsmTrCHECK_MEMORY_TOPSteps1,
  sizeof(PROG_HsmTrCHECK_MEMORY_TOPSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrCHECK_MEMORY_TOPSteps2,
  sizeof(PROG_HsmTrCHECK_MEMORY_TOPSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP /* target state */
},
{
  PROG_HsmTrCHECK_MEMORY_TOPSteps4,
  sizeof(PROG_HsmTrCHECK_MEMORY_TOPSteps4)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrCHECK_MEMORY_TOPSteps5,
  sizeof(PROG_HsmTrCHECK_MEMORY_TOPSteps5)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_WRITE_FINGERPRINT /* target state */
},
};
/* transitions from state BLU_PRE_RESET */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrBLU_PRE_RESET[1] =
{
{
  PROG_HsmTrBLU_PRE_RESETSteps1,
  sizeof(PROG_HsmTrBLU_PRE_RESETSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RESET /* target state */
},
};
/* transitions from state BLU_RESUME */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrBLU_RESUME[1] =
{
{
  PROG_HsmTrBLU_RESUMESteps1,
  sizeof(PROG_HsmTrBLU_RESUMESteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_FINISHED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_CHECK_MEMORY_FINISH /* target state */
},
};
/* transitions from state CHECK_MEMORY */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrCHECK_MEMORY[4] =
{
{
  PROG_HsmTrCHECK_MEMORYSteps1,
  sizeof(PROG_HsmTrCHECK_MEMORYSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_BLU_PRE_RESET /* target state */
},
{
  PROG_HsmTrCHECK_MEMORYSteps2,
  sizeof(PROG_HsmTrCHECK_MEMORYSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrCHECK_MEMORYSteps3,
  sizeof(PROG_HsmTrCHECK_MEMORYSteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_CHECK_MEMORY_FINISH /* target state */
},
{
  PROG_HsmTrCHECK_MEMORYSteps4,
  sizeof(PROG_HsmTrCHECK_MEMORYSteps4)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_FINISHED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_CHECK_MEMORY_FINISH /* target state */
},
};
/* transitions from state CHECK_MEMORY_FINISH */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrCHECK_MEMORY_FINISH[4] =
{
{
  PROG_HsmTrCHECK_MEMORY_FINISHSteps1,
  sizeof(PROG_HsmTrCHECK_MEMORY_FINISHSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrCHECK_MEMORY_FINISHSteps2,
  sizeof(PROG_HsmTrCHECK_MEMORY_FINISHSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_COHERENCY_CHECK_TOP /* target state */
},
{
  PROG_HsmTrCHECK_MEMORY_FINISHSteps3,
  sizeof(PROG_HsmTrCHECK_MEMORY_FINISHSteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE, /* triggering event */
  PROG_HSM_PROG_GIDX_CHECK_MEMORY_FINISH_GUARD_3, /* guard idx */
  PROG_HSM_PROG_SIDX_ERASE_TOP /* target state */
},
{
  PROG_HsmTrCHECK_MEMORY_FINISHSteps4,
  sizeof(PROG_HsmTrCHECK_MEMORY_FINISHSteps4)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD, /* triggering event */
  PROG_HSM_PROG_GIDX_CHECK_MEMORY_FINISH_GUARD_4, /* guard idx */
  PROG_HSM_PROG_SIDX_REPROG /* target state */
},
};
/* transitions from state SIGNATURE_CHECK */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrSIGNATURE_CHECK[2] =
{
{
  PROG_HsmTrSIGNATURE_CHECKSteps1,
  sizeof(PROG_HsmTrSIGNATURE_CHECKSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_CHECK_MEMORY /* target state */
},
{
  PROG_HsmTrSIGNATURE_CHECKSteps2,
  sizeof(PROG_HsmTrSIGNATURE_CHECKSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_FAILED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_CHECK_MEMORY_FINISH /* target state */
},
};
/* transitions from state COHERENCY_CHECK_TOP */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrCOHERENCY_CHECK_TOP[8] =
{
{
  PROG_HsmTrCOHERENCY_CHECK_TOPSteps1,
  sizeof(PROG_HsmTrCOHERENCY_CHECK_TOPSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE, /* triggering event */
  PROG_HSM_PROG_GIDX_COHERENCY_CHECK_TOP_GUARD_2, /* guard idx */
  PROG_HSM_PROG_SIDX_ERASE_TOP /* target state */
},
{
  PROG_HsmTrCOHERENCY_CHECK_TOPSteps3,
  sizeof(PROG_HsmTrCOHERENCY_CHECK_TOPSteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP /* target state */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD, /* triggering event */
  PROG_HSM_PROG_GIDX_COHERENCY_CHECK_TOP_GUARD_5, /* guard idx */
  PROG_HSM_PROG_SIDX_REPROG /* target state */
},
{
  PROG_HsmTrCOHERENCY_CHECK_TOPSteps6,
  sizeof(PROG_HsmTrCOHERENCY_CHECK_TOPSteps6)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrCOHERENCY_CHECK_TOPSteps7,
  sizeof(PROG_HsmTrCOHERENCY_CHECK_TOPSteps7)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_WRITE_FINGERPRINT /* target state */
},
};
/* transitions from state COHERENCY_CHECK */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrCOHERENCY_CHECK[1] =
{
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_FINISHED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_COHERENCY_CHECK_FINISH /* target state */
},
};
/* transitions from state COHERENCY_CHECK_FINISH */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrCOHERENCY_CHECK_FINISH[2] =
{
{
  PROG_HsmTrCOHERENCY_CHECK_FINISHSteps1,
  sizeof(PROG_HsmTrCOHERENCY_CHECK_FINISHSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_COHERENCY_CHECK_TOP /* target state */
},
};
/* transitions from state COMPARE_KEY */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrCOMPARE_KEY[11] =
{
{
  PROG_HsmTrCOMPARE_KEYSteps1,
  sizeof(PROG_HsmTrCOMPARE_KEYSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrCOMPARE_KEYSteps2,
  sizeof(PROG_HsmTrCOMPARE_KEYSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrCOMPARE_KEYSteps3,
  sizeof(PROG_HsmTrCOMPARE_KEYSteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrCOMPARE_KEYSteps4,
  sizeof(PROG_HsmTrCOMPARE_KEYSteps4)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrCOMPARE_KEYSteps5,
  sizeof(PROG_HsmTrCOMPARE_KEYSteps5)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP /* target state */
},
{
  PROG_HsmTrCOMPARE_KEYSteps7,
  sizeof(PROG_HsmTrCOMPARE_KEYSteps7)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrCOMPARE_KEYSteps8,
  sizeof(PROG_HsmTrCOMPARE_KEYSteps8)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrCOMPARE_KEYSteps9,
  sizeof(PROG_HsmTrCOMPARE_KEYSteps9)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_WRITE_FINGERPRINT /* target state */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_LOCKED /* target state */
},
};
/* transitions from state DEFAULT_SESSION */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrDEFAULT_SESSION[1] =
{
{
  PROG_HsmTrDEFAULT_SESSIONSteps1,
  sizeof(PROG_HsmTrDEFAULT_SESSIONSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RESET /* target state */
},
};
/* transitions from state ECU_RESET */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrECU_RESET[1] =
{
{
  PROG_HsmTrECU_RESETSteps1,
  sizeof(PROG_HsmTrECU_RESETSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RESET /* target state */
},
};
/* transitions from state ERASE_TOP */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrERASE_TOP[8] =
{
{
  PROG_HsmTrERASE_TOPSteps1,
  sizeof(PROG_HsmTrERASE_TOPSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrERASE_TOPSteps2,
  sizeof(PROG_HsmTrERASE_TOPSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrERASE_TOPSteps3,
  sizeof(PROG_HsmTrERASE_TOPSteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrERASE_TOPSteps4,
  sizeof(PROG_HsmTrERASE_TOPSteps4)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrERASE_TOPSteps5,
  sizeof(PROG_HsmTrERASE_TOPSteps5)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrERASE_TOPSteps6,
  sizeof(PROG_HsmTrERASE_TOPSteps6)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrERASE_TOPSteps7,
  sizeof(PROG_HsmTrERASE_TOPSteps7)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrERASE_TOPSteps8,
  sizeof(PROG_HsmTrERASE_TOPSteps8)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
};
/* transitions from state ERASE */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrERASE[2] =
{
{
  PROG_HsmTrERASESteps1,
  sizeof(PROG_HsmTrERASESteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_FINISHED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_ERASE_FINISH /* target state */
},
{
  PROG_HsmTrERASESteps2,
  sizeof(PROG_HsmTrERASESteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_ERASE_NRC78 /* target state */
},
};
/* transitions from state ERASE_CHECK */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrERASE_CHECK[2] =
{
{
  PROG_HsmTrERASE_CHECKSteps1,
  sizeof(PROG_HsmTrERASE_CHECKSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_FINISHED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_ERASE_FINISH /* target state */
},
{
  PROG_HsmTrERASE_CHECKSteps2,
  sizeof(PROG_HsmTrERASE_CHECKSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_ERASE /* target state */
},
};
/* transitions from state ERASE_FINISH */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrERASE_FINISH[2] =
{
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE, /* triggering event */
  PROG_HSM_PROG_GIDX_ERASE_FINISH_GUARD_1, /* guard idx */
  PROG_HSM_PROG_SIDX_ERASE_TOP /* target state */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD, /* triggering event */
  PROG_HSM_PROG_GIDX_ERASE_FINISH_GUARD_2, /* guard idx */
  PROG_HSM_PROG_SIDX_REPROG /* target state */
},
};
/* transitions from state ERASE_NRC78 */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrERASE_NRC78[1] =
{
{
  PROG_HsmTrERASE_NRC78Steps1,
  sizeof(PROG_HsmTrERASE_NRC78Steps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_ERASE /* target state */
},
};
/* transitions from state ERASE_TRANSMITNRC78 */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrERASE_TRANSMITNRC78[1] =
{
{
  PROG_HsmTrERASE_TRANSMITNRC78Steps1,
  sizeof(PROG_HsmTrERASE_TRANSMITNRC78Steps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_ERASE_CHECK /* target state */
},
};
/* transitions from state EXT_SESSION */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrEXT_SESSION[1] =
{
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP /* target state */
},
};
/* transitions from state GET_SEED */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrGET_SEED[7] =
{
{
  PROG_HsmTrGET_SEEDSteps1,
  sizeof(PROG_HsmTrGET_SEEDSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrGET_SEEDSteps2,
  sizeof(PROG_HsmTrGET_SEEDSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrGET_SEEDSteps3,
  sizeof(PROG_HsmTrGET_SEEDSteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_COMPARE_KEY /* target state */
},
{
  PROG_HsmTrGET_SEEDSteps4,
  sizeof(PROG_HsmTrGET_SEEDSteps4)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrGET_SEEDSteps5,
  sizeof(PROG_HsmTrGET_SEEDSteps5)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrGET_SEEDSteps6,
  sizeof(PROG_HsmTrGET_SEEDSteps6)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_LOCKED /* target state */
},
};
/* transitions from state INIT */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrINIT[1] =
{
{
  PROG_HsmTrINITSteps1,
  sizeof(PROG_HsmTrINITSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_SLEEP, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_SLEEP /* target state */
},
};
/* transitions from state LOCKED */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrLOCKED[6] =
{
{
  PROG_HsmTrLOCKEDSteps1,
  sizeof(PROG_HsmTrLOCKEDSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrLOCKEDSteps2,
  sizeof(PROG_HsmTrLOCKEDSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrLOCKEDSteps3,
  sizeof(PROG_HsmTrLOCKEDSteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrLOCKEDSteps4,
  sizeof(PROG_HsmTrLOCKEDSteps4)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_GET_SEED /* target state */
},
{
  PROG_HsmTrLOCKEDSteps5,
  sizeof(PROG_HsmTrLOCKEDSteps5)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrLOCKEDSteps6,
  sizeof(PROG_HsmTrLOCKEDSteps6)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
};
/* transitions from state PROG_SESSION */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrPROG_SESSION[7] =
{
{
  PROG_HsmTrPROG_SESSIONSteps1,
  sizeof(PROG_HsmTrPROG_SESSIONSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_BLU_RESUME /* target state */
},
{
  PROG_HsmTrPROG_SESSIONSteps2,
  sizeof(PROG_HsmTrPROG_SESSIONSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrPROG_SESSIONSteps3,
  sizeof(PROG_HsmTrPROG_SESSIONSteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrPROG_SESSIONSteps4,
  sizeof(PROG_HsmTrPROG_SESSIONSteps4)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrPROG_SESSIONSteps5,
  sizeof(PROG_HsmTrPROG_SESSIONSteps5)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_GET_SEED /* target state */
},
{
  PROG_HsmTrPROG_SESSIONSteps6,
  sizeof(PROG_HsmTrPROG_SESSIONSteps6)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrPROG_SESSIONSteps7,
  sizeof(PROG_HsmTrPROG_SESSIONSteps7)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
};
/* transitions from state REPROG */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrREPROG[7] =
{
{
  PROG_HsmTrREPROGSteps1,
  sizeof(PROG_HsmTrREPROGSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrREPROGSteps2,
  sizeof(PROG_HsmTrREPROGSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrREPROGSteps3,
  sizeof(PROG_HsmTrREPROGSteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrREPROGSteps4,
  sizeof(PROG_HsmTrREPROGSteps4)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrREPROGSteps5,
  sizeof(PROG_HsmTrREPROGSteps5)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrREPROGSteps6,
  sizeof(PROG_HsmTrREPROGSteps6)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrREPROGSteps7,
  sizeof(PROG_HsmTrREPROGSteps7)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
};
/* transitions from state RD_TOP */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrRD_TOP[5] =
{
{
  PROG_HsmTrRD_TOPSteps1,
  sizeof(PROG_HsmTrRD_TOPSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrRD_TOPSteps2,
  sizeof(PROG_HsmTrRD_TOPSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrRD_TOPSteps3,
  sizeof(PROG_HsmTrRD_TOPSteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_TD_TOP /* target state */
},
{
  PROG_HsmTrRD_TOPSteps5,
  sizeof(PROG_HsmTrRD_TOPSteps5)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_STREAMING, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_TD_STREAMING /* target state */
},
};
/* transitions from state RD */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrRD[1] =
{
{
  PROG_HsmTrRDSteps1,
  sizeof(PROG_HsmTrRDSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RD_SIGNATURE /* target state */
},
};
/* transitions from state RD_FINISH */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrRD_FINISH[1] =
{
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RD_TOP /* target state */
},
};
/* transitions from state RD_SIGNATURE */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrRD_SIGNATURE[1] =
{
{
  PROG_HsmTrRD_SIGNATURESteps1,
  sizeof(PROG_HsmTrRD_SIGNATURESteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RD_FINISH /* target state */
},
};
/* transitions from state RTE_TOP */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrRTE_TOP[2] =
{
{
  PROG_HsmTrRTE_TOPSteps1,
  sizeof(PROG_HsmTrRTE_TOPSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrRTE_TOPSteps2,
  sizeof(PROG_HsmTrRTE_TOPSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
};
/* transitions from state RTE */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrRTE[4] =
{
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RTE_DECRYPT /* target state */
},
{
  PROG_HsmTrRTESteps2,
  sizeof(PROG_HsmTrRTESteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_FAILED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RTE_FAILED /* target state */
},
{
  PROG_HsmTrRTESteps3,
  sizeof(PROG_HsmTrRTESteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_FINISHED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RTE_FINISH /* target state */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_WRITE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RTE_DECOMP /* target state */
},
};
/* transitions from state RTE_DECOMP_FINISH */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrRTE_DECOMP_FINISH[2] =
{
{
  PROG_HsmTrRTE_DECOMP_FINISHSteps1,
  sizeof(PROG_HsmTrRTE_DECOMP_FINISHSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_WRITE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RTE_DECOMP_WRITE /* target state */
},
{
  PROG_HsmTrRTE_DECOMP_FINISHSteps2,
  sizeof(PROG_HsmTrRTE_DECOMP_FINISHSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RTE_DECOMP_WRITE_CHECK /* target state */
},
};
/* transitions from state RTE_DECOMP_WRITE */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrRTE_DECOMP_WRITE[1] =
{
{
  PROG_HsmTrRTE_DECOMP_WRITESteps1,
  sizeof(PROG_HsmTrRTE_DECOMP_WRITESteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RTE_DECOMP_WRITE_CHECK /* target state */
},
};
/* transitions from state RTE_DECOMP_WRITE_CHECK */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrRTE_DECOMP_WRITE_CHECK[2] =
{
{
  PROG_HsmTrRTE_DECOMP_WRITE_CHECKSteps1,
  sizeof(PROG_HsmTrRTE_DECOMP_WRITE_CHECKSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_TD_END, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RTE /* target state */
},
{
  PROG_HsmTrRTE_DECOMP_WRITE_CHECKSteps2,
  sizeof(PROG_HsmTrRTE_DECOMP_WRITE_CHECKSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_WRITE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RTE_DECOMP_WRITE /* target state */
},
};
/* transitions from state RTE_DECRYPT_FINISH */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrRTE_DECRYPT_FINISH[2] =
{
{
  PROG_HsmTrRTE_DECRYPT_FINISHSteps1,
  sizeof(PROG_HsmTrRTE_DECRYPT_FINISHSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_WRITE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RTE_WRITE /* target state */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RTE_WRITE_CHECK /* target state */
},
};
/* transitions from state RTE_WRITE */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrRTE_WRITE[1] =
{
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RTE_WRITE_CHECK /* target state */
},
};
/* transitions from state RTE_WRITE_CHECK */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrRTE_WRITE_CHECK[2] =
{
{
  PROG_HsmTrRTE_WRITE_CHECKSteps1,
  sizeof(PROG_HsmTrRTE_WRITE_CHECKSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_TD_END, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RTE /* target state */
},
{
  PROG_HsmTrRTE_WRITE_CHECKSteps2,
  sizeof(PROG_HsmTrRTE_WRITE_CHECKSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_WRITE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RTE_WRITE /* target state */
},
};
/* transitions from state RTE_FAILED */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrRTE_FAILED[3] =
{
{
  PROG_HsmTrRTE_FAILEDSteps1,
  sizeof(PROG_HsmTrRTE_FAILEDSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE, /* triggering event */
  PROG_HSM_PROG_GIDX_RTE_FAILED_GUARD_2, /* guard idx */
  PROG_HSM_PROG_SIDX_ERASE_TOP /* target state */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD, /* triggering event */
  PROG_HSM_PROG_GIDX_RTE_FAILED_GUARD_3, /* guard idx */
  PROG_HSM_PROG_SIDX_REPROG /* target state */
},
};
/* transitions from state RTE_FINISH */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrRTE_FINISH[3] =
{
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_CHECK_MEMORY_TOP /* target state */
},
{
  PROG_HsmTrRTE_FINISHSteps2,
  sizeof(PROG_HsmTrRTE_FINISHSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD, /* triggering event */
  PROG_HSM_PROG_GIDX_RTE_FINISH_GUARD_3, /* guard idx */
  PROG_HSM_PROG_SIDX_REPROG /* target state */
},
};
/* transitions from state TD_TOP */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrTD_TOP[4] =
{
{
  PROG_HsmTrTD_TOPSteps1,
  sizeof(PROG_HsmTrTD_TOPSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_FAILED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_TD_FAILED /* target state */
},
{
  PROG_HsmTrTD_TOPSteps2,
  sizeof(PROG_HsmTrTD_TOPSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrTD_TOPSteps3,
  sizeof(PROG_HsmTrTD_TOPSteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_RTE_TOP /* target state */
},
};
/* transitions from state TD */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrTD[1] =
{
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_TD_WRITE /* target state */
},
};
/* transitions from state TD_CRC */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrTD_CRC[3] =
{
{
  PROG_HsmTrTD_CRCSteps1,
  sizeof(PROG_HsmTrTD_CRCSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrTD_CRCSteps2,
  sizeof(PROG_HsmTrTD_CRCSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_TD /* target state */
},
{
  PROG_HsmTrTD_CRCSteps3,
  sizeof(PROG_HsmTrTD_CRCSteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_STREAMING, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_TD_STREAMING /* target state */
},
};
/* transitions from state TD_FAILED */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrTD_FAILED[4] =
{
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE, /* triggering event */
  PROG_HSM_PROG_GIDX_TD_FAILED_GUARD_1, /* guard idx */
  PROG_HSM_PROG_SIDX_ERASE_TOP /* target state */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD, /* triggering event */
  PROG_HSM_PROG_GIDX_TD_FAILED_GUARD_2, /* guard idx */
  PROG_HSM_PROG_SIDX_REPROG /* target state */
},
{
  PROG_HsmTrTD_FAILEDSteps3,
  sizeof(PROG_HsmTrTD_FAILEDSteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_TD /* target state */
},
{
  PROG_HsmTrTD_FAILEDSteps4,
  sizeof(PROG_HsmTrTD_FAILEDSteps4)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_STREAMING, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_TD_STREAMING /* target state */
},
};
/* transitions from state TD_STREAMING */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrTD_STREAMING[1] =
{
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_TD_WRITE /* target state */
},
};
/* transitions from state TD_WRITE */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrTD_WRITE[2] =
{
{
  PROG_HsmTrTD_WRITESteps1,
  sizeof(PROG_HsmTrTD_WRITESteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrTD_WRITESteps2,
  sizeof(PROG_HsmTrTD_WRITESteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_STREAMING, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
};
/* transitions from state DECRYPT_FINISH */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrDECRYPT_FINISH[2] =
{
{
  PROG_HsmTrDECRYPT_FINISHSteps1,
  sizeof(PROG_HsmTrDECRYPT_FINISHSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_WRITE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_WRITE /* target state */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_WRITE_CHECK /* target state */
},
};
/* transitions from state DECRYPT_UPDATE */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrDECRYPT_UPDATE[1] =
{
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_WRITE_CHECK /* target state */
},
};
/* transitions from state WRITE */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrWRITE[1] =
{
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_WRITE_CHECK /* target state */
},
};
/* transitions from state WRITE_CHECK */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrWRITE_CHECK[3] =
{
{
  PROG_HsmTrWRITE_CHECKSteps1,
  sizeof(PROG_HsmTrWRITE_CHECKSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_DECRYPT_FINISH /* target state */
},
{
  PROG_HsmTrWRITE_CHECKSteps2,
  sizeof(PROG_HsmTrWRITE_CHECKSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_TD_END, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_TD_CRC /* target state */
},
{
  PROG_HsmTrWRITE_CHECKSteps3,
  sizeof(PROG_HsmTrWRITE_CHECKSteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_WRITE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_WRITE /* target state */
},
};
/* transitions from state VERIFY_PARTIAL_SW_CHECKSUM_TOP */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOP[9] =
{
{
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps1,
  sizeof(PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps2,
  sizeof(PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_COHERENCY_CHECK_TOP /* target state */
},
{
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps3,
  sizeof(PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps4,
  sizeof(PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps4)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE, /* triggering event */
  PROG_HSM_PROG_GIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_GUARD_4, /* guard idx */
  PROG_HSM_PROG_SIDX_ERASE_TOP /* target state */
},
{
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps5,
  sizeof(PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps5)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_GET_SEED /* target state */
},
{
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps6,
  sizeof(PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps6)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps7,
  sizeof(PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps7)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps8,
  sizeof(PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps8)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps9,
  sizeof(PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOPSteps9)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_WRITE_FINGERPRINT /* target state */
},
};
/* transitions from state VERIFY_PARTIAL_SW_CHECKSUM */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM[3] =
{
{
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUMSteps1,
  sizeof(PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUMSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUMSteps2,
  sizeof(PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUMSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_VERIFY_PARTIAL_SW_CHECKSUM_FINISH /* target state */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_FINISHED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_VERIFY_PARTIAL_SW_CHECKSUM_FINISH /* target state */
},
};
/* transitions from state VERIFY_PARTIAL_SW_CHECKSUM_FINISH */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_FINISH[1] =
{
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP /* target state */
},
};
/* transitions from state WRITE_FINGERPRINT */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrWRITE_FINGERPRINT[7] =
{
{
  PROG_HsmTrWRITE_FINGERPRINTSteps1,
  sizeof(PROG_HsmTrWRITE_FINGERPRINTSteps1)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrWRITE_FINGERPRINTSteps2,
  sizeof(PROG_HsmTrWRITE_FINGERPRINTSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrWRITE_FINGERPRINTSteps3,
  sizeof(PROG_HsmTrWRITE_FINGERPRINTSteps3)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrWRITE_FINGERPRINTSteps4,
  sizeof(PROG_HsmTrWRITE_FINGERPRINTSteps4)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP /* target state */
},
{
  PROG_HsmTrWRITE_FINGERPRINTSteps6,
  sizeof(PROG_HsmTrWRITE_FINGERPRINTSteps6)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
{
  PROG_HsmTrWRITE_FINGERPRINTSteps7,
  sizeof(PROG_HsmTrWRITE_FINGERPRINTSteps7)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_SIDX_INVALID /* no target state, internal transition */
},
};
/* transitions from state WFP_FINISHED */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrWFP_FINISHED[3] =
{
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE, /* triggering event */
  PROG_HSM_PROG_GIDX_WFP_FINISHED_GUARD_1, /* guard idx */
  PROG_HSM_PROG_SIDX_ERASE_TOP /* target state */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD, /* triggering event */
  PROG_HSM_PROG_GIDX_WFP_FINISHED_GUARD_2, /* guard idx */
  PROG_HSM_PROG_SIDX_REPROG /* target state */
},
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_WRITE_FINGERPRINT /* target state */
},
};
/* transitions from state WFP_INPROGRESS */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrWFP_INPROGRESS[1] =
{
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_FINISHED, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_WFP_FINISHED /* target state */
},
};
/* transitions from state PRE_INIT */
STATIC CONST(PROG_HsmTranType, PROG_CONST)
 PROG_HsmTrPRE_INIT[2] =
{
{
  NULL_PTR,
  0U,
  PROG_HSM_PROG_EV_PROG_EVENT_INIT, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_ALIVE /* target state */
},
{
  PROG_HsmTrPRE_INITSteps2,
  sizeof(PROG_HsmTrPRE_INITSteps2)/sizeof(PROG_HsmActionIdxType),
  PROG_HSM_PROG_EV_PROG_EVENT_SLEEP, /* triggering event */
  PROG_HSM_GIDX_INVALID, /* no guard */
  PROG_HSM_PROG_SIDX_SLEEP /* target state */
},
};



/* statechart model description of the PROG state
 * machine */
STATIC CONST(PROG_HsmStateType, PROG_CONST)
  PROG_HsmScdPROG[PROG_HSM_PROG_NO_OF_STATES] =
{
  {
    /* description of state TOP */
    0U, /* no non-deferred event mask (no leaf state) */
    0U, /* no ignored event mask (no leaf state) */
    NULL_PTR,  /* no transitions */
    PROG_HSM_SIDX_INVALID, /* no parent state */
    PROG_HSM_PROG_SIDX_PRE_INIT, /* init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    0U  /* no transitions */
  },
  {
    /* description of state ALIVE */
    0U, /* no non-deferred event mask (no leaf state) */
    0U, /* no ignored event mask (no leaf state) */
    PROG_HsmTrALIVE, /* transitions for this state */
    PROG_HSM_PROG_SIDX_TOP, /* parent state */
    PROG_HSM_PROG_SIDX_INIT, /* init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    7 /* num of transitions */
  },
  {
    /* description of state CHECK_MEMORY_TOP */
    0U, /* no non-deferred event mask (no leaf state) */
    0U, /* no ignored event mask (no leaf state) */
    PROG_HsmTrCHECK_MEMORY_TOP, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ALIVE, /* parent state */
    PROG_HSM_PROG_SIDX_SIGNATURE_CHECK, /* init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    6 /* num of transitions */
  },
  {
    /* description of state BLU_PRE_RESET */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrBLU_PRE_RESET, /* transitions for this state */
    PROG_HSM_PROG_SIDX_CHECK_MEMORY_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_BLU_PRE_RESET_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    1 /* num of transitions */
  },
  {
    /* description of state BLU_RESUME */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrBLU_RESUME, /* transitions for this state */
    PROG_HSM_PROG_SIDX_CHECK_MEMORY_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_BLU_RESUME_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    1 /* num of transitions */
  },
  {
    /* description of state CHECK_MEMORY */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrCHECK_MEMORY, /* transitions for this state */
    PROG_HSM_PROG_SIDX_CHECK_MEMORY_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_CHECK_MEMORY_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_PROG_AIDX_CHECK_MEMORY_DO, /* do function */
    4 /* num of transitions */
  },
  {
    /* description of state CHECK_MEMORY_FINISH */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrCHECK_MEMORY_FINISH, /* transitions for this state */
    PROG_HSM_PROG_SIDX_CHECK_MEMORY_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_CHECK_MEMORY_FINISH_ENTRY, /* entry function */
    PROG_HSM_PROG_AIDX_CHECK_MEMORY_FINISH_EXIT, /* exit function */
    PROG_HSM_AIDX_INVALID, /* no do action */
    4 /* num of transitions */
  },
  {
    /* description of state SIGNATURE_CHECK */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrSIGNATURE_CHECK, /* transitions for this state */
    PROG_HSM_PROG_SIDX_CHECK_MEMORY_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_SIGNATURE_CHECK_ENTRY, /* entry function */
    PROG_HSM_PROG_AIDX_SIGNATURE_CHECK_EXIT, /* exit function */
    PROG_HSM_AIDX_INVALID, /* no do action */
    2 /* num of transitions */
  },
  {
    /* description of state COHERENCY_CHECK_TOP */
    0U, /* no non-deferred event mask (no leaf state) */
    0U, /* no ignored event mask (no leaf state) */
    PROG_HsmTrCOHERENCY_CHECK_TOP, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ALIVE, /* parent state */
    PROG_HSM_PROG_SIDX_COHERENCY_CHECK, /* init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    8 /* num of transitions */
  },
  {
    /* description of state COHERENCY_CHECK */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrCOHERENCY_CHECK, /* transitions for this state */
    PROG_HSM_PROG_SIDX_COHERENCY_CHECK_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_PROG_AIDX_COHERENCY_CHECK_DO, /* do function */
    1 /* num of transitions */
  },
  {
    /* description of state COHERENCY_CHECK_FINISH */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrCOHERENCY_CHECK_FINISH, /* transitions for this state */
    PROG_HSM_PROG_SIDX_COHERENCY_CHECK_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    2 /* num of transitions */
  },
  {
    /* description of state COMPARE_KEY */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrCOMPARE_KEY, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ALIVE, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_COMPARE_KEY_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    11 /* num of transitions */
  },
  {
    /* description of state DEFAULT_SESSION */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrDEFAULT_SESSION, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ALIVE, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_DEFAULT_SESSION_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    1 /* num of transitions */
  },
  {
    /* description of state ECU_RESET */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrECU_RESET, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ALIVE, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_ECU_RESET_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    1 /* num of transitions */
  },
  {
    /* description of state ERASE_TOP */
    0U, /* no non-deferred event mask (no leaf state) */
    0U, /* no ignored event mask (no leaf state) */
    PROG_HsmTrERASE_TOP, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ALIVE, /* parent state */
    PROG_HSM_PROG_SIDX_ERASE_TRANSMITNRC78, /* init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    8 /* num of transitions */
  },
  {
    /* description of state ERASE */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrERASE, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ERASE_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_ERASE_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_PROG_AIDX_ERASE_DO, /* do function */
    2 /* num of transitions */
  },
  {
    /* description of state ERASE_CHECK */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrERASE_CHECK, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ERASE_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_ERASE_CHECK_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    2 /* num of transitions */
  },
  {
    /* description of state ERASE_FINISH */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrERASE_FINISH, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ERASE_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_ERASE_FINISH_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    2 /* num of transitions */
  },
  {
    /* description of state ERASE_NRC78 */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrERASE_NRC78, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ERASE_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_ERASE_NRC78_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    1 /* num of transitions */
  },
  {
    /* description of state ERASE_TRANSMITNRC78 */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrERASE_TRANSMITNRC78, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ERASE_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_ERASE_TRANSMITNRC78_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    1 /* num of transitions */
  },
  {
    /* description of state EXT_SESSION */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrEXT_SESSION, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ALIVE, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_EXT_SESSION_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    1 /* num of transitions */
  },
  {
    /* description of state GET_SEED */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrGET_SEED, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ALIVE, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_GET_SEED_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    7 /* num of transitions */
  },
  {
    /* description of state INIT */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    | 0UL
    ,
    PROG_HsmTrINIT, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ALIVE, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_INIT_ENTRY, /* entry function */
    PROG_HSM_PROG_AIDX_INIT_EXIT, /* exit function */
    PROG_HSM_AIDX_INVALID, /* no do action */
    1 /* num of transitions */
  },
  {
    /* description of state LOCKED */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrLOCKED, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ALIVE, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    6 /* num of transitions */
  },
  {
    /* description of state PROG_SESSION */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrPROG_SESSION, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ALIVE, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_PROG_SESSION_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    7 /* num of transitions */
  },
  {
    /* description of state REPROG */
    0U, /* no non-deferred event mask (no leaf state) */
    0U, /* no ignored event mask (no leaf state) */
    PROG_HsmTrREPROG, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ALIVE, /* parent state */
    PROG_HSM_PROG_SIDX_RD_TOP, /* init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    7 /* num of transitions */
  },
  {
    /* description of state RD_TOP */
    0U, /* no non-deferred event mask (no leaf state) */
    0U, /* no ignored event mask (no leaf state) */
    PROG_HsmTrRD_TOP, /* transitions for this state */
    PROG_HSM_PROG_SIDX_REPROG, /* parent state */
    PROG_HSM_PROG_SIDX_RD, /* init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    5 /* num of transitions */
  },
  {
    /* description of state RD */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrRD, /* transitions for this state */
    PROG_HSM_PROG_SIDX_RD_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_RD_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    1 /* num of transitions */
  },
  {
    /* description of state RD_FINISH */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrRD_FINISH, /* transitions for this state */
    PROG_HSM_PROG_SIDX_RD_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_RD_FINISH_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    1 /* num of transitions */
  },
  {
    /* description of state RD_SIGNATURE */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrRD_SIGNATURE, /* transitions for this state */
    PROG_HSM_PROG_SIDX_RD_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_RD_SIGNATURE_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    1 /* num of transitions */
  },
  {
    /* description of state RTE_TOP */
    0U, /* no non-deferred event mask (no leaf state) */
    0U, /* no ignored event mask (no leaf state) */
    PROG_HsmTrRTE_TOP, /* transitions for this state */
    PROG_HSM_PROG_SIDX_REPROG, /* parent state */
    PROG_HSM_PROG_SIDX_RTE, /* init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    2 /* num of transitions */
  },
  {
    /* description of state RTE */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrRTE, /* transitions for this state */
    PROG_HSM_PROG_SIDX_RTE_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_RTE_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_PROG_AIDX_RTE_DO, /* do function */
    4 /* num of transitions */
  },
  {
    /* description of state RTE_DECOMP */
    0U, /* no non-deferred event mask (no leaf state) */
    0U, /* no ignored event mask (no leaf state) */
    NULL_PTR,  /* no transitions */
    PROG_HSM_PROG_SIDX_RTE_TOP, /* parent state */
    PROG_HSM_PROG_SIDX_RTE_DECOMP_FINISH, /* init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_PROG_AIDX_RTE_DECOMP_EXIT, /* exit function */
    PROG_HSM_AIDX_INVALID, /* no do action */
    0U  /* no transitions */
  },
  {
    /* description of state RTE_DECOMP_FINISH */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrRTE_DECOMP_FINISH, /* transitions for this state */
    PROG_HSM_PROG_SIDX_RTE_DECOMP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_RTE_DECOMP_FINISH_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    2 /* num of transitions */
  },
  {
    /* description of state RTE_DECOMP_WRITE */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrRTE_DECOMP_WRITE, /* transitions for this state */
    PROG_HSM_PROG_SIDX_RTE_DECOMP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_RTE_DECOMP_WRITE_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_PROG_AIDX_RTE_DECOMP_WRITE_DO, /* do function */
    1 /* num of transitions */
  },
  {
    /* description of state RTE_DECOMP_WRITE_CHECK */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrRTE_DECOMP_WRITE_CHECK, /* transitions for this state */
    PROG_HSM_PROG_SIDX_RTE_DECOMP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_RTE_DECOMP_WRITE_CHECK_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    2 /* num of transitions */
  },
  {
    /* description of state RTE_DECRYPT */
    0U, /* no non-deferred event mask (no leaf state) */
    0U, /* no ignored event mask (no leaf state) */
    NULL_PTR,  /* no transitions */
    PROG_HSM_PROG_SIDX_RTE_TOP, /* parent state */
    PROG_HSM_PROG_SIDX_RTE_DECRYPT_FINISH, /* init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_PROG_AIDX_RTE_DECRYPT_EXIT, /* exit function */
    PROG_HSM_AIDX_INVALID, /* no do action */
    0U  /* no transitions */
  },
  {
    /* description of state RTE_DECRYPT_FINISH */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrRTE_DECRYPT_FINISH, /* transitions for this state */
    PROG_HSM_PROG_SIDX_RTE_DECRYPT, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_RTE_DECRYPT_FINISH_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_PROG_AIDX_RTE_DECRYPT_FINISH_DO, /* do function */
    2 /* num of transitions */
  },
  {
    /* description of state RTE_WRITE */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrRTE_WRITE, /* transitions for this state */
    PROG_HSM_PROG_SIDX_RTE_DECRYPT, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_RTE_WRITE_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_PROG_AIDX_RTE_WRITE_DO, /* do function */
    1 /* num of transitions */
  },
  {
    /* description of state RTE_WRITE_CHECK */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrRTE_WRITE_CHECK, /* transitions for this state */
    PROG_HSM_PROG_SIDX_RTE_DECRYPT, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_PROG_AIDX_RTE_WRITE_CHECK_DO, /* do function */
    2 /* num of transitions */
  },
  {
    /* description of state RTE_FAILED */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrRTE_FAILED, /* transitions for this state */
    PROG_HSM_PROG_SIDX_RTE_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_RTE_FAILED_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    3 /* num of transitions */
  },
  {
    /* description of state RTE_FINISH */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrRTE_FINISH, /* transitions for this state */
    PROG_HSM_PROG_SIDX_RTE_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_RTE_FINISH_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    3 /* num of transitions */
  },
  {
    /* description of state TD_TOP */
    0U, /* no non-deferred event mask (no leaf state) */
    0U, /* no ignored event mask (no leaf state) */
    PROG_HsmTrTD_TOP, /* transitions for this state */
    PROG_HSM_PROG_SIDX_REPROG, /* parent state */
    PROG_HSM_PROG_SIDX_TD, /* init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    4 /* num of transitions */
  },
  {
    /* description of state TD */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrTD, /* transitions for this state */
    PROG_HSM_PROG_SIDX_TD_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_TD_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    1 /* num of transitions */
  },
  {
    /* description of state TD_CRC */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrTD_CRC, /* transitions for this state */
    PROG_HSM_PROG_SIDX_TD_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_PROG_AIDX_TD_CRC_DO, /* do function */
    3 /* num of transitions */
  },
  {
    /* description of state TD_FAILED */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrTD_FAILED, /* transitions for this state */
    PROG_HSM_PROG_SIDX_TD_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_TD_FAILED_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    4 /* num of transitions */
  },
  {
    /* description of state TD_STREAMING */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrTD_STREAMING, /* transitions for this state */
    PROG_HSM_PROG_SIDX_TD_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_TD_STREAMING_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    1 /* num of transitions */
  },
  {
    /* description of state TD_WRITE */
    0U, /* no non-deferred event mask (no leaf state) */
    0U, /* no ignored event mask (no leaf state) */
    PROG_HsmTrTD_WRITE, /* transitions for this state */
    PROG_HSM_PROG_SIDX_TD_TOP, /* parent state */
    PROG_HSM_PROG_SIDX_DECRYPT_UPDATE, /* init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_PROG_AIDX_TD_WRITE_EXIT, /* exit function */
    PROG_HSM_AIDX_INVALID, /* no do action */
    2 /* num of transitions */
  },
  {
    /* description of state DECRYPT_FINISH */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrDECRYPT_FINISH, /* transitions for this state */
    PROG_HSM_PROG_SIDX_TD_WRITE, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_DECRYPT_FINISH_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_PROG_AIDX_DECRYPT_FINISH_DO, /* do function */
    2 /* num of transitions */
  },
  {
    /* description of state DECRYPT_UPDATE */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrDECRYPT_UPDATE, /* transitions for this state */
    PROG_HSM_PROG_SIDX_TD_WRITE, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_DECRYPT_UPDATE_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_PROG_AIDX_DECRYPT_UPDATE_DO, /* do function */
    1 /* num of transitions */
  },
  {
    /* description of state WRITE */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrWRITE, /* transitions for this state */
    PROG_HSM_PROG_SIDX_TD_WRITE, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_WRITE_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_PROG_AIDX_WRITE_DO, /* do function */
    1 /* num of transitions */
  },
  {
    /* description of state WRITE_CHECK */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrWRITE_CHECK, /* transitions for this state */
    PROG_HSM_PROG_SIDX_TD_WRITE, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_PROG_AIDX_WRITE_CHECK_DO, /* do function */
    3 /* num of transitions */
  },
  {
    /* description of state RESET */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    NULL_PTR,  /* no transitions */
    PROG_HSM_PROG_SIDX_ALIVE, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_RESET_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    0U  /* no transitions */
  },
  {
    /* description of state VERIFY_PARTIAL_SW_CHECKSUM_TOP */
    0U, /* no non-deferred event mask (no leaf state) */
    0U, /* no ignored event mask (no leaf state) */
    PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_TOP, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ALIVE, /* parent state */
    PROG_HSM_PROG_SIDX_VERIFY_PARTIAL_SW_CHECKSUM, /* init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP_EXIT, /* exit function */
    PROG_HSM_AIDX_INVALID, /* no do action */
    9 /* num of transitions */
  },
  {
    /* description of state VERIFY_PARTIAL_SW_CHECKSUM */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM, /* transitions for this state */
    PROG_HSM_PROG_SIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_PROG_AIDX_VERIFY_PARTIAL_SW_CHECKSUM_DO, /* do function */
    3 /* num of transitions */
  },
  {
    /* description of state VERIFY_PARTIAL_SW_CHECKSUM_FINISH */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrVERIFY_PARTIAL_SW_CHECKSUM_FINISH, /* transitions for this state */
    PROG_HSM_PROG_SIDX_VERIFY_PARTIAL_SW_CHECKSUM_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    1 /* num of transitions */
  },
  {
    /* description of state WRITE_FINGERPRINT */
    0U, /* no non-deferred event mask (no leaf state) */
    0U, /* no ignored event mask (no leaf state) */
    PROG_HsmTrWRITE_FINGERPRINT, /* transitions for this state */
    PROG_HSM_PROG_SIDX_ALIVE, /* parent state */
    PROG_HSM_PROG_SIDX_WFP_INPROGRESS, /* init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    7 /* num of transitions */
  },
  {
    /* description of state WFP_FINISHED */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrWFP_FINISHED, /* transitions for this state */
    PROG_HSM_PROG_SIDX_WRITE_FINGERPRINT, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_AIDX_INVALID, /* no entry action */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    3 /* num of transitions */
  },
  {
    /* description of state WFP_INPROGRESS */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    PROG_HsmTrWFP_INPROGRESS, /* transitions for this state */
    PROG_HSM_PROG_SIDX_WRITE_FINGERPRINT, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_WFP_INPROGRESS_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_PROG_AIDX_WFP_INPROGRESS_DO, /* do function */
    1 /* num of transitions */
  },
  {
    /* description of state PRE_INIT */
    /* non-deferred and non-ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    | 0UL
    ,
    PROG_HsmTrPRE_INIT, /* transitions for this state */
    PROG_HSM_PROG_SIDX_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_PRE_INIT_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_PROG_AIDX_PRE_INIT_DO, /* do function */
    2 /* num of transitions */
  },
  {
    /* description of state SLEEP */
    /* non-deferred and non-ignored event mask */
 0UL
    ,
      /* ignored event mask */
   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_OPEN_PROG_SESSION)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC01)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_DSC03)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ER)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_RESET)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_S3_TIMEOUT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WAIT_NRC78)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TX_CONF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_UNLOCK_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_BLU_PROGRESS)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PRECOND_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_NOTIFY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FAILED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_STREAMING)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_TD_END)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_WRITE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRC_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_CRYPTO_FINISH)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_CHECKMEMORY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COHERENCY_CHECK)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_COMPARE_KEY)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_GET_SEED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_PART_SW_VERIF)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RTE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_TD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_ERASE)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_RD)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_REQ_WRITE_FP)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_FINISHED)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_INIT)
    |   (1UL << PROG_HSM_PROG_EV_PROG_EVENT_SLEEP)
    | 0UL
    ,
    NULL_PTR,  /* no transitions */
    PROG_HSM_PROG_SIDX_TOP, /* parent state */
    PROG_HSM_SIDX_INVALID, /* no init state */
      PROG_HSM_PROG_AIDX_SLEEP_ENTRY, /* entry function */
    PROG_HSM_AIDX_INVALID, /* no exit action */
    PROG_HSM_AIDX_INVALID, /* no do action */
    0U  /* no transitions */
  }
};

#if (PROG_HSM_TRACE == STD_ON)
STATIC CONSTP2CONST(char, PROG_CONST, PROG_CONST)
  PROG_HsmPROGStateNames[] =
{
  "TOP",
  "ALIVE",
  "CHECK_MEMORY_TOP",
  "BLU_PRE_RESET",
  "BLU_RESUME",
  "CHECK_MEMORY",
  "CHECK_MEMORY_FINISH",
  "SIGNATURE_CHECK",
  "COHERENCY_CHECK_TOP",
  "COHERENCY_CHECK",
  "COHERENCY_CHECK_FINISH",
  "COMPARE_KEY",
  "DEFAULT_SESSION",
  "ECU_RESET",
  "ERASE_TOP",
  "ERASE",
  "ERASE_CHECK",
  "ERASE_FINISH",
  "ERASE_NRC78",
  "ERASE_TRANSMITNRC78",
  "EXT_SESSION",
  "GET_SEED",
  "INIT",
  "LOCKED",
  "PROG_SESSION",
  "REPROG",
  "RD_TOP",
  "RD",
  "RD_FINISH",
  "RD_SIGNATURE",
  "RTE_TOP",
  "RTE",
  "RTE_DECOMP",
  "RTE_DECOMP_FINISH",
  "RTE_DECOMP_WRITE",
  "RTE_DECOMP_WRITE_CHECK",
  "RTE_DECRYPT",
  "RTE_DECRYPT_FINISH",
  "RTE_WRITE",
  "RTE_WRITE_CHECK",
  "RTE_FAILED",
  "RTE_FINISH",
  "TD_TOP",
  "TD",
  "TD_CRC",
  "TD_FAILED",
  "TD_STREAMING",
  "TD_WRITE",
  "DECRYPT_FINISH",
  "DECRYPT_UPDATE",
  "WRITE",
  "WRITE_CHECK",
  "RESET",
  "VERIFY_PARTIAL_SW_CHECKSUM_TOP",
  "VERIFY_PARTIAL_SW_CHECKSUM",
  "VERIFY_PARTIAL_SW_CHECKSUM_FINISH",
  "WRITE_FINGERPRINT",
  "WFP_FINISHED",
  "WFP_INPROGRESS",
  "PRE_INIT",
  "SLEEP",
};

STATIC CONSTP2CONST(char, PROG_CONST, PROG_CONST)
  PROG_HsmPROGActionNames[] =
{
  "ALIVE action 5",
  "CHECK_MEMORY_TOP action 1",
  "CHECK_MEMORY_TOP action 2",
  "CHECK_MEMORY_TOP action 4",
  "CHECK_MEMORY_TOP action 5",
  "BLU_PRE_RESET entry",
  "BLU_RESUME entry",
  "CHECK_MEMORY entry",
  "CHECK_MEMORY do",
  "CHECK_MEMORY action 2",
  "CHECK_MEMORY action 3",
  "CHECK_MEMORY_FINISH entry",
  "CHECK_MEMORY_FINISH exit",
  "CHECK_MEMORY_FINISH action 1",
  "SIGNATURE_CHECK entry",
  "SIGNATURE_CHECK exit",
  "COHERENCY_CHECK_TOP action 1",
  "COHERENCY_CHECK_TOP action 3",
  "COHERENCY_CHECK_TOP action 6",
  "COHERENCY_CHECK_TOP action 7",
  "COHERENCY_CHECK do",
  "COHERENCY_CHECK_FINISH action 1",
  "COMPARE_KEY entry",
  "COMPARE_KEY action 1",
  "COMPARE_KEY action 2",
  "COMPARE_KEY action 3",
  "COMPARE_KEY action 4",
  "COMPARE_KEY action 5",
  "COMPARE_KEY action 7",
  "COMPARE_KEY action 8",
  "COMPARE_KEY action 9",
  "DEFAULT_SESSION entry",
  "ECU_RESET entry",
  "ERASE_TOP action 1",
  "ERASE_TOP action 2",
  "ERASE_TOP action 3",
  "ERASE_TOP action 4",
  "ERASE_TOP action 5",
  "ERASE_TOP action 6",
  "ERASE_TOP action 7",
  "ERASE_TOP action 8",
  "ERASE entry",
  "ERASE do",
  "ERASE_CHECK entry",
  "ERASE_FINISH entry",
  "ERASE_NRC78 entry",
  "ERASE_TRANSMITNRC78 entry",
  "EXT_SESSION entry",
  "GET_SEED entry",
  "GET_SEED action 1",
  "GET_SEED action 2",
  "GET_SEED action 4",
  "GET_SEED action 5",
  "GET_SEED action 6",
  "INIT entry",
  "INIT exit",
  "LOCKED action 1",
  "LOCKED action 2",
  "LOCKED action 3",
  "LOCKED action 5",
  "LOCKED action 6",
  "PROG_SESSION entry",
  "PROG_SESSION action 2",
  "PROG_SESSION action 3",
  "PROG_SESSION action 4",
  "PROG_SESSION action 6",
  "PROG_SESSION action 7",
  "REPROG action 1",
  "REPROG action 2",
  "REPROG action 3",
  "REPROG action 4",
  "REPROG action 5",
  "REPROG action 6",
  "REPROG action 7",
  "RD_TOP action 1",
  "RD_TOP action 2",
  "RD_TOP action 3",
  "RD entry",
  "RD_FINISH entry",
  "RD_SIGNATURE entry",
  "RTE_TOP action 1",
  "RTE_TOP action 2",
  "RTE entry",
  "RTE do",
  "RTE_DECOMP exit",
  "RTE_DECOMP_FINISH entry",
  "RTE_DECOMP_WRITE entry",
  "RTE_DECOMP_WRITE do",
  "RTE_DECOMP_WRITE_CHECK entry",
  "RTE_DECRYPT exit",
  "RTE_DECRYPT_FINISH entry",
  "RTE_DECRYPT_FINISH do",
  "RTE_WRITE entry",
  "RTE_WRITE do",
  "RTE_WRITE_CHECK do",
  "RTE_FAILED entry",
  "RTE_FAILED action 1",
  "RTE_FINISH entry",
  "RTE_FINISH action 2",
  "TD_TOP action 2",
  "TD_TOP action 3",
  "TD entry",
  "TD_CRC do",
  "TD_CRC action 1",
  "TD_FAILED entry",
  "TD_STREAMING entry",
  "TD_WRITE exit",
  "TD_WRITE action 1",
  "TD_WRITE action 2",
  "DECRYPT_FINISH entry",
  "DECRYPT_FINISH do",
  "DECRYPT_UPDATE entry",
  "DECRYPT_UPDATE do",
  "WRITE entry",
  "WRITE do",
  "WRITE_CHECK do",
  "RESET entry",
  "VERIFY_PARTIAL_SW_CHECKSUM_TOP exit",
  "VERIFY_PARTIAL_SW_CHECKSUM_TOP action 1",
  "VERIFY_PARTIAL_SW_CHECKSUM_TOP action 3",
  "VERIFY_PARTIAL_SW_CHECKSUM_TOP action 6",
  "VERIFY_PARTIAL_SW_CHECKSUM_TOP action 7",
  "VERIFY_PARTIAL_SW_CHECKSUM_TOP action 8",
  "VERIFY_PARTIAL_SW_CHECKSUM entry",
  "VERIFY_PARTIAL_SW_CHECKSUM do",
  "VERIFY_PARTIAL_SW_CHECKSUM action 1",
  "VERIFY_PARTIAL_SW_CHECKSUM action 2",
  "WRITE_FINGERPRINT action 1",
  "WRITE_FINGERPRINT action 2",
  "WRITE_FINGERPRINT action 3",
  "WRITE_FINGERPRINT action 4",
  "WRITE_FINGERPRINT action 6",
  "WRITE_FINGERPRINT action 7",
  "WFP_INPROGRESS entry",
  "WFP_INPROGRESS do",
  "PRE_INIT entry",
  "PRE_INIT do",
  "SLEEP entry",
};

STATIC CONSTP2CONST(char, PROG_CONST, PROG_CONST)
  PROG_HsmPROGGuardNames[] =
{
  "CHECK_MEMORY_FINISH guard 3",
  "CHECK_MEMORY_FINISH guard 4",
  "COHERENCY_CHECK_TOP guard 2",
  "COHERENCY_CHECK_TOP guard 5",
  "ERASE_FINISH guard 1",
  "ERASE_FINISH guard 2",
  "RTE_FAILED guard 2",
  "RTE_FAILED guard 3",
  "RTE_FINISH guard 3",
  "TD_FAILED guard 1",
  "TD_FAILED guard 2",
  "VERIFY_PARTIAL_SW_CHECKSUM_TOP guard 4",
  "WFP_FINISHED guard 1",
  "WFP_FINISHED guard 2",
};

STATIC CONSTP2CONST(char, PROG_CONST, PROG_CONST)
  PROG_HsmPROGEventNames[] =
{
  "PROG_EVENT_OPEN_PROG_SESSION",
  "PROG_EVENT_REQ_DSC01",
  "PROG_EVENT_REQ_DSC03",
  "PROG_EVENT_REQ_ER",
  "PROG_EVENT_RESET",
  "PROG_EVENT_S3_TIMEOUT",
  "PROG_EVENT_WAIT_NRC78",
  "PROG_EVENT_TX_CONF",
  "PROG_EVENT_UNLOCK_FAILED",
  "PROG_EVENT_BLU_PROGRESS",
  "PROG_EVENT_REQ_PRECOND_CHECK",
  "PROG_EVENT_CRYPTO_NOTIFY",
  "PROG_EVENT_FAILED",
  "PROG_EVENT_STREAMING",
  "PROG_EVENT_WRITE_CHECK",
  "PROG_EVENT_TD_END",
  "PROG_EVENT_WRITE",
  "PROG_EVENT_CRC_FINISH",
  "PROG_EVENT_CRYPTO_FINISH",
  "PROG_EVENT_REQ_CHECKMEMORY",
  "PROG_EVENT_REQ_COHERENCY_CHECK",
  "PROG_EVENT_REQ_COMPARE_KEY",
  "PROG_EVENT_REQ_GET_SEED",
  "PROG_EVENT_REQ_PART_SW_VERIF",
  "PROG_EVENT_REQ_RTE",
  "PROG_EVENT_REQ_TD",
  "PROG_EVENT_REQ_ERASE",
  "PROG_EVENT_REQ_RD",
  "PROG_EVENT_REQ_WRITE_FP",
  "PROG_EVENT_FINISHED",
  "PROG_EVENT_INIT",
  "PROG_EVENT_SLEEP",
};
#endif

/*==================[external constants]====================================*/

/* Top level state chart description data */
CONST(PROG_HsmStatechartType, PROG_CONST)
  PROG_HsmScPROG =
{
  PROG_HsmScdPROG, /* state description array */
  PROG_HsmInstPROG, /* instances RAM */
  PROG_HsmPROGActions, /* actions */
  PROG_HsmPROGGuards, /* guards */
  PROG_HsmEvCountersPROG, /* event counters RAM */
  PROG_HsmEvQueuesPROG, /* event queues RAM */
#if (PROG_HSM_TRACE == STD_ON)
  "PROG", /* name of the HSM */
  PROG_HsmPROGStateNames,
  PROG_HsmPROGActionNames,
  PROG_HsmPROGGuardNames,
  PROG_HsmPROGEventNames,
#endif
  PROG_HSM_PROG_NUM_EVENTS, /* num of events */
  0U, /* state chart id */
  PROG_HSM_PROG_NUM_INST, /* num of instances */
  PROG_HSM_PROG_SIDX_TOP /* top state index */
};


#define PROG_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[internal function definitions]=========================*/

/*==================[external function definitions]=========================*/

/*==================[end of file]===========================================*/
