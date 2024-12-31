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
#include "common.h"
#include "MIC_Private.h"
#include "MIC_LLD.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *      Address for NO ECC
 */
#define KU32_MIC_NO_ECC_ADDRESS      ((uint32)0xFFFFAA55)
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
#define MIC_START_SEC_CODE_ASIL_A
#include "MIC_MemMap.h"

/**
* \brief
*       Function used to check if ECC errors are detected in FLASH or RAM.
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       B_TRUE   - ECC detected.
*       B_FALSE  - ECC not detected.
* \dynamicaspectcaller
*       MIC_HardFaultException, MIC_BusFaultException.
* \dynamicaspectdescription
*       Function called by a Hard Fault to make the ECC management if necessary.
* \ddesignrequirement
*       DSG_MIC_LLD_CheckEccFault
* \archrequirement
*       ARCH_SW_MIC_p_ptrrMicServicesOsIf_MIC_HardFaultException
*       ARCH_SW_MIC_p_ptrrMicServicesOsIf_MIC_MIC_BusFaultException
*/
EXPORTED boolean MIC_LLD_CheckEccFault(void)
{
   uint32 u32RamEccRegister;
   boolean bEccErrorDetected = B_FALSE;

   /* Read flag from the ERM module */
   u32RamEccRegister = REG_READ32(KU32_MIC_ERM_BASE_ADDRESS,KU32_MIC_ERM_SR0_REG);

   /* Check RAM corruption from ERM module */
   if(KU32_MIC_SR0_NCE0_BIT == (u32RamEccRegister & KU32_MIC_SR0_NCE0_BIT))
   {
      /* Mark detection of an ECC error */
      bEccErrorDetected = B_TRUE;
   }
   else if(KU32_MIC_SR0_NCE1_BIT == (u32RamEccRegister & KU32_MIC_SR0_NCE1_BIT))
   {
      /* Mark detection of an ECC error */
      bEccErrorDetected = B_TRUE;
   }
   /* if ERM and FTFC modules don't report ECC errors, inform upper layers */
   else
   {
      bEccErrorDetected = B_FALSE;
   }

   /* Return the current status of the ECC errors */
   return bEccErrorDetected;
}

/**
* \brief
*       Function used to get fault address from CPU registers.
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       void.
* \dynamicaspectcaller
*      MIC_MachineExceptionInterrupt.
* \dynamicaspectdescription
*       Function when a machine exception is detected by the MCU core,
*       caused by an ECC error Interrupt function will lead to a reset for
*       any ECC error except one in the Emulated EEPROM space found by the Fls.
* \ddesignrequirement
*       DSG_MIC_LLD_GetFaultAddress
* \archrequirement
*       ARCH_SW_MIC_p_ptrrMicServicesOsIf_MIC_HardFaultException
*/
EXPORTED void MIC_LLD_GetFaultAddress(void)
{
   uint32 u32RamEccRegister;
   uint8 u8BFSRImage;
   /* Check if a valid address is stored in the BusFaultAddress register */
   u8BFSRImage = REG_READ8(KU32_MIC_ARMCM4_BASE_ADDRESS, KU32_MIC_ARMCM4_BFSR_REG);

   if(KU8_MIC_BFSR_BFARVALID_BIT == (u8BFSRImage & KU8_MIC_BFSR_BFARVALID_BIT))
   {
      /* Read fault address */
      MIC_stBusFaultRegister.u32FaultAddress = REG_READ32(KU32_MIC_ARMCM4_BASE_ADDRESS,KU32_MIC_ARMCM4_BFAR_REG);
   }
   else
   {
      /* Since BFSR doesn't contain an address, check the ERM */
      u32RamEccRegister = REG_READ32(KU32_MIC_ERM_BASE_ADDRESS,KU32_MIC_ERM_SR0_REG);

      /* For RAM ECC hard fault is called, and no address is available */
      if(KU32_MIC_SR0_NCE0_BIT == (u32RamEccRegister & KU32_MIC_SR0_NCE0_BIT))
      {
         /* Read the address from ERM for RAM0 */
         MIC_stBusFaultRegister.u32FaultAddress = REG_READ32(KU32_MIC_ERM_BASE_ADDRESS,KU32_MIC_ERM_EAR0_REG);
         /* Clear the error flag */
         REG_WRITE32(KU32_MIC_ERM_BASE_ADDRESS, KU32_MIC_ERM_SR0_REG, KU32_MIC_SR0_NCE0_BIT);
      }
      else if(KU32_MIC_SR0_NCE1_BIT == (u32RamEccRegister & KU32_MIC_SR0_NCE1_BIT))
      {
         /* Read the address from ERM for RAM1 */
         MIC_stBusFaultRegister.u32FaultAddress = REG_READ32(KU32_MIC_ERM_BASE_ADDRESS,KU32_MIC_ERM_EAR1_REG);
         /* Clear the error flag */
         REG_WRITE32(KU32_MIC_ERM_BASE_ADDRESS, KU32_MIC_ERM_SR0_REG, KU32_MIC_SR0_NCE1_BIT);
      }
      else
      {
         /* If an ECC is detected on flash and no address is available in the Bus Fault Address register
          * a standard pattern will be loaded in the NO_INIT RAM for further analysis */
         MIC_stBusFaultRegister.u32FaultAddress = KU32_MIC_NO_ECC_ADDRESS;
      }
   }

   /* Store mirror image */
   MIC_stBusFaultRegister.u32FaultAddress_XOR = MIC_stBusFaultRegister.u32FaultAddress;
   MIC_stBusFaultRegister.u32FaultAddress_XOR ^= KU32_MAX;
}

/**
* \brief
*       Function for HW initializations of the MIC module.
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       void.
* \dynamicaspectcaller
*       MIC_Init.
* \dynamicaspectdescription
*       Function called during initialization sequence in order to control the MMC
*       peripheral and RAM_NO_INIT data and apply (if possible) a backup strategy
*       in order to restore the memory usage.
* \ddesignrequirement
*       DSG_MIC_LLD_Init
* \archrequirement
*       ARCH_SW_MIC_p_ptrrMicServicesBswMIf_MIC_Init
*/
EXPORTED void MIC_LLD_Init(void)
{
   uint32 u32SHCSRegister;

   /* Read System Handler Control and State Register */
   u32SHCSRegister = REG_READ32(KU32_MIC_ARMCM4_BASE_ADDRESS, KU32_MIC_ARMCM4_SHCSR_REG);

   /* Enable BUS FAULT interrupt */
   u32SHCSRegister |= KU32_MIC_SHCSR_BUSFAULTENA;

   /* Write-back the register with its modified value */
   REG_WRITE32(KU32_MIC_ARMCM4_BASE_ADDRESS, KU32_MIC_ARMCM4_SHCSR_REG, u32SHCSRegister);

}

#define MIC_STOP_SEC_CODE_ASIL_A
#include "MIC_MemMap.h"

/*************************************************************************
Evolution of the component

Created by : C.Sauvage

$Log: MIC_LLD_Old.c  $
Revision 1.3.1.9 2023/07/05 09:28:43CEST Mihai Motoc (mihai.motoc) 
Run QAC on MIC
Revision 1.1.6.11 2023/06/20 23:29:10EEST Razvan Badiu (razvan.badiu) 
update traceability
Revision 1.1.6.10 2023/06/19 13:28:13EEST Roxana Dimanescu (roxana.dimanescu) 
MIC src update comments
Revision 1.1.6.9 2023/03/20 15:15:23EET David Puscasu (david.puscasu) 
Add Architecture requirements on local functions
Revision 1.1.6.8 2023/03/17 14:05:45EET Razvan Badiu (razvan.badiu) 
fixes after review
Revision 1.1.6.7 2023/02/28 17:34:35EET Septimiu Vintila (septimiu.vintila) 
Memory sections changed to FuSa memory sections.
Revision 1.1.6.6 2023/02/22 21:52:55EET Razvan Badiu (razvan.badiu) 
Mic interface
Revision 1.1.6.5 2022/11/22 15:27:40EET Andrei Anca (andrei.anca) 
Update after review
Revision 1.1 2014/10/06 11:00:57CEST Cedric Sauvage (csauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/_MIC/src/project.pj

*****************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/
