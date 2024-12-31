
#ifndef I_ATM_PUBLIC
#define I_ATM_PUBLIC 1

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
    by the component ATM, part of the package <Package name>.
    These are globally visible.
    This file is intended to be included in a package header file;
    all components should include the package header file instead of this file.
    
******************************************************************************/
/*
$Revision: 1.1.5.7 $
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
#define ATM_START_SEC_CODE_ASIL_A
#include "ATM_MemMap.h"

extern void ATM_Init(void);

#define ATM_STOP_SEC_CODE_ASIL_A
#include "ATM_MemMap.h"
/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/
#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* I_ATM_PUBLIC */
