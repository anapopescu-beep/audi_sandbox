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

#ifndef CRY_RSASSAV15VERIFYCONFIG_H
#define CRY_RSASSAV15VERIFYCONFIG_H

/*==[Includes]================================================================*/

#include <Std_Types.h>

#include <Csm_Types.h>
#include <Csm.h>

#include <Csm_Hash.h>

#include <Cry_LN.h>

/*==[Macros]==================================================================*/

#if (defined CRY_RSASSAV15VERIFY_ENABLED)
#error CRY_RSASSAV15VERIFY_ENABLED is already defined
#endif
/* !LINKSTO EB_CRY_0018,1 */
#define CRY_RSASSAV15VERIFY_ENABLED STD_OFF

#if(CRY_RSASSAV15VERIFY_ENABLED == STD_ON)

#if (defined CRY_RSASSAV15VERIFY_USE_TIME_SLICES)
#error CRY_RSASSAV15VERIFY_USE_TIME_SLICES is already defined
#endif
#define CRY_RSASSAV15VERIFY_USE_TIME_SLICES STD_OFF

#if (defined CRY_RSASSAV15VERIFY_USE_CBK)
#error CRY_RSASSAV15VERIFY_USE_CBK is already defined
#endif
#define CRY_RSASSAV15VERIFY_USE_CBK STD_OFF

#if (defined CRY_RSASSAV15VERIFY_BARRETT)
#error CRY_RSASSAV15VERIFY_BARRETT is already defined
#endif
#define CRY_RSASSAV15VERIFY_BARRETT STD_OFF

#if (defined CRY_SIGN_VRFY_V15_IMMEDIATE_RESTART_ENABLED)
#error CRY_SIGN_VRFY_V15_IMMEDIATE_RESTART_ENABLED is already defined
#endif
/** \brief Flag to indicate if the immediate restart of the service regardless of the configuration ID is enabled. */
#define CRY_SIGN_VRFY_V15_IMMEDIATE_RESTART_ENABLED STD_OFF

/*==[Types]===================================================================*/

/* !LINKSTO EB_CRY_0017,1 */
/**
 * \struct Cry_RsaSsaV15VerifyConfigType
 * \brief The configuration of the RSASSA-PKCS1-v1_5 signature verification.
 *//**
 * \var Cry_RsaSsaV15VerifyConfigType::HashCfg
 * \brief The configuration of the underlying hash algorithm.
 *//**
 * \var Cry_RsaSsaV15VerifyConfigType::Base64Encoded
 * \brief Indicates whether the signature to verify is base64-encoded.
 *//**
 * \var Cry_RsaSsaV15VerifyConfigType::UseBarrett
 * \brief Indicates whether the signature verification uses Barrett reduction. This
 *        member only exists when Barrett reduction is enabled in a configuration.
 *//**
 * \var Cry_RsaSsaV15VerifyConfigType::SupportRestart
 * \brief Indicates whether restarting of the signature verification feature is
 *        enabled or not.
 */
typedef struct
{
  Csm_ConfigIdType HashCfg;
  boolean          Base64Encoded;
  boolean          SupportRestart;
}
Cry_RsaSsaV15VerifyConfigType;

/*==[Constants with external linkage]=========================================*/

#define CRY_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/* !LINKSTO EB_CRY_0023,1 */


#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/
#endif /* #if(CRY_RSASSAV15VERIFY_ENABLED == STD_ON) */

#endif /* CRY_RSASSAV15VERIFYCONFIG_H */
