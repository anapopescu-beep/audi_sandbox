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
$Revision: 1.2 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader/Autoliv/ComMIf/Implementation/src/project.pj $
*/
/*!****************************************************************************

@details
   This file contains function for communication type.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include <Std_Types.h>
#include <ComStack_Types.h>   /* AUTOSAR communication stack types */
#include <ComM_BusSM.h>
#include <common.h>
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
*       Function used to indicate the communication type.
* \param
*       Name: Channel;
*       Type: NetworkHandleType;
*       Description: the identifier of a communication channel;
*       Name: ComMode;
*       Type: P2VAR;
*       Description: communication mode;
* \constrains
*       None.
* \dynamicaspectcaller
*       Tresos BSW generated module.
* \dynamicaspectdescription
*       Called in CANSM_CALL_SM_MODEINDICATION function.
* \ddesignrequirement
*		DSG_ComMIf_ComM_BusSM_ModeIndication
* \archrequirement
*		ARCH_SW_ComMIf_ComM_BusSM_ModeIndication
**/
EXPORTED FUNC(void, COMM_CODE) ComM_BusSM_ModeIndication
(
    NetworkHandleType Channel,
    P2VAR(uint8, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{


}

/******************************************************************************
End Of File
*****************************************************************************/
