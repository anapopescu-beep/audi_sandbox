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
/**
 *    $Revision: 1.1.3.5 $
 *    $ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/RCM/Quality_Assurance/Static_Analysis/project.pj $
 */

/**
 * \brief
 *      The RCM - is designed  to get the ECU reset reason
 */

/*****************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Common.h"
#include "Rte_RCM.h"
#include "Rcm.h"
#include "Nvp_Cfg.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *      Reset counter maximum value
 */
#define KU32_RESET_COUNTER_MAX                        ((uint32)0xFFFFFFFE)
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
#define RCM_START_SEC_CODE_ASIL_A
#include "RCM_MemMap.h"

/**
* \brief
*       This autotest aims at checking if an unexpected reset cause has been.
* \outputparam
*       Name: pu8TestResult;
*       Type: u8TestResultType* (uint8 *);
*       Description: Test result.;
*       Range: 
*           KU8_ATM_TEST_NOK;
*           KU8_ATM_TEST_OK;
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       ATM module.
* \dynamicaspectdescription
*       Warm reset autotest callback.
* \constrains
*       No constraints.
* \ddesignrequirement
*		  DSG_RCM_Autotest_RunResetCause
* \archrequirement
*       ARCH_SW_RCM_pseRunExtWDTest_RCM_Autotest_ResetCause
*       ARCH_SW_RCM_pclNvmIfServices_SetRamBlockStatus
**/
EXPORTED void RCM_Autotest_ResetCause(u8TestResultType * pu8TestResult)
{
   uint32 u32ResetCause;
   uint32 u32ResetCauseFiltered;
   uint8 u8ResultOfAutoTest;

   RCM_GetResetCause(&u32ResetCause);

   u32ResetCauseFiltered = u32ResetCause & (KU32_MCU_LOW_VOLTAGE_DETECT_RESET_MASK \
       | KU32_MCU_LOSS_OF_CLOCK_RESET_MASK \
       | KU32_MCU_LOSS_OF_LOCK_RESET_MASK \
       | KU32_MCU_WATCHDOG_RESET_MASK \
       | KU32_MCU_JTAG_GENERATED_RESET_MASK \
       | KU32_MCU_CORE_LOCKUP_RESET_MASK \
       | KU32_MCU_SOFTWARE_RESET_MASK \
       | KU32_MCU_MDM_AP_SYSTEM_RESET_REQUESTED_MASK \
       | KU32_MCU_STOP_ACKNOWLEDGE_ERROR_RESET_MASK \
       | KU32_APP_INVALID_INTERRUPT_NOTIFICACTION_MASK \
       | KU32_APP_OS_EXCEPTION_NOTIFICATION_MASK \
       | KU32_APP_BATTERY_LOSS_NOTIFICATION_MASK \
       | KU32_APP_ECC_RAM_NOTIFICATION_MASK \
       | KU32_APP_ECC_PFLASH_NOTIFICATION_MASK \
       | KU32_APP_ECC_E2P_NOTIFICATION_MASK \
       | KU32_APP_ECC_UNIDENTIFIED_NOTIFICATION_MASK \
       | KU32_APP_MACHINE_EXCEPTION_NOTIFICATION_MASK \
       | KU32_APP_STACK_OVERFLOW_NOTIFICATION_MASK \
       | KU32_APP_RAM_DATA_CORRUPTED_NOTIFICATION_MASK);

   if ((KU32_ZERO != u32ResetCauseFiltered) || 
      (KU32_ZERO == u32ResetCause) || 
      ((KU32_ZERO == u32ResetCauseFiltered) && (KU32_MCU_EXTERNAL_RESET_PIN_MASK == (u32ResetCause & KU32_MCU_EXTERNAL_RESET_PIN_MASK))&&
      (KU32_ZERO == (u32ResetCause & (KU32_APP_BATTERY_LOSS_NOTIFICATION_MASK | KU32_APP_SW_WDG_TEST_NOTIFICATION_MASK | KU32_APP_BLTD_RESET_NOTIFICATION_MASK |
      KU32_APP_DIAG_HARD_RESET_NOTIFICATION_MASK | KU32_APP_DIAG_SOFT_RESET_NOTIFICATION_MASK)))))
   {
      u8ResultOfAutoTest = KU8_ATM_TEST_NOK;

      /* warm reset detected */
      /* update cause */
      NVP_u32WarmResetCause   = u32ResetCauseFiltered | (u32ResetCause & KU32_MCU_EXTERNAL_RESET_PIN_MASK);
      /* update counter */
      /* 0xFFFFFFFE reserved for maximum value 0xFFFFFFFF for empty record */
      /* replace with single macro */
      if (NVP_u32WarmResetCounter < KU32_RESET_COUNTER_MAX)
      {
         NVP_u32WarmResetCounter++;
      }
      /* initial cnt val FFFFFFFFh, set to 1 */
      else if(KU32_MAX == NVP_u32WarmResetCounter)
      {
         NVP_u32WarmResetCounter = KU32_ONE;
      }
      else
      {
         /* nothing to do */
      }

      /* Notification to record the WarmReset Block during the shutdown */
      (void)Rte_Call_pclNvmIfServices_SetRamBlockStatus(NvM_WARM_RESET_COUNTERS, TRUE);
   }
   else
   {
      u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }

   /* Return the auto test status */
   *pu8TestResult = u8ResultOfAutoTest;
}
#define RCM_STOP_SEC_CODE_ASIL_A
#include "RCM_MemMap.h"

/*************************************************************************
Evolution of the component

Created by : P-O.Pilot

$Log: RCM_autotests_Old.c  $
Revision 1.1.3.5 2023/07/13 10:25:39CEST Razvan Badiu (razvan.badiu) 
update qac
Revision 1.1.5.12 2023/07/13 11:23:01EEST Razvan Badiu (razvan.badiu) 
review fixes
Revision 1.1.5.11 2023/06/20 23:29:17EEST Razvan Badiu (razvan.badiu) 
update traceability
Revision 1.1.5.10 2023/06/12 09:39:09EEST Mihai Motoc (mihai.motoc) 
Doxygen comments updates
Revision 1.1.5.9 2023/06/08 10:02:30EEST Mihai Motoc (mihai.motoc) 
Doxygen comments updates
Revision 1.1.5.8 2023/05/02 18:03:09EEST Razvan Badiu (razvan.badiu) 
fix reset counter
Revision 1.1.5.7 2023/04/21 00:44:47EEST Razvan Badiu (razvan.badiu) 
add wdg autotest
Revision 1.1.5.6 2023/03/23 01:06:34EET Razvan Badiu (razvan.badiu) 
RCM rework first draft
Revision 1.1.5.4 2023/02/28 17:30:09EET Septimiu Vintila (septimiu.vintila) 
Memory sections changed to FuSa memory sections.
Revision 1.1.5.3 2023/02/23 17:11:11EET Razvan Badiu (razvan.badiu) 
add traceabilty
Revision 1.1.5.2 2022/11/11 14:24:26EET Andrei Anca (andrei.anca) 

*************************************************************************/

/* end of file */
