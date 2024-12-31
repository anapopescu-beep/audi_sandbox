/**
 * \file
 *
 * \brief AUTOSAR Cry
 *
 * This file contains the implementation of the AUTOSAR
 * module Cry.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO EB_CRY_0003,1 */

#ifndef CRY_SSGSTATECONFIG_H
#define CRY_SSGSTATECONFIG_H

/*==[Includes]================================================================*/

#include <Std_Types.h>

#include <Csm_Types.h>
#include <Csm.h>

#include <Cry_Common.h>

/*==[Macros]==================================================================*/

#if (defined CRY_SSGSTATE_ENABLED)
#error CRY_SSGSTATE_ENABLED is already defined
#endif
#define CRY_SSGSTATE_ENABLED STD_OFF

#if (CRY_SSGSTATE_ENABLED == STD_ON)

/*==[Types]===================================================================*/

/* !LINKSTO EB_CRY_0017,1 */
/** \brief The configuration of the SSG
 **
 ** \var Cry_SSGConfigType::LfsrState
 ** \brief A pointer to the start of an array which contains a state of
 ** the linear feedback shift register which is the base for the SSG.
 **
 ** \var Cry_SSGConfigType::CfgId
 **  \brief A number which identifies the configuration
 **
 **/

typedef struct
{
   P2VAR(uint8, TYPEDEF, CRY_APPL_DATA) LfsrState;
   uint8                                CfgId;
}
Cry_SSGConfigType;


typedef uint8 Cry_SSGStateType[1];

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

#define CRY_START_SEC_VAR_INIT_UNSPECIFIED
#include <MemMap.h>

/* !LINKSTO EB_CRY_0023,1 */


#define CRY_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <MemMap.h>

/*==[Declaration of functions with external linkage]==========================*/

#endif /* #if (CRY_SSG_ENABLED == STD_ON) */

#endif
