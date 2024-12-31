
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
$Revision: 1.5 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootloader/Autoliv/SBC/Quality_Assurance/Static_Analysis/project.pj $
*/
/*!****************************************************************************

details
   This file contains the autotests of ACC module.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_SBC.h"
#include "SBC.h"
#include "SBC_Cfg.h"
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
#define SBC_START_SEC_CODE_ASIL_A
#include "SBC_MemMap.h"

/**
 * \brief
 *       This is the SBC self-test. It consists of checking the Status information section of a Spi response from the SBC chip,
 *       if one or more bits of status information are qualified within 100ms then the result of autotest will be NOK.
 * \outputparam
 *       Name: *pu8TestResult;
 *       Type: u8TestResultType;
 *       Description: The autotest test result in uint8 range;
 *       Range: 
 *          KU8_ATM_TEST_OK;
 *          KU8_ATM_TEST_NOK; 
 *          KU8_ATM_TEST_NOT_DECIDED;
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
    /* Returned status */
    u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

    /* check Status Information */
    if (KU8_ZERO != SBC_u8StatusInfoForAutotest)
    {
        SBC_u8StatusInfoForAutotest = KU8_ZERO;
        u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
    }
    else
    {
        u8ResultOfAutoTest = KU8_ATM_TEST_OK;
    }

    /* Return the auto test status */
    *pu8TestResult = u8ResultOfAutoTest;
}

/**
 * \brief
 *       This is the SBC watchdog self-test. It consists of checking the watchdog functionality from the SBC chip,
 *       If the watchdog fails to reset the ECU then the result of autotest will be NOK.
 * \outputparam
 *       Name: *pu8TestResult;
 *       Type: u8TestResultType;
 *       Description: The autotest test result in uint8 range;
 *       Range: 
 *          KU8_ATM_TEST_OK; 
 *          KU8_ATM_TEST_NOK;
 *          KU8_ATM_TEST_NOT_DECIDED;
 * \pre
 *       This function must be called in autotests.
 * \dynamicaspectcaller
 *       ATM Autotests.
 * \dynamicaspectdescription
 *       Called in Autotests via RTE layer.
 * \ddesignrequirement
 *       DSG_SBC_Autotest_WdgTest
 * \archrequirement
 *       ARCH_SW_SBC_pseSbcWdgAutotest
 *       ARCH_SW_SBC_pclResetCause_SBC_Autotest_WdgTest
 **/
void SBC_Autotest_WdgTest(u8TestResultType *pu8TestResult)
{
    u32ResetCauseType u32ResetCause;
    uint32 u32SbcStatus;
    /* Returned status */
    u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

    SBC_GetSBCStatusInformation(&u32SbcStatus);

    /* check Status Information */
    if(KU8_SBC_WDG_TEST_DECISION_PENDING == SBC_u8WdgStatusForAutotest)
    {
        Rte_Call_pclResetCause_GetResetCause(&u32ResetCause);
        if((KU32_APP_SW_WDG_TEST_NOTIFICATION_MASK == (u32ResetCause & KU32_APP_SW_WDG_TEST_NOTIFICATION_MASK)) &&
            (KU32_MCU_EXTERNAL_RESET_PIN_MASK == (u32ResetCause & KU32_MCU_EXTERNAL_RESET_PIN_MASK)) &&
            (KU32_SBC_STAT_REGS_RESTART_DUE_TO_FAIL_MASK == (u32SbcStatus & KU32_SBC_STAT_REGS_RESTART_DUE_TO_FAIL_MASK)))
        {
            u8ResultOfAutoTest = KU8_ATM_TEST_OK;
            SBC_u8WdgStatusForAutotest = KU8_SBC_WDG_TEST_OK;
            /* clear SBC autotest flag */
            SBC_u8StatusInfoForAutotest = KU8_ZERO;
        }
        else
        {
            SBC_u8WdgStatusForAutotest = KU8_SBC_WDG_TEST_NOK;
            u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
        }
    }
    else if(KU8_SBC_WDG_TEST_OK == SBC_u8WdgStatusForAutotest)
    {
        u8ResultOfAutoTest = KU8_ATM_TEST_OK;
    }
    else
    {
        u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
    }

    /* Return the auto test status */
    *pu8TestResult = u8ResultOfAutoTest;
}
#define SBC_STOP_SEC_CODE_ASIL_A
#include "SBC_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
