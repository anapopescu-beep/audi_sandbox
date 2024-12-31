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
#ifndef CRY_CCMDECRYPTCONFIG_H
#define CRY_CCMDECRYPTCONFIG_H

/*==================[includes]====================================================================*/

#include <Std_Types.h>

#include <Csm.h>
#include <Cry_CCM_CommonConfig.h>

/*==================[macros]======================================================================*/

#if (defined CRY_CCM_DEC_ENABLED)
#error CRY_CCM_DEC_ENABLED is already defined
#endif
/* !LINKSTO EB_CRY_0018,1 */
#define CRY_CCM_DEC_ENABLED STD_OFF

#if (CRY_CCM_DEC_ENABLED == STD_ON)

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/

/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #if (CRY_CCM_DEC_ENABLED == STD_ON) */

#endif /* #ifndef CRY_CCMDECRYPTCONFIG_H */
