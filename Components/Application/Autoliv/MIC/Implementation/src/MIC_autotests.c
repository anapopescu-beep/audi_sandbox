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
$Revision: 1.1.4.14 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/MIC/Implementation/src/project.pj $
*/
/******************************************************************************

   The MIC - Memory Integrity Control is designed in order to control  
   the MCU memory state and to apply the backup strategy (if possible)
   in case of issue detection

******************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_MIC.h"
#include "Nvp_Generated_NvmDefault.h"
#include "NvM_Cfg.h"
#include "MIC_Private.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 * 		Ram Shadow start address
 */
#define MIC_RAM_SHADOW_START_ADDRESS  ((uint32)0x14000000)

/**
 * \brief
 * 		Ram Shadow end address
 */
#define MIC_RAM_SHADOW_END_ADDRESS    ((uint32)0x14000FFF)
/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
/**
 * \brief
 * 		Ram Shadow address that will be used for autotest
 */
LOCAL uint32 mic_u32_RamShadowAddr = MIC_RAM_SHADOW_START_ADDRESS;
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
#define MIC_START_SEC_CODE_ASIL_A
#include "MIC_MemMap.h"

/**
* \brief
*       This autotest check if an ECC was detected in RAM memory area.
* \outputparam
*       Name: pu8TestResult;
*       Type: uint8 *;
*       Description: Pointer to pass the auto-test result;
*       Range: 
*			KU8_ATM_TEST_OK 
*			KU8_ATM_TEST_NOK 
*			KU8_ATM_TEST_NOT_DECIDED;
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       Void.
* \dynamicaspectcaller
*       MIC_cbk_RunRamMemoryCorruption_Autotest.
* \dynamicaspectdescription
*       Callback of Rte_Call_pclRunRamMemoryCorruption AutoTest.
* \ddesignrequirement
*		DSG_MIC_Autotest_RunRamMemoryCorruption
* \archrequirement
*       ARCH_SW_MIC_pseRunRamMemoryCorruption_MIC_Autotest_RunRamMemoryCorruption
*       ARCH_SW_MIC_pclNvmIfServices_SetRamBlockStatus
*       ARCH_SW_MIC_pclResetCause_GetResetCause
*/
EXPORTED void MIC_Autotest_RunRamMemoryCorruption(u8TestResultType * pu8TestResult)
{
   uint8 u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   uint8 u8RamShadowAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   uint8 u8Index;
   uint32 u32ResetCause;
   uint32 u32InitialData;
   uint32 * p32RamShadowAddr;

   /* Call service to get RAM ECC status */
   /* Architecture ensures that RCM reset cause determination has been done */
   /* at initialisation of software, before reading reset cause in this auto test */

   Rte_Call_pclResetCause_GetResetCause(&u32ResetCause);

   /* If RAM ECC error is active -> autotest is failed */
   if ( (KU32_APP_ECC_RAM_NOTIFICATION_MASK == (u32ResetCause & KU32_APP_ECC_RAM_NOTIFICATION_MASK))
     || (KU32_APP_RAM_DATA_CORRUPTED_NOTIFICATION_MASK == (u32ResetCause & KU32_APP_RAM_DATA_CORRUPTED_NOTIFICATION_MASK)) )
   {
      /* Indicate autotest is failed */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOK;

      /*Prevent value to overflow */
      if(KU32_MAX != NVP_u32RAMECCOccurrenceNumber)
      {
         /*Increment the RAM ECC Occurrence Number*/
         NVP_u32RAMECCOccurrenceNumber++;
      }

      /* Notify that the ECC Counters Block has to be recorded in the EEPROM during the shutdown */
      /* (void) the return value is always E_OK because the block exist*/
      (void)Rte_Call_pclNvmIfServices_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_ECC_COUNTERS, TRUE);
   }
   else
   {
      /* Indicate autotest is successful */
      u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }

   /*Check RAM Shadow ECC*/
   if(KU8_ATM_TEST_NOK != u8ResultOfAutoTest )
   {
      /*Disable interrupts */
      SuspendAllInterrupts();

      for(u8Index = KU8_ZERO; u8Index < KU8_FOUR; u8Index++)
      {
         /*Prevent address to overflow */
         if(MIC_RAM_SHADOW_END_ADDRESS < mic_u32_RamShadowAddr)
         {
            mic_u32_RamShadowAddr = MIC_RAM_SHADOW_START_ADDRESS;
         }

         /*Cast the address as a pointer*/
         p32RamShadowAddr = (uint32*)mic_u32_RamShadowAddr;

         /*Read initial value from evaluated address */
         u32InitialData = *p32RamShadowAddr;

         /*Write 0x00000000 at evaluated address */
         *p32RamShadowAddr = KU32_MIN;
         /*check if the writing was correctly done */
         if(KU32_MIN != *p32RamShadowAddr)
         {
            u8RamShadowAutoTest = KU8_ATM_TEST_NOK;
         }

         /*Write 0xFFFFFFFF at evaluated address */
         *p32RamShadowAddr = KU32_MAX;
         /*check if the writing was correctly done */
         if(KU32_MAX != *p32RamShadowAddr)
         {
            u8RamShadowAutoTest = KU8_ATM_TEST_NOK;
         }

         /*Write initial value at evaluated address*/
         *p32RamShadowAddr = u32InitialData;

         mic_u32_RamShadowAddr+=KU8_FOUR;
      }

      /*Enable interrupts */
      ResumeAllInterrupts();

      if(KU8_ATM_TEST_NOK == u8RamShadowAutoTest)
      {
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
   }

   /* Return the auto test status */
   *pu8TestResult = u8ResultOfAutoTest;
}

/**
* \brief
*       This autotest check if an ECC was detected in PFLASH memory area.
* \outputparam
*       Name: pu8TestResult;
*       Type: uint8 *;
*       Description:Pointer to pass the auto-test result;
*       Range: 
*			KU8_ATM_TEST_OK 
*			KU8_ATM_TEST_NOK 
*			KU8_ATM_TEST_NOT_DECIDED;
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       Void.
* \dynamicaspectcaller
*       MIC_cbk_RunPFlashMemoryCorruption_Autotest.
* \dynamicaspectdescription
*       Callback of Rte_Call_pclRunPFlashMemoryCorruption AutoTest.
* \ddesignrequirement
*		DSG_MIC_Autotest_RunPFlashMemoryCorruption
* \archrequirement
*       ARCH_SW_MIC_pseRunPFlashMemoryCorruption_MIC_Autotest_RunPFlashMemoryCorruption
*       ARCH_SW_MIC_pclNvmIfServices_SetRamBlockStatus
*       ARCH_SW_MIC_pclResetCause_GetResetCause
*/
EXPORTED void MIC_Autotest_RunPFlashMemoryCorruption(u8TestResultType * pu8TestResult)
{
   uint8 u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   uint32 u32ResetCause;

   /* Call service to get PFLASH ECC status */
   Rte_Call_pclResetCause_GetResetCause(&u32ResetCause);

   /* If PFLASH ECC error is active -> autotest is failed */
   if ( KU32_APP_ECC_PFLASH_NOTIFICATION_MASK == (u32ResetCause & KU32_APP_ECC_PFLASH_NOTIFICATION_MASK) )
   {
      /* Indicate autotest is failed */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOK;

      /*Prevent value to overflow */
      if(KU32_MAX != NVP_u32PFLASHECCOccurrenceNumber)
      {
         /*Increment the PFLASH ECC Occurrence Number*/
         NVP_u32PFLASHECCOccurrenceNumber++;
      }

      /* Notify that the ECC Counters Block has to be recorded in the EEPROM during the shutdown */
      /* (void) the return value is always E_OK because the block exist*/
      (void)Rte_Call_pclNvmIfServices_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_ECC_COUNTERS, TRUE);
   }
   else
   {
      /* Indicate autotest is successful */
      u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }

   /* Return the auto test status */
   *pu8TestResult = u8ResultOfAutoTest;
}

/**
* \brief
*       This autotest check if an ECC was detected in DFLASH memory area.
* \outputparam
*       Name: pu8TestResult;
*       Type: u8TestResultType * (uint8 *);
*       Description:Pointer to pass the auto-test result;
*       Range: 
*			KU8_ATM_TEST_OK 
*			KU8_ATM_TEST_NOK 
*			KU8_ATM_TEST_NOT_DECIDED;
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       Void.
* \dynamicaspectcaller
*       MIC_cbk_RunEepromMemoryCorruption_Autotest.
* \dynamicaspectdescription
*       Callback of Rte_Call_pclRunEepromMemoryCorruption AutoTest.
* \ddesignrequirement
*		DSG_MIC_Autotest_RunEepromMemoryCorruption
* \archrequirement
*       ARCH_SW_MIC_pseRunEepromMemoryCorruption_MIC_Autotest_RunEepromMemoryCorruption
*       ARCH_SW_MIC_pclNvmIfServices_SetRamBlockStatus
*       ARCH_SW_MIC_pclResetCause_GetResetCause
*/
EXPORTED void MIC_Autotest_RunEepromMemoryCorruption(u8TestResultType * pu8TestResult)
{
   uint8 u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   uint32 u32ResetCause;

   /* Call service to get DFLASH ECC status */
   /* Architecture ensures that RCM reset cause determination has been done */
   /* at initialisation of software, before reading reset cause in this auto test */
   Rte_Call_pclResetCause_GetResetCause(&u32ResetCause);

   /* If DFLASH ECC error is active -> autotest is failed */
   if (( KU32_APP_ECC_E2P_NOTIFICATION_MASK == (u32ResetCause & KU32_APP_ECC_E2P_NOTIFICATION_MASK) ) || (MIC_bECCErrFls == B_TRUE))
   {
      MIC_bECCErrFls = B_FALSE;

      /* Indicate autotest is failed */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOK;

      /*Prevent value to overflow */
      if(KU32_MAX != NVP_u32DFLASHECCOccurrenceNumber)
      {
         /*Increment the DFLASH ECC Occurrence Number*/
         NVP_u32DFLASHECCOccurrenceNumber++;
      }

      /* Notify that the ECC Counters Block has to be recorded in the EEPROM during the shutdown */
      /* (void) the return value is always E_OK because the block exist*/
      (void)Rte_Call_pclNvmIfServices_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_ECC_COUNTERS, TRUE);
   }
   else
   {
      /* Indicate autotest is successful */
      u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }

   /* Return the auto test status */
   *pu8TestResult = u8ResultOfAutoTest;
}

#define MIC_STOP_SEC_CODE_ASIL_A
#include "MIC_MemMap.h"

/*************************************************************************
Evolution of the component

Created by : Pierre-Olivier.Pilot

$Log: MIC_autotests.c  $
Revision 1.1.4.14 2023/08/01 10:09:24CEST Gabriel Brasoveanu (gabriel.brasoveanu) 
Update code after integration of new EB packages
Revision 1.1.4.13 2023/06/19 13:28:13EEST Roxana Dimanescu (roxana.dimanescu) 
MIC src update comments
Revision 1.1.4.12 2023/06/08 09:50:33EEST Mihai Motoc (mihai.motoc) 
Doxygen comments updates
Revision 1.1.4.11 2023/03/23 01:06:32EET Razvan Badiu (razvan.badiu) 
RCM rework first draft
Revision 1.1.4.10 2023/03/17 14:05:45EET Razvan Badiu (razvan.badiu) 
fixes after review
Revision 1.1.4.9 2023/02/28 17:34:35EET Septimiu Vintila (septimiu.vintila) 
Memory sections changed to FuSa memory sections.
Revision 1.1.4.8 2023/02/22 21:52:55EET Razvan Badiu (razvan.badiu) 
Mic interface
Revision 1.1.4.7 2022/11/23 13:36:14EET Andrei Anca (andrei.anca) 
Mic Autotest Fix
Revision 1.1 2015/04/23 15:00:33CEST Pierre-Olivier Pilot (ppilot) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/_MIC/src/project.pj


*****************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/
