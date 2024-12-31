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
$Revision: 1.2.1.10 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/Startup/Implementation/src/project.pj $
*/
/******************************************************************************

   The module is reponsible of clock initialization

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "MyMcuArchClock.h"
#include "Mcl.h"
#include "S32K144_LMEM.h"
#ifndef QAC
#include "T1_AppInterface.h"
#endif
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 *\brief
 *     Macro which defines which memories have cache enabled
 */
#define LMEM_DISABLE_CACHE_ON_DATA_MEM (0xA20FA000u)
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
/**
* \brief
*       This function initialize the PLL for maximum speed.
* \exception
*       This function has no exceptions.
* \pre
*       This function should be called as soon as possible before the app starts.
* \post
*       This function has no postconditions.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       EcuM, LPM.
* \dynamicaspectdescription
*       Called by Ecum Init one sequenceand in LPM module when going to normal mode.
* \constrains
*       None.
* \ddesignrequirement
*		  !DSG_MyMcuArchClock_Init
* \archrequirement
*       ARCH_MyMcuArchClock_Init
**/
EXPORTED void MyMcuArchClock_Init(void)
{

   (void)Mcu_InitClock(MCU_CLOCK_CFG_PARAM);

   /* Wait until the PLL is locked */
   while (MCU_PLL_LOCKED != Mcu_GetPllStatus())
   {
      ;
   }

   /* Activate the PLL Clock */
   (void)Mcu_DistributePllClock();

   /* Set Mcu in RUN Mode */
   Mcu_SetMode(McuConf_McuModeSettingConf_McuModeSettingConf_RUN);

   /* disable program data cache */
   IP_LMEM->PCCRMR = LMEM_DISABLE_CACHE_ON_DATA_MEM;
   /* enable cache */
   (void)Mcl_CacheEnable(MCL_CACHE_ALL);

   T1_AppInit();
}
/******************************************************************************
End Of File
*****************************************************************************/
