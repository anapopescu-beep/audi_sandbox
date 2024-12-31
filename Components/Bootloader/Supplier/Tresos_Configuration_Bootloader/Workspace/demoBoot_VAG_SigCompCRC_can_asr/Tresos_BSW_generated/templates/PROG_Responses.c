/*===============================================================================*/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                               PROG layer                                      */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file PROG_Responses.c                */
/*%%  |                             |  %%  \brief PROG layer source plugin file  */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.48.0 BL3 */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*===============================================================================*/
/* Copyright 2017 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*===============================================================================*/
/*=============================== FILE INCLUSION ================================*/
/*                                                                               */
#include "EB_Prj.h"
#include "PROG_Hsm.h"
#include "PROG_HsmPROG.h"
#include "board.h"
/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */
/** \brief API that allows to change the response sent in the case of success of Check Precondition
 **
 ** Callback is called: when Check Precondition succeeded and before sending the response
 **
 ** Callback shall implement: The expected Data to send, the length of the response
 **
 ** \param[in,out] Data received data pointer (points to the encrypted data and callback implementation shall copy decrypted data at the same location than the encrypted one.)
 ** \param[in,out] DataLength received data length
 **
 **/
void PROG_Custom_PreCondCheckRoutine_Succeed(u8 * Data, PduLengthType * DataLength)
{
    /* No Change */
    OSC_PARAM_UNUSED(Data);
    OSC_PARAM_UNUSED(DataLength);
}

/** \brief API that allows to change the response sent in the case of failure of Check Precondition
 **
 ** Callback is called: when Check Precondition failed and before sending the response
 **
 ** Callback shall implement: The expected Data to send, the length of the response and UDS status
 **
 ** \param[in,out] Data received data pointer (points to the encrypted data and callback implementation shall copy decrypted data at the same location than the encrypted one.)
 ** \param[in,out] DataLength received data length
 ** \param[in,out] eUdsStatus The result of the Check Precondition.
 **             Can be: UDS_ACK, UDS_NRC_XX (XX can take the values defined in ISO 14429 -  Annex A - Negative Response codes)
 **
 **/
void PROG_Custom_PreCondCheckRoutine_Failed(u8 * Data, PduLengthType * DataLength, tUdsStatus * eUdsStatus)
{
    /* No Change */
    OSC_PARAM_UNUSED(Data);
    OSC_PARAM_UNUSED(DataLength);
    OSC_PARAM_UNUSED(eUdsStatus);
}
