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


  #if (!defined CANIF_SYMBOLICNAMES_PBCFG_H)
#define CANIF_SYMBOLICNAMES_PBCFG_H

/*==================[includes]===============================================*/
/*==================[macros]=================================================*/

/*------------------[symbolic name values]----------------------------------*/

/** \brief Export symbolic name values for CanIfTxPduIds */


#if (defined CanIfConf_CanIfTxPduCfg_Pdu_Tx_1)
#error CanIfConf_CanIfTxPduCfg_Pdu_Tx_1 already defined!
#endif /* #if( defined CanIfConf_CanIfTxPduCfg_Pdu_Tx_1)*/
#define CanIfConf_CanIfTxPduCfg_Pdu_Tx_1 0U

#if (defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <=
AUTOSAR version) */
#if (defined CanIf_Pdu_Tx_1)
#error CanIf_Pdu_Tx_1 already defined!
#endif /* #if( defined CanIf_Pdu_Tx_1)*/
#define CanIf_Pdu_Tx_1 0U
#endif /* defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined CanIfConf_CanIfTxPduCfg_Pdu_Tx_2)
#error CanIfConf_CanIfTxPduCfg_Pdu_Tx_2 already defined!
#endif /* #if( defined CanIfConf_CanIfTxPduCfg_Pdu_Tx_2)*/
#define CanIfConf_CanIfTxPduCfg_Pdu_Tx_2 1U

#if (defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <=
AUTOSAR version) */
#if (defined CanIf_Pdu_Tx_2)
#error CanIf_Pdu_Tx_2 already defined!
#endif /* #if( defined CanIf_Pdu_Tx_2)*/
#define CanIf_Pdu_Tx_2 1U
#endif /* defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */


/** \brief Export symbolic name values for CanIfRxPduIds */


#if (defined CanIfConf_CanIfRxPduCfg_Pdu_Rx_Func)
#error CanIfConf_CanIfRxPduCfg_Pdu_Rx_Func already defined!
#endif /* #if( defined CanIfConf_CanIfRxPduCfg_Pdu_Rx_Func)*/
#define CanIfConf_CanIfRxPduCfg_Pdu_Rx_Func 0U

#if (defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <=
AUTOSAR version) */
#if (defined CanIf_Pdu_Rx_Func)
#error CanIf_Pdu_Rx_Func already defined!
#endif /* #if( defined CanIf_Pdu_Rx_Func)*/
#define CanIf_Pdu_Rx_Func 0U
#endif /* defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined CanIfConf_CanIfRxPduCfg_Pdu_Rx_Phys)
#error CanIfConf_CanIfRxPduCfg_Pdu_Rx_Phys already defined!
#endif /* #if( defined CanIfConf_CanIfRxPduCfg_Pdu_Rx_Phys)*/
#define CanIfConf_CanIfRxPduCfg_Pdu_Rx_Phys 1U

#if (defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <=
AUTOSAR version) */
#if (defined CanIf_Pdu_Rx_Phys)
#error CanIf_Pdu_Rx_Phys already defined!
#endif /* #if( defined CanIf_Pdu_Rx_Phys)*/
#define CanIf_Pdu_Rx_Phys 1U
#endif /* defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */


/** \brief Export symbolic name values for CanIfCtrlIds */


#if (defined CanIfConf_CanIfCtrlDrvCfg_EcuTestNode)
#error CanIfConf_CanIfCtrlDrvCfg_EcuTestNode already defined!
#endif /* #if( defined CanIfConf_CanIfCtrlDrvCfg_EcuTestNode)*/
#define CanIfConf_CanIfCtrlDrvCfg_EcuTestNode 0U

#if (defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only (AUTOSAR 4.0 rev2 <=
AUTOSAR version) */
#if (defined CanIf_CanIfCtrlDrvCfg_EcuTestNode)
#error CanIf_CanIfCtrlDrvCfg_EcuTestNode already defined!
#endif /* #if( defined CanIf_CanIfCtrlDrvCfg_EcuTestNode)*/
#define CanIf_CanIfCtrlDrvCfg_EcuTestNode 0U
#endif /* defined CANIF_PROVIDE_LEGACY_SYMBOLIC_NAMES */


/** \brief Export symbolic name values for CanIfTrcvIds */

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* if !defined( CANIF_SYMBOLICNAMES_PBCFG_H ) */
/*==================[end of file]============================================*/
