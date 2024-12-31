#if (!defined DEM_TYPES_H)
#define DEM_TYPES_H
/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------------------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
H-File Template Version:
Template version: AEM_PROCESS_1.25.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2022-09
*******************************************************************************

Overview of the interfaces:
   This file contains the implementation of the AUTOSAR module Demo_DAG.

******************************************************************************/
/*
$Revision: 1.3 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader/Autoliv/FblUsr/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include <Std_Types.h>

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/* Dem_EventStatusType */
/**
 *\brief
 *       Passed status for Dem events.
 *
 */
#define DEM_EVENT_STATUS_PASSED 0x00U
/**
 *\brief
 *       Failed status for Dem events.
 *
 */
#define DEM_EVENT_STATUS_FAILED 0x01U
/**
 *\brief
 *       Prefailed status for Dem events.
 *
 */
#define DEM_EVENT_STATUS_PREFAILED 0x03U
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 *\brief
 *       Dem Config Type.
 *
 */
typedef struct
{
   uint8 Dummy;
} Dem_ConfigType;

/**
 *\brief
 *       Dem Event Type.
 *
 */
typedef uint16 Dem_EventIdType;
/**
 *\brief
 *       Dem Event Status Type.
 *
 */
typedef uint8 Dem_EventStatusType;
/**
 *\brief
 *       Dem Event Status Extended Type.
 *
 */
typedef uint8 Dem_EventStatusExtendedType;
/**
 *\brief
 *       Dem Operation Cycle State Type.
 *
 */
typedef uint8 Dem_OperationCycleStateType;
/**
 *\brief
 *       Dem Operation Indicator Status Type.
 *
 */
typedef uint8 Dem_IndicatorStatusType;
/**
 *\brief
 *       Dem DTC Group Type.
 *
 */
typedef uint32 Dem_DTCGroupType;
/**
 *\brief
 *       Dem DTC Kind Type.
 *
 */
typedef uint8 Dem_DTCKindType;
/**
 *\brief
 *       Dem DTC Format Type.
 *
 */
typedef uint8 Dem_DTCFormatType;
/**
 *\brief
 *       Dem DTC Origin Type.
 *
 */
typedef uint8 Dem_DTCOriginType;
/**
 *\brief
 *       Dem DTC Request Type.
 *
 */
typedef uint8 Dem_DTCRequestType;
/**
 *\brief
 *       Dem DTC Translation Format Type.
 *
 */
typedef uint8 Dem_DTCTranslationFormatType;
/**
 *\brief
 *       Dem DTC Severity Type.
 *
 */
typedef uint8 Dem_DTCSeverityType;
/**
 *\brief
 *       Dem Filter for DTC Type.
 *
 */
typedef uint8 Dem_FilterForFDCType;
/**
 *\brief
 *       Dem Filter with Severity Type.
 *
 */
typedef uint8 Dem_FilterWithSeverityType;
/**
 *\brief
 *       Dem Ratio ID Type.
 *
 */
typedef uint16 Dem_RatioIdType;
/**
 *\brief
 *       Dem Return Set Filter Type.
 *
 */
typedef uint8 Dem_ReturnSetFilterType;
/**
 *\brief
 *       Dem Return Get Status of DTC Type.
 *
 */
typedef uint8 Dem_ReturnGetStatusOfDTCType;
/**
 *\brief
 *       Dem Return Get Next Filtered DTC Type.
 *
 */
typedef uint8 Dem_ReturnGetNextFilteredDTCType;
/**
 *\brief
 *       Dem Return Get Number Of Filtered DTC Type.
 *
 */
typedef uint8 Dem_ReturnGetNumberOfFilteredDTCType;
/**
 *\brief
 *       Dem Return Clear DTC Type.
 *
 */
typedef uint8 Dem_ReturnClearDTCType;
/**
 *\brief
 *       Dem Return Control DTC Setting Type.
 *
 */
typedef uint8 Dem_ReturnControlDTCSettingType;
/**
 *\brief
 *       Dem Return Disable DTC Record Update Type.
 *
 */
typedef uint8 Dem_ReturnDisableDTCRecordUpdateType;
/**
 *\brief
 *       Dem Return Get Freeze Frame Data By Record Type.
 *
 */
typedef uint8 Dem_ReturnGetFreezeFrameDataByRecordType;
/**
 *\brief
 *       Dem Return Get Extended Data Record By DTC Type.
 *
 */
typedef uint8 Dem_ReturnGetExtendedDataRecordByDTCType;
/**
 *\brief
 *       Dem Return Get DTC By Occurrence Time Type.
 *
 */
typedef uint8 Dem_ReturnGetDTCByOccurrenceTimeType;
/**
 *\brief
 *       Dem Return Get Freeze Frame Data By DTC Type.
 *
 */
typedef uint8 Dem_ReturnGetFreezeFrameDataByDTCType;
/**
 *\brief
 *       Dem Return Get Size Of Extended Data Record By DTC Type.
 *
 */
typedef uint8 Dem_ReturnGetSizeOfExtendedDataRecordByDTCType;
/**
 *\brief
 *       Dem Return Get Size Of Freeze Frame By DTC Type.
 *
 */
typedef uint8 Dem_ReturnGetSizeOfFreezeFrameByDTCType;
/**
 *\brief
 *       Dem Return Get Severity Of DTC Type.
 *
 */
typedef uint8 Dem_ReturnGetSeverityOfDTCType;
/**
 *\brief
 *       Dem Return Get Functional Unit Of DTC Type.
 *
 */
typedef uint8 Dem_ReturnGetFunctionalUnitOfDTCType;
/**
 *\brief
 *       Dem Data Kind Type.
 *
 */
typedef uint8 Dem_DataKindType;
/**
 *\brief
 *       Dem DTC Type.
 *
 */
typedef uint32 Dem_DTCType;

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
#define EBSTUBS_START_SEC_CODE
#include <MemMap.h>

#define EBSTUBS_STOP_SEC_CODE
#include <MemMap.h>

#define EBSTUBS_START_SEC_VAR_UNSPECIFIED
#include <MemMap.h>


#define EBSTUBS_STOP_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

/* stub extension header file */
#include <Dem_StubExt.h>
/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/
#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/
#endif /* !defined DEM_TYPES_H */
