/**
 * \file
 *
 * \brief AUTOSAR Det
 *
 * This file contains the implementation of the AUTOSAR
 * module Det.
 *
 * \version 6.5.10
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* This file contains all definitions of the configuration of the AUTOSAR
 * module Det that are target independent. */

/*==[Includes]================================================================*/

#include <Std_Types.h>
#include <Det_Int.h>

/*==[Macros]==================================================================*/

/*==[Types]===================================================================*/

/*==[Declaration of functions with internal linkage]==========================*/

/*==[Constants with internal linkage]=========================================*/

/*==[Variables with internal linkage]=========================================*/

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Definition of functions with external linkage]===========================*/

#if ((DET_REPORT_ERROR_STOP_EXECUTION == TRUE) && (DET_LOGMODE == DET_LOGMODE_INTERNAL))

#define DET_START_SEC_CODE
/* !LINKSTO Det.EB.req.bsw_include,1 */
#include <Det_MemMap.h>

FUNC(void, DET_CODE) Det_StopExecution(uint8 ErrorType)
{
  if (ErrorType == DET_DEVELOPMENT_ERROR_TYPE)
  {
    while (1)
    {
      ;
    }
  }
}

#define DET_STOP_SEC_CODE
/* !LINKSTO Det.EB.req.bsw_include,1 */
#include <Det_MemMap.h>

#endif /* (DET_REPORT_ERROR_STOP_EXECUTION == TRUE) && (DET_LOGMODE == DET_LOGMODE_INTERNAL) */

/*==[Definition of functions with internal linkage]===========================*/

