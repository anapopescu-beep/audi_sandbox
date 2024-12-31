
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
$Revision: 1.13 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/McuIf/Implementation/src/project.pj $
 */
/*****************************************************************************

details
   The modules handles the interface with the Mcu

 ******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "McuIf.h"
#include "Rte_McuIf.h"
#include "m4_scst_test_shell.h"
#include "Common.h"
#include "Reg_eSys.h"
#include "Crc.h"
/******************************************************************************
MODULE DEFINES
 ******************************************************************************/
/**
 * \brief
 *       Macro used to indicate the number of steps
 *       that the MCU self test has
 */
#define  KU8_MCUIF_MCU_SELF_TEST_STEPS	((uint8)11u)

/**
 * \brief
 *       Macro used to indicate the start value of CRC32
 */
#define KU32_MCUIF_CRC32_START_VALUE	((uint32)KU32_MAX)

/**
 * \brief
 *       Macro used to indicate the length of the CRC input data
 */
#define KU8_MCUIF_CRC32_INIT_LEN		((uint8) 0x04)

/**
 * \brief
 *    Macro used to define the FTM Status and Control register mask
 */
#define KU8_MCUIF_SC_REG_MASK		((uint8) 0x00)

/**
 * \brief
 *    Macro used to define the FTM Status And Control Channel 0 register mask
 */
#define KU8_MCUIF_C0SC_REG_MASK		((uint8) 0x0C)

/**
 * \brief
 *    Macro used to define the FTM Status And Control Channel 1 register mask
 */
#define KU8_MCUIF_C1SC_REG_MASK		((uint8) 0x14)

/**
 * \brief
 *    Macro used to define the FTM Status And Control Channel 2 register mask
 */
#define KU8_MCUIF_C2SC_REG_MASK		((uint8) 0x1C)

/**
 * \brief
 *    Macro used to define the FTM Status And Control Channel 3 register mask
 */
#define KU8_MCUIF_C3SC_REG_MASK		((uint8) 0x24)

/**
 * \brief
 *    Macro used to define the FTM Status And Control Channel 4 register mask
 */
#define KU8_MCUIF_C4SC_REG_MASK		((uint8) 0x2C)

/**
 * \brief
 *    Macro used to define the FTM Status And Control Channel 5 register mask
 */
#define KU8_MCUIF_C5SC_REG_MASK		((uint8) 0x34)

/**
 * \brief
 *    Macro used to define the FTM Status And Control Channel 6 register mask
 */
#define KU8_MCUIF_C6SC_REG_MASK		((uint8) 0x3C)

/**
 * \brief
 *    Macro used to define the FTM Status And Control Channel 7 register mask
 */
#define KU8_MCUIF_C7SC_REG_MASK		((uint8) 0x44)

/**
 * \brief
 *    Macro used to define the FTM External Trigger register mask
 */
#define KU8_MCUIF_EXTTRIG_REG_MASK	((uint8) 0x6C)

/**
 * \brief
 *    Macro used to define the bit mask for FTM Status And Control register
 */
#define KU32_MCUIF_SC_REG_BITSMASK 		((uint32) 0xFFFFFD7F)

/**
 * \brief
 *    Macro used to define the bit mask for FTM Status And Control Channel x
 *    register
 */
#define KU32_MCUIF_CxSC_REG_BITSMASK	((uint32) 0xFFFFF93F)

/**
 * \brief
 *    Macro used to define the bit mask for FTM External Trigger register
 */
#define KU32_MCUIF_EXTTRIG_REG_BITSMASK	((uint32) 0xFFFFFF7F)

/**
 * \brief
 *    Macro used to define the ADC Config 1 register mask
 */
#define KU8_MCUIF_ADC_CFG1_REG_MASK		((uint8) 0x40)

/**
 * \brief
 *    Macro used to define the ADC Config 2 register mask
 */
#define KU8_MCUIF_ADC_CFG2_REG_MASK		((uint8) 0x44)

/******************************************************************************
MODULE TYPES
 ******************************************************************************/
/**
 *  \brief
 *       This structure describes the constant data of a Mcu self test.
 */
typedef struct
{
   /**
    * \brief
    *    Value of the expected result.
    */
   uint32 u32ExpectedSignature;
   /**
    * \brief
    *    Number of start self test.
    */
   uint8 u8StartTest;
   /**
    * \brief
    *    Number of stop self test.
    */
   uint8 u8StopTest;
} mcuif_stMcuSelfTestConfigurationType;
/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
 ******************************************************************************/
LOCAL void mcuif_PortSwTestRegCrcInit(void);
LOCAL void mcuif_AdcSwTestRegCrcVerif(uint32 au32CrcDataOutput[]);
LOCAL void mcuif_FtmSwTestRegCrcInit(void);
LOCAL uint8 mcuif_AdcSwTestRegCrc(void);
LOCAL uint8 mcuif_PortSwTestRegCrc(void);
LOCAL uint8 mcuif_FtmSwTestRegCrc(void);
LOCAL void mcuif_CheckCrcOnAdcRegistersAutotest(u8TestResultType * pu8TestResult);
LOCAL void mcuif_CheckCrcOnFtmRegistersAutotest(u8TestResultType * pu8TestResult);
LOCAL void mcuif_CheckCrcOnPortRegistersAutotest(u8TestResultType * pu8TestResult);
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
 ******************************************************************************/
#define McuIf_START_SEC_VAR_NO_INIT_32_ASIL_A
#include "McuIf_MemMap.h"
/**
 * \brief
 *       This variable is used to store the CRC initial calculated value of every
 *       register from every FTM (SC, C0SC, C1SC, C2SC, C3SC, C4SC, C5SC, C6SC,
 *       C7SC, MODE, SYNC, EXTTRG, QDCTRL, CONF, FLTPOL, INVCTRL, PWMLOAD).
 * \initialization
 *       NA.
 * \range
 *       KU32_ZERO..KU32_MAX.
 */
LOCAL uint32 mcuif_u32FtmCrcInitDataOutput[KU8_FOUR][KU8_SEVENTEEN];

/**
 * \brief
 *       This variable is used to store the CRC initial calculated value of every
 *       register from every PORT (PORTA, PORTB, PORTC, PORTD, PORTE).
 * \initialization
 *       NA.
 * \range
 *       KU32_ZERO..KU32_MAX.
 */
LOCAL uint32 mcuif_u32PortCrcInitOutput[KU8_FIVE][KU8_THIRTYTWO];

#define McuIf_STOP_SEC_VAR_NO_INIT_32_ASIL_A
#include "McuIf_MemMap.h"

#define McuIf_START_SEC_VAR_INIT_32
#include "McuIf_MemMap.h"
/**
 * \brief
 *       This variable store the initialization value of calculated CRC.
 * \initialization
 *       KU32_MAX.
 * \range
 *       KU32_ZERO..KU32_MAX.
 */
LOCAL uint32 mcuif_u32TempCrcValue = KU32_MCUIF_CRC32_START_VALUE;
/**
 * \brief
 *       This variable is used to store the calculated CRC value
 *       of PORT register.
 * \initialization
 *       KU32_ZERO
 * \range
 *       KU32_ZERO..KU32_MAX.
 */
LOCAL uint32 mcuif_u32PortCrcRuntimeOutput[KU8_THIRTYTWO] =
{
      KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO,
      KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO,
      KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO,
      KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO
};


/**
 * \brief
 *       This variable is used to store the calculated CRC value
 *       of ADC register.
 * \initialization
 *       KU32_ZERO.
 * \range
 *       KU32_ZERO..KU32_MAX.
 */
LOCAL uint32 mcuif_u32AdcCrcRuntimeOutput[KU8_FOUR] = {KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO};

/**
 * \brief
 *       This variable is used to store the CRC initial calculated value of
 *       every register from every ADC (ADC0, ADC1).
 * \initialization
 *       KU32_ZERO.
 * \range
 *       KU32_ZERO..KU32_MAX.
 */
LOCAL uint32 mcuif_u32AdcCrcInitOutput[KU8_FOUR] = {KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO};

/**
 * \brief
 *       This variable is used to store the calculated CRC value
 *       of FTM register.
 * \initialization
 *       KU32_ZERO.
 * \range
 *       KU32_ZERO..KU32_MAX.
 */
LOCAL uint32 mcuif_u32FtmCrcRuntimeOutput[KU8_SEVENTEEN] =
{
      KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO,
      KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO, KU32_ZERO,
      KU32_ZERO
};

#define McuIf_STOP_SEC_VAR_INIT_32
#include "McuIf_MemMap.h"

#define McuIf_START_SEC_VAR_INIT_8_ASIL_A
#include "McuIf_MemMap.h"
/**
 * \brief
 *       This variable represents current tests to the executed.
 * \initialization.
 *       0.
 * \range
 *       0..10.
 */
LOCAL uint8 mcuif_u8McuSelfTestState = KU8_ZERO;

/**
 * \brief
 *       This variable represents current queue of calculated CRC on PORT
 *       registers.
 * \initialization
 *       0.
 * \range
 *       0..5.
 */
LOCAL uint8 mcuif_u8PortCrcCalcQueuePort = KU8_ZERO;
/**
 * \brief
 *       This variable represents current queue of calculated CRC on FTM
 *       registers.
 * \initialization
 *       0.
 * \range
 *       0..4.
 */
LOCAL uint8 mcuif_u8FtmCrcCalcQueuePort = KU8_ZERO;

#define McuIf_STOP_SEC_VAR_INIT_8_ASIL_A
#include "McuIf_MemMap.h"

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
 ******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
 ******************************************************************************/
#define McuIf_START_SEC_CONST_32_ASIL_A
#include "McuIf_MemMap.h"
/**
 * \brief
 *    This variable is used to store the masks of PORT registers
 */
#define PORTA_MULTIPLEX_BASEADDR 0
#define PORTB_MULTIPLEX_BASEADDR 0
#define PORTC_MULTIPLEX_BASEADDR 0
#define PORTD_MULTIPLEX_BASEADDR 0
#define PORTE_MULTIPLEX_BASEADDR 0

#define FTM_0_BASEADDR 0
#define FTM_1_BASEADDR 0
#define FTM_2_BASEADDR 0
#define FTM_3_BASEADDR 0

LOCAL const uint32 mcuif_ku32PortRegistersArray[KU8_FIVE] =
{
      PORTA_MULTIPLEX_BASEADDR,
      PORTB_MULTIPLEX_BASEADDR,
      PORTC_MULTIPLEX_BASEADDR,
      PORTD_MULTIPLEX_BASEADDR,
      PORTE_MULTIPLEX_BASEADDR
};

/**
 * \brief
 *    This variable is used to store the masks of FTM registers
 */
LOCAL const uint32 mcuif_ku32FlexTimerRegistersArray[KU8_FOUR] =
{
      FTM_0_BASEADDR,
      FTM_1_BASEADDR,
      FTM_2_BASEADDR,
      FTM_3_BASEADDR
};
#define McuIf_STOP_SEC_CONST_32_ASIL_A
#include "McuIf_MemMap.h"

#define McuIf_START_SEC_CONST_UNSPECIFIED_ASIL_A
#include "McuIf_MemMap.h"
/**
 * \brief
 *       This table constains the tests to run and the expected result
 */
LOCAL const mcuif_stMcuSelfTestConfigurationType mcuif_KastMcuSeftTestSchedule[KU8_MCUIF_MCU_SELF_TEST_STEPS]=
{
      {0xB78u, 0u, 8u},
      {0xC73EED29u, 9u, 16u},
      {0xB6E13BAFu, 17u, 19u},
      {0x941F1413u, 20u, 22u},
      {0xF61A1F74u, 23u, 23u},
      {0xCB8B5710u, 24u, 25u},
      {0xC7272625u, 26u, 30u},
      {0x92BEu, 31u, 32u},
      {0x8C65u, 33u, 33u},
      {0x64801EFCu, 34u, 37u},
      {0xE96FE77Au, 38u, 43u}
};
#define McuIf_STOP_SEC_CONST_UNSPECIFIED_ASIL_A
#include "McuIf_MemMap.h"

#define McuIf_START_SEC_CONST_8_ASIL_A
#include "McuIf_MemMap.h"
/**
 * \brief
 *       This variable contains all register masks for FTM registers
 */
LOCAL const uint8 ku8FtmConfigRegisterMasks[KU8_SEVENTEEN] =
{
      (uint8)0x00,	/*SC_REG_MASK*/
      (uint8)0x0C,	/*C0SC_REG_MASK*/
      (uint8)0x14,	/*C1SC_REG_MASK*/
      (uint8)0x1C,	/*C2SC_REG_MASK*/
      (uint8)0x24,	/*C3SC_REG_MASK*/
      (uint8)0x2C,	/*C4SC_REG_MASK*/
      (uint8)0x34,	/*C5SC_REG_MASK*/
      (uint8)0x3C,	/*C6SC_REG_MASK*/
      (uint8)0x44,	/*C7SC_REG_MASK*/
      (uint8)0x54,	/*MODE_REG_MASK*/
      (uint8)0x58,	/*SYNC_REG_MASK*/
      (uint8)0x6C,	/*EXTTRIG_REG_MASK*/
      (uint8)0x80,	/*QDCTRL_REG_MASK*/
      (uint8)0x84,	/*CONF_REG_MASK*/
      (uint8)0x88,	/*FLTPOL_REG_MASK*/
      (uint8)0x90,	/*INVCTRL_REG_MASK*/
      (uint8)0x98	/*PWMLOAD_REG_MASK*/
};

#define McuIf_STOP_SEC_CONST_8_ASIL_A
#include "McuIf_MemMap.h"
/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
 ******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
 ******************************************************************************/
/**
 * \brief
 *      Macros for reading from HW mapped registers:
 *        o module  - module base address;
 *        o reg     - register address within module;
 */
#define MCUIF_REG_READ32(module, reg)               	(*(volatile uint32*)(module+reg))
/******************************************************************************
DEFINITION OF LOCAL FUNCTION
 ******************************************************************************/
/**
 * \brief
 *       This function is used to calculate the CRC value of ADC registers right
 *       after initialization phase.
 * \outputparam
 *Name: au32CrcDataOutput;
 *       Type: uint32;
 *       Description: Output array where CRC result shall be saved;
 *       Range: KU32_ZERO..KU32_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       This function has no return.
 * \dynamicaspectcaller
 *       McuIf_runInit
 * \dynamicaspectdescription
 *       Called at startup after initialization phase.
 * \constrains
 *       This function has no constraints.
 * \ddesignrequirement
 *		  DSG_mcuif_AdcSwTestRegCrcInit
 * \archrequirement
 *       ARCH_SW_McuIf_ptrpMcuIfServicesBswmIf_McuIf_runInit
 *       ARCH_SW_McuIf_pseCheckCrcOnMcuRegisters_McuIf_CheckMcuCrcRegisterStatus
 **/
LOCAL void mcuif_AdcSwTestRegCrcVerif(uint32 au32CrcDataOutput[])
{
   uint32 u32AdcRegisterValueRead = KU32_ZERO;

   /* Read ADC register (starting with CFG1) */
//   u32AdcRegisterValueRead = MCUIF_REG_READ32(ADC0_BASEADDR,KU8_MCUIF_ADC_CFG1_REG_MASK);
   au32CrcDataOutput[KU8_ZERO] = Crc_CalculateCRC32((uint8 *)&u32AdcRegisterValueRead,KU8_MCUIF_CRC32_INIT_LEN,mcuif_u32TempCrcValue,TRUE);

   /* Read ADC register (starting with CFG2) */
//   u32AdcRegisterValueRead = MCUIF_REG_READ32(ADC0_BASEADDR,KU8_MCUIF_ADC_CFG2_REG_MASK);
   au32CrcDataOutput[KU8_ONE] = Crc_CalculateCRC32((uint8 *)&u32AdcRegisterValueRead,KU8_MCUIF_CRC32_INIT_LEN,mcuif_u32TempCrcValue,TRUE);

   /* Read ADC register (starting with CFG1) */
//   u32AdcRegisterValueRead = MCUIF_REG_READ32(ADC1_BASEADDR,KU8_MCUIF_ADC_CFG1_REG_MASK);
   au32CrcDataOutput[KU8_TWO] = Crc_CalculateCRC32((uint8 *)&u32AdcRegisterValueRead,KU8_MCUIF_CRC32_INIT_LEN,mcuif_u32TempCrcValue,TRUE);

   /* Read ADC register (starting with CFG2) */
//   u32AdcRegisterValueRead = MCUIF_REG_READ32(ADC1_BASEADDR,KU8_MCUIF_ADC_CFG2_REG_MASK);
   au32CrcDataOutput[KU8_THREE] = Crc_CalculateCRC32((uint8 *)&u32AdcRegisterValueRead,KU8_MCUIF_CRC32_INIT_LEN,mcuif_u32TempCrcValue,TRUE);
}

/**
 * \brief
 *       This function is used to calculate the CRC value of PORT registers right
 *       after initialization phase.
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       This function has no return.
 * \dynamicaspectcaller
 *       McuIf_runInit
 * \dynamicaspectdescription
 *       Called at startup after initialization phase.
 * \constrains
 *       This function has no constraints.
 * \ddesignrequirement
 *		DSG_mcuif_PortSwTestRegCrcInit
 * \archrequirement
 *       ARCH_SW_McuIf_ptrpMcuIfServicesBswmIf_McuIf_runInit
 *       ARCH_SW_McuIf_pseCheckCrcOnMcuRegisters_McuIf_CheckMcuCrcRegisterStatus
 **/
LOCAL void mcuif_PortSwTestRegCrcInit(void)
{
   uint32 u32PortRegisterValueRead = KU32_ZERO;
   uint8  u8CounterRegister = KU8_ZERO;
   uint8  u8PcrRegisterAddress = KU8_ZERO;
   uint8  u8CounterStatusRegister = KU8_ZERO;

   /* Parse every PORT register */
   for(u8CounterRegister = KU8_ZERO; u8CounterRegister < KU8_FIVE; u8CounterRegister++)
   {
      /* Calculate CRC for PCR registers */
      for(u8CounterStatusRegister = KU8_ZERO; u8CounterStatusRegister < KU8_THIRTYTWO; u8CounterStatusRegister++)
      {
         /* Read PCR register (starting with PCR0) */
         u32PortRegisterValueRead = MCUIF_REG_READ32(mcuif_ku32PortRegistersArray[u8CounterRegister],u8PcrRegisterAddress);

         /* Calculate CRC */
         mcuif_u32PortCrcInitOutput[u8CounterRegister][u8CounterStatusRegister] = Crc_CalculateCRC32
               (
                     (uint8 *)&u32PortRegisterValueRead,
                     KU8_MCUIF_CRC32_INIT_LEN,
                     mcuif_u32TempCrcValue,
                     TRUE
               );
         /* Mask PORTE PCR11 register (ACC modify it)*/
         if((KU8_FOUR == u8CounterRegister) && (KU8_ELEVEN == u8CounterStatusRegister))
         {
            mcuif_u32PortCrcInitOutput[u8CounterRegister][u8CounterStatusRegister] = KU32_ZERO;
         }

         /* Increment u8PcrRegisterAddress with 4 to go to the next PCR register at next iteration */
         u8PcrRegisterAddress += KU8_FOUR;
      }

      /* PORT Register CRC calculated, reset PCR register address to be able to parse the next PORT */
      u8PcrRegisterAddress = KU8_ZERO;
   }
}

/**
 * \brief
 *       This function is used to calculate the CRC value of FTM registers right
 *       after initialization phase.
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       This function has no return.
 * \dynamicaspectcaller
 *       McuIf_runInit
 * \dynamicaspectdescription
 *       Called at startup after initialization phase.
 * \constrains
 *       This function has no constraints.
 * \ddesignrequirement
 *		DSG_mcuif_FtmSwTestRegCrcInit
 * \archrequirement
 *       ARCH_SW_McuIf_ptrpMcuIfServicesBswmIf_McuIf_runInit
 **/
LOCAL void mcuif_FtmSwTestRegCrcInit(void)
{
   uint32	u32FlexTimerRegisterValueRead = KU32_ZERO;
   uint8	u8CounterRegister = KU8_ZERO;
   uint8	u8CounterStatusRegister = KU8_ZERO;

   /* Parse every FTM register */
   for(u8CounterRegister = KU8_ZERO; u8CounterRegister < KU8_FOUR; u8CounterRegister++)
   {
      /* Calculate CRC for PCR registers */
      for(u8CounterStatusRegister = KU8_ZERO; u8CounterStatusRegister < KU8_SEVENTEEN; u8CounterStatusRegister++)
      {
         /* Read FTMx register (starting with SC) */
         u32FlexTimerRegisterValueRead = MCUIF_REG_READ32
               (
                     mcuif_ku32FlexTimerRegistersArray[u8CounterRegister],
                     ku8FtmConfigRegisterMasks[u8CounterStatusRegister]
               );

         /* Apply mask for registers which contains flag bits*/
         switch(ku8FtmConfigRegisterMasks[u8CounterStatusRegister])
         {
         case KU8_MCUIF_SC_REG_MASK:
            /* Clear status on the next 2 bits:
             * Bit 9 (Timer Overflow Flag)
             * Bit 7 (Reload Bit) */
            u32FlexTimerRegisterValueRead &= KU32_MCUIF_SC_REG_BITSMASK;
            break;

         case KU8_MCUIF_C0SC_REG_MASK:
         case KU8_MCUIF_C1SC_REG_MASK:
         case KU8_MCUIF_C2SC_REG_MASK:
         case KU8_MCUIF_C3SC_REG_MASK:
         case KU8_MCUIF_C4SC_REG_MASK:
         case KU8_MCUIF_C5SC_REG_MASK:
         case KU8_MCUIF_C6SC_REG_MASK:
         case KU8_MCUIF_C7SC_REG_MASK:
            /* Clear status on the next 3 bits:
             * Bit 10 (Channel Output Value)
             * Bit 9 (Channel Input State)
             * Bit 7 (Channel Flag) */
            u32FlexTimerRegisterValueRead &= KU32_MCUIF_CxSC_REG_BITSMASK;
            break;
         case KU8_MCUIF_EXTTRIG_REG_MASK:
            /* Clear status on the next bit:
             * Bit 7 (Channel Trigger Flag)*/
            u32FlexTimerRegisterValueRead &= KU32_MCUIF_EXTTRIG_REG_BITSMASK;
            break;
         default:
            break;
         }

         /* Calculate CRC */
         mcuif_u32FtmCrcInitDataOutput[u8CounterRegister][u8CounterStatusRegister] = Crc_CalculateCRC32
               (
                     (uint8 *)&u32FlexTimerRegisterValueRead,
                     KU8_MCUIF_CRC32_INIT_LEN,
                     mcuif_u32TempCrcValue,
                     TRUE
               );
      }
   }
}

/**
 * \brief
 *       This function is used to calculate CRC on ADC registers.
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       This function return the status of the test.
 * \dynamicaspectcaller
 *       mcuif_CheckCrcOnPortRegistersAutotest
 * \dynamicaspectdescription
 *       Called cyclic at every 10ms to check ADC CFG registers.
 * \constrains
 *       This function has no constraints.
 * \ddesignrequirement
 *		  DSG_mcuif_AdcSwTestRegCrc
 * \archrequirement
 *       ARCH_SW_McuIf_pseCheckCrcOnMcuRegisters_McuIf_CheckMcuCrcRegisterStatus
 **/
LOCAL uint8 mcuif_AdcSwTestRegCrc(void)
{
   uint8 u8Counter = KU8_ZERO;
   uint8 u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   uint8 u8FailedCrcComp = KU8_FALSE;

   mcuif_AdcSwTestRegCrcVerif(&mcuif_u32AdcCrcRuntimeOutput[KU8_ZERO]);

   /* Verify if runtime and initial calculated CRC are the same */
   for(u8Counter = KU8_ZERO; u8Counter < KU8_FOUR; u8Counter++)
   {
      /* Stop CRC comparison if at least 1 comparison is NOK */
      if(KU8_TRUE != u8FailedCrcComp)
      {
         if(mcuif_u32AdcCrcRuntimeOutput[u8Counter] != mcuif_u32AdcCrcInitOutput[u8Counter])
         {
            u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
            u8FailedCrcComp = KU8_TRUE;
         }
         else
         {
            u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
      }
   }

   return u8ResultOfAutoTest;
}

/**
 * \brief
 *       This function is used to calculate CRC on PORT registers.
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       This function return the status of the test.
 * \dynamicaspectcaller
 *       mcuif_CheckCrcOnPortRegistersAutotest
 * \dynamicaspectdescription
 *       Called cyclic at every 10ms to check PORT PCR registers.
 * \constrains
 *       This function has no constraints.
 * \ddesignrequirement
 *		  DSG_mcuif_PortSwTestRegCrc
 * \archrequirement
 *       ARCH_SW_McuIf_pseCheckCrcOnMcuRegisters_McuIf_CheckMcuCrcRegisterStatus
 **/
LOCAL uint8 mcuif_PortSwTestRegCrc(void)
{
   uint32 u32PcrRegisterValueRead = KU32_ZERO;
   uint8 u8Counter = KU8_ZERO;
   uint8 u8PcrRegisterAddress = KU8_ZERO;
   uint8 u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   uint8 u8FailedCrcComp = KU8_FALSE;

   /* Calculate CRC for the first PORT register */
   for(u8Counter = KU8_ZERO; u8Counter < KU8_THIRTYTWO; u8Counter++)
   {
      /* Read PCR register (starting with PCR0) */
      u32PcrRegisterValueRead = MCUIF_REG_READ32(mcuif_ku32PortRegistersArray[mcuif_u8PortCrcCalcQueuePort], u8PcrRegisterAddress);

      /* Calculate CRC */
      mcuif_u32PortCrcRuntimeOutput[u8Counter] = Crc_CalculateCRC32
            (
                  (uint8 *)&u32PcrRegisterValueRead,
                  KU8_MCUIF_CRC32_INIT_LEN,
                  mcuif_u32TempCrcValue,
                  TRUE
            );

      /* Mask PORTE PCR11 register (ACC modify it)*/
      if((KU8_FOUR == mcuif_u8PortCrcCalcQueuePort) && (KU8_ELEVEN == u8Counter))
      {
         mcuif_u32PortCrcRuntimeOutput[u8Counter] = KU32_ZERO;
      }

      /* Increment u8PcrRegisterAddress with 4 to go to the next PCR register at next iteration */
      u8PcrRegisterAddress += KU8_FOUR;
   }

   /* Verify if runtime and initial calculated CRC are the same */
   for(u8Counter = KU8_ZERO; u8Counter < KU8_THIRTYTWO; u8Counter++)
   {
      /* Stop CRC comparison if at least 1 comparison is NOK */
      if(KU8_TRUE != u8FailedCrcComp)
      {
         if(mcuif_u32PortCrcRuntimeOutput[u8Counter] != mcuif_u32PortCrcInitOutput[mcuif_u8PortCrcCalcQueuePort][u8Counter])
         {
            u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
            u8FailedCrcComp = KU8_TRUE;
         }
         else
         {
            u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
      }
   }

   /* Update CRC queue to test the next PORT register at the next iteration */
   if(KU8_FOUR == mcuif_u8PortCrcCalcQueuePort)
   {
      /* CRC on the last PORT was calculated, reset the queue */
      mcuif_u8PortCrcCalcQueuePort = KU8_ZERO;
   }
   else
   {
      /* PORTE wasn't reached, increment queue */
      mcuif_u8PortCrcCalcQueuePort++;
   }

   return u8ResultOfAutoTest;
}

/**
 * \brief
 *       This function is used to calculate CRC on FTM registers.
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       This function return the status of the test.
 * \dynamicaspectcaller
 *       mcuif_CheckCrcOnFtmRegistersAutotest
 * \dynamicaspectdescription
 *       Called cyclic at every 10ms to check FTM registers.
 * \constrains
 *       This function has no constraints.
 * \ddesignrequirement
 *		  DSG_mcuif_FtmSwTestRegCrc
 * \archrequirement
 *       ARCH_SW_McuIf_pseCheckCrcOnMcuRegisters_McuIf_CheckMcuCrcRegisterStatus
 **/
LOCAL uint8 mcuif_FtmSwTestRegCrc(void)
{
   uint32 u32FlexTimerRegisterValueRead = KU32_ZERO;
   uint8 u8CounterStatusRegister = KU8_ZERO;
   uint8 u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   uint8 u8FailedCrcComp = KU8_FALSE;

   /* Calculate CRC for FTM registers */
   for(u8CounterStatusRegister = KU8_ZERO; u8CounterStatusRegister < KU8_SEVENTEEN; u8CounterStatusRegister++)
   {
      /* Read FTMx register (starting with SC) */
      u32FlexTimerRegisterValueRead = MCUIF_REG_READ32
            (
                  mcuif_ku32FlexTimerRegistersArray[mcuif_u8FtmCrcCalcQueuePort],
                  ku8FtmConfigRegisterMasks[u8CounterStatusRegister]
            );

      /* Apply mask for registers which contains flag bits*/
      switch(ku8FtmConfigRegisterMasks[u8CounterStatusRegister])
      {
      case KU8_MCUIF_SC_REG_MASK:
         /* Clear status on the next 2 bits:
          * Bit 9 (Timer Overflow Flag)
          * Bit 7 (Reload Bit) */
         u32FlexTimerRegisterValueRead &= KU32_MCUIF_SC_REG_BITSMASK;
         break;

      case KU8_MCUIF_C0SC_REG_MASK:
      case KU8_MCUIF_C1SC_REG_MASK:
      case KU8_MCUIF_C2SC_REG_MASK:
      case KU8_MCUIF_C3SC_REG_MASK:
      case KU8_MCUIF_C4SC_REG_MASK:
      case KU8_MCUIF_C5SC_REG_MASK:
      case KU8_MCUIF_C6SC_REG_MASK:
      case KU8_MCUIF_C7SC_REG_MASK:
         /* Clear status on the next 3 bits:
          * Bit 10 (Channel Output Value)
          * Bit 9 (Channel Input State)
          * Bit 7 (Channel Flag)
          * Bit 6 (Channel interrupt) */
         u32FlexTimerRegisterValueRead &= KU32_MCUIF_CxSC_REG_BITSMASK;
         break;
      case KU8_MCUIF_EXTTRIG_REG_MASK:
         /* Clear status on the next bit:
          * Bit 7 (Channel Trigger Flag)*/
         u32FlexTimerRegisterValueRead &= KU32_MCUIF_EXTTRIG_REG_BITSMASK;
         break;
      default:
         break;
      }

      /* Calculate CRC */
      mcuif_u32FtmCrcRuntimeOutput[u8CounterStatusRegister] = Crc_CalculateCRC32
            (
                  (uint8 *)&u32FlexTimerRegisterValueRead,
                  KU8_MCUIF_CRC32_INIT_LEN,
                  mcuif_u32TempCrcValue,
                  TRUE
            );
   }

   /* Compare CRC values */
   for(u8CounterStatusRegister = KU8_ZERO; u8CounterStatusRegister < KU8_SEVENTEEN; u8CounterStatusRegister++)
   {
      /* Stop CRC comparison if at least 1 comparison is NOK */
      if(KU8_TRUE != u8FailedCrcComp)
      {
         if((mcuif_u32FtmCrcRuntimeOutput[u8CounterStatusRegister]) !=
               (mcuif_u32FtmCrcInitDataOutput[mcuif_u8FtmCrcCalcQueuePort][u8CounterStatusRegister]))
         {
            u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
            u8FailedCrcComp = KU8_TRUE;
         }
         else
         {
            u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
      }
   }

   if(KU8_THREE == mcuif_u8FtmCrcCalcQueuePort)
   {
      /* All FTM channels were parsed, reset counter */
      mcuif_u8FtmCrcCalcQueuePort = KU8_ZERO;
   }
   else
   {
      /* At next iteration go to the next FTM channel */
      mcuif_u8FtmCrcCalcQueuePort++;
   }

   return u8ResultOfAutoTest;
}

/**
 * \brief
 *       This function is used to handle the ATM result test of ADC CRC.
 * \outputparam
 *       Name: pu8TestResult;
 *       Type: u8TestResultType *;
 *       Description: This parameter is used to return the test status;
 *       Range:
 *           1 - KU8_ATM_TEST_OK
 *           2 - KU8_ATM_TEST_NOK
 *           4 - KU8_ATM_TEST_NOT_DECIDED;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       This function has no return.
 * \dynamicaspectcaller
 *       McuIf_CheckMcuCrcRegisterStatus
 * \dynamicaspectdescription
 *       Called cyclic at every 10ms to check ADC test status.
 * \constrains
 *       This function has no constraints.
 * \ddesignrequirement
 *		  DSG_mcuif_CheckCrcOnAdcRegistersAutotest
 * \archrequirement
 *       ARCH_SW_McuIf_pseCheckCrcOnMcuRegisters_McuIf_CheckMcuCrcRegisterStatus
 **/
LOCAL void mcuif_CheckCrcOnAdcRegistersAutotest(u8TestResultType * pu8TestResult)
{
   uint8 u8CurrentCrcTestResult = KU8_ATM_TEST_NOT_DECIDED;

   u8CurrentCrcTestResult = mcuif_AdcSwTestRegCrc();

   /* Verify CRC comparison status */
   if (KU8_ATM_TEST_OK == u8CurrentCrcTestResult)
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
 *       This function is used to handle the ATM result test of FTM CRC.
 * \outputparam
 *       Name: pu8TestResult;
 *       Type: u8TestResultType *;
 *       Description: This parameter is used to return the test status;
 *       Range:
 *          1 - KU8_ATM_TEST_OK
 *          2 - KU8_ATM_TEST_NOK
 *          4 - KU8_ATM_TEST_NOT_DECIDED;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       This function has no return.
 * \dynamicaspectcaller
 *       McuIf_CheckMcuCrcRegisterStatus
 * \dynamicaspectdescription
 *       Called cyclic at every 10ms to check FTM test status.
 * \constrains
 *       This function has no constraints.
 * \ddesignrequirement
 *		  DSG_mcuif_CheckCrcOnFtmRegistersAutotest
 * \archrequirement
 *       ARCH_SW_McuIf_pseCheckCrcOnMcuRegisters_McuIf_CheckMcuCrcRegisterStatus
 **/
LOCAL void mcuif_CheckCrcOnFtmRegistersAutotest(u8TestResultType * pu8TestResult)
{
   static uint8 u8NoOfParsedCrcRegisters = KU8_ZERO;
   static uint8 u8PcrCrcStatusCounter = KU8_ZERO;
   static uint8 u8TestFailedThisCycle = KU8_FALSE;
   static uint8 u8PreviousCrcTestResult = KU8_ATM_TEST_NOT_DECIDED;
   uint8 u8CurrentCrcTestResult = KU8_ATM_TEST_NOT_DECIDED;

   /* 4 cycles to calculate CRC on all 4 FTM channels */
   if(KU8_FIVE > u8NoOfParsedCrcRegisters)
   {
      /* Reset counters if all 4 channels were verified and a new iteration comes */
      if(KU8_FOUR == u8NoOfParsedCrcRegisters)
      {
         u8NoOfParsedCrcRegisters = KU8_ZERO;
         u8PcrCrcStatusCounter = KU8_ZERO;
      }

      /* Calculate and compare runtime CRC with initial one */
      u8CurrentCrcTestResult = mcuif_FtmSwTestRegCrc();

      /* Verify CRC comparison status */
      if (KU8_ATM_TEST_OK == u8CurrentCrcTestResult)
      {
         /* CRC comparison OK, increment status counter */
         u8PcrCrcStatusCounter++;
      }
      else
      {
         /* CRC comparison failed, set failure flag */
         u8TestFailedThisCycle = KU8_TRUE;
      }
      /* Increment no of parsed channels CRC */
      u8NoOfParsedCrcRegisters++;
   }

   /* Check if the test failed this cycle */
   if(KU8_TRUE == u8TestFailedThisCycle)
   {
      /* Set NOK status for this operation cycle and maintain until u8PcrCrcStatusCounter
       * is equal with 4 (all FTM channel registers are OK) */
      *pu8TestResult = KU8_ATM_TEST_NOK;

      /* If all 4 channels CRC are correct when last cycle is failed, pass the test */
      if(KU8_FOUR == u8PcrCrcStatusCounter)
      {
         /* Return status ok for this cycle (4 iterations) */
         *pu8TestResult = KU8_ATM_TEST_OK;
         /* Reset status of the flag */
         u8TestFailedThisCycle = KU8_FALSE;
         /* Reset Counter */
         u8PcrCrcStatusCounter = KU8_ZERO;
      }
   }
   /* If all 4 FTM CRC are correct OR previous cycle test status is OK */
   else if((KU8_FOUR == u8PcrCrcStatusCounter) || (KU8_ATM_TEST_OK == u8PreviousCrcTestResult))
   {
      /* Return status ok for this cycle (4 iterations) */
      *pu8TestResult = KU8_ATM_TEST_OK;

      /* Reset counters when the 4th iteration is reached */
      if(KU8_FOUR == u8PcrCrcStatusCounter)
      {
         u8PcrCrcStatusCounter = KU8_ZERO;
      }
   }
   /* Set NOT_DECIDED case is covered at statup */
   else
   {
      *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;
   }

   u8PreviousCrcTestResult = *pu8TestResult;

}

/**
 * \brief
 *       This function is used to handle the ATM result test of PORT CRC.
 * \outputparam
 *       Name: pu8TestResult;
 *       Type: u8TestResultType *;
 *       Description: This parameter is used to return the test status;
 *       Range:
 *          1 - KU8_ATM_TEST_OK
 *          2 - KU8_ATM_TEST_NOK
 *          4 - KU8_ATM_TEST_NOT_DECIDED;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       This function has no return.
 * \dynamicaspectcaller
 *       McuIf_CheckMcuCrcRegisterStatus
 * \dynamicaspectdescription
 *       Called cyclic at every 10ms to check PORT test status.
 * \constrains
 *       This function has no constraints.
 * \ddesignrequirement
 *		  DSG_mcuif_CheckCrcOnPortRegistersAutotest
 * \archrequirement
 *       ARCH_SW_McuIf_pseCheckCrcOnMcuRegisters_McuIf_CheckMcuCrcRegisterStatus
 **/
LOCAL void mcuif_CheckCrcOnPortRegistersAutotest(u8TestResultType * pu8TestResult)
{
   uint8 u8CurrentCrcTestResult = KU8_ATM_TEST_NOT_DECIDED;
   static uint8 u8PreviousCrcTestResult = KU8_ATM_TEST_NOT_DECIDED;
   static uint8 u8NoOfParsedCrcRegisters = KU8_ZERO;
   static uint8 u8PcrCrcStatusCounter = KU8_ZERO;
   static uint8 u8TestFailedThisCycle = KU8_FALSE;

   /* Check if all 5 PORT registers were verified */
   if(KU8_SIX > u8NoOfParsedCrcRegisters)
   {
      /* Reset counters if all 5 registers were verified and a new iteration comes */
      if(KU8_FIVE == u8NoOfParsedCrcRegisters)
      {
         u8NoOfParsedCrcRegisters = KU8_ZERO;
         u8PcrCrcStatusCounter = KU8_ZERO;
      }

      /* Calculate and compare runtime CRC with initial one */
      u8CurrentCrcTestResult = mcuif_PortSwTestRegCrc();

      /* Verify CRC comparison status */
      if (KU8_ATM_TEST_OK == u8CurrentCrcTestResult)
      {
         /* CRC comparison OK, increment status counter */
         u8PcrCrcStatusCounter++;
      }
      else
      {
         /* CRC comparison failed, set failure flag */
         u8TestFailedThisCycle = KU8_TRUE;
      }

      /* Increment no of parsed PCR CRC's */
      u8NoOfParsedCrcRegisters++;
   }

   /* Check if the test failed this cycle */
   if(KU8_TRUE == u8TestFailedThisCycle)
   {
      /* Set NOK status for this operation cycle and maintain until u8PcrCrcStatusCounter
       * is equal with 5 (all PORT registers are ok) */
      *pu8TestResult = KU8_ATM_TEST_NOK;

      /* If all 5 CRC are correct when last cycle is failed, pass the test */
      if(KU8_FIVE == u8PcrCrcStatusCounter)
      {
         /* Return status ok for this cycle (5 iterations) */
         *pu8TestResult = KU8_ATM_TEST_OK;
         /* Reset status of the flag */
         u8TestFailedThisCycle = KU8_FALSE;
         /* Reset Counter */
         u8PcrCrcStatusCounter = KU8_ZERO;
      }
   }
   /* If all 5 PORT CRC are correct OR previous cycle test status is OK */
   else if((KU8_FIVE == u8PcrCrcStatusCounter) || (KU8_ATM_TEST_OK == u8PreviousCrcTestResult))
   {
      /* Return status ok for this cycle (5 iterations) */
      *pu8TestResult = KU8_ATM_TEST_OK;

      /* Reset counters when the 5th iteration is reached */
      if(KU8_FIVE == u8PcrCrcStatusCounter)
      {
         u8PcrCrcStatusCounter = KU8_ZERO;
      }
   }
   /* Set NOT_DECIDED case is covered at statup */
   else
   {
      *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;
   }

   u8PreviousCrcTestResult = *pu8TestResult;
}
/******************************************************************************
DEFINITION OF APIs
 ******************************************************************************/
#define McuIf_START_SEC_CODE_ASIL_A
#include "McuIf_MemMap.h"
/**
 * \brief
 *       This function is used to initialize McuIf module. Here are calculated
 *       the initial CRC's of MCU registers after initialization phase.
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       This function has no return.
 * \dynamicaspectcaller
 *       BswM_OnRunFromWakeup
 * \dynamicaspectdescription
 *       Called when the transition from Startup to RUN is made.
 * \constrains
 *       This function has no constraints.
 * \ddesignrequirement
 *		  DSG_McuIf_runInit
 * \archrequirement
 *       ARCH_SW_McuIf_ptrpMcuIfServicesBswmIf_McuIf_runInit
 **/
EXPORTED void McuIf_runInit(void)
{
   /* Calculate init CRC values for PORT registers */
   mcuif_PortSwTestRegCrcInit();

   /* Calculate init CRC values for ADC registers */
   mcuif_AdcSwTestRegCrcVerif(&mcuif_u32AdcCrcInitOutput[KU8_ZERO]);

   /* Calculate init CRC values for FLEXTIMER registers */
   mcuif_FtmSwTestRegCrcInit();
}

/**
 * \brief
 *       This is the Mcu autotest. It consists of checking the if PORT, ADC and FTM
 *       control registers are changed during runtime.
 * \outputparam
 *       Name: *pu8TestResult;
 *       Type: u8TestResultType;
 *       Description: The autotest test result in uint8 range;
 *       Range:
 *			  KU8_ATM_TEST_OK
 *			  KU8_ATM_TEST_NOK
 *			  KU8_ATM_TEST_NOT_DECIDED;
 * \pre
 *       This function must be called in autotests.
 * \dynamicaspectcaller
 *       ATM Autotests.
 * \dynamicaspectdescription
 *       Called in Autotests via RTE layer.
 * \constrains
 *       NONE.
 * \ddesignrequirement
 *		  DSG_McuIf_CheckMcuSelfTest
 * \archrequirement
 *       ARCH_SW_McuIf_pseCheckCrcOnMcuRegisters_McuIf_CheckMcuCrcRegisterStatus
 */
EXPORTED void McuIf_CheckMcuCrcRegisterStatus(u8TestResultType *pu8TestResult)
{
   uint8 u8PortTestStatus = KU8_ATM_TEST_NOT_DECIDED;
   uint8 u8AdcTestStatus = KU8_ATM_TEST_NOT_DECIDED;
   uint8 u8FtmTestStatus = KU8_ATM_TEST_NOT_DECIDED;

   /* Check PORT Registers status */
   mcuif_CheckCrcOnPortRegistersAutotest(&u8PortTestStatus);
   /* Check ADC Registers status */
   mcuif_CheckCrcOnAdcRegistersAutotest(&u8AdcTestStatus);
   /* Check FTM Registers status */
   mcuif_CheckCrcOnFtmRegistersAutotest(&u8FtmTestStatus);

   if((KU8_ATM_TEST_OK == u8PortTestStatus) && (KU8_ATM_TEST_OK == u8AdcTestStatus) && (KU8_ATM_TEST_OK == u8FtmTestStatus))
   {
      *pu8TestResult = KU8_ATM_TEST_OK;
   }
   else if ((KU8_ATM_TEST_NOK == u8PortTestStatus) || (KU8_ATM_TEST_NOK == u8AdcTestStatus) || (KU8_ATM_TEST_NOK == u8FtmTestStatus))
   {
      *pu8TestResult = KU8_ATM_TEST_NOK;
   }
   else
   {
      *pu8TestResult = KU8_ATM_TEST_NOT_DECIDED;
   }
}

/**
 * \brief
 *       This is the Mcu autotest. It consists of checking the internal hardware logic of the mcu.
 * \outputparam
 *       Name: *pu8TestResult;
 *       Type: u8TestResultType;
 *       Description: The autotest test result in uint8 range;
 *       Range:
 *			KU8_ATM_TEST_OK
 *			KU8_ATM_TEST_NOK
 *			KU8_ATM_TEST_NOT_DECIDED;
 * \pre
 *       This function must be called in autotests.
 * \dynamicaspectcaller
 *       ATM Autotests.
 * \dynamicaspectdescription
 *       Called in Autotests via RTE layer.
 * \constrains
 *       NONE.
 * \ddesignrequirement
 *		  DSG_McuIf_CheckMcuSelfTest
 * \archrequirement
 *       ARCH_SW_McuIf_pseCheckMcuSelfTest_McuIf_CheckMcuSelfTest
 */
EXPORTED void McuIf_CheckMcuSelfTest(u8TestResultType *pu8TestResult)
{
   uint32 u32Result = KU32_ZERO;
   u32Result = m4_scst_execute_core_tests(mcuif_KastMcuSeftTestSchedule[mcuif_u8McuSelfTestState].u8StartTest, mcuif_KastMcuSeftTestSchedule[mcuif_u8McuSelfTestState].u8StopTest);

   if(u32Result != M4_SCST_TEST_WAS_INTERRUPTED)
   {
      if(u32Result == mcuif_KastMcuSeftTestSchedule[mcuif_u8McuSelfTestState].u32ExpectedSignature)
      {
         *pu8TestResult = KU8_ATM_TEST_OK;
      }
      else
      {
         *pu8TestResult = KU8_ATM_TEST_NOK;
      }

      mcuif_u8McuSelfTestState++;
      if(mcuif_u8McuSelfTestState >= KU8_MCUIF_MCU_SELF_TEST_STEPS)
      {
         mcuif_u8McuSelfTestState = KU8_ZERO;
      }
   }
   else
   {
      /* retry test step -> test ok for now */
      *pu8TestResult = KU8_ATM_TEST_OK;
   }    
}

#define McuIf_STOP_SEC_CODE_ASIL_A
#include "McuIf_MemMap.h"
/******************************************************************************
End Of File
 *****************************************************************************/

