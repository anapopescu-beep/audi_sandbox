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

/*==================[includes]====================================================================*/

#include <Cal_Types.h>

#include <Cal_SymBlockEncrypt.h>
#include <Cal_SymBlockEncrypt_Cfg.h>

#if (CAL_SYMBLOCKENCRYPT_ENABLED == TRUE)

/* !LINKSTO CAL0008, 1
 */

/*==================[macros]======================================================================*/

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

/*==================[internal function declarations]==============================================*/

/*==================[external constants]==========================================================*/

#define CAL_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

CONST(Cal_SymBlockEncryptConfigType, CAL_CONST)
  Cal_SymBlockEncConfigurations[CAL_SYMBLOCKENCRYPT_CONFIG_COUNT] =
{
};

#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[internal constants]==========================================================*/

/*==================[external data]===============================================================*/

/*==================[internal data]===============================================================*/

/*==================[external function definitions]===============================================*/

/*==================[internal function definitions]===============================================*/

#else /* #if (CAL_SYMBLOCKENCRYPT_ENABLED == TRUE) */

/** Dummy definition preventing this file from being empty, if there is no SymBlockEncrypt
 *  configuration.
 */
typedef void CalPrvntEmptyTranslationUnit_t;

#endif /* #if (CAL_SYMBLOCKENCRYPT_ENABLED == TRUE) #else */

/*==================[end of file]=================================================================*/

