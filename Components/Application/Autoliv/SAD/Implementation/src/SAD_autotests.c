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
$Revision: 1.55 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/SAD/Implementation/src/project.pj $
*/
/*!****************************************************************************

details
   The purpose of this module is to handle the auto-tests related to the
   solenoids.
   ○ Actuator stuck;
   ○ Open circuit;
   ○ Short circuit to ground;
   ○ Short circuit to supply voltage;

******************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "common.h"
#include "SAD.h"
#include "Rte_Sad.h"
#include "Rte_Dem_Type.h"
#include "Math.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/

/**
 *\brief
 *      None of the solenoids are stuck.
 */
#define KU8_SAD_NO_STUCK_SOLENOID                     ((uint8) 0)

/**
 *\brief
 *      Number of entries in interpolation table for voltage threshold
 *
 */
#define KU8_SAD_NB_OF_INTERPOLATION_POINTS            ((uint8) 8)

/**
 *\brief
 *      Coefficient used in division to convert units from micro-volts to milli-volts.
 *
 */
#define KU32_SAD_CONVERSION_UNIT                      ((uint32)1000)

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
LOCAL u8TestResultType sad_ExecuteOpenCircuitCheck(const uint8 ku8SolenoidId);
LOCAL u8TestResultType sad_ExecuteShortToGNDCheck(const uint8 ku8SolenoidId);
LOCAL u8TestResultType sad_ExecuteShortToVBATCheck(const uint8 ku8SolenoidId);
LOCAL u8TestResultType sad_ExecuteOvervoltageCheck(const uint8 ku8SolenoidId);
LOCAL u8TestResultType sad_ExecutePinStateCheck(const uint8 ku8SolenoidId);
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#define SAD_START_SEC_VAR_INIT_8_ASIL_A
#include "SAD_MemMap.h"

/**
 * \brief
 *    The variable is used to store in each bit the stuck status flag of each
 *    solenoid.
 *
 * \initialization
 *       KU8_SAD_NO_STUCK_SOLENOID (uint8 0)
 *
 * \range
 *       0...KU8_MAX.
 *
 */
LOCAL uint8 sad_u8StuckActuatorsStatus = KU8_SAD_NO_STUCK_SOLENOID;

/**
 * \brief
 *    This array will hold errors of Open Circuit per every solenoid.
 *
 * \initialization
 *       KU8_SOLENOID_ELECTRICAL_AT_PASSED
 *
 * \range
 *       KU8_SOLENOID_ELECTRICAL_AT_PASSED
 *       KU8_SOLENOID_ELECTRICAL_AT_FAILED;
 *
 */
LOCAL uint8 sad_au8SolErrorPresentOpenCircuit[KU8_MAX_SOLENOID_NB] = {
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED
};

/**
 * \brief
 *    This array will hold errors of Short To GND per every solenoid.
 *
 * \initialization
 *       KU8_SOLENOID_ELECTRICAL_AT_PASSED
 *
 * \range
 *       KU8_SOLENOID_ELECTRICAL_AT_PASSED
 *       KU8_SOLENOID_ELECTRICAL_AT_FAILED;
 *
 */
LOCAL uint8 sad_au8SolErrorPresentShortToGND[KU8_MAX_SOLENOID_NB] = {
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED
};

/**
 * \brief
 *    This array will hold errors of Short To VBAT per every solenoid.
 *
 * \initialization
 *       KU8_SOLENOID_ELECTRICAL_AT_PASSED
 *
 * \range
 *       KU8_SOLENOID_ELECTRICAL_AT_PASSED
 *       KU8_SOLENOID_ELECTRICAL_AT_FAILED;
 *
 */
LOCAL uint8 sad_au8SolErrorPresentShortToVBAT[KU8_MAX_SOLENOID_NB] = {
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED
};

/**
 * \brief
 *    This array will hold errors of overvoltage per every solenoid.
 *
 * \initialization
 *       KU8_SOLENOID_ELECTRICAL_AT_PASSED
 *
 * \range
 *       KU8_SOLENOID_ELECTRICAL_AT_PASSED
 *       KU8_SOLENOID_ELECTRICAL_AT_FAILED;
 *
 */
LOCAL uint8 sad_au8SolErrorPresentOvervoltage[KU8_MAX_SOLENOID_NB] = {
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED
};

/**
 * \brief
 *    This array will hold errors of en_cs pin check per every solenoid.
 *
 * \initialization
 *       KU8_SOLENOID_ELECTRICAL_AT_PASSED
 *
 * \range
 *       KU8_SOLENOID_ELECTRICAL_AT_PASSED
 *       KU8_SOLENOID_ELECTRICAL_AT_FAILED;
 *
 */
LOCAL uint8 sad_au8SolErrorPresentEnCSPin[KU8_MAX_SOLENOID_NB] = {
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED,
      KU8_SOLENOID_ELECTRICAL_AT_PASSED
};

#define SAD_STOP_SEC_VAR_INIT_8_ASIL_A
#include "SAD_MemMap.h"

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
#define SAD_START_SEC_CONST_UNSPECIFIED_ASIL_A
#include "SAD_MemMap.h"

/**
 * \brief
 *       This array holds the buckle latch confirmation mask of each solenoid based on what
 *       flag to check.
 * \initialization
 *       {KU64_SOLENOID_X_BUCKLE_LATCHED}
 *       where X - the solenoid number
 *
 * \range
 *       0..KU64_MAX.
 */
LOCAL const uint64 sad_kau64SolenoidBuckleStatusMask[KU8_MAX_SOLENOID_NB] =
{
   /* Solenoid 1 */ (KU64_SOLENOID_1_BUCKLE_LATCHED),
   /* Solenoid 2 */ (KU64_SOLENOID_2_BUCKLE_LATCHED),
   /* Solenoid 3 */ (KU64_SOLENOID_3_BUCKLE_LATCHED),
   /* Solenoid 4 */ (KU64_SOLENOID_4_BUCKLE_LATCHED),
   /* Solenoid 5 */ (KU64_SOLENOID_5_BUCKLE_LATCHED),
   /* Solenoid 6 */ (KU64_SOLENOID_6_BUCKLE_LATCHED)
};

/**
 *\brief
 *      Interpolation table for solenoid resistance.
 *      USED IN CALCULATION OF SOLENOID VOLTAGE THRSH BASED ON A SPECIFIC RESISTANCE.
 *      INPUT: RESISTANCE, OUTPUT: VOLTAGE
 */
LOCAL const stInterpolationParam_Type sad_kstLookUpTableREStoOVDiagThrsh = {
   (const uint8*)(&NVP_as16SolenoidRes[KU8_ZERO]), /* x_table: vector with axis values */
   (const uint8*)(&NVP_au16SolenoidDiagOvervoltageThrs[KU8_ZERO]), /* y_table: vector with axis values */
   KU8_SAD_NB_OF_INTERPOLATION_POINTS,
   KU8_X16_LIndian | KU8_Y16_LIndian,
   KU8_IN_RANGE_LINEAR_INTER | KU8_BELOW_RANGE_UPPER_INTER | KU8_OVER_RANGE_LOWER_INTER
};

/**
 *\brief
 *      Interpolation table for solenoid resistance.
 *      USED IN CALCULATION OF SOLENOID VOLTAGE THRSH BASED ON A SPECIFIC RESISTANCE.
 *      INPUT: RESISTANCE, OUTPUT: VOLTAGE
 */
LOCAL const stInterpolationParam_Type sad_kstLookUpTableREStoOVUnlockThrsh = {
   (const uint8*)(&NVP_as16SolenoidRes[KU8_ZERO]), /* x_table: vector with axis values */
   (const uint8*)(&NVP_au16SolenoidUnlockOvervoltageThrs[KU8_ZERO]), /* y_table: vector with axis values */
   KU8_SAD_NB_OF_INTERPOLATION_POINTS,
   KU8_X16_LIndian | KU8_Y16_LIndian,
   KU8_IN_RANGE_LINEAR_INTER | KU8_BELOW_RANGE_UPPER_INTER | KU8_OVER_RANGE_LOWER_INTER
};

#define SAD_STOP_SEC_CONST_UNSPECIFIED_ASIL_A
#include "SAD_MemMap.h"

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
#define SAD_START_SEC_CODE_ASIL_A
#include "SAD_MemMap.h"

/**
* \brief
*        Auto-test to check an open circuit fault on the required solenoid.
* \inputparam
*        Name: ku8SolenoidId;
*        Type: const uint8;
*        Description: The ID of the solenoid;
*        Range: KU8_SOLENOID_1..KU8_SOLENOID_6;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        The result of auto-test.
* \dynamicaspectcaller
*        SAD_CheckSolenoidOpenCircuitAutotest
* \dynamicaspectdescription
*        API called by SAD_CheckSolenoidOpenCircuitAutotest.
* \constraints
*        It is called just for enabled solenoids and just if the ADC auto-test
*        is OK.
* \ddesignrequirement
*        DSG_sad_ExecuteOpenCircuitCheck
* \archrequirement
*        ARCH_SW_SAD_pclAutotestServices
*        ARCH_SW_SAD_prrSolenoidProfile
*        ARCH_SW_SAD_pclConvAdcService
**/
LOCAL u8TestResultType sad_ExecuteOpenCircuitCheck(const uint8 ku8SolenoidId)
{
   uint16 u16VBoostDiag = KU16_ZERO;
   uint16 u16LowVoltageThresold = KU16_ZERO;
   uint16 u16SolenoidMeasuredVoltage = KU16_ZERO;
   uint16 u16VBATMeasuredVoltage = KU16_ZERO;

   /* Auto-test result */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   uint8 u8SolenoidUsedBitMask = KU8_ZERO;
   uint8 au8SelectedProfile[KU8_MAX_SOLENOID_NB];

   (void)Rte_Read_prrSolenoidProfile_au8SelectedProfile((uint8 *)au8SelectedProfile);

   u8SolenoidUsedBitMask |= (uint8)(KU8_ONE << ku8SolenoidId);

   /* Check if a profile is currently running but not reached infinite step*/
   if (((KU8_PROFILE_UNLOCK == au8SelectedProfile[ku8SolenoidId]) || (KU8_PROFILE_BACKUP == au8SelectedProfile[ku8SolenoidId])) &&
       (KU8_ZERO == (SAD_u8SolenoidInfiniteStepReached & u8SolenoidUsedBitMask)) &&
       (KU8_FIVE != SAD_au8StepToExecute[ku8SolenoidId]) &&
       (KU8_SAD_UNDEFINED_STEP != SAD_au8StepToExecute[ku8SolenoidId]))
   {
      /* Measurements compared to unlock threshold */
      /* Measure voltage across solenoid */
      Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_MAG_V_1 + ku8SolenoidId, &u16SolenoidMeasuredVoltage);
      Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_BOOST_DIAG, &u16VBoostDiag);

      u16LowVoltageThresold  = u16VBoostDiag - (uint16)( ((uint32)u16VBoostDiag * (uint32)NVP_u8OpenCircuitUnlockWithBoostProfThrs ) / (uint32)KU8_ONE_HUNDRED );

      /* If voltage is between the specific thresholds */
      if (u16SolenoidMeasuredVoltage > u16LowVoltageThresold)
      {
         /* Solenoid is in open circuit */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         sad_au8SolErrorPresentOpenCircuit[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_FAILED;
      }
      else
      {
         u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         sad_au8SolErrorPresentOpenCircuit[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_PASSED;
      }
   }
   /* Check if a profile is not currently running */
   else if (((KU8_PROFILE_UNLOCK == au8SelectedProfile[ku8SolenoidId]) || (KU8_PROFILE_BACKUP == au8SelectedProfile[ku8SolenoidId])) && (KU8_ZERO != (SAD_u8SolenoidInfiniteStepReached & u8SolenoidUsedBitMask)))
   {
      /* Measure voltage across solenoid */
      Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_MAG_V_1 + ku8SolenoidId, &u16SolenoidMeasuredVoltage);
      Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_V_BATT, &u16VBATMeasuredVoltage);

      u16LowVoltageThresold  = u16VBATMeasuredVoltage - (uint16)(((uint32)u16VBATMeasuredVoltage * (uint32)NVP_u8OpenCircuitUnlockWithoutBoostProfThrs) / (uint32)KU8_ONE_HUNDRED );

      /* If voltage is between the specific thresholds */
      if (u16SolenoidMeasuredVoltage > u16LowVoltageThresold)
      {
         /* Solenoid is in open circuit */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         sad_au8SolErrorPresentOpenCircuit[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_FAILED;
      }
      else
      {
         u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         sad_au8SolErrorPresentOpenCircuit[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_PASSED;
      }
   }
   /* If the profile is DIAGNOSTIC */
   else if ((KU8_PROFILE_DIAGNOSTIC == au8SelectedProfile[ku8SolenoidId]) && (KU8_SAD_UNDEFINED_STEP != SAD_au8StepToExecute[ku8SolenoidId]))
   {
      /* Measure voltage across solenoid */
      Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_MAG_V_1 + ku8SolenoidId, &u16SolenoidMeasuredVoltage);
      Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_BOOST_DIAG, &u16VBoostDiag);

      u16LowVoltageThresold  = u16VBoostDiag - (uint16)( ((uint32)u16VBoostDiag * (uint32)NVP_u8OpenCircuitDiagProfThrs ) / (uint32)KU8_ONE_HUNDRED );

      /* If voltage is between the specific thresholds */
      if ((u16SolenoidMeasuredVoltage > u16LowVoltageThresold))
      {
         /* Solenoid is in open circuit */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         sad_au8SolErrorPresentOpenCircuit[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_FAILED;
      }
      else
      {
         u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         sad_au8SolErrorPresentOpenCircuit[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_PASSED;
      }
   }
   else
   {
      /* Read last state of auto-test */
      Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_OPEN_CIRCUIT, &u8ResultOfAutoTest);
   }

   /* Return the auto test status */
   return u8ResultOfAutoTest;
}

/**
* \brief
*        Auto-test to check a short-to-ground fault on the required solenoid.
* \inputparam
*        Name: ku8SolenoidId;
*        Type: const uint8;
*        Description: The ID of the solenoid;
*        Range: KU8_SOLENOID_1..KU8_SOLENOID_6;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        The result of auto-test.
* \dynamicaspectcaller
*        SAD_CheckSolenoidShortToGNDAutotest
* \dynamicaspectdescription
*        API called by SAD_CheckSolenoidShortToGNDAutotest.
* \constraints
*        It is called just for enabled solenoids and just if the ADC auto-test
*        is OK.
* \ddesignrequirement
*        DSG_sad_ExecuteShortToGNDCheck
* \archrequirement
*        ARCH_SW_SAD_pclAutotestServices
*        ARCH_SW_SAD_prrSolenoidProfile
*        ARCH_SW_SAD_pclConvAdcService
**/
LOCAL u8TestResultType sad_ExecuteShortToGNDCheck(const uint8 ku8SolenoidId)
{
   /* to get Solenoid measured voltage */
   uint16 u16SolenoidMeasuredVoltage = KU16_ZERO;

   /* Auto-test result */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   uint8 au8SelectedProfile[KU8_MAX_SOLENOID_NB];

   (void)Rte_Read_prrSolenoidProfile_au8SelectedProfile((uint8 *)au8SelectedProfile);

   /* Check if a profile is not currently running */
   if (((KU8_PROFILE_UNLOCK == au8SelectedProfile[ku8SolenoidId]) || (KU8_PROFILE_BACKUP == au8SelectedProfile[ku8SolenoidId])) &&
       (KU8_FIVE != SAD_au8StepToExecute[ku8SolenoidId]) && (KU8_SAD_UNDEFINED_STEP != SAD_au8StepToExecute[ku8SolenoidId]))
   {
      /* Measurements compared to unlock threshold */
      /* Measure voltage across solenoid */
      Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_MAG_V_1 + ku8SolenoidId, &u16SolenoidMeasuredVoltage);

      /* The voltage is different than a threshold */
      if (u16SolenoidMeasuredVoltage >= NVP_u16ShortToGNDUnlockProfThrs)
      {
         u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         sad_au8SolErrorPresentShortToGND[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_PASSED;
      }
      else
      {
         /* Solenoid is in short to GND */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         sad_au8SolErrorPresentShortToGND[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_FAILED;
      }
   }
   /* If the profile is DIAGNOSTIC */
   else if ((KU8_PROFILE_DIAGNOSTIC == au8SelectedProfile[ku8SolenoidId]) &&
            (KU8_FIVE != SAD_au8StepToExecute[ku8SolenoidId]) && (KU8_SAD_UNDEFINED_STEP != SAD_au8StepToExecute[ku8SolenoidId]))
   {
      /* Measure voltage across solenoid */
      Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_MAG_V_1 + ku8SolenoidId, &u16SolenoidMeasuredVoltage);

      /* If voltage is greater than a specific threshold */
      if (u16SolenoidMeasuredVoltage >= NVP_u16ShortToGNDDiagProfThrs)
      {
         u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         sad_au8SolErrorPresentShortToGND[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_PASSED;
      }
      else
      {
         /* Solenoid is in short to GND */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         sad_au8SolErrorPresentShortToGND[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_FAILED;
      }
   }
   else
   {
      /* Read last state of auto-test */
      Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_SHORT_TO_GND, &u8ResultOfAutoTest);
   }

   /* Return the auto test status */
   return u8ResultOfAutoTest;
}

/**
* \brief
*        Auto-test to check a short to VBAT fault on the required solenoid.
* \inputparam
*        Name: ku8SolenoidId;
*        Type: const uint8;
*        Description: The ID of the solenoid;
*        Range: KU8_SOLENOID_1..KU8_SOLENOID_6;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        The result of auto-test.
* \dynamicaspectcaller
*        SAD_CheckSolenoidShortToVBATAutotest
* \dynamicaspectdescription
*        API called by SAD_CheckSolenoidShortToVBATAutotest.
* \constraints
*        It is called just for enabled solenoids and just if the ADC auto-test
*        is OK.
* \ddesignrequirement
*        DSG_sad_ExecuteShortToVBATCheck
* \archrequirement
*        ARCH_SW_SAD_pclAutotestServices
*        ARCH_SW_SAD_prrSolenoidProfile
*        ARCH_SW_SAD_pclConvAdcService
**/
LOCAL u8TestResultType sad_ExecuteShortToVBATCheck(const uint8 ku8SolenoidId)
{
   /* Variables used to compute voltage thresholds */
   uint16 u16LowVoltageThresold = KU16_ZERO;
   uint16 u16HighVoltageThresold = KU16_ZERO;

   /* to get Solenoid measured voltage */
   uint16 u16SolenoidMeasuredVoltage = KU16_ZERO;

   /* to get VBAT measured voltage */
   uint16 u16VBATMeasuredVoltage = KU16_ZERO;

   /* Auto-test result */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   uint8 au8SelectedProfile[KU8_MAX_SOLENOID_NB];

   (void)Rte_Read_prrSolenoidProfile_au8SelectedProfile((uint8 *)au8SelectedProfile);

   /* Check if no profile is running */
   if (KU8_PROFILE_NONE == au8SelectedProfile[ku8SolenoidId])
   {
      if((KU8_SOLENOID_ELECTRICAL_AT_PASSED == sad_au8SolErrorPresentOpenCircuit[ku8SolenoidId]) && (KU8_SOLENOID_ELECTRICAL_AT_PASSED == sad_au8SolErrorPresentOvervoltage[ku8SolenoidId]))
      {
         /* Measurements compared to unlock threshold */
         /* Measure voltage across VBAT */
         Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_V_BATT, &u16VBATMeasuredVoltage);

         /* Compute plateau for checking voltage */
         u16LowVoltageThresold  = u16VBATMeasuredVoltage - (uint16)( ((uint32)u16VBATMeasuredVoltage * (uint32)NVP_u8ShortToVBATLockProfThrs ) / (uint32)KU8_ONE_HUNDRED );
         u16HighVoltageThresold = u16VBATMeasuredVoltage + (uint16)( ((uint32)u16VBATMeasuredVoltage * (uint32)NVP_u8ShortToVBATLockProfThrs ) / (uint32)KU8_ONE_HUNDRED );

         /* Measure voltage across solenoid */
         Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_MAG_V_1 + ku8SolenoidId, &u16SolenoidMeasuredVoltage);

         /* If voltage is between the specific thresholds */
         if ((u16SolenoidMeasuredVoltage > u16LowVoltageThresold ) && (u16SolenoidMeasuredVoltage < u16HighVoltageThresold))
         {
            u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
            sad_au8SolErrorPresentShortToVBAT[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_FAILED;
         }
         else
         {
            u8ResultOfAutoTest = KU8_ATM_TEST_OK;
            sad_au8SolErrorPresentShortToVBAT[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_PASSED;
         }
      }
      else
      {
         Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_SHORT_TO_VBAT, &u8ResultOfAutoTest);
      }
   }
   else
   {
      Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_SHORT_TO_VBAT, &u8ResultOfAutoTest);
   }

   /* Return the auto test status */
   return u8ResultOfAutoTest;
}

/**
* \brief
*        Auto-test to check an pin state fault on the required solenoid.
* \inputparam
*        Name: ku8SolenoidId;
*        Type: const uint8;
*        Description: The ID of the solenoid;
*        Range: KU8_SOLENOID_1..KU8_SOLENOID_6;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        The result of auto-test.
* \dynamicaspectcaller
*        SAD_CheckPowerStage
* \dynamicaspectdescription
*        API called by SAD_CheckPowerStage.
* \constraints
*        It is called just for enabled solenoids and just if the ADC auto-test
*        is OK.
* \ddesignrequirement
*        DSG_sad_ExecutePinStateCheck
* \archrequirement
*        ARCH_SW_SAD_prrSolenoidProfile
*        ARCH_SW_SAD_pclAutotestServices
*        ARCH_SW_SAD_pclDioIfServices
**/

LOCAL u8TestResultType sad_ExecutePinStateCheck(const uint8 ku8SolenoidId)
{
   /* Auto-test result */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   uint8 au8SelectedProfile[KU8_MAX_SOLENOID_NB];
   uint8 au8SolenoidStates[KU8_MAX_SOLENOID_NB];
   uint8 u8SolenoidLockProfileMask = KU8_ZERO;
   uint8 u8SolenoidDisableMask = KU8_ZERO;
   uint8 u8Idx = KU8_ZERO;
   uint8 u8OnOffPinState = STD_LOW;
   uint8 u8BoostEnPinState = STD_LOW;
   uint8 u8EnCSPinState = STD_LOW;

   (void)Rte_Read_prrSolenoidProfile_au8SelectedProfile((uint8 *)au8SelectedProfile);
   (void)Rte_Read_SAD_prrSolenoidState_au8SolenoidState((uint8 *)au8SolenoidStates);

   for(u8Idx = KU8_ZERO; u8Idx < KU8_MAX_SOLENOID_NB; u8Idx++)
   {
      if((KU8_PROFILE_NONE == au8SelectedProfile[u8Idx]) && (KB_TRUE == KB_SAD_SOLENOID_CONFIGURED(u8Idx)))
      {
         u8SolenoidLockProfileMask |=  (uint8)(KU8_ONE << u8Idx);
      }
      if((KU8_DISABLED_STATE == au8SolenoidStates[u8Idx]) && (KB_TRUE == KB_SAD_SOLENOID_CONFIGURED(u8Idx)))
      {
         u8SolenoidDisableMask |=  (uint8)(KU8_ONE << u8Idx);
      }
   }
   /* Check if a profile ( unlock or backup )  is currently running */
   if (((KU8_PROFILE_UNLOCK == au8SelectedProfile[ku8SolenoidId]) || (KU8_PROFILE_BACKUP == au8SelectedProfile[ku8SolenoidId])) &&
       ((SAD_u8SolenoidInfiniteStepReached | u8SolenoidDisableMask) == SAD_u8SolenoidUsedBitMask))
   {
      /* Read all pin states */
      (void)Rte_Call_pclDioIfServices_ReadChannel(DIOIF_CH_ON_OFF_POWER, &u8OnOffPinState);
      (void)Rte_Call_pclDioIfServices_ReadChannel(DIOIF_CH_EN_BOOST, &u8BoostEnPinState);
      (void)Rte_Call_pclDioIfServices_ReadChannel(DIOIF_CH_EN_CS_1 + ku8SolenoidId, &u8EnCSPinState);

      if ((STD_HIGH == u8OnOffPinState) && (STD_LOW == u8BoostEnPinState) && (STD_LOW == u8EnCSPinState))
      {
         u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         sad_au8SolErrorPresentEnCSPin[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_PASSED;
      }
      else
      {
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         sad_au8SolErrorPresentEnCSPin[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_FAILED;
      }
   }

   /* If the profile is DIAGNOSTIC */
   else if ((KU8_PROFILE_DIAGNOSTIC == au8SelectedProfile[ku8SolenoidId]) && (KU8_SAD_UNDEFINED_STEP != SAD_au8StepToExecute[ku8SolenoidId]))
   {

      /* Read all pin states */
      (void)Rte_Call_pclDioIfServices_ReadChannel(DIOIF_CH_ON_OFF_POWER, &u8OnOffPinState);
      (void)Rte_Call_pclDioIfServices_ReadChannel(DIOIF_CH_EN_BOOST, &u8BoostEnPinState);
      (void)Rte_Call_pclDioIfServices_ReadChannel(DIOIF_CH_EN_CS_1 + ku8SolenoidId, &u8EnCSPinState);

      if ((STD_HIGH == u8OnOffPinState) && (STD_HIGH == u8BoostEnPinState) && (STD_LOW == u8EnCSPinState))
      {
         u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         sad_au8SolErrorPresentEnCSPin[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_PASSED;
      }
      else
      {
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         sad_au8SolErrorPresentEnCSPin[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_FAILED;
      }
   }

   /* Profile is lock for all enabled solenoids */
   else if (u8SolenoidLockProfileMask == SAD_u8SolenoidUsedBitMask)
   {

      /* Read all pin states */
      (void)Rte_Call_pclDioIfServices_ReadChannel(DIOIF_CH_ON_OFF_POWER, &u8OnOffPinState);
      (void)Rte_Call_pclDioIfServices_ReadChannel(DIOIF_CH_EN_BOOST, &u8BoostEnPinState);
      (void)Rte_Call_pclDioIfServices_ReadChannel(DIOIF_CH_EN_CS_1 + ku8SolenoidId, &u8EnCSPinState);

      if ((STD_LOW == u8OnOffPinState) && (STD_HIGH == u8BoostEnPinState) && (STD_HIGH == u8EnCSPinState))
      {
         u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         sad_au8SolErrorPresentEnCSPin[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_PASSED;
      }
      else
      {
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         sad_au8SolErrorPresentEnCSPin[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_FAILED;
      }
   }
   else
   {
      Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_POWER_STAGE_FAULT, &u8ResultOfAutoTest);
   }

   /* Return the auto test status */
   return u8ResultOfAutoTest;
}

/**
* \brief
*        Auto-test to check an overvoltage fault on the required solenoid.
* \inputparam
*        Name: ku8SolenoidId;
*        Type: const uint8;
*        Description: The ID of the solenoid;
*        Range: KU8_SOLENOID_1..KU8_SOLENOID_6;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        The result of auto-test.
* \dynamicaspectcaller
*        SAD_CheckSolenoidOvervoltage
* \dynamicaspectdescription
*        API called by SAD_CheckSolenoidOvervoltage.
* \constraints
*        It is called just for enabled solenoids and just if the ADC auto-test
*        is OK.
* \ddesignrequirement
*        DSG_sad_ExecuteOvervoltageCheck
* \archrequirement
*        ARCH_SW_SAD_pclAutotestServices
*        ARCH_SW_SAD_prrSolenoidProfile
*        ARCH_SW_SAD_pclConvAdcService
**/

LOCAL u8TestResultType sad_ExecuteOvervoltageCheck(const uint8 ku8SolenoidId)
{

   uint32 u32SolenoidResistance = KU32_ZERO;

   /* to get Solenoid measured voltage */
   uint16 u16SolenoidMeasuredVoltage = KU16_ZERO;
   uint16 u16SolenoidMeasuredCurrent = KU16_ZERO;

   uint16 u16SolenoidOVThreshold = KU16_ZERO;

   /* Auto-test result */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   uint8 u8SolenoidUsedBitMask = KU8_ZERO;
   uint8 au8SelectedProfile[KU8_MAX_SOLENOID_NB];

   (void)Rte_Read_prrSolenoidProfile_au8SelectedProfile((uint8 *)au8SelectedProfile);

   u8SolenoidUsedBitMask |= (uint8)(KU8_ONE << ku8SolenoidId);

   if(sad_au8SolErrorPresentShortToGND[ku8SolenoidId] == KU8_SOLENOID_ELECTRICAL_AT_PASSED)
   {
      /* Check if a profile is currently running */
      if (((KU8_PROFILE_UNLOCK == au8SelectedProfile[ku8SolenoidId]) || (KU8_PROFILE_BACKUP == au8SelectedProfile[ku8SolenoidId])) &&
          (KU8_ZERO != (SAD_u8SolenoidInfiniteStepReached & u8SolenoidUsedBitMask)) )
      {
         /* Measure voltage across solenoid */
         Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_MAG_V_1 + ku8SolenoidId, &u16SolenoidMeasuredVoltage);
         Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_MAG_I_1 + ku8SolenoidId, &u16SolenoidMeasuredCurrent);

         /* Compute Solenoid Resistance in milliohms */
         u32SolenoidResistance = (uint32)( (uint32)u16SolenoidMeasuredVoltage / (uint32)u16SolenoidMeasuredCurrent ) * KU32_SAD_CONVERSION_UNIT;

         u16SolenoidOVThreshold = (uint16)u32InterpolateFromTable(u32SolenoidResistance, &sad_kstLookUpTableREStoOVUnlockThrsh);

         /* If voltage is between the specific thresholds */
         if (u16SolenoidMeasuredVoltage < u16SolenoidOVThreshold)
         {
            u8ResultOfAutoTest = KU8_ATM_TEST_OK;
            sad_au8SolErrorPresentOvervoltage[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_PASSED;
         }
         else
         {
            /* Solenoid is in open circuit */
            u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
            sad_au8SolErrorPresentOvervoltage[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_FAILED;
         }
      }
      /* If the profile is DIAGNOSTIC */
      else if ((KU8_PROFILE_DIAGNOSTIC == au8SelectedProfile[ku8SolenoidId]) && (KU8_SAD_UNDEFINED_STEP != SAD_au8StepToExecute[ku8SolenoidId]))
      {
         /* Measure voltage across solenoid */
         Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_MAG_V_1 + ku8SolenoidId, &u16SolenoidMeasuredVoltage);
         Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_MAG_I_1 + ku8SolenoidId, &u16SolenoidMeasuredCurrent);

         /* Compute Solenoid Resistance in milliohms */
         u32SolenoidResistance = (uint32)( (uint32)u16SolenoidMeasuredVoltage / (uint32)u16SolenoidMeasuredCurrent ) * KU32_SAD_CONVERSION_UNIT;

         u16SolenoidOVThreshold = (uint16)u32InterpolateFromTable(u32SolenoidResistance, &sad_kstLookUpTableREStoOVDiagThrsh);

         /* If voltage is between the specific thresholds */
         if (u16SolenoidMeasuredVoltage < u16SolenoidOVThreshold)
         {
            u8ResultOfAutoTest = KU8_ATM_TEST_OK;
            sad_au8SolErrorPresentOvervoltage[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_PASSED;
         }
         else
         {
            /* Solenoid is in open circuit */
            u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
            sad_au8SolErrorPresentOvervoltage[ku8SolenoidId] = KU8_SOLENOID_ELECTRICAL_AT_FAILED;
         }
      }
      else
      {
         /* Read last state of auto-test */
         Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_SOLENOID_OVERVOLTAGE, &u8ResultOfAutoTest);
      }
   }
   else
   {
      /* Read last state of auto-test */
      Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_SOLENOID_OVERVOLTAGE, &u8ResultOfAutoTest);
   }
   /* Return the auto test status */
   return u8ResultOfAutoTest;

}
/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

/**
* \brief
*        The function used to check each enabled solenoid if the maximum number
*        of retries was reached as an effect of trying to perform unlock profile
*        without unlock confirmation.
* \outputparam
*        Name: pu8TestResult;
*        Type: u8TestResultType *;
*        Description: The result of the auto-test;
*        Range:
*            KU8_ATM_TEST_OK
*            KU8_ATM_TEST_NOK
*            KU8_ATM_TEST_NOT_DECIDED;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        ATM_runMainFunction
* \dynamicaspectdescription
*        API called by ATM_runMainFunction.
* \constraints
*        Called from ATM_runMainFunction at each 10ms based on how is set in
*        RunningCyclicList.
* \ddesignrequirement
*        DSG_SAD_checkActuatorState
* \archrequirement
*        ARCH_SW_SAD_pseCheckActuatorState_SAD_checkActuatorState
*        ARCH_SW_SAD_prrSolenoidStuckStatus_SAD_checkActuatorState
*        ARCH_SW_SAD_pclModeManagement
**/
EXPORTED void SAD_checkActuatorState(u8TestResultType * pu8TestResult)
{
   uint8 u8BuckleStatus;
   uint8 au8SolenoidIsStuck[KU8_MAX_SOLENOID_NB];
   uint8 u8Index;


   *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;

   (void)Rte_Read_prrSolenoidStuckStatus_au8SolenoidIsStuck(au8SolenoidIsStuck);

   for (u8Index = KU8_ZERO; u8Index < KU8_MAX_SOLENOID_NB; u8Index++)
   {
      Rte_Call_pclModeManagement_CheckModeStatus(sad_kau64SolenoidBuckleStatusMask[u8Index], &u8BuckleStatus);
      /* Check if solenoid is enabled */
      if ((KU8_TRUE == au8SolenoidIsStuck[u8Index]) &&
          (KU8_TRUE == u8BuckleStatus) &&
          (KB_TRUE == KB_SAD_SOLENOID_CONFIGURED(u8Index)))
      {
         sad_u8StuckActuatorsStatus |= (uint8)(KU8_ONE << u8Index);
      }
      else
      {
         sad_u8StuckActuatorsStatus &= (uint8)(~(uint8)(KU8_ONE << u8Index));
      }
   }

   if(KU8_SAD_NO_STUCK_SOLENOID == sad_u8StuckActuatorsStatus)
   {
      *pu8TestResult = KU8_ATM_TEST_OK;
   }
   else
   {
      *pu8TestResult = KU8_ATM_TEST_NOK;
   }
}


/**
* \brief
*        Auto-test to check an open circuit fault on each solenoid circuit.
* \outputparam
*        Name: pu8TestResult;
*        Type: u8TestResultType * (uint8 *);
*        Description: The result of the auto-test;
*        Range:
*           KU8_ATM_TEST_OK
*           KU8_ATM_TEST_NOK
*           KU8_ATM_TEST_NOT_DECIDED;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        ATM_runMainFunction
* \dynamicaspectdescription
*        API called by ATM_runMainFunction.
* \constraints
*        ADC peripheral must be initialized.
*        Called from ATM_runMainFunction at each 100ms based on how is set in
*        RunningCyclicList.
* \ddesignrequirement
*        DSG_SAD_CheckSolenoidOpenCircuitAutotest
* \archrequirement
*        ARCH_SW_SAD_psrSolenoidOpenCircutStatus
*        ARCH_SW_SAD_pclAutotestServices
*        ARCH_SW_SAD_pclModeManagement
*        ARCH_SW_SAD_pclEvtActuatorOpenCircuit
*        ARCH_SW_SAD_pseCheckSolenoidOpenCircuit_SAD_CheckSolenoidOpenCircuitAutotest
*        ARCH_SW_SAD_psrSolenoidOpenCircutStatus_SAD_CheckSolenoidOpenCircuitAutotest
**/
EXPORTED void SAD_CheckSolenoidOpenCircuitAutotest(u8TestResultType * pu8TestResult)
{
   /* Auto-test Pass counter */
   uint8 u8SolenoidAutoTestPassCounter = KU8_ZERO;

   /* Auto-test Not Decided counter */
   uint8 u8SolenoidAutoTestNotDecidedCounter = KU8_ZERO;

   /* To store ADC auto-test status from ATM */
   uint8 u8PreviousADCTestResult;

   /* To return the result of individual enabled solenoid */
   u8TestResultType u8IndividualSolenoidAutotestResult = KU8_ATM_TEST_NOT_DECIDED;

   /* Definition for iterating in solenoid indexes */
   uint8 u8SolenoidIdx = KU8_ZERO;

   /* To store the status of the Open Circuit DTC */
   uint8 u8EventStatus;

   /* To store the number of enabled solenoids */
   uint8 u8NbOfEnableSolenoids = KU8_ZERO;

   /* Get ADC auto-test last result */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC_OUT_OF_ORDER, &u8PreviousADCTestResult);

   /* To execute this auto-test, previous auto-test result shall be passed  */
   if (KU8_ATM_TEST_OK == u8PreviousADCTestResult)
   {
      for(u8SolenoidIdx = KU8_ZERO; u8SolenoidIdx < KU8_MAX_SOLENOID_NB; u8SolenoidIdx++)
      {
         /* Check if solenoid is enabled */
         if(KB_TRUE == KB_SAD_SOLENOID_CONFIGURED(u8SolenoidIdx))
         {
            u8NbOfEnableSolenoids++;
            u8IndividualSolenoidAutotestResult = sad_ExecuteOpenCircuitCheck(u8SolenoidIdx);

            if(KU8_ATM_TEST_OK == u8IndividualSolenoidAutotestResult)
            {
               u8SolenoidAutoTestPassCounter++;
            }
            else if(KU8_ATM_TEST_NOT_DECIDED == u8IndividualSolenoidAutotestResult)
            {
               u8SolenoidAutoTestNotDecidedCounter++;
            }
            else
            {
               /* If the auto-test has failed, the counters will not be incremented */
            }
         }
      }

      /* Check if all enabled solenoids have passed the auto-test */
      if(u8NbOfEnableSolenoids == u8SolenoidAutoTestPassCounter)
      {
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_OK;

         /* Write status per every solenoid */
         (void)Rte_Write_psrSolenoidOpenCircutStatus_au8SolenoidAutotestStatus(sad_au8SolErrorPresentOpenCircuit);
      }
      /* Check if all auto-test results for enabled solenoids were not completed because of the LOCK profile */
      else if(u8NbOfEnableSolenoids == u8SolenoidAutoTestNotDecidedCounter)
      {
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;

         /* Write status per every solenoid */
         (void)Rte_Write_psrSolenoidOpenCircutStatus_au8SolenoidAutotestStatus(sad_au8SolErrorPresentOpenCircuit);
      }
      /* Check if all enabled solenoids were tested and the result was PASS
       * or Not Decided (caused by different executed profiles for individual solenoids) */
      else if(u8NbOfEnableSolenoids == (u8SolenoidAutoTestNotDecidedCounter + u8SolenoidAutoTestPassCounter))
      {
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;

         /* Write status per every solenoid */
         (void)Rte_Write_psrSolenoidOpenCircutStatus_au8SolenoidAutotestStatus(sad_au8SolErrorPresentOpenCircuit);
      }
      /* If at least one of the solenoids FAILED */
      else
      {
         (void)Rte_Call_pclEvtActuatorOpenCircuit_GetEventStatus(&u8EventStatus);

         /* Check if the open circuit Event has been qualified */
         if ((DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8EventStatus)) && ((KU8_ZERO == ((u8EventStatus) & (DEM_UDS_STATUS_TNCTOC)))))
         {
            /* Write status per every solenoid */
            (void)Rte_Write_psrSolenoidOpenCircutStatus_au8SolenoidAutotestStatus(sad_au8SolErrorPresentOpenCircuit);
         }
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_NOK;
      }
   }
   else
   {
      /* Conditions are not correct to execute the test, do nothing.
       * Test output has been already initialized to NOT_DECIDED */
      *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;
   }
}

/**
* \brief
*        Auto-test to check a short-to-ground fault on each solenoid circuit.
* \outputparam
*        Name: pu8TestResult;
*        Type: u8TestResultType * (uint8 *);
*        Description: The result of the auto-test;
*        Range: 
*           KU8_ATM_TEST_OK
*           KU8_ATM_TEST_NOK
*           KU8_ATM_TEST_NOT_DECIDED;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        ATM_runMainFunction
* \dynamicaspectdescription
*        API called by ATM_runMainFunction.
* \constraints
*        ADC peripheral must be initialized.
*        Called from ATM_runMainFunction at each 100ms based on how is set in
*        RunningCyclicList.
* \ddesignrequirement
*        DSG_SAD_CheckSolenoidShortToGNDAutotest
* \archrequirement
*        ARCH_SW_SAD_psrSolenoidShortToGndStatus
*        ARCH_SW_SAD_pclAutotestServices
*        ARCH_SW_SAD_pclModeManagement
*        ARCH_SW_SAD_pclEvtActuatorShortToGround
*        ARCH_SW_SAD_pseCheckSolenoidShortToGND_SAD_CheckSolenoidShortToGNDAutotest
*        ARCH_SW_SAD_psrSolenoidShortToGndStatus
**/
EXPORTED void SAD_CheckSolenoidShortToGNDAutotest(u8TestResultType * pu8TestResult)
{
   /* Auto-test Pass counter */
   uint8 u8SolenoidAutoTestPassCounter = KU8_ZERO;

   /* Auto-test Not Decided counter */
   uint8 u8SolenoidAutoTestNotDecidedCounter = KU8_ZERO;

   /* To store ADC auto-test status from ATM */
   uint8 u8PreviousADCTestResult;

   /* To return the result of individual enabled solenoid */
   u8TestResultType u8IndividualSolenoidAutotestResult = KU8_ATM_TEST_NOT_DECIDED;

   /* Definition for iterating in solenoid indexes */
   uint8 u8SolenoidIdx = KU8_ZERO;

   /* To store the status of the Open Circuit DTC */
   uint8 u8EventStatus;

   /* To store the number of enabled solenoids */
   uint8 u8NbOfEnableSolenoids = KU8_ZERO;

   /* Get ADC auto-test last result */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC_OUT_OF_ORDER, &u8PreviousADCTestResult);

   /* To execute this auto-test, previous auto-test result shall be passed  */
   if (KU8_ATM_TEST_OK == u8PreviousADCTestResult)
   {
      for(u8SolenoidIdx = KU8_ZERO; u8SolenoidIdx < KU8_MAX_SOLENOID_NB; u8SolenoidIdx++)
      {
         /* Check if solenoid is enabled */
         if(KB_TRUE == KB_SAD_SOLENOID_CONFIGURED(u8SolenoidIdx))
         {
            u8NbOfEnableSolenoids++;
            u8IndividualSolenoidAutotestResult = sad_ExecuteShortToGNDCheck(u8SolenoidIdx);

            if(KU8_ATM_TEST_OK == u8IndividualSolenoidAutotestResult)
            {
               u8SolenoidAutoTestPassCounter++;
            }
            else if(KU8_ATM_TEST_NOT_DECIDED == u8IndividualSolenoidAutotestResult)
            {
               u8SolenoidAutoTestNotDecidedCounter++;
            }
            else
            {
               /* If the auto-test has failed, the counters will not be incremented */
            }
         }
         else
         {
            /* Set the auto-test as OK if the solenoid is disabled */
            u8IndividualSolenoidAutotestResult = KU8_ATM_TEST_OK;
         }
      }

      /* Check if all enabled solenoids have passed the auto-test */
      if(u8NbOfEnableSolenoids == u8SolenoidAutoTestPassCounter)
      {
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_OK;

         /* Write status per every solenoid */
         (void)Rte_Write_psrSolenoidShortToGndStatus_au8SolenoidAutotestStatus(sad_au8SolErrorPresentShortToGND);
      }
      /* Check if all enabled solenoids were not completed because of the LOCK profile */
      else if(u8NbOfEnableSolenoids == u8SolenoidAutoTestNotDecidedCounter)
      {
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;

         /* Write status per every solenoid */
         (void)Rte_Write_psrSolenoidShortToGndStatus_au8SolenoidAutotestStatus(sad_au8SolErrorPresentShortToGND);
      }
      /* Check if all enabled solenoids were tested and the result was PASS
       * or Not Decided (caused by different executed profiles for individual solenoids) */
      else if(u8NbOfEnableSolenoids == (u8SolenoidAutoTestNotDecidedCounter + u8SolenoidAutoTestPassCounter))
      {
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;

         /* Write status per every solenoid */
         (void)Rte_Write_psrSolenoidShortToGndStatus_au8SolenoidAutotestStatus(sad_au8SolErrorPresentShortToGND);
      }
      /* If at least one of the solenoids FAILED */
      else
      {
         (void)Rte_Call_pclEvtActuatorShortToGround_GetEventStatus(&u8EventStatus);

         /* Check if the open circuit Event has been qualified */
         if ((DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8EventStatus)) && ((KU8_ZERO == ((u8EventStatus) & (DEM_UDS_STATUS_TNCTOC)))))
         {
            /* Write status per every solenoid */
            (void)Rte_Write_psrSolenoidShortToGndStatus_au8SolenoidAutotestStatus(sad_au8SolErrorPresentShortToGND);
         }
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_NOK;
      }
   }
   else
   {
      /* Conditions are not correct to execute the test, do nothing.
       * Test output has been already initialized to NOT_DECIDED */
      *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;
   }
}

/**
* \brief
*        Auto-test to check a short to VBAT fault on each solenoid circuit.
* \inputparam
*        None;
* \outputparam
*        Name: pu8TestResult;
*        Type: u8TestResultType * (uint8 *);
*        Description: The result of the auto-test;
*        Range:
*            KU8_ATM_TEST_OK
*            KU8_ATM_TEST_NOK
*            KU8_ATM_TEST_NOT_DECIDED;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        ATM_runMainFunction
* \dynamicaspectdescription
*        API called by ATM_runMainFunction.
* \constraints
*        ADC peripheral must be initialized.
*        Called from ATM_runMainFunction at each 100ms based on how is set in
*        RunningCyclicList.
* \ddesignrequirement
*        DSG_SAD_CheckSolenoidShortToGNDAutotest
* \archrequirement
*        ARCH_SW_SAD_psrSolenoidShortToVccStatus
*        ARCH_SW_SAD_pclAutotestServices
*        ARCH_SW_SAD_pclModeManagement
*        ARCH_SW_SAD_pclEvtActuatorShortToVbat
*        ARCH_SW_SAD_pseCheckSolenoidShortToVBAT_SAD_CheckSolenoidShortToVBATAutotest
**/
EXPORTED void SAD_CheckSolenoidShortToVBATAutotest(u8TestResultType * pu8TestResult)
{
   /* Auto-test Pass counter */
   uint8 u8SolenoidAutoTestPassCounter = KU8_ZERO;

   /* Auto-test Not Decided counter */
   uint8 u8SolenoidAutoTestNotDecidedCounter = KU8_ZERO;

   /* To store ADC auto-test status from ATM */
   uint8 u8PreviousADCTestResult;

   /* To return the result of individual enabled solenoid */
   u8TestResultType u8IndividualSolenoidAutotestResult = KU8_ATM_TEST_NOT_DECIDED;

   /* Definition for iterating in solenoid indexes */
   uint8 u8SolenoidIdx = KU8_ZERO;

   /* To store the status of the Open Circuit DTC */
   uint8 u8EventStatus;

   /* To store the number of enabled solenoids */
   uint8 u8NbOfEnableSolenoids = KU8_ZERO;

   /* Get ADC auto-test last result */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC_OUT_OF_ORDER, &u8PreviousADCTestResult);

   /* To execute this auto-test, previous auto-test result shall be passed  */
   if (KU8_ATM_TEST_OK == u8PreviousADCTestResult)
   {
      for(u8SolenoidIdx = KU8_ZERO; u8SolenoidIdx < KU8_MAX_SOLENOID_NB; u8SolenoidIdx++)
      {
         /* Check if solenoid is enabled */
         if(KB_TRUE == KB_SAD_SOLENOID_CONFIGURED(u8SolenoidIdx))
         {
            u8NbOfEnableSolenoids++;
            u8IndividualSolenoidAutotestResult = sad_ExecuteShortToVBATCheck(u8SolenoidIdx);

            if(KU8_ATM_TEST_OK == u8IndividualSolenoidAutotestResult)
            {
               u8SolenoidAutoTestPassCounter++;
            }
            else if(KU8_ATM_TEST_NOT_DECIDED == u8IndividualSolenoidAutotestResult)
            {
               u8SolenoidAutoTestNotDecidedCounter++;
            }
            else
            {
               /* If the auto-test has failed, the counters will not be incremented */
            }
         }
      }

      /* Check if all enabled solenoids have passed the auto-test */
      if(u8NbOfEnableSolenoids == u8SolenoidAutoTestPassCounter)
      {
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_OK;

         /* Write status per every solenoid */
         (void)Rte_Write_psrSolenoidShortToVccStatus_au8SolenoidAutotestStatus(sad_au8SolErrorPresentShortToVBAT);
      }
      /* Check if all enabled solenoids were not completed because of the LOCK profile */
      else if(u8NbOfEnableSolenoids == u8SolenoidAutoTestNotDecidedCounter)
      {
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;

         /* Write status per every solenoid */
         (void)Rte_Write_psrSolenoidShortToVccStatus_au8SolenoidAutotestStatus(sad_au8SolErrorPresentShortToVBAT);
      }
      /* Check if all enabled solenoids were tested and the result was PASS
       * or Not Decided (caused by different executed profiles for individual solenoids) */
      else if(u8NbOfEnableSolenoids == (u8SolenoidAutoTestNotDecidedCounter + u8SolenoidAutoTestPassCounter))
      {
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;

         /* Write status per every solenoid */
         (void)Rte_Write_psrSolenoidShortToVccStatus_au8SolenoidAutotestStatus(sad_au8SolErrorPresentShortToVBAT);
      }
      /* If at least one of the solenoids FAILED */
      else
      {
         (void)Rte_Call_pclEvtActuatorShortToVbat_GetEventStatus(&u8EventStatus);

         /* Check if the open circuit Event has been qualified */
         if ((DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8EventStatus)) && ((KU8_ZERO == ((u8EventStatus) & (DEM_UDS_STATUS_TNCTOC)))))
         {
            /* Write status per every solenoid */
            (void)Rte_Write_psrSolenoidShortToVccStatus_au8SolenoidAutotestStatus(sad_au8SolErrorPresentShortToVBAT);
         }
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_NOK;
      }
   }

   else
   {
      /* Conditions are not correct to execute the test, do nothing.
       * Test output has been already initialized to NOT_DECIDED */
      *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;
   }
}

/**
* \brief
*        Auto-test to check that the power stage is functioning correctly.
* \outputparam
*        Name: pu8TestResult;
*        Type: u8TestResultType * (uint8 *);
*        Description: The result of the auto-test;
*        Range:
*           KU8_ATM_TEST_OK
*           KU8_ATM_TEST_NOK
*           KU8_ATM_TEST_NOT_DECIDED;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        ATM_runMainFunction
* \dynamicaspectdescription
*        API called by ATM_runMainFunction.
* \constraints
*        ADC peripheral must be initialized.
*        Called from ATM_runMainFunction at each 100ms based on how is set in
*        RunningCyclicList.
* \ddesignrequirement
*        DSG_SAD_CheckPowerStage
* \archrequirement
*        ARCH_SW_SAD_pseCheckPowerStage_SAD_CheckPowerStage
*        ARCH_SW_SAD_pclModeManagement
*        ARCH_SW_SAD_pclDioIfServices
**/
EXPORTED void SAD_CheckPowerStage (u8TestResultType *pu8TestResult)
{
   /* Auto-test Pass counter */
   uint8 u8SolenoidAutoTestPassCounter = KU8_ZERO;

   /* Auto-test Not Decided counter */
   uint8 u8SolenoidAutoTestNotDecidedCounter = KU8_ZERO;

   /* To return the result of individual enabled solenoid */
   u8TestResultType u8IndividualSolenoidAutotestResult = KU8_ATM_TEST_NOT_DECIDED;

   /* Definition for iterating in solenoid indexes */
   uint8 u8SolenoidIdx = KU8_ZERO;

   /* To store the number of enabled solenoids */
   uint8 u8NbOfEnableSolenoids = KU8_ZERO;

   for(u8SolenoidIdx = KU8_ZERO; u8SolenoidIdx < KU8_MAX_SOLENOID_NB; u8SolenoidIdx++)
   {
      if(KB_TRUE == KB_SAD_SOLENOID_CONFIGURED(u8SolenoidIdx))
      {
         u8NbOfEnableSolenoids++;
         u8IndividualSolenoidAutotestResult = sad_ExecutePinStateCheck(u8SolenoidIdx);

         if(KU8_ATM_TEST_OK == u8IndividualSolenoidAutotestResult)
         {
            u8SolenoidAutoTestPassCounter++;
         }
         else if(KU8_ATM_TEST_NOT_DECIDED == u8IndividualSolenoidAutotestResult)
         {
            u8SolenoidAutoTestNotDecidedCounter++;
         }
         else
         {
            /* If the auto-test has failed, the counters will not be incremented */
         }
      }
   }

      /* Check if all enabled solenoids have passed the auto-test */
      if(u8NbOfEnableSolenoids == u8SolenoidAutoTestPassCounter)
      {
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_OK;

      }
      /* Check if all auto-test results for enabled solenoids were not completed because of the LOCK profile */
      else if(u8NbOfEnableSolenoids == u8SolenoidAutoTestNotDecidedCounter)
      {
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;

      }
      /* Check if all enabled solenoids were tested and the result was PASS
       * or Not Decided (caused by different executed profiles for individual solenoids) */
      else if(u8NbOfEnableSolenoids == (u8SolenoidAutoTestNotDecidedCounter + u8SolenoidAutoTestPassCounter))
      {
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;

      }
      /* If at least one of the solenoids FAILED */
      else
      {
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_NOK;
      }

}

/**
* \brief
*        Auto-test to check that no overvoltage condition is present on the solenoids.
* \outputparam
*        Name: pu8TestResult;
*        Type: u8TestResultType * (uint8 *);
*        Description: The result of the auto-test;
*        Range: 
*           KU8_ATM_TEST_OK
*           KU8_ATM_TEST_NOK
*           KU8_ATM_TEST_NOT_DECIDED;
* \exception
*        This function has no exceptions.
* \pre
*        This function has no preconditions.
* \post
*        This function has no postconditions.
* \return
*        This function has no return.
* \dynamicaspectcaller
*        ATM_runMainFunction
* \dynamicaspectdescription
*        API called by ATM_runMainFunction.
* \constraints
*        ADC peripheral must be initialized.
*        Called from ATM_runMainFunction at each 100ms based on how is set in
*        RunningCyclicList.
* \ddesignrequirement
*        DSG_SAD_CheckSolenoidOvervoltage
* \archrequirement
*        ARCH_SW_SAD_pseCheckSolenoidOvervoltage_SAD_CheckSolenoidOvervoltage
*        ARCH_SW_SAD_psrSolenoidOvervoltageStatus
*        ARCH_SW_SAD_pclEvtSolenoidOvervoltage
*        ARCH_SW_SAD_pclAutotestServices
*        ARCH_SW_SAD_pclModeManagement
**/
EXPORTED void SAD_CheckSolenoidOvervoltage (u8TestResultType *pu8TestResult)
{
   /* Auto-test Pass counter */
   uint8 u8SolenoidAutoTestPassCounter = KU8_ZERO;

   /* Auto-test Not Decided counter */
   uint8 u8SolenoidAutoTestNotDecidedCounter = KU8_ZERO;

   /* To store ADC auto-test status from ATM */
   uint8 u8PreviousADCTestResult;

   /* To return the result of individual enabled solenoid */
   u8TestResultType u8IndividualSolenoidAutotestResult = KU8_ATM_TEST_NOT_DECIDED;

   /* Definition for iterating in solenoid indexes */
   uint8 u8SolenoidIdx = KU8_ZERO;

   /* To store the status of the Open Circuit DTC */
   uint8 u8EventStatus;

   /* To store the number of enabled solenoids */
   uint8 u8NbOfEnableSolenoids = KU8_ZERO;

   /* Get ADC auto-test last result */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC_OUT_OF_ORDER, &u8PreviousADCTestResult);

   /* To execute this auto-test, previous auto-test result shall be passed  */
   if (KU8_ATM_TEST_OK == u8PreviousADCTestResult)
   {
      for(u8SolenoidIdx = KU8_ZERO; u8SolenoidIdx < KU8_MAX_SOLENOID_NB; u8SolenoidIdx++)
      {
         if(KB_TRUE == KB_SAD_SOLENOID_CONFIGURED(u8SolenoidIdx))
         {
            u8NbOfEnableSolenoids++;
            u8IndividualSolenoidAutotestResult = sad_ExecuteOvervoltageCheck(u8SolenoidIdx);

            if(KU8_ATM_TEST_OK == u8IndividualSolenoidAutotestResult)
            {
               u8SolenoidAutoTestPassCounter++;
            }
            else if(KU8_ATM_TEST_NOT_DECIDED == u8IndividualSolenoidAutotestResult)
            {
               u8SolenoidAutoTestNotDecidedCounter++;
            }
            else
            {
               /* If the auto-test has failed, the counters will not be incremented */
            }
         }
      }

      /* Check if all enabled solenoids have passed the auto-test */
      if(u8NbOfEnableSolenoids == u8SolenoidAutoTestPassCounter)
      {
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_OK;

         /* Write status per every solenoid */
         (void)Rte_Write_psrSolenoidOvervoltageStatus_au8SolenoidOvervoltageStatus(sad_au8SolErrorPresentOvervoltage);
      }
      /* Check if all auto-test results for enabled solenoids were not completed because of the LOCK profile */
      else if(u8NbOfEnableSolenoids == u8SolenoidAutoTestNotDecidedCounter)
      {
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;

         /* Write status per every solenoid */
         (void)Rte_Write_psrSolenoidOvervoltageStatus_au8SolenoidOvervoltageStatus(sad_au8SolErrorPresentOvervoltage);
      }
      /* Check if all enabled solenoids were tested and the result was PASS
       * or Not Decided (caused by different executed profiles for individual solenoids) */
      else if(u8NbOfEnableSolenoids == (u8SolenoidAutoTestNotDecidedCounter + u8SolenoidAutoTestPassCounter))
      {
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;

         /* Write status per every solenoid */
         (void)Rte_Write_psrSolenoidOvervoltageStatus_au8SolenoidOvervoltageStatus(sad_au8SolErrorPresentOvervoltage);
      }
      /* If at least one of the solenoids FAILED */
      else
      {
         (void)Rte_Call_pclEvtSolenoidOvervoltage_GetEventStatus(&u8EventStatus);

         /* Check if the open circuit Event has been qualified */
         if ((DEM_UDS_STATUS_TF == (DEM_UDS_STATUS_TF & u8EventStatus)) && ((KU8_ZERO == ((u8EventStatus) & (DEM_UDS_STATUS_TNCTOC)))))
         {
            /* Write status per every solenoid */
            (void)Rte_Write_psrSolenoidOvervoltageStatus_au8SolenoidOvervoltageStatus(sad_au8SolErrorPresentOvervoltage);
         }
         /* Return the auto test status */
         *pu8TestResult = KU8_ATM_TEST_NOK;
      }
   }
   else
   {
      /* Conditions are not correct to execute the test, do nothing.
       * Test output has been already initialized to NOT_DECIDED */
      *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;
   }
}

#define SAD_STOP_SEC_CODE_ASIL_A
#include "SAD_MemMap.h"

/******************************************************************************
End Of File
*****************************************************************************/
