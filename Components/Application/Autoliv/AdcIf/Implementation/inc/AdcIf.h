#ifndef ADCIF_H_
#define ADCIF_H_ 1
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
	by the module AdcIf, part of the component AdcIf.

******************************************************************************/
/*
$Revision: 1.3.2.9 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/AdcIf/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Adc_Types.h"

#ifdef __cplusplus
extern "C" {
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
extern Adc_CalibrationStatusType ADCIF_stCalibrationStatus0;
extern Adc_CalibrationStatusType ADCIF_stCalibrationStatus1;
/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
#define AdcIf_START_SEC_CODE_ASIL_A
#include "AdcIf_MemMap.h"

/* Initialization functions */
extern void AdcIf_runInit                       (void);

/* Shutdown functions */
extern void AdcIf_runDeInit                     (void);

/* Calibraton functions */
extern void AdcIf_Calib                         (void);

/* LowPower functions */
extern void AdcIf_StopConversion                (void);
extern void AdcIf_WaitForConversion             (void);
extern void AdcIf_StartConversion               (void);

#define AdcIf_STOP_SEC_CODE_ASIL_A
#include "AdcIf_MemMap.h"

/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* ADCIF_H_ */
