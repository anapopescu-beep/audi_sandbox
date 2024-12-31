
#ifndef _BSWM_CALLOUTS_H
#define _BSWM_CALLOUTS_H 1

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
   This file defines the information (interfaces, definitions and data) provided
   by the module BswM_Callouts, part of the component BswM_Callouts.

******************************************************************************/
/*
$Revision: 1.13.1.6 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/BswMIf/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Nvp_Cfg.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 * \brief
 *		BswM request mode condition
 */
#define BSWM_STARTUP_TWO_A          ((uint8) 0)
/**
 * \brief
 *		BswM request mode condition
 */
#define BSWM_READ_ALL_ON_GOING      ((uint8) 1)
/**
 * \brief
 *		BswM request mode condition
 */
#define BSWM_STARTUP_TWO_B          ((uint8) 2)
/**
 * \brief
 *		BswM request mode condition
 */
#define BSWM_WAIT_WAKEUP_VALIDATION ((uint8) 3)
/**
 * \brief
 *		BswM request mode condition
 */
#define BSWM_WAKEUP_VALIDATED       ((uint8) 4)
/**
 * \brief
 *		BswM request mode condition
 */
#define BSWM_GO_OFF_ONE_A           ((uint8) 5)
/**
 * \brief
 *		BswM request mode condition
 */
#define BSWM_GO_OFF_ONE_B           ((uint8) 6)
/**
 * \brief
 *		BswM request mode condition
 */
#define BSWM_READ_WRITE_ALL_PROCESS ((uint8) 7)
/**
 * \brief
 *		Ecu state condition
 */
#define BSWM_RUN_MODE_ACTIVE        ((uint8) 8)
/**
 * \brief
 *		Ecu state condition
 */
#define BSWM_POST_RUN_MODE_ACTIVE   ((uint8) 9)
/**
 * \brief
 *		Ecu state condition
 */
#define BSWM_LOW_PWR_MODE_ACTIVE    ((uint8) 10)
/**
 * \brief
 *		Ecu state condition
 */
#define BSWM_SHUTDOWN_MODE_ACTIVE   ((uint8) 11)
/**
 * \brief
 *		Ecu state condition
 */
#define BSWM_WAKEUP_MODE_ACTIVE     ((uint8) 12)
/**
 * \brief
 *		Passanger occupancy request mode condition
 */
#define BSWM_PASSANGER_OCCUPANCY_DETECTED      ((uint8) 13)
/**
 * \brief
 *		Passanger occupancy request mode condition
 */
#define BSWM_PASSANGER_OCCUPANCY_NOT_DETECTED  ((uint8)14)
/**
 * \brief
 *		Wakeup type request mode condition
 */
#define BSWM_ACTIVE_WAKEUP_REQ      ((uint8) 15)
/**
 * \brief
 *		Wakeup type request mode condition
 */
#define BSWM_PASSIVE_WAKEUP_REQ     ((uint8) 16)
/**
 * \brief
 *		Wakeup type request mode condition
 */
#define BSWM_NO_WAKEUP_REQ          ((uint8) 17)
/**
 * \brief
 *		Ecu state condition
 */
#define BSWM_LOW_PWR_MODE_REQUESTED ((uint8) 18)
/**
 * \brief
 *		Tx Pdu request mode condition
 */
#define BSWM_ENABLE_TX_PDU          ((uint8) 19)
/**
 * \brief
 *		Tx Pdu request mode condition
 */
#define BSWM_DISABLE_TX_PDU         ((uint8) 20)
/**
 * \brief
 *		Tx Pdu request mode condition
 */
#define BSWM_WAIT_TX_PDU            ((uint8) 21)
/**
 * \brief
 *		Ecu state condition
 */
#define BSWM_RUN_MODE_NO_COM_ACTIVE ((uint8) 22)
/**
 * \brief
 *		Ecu state condition
 */
#define BSWM_RUN_MODE_FROM_LOW_PWR  ((uint8) 23)
/**
 * \brief
 *		Ecu requested shutdown state
 */
#define BSWM_ECU_SHUTDOWN_REQUESTED ((uint8) 24)
/**
 * \brief
 *		Ecu requested shutdown state
 */
#define BSWM_ECU_SHUTDOWN_NOT_REQUESTED ((uint8) 25)
/**
 * \brief
 *		Ecu state condition
 */
#define BSWM_PROCESS_MODE_ACTIVE   ((uint8) 26)
/**
 * \brief
 *		BswM request port id number
 */
#define KU8_BSWM_REQUEST_PORT           ((uint8) 0)
/**
 * \brief
 *		External wakeup request port id number
 */
#define KU8_BSWM_PASSANGER_OCCUPANCY_REQUEST_PORT   ((uint8) 1)
/**
 * \brief
 *		Ecu state request port id number
 */
#define KU8_BSWM_ECU_STATE_REQUEST_PORT       ((uint8) 3)
/**
 * \brief
 *		Wakeup request port id number
 */
#define KU8_BSWM_REQ_WAKEUP_TYPE_REQUEST_PORT ((uint8) 4)
/**
 * \brief
 *		Tx pdu request port id number
 */
#define KU8_BSWM_TX_PDU_STATE_REQUESTED_PORT  ((uint8) 5)
/**
 * \brief
 *		Ecu Shutdown request port id number
 */
#define KU8_BSWM_ECU_SHUTDOWN_REQUESTED_PORT  ((uint8) 6)
/**
 * \brief
 *		Ecu state condition
 */
#define KU8_BSWM_INIT_STATE_ACTIVE            ((uint8) 40)
/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
extern void BswM_OnGoOffOneA(void);
extern void setTxPduToEnable(void);
extern void BswM_ProceedReset(void);
extern void BswM_MainFunction(void);
extern void BswM_OnStartupTwoA(void);
extern void BswM_OnStartupTwoB(void);
extern void BswM_OnEnableTxPdu(void);
extern void BswM_OnDisableTxPdu(void);
extern void BswM_OnRunFromLowPwr(void);
extern void BswM_OnRunFromWakeup(void);
extern void BswM_OnPostRunFromRun(void);
extern void BswM_OnRunFromPostRun(void);
extern void BswM_On_Prep_Shutdown(void);
extern void BswM_OnWakeupValidation(void);
extern void BswM_ProcessModeFromRun(void);
extern void BswM_OnStartComEffective(void);
extern void BswM_HWResetNotification(void);
extern void BswM_SWResetNotification(void);
extern void BswM_OnLowPwrFromPostRun(void);
extern void BswM_OnSleepFromShutdown(void);
extern void BswM_OnShutdownFromLowPwr(void);
extern void BswM_JumpToFBLNotification(void);
extern void BswM_ActivateWakeUpValidationProcess(void);
extern void BswM_UpdatePassangerOccupancyStatus(void);
extern void BswM_CB_NfyNvMJobEnd(uint8 NvM_CurrentServiceId, uint8 NvM_GlobalErrorStatus);
/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* _BSWM_CALLOUTS_H */
