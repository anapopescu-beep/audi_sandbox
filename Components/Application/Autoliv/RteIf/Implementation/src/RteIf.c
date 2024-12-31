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
$Revision: 1.9 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/RteIf/Implementation/src/project.pj $
*/

/*!****************************************************************************

details
   The purpose of this module is to provide information about the RTE variables
   from the RTE module.

******************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "RteIf.h"
#include "Rte_Intern.h"
#include "common.h"

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
#define RTE_START_SEC_CODE
#include <Rte_MemMap.h>

/**
* \brief
*       The function is used to return the value of the RTE variable related
*       to the Diag request.
* \inputparam
*       None;
* \outputparam
*       Name: pu8Data;
*       Type: uint8 *;
*       Description: Outputs the value of the RTE the Diag request variable;
*       Range:
*       KU8_NO_DIAG_REQUEST
*       KU8_UNLOCK_DIAG_REQUEST
*       KU8_LOCK_DIAG_REQUEST
*       KU8_DIAG_PROFILE_REQUEST_ON
*       KU8_DIAG_PROFILE_REQUEST_OFF;
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       CIL_runCANToAppli
*       sad_TriggerDiagProfile
* \dynamicaspectdescription
*       API called in CIL_runCANToAppli and SAD_runMainFunction.
* \constraints
*       None.
* \ddesignrequirement
*       !DSG_Rte_Read_CIL_SAD_au8DiagReq_prrEcsDiagRequest
* \archrequirement
*       None;
**/

EXPORTED Std_ReturnType Rte_Read_CIL_SAD_au8DiagReq_prrEcsDiagRequest (uint8 * pu8Data)
{
   Std_ReturnType Rte_Status = RTE_E_OK;

   DisableAllInterrupts();
   TS_MemCpy(pu8Data, Rte_ReceiveBuffer__FSM_prrEcsDiagRequest_au8DiagReq_value, sizeof(au8eCSDiagReqType));
   EnableAllInterrupts();
   return Rte_Status;
}

/**
* \brief
*       The function is used to return the value of the RTE variable related to
*       the Complement Diag request.
* \inputparam
*       None;
* \outputparam
*       Name: pu8Data;
*       Type: uint8 *;
*       Description: Outputs the value of the RTE Diag request variable;
*       Range:
*       ~KU8_NO_DIAG_REQUEST
*       ~KU8_UNLOCK_DIAG_REQUEST
*       ~KU8_LOCK_DIAG_REQUEST
*       ~KU8_DIAG_PROFILE_REQUEST_ON
*       ~KU8_DIAG_PROFILE_REQUEST_OFF;
*
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       CIL_runCANToAppli
*       sad_TriggerDiagProfile
* \dynamicaspectdescription
*       API called in CIL_runCANToAppli and SAD_runMainFunction.
* \constraints
*       None.
* \ddesignrequirement
*       !DSG_Rte_Read_CIL_SAD_au8DiagReqComplement_prrEcsDiagRequest
* \archrequirement
*       None;
**/

EXPORTED Std_ReturnType Rte_Read_CIL_SAD_au8DiagReqComplement_prrEcsDiagRequest (uint8 * pu8Data)
{
   Std_ReturnType Rte_Status = RTE_E_OK;

   DisableAllInterrupts();
   TS_MemCpy(pu8Data, Rte_ReceiveBuffer__FSM_prrEcsDiagRequest_au8DiagReqComplement_value, sizeof(au8eCSDiagReqType));
   EnableAllInterrupts();
   return Rte_Status;
}

#define RTE_STOP_SEC_CODE
#include <Rte_MemMap.h>
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
