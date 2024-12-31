/**
 * \file
 *
 * \brief AUTOSAR ComM
 *
 * This file contains the implementation of the AUTOSAR
 * module ComM.
 *
 * \version 5.21.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]============================================*/






/* prevent RTE symbols defined in ComM.h to be visible for ComM's .c files */
#if (defined COMM_INTERNAL_USAGE)
#error COMM_INTERNAL_USAGE already defined
#endif
#define COMM_INTERNAL_USAGE

#include <ComM_BSW_Cfg.h>           /* Module Internal identifiers */
#include <ComM.h>
#include <ComM_Int.h>
#include <ComM_EcuMBswM.h>
#include <ComM_Dcm.h>
#include <ComM_Trace.h>

#if (COMM_NM_ACCESS_NEEDED == STD_ON)
#include <Nm.h>
#endif





  




  




 



 

  
    
  
 
 

  

 

 
/* for the case COMM_INCLUDE_RTE == STD_OFF these symbols are provided via
 * ComM.h. */





  




  




 



 

  
    
  
 
 

  

 
 
  
/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

 
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>


/** \brief Main function for channelid 0 **/
/* !LINKSTO ComM429,1, ComM472,1 */
FUNC(void, COMM_CODE) ComM_MainFunction_0
(
  void
)
{
  if (ComM_InitStatus != COMM_UNINIT)
  {
#if ((COMM_MULTICORE_ENABLED == STD_ON) && (COMM_WAKEUPSLEEPREQUEST_ENABLED == STD_ON))
    ComM_BusSmModeToReport[0] = COMM_INVALID_COM_MODE;
#endif /*#if ((COMM_MULTICORE_ENABLED == STD_ON) && (COMM_WAKEUPSLEEPREQUEST_ENABLED == STD_ON))*/      
/* !LINKSTO ComM979,1 */
#if (COMM_PNC_SUPPORT == STD_ON)
    if( COMM_PNC_ENABLED )
    {
       ComM_PncProcessTimers();
      ComM_PncMainFunction();
    }
#endif

    ComM_ProcessTimers(0U);

    if(COMM_CH_HSM_EVENT_PENDING(0U))
    {
      /* ComM channels are independent of each other and do not send events to
       * each other. Hence the return value is ignored */
      (void) COMM_HSMMAININST(
        &ComM_HsmScComM, 0U);
    }

#if ((COMM_MULTICORE_ENABLED == STD_ON) && (COMM_WAKEUPSLEEPREQUEST_ENABLED == STD_ON))
    if (ComM_BusSmModeToReport[0] != COMM_INVALID_COM_MODE)
    {
      if(COMM_BUSSM_REQUEST_COM_MODE((uint8)0, ComM_BusSmModeToReport[0]) != SCHM_E_OK)
      {
#if (COMM_DEV_ERROR_DETECT == STD_ON)
        /* !LINKSTO ComM.EB.SchM_Call_Client_Server_DET,1 */
        COMM_DET_REPORT_ERROR(COMM_INSTANCE_ID,
                              COMM_SID_MAIN_FUNCTION,
                              COMM_E_BUSSM_REQUESTCOMMODE);
#endif
      }
    }
#endif /* #if ((COMM_MULTICORE_ENABLED == STD_ON) && (COMM_WAKEUPSLEEPREQUEST_ENABLED == STD_ON)) */    

    if(ComM_RteNotificationDoActFkp != NULL_PTR)
    {
      ComM_RteNotificationDoActFkp(0U);
    }
  }
}

#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>


 

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
