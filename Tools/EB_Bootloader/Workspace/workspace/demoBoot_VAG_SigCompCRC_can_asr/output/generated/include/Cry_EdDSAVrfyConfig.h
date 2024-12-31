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

#ifndef CRY_EDDSA_V_CGF_H
#define CRY_EDDSA_V_CGF_H

/*==[Includes]================================================================*/
#include <Std_Types.h>

#include <Csm.h>
#include <Csm_Hash.h>
#include <Csm_Types.h>

#include <Cry_LN.h>
#include <Cry_EdDSA.h>

/*==[Macros]==================================================================*/

#if (defined CRY_EDDSA_VRFY_ENABLED)
#error CRY_EDDSA_VRFY_ENABLED is already defined
#endif
#define CRY_EDDSA_VRFY_ENABLED STD_OFF

#if (CRY_EDDSA_VRFY_ENABLED == STD_ON)

#if (defined CRY_EDDSAVRFY_IMMEDIATE_RESTART_ENABLED)
#error CRY_EDDSAVRFY_IMMEDIATE_RESTART_ENABLED is already defined
#endif
/** \brief Flag to indicate if the immediate restart of the service regardless of the configuration ID is enabled. */
#define CRY_EDDSAVRFY_IMMEDIATE_RESTART_ENABLED STD_OFF

/*==[Types]===================================================================*/
/**
 * \struct Cry_EdDSAVrfyConfigType
 * \brief The configuration of the Ed25519ph signature verification.
 *//**
 * \var Cry_EdDSAVrfyConfigType::HashCfg
 * \brief The configuration of the underlying hash algorithm.
 *//**
 * \var Cry_EdDSAVrfyConfigType::SupportRestart
 * \brief Indicates whether restarting of the signature verification feature is
 *        enabled or not.
 *//**
 * \var Cry_EdDSAVrfyConfigType::NumberOfTimeSlices
 * \brief The configured number of time slices for long number or point operations
 *        during one main function call.
 */
typedef struct
{
  Csm_ConfigIdType   HashCfg;
  boolean            SupportRestart;
  /* !LINKSTO EB_Cry_Slicing_Cfg_CryEdDSASignatureVerifyTimeSlices,1 */
  uint16             NumberOfTimeSlices;
}
Cry_EdDSAVrfyConfigType;

/*==[Constants with external linkage]=========================================*/

#define CRY_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>


#define CRY_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>
/*================================================================================*/

#endif /* #if (CRY_EDDSA_VRFY_ENABLED == STD_ON) */

#endif /* CRY_EDDSA_V_CGF_H */
