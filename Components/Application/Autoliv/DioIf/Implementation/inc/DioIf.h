#ifndef DIOIF_H_
#define DIOIF_H_ 1

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
	by the module DioIf, part of the component DioIf.

******************************************************************************/
/*
$Revision: 1.7 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/DioIf/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Std_Types.h"
#include "Rte_Type.h"

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
extern FUNC(void, RTE_CODE) DioIf_Init (void);
extern FUNC(void, RTE_CODE) DioIf_SetSolenoidCurrentSourcesState(uint8 u8PinLevel);
extern FUNC(void, RTE_CODE) DioIf_runReadChannel (u8DioIfChannelType u8ChannelID, u8DioIfLvlType* u8Level);
extern FUNC(void, RTE_CODE) DioIf_runWriteChannel (u8DioIfChannelType u8ChannelID, u8DioIfLvlType u8Level);
/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* DIOIF_H_ */
