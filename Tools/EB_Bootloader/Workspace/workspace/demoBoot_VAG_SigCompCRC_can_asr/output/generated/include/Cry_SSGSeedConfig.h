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

#ifndef CRY_SSGSEEDCONFIG_H
#define CRY_SSGSEEDCONFIG_H

/*==[Includes]================================================================*/

#include <Std_Types.h>

#include <Csm_Types.h>
#include <Csm.h>


/*==[Macros]==================================================================*/

#if (defined CRY_SSGSEED_ENABLED)
#error CRY_SSGSEED_ENABLED is already defined
#endif
/* !LINKSTO EB_CRY_0018,1 */
#define CRY_SSGSEED_ENABLED STD_OFF

#if (CRY_SSGSEED_ENABLED == STD_ON)

#if (defined CRY_SSGSEED_IMMEDIATE_RESTART_ENABLED)
#error CRY_SSGSEED_IMMEDIATE_RESTART_ENABLED is already defined
#endif
/** \brief Flag to indicate if the immediate restart of the service regardless of the configuration ID is enabled. */
#define CRY_SSGSEED_IMMEDIATE_RESTART_ENABLED STD_OFF

/*==[Types]===================================================================*/

/* !LINKSTO EB_CRY_0017,1 */
/** \brief The configuration of the SSG Seed
 **
 ** \var Cry_SSGSeedConfigType::LfsrState
 ** \brief A pointer to the start of an array which contains a state of
 ** the linear feedback shift register which is the base for the SSG Seed.
 **
 ** \var Cry_SSGSeedConfigType::CfgId
 **  \brief A number which identifies the configuration
 **
 **/
typedef struct
{
   P2VAR(uint8, TYPEDEF, CRY_APPL_DATA) LfsrState;
   uint8                                CfgId;
}
Cry_SSGSeedConfigType;

/*==[Constants with external linkage]=========================================*/

#define CRY_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/* !LINKSTO EB_CRY_0023,1 */


#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/

#endif /* #if (CRY_SSGSEED_ENABLED == STD_ON) */

#endif
