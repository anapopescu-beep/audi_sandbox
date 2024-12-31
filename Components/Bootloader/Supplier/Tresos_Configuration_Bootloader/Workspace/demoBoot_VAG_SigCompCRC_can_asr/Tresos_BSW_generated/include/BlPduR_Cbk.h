/*********************************************************************************/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                                 BlPduR configuration                          */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file BlPduR_Cbk.h                    */
/*%%  |                             |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 0.23.0 BL3                */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*********************************************************************************/
/* Copyright 2010 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*********************************************************************************/

#ifndef BLPDUR_CBK_H
#define BLPDUR_CBK_H

/** \brief Notification for diagnostic session transition
 **
 ** It provides old and new sessions, with the reason for the transition.
 **
 ** \param[in] eUdsNewSessType new session
 ** \param[in] eUdsOldSessType old session
 ** \param[in] eUdsChangingCause explicit request (UDS_SESSION_CHANGE_REQUESTED) or session timeout (UDS_SESSION_TIMEOUT)
 **
 **/
extern void APP_UdsSessionStatusInd (tUdsSessionType eUdsNewSessType,tUdsSessionType eUdsOldSessType,tUdsChangeReason eUdsChangingCause);


/** \brief This service is at system initialization by BlPduR module to retrieve Group Id use in the ECU
 **
 ** The Group ID shall be retrieve depending on the system architecture (e.g. from NVM, from a specific I/O,..)
 ** It shall then be returned.
 **
 ** \return value of the Group ID that shall be used in by the bootloader to run
 **/
extern u8 BlPduR_GetGroupIdVal (void);


extern void APP_TpRxInd (tTpMsgIdx uMsgIdx, u8 ebStatus);
extern void APP_TpTxConf (tTpMsgIdx uMsgIdx, u8 ebStatus);

extern void BlPduR_GetRxPduId(u8* pubRxPduId);

extern void BlPduR_StoreRxPduId(u8 ubRxPduId);

extern void BlPduR_Custom_Com_Init(void);

extern void BlPduR_Custom_Com_Deactivate(void);

#endif      /* BLPDUR_CBK_H */
