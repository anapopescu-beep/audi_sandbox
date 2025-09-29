
/**
 * \file
 *
 * \brief SchM
 *
 * This file contains the implementation of the SchM
 * exclusive areas.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /* Misra deviations:
  * 1) Deviation against MISRA-C:1998 Rule 11 (required)
  *      and               MISRA-C:2004 Rule 5.1 (required)
  *      Description:
  *      Identifiers (internal and external) shall not rely
  *      on the significance of more than 31 characters.
  *      Reason:
  *      The defined SchM naming convention may result in
  *      identifiers with more than 31 characters.
  *      The compliance to this rule is under user's control.
  *
  */


/*==================[inclusions]=============================================*/

#include <Std_Types.h>

#include <EB_Prj.h>

#include <board.h>

#include <SchM_Prog.h>

/*==================[macros]=================================================*/

/*------------------[interrupt locking]--------------------------------------*/

/*==================[internal data]==========================================*/

/*------------------[API function definitions]-------------------------------*/



FUNC(void, SCHM_CODE) SchM_Enter_PROG_SCHM_PROG_EXCLUSIVE_AREA_0 (void)
{
  BoardDisableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Enter_PROG_SCHM_PROG_EXCLUSIVE_AREA_0 (void) */

FUNC(void, SCHM_CODE) SchM_Exit_PROG_SCHM_PROG_EXCLUSIVE_AREA_0 (void)
{
  BoardEnableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Exit_PROG_SCHM_PROG_EXCLUSIVE_AREA_0 (void) */

FUNC(void, SCHM_CODE) SchM_Enter_Det_SCHM_DET_EXCLUSIVE_AREA_0(void)
{
  BoardDisableInterrupts();
} /* FUNC(void, SCHM_CODE) SchM_Enter_Det_SCHM_DET_EXCLUSIVE_AREA_0 (void) */


FUNC(void, SCHM_CODE) SchM_Exit_Det_SCHM_DET_EXCLUSIVE_AREA_0(void)
{
  BoardEnableInterrupts();
} /* FUNC(void, SCHM_CODE) SchM_Exit_Det_SCHM_DET_EXCLUSIVE_AREA_0 (void) */





FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_00 (void)
{
  BoardDisableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_00 (void) */

FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_00 (void)
{
  BoardEnableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_00 (void) */

FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_01 (void)
{
  BoardDisableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_01 (void) */

FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_01 (void)
{
  BoardEnableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_01 (void) */

FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_02 (void)
{
  BoardDisableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_02 (void) */

FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_02 (void)
{
  BoardEnableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_02 (void) */

FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_03 (void)
{
  BoardDisableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_03 (void) */

FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_03 (void)
{
  BoardEnableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_04 (void) */

FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_04 (void)
{
  BoardDisableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_04 (void) */

FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_04 (void)
{
  BoardEnableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_04 (void) */

FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05 (void)
{
  BoardDisableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05 (void) */

FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05 (void)
{
  BoardEnableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05 (void) */

FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_06 (void)
{
  BoardDisableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_06 (void) */

FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_06 (void)
{
  BoardEnableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_06 (void) */

FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_07 (void)
{
  BoardDisableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_07 (void) */

FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_07 (void)
{
  BoardEnableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_07 (void) */

FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_08 (void)
{
  BoardDisableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_08 (void) */

FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_08 (void)
{
  BoardEnableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_08 (void) */

FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_09 (void)
{
  BoardDisableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_09 (void) */

FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_09 (void)
{
  BoardEnableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_09 (void) */

FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_13 (void)
{
  BoardDisableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Enter_Can_CAN_EXCLUSIVE_AREA_13 (void) */

FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_13 (void)
{
  BoardEnableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Exit_Can_CAN_EXCLUSIVE_AREA_13 (void) */



FUNC(void, SCHM_CODE) SchM_Enter_CanIf_SCHM_CANIF_EXCLUSIVE_AREA_0 (void)
{
  BoardDisableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Enter_CanIf_SCHM_CANIF_EXCLUSIVE_AREA_0 (void) */

FUNC(void, SCHM_CODE) SchM_Exit_CanIf_SCHM_CANIF_EXCLUSIVE_AREA_0 (void)
{
  BoardEnableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Exit_CanIf_SCHM_CANIF_EXCLUSIVE_AREA_0 (void) */

FUNC(void, SCHM_CODE) SchM_Enter_CanSM_SCHM_CANSM_EXCLUSIVE_AREA_0 (void)
{
  BoardDisableInterrupts();

} /* FUNC(void, RTE_CODE) SchM_Enter_CanSM_SCHM_CANSM_EXCLUSIVE_AREA_0 (void) */

FUNC(void, SCHM_CODE) SchM_Exit_CanSM_SCHM_CANSM_EXCLUSIVE_AREA_0 (void)
{
  BoardEnableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Exit_CanSM_SCHM_CANSM_EXCLUSIVE_AREA_0 (void) */

FUNC(void, SCHM_CODE) SchM_Enter_Can_17_MCanP_CanDisInt (void)
{
  BoardDisableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Enter_Can_17_MCanP_CanDisInt (void) */

FUNC(void, SCHM_CODE) SchM_Exit_Can_17_MCanP_CanDisInt (void)
{
  BoardEnableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Exit_Can_17_MCanP_CanDisInt (void) */

FUNC(void, SCHM_CODE) SchM_Enter_CanTp_SCHM_CANTP_EXCLUSIVE_AREA_0 (void)
{
  BoardDisableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Enter_CanTp_SCHM_CANTP_EXCLUSIVE_AREA_0 (void) */

FUNC(void, SCHM_CODE) SchM_Exit_CanTp_SCHM_CANTP_EXCLUSIVE_AREA_0 (void)
{
  BoardEnableInterrupts();

} /* FUNC(void, SCHM_CODE) SchM_Exit_CanTp_SCHM_CANTP_EXCLUSIVE_AREA_0 (void) */

FUNC(void, SCHM_CODE) SchM_Enter_Csm_SCHM_CSM_EXCLUSIVE_AREA_0 (void)
{

} /* FUNC(void, SCHM_CODE) SchM_Enter_Csm_SCHM_CSM_EXCLUSIVE_AREA_0 (void) */
FUNC(void, SCHM_CODE) SchM_Exit_Csm_SCHM_CSM_EXCLUSIVE_AREA_0 (void)
{

} /* FUNC(void, SCHM_CODE) SchM_Exit_Csm_SCHM_CSM_EXCLUSIVE_AREA_0 (void) */


/*==================[internal function definitions]==========================*/

/*==================[end of file]============================================*/
