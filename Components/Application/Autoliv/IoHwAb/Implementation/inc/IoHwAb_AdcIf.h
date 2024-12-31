
#ifndef IOHWAB_ADCIF_H_
#define IOHWAB_ADCIF_H_ 1

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
by the module IoHwAb, part of the component IoHwAb.

******************************************************************************/
/*
$Revision: 1.7 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/IoHwAb/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Std_Types.h"
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 * \brief
 *      ADC 10 bits range = 1024.
 */
#define KU16_IOHWAB_ADC_10BIT_RANGE				((uint16) 1024)

/**
 * \brief
 *      ADC full range (Star12Z with 10 bit ADC peripheral).
 */
#define KU16_IOHWAB_ADC_FULL_RANGE				KU16_IOHWAB_ADC_10BIT_RANGE

/**
 * \brief
 *      ADC voltage reference = 5000 mV.
 */
#define KU16_IOHWAB_ADC_REFERENCE_MV				((uint16) 5000)

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
EXPORTED void IoHwAb_DetectVoltageFluctuation();
EXPORTED void IoHwAb_HandleSeatVariants(uint16 u16WakeCh1, uint16 u16WakeCh2, boolean *bReturn);
EXPORTED void IoHwAb_HandleSeatCurrentCircuit(uint16 *pu16WakeCh1, uint16 *pu16WakeCh2, uint8* pu8Valid, uint8 u8ResetState);
/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* IOHWAB_ADCIF_H_ */


































