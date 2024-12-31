#ifndef DEM_CALLOUTS_H
#define DEM_CALLOUTS_H 1

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
	This file implements the different services provided by the DemIf module.

******************************************************************************/
/*
$Revision: 1.7 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/DemIf/Implementation/inc/project.pj $
*/

/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Dem_Types.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/

/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
#define DemIf_START_SEC_CODE
#include "DemIf_MemMap.h"

extern void Dem_Callback_EventStatusChanged(const Dem_EventIdType cEventId, const Dem_DTCStatusMaskType cOldDTCStatusMask, const Dem_DTCStatusMaskType cNewDTCStatusMask);
extern void Dem_GetEventDebounceTime (const Dem_EventIdType ku16EventId, uint16 * pu16DebounceTime);
#define DemIf_STOP_SEC_CODE
#include "DemIf_MemMap.h"

/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif    /* DEM_CALLOUTS_H */
