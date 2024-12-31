/**
 * \file
 *
 * \brief AUTOSAR Dcm
 *
 * This file contains the implementation of the AUTOSAR
 * module Dcm.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined DCM_API_CFG_H)
#define DCM_API_CFG_H

/*==================[includes]===================================================================*/

#include <Dcm_Types.h>

/*==================[macros]=====================================================================*/



/*==================[type definitions]===========================================================*/

/*==================[external function declarations]=============================================*/

#define DCM_START_SEC_CALLOUT_CODE
#include <Dcm_MemMap.h>

/* !LINKSTO Dcm.ReadDataById.ReadData.SyncAPI,1 */
extern FUNC(Std_ReturnType, DCM_APPL_CODE) Dcm_Internalf186Readout(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data);

/* !LINKSTO Dcm.ReadData.DcmDspPid.SyncFnc,1 */
#define DCM_STOP_SEC_CALLOUT_CODE
#include <Dcm_MemMap.h>
/*==================[internal function declarations]=============================================*/

/*==================[external constants]=========================================================*/

/*==================[internal data]==============================================================*/

/*==================[external function definitions]==============================================*/

/*==================[internal function definitions]==============================================*/

#endif /* if !defined( DCM_API_CFG_H ) */
/*==================[end of file]================================================================*/
