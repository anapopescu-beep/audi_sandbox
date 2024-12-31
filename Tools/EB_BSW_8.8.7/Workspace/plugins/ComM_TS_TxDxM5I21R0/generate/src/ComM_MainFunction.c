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
[!AUTOSPACING!]
[!INCLUDE "../../generate_macros/ComM_Functions.m"!][!//

[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]
[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'true'"!]
[!CALL "GetMasterCoreId"!][!//
[!CALL "GetUsedCores"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
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

[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMDevErrorDetect = 'true'"!]
#include <Det.h>
[!ENDIF!]

[!CALL "GetUsedUserPlusChannelPlusMasterPncPlusInhibitionOsApplications"!]
[!IF "(count(text:split($FoundUserPlusChannePlusMasterPncPlusInhibitionOsApplications,' ')) > 1) and (as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'false')"!]
#include <Os.h>
[!ENDIF!] [!/*[!IF "(count(text:split($FoundUserPlusChannePlusMasterPncPlusInhibitionOsApplications,' ')) > 1) and (as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'false')"!]*/!]

[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMRteUsage = 'true'"!]
/* Symbols defined by RTE: Rte_ModeType_ComMode
 * Functions declared by RTE: ComM_RequestComMode(), ComM_MainFunction_X() */
 /* !LINKSTO ComM506_Refine_Rte,1 */
  [!CALL "GetUsedUserPlusChannelPlusMasterPncPlusInhibitionOsApplications"!]
  [!IF "not((count(text:split($FoundUserPlusChannePlusMasterPncPlusInhibitionOsApplications,' ')) > 1) and (as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'false'))"!]
#include <Rte_ComM.h>       /* Include Symbols defined by RTE */
  [!ENDIF!] [!/*[!IF "(count(text:split($FoundUserPlusChannePlusMasterPncPlusInhibitionOsApplications,' ')) > 1) and (as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'false')"!]*/!]
[!ENDIF!] [!/*[!IF "ComMGeneral/ComMRteUsage = 'true'"!]*/!]
/* for the case COMM_INCLUDE_RTE == STD_OFF these symbols are provided via
 * ComM.h. */


[!CALL "GetUsedUserPlusChannelPlusMasterPncPlusInhibitionOsApplications"!]
[!IF "(count(text:split($FoundUserPlusChannePlusMasterPncPlusInhibitionOsApplications,' ')) > 1) and (as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'false')"!]
  [!CALL "GetUsedChannelsOsApplications"!]
  [!FOR "Idx1" = "1" TO "count(text:split($FoundChannelsOsApplications,' '))"!]
    [!VAR "CurrentOsApplication" = "string(text:split($FoundChannelsOsApplications,' ')[position() = $Idx1])"!]
#include <SchM_ComM_1_Ch_OsApplication_[!"$CurrentOsApplication"!]_ComM.h>
  [!ENDFOR!] [!/*[!FOR "Idx1" = "1" TO "count(text:split($FoundChannelsOsApplications,' '))"!]*/!]

  [!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]
    [!CALL "GetMasterPncOsApplication"!]
    [!CALL "GetUsedSignalsPlusMasterPncOsApplications"!]
    [!FOR "Idx1" = "1" TO "count(text:split($FoundMasterPncPlusSignalsOsApplications,' '))"!]
      [!VAR "CurrentOsApplication" = "string(text:split($FoundMasterPncPlusSignalsOsApplications,' ')[position() = $Idx1])"!]
      [!IF "($CurrentOsApplication) != ($MasterPncOsApplication)"!]
#include <SchM_ComM_1_SgnSlavePnc_[!"($CurrentOsApplication)"!].h>
      [!ENDIF!] [!/*[!IF "($CurrentOsApplication) != ($MasterPncOsApplication)"!]*/!]
    [!ENDFOR!] [!/*[!FOR "Idx1" = "1" TO "count(text:split($FoundMasterPncPlusSignalsOsApplications,' '))"!]*/!]
#include <SchM_ComM_1_MasterPnc.h>
  [!ENDIF!] [!/* [!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!] */!]
  [!CALL "GetUsedUserOsApplications"!]
  [!FOR "Idx1" = "1" TO "count(text:split($FoundUserOsApplications,' '))"!]
    [!VAR "CurrentOsApplication" = "string(text:split($FoundUserOsApplications,' ')[position() = $Idx1])"!]
#include <SchM_ComM_1_User_[!"$CurrentOsApplication"!]_ComM.h>
  [!ENDFOR!] [!/*[!FOR "Idx1" = "1" TO "count(text:split($FoundUserOsApplications,' '))"!]*/!]
  [!IF "(as:modconf('ComM')[1]/ComMGeneral/ComMModeLimitationEnabled = 'true') or (as:modconf('ComM')[1]/ComMGeneral/ComMWakeupInhibitionEnabled = 'true')"!]
#include <SchM_ComM_1_Inhibition.h>
  [!ENDIF!] [!/*[!IF "(as:modconf('ComM')[1]/ComMGeneral/ComMModeLimitationEnabled = 'true') or (as:modconf('ComM')[1]/ComMGeneral/ComMWakeupInhibitionEnabled = 'true')"!]*/!]
[!ELSE!] [!/*(count(text:split($FoundUserPlusChannePlusMasterPncPlusInhibitionOsApplications,' ')) > 1) and (as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'false') */!]
  [!IF "as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'true'"!]
    [!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]
      [!FOR "Idx" = "1" TO "count(text:split($UsedCores,'_'))"!]
        [!VAR "CurrentCore" = "num:i(string(text:split($UsedCores,'_')[position() = $Idx]))"!]
        [!IF "num:i($CurrentCore) != num:i($MasterCoreId)"!]
#include <SchM_ComM_1_Slave_[!"num:i($CurrentCore)"!].h>
        [!ENDIF!] [!/*[!IF "num:i($CurrentCore) != num:i($MasterCoreId)"!]*/!]
      [!ENDFOR!] [!/* [!FOR "Idx" = "1" TO "count(text:split($UsedCores,'_'))"!] */!]
    [!ENDIF!] [!/*[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]*/!]
  [!ENDIF!] [!/*[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'true'"!] */!]
[!ENDIF!]  [!/*[!IF "(count(text:split($FoundUserPlusChannePlusMasterPncPlusInhibitionOsApplications,' ')) > 1) and (as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'false')"!]*/!]
/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

[!IF "(count(text:split($FoundUserPlusChannePlusMasterPncPlusInhibitionOsApplications,' ')) > 1) and (as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'false')"!]
#define COMM_START_SEC_CODE
#include <COMM_MemMap.h>

/** \brief Channel and pnc exclusive area enter function */
FUNC(void, COMM_CODE) ComM_ChannelPncEnterExclusiveArea(const ComM_HsmStatechartPtrType sc, const uint16 idx)
{
[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]
  if (sc == (&ComM_HsmScComM))
  {
    ComM_Multicore_ChannelEnterExclusiveArea_FctPtr_List[idx]();
  }
  else
  {
    SchM_Enter_ComM_1_MasterPnc_SCHM_COMM_EXCLUSIVE_AREA_MASTERPNC();
  }
[!ELSE!] [!/*[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]*/!]
  TS_PARAM_UNUSED(sc);
  ComM_Multicore_ChannelEnterExclusiveArea_FctPtr_List[idx]();
[!ENDIF!] [!/*[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]*/!]
}

/** \brief Channel and pnc exclusive area exit function */
FUNC(void, COMM_CODE) ComM_ChannelPncExitExclusiveArea(const ComM_HsmStatechartPtrType sc, const uint16 idx)
{
[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]
  if (sc == (&ComM_HsmScComM))
  {
    ComM_Multicore_ChannelExitExclusiveArea_FctPtr_List[idx]();
  }
  else
  {
    SchM_Exit_ComM_1_MasterPnc_SCHM_COMM_EXCLUSIVE_AREA_MASTERPNC();
  }
[!ELSE!] [!/*[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]*/!]
  TS_PARAM_UNUSED(sc);
  ComM_Multicore_ChannelExitExclusiveArea_FctPtr_List[idx]();
[!ENDIF!] [!/*[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]*/!]
}
#define COMM_STOP_SEC_CODE
#include <COMM_MemMap.h>
  [!IF "(num:i(count(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMUser/*)) > 0)"!]
    [!CALL "GetUserToCh_FromOsAppToOsAppList"!]
    [!FOR "Idx1" = "1" TO "count(text:split($UserToChFromOsApp_ToOsApp,' '))"!]
      [!VAR "CurrentFromOsAppToOsApp" = "string(text:split($UserToChFromOsApp_ToOsApp,' ')[position() = $Idx1])"!]
      [!VAR "FromOsApplication" = "string(text:split($CurrentFromOsAppToOsApp,'->')[position() = 1])"!]
      [!VAR "ToOsApplication" = "string(text:split($CurrentFromOsAppToOsApp,'->')[position() = 2])"!]
#define COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_START_SEC_CODE
#include <COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_MemMap.h>
/** \brief Multicore user to channel receive function */
FUNC(void, COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_CODE) ComM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_User_To_Ch_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_RcvFnct(void)
{
  ComM_User_To_Ch_DataType data;
  while(SCHM_E_OK == SchM_Receive_ComM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_ComM_User_To_Ch_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_DataGet(&data))
  {
    if (data.Operation == COMM_MULTICORE_REQUEST_COMMODE_EVALUATE_CHANNEL)
    {
      ComM_EvaluateChannel(data.Channel);
    }
    else
    if (data.Operation == COMM_MULTICORE_EMIT_REQ_STATUS_CHANGED)
    {
      COMM_EMIT(data.Channel, COMM_HSM_COMM_EV_REQ_STATUS_CHANGED);
    }
    else
    {

    }
  }
}
#define COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_STOP_SEC_CODE
#include <COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_MemMap.h>
    [!ENDFOR!] [!/*[!FOR "Idx1" = "1" TO "count(text:split($FoundChannelsOsApplications,' '))"!]*/!]
  [!ENDIF!] [!/*[!IF "(num:i(count(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMUser/*)) > 0)"!]*/!]

  [!IF "(as:modconf('ComM')[1]/ComMGeneral/ComMRteUsage = 'true') or (as:modconf('ComM')[1]/ComMGeneral/ComMModeLimitationEnabled = 'true')"!]
    [!IF "(num:i(count(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMUser/*)) > 0)"!]
      [!CALL "GetChToUser_FromOsAppToOsAppList"!]
      [!FOR "Idx1" = "1" TO "count(text:split($ChToUserFromOsApp_ToOsApp,' '))"!]
        [!VAR "CurrentFromOsAppToOsApp" = "string(text:split($ChToUserFromOsApp_ToOsApp,' ')[position() = $Idx1])"!]
        [!VAR "FromOsApplication" = "string(text:split($CurrentFromOsAppToOsApp,'->')[position() = 1])"!]
        [!VAR "ToOsApplication" = "string(text:split($CurrentFromOsAppToOsApp,'->')[position() = 2])"!]
#define COMM_1_User_[!"$ToOsApplication"!]_ComM_START_SEC_CODE
#include <ComM_1_User_[!"$ToOsApplication"!]_ComM_MemMap.h>
/** \brief Multicore channel to user receive function */
FUNC(void, COMM_1_User_[!"$ToOsApplication"!]_ComM_CODE) ComM_1_User_[!"$ToOsApplication"!]_ComM_Ch_To_User_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_RcvFnct(void)
{
  ComM_Ch_To_User_DataType inData;
  while(SCHM_E_OK == SchM_Receive_ComM_1_User_[!"$ToOsApplication"!]_ComM_ComM_Ch_To_User_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_DataGet(&inData))
  {
#if (COMM_INCLUDE_RTE == STD_ON)
    if (inData.Operation == COMM_MULTICORE_NOTIFY_RTE)
    {
      ComM_RteNotificationSuccessful[inData.User] = FALSE;
    }
#endif /* #if (COMM_INCLUDE_RTE == STD_ON) */
#if ((COMM_MODE_LIMITATION_ENABLED == STD_ON) && (COMM_NUM_USERS > 0))
    if (inData.Operation == COMM_MULTICORE_CLEAR_USER_REQUEST)
    {
      uint8 ChannelPos = 0;
#if (COMM_NUM_PNC > 0U)
      PNCHandleType PncPos = 0;
#endif /* #if (COMM_NUM_PNC > 0U) */
      ComM_UserRequestedComMode[inData.User] = COMM_NO_COMMUNICATION;
      for (ChannelPos = 0U; ChannelPos < COMM_NUM_CHANNELS_OF_USER(inData.User); ++ChannelPos)
      {
        const uint8 Channel = COMM_CHANNEL_OF_USER(inData.User,ChannelPos);
#if (COMM_OS_APPLICATION_USER_TO_CH_FCTPTR_LENGTH != 0)
        if (ComM_Multicore_UserToChSchmSend_FctPtr_IndexList[inData.User][Channel] != COMM_MULTICORE_INVALID_FCT_INDEX)
        {
          ComM_User_To_Ch_DataType UserToChData;
          UserToChData.Channel = Channel;
          UserToChData.Operation = COMM_MULTICORE_REQUEST_COMMODE_EVALUATE_CHANNEL;
          /* !LINKSTO ComM.EB.UserToChannelCrossPartition,1 */
          if (ComM_Multicore_UserToChSchmSend_FctPtr_List[ComM_Multicore_UserToChSchmSend_FctPtr_IndexList[inData.User][Channel]](&UserToChData) != SCHM_E_OK)
          {
#if (COMM_DEV_ERROR_DETECT == STD_ON)
            /* !LINKSTO ComM.EB.ChannelToUserDataGetSIDError,1 */
            /* !LINKSTO ComM.EB.UserToChannelDataSetError,1 */
            COMM_DET_REPORT_ERROR(GetApplicationID(), COMM_SID_CHANNEL_TO_USER_DATA_GET, COMM_E_USER_TO_CH_DATASET_ERROR);
            
#endif
          }
        }
        else
#endif /*#if (COMM_OS_APPLICATION_USER_TO_CH_FCTPTR_LENGTH != 0)*/          
        {
          ComM_EvaluateChannel(Channel);
        }
      }
#if (COMM_NUM_PNC > 0U)
#if (COMM_OS_APPLICATION_USER_TO_MASTER_PNC_FCTPTR_LENGTH != 0)  
      if (ComM_Multicore_UserToMasterPncSchmSend_FctPtr_IndexList[inData.User] != COMM_MULTICORE_INVALID_FCT_INDEX)
      {
        ComM_User_To_MasterPnc_DataType UserToMasterPncData;
        UserToMasterPncData.User = inData.User;
        UserToMasterPncData.Operation = COMM_MULTICORE_EVALUATE_PNC;
        UserToMasterPncData.ComMode = inData.ComMode;
        /* !LINKSTO ComM.EB.UserToMasterPncCrossPartition, 1*/
        if (ComM_Multicore_UserToMasterPncSchmSend_FctPtr_List[ComM_Multicore_UserToMasterPncSchmSend_FctPtr_IndexList[inData.User]](&UserToMasterPncData) != SCHM_E_OK)
        {
#if (COMM_DEV_ERROR_DETECT == STD_ON)
          /* !LINKSTO ComM.EB.ChannelToUserDataGetSIDError,1 */
          /* !LINKSTO ComM.EB.UserToMasterPncDataSetError,1 */
          COMM_DET_REPORT_ERROR(GetApplicationID(), COMM_SID_CHANNEL_TO_USER_DATA_GET, COMM_E_USER_TO_MASTERPNC_DATASET_ERROR);
#endif
        }
      }
      else
#endif /*#if (COMM_OS_APPLICATION_USER_TO_MASTER_PNC_FCTPTR_LENGTH != 0) */        
      {
        for (PncPos = 0U; PncPos < COMM_NUM_PNCS_OF_USER(inData.User); PncPos++)
        {
          const PNCHandleType Pnc = COMM_PNC_OF_USER(inData.User,PncPos);
          /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_RequestComMode_NO_COM_REQ_BY_ALL_COMM_USER,1 */
          ComM_EvaluatePnc(Pnc, inData.ComMode);
        }
      }

#endif /* #if (COMM_NUM_PNC > 0U) */
    }
#endif /* #if ((COMM_MODE_LIMITATION_ENABLED == STD_ON) && (COMM_NUM_USERS > 0)) */
  }
}
#define COMM_1_User_[!"$ToOsApplication"!]_ComM_STOP_SEC_CODE
#include <ComM_1_User_[!"$ToOsApplication"!]_ComM_MemMap.h>
      [!ENDFOR!] [!/*[!FOR "Idx1" = "1" TO "count(text:split($ChToUserFromOsApp_ToOsApp,' '))"!]*/!]
    [!ENDIF!] [!/*[!IF "(num:i(count(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMUser/*)) > 0)"!]*/!]
  [!ENDIF!] [!/*[!IF "(as:modconf('ComM')[1]/ComMGeneral/ComMRteUsage = 'true') or (as:modconf('ComM')[1]/ComMGeneral/ComMModeLimitationEnabled = 'true')"!] */!]

  [!IF "(as:modconf('ComM')[1]/ComMGeneral/ComMModeLimitationEnabled = 'true') or (as:modconf('ComM')[1]/ComMGeneral/ComMWakeupInhibitionEnabled = 'true')"!]
    [!CALL "GetInhibitionToCh_FromOsAppToOsAppList"!]
    [!FOR "Idx1" = "1" TO "count(text:split($InhibitionToChFromOsApp_ToOsApp,' '))"!]
      [!VAR "CurrentFromOsAppToOsApp" = "string(text:split($InhibitionToChFromOsApp_ToOsApp,' ')[position() = $Idx1])"!]
      [!VAR "FromOsApplication" = "string(text:split($CurrentFromOsAppToOsApp,'->')[position() = 1])"!]
      [!VAR "ToOsApplication" = "string(text:split($CurrentFromOsAppToOsApp,'->')[position() = 2])"!]
#define COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_START_SEC_CODE
#include <COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_MemMap.h>
/** \brief Multicore inhibition to channel receive function */
FUNC(void, COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_CODE) ComM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_Inhibition_To_Ch_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_RcvFnct(void)
{
  ComM_Inhibition_To_Ch_DataType data;
  while(SCHM_E_OK == SchM_Receive_ComM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_ComM_Inhibition_To_Ch_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_DataGet(&data))
  {
    if (data.Operation == COMM_MULTICORE_EMIT_WAKEUP_INHIBITION)
    {
      COMM_EMIT(data.Channel, COMM_HSM_COMM_EV_WAKEUP_INHIBITION);
    }
    else
    if (data.Operation == COMM_MULTICORE_EMIT_LIMIT_TO_NO_COM)
    {
      COMM_EMIT(data.Channel, COMM_HSM_COMM_EV_LIMIT_TO_NO_COM);
    }
    else
    if (data.Operation == COMM_MULTICORE_EMIT_REQ_STATUS_CHANGED)
    {
      COMM_EMIT(data.Channel, COMM_HSM_COMM_EV_REQ_STATUS_CHANGED);
    }
    else
    {

    }
  }
}
#define COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_STOP_SEC_CODE
#include <COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_MemMap.h>
    [!ENDFOR!] [!/*[!FOR "Idx1" = "1" TO "count(text:split($InhibitionToChFromOsApp_ToOsApp,' '))"!]*/!]

    [!CALL "GetChToInhibition_FromOsAppToOsAppList"!]
    [!FOR "Idx1" = "1" TO "count(text:split($ChToInhibitionFromOsApp_ToOsApp,' '))"!]
      [!VAR "CurrentFromOsAppToOsApp" = "string(text:split($ChToInhibitionFromOsApp_ToOsApp,' ')[position() = $Idx1])"!]
      [!VAR "FromOsApplication" = "string(text:split($CurrentFromOsAppToOsApp,'->')[position() = 1])"!]
      [!VAR "ToOsApplication" = "string(text:split($CurrentFromOsAppToOsApp,'->')[position() = 2])"!]
#define COMM_1_Inhibition_START_SEC_CODE
#include <ComM_1_Inhibition_MemMap.h>
/** \brief Multicore channel to inhibition receive function */
FUNC(void, COMM_1_Inhibition_CODE) ComM_1_Inhibition_Ch_To_Inhibition_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_RcvFnct(void)
{
  ComM_Ch_To_Inhibition_DataType data;
  while(SCHM_E_OK == SchM_Receive_ComM_1_Inhibition_ComM_Ch_To_Inhibition_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_DataGet(&data))
  {
    if (data.Operation == COMM_MULTICORE_COMM_PREVENT_WAKEUP_TRUE)
    {
      ComM_SetChannelComMInhibitionStatus(data.Channel, COMM_PREVENT_WAKEUP, TRUE);
    }
    else
    if (data.Operation == COMM_MULTICORE_COMM_PREVENT_WAKEUP_FALSE)
    {
      ComM_SetChannelComMInhibitionStatus(data.Channel, COMM_PREVENT_WAKEUP, FALSE);
    }
    else
    if (data.Operation == COMM_MULTICORE_COMM_LIMIT_NOCOM_TRUE)
    {
      ComM_SetChannelComMInhibitionStatus(data.Channel, COMM_LIMIT_NOCOMM, TRUE);
    }
    else
    if(data.Operation == COMM_MULTICORE_COMM_LIMIT_NOCOM_FALSE)
    {
      ComM_SetChannelComMInhibitionStatus(data.Channel, COMM_LIMIT_NOCOMM, FALSE);
    }
    else
    {
    }
  }
}
#define COMM_1_Inhibition_STOP_SEC_CODE
#include <ComM_1_Inhibition_MemMap.h>
    [!ENDFOR!] [!/*[!FOR "Idx1" = "1" TO "count(text:split($ChToInhibitionFromOsApp_ToOsApp,' '))"!]*/!]
  [!ENDIF!] [!/*[!IF "(as:modconf('ComM')[1]/ComMGeneral/ComMModeLimitationEnabled = 'true') or (as:modconf('ComM')[1]/ComMGeneral/ComMWakeupInhibitionEnabled = 'true')"!]*/!]

  [!CALL "GetChToCh_FromOsAppToOsAppList"!]
  [!FOR "Idx1" = "1" TO "count(text:split($ChToChFromOsApp_ToOsApp,' '))"!]
    [!VAR "FromOsApplicationToOsApplication" = "string(text:split($ChToChFromOsApp_ToOsApp,' ')[position() = $Idx1])"!]
    [!VAR "FromOsApplication" = "string(text:split($FromOsApplicationToOsApplication,'->')[position() = 1])"!]
    [!VAR "ToOsApplication" = "string(text:split($FromOsApplicationToOsApplication,'->')[position() = 2])"!]
#define COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_START_SEC_CODE
#include <COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_MemMap.h>
/** \brief Multicore channel to channel receive function */
FUNC(void, COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_CODE) ComM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_Ch_To_Ch_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_RcvFnct(void)
{
  ComM_Ch_To_Ch_DataType data;
  while(SCHM_E_OK == SchM_Receive_ComM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_ComM_Ch_To_Ch_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_DataGet(&data))
  {
    if (data.Operation == COMM_MULTICORE_ECUM_WAKEUP_SET_PASSIVESTARTUPSTATUS)
    {
      ComM_PassiveStartupStatus[data.Channel] = TRUE;
    }
    else
    if (data.Operation == COMM_MULTICORE_ECUM_WAKEUP_EMIT_PASSIVE_WAKEUP_IND)
    {
      COMM_EMIT(data.Channel, COMM_HSM_COMM_EV_PASSIVE_WAKEUP_IND);
    }
    else
    {

    }
  }
}
#define COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_STOP_SEC_CODE
#include <COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_MemMap.h>
  [!ENDFOR!] [!/*[!FOR "Idx1" = "1" TO "count(text:split($ChToChFromOsApp_ToOsApp,' '))"!]*/!]

  [!IF "(as:modconf('ComM')[1]/ComMGeneral/ComMModeLimitationEnabled = 'true') or (as:modconf('ComM')[1]/ComMGeneral/ComMWakeupInhibitionEnabled = 'true')"!]
    [!IF "(num:i(count(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMUser/*)) > 0)"!]
      [!CALL "GetUserToInhibition_FromOsAppToOsAppList"!]
      [!FOR "Idx1" = "1" TO "count(text:split($UserToInhibitionFromOsApp_ToOsApp,' '))"!]
        [!VAR "CurrentFromOsAppToOsApp" = "string(text:split($UserToInhibitionFromOsApp_ToOsApp,' ')[position() = $Idx1])"!]
        [!VAR "FromOsApplication" = "string(text:split($CurrentFromOsAppToOsApp,'->')[position() = 1])"!]
        [!VAR "ToOsApplication" = "string(text:split($CurrentFromOsAppToOsApp,'->')[position() = 2])"!]
#define COMM_1_Inhibition_START_SEC_CODE
#include <ComM_1_Inhibition_MemMap.h>
/** \brief Multicore user to inhibition receive function */
FUNC(void, COMM_1_Inhibition_CODE) ComM_1_Inhibition_User_To_Inhibition_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_RcvFnct(void)
{
  uint8 data;
  while(SCHM_E_OK == SchM_Receive_ComM_1_Inhibition_ComM_User_To_Inhibition_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_DataGet(&data))
  {
    boolean Call_ComMPersDataModified = FALSE;
    SchM_Enter_ComM_1_Inhibition_SCHM_COMM_EXCLUSIVE_AREA_INHIBITION();
    if(ComM_EB_NvRAM.InhibitionCounter < 0xFFFFU)
    {
      ComM_EB_NvRAM.InhibitionCounter++;
      Call_ComMPersDataModified = TRUE;
    }
    SchM_Exit_ComM_1_Inhibition_SCHM_COMM_EXCLUSIVE_AREA_INHIBITION();
    if (Call_ComMPersDataModified == TRUE)
    {
      COMM_PERS_DATA_MODIFIED();
    }
  }
}
#define COMM_1_Inhibition_STOP_SEC_CODE
#include <ComM_1_Inhibition_MemMap.h>
      [!ENDFOR!] [!/*[!FOR "Idx1" = "1" TO "count(text:split($UserToInhibitionFromOsApp_ToOsApp,' '))"!]*/!]
    [!ENDIF!] [!/*[!IF "(num:i(count(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMUser/*)) > 0)"!]*/!]
  [!ENDIF!] [!/*[!IF "(as:modconf('ComM')[1]/ComMGeneral/ComMModeLimitationEnabled = 'true') or (as:modconf('ComM')[1]/ComMGeneral/ComMWakeupInhibitionEnabled = 'true')"!]*/!]


  [!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]
    [!CALL "GetMasterPncToCh_FromOsAppToOsAppList"!]
    [!FOR "Idx1" = "1" TO "count(text:split($MasterPncToChFromOsApp_ToOsApp,' '))"!]
      [!VAR "FromOsApplicationToOsApplication" = "string(text:split($MasterPncToChFromOsApp_ToOsApp,' ')[position() = $Idx1])"!]
      [!VAR "FromOsApplication" = "string(text:split($FromOsApplicationToOsApplication,'->')[position() = 1])"!]
      [!VAR "ToOsApplication" = "string(text:split($FromOsApplicationToOsApplication,'->')[position() = 2])"!]            
#define COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_START_SEC_CODE
#include <COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_MemMap.h>
/** \brief Multicore master pnc to channel receive function */
FUNC(void, COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_CODE) ComM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_MasterPnc_To_Ch_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_RcvFnct(void)
{

  ComM_MasterPnc_To_Ch_DataType data;
  while(SCHM_E_OK == SchM_Receive_ComM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_ComM_MasterPnc_To_Ch_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_DataGet(&data))
  {
    if (data.Operation == COMM_MULTICORE_PNC_EMIT_PNC_NM_REQUEST)
    {
      COMM_EMIT(data.Channel, COMM_HSM_COMM_EV_PNC_NM_REQUEST);
    }
    else
    if  (data.Operation == COMM_MULTICORE_PNC_EVALUATE_CHANNEL_AND_EMIT_REQ_STATUS_CHANGED)
    {
      ComM_EvaluateChannel(data.Channel);
      COMM_EMIT(data.Channel, COMM_HSM_COMM_EV_REQ_STATUS_CHANGED);
    }
    else
    if (data.Operation == COMM_MULTICORE_PNC_REQUEST_BUSSM)
    {
      COMM_EMIT_TO_SELF(data.Channel, COMM_HSM_COMM_EV_BUSSM_REQUEST_FULL_COM_WITH_WAKEUP_REQUEST);
    }    
    else
    if (data.Operation == COMM_MULTICORE_ECUM_WAKEUP_PNC_SET_PASSIVESTARTUP_STATUS)
    {
      ComM_PassiveStartupStatus[data.Channel] = TRUE;
    }
    else
    if (data.Operation == COMM_MULTICORE_ECUM_WAKEUP_PNC_EMIT_PASSIVE_WAKEUP_IND)
    {
      COMM_EMIT(data.Channel, COMM_HSM_COMM_EV_PASSIVE_WAKEUP_IND);
    }
    else 
#if (COMM_SYNCHRONIZED_PNC_SHUTDOWN_ENABLED == STD_ON)
    if (data.Operation == COMM_MULTICORE_REQUEST_SYNCHRONIZED_PNC_SHUTDOWN)
    {
      /* !LINKSTO SWS_ComM_01082_Refine1,1 */
      /* !LINKSTO SWS_ComM_01082_Refine2,1 */
      /* !LINKSTO SWS_ComM_01083,1 */
      (void) Nm_RequestSynchronizedPncShutdown(data.Channel, data.PncId);
    }
    else
#endif /* #if (COMM_SYNCHRONIZED_PNC_SHUTDOWN_ENABLED == STD_ON) */
    {
      
    }
  }
}
#define COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_STOP_SEC_CODE
#include <COMM_1_Ch_OsApplication_[!"$ToOsApplication"!]_ComM_MemMap.h>
    [!ENDFOR!] [!/* [!FOR "Idx1" = "1" TO "count(text:split($MasterPncToChFromOsApp_ToOsApp,' '))"!] */!]
  [!ENDIF!] [!/*[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]*/!]

  [!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]
    [!CALL "GetChToMasterPnc_FromOsAppToOsAppList"!]
    [!FOR "Idx1" = "1" TO "count(text:split($ChToMasterPncFromOsApp_ToOsApp,' '))"!]
      [!VAR "FromOsApplicationToOsApplication" = "string(text:split($ChToMasterPncFromOsApp_ToOsApp,' ')[position() = $Idx1])"!]
      [!VAR "FromOsApplication" = "string(text:split($FromOsApplicationToOsApplication,'->')[position() = 1])"!]
      [!VAR "ToOsApplication" = "string(text:split($FromOsApplicationToOsApplication,'->')[position() = 2])"!]
#define COMM_1_MasterPnc_START_SEC_CODE
#include <ComM_1_MasterPnc_MemMap.h>
/** \brief Multicore channel to master pnc receive function */
FUNC(void, COMM_1_MasterPnc_CODE) ComM_1_MasterPnc_Ch_To_MasterPnc_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_RcvFnct(void)
{
  ComM_Ch_To_MasterPnc_DataType data;
  while(SCHM_E_OK == SchM_Receive_ComM_1_MasterPnc_ComM_Ch_To_MasterPnc_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_DataGet(&data))
  {
    if (data.Operation == COMM_MULTICORE_ECUM_WAKEUP_EMIT_PNCPASSIVE_WAKEUP_IND)
    {
      (void)ComM_HsmEmit(&ComM_HsmScComMPnc, COMM_HSM_COMMPNC_EV_ECUM_WAKEUP_IND);
    }
    else
    {

    }
  }
}
#define COMM_1_MasterPnc_STOP_SEC_CODE
#include <ComM_1_MasterPnc_MemMap.h>
    [!ENDFOR!] [!/*[!FOR "Idx1" = "1" TO "count(text:split($ChToMasterPncFromOsApp_ToOsApp,' '))"!]*/!]
  [!ENDIF!][!/*[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]*/!]
  
 [!IF "node:exists(as:modconf('ComM')[1]/ComMGeneral/ComMSynchronizedPncShutdownEnabled) and (as:modconf('ComM')[1]/ComMGeneral/ComMSynchronizedPncShutdownEnabled = 'true')"!]
    [!CALL "GetSynchShutDownChToMasterPnc_FromOsAppToOsAppList"!]
    [!FOR "Idx1" = "1" TO "count(text:split($SynchShutDownChToMasterPncFromOsApp_ToOsApp,' '))"!]
      [!VAR "FromOsApplicationToOsApplication" = "string(text:split($SynchShutDownChToMasterPncFromOsApp_ToOsApp,' ')[position() = $Idx1])"!]
      [!VAR "FromOsApplication" = "string(text:split($FromOsApplicationToOsApplication,'->')[position() = 1])"!]
      [!VAR "ToOsApplication" = "string(text:split($FromOsApplicationToOsApplication,'->')[position() = 2])"!]
#define COMM_1_MasterPnc_START_SEC_CODE
#include <ComM_1_MasterPnc_MemMap.h>
/** \brief Multicore channel to master pnc receive function */
FUNC(void, COMM_1_MasterPnc_CODE) ComM_1_MasterPnc_SynchShutDownCh_To_MasterPnc_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_RcvFnct(void)
{
  ComM_SynchShutDownCh_To_MasterPnc_DataType data;
  uint16 cntr = 0;
  while(SCHM_E_OK == SchM_Receive_ComM_1_MasterPnc_ComM_SynchShutDownCh_To_MasterPnc_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_DataGet(&data))
  {
    SchM_Enter_ComM_1_MasterPnc_SCHM_COMM_EXCLUSIVE_AREA_MASTERPNC();
    for (cntr = 0; cntr < COMM_PN_INFO_LENGTH; cntr++)
    {
      ComM_SynchronusShutDownArr[cntr] |= (data.PnInfo[cntr] & ComM_SynchronizedShutDownPncMask[cntr]);
    } 
    SchM_Exit_ComM_1_MasterPnc_SCHM_COMM_EXCLUSIVE_AREA_MASTERPNC();    
  }
}
#define COMM_1_MasterPnc_STOP_SEC_CODE
#include <ComM_1_MasterPnc_MemMap.h>
    [!ENDFOR!] [!/*[!FOR "Idx1" = "1" TO "count(text:split($SynchShutDownChToMasterPncFromOsApp_ToOsApp,' '))"!]*/!]
  [!ENDIF!][!/*[!IF "node:exists(as:modconf('ComM')[1]/ComMGeneral/ComMSynchronizedPncShutdownEnabled) and (as:modconf('ComM')[1]/ComMGeneral/ComMSynchronizedPncShutdownEnabled = 'true')"!]*/!]
  [!IF "(as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true') and (num:i(count(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMUser/*)) > 0)"!]
    [!CALL "GetUserToMasterPnc_FromOsAppToOsAppList"!]
    [!FOR "Idx1" = "1" TO "count(text:split($UserToMasterPncFromOsApp_ToOsApp,' '))"!]
      [!VAR "CurrentFromOsAppToOsApp" = "string(text:split($UserToMasterPncFromOsApp_ToOsApp,' ')[position() = $Idx1])"!]
      [!VAR "FromOsApplication" = "string(text:split($CurrentFromOsAppToOsApp,'->')[position() = 1])"!]
      [!VAR "ToOsApplication" = "string(text:split($CurrentFromOsAppToOsApp,'->')[position() = 2])"!]
#define COMM_1_MasterPnc_START_SEC_CODE
#include <ComM_1_MasterPnc_MemMap.h>
/** \brief Multicore user to master pnc receive function */
FUNC(void, COMM_1_MasterPnc_CODE) ComM_1_MasterPnc_User_To_MasterPnc_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_RcvFnct (void)
{
  ComM_User_To_MasterPnc_DataType data;
  PNCHandleType PncPos;
  while(SCHM_E_OK == SchM_Receive_ComM_1_MasterPnc_ComM_User_To_MasterPnc_From_[!"$FromOsApplication"!]_To_[!"$ToOsApplication"!]_DataGet(&data))
  {
    if (data.Operation == COMM_MULTICORE_EVALUATE_PNC)
    {
      for (PncPos = 0U; PncPos < COMM_NUM_PNCS_OF_USER(data.User); PncPos++)
      {
        const PNCHandleType Pnc = COMM_PNC_OF_USER(data.User,PncPos);
        /* !LINKSTO ComM.EB.Dsn.StateDynamics.ComM_RequestComMode_NO_COM_REQ_BY_ALL_COMM_USER,1 */
        ComM_EvaluatePnc(Pnc, data.ComMode);
      }
    }
  }
}
#define COMM_1_MasterPnc_STOP_SEC_CODE
#include <ComM_1_MasterPnc_MemMap.h>
    [!ENDFOR!] [!/*[!FOR "Idx1" = "1" TO "count(text:split($UserToMasterPncFromOsApp_ToOsApp,' '))"!]*/!]
  [!ENDIF!] [!/*[!IF "(as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true') and (num:i(count(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMUser/*)) > 0)"!]*/!]

  [!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]
    [!CALL "GetMasterPncOsApplication"!]
    [!VAR "TxIdx" = "0"!][!//
    [!LOOP "node:order(node:refs(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalDirection='TX']/ComMPncComSignalRef), 'ComHandleId')"!]
      [!CALL "GetSignalOsApplication","SignalHandle"="ComHandleId","Direction"="'TX'"!]
      [!IF "($SignalOsApplication) != ($MasterPncOsApplication)"!]
#define COMM_1_SgnSlavePnc_[!"$SignalOsApplication"!]_START_SEC_CODE
#include <ComM_1_SgnSlavePnc_[!"$SignalOsApplication"!]_MemMap.h>
/** \brief Multicore from master pnc to slave signal partiton receive function */
FUNC(void, COMM_1_SgnSlavePnc_[!"$SignalOsApplication"!]_CODE) ComM_1_SgnSlavePnc_[!"$SignalOsApplication"!]_SgnSlavePnc_From_[!"$MasterPncOsApplication"!]_To_[!"$SignalOsApplication"!]_RcvFnct_[!"node:name(.)"!](void)
{
   uint8 ReceivedData[COMM_PN_INFO_LENGTH] = {0};
   while(SCHM_E_OK == SchM_Receive_ComM_1_SgnSlavePnc_[!"$SignalOsApplication"!]_ComM_SgnSlavePnc_From_[!"$MasterPncOsApplication"!]_To_[!"$SignalOsApplication"!]_DataGet_[!"node:name(.)"!](ReceivedData))
   {
     (void)Com_SendSignal(ComM_TxComSignalCfg[[!"num:i($TxIdx)"!]].ComHandleId, ReceivedData);
   }
}
#define COMM_1_SgnSlavePnc_[!"$SignalOsApplication"!]_STOP_SEC_CODE
#include <ComM_1_SgnSlavePnc_[!"$SignalOsApplication"!]_MemMap.h>
      [!ENDIF!] [!/*[!IF "$MasterPncOsApplication != $SignalOsApplication"!] */!]
      [!VAR "TxIdx" = "num:i($TxIdx) + 1"!]
    [!ENDLOOP!] [!/*[!LOOP "node:order(node:refs(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalDirection='TX']/ComMPncComSignalRef), 'ComHandleId')"!]*/!]

    [!LOOP "node:order(node:refs(ComMConfigSet/*[1]/ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalKind='EIRA'][ComMPncComSignalDirection='RX']/ComMPncComSignalRef), 'ComHandleId')"!]
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>
/* !LINKSTO ComM975,1, ComM986,1, ComM971,1 */
/** \brief Multicore receive signal callback */
FUNC(void, COMM_CODE) ComM_COMCbk_[!"node:name(.)"!](void)
{
  /* There is one bit indicating the status of each unique Com signal.
   * For easy mapping, the bits are assigned in the ascending order of
   * the signal handle ids.
   */
  SchM_Enter_ComM_1_MasterPnc_SCHM_COMM_EXCLUSIVE_AREA_MASTERPNC();
  ComM_RxEiraSignalStatus = TRUE;
  SchM_Exit_ComM_1_MasterPnc_SCHM_COMM_EXCLUSIVE_AREA_MASTERPNC();
}
#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
    [!ENDLOOP!] [!/*[!LOOP "node:order(node:refs(ComMConfigSet/*[1]/ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalKind='EIRA'][ComMPncComSignalDirection='RX']/ComMPncComSignalRef), 'ComHandleId')"!]*/!]
    [!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncGatewayEnabled = 'true'"!]
      [!LOOP "node:order(node:refs(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalKind='ERA'][ComMPncComSignalDirection='RX'][(node:exists(node:ref(ComMPncComSignalChannelRef)/ComMPncGatewayType)) and (node:ref(ComMPncComSignalChannelRef)/ComMPncGatewayType='COMM_GATEWAY_TYPE_ACTIVE')]/ComMPncComSignalRef), 'ComHandleId')"!]
        [!VAR "Generated" = "'false'"!]
        [!CALL "GetUsedSignalsPlusMasterPncOsApplications"!]
        [!CALL "GetMasterPncOsApplication"!]
        [!IF "count(text:split($FoundMasterPncPlusSignalsOsApplications,' ')) > 1 "!]
          [!CALL "GetSignalOsApplication","SignalHandle"="ComHandleId","Direction"="'RX'"!]
          [!IF "$SignalOsApplication != $MasterPncOsApplication"!]
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>
/* !LINKSTO ComM975,1, ComM986,1, ComM971,1 */
/** \brief Multicore receive signal callback */
FUNC(void, COMM_CODE) ComM_COMCbk_[!"node:name(.)"!](void)
{
  /* There is one bit indicating the status of each unique Com signal.
   * For easy mapping, the bits are assigned in the ascending order of
   * the signal handle ids.
   */
  uint8 ReceivedData[COMM_PN_INFO_LENGTH] = {0};
  /* !LINKSTO ComM.EB.ReceiveSignalReturnsValueDiffrentThanEOK, 1 */ 
  if(Com_ReceiveSignal([!"ComHandleId"!], ReceivedData) == E_OK)
  {
    /* !LINKSTO ComM.EB.SignalToMasterPncERACrossPartition,1 */
    if (SCHM_E_OK != SchM_Send_ComM_1_SgnSlavePnc_[!"$SignalOsApplication"!]_ComM_SgnSlavePnc_From_[!"$SignalOsApplication"!]_To_[!"$MasterPncOsApplication"!]_DataSet_[!"node:name(.)"!](ReceivedData))
    {
#if (COMM_DEV_ERROR_DETECT == STD_ON)
       /* !LINKSTO ComM.EB.SignalToMasterPncDataSetSIDError,1 */
       /* !LINKSTO ComM.EB.SignalToMasterPncSetError,1 */
       COMM_DET_REPORT_ERROR([!"$SignalOsApplication"!], COMM_SID_SLAVE_DATA_SET, COMM_E_SLAVE_DATA_SET);
#endif
    }
  }
}
#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
            [!VAR "Generated" = "'true'"!]
          [!ENDIF!] [!/*[!IF "$SignalOsApplication != $MasterPncOsApplication"!]*/!]
        [!ENDIF!] [!/*[!IF "count(text:split($FoundMasterPncPlusSignalsOsApplications,' ')) > 1 "!]*/!]
        [!IF "$Generated = 'false'"!]
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>
/* !LINKSTO ComM975,1, ComM986,1, ComM971,1 */
/** \brief Multicore receive signal callback */
FUNC(void, COMM_CODE) ComM_COMCbk_[!"node:name(.)"!](void)
{
  /* There is one bit indicating the status of each unique Com signal.
   * For easy mapping, the bits are assigned in the ascending order of
   * the signal handle ids.
   */
  SchM_Enter_ComM_1_MasterPnc_SCHM_COMM_EXCLUSIVE_AREA_MASTERPNC();
  ComM_RxActiveEraSignalStatus = TRUE;
  ComM_RxUnfilteredEraSignalStatus = TRUE;
  SchM_Exit_ComM_1_MasterPnc_SCHM_COMM_EXCLUSIVE_AREA_MASTERPNC();
}
#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
        [!ENDIF!] [!/*[!IF "$Generated = 'false'"!]*/!]
        [!IF "count(text:split($FoundMasterPncPlusSignalsOsApplications,' ')) > 1 "!]
          [!CALL "GetSignalOsApplication","SignalHandle"="ComHandleId","Direction"="'RX'"!]
          [!IF "$SignalOsApplication != $MasterPncOsApplication"!]
#define COMM_1_MasterPnc_START_SEC_CODE
#include <ComM_1_MasterPnc_MemMap.h>
/** \brief PNC signal slave to master partition receive function */
FUNC(void, COMM_1_MasterPnc_CODE) ComM_1_MasterPnc_SgnMasterPnc_From_[!"$SignalOsApplication"!]_To_[!"$MasterPncOsApplication"!]_RcvFnct_[!"node:name(.)"!](void)
{
  [!CALL "GetMulticoreRxSignalIndex","SignalHandleId"="ComHandleId"!]
  while(SCHM_E_OK == SchM_Receive_ComM_1_MasterPnc_ComM_SgnMasterPnc_From_[!"$SignalOsApplication"!]_To_[!"$MasterPncOsApplication"!]_DataGet_[!"node:name(.)"!](&ComM_MulticoreRxBuffer[[!"num:i($MulticoreRxSignalIndex)"!]][0]))
  {
    SchM_Enter_ComM_1_MasterPnc_SCHM_COMM_EXCLUSIVE_AREA_MASTERPNC();
    ComM_RxActiveEraSignalStatus = TRUE;
    ComM_RxUnfilteredEraSignalStatus = TRUE;
    SchM_Exit_ComM_1_MasterPnc_SCHM_COMM_EXCLUSIVE_AREA_MASTERPNC();
  }
}
#define COMM_1_MasterPnc_STOP_SEC_CODE
#include <ComM_1_MasterPnc_MemMap.h>
          [!ENDIF!] [!/*[!IF "$SignalOsApplication != $MasterPncOsApplication"!]*/!]
        [!ENDIF!] [!/*[!IF "count(text:split($FoundMasterPncPlusSignalsOsApplications,' ')) > 1 "!]*/!]
      [!ENDLOOP!] [!/*[!LOOP "node:order(node:refs(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalKind='ERA'][ComMPncComSignalDirection='RX'][(node:exists(node:ref(ComMPncComSignalChannelRef)/ComMPncGatewayType)) and (node:ref(ComMPncComSignalChannelRef)/ComMPncGatewayType='COMM_GATEWAY_TYPE_ACTIVE')]/ComMPncComSignalRef), 'ComHandleId')"!]*/!]

      [!LOOP "node:order(node:refs(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalKind='ERA'][ComMPncComSignalDirection='RX'][(node:exists(node:ref(ComMPncComSignalChannelRef)/ComMPncGatewayType)) and (node:ref(ComMPncComSignalChannelRef)/ComMPncGatewayType='COMM_GATEWAY_TYPE_PASSIVE')]/ComMPncComSignalRef), 'ComHandleId')"!]
        [!VAR "Generated" = "'false'"!]
        [!CALL "GetUsedSignalsPlusMasterPncOsApplications"!]
        [!CALL "GetMasterPncOsApplication"!]
        [!IF "count(text:split($FoundMasterPncPlusSignalsOsApplications,' ')) > 1 "!]
          [!CALL "GetSignalOsApplication","SignalHandle"="ComHandleId","Direction"="'RX'"!]
          [!IF "$SignalOsApplication != $MasterPncOsApplication"!]
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>
/* !LINKSTO ComM975,1, ComM986,1, ComM971,1 */
/** \brief Multicore receive signal callback */
FUNC(void, COMM_CODE) ComM_COMCbk_[!"node:name(.)"!](void)
{
  /* There is one bit indicating the status of each unique Com signal.
   * For easy mapping, the bits are assigned in the ascending order of
   * the signal handle ids.
   */
  uint8 ReceivedData[COMM_PN_INFO_LENGTH] = {0};
  /* !LINKSTO ComM.EB.ReceiveSignalReturnsValueDiffrentThanEOK, 1 */
  if(Com_ReceiveSignal([!"ComHandleId"!], ReceivedData) == E_OK)
  {
    /* !LINKSTO ComM.EB.SignalToMasterPncEIRACrossPartition,1 */
    if (SCHM_E_OK != SchM_Send_ComM_1_SgnSlavePnc_[!"$SignalOsApplication"!]_ComM_SgnSlavePnc_From_[!"$SignalOsApplication"!]_To_[!"$MasterPncOsApplication"!]_DataSet_[!"node:name(.)"!](ReceivedData))
    {
#if (COMM_DEV_ERROR_DETECT == STD_ON)
       /* !LINKSTO ComM.EB.SignalToMasterPncDataSetSIDError,1 */
       /* !LINKSTO ComM.EB.SignalToMasterPncSetError,1 */
       COMM_DET_REPORT_ERROR([!"$SignalOsApplication"!], COMM_SID_SLAVE_DATA_SET, COMM_E_SLAVE_DATA_SET);
#endif
    }
  }
}
#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
            [!VAR "Generated" = "'true'"!]
          [!ENDIF!] [!/*[!IF "$SignalOsApplication != $MasterPncOsApplication"!]*/!]
        [!ENDIF!] [!/*[!IF "count(text:split($FoundMasterPncPlusSignalsOsApplications,' ')) > 1 "!]*/!]
        [!IF "$Generated = 'false'"!]
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>
/* !LINKSTO ComM975,1, ComM986,1, ComM971,1 */
/** \brief Multicore receive signal callback */
FUNC(void, COMM_CODE) ComM_COMCbk_[!"node:name(.)"!](void)
{
  /* There is one bit indicating the status of each unique Com signal.
   * For easy mapping, the bits are assigned in the ascending order of
   * the signal handle ids.
   */
  SchM_Enter_ComM_1_MasterPnc_SCHM_COMM_EXCLUSIVE_AREA_MASTERPNC();
  ComM_RxUnfilteredEraSignalStatus = TRUE;
  SchM_Exit_ComM_1_MasterPnc_SCHM_COMM_EXCLUSIVE_AREA_MASTERPNC();
}
#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
        [!ENDIF!] [!/*[!IF "$Generated = 'false'"!]*/!]
        [!IF "count(text:split($FoundMasterPncPlusSignalsOsApplications,' ')) > 1 "!]
          [!CALL "GetSignalOsApplication","SignalHandle"="ComHandleId","Direction"="'RX'"!]
          [!IF "$SignalOsApplication != $MasterPncOsApplication"!]
#define COMM_1_MasterPnc_START_SEC_CODE
#include <ComM_1_MasterPnc_MemMap.h>
/** \brief Master core receive function for an RX signal */
FUNC(void, COMM_1_MasterPnc_CODE) ComM_1_MasterPnc_SgnMasterPnc_From_[!"$SignalOsApplication"!]_To_[!"$MasterPncOsApplication"!]_RcvFnct_[!"node:name(.)"!](void)
{
  [!CALL "GetMulticoreRxSignalIndex","SignalHandleId"="ComHandleId"!]
  while(SCHM_E_OK == SchM_Receive_ComM_1_MasterPnc_ComM_SgnMasterPnc_From_[!"$SignalOsApplication"!]_To_[!"$MasterPncOsApplication"!]_DataGet_[!"node:name(.)"!](&ComM_MulticoreRxBuffer[[!"num:i($MulticoreRxSignalIndex)"!]][0]))
  {
    SchM_Enter_ComM_1_MasterPnc_SCHM_COMM_EXCLUSIVE_AREA_MASTERPNC();
    ComM_RxUnfilteredEraSignalStatus = TRUE;
    SchM_Exit_ComM_1_MasterPnc_SCHM_COMM_EXCLUSIVE_AREA_MASTERPNC();
  }
}
#define COMM_1_MasterPnc_STOP_SEC_CODE
#include <ComM_1_MasterPnc_MemMap.h>
          [!ENDIF!] [!/*[!IF "$SignalOsApplication != $MasterPncOsApplication"!]*/!]
        [!ENDIF!] [!/*[!IF "count(text:split($FoundMasterPncPlusSignalsOsApplications,' ')) > 1 "!]*/!]
      [!ENDLOOP!] [!/*[!LOOP "node:order(node:refs(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalKind='ERA'][ComMPncComSignalDirection='RX'][(node:exists(node:ref(ComMPncComSignalChannelRef)/ComMPncGatewayType)) and (node:ref(ComMPncComSignalChannelRef)/ComMPncGatewayType='COMM_GATEWAY_TYPE_PASSIVE')]/ComMPncComSignalRef), 'ComHandleId')"!]*/!]
    [!ENDIF!] [!/*[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncGatewayEnabled = 'true'"!]*/!]
  [!ENDIF!] [!/*[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]*/!]

  [!IF "(num:i(count(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMUser/*)) > 0)"!]
    [!LOOP "as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMUser/*"!]
      [!IF "node:exists(ComMUserEcucPartitionRef)"!]
        [!CALL "GetUserOsApplication","UserEcuCPartitionRef"="ComMUserEcucPartitionRef"!]
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>
/** \brief Multicore user mainfunction */
FUNC(void, COMM_CODE) ComM_1_User_[!"$UserOsApplication"!]_ComM_MainFunction_User_[!"ComMUserIdentifier"!] (void)
{
[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMRteUsage = 'true'"!]
  if (FALSE == ComM_RteNotificationSuccessful[[!"ComMUserIdentifier"!]])
  {
   /* Report the mode to RTE, if the current mode was not yet reported to
    * the Rte for this user */
    COMM_EB_RTE_NOTIFY([!"ComMUserIdentifier"!]);
  }
[!ENDIF!] [!/*[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMRteUsage = 'true'"!]*/!]
}
#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
      [!ENDIF!] [!/*[!IF "node:exists(ComMUserEcucPartitionRef)"!]*/!]
    [!ENDLOOP!] [!/*[!LOOP "as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMUser/*"!]*/!]
  [!ENDIF!] [!/*[!IF "(num:i(count(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMUser/*)) > 0)"!]*/!]

[!LOOP "node:order(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMChannel/*, 'ComMChannelId')"!]
  [!CALL "GetChannelOsApplication","ChannelEcuCPartitionRef" = "ComMChannelPartitionRef"!]
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>
/** \brief Multicore channel mainfunction */
FUNC(void, COMM_CODE) ComM_1_Ch_OsApplication_[!"$ChannelOsApplication"!]_ComM_MainFunction_[!"ComMChannelId"!] (void)
{
  if (ComM_InitStatus != COMM_UNINIT)
  {
    ComM_ProcessTimers([!"ComMChannelId"!]U);

    if(COMM_CH_HSM_EVENT_PENDING([!"ComMChannelId"!]U))
    {
      /* ComM channels are independent of each other and do not send events to
       * each other. Hence the return value is ignored */
      (void) COMM_HSMMAININST(
        &ComM_HsmScComM, [!"ComMChannelId"!]U);
    }
  }
}
#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
[!ENDLOOP!] [!/*[!LOOP "node:order(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMChannel/*, 'ComMChannelId')"!]*/!]

[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>
/** \brief Multicore master pnc ecum wakeup indication */
[!IF "node:exists(as:modconf('EcuM')[1]/EcuMGeneral/EcuMCrossCoreComMWakeup) and (node:value(as:modconf('EcuM')[1]/EcuMGeneral/EcuMCrossCoreComMWakeup) = 'true')"!]
  [!IF "num:i(count(node:refs(as:modconf('EcuM')[1]/EcuMConfiguration/*[1]/EcuMCommonConfiguration/EcuMWakeupSource/*/EcuMComMPNCRef))) > 0"!]
FUNC(void, COMM_CODE) ComM_1_MasterPnc_EcuM_PNCWakeUpIndication (PNCHandleType PNCid)
{
  ComM_EcuM_PNCWakeUpIndication(PNCid);
}
  [!ENDIF!] [!/*[!IF "num:i(count(node:refs(as:modconf('EcuM')[1]/EcuMConfiguration/*[1]/EcuMCommonConfiguration/EcuMWakeupSource/*/EcuMComMPNCRef))) > 0"!]*/!]
[!ENDIF!] [!/*[!IF "node:exists(as:modconf('EcuM')[1]/EcuMGeneral/EcuMCrossCoreComMWakeup) and (node:value(as:modconf('EcuM')[1]/EcuMGeneral/EcuMCrossCoreComMWakeup) = 'true')"!]*/!]  

FUNC(void, COMM_CODE) ComM_1_MasterPnc_MainFunction_MasterPnc (void)
{
  if (ComM_InitStatus != COMM_UNINIT)
  {
    if( COMM_PNC_ENABLED )
    {
      ComM_PncProcessTimers();
      ComM_PncMainFunction();
    }
  }
}

#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
[!ENDIF!] [!/*[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!]*/!]

[!CALL "GetUsedEcuMChannelsOsApplications"!]
[!FOR "Idx1" = "1" TO "count(text:split($FoundEcuMChannelsOsApplications,' '))"!]
  [!VAR "CurrentOsApplication" = "string(text:split($FoundEcuMChannelsOsApplications,' ')[position() = $Idx1])"!]
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>
/** \brief Multicore channel ecum wakeup indication */
FUNC(void, COMM_CODE) ComM_1_Ch_OsApplication_[!"$CurrentOsApplication"!]_ComM_EcuM_WakeUpIndication (uint8 Channel)
{
  ComM_EcuM_WakeUpIndication(Channel);
}
#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
[!ENDFOR!] [!/*[!FOR "Idx1" = "1" TO "count(text:split($FoundEcuMChannelsOsApplications,' '))"!]*/!]

  [!IF "as:modconf('ComM')[1]/ComMGeneral/ComMDcmUsage = 'true'"!]
    [!CALL "GetUsedDcmChannelsOsApplications"!]
    [!FOR "Idx1" = "1" TO "count(text:split($FoundDcmChannelsOsApplications,' '))"!]
      [!VAR "CurrentOsApplication" = "string(text:split($FoundDcmChannelsOsApplications,' ')[position() = $Idx1])"!]
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>
/** \brief Multicore channel active diagnostic indication */
FUNC(void, COMM_CODE) ComM_1_Ch_OsApplication_[!"$CurrentOsApplication"!]_ComM_DCM_ActiveDiagnostic (uint8 Channel)
{
  ComM_DCM_ActiveDiagnostic(Channel);
}

/** \brief Multicore channel inactive diagnostic indication */
FUNC(void, COMM_CODE) ComM_1_Ch_OsApplication_[!"$CurrentOsApplication"!]_ComM_DCM_InactiveDiagnostic (uint8 Channel)
{
  ComM_DCM_InactiveDiagnostic(Channel);
}
#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
    [!ENDFOR!] [!/*[!FOR "Idx1" = "1" TO "count(text:split($FoundDcmChannelsOsApplications,' '))"!]*/!]
  [!ENDIF!] [!/* [!IF "as:modconf('ComM')[1]/ComMGeneral/ComMDcmUsage = 'true'"!] */!]


[!ELSE!] [!/*[!IF "(count(text:split($FoundUserPlusChannePlusMasterPncPlusInhibitionOsApplications,' ')) > 1) and (as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'false')"!]*/!]
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>

[!VAR "LeastMainFnPeriodChId" = "0"!][!//
[!LOOP "node:order(ComMConfigSet/*[1]/ComMChannel/*, 'ComMMainFunctionPeriod')"!][!//
[!VAR "LeastMainFnPeriodChId" = "ComMChannelId"!]
[!BREAK!]
[!ENDLOOP!][!//

[!LOOP "ComMConfigSet/*[1]/ComMChannel/*"!][!//
/** \brief Main function for channelid [!"ComMChannelId"!] **/
/* !LINKSTO ComM429,1, ComM472,1 */
FUNC(void, COMM_CODE) ComM_MainFunction_[!"ComMChannelId"!]
(
  void
)
{
  if (ComM_InitStatus != COMM_UNINIT)
  {
#if ((COMM_MULTICORE_ENABLED == STD_ON) && (COMM_WAKEUPSLEEPREQUEST_ENABLED == STD_ON))
    ComM_BusSmModeToReport[[!"ComMChannelId"!]] = COMM_INVALID_COM_MODE;
#endif /*#if ((COMM_MULTICORE_ENABLED == STD_ON) && (COMM_WAKEUPSLEEPREQUEST_ENABLED == STD_ON))*/      
/* !LINKSTO ComM979,1 */
#if (COMM_PNC_SUPPORT == STD_ON)
    if( COMM_PNC_ENABLED )
    {
      [!IF "ComMChannelId = $LeastMainFnPeriodChId"!]
       ComM_PncProcessTimers();
      [!ENDIF!]
      ComM_PncMainFunction();
    }
#endif

    ComM_ProcessTimers([!"ComMChannelId"!]U);

    if(COMM_CH_HSM_EVENT_PENDING([!"ComMChannelId"!]U))
    {
      /* ComM channels are independent of each other and do not send events to
       * each other. Hence the return value is ignored */
      (void) COMM_HSMMAININST(
        &ComM_HsmScComM, [!"ComMChannelId"!]U);
    }

#if ((COMM_MULTICORE_ENABLED == STD_ON) && (COMM_WAKEUPSLEEPREQUEST_ENABLED == STD_ON))
    if (ComM_BusSmModeToReport[[!"ComMChannelId"!]] != COMM_INVALID_COM_MODE)
    {
      if(COMM_BUSSM_REQUEST_COM_MODE((uint8)[!"ComMChannelId"!], ComM_BusSmModeToReport[[!"ComMChannelId"!]]) != SCHM_E_OK)
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
      ComM_RteNotificationDoActFkp([!"ComMChannelId"!]U);
    }
  }
}

[!ENDLOOP!][!//
#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>

[!IF "ComMGeneral/ComMPncSupport = 'true'"!]

[!LOOP "node:order(node:refs(ComMConfigSet/*[1]/ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalKind='EIRA']
        [ComMPncComSignalDirection='RX']/ComMPncComSignalRef), 'ComHandleId')"!]
[!VAR "Generated" = "'false'"!][!//
[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'true'"!][!//
  [!IF "count(text:split($UsedCores,'_')) > 1 "!][!//
    [!VAR "FoundCore" = "''"!][!//
    [!CALL "GetCore","SignalHandle"="ComHandleId","Direction"="'RX'"!][!//
    [!IF "num:i($FoundCore) != num:i($MasterCoreId)"!][!//
#define COMM_1_Slave_[!"num:i($FoundCore)"!]_START_SEC_CODE
#include <ComM_1_Slave_[!"num:i($FoundCore)"!]_MemMap.h>
/* !LINKSTO ComM975,1, ComM986,1, ComM971,1 */
FUNC(void, COMM_CODE) ComM_COMCbk_[!"node:name(.)"!](void)
{
  /* There is one bit indicating the status of each unique Com signal.
   * For easy mapping, the bits are assigned in the ascending order of
   * the signal handle ids.
   */
  uint8 ReceivedData[COMM_PN_INFO_LENGTH] = {0};
  /* !LINKSTO ComM.EB.SchM_Call_Sender_Receiver_1,1 */
  if(Com_ReceiveSignal([!"ComHandleId"!], ReceivedData) == E_OK)
  {
    /* !LINKSTO ComM.EB.SchM_Call_Sender_Receiver_3,1 */
    if (SCHM_E_OK != SchM_Send_ComM_1_Slave_[!"num:i($FoundCore)"!]_Slave_[!"num:i($FoundCore)"!]_DataSet_[!"node:name(.)"!](ReceivedData))
    {
#if (COMM_DEV_ERROR_DETECT == STD_ON)
       /* !LINKSTO ComM.EB.SchM_Call_Sender_Receiver_DET,1 */
       COMM_DET_REPORT_ERROR([!"num:i($FoundCore)"!], COMM_SID_SLAVE_DATA_SET, COMM_E_SLAVE_DATA_SET);
#endif
    }
  }
}
#define COMM_1_Slave_[!"num:i($FoundCore)"!]_STOP_SEC_CODE
#include <ComM_1_Slave_[!"num:i($FoundCore)"!]_MemMap.h>
      [!VAR "Generated" = "'true'"!][!//
    [!ENDIF!][!//
  [!ENDIF!][!//
[!ENDIF!][!//
[!IF "$Generated = 'false'"!][!//
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>
/* !LINKSTO ComM975,1, ComM986,1, ComM971,1 */
FUNC(void, COMM_CODE) ComM_COMCbk_[!"node:name(.)"!](void)
{
  /* There is one bit indicating the status of each unique Com signal.
   * For easy mapping, the bits are assigned in the ascending order of
   * the signal handle ids.
   */
  ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
  ComM_RxEiraSignalStatus = TRUE;
  ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
}
#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
[!ENDIF!][!//


[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'true'"!][!//
  [!IF "count(text:split($UsedCores,'_')) > 1 "!][!//
    [!VAR "FoundCore" = "''"!][!//
    [!CALL "GetCore","SignalHandle"="ComHandleId","Direction"="'RX'"!][!//
    [!IF "num:i($FoundCore) != num:i($MasterCoreId)"!][!//
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>
/** \brief Master core receive function for an RX signal */
FUNC(void, COMM_CODE) ComM_Master_ReceiveFunction_[!"node:name(.)"!] (void)
{
  boolean DataReceived = FALSE;
  [!CALL "GetRxSignalIndex","SignalHandleId"="ComHandleId"!][!//
  while(SCHM_E_OK == SchM_Receive_ComM_Master_DataGet_[!"node:name(.)"!](&ComM_MulticoreRxBuffer[[!"num:i($RxSignalIndex)"!]][0]))
  {
    DataReceived = TRUE;
  }
  if(DataReceived == TRUE)
  {
    ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
    ComM_RxEiraSignalStatus = TRUE;
    ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
  }
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* !LINKSTO ComM.EB.SchM_Call_Sender_Receiver_DET,1 */
    COMM_DET_REPORT_ERROR([!"num:i($FoundCore)"!], COMM_SID_MASTER_DATA_GET, COMM_E_MASTER_DATA_GET);
  }
#endif
}
#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
    [!ENDIF!][!//
  [!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//



[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncGatewayEnabled = 'true'"!]
[!LOOP "node:order(node:refs(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalKind='ERA']
        [ComMPncComSignalDirection='RX'][(node:exists(node:ref(ComMPncComSignalChannelRef)/ComMPncGatewayType)) and (node:ref(ComMPncComSignalChannelRef)/ComMPncGatewayType='COMM_GATEWAY_TYPE_ACTIVE')]/ComMPncComSignalRef), 'ComHandleId')"!]
[!VAR "Generated" = "'false'"!][!//
[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'true'"!][!//
  [!IF "count(text:split($UsedCores,'_')) > 1 "!][!//
    [!VAR "FoundCore" = "''"!][!//
    [!CALL "GetCore","SignalHandle"="ComHandleId","Direction"="'RX'"!][!//
    [!IF "num:i($FoundCore) != num:i($MasterCoreId)"!][!//
#define COMM_1_Slave_[!"num:i($FoundCore)"!]_START_SEC_CODE
#include <ComM_1_Slave_[!"num:i($FoundCore)"!]_MemMap.h>
/* !LINKSTO ComM975,1, ComM986,1, ComM971,1 */
FUNC(void, COMM_CODE) ComM_COMCbk_[!"node:name(.)"!](void)
{
  /* There is one bit indicating the status of each unique Com signal.
   * For easy mapping, the bits are assigned in the ascending order of
   * the signal handle ids.
   */
  uint8 ReceivedData[COMM_PN_INFO_LENGTH] = {0};
  /* !LINKSTO ComM.EB.SchM_Call_Sender_Receiver_1,1 */
  if(Com_ReceiveSignal([!"ComHandleId"!], ReceivedData) == E_OK)
  {
    if (SCHM_E_OK != SchM_Send_ComM_1_Slave_[!"num:i($FoundCore)"!]_Slave_[!"num:i($FoundCore)"!]_DataSet_[!"node:name(.)"!](ReceivedData))
    {
#if (COMM_DEV_ERROR_DETECT == STD_ON)
       /* !LINKSTO ComM.EB.SchM_Call_Sender_Receiver_DET,1 */
       COMM_DET_REPORT_ERROR([!"num:i($FoundCore)"!], COMM_SID_SLAVE_DATA_SET, COMM_E_SLAVE_DATA_SET);
#endif
    }
  }
}
#define COMM_1_Slave_[!"num:i($FoundCore)"!]_STOP_SEC_CODE
#include <ComM_1_Slave_[!"num:i($FoundCore)"!]_MemMap.h>
      [!VAR "Generated" = "'true'"!][!//
    [!ENDIF!][!//
  [!ENDIF!][!//
[!ENDIF!][!//
[!IF "$Generated = 'false'"!][!//
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>
/* !LINKSTO ComM975,1, ComM986,1, ComM971,1 */
FUNC(void, COMM_CODE) ComM_COMCbk_[!"node:name(.)"!](void)
{
  /* There is one bit indicating the status of each unique Com signal.
   * For easy mapping, the bits are assigned in the ascending order of
   * the signal handle ids.
   */
  ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
  ComM_RxActiveEraSignalStatus = TRUE;
  ComM_RxUnfilteredEraSignalStatus = TRUE;
  ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
}
#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
[!ENDIF!][!//


[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'true'"!][!//
  [!IF "count(text:split($UsedCores,'_')) > 1 "!][!//
    [!VAR "FoundCore" = "''"!][!//
    [!CALL "GetCore","SignalHandle"="ComHandleId","Direction"="'RX'"!][!//
    [!IF "num:i($FoundCore) != num:i($MasterCoreId)"!][!//
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>
/** \brief Master core receive function for an RX signal */
FUNC(void, COMM_CODE) ComM_Master_ReceiveFunction_[!"node:name(.)"!] (void)
{
  boolean DataReceived = FALSE;
  [!CALL "GetRxSignalIndex","SignalHandleId"="ComHandleId"!][!//
  while(SCHM_E_OK == SchM_Receive_ComM_Master_DataGet_[!"node:name(.)"!](&ComM_MulticoreRxBuffer[[!"num:i($RxSignalIndex)"!]][0]))
  {
    DataReceived = TRUE;
  }
  if(DataReceived == TRUE)
  {
    ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
    ComM_RxActiveEraSignalStatus = TRUE;
    ComM_RxUnfilteredEraSignalStatus = TRUE;
    ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
  }
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* !LINKSTO ComM.EB.SchM_Call_Sender_Receiver_DET,1 */
    COMM_DET_REPORT_ERROR([!"num:i($FoundCore)"!], COMM_SID_MASTER_DATA_GET, COMM_E_MASTER_DATA_GET);
  }
#endif
}
#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
    [!ENDIF!][!//
  [!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

[!LOOP "node:order(node:refs(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalKind='ERA']
        [ComMPncComSignalDirection='RX'][(node:exists(node:ref(ComMPncComSignalChannelRef)/ComMPncGatewayType)) and (node:ref(ComMPncComSignalChannelRef)/ComMPncGatewayType='COMM_GATEWAY_TYPE_PASSIVE')]/ComMPncComSignalRef), 'ComHandleId')"!]
[!VAR "Generated" = "'false'"!][!//
[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'true'"!][!//
  [!IF "count(text:split($UsedCores,'_')) > 1 "!][!//
    [!VAR "FoundCore" = "''"!][!//
    [!CALL "GetCore","SignalHandle"="ComHandleId","Direction"="'RX'"!][!//
    [!IF "num:i($FoundCore) != num:i($MasterCoreId)"!][!//
#define COMM_1_Slave_[!"num:i($FoundCore)"!]_START_SEC_CODE
#include <ComM_1_Slave_[!"num:i($FoundCore)"!]_MemMap.h>
/* !LINKSTO ComM975,1, ComM986,1, ComM971,1 */
FUNC(void, COMM_CODE) ComM_COMCbk_[!"node:name(.)"!](void)
{
  /* There is one bit indicating the status of each unique Com signal.
   * For easy mapping, the bits are assigned in the ascending order of
   * the signal handle ids.
   */
  uint8 ReceivedData[COMM_PN_INFO_LENGTH] = {0};
  /* !LINKSTO ComM.EB.SchM_Call_Sender_Receiver_1,1 */
  if(Com_ReceiveSignal([!"ComHandleId"!], ReceivedData) == E_OK)
  {
    if (SCHM_E_OK != SchM_Send_ComM_1_Slave_[!"num:i($FoundCore)"!]_Slave_[!"num:i($FoundCore)"!]_DataSet_[!"node:name(.)"!](ReceivedData))
    {
#if (COMM_DEV_ERROR_DETECT == STD_ON)
       /* !LINKSTO ComM.EB.SchM_Call_Sender_Receiver_DET,1 */
       COMM_DET_REPORT_ERROR([!"num:i($FoundCore)"!], COMM_SID_SLAVE_DATA_SET, COMM_E_SLAVE_DATA_SET);
#endif
    }
  }
}
#define COMM_1_Slave_[!"num:i($FoundCore)"!]_STOP_SEC_CODE
#include <ComM_1_Slave_[!"num:i($FoundCore)"!]_MemMap.h>
      [!VAR "Generated" = "'true'"!][!//
    [!ENDIF!][!//
  [!ENDIF!][!//
[!ENDIF!][!//
[!IF "$Generated = 'false'"!][!//
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>
/* !LINKSTO ComM975,1, ComM986,1, ComM971,1 */
FUNC(void, COMM_CODE) ComM_COMCbk_[!"node:name(.)"!](void)
{
  /* There is one bit indicating the status of each unique Com signal.
   * For easy mapping, the bits are assigned in the ascending order of
   * the signal handle ids.
   */
  ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
  ComM_RxUnfilteredEraSignalStatus = TRUE;
  ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
}
#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
[!ENDIF!][!//


[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'true'"!][!//
  [!IF "count(text:split($UsedCores,'_')) > 1 "!][!//
    [!VAR "FoundCore" = "''"!][!//
    [!CALL "GetCore","SignalHandle"="ComHandleId","Direction"="'RX'"!][!//
    [!IF "num:i($FoundCore) != num:i($MasterCoreId)"!][!//
#define COMM_START_SEC_CODE
#include <ComM_MemMap.h>
/** \brief Master core receive function for an RX signal */
FUNC(void, COMM_CODE) ComM_Master_ReceiveFunction_[!"node:name(.)"!] (void)
{
  boolean DataReceived = FALSE;
  [!CALL "GetRxSignalIndex","SignalHandleId"="ComHandleId"!][!//
  while(SCHM_E_OK == SchM_Receive_ComM_Master_DataGet_[!"node:name(.)"!](&ComM_MulticoreRxBuffer[[!"num:i($RxSignalIndex)"!]][0]))
  {
    DataReceived = TRUE;
  }
  if(DataReceived == TRUE)
  {
    ComM_Enter_SCHM_COMM_EXCLUSIVE_AREA_0();
    ComM_RxUnfilteredEraSignalStatus = TRUE;
    ComM_Exit_SCHM_COMM_EXCLUSIVE_AREA_0();
  }
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* !LINKSTO ComM.EB.SchM_Call_Sender_Receiver_DET,1 */
    COMM_DET_REPORT_ERROR([!"num:i($FoundCore)"!], COMM_SID_MASTER_DATA_GET, COMM_E_MASTER_DATA_GET);
  }
#endif
}
#define COMM_STOP_SEC_CODE
#include <ComM_MemMap.h>
    [!ENDIF!][!//
  [!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!]
[!ENDIF!]

[!IF "as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'true'"!][!//
  [!IF "as:modconf('ComM')[1]/ComMGeneral/ComMPncSupport = 'true'"!][!//
    [!IF "count(text:split($UsedCores,'_')) > 1 "!][!//
      [!VAR "TxIdx" = "0"!][!//
      [!LOOP "node:order(node:refs(as:modconf('ComM')[1]/ComMConfigSet/*[1]/ComMPnc/*/ComMPncComSignal/*[ComMPncComSignalDirection='TX']/ComMPncComSignalRef), 'ComHandleId')"!][!//
        [!VAR "FoundCore" = "''"!][!//
        [!CALL "GetCore","SignalHandle"="ComHandleId","Direction"="'TX'"!][!//
        [!IF "num:i($FoundCore) != num:i($MasterCoreId)"!][!//
#define COMM_1_Slave_[!"num:i($FoundCore)"!]_START_SEC_CODE
#include <ComM_1_Slave_[!"num:i($FoundCore)"!]_MemMap.h>
/** \brief Slave core receive function for a TX signal */
FUNC(void, COMM_1_Slave_1_CODE) ComM_1_Slave_[!"num:i($FoundCore)"!]_Slave_[!"num:i($FoundCore)"!]_ReceiveFunction_[!"node:name(.)"!](void)
{
   uint8 ReceivedData[COMM_PN_INFO_LENGTH] = {0};
   boolean DataReceived = FALSE;
   while(SCHM_E_OK == SchM_Receive_ComM_1_Slave_[!"num:i($FoundCore)"!]_Slave_[!"num:i($FoundCore)"!]_DataGet_[!"node:name(.)"!](ReceivedData))
   {
     DataReceived = TRUE;
   }
   if (DataReceived == TRUE)
   {
     /* !LINKSTO ComM.EB.SchM_Call_Sender_Receiver_1,1 */
     (void)Com_SendSignal(ComM_TxComSignalCfg[[!"num:i($TxIdx)"!]].ComHandleId, ReceivedData);
   }
#if (COMM_DEV_ERROR_DETECT == STD_ON)
   else
   {
     /* !LINKSTO ComM.EB.SchM_Call_Sender_Receiver_DET,1 */
     COMM_DET_REPORT_ERROR([!"num:i($FoundCore)"!], COMM_SID_SLAVE_DATA_GET, COMM_E_SLAVE_DATA_GET);
   }
#endif
}
#define COMM_1_Slave_[!"num:i($FoundCore)"!]_STOP_SEC_CODE
#include <ComM_1_Slave_[!"num:i($FoundCore)"!]_MemMap.h>
        [!ENDIF!][!//
        [!VAR "TxIdx" = "num:i($TxIdx) + 1"!][!//
      [!ENDLOOP!][!//
    [!ENDIF!][!//
  [!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!] [!/*[!IF "(count(text:split($FoundUserPlusChannePlusMasterPncPlusInhibitionOsApplications,' ')) > 1) and (as:modconf('ComM')[1]/ComMGeneral/ComMMultiCoreSupport = 'false')"!]*/!]

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
