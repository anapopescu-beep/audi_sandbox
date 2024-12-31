/**
 * \file
 *
 * \brief AUTOSAR MemAcc
 *
 * This file contains the implementation of the AUTOSAR
 * module MemAcc.
 *
 * \version 1.0.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 11.8 (Required):
 * A cast shall not remove any const or volatile qualification from the type pointed to by a pointer.
 *
 * Reason:
 * For of memory optimization, the same pointer type const MemAcc_DataType* is used for jobs
 * that write user data and jobs that only read user data
 * As a consequence, a cast that discards 'const' qualifier is needed.
 *
 * MISRAC2012-2) Deviated Rule: 13.5 (Required):
 * The right hand operand of a logical && or || operator shall not contain persistent side effects.
 *
 * Reason:
 * TS_MemCmp function doesn't have side effects and it just compare the contents of two buffers
 * without modifying them
 */

/* mgcc62 Deviation List
 *
 * MGCC62-1) Deviated Rule: cast-qual
 * warning: cast discards 'const' qualifier from pointer target type [-Wcast-qual]
 *
 * Reason:
 * For of memory optimization, the same pointer type uint8* is used for jobs
 * that write user data and jobs that only read user data
 * As a consequence, a cast that discards 'const' qualifier is needed.
 *
 *
 */

/*==================[inclusions]=============================================*/
#include <TSAutosar.h>            /* EB specific standard types              */
#include <MemAcc_Lcfg.h>
#include <MemAcc.h>               /* General MemAcc header file              */
#include <TSMem.h>                /* Autosar Base module header              */
#include <MemAcc_Int_Types.h>
#include <MemAcc_Queue.h>
#include <MemAcc_Int.h>
#include <MemAcc_Trace.h>

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
#include <Det.h>                  /* API of module Det.                      */
#endif
#if (MEMACC_LEGACY_DRIVER_SUPPORT == STD_ON)
#include <MemIf.h>          /* memory interface types */
#endif
/*==================[macros]=================================================*/


/** \brief Checks for offset of a job start given a valid Area Index
 **
 ** \param[in]   AreaIdx Index of the area
 ** \param[in]   Offset  Logical address to be checked if belongs to the area
 **
 ** \pre   AreaIdx must be valid
 **
 ** \return True if Offset is INVALID
 **
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
#define MEMACC_REQUEST_PARAM_OFFSET_INVALID(AreaIdx, Offset)                \
(                                                                           \
  ((Offset) < MemAcc_AddressAreas[(AreaIdx)].LogicalStartAddress)           \
  ||                                                                        \
  (                                                                         \
    (Offset) >                                                              \
    (                                                                       \
      MemAcc_AddressAreas[(AreaIdx)].LogicalStartAddress                    \
      +                                                                     \
      (MemAcc_AddressAreas[(AreaIdx)].Length - 1U)                          \
    )                                                                       \
  )                                                                         \
)

/** \brief Checks for invalid length of a job given a valid Area Index and Offset
 **
 ** \param[in]   AreaIdx Index of the area
 ** \param[in]   Offset  Logical address for which length is checked
 ** \param[in]   Length  Number of bytes to check if inside area, starting at given offset
 **
 ** \pre   Offset and AreaIdx must be valid
 **
 ** \return True if Length is INVALID
 **
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
#define MEMACC_REQUEST_PARAM_LENGTH_INVALID(AreaIdx, Offset, Length)        \
(                                                                           \
  ((Length) > MemAcc_AddressAreas[(AreaIdx)].Length)                        \
  ||                                                                        \
  (Length == 0U)                                                             \
  ||                                                                        \
  (                                                                         \
    (Length - 1U)                                                           \
    >                                                                       \
    (                                                                       \
      MemAcc_AddressAreas[(AreaIdx)].LogicalStartAddress                    \
      +                                                                     \
      (MemAcc_AddressAreas[(AreaIdx)].Length - 1U)                          \
      -                                                                     \
      (Offset)                                                              \
    )                                                                       \
  )                                                                         \
)

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
/** \brief Defines the Det reporting.
 **/
#define MEMACC_DET_REPORT_ERROR( ApiId, ErrorId )                           \
  (void)Det_ReportError( MEMACC_MODULE_ID, MEMACC_INSTANCE_ID, ( ApiId ), ( ErrorId ) )
#endif

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

#define MEMACC_START_SEC_CODE
#include <MemAcc_MemMap.h>

#if ((MEMACC_ERASE_RETRY_SUPPORT == STD_ON) || (MEMACC_WRITE_RETRY_SUPPORT == STD_ON))
/** \brief Check if retry is applicable on the the related job, and update JobRetryCounter and JobState
 **
 ** \param[in]   AddressAreaCfgIdx Index in the configuration of areas
 ** \param[in]   SubAreaIdx        Index of the sub area
 **
 ** \pre   Parameters must be validated before function call
 **
 ** \return boolean
 ** \retval TRUE, FALSE
 **
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
STATIC FUNC(boolean, MEMACC_CODE) MemAcc_HandleRetryOperations (MemAcc_AddressAreaIdType AddressAreaCfgIdx, MemAcc_AddressAreaIdType SubAreaIdx);
#endif


/** \brief Validates the input of a Job receiving a Job address, a Job content address and a length.
 **
 ** Reports DET errors depending on validation of parameters and DET enable switch
 **
 ** \param[in]   ApiId              Numeric Id of the API for which validation is performed
 ** \param[in]   AddressAreaCfgIdx  Index in the configuration of areas
 ** \param[in]   JobAddress         Logical address in memory for the job
 ** \param[in]   JobDataPtr         Data pointer for Job content: returned or input data
 ** \param[in]   Length             Length of the job
 **
 ** \return Std_ReturnType
 ** \retval E_OK, E_NOT_OK
 **
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
STATIC FUNC(Std_ReturnType, MEMACC_CODE) MemAcc_ValidateMemDataJobParams
(
    uint8                     ApiId,
    MemAcc_AddressAreaIdType  AddressAreaCfgIdx,
    MemAcc_AddressType        JobAddress,
    const MemAcc_DataType     *JobDataPtr,
    MemAcc_LengthType         Length
);


/** \brief Validates the input of a Job receiving a Job address and a length.
 **
 ** Reports DET errors depending on validation of parameters and DET enable switch
 **
 ** \param[in]   ApiId              Numeric Id of the API for which validation is performed
 ** \param[in]   AddressAreaCfgIdx  Index in the configuration of areas
 ** \param[in]   JobAddress         Logical address in memory for the job
 ** \param[in]   Length             Length of the job
 **
 ** \return Std_ReturnType
 ** \retval E_OK, E_NOT_OK
 **
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
STATIC FUNC(Std_ReturnType, MEMACC_CODE) MemAcc_ValidateMemOperationJobParams
(
    uint8                     ApiId,
    MemAcc_AddressAreaIdType  AddressAreaCfgIdx,
    MemAcc_AddressType        JobAddress,
    MemAcc_LengthType         Length
);


/** \brief Finds and returns the sub-area for a logical memory address
 **
 ** \param[in]   AddressAreaCfgIdx Index of the area
 ** \param[in]   LogicalAddress Logical address for which sub-area is returned
 **
 ** \pre   Parameters must be validated before function call
 **
 ** \return MemAcc_AddressAreaIdType
 **
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
STATIC FUNC(MemAcc_AddressAreaIdType, MEMACC_CODE) MemAcc_FindLogicalAddressSubarea (MemAcc_AddressAreaIdType AddressAreaCfgIdx, MemAcc_AddressType LogicalAddress);


/** \brief Validates the input of the GetJobInfo function.
 **
 ** Validates the input of the GetJobInfo function.
 **
 ** \param[in]   AddressAreaCfgIdx Index in the areas configuration
 ** \param[in]   JobInfoPtr Structure pointer to return the detailed processing information of the current job
 **
 ** \return Std_ReturnType
 ** \retval E_OK, E_NOT_OK
 **
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
STATIC FUNC(Std_ReturnType, MEMACC_CODE) MemAcc_ValidateGetJobInfoParams (MemAcc_AddressAreaIdType AddressAreaCfgIdx, MemAcc_JobInfoType* JobInfoPtr);


/** \brief Validates the input of the GetMemoryInfo function.
 **
 ** Validates the input of the GetMemoryInfo function.
 **
 ** \param[in]   AddressAreaCfgIdx Index in the areas configuration
 ** \param[in]   Address Address in logical address space from which corresponding memory device information shall be retrieved
 ** \param[in]   MemoryInfoPtr Destination memory pointer to store the memory device information
 **
 ** \return Std_ReturnType
 ** \retval E_OK, E_NOT_OK
 **
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
STATIC FUNC(Std_ReturnType, MEMACC_CODE) MemAcc_ValidateGetMemoryInfoParams (MemAcc_AddressAreaIdType AddressAreaCfgIdx, MemAcc_AddressType Address,MemAcc_MemoryInfoType* MemoryInfoPtr);


/** \brief Gets the job result for all ongoing subareas
 **
 ** Gets the job result for all ongoing subareas
 ** \return void
 **
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
STATIC FUNC(void, MEMACC_CODE) MemAcc_GetOngoingJobResults (void);


/** \brief Gets the job result and merges it into a common return(abstract of the type of lower layer)
 **
 ** Converts return values of legacy drivers to values of memory driver
 **
 ** \param[in]   AddressAreaId Address Area Id
 ** \param[in]   SubAreaIdx SubAddress Area Id
 **
 ** \return Mem_JobResultType
 **
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
STATIC FUNC(Mem_JobResultType, MEMACC_CODE) MemAcc_GetDriverJobResult (  MemAcc_AddressAreaIdType AddressAreaCfgIdx, MemAcc_AddressAreaIdType SubAreaIdx);


/** \brief Triggers the lower layer jobs for a SubArea.
 **
 ** Triggers the lower layer jobs for a SubArea.
 **
 ** \param[in]   AddressAreaCfgIdx Index in the areas configuration
 ** \param[in]   SubAreaIdx SubAddress Area Index
 **
 ** \return Std_ReturnType
 **
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
STATIC FUNC(Std_ReturnType, MEMACC_CODE) MemAcc_TriggerJob (  MemAcc_AddressAreaIdType AddressAreaCfgIdx, MemAcc_AddressAreaIdType SubAreaIdx);


/** \brief Returns the Index in the configuration for a specific Address Area
 **
 ** Returns the index in the configuration of the Address Area structures for an Area Id
 ** or invalid value for an invalid Area Id
 **
 ** \param[in]   AddressAreaId Address Area Id
 **
 ** \return MemAcc_AddressAreaIdType
 ** \retval Index of the Address Area
 **
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
STATIC FUNC(MemAcc_AddressAreaIdType, MEMACC_CODE) MemAcc_GetAddressAreaConfigIndex (MemAcc_AddressAreaIdType AddressAreaId);


/** \brief Add a job that goes page by page to the driver queues
 **
 ** Add the needed jobs to the drivers queues
 **
 ** \param[in]   AddressAreaCfgIdx Address Area Index
 ** \param[in]   DriverAddress the logical address targeted by the request
 ** \param[in]   UserDataPtr Pointer to the user buffer
 ** \param[in]   Length Length targeted
 **
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
STATIC FUNC(void, MEMACC_CODE) MemAcc_AddDeviceRequest
(
  MemAcc_AddressAreaIdType AddressAreaCfgIdx,
  MemAcc_AddressType JobLogicalAddress,
  const MemAcc_DataType *UserDataPtr,
  MemAcc_LengthType JobLength
);


/** \brief Handles the area job state machine by triggering the
 **        corresponding driver for each sub-area pertaining to the job
 **
 **
 ** \param[in]   AddressAreaCfgIdx Address Area Index in the administrative array
 **
 ** \Reentrancy{Non-Reentrant}
 ** \Synchronicity{Synchronous} */
STATIC FUNC(void, MEMACC_CODE) MemAcc_AreaJobStateMachine (MemAcc_AddressAreaIdType AddressAreaCfgIdx);

#if (MEMACC_LEGACY_DRIVER_SUPPORT == STD_ON)
/** \brief Checks whether blank check api is available for all drivers
 **        that would be used for a blank check job
 **
 **
 ** \param[in]  AddressAreaCfgIdx Address Area Index in the administrative array
 ** \param[in]  TargetAddress  Address starting the blank check job
 ** \param[in]  JobLength  Length of the blank check job
 **
 ** \pre   Parameters must be validated before function call,
 **        as contiguity of sub-areas is ensured by the generator
 **
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
STATIC FUNC(boolean, MEMACC_CODE) MemAcc_BlankCheckApisAvailable(
    MemAcc_AddressAreaIdType AddressAreaCfgIdx,
    MemAcc_AddressType JobLogicalAddress,
    MemAcc_LengthType JobLength);
#endif /* MEMACC_LEGACY_DRIVER_SUPPORT */

/** \brief Get the read chunk size to be used during Read and BlankCheck driver call
 **
 ** \param[in]   AddressAreaCfgIdx Index in the areas configuration
 ** \param[in]   SubAreaIdx SubAddress Area Index
 **
 ** \return Std_ReturnType
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
STATIC FUNC(MemAcc_LengthType, MEMACC_CODE) MemAcc_GetReadChunkSize(
    MemAcc_AddressAreaIdType AddressAreaCfgIdx,
    MemAcc_AddressAreaIdType SubAreaIdx);
#define MEMACC_STOP_SEC_CODE
#include <MemAcc_MemMap.h>

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/
#define MEMACC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <MemAcc_MemMap.h>

STATIC VAR(MemAcc_AdminAddressAreaType, MEMACC_VAR_CLEARED) MemAcc_AdminAddressArea[MEMACC_NB_OF_CONFIGURED_ADDRESSAREAS];

#define MEMACC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <MemAcc_MemMap.h>

#define MEMACC_START_SEC_VAR_INIT_8
#include <MemAcc_MemMap.h>

/** \brief It holds the initialization status of MemAcc. */
STATIC VAR(boolean, MEMACC_VAR) MemAcc_InitStatus = FALSE;

#define MEMACC_STOP_SEC_VAR_INIT_8
#include <MemAcc_MemMap.h>
/*==================[internal function definitions]==========================*/

#define MEMACC_START_SEC_CODE
#include <MemAcc_MemMap.h>

STATIC FUNC(MemAcc_LengthType, MEMACC_CODE) MemAcc_GetReadChunkSize(
    MemAcc_AddressAreaIdType AddressAreaCfgIdx,
    MemAcc_AddressAreaIdType SubAreaIdx)
{
  const MemAcc_SectorBatchType * const SectorBatchCfgPtr = MemAcc_AddressAreas[AddressAreaCfgIdx].SubAreaCfg[SubAreaIdx].SectorBatch;
#if ( MEMACC_READ_BURST_SUPPORT == STD_ON )
  MemAcc_AddressSubAreaAdminType * const SubAreaAdminPtr = &MemAcc_AdminAddressArea[AddressAreaCfgIdx].SubAreaAdmin;
  const MemAcc_AddressSubAreaType * const SubAreaCfgPtr  = &MemAcc_AddressAreas[AddressAreaCfgIdx].SubAreaCfg[SubAreaIdx];
#endif /* MEMACC_READ_BURST_SUPPORT */
  MemAcc_LengthType ReadChunkSize = 0;
#if (MEMACC_READ_BURST_SUPPORT == STD_ON)
  /* !LINKSTO MemAcc.SWS_MemAcc_00101,1 */
  /* !LINKSTO MemAcc.EB.MemoryAccess.Compare.Burst,1 */
  /* !LINKSTO MemAcc.EB.MemoryAccess.BlankCheck.Burst,1 */
  if((SubAreaCfgPtr->UseReadBurst)
      &&
      (SubAreaAdminPtr->RemainingLength >= SectorBatchCfgPtr->ReadPageBurstSize))
  {
    ReadChunkSize = SectorBatchCfgPtr->ReadPageBurstSize;
  }
  else if((SubAreaCfgPtr->UseReadBurst)
          &&
         ((SubAreaAdminPtr->RemainingLength < SectorBatchCfgPtr->ReadPageBurstSize)
         &&
         (SubAreaAdminPtr->RemainingLength >= SectorBatchCfgPtr->ReadPageSize)))
  {
    ReadChunkSize = SubAreaAdminPtr->RemainingLength;
  }
  /* !LINKSTO MemAcc.MemoryAccess.Read.Page, 1 */
  /* !LINKSTO MemAcc.EB.MemoryAccess.Compare.Page, 1 */
  /* !LINKSTO MemAcc.EB.MemoryAccess.BlankCheck.Page, 1 */
  else
#endif /* MEMACC_READ_BURST_SUPPORT */
  {
    ReadChunkSize = SectorBatchCfgPtr->ReadPageSize;
  }

  return ReadChunkSize;
}
#if ((MEMACC_ERASE_RETRY_SUPPORT == STD_ON) || (MEMACC_WRITE_RETRY_SUPPORT == STD_ON))
STATIC FUNC(boolean, MEMACC_CODE) MemAcc_HandleRetryOperations (MemAcc_AddressAreaIdType AddressAreaCfgIdx, MemAcc_AddressAreaIdType SubAreaIdx)
{
  boolean Retry = FALSE;
  const MemAcc_AddressSubAreaType * const SubAreaCfgPtr = &MemAcc_AddressAreas[AddressAreaCfgIdx].SubAreaCfg[SubAreaIdx];
  const MemAcc_JobType JobType = MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobType;

  /* !LINKSTO MemAcc.SWS_MemAcc_00100, 1 */
#if (MEMACC_WRITE_RETRY_SUPPORT == STD_ON)
  if( ( JobType == MEMACC_WRITE_JOB ) && ( MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobRetryCounter < SubAreaCfgPtr->NumberOfWriteRetries ) )
  {
    Retry = TRUE;
  }
  else
  {
    /* No write retry */
  }
#endif

  /* !LINKSTO MemAcc.SWS_MemAcc_00005, 1 */
#if (MEMACC_ERASE_RETRY_SUPPORT == STD_ON)
  if( ( JobType == MEMACC_ERASE_JOB ) && ( MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobRetryCounter < SubAreaCfgPtr->NumberOfEraseRetries ) )
  {
    Retry = TRUE;
  }
  else
  {
    /* No erase retry */
  }
#endif

  if(Retry)
  {
    MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobRetryCounter++;
  }
  else
  {
    /* Retry is not applicable due to
      - Job type is not Erase or Write,
      - The configured number of retries is zero, or
      - The number of retries is exceeded
    */
  }
  return Retry;
}
#endif


STATIC FUNC(MemAcc_AddressAreaIdType, MEMACC_CODE) MemAcc_FindLogicalAddressSubarea(MemAcc_AddressAreaIdType AddressAreaCfgIdx, MemAcc_AddressType LogicalAddress)
{
  MemAcc_AddressAreaIdType SubAreaIdx;
  MemAcc_AddressSubAreaType const *SubAreaCfgPtr;
  boolean SubAreaFound = FALSE;
  for (SubAreaIdx = 0; (SubAreaIdx < MemAcc_AddressAreas[AddressAreaCfgIdx].NumberOfSubAreas) && (SubAreaFound == FALSE); SubAreaIdx++)
  {
    SubAreaCfgPtr = &MemAcc_AddressAreas[AddressAreaCfgIdx].SubAreaCfg[SubAreaIdx];
    if(LogicalAddress <= ((SubAreaCfgPtr->LogicalStartAddress) + (SubAreaCfgPtr->Length -1U)))
    {
      SubAreaFound = TRUE;
    }
  }
  SubAreaIdx--;
  return SubAreaIdx;
}


STATIC FUNC(Std_ReturnType, MEMACC_CODE) MemAcc_ValidateMemDataJobParams
(
    uint8                     ApiId,
    MemAcc_AddressAreaIdType  AddressAreaCfgIdx,
    MemAcc_AddressType        JobAddress,
    const MemAcc_DataType     *JobDataPtr,
    MemAcc_LengthType         Length
)
{
  /* !LINKSTO MemAcc.Request.InvalidParameter, 1 */
  /* !LINKSTO MemAcc.Request.MultipleRequestsForSameAreaReturnCode, 1 */
  Std_ReturnType Result = E_NOT_OK;

  if(AddressAreaCfgIdx == MEMACC_INVALID_ADDRESSAREA)
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00044, 1 */
    /* !LINKSTO MemAcc.SWS_MemAcc_00049, 1*/
    /* !LINKSTO MemAcc.SWS_MemAcc_00058, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(ApiId, MEMACC_E_PARAM_ADDRESS_AREA_ID);
#endif
  }
  else if(JobDataPtr == NULL_PTR)
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00045, 1 */
    /* !LINKSTO MemAcc.SWS_MemAcc_00050, 1*/
    /* !LINKSTO MemAcc.SWS_MemAcc_00059, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(ApiId,MEMACC_E_PARAM_POINTER);
#endif
  }
  else if(MEMACC_REQUEST_PARAM_OFFSET_INVALID(AddressAreaCfgIdx, JobAddress))
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00046, 1*/
    /* !LINKSTO MemAcc.SWS_MemAcc_00051, 1*/
    /* !LINKSTO MemAcc.SWS_MemAcc_00060, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(ApiId, MEMACC_E_PARAM_ADDRESS_LENGTH);
#endif
  }
  else if(MEMACC_REQUEST_PARAM_LENGTH_INVALID(AddressAreaCfgIdx, JobAddress, Length))
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00046, 1*/
    /* !LINKSTO MemAcc.SWS_MemAcc_00051, 1*/
    /* !LINKSTO MemAcc.SWS_MemAcc_00060, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(ApiId, MEMACC_E_PARAM_ADDRESS_LENGTH);
#endif
  }
  /* !LINKSTO MemAcc.SWS_MemAcc_00018, 1 */
  else if(MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobStatus == MEMACC_JOB_PENDING)
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00047, 1*/
    /* !LINKSTO MemAcc.SWS_MemAcc_00052, 1*/
    /* !LINKSTO MemAcc.SWS_MemAcc_00061, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(ApiId, MEMACC_E_BUSY);
#endif
  }
  else
  {
    Result = E_OK;
  }

#if ( MEMACC_DEV_ERROR_DETECT != STD_ON )
  TS_PARAM_UNUSED(ApiId);
#endif

  return Result;
}


STATIC FUNC(Std_ReturnType, MEMACC_CODE) MemAcc_ValidateMemOperationJobParams
(
    uint8                     ApiId,
    MemAcc_AddressAreaIdType  AddressAreaCfgIdx,
    MemAcc_AddressType        JobAddress,
    MemAcc_LengthType         Length
)
{
  /* !LINKSTO MemAcc.Request.InvalidParameter, 1 */
  /* !LINKSTO MemAcc.Request.MultipleRequestsForSameAreaReturnCode, 1 */
  Std_ReturnType Result = E_NOT_OK;

  if(AddressAreaCfgIdx == MEMACC_INVALID_ADDRESSAREA)
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00039, 1*/
    /* !LINKSTO MemAcc.SWS_MemAcc_00054, 1*/
    /* !LINKSTO MemAcc.SWS_MemAcc_00063, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(ApiId, MEMACC_E_PARAM_ADDRESS_AREA_ID);
#endif
  }
  else if(MEMACC_REQUEST_PARAM_OFFSET_INVALID(AddressAreaCfgIdx, JobAddress))
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00055, 1*/
    /* !LINKSTO MemAcc.SWS_MemAcc_00064, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(ApiId, MEMACC_E_PARAM_ADDRESS_LENGTH);
#endif
  }
  else if(MEMACC_REQUEST_PARAM_LENGTH_INVALID(AddressAreaCfgIdx, JobAddress, Length))
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00055, 1*/
    /* !LINKSTO MemAcc.SWS_MemAcc_00064, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(ApiId, MEMACC_E_PARAM_ADDRESS_LENGTH);
#endif
  }
  /* !LINKSTO MemAcc.SWS_MemAcc_00018, 1 */
  else if(MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobStatus == MEMACC_JOB_PENDING)
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00056, 1*/
    /* !LINKSTO MemAcc.SWS_MemAcc_00065, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(ApiId, MEMACC_E_BUSY);
#endif
  }
  else
  {
    Result = E_OK;
  }

#if ( MEMACC_DEV_ERROR_DETECT != STD_ON )
  TS_PARAM_UNUSED(ApiId);
#endif

  return Result;
}


#if (MEMACC_LEGACY_DRIVER_SUPPORT == STD_ON)
STATIC FUNC(boolean, MEMACC_CODE) MemAcc_BlankCheckApisAvailable
(
  MemAcc_AddressAreaIdType AddressAreaCfgIdx,
  MemAcc_AddressType JobLogicalAddress,
  MemAcc_LengthType JobLength
)
{
  MemAcc_AddressSubAreaType const *SubAreaCfgPtr;
  MemAcc_HwIdType                 HwIdx;
  MemAcc_LengthType               RemainingLength;
  MemAcc_LengthType               SubAreaPossibleJobLength;
  MemAcc_AddressAreaIdType        SubAreaIdx;
  boolean                         DrvApisAvailable = TRUE;

  SubAreaIdx = MemAcc_FindLogicalAddressSubarea(AddressAreaCfgIdx, JobLogicalAddress);
  SubAreaCfgPtr = &MemAcc_AddressAreas[AddressAreaCfgIdx].SubAreaCfg[SubAreaIdx];

  HwIdx = SubAreaCfgPtr->DrvHwId;
  if(((MemAcc_MemApi_LegacyType const *)MemAcc_MemoryDevicesInfo[HwIdx].DrvApiTable)->BlankCheck != NULL_PTR)
  {
    /*avoid possible ovf for an end of memory sub-area*/
    SubAreaPossibleJobLength = ((SubAreaCfgPtr->LogicalStartAddress + (SubAreaCfgPtr->Length -1U))
                               - JobLogicalAddress + 1U);

    if(JobLength > SubAreaPossibleJobLength)
    {
      RemainingLength = JobLength - SubAreaPossibleJobLength;

      for(++SubAreaIdx; SubAreaIdx < MemAcc_AddressAreas[AddressAreaCfgIdx].NumberOfSubAreas; SubAreaIdx++)
      {
        SubAreaCfgPtr = &MemAcc_AddressAreas[AddressAreaCfgIdx].SubAreaCfg[SubAreaIdx];
        HwIdx = SubAreaCfgPtr->DrvHwId;
        if( ((MemAcc_MemApi_LegacyType const *)MemAcc_MemoryDevicesInfo[HwIdx].DrvApiTable)->BlankCheck != NULL_PTR)
        {
          if(RemainingLength <= SubAreaCfgPtr->Length)
          {
            break;
          }
          else/*Job Spans Other SubArea*/
          {
            RemainingLength -= SubAreaCfgPtr->Length;
          }
        }
        else
        {
          DrvApisAvailable = FALSE;
          break;
        }
      }
    }
    else
    { /*availability already set, nothing to do*/
    }
  }
  else
  {
    DrvApisAvailable = FALSE;
  }
  return DrvApisAvailable;
}
#endif /* MEMACC_LEGACY_DRIVER_SUPPORT */
/*--------------------------[MemAcc_GetAddressAreaConfigIndex]---------------------------------------*/
STATIC FUNC(MemAcc_AddressAreaIdType, MEMACC_CODE) MemAcc_GetAddressAreaConfigIndex (MemAcc_AddressAreaIdType AddressAreaId)
{
  MemAcc_AddressAreaIdType AddressAreaCfgIdx;

  /* If address area id exists return it
   * This function is to allow future implementation of noncontiguous address area id */
  if(AddressAreaId < MEMACC_NB_OF_CONFIGURED_ADDRESSAREAS)
  {
    AddressAreaCfgIdx = AddressAreaId;
  }
  else
  {
    AddressAreaCfgIdx = MEMACC_INVALID_ADDRESSAREA;
  }
  return AddressAreaCfgIdx;
}

/*--------------------------[MemAcc_AddDeviceRequest]---------------------------------------*/
STATIC FUNC(void, MEMACC_CODE) MemAcc_AddDeviceRequest
(
  MemAcc_AddressAreaIdType AddressAreaCfgIdx,
  MemAcc_AddressType JobLogicalAddress,
  const MemAcc_DataType *UserDataPtr,
  MemAcc_LengthType JobLength
)
{
  MemAcc_AddressAreaIdType SubAreaIdx;
  MemAcc_AddressSubAreaAdminType * SubAreaAdminPtr;
  const MemAcc_AddressSubAreaType * SubAreaCfgPtr;
  MemAcc_AddressType SubAreaEndAddress;

  MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobLogicalAddress = JobLogicalAddress;
  MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobLength = JobLength;
  MemAcc_AdminAddressArea[AddressAreaCfgIdx].RemainingLength = JobLength;
  MemAcc_AdminAddressArea[AddressAreaCfgIdx].MemLength = 0;
#if ((MEMACC_ERASE_RETRY_SUPPORT == STD_ON) || (MEMACC_WRITE_RETRY_SUPPORT == STD_ON))
  MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobRetryCounter = 0;
#endif
  /* !LINKSTO MemAcc.SWS_MemAcc_00020, 1*/
  MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobStatus = MEMACC_JOB_PENDING;
  /* !LINKSTO MemAcc.EB.GetJobResult.Init.NewRequest, 1*/
  MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobResult = MEMACC_MEM_OK;

  /*Handle first sub-area, job might start anywhere inside*/
  SubAreaIdx = MemAcc_FindLogicalAddressSubarea(AddressAreaCfgIdx, JobLogicalAddress);
  MemAcc_AdminAddressArea[AddressAreaCfgIdx].SubAreaIdx = SubAreaIdx;


  SubAreaCfgPtr = &MemAcc_AddressAreas[AddressAreaCfgIdx].SubAreaCfg[SubAreaIdx];

  SubAreaAdminPtr = &MemAcc_AdminAddressArea[AddressAreaCfgIdx].SubAreaAdmin;
  /* !LINKSTO MemAcc.Dsn.SubAreaJobState.NewJob, 1*/
  SubAreaAdminPtr->JobState = MEMACC_WAITING;
  SubAreaAdminPtr->JobPhysicalStartAddress = SubAreaCfgPtr->PhysicalStartAddress
                                            +(JobLogicalAddress - SubAreaCfgPtr->LogicalStartAddress);
  SubAreaAdminPtr->UserDataPtr =  UserDataPtr;

  SubAreaEndAddress = SubAreaCfgPtr->LogicalStartAddress + (SubAreaCfgPtr->Length - 1U);

  if((JobLogicalAddress + (JobLength - 1U)) <= SubAreaEndAddress)
  {/*Job ends in this first subArea*/
    SubAreaAdminPtr->RemainingLength = JobLength;
  }
  else
  {
    /*Job Spans Other SubArea*/
    SubAreaAdminPtr->RemainingLength = (SubAreaEndAddress - JobLogicalAddress) + 1U;
  }
}

/*--------------------------[MemAcc_AreaJobStateMachine]---------------------------------------*/
STATIC FUNC(void, MEMACC_CODE) MemAcc_AreaJobStateMachine (MemAcc_AddressAreaIdType AddressAreaCfgIdx)
{
  MemAcc_AddressAreaIdType SubAreaIdx;
  Mem_JobResultType DriverJobResult;

  Std_ReturnType TriggerJobResult = E_NOT_OK;
  boolean TriggerJob = FALSE;
  MemAcc_AddressSubAreaAdminType *SubAreaAdminPtr;
  const MemAcc_AddressSubAreaType * SubAreaCfgPtr;

  /*Sequential processing of sub-areas, calculate current sub-area*/
  SubAreaIdx = MemAcc_AdminAddressArea[AddressAreaCfgIdx].SubAreaIdx;

  SubAreaAdminPtr = &MemAcc_AdminAddressArea[AddressAreaCfgIdx].SubAreaAdmin;
  switch(SubAreaAdminPtr->JobState)
  {
    case MEMACC_WAITING:
        TriggerJob = TRUE;
      break;
    case MEMACC_INPROGRESS:
      switch (SubAreaAdminPtr->MemDrvJobResult)
      {
        /* !LINKSTO MemAcc.SWS_MemAcc_00028, 1*/
        case MEM_JOB_OK:
#if ((MEMACC_ERASE_RETRY_SUPPORT == STD_ON) || (MEMACC_WRITE_RETRY_SUPPORT == STD_ON))
          MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobRetryCounter = 0;
#endif
#if (MEMACC_COMPARE_API == STD_ON)
          /* Deviation MISRAC2012-2 */
          if((MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobType == MEMACC_COMPARE_JOB)
            && (TS_MemCmp(MemAcc_AddressAreas[AddressAreaCfgIdx].AddressAreaCmpBuffer,
                          (SubAreaAdminPtr->UserDataPtr - MemAcc_AdminAddressArea[AddressAreaCfgIdx].MemLength),
                          MemAcc_AdminAddressArea[AddressAreaCfgIdx].MemLength) != E_OK))
          {
              /* !LINKSTO MemAcc.Request.Inconsistent.Compare , 1 */
              /* !LINKSTO MemAcc.Compare.JobResult.Mismatch, 1 */
              MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobResult = MEMACC_MEM_INCONSISTENT;
          }
          else
#endif
          {
            if((SubAreaAdminPtr->RemainingLength) > 0U )
            {
              TriggerJob = TRUE;
            }
            else
            {
              /* !LINKSTO MemAcc.Dsn.SubAreaJobState.JobDone, 1*/
              /*sub area completed*/
              SubAreaAdminPtr->JobState = MEMACC_IDLE;
              /*After one area is completed check if any more is needed, if not, complete Area Job*/
              if(MemAcc_AdminAddressArea[AddressAreaCfgIdx].RemainingLength == 0U)
              {
                /* !LINKSTO MemAcc.SWS_MemAcc_00105, 1*/
                /* !LINKSTO MemAcc.Compare.JobResult.Match, 1*/
                /* !LINKSTO MemAcc.Dsn.Interaction.Polling.JobResult, 1*/
                /* !LINKSTO MemAcc.Dsn.Interaction.Cbk.CancelFinishedJob, 1*/
                MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobResult = MEMACC_MEM_OK;
                /* !LINKSTO MemAcc.SWS_MemAcc_00104, 1*/
                MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobStatus = MEMACC_JOB_IDLE;
              }
              else
              {
                ++SubAreaIdx;
                MemAcc_AdminAddressArea[AddressAreaCfgIdx].SubAreaIdx = SubAreaIdx;
                SubAreaCfgPtr = &MemAcc_AddressAreas[AddressAreaCfgIdx].SubAreaCfg[SubAreaIdx];

                SubAreaAdminPtr->JobPhysicalStartAddress = SubAreaCfgPtr->PhysicalStartAddress;

                if(MemAcc_AdminAddressArea[AddressAreaCfgIdx].RemainingLength <= SubAreaCfgPtr->Length)
                {
                  SubAreaAdminPtr->RemainingLength = MemAcc_AdminAddressArea[AddressAreaCfgIdx].RemainingLength;
                }
                else
                {
                  SubAreaAdminPtr->RemainingLength = SubAreaCfgPtr->Length;
                }
                TriggerJob = TRUE;
              }
            }
          }
          break;
        case MEM_JOB_PENDING:
          /* do nothing this cycle, job still ongoing
           * and cancel request is handled only at driver operation end
           */
          break;
        default:
          /*ongoing sub-area job failed, job for AreaId is terminated*/
          if(SubAreaAdminPtr->MemDrvJobResult == MEM_INCONSISTENT)
          {
            /* !LINKSTO MemAcc.Dsn.Interaction.Polling.JobResult, 1*/
            /* !LINKSTO MemAcc.Dsn.Interaction.Cbk.CancelFinishedJob, 1*/
            /* !LINKSTO MemAcc.Request.Inconsistent.BlankCheck, 1 */
            MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobResult = MEMACC_MEM_INCONSISTENT;
          }
          else
          {
#if ((MEMACC_ERASE_RETRY_SUPPORT == STD_ON) || (MEMACC_WRITE_RETRY_SUPPORT==STD_ON))
            if(MemAcc_HandleRetryOperations(AddressAreaCfgIdx, SubAreaIdx))
            {
              SubAreaAdminPtr->RemainingLength += MemAcc_AdminAddressArea[AddressAreaCfgIdx].MemLength;
              MemAcc_AdminAddressArea[AddressAreaCfgIdx].RemainingLength += MemAcc_AdminAddressArea[AddressAreaCfgIdx].MemLength;
              SubAreaAdminPtr->JobPhysicalStartAddress -= MemAcc_AdminAddressArea[AddressAreaCfgIdx].MemLength;
              if(SubAreaAdminPtr->UserDataPtr != NULL_PTR)
              {
                SubAreaAdminPtr->UserDataPtr -= MemAcc_AdminAddressArea[AddressAreaCfgIdx].MemLength;
              }
              else
              {
                /*Job type without user data*/
              }

              TriggerJob = TRUE;
            }
            else
#endif
            {
              /* !LINKSTO MemAcc.Dsn.Interaction.Polling.JobResult, 1*/
              /* !LINKSTO MemAcc.Dsn.Interaction.Cbk.CancelFinishedJob, 1*/
              /* !LINKSTO MemAcc.SWS_MemAcc_00109, 1*/
              MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobResult = MEMACC_MEM_FAILED;
            }
          }
          break;
      }
      break;
/* CHECK: NOPARSE */
/* switching is done between fixed known states, so default is not needed */
    default:
      /* Unknown state, should not be reached*/
      break;
/* CHECK: PARSE */
  }
  if(TriggerJob)
  {
    if(!MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobCancelRequested)
    {
      /* !LINKSTO MemAcc.SWS_MemAcc_00006, 1 */
      DriverJobResult = MemAcc_GetDriverJobResult(AddressAreaCfgIdx, SubAreaIdx);
      if(DriverJobResult != MEM_JOB_PENDING)
      {
        TriggerJobResult = MemAcc_TriggerJob(AddressAreaCfgIdx, SubAreaIdx);
        if (TriggerJobResult == E_NOT_OK)
        {
          /* !LINKSTO MemAcc.SWS_MemAcc_00109, 1*/
          MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobResult = MEMACC_MEM_FAILED;
        }
        else
        {
          /* !LINKSTO MemAcc.Dsn.SubAreaJobState.JobRequested, 1*/
          SubAreaAdminPtr->JobState = MEMACC_INPROGRESS;
        }
      }
      else
      {
        /* !LINKSTO MemAcc.Dsn.SubAreaJobState.BusyDriver, 1*/
        SubAreaAdminPtr->JobState = MEMACC_WAITING;
      }
    }
    else
    {
      /* !LINKSTO MemAcc.Dsn.Interaction.Polling.Canceled, 1*/
      /* !LINKSTO MemAcc.Dsn.Interaction.Cbk.Canceled, 1*/
      /* !LINKSTO MemAcc.SWS_MemAcc_00028, 1*/
      MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobResult = MEMACC_MEM_CANCELED;
    }
  }
  /*Job result is set to MEMACC_MEM_OK when job is started;
   * and changed only at job end
   * tdo: according to published SWS, JobResult shall not be set to OK at new request...
   */
  if(MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobResult != MEMACC_MEM_OK)
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00104, 1*/
    MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobStatus = MEMACC_JOB_IDLE;
  }
  else
  {
    /* The current job is sill in progress */
  }

  if(MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobStatus != MEMACC_JOB_PENDING)
  {
    MemAcc_AdminAddressArea[AddressAreaCfgIdx].SubAreaAdmin.JobState = MEMACC_IDLE;
  }
  else
  {
    /*continue processing this area next main cycle*/
  }
}
#define MEMACC_STOP_SEC_CODE
#include <MemAcc_MemMap.h>


/*==================[external function definitions]==========================*/

#define MEMACC_START_SEC_CODE
#include <MemAcc_MemMap.h>


/*--------------------------[MemAcc_Init]---------------------------------------*/
/* !LINKSTO MemAcc.Dsn.Interfaces.Init, 1*/
FUNC(void, MEMACC_CODE) MemAcc_Init (const MemAcc_ConfigType* ConfigPtr)
{
  MemAcc_AddressAreaIdType AddressAreaCfgIdx = 0;
#if (MEMACC_HANDLING_SUPPORT == STD_ON)
  MemAcc_HwIdType HwIdx;
  Mem_ConfigType DriverConfigPtr;
  MemAcc_MemInstanceIdType InstanceIdx = 0;
#endif /* #if (MEMACC_HANDLING_SUPPORT == STD_ON) */

  TS_PARAM_UNUSED(ConfigPtr); /*post build configuration is not supported yet*/

  DBG_MEMACC_INIT_ENTRY();

  MemAcc_Queue_Init();

  for(AddressAreaCfgIdx = 0; AddressAreaCfgIdx < MEMACC_NB_OF_CONFIGURED_ADDRESSAREAS; AddressAreaCfgIdx++)
  {
    /* Init the Admin data for the Address Areas */
    /* !LINKSTO MemAcc.SWS_MemAcc_00112, 1*/
    MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobResult = MEMACC_MEM_OK;
    /* !LINKSTO MemAcc.SWS_MemAcc_00113, 1*/
    MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobStatus = MEMACC_JOB_IDLE;
    MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobType   = MEMACC_NO_JOB;
    MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobLength = 0;
    MemAcc_AdminAddressArea[AddressAreaCfgIdx].MemLength = 0;
    MemAcc_AdminAddressArea[AddressAreaCfgIdx].LastActiveSubAreaIdx = 0;
    MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobCancelRequested   = FALSE;
#if ((MEMACC_ERASE_RETRY_SUPPORT == STD_ON) || (MEMACC_WRITE_RETRY_SUPPORT == STD_ON))
    MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobRetryCounter = 0;
#endif
      /* !LINKSTO MemAcc.Dsn.SubAreaJobState.Init, 1*/
    MemAcc_AdminAddressArea[AddressAreaCfgIdx].SubAreaAdmin.JobState = MEMACC_IDLE;
  }

  MemAcc_InitStatus = TRUE;

  DBG_MEMACC_INIT_EXIT();
}


/*--------------------------[MemAcc_Read]---------------------------------------*/
/* !LINKSTO MemAcc.Dsn.Interfaces.Read, 1*/
FUNC(Std_ReturnType, MEMACC_CODE) MemAcc_Read
(
  MemAcc_AddressAreaIdType AddressAreaId,
  MemAcc_AddressType SourceAddress,
  MemAcc_DataType *DestinationDataPtr,
  MemAcc_LengthType Length
)
{
  Std_ReturnType Result = E_NOT_OK;
  MemAcc_AddressAreaIdType AddressAreaCfgIdx;

  DBG_MEMACC_READ_ENTRY(AddressAreaId, SourceAddress, DestinationDataPtr, Length);

  if(MemAcc_InitStatus)
  {
    AddressAreaCfgIdx = MemAcc_GetAddressAreaConfigIndex(AddressAreaId);
    Result = MemAcc_ValidateMemDataJobParams(MEMACC_READ_API_ID, AddressAreaCfgIdx, SourceAddress, DestinationDataPtr, Length);
    if( Result == E_OK)
    {
      MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobType = MEMACC_READ_JOB;
      MemAcc_InsertInQueue(AddressAreaCfgIdx);
      /* !LINKSTO MemAcc.SWS_MemAcc_00008, 1*/
      MemAcc_AddDeviceRequest(AddressAreaCfgIdx, SourceAddress, DestinationDataPtr, Length);
    }
  }
  else
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00043, 1*/
    #if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        MEMACC_DET_REPORT_ERROR(MEMACC_READ_API_ID, MEMACC_E_UNINIT);
    #endif
  }

  DBG_MEMACC_READ_EXIT(Result, AddressAreaId, SourceAddress, DestinationDataPtr, Length);
  return Result;
}


/*--------------------------[MemAcc_Write]---------------------------------------*/
/* !LINKSTO MemAcc.Dsn.Interfaces.Write, 1 */
FUNC(Std_ReturnType, MEMACC_CODE) MemAcc_Write
(
  MemAcc_AddressAreaIdType AddressAreaId,
  MemAcc_AddressType TargetAddress,
  const MemAcc_DataType* SourceDataPtr,
  MemAcc_LengthType Length
)
{
  Std_ReturnType Result = E_NOT_OK;
  MemAcc_AddressAreaIdType AddressAreaCfgIdx;

  DBG_MEMACC_WRITE_ENTRY(AddressAreaId, TargetAddress, SourceDataPtr, Length);
  if(MemAcc_InitStatus)
  {
    AddressAreaCfgIdx = MemAcc_GetAddressAreaConfigIndex(AddressAreaId);
    Result = MemAcc_ValidateMemDataJobParams(MEMACC_WRITE_API_ID,AddressAreaCfgIdx, TargetAddress, SourceDataPtr, Length);
    if( Result == E_OK)
    {
      MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobType = MEMACC_WRITE_JOB;
      MemAcc_InsertInQueue(AddressAreaCfgIdx);
      /* !LINKSTO MemAcc.SWS_MemAcc_00008, 1*/
      MemAcc_AddDeviceRequest(AddressAreaCfgIdx, TargetAddress, SourceDataPtr, Length);
    }
  }
  else
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00048, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(MEMACC_WRITE_API_ID, MEMACC_E_UNINIT);
#endif
  }
  DBG_MEMACC_WRITE_EXIT(Result, AddressAreaId, TargetAddress, SourceDataPtr, Length);
  return Result;
}


/*--------------------------[MemAcc_Erase]---------------------------------------*/
/* !LINKSTO MemAcc.Dsn.Interfaces.Erase, 1*/
FUNC(Std_ReturnType, MEMACC_CODE) MemAcc_Erase
(
  MemAcc_AddressAreaIdType AddressAreaId,
  MemAcc_AddressType TargetAddress,
  MemAcc_LengthType Length
)
{
  Std_ReturnType Result = E_NOT_OK;
  MemAcc_AddressAreaIdType AddressAreaCfgIdx;

  DBG_MEMACC_ERASE_ENTRY(AddressAreaId, TargetAddress, Length);
  if(MemAcc_InitStatus)
  {
    AddressAreaCfgIdx = MemAcc_GetAddressAreaConfigIndex(AddressAreaId);
    Result = MemAcc_ValidateMemOperationJobParams(MEMACC_ERASE_API_ID, AddressAreaCfgIdx, TargetAddress, Length);
    if( Result == E_OK)
    {

      MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobType = MEMACC_ERASE_JOB;
      MemAcc_InsertInQueue(AddressAreaCfgIdx);
      /* !LINKSTO MemAcc.SWS_MemAcc_00008, 1*/
      MemAcc_AddDeviceRequest(AddressAreaCfgIdx, TargetAddress, NULL_PTR, Length);
    }
  }
  else
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00053, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(MEMACC_ERASE_API_ID, MEMACC_E_UNINIT);
#endif
  }

  DBG_MEMACC_ERASE_EXIT(Result, AddressAreaId, TargetAddress, Length);
  return Result;
}


#if (MEMACC_COMPARE_API == STD_ON)
/*--------------------------[MemAcc_Compare]---------------------------------------*/
/* !LINKSTO MemAcc.Dsn.Interfaces.Compare, 1*/
FUNC(Std_ReturnType, MEMACC_CODE) MemAcc_Compare
(
  MemAcc_AddressAreaIdType AddressAreaId,
  MemAcc_AddressType SourceAddress,
  const MemAcc_DataType *DataPtr,
  MemAcc_LengthType Length
)
{
  Std_ReturnType Result = E_NOT_OK;
  MemAcc_AddressAreaIdType AddressAreaCfgIdx;

  DBG_MEMACC_COMPARE_ENTRY(AddressAreaId, SourceAddress, DataPtr, Length);

  if(MemAcc_InitStatus)
  {
    AddressAreaCfgIdx = MemAcc_GetAddressAreaConfigIndex(AddressAreaId);
    Result = MemAcc_ValidateMemDataJobParams(MEMACC_COMPARE_API_ID,AddressAreaCfgIdx, SourceAddress, DataPtr, Length);
    if( Result == E_OK)
    {

      MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobType = MEMACC_COMPARE_JOB;
      MemAcc_InsertInQueue(AddressAreaCfgIdx);
      /* !LINKSTO MemAcc.SWS_MemAcc_00008, 1*/
      MemAcc_AddDeviceRequest(AddressAreaCfgIdx, SourceAddress, DataPtr, Length);
    }
  }
  else
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00057, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(MEMACC_COMPARE_API_ID, MEMACC_E_UNINIT);
#endif
  }

  DBG_MEMACC_COMPARE_EXIT(Result, AddressAreaId, SourceAddress, DataPtr, Length);
  return Result;
}
#endif


/*--------------------------[MemAcc_BlankCheck]---------------------------------------*/
/* !LINKSTO MemAcc.Dsn.Interfaces.BlankCheck, 1*/
FUNC(Std_ReturnType, MEMACC_CODE) MemAcc_BlankCheck
(
  MemAcc_AddressAreaIdType AddressAreaId,
  MemAcc_AddressType TargetAddress,
  MemAcc_LengthType Length
)
{
  MemAcc_AddressAreaIdType AddressAreaCfgIdx;
  Std_ReturnType Result = E_NOT_OK;


  DBG_MEMACC_BLANKCHECK_ENTRY(AddressAreaId, TargetAddress, Length);

  if(MemAcc_InitStatus)
  {
    AddressAreaCfgIdx = MemAcc_GetAddressAreaConfigIndex(AddressAreaId);
    Result = MemAcc_ValidateMemOperationJobParams(MEMACC_BLANK_CHECK_API_ID, AddressAreaCfgIdx, TargetAddress, Length);
    if( Result == E_OK)
    {
      /*check all sub-areas to which driver they belong*/
#if (MEMACC_LEGACY_DRIVER_SUPPORT == STD_ON)
      if(MemAcc_BlankCheckApisAvailable(AddressAreaCfgIdx, TargetAddress, Length))
#endif /* MEMACC_LEGACY_DRIVER_SUPPORT */
      {
        MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobType = MEMACC_BLANKCHECK_JOB;
        MemAcc_InsertInQueue(AddressAreaCfgIdx);
        /* !LINKSTO MemAcc.SWS_MemAcc_00008, 1*/
        MemAcc_AddDeviceRequest(AddressAreaCfgIdx, TargetAddress, NULL_PTR, Length);
      }
#if (MEMACC_LEGACY_DRIVER_SUPPORT == STD_ON)
      else
      {
        Result = MEMACC_MEM_SERVICE_NOT_AVAIL;
      }
#endif /* MEMACC_LEGACY_DRIVER_SUPPORT */
    }
    else
    {
      /* Invalid parameters, return NOK to caller*/
    }
  }
  else
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00062, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(MEMACC_BLANK_CHECK_API_ID, MEMACC_E_UNINIT);
#endif
  }

  DBG_MEMACC_BLANKCHECK_EXIT(Result, AddressAreaId, TargetAddress, Length);
  return Result;
}

/*--------------------------[MemAcc_GetDriverJobResult]---------------------------------------*/
STATIC FUNC(Mem_JobResultType, MEMACC_CODE) MemAcc_GetDriverJobResult(
  MemAcc_AddressAreaIdType AddressAreaCfgIdx,
  MemAcc_AddressAreaIdType SubAreaIdx
  )
{
  Mem_JobResultType  MemJobResult = MEM_JOB_FAILED;
  MemAcc_HwIdType HwIdx = MemAcc_AddressAreas[AddressAreaCfgIdx].SubAreaCfg[SubAreaIdx].DrvHwId;
#if (MEMACC_LEGACY_DRIVER_SUPPORT == STD_ON)
  MemAcc_MemInvocationType DrvInvocationType = MemAcc_MemoryDevicesInfo[HwIdx].DrvInvocationType;
  MemIf_JobResultType MemIfJobResult;
  if(DrvInvocationType == DIRECT_LEGACY)
  {
    MemIfJobResult = ((const MemAcc_MemApi_LegacyType*)MemAcc_MemoryDevicesInfo[HwIdx].DrvApiTable)->GetJobResult();
    switch (MemIfJobResult)
    {
    case MEMIF_JOB_OK:
      MemJobResult = MEM_JOB_OK;
      break;
    case MEMIF_JOB_PENDING:
      MemJobResult = MEM_JOB_PENDING;
      break;
    case MEMIF_BLOCK_INCONSISTENT:
      MemJobResult = MEM_INCONSISTENT;
      break;
    case MEMIF_JOB_FAILED:
      MemJobResult = MEM_JOB_FAILED;
      break;
    default:
      MemJobResult = MEM_JOB_FAILED;
      break;
    }
  }
  else
#endif /* MEMACC_LEGACY_DRIVER_SUPPORT */
  {

#if (MEMACC_MEM_DRIVER_SUPPORT == STD_ON)
    MemJobResult = ((const MemAcc_MemApi_Type*)MemAcc_MemoryDevicesInfo[HwIdx].DrvApiTable)->GetJobResult(MemAcc_MemoryDevicesInfo[HwIdx].MemInstanceId);
#endif /* MEMACC_MEM_DRIVER_SUPPORT */
  }
  return MemJobResult;
}
/*--------------------------[MemAcc_GetOngoingJobResults]---------------------------------------*/
STATIC FUNC(void, MEMACC_CODE) MemAcc_GetOngoingJobResults(void)
{
  MemAcc_AddressAreaIdType SearchQueueIdx;
  MemAcc_AddressAreaIdType AddressAreaCfgIdx;

  for(SearchQueueIdx = 0; SearchQueueIdx < QueueElementsNo; SearchQueueIdx++)
  {
    /* There is not check for MEMACC_QUEUE_INVALID_AREA_INDEX, as all elements in the queue have a valid index */
    AddressAreaCfgIdx = MemAcc_AreaIdQueue[SearchQueueIdx].AddressAreaCfgIdx;

    if(MemAcc_AdminAddressArea[AddressAreaCfgIdx].SubAreaAdmin.JobState == MEMACC_INPROGRESS)
    {
      MemAcc_AdminAddressArea[AddressAreaCfgIdx].SubAreaAdmin.MemDrvJobResult
      = MemAcc_GetDriverJobResult(AddressAreaCfgIdx, MemAcc_AdminAddressArea[AddressAreaCfgIdx].SubAreaIdx);
    }

  }
}


/*--------------------------[MemAcc_TriggerJob]---------------------------------------*/
STATIC FUNC(Std_ReturnType, MEMACC_CODE) MemAcc_TriggerJob
(
  MemAcc_AddressAreaIdType AddressAreaCfgIdx,
  MemAcc_AddressAreaIdType SubAreaIdx
)
{
  Std_ReturnType Result = E_NOT_OK;
  MemAcc_HwIdType HwIdx = MemAcc_AddressAreas[AddressAreaCfgIdx].SubAreaCfg[SubAreaIdx].DrvHwId;
  MemAcc_AddressSubAreaAdminType * const SubAreaAdminPtr = &MemAcc_AdminAddressArea[AddressAreaCfgIdx].SubAreaAdmin;
#if ( (MEMACC_WRITE_BURST_SUPPORT == STD_ON) \
    ||(MEMACC_ERASE_BURST_SUPPORT == STD_ON) \
    )
  const MemAcc_AddressSubAreaType * const SubAreaCfgPtr = &MemAcc_AddressAreas[AddressAreaCfgIdx].SubAreaCfg[SubAreaIdx];
#endif
  const MemAcc_SectorBatchType * const SectorBatchCfgPtr = MemAcc_AddressAreas[AddressAreaCfgIdx].SubAreaCfg[SubAreaIdx].SectorBatch;
  MemAcc_LengthType ProcessingLength = 0;
  MemAcc_DataType *ReadDataPtr;
  /* Trigger the lower layer based on the Job, Burst and Legacy support */
  switch(MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobType)
  {
    case MEMACC_READ_JOB:
#if (MEMACC_COMPARE_API == STD_ON)
    case MEMACC_COMPARE_JOB: /* An intended fall through as the behavior of compare and read is the same  interaction with drivers */
      if(MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobType == MEMACC_COMPARE_JOB)
      {
        ReadDataPtr = MemAcc_AddressAreas[AddressAreaCfgIdx].AddressAreaCmpBuffer;
      }
      else
#endif
      {
        /* Deviation MISRAC2012-1, MGCC62-1 */
        ReadDataPtr = (MemAcc_DataType *)SubAreaAdminPtr->UserDataPtr;
      }

      ProcessingLength = MemAcc_GetReadChunkSize(AddressAreaCfgIdx,SubAreaIdx);

#if (MEMACC_LEGACY_DRIVER_SUPPORT == STD_ON)
      if(MemAcc_MemoryDevicesInfo[HwIdx].DrvInvocationType == DIRECT_LEGACY)
      {
        Result = ((const MemAcc_MemApi_LegacyType*)MemAcc_MemoryDevicesInfo[HwIdx].DrvApiTable)->Read(
                                  SubAreaAdminPtr->JobPhysicalStartAddress,
                                  ReadDataPtr,
                                  ProcessingLength);
      }
      else
#endif /* MEMACC_LEGACY_DRIVER_SUPPORT */
      {
#if (MEMACC_MEM_DRIVER_SUPPORT == STD_ON)
        Result = ((const MemAcc_MemApi_Type*)MemAcc_MemoryDevicesInfo[HwIdx].DrvApiTable)->Read(
                                  MemAcc_MemoryDevicesInfo[HwIdx].MemInstanceId,
                                  SubAreaAdminPtr->JobPhysicalStartAddress,
                                  ReadDataPtr,
                                  ProcessingLength);
#endif /* MEMACC_MEM_DRIVER_SUPPORT */
      }
      break;
    case MEMACC_WRITE_JOB:
#if (MEMACC_WRITE_BURST_SUPPORT == STD_ON)
      /* !LINKSTO MemAcc.SWS_MemAcc_00102,1 */
      if(
          (SubAreaCfgPtr->UseWriteBurst)
          &&
          (
            MemAcc_AdminAddressArea[AddressAreaCfgIdx].SubAreaAdmin.RemainingLength
            >=
            SectorBatchCfgPtr->WritePageBurstSize
          )
        )
      {
        ProcessingLength = SectorBatchCfgPtr->WritePageBurstSize;
      }
      /* !LINKSTO MemAcc.MemoryAccess.Write.Page, 1 */
      else
#endif /* MEMACC_WRITE_BURST_SUPPORT */
      {
        ProcessingLength = SectorBatchCfgPtr->WritePageSize;
      }
#if (MEMACC_LEGACY_DRIVER_SUPPORT == STD_ON)
        if(MemAcc_MemoryDevicesInfo[HwIdx].DrvInvocationType == DIRECT_LEGACY)
        {
          Result = ((const MemAcc_MemApi_LegacyType*)MemAcc_MemoryDevicesInfo[HwIdx].DrvApiTable)->Write(
                                    SubAreaAdminPtr->JobPhysicalStartAddress,
                                    SubAreaAdminPtr->UserDataPtr,
                                    ProcessingLength);
        }
        else
#endif /* MEMACC_LEGACY_DRIVER_SUPPORT */
        {
#if (MEMACC_MEM_DRIVER_SUPPORT == STD_ON)
          Result = ((const MemAcc_MemApi_Type*)MemAcc_MemoryDevicesInfo[HwIdx].DrvApiTable)->Write(
                                    MemAcc_MemoryDevicesInfo[HwIdx].MemInstanceId,
                                    SubAreaAdminPtr->JobPhysicalStartAddress,
                                    SubAreaAdminPtr->UserDataPtr,
                                    ProcessingLength);
#endif /* MEMACC_MEM_DRIVER_SUPPORT */
        }
      break;
    case MEMACC_ERASE_JOB:
#if (MEMACC_ERASE_BURST_SUPPORT == STD_ON)
      /* !LINKSTO MemAcc.SWS_MemAcc_00087,1*/
      if(
          (SubAreaCfgPtr->UseEraseBurst)
          &&
          (
            MemAcc_AdminAddressArea[AddressAreaCfgIdx].SubAreaAdmin.RemainingLength
            >=
            SectorBatchCfgPtr->SectorBurstSize
          )
        )
      {
        ProcessingLength = SectorBatchCfgPtr->SectorBurstSize;
      }
      /* !LINKSTO MemAcc.MemoryAccess.Erase.Sector, 1 */
      else
#endif /* MEMACC_ERASE_BURST_SUPPORT */
      {
        ProcessingLength = SectorBatchCfgPtr->SectorSize;
      }
#if (MEMACC_LEGACY_DRIVER_SUPPORT == STD_ON)
        if(MemAcc_MemoryDevicesInfo[HwIdx].DrvInvocationType == DIRECT_LEGACY)
        {
          Result = ((const MemAcc_MemApi_LegacyType*)MemAcc_MemoryDevicesInfo[HwIdx].DrvApiTable)->Erase(
                                    SubAreaAdminPtr->JobPhysicalStartAddress,
                                    ProcessingLength);
        }
        else
#endif /* MEMACC_LEGACY_DRIVER_SUPPORT */
        {
#if (MEMACC_MEM_DRIVER_SUPPORT == STD_ON)
          Result = ((const MemAcc_MemApi_Type*)MemAcc_MemoryDevicesInfo[HwIdx].DrvApiTable)->Erase(
                                    MemAcc_MemoryDevicesInfo[HwIdx].MemInstanceId,
                                    SubAreaAdminPtr->JobPhysicalStartAddress,
                                    ProcessingLength);
#endif /* MEMACC_MEM_DRIVER_SUPPORT */
        }
    break;
    case MEMACC_BLANKCHECK_JOB:

      ProcessingLength = MemAcc_GetReadChunkSize(AddressAreaCfgIdx,SubAreaIdx);

#if (MEMACC_LEGACY_DRIVER_SUPPORT == STD_ON)
      if(MemAcc_MemoryDevicesInfo[HwIdx].DrvInvocationType == DIRECT_LEGACY)
      {
        Result = ((const MemAcc_MemApi_LegacyType*)MemAcc_MemoryDevicesInfo[HwIdx].DrvApiTable)->BlankCheck(
            SubAreaAdminPtr->JobPhysicalStartAddress,
            ProcessingLength);
      }
      else
#endif /* MEMACC_LEGACY_DRIVER_SUPPORT */
      {
#if (MEMACC_MEM_DRIVER_SUPPORT == STD_ON)
        Result = ((const MemAcc_MemApi_Type*)MemAcc_MemoryDevicesInfo[HwIdx].DrvApiTable)->BlankCheck(
            MemAcc_MemoryDevicesInfo[HwIdx].MemInstanceId,
            SubAreaAdminPtr->JobPhysicalStartAddress,
            ProcessingLength);
#endif /* MEMACC_MEM_DRIVER_SUPPORT */
      }
      break;
/* CHECK: NOPARSE */
/* switching is done between fixed known job types, so default is not needed */
    default:
      /*Unknown job, result already set*/
      break;
/* CHECK: PARSE */
  }
  if(Result != E_NOT_OK)
  {
    MemAcc_AdminAddressArea[AddressAreaCfgIdx].LastActiveSubAreaIdx = SubAreaIdx;

    MemAcc_AdminAddressArea[AddressAreaCfgIdx].MemLength = ProcessingLength;
    MemAcc_AdminAddressArea[AddressAreaCfgIdx].RemainingLength -= ProcessingLength;

    SubAreaAdminPtr->RemainingLength -= ProcessingLength;
    SubAreaAdminPtr->JobPhysicalStartAddress += ProcessingLength;
    if(SubAreaAdminPtr->UserDataPtr != NULL_PTR)
    {
      SubAreaAdminPtr->UserDataPtr += ProcessingLength;
    }
    else
    {
      /*Job type without user data*/
    }
  }
  else
  {/*job not successfully triggered, no update of last active sub area index*/
  }
  return Result;
}


/*--------------------------[MemAcc_MainFunction]---------------------------------------*/
/* !LINKSTO MemAcc.Dsn.Interfaces.MainFunction, 1*/
FUNC(void, MEMACC_CODE) MemAcc_MainFunction (void)
{
  MemAcc_AddressAreaIdType SearchIdx;
  MemAcc_AddressAreaIdType AddressAreaCfgIdx;
  #if(MEMACC_HANDLING_SUPPORT == STD_ON)
  MemAcc_HwIdType HwIdx;
  MemAcc_MemInstanceIdType InstanceIdx;
  #endif

  DBG_MEMACC_MAINFUNCTION_ENTRY();

  /*Step1: Get Job Results for jobs triggered in the previous cycle*/
  /* Optimization potential: if driver would also have some storage to handle owner change,
   * no double checking of status;
   * we could process the prev results while processing the new queue state tbd
   */
  MemAcc_GetOngoingJobResults();
  /*Step2: Go through all pending AreaId jobs and trigger sub-area jobs*/
  for(SearchIdx = 0; SearchIdx < QueueElementsNo; SearchIdx++)
  {
    MemAcc_AreaJobStateMachine(MemAcc_AreaIdQueue[SearchIdx].AddressAreaCfgIdx);
  }
  /*Step3: Remove from queue all completed jobs*/
  for(SearchIdx = QueueElementsNo; SearchIdx > 0U; SearchIdx--)
  {
    MemAcc_AddressAreaIdType QueueIdx = SearchIdx - 1U;
    AddressAreaCfgIdx = MemAcc_AreaIdQueue[QueueIdx].AddressAreaCfgIdx;
    if(MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobStatus != MEMACC_JOB_PENDING)
    {
      MemAcc_DequeueElement(AddressAreaCfgIdx);
      MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobCancelRequested = FALSE;
      if(MemAcc_AddressAreas[AddressAreaCfgIdx].AddressAreaCallback != NULL_PTR)
      {
        /* !LINKSTO MemAcc.SWS_MemAcc_00015, 1*/
        /* !LINKSTO MemAcc.Dsn.Interaction.Cbk.CancelFinishedJob, 1*/
        (void)MemAcc_AddressAreas[AddressAreaCfgIdx].AddressAreaCallback(AddressAreaCfgIdx, MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobResult);
      }
    }
  }

  DBG_MEMACC_MAINFUNCTION_EXIT();
}

/*--------------------------[MemAcc_Cancel]---------------------------------------*/
/* !LINKSTO MemAcc.Dsn.Interfaces.Cancel, 1*/
FUNC(void, MEMACC_CODE) MemAcc_Cancel (MemAcc_AddressAreaIdType AddressAreaId)
{
  MemAcc_AddressAreaIdType AddressAreaCfgIdx;

  DBG_MEMACC_CANCEL_ENTRY(AddressAreaId);

  if(MemAcc_InitStatus)
  {
    AddressAreaCfgIdx = MemAcc_GetAddressAreaConfigIndex(AddressAreaId);

    if(AddressAreaCfgIdx == MEMACC_INVALID_ADDRESSAREA)
    {
      /* !LINKSTO MemAcc.SWS_MemAcc_00031, 1*/
  #if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
      MEMACC_DET_REPORT_ERROR(MEMACC_CANCEL_API_ID,MEMACC_E_PARAM_ADDRESS_AREA_ID);
  #endif
    }
    else if(MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobStatus != MEMACC_JOB_PENDING)
    {
      /* !LINKSTO MemAcc.SWS_MemAcc_00029, 1*/
      /*Nothing to do if job ended*/
    }
    else
    {
      /* !LINKSTO MemAcc.SWS_MemAcc_00028, 1*/
      MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobCancelRequested = TRUE;
    }
  }
  else
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00030, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(MEMACC_CANCEL_API_ID, MEMACC_E_UNINIT);
#endif
  }

  DBG_MEMACC_CANCEL_EXIT(AddressAreaId);
}


/*--------------------------[MemAcc_GetJobResult]---------------------------------------*/
/* !LINKSTO MemAcc.Dsn.Interfaces.GetJobResult, 1*/
FUNC(MemAcc_JobResultType, MEMACC_CODE) MemAcc_GetJobResult(MemAcc_AddressAreaIdType AddressAreaId)
{
  MemAcc_JobResultType Result = MEMACC_MEM_FAILED;
  MemAcc_AddressAreaIdType AddressAreaCfgIdx;

  DBG_MEMACC_GETJOBRESULT_ENTRY(AddressAreaId);
  if(MemAcc_InitStatus)
  {
    AddressAreaCfgIdx = MemAcc_GetAddressAreaConfigIndex(AddressAreaId);

    if(AddressAreaCfgIdx == MEMACC_INVALID_ADDRESSAREA)
    {
      /* !LINKSTO MemAcc.SWS_MemAcc_00034, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
      MEMACC_DET_REPORT_ERROR(MEMACC_GET_JOB_RESULT_API_ID,MEMACC_E_PARAM_ADDRESS_AREA_ID);
#endif
    }
    else
    {
      /* !LINKSTO MemAcc.Dsn.Interaction.Polling.JobResult, 1*/
      Result = MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobResult;
    }
  }
  else
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00033, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(MEMACC_GET_JOB_RESULT_API_ID,MEMACC_E_UNINIT);
#endif
  }

  DBG_MEMACC_GETJOBRESULT_EXIT(Result, AddressAreaId);
  return Result;
}
/*--------------------------[MemAcc_GetJobStatus]---------------------------------------*/
/* !LINKSTO MemAcc.Dsn.Interfaces.GetJobStatus, 1*/
FUNC(MemAcc_JobStatusType, MEMACC_CODE) MemAcc_GetJobStatus(MemAcc_AddressAreaIdType AddressAreaId)
{
  MemAcc_JobStatusType Result = MEMACC_JOB_IDLE;
  MemAcc_AddressAreaIdType AddressAreaCfgIdx;

  DBG_MEMACC_GETJOBSTATUS_ENTRY(AddressAreaId);
  if(MemAcc_InitStatus)

  {
    AddressAreaCfgIdx = MemAcc_GetAddressAreaConfigIndex(AddressAreaId);

    if(AddressAreaCfgIdx == MEMACC_INVALID_ADDRESSAREA)
    {
      /* !LINKSTO MemAcc.EB.GetJobStatus.InvalidAddressAreaId, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
      MEMACC_DET_REPORT_ERROR(MEMACC_GET_JOB_STATUS_API_ID,MEMACC_E_PARAM_ADDRESS_AREA_ID);
#endif
    }
    else
    {
      /* !LINKSTO MemAcc.SWS_MemAcc_00118, 1*/
      /* !LINKSTO MemAcc.SWS_MemAcc_00119, 1*/
      Result = MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobStatus;
    }
  }
  else
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00117, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(MEMACC_GET_JOB_STATUS_API_ID,MEMACC_E_UNINIT);
#endif
  }

  DBG_MEMACC_GETJOBSTATUS_EXIT(Result,AddressAreaId);
  return Result;
}
/*--------------------------[MemAcc_ValidateGetMemoryInfoParams]---------------------------------------*/
STATIC FUNC(Std_ReturnType, MEMACC_CODE) MemAcc_ValidateGetMemoryInfoParams
(
  MemAcc_AddressAreaIdType AddressAreaCfgIdx,
  MemAcc_AddressType Address,
  MemAcc_MemoryInfoType* MemoryInfoPtr)
{
  Std_ReturnType Result = E_NOT_OK;

  DBG_MEMACC_VALIDATEGETMEMORYINFOPARAMS_ENTRY(AddressAreaCfgIdx, Address, MemoryInfoPtr);

  if(AddressAreaCfgIdx == MEMACC_INVALID_ADDRESSAREA)
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00036, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(MEMACC_GET_MEMORY_INFO_API_ID, MEMACC_E_PARAM_ADDRESS_AREA_ID);
#endif
  }
  else if(MemoryInfoPtr == NULL_PTR)
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00037, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(MEMACC_GET_MEMORY_INFO_API_ID, MEMACC_E_PARAM_POINTER);
#endif
  }
  else if(MEMACC_REQUEST_PARAM_OFFSET_INVALID(AddressAreaCfgIdx, Address))
  {
    /* !LINKSTO MemAcc.EB.GetMemoryInfo.InvalidAddress, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(MEMACC_GET_MEMORY_INFO_API_ID, MEMACC_E_PARAM_ADDRESS_LENGTH);
#endif
  }
  else
  {
    Result = E_OK;
  }

  DBG_MEMACC_VALIDATEGETMEMORYINFOPARAMS_EXIT(Result, AddressAreaCfgIdx, Address, MemoryInfoPtr);
  return Result;
}

/*--------------------------[MemAcc_GetMemoryInfo]---------------------------------------*/
/* !LINKSTO MemAcc.Dsn.Interfaces.GetMemoryInfo, 1*/
FUNC(Std_ReturnType, MEMACC_CODE) MemAcc_GetMemoryInfo
(
  MemAcc_AddressAreaIdType AddressAreaId,
  MemAcc_AddressType Address,
  MemAcc_MemoryInfoType* MemoryInfoPtr
)
{
  Std_ReturnType Result = E_NOT_OK;
  MemAcc_AddressAreaIdType AddressAreaCfgIdx;
  MemAcc_AddressAreaIdType SubAreaIdx;

  const MemAcc_SectorBatchType* SectorBatchCfgPtr;
  const MemAcc_AddressSubAreaType* SubAreaCfgPtr;

  DBG_MEMACC_GETMEMORYINFO_ENTRY(AddressAreaId, Address, MemoryInfoPtr);

  if(MemAcc_InitStatus)
  {
      AddressAreaCfgIdx = MemAcc_GetAddressAreaConfigIndex(AddressAreaId);
      Result = MemAcc_ValidateGetMemoryInfoParams(AddressAreaCfgIdx, Address, MemoryInfoPtr);

      if(Result == E_OK)
      {
        SubAreaIdx = MemAcc_FindLogicalAddressSubarea(AddressAreaCfgIdx, Address);

        SubAreaCfgPtr = &MemAcc_AddressAreas[AddressAreaCfgIdx].SubAreaCfg[SubAreaIdx];
        SectorBatchCfgPtr = MemAcc_AddressAreas[AddressAreaCfgIdx].SubAreaCfg[SubAreaIdx].SectorBatch;
        MemoryInfoPtr->LogicalStartAddress=SubAreaCfgPtr->LogicalStartAddress;
        MemoryInfoPtr->PhysicalStartAddress=SubAreaCfgPtr->PhysicalStartAddress;
        MemoryInfoPtr->MaxOffset= (SubAreaCfgPtr->Length - 1U);
        MemoryInfoPtr->EraseSectorSize=SectorBatchCfgPtr->SectorSize;
        MemoryInfoPtr->ReadPageSize=SectorBatchCfgPtr->ReadPageSize;
        MemoryInfoPtr->WritePageSize=SectorBatchCfgPtr->WritePageSize;
        MemoryInfoPtr->HwId=SubAreaCfgPtr->DrvHwId;

    #if (MEMACC_ERASE_BURST_SUPPORT == STD_ON)
        MemoryInfoPtr->EraseSectorBurstSize=SectorBatchCfgPtr->SectorBurstSize;
    #else
        MemoryInfoPtr->EraseSectorBurstSize=SectorBatchCfgPtr->SectorSize;
    #endif

    #if (MEMACC_READ_BURST_SUPPORT == STD_ON)
        MemoryInfoPtr->ReadPageBurstSize=SectorBatchCfgPtr->ReadPageBurstSize;
    #else
        MemoryInfoPtr->ReadPageBurstSize=SectorBatchCfgPtr->ReadPageSize;
    #endif

    #if (MEMACC_WRITE_BURST_SUPPORT == STD_ON)
        MemoryInfoPtr->WritePageBurstSize=SectorBatchCfgPtr->WritePageBurstSize;
    #else
        MemoryInfoPtr->WritePageBurstSize=SectorBatchCfgPtr->WritePageSize;
    #endif
      }
  }
  else
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00035, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(MEMACC_GET_MEMORY_INFO_API_ID,MEMACC_E_UNINIT);
#endif
  }

  DBG_MEMACC_GETMEMORYINFO_EXIT(Result, AddressAreaId, Address, MemoryInfoPtr);

  return Result;
}


/*--------------------------[MemAcc_GetProcessedLength]---------------------------------------*/
/* !LINKSTO MemAcc.Dsn.Interfaces.GetProcessedLength , 1*/
FUNC(MemAcc_LengthType, MEMACC_CODE) MemAcc_GetProcessedLength
(
  MemAcc_AddressAreaIdType AddressAreaId
)
{
  MemAcc_LengthType ProcessedLength = 0;
  MemAcc_AddressAreaIdType AddressAreaCfgIdx;

  DBG_MEMACC_GETPROCESSEDLENGTH_ENTRY(AddressAreaId);

  if(MemAcc_InitStatus)
  {
    AddressAreaCfgIdx = MemAcc_GetAddressAreaConfigIndex(AddressAreaId);
    if(AddressAreaCfgIdx == MEMACC_INVALID_ADDRESSAREA)
    {
      /* !LINKSTO MemAcc.SWS_MemAcc_00039, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
      MEMACC_DET_REPORT_ERROR(MEMACC_GET_PROCESSED_LENGTH_API_ID, MEMACC_E_PARAM_ADDRESS_AREA_ID);
#endif
    }
    else
    {
      /* !LINKSTO MemAcc.SWS_MemAcc_00120, 1*/
      if(MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobLength > 0U)
      {
        ProcessedLength = MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobLength - MemAcc_AdminAddressArea[AddressAreaCfgIdx].RemainingLength;
      }
      else
      {
        /*nothing to do, no job for area, ProcessedLength already set to 0 */
      }
    }
  }
  else
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00038, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(MEMACC_GET_PROCESSED_LENGTH_API_ID, MEMACC_E_UNINIT);
#endif
  }

  DBG_MEMACC_GETPROCESSEDLENGTH_EXIT(ProcessedLength, AddressAreaId);
  return ProcessedLength;
}


/*--------------------------------------[MemAcc_ValidateGetJobInfoParams]---------------------------------------*/
STATIC FUNC(Std_ReturnType, MEMACC_CODE) MemAcc_ValidateGetJobInfoParams
(
  MemAcc_AddressAreaIdType AddressAreaCfgIdx,
  MemAcc_JobInfoType* JobInfoPtr
)
{
  Std_ReturnType Result = E_NOT_OK;

  DBG_MEMACC_VALIDATEGETJOBINFOPARAMS_ENTRY(AddressAreaCfgIdx, JobInfoPtr);

  if(AddressAreaCfgIdx == MEMACC_INVALID_ADDRESSAREA)
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00041, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(MEMACC_GET_JOB_INFO_API_ID, MEMACC_E_PARAM_ADDRESS_AREA_ID);
#endif
  }
  else if(JobInfoPtr == NULL_PTR)
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00042, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(MEMACC_GET_JOB_INFO_API_ID, MEMACC_E_PARAM_POINTER);
#endif
  }
  else
  {
    Result = E_OK;
  }

  DBG_MEMACC_VALIDATEGETJOBINFOPARAMS_EXIT(Result, AddressAreaCfgIdx, JobInfoPtr);
  return Result;
}
/*--------------------------[MemAcc_GetJobInfo]---------------------------------------*/
/* !LINKSTO MemAcc.Dsn.Interfaces.GetJobInfo, 1*/
FUNC(void, MEMACC_CODE) MemAcc_GetJobInfo
(
  MemAcc_AddressAreaIdType AddressAreaId,
  MemAcc_JobInfoType* JobInfoPtr
)
{
  MemAcc_AddressAreaIdType AddressAreaCfgIdx;
  MemAcc_AddressAreaIdType SubAreaIdx;
  MemAcc_AddressSubAreaAdminType *SubAreaAdminPtr;
  const MemAcc_AddressSubAreaType * SubAreaCfgPtr;

  DBG_MEMACC_GETJOBINFO_ENTRY(AddressAreaId,JobInfoPtr);

  if(MemAcc_InitStatus == FALSE)
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00040, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(MEMACC_GET_JOB_INFO_API_ID, MEMACC_E_UNINIT);
#endif
  }
  else
  {
    AddressAreaCfgIdx = MemAcc_GetAddressAreaConfigIndex(AddressAreaId);

    if(MemAcc_ValidateGetJobInfoParams(AddressAreaCfgIdx, JobInfoPtr) == E_OK)
    {
      JobInfoPtr->LogicalAddress = MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobLogicalAddress;
      JobInfoPtr->Length = MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobLength;
      JobInfoPtr->CurrentJob = MemAcc_AdminAddressArea[AddressAreaCfgIdx].JobType;
      if( MemAcc_AdminAddressArea[AddressAreaCfgIdx].MemLength > 0U )
      {
        SubAreaIdx = MemAcc_AdminAddressArea[AddressAreaCfgIdx].LastActiveSubAreaIdx;
        SubAreaAdminPtr = &MemAcc_AdminAddressArea[AddressAreaCfgIdx].SubAreaAdmin;
        SubAreaCfgPtr = &MemAcc_AddressAreas[AddressAreaCfgIdx].SubAreaCfg[SubAreaIdx];
        JobInfoPtr->MemAddress = (SubAreaAdminPtr->JobPhysicalStartAddress - MemAcc_AdminAddressArea[AddressAreaCfgIdx].MemLength);
        JobInfoPtr->MemLength = MemAcc_AdminAddressArea[AddressAreaCfgIdx].MemLength;
        JobInfoPtr->HwId = SubAreaCfgPtr->DrvHwId;
        JobInfoPtr->MemInstanceId = MemAcc_MemoryDevicesInfo[SubAreaCfgPtr->DrvHwId].MemInstanceId;

        if(SubAreaAdminPtr->JobState==MEMACC_INPROGRESS)
        {
          /* !LINKSTO MemAcc.EB.MemoryAccess.GetJobInfo.ActiveJob, 1*/
          JobInfoPtr->MemResult = MemAcc_GetDriverJobResult(AddressAreaCfgIdx, SubAreaIdx);
        }
        else
        {
          /* !LINKSTO MemAcc.EB.MemoryAccess.GetJobInfo.InactiveJob, 1*/
          JobInfoPtr->MemResult = SubAreaAdminPtr->MemDrvJobResult;
        }
      }
      else
      {
        JobInfoPtr->MemAddress = 0;
        JobInfoPtr->MemLength = 0;
        JobInfoPtr->MemResult = MEM_JOB_OK;
        JobInfoPtr->HwId = 0;
        JobInfoPtr->MemInstanceId = 0;
      }
    }
  }

  DBG_MEMACC_GETJOBINFO_EXIT(AddressAreaId,JobInfoPtr);

}

#if (MEMACC_VERSION_INFO_API == STD_ON)
/*--------------------------[MemAcc_GetVersionInfo]---------------------------------------*/
/* !LINKSTO MemAcc.Dsn.Interfaces.GetVersionInfo, 1*/
FUNC(void, MEMACC_CODE) MemAcc_GetVersionInfo (Std_VersionInfoType *VersionInfoPtr)
{
  DBG_MEMACC_GETVERSIONINFO_ENTRY(VersionInfoPtr);

  if(VersionInfoPtr == NULL_PTR)
  {
    /* !LINKSTO MemAcc.SWS_MemAcc_00027, 1*/
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    MEMACC_DET_REPORT_ERROR(MEMACC_GET_VERSION_INFO_API_ID, MEMACC_E_PARAM_POINTER);
#endif
  }
  else
  {
    VersionInfoPtr->vendorID = MEMACC_VENDOR_ID;
    VersionInfoPtr->moduleID = MEMACC_MODULE_ID;
    VersionInfoPtr->sw_major_version = MEMACC_SW_MAJOR_VERSION;
    VersionInfoPtr->sw_minor_version = MEMACC_SW_MINOR_VERSION;
    VersionInfoPtr->sw_patch_version = MEMACC_SW_PATCH_VERSION;
  }
  DBG_MEMACC_GETVERSIONINFO_ENTRY(VersionInfoPtr);
}
#endif


#define MEMACC_STOP_SEC_CODE
#include <MemAcc_MemMap.h>
/*==================[end of file]===========================================*/
