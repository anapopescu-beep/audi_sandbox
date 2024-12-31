
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
$Revision: 1.3.8.28 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/ATM/Implementation/src/project.pj $
*/
/*!****************************************************************************

Overview of the component :
   The AutoTests manager (ATM) function schedules autotests and manages
   the reported failures. An autotest is defined as a procedure that checks
   functions and returns status.
   The ATM mainly calls autotests implemented in hardware management modules.
   It is itself timed by the Scheduler or OS.
   Autotests list also includes RAM and ROM test.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_ATM.h"
#include "ATM_public.h"
#include "ATM_cfg_private.h"
#include "ATM_private.h"
#include "Nvp_Generated_NvmDefault.h"
#include "EIM.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
LOCAL void atm_SetDemEvent(const uint8 ku8AutotestID, Dem_EventStatusType u8EventStatus);
LOCAL void atm_executeAutoTest(const uint8 ku8AutotestID);
LOCAL boolean atm_isAutoTestEnabled(const uint8 ku8AutotestID);
LOCAL void atm_PlayOneShotTests(void);
LOCAL void atm_PlayCyclicTests(const ATM_stCyclicListEltType * const kpkstCyclicList);

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#define ATM_START_SEC_VAR_NO_INIT_8_ASIL_A
#include "ATM_MemMap.h"

/**
 * \brief
 *       This array contains the status of each test (RAM)
 * \initialization 
 *       KU8_ZERO
 * \range
 *       0..KU8_MAX
 */
LOCAL uint8 atm_au8AtStatuses[ATM_KU8_NB_OF_AUTOTEST];

#define ATM_STOP_SEC_VAR_NO_INIT_8_ASIL_A
#include "ATM_MemMap.h"

#define ATM_START_SEC_VAR_INIT_8_ASIL_A
#include "ATM_MemMap.h"

/**
 * \brief
 *       This variable represents the cyclic task counter.
 * \initialization 
 *       ZERO.
 * \range
 *       0..4.
 */
LOCAL uint8 atm_u8CurrentTask = KU8_ZERO;

/**
 * \brief
 *       Indexes the "castStartupList" array during the start-up test sequence
 *       over several execution of the main function. This array is browsed once,
 *       after what main function will follow the cyclic list of test.
 * \initialization 
 *       KU8_ZERO.
 * \range
 *       0..KU8_MAX.
 */
LOCAL uint8 atm_u8StartupTestIndex = KU8_ZERO;

/**
 * \brief
 *       Loop indexes the "castCyclicList" array over several execution of the main function,
 *       only after the completion of the start-up test sequence.
 * \initialization 
 *       KU8_ZERO.
 * \range
 *       0..KU8_MAX.
 */
LOCAL uint8 atm_u8CyclicTestIndex = KU8_ZERO;

#define ATM_STOP_SEC_VAR_INIT_8_ASIL_A
#include "ATM_MemMap.h"

#define ATM_START_SEC_VAR_INIT_16_ASIL_A
#include "ATM_MemMap.h"

/**
 * \brief
 *       This variable is used only during the start-up sequence
 *       to count the period between execution step of tests
 *       (if executed during several steps).
 * \initialization 
 *       KU8_ZERO.
 * \range
 *       0..KU16_MAX.
 */
LOCAL uint16 atm_u16StartupPeriodCnt = KU16_ZERO;

/**
 * \brief
 *      This variable represents the cycle decade counter.
 * \initialization 
 *      KU8_ZERO.
 * \range
 *      0..59000.
 */
LOCAL uint16 atm_u16CurrentDecade = KU16_ZERO;

#define ATM_STOP_SEC_VAR_INIT_16_ASIL_A
#include "ATM_MemMap.h"

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
#define ATM_START_SEC_CODE_ASIL_A
#include "ATM_MemMap.h"

/**
* \brief
*        Update the associated event status accordingly with Autotest result.
* \inputparam
*        Name: ku8AutotestID;
*        Type: const uint8;
*        Description: The Id of autotest we want to set the status of;;
*        Range: 0..KU8_MAX;
*        Name: Dem_EventStatusType(uint8);
*        Type: uint16;
*        Description: The status to be set to the autotest;
*        Range: 
*           DEM_DEBOUNCE_STATUS_FREEZE
*           DEM_DEBOUNCE_STATUS_RESET
*           DEM_EVENT_STATUS_PASSED
*           DEM_EVENT_STATUS_FAILED
*           DEM_EVENT_STATUS_PREPASSED
*           DEM_EVENT_STATUS_PREFAILED;
* \return
*        This function has no return.
* \dynamicaspectcaller
*        ATM module (local function).
* \dynamicaspectdescription
*        Called in atm_executeAutoTest function.
* \ddesignrequirement
*        DSG_atm_SetDemEvent.
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction
**/
LOCAL inline void atm_SetDemEvent(const uint8 ku8AutotestID, Dem_EventStatusType u8EventStatus)
{
   switch (ku8AutotestID)
   {
   case ATM_KU8_ID_TEST_ADC_OUT_OF_ORDER:
      (void)Rte_Call_pclEvtAdcOutOfOrder_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_PFLASH_MEMORY_CORRUPTION:
      (void)Rte_Call_pclEvtFlsEcc_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_EXT_WDG_OUT_OF_ORDER:
      (void)Rte_Call_pclEvtExtWdgOutOfOrder_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_NVM_NOT_PROG:
      (void)Rte_Call_pclEvtNvmNotPrg_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_NVM_MEMORY_CORRUPTION:
      (void)Rte_Call_pclEvtNvmEcc_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_RAM_MEMORY_CORRUPTION:
      (void)Rte_Call_pclEvtRamEcc_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_RESET_CAUSE:
      (void)Rte_Call_pclEvtWarmReset_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_TEST_ADC_CALIB:
      (void)Rte_Call_pclEvtAdcCalibration_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_TEST_ECU_OVER_TEMPERATURE:
      (void)Rte_Call_pclEvtEcuoverTemperature_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_POWER_SUPPLY_UV:
      (void)Rte_Call_pclEvtPowerSupllyUV_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_POWER_SUPPLY_OV:
      (void)Rte_Call_pclEvtPowerSupllyOV_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_ACTUATOR_STUCK:
      (void)Rte_Call_pclEvtActuatorState_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_MCU_SELFTEST:
      (void)Rte_Call_pclEvtMcuSelftest_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_SHORT_TO_VBAT:
      (void)Rte_Call_pclEvtActuatorShortToVBAT_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_SHORT_TO_GND:
      (void)Rte_Call_pclEvtActuatorShortToGND_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_OPEN_CIRCUIT:
      (void)Rte_Call_pclEvtActuatorOpenCircuit_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_ACC_CHECK_ALARMB:
      (void)Rte_Call_pclEvtAccStatusFailure_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_SBC_CHECK_STATUS_INFO:
      (void)Rte_Call_pclEvtSbcStatusFailiure_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_SOLENOID_OVERVOLTAGE:
      (void)Rte_Call_pclEvtSolenoidOvervoltage_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_POWER_STAGE_FAULT:
      (void)Rte_Call_pclEvtPowerStageFailiure_SetEventStatus(u8EventStatus);
      break;

   case ATM_KU8_ID_MCU_CRC_REGISTERS:
	  (void)Rte_Call_pclEvtMcuCrcRegisters_SetEventStatus(u8EventStatus);
	  break;
   default:
      /* Nothing to do */
      break;
   } /* End switch */
}

/**
* \brief
*        Function used to checks if an autotest execution is compliant
*        with the ECU mode (according to its parameters), 
*        executes it (if compliant), or ignore it (if not compliant), 
*        update the AEC status according to the test result (if executed).
* \inputparam
*        Name: ku8AutotestID;
*        Type: const uint8;
*        Description: The Id of autotest to execute;
*        Range: 0..KU8_MAX;
* \return
*        This function has no return.
* \dynamicaspectcaller
*        ATM module (local function).
* \dynamicaspectdescription
*        Called in atm_PlayOneShotTests and atm_PlayCyclicTests functions.
* \ddesignrequirement
*        DSG_atm_executeAutoTest.
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction
**/
LOCAL inline void atm_executeAutoTest(const uint8 ku8AutotestID)
{
   /* To store the auto-test results before notification and storage */
   u8TestResultType u8ReturnedAutoTestStatus = KU8_ATM_TEST_NOT_DECIDED;
   uint8 bModeStatus = B_FALSE;

   if(KU64_ZERO != ATM_kastTestConfig[ku8AutotestID].u64InhibitionMask)
   {
      Rte_Call_pclModeManagement_CheckModeStatus(ATM_kastTestConfig[ku8AutotestID].u64InhibitionMask, &bModeStatus);
   }
   else
   {
      bModeStatus = B_FALSE;
   }

   /* Status is initialized to NOT DECIDED */
   atm_au8AtStatuses[ku8AutotestID] =  KU8_ATM_TEST_NOT_DECIDED;

   if(B_FALSE == bModeStatus)
   {
      /* Execute the Auto-test */
      u8ReturnedAutoTestStatus = ATM_kastTestConfig[ku8AutotestID].pfAutotestCallbackType();

      /* Manage the test result */
      switch (u8ReturnedAutoTestStatus)
      {
         case KU8_ATM_TEST_OK:
         /* Store the result */
         atm_au8AtStatuses[ku8AutotestID] = u8ReturnedAutoTestStatus;
         /* Update the associated Event status accordingly */
         atm_SetDemEvent(ku8AutotestID, DEM_EVENT_STATUS_PREPASSED);
         break;

         case KU8_ATM_TEST_NOK:
         /* Store the result */
         atm_au8AtStatuses[ku8AutotestID] = u8ReturnedAutoTestStatus;
         /* Update the associated Event status accordingly */
         atm_SetDemEvent(ku8AutotestID, DEM_EVENT_STATUS_PREFAILED);
         break;

         case KU8_ATM_TEST_NOT_DECIDED:
         case KU8_ATM_TEST_BAD_CONDITIONS:
         /* Result not determined: Do not notify ERH */
         /* Store the result */
         atm_au8AtStatuses[ku8AutotestID] = u8ReturnedAutoTestStatus;
         break;

         default:
            /* This is an auto-test fault (returned invalid result) : do nothing */
         break;
      } /* End switch */
   }
}

/**
* \brief
*        Function used to check if an autotest is enabled.
* \inputparam
*        Name: ku8AutotestID;
*        Type: const uint8;
*        Description: The Id of autotest we want to check;
*        Range: 0..KU8_MAX;
* \return
*        If autotest is enabled, then the function return B_TRUE, else then the function return B_FALSE.
* \dynamicaspectcaller
*        ATM module (local function).
* \dynamicaspectdescription
*        Called in atm_PlayOneShotTests, atm_PlayCyclicTests functions.
* \ddesignrequirement
*        DSG_atm_isAutoTestEnabled.
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction
**/
LOCAL inline boolean atm_isAutoTestEnabled(const uint8 ku8AutotestID)
{
   /* To return the result */
   boolean bReturn = B_FALSE;

   /* Check if an auto test callback is defined */
   if (KPF_NULL != ATM_kastTestConfig[ku8AutotestID].pfAutotestCallbackType)
   {
      /* Check if the auto test is activated */
      if (KU8_TRUE == NVP_au8AutoTestsActivation[ku8AutotestID])
      {
         /* The test is enabled */
         bReturn = B_TRUE;
      }
      else
      {
         /* Auto test is considered as successful
         in order to avoid to disturb the ECU functioning */
         atm_au8AtStatuses[ku8AutotestID] = KU8_ATM_TEST_OK;

         /* Update the associated Event status accordingly */
         atm_SetDemEvent(ku8AutotestID, DEM_EVENT_STATUS_PREPASSED);

         /* The test is disabled by the configuration */
         bReturn = B_FALSE;
      }
   }
   else
   {
      /* The test is disabled since the call back function is not defined */
      bReturn = B_FALSE;
   }
   return bReturn;
}

/**
* \brief
*        Function used to run one shot tests from startup tests sequential list.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        ATM module (local function).
* \dynamicaspectdescription
*        Called in ATM_runMainFunction function.
* \ddesignrequirement
*        DSG_atm_PlayOneShotTests.
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction
**/
LOCAL inline void atm_PlayOneShotTests(void)
{
   /* ID to execute in the current state */
   uint8 u8AutotestID = ATM_kastStartupTestSequentialList[KU8_ZERO].u8TestIndex;

   /* If start-up test sequence is in progress, go over the tests which are disabled */
   boolean bAutoTestEnabledFlag;
   bAutoTestEnabledFlag = atm_isAutoTestEnabled(ATM_kastStartupTestSequentialList[atm_u8StartupTestIndex].u8TestIndex);
   while ((KU8_ATM_NB_OF_STARTUP_AUTO_TESTS > atm_u8StartupTestIndex) && (B_TRUE != bAutoTestEnabledFlag))
   {
      /* Go over this disabled test */
      atm_u8StartupTestIndex++;
      bAutoTestEnabledFlag = atm_isAutoTestEnabled(ATM_kastStartupTestSequentialList[atm_u8StartupTestIndex].u8TestIndex);
   }

   if (KU8_ATM_NB_OF_STARTUP_AUTO_TESTS > atm_u8StartupTestIndex)
   {
      /* The startup test sequence is still being in progress */
      if (KU16_ZERO == atm_u16StartupPeriodCnt)
      {
         /* Get the attributes of current startup sequence element */
         u8AutotestID = ATM_kastStartupTestSequentialList[atm_u8StartupTestIndex].u8TestIndex;

         /* Execute the auto test function */
         atm_executeAutoTest(u8AutotestID);

         /* According to the result of the auto test */
         switch (atm_au8AtStatuses[u8AutotestID])
         {
            case KU8_ATM_TEST_OK:
            /* Go to next test only when successful result has been returned */
            atm_u8StartupTestIndex++;
            /* Do not respect any delay before the first step of the next autotest */
            atm_u16StartupPeriodCnt = KU16_ZERO;
            break;

            case KU8_ATM_TEST_NOK:
               if (KU8_ATM_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_ABORT == ATM_kastStartupTestSequentialList[atm_u8StartupTestIndex].u8Type)
               {
                  /* Never retry this test after failure,
                  and definitively freeze the start-up test sequence */
                  atm_u16StartupPeriodCnt = KU16_MAX;
               }
               else if ((KU8_ATM_AUTO_TEST_CONFIG_TYPE_ONE_SHOT == ATM_kastStartupTestSequentialList[atm_u8StartupTestIndex].u8Type)
                        || (KU8_ATM_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_DECIDED == ATM_kastStartupTestSequentialList[atm_u8StartupTestIndex].u8Type))
               {
                  /* Test is played only once so Go to next test */
                  atm_u8StartupTestIndex++;
                  /* Do not respect any delay before the first step of the next autotest */
                  atm_u16StartupPeriodCnt = KU16_ZERO;
               }
               else /* ONE_SHOT_RETRY */
               {
                  /* Retry this test after failure + configured inter-step delay */
                  atm_u16StartupPeriodCnt = ATM_kastStartupTestSequentialList[(atm_u8StartupTestIndex)].u16StepPeriod;
               }
            break;

            case KU8_ATM_TEST_BAD_CONDITIONS:
               if ((KU8_ATM_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_DECIDED == ATM_kastStartupTestSequentialList[atm_u8StartupTestIndex].u8Type)
                  || (KU8_ATM_AUTO_TEST_CONFIG_TYPE_ONE_SHOT == ATM_kastStartupTestSequentialList[atm_u8StartupTestIndex].u8Type))
               {
                  /* Test is not retried any more so Go to next test */
                  atm_u8StartupTestIndex++;
                  /* Do not respect any delay before the first step of the next autotest */
                  atm_u16StartupPeriodCnt = KU16_ZERO;
               }
               else /* ONE_SHOT_RETRY or ONE_SHORT_ABORT */
               {
                  /* Retry this test after failure + configured inter-step delay */
                  atm_u16StartupPeriodCnt = ATM_kastStartupTestSequentialList[(atm_u8StartupTestIndex)].u16StepPeriod;
               }
            break;

            default:  /* not decided */
               if (KU8_ATM_AUTO_TEST_CONFIG_TYPE_ONE_SHOT == ATM_kastStartupTestSequentialList[atm_u8StartupTestIndex].u8Type)
               {
                  /* Test is played only once so Go to next test */
                  atm_u8StartupTestIndex++;
                  /* Do not respect any delay before the first step of the next autotest */
                  atm_u16StartupPeriodCnt = KU16_ZERO;
               }
               else
               {
                  /* Reload the period counter (between steps of the same test) */
                  atm_u16StartupPeriodCnt = ATM_kastStartupTestSequentialList[(atm_u8StartupTestIndex)].u16StepPeriod;
               }
            break;
         }
      }
      else if (KU16_MAX == atm_u16StartupPeriodCnt)
      {
         /* Do nothing as the start-up test sequence is
         definitively frozen since a "one shot" test result is NOK */
      }
      else
      {
         /* Count down the delay before the current test next step */
         atm_u16StartupPeriodCnt--;
      }
   }
   else
   {
      /* Do nothing as the startup test sequence is no more in progress */
   }

   /* Synchronization test: Wait for last task time slot to allow the cyclic execution of tests */
   if ((KU8_ATM_NB_OF_STARTUP_AUTO_TESTS <= atm_u8StartupTestIndex) && ((ATM_KU16_CFG_MAX_TASK - KU16_ONE) == atm_u8CurrentTask))
   {
      /* Definitively allow the cyclic execution of tests for this function next execution */
      atm_u8StartupTestIndex++;
      /* Initialize index now used to browse the running cyclic task
      (no longer used to browse the startup cyclic task) */
      atm_u8CyclicTestIndex = KU8_ZERO;
   }
   else
   {
      /* Do nothing as the startup sequence is not yet finished */
   }
}

/**
* \brief
*        Function used to run cyclic tests.
*        Running Auto test phase:
*        Execute auto test only if enabled
*        If status = OK, then go to next startup auto test at next ATM Main time slot
*        For critical auto tests:
*        If status = NOK and if ONE_SHOT_ABORT, then startup phase is frozen
*        If status = NOK and if ONE_SHOT_RETRY, then retry auto test execution
*        until OK at next ATM Main time slot
*        For NOT critical auto tests:
*        If status = NOK and if ONE_SHOT, then go to next startup auto test
*                             at next ATM Main time slot.
* \inputparam
*        Name: kpstCyclicList;
*        Type: const ATM_stCyclicListEltType *const (struct[uint16, uint8, uint8]);
*        Description: Pointer to the head of the cyclic list constant to play;
*        Range: NA.;
* \return
*        This function has no return.
* \dynamicaspectcaller
*        ATM module (local function).
* \dynamicaspectdescription
*        Called in ATM_runMainFunction function.
* \ddesignrequirement
*        DSG_atm_PlayCyclicTests.
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction
**/
LOCAL void atm_PlayCyclicTests(const ATM_stCyclicListEltType * const kpkstCyclicList)
{
   /* ID to execute in the current state */
   uint8 u8AutotestID;

   /* After the start-up sequence: run only periodic tests according their time slot allocation: */
   /* Parse all tests, and executed the enabled ones which config match with current time slot */
   while (KU16_ZERO != (kpkstCyclicList + atm_u8CyclicTestIndex)->u16Period)
   {
      /* Period and offset shall match to the current period counter */
      if ((uint16)((kpkstCyclicList + atm_u8CyclicTestIndex)->u8Offset) == (atm_u16CurrentDecade % ((kpkstCyclicList + atm_u8CyclicTestIndex)->u16Period)))
      {
         /* Get the attributes of current startup sequence element */
         u8AutotestID = (kpkstCyclicList + atm_u8CyclicTestIndex)->u8TestIndex;
         /* Test if the execution is enabled */
         if (B_TRUE == atm_isAutoTestEnabled(u8AutotestID))
         {
            atm_executeAutoTest(u8AutotestID);
         }
         else
         {
            /* Do nothing as the auto test is disabled */
         }
      }
      else
      {
         /* This time slot does not correspond to the periodicity and offset of this auto test */
         /* So it is not the moment to run this auto test => Do nothing */
      }
      atm_u8CyclicTestIndex++;
   }
   /* Prepare indexes for next main function execution */
   if (KU8_ZERO == (kpkstCyclicList + atm_u8CyclicTestIndex)->u8Offset)
   {
      /* Restart the whole list */
      atm_u8CyclicTestIndex = KU8_ZERO;
      /* Consider next decade number */
      atm_u16CurrentDecade = (atm_u16CurrentDecade + KU16_ONE) % ATM_KU16_CFG_MAX_DECADE;
   }
   else
   {
      /* Continue with the following task sub-list */
      atm_u8CyclicTestIndex++;
   }
}

/**
* \brief
*        The function ATM_Init is the memory initialization function for the ATM module.
*        The initialization value of the status of each auto test is  KU8_ATM_TEST_NOT_DECIDED.
*        The state and cycle counters of the state machine are initialized to zero.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        BswMIf module.
* \dynamicaspectdescription
*        Called in BswM_OnStartComEffective function via direct call.
* \constrains
*        ATM_Init shall be called once before execution of ATM_MainFunction.
*        ATM_MainFunction doesn't check if internal data are initialized.
* \ddesignrequirement
*        DSG_ATM_Init.
* \archrequirement
*        ARCH_SW_Atm_ptrpAtmServicesBswMIf_ATM_runInit
**/
EXPORTED void ATM_Init(void)
{
   u8AutoTestIdType u8IdxAutotest;
   
   /* Initialization of all the tests statuses */
   for (u8IdxAutotest = (u8AutoTestIdType)KU8_ZERO; u8IdxAutotest < (ATM_KU8_NB_OF_AUTOTEST); u8IdxAutotest++)
   {
      atm_au8AtStatuses [u8IdxAutotest] = KU8_ATM_TEST_NOT_DECIDED;
   }
   
   /* Used during ATM STARTUP phase */
   /* Initialization of indexes to browse lists of tests */
   atm_u8StartupTestIndex = KU8_ZERO;
   atm_u8CyclicTestIndex = KU8_ZERO;

   /* Initialization of the timer counters */
   atm_u16StartupPeriodCnt = KU16_ZERO;
   atm_u16CurrentDecade = KU16_ZERO;
   atm_u8CurrentTask = KU8_ZERO;
}

/*==============================================*/
/*               ATM Scheduler                  */
/*==============================================*/
/**
* \brief
*        The function ATM_MainFunction is the main entry point executed periodically by the Scheduler or OS.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        BswMIf module.
* \dynamicaspectdescription
*        Called in OsTask_Alv_Autotests Rte Task via direct call.
* \constrains
*        ATM_AC_AutoTestManager_ATM_runInit shall be called once before this function
* \ddesignrequirement
*        DSG_ATM_runMainFunction.
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction
*        ARCH_SW_pclInjectError
*        ARCH_SW_ATM_pclModeManagement
**/
EXPORTED void ATM_runMainFunction(void)
{
   /* Process separately the startup auto-tests sequence,
   and periodic test execution applicable only after the startup sequence */
   if (atm_u8StartupTestIndex < (KU8_ATM_NB_OF_STARTUP_AUTO_TESTS + KU8_ONE))
   {
      /* During ATM STARTUP phase:
      * Startup auto tests are sequentially executed one after one,
      * in the order defined by the startup list castStartupList,
      * until the KU8_ATM_NB_OF_STARTUP_AUTO_TESTS.
      * If a critical startup auto test is not successful,
      * the ATM STARTUP phase is suspended
      * => if ONE_SHOT_RETRY: this auto test is launched until successful result
      * => if ONE_SHOT_ABORT: this auto test is no more launched
      * Not critical (ONE_SHOT configured) auto test
      * do never freeze the ATM STARTUP phase, even if failed result. */

      /* Execution of a step from the ATM Startup sequence */
      atm_PlayOneShotTests();

      /* ATM Cyclic Tests applicable in start-up phase are run in parallel */
      atm_PlayCyclicTests(ATM_kastStartupTestCyclicList);

   }
   else
   {
      /* Run cyclic tests which are applicable only if the Startup phase is finished */
      atm_PlayCyclicTests(ATM_kastRunningCyclicList);
   }

   /* next time slot becomes current one (Loop cycle counter)
    * Note: Even if the start-up sequence do not use the 'atm_u8CurrentTask' variable, it is updated
    *       all the time from the start-up to remain synchronized with the schedule table. */
   atm_u8CurrentTask = (uint8) ((atm_u8CurrentTask + KU8_ONE) % (uint8)ATM_KU16_CFG_MAX_TASK);
#if (EIM_CONFIGURED == CAL_KU8_ERROR_INJECTION_MANAGER_ACTIVE)
   /*Manage error injection mode*/
   Rte_Call_pclInjectError_EIM_ManageAecStatus();
#endif
}

/**
* \brief
*     The function ATM_runGetTestResult allows any module to get the test result of any auto test, 
*     identified by Auto test ID to get the last test result executed by ATM independently of AEC status.
* \inputparam
*     Name: u8AutoTestId;
*     Type: u8AutoTestIdType (uint8);
*     Description: The ID of Autotest;
*     Range: 0..KU8_MAX;
* \outputparam
*     Name: u8TestResult;
*     Type: u8TestResultType * (uint8);
*     Description: The reported status of the Autotest;
*     Range: 
*        KU8_ATM_TEST_OK
*        KU8_ATM_TEST_NOK
*        KU8_ATM_TEST_NOT_DECIDED
*        KU8_ATM_TEST_NON_EXISTENT
*        KU8_ATM_TEST_BAD_CONDITIONS;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     IoHwAb module and locally.
* \dynamicaspectdescription
*     Called in IoHwAb module in functions IoHwAb_CheckEcuOverTemperatureAutotest, IoHwAb_CheckPowerSupplyOvervoltageAutotest 
*     and IoHwAb_CheckPowerSupplyUndervoltageAutotest through Rte_Call_pclAutotestServices_GetTestResult 
*     and locally in function ATM_runGetCriticalAutoTestsReachedFlag.
* \ddesignrequirement
*     DSG_ATM_runGetTestResult
* \archrequirement
*     ARCH_SW_pseAutotestServices_GetTestResult
**/
EXPORTED void ATM_runGetTestResult (u8AutoTestIdType u8AutoTestId, u8TestResultType * u8TestResult)
{
   /* Check ID exists */
   if (ATM_KU8_NB_OF_AUTOTEST <= u8AutoTestId)
   {
      /* This is a fault case : Nonexistent ID passed as parameter */
      *u8TestResult = KU8_ATM_TEST_NON_EXISTENT;
   }
   else
   {
      /* Return the last test result (OK or NOK), or NOT_DECIDED if
        no result has been returned yet by the autotest */
      *u8TestResult = atm_au8AtStatuses[u8AutoTestId];
   }
}

/**
* \brief
*     Function used to get the auto test reached flag.
* \outputparam
*     Name: pb8CriticalAutoTestsFlag;
*     Type: boolean *;
*     Description: The value of test reached flag;
*     Range: 0..1;
* \return
*     This function has no return.
* \dynamicaspectcaller
*     FSM module.
* \dynamicaspectdescription
*     Called in function fsm_UpdateModeStatus_Init through Rte_Call_pclAutotestServices_GetCriticalAutoTestsReachedFlag interface.
* \ddesignrequirement
*     DSG_ATM_runGetCriticalAutoTestsReachedFlag
* \archrequirement
*     ARCH_SW_pseAutotestServices_GetCriticalAutoTestsReachedFlag
**/
EXPORTED void ATM_runGetCriticalAutoTestsReachedFlag (uint8 * pu8CriticalAutoTestsFlag)
{
   /*Status pointer declaration*/
   u8TestResultType u8TestResult;
   /* getting the status of the last critical test*/
   ATM_runGetTestResult(ATM_kastStartupTestSequentialList[KU8_ATM_NB_OF_STARTUP_AUTO_TESTS - KU8_ONE].u8TestIndex, &u8TestResult);

   /* last critical test is it run ? */
   if ( KU8_ATM_TEST_NOT_DECIDED != u8TestResult)
   {
      /* yes : return true */
      *pu8CriticalAutoTestsFlag = KU8_TRUE;
   }
   else
   {
      /* no : return false */
      *pu8CriticalAutoTestsFlag = KU8_FALSE;
   }
}

#define ATM_STOP_SEC_CODE_ASIL_A
#include "ATM_MemMap.h"

/* end of file */
