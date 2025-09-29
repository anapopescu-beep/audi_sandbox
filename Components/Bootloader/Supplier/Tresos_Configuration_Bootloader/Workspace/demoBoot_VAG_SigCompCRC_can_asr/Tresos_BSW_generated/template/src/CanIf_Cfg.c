/**
 * \file
 *
 * \brief AUTOSAR CanIf
 *
 * This file contains the implementation of the AUTOSAR
 * module CanIf.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*
 *  MISRA-C:2012 Deviations:
 *
 *  MISRAC2012-1) Deviated Rule: 9.5 (Required)
 *    Where designated initializers are used to initialize an array object the
 *    size of the array shall be specified explicitly.
 *
 *    Reason:
 *    Array size and initialization are depending on configuration whereas the
 *    array declaration is used by configuration-independent library code.
 */

/*==================[inclusions]=============================================*/

#define CANIF_NO_CFGCLASSMIX_REQUIRED
#define CANIF_NO_PBCFG_REQUIRED
#include <CanIf.h>                /* CanIf Types */
#include <CanIf_Int.h>




/* do not indirectly include PduR_SymbolicNames_PBcfg.h via PduR_CanIf.h */
#define PDUR_NO_PBCFG_REQUIRED

#include <CanTp_Cbk.h>             /* CanTp callback function declarations */


/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[internal constants]=====================================*/

/*==================[external constants]=====================================*/

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanIf_MemMap.h>



#if (CANIF_ANY_UL_CBK_SUPPORT == STD_ON)
/** \brief Configuration of upper layer callback function pointers */
/* Deviation MISRAC2012-1 <START> */
CONST( CanIf_CbkFctPtrTblType, CANIF_APPL_CONST ) CanIf_CbkFctPtrTbl[] =
{
  {
     /* CAN_TP */
#if (CANIF_UL_RX_INDICATION_SUPPORT == STD_ON)
    &CanTp_RxIndication,
#endif /* CANIF_UL_RX_INDICATION_SUPPORT == STD_ON */
#if (CANIF_CDD_RX_INDICATION_SUPPORT == STD_ON)
    NULL_PTR,
#endif /* CANIF_CDD_RX_INDICATION_SUPPORT == STD_ON */
#if (CANIF_TX_CONFIRMATION_SUPPORT == STD_ON)
    &CanTp_TxConfirmation,
#endif /* CANIF_TX_CONFIRMATION_SUPPORT == STD_ON */
#if (CANIF_DLC_ERROR_NOTIF_SUPPORT == STD_ON)
    NULL_PTR,
#endif /* CANIF_DLC_ERROR_NOTIF_SUPPORT == STD_ON */
#if (CANIF_DLC_PASSED_NOTIF_SUPPORT == STD_ON)
    NULL_PTR,
#endif  /* CANIF_DLC_PASSED_NOTIF_SUPPORT == STD_ON */
  },
};
/* Deviation MISRAC2012-1 <STOP> */
#endif /* CANIF_ANY_UL_CBK_SUPPORT == STD_ON */





#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <CanIf_MemMap.h>

/*==================[external data]==========================================*/


#define CANIF_START_SEC_VAR_NO_INIT_8
#include <CanIf_MemMap.h>

#if( ( CANIF_WAKEUP_VALIDATION_API == STD_ON ) || \
     ( CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT == STD_ON )  || \
     ( CANIF_PUBLIC_PN_SUPPORT == STD_ON) )

/** \brief Controller flags
 **
 ** This array contains the wakeup flags of all configured
 ** controllers. If a bit/flag has the value 1 it is set.
 ** Bit masks are:
 ** CANIF_WAKEUP_MASK             Wakeup flag
 ** CANIF_WAKEUP_VALIDATION_MASK  Wakeup validation flag
 ** CANIF_TX_CONFIRMATION_MASK    Tx confirmation flag
 ** CANIF_PN_FILTER_ACTIVE_MASK   Partial networking filter flag
 */
VAR( uint8, CANIF_VAR )
  CanIf_CanControllerFlags[4U];

#endif /* ( CANIF_WAKEUP_VALIDATION_API == STD_ON ) || \
          ( CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT == STD_ON ) */

#if( CANIF_READTXPDU_NOTIF_STATUS_API == STD_ON )
/** \brief Bit-array of Tx notification flags (if enabled) */
VAR( uint8, CANIF_VAR )
  CanIf_TxLPduNotifyFlags[(1U+7U)/8U];
#endif /* CANIF_READTXPDU_NOTIF_STATUS_API == STD_ON */

#if( CANIF_READRXPDU_NOTIF_STATUS_API == STD_ON )
/** \brief Bit-array of Rx notification flags (if enabled) */
VAR( uint8, CANIF_VAR )
  CanIf_RxLPduNotifyFlags[(1U+7U)/8U];
#endif /* CANIF_READRXPDU_NOTIF_STATUS_API == STD_ON */

#if( CANIF_READRXPDU_DATA_API == STD_ON )
/** \brief Array of Rx buffers */
VAR( uint8, CANIF_VAR ) CanIf_RxBuffer[1U];
#endif /* CANIF_READRXPDU_NOTIF_STATUS_API == STD_ON */

#if( CANIF_PUBLIC_TX_BUFFERING == STD_ON )
/** \brief Tx buffer memory */
VAR( uint8, CANIF_VAR ) CanIf_TxBufferMemory[1U];
#endif /* CANIF_PUBLIC_TX_BUFFERING == STD_ON */

#if (CANIF_DECOUPLED_RXPROCESSING_SUPPORT == STD_ON)
/** \brief Array of Rx queued data */
VAR( uint8, CANIF_VAR )
  CanIf_RxDataQueue[0U];
#endif /* CANIF_DECOUPLED_RXPROCESSING_SUPPORT */

#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include <CanIf_MemMap.h>

#define CANIF_START_SEC_VAR_NO_INIT_16
#include <CanIf_MemMap.h>

#if (CANIF_DECOUPLED_RXPROCESSING_SUPPORT == STD_ON)
/** \brief Array of Rx queue Indexes
 **
 ** This is the array of Rx queue Indexes used to get the payload index during
 ** message reception if Rx processing is enabled.
 */
VAR( uint16, CANIF_VAR )
  CanIf_MFRxQueueIdx[0U];
#endif /* CANIF_DECOUPLED_RXPROCESSING_SUPPORT */

#if CANIF_PUBLIC_TX_BUFFERING == STD_ON
/** \brief Array of a HTH's number of pending Tx requests */
VAR( CanIf_TxBufferIndexType, CANIF_VAR )
  CanIf_NrOfPendingTxRequests[1U];

/** \brief Pending transmit request buffers
 **
 ** This array stores pending transmit request IDs. It is named as array (8)
 ** in the CAN interface design.
 */
VAR( CanIf_LPduIndexType, CANIF_VAR )
  CanIf_PendingTxBuffers[1U];
#endif /* CANIF_PUBLIC_TX_BUFFERING */

#if(CANIF_DECOUPLED_RXPROCESSING_SUPPORT == STD_ON)
/** \brief Total size of the queue
 **
 ** This variable shows the current value of the queue of the CAN interface.
 */
VAR( uint16, CANIF_VAR ) CanIf_TotalRxQueueSize[1U];
#endif/* CANIF_DECOUPLED_RXPROCESSING_SUPPORT == STD_ON */

#if((CANIF_DECOUPLED_TXPROCESSING_SUPPORT == STD_ON) && (CANIF_TX_CONFIRMATION_SUPPORT == STD_ON))
/** \brief Total size of the queue
 **
 ** This variable shows the current value of the queue of the CAN interface.
 */
VAR( uint16, CANIF_VAR ) CanIf_TotalTxQueueSize[1U];
#endif/* CANIF_DECOUPLED_TXPROCESSING_SUPPORT == STD_ON && CANIF_TX_CONFIRMATION_SUPPORT == STD_ON */

#define CANIF_STOP_SEC_VAR_NO_INIT_16
#include <CanIf_MemMap.h>

#define CANIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include <CanIf_MemMap.h>

VAR( CanIf_ControllerModeType, CANIF_VAR )
  CanIf_CanControllerMode[4U];

VAR( CanIf_PduModeType, CANIF_VAR )
  CanIf_PduMode[4U];

#if( CANIF_SETDYNAMICTXID_API == STD_ON )
/** \brief Array for dynamic CAN IDs
 **
 ** This array contains the current set CAN ID for dynamic Tx L-PDUs.
 */
 VAR( Can_IdType, CANIF_VAR )
  CanIf_DynamicTxLPduCanIds[1U];
#endif /* CANIF_SETDYNAMICTXID_API == STD_ON */

#if CANIF_PUBLIC_TX_BUFFERING == STD_ON
/** \brief Array of Tx buffers
 **
 ** This is the array of Tx buffers used during message transmission if Tx
 ** buffering is enabled.
 */
VAR( CanIf_TxBufferType, CANIF_VAR )
  CanIf_TxBuffer[1U];
#endif /* CANIF_PUBLIC_TX_BUFFERING */

#if (CANIF_DECOUPLED_TXPROCESSING_SUPPORT == STD_ON)
/** \brief Array of Tx queue
 **
 ** This is the array of Tx queue used during message transmission confirmation
 ** if Tx processing is enabled.
 */
VAR( CanIf_TxQueueType, CANIF_VAR )
  CanIf_TxPduQueue[0U];
#endif /* CANIF_DECOUPLED_TXPROCESSING_SUPPORT */

#if (CANIF_DECOUPLED_RXPROCESSING_SUPPORT == STD_ON)
/** \brief Array of Rx queue
 **
 ** This is the array of Rx queue used during message reception
 ** if Rx processing is enabled.
 */
VAR( CanIf_RxQueueType, CANIF_VAR )
  CanIf_RxPduQueue[0U];

#endif /* CANIF_DECOUPLED_RXPROCESSING_SUPPORT */

#define CANIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include <CanIf_MemMap.h>


/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/*==================[end of file]============================================*/
