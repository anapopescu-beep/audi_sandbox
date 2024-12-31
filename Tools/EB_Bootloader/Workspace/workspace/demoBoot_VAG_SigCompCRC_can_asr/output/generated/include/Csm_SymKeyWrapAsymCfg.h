/**
 * \file
 *
 * \brief AUTOSAR Csm
 *
 * This file contains the implementation of the AUTOSAR
 * module Csm.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*================================================================================================*/

/*  MISRA-C:2004 Deviation List
 *
 *  MISRA-1) Deviated Rule: 8.8 (required)
 *   "An external object or function shall be declared in one and only one file."
 *
 *   Reason:
 *   For each provided Csm service, the used callback functions are declared independent from the
 *   callbacks used for other services. The redundant redeclaration of callback functions are caused
 *   by certain test configurations, which use the same callback for
 *   different Csm services.
 */


#ifndef CSM_SYMKEYWRAPASYMCFG_H
#define CSM_SYMKEYWRAPASYMCFG_H

/*==================[includes]====================================================================*/

#include <Csm_Cfg.h>
#include <Csm_Types.h>

/*==================[macros]======================================================================*/

/* !LINKSTO CSM0015, 1
 */
#define  CSM_SYMKEYWRAPASYM_ENABLED  STD_OFF

/** \brief Macro indicating whether there is an Rte Interface for the SymKeyWrapAsym service.
 */
#define  CSM_SYMKEYWRAPASYM_RTE_INTERFACE_ENABLED  STD_OFF

/** \brief Macro indicating whether the immediate restart feature is enabled for the SymKeyWrapAsym service.
 */
#define  CSM_SYMKEYWRAPASYM_IMMEDIATE_RESTART_ENABLED  STD_OFF

/** \brief Macro indicating whether there is an Synchronous Interface for the SymKeyWrapAsym service.
 */
#define  CSM_SYMKEYWRAPASYM_SYNCJOBPROCESSING_ENABLED  STD_OFF

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/

/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #ifndef CSM_SYMKEYWRAPASYMCFG_H */

