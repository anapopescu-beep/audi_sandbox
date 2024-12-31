/**
 * \file
 *
 * \brief AUTOSAR ETS
 *
 * This file contains the implementation of the AUTOSAR
 * module ETS.
 *
 * \version 2.5.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*  MISRA-C:2012 Deviation List
 *
 *   MISRAC2012-1) Deviated Rule: 8.9 (Advisory)
 *     An object should be defined at block scope if its identifier only appears in a single function.
 *
 *     Reason:
 *     This object is used in ETS_Events[] -table.
 *
 *
 *   MISRAC2012-2) Deviated Rule: Dir 4.5 (Advisory)
 *     Identifiers in the same name space with overlapping visibility should be typographically unambiguous.
 *
 *     Reason:
 *     Identifier name change didin't solve issue.
 *
 */
/*================================================================================================*/

/*==================[includes]====================================================================*/

#include <string.h>
#include <ETS_Cfg.h>
#include <ETS_Services.h>
#include <Rte_Type.h>
#include <Rte_ETS.h>
#include <ETS_Types.h>

#include <ETS_TriggerAndEvents.h>
#include <ETS_EventsHandler.h>
#include <ETS_FieldsHandler.h>
/*==================[macros]======================================================================*/

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

/*==================[internal function declarations]==============================================*/

#define ETS_START_SEC_CODE
#include <ETS_MemMap.h>

#define ETS_STOP_SEC_CODE
#include <ETS_MemMap.h>

/*==================[external constants]==========================================================*/

/*==================[internal constants]==========================================================*/

/*==================[external data]===============================================================*/

/*==================[internal data]===============================================================*/

#define ETS_START_SEC_VAR_UNSPECIFIED
#include <ETS_MemMap.h>

#if ( ETS_Service_ResetInterface == TRUE )
STATIC boolean ETS_Initialized = FALSE;
#endif

#if ( ETS_Service_TestEventUINT8 == TRUE )
STATIC uint8 ETS_Received_Uint8_Unicast = 0;
#endif

#if ( ETS_Service_TestEventUINT8Multicast == TRUE )
STATIC uint8 ETS_Received_Uint8_Multicast = 0;
#endif

#if ( ETS_Service_TestEventUINT8Reliable == TRUE )
STATIC uint8 ETS_Received_Uint8_TCP = 0;
#endif

#if ( ETS_Service_ClientServiceActivate == TRUE )
/* Deviation MISRAC2012-1 */
STATIC ETS_TriggeredEventType ETS_EventClientActivate = {
  {0,0,0},
  ETS_EVENT_STATUS_DISABLED,
  0,
  &ETS_Action_ClientActivateInterface,
  NULL_PTR,
  NULL_PTR
};
#endif

#if (ETS_Service_ClientServiceSubscribeEventgroup == STD_ON)
/* Deviation MISRAC2012-1 */
STATIC ETS_TriggeredEventType ETS_EventClientSubscribe = {
  {0,0,0},
  ETS_EVENT_STATUS_DISABLED,
  0,
  &ETS_Action_ClientSubscribeEventgroup,
  NULL_PTR,
  &ETS_Action_ClientUnsubscribeEventgroup
};
#endif

#if (ETS_Service_ClientServiceDeactivate == STD_ON)
/* Deviation MISRAC2012-1 */
STATIC ETS_TriggeredEventType ETS_EventClientDeactivate = {
  {0,0,0},
  ETS_EVENT_STATUS_DISABLED,
  0,
  &ETS_Action_ClientDeactivateInterface,
  NULL_PTR,
  NULL_PTR
};
#endif

#if ( ETS_Service_TriggerEventUINT8 == TRUE )
/* Deviation MISRAC2012-1 */
STATIC ETS_TriggeredEventType ETS_EventUINT8 = {
  {0,0,0},
  ETS_EVENT_STATUS_DISABLED,
  0,
  &ETS_Action_TriggerEventUINT8,
  &ETS_Action_TriggerEventUINT8,
  NULL_PTR
};
#endif

#if ( ETS_Service_TriggerEventUINT8Reliable == TRUE )
/* Deviation MISRAC2012-1 */
STATIC ETS_TriggeredEventType ETS_EventUINT8Reliable = {
  {0,0,0},
  ETS_EVENT_STATUS_DISABLED,
  0,
  &ETS_Action_TriggerEventUINT8Reliable,
  &ETS_Action_TriggerEventUINT8Reliable,
  NULL_PTR
};
#endif

#if ( ETS_Service_TriggerEventUINT8Array == TRUE )
/* Deviation MISRAC2012-1 */
STATIC ETS_TriggeredEventType ETS_EventUINT8Array = {
  {0,0,0},
  ETS_EVENT_STATUS_DISABLED,
  0,
  &ETS_Action_TriggerEventUINT8Array,
  &ETS_Action_TriggerEventUINT8Array,
  NULL_PTR
};
#endif

#if ( ETS_Service_TriggerEventUINT8E2E == TRUE )
/* Deviation MISRAC2012-1 */
STATIC ETS_TriggeredEventType ETS_EventUINT8E2E = {
  {0,0,0},
  ETS_EVENT_STATUS_DISABLED,
  0,
  &ETS_Action_TriggerEventUINT8E2E,
  &ETS_Action_TriggerEventUINT8E2E,
  NULL_PTR
};
#endif

#if ( ETS_Service_TriggerEventUINT8Multicast == TRUE )
/* Deviation MISRAC2012-1 */
STATIC ETS_TriggeredEventType ETS_EventUINT8Multicast = {
  {0,0,0},
  ETS_EVENT_STATUS_DISABLED,
  0,
  &ETS_Action_TriggerEventUINT8Multicast,
  &ETS_Action_TriggerEventUINT8Multicast,
  NULL_PTR
};
#endif

#if ( ETS_Service_SuspendInterface == TRUE )
/* Deviation MISRAC2012-1 */
STATIC ETS_TriggeredEventType ETS_EventSuspend = {
  {0,0,0},
  ETS_EVENT_STATUS_DISABLED,
  0,
#if ( ETS_Service_SuspendInterface == TRUE )
  &ETS_Action_SuspendInterface,
#endif
  NULL_PTR,
#if ( ETS_Service_SuspendInterface == TRUE )
  &ETS_Action_ResumeInterface
#endif
};
#endif


#if ( NUM_OF_ETS_EVENTS > 0 )

STATIC ETS_TriggeredEventType * const ETS_Events[] = {
#if ( ETS_Service_TriggerEventUINT8 == TRUE )
  &ETS_EventUINT8,
#endif
#if ( ETS_Service_TriggerEventUINT8Reliable == TRUE )
  &ETS_EventUINT8Reliable,
#endif
#if ( ETS_Service_TriggerEventUINT8Array == TRUE )
  &ETS_EventUINT8Array,
#endif
#if ( ETS_Service_TriggerEventUINT8E2E == TRUE )
  &ETS_EventUINT8E2E,
#endif
#if ( ETS_Service_TriggerEventUINT8Multicast == TRUE )
  &ETS_EventUINT8Multicast,
#endif
#if ( ETS_Service_SuspendInterface == TRUE )
  &ETS_EventSuspend,
#endif
#if ( ETS_Service_ClientServiceActivate == STD_ON )
  &ETS_EventClientActivate,
#endif
#if ( ETS_Service_ClientServiceSubscribeEventgroup == TRUE )
  &ETS_EventClientSubscribe,
#endif
#if ( ETS_Service_ClientServiceDeactivate == TRUE )
  &ETS_EventClientDeactivate
#endif
};

#endif /* ( NUM_OF_ETS_EVENTS > 0 ) */

#define ETS_STOP_SEC_VAR_UNSPECIFIED
#include <ETS_MemMap.h>

/*==================[external function definitions]===============================================*/

#define ETS_START_SEC_CODE
#include <ETS_MemMap.h>

/**
 * \brief Check order of bytes (Little or Big endianes)
 *
 * \param[in] summandUINT8 Param 1 is 8 bit
 * \param[in] summandUINT16 Param 2 is 16 bit
 * \param[out] sum Sum of param 1 and 2 result is 32bit
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0001.1, 1 */
/* !LINKSTO swdd.ETS-0001.2, 1 */
/* !LINKSTO swdd.ETS-0001.3, 1 */
#if ( ETS_Service_CheckByteOrder == TRUE )
FUNC(void, RTE_CODE) ETS_CheckByteOrder (uint8 summandUINT8, uint16 summandUINT16, P2VAR(uint32, AUTOMATIC, RTE_APPL_DATA) sum)
{
  *sum = (uint32)(summandUINT8) + (uint32)(summandUINT16);
}
#endif

/**
 * \brief Activates client server interface
 *
 * \param[in] none
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0002, 1 */
/* !LINKSTO swdd.EB.ETS.Service_dre.1, 1 */
#if ( ETS_Service_ClientServiceActivate == STD_ON )
FUNC(void, RTE_CODE) ETS_ClientServiceActivate (void)
{
  Std_ReturnType result;
  uint8 start = 0U;

  result = Rte_Receive_ETS_ClientServiceActivate_start(&start);

  if(result == E_OK)
  {
    ETS_SetTimer(&ETS_EventClientActivate, start, 0, 0);
  }
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  else
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_CLI_SER_ACT, ID_CLIENTSERVICE_ACTIVATE);
  }
#endif
}
#endif

/**
 * \brief Calls ETS_EchoUINT8ArrayClient_EchoUINT8Array interface.
 *
 * \param[out] uINT8ARRAY ETS_Uint8Array type of array
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0004.1, 1 */
/* !LINKSTO swdd.ETS-0004.2, 1 */
#if ( ETS_Service_ClientServiceCallEchoUINT8Array == TRUE )
FUNC(void, RTE_CODE) ETS_ClientServiceCallEchoUINT8Array (P2VAR(ETS_Uint8Array, AUTOMATIC, RTE_APPL_DATA) uINT8ARRAY)
{
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType ret_Receive;

  ret_Receive = Rte_Call_ETS_EchoUINT8ArrayClient_EchoUINT8Array(uINT8ARRAY);

  if(ret_Receive != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_CLI_SER_CALL_ECH_UINT8_ARR, ID_CLIENTSERVICE_CALLECHOUINT8ARRAY);
  }
#else
  (void)Rte_Call_ETS_EchoUINT8ArrayClient_EchoUINT8Array(uINT8ARRAY);
#endif
}
#endif

/**
 * \brief Deactivates client service interface.
 *
 * \param[in] none
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0003, 1 */
/* !LINKSTO swdd.EB.ETS.Service_dre.2, 1 */
#if ( ETS_Service_ClientServiceDeactivate == TRUE )
FUNC(void, RTE_CODE) ETS_ClientServiceDeactivate (void)
{
  uint8 start;
  Std_ReturnType ret_Receive;

  ret_Receive = Rte_Receive_ETS_ClientServiceDeactivate_start(&start);

  if(ret_Receive == E_OK)
  {
    ETS_SetTimer(&ETS_EventClientDeactivate, start, 0, 0);
  }
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  else
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_CLI_SER_DEACT, ID_CLIENTSERVICE_DEACTIVATE);
  }
#endif
}
#endif


/**
 * \brief Gets last value of client server TCP event.
 *
 * \param[in] lastValue 8-bit value of ETS_Received_Uint8_TCP
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0039, 1 */
#if ( ETS_Service_ClientServiceGetLastValueOfEventTCP == TRUE )
FUNC(void, RTE_CODE) ETS_ClientServiceGetLastValueOfEventTCP (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) lastValue)
{
  *lastValue = ETS_Received_Uint8_TCP;
}
#endif

/**
 * \brief Gets last value of client server UDP multicast.
 *
 * \param[in] lastValue 8-bit value of ETS_Received_Uint8_Multicast.
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0041, 1 */
#if ( ETS_Service_ClientServiceGetLastValueOfEventUDPMulticast == TRUE )
FUNC(void, RTE_CODE) ETS_ClientServiceGetLastValueOfEventUDPMulticast (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) lastValue)
{
  *lastValue = ETS_Received_Uint8_Multicast;
}
#endif

/**
 * \brief Gets last value of client server UDP Unicast.
 *
 * \param[in] lastValue 8-bit value of ETS_Received_Uint8_Unicast.
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0040, 1 */
#if ( ETS_Service_ClientServiceGetLastValueOfEventUDPUnicast == TRUE )
FUNC(void, RTE_CODE) ETS_ClientServiceGetLastValueOfEventUDPUnicast (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) lastValue)
{
  *lastValue = ETS_Received_Uint8_Unicast;
}
#endif

/**
 * \brief Subscribe to Eventgroup
 *
 * \param[in] none
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0005, 1 */
/* !LINKSTO swdd.EB.ETS.Service_dre.3, 1 */
#if ( ETS_Service_ClientServiceSubscribeEventgroup == TRUE )
FUNC(void, RTE_CODE) ETS_ClientServiceSubscribeEventgroup (void)
{
  ETS_TimePeriod arg_Receive_data;
  Std_ReturnType ret_Receive;

  ret_Receive = Rte_Receive_ETS_ClientServiceSubscribeEventgroup_clientServiceSubscribeEventgroup(&arg_Receive_data);

  if(ret_Receive == E_OK)
  {
    ETS_SetTimer(&ETS_EventClientSubscribe, arg_Receive_data.start, 0, arg_Receive_data.duration);
  }
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  else
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_CLI_SER_SUB_EVE_GRP, ID_CLIENTSERVICE_SUBSCRIBEEVENTGROUP);
  }
#endif
}
#endif

/**
 * \brief ETS_Init function
 *
 * \param[in] none
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0050, 1 */
/* !LINKSTO swdd.EB.ETS.Init.1, 1 */
/* !LINKSTO swdd.EB.ETS.Init.2, 1 */
/* !LINKSTO swdd.EB.ETS.FieldsHandler.4, 1 */
/* !LINKSTO swdd.EB.ETS.FieldsHandler.8, 1 */
FUNC(void, RTE_CODE) ETS_Init( void )
{
#if ( ETS_Service_ResetInterface == TRUE )
#if ( NUM_OF_ETS_EVENTS > 0 )
  uint32 ulIndex;
#endif

#if ( ETS_Fields_TestFieldUINT8 == TRUE )
  uint8 TestFieldInitValue = 0;
#endif

#if ( ETS_Fields_TestFieldUINT8Array == TRUE )
  ETS_Uint8Array TestFieldUint8ArrayInit = {0,{0,0,0,0,0}};
#endif

  Std_ReturnType EtsReturn = E_OK;

  if (ETS_Initialized == FALSE)
  {
    ETS_Initialized = TRUE;

#if ( ETS_Service_ClientServiceActivate == STD_ON )
    /* Deactivate client service interface */
    EtsReturn = Rte_Write_ETS_SD_ClientServiceRequest_requestedMode(ETS_SD_CLIENT_SERVICE_RELEASED);
#endif

#if (ETS_DEV_ERROR_DETECT == STD_ON)
    if (EtsReturn != E_OK)
    {
      (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_INIT_ID, ID_CLIENTSERVICE_DEACTIVATE);
    }
#endif

#if ( ETS_Service_ClientServiceActivate == STD_ON )
    /* Activate server interface */
    EtsReturn = Rte_Write_ETS_SD_ServerServiceRequest_requestedMode(ETS_SD_SERVER_SERVICE_AVAILABLE);
#endif

#if (ETS_DEV_ERROR_DETECT == STD_ON)
    if (EtsReturn != E_OK)
    {
      (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_INIT_ID, ID_CLIENTSERVICE_ACTIVATE);
    }
#endif

#if ( ETS_Service_ClientServiceSubscribeEventgroup == STD_ON )
    /* Unsubscribe to the client service interfaces eventgroup */
    EtsReturn = Rte_Write_ETS_SD_ConsumedEventGroupRequest_requestedMode(ETS_SD_CONSUMED_EVENTGROUP_RELEASED);
#endif

#if (ETS_DEV_ERROR_DETECT == STD_ON)
    if (EtsReturn != E_OK)
    {
      (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_INIT_ID, ID_CLIENTSERVICE_SUBSCRIBEEVENTGROUP);
    }
#else
   /* suppress compiler warnings about unused arguments */
   (void)EtsReturn;
#endif

#if ( NUM_OF_ETS_EVENTS > 0 )
    /* Reset event timers */
    for(ulIndex = 0; ulIndex < (sizeof(ETS_Events)/(sizeof(ETS_Events[0]))); ulIndex++)
    {
      ETS_ResetTimer(ETS_Events[ulIndex]);
    }
#endif

#if ( ETS_Fields_TestFieldUINT8 == TRUE )
    /* Initialize test fields values */
    ETS_SetField_uint8(&TestFieldInitValue);
#endif

#if ( ETS_Fields_TestFieldUINT8Array == TRUE )
    ETS_SetField_VarArray(&TestFieldUint8ArrayInit);
#endif

#if ( ETS_Fields_InterfaceVersion == TRUE )
    ETS_SetField_InterfaceVersion();
#endif
  }
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  else
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_INIT_ID, ETS_ALREADY_INITIALIZED);
  }
#endif
#endif
}


/**
 * \brief ETS_MainFunction
 *
 * \param[in] none
 *
 * \return none
 *
 */
/* !LINKSTO swdd.EB.ETS.Service_TimingEvent.1, 1 */
FUNC(void, RTE_CODE) ETS_MainFunction( void )
{
#if ( NUM_OF_ETS_EVENTS > 0 )
  uint16 usIndex;

  for(usIndex = 0; usIndex < (sizeof(ETS_Events)/(sizeof(ETS_Events[0]))); usIndex++)
  {
    ETS_CheckEvent(ETS_Events[usIndex]);
  }
#endif
}


/**
 * \brief Reset Interface by running ETS_Init again.
 *
 * \param[in] none
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0032, 1 */
/* !LINKSTO swdd.EB.ETS.Service_ext_trigg.1, 1 */
#if ( ETS_Service_ResetInterface == TRUE )
FUNC(void, RTE_CODE) ETS_ResetInterface (void)
{
  ETS_Initialized = FALSE;
  ETS_Init();
}
#endif

/**
 * \brief ETS_SuspendInterface for a specific time.
 *
 * \param[in] none
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0033.1, 1 */
/* !LINKSTO swdd.ETS-0033.2, 1 */
/* !LINKSTO swdd.ETS-0033.3, 1 */
/* !LINKSTO swdd.EB.ETS.Service_dre.4, 1 */
#if ( ETS_Service_SuspendInterface == TRUE )
FUNC(void, RTE_CODE) ETS_SuspendInterface (void)
{
  ETS_TimePeriod arg_Receive_data;
  Std_ReturnType ret_Receive;

  ret_Receive = Rte_Receive_ETS_SuspendInterface_suspendInterface(&arg_Receive_data);

  if(ret_Receive == E_OK)
  {
    ETS_SetTimer(&ETS_EventSuspend, arg_Receive_data.start, 0, arg_Receive_data.duration);
  }
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  else
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_SUS_INT_FACE, ID_SUSPENDINTERFACE);
  }
#endif
}
#endif

/**
 * \brief Trigger uint8 event interface
 *
 * \param[in] none
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0034.1, 1 */
/* !LINKSTO swdd.ETS-0034.2, 1 */
/* !LINKSTO swdd.EB.ETS.Service_dre.5, 1 */
#if ( ETS_Service_TriggerEventUINT8 == TRUE )
FUNC(void, RTE_CODE) ETS_TriggerEventUINT8 (void)
{
  ETS_TriggerEventType arg_Receive_data;
  Std_ReturnType ret_Receive;

  ret_Receive = Rte_Receive_ETS_TriggerEventUINT8_triggerEventUINT8(&arg_Receive_data);

  if(ret_Receive == E_OK)
  {
    ETS_SetTimer(&ETS_EventUINT8, arg_Receive_data.start, arg_Receive_data.debounceTime, arg_Receive_data.duration);
  }
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  else
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_TRIG_EVENT_UINT8, ID_TRIGGER_EVENTUINT8);
  }
#endif
}
#endif

/**
 * \brief Trigger uint8 event reliable interface
 *
 * \param[in] none
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0037.1, 1 */
/* !LINKSTO swdd.ETS-0037.2, 1 */
/* !LINKSTO swdd.EB.ETS.Service_dre.9, 1 */
#if ( ETS_Service_TriggerEventUINT8Reliable == TRUE )
FUNC(void, RTE_CODE) ETS_TriggerEventUINT8Reliable (void)
{
  ETS_TriggerEventType arg_Receive_data;
  Std_ReturnType ret_Receive;

  ret_Receive = Rte_Receive_ETS_TriggerEventUINT8Reliable_triggerEventUINT8Reliable(&arg_Receive_data);

  if(ret_Receive == E_OK)
  {
    ETS_SetTimer(&ETS_EventUINT8Reliable, arg_Receive_data.start, arg_Receive_data.debounceTime, arg_Receive_data.duration);
  }
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  else
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_TRIG_EVENT_UINT8_RELIB, ID_TESTEVENTUINT8RELIABLE);
  }
#endif
}
#endif

/**
 * \brief Trigger uint8 Array event interface
 *
 * \param[in] none
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0035.1, 1 */
/* !LINKSTO swdd.ETS-0035.2, 1 */
/* !LINKSTO swdd.EB.ETS.Service_dre.6, 1 */
#if ( ETS_Service_TriggerEventUINT8Array == TRUE )
FUNC(void, RTE_CODE) ETS_TriggerEventUINT8Array (void)
{
  ETS_TriggerEventType arg_Receive_data;
  Std_ReturnType ret_Receive;

  ret_Receive = Rte_Receive_ETS_TriggerEventUINT8Array_triggerEventUINT8Array(&arg_Receive_data);

  if(ret_Receive == E_OK)
  {
    ETS_SetTimer(&ETS_EventUINT8Array, arg_Receive_data.start, arg_Receive_data.debounceTime, arg_Receive_data.duration);
  }
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  else
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_TRIG_EVENT_UINT8_ARRAY, ID_TRIGGER_EVENTUINT8ARRAY);
  }
#endif
}
#endif

/**
 * \brief  Trigger uint8 end to end event interface
 *
 * \param[in] none
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0036.1, 1 */
/* !LINKSTO swdd.ETS-0036.2, 1 */
/* !LINKSTO swdd.EB.ETS.Service_dre.7, 1 */
#if ( ETS_Service_TriggerEventUINT8E2E == TRUE )
FUNC(void, RTE_CODE) ETS_TriggerEventUINT8E2E (void)
{
  ETS_TriggerEventType arg_Receive_data;
  Std_ReturnType ret_Receive;

  ret_Receive = Rte_Receive_ETS_TriggerEventUINT8E2E_triggerEventUINT8E2E(&arg_Receive_data);

  if(ret_Receive == E_OK)
  {
    ETS_SetTimer(&ETS_EventUINT8E2E, arg_Receive_data.start, arg_Receive_data.debounceTime, arg_Receive_data.duration);
  }
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  else
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_TRIG_EVENT_UINT8_E2E, ID_TRIGGER_EVENTUINT8E2E);
  }
#endif
}
#endif

/**
 * \brief Trigger uint8 multicast event interface.
 *
 * \param[in] none
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0038.1, 1 */
/* !LINKSTO swdd.ETS-0038.2, 1 */
/* !LINKSTO swdd.EB.ETS.Service_dre.8, 1 */
#if ( ETS_Service_TriggerEventUINT8Multicast == TRUE )
FUNC(void, RTE_CODE) ETS_TriggerEventUINT8Multicast (void)
{
  ETS_TriggerEventType arg_Receive_data;
  Std_ReturnType ret_Receive;

  ret_Receive = Rte_Receive_ETS_TriggerEventUINT8Multicast_triggerEventUINT8Multicast(&arg_Receive_data);

  if(ret_Receive == E_OK)
  {
    ETS_SetTimer(&ETS_EventUINT8Multicast, arg_Receive_data.start, arg_Receive_data.debounceTime, arg_Receive_data.duration);
  }
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  else
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_TRIG_EVENT_UINT8_MULT_CST, ID_TRIGGER_EVENTUINT8MULTICAST);
  }
#endif
}
#endif

/**
 * \brief Test uint8 event interface.
 *
 * \param[in] none
 *
 * \return none
 *
 */
/* !LINKSTO swdd.EB.ETS.Service.1, 1 */
#if ( ETS_Service_TestEventUINT8 == TRUE )
FUNC(void, RTE_CODE) ETS_TestEventUINT8 (void)
{
  ETS_Uint8Value arg_Read_data;
  Std_ReturnType ret_Read;

  ret_Read = Rte_Read_ETS_TestEventUINT8Client_TestEventUINT8(&arg_Read_data);

  if(ret_Read == E_OK)
  {
    ETS_Received_Uint8_Unicast = arg_Read_data.uINT8Value;
  }
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  else
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_TEST_EVT_UINT8, ID_TESTEVENTUINT8);
  }
#endif
}
#endif

/**
 * \brief Test uint8 event reliable interface.
 *
 * \param[in] none
 *
 * \return none
 *
 */
/* !LINKSTO swdd.EB.ETS.Service.2, 1 */
#if ( ETS_Service_TestEventUINT8Reliable == TRUE )
FUNC(void, RTE_CODE) ETS_TestEventUINT8Reliable (void)
{
  ETS_Uint8Value arg_Read_data;
  Std_ReturnType ret_Read;

  ret_Read = Rte_Read_ETS_TestEventUINT8ReliableClient_TestEventUINT8Reliable(&arg_Read_data);

  if(ret_Read == E_OK)
  {
    ETS_Received_Uint8_TCP = arg_Read_data.uINT8Value;
  }
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  else
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_TEST_EVT_UINT8_REL, ID_TESTEVENTUINT8RELIABLE);
  }
#endif
}
#endif

/**
 * \brief Test uint8 event array interface.
 *
 * \param[in] none
 *
 * \return none
 *
 */

/* Note: This function is not defined in request ETS-0044  */
#if ( ETS_Service_TestEventUINT8Array == TRUE )
FUNC(void, RTE_CODE) ETS_TestEventUINT8Array (void)
{
  ETS_Uint8Array arg_Receive_data;
  Std_ReturnType ret_Receive;

  ret_Receive = Rte_Receive_ETS_TestEventUINT8ArrayClient_TestEventUINT8Array(&arg_Receive_data);

#if (ETS_DEV_ERROR_DETECT == STD_ON)
  if(ret_Receive != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_TEST_EVT_UINT8_ARRAY, ID_TESTEVENTUINT8ARRAY);
  }
#else
  /* suppress compiler warnings about unused arguments */
  (void)ret_Receive;
#endif
}
#endif

/**
 * \brief Test uint8 event end to end interface.
 *
 * \param[in] none
 *
 * \return none
 *
 */

#if ( ETS_Service_TestEventUINT8E2E == TRUE )
FUNC(void, RTE_CODE) ETS_TestEventUINT8E2E (void)
{
  ETS_Uint8Value arg_Read_data;
  Std_ReturnType ret_Read;

  ret_Read = Rte_Read_ETS_TestEventUINT8E2EClient_TestEventUINT8E2E(&arg_Read_data);

#if (ETS_DEV_ERROR_DETECT == STD_ON)
  if(ret_Read != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_TEST_EVT_UINT8_E2E, ID_TESTEVENTUINT8E2E);
  }
#else
   /* suppress compiler warnings about unused arguments */
   (void)ret_Read;
#endif
}
#endif

/**
 * \brief Test uint8 event multicast interface.
 *
 * \param[in] none
 *
 * \return none
 *
 */
/* !LINKSTO swdd.EB.ETS.Service.3, 1 */
#if ( ETS_Service_TestEventUINT8Multicast == TRUE )
FUNC(void, RTE_CODE) ETS_TestEventUINT8Multicast (void)
{
  ETS_Uint8Value arg_Read_data;
  Std_ReturnType ret_Read;

  ret_Read = Rte_Read_ETS_TestEventUINT8MulticastClient_TestEventUINT8Multicast(&arg_Read_data);

  if(ret_Read == E_OK)
  {
    ETS_Received_Uint8_Multicast = arg_Read_data.uINT8Value;
  }
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  else
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_TEST_EVT_UINT8_MULT_CST, ID_TESTEVENTUINT8MULTICAST);
  }
#endif
}
#endif

/**
 * \brief Get uint8 test field.
 *
 * \param[out] Getter Test value 8-bit field.
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0051, 1 */
#if ( ETS_Fields_TestFieldUINT8 == TRUE )
FUNC(void, RTE_CODE) ETS_GetFieldTestFieldUINT8 (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Getter)
{
  ETS_GetField_uint8(Getter);
}
#endif

/**
 * \brief Get uint8 test field reliable.
 *
 * \param[out] Getter Test value 8-bit field.
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0057, 1 */
#if ( ETS_Fields_TestFieldUINT8Reliable == TRUE )
FUNC(void, RTE_CODE) ETS_GetFieldTestFieldUINT8Reliable (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Getter)
{
  ETS_GetField_uint8Reliable(Getter);
}
#endif

/**
 * \brief Get uint8 array test field.
 *
 * \param[out] Getter Gets ETS_Uint8Array field.
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0054, 1 */
#if ( ETS_Fields_TestFieldUINT8Array == TRUE )
FUNC(void, RTE_CODE) ETS_GetFieldTestFieldUINT8Array (P2VAR(ETS_Uint8Array, AUTOMATIC, RTE_APPL_DATA) Getter)
{
  ETS_GetField_VarArray(Getter);
}
#endif

/**
 * \brief Set uint8 test field.
 *
 * \param[out] Setter Sett test uint8 value.
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0052, 1 */
#if ( ETS_Fields_TestFieldUINT8 == TRUE )
FUNC(void, RTE_CODE) ETS_SetFieldTestFieldUINT8 (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Setter)
{
  ETS_SetField_uint8(Setter);
}
#endif

/**
 * \brief Set uint8 reliable test field.
 *
 * \param[out] Setter Sett test uint8 value.
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0058, 1 */
#if ( ETS_Fields_TestFieldUINT8Reliable == TRUE )
FUNC(void, RTE_CODE) ETS_SetFieldTestFieldUINT8Reliable (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Setter)
{
  ETS_SetField_uint8Reliable(Setter);
}
#endif

/**
 * \brief Set uint8 field array test field.
 *
 * \param[out] Setter Sett test ETS_Uint8Array.
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0055, 1 */
#if ( ETS_Fields_TestFieldUINT8Array == TRUE )
FUNC(void, RTE_CODE) ETS_SetFieldTestFieldUINT8Array (P2VAR(ETS_Uint8Array, AUTOMATIC, RTE_APPL_DATA) Setter)
{
  ETS_SetField_VarArray(Setter);
}
#endif

/**
 * \brief Get field interface version.
 *
 * \param[in] Getter Field interface version.
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0049, 1 */
#if ( ETS_Fields_InterfaceVersion == TRUE )
/* Deviation MISRAC2012-2 */
FUNC(void, RTE_CODE) ETS_GetFieldInterfaceVersion (P2VAR(ETS_VersionType, AUTOMATIC, RTE_APPL_DATA) Getter)
{
  ETS_GetField_InterfaceVersion(Getter);
}
#endif

#define ETS_STOP_SEC_CODE
#include <ETS_MemMap.h>

/* ==================[end of file]============================================ */
