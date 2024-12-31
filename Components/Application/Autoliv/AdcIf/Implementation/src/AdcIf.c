
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
$Revision: 1.19.1.5.1.2.1.15 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/AdcIf/Implementation/src/project.pj $
*/
/*!****************************************************************************

details
	interface of the AdcIf package to modules below the RTE

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_AdcIf.h"
#include "common.h"
#include "AdcIf.h"
#include "AdcIf_cfg.h"
#include "Gpt.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/

/**
 * \brief
 *      End of converison OS alarm period. Based on Os ticks: 1 tick = 25ns and 1mS = 40000 ticks.
 */
#define KU32_TIMER_INTERRUPT_RST_VALUE           ((uint32) 40000)

/**
 * \brief
 *      Macro used to select groups of ADC channels to be calibrated.
 */
#define KU8_ADCIF_CALIBRATE_INDEX_MAX     ((uint8) 3u)

/**
 * \brief
 *      Macro used to count number of solenoids.
 */
#define KU8_ADCIF_NUMBER_OF_SOLENOIDS	  ((uint8) KU8_GLOBAL_NUMBER_OF_SOLENOIDS)


/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#define AdcIf_START_SEC_VAR_NO_INIT_16_ASIL_A
#include "AdcIf_MemMap.h"
/**
 * \brief
 *      Array of solenoid values aquired for solenoid confirmation algorithm.
 *      This array is constructed to work as a circular buffer for each solenoid.
 *      First position is solenoid number and second position is sample block number.
 *      Because the IoHwAb_SolenoidConfirmation API is called every 2mS and ADC pheripheral
 *      is configued to work at every 1mS, will be 2 blocks of 3 samples, each block will be
 *      sampled every 1mS.
 * \initialization
 *      None.
 * \range
 *      0..ADC BIT RANGE ( 10 bit - 1023 ).
 *
 */
LOCAL uint16 adcif_au16RawAdcSampleBuffer[KU8_SIX][KU8_SIX];

#define AdcIf_STOP_SEC_VAR_NO_INIT_16_ASIL_A
#include "AdcIf_MemMap.h"

#define AdcIf_START_SEC_VAR_NO_INIT_8_ASIL_A
#include "AdcIf_MemMap.h"
/**
 * \brief
 *      Index of solenoid values array needed in order to aquire from corect position.
 *      This index must be proportional with ratio between ADC pheripheral callback ( 1mS )
 *      and IoHwAB SolenoidConfirmation callback ( 2mS ).
 *      Because there are 3 channels of ADC sampled every 1mS => for 2 mS is needed 2 blocks of 3 samples each
 *      => 2 * 3 = 6 values.
 * \initialization
 *      None.
 * \range
 *      0 and 3.
 */
LOCAL uint8 adcif_u8RawAdcSampleBufferIdx;

#define AdcIf_STOP_SEC_VAR_NO_INIT_8_ASIL_A
#include "AdcIf_MemMap.h"
/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/**
 * \brief
 *      This variable is used to retain calibration status of group 0.
 * \initialization 
 *      E_NOT_OK.
 */
EXPORTED Adc_CalibrationStatusType ADCIF_stCalibrationStatus0 = {E_NOT_OK};

/**
 * \brief
 *      This variable is used to retain calibration status of group 1.
 * \initialization 
 *      E_NOT_OK.
 */
EXPORTED Adc_CalibrationStatusType ADCIF_stCalibrationStatus1 = {E_NOT_OK};

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
 *       This function will start the adc timer used for sampling.
 *       This service is called only when exiting low power mode.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       Called by LPM component.
 * \dynamicaspectdescription
 *       Called by LPM component.
 * \ddesignrequirement
 *		 DSG_AdcIf_StartConversion
 * \archrequirement
 *       ARCH_SW_AdcIf_pseAdcIfServices_AdcIf_StartConversion
 *       ARCH_SW_AdcIf_ptrrAsrGptServicesAdcIf_Gpt_StartTimer_AdcIf_StartConversion
 */
EXPORTED void AdcIf_StartConversion(void)
{
   Adc_StartGroupConversion(AdcGroup_0);
   Adc_StartGroupConversion(AdcGroup_1);
   Gpt_StartTimer(GptConf_GptChannelConfiguration_GPT_ADC_TIMER, KU32_TIMER_INTERRUPT_RST_VALUE);
}

/**
 * \brief
 *       This function will stop the adc timer used for sampling. 
 *       This service is called only when going to low power mode.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       Called by LPM component.
 * \dynamicaspectdescription
 *       Called by LPM component.
 * \ddesignrequirement
 *		 DSG_AdcIf_StopConversion
 * \archrequirement
 *       ARCH_SW_AdcIf_pseAdcIfServices_AdcIf_StopConversion
 *       ARCH_SW_AdcIf_ptrrAsrGptServicesAdcIf_Gpt_StopTimer_AdcIf_StopConversion
 */
EXPORTED void AdcIf_StopConversion(void)
{
   Gpt_StopTimer(GptConf_GptChannelConfiguration_GPT_ADC_TIMER);
}

/**
 * \brief
 *       This function will wait for current adc sampling to finish.
 *       This service is called only when going to low power mode.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       Called by LPM component.
 * \dynamicaspectdescription
 *       Called by LPM component.
 * \ddesignrequirement
 *		 DSG_AdcIf_WaitForConversion
 * \archrequirement
 *       ARCH_SW_AdcIf_pseAdcIfServices_AdcIf_WaitForConversion
 *       ARCH_SW_AdcIf_ptrrAsrAdcServicesAdcIf_Adc_ReadGroup_AdcIf_WaitForConversion 
 */
EXPORTED void AdcIf_WaitForConversion(void)
{
   Std_ReturnType u8ReturnGroup0 = E_NOT_OK;
   Std_ReturnType u8ReturnGroup1 = E_NOT_OK;

   uint8 u8NoOfRetries = KU8_ZERO;

   do
   {
      u8ReturnGroup0 = Adc_ReadGroup(AdcGroup_0, ADCIF_au16Group0Results);
      u8NoOfRetries++;

   }while((E_NOT_OK == u8ReturnGroup0) && (u8NoOfRetries < KU8_SIXTY));

   u8NoOfRetries = KU8_ZERO;

   do
   {
      u8ReturnGroup1 = Adc_ReadGroup(AdcGroup_1, ADCIF_au16Group1Results);
      u8NoOfRetries++;

   }while((E_NOT_OK == u8ReturnGroup1) && (u8NoOfRetries < KU8_SIXTY));
}

/**
* \brief
*       This function will get all results from ADC Channels and will start
*       performing battery monitoring.
*       This service is configured as a notification API from tresos-configured GPT timer.
*       This service behaves like an interrupt that is called by GPT timer cyclic.
*       First group will sample ECU Temp reference, ADC reference and WAKE lines.
*       Second group will sample solenoid voltages, KL30 line and PTC sensor readings.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       Operating System.
* \dynamicaspectdescription
*       Timer Interrupt configured in Tresos. 
* \constrains
*       It is called cyclic by timer interrupt.
* \ddesignrequirement
*		DSG_AdcIf_GPTOnTimer_Expiration
* \archrequirement
*       ARCH_SW_AdcIf_ptrpAsrGptServicesAdcIf
*       ARCH_SW_AdcIf_ptrrAsrAdcServicesAdcIf_Adc_StartGroupConversion_AdcIf_GPTOnTimer_Expiration
*       ARCH_SW_AdcIf_prrAdcBufferServices_AdcIf_GPTOnTimer_Expiration
*       ARCH_SW_IoHwAb_prrAdcBufferServices_IoHwAb_DetectVoltageFluctuation
*/
void AdcIf_GPTOnTimer_Expiration(void)
{

//   /* Read all ADC result */
//   ADCIF_EndOfConvGroup0();
//   ADCIF_EndOfConvGroup1();
//
//   /* Start new conversion */
//   /* COVERS: ARCH_SW_AdcIf_ptrrAsrAdcServices_Adc_StartGroupConversion_AdcIf_GPTOnTimer_Expiration */
//   Adc_StartGroupConversion(AdcGroup_0);
//   Adc_StartGroupConversion(AdcGroup_1);

   adcif_au16RawAdcSampleBuffer[KU8_ZERO][adcif_u8RawAdcSampleBufferIdx]           = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_MAG_V_1];
   adcif_au16RawAdcSampleBuffer[KU8_ZERO][adcif_u8RawAdcSampleBufferIdx + KU8_ONE] = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_MAG_V_1_1];
   adcif_au16RawAdcSampleBuffer[KU8_ZERO][adcif_u8RawAdcSampleBufferIdx + KU8_TWO] = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_MAG_V_1_2];

   adcif_au16RawAdcSampleBuffer[KU8_ONE][adcif_u8RawAdcSampleBufferIdx]            = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_MAG_V_2];
   adcif_au16RawAdcSampleBuffer[KU8_ONE][adcif_u8RawAdcSampleBufferIdx + KU8_ONE]  = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_MAG_V_2_1];
   adcif_au16RawAdcSampleBuffer[KU8_ONE][adcif_u8RawAdcSampleBufferIdx + KU8_TWO]  = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_MAG_V_2_2];

   adcif_au16RawAdcSampleBuffer[KU8_TWO][adcif_u8RawAdcSampleBufferIdx]            = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_MAG_V_3];
   adcif_au16RawAdcSampleBuffer[KU8_TWO][adcif_u8RawAdcSampleBufferIdx + KU8_ONE]  = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_MAG_V_3_1];
   adcif_au16RawAdcSampleBuffer[KU8_TWO][adcif_u8RawAdcSampleBufferIdx + KU8_TWO]  = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_MAG_V_3_2];

   adcif_au16RawAdcSampleBuffer[KU8_THREE][adcif_u8RawAdcSampleBufferIdx]           = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_MAG_V_4];
   adcif_au16RawAdcSampleBuffer[KU8_THREE][adcif_u8RawAdcSampleBufferIdx + KU8_ONE] = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_MAG_V_4_1];
   adcif_au16RawAdcSampleBuffer[KU8_THREE][adcif_u8RawAdcSampleBufferIdx + KU8_TWO] = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_MAG_V_4_2];

   adcif_au16RawAdcSampleBuffer[KU8_FOUR][adcif_u8RawAdcSampleBufferIdx]           = ADCIF_au16Group0Results[ADCIF_ENUM_GROUP0_ADC_MAG_V_5];
   adcif_au16RawAdcSampleBuffer[KU8_FOUR][adcif_u8RawAdcSampleBufferIdx + KU8_ONE] = ADCIF_au16Group0Results[ADCIF_ENUM_GROUP0_ADC_MAG_V_5_1];
   adcif_au16RawAdcSampleBuffer[KU8_FOUR][adcif_u8RawAdcSampleBufferIdx + KU8_TWO] = ADCIF_au16Group0Results[ADCIF_ENUM_GROUP0_ADC_MAG_V_5_2];

   adcif_au16RawAdcSampleBuffer[KU8_FIVE][adcif_u8RawAdcSampleBufferIdx]           = ADCIF_au16Group0Results[ADCIF_ENUM_GROUP0_ADC_MAG_V_6];
   adcif_au16RawAdcSampleBuffer[KU8_FIVE][adcif_u8RawAdcSampleBufferIdx + KU8_ONE] = ADCIF_au16Group0Results[ADCIF_ENUM_GROUP0_ADC_MAG_V_6_1];
   adcif_au16RawAdcSampleBuffer[KU8_FIVE][adcif_u8RawAdcSampleBufferIdx + KU8_TWO] = ADCIF_au16Group0Results[ADCIF_ENUM_GROUP0_ADC_MAG_V_6_2];

   adcif_u8RawAdcSampleBufferIdx += KU8_THREE;

   if ( KU8_SIX == adcif_u8RawAdcSampleBufferIdx)
   {
      adcif_u8RawAdcSampleBufferIdx = KU8_ZERO;
   }

   (void)Rte_Write_prrAdcBufferServices_aau16HistoricalAdcSamples((uint16*)&adcif_au16RawAdcSampleBuffer[0][0]);

   (void)Rte_Write_prrAdcBufferServices_u8HistoricalAdcSampleIndex(adcif_u8RawAdcSampleBufferIdx);


}

/**
* \brief
*       Initialisation function of AdcIf component.
*       This service should initialise timer: LPIT0_Ch1 used in readings of samples from ADC pheripheral.
* \dynamicaspectcaller
*       EcuM SW Component.
* \dynamicaspectdescription
*       Called in EcuM Init list one. 
* \constrains
*       ADC Pheripheral must be initialised.
* \ddesignrequirement
*		DSG_AdcIf_runInit
* \archrequirement
*       ARCH_SW_AdcIf_ptrpAdcIfServicesBswMIf_AdcIf_runInit
*       ARCH_SW_AdcIf_ptrrAsrGptServicesAdcIf_Gpt_Init_AdcIf_runInit
*       ARCH_SW_AdcIf_ptrrAsrGptServicesAdcIf_Gpt_StartTimer_AdcIf_runInit
*       ARCH_SW_AdcIf_ptrrAsrGptServicesAdcIf_Gpt_EnableNotification_AdcIf_runInit
*       ARCH_SW_AdcIf_ptrrAsrAdcServices_Adc_StartGroupConversion_AdcIf_runInit
*/
EXPORTED void AdcIf_runInit(void)
{
   /* Initialise GPT timer on LPIT Channel 1 */
   Gpt_Init(&Gpt_Config_TDK_4G);

   /* Enable Notification function on GPT timer on LPIT Channel 1 */
   Gpt_EnableNotification(GptConf_GptChannelConfiguration_GPT_ADC_TIMER);

   /* Start GPT timer on LPIT Channel 1 */
   Gpt_StartTimer(GptConf_GptChannelConfiguration_GPT_ADC_TIMER, KU32_TIMER_INTERRUPT_RST_VALUE);

   /* Start ADC Measurements */
   Adc_StartGroupConversion(AdcGroup_0);
   Adc_StartGroupConversion(AdcGroup_1);
}

/**
* \brief
*       Calibration function of AdcIf component.
*       This service should call API generated from Tresos-configuration of ADC
*       in order to execute a calibration over ADC pheripheral.
* \dynamicaspectcaller
*       EcuM SW Component.
* \dynamicaspectdescription
*       Called in EcuM Init list one. 
* \constrains
*       ADC Pheripheral must be initialised.
* \ddesignrequirement
*		DSG_AdcIf_Calib
* \archrequirement
*       ARCH_SW_AdcIf_ptrpEcuMIfServicesAdcIf
*       ARCH_SW_AdcIf_ptrrAsrAdcServicesAdcIf_Adc_Calibrate_AdcIf_Calib
*/
EXPORTED void AdcIf_Calib(void)
{
   /*This variable is used to iterate in all Adc channels. */
   uint8 u8CalibAdcIndex = KU8_ZERO;

   ADCIF_stCalibrationStatus0.AdcUnitSelfTestStatus = (Std_ReturnType)E_NOT_OK;
   ADCIF_stCalibrationStatus1.AdcUnitSelfTestStatus = (Std_ReturnType)E_NOT_OK;

   for (u8CalibAdcIndex = KU8_ZERO;
      (u8CalibAdcIndex < KU8_ADCIF_CALIBRATE_INDEX_MAX) &&
      (
         (E_NOT_OK == ADCIF_stCalibrationStatus0.AdcUnitSelfTestStatus) ||
         (E_NOT_OK == ADCIF_stCalibrationStatus1.AdcUnitSelfTestStatus)
      );
      u8CalibAdcIndex++)
   {
      if (E_NOT_OK == ADCIF_stCalibrationStatus0.AdcUnitSelfTestStatus)
      {
         Adc_Calibrate(AdcGroup_0, &ADCIF_stCalibrationStatus0);
      }

      if (E_NOT_OK == ADCIF_stCalibrationStatus1.AdcUnitSelfTestStatus)
      {
         Adc_Calibrate(AdcGroup_1, &ADCIF_stCalibrationStatus1);
      }

   }
}

/**
* \brief
*       Deinitialisation function of AdcIf component.
*       This service should stop ADC pheripheral readings. 
* \dynamicaspectcaller
*       BswMIf SW Component.
* \dynamicaspectdescription
*       Called in BswM_OnGoOffOneA function.
* \constrains
*       ADC Pheripheral must be initialised.
* \ddesignrequirement
*		DSG_AdcIf_runDeInit
* \archrequirement
*       ARCH_SW_AdcIf_ptrpAdcIfServicesBswMIf_AdcIf_runDeInit
*       ARCH_SW_AdcIf_ptrrAsrAdcServicesAdcIf_Adc_StopGroupConversion_AdcIf_runDeInit
*/
EXPORTED void AdcIf_runDeInit(void)
{
   Adc_StopGroupConversion(AdcGroup_0);
   Adc_StopGroupConversion(AdcGroup_1);
}

/**
* \brief
*       Function used to return an ADC raw value from ADC buffer from a specific channel.
* \inputparam
*       Name: u8ChannelID;
*       Type: u8AdcChannelIDType;
*       Description: Id of an ADC Channel to measure;
*       Range: 
*       	KU8_ADC_CH_ID_PTC_TEMP
*       	KU8_ADC_CH_ID_V_BATT
*       	KU8_ADC_CH_ID_MAG_V_1
*       	KU8_ADC_CH_ID_MAG_V_2
*       	KU8_ADC_CH_ID_MAG_V_3
*       	KU8_ADC_CH_ID_MAG_V_4
*       	KU8_ADC_CH_ID_MAG_V_5
*       	KU8_ADC_CH_ID_MAG_V_6
*       	KU8_ADC_CH_ID_BOOST_DIAG
*       	KU8_ADC_CH_ID_V_REF_HIGH
*       	KU8_ADC_CH_ID_V_REF_LOW
*       	KU8_ADC_CH_V_ECU_TEMP_MCU_BAND_GAP
*       	KU8_ADC_CH_V_ECU_TEMP_MCU;
* \outputparam
*       Name: u16Value;
*       Type: u16AdcValueLsbType * ;
*       Description: LSB Raw value returned from ADC Channel;
*       Range: 0..1024 ( 10 bit ADC range );
* \dynamicaspectcaller
*       Autosar RTE SW Layer.
* \dynamicaspectdescription
*       Called in CIL, SAD, IoHwAb SW Components.
* \constrains
*       ADC Pheripheral must be initialised.
* \ddesignrequirement
*		DSG_AdcIf_runGetChannelValue
* \archrequirement
*       ARCH_SW_AdcIf_pseRawAdcService
*/
void AdcIf_runGetChannelValue (u8AdcChannelIDType u8ChannelID, P2VAR(u16AdcValueLsbType, AUTOMATIC, RTE_APPL_DATA) pu16Value)
{
   /* Search for the right channel */
   switch( u8ChannelID )
   {
      case KU8_ADC_CH_ID_PTC_TEMP:
         *pu16Value = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_ECU_TEMP_PTC];
      break;
      case KU8_ADC_CH_ID_V_BATT:
         *pu16Value = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_V_KL30];
      break;
      case KU8_ADC_CH_ID_MAG_V_1:
         *pu16Value = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_MAG_V_1];
      break;
      case KU8_ADC_CH_ID_MAG_V_2:
         *pu16Value = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_MAG_V_2];
      break;
      case KU8_ADC_CH_ID_MAG_V_3:
         *pu16Value = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_MAG_V_3];
      break;
      case KU8_ADC_CH_ID_MAG_V_4:
         *pu16Value = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_MAG_V_4];
      break;
      case KU8_ADC_CH_ID_MAG_V_5:
         *pu16Value = ADCIF_au16Group0Results[ADCIF_ENUM_GROUP0_ADC_MAG_V_5];
      break;
      case KU8_ADC_CH_ID_MAG_V_6:
         *pu16Value = ADCIF_au16Group0Results[ADCIF_ENUM_GROUP0_ADC_MAG_V_6];
      break;
      case KU8_ADC_CH_ID_V_REF_HIGH:
         *pu16Value = ADCIF_au16Group0Results[ADCIF_ENUM_GROUP0_ADC_REF_HIGH];
      break;
      case KU8_ADC_CH_ID_V_REF_LOW:
         *pu16Value = ADCIF_au16Group0Results[ADCIF_ENUM_GROUP0_ADC_REF_LOW];
      break;
      case KU8_ADC_CH_V_ECU_TEMP_MCU_BAND_GAP:
          *pu16Value = ADCIF_au16Group0Results[ADCIF_ENUM_GROUP0_ADC_ECU_TEMP_MCU_VREF];
      break;
      case KU8_ADC_CH_V_ECU_TEMP_MCU:
          *pu16Value = ADCIF_au16Group0Results[ADCIF_ENUM_GROUP0_ADC_ECU_TEMP_MCU];
      break;
      case KU8_ADC_CH_ID_WAKE_1:
          *pu16Value = ADCIF_au16Group0Results[ADCIF_ENUM_GROUP0_ADC_WAKE_1];
      break;
      case KU8_ADC_CH_ID_WAKE_2:
          *pu16Value = ADCIF_au16Group0Results[ADCIF_ENUM_GROUP0_ADC_WAKE_2];
      break;
      case KU8_ADC_CH_ID_BOOST_DIAG:
          *pu16Value = ADCIF_au16Group1Results[ADCIF_ENUM_GROUP1_ADC_BOOST_DIAG];
      break;
      default:
      /* Wrong ID or channel not used yet on the PCB */
          *pu16Value = KU16_ZERO;
      break;
   }
}

#define AdcIf_STOP_SEC_CODE_ASIL_A
#include "AdcIf_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
