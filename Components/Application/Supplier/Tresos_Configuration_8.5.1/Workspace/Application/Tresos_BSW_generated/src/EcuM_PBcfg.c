/**
 * \file
 *
 * \brief AUTOSAR EcuM
 *
 * This file contains the implementation of the AUTOSAR
 * module EcuM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO EcuM2988,1 */
/*==================[inclusions]============================================*/

#include <EcuM.h>         /* EcuM public header */
#include <EcuM_Int.h>     /* EcuM private header */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external constants]====================================*/
#define ECUM_START_SEC_CONST_UNSPECIFIED
#include <EcuM_MemMap.h>

CONST(EcuM_ConfigType, ECUM_CONST) EcuM_Config_0 =
{

  OSDEFAULTAPPMODE,  /* DefaultAppMode */
  &EcuM_DriverInitListOne,
  NULL_PTR,
  ECUM_STATE_OFF, /* DefaultShutdownTarget */
  0U,
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
#include <EcuM_MemMap.h>

/*==================[external data]=========================================*/

/*==================[internal function definitions]=========================*/

/*==================[external function definitions]=========================*/

/*==================[end of file]===========================================*/

