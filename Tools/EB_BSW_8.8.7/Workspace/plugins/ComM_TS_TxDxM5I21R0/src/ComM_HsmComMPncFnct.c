/**
 * \file
 *
 * \brief AUTOSAR ComM
 *
 * This file contains the implementation of the AUTOSAR
 * module ComM.
 *
 * \version 5.21.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* Implementation of the state handler functions of the state machine
 * ComMPnc.
 *
 * This file contains the implementation of the state functions.  It
 * is generated but must be edited to implement the real actions.  If the
 * state machine model is updated and the code generator regenerates the
 * files the user must manually merge the changes with any existing hand
 * written code.
 */

/* CHECK: RULE 301 OFF (this file is partly generated, some lines may be
 * longer then 100 characters) */

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 20.7 (required)
 * Expressions resulting from the expansion of macro parameters shall be enclosed in parentheses.
 *
 * Reason:
 * The macro is used in function parameter declarations and definitions of structure member
 * where the number of parentheses matter.
 *
 */

/* tasking Deviation List
 *
 * TASKING-1) Deviated Rule: W549
 * W549: condition is always true
 *
 * Reason:
 * In the context of "for (j = 0U; j < COMM_PN_INFO_LENGTH; j++)"
 * when "COMM_PN_INFO_LENGTH = 1" the message condition is always true is expected;
 * Expression "j < COMM_PN_INFO_LENGTH" is always evaluated as true if "COMM_PN_INFO_LENGTH = 1".
 *
 * TASKING-2) Deviated Rule: W549
 * W549: condition is always true
 *
 * Reason:
 * In the context of "for (PncIdx = 0U ; PncIdx < COMM_NUM_PNC ; PncIdx++)"
 * when "COMM_NUM_PNC = 1" the message condition is always true is expected;
 * Expression "PncIdx < COMM_NUM_PNC" is always evaluated as true if "COMM_NUM_PNC = 1".
 */

/*==================[inclusions]============================================*/

#include <ComM_Trace.h>
#include <ComM_BSW.h>
#include <ComM_Int.h>
#include <ComM_BSW_Cfg.h>
#include <ComM.h>

#include <ComM_Hsm.h>  /* state machine driver interface */
#include <ComM_HsmComMPnc.h> /* public statechart model definitions */
#include <ComM_HsmComMPncInt.h> /* internal statechart model definitions */
#include <ComM_Cfg.h>
#include <BswM_ComM.h>
#include <TSMem.h>
#if (COMM_PNC_SUPPORT == STD_ON)
/* !LINKSTO ComM506_Refine_Com,1 */
#include <Com.h>     /* Com API's */
#endif
#if (COMM_NUM_PNC > 0U)
#if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON)
#include <SchM_ComM_1_MasterPnc.h>
#endif /* (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON) */

#if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON)
#include <Os.h>
#endif

#if (COMM_DEV_ERROR_DETECT == STD_ON)
#include <Det.h>                /* Det API */
#endif

#if (COMM_NM_ACCESS_NEEDED == STD_ON)
#include <Nm.h>                /* Network Management Identifiers */
#endif /* (COMM_NM_ACCESS_NEEDED == STD_ON) */

/*==================[macros]================================================*/

/** \brief Instant access to Pnc Timer */
#if (defined COMM_PNC_TIMER)
#error COMM_PNC_TIMER already defined
#endif
#define COMM_PNC_TIMER(Pnc)                     \
  COMM_INST_ACCESS(ComM_PncTimer,Pnc)

#if (defined ComM_PncStartTimer)
#error ComM_PncStartTimer already defined
#endif
#if (COMM_T_PNC_PREPARE_SLEEP == 0U)
#define ComM_PncStartTimer(Pnc)       \
  COMM_PNC_EMIT(Pnc, COMM_HSM_COMMPNC_EV_PREPARE_SLEEP_TIMEOUT);
#else
#define ComM_PncStartTimer(Pnc)  \
  COMM_PNC_TIMER(Pnc) = COMM_T_PNC_PREPARE_SLEEP;
#endif

#if (defined ComM_PncStopTimer)
#error ComM_PncStopTimer already defined
#endif
#define ComM_PncStopTimer(Pnc)  \
  COMM_PNC_TIMER(Pnc) = 0U;

/** \brief User ID of a channel. */
#if (defined COMM_NUMCHANNELSOFPNC)
#error COMM_NUMCHANNELSOFPNC already defined
#endif
#define COMM_NUMCHANNELSOFPNC(pnc) (COMM_NUM_CHANNELS_OF_PNC(pnc))

#if (defined COMM_CHANNELSOFPNC)
#error COMM_CHANNELSOFPNC already defined
#endif
#define COMM_CHANNELSOFPNC(pnc,i) (COMM_CHANNEL_OF_PNC(pnc,i))

#if (defined COMM_PARAM_UNUSED)
#error COMM_PARAM_UNUSED already defined
#endif
#if (COMM_HSM_INST_MULTI_ENABLED == STD_ON)
#define COMM_PARAM_UNUSED(instIdx)      TS_PARAM_UNUSED(instIdx)
#else
#define COMM_PARAM_UNUSED(instIdx)      /* nothing */
#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>

/** \brief Release/Request all channels of a PNC
 **
 ** This updates the mode requested by a PNC and emits the event RE_STATUS_CHANGED to its channels.
 **
 ** \param[in] Pnc index of PNC */
STATIC FUNC(void, COMM_CODE) ComM_PNC_RequestComMode(
  uint16 pncIdx,
  ComM_ModeType Mode,
  uint8         TXSignalType
);

/** \brief Request Full com for all channels of a Pnc
 **
 ** This function requests Full communication for all channels of
 ** a Pnc.
 **
 ** \param[in] Pnc index of Pnc */
STATIC FUNC(void, COMM_CODE)
  ComM_NmNwReqAllChOfPnc (uint16 pncIdx);

/** \brief Get Eira
 **
 ** This function returns the status of EIRA (when Set TRUE is returned)
 ** of a Pnc */
/* Deviation MISRAC2012-1 */
STATIC FUNC(uint8, COMM_CODE) ComM_PncGetEIRA(
                                COMM_PDL_SF(uint16 instIdx));

#if(COMM_PNC_GW_ENABLED == STD_ON)
/** \brief Get Era
 **
 ** This function returns the status of ERA (when Set TRUE is returned)
 ** of a Pnc
 ** \param[in]  instIdx - instance index
 */
/* Deviation MISRAC2012-1 */
STATIC FUNC(uint8, COMM_CODE) ComM_PncGetERAUnfiltered(COMM_PDL_SF(uint16 instIdx));
#endif

/** \brief Send the status of PNC(s) via Com signal(s)
 **
 ** A PNC may contain references to more than one TX EIRA Com Signal.
 ** Therefore, this function sends the updated EIRA to all Com Signals
 ** which are referenced by this PNC.
 **
 ** Some PNCs may not reference a TX EIRA Com signal.
 ** Therefore, this function also masks out the bits corresponding
 ** to PNCs which do not reference this Com signal before sending.
 **/
/* !LINKSTO ComM916,1 */
STATIC FUNC(void, COMM_CODE) ComM_PncSendSignal
(
  uint16 instIdx,
  uint8 signalKind
);

#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

#define COMM_START_SEC_VAR_CLEARED_16
#include <ComM_MemMap.h>

/** \brief Time counter value for checking the Prepare Sleep
 ** timeout for different Pnc */
STATIC VAR(uint16, COMM_VAR) ComM_PncTimer[COMM_NUM_PNC];

#define COMM_STOP_SEC_VAR_CLEARED_16
#include <ComM_MemMap.h>

/*==================[external function definitions]=========================*/

#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>

/* ************************ state functions ******************************* */

/* ************************************************************************
 * State: PncTop
 * Parent state: none
 * Init substate: PncNoCom
 * Transitions originating from this state:
 */

/* ************************************************************************
 * State: PncFullCom
 * Parent state: PncTop
 * Init substate: PncPrepareSleep
 * Transitions originating from this state:
 */

/* ************************************************************************
 * State: PncPrepareSleep
 * Parent state: PncFullCom
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) PncPrepareSleep -> PncReadySleep: COMCBK[ComM_PncGetEIRA() == 1]/ComM_PncStopTimer(PNC);
 * 2) PncPrepareSleep -> PncRequested: FULL_COM_REQ_BY_COMM_USER[]/ComM_PncStopTimer(PNC);
 * 3) PncPrepareSleep -> PncNoComNotify: PREPARE_SLEEP_TIMEOUT[]/if(COMM_NO_INTERNAL_AND_EXTERNAL_REQUESTS) ComM_PNC_RequestComMode (PNC, COMM_NO_COMMUNICATION);
 */

/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncPrepareSleepEntry(
  COMM_PDL_SF(const uint16 instIdx))
{
  /* entry action 'BswM_ComM_CurrentPNCMode(PNC_ID, PNC_PREPARE_SLEEP);ComM_PncStartTimer(PNC);' */

  ComM_PNCState[COMM_INST(instIdx)] = PNC_PREPARE_SLEEP;
  /* !LINKSTO ComM907,1, ComM908,1 */
  /* !LINKSTO ComM829_Refine_BswM_ComM_CurrentPNCMode,1 */
  BswM_ComM_CurrentPNCMode(ComM_PncID[COMM_INST(instIdx)], PNC_PREPARE_SLEEP);

  /* !LINKSTO ComM952,1 */
  ComM_PncStartTimer(COMM_INST(instIdx));
}
/* Deviation MISRAC2012-1 */
FUNC(boolean, COMM_CODE) ComM_HsmComMPncSfPncPrepareSleepGuard1(
  COMM_PDL_SF(const uint16 instIdx))
{
  /* guard condition 'ComM_PncGetEIRA() == 1'
   * for COMCBK[...]/ComM_PncStopTimer(PNC);
   * external transition to state PncReadySleep */
  boolean ret = FALSE;
  /* !LINKSTO ComM942,1 */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.COMCBK_PNC_PREPARE_SLEEP,1 */
  ret = (ComM_PncGetEIRA(COMM_PL_SF(instIdx)) != 0U) ? TRUE : FALSE;
  return ret;
}
/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncPrepareSleepAction1(
  COMM_PDL_SF(const uint16 instIdx))
{
  /* action 'ComM_PncStopTimer(PNC);'
   * for COMCBK[ComM_PncGetEIRA() == 1]/...
   * external transition to state PncReadySleep */
  ComM_PncStopTimer(COMM_INST(instIdx));
}
/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncPrepareSleepAction2(
  COMM_PDL_SF(const uint16 instIdx))
{
  /* action 'ComM_PncStopTimer(PNC);'
   * for FULL_COM_REQ_BY_COMM_USER[]/...
   * external transition to state PncRequested */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.FULL_COM_REQ_BY_COMM_USER_PNC_PREPARE_SLEEP_0,1, ComM948,1 */
  ComM_PncStopTimer(COMM_INST(instIdx));
}
/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncPrepareSleepAction3(
  COMM_PDL_SF(const uint16 instIdx))
{
  /* action 'if(COMM_NO_INTERNAL_AND_EXTERNAL_REQUESTS) ComM_PNC_RequestComMode (COMM_NO_COMMUNICATION);'
   * for PREPARE_SLEEP_TIMEOUT[]/...
   * external transition to state PncNoComNotify */
  /* !LINKSTO ComM.EB.Dsn.Algorithm.PncReleaseChannel,1 */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.PREPARE_SLEEP_TIMEOUT_PNC_PREPARE_SLEEP,1 */
#if (COMM_PNC_RELEASE_CHANNEL == COMM_NO_INTERNAL_AND_EXTERNAL_REQUESTS)
  /* !LINKSTO SWS_ComM_00966,1 */
  /* !LINKSTO ComM.EB.NoComRelease,1, ComM947,1 */
  ComM_PNC_RequestComMode(COMM_INST(instIdx), COMM_NO_COMMUNICATION, COMM_TX_ERA_ACTIVE_OR_EIRA);

#else
  COMM_PARAM_UNUSED(instIdx);
#endif
}

/* ************************************************************************
 * State: PncReadySleep
 * Parent state: PncFullCom
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 * 1) PncReadySleep -> PncPrepareSleep: COMCBK[ComM_PncGetEIRA() == 0]/
 * 2) PncReadySleep -> PncRequested: FULL_COM_REQ_BY_COMM_USER[]/
 */

/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncReadySleepEntry(
  COMM_PDL_SF(const uint16 instIdx))
{
  COMM_PNC_EMIT(COMM_INST(instIdx), COMM_HSM_COMMPNC_EV_COMCBK);
  /* entry action 'BswM_ComM_CurrentPNCMode(PNC_ID, PNC_READY_SLEEP);' */
  ComM_PNCState[COMM_INST(instIdx)] = PNC_READY_SLEEP;

  /* !LINKSTO ComM907,1, ComM908,1 */
  /* !LINKSTO ComM829_Refine_BswM_ComM_CurrentPNCMode,1 */
  /* !LINKSTO ComM.EB.SWS_ComM_00938_2,1 */
  BswM_ComM_CurrentPNCMode(ComM_PncID[COMM_INST(instIdx)], PNC_READY_SLEEP);
}
/* Deviation MISRAC2012-1 */
FUNC(boolean, COMM_CODE) ComM_HsmComMPncSfPncReadySleepGuard1(
  COMM_PDL_SF(const uint16 instIdx))
{
  boolean ret = FALSE;
  /* guard condition 'ComM_PncGetEIRA() == 0'
   * for COMCBK[...]/
   * external transition to state PncPrepareSleep */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.COMCBK_PNC_READY_SLEEP,1, ComM940,1 */
  ret =  (ComM_PncGetEIRA(COMM_PL_SF(instIdx)) == 0U) ? TRUE : FALSE;
  return ret;
}

/* ************************************************************************
 * State: PncRequested
 * Parent state: PncFullCom
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
  * 1) PNC_UPDATE_TX_PASSIVE[]/UpdateEraPassive
  * 2) PncRequested -> PncReadySleep: NO_COM_REQ_BY_ALL_COMM_USER[ComM_PncGetERAUnfiltered() == 0 && NO_COM]/ComM_TxEiraEraActive(PNC_ID) = 0; ComM_PncSendSignal(PNC); if(COMM_NO_INTERNAL_REQUESTS) ComM_PNC_RequestComMode (COMM_NO_COMMUNICATION);
 */

/* !LINKSTO ComM.EB.ComM_PncReadySleep_PncRequested_User,1 */
/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncRequestedEntry(
  COMM_PDL_SF(const uint16 instIdx))
{
  /* entry action 'BswM_ComM_CurrentPNCMode(PNC_ID, PNC_REQUESTED);ComM_PNC_RequestComMode(PNC, COMM_FULL_COMMUNICATION);ComM_TxEiraEraActive(PNC_ID) = 1;ComM_PncSendSignal(PNC); ComM_NmNwReqAllChOfPnc(PNC);' */
  const uint8 Index = ((uint8)(ComM_PncID[COMM_INST(instIdx)] >> SHIFT_3_BITS)) - COMM_PN_OFFSET;
#if (COMM_PNCWAKEUPSLEEPREQUEST_ENABLED == STD_ON)
  uint8 PNCStateLocal = ComM_PNCState[COMM_INST(instIdx)];
#endif
  /* !LINKSTO SWS_ComM_00966,1 */
  /* !LINKSTO ComM.EB.Dsn.Algorithm.PncRequestChannel,1 */
  /* !LINKSTO ComM993,1 */
  /* !LINKSTO SWS_ComM_01067_Refine1,1 */
  /* !LINKSTO SWS_ComM_01067_Refine2,1 */
  /* !LINKSTO SWS_ComM_01069_Refine,1 */
  /* !LINKSTO SWS_ComM_01070_Refine1,1 */
  /* !LINKSTO SWS_ComM_01070_Refine2,1 */
  /* !LINKSTO SWS_ComM_01071_Refine,1 */
#if (COMM_WAKEUPSLEEPREQUEST_ENABLED == STD_ON)
  if ((ComM_PNCState[COMM_INST(instIdx)] == PNC_NO_COMMUNICATION) ||
      (ComM_PNCState[COMM_INST(instIdx)] == PNC_PREPARE_SLEEP))
  {
    /* Since requirement states that COMM_FULL_COMMUNICATION_WITH_WAKEUP_REQUEST shall be handled the same way
     * as COMM_FULL_COMMUNICATION, there is no need to add protection.
     * The only diffrence is at EthSM_RequestComMode call (if it's called with COMM_FULL_COMMUNICATION or
     * COMM_FULL_COMMUNICATION_WITH_WAKEUP_REQUEST)
     */
    ComM_PNC_RequestComMode(COMM_INST(instIdx), COMM_FULL_COMMUNICATION_WITH_WAKEUP_REQUEST, COMM_TX_ERA_ACTIVE_OR_EIRA);
  }
  else
#endif /* #if (COMM_WAKEUPSLEEPREQUEST_ENABLED == STD_ON) */
  {
    ComM_PNC_RequestComMode(COMM_INST(instIdx), COMM_FULL_COMMUNICATION, COMM_TX_ERA_ACTIVE_OR_EIRA);
  }


  /* ComM.EB.SWS_ComM_00930_1: When entering the PNC sub state PNC_REQUESTED
   * the API Com_SendSignal() shall be called with the value '1' for the bit
   * representing this PNC for the Com signal assigned to this PNC with
   * ComMPncComSignalDirection "TX".
   */

  /* First, set the bit corresponding to this PNC in the EIRA to be sent */
  TS_AtomicSetBit_8(&ComM_TxEiraEraActive[Index], (uint8)(ComM_PncID[COMM_INST(instIdx)] & MASK_3_BITS));

  /* Now, send the status via the assigned Com signal(s) */
  ComM_PncSendSignal(COMM_INST(instIdx), COMM_EIRA_ERA_ACTIVE);

#if(COMM_PNC_GW_ENABLED == STD_ON)
  /* action 'UpdateERAPassive();'
   * for PNC_UPDATE_PASSIVE[]/...
   * internal transition */
  ComM_TxEraPassive[Index] = ComM_PncStateGWE[Index] | ComM_RxActiveEra[Index];

  if ((ComM_TxEraPassive[Index] & (1U << (uint8)(ComM_PncID[COMM_INST(instIdx)] & MASK_3_BITS))) != 0U)
  {
    /* Now, send the status via the assigned Com signal(s) */
    ComM_PncSendSignal(COMM_INST(instIdx), COMM_ERA_PASSIVE);

#if(COMM_0_PNC_VECTOR_AVOIDANCE == STD_ON)
    /* !LINKSTO SWS_ComM_00966,1 */
    ComM_PNC_RequestComMode(COMM_INST(instIdx), COMM_FULL_COMMUNICATION, COMM_TX_ERA_PASSIVE);
#endif /* #if(COMM_0_PNC_VECTOR_AVOIDANCE == STD_ON) */
  }
#else /* #if(COMM_PNC_GW_ENABLED == STD_ON) */
  COMM_PARAM_UNUSED(instIdx);
#endif /* #if(COMM_PNC_GW_ENABLED == STD_ON) */

  ComM_PNCState[COMM_INST(instIdx)] = PNC_REQUESTED;
#if (COMM_PNCWAKEUPSLEEPREQUEST_ENABLED == STD_ON)
  if ((ComM_WakeupSleepRequestEnabledPncList[COMM_INST(instIdx)] == TRUE) &&
      ((PNCStateLocal == PNC_NO_COMMUNICATION) || (PNCStateLocal == PNC_PREPARE_SLEEP)))
  {
    BswM_ComM_CurrentPNCMode(ComM_PncID[COMM_INST(instIdx)], COMM_PNC_REQUESTED_WITH_WAKEUP_REQUEST);
  }
  else
#endif
  {
    /* !LINKSTO ComM907,1, ComM908,1 */
    /* !LINKSTO ComM829_Refine_BswM_ComM_CurrentPNCMode,1 */
    BswM_ComM_CurrentPNCMode(ComM_PncID[COMM_INST(instIdx)], PNC_REQUESTED);
  }

  /* !LINKSTO ComM.EB.Dsn.StateDynamics.PNC_NM_REQUEST,1 */
  /* !LINKSTO ComM929,1, ComM980,1 */
  ComM_NmNwReqAllChOfPnc(COMM_INST(instIdx));
}

/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncRequestedAction1(
  COMM_PDL_SF(const uint16 instIdx))
{
   /* action 'UpdateEraPassive'
   * for PNC_UPDATE_TX_PASSIVE[]/...
   * internal transition */
#if(COMM_PNC_GW_ENABLED == STD_ON)
  /* action 'UpdateERAPassive();'
   * for PNC_UPDATE_PASSIVE[]/...
   * internal transition */
  const uint8 Index = ((uint8)(ComM_PncID[COMM_INST(instIdx)] >> SHIFT_3_BITS)) - COMM_PN_OFFSET;
  uint8   UserOrExternalActiveRequest = ComM_PncStateGWE[Index] | ComM_RxActiveEra[Index];

  if (((ComM_TxEraPassive[Index]   & (1U << (uint8)(ComM_PncID[COMM_INST(instIdx)] & MASK_3_BITS)))) !=
      (UserOrExternalActiveRequest & (1U << (uint8)(ComM_PncID[COMM_INST(instIdx)] & MASK_3_BITS))))
  {
    ComM_TxEraPassive[Index] = UserOrExternalActiveRequest;
    /* Now, send the status via the assigned Com signal(s) */
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.PncRequestedAction1_0,1 */
    /* !LINKSTO ComM.EB.Dsn.StateDynamics.PncRequestedAction1_1,1 */
    ComM_PncSendSignal(COMM_INST(instIdx), COMM_ERA_PASSIVE);

#if(COMM_0_PNC_VECTOR_AVOIDANCE == STD_ON)
    /* !LINKSTO SWS_ComM_00966,1 */
    if ((ComM_TxEraPassive[Index] & (1U << (uint8)(ComM_PncID[COMM_INST(instIdx)] & MASK_3_BITS))) == 0U)
    {
      ComM_PNC_RequestComMode(COMM_INST(instIdx), COMM_NO_COMMUNICATION, COMM_TX_ERA_PASSIVE);
    }
    else
    {
      ComM_PNC_RequestComMode(COMM_INST(instIdx), COMM_FULL_COMMUNICATION, COMM_TX_ERA_PASSIVE);
    }
#endif /* #if(COMM_0_PNC_VECTOR_AVOIDANCE == STD_ON) */
  }
#else /* #if(COMM_PNC_GW_ENABLED == STD_ON) */
  COMM_PARAM_UNUSED(instIdx);
#endif /* #if(COMM_PNC_GW_ENABLED == STD_ON) */
}

/* Deviation MISRAC2012-1 */
FUNC(boolean, COMM_CODE) ComM_HsmComMPncSfPncRequestedGuard2(
  COMM_PDL_SF(const uint16 instIdx))
{
  /* guard condition 'ComM_PncGetERAUnfiltered() == 0 && NO_COM'
   * for NO_COM_REQ_BY_ALL_COMM_USER[...]/ComM_TxEiraEraActive(PNC_ID) = 0; ComM_PncSendSignal(PNC); if(COMM_NO_INTERNAL_REQUESTS) ComM_PNC_RequestComMode (COMM_NO_COMMUNICATION);
   * external transition to state PncReadySleep */
  boolean RetVal = FALSE;
#if(COMM_PNC_GW_ENABLED == STD_ON)
  const uint8 Index = ((uint8)(ComM_PncID[COMM_INST(instIdx)] >> SHIFT_3_BITS)) - COMM_PN_OFFSET;
  const uint8 Mask = (1U << (uint8)(ComM_PncID[COMM_INST(instIdx)] & MASK_3_BITS));
  /* !LINKSTO ComM.EB.SWS_ComM_00991,1 */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.NO_COM_REQ_BY_ALL_COMM_USER_PNC_REQUESTED_1,1 */
  if((ComM_PncGetERAUnfiltered(COMM_PL_SF(instIdx)) == 0x0U) &&
     ((ComM_PncStateGWE[Index] & Mask) == 0U))
  {
    RetVal = TRUE;
  }
  else
  {
    RetVal = FALSE;
  }
#else
  /* !LINKSTO ComM.EB.SWS_ComM_00938_1,1 */
  RetVal = TRUE;
  COMM_PARAM_UNUSED(instIdx);
#endif
  return RetVal;
}
/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncRequestedAction2(
  COMM_PDL_SF(const uint16 instIdx))
{
  /* action 'ComM_TxEiraEraActive(PNC_ID) = 0; ComM_PncSendSignal(PNC);
   * if(COMM_NO_INTERNAL_REQUESTS) ComM_PNC_RequestComMode (COMM_NO_COMMUNICATION)'
   * for NO_COM_REQ_BY_ALL_COMM_USER[ComM_PncGetERAUnfiltered() == 0 && NO_COM]/...
   * external transition to state PncReadySleep */
  const uint8 Index  = ((uint8)(ComM_PncID[COMM_INST(instIdx)] >> SHIFT_3_BITS)) - COMM_PN_OFFSET;

  /* ComM960: When entering the PNC sub state PNC_READY_SLEEP from
   * PNC_REQUESTED, the API Com_SendSignal() shall be called with the value '0'
   * for the bit representing this PNC for all Com signals assigned to this PNC
   * with ComMPncComSignalDirection "TX".
   */

  /* First, clear the bit corresponding to this PNC in the EIRA to be sent */
  TS_AtomicClearBit_8(&ComM_TxEiraEraActive[Index], (uint8)(ComM_PncID[COMM_INST(instIdx)] & MASK_3_BITS));

  /* Now, send the status via the assigned Com signal(s) */
  ComM_PncSendSignal(COMM_INST(instIdx), COMM_EIRA_ERA_ACTIVE);

/* !LINKSTO SWS_ComM_00961,1 */
#if (COMM_PNC_RELEASE_CHANNEL == COMM_NO_INTERNAL_REQUESTS)

  /* !LINKSTO SWS_ComM_00966,1 */
  /* !LINKSTO ComM.EB.ReadySleepFullComRelease,1 */
  ComM_PNC_RequestComMode(COMM_INST(instIdx), COMM_NO_COMMUNICATION, COMM_TX_ERA_ACTIVE_OR_EIRA);

#endif
#if(COMM_PNC_GW_ENABLED == STD_ON)
  /* action 'UpdateERAPassive();'
   * for PNC_UPDATE_PASSIVE[]/...
   * internal transition */

  TS_AtomicClearBit_8(&ComM_TxEraPassive[Index], (uint8)(ComM_PncID[COMM_INST(instIdx)] & MASK_3_BITS));
  /* Now, send the status via the assigned Com signal(s) */
  ComM_PncSendSignal(COMM_INST(instIdx), COMM_ERA_PASSIVE);

#if(COMM_0_PNC_VECTOR_AVOIDANCE == STD_ON)
  /* !LINKSTO SWS_ComM_00966,1 */
  ComM_PNC_RequestComMode(COMM_INST(instIdx), COMM_NO_COMMUNICATION, COMM_TX_ERA_PASSIVE);
#endif /* #if(COMM_0_PNC_VECTOR_AVOIDANCE == STD_ON) */
#endif /* #if(COMM_PNC_GW_ENABLED == STD_ON) */
#if (COMM_SYNCHRONIZED_PNC_SHUTDOWN_ENABLED == STD_ON)
  /* !LINKSTO SWS_ComM_01083,1 */
  if (ComM_IsTopLevelCoordinator[COMM_INST(instIdx)] == TRUE)
  {
    uint8 chIdx;
    for (chIdx = 0U; chIdx < COMM_NUMCHANNELSOFPNC(COMM_INST(instIdx)); chIdx++)
    {
      const uint8 Channel = COMM_CHANNELSOFPNC(COMM_INST(instIdx),chIdx);
#if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON)
#if (COMM_OS_APPLICATION_MASTER_PNC_TO_CH_FCTPTR_LENGTH != 0)
      if (ComM_Multicore_MasterPncToChSchmSend_FctPtr_IndexList[Channel] != COMM_MULTICORE_INVALID_FCT_INDEX)
      {
        ComM_MasterPnc_To_Ch_DataType MasterPncToChData;
        MasterPncToChData.Channel = Channel;
        MasterPncToChData.Operation = COMM_MULTICORE_REQUEST_SYNCHRONIZED_PNC_SHUTDOWN;
        MasterPncToChData.PncId = ComM_PncID[COMM_INST(instIdx)];
        /* !LINKSTO ComM.EB.MasterPncToChannelCrossPartition,1 */
        if (ComM_Multicore_MasterPncToChPncSchmSend_FctPtr_List[ComM_Multicore_MasterPncToChSchmSend_FctPtr_IndexList[Channel]](&MasterPncToChData) != SCHM_E_OK)
        {
#if (COMM_DEV_ERROR_DETECT == STD_ON)
          /* !LINKSTO ComM.EB.MasterPncToChannelSetError,1 */
          /* !LINKSTO ComM.EB.PncMainfunctionDataSetSIDError,1 */
          COMM_DET_REPORT_ERROR(GetApplicationID(), COMM_SID_MAIN_FUNCTIONPNC, COMM_E_MASTERPNC_TO_CH_DATASET_ERROR);
#endif
        }
      }
      else
#endif /* #if (COMM_OS_APPLICATION_MASTER_PNC_TO_CH_FCTPTR_LENGTH != 0) */
#endif  /* #if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON) */
      {
        (void) Nm_RequestSynchronizedPncShutdown(Channel, ComM_PncID[COMM_INST(instIdx)]);
      }
    }
  }
#endif /* #if ((COMM_SYNCHRONIZED_PNC_SHUTDOWN_ENABLED == STD_ON) */
}

/* ************************************************************************
 * State: PncNoCom
 * Parent state: PncTop
 * Init substate: PncNoComInit
 * Transitions originating from this state:
 * 1) PncNoCom -> PncReadySleep: COMCBK[ComM_PncGetEIRA() == 1]/BswM_ComM_CurrentPNCMode(PNC_ID, PNC_FULL_COMMUNICATION);
 * 2) PncNoCom -> PncPrepareSleep: ECUM_PNCWAKEUP_IND[]/
 * 3) PncNoCom -> PncPrepareSleep: ECUM_WAKEUP_IND[ComMSynchronousWakeUp == TRUE]/BswM_ComM_CurrentPNCMode(PNC_ID, PNC_FULL_COMMUNICATION);
 * 4) PncNoCom -> PncRequested: FULL_COM_REQ_BY_COMM_USER[]/BswM_ComM_CurrentPNCMode(PNC_ID, PNC_FULL_COMMUNICATION);
 */

/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncNoComEntry(
  COMM_PDL_SF(const uint16 instIdx))
{
  /* entry action 'ComM_PNCMode(instIdx) = COMM_NO_COMMUNICATION' */
  ComM_PNCState[COMM_INST(instIdx)] = PNC_NO_COMMUNICATION;
}

/* Deviation MISRAC2012-1 */
FUNC(boolean, COMM_CODE) ComM_HsmComMPncSfPncNoComGuard1(
  COMM_PDL_SF(const uint16 instIdx))
{
  boolean ret = FALSE;
  /* guard condition 'ComM_PncGetEIRA() == 1'
   * for COMCBK[...]/BswM_ComM_CurrentPNCMode(PNC_ID, PNC_FULL_COMMUNICATION);
   * external transition to state PncReadySleep */
  /* !LINKSTO ComM933,1 */
  ret =  (ComM_PncGetEIRA(COMM_PL_SF(instIdx)) != 0U) ? TRUE : FALSE;
  return ret;
}
/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncNoComAction1(
  COMM_PDL_SF(const uint16 instIdx))
{
  /* action 'BswM_ComM_CurrentPNCMode(PNC_ID, PNC_FULL_COMMUNICATION);'
   * for COMCBK[ComM_PncGetEIRA() == 1]/...
   * external transition to state PncReadySleep */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.COMCBK_PNC_NO_COMMUNICATION,1, ComM924,1, ComM908,1 */
  /* !LINKSTO ComM829_Refine_BswM_ComM_CurrentPNCMode,1 */
  BswM_ComM_CurrentPNCMode(ComM_PncID[COMM_INST(instIdx)], PNC_FULL_COMMUNICATION);
}
/* !LINKSTO ComM931,1 */
/* Deviation MISRAC2012-1 */
FUNC(boolean, COMM_CODE) ComM_HsmComMPncSfPncNoComGuard3(
  COMM_PDL_SF(const uint16 instIdx))
{
#if (COMM_SYNCHRONOUS_WAKE_UP == STD_ON)
  boolean ret = TRUE;
#else
  /* !LINKSTO ComM990,1 */
  boolean ret = FALSE;
#endif
  /* guard condition 'ComMSynchronousWakeUp == TRUE'
   * for ECUM_WAKEUP_IND[...]/BswM_ComM_CurrentPNCMode(PNC_ID, PNC_FULL_COMMUNICATION);
   * external transition to state PncPrepareSleep */
  COMM_PARAM_UNUSED(instIdx);
  return ret;
}
/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncNoComAction3(
  COMM_PDL_SF(const uint16 instIdx))
{
  /* action 'BswM_ComM_CurrentPNCMode(PNC_ID, PNC_FULL_COMMUNICATION);'
   * for ECUM_WAKEUP_IND[ComMSynchronousWakeUp == TRUE]/...
   * external transition to state PncPrepareSleep */
  /* !LINKSTO ComM924,1, ComM908,1 */
  /* !LINKSTO ComM829_Refine_BswM_ComM_CurrentPNCMode,1 */
  BswM_ComM_CurrentPNCMode(ComM_PncID[COMM_INST(instIdx)], PNC_FULL_COMMUNICATION);
}
/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncNoComAction4(
  COMM_PDL_SF(const uint16 instIdx))
{
  /* action 'BswM_ComM_CurrentPNCMode(PNC_ID, PNC_FULL_COMMUNICATION);'
   * for FULL_COM_REQ_BY_COMM_USER[]/...
   * external transition to state PncRequested */
  /* !LINKSTO ComM.EB.Dsn.StateDynamics.FULL_COM_REQ_BY_COMM_USER_PNC_NO_COMMUNICATION_0,1 */
  /* !LINKSTO ComM924,1, ComM908,1, ComM932,1 */
  /* !LINKSTO ComM829_Refine_BswM_ComM_CurrentPNCMode,1 */
  BswM_ComM_CurrentPNCMode(ComM_PncID[COMM_INST(instIdx)], PNC_FULL_COMMUNICATION);
}

/* ************************************************************************
 * State: PncNoComInit
 * Parent state: PncNoCom
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 */

/* ************************************************************************
 * State: PncNoComNotify
 * Parent state: PncNoCom
 * Init substate: none, this is a leaf state
 * Transitions originating from this state:
 */

/* !LINKSTO ComM925,1 */
/* Deviation MISRAC2012-1 */
FUNC(void, COMM_CODE) ComM_HsmComMPncSfPncNoComNotifyEntry(
  COMM_PDL_SF(const uint16 instIdx))
{
  /* entry action 'BswM_ComM_CurrentPNCMode(PNC_ID, PNC_NO_COMMUNICATION);' */
  /* !LINKSTO ComM924,1, ComM908,1, ComM926,1 */
  /* !LINKSTO ComM829_Refine_BswM_ComM_CurrentPNCMode,1 */
  BswM_ComM_CurrentPNCMode(ComM_PncID[COMM_INST(instIdx)], PNC_NO_COMMUNICATION);
}

/*==================[internal function definitions]=========================*/

STATIC FUNC(void, COMM_CODE) ComM_NmNwReqAllChOfPnc
(
  uint16 pncIdx
)
{
  uint8_least chIdx;

  for (chIdx = 0U; chIdx < COMM_NUMCHANNELSOFPNC(pncIdx); chIdx++)
  {
    const uint8 Channel = COMM_CHANNELSOFPNC(pncIdx,chIdx);
    if(ComM_PncNmRequest[Channel]==TRUE)
    {
#if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON)
#if (COMM_OS_APPLICATION_MASTER_PNC_TO_CH_FCTPTR_LENGTH != 0)
      if (ComM_Multicore_MasterPncToChSchmSend_FctPtr_IndexList[Channel] != COMM_MULTICORE_INVALID_FCT_INDEX)
      {
        ComM_MasterPnc_To_Ch_DataType PncTocChData;
        PncTocChData.Channel = Channel;
        PncTocChData.Operation = COMM_MULTICORE_PNC_EMIT_PNC_NM_REQUEST;
        /* !LINKSTO ComM.EB.MasterPncToChannelCrossPartition,1 */
        if (ComM_Multicore_MasterPncToChPncSchmSend_FctPtr_List[ComM_Multicore_MasterPncToChSchmSend_FctPtr_IndexList[Channel]](&PncTocChData) != SCHM_E_OK)
        {
#if (COMM_DEV_ERROR_DETECT == STD_ON)
          /* !LINKSTO ComM.EB.MasterPncToChannelSetError,1 */
          /* !LINKSTO ComM.EB.PncMainfunctionDataSetSIDError,1 */
          COMM_DET_REPORT_ERROR(GetApplicationID(), COMM_SID_MAIN_FUNCTIONPNC, COMM_E_MASTERPNC_TO_CH_DATASET_ERROR);
#endif
        }
      }
      else
#endif /*#if (COMM_OS_APPLICATION_MASTER_PNC_TO_CH_FCTPTR_LENGTH != 0)*/
#endif /* #if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON) */
      {
        COMM_EMIT(Channel, COMM_HSM_COMM_EV_PNC_NM_REQUEST);
      }
    }
  }
#if (COMM_HSM_INST_MULTI_ENABLED == STD_OFF)
  TS_PARAM_UNUSED(pncIdx);
#endif
}

/* !LINKSTO ComM.EB.Dsn.Algorithm.ComM_PNC_RequestComMode,1 */
STATIC FUNC(void, COMM_CODE) ComM_PNC_RequestComMode
(
  uint16 pncIdx,
  ComM_ModeType Mode,
  uint8         TXSignalType
)
{
  uint8_least chIdx;

#if (COMM_0_PNC_VECTOR_AVOIDANCE == STD_OFF)
  TS_PARAM_UNUSED(TXSignalType);
#endif /* #if (COMM_0_PNC_VECTOR_AVOIDANCE == STD_OFF) */

  /* !LINKSTO ComM.EB.Dsn.Algorithm.ComM_PNC_RequestComMode_Mode,1 */
#if (COMM_0_PNC_VECTOR_AVOIDANCE == STD_ON)
  /* !LINKSTO SWS_ComM_00966,1 */
  if (TXSignalType == COMM_TX_ERA_PASSIVE)
  {
    ComM_PNCRequestedComMode0PncVectorAvoidance[pncIdx] = Mode;
  }
  else
#endif /* #if (COMM_0_PNC_VECTOR_AVOIDANCE == STD_ON) */
  {
    ComM_PNCRequestedComMode[pncIdx] = Mode;
  }

  for (chIdx = 0U; chIdx < COMM_NUMCHANNELSOFPNC(pncIdx); chIdx++)
  {
    const uint8 Channel = COMM_CHANNELSOFPNC(pncIdx,chIdx);
    /* !LINKSTO ComM.EB.Dsn.Algorithm.ComM_PNC_RequestComMode_Mode,1 */

#if (COMM_WAKEUPSLEEPREQUEST_ENABLED == STD_ON)
    if ((ComM_WakeupSleepRequestEnabledChList[Channel] == TRUE) &&
        (Mode == COMM_FULL_COMMUNICATION_WITH_WAKEUP_REQUEST))
    {
#if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON)
#if (COMM_OS_APPLICATION_MASTER_PNC_TO_CH_FCTPTR_LENGTH != 0)
      if (ComM_Multicore_MasterPncToChSchmSend_FctPtr_IndexList[Channel] != COMM_MULTICORE_INVALID_FCT_INDEX)
      {
        ComM_MasterPnc_To_Ch_DataType PncTocChData;
        PncTocChData.Channel = Channel;
        PncTocChData.Operation = COMM_MULTICORE_PNC_REQUEST_BUSSM;
        /* !LINKSTO ComM.EB.MasterPncToChannelCrossPartition,1 */
        if (ComM_Multicore_MasterPncToChPncSchmSend_FctPtr_List[ComM_Multicore_MasterPncToChSchmSend_FctPtr_IndexList[Channel]](&PncTocChData) != SCHM_E_OK)
        {
#if (COMM_DEV_ERROR_DETECT == STD_ON)
        /* !LINKSTO ComM.EB.MasterPncToChannelSetError,1 */
          COMM_DET_REPORT_ERROR(GetApplicationID(), COMM_SID_MAIN_FUNCTIONPNC, COMM_E_MASTERPNC_TO_CH_DATASET_ERROR);
#endif
        }
      }
      else
#endif /* #if (COMM_OS_APPLICATION_MASTER_PNC_TO_CH_FCTPTR_LENGTH != 0) */
#endif /* #if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON) */
      {
        COMM_EMIT_TO_SELF(Channel, COMM_HSM_COMM_EV_BUSSM_REQUEST_FULL_COM_WITH_WAKEUP_REQUEST);
      }
    }
#endif /* #if (COMM_WAKEUPSLEEPREQUEST_ENABLED == STD_ON) */

#if (COMM_0_PNC_VECTOR_AVOIDANCE == STD_ON)
    if(((ComM_PncZeroVectorAvoidanceRelease[Channel] == TRUE) &&
        (TXSignalType == COMM_TX_ERA_PASSIVE)) ||
       ((ComM_PncZeroVectorAvoidanceRelease[Channel] == FALSE) &&
        (TXSignalType == COMM_TX_ERA_ACTIVE_OR_EIRA)))
#endif /* #if (COMM_0_PNC_VECTOR_AVOIDANCE == STD_ON) */
    {
#if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON)
#if (COMM_OS_APPLICATION_MASTER_PNC_TO_CH_FCTPTR_LENGTH != 0)
      if (ComM_Multicore_MasterPncToChSchmSend_FctPtr_IndexList[Channel] != COMM_MULTICORE_INVALID_FCT_INDEX)
      {
        ComM_MasterPnc_To_Ch_DataType PncTocChData;
        PncTocChData.Channel = Channel;
        PncTocChData.Operation = COMM_MULTICORE_PNC_EVALUATE_CHANNEL_AND_EMIT_REQ_STATUS_CHANGED;
        /* !LINKSTO ComM.EB.MasterPncToChannelCrossPartition,1 */
        if (ComM_Multicore_MasterPncToChPncSchmSend_FctPtr_List[ComM_Multicore_MasterPncToChSchmSend_FctPtr_IndexList[Channel]](&PncTocChData) != SCHM_E_OK)
        {
#if (COMM_DEV_ERROR_DETECT == STD_ON)
        /* !LINKSTO ComM.EB.MasterPncToChannelSetError,1 */
          COMM_DET_REPORT_ERROR(GetApplicationID(), COMM_SID_MAIN_FUNCTIONPNC, COMM_E_MASTERPNC_TO_CH_DATASET_ERROR);
#endif
        }
      }
      else
#endif /* #if (COMM_OS_APPLICATION_MASTER_PNC_TO_CH_FCTPTR_LENGTH != 0) */
#endif /* #if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON) */
      {
        ComM_EvaluateChannel(Channel);
      /* !LINKSTO ComM.EB.Dsn.Algorithm.ComM_PNC_RequestComMode_Event,1 */
        COMM_EMIT(Channel, COMM_HSM_COMM_EV_REQ_STATUS_CHANGED);
      }
    }
  }
}

/* Deviation MISRAC2012-1 */
STATIC FUNC(uint8, COMM_CODE) ComM_PncGetEIRA
(
  COMM_PDL_SF(uint16 instIdx)
)
{
  /*Index is byte in which this PncID is received
    pncID   byte
     8       0
     9       0
     .........
     16      1
     .........
     63      6
  */
  const uint8 Index  = ((uint8)(ComM_PncID[COMM_INST(instIdx)] >> SHIFT_3_BITS)) - COMM_PN_OFFSET;

  /*mask represent bit position in the byte received
    pncID   byte  EiraMask pos In byte
     8       0      0x01   bit 0
     9       0      0x02   bit 1
     .........
     16      1      0x01   bit 0
     .........
     63      6      128    bit 7
   */

  const uint8 EiraMask = (uint8)(0x01U << (ComM_PncID[COMM_INST(instIdx)] & MASK_3_BITS));
  boolean ret;

  ret = ((uint8)(ComM_RxEira[Index] & EiraMask));
  return ret;
}

#if(COMM_PNC_GW_ENABLED == STD_ON)
/* Deviation MISRAC2012-1 */
STATIC FUNC(uint8, COMM_CODE) ComM_PncGetERAUnfiltered(COMM_PDL_SF(uint16 instIdx))
{
  const uint8 Index  = ((uint8)(ComM_PncID[COMM_INST(instIdx)] >> SHIFT_3_BITS)) - COMM_PN_OFFSET;
  const uint8 EraMask = (uint8)(0x01U << (ComM_PncID[COMM_INST(instIdx)] & MASK_3_BITS));
  boolean ret;

  ret = ((uint8)(ComM_RxUnfilteredEra[Index] & EraMask));

  return ret;
}
#endif

STATIC FUNC(void, COMM_CODE) ComM_PncSendSignal
(
  uint16 instIdx,
  uint8 signalKind
)
{

#if (COMM_NUM_TX_SIGNALS > 0U)
  uint8 i;
  uint8 TxEiraEra[COMM_PN_INFO_LENGTH];

  uint8 *TxBufferPtr = ComM_TxEiraEraActive;
#if (COMM_PNC_GW_ENABLED == STD_ON)
  if (signalKind == COMM_ERA_PASSIVE)
  {
    TxBufferPtr = ComM_TxEraPassive;
  }
#endif
  /* A PNC may contain references to more than one TX EIRA Com Signal.
   * Therefore, the updated EIRA has to be sent to all Com Signals
   * which are referenced by this PNC.
   */
  for (i = 0U; i < ComM_PncTxSignalMap[instIdx].NumTxSignal; i++)
  {
    /* Get the index of this signal in the list of Tx EIRA signals
     * assigned to this PNC */
    const uint8 SigIndex = ComM_PncTxSignalMap[instIdx].TxSignalList[i];
    uint8 j;

    /* Some PNCs may not reference this TX EIRA Com signal.
     * Therefore, the bits corresponding to PNCs which do not
     * reference this Com signal have to be masked out before sending.
     */
    if (ComM_TxComSignalCfg[SigIndex].TxSignalKind == signalKind)
    {
      /* Deviation TASKING-1 */
      for (j = 0U; j < COMM_PN_INFO_LENGTH; j++)
      {
        /* !LINKSTO SWS_ComM_00959,1 */
        TxEiraEra[j] = TxBufferPtr[j] & ComM_PncTxMask[SigIndex][j];
      }
      /* !LINKSTO ComM.EB.SWS_ComM_00930_1,1, SWS_ComM_00992,1, ComM960,1, SWS_ComM_00959,1 */
      /* !LINKSTO SWS_ComM_00164_Refine_1,1 */
      /* !LINKSTO SWS_ComM_00164_Refine_2,1 */
      /* !LINKSTO SWS_ComM_00164_Refine_3,1 */
      /* !LINKSTO SWS_ComM_00164_Refine_4,1 */
      /* !LINKSTO ComM.EB.SWS_ComM_00930_2,1 */
#if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON)
#if (COMM_MULTICORE_NO_OF_TX_BUFFERS == 0)
    (void)Com_SendSignal(ComM_TxComSignalCfg[SigIndex].ComHandleId, TxEiraEra);
#else /* (COMM_MULTICORE_NO_OF_TX_BUFFERS == 0) */
    if (ComM_TxComSignalCfg[SigIndex].SchMSendFctPtr == NULL_PTR)
    {
      (void)Com_SendSignal(ComM_TxComSignalCfg[SigIndex].ComHandleId, TxEiraEra);
    }
    else
    {
      uint16 index = ComM_TxComSignalCfg[SigIndex].MulticoreTxBufferIndex;
      TS_MemCpy(&ComM_MulticoreTxBuffer[index][0], &TxEiraEra[0], COMM_PN_INFO_LENGTH);
      ComM_MulticoreTxBufferStatus[index] = TRUE;
    }
#endif /* #if (COMM_MULTICORE_NO_OF_TX_BUFFERS == 0) */
#else /* #if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON) */
#if (COMM_MULTICORE_ENABLED == STD_OFF)
    (void)Com_SendSignal(ComM_TxComSignalCfg[SigIndex].ComHandleId, TxEiraEra);
#else /* #if (COMM_MULTICORE_ENABLED == STD_OFF) */
#if (COMM_NO_OF_TX_BUFFERS == 0)
    (void)Com_SendSignal(ComM_TxComSignalCfg[SigIndex].ComHandleId, TxEiraEra);
#else /* (COMM_NO_OF_TX_BUFFERS == 0) */
    if (ComM_TxComSignalCfg[SigIndex].SchMSendFctPtr == NULL_PTR)
    {
      (void)Com_SendSignal(ComM_TxComSignalCfg[SigIndex].ComHandleId, TxEiraEra);
    }
    else
    {
      uint16 index = ComM_TxComSignalCfg[SigIndex].MulticoreTxBufferIndex;
      TS_MemCpy(&ComM_MulticoreTxBuffer[index][0], &TxEiraEra[0], COMM_PN_INFO_LENGTH);
      ComM_MulticoreTxBufferStatus[index] = TRUE;
    }
#endif /* #if (COMM_NO_OF_TX_BUFFERS == 0) */
#endif /* #if (COMM_MULTICORE_ENABLED == STD_OFF) */
#endif /* #if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON) */
    }
  }
#else
  TS_PARAM_UNUSED(instIdx);
  TS_PARAM_UNUSED(signalKind);
#endif
}

FUNC(void, COMM_CODE) ComM_PncProcessTimers(void)
{
  uint16 PncIdx;
  boolean emitEvent = FALSE;
  /* Deviation TASKING-2 */
  for (PncIdx = 0U ; PncIdx < COMM_NUM_PNC ; PncIdx++)
  {
    emitEvent = FALSE;
#if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON)
    SchM_Enter_ComM_1_MasterPnc_SCHM_COMM_EXCLUSIVE_AREA_MASTERPNC();
#else /* #if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON) */
    ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
#endif /* #if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON) */
    if (COMM_PNC_TIMER(PncIdx) > 0U)
    {
      --COMM_PNC_TIMER(PncIdx);
      if (COMM_PNC_TIMER(PncIdx) == 0U)
      {
        emitEvent = TRUE;
      }
    }
#if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON)
    SchM_Exit_ComM_1_MasterPnc_SCHM_COMM_EXCLUSIVE_AREA_MASTERPNC();
#else /* #if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON) */
    ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
#endif /* #if (COMM_OS_APPLICATION_MULTICORE_ENABLED == STD_ON) */
    if (emitEvent == TRUE)
    {
      /* timeout events are generated outside of transitions, therefore do
       * not use the EMITTOSELF function */
      /* !LINKSTO ComM.EB.Dsn.StateDynamics.PREPARE_SLEEP_TIMEOUT,1 */
      COMM_PNC_EMIT(PncIdx, COMM_HSM_COMMPNC_EV_PREPARE_SLEEP_TIMEOUT);
    }
  }
}

#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
#endif /* (COMM_NUM_PNC > 0U) */
/*==================[end of file]===========================================*/
