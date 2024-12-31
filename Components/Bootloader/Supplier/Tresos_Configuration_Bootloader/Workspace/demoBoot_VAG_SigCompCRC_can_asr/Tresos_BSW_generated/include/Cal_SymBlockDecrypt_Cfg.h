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

#ifndef CAL_SYMBLOCKDECRYPT_CFG_H
#define CAL_SYMBLOCKDECRYPT_CFG_H


/*==================[includes]====================================================================*/


#include <Cal_Types.h>

/*==================[macros]======================================================================*/

#define CAL_SYMBLOCKDECRYPT_ENABLED FALSE

#if (CAL_SYMBLOCKDECRYPT_ENABLED == TRUE)

#define CAL_SYMBLOCKDECRYPT_CTX_BUF_SIZE \
  CAL_LEN_IN_ALIGN_TYPE(348U)

/* !LINKSTO CAL0026, 1
 */

/** \brief Macro defining the amount of existing configurations for the symmetrical block decryption
 *         service
 */
#define CAL_SYMBLOCKDECRYPT_CONFIG_COUNT \
  0U


/*==================[type definitions]============================================================*/


/*==================[external function declarations]==============================================*/


/*==================[external constants]==========================================================*/


/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #if (CAL_SYMBLOCKDECRYPT_ENABLED == TRUE) */

#endif /* #ifndef CAL_SYMBLOCKDECRYPT_CFG_H */

