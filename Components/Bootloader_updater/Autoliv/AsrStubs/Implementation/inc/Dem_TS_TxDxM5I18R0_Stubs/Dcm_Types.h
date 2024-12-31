#if (!defined DCM_TYPES_H)
#define DCM_TYPES_H

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
   This file contains the DCM specific configuration.

******************************************************************************/
/*
$Revision: 1.1 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader_updater/Autoliv/AsrStubs/Implementation/inc/Dem_TS_TxDxM5I18R0_Stubs/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include <ComStack_Types.h>

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/
/**
 *\brief
 *       DCM Operation Status Type
 *
 */
typedef uint8 Dcm_OpStatusType;
/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/
/**
 *\brief
 *       Constant with external linkage.
 *
 */
#define EBSTUBS_START_SEC_CODE
#include <MemMap.h>
/**
 *\brief
 *       Constant with external linkage.
 *
 */
#define EBSTUBS_STOP_SEC_CODE
#include <MemMap.h>
/**
 *\brief
 *       Constant with external linkage.
 *
 */
#define EBSTUBS_START_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

/**
 *\brief
 *       Constant with external linkage.
 *
 */
#define EBSTUBS_STOP_SEC_VAR_UNSPECIFIED
#include <MemMap.h>

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/
#endif /* !defined DCM_TYPES_H */
