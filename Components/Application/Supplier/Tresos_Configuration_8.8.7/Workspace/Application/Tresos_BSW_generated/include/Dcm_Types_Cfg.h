/**
 * \file
 *
 * \brief AUTOSAR Dcm
 *
 * This file contains the implementation of the AUTOSAR
 * module Dcm.
 *
 * \version 5.0.15
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef DCM_TYPES_CFG_H
#define DCM_TYPES_CFG_H

/*==================[includes]===================================================================*/
/*==================[macros]=====================================================================*/

/* !LINKSTO Dcm.EB.SesCtrlType.RteUsageFalse,1 */
#if (DCM_INCLUDE_RTE == STD_OFF)
/*------------------[definitions of session levels]----------------------------------------------*/
#if (defined DcmConf_DcmDspSession_DCM_DEFAULT_SESSION)
#error DcmConf_DcmDspSession_DCM_DEFAULT_SESSION already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDspSession_DCM_DEFAULT_SESSION 1U

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DCM_DEFAULT_SESSION)
#error Dcm_DCM_DEFAULT_SESSION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DCM_DEFAULT_SESSION 1U
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DcmConf_DcmDspSession_DCM_PROGRAMMING_SESSION)
#error DcmConf_DcmDspSession_DCM_PROGRAMMING_SESSION already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDspSession_DCM_PROGRAMMING_SESSION 2U

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DCM_PROGRAMMING_SESSION)
#error Dcm_DCM_PROGRAMMING_SESSION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DCM_PROGRAMMING_SESSION 2U
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DcmConf_DcmDspSession_DCM_EXTENDED_SESSION)
#error DcmConf_DcmDspSession_DCM_EXTENDED_SESSION already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDspSession_DCM_EXTENDED_SESSION 3U

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DCM_EXTENDED_SESSION)
#error Dcm_DCM_EXTENDED_SESSION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DCM_EXTENDED_SESSION 3U
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DcmConf_DcmDspSession_DCM_SUPPLIER_SESSION)
#error DcmConf_DcmDspSession_DCM_SUPPLIER_SESSION already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDspSession_DCM_SUPPLIER_SESSION 126U

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DCM_SUPPLIER_SESSION)
#error Dcm_DCM_SUPPLIER_SESSION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DCM_SUPPLIER_SESSION 126U
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DcmConf_DcmDspSession_DCM_ELE_MANUFACTURING_SESSION)
#error DcmConf_DcmDspSession_DCM_ELE_MANUFACTURING_SESSION already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDspSession_DCM_ELE_MANUFACTURING_SESSION 96U

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DCM_ELE_MANUFACTURING_SESSION)
#error Dcm_DCM_ELE_MANUFACTURING_SESSION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DCM_ELE_MANUFACTURING_SESSION 96U
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DcmConf_DcmDspSession_DCM_SYSTEM_MANUFACTURING_SESSION)
#error DcmConf_DcmDspSession_DCM_SYSTEM_MANUFACTURING_SESSION already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDspSession_DCM_SYSTEM_MANUFACTURING_SESSION 97U

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DCM_SYSTEM_MANUFACTURING_SESSION)
#error Dcm_DCM_SYSTEM_MANUFACTURING_SESSION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DCM_SYSTEM_MANUFACTURING_SESSION 97U
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#endif /* #if (DCM_INCLUDE_RTE == STD_OFF) */

/*==================[type definitions]===========================================================*/
/*==================[external function declarations]=============================================*/
/*==================[internal function declarations]=============================================*/
/*==================[external constants]=========================================================*/
/*==================[internal data]==============================================================*/
/*==================[external function definitions]==============================================*/
/*==================[internal function definitions]==============================================*/

#endif /* ifndef DCM_TYPES_CFG_H */
/*==================[end of file]================================================================*/
