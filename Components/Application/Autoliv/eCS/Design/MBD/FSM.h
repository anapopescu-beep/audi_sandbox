#ifndef FSM_H
#define FSM_H
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
   The header includes the common defines of all FSM source files and the 
   exported functions used between source files.

******************************************************************************/
/*
$Revision: 1.1 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/eCS/Design/MBD/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "common.h"
#include "Rte_Type.h"
#include "FSM_Config.h"

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
/**
 *\brief
 *     This variable holds the state of each solenoid
 */
extern uint8 FSM_au8SolenoidStates[KU8_MAX_SOLENOID_NB];

/**
* \brief
*       Used to store each solenoid's Initialization status in a bit mask
*
* \initialization
*       KU8_ZERO (uint8 0x00)
*
* \range
*       0...255;
*/
extern uint8 FSM_u8SolenoidInitState;

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
#define FSM_START_SEC_CODE_ASIL_A
#include "FSM_MemMap.h"

extern void FSM_Init(void);
extern void FSM_ModesInit(void);

#define FSM_STOP_SEC_CODE_ASIL_A
#include "FSM_MemMap.h"
/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* FSM_H */
