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

#ifndef CRY_AES_ENCRYPTCONFIG_H
#define CRY_AES_ENCRYPTCONFIG_H

/*==================[includes]====================================================================*/

#include <Std_Types.h>

#include <Cry_AES_CommonConfig.h>

/*==================[macros]======================================================================*/

#if (defined CRY_AES_ENCRYPT_ENABLED)
#error CRY_AES_ENCRYPT_ENABLED is already defined
#endif
/* !LINKSTO EB_CRY_0018,1 */
#define CRY_AES_ENCRYPT_ENABLED STD_OFF

#if (CRY_AES_ENCRYPT_ENABLED == STD_ON)

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/



/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #if (CRY_AES_ENCRYPT_ENABLED == STD_ON) */

#endif /* #ifndef CRY_AES_ENCRYPTCONFIG_H */
