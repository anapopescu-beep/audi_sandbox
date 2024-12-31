
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
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.16 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/ACC/Quality_Assurance/Static_Analysis/project.pj $
*/
/*!****************************************************************************

details
   High level module for controlling the Accelerometer chip. In charge of:
      o   Initialization
      o   Get temperature data
      o   Get 3 axis of accelerometer data

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "ACC_cfg.h"
#include "ACC.h"
#include "SpiIf.h"
#include "Nvp_Generated_Nvmdefault.h"
#include "Rte_ACC.h"
#include "NXP\S32K144.h"
#include "Dio.h"
#include "DioIf.h"
#include "Gpt.h"
#include "Rte_Intern.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *       SPI to eCS (g to m/s²) shift power.
 */
#define KU8_ACC_SHIFT_POWER ((uint8)0x0D)
/**
 * \brief
 *       Return Status Mask for first byte of Spi response from Accelerometer.
 */
#define KU8_ACC_SPI_RESPONSE_RS_MASK ((uint8)0x03)
/**
 * \brief
 *       A flag used to set read register command -> first bit of Spi command to Accelerometer.
 */
#define KU8_ACC_READ_REGISTER_FLAG ((uint8)0x00)
/**
 * \brief
 *       A flag used to set write register command -> first bit of Spi command to Accelerometer.
 */
#define KU8_ACC_WRITE_REGISTER_FLAG ((uint8)0x01)
/**
 * \brief
 *       A define used at the convertion from raw accelerometer values to g-values.
 */
#define S32_ACC_CONVERSION_MULTIPLAYER ((sint32)5142)
/**
 * \brief
 *       A define used at the convertion from raw accelerometer values to g-values.
 */
#define U16_ACC_ANGLE_OFFSET_ARRAY_LENGTH ((uint16)361)

/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_CHECK_ALARMB_SEQ ((uint8)0)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_IDLE ((uint8)1)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_READ_GYRO_X_AXIS_FILTER_SETTINGS ((uint8)2)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_READ_GYRO_Y_Z_AXIS_FILTER_SETTINGS ((uint8)3)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_WRITE_GYRO_X_AXIS_FILTER_SETTINGS ((uint8)4)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_WRITE_GYRO_Y_Z_AXIS_FILTER_SETTINGS ((uint8)5)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_UNLOCK_SETTINGS ((uint8)6)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_BANK_SWITCH_6 ((uint8)7)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_READ_SENSITIVITY_CONFIG ((uint8)8)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_READ_DUMMY_SENSITIVITY_CONFIG ((uint8)9)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_WRITE_SENSITIVITY_CONFIG ((uint8)10)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_BANK_SWITCH_1 ((uint8)11)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_READ_S_M_ENABLE0 ((uint8)12)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_READ_S_M_ENABLE1 ((uint8)13)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_WRITE_S_M_ENABLE0 ((uint8)14)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_WRITE_S_M_ENABLE1 ((uint8)15)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_READ_S_M_MASK0 ((uint8)16)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_READ_S_M_MASK1 ((uint8)17)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_READ_S_M_MASK3 ((uint8)18)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_WRITE_S_M_MASK0 ((uint8)19)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_WRITE_S_M_MASK1 ((uint8)20)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_WRITE_S_M_MASK3 ((uint8)21)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_BANK_SWITCH_0 ((uint8)22)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_READ_MODE_REGISTER ((uint8)23)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_READ_DUMMY_MODE_REGISTER ((uint8)24)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_WRITE_MODE_REGISTER ((uint8)25)
/**
 * \brief
 *       Define used for staging ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_INIT_WAIT_READY ((uint8)26)
/**
 * \brief
 *       Define used for waiting the initialization time of TDK accelerometer chip,
 *       and after that, start the execution of the ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_WAIT_ACC_INITIALIZATION_TIMER ((uint8)201)
/**
 * \brief
 *       Define used for waiting the initialization time of TDK accelerometer chip,
 *       and after that, start the execution of the ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_TIMEOUT_PREINIT_CHECK_ALARMB_SEQ ((uint8)100)
/**
 * \brief
 *       Define used for waiting the initialization time of TDK accelerometer chip,
 *       and after that, start the execution of the ACC_ReadAccelerometerData function.
 */
#define KU8_ACC_WAIT_ACC_SENS_SWITCH_TIMER ((uint8)10)

/**
 * \brief
 *       Define used for staging ACC_ReadAlarmRegisters function.
 */
#define KU8_ACC_READ_ACCEL_ALARM_0_REG ((uint8)0)
/**
 * \brief
 *       Define used for staging ACC_ReadAlarmRegisters function.
 */
#define KU8_ACC_READ_ACCEL_ALARM_1_REG ((uint8)1)
/**
 * \brief
 *       Define used for staging ACC_ReadAlarmRegisters function.
 */
#define KU8_ACC_READ_OTHER_ALARM_0_REG ((uint8)2)
/**
 * \brief
 *       Define used for staging ACC_ReadAlarmRegisters function.
 */
#define KU8_ACC_READ_OTHER_ALARM_1_REG ((uint8)3)
/**
 * \brief
 *       Define used for staging ACC_ReadAlarmRegisters function.
 */
#define KU8_ACC_EXTRACT_USEFUL_DATA_FROM_ALARM_REGISTERS ((uint8)4)
/**
 * \brief
 *       The Id of ALARMB pin of Accelerometer in the kau8DioMapping array.
 */
#define KU8_ACC_DIO_ALARMB_PIN_ID ((uint8)8)
/**
 * \brief
 *       The value of two bits of Return Status from Spi response that indicate an error.
 */
#define KU8_ACC_RETURN_STATUS_ERROR ((uint8)0x03)

/**
 *\brief
 *       Macro used to define the port interrupt enable on rising edge.
 */
#define KU8_ACC_PORTE_INTERRUPT_RISING_EDGE ((uint8)0x09)
/**
 *\brief
 *       Macro used to define the port interrupt enable on falling edge.
 */
#define KU8_ACC_PORTE_INTERRUPT_FALLING_EDGE ((uint8)0x0A)
/**
 *\brief
 *       Macro used to define the port interrupt disable.
 */
#define KU8_ACC_PORTE_INTERRUPT_DISABLE ((uint8)0x00)
/**
 *\brief
 *       Define used for staging execution of PORTE_ISR.
 */
#define KU8_ACC_ALARMB_SEQ_BEGIN_SM ((uint8)0)
/**
 *\brief
 *       Define used for staging execution of PORTE_ISR.
 */
#define KU8_ACC_ALARMB_SEQ_STEP1_SM ((uint8)1)
/**
 *\brief
 *       Define used for staging execution of PORTE_ISR.
 */
#define KU8_ACC_ALARMB_SEQ_STEP2_SM ((uint8)2)

/**
 *\brief
 *       The minimal time in microsecounds x10 between t=0
 *       and first falling edge of ALARMB pin. 
 *       A small error margin of 0.1 ms has been added.
 *       Final value = 10.3 - 0.1 = 10.2ms
 */
#define KU32_ACC_ALARMB_FALLING_EDGE_MIN_TIME ((uint32)102000)
/**
 *\brief
 *       The mximum time in microsecounds x10 between t=0
 *       and first falling edge of ALARMB pin.
 *       A small error margin of 0.1 ms has been added.
 *       Final value = 11.3 + 0.1 = 11.4ms
 */
#define KU32_ACC_ALARMB_FALLING_EDGE_MAX_TIME ((uint32)114000)
/**
 *\brief
 *       The minimal time in microsecounds x10 between t=0
 *       and first rising edge of ALARMB pin.
 *       A small error margin of 0.1 ms has been added.
 *       Final value = 75.6 - 0.1 = 75.5ms
 */
#define KU32_ACC_ALARMB_RISING_EDGE_MIN_TIME ((uint32)755000)
/**
 *\brief
 *       The mximum time in microsecounds x10 between t=0
 *       and first rising edge of ALARMB pin.
 *       A small error margin of 0.1 ms has been added.
 *       Final value = 83.2 + 0.1 = 83.3ms
 */
#define KU32_ACC_ALARMB_RISING_EDGE_MAX_TIME ((uint32)833000)
/**
 *\brief
 *     Macro used to define the port mux value - sets the mux register
 */
#define KU16_ACC_PORT_MUX_500 ((uint16)0x500u)
/**
 *\brief
 *     Macro used to define the port mux value - sets the mux register
 */
#define KU16_ACC_PORT_MUX_400 ((uint16)0x400u)
/**
 *\brief
 *     Macro used to define the port mux value - sets the mux register
 */
#define KU16_ACC_PORT_MUX_300 ((uint16)0x300u)

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
LOCAL uint8 acc_ComputeCRC(const uint8 *kpu8Buffer);
LOCAL void acc_SendCommandToReadOrWriteRegister(const uint8 ku8ReadOrWriteFlag,
                                                const uint8 ku8RegisterAddress,
                                                const uint16 *kpu16RegisterDataCommand,
                                                const SpiIf_stSpiChannelSequenceType *kpstAccelerometerChannelSequence);
LOCAL void acc_GetRegDataResponseFromSpiIB(uint16 *pu16RegisterDataRead, const Spi_ChannelType *kpu8AccelerometerChannel);
LOCAL void acc_ReadAlarmRegisters(void);
LOCAL void acc_Init(void);
LOCAL void acc_ReadData(void);

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

#define ACC_START_SEC_VAR_INIT_16
#include "ACC_MemMap.h"

/**
 * \brief
 *      The response from Accelerometer with Temperature Register data.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU16_MAX.
 */
LOCAL uint16 acc_u16TemperatureDataRegDataReceive = KU16_ZERO;

#define ACC_STOP_SEC_VAR_INIT_16
#include "ACC_MemMap.h"

#define ACC_START_SEC_VAR_INIT_BOOL_ASIL_A
#include "ACC_MemMap.h"

/**
 * \brief
 *      A flag used to signal that each step in the ALARMB pin preinit sequence check routine has been run.
 *      (This flag only tells us that this routine has been run, not the result of the run.)
 * \initialization
 *      False.
 * \range
 *      0..1.
 */
LOCAL boolean acc_bPreinitSeqAlarmbWasChecked = KB_FALSE;

#define ACC_STOP_SEC_VAR_INIT_BOOL_ASIL_A
#include "ACC_MemMap.h"

#define ACC_START_SEC_VAR_INIT_8_ASIL_A
#include "ACC_MemMap.h"

/**
 * \brief
 *      Variable used in state machine of the function ACC_runMainFunction.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU8_MAX.
 */
LOCAL uint8 acc_u8AccInitSM = KU8_ZERO;
/**
 * \brief
 *      Counter used to wait the initialization of TDK accelerometer before beginning the init sequence.
 * \initialization
 *      ZERO.
 * \range
 *      0..200.
 */
LOCAL uint8 acc_u8AccInitCnt = KU8_ZERO;
/**
 * \brief
 *      Variable used in state machine of the function ACC_ReadAlarmRegisters.
 * \initialization
 *      ZERO.
 * \range
 *      0..4.
 */
LOCAL uint8 acc_u8AccReadAlarmsSM = KU8_ZERO;
/**
 * \brief
 *      Variable used in state machine of the function ACC_ReadAlarmRegisters.
 * \initialization
 *      ZERO.
 * \range
 *      0..2.
 */
LOCAL uint8 acc_u8AlarmbIsrCallCounter = KU8_ZERO;
/**
 * \brief
 *      Variable used to counter the time of 10 ms between two reads of alarm registers.
 * \initialization
 *      ZERO.
 * \range
 *      0..10.
 */
LOCAL uint8 acc_u8ReadAlarmRegistersPeriodCounter = KU8_ZERO;
/**
 * \brief
 *      Variable used to counter the number of X-axis consecutive sane values of accelerometer.
 * \initialization
 *      ZERO.
 * \range
 *      0..30.
 */
LOCAL uint8 acc_u8ConsecutiveXaxisIdenticalValuesCounter = KU8_ZERO;
/**
 * \brief
 *      Variable used to counter the number of Y-axis consecutive sane values of accelerometer.
 * \initialization
 *      ZERO.
 * \range
 *      0..30.
 */
LOCAL uint8 acc_u8ConsecutiveYaxisIdenticalValuesCounter = KU8_ZERO;
/**
 * \brief
 *      Variable used to counter the number of Z-axis consecutive sane values of accelerometer.
 * \initialization
 *      ZERO.
 * \range
 *      0..30.
 */
LOCAL uint8 acc_u8ConsecutiveZaxisIdenticalValuesCounter = KU8_ZERO;

#define ACC_STOP_SEC_VAR_INIT_8_ASIL_A
#include "ACC_MemMap.h"

#define ACC_START_SEC_VAR_INIT_16_ASIL_A
#include "ACC_MemMap.h"

/**
 * \brief
 *      Current reading data of accelerometer X-axis.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU16_MAX.
 */
LOCAL uint16 acc_u16AccelXaxisCurrentReadData = KU16_ZERO;
/**
 * \brief
 *      Current reading data of accelerometer Y-axis.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU16_MAX.
 */
LOCAL uint16 acc_u16AccelYaxisCurrentReadData = KU16_ZERO;
/**
 * \brief
 *      Current reading data of accelerometer Z-axis.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU16_MAX.
 */
LOCAL uint16 acc_u16AccelZaxisCurrentReadData = KU16_ZERO;
/**
 * \brief
 *      Last reading data of accelerometer X-axis.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU16_MAX.
 */
LOCAL uint16 acc_u16AccelXaxisPreviousReadData = KU16_ZERO;
/**
 * \brief
 *      Last reading data of accelerometer Y-axis.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU16_MAX.
 */
LOCAL uint16 acc_u16AccelYaxisPreviousReadData = KU16_ZERO;
/**
 * \brief
 *      Last reading data of accelerometer Z-axis.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU16_MAX.
 */
LOCAL uint16 acc_u16AccelZaxisPreviousReadData = KU16_ZERO;
/**
 * \brief
 *      The Register Data to transmit to Accelerometer.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU16_MAX.
 */
LOCAL uint16 acc_u16RegisterDataTransmit = KU16_ZERO;
/**
 * \brief
 *      The response from Accelerometer with X Axis Filter Register data.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU16_MAX.
 */
LOCAL uint16 acc_u16XAxisFilterRegDataReceive = KU16_ZERO;
/**
 * \brief
 *      The response from Accelerometer with Y and Z Axis Filter Register data.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU16_MAX.
 */
LOCAL uint16 acc_u16YZAxisFilterRegDataReceive = KU16_ZERO;
/**
 * \brief
 *      The response from Accelerometer with Sensivity Configuration Register data.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU16_MAX.
 */
LOCAL uint16 acc_u16SensivityConfigRegDataReceive = KU16_ZERO;
/**
 * \brief
 *      The response from Accelerometer with Receive Mode Register data.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU16_MAX.
 */
LOCAL uint16 acc_u16ModeRegDataReceive = KU16_ZERO;
/**
 * \brief
 *      The response from Accelerometer with Receive Safety Mechanisms Enable 1 Register data.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU16_MAX.
 */
LOCAL uint16 acc_u16SmEnable_0_DataReceive = KU16_ZERO;
/**
 * \brief
 *      The response from Accelerometer with Receive Safety Mechanisms Enable 2 Register data.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU16_MAX.
 */
LOCAL uint16 acc_u16SmEnable_1_DataReceive = KU16_ZERO;
/**
 * \brief
 *      The response from Accelerometer with Receive Safety Mechanisms Mask 0 Register data.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU16_MAX.
 */
LOCAL uint16 acc_u16SmMask_0_DataReceive = KU16_ZERO;
/**
 * \brief
 *      The response from Accelerometer with Receive Safety Mechanisms Mask 1 Register data.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU16_MAX.
 */
LOCAL uint16 acc_u16SmMask_1_DataReceive = KU16_ZERO;
/**
 * \brief
 *      The response from Accelerometer with Receive Safety Mechanisms Mask 3 Register data.
 * \initialization
 *      ZERO.
 * \range
 *      0..KU16_MAX.
 */
LOCAL uint16 acc_u16SmMask_3_DataReceive = KU16_ZERO;

/**
 * \brief
 *      The response from Accelerometer with Accelerometer Alarm Register data.
 * \initialization
 *      ZERO.
 * \range
 *      NA.
 */
/* -------------------------------------------------------- */
/*  Data from ACCELEROMETER ALARM REGISTER 0 - address 0x12 */
/* -------------------------------------------------------- */
/*  Bit | SM number | Alarm Name                            */
/* -------------------------------------------------------- */
/*   13 |      SM17 | vrefshieldz_alarm                     */
/*   12 |      SM17 | vrefshieldxy_alarm                    */
/*    1 |      SM18 | accel_cp_alarm                        */
/*    0 |      SM14 | accel_vref_alarm                      */
/* -------------------------------------------------------- */
LOCAL uint16 acc_u16AccelAlarm_0_DataReceive = KU16_ZERO;

/**
 * \brief
 *      The response from Accelerometer with Accelerometer Alarm Register data.
 * \initialization
 *      ZERO.
 * \range
 *      NA.
 */
/* -------------------------------------------------------- */
/*  Data from ACCELEROMETER ALARM REGISTER 1 - address 0x13 */
/* -------------------------------------------------------- */
/*  Bit | SM number | Alarm Name                            */
/* -------------------------------------------------------- */
/*    2 |      SM16 | accel_x_dcst_alarm                    */
/*    1 |      SM16 | accel_y_dcst_alarm                    */
/*    0 |      SM16 | accel_z_dcst_alarm                    */
/* -------------------------------------------------------- */
LOCAL uint16 acc_u16AccelAlarm_1_DataReceive = KU16_ZERO;

/**
 * \brief
 *      The response from Accelerometer with Other Alarms 0 Register data.
 * \initialization
 *      ZERO.
 * \range
 *      NA.
 */
/* -------------------------------------------------- */
/*  Data from OTHER ALARMS REGISTER 0 - address 0x14  */
/* -------------------------------------------------- */
/*  Bit | SM number | Alarm Name                      */
/* -------------------------------------------------- */
/*   13 |      SM26 | otp_crc_alarm                   */
/*   12 |      SM26 | otp_reg_alarm                   */
/*   11 |      SM34 | bg_alarm                        */
/*   10 |      SM14 | cp_vref_alarm                   */
/*    9 |      SM14 | temp_vref_alarm                 */
/*    8 |      SM13 | vdd_alarm                       */
/*    7 |      SM13 | vddio_alarm                     */
/*    6 |      SM12 | dvddreg_alarm                   */
/*    5 |      SM11 | avddreg_alarm                   */
/*    4 |      SM10 | vddmaster_alarm                 */
/*    3 |      SM08 | temp12_alarm                    */
/*    2 |      SM08 | temp_dsp_alarm                  */
/*    1 |      SM03 | rcosc2_freqmeas_alarm           */
/*    0 |      SM03 | rcosc1_freqmeas_alarm           */
/* -------------------------------------------------- */
LOCAL uint16 acc_u16OtherAlarms_0_DataReceive = KU16_ZERO;

/**
 * \brief
 *      The response from Accelerometer with Other Alarms 1 Register data.
 * \initialization
 *      ZERO.
 * \range
 *      NA.
 */
/* -------------------------------------------------- */
/*  Data from OTHER ALARMS REGISTER 1 - address 0x15  */
/* -------------------------------------------------- */
/*  Bit | SM number | Alarm Name                      */
/* -------------------------------------------------- */
/*   13 |      SM03 | sys_clk_alarm                   */
/*   12 |      SM26 | otp_cpy_alarm                   */
/*    9 |      SM22 | reg_eccdone_warn                */
/*    8 |      SM22 | reg_eccerr_alarm                */
/*    7 |      SM22 | ahb_eccdone_warn                */
/*    6 |      SM22 | ahb_eccerr_alarm                */
/*    5 |      SM33 | regcheck_alarm                  */
/*    4 |      SM30 | spi_clkcnt_alarm                */
/*    3 |      SM30 | spi_cmddecod_alarm              */
/*    2 |      SM30 | spi_crc_alarm                   */
/*    1 |      SM29 | ahb_bus_alarm                   */
/* -------------------------------------------------- */
LOCAL uint16 acc_u16OtherAlarms_1_DataReceive = KU16_ZERO;

#define ACC_STOP_SEC_VAR_INIT_16_ASIL_A
#include "ACC_MemMap.h"
/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
#define ACC_START_SEC_VAR_INIT_32_ASIL_A
#include "ACC_MemMap.h"

/**
 * \brief
 *      A variable with all useful bits from alarm registers, which is transmitted on the measurement frame.
 * \initialization
 *      ZERO.
 * \range
 *      NA.
 */
/* +-----------------------------------------------------------------------------------+ */
/* |  The maping method of bits from alarm registers                                   | */
/* +------+------+-----------+-----------------------+---------+-----------------------+ */
/* | Byte |  Bit | SM number | Alarm Name            | REG Bit | Alarm Register Name   | */
/* +------+------+-----------+-----------------------+---------+-----------------------+ */
/* |      |  31  |    SM17   | vrefshieldz_alarm     |    13   |                       | */
/* |      |  30  |    SM17   | vrefshieldxy_alarm    |    12   |                       | */
/* |      |  29  |    SM18   | accel_cp_alarm        |     1   | ACCELEROMETER ALARM 0 | */
/* |   1  |  28  |    SM14   | accel_vref_alarm      |     0   |                       | */
/* |      +------+-----------+-----------------------+---------+-----------------------+ */
/* |      |  27  |    SM16   | accel_x_dcst_alarm    |     2   |                       | */
/* |      |  26  |    SM16   | accel_y_dcst_alarm    |     1   | ACCELEROMETER ALARM 1 | */
/* |      |  25  |    SM16   | accel_z_dcst_alarm    |     0   |                       | */
/* |      +------+-----------+-----------------------+---------+-----------------------+ */
/* |______|  24  |    SM26   | otp_crc_alarm         |    13   |                       | */
/* |      |  23  |    SM26   | otp_reg_alarm         |    12   |                       | */
/* |      |  22  |    SM34   | bg_alarm              |    11   |                       | */
/* |      |  21  |    SM14   | cp_vref_alarm         |    10   |                       | */
/* |   2  |  20  |    SM14   | temp_vref_alarm       |     9   |                       | */
/* |      |  19  |    SM13   | vdd_alarm             |     8   |                       | */
/* |      |  18  |    SM13   | vddio_alarm           |     7   |    OTHER ALARMS 0     | */
/* |      |  17  |    SM12   | dvddreg_alarm         |     6   |                       | */
/* |______|  16  |    SM11   | avddreg_alarm         |     5   |                       | */
/* |      |  15  |    SM10   | vddmaster_alarm       |     4   |                       | */
/* |      |  14  |    SM08   | temp12_alarm          |     3   |                       | */
/* |      |  13  |    SM08   | temp_dsp_alarm        |     2   |                       | */
/* |   3  |  12  |    SM03   | rcosc2_freqmeas_alarm |     1   |                       | */
/* |      |  11  |    SM03   | rcosc1_freqmeas_alarm |     0   |                       | */
/* |      +------+-----------+-----------------------+---------+-----------------------+ */
/* |      |  10  |    SM03   | sys_clk_alarm         |    13   |                       | */
/* |      |   9  |    SM26   | otp_cpy_alarm         |    12   |                       | */
/* |______|   8  |    SM22   | reg_eccdone_warn      |     9   |                       | */
/* |      |   7  |    SM22   | reg_eccerr_alarm      |     8   |                       | */
/* |      |   6  |    SM22   | ahb_eccdone_warn      |     7   |                       | */
/* |      |   5  |    SM22   | ahb_eccerr_alarm      |     6   |    OTHER ALARMS 1     | */
/* |   4  |   4  |    SM33   | regcheck_alarm        |     5   |                       | */
/* |      |   3  |    SM30   | spi_clkcnt_alarm      |     4   |                       | */
/* |      |   2  |    SM30   | spi_cmddecod_alarm    |     3   |                       | */
/* |      |   1  |    SM30   | spi_crc_alarm         |     2   |                       | */
/* |      |   0  |    SM29   | ahb_bus_alarm         |     1   |                       | */
/* +------+------+-----------+-----------------------+---------+-----------------------+ */
EXPORTED uint32 ACC_u32AlarmRegistersUsefulData = KU32_ZERO;

#define ACC_STOP_SEC_VAR_INIT_32_ASIL_A
#include "ACC_MemMap.h"

#define ACC_START_SEC_VAR_INIT_BOOL_ASIL_A
#include "ACC_MemMap.h"
/**
 * \brief
 *      A flag used to notify that the preinit sequence on ALARMB pin is within normal timing parameters.
 * \initialization
 *      False.
 * \range
 *      0..1.
 */
EXPORTED boolean ACC_bAlarmbPreinitSeqFlag = KB_FALSE;
/**
 * \brief
 *      A flag used to notify that the X-axis of the accelerometer has the same value for the last 30 samples.
 * \initialization
 *      False.
 * \range
 *      0..1.
 */
EXPORTED boolean ACC_bAccelXaxisBrokenFlag = KB_FALSE;
/**
 * \brief
 *      A flag used to notify that the Y-axis of the accelerometer has the same value for the last 30 samples.
 * \initialization
 *      False.
 * \range
 *      0..1.
 */
EXPORTED boolean ACC_bAccelYaxisBrokenFlag = KB_FALSE;
/**
 * \brief
 *      A flag used to notify that the Z-axis of the accelerometer has the same value for the last 30 samples.
 * \initialization
 *      False.
 * \range
 *      0..1.
 */
EXPORTED boolean ACC_bAccelZaxisBrokenFlag = KB_FALSE;
/**
 * \brief
 *      A flag used to notify that the TDK accelerometer chip has some errors.
 * \initialization
 *      False.
 * \range
 *      0..1.
 */
EXPORTED boolean ACC_bAlarmPresentFlag = KB_FALSE;
/**
 * \brief
 *      A flag used to notify that the CRC read from TDK chip was incorrect according with the rest of command.
 * \initialization
 *      False.
 * \range
 *      0..1.
 */
EXPORTED boolean ACC_bReadCrcErrorFlag = KB_FALSE;
/**
 * \brief
 *      A flag used to notify that the two bits of return status from Spi response have value of 0b11.
 * \initialization
 *      False.
 * \range
 *      0..1.
 */
EXPORTED boolean ACC_bReturnStatusErrorFlag = KB_FALSE;

#define ACC_STOP_SEC_VAR_INIT_BOOL_ASIL_A
#include "ACC_MemMap.h"

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
#define ACC_START_SEC_CONST_UNSPECIFIED_ASIL_A
#include "ACC_MemMap.h"

/**
 * \brief
 *       Struct with ACC command Spi Channel and Sequence
 * \initialization
 *       NA.
 * \range
 *       NA.
 */
LOCAL const SpiIf_stSpiChannelSequenceType acc_kstSpiInitChannelSeqeunce = {SpiConf_SpiChannel_Acc_INIT_Ch, SpiConf_SpiSequence_Acc_INIT_Seq};
/**
 * \brief
 *       Struct with ACC command Spi Channel and Sequence
 * \initialization
 *       NA.
 * \range
 *       NA.
 */
LOCAL const SpiIf_stSpiChannelSequenceType acc_kstSpiReadTemperatureChannelSeqeunce = {SpiConf_SpiChannel_Acc_READ_TEMPERATURE_Ch, SpiConf_SpiSequence_Acc_READ_TEMP_Seq};

#define ACC_STOP_SEC_CONST_UNSPECIFIED_ASIL_A
#include "ACC_MemMap.h"

#define ACC_START_SEC_CONST_16_ASIL_A
#include "ACC_MemMap.h"

/**
 * \brief
 *       Array that contains all offset values for calibration of accelerometer
 *       sensor based on a specific rotation angle.
 *
 *       Each value of this array represents the raw (computed) value acceleration
 *       returned by accelerometer sensor when is inclined by a specific angle.
 *       So, for a 360 degrees array will contain 360 values, each index of array
 *       represents the raw value of accelerometer by that angle.
 *
 *       For example:
 *          If we inclined accelerometer on X-axis by 30 degrees, we will measure
 *          about sin(30) = 1/2 = 0.5 G of acceleration, that means a raw value of
 *          0.5 G / 0.125 * 1000 = 4000.
 *
 *       This 4000 is raw value of accelerometer returned without any calculation!!
 *
 *       Applied formula is:
 *       First of all, we need sine computation of angle to determine G acceleration.
 *
 *       Acceleration ( g ) = sine( angle_degrees )
 *
 *       Using acceleration in G, we can determine raw values using formula:
 *
 *       RAW acceleration = Acceleration ( g ) / 0.125 * 1000
 *
 *       Note: The 0.125 coefficient is taken from Accelerometer datasheet, as follows:
 *       Acceleration ( g ) = RAW acceleration * 0.125;
 * 
 * \initialization
 *       NA.
 * \range
 *       NA.
 */
LOCAL const sint16 acc_kas16AccelerometerAngleAxisOffset[U16_ACC_ANGLE_OFFSET_ARRAY_LENGTH] =
{
   0, 140, 279, 419, 558, 697, 836, 975, 1113, 1251, 1389, 1526, 1663, 1800, 1935,
   2071, 2205, 2339, 2472, 2605, 2736, 2867, 2997, 3126, 3254, 3381, 3507, 3632,
   3756, 3878, 4000, 4120, 4239, 4357, 4474, 4589, 4702, 4815, 4925, 5035, 5142,
   5248, 5353, 5456, 5557, 5657, 5755, 5851, 5945, 6038, 6128, 6217, 6304, 6389,
   6472, 6553, 6632, 6709, 6784, 6857, 6928, 6997, 7064, 7128, 7190, 7250, 7308,
   7364, 7417, 7469, 7518, 7564, 7608, 7650, 7690, 7727, 7762, 7795, 7825, 7853,
   7878, 7902, 7922, 7940, 7956, 7970, 7981, 7989, 7995, 7999, 8000, 7999, 7995,
   7989, 7981, 7970, 7956, 7940, 7922, 7902, 7878, 7853, 7825, 7795, 7762, 7727,
   7690, 7650, 7608, 7564, 7518, 7469, 7417, 7364, 7308, 7250, 7190, 7128, 7064,
   6997, 6928, 6857, 6784, 6709, 6632, 6553, 6472, 6389, 6304, 6217, 6128, 6038,
   5945, 5851, 5755, 5657, 5557, 5456, 5353, 5248, 5142, 5035, 4925, 4815, 4702,
   4589, 4474, 4357, 4239, 4120, 4000, 3878, 3756, 3632, 3507, 3381, 3254, 3126,
   2997, 2867, 2736, 2605, 2472, 2339, 2205, 2071, 1935, 1800, 1663, 1526, 1389,
   1251, 1113, 975, 836, 697, 558, 419, 279, 140, 0, -140, -279, -419, -558,
   -697, -836, -975, -1113, -1251, -1389, -1526, -1663, -1800, -1935, -2071,
   -2205, -2339, -2472, -2605, -2736, -2867, -2997, -3126, -3254, -3381, -3507,
   -3632, -3756, -3878, -4000, -4120, -4239, -4357, -4474, -4589, -4702, -4815,
   -4925, -5035, -5142, -5248, -5353, -5456, -5557, -5657, -5755, -5851, -5945,
   -6038, -6128, -6217, -6304, -6389, -6472, -6553, -6632, -6709, -6784, -6857,
   -6928, -6997, -7064, -7128, -7190, -7250, -7308, -7364, -7417, -7469, -7518,
   -7564, -7608, -7650, -7690, -7727, -7762, -7795, -7825, -7853, -7878, -7902,
   -7922, -7940, -7956, -7970, -7981, -7989, -7995, -7999, -8000, -7999, -7995,
   -7989, -7981, -7970, -7956, -7940, -7922, -7902, -7878, -7853, -7825, -7795,
   -7762, -7727, -7690, -7650, -7608, -7564, -7518, -7469, -7417, -7364, -7308,
   -7250, -7190, -7128, -7064, -6997, -6928, -6857, -6784, -6709, -6632, -6553,
   -6472, -6389, -6304, -6217, -6128, -6038, -5945, -5851, -5755, -5657, -5557,
   -5456, -5353, -5248, -5142, -5035, -4925, -4815, -4702, -4589, -4474, -4357,
   -4239, -4120, -4000, -3878, -3756, -3632, -3507, -3381, -3254, -3126, -2997,
   -2867, -2736, -2605, -2472, -2339, -2205, -2071, -1935, -1800, -1663, -1526,
   -1389, -1251, -1113, -975, -836, -697, -558, -419, -279, -140, 0
};

#define ACC_STOP_SEC_CONST_16_ASIL_A
#include "ACC_MemMap.h"

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/
/**
 * \brief
 *       SPI to eCS  (g to m/s^2) shift power.
 */
#define ACC_U8_ACCEL_TO_S16(MSB, LSB)  ((sint16)((((uint16)(MSB) << 0x08) & (uint16)0xFF00) | ((uint16)(LSB) & (uint16)0x00FF)))
/**
 * \brief
 *       Define used to concatenate two uint8 to one uint16.
 */
#define ACC_U8_ACCEL_TO_U16(MSB, LSB)  ((((uint16)(MSB) << 0x08) & (uint16)0xFF00) | ((uint16)(LSB) & (uint16)0x00FF))
/**
 * \brief
 *       Macro used to return raw acceleration value based on a specific degree angle
 *       This macro will have as input value of angle ( degrees, in range 0 - 360 )
 *       and will return a raw acceleration value based on this angle.
 *
 */
#define ACC_S32_GET_ANGLE_OFFSET_RAW_ACC(uint16DegreeAngle) \
   (((uint16DegreeAngle) <= (uint16)360) ? acc_kas16AccelerometerAngleAxisOffset[uint16DegreeAngle] : KS16_ZERO)

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
#define ACC_START_SEC_CODE_ASIL_A
#include "ACC_MemMap.h"

/**
 * \brief
 *     Function used to create and send Spi frame to read or write a register of Accelerometer.
 * \inputparam
 *     Name: ku8ReadOrWriteFlag;
 *     Type: const uint8;
 *     Description: This flag is used to select if the command is a read or a write command.;
 *     Range: 0..1;
 * \inputparam
 *     Name: ku8RegisterAddress;
 *     Type: const uint8;
 *     Description: The address of Accelereometer Register to Read/Write.;
 *     Range: 0..31;
 * \inputparam
 *     Name: kpu16RegisterDataCommand;
 *     Type: const uint16 *;
 *     Description: Data to write in Accelerometer Register;
 *     Range: 0..KU16_MAX;
 * \inputparam
 *     Name: kpstAccelerometerChannelSequence;
 *     Type: const SpiIf_stSpiChannelSequenceType * (struct[uint8, uint8]);
 *     Description: A structure that contain the Spi Channel and Sequence;
 *     Range: NA.;
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     ACC module (locally).
 * \dynamicaspectdescription
 *     Called locally in ACC_ReadAccelerometerData and ACC_ReadAccelerometerTemperature functions via direct call.
 * \ddesignrequirement
 *     DSG_acc_SendCommandToReadOrWriteRegister
 * \archrequirement
 *     ARCH_SW_ACC_ptrpAsrOsServices_ACC_runMainFunction;
 *     ARCH_SW_ACC_ptrrSpiIfServices_SpiIf_writeSpiData_ACC_runMainFunction;
 **/
LOCAL void acc_SendCommandToReadOrWriteRegister(const uint8 ku8ReadOrWriteFlag,
                                                const uint8 ku8RegisterAddress,
                                                const uint16 *kpu16RegisterDataCommand,
                                                const SpiIf_stSpiChannelSequenceType *kpstAccelerometerChannelSequence)
{
   uint8 au8TransmitBuffer[KU8_FOUR];

   au8TransmitBuffer[KU8_THREE] = (uint8)(ku8ReadOrWriteFlag << KU8_SEVEN) + (uint8)(ku8RegisterAddress << KU8_TWO);
   au8TransmitBuffer[KU8_TWO] = (uint8)(*kpu16RegisterDataCommand >> KU8_EIGHT);
   au8TransmitBuffer[KU8_ONE] = (uint8)*kpu16RegisterDataCommand;
   au8TransmitBuffer[KU8_ZERO] = acc_ComputeCRC(au8TransmitBuffer);
   SpiIf_writeSpiData(*kpstAccelerometerChannelSequence, au8TransmitBuffer);
}

/**
 * \brief
 *     Function used to read the register data from Spi response of accelerometer .
 * \outputparam
 *     Name: pu16RegisterDataRead;
 *     Type: uint16 *;
 *     Description: Data read from Accelerometer Register.;
 *     Range: 0..KU16_MAX;
 * \inputparam
 *     Name: kpu8AccelerometerChannel;
 *     Type: const Spi_ChannelType * (uint8);
 *     Description: The Spi Channel from which to read the internal buffer;
 *     Range: NA.;
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     ACC module (locally).
 * \dynamicaspectdescription
 *     Called locally in ACC_ReadAccelerometerData and ACC_ReadAccelerometerTemperature functions via direct call.
 * \ddesignrequirement
 *     DSG_acc_GetRegDataResponseFromSpiIB
  * \archrequirement
 *     ARCH_SW_ACC_ptrpAsrOsServices_ACC_runMainFunction;
 *     ARCH_SW_ACC_ptrrSpiIfServices_SpiIf_spiReadIBFromChannel_ACC_runMainFunction;
 **/
LOCAL void acc_GetRegDataResponseFromSpiIB(uint16 *pu16RegisterDataRead, const Spi_ChannelType *kpu8AccelerometerChannel)
{
   uint8 au8ReceiveBuffer[KU8_FOUR];
   uint8 u8ReturnStatus = KU8_ZERO;
   uint8 u8CalculatedCRC = KU8_ZERO;

   SpiIf_spiReadIBFromChannel(*kpu8AccelerometerChannel, &au8ReceiveBuffer[KU8_ZERO]);

   *pu16RegisterDataRead = (uint16)((uint16)au8ReceiveBuffer[KU8_TWO] << KU8_EIGHT) | (uint16)au8ReceiveBuffer[KU8_ONE];

   /* Verify if Retrun Status bits have value of 0b11 */
   u8ReturnStatus = (au8ReceiveBuffer[KU8_THREE] & KU8_ACC_SPI_RESPONSE_RS_MASK);
   if (KU8_ACC_RETURN_STATUS_ERROR == u8ReturnStatus)
   {
      ACC_bReturnStatusErrorFlag = KB_TRUE;
   }

   /* Verify if the received CRC is equal with calculated CRC */
   u8CalculatedCRC = acc_ComputeCRC(au8ReceiveBuffer);
   if (u8CalculatedCRC != au8ReceiveBuffer[KU8_ZERO])
   {
      ACC_bReadCrcErrorFlag = KB_TRUE;
   }
}

/**
 * \brief
 *     Function used to calculate the CRC byte of Accelerometer Spi Command 
 *     (function given by the TDK accelerometer datasheet).
 * \inputparam
 *     Name: kpu8Buffer;
 *     Type: const uint8 *;
 *     Description: Pointer to spi buffer array;
 *     Range: 0..1;
 * \return
 *     CRC calculated value.
 * \dynamicaspectcaller
 *     ACC module.
 * \dynamicaspectdescription
 *     Called locally in acc_ReadOrWriteRegister local function via direct call.
 * \ddesignrequirement
 *     DSG_acc_ComputeCRC
 * \archrequirement
 *     ARCH_SW_ACC_ptrpAsrOsServices_ACC_runMainFunction
 **/
LOCAL uint8 acc_ComputeCRC(const uint8 *kpu8Buffer)
{
   register uint32 u32Input;
   register uint8 u8CRC = KU8_MAX;
   register uint8 u8Index;
   register uint8 u8CRC_New = KU8_ZERO;

   u32Input = ((uint32)kpu8Buffer[KU8_THREE] << KU8_SIXTEEN) + ((uint32)kpu8Buffer[KU8_TWO] << KU8_EIGHT) + (uint32)kpu8Buffer[KU8_ONE];

   for (u8Index = KU8_TWENTYFOUR; u8Index != KU8_ZERO; u8Index--)
   {
      u8CRC_New = u8CRC << KU8_ONE;
      u8CRC_New = (u8CRC_New & KU8_BIT_4_ZERO) | ((uint8)((u8CRC & KU8_MASK_BIT_3) << KU8_ONE) ^ ((u8CRC & KU8_MASK_BIT_7) >> KU8_THREE));
      u8CRC_New = (u8CRC_New & KU8_BIT_3_ZERO) | ((uint8)((u8CRC & KU8_MASK_BIT_2) << KU8_ONE) ^ ((u8CRC & KU8_MASK_BIT_7) >> KU8_FOUR));
      u8CRC_New = (u8CRC_New & KU8_BIT_2_ZERO) | ((uint8)((u8CRC & KU8_MASK_BIT_1) << KU8_ONE) ^ ((u8CRC & KU8_MASK_BIT_7) >> KU8_FIVE));
      u8CRC_New = (u8CRC_New & KU8_BIT_0_ZERO) | ((uint8)((u32Input & (KU32_ONE << (u8Index - KU8_ONE))) >> (u8Index - KU8_ONE)) ^ ((u8CRC & KU8_MASK_BIT_7) >> KU8_SEVEN));
      u8CRC = u8CRC_New;
   }
   u8CRC = u8CRC ^ KU8_MAX;

   return u8CRC;
}

/**
 * \brief
 *     The initialization function of Accelerometer.
 * \return
 *     NA.
 * \dynamicaspectcaller
 *     ACC module.
 * \dynamicaspectdescription
 *     Called locally in ACC_runMainFunction function via direct call.
 * \ddesignrequirement
 *     DSG_acc_Init
 * \archrequirement
 *     ARCH_SW_ACC_ptrpAsrOsServices_ACC_runMainFunction;
 *     ARCH_SW_ACC_ptrrSpiIfServices_SpiIf_writeSpiData_ACC_runMainFunction;
 *     ARCH_SW_ACC_ptrrSpiIfServices_SpiIf_spiReadIBFromChannel_ACC_runMainFunction;
 *     ARCH_SW_SpiIf_ptrrAsrSpiServices_Spi_SyncTransmit_SpiIf_spiSyncTransmitSequence;
 **/
LOCAL void acc_Init(void)
{
   switch (acc_u8AccInitSM)
   {
      case KU8_ACC_INIT_CHECK_ALARMB_SEQ:
      {
         if (KU8_ZERO == acc_u8AccInitCnt)
         {
            /* enable ALARMB pin external interrupt on rising edge */
            PORTE->PCR[KU8_ELEVEN] = (PORTE->PCR[KU8_ELEVEN] & (~PORT_PCR_IRQC_MASK)) | (KU8_ACC_PORTE_INTERRUPT_RISING_EDGE << (PORT_PCR_IRQC_SHIFT));

            Dio_WriteChannel(DioConf_DioChannel_Dio_Sleep_Off, STD_HIGH);
            Dio_WriteChannel(DioConf_DioChannel_Dio_ACC_RESETN, STD_HIGH);

            DioIf_SetSolenoidCurrentSourcesState(STD_HIGH);

            /* restore ACC pins */
            PORTD->PCR[KU8_ZERO] = KU16_ACC_PORT_MUX_300;
            PORTD->PCR[KU8_ONE] = KU16_ACC_PORT_MUX_300;
            PORTD->PCR[KU8_TWO] = KU16_ACC_PORT_MUX_300;
            PORTE->PCR[KU8_ONE] = KU16_ACC_PORT_MUX_500;
         }

         /* wait check ALARMB pin sequence at startup */
         if ((KU8_ACC_TIMEOUT_PREINIT_CHECK_ALARMB_SEQ > acc_u8AccInitCnt) && (KB_FALSE == acc_bPreinitSeqAlarmbWasChecked))
         {
            acc_u8AccInitCnt++;
         }
         else
         {
            /* disable ALARMB pin external interrupt */
            PORTE->PCR[KU8_ELEVEN] = (PORTE->PCR[KU8_ELEVEN] & (~PORT_PCR_IRQC_MASK)) | (KU8_ACC_PORTE_INTERRUPT_DISABLE << PORT_PCR_IRQC_SHIFT);
            
            Gpt_StopTimer(GPT_ACC_TIMER);

            if (KB_FALSE == acc_bPreinitSeqAlarmbWasChecked)
            {
               ACC_bAlarmbPreinitSeqFlag = KB_TRUE;
            }
            acc_u8AccInitSM++;
            acc_u8AccInitCnt = KU8_ZERO;
         }
         break;
      }
      case KU8_ACC_INIT_IDLE:
      {

         if (KU8_ACC_WAIT_ACC_INITIALIZATION_TIMER > acc_u8AccInitCnt)
         {
            acc_u8AccInitCnt++;
         }
         else
         {
            acc_u8AccInitSM++;
            acc_u8AccInitCnt = KU8_ZERO;
         }
         break;
      }
      case KU8_ACC_INIT_READ_GYRO_X_AXIS_FILTER_SETTINGS:
      {
         /* send a request to read Status Summary and X Axis Filter Settings Register */
         acc_u16RegisterDataTransmit = KU16_ZERO;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_X_AXIS_FILTER_SET_BK_0,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_READ_GYRO_Y_Z_AXIS_FILTER_SETTINGS:
      {
         /* send a request to read Accelerometer and Gyroscope Y and Z Axis Filter Settings Register
         and read value of Status Summary and X Axis Filter Settings Register from last request */
         acc_u16RegisterDataTransmit = KU16_ZERO;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_Y_Z_AXIS_FILTER_SET_BK_0,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_GetRegDataResponseFromSpiIB((uint16 *)&acc_u16XAxisFilterRegDataReceive, &acc_kstSpiInitChannelSeqeunce.kstSpiChannel);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_WRITE_GYRO_X_AXIS_FILTER_SETTINGS:
      {
         /* change some bits from Status Summary and X Axis Filter Settings Register and send a command to write data in register
         and read value of Accelerometer and Gyroscope Y and Z Axis Filter Settings Register from last request */
         acc_u16RegisterDataTransmit = (acc_u16XAxisFilterRegDataReceive & KU16_ACC_REG_X_AXIS_FILTER_SET_BK_0_MASK) |
                                       (uint16)((uint16)NVP_u8XaxisLowPass << KU8_EIGHT);
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_WRITE_REGISTER_FLAG, KU8_ACC_REG_X_AXIS_FILTER_SET_BK_0,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_GetRegDataResponseFromSpiIB((uint16 *)&acc_u16YZAxisFilterRegDataReceive, &acc_kstSpiInitChannelSeqeunce.kstSpiChannel);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_WRITE_GYRO_Y_Z_AXIS_FILTER_SETTINGS:
      {
         /* change some bits from Accelerometer and Gyroscope Y and Z Axis Filter Settings Register
         and send a command to write data in register */
         acc_u16RegisterDataTransmit = (acc_u16YZAxisFilterRegDataReceive & KU16_ACC_REG_Y_Z_AXIS_FILTER_SET_BK_0_MASK) |
                                       ((uint16)NVP_u8YaxisLowPass | (uint16)((uint16)NVP_u8ZaxisLowPass << KU8_SIX));
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_WRITE_REGISTER_FLAG, KU8_ACC_REG_Y_Z_AXIS_FILTER_SET_BK_0,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_UNLOCK_SETTINGS:
      {
         /* send unlock sequence provided by TDK datasheet*/
         SpiIf_spiSyncTransmitSequence(SpiConf_SpiSequence_Acc_UNLOCK_Seq);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_BANK_SWITCH_6:
      {
         /* send a command to change current bank to bank 6 */
         acc_u16RegisterDataTransmit = KU16_ACC_SET_BANK_SELECTION_BK_6;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_WRITE_REGISTER_FLAG, KU8_ACC_REG_BANK_SELECTION,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_READ_SENSITIVITY_CONFIG:
      {
         /* send a request to read Sensivity Configuration Register from Bank 6 */
         acc_u16RegisterDataTransmit = KU16_ZERO;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_SENSIVITY_CONFIG_BK_6,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_READ_DUMMY_SENSITIVITY_CONFIG:
      {
         /* resend last command to read response data from Sensivity Configuration Register from Bank 6*/
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_SENSIVITY_CONFIG_BK_6,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_GetRegDataResponseFromSpiIB((uint16 *)&acc_u16SensivityConfigRegDataReceive, &acc_kstSpiInitChannelSeqeunce.kstSpiChannel);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_WRITE_SENSITIVITY_CONFIG:
      {
         /* change some bits from Sensivity Configuration Register from Bank 6
         to set Accelerometer sensivity to +/- 4g and send a command to write data in register */
         acc_u16RegisterDataTransmit = (acc_u16SensivityConfigRegDataReceive & KU16_ACC_REG_SENSIVITY_CONFIG_BK_6_MASK_ACCEL_FS_SEL) |
                                       KU16_ACC_SET_SENSIVITY_CONFIG_BANK_6_ACCEL_FS_SEL;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_WRITE_REGISTER_FLAG, KU8_ACC_REG_SENSIVITY_CONFIG_BK_6,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_BANK_SWITCH_1:
      {
         /* send a command to change current bank to bank 1 */
         acc_u16RegisterDataTransmit = KU16_ACC_SET_BANK_SELECTION_BK_1;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_WRITE_REGISTER_FLAG, KU8_ACC_REG_BANK_SELECTION,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_READ_S_M_ENABLE0:
      {
         /* send a command to read Safety Mechanisms Enable 0 Register from bank 1 */
         acc_u16RegisterDataTransmit = KU16_ZERO;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_S_M_ENABLE_0_BK_1,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_READ_S_M_ENABLE1:
      {
         /* send a command to read Safety Mechanisms Enable 1 Register from bank 1
         And receive response from Safety Mechanisms Enable 0 Register */
         acc_u16RegisterDataTransmit = KU16_ZERO;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_S_M_ENABLE_1_BK_1,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_GetRegDataResponseFromSpiIB((uint16 *)&acc_u16SmEnable_0_DataReceive, &acc_kstSpiInitChannelSeqeunce.kstSpiChannel);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_WRITE_S_M_ENABLE0:
      {
         /* change some bits from Safety Mechanisms Enable 0 Register from Bank 1 to disable SM04
         And receive response from Safety Mechanisms Enable 1 Register */
         acc_u16RegisterDataTransmit = (acc_u16SmEnable_0_DataReceive & KU16_ACC_REG_S_M_ENABLE_0_MASK_RW_BITS) |
                                       KU16_ACC_SET_S_M_ENABLE_0_BK_1_USED_S_M;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_WRITE_REGISTER_FLAG, KU8_ACC_REG_S_M_ENABLE_0_BK_1,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_GetRegDataResponseFromSpiIB((uint16 *)&acc_u16SmEnable_1_DataReceive, &acc_kstSpiInitChannelSeqeunce.kstSpiChannel);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_WRITE_S_M_ENABLE1:
      {
         /* change some bits from Safety Mechanisms Enable 1 Register from Bank 1 to disable SM36 */
         acc_u16RegisterDataTransmit = (acc_u16SmEnable_1_DataReceive & KU16_ACC_REG_S_M_ENABLE_1_MASK_RW_BITS) |
                                       KU16_ACC_SET_S_M_ENABLE_1_BK_1_USED_S_M;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_WRITE_REGISTER_FLAG, KU8_ACC_REG_S_M_ENABLE_1_BK_1,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_READ_S_M_MASK0:
      {
         /* send a command to read Safety Mechanisms Mask 0 Register from bank 1 */
         acc_u16RegisterDataTransmit = KU16_ZERO;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_S_M_MASK_0_BK_1,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_READ_S_M_MASK1:
      {
         /* send a command to read Safety Mechanisms Mask 1 Register from bank 1
         And receive response from Safety Mechanisms Mask 0 Register */
         acc_u16RegisterDataTransmit = KU16_ZERO;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_S_M_MASK_1_BK_1,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_GetRegDataResponseFromSpiIB((uint16 *)&acc_u16SmMask_0_DataReceive, &acc_kstSpiInitChannelSeqeunce.kstSpiChannel);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_READ_S_M_MASK3:
      {
         /* send a command to read Safety Mechanisms Mask 3 Register from bank 1
         And receive response from Safety Mechanisms Mask 2 Register */
         acc_u16RegisterDataTransmit = KU16_ZERO;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_S_M_MASK_3_BK_1,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_GetRegDataResponseFromSpiIB((uint16 *)&acc_u16SmMask_1_DataReceive, &acc_kstSpiInitChannelSeqeunce.kstSpiChannel);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_WRITE_S_M_MASK0:
      {
         /* change some bits from Safety Mechanisms Mask 0 Register from Bank 1
         to mask gyro_quadadc_alarm and gyro_drfreqmeas_alarm
         And receive response from Safety Mechanisms Mask 4 Register */
         acc_u16RegisterDataTransmit = (acc_u16SmMask_0_DataReceive & KU16_ACC_REG_S_M_MASK_0_MASK_RW_BITS) |
                                       KU16_ACC_SET_S_M_MASK_0_BK_1_MASKED_S_M;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_WRITE_REGISTER_FLAG, KU8_ACC_REG_S_M_MASK_0_BK_1,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_GetRegDataResponseFromSpiIB((uint16 *)&acc_u16SmMask_3_DataReceive, &acc_kstSpiInitChannelSeqeunce.kstSpiChannel);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_WRITE_S_M_MASK1:
      {
         /* change some bits from Safety Mechanisms Mask 1 Register from Bank 1
         to mask gyro_vref_alarm and gyro_drclk_alarm*/
         acc_u16RegisterDataTransmit = (acc_u16SmMask_1_DataReceive & KU16_ACC_REG_S_M_MASK_1_MASK_RW_BITS) |
                                       KU16_ACC_SET_S_M_MASK_1_BK_1_MASKED_S_M;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_WRITE_REGISTER_FLAG, KU8_ACC_REG_S_M_MASK_1_BK_1,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_WRITE_S_M_MASK3:
      {
         /* change some bits from Safety Mechanisms Mask 3 Register from Bank 1
         to mask gyro_dcst_alarm */
         acc_u16RegisterDataTransmit = (acc_u16SmMask_3_DataReceive & KU16_ACC_REG_S_M_MASK_3_MASK_RW_BITS) |
                                       KU16_ACC_SET_S_M_MASK_3_BK_1_MASKED_S_M;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_WRITE_REGISTER_FLAG, KU8_ACC_REG_S_M_MASK_3_BK_1,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_BANK_SWITCH_0:
      {
         /* send a command to change current bank to bank 0 */
         acc_u16RegisterDataTransmit = KU16_ACC_SET_BANK_SELECTION_BK_0;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_WRITE_REGISTER_FLAG, KU8_ACC_REG_BANK_SELECTION,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_READ_MODE_REGISTER:
      {
         /* send a request to read Mode Registers - Register from Bank 0 */
         acc_u16RegisterDataTransmit = KU16_ZERO;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_MODE_REGISTER_BK_0,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_READ_DUMMY_MODE_REGISTER:
      {
         /* resend last command to read response data from Mode Registers - Register from Bank 0*/
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_MODE_REGISTER_BK_0,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_GetRegDataResponseFromSpiIB((uint16 *)&acc_u16ModeRegDataReceive, &acc_kstSpiInitChannelSeqeunce.kstSpiChannel);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_WRITE_MODE_REGISTER:
      {
         /* change some bits from Mode Registers - Register from Bank 0
         to activate write register lock and send a command to write data in register */
         acc_u16RegisterDataTransmit = (acc_u16ModeRegDataReceive & KU16_ACC_REG_MODE_REGISTES_BK_0_MASK_REG_WRITE_LOCK) |
                                       KU16_ACC_SET_MODE_REGISTES_BK_0_REG_WRITE_LOCK;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_WRITE_REGISTER_FLAG, KU8_ACC_REG_MODE_REGISTER_BK_0,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);

         acc_u8AccInitSM++;
         break;
      }
      case KU8_ACC_INIT_WAIT_READY:
      {
         if (KU8_ACC_WAIT_ACC_SENS_SWITCH_TIMER > acc_u8AccInitCnt)
         {
            acc_u8AccInitCnt++;
         }
         else
         {
            acc_u8AccInitSM++;
            acc_u8AccInitCnt = KU8_ZERO;
         }
         break;
      }
      default:
      {
         break;
      }
   }
}

/**
 * \brief
 *     Function used to read and compute 3 axis of acceleration data from TDK Accelerometer chip.
 * \return
 *     NA.
 * \dynamicaspectcaller
 *     ACC module.
 * \dynamicaspectdescription
 *     Called locally in ACC_runMainFunction function via direct call.
 * \ddesignrequirement
 *     DSG_acc_ReadData
 * \archrequirement
 *     ARCH_SW_ACC_ptrpAsrOsServices_ACC_runMainFunction
 *     ARCH_SW_ACC_psr3DAcceleration
 *     ARCH_SW_ACC_pclDioIfServices
 *     ARCH_SW_ACC_psrAccelMtrPerSecSqd
 *     ARCH_SW_ACC_ptrrSpiIfServices_SpiIf_spiReadIBFromChannel_ACC_runMainFunction
 *     ARCH_SW_ACC_ptrrSpiIfServices_SpiIf_spiSyncTransmitSequence_ACC_runMainFunction
 **/
LOCAL void acc_ReadData(void)
{
   REC_3D_AccelMtrPerSecSqdType stCarAcceleration;
   REC_3D_AccelerationType stRawAccel;
   register sint32 s32IntermediateValue = KS32_ZERO;
   uint8 au8AxAccelerationRegData[KU8_FOUR];
   uint8 au8AyAccelerationRegData[KU8_FOUR];
   uint8 au8AzAccelerationRegData[KU8_FOUR];
   uint8 u8CalculatedCRC = KU8_ZERO;
   uint8 u8ReturnStatus = KU8_ZERO;
   uint8 u8AlarmbState = KU8_ONE;
   uint8 u8Idx = KU8_ZERO;
   uint8 u8ProfileActive = KU8_FALSE;
   uint8 au8SelectedProfile[KU8_MAX_SOLENOID_NB] = {
         KU8_PROFILE_NONE, KU8_PROFILE_NONE, KU8_PROFILE_NONE,
         KU8_PROFILE_NONE, KU8_PROFILE_NONE, KU8_PROFILE_NONE
   };

   (void)Rte_Read_prrSolenoidProfile_au8SelectedProfile((uint8 *)au8SelectedProfile);

   /* Send spi request to read acceleration data registers of TDK */
   SpiIf_spiSyncTransmitSequence(SpiConf_SpiSequence_Acc_READ_Ax_Ay_Az_Seq);

   /* Read IB with Ax, Ay and Az data*/
   SpiIf_spiReadIBFromChannel(SpiConf_SpiChannel_Acc_READ_AY_Ch, &au8AxAccelerationRegData[KU8_ZERO]);
   SpiIf_spiReadIBFromChannel(SpiConf_SpiChannel_Acc_READ_AZ_Ch, &au8AyAccelerationRegData[KU8_ZERO]);
   SpiIf_spiReadIBFromChannel(SpiConf_SpiChannel_Acc_Dummy_Ch, &au8AzAccelerationRegData[KU8_ZERO]);

   /* verify if last 30 samples of accelerometer data have same value (FUSA_SM_ACC_DS-000342_IAM-20685_141) */
   acc_u16AccelXaxisCurrentReadData = ACC_U8_ACCEL_TO_U16(au8AxAccelerationRegData[KU8_TWO], au8AxAccelerationRegData[KU8_ONE]);
   acc_u16AccelYaxisCurrentReadData = ACC_U8_ACCEL_TO_U16(au8AyAccelerationRegData[KU8_TWO], au8AyAccelerationRegData[KU8_ONE]);
   acc_u16AccelZaxisCurrentReadData = ACC_U8_ACCEL_TO_U16(au8AzAccelerationRegData[KU8_TWO], au8AzAccelerationRegData[KU8_ONE]);

   if (acc_u16AccelXaxisCurrentReadData == acc_u16AccelXaxisPreviousReadData)
   {
      if (KU8_THIRTY > acc_u8ConsecutiveXaxisIdenticalValuesCounter)
      {
         acc_u8ConsecutiveXaxisIdenticalValuesCounter++;
      }
      else
      {
         ACC_bAccelXaxisBrokenFlag = KB_TRUE;
      }
   }
   else
   {
      acc_u8ConsecutiveXaxisIdenticalValuesCounter = KU8_ZERO;
   }

   if (acc_u16AccelYaxisCurrentReadData == acc_u16AccelYaxisPreviousReadData)
   {
      if (KU8_THIRTY > acc_u8ConsecutiveYaxisIdenticalValuesCounter)
      {
         acc_u8ConsecutiveYaxisIdenticalValuesCounter++;
      }
      else
      {
         ACC_bAccelYaxisBrokenFlag = KB_TRUE;
      }
   }
   else
   {
      acc_u8ConsecutiveYaxisIdenticalValuesCounter = KU8_ZERO;
   }

   if (acc_u16AccelZaxisCurrentReadData == acc_u16AccelZaxisPreviousReadData)
   {
      if (KU8_THIRTY > acc_u8ConsecutiveZaxisIdenticalValuesCounter)
      {
         acc_u8ConsecutiveZaxisIdenticalValuesCounter++;
      }
      else
      {
         ACC_bAccelZaxisBrokenFlag = KB_TRUE;
      }
   }
   else
   {
      acc_u8ConsecutiveZaxisIdenticalValuesCounter = KU8_ZERO;
   }
   
   acc_u16AccelXaxisPreviousReadData = acc_u16AccelXaxisCurrentReadData;
   acc_u16AccelYaxisPreviousReadData = acc_u16AccelYaxisCurrentReadData;
   acc_u16AccelZaxisPreviousReadData = acc_u16AccelZaxisCurrentReadData;

   /* verify CRC for each channel*/
   u8CalculatedCRC = acc_ComputeCRC(au8AxAccelerationRegData);
   if (u8CalculatedCRC != au8AxAccelerationRegData[KU8_ZERO])
   {
      ACC_bReadCrcErrorFlag = KB_TRUE;
   }
   u8CalculatedCRC = acc_ComputeCRC(au8AyAccelerationRegData);
   if (u8CalculatedCRC != au8AyAccelerationRegData[KU8_ZERO])
   {
      ACC_bReadCrcErrorFlag = KB_TRUE;
   }
   u8CalculatedCRC = acc_ComputeCRC(au8AzAccelerationRegData);
   if (u8CalculatedCRC != au8AzAccelerationRegData[KU8_ZERO])
   {
      ACC_bReadCrcErrorFlag = KB_TRUE;
   }

   /* Verify if Retrun Status bits have value of 0b11 */
   u8ReturnStatus = (au8AxAccelerationRegData[KU8_THREE] & KU8_ACC_SPI_RESPONSE_RS_MASK);
   if (KU8_ACC_RETURN_STATUS_ERROR == u8ReturnStatus)
   {
      ACC_bReturnStatusErrorFlag = KB_TRUE;
   }
   u8ReturnStatus = (au8AyAccelerationRegData[KU8_THREE] & KU8_ACC_SPI_RESPONSE_RS_MASK);
   if (KU8_ACC_RETURN_STATUS_ERROR == u8ReturnStatus)
   {
      ACC_bReturnStatusErrorFlag = KB_TRUE;
   }
   u8ReturnStatus = (au8AzAccelerationRegData[KU8_THREE] & KU8_ACC_SPI_RESPONSE_RS_MASK);
   if (KU8_ACC_RETURN_STATUS_ERROR == u8ReturnStatus)
   {
      ACC_bReturnStatusErrorFlag = KB_TRUE;
   }

   /* get acceleration data from response frame */
   stRawAccel.s16Ay = ACC_U8_ACCEL_TO_S16(au8AyAccelerationRegData[KU8_TWO], au8AyAccelerationRegData[KU8_ONE]);

   if (KUB_eCS_ACC_ON_PCB_BOTTOM_VARIANT)
   {
      stRawAccel.s16Az = -ACC_U8_ACCEL_TO_S16(au8AzAccelerationRegData[KU8_TWO], au8AzAccelerationRegData[KU8_ONE]);
      stRawAccel.s16Ax = -ACC_U8_ACCEL_TO_S16(au8AxAccelerationRegData[KU8_TWO], au8AxAccelerationRegData[KU8_ONE]);
   }
   else
   {
      stRawAccel.s16Az = ACC_U8_ACCEL_TO_S16(au8AzAccelerationRegData[KU8_TWO], au8AzAccelerationRegData[KU8_ONE]);
      stRawAccel.s16Ax = ACC_U8_ACCEL_TO_S16(au8AxAccelerationRegData[KU8_TWO], au8AxAccelerationRegData[KU8_ONE]);
   }

   /* Calibrate RAW values of axis by a specific given angle */
   stRawAccel.s16Ax = stRawAccel.s16Ax - ACC_S32_GET_ANGLE_OFFSET_RAW_ACC(NVP_u16XAxisAngleCalib);
   stRawAccel.s16Ay = stRawAccel.s16Ay - ACC_S32_GET_ANGLE_OFFSET_RAW_ACC(NVP_u16YAxisAngleCalib);
   stRawAccel.s16Az = stRawAccel.s16Az - ACC_S32_GET_ANGLE_OFFSET_RAW_ACC(NVP_u16ZAxisAngleCalib);

   (void)Rte_Write_ACC_psr3DAcceleration_st3DAccel(&stRawAccel);

   /* Convert acceleration raw data to g-data */
   /* Ax Conversion */
   s32IntermediateValue = (((sint32)stRawAccel.s16Ax + (sint32)NVP_s16OffsetAx) * S32_ACC_CONVERSION_MULTIPLAYER);
   stCarAcceleration.s16Ax = (sint16)(s32IntermediateValue >> KU8_ACC_SHIFT_POWER);

   /* Ay Conversion */
   s32IntermediateValue = (sint32)((sint32)(stRawAccel.s16Ay + NVP_s16OffsetAy) * S32_ACC_CONVERSION_MULTIPLAYER);
   stCarAcceleration.s16Ay = (sint16)(s32IntermediateValue >> KU8_ACC_SHIFT_POWER);

   /* Az not used yet */
   s32IntermediateValue = (sint32)((sint32)(stRawAccel.s16Az + NVP_s16OffsetAz) * S32_ACC_CONVERSION_MULTIPLAYER);
   stCarAcceleration.s16Az = (sint16)(s32IntermediateValue >> KU8_ACC_SHIFT_POWER);

   (void)Rte_Write_psrAccelMtrPerSecSqd_stAccelMtrPerSecSqd(&stCarAcceleration);

   /* check if ALARMB pin is triggered (alarm present on low level) */
   Rte_Call_pclDioIfServices_ReadChannel(KU8_ACC_DIO_ALARMB_PIN_ID, &u8AlarmbState);
   if (KU8_ZERO == u8AlarmbState)
   {
      ACC_bAlarmPresentFlag = KB_TRUE;
   }

   /* read status of alarms from alarm register after every 10 ms */
   if (KU8_NINE < acc_u8ReadAlarmRegistersPeriodCounter)
   {
      for (u8Idx = 0; u8Idx < KU8_MAX_SOLENOID_NB; u8Idx++)
      {
         if(KU8_PROFILE_NONE != au8SelectedProfile[u8Idx])
         {
            u8ProfileActive = KU8_TRUE;
            break;
         }
      }
      if(KU8_FALSE == u8ProfileActive)
      {
         acc_ReadAlarmRegisters();
      }
      acc_u8ReadAlarmRegistersPeriodCounter = KU8_ZERO;
   }
   acc_u8ReadAlarmRegistersPeriodCounter++;
}

/**
 * \brief
 *     Function used to read used status registers from TDK Accelerometer.
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     ACC module.
 * \dynamicaspectdescription
 *     Called locally in ACC_runMainFunction function via direct call.
 * \ddesignrequirement
 *     DSG_ACC_ReadAlarmRegisters
 * \archrequirement
 *     ARCH_SW_ACC_ptrpAsrOsServices_ACC_runMainFunction
 *     ARCH_SW_ACC_ptrrSpiIfServices_SpiIf_writeSpiData_ACC_runMainFunction
 *     ARCH_SW_ACC_ptrrSpiIfServices_SpiIf_spiReadIBFromChannel_ACC_runMainFunction
 **/
LOCAL void acc_ReadAlarmRegisters(void)
{
   switch (acc_u8AccReadAlarmsSM)
   {
      case KU8_ACC_READ_ACCEL_ALARM_0_REG:
      {
         /* send a request to read Accelerometer Alarm 0 Register */
         acc_u16RegisterDataTransmit = KU16_ZERO;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_ACCELEROMETER_ALARM_0_BK_0,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_ACCELEROMETER_ALARM_0_BK_0,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_GetRegDataResponseFromSpiIB((uint16 *)&acc_u16AccelAlarm_0_DataReceive, &acc_kstSpiInitChannelSeqeunce.kstSpiChannel);

         acc_u8AccReadAlarmsSM++;
         break;
      }
      case KU8_ACC_READ_ACCEL_ALARM_1_REG:
      {
         /* send a request to read Accelerometer Alarm 1 Register */
         acc_u16RegisterDataTransmit = KU16_ZERO;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_ACCELEROMETER_ALARM_1_BK_0,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_ACCELEROMETER_ALARM_1_BK_0,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_GetRegDataResponseFromSpiIB((uint16 *)&acc_u16AccelAlarm_1_DataReceive, &acc_kstSpiInitChannelSeqeunce.kstSpiChannel);

         acc_u8AccReadAlarmsSM++;
         break;
      }
      case KU8_ACC_READ_OTHER_ALARM_0_REG:
      {
         /* send a request to read Other Alarms 0 Register */
         acc_u16RegisterDataTransmit = KU16_ZERO;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_OTHER_ALARMS_0_BK_0,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_OTHER_ALARMS_0_BK_0,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_GetRegDataResponseFromSpiIB((uint16 *)&acc_u16OtherAlarms_0_DataReceive, &acc_kstSpiInitChannelSeqeunce.kstSpiChannel);

         acc_u8AccReadAlarmsSM++;
         break;
      }
      case KU8_ACC_READ_OTHER_ALARM_1_REG:
      {
         /* send a request to read Other Alarms 1 Register */
         acc_u16RegisterDataTransmit = KU16_ZERO;
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_OTHER_ALARMS_1_BK_0,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_OTHER_ALARMS_1_BK_0,
                                             (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiInitChannelSeqeunce);
         acc_GetRegDataResponseFromSpiIB((uint16 *)&acc_u16OtherAlarms_1_DataReceive, &acc_kstSpiInitChannelSeqeunce.kstSpiChannel);

         acc_u8AccReadAlarmsSM++;
         break;
      }
      case KU8_ACC_EXTRACT_USEFUL_DATA_FROM_ALARM_REGISTERS:
      {
         /* Map useful bits from alarm registers in a uint32 variable.
         To understand the mapping method, see the table in the comment on initializing this variable. */
         ACC_u32AlarmRegistersUsefulData |= ((uint32)(acc_u16AccelAlarm_0_DataReceive & KU16_ACC_ACCEL_ALARM_0_GR1_USED_BITS_MASK) << KU8_EIGHTEEN)
                                         | ((uint32)(acc_u16AccelAlarm_0_DataReceive & KU16_ACC_ACCEL_ALARM_0_GR2_USED_BITS_MASK) << KU8_TWENTYEIGHT)
                                         | ((uint32)(acc_u16AccelAlarm_1_DataReceive & KU16_ACC_ACCEL_ALARM_1_USED_BITS_MASK) << KU8_TWENTYFIVE)
                                         | ((uint32)(acc_u16OtherAlarms_0_DataReceive & KU16_ACC_OTHER_ALARMS_0_USED_BITS_MASK) << KU8_ELEVEN)
                                         | ((uint32)(acc_u16OtherAlarms_1_DataReceive & KU16_ACC_OTHER_ALARMS_1_GR1_USED_BITS_MASK) >> KU8_THREE)
                                         | ((uint32)(acc_u16OtherAlarms_1_DataReceive & KU16_ACC_OTHER_ALARMS_1_GR2_USED_BITS_MASK) >> KU8_ONE);

         acc_u8AccReadAlarmsSM = KU8_ZERO;
         break;
      }
      default:
      {
         break;
      }
   }
}

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

/**
 * \brief
 *     Function used to initialize and read 3 axis of acceleration from TDK Accelerometer.
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     OS trough RTE layer.
 * \dynamicaspectdescription
 *     Called on OsTask_Alv_eCS_App Rte task via direct call.
 * \ddesignrequirement
 *     DSG_ACC_runMainFunction
 * \archrequirement
 *     ARCH_SW_ACC_ptrpAsrOsServices_ACC_runMainFunction;
 *     ARCH_SW_ACC_psrAccStatusFailiureSource_u32AccAlarmRegStatus;
 *     ARCH_SW_ACC_psrAccStatusFailiureSource_u8AccReturnStatus;
 *     ARCH_SW_ACC_psrAccStatusFailiureSource_u8AccCRCStatus;
 *     ARCH_SW_ACC_psrAccStatusFailiureSource_u8AccAlarmbPreinitSeqStatus;
 *     ARCH_SW_ACC_psrAccStatusFailiureSource_u8AccelAxisBroken;
 *     ARCH_SW_ACC_psrACCServices;
 *     ARCH_SW_ACC_ptrrSpiIfServices_SpiIf_writeSpiData_ACC_runMainFunction;
 *     ARCH_SW_ACC_ptrrSpiIfServices_SpiIf_spiReadIBFromChannel_ACC_runMainFunction;
 *     ARCH_SW_SpiIf_ptrrAsrSpiServices_Spi_SyncTransmit_SpiIf_spiSyncTransmitSequence;
 *     ARCH_SW_ACC_psr3DAcceleration;
 *     ARCH_SW_ACC_pclDioIfServices;
 *     ARCH_SW_ACC_psrAccelMtrPerSecSqd;
 **/
EXPORTED void ACC_runMainFunction(void)
{
   if (KU8_ACC_INIT_WAIT_READY >= acc_u8AccInitSM)
   {
      acc_Init();
   }
   else
   {
      acc_ReadData();
   }

   /* send Crc error flag and Return Status error flag to be transmitted on the measurement frame*/
   (void)Rte_Write_psrAccStatusFailiureSource_u8AccAlarmbPreinitSeqStatus((uint8)ACC_bAlarmbPreinitSeqFlag);
   (void)Rte_Write_psrAccStatusFailiureSource_u8AccelAxisBroken(((uint8)ACC_bAccelXaxisBrokenFlag << KU8_TWO) | ((uint8)ACC_bAccelYaxisBrokenFlag << KU8_ONE) | (uint8)ACC_bAccelZaxisBrokenFlag);
   (void)Rte_Write_psrAccStatusFailiureSource_u32AccAlarmRegStatus(ACC_u32AlarmRegistersUsefulData);
   (void)Rte_Write_psrAccStatusFailiureSource_u8AccReturnStatus((uint8)ACC_bReturnStatusErrorFlag);
   (void)Rte_Write_psrAccStatusFailiureSource_u8AccCRCStatus((uint8)ACC_bReadCrcErrorFlag);

   (void)Rte_Write_psrACCServices_u8AccInitStateMachine(acc_u8AccInitSM);
}

/**
 * \brief
 *     Function used to reset the accelerometer Init state machine counter when ECU restore from sleep mode.
 *     The initialization sequence must be sent again because in sleep mode the TDK accelerometer chip is turned off.
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     LPM trough RTE layer.
 * \dynamicaspectdescription
 *     Called on LPM_sleepRestore function via RTE call.
 * \ddesignrequirement
 *     DSG_ACC_restartInitialization
 * \archrequirement
 *     ARCH_SW_ACC_pseAccRestartInit
 **/
EXPORTED void ACC_RestartInitialization(void)
{
   /* Reinit acc init state */
   acc_u8AccInitSM = KU8_ZERO;
}

#define ACC_STOP_SEC_CODE_ASIL_A
#include "ACC_MemMap.h"

#define ACC_START_SEC_CODE
#include "ACC_MemMap.h"

/**
 * \brief
 *     Function used to read the value of temperature from Accelerometer internal temperature sensor.
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     OS trough RTE layer.
 * \dynamicaspectdescription
 *     Called on OsTask_Alv_Wdg_Refresh Rte task via direct call.
 * \ddesignrequirement
 *     DSG_ACC_ReadAccelerometerTemperature
 * \archrequirement
 *     ARCH_SW_ACC_ptrpAsrOsServices_ReadAccelerometerTemperature;
 *     ARCH_SW_ACC_ptrrSpiIfServices_SpiIf_writeSpiData_ACC_ReadAccelerometerTemperature;
 *     ARCH_SW_ACC_ptrrSpiIfServices_SpiIf_spiReadIBFromChannel_ACC_ReadAccelerometerTemperature;
 **/
EXPORTED void ACC_ReadAccelerometerTemperature(void)
{
   if (acc_u8AccInitSM >= KU8_ACC_INIT_WAIT_READY)
   {
      /* send a request to read Temperature Data 1 Register */
      acc_u16RegisterDataTransmit = KU16_ZERO;
      acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_TEMPERATURE_1_DATA,
                                           (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiReadTemperatureChannelSeqeunce);
      acc_SendCommandToReadOrWriteRegister(KU8_ACC_READ_REGISTER_FLAG, KU8_ACC_REG_TEMPERATURE_1_DATA,
                                           (uint16 const *)&acc_u16RegisterDataTransmit, &acc_kstSpiReadTemperatureChannelSeqeunce);
      acc_GetRegDataResponseFromSpiIB((uint16 *)&acc_u16TemperatureDataRegDataReceive, &acc_kstSpiReadTemperatureChannelSeqeunce.kstSpiChannel);
   }
}

/**
 * \brief
 *     Function used to get the value of temperature from Accelerometer internal temperature sensor.
 *     The value is read in function Acc_ReadAccelerometerTemperature.
 * \outputparam
 *     Name: pu16Temperature;
 *     Type: uint16 *;
 *     Description: Raw temperature data, read from accelerometer.;
 *     Range: 0..KU16_MAX;
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     IoHwAb module.
 * \dynamicaspectdescription
 *     Called in IoHwAb_GetAccelerometerTemperature function through an RTE call.
 * \ddesignrequirement
 *     DSG_ACC_GetAccelerometerTemperature
 * \archrequirement
 *     ARCH_SW_ACC_pseAccTemperatureSpiData
 **/
EXPORTED void ACC_GetAccelerometerTemperature(uint16 *pu16Temperature)
{
   *pu16Temperature = acc_u16TemperatureDataRegDataReceive;
}

/**
 * \brief
 *     External interrupt function of port E on pin PTE11.
 *     Used to check if the start-up sequence on ALARMB pin is corectly executed.
 * \return
 *     NA.
 * \dynamicaspectcaller
 *     Exernal intrrupt.
 * \dynamicaspectdescription
 *     Called at the rising or falling edge of ALARMB pin.
 * \ddesignrequirement
 *     DSG_PORTE_ISR
 * \archrequirement
 *     ARCH_SW_ACC_ptrpAsrOsServicesACC_PORTE_ISR
 **/
ISR(PORTE_ISR)
{
   uint32 u32AccTimerTimeElapsedMicrosX10;
   uint16 u16AccTimerTimeElapsedTiks;

   /* Disable interrupt flag */
   PORTE->ISFR = KU16_MAX;

   switch (acc_u8AlarmbIsrCallCounter)
   {
      /* rising edge t = 0 ms */
      case KU8_ACC_ALARMB_SEQ_BEGIN_SM:
      {
         Gpt_StartTimer(GPT_ACC_TIMER, KU16_MAX);

         /* enable ALARMB pin external interrupt on falling edge */
         PORTE->PCR[KU8_ELEVEN] = (PORTE->PCR[KU8_ELEVEN] & (~PORT_PCR_IRQC_MASK)) | (KU8_ACC_PORTE_INTERRUPT_FALLING_EDGE << PORT_PCR_IRQC_SHIFT);
         break;
      }
      /* falling edge t = 10.8 ms */
      case KU8_ACC_ALARMB_SEQ_STEP1_SM:
      {
         u16AccTimerTimeElapsedTiks = Gpt_GetTimeElapsed(GPT_ACC_TIMER);
         /* Timmer frequency = 625000 => Timmer Period = 1.6us*/
         /* TimeMicrosX10 = 16 * Tiks */
         u32AccTimerTimeElapsedMicrosX10 = (uint32)u16AccTimerTimeElapsedTiks * KU32_SIXTEEN;

         /* check if time is between 10.3ms and 11.3ms (FUSA_SM_ACC_DS-000342_IAM-20685_130)*/
         if ((KU32_ACC_ALARMB_FALLING_EDGE_MIN_TIME > u32AccTimerTimeElapsedMicrosX10) || (KU32_ACC_ALARMB_FALLING_EDGE_MAX_TIME < u32AccTimerTimeElapsedMicrosX10))
         {
            ACC_bAlarmbPreinitSeqFlag = KB_TRUE;
         }

         /* enable ALARMB pin external interrupt on rising edge */
         PORTE->PCR[KU8_ELEVEN] = (PORTE->PCR[KU8_ELEVEN] & (~PORT_PCR_IRQC_MASK)) | (KU8_ACC_PORTE_INTERRUPT_RISING_EDGE << PORT_PCR_IRQC_SHIFT);
         break;
      }
      /* rising edge t = 79.4 ms */
      case KU8_ACC_ALARMB_SEQ_STEP2_SM:
      {
         u16AccTimerTimeElapsedTiks = Gpt_GetTimeElapsed(GPT_ACC_TIMER);
         /* Timmer frequency = 625000 => Timmer Period = 1.6us*/
         /* TimeMicrosX10 = 16 * Tiks */
         u32AccTimerTimeElapsedMicrosX10 = (uint32)u16AccTimerTimeElapsedTiks * KU32_SIXTEEN;

         /* check if time is between 75.6ms and 83.2ms (FUSA_SM_ACC_DS-000342_IAM-20685_131)*/
         if ((KU32_ACC_ALARMB_RISING_EDGE_MIN_TIME > u32AccTimerTimeElapsedMicrosX10) || (KU32_ACC_ALARMB_RISING_EDGE_MAX_TIME < u32AccTimerTimeElapsedMicrosX10))
         {
            ACC_bAlarmbPreinitSeqFlag = KB_TRUE;
         }

         /* disable ALARMB pin external interrupt */
         PORTE->PCR[KU8_ELEVEN] = (PORTE->PCR[KU8_ELEVEN] & (~PORT_PCR_IRQC_MASK)) | (KU8_ACC_PORTE_INTERRUPT_DISABLE << PORT_PCR_IRQC_SHIFT);
         
         acc_bPreinitSeqAlarmbWasChecked = KB_TRUE;
         
         break;
      }
      default:
      {
         ACC_bAlarmbPreinitSeqFlag = KB_TRUE;
         break;
      }
   }
   acc_u8AlarmbIsrCallCounter++;
}

#define ACC_STOP_SEC_CODE
#include "ACC_MemMap.h"

/******************************************************************************
End Of File
*****************************************************************************/
