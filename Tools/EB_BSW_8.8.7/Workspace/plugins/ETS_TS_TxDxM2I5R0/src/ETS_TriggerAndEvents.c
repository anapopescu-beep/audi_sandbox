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

/* ==================[Includes]=============================================== */

#include <ETS_TriggerAndEvents.h>
#include <ETS_Types.h>
#include <Rte_ETS_Type.h>
#include <Rte_ETS.h>
#include <ETS_Cfg.h>

/*===================[internal data]===========================================*/

/* ==================[Definition of functions with external linkage]========== */


#define ETS_START_SEC_CODE
#include <ETS_MemMap.h>

/**
 * \brief Event EventUINT8 triggering.
 *
 * \param[in] none
 *
 * \return none
 *
 */
#if ( ETS_Service_TestEventUINT8 == TRUE )

/* !LINKSTO swdd.ETS-0043, 1 */
FUNC(void, RTE_CODE) ETS_Action_TriggerEventUINT8(void)
{
  STATIC uint8 triggerUint8Value = 1;
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType EtsReturn;
#endif
  ETS_Uint8Value eventData;

  eventData.uINT8Value = triggerUint8Value;
  triggerUint8Value++;

#if (ETS_DEV_ERROR_DETECT == STD_ON)
  EtsReturn = Rte_Write_ETS_TestEventUINT8_TestEventUINT8(&eventData);

  if (EtsReturn != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_ACT_TRIG_EVT_UINT8, ID_TRIGGER_EVENTUINT8);
  }
#else
  (void)Rte_Write_ETS_TestEventUINT8_TestEventUINT8(&eventData);
#endif
}

#endif

/**
 * \brief Event EventUINT8Reliable triggering.
 *
 * \param[in] none
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0046, 1 */
#if ( ETS_Service_TestEventUINT8Reliable == TRUE )
FUNC(void, RTE_CODE) ETS_Action_TriggerEventUINT8Reliable(void)
{
  STATIC uint8 triggerUint8ReliableValue = 1;
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType EtsReturn;
#endif
  ETS_Uint8Value eventData;

  eventData.uINT8Value = triggerUint8ReliableValue;
  triggerUint8ReliableValue++;

#if (ETS_DEV_ERROR_DETECT == STD_ON)
  EtsReturn = Rte_Write_ETS_TestEventUINT8Reliable_TestEventUINT8Reliable(&eventData);

  if (EtsReturn != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_ACT_TRIG_EVT_UINT8_RELIAB, ID_TRIGGER_EVENTUINT8RELIABLE);
  }
#else
  (void)Rte_Write_ETS_TestEventUINT8Reliable_TestEventUINT8Reliable(&eventData);
#endif
}

#endif

/**
 * \brief Event EventUINT8Array triggering.
 *
 * \param[in] none
 *
 * \return none
 *
 */
#if ( ETS_Service_TestEventUINT8Array == TRUE )

/* !LINKSTO swdd.ETS-0044, 1 */
FUNC(void, RTE_CODE) ETS_Action_TriggerEventUINT8Array(void)
{
  STATIC uint8 triggerUint8ArrayValue = 1;
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType EtsReturn;
#endif
  ETS_Uint8Array eventData;

  eventData.size = 4;
  eventData.elem[0] = triggerUint8ArrayValue;
  triggerUint8ArrayValue++;
  eventData.elem[1] = 0xED;
  eventData.elem[2] = 0xBE;
  eventData.elem[3] = 0xEF;
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  EtsReturn = Rte_Send_ETS_TestEventUINT8Array_TestEventUINT8Array(&eventData);

  if (EtsReturn != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_ACT_TRIG_EVT_UINT8_ARRAY, ID_TRIGGER_EVENTUINT8ARRAY);
  }
#else
  (void)Rte_Send_ETS_TestEventUINT8Array_TestEventUINT8Array(&eventData);
#endif
}

#endif

/**
 * \brief EventUINT8E2E triggering.
 *
 * \param[in] none
 *
 * \return none
 *
 */
#if ( ETS_Service_TestEventUINT8E2E == TRUE )
/* !LINKSTO swdd.ETS-0045, 1 */
FUNC(void, RTE_CODE) ETS_Action_TriggerEventUINT8E2E(void)
{
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType EtsReturn;
#endif
  ETS_Uint8Value eventData;

  /* TODO Check is this mine added init value correct */
  eventData.uINT8Value = 0U;

  eventData.uINT8Value++;
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  EtsReturn = Rte_Write_ETS_TestEventUINT8E2E_TestEventUINT8E2E(&eventData);

  if (EtsReturn != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_ACT_TRIG_EVT_UINT8_E2E, ID_TRIGGER_EVENTUINT8E2E);
  }
#else
  (void)Rte_Write_ETS_TestEventUINT8E2E_TestEventUINT8E2E(&eventData);
#endif
}

#endif

/**
 * \brief EventUINT8Multicast triggering.
 *
 * \param[in] none
 *
 * \return none
 *
 */
#if ( ETS_Service_TestEventUINT8Multicast == TRUE )
/* !LINKSTO swdd.ETS-0047, 1 */
FUNC(void, RTE_CODE) ETS_Action_TriggerEventUINT8Multicast(void)
{
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType EtsReturn;
#endif
  ETS_Uint8Value eventData;

  /* TODO Check is this mine added init value correct */
  eventData.uINT8Value = 0U;

  eventData.uINT8Value++;
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  EtsReturn = Rte_Write_ETS_TestEventUINT8Multicast_TestEventUINT8Multicast(&eventData);

  if (EtsReturn != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_ACT_TRIG_EVT_UINT8_MULTI_CST, ID_TRIGGER_EVENTUINT8MULTICAST);
  }
#else
  (void)Rte_Write_ETS_TestEventUINT8Multicast_TestEventUINT8Multicast(&eventData);
#endif
}

#endif

/**
 * \brief Suspend Server Service by setting ETS_SD_SERVER_SERVICE_DOWN.
 *
 * \param[in] none
 *
 * \return none
 *
 */

#if ( ETS_Service_SuspendInterface == TRUE )
/* !LINKSTO swdd.EB.ETS.TriggAndEvent.1, 1 */
FUNC(void, RTE_CODE) ETS_Action_SuspendInterface(void)
{
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType EtsReturn;

  EtsReturn = Rte_Write_ETS_SD_ServerServiceRequest_requestedMode(ETS_SD_SERVER_SERVICE_DOWN);

  if (EtsReturn != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_ACT_SUSP_INTERF, ID_SUSPENDINTERFACE);
  }
#else
  (void)Rte_Write_ETS_SD_ServerServiceRequest_requestedMode(ETS_SD_SERVER_SERVICE_DOWN);
#endif
}
#endif

/**
 * \brief Resume service by setting ETS_SD_SERVER_SERVICE_AVAILABLE.
 *
 * \param[in] none
 *
 * \return none
 *
 */

#if ( ETS_Service_SuspendInterface == TRUE )
/* !LINKSTO swdd.EB.ETS.TriggAndEvent.2, 1 */
FUNC(void, RTE_CODE) ETS_Action_ResumeInterface(void)
{
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType EtsReturn;

  EtsReturn = Rte_Write_ETS_SD_ServerServiceRequest_requestedMode(ETS_SD_SERVER_SERVICE_AVAILABLE);

  if (EtsReturn != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_ACT_RES_INTERF, ID_INTERFACEVERSION_NOTIFY);
  }
#else
  (void)Rte_Write_ETS_SD_ServerServiceRequest_requestedMode(ETS_SD_SERVER_SERVICE_AVAILABLE);
#endif
}
#endif

/**
 * \brief Resume service by setting ETS_SD_SERVER_SERVICE_AVAILABLE.
 *
 * \param[in] none
 *
 * \return none
 *
 */

#if ( ETS_Service_ClientServiceActivate == TRUE )
/* !LINKSTO swdd.EB.ETS.TriggAndEvent.3, 1 */
FUNC(void, RTE_CODE) ETS_Action_ClientActivateInterface(void)
{
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType EtsReturn;

  EtsReturn = Rte_Write_ETS_SD_ClientServiceRequest_requestedMode(ETS_SD_CLIENT_SERVICE_REQUESTED);

  if (EtsReturn != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_ACT_CLI_ACT_INTERF, ID_CLIENTSERVICE_ACTIVATE);
  }
#else
  (void)Rte_Write_ETS_SD_ClientServiceRequest_requestedMode(ETS_SD_CLIENT_SERVICE_REQUESTED);
#endif
}
#endif

/**
 * \brief Consume eventgroup by setting ETS_SD_CONSUMED_EVENTGROUP_REQUESTED.
 *
 * \param[in] none
 *
 * \return none
 *
 */

#if (ETS_Service_ClientServiceSubscribeEventgroup == STD_ON)
/* !LINKSTO swdd.EB.ETS.TriggAndEvent.4, 1 */
FUNC(void, RTE_CODE) ETS_Action_ClientSubscribeEventgroup(void)
{
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType EtsReturn;

  EtsReturn = Rte_Write_ETS_SD_ConsumedEventGroupRequest_requestedMode(ETS_SD_CONSUMED_EVENTGROUP_REQUESTED);

  if (EtsReturn != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_ACT_CLI_SUB_EVT_GRP, ID_CLIENTSERVICE_SUBSCRIBEEVENTGROUP);
  }
#else
  (void)Rte_Write_ETS_SD_ConsumedEventGroupRequest_requestedMode(ETS_SD_CONSUMED_EVENTGROUP_REQUESTED);
#endif
}
#endif

/**
 * \brief Unsubscribe eventgroup by setting ETS_SD_CONSUMED_EVENTGROUP_RELEASED.
 *
 * \param[in] none
 *
 * \return none
 *
 */

#if (ETS_Service_ClientServiceSubscribeEventgroup == STD_ON)
/* !LINKSTO swdd.EB.ETS.TriggAndEvent.5, 1 */
FUNC(void, RTE_CODE) ETS_Action_ClientUnsubscribeEventgroup(void)
{
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType EtsReturn;

  EtsReturn = Rte_Write_ETS_SD_ConsumedEventGroupRequest_requestedMode(ETS_SD_CONSUMED_EVENTGROUP_RELEASED);

  if (EtsReturn != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_ACT_CLI_UNSUB_EVT_GRP, ID_CLIENTSERVICE_SUBSCRIBEEVENTGROUP);
  }
#else
  (void)Rte_Write_ETS_SD_ConsumedEventGroupRequest_requestedMode(ETS_SD_CONSUMED_EVENTGROUP_RELEASED);
#endif
}
#endif


/**
 * \brief Deactivate ClientService by setting ETS_SD_CLIENT_SERVICE_RELEASED.
 *
 * \param[in] none
 *
 * \return none
 *
 */

#if (ETS_Service_ClientServiceDeactivate == STD_ON)
/* !LINKSTO swdd.EB.ETS.TriggAndEvent.6, 1 */
FUNC(void, RTE_CODE) ETS_Action_ClientDeactivateInterface(void)
{
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType EtsReturn;

  EtsReturn = Rte_Write_ETS_SD_ClientServiceRequest_requestedMode(ETS_SD_CLIENT_SERVICE_RELEASED);

  if (EtsReturn != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_ACT_CLI_DE_ACT_INTERF, ID_CLIENTSERVICE_DEACTIVATE);
  }
#else
  (void)Rte_Write_ETS_SD_ClientServiceRequest_requestedMode(ETS_SD_CLIENT_SERVICE_RELEASED);
#endif
}
#endif

#define ETS_STOP_SEC_CODE
#include <ETS_MemMap.h>

/* ==================[end of file]============================================ */
