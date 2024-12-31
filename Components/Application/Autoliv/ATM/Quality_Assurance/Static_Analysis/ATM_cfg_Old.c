
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
$Revision: 1.2.3.14 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/ATM/Quality_Assurance/Static_Analysis/project.pj $
*/
/*!****************************************************************************

Overview of the component :
   The AutoTests manager (ATM) function schedules autotests and manages
   the reported failures. An autotest is defined as a procedure that checks
   functions and returns status.
   The ATM mainly calls autotests implemented in hardware management modules.
   It is itself timed by the Scheduler or OS.
   Autotests list also includes RAM and ROM test.

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_ATM.h"
#include "ATM_private.h"
#include "Common.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *       Delimiter used between lists.
 *       Indicates to the ATM main function to continue with its current indexes.
 */
#define  KST_ATM_END_OF_SUB_LIST                    (uint16) 0, (uint8) 1, (uint8) 0
/**
 * \brief
 *       Delimiter used to terminate the  list. Indicates to the ATM main function
 *       to loop back to the first list and reset all its indexes.
 */
#define  KST_ATM_END_OF_THE_WHOLE_LIST              (uint16) 0, (uint8) 0, (uint8) 0
/* 'decade' argument value for macro above */
/**
 * \brief
 *       Decade value used for macros - example: KST_ATM_PERIODIC_100_MS(KU8_ATM_IN_DECADE_0)
 */
#define  KU8_ATM_IN_DECADE_0                     ((uint8) 0)
/**
 * \brief
 *       Decade value used for macros - example: KST_ATM_PERIODIC_100_MS(KU8_ATM_IN_DECADE_1)
 */
#define  KU8_ATM_IN_DECADE_1                     ((uint8) 1)
/**
 * \brief
 *       Decade value used for macros - example: ATM_KU8_PERIODIC_1_S(KU8_ATM_IN_DECADE_2)
 */
#define  KU8_ATM_IN_DECADE_2                     ((uint8) 2)

/**
 * \brief
 *       Decade argument value for macro to set periodicity to 1ms.
 */
#define  KU16_ATM_STEP_EVERY_1MS                 ((uint16) 0)
/**
 * \brief
 *       Decade argument value for macro to set periodicity to 2ms.
 */
#define  KU16_ATM_STEP_EVERY_2MS                 ((uint16) 1)
/**
 * \brief
 *       Decade argument value for macro to set periodicity to 10ms.
 */
#define  KU16_ATM_STEP_EVERY_10MS                ((uint16) 9)
/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/
/* Main timing Auto tests parameters macros,*/
/*(considering the ATM main function execution period is 2ms) */
/**
 * \brief
 *       Main timing (5 ms) Auto tests manager parameters macros,
 *       to be used in "castATMConfig" definition
 */
#define  KST_ATM_PERIODIC_5_MS                 (uint16) 1, (uint8) 0
/**
 * \brief
 *       Main timing (10 ms) Auto tests manager parameters macros,
 *       to be used in "castATMConfig" definition
 */
#define  KST_ATM_PERIODIC_10_MS(decade)                 (uint16) 2, (decade)
/**
 * \brief
 *       Main timing (100 ms) Auto tests manager parameters macros,
 *       to be used in "castATMConfig" definition
 */
#define  KST_ATM_PERIODIC_100_MS(decade)        (uint16) 20, (decade)
/**
 * \brief
 *       Main timing (1s) Auto tests manager parameters macros,
 *       to be used in "castATMConfig" definition
 */
#define  KST_ATM_PERIODIC_1_S(decade)           (uint16) 200, (decade)

/**
 * \brief
 *       The autotest is periodically called until its result is OK or NOK.
 *       It is considered as finished only when its result is OK or NOK.
 */
#define  KST_ATM_ONE_SHOT_ABORT(step_period)    (step_period), KU8_ATM_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_ABORT
/**
 * \brief
 *       The autotest is periodically called until its result is OK.
 *       It is considered as finished only when its result is OK.
 */
#define  KST_ATM_ONE_SHOT_RETRY(step_period)    (step_period), KU8_ATM_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_RETRY
/**
 * \brief
 *       The autotest is called only once and it is considered as finished whatever its result is : OK, NOK, NotDecided
 */
#define  KST_ATM_ONE_SHOT(step_period)          (step_period), KU8_ATM_AUTO_TEST_CONFIG_TYPE_ONE_SHOT
/**
 * \brief
 *       The autotest is periodically called until its result is OK, NOK or NOT DECIDED.
 *       It is considered as finished only when its result is OK,  NOK or NOT DECIDED.
 */
#define  KST_ATM_ONE_SHOT_DECIDED(step_period)  (step_period), KU8_ATM_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_DECIDED

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
LOCAL u8TestResultType atm_cbk_CheckAdc(void);
LOCAL u8TestResultType atm_cbk_CheckAdcCalib(void);
LOCAL u8TestResultType atm_cbk_RunResetCause_RCM_Autotest(void);
LOCAL u8TestResultType atm_cbk_RunEepromMemoryNotProgrammed_NVMIF_Autotest(void);
LOCAL u8TestResultType atm_cbk_RunEepromMemoryCorruption_MIC_Autotest(void);
LOCAL u8TestResultType atm_cbk_RunPFlashMemoryCorruption_MIC_Autotest(void);
LOCAL u8TestResultType atm_cbk_RunRamMemoryCorruption_MIC_Autotest(void);
LOCAL u8TestResultType atm_cbk_runOverTemperature(void);
LOCAL u8TestResultType atm_cbk_runExtWDTest(void);
LOCAL u8TestResultType atm_cbk_CheckPowerSupplyUV(void);
LOCAL u8TestResultType atm_cbk_CheckPowerSupplyOV(void);
LOCAL u8TestResultType atm_cbk_CheckActuatorStuck(void);
LOCAL u8TestResultType atm_cbk_CheckShortToVBAT(void);
LOCAL u8TestResultType atm_cbk_CheckShortToGND(void);
LOCAL u8TestResultType atm_cbk_CheckOpenCircuit(void);
LOCAL u8TestResultType atm_cbk_CheckMcuSelfTest(void);
LOCAL u8TestResultType atm_cbk_CheckAccAlarmbPin(void);
LOCAL u8TestResultType atm_cbk_CheckSbcStatusInfo(void);
LOCAL u8TestResultType atm_cbk_CheckBatteryUnstable(void);
LOCAL u8TestResultType atm_cbk_CheckPowerStageFailiure(void);
LOCAL u8TestResultType atm_cbk_CheckSolenoidOvervoltage(void);
LOCAL u8TestResultType atm_cbk_CheckMcuCrcRegisterStatus(void);
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
#define ATM_START_SEC_CONST_UNSPECIFIED_ASIL_A
#include "ATM_MemMap.h"

/**
 * \brief
 *       This array configures autotests common attributes and store the test ID for autotes:
 *       Pointer to text execution function.
 *       The inhibition mask.
 */
EXPORTED const ATM_stAutoTestConfigurationType  ATM_kastTestConfig[ATM_KU8_NB_OF_AUTOTEST] =
{
/* ----------------------------------------------------------------------------------------------------------------------------------------- */
/*               autotest ID                 |            autotest executing function                  | mode mask for inhibition            */
/* ----------------------------------------------------------------------------------------------------------------------------------------- */
/* 0 : ATM_KU8_ID_TEST_ADC_OUT_OF_ORDER     */ { &atm_cbk_CheckAdc,                                      KU64_NVM_BLOCK_RESTORE_IN_PROGRESS  },
/* 1 : ATM_KU8_ID_PFLASH_MEMORY_CORRUPTION  */ { &atm_cbk_RunPFlashMemoryCorruption_MIC_Autotest,        KU32_ZERO                           },
/* 2 : ATM_KU8_ID_NVM_NOT_PROG              */ { &atm_cbk_RunEepromMemoryNotProgrammed_NVMIF_Autotest,   KU64_NVM_BLOCK_RESTORE_IN_PROGRESS  },
/* 3 : ATM_KU8_ID_NVM_MEMORY_CORRUPTION     */ { &atm_cbk_RunEepromMemoryCorruption_MIC_Autotest,        KU32_ZERO                           },
/* 4 : ATM_KU8_ID_RAM_MEMORY_CORRUPTION     */ { &atm_cbk_RunRamMemoryCorruption_MIC_Autotest,           KU32_ZERO                           },
/* 5 : ATM_KU8_ID_RESET_CAUSE               */ { &atm_cbk_RunResetCause_RCM_Autotest,                    KU32_ZERO                           },
/* 6 : ATM_KU8_ID_TEST_ADC_CALIB            */ { &atm_cbk_CheckAdcCalib,                                 KU64_NVM_BLOCK_RESTORE_IN_PROGRESS  },
/* 7 : ATM_KU8_ID_TEST_ECU_OVER_TEMPERATURE */ { &atm_cbk_runOverTemperature,                            KU64_NVM_BLOCK_RESTORE_IN_PROGRESS  },
/* 8 : ATM_KU8_ID_EXT_WDG_OUT_OF_ORDER      */ { &atm_cbk_runExtWDTest,                                  KU32_ZERO                           },
/* 9  : ATM_KU8_ID_POWER_SUPPLY_UV          */ { &atm_cbk_CheckPowerSupplyUV,                            KU64_NVM_BLOCK_RESTORE_IN_PROGRESS  },
/* 10 : ATM_KU8_ID_POWER_SUPPLY_OV          */ { &atm_cbk_CheckPowerSupplyOV,                            KU64_NVM_BLOCK_RESTORE_IN_PROGRESS  },
/* 11 : ATM_KU8_ID_ACTUATOR_STUCK           */ { &atm_cbk_CheckActuatorStuck,                            KU32_ZERO                           },
/* 12 : ATM_KU8_ID_OPEN_CIRCUIT             */ { &atm_cbk_CheckOpenCircuit,                              KU64_NVM_BLOCK_RESTORE_IN_PROGRESS  },
/* 13 : ATM_KU8_ID_SHORT_TO_GND             */ { &atm_cbk_CheckShortToGND,                               KU64_NVM_BLOCK_RESTORE_IN_PROGRESS  },
/* 14 : ATM_KU8_ID_SHORT_TO_VBAT            */ { &atm_cbk_CheckShortToVBAT,                              KU64_NVM_BLOCK_RESTORE_IN_PROGRESS  },
/* 15 : ATM_KU8_ID_MCU_SELFTEST             */ { &atm_cbk_CheckMcuSelfTest,                              KU32_ZERO                           },
/* 16 : ATM_KU8_ID_ACC_CHECK_ALARMB         */ { &atm_cbk_CheckAccAlarmbPin,                             KU32_ZERO                           },
/* 17 : ATM_KU8_ID_SBC_CHECK_STATUS_INFO    */ { &atm_cbk_CheckSbcStatusInfo,                            KU32_ZERO                           },
/* 18 : ATM_KU8_ID_ECU_BATTERY_UNSTABLE     */ { &atm_cbk_CheckBatteryUnstable,                          KU64_ECU_BATTERY_UNSTABLE           },
/* 19 : ATM_KU8_ID_SOLENOID_OVERVOLTAGE     */ { &atm_cbk_CheckSolenoidOvervoltage,                      KU64_NVM_BLOCK_RESTORE_IN_PROGRESS  },
/* 20 : ATM_KU8_ID_POWER_STAGE_FAULT        */ { &atm_cbk_CheckPowerStageFailiure,                       KU64_NVM_BLOCK_RESTORE_IN_PROGRESS  },
/* 21 : ATM_KU8_ID_MCU_CRC_REGISTERS        */ { &atm_cbk_CheckMcuCrcRegisterStatus,                     KU64_NVM_BLOCK_RESTORE_IN_PROGRESS  },
/* ----------------------------------------------------------------------------------------------------------------------------------------- */
};

/**
 * \brief
 *       This array of "one shot" tests is run once at startup.
 *       Each test is run only after the previous one completion.
 */
EXPORTED const ATM_stStartupEltType ATM_kastStartupTestSequentialList[KU8_ATM_NB_OF_STARTUP_AUTO_TESTS] =
{
   /* -------------------------------------------------------------------------------------------------------------- */
   /*          autotest step period and type                          |              autotest ID                     */
   /* -------------------------------------------------------------------------------------------------------------- */
   { KST_ATM_ONE_SHOT_DECIDED(KU16_ATM_STEP_EVERY_2MS),                 ATM_KU8_ID_EXT_WDG_OUT_OF_ORDER              },
   { KST_ATM_ONE_SHOT_ABORT(KU16_ATM_STEP_EVERY_10MS),                  ATM_KU8_ID_PFLASH_MEMORY_CORRUPTION          },
   { KST_ATM_ONE_SHOT(KU16_ATM_STEP_EVERY_10MS),                        ATM_KU8_ID_NVM_MEMORY_CORRUPTION             },
   { KST_ATM_ONE_SHOT_ABORT(KU16_ATM_STEP_EVERY_10MS),                  ATM_KU8_ID_RAM_MEMORY_CORRUPTION             },
   { KST_ATM_ONE_SHOT_DECIDED(KU16_ATM_STEP_EVERY_10MS),                ATM_KU8_ID_RESET_CAUSE                       },
   { KST_ATM_ONE_SHOT_RETRY(KU16_ATM_STEP_EVERY_1MS),                   ATM_KU8_ID_TEST_ADC_OUT_OF_ORDER             },
   { KST_ATM_ONE_SHOT(KU16_ATM_STEP_EVERY_10MS),                        ATM_KU8_ID_TEST_ADC_CALIB                    },
   { KST_ATM_ONE_SHOT_DECIDED(KU16_ATM_STEP_EVERY_10MS),                ATM_KU8_ID_NVM_NOT_PROG                      },
   { KST_ATM_ONE_SHOT_RETRY(KU16_ATM_STEP_EVERY_10MS),                  ATM_KU8_ID_ECU_BATTERY_UNSTABLE              },
   /* -------------------------------------------------------------------------------------------------------------- */
};

/**
 * \brief
 *       This table of startup cyclic tests is run in parallel with the "one shot" tests list.
 */
EXPORTED const ATM_stCyclicListEltType ATM_kastStartupTestCyclicList[KU8_ATM_NB_OF_STARTUP_CYCLIC_ELTS] =
{
   /* Start Of Test List Executed during the 1st Time Slot */
   { KST_ATM_PERIODIC_10_MS (KU8_ATM_IN_DECADE_0),   ATM_KU8_ID_POWER_SUPPLY_UV  },
   { KST_ATM_END_OF_SUB_LIST                                                     },

   /* Start Of Test List Executed during the 2nd Time Slot */
   { KST_ATM_PERIODIC_10_MS (KU8_ATM_IN_DECADE_0),   ATM_KU8_ID_POWER_SUPPLY_OV  },
   { KST_ATM_END_OF_SUB_LIST                                                     },

   /* Start Of Test List Executed during the 3rd Time Slot */
   { KST_ATM_END_OF_SUB_LIST                                                     },

   /* Start Of Test List Executed during the 4th Time Slot */
   { KST_ATM_END_OF_SUB_LIST                                                     },

   /* Start Of Test List Executed during the 5th Time Slot */
   { KST_ATM_END_OF_THE_WHOLE_LIST                                               }
};

/**
 * \brief
 *       This table of running cyclic tests is run in parallel with the "one shot" tests list.
 */
EXPORTED const ATM_stCyclicListEltType ATM_kastRunningCyclicList[KU8_ATM_NB_OF_RUNNING_CYCLIC_ELTS] =
{
   /* Start Of Test List Executed during the 1st Time Slot */
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_TEST_ADC_OUT_OF_ORDER       },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_ACC_CHECK_ALARMB            },
   { KST_ATM_PERIODIC_10_MS (KU8_ATM_IN_DECADE_1),      ATM_KU8_ID_SBC_CHECK_STATUS_INFO       },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_SHORT_TO_VBAT               },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_OPEN_CIRCUIT                },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_MCU_SELFTEST                },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_SHORT_TO_GND                },
   { KST_ATM_END_OF_SUB_LIST                                                                   },

   /* Start Of Test List Executed during the 2nd Time Slot */
   { KST_ATM_PERIODIC_10_MS (KU8_ATM_IN_DECADE_0),      ATM_KU8_ID_POWER_SUPPLY_UV             },
   { KST_ATM_PERIODIC_10_MS (KU8_ATM_IN_DECADE_1),      ATM_KU8_ID_SOLENOID_OVERVOLTAGE        },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_TEST_ADC_OUT_OF_ORDER       },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_ACC_CHECK_ALARMB            },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_SHORT_TO_VBAT               },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_OPEN_CIRCUIT                },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_SHORT_TO_GND                },
   { KST_ATM_END_OF_SUB_LIST                                                                   },

   /* Start Of Test List Executed during the 3rd Time Slot */
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_TEST_ADC_OUT_OF_ORDER       },
   { KST_ATM_PERIODIC_10_MS (KU8_ATM_IN_DECADE_0),      ATM_KU8_ID_ACTUATOR_STUCK              },
   { KST_ATM_PERIODIC_10_MS (KU8_ATM_IN_DECADE_1),      ATM_KU8_ID_POWER_STAGE_FAULT           },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_ACC_CHECK_ALARMB            },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_SHORT_TO_VBAT               },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_OPEN_CIRCUIT                },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_SHORT_TO_GND                },
   { KST_ATM_END_OF_SUB_LIST                                                                   },

   /* Start Of Test List Executed during the 4th Time Slot */
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_SHORT_TO_GND                },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_TEST_ADC_OUT_OF_ORDER       },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_ACC_CHECK_ALARMB            },
   { KST_ATM_PERIODIC_10_MS (KU8_ATM_IN_DECADE_0),		ATM_KU8_ID_MCU_CRC_REGISTERS		   },
   { KST_ATM_PERIODIC_10_MS (KU8_ATM_IN_DECADE_1),      ATM_KU8_ID_POWER_SUPPLY_OV             },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_SHORT_TO_VBAT               },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_OPEN_CIRCUIT                },
   { KST_ATM_END_OF_SUB_LIST                                                                   },

   /* Start Of Test List Executed during the 5th Time Slot */
   { KST_ATM_PERIODIC_5_MS                        ,     ATM_KU8_ID_TEST_ADC_OUT_OF_ORDER       },
   { KST_ATM_PERIODIC_100_MS (KU8_ATM_IN_DECADE_1),     ATM_KU8_ID_TEST_ECU_OVER_TEMPERATURE   },
   { KST_ATM_PERIODIC_5_MS                        ,     ATM_KU8_ID_ACC_CHECK_ALARMB            },
   { KST_ATM_PERIODIC_5_MS                        ,     ATM_KU8_ID_SHORT_TO_VBAT               },
   { KST_ATM_PERIODIC_5_MS                        ,     ATM_KU8_ID_OPEN_CIRCUIT                },
   { KST_ATM_PERIODIC_5_MS                       ,      ATM_KU8_ID_SHORT_TO_GND                },
   { KST_ATM_END_OF_THE_WHOLE_LIST                                                             }
};
#define ATM_STOP_SEC_CONST_UNSPECIFIED_ASIL_A
#include "ATM_MemMap.h"

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
#define ATM_START_SEC_CODE_ASIL_A
#include "ATM_MemMap.h"

/**
* \brief
*        Callback of Rte_Call_pclCheckAdc autotest to check ADC.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_CheckAdc
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction;
*        ARCH_SW_pclCheckAdc;
**/
LOCAL u8TestResultType atm_cbk_CheckAdc(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;
   Rte_Call_pclCheckAdc_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
* \brief
*        Callback of Rte_Call_pclCheckAdcCalib autotest to check ADC calibration.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_CheckAdcCalib
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction;
*        ARCH_SW_pclCheckAdcCalib;
**/
LOCAL u8TestResultType atm_cbk_CheckAdcCalib(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;
   Rte_Call_pclCheckAdcCalib_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
* \brief
*        Callback of Rte_Call_pclRunResetCause autotest
*        to check if an unexpected reset cause has been detected.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_RunResetCause_RCM_Autotest
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction;
*        ARCH_SW_pclRunResetCause;
**/
LOCAL u8TestResultType atm_cbk_RunResetCause_RCM_Autotest(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;
   Rte_Call_pclRunResetCause_AutotestCallback(&u8TestResult);

   return u8TestResult; 
}

/**
* \brief
*        Callback of Rte_Call_pclRunEepromMemoryNotProgrammed autotest
*        to check if the EEPROM write was performed correctly.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_RunEepromMemoryNotProgrammed_NVMIF_Autotest
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction;
*        ARCH_SW_pclRunEepromMemoryNotProgrammed;
**/
LOCAL u8TestResultType atm_cbk_RunEepromMemoryNotProgrammed_NVMIF_Autotest(void)
{
   /* For this autotest is mandatory to initialize u8TestResult with KU8_ATM_TEST_NOT_DECIDED
   because the KU8_ATM_TEST_NOK value is used in the autotest function as a flag to terminate execution and return NOK*/
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOT_DECIDED;
   Rte_Call_pclRunEepromMemoryNotProgrammed_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
* \brief
*        Callback of automatic test Rte_Call_pclRunEepromMemoryCorruption
*        to check if an unexpected EEPROM error occurred during runtime execution.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_RunEepromMemoryCorruption_MIC_Autotest
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction;
*        ARCH_SW_pclRunEepromMemoryCorruption;
**/
LOCAL u8TestResultType atm_cbk_RunEepromMemoryCorruption_MIC_Autotest(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;
   Rte_Call_pclRunEepromMemoryCorruption_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
* \brief
*        Callback of Rte_Call_pclRunPFlashMemoryCorruption autotest
*        to check if an unexpected PFlash error occurred during runtime execution.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_RunPFlashMemoryCorruption_MIC_Autotest
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction;
*        ARCH_SW_pclRunPFlashMemoryCorruption;
**/
LOCAL u8TestResultType atm_cbk_RunPFlashMemoryCorruption_MIC_Autotest(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;
   Rte_Call_pclRunPFlashMemoryCorruption_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
* \brief
*        Callback of Rte_Call_pclRunRamMemoryCorruption AutoTest
*        to check if an unexpected RAM error occurred during runtime execution.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_RunRamMemoryCorruption_MIC_Autotest
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction;
*        ARCH_SW_pclRunRamMemoryCorruption;
**/
LOCAL u8TestResultType atm_cbk_RunRamMemoryCorruption_MIC_Autotest(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;
   Rte_Call_pclRunRamMemoryCorruption_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
* \brief
*        Callback of Rte_Call_pclEcuOverTemperature AutoTest.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_runOverTemperature
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction;
*        ARCH_SW_pclEcuOverTemperature;
**/
LOCAL u8TestResultType atm_cbk_runOverTemperature(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;
   Rte_Call_pclEcuOverTemperature_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
* \brief
*        Callback of Rte_Call_pclRunExtWDTest AutoTest.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_runExtWDTest
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction;
*        ARCH_SW_pclEvtExtWdgOutOfOrder;
**/
LOCAL u8TestResultType atm_cbk_runExtWDTest(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;
   Rte_Call_pclRunExtWDTest_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
* \brief
*        Callback of Rte_Call_pclCheckPowerSupplyUV AutoTest.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_CheckPowerSupplyUV
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction;
*        ARCH_SW_pclCheckPowerSupplyUV;
**/
LOCAL u8TestResultType atm_cbk_CheckPowerSupplyUV(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;
   Rte_Call_pclCheckPowerSupplyUV_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
* \brief
*        Callback of Rte_Call_pclCheckPowerSupplyOV AutoTest.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_CheckPowerSupplyOV
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction;
*        ARCH_SW_pclCheckPowerSupplyOV;
**/
LOCAL u8TestResultType atm_cbk_CheckPowerSupplyOV(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;
   Rte_Call_pclCheckPowerSupplyOV_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
* \brief
*        Callback of Rte_Call_pclCheckActuatorState AutoTest.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_CheckActuatorStuck
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction;
*        ARCH_SW_pclCheckActuatorState;
**/
LOCAL u8TestResultType atm_cbk_CheckActuatorStuck(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;
   Rte_Call_pclCheckActuatorState_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
* \brief
*        Callback of Rte_Call_pclCheckShortToVBAT_AutotestCallback_Solenoid AutoTest.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_CheckShortToVBAT
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction;
*        ARCH_SW_pclCheckShortToVBAT;
**/
LOCAL u8TestResultType atm_cbk_CheckShortToVBAT(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;
   Rte_Call_pclCheckShortToVBAT_AutotestCallback(&u8TestResult);

   return u8TestResult;

}

/**
* \brief
*        Callback of Rte_Call_pclCheckShortToGND_AutotestCallback_Solenoid AutoTest.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_CheckShortToGND
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction;
*        ARCH_SW_pclCheckShortToGND;
**/
LOCAL u8TestResultType atm_cbk_CheckShortToGND(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;
   Rte_Call_pclCheckShortToGND_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
* \brief
*        Callback of Rte_Call_pclCheckOpenCircuit_AutotestCallback_Solenoid AutoTest.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_CheckOpenCircuit
* \archrequirement
*        ARCH_SW_ATM_pclCheckOpenCircuit_ATM_runMainFunction;
*        ARCH_SW_pclCheckOpenCircuit
**/
LOCAL u8TestResultType atm_cbk_CheckOpenCircuit(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;
   Rte_Call_pclCheckOpenCircuit_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
* \brief
*        Callback of Mcu selftest AutoTest.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_CheckMcuSelfTest
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction
*        ARCH_SW_pclCheckMcuSelfTest
**/
LOCAL u8TestResultType atm_cbk_CheckMcuSelfTest(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;
   Rte_Call_pclCheckMcuSelfTest_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
* \brief
*        Callback of Rte_Call_pclCheckAccAlarmbPin_AutotestCallback AutoTest.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_CheckAccAlarmbPin
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction;
*        ARCH_SW_pclCheckAccAlarmbPin;
**/
LOCAL u8TestResultType atm_cbk_CheckAccAlarmbPin(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;
   Rte_Call_pclCheckAccAlarmbPin_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
* \brief
*        Callback of Rte_Call_pclCheckSbcStatusInfo_AutotestCallback AutoTest.
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_CheckSbcStatusInfo
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction;
*        ARCH_SW_pclCheckSbcStatusInfo;
**/
LOCAL u8TestResultType atm_cbk_CheckSbcStatusInfo(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;

   Rte_Call_pclCheckSbcStatusInfo_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
* \brief
*        Dummy auto-test used to delay initialization if KL30 < specified threshold
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_CheckBatteryUnstable
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction
**/
LOCAL u8TestResultType atm_cbk_CheckBatteryUnstable(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_OK;

   return u8TestResult;
}

/**
* \brief
*        Auto-test for checking overvoltage condition voltage on each solenoid
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_CheckSolenoidOvervoltage
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction
*        ARCH_SW_pclCheckSolenoidOvervoltage
**/
LOCAL u8TestResultType atm_cbk_CheckSolenoidOvervoltage(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;

   (void)Rte_Call_pclCheckSolenoidOvervoltage_AutotestCallback(&u8TestResult);

   return u8TestResult;
}

/**
* \brief
*        Auto-test callback for checking the power stage
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_CheckPowerStageFailiure
* \archrequirement
*        ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction
*        ARCH_SW_pclCheckPowerStage
**/
LOCAL u8TestResultType atm_cbk_CheckPowerStageFailiure(void)
{
   u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;

   (void)Rte_Call_pclCheckPowerStage_AutotestCallback(&u8TestResult);

   return u8TestResult;
}
/**
* \brief
*        Auto-test callback for checking the MCU CRC registers
* \return
*        The result of autotest.
* \dynamicaspectcaller
*        ATM module (locally).
* \dynamicaspectdescription
*        Called in other function through ATM_kastTestConfig array with pointers to functions.
* \ddesignrequirement
*        DSG_atm_cbk_CheckMcuCrcRegisterStatus
* \archrequirement
* 		 ARCH_SW_BswMIf_ptrpAtmServicesAsrOs_ATM_runMainFunction
*		 ARCH_SW_pclCheckCrcOnMcuRegisters
**/
LOCAL u8TestResultType atm_cbk_CheckMcuCrcRegisterStatus(void)
{
	u8TestResultType u8TestResult = KU8_ATM_TEST_NOK;

	Rte_Call_pclCheckCrcOnMcuRegisters_AutotestCallback(&u8TestResult);
	return u8TestResult;

}

#define ATM_STOP_SEC_CODE_ASIL_A
#include "ATM_MemMap.h"

/**************************************************************************
Exported Functions
**************************************************************************/

/* end of file */
