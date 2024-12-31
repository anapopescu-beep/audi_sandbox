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
$Revision: 1.1 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader_updater/Autoliv/AsrStubs/Implementation/inc/Dem_TS_TxDxM5I18R0_Stubs/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include <Dem_StubCfg.h>
#include <Std_Types.h>

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/* Dem_EventStatusType */
#define DEM_EVENT_STATUS_PASSED 0x00U
#define DEM_EVENT_STATUS_FAILED 0x01U
#define DEM_EVENT_STATUS_PREFAILED 0x03U
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
typedef struct
{
   uint8 Dummy;
} Dem_ConfigType;

typedef uint16 Dem_EventIdType;

typedef uint8 Dem_EventStatusType;

typedef uint8 Dem_EventStatusExtendedType;

typedef uint8 Dem_OperationCycleStateType;

typedef uint8 Dem_IndicatorStatusType;

typedef uint32 Dem_DTCGroupType;

typedef uint8 Dem_DTCKindType;

typedef uint8 Dem_DTCFormatType;

typedef uint8 Dem_DTCOriginType;

typedef uint8 Dem_DTCRequestType;

typedef uint8 Dem_DTCTranslationFormatType;

typedef uint8 Dem_DTCSeverityType;

typedef uint8 Dem_FilterForFDCType;

typedef uint8 Dem_FilterWithSeverityType;

typedef uint16 Dem_RatioIdType;

typedef uint8 Dem_ReturnSetFilterType;

typedef uint8 Dem_ReturnGetStatusOfDTCType;

typedef uint8 Dem_ReturnGetNextFilteredDTCType;

typedef uint8 Dem_ReturnGetNumberOfFilteredDTCType;

typedef uint8 Dem_ReturnClearDTCType;

typedef uint8 Dem_ReturnControlDTCSettingType;

typedef uint8 Dem_ReturnDisableDTCRecordUpdateType;

typedef uint8 Dem_ReturnGetFreezeFrameDataByRecordType;

typedef uint8 Dem_ReturnGetExtendedDataRecordByDTCType;

typedef uint8 Dem_ReturnGetDTCByOccurrenceTimeType;

typedef uint8 Dem_ReturnGetFreezeFrameDataByDTCType;

typedef uint8 Dem_ReturnGetSizeOfExtendedDataRecordByDTCType;

typedef uint8 Dem_ReturnGetSizeOfFreezeFrameByDTCType;

typedef uint8 Dem_ReturnGetSeverityOfDTCType;

typedef uint8 Dem_ReturnGetFunctionalUnitOfDTCType;

typedef uint8 Dem_DataKindType;

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
