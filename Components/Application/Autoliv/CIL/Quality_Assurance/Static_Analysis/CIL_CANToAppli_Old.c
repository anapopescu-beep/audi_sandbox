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
 *    $Revision: 1.7.1.5 $
 *    $ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/CIL/Quality_Assurance/Static_Analysis/project.pj $
 */

/**
 * Overview of the component :
 *    Communication Interface Layer (CIL) oversees extracting data from the 
 *    network frames (e.g. CAN) and providing the data to the application, and 
 *    packing the outgoing data to the network frames.
 *    The aim of the CIL component is to interpret all received signals on the
 *    communication component and to provide the right information to the application.
 *    Also, it’s purpose is to gather information from the Application and
 *    compute the status signals and sent them to the CAN bus.
 *    CIL oversees:
 *       - Unpacking received data frames from the network (CAN), and providing 
 *         the data to the application
 *       - Packing the outgoing data to data frames for the network (CAN)
 */

/*!****************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_CIL.h"
#include "Nvp_Cfg.h"
#include "CIL.h"
#include "RteIf.h"

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
#define CIL_START_SEC_VAR_INIT_8_ASIL_A
#include "CIL_MemMap.h"

/**
 * \brief
 *      This variable is used to retain if a diagnostic request has been received on
 *      the CAN bus on the AktuatorTest signal
 * \initialization KU8_FALSE for each solenoid
 */
LOCAL uint8 cil_u8DiagReqPresent[sizeof(au8eCSDiagReqType)] = {KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE, KU8_FALSE};

#define CIL_STOP_SEC_VAR_INIT_8_ASIL_A
#include "CIL_MemMap.h"

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
#define CIL_START_SEC_VAR_NO_INIT_8
#include "CIL_MemMap.h"

/**
 * \brief
 *      This variable is used to retain the status of buckle that should be send on CAN.
 * \initialization 
 *      NA.
 * \range
 *      NA.
 */
EXPORTED uint8 CIL_u8BuckleStatusTx[CIL_NO_OF_BUCKLES];

/**
 * \brief
 *      This variable is used to retain the status of seat occupancy that should be send on CAN.
 * \initialization
 *      NA.
 * \range
 *      NA.
 */
EXPORTED uint8 CIL_u8SeatOccupancySensorTx[CIL_NO_OF_SEATS];

#define CIL_STOP_SEC_VAR_NO_INIT_8
#include "CIL_MemMap.h"

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
#define CIL_START_SEC_CODE_ASIL_A
#include "CIL_MemMap.h"

/**
* \brief
*       Function is used to handle functional safety part of communication(handling
*       of diagnostic requests received on the CAN bus)
* \return
*       This function must not have a return value.
* \constrains
*       This function is called cyclically
* \dynamicaspectcaller
*       OsTask_Alv_ComServices
* \dynamicaspectdescription
*       Called by Operating System
* \ddesignrequirement
*       DSG_CIL_runCANToSafetyAppli
* \archrequirement
*     ARCH_SW_CIL_RP_IF_AB_eCS_Aktuatortest_Reihe2_BF_XIX_Grundumfang_XIX_eCS;
*     ARCH_SW_CIL_RP_IF_AB_eCS_Aktuatortest_FA_XIX_Grundumfang_XIX_eCS;
*     ARCH_SW_CIL_RP_IF_AB_eCS_Aktuatortest_BF_XIX_Grundumfang_XIX_eCS;
*     ARCH_SW_CIL_RP_IF_AB_eCS_Aktuatortest_FA_XIX_Grundumfang_XIX_eCS;
*     ARCH_SW_CIL_RP_IF_AB_Crash_Int_XIX_Grundumfang_XIX_eCS;
*     ARCH_SW_CIL_ptrpAsrOsServicesCIL_CIL_runCANToSafetyAppli;
*     ARCH_SW_CIL_psrEcsDiagRequest;
*     ARCH_SW_CIL_psrCrashStatus_u8IsCrashActive;
**/
EXPORTED void CIL_runCANToSafetyAppli(void)
{
   uint8 u8Crash_Int_Status = (uint8)CM_AB_Crash_Int_Cx7_Crash_Intensitaet_3;
   uint8 u8Aktuatortest_Reihe1_FA = (uint8)CM_AB_eCS_Aktuatortest_FA_Cx0_Keine_Aktion;
   uint8 u8Aktuatortest_Reihe1_BF = (uint8)CM_AB_eCS_Aktuatortest_BF_Cx0_Keine_Aktion;
   uint8 u8Aktuatortest_Reihe2_FA = (uint8)CM_AB_eCS_Aktuatortest_Reihe2_FA_Cx0_Keine_Aktion;   
   uint8 u8Aktuatortest_Reihe2_BF = (uint8)CM_AB_eCS_Aktuatortest_Reihe2_BF_Cx0_Keine_Aktion;

   u8eCSDiagReqType au8SolenoidDiagRequest[sizeof(au8eCSDiagReqType)];
   u8eCSDiagReqType au8SolenoidDiagRequestComplement[sizeof(au8eCSDiagReqType)];
      
   /* get initial diagnositc request */
   (void)Rte_Read_CIL_SAD_au8DiagReq_prrEcsDiagRequest(au8SolenoidDiagRequest);
   (void)Rte_Read_CIL_SAD_au8DiagReqComplement_prrEcsDiagRequest(au8SolenoidDiagRequestComplement);

   /* Check the command recieved on CAN */
   (void)Rte_Read_RP_IF_AB_eCS_Aktuatortest_FA_XIX_Grundumfang_XIX_eCS_DE_AB_eCS_Aktuatortest_FA(&u8Aktuatortest_Reihe1_FA);
   (void)Rte_Read_RP_IF_AB_eCS_Aktuatortest_BF_XIX_Grundumfang_XIX_eCS_DE_AB_eCS_Aktuatortest_BF(&u8Aktuatortest_Reihe1_BF);
   (void)Rte_Read_RP_IF_AB_eCS_Aktuatortest_Reihe2_FA_XIX_Grundumfang_XIX_eCS_DE_AB_eCS_Aktuatortest_Reihe2_FA(&u8Aktuatortest_Reihe2_FA);
   (void)Rte_Read_RP_IF_AB_eCS_Aktuatortest_Reihe2_BF_XIX_Grundumfang_XIX_eCS_DE_AB_eCS_Aktuatortest_Reihe2_BF(&u8Aktuatortest_Reihe2_BF);

   /* Actuator 1 & 2 handling */
   if ((uint8)CM_AB_eCS_Aktuatortest_FA_Cx1_Verriegelt == u8Aktuatortest_Reihe1_FA)
   {
      /* LOCK actuator 1 */
      au8SolenoidDiagRequest[KU8_ZERO] = KU8_LOCK_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_ZERO] = (uint8)~KU8_LOCK_DIAG_REQUEST;
      /* LOCK actuator 2 */
      au8SolenoidDiagRequest[KU8_ONE] = KU8_LOCK_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_ONE] = (uint8)~KU8_LOCK_DIAG_REQUEST;
      /* set diagnostic request */
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReq(au8SolenoidDiagRequest);
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReqComplement(au8SolenoidDiagRequestComplement);
      cil_u8DiagReqPresent[KU8_ZERO] = KU8_TRUE;
      cil_u8DiagReqPresent[KU8_ONE] = KU8_TRUE;
   }
   else if(CM_AB_eCS_Aktuatortest_FA_Cx2_Entriegelt == u8Aktuatortest_Reihe1_FA)
   {
      /* UNLOCK actuator 1 */
      au8SolenoidDiagRequest[KU8_ZERO] = KU8_UNLOCK_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_ZERO] = (uint8)~KU8_UNLOCK_DIAG_REQUEST;
      /* UNLOCK actuator 2 */
      au8SolenoidDiagRequest[KU8_ONE] = KU8_UNLOCK_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_ONE] = (uint8)~KU8_UNLOCK_DIAG_REQUEST;
      /* set diagnostic request */
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReq(au8SolenoidDiagRequest);
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReqComplement(au8SolenoidDiagRequestComplement);
      cil_u8DiagReqPresent[KU8_ZERO] = KU8_TRUE;
      cil_u8DiagReqPresent[KU8_ONE] = KU8_TRUE;
   }
   else if ((KU8_TRUE == cil_u8DiagReqPresent[KU8_ZERO]) && (KU8_TRUE == cil_u8DiagReqPresent[KU8_ONE]))
   {
      /* Clear old actuator 1 status */
      au8SolenoidDiagRequest[KU8_ZERO] = KU8_NO_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_ZERO] = (uint8)~KU8_NO_DIAG_REQUEST;
      /* Clear old actuator 2 status */
      au8SolenoidDiagRequest[KU8_ONE] = KU8_NO_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_ONE] = (uint8)~KU8_NO_DIAG_REQUEST;
      /* Clear diagnostic request */
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReq(au8SolenoidDiagRequest);
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReqComplement(au8SolenoidDiagRequestComplement);
      cil_u8DiagReqPresent[KU8_ZERO] = KU8_FALSE;
      cil_u8DiagReqPresent[KU8_ONE] = KU8_FALSE;
   }
   else
   {
      /* Do nothing */
   }

   /* Actuator 3 & 4 handling */
   if ((uint8)CM_AB_eCS_Aktuatortest_BF_Cx1_Verriegelt == u8Aktuatortest_Reihe1_BF)
   {
      /* LOCK actuator 3 */
      au8SolenoidDiagRequest[KU8_TWO] = KU8_LOCK_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_TWO] = (uint8)~KU8_LOCK_DIAG_REQUEST;
      /* LOCK actuator 4 */
      au8SolenoidDiagRequest[KU8_THREE] = KU8_LOCK_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_THREE] = (uint8)~KU8_LOCK_DIAG_REQUEST;
      /* set diagnostic request */
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReq(au8SolenoidDiagRequest);
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReqComplement(au8SolenoidDiagRequestComplement);
      cil_u8DiagReqPresent[KU8_TWO] = KU8_TRUE;
      cil_u8DiagReqPresent[KU8_THREE] = KU8_TRUE;
   }
   else if((uint8)CM_AB_eCS_Aktuatortest_BF_Cx2_Entriegelt == u8Aktuatortest_Reihe1_BF)
   {
      /* UNLOCK actuator 3 */
      au8SolenoidDiagRequest[KU8_TWO] = KU8_UNLOCK_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_TWO] = (uint8)~KU8_UNLOCK_DIAG_REQUEST;
      /* UNLOCK actuator 4 */
      au8SolenoidDiagRequest[KU8_THREE] = KU8_UNLOCK_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_THREE] = (uint8)~KU8_UNLOCK_DIAG_REQUEST;
      /* set diagnostic request */
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReq(au8SolenoidDiagRequest);
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReqComplement(au8SolenoidDiagRequestComplement);
      cil_u8DiagReqPresent[KU8_TWO] = KU8_TRUE;
      cil_u8DiagReqPresent[KU8_THREE] = KU8_TRUE;
   }
   else if ((KU8_TRUE == cil_u8DiagReqPresent[KU8_TWO]) && (KU8_TRUE == cil_u8DiagReqPresent[KU8_THREE]))
   {
      /* Clear old actuator 3 status */
      au8SolenoidDiagRequest[KU8_TWO] = KU8_NO_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_TWO] = (uint8)~KU8_NO_DIAG_REQUEST;
      /* Clear old actuator 4 status */
      au8SolenoidDiagRequest[KU8_THREE] = KU8_NO_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_THREE] = (uint8)~KU8_NO_DIAG_REQUEST;
      /* Clear diagnostic request */
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReq(au8SolenoidDiagRequest);
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReqComplement(au8SolenoidDiagRequestComplement);
      cil_u8DiagReqPresent[KU8_TWO] = KU8_FALSE;
      cil_u8DiagReqPresent[KU8_THREE] = KU8_FALSE;
   }
   else
   {
      /* Do nothing */
   }

   /* Actuator 5 handling */
   if ((uint8)CM_AB_eCS_Aktuatortest_Reihe2_FA_Cx1_Verriegelt == u8Aktuatortest_Reihe2_FA)
   {
      /* LOCK actuator 5 */
      au8SolenoidDiagRequest[KU8_FOUR] = KU8_LOCK_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_FOUR] = (uint8)~KU8_LOCK_DIAG_REQUEST;

      /* set diagnostic request */
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReq(au8SolenoidDiagRequest);
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReqComplement(au8SolenoidDiagRequestComplement);
      cil_u8DiagReqPresent[KU8_FOUR] = KU8_TRUE;
   }
   else if((uint8)CM_AB_eCS_Aktuatortest_Reihe2_FA_Cx2_Entriegelt == u8Aktuatortest_Reihe2_FA)
   {
      /* UNLOCK actuator 5 */
      au8SolenoidDiagRequest[KU8_FOUR] = KU8_UNLOCK_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_FOUR] = (uint8)~KU8_UNLOCK_DIAG_REQUEST;

      /* set diagnostic request */
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReq(au8SolenoidDiagRequest);
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReqComplement(au8SolenoidDiagRequestComplement);
      cil_u8DiagReqPresent[KU8_FOUR] = KU8_TRUE;
   }
   else if (KU8_TRUE == cil_u8DiagReqPresent[KU8_FOUR])
   {
      /* Clear old actuator 5 status */
      au8SolenoidDiagRequest[KU8_FOUR] = KU8_NO_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_FOUR] = (uint8)~KU8_NO_DIAG_REQUEST;
      /* Clear diagnostic request */
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReq(au8SolenoidDiagRequest);
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReqComplement(au8SolenoidDiagRequestComplement);
      cil_u8DiagReqPresent[KU8_FOUR] = KU8_FALSE;
   }
   else
   {
      /* do nothing */
   }

   /* Actuator 6 handling */
   if ((uint8)CM_AB_eCS_Aktuatortest_Reihe2_BF_Cx1_Verriegelt == u8Aktuatortest_Reihe2_BF)
   {
      /* LOCK actuator 6 */
      au8SolenoidDiagRequest[KU8_FIVE] = KU8_LOCK_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_FIVE] = (uint8)~KU8_LOCK_DIAG_REQUEST;
      /* set diagnostic request */
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReq(au8SolenoidDiagRequest);
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReqComplement(au8SolenoidDiagRequestComplement);
      cil_u8DiagReqPresent[KU8_FIVE] = KU8_TRUE;
   }
   else if((uint8)CM_AB_eCS_Aktuatortest_Reihe2_BF_Cx2_Entriegelt == u8Aktuatortest_Reihe2_BF)
   {
      /* UNLOCK actuator 6 */
      au8SolenoidDiagRequest[KU8_FIVE] = KU8_UNLOCK_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_FIVE] = (uint8)~KU8_UNLOCK_DIAG_REQUEST;
      /* set diagnostic request */
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReq(au8SolenoidDiagRequest);
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReqComplement(au8SolenoidDiagRequestComplement);
      cil_u8DiagReqPresent[KU8_FIVE] = KU8_TRUE;
   }
   else if (KU8_TRUE == cil_u8DiagReqPresent[KU8_FIVE])
   {
      /* Clear old actuator 6 status */
      au8SolenoidDiagRequest[KU8_FIVE] = KU8_NO_DIAG_REQUEST;
      au8SolenoidDiagRequestComplement[KU8_FIVE] = (uint8)~KU8_NO_DIAG_REQUEST;
      /* Clear diagnostic request */
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReq(au8SolenoidDiagRequest);
      (void)Rte_Write_psrEcsDiagRequest_au8DiagReqComplement(au8SolenoidDiagRequestComplement);
      cil_u8DiagReqPresent[KU8_FIVE] = KU8_FALSE;
   }
   else
   {
      /* do nothing */
   }

   /* Read the Crash Status sent via CAN message */
   (void)Rte_Read_RP_IF_AB_Crash_Int_XIX_Grundumfang_XIX_eCS_DE_AB_Crash_Int(&u8Crash_Int_Status);
   /* Make the result visible for other modules */
   (void)Rte_Write_psrCrashStatus_u8IsCrashActive(u8Crash_Int_Status);      
}

#define CIL_STOP_SEC_CODE_ASIL_A
#include "CIL_MemMap.h"

#define CIL_START_SEC_CODE
#include "CIL_MemMap.h"

/**
* \brief
*        This function is the CIL periodic main function that is used to get data from the CAN bus.
* \dynamicaspectcaller
*        Scheduler.
* \dynamicaspectdescription
*        Called at 10 ms.
* \ddesignrequirement
*        DSG_CIL_runCANToAppli
* \archrequirement
*        ARCH_SW_CIL_RP_IF_AB_Gurtschloss_BF_XIX_Grundumfang_XIX_eCS;
*        ARCH_SW_CIL_RP_IF_AB_Gurtschloss_FA_XIX_Grundumfang_XIX_eCS;
*        ARCH_SW_CIL_RP_IF_AB_eCS_Aktuatortest_Reihe2_FA_XIX_Grundumfang_XIX_eCS;
*        ARCH_SW_CIL_ptrpAsrOsServicesCIL_CIL_runCANToAppli;
**/
EXPORTED void CIL_runCANToAppli(void)
{
   /* Read Buckle Status from Airbag_02 */
   (void)Rte_Read_RP_IF_AB_Gurtschloss_FA_XIX_Grundumfang_XIX_eCS_DE_AB_Gurtschloss_FA(&CIL_u8BuckleStatusTx[KU8_ZERO]);
   (void)Rte_Read_RP_IF_AB_Gurtschloss_FA_XIX_Grundumfang_XIX_eCS_DE_AB_Gurtschloss_FA(&CIL_u8BuckleStatusTx[KU8_ONE]);
   (void)Rte_Read_RP_IF_AB_Gurtschloss_BF_XIX_Grundumfang_XIX_eCS_DE_AB_Gurtschloss_BF(&CIL_u8BuckleStatusTx[KU8_TWO]);
   (void)Rte_Read_RP_IF_AB_Gurtschloss_BF_XIX_Grundumfang_XIX_eCS_DE_AB_Gurtschloss_BF(&CIL_u8BuckleStatusTx[KU8_THREE]);
} 

#define CIL_STOP_SEC_CODE
#include "CIL_MemMap.h"

/******************************************************************************
Evolution of the component

Created by : F.GILBERT

$Log: CIL_CANToAppli_Old.c  $
Revision 1.7.1.5 2023/07/20 08:35:52CEST David Puscasu (david.puscasu) 
Run QAC after Update Traceability
Revision 1.6.3.24 2023/07/20 09:28:19EEST David Puscasu (david.puscasu) 
Update traceability
Revision 1.6.3.23 2023/07/18 09:29:40EEST David Puscasu (david.puscasu) 
Update Traceability on CIL
Revision 1.6.3.22 2023/06/08 10:52:06EEST Mihai Motoc (mihai.motoc) 
Doxygen comments updates
Revision 1.6.3.21 2023/05/25 14:30:37EEST Ioan Repede (ioan.repede) 
Update Rte_Read_CIL_SAD function call naming.
Revision 1.6.3.20 2023/05/23 13:50:10EEST Dan Dustinta (dan.dustinta) 
update mem sections
Revision 1.6.3.19 2023/05/16 12:43:41EEST Dan Dustinta (dan.dustinta) 
update b8 to u8
Revision 1.6.3.18 2023/04/20 13:59:44EEST Dan Dustinta (dan.dustinta) 
update traceability and comments
Revision 1.6.3.17 2023/04/19 09:23:30EEST Dan Dustinta (dan.dustinta) 
update traceability
Revision 1.6.3.16 2023/04/18 16:59:51EEST Dan Dustinta (dan.dustinta) 
update comments in CIL
Revision 1.6.3.15 2023/04/18 15:24:57EEST Dan Dustinta (dan.dustinta) 
add local functions
Revision 1.6.3.14 2023/03/01 14:08:20EET Septimiu Vintila (septimiu.vintila) 
Crash reading function made ASIL.
Revision 1.6.3.13 2023/03/01 11:51:54EET Septimiu Vintila (septimiu.vintila) 
ASIL function moved to FuSa section.
Revision 1.6.3.12 2023/02/28 09:17:54EET Dan Dustinta (dan.dustinta) 
add stub function
Revision 1.6.3.11 2023/02/15 10:07:34EET Septimiu Vintila (septimiu.vintila) 
QAC related code changes.
Revision 1.6.3.10 2023/02/01 14:48:46EET Ioan Repede (ioan.repede) 
Replace internal RTE connection with implementation from the RteIf module.
Revision 1.6.3.9 2023/01/31 14:16:09EET Ioan Repede (ioan.repede) 
Solving compiler warnings.
Revision 1.6.3.8 2023/01/31 13:11:22EET Ioan Repede (ioan.repede) 
Update the read method for the RTE variables regarding the diagnostic requests.
Revision 1.6.3.7 2023/01/16 13:35:03EET Septimiu Vintila (septimiu.vintila) 
Variables name changed.
Revision 1.6.3.6 2023/01/16 11:38:47EET Septimiu Vintila (septimiu.vintila) 
Fixes after review.
Revision 1.6.3.5 2023/01/12 16:12:14EET Razvan Badiu (razvan.badiu) 
add gliwa
Revision 1.6.3.4 2022/12/14 11:35:55EET Septimiu Vintila (septimiu.vintila) 
Integration for Gliwa related Tx/Rx frames.
Revision 1.6.3.3 2022/11/24 10:13:15EET Septimiu Vintila (septimiu.vintila) 
CIL implemantation.
Revision 1.2 2022/03/09 15:27:32EET Pierre-Olivier Pilot (pierre-olivier.pilot)
eCS_ECUV.005:
 Fix DIO index for Boost
 Add Enable for boost 2

eCS_ECUV.004:
 Fix ADCIF "getMeasure" value for KL30
 Fix Az offset value for +/-16g calibration
Revision 1.1 2021/08/26 08:16:53CEST Pierre-Olivier Pilot (pierre-olivier.pilot)
Initial revision
Member added to project e:/MKSProjects/SBE/Innovation/ECS/Phase_01/Components/Application/Autoliv/CIL/Implementation/src/project.pj
Revision 1.1 2020/12/08 13:59:49CET Gaetan Lievre (gaetan.lievre)
Initial revision
Member added to project e:/MKSProjects/AEM/Frame_Platforms/S32K144/Phase_01/View_Development/Components/Application/Autoliv/CIL/Implementation/src/project.pj
Revision 1.3 2020/08/14 16:22:09CEST Pierre-Olivier Pilot (pierre-olivier.pilot)
Use Autosar shortname field for the Module Trigram and the long name for the full component name (XXX_AC_TrigramExplained)
Revision 1.2 2019/10/09 16:14:29CEST Gaetan Lievre (gaetan.lievre)
Update for Nvm
Revision 1.1 2019/08/21 09:23:26CEST Nicolas Bianchi (nicolas.bianchi)
Initial revision

*****************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/
