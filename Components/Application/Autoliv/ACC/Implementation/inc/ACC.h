#ifndef ACC_H_
#define ACC_H_ 1

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
   High level module for controlling the Accelerometer chip. In charge of:
      o  Initialization;
      o  Get temperature data;
      o  Get 3 axis of accelerometer data;
******************************************************************************/
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.14 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/ACC/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Std_Types.h"
#ifdef __cplusplus
extern "C"  {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/

/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/
extern uint32 ACC_u32AlarmRegistersUsefulData;
extern boolean ACC_bAccelXaxisBrokenFlag;
extern boolean ACC_bAccelYaxisBrokenFlag;
extern boolean ACC_bAccelZaxisBrokenFlag;
extern boolean ACC_bAlarmPresentFlag;
extern boolean ACC_bReadCrcErrorFlag;
extern boolean ACC_bReturnStatusErrorFlag;
extern boolean ACC_bAlarmbPreinitSeqFlag;

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/

#define ACC_START_SEC_CODE
#include "ACC_MemMap.h"

extern void ACC_GetAccelerometerTemperature(uint16 *pu16Temperature);
extern void ACC_ReadAccelerometerTemperature(void);

#define ACC_START_SEC_CODE
#include "ACC_MemMap.h"



/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
            }
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* ACC_H_ */
