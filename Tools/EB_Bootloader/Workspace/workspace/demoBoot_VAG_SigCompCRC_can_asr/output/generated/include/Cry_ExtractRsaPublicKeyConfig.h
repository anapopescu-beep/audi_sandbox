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

#ifndef CRY_EXTRACTRSAPUBLICKEYCONFIG_H
#define CRY_EXTRACTRSAPUBLICKEYCONFIG_H

/*==================[includes]====================================================================*/

#include <Std_Types.h>

/*==================[macros]======================================================================*/

#if (defined CRY_EXTRACTRSAPUBLICKEY_ENABLED)
#error CRY_EXTRACTRSAPUBLICKEY_ENABLED is already defined
#endif
/** \brief Indicates whether a ExtractRsaPublicKey configuration exists.
 */
#define CRY_EXTRACTRSAPUBLICKEY_ENABLED FALSE

#if (CRY_EXTRACTRSAPUBLICKEY_ENABLED == TRUE)

/*==================[type definitions]============================================================*/

/*---[struct]-------------------------------------------------------------------------------------*/
/* !LINKSTO EB_CRY_0017, 1
 */
/** \brief  Configuration type for representing a configured RSA Public key extraction.
 **/
typedef struct
{
  uint32 KeyLength;
}
Cry_ExtractRsaPubKeyConfigType;

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/
/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #if (CRY_EXTRACTRSAPUBLICKEY_ENABLED == TRUE) */

#endif /* #ifndef CRY_EXTRACTRSAPUBLICKEYCONFIG_H */
