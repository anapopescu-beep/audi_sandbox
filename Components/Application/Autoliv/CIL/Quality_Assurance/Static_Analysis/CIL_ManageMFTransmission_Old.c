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
 *    $Revision: 1.2.3.7 $
 *    $ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/CIL/Quality_Assurance/Static_Analysis/project.pj $
 */

/**
 * Overview of the component :
 *    Communication Interface Layer (CIL) oversees extracting data from the
 *    network frames (e.g. CAN) and providing the data to the application, and
 *    packing the outgoing data to the network frames.
 *    The aim of the CIL component is to interpret all received signals on the
 *    communication component and to provide the right information to the application.
 *    Also, it’s purpose is to gather information from the Application and
 *    compute the status signals and sent them to the CAN bus.
 *    CIL oversees:
 *       - Unpacking received data frames from the network (CAN), and providing
 *         the data to the application
 *       - Packing the outgoing data to data frames for the network (CAN)
 */

/*!****************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_CIL.h"
#include "common.h"
#include "Nvp_Cfg.h"
#include "FSM.h"
#include "CIL.h"
#include "Dem_Cfg.h"
#include "Dcm_Dsp_MemoryServices.h"
#include "Dcm_Callouts.h"
#include "ComM.h"
#ifndef QAC
#include "T1_AppInterface.h"
#endif
/******************************************************************************
MODULE DEFINES
******************************************************************************/

/**
 * \brief
 *       Id constant for measurement frame Block 1
 */
#define KU8_CIL_BLOCK_ID_01 (KU8_ONE)

/**
 * \brief
 *       Id constant for measurement frame Block 2
 */
#define KU8_CIL_BLOCK_ID_02 (KU8_TWO)

/**
 * \brief
 *       Id constant for measurement frame Block 3
 */

#define KU8_CIL_BLOCK_ID_03 (KU8_THREE)


/**
 * \brief
 *       Constant timeslot identifier
 */

#define KU8_CIL_TIME_SLOT_0 (KU8_ZERO)

/**
 * \brief
 *       Constant timeslot identifier
 */

#define KU8_CIL_TIME_SLOT_1 (KU8_ONE)

/**
 * \brief
 *       Constant timeslot identifier
 */

#define KU8_CIL_TIME_SLOT_2 (KU8_TWO)

/**
 * \brief
 *       Constant timeslot identifier
 */

#define KU8_CIL_TIME_SLOT_3 (KU8_THREE)

/**
 * \brief
 *       Constant timeslot identifier
 */

#define KU8_CIL_TIME_SLOT_4 (KU8_FOUR)

/**
 * \brief
 *       Constant with the number of support blocks
 */
#define KU8_CIL_MF_NB_OF_BLOCKS (KU8_THREE)


/**
 * \brief
 *       Constant of the invalid block ID
 */
#define KU8_CIL_MF_INVALID_BLOCK_ID (KU8_ZERO)

/**
 * \brief
 *       Constant for addressing byte 0 of the NVP_au8MeasFrameBlockConfig array
 */
#define KU8_CIL_INDEX_0_IN_SELECTED_BLOCKS_ARRAY KU8_ZERO

/**
 * \brief
 *       Constant for addressing byte 1 of the NVP_au8MeasFrameBlockConfig array
 */
#define KU8_CIL_INDEX_1_IN_SELECTED_BLOCKS_ARRAY KU8_ONE

/**
 * \brief
 *       Constant for addressing byte 2 of the NVP_au8MeasFrameBlockConfig array
 */
#define KU8_CIL_INDEX_2_IN_SELECTED_BLOCKS_ARRAY KU8_TWO

/**
 * \brief
 *       Number of solenoid in the project
 */
#define KU8_CIL_NB_SOLENOID ((uint8) KU8_GLOBAL_NUMBER_OF_SOLENOIDS)

/**
 * \brief
 *       Temperature offset
 */
#define KU8_CIL_TEMPERATURE_OFFSET ((uint8) 0u)

/**
 * \brief
 *       Temperature offset
 */
#define KU8_CIL_TIME_SLOTS ((uint8)5u)

/**
 * \brief
 *       Temperature offset
 */
#define KU8_FIFTY ((uint8)50u)

/******************************************************************************
MODULE TYPES
******************************************************************************/
/**
 * \brief
 *       Function pointer for addressing measurement frame callbacks
 */
typedef void (*cil_pfBlockFunction_Type)(uint8 u8TimeSlot);

/**
 * \brief
 *       This enum contains helper defines for checking which block is currently active
 * \remark
 *       No unit has been defined for this enumeration.
 */
typedef enum CIL_Block_Mask_Type
{
   CIL_BLOCK_MASK_1 = 0x01u,
   CIL_BLOCK_MASK_2,
   CIL_BLOCK_MASK_12,
   CIL_BLOCK_MASK_3,
   CIL_BLOCK_MASK_13,
   CIL_BLOCK_MASK_23,
   CIL_BLOCK_MASK_123
}CIL_Block_Mask_Type;

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/**
 * \brief
 *       Macro which computes a bit mask from a measurement frames block number
 */
#define U32_CIL_BLOCK_MASK(u8u8BlockId) ((uint32)(((uint32)(0x00000001uL)) << ((uint8)((u8u8BlockId)-1u))))

/**
 * \brief
 *       Macro which computes a bit mask to select the next measurement frames block number
 */
#define U32_CIL_NEXT_BLOCK(u32BlockMask) ((uint32)((u32BlockMask) << 1u))

/**
 * \brief
 *       Ecu state initial condition
 */
#define KU8_CIL_INIT_STATE_ACTIVE            ((uint8) 40)

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
LOCAL_INLINE void cil_Update_07Cx_Block01_Timeslot0_InfosToSend(void);
LOCAL_INLINE void cil_Update_07Cx_Block01_Timeslot1_InfosToSend(void);
LOCAL_INLINE void cil_Update_07Cx_Block01_Timeslot2_InfosToSend(void);
LOCAL_INLINE void cil_Update_07Cx_Block01_Timeslot3_InfosToSend(void);
LOCAL_INLINE void cil_Update_07Cx_Block01_Timeslot4_InfosToSend(void);
LOCAL_INLINE void cil_Update_07Cx_Block03_Timeslot0_InfosToSend(uint32 *u32DataToDisplay);
LOCAL_INLINE void cil_Update_07Cx_Block03_Timeslot1_InfosToSend(uint32 *u32DataToDisplay);
LOCAL_INLINE void cil_Update_07Cx_Block03_Timeslot2_InfosToSend(uint32 *u32DataToDisplay);
LOCAL_INLINE void cil_Update_07Cx_Block03_Timeslot3_InfosToSend(uint32 *u32DataToDisplay);
LOCAL_INLINE void cil_Update_07Cx_Block03_Timeslot4_InfosToSend(uint32 *u32DataToDisplay);
LOCAL boolean cil_Update_07Cx_InfosToSend(uint8 u8TimeSlot);
LOCAL void cil_Update_07Cx_Block01_InfosToSend(uint8 u8TimeSlot);
LOCAL void cil_Update_07Cx_Block02_InfosToSend(uint8 u8TimeSlot);
LOCAL void cil_Update_07Cx_Block03_InfosToSend(uint8 u8TimeSlot);
LOCAL void cil_Update_07Cx_IncorrectBlock_InfosToSend(uint8 u8BlockIndex);

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

#define CIL_START_SEC_VAR_INIT_32
#include "CIL_MemMap.h"
/**
 * \brief
 *       Variable used to determine if the next block is active
 *       Initialized to M_U32_BLOCK_MASK(M_CU8_BLOCK_ID_23) - last block
 */
LOCAL uint32 cil_u32MeasureNextBlockToSendMask = U32_CIL_BLOCK_MASK(KU8_CIL_BLOCK_ID_03);

#define CIL_STOP_SEC_VAR_INIT_32
#include "CIL_MemMap.h"

#define CIL_START_SEC_VAR_INIT_8
#include "CIL_MemMap.h"

/**
 * \brief
 *       This variable is used to store the current ECU State.
 * \initialization
 *       INIT_STATE_ACTIVE        - 40
 * \range
 *       INIT_STATE_ACTIVE        - 40;
 *       STARTUP_TWO_A            - 0;
 *       STARTUP_TWO_B            - 1;
 *       RUN_MODE_ACTIVE          - 8;
 *       POST_RUN_MODE_ACTIVE     - 9;
 *       RUN_MODE_NO_COM_ACTIVE   - 22;
 *       LOW_PWR_MODE_ACTIVE      - 10;
 *       SHUTDOWN_MODE_ACTIVE     - 11;
 *       PROCESS_MODE_ACTIVE      - 26;
 *       RUN_MODE_FROM_LOW_PWR    - 23;
 */
LOCAL uint8 cil_u8LastEcuState = KU8_CIL_INIT_STATE_ACTIVE;

/**
 * \brief
 *    Variable used to control periodicity of TX Frame
 */
LOCAL uint8 cil_u8MFPeriodCounter = KU8_ZERO;
/**
 * \brief
 *       Variable used to determine what block shall be sent next on the CAN bus
 *       Initialized to M_CU8_BLOCK_ID_23 - last block
 */
LOCAL uint8 cil_u8MeasureNextBlockToSend = KU8_CIL_BLOCK_ID_03;

/**
 * \brief
 *       Variable used to determine when a Rx frame was received
 */
LOCAL uint8 cil_u8GliwaRxFlag = KU8_ZERO;

/**
 * \brief
 *       Variable used to hold the content of the Gliwa Rx frame
 */
LOCAL REC_GliwaDataIn_Type cil_tGliwaRxFrameContent = {KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO};

/**
 * \brief
 *       Variable used to hold the time slot counter
 */
LOCAL uint8 cil_u8TimeSlotCnt = KU8_ZERO;

/**
 * \brief
 *       Variable used to determine the number of the next measurement frame
 *       block that must be sent on the CAN bus
 */
LOCAL uint8 cil_u8MeasureNextBlockSent = KU8_MAX;

#define CIL_STOP_SEC_VAR_INIT_8
#include "CIL_MemMap.h"

#define CIL_START_SEC_VAR_INIT_BOOL
#include "CIL_MemMap.h"
/**
 * \brief
 *       Variable used to determine if a time slot has expired
 */
LOCAL boolean cil_bTimeSlotExpired = KB_FALSE;

#define CIL_STOP_SEC_VAR_INIT_BOOL
#include "CIL_MemMap.h"

#define CIL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CIL_MemMap.h"

/**
 * \brief
 *       Variable used to hold the content of the measurement frame that will be
 *       sent on the CAN bus
 */
LOCAL CIL_stFrameDataBytes cil_tMeasurementFrameContent[KU8_CIL_MF_NB_OF_BLOCKS];

/**
 * \brief
 *       Variable used to hold the content of the measurement frame that will be
 *       sent on the CAN bus
 */
LOCAL REC_CanDataOut64_Type cil_tMeasurementFrameContentOnBus[KU8_CIL_MF_NB_OF_BLOCKS];

/**
 * \brief
 *       The actual content of the measurement frame that will be sent on the CAN bus (8 Byte Chunks)
 */
LOCAL REC_CanDataOut64_Type cil_u8EcuCanDataOut_Gliwa_Tx_OnBus;

#define CIL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CIL_MemMap.h"


/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/

/**
 * \brief
 *       Array of function pointers that hold the callbacks for each measurement
 *       frame block. Block 01 is position 01 of the function pointer array.
 */
LOCAL const cil_pfBlockFunction_Type cil_kapfBlocksEncodFunc[KU8_CIL_MF_NB_OF_BLOCKS] =
{
   &cil_Update_07Cx_Block01_InfosToSend,
   &cil_Update_07Cx_Block02_InfosToSend,
   &cil_Update_07Cx_Block03_InfosToSend,
};

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
#define CIL_START_SEC_CODE
#include "CIL_MemMap.h"

/**
* \brief
*        This function gather the relevant data that will be sent on the CAN bus on
*        Measurement Frame Block 01. Function is split into 5 timeslots for offsetting
*        cpu load intensive function calls
* \constrains
*        NVP_au8MeasFrameBlockConfig is configured for Block 01.
* \dynamicaspectcaller
*        cil_Update_07Cx_Block01_InfosToSend
* \dynamicaspectdescription
*        Internally called by CIL component.
* \ddesignrequirement
*        DSG_cil_Update_07Cx_Block01_Timeslot0_InfosToSend
* \archrequirement
*        ARCH_SW_CIL_prrSolenoidPWM;
*        ARCH_SW_CIL_pclEcuCharacterstics;
*        ARCH_SW_CIL_pclMcuCharacteristics;
*        ARCH_SW_CIL_pclPtcSensor;
*        ARCH_SW_CIL_pclAccSensor;
**/
LOCAL_INLINE void cil_Update_07Cx_Block01_Timeslot0_InfosToSend(void)
{
   sint16 s16McuTemperature = KS16_ZERO;
   sint16 s16AccTemperature = KS16_ZERO;
   sint16 s16PtcSensorTemperature = KS16_ZERO;
   sint16 s16EcuTemperature = KS16_ZERO;
   uint8 au8LowResolutionPwm[(KU8_MAX_SOLENOID_NB)];
   uint16 au16SolenoidPWM[sizeof(au16PwmType)];
   uint8 u8Idx = KU8_ZERO;

   /* Get MCU, Accelerometer, PTC Sensor and ECU temperature */
   (void)Rte_Call_pclMcuCharacteristics_GetTemperature(&s16McuTemperature);
   (void)Rte_Call_pclAccSensor_GetTemperature(&s16AccTemperature);
   (void)Rte_Call_pclPtcSensor_GetTemperature(&s16PtcSensorTemperature);
   (void)Rte_Call_pclEcuCharacterstics_GetTemperature(&s16EcuTemperature);

   /* Get all solenoid PWM in high resolution */
   (void)Rte_Read_prrSolenoidPWM_au16Pwm(au16SolenoidPWM);

   /* Lower PWM resolution. 1 byte per solenoid. Resolution: 2^-1 <> 1 lsb = 0.5% */
   for (u8Idx = KU8_ZERO; u8Idx < (uint8)KU8_GLOBAL_NUMBER_OF_SOLENOIDS; u8Idx++)
   {
      /* Change from 2^-15 [0 ; 1] to 2^-1 [0 ; 100] */
      au8LowResolutionPwm[u8Idx] = (uint8)((uint32)(au16SolenoidPWM[u8Idx] * KU8_ONE_HUNDRED) >> KU8_FOURTEEN);
   }

   /* Fill the frame with aquired data */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte0 = KU8_CIL_BLOCK_ID_01;
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte1  = U16_GET_LOW_BYTE((uint16)s16McuTemperature);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte2  = U16_GET_HIGH_BYTE((uint16)s16McuTemperature);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte3  = U16_GET_LOW_BYTE((uint16)s16AccTemperature);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte4  = U16_GET_HIGH_BYTE((uint16)s16AccTemperature);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte5  = U16_GET_LOW_BYTE((uint16)s16PtcSensorTemperature);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte6  = U16_GET_HIGH_BYTE((uint16)s16PtcSensorTemperature);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte7  = U16_GET_HIGH_BYTE((uint16)s16EcuTemperature);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte8  = U16_GET_LOW_BYTE((uint16)s16EcuTemperature);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte9  = au8LowResolutionPwm[KU8_ZERO];
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte10 = au8LowResolutionPwm[KU8_ONE];
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte11 = au8LowResolutionPwm[KU8_TWO];
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte12 = au8LowResolutionPwm[KU8_THREE];
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte13 = au8LowResolutionPwm[KU8_FOUR];
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte14 = au8LowResolutionPwm[KU8_FIVE];

   cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u64Byte_0_7   = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte0);
}

/**
* \brief
*        This function gather the relevant data that will be sent on the CAN bus on
*        Measurement Frame Block 01. Function is split into 5 timeslots for offsetting
*        cpu load intensive function calls
* \constrains
*        NVP_au8MeasFrameBlockConfig is configured for Block 01.
* \dynamicaspectcaller
*        cil_Update_07Cx_Block01_InfosToSend
* \dynamicaspectdescription
*        Internally called by CIL component.
* \ddesignrequirement
*        DSG_cil_Update_07Cx_Block01_Timeslot1_InfosToSend
* \archrequirement
*        ARCH_SW_CIL_pclConvAdcService
**/
LOCAL_INLINE void cil_Update_07Cx_Block01_Timeslot1_InfosToSend(void)
{
   uint16 au16SolenoidVoltageHifi[KU8_MAX_SOLENOID_NB];
   uint8 u8Idx = KU8_ZERO;

   /* Parse all solenoids to get their voltage value */
   for (u8Idx = KU8_ZERO; u8Idx < (uint8)KU8_GLOBAL_NUMBER_OF_SOLENOIDS; u8Idx++)
   {
      /* Get measure voltage */
      (void)Rte_Call_pclConvAdcService_getMeasure((KU8_ADC_CH_ID_MAG_V_1 + u8Idx), &au16SolenoidVoltageHifi[u8Idx]);
   }

   /* Fill the frame with aquired data */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte15 = U16_GET_LOW_BYTE(au16SolenoidVoltageHifi[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte16 = U16_GET_HIGH_BYTE(au16SolenoidVoltageHifi[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte17 = U16_GET_LOW_BYTE(au16SolenoidVoltageHifi[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte18 = U16_GET_HIGH_BYTE(au16SolenoidVoltageHifi[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte19 = U16_GET_LOW_BYTE(au16SolenoidVoltageHifi[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte20 = U16_GET_HIGH_BYTE(au16SolenoidVoltageHifi[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte21 = U16_GET_LOW_BYTE(au16SolenoidVoltageHifi[KU8_THREE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte22 = U16_GET_HIGH_BYTE(au16SolenoidVoltageHifi[KU8_THREE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte23 = U16_GET_LOW_BYTE(au16SolenoidVoltageHifi[KU8_FOUR]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte24 = U16_GET_HIGH_BYTE(au16SolenoidVoltageHifi[KU8_FOUR]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte25 = U16_GET_LOW_BYTE(au16SolenoidVoltageHifi[KU8_FIVE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte26 = U16_GET_HIGH_BYTE(au16SolenoidVoltageHifi[KU8_FIVE]);

   cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u64Byte_8_15  = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte8);
   cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u64Byte_16_23 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte16);

}

/**
* \brief
*        This function gather the relevant data that will be sent on the CAN bus on
*        Measurement Frame Block 01. Function is split into 5 timeslots for offsetting
*        cpu load intensive function calls
* \constrains
*        NVP_au8MeasFrameBlockConfig is configured for Block 01.
* \dynamicaspectcaller
*        cil_Update_07Cx_Block01_InfosToSend
* \dynamicaspectdescription
*        Internally called by CIL component.
* \ddesignrequirement
*        DSG_cil_Update_07Cx_Block01_Timeslot2_InfosToSend
* \archrequirement
*        ARCH_SW_CIL_pclConvAdcService
**/
LOCAL_INLINE void cil_Update_07Cx_Block01_Timeslot2_InfosToSend(void)
{
   uint16 au16SolenoidCurrentHifi[KU8_MAX_SOLENOID_NB];
   uint8 u8Idx = KU8_ZERO;

   /* Parse all solenoids to get their current value */
   for (u8Idx = KU8_ZERO; u8Idx < (uint8)KU8_GLOBAL_NUMBER_OF_SOLENOIDS; u8Idx++)
   {
      /* Get measure current */
      (void)Rte_Call_pclConvAdcService_getMeasure((KU8_ADC_CH_ID_MAG_I_1 + u8Idx), &au16SolenoidCurrentHifi[u8Idx]);
   }

   /* Fill the frame with aquired data */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte27 = U16_GET_LOW_BYTE(au16SolenoidCurrentHifi[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte28 = U16_GET_HIGH_BYTE(au16SolenoidCurrentHifi[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte29 = U16_GET_LOW_BYTE(au16SolenoidCurrentHifi[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte30 = U16_GET_HIGH_BYTE(au16SolenoidCurrentHifi[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte31 = U16_GET_LOW_BYTE(au16SolenoidCurrentHifi[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte32 = U16_GET_HIGH_BYTE(au16SolenoidCurrentHifi[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte33 = U16_GET_LOW_BYTE(au16SolenoidCurrentHifi[KU8_THREE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte34 = U16_GET_HIGH_BYTE(au16SolenoidCurrentHifi[KU8_THREE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte35 = U16_GET_LOW_BYTE(au16SolenoidCurrentHifi[KU8_FOUR]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte36 = U16_GET_HIGH_BYTE(au16SolenoidCurrentHifi[KU8_FOUR]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte37 = U16_GET_LOW_BYTE(au16SolenoidCurrentHifi[KU8_FIVE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte38 = U16_GET_HIGH_BYTE(au16SolenoidCurrentHifi[KU8_FIVE]);

   cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u64Byte_24_31 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte24);

}

/**
* \brief
*        This function gather the relevant data that will be sent on the CAN bus on
*        Measurement Frame Block 01. Function is split into 5 timeslots for offsetting
*        cpu load intensive function calls
* \constrains
*        NVP_au8MeasFrameBlockConfig is configured for Block 01.
* \dynamicaspectcaller
*        cil_Update_07Cx_Block01_InfosToSend
* \dynamicaspectdescription
*        Internally called by CIL component.
* \ddesignrequirement
*        DSG_cil_Update_07Cx_Block02_Timeslot3_InfosToSend
* \archrequirement
*        ARCH_SW_CIL_pclConvAdcService;
*        ARCH_SW_CIL_prrSolenoidShortToGndStatus;
*        ARCH_SW_CIL_prrSolenoidShortToVccStatus;
*        ARCH_SW_CIL_prrSolenoidOCStatus;
*        ARCH_SW_CIL_pclSolenoidCharacteristics;
**/
LOCAL_INLINE void cil_Update_07Cx_Block01_Timeslot3_InfosToSend(void)
{
   u16AdcValueLsbType u16VBatt = KU16_ZERO;
   u16AdcValueLsbType u16VBoost = KU16_ZERO;
   sint16 as16SolenoidTemp[KU8_MAX_SOLENOID_NB];
   uint8 u8Idx = KU8_ZERO;
   uint8 au8SolenoidErrorPresentOpenCircuit[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidErrorPresentShortToGND[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidErrorPresentShortToVBAT[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   register uint8 u8SolenoidOpenCircuitStatus = KU8_ZERO;
   register uint8 u8SolenoidShortToGNDStatus = KU8_ZERO;
   register uint8 u8SolenoidShortToVBATStatus = KU8_ZERO;

   /* KL30 */
   (void)Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_V_BATT, &u16VBatt);

   /* Boost Diag */
   (void)Rte_Call_pclConvAdcService_getMeasure(KU8_ADC_CH_ID_BOOST_DIAG, &u16VBoost);

   /* Get all solenoid error status */
   (void)Rte_Read_prrSolenoidOCStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentOpenCircuit);
   (void)Rte_Read_prrSolenoidShortToGndStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentShortToGND);
   (void)Rte_Read_prrSolenoidShortToVccStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentShortToVBAT);

   for (u8Idx = KU8_ZERO; u8Idx < (uint8)KU8_GLOBAL_NUMBER_OF_SOLENOIDS; u8Idx++ )
   {
      /* Parse all solenoids to get their temperature value */
      (void)Rte_Call_pclSolenoidCharacteristics_GetTemperature(KU8_ADC_CH_ID_SOLENOID_TEMP_1 + u8Idx, &as16SolenoidTemp[u8Idx]);

      /* Parse all solenoids to get their error status */
      /* Variable mapping: LSB -> Solenoid 0, MSB -> Solenoid 6 */
      /* Variable mapping for variables u8SolenoidOpenCircuitStatus, u8SolenoidShortToGNDStatus, u8SolenoidShortToVBATStatus: */
      /* 1 means NOK, 0 means OK */
      /* 0 | 0 | Sol6 | Sol5 | Sol4 | Sol3 | Sol2 | Sol1 */
      u8SolenoidOpenCircuitStatus |= (uint8)((au8SolenoidErrorPresentOpenCircuit[u8Idx] & KU8_ONE) << u8Idx);
      u8SolenoidShortToGNDStatus |= (uint8)((au8SolenoidErrorPresentShortToGND[u8Idx] & KU8_ONE) << u8Idx);
      u8SolenoidShortToVBATStatus |= (uint8)((au8SolenoidErrorPresentShortToVBAT[u8Idx] & KU8_ONE) << u8Idx);
   }

   /* Fill the frame with aquired data */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte39 = (uint8)((uint8)as16SolenoidTemp[KU8_ZERO] + KU8_CIL_TEMPERATURE_OFFSET);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte40 = (uint8)((uint8)as16SolenoidTemp[KU8_ONE] + KU8_CIL_TEMPERATURE_OFFSET);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte41 = (uint8)((uint8)as16SolenoidTemp[KU8_TWO] + KU8_CIL_TEMPERATURE_OFFSET);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte42 = (uint8)((uint8)as16SolenoidTemp[KU8_THREE] + KU8_CIL_TEMPERATURE_OFFSET);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte43 = (uint8)((uint8)as16SolenoidTemp[KU8_FOUR] + KU8_CIL_TEMPERATURE_OFFSET);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte44 = (uint8)((uint8)as16SolenoidTemp[KU8_FIVE] + KU8_CIL_TEMPERATURE_OFFSET);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte45 = U16_GET_HIGH_BYTE(u16VBatt);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte46 = U16_GET_LOW_BYTE(u16VBatt);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte47 = u8SolenoidOpenCircuitStatus;
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte48 = u8SolenoidShortToGNDStatus;
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte49 = u8SolenoidShortToVBATStatus;
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte60 = U16_GET_HIGH_BYTE(u16VBoost);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte61 = U16_GET_LOW_BYTE(u16VBoost);

   cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u64Byte_32_39 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte32);
   cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u64Byte_40_47 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte40);
}

/**
* \brief
*        This function gather the relevant data that will be sent on the CAN bus on
*        Measurement Frame Block 01. Function is split into 5 timeslots for offsetting
*        cpu load intensive function calls
* \constrains
*        NVP_au8MeasFrameBlockConfig is configured for Block 01.
* \dynamicaspectcaller
*        cil_Update_07Cx_Block01_InfosToSend
* \dynamicaspectdescription
*        Internally called by CIL component.
* \ddesignrequirement
*        DSG_cil_Update_07Cx_Block02_Timeslot4_InfosToSend
* \archrequirement
*        ARCH_SW_CIL_prrSolenoidStuckStatus;
*        ARCH_SW_CIL_prrSbcStatusFailiureSource;
*        ARCH_SW_CIL_prrAccStatusFailiureSource;
*        ARCH_SW_CIL_prrSolenoidOvervoltageStatus;
**/
LOCAL_INLINE void cil_Update_07Cx_Block01_Timeslot4_InfosToSend(void)
{
   uint32 u32AccAlarmRegistersData = KU32_ZERO;
   uint32 u32SbcStatusRegistersData = KU32_ZERO;
   uint8 au8SolenoidIsStuck[KU8_MAX_SOLENOID_NB];
   uint8 au8SolenoidOvervoltageStatus[KU8_MAX_SOLENOID_NB];
   uint8 u8Idx = KU8_ZERO;
   uint8 u8ActuatorBlockedStatus = KU8_ZERO;
   uint8 u8AccReturnStatus = KU8_ZERO;
   uint8 u8AccCRCStatus = KU8_ZERO;
   uint8 u8AccAlarmbPreinitSeqStatus = KU8_ZERO;
   uint8 u8AccelAxisBroken = KU8_ZERO;
   uint8 u8SolenoidOvervoltageStatus = KU8_ZERO;

   /* Get TDK Accelerometer Alarms data */
   (void)Rte_Read_prrAccStatusFailiureSource_u32AccAlarmRegStatus(&u32AccAlarmRegistersData);

   /* Get Crc error flag */ 
   (void)Rte_Read_prrAccStatusFailiureSource_u8AccCRCStatus(&u8AccCRCStatus);
   /* Get Return Status error flag */
   (void)Rte_Read_prrAccStatusFailiureSource_u8AccReturnStatus(&u8AccReturnStatus);
   /* Get Alarmb Preinit Sequence Status error flag */
   (void)Rte_Read_prrAccStatusFailiureSource_u8AccAlarmbPreinitSeqStatus(&u8AccAlarmbPreinitSeqStatus);
   /* Get Accelerometer axis broken error flag 
   data in u8AccelAxisBroken = 0b00000xyz */
   (void)Rte_Read_prrAccStatusFailiureSource_u8AccelAxisBroken(&u8AccelAxisBroken);
   

   /* Get SBC status registers data */
   (void)Rte_Read_prrSbcStatusFailiureSource_u32SbcReg1Status(&u32SbcStatusRegistersData);

   (void)Rte_Read_prrSolenoidStuckStatus_au8SolenoidIsStuck((uint8 *)&au8SolenoidIsStuck[0]);

   (void)Rte_Read_prrSolenoidOvervoltageStatus_au8SolenoidOvervoltageStatus((uint8 *)&au8SolenoidOvervoltageStatus[0]);

   /* Parse all solenoids to get their voltage value */
   for (u8Idx = KU8_ZERO; u8Idx < (uint8)KU8_GLOBAL_NUMBER_OF_SOLENOIDS; u8Idx++)
   {
      if(KU8_TRUE == au8SolenoidIsStuck[u8Idx])
      {
         u8ActuatorBlockedStatus |= (uint8)(KU8_ONE << u8Idx);
      }

      u8SolenoidOvervoltageStatus |= (uint8)((au8SolenoidOvervoltageStatus[u8Idx] & KU8_ONE) << u8Idx);
   }

   /* Fill the frame with aquired data */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte50 = U32_GET_HIGH_BYTE(u32SbcStatusRegistersData);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte51 = U32_GET_HIGH_MIDDLE_BYTE(u32SbcStatusRegistersData);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte52 = U32_GET_LOW_MIDDLE_BYTE(u32SbcStatusRegistersData);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte53 = U32_GET_LOW_BYTE(u32SbcStatusRegistersData);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte54 = U32_GET_HIGH_BYTE(u32AccAlarmRegistersData);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte55 = U32_GET_HIGH_MIDDLE_BYTE(u32AccAlarmRegistersData);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte56 = U32_GET_LOW_MIDDLE_BYTE(u32AccAlarmRegistersData);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte57 = U32_GET_LOW_BYTE(u32AccAlarmRegistersData);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte58 = ((uint8)(u8AccelAxisBroken << KU8_THREE)) | ((uint8)(u8AccAlarmbPreinitSeqStatus << KU8_TWO)) | ((uint8)(u8AccCRCStatus << KU8_ONE)) | u8AccReturnStatus;
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte59 = u8ActuatorBlockedStatus;
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte62 = u8SolenoidOvervoltageStatus;
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte63 = KU8_MAX;

   cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u64Byte_48_55 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte48);
   cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u64Byte_56_63 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_01 - KU8_ONE].u8Byte56);
}

/**
* \brief
*        This function gather the relevant data that will be sent on the CAN bus on
*        Measurement Frame Block 03. Function is split into 5 timeslots for offsetting
*        cpu load intensive function calls
* \inputparam
*        Name: u32DataToDisplay;
*        Type: uint32 *;
*        Description: Data pointer to data that should be displayed on the CAN bus;
*        Range: 0..5;
* \constrains
*        NVP_au8MeasFrameBlockConfig is configured for Block 01.
* \dynamicaspectcaller
*        cil_Update_07Cx_Block03_InfosToSend
* \dynamicaspectdescription
*        Internally called by CIL component.
* \ddesignrequirement
*        DSG_cil_Update_07Cx_Block03_Timeslot0_InfosToSend
* \archrequirement
*        ARCH_SW_CIL_P_CAN_MF_Frame
**/
LOCAL_INLINE void cil_Update_07Cx_Block03_Timeslot0_InfosToSend(uint32 *u32DataToDisplay)
{
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte0 = KU8_CIL_BLOCK_ID_03;

   /* Reserved for 1st RAM address */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte1  = U32_GET_LOW_BYTE(u32DataToDisplay[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte2  = U32_GET_LOW_MIDDLE_BYTE(u32DataToDisplay[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte3  = U32_GET_HIGH_MIDDLE_BYTE(u32DataToDisplay[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte4  = U32_GET_HIGH_BYTE(u32DataToDisplay[KU8_ZERO]);

   /* Reserved for 2nd RAM address */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte5  = U32_GET_LOW_BYTE(u32DataToDisplay[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte6  = U32_GET_LOW_MIDDLE_BYTE(u32DataToDisplay[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte7  = U32_GET_HIGH_MIDDLE_BYTE(u32DataToDisplay[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte8  = U32_GET_HIGH_BYTE(u32DataToDisplay[KU8_ONE]);

   /* Reserved for 3rd RAM address */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte9  = U32_GET_LOW_BYTE(u32DataToDisplay[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte10 = U32_GET_LOW_MIDDLE_BYTE(u32DataToDisplay[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte11 = U32_GET_HIGH_MIDDLE_BYTE(u32DataToDisplay[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte12 = U32_GET_HIGH_BYTE(u32DataToDisplay[KU8_TWO]);

   cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u64Byte_0_7   = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte0);
}

/**
* \brief
*        This function gather the relevant data that will be sent on the CAN bus on
*        Measurement Frame Block 03. Function is split into 5 timeslots for offsetting
*        cpu load intensive function calls
* \inputparam
*        Name: u32DataToDisplay;
*        Type: uint32 *;
*        Description: Data pointer to data that should be displayed on the CAN bus;
*        Range: 0..5;
* \constrains
*        NVP_au8MeasFrameBlockConfig is configured for Block 01.
* \dynamicaspectcaller
*        cil_Update_07Cx_Block03_InfosToSend
* \dynamicaspectdescription
*        Internally called by CIL component.
* \ddesignrequirement
*        DSG_cil_Update_07Cx_Block03_Timeslot1_InfosToSend
* \archrequirement
*        ARCH_SW_CIL_P_CAN_MF_Frame
**/
LOCAL_INLINE void cil_Update_07Cx_Block03_Timeslot1_InfosToSend(uint32 *u32DataToDisplay)
{
   /* Reserved for 4th RAM address */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte13 = U32_GET_LOW_BYTE(u32DataToDisplay[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte14 = U32_GET_LOW_MIDDLE_BYTE(u32DataToDisplay[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte15 = U32_GET_HIGH_MIDDLE_BYTE(u32DataToDisplay[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte16 = U32_GET_HIGH_BYTE(u32DataToDisplay[KU8_ZERO]);

   /* Reserved for 5th RAM address */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte17 = U32_GET_LOW_BYTE(u32DataToDisplay[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte18 = U32_GET_LOW_MIDDLE_BYTE(u32DataToDisplay[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte19 = U32_GET_HIGH_MIDDLE_BYTE(u32DataToDisplay[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte20 = U32_GET_HIGH_BYTE(u32DataToDisplay[KU8_ONE]);

   /* Reserved for 6th RAM address */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte21 = U32_GET_LOW_BYTE(u32DataToDisplay[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte22 = U32_GET_LOW_MIDDLE_BYTE(u32DataToDisplay[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte23 = U32_GET_HIGH_MIDDLE_BYTE(u32DataToDisplay[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte24 = U32_GET_HIGH_BYTE(u32DataToDisplay[KU8_TWO]);

   cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u64Byte_8_15  = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte8);
   cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u64Byte_16_23 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte16);
}

/**
* \brief
*        This function gather the relevant data that will be sent on the CAN bus on
*        Measurement Frame Block 03. Function is split into 5 timeslots for offsetting
*        cpu load intensive function calls
* \inputparam
*        Name: u32DataToDisplay;
*        Type: uint32 *;
*        Description: Data pointer to data that should be displayed on the CAN bus;
*        Range: 0..5;
* \constrains
*        NVP_au8MeasFrameBlockConfig is configured for Block 01.
* \dynamicaspectcaller
*        cil_Update_07Cx_Block03_InfosToSend
* \dynamicaspectdescription
*        Internally called by CIL component.
* \ddesignrequirement
*        DSG_cil_Update_07Cx_Block03_Timeslot2_InfosToSend
* \archrequirement
*        ARCH_SW_CIL_P_CAN_MF_Frame
**/
LOCAL_INLINE void cil_Update_07Cx_Block03_Timeslot2_InfosToSend(uint32 *u32DataToDisplay)
{
   /* Reserved for 7th RAM address */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte25 = U32_GET_LOW_BYTE(u32DataToDisplay[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte26 = U32_GET_LOW_MIDDLE_BYTE(u32DataToDisplay[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte27 = U32_GET_HIGH_MIDDLE_BYTE(u32DataToDisplay[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte28 = U32_GET_HIGH_BYTE(u32DataToDisplay[KU8_ZERO]);

   /* Reserved for 8th RAM address */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte29 = U32_GET_LOW_BYTE(u32DataToDisplay[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte30 = U32_GET_LOW_MIDDLE_BYTE(u32DataToDisplay[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte31 = U32_GET_HIGH_MIDDLE_BYTE(u32DataToDisplay[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte32 = U32_GET_HIGH_BYTE(u32DataToDisplay[KU8_ONE]);

   /* Reserved for 9th RAM address */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte33 = U32_GET_LOW_BYTE(u32DataToDisplay[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte34 = U32_GET_LOW_MIDDLE_BYTE(u32DataToDisplay[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte35 = U32_GET_HIGH_MIDDLE_BYTE(u32DataToDisplay[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte36 = U32_GET_HIGH_BYTE(u32DataToDisplay[KU8_TWO]);

   cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u64Byte_24_31 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte24);
}


/**
* \brief
*        This function gather the relevant data that will be sent on the CAN bus on
*        Measurement Frame Block 03. Function is split into 5 timeslots for offsetting
*        cpu load intensive function calls
* \inputparam
*        Name: u32DataToDisplay;
*        Type: uint32 *;
*        Description: Data pointer to data that should be displayed on the CAN bus;
*        Range: 0..5;
* \constrains
*        NVP_au8MeasFrameBlockConfig is configured for Block 01.
* \dynamicaspectcaller
*        cil_Update_07Cx_Block03_InfosToSend
* \dynamicaspectdescription
*        Internally called by CIL component.
* \ddesignrequirement
*        DSG_cil_Update_07Cx_Block03_Timeslot3_InfosToSend
* \archrequirement
*        ARCH_SW_CIL_P_CAN_MF_Frame
**/
LOCAL_INLINE void cil_Update_07Cx_Block03_Timeslot3_InfosToSend(uint32 *u32DataToDisplay)
{
   /* Reserved for 10th RAM address */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte37 = U32_GET_LOW_BYTE(u32DataToDisplay[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte38 = U32_GET_LOW_MIDDLE_BYTE(u32DataToDisplay[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte39 = U32_GET_HIGH_MIDDLE_BYTE(u32DataToDisplay[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte40 = U32_GET_HIGH_BYTE(u32DataToDisplay[KU8_ZERO]);

   /* Reserved for 11th RAM address */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte41 = U32_GET_LOW_BYTE(u32DataToDisplay[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte42 = U32_GET_LOW_MIDDLE_BYTE(u32DataToDisplay[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte43 = U32_GET_HIGH_MIDDLE_BYTE(u32DataToDisplay[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte44 = U32_GET_HIGH_BYTE(u32DataToDisplay[KU8_ONE]);

   /* Reserved for 12th RAM address */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte45 = U32_GET_LOW_BYTE(u32DataToDisplay[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte46 = U32_GET_LOW_MIDDLE_BYTE(u32DataToDisplay[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte47 = U32_GET_HIGH_MIDDLE_BYTE(u32DataToDisplay[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte48 = U32_GET_HIGH_BYTE(u32DataToDisplay[KU8_TWO]);

   cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u64Byte_32_39 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte32);
   cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u64Byte_40_47 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte40);
}

/**
* \brief
*        This function gather the relevant data that will be sent on the CAN bus on
*        Measurement Frame Block 03. Function is split into 5 timeslots for offsetting
*        cpu load intensive function calls
* \inputparam
*        Name: u32DataToDisplay;
*        Type: uint32 *;
*        Description: Data pointer to data that should be displayed on the CAN bus;
*        Range: 0..5;
* \constrains
*        NVP_au8MeasFrameBlockConfig is configured for Block 01.
* \dynamicaspectcaller
*        cil_Update_07Cx_Block03_InfosToSend
* \dynamicaspectdescription
*        Internally called by CIL component.
* \ddesignrequirement
*        DSG_cil_Update_07Cx_Block03_Timeslot4_InfosToSend
* \archrequirement
*        ARCH_SW_CIL_P_CAN_MF_Frame
**/
LOCAL_INLINE void cil_Update_07Cx_Block03_Timeslot4_InfosToSend(uint32 *u32DataToDisplay)
{
   /* Reserved for 13th RAM address */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte49 = U32_GET_LOW_BYTE(u32DataToDisplay[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte50 = U32_GET_LOW_MIDDLE_BYTE(u32DataToDisplay[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte51 = U32_GET_HIGH_MIDDLE_BYTE(u32DataToDisplay[KU8_ZERO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte52 = U32_GET_HIGH_BYTE(u32DataToDisplay[KU8_ZERO]);

   /* Reserved for 14th RAM address */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte53 = U32_GET_LOW_BYTE(u32DataToDisplay[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte54 = U32_GET_LOW_MIDDLE_BYTE(u32DataToDisplay[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte55 = U32_GET_HIGH_MIDDLE_BYTE(u32DataToDisplay[KU8_ONE]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte56 = U32_GET_HIGH_BYTE(u32DataToDisplay[KU8_ONE]);

   /* Reserved for 15th RAM address */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte57 = U32_GET_LOW_BYTE(u32DataToDisplay[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte58 = U32_GET_LOW_MIDDLE_BYTE(u32DataToDisplay[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte59 = U32_GET_HIGH_MIDDLE_BYTE(u32DataToDisplay[KU8_TWO]);
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte60 = U32_GET_HIGH_BYTE(u32DataToDisplay[KU8_TWO]);

   /* Unused bytes */
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte61 = KU8_MAX;
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte62 = KU8_MAX;
   cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte63 = KU8_MAX;

   cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u64Byte_48_55 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte48);
   cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u64Byte_56_63 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_03 - KU8_ONE].u8Byte56);
}

/**
* \brief
*        This function fill the CAN buffer for the measurement frame sent
*        when the block number to send is 01. Content of Block 01 on the CAN bus
*        will be various physical measurements internal to the uC
* \constrains
*        NVP_au8MeasFrameBlockConfig is configured for Block 01.
* \dynamicaspectcaller
*        CIL_runManageMF
* \dynamicaspectdescription
*        Internally called by CIL component.
* \ddesignrequirement
*        DSG_cil_Update_07Cx_Block01_InfosToSend
* \archrequirement
*        ARCH_SW_CIL_P_CAN_MF_Frame
**/
LOCAL_INLINE void cil_Update_07Cx_Block01_InfosToSend(uint8 u8TimeSlot)
{
   /******************************************/
   /* Read infos from application components */
   /******************************************/
   switch(u8TimeSlot)
   {
   case KU8_CIL_TIME_SLOT_0:

      /* function call for block 0 timeslot 0 */
      cil_Update_07Cx_Block01_Timeslot0_InfosToSend();
      
      break;
   case KU8_CIL_TIME_SLOT_1:

      /* function call for block 0 timeslot 1 */
      cil_Update_07Cx_Block01_Timeslot1_InfosToSend();
      
      break;
   case KU8_CIL_TIME_SLOT_2:

      /* function call for block 0 timeslot 2 */
      cil_Update_07Cx_Block01_Timeslot2_InfosToSend();

      break;
   case KU8_CIL_TIME_SLOT_3:
      
      /* function call for block 0 timeslot 3 */
      cil_Update_07Cx_Block01_Timeslot3_InfosToSend();

      break;
   case KU8_CIL_TIME_SLOT_4:

      /* function call for block 0 timeslot 4 */
      cil_Update_07Cx_Block01_Timeslot4_InfosToSend();

      break;
   default:
      /* function called with wrong argument */
      cil_Update_07Cx_IncorrectBlock_InfosToSend(KU8_CIL_MF_INVALID_BLOCK_ID);
      break;
   }
}

/**
* \brief
*        This function fill the CAN buffer for the measurement frame sent
*        when the block number to send is 02. Content of Block 02 on the CAN bus
*        will reflect the current Dem Event status for all Events.
* \constrains
*        NVP_au8MeasFrameBlockConfig is configured for Block 02.
* \dynamicaspectcaller
*        CIL_runManageMF
* \dynamicaspectdescription
*        Internally called by CIL component.
* \ddesignrequirement
*        DSG_cil_Update_07Cx_Block02_InfosToSend
* \archrequirement
*        ARCH_SW_CIL_P_CAN_MF_Frame
**/
LOCAL_INLINE void cil_Update_07Cx_Block02_InfosToSend(uint8 u8TimeSlot)
{
   uint16 u16IndexEvent = KU8_ZERO;
   uint16 u16LowEventLimit = KU8_ZERO;
   uint16 u16HighEventLimit = KU8_ZERO;
   uint8 u8Idx;

   u16HighEventLimit = ((uint16)DEM_NUMBER_OF_EVENTS - ((uint16)u8TimeSlot * (((uint16)DEM_NUMBER_OF_EVENTS/KU8_CIL_TIME_SLOTS) + KU16_ONE)));

   /* Decide filling range based on the timeslot */
   if (u16HighEventLimit >= ((uint16)DEM_NUMBER_OF_EVENTS/KU8_CIL_TIME_SLOTS) + KU16_ONE)
   {
      u16LowEventLimit = (u16HighEventLimit - ((((uint16)DEM_NUMBER_OF_EVENTS/(uint16)KU8_CIL_TIME_SLOTS)) + KU16_ONE));
   }
   else
   {
      u16LowEventLimit = KU16_ZERO;
   }

   /* Fill frame will information  known */
   for(u16IndexEvent = u16HighEventLimit; u16IndexEvent > u16LowEventLimit; u16IndexEvent--)
   {
      *((uint8*) (((uint8 *)&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u8Byte1) + ((u16IndexEvent * KU8_TWO) - KU8_TWO))) = u16IndexEvent;
      (void)Dem_GetEventStatus(u16IndexEvent, (((uint8 *)&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u8Byte1) + (u16IndexEvent * KU8_TWO) - 0x01));
   }

   /* Fill ID and the rest of the frame on the last timeslot */
   if (KU8_CIL_TIME_SLOT_4 == u8TimeSlot)
   {
      cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u8Byte0 = KU8_CIL_BLOCK_ID_02;

      for(u8Idx = (((DEM_NUMBER_OF_EVENTS-KU8_ONE) * KU8_TWO) + KU8_ONE); u8Idx < KU8_SIXTYFOUR; u8Idx++)
      {
         *((uint8*)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u8Byte0 + u8Idx)) = KU8_MAX;
      }

      cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u64Byte_0_7   = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u8Byte0);
      cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u64Byte_8_15  = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u8Byte8);
      cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u64Byte_16_23 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u8Byte16);
      cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u64Byte_24_31 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u8Byte24);
      cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u64Byte_32_39 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u8Byte32);
      cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u64Byte_40_47 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u8Byte40);
      cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u64Byte_48_55 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u8Byte48);
      cil_tMeasurementFrameContentOnBus[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u64Byte_56_63 = *(uint64 *)(&cil_tMeasurementFrameContent[KU8_CIL_BLOCK_ID_02 - KU8_ONE].u8Byte56);
   }
}

/**
* \brief
*        This function fill the CAN buffer for the measurement frame sent
*        when the block number to send is 03. Content of block 3 on the CAN bus
*        will be values present at certain RAM addresses as configured in
*        NVP_au32RequestedRamAddressArray and NVP_au8RequestedRamSizeArray
* \constrains
*        NVP_au8MeasFrameBlockConfig is configured for Block 03.
* \dynamicaspectcaller
*        CIL_runManageMF
* \dynamicaspectdescription
*        Internally called by CIL component.
* \ddesignrequirement
*        DSG_cil_Update_07Cx_Block03_InfosToSend
* \archrequirement
*        ARCH_SW_CIL_P_CAN_MF_Frame
**/
LOCAL_INLINE void cil_Update_07Cx_Block03_InfosToSend(uint8 u8TimeSlot)
{
   uint8 *pu8Data;
   uint8 u8FirstIndex = KU8_ZERO;
   uint8 u8SecondIndex = KU8_ZERO;
   uint8 u8RamAddressToPutOnMf[KU8_FOUR] = {KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO};
   uint32 u32DataToDisplay[KU8_FIFTEEN] = {KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO,
                                           KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO,
                                           KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO};

   uint8 u8LowIndex, u8HighIndex;

   /* Decide range to check based on time slot */
   u8LowIndex = u8TimeSlot * KU8_THREE;
   u8HighIndex = u8LowIndex + KU8_THREE;
   
   /* Verify if valid RAM address was requested to be read */
   for(u8FirstIndex = u8LowIndex; u8FirstIndex < u8HighIndex; u8FirstIndex++)
   {
      if(((NVP_au32RequestedRamAddressArray[u8FirstIndex] >= (Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_E2P_MEMORY_ID_INDEX].ReadMemoryRangeInfo[KU8_DCM_READ_RAM_SHADOW_MEMORY_ID_INDEX]).MemoryRangeLow) &&
          (NVP_au32RequestedRamAddressArray[u8FirstIndex] <= (Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_E2P_MEMORY_ID_INDEX].ReadMemoryRangeInfo[KU8_DCM_READ_RAM_SHADOW_MEMORY_ID_INDEX]).MemoryRangeHigh)) ||
         ((NVP_au32RequestedRamAddressArray[u8FirstIndex] >= (Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_E2P_MEMORY_ID_INDEX].ReadMemoryRangeInfo[KU8_DCM_READ_RAM_APPLI_MEMORY_ID_INDEX]).MemoryRangeLow)   &&
          (NVP_au32RequestedRamAddressArray[u8FirstIndex] <= (Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_E2P_MEMORY_ID_INDEX].ReadMemoryRangeInfo[KU8_DCM_READ_RAM_APPLI_MEMORY_ID_INDEX]).MemoryRangeHigh))  ||
         ((NVP_au32RequestedRamAddressArray[u8FirstIndex] >= (Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_E2P_MEMORY_ID_INDEX].ReadMemoryRangeInfo[KU8_DCM_READ_RAM_NO_INIT_MEMORY_ID_INDEX]).MemoryRangeLow) &&
          (NVP_au32RequestedRamAddressArray[u8FirstIndex] <= (Dcm_MemoryIdInfoAndIdValueTable[KU8_DCM_E2P_MEMORY_ID_INDEX].ReadMemoryRangeInfo[KU8_DCM_READ_RAM_NO_INIT_MEMORY_ID_INDEX]).MemoryRangeHigh)))
      {
         /* Access to direct memory */
         pu8Data = (uint8 *)NVP_au32RequestedRamAddressArray[u8FirstIndex];  

         /* Save into a local variable the number of requested bytes */
         for(u8SecondIndex = KU8_ZERO; u8SecondIndex < NVP_au8RequestedRamSizeArray[u8FirstIndex]; u8SecondIndex++)
         {
            u8RamAddressToPutOnMf[u8SecondIndex] = pu8Data[u8SecondIndex];
         } 

         /* Cast 4 uint8 to an uint32 */
         u32DataToDisplay[u8FirstIndex] = (uint32)(
                                          ((uint32)(u8RamAddressToPutOnMf[KU8_THREE]) << KU8_POS_L_HIGH_BYTE) |
                                          ((uint32)(u8RamAddressToPutOnMf[KU8_TWO]) << KU8_POS_L_HIGH_MIDDLE_BYTE) |
                                          ((uint32)(u8RamAddressToPutOnMf[KU8_ONE]) << KU8_POS_L_LOW_MIDDLE_BYTE) |
                                          (uint32)(u8RamAddressToPutOnMf[KU8_ZERO]));
      }
      else
      {
         /* No valid RAM address was requested, go to the next address */
      }
   }

   /* Fill frame with information aqquried (time slot based) */
   switch(u8TimeSlot)
   {
   case KU8_CIL_TIME_SLOT_0:

      /* function call measurement block 3 for timeslot 0 */
      cil_Update_07Cx_Block03_Timeslot0_InfosToSend((uint32*)&u32DataToDisplay[KU8_ZERO]);

      break;
   case KU8_CIL_TIME_SLOT_1:

      /* function call measurement block 3 for timeslot 1 */
      cil_Update_07Cx_Block03_Timeslot1_InfosToSend((uint32*)&u32DataToDisplay[KU8_THREE]);

      break;
   case KU8_CIL_TIME_SLOT_2:

      /* function call measurement block 3 for timeslot 2 */
      cil_Update_07Cx_Block03_Timeslot2_InfosToSend((uint32*)&u32DataToDisplay[KU8_SIX]);

      break;
   case KU8_CIL_TIME_SLOT_3:

      /* function call measurement block 3 for timeslot 3 */
      cil_Update_07Cx_Block03_Timeslot3_InfosToSend((uint32*)&u32DataToDisplay[KU8_NINE]);

      break;
   case KU8_CIL_TIME_SLOT_4:

      /* function call measurement block 3 for timeslot 4 */
      cil_Update_07Cx_Block03_Timeslot4_InfosToSend((uint32*)&u32DataToDisplay[KU8_TWELVE]);

      break;
   default:
      /* Function called with wrong argument */
      cil_Update_07Cx_IncorrectBlock_InfosToSend(KU8_CIL_MF_INVALID_BLOCK_ID);
      break;
   }
}

/**
* \brief
*        This function fill the CAN buffer with 0 in case incorrect measurement
*        frame block is requested.
* \dynamicaspectcaller
*        CIL_runManageMF
* \dynamicaspectdescription
*        Internally called by CIL component.
* \ddesignrequirement
*        DSG_cil_Update_07Cx_IncorrectBlock_InfosToSend
* \archrequirement
*        ARCH_SW_CIL_P_CAN_MF_Frame
**/
LOCAL_INLINE void cil_Update_07Cx_IncorrectBlock_InfosToSend(uint8 u8BlockIndex)
{
   uint8 u8Idx;

   for(u8Idx = 0u; u8Idx < KU8_SIXTYFOUR; u8Idx++)
   {
      *(uint8 *)((&cil_tMeasurementFrameContent[u8BlockIndex].u8Byte0) + u8Idx) = KU8_ZERO;
   }

   cil_tMeasurementFrameContentOnBus[u8BlockIndex].u64Byte_0_7   = *(uint64 *)(&cil_tMeasurementFrameContent[u8BlockIndex].u8Byte0);
   cil_tMeasurementFrameContentOnBus[u8BlockIndex].u64Byte_8_15  = *(uint64 *)(&cil_tMeasurementFrameContent[u8BlockIndex].u8Byte8);
   cil_tMeasurementFrameContentOnBus[u8BlockIndex].u64Byte_16_23 = *(uint64 *)(&cil_tMeasurementFrameContent[u8BlockIndex].u8Byte16);
   cil_tMeasurementFrameContentOnBus[u8BlockIndex].u64Byte_24_31 = *(uint64 *)(&cil_tMeasurementFrameContent[u8BlockIndex].u8Byte24);
   cil_tMeasurementFrameContentOnBus[u8BlockIndex].u64Byte_32_39 = *(uint64 *)(&cil_tMeasurementFrameContent[u8BlockIndex].u8Byte32);
   cil_tMeasurementFrameContentOnBus[u8BlockIndex].u64Byte_40_47 = *(uint64 *)(&cil_tMeasurementFrameContent[u8BlockIndex].u8Byte40);
   cil_tMeasurementFrameContentOnBus[u8BlockIndex].u64Byte_48_55 = *(uint64 *)(&cil_tMeasurementFrameContent[u8BlockIndex].u8Byte48);
   cil_tMeasurementFrameContentOnBus[u8BlockIndex].u64Byte_56_63 = *(uint64 *)(&cil_tMeasurementFrameContent[u8BlockIndex].u8Byte56);
}

/**
* \brief
*        This function will fill the CAN buffer for measurement frames.
*        Function shall check if there are measurement block activated in NVM.
* \dynamicaspectcaller
*        CIL_runManageMF
* \dynamicaspectdescription
*        Internally called by CIL component.
* \ddesignrequirement
*        DSG_cil_Update_07Cx_InfosToSend
* \archrequirement
*        ARCH_SW_CIL_P_CAN_MF_Frame
**/
LOCAL_INLINE boolean cil_Update_07Cx_InfosToSend(uint8 u8TimeSlot)
{
   uint32 u32CILMFSelectedBlocks;
   boolean bIsUpdated;

   u32CILMFSelectedBlocks = (uint32)(((uint32)(NVP_au8MeasFrameBlockConfig[KU8_CIL_INDEX_0_IN_SELECTED_BLOCKS_ARRAY]) << KU8_POS_L_HIGH_MIDDLE_BYTE) |
                                     ((uint32)(NVP_au8MeasFrameBlockConfig[KU8_CIL_INDEX_1_IN_SELECTED_BLOCKS_ARRAY]) << KU8_POS_L_LOW_MIDDLE_BYTE) |
                                     ((uint32)(NVP_au8MeasFrameBlockConfig[KU8_CIL_INDEX_2_IN_SELECTED_BLOCKS_ARRAY])));

   /* Check if there are activated blocks */
   if (KU32_ZERO != u32CILMFSelectedBlocks) /* cil_u32CILMFSelectedBlocks < max block ... 2 ... */
   {
      do
      {
         /* Update the block to send for next frame transmission */
         /* Set the next bit position to check if the associated block is activated */
         if (cil_u32MeasureNextBlockToSendMask >= U32_CIL_BLOCK_MASK(KU8_CIL_BLOCK_ID_03))
         {
            /* Previous tested bit was the last implemented block, go back to bit 0 (corresponding to block 01) */
            cil_u32MeasureNextBlockToSendMask = U32_CIL_BLOCK_MASK(KU8_CIL_BLOCK_ID_01);
            cil_u8MeasureNextBlockToSend = KU8_CIL_BLOCK_ID_01;
         }
         else
         {
            /* Increment the bit position to test (right to left bit search) */
            cil_u32MeasureNextBlockToSendMask = U32_CIL_NEXT_BLOCK(cil_u32MeasureNextBlockToSendMask);
            cil_u8MeasureNextBlockToSend++;
         }
      } while ((cil_u32MeasureNextBlockToSendMask & u32CILMFSelectedBlocks) == (uint32)KU8_ZERO);

      /* Check if block encoding function is implemented */
      if (KU8_CIL_MF_NB_OF_BLOCKS >= cil_u8MeasureNextBlockToSend)
      {
         /* Call function corresponding to requested block */
         /* Block index starts at index 1, function pointer starts at index 0 */
         (*(cil_kapfBlocksEncodFunc[cil_u8MeasureNextBlockToSend - KU8_ONE]))(u8TimeSlot);
         bIsUpdated = B_TRUE;
      }
      else
      {
         cil_Update_07Cx_IncorrectBlock_InfosToSend(KU8_ZERO);
         bIsUpdated = B_TRUE;
      }
   }
   else
   {
      /* Nothing to do : no block activated */
      bIsUpdated = B_FALSE;
   }

   return bIsUpdated;
}

#define CIL_STOP_SEC_CODE
#include "CIL_MemMap.h"

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

#define CIL_START_SEC_CODE
#include "CIL_MemMap.h"

/**
* \brief
*        This function is used to notify the reception of a GLIWA frame
* \dynamicaspectcaller
*        Called by BswMIf module
* \dynamicaspectdescription
*        Called in BswMIf module when ECU state is changed
* \ddesignrequirement
*        DSG_CIL_Rx_Gliwa_Ind
* \archrequirement
*        ARCH_SW_CIL_P_CAN_GliwaDataIn_Framez
**/
void CIL_Rx_Gliwa_Ind(void)
{
   Rte_COMCbk_GRGliwaInGroup_300R();
   cil_u8GliwaRxFlag = KU8_ONE;
}

/**
* \brief
*        This function is used to update the current
*        ECU state signal on MF_Logger frame.
* \inputparam
*        Name: u8CurrentEcuState;
*        Type: uint8;
*        Description: Current ECU state to set on signal;
*        Range: NA.;
* \dynamicaspectcaller
*        Called by BswMIf module
* \dynamicaspectdescription
*        Called in BswMIf module when ECU state is changed
* \ddesignrequirement
*        DSG_CIL_updateCurrentEcuState
* \archrequirement
*        ARCH_SW_CIL_pseSetEcuStateSignal;
*        ARCH_SW_CIL_P_CAN_MF_Logger_Frame;
**/
EXPORTED void CIL_updateCurrentEcuState(uint8 u8CurrentEcuState)
{
   if(cil_u8LastEcuState != u8CurrentEcuState)
   {
      if (KU8_ZERO != NVP_u8MeasFrameTiming)
      {
         /* Update frame signal */
         (void)Rte_Write_CIL_P_CAN_MF_Logger_Frame_MfLogger(u8CurrentEcuState);
      }
      cil_u8LastEcuState = u8CurrentEcuState;
   }
}

/**
* \brief
*        The CIL_runManageMF service transmits data periodically on the CAN bus
*        based on the NVP_u8MeasFrameTiming and NVP_au8MeasFrameBlockConfig
*        variables that are store in NvM.
* \constrains
*        NVP_u8MeasFrameTiming and NVP_au8MeasFrameBlockConfig is correctly configured.
* \dynamicaspectcaller
*        Scheduler.
* \dynamicaspectdescription
*        Called at 10 ms.
* \ddesignrequirement
*        DSG_CIL_runManageMF
* \archrequirement
*        ARCH_SW_CIL_P_CAN_MF_Frame;
*        ARCH_SW_CIL_P_CAN_GliwaDataIn_Frame;
**/
EXPORTED void CIL_runManageMF(void)
{
   boolean bInfoUpdated;
   uint8 au8MaskToCheck = NVP_au8MeasFrameBlockConfig[KU8_CIL_INDEX_2_IN_SELECTED_BLOCKS_ARRAY];

   if(cil_u8GliwaRxFlag == KU8_ONE)
   {
      if(B_TRUE == NVP_Gliwa_Enable)
      {
         (void)Rte_Read_P_CAN_GliwaDataIn_Frame_GliwaCanDataIn(&cil_tGliwaRxFrameContent);
         /* Call GLIWA notification */
         CIL_Gliwa_RxNotification(&cil_tGliwaRxFrameContent);
         cil_u8GliwaRxFlag = KU8_ZERO;
      }
   }
   if (KU8_ZERO != NVP_u8MeasFrameTiming)
   {
      /* Is it time for a new block ? */
      bInfoUpdated = cil_Update_07Cx_InfosToSend(cil_u8TimeSlotCnt);

      /* Prepare next time slot */
      cil_u8TimeSlotCnt++;

      if (cil_u8TimeSlotCnt >= KU8_CIL_TIME_SLOTS)
      {
         /* Reset time slot */
         cil_bTimeSlotExpired = KB_TRUE;
         cil_u8TimeSlotCnt = KU8_ZERO;
      }
      else
      {
         /* Intermediary time slot */
      }

      if (KU8_ZERO == cil_u8MFPeriodCounter)
      {
         /* Info was updated and at least 1 time slot full cycle was executed */
         if ((B_TRUE == bInfoUpdated) && (KB_TRUE == cil_bTimeSlotExpired))
         {
            if (cil_u8MeasureNextBlockToSend == cil_u8MeasureNextBlockSent)
            {
               /* This block was sent last cycle, check number of blocks activated */
               switch(cil_u8MeasureNextBlockToSend)
               {
               case KU8_CIL_BLOCK_ID_01:
                  /* Check if more than one block is activated */
                  if ((au8MaskToCheck != (uint8)CIL_BLOCK_MASK_12) && (au8MaskToCheck != (uint8)CIL_BLOCK_MASK_13))
                  {
                     cil_u8MeasureNextBlockToSend = KU8_CIL_BLOCK_ID_01;
                  }
                  else if (au8MaskToCheck == (uint8)CIL_BLOCK_MASK_12)
                  {
                     cil_u8MeasureNextBlockToSend = KU8_CIL_BLOCK_ID_02;
                  }
                  else
                  {
                     cil_u8MeasureNextBlockToSend = KU8_CIL_BLOCK_ID_03;
                  }

                  break;
               case KU8_CIL_BLOCK_ID_02:
                  /* Check if more than one block is activated */
                  if ((au8MaskToCheck != (uint8)CIL_BLOCK_MASK_12) && (au8MaskToCheck != (uint8)CIL_BLOCK_MASK_23))
                  {
                     cil_u8MeasureNextBlockToSend = KU8_CIL_BLOCK_ID_02;
                  }
                  else if (au8MaskToCheck == (uint8)CIL_BLOCK_MASK_12)
                  {
                     cil_u8MeasureNextBlockToSend = KU8_CIL_BLOCK_ID_01;
                  }
                  else
                  {
                     cil_u8MeasureNextBlockToSend = KU8_CIL_BLOCK_ID_03;
                  }

                  break;
               case KU8_CIL_BLOCK_ID_03:
                  /* Check if more than one block is activated */
                  if ((au8MaskToCheck != (uint8)CIL_BLOCK_MASK_13) && (au8MaskToCheck != (uint8)CIL_BLOCK_MASK_23))
                  {
                     cil_u8MeasureNextBlockToSend = KU8_CIL_BLOCK_ID_03;
                  }
                  else if (au8MaskToCheck == (uint8)CIL_BLOCK_MASK_13)
                  {
                     cil_u8MeasureNextBlockToSend = KU8_CIL_BLOCK_ID_01;
                  }
                  else
                  {
                     cil_u8MeasureNextBlockToSend = KU8_CIL_BLOCK_ID_02;
                  }

                  break;
               default:
                  /* This should not be possible */
                  break;
               }
            }
            else
            {
               /* Nothing to do */
            }

            /* Write data to sent */
            (void)Rte_Write_P_CAN_MF_Frame_stMFData(&cil_tMeasurementFrameContentOnBus[cil_u8MeasureNextBlockToSend - KU8_ONE]);
            /* Remember block sent */
            cil_u8MeasureNextBlockSent = cil_u8MeasureNextBlockToSend;
            /* Reset time slot mechanism */
            cil_u8TimeSlotCnt = KU8_ZERO;
            cil_bTimeSlotExpired = KB_FALSE;
         }
         else
         {
            if (B_TRUE != bInfoUpdated)
            {
               /* Suspend measurement frame sending since there are no blocks activated */
               cil_u8TimeSlotCnt = KU8_ZERO;
               cil_bTimeSlotExpired = KB_FALSE;
            }
            else
            {
               /* No operation; wait for the time slot mechanism */
            }
         }

         /* Reload period counter */
         if (NVP_u8MeasFrameTiming > KU8_FIFTY)
         {
            NVP_u8MeasFrameTiming = KU8_FIFTY;
         }

         cil_u8MFPeriodCounter = NVP_u8MeasFrameTiming * KU8_CIL_TIME_SLOTS;
      }
      else
      {
         /* Nothing to do */
      }

      cil_u8MFPeriodCounter--;
   }
   else
   {
      /* MF Disabled */
      cil_u8TimeSlotCnt = KU8_ZERO;
      cil_bTimeSlotExpired = KB_FALSE;
   }
}

/**
* \brief
*        The runnable shall transmit the data received on the CAN bus to the rest
*        of the T1 Gliwa library
* \inputparam
*        Name: data;
*        Type: REC_GliwaDataIn_Type *;
*        Description: Content of frame received on the CAN bus;
* \constrains
*        NVP_Gliwa_Enable must be enabled in the Calibration block
* \dynamicaspectcaller
*        CIL_runManageMF
* \dynamicaspectdescription
*        Called internally in CIL
* \ddesignrequirement
*        DSG_CIL_Gliwa_RxNotification
* \archrequirement
*        ARCH_SW_CIL_P_CAN_GliwaDataIn_Frame
**/
EXPORTED void CIL_Gliwa_RxNotification(REC_GliwaDataIn_Type *data)
{
   (void)T1_AppReceiveFrame((T1_uint8_t const *)data,8u);
}

/**
* \brief
*       The runnable shall transmit the data received from the T1 Gliwa library
*       on the CAN bus
* \inputparam
*       Name: data;
*       Type: CIL_stFrameDataBytes *;
*       Description: Content received from the T1 Gliwa library;
* \outputparam
*       None;
* \constrains
*       NVP_Gliwa_Enable must be enabled in the Calibration block
* \dynamicaspectcaller
*       T1_TransmitFrame
* \dynamicaspectdescription
*       Called by the T1 Gliwa library
* \ddesignrequirement
*       DSG_CIL_Gliwa_TXNotification
* \archrequirement
*       ARCH_SW_CIL_P_CAN_GliwaDataOut_Frame
**/
EXPORTED void CIL_Gliwa_TXNotification(CIL_stFrameDataBytes *data)
{
   cil_u8EcuCanDataOut_Gliwa_Tx_OnBus.u64Byte_0_7     = *(uint64 *)(&data->u8Byte0);
   cil_u8EcuCanDataOut_Gliwa_Tx_OnBus.u64Byte_8_15    = *(uint64 *)(&data->u8Byte8);
   cil_u8EcuCanDataOut_Gliwa_Tx_OnBus.u64Byte_16_23   = *(uint64 *)(&data->u8Byte16);
   cil_u8EcuCanDataOut_Gliwa_Tx_OnBus.u64Byte_24_31   = *(uint64 *)(&data->u8Byte24);
   cil_u8EcuCanDataOut_Gliwa_Tx_OnBus.u64Byte_32_39   = *(uint64 *)(&data->u8Byte32);
   cil_u8EcuCanDataOut_Gliwa_Tx_OnBus.u64Byte_40_47   = *(uint64 *)(&data->u8Byte40);
   cil_u8EcuCanDataOut_Gliwa_Tx_OnBus.u64Byte_48_55   = *(uint64 *)(&data->u8Byte48);
   cil_u8EcuCanDataOut_Gliwa_Tx_OnBus.u64Byte_56_63   = *(uint64 *)(&data->u8Byte56);

   /* Sent information to CAN */
   (void)Rte_Write_P_CAN_GliwaDataOut_Frame_GliwaCanDataOut(&cil_u8EcuCanDataOut_Gliwa_Tx_OnBus);
}

#define CIL_STOP_SEC_CODE
#include "CIL_MemMap.h"

/******************************************************************************
Evolution of the component

Created by : F.GILBERT

$Log: CIL_ManageMFTransmission_Old.c  $
Revision 1.2.3.7 2023/07/18 08:40:54CEST David Puscasu (david.puscasu) 
Run QAC after Update Traceability on CIL
Revision 1.3.3.50 2023/07/18 09:29:41EEST David Puscasu (david.puscasu) 
Update Traceability on CIL
Revision 1.3.3.49 2023/06/15 13:58:27EEST David Puscasu (david.puscasu) 
Add ACC_bAccelAxisBrokenFlag and ACC_bAlarmbPreinitSeqFlag on MFT
Revision 1.3.3.48 2023/06/12 09:05:53EEST Mihai Motoc (mihai.motoc) 
Doxygen comments updates
Revision 1.3.3.47 2023/06/08 13:34:18EEST Mihai Motoc (mihai.motoc) 
Doxygen comments updates
Revision 1.3.3.46 2023/05/31 15:58:16EEST Dan Dustinta (dan.dustinta) 
update traceability
Revision 1.3.3.45 2023/05/16 15:01:22EEST Dan Dustinta (dan.dustinta) 
update findings after PRWB
Revision 1.3.3.44 2023/05/15 16:20:26EEST Ioan Repede (ioan.repede) 
Update RTE connection for SolenoidStuckStatus prot from FSM.
Revision 1.3.3.43 2023/05/10 14:10:37EEST Mihai Motoc (mihai.motoc) 
Code Fixes for QAC
Revision 1.3.3.42 2023/04/28 10:28:48EEST Dan Dustinta (dan.dustinta) 
add stub implementation for sol overvoltage/ power stage auto-tests
Revision 1.3.3.41 2023/04/25 11:13:42EEST Lucian Ardeleanu (lucian.ardeleanu) 
[SRC] Current measurement bugfix
Revision 1.3.3.40 2023/04/20 17:26:47EEST Gabriel Brasoveanu (gabriel.brasoveanu) 
Handle new signals imported from K-matrix
Revision 1.3.3.39 2023/04/20 13:59:44EEST Dan Dustinta (dan.dustinta) 
update traceability and comments
Revision 1.3.3.38 2023/04/19 15:12:44EEST Dan Dustinta (dan.dustinta) 
add define for CIL nb of backups
Revision 1.3.3.37 2023/04/19 09:23:22EEST Dan Dustinta (dan.dustinta) 
split into local functions
Revision 1.3.3.36 2023/04/18 16:59:51EEST Dan Dustinta (dan.dustinta) 
update comments in CIL
Revision 1.3.3.35 2023/04/18 15:24:57EEST Dan Dustinta (dan.dustinta) 
add local functions
Revision 1.3.3.34 2023/04/03 11:11:05EEST Gabriel Brasoveanu (gabriel.brasoveanu) 
Update block 3 implementation
Revision 1.3.3.33 2023/03/24 08:46:25EET Septimiu Vintila (septimiu.vintila) 
Changes after review.
Revision 1.3.3.32 2023/03/15 15:15:43EET Septimiu Vintila (septimiu.vintila) 
QAC related code changes.
Revision 1.3.3.31 2023/03/14 11:39:45EET Gabriel Brasoveanu (gabriel.brasoveanu) 
Measurement frame, Gliwa Out frame and DevKit frame changed from 64 signals of 1 byte to 8 signals of 8 bytes
Revision 1.3.3.28 2023/03/10 11:25:32EET Septimiu Vintila (septimiu.vintila) 
MF redesign; cast corrected in CanToAppli
Revision 1.3.3.27 2023/03/08 12:16:53EET Septimiu Vintila (septimiu.vintila) 
High limit formula fixed.
Revision 1.3.3.26 2023/03/07 14:28:10EET Septimiu Vintila (septimiu.vintila) 
Rework on sync mechanism; solenoid error reporting fixed.
Revision 1.3.3.25 2023/03/07 12:14:38EET Septimiu Vintila (septimiu.vintila) 
Syncronization mechanism (time-slot mechanism with transmision mechanism) fixed.
Revision 1.3.3.24 2023/03/06 15:03:25EET Septimiu Vintila (septimiu.vintila) 
Cast to uint8 changed to cast to uint16 to avoid data lost.
Revision 1.3.3.23 2023/03/06 10:47:33EET Septimiu Vintila (septimiu.vintila) 
Changes due to QAC warnings.
Revision 1.3.3.22 2023/03/03 12:35:24EET Dan Dustinta (dan.dustinta) 
update MF handling
Revision 1.3.3.21 2023/03/02 18:19:00EET Dan Dustinta (dan.dustinta) 
remove duplicate for loops
Revision 1.3.3.20 2023/03/02 15:23:05EET David Puscasu (david.puscasu) 
Add QAC preporcessor
Revision 1.3.3.19 2023/03/02 14:45:29EET David Puscasu (david.puscasu) 
Add ACC and SBC Alarm registers data on Measurement Frames
Revision 1.3.3.18 2023/03/02 13:33:38EET Lucian Ardeleanu (lucian.ardeleanu) 
[eCS][SRC] Add in CIL capability to detect which solenoid is faulty
Revision 1.3.3.17 2023/03/01 13:54:35EET Dan Dustinta (dan.dustinta) 
fix memory section
Revision 1.3.3.16 2023/02/15 10:07:34EET Septimiu Vintila (septimiu.vintila) 
QAC related code changes.
Revision 1.3.3.15 2023/01/30 09:31:47EET Dan Dustinta (dan.dustinta) 
add CIL callback
Revision 1.3.3.14 2023/01/16 15:00:23EET Septimiu Vintila (septimiu.vintila) 
Maximum number of solenoids macro replaced.
Revision 1.3.3.13 2023/01/16 14:12:34EET Septimiu Vintila (septimiu.vintila) 
Double protection removed.
Revision 1.3.3.12 2023/01/16 13:35:05EET Septimiu Vintila (septimiu.vintila) 
Variables name changed.
Revision 1.3.3.11 2023/01/16 11:38:46EET Septimiu Vintila (septimiu.vintila) 
Fixes after review.
Revision 1.3.3.10 2023/01/13 12:10:26EET Dan Dustinta (dan.dustinta) 
enable all solenoid measurements
Revision 1.3.3.8 2023/01/13 09:06:47EET Dan Dustinta (dan.dustinta) 
revet Gliwa frame NVP var
Revision 1.3.3.7 2023/01/12 16:44:20EET Dan Dustinta (dan.dustinta) 
add event on MF
Revision 1.3.3.5 2023/01/09 10:13:17EET Septimiu Vintila (septimiu.vintila) 
Gliwa TX Frame protected with NVP variable.
Revision 1.3.3.4 2022/12/14 11:35:54EET Septimiu Vintila (septimiu.vintila) 
Integration for Gliwa related Tx/Rx frames.
Revision 1.3.3.3 2022/11/24 10:13:15EET Septimiu Vintila (septimiu.vintila) 
CIL implemantation.
Revision 1.6 2022/03/22 14:37:47EET Pierre-Olivier Pilot (pierre-olivier.pilot)
eCS_ECUV.007:
* SPIIF: update Accel init sequence: remove filter configuration (we select bank 6 but we configure register from bank 0 => drift issue). Only the full scale register is written
   * Implements a test function to get accelerometer temperautre. Output in MF block 4
* Remove 2g variant configuration. Force accelerometer to use 4g
* Fix SAD following cycle management. A bug was found when going grom lock to unlock, the holding profile was run for 1ms then the unlocking one was triggered.
* DIA RC: update calibration
Revision 1.5 2022/03/09 14:27:32CET Pierre-Olivier Pilot (pierre-olivier.pilot)
eCS_ECUV.005:
 Fix DIO index for Boost
 Add Enable for boost 2

eCS_ECUV.004:
 Fix ADCIF "getMeasure" value for KL30
 Fix Az offset value for +/-16g calibration
Revision 1.4 2021/12/23 14:30:18CET Pierre-Olivier Pilot (pierre-olivier.pilot)
DID FDE7
Revision 1.3 2021/12/23 09:25:35CET Pierre-Olivier Pilot (pierre-olivier.pilot)
Add IIR filter for solenoids current, RID to lock/unlock solenoid and some fixes
Revision 1.2 2021/10/27 08:52:23CEST Pierre-Olivier Pilot (pierre-olivier.pilot)
Intermediate release.
- Update MCU Pinout
- Configure ADC
- Add LuT for NTC temperature
- Add Measurement frame. (Id to be changed)
- Add current regulation in SAD (PI controller)
- Add solenoid discrete model in targetlink
Revision 1.1 2021/08/26 08:16:54CEST Pierre-Olivier Pilot (pierre-olivier.pilot)
Initial revision

*****************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/
