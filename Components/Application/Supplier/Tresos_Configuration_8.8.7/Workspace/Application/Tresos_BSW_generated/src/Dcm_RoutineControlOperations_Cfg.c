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


/* !LINKSTO Dcm.Dsn.File.RoutineControlOperations.ConfigC,1 */

 /* MISRA-C:2004 Deviation List
  *
  * MISRA-1) Deviated Rule: 11.4 (advisory)
  *     A cast should not be performed between a pointer to object type and a
  *     different pointer to object type.
  *
  *     Reason:
  *     A cast to unsigned is necessary here to copy data bit by bit and
  *     there is no alignment issues.
  *
  */

 /* MISRA-C:2012 Deviation List
  *
  *  MISRAC2012-1) Deviated Rule: 11.3 (required)
  *     "A cast should not be performed between a pointer to object type and a different pointer to
  *     object type."
  *
  *     Reason:
  *     A cast to UINT8 is necessary here to copy data bit by bit and to be flexible for all
  *     the types, being no alignment issues.
  *     There is no side effects.
  *
  *  MISRAC2012-2) Deviated Rule: 8.9 (advisory)
  *     "An object should be defined at block scope if its identifier only
  *     appears in a single function."
  *
  *     Reason:
  *     The object is defined in this way because the values that are stored
  *     in them are required for the next call of this function and should be
  *     hold in the data segment memory.
  *
  */

/*==================[inclusions]=================================================================*/

#include <Dcm_RoutineControl_Cfg.h>                             /*  RoutineControl Configuration */
#include <Dcm_API_Cfg.h>                                  /*  Configurable function declarations */
#include <Dcm_DspExternal.h>                           /* Callbacks provided by Central Diag SwC */
#include <Dcm_Dsl_Supervisor.h>                        /* Dcm Dsl Supervisor header file */
#include <TSMem.h>
/*==================[macros]=====================================================================*/

/* The minimum length of a positive response (without the SID which is already added in the Dsd) is:
 * byte Subservice ID + 2 bytes RoutineId. */
#define DCM_SUBSERVICEID_AND_ROUTINEID_LENGTH 3U

/*==================[type definitions]===========================================================*/

/*==================[external function declarations]=============================================*/

/*==================[internal function declarations]=============================================*/


#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>

STATIC FUNC(void, DCM_CODE) Dcm_Dsp_RoutineControl_ClearInternalArrays(void);

#if (DCM_ROUTINE_ENDIANNESS_CONVERSION == STD_ON)
STATIC FUNC(void, DCM_CODE) Dcm_Dsp_RoutineControl_SwapBytes_U16(uint16* SignalData, uint32 SignalLength);



#endif

#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>

/*==================[internal constants]=========================================================*/

/*==================[internal data]==============================================================*/

#define DCM_START_SEC_VAR_CLEARED_8
#include <Dcm_MemMap.h>

/* Defining global uint8 buffer for API parameters used by Routine Control service */
STATIC VAR(uint8, DCM_VAR) Uint8Array[2];

/* Defining global sint8 buffer for API parameters used by Routine Control service */
STATIC VAR(sint8, DCM_VAR) Sint8Array[1];

#define DCM_STOP_SEC_VAR_CLEARED_8
#include <Dcm_MemMap.h>

#define DCM_START_SEC_VAR_CLEARED_16
#include <Dcm_MemMap.h>

/* Defining global uint16 buffer for API parameters used by Routine Control service */
STATIC VAR(uint16, DCM_VAR) Uint16Array[3];

#define DCM_STOP_SEC_VAR_CLEARED_16
#include <Dcm_MemMap.h>

/*==================[external constants]=========================================================*/

/*==================[external data]==============================================================*/

/*==================[external function definitions]==============================================*/

#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutineCtrl_Lock_UnlockECU_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineCtrl_Lock_UnlockECU_Start(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineCtrl_Lock_UnlockECU_Start(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}
#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutineCtrl_Lock_UnlockECU_Stop(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineCtrl_Lock_UnlockECU_Stop(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineCtrl_Lock_UnlockECU_Stop(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}
#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutineCtrl_Lock_UnlockECU_RequestResults(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the configuration for current protocol */
  Dcm_ProtocolConfigType CurProtocolConfig;

  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  /* This is executed in the context of the SvcH and the protocol on which the request was made is
   * surely started */
  (void) Dcm_Dsl_Supervisor_GetLatestExternalUDSProtocolConfig(&CurProtocolConfig);

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineCtrl_Lock_UnlockECU_RequestResults(DCM_INITIAL, &Uint8Array[0], &Uint16Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineCtrl_Lock_UnlockECU_RequestResults(OpStatus, &Uint8Array[0], &Uint16Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 6U;
#if (DCM_ROUTINE_ENDIANNESS_CONVERSION == STD_ON)
    /* !LINKSTO Dcm.EB.RoutineControl.EndiannessEnabled,1 */
    if(CurProtocolConfig.EndiannessConversion == TRUE)
    {
      Dcm_Dsp_RoutineControl_SwapBytes_U16(&Uint16Array[0], 1U);
    }
#endif /*(DCM_ROUTINE_ENDIANNESS_CONVERSION == STD_ON)*/

    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint16Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   8U,
                                   16U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}
#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutineProcessMode_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineProcessMode_Start(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineProcessMode_Start(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}
#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutineProcessMode_Stop(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineProcessMode_Stop(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineProcessMode_Stop(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}
#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutineProcessMode_RequestResults(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineProcessMode_RequestResults(DCM_INITIAL, &Uint8Array[0], &Uint8Array[1], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineProcessMode_RequestResults(OpStatus, &Uint8Array[0], &Uint8Array[1], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 5U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[1],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   8U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}
#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutineAccCalib_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineAccCalib_Start(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineAccCalib_Start(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}
#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutineLockSolenoid_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineLockSolenoid_Start(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineLockSolenoid_Start(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}
#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutineLockSolenoid_Stop(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineLockSolenoid_Stop(DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineLockSolenoid_Stop(OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}
#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutineEcuTempCalibration_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 1U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Sint8Array[0],
                                     0U,
                                     0U,
                                     8U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineEcuTempCalibration_Start(Sint8Array[0], DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineEcuTempCalibration_Start(Sint8Array[0], OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}
#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutineAccAngleOffsetCalibration_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Parameter to store the configuration for current protocol */
  Dcm_ProtocolConfigType CurProtocolConfig;

  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  /* This is executed in the context of the SvcH and the protocol on which the request was made is
   * surely started */
  (void) Dcm_Dsl_Supervisor_GetLatestExternalUDSProtocolConfig(&CurProtocolConfig);

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 6U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint16Array[0],
                                     0U,
                                     0U,
                                     16U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint16Array[1],
                                     16U,
                                     0U,
                                     16U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

      /* Deviation MISRAC2012-1 <+2> */
      /* Deviation MISRA-1 <+2> */
      Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->reqData[2]),
                                     (P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint16Array[2],
                                     32U,
                                     0U,
                                     16U,
                                     DCM_COPY_FROM_INBUFFER_OPAQUE,
                                     DCM_BYTE_DIRECTION_INCREMENT);

#if (DCM_ROUTINE_ENDIANNESS_CONVERSION == STD_ON)
      /* !LINKSTO Dcm.EB.RoutineControl.EndiannessEnabled,1 */
      if(CurProtocolConfig.EndiannessConversion == TRUE)
      {
        Dcm_Dsp_RoutineControl_SwapBytes_U16(&Uint16Array[0], 3U);
      }
#endif /*(DCM_ROUTINE_ENDIANNESS_CONVERSION == STD_ON)*/

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineAccAngleOffsetCalibration_Start(Uint16Array[0], Uint16Array[1], Uint16Array[2], DCM_INITIAL, &Uint8Array[0], ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineAccAngleOffsetCalibration_Start(Uint16Array[0], Uint16Array[1], Uint16Array[2], OpStatus, &Uint8Array[0], ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = 4U;
    /* Deviation MISRAC2012-1 <+2> */
    /* Deviation MISRA-1 <+2> */
    Dcm_DspInternal_CopySignalData((P2VAR(uint8, AUTOMATIC, DCM_VAR))&Uint8Array[0],
                                   (P2VAR(uint8, AUTOMATIC, DCM_VAR))&(pMsgContext->resData[3]),
                                   0U,
                                   0U,
                                   8U,
                                   DCM_COPY_TO_OUTBUFFER_OPAQUE,
                                   DCM_BYTE_DIRECTION_INCREMENT);

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}
#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>

#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>
FUNC(Std_ReturnType, DCM_CODE) Dcm_DcmDspRoutineRoutineCheckProgrammingPreconditions_Start(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType ServiceProcessStatus = DCM_E_NOT_OK;
  /* Variable length input/output signal length */
  uint16 CurrentDataLength = 0U;
  /* Parameter to store the length of input data (2U indicates the 2-byte RoutineID) received */
  Dcm_MsgLenType InDataLength = pMsgContext->reqDataLen - 2U;

  if (DCM_INITIAL == OpStatus)
  {
    /* Total input data length check */
    if (InDataLength == 0U)
    {

      Dcm_Dsp_RoutineControl_ClearInternalArrays();

      ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineRoutineCheckProgrammingPreconditions_Start(DCM_INITIAL, &(pMsgContext->resData[3]), &CurrentDataLength, ErrorCode);

    }
    else
    {
      /* Invalid total data length */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      ServiceProcessStatus = DCM_E_NOT_OK;
    }
  }
  else
  {
    ServiceProcessStatus = Rte_Call_RoutineServices_DcmDspRoutineRoutineCheckProgrammingPreconditions_Start(OpStatus, &(pMsgContext->resData[3]), &CurrentDataLength, ErrorCode);
  }

  if (ServiceProcessStatus == E_OK)
  {
    pMsgContext->resDataLen = DCM_GET_BYTES((Dcm_MsgLenType)CurrentDataLength) + DCM_SUBSERVICEID_AND_ROUTINEID_LENGTH;

    ServiceProcessStatus = DCM_E_OK;
  }
  else if(ServiceProcessStatus == E_NOT_OK)
  {
    ServiceProcessStatus = DCM_E_NOT_OK;
  }
  else
  {
    /* ServiceProcessStatus is DCM_E_PENDING, DCM_E_FORCE_RCRRP or unknown and these
     * cases are processed in service handler */
  }

  return ServiceProcessStatus;
}
#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>

/*==================[internal function definitions]==============================================*/
#define DCM_START_SEC_CODE
#include <Dcm_MemMap.h>

STATIC FUNC(void, DCM_CODE) Dcm_Dsp_RoutineControl_ClearInternalArrays(void)
{

  TS_MemSet(Uint8Array,0U,sizeof(Uint8Array));

  TS_MemSet(Sint8Array,0U,sizeof(Sint8Array));

  TS_MemSet(Uint16Array,0U,sizeof(Uint16Array));

}
#if (DCM_ROUTINE_ENDIANNESS_CONVERSION == STD_ON)

STATIC FUNC(void, DCM_CODE) Dcm_Dsp_RoutineControl_SwapBytes_U16(uint16* SignalData, uint32 SignalLength)
{
  uint16_least ArrayIndex;
  for(ArrayIndex = 0U; ArrayIndex < SignalLength; ArrayIndex++)
  {
    const uint16 TempParameter = (SignalData[ArrayIndex] >> 8U) | (SignalData[ArrayIndex] << 8U);
    SignalData[ArrayIndex] = TempParameter;
  }
}



#endif
#define DCM_STOP_SEC_CODE
#include <Dcm_MemMap.h>
/*==================[end of file]================================================================*/
