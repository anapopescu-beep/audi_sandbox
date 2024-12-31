
#ifndef I_ATM_PUBLIC_CFG
#define I_ATM_PUBLIC_CFG 1

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
    This file defines the information (interfaces, definitions and data) configurable
    in the package ATM.
    This file is to be included only by this component.

******************************************************************************/
/*
$Revision: 1.1.7.18 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/ATM/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Std_Types.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/* BE CAREFUL: when adding a new auto test identifier DO NOT FORGET TO UPDATE the constants below */
/**
 * \brief
 *       Number of Startup cyclic tests.
 */
#define KU8_ATM_NB_OF_STARTUP_CYCLIC_ELTS                   ((uint8) 7)
/**
 * \brief
 *       Number of Running cyclic tests.
 */
#define KU8_ATM_NB_OF_RUNNING_CYCLIC_ELTS                   ((uint8) 39)
/**
 * \brief
 *       Number of Startup autotests.
 */
#define KU8_ATM_NB_OF_STARTUP_AUTO_TESTS                    ((uint8) 9)

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
/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* I_ATM_PUBLIC_CFG */
