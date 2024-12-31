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
$Revision: 1.3.1.9 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/MIC/Quality_Assurance/Static_Analysis/project.pj $
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
#include "MIC_LLD.h"
#include "MIC_Private.h"
#include "MIC_Public.h"
#include "common.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *      D-FLASH start address
 */
#define KU32_MIC_DFLASH_START_ADDRESS  ((uint32)0x10000000)

/**
 * \brief
 *      D-FLASH END address
 */
#define KU32_MIC_DFLASH_END_ADDRESS    ((uint32)0x1000FFFF)

/**
 * \brief
 *      Check data address
 */
#define KU32_MIC_BFAR_ADDR ((uint32)0xE000ED38)

/**
 * \brief
 *      Check syndrome
 */
#define KU32_MIC_CFSR_ADDR ((uint32)0xE000ED28)

/**
 * \brief
 *      Caused of the hardfault
 */
#define KU16_MIC_CAUSE_E800 ((uint16) 0xE800)

/**
 * \brief
 *      Caused of the hardfault
 */
#define KU16_MIC_CAUSE_F000 ((uint16) 0xF000)

/**
 * \brief
 *      Caused of the hardfault
 */
#define KU16_MIC_CAUSE_F800 ((uint16) 0xF800)
/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
LOCAL void mic_ECC_RAM_Correction (void);
LOCAL void mic_MachineExceptionInterrupt(void);
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
#define MIC_START_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A
#include "MIC_MemMap.h"
/**
 * \brief
 *      Bus Fault Register structure.
 */
EXPORTED MIC_stSnapshotRegister MIC_stBusFaultRegister;

#define MIC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_ASIL_A
#include "MIC_MemMap.h"

#define MIC_START_SEC_VAR_INIT_8_ASIL_A
#include "MIC_MemMap.h"
/**
 * \brief
 *      Variable declaration for FLS ECC Error detection.
 * \initialization
 *      B_FALSE.
 * \range
 *      B_TRUE;
 *      B_FALSE;
 */
EXPORTED boolean MIC_bECCErrFls = B_FALSE;

#define MIC_STOP_SEC_VAR_INIT_8_ASIL_A
#include "MIC_MemMap.h"
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
#define MIC_START_SEC_CODE_ASIL_A
#include "MIC_MemMap.h"
/**
* \brief
*       Function called in case of a RAM ECC corruption to clear the byte
*       content of the RAM_NO_INIT memory section and  write reset notification
*       flags with valid values.
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       No return
* \dynamicaspectcaller
*       MIC_Init.
* \dynamicaspectdescription
*       Function called during initialization sequence in order to control the MMC
*       peripheral and RAM_NO_INIT data and apply (if possible) a backup strategy
*       in order to restore the memory usage.
* \ddesignrequirement
*       DSG_mic_ECC_RAM_Correction
* \archrequirement
*       ARCH_SW_MIC_p_ptrrMicServicesBswMIf_MIC_Init
*       ARCH_SW_MIC_pclResetCauseNotification_NotifyResetCause
*/
LOCAL void mic_ECC_RAM_Correction (void)
{
   uint32 u32LocalStartAddress;
   uint32 u32LocalEndAddress;
   uint32 u32FloatingAddress;

   /* Get the RAM no-init size */
   u32LocalStartAddress = (uint32)&_NoInitRam_Start;
   u32LocalEndAddress = (uint32)&_NoInitRam_End;

   /* For each byte allocated in RAM_NO_INIT memory section, clear the byte content */
   for ( u32FloatingAddress=u32LocalStartAddress ; u32FloatingAddress<=u32LocalEndAddress ; u32FloatingAddress++ )
   {
      * ((uint8 * )u32FloatingAddress) = KU8_ZERO;
   }

   Rte_Call_pclResetCauseNotification_NotifyResetCause(KU32_ECC_RAM_NOTIFICATION);
}

/**
* \brief
*       Function when a machine exception is detected by the MCU core,
*       caused by an ECC error Interrupt function will lead to a reset for
*       any ECC error except one in the Emulated EEPROM space found by the Fls.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       No return
* \dynamicaspectcaller
*       MIC_BusFaultException, MIC_HardFaultException.
* \dynamicaspectdescription
*       Function called by a Hard Fault to make the ECC management if necessary.
* \ddesignrequirement
*       DSG_mic_MachineExceptionInterrupt
* \archrequirement
*       ARCH_SW_MIC_p_ptrrMicServicesOsIf_MIC_HardFaultException
*       ARCH_SW_MIC_pclResetCauseNotification_NotifyResetCause
*       ARCH_SW_MIC_pclSbcServices_SBC_Reset
*       ARCH_SW_MIC_p_ptrrMicServicesOsIf_MIC_MIC_BusFaultException
*/
LOCAL void mic_MachineExceptionInterrupt(void)
{
   /* Get the fault address from HW register */
   MIC_LLD_GetFaultAddress();

   /* Notify a machine exception occurs which will lead to a reset */
   (void) Rte_Call_pclResetCauseNotification_NotifyResetCause(KU32_MACHINE_EXCEPTION_NOTIFICATION);

   /* Force reset by external watchdog */
   (void) Rte_Call_pclSbcServices_SBC_Reset();
}
/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
/**
* \brief
*       Function called by a CPU Hard Fault to make the ECC management if necessary.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       No return
* \dynamicaspectcaller
*       MIC_HardFaultHandlerHll.
* \dynamicaspectdescription
*       Function called by Arm_FaultHandlerThumb to establish the cause of the
*       fault, ignore the address that trigger the fault and compute the address of the
*       following instruction that will be executed.
* \ddesignrequirement
*		DSG_MIC_HardFaultException
* \archrequirement
*       ARCH_SW_MIC_p_ptrrMicServicesOsIf_MIC_HardFaultException
*       ARCH_SW_MIC_pclResetCauseNotification_NotifyResetCause
*       ARCH_SW_MIC_pclSbcServices_SBC_Reset
*/
EXPORTED void MIC_HardFaultException(void)
{
   boolean bIsEccDetected = B_FALSE;

   /* Call the LLD function in charge of MCU registers management */
   bIsEccDetected = MIC_LLD_CheckEccFault();

   /* Check if any module reports an ECC error */
   if(B_TRUE == bIsEccDetected)
   {
      mic_MachineExceptionInterrupt();
   }
   else
   {
      (void) Rte_Call_pclResetCauseNotification_NotifyResetCause(KU32_OS_EXCEPTION_NOTIFICATION);
   }

}

/**
* \brief
*       Function called by a CPU Bus Fault to make the ECC management if necessary.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       No return.
* \dynamicaspectcaller
*       ProtectionHook.
* \dynamicaspectdescription
*       ProtectionHook for the Bus Fault Exception.
* \ddesignrequirement
*		DSG_MIC_BusFaultException
* \archrequirement
*       ARCH_SW_MIC_p_ptrrMicServicesOsIf_MIC_MIC_BusFaultException
*       ARCH_SW_MIC_pclResetCauseNotification_NotifyResetCause
*       ARCH_SW_MIC_pclSbcServices_SBC_Reset
*/
EXPORTED void MIC_BusFaultException(void)
{
   boolean bIsEccDetected = B_FALSE;

   /* Call the LLD function in charge of MCU registers management */
   bIsEccDetected = MIC_LLD_CheckEccFault();

   /* Check if any module reports an ECC error */
   if(B_TRUE == bIsEccDetected)
   {
      mic_MachineExceptionInterrupt();
   }
   else
   {
      (void) Rte_Call_pclResetCauseNotification_NotifyResetCause(KU32_OS_EXCEPTION_NOTIFICATION);
   }

}

/**
* \brief
*       Function called during initialization sequence in order to control the MMC
*       peripheral and RAM_NO_INIT data and apply (if possible) a backup strategy
*       in order to restore the memory usage.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       No return.
* \dynamicaspectcaller
*       BswM_OnStartupTwoA.
* \dynamicaspectdescription
*      Callout to initialize Can/Com stack and modules which doesn't need RTE
*      nor dynamic EEPROM parameters, and start ReadAll process.
* \ddesignrequirement
*		DSG_MIC_Init
* \archrequirement
*       ARCH_SW_MIC_p_ptrrMicServicesBswMIf_MIC_Init
*       ARCH_SW_MIC_pclResetCauseNotification_NotifyResetCause
*/
EXPORTED void MIC_Init(void)
{
   uint32 u32BusFaultAddress;

   /* Call MCU peripheral initialization*/
   MIC_LLD_Init ();

   /* Check RAM NO INIT data consistency */
   if (  (KU32_ZERO != MIC_stBusFaultRegister.u32FaultAddress) &&
         (MIC_stBusFaultRegister.u32FaultAddress == (~(MIC_stBusFaultRegister.u32FaultAddress_XOR))))
   {
      u32BusFaultAddress = MIC_stBusFaultRegister.u32FaultAddress;

      /* Check for ECC error in RAM */
      if((u32BusFaultAddress >= (uint32)&_Ram_Start) && (u32BusFaultAddress <= (uint32)&_Ram_End))
      {
         /* Notify the RCM about the ECC in RAM */
         (void) Rte_Call_pclResetCauseNotification_NotifyResetCause(KU32_ECC_RAM_NOTIFICATION);
      }
      /* Check for ECC error in NO_INIT RAM */
      else if((u32BusFaultAddress >= (uint32)&_NoInitRam_Start) && (u32BusFaultAddress <= (uint32)&_NoInitRam_End))
      {
         /* Call RAM correction for NO_INIT ram */
         mic_ECC_RAM_Correction();
      }
      /* Check for ECC error in Flex RAM */
      else if((u32BusFaultAddress >= (uint32)&_FlexRam_Start) && (u32BusFaultAddress <= (uint32)&_FlexRam_End))
      {
         /* Notify the RCM about the ECC in RAM */
         (void) Rte_Call_pclResetCauseNotification_NotifyResetCause(KU32_ECC_RAM_NOTIFICATION);
      }
      /* Check for ECC error in Stack RAM */
      else if((u32BusFaultAddress >= (uint32)&_Stack_end) && (u32BusFaultAddress <= (uint32)&_Stack_start))
      {
         /* Notify the RCM about the ECC in RAM */
         (void) Rte_Call_pclResetCauseNotification_NotifyResetCause(KU32_ECC_RAM_NOTIFICATION);
      }
      /* Check for ECC in Default EEPROM */
      else if((u32BusFaultAddress >= (uint32)&_EEP_Def_Start) && (u32BusFaultAddress <= (uint32)&_EEP_Def_End))
      {
         /* Notify the RCM about the ECC in D-FLASH */
         (void)  Rte_Call_pclResetCauseNotification_NotifyResetCause(KU32_ECC_PFLASH_NOTIFICATION);
      }
      /* Check for ECC in Calibration FLASH */
      else if((u32BusFaultAddress >= (uint32)&_Calib_Start) && (u32BusFaultAddress <= (uint32)&_Calib_End))
      {
         /* Notify the RCM about the ECC in D-FLASH */
         (void) Rte_Call_pclResetCauseNotification_NotifyResetCause(KU32_ECC_PFLASH_NOTIFICATION);
      }
      /* Check for ECC in Program FLASH */
      else if((u32BusFaultAddress >= (uint32)&_PFlash_Start) && (u32BusFaultAddress <= (uint32)&_PFlash_End))
      {
         /* Notify the RCM about the ECC in D-FLASH */
         (void) Rte_Call_pclResetCauseNotification_NotifyResetCause(KU32_ECC_PFLASH_NOTIFICATION);
      }
      /* Check for ECC in Emulated EEPROM that the FLS did not recognize */
      else if((u32BusFaultAddress >= KU32_MIC_DFLASH_START_ADDRESS) && (u32BusFaultAddress <= KU32_MIC_DFLASH_END_ADDRESS))
      {
         /* Notify the RCM about the ECC in D-FLASH */
         (void) Rte_Call_pclResetCauseNotification_NotifyResetCause(KU32_ECC_E2P_NOTIFICATION);
      }
      else
      {
         /* Notify the RCM about an ECC error in an unknown location */
         (void) Rte_Call_pclResetCauseNotification_NotifyResetCause(KU32_ECC_UNIDENTIFIED_NOTIFICATION);
      }
   }
   /* Clear the RAM NO INIT storage of the ECC address */
   MIC_stBusFaultRegister.u32FaultAddress       = KU32_ZERO;
   MIC_stBusFaultRegister.u32FaultAddress_XOR   = KU32_MAX;

}

/**
* \brief
*       Function called by Arm_FaultHandlerThumb to establish the cause of the
*       fault, ignore the address that trigger the fault and compute the address of the
*       following instruction that will be executed.
* \inputparam
*       Name: instr_pt2pt;
*       Type: Fls_InstructionAddressType* (const uint8 *);
*       Description: pointer to the instruction that caused the hardfault;
*       Range: 0x00..0xFFFFFFFF;
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       No return.
* \dynamicaspectcaller
*       Arm_FaultHandlerThumb.
* \dynamicaspectdescription
*       Function used to compute the address of the following instruction
*       that will be executed.
* \ddesignrequirement
*       DSG_MIC_HardFaultHandlerHll
* \archrequirement
*       ARCH_SW_MIC_p_ptrrMicServicesOsIf_MIC_MIC_HardFaultHandlerHll
*/
EXPORTED void MIC_HardFaultHandlerHll(Fls_InstructionAddressType * const instr_pt2pt)
{
   Fls_InstructionAddressType pu8InstructionAddress;
   Fls_DataAddressType pvDataAddress;
   uint32 u32Syndrome;
   Fls_ExceptionDetailsType stExceptionDetails;
   Fls_CompHandlerReturnType u8SpecificHandlerResult = FLS_UNHANDLED;
   uint16 u16InstrOpcode;     /* The instruction opcode(or the first 16 bits) value, stored in memory, for the instruction which caused the fault */
   uint16 u16ThumbInstrSize;   /* Size of the instruction opcode stored in memory, 2 or 4 bytes */

   pu8InstructionAddress = * instr_pt2pt;
   pvDataAddress  = (void const *)(*((uint32*)KU32_MIC_BFAR_ADDR));
   u32Syndrome = *((uint32*)KU32_MIC_CFSR_ADDR);

   /* Compute the instruction opcode size for the instruction which caused the hardfault. *
    * The value will be used to compute the address of the following instruction */
   u16InstrOpcode =  *((uint16*)(*instr_pt2pt));
   /* Compute the size of the instruction which caused the fault */
   if (((u16InstrOpcode & KU16_MIC_CAUSE_E800) == KU16_MIC_CAUSE_E800) ||   /* 0b11101x... */
       ((u16InstrOpcode & KU16_MIC_CAUSE_F000) == KU16_MIC_CAUSE_F000) ||   /* 0b11110x... */
       ((u16InstrOpcode & KU16_MIC_CAUSE_F800) == KU16_MIC_CAUSE_F800))     /* 0b11111x... */
   {
      /* Instruction size is 32 bits, 4 bytes */
      u16ThumbInstrSize = (uint16)KU8_FOUR;
   }
   else
   {
      /* Instruction size is 16 bits, 2 bytes */
      u16ThumbInstrSize = (uint16)KU8_TWO;
   }

   stExceptionDetails.instruction_pt = pu8InstructionAddress;
   stExceptionDetails.data_pt        = pvDataAddress;
   stExceptionDetails.syndrome_u32   = u32Syndrome;

   u8SpecificHandlerResult = Fls_DsiHandler(&stExceptionDetails);

   if(FLS_HANDLED_SKIP == u8SpecificHandlerResult)
   {
      /* exception was handled by one of the functions called above,                       *
       * continue execution, skipping the causing instruction                              *
       * In the test code we assume that the exception was caused by 16-bit/32-bit         *
       * load Thumb instruction => increment return address by the size of the instruction */
      * instr_pt2pt = pu8InstructionAddress + u16ThumbInstrSize;
      /* clear the flags and address register */
      *((volatile uint32*)KU32_MIC_CFSR_ADDR) = *((volatile uint32*)KU32_MIC_CFSR_ADDR);
      *((uint32*)KU32_MIC_BFAR_ADDR) = KU32_ZERO;
      MIC_bECCErrFls = B_TRUE;
   }
   else
   {
      (void) MIC_HardFaultException();
      (void) OS_ExceptionBusFaultHandler();
   }
}

#define MIC_STOP_SEC_CODE_ASIL_A
#include "MIC_MemMap.h"

/*************************************************************************
Evolution of the component

Created by : C.Sauvage

$Log: MIC_Old.c  $
Revision 1.3.1.9 2023/07/05 09:28:45CEST Mihai Motoc (mihai.motoc) 
Run QAC on MIC
Revision 1.1.9.15 2023/06/20 23:29:11EEST Razvan Badiu (razvan.badiu) 
update traceability
Revision 1.1.9.14 2023/06/19 13:28:15EEST Roxana Dimanescu (roxana.dimanescu) 
MIC src update comments
Revision 1.1.9.13 2023/06/08 09:50:33EEST Mihai Motoc (mihai.motoc) 
Doxygen comments updates
Revision 1.1.9.12 2023/03/23 01:06:31EET Razvan Badiu (razvan.badiu) 
RCM rework first draft
Revision 1.1.9.11 2023/03/20 15:15:23EET David Puscasu (david.puscasu) 
Add Architecture requirements on local functions
Revision 1.1.9.10 2023/03/17 14:05:45EET Razvan Badiu (razvan.badiu) 
fixes after review
Revision 1.1.9.9 2023/02/28 17:34:35EET Septimiu Vintila (septimiu.vintila) 
Memory sections changed to FuSa memory sections.
Revision 1.1.9.8 2023/02/22 21:52:54EET Razvan Badiu (razvan.badiu) 
Mic interface
Revision 1.1.9.7 2023/02/21 11:39:14EET David Puscasu (david.puscasu) 
Update architecture and add architecture requirements
Revision 1.1.9.6 2022/11/25 10:20:24EET Andrei Anca (andrei.anca) 
Update header zone
Revision 1.1 2014/10/06 10:58:42CEST Cedric Sauvage (csauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/_MIC/src/project.pj

*****************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/
