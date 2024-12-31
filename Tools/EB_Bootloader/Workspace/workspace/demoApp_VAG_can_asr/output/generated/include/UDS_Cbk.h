/*********************************************************************************/
/*                                                                               */
/*                                  CAN Stack                                    */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                                 UDS configuration                             */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file UDS_Cbk.h                       */
/*%%  |                             |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 3.9.1 BL-3.X                 */
/*%%  |   &       &    &            |  %%  Module variant: ISO           */
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

#ifndef UDS_CBK_H
#define UDS_CBK_H

/** \brief Notification for diagnostic session transition
 **
 ** It provides old and new sessions, with the reason for the transition.
 ** 
 ** \param[in] eUdsNewSessType new session
 ** \param[in] eUdsOldSessType old session
 ** \param[in] eUdsChangingCause explicit request (UDS_SESSION_CHANGE_REQUESTED) or session timeout (UDS_SESSION_TIMEOUT)
 ** 
 **/
extern void UDS_SessionStatusInd (tUdsSessionType eUdsNewSessType,tUdsSessionType eUdsOldSessType,tUdsChangeReason eUdsChangingCause);


/** \brief Notification just before the P2/P2_STAR timeout.
 **
 ** Notification in order to give possibility to the application
 ** to execute an action before P2/P2_STAR timeout.
 ** 
 **/
extern void UDS_P2AboutToExpireInd(void);

/** \brief Notification of positive answer.
 **
 ** Notification in order to give possibility to the user to
 ** execute an action before the positive answer transmission.
 ** 
 ** \param[in] puwLen received data length
 ** \param[in] aubUdsData received data pointer
 **
 **/
extern void UDS_CustomPositiveAnswerInd(const u16 *puwLen, const u8 *aubUdsData);



/* skip this code from DoxyGen */
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* Callback function prototype : Service */

/** \brief Callback for the diagnostic request (configuration) 
 **
 ** The diagnostic request is valid (filtering completed).
 ** The callback configured for this service is used.
 ** 
 ** \param[in,out] puwLen pointer on data length
 ** \param[in,out] aubUdsData pointer on data
 ** 
 ** \return Diagnostic response status
 ** \retval UDS_ACK     Positive response
 ** \retval UDS_NRC_xxx Negative response code.
 **
 **/
extern tUdsStatus APP_ProgSession(u16 *puwLen, u8 *aubUdsData);

/** \brief Callback for the diagnostic request (configuration) 
 **
 ** The diagnostic request is valid (filtering completed).
 ** The callback configured for this service is used.
 ** 
 ** \param[in,out] puwLen pointer on data length
 ** \param[in,out] aubUdsData pointer on data
 ** 
 ** \return Diagnostic response status
 ** \retval UDS_ACK     Positive response
 ** \retval UDS_NRC_xxx Negative response code.
 **
 **/
extern tUdsStatus APP_CommunicationControl(u16 *puwLen, u8 *aubUdsData);

/** \brief Callback for the diagnostic request (configuration) 
 **
 ** The diagnostic request is valid (filtering completed).
 ** The callback configured for this service is used.
 ** 
 ** \param[in,out] puwLen pointer on data length
 ** \param[in,out] aubUdsData pointer on data
 ** 
 ** \return Diagnostic response status
 ** \retval UDS_ACK     Positive response
 ** \retval UDS_NRC_xxx Negative response code.
 **
 **/
extern tUdsStatus APP_ControlDTCSetting(u16 *puwLen, u8 *aubUdsData);

/** \brief Callback for the diagnostic request (configuration) 
 **
 ** The diagnostic request is valid (filtering completed).
 ** The callback configured for this service is used.
 ** 
 ** \param[in,out] puwLen pointer on data length
 ** \param[in,out] aubUdsData pointer on data
 ** 
 ** \return Diagnostic response status
 ** \retval UDS_ACK     Positive response
 ** \retval UDS_NRC_xxx Negative response code.
 **
 **/
extern tUdsStatus APP_EcuReset(u16 *puwLen, u8 *aubUdsData);

/* Callback function prototype : Service_DID */

/** \brief Callback for the diagnostic request (configuration) 
 **
 ** The diagnostic request is valid (filtering completed).
 ** The callback configured for this service is used.
 ** 
 ** \param[in,out] puwLen pointer on data length
 ** \param[in,out] aubUdsData pointer on data
 ** 
 ** \return Diagnostic response status
 ** \retval UDS_ACK     Positive response
 ** \retval UDS_NRC_xxx Negative response code.
 **
 **/
extern tUdsStatus UDS_ReadDataByIdentifier(u16 *puwLen, u8 *aubUdsData);

/* Callback function prototype : Routine_Control */

/** \brief Callback for the diagnostic request (configuration) 
 **
 ** The diagnostic request is valid (filtering completed).
 ** The callback configured for this service is used.
 ** 
 ** \param[in,out] puwLen pointer on data length
 ** \param[in,out] aubUdsData pointer on data
 ** 
 ** \return Diagnostic response status
 ** \retval UDS_ACK     Positive response
 ** \retval UDS_NRC_xxx Negative response code.
 **
 **/
extern tUdsStatus APP_ReqCheckProgPreCondition(u16 *puwLen, u8 *aubUdsData);

/** \brief Callback for the diagnostic request (configuration) 
 **
 ** The diagnostic request is valid (filtering completed).
 ** The callback configured for this service is used.
 ** 
 ** \param[in,out] puwLen pointer on data length
 ** \param[in,out] aubUdsData pointer on data
 ** 
 ** \return Diagnostic response status
 ** \retval UDS_ACK     Positive response
 ** \retval UDS_NRC_xxx Negative response code.
 **
 **/
extern tUdsStatus APP_ClearProgCounter(u16 *puwLen, u8 *aubUdsData);

/* Callback function prototype : OBD */


#endif /* DOXYGEN_SHOULD_SKIP_THIS */






#endif      /* UDS_CBK_H */
