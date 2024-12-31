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
$Revision: 1.14 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/IoHwAb/Implementation/src/project.pj $
*/
/*!****************************************************************************
Overview of the interfaces:
   This file defines the information (interfaces, definitions and data) provided
by the module IoHwAb, part of the component IoHwAb.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "IoHwAb_AdcIf.h"
#include "Rte_IoHwAb.h"
#include "common.h"
#include "Nvp_Cfg.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/


/**
 *\brief
 *     Macro used to count number of solenoids.
 */
#define KU8_IOHWAB_NUMBER_OF_SOLENOIDS  ((uint8) KU8_GLOBAL_NUMBER_OF_SOLENOIDS)

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
#define IoHwAb_START_SEC_CODE
#include "IoHwAb_MemMap.h"

/**
* \brief
*       Auto test to check over temperature of MCU.
* \outputparam
*       Name: pu8TestResult;
*       Type: u8TestResultType *;
*       Description: Autotest test result;
*       Range: 
*          KU8_ATM_TEST_OK
*          KU8_ATM_TEST_NOK
*          KU8_ATM_TEST_NOT_DECIDED;    
* \dynamicaspectcaller
*       ATM SW Component.
* \dynamicaspectdescription
*       API called in ATM_castTestConfig autotests list.
* \constrains
*       ADC pheripheral must be initialised.
* \ddesignrequirement
*       DSG_IoHwAb_CheckEcuOverTemperatureAutotest
* \archrequirement
*       ARCH_SW_IoHwAb_pseEcuOverTemperature
*       ARCH_SW_IoHwAb_pclAutotestServices_IoHwAb_CheckEcuOverTemperatureAutotest
*       ARCH_SW_IoHwAb_pclRawAdcService_IoHwAb_GetPtcTemperature
*/
EXPORTED void IoHwAb_CheckEcuOverTemperatureAutotest(u8TestResultType * pu8TestResult)
{
   /* To store ADC auto-test status from ATM */
   uint8  u8PreviousADCTestResult;

   /* Auto-test result */
   uint8 u8ResultOfAutoTest;
   sint16 s16MCUTemperature;

   /* Init result to not decided*/
   u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* Get ADC auto-test result */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC_OUT_OF_ORDER, &u8PreviousADCTestResult);

   /* To execute this auto-test, ADC auto-test shall be passed */
   if ( KU8_ATM_TEST_OK == u8PreviousADCTestResult)
   {
      /* Read Temperature in deci °C with offset -40°c = -400 deci °C*/
      IoHwAb_GetPtcTemperature(&s16MCUTemperature);
      if ((NVP_s16TemperatureSensorLowThrs  <= s16MCUTemperature) &&
          (NVP_s16TemperatureSensorHighThrs >= s16MCUTemperature))
      {
         /* Temperature is in nominal range, return OK */
         u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }
      else
      {
         /* Temperature is out of nominal range, return OK */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
   }

   /* Return the auto test status */
   *pu8TestResult = u8ResultOfAutoTest;
}

#define IoHwAb_STOP_SEC_CODE
#include "IoHwAb_MemMap.h"

#define IoHwAb_START_SEC_CODE_ASIL_A
#include "IoHwAb_MemMap.h"

/**
* \brief
*       Auto test to check overvoltage detection on KL30 ADC line.
* \outputparam
*       Name: pu8TestResult;
*       Type: u8TestResultType *;
*       Description: Autotest test result;
*       Range: 
*          KU8_ATM_TEST_OK
*          KU8_ATM_TEST_NOK
*          KU8_ATM_TEST_NOT_DECIDED;    
* \dynamicaspectcaller
*       ATM SW Component.
* \dynamicaspectdescription
*       API called in ATM_castTestConfig autotests list.
* \constrains
*       ADC pheripheral must be initialised.
* \ddesignrequirement
*		DSG_IoHwAb_CheckPowerSupplyOvervoltageAutotest
* \archrequirement
*       ARCH_SW_IoHwAb_pseCheckPowerSupplyOV
*       ARCH_SW_IoHwAb_pclAutotestServices_IoHwAb_CheckPowerSupplyOvervoltageAutotest
*       ARCH_SW_IoHwAb_prrSolenoidPwm_IoHwAb_runGetMeasure
*       ARCH_SW_IoHwAb_pclRawAdcService_IoHwAb_runGetMeasure 
*       ARCH_SW_IoHwAb_pclDioIfServices_IoHwAb_runGetMeasure
*/
EXPORTED void IoHwAb_CheckPowerSupplyOvervoltageAutotest(u8TestResultType * pu8TestResult)
{
   /* To store ADC auto-test status from ATM */
   uint8  u8PreviousADCTestResult;

   /* Variable used to store last autotest result of this autotest */
   uint8 u8PreviousKL30TestResult;

   /* to get KLXX Vbat measure*/
   uint16 u16VbatPowerVoltage;

   /* Auto-test result */
   uint8 u8ResultOfAutoTest;

   /* Init result to not decided*/
   u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* Get ADC auto-test result */
   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC_OUT_OF_ORDER, &u8PreviousADCTestResult);

   /* To execute this auto-test, ADC auto-test shall be passed  */
   if (KU8_ATM_TEST_OK == u8PreviousADCTestResult)
   {

      /* ADC auto-test are OK, we can get the battery voltage */
      /* Get the filtered physical value measured on ADC Power Vbat pin from IoHwAb */
      IoHwAb_runGetMeasure(KU8_ADC_CH_ID_V_BATT_10_MS, &u16VbatPowerVoltage);

      /* Read last state of IoHwAb_CheckPowerSupplyOvervoltageAutotest autotest */
      Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_POWER_SUPPLY_OV, &u8PreviousKL30TestResult);

      /* Check current autotest last status */
      if (KU8_ATM_TEST_OK == u8PreviousKL30TestResult)
      {
         /* Check if KL30 is under NVP_u16UnderKL30QualificationThrs*/
         if (NVP_u16OverKL30QualificationThrs > u16VbatPowerVoltage)
         {
             /* Voltage is below the threshold, return OK */
            u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
         else
         {
            /* Voltage is over the threshold, return NOK */
            u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
      }
      else
      {
         /* Check if KL30 is under NVP_u16UnderKL30QualificationThrs*/
         if (NVP_u16OverKL30DisqualificationThrs > u16VbatPowerVoltage)
         {
             /* Voltage is below the threshold, return OK */
            u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
         else
         {
            /* Voltage is over the threshold, return NOK */
            u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
      }
   }

   /* Return the auto test status */
   *pu8TestResult = u8ResultOfAutoTest;
}

/**
* \brief
*       Auto test to check undervoltage detection on KL30 ADC line.
* \outputparam
*       Name: pu8TestResult;
*       Type: u8TestResultType *;
*       Description: Autotest test result;
*       Range: 
*          KU8_ATM_TEST_OK
*          KU8_ATM_TEST_NOK
*          KU8_ATM_TEST_NOT_DECIDED;    
* \dynamicaspectcaller
*       ATM SW Component.
* \dynamicaspectdescription
*       API called in ATM_castTestConfig autotests list.
* \constrains
*       ADC pheripheral must be initialised.
* \ddesignrequirement
*		DSG_IoHwAb_CheckPowerSupplyUndervoltageAutotest
* \archrequirement
*       ARCH_SW_IoHwAb_pseCheckPowerSupplyUV
*       ARCH_SW_IoHwAb_pclAutotestServices_IoHwAb_CheckPowerSupplyUndervoltageAutotest
*       ARCH_SW_IoHwAb_prrSolenoidPwm_IoHwAb_runGetMeasure
*       ARCH_SW_IoHwAb_pclRawAdcService_IoHwAb_runGetMeasure 
*       ARCH_SW_IoHwAb_pclDioIfServices_IoHwAb_runGetMeasure
*/
EXPORTED void IoHwAb_CheckPowerSupplyUndervoltageAutotest(u8TestResultType * pu8TestResult)
{
	/* To store ADC auto-test status from ATM */
	uint8  u8PreviousADCTestResult;

	/* Variable used to store last autotest result of this autotest */
	uint8 u8PreviousKL30TestResult;

	/* to get KLXX Vbat measure*/
	uint16 u16VbatPowerVoltage;

	/* Auto-test result */
	uint8 u8ResultOfAutoTest;

	/* Init result to not decided*/
	u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

	/* Get ADC auto-test result */
	Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_TEST_ADC_OUT_OF_ORDER, &u8PreviousADCTestResult);

	/* To execute this auto-test, ADC auto-test shall be passed  */
	if (KU8_ATM_TEST_OK == u8PreviousADCTestResult)
	{
	   /* ADC auto-test are OK, we can get the battery voltage */
	   /* Get the filtered physical value measured on ADC Power Vbat pin from IoHwAb */
	   IoHwAb_runGetMeasure(KU8_ADC_CH_ID_V_BATT_10_MS, &u16VbatPowerVoltage);

	   /* Read last state of IoHwAb_CheckPowerSupplyUndervoltageAutotest autotest */
	   Rte_Call_pclAutotestServices_GetTestResult(ATM_KU8_ID_POWER_SUPPLY_UV, &u8PreviousKL30TestResult);

      /* Check current autotest last status */
      if (KU8_ATM_TEST_OK == u8PreviousKL30TestResult)
      {
         /* Check if KL30 is under NVP_u16UnderKL30QualificationThrs*/
         if (NVP_u16UnderKL30QualificationThrs <= u16VbatPowerVoltage)
         {
             /* Voltage is below the threshold, return OK */
            u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
         else
         {
            /* Voltage is over the threshold, return NOK */
            u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
      }
      else
      {
         /* Check if KL30 is under NVP_u16UnderKL30QualificationThrs*/
         if (NVP_u16UnderKL30DisqualificationThrs <= u16VbatPowerVoltage)
         {
             /* Voltage is below the threshold, return OK */
            u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
         else
         {
            /* Voltage is over the threshold, return NOK */
            u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
      }

	}

	/* Return the auto test status */
	*pu8TestResult = u8ResultOfAutoTest;
}

#define IoHwAb_STOP_SEC_CODE_ASIL_A
#include "IoHwAb_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
