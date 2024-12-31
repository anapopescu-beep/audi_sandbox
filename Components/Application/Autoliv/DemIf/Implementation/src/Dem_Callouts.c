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
/*
$Revision: 1.12 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/DemIf/Implementation/src/project.pj $
*/

/*!****************************************************************************

details
   This file defines the function "Dem_Callback_EventStatusChanged",
   used to notify other system components of changes in an event's status. 
   
******************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Dem_Callouts.h"
#include "Rte_Dem.h"
#include "common.h"
#include "Dem_Int.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/

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
Private Functions
******************************************************************************/

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
#define DemIf_START_SEC_CODE
#include "DemIf_MemMap.h"

/**
* \brief
*      Callout to change event status for triggered events.
* \inputparam
*      Name: cEventId
*      Type: const Dem_EventIdType (uint16)
*      Description: The Id of event to change.
*      Range: None
* \inputparam
*      Name: cOldDTCStatusMask
*      Type: const Dem_DTCStatusMaskType (uint8)
*      Description: Old status of event.
*      Range: None
* \inputparam
*      Name: cNewDTCStatusMask
*      Type: const Dem_DTCStatusMaskType (uint8)
*      Description: New status of event.
*      Range: None
* \constrains
*      None.
* \dynamicaspectcaller
*     This function is not called.
* \dynamicaspectdescription
*     .
* \ddesignrequirement
*      DSG_DEM_Callback_EventStatusChange
* \archrequirement
*      ARCH_SW_DemIf_ptrpAsrDemServices
**/
EXPORTED void Dem_Callback_EventStatusChanged(const Dem_EventIdType cEventId, const Dem_DTCStatusMaskType cOldDTCStatusMask, const Dem_DTCStatusMaskType cNewDTCStatusMask)
{
   (void) cEventId;
   (void) cOldDTCStatusMask;
   (void) cNewDTCStatusMask;
}

/**
* \brief
*      Callout to get event status for debounce time event.
* \inputparam
*      Name: ku16EventId
*      Type: const Dem_EventIdType (uint16)
*      Description: The Id of event to change.
*      Range: None
* \outputparam
*      Name: pu16DebounceTime
*      Type: uint16
*      Description: Event status.
*      Range: None
* \constrains
*      None.
* \dynamicaspectcaller
*     This function is not called.
* \dynamicaspectdescription
*     .
* \ddesignrequirement
*      DSG_DEM_Dem_GetEventDebounceTime
* \archrequirement
*      ARCH_SW_Dem_GetEventDebounceTime
**/
EXPORTED void Dem_GetEventDebounceTime(const Dem_EventIdType ku16EventId, uint16 * pu16DebounceTime)
{
   *pu16DebounceTime = (KU16_MAX - (uint16)Dem_DebounceCounterClass[Dem_DebounceCounterClassIdx[ku16EventId - KU16_ONE]].CounterPassedThreshold) + KU16_ONE;
}

#define DemIf_STOP_SEC_CODE
#include "DemIf_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
