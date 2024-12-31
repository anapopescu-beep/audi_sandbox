/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------------------------------------------------

Copyright Autoliv Inc. All rights reserved.

 *******************************************************************************
H-File Template Version: 
Template version: AEM_PROCESS_1.25.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2022-09
 *******************************************************************************

Overview of the interfaces:
   This file is intended to handle DiagOnCAN services.

 ******************************************************************************/
/**
 *    $Revision: 1.1.12.20 $
 *    $ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/DIA/Implementation/inc/project.pj $
 */

/******************************************************************************

details
   This file is intended to handle DiagOnCAN services.

 ******************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "BswM_Callouts.h"
/******************************************************************************
DEFINITION OF CONSTANTS
 ******************************************************************************/
/**
 * \brief
 *    Overvoltage condition
 */
#define KU8_DIA_OVERVOLTAGE                                        ((uint8)0x9A)
/**
 * \brief
 *    Undervoltage condition
 */
#define KU8_DIA_UNDERVOLTAGE                                       ((uint8)0x0A)
/**
 * \brief
 *    Offset RequestedRamSizeArray
 */
#define KU8_DIA_OFFSET_REQUESTED_RAM_SIZE_ARRAY                   ((uint8) 0x3C)
/**
 * \brief
 *    Tx Timeout
 */
#define KU32_DIA_TX_TIMEOUT                                       ((uint32) 1000)
/******************************************************************************
DECLARATION OF TYPES
 ******************************************************************************/

/******************************************************************************
DECLARATION OF VARIABLES
 ******************************************************************************/
#define DIA_START_SEC_VAR_INIT_8
#include "DIA_MemMap.h"

extern uint8 DIA_u8ManageNVPBlockWritingStatus;
extern uint8 DIA_u8BootTpSize;

#define DIA_STOP_SEC_VAR_INIT_8
#include "DIA_MemMap.h"
/******************************************************************************
DECLARATION OF CONSTANT DATA
 ******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
 ******************************************************************************/
#define DIA_START_SEC_CODE
#include "DIA_MemMap.h"

extern void DIA_SecurityAccess_Init(void);
extern void DIA_CopyData(uint8 * const pku8Destination, const uint8* const kpku8Source, const uint16 ku16DataLength);
extern void DIA_CopyDataSwap(uint8* const pku8Destination, const uint8* const kpku8Source, const uint16 ku16DataLength);
extern uint8 DIA_ManageNVPBlockWriting(NvM_ASR42_BlockIdType u16BlockID, const uint8 *kpu8Data);
extern void DIA_Init(void);
extern void DIA_CopyDataSwap32(uint8* const pku8Destination, const uint8* const kpku8Source, const uint16 ku16DataLength);

#define DIA_STOP_SEC_CODE
#include "DIA_MemMap.h"
/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
 ******************************************************************************/

/******************************************************************************
Evolution of the component

 created by : T. DEMIREL

 $Log: DIA.h  $
 Revision 1.1.12.20 2023/07/11 15:59:58CEST Andreea Suiu (andreea.suiu) 
 update comments, update 0236 write
 Revision 1.1.12.19 2023/06/22 14:07:17EEST Andreea Suiu (andreea.suiu) 
 update src files (fix findings) after review
 Revision 1.1.12.18 2023/06/20 14:55:03EEST Andreea Suiu (andreea.suiu) 
 remove global variables
 Revision 1.1.12.17 2023/06/19 18:23:49EEST Andreea Suiu (andreea.suiu) 
 update 0236 read
 Revision 1.1.12.16 2023/06/12 09:16:26EEST Mihai Motoc (mihai.motoc) 
 Doxygen comments updates
 Revision 1.1.12.15 2023/04/25 09:13:04EEST Andreea Suiu (andreea.suiu) 
 Fix DIA after review
 Revision 1.1.12.14 2023/04/18 18:22:03EEST Andreea Suiu (andreea.suiu) 
 Update DIA module according to the coding rules
 Revision 1.1.12.13 2023/04/18 18:08:10EEST Andreea Suiu (andreea.suiu) 
 Update DIA module according to the coding rules
 Revision 1.1.12.12 2023/03/15 10:15:35EET Andreea Suiu (andreea.suiu) 
 Add OEM diagnostics
 Revision 1.1.12.11 2023/02/28 18:06:14EET Septimiu Vintila (septimiu.vintila) 
 FuSa section reverted to normal one.
 Revision 1.1.12.10 2023/02/28 17:15:03EET Septimiu Vintila (septimiu.vintila) 
 Data sections changed to FuSa data sections.
 Revision 1.1.12.9 2023/02/28 16:35:53EET Septimiu Vintila (septimiu.vintila) 
 Code sections changed to FuSa code sections.
 Revision 1.1.12.8 2023/02/22 20:35:45EET Gabriel Brasoveanu (gabriel.brasoveanu) 
 Update after QAC analysis
 Revision 1.1.12.7 2023/02/16 09:16:03EET Andreea Suiu (andreea.suiu) 
 Update Dcm and DIA module (programming response fixed, incorrect transition between session fixed)
 Revision 1.1.12.6 2023/01/23 16:10:27EET Denis Folea (denis.folea) 
 DIA fix after review
 Revision 1.1.12.5 2023/01/20 15:24:06EET Denis Folea (denis.folea) 
 DIA fix after review
 Revision 1.1.12.4 2022/12/22 16:28:58EET Andrei Anca (andrei.anca) 
 Dia cleanup
 Revision 1.1.12.3 2022/11/25 12:47:59EET Dan Dustinta (dan.dustinta) 
 update DCM integration code
 Revision 1.1 2021/08/26 09:16:55EEST Pierre-Olivier Pilot (pierre-olivier.pilot) 
 Initial revision
 Member added to project e:/MKSProjects/SBE/Innovation/ECS/Phase_01/Components/Application/Autoliv/DIA/Implementation/inc/project.pj


 ******************************************************************************/

/******************************************************************************
End Of File
 *****************************************************************************/
