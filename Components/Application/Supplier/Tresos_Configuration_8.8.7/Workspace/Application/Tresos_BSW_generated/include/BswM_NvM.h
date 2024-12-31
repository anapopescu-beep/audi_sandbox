#ifndef BSWM_NVM_H
#define BSWM_NVM_H

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

/* Definition of the BswM_NvM.h for the NvM. */

/*==================[includes]===============================================*/

#include <NvM_Types.h>   /* NvM API                   */

/*==================[macros]=================================================*/

/* Magic numbers not exported by NvM */

#if (defined BSWM_NVM_READ_ALL_API_ID)
#error BSWM_NVM_READ_ALL_API_ID is already defined
#endif

#define BSWM_NVM_READ_ALL_API_ID                   0x0CU

#if (defined BSWM_NVM_WRITE_ALL_API_ID)
#error BSWM_NVM_WRITE_ALL_API_ID is already defined
#endif

#define BSWM_NVM_WRITE_ALL_API_ID                  0x0DU

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

#define BSWM_START_SEC_CODE
#include <BswM_MemMap.h>

/** \brief Indicates the current block mode of an NvM block (Called by NvM).
 **
 ** This function is called by NvM to indicate the current block mode of an NvM block.
 **
 ** Precondition: None
 **
 ** \param[in]    Block            - The Block that the new NvM Mode corresponds to.
 **               CurrentBlockMode - The current block mode of the NvM block.
 ** \param[inout] None.
 ** \param[out]   None.
 **
 ** \ServiceID{0x16}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
extern FUNC(void, BSWM_CODE) BswM_NvM_CurrentBlockMode
(
NvM_BlockIdType Block,
NvM_RequestResultType CurrentBlockMode
);
/** \brief Indicates the current state of a multi block job (Called by NvM).
 **
 ** This function is called by NvM to inform the BswM about the current state
 ** of a multi block job
 **
 ** Precondition: None
 **
 ** \param[in]    ServiceId        - Indicates whether the callback refers to
 **                                  multi block services NvM_ReadAll or NvM_WriteAll.
 **               CurrentJobMode   - Current state of the multi block job indicated
 **                                  by parameter ServiceId.
 ** \param[inout] None.
 ** \param[out]   None.
 **
 ** \ServiceID{0x17}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
extern FUNC(void, BSWM_CODE) BswM_NvM_CurrentJobMode
(
uint8 ServiceId,
NvM_RequestResultType CurrentJobMode
);

#define BSWM_STOP_SEC_CODE
#include <BswM_MemMap.h>

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/** @} doxygen end group definition */
#endif /* ifndef BSWM_NVM_H */
/*==================[end of file]============================================*/

/*==================[end of file]============================================*/
