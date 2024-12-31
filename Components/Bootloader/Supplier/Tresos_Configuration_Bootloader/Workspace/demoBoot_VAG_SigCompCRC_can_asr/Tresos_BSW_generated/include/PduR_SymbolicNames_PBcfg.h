/**
 * \file
 *
 * \brief AUTOSAR PduR
 *
 * This file contains the implementation of the AUTOSAR
 * module PduR.
 *
 * \version 5.3.44
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2020 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined PDUR_SYMBOLIC_NAMES_PBCFG_H)
#define PDUR_SYMBOLIC_NAMES_PBCFG_H

/*==================[includes]==============================================*/

/*==================[macros]================================================*/
/* -------------------- Routing path: 0 Pdu_DIA_RGS_VL_Req */
#if (defined PduRConf_PduRSrcPdu_Sdu_Rx_Phys_VL)
#error PduRConf_PduRSrcPdu_Sdu_Rx_Phys_VL is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_Rx_Phys_VL 0U /* SRC CanTp-LO-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_Rx_Phys_VL)
#error PduR_Sdu_Rx_Phys_VL is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_Rx_Phys_VL 0U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Rx_Phys_d_VL)
#error PduRConf_PduRDestPdu_Sdu_Rx_Phys_d_VL is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Rx_Phys_d_VL 0U /* DEST BlPduR-UP-TP */


/* -------------------- Routing path: 1 Pdu_DIA_RGS_VL_Resp */
#if (defined PduRConf_PduRSrcPdu_Sdu_Tx_VL)
#error PduRConf_PduRSrcPdu_Sdu_Tx_VL is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_Tx_VL 0U /* SRC BlPduR-UP-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_Tx_VL)
#error PduR_Sdu_Tx_VL is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_Tx_VL 0U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Tx_d_VL)
#error PduRConf_PduRDestPdu_Sdu_Tx_d_VL is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Tx_d_VL 0U /* DEST CanTp-LO-TP */


/* -------------------- Routing path: 2 Pdu_DIA_RGS_VR_Req */
#if (defined PduRConf_PduRSrcPdu_Sdu_Rx_Phys_VR)
#error PduRConf_PduRSrcPdu_Sdu_Rx_Phys_VR is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_Rx_Phys_VR 1U /* SRC CanTp-LO-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_Rx_Phys_VR)
#error PduR_Sdu_Rx_Phys_VR is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_Rx_Phys_VR 1U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Rx_Phys_d_VR)
#error PduRConf_PduRDestPdu_Sdu_Rx_Phys_d_VR is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Rx_Phys_d_VR 1U /* DEST BlPduR-UP-TP */


/* -------------------- Routing path: 3 Pdu_DIA_RGS_VR_Resp */
#if (defined PduRConf_PduRSrcPdu_Sdu_Tx_VR)
#error PduRConf_PduRSrcPdu_Sdu_Tx_VR is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_Tx_VR 1U /* SRC BlPduR-UP-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_Tx_VR)
#error PduR_Sdu_Tx_VR is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_Tx_VR 1U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Tx_d_VR)
#error PduRConf_PduRDestPdu_Sdu_Tx_d_VR is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Tx_d_VR 1U /* DEST CanTp-LO-TP */


/* -------------------- Routing path: 4 Pdu_Diag_RGS_VL_Req */
#if (defined PduRConf_PduRSrcPdu_Sdu_Diag_RGS_VL_Req)
#error PduRConf_PduRSrcPdu_Sdu_Diag_RGS_VL_Req is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_Diag_RGS_VL_Req 2U /* SRC CanTp-LO-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_Diag_RGS_VL_Req)
#error PduR_Sdu_Diag_RGS_VL_Req is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_Diag_RGS_VL_Req 2U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Diag_RGS_VL_Req_D)
#error PduRConf_PduRDestPdu_Sdu_Diag_RGS_VL_Req_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Diag_RGS_VL_Req_D 2U /* DEST BlPduR-UP-TP */


/* -------------------- Routing path: 5 Pdu_Diag_RGS_VL_Resp */
#if (defined PduRConf_PduRSrcPdu_Sdu_Diag_RGS_VL_Resp)
#error PduRConf_PduRSrcPdu_Sdu_Diag_RGS_VL_Resp is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_Diag_RGS_VL_Resp 2U /* SRC BlPduR-UP-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_Diag_RGS_VL_Resp)
#error PduR_Sdu_Diag_RGS_VL_Resp is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_Diag_RGS_VL_Resp 2U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Diag_RGS_VL_Resp_D)
#error PduRConf_PduRDestPdu_Sdu_Diag_RGS_VL_Resp_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Diag_RGS_VL_Resp_D 2U /* DEST CanTp-LO-TP */


/* -------------------- Routing path: 6 Pdu_Diag_RGS_VR_Req */
#if (defined PduRConf_PduRSrcPdu_Sdu_Diag_RGS_VR_Req)
#error PduRConf_PduRSrcPdu_Sdu_Diag_RGS_VR_Req is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_Diag_RGS_VR_Req 3U /* SRC CanTp-LO-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_Diag_RGS_VR_Req)
#error PduR_Sdu_Diag_RGS_VR_Req is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_Diag_RGS_VR_Req 3U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Diag_RGS_VR_Req_D)
#error PduRConf_PduRDestPdu_Sdu_Diag_RGS_VR_Req_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Diag_RGS_VR_Req_D 3U /* DEST BlPduR-UP-TP */


/* -------------------- Routing path: 7 Pdu_Diag_RGS_VR_Resp */
#if (defined PduRConf_PduRSrcPdu_Sdu_Diag_RGS_VR_Resp)
#error PduRConf_PduRSrcPdu_Sdu_Diag_RGS_VR_Resp is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_Diag_RGS_VR_Resp 3U /* SRC BlPduR-UP-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_Diag_RGS_VR_Resp)
#error PduR_Sdu_Diag_RGS_VR_Resp is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_Diag_RGS_VR_Resp 3U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Diag_RGS_VR_Resp_D)
#error PduRConf_PduRDestPdu_Sdu_Diag_RGS_VR_Resp_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Diag_RGS_VR_Resp_D 3U /* DEST CanTp-LO-TP */


/* -------------------- Routing path: 8 Pdu_OBDC_SSN_RGS_VL_Resp */
#if (defined PduRConf_PduRSrcPdu_Sdu_OBDC_SSN_RGS_VL_Resp)
#error PduRConf_PduRSrcPdu_Sdu_OBDC_SSN_RGS_VL_Resp is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_OBDC_SSN_RGS_VL_Resp 4U /* SRC BlPduR-UP-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_OBDC_SSN_RGS_VL_Resp)
#error PduR_Sdu_OBDC_SSN_RGS_VL_Resp is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_OBDC_SSN_RGS_VL_Resp 4U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Diag_OBDC_SSN_RGS_VL_Resp_D)
#error PduRConf_PduRDestPdu_Sdu_Diag_OBDC_SSN_RGS_VL_Resp_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Diag_OBDC_SSN_RGS_VL_Resp_D 4U /* DEST CanTp-LO-TP */


/* -------------------- Routing path: 9 Pdu_OBDC_SSN_RGS_VL_Req */
#if (defined PduRConf_PduRSrcPdu_Sdu_Diag_OBDC_SSN_RGS_VL_Req)
#error PduRConf_PduRSrcPdu_Sdu_Diag_OBDC_SSN_RGS_VL_Req is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_Diag_OBDC_SSN_RGS_VL_Req 4U /* SRC CanTp-LO-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_Diag_OBDC_SSN_RGS_VL_Req)
#error PduR_Sdu_Diag_OBDC_SSN_RGS_VL_Req is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_Diag_OBDC_SSN_RGS_VL_Req 4U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Diag_OBDC_SSN_RGS_VL_Req_D)
#error PduRConf_PduRDestPdu_Sdu_Diag_OBDC_SSN_RGS_VL_Req_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Diag_OBDC_SSN_RGS_VL_Req_D 4U /* DEST BlPduR-UP-TP */


/* -------------------- Routing path: 10 Pdu_OBDC_SSN_RGS_VR_Resp */
#if (defined PduRConf_PduRSrcPdu_Sdu_OBDC_SSN_RGS_VR_Resp)
#error PduRConf_PduRSrcPdu_Sdu_OBDC_SSN_RGS_VR_Resp is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_OBDC_SSN_RGS_VR_Resp 5U /* SRC BlPduR-UP-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_OBDC_SSN_RGS_VR_Resp)
#error PduR_Sdu_OBDC_SSN_RGS_VR_Resp is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_OBDC_SSN_RGS_VR_Resp 5U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Diag_OBDC_SSN_RGS_VR_Resp_D)
#error PduRConf_PduRDestPdu_Sdu_Diag_OBDC_SSN_RGS_VR_Resp_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Diag_OBDC_SSN_RGS_VR_Resp_D 5U /* DEST CanTp-LO-TP */


/* -------------------- Routing path: 11 Pdu_OBDC_SSN_RGS_VR_Req */
#if (defined PduRConf_PduRSrcPdu_Sdu_Diag_OBDC_SSN_RGS_VR_Req)
#error PduRConf_PduRSrcPdu_Sdu_Diag_OBDC_SSN_RGS_VR_Req is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRSrcPdu_Sdu_Diag_OBDC_SSN_RGS_VR_Req 5U /* SRC CanTp-LO-TP */

#if (defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined PduR_Sdu_Diag_OBDC_SSN_RGS_VR_Req)
#error PduR_Sdu_Diag_OBDC_SSN_RGS_VR_Req is already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <= AUTOSAR version) */
#define PduR_Sdu_Diag_OBDC_SSN_RGS_VR_Req 5U
#endif /* defined PDUR_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined PduRConf_PduRDestPdu_Sdu_Diag_OBDC_SSN_RGS_VR_Req_D)
#error PduRConf_PduRDestPdu_Sdu_Diag_OBDC_SSN_RGS_VR_Req_D is already defined
#endif
/** \brief Export symbolic name value */
#define PduRConf_PduRDestPdu_Sdu_Diag_OBDC_SSN_RGS_VR_Req_D 5U /* DEST BlPduR-UP-TP */



/* Define vendor specific destination PDU IDs of adjacent modules */
#if (defined PDUR_PROVIDE_ADJACENT_MODULE_VENDOR_SYMBOLIC_NAMES)

/* -------------------- Routing path: 0 Pdu_DIA_RGS_VL_Req */
#define PDURSA_Sdu_DIA_RGS_VL_Req 0U /* SRC CanTp-LO-TP */
#define PDURDA_Sdu_DIA_RGS_VL_Req 0U /* DEST BlPduR-UP-TP */

/* -------------------- Routing path: 1 Pdu_DIA_RGS_VL_Resp */
#define PDURSA_Sdu_DIA_RGS_VL_Resp 0U /* SRC BlPduR-UP-TP */
#define PDURDA_Sdu_DIA_RGS_VL_Resp 0U /* DEST CanTp-LO-TP */

/* -------------------- Routing path: 2 Pdu_DIA_RGS_VR_Req */
#define PDURSA_Sdu_DIA_RGS_VR_Req 1U /* SRC CanTp-LO-TP */
#define PDURDA_Sdu_DIA_RGS_VR_Req 1U /* DEST BlPduR-UP-TP */

/* -------------------- Routing path: 3 Pdu_DIA_RGS_VR_Resp */
#define PDURSA_Sdu_DIA_RGS_VR_Resp 1U /* SRC BlPduR-UP-TP */
#define PDURDA_Sdu_DIA_RGS_VR_Resp 1U /* DEST CanTp-LO-TP */

/* -------------------- Routing path: 4 Pdu_Diag_RGS_VL_Req */
#define PDURSA_Sdu_Diag_RGS_VL_Req 2U /* SRC CanTp-LO-TP */
#define PDURDA_Sdu_Diag_RGS_VL_Req 2U /* DEST BlPduR-UP-TP */

/* -------------------- Routing path: 5 Pdu_Diag_RGS_VL_Resp */
#define PDURSA_Sdu_Diag_RGS_VL_Resp 2U /* SRC BlPduR-UP-TP */
#define PDURDA_Sdu_Diag_RGS_VL_Resp 2U /* DEST CanTp-LO-TP */

/* -------------------- Routing path: 6 Pdu_Diag_RGS_VR_Req */
#define PDURSA_Sdu_Diag_RGS_VR_Req 3U /* SRC CanTp-LO-TP */
#define PDURDA_Sdu_Diag_RGS_VR_Req 3U /* DEST BlPduR-UP-TP */

/* -------------------- Routing path: 7 Pdu_Diag_RGS_VR_Resp */
#define PDURSA_Sdu_Diag_RGS_VR_Resp 3U /* SRC BlPduR-UP-TP */
#define PDURDA_Sdu_Diag_RGS_VR_Resp 3U /* DEST CanTp-LO-TP */

/* -------------------- Routing path: 8 Pdu_OBDC_SSN_RGS_VL_Resp */
#define PDURSA_Sdu_OBDC_SSN_RGS_VL_Resp 4U /* SRC BlPduR-UP-TP */
#define PDURDA_Sdu_OBDC_SSN_RGS_VL_Resp 4U /* DEST CanTp-LO-TP */

/* -------------------- Routing path: 9 Pdu_OBDC_SSN_RGS_VL_Req */
#define PDURSA_Sdu_OBDC_SSN_RGS_VL_Req 4U /* SRC CanTp-LO-TP */
#define PDURDA_Sdu_OBDC_SSN_RGS_VL_Req 4U /* DEST BlPduR-UP-TP */

/* -------------------- Routing path: 10 Pdu_OBDC_SSN_RGS_VR_Resp */
#define PDURSA_Sdu_OBDC_SSN_RGS_VR_Resp 5U /* SRC BlPduR-UP-TP */
#define PDURDA_Sdu_OBDC_SSN_RGS_VR_Resp 5U /* DEST CanTp-LO-TP */

/* -------------------- Routing path: 11 Pdu_OBDC_SSN_RGS_VR_Req */
#define PDURSA_Sdu_OBDC_SSN_RGS_VR_Req 5U /* SRC CanTp-LO-TP */
#define PDURDA_Sdu_OBDC_SSN_RGS_VR_Req 5U /* DEST BlPduR-UP-TP */

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

#endif /* if !defined( PDUR_SYMBOLIC_NAMES_PBCFG_H ) */
/*==================[end of file]===========================================*/
