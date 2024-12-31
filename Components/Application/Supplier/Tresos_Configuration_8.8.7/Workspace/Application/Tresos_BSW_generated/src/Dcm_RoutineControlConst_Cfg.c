/**
 * \file
 *
 * \brief AUTOSAR Dcm
 *
 * This file contains the implementation of the AUTOSAR
 * module Dcm.
 *
 * \version 5.0.15
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO Dcm.Dsn.File.RoutineControlConst.ConfigC,1 */

/*==================[inclusions]=================================================================*/

#include <Dcm_RoutineControl_Cfg.h>                             /*  RoutineControl Configuration */

/*==================[macros]=====================================================================*/

/*==================[type definitions]===========================================================*/

/*==================[external function declarations]=============================================*/

/*==================[internal function declarations]=============================================*/

/*==================[internal constants]=========================================================*/

/*==================[internal data]==============================================================*/

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>

/* Array of session types for all routines */
STATIC CONST(Dcm_SesCtrlType, DCM_CONST) Dcm_RoutineControl_SessionTypes[9] =
{
  0x7eU,
  0x7eU,
  0x01U,
  0x7eU,
  0x7eU,
  0x7eU,
  0x01U,
  0x03U,
  0x7eU,
};

/* Array of security types for all routines */
STATIC CONST(Dcm_SecLevelType,DCM_CONST) Dcm_RoutineControl_SecurityLevel[6] =
{
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
  0x31U,
};

#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>

/*==================[external constants]=========================================================*/

#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/* Configuration parameters for 'Routine Control' service */
CONST(Dcm_DspRoutineServicesType, DCM_CONST) Dcm_DspRoutineConfig[DCM_NUM_ROUTINES] =
{
  {
    /* Pointer to request service handler function */
    &Dcm_DcmDspRoutineCtrl_Lock_UnlockECU_RequestResults,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutineCtrl_Lock_UnlockECU_Start,
    /* Pointer to stop service handler function */
    &Dcm_DcmDspRoutineCtrl_Lock_UnlockECU_Stop,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[0],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0xf781U,
  },
  {
    /* Pointer to request service handler function */
    &Dcm_DcmDspRoutineProcessMode_RequestResults,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutineProcessMode_Start,
    /* Pointer to stop service handler function */
    &Dcm_DcmDspRoutineProcessMode_Stop,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[1],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0xf793U,
  },
  {
    /* Pointer to request service handler function */
    NULL_PTR,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutineAccCalib_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[2],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0xf794U,
  },
  {
    /* Pointer to request service handler function */
    NULL_PTR,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutineLockSolenoid_Start,
    /* Pointer to stop service handler function */
    &Dcm_DcmDspRoutineLockSolenoid_Stop,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[3],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0xf795U,
  },
  {
    /* Pointer to request service handler function */
    NULL_PTR,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutineEcuTempCalibration_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[4],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0xf796U,
  },
  {
    /* Pointer to request service handler function */
    NULL_PTR,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutineAccAngleOffsetCalibration_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[5],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0xf797U,
  },
  {
    /* Pointer to request service handler function */
    NULL_PTR,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutineRoutineCheckProgrammingPreconditions_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[6],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0x203U,
  },
};

/* Contains the configuration (parameters) for Routine's Info */
CONST(Dcm_DspRoutineServicesInfoType, DCM_CONST) Dcm_DspRoutineInfoConfig[7] =
{
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[0]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[0]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[1]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[1]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[2]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[2]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[3]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[3]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[4]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[4]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[5]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[5]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    NULL_PTR,
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[6]),
    /* Number of sessions */
    3U,
    /* Number of security levels */
    0U
  },
};

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/*==================[external data]==============================================================*/

/*==================[external function definitions]==============================================*/

/*==================[internal function definitions]==============================================*/

/*==================[end of file]================================================================*/
