#if !defined(BSWM_LCFG_H)
#define BSWM_LCFG_H

/**
 * \file
 *
 * \brief AUTOSAR BswM
 *
 * This file contains the implementation of the AUTOSAR
 * module BswM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /* \addtogroup Mode Management Stack
  * @{ */

/* !LINKSTO BswM.Impl.SourceFile.BswM_Partition_Lcfg_h,1 */
/*==================[inclusions]============================================*/

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

/*==================[external function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[external constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external data]=========================================*/

#define BSWM_START_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_MemMap.h>

extern BswM_PartitionContextType BswM_Context;

extern BswMUInt8RteModeRequestPortType BswM_MPI_BswM_Dcm_RequestPort;
extern BswMUInt8RteModeRequestPortType BswM_MPI_BswM_Dcm_ComM_RequestPort;

extern BswMModeRequestPortType BswMCanSMIndicationPortTable[1];
extern BswMModeRequestPortType BswMEcuMWakeupSourcePortTable[1];
extern BswMGenericRequestPortType BswMGenericRequestPortTable[6];

#define BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_MemMap.h>

/*==================[external function definitions]=========================*/

#define BSWM_START_SEC_CODE
#include <BswM_MemMap.h>

extern FUNC(void, BSWM_CODE) BswM_LT_Init(void);

#define BSWM_STOP_SEC_CODE
#include <BswM_MemMap.h>

/*==================[internal function definitions]=========================*/
/** @} doxygen end group definition */
#endif /* !defined(BSWM_LCFG_H) */
/*==================[end of file]============================================*/

