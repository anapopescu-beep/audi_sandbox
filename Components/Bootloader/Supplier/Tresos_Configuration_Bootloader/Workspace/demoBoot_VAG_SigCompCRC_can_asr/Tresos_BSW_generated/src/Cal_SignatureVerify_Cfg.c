/**
 * \file
 *
 * \brief AUTOSAR Cal
 *
 * This file contains the implementation of the AUTOSAR
 * module Cal.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==[Includes]================================================================*/

#include <Cal_Types.h>

#include <Cal_SignatureVerify.h>
#include <Cal_SignatureVerify_Cfg.h>

#if (CAL_SIG_VRFY_ENABLED == TRUE)

/* !LINKSTO CAL0008, 1
 */


/*==[Macros]==================================================================*/



/*==[Types]===================================================================*/



/*==[Declaration of functions with internal linkage]==========================*/



/*==[Constants with internal linkage]=========================================*/



/*==[Variables with internal linkage]=========================================*/



/*==[Variables with external linkage]=========================================*/



/*==[Constants with external linkage]=========================================*/

#define CAL_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

CONST(Cal_SignatureVerifyConfigType, CAL_CONST)
  Cal_SigVerifyConfigurations[CAL_SIGVRFY_CONFIG_COUNT] =
{
};

#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>


/*==[Definition of functions with external linkage]===========================*/



/*==[Definition of functions with internal linkage]===========================*/
#else /* #if (CAL_SIG_VRFY_ENABLED == TRUE) */


/** Dummy definition preventing this file from being empty, if there is no SignatureVerify
 *  configuration.
 */
typedef void CalPrvntEmptyTranslationUnit_t;



#endif /* #if (CAL_SIG_VRFY_ENABLED == TRUE) #else */

