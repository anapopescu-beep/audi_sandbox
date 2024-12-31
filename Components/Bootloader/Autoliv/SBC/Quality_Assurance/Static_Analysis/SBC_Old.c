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
$Revision: 1.3.4.8 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader/Autoliv/SBC/Quality_Assurance/Static_Analysis/project.pj $
*/
/*!****************************************************************************

details
   High level module for controlling the SBC chip. In charge of:
      o Initialization;
      o Shutdown;
      o Cyclic monitor and WD refresh;
      o Sleep;
      o Normal mode;
      o Low Power;
      o Reset;
******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "SBC.h"
#include "Rte_SBC.h"
#include "SBC_cfg.h"
#include "SpiIf.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/

/* Definition of value reset cause in specific register */
/* SUP_STAT_1 */
/**
 * \brief
 *       VS Under-Voltage status value.
 */
#define KU8_SBC_STATUS_VS_UV                    ((uint8)0x40)
/* SUP_STAT_0 */
/**
 * \brief
 *       Power on Reset status value.
 */
#define KU8_SBC_STATUS_POR                      ((uint8)0x80)
/**
 * \brief
 *       VCC1 Under-Voltage status value.
 */
#define KU8_SBC_STATUS_VCC1_UV                  ((uint8)0x01)
/* DEV_STAT*/
/**
 * \brief
 *       1xWatchdog Fail status value.
 */
#define KU8_SBC_STATUS_WD_FAIL_1x               ((uint8)0x40)

/* WK_STAT_0*/
/**
 * \brief
 *       Can wake up status value.
 */
#define KU8_SBC_STATUS_CAN_WU                   ((uint8)0x20)

/* Mask for all individual status information provided by the SBC registers
 * Note: To be extended with any needed ones */
/**
 * \brief
 *       VCC1 Under-Voltage mask.
 */
#define KU8_SBC_MASK_VCC1_UNDER_VOLTAGE         ((uint8)0x02)
/**
 * \brief
 *       Watchdog Failure mask.
 */
#define KU8_SBC_MASK_WATCHDOG_FAILURE           ((uint8)0x01)
/**
 * \brief
 *       GPIO_OL mask.
 */
#define KU8_SBC_MASK_GPIO_OL                    ((uint8)0x80)
/**
 * \brief
 *       GPIO_OC mask.
 */
#define KU8_SBC_MASK_GPIO_OC                    ((uint8)0x40)
/**
 * \brief
 *       SUP_STAT_1 mask.
 */
#define KU8_SBC_MASK_SUP_STAT_1                 ((uint8)0x20)
/**
 * \brief
 *       WK_STAT mask.
 */
#define KU8_SBC_MASK_WK_STAT                    ((uint8)0x10)
/**
 * \brief
 *       BUS_STAT mask.
 */
#define KU8_SBC_MASK_BUS_STAT                   ((uint8)0x08)
/**
 * \brief
 *       DEV_STAT mask.
 */
#define KU8_SBC_MASK_DEV_STAT                   ((uint8)0x04)
/**
 * \brief
 *       THERM_STAT mask.
 */
#define KU8_SBC_MASK_THERM_STAT                 ((uint8)0x02)
/**
 * \brief
 *       SUP_STAT_0 mask.
 */
#define KU8_SBC_MASK_SUP_STAT_0                 ((uint8)0x01)
/**
 * \brief
 *       Status Information mask needed for autotest.
 */
#define KU8_SBC_STATUS_INFO_MASK_FOR_AUTOTEST   ((uint8)0xEF)

/* Definition of Switch bits */
/**
 * \brief
 *       No cause reset.
 */
#define KU8_SBC_NO_RESET_CAUSE                  ((uint8)0x00)

/* Specific definition of SBC chip */
/**
 * \brief
 *       Max counter to refresh external watchdog.
 */
#define KU8_SBC_MAX_COUNTER_REFRESH_WD          ((uint8)0x02)
/******************************************************************************
MODULE TYPES
******************************************************************************/
/*
 *  \brief
 *     This structure contains the address and data of an SBC register
 *     to send on a Spi command.
 */
typedef struct
{
   /**
    * \brief
    *    Address of register to write.
    */
   uint8 u8RegAddr;
   /**
    * \brief
    *    Data to write in the register.
    */
   uint8 u8RegData;
} SBC_stSpiCommandType;

/*
 *  \brief
 *     This structure contains the status information
 *     and data of an SBC register.
 */
typedef struct
{
   /**
    * \brief
    *    Status Information response from SBC.
    */
   uint8 u8StatusInfo;
   /**
    * \brief
    *    Data read from the register.
    */
   uint8 u8RegData;
} SBC_stSpiResponseType;
/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
LOCAL void sbc_ClearStateAndReport(void);

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#define SBC_START_SEC_VAR_INIT_8_ASIL_A
#include "SBC_MemMap.h"

/**
 * \brief
 *       SBC status information.
 * \initialization
 *       ZERO.
 * \range
 *       0..KU8_MAX.
 */
LOCAL uint8 sbc_u8StatusInformationSBC = KU8_ZERO;
/**
 * \brief
 *       SBC watchdog software Counter.
 * \initialization
 *       ZERO.
 * \range
 *       0..KU8_MAX.
 */
LOCAL uint8 sbc_u8CounterBaseRefreshWD = KU8_ZERO;
/**
 * \brief
 *       Data read from GPIO_OL_STAT register.
 * \initialization
 *       ZERO.
 * \range
 *       0..KU8_MAX.
 */
/* +-------------------------+ */
/* | GPIO_OL_STAT register   | */
/* |---------------+---------+ */
/* | Name          | REG Bit | */
/* |---------------+---------+ */
/* | GPIO_OL       |     6   | */
/* +---------------+---------+ */
LOCAL uint8 sbc_u8GpioOlStatRegData = KU8_ZERO;
/**
 * \brief
 *       Data read from GPIO_OC_STAT register.
 * \initialization
 *       ZERO.
 * \range
 *       0..KU8_MAX.
 */
/* +-------------------------+ */
/* | GPIO_OC_STAT register   | */
/* |---------------+---------+ */
/* | Name          | REG Bit | */
/* |---------------+---------+ */
/* | GPIO_OC       |     6   | */
/* +---------------+---------+ */
LOCAL uint8 sbc_u8GpioOcStatRegData = KU8_ZERO;
/**
 * \brief
 *       Data read from SUP_STAT_1 register.
 * \initialization
 *       ZERO.
 * \range
 *       0..KU8_MAX.
 */
/* +-------------------------+ */
/* |  SUP_STAT_1 REGISETER   | */
/* |---------------+---------+ */
/* | Name          | REG Bit | */
/* |---------------+---------+ */
/* | VS_UV         |     6   | */
/* | VS_OV         |     5   | */
/* | VCC1_OV       |     1   | */
/* | VCC1_WARN     |     0   | */
/* +---------------+---------+ */
LOCAL uint8 sbc_u8SupStat1RegData = KU8_ZERO;
/**
 * \brief
 *       Data read from BUS_STAT_0 register.
 * \initialization
 *       ZERO.
 * \range
 *       0..KU8_MAX.
 */
/* +-------------------------+ */
/* |  BUS_STAT REGISETER     | */
/* |---------------+---------+ */
/* | Name          | REG Bit | */
/* |---------------+---------+ */
/* | CANTO         |     4   | */
/* | SYSERR        |     3   | */
/* | CAN_FAIL bit1 |     2   | */
/* | CAN_FAIL bit0 |     1   | */
/* | VCAN_UV       |     0   | */
/* +---------------+---------+ */
LOCAL uint8 sbc_u8BusStatRegData = KU8_ZERO;
/**
 * \brief
 *       Data read from DEV_STAT register.
 * \initialization
 *       ZERO.
 * \range
 *       0..KU8_MAX.
 */
/* +-------------------------+ */
/* |  DEV_STAT REGISETER     | */
/* |---------------+---------+ */
/* | Name          | REG Bit | */
/* |---------------+---------+ */
/* | DEV_STAT bit1 |     7   | */
/* | DEV_STAT bit0 |     6   | */
/* | WD_FAIL bit1  |     3   | */
/* | WD_FAIL bit0  |     2   | */
/* | SPI_FAIL      |     1   | */
/* | FAILURE       |     0   | */
/* +---------------+---------+ */
LOCAL uint8 sbc_u8DevStatRegData = KU8_ZERO;
/**
 * \brief
 *       Data read from THERM_STAT register.
 * \initialization
 *       ZERO.
 * \range
 *       0..KU8_MAX.
 */
/* +-------------------------+ */
/* |  THERM_STAT REGISETER   | */
/* |---------------+---------+ */
/* | Name          | REG Bit | */
/* |---------------+---------+ */
/* | TSD2_SAFE     |     3   | */
/* | TSD2          |     2   | */
/* | TSD1          |     1   | */
/* | TPW           |     0   | */
/* +---------------+---------+ */
LOCAL uint8 sbc_u8ThermStatRegData = KU8_ZERO;
/**
 * \brief
 *       Data read from SUP_STAT_0 register.
 * \initialization
 *       ZERO.
 * \range
 *       0..KU8_MAX.
 */
/* +-------------------------+ */
/* |  SUP_STAT_0 REGISETER   | */
/* |---------------+---------+ */
/* | Name          | REG Bit | */
/* |---------------+---------+ */
/* | POR           |     7   | */
/* | VCC2_OT       |     4   | */
/* | VCC2_UV       |     3   | */
/* | VCC1_SC       |     2   | */
/* | VCC1_UV       |     0   | */
/* +---------------+---------+ */
LOCAL uint8 sbc_u8SupStat0RegData = KU8_ZERO;
/**
 * \brief
 *       Data read from WK_STAT_0 register.
 * \initialization
 *       ZERO.
 * \range
 *       0..KU8_MAX.
 */
/* +-------------------------+ */
/* |  WK_STAT_0 REGISETER    | */
/* |---------------+---------+ */
/* | Name          | REG Bit | */
/* |---------------+---------+ */
/* | CAN_WU        |     5   | */
/* | TIMER_WU      |     4   | */
/* | WK_WU         |     0   | */
/* +---------------+---------+ */
LOCAL uint8 sbc_u8WkStat0RegData = KU8_ZERO;
/**
 * \brief
 *       Data read from WK_STAT_1 register.
 * \initialization
 *       ZERO.
 * \range
 *       0..KU8_MAX.
 */
/* +-------------------------+ */
/* |  WK_STAT_1 REGISETER    | */
/* |---------------+---------+ */
/* | Name          | REG Bit | */
/* |---------------+---------+ */
/* | GPIO_WK_WU    |     4   | */
/* +---------------+---------+ */
LOCAL uint8 sbc_u8WkStat1RegData = KU8_ZERO;

#define SBC_STOP_SEC_VAR_INIT_8_ASIL_A
#include "SBC_MemMap.h"

#define SBC_START_SEC_VAR_INIT_32_ASIL_A
#include "SBC_MemMap.h"

/**
 * \brief
 *      A variable with all useful bits from Status registers, which is transmitted on the measurement frame.
 * \initialization
 *      ZERO.
 * \range
 *      NA.
 */
/* +------------------------------------------------------+ */
/* |  The maping method of bits from Status Registers     | */
/* |------+-----+---------------+---------+---------------| */
/* | Byte | Bit | Name          | REG Bit | Register Name | */
/* |------+-----+---------------+---------+---------------| */
/* |      |  31 | NA            |    NA   |               | */
/* |      |  30 | NA            |    NA   |               | */
/* |      +-----+---------------+---------+---------------+ */
/* |      |  29 | VS_UV         |     6   |               | */
/* |   1  |  28 | VS_OV         |     5   |               | */
/* |      |  27 | VCC1_OV       |     1   | SUP_STAT_1    | */
/* |      |  26 | VCC1_WARN     |     0   |               | */
/* |      +-----+---------------+---------+---------------+ */
/* |      |  25 | POR           |     7   |               | */
/* |______|  24 | VCC2_OT       |     4   |               | */
/* |      |  23 | VCC2_UV       |     3   | SUP_STAT_0    | */
/* |      |  22 | VCC1_SC       |     2   |               | */
/* |      |  21 | VCC1_UV       |     0   |               | */
/* |      +-----+---------------+---------+---------------+ */
/* |   2  |  20 | TSD2_SAFE     |     3   |               | */
/* |      |  19 | TSD2          |     2   |               | */
/* |      |  18 | TSD1          |     1   | THERM_STAT    | */
/* |      |  17 | TPW           |     0   |               | */
/* |      +-----+---------------+---------+---------------+ */
/* |______|  16 | DEV_STAT bit1 |     7   |               | */
/* |      |  15 | DEV_STAT bit0 |     6   |               | */
/* |      |  14 | WD_FAIL bit1  |     3   |               | */
/* |      |  13 | WD_FAIL bit0  |     2   | DEV_STAT      | */
/* |   3  |  12 | SPI_FAIL      |     1   |               | */
/* |      |  11 | FAILURE       |     0   |               | */
/* |      +-----+---------------+---------+---------------+ */
/* |      |  10 | CANTO         |     4   |               | */
/* |      |   9 | SYSERR        |     3   |               | */
/* |______|   8 | CAN_FAIL bit1 |     2   | BUS_STAT      | */
/* |      |   7 | CAN_FAIL bit0 |     1   |               | */
/* |      |   6 | VCAN_UV       |     0   |               | */
/* |      +-----+---------------+---------+---------------+ */
/* |      |   5 | CAN_WU        |     5   |               | */
/* |   4  |   4 | TIMER_WU      |     4   | WK_STAT_0     | */
/* |      |   3 | WK_WU         |     0   |               | */
/* |      +-----+---------------+---------+---------------+ */
/* |      |   2 | GPIO_WK_WU    |     4   | WK_STAT_1     | */
/* |      +-----+---------------+---------+---------------+ */
/* |      |   1 | GPIO_OC       |     6   | GPIO_OC_STAT  | */
/* |      +-----+---------------+---------+---------------+ */
/* |      |   0 | GPIO_OL       |     6   | GPIO_OL_STAT  | */
/* +------+-----+---------------+---------+---------------+ */
LOCAL uint32 sbc_u32StatusRegistersUsefulData = KU32_ZERO;

#define SBC_STOP_SEC_VAR_INIT_32_ASIL_A
#include "SBC_MemMap.h"

#define SBC_START_SEC_VAR_INIT_UNSPECIFIED_ASIL_A
#include "SBC_MemMap.h"

/**
 * \brief
 *       SBC Response for all commands.
 * \initialization
 *       {ZERO, ZERO}.
 * \range
 *       NA.
 */
LOCAL SBC_stSpiResponseType sbc_stSPIResponse = {KU8_ZERO, KU8_ZERO};
/**
 * \brief
 *       SBC command for all registers.
 * \initialization
 *       {ZERO, ZERO}.
 * \range
 *       NA.
 */
LOCAL SBC_stSpiCommandType sbc_stSPICommand = {KU8_ZERO, KU8_ZERO};

#define SBC_STOP_SEC_VAR_INIT_UNSPECIFIED_ASIL_A
#include "SBC_MemMap.h"

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
#define SBC_START_SEC_VAR_INIT_8_ASIL_A
#include "SBC_MemMap.h"

/**
 * \brief
 *      SBC Status Information used in SBC autotest.
 * \initialization
 *      KU8_ZERO.
 * \range
 *       NA.
 */
EXPORTED uint8 SBC_u8StatusInfoForAutotest = KU8_ZERO;

#define SBC_STOP_SEC_VAR_INIT_8_ASIL_A
#include "SBC_MemMap.h"

#define SBC_START_SEC_VAR_POWER_ON_CLEARED
#include "SBC_MemMap.h"

/**
 * \brief
 *      SBC Wdg status used in SBC Wdg autotest.
 * \initialization
 *      No initialization.
 * \range
 *      KU8_SBC_WDG_TEST_INIT
 *      KU8_SBC_WDG_TEST_STARTED
 *      KU8_SBC_WDG_TEST_DECISION_PENDING;
 */
EXPORTED uint8 SBC_u8WdgStatusForAutotest;

#define SBC_STOP_SEC_VAR_POWER_ON_CLEARED
#include "SBC_MemMap.h"
/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
#define SBC_START_SEC_CONST_UNSPECIFIED_ASIL_A
#include "SBC_MemMap.h"

/**
 * \brief
 *       Struct with SBC Watchdog Spi Channel and Spi Sequence.
 * \initialization
 *       NA.
 * \range
 *       NA.
 */
LOCAL const SpiIf_stSpiChannelSequenceType SBC_kstSpiClearStateChannelSequence = {SpiConf_SpiChannel_Sbc_CLEAR_STATE_Ch, SpiConf_SpiSequence_Sbc_CLEAR_STATE_Seq};

#define SBC_STOP_SEC_CONST_UNSPECIFIED_ASIL_A
#include "SBC_MemMap.h"

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/

#define SBC_START_SEC_CODE
#include "SBC_MemMap.h"
/**
 * \brief
 *     Function used to put the SBC in shutdown mode.
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     EcuMIf Module
 * \dynamicaspectdescription
 *     Called in EcuM_AL_SwitchOff function via direct call.
 * \ddesignrequirement
 *     DSG_SBC_Shutdown
 * \archrequirement
 *     ARCH_SW_SBC_pseSbcStatus_SBC_Shutdown;
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiSyncTransmitSequence_SBC_Shutdown;
 **/
EXPORTED void SBC_Shutdown(void)
{
   /* Necessary check & clear the informations wake registers ie : see datasheet TLE9461-ES */
   /* SpiConf_SpiSequence_Sbc_SHUTDOWN_Seq contain the following channels:
      - Sbc_SD_WK_STAT_0_Ch      -> 0x00c6 (  198);  (clear the wake register 0)
      - Sbc_SD_WK_STAT_1_Ch      -> 0x00c7 (  199);  (clear the wake register 1)
      - Sbc_SD_BUS_CTRL_0_Ch     -> 0x0184 (  388);  (Set CAN mode to Wake capable)
      - Sbc_SD_M_S_CTRL_Ch       -> 0x4181 (16769);  (set control register M_S_CTRL to Sleep mode)
      The format of data in tresos: [(1 byte registerData), (1 byte registerAddress)]
   */
   SpiIf_spiSyncTransmitSequence(SpiConf_SpiSequence_Sbc_SHUTDOWN_Seq);
}

/**
 * \brief
 *     Function used to trigger watchdog when the ECU is in sleep mode.
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     LPM module.
 * \dynamicaspectdescription
 *     Called in LPM_sleepInit and LPM_sleepMainLoop functions via direct call.
 * \ddesignrequirement
 *     DSG_SBC_sleepTriggerWatchdog
 * \archrequirement
 *     ARCH_SW_SBC_pseSbcServicesLpm_SBC_sleepTriggerWatchdog;
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiSyncTransmitSequence_SBC_sleepTriggerWatchdog;
 **/
EXPORTED void SBC_sleepTriggerWatchdog(void)
{
   /* Refresh external watchdog */
   /* SpiConf_SpiSequence_Sbc_WDG_Seq contain the following channels:
      - Sbc_WDG_Ch               -> 0x9583 (38275); (watchdog refresh)
      The format of data in tresos: [(1 byte registerData), (1 byte registerAddress)]
   */
   SpiIf_spiSyncTransmitSequence(SpiConf_SpiSequence_Sbc_WDG_Seq);
}

/**
 * \brief
 *     Function used to put the SBC in Normal Mode.
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     LPM module.
 * \dynamicaspectdescription
 *     Called in LPM_sleepRestore function via direct call.
 * \ddesignrequirement
 *     DSG_SBC_SetToNormal
 * \archrequirement
 *     ARCH_SW_SBC_pseSbcServicesLpm_SBC_SetToNormal;
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiSyncTransmitSequence_SBC_SetToNormal;
 **/
EXPORTED void SBC_SetToNormal(void)
{
   /* SpiConf_SpiSequence_Sbc_SET_NORMAL_Seq contain the following channels:
      - Sbc_STN_M_S_CTRL_Ch      -> 0x0881 (2177);  (set control register M_S_CTRL to Normal mode)
      - Sbc_STN_M_S_CTRL_Ch      -> 0x0881 (2177);  (enable VCC2)
      - Sbc_STN_BUS_CTRL_0_Ch    -> 0x0384 ( 900);  (set control register BUS_CTRL_0)
      The format of data in tresos: [(1 byte registerData), (1 byte registerAddress)]
   */
   SpiIf_spiSyncTransmitSequence(SpiConf_SpiSequence_Sbc_SET_NORMAL_Seq);
}

/**
 * \brief
 *     Function used to put the SBC in Low Power Mode.
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     LPM module.
 * \dynamicaspectdescription
 *     Called in LPM_sleepInit function via direct call.
 * \ddesignrequirement
 *     DSG_SBC_SetToLowPower
 * \archrequirement
 *     ARCH_SW_SBC_pseSbcServicesLpm_SBC_SetToLowPower;
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiSyncTransmitSequence_SBC_SetToLowPower;
 **/
EXPORTED void SBC_SetToLowPower(void)
{
   /* SpiConf_SpiSequence_Sbc_SET_LOW_POWER_Seq contain the following channels:
      - Sbc_STLP_BUS_CTRL_0_Ch   -> 0x0184 (  388);  (Set CAN mode to Wake capable)
      - Sbc_STLP_HW_CTRL_2_Ch    -> 0x508f (20623);  (Set Ivcc active threshold 2)
      - Sbc_STLP_M_S_CTRL_Ch     -> 0x8181 (33153);  (set control register M_S_CTRL to Stop mode)
      The format of data in tresos: [(1 byte registerData), (1 byte registerAddress)]
   */
   SpiIf_spiSyncTransmitSequence(SpiConf_SpiSequence_Sbc_SET_LOW_POWER_Seq);
}

#define SBC_STOP_SEC_CODE
#include "SBC_MemMap.h"

#define SBC_START_SEC_CODE_ASIL_A
#include "SBC_MemMap.h"
/**
 * \brief
 *     Clear the informations register and check errors of SBC chip.
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     SBC module.
 * \dynamicaspectdescription
 *     Called locally in SBC_runMainFunction function.
 * \ddesignrequirement
 *     DSG_sbc_ClearStateAndReport
 * \archrequirement
 *     ARCH_SW_SBC_ptrpSbcServicesEcuM_SBC_Init;
 *     ARCH_SW_SBC_ptrpAsrOsServices;
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiReadIBFromChannel_SBC_Init;
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_writeSpiData_SBC_Init;
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiReadIBFromChannel_SBC_runMainFunction;
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_writeSpiData_SBC_runMainFunction;
 **/
/*************************************************************************
Errors check :
-------------------------------------------------------------------------------------
| Error         |  Register                |  Read/Write/read&clear| Data           |
-------------------------------------------------------------------------------------
| see DATASHEET | KU8_REG_GPIOOL_STAT      |   1 (Read&Clear)      |  KU16_DEFAULT  |
| see DATASHEET | KU8_REG_GPIOOC_STAT      |   1 (Read&Clear)      |  KU16_DEFAULT  |
| see DATASHEET | KU8_REG_SUP_STAT_1       |   1 (Read&Clear)      |  KU16_DEFAULT  |
| see DATASHEET | KU8_REG_WK_STAT_0        |   1 (Read&Clear)      |  KU16_DEFAULT  |
| see DATASHEET | KU8_REG_WK_STAT_1        |   1 (Read&Clear)      |  KU16_DEFAULT  |
| see DATASHEET | KU8_REG_BUS_STAT         |   1 (Read&Clear)      |  KU16_DEFAULT  |
| see DATASHEET | KU8_REG_DEV_STAT         |   1 (Read&Clear)      |  KU16_DEFAULT  |
| see DATASHEET | KU8_REG_THERMAL_STAT     |   1 (Read&Clear)      |  KU16_DEFAULT  |
| see DATASHEET | KU8_REG_SUP_STAT_0       |   1 (Read&Clear)      |  KU16_DEFAULT  |
-------------------------------------------------------------------------------------
**************************************************************************************/
LOCAL void sbc_ClearStateAndReport(void)
{
   /* Read & clear GPIO_OL_STAT register if necessary */
   if (KU8_SBC_MASK_GPIO_OL == (KU8_SBC_MASK_GPIO_OL & sbc_stSPIResponse.u8StatusInfo))
   {
      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_GPIO_OL_STAT;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
      SpiIf_spiReadIBFromChannel(SBC_kstSpiClearStateChannelSequence.kstSpiChannel, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      sbc_u8GpioOlStatRegData = sbc_stSPIResponse.u8RegData;
   }

   /* Read & clear GPIO_OC_STAT register if necessary */
   if (KU8_SBC_MASK_GPIO_OC == (KU8_SBC_MASK_GPIO_OC & sbc_stSPIResponse.u8StatusInfo))
   {
      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_GPIO_OC_STAT;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
      SpiIf_spiReadIBFromChannel(SBC_kstSpiClearStateChannelSequence.kstSpiChannel, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      sbc_u8GpioOcStatRegData = sbc_stSPIResponse.u8RegData;
   }

   /* Read & clear SUP_STAT_1 register if necessary */
   if (KU8_SBC_MASK_SUP_STAT_1 == (KU8_SBC_MASK_SUP_STAT_1 & sbc_stSPIResponse.u8StatusInfo))
   {
      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_SUP_STAT_1;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
      SpiIf_spiReadIBFromChannel(SBC_kstSpiClearStateChannelSequence.kstSpiChannel, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      sbc_u8SupStat1RegData = sbc_stSPIResponse.u8RegData;
   }

   /* Read & clear WK_STAT_0 and 1 register if necessary */
   if (KU8_SBC_MASK_WK_STAT == (KU8_SBC_MASK_WK_STAT & sbc_stSPIResponse.u8StatusInfo))
   {
      /* Treatment WK_STAT_0 register */
      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_WK_STAT_0;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
      SpiIf_spiReadIBFromChannel(SBC_kstSpiClearStateChannelSequence.kstSpiChannel, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      sbc_u8WkStat0RegData = sbc_stSPIResponse.u8RegData;

      /* Treatment WK_STAT_1 register */
      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_WK_STAT_1;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
      SpiIf_spiReadIBFromChannel(SBC_kstSpiClearStateChannelSequence.kstSpiChannel, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      sbc_u8WkStat1RegData = sbc_stSPIResponse.u8RegData;
   }

   /* Read & clear BUS_STAT_0 register if necessary */
   if (KU8_SBC_MASK_BUS_STAT == (KU8_SBC_MASK_BUS_STAT & sbc_stSPIResponse.u8StatusInfo))
   {
      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_BUS_STAT;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
      SpiIf_spiReadIBFromChannel(SBC_kstSpiClearStateChannelSequence.kstSpiChannel, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      sbc_u8BusStatRegData = sbc_stSPIResponse.u8RegData;
   }

   /* Read & clear DEV_STAT register if necessary */
   if (KU8_SBC_MASK_DEV_STAT == (KU8_SBC_MASK_DEV_STAT & sbc_stSPIResponse.u8StatusInfo))
   {
      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_DEV_STAT;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
      SpiIf_spiReadIBFromChannel(SBC_kstSpiClearStateChannelSequence.kstSpiChannel, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      sbc_u8DevStatRegData = sbc_stSPIResponse.u8RegData;
   }

   /* Read & clear THERM_STAT register if necessary */
   if (KU8_SBC_MASK_THERM_STAT == (KU8_SBC_MASK_THERM_STAT & sbc_stSPIResponse.u8StatusInfo))
   {
      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_THERMAL_STAT;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
      SpiIf_spiReadIBFromChannel(SBC_kstSpiClearStateChannelSequence.kstSpiChannel, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      sbc_u8ThermStatRegData = sbc_stSPIResponse.u8RegData;
   }

   /* Read & clear SUP_STAT_0 register if necessary */
   if (KU8_SBC_MASK_SUP_STAT_0 == (KU8_SBC_MASK_SUP_STAT_0 & sbc_stSPIResponse.u8StatusInfo))
   {
      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_SUP_STAT_0;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
      SpiIf_spiReadIBFromChannel(SBC_kstSpiClearStateChannelSequence.kstSpiChannel, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      sbc_u8SupStat0RegData = sbc_stSPIResponse.u8RegData;
   }

   /* Map useful bits from Status Registers in a uint32 variable.
   To understand the mapping method, see the table in the comment on initializing this variable. */
   sbc_u32StatusRegistersUsefulData |= (((uint32)sbc_u8SupStat1RegData & KU8_SBC_SUP_STAT_1_GR1_USED_BITS_MASK) << KU8_TWENTYTHREE)
                                    | (((uint32)sbc_u8SupStat1RegData & KU8_SBC_SUP_STAT_1_GR2_USED_BITS_MASK) << KU8_TWENTYSIX)
                                    | (((uint32)sbc_u8SupStat0RegData & KU8_SBC_SUP_STAT_0_GR1_USED_BITS_MASK) << KU8_EIGHTEEN)
                                    | (((uint32)sbc_u8SupStat0RegData & KU8_SBC_SUP_STAT_0_GR2_USED_BITS_MASK) << KU8_TWENTY)
                                    | (((uint32)sbc_u8SupStat0RegData & KU8_SBC_SUP_STAT_0_GR3_USED_BITS_MASK) << KU8_TWENTYONE)
                                    | (((uint32)sbc_u8ThermStatRegData & KU8_SBC_THERM_STAT_USED_BITS_MASK) << KU8_SEVENTEEN)
                                    | (((uint32)sbc_u8DevStatRegData & KU8_SBC_DEV_STAT_GR1_USED_BITS_MASK) << KU8_NINE)
                                    | (((uint32)sbc_u8DevStatRegData & KU8_SBC_DEV_STAT_GR2_USED_BITS_MASK) << KU8_ELEVEN)
                                    | (((uint32)sbc_u8BusStatRegData & KU8_SBC_BUS_STAT_USED_BITS_MASK) << KU8_SIX)
                                    | ((uint32)sbc_u8WkStat0RegData & KU8_SBC_WK_STAT_0_GR1_USED_BITS_MASK)
                                    | (((uint32)sbc_u8WkStat0RegData & KU8_SBC_WK_STAT_0_GR2_USED_BITS_MASK) << KU8_THREE)
                                    | (((uint32)sbc_u8WkStat1RegData & KU8_SBC_WK_STAT_1_USED_BITS_MASK) >> KU8_TWO)
                                    | (((uint32)sbc_u8GpioOcStatRegData & KU8_SBC_GPIO_OC_STAT_USED_BITS_MASK) >> KU8_FIVE)
                                    | (((uint32)sbc_u8GpioOlStatRegData & KU8_SBC_GPIO_OL_STAT_USED_BITS_MASK) >> KU8_SIX);
                                 
   Rte_Write_psrSbcStatusFailiureSource_u32SbcReg1Status(sbc_u32StatusRegistersUsefulData);
}
/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

/**
 * \brief
 *     Initialization function of module SBC.
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     EcuMIf Module.
 * \dynamicaspectdescription
 *     Called EcuM_DefaultInitListOne function via direct call.
 * \ddesignrequirement
 *     DSG_SBC_Init
 * \archrequirement
 *     ARCH_SW_SBC_ptrpSbcServicesEcuM_SBC_Init;
 *     ARCH_SW_SBC_psrSbcStatusFailiureSource_SBC_Init;
 *     ARCH_SW_SBC_pclResetCauseNotification_SBC_Init;
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiSyncTransmitSequence_SBC_Init;
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiReadIBFromChannel_SBC_Init;
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_writeSpiData_SBC_Init;
 **/
EXPORTED void SBC_Init(void)
{
   sbc_u8CounterBaseRefreshWD = KU8_ZERO;

   if(KU8_SBC_WDG_TEST_INIT == SBC_u8WdgStatusForAutotest)
   {
      SpiIf_spiSyncTransmitSequence(SpiConf_SpiSequence_Sbc_WDG_Autotest_Seq);
      SpiIf_spiReadIBFromChannel(SpiConf_SpiChannel_Sbc_Wdg_Autotest_Ch, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      SBC_u8WdgStatusForAutotest = KU8_SBC_WDG_TEST_STARTED;
   }
   else
   {
      /* Refresh external Watchdog first  : ie see datasheet TLE9461-3ES */
      SpiIf_spiSyncTransmitSequence(SpiConf_SpiSequence_Sbc_WDG_Seq);
      SpiIf_spiReadIBFromChannel(SpiConf_SpiChannel_Sbc_WDG_Ch, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      if(KU8_SBC_WDG_TEST_STARTED == SBC_u8WdgStatusForAutotest)
      {
         SBC_u8WdgStatusForAutotest = KU8_SBC_WDG_TEST_DECISION_PENDING;
         Rte_Call_pclResetCauseNotification_NotifyResetCause(KU32_SW_WDG_TEST_NOTIFICATION);
      }
   }

   if (KU8_SBC_NO_RESET_CAUSE != sbc_stSPIResponse.u8StatusInfo)
   {
      sbc_ClearStateAndReport();
   }

   /* SpiConf_SpiSequence_Sbc_INIT_Seq contain the following channels:
      - Sbc_INIT_GPIO_CTRL_Ch    -> 0x0497 ( 1175);
      - Sbc_INIT_WK_CTRL_1_Ch    -> 0x0087 (  135);
      - Sbc_INIT_HW_CTRL_2_Ch    -> 0x008f (  143);
      - Sbc_INIT_HW_CTRL_1_Ch    -> 0x008e (  142);
      - Sbc_INIT_HW_CTRL_0_Ch    -> 0x0082 (  130);
      - Sbc_INIT_BUS_CTRL_0_Ch   -> 0x0384 (  900);
      - Sbc_INIT_WK_CTRL_0_Ch    -> 0x0086 (  134);
      - Sbc_INIT_TIMER_CTRL_Ch   -> 0x008c (  140);
      - Sbc_INIT_PWM_CTRL_Ch     -> 0x0098 (  152);
      - Sbc_INIT_SBC_NORMAL_Ch   -> 0x0881 ( 2177);
      The format of data in tresos: [(1 byte registerData), (1 byte registerAddress)]
   */
   SpiIf_spiSyncTransmitSequence(SpiConf_SpiSequence_Sbc_INIT_Seq);
}

/**
 * \brief
 *     Main function of SBC module.
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     Rte module.
 * \dynamicaspectdescription
 *     Called in OsTask_Alv_Wdg_Refresh Rte Task via direct call.
 * \ddesignrequirement
 *     DSG_SBC_runMainFunction
 * \archrequirement
 *     ARCH_SW_SBC_ptrpAsrOsServices;
 *     ARCH_SW_SBC_psrSbcStatusFailiureSource_SBC_runMainFunction;
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiSyncTransmitSequence_SBC_runMainFunction;
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiReadIBFromChannel_SBC_runMainFunction;
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_writeSpiData_SBC_runMainFunction;
 **/
/*************************************************************************
Main sequence :
--------------------------------------------------------------------------
Register      |  Read/Write/read&clear | Data                             |
--------------------------------------------------------------------------
WD_CTRL       |  1 (Write)             |  KU8_CONF_WD_CTRL_REG            |
--------------------------------------------------------------------------
**************************************************************************/
EXPORTED void SBC_runMainFunction(void)
{
   /* Refresh watchdog for 4 call because this function
      is included in task called to 10 ms  ie : watchdog opened window between 36 to 60 */
   if (KU8_SBC_MAX_COUNTER_REFRESH_WD < sbc_u8CounterBaseRefreshWD)
   {
      /* Reset counter watchdog to refresh it */
      sbc_u8CounterBaseRefreshWD = KU8_ZERO;

      /* Refresh external watchdog */
      /* SpiConf_SpiSequence_Sbc_WDG_Seq contain the following channels:
         - Sbc_WDG_Ch               -> 0x9583 (38275); (watchdog refresh)
         The format of data in tresos: [(1 byte registerData), (1 byte registerAddress)]
      */
      SpiIf_spiSyncTransmitSequence(SpiConf_SpiSequence_Sbc_WDG_Seq);
      SpiIf_spiReadIBFromChannel(SpiConf_SpiChannel_Sbc_WDG_Ch, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);

      /* stores the Status Information needed for autotest,
      ignore the bit asociated with WK_STAT_0 and WK_STAT_1 registers. */
      SBC_u8StatusInfoForAutotest = SBC_u8StatusInfoForAutotest | (sbc_stSPIResponse.u8StatusInfo & KU8_SBC_STATUS_INFO_MASK_FOR_AUTOTEST);

      if (KU8_SBC_NO_RESET_CAUSE != sbc_stSPIResponse.u8StatusInfo)
      {
         sbc_ClearStateAndReport();
      }
   }
   else
   {
      /* Increment counter watchdog */
      sbc_u8CounterBaseRefreshWD++;
   }
}


/**
 * \brief
 *     Function used to reset the SBC.
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     EcuMIF module.
 * \dynamicaspectdescription
 *     Called in EcuM_AL_Reset via direct call.
 * \ddesignrequirement
 *     DSG_SBC_Reset
 * \archrequirement
 *     ARCH_SW_SBC_pseSbcStatus_SBC_Reset;
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiSyncTransmitSequence_SBC_Reset;
 **/
EXPORTED void SBC_Reset(void)
{
   /* SpiConf_SpiSequence_Sbc_RESET_Seq contain the following channels:
      - Sbc_RST_M_S_CTRL_Ch   -> 0xc181 (49537);  (set control register M_S_CTRL to Reset)
      The format of data in tresos: [(1 byte registerData), (1 byte registerAddress)]
   */
   SpiIf_spiSyncTransmitSequence(SpiConf_SpiSequence_Sbc_RESET_Seq);
}

/**
 * \brief
 *     Function used to get the status of SBC chip.
 * \inputparam
 *     Name: u32StatusInformation;
 *     Type: uint32 *;
 *     Description: SBC Status Information data;
 *     Range: NA.;
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     RCM Module.
 * \dynamicaspectdescription
 *     Called in RCM_runDetermineResetCause function via RTE call.
 * \ddesignrequirement
 *     DSG_SBC_GetSBCStatusInformation
 * \archrequirement
 *     ARCH_SW_SBC_pseSbcStatus_SBC_GetSBCStatusInformation
 **/
EXPORTED void SBC_GetSBCStatusInformation(uint32 *u32StatusInformation)
{
   *u32StatusInformation = sbc_u32StatusRegistersUsefulData;
}

#define SBC_STOP_SEC_CODE_ASIL_A
#include "SBC_MemMap.h"
/******************************************************************************
End Of File
******************************************************************************/
