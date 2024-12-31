
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
$Revision: 1.11 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/ACC/Implementation/src/project.pj $
*/
/*!****************************************************************************

details
   This file contains the autotests of ACC module.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "ACC.h"
#include "Rte_ACC.h"
#include "common.h"

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
#define ACC_START_SEC_CODE_ASIL_A
#include "ACC_MemMap.h"
/**
 * \brief
 *       This is the ACC self-test. It consists of checking if the ALARMB pin of the TDK accelerometer chip has been activated,
 *       or if any of the x, y, z axes of accelerometer have 30 consecutive identical values,
 *       or if the sequence of the ALARMB pin at initialisation is within the nominal timing parameters,
 *       or if any bit from alarm register is qualified.
 *       Also the autotest consists of checking the two bits of return status from the Spi response 
 *       and also checking if a Spi response has a wrong CRC.
 * \outputparam
 *       Name: *pu8TestResult;
 *       Type: u8TestResultType;
 *       Description: The autotest test result in uint8 range;
 *       Range: KU8_ATM_TEST_OK, KU8_ATM_TEST_NOK and KU8_ATM_TEST_NOT_DECIDED;
 * \pre
 *       This function must be called in autotests.
 * \dynamicaspectcaller
 *       ATM Autotests.
 * \dynamicaspectdescription
 *       Called in Autotests via RTE layer.
 * \constrains
 *       ADC Pheripheral must be initialised.
 * \ddesignrequirement
 *       DSG_ACC_Autotest_CheckAlarmbPin
 * \archrequirement
 *       ARCH_SW_ACC_pseCheckAccAlarmbPin
 **/
EXPORTED void ACC_Autotest_CheckAlarmbPin(u8TestResultType *pu8TestResult)
{
    /* Returned status */
    u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

    
    if ((KB_TRUE == ACC_bReturnStatusErrorFlag) 
        || (KB_TRUE == ACC_bAccelXaxisBrokenFlag) 
        || (KB_TRUE == ACC_bAccelYaxisBrokenFlag) 
        || (KB_TRUE == ACC_bAccelZaxisBrokenFlag) 
        || (KB_TRUE == ACC_bReadCrcErrorFlag) 
        || (KB_TRUE == ACC_bAlarmPresentFlag) 
        || (KB_TRUE == ACC_bAlarmbPreinitSeqFlag) 
        || (KU32_ZERO != ACC_u32AlarmRegistersUsefulData))
    {
        u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
    }
    else
    {
        u8ResultOfAutoTest = KU8_ATM_TEST_OK;
    }

    /* Return the auto test status */
    *pu8TestResult = u8ResultOfAutoTest;
}

#define ACC_STOP_SEC_CODE_ASIL_A
#include "ACC_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
