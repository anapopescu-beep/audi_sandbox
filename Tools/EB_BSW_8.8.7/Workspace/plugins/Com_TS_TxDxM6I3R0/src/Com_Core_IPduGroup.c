/**
 * \file
 *
 * \brief AUTOSAR Com
 *
 * This file contains the implementation of the AUTOSAR
 * module Com.
 *
 * \version 6.3.54
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]============================================*/

#include <Com_Trace.h>
#include <TSAutosar.h>          /* EB specific standard types */
#include <ComStack_Types.h>     /* AUTOSAR Standard types */
#include <Com_Api.h>                /* Module public API */
#include <Com_Priv.h>           /* Module private API */

#include <Com_Core_TxIPdu.h>    /* Header TxIPdu functions */
#include <Com_Core_RxIPdu.h>    /* Header RxIPdu functions */
#include <Com_Core_IPduGroup.h>    /* Header IPduGroup functions */

/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

#if (TS_MERGED_COMPILE == STD_OFF)
#define COM_START_SEC_CODE
#include <Com_MemMap.h>
#endif


/** \brief Com_EB_HandlePduGroupRx - handle PDU groups
 * function which manages starting/stopping of Rx-Pdus and enabling/disabling
 * RxDM of Rx-Pdus
 * Preconditions:
 * - prior to this call, the COM module shall be initialized
 *
 * \param[in] mode - type of action which should be performed
 * (COM_IPDUGROUP_CONTROL, COM_IPDUGROUP_RXDM_CONTROL)
 * \param[in] ipduGroupVector - I-PDU group vector containing the activation
 * state (stopped = 0/ started = 1) for all IPdus.
 * \param[in] Initialize - defines if the Pdu group should be initialized
 * in case of starting of Pdus
 */
TS_MOD_PRIV_DEFN FUNC(void, COM_CODE) Com_EB_HandlePduGroupRx
(
   Com_IpduGroupModeType mode,
   P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) ipduGroupVector,
   boolean Initialize
)
{

   ComIPduRefType const rxPduCount = Com_gConfigPtr->ComRxIPduArraySize;
   ComIPduRefType IPduId;


   /* loop over all Rx-Pdus */
   for (IPduId = 0U; IPduId < rxPduCount; IPduId++)
   {
     CONSTP2CONST(ComRxIPduType, AUTOMATIC, COM_APPL_CONST) IPduPtr =
         COM_GET_CONFIG_ELEMENT(ComRxIPduType, Com_gConfigPtr->ComRxIPduRef, IPduId);

#if (COM_PBCFG_VARIANT_SUPPORT_ENABLED == STD_ON)
     if( FALSE == COM_GET_COM_RX_IPDU_DUMMY(IPduPtr) )
#endif /* (COM_PBCFG_VARIANT_SUPPORT_ENABLED == STD_ON) */
     {

       if(IPduPtr->ComIPduGroupMaskRef != COM_IPDUGROUPMASK_REF_INVALID)
       {
         CONSTP2CONST(ComIPduGroupMaskType, AUTOMATIC, COM_APPL_CONST) MaskPtr =
             COM_GET_CONFIG_ELEMENT(ComIPduGroupMaskType,
                 Com_gConfigPtr->ComIPduGroupMaskRef,
                 IPduPtr->ComIPduGroupMaskRef * COM_IPDU_GROUP_VECTOR_NUM_BYTES);

         boolean toBeActivated = FALSE;
         boolean activate = FALSE;
         uint16 iPduGroupVectorByte =
             (uint16)(Com_gConfigPtr->ComRxIpduGroupVectorByteEnd);

         /* loop over all bytes of the vector */
         do {

           iPduGroupVectorByte--;

           activate =
               ((MaskPtr[iPduGroupVectorByte] & ipduGroupVector[iPduGroupVectorByte]) != FALSE)
               ? TRUE
                   : FALSE;

           toBeActivated = (toBeActivated || activate) ? TRUE: FALSE;

         } while(iPduGroupVectorByte != 0U);

         Com_EB_HandleRxIPdu(mode,
             toBeActivated,
  #if (COM_RX_TIMEOUT_FACTOR_AVAILABLE == STD_ON)
             IPduPtr,
  #endif /* (COM_RX_TIMEOUT_FACTOR_AVAILABLE == STD_ON) */
             Initialize,
             IPduId);
       }

     }

   }                            /* for (IPduId = 0U; IPduId < rxPduCount; IPduId++) */

   return;
}                               /* Com_EB_HandlePduGroupRx */

/** \brief Com_EB_HandlePduGroupTx - handle PDU groups
 * function which manages starting/stopping of Tx-Pdus
 * Preconditions:
 * - prior to this call, the COM module shall be initialized
 *
 * \param[in] ipduGroupVector - I-PDU group vector containing the activation
 * state (stopped = 0/ started = 1) for all IPdus.
 * \param[in] Initialize - defines if the Pdu should be initialized
 */
TS_MOD_PRIV_DEFN FUNC(void, COM_CODE) Com_EB_HandlePduGroupTx
(
   P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) ipduGroupVector,
   boolean Initialize
)
{

   ComIPduRefType const txPduCount = Com_gConfigPtr->ComTxIPduArraySize;
   ComIPduRefType IPduId;


   /* loop over all Tx-Pdus */
   for (IPduId = 0U; IPduId < txPduCount; IPduId++)
   {
     CONSTP2CONST(ComTxIPduType, AUTOMATIC, COM_APPL_CONST) IPduPtr =
         COM_GET_CONFIG_ELEMENT(ComTxIPduType, Com_gConfigPtr->ComTxIPduRef, IPduId);

#if (COM_PBCFG_VARIANT_SUPPORT_ENABLED == STD_ON)
     if( FALSE == COM_GET_COM_TX_IPDU_DUMMY(IPduPtr) )
#endif /* (COM_PBCFG_VARIANT_SUPPORT_ENABLED == STD_ON) */
     {

       if(IPduPtr->ComIPduGroupMaskRef != COM_IPDUGROUPMASK_REF_INVALID)
       {
         CONSTP2CONST(ComIPduGroupMaskType, AUTOMATIC, COM_APPL_CONST) MaskPtr =
             COM_GET_CONFIG_ELEMENT(ComIPduGroupMaskType,
                 Com_gConfigPtr->ComIPduGroupMaskRef,
                 IPduPtr->ComIPduGroupMaskRef * COM_IPDU_GROUP_VECTOR_NUM_BYTES);

         boolean toBeActivated = FALSE;
         uint16 iPduGroupVectorByte =
             (uint16)(Com_gConfigPtr->ComTxIpduGroupVectorByteStart);

         /* loop over all bytes of the vector */
         do {

           boolean activate =
               ((MaskPtr[iPduGroupVectorByte] & ipduGroupVector[iPduGroupVectorByte]) != FALSE)
               ? TRUE
                   : FALSE;

           toBeActivated = (toBeActivated || activate) ? TRUE : FALSE;

           iPduGroupVectorByte++;

         } while(iPduGroupVectorByte != COM_IPDU_GROUP_VECTOR_NUM_BYTES);

         Com_EB_HandleTxIPdu(toBeActivated, IPduPtr, Initialize, IPduId);
       }

     }

   }                            /* for (IPduId = 0U; IPduId < txPduCount; IPduId++) */

   return;
}                               /* Com_EB_HandlePduGroupTx */


#if (TS_MERGED_COMPILE == STD_OFF)
#define COM_STOP_SEC_CODE
#include <Com_MemMap.h>
#endif

