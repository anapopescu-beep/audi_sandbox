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

/* !LINKSTO EB_CRY_0006,1 */

/*==[Includes]================================================================*/

#include <Std_Types.h>

#include <Csm_Types.h>
#include <Csm_Hash.h>
#include <Csm.h>

#include <Cry_SHA2.h>
#include <Cry_Common.h>

#if (CRY_SHA2_ENABLED == STD_ON)

/*==[Macros]==================================================================*/

/*==[Types]===================================================================*/

/*==[Declaration of functions with internal linkage]==========================*/

/*==[Constants with internal linkage]=========================================*/

#define CRY_START_SEC_CONST_8
#include <MemMap.h>

/** \brief The algorithm identifier
 **
 ** This constant contains the algorithm identifier for each SHA2 configuration.
 **/

static CONST(uint8, CRY_CONST) CrySHA2Config_0_AlgorithmId[] = { CRY_SHA_256_ALGORITHM_ID };


#define CRY_STOP_SEC_CONST_8
#include <MemMap.h>

/*==[Variables with internal linkage]=========================================*/

/*==[Constants with external linkage]=========================================*/

#define CRY_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/** \brief SHA2 Configuration
 **
 ** One of the configurations of the SHA2 computation
 **/

CONST(Cry_SHAConfigType, CRY_CONST) CrySHA2Config_0 =
{
  sizeof(CrySHA2Config_0_AlgorithmId),

  CRY_SHA256_HASH_LEN_BYTES,

  CrySHA2Config_0_AlgorithmId,
  1U,

  TRUE
};

#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/

#else /* #if (CRY_SHA2_ENABLED == STD_ON) */

typedef uint8 Cry_SHA2_PrvtEmptyTranslationUnitType;

#endif /* #if (CRY_SHA2_ENABLED == STD_ON) #else */
