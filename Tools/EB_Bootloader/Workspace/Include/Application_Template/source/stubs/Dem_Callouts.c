/**
 * \file
 *
 * \brief AUTOSAR Dem
 *
 * This file contains the implementation of the AUTOSAR
 * module Dem.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


/*==================[inclusions]============================================*/

#include <Std_Types.h>                            /* AUTOSAR standard types */
#include <TSAutosar.h>     /* EB specific standard types, TS_PARAM_UNUSED() */

#include <Dem_Cfg.h>                             /* declaration of callouts */
#include <NvM.h>
#include <Fee.h>
#include <Fls.h>

/* Implementation hint:
 * include necessary Memory-Stack header-files: NvM.h, Ea/Fee.h, Eep/Fls.h */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/


#define DEM_START_SEC_CODE
#include <Dem_MemMap.h>

/*------------------[Main callouts]-----------------------------------------*/

FUNC(void, DEM_APPL_CODE) Appl_TriggerMemoryStack(NvM_BlockIdType BlockId)
{
 // TS_PARAM_UNUSED(BlockId);
    NvM_RequestResultType Result;
	volatile uint32 i;
   do
   {
	for(i=0;i<=100000;i++);
    NvM_MainFunction();
    Fee_MainFunction();
    Fls_MainFunction();
    NvM_GetErrorStatus(BlockId, &Result);
   }
   while (Result == NVM_REQ_PENDING);

  /* Implement the routine to trigger memory stack main functions
   * with in this callout function.
   *
   *  Implementation hint:
   *
   *  FUNC(void, DEM_APPL_CODE) Appl_TriggerMemoryStack(NvM_BlockIdType BlockId)
   *  {
   *    NvM_RequestResultType Result;
   *
   *    do
   *    {
   *      NvM_MainFunction();
   *      Ea_MainFunction();  // Fee_MainFunction();
   *      Eep_MainFunction(); // Fls_MainFunction();
   *
   *      NvM_GetErrorStatus(BlockId, &Result);
   *    }
   *    while (Result == NVM_REQ_PENDING);
   *
   *    // In case an error occurs, the Dem module will handle it internally.
   *    // Optionally, inform the application to let it perform some generic
   *    // error handling:
   *    if (Result != NVM_REQ_OK)
   *    {
   *      // Appl_DemHandleUnknownNvMError();
   *    }
   *  }
   *
   */
}


#define DEM_STOP_SEC_CODE
#include <Dem_MemMap.h>


/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
