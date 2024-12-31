#ifndef COMM_H
#define COMM_H
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
      This file defines the information (definitions) provided
by the module ComM, part of the component ComMIf

******************************************************************************/
/*
$Revision: 1.2 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader/Autoliv/ComMIf/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 *\brief
 *     No communication value.
 *
 */
#define COMM_NO_COMMUNICATION     0U
/**
 *\brief
 *     Silent communication value.
 *
 */
#define COMM_SILENT_COMMUNICATION 1U
/**
 *\brief
 *     Full communication value.
 *
 */
#define COMM_FULL_COMMUNICATION   2U
/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/
/**
 *\brief
 *     Communication type.
 *
 */
typedef uint8 ComM_ModeType;
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

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/
#endif /* COMM_H */

