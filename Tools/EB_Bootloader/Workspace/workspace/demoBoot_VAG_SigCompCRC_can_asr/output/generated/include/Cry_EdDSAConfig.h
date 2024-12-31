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

#ifndef CRY_EDDSACONFIG_H_
#define CRY_EDDSACONFIG_H_

/*==[Includes]================================================================*/

#include <Std_Types.h>

#include <Csm.h>

#include <Cry_LN.h>
#include <Cry_Common.h>

/*==[Macros]==================================================================*/

#if (defined CRY_EdDSA_ENABLED)
#error CRY_EdDSA_ENABLED is already defined
#endif
#define CRY_EdDSA_ENABLED    STD_OFF

/*==[Types]===================================================================*/

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/

#endif /* CRY_EDDSACONFIG_H_ */
