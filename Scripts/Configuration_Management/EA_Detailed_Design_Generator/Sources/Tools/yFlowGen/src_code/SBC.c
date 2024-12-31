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
$Revision: 1.1 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Scripts/Configuration_Management/EA_Detailed_Design_Generator/Sources/Tools/yFlowGen/src_code/project.pj $
*/
/*!****************************************************************************

@details
   High level module for controlling the SBC chip. In charge of:
      - Initialization
      - Shutdown
      - Cyclic monitor and WD refresh
      - Sleep
      - Normal mode
      - Low Power
      - Reset
******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "SBC.h"
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
/*! \union SBC_stSpiCommandType_Struct SBC.c "inc/SBC.c"
 *  \brief
 *     This structure contains the address and data of an SBC register
 *     to send on a Spi command.
 */
typedef struct SBC_stSpiCommandType_Struct
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
} SBC_stSpiCommandType_Struct;

/*! \union SBC_stSpiResponseType_Struct SBC.c "inc/SBC.c"
 *  \brief
 *     This structure contains the status information
 *     and data of an SBC register.
 */
typedef struct SBC_stSpiResponseType_Struct
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
} SBC_stSpiResponseType_Struct;
/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
LOCAL void sbc_DetermineSBCErrors(uint8 const u8Register);
LOCAL void sbc_ClearStateAndReport(void);

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
/**
 * \brief
 *       SBC status information.
 * \initialization
 *       ZERO.
 * \range
 *       0..255.
 */
LOCAL uint8 sbc_u8StatusInformationSBC = KU8_ZERO;
/**
 * \brief
 *       SBC watchdog software Counter.
 * \initialization
 *       ZERO.
 * \range
 *       0..255.
 */
LOCAL uint8 sbc_u8CounterBaseRefreshWD = KU8_ZERO;
/**
 * \brief
 *       Data read from GPIO_OL_STAT register.
 * \initialization
 *       ZERO.
 * \range
 *       0..255.
 */
LOCAL uint8 sbc_u8GpioOlStatRegData = KU8_ZERO;
/**
 * \brief
 *       Data read from GPIO_OC_STAT register.
 * \initialization
 *       ZERO.
 * \range
 *       0..255.
 */
LOCAL uint8 sbc_u8GpioOcStatRegData = KU8_ZERO;
/**
 * \brief
 *       Data read from SUP_STAT_1 register.
 * \initialization
 *       ZERO.
 * \range
 *       0..255.
 */
LOCAL uint8 sbc_u8SupStat1RegData = KU8_ZERO;
/**
 * \brief
 *       Data read from BUS_STAT_0 register.
 * \initialization
 *       ZERO.
 * \range
 *       0..255.
 */
LOCAL uint8 sbc_u8BusStat0RegData = KU8_ZERO;
/**
 * \brief
 *       Data read from DEV_STAT register.
 * \initialization
 *       ZERO.
 * \range
 *       0..255.
 */
LOCAL uint8 sbc_u8DevStatRegData = KU8_ZERO;
/**
 * \brief
 *       Data read from THERM_STAT register.
 * \initialization
 *       ZERO.
 * \range
 *       0..255.
 */
LOCAL uint8 sbc_u8ThermStatRegData = KU8_ZERO;
/**
 * \brief
 *       Data read from SUP_STAT_0 register.
 * \initialization
 *       ZERO.
 * \range
 *       0..255.
 */
LOCAL uint8 sbc_u8SupStat0RegData = KU8_ZERO;

/**
 * \brief
 *       SBC Response for all commands.
 * \initialization
 *       {ZERO, ZERO}.
 * \range
 *       N/A.
 */
LOCAL SBC_stSpiResponseType sbc_stSPIResponse = {KU8_ZERO, KU8_ZERO};
/**
 * \brief
 *       SBC command for all registers.
 * \initialization
 *       {ZERO, ZERO}.
 * \range
 *       N/A.
 */
LOCAL SBC_stSpiCommandType sbc_stSPICommand = {KU8_ZERO, KU8_ZERO};
/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
/**
 * \brief
 *      SBC Status Information used in SBC autotest.
 * \initialization
 *      KU8_ZERO.
 */
EXPORTED uint8 SBC_u8StatusInfoForAutotest = KU8_ZERO;

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
/**
 * \brief
 *       Struct with SBC Watchdog Spi Channel and Spi Sequence
 */
LOCAL const SpiIf_stSpiChannelSequenceType SBC_kstSpiClearStateChannelSequence = {SpiConf_SpiChannel_Sbc_CLEAR_STATE_Ch, SpiConf_SpiSequence_Sbc_CLEAR_STATE_Seq};

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
/**
 * \brief
 *     Function used to determine and Check errors of SBC chip.
 * \inputparam
 *     Name: u8Register;
 *     Type: uint8 const;
 *     Description: SPI data received from SBC.;
 *     Range: N/A;
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     SBC module.
 * \dynamicaspectdescription
 *     Called locally in sbc_ClearStateAndReport function.
 * \ddesignrequirement
 *     DSG_sbc_DetermineSBCErrors
 **/
LOCAL void sbc_DetermineSBCErrors(uint8 const u8Register)
{
   switch (u8Register)
   {
      case (KU8_SBC_ID_SUP_STAT_1): 
      {
         if (KU8_SBC_STATUS_VS_UV == (sbc_stSPIResponse.u8StatusInfo & KU8_SBC_STATUS_VS_UV))
         {
            sbc_u8StatusInformationSBC |= KU8_SBC_MASK_VS_UNDER_VOLTAGE;
         }
         break;
      }
      case (KU8_SBC_ID_WK_STAT_0):
      {
         if (KU8_SBC_STATUS_CAN_WU == (sbc_stSPIResponse.u8StatusInfo & KU8_SBC_STATUS_CAN_WU))
         {
            sbc_u8StatusInformationSBC |= KU8_SBC_MASK_CAN_WU;
         }
         break;
      }
      case (KU8_SBC_ID_DEV_STAT):
      {
         if (KU8_SBC_STATUS_WD_FAIL_1x == (sbc_stSPIResponse.u8StatusInfo & KU8_SBC_STATUS_WD_FAIL_1x))
         {
            sbc_u8StatusInformationSBC |= KU8_SBC_MASK_WATCHDOG_FAILURE;
         }
         break;
      }
      case (KU8_SBC_ID_SUP_STAT_0):
      {
         if (KU8_SBC_STATUS_POR == (sbc_stSPIResponse.u8StatusInfo & KU8_SBC_STATUS_POR))
         {
            sbc_u8StatusInformationSBC |= KU8_SBC_MASK_POWER_ON_RESET;
         }
         if (KU8_SBC_STATUS_VCC1_UV == (sbc_stSPIResponse.u8StatusInfo & KU8_SBC_STATUS_VCC1_UV))
         {
            sbc_u8StatusInformationSBC |= KU8_SBC_MASK_VCC1_UNDER_VOLTAGE;
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
 *     Clear the informations register and check errors of SBC chip.
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     SBC module.
 * \dynamicaspectdescription
 *     Called locally in SBC_runMainFunction function.
 * \ddesignrequirement
 *     DSG_sbc_ClearStateAndReport
 **/
LOCAL void sbc_ClearStateAndReport(void)
{
   if (KU8_SBC_MASK_GPIO_OL == (KU8_SBC_MASK_GPIO_OL & sbc_stSPIResponse.u8StatusInfo))
   {
      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_GPIO_OL_STAT;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
      SpiIf_spiReadIBFromChannel(SBC_kstSpiClearStateChannelSequence.kstSpiChannel, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      sbc_u8GpioOlStatRegData = sbc_stSPIResponse.u8RegData;
   }

   if (KU8_SBC_MASK_GPIO_OC == (KU8_SBC_MASK_GPIO_OC & sbc_stSPIResponse.u8StatusInfo))
   {
      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_GPIO_OC_STAT;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
      SpiIf_spiReadIBFromChannel(SBC_kstSpiClearStateChannelSequence.kstSpiChannel, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      sbc_u8GpioOcStatRegData = sbc_stSPIResponse.u8RegData;
   }

   if (KU8_SBC_MASK_SUP_STAT_1 == (KU8_SBC_MASK_SUP_STAT_1 & sbc_stSPIResponse.u8StatusInfo))
   {
      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_SUP_STAT_1;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
      SpiIf_spiReadIBFromChannel(SBC_kstSpiClearStateChannelSequence.kstSpiChannel, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      sbc_u8SupStat1RegData = sbc_stSPIResponse.u8RegData;
      sbc_DetermineSBCErrors(KU8_SBC_ID_SUP_STAT_0);
   }

   if (KU8_SBC_MASK_WK_STAT == (KU8_SBC_MASK_WK_STAT & sbc_stSPIResponse.u8StatusInfo))
   {
      /* Treatment WK_STAT_0 register */
      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_WK_STAT_0;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
      SpiIf_spiReadIBFromChannel(SBC_kstSpiClearStateChannelSequence.kstSpiChannel, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      sbc_DetermineSBCErrors(KU8_SBC_ID_WK_STAT_0);

      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_WK_STAT_1;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
   }

   if (KU8_SBC_MASK_BUS_STAT == (KU8_SBC_MASK_BUS_STAT & sbc_stSPIResponse.u8StatusInfo))
   {
      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_BUS_STAT;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
      SpiIf_spiReadIBFromChannel(SBC_kstSpiClearStateChannelSequence.kstSpiChannel, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      sbc_u8BusStat0RegData = sbc_stSPIResponse.u8RegData;
   }

   if (KU8_SBC_MASK_DEV_STAT == (KU8_SBC_MASK_DEV_STAT & sbc_stSPIResponse.u8StatusInfo))
   {
      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_DEV_STAT;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
      SpiIf_spiReadIBFromChannel(SBC_kstSpiClearStateChannelSequence.kstSpiChannel, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      sbc_u8DevStatRegData = sbc_stSPIResponse.u8RegData;
      sbc_DetermineSBCErrors(KU8_SBC_ID_DEV_STAT);
   }

   if (KU8_SBC_MASK_THERM_STAT == (KU8_SBC_MASK_THERM_STAT & sbc_stSPIResponse.u8StatusInfo))
   {
      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_THERMAL_STAT;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
      SpiIf_spiReadIBFromChannel(SBC_kstSpiClearStateChannelSequence.kstSpiChannel, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      sbc_u8ThermStatRegData = sbc_stSPIResponse.u8RegData;
   }

   if (KU8_SBC_MASK_SUP_STAT_0 == (KU8_SBC_MASK_SUP_STAT_0 & sbc_stSPIResponse.u8StatusInfo))
   {
      sbc_stSPICommand.u8RegAddr = KU8_SBC_READ_CLEAR_REG_COMMAND_TYPE | KU8_SBC_REG_SUP_STAT_0;
      sbc_stSPICommand.u8RegData = KU8_ZERO;
      SpiIf_writeSpiData(SBC_kstSpiClearStateChannelSequence, (Spi_DataBufferType const *)&sbc_stSPICommand.u8RegAddr);
      SpiIf_spiReadIBFromChannel(SBC_kstSpiClearStateChannelSequence.kstSpiChannel, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
      sbc_u8SupStat0RegData = sbc_stSPIResponse.u8RegData;
      sbc_DetermineSBCErrors(KU8_SBC_ID_SUP_STAT_0);
   }
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
 *     ARCH_SW_SBC_ptrpSbcServicesEcuM_SBC_Init
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiSyncTransmitSequence_SBC_Init
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiReadIBFromChannel_SBC_Init
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_writeSpiData_SBC_Init
 **/
EXPORTED void SBC_Init(void)
{
   sbc_u8CounterBaseRefreshWD = KU8_ZERO;

   SpiIf_spiSyncTransmitSequence(SpiConf_SpiSequence_Sbc_WDG_Seq);
   SpiIf_spiReadIBFromChannel(SpiConf_SpiChannel_Sbc_WDG_Ch, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);
   if (KU8_SBC_NO_RESET_CAUSE != sbc_stSPIResponse.u8StatusInfo)
   {
      sbc_ClearStateAndReport();
   }

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
 *     ARCH_SW_SBC_ptrpAsrOsServices
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiSyncTransmitSequence_SBC_runMainFunction
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiReadIBFromChannel_SBC_runMainFunction
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_writeSpiData_SBC_runMainFunction
 **/
EXPORTED void SBC_runMainFunction(void)
{
   if (KU8_SBC_MAX_COUNTER_REFRESH_WD < sbc_u8CounterBaseRefreshWD)
   {
      sbc_u8CounterBaseRefreshWD = KU8_ZERO;

      SpiIf_spiSyncTransmitSequence(SpiConf_SpiSequence_Sbc_WDG_Seq);
      SpiIf_spiReadIBFromChannel(SpiConf_SpiChannel_Sbc_WDG_Ch, (Spi_DataBufferType *)&sbc_stSPIResponse.u8StatusInfo);

      SBC_u8StatusInfoForAutotest = SBC_u8StatusInfoForAutotest | (sbc_stSPIResponse.u8StatusInfo & KU8_SBC_STATUS_INFO_MASK_FOR_AUTOTEST);

      if (KU8_SBC_NO_RESET_CAUSE != sbc_stSPIResponse.u8StatusInfo)
      {
         sbc_ClearStateAndReport();
      }
   }
   else
   {
      sbc_u8CounterBaseRefreshWD++;
   }
}

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
 *     ARCH_SW_SBC_pseSbcStatus_SBC_Shutdown
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiSyncTransmitSequence_SBC_Shutdown
 **/
EXPORTED void SBC_Shutdown(void)
{
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
 *     ARCH_SW_SBC_pseSbcServicesLpm_SBC_sleepTriggerWatchdog
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiSyncTransmitSequence_SBC_sleepTriggerWatchdog
 **/
EXPORTED void SBC_sleepTriggerWatchdog(void)
{
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
 *     ARCH_SW_SBC_pseSbcServicesLpm_SBC_SetToNormal
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiSyncTransmitSequence_SBC_SetToNormal
 **/
EXPORTED void SBC_SetToNormal(void)
{
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
 *     ARCH_SW_SBC_pseSbcServicesLpm_SBC_SetToLowPower
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiSyncTransmitSequence_SBC_SetToLowPower
 **/
EXPORTED void SBC_SetToLowPower(void)
{
   SpiIf_spiSyncTransmitSequence(SpiConf_SpiSequence_Sbc_SET_LOW_POWER_Seq);
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
 *     ARCH_SW_SBC_pseSbcStatus_SBC_Reset
 *     ARCH_SW_SBC_ptrrSpiIfServices_SpiIf_spiSyncTransmitSequence_SBC_Reset
 **/
EXPORTED void SBC_Reset(void)
{
   SpiIf_spiSyncTransmitSequence(SpiConf_SpiSequence_Sbc_RESET_Seq);
}

/**
 * \brief
 *     Function used to get the status of SBC chip.
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
EXPORTED void SBC_GetSBCStatusInformation(uint8 *u8StatusInformation)
{
   *u8StatusInformation = sbc_u8StatusInformationSBC;
}

/**
 * \brief
 *     Function used to trigger a reset caused by improper watchdog refreshing.
 * \return
 *     This function has no return.
 * \dynamicaspectcaller
 *     This function is not called.
 * \dynamicaspectdescription
 *     .
 * \ddesignrequirement
 *     DSG_SBC_ForceExternalWatchdogReset
 * \archrequirement
 * 
 **/
EXPORTED void SBC_ForceExternalWatchdogReset(void)
{
   SpiIf_spiSyncTransmitSequence(SpiConf_SpiSequence_Sbc_FORCE_WDG_RESET_Seq);
}
/******************************************************************************
End Of File
******************************************************************************/
