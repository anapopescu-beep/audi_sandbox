
/**
 * \file
 *
 * \brief AUTOSAR BswM
 *
 * This file contains the implementation of the AUTOSAR
 * module BswM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO BswM0024,1 */
/* The BswM_Lcfg.c contains all link-time configuration parameters. */

/* !LINKSTO BswM.Impl.SourceFile.BswM_Partition_Lcfg_c,1 */

/*==================[inclusions]============================================*/

#include <BswM_Trace.h>       /* Dbg macros */
#include <BswM.h>
#include <BswM_Int_Cfg.h>
#include <BswM_Int.h>
#include <TSMem.h>            /* Used for TS_MemSet */
#include <SchM_BswM.h>        /* SchM API for BswM         */

#include <BswM_Lcfg.h>

/*==================[macros]================================================*/

#if (defined BSWM_NUM_LOGICAL_EXPRESSIONS)
#error BSWM_NUM_LOGICAL_EXPRESSIONS is already defined
#endif
#define BSWM_NUM_LOGICAL_EXPRESSIONS 23U

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

/* !LINKSTO BswM.Impl.MemoryMapping.InstanceCode,1 */
#define BSWM_START_SEC_CODE
#include <BswM_MemMap.h>

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_BswM_StartupTwoA(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_BswM_StartupTwoB(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_BswM_GoOffOneA(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_BswM_GoOffOneB(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_WakeUpValidated(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_WakeUpExpired(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_StartShutdownSequence(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_PrepareHWReset(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_ExecuteReset(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_PrepareSWReset(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_StartComEffective(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_PrepareJumpToFbl(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterRunFromWakeup(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterRunFromPostRun_1(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterRunFromPostRun_2(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterPostRunFromRun(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterRunFromLowPwr_ActiveWake(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterRunFromLowPwr_PassiveWake(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterLowPwrFromPostRun(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterShutdownFromLowPwr(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnableTxPdu(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnableTxPdu_DcmRequest(void);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_DisableTxPdu_DcmRequest(void);

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_BswM_StartupTwoA(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_BswM_StartupTwoB(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_BswM_GoOffOneA(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_BswM_GoOffOneB(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_WakeUpValidated(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_WakeUpExpired(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_StartShutdownSequence(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_PrepareHWReset(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_ExecuteReset(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_PrepareSWReset(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_StartComEffective(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_PrepareJumpToFbl(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnterRunFromWakeup(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnterRunFromPostRun_1(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnterRunFromPostRun_2(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnterPostRunFromRun(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnterRunFromLowPwr_ActiveWake(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnterRunFromLowPwr_PassiveWake(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnterLowPwrFromPostRun(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnterShutdownFromLowPwr(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnableTxPdu(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnableTxPdu_DcmRequest(void);
STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_DisableTxPdu_DcmRequest(void);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_OnStartupTwoA(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_OnStartupTwoB(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_ComM_EnablePdus(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_OnGoOffOneA(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_OnWakeupExpired(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_OnWakeupValidation(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_On_Prep_Shutdown(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_EcuM_SelectShutdownTarget_RESET(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_OnStartComEffective(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_ProceedReset(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_SWResetNotification(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_HWResetNotification(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_PrepareJumpToFBL(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_RunStateFromWakeup(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_PostRunStateFromRun(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_RunStateFromPostRunBusAvailable(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_LowPwrStateFromPostRun(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_RunStateFromLowPwr_ActiveWake(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_RunStateFromLowPwr_PassiveWake(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_EcuM_SelectShutdownTarget_SLEEP(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_ComM_FullCom(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_ComM_EnableTxPduConfirmation(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_ComM_DisableTxPduConfirmation(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_RunStateFromPostRunPassengerDetected(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_OnSafeStateFromPostRun(void);
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_Action_BswMAction_BswM_OnRunFromSafeState(void);

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprGetState(uint16 exprIndex);
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprGetResult(uint16 exprIndex);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ExecuteAction(uint16 actionIndex);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ExecuteModeArbitration(uint8 source, uint32 channel, uint8 mode);

#define BSWM_STOP_SEC_CODE
#include <BswM_MemMap.h>

/*==================[external function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[external constants]====================================*/

/*==================[internal data]=========================================*/

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include <BswM_MemMap.h>
/**
 * BswM_NumModeRequestPortsTable
 */
STATIC CONST( uint16 , AUTOMATIC ) BswM_NumModeRequestPortsTable[13] = 
{
  UINT16_C( 1 ), /* Number of ports of type BSWM_CAN_SM_INDICATION */
  UINT16_C( 0 ), /* Number of ports of type BSWM_COMM_INDICATION */
  UINT16_C( 0 ), /* Number of ports of type BSWM_COMM_PNC_REQUEST */
  UINT16_C( 0 ), /* Number of ports of type BSWM_DCM_APPLICATION_UPDATED_INDICATION */
  UINT16_C( 0 ), /* Number of ports of type BSWM_DCM_COM_MODE_CURRENT_STATE */
  UINT16_C( 0 ), /* Number of ports of type BSWM_DCM_COM_MODE_REQUEST */
  UINT16_C( 0 ), /* Number of ports of type BSWM_DCM_RESET_MODE_REQUEST */
  UINT16_C( 0 ), /* Number of ports of type BSWM_DCM_SESSION_MODE_REQUEST */
  UINT16_C( 0 ), /* Number of ports of type BSWM_ECUM_INDICATION */
  UINT16_C( 1 ), /* Number of ports of type BSWM_ECUM_WAKEUP_SOURCE */
  UINT16_C( 6 ), /* Number of ports of type BSWM_GENERIC_REQUEST */
  UINT16_C( 0 ), /* Number of ports of type BSWM_NVM_JOB_MODE_INDICATION */
  UINT16_C( 0 )  /* Number of ports of type BSWM_NVM_REQUEST */
};

/*
 * The logical expressions table contains both the state
 * and the result function pointers for each defined logical
 * expression configured in the current BswM instance.
 */
/**
 * BswM_LogicalExprTable
 */
STATIC CONST( BswMLogicalExprType , AUTOMATIC ) BswM_LogicalExprTable[23] = 
{
  { /* [0] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_BswM_StartupTwoA, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_BswM_StartupTwoA  /* GetResult */
  },
  { /* [1] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_BswM_StartupTwoB, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_BswM_StartupTwoB  /* GetResult */
  },
  { /* [2] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_BswM_GoOffOneA, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_BswM_GoOffOneA  /* GetResult */
  },
  { /* [3] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_BswM_GoOffOneB, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_BswM_GoOffOneB  /* GetResult */
  },
  { /* [4] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_WakeUpValidated, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_WakeUpValidated  /* GetResult */
  },
  { /* [5] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_WakeUpExpired, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_WakeUpExpired  /* GetResult */
  },
  { /* [6] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_StartShutdownSequence, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_StartShutdownSequence  /* GetResult */
  },
  { /* [7] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_PrepareHWReset, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_PrepareHWReset  /* GetResult */
  },
  { /* [8] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_ExecuteReset, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_ExecuteReset  /* GetResult */
  },
  { /* [9] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_PrepareSWReset, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_PrepareSWReset  /* GetResult */
  },
  { /* [10] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_StartComEffective, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_StartComEffective  /* GetResult */
  },
  { /* [11] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_PrepareJumpToFbl, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_PrepareJumpToFbl  /* GetResult */
  },
  { /* [12] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_EnterRunFromWakeup, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterRunFromWakeup  /* GetResult */
  },
  { /* [13] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_EnterRunFromPostRun_1, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterRunFromPostRun_1  /* GetResult */
  },
  { /* [14] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_EnterRunFromPostRun_2, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterRunFromPostRun_2  /* GetResult */
  },
  { /* [15] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_EnterPostRunFromRun, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterPostRunFromRun  /* GetResult */
  },
  { /* [16] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_EnterRunFromLowPwr_ActiveWake, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterRunFromLowPwr_ActiveWake  /* GetResult */
  },
  { /* [17] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_EnterRunFromLowPwr_PassiveWake, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterRunFromLowPwr_PassiveWake  /* GetResult */
  },
  { /* [18] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_EnterLowPwrFromPostRun, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterLowPwrFromPostRun  /* GetResult */
  },
  { /* [19] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_EnterShutdownFromLowPwr, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterShutdownFromLowPwr  /* GetResult */
  },
  { /* [20] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_EnableTxPdu, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_EnableTxPdu  /* GetResult */
  },
  { /* [21] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_EnableTxPdu_DcmRequest, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_EnableTxPdu_DcmRequest  /* GetResult */
  },
  { /* [22] */
    &BswM_ExprState_BswMLogicalExpression_BswMRule_DisableTxPdu_DcmRequest, /* GetState */
    &BswM_ExprResult_BswMLogicalExpression_BswMRule_DisableTxPdu_DcmRequest  /* GetResult */
  }
};

/*
 * The action table contains function pointers to all configured
 * actions within the current BswM instance.
 */
/**
 * BswM_ActionTable
 */
STATIC CONST( BswMActionFuncPtrType , AUTOMATIC ) BswM_ActionTable[26] = 
{
  &BswM_Action_BswMAction_BswM_OnStartupTwoA, /* [0] */
  &BswM_Action_BswMAction_BswM_OnStartupTwoB, /* [1] */
  &BswM_Action_BswMAction_ComM_EnablePdus, /* [2] */
  &BswM_Action_BswMAction_BswM_OnGoOffOneA, /* [3] */
  &BswM_Action_BswMAction_OnWakeupExpired, /* [4] */
  &BswM_Action_BswMAction_BswM_OnWakeupValidation, /* [5] */
  &BswM_Action_BswMAction_BswM_On_Prep_Shutdown, /* [6] */
  &BswM_Action_BswMAction_EcuM_SelectShutdownTarget_RESET, /* [7] */
  &BswM_Action_BswMAction_BswM_OnStartComEffective, /* [8] */
  &BswM_Action_BswMAction_BswM_ProceedReset, /* [9] */
  &BswM_Action_BswMAction_BswM_SWResetNotification, /* [10] */
  &BswM_Action_BswMAction_BswM_HWResetNotification, /* [11] */
  &BswM_Action_BswMAction_BswM_PrepareJumpToFBL, /* [12] */
  &BswM_Action_BswMAction_BswM_RunStateFromWakeup, /* [13] */
  &BswM_Action_BswMAction_BswM_PostRunStateFromRun, /* [14] */
  &BswM_Action_BswMAction_BswM_RunStateFromPostRunBusAvailable, /* [15] */
  &BswM_Action_BswMAction_BswM_LowPwrStateFromPostRun, /* [16] */
  &BswM_Action_BswMAction_BswM_RunStateFromLowPwr_ActiveWake, /* [17] */
  &BswM_Action_BswMAction_BswM_RunStateFromLowPwr_PassiveWake, /* [18] */
  &BswM_Action_BswMAction_EcuM_SelectShutdownTarget_SLEEP, /* [19] */
  &BswM_Action_BswMAction_ComM_FullCom, /* [20] */
  &BswM_Action_BswMAction_ComM_EnableTxPduConfirmation, /* [21] */
  &BswM_Action_BswMAction_ComM_DisableTxPduConfirmation, /* [22] */
  &BswM_Action_BswMAction_BswM_RunStateFromPostRunPassengerDetected, /* [23] */
  &BswM_Action_BswMAction_BswM_OnSafeStateFromPostRun, /* [24] */
  &BswM_Action_BswMAction_BswM_OnRunFromSafeState  /* [25] */
};

#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include <BswM_MemMap.h>

/* !LINKSTO BswM.Impl.MemoryMapping.InstanceData,1 */
#define BSWM_START_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_MemMap.h>

/* Dynamically Generated Mode Request Ports */
/**
 * BswM_MPI_BswM_Dcm_RequestPort
 */
BswMUInt8RteModeRequestPortType BswM_MPI_BswM_Dcm_RequestPort = 
{
  { /* base */
    UINT16_C( 3 ), /* id */
    UINT8_C( 1 ), /* isImmediate */
    UINT8_C( 0 ), /* isDefined */
    UINT8_C( 1 )  /* hasInitValue */
  },
  UINT8_C( 5 )  /* mode */
};

/**
 * BswM_MPI_BswM_Dcm_ComM_RequestPort
 */
BswMUInt8RteModeRequestPortType BswM_MPI_BswM_Dcm_ComM_RequestPort = 
{
  { /* base */
    UINT16_C( 9 ), /* id */
    UINT8_C( 1 ), /* isImmediate */
    UINT8_C( 0 ), /* isDefined */
    UINT8_C( 1 )  /* hasInitValue */
  },
  UINT8_C( 0 )  /* mode */
};

/**
 * BswMCanSMIndicationPortTable
 */
BswMModeRequestPortType BswMCanSMIndicationPortTable[1] = 
{
  { /* [0] */
    { /* base */
      UINT16_C( 1 ), /* id */
      UINT8_C( 1 ), /* isImmediate */
      UINT8_C( 0 ), /* isDefined */
      UINT8_C( 0 )  /* hasInitValue */
    },
    0U, /* channel */
    UINT8_C( 0 )  /* mode */
  }
};

/**
 * BswMEcuMWakeupSourcePortTable
 */
BswMModeRequestPortType BswMEcuMWakeupSourcePortTable[1] = 
{
  { /* [0] */
    { /* base */
      UINT16_C( 2 ), /* id */
      UINT8_C( 0 ), /* isImmediate */
      UINT8_C( 0 ), /* isDefined */
      UINT8_C( 0 )  /* hasInitValue */
    },
    EcuMConf_EcuMWakeupSource_ECUM_WKSOURCE_CAN, /* channel */
    UINT8_C( 0 )  /* mode */
  }
};

/**
 * BswMGenericRequestPortTable
 */
BswMGenericRequestPortType BswMGenericRequestPortTable[6] = 
{
  { /* [0] */
    { /* base */
      UINT16_C( 0 ), /* id */
      UINT8_C( 0 ), /* isImmediate */
      UINT8_C( 0 ), /* isDefined */
      UINT8_C( 0 )  /* hasInitValue */
    },
    UINT16_C( 0 ), /* channel */
    UINT16_C( 0 )  /* mode */
  },
  { /* [1] */
    { /* base */
      UINT16_C( 4 ), /* id */
      UINT8_C( 0 ), /* isImmediate */
      UINT8_C( 0 ), /* isDefined */
      UINT8_C( 0 )  /* hasInitValue */
    },
    UINT16_C( 1 ), /* channel */
    UINT16_C( 0 )  /* mode */
  },
  { /* [2] */
    { /* base */
      UINT16_C( 5 ), /* id */
      UINT8_C( 0 ), /* isImmediate */
      UINT8_C( 0 ), /* isDefined */
      UINT8_C( 0 )  /* hasInitValue */
    },
    UINT16_C( 3 ), /* channel */
    UINT16_C( 0 )  /* mode */
  },
  { /* [3] */
    { /* base */
      UINT16_C( 6 ), /* id */
      UINT8_C( 0 ), /* isImmediate */
      UINT8_C( 0 ), /* isDefined */
      UINT8_C( 0 )  /* hasInitValue */
    },
    UINT16_C( 4 ), /* channel */
    UINT16_C( 0 )  /* mode */
  },
  { /* [4] */
    { /* base */
      UINT16_C( 7 ), /* id */
      UINT8_C( 0 ), /* isImmediate */
      UINT8_C( 0 ), /* isDefined */
      UINT8_C( 0 )  /* hasInitValue */
    },
    UINT16_C( 5 ), /* channel */
    UINT16_C( 0 )  /* mode */
  },
  { /* [5] */
    { /* base */
      UINT16_C( 8 ), /* id */
      UINT8_C( 0 ), /* isImmediate */
      UINT8_C( 0 ), /* isDefined */
      UINT8_C( 0 )  /* hasInitValue */
    },
    UINT16_C( 6 ), /* channel */
    UINT16_C( 0 )  /* mode */
  }
};

#define BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_MemMap.h>

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include <BswM_MemMap.h>
/**
 * BswM_PtrModeRequestPortsTable
 */
STATIC CONSTP2VAR( BswMModeRequestPortType, AUTOMATIC, BSWM_APPL_CONST ) BswM_PtrModeRequestPortsTable[13] = 
{
  &BswMCanSMIndicationPortTable[0], /* BSWM_CAN_SM_INDICATION */
  NULL_PTR, /* BSWM_COMM_INDICATION */
  NULL_PTR, /* BSWM_COMM_PNC_REQUEST */
  NULL_PTR, /* BSWM_DCM_APPLICATION_UPDATED_INDICATION */
  NULL_PTR, /* BSWM_DCM_COM_MODE_CURRENT_STATE */
  NULL_PTR, /* BSWM_DCM_COM_MODE_REQUEST */
  NULL_PTR, /* BSWM_DCM_RESET_MODE_REQUEST */
  NULL_PTR, /* BSWM_DCM_SESSION_MODE_REQUEST */
  NULL_PTR, /* BSWM_ECUM_INDICATION */
  &BswMEcuMWakeupSourcePortTable[0], /* BSWM_ECUM_WAKEUP_SOURCE */
  NULL_PTR, /* BSWM_GENERIC_REQUEST */
  NULL_PTR, /* BSWM_NVM_JOB_MODE_INDICATION */
  NULL_PTR  /* BSWM_NVM_REQUEST */
};

#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include <BswM_MemMap.h>

/*==================[external data]=========================================*/

#define BSWM_START_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_MemMap.h>
/**
 * BswM_LinkTimeContext
 */
STATIC BswM_LinkTimeContextType BswM_LinkTimeContext = 
{
  &BswM_ExprGetState, /* logicalExprGetStateFuncPtr */
  &BswM_ExprGetResult, /* logicalExprGetResultFuncPtr */
  &BswM_ExecuteAction, /* executeActionFuncPtr */
  &BswM_ExecuteModeArbitration, /* executeModeArbitrationFuncPtr */
  &BswMGenericRequestPortTable[0], /* genericRequestPortsTablePtr */
  UINT16_C( 6 ), /* numBswMGenericRequestPorts */
  UINT16_C( 23 )  /* numBswMExpressions */
};

/**
 * BswM_Context
 */
BswM_PartitionContextType BswM_Context = 
{
  UINT8_C( 0 ), /* ID */
  &SchM_Enter_BswM_SCHM_BSWM_EXCLUSIVE_AREA, /* SchMEnter */
  &SchM_Exit_BswM_SCHM_BSWM_EXCLUSIVE_AREA, /* SchMExit */
  { /* RunTimeContext */
    UINT8_C( 0 ), /* IsInitialized */
    { /* IPduGroupReInitVector */
      UINT8_C( 0 ), /* [0] */
      UINT8_C( 0 ), /* [1] */
      UINT8_C( 0 ), /* [2] */
      UINT8_C( 0 )  /* [3] */
    },
    { /* IPduGroupVector */
      UINT8_C( 0 ), /* [0] */
      UINT8_C( 0 ), /* [1] */
      UINT8_C( 0 ), /* [2] */
      UINT8_C( 0 )  /* [3] */
    },
    UINT8_C( 0 ), /* PduGroupSwitchTriggered */
    UINT8_C( 0 ), /* PduGroupSwitchReInitTriggered */
    { /* LogicalExprInitStatus */
      UINT8_C( 0 ), /* [0] */
      UINT8_C( 0 ), /* [1] */
      UINT8_C( 0 ), /* [2] */
      UINT8_C( 0 ), /* [3] */
      UINT8_C( 0 ), /* [4] */
      UINT8_C( 0 ), /* [5] */
      UINT8_C( 0 ), /* [6] */
      UINT8_C( 0 ), /* [7] */
      UINT8_C( 0 ), /* [8] */
      UINT8_C( 0 ), /* [9] */
      UINT8_C( 0 ), /* [10] */
      UINT8_C( 0 ), /* [11] */
      UINT8_C( 0 ), /* [12] */
      UINT8_C( 0 ), /* [13] */
      UINT8_C( 0 ), /* [14] */
      UINT8_C( 0 ), /* [15] */
      UINT8_C( 0 ), /* [16] */
      UINT8_C( 0 ), /* [17] */
      UINT8_C( 0 ), /* [18] */
      UINT8_C( 0 ), /* [19] */
      UINT8_C( 0 ), /* [20] */
      UINT8_C( 0 ), /* [21] */
      UINT8_C( 0 )  /* [22] */
    },
    { /* RuleResultTable */
      UINT8_C( 0 ), /* [0] */
      UINT8_C( 0 ), /* [1] */
      UINT8_C( 0 ), /* [2] */
      UINT8_C( 0 ), /* [3] */
      UINT8_C( 0 ), /* [4] */
      UINT8_C( 0 ), /* [5] */
      UINT8_C( 0 ), /* [6] */
      UINT8_C( 0 ), /* [7] */
      UINT8_C( 0 ), /* [8] */
      UINT8_C( 0 ), /* [9] */
      UINT8_C( 0 ), /* [10] */
      UINT8_C( 0 ), /* [11] */
      UINT8_C( 0 ), /* [12] */
      UINT8_C( 0 ), /* [13] */
      UINT8_C( 0 ), /* [14] */
      UINT8_C( 0 ), /* [15] */
      UINT8_C( 0 ), /* [16] */
      UINT8_C( 0 ), /* [17] */
      UINT8_C( 0 ), /* [18] */
      UINT8_C( 0 ), /* [19] */
      UINT8_C( 0 ), /* [20] */
      UINT8_C( 0 ), /* [21] */
      UINT8_C( 0 )  /* [22] */
    }
  },
  &BswM_LinkTimeContext  /* LinkTimeContext */
};

#define BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_MemMap.h>

/*==================[external function definitions]=========================*/

#define BSWM_START_SEC_CODE
#include <BswM_MemMap.h>

FUNC(void, BSWM_CODE) BswM_LT_Init(void)
{
  DBG_BSWM_LT_INIT_ENTRY();

  BswM_MPI_BswM_Dcm_RequestPort.mode = BSWM_GET_UINT8_INITIAL_VALUES_TABLE(BswM_Context.ID)[0U];
  BswM_MPI_BswM_Dcm_ComM_RequestPort.mode = BSWM_GET_UINT8_INITIAL_VALUES_TABLE(BswM_Context.ID)[1U];

  {
    BswM_IndexType i,j;
    for (i = 0U; i < 13U; i++)
    {
      BswMModeRequestPortType* arrPtr = BswM_PtrModeRequestPortsTable[i];
      if ( arrPtr != NULL_PTR)
      {
        for (j = 0U; j < BswM_NumModeRequestPortsTable[i]; j++)
        {
          arrPtr[j].base.isDefined = arrPtr[j].base.hasInitValue;
        }
      }
    }
  }

  {
    BswM_IndexType i;
    for (i = 0U; i < BswM_NumModeRequestPortsTable[BSWM_GENERIC_REQUEST]; i++)
    {
      BswMGenericRequestPortTable[i].base.isDefined = BswMGenericRequestPortTable[i].base.hasInitValue;
    }
  }

  BswM_MPI_BswM_Dcm_RequestPort.base.isDefined = BswM_MPI_BswM_Dcm_RequestPort.base.hasInitValue;
  BswM_MPI_BswM_Dcm_ComM_RequestPort.base.isDefined = BswM_MPI_BswM_Dcm_ComM_RequestPort.base.hasInitValue;

  DBG_BSWM_LT_INIT_EXIT();
}

/*===================== BswModeNotification ports =====================*/
FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_RequestPort_NONE(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_REQUESTPORT_NONE_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_RequestPort.mode = RTE_MODE_DcmEcuReset_NONE;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_REQUESTPORT_NONE_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_RequestPort_HARD(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_REQUESTPORT_HARD_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_RequestPort.mode = RTE_MODE_DcmEcuReset_HARD;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_REQUESTPORT_HARD_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_RequestPort_KEYOFFON(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_REQUESTPORT_KEYOFFON_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_RequestPort.mode = RTE_MODE_DcmEcuReset_KEYOFFON;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_REQUESTPORT_KEYOFFON_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_RequestPort_SOFT(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_REQUESTPORT_SOFT_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_RequestPort.mode = RTE_MODE_DcmEcuReset_SOFT;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_REQUESTPORT_SOFT_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_RequestPort_JUMPTOBOOTLOADER(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_REQUESTPORT_JUMPTOBOOTLOADER_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_RequestPort.mode = RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_REQUESTPORT_JUMPTOBOOTLOADER_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_RequestPort_JUMPTOSYSSUPPLIERBOOTLOADER(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_REQUESTPORT_JUMPTOSYSSUPPLIERBOOTLOADER_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_RequestPort.mode = RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_REQUESTPORT_JUMPTOSYSSUPPLIERBOOTLOADER_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_RequestPort_EXECUTE(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_REQUESTPORT_EXECUTE_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_RequestPort.mode = RTE_MODE_DcmEcuReset_EXECUTE;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_REQUESTPORT_EXECUTE_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_ComM_RequestPort_DCM_ENABLE_RX_TX_NORM(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_ENABLE_RX_TX_NORM_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_ComM_RequestPort.mode = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_ComM_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_ENABLE_RX_TX_NORM_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_ComM_RequestPort_DCM_ENABLE_RX_DISABLE_TX_NORM(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_ENABLE_RX_DISABLE_TX_NORM_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_ComM_RequestPort.mode = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_ComM_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_ENABLE_RX_DISABLE_TX_NORM_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_ComM_RequestPort_DCM_DISABLE_RX_ENABLE_TX_NORM(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_DISABLE_RX_ENABLE_TX_NORM_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_ComM_RequestPort.mode = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_ComM_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_DISABLE_RX_ENABLE_TX_NORM_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_ComM_RequestPort_DCM_DISABLE_RX_TX_NORM(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_DISABLE_RX_TX_NORM_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_ComM_RequestPort.mode = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_ComM_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_DISABLE_RX_TX_NORM_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_ComM_RequestPort_DCM_ENABLE_RX_TX_NM(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_ENABLE_RX_TX_NM_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_ComM_RequestPort.mode = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NM;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_ComM_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_ENABLE_RX_TX_NM_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_ComM_RequestPort_DCM_ENABLE_RX_DISABLE_TX_NM(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_ENABLE_RX_DISABLE_TX_NM_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_ComM_RequestPort.mode = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NM;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_ComM_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_ENABLE_RX_DISABLE_TX_NM_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_ComM_RequestPort_DCM_DISABLE_RX_ENABLE_TX_NM(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_DISABLE_RX_ENABLE_TX_NM_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_ComM_RequestPort.mode = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NM;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_ComM_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_DISABLE_RX_ENABLE_TX_NM_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_ComM_RequestPort_DCM_DISABLE_RX_TX_NM(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_DISABLE_RX_TX_NM_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_ComM_RequestPort.mode = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NM;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_ComM_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_DISABLE_RX_TX_NM_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_ComM_RequestPort_DCM_ENABLE_RX_TX_NORM_NM(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_ENABLE_RX_TX_NORM_NM_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_ComM_RequestPort.mode = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_ComM_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_ENABLE_RX_TX_NORM_NM_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_ComM_RequestPort_DCM_ENABLE_RX_DISABLE_TX_NORM_NM(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_ENABLE_RX_DISABLE_TX_NORM_NM_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_ComM_RequestPort.mode = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_ComM_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_ENABLE_RX_DISABLE_TX_NORM_NM_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_ComM_RequestPort_DCM_DISABLE_RX_ENABLE_TX_NORM_NM(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_DISABLE_RX_ENABLE_TX_NORM_NM_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_ComM_RequestPort.mode = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_ComM_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_DISABLE_RX_ENABLE_TX_NORM_NM_EXIT();
}

FUNC(void, BSWM_CODE) BswM_MRPFunc_BswM_Dcm_ComM_RequestPort_DCM_DISABLE_RX_TX_NORM_NM(void) 
{

  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_DISABLE_RX_TX_NORM_NM_ENTRY();

  if (TRUE == BswM_Context.RunTimeContext.IsInitialized)
  {
    boolean hasActivatedActionLists = FALSE;
    boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
    TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );
    BswM_Context.SchMEnter();
    BswM_MPI_BswM_Dcm_ComM_RequestPort.mode = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM_NM;
    hasActivatedActionLists |= BswM_PortUpdated(&BswM_MPI_BswM_Dcm_ComM_RequestPort.base, activatedActionLists, &BswM_Context);
    BswM_Context.SchMExit();
    if (hasActivatedActionLists == TRUE) 
    {
      BswM_ExecuteModeControl(activatedActionLists, &BswM_Context);
    }
  }
  DBG_BSWM_MRPFUNC_BSWM_DCM_COMM_REQUESTPORT_DCM_DISABLE_RX_TX_NORM_NM_EXIT();
}

/*==================[internal function definitions]=========================*/

/* INDENT:OFF */
STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_BswM_StartupTwoA(void)
{
  return
  (
    (BswMGenericRequestPortTable[0U].mode == BSWM_STARTUP_TWO_A)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_BswM_StartupTwoB(void)
{
  return
  (
    (BswMGenericRequestPortTable[0U].mode == BSWM_STARTUP_TWO_B)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_BswM_GoOffOneA(void)
{
  return
  (
    (BswMGenericRequestPortTable[0U].mode == BSWM_GO_OFF_ONE_A)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_BswM_GoOffOneB(void)
{
  return
  (
    (BswMGenericRequestPortTable[0U].mode == BSWM_GO_OFF_ONE_B)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_WakeUpValidated(void)
{
  return
  (
    (BswMGenericRequestPortTable[0U].mode == BSWM_WAIT_WAKEUP_VALIDATION) &&
    (BswMEcuMWakeupSourcePortTable[0U].mode == ECUM_WKSTATUS_VALIDATED)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_WakeUpExpired(void)
{
  return
  (
    (BswMEcuMWakeupSourcePortTable[0U].mode == ECUM_WKSTATUS_EXPIRED) &&
    (BswMGenericRequestPortTable[0U].mode == BSWM_WAIT_WAKEUP_VALIDATION)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_StartShutdownSequence(void)
{
  return
  (
    (BswMGenericRequestPortTable[5U].mode == BSWM_ECU_SHUTDOWN_REQUESTED)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_PrepareHWReset(void)
{
  return
  (
    (BswM_MPI_BswM_Dcm_RequestPort.mode == RTE_MODE_DcmEcuReset_HARD)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_ExecuteReset(void)
{
  return
  (
    (BswM_MPI_BswM_Dcm_RequestPort.mode == RTE_MODE_DcmEcuReset_EXECUTE)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_PrepareSWReset(void)
{
  return
  (
    (BswM_MPI_BswM_Dcm_RequestPort.mode == RTE_MODE_DcmEcuReset_SOFT)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_StartComEffective(void)
{
  return
  (
    (BswMCanSMIndicationPortTable[0U].mode != CANSM_BSWM_NO_COMMUNICATION) &&
    (BswMGenericRequestPortTable[0U].mode == BSWM_WAIT_WAKEUP_VALIDATION)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_PrepareJumpToFbl(void)
{
  return
  (
    (BswM_MPI_BswM_Dcm_RequestPort.mode == RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterRunFromWakeup(void)
{
  return
  (
    (BswMGenericRequestPortTable[2U].mode == BSWM_WAKEUP_MODE_ACTIVE)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterRunFromPostRun_1(void)
{
  return
  (
    (BswMGenericRequestPortTable[2U].mode == BSWM_POST_RUN_MODE_ACTIVE) &&
    (BswMGenericRequestPortTable[1U].mode == BSWM_PASSANGER_OCCUPANCY_DETECTED)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterRunFromPostRun_2(void)
{
  return
  (
    (BswMGenericRequestPortTable[2U].mode == BSWM_POST_RUN_MODE_ACTIVE) &&
    (BswMGenericRequestPortTable[4U].mode == BSWM_ENABLE_TX_PDU)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterPostRunFromRun(void)
{
  return
  (
    (BswMGenericRequestPortTable[4U].mode == BSWM_DISABLE_TX_PDU) &&
    (BswMGenericRequestPortTable[2U].mode == BSWM_RUN_MODE_ACTIVE)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterRunFromLowPwr_ActiveWake(void)
{
  return
  (
    (BswMGenericRequestPortTable[1U].mode == BSWM_PASSANGER_OCCUPANCY_DETECTED) &&
    (BswMGenericRequestPortTable[2U].mode == BSWM_LOW_PWR_MODE_ACTIVE) &&
    (BswMGenericRequestPortTable[3U].mode == BSWM_ACTIVE_WAKEUP_REQ)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterRunFromLowPwr_PassiveWake(void)
{
  return
  (
    (BswMGenericRequestPortTable[2U].mode == BSWM_LOW_PWR_MODE_ACTIVE) &&
    (BswMGenericRequestPortTable[3U].mode == BSWM_PASSIVE_WAKEUP_REQ)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterLowPwrFromPostRun(void)
{
  return
  (
    (BswMGenericRequestPortTable[2U].mode == BSWM_LOW_PWR_MODE_REQUESTED)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnterShutdownFromLowPwr(void)
{
  return
  (
    (BswMGenericRequestPortTable[2U].mode == BSWM_LOW_PWR_MODE_ACTIVE) &&
    (BswMGenericRequestPortTable[1U].mode == BSWM_PASSANGER_OCCUPANCY_NOT_DETECTED) &&
    (BswMGenericRequestPortTable[3U].mode == BSWM_NO_WAKEUP_REQ)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnableTxPdu(void)
{
  return
  (
    (BswMGenericRequestPortTable[4U].mode == BSWM_ENABLE_TX_PDU)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_EnableTxPdu_DcmRequest(void)
{
  return
  (
    (BswM_MPI_BswM_Dcm_ComM_RequestPort.mode == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprResult_BswMLogicalExpression_BswMRule_DisableTxPdu_DcmRequest(void)
{
  return
  (
    (BswM_MPI_BswM_Dcm_ComM_RequestPort.mode == RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM)
  ) ? BSWM_TRUE : BSWM_FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_BswM_StartupTwoA(void)
{
  return
  (
    (TRUE == BswMGenericRequestPortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_BswM_StartupTwoB(void)
{
  return
  (
    (TRUE == BswMGenericRequestPortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_BswM_GoOffOneA(void)
{
  return
  (
    (TRUE == BswMGenericRequestPortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_BswM_GoOffOneB(void)
{
  return
  (
    (TRUE == BswMGenericRequestPortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_WakeUpValidated(void)
{
  return
  (
    (TRUE == BswMGenericRequestPortTable[0U].base.isDefined) && 
    (TRUE == BswMEcuMWakeupSourcePortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_WakeUpExpired(void)
{
  return
  (
    (TRUE == BswMEcuMWakeupSourcePortTable[0U].base.isDefined) && 
    (TRUE == BswMGenericRequestPortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_StartShutdownSequence(void)
{
  return
  (
    (TRUE == BswMGenericRequestPortTable[5U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_PrepareHWReset(void)
{
  return
  (
    (TRUE == BswM_MPI_BswM_Dcm_RequestPort.base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_ExecuteReset(void)
{
  return
  (
    (TRUE == BswM_MPI_BswM_Dcm_RequestPort.base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_PrepareSWReset(void)
{
  return
  (
    (TRUE == BswM_MPI_BswM_Dcm_RequestPort.base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_StartComEffective(void)
{
  return
  (
    (TRUE == BswMCanSMIndicationPortTable[0U].base.isDefined) && 
    (TRUE == BswMGenericRequestPortTable[0U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_PrepareJumpToFbl(void)
{
  return
  (
    (TRUE == BswM_MPI_BswM_Dcm_RequestPort.base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnterRunFromWakeup(void)
{
  return
  (
    (TRUE == BswMGenericRequestPortTable[2U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnterRunFromPostRun_1(void)
{
  return
  (
    (TRUE == BswMGenericRequestPortTable[2U].base.isDefined) && 
    (TRUE == BswMGenericRequestPortTable[1U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnterRunFromPostRun_2(void)
{
  return
  (
    (TRUE == BswMGenericRequestPortTable[2U].base.isDefined) && 
    (TRUE == BswMGenericRequestPortTable[4U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnterPostRunFromRun(void)
{
  return
  (
    (TRUE == BswMGenericRequestPortTable[4U].base.isDefined) && 
    (TRUE == BswMGenericRequestPortTable[2U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnterRunFromLowPwr_ActiveWake(void)
{
  return
  (
    (TRUE == BswMGenericRequestPortTable[1U].base.isDefined) && 
    (TRUE == BswMGenericRequestPortTable[2U].base.isDefined) && 
    (TRUE == BswMGenericRequestPortTable[3U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnterRunFromLowPwr_PassiveWake(void)
{
  return
  (
    (TRUE == BswMGenericRequestPortTable[2U].base.isDefined) && 
    (TRUE == BswMGenericRequestPortTable[3U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnterLowPwrFromPostRun(void)
{
  return
  (
    (TRUE == BswMGenericRequestPortTable[2U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnterShutdownFromLowPwr(void)
{
  return
  (
    (TRUE == BswMGenericRequestPortTable[2U].base.isDefined) && 
    (TRUE == BswMGenericRequestPortTable[1U].base.isDefined) && 
    (TRUE == BswMGenericRequestPortTable[3U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnableTxPdu(void)
{
  return
  (
    (TRUE == BswMGenericRequestPortTable[4U].base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_EnableTxPdu_DcmRequest(void)
{
  return
  (
    (TRUE == BswM_MPI_BswM_Dcm_ComM_RequestPort.base.isDefined)
  ) ? TRUE : FALSE;
}

STATIC FUNC(boolean, BSWM_CODE) BswM_ExprState_BswMLogicalExpression_BswMRule_DisableTxPdu_DcmRequest(void)
{
  return
  (
    (TRUE == BswM_MPI_BswM_Dcm_ComM_RequestPort.base.isDefined)
  ) ? TRUE : FALSE;
}


/* INDENT:ON */

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_OnStartupTwoA(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTUPTWOA_ENTRY();
  (void)BswM_OnStartupTwoA();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTUPTWOA_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_OnStartupTwoB(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTUPTWOB_ENTRY();
  (void)BswM_OnStartupTwoB();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTUPTWOB_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_ComM_EnablePdus(void)
{
  DBG_BSWM_ACTION_BSWMACTION_COMM_ENABLEPDUS_ENTRY();
  BswM_ExecutePduGroupSwitchAction(0U, &BswM_Context);
  DBG_BSWM_ACTION_BSWMACTION_COMM_ENABLEPDUS_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_OnGoOffOneA(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_ONGOOFFONEA_ENTRY();
  (void)BswM_OnGoOffOneA();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_ONGOOFFONEA_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_OnWakeupExpired(void)
{
  DBG_BSWM_ACTION_BSWMACTION_ONWAKEUPEXPIRED_ENTRY();
  (void)BswM_OnWakeupExpired();
  DBG_BSWM_ACTION_BSWMACTION_ONWAKEUPEXPIRED_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_OnWakeupValidation(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_ONWAKEUPVALIDATION_ENTRY();
  (void)BswM_OnWakeupValidation();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_ONWAKEUPVALIDATION_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_On_Prep_Shutdown(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_ON_PREP_SHUTDOWN_ENTRY();
  (void)BswM_On_Prep_Shutdown();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_ON_PREP_SHUTDOWN_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_EcuM_SelectShutdownTarget_RESET(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_BSWMACTION_ECUM_SELECTSHUTDOWNTARGET_RESET_ENTRY();
  result = EcuM_SelectShutdownTarget(ECUM_STATE_RESET, 3);
  DBG_BSWM_ACTION_BSWMACTION_ECUM_SELECTSHUTDOWNTARGET_RESET_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_OnStartComEffective(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTCOMEFFECTIVE_ENTRY();
  (void)BswM_OnStartComEffective();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTCOMEFFECTIVE_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_ProceedReset(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_PROCEEDRESET_ENTRY();
  (void)BswM_ProceedReset();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_PROCEEDRESET_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_SWResetNotification(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_SWRESETNOTIFICATION_ENTRY();
  (void)BswM_SWResetNotification();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_SWRESETNOTIFICATION_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_HWResetNotification(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_HWRESETNOTIFICATION_ENTRY();
  (void)BswM_HWResetNotification();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_HWRESETNOTIFICATION_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_PrepareJumpToFBL(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_PREPAREJUMPTOFBL_ENTRY();
  (void)BswM_JumpToFBLNotification();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_PREPAREJUMPTOFBL_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_RunStateFromWakeup(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMWAKEUP_ENTRY();
  (void)BswM_OnRunFromWakeup();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMWAKEUP_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_PostRunStateFromRun(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_POSTRUNSTATEFROMRUN_ENTRY();
  (void)BswM_OnPostRunFromRun();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_POSTRUNSTATEFROMRUN_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_RunStateFromPostRunBusAvailable(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMPOSTRUNBUSAVAILABLE_ENTRY();
  (void)BswM_OnRunFromPostRunBusAvailable();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMPOSTRUNBUSAVAILABLE_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_LowPwrStateFromPostRun(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_LOWPWRSTATEFROMPOSTRUN_ENTRY();
  (void)BswM_OnLowPwrFromPostRun();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_LOWPWRSTATEFROMPOSTRUN_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_RunStateFromLowPwr_ActiveWake(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMLOWPWR_ACTIVEWAKE_ENTRY();
  (void)BswM_OnRunFromLowPwrPassengerDetected();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMLOWPWR_ACTIVEWAKE_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_RunStateFromLowPwr_PassiveWake(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMLOWPWR_PASSIVEWAKE_ENTRY();
  (void)BswM_OnRunFromLowPwrBusAvailable();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMLOWPWR_PASSIVEWAKE_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_EcuM_SelectShutdownTarget_SLEEP(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_BSWMACTION_ECUM_SELECTSHUTDOWNTARGET_SLEEP_ENTRY();
  result = EcuM_SelectShutdownTarget(ECUM_STATE_SLEEP, 0);
  DBG_BSWM_ACTION_BSWMACTION_ECUM_SELECTSHUTDOWNTARGET_SLEEP_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_ComM_FullCom(void)
{
  Std_ReturnType result;
  DBG_BSWM_ACTION_BSWMACTION_COMM_FULLCOM_ENTRY();
  result = ComM_RequestComMode( 0, COMM_FULL_COMMUNICATION );
  DBG_BSWM_ACTION_BSWMACTION_COMM_FULLCOM_EXIT(result);
  return result;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_ComM_EnableTxPduConfirmation(void)
{
  DBG_BSWM_ACTION_BSWMACTION_COMM_ENABLETXPDUCONFIRMATION_ENTRY();
  (void)BswM_OnEnableTxPdu();
  DBG_BSWM_ACTION_BSWMACTION_COMM_ENABLETXPDUCONFIRMATION_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_ComM_DisableTxPduConfirmation(void)
{
  DBG_BSWM_ACTION_BSWMACTION_COMM_DISABLETXPDUCONFIRMATION_ENTRY();
  (void)BswM_OnDisableTxPdu();
  DBG_BSWM_ACTION_BSWMACTION_COMM_DISABLETXPDUCONFIRMATION_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_RunStateFromPostRunPassengerDetected(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMPOSTRUNPASSENGERDETECTED_ENTRY();
  (void)BswM_OnRunFromPostRunPassengerDetected();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMPOSTRUNPASSENGERDETECTED_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_OnSafeStateFromPostRun(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSAFESTATEFROMPOSTRUN_ENTRY();
  (void)BswM_OnSafeStateFromPostRun();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSAFESTATEFROMPOSTRUN_EXIT();
  return E_OK;
}

STATIC FUNC(Std_ReturnType, BSWM_CODE)BswM_Action_BswMAction_BswM_OnRunFromSafeState(void)
{
  DBG_BSWM_ACTION_BSWMACTION_BSWM_ONRUNFROMSAFESTATE_ENTRY();
  (void)BswM_OnRunFromSafeState();
  DBG_BSWM_ACTION_BSWMACTION_BSWM_ONRUNFROMSAFESTATE_EXIT();
  return E_OK;
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprGetState(uint16 exprIndex)
{
  return BswM_LogicalExprTable[exprIndex].GetState();
}

STATIC FUNC(BswMResultType, BSWM_CODE) BswM_ExprGetResult(uint16 exprIndex)
{
  return BswM_LogicalExprTable[exprIndex].GetResult();
}

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ExecuteAction(uint16 actionIndex)
{
  return BswM_ActionTable[actionIndex]();
}

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ExecuteModeArbitration(uint8 source, uint32 channel, uint8 mode)
{
  BswM_PartitionContextType* inst = BswM_GetInstance();
  BswMModeRequestPortType* arrPtr;
  BswM_IndexType i;

  if (TRUE == inst->RunTimeContext.IsInitialized)
  {
    arrPtr = BswM_PtrModeRequestPortsTable[source];

    if ( arrPtr != NULL_PTR)
    {
      boolean hasActivatedActionLists = FALSE;
      boolean activatedActionLists[BSWM_MAX_NUM_ACTION_LISTS];
      TS_MemSet(activatedActionLists, 0x00U, BSWM_MAX_NUM_ACTION_LISTS );

      inst->SchMEnter();
      for (i= 0U; i < BswM_NumModeRequestPortsTable[source]; i++)
      {
        if (((source != BSWM_ECUM_WAKEUP_SOURCE) && (arrPtr[i].channel == channel)) || ((source == BSWM_ECUM_WAKEUP_SOURCE) && ((((uint32)1U << arrPtr[i].channel) & channel) != 0U)))
        {
          arrPtr[i].mode = mode;
          hasActivatedActionLists |= BswM_PortUpdated(&(arrPtr[i].base), activatedActionLists, inst);
        }
      }
      inst->SchMExit();
      if (hasActivatedActionLists == TRUE)
      {
        BswM_ExecuteModeControl(activatedActionLists, inst);
      }
    }
  }
  return E_OK;
}

#define BSWM_STOP_SEC_CODE
#include <BswM_MemMap.h>

/** @} doxygen end group definition */
/*==================[end of file]===========================================*/
