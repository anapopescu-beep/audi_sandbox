
#ifndef I_ATM_PRIVATE_CFG
#define I_ATM_PRIVATE_CFG 1

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
$Revision: 1.1.6.5 $
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
/**
 * \brief
 *      The value of maximum period in main function occurrences (2ms) = 100s.
 */
#define ATM_KU16_CFG_MAX_TASK                    ((uint16) 5)
/**
 * \brief
 *      The value of maximum decade in main function.
 */
#define ATM_KU16_CFG_MAX_DECADE                  ((uint16) 60000)

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

#endif /* I_ATM_PRIVATE_CFG */
