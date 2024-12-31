/**
 * \file
 *
 * \brief AUTOSAR NvM
 *
 * This file contains the implementation of the AUTOSAR
 * module NvM.
 *
 * \version 6.17.18
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2020 Elektrobit Automotive GmbH
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
    0U,  /* nvBlockIdentifier*/
    0xFFFFU,  /* ramBlockCrcIndex */
    0U,  /* nvBlockNum */
    0U,  /* romBlockNum */
    0U,  /* blockJobPriority */
    0U,  /* writeRetryLimit */
  },

  /* NVM_BLOCK_NvMBlock_ConfigID */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    &NvM_CompiledConfigurationId, /* romBlockDataAddress */
    &NvM_ConfigurationId, /* ramBlockDataAddress */
    0x0050208aU,  /* blockDesc */
    2U,  /* nvBlockLength */
    
    
    16U,  /* nvBlockBaseNumber */
    1U,   /* nvBlockIdentifier*/
    0U, /* ramBlockCrcIndex */
    2U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_SIDE */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* romBlockDataAddress */
    NULL_PTR, /* ramBlockDataAddress */
    0x00400040U,  /* blockDesc */
    1U,  /* nvBlockLength */
    
    
    288U,  /* nvBlockBaseNumber */
    9U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_CRC */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* romBlockDataAddress */
    NULL_PTR, /* ramBlockDataAddress */
    0x00400040U,  /* blockDesc */
    16U,  /* nvBlockLength */
    
    
    5120U,  /* nvBlockBaseNumber */
    11U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_FAZIT */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* romBlockDataAddress */
    NULL_PTR, /* ramBlockDataAddress */
    0x00400000U,  /* blockDesc */
    23U,  /* nvBlockLength */
    
    
    2352U,  /* nvBlockBaseNumber */
    147U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_SECURITYATT */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* romBlockDataAddress */
    NULL_PTR, /* ramBlockDataAddress */
    0x00402140U,  /* blockDesc */
    1U,  /* nvBlockLength */
    
    
    2368U,  /* nvBlockBaseNumber */
    148U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_ID_SPARE_PART_NUMBER */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* romBlockDataAddress */
    NULL_PTR, /* ramBlockDataAddress */
    0x00440240U,  /* blockDesc */
    11U,  /* nvBlockLength */
    
    
    2384U,  /* nvBlockBaseNumber */
    149U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_ID_HARDWARE_VERSION_NUMBER */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* romBlockDataAddress */
    NULL_PTR, /* ramBlockDataAddress */
    0x00400040U,  /* blockDesc */
    3U,  /* nvBlockLength */
    
    
    2400U,  /* nvBlockBaseNumber */
    150U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_ID_HARDWARE_NUMBER */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* romBlockDataAddress */
    NULL_PTR, /* ramBlockDataAddress */
    0x00400040U,  /* blockDesc */
    11U,  /* nvBlockLength */
    
    
    2416U,  /* nvBlockBaseNumber */
    151U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_ID_ECU_SERIAL_NUMBER */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* romBlockDataAddress */
    NULL_PTR, /* ramBlockDataAddress */
    0x00400040U,  /* blockDesc */
    20U,  /* nvBlockLength */
    
    
    2448U,  /* nvBlockBaseNumber */
    153U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
  },

  /* NVM_BLOCK_NVM_BOOTLOADER_DATA */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* romBlockDataAddress */
    NULL_PTR, /* ramBlockDataAddress */
    0x00400040U,  /* blockDesc */
    156U,  /* nvBlockLength */
    
    
    2512U,  /* nvBlockBaseNumber */
    157U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
  },

  /* NVM_BLOCK_NVM_BLOCK_IDENTIFICATION */
  {
    NULL_PTR, /* initBlockCallback */
    NULL_PTR, /* singleBlockCallback */
    NULL_PTR, /* romBlockDataAddress */
    NULL_PTR, /* ramBlockDataAddress */
    0x00400040U,  /* blockDesc */
    67U,  /* nvBlockLength */
    
    
    5088U,  /* nvBlockBaseNumber */
    318U,   /* nvBlockIdentifier*/
    0xFFFFU, /* ramBlockCrcIndex */
    1U, /* nvBlockNum */
    1U, /* romBlockNum */
    1U, /* blockJobPriority */
    3U,  /* writeRetryLimit */
  }
}; /* NvM_BlockDescriptorTable */

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
 
VAR(uint16,NVM_APPL_DATA) NvM_CalcCrc_CalcBuffer = (uint16)0U;

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
