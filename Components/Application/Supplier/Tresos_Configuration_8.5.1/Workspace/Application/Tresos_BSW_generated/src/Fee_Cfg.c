/**
*   @file    Fee_Cfg.c
*   @implements Fee_Cfg.c_Artifact   
*   @version 1.0.2
*
*   @brief   AUTOSAR Fee - AUTOSAR Module Flash EEPROM Emulation Driver.
*   @details Definitions of all Pre-compile configuration structures.
*
*   @addtogroup FEE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : none
*   Dependencies         : Fls
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.2
*   Build Version        : S32K14xS32K14X_MCAL_1_0_2_RTM_ASR_REL_4_2_REV_0002_20190426
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2019 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fee_cfg_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file.
* Repeatedly included but does not have a standard include guard due to AUTOSAR 
* requirement MEMMAP003.
*
* @section Fee_cfg_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, #include statement preceded by some code 
* #include statements should only be preceded by other preprocessor directive or comments.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters due to 
* AUTOSAR compatibility.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* External identifiers are not distinct in the first 6 characters due to AUTOSAR
* compatibility.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fee.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_VENDOR_ID_CFG_C                      43
#define FEE_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define FEE_AR_RELEASE_MINOR_VERSION_CFG_C       2
#define FEE_AR_RELEASE_REVISION_VERSION_CFG_C    2
#define FEE_SW_MAJOR_VERSION_CFG_C               1
#define FEE_SW_MINOR_VERSION_CFG_C               0
#define FEE_SW_PATCH_VERSION_CFG_C               2

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Fee header file are of the same vendor */
#if (FEE_VENDOR_ID_CFG_C != FEE_VENDOR_ID)
    #error "Fee_Cfg.c and Fee.h have different vendor ids"
#endif
/* Check if current file and Fee header file are of the same Autosar version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION_CFG_C    != FEE_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_CFG_C    != FEE_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_CFG_C != FEE_AR_RELEASE_REVISION_VERSION)\
    )
    #error "AutoSar Version Numbers of Fee_Cfg.c and Fee.h are different"
#endif
/* Check if current file and Fee header file are of the same Software version */
#if ((FEE_SW_MAJOR_VERSION_CFG_C != FEE_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_CFG_C != FEE_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_CFG_C != FEE_SW_PATCH_VERSION)\
    )
    #error "Software Version Numbers of Fee_Cfg.c and Fee.h are different"
#endif



#define FEE_START_SEC_CONST_UNSPECIFIED
/* @violates @ref Fee_cfg_h_REF_1 Repeated include file */
#include "Fee_MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/* Configuration of cluster group FeeClusterGroup_APP */
static CONST(Fee_ClusterType, FEE_CONST) Fee_FeeClusterGroup_APP[2] =
{
    /* APP_FeeCluster_0 */
    {
        0U, /* Start address */
        28672U /* Size */
    },    /* APP_FeeCluster_1 */
    {
        28672U, /* Start address */
        28672U /* Size */
    }};
/* Configuration of cluster group FeeClusterGroup_FBL */
static CONST(Fee_ClusterType, FEE_CONST) Fee_FeeClusterGroup_FBL[2] =
{
    /* FBL_FeeCluster_0 */
    {
        57344U, /* Start address */
        4096U /* Size */
    },    /* FBL_FeeCluster_1 */
    {
        61440U, /* Start address */
        4096U /* Size */
    }};



/* Configuration of cluster group set */
CONST(Fee_ClusterGroupType, FEE_CONST) Fee_ClrGrps[FEE_NUMBER_OF_CLUSTER_GROUPS] =
{
    
    /* FeeClusterGroup_APP */
    {
        Fee_FeeClusterGroup_APP, /* Cluster set */
        2U, /* Number of clusters */
        0U /* Size of the reserved area */        
    },
    
    /* FeeClusterGroup_FBL */
    {
        Fee_FeeClusterGroup_FBL, /* Cluster set */
        2U, /* Number of clusters */
        0U /* Size of the reserved area */        
    }
};

/* Configuration of Fee blocks */
CONST(Fee_BlockConfigType, FEE_CONST) Fee_BlockConfig[FEE_CRT_CFG_NR_OF_BLOCKS] =
{
    /* FEE_BLOCK_CONFIG_ID_1 */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_CONFIG_ID_1, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_CONFIG_ID_2 */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_CONFIG_ID_2, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_DEM_DEFAULT */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_DEM_DEFAULT, /* FeeBlockNumber symbol */
        176U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ECC_COUNTERS */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECC_COUNTERS, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_RESET_CAUSE */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_RESET_CAUSE, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_SOLENOID_UNLOCK_CONF_PARAM */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_SOLENOID_UNLOCK_CONF_PARAM, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_AUTOTEST_ENABLE_PARAM */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_AUTOTEST_ENABLE_PARAM, /* FeeBlockNumber symbol */
        64U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_LOCK_UNLOCK_ECU */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_LOCK_UNLOCK_ECU, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_MEAS_FRAME_CONFIG */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_MEAS_FRAME_CONFIG, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_PART_NUMBER */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_PART_NUMBER, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_AEE_TRACEABILITY_NUMBER */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_AEE_TRACEABILITY_NUMBER, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ECU_ASSEMBLY_SERIAL_NUMBER */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECU_ASSEMBLY_SERIAL_NUMBER, /* FeeBlockNumber symbol */
        32U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_PROCESS_MODE */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_PROCESS_MODE, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        1U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ECS_VARIANT */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_VARIANT, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_RESERVED_1 */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_RESERVED_1, /* FeeBlockNumber symbol */
        48U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ECS_ACC_OFFSETS */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_ACC_OFFSETS, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ECS_BUCKLE_CONFIG */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_BUCKLE_CONFIG, /* FeeBlockNumber symbol */
        32U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ECS_CODING_VARIANT */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_CODING_VARIANT, /* FeeBlockNumber symbol */
        32U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ECS_ACC_LPF */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_ACC_LPF, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_SBS_LAST_STATE */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_SBS_LAST_STATE, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ECS_ALGO_OUTPUT_DELAY */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_ALGO_OUTPUT_DELAY, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ECS_SENSITIVY_LUT */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_SENSITIVY_LUT, /* FeeBlockNumber symbol */
        32U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ECS_SENSITIVITY_OPT */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_SENSITIVITY_OPT, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ECU_TEMP_CALIBRATION */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECU_TEMP_CALIBRATION, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ALV_NVM_VERSION */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ALV_NVM_VERSION, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_MEAS_FRAME_RAM_ADDR_CFG */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_MEAS_FRAME_RAM_ADDR_CFG, /* FeeBlockNumber symbol */
        80U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ACC_AXIS_ANGLE_CALIBRATION */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ACC_AXIS_ANGLE_CALIBRATION, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_EOL_COUNTERS */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_EOL_COUNTERS, /* FeeBlockNumber symbol */
        80U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_RESERVED_4 */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_RESERVED_4, /* FeeBlockNumber symbol */
        48U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_AUTOTEST_PARAM */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_AUTOTEST_PARAM, /* FeeBlockNumber symbol */
        128U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_PHYS_MEASUREMENTS */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_PHYS_MEASUREMENTS, /* FeeBlockNumber symbol */
        72U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_SOLENOID_PARAM */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_SOLENOID_PARAM, /* FeeBlockNumber symbol */
        72U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ECS_PROFILES */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_PROFILES, /* FeeBlockNumber symbol */
        48U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ECU_STATE_TIMING_PARAMETERS */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECU_STATE_TIMING_PARAMETERS, /* FeeBlockNumber symbol */
        128U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_SPARE_PART_NUMBER */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_SPARE_PART_NUMBER, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_HARDWARE_NUMBER */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_HARDWARE_NUMBER, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_SYSTEM_NAME_OR_ENGINE_TYPE */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_SYSTEM_NAME_OR_ENGINE_TYPE, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_FBL */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_FBL, /* FeeBlockNumber symbol */
        160U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ODX_FILE_IDENTIFIER */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ODX_FILE_IDENTIFIER, /* FeeBlockNumber symbol */
        32U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ODX_FILE_VERSION */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ODX_FILE_VERSION, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ECU_SERIAL_NUMBER */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECU_SERIAL_NUMBER, /* FeeBlockNumber symbol */
        32U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_LOGICAL_SW_BLOCK_VERSION */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_LOGICAL_SW_BLOCK_VERSION, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_HARDWARE_VERSION_NUMBER */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_HARDWARE_VERSION_NUMBER, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_APP_SOFTWARE_VERSION_NUMBER */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_APP_SOFTWARE_VERSION_NUMBER, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ECS_STEPS */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_STEPS, /* FeeBlockNumber symbol */
        64U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ID_ECS_PARAMETERS */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_PARAMETERS, /* FeeBlockNumber symbol */
        64U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_APPLICATION /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    }
};


#define FEE_STOP_SEC_CONST_UNSPECIFIED
/* @violates @ref Fee_cfg_h_REF_1 Repeated include file */
/* @violates @ref Fee_cfg_h_REF_2 #include statement preceded by some code */
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @}*/
