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
$Revision: 1.17 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/IoHwAb/Quality_Assurance/Static_Analysis/project.pj $
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
#include "EFX_Filter.h"
#include "Math.h"
#include "Nvp_Cfg.h"
#include "Rte_Intern.h"
#include "stdlib.h"
#include "Os.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/


/* Solenoid regarded parameters */

/**
 *\brief
 *     Macro used to compute temperature value from the internal MCU sensor
 */
#define KU32_IOHWAB_MCU_BANDGAP_NUMERATOR          ((uint32) 1000)

/**
 *\brief
 *     Macro used to compute temperature value from the internal MCU sensor
 */
#define KS32_IOHWAB_MCU_T_SENS_SLOPE_NUMERATOR     ((sint32)162)

/**
 *\brief
 *     Macro used to compute temperature value from the internal MCU sensor.
 *     Reference value in *C for calculation.
 */
#define KS32_IOHWAB_MCU_T_SENS_REF_TEMPERATURE     ((sint32)25)

/**
 *\brief
 *     Macro used to compute temperature value from the internal MCU sensor
 */
#define KS32_IOHWAB_MCU_T_SENS_SLOPE_DENOMINATOR   ((sint32) 100)

/**
 *\brief
 *     Macro used to compute temperature value from the internal MCU sensor.
 *     Temperature sensor output in uV at its reference temperature.
 */
#define KS32_IOHWAB_MCU_T_SENS_TEMP_REF_MV         ((sint32) 755)

/**
 *\brief
 *     Macro used to initialize global temperature variables
 */
#define KS16_IOHWAB_DEFAULT_TEMPERATURE            ((sint16) 25)


/* MACROS USED TO COMPUTE CURRENT FROM PWM VALUE */

/**
 *\brief
 *      Coefficient calculated from  ( R545 / R544 ) + 1. Formula: 
 *       o VU503_3 = VPWM *( ( R545 / R544 ) + 1  );
 *       o R545 has a value of 8.2 KOhms and R544 has a value of 2.2 kOhms;
 *       o ( R545 / R544 ) + 1 = ( 8.2 / 2.2 ) + 1 = 4.72;
 *      In order to also use decimals, will be multiplied by 100 and divided by 100.
 */
#define KU32_IOHWAB_PWM_RESISTANCE_COEFFICIENT     ((uint32)472)

/**
 *\brief
 *      PWM Reference voltage in milli-volts
 *
 */
#define KU16_IOHWAB_PWM_REFERENCE                  ((uint16)5000)

/**
 *\brief
 *      Percent value for PWM Duty Cycle conversion
 *
 */
#define KU32_IOHWAB_PERCENT                        ((uint32)100)

/**
 *\brief
 *      Coefficient used in division to convert units from micro-volts to milli-volts
 *
 */
#define KU32_IOHWAB_CONVERSION_UNIT                ((uint32)1000)

/**
 *\brief
 *      PWM boost voltage in milli-volts
 *
 */
#define KU16_IOHWAB_PWM_BOOST_VOLTAGE              ((uint16)24170)

/**
 *\brief
 *      Buck resistance in ohms
 *
 */
#define KU32_IOHWAB_BUCK_RESISTANCE                ((uint32) 34)

/**
 *\brief
 *      Lowest temperature accepted by solenoid
 *
 */
#define KS8_IOHWAB_SOLENOID_LOWEST_TEMP            ((sint8) -40)

/**
 *\brief
 *      Highest temperature accepted by solenoid
 *
 */
#define KU8_IOHWAB_SOLENOID_HIGHEST_TEMP           ((uint8) 80)

/**
 *\brief
 *      Temperature offset for cast solenoid temperature
 *
 */
#define KS16_IOHWAB_SOLENOID_TEMP_OFFSET           ((sint16) 40)

/**
 *\brief
 *      Number of solenoid samples for temperature-resistance calculation
 *
 */
#define KU8_IOHWAB_SOLENOID_NB_OF_SAMPLES          ((uint8) 8)

/**
 *\brief
 *      Max PWM Duty Cycle value
 *
 */
#define KU8_MAX_PWM_DUTY_CYCLE                     ((uint8) 99)

/* PTC SENSOR MACROS */
/**
 *\brief
 *      Bias resistor value in ohms
 */
#define KU32_IOHWAB_BIAS_RESISTOR_VALUE            ((uint32)10000)

/**
 *\brief
 *      Bias voltage of PTC sensor in milli-volts
 *
 */
#define KU32_IOHWAB_BIAS_VOLTAGE                   ((uint32)5000)

/**
 *\brief
 *      Length of interpolation table of PTC sensor from NVP_Calibration
 *
 */
#define KU8_IOHWAB_PTC_LOOKUP_TABLE_LENGTH             ((uint8) 34)

/* STATE MACHINE MACROS */

/**
 *\brief
 *      Definition for buffer length for ADC readings
 *
 */
#define KU8_IOHWAB_ADC_BUFFER_SIZE                 ((uint8) 50)

/**
 *\brief
 *      Definition for percentage offset to check when constructing trend array
 *
 */
#define KU16_IOHWAB_OFFSET_PERCENTAGE              ((uint16) NVP_u8DetectionOffsetPer)

/**

 *\brief
 *      Definition for percentage plateau to check when constructing trend array
 *
 */
#define KU16_IOHWAB_PLATEAU_PERCENTAGE             ((uint16) NVP_u8DetectionPlateauPer)

/**
 *\brief
 *      PTC Sensor percentage of MCU temp
 *
 */
#define KU8_IOHWAB_PTC_PERCENTAGE                  ((uint8) NVP_u8PTCTempPer)

/**
 *\brief
 *      ADC state seat occupancy on and buckle not plugged
 *
 */
#define KU8_IOHWAB_SEAT_OCC_BELT_NOT_PLUG          ((uint8) 0)

/**
 *\brief
 *      ADC state seat occupancy off and buckle not plugged
 *
 */
#define KU8_IOHWAB_SEAT_NOT_OCC_BELT_NOT_PLUG      ((uint8) 1)

/**
 *\brief
 *      ADC state buckle plugged
 *
 */
#define KU8_IOHWAB_BELT_PLUG                       ((uint8) 2)

/**
 *\brief
 *      ADC seat state short definition
 */
#define KU8_IOHWAB_SEAT_SHORT_STATE                ((uint8)3)

/**
 *\brief
 *      ADC seat state undefined definition
 *
 */
#define KU8_IOHWAB_SEAT_UNDEFINED_STATE            ((uint8)4)


/**
 *\brief
 *      PWM Conversion factor used in KL30 conversions
 *
 */
#define KU16_IOHWAB_PWM_CONVERSION_FACTOR          ((uint16) 772)

/**
 *\brief
 *      Measurements array initialization values.
 *      This value represents first initialization of old measurements
 *      array used in iohwab_DetectVoltageFluctuationOnSolenoid function.
 */
#define KU16_IOHWAB_ADC_MEAS_INIT_MV               ((uint16) 25000)

/**
 *\brief
 *      Search state check macro definition used in SearchState API
 *
 */
#define KU8_IOHWAB_SEARCH_STATE_CHECK              ((uint8) KU8_IOHWAB_SEAT_UNDEFINED_STATE*KU8_FOUR )

/**
 *\brief
 *      Max Temperature value (*C)
 *
 */
#define KS16_IOHWAB_MAX_TEMPERTATURE_VAL           ((sint16) 180)

/**
 *\brief
 *      Min Temperature value (*C)
 *
 */
#define KS16_IOHWAB_MIN_TEMPERTATURE_VAL           ((sint16) -80)

/**
*\brief
*      Voltage dropout for KL30 measurements in milli-volts
*
*/
#define KU16_KL30_VOLTAGE_DROPOUT           ((uint16) 122)

/**
*\brief
*      Solenoid unlock detection algo first state
*
*/
#define KU8_IOHWAB_FIRST_PEAK_SEARCH_STATE     ((uint8) 0)

/**
*\brief
*      Solenoid unlock detection algo second state
*
*/
#define KU8_IOHWAB_FIRST_VALLEY_SEARCH_STATE   ((uint8) 1)

/**
*\brief
*      Solenoid unlock detection algo last state
*
*/
#define KU8_IOHWAB_SECOND_PEAK_SEARCH_STATE    ((uint8) 2)

/**
*\brief
*      Current offset per each solenoid current computation
*
*/
#define KU16_IOHWAB_CURRENT_OFFSET              ((uint16) 4)

/**
*\brief
*      Maximum value that should be read with the 4ma circuit.
*
*/
#define KU16_IOHWAB_SEAT_CIRCUT_4MA_LIMIT       ((uint16)0x332)

/**
*\brief
*      Value to be added to adc reading when using 1ma circuit
*
*/
#define KU16_IOHWAB_SEAT_CIRCUT_1MA_THRES       ((uint16)0x400)
/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
LOCAL sint16 iohwab_GetPTCSensorTemp(uint16 u16RawADCValue);
LOCAL sint16 iohwab_computeSolenoidTemperature(uint16 u16SolenoidVoltage, uint16 u16SolenoidCurrent);
LOCAL void iohwab_SearchState(const uint16 * pkau16Thres,const uint16 * pkau16ThresNext, uint8* pu8WakeState, uint16 u16AdcVal);
LOCAL void iohwab_ReportSeatStatus(void);
LOCAL void iohwab_DetectSeatOccupancy(uint16 u16WakeCh1, uint16 u16WakeCh2);
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

#define IoHwAb_START_SEC_VAR_INIT_BOOL_ASIL_A
#include "IoHwAb_MemMap.h"

/**
 * \brief
 *       Used to store the Rte return status that signals that the corresponding
 *       sender receiver inteface has been previously written before read.
 * \initialization
 *       FALSE (boolean 0).
 * \range
 *       FALSE
 *       TRUE;
 */
LOCAL boolean iohwab_bRteIsau8SelectedProfileUpdated = FALSE;

/**
 * \brief
 *       Used to store the Rte return status that signals that the corresponding
 *       sender receiver inteface has been previously written before read.
 * \initialization
 *       FALSE (boolean 0).
 * \range
 *       FALSE
 *       TRUE;
 */
LOCAL boolean iohwab_bRteIsaau8CurrentStepUpdated = FALSE;

/**
 * \brief
 *       Used to store the Rte return status that signals that the corresponding
 *       sender receiver inteface has been previously written before read.
 * \initialization
 *       FALSE (boolean 0).
 * \range
 *       FALSE
 *       TRUE;
 */
LOCAL boolean iohwab_bRteIsaau16HistoricalAdcSamplesUpdated = FALSE;

/**
 * \brief
 *       Used to store the Rte return status that signals that the corresponding
 *       sender receiver inteface has been previously written before read.
 * \initialization
 *       FALSE (boolean 0).
 * \range
 *       FALSE
 *       TRUE;
 */
LOCAL boolean iohwab_bRteIsu8HistoricalAdcSampleIndexUpdated = FALSE;

#define IoHwAb_STOP_SEC_VAR_INIT_BOOL_ASIL_A
#include "IoHwAb_MemMap.h"

#define IoHwAb_START_SEC_VAR_INIT_8_ASIL_A
#include "IoHwAb_MemMap.h"

/**
 *\brief
 *     This variable will retain the times the read wake input  function is called.
 *\initialization 
 *	   KU8_ZERO.
 */
LOCAL uint8 iohwab_u8WakeCounter = KU8_ZERO;

/**
 *\brief
 *     This array is used to retain the previous state of the buckle. 
 *\initialization 
 *     KU8_IOHWAB_UNDEFINED.
 */
LOCAL uint8 iohwab_au8WakeSensePrevState[KU8_TWO] = {KU8_IOHWAB_SEAT_UNDEFINED_STATE, KU8_IOHWAB_SEAT_UNDEFINED_STATE};

/**
 *\brief
 *     This array is used to retain the current state of the buckle. 
 *\initialization 
 *	   KU8_IOHWAB_UNDEFINED.
 */
LOCAL uint8 iohwab_au8WakeSenseCurrState[KU8_TWO] = {KU8_IOHWAB_SEAT_UNDEFINED_STATE, KU8_IOHWAB_SEAT_UNDEFINED_STATE};

/**
 *\brief
 *     This array will count how many ADC samples has been aquired per every solenoid.
 *\initialization 
 *	   None.
 */
LOCAL uint8 iohwab_au8SampleCounter[KU8_MAX_SOLENOID_NB] = {
      KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO
};

/**
 *\brief
 *     This array will hold state machine case per each solenoid.
 *\initialization
 *     KU16_ZERO.
 */
LOCAL uint8 iohwab_au8StateMachineCase[KU8_MAX_SOLENOID_NB] = {
   KU8_ZERO,KU8_ZERO,KU8_ZERO,KU8_ZERO,KU8_ZERO,KU8_ZERO
};

/**
 *\brief
 *     This array will hold the number of slopes determined for each solenoid.
 *\initialization
 *     KU16_ZERO.
 */
LOCAL uint8 iohwab_au8NoOfConsecutiveSlopes[KU8_MAX_SOLENOID_NB][KU8_THREE] = {
   {KU8_ZERO, KU8_ZERO, KU8_ZERO},
   {KU8_ZERO, KU8_ZERO, KU8_ZERO},
   {KU8_ZERO, KU8_ZERO, KU8_ZERO},
   {KU8_ZERO, KU8_ZERO, KU8_ZERO},
   {KU8_ZERO, KU8_ZERO, KU8_ZERO},
   {KU8_ZERO, KU8_ZERO, KU8_ZERO}
};

/**
 *\brief
 *     This array will hold peak points indexes determined for each solenoid.
 *\initialization
 *     KU8_ZERO.
 */
LOCAL uint8 iohwab_au8PeakPointsIdx[KU8_MAX_SOLENOID_NB][KU8_THREE] = {
   {KU8_ZERO, KU8_ZERO, KU8_ZERO},
   {KU8_ZERO, KU8_ZERO, KU8_ZERO},
   {KU8_ZERO, KU8_ZERO, KU8_ZERO},
   {KU8_ZERO, KU8_ZERO, KU8_ZERO},
   {KU8_ZERO, KU8_ZERO, KU8_ZERO},
   {KU8_ZERO, KU8_ZERO, KU8_ZERO}
};

#define IoHwAb_STOP_SEC_VAR_INIT_8_ASIL_A
#include "IoHwAb_MemMap.h"

#define IoHwAb_START_SEC_VAR_NO_INIT_8_ASIL_A
#include "IoHwAb_MemMap.h"

/**
 *\brief
 *     This array will hold the unlock confirmation for all solenoids.
 *\initialization 
 *     None.
 */
LOCAL uint8 iohwab_au8SolenoidUnlockConfirmation[sizeof(au8SolenoidUnlockConfirmationType)];

#define IoHwAb_STOP_SEC_VAR_NO_INIT_8_ASIL_A
#include "IoHwAb_MemMap.h"

#define IoHwAb_START_SEC_VAR_NO_INIT_16_ASIL_A
#include "IoHwAb_MemMap.h"

/**
 *\brief
 *     This array is used to retain filtered values of ADC solenoid current raw values.
 *\initialization 
 *     KU16_ZERO.
 */
LOCAL uint16 iohwab_au16FilteredValue10ms[KU8_ADC_CH_ID_V_BATT_10_MS+KU8_ONE];

/**
 *\brief
 *     This array is used to retain filtered values of ADC solenoid current raw values.
 *\initialization 
 *     KU16_ZERO.
 */
LOCAL uint16 iohwab_au16FilteredValue100ms[KU8_ADC_CH_ID_V_BATT_10_MS+KU8_ONE];

/**
 *\brief
 *     This array will hold integral buffer values in milivolts per each solenoid.
 *\initialization
 *     KU16_ZERO.
 */
LOCAL uint16 iohwab_au16IntegralBuffer[KU8_MAX_SOLENOID_NB][KU8_FIVE];

#define IoHwAb_STOP_SEC_VAR_NO_INIT_16_ASIL_A
#include "IoHwAb_MemMap.h"

#define IoHwAb_START_SEC_VAR_INIT_16_ASIL_A
#include "IoHwAb_MemMap.h"


/**
 *\brief
 *     This variable hold the global temperature value for the Accelerometer sensor.
 *\initialization 
 *     KS16_IOHWAB_DEFAULT_TEMPERATURE.
 */
LOCAL sint16 iohwab_s16LocalAccTemp = KS16_IOHWAB_DEFAULT_TEMPERATURE;

/**
 *\brief
 *     This variable hold the global temperature value for the MCU sensor.
 *\initialization 
 *     KS16_IOHWAB_DEFAULT_TEMPERATURE.
 */
LOCAL sint16 iohwab_s16LocalMcuTemp = KS16_IOHWAB_DEFAULT_TEMPERATURE;

/**
 *\brief
 *     This variable hold the global temperature value for the PTC resistor sensor.
 *\initialization 
 *     KS16_IOHWAB_DEFAULT_TEMPERATURE.
 */
LOCAL sint16 iohwab_s16LocalPtcTemp = KS16_IOHWAB_DEFAULT_TEMPERATURE;

/**
 *\brief
 *     This variable hold the global temperature value for the ECU.
 *\initialization 
 *     KS16_IOHWAB_DEFAULT_TEMPERATURE.
 */
LOCAL sint16 iohwab_s16LocalEcuTemp = KS16_IOHWAB_DEFAULT_TEMPERATURE;

/**
 *\brief
 *     This array holds last valid values of temperature of solenoid.
 *\initialization 
 *     KS16_ZERO.
 */
LOCAL sint16 iohwab_as16LocalSolenoidTemp[KU8_GLOBAL_NUMBER_OF_SOLENOIDS] = {
   KS16_ZERO, KS16_ZERO, KS16_ZERO, KS16_ZERO, KS16_ZERO, KS16_ZERO
};

/**
 *\brief
 *     This array will hold derivate computed values in milivolts per each solenoid.
 *\initialization
 *     KU16_ZERO.
 */
LOCAL uint16 iohwab_au16DerivativeComputation[KU8_MAX_SOLENOID_NB] = {
   KU16_ZERO,KU16_ZERO,KU16_ZERO,KU16_ZERO,KU16_ZERO,KU16_ZERO
};

/**
 *\brief
 *     This array will hold integral computed values in milivolts per each solenoid.
 *\initialization
 *     KU16_ZERO.
 */
LOCAL uint16 iohwab_au16IntegralComputation[KU8_MAX_SOLENOID_NB] = {
   KU16_ZERO,KU16_ZERO,KU16_ZERO,KU16_ZERO,KU16_ZERO,KU16_ZERO
};

/**
 *\brief
 *     This array will buffer ADC computed values in milivolts per each solenoid.
 *\initialization
 *     KU16_ZERO.
 */
LOCAL uint16 iohwab_au16SampleBuffer[KU8_MAX_SOLENOID_NB][KU8_TWO] = {
   {KU16_ZERO, KU16_ZERO},
   {KU16_ZERO, KU16_ZERO},
   {KU16_ZERO, KU16_ZERO},
   {KU16_ZERO, KU16_ZERO},
   {KU16_ZERO, KU16_ZERO},
   {KU16_ZERO, KU16_ZERO}
};

/**
 *\brief
 *     This array will buffer computed integral and derivate values in milivolts per each solenoid.
 *\initialization
 *     KU16_ZERO.
 */
LOCAL uint16 iohwab_au16ComputedSampleBuffer[KU8_MAX_SOLENOID_NB][KU8_TWO] = {
   {KU16_ZERO, KU16_ZERO},
   {KU16_ZERO, KU16_ZERO},
   {KU16_ZERO, KU16_ZERO},
   {KU16_ZERO, KU16_ZERO},
   {KU16_ZERO, KU16_ZERO},
   {KU16_ZERO, KU16_ZERO}
};

/**
 *\brief
 *     This array will hold peak points determined for each solenoid.
 *\initialization
 *     KU16_ZERO.
 */
LOCAL uint16 iohwab_au16PeakPoints[KU8_MAX_SOLENOID_NB][KU8_THREE] = {
   {KU16_ZERO, KU16_MAX, KU16_ZERO},
   {KU16_ZERO, KU16_MAX, KU16_ZERO},
   {KU16_ZERO, KU16_MAX, KU16_ZERO},
   {KU16_ZERO, KU16_MAX, KU16_ZERO},
   {KU16_ZERO, KU16_MAX, KU16_ZERO},
   {KU16_ZERO, KU16_MAX, KU16_ZERO}
};

#define IoHwAb_STOP_SEC_VAR_INIT_16_ASIL_A
#include "IoHwAb_MemMap.h"

#define IoHwAb_START_SEC_VAR_INIT_32_ASIL_A
#include "IoHwAb_MemMap.h"

/**
 *\brief
 *     This array will hold PWM values computed in SAD.
 *\initialization
 *     KU32_ZERO.
 */
LOCAL uint32 iohwab_au32PwmCurrentValue[KU8_MAX_SOLENOID_NB] = {KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO};

#define IoHwAb_STOP_SEC_VAR_INIT_32_ASIL_A
#include "IoHwAb_MemMap.h"
/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
#define IoHwAb_START_SEC_CONST_16_ASIL_A
#include "IoHwAb_MemMap.h"

/**
 *\brief
 *     This constant array holds the sin computation per each solenoid.
 *     This array is computed as follow:
 *      o ARRAY_VALUE[ANGLE_VALUE_IN_DEGREE]  =
 *          SINE(ANGLE_VALUE_IN_DEGREE) * 847;
 *      o  where 847 is determined by the simple rule of 3;
 *      o MAX_SAMPLE.....................MAX_SOLENOID_VOLTAGE;
 *      o 1................................................................x;
 *      o x = ( 33000mV * 1 )/39 => 847;
 *     Usage iohwab_au16DegreeToSineAngle(30 degrees) will be slope
 *     between 2 plotted points.
 */
LOCAL const uint16 iohwab_kau16DegreeToSineAngle[KU8_NINETY] = {
   0, 15, 30, 44, 59, 74, 89, 104, 119, 134, 149, 165, 180,
   196, 211, 227, 243, 259, 275, 292, 308, 325, 342, 360, 377,
   395, 413, 432, 450, 469, 489, 509, 529, 550, 571, 593, 615,
   638, 662, 686, 711, 736, 763, 790, 818, 847, 877, 908, 941,
   974, 1009, 1046, 1084, 1124, 1166, 1210, 1256, 1304, 1355,
   1410, 1467, 1528, 1593, 1662, 1737, 1816, 1902, 1995, 2096,
   2207, 2327, 2460, 2607, 2770, 2954, 3161, 3397, 3669, 3985,
   4357, 4804, 5348, 6027, 6898, 8059, 9681, 12113, 16162, 24255, 48525
};

#define IoHwAb_STOP_SEC_CONST_16_ASIL_A
#include "IoHwAb_MemMap.h"

#define IoHwAb_START_SEC_CONST_8_ASIL_A
#include "IoHwAb_MemMap.h"
/**
 *\brief
 *     LookUp table for wakeup conditions. The first index is previous state,
 *     second index in current state.
 */
LOCAL const uint8 iohwab_kau8WakeupMatrix[KU8_FIVE][KU8_FIVE] = {
   { KU8_FALSE, KU8_TRUE,  KU8_TRUE,  KU8_FALSE, KU8_FALSE},
   { KU8_FALSE, KU8_FALSE, KU8_TRUE,  KU8_FALSE, KU8_FALSE},
   { KU8_TRUE,  KU8_TRUE,  KU8_FALSE, KU8_FALSE, KU8_FALSE},
   { KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE},
   { KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE}
};

#define IoHwAb_STOP_SEC_CONST_8_ASIL_A
#include "IoHwAb_MemMap.h"

#define IoHwAb_START_SEC_CONST_UNSPECIFIED_ASIL_A
#include "IoHwAb_MemMap.h"

/**
 *\brief
 *      Interpolation table for solenoid resistance.
 *      USED IN CALCULATION OF SOLENOID TEMPERATURE BASED ON A SPECIFIC RESISTANCE.
 *      INPUT - RESISTANCE, OUTPUT - TEMPERATURE.
 */
LOCAL const stInterpolationParam_Type iohwab_kstLookUpTableREStoTEMP = {
   (const uint8*)(&NVP_as16SolenoidRes[KU8_ZERO]), /* x_table: vector with axis values */
   (const uint8*)(&NVP_as16SolenoidTemp[KU8_ZERO]), /* y_table: vector with axis values */
   KU8_IOHWAB_SOLENOID_NB_OF_SAMPLES,
   KU8_X16_LIndian | KU8_Y16_LIndian,
   KU8_IN_RANGE_LINEAR_INTER | KU8_BELOW_RANGE_UPPER_INTER | KU8_OVER_RANGE_LOWER_INTER
};

/**
 * \brief
 *       This array holds the configuration mask of each solenoid based on what
 *       flag to check.
 * \initialization
 *       {KU64_SOLENOID_X_CONFIGURED} where X - the solenoid number.
 * \range
 *       0..KU64_MAX.
 */
LOCAL const uint64 iohwab_kau64SolenoidConfigMask[KU8_MAX_SOLENOID_NB] =
{
   /* Solenoid 1 */ (KU64_SOLENOID_1_CONFIGURED),
   /* Solenoid 2 */ (KU64_SOLENOID_2_CONFIGURED),
   /* Solenoid 3 */ (KU64_SOLENOID_3_CONFIGURED),
   /* Solenoid 4 */ (KU64_SOLENOID_4_CONFIGURED),
   /* Solenoid 5 */ (KU64_SOLENOID_5_CONFIGURED),
   /* Solenoid 6 */ (KU64_SOLENOID_6_CONFIGURED)
};

#define IoHwAb_STOP_SEC_CONST_UNSPECIFIED_ASIL_A
#include "IoHwAb_MemMap.h"
/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/
/**
 *\brief
 *      Macro like function used to compute voltage IN MILLIVOLTS of ADC through resistors division.
 *      This will measure voltage of ADC using formula
 *      ( ADC_RAW_VALUE * ADC_REFERENCE (5000 mV) ) / ADC_RANGE ( 1023 ) * RESISTOR DIVISION, where:
 *      	o RESISTOR DIVISION = ( 56Kohm + 10KOhm ) / 10 KOhm;
 *      The formula becomes:
 *          o ( ADC_RAW_VALUE *ADC_REFERENCE (5000 mV) *( 56Kohm + 10KOhm ) ) / ADC_RANGE ( 1023* ) *10 KOhm;
 *      After some simplification of macros, the formula becomes:
 *          o ADC_VALUE_IN_mV = ( ADC_RAW_VALUE * 32.2580 );
 *      Because the existence of the "." in constant, the constant will be multiplied with 10000 and final
 *      calculation will be divided by 10000. The final calculation becomes:
 *          o ADC_VALUE_IN_mV = ( ADC_RAW_VALUE * 322580 ) / 10000;
 *      This macro cast to uint16 will not overflow because maximum voltage read by ADC is 30V.
 */
#define KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(u16RawAdc)  \
         (uint16)( (uint32)( (uint32)(u16RawAdc) *(uint32)(322580u) ) / (uint32)(10000u))

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
#define IoHwAb_START_SEC_CODE_ASIL_A
#include "IoHwAb_MemMap.h"
/**
* \brief
*       Function used to compute temperature from raw values readed by ADC pheripheral of PTC sensor. 
* \inputparam
*       Name: u16RawADCValue;
*       Type: uint16;
*       Description: Input raw ADC value from PTC sensor;
*       Range: 0..ADC Range;
* \pre
*       ADC Pheripheral must be initialised.
* \return
*       Temperature output from PTC sensor in degrees celsius.
*       Output value will be in range -40..80.
* \dynamicaspectcaller
*       IoHwAb SW Component.
* \dynamicaspectdescription
*       API called by function IoHwAb_GetPtcTemperature.
* \constrains
*       Input value must be in range 0..1024.
* \ddesignrequirement
*       DSG_IoHwAb_GetPTCSensorTemp
* \archrequirement
*       ARCH_SW_IoHwAb_psePtcSensor
*/
LOCAL inline sint16 iohwab_GetPTCSensorTemp(uint16 u16RawADCValue)
{
   register uint32 u32SensorVoltage = KU32_ZERO;
   register uint16 u16SensorResistance = KU16_ZERO;
   register uint8  u8Counter = KU8_ZERO;
   register sint16 s16SensorTemperature = KS16_ZERO;

   register sint16 s16X1 = KS16_ZERO;
   register sint16 s16X2 = KS16_ZERO;
   register sint16 s16Y1 = KS16_ZERO;
   register sint16 s16Y2 = KS16_ZERO;

   register boolean bValueFound = B_FALSE;

   /* Compute voltage across temperature sensor in milivolts. */
   /* Will not overflow because voltage will be a very low value */
   u32SensorVoltage = (uint32)(((uint32)u16RawADCValue * KU32_IOHWAB_BIAS_VOLTAGE ) / KU16_IOHWAB_ADC_FULL_RANGE );

   /* Compute sensor resistance from sensor voltage in ohms */
   u16SensorResistance = (uint16)( (u32SensorVoltage * KU32_IOHWAB_BIAS_RESISTOR_VALUE ) / ( KU32_IOHWAB_BIAS_VOLTAGE - u32SensorVoltage) );

   for (u8Counter = KU8_ONE; ((KU8_IOHWAB_PTC_LOOKUP_TABLE_LENGTH > u8Counter) && (B_FALSE == bValueFound)); u8Counter++)
   {
      /* the linear interpolation process is y = y1 + ((x - x1) / (x2 - x1)) * (y2 - y1) */
      if (NVP_as16PTCRes[u8Counter] >= u16SensorResistance)
      {
         s16X1 = NVP_as16PTCRes[u8Counter - KU8_ONE];
         s16X2 = NVP_as16PTCRes[u8Counter];
         s16Y1 = NVP_as16PTCTemp[u8Counter - KU8_ONE];
         s16Y2 = NVP_as16PTCTemp[u8Counter];
      
         s16SensorTemperature = s16Y1 + ((((((sint16)u16SensorResistance - s16X1) * (sint16)KU32_IOHWAB_CONVERSION_UNIT) / (s16X2 - s16X1)) * (s16Y2 - s16Y1)) / (sint16)KU32_IOHWAB_CONVERSION_UNIT);  // Use the low value resistance and temperature
         bValueFound = B_TRUE;
         
      }
   }

   return s16SensorTemperature;
}

/**
* \brief
*       Function used to compute solenoid temperature from solenoid voltage and current.
* \inputparam
*       Name: u16SolenoidVoltage;
*       Type: uint16;
*       Description: Solenoid Voltage in mV;
*       Range: 0..20000;
* \outputparam
*       Name: u16SolenoidCurrent;
*       Type: uint16;
*       Description: Solenoid Voltage in mA;
*       Range: 0..1000;
* \pre
*       Solenoid Voltage and current must be computed. 
* \return
*       Computed temperature in degrees celsius based on interpolation table.     
* \dynamicaspectcaller
*       IoHwAb SW Component.
* \dynamicaspectdescription
*       API called by function IoHwAb_GetSolenoidTemperature.
* \constrains
*       Output returned value must be in range -40..80. 
* \ddesignrequirement
*       DSG_IoHWAb_computeSolenoidTemperature
* \archrequirement
*       ARCH_SW_IoHwAb_pseSolenoidCharacterstics
*/
LOCAL inline sint16 iohwab_computeSolenoidTemperature(uint16 u16SolenoidVoltage, uint16 u16SolenoidCurrent)
{
   register uint16 u16SolenoidTempWithOffset;
   register sint16 s16SolenoidTemp;
   register uint32 u32SolenoidResistance;

   /* Make sure all divisions are made below 0 */
   if (KU16_ZERO == u16SolenoidCurrent)
   {
      u16SolenoidCurrent = KU16_ONE;
   }

   /* Make sure obtaining values always positive */
   if (KU16_ZERO == u16SolenoidVoltage)
   {
      u16SolenoidVoltage = KU16_ONE;
   }

   /* Compute Solenoid Resistance in milliohms */
   u32SolenoidResistance = (uint32)( (uint32)u16SolenoidVoltage / (uint32)u16SolenoidCurrent ) * KU32_IOHWAB_CONVERSION_UNIT;

   /* Get Solenoid Temperature IN degrees celsius. */
   /* This temperature has an offset added with 40 degrees because interpolation function does not support signed values */
   u16SolenoidTempWithOffset = (uint16)u32InterpolateFromTable(u32SolenoidResistance, &iohwab_kstLookUpTableREStoTEMP);

   /* Get temperature without offset */
   s16SolenoidTemp = (sint16)u16SolenoidTempWithOffset - KS16_IOHWAB_SOLENOID_TEMP_OFFSET;

   return s16SolenoidTemp;
}

/**
* \brief
*       Function used to implement a state machine.
*       The main usage of the state machine is to check if the solenoid has been activated
*       and to send a confirmation message over diagnostic services.
* \inputparam
*       Name: u8SolenoidIdx;
*       Type: uint8;
*       Description: Index of solenoid to be checked;
*       Range:
*          KU8_ADC_CH_ID_MAG_V_1
*          KU8_ADC_CH_ID_MAG_V_2
*          KU8_ADC_CH_ID_MAG_V_3
*          KU8_ADC_CH_ID_MAG_V_4
*          KU8_ADC_CH_ID_MAG_V_5
*          KU8_ADC_CH_ID_MAG_V_6;
* \dynamicaspectcaller
*       IoHwAb SW Component.
* \dynamicaspectdescription
*       API called in IoHwAb_DetectVoltageFluctuation to determine solenoid state.
* \constrains
*       ADC pherihperal must be initialised.
* \ddesignrequirement
*       DSG_iohwab_DetectVoltageFluctuationOnSolenoid
* \archrequirement
*       ARCH_SW_BswMIf_ptrpAsrOsServicesIoHwAb_IoHwAb_DetectVoltageFluctuation
*       ARCH_SW_IoHwAb_pclSolenoidProfile
*       ARCH_SW_IoHwAb_pclUnlockTimeout
*       ARCH_SW_AdcIf_prrAdcBufferServices_AdcIf_GPTOnTimer_Expiration
*       ARCH_SW_IoHwAb_prrAdcBufferServices_IoHwAb_DetectVoltageFluctuation
*/

LOCAL void iohwab_DetectVoltageFluctuationOnSolenoid(uint8 u8SolenoidIdx)
{
   uint16 u16SolenoidRawValue;
   uint16 u16SolenoidVoltage;

   uint8 au8SelectedProfile[sizeof(au8SolenoidProfileType)];
   uint8 au8CurrentStep[sizeof(au8CurrentStepType)];
   uint16 u16UnlockProfileTimeout;
   uint16 u16SlopeDiff;

   uint16 u16AdcRawBuffer[KU8_MAX_SOLENOID_NB][KU8_SIX];
   uint8 u8RawIndex;

   uint8 u8BlockIndex;
   uint8 u8SampleIdx;
   uint8 u8PeaksPositionDiff;

   /* Interface used to check current profile in order to avoid detection of a false confirmation signal */
   Rte_Read_pclSolenoidProfile_au8SelectedProfile(au8SelectedProfile);

   /* Get current step from profile definition */
   Rte_Read_pclSolenoidStep_au8CurrentStep(au8CurrentStep);

   /* Call interface to get timeout */
   Rte_Call_pclUnlockTimeout_getUnlockTimeoutPeriod(&u16UnlockProfileTimeout);

   /* Get data from AdcIf in raw samples */
   Rte_Read_prrAdcBufferServices_aau16HistoricalAdcSamples((uint16*)&u16AdcRawBuffer[0][0]);

   Rte_Read_prrAdcBufferServices_u8HistoricalAdcSampleIndex(&u8RawIndex);


   if ((KU8_PROFILE_UNLOCK == au8SelectedProfile[u8SolenoidIdx] ) || (KU8_PROFILE_BACKUP == au8SelectedProfile[u8SolenoidIdx] ))
   {
      if ((KU8_FIVE != au8CurrentStep[u8SolenoidIdx] ) && (KU8_MAX != au8CurrentStep[u8SolenoidIdx] ) && (iohwab_au8SampleCounter[u8SolenoidIdx] < KU8_IOHWAB_ADC_BUFFER_SIZE))
      {
         for (u8BlockIndex = KU8_ZERO; u8BlockIndex < KU8_SIX; u8BlockIndex++)
         {

            /* Retain last sample where AdcIf Put a value in */
            u8SampleIdx = (u8BlockIndex + u8RawIndex) % KU8_SIX;

            /* Compute from raw value voltage value */
            u16SolenoidRawValue = u16AdcRawBuffer[u8SolenoidIdx][u8SampleIdx];
            u16SolenoidVoltage = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(u16SolenoidRawValue);

            /* ------ COMPUTATION OF THE DERIVATE AND INTEGRAL ------ */
            /* Construct a sample buffer with an array of 2 elements */
            iohwab_au16SampleBuffer[u8SolenoidIdx][KU8_ZERO] = iohwab_au16SampleBuffer[u8SolenoidIdx][KU8_ONE];
            iohwab_au16SampleBuffer[u8SolenoidIdx][KU8_ONE] = u16SolenoidVoltage;

            /* Compute derivate of last 2 samples arrived */
            iohwab_au16DerivativeComputation[u8SolenoidIdx] = abs(iohwab_au16SampleBuffer[u8SolenoidIdx][KU8_ONE] - iohwab_au16SampleBuffer[u8SolenoidIdx][KU8_ZERO]);

            /* Construct an integral buffer by using an array with 4 elements that will hold last 4 derivative elements upper calculated */
            iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_ZERO] = iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_ONE];
            iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_ONE] = iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_TWO];
            iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_TWO] = iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_THREE];
            iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_THREE] = iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_FOUR];
            iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_FOUR] = iohwab_au16DerivativeComputation[u8SolenoidIdx];

            /* Compute Integral as sum of last derivate computations */
            iohwab_au16IntegralComputation[u8SolenoidIdx] = iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_ZERO] + iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_ONE] + iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_TWO] + iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_THREE] + iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_FOUR];

            /* Construct a integral buffer in order to retain last 2 consecutive elements of integral */
            iohwab_au16ComputedSampleBuffer[u8SolenoidIdx][KU8_ZERO] = iohwab_au16ComputedSampleBuffer[u8SolenoidIdx][KU8_ONE];
            iohwab_au16ComputedSampleBuffer[u8SolenoidIdx][KU8_ONE] = iohwab_au16IntegralComputation[u8SolenoidIdx];


            /* ------ DETECTIONS OF PEAKS ------ */
            switch(iohwab_au8StateMachineCase[u8SolenoidIdx])
            {

               /* CASE 1: FIRST PEAK DETECTION
                *       -- <- 2. After up-rising, we retain peak value and it's index
                *      /
                *     /    <- 1. First, we detect if an up-rising edge
                * ---/
                */
               case KU8_IOHWAB_FIRST_PEAK_SEARCH_STATE:
               {
                  /* If we have an up-rising sceneray, where current sample is greater than last sample */
                  if (iohwab_au16ComputedSampleBuffer[u8SolenoidIdx][KU8_ONE] >= iohwab_au16ComputedSampleBuffer[u8SolenoidIdx][KU8_ZERO])
                  {
                     /* If current sample is greater than last saved maximum sample   */
                     if (iohwab_au16ComputedSampleBuffer[u8SolenoidIdx][KU8_ONE] > iohwab_au16PeakPoints[u8SolenoidIdx][KU8_ZERO] )
                     {
                        /* Save sample and it's index */
                        iohwab_au16PeakPoints[u8SolenoidIdx][KU8_ZERO] = iohwab_au16ComputedSampleBuffer[u8SolenoidIdx][KU8_ONE];
                        iohwab_au8PeakPointsIdx[u8SolenoidIdx][KU8_ZERO] = iohwab_au8SampleCounter[u8SolenoidIdx];
                     }

                     /* Increment a counter used to check for searching a Up peak */
                     iohwab_au8NoOfConsecutiveSlopes[u8SolenoidIdx][KU8_ZERO] += KU8_ONE;
                  }
                  else
                  {
                     /* In this case, then we detect that samples are decreasing */

                     /* If last saved max sample is greater than a threshold, then it's clear we identified the first peak and we can search for a valley peak */
                     if ((iohwab_au16PeakPoints[u8SolenoidIdx][KU8_ZERO] >= NVP_u16FirstPeakMinThrs ) && ( iohwab_au8NoOfConsecutiveSlopes[u8SolenoidIdx][KU8_ZERO] >= NVP_u8NoOfRetriesFirstPeak))
                     {
                        iohwab_au8StateMachineCase[u8SolenoidIdx] = KU8_IOHWAB_FIRST_VALLEY_SEARCH_STATE;
                        iohwab_au8NoOfConsecutiveSlopes[u8SolenoidIdx][KU8_ZERO] = KU8_ZERO;
                     }
                  }
                  break;
               }

               /* CASE 2: FIRST VALLEY DETECTION
                *       --
                *      /  \
                *     /    \
                * ---/      \       <- 1. First, we detect if we are in a down-trend decreasing values
                *            \
                *             \-----<- 2. Then, we retain valley lowest value
                */
               case KU8_IOHWAB_FIRST_VALLEY_SEARCH_STATE:
               {

                  /* If we have an up-rising sceneray, where current sample is greater than last sample */
                  if (iohwab_au16ComputedSampleBuffer[u8SolenoidIdx][KU8_ONE] <= iohwab_au16ComputedSampleBuffer[u8SolenoidIdx][KU8_ZERO]  )
                  {

                     /* If current sample is lower than last saved maximum sample   */
                     if (( iohwab_au16ComputedSampleBuffer[u8SolenoidIdx][KU8_ONE] < iohwab_au16PeakPoints[u8SolenoidIdx][KU8_ONE] ))
                     {
                        /* Save sample and it's index */
                        iohwab_au16PeakPoints[u8SolenoidIdx][KU8_ONE] = iohwab_au16ComputedSampleBuffer[u8SolenoidIdx][KU8_ONE];
                        iohwab_au8PeakPointsIdx[u8SolenoidIdx][KU8_ONE] = iohwab_au8SampleCounter[u8SolenoidIdx];
                     }

                     /* Increment a counter used to check for searching a down valley */
                     iohwab_au8NoOfConsecutiveSlopes[u8SolenoidIdx][KU8_ONE] += KU8_ONE;

                  }
                  else
                  {
                     /* In this case, then we detect that samples are increasing */

                     /* If retries value are accomplished */
                     if (iohwab_au8NoOfConsecutiveSlopes[u8SolenoidIdx][KU8_ONE] >= NVP_u8NoOfRetriesFirstValley)
                     {

                        /* Then we can start to seek for a second peak  */
                        iohwab_au8StateMachineCase[u8SolenoidIdx] = KU8_IOHWAB_SECOND_PEAK_SEARCH_STATE;
                        iohwab_au8NoOfConsecutiveSlopes[u8SolenoidIdx][KU8_ONE] = KU8_ZERO;

                     }
                  }
                  break;
               }

               /* CASE 3: SECOND PEAK DETECTION ( CASE WITH SOLENOID CONFIRMED )                          |  CASE 2 : SECOND PEAK DETECTION ( CASE WITH SOLENOID BLOCKED )
                *       --                                                                                |        --
                *      /  \                                                                               |       /  \
                *     /    \                                                                              |      /    \
                * ---/      \         ------- <- 2. After up-rising, we retain peak value and it's index  |  ---/      \
                *            \       /        <- 1.  First, we detect if an up-rising edge                |             \
                *             \-----/         => Second peak means solenoid confirmed.                    |              \-----------------  <- Second peak doesn't appear, so, there is a solenoid blocked.
                */


               case KU8_IOHWAB_SECOND_PEAK_SEARCH_STATE:
               {

                  /* If we have an up-rising sceneray, where current sample is greater than last sample */
                  if (iohwab_au16ComputedSampleBuffer[u8SolenoidIdx][KU8_ONE] >= iohwab_au16ComputedSampleBuffer[u8SolenoidIdx][KU8_ZERO]  )
                  {

                     /* If current sample is greater than last saved maximum sample   */
                     if ((iohwab_au16ComputedSampleBuffer[u8SolenoidIdx][KU8_ONE] > iohwab_au16PeakPoints[u8SolenoidIdx][KU8_TWO] ))
                     {
                        /* Save sample and it's index */
                        iohwab_au16PeakPoints[u8SolenoidIdx][KU8_TWO] = iohwab_au16ComputedSampleBuffer[u8SolenoidIdx][KU8_ONE];
                        iohwab_au8PeakPointsIdx[u8SolenoidIdx][KU8_TWO] = iohwab_au8SampleCounter[u8SolenoidIdx];
                     }

                     /* Increment a counter used to check for searching a second up peak */
                     iohwab_au8NoOfConsecutiveSlopes[u8SolenoidIdx][KU8_TWO] += KU8_ONE;
                  }
                  else
                  {
                     /* If retries value are accomplished */
                     if  (iohwab_au8NoOfConsecutiveSlopes[u8SolenoidIdx][KU8_TWO] >= NVP_u8NoOfRetriesSecondPeak)
                     {

                        /* We compute the slope between 2 consecutive samples */
                        u16SlopeDiff = abs(iohwab_au16PeakPoints[u8SolenoidIdx][KU8_TWO] - iohwab_au16PeakPoints[u8SolenoidIdx][KU8_ONE]);

                        /* We compute distance in samples between first and second peak */
                        u8PeaksPositionDiff = iohwab_au8PeakPointsIdx[u8SolenoidIdx][KU8_TWO] - iohwab_au8PeakPointsIdx[u8SolenoidIdx][KU8_ZERO];

                        /* If computed slope is greater than a threshold */
                        if (( u16SlopeDiff >= iohwab_kau16DegreeToSineAngle[NVP_u8AngleOfValleyAndPeak]) && (iohwab_au16PeakPoints[u8SolenoidIdx][KU8_TWO] >= NVP_u16SecondPeakMinThrs) && (u8PeaksPositionDiff > NVP_u8MinimumDistanceBetweenPeaks))
                        {
                           /* We can declare a confirmation signal */
                           iohwab_au8SolenoidUnlockConfirmation[u8SolenoidIdx] = KU8_SOLENOID_UNLOCK_CONFIRMED;
                        }

                        /* RESET VARIABLES FOR STATE MACHINE PEAK DETECTION */
                        iohwab_au8StateMachineCase[u8SolenoidIdx] = KU8_IOHWAB_FIRST_PEAK_SEARCH_STATE;

                        iohwab_au16PeakPoints[u8SolenoidIdx][KU8_ZERO] = KU16_ZERO;
                        iohwab_au16PeakPoints[u8SolenoidIdx][KU8_ONE]  = KU16_MAX;
                        iohwab_au16PeakPoints[u8SolenoidIdx][KU8_TWO]  = KU16_ZERO;

                        iohwab_au8PeakPointsIdx[u8SolenoidIdx][KU8_ZERO] = KU8_ZERO;
                        iohwab_au8PeakPointsIdx[u8SolenoidIdx][KU8_ONE]  = KU8_ZERO;
                        iohwab_au8PeakPointsIdx[u8SolenoidIdx][KU8_TWO]  = KU8_ZERO;

                        iohwab_au8NoOfConsecutiveSlopes[u8SolenoidIdx][KU8_ZERO] = KU8_ZERO;
                        iohwab_au8NoOfConsecutiveSlopes[u8SolenoidIdx][KU8_ONE]  = KU8_ZERO;
                        iohwab_au8NoOfConsecutiveSlopes[u8SolenoidIdx][KU8_TWO]  = KU8_ZERO;

                        iohwab_au8SampleCounter[u8SolenoidIdx] = KU8_ZERO;
                     }
                  }
                  break;
                }

               default:
               {
                  break;
               }
            }

            if ( iohwab_au8SampleCounter[u8SolenoidIdx] < (KU8_IOHWAB_ADC_BUFFER_SIZE - KU8_ONE))
            {
               /* Sample counter used to qualify an detection only after a specific number of samples */
               iohwab_au8SampleCounter[u8SolenoidIdx] = iohwab_au8SampleCounter[u8SolenoidIdx] + KU8_ONE;
            }
         }
      }
   }
   else
   {

      iohwab_au8SolenoidUnlockConfirmation[u8SolenoidIdx] = KU8_SOLENOID_UNLOCK_NOT_CONFIRMED;

      /* RESET VARIABLES FOR DERIVATIVE COMPUTATION */
      iohwab_au16SampleBuffer[u8SolenoidIdx][KU8_ZERO] = KU16_ZERO;
      iohwab_au16SampleBuffer[u8SolenoidIdx][KU8_ONE]  = KU16_ZERO;

      iohwab_au16DerivativeComputation[u8SolenoidIdx] = KU16_ZERO;

      iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_ZERO]  = KU16_ZERO;
      iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_ONE]   = KU16_ZERO;
      iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_TWO]   = KU16_ZERO;
      iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_THREE] = KU16_ZERO;
      iohwab_au16IntegralBuffer[u8SolenoidIdx][KU8_FOUR]  = KU16_ZERO;

      iohwab_au16IntegralComputation[u8SolenoidIdx] = KU16_ZERO;

      iohwab_au16ComputedSampleBuffer[u8SolenoidIdx][KU8_ZERO] = KU16_ZERO;
      iohwab_au16ComputedSampleBuffer[u8SolenoidIdx][KU8_ONE]  = KU16_ZERO;

      /* RESET VARIABLES FOR STATE MACHINE PEAK DETECTION */
      iohwab_au8StateMachineCase[u8SolenoidIdx] = KU8_IOHWAB_FIRST_PEAK_SEARCH_STATE;

      iohwab_au16PeakPoints[u8SolenoidIdx][KU8_ZERO] = KU16_ZERO;
      iohwab_au16PeakPoints[u8SolenoidIdx][KU8_ONE]  = KU16_MAX;
      iohwab_au16PeakPoints[u8SolenoidIdx][KU8_TWO]  = KU16_ZERO;

      iohwab_au8PeakPointsIdx[u8SolenoidIdx][KU8_ZERO] = KU8_ZERO;
      iohwab_au8PeakPointsIdx[u8SolenoidIdx][KU8_ONE]  = KU8_ZERO;
      iohwab_au8PeakPointsIdx[u8SolenoidIdx][KU8_TWO]  = KU8_ZERO;

      iohwab_au8NoOfConsecutiveSlopes[u8SolenoidIdx][KU8_ZERO] = KU8_ZERO;
      iohwab_au8NoOfConsecutiveSlopes[u8SolenoidIdx][KU8_ONE]  = KU8_ZERO;
      iohwab_au8NoOfConsecutiveSlopes[u8SolenoidIdx][KU8_TWO]  = KU8_ZERO;

      iohwab_au8SampleCounter[u8SolenoidIdx] = KU8_ZERO;
   }

}

/**
* \brief
*       Function used to search a state for the value given
* \inputparam
*       Name: pkau16CurState;
*       Type: const uint16 *;
*       Description: Array containing the state and the state thresholds;
* \inputparam
*       Name: pkau16NextState;
*       Type: const uint16 *;
*       Description: Array containing the next state and the state thresholds;
* \inputparam
*       Name: pu8WakeState;
*       Type: uint8*;
*       Description: Pointer to current state array;
* \inputparam
*       Name: u16AdcVal;
*       Type: uint16;
*       Description: Current Adc value;
* \dynamicaspectcaller
*       IoHwAb_AdcIf
* \dynamicaspectdescription
*       API called in current SW components via direct call.
* \ddesignrequirement
*       DSG_iohwab_SearchState
* \archrequirement
*       ARCH_SW_IoHwAb_pseLowPowerWakeUp
*/
LOCAL void iohwab_SearchState(const uint16 * pkau16CurState, const uint16 * pkau16NextState, uint8* pu8WakeState, uint16 u16AdcVal)
{
   uint16 u16Center;
   boolean bState;

   /* check if value is between the thresholds of a state */
   if ((pkau16CurState[KU8_ZERO] <= u16AdcVal) && (pkau16CurState[KU8_ONE] >= u16AdcVal))
   {
      *pu8WakeState = pkau16CurState[KU8_TWO];
   }
   /* is a next state available ? */
   else if(pkau16NextState != NULL_PTR)
   {
      u16Center = (pkau16CurState[KU8_ONE] + pkau16NextState[KU8_ZERO])/KU8_TWO;

      /* check if the value is between the max state value and start of hysteresis */
      if((pkau16CurState[KU8_ONE] < u16AdcVal) && ((u16Center - pkau16CurState[KU8_THREE]) > u16AdcVal))
      {
         *pu8WakeState = pkau16CurState[KU8_TWO];
      }
      /* check if the value is between the hysteresis points */
      else if(((u16Center - pkau16CurState[KU8_THREE]) <= u16AdcVal) && ((u16Center + pkau16CurState[KU8_THREE]) >= u16AdcVal))
      {
         /* if old state that is stored is the next state */
         if((*pu8WakeState) == pkau16NextState[KU8_TWO])
         {
            bState = TRUE;
         }
         else
         {
            bState = FALSE;
         }

         bState = Efx_HystCenterHalfDelta_u16_u8( u16AdcVal, u16Center, pkau16CurState[KU8_THREE], &bState );

         /* state change */
         if(FALSE == bState)
         {
            *pu8WakeState = pkau16CurState[KU8_TWO];
         }
         else
         {
            *pu8WakeState = pkau16NextState[KU8_TWO];
         }
      }
      /* check if value is between start of hysteris end and next states min value */
      else if(((u16Center + pkau16CurState[KU8_THREE]) < u16AdcVal) && (pkau16NextState[KU8_ZERO] > u16AdcVal))
      {
         *pu8WakeState = pkau16NextState[KU8_TWO];
      }
      else
      {
         /* Do nothing */
      }
   }
   else
   {
      /* Do nothing */
   }
}

/**
* \brief
*       Function used to report seat status to rte layer
* \dynamicaspectcaller
*       IoHwAb_AdcIf.
* \dynamicaspectdescription
*       API called in current SW components via direct call.
* \ddesignrequirement
*       DSG_iohwab_ReportSeatStatus
* \archrequirement
*       ARCH_SW_IoHwAb_psrSeatOccupancySensorStatus
*       ARCH_SW_IoHwAb_psrBuckleStatus
*       ARCH_SW_IoHwAb_pclNvmIfServices_SetRamBlockStatus
**/
LOCAL void iohwab_ReportSeatStatus(void)
{
   uint8 au8RteSeat[KU8_TWO];
   uint8 au8RteBelt[KU8_TWO];
   uint8 u8Counter;

   for (u8Counter = KU8_ZERO; u8Counter < KU8_TWO; u8Counter++)
   {
      switch (iohwab_au8WakeSensePrevState[u8Counter])
      {
         case KU8_IOHWAB_SEAT_OCC_BELT_NOT_PLUG:
            au8RteBelt[u8Counter] = KU8_BUCKLE_NOT_LATCHED;
            au8RteSeat[u8Counter] = KU8_SEAT_OCCUPANCY_DETECTED;
            if(KU8_SEAT_OCCUPANCY_DETECTED != NVP_au8SBSLastState[u8Counter])
            {
               NVP_au8SBSLastState[u8Counter] = KU8_SEAT_OCCUPANCY_DETECTED;
               (void)Rte_Call_pclNvmIfServices_SetRamBlockStatus(SBS_LAST_STATE, TRUE);
            }
            break;
         case KU8_IOHWAB_SEAT_NOT_OCC_BELT_NOT_PLUG:
            au8RteBelt[u8Counter] = KU8_BUCKLE_NOT_LATCHED;
            au8RteSeat[u8Counter] = KU8_SEAT_OCCUPANCY_NOT_DETECTED;
            if(KU8_SEAT_OCCUPANCY_NOT_DETECTED != NVP_au8SBSLastState[u8Counter])
            {
               NVP_au8SBSLastState[u8Counter] = KU8_SEAT_OCCUPANCY_NOT_DETECTED;
               (void)Rte_Call_pclNvmIfServices_SetRamBlockStatus(SBS_LAST_STATE, TRUE);
            }
            break;
         case KU8_IOHWAB_BELT_PLUG:
            au8RteBelt[u8Counter] = KU8_BUCKLE_LATCHED;
            au8RteSeat[u8Counter] = KU8_SEAT_OCCUPANCY_DETECTED;
            break;
         case KU8_IOHWAB_SEAT_SHORT_STATE:
            au8RteBelt[u8Counter] = KU8_BUCKLE_UNKNOWN;
            au8RteSeat[u8Counter] = KU8_SEAT_OCCUPANCY_SHORT_TO_GND;
            if((KU8_SEAT_OCCUPANCY_SHORT_TO_GND != NVP_au8SBSLastState[u8Counter]) && (KB_SEAT_1_REMOVABLE_CONFIG_DEACTIVATED))
            {
               NVP_au8SBSLastState[u8Counter] = KU8_SEAT_OCCUPANCY_SHORT_TO_GND;
               (void)Rte_Call_pclNvmIfServices_SetRamBlockStatus(SBS_LAST_STATE, TRUE);
            }
            break;
         case KU8_IOHWAB_SEAT_UNDEFINED_STATE:
         default:
            au8RteBelt[u8Counter] = KU8_BUCKLE_UNKNOWN;
            au8RteSeat[u8Counter] = KU8_SEAT_OCCUPANCY_UNKNOWN;
            if(KU8_SEAT_OCCUPANCY_UNKNOWN != NVP_au8SBSLastState[u8Counter])
            {
               NVP_au8SBSLastState[u8Counter] = KU8_SEAT_OCCUPANCY_UNKNOWN;
               (void)Rte_Call_pclNvmIfServices_SetRamBlockStatus(SBS_LAST_STATE, TRUE);
            }
            break;
      }
   }
   (void)Rte_Write_psrBuckleStatus_au8BuckleStatus(au8RteBelt);
   (void)Rte_Write_psrSeatOccupancySensorStatus_au8SeatOccupancySensorStatus(au8RteSeat);
}

/**
* \brief
*       Function used to call detection functions per seat occupancy
* \inputparam
*       Name: u16WakeCh1;
*       Type: uint16;
*       Description: Wake1 adc value;
* \inputparam
*       Name: u16WakeCh2;
*       Type: uint16;
*       Description: Wake2 adc value;
* \dynamicaspectcaller
*       IoHwAb_AdcIf.
* \dynamicaspectdescription
*       API called in SW component via direct call.
* \constrains
*       This function is called cyclic.
* \ddesignrequirement
*       DSG_iohwab_DetectSeatOccupancy
* \archrequirement
*       ARCH_SW_IoHwAb_pclPassengerOccupancyState
*       ARCH_SW_IoHwAb_psrBuckleStatus
*       ARCH_SW_IoHwAb_psrSeatOccupancySensorStatus
*       ARCH_SW_IoHwAb_pclNvmIfServices_SetRamBlockStatus
*       ARCH_SW_IoHwAb_pseHandleSeatCurrentCircuit
*       ARCH_SW_IoHwAb_pclDioIfServices_IoHwAb_HandleSeatCurrentCircuit
*       ARCH_SW_IoHwAb_pseLowPowerWakeUp
*       ARCH_SW_IoHwAb_pclPassengerOccupancyState
**/
LOCAL void iohwab_DetectSeatOccupancy(uint16 u16WakeCh1, uint16 u16WakeCh2)
{
   uint8 u8UpdateValues = KU8_FALSE;
   uint8 bReturn;

   /* handle wake cicuit on/off only in normal app mode */
   iohwab_u8WakeCounter++;
   if(KU8_SEVENTEEN == iohwab_u8WakeCounter)
   {
      Rte_Call_pclDioIfServices_WriteChannel(DIOIF_CH_WAKE_CYCLIC_POWER, STD_HIGH);    
   }
   else if(KU8_EIGHTEEN == iohwab_u8WakeCounter )
   {
      u8UpdateValues = KU8_TRUE;
   }
   else if(KU8_NINETEEN == iohwab_u8WakeCounter)
   {
      Rte_Call_pclDioIfServices_WriteChannel(DIOIF_CH_WAKE_CYCLIC_POWER, STD_LOW);
   }
   else if(KU8_TWENTY < iohwab_u8WakeCounter)
   {
      iohwab_u8WakeCounter = KU8_ZERO;
   }
   else
   {
      /* do nothing */
   }


   /* handle 4mA or 1mA current source */
   if(u8UpdateValues == KU8_TRUE)
   {
      IoHwAb_HandleSeatCurrentCircuit(&u16WakeCh1, &u16WakeCh2, &u8UpdateValues, KU8_FALSE);
      if(KU8_TRUE != u8UpdateValues)
      {
         iohwab_u8WakeCounter--;
      }
   }


   if(u8UpdateValues == KU8_TRUE)
   {
      IoHwAb_HandleSeatVariants(u16WakeCh1, u16WakeCh2, &bReturn);
      iohwab_ReportSeatStatus();
   }
}
/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

/**
* \brief
*       Cyclic function used to filter ADC lines. API not implemented.
* \dynamicaspectcaller
*       OS tasks.
* \dynamicaspectdescription
*       Called every 2 mS.
* \ddesignrequirement
*       DSG_IoHwAb_runFilterMeasurements2ms
* \archrequirement
*       ARCH_SW_BswMIf_ptrpAsrOsServicesIoHwAb_IoHwAb_runFilterMeasurements2ms
*/

EXPORTED void IoHwAb_runFilterMeasurements2ms (void)
{
}

/**
*\brief
*      Function used to filter ADC lines every 10mS. 
*\return
*      None.
*\dynamicaspectcaller
*      IoHWAb module.
*\dynamicaspectdescription
*      Called in IoHwAb_runGetMeasure.
*\constrains
*      None.
*\ddesignrequirement
*      DSG_IoHwAb_runFilterMeasurements10ms
*\archrequirement
*      ARCH_SW_BswMIf_ptrpAsrOsServicesIoHwAb_IoHwAb_runFilterMeasurements10ms
*      ARCH_SW_IoHwAb_pclRawAdcService_IoHwAb_runFilterMeasurements10ms
*      ARCH_SW_IoHwAb_pclEfxServices_IoHwAb_runFilterMeasurements10ms
*      ARCH_SW_IoHwAb_psrSeatOccupancySensorStatus
*      ARCH_SW_IoHwAb_psrBuckleStatus
*      ARCH_SW_IoHwAb_pclNvmIfServices_SetRamBlockStatus
*      ARCH_SW_IoHwAb_pseHandleSeatCurrentCircuit
*      ARCH_SW_IoHwAb_pclDioIfServices_IoHwAb_HandleSeatCurrentCircuit
*      ARCH_SW_IoHwAb_pseLowPowerWakeUp
*      ARCH_SW_IoHwAb_pclPassengerOccupancyState
*/

EXPORTED void IoHwAb_runFilterMeasurements10ms (void)
{
   uint16 u16AdcValue;
   uint16 u16AdcValue1;
   uint16 u16AdcValue2;
   uint8 u8Idx;

   for (u8Idx = KU8_ZERO; u8Idx < KU8_GLOBAL_NUMBER_OF_SOLENOIDS; u8Idx++)
   {
      /* Get ADC lsb value */
      Rte_Call_pclRawAdcService_getChannelValue(KU8_ADC_CH_ID_MAG_V_1+u8Idx, &u16AdcValue1);

      iohwab_au16FilteredValue10ms[KU8_ADC_CH_ID_MAG_V_1+u8Idx] = EFX_LPF_Filter_u16_u16(iohwab_au16FilteredValue10ms[KU8_ADC_CH_ID_MAG_V_1+u8Idx], u16AdcValue1);
   }
   Rte_Call_pclRawAdcService_getChannelValue(KU8_ADC_CH_ID_WAKE_1, &u16AdcValue1);
   Rte_Call_pclRawAdcService_getChannelValue(KU8_ADC_CH_ID_WAKE_2, &u16AdcValue2);
   iohwab_DetectSeatOccupancy(u16AdcValue1, u16AdcValue2);

   Rte_Call_pclRawAdcService_getChannelValue(KU8_ADC_CH_ID_V_BATT, &u16AdcValue );
   iohwab_au16FilteredValue10ms[KU8_ADC_CH_ID_V_BATT] = EFX_LPF_Filter_u16_u16(iohwab_au16FilteredValue10ms[KU8_ADC_CH_ID_V_BATT], u16AdcValue);

}

/**
*\brief
*      Function used to filter ADC lines every 100mS.
*\return
*      None.
*\dynamicaspectcaller
*      IoHWAb module.
*\dynamicaspectdescription
*      Called in IoHwAb_runGetMeasure.
*\constrains
*      None.
*\ddesignrequirement
*      DSG_IoHwAb_runFilterMeasurements100ms
*\archrequirement
*      ARCH_SW_BswMIf_ptrpAsrOsServicesIoHwAb_IoHwAb_runFilterMeasurements100ms
*      ARCH_SW_IoHwAb_ptrrIoHwAbServicesAdcIf_AdcIf_runGetChannelValue_IoHwAb_runFilterMeasurements100ms
*      ARCH_SW_IoHwAb_pclEfxServices_IoHwAb_runFilterMeasurements100ms
*      ARCH_SW_IoHwAb_pclRawAdcService_IoHwAb_runFilterMeasurements100ms
*/

EXPORTED void IoHwAb_runFilterMeasurements100ms (void)
{
   uint16 u16AdcValue;
   register uint8 u8Idx;

   for (u8Idx = KU8_ZERO; u8Idx < KU8_GLOBAL_NUMBER_OF_SOLENOIDS; u8Idx++)
   {
      /* Get ADC lsb value */
      Rte_Call_pclRawAdcService_getChannelValue(KU8_ADC_CH_ID_MAG_V_1+u8Idx, &u16AdcValue );
      iohwab_au16FilteredValue100ms[KU8_ADC_CH_ID_MAG_V_1+u8Idx] = EFX_LPF_Filter_u16_u16(iohwab_au16FilteredValue100ms[KU8_ADC_CH_ID_MAG_V_1+u8Idx], u16AdcValue);
   }
}

/**
* \brief
*       Function used to convert raw values read from ADC Pheripheral in SI units.
* \inputparam
*       Name: u8TypeOfMeasure;
*       Type: uint8;
*       Description: Index of ADC line to be converted;
*       Range: 
*           KU8_ADC_CH_ID_V_BATT
*           KU8_ADC_CH_ID_MAG_V_1
*           KU8_ADC_CH_ID_MAG_V_2
*           KU8_ADC_CH_ID_MAG_V_3
*           KU8_ADC_CH_ID_MAG_V_4
*           KU8_ADC_CH_ID_MAG_V_5
*           KU8_ADC_CH_ID_MAG_V_6
*           KU8_ADC_CH_ID_MAG_I_1
*           KU8_ADC_CH_ID_MAG_I_2
*           KU8_ADC_CH_ID_MAG_I_3
*           KU8_ADC_CH_ID_MAG_I_4
*           KU8_ADC_CH_ID_MAG_I_5
*           KU8_ADC_CH_ID_MAG_I_6
*           KU8_ADC_CH_ID_MAG_V_10_MS_1
*           KU8_ADC_CH_ID_MAG_V_10_MS_2
*           KU8_ADC_CH_ID_MAG_V_10_MS_3
*           KU8_ADC_CH_ID_MAG_V_10_MS_4
*           KU8_ADC_CH_ID_MAG_V_10_MS_5
*           KU8_ADC_CH_ID_MAG_V_10_MS_6
*           KU8_ADC_CH_ID_MAG_V_100_MS_1
*           KU8_ADC_CH_ID_MAG_V_100_MS_2
*           KU8_ADC_CH_ID_MAG_V_100_MS_3
*           KU8_ADC_CH_ID_MAG_V_100_MS_4
*           KU8_ADC_CH_ID_MAG_V_100_MS_5
*           KU8_ADC_CH_ID_MAG_V_100_MS_6;
* \outputparam
*       Name: pu16Measure;
*       Type: uint16;
*       Description: Output computed value in SI unit;
*       Range: 0..unit16;
* \return
*       This function must not have a return value.     
* \dynamicaspectcaller
*       CIL, DIA, SAD, IoHwAb SW Components
* \dynamicaspectdescription
*       Called to return SI units of ADC measurements.
* \constrains
*       This function is called cyclic.
* \ddesignrequirement
*       DSG_IoHwAb_runGetMeasure
* \archrequirement
*       ARCH_SW_IoHwAb_pseConvAdcService
*       ARCH_SW_IoHwAb_prrSolenoidPwm_IoHwAb_runGetMeasure
*       ARCH_SW_IoHwAb_pclRawAdcService_IoHwAb_runGetMeasure 
*       ARCH_SW_IoHwAb_pclSolenoidProfile
*       ARCH_SW_IoHwAb_prrSolenoidElectricalCharacteristics_IoHwAb_runGetMeasure
*/
EXPORTED void IoHwAb_runGetMeasure (uint8 u8TypeOfMeasure, uint16 *pu16Measure)
{

   /* ADC Temp variables */
   u16AdcValueLsbType u16AdcValue;

   /* Get all solenoid PWM in high resolution */
   (void)Rte_Read_prrSolenoidElectricalCharacteristics_au32SolenoidmATarget(iohwab_au32PwmCurrentValue);

   /* Get ADC lsb value */
   Rte_Call_pclRawAdcService_getChannelValue(u8TypeOfMeasure, &u16AdcValue );

   /* Search for the right channel */
   switch ( u8TypeOfMeasure )
   {

   /* VOLTAGE READING FROM ADC KL30 LINE IN MILLIVOLTS */
   case KU8_ADC_CH_ID_V_BATT:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(u16AdcValue) + KU16_KL30_VOLTAGE_DROPOUT;
   break;

   /* VOLTAGE READING FROM ADC BOOST_DIAG LINE IN MILLIVOLTS */
   case KU8_ADC_CH_ID_BOOST_DIAG:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(u16AdcValue);
   break;

   /* VOLTAGE READING FROM ADC SOLENOID 1 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_1:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(u16AdcValue);
   break;

   /* VOLTAGE READING FROM ADC SOLENOID 2 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_2:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(u16AdcValue);
   break;

      /* VOLTAGE READING FROM ADC SOLENOID 3 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_3:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(u16AdcValue);
   break;

      /* VOLTAGE READING FROM ADC SOLENOID 4 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_4:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(u16AdcValue);
   break;

      /* VOLTAGE READING FROM ADC SOLENOID 5 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_5:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(u16AdcValue);
   break;

   /* VOLTAGE READING FROM ADC SOLENOID 6 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_6:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(u16AdcValue);
   break;

   /* CURRENT COMPUTING FROM PWM FOR SOLENOID 1 IN MILIAMPS */
   case KU8_ADC_CH_ID_MAG_I_1:
     *pu16Measure = (uint16)iohwab_au32PwmCurrentValue[KU8_SOLENOID_1] - KU16_IOHWAB_CURRENT_OFFSET;
   break;

   /* CURRENT COMPUTING FROM PWM FOR SOLENOID 2 IN MILIAMPS */
   case KU8_ADC_CH_ID_MAG_I_2:
      *pu16Measure = (uint16)iohwab_au32PwmCurrentValue[KU8_SOLENOID_2] - KU16_IOHWAB_CURRENT_OFFSET;
   break;

   /* CURRENT COMPUTING FROM PWM FOR SOLENOID 3 IN MILIAMPS */
   case KU8_ADC_CH_ID_MAG_I_3:
      *pu16Measure = (uint16)iohwab_au32PwmCurrentValue[KU8_SOLENOID_3] - KU16_IOHWAB_CURRENT_OFFSET;
   break;

   /* CURRENT COMPUTING FROM PWM FOR SOLENOID 4 IN MILIAMPS */
   case KU8_ADC_CH_ID_MAG_I_4:
      *pu16Measure = (uint16)iohwab_au32PwmCurrentValue[KU8_SOLENOID_4] - KU16_IOHWAB_CURRENT_OFFSET;
   break;

   /* CURRENT COMPUTING FROM PWM FOR SOLENOID 5 IN MILIAMPS */
   case KU8_ADC_CH_ID_MAG_I_5:
      *pu16Measure = (uint16)iohwab_au32PwmCurrentValue[KU8_SOLENOID_5] - KU16_IOHWAB_CURRENT_OFFSET;
   break;

   /* CURRENT COMPUTING FROM PWM FOR SOLENOID 6 IN MILIAMPS */
   case KU8_ADC_CH_ID_MAG_I_6:
      *pu16Measure = (uint16)iohwab_au32PwmCurrentValue[KU8_SOLENOID_6] - KU16_IOHWAB_CURRENT_OFFSET;
   break;

   /* VOLTAGE READING FROM ADC SOLENOID 1 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_10_MS_1:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(iohwab_au16FilteredValue10ms[KU8_ADC_CH_ID_MAG_V_1]);
   break;

   /* VOLTAGE READING FROM ADC SOLENOID 2 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_10_MS_2:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(iohwab_au16FilteredValue10ms[KU8_ADC_CH_ID_MAG_V_2]);
   break;

   /* VOLTAGE READING FROM ADC SOLENOID 3 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_10_MS_3:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(iohwab_au16FilteredValue10ms[KU8_ADC_CH_ID_MAG_V_3]);
   break;

   /* VOLTAGE READING FROM ADC SOLENOID 4 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_10_MS_4:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(iohwab_au16FilteredValue10ms[KU8_ADC_CH_ID_MAG_V_4]);
   break;

   /* VOLTAGE READING FROM ADC SOLENOID 5 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_10_MS_5:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(iohwab_au16FilteredValue10ms[KU8_ADC_CH_ID_MAG_V_5]);
   break;

   /* VOLTAGE READING FROM ADC SOLENOID 6 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_10_MS_6:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(iohwab_au16FilteredValue10ms[KU8_ADC_CH_ID_MAG_V_6]);
   break;

   /* VOLTAGE READING FROM ADC SOLENOID 1 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_100_MS_1:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(iohwab_au16FilteredValue100ms[KU8_ADC_CH_ID_MAG_V_1]);
   break;

   /* VOLTAGE READING FROM ADC SOLENOID 2 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_100_MS_2:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(iohwab_au16FilteredValue100ms[KU8_ADC_CH_ID_MAG_V_2]);
   break;

   /* VOLTAGE READING FROM ADC SOLENOID 3 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_100_MS_3:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(iohwab_au16FilteredValue100ms[KU8_ADC_CH_ID_MAG_V_3]);
   break;

   /* VOLTAGE READING FROM ADC SOLENOID 4 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_100_MS_4:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(iohwab_au16FilteredValue100ms[KU8_ADC_CH_ID_MAG_V_4]);
   break;

   /* VOLTAGE READING FROM ADC SOLENOID 5 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_100_MS_5:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(iohwab_au16FilteredValue100ms[KU8_ADC_CH_ID_MAG_V_5]);
   break;

   /* VOLTAGE READING FROM ADC SOLENOID 6 LINE IN MILIVOLTS */
   case KU8_ADC_CH_ID_MAG_V_100_MS_6:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(iohwab_au16FilteredValue100ms[KU8_ADC_CH_ID_MAG_V_6]);
   break;

   case KU8_ADC_CH_ID_V_BATT_10_MS:
      *pu16Measure = KU16_IOHWAB_MEASURE_ADC_VOLTAGE_WITH_VOLTAGE_DIV(iohwab_au16FilteredValue10ms[KU8_ADC_CH_ID_V_BATT]);
      break;

   default:
      /* Wrong ID or channel not used yet on the PCB */
      *pu16Measure = KU16_ZERO;
   break;
   }
}

#define IoHwAb_STOP_SEC_CODE_ASIL_A
#include "IoHwAb_MemMap.h"

#define IoHwAb_START_SEC_CODE
#include "IoHwAb_MemMap.h"

/**
* \brief
*       Function used to get temperature of a specific solenoid based on solenoid activation.
* \inputparam
*       Name: u8TypeOfMeasure;
*       Type: uint8;
*       Description: Index of solenoid to be measured;
*       Range: 
*       	  KU8_ADC_CH_ID_SOLENOID_TEMP_1
*       	  KU8_ADC_CH_ID_SOLENOID_TEMP_2
*       	  KU8_ADC_CH_ID_SOLENOID_TEMP_3
*       	  KU8_ADC_CH_ID_SOLENOID_TEMP_4
*       	  KU8_ADC_CH_ID_SOLENOID_TEMP_5
*       	  KU8_ADC_CH_ID_SOLENOID_TEMP_6;
* \outputparam
*       Name: *ps16SolenoidTemperature;
*       Type: sint16;
*       Description: Computed value of temperature of selected solenoid in degrees celsius;
*       Range: -40..80;
* \pre
*       ADC, PWM Pheripherals must be initalised.
* \return
*       This function must not have a return value.    
* \dynamicaspectcaller
*       CIL SW Component.
* \dynamicaspectdescription
*       API called in CIL_ManangeMFTransmission.
* \constrains
*       In order to return valid values, solenoid must be activated.
* \ddesignrequirement
*       DSG_IoHwAb_GetSolenoidTemperature
* \archrequirement
*       ARCH_SW_IoHwAb_pseSolenoidCharacterstics
*       ARCH_SW_IoHwAb_prrSolenoidPwm_IoHwAb_runGetMeasure
*       ARCH_SW_IoHwAb_pclRawAdcService_IoHwAb_runGetMeasure 
*       ARCH_SW_IoHwAb_prrSolenoidElectricalCharacteristics_IoHwAb_runGetMeasure
*/

EXPORTED void IoHwAb_GetSolenoidTemperature (uint8 u8TypeOfMeasure, sint16 *ps16SolenoidTemperature)
{
   uint16 u16SolenoidVoltage;
   uint16 u16SolenoidCurrent;

   switch (u8TypeOfMeasure)
   {
      case KU8_ADC_CH_ID_SOLENOID_TEMP_1:
         IoHwAb_runGetMeasure(KU8_ADC_CH_ID_MAG_V_100_MS_1, &u16SolenoidVoltage);
         IoHwAb_runGetMeasure(KU8_ADC_CH_ID_MAG_I_1, &u16SolenoidCurrent);

         if ((KU16_ZERO == u16SolenoidCurrent) || (KU16_ZERO == u16SolenoidVoltage))
         {
            *ps16SolenoidTemperature = iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_1];
         }
         else
         {
            iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_1] = iohwab_computeSolenoidTemperature(u16SolenoidVoltage, u16SolenoidCurrent);
            *ps16SolenoidTemperature = iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_1];
         }
        
      break;

      case KU8_ADC_CH_ID_SOLENOID_TEMP_2:
         IoHwAb_runGetMeasure(KU8_ADC_CH_ID_MAG_V_100_MS_2, &u16SolenoidVoltage);
         IoHwAb_runGetMeasure(KU8_ADC_CH_ID_MAG_I_2, &u16SolenoidCurrent); 

         if ((KU16_ZERO == u16SolenoidCurrent) || (KU16_ZERO == u16SolenoidVoltage))
         {
            *ps16SolenoidTemperature = iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_2];
         }
         else
         {
            iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_2] = iohwab_computeSolenoidTemperature(u16SolenoidVoltage, u16SolenoidCurrent);
            *ps16SolenoidTemperature = iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_2];
         }

      break;

      case KU8_ADC_CH_ID_SOLENOID_TEMP_3:
         IoHwAb_runGetMeasure(KU8_ADC_CH_ID_MAG_V_100_MS_3, &u16SolenoidVoltage);
         IoHwAb_runGetMeasure(KU8_ADC_CH_ID_MAG_I_3, &u16SolenoidCurrent);

         if ((KU16_ZERO == u16SolenoidCurrent) || (KU16_ZERO == u16SolenoidVoltage))
         {
            *ps16SolenoidTemperature = iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_3];
         }
         else
         {
            iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_3] = iohwab_computeSolenoidTemperature(u16SolenoidVoltage, u16SolenoidCurrent);
            *ps16SolenoidTemperature = iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_3];
         }
      break;

      case KU8_ADC_CH_ID_SOLENOID_TEMP_4:
         IoHwAb_runGetMeasure(KU8_ADC_CH_ID_MAG_V_100_MS_4, &u16SolenoidVoltage);
         IoHwAb_runGetMeasure(KU8_ADC_CH_ID_MAG_I_4, &u16SolenoidCurrent);

         if ((KU16_ZERO == u16SolenoidCurrent) || (KU16_ZERO == u16SolenoidVoltage))
         {
            *ps16SolenoidTemperature = iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_4];
         }
         else
         {
            iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_4] = iohwab_computeSolenoidTemperature(u16SolenoidVoltage, u16SolenoidCurrent);
            *ps16SolenoidTemperature = iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_4];
         }
      break;

      case KU8_ADC_CH_ID_SOLENOID_TEMP_5:
         IoHwAb_runGetMeasure(KU8_ADC_CH_ID_MAG_V_100_MS_5, &u16SolenoidVoltage);
         IoHwAb_runGetMeasure(KU8_ADC_CH_ID_MAG_I_5, &u16SolenoidCurrent);

         if ((KU16_ZERO == u16SolenoidCurrent) || (KU16_ZERO == u16SolenoidVoltage))
         {
            *ps16SolenoidTemperature = iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_5];
         }
         else
         {
            iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_5] = iohwab_computeSolenoidTemperature(u16SolenoidVoltage, u16SolenoidCurrent);
            *ps16SolenoidTemperature = iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_5];
         }
      break;

      case KU8_ADC_CH_ID_SOLENOID_TEMP_6:
         IoHwAb_runGetMeasure(KU8_ADC_CH_ID_MAG_V_100_MS_6, &u16SolenoidVoltage);
         IoHwAb_runGetMeasure(KU8_ADC_CH_ID_MAG_I_6, &u16SolenoidCurrent);

         if ((KU16_ZERO == u16SolenoidCurrent) || (KU16_ZERO == u16SolenoidVoltage))
         {
            *ps16SolenoidTemperature = iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_6];
         }
         else
         {
            iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_6] = iohwab_computeSolenoidTemperature(u16SolenoidVoltage, u16SolenoidCurrent);
            *ps16SolenoidTemperature = iohwab_as16LocalSolenoidTemp[KU8_SOLENOID_6];
         }
      break;

      default:
         /* Wrong ID or channel not used yet on the PCB */
         *ps16SolenoidTemperature = KS16_ZERO;
      break;
   }
}

/**
* \brief
*       Function used to get temperature readed by accelerometer hardware pheripheral.
* \outputparam
*       Name: *s16AccTemperature;
*       Type: sint16;
*       Description: Output temperature readed by accelerometer in degrees celsius;
*       Range: -40..80;
* \dynamicaspectcaller
*       CIL, DIA, IoHwAb SW Components.
* \dynamicaspectdescription
*       Called to output temperature of sensor.
* \constrains
*       Accelerometer must be initialised.
* \ddesignrequirement
*       DSG_IoHwAb_GetAccelerometerTemperature
* \archrequirement
*       ARCH_SW_IoHwAb_pseAccSensor
*       ARCH_SW_IoHwAb_pclAccSpiData
*/
EXPORTED void IoHwAb_GetAccelerometerTemperature (sint16 *ps16AccTemperature)
{
   uint16 u16TmpSpiVal = KU16_ZERO;
   sint16 s16TmpIntermediateValue = KS16_ZERO;

   Rte_Call_pclAccSpiData_GetTemperatureData(&u16TmpSpiVal);
   /* Temperature resolution: 1 lsb = 0.05 */
   /* Formula: temp(degree) = 25 ℃ + (register_data/20) */

   s16TmpIntermediateValue = (sint16)KU8_TWENTYFIVE + ((sint16)u16TmpSpiVal / (sint16)KU8_TWENTY);
   
   /* Ignore wrong values */
   if ((s16TmpIntermediateValue > KS16_IOHWAB_MIN_TEMPERTATURE_VAL) && (s16TmpIntermediateValue < KS16_IOHWAB_MAX_TEMPERTATURE_VAL))
   {
      iohwab_s16LocalAccTemp = s16TmpIntermediateValue;
   }

   *ps16AccTemperature = iohwab_s16LocalAccTemp;
}

/**
* \brief
*       Function used to get temperature readed by MCU Temp hardware pheripheral.
* \outputparam
*       Name: *ps16McuTemperature;
*       Type: sint16;
*       Description: Output temperature readed by MCU Temp in degrees celsius;
*       Range: -40..80;
* \dynamicaspectcaller
*       CIL, DIA, IoHwAb SW Components.
* \dynamicaspectdescription
*       Called to output temperature of sensor.
* \constrains
*       MCU Temp ADC pherihperal must be initialised.
* \ddesignrequirement
*       DSG_IoHwAb_IoHwAb_GetMcuTemperature
* \archrequirement
*       ARCH_SW_IoHwAb_pseMcuCharacteristics
*       ARCH_SW_IoHwAb_pclRawAdcService_IoHwAb_GetMcuTemperature
*/
EXPORTED void IoHwAb_GetMcuTemperature (sint16 *ps16McuTemperature)
{
   /* MCU Temp variables */
   register sint32 s32SubEquationOne;
   register sint32 s32SubEquationTwo;
   uint16 u16BandGapVal;
   register uint16 u16CalcVrefBasedOnBandGap;
   uint16 u16RawVal;
   register uint16 u16Vsense;
   sint16 s16TmpIntermediateValue = KS16_ZERO;
   
   /* Read ADC BandGap channel to get the raw value */
   Rte_Call_pclRawAdcService_getChannelValue(KU8_ADC_CH_V_ECU_TEMP_MCU_BAND_GAP, &u16BandGapVal);

   /* Calculate Vref value based on bandgap raw measurement */
   u16CalcVrefBasedOnBandGap = (uint16) ((KU32_IOHWAB_MCU_BANDGAP_NUMERATOR * KU16_IOHWAB_ADC_FULL_RANGE) / u16BandGapVal);

   /* Read ADC channel assigned to MCU internal temperature (channel 26) */
   Rte_Call_pclRawAdcService_getChannelValue(KU8_ADC_CH_V_ECU_TEMP_MCU, &u16RawVal);

   /* Calculate Vsense value */
   u16Vsense = (uint16) (((uint32)u16RawVal * u16CalcVrefBasedOnBandGap) / KU16_IOHWAB_ADC_FULL_RANGE);

   /* Get MCU temperature : 25 - (Vsense - VTEMP_25) / VTEMP_S  */
   /* VTEMP_25  = 755 mV; VTEMP_S = 1.62 mV/°C                 */
   /* so MCU_temp = 25 - [ ( Vsense - 755 mV)  ) / 1.62 mV/°C ] */
   /* Equation is divided in 3 operations because sint operation issues */

   /* EquationOne = (Vsense - VTEMP_25) *100 */
   s32SubEquationOne = (((sint32)u16Vsense - KS32_IOHWAB_MCU_T_SENS_TEMP_REF_MV) * KS32_IOHWAB_MCU_T_SENS_SLOPE_DENOMINATOR);

   /* EquationTwo = EquationOne / 162 */
   s32SubEquationTwo = s32SubEquationOne / KS32_IOHWAB_MCU_T_SENS_SLOPE_NUMERATOR;

   /* MCU temperature = 25 - EquationTwo */
   s16TmpIntermediateValue = (sint16)(KS32_IOHWAB_MCU_T_SENS_REF_TEMPERATURE - s32SubEquationTwo);

   /* Ignore wrong values */
   if ((s16TmpIntermediateValue > KS16_IOHWAB_MIN_TEMPERTATURE_VAL) && (s16TmpIntermediateValue < KS16_IOHWAB_MAX_TEMPERTATURE_VAL))
   {
      iohwab_s16LocalMcuTemp = s16TmpIntermediateValue;
   }

   *ps16McuTemperature = iohwab_s16LocalMcuTemp;
}

/**
* \brief
*       Function used to get temperature readed by PTC Temp hardware pheripheral.
* \outputparam
*       Name: *ps16PtcSensorTemperature;
*       Type: sint16;
*       Description: Output temperature readed by PTC Temp in degrees celsius;
*       Range: -40..80;
* \dynamicaspectcaller
*       CIL, DIA, IoHwAb SW Components.
* \dynamicaspectdescription
*       Called to output temperature of sensor.
* \constrains
*       PTC ADC line pherihperal must be initialised.
* \ddesignrequirement
*       DSG_IoHwAb_GetPtcTemperature
* \archrequirement
*       ARCH_SW_IoHwAb_psePtcSensor
*       ARCH_SW_IoHwAb_pclRawAdcService_IoHwAb_GetPtcTemperature
*/
EXPORTED void IoHwAb_GetPtcTemperature (sint16 *ps16PtcSensorTemperature)
{
   uint16 u16AdcValue;
   sint16 s16TmpIntermediateValue = KS16_ZERO;

   Rte_Call_pclRawAdcService_getChannelValue(KU8_ADC_CH_ID_PTC_TEMP, &u16AdcValue);
   s16TmpIntermediateValue = iohwab_GetPTCSensorTemp(u16AdcValue);
   
   /* Ignore wrong values */
   if ((s16TmpIntermediateValue > KS16_IOHWAB_MIN_TEMPERTATURE_VAL) && (s16TmpIntermediateValue < KS16_IOHWAB_MAX_TEMPERTATURE_VAL))
   {
      iohwab_s16LocalPtcTemp = s16TmpIntermediateValue;
   }

   *ps16PtcSensorTemperature = iohwab_s16LocalPtcTemp;
}



/**
* \brief
*       Function used to get temperature readed by ECU Temp hardware pheripheral.
* \outputparam
*       Name: *ps16EcuTemperature;
*       Type: sint16;
*       Description: Output temperature readed by ECU Temp in degrees celsius;
*       Range: -40..80;
* \dynamicaspectcaller
*       CIL, DIA, IoHwAb SW Components.
* \dynamicaspectdescription
*       Called to output temperature of sensor.
* \constrains
*       PTC ADC line pherihperal must be initialised.
* \ddesignrequirement
*       DSG_IoHwAb_GetEcuTemperature
* \archrequirement
*       ARCH_SW_IoHwAb_pseEcuCharacteristics
*/
EXPORTED void IoHwAb_GetEcuTemperature (sint16 *ps16EcuTemperature)
{
   iohwab_s16LocalEcuTemp = ((((iohwab_s16LocalPtcTemp+(sint16)NVP_s8PtcTempOffset) * (sint16)KU8_IOHWAB_PTC_PERCENTAGE))/(sint16)KU8_ONE_HUNDRED) +
                            ((((iohwab_s16LocalMcuTemp+(sint16)NVP_s8McuTempOffset) * (sint16)NVP_u8MCUTempPer)         )/ (sint16)KU8_ONE_HUNDRED)+
                            ((((iohwab_s16LocalAccTemp+(sint16)NVP_s8AccTempOffset) * (sint16)NVP_u8ACCTempPer)         )/ (sint16)KU8_ONE_HUNDRED);
   *ps16EcuTemperature = iohwab_s16LocalEcuTemp;
}

/**
* \brief
*       Function used to call detection functions per every solenoid.
* \dynamicaspectcaller
*       RTE SW layer.
* \dynamicaspectdescription
*       API called in other SW components via RTE layer.
* \constrains
*       This function is called ciclyc.
* \ddesignrequirement
*       DSG_IoHwAb_DetectVoltageFluctuation
* \archrequirement
*       ARCH_SW_BswMIf_ptrpAsrOsServicesIoHwAb_IoHwAb_DetectVoltageFluctuation
*       ARCH_SW_IoHwAb_psrSolenoidConfirmation
*       ARCH_SW_AdcIf_prrAdcBufferServices_AdcIf_GPTOnTimer_Expiration
*       ARCH_SW_IoHwAb_prrAdcBufferServices_IoHwAb_DetectVoltageFluctuation
*       ARCH_SW_IoHwAb_pclSolenoidStep
*/
EXPORTED void IoHwAb_DetectVoltageFluctuation(void)
{
   uint8 u8SolenoidEnableVariant;
   uint8 u8SolenoidIdx;

   iohwab_bRteIsau8SelectedProfileUpdated = Rte_IsUpdated_pclSolenoidProfile_au8SelectedProfile();
   iohwab_bRteIsaau8CurrentStepUpdated = Rte_IsUpdated_pclSolenoidStep_au8CurrentStep();
   iohwab_bRteIsaau16HistoricalAdcSamplesUpdated = Rte_IsUpdated_prrAdcBufferServices_aau16HistoricalAdcSamples();
   iohwab_bRteIsu8HistoricalAdcSampleIndexUpdated = Rte_IsUpdated_prrAdcBufferServices_u8HistoricalAdcSampleIndex();

   SuspendAllInterrupts();
   for(u8SolenoidIdx = KU8_ZERO; u8SolenoidIdx <= (KU8_MAX_SOLENOID_NB - KU8_ONE); u8SolenoidIdx++)
   {
      Rte_Call_pclModeManagement_CheckModeStatus(iohwab_kau64SolenoidConfigMask[u8SolenoidIdx], &u8SolenoidEnableVariant);

      if(KU8_TRUE == u8SolenoidEnableVariant)
      {
         if((TRUE == iohwab_bRteIsau8SelectedProfileUpdated) &&
            (TRUE == iohwab_bRteIsaau8CurrentStepUpdated) &&
            (TRUE == iohwab_bRteIsaau16HistoricalAdcSamplesUpdated) &&
            (TRUE == iohwab_bRteIsu8HistoricalAdcSampleIndexUpdated))
         {
            iohwab_DetectVoltageFluctuationOnSolenoid(u8SolenoidIdx);
         }
      }
   }

   Rte_Write_psrSolenoidConfirmation_au8SolenoidStatus(iohwab_au8SolenoidUnlockConfirmation);
   ResumeAllInterrupts();
}

/**
* \brief
*       Function used to call detection functions per seat occupancy according to variant.
* \inputparam
*       Name: u16WakeCh1;
*       Type: uint16;
*       Description: Wake1 adc value;
* \inputparam
*       Name: u16WakeCh2;
*       Type: uint16;
*       Description: Wake2 adc value;
* \outputparam
*       Name: bReturn;
*       Type: boolean;
*       Description: returns B_TRUE if wakeup conditions are true;
* \dynamicaspectcaller
*       LPM, IoHwAb_AdcIf.
* \dynamicaspectdescription
*       API called in other SW components via direct call.
* \constrains
*       This function is called cyclic.
* \ddesignrequirement
*       DSG_IoHwAb_HandleSeatVariants
* \archrequirement
*       ARCH_SW_IoHwAb_pseLowPowerWakeUp
*       ARCH_SW_IoHwAb_pclPassengerOccupancyState
*/
EXPORTED void IoHwAb_HandleSeatVariants(uint16 u16WakeCh1, uint16 u16WakeCh2, boolean *bReturn)
{
   const uint16 * pkau16CurVar1;
   const uint16 * pkau16CurVar2;
   uint8 u8Counter;

   *bReturn = B_FALSE;

   if (KUB_eCS_SBS_BKL_RES_CIRCUIT_SEAT_1_VARIANT_1)
   {
      pkau16CurVar1 = (uint16 const *)NVP_au16Var1AdcRange;
   }
   else
   {
      pkau16CurVar1 = (uint16 const *)NVP_au16Var2AdcRange;
   }

   if(KUB_eCS_SBS_BKL_RES_CIRCUIT_SEAT_2_VARIANT_1)
   {
      pkau16CurVar2 = (uint16 const *)NVP_au16Var1AdcRange;
   }
   else
   {
      pkau16CurVar2 = (uint16 const *)NVP_au16Var2AdcRange;
   }

   for (u8Counter = KU8_ZERO; u8Counter < KU8_IOHWAB_SEARCH_STATE_CHECK; u8Counter += KU8_FOUR)
   {
      iohwab_SearchState((uint16 const *)&pkau16CurVar1[u8Counter], (uint16 const *)&pkau16CurVar1[u8Counter + KU8_FOUR], &iohwab_au8WakeSenseCurrState[KU8_ZERO], u16WakeCh1);
      iohwab_SearchState((uint16 const *)&pkau16CurVar2[u8Counter], (uint16 const *)&pkau16CurVar2[u8Counter + KU8_FOUR], &iohwab_au8WakeSenseCurrState[KU8_ONE], u16WakeCh2);
   }
   /* search last state, no next state available */
   iohwab_SearchState((uint16 const *)&pkau16CurVar1[u8Counter], NULL_PTR, &iohwab_au8WakeSenseCurrState[KU8_ZERO], u16WakeCh1);
   iohwab_SearchState((uint16 const *)&pkau16CurVar2[u8Counter], NULL_PTR, &iohwab_au8WakeSenseCurrState[KU8_ONE], u16WakeCh2);

   if ((KU8_TRUE == iohwab_kau8WakeupMatrix[iohwab_au8WakeSensePrevState[KU8_ZERO]][iohwab_au8WakeSenseCurrState[KU8_ZERO]]) ||
   (KU8_TRUE == iohwab_kau8WakeupMatrix[iohwab_au8WakeSensePrevState[KU8_ONE]][iohwab_au8WakeSenseCurrState[KU8_ONE]]))
   {
      Rte_Call_pclPassengerOccupancyState_BswM_UpdatePassangerOccupancyStatus();
      *bReturn = B_TRUE;
   }

   iohwab_au8WakeSensePrevState[KU8_ZERO] = iohwab_au8WakeSenseCurrState[KU8_ZERO];
   iohwab_au8WakeSensePrevState[KU8_ONE] = iohwab_au8WakeSenseCurrState[KU8_ONE];
}

/**
* \brief
*       Function used to call detection handle the seat occupancy detection circuit.
* \inputparam
*       Name: u8ResetState;
*       Type: uint8;
*       Description: KU8_TRUE when the seat detection circuit must be reset to its initial state;
* \inputparam
*       Name: pu16WakeCh1;
*       Type: uint16 *;
*       Description: Wake1 adc value;
* \inputparam
*       Name: pu16WakeCh2;
*       Type: uint16 *;
*       Description: Wake2 adc value;
* \outputparam
*       Name: pu8Valid;
*       Type: uint8 *;
*       Description: KU8_TRUE if the adc inputs can be used, else KU8_FALSE;
* \dynamicaspectcaller
*       LPM, IoHwAb_AdcIf.
* \dynamicaspectdescription
*       API called in other SW components via direct call.
* \constrains
*       This function is called cyclic.
* \ddesignrequirement
*       DSG_IoHwAb_HandleSeatCurrentCircuit
* \archrequirement
*       ARCH_SW_IoHwAb_pseHandleSeatCurrentCircuit
*       ARCH_SW_IoHwAb_pclDioIfServices_IoHwAb_HandleSeatCurrentCircuit
*/
EXPORTED void IoHwAb_HandleSeatCurrentCircuit(uint16 *pu16WakeCh1, uint16 *pu16WakeCh2, uint8* pu8Valid, uint8 u8ResetState)
{
   STATIC uint16 u16PrevChan1Val = KU16_ZERO;
   STATIC uint16 u16PrevChan2Val = KU16_ZERO;
   STATIC uint8 u8Chan1ValOverflow = KU8_FALSE;
   STATIC uint8 u8Chan2ValOverflow = KU8_FALSE;
   STATIC uint8 u8UseLowCurrentDetect = KU8_FALSE;

   *pu8Valid = KU8_TRUE;

   if(KU8_TRUE == u8ResetState)
   {
      u16PrevChan1Val = KU16_ZERO;
      u16PrevChan2Val = KU16_ZERO;
      u8Chan1ValOverflow = KU8_FALSE;
      u8Chan2ValOverflow = KU8_FALSE;
      u8UseLowCurrentDetect = KU8_FALSE;     
   }

   if(KU8_FALSE == u8UseLowCurrentDetect) 
   {
      if((*pu16WakeCh1) > KU16_IOHWAB_SEAT_CIRCUT_4MA_LIMIT)
      {
         u8Chan1ValOverflow = KU8_TRUE;
         u16PrevChan1Val = KU16_ZERO;
         Rte_Call_pclDioIfServices_WriteChannel(DIOIF_CH_WAKE_SW1, STD_LOW);
      }
      else
      {
         u16PrevChan1Val = *pu16WakeCh1;
      }

      if((*pu16WakeCh2) > KU16_IOHWAB_SEAT_CIRCUT_4MA_LIMIT)
      {
         u8Chan2ValOverflow = KU8_TRUE;
         u16PrevChan2Val = KU16_ZERO;
         Rte_Call_pclDioIfServices_WriteChannel(DIOIF_CH_WAKE_SW2, STD_LOW);
      }
      else
      {
         u16PrevChan2Val = *pu16WakeCh2;
      }

      if((KU8_TRUE == u8Chan1ValOverflow) || (KU8_TRUE == u8Chan2ValOverflow))
      {
         u8UseLowCurrentDetect = KU8_TRUE;
         *pu8Valid = KU8_FALSE;
      }
   }
   else
   {
      u8UseLowCurrentDetect = KU8_FALSE;
      Rte_Call_pclDioIfServices_WriteChannel(DIOIF_CH_WAKE_SW2, STD_HIGH);
      Rte_Call_pclDioIfServices_WriteChannel(DIOIF_CH_WAKE_SW1, STD_HIGH);

      if(KU8_TRUE == u8Chan1ValOverflow)
      {
         *pu16WakeCh1 += KU16_IOHWAB_SEAT_CIRCUT_1MA_THRES;
         u8Chan1ValOverflow = KU8_FALSE;
      }
      else
      {
         *pu16WakeCh1 = u16PrevChan1Val;
      }
      if(KU8_TRUE == u8Chan2ValOverflow)
      {
         *pu16WakeCh2 += KU16_IOHWAB_SEAT_CIRCUT_1MA_THRES;
         u8Chan2ValOverflow = KU8_FALSE;
      }
      else
      {
         *pu16WakeCh2 = u16PrevChan2Val;
      }
   }
}
#define IoHwAb_STOP_SEC_CODE
#include "IoHwAb_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
