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

#ifndef CAL_SYMKEYEXTRACT_CFG_H
#define CAL_SYMKEYEXTRACT_CFG_H


/*==================[includes]====================================================================*/


#include <Cal_Types.h>

/*==================[macros]======================================================================*/

#define CAL_SYM_KEY_EXTRACT_ENABLED FALSE

#if (CAL_SYM_KEY_EXTRACT_ENABLED == TRUE)

/** \brief size in bytes of the context buffer configured for symmetrical key extraction.
*/
#define CAL_SYMKEYEXTRACT_CONTEXT_BUFFER_SIZE \
  CAL_LEN_IN_ALIGN_TYPE(72U)



/* !LINKSTO CAL0026, 1
 */

/** \brief Macro defining the amount of existing configurations for the symmetrical key extraction
 *        service
 */
#define CAL_SYMKEYEX_CONFIG_COUNT \
  0U


/*==================[type definitions]============================================================*/


/*==================[external function declarations]==============================================*/


/*==================[external constants]==========================================================*/


/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #if (CAL_SYM_KEY_EXTRACT_ENABLED == TRUE) */


#endif /* #ifndef CAL_SYMKEYEXTRACT_CFG_H */

