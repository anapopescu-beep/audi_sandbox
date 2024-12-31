/**
 * \file
 *
 * \brief AUTOSAR PduR
 *
 * This file contains the implementation of the AUTOSAR
 * module PduR.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined PDUR_SYMBOLIC_NAMES_PBCFG_H)
#define PDUR_SYMBOLIC_NAMES_PBCFG_H

/*==================[includes]==============================================*/

/*==================[macros]================================================*/
/* -------------------- Routing path: 0 Pdu_Rx_Phys */
#if (defined PduRConf_PduRSrcPdu_Sdu_Rx_Phys)
#error PduRConf_PduRSrcPdu_Sdu_Rx_Phys is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_Rx_Phys 0U /* SRC CanTp-LO-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_Rx_Phys)
#error PduR_Sdu_Rx_Phys is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_Rx_Phys 0U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Rx_Phys_d)
#error PduRConf_PduRDestPdu_Sdu_Rx_Phys_d is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Rx_Phys_d 0U /* DEST BlPduR-UP-TP */


/* -------------------- Routing path: 1 Pdu_Rx_Func */
#if (defined PduRConf_PduRSrcPdu_Sdu_Rx_Func)
#error PduRConf_PduRSrcPdu_Sdu_Rx_Func is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_Rx_Func 1U /* SRC CanTp-LO-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_Rx_Func)
#error PduR_Sdu_Rx_Func is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_Rx_Func 1U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Rx_Func_d)
#error PduRConf_PduRDestPdu_Sdu_Rx_Func_d is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Rx_Func_d 1U /* DEST BlPduR-UP-TP */


/* -------------------- Routing path: 2 Pdu_Tx */
#if (defined PduRConf_PduRSrcPdu_Sdu_Tx)
#error PduRConf_PduRSrcPdu_Sdu_Tx is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_Tx 0U /* SRC BlPduR-UP-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_Tx)
#error PduR_Sdu_Tx is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_Tx 0U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Tx_d)
#error PduRConf_PduRDestPdu_Sdu_Tx_d is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Tx_d 0U /* DEST CanTp-LO-TP */



/* Define vendor specific destination PDU IDs of adjacent modules */
#if (defined PDUR_PROVIDE_ADJACENT_MODULE_VENDOR_SYMBOLIC_NAMES)

/* -------------------- Routing path: 0 Pdu_Rx_Phys */
#define PDURSA_Sdu_Rx_Phys_Boot 0U /* SRC CanTp-LO-TP */
#define PDURDA_Sdu_Rx_Phys_Boot 1U /* DEST BlPduR-UP-TP */

/* -------------------- Routing path: 1 Pdu_Rx_Func */
#define PDURSA_Sdu_Rx_Func_Boot 1U /* SRC CanTp-LO-TP */
#define PDURDA_Sdu_Rx_Func_Boot 0U /* DEST BlPduR-UP-TP */

/* -------------------- Routing path: 2 Pdu_Tx */
#define PDURSA_Sdu_Tx_Boot 0U /* SRC BlPduR-UP-TP */
#define PDURDA_Sdu_Tx_Boot 0U /* DEST CanTp-LO-TP */

#endif /* defined PDUR_PROVIDE_ADJACENT_MODULE_VENDOR_SYMBOLIC_NAMES */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
#endif /* if !defined( PDUR_SYMBOLIC_NAMES_PBCFG_H ) */
