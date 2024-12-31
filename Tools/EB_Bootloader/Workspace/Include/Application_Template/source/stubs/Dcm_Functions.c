/**
 * \file
 *
 * \brief AUTOSAR Dcm
 *
 * This file contains the stub implementation of the AUTOSAR
 * module Dcm.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/
#include <Dcm.h>
#include <Rte_TestSwc_RGS_VL.h>
/* #include <RamSharedData.h> */
#include <TSAutosar.h>
#ifndef REMOVE_USRINFO_TRANSITION
/* #include <Dcm_Integration.h> */
#include <Mcu.h>
#endif
/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

typedef struct
{
    uint32 ulProgSig;
    uint8 ubResponseRequired;
    uint8 ubResetCause;
    uint8 ubRxPduId;
} tNoIntShareVar;
#define MYDCM_BOOT_STATUS_START_SEC_Common
#include <Common_MemMap.h>

/* For reprogramming when in application */
tNoIntShareVar stNoIntShareVar;

#define MYDCM_BOOT_STATUS_STOP_SEC_Common
#include <Common_MemMap.h>

/*==================[external function declarations]=========================*/


#define DCM_START_SEC_CALLOUT_CODE
#include <MemMap.h>
/** \brief Callout for retrieving the stored program conditions.
 **
 ** This callout allows the user to retrieve the stored programming environment from the
 ** non-volatile memory after jumping from bootloader.
 **
 ** \param[in,out]  ProgConditions Pointer to the structure which holds the program conditions
 **
 ** \return DCM_COLD_START or DCM_WARM_START.
 */
/* FUNC(Dcm_EcuStartModeType, DCM_CALLOUT_CODE) Dcm_GetProgConditions(Dcm_ProgConditionsPtrType progConditions) */
FUNC(Dcm_EcuStartModeType, DCM_CODE) Dcm_GetProgConditions(
  P2VAR(Dcm_ProgConditionsType, AUTOMATIC, DCM_APPL_DATA) ProgConditions)
{

  return DCM_COLD_START;
}

/** \brief Callout for storing the program conditions.
 **
 ** This callout allows the user to store the programming environment in a
 ** non-volatile memory before jumping to bootloader.
 **
 ** \param[in]  ProgConditions Pointer to the structure which holds the program conditions
 **
 ** \return E_OK, E_NOT_OK or DCM_E_PENDING.
 */
/* FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_SetProgConditions(Dcm_ProgConditionsPtrType progConditions) */
FUNC(Std_ReturnType, DCM_CODE) Dcm_SetProgConditions(
  P2VAR(Dcm_ProgConditionsType, AUTOMATIC, DCM_APPL_DATA) ProgConditions)
{
  if (ProgConditions->ReprogramingRequest == TRUE)
  {
    stNoIntShareVar.ulProgSig = 0x55AA55AAU;
	stNoIntShareVar.ubResponseRequired = TRUE;
    stNoIntShareVar.ubResetCause = 0x02U;
	stNoIntShareVar.ubRxPduId = 0u;
  }
  else
  {

  }
	Mcu_PerformReset();
  return DCM_E_OK;
}

/** \brief Get number of failed attempts of a certain security level
 **
 ** The function Rte_DcmSetNumAtt() shall set the number of failed attempts for security access.The
 ** central diagnostic SwC has to store the number of failed attempts value into some kind of
 ** non-volatile memory.
 **
 ** \param SecurityLevel Requested security level
 **
 ** \return number of failed attempts
 **/
FUNC(uint8, DCM_APPL_CODE) Rte_DcmSecGetNumAtt(Dcm_SecLevelType SecurityLevel)
{
  uint8 retval = 0U;

  return retval;
}
/** \brief Callout for upload of data (used for service TransferData).
 **
 ** This callout allows the user to transfer data from the ECU to the tester, after
 ** successful execution of a RequestUpload service.
 **
 ** \param[in]    OpStatus Operation status
 ** \param[in]    MemoryIdentifier Identifier of the memory device (optional)
 ** \param[in]    MemoryAddress Start address of the memory from which data is to be retrieved
 ** \param[in]    MemorySize Number of bytes to be read
 ** \param[in,out] MemoryData Pointer to the buffer in Dcm
 **
 ** \return DCM_READ_OK, DCM_READ_PENDING or DCM_READ_FAILED.
 */
FUNC(Dcm_ReturnReadMemoryType, DCM_APPL_CODE) Dcm_ReadMemory(
    Dcm_OpStatusType  OpStatus,
    uint8 MemoryIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) MemoryData)
{
  Dcm_ReturnReadMemoryType retval = DCM_READ_OK;

  return retval;
}

/** \brief Set number of failed attempts of a certain security level
 **
 ** The function Rte_DcmSetNumAtt() shall set the number of failed attempts for security access.The
 ** central diagnostic SwC has to store the number of failed attempts value into some kind of
 ** non-volatile memory.
 **
 ** \param SecurityLevel Requested security level
 ** \param NumAtt Number of failed attempts
 **/
FUNC(void, DCM_APPL_CODE) Rte_DcmSecSetNumAtt(Dcm_SecLevelType SecurityLevel, uint8 NumAtt)
{

}

/** \brief Callout for RequestDownload
 **
 **  This callout allows the user to implement the negotiation of a data transfer
 ** from the tester to the ECU.
 **
 ** \param[in]    OpStatus Operation status
 ** \param[in]    DataFormatIdentifier Format identifier from the request
 ** \param[in]    MemoryAddress Memory address to download
 ** \param[in]    MemorySize Size of memory to be downloaded
 ** \param[in]    BlockLength Maximum number of bytes for a write operation
 ** \param[in,out] ErrorCode NRC if the request for download fails.
 **
 ** \return E_OK, E_NOT_OK or DCM_E_PENDING.
 */
FUNC(Std_ReturnType, DCM_APPL_CODE) Dcm_ProcessRequestDownload(
    Dcm_OpStatusType  OpStatus,
    uint8 DataFormatIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    uint32 BlockLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/** \brief Confirmation function
 **
 ** Confirmation to be provided to the user when RTE is OFF.
 **
 ** \param SID Value of service identifier
 ** \param ReqType Address type from RxPdu
 ** \param SourceAddress Tester source address
 ** \param ConfirmationStatus status of the confirmation
 **
 ** \return None
 **/
FUNC(void, DCM_APPL_CODE) Rte_DcmConfirmation(
    uint8 SID,
    uint8 ReqType,
    uint16 SourceAddress,
    Dcm_ConfirmationStatusType ConfirmationStatus)
{

}

/** \brief Callout for RequestUpload.
 **
 **  This callout allows the user to implement the negotiation of a data transfer
 ** from the ECU to the tester.
 **
 ** \param[in]    OpStatus Operation status
 ** \param[in]    DataFormatIdentifier Format identifier from the request
 ** \param[in]    MemoryAddress Memory address to upload
 ** \param[in]    MemorySize Size of memory to be uploaded
 ** \param[in,out] ErrorCode NRC if the request for upload fails.
 **
 ** \return E_OK, E_NOT_OK or DCM_E_PENDING.
 */
FUNC(Std_ReturnType, DCM_APPL_CODE) Dcm_ProcessRequestUpload(
    Dcm_OpStatusType  OpStatus,
    uint8 DataFormatIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/** \brief Callout for download of data (used for service TransferData).
 **
 ** This callout allows the user to transfer data from the tester to the ECU, after
 ** successful execution of a RequestDownload service.
 **
 ** \param[in]    OpStatus Operation status
 ** \param[in]    MemoryIdentifier Identifier of the memory device (optional)
 ** \param[in]    MemoryAddress Start address of the memory from which data is to be retrieved
 ** \param[in]    MemorySize Number of bytes to be read
 ** \param[in,out] MemoryData Pointer to the buffer in Dcm
 **
 ** \return DCM_WRITE_OK, DCM_WRITE_PENDING or DCM_WRITE_FAILED.
 */
FUNC(Dcm_ReturnWriteMemoryType, DCM_APPL_CODE) Dcm_WriteMemory(
    Dcm_OpStatusType  OpStatus,
    uint8 MemoryIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) MemoryData)
{
  Dcm_ReturnWriteMemoryType retval = DCM_WRITE_OK;

  return retval;
}

/** \brief Callout for termination of an upload or download process.
 **
 ** This callout allows the user to terminate the data transfer between the ECU and the tester.
 **
 ** \param[in]    OpStatus Operation status
 ** \param[in]    ParameterRecord Pointer to vehicle/manufacturer specific data (optional)
 ** \param[in]    ParameterRecordSize Length of ParameterRecord in bytes (optional)
 ** \param[in,out] ErrorCode NRC if the request for termination fails.
 **
 ** \return E_OK, E_NOT_OK or DCM_E_PENDING.
 */
FUNC(Std_ReturnType, DCM_APPL_CODE) Dcm_ProcessRequestTransferExit(
    Dcm_OpStatusType  OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) ParameterRecord,
    uint32 ParameterRecordSize,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/** \brief Callout for service LinkControl.
 **
 ** This callout allows the user to control the communication baud rate of the ECU.
 **
 ** \param[in]    OpStatus Operation status
 ** \param[in]    LinkControlRequestType Sub-function identifier.
 ** \param[in]    BaudrateRecord Pointer to the array which holds the baudrate
 ** \param[in,out] ErrorCode NRC if the request for baudrate change fails.
 **
 ** \return E_OK, E_NOT_OK or DCM_E_PENDING.
 */
FUNC(Std_ReturnType, DCM_APPL_CODE) Dcm_LinkControl(
    Dcm_OpStatusType  OpStatus,
    Dcm_LinkControlRequestType LinkControlRequestType,
    P2VAR(uint8, AUTOMATIC, DCM_VAR)  BaudrateRecord,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_366_startRoutine(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) inParam0,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,
    AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}
/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_366_stopRoutine(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}


/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_366_requestRoutineResult(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8 , AUTOMATIC, DCM_VAR) outParam0,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,
    AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_300_Start(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) inParam0,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,
    AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_300_RequestResult(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8 , AUTOMATIC, DCM_VAR) outParam0,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,
    AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_ff00_Start(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8 , AUTOMATIC, DCM_VAR) outParam0,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,
    AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_ff00_RequestResult(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,
    AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_ff01_Start(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) inParam0,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8 , AUTOMATIC, DCM_VAR) outParam0,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,
    AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}
/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_ff01_RequestResult(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_202_Start(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8 , AUTOMATIC, DCM_VAR) outParam0,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_202_RequestResult(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,
    AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_203_Start(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) inParam0,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,
    AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_203_RequestResult(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,
    AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_374_Start(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) inParam0,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8 , AUTOMATIC, DCM_VAR) outParam0,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,
    AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_374_RequestResult(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8 , AUTOMATIC, DCM_VAR) outParam0,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,
    AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_375_Start(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) inParam0,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8 , AUTOMATIC, DCM_VAR) outParam0,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_375_RequestResult(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8 , AUTOMATIC, DCM_VAR) outParam0,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_43d_Start(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) inParam0,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8 , AUTOMATIC, DCM_VAR) outParam0,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_43d_RequestResult(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8 , AUTOMATIC, DCM_VAR) outParam0,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,
    AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_2ef_Start(
    P2CONST(uint8, AUTOMATIC, DCM_VAR) inParam0,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,
    AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.EB.RoutineServices.DcmDspRoutineFixedLength,1 */
Std_ReturnType Routine_2ef_RequestResult(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8 , AUTOMATIC, DCM_VAR) outParam0,
    P2VAR(uint16, AUTOMATIC, DCM_VAR)currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType,
    AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}


/* !LINKSTO Dcm.ConditionCheckRead.AsyncFnc,1 */
FUNC(Std_ReturnType, DCM_APPL_CODE) ReadDIDDataCondition0(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.ReadDataLength.FncInterface,1 */
/* !LINKSTO SWS_Dcm_00796,1 */
FUNC(Std_ReturnType, DCM_APPL_CODE) ReadDIDDataLength0(
    P2VAR(uint16, AUTOMATIC, DCM_VAR) DataLength)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/* !LINKSTO Dcm.ReadData.AsyncFnc,1 */
FUNC(Std_ReturnType, DCM_APPL_CODE) ReadDIDData0(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

FUNC(Std_ReturnType, DCM_APPL_CODE) Dcm_DID_0xf1AA_Readout( Dcm_OpStatusType OpStatus,  P2VAR(uint8, AUTOMATIC, DCM_VAR) Data)
{

	*Data = 0xEB;
  Std_ReturnType retval = E_OK;

  return retval;
  
}

/* !LINKSTO Dcm.WriteData.DcmDspDataFixedLength.True.AsyncFnc,1 */
FUNC(Std_ReturnType, DCM_APPL_CODE) WriteDIDData0(
    P2CONST(uint8, AUTOMATIC, DCM_CONST) Data,
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

FUNC(Std_ReturnType, DCM_APPL_CODE) ReadDID_ECUName(P2VAR(uint8, AUTOMATIC, DCM_VAR) Data)
{
uint8 Data_Dummy[2] = {0x11, 0x22};
*Data = Data_Dummy[0];
Data++;
*Data = Data_Dummy[1];
return E_OK;
}

FUNC(Std_ReturnType, DCM_APPL_CODE) ReadDID_NodeAddre(P2VAR(uint8, AUTOMATIC, DCM_VAR) Data)
{
uint8 Data_Dummy[2] = {0x33, 0x44};
*Data = Data_Dummy[0];
Data++;
*Data = Data_Dummy[1];
return E_OK;
}
uint8 DID_0x102;
FUNC(Std_ReturnType, DCM_APPL_CODE) ReadDID_DataRecor_1(P2VAR(uint8, AUTOMATIC, DCM_VAR) Data)
{
*Data = DID_0x102;
return E_OK;
}

uint8 DID_0xF189;
FUNC(Std_ReturnType, DCM_APPL_CODE) ReadDID_DataRecor_2(P2VAR(uint8, AUTOMATIC, DCM_VAR) Data)
{
*Data = DID_0xF189;
return E_OK;
}

FUNC(Std_ReturnType, DCM_APPL_CODE) WriteDID_DataRecor_1(P2VAR(uint8, AUTOMATIC, DCM_VAR) Data)
{
	DID_0x102 = *Data;
	if(DID_0x102 = 1)
	{
		Rte_Call_ASR42_Event_DTC_0x10000d_Event_SetEventStatus(0);
	}
return E_OK;
}
 /** \brief Manfacturer notification function
 **
 ** The purpose of this functionality is that, just after receiving the diagnostic request, the
 ** Manufacturer Application is requested to check permission/environment.
 ** E.g. in after-run ECU state, it might be not allowed to process OBD requests.
 **
 ** \param Sid           : Value of service identifier
 ** \param RequestData   : This parameter contains the complete request data (diagnostic buffer),
 **                        except the service ID.
 ** \param DataSize      : This parameter defines how many bytes in the RequestData
 **                        parameter are valid
 ** \param ReqType       : Addressing type of the request(0=physical request
                           1=functional request)
 ** \param SourceAddress : Tester source address configured per protocol
 ** \param ErrorCode     : Error code set from application
 **
 ** \return Result of comparision:
 **         - ::E_OK: Operation successful
 **         - ::E_NOT_OK: Operation not successful
 **         - ::DCM_E_REQUEST_NOT_ACCEPTED: Request not accepted
 **/   
FUNC(Std_ReturnType, DCM_APPL_CODE) Rte_DcmManufacturerNotification(
    uint8 Sid,
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) RequestData,
    uint16 DataSize,
    uint8 ReqType,
    uint16 SourceAddress,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

/** \brief Supplier notification function
 **
 ** The purpose of this functionality is that, right before processing the diagnostic
 ** message, the Supplier Application is requested to check permission/environment.
 ** E.g. in after-run ECU state, it might be not allowed to process OBD requests.
 **
 ** \param Sid           : Value of service identifier
 ** \param RequestData   : This parameter contains the complete request data (diagnostic buffer),
 **                        except the service ID.
 ** \param DataSize      : This parameter defines how many bytes in the RequestData
 **                        parameter are valid
 ** \param ReqType       : Addressing type of the request(0=physical request
                           1=functional request)
 ** \param SourceAddress : Tester source address configured per protocol
 ** \param ErrorCode     : Error code set from application
 **
 ** \return Result of comparision:
 **         - ::E_OK: Operation successful
 **         - ::E_NOT_OK: Operation not successful
 **         - ::DCM_E_REQUEST_NOT_ACCEPTED: Request not accepted
 **/
FUNC(Std_ReturnType, DCM_APPL_CODE) Rte_DcmSupplierNotification(
    uint8 Sid,
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) RequestData,
    uint16 DataSize,
    uint8 ReqType,
    uint16 SourceAddress,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
  Std_ReturnType retval = E_OK;

  return retval;
}

 FUNC(Std_ReturnType, DCM_APPL_CODE) Dcm_ON_DTC_StatusCahnge( Dcm_OpStatusType OpStatus, P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext)
  {
    Std_ReturnType retval = E_OK;
    return retval;
  }


#define DCM_STOP_SEC_CALLOUT_CODE
#include <MemMap.h>

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/** @} doxygen end group definition */
/*==================[end of file]============================================*/
