
#ifndef I_ATM_PRIVATE
#define I_ATM_PRIVATE 1

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
   by the component ATM, part of the package <Package name>.
   These are globally visible.
   This file is intended to be included in a package header file;
   all components should include the package header file instead of this file.

******************************************************************************/
/*
$Revision: 1.3.4.8 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/ATM/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "ATM_cfg_public.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 * \brief
 *       Define used to configure the autotest to run one shot 
 *       and if the result is NOK then the execution will be frozen.
 */
#define KU8_ATM_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_ABORT     ((uint8) 0x02)
/**
 * \brief
 *       Define used to configure the autotest to run one shot 
 *       and if the result is NOK then the autotest will be run again.
 */
#define KU8_ATM_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_RETRY     ((uint8) 0x04)
/**
 * \brief
 *       Define used to configure the autotest to run one shot 
 *       and run again until the result will be OK or NOK.
 */
#define KU8_ATM_AUTO_TEST_CONFIG_TYPE_ONE_SHOT           ((uint8) 0x08)
/**
 * \brief
 *       Define used to configure the autotest to run one shot 
 *       and if the result is NOT DECIDED then the autotest will be run again.
 */
#define KU8_ATM_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_DECIDED   ((uint8) 0x10)

/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/
/*! \union ATM_stAutoTestConfigurationType ATM_private.h "inc/ATM_private.h"
 *  \brief
 *       This structure describes the constant data of a autotest.
 */
typedef struct
{
   /**
    * \brief
    *    Pointer to auto test callback.
    */
   u8TestResultType (*pfAutotestCallbackType)(void);
   /**
    * \brief
    *    The inhibiting modes mask.
    */
   uint64 u64InhibitionMask;
} ATM_stAutoTestConfigurationType;

/*! \union ATM_stCyclicListEltType ATM_private.h "inc/ATM_private.h"
 *  \brief
 *       This structure describes the constant data of a cyclic autotest.
 */
typedef struct
{
   /**
    * \brief
    *    The period of cyclic autotest (expressed in number of ATM execution occurrences).
    */
   uint16 u16Period;
   /**
    * \brief
    *    The execution offset of cyclic autotest (expressed in number of ATM execution occurrences).
    */
   uint8 u8Offset;
   /**
    * \brief
    *    The ID of autotest.
    */
   uint8 u8TestIndex;
} ATM_stCyclicListEltType;

/*! \union ATM_stStartupEltType ATM_private.h "inc/ATM_private.h"
 *  \brief
 *       This structure describes the constant data of a startup autotest.
 */
typedef struct
{
   /**
    * \brief
    *    The step period of startup autotest (expressed in number of ATM execution occurrences).
    */
   uint16 u16StepPeriod;
   /**
    * \brief
    *    The type of autotest (ONE_SHOT_ABORT, ONE_SHOT_RETRY, ONE_SHOT, ONE_SHOT_DECIDED).
    */
   uint8 u8Type;
   /**
    * \brief
    *    The ID of autotest
    */
   uint8 u8TestIndex;
} ATM_stStartupEltType;

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/
#define ATM_START_SEC_CONST_UNSPECIFIED_ASIL_A
#include "ATM_MemMap.h"

extern const ATM_stAutoTestConfigurationType ATM_kastTestConfig[ATM_KU8_NB_OF_AUTOTEST];
extern const ATM_stStartupEltType ATM_kastStartupTestSequentialList[KU8_ATM_NB_OF_STARTUP_AUTO_TESTS];
extern const ATM_stCyclicListEltType ATM_kastStartupTestCyclicList[KU8_ATM_NB_OF_STARTUP_CYCLIC_ELTS];
extern const ATM_stCyclicListEltType ATM_kastRunningCyclicList[KU8_ATM_NB_OF_RUNNING_CYCLIC_ELTS];

#define ATM_STOP_SEC_CONST_UNSPECIFIED_ASIL_A
#include "ATM_MemMap.h"

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

#endif /* I_ATM_PRIVATE */
