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
$Revision: 1.3 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader/Autoliv/FblUsr/Implementation/src/project.pj $
*/
/*!****************************************************************************

@details
   Bootmanager HW and SW initialization.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include <ncs.h>
#include <BM_Cbk.h>
#include <common.h>
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
 *       This function is used for bootmanager HW initialization.
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       BM_Prg module.
 * \dynamicaspectdescription
 *       Called by BM startup function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *    DSG_FblUsr_BM_HardwareInit.
 * \archrequirement
 *       ARCH_SW_FblUsr_BM_HardwareInit
 **/
EXPORTED void BM_HardwareInit (void)
{

}

/**
 * \brief
 *       This function is used for bootmanager SW initialization.
 * \pre
 *       None.
 * \return
 *       None.
 * \dynamicaspectcaller
 *       BM_Prg module.
 * \dynamicaspectdescription
 *       Called by BM startup function.
 * \constrains
 *       None.
 * \ddesignrequirement
 *      DSG_FblUsr_BM_SoftwareInit.
 * \archrequirement
 *     ARCH_SW_FblUsr_BM_SoftwareInit

 **/
EXPORTED void BM_SoftwareInit(void)
{

}

/******************************************************************************
End Of File
*****************************************************************************/
