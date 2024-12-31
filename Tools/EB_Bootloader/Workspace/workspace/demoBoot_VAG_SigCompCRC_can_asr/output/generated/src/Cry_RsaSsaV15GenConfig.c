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

#include <Csm_Types.h>
#include <Csm_SignatureGenerate.h>
#include <Csm_Hash.h>

#include <Cry_LN.h>
#include <Cry_RsaSsaV15Gen.h>

#if (CRY_RSASSAV15_GEN_ENABLED == TRUE)

/*==[Macros]==================================================================*/

/*==[Types]===================================================================*/

/*==[Declaration of functions with internal linkage]==========================*/

/*==[Constants with internal linkage]=========================================*/

/*==[Variables with internal linkage]=========================================*/

/*==[Constants with external linkage]=========================================*/

#define CRY_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*
 * CHECK: NOPARSE

<api API="DATA_EXTERN_USER">
  <name>[CryRsaSsaV15GenerateConfig]</name>
  <synopsis>RSASSA-PKCS1-v1_5 signature generation configuration</synopsis>
  <syntax>
     CONST(Cry_RsaSsaV15GenConfigType, CRY_CONST) [CryRsaSsaV15GenerateConfig];
  </syntax>
  <description>
    One of the configurations of the RSASSA-PKCS1-v1_5 signature generation.
  </description>
  <value>
    Created from the configuration values.
  </value>
</api>

 * CHECK: PARSE
 */


#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/

/*==[Definition of functions with internal linkage]===========================*/

#else /* #if (CRY_RSASSAV15_GEN_ENABLED == TRUE) */

#define CRY_START_SEC_CONST_8
#include <MemMap.h>

typedef uint8 Cry_RsaSsaV15Gen_PrvtEmptyTranslationUnitType;

#define CRY_STOP_SEC_CONST_8
#include <MemMap.h>

#endif /* #if (CRY_RSASSAV15_GEN_ENABLED == TRUE) #else */
