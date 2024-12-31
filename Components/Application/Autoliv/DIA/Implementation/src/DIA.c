/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

 *******************************************************************************
C-File Template Version: 
Template version: AEM_PROCESS_1.25.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2022-09
 ******************************************************************************/
/**
 *    $Revision: 1.1.12.24 $
 *    $ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/DIA/Implementation/src/project.pj $
 */

/******************************************************************************

details
   This file is intended to handle DiagOnCAN services.

 ******************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "Rte_DIA.h"
#include "DIA.h"
#include "Dcm.h"
/******************************************************************************
MODULE DEFINES
 ******************************************************************************/
/**
 * \brief
 *    Supported block length
 */
#define KU16_DIA_SUPPORTED_BLOCK_LENGTH   ((uint16) 0x0006)
/******************************************************************************
MODULE TYPES
 ******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
 ******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
 ******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
 ******************************************************************************/
#define DIA_START_SEC_VAR_INIT_8
#include "DIA_MemMap.h"

/**
 * \brief
 *    Variable used to check the writing status for NVM Block.
 * \initialization
 *    NVM_REQ_NOT_OK
 * \range
 *    NVM_REQ_OK
 *    NVM_REQ_NOT_OK
 *    NVM_REQ_PENDING;
 */
EXPORTED uint8 DIA_u8ManageNVPBlockWritingStatus = NVM_REQ_NOT_OK;

#define DIA_STOP_SEC_VAR_INIT_8
#include "DIA_MemMap.h"
/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
 ******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
 ******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
 ******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
 ******************************************************************************/

/******************************************************************************
DEFINITION OF APIs
 ******************************************************************************/
#define DIA_START_SEC_CODE
#include "DIA_MemMap.h"


/**
 * \brief
 *       Generic function used to copy the RAM mirror to the DiagOnCAN buffer.
 * \inputparam
 *       Name: kpku8Source;
 *       Type: const uint8* const;
 *       Description: Address from which the reading will be done;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: ku16DataLenght;
 *       Type: const uint16;
 *       Description: Number of data to be read;
 *       Range: 0..KU16_MAX;
 * \outputparam
 *       Name: pku8Destination;
 *       Type: uint8* const;
 *       Description: Address where data will be stored;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       This function has no return.
 * \dynamicaspectcaller
 *       Called by ReadDataByIdentifier functions.
 * \dynamicaspectdescription
 *       Functions used to read data by 22 service.
 * \ddesignrequirement
 *		   DSG_DIA_CopyData
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FD00_HWVersion_ReadData
 *       ARCH_SW_DIA_pseDID_FD01_SWVersion
 *       ARCH_SW_DIA_pseDID_FDFF_MeasurementFrameRamConf_ReadData
 *       ARCH_SW_DIA_pseDID_FEFF_MeasurementFramesConf_ReadData
 *       ARCH_SW_DIA_pseDID_FD03_AEETraceabilityNumber
 *       ARCH_SW_DIA_pseDID_FD8B_ECUManufacturingDate
 *       ARCH_SW_DIA_pseDID_FD8C_AssemblySerialNumber_ReadData
 *       ARCH_SW_DIA_pseDID_FDE1_EcsParameters_ReadData
 *       ARCH_SW_DIA_pseDID_FDE3_EcsProfiles_ReadData
 *       ARCH_SW_DIA_pseDID_FDE4_EcsSteps_ReadData
 *       ARCH_SW_DIA_pseDID_FDE5_EcsAccLowPass_ReadData
 *       ARCH_SW_DIA_pseDID_F187_VWSparePartNumber_ReadData
 *       ARCH_SW_DIA_pseDID_F189_VWApplicationSoftwareVersionNumber_ReadData
 *       ARCH_SW_DIA_pseDID_F191_VWECUHardwareNumber_ReadData
 *       ARCH_SW_DIA_pseDID_F197_VWSystemNameOrEngineType_ReadData
 *       ARCH_SW_DIA_pseDID_F1A2_ASAMODXFileVersion_ReadData
 *       ARCH_SW_DIA_pseDID_F1A3_VWECUHardwareVersionNumber_ReadData
 *       ARCH_SW_DIA_pseDID_F18C_ECUSerialNumberData_ReadData
 *       ARCH_SW_DIA_pseDID_F1AB_VWLogicalSoftwareBlockVersion
 *       ARCH_SW_DIA_pseDID_F19E_ASAMODXFileIdentifier_ReadData
 *       ARCH_SW_DIA_pseDID_FD00_HWVersion_WriteData
 *       ARCH_SW_DIA_pseDID_F18C_AssemblySerialNumber_WriteData
 *       ARCH_SW_DIA_pseDID_FDE3_EcsProfiles_WriteData
 *       ARCH_SW_DIA_pseDID_FDE4_EcsSteps_WriteData
 *       ARCH_SW_DIA_pseDID_F187_VWSparePartNumber_WriteData
 *       ARCH_SW_DIA_pseDID_F189_VWApplicationSoftwareVersionNumber_WriteData
 *       ARCH_SW_DIA_pseDID_F191_VWECUHardwareNumber_WriteData
 *       ARCH_SW_DIA_pseDID_FDEA_EcsSensitivityOpt_WriteData
 *       ARCH_SW_DIA_pseDID_F197_VWSystemNameOrEngineType_WriteData
 *       ARCH_SW_DIA_pseDID_F18C_ECUSerialNumberData_WriteData
 *       ARCH_SW_DIA_pseDID_F1A3_VWECUHardwareVersionNumber_WriteData
 **/
EXPORTED void DIA_CopyData(uint8* const pku8Destination, const uint8* const kpku8Source, const uint16 ku16DataLength)
{
   uint16 u16Index;

   for (u16Index = KU16_ZERO; u16Index < ku16DataLength; u16Index++)
   {
      *(pku8Destination + u16Index) = *(kpku8Source + u16Index);
   }
}

/**
 * \brief
 *       Generic function used to copy the RAM mirror to the DiagOnCAN buffer,
 *       used for u16 data.
 * \inputparam
 *       Name: kpku8Source;
 *       Type: const uint8* const;
 *       Description: Address from which the reading will be done;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: ku16DataLenght;
 *       Type: const uint16;
 *       Description: Number of data to be read;
 *       Range: 0..KU16_MAX;
 * \outputparam
 *       Name: pku8Destination;
 *       Type: uint8* const;
 *       Description: Address where data will be stored;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       This function has no return.
 * \dynamicaspectcaller
 *       Called by ReadDataByIdentifier functions.
 * \dynamicaspectdescription
 *       Functions used to read data by 22 service.
 * \ddesignrequirement
 *       DSG_DIA_CopyDataSwap
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDE9_EcsSensitivityLut_WriteData
 *       ARCH_SW_DIA_pseDID_FDE9_EcsSensitivityLut_ReadData
 *       ARCH_SW_DIA_pseDID_FD0F_BatteryMeasure
 *       ARCH_SW_DIA_pseDID_FD10_MCUTemperature
 *       ARCH_SW_DIA_pseDID_FDE1_EcsParameters_ReadData
 *       ARCH_SW_DIA_pseDID_FDE2_EcsAccOffsets_ReadData
 *       ARCH_SW_DIA_pseDID_FDE7_EcsAlgoOutputDelay_ReadData
 *       ARCH_SW_DIA_pseDID_FDE9_EcsSensitivityLut_ReadData
 **/
EXPORTED void DIA_CopyDataSwap(uint8* const pku8Destination, const uint8* const kpku8Source, const uint16 ku16DataLength)
{
   uint16 u16Index;

   for (u16Index = KU16_ZERO; u16Index < ku16DataLength; u16Index+=KU16_TWO)
   {
      /* Swap little Indian to big Indian for u16 data */
      *(pku8Destination + u16Index) = *(kpku8Source + u16Index + KU8_ONE);
      *(pku8Destination + u16Index + KU8_ONE) = *(kpku8Source + u16Index);
   }
}
/**
 * \brief
 *       Generic function used to copy the RAM mirror to the DiagOnCAN buffer,
 *       used for u32 data.
 * \inputparam
 *       Name: kpku8Source;
 *       Type: const uint8* const;
 *       Description: Address from which the reading will be done;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: ku16DataLenght;
 *       Type: const uint16;
 *       Description: Number of data to be read;
 *       Range: 0..KU16_MAX;
 * \outputparam
 *       Name: pku8Destination;
 *       Type: uint8* const;
 *       Description: Address where data will be stored;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       This function has no return.
 * \dynamicaspectcaller
 *       Called by ReadDataByIdentifier functions.
 * \dynamicaspectdescription
 *       Functions used to read data by 22 service.
 * \ddesignrequirement
 *       DSG_DIA_CopyDataSwap32
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDFF_MeasurementFrameRamConf_ReadData
 *
 **/
EXPORTED void DIA_CopyDataSwap32(uint8* const pku8Destination, const uint8* const kpku8Source, const uint16 ku16DataLength)
{
   uint16 u16Index;

   for (u16Index = KU16_ZERO; u16Index < ku16DataLength; u16Index+=KU8_FOUR)
   {
      /* Swap little Indian to big Indian for u32 data */
      *(pku8Destination + u16Index) = *(kpku8Source + u16Index + KU8_THREE);
      *(pku8Destination + u16Index + KU8_ONE) = *(kpku8Source + u16Index + KU8_TWO);
      *(pku8Destination + u16Index + KU8_TWO) = *(kpku8Source + u16Index + KU8_ONE);
      *(pku8Destination + u16Index + KU8_THREE) = *(kpku8Source + u16Index);
   }
}
/**
 * \brief
 *       DIA component initialization function.
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       This function has no return.
 * \dynamicaspectcaller
 *       BswM_OnStartComEffective
 * \dynamicaspectdescription
 *       Callout to start RTE and authorize communication.
 * \ddesignrequirement
 *       DSG_DIA_Init
 * \archrequirement
 *       ARCH_SW_BswMIf_ptrpAsrBswMServicesBswMIf_BswM_OnStartComEffective
 *       ARCH_SW_Dia_ptrpDiaServicesBswMIf_DIA_Init
 **/
EXPORTED void DIA_Init(void)
{
   /* Initialize the Security Access parameters */
   DIA_SecurityAccess_Init();
}


/**
 * \brief
 *       Function used to manage the writing in non volatile memory.
 * \inputparam
 *       Name: u16BlockID;
 *       Type: NvM_ASR42_BlockIdType (uint16);
 *       Description: The block id to write;
 *       Range: 0..KU16_MAX;
 * \inputparam
 *       Name: kpu8Data;
 *       Type: const uint8*;
 *       Description: Data to write;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Status of NVP Block Writing.
 * \constrains
 *       NVP Block Writing status can be:
 *          o NVM_REQ_PENDING;
 *          o NVM_REQ_OK;
 *          o NVM_REQ_NOT_OK;
 * \dynamicaspectcaller
 *       Called by WriteDataByIdentifier functions.
 * \dynamicaspectdescription
 *       Functions used to write NVP block by 2E service.
 * \ddesignrequirement
 *		   DSG_DIA_ManageNVPBlockWriting
 * \archrequirement
 *       ARCH_SW_DIA_pclNvmIfServices_WriteNvmBlock
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockStatus
 *       ARCH_SW_DIA_pseRoutineControl_LockUnlockECU_Start
 *       ARCH_SW_DIA_pseRoutineControl_LockUnlockECU_Stop
 *       ARCH_SW_DIA_pseRoutineControl_ProcessMode_Start
 *       ARCH_SW_DIA_pseRoutineControl_ProcessMode_Stop
 *       ARCH_SW_DIA_pseRoutineControl_AccCalib
 *       ARCH_SW_DIA_pseRoutineControl_AccAngleOffsetCalibration
 *       ARCH_SW_DIA_pseDID_FD00_HWVersion_WriteData
 *       ARCH_SW_DIA_pseDID_FDFF_MeasurementFrameRamConf_WriteData
 *       ARCH_SW_DIA_pseDID_FEFF_MeasurementFramesConf_WriteData
 *       ARCH_SW_DIA_pseDID_FD8C_AssemblySerialNumber_WriteData
 *       ARCH_SW_DIA_pseDID_FDE0_EcsVariant_WriteData
 *       ARCH_SW_DIA_pseDID_FDE1_EcsParameters_WriteData
 *       ARCH_SW_DIA_pseDID_FDE2_EcsAccOffsets_WriteData
 *       ARCH_SW_DIA_pseDID_FDE3_EcsProfiles_WriteData
 *       ARCH_SW_DIA_pseDID_FDE4_EcsSteps_WriteData
 *       ARCH_SW_DIA_pseDID_FDE5_EcsAccLowPass_WriteData
 *       ARCH_SW_DIA_pseDID_FDE7_EcsAlgoOutputDelay_WriteData
 *       ARCH_SW_DIA_pseDID_FDE9_EcsSensitivityLut_WriteData
 *       ARCH_SW_DIA_pseDID_FDEA_EcsSensitivityOpt_WriteData
 *       ARCH_SW_DIA_pseDID_F187_VWSparePartNumber_WriteData
 *       ARCH_SW_DIA_pseDID_F189_VWApplicationSoftwareVersionNumber_WriteData
 *       ARCH_SW_DIA_pseDID_F191_VWECUHardwareNumber_WriteData
 *       ARCH_SW_DIA_pseDID_F197_VWSystemNameOrEngineType_WriteData
 *       ARCH_SW_DIA_pseDID_F19E_ASAMODXFileIdentifier_WriteData
 *       ARCH_SW_DIA_pseDID_F1A2_ASAMODXFileVersion_WriteData
 *       ARCH_SW_DIA_pseDID_F18C_ECUSerialNumberData_WriteData
 *       ARCH_SW_DIA_pseDID_F1A3_VWECUHardwareVersionNumber_WriteData
 **/
EXPORTED uint8 DIA_ManageNVPBlockWriting(NvM_ASR42_BlockIdType u16BlockID, const uint8* kpu8Data)
{
   /* Variable used to get NVP services result */
   NvM_ASR42_RequestResultType stNvMRequestResult;

   if (NVM_REQ_PENDING != DIA_u8ManageNVPBlockWritingStatus)
   {
      /* Send request to Write NvM Block */
      (void)Rte_Call_pclNvmIfServices_WriteNvmBlock(u16BlockID, (NvM_SrcPtrType *)kpu8Data);

      DIA_u8ManageNVPBlockWritingStatus = NVM_REQ_PENDING;
   }
   else
   { /* A Read request is pending, just check if it is done */
      Rte_Call_pclNvmIfServices_GetNvmBlockStatus(u16BlockID, &stNvMRequestResult);

      if (NVM_REQ_PENDING == stNvMRequestResult)
      {
         DIA_u8ManageNVPBlockWritingStatus = NVM_REQ_PENDING;
      }
      else if (NVM_REQ_OK == stNvMRequestResult)
      {
         DIA_u8ManageNVPBlockWritingStatus = NVM_REQ_OK;
      }
      else
      {
         DIA_u8ManageNVPBlockWritingStatus = NVM_REQ_NOT_OK;
      }
   }
   return DIA_u8ManageNVPBlockWritingStatus;
}

/**
 * \brief
 *       Run the service request confirmation.
 * \inputparam
 *       Name: u8SID;
 *       Type: uint8;
 *       Description: Service Identifier;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: u8ReqType;
 *       Type: uint8;
 *       Description: Not used, automatically generated by Autosar;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: u16SourceAddress;
 *       Type: uint16;
 *       Description: Source address not used, automatically generated by Autosar;
 *       Range: 0..KU16_MAX;
 * \outputparam
 *       Name: ConfirmationStatus;
 *       Type: Dcm_ConfirmationStatusType(uint8);
 *       Description: Confirmation status;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Confirmation Status
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_ServiceRequestSupplierNotification_DcmDslServiceRequestSupplierNotification_Confirmation
 * \dynamicaspectdescription
 *       RTE function pointer table for Supplier Notification.
 * \ddesignrequirement
 *		   DSG_DIA_runServiceRequestConfirmation
 * \archrequirement
 *       ARCH_SW_DIA_pseServiceRequestSupplierNotification_Confirmation
 **/
EXPORTED Std_ReturnType DIA_runServiceRequestConfirmation (uint8 u8SID, uint8 u8ReqType, uint16 u16SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus)
{
   (void)u8SID; /* to avoid compiler warning */
   (void)u8ReqType; /* to avoid compiler warning */
   (void)u16SourceAddress; /* to avoid compiler warning */
   (void)ConfirmationStatus;

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Run the service request identification.
 * \inputparam
 *       Name: u8SID;
 *       Type: uint8;
 *       Description: Service Identifier;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: RequestData;
 *       Type: P2CONST(uint8);
 *       Description: ECU current session;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: DataSize;
 *       Type: uint16;
 *       Description: Data size;
 *       Range: 0..KU16_MAX;
 * \inputparam
 *       Name: u8ReqType;
 *       Type: uint8;
 *       Description: Not used, automatically generated by Autosar;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: u16SourceAddress;
 *       Type: uint16;
 *       Description:  Not used, automatically generated by Autosar;
 *       Range: 0..KU16_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR(uint8);
 *       Description: Not used, automatically generated by Autosar;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Error code
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_ServiceRequestSupplierNotification_DcmDslServiceRequestSupplierNotification_Indication
 * \dynamicaspectdescription
 *       RTE function pointer table for Supplier Notification.
 * \ddesignrequirement
 *		   DSG_DIA_runServiceRequestIndication
 * \archrequirement
 *       ARCH_SW_DIA_pseServiceRequestSupplierNotification_Indication
 **/
EXPORTED Std_ReturnType DIA_runServiceRequestIndication (uint8 u8SID, P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) RequestData, uint16 DataSize, uint8 u8ReqType, uint16 u16SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   (void)u8SID; /* to avoid compiler warning */
   (void)RequestData; /* to avoid compiler warning */
   (void)DataSize; /* to avoid compiler warning */
   (void)u8ReqType; /* to avoid compiler warning */
   (void)u16SourceAddress; /* to avoid compiler warning */
   (void)ErrorCode;

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Defines the names of the Require Ports the Dcm generates for the
 *       interface CallBackDCMRequestServices.
 *       The CallBackDCMRequestServices interface allows the Dcm to ask about
 *       prioritization of Diagnostic Protocols to the Application.
 *       The Application can further disallow to start a Diagnostic Protocol.
 *       The names of the containers in this list are used to define the name of
 *       the Require Ports generated to access the CallBackDCMRequestServices interface.
 *       The ports are named CallBackDCMRequestServices_<SWC> where <SWC> is
 *       the name of the container DcmDslCallbackDCMRequestService.
 * \inputparam
 *       Name: ProtocolID;
 *       Type: Dcm_ProtocolType(uint8);
 *       Description: Represents the protocol ID from the requested services;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       RTE_E_OK
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_CallBackDCMRequestServices_CBReqServInd_1_StartProtocol
 * \dynamicaspectdescription
 *       RTE function pointer table for DCM Request Services.
 * \ddesignrequirement
 *		   DSG_DIA_runCallBackDCMRequestServices_CBReqServInd_1_StartProtocol
 * \archrequirement
 *       ARCH_SW_DIA_pseCallBackDCMRequestServices_CBReqServInd_1
 **/
EXPORTED Std_ReturnType DIA_runCallBackDCMRequestServices_CBReqServInd_1_StartProtocol (Dcm_ProtocolType ProtocolID)
{
   (void)ProtocolID; /* to avoid compiler warning */

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Defines the names of the Require Ports the Dcm generates for the
 *       interface CallBackDCMRequestServices.
 *       The CallBackDCMRequestServices interface allows the Dcm to ask about
 *       prioritization of Diagnostic Protocols to the Application.
 *       The Application can further disallow to start a Diagnostic Protocol.
 *       The names of the containers in this list are used to define the name of
 *       the Require Ports generated to access the CallBackDCMRequestServices interface.
 *       The ports are named CallBackDCMRequestServices_<SWC> where <SWC> is
 *       the name of the container DcmDslCallbackDCMRequestService.
 * \inputparam
 *       Name: ProtocolID;
 *       Type: Dcm_ProtocolType(uint8);
 *       Description: Represents the protocol ID from the requested services;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       RTE_E_OK
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_CallBackDCMRequestServices_CBReqServInd_1_StopProtocol
 * \dynamicaspectdescription
 *       RTE function pointer table for DCM Request Services.
 * \ddesignrequirement
 *		   DSG_DIA_runRte_Call_Dcm_CallBackDCMRequestServices_CBReqServInd_1_StopProtocol
 * \archrequirement
 *       ARCH_SW_DIA_pseCallBackDCMRequestServices_CBReqServInd_1_Stop
 **/
EXPORTED Std_ReturnType DIA_runRte_Call_Dcm_CallBackDCMRequestServices_CBReqServInd_1_StopProtocol (Dcm_ProtocolType ProtocolID)
{
   /* suppress compiler warnings about unused arguments */
   (void)ProtocolID; /* to avoid compiler warning */

   return ((Std_ReturnType)RTE_E_OK);
}

#define DIA_STOP_SEC_CODE
#include "DIA_MemMap.h"
/*************************************************************************
 Evolution of the component

 created by : T. DEMIREL

 $Log: DIA.c  $
 Revision 1.1.12.24 2023/07/14 14:18:56CEST Andreea Suiu (andreea.suiu) 
 add traceability
 Revision 1.1.12.23 2023/07/11 16:59:56EEST Andreea Suiu (andreea.suiu) 
 update comments, update 0236 write
 Revision 1.1.12.22 2023/06/22 14:07:14EEST Andreea Suiu (andreea.suiu) 
 update src files (fix findings) after review
 Revision 1.1.12.21 2023/06/21 16:18:30EEST Andreea Suiu (andreea.suiu) 
 change 0236 size to 62 bytes (did + data content)
 Revision 1.1.12.20 2023/06/12 09:16:26EEST Mihai Motoc (mihai.motoc) 
 Doxygen comments updates
 Revision 1.1.12.19 2023/06/08 09:29:49EEST Mihai Motoc (mihai.motoc) 
 Doxygen comments updates
 Revision 1.1.12.18 2023/04/25 09:13:03EEST Andreea Suiu (andreea.suiu) 
 Fix DIA after review
 Revision 1.1.12.17 2023/04/18 18:22:01EEST Andreea Suiu (andreea.suiu) 
 Update DIA module according to the coding rules
 Revision 1.1.12.16 2023/04/18 18:08:07EEST Andreea Suiu (andreea.suiu) 
 Update DIA module according to the coding rules
 Revision 1.1.12.15 2023/04/03 11:11:04EEST Gabriel Brasoveanu (gabriel.brasoveanu) 
 Update block 3 implementation
 Revision 1.1.12.14 2023/03/20 15:15:27EET David Puscasu (david.puscasu) 
 Add Architecture requirements on local functions
 Revision 1.1.12.13 2023/02/28 18:06:43EET Septimiu Vintila (septimiu.vintila) 
 FuSa section reverted to normal one.
 Revision 1.1.12.12 2023/02/28 17:15:02EET Septimiu Vintila (septimiu.vintila) 
 Data sections changed to FuSa data sections.
 Revision 1.1.12.11 2023/02/28 16:35:52EET Septimiu Vintila (septimiu.vintila) 
 Code sections changed to FuSa code sections.
 Revision 1.1.12.10 2023/02/24 13:58:54EET Andreea Suiu (andreea.suiu) 
 Update DIA after QAC
 Revision 1.1.12.9 2023/02/16 14:27:20EET Andreea Suiu (andreea.suiu) 
 Update Dcm and Dia module according to the coding rules
 Revision 1.1.12.8 2023/02/16 09:16:04EET Andreea Suiu (andreea.suiu) 
 Update Dcm and DIA module (programming response fixed, incorrect transition between session fixed)
 Revision 1.1.12.7 2023/01/30 09:05:27EET Dan Dustinta (dan.dustinta) 
 update RAM_NO_INIT section
 Revision 1.1.12.6 2023/01/23 16:10:26EET Denis Folea (denis.folea) 
 DIA fix after review
 Revision 1.1.12.5 2023/01/20 15:24:05EET Denis Folea (denis.folea) 
 DIA fix after review
 Revision 1.1.12.4 2022/12/22 16:28:53EET Andrei Anca (andrei.anca) 
 Dia cleanup
 Revision 1.1.12.3 2022/11/25 12:47:56EET Dan Dustinta (dan.dustinta) 
 update DCM integration code
 Revision 1.5 2014/05/26 14:38:39CEST Temel Demirel (tdemirel) 
 Adding logs tags to allow PTC to include the Evolution of the component at checking time

 *************************************************************************/

/******************************************************************************
End Of File
 *****************************************************************************/
