
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
$Revision: 1.1 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Scripts/Configuration_Management/EA_Detailed_Design_Generator/Sources/Tools/yFlowGen/src_code/project.pj $
*/
/*!****************************************************************************

@details
   This file contains the autotests of ACC module.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "SBC.h"
#include "Rte_SBC.h"
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
/**
 * \brief
 *       This is the SBC self-test. It consists of checking the Status information section of a Spi response from the SBC chip,
 *       if one or more bits of status information are qualified within 100ms then the result of autotest will be NOK.
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
 * \ddesignrequirement
 *       DSG_SBC_Autotest_CheckStatusInformation
 * \archrequirement
 *       ARCH_SW_SBC_pseCheckSbcStatusInfo
 **/
void SBC_Autotest_CheckStatusInformation(u8TestResultType *pu8TestResult)
{
    u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

    if (KU8_ZERO != SBC_u8StatusInfoForAutotest)
    {
        SBC_u8StatusInfoForAutotest = KU8_ZERO;
        u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
    }
    else
    {
        u8ResultOfAutoTest = KU8_ATM_TEST_OK;
    }

    *pu8TestResult = u8ResultOfAutoTest;
}

/******************************************************************************
End Of File
*****************************************************************************/
