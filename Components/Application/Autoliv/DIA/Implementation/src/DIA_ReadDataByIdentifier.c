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
 *    $Revision: 1.4.2.48 $
 *    $ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/DIA/Implementation/src/project.pj $
 */

/******************************************************************************

details
	This file is intended to handle Read Data By Identifier services.

 ******************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "Rte_DIA.h"
#include "DIA.h"
#include "Dem_Cfg.h"
/******************************************************************************
MODULE DEFINES
 ******************************************************************************/
/**
 * \brief
 *    Offset of event ID
 */
#define KU16_DIA_EVT_ID_OFFSET                                    ((uint16)0x08)
/**
 * \brief
 *    Offset of event status
 */
#define KU16_DIA_EVT_STATUS_OFFSET                                ((uint16)0x01)
/**
 * \brief
 *    Index of event start
 */
#define KU16_DIA_EVT_START_INDEX                                  ((uint16)0x01)
/**
 * \brief
 *    Definition of the SW version length
 */
#define KU8_DIA_SW_VERSION_LENGTH                                 ((uint8)12)
/**
 * \brief
 *    VW SW version number buffer size
 */
#define KU8_DIA_TECHNICAL_SPEC_SIZE                                ((uint8)26)
/**
 * \brief
 *    Number of programming preconditions
 */
#define KU8_DIA_NB_PRECONDITIONS                                   ((uint8)4)
/**
 * \brief
 *    Ecu programmable and consistent value
 */
#define KU8_DIA_ECU_PROGRAMABLE_AND_CONSISTENT                     ((uint8)0x40)
/**
 * \brief
 *    SW ASAM ODX File Identifier buffer size
 */
#define KU8_DIA_FDS_ID_HIGH                                        ((uint8)0x08)
/**
 * \brief
 *    SW ASAM ODX File Identifier buffer size
 */
#define KU8_DIA_FDS_ID_LOW                                         ((uint8)0x6B)
/**
 * \brief
 *    Fingerprint And Programming Date Of Logical Software Blocks buffer size
 */
#define KU8_DIA_FINGERPRINT_AND_PROGRAMMING_DATE_SIZE                ((uint8)30)
/**
 * \brief
 *    Fingerprint And Programming Date Of Logical Software Blocks buffer size
 */
#define KU8_DIA_TWENTYNINE                                           ((uint8)29)
/**
 * \brief
 *    Lock timing programming active condition
 */
#define KU8_DIA_LOCK_TIME_PROGRAMMNG_ACTIVE                        ((uint8)0x81)
/**
 * \brief
 *    Crash counter condition
 */
#define KU8_DIA_CRASH_COUNTER                                      ((uint8)0x85)
/**
 * \brief
 *    Crash counter condition
 */
#define KU8_DIA_FD03_SIZE                                          ((uint8)0x0C)
/**
 * \brief
 *    DID 0236 maximum size
 */
#define KU8_DIA_0236_SIZE                                           ((uint8) 59)
/*****************************************************************************
MODULE TYPES
 ******************************************************************************/
/**
 * \brief
 *    NVM Ecu Data struct
 */
typedef struct
{
   uint8 u8ECUProgInfo;                               /* Represent the application coherency */
   uint8 au8Random[KU8_FOUR];                         /* Last random value use for security access */
   uint8 u8AsRetryCnt;                                /* Counter of failed security access error   */
} Dia_stNVMEcuDataType;
/**
 * \brief
 *    NVM Segment list struct
 */
typedef struct
{
   uint32 au32SegProgSize[KU8_FIVE];
   uint8  u8NbSegNbr;
} Dia_stSegmentListType;
/**
 * \brief
 *    NVM Block Data struct
 */
typedef struct
{
   Dia_stSegmentListType stSegmentList;        /* List of segment flashed during last block reprogramming */
   uint16 u16ProgCounter;                      /* Programming counter of the block */
   uint8 u8StatusInformation;
   uint8 au8FingerPrintInfo[KU8_NINE];         /* Finger print of the block */
} Dia_stNVMBlockDataType;
/**
 * \brief
 *    NVM Bootloader Data struct
 */
typedef struct
{
   uint32 u32InitPattern;
   Dia_stNVMBlockDataType stNVMBlockData[KU8_THREE];
   Dia_stNVMEcuDataType stNVMEcuData;
} Dia_stNVMBootloaderDataType;
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
 *    Bootloader Tp size
 * \initialization
 *    KU8_ZERO (0)
 * \range
 *    0..KU8_MAX
 */
EXPORTED uint8 DIA_u8BootTpSize = KU8_ZERO;

#define DIA_STOP_SEC_VAR_INIT_8
#include "DIA_MemMap.h"

/**
 * \brief
 *    Aee Traceability Nb. Flash Address
 */
extern uint32 __Flash_AEE_TRACEABILITY_ADDR;
/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
 ******************************************************************************/
#define DIA_START_SEC_CONST_8
#include "DIA_MemMap.h"

/**
 * \brief
 *    Set the SW version.
 * \initialization
 *    XXXXXXXX.XXX
 */
LOCAL const uint8 dia_kau8SWVersion[KU8_DIA_SW_VERSION_LENGTH] = "XXXXXXXX.XXX";
/**
 * \brief
 *    Technical Specifications version.
 * \initialization
 *    0x00, 0x00, 0x02, 0x07, 0x05, 0x07, 0x02, 0x07, 0x05, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
 * \range
 *    0..KU8_MAX
 */
LOCAL const uint8 dia_kau8TechnicalSpec[KU8_DIA_TECHNICAL_SPEC_SIZE] = {0x00u, 0x00u, 0x02u, 0x07u, 0x05u, 0x07u, 0x02u, 0x07u, 0x05u, 0x07u, 0x03u, 0x01u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u};

#define DIA_STOP_SEC_CONST_8
#include "DIA_MemMap.h"
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
 *       Read Hardware Version Number.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: pu8Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FD00_HWVersionData_ReadData
 * \dynamicaspectdescription
 *       Read Hardware Version Number.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidFD00_HWVersionRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FD00_HWVersion_ReadData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidFD00_HWVersionRead(Dcm_OpStatusType OpStatus, uint8 * pu8Data)
{
   uint16 u16DataLength = KU16_ZERO;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_HW_PART_NUMBER, &u16DataLength);

   /* Length is valid, then read all data bytes */
   DIA_CopyData ((uint8 *)pu8Data, (uint8 *)&NVP_au8HWPartNumber, u16DataLength);

   return ((Std_ReturnType)RTE_E_OK);

}

/**
 * \brief
 *       Function used to read the SW version.
 * \outputparam
 *       Name: pu8Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FD01_SWVersionData_ReadData
 * \dynamicaspectdescription
 *       Function used to read the SW version.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidFD01_SWVersionRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FD01_SWVersion
 **/
EXPORTED Std_ReturnType DIA_runDidFD01_SWVersionRead(uint8 * pu8Data)
{
   uint16 u16Length;

   /* Read SW Version Date data length */
   u16Length = ((uint16)KU8_DIA_SW_VERSION_LENGTH);

   /* Read all data bytes */
   DIA_CopyData (pu8Data, dia_kau8SWVersion, u16Length);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read Measurement Frames RAM parameters.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: pu8Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDFF_MeasurementFrameConfDataRam_ReadData
 * \dynamicaspectdescription
 *       Read Measurement Frames RAM parameters.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidFDFF_MeasurementFrameRamConfRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDFF_MeasurementFrameRamConf_ReadData
 *
 **/
EXPORTED Std_ReturnType DIA_runDidFDFF_MeasurementFrameRamConfRead(Dcm_OpStatusType OpStatus, uint8 * pu8Data)
{
   /* Length is valid, then read all uint32 data bytes */
   DIA_CopyDataSwap32(pu8Data, (uint8*)&NVP_au32RequestedRamAddressArray[KU8_ZERO], KU8_DIA_OFFSET_REQUESTED_RAM_SIZE_ARRAY);

   /* Read all uint8 data bytes*/
   DIA_CopyData(pu8Data + KU8_DIA_OFFSET_REQUESTED_RAM_SIZE_ARRAY, (uint8*)&NVP_au8RequestedRamSizeArray[KU8_ZERO], KU8_FIFTEEN);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read Measurement Frames parameters.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: pu8Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FEFF_MeasurementFramesConfData_ReadData
 * \dynamicaspectdescription
 *       Read Measurement Frames parameters.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidFEFF_MeasurementFramesConfRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FEFF_MeasurementFramesConf_ReadData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidFEFF_MeasurementFramesConfRead(Dcm_OpStatusType OpStatus, uint8 * pu8Data)
{
   uint16 u16Length;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_MEASUREMENT_FRAME_CONFIG, &u16Length);

   /* Length is valid, then read all data bytes */
   DIA_CopyData(pu8Data, (uint8*)&NVP_u8EnableDevFrame, u16Length);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read the time of system has been on.
 * \outputparam
 *       Name: pu8Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_4024_SWSystemTimeData_ReadData
 * \dynamicaspectdescription
 *       Read system time.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDid4024_SWSystemTimeRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_4024_SWSystemTime
 *       ARCH_SW_DIA_pclSystemTime_ReadAbsoluteSystemTime
 **/
EXPORTED Std_ReturnType DIA_runDid4024_SWSystemTimeRead(uint8 * pu8Data)
{
   /*Variable used to store the System Time.*/
   stAbsoluteSystemTimeType stSystemTimeValues;

   /*Rte call to the get the Absolute System Time*/
   Rte_Call_pclSystemTime_ReadAbsoluteSystemTime(&stSystemTimeValues);

   /* Correct behavior increment index after use */
   *(pu8Data + (KU8_ZERO)) = U32_GET_HIGH_BYTE(stSystemTimeValues.u32SystemTimeInSec);
   /* Correct behavior increment index after use */
   *(pu8Data + (KU8_ONE)) = U32_GET_HIGH_MIDDLE_BYTE(stSystemTimeValues.u32SystemTimeInSec);
   /* Correct behavior increment index after use */
   *(pu8Data + (KU8_TWO)) = U32_GET_LOW_MIDDLE_BYTE(stSystemTimeValues.u32SystemTimeInSec);
   /* Correct behavior increment index after use */
   *(pu8Data + (KU8_THREE)) = U32_GET_LOW_BYTE(stSystemTimeValues.u32SystemTimeInSec);
   /* Last byte is reserved */
   *(pu8Data + (KU8_FOUR)) = KU8_MAX;

   return ((Std_ReturnType)RTE_E_OK);
}


/**
 * \brief
 *       Read AEE Traceability Number.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: pu8Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FD03_AEETraceabilityNumberData_ReadData
 * \dynamicaspectdescription
 *       Read AEE Traceability Number.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidFD03_AEETraceabilityNumberRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FD03_AEETraceabilityNumberRead
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidFD03_AEETraceabilityNumberRead(Dcm_OpStatusType OpStatus, uint8 * pu8Data)
{
   uint16 u16Length;
   uint8 u8Index;
   boolean bFound = B_FALSE;

   for(u8Index = KU8_ZERO; ((u8Index < KU8_DIA_FD03_SIZE) && (bFound == B_FALSE)); u8Index++)
   {
      if(KU8_MAX != ((uint8*)&__Flash_AEE_TRACEABILITY_ADDR)[u8Index])
      {
         bFound = B_TRUE;
      }
   }

   if(B_TRUE == bFound)
   {
      DIA_CopyData(pu8Data, (uint8*)&__Flash_AEE_TRACEABILITY_ADDR, KU8_DIA_FD03_SIZE);
   }
   else
   {
      /* Read data block length */
      Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_AEE_TRACEABILITY_NUMBER, &u16Length);

      /* Length is valid, then read all data bytes */
      DIA_CopyData(pu8Data, &NVP_au8AEE_TRACEABILITY_NUM[KU8_ZERO], u16Length);
   }

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read Ecu Manufacturing Date.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: pu8Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F18B_ECUManufacturingDateData_ReadData
 * \dynamicaspectdescription
 *       Read Ecu Manufacturing Date.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidF18B_ECUManufacturingDateRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FD8B_ECUManufacturingDateRead
 **/
EXPORTED Std_ReturnType DIA_runDidFD8B_ECUManufacturingDateRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   uint16 u16Length;

   /* Compute data length */
   u16Length = sizeof(NVP_u8AssemblyManufacturingYear);
   u16Length += sizeof(NVP_u8AssemblyManufacturingMonth);
   u16Length += sizeof(NVP_u8AssemblyManufacturingDay);

   /* Length is valid, then read all data bytes */
   DIA_CopyData(Data, &NVP_u8AssemblyManufacturingYear, u16Length);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read ECU Assembly Serial Number.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: pu8Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F18C_AssemblySerialNumber_ReadData
 * \dynamicaspectdescription
 *       Read ECU Assembly Serial Number.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidF18C_AssemblySerialNumberRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FD8C_AssemblySerialNumber_ReadData
 **/
EXPORTED Std_ReturnType DIA_runDidFD8C_AssemblySerialNumberRead(Dcm_OpStatusType OpStatus, uint8 * pu8Data)
{
   uint16 u16Length;

   /* Length is valid, then read all data bytes */
   u16Length = sizeof(NVP_au8AssemblySerialNumber);

   /* Fill-in data in response buffer */
   DIA_CopyData(pu8Data, &NVP_au8AssemblySerialNumber[KU8_ZERO], u16Length);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read Last Warm Reset.
 *       RID returns a code for last warm reset and the number of warm resets recorded.
 * \outputparam
 *       Name: pu8Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FD09_LastWarmResetParamData_ReadData
 * \dynamicaspectdescription
 *       Read Last Warm Reset.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidFD09_LastWarmResetParamRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FD09_LastWarmResetParam
 **/
EXPORTED Std_ReturnType DIA_runDidFD09_LastWarmResetParamRead(uint8 * pu8Data)
{
   /* Concatenate the last reset cause stored and the number of warm reset since this service call */
   (*((uint32 *)pu8Data)) = U32_SWAP_BYTE_ORDER(NVP_u32WarmResetCause);
   (*((uint32*) (pu8Data + KU8_FOUR))) = U32_SWAP_BYTE_ORDER(NVP_u32WarmResetCounter);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read the number of ECCs
 * \outputparam
 *       Name: pu8Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FD62_EccOccurenceNbData_ReadData
 * \dynamicaspectdescription
 *       Read the number of ECCs.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidFD62_EccOccurenceNbRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FD62_EccOccurenceNb
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidFD62_EccOccurenceNbRead(uint8 * pu8Data)
{
   uint16 u16Length;

   /* Set response data length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ECC_COUNTERS, &u16Length);

   /* Cast done intentionally to copy the 32 bits data into the pu8Data with only one instruction */
   *((uint32*) pu8Data) = U32_SWAP_BYTE_ORDER(NVP_u32RAMECCOccurrenceNumber);
   /* Cast done intentionally to copy the 32 bits data into the pu8Data with only one instruction */
   *((uint32*) pu8Data + KU8_ONE) = U32_SWAP_BYTE_ORDER(NVP_u32DFLASHECCOccurrenceNumber);
   /* Cast done intentionally to copy the 32 bits data into the pu8Data with only one instruction */
   *((uint32*) pu8Data + KU8_TWO) = U32_SWAP_BYTE_ORDER(NVP_u32TFLASHECCOccurrenceNumber);
   /* Cast done intentionally to copy the 32 bits data into the pu8Data with only one instruction */
   *((uint32*) pu8Data + KU8_THREE) = U32_SWAP_BYTE_ORDER(NVP_u32PFLASHECCOccurrenceNumber);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read last reset cause.
 * \outputparam
 *       Name: pu8Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FD08_ResetCauseData_ReadData.
 * \dynamicaspectdescription
 *       Read last reset cause.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidFD08_ResetCauseRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FD08_ResetCause
 *       ARCH_SW_DIA_pclResetCause
 *       ARCH_SW_DIA_pclResetCauseNotification
 **/
EXPORTED Std_ReturnType DIA_runDidFD08_ResetCauseRead(uint8 * pu8Data)
{
   u32ResetCauseType u32WarmResetCause;

   /* get reset cause */
   Rte_Call_pclResetCause_GetResetCause(&u32WarmResetCause);

   /* Fill-in the response data bytes */
   pu8Data[KU8_ZERO] = U32_GET_HIGH_BYTE(u32WarmResetCause);
   pu8Data[KU8_ONE] = U32_GET_HIGH_MIDDLE_BYTE(u32WarmResetCause);
   pu8Data[KU8_TWO] = U32_GET_LOW_MIDDLE_BYTE(u32WarmResetCause);
   pu8Data[KU8_THREE] = U32_GET_LOW_BYTE(u32WarmResetCause);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read All Event statuses.
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FE00_AllEventStatusesRead_ReadData
 * \dynamicaspectdescription
 *       Read All Event statuses.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidFE00_AllEventStatusesRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FE00_AllEventStatusesRead
 *       ARCH_SW_DIA_pclDemServices_GetEventStatus
 *       ARCH_SW_DIA_pclDemServices_GetEventFailed
 **/
EXPORTED Std_ReturnType DIA_runDidFE00_AllEventStatusesRead (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   uint16 u16IndexEvent = KU16_DIA_EVT_START_INDEX;

   for(u16IndexEvent = KU16_DIA_EVT_START_INDEX; u16IndexEvent < DEM_NUMBER_OF_EVENTS; u16IndexEvent++)
   {
      *((uint16*) (Data + ((u16IndexEvent * KU16_THREE) - KU16_THREE))) = u16IndexEvent << KU16_DIA_EVT_ID_OFFSET;
      (void) Rte_Call_pclDemServices_GetEventStatus(u16IndexEvent, (Data + (u16IndexEvent * KU16_THREE) - KU16_DIA_EVT_STATUS_OFFSET));
   }

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Function used to read Battery Measure.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: pu8Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FD0F_BatteryMeasureData_ReadData
 * \dynamicaspectdescription
 *       Function used to read Battery Measure.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDid_FD0F_BatteryMeasureRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FD0F_BatteryMeasure
 *       ARCH_SW_DIA_pclConvAdcService
 **/
EXPORTED Std_ReturnType DIA_runDid_FD0F_BatteryMeasureRead(Dcm_OpStatusType OpStatus, uint8 * pu8Data)
{
   uint16 u16BatteryInput;

   /* get the Vbat in mili Volts */
   Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_V_BATT, &u16BatteryInput);

   /* Fill-in data in response buffer */
   DIA_CopyDataSwap(pu8Data, (uint8*)&u16BatteryInput, KU16_ONE);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Function used to read ECU Temperature Measure.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: pu8Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FD10_MCUTemperatureData_ReadDat
 * \dynamicaspectdescription
 *       Function used to read MCU Temperature Measure.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_run_DidFD10_ECUTemperatureRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FD10_MCUTemperature
 *       ARCH_SW_DIA_pclConvAdcService
 *       ARCH_SW_DIA_pclEcuCharacteristics
 *
 **/
EXPORTED Std_ReturnType DIA_run_DidFD10_ECUTemperatureRead(Dcm_OpStatusType OpStatus, uint8 * pu8Data)
{
   sint16 s16ECUTemperatureInput;

   /* get the MCU temperature */
   Rte_Call_pclEcuCharacterstics_GetTemperature(&s16ECUTemperatureInput);

   /* Fill-in data in response buffer */
   DIA_CopyDataSwap(pu8Data, (uint8*)&s16ECUTemperatureInput, KU16_ONE);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read the ECS variant.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDE0_EcsVariantData_ReadData
 * \dynamicaspectdescription
 *       Read the ECS variant.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidFDE0_EcsVariantRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDE0_EcsVariant_ReadData
 **/
EXPORTED Std_ReturnType DIA_runDidFDE0_EcsVariantRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   /* Fill-in data in response buffer */
   *(uint32*)Data = U32_SWAP_BYTE_ORDER(NVP_u32eCSVariant);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read all eCS algorithm parameters.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDE1_EcsParametersData_ReadData
 * \dynamicaspectdescription
 *       Read all eCS algorithm parameters.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidFDE1_EcsParametersRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDE1_EcsParameters_ReadData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidFDE1_EcsParametersRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   uint16 u16BlockSize;
   uint16 u16BlockSizeWithoutLastParam;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ECS_PARAMETERS, &u16BlockSize);

   /* Block size without uint8 data bytes */
   u16BlockSizeWithoutLastParam = u16BlockSize - KU16_ONE;

   /* Read all uint16 data bytes */
   DIA_CopyDataSwap(Data, (uint8 *)&NVP_au16Angle1_Idx[KU8_ZERO], u16BlockSizeWithoutLastParam);
   /* Read all uint8 data bytes */
   DIA_CopyData(Data + u16BlockSizeWithoutLastParam, (uint8 *)&NVP_u8CrashSample, sizeof(NVP_u8CrashSample));

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read accelerometer offsets (x/y/z).
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDE2_AccOffsetData_ReadData
 * \dynamicaspectdescription
 *       Read accelerometer offsets (x/y/z).
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidFDE2_EcsAccOffsetsRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDE2_EcsAccOffsets_ReadData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidFDE2_EcsAccOffsetsRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   uint16 u16BlockSize;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ECS_ACC_OFFSETS, &u16BlockSize);

   /* Fill-in data in response buffer */
   DIA_CopyDataSwap(Data, (uint8 *)&NVP_s16OffsetAx, u16BlockSize);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read ECS profiles configuration n * 12 bytes + 12 reserved bytes (n = 4).
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDE3_EcsProfilesData_ReadData
 * \dynamicaspectdescription
 *       Read ECS profiles configuration n * 12 bytes + 12 reserved bytes (n = 4).
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidFDE3_EcsProfilesRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDE3_EcsProfiles_ReadData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidFDE3_EcsProfilesRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   uint16 u16BlockSize;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ECS_PROFILES, &u16BlockSize);

   /* Fill-in data in response buffer */
   DIA_CopyData(Data, (uint8 *)&NVP_au8EcsProfile_0, u16BlockSize);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read ECS steps configuration n * 7 bytes (n = 8).
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDE4_EcsStepsData_ReadData
 * \dynamicaspectdescription
 *       Read ECS steps configuration n * 7 bytes (n = 8).
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidFDE4_EcsStepsRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDE4_EcsSteps_ReadData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidFDE4_EcsStepsRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   uint16 u16BlockSize;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ECS_STEPS, &u16BlockSize);

   /* Fill-in data in response buffer */
   DIA_CopyData(Data, (uint8 *)&NVP_au8Step_0, u16BlockSize);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read accelerometer lowpass filter value (x/y/z).
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDE5_EcsAccLowPassData_ReadData
 * \dynamicaspectdescription
 *       Read accelerometer lowpass filter value (x/y/z).
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidFDE5_EcsAccLowPassRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDE5_EcsAccLowPass_ReadData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidFDE5_EcsAccLowPassRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   uint16 u16BlockSize;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ECS_ACC_LOWPASS, &u16BlockSize);

   /* Fill-in data in response buffer */
   DIA_CopyData(Data, (uint8 *)&NVP_u8XaxisLowPass, u16BlockSize);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read algo output delay. 1 lsb = 1 ms.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDE7_AlgoOutputDelayData_ReadData
 * \dynamicaspectdescription
 *       Read algo output delay (1 lsb = 1 ms).
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDIDFDE7_EcsAlgoOutputDelayRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDE7_EcsAlgoOutputDelay_ReadData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDIDFDE7_EcsAlgoOutputDelayRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   uint16 u16BlockSize;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ECS_ALGO_OUTPUT_DELAY, &u16BlockSize);

   /* Fill-in data in response buffer */
   DIA_CopyDataSwap(Data, (uint8 *)&NVP_u16AlgoDelay, u16BlockSize);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read ECS Sensitivity Lut.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDE9_SensitivityLutData_ReadData
 * \dynamicaspectdescription
 *       Read ECS Sensitivity Lut.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidFDE9_EcsSensitivityLutRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDE9_EcsSensitivityLut_ReadData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidFDE9_EcsSensitivityLutRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   uint16 u16BlockSize;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ECS_SENSITIVITY_LUT, &u16BlockSize);

   /* Fill-in data in response buffer */
   DIA_CopyDataSwap(Data, (uint8 *)&NVP_au16SensitivityIdx[KU8_ZERO], u16BlockSize);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Read ECS Sensitivity Opt.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDEA_SensitivityOptData_ReadData
 * \dynamicaspectdescription
 *       Read ECS Sensitivity Opt.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidFDEA_EcsSensitivityOptRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDEA_EcsSensitivityOpt_ReadData
 **/
EXPORTED Std_ReturnType DIA_runDidFDEA_EcsSensitivityOptRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   /* Fill-in data in response buffer */
   *Data = NVP_b8SensitivityOpt;

   return ((Std_ReturnType)RTE_E_OK);
}
/**
 * \brief
 *       Function used to read the VW Spare Part Number.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F187_VWSparePartNumberData_ReadData
 * \dynamicaspectdescription
 *       Read VW Spare Part Number.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidF187_VWSparePartNumberRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F187_VWSparePartNumber_ReadData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidF187_VWSparePartNumberRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   uint16 u16BlockSize;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_SPARE_PART_NUMBER, &u16BlockSize);

   /* Fill-in data in response buffer */
   DIA_CopyData(Data, (uint8 *)&NVP_au8SparePartNumber, u16BlockSize);

   return ((Std_ReturnType)RTE_E_OK);
}
/**
 * \brief
 *       Function used to read the VW Application Software Number.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F189_VWApplicationSoftwareVersionNumberData_ReadData
 * \dynamicaspectdescription
 *       Read VW Application Software Number.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidF189_VWApplicationSoftwareVersionNumberRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F189_VWApplicationSoftwareVersionNumber_ReadData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidF189_VWApplicationSoftwareVersionNumberRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{

   uint16 u16BlockSize;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_APP_SOFTWARE_VERSION_NUMBER, &u16BlockSize);

   /* Fill-in data in response buffer */
   DIA_CopyData(Data, (uint8 *)&NVP_au8AppSwVersionNumber, u16BlockSize);

   return ((Std_ReturnType)RTE_E_OK);
}
/**
 * \brief
 *       Function used to read the VW ECU Hardware Number.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F191_VWECUHardwareNumberData_ReadData
 * \dynamicaspectdescription
 *       Read VW ECU Hardware Number.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidF191_VWECUHardwareNumberRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F191_VWECUHardwareNumber_ReadData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidF191_VWECUHardwareNumberRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   /*Used as index to parse UDS buffer and SW version no buffer*/
   uint16 u16BlockSize;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_HARDWARE_NUMBER, &u16BlockSize);

   /* Fill-in data in response buffer */
   DIA_CopyData(Data, (uint8 *)&NVP_au8HardwareNumber, u16BlockSize);

   return ((Std_ReturnType)RTE_E_OK);

}
/**
 * \brief
 *       Function used to read the VW System Name or Engine Type.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F197_VWSystemNameOrEngineTypeData_ReadData
 * \dynamicaspectdescription
 *       Read VW System Name or Engine Type.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidF197_VWSystemNameOrEngineTypeRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F197_VWSystemNameOrEngineType_ReadData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidF197_VWSystemNameOrEngineTypeRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   /*Used as index to parse UDS buffer and SW version no buffer*/
   uint16 u16BlockSize;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_SYSTEM_NAME_OR_ENGINE_TYPE, &u16BlockSize);

   /* Fill-in data in response buffer */
   DIA_CopyData(Data, (uint8 *)&NVP_au8SystemName, u16BlockSize);

   return ((Std_ReturnType)RTE_E_OK);

}
/**
 * \brief
 *       Function used to read the Technical Specification version.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F1B4_TechnicalSpecificationsVersionData_ReadData
 * \dynamicaspectdescription
 *       Read Technical Specification version.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidF1B4_TechnicalSpecificationsVersionRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F1B4_TechnicalSpecificationsVersion
 **/
EXPORTED Std_ReturnType DIA_runDidF1B4_TechnicalSpecificationsVersionRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   /* Used as index to parse UDS buffer and SW version no buffer */
   uint8 u8BufferIndex;

   /* Parse spare part number buffer and copy data to UDS data buffer */
   for(u8BufferIndex = KU8_ZERO; u8BufferIndex < KU8_DIA_TECHNICAL_SPEC_SIZE; u8BufferIndex++)
   {
      Data[u8BufferIndex] = dia_kau8TechnicalSpec[u8BufferIndex];
   }

   return ((Std_ReturnType)RTE_E_OK);
}
/**
 * \brief
 *       Function used to read the VW Logical Software Block Counter Of Programming Attempts.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_0407_VWLogicalSoftwareBlockCounterOfProgrammingAttemptsData_ReadData
 * \dynamicaspectdescription
 *       Read VW Logical Software Block Counter Of Programming Attempts.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDid0407_VWLogicalSoftwareBlockCounterOfProgrammingAttemptsRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_0407_VWLogicalSoftwareBlockCounterOfProgrammingAttempts
 **/
EXPORTED Std_ReturnType DIA_runDid0407_VWLogicalSoftwareBlockCounterOfProgrammingAttemptsRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   /* Fill-in data in response buffer */
   Data[KU8_ZERO]  = KU8_ZERO;
   Data[KU8_ONE]   = KU8_ONE;
   Data[KU8_TWO]   = (uint8)((((Dia_stNVMBootloaderDataType*) NVP_au8FBL)->stNVMBlockData[KU8_ONE].u16ProgCounter & KU16_MASK_BYTE_HIGH) >> KU8_EIGHT);
   Data[KU8_THREE] = (uint8)(((Dia_stNVMBootloaderDataType*) NVP_au8FBL)->stNVMBlockData[KU8_ONE].u16ProgCounter & KU16_MASK_BYTE_LOW);
   Data[KU8_FOUR]  = (uint8)((((Dia_stNVMBootloaderDataType*) NVP_au8FBL)->stNVMBlockData[KU8_TWO].u16ProgCounter & KU16_MASK_BYTE_HIGH) >> KU8_EIGHT);
   Data[KU8_FIVE]  = (uint8)(((Dia_stNVMBootloaderDataType*) NVP_au8FBL)->stNVMBlockData[KU8_TWO].u16ProgCounter & KU16_MASK_BYTE_LOW);

   return ((Std_ReturnType)RTE_E_OK);
}
/**
 * \brief
 *       Function used to read the VW Logical Software Block Lock Value.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_040F_VWLogicalSoftwareBlockLockValueData_ReadData
 * \dynamicaspectdescription
 *       Read VW Logical Software Block Lock Value.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDid040F_VWLogicalSoftwareBlockLockValueRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_040F_VWLogicalSoftwareBlockLockValue
 **/
EXPORTED Std_ReturnType DIA_runDid040F_VWLogicalSoftwareBlockLockValueRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   /* Fill-in data in response buffer */
   Data[KU8_ZERO]  = KU8_ZERO;
   Data[KU8_ONE]   = KU8_ONE;
   Data[KU8_TWO]   = KU8_ZERO;
   Data[KU8_THREE] = KU8_ZERO;
   Data[KU8_FOUR]  = KU8_ZERO;
   Data[KU8_FIVE]  = KU8_ZERO;

   return ((Std_ReturnType)RTE_E_OK);
}
/**
 * \brief
 *       Function used to read the Bootloader TP Block Size Value.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_040F_VWLogicalSoftwareBlockLockValueData_ReadData
 * \dynamicaspectdescription
 *       Read Bootloader TP Block Size Value.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDid040F_VWLogicalSoftwareBlockLockValueRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_0410_BootloaderTPBlocksize_ReadData
 **/
EXPORTED Std_ReturnType DIA_runDid0410_BootloaderTPBlocksizeRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   /* Fill-in data in response buffer */
   *Data = DIA_u8BootTpSize;

   return ((Std_ReturnType)RTE_E_OK);
}
/**
 * \brief
 *       Function used to read the Programming preconditions.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_0448_ProgrammingPreconditionsData_ReadData
 * \dynamicaspectdescription
 *       Read Programming preconditions.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDid0448_ProgrammingPreconditionsRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_0448_ProgrammingPreconditions
 **/
EXPORTED Std_ReturnType DIA_runDid0448_ProgrammingPreconditionsRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   /* Number of preconditions */
   Data[KU8_ZERO] = KU8_DIA_NB_PRECONDITIONS;
   /* Locking time for programming active */
   Data[KU8_ONE] = KU8_DIA_LOCK_TIME_PROGRAMMNG_ACTIVE;
   /* Overvoltage */
   Data[KU8_TWO] = KU8_DIA_OVERVOLTAGE;
   /*  Undervoltage */
   Data[KU8_THREE] = KU8_DIA_UNDERVOLTAGE;
   /* Crash counter has non -zero value */
   Data[KU8_FOUR] = KU8_DIA_CRASH_COUNTER;

   return ((Std_ReturnType)RTE_E_OK);
}
/**
 * \brief
 *       Function used to read the ECU programming information.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F1DF_ECUProgrammingInformationData_ReadData
 * \dynamicaspectdescription
 *       Read ECU programming information.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidF1DF_ECUProgrammingInformationRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F1DF_ECUProgrammingInformation

 **/
EXPORTED Std_ReturnType DIA_runDidF1DF_ECUProgrammingInformationRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   /* Fill-in data in response buffer */
   *Data = KU8_DIA_ECU_PROGRAMABLE_AND_CONSISTENT;

   return ((Std_ReturnType)RTE_E_OK);
}
/**
 * \brief
 *       Function used to read the ASAM ODX file version.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F1A2_ASAMODXFileVersionData_ReadData
 * \dynamicaspectdescription
 *       Read ASAM ODX file version.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidF1A2_ASAMODXFileVersionRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F1A2_ASAMODXFileVersion_ReadData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidF1A2_ASAMODXFileVersionRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   uint16 u16BlockSize;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ODX_FILE_VERSION, &u16BlockSize);

   /* Fill-in data in response buffer */
   DIA_CopyData(Data, (uint8 *)&NVP_au8ODXFileVersion, u16BlockSize);

   return ((Std_ReturnType)RTE_E_OK);
}
/**
 * \brief
 *       Function used to read the FDS Project parameters.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F1D5_FDSProjectData_ReadData
 * \dynamicaspectdescription
 *       Read FDS project parameters.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidF1D5_FDSProjectDataRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F1D5_FDSProject
 **/
EXPORTED Std_ReturnType DIA_runDidF1D5_FDSProjectDataRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   /* first bit is dev or production key */
   Data[KU8_ZERO] =  KU8_ONE;
   /* FDS id */
   Data[KU8_ONE]   =  KU8_ZERO;
   Data[KU8_TWO]   =  KU8_ZERO;
   Data[KU8_THREE] =  KU8_DIA_FDS_ID_HIGH;
   Data[KU8_FOUR]  =  KU8_DIA_FDS_ID_LOW;
   /* key and hash lenght */
   Data[KU8_FIVE] =  KU8_ZERO;
   Data[KU8_SIX] =  KU8_ZERO;

   return ((Std_ReturnType)RTE_E_OK);
}
/**
 * \brief
 *       Function used to read the VW Ecu Hardware Version Number.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F1A3_VWECUHardwareVersionNumberData_ReadData
 * \dynamicaspectdescription
 *       Read VW Ecu Hardware Version Number.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidF1A3_VWECUHardwareVersionNumberRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F1A3_VWECUHardwareVersionNumber_ReadData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidF1A3_VWECUHardwareVersionNumberRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   uint16 u16BlockSize;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_HARDWARE_VERSION_NUMBER, &u16BlockSize);

   /* Fill-in data in response buffer */
   DIA_CopyData(Data, (uint8 *)&NVP_au8HardwareVersionNumber, u16BlockSize);

   return ((Std_ReturnType)RTE_E_OK);
}
/**
 * \brief
 *       Function used to read the Ecu Serial Number.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F18C_ECUSerialNumberData_ReadData
 * \dynamicaspectdescription
 *       Read Ecu Serial Number.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidF18C_ECUSerialNumberRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F18C_ECUSerialNumberData_ReadData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidF18C_ECUSerialNumberRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   uint16 u16BlockSize;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ECU_SERIAL_NUMBER, &u16BlockSize);

   /* Fill-in data in response buffer */
   DIA_CopyData(Data, (uint8 *)&NVP_au8ECUSerialNumber, u16BlockSize);

   return ((Std_ReturnType)RTE_E_OK);
}
/**
 * \brief
 *       Function used to read the VW Logical SW Block Version.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F1AB_VWLogicalSoftwareBlockVersionData_ReadData
 * \dynamicaspectdescription
 *       Read VW Logical SW Block Version.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidF1AB_VWLogicalSoftwareBlockVersionRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F1AB_VWLogicalSoftwareBlockVersion
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidF1AB_VWLogicalSoftwareBlockVersionRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   uint16 u16BlockSize;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_LOGICAL_SW_BLOCK_VERSION, &u16BlockSize);

   /* Fill-in data in response buffer */
   DIA_CopyData(Data, (uint8 *)&NVP_au8VWLogicalSoftwareBlockVersion, u16BlockSize);

   return ((Std_ReturnType)RTE_E_OK);
}
/**
 * \brief
 *       Function used to read the fingerprint and programming date of logical SW blocks.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F15B_FingerprintAndProgrammingDateOfLogicalSoftwareBlocksData_ReadData
 * \dynamicaspectdescription
 *       Read the fingerprint and programming date of logical SW blocks.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidF15B_FingerprintAndProgrammingDateOfLogicalSoftwareBlocksRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F15B_FingerprintAndProgrammingDateOfLogicalSoftwareBlocks
 **/
EXPORTED Std_ReturnType DIA_runDidF15B_FingerprintAndProgrammingDateOfLogicalSoftwareBlocksRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   /* Used as index to parse UDS buffer and SW version no buffer */
   uint8 u8BufferIndex = KU8_ZERO;
   uint8 u8DataIndex = KU8_ZERO;

   /* Parse spare part number buffer and copy data to UDS data buffer */
   for (u8BufferIndex = KU8_ZERO; u8BufferIndex < KU8_DIA_FINGERPRINT_AND_PROGRAMMING_DATE_SIZE; u8BufferIndex++)
   {
      /* Fingerprint And Programming Date Of Logical Bootloader Block */
      if ((KU8_ONE == u8BufferIndex) || (KU8_TWO == u8BufferIndex))
      {
         Data[u8BufferIndex] = KU8_ONE;
      }
      else if (KU8_NINE >= u8BufferIndex)
      {
         Data[u8BufferIndex] = KU8_ZERO;
      }
      /* Fingerprint And Programming Date Of Logical Application Block */
      else if((KU8_NINE < u8BufferIndex) && (KU8_NINETEEN > u8BufferIndex))
      {
         Data[u8BufferIndex] = (((Dia_stNVMBootloaderDataType*) NVP_au8FBL)->stNVMBlockData[KU8_ONE].au8FingerPrintInfo[u8DataIndex]);
         u8DataIndex++;
      }
      /* Status information bit Of Logical Application Block */
      else if(KU8_NINETEEN == u8BufferIndex)
      {
         Data[u8BufferIndex] = (((Dia_stNVMBootloaderDataType*) NVP_au8FBL)->stNVMBlockData[KU8_ONE].u8StatusInformation);
         u8DataIndex = KU8_ZERO;
      }
      /* Fingerprint And Programming Date Of Logical Calibration Block */
      else if((KU8_NINETEEN < u8BufferIndex) && (KU8_DIA_TWENTYNINE > u8BufferIndex))
      {

         Data[u8BufferIndex] = (((Dia_stNVMBootloaderDataType*) NVP_au8FBL)->stNVMBlockData[KU8_TWO].au8FingerPrintInfo[u8DataIndex]);
         u8DataIndex++;
      }
      else
      {
         /* do nothing */
      }
   }
   /* Status information bit Of Logical Calibration Block */
   Data[KU8_DIA_TWENTYNINE] = (((Dia_stNVMBootloaderDataType*) NVP_au8FBL)->stNVMBlockData[KU8_TWO].u8StatusInformation);

   return ((Std_ReturnType)RTE_E_OK);
}
/**
 * \brief
 *       Function used to read the ASAM ODX file identifier.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F19E_ASAMODXFileIdentifierData_ReadData
 * \dynamicaspectdescription
 *       Read ASAM ODX file identifier.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *		   DSG_DIA_runDidF19E_ASAMODXFileIdentifierRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F19E_ASAMODXFileIdentifier_ReadData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidF19E_ASAMODXFileIdentifierRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{
   uint16 u16BlockSize;

   /* Read data block length */
   Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ODX_FILE_IDENTIFIER, &u16BlockSize);

   /* Fill-in data in response buffer */
   DIA_CopyData(Data, (uint8 *)&NVP_au8ODXFileIdentifier, u16BlockSize);

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Function used to read the eCS parameters.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_0236_ProgrammingDataElockEcuData_ReadData
 * \dynamicaspectdescription
 *       Read eCS parameters.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *       DSG_DIA_run_Did0236_ProgrammingDataElockEcuRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_0236_ProgrammingDataElockEcu_ReadData
 *
 **/
EXPORTED Std_ReturnType DIA_run_Did0236_ProgrammingDataElockEcuRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{

   uint8 u8VarIndex = KU8_FOUR;
   uint8 u8Index = KU8_THIRTYTHREE;

   (*((uint16*) Data)) = U16_SWAP_BYTE_ORDER(NVP_u16XAxisAngleCalib);
   (*((uint16*) (Data + KU8_TWO))) = U16_SWAP_BYTE_ORDER(NVP_u16YAxisAngleCalib);

   for(u8VarIndex = KU8_FOUR; u8VarIndex < KU8_TWENTYONE; u8VarIndex++)
   {
      *(Data + (u8VarIndex)) = (NVP_u32eCSVariant >> (u8VarIndex - KU8_TWO)) & KU8_ONE;
   }

   (*((uint32*) (Data + KU8_TWENTYONE))) = U32_SWAP_BYTE_ORDER(NVP_u32TPassengerWakeup);
   (*((uint32*) (Data + KU8_TWENTYFIVE))) = U32_SWAP_BYTE_ORDER((NVP_u32TPostRun + KU32_DIA_TX_TIMEOUT));
   (*((uint32*) (Data + KU8_TWENTYNINE))) = U32_SWAP_BYTE_ORDER(NVP_u32TLowPower);

   for(u8Index = KU8_THIRTYTHREE; u8Index < KU8_DIA_0236_SIZE; u8Index++)
   {
      *(Data + (u8Index)) = KU8_MAX;
   }

   return ((Std_ReturnType)RTE_E_OK);
}

/**
 * \brief
 *       Function used to read eCS variant.
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by Autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: Data;
 *       Type: uint8*;
 *       Description: Contain the data that will be sent to CAN;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_023E_WSCForProgrammingElockEcuData_ReadData
 * \dynamicaspectdescription
 *       Read eCS variant.
 * \constrains
 *       Service result is RTE_E_OK.
 * \ddesignrequirement
 *       DSG_DIA_run_Did023E_WSCForProgrammingElockEcuRead
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_023E_WSCForProgrammingElockEcu_ReadData
 *
 **/
EXPORTED Std_ReturnType DIA_run_Did023E_WSCForProgrammingElockEcuRead (Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data)
{

   *(Data + (KU8_ZERO)) = NVP_u8Reserved[KU8_ZERO];
   *(Data + (KU8_ONE)) = NVP_u8Reserved[KU8_ONE];
   (*((uint32*) (Data + KU8_TWO))) = U32_SWAP_BYTE_ORDER(NVP_u32eCSCodingVariant);

   return ((Std_ReturnType)RTE_E_OK);
}
#define DIA_STOP_SEC_CODE
#include "DIA_MemMap.h"

/******************************************************************************
Evolution of the component

 created by : T. DEMIREL

 $Log: DIA_ReadDataByIdentifier.c  $
 Revision 1.4.2.48 2023/08/01 10:09:23CEST Gabriel Brasoveanu (gabriel.brasoveanu) 
 Update code after integration of new EB packages
 Revision 1.4.2.47 2023/07/20 09:44:09EEST David Puscasu (david.puscasu) 
 Update Traceability
 Revision 1.4.2.46 2023/07/17 13:35:57EEST Andreea Suiu (andreea.suiu) 
 update traceability
 Revision 1.4.2.45 2023/07/14 15:18:54EEST Andreea Suiu (andreea.suiu) 
 add traceability
 Revision 1.4.2.44 2023/07/11 16:59:57EEST Andreea Suiu (andreea.suiu) 
 update comments, update 0236 write
 Revision 1.4.2.43 2023/06/28 15:17:21EEST Andreea Suiu (andreea.suiu) 
 change NVP variable for 023e did
 Revision 1.4.2.42 2023/06/22 14:07:16EEST Andreea Suiu (andreea.suiu) 
 update src files (fix findings) after review
 Revision 1.4.2.41 2023/06/21 16:18:30EEST Andreea Suiu (andreea.suiu) 
 change 0236 size to 62 bytes (did + data content)
 Revision 1.4.2.40 2023/06/21 14:44:50EEST Andreea Suiu (andreea.suiu) 
 add new line at the bottom of the file
 Revision 1.4.2.39 2023/06/20 14:55:35EEST Andreea Suiu (andreea.suiu) 
 update comments
 Revision 1.4.2.38 2023/06/19 18:23:49EEST Andreea Suiu (andreea.suiu) 
 update 0236 read
 Revision 1.4.2.37 2023/06/19 14:17:53EEST Andreea Suiu (andreea.suiu) 
 add read for 0236, 023e
 Revision 1.4.2.34 2023/06/12 09:16:26EEST Mihai Motoc (mihai.motoc) 
 Doxygen comments updates
 Revision 1.4.2.33 2023/06/08 09:29:50EEST Mihai Motoc (mihai.motoc) 
 Doxygen comments updates
 Revision 1.4.2.32 2023/05/03 10:03:10EEST Andreea Suiu (andreea.suiu) 
 change data access interface for fd8b
 Revision 1.4.2.31 2023/05/02 13:55:07EEST Andreea Suiu (andreea.suiu) 
 add write subfunction for did fd8b, add local functin to check if data is BCD fomrat
 Revision 1.4.2.30 2023/04/28 14:59:12EEST Andreea Suiu (andreea.suiu) 
 update fd10 did
 Revision 1.4.2.29 2023/04/25 09:13:03EEST Andreea Suiu (andreea.suiu) 
 Fix DIA after review
 Revision 1.4.2.28 2023/04/18 18:08:05EEST Andreea Suiu (andreea.suiu) 
 Update DIA module according to the coding rules
 Revision 1.4.2.27 2023/04/18 16:39:03EEST Andreea Suiu (andreea.suiu) 
 Fix DIA module after review
 Revision 1.4.2.26 2023/04/13 16:44:17EEST Andreea Suiu (andreea.suiu) 
 add byte swapping
 Revision 1.4.2.25 2023/04/10 15:51:58EEST Andreea Suiu (andreea.suiu) 
 - change SW version
 - change ascii conditions for F1A3, F189
 Revision 1.4.2.24 2023/04/06 13:40:58EEST Andreea Suiu (andreea.suiu) 
 Update Sw version value to "ES01401H.R12"
 Revision 1.4.2.23 2023/04/06 13:26:30EEST Andreea Suiu (andreea.suiu) 
 Add ascii restrictions (first version)
 Revision 1.4.2.21 2023/03/30 07:31:06EEST Dan Dustinta (dan.dustinta) 
 add else clause
 Revision 1.4.2.20 2023/03/23 01:06:57EET Razvan Badiu (razvan.badiu) 
 RCM rework first draft
 Revision 1.4.2.19 2023/03/22 15:05:30EET Andreea Suiu (andreea.suiu) 
 Update SW Version
 Revision 1.4.2.18 2023/03/16 15:58:37EET Dan Dustinta (dan.dustinta) 
 update SW version
 Revision 1.4.2.17 2023/03/15 12:31:46EET Andreea Suiu (andreea.suiu) 
 Add OEM diagnostics
 Revision 1.4.2.16 2023/03/15 10:15:20EET Andreea Suiu (andreea.suiu) 
 Add OEM diagnostics
 Revision 1.4.2.15 2023/03/01 10:58:45EET Emilian Gustescu (emilian.gustescu) 
 Source file updated to fix QAC warnings
 Revision 1.4.2.14 2023/02/28 18:06:44EET Septimiu Vintila (septimiu.vintila) 
 FuSa section reverted to normal one.
 Revision 1.4.2.13 2023/02/28 17:15:02EET Septimiu Vintila (septimiu.vintila) 
 Data sections changed to FuSa data sections.
 Revision 1.4.2.12 2023/02/28 16:35:52EET Septimiu Vintila (septimiu.vintila) 
 Code sections changed to FuSa code sections.
 Revision 1.4.2.11 2023/02/24 14:27:43EET Andreea Suiu (andreea.suiu) 
 Update SW version
 Revision 1.4.2.10 2023/02/24 13:58:53EET Andreea Suiu (andreea.suiu) 
 Update DIA after QAC
 Revision 1.4.2.9 2023/01/31 20:02:31EET Dan Dustinta (dan.dustinta) 
 remove hardcoded sw version
 Revision 1.4.2.8 2023/01/20 15:24:06EET Denis Folea (denis.folea) 
 DIA fix after review
 Revision 1.4.2.7 2023/01/13 09:08:16EET Dan Dustinta (dan.dustinta) 
 update byte swap
 Revision 1.4.2.6 2022/12/22 16:28:53EET Andrei Anca (andrei.anca) 
 Dia cleanup
 Revision 1.4.2.5 2022/11/28 14:01:02EET Dan Dustinta (dan.dustinta) 
 fix SW version
 Revision 1.4.2.4 2022/11/28 13:53:59EET Dan Dustinta (dan.dustinta) 
 revert SW Version
 Revision 1.4.2.3 2022/11/25 12:47:56EET Dan Dustinta (dan.dustinta) 
 update DCM integration code
 Revision 1.1 2021/09/06 09:39:13EEST Pierre-Olivier Pilot (pierre-olivier.pilot)
 Initial revision

 *****************************************************************************/

/******************************************************************************
End Of File
 *****************************************************************************/
