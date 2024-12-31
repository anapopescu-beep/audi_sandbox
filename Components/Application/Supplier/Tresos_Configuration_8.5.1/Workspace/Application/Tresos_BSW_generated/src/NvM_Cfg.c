/**
 * \file
 *
 * \brief AUTOSAR NvM
 *
 * This file contains the implementation of the AUTOSAR
 * module NvM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */




/*  MISRA-C:2012 Deviation List
 *
 *  MISRAC2012-1) Deviated Rule: 11.1 (required)
 *           "Conversions shall not be performed between a pointer to a function
 *           and any type other than an integral type."
 *
 *           Reason:
 *           The cast is necessary in order to avoid compiler warnings when mixing
 *           ports for mirror operations of different AUTOSAR versions.
 *
 *  MISRAC2012-2) Deviated Rule: 20.10 (advisory)
 *           "The # and ## preprocessor operators should not be used."
 *
 *           Reason:
 *           Concatenation(##) operator is used by pre compile time parameter. It doesn't
 *           have any negative impact on code.
 *
 */

/*==================[inclusions]=============================================*/

#include <TSAutosar.h>

#if (defined NVM_INTERNAL_USE)
#error NVM_INTERNAL_USE already defined
#endif
/* prevent redundant declarations of RTE types */
#define NVM_INTERNAL_USE

/* !LINKSTO NVM554,1 */
#include <NvM.h>
#include <NvM_FunctionIntern.h> /* for initialization of NvM_CalcCrc */
#include <NvM_DataIntern.h>   /* extern definition of NvM_ConfigurationId */
#include <NvM_CalcCrc.h>      /* Extern definitions of unit 'CalcCrc'. */
#include <NvM_UsrHdr.h>

#if (NVM_INCLUDE_RTE == STD_ON)
# include <Rte_NvM.h>
# include <Rte_NvMData.h>
#endif

/*==================[macros]================================================*/


/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

#if ( defined(NVM_MULTICORE_ENABLED) )
#define NVM_START_SEC_MC_SHARED_CONFIG_DATA_UNSPECIFIED
#include <NvM_MemMap.h>
#else
#define NVM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <NvM_MemMap.h>
#endif
/* !LINKSTO NVM138,1, NVM143,1, NVM443,1, NVM321,1 ,NVM140,1 */
CONST(NvM_BlockDescriptorType,NVM_CONST) NvM_BlockDescriptorTable[NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS]=
{
  /** \brief  block 0:  NvM internal block, used to manage multi block requests. */
  {
    NULL_PTR,    /* initBlockCallback */
    NULL_PTR,    /* singleBlockCallback */
    NULL_PTR,    /* romBlockDataAddress */
    NULL_PTR,    /* ramBlockDataAddress */
    0U,  /* blockDesc */
    0U,  /* nvBlockLength */
    0U,  /* BlockBaseNumber */
    0xFFFFU,  /* ramBlockCrcIndex */
    0U,  /* bcBlockIdx */
    0U,  /* nvBlockNum */
    0U,  /* romBlockNum */
    0U,  /* blockJobPriority */
    0U,  /* writeRetryLimit */
    0U  /* readRetryLimit */
  },

  /* NVM_BLOCK_NvMBlock_ConfigID */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    &NvM_CompiledConfigurationId, /* romBlockDataAddress */
    &NvM_ConfigurationId, /* ramBlockDataAddress */
    0x0054628aU,  /* blockDesc */
    2U,  /* nvBlockLength */
	
    1U,  /* nvBlockBaseNumber */
    0U, /* ramBlockCrcIndex */
    0U, /* bcBlockIdx */
    2U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U  /* readRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_DEM_DEFAULT */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* romBlockDataAddress */
    &Dem_NvData, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    176U,  /* nvBlockLength */
	
    2U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    1U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    0U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    0U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ECC_COUNTERS */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ECCCounters, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ECCCounters, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    16U,  /* nvBlockLength */
	
    3U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    2U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_WARM_RESET_COUNTERS */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_WarmReset, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_WarmReset, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    8U,  /* nvBlockLength */
	
    4U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    3U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_SOLENOID_UNLOCK_CONF_PARAM */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_SOLENOID_UNLOCK_CONF_PARAM, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_SOLENOID_UNLOCK_CONF_PARAM, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    9U,  /* nvBlockLength */
	
    5U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    4U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_AUTOTEST_ENABLE_PARAM */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ATMEnableParam, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ATMEnableParam, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    32U,  /* nvBlockLength */
	
    6U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    5U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_LOCK_UNLOCK_ECU */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_LOCK_UNLOCK_ECU_ParamSpecific, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_LOCK_UNLOCK_ECU_ParamSpecific, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    2U,  /* nvBlockLength */
	
    7U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    6U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_MEASUREMENT_FRAME_CONFIG */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_MeasFrameCfg, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_MeasFrameCfg, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    5U,  /* nvBlockLength */
	
    8U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    7U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_HW_PART_NUMBER */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_HW_PART_NUMBER, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_HW_PART_NUMBER, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    10U,  /* nvBlockLength */
	
    9U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    8U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_AEE_TRACEABILITY_NUMBER */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_AEE_TRACEABILITY_NUMBER, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_AEE_TRACEABILITY_NUMBER, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    12U,  /* nvBlockLength */
	
    10U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    9U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ECU_ASSEMBLY_SERIAL_NUMBER */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ECU_ASSEMBLY_SERIAL_NUMBER, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ECU_ASSEMBLY_SERIAL_NUMBER, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    23U,  /* nvBlockLength */
	
    11U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    10U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_PROCESS_MODE */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ProcessMode, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ProcessMode, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    1U,  /* nvBlockLength */
	
    12U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    11U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ECS_VARIANT */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ECS_VARIANT, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ECS_VARIANT, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    4U,  /* nvBlockLength */
	
    13U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    12U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_RESERVED_1 */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_RESERVED_1, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_RESERVED_1, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    45U,  /* nvBlockLength */
	
    14U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    13U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ECS_ACC_OFFSETS */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ECS_ACC_OFFSETS, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ECS_ACC_OFFSETS, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    6U,  /* nvBlockLength */
	
    15U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    14U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ECS_BUCKLE_CONFIG */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ECS_BUCKLE_CONFIG, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ECS_BUCKLE_CONFIG, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    1U,  /* nvBlockLength */
	
    16U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    15U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ECS_CODING_VARIANT */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ECS_CODING_VARIANT, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ECS_CODING_VARIANT, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    6U,  /* nvBlockLength */
	
    17U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    16U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ECS_ACC_LOWPASS */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ECS_ACC_LOWPASS, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ECS_ACC_LOWPASS, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    3U,  /* nvBlockLength */
	
    18U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    17U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_SBS_LAST_STATE */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_SBS_LAST_STATE, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_SBS_LAST_STATE, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    2U,  /* nvBlockLength */
	
    19U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    18U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ECS_ALGO_OUTPUT_DELAY */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ECS_ALGO_OUTPUT_DELAY, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ECS_ALGO_OUTPUT_DELAY, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    2U,  /* nvBlockLength */
	
    20U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    19U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ECS_SENSITIVITY_LUT */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ECS_SENSITIVITY_LUT, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ECS_SENSITIVITY_LUT, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    20U,  /* nvBlockLength */
	
    21U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    20U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ECS_SENSITIVITY_OPT */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ECS_SENSITIVITY_OPT, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ECS_SENSITIVITY_OPT, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    1U,  /* nvBlockLength */
	
    22U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    21U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ECU_TEMP_CALIBRATION */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ECU_TEMP_CALIBRATION, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ECU_TEMP_CALIBRATION, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    3U,  /* nvBlockLength */
	
    23U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    22U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ALV_NVM_VERSION */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ALV_NVM_VERSION, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ALV_NVM_VERSION, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    4U,  /* nvBlockLength */
	
    24U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    23U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_MEAS_FRAME_RAM_ADDR_CFG */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_MEAS_FRAME_RAM_ADDR_CFG, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_MEAS_FRAME_RAM_ADDR_CFG, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    75U,  /* nvBlockLength */
	
    25U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    24U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ACC_AXIS_ANGLE_CALIBRATION */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ACC_AXIS_ANGLE_CALIBRATION, /* romBlockDataAddress */
    (void*)BlockAddress__RAM_ACC_AXIS_ANGLE_CALIBRATION, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    6U,  /* nvBlockLength */
	
    26U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    25U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_EOL_COUNTERS */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_EOL_COUNTERS, /* romBlockDataAddress */
    (void*)BlockAddress__RAM_EOL_COUNTERS, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    72U,  /* nvBlockLength */
	
    27U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    26U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_RESERVED_4 */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_RESERVED_4, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_RESERVED_4, /* ramBlockDataAddress */
    0x00404000U,  /* blockDesc */
    36U,  /* nvBlockLength */
	
    28U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    27U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_AUTOTEST_PARAM */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_AutotestParam, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_AutotestParam, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    27U,  /* nvBlockLength */
	
    29U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    28U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_PHYS_MEASUREMENTS */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_PhysMeasurements, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_PhysMeasurements, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    6U,  /* nvBlockLength */
	
    30U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    29U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_SOLENOID_PARAM */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_SolenoidParam, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_SolenoidParam, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    11U,  /* nvBlockLength */
	
    31U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    30U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ECS_PROFILES */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ECS_PROFILES, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ECS_PROFILES, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    48U,  /* nvBlockLength */
	
    32U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    31U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ECU_STATE_TIMING_PARAMETERS */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ECU_STATE_TIMING_PARAMETERS, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ECU_STATE_TIMING_PARAMETERS, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    92U,  /* nvBlockLength */
	
    33U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    32U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_SPARE_PART_NUMBER */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_SparePartNumber, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_SparePartNumber, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    11U,  /* nvBlockLength */
	
    34U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    33U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_HARDWARE_NUMBER */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_HwPartNumber, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_HwPartNumber, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    11U,  /* nvBlockLength */
	
    35U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    34U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_SYSTEM_NAME_OR_ENGINE_TYPE */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_SystemNameOrEngineType, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_SystemNameOrEngineType, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    13U,  /* nvBlockLength */
	
    36U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    35U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_BLOCK_FBL */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_FBL, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_FBL, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    156U,  /* nvBlockLength */
	
    37U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    36U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ODX_FILE_IDENTIFIER */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_Identification, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_Identification, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    24U,  /* nvBlockLength */
	
    38U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    37U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ODX_FILE_VERSION */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_OdxFileVersion, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_OdxFileVersion, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    6U,  /* nvBlockLength */
	
    39U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    38U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ECU_SERIAL_NUMBER */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ECUSerialNumber, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ECUSerialNumber, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    20U,  /* nvBlockLength */
	
    40U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    39U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_LOGICAL_SW_BLOCK_VERSION */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_LogicalSwBlockVersion, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_LogicalSwBlockVersion, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    12U,  /* nvBlockLength */
	
    41U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    40U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_HARDWARE_VERSION_NUMBER */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_HardwareVersionNumber, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_HardwareVersionNumber, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    3U,  /* nvBlockLength */
	
    42U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    41U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_APP_SOFTWARE_VERSION_NUMBER */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_AppSoftwareVersionNumber, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_AppSoftwareVersionNumber, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    4U,  /* nvBlockLength */
	
    43U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    42U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ECS_STEPS */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ECS_STEPS, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ECS_STEPS, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    56U,  /* nvBlockLength */
	
    44U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    43U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  },

  /* NVM_BLOCK_ECS_PARAMETERS */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    (void*)BlockAddress_ROM_ECS_PARAMETERS, /* romBlockDataAddress */
    (void*)BlockAddress_RAM_ECS_PARAMETERS, /* ramBlockDataAddress */
    0x00444200U,  /* blockDesc */
    49U,  /* nvBlockLength */
	
    45U,  /* nvBlockBaseNumber */
    0xFFFFU, /* ramBlockCrcIndex */
    44U, /* bcBlockIdx */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
    3U  /* readRetryLimit */
  }
}; /* NvM_BlockDescriptorTable */
CONST(NvM_BcCfgDataType,NVM_CONST) NvM_BcCfgData[NVM_BC_NR_OF_BLOCKS]=
{
  {
  1U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  2U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  3U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  4U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  5U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  6U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  7U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  8U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  9U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  10U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  11U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  12U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  13U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  14U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  15U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  16U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  17U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  18U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  19U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  20U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  21U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  22U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  23U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  24U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  25U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  26U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  27U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  28U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  29U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  30U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  31U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  32U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  33U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  34U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  35U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  36U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  37U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  38U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  39U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  40U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  41U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  42U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  43U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  44U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
  {
  45U,  /* NvMNvramBlockIdentifier */
  0U,  /* delayCounter */
  0x15U,  /* BcBlockDesc */
  },
};
#if ( defined(NVM_MULTICORE_ENABLED) )
#define NVM_STOP_SEC_MC_SHARED_CONFIG_DATA_UNSPECIFIED
#include <NvM_MemMap.h>
#else
#define NVM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <NvM_MemMap.h>
#endif /*MULTICORE ENABLED*/

#define NVM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <NvM_MemMap.h>

#if (NVM_CANCEL_INTERNAL_JOB == STD_ON)
CONST(uint8,NVM_CONST) NvM_UsedDeviceIds[NVM_NUM_USED_DEVICES]=
{
0U,
};/*NvM_UsedDeviceIds*/
#endif /* NVM_CANCEL_INTERNAL_JOB == STD_ON */

#define NVM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <NvM_MemMap.h>


#define NVM_START_SEC_VAR_INIT_16
#include <NvM_MemMap.h>
 
VAR(uint16,NVM_APPL_DATA) NvM_CalcCrc_CalcBuffer;

#define NVM_STOP_SEC_VAR_INIT_16
#include <NvM_MemMap.h>


#define NVM_START_SEC_CONFIG_DATA_APPL_CONST
#include <NvM_MemMap.h>
/* !LINKSTO NVM034,1 */
CONST(uint16,NVM_APPL_CONST) NvM_CompiledConfigurationId = 0x1U;



#define NVM_STOP_SEC_CONFIG_DATA_APPL_CONST
#include <NvM_MemMap.h>


/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/*==================[end of file]============================================*/
