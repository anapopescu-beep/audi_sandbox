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

#ifndef CAL_KEYEXCHANGE_CFG_H
#define CAL_KEYEXCHANGE_CFG_H


/*==[Includes]================================================================*/


#include <Cal_Types.h>



/*==[Macros]==================================================================*/

#define CAL_KEYEXCHANGE_PUBVAL_ENABLED FALSE

#define CAL_KEYEXCHANGE_SECRET_ENABLED FALSE

#if ((CAL_KEYEXCHANGE_PUBVAL_ENABLED == TRUE) || (CAL_KEYEXCHANGE_SECRET_ENABLED == TRUE))


/** \brief size of the context buffer required for key exchange protocol.
 */
#define CAL_KEYEXCHANGE_CONTEXT_BUFFER_SIZE \
  CAL_LEN_IN_ALIGN_TYPE(100U)




/* !LINKSTO CAL0026, 1
 */

/** \brief Macro defining the amount of existing configurations for the public value calculation of
 *         the key exchange service
 */
#define CAL_KEYEXPUBVAL_CONFIG_COUNT \
  0U

/** \brief Macro defining the amount of existing configurations for the secret calculation of the
 *         key exchange service
 */
#define CAL_KEYEXSECRET_CONFIG_COUNT \
  0U


/*==[Types]===================================================================*/


/*==[Constants with external linkage]=========================================*/


/*==[Variables with external linkage]=========================================*/

/*==[Declaration of functions with external linkage]==========================*/

#endif /*#if ((CAL_KEYEXCHANGE_PUBVAL_ENABLED == TRUE)||(CAL_KEYEXCHANGE_SECRET_ENABLED == TRUE))*/


#endif /* #ifndef CAL_KEYEXCHANGE_CFG_H */

