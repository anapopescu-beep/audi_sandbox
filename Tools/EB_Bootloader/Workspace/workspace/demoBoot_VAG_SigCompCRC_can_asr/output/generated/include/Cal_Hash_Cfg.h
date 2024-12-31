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

#ifndef CAL_HASH_CFG_H
#define CAL_HASH_CFG_H


/*==[Includes]================================================================*/

#include <Cal_Types.h>


/*==[Macros]==================================================================*/
#define CAL_HASH_ENABLED FALSE

#if (CAL_HASH_ENABLED == TRUE)

/** \brief length of the hash context buffers, in elements of type ::Cal_AlignType
 */
#define CAL_HASH_CONTEXT_BUFFER_SIZE \
  CAL_LEN_IN_ALIGN_TYPE(316U)

/* !LINKSTO CAL0026, 1
 */

/** \brief Macro defining the amount of existing configurations for the Hash service
 */
#define CAL_HASH_CONFIG_COUNT 0U

/*==[Types]===================================================================*/


/*==[Constants with external linkage]=========================================*/


/*==[Variables with external linkage]=========================================*/



/*==[Declaration of functions with external linkage]==========================*/
#endif /* #if (CAL_HASH_ENABLED == TRUE) */

#endif /* #ifndef CAL_HASH_CFG_H */

