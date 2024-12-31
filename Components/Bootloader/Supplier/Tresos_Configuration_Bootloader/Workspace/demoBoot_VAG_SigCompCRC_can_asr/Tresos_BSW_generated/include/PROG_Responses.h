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
/*%%   _____________________________   %%  \file PROG_Responses.h                */
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

#ifndef PROG_RESPONSES_H
#define PROG_RESPONSES_H

/*=============================== FILE INCLUSION ================================*/
/*                                                                               */

/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */

extern void PROG_Custom_PreCondCheckRoutine_Succeed(u8 * Data, PduLengthType * DataLength);

extern void PROG_Custom_PreCondCheckRoutine_Failed(u8 * Data, PduLengthType * DataLength, tUdsStatus * eUdsStatus);

#endif /* PROG_RESPONSES_H */
