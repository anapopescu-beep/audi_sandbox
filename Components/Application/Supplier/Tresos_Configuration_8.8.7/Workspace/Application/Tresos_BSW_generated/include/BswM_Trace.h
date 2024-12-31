
#ifndef BSWM_TRACE_H
#define BSWM_TRACE_H

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

/*==================[inclusions]============================================*/

/*==================[macros]================================================*/
#ifndef DBG_BSWM_INIT_ENTRY
/** \brief Entry point of function BswM_Init */
#define DBG_BSWM_INIT_ENTRY(a)
#endif

#ifndef DBG_BSWM_INIT_EXIT
/** \brief Exit point of function BswM_Init */
#define DBG_BSWM_INIT_EXIT(a)
#endif

#ifndef DBG_BSWM_GETVERSIONINFO_ENTRY
/** \brief Entry point of function BswM_GetVersionInfo */
#define DBG_BSWM_GETVERSIONINFO_ENTRY(a)
#endif

#ifndef DBG_BSWM_GETVERSIONINFO_EXIT
/** \brief Exit point of function BswM_GetVersionInfo */
#define DBG_BSWM_GETVERSIONINFO_EXIT(a)
#endif

#ifndef DBG_BSWM_DEINIT_ENTRY
/** \brief Entry point of function BswM_Deinit */
#define DBG_BSWM_DEINIT_ENTRY()
#endif

#ifndef DBG_BSWM_DEINIT_EXIT
/** \brief Exit point of function BswM_Deinit */
#define DBG_BSWM_DEINIT_EXIT()
#endif

#ifndef DBG_BSWM_REQUESTMODE_ENTRY
/** \brief Entry point of function BswM_RequestMode */
#define DBG_BSWM_REQUESTMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_REQUESTMODE_EXIT
/** \brief Exit point of function BswM_RequestMode */
#define DBG_BSWM_REQUESTMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTMODE_ENTRY
/** \brief Entry point of function BswM_ComM_CurrentMode */
#define DBG_BSWM_COMM_CURRENTMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTMODE_EXIT
/** \brief Exit point of function BswM_ComM_CurrentMode */
#define DBG_BSWM_COMM_CURRENTMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTPNCMODE_ENTRY
/** \brief Entry point of function BswM_ComM_CurrentPNCMode */
#define DBG_BSWM_COMM_CURRENTPNCMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTPNCMODE_EXIT
/** \brief Exit point of function BswM_ComM_CurrentPNCMode */
#define DBG_BSWM_COMM_CURRENTPNCMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_ENTRY
/** \brief Entry point of function BswM_Dcm_RequestCommunicationMode */
#define DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_EXIT
/** \brief Exit point of function BswM_Dcm_RequestCommunicationMode */
#define DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Dcm_CommunicationMode_CurrentState */
#define DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Dcm_CommunicationMode_CurrentState */
#define DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_DCM_REQUESTSESSIONMODE_ENTRY
/** \brief Entry point of function BswM_Dcm_RequestSessionMode */
#define DBG_BSWM_DCM_REQUESTSESSIONMODE_ENTRY(a)
#endif

#ifndef DBG_BSWM_DCM_REQUESTSESSIONMODE_EXIT
/** \brief Exit point of function BswM_Dcm_RequestSessionMode */
#define DBG_BSWM_DCM_REQUESTSESSIONMODE_EXIT(a)
#endif

#ifndef DBG_BSWM_DCM_REQUESTRESETMODE_ENTRY
/** \brief Entry point of function BswM_Dcm_RequestResetMode */
#define DBG_BSWM_DCM_REQUESTRESETMODE_ENTRY(a)
#endif

#ifndef DBG_BSWM_DCM_REQUESTRESETMODE_EXIT
/** \brief Exit point of function BswM_Dcm_RequestResetMode */
#define DBG_BSWM_DCM_REQUESTRESETMODE_EXIT(a)
#endif

#ifndef DBG_BSWM_DCM_APPLICATIONUPDATED_ENTRY
/** \brief Exit point of function BswM_Dcm_ApplicationUpdated */
#define DBG_BSWM_DCM_APPLICATIONUPDATED_ENTRY()
#endif

#ifndef DBG_BSWM_DCM_APPLICATIONUPDATED_EXIT
/** \brief Exit point of function BswM_Dcm_ApplicationUpdated */
#define DBG_BSWM_DCM_APPLICATIONUPDATED_EXIT()
#endif

#ifndef DBG_BSWM_CANSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_CanSM_CurrentState */
#define DBG_BSWM_CANSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_CANSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_CanSM_CurrentState */
#define DBG_BSWM_CANSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_ETHIF_PORTGROUPLINKSTATECHG_ENTRY
/** \brief Entry point of function BswM_EthIf_PortGroupLinkStateChg */
#define DBG_BSWM_ETHIF_PORTGROUPLINKSTATECHG_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_ETHIF_PORTGROUPLINKSTATECHG_EXIT
/** \brief Exit point of function BswM_EthIf_PortGroupLinkStateChg */
#define DBG_BSWM_ETHIF_PORTGROUPLINKSTATECHG_EXIT(a,b)
#endif

#ifndef DBG_BSWM_ETHSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_EthSM_CurrentState */
#define DBG_BSWM_ETHSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_ETHSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_EthSM_CurrentState */
#define DBG_BSWM_ETHSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_FRSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_FrSM_CurrentState */
#define DBG_BSWM_FRSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_FRSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_FrSM_CurrentState */
#define DBG_BSWM_FRSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_LinSM_CurrentState */
#define DBG_BSWM_LINSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_LinSM_CurrentState */
#define DBG_BSWM_LINSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_EcuM_CurrentState */
#define DBG_BSWM_ECUM_CURRENTSTATE_ENTRY(a)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_EcuM_CurrentState */
#define DBG_BSWM_ECUM_CURRENTSTATE_EXIT(a)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTWAKEUP_ENTRY
/** \brief Entry point of function BswM_EcuM_CurrentWakeup */
#define DBG_BSWM_ECUM_CURRENTWAKEUP_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTWAKEUP_EXIT
/** \brief Exit point of function BswM_EcuM_CurrentWakeup */
#define DBG_BSWM_ECUM_CURRENTWAKEUP_EXIT(a,b)
#endif

#ifndef DBG_BSWM_NMIF_CARWAKEUPINDICATION_ENTRY
/** \brief Entry point of function BswM_NmIf_CarWakeUpIndication */
#define DBG_BSWM_NMIF_CARWAKEUPINDICATION_ENTRY(a)
#endif

#ifndef DBG_BSWM_NMIF_CARWAKEUPINDICATION_EXIT
/** \brief Exit point of function BswM_NmIf_CarWakeUpIndication */
#define DBG_BSWM_NMIF_CARWAKEUPINDICATION_EXIT(a)
#endif

#ifndef DBG_BSWM_NVM_CURRENTBLOCKMODE_ENTRY
/** \brief Entry point of function BswM_NvM_CurrentBlockMode */
#define DBG_BSWM_NVM_CURRENTBLOCKMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_NVM_CURRENTBLOCKMODE_EXIT
/** \brief Exit point of function BswM_NvM_CurrentBlockMode */
#define DBG_BSWM_NVM_CURRENTBLOCKMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_NVM_CURRENTJOBMODE_ENTRY
/** \brief Entry point of function BswM_NvM_CurrentJobMode */
#define DBG_BSWM_NVM_CURRENTJOBMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_NVM_CURRENTJOBMODE_EXIT
/** \brief Exit point of function BswM_NvM_CurrentJobMode */
#define DBG_BSWM_NVM_CURRENTJOBMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSCHEDULE_ENTRY
/** \brief Entry point of function BswM_LinSM_CurrentSchedule */
#define DBG_BSWM_LINSM_CURRENTSCHEDULE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSCHEDULE_EXIT
/** \brief Exit point of function BswM_LinSM_CurrentSchedule */
#define DBG_BSWM_LINSM_CURRENTSCHEDULE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_LINTP_REQUESTMODE_ENTRY
/** \brief Entry point of function BswM_LinTp_RequestMode */
#define DBG_BSWM_LINTP_REQUESTMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_LINTP_REQUESTMODE_EXIT
/** \brief Exit point of function BswM_LinTp_RequestMode */
#define DBG_BSWM_LINTP_REQUESTMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Sd_ClientServiceCurrentState */
#define DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Sd_ClientServiceCurrentState */
#define DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Sd_ConsumedEventGroupCurrentState */
#define DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Sd_ConsumedEventGroupCurrentState */
#define DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Sd_EventHandlerCurrentState */
#define DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Sd_EventHandlerCurrentState */
#define DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_WDGM_REQUESTPARTITIONRESET_ENTRY
/** \brief Entry point of function BswM_WdgM_RequestPartitionReset */
#define DBG_BSWM_WDGM_REQUESTPARTITIONRESET_ENTRY(a)
#endif

#ifndef DBG_BSWM_WDGM_REQUESTPARTITIONRESET_EXIT
/** \brief Exit point of function BswM_WdgM_RequestPartitionReset */
#define DBG_BSWM_WDGM_REQUESTPARTITIONRESET_EXIT(a)
#endif

#ifndef DBG_BSWM_TRIGGERSTARTUPPHASE2_ENTRY
/** \brief Entry point of function BswM_TriggerStartUpPhase2 */
#define DBG_BSWM_TRIGGERSTARTUPPHASE2_ENTRY(a)
#endif

#ifndef DBG_BSWM_TRIGGERSTARTUPPHASE2_EXIT
/** \brief Exit point of function BswM_TriggerStartUpPhase2 */
#define DBG_BSWM_TRIGGERSTARTUPPHASE2_EXIT(a,b)
#endif

#ifndef DBG_BSWM_TRIGGERSLAVERTESTOP_ENTRY
/** \brief Entry point of function BswM_TriggerSlaveRTEStop */
#define DBG_BSWM_TRIGGERSLAVERTESTOP_ENTRY(a)
#endif

#ifndef DBG_BSWM_TRIGGERSLAVERTESTOP_EXIT
/** \brief Exit point of function BswM_TriggerSlaveRTEStop */
#define DBG_BSWM_TRIGGERSLAVERTESTOP_EXIT(a,b)
#endif

#ifndef DBG_BSWM_MAINFUNCTION_ENTRY
/** \brief Entry point of function BswM_MainFunction */
#define DBG_BSWM_MAINFUNCTION_ENTRY()
#endif

#ifndef DBG_BSWM_MAINFUNCTION_EXIT
/** \brief Exit point of function BswM_MainFunction */
#define DBG_BSWM_MAINFUNCTION_EXIT()
#endif

#ifndef DBG_BSWM_CORE_INIT_ENTRY
/** \brief Entry point of function BswM_Core_Init */
#define DBG_BSWM_CORE_INIT_ENTRY()
#endif

#ifndef DBG_BSWM_CORE_INIT_EXIT
/** \brief Exit point of function BswM_Core_Init */
#define DBG_BSWM_CORE_INIT_EXIT()
#endif

#ifndef DBG_BSWM_PARTITION_INIT_ENTRY
/** \brief Entry point of function BswM_Partition_Init */
#define DBG_BSWM_PARTITION_INIT_ENTRY(a)
#endif

#ifndef DBG_BSWM_PARTITION_INIT_EXIT
/** \brief Exit point of function BswM_Partition_Init */
#define DBG_BSWM_PARTITION_INIT_EXIT(a)
#endif

#ifndef DBG_BSWM_PB_INIT_ENTRY
/** \brief Entry point of function BswM_PB_Init */
#define DBG_BSWM_PB_INIT_ENTRY(a,b,c)
#endif

#ifndef DBG_BSWM_PB_INIT_EXIT
/** \brief Exit point of function BswM_PB_Init */
#define DBG_BSWM_PB_INIT_EXIT(a,b,c,d)
#endif

#ifndef DBG_BSWM_RT_INIT_ENTRY
/** \brief Entry point of function BswM_RT_Init */
#define DBG_BSWM_RT_INIT_ENTRY(a)
#endif

#ifndef DBG_BSWM_RT_INIT_EXIT
/** \brief Exit point of function BswM_RT_Init */
#define DBG_BSWM_RT_INIT_EXIT(a)
#endif

#ifndef DBG_BSWM_LT_INIT_ENTRY
/** \brief Entry point of function BswM_LT_Init */
#define DBG_BSWM_LT_INIT_ENTRY()
#endif

#ifndef DBG_BSWM_LT_INIT_EXIT
/** \brief Exit point of function BswM_LT_Init */
#define DBG_BSWM_LT_INIT_EXIT()
#endif

/* Dynamically generated macros */
#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTUPTWOA_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_OnStartupTwoA */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTUPTWOA_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTUPTWOA_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_OnStartupTwoA */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTUPTWOA_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTUPTWOB_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_OnStartupTwoB */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTUPTWOB_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTUPTWOB_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_OnStartupTwoB */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTUPTWOB_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_COMM_ENABLEPDUS_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_ComM_EnablePdus */
#define DBG_BSWM_ACTION_BSWMACTION_COMM_ENABLEPDUS_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_COMM_ENABLEPDUS_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_ComM_EnablePdus */
#define DBG_BSWM_ACTION_BSWMACTION_COMM_ENABLEPDUS_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_ONGOOFFONEA_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_OnGoOffOneA */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_ONGOOFFONEA_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_ONGOOFFONEA_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_OnGoOffOneA */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_ONGOOFFONEA_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_ONWAKEUPEXPIRED_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_OnWakeupExpired */
#define DBG_BSWM_ACTION_BSWMACTION_ONWAKEUPEXPIRED_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_ONWAKEUPEXPIRED_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_OnWakeupExpired */
#define DBG_BSWM_ACTION_BSWMACTION_ONWAKEUPEXPIRED_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_ONWAKEUPVALIDATION_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_OnWakeupValidation */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_ONWAKEUPVALIDATION_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_ONWAKEUPVALIDATION_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_OnWakeupValidation */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_ONWAKEUPVALIDATION_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_ON_PREP_SHUTDOWN_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_On_Prep_Shutdown */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_ON_PREP_SHUTDOWN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_ON_PREP_SHUTDOWN_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_On_Prep_Shutdown */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_ON_PREP_SHUTDOWN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_ECUM_SELECTSHUTDOWNTARGET_RESET_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_EcuM_SelectShutdownTarget_RESET */
#define DBG_BSWM_ACTION_BSWMACTION_ECUM_SELECTSHUTDOWNTARGET_RESET_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_ECUM_SELECTSHUTDOWNTARGET_RESET_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_EcuM_SelectShutdownTarget_RESET */
#define DBG_BSWM_ACTION_BSWMACTION_ECUM_SELECTSHUTDOWNTARGET_RESET_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTCOMEFFECTIVE_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_OnStartComEffective */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTCOMEFFECTIVE_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTCOMEFFECTIVE_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_OnStartComEffective */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSTARTCOMEFFECTIVE_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_PROCEEDRESET_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_ProceedReset */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_PROCEEDRESET_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_PROCEEDRESET_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_ProceedReset */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_PROCEEDRESET_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_SWRESETNOTIFICATION_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_SWResetNotification */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_SWRESETNOTIFICATION_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_SWRESETNOTIFICATION_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_SWResetNotification */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_SWRESETNOTIFICATION_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_HWRESETNOTIFICATION_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_HWResetNotification */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_HWRESETNOTIFICATION_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_HWRESETNOTIFICATION_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_HWResetNotification */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_HWRESETNOTIFICATION_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_PREPAREJUMPTOFBL_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_PrepareJumpToFBL */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_PREPAREJUMPTOFBL_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_PREPAREJUMPTOFBL_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_PrepareJumpToFBL */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_PREPAREJUMPTOFBL_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMWAKEUP_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_RunStateFromWakeup */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMWAKEUP_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMWAKEUP_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_RunStateFromWakeup */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMWAKEUP_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_POSTRUNSTATEFROMRUN_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_PostRunStateFromRun */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_POSTRUNSTATEFROMRUN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_POSTRUNSTATEFROMRUN_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_PostRunStateFromRun */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_POSTRUNSTATEFROMRUN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMPOSTRUNBUSAVAILABLE_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_RunStateFromPostRunBusAvailable */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMPOSTRUNBUSAVAILABLE_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMPOSTRUNBUSAVAILABLE_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_RunStateFromPostRunBusAvailable */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMPOSTRUNBUSAVAILABLE_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_LOWPWRSTATEFROMPOSTRUN_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_LowPwrStateFromPostRun */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_LOWPWRSTATEFROMPOSTRUN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_LOWPWRSTATEFROMPOSTRUN_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_LowPwrStateFromPostRun */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_LOWPWRSTATEFROMPOSTRUN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMLOWPWR_ACTIVEWAKE_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_RunStateFromLowPwr_ActiveWake */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMLOWPWR_ACTIVEWAKE_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMLOWPWR_ACTIVEWAKE_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_RunStateFromLowPwr_ActiveWake */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMLOWPWR_ACTIVEWAKE_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMLOWPWR_PASSIVEWAKE_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_RunStateFromLowPwr_PassiveWake */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMLOWPWR_PASSIVEWAKE_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMLOWPWR_PASSIVEWAKE_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_RunStateFromLowPwr_PassiveWake */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMLOWPWR_PASSIVEWAKE_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_ECUM_SELECTSHUTDOWNTARGET_SLEEP_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_EcuM_SelectShutdownTarget_SLEEP */
#define DBG_BSWM_ACTION_BSWMACTION_ECUM_SELECTSHUTDOWNTARGET_SLEEP_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_ECUM_SELECTSHUTDOWNTARGET_SLEEP_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_EcuM_SelectShutdownTarget_SLEEP */
#define DBG_BSWM_ACTION_BSWMACTION_ECUM_SELECTSHUTDOWNTARGET_SLEEP_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_COMM_FULLCOM_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_ComM_FullCom */
#define DBG_BSWM_ACTION_BSWMACTION_COMM_FULLCOM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_COMM_FULLCOM_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_ComM_FullCom */
#define DBG_BSWM_ACTION_BSWMACTION_COMM_FULLCOM_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_COMM_ENABLETXPDUCONFIRMATION_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_ComM_EnableTxPduConfirmation */
#define DBG_BSWM_ACTION_BSWMACTION_COMM_ENABLETXPDUCONFIRMATION_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_COMM_ENABLETXPDUCONFIRMATION_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_ComM_EnableTxPduConfirmation */
#define DBG_BSWM_ACTION_BSWMACTION_COMM_ENABLETXPDUCONFIRMATION_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_COMM_DISABLETXPDUCONFIRMATION_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_ComM_DisableTxPduConfirmation */
#define DBG_BSWM_ACTION_BSWMACTION_COMM_DISABLETXPDUCONFIRMATION_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_COMM_DISABLETXPDUCONFIRMATION_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_ComM_DisableTxPduConfirmation */
#define DBG_BSWM_ACTION_BSWMACTION_COMM_DISABLETXPDUCONFIRMATION_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMPOSTRUNPASSENGERDETECTED_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_RunStateFromPostRunPassengerDetected */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMPOSTRUNPASSENGERDETECTED_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMPOSTRUNPASSENGERDETECTED_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_RunStateFromPostRunPassengerDetected */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_RUNSTATEFROMPOSTRUNPASSENGERDETECTED_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSAFESTATEFROMPOSTRUN_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_OnSafeStateFromPostRun */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSAFESTATEFROMPOSTRUN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSAFESTATEFROMPOSTRUN_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_OnSafeStateFromPostRun */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_ONSAFESTATEFROMPOSTRUN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_ONRUNFROMSAFESTATE_ENTRY
/** \brief Entry point of function BswM_Action_BswMAction_BswM_OnRunFromSafeState */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_ONRUNFROMSAFESTATE_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_BSWMACTION_BSWM_ONRUNFROMSAFESTATE_EXIT
/** \brief Exit point of function BswM_Action_BswMAction_BswM_OnRunFromSafeState */
#define DBG_BSWM_ACTION_BSWMACTION_BSWM_ONRUNFROMSAFESTATE_EXIT()
#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[end of file]===========================================*/
/** @} doxygen end group definition */
#endif /* ifndef BSWM_TRACE_H */
/*==================[end of file]============================================*/

