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

#ifndef CRY_CBCPKCS7DECRYPTCONFIG_H
#define CRY_CBCPKCS7DECRYPTCONFIG_H

/*==================[includes]====================================================================*/

#include <Std_Types.h>

#include <Csm.h>

/*==================[macros]======================================================================*/

#if (defined CRY_CBC_PKCS7_DEC_ENABLED)
#error CRY_CBC_PKCS7_DEC_ENABLED is already defined
#endif
/* !LINKSTO EB_CRY_0018,1 */
#define CRY_CBC_PKCS7_DEC_ENABLED STD_OFF

#if (CRY_CBC_PKCS7_DEC_ENABLED == STD_ON)

/*==================[type definitions]============================================================*/

/* !LINKSTO EB_CRY_0017,1 */
/** \brief  Configuration type for representing a configured AES algorithm.
 **/
typedef struct
{
  Csm_ConfigIdType symBlockDecryptCfgId;
}
Cry_CbcPkcs7DecryptConfigType;

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/



/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #if (CRY_CBC_PKCS7_DEC_ENABLED == STD_ON) */

#endif /* #ifndef CRY_CBC_PKCS7_DECCONFIG_H */
