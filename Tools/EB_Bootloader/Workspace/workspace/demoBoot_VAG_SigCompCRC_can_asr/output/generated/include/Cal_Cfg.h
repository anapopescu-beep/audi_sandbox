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

#ifndef CAL_CFG_H
#define CAL_CFG_H
/* !LINKSTO CAL0003, 1
 */


/*==[Includes]================================================================*/

/* !LINKSTO CAL0008, 1
 */
#include <Cal_Types.h>


/*==[Macros]==================================================================*/



/*==[Types]===================================================================*/



/*==[Constants with external linkage]=========================================*/



/*==[Variables with external linkage]=========================================*/



/*==[Declaration of functions with external linkage]==========================*/

#define CAL_START_SEC_CODE
#include <MemMap.h>


#define CAL_STOP_SEC_CODE
#include <MemMap.h>


#endif /* #ifndef CAL_CFG_H */

