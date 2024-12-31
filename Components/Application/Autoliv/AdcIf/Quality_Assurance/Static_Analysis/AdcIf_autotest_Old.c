
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
$Revision: 1.4.2.7 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/AdcIf/Quality_Assurance/Static_Analysis/project.pj $
*/
/*!****************************************************************************

details
   File containing the AdcIf component autotest

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "common.h"
#include "Nvp_Generated_NvmDefault.h"
#include "Rte_AdcIf.h"
#include "AdcIf.h"
#include "IoHwAb_AdcIf.h"

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
#define AdcIf_START_SEC_CODE_ASIL_A
#include "AdcIf_MemMap.h"

/**
* \brief
*       This is the ADC autotest. It consists of checking that the two
*       reference voltages measured on the dedicated ADC channels do not drift.
* \outputparam
*       Name: pu8TestResult;
*       Type: u8TestResultType *;
*       Description: The autotest test result in uint8 range;
*       Range: 
*			KU8_ATM_TEST_OK
*           KU8_ATM_TEST_NOK
*           KU8_ATM_TEST_NOT_DECIDED;
* \pre
*       This function must be called in autotests.
* \dynamicaspectcaller
*       ATM Autotests.
* \dynamicaspectdescription
*       Called in Autotests via RTE layer.
* \constrains
*       ADC Pheripheral must be initialised.
* \ddesignrequirement
*		DSG_AdcIf_Autotest_CheckAdc
* \archrequirement
*       ARCH_SW_AdcIf_pseCheckAdc
*/
void AdcIf_Autotest_CheckAdc(u8TestResultType * pu8TestResult)
{
   /* This is the filtered raw value measured on ADC test pins */
	uint16 u16ADCRefLowVoltage;
	uint16 u16ADCRefHighVoltage;

   /* Returned status */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* Get the filtered raw (not transformed to physical) value
      of measured voltage on ADC test pins */
   AdcIf_runGetChannelValue((u8AdcChannelIDType)KU8_ADC_CH_ID_V_REF_LOW, &u16ADCRefLowVoltage);
   AdcIf_runGetChannelValue((u8AdcChannelIDType)KU8_ADC_CH_ID_V_REF_HIGH, &u16ADCRefHighVoltage);

   /* Convert filtered raw values in mV */
   u16ADCRefLowVoltage = (uint16) ((((uint32)u16ADCRefLowVoltage) * KU16_IOHWAB_ADC_REFERENCE_MV) / KU16_IOHWAB_ADC_FULL_RANGE);
   u16ADCRefHighVoltage = (uint16) ((((uint32)u16ADCRefHighVoltage) * KU16_IOHWAB_ADC_REFERENCE_MV) / KU16_IOHWAB_ADC_FULL_RANGE);

   /* Compare the ADC low voltage value to the corresponding threshold */
   if (NVP_u16ADCLowVoltageThrs < u16ADCRefLowVoltage)
   {
      /* If the value is strictly above the threshold, return NOK */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }
   /* Compare the ADC high voltage value to the corresponding threshold */
   else if(u16ADCRefHighVoltage < NVP_u16ADCHighVoltageThrs)
   {
      u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }
   /* All ADC reference voltages are in expected range */
   else
   {
      u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }

   /* Return the auto test status */
   *pu8TestResult = u8ResultOfAutoTest;
}

/**
* \brief
*       This is the ADC calib autotest. 
*       It consists of checking that the ADC calibration is OK.
* \outputparam
*       Name: pu8TestResult;
*       Type: u8TestResultType *;
*       Description: The autotest test result in uint8 range;
*       Range: 
*          KU8_ATM_TEST_OK
*          KU8_ATM_TEST_NOK
*          KU8_ATM_TEST_NOT_DECIDED;
* \pre
*       This function must be called in autotests.
* \dynamicaspectcaller
*       ATM Autotests.
* \dynamicaspectdescription
*       Called in Autotests Manager SW component via RTE layer.
* \constrains
*       AdcIf_Calib function must be executed first.
* \ddesignrequirement
*		DSG_AdcIf_Autotest_CheckAdcCalib
* \archrequirement
*       ARCH_SW_AdcIf_pseCheckAdcCalib
*/
void AdcIf_Autotest_CheckAdcCalib(u8TestResultType *pu8TestResult)
{

   /* Returned status */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* If the two calibration are OK */
   if ((E_OK == ADCIF_stCalibrationStatus0.Adc_UnitSelfTestStatus) && (E_OK == ADCIF_stCalibrationStatus1.Adc_UnitSelfTestStatus ))
   {

      u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }
   /*If one of them is NOK */
   else
   {
      u8ResultOfAutoTest = KU8_ATM_TEST_NOK;

   }

   /* Return the auto test status */
   *pu8TestResult = u8ResultOfAutoTest;
}

#define AdcIf_STOP_SEC_CODE_ASIL_A
#include "AdcIf_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
