/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version:
Template version: AEM_PROCESS_1.25.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2022-09
******************************************************************************/
/*
$Revision: 1.1 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader/Autoliv/CanSMIf/Quality_Assurance/Static_Analysis/project.pj $
*/
/*!****************************************************************************

@details
   This file contains function for CAN state machine.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include <Std_Types.h>
#include <CanSM_BswM.h>
#include <common.h>
#include <BswM_CanSM.h>
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/******************************************************************************
MODULE TYPES
******************************************************************************/
/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/
/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/
/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
/**
* \brief
*       Function used to indicate state changes to BswM.
* \param
*       Name: Network;
*       Type: NetworkHandleType;
*       Description: the identifier of a communication channel;
*       Name: CurrentState;
*       Type: CanSM_BswMCurrentStateType;
*       Description: current state to BswM;
* \constrains
*       None.
* \dynamicaspectcaller
*       CanSM_TS_TxDxM3I6R0 module.
* \dynamicaspectdescription
*       Called in BSWM_CANSM_CURRENTSTATE function.
* \ddesignrequirement
*		DSG_CanSMIf_BswM_CanSM_CurrentState
* \archrequirement
*		ARCH_SW_CanSMIf_BswM_CanSM_CurrentState
**/
EXPORTED FUNC(void, BSWM_CODE) BswM_CanSM_CurrentState
(
  NetworkHandleType Network,
  CanSM_BswMCurrentStateType CurrentState
)
{


}


/******************************************************************************
End Of File
*****************************************************************************/
