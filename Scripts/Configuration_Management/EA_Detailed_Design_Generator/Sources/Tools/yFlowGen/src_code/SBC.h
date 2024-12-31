#ifndef SBC_H_
#define SBC_H_ 1

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
   High level module for controlling the SBC chip. In charge of:
      - Initialization
      - Shutdown
      - Cyclic monitor and WD refresh
      - Sleep
      - Normal mode
      - Low Power
      - Reset
******************************************************************************/
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Scripts/Configuration_Management/EA_Detailed_Design_Generator/Sources/Tools/yFlowGen/src_code/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Std_Types.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 * \brief
 *       Can wake up mask.
 */
#define KU8_SBC_MASK_CAN_WU                          ((uint8)0x10)
/**
 * \brief
 *       VS Under-Voltage mask.
 */
#define KU8_SBC_MASK_VS_UNDER_VOLTAGE                ((uint8)0x08)
/**
 * \brief
 *       Power on Reset mask.
 */
#define KU8_SBC_MASK_POWER_ON_RESET                  ((uint8)0x04)
/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/
extern uint8 SBC_u8StatusInfoForAutotest;

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
extern void SBC_Init(void);
extern void SBC_Shutdown(void);
extern void SBC_runMainFunction(void);
extern void SBC_sleepTriggerWatchdog(void);
extern void SBC_SetToNormal(void);
extern void SBC_SetToLowPower(void);
extern void SBC_Reset(void);
extern void SBC_GetSBCStatusInformation(uint8 * u8StatusInformation);
extern void SBC_ForceExternalWatchdogReset(void);

/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
           }
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* SBC_H_ */
