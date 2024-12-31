#ifndef BSWM_LCFG_H
#define BSWM_LCFG_H

/**
 * \file
 *
 * \brief AUTOSAR BswM
 *
 * This file contains the implementation of the AUTOSAR
 * module BswM.
 *
 * \version 1.17.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /* \addtogroup Mode Management Stack
  * @{ */

/* !LINKSTO BswM.Impl.SourceFile.BswM_Partition_Lcfg_h,1 */
/*==================[inclusions]============================================*/

/*==================[macros]================================================*/

#if (defined BSWM_NUM_LOGICAL_EXPRESSIONS)
#error BSWM_NUM_LOGICAL_EXPRESSIONS is already defined
#endif
#define BSWM_NUM_LOGICAL_EXPRESSIONS 23U

#if (defined BSWM_NUM_ACTIONS)
#error BSWM_NUM_ACTIONS is already defined
#endif
#define BSWM_NUM_ACTIONS 26U

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

/*==================[external function declarations]========================*/

#define BSWM_START_SEC_CODE
#include <BswM_MemMap.h>

extern FUNC(Std_ReturnType, BSWM_CODE) BswM_HandleStaticRequest(uint32 channel, uint16 mode, uint8 source, uint8 sid, uint8 type);

#define BSWM_STOP_SEC_CODE
#include <BswM_MemMap.h>

/*==================[internal constants]====================================*/

/*==================[external constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external data]=========================================*/

#define BSWM_START_SEC_VAR_INIT_UNSPECIFIED
#include <BswM_MemMap.h>

extern BswM_PartitionContextType BswM_Context;

extern BswMGenericRequestPortType BswMGenericRequestPortTable[6];
extern BswMU8ChannelU8ModePortType BswMCanSMIndicationPortTable[1];
extern BswMU8ChannelU8ModePortType BswMEcuMWakeupSourcePortTable[1];

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
#endif /* ifndef BSWM_LCFG_H */
/*==================[end of file]============================================*/

