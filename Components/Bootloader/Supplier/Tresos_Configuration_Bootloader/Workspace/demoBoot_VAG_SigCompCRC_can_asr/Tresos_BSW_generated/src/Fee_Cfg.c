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

/* Configuration of cluster group FeeClusterGroup_0 */
static CONST(Fee_ClusterType, FEE_CONST) Fee_FeeClusterGroup_0[2] =
{
    /* FeeCluster_0 */
    {
        0U, /* Start address */
        32768U /* Size */
    },    /* FeeCluster_1 */
    {
        32768U, /* Start address */
        32768U /* Size */
    }};



/* Configuration of cluster group set */
CONST(Fee_ClusterGroupType, FEE_CONST) Fee_ClrGrps[FEE_NUMBER_OF_CLUSTER_GROUPS] =
{
    
    /* FeeClusterGroup_0 */
    {
        Fee_FeeClusterGroup_0, /* Cluster set */
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
        FEE_PROJECT_SHARED /* Fee Block Assignment to a project */
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
        FEE_PROJECT_SHARED /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_SIDE */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_SIDE, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_SHARED /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_FAZIT */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_FAZIT, /* FeeBlockNumber symbol */
        32U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_SHARED /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_SECURITYATT */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_SECURITYATT, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_SHARED /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_SPARE_PART_NUMBER */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_SPARE_PART_NUMBER, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_SHARED /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_HARDWARE_VERSION_NUMBER */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_HARDWARE_VERSION_NUMBER, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_SHARED /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_HARDWARE_NUMBER */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_HARDWARE_NUMBER, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_SHARED /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_ECU_SERIAL_NUMBER */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_ECU_SERIAL_NUMBER, /* FeeBlockNumber symbol */
        32U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_SHARED /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_FBL */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_FBL, /* FeeBlockNumber symbol */
        160U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_SHARED /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_IDENTIFICATION */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_IDENTIFICATION, /* FeeBlockNumber symbol */
        80U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_SHARED /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    },
    /* FEE_BLOCK_CRC */
    {
        FeeConf_FeeBlockConfiguration_FEE_BLOCK_CRC, /* FeeBlockNumber symbol */
        16U, /* FeeBlockSize */
        0U, /* FeeClusterGroup */
        (boolean)FALSE,   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_SHARED /* Fee Block Assignment to a project */
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
