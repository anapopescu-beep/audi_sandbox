
#ifndef EIM_H_
#define EIM_H_ 1

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
   This file defines the information (interfaces, definitions and data) provided
   by the module EIM, part of the component EIM.

******************************************************************************/
/*
$Revision: 1.3.1.3 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/EIM/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 * \brief
 *    This macro is used to define EIM maximum number of errors
 */
#define KU8_EIM_MAXIMUM_NUMBER_OF_ERRORS        ((uint8)0x05)
/**
 * \brief
 *    This macro is used to define if EIM is not configured
 */
#define EIM_NOT_CONFIGURED                          0
/**
 * \brief
 *    This macro is used to define if EIM is configured
 */
#define EIM_CONFIGURED                              1

#ifndef ALV_RELEASE_BUILD
#ifndef CAL_KU8_ERROR_INJECTION_MANAGER_ACTIVE
/**
 * \brief
 *   This macro is used to define error injection manager active
 */
#define CAL_KU8_ERROR_INJECTION_MANAGER_ACTIVE      EIM_CONFIGURED
#endif
#else
/**
 * \brief
 * This macro is used to define error injection manager active
 */
#define CAL_KU8_ERROR_INJECTION_MANAGER_ACTIVE      EIM_NOT_CONFIGURED
#endif
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

#endif /* _EIM_H_ */
