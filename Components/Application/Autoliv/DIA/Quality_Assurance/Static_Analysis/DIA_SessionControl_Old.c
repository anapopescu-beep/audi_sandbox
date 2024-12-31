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
/**
 *    $Revision: 1.1.2.6 $
 *    $ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/DIA/Quality_Assurance/Static_Analysis/project.pj $
 */

/******************************************************************************

@details
   The purpose of this source file is to handle and notify the session changes.

******************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "DIA.h"
#include "EcuM_BSW.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *    Constant used to enable application notification that the DiagOnCAN session has changed .
 *
 */
#define KU8_DIA_ENABLE_RUN_SESSION_CHANGE_INDICATION  STD_OFF
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
#define DIA_START_SEC_CODE
#include "DIA_MemMap.h"

#if(KU8_DIA_ENABLE_RUN_SESSION_CHANGE_INDICATION == STD_ON)
/**
* \brief
*       Notify the application that DiagOnCAN session has changed
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       This function has no return.
* \ddesignrequirement
*		DSG_DIA_runSessionChangeIndication
* \archrequirement
*       ARCH_TEST_REQ
**/
EXPORTED void DIA_runSessionChangeIndication(void)
{
   /* nothing to do */
}
#endif

#define DIA_STOP_SEC_CODE
#include "DIA_MemMap.h"

/*************************************************************************
 Evolution of the component

 created by : T. DEMIREL

 $Log: DIA_SessionControl_Old.c  $
 Revision 1.1.2.6 2023/07/18 14:00:44CEST David Puscasu (david.puscasu) 
 Run QAC After Update DIA Traceability
 Revision 1.1.2.5 2023/04/18 14:24:45EEST Andreea Suiu (andreea.suiu) 
 update QAC reports
 Revision 1.1.2.4 2023/02/24 14:06:09EET Andreea Suiu (andreea.suiu) 
 Update QAC
 Revision 1.1.11.7 2023/02/16 14:27:20EET Andreea Suiu (andreea.suiu) 
 Update Dcm and Dia module according to the coding rules
 Revision 1.1.11.6 2023/02/16 09:16:05EET Andreea Suiu (andreea.suiu) 
 Update Dcm and DIA module (programming response fixed, incorrect transition between session fixed)
 Revision 1.1.11.5 2023/01/20 15:24:05EET Denis Folea (denis.folea) 
 DIA fix after review
 Revision 1.1.11.4 2022/12/22 16:28:53EET Andrei Anca (andrei.anca) 
 Dia cleanup
 Revision 1.1.11.3 2022/11/25 12:47:56EET Dan Dustinta (dan.dustinta) 
 Revision 1.1 2021/08/26 09:16:55EEST Pierre-Olivier Pilot (pierre-olivier.pilot) 
 Initial revision
 Member added to project e:/MKSProjects/SBE/Innovation/ECS/Phase_01/Components/Application/Autoliv/DIA/Implementation/src/project.pj
 Revision 1.2 2021/01/20 11:33:36CET Bayram Ezzayet (bayram.ezzayet) 
 Source files for DIA module
 Revision 1.2 2019/09/18 17:12:03CEST Pierre-Olivier Pilot (pierre-olivier.pilot) 
 DIA integration
 Revision 1.1 2019/08/20 09:18:54CEST Audrey Vache (audrey.vache) 
 Initial revision

*************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/
