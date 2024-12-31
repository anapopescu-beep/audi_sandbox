#ifndef _SAD_H_
#define _SAD_H_

/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
H-File Template Version:
Template version: AEM_PROCESS_1.25.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2022-09
******************************************************************************/
/**
 *    $Revision: 1.16 $
 *    $ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/SAD/Implementation/inc/project.pj $
 */

/**
 * \brief
 *    The SAD component is responsible for the control of the solenoid
 *    actuators and error detection
 */

/*!****************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "SAD_Config.h"

/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 *\brief
 *      Indicates the undefined value of a step
 */
#define KU8_SAD_UNDEFINED_STEP               ((uint8) 255)
/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/
extern uint8 SAD_u8SolenoidInfiniteStepReached;
extern uint8 SAD_u8SolenoidUsedBitMask;
extern uint8 SAD_au8StepToExecute[KU8_MAX_SOLENOID_NB];
/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/

extern void SAD_Init(void);

/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

/**
 * \brief
 *       Check if the current solenoid (input parameter) is enabled.
 */
#define KB_SAD_SOLENOID_CONFIGURED(u8SolenoidId) \
         (((SAD_u8SolenoidUsedBitMask & (uint8)(KU8_ONE << u8SolenoidId)) != KU8_ZERO) ? KB_TRUE : KB_FALSE)
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* _SAD_H_ */

