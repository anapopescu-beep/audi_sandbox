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

/*==[Includes]================================================================*/

#include <Std_Types.h>

#include <Cry_MD5Config.h>

#if (CRY_MD5_ENABLED == STD_ON)

/*==[Macros]==================================================================*/

/*==[Types]===================================================================*/

/*==[Declaration of functions with internal linkage]==========================*/

/*==[Constants with internal linkage]=========================================*/

/*==[Variables with internal linkage]=========================================*/

/*==[Constants with external linkage]=========================================*/

#define CRY_START_SEC_CONST_16
#include <MemMap.h>


#define CRY_STOP_SEC_CONST_16
#include <MemMap.h>

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/

#else /* #if (CRY_MD5_ENABLED == STD_ON) */


/** Dummy definition preventing this file from being empty, if there is no MD5 configuration.
 */
typedef void CryPrvntEmptyTranslationUnit_t;


#endif /* #if (CRY_MD5_ENABLED == STD_ON) #else */

