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

#include <Cal_MacGenerate.h>
#include <Cal_MacGenerate_Cfg.h>

#if (CAL_MAC_GENERATE_ENABLED == TRUE)

/* !LINKSTO CAL0008, 1
 */

/*==================[macros]======================================================================*/

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

/*==================[internal function declarations]==============================================*/

/*==================[external constants]==========================================================*/

#define CAL_START_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

CONST(Cal_MacGenerateConfigType, CAL_CONST) Cal_MacGenerateConfigurations[CAL_MACGEN_CONFIG_COUNT] =
{
};

#define CAL_STOP_SEC_CONST_UNSPECIFIED
#include <MemMap.h>

/*==================[internal constants]==========================================================*/

/*==================[external data]===============================================================*/

/*==================[internal data]===============================================================*/

/*==================[external function definitions]===============================================*/

/*==================[internal function definitions]===============================================*/
#else /* #if (CAL_MAC_GENERATE_ENABLED == TRUE) */

/** Dummy definition preventing this file from being empty, if there is no MacGenerate
 *  configuration.
 */
typedef void CalPrvntEmptyTranslationUnit_t;



#endif /* #if (CAL_MAC_GENERATE_ENABLED == TRUE) #else */

/*==================[end of file]=================================================================*/

