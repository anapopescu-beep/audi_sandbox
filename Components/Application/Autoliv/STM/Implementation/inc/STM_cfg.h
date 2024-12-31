
#ifndef STM_CFG_H_
#define STM_CFG_H_

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
This file defines the information (interfaces, definitions and data) provided
by the component SystemTimeManagement, part of the package STM.
These are globally visible.
This file is intended to be included in a package header file;
all components should include the package header file instead of this file.
Last template change: NA
Current revision: $Revision: 1.1.2.4 $
Checked in:       $Date: 2022/11/23 06:28:27CET $
Template release date: NA
*************************************************************************/
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1.2.4 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/STM/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/*!****************************************************************************

Overview of the component :
   The aim of the STM component is to handle the System Time Management of microcontroller.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Std_Types.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/
/**
 * \brief
 *       Max ECU time offset with scale 10 ms (1s)
 */
#define KU8_MAX_ECU_TIME_OFFSET                 ((uint8) 99)
/**
 * \brief
 *       Max absolute ECU time
 */
#define KU32_MAX_ABSOLUTE_ECU_TIME              ((uint32) 0xFFFFFFFF)
/**
 * \brief
 *       Configuration define to enable Read absolute system time API
 */
#define KU8_STM_ENABLE_READ_ABS_SYS_TIME_API    (STD_ON)
/**
 * \brief
 *       Configuration define to enable Read relative system time API
 */
#define KU8_STM_ENABLE_READ_REL_SYS_TIME_API    (STD_OFF)
/**
 * \brief
 *       Configuration define to enable Write relative system time API
 */
#define KU8_STM_ENABLE_WRITE_REL_SYS_TIME_API   (STD_OFF)
/**
 * \brief
 *       Configuration define to enable Write absolute system time API
 */
#define KU8_STM_ENABLE_WRITE_ABS_SYS_TIME_API   (STD_OFF)
/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* STM_CFG_H_ */
