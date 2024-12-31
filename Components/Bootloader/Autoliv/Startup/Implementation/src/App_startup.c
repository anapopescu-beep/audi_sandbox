/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version: 
Template version: AEM_PROCESS_1.25.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2022-07
******************************************************************************/
/*
$Revision: 1.2.1.11 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader/Autoliv/Startup/Implementation/src/project.pj $
*/
/*****************************************************************************

details
   This file contains some specific C-functions called during startup code
   These functions have to be called after SP initialization
   These functions are specific to IAR build tool chain

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Std_types.h"
#include "EcuM.h"
#include "common.h"
#include "S32K144_RCM.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/

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
/**
 * \brief
 *      This variable defined in the linker script and points to first availale RAM address.
 * \initialization 
 *      From linker script.
 * \range
 *      0x1FFF8000..0x20004000.
 */
extern uint8 _Ram_Start;
/**
 * \brief
 *      This variable defined in the linker script and points to last availale RAM address.
 * \initialization 
 *      From linker script.
 * \range
 *      0x1FFF8000..0x20004000.
 */
extern uint8 _Ram_End;
/**
 * \brief
 *      This variable defined in the linker script and points to first availale NVM RAM address.
 * \initialization 
 *      From linker script.
 * \range
 *      0x14000000..0x1400FFFF.
 */
extern uint8 _FlexRam_Start;
/**
 * \brief
 *      This variable defined in the linker script and points to last availale NVM RAM address.
 * \initialization 
 *      From linker script.
 * \range
 *      0x14000000..0x1400FFFF.
 */
extern uint8 _FlexRam_End;
/**
 * \brief
 *      This variable defined in the linker script and points to first availale NVM RAM no init address.
 * \initialization 
 *      From linker script.
 * \range
 *      0x20006F00..0x20006FFF.
 */
extern uint8 _NoInitRam_Start;
/**
 * \brief
 *      This variable defined in the linker script and points to last availale NVM RAM no init address.
 * \initialization 
 *      From linker script.
 * \range
 *      0x20006F00..0x20006FFF.
 */
extern uint8 _NoInitRam_End;
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
/**
* \brief
*       This function has to init RAM data area depending of there types (init/uninit/ etc).
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       Startup.
* \dynamicaspectdescription
*       Called by Startup sequence (refer to startup_iar.s).
* \constrains
*       Has to be called after SP initialization and before main function
*       The Stack shall NOT be erased or we will not be able to return to startup function
* \ddesignrequirement
*		  !DSG_RAM_InitData
* \archrequirement
*       ARCH_RAM_InitData
**/
void RAM_InitData (void)
{
   uint8 * u8From;
   uint8 * u8To;
   uint32  u32length;  
   
   /* Initialize AppData segment with its initialization Flash segment */
   u8To      = &_Ram_Start;
   u32length = (((uint32)&_Ram_End) - ((uint32)&_Ram_Start)) + 1u;
   while (0u != u32length)
   {
      *u8To = 0u;
      u8To++;
      u32length--;
   }

   /* Initialize AppData segment with its initialization Flash segment */
   u8To      = &_FlexRam_Start;
   u32length = (((uint32)&_FlexRam_End) - ((uint32)&_FlexRam_Start)) + 1u;
   while (0u != u32length)
   {
      *u8To = KU8_MAX;
      u8To++;
      u32length--;
   }

   /* Initialize AppData segment with its initialization Flash segment */
   #pragma section = "AppData"
   #pragma section = "AppData_Init"
   u8From    = (uint8 *)__segment_begin("AppData_Init");
   u8To      = (uint8 *)__segment_begin("AppData");
   u32length = (uint32) __segment_size("AppData");
   while (0u != u32length)
   {
      *u8To = *u8From;
      u8To++;
      u8From++;
      u32length--;
   }

   /* Initialize AppData segment with its initialization Flash segment */
   #pragma section = "AppData_ASIL_A"
   #pragma section = "AppData_Init_ASIL_A"
   u8From    = (uint8 *)__segment_begin("AppData_Init_ASIL_A");
   u8To      = (uint8 *)__segment_begin("AppData_ASIL_A");
   u32length = (uint32) __segment_size("AppData_ASIL_A");
   while (0u != u32length)
   {
      *u8To = *u8From;
      u8To++;
      u8From++;
      u32length--;
   }
   
   /* Erase bss section */
   #pragma section = "AppBSS"
   u8To      = (uint8 *)__segment_begin("AppBSS");
   u32length = (uint32) __segment_size("AppBSS");
   while (0u != u32length)
   {
      *u8To = 0u;
      u8To++;
      u32length--;
   }

   /* Erase bss section */
   #pragma section = "AppBSS_ASIL_A"
   u8To      = (uint8 *)__segment_begin("AppBSS_ASIL_A");
   u32length = (uint32) __segment_size("AppBSS_ASIL_A");
   while (0u != u32length)
   {
      *u8To = 0u;
      u8To++;
      u32length--;
   }

   /* if Power on reset init also the no init area */
   if(RCM_SRS_POR_MASK == (IP_RCM->SRS & RCM_SRS_POR_MASK))
   {
      u8To      = &_NoInitRam_Start;
      u32length = (((uint32)&_NoInitRam_End) - ((uint32)&_NoInitRam_Start)) + 1u;
      while (0u != u32length)
      {
         *u8To = 0u;
         u8To++;
         u32length--;
      }
   }
}

/**
* \brief
*       This function is the main application entry point
*       This function will start the application
* \exception
*       This function has no exceptions.
* \pre
*       Has to be called after SP initialization and Ram init.
* \post
*       This function has no postconditions.
* \return
*       This function is not expected to return.
* \dynamicaspectcaller
*       Startup.
* \dynamicaspectdescription
*       Called by Startup sequence (refer to startup_iar.s).
* \constrains
*       None.
* \ddesignrequirement
*		  !DSG_main
* \archrequirement
*       ARCH_main
**/
int main(void)
{
   /* enable interrupts because fbl disables them => machine exception */
   __asm("cpsie   i ");
   EcuM_Init();
    
   return 0;
}
/******************************************************************************
End Of File
*****************************************************************************/
