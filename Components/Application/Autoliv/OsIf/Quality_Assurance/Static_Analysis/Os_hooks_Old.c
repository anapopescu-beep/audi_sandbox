
/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version: 
Template version: AEM_PROCESS_1.25.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2022-09
******************************************************************************/
/*
$Revision: 1.2.1.5 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/OsIf/Quality_Assurance/Static_Analysis/project.pj $
*/
/*****************************************************************************

details
   This module is intended to handle error and protection Os hooks.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Os_hooks.h"
#include "Rte_OsIf.h"
#ifndef QAC
#include "Os.h"
#include "Os_config.h"
#else
#include "Os_Stubs.h"
#include "Std_Types.h"
#include "Platform_Types.h"
#endif
#include "common.h"
#include "MIC_Public.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
#define OsIf_START_SEC_CODE_ASIL_A
#include <OsIf_MemMap.h>
/**
* \brief
*     This service is a callout called when an error hook is available.
* \inputparam
*     Name: Error;
*     Type: StatusType - uint8;
*     Description: Os error status;
*     Range: 0...KU8_MAX;
* \dynamicaspectcaller
*     Called by OS.  
* \ddesignrequirement
*     DSG_OsIf_ErrorHook
* \archrequirement
*     ARCH_SW_OsIf_ptrpAsrOsServices_ErrorHook;
*     ARCH_SW_OsIf_pclRcmServices_ErrorHook;
*     ARCH_SW_OsIf_pclResetCauseNotification_ErrorHook;
**/
void ErrorHook(StatusType Error)
{
   os_kerneldata_t * const pkstkernel_data = OS_GetKernelData();

   (void) Rte_Call_pclRcmServices_ReportOsErrorStatus((u8OSTaskIDType)pkstkernel_data->taskCurrent->taskId,(u8OSErrorType)Error);
   (void) Rte_Call_pclResetCauseNotification_NotifyResetCause(KU32_OS_EXCEPTION_NOTIFICATION);

   while (1)
   {
      /* Do nothing */
   }
}

/**
* \brief
*     This service is a callout called when an protection hook is available.
* \inputparam
*     Name: errorID;
*     Type: StatusType - uint8;
*     Description: Os error id;
*     Range:
*         OS_E_EXCEPTPROT - 14u;
*         OS_E_MEMPROT - 10u;
* \return
*     Os action do nothing
* \dynamicaspectcaller
*     Called by OS.   
* \ddesignrequirement
*     DSG_OsIf_ErrorHook
* \archrequirement
*     ARCH_SW_OsIf_ptrpAsrOsServices_ProtectionHook;
*     ARCH_SW_OsIf_ptrrMicServices;
*     ARCH_SW_OsIf_pclRcmServices_ProtectionHook;
*     ARCH_SW_OsIf_pclResetCauseNotification_ProtectionHook;
**/
ProtectionReturnType ProtectionHook(StatusType errorID)
{
   os_kerneldata_t * const pkstkernel_data = OS_GetKernelData();

   (void) Rte_Call_pclRcmServices_ReportOsErrorStatus((u8OSTaskIDType)pkstkernel_data->taskCurrent->taskId,(u8OSErrorType)errorID);

   switch(errorID)
   {
      /*OS_EC_OS_ERROR_HardFault*/
      case OS_E_EXCEPTPROT:
      {
         MIC_HardFaultException();
         break;
      }
      /*OS_EC_OS_ERROR_BusFault*/ 
      case OS_E_MEMPROT:
      {
         MIC_BusFaultException();
         break;
      }
      default:
      {
         (void) Rte_Call_pclResetCauseNotification_NotifyResetCause(KU32_OS_EXCEPTION_NOTIFICATION);
         break;
      }
   }

   return PRO_IGNORE;
}

#define OsIf_STOP_SEC_CODE_ASIL_A
#include <OsIf_MemMap.h>
/******************************************************************************
End Of File
*****************************************************************************/
