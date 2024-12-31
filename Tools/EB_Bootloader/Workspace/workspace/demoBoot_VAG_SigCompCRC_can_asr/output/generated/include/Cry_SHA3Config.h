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


#ifndef CRY_SHA3CONFIG_H
#define CRY_SHA3CONFIG_H

/*==[Includes]================================================================*/

#include <Std_Types.h>

#include <Csm_Types.h>
#include <Csm.h>
#include <Cry_SHA_CommonConfig.h>

/*==[Macros]==================================================================*/

/* !LINKSTO EB_CRY_0018,1 */
#if (defined CRY_SHA3_ENABLED)
#error CRY_SHA3_ENABLED is already defined
#endif
#define CRY_SHA3_ENABLED STD_OFF

/*==[Types]===================================================================*/

/*==[Constants with external linkage]=========================================*/


/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/

#endif
