/**
*   @file    Fee_Cfg.h
*   @implements Fee_Cfg.h_Artifact
*   @version 1.0.2
*
*   @brief   AUTOSAR Fee - AUTOSAR Module Flash EEPROM Emulation Driver.
*   @details Definitions of all pre-compile configuration parameters..
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

#ifndef FEE_CFG_H
#define FEE_CFG_H

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
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for a macro.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external
* identifiers.
* Block name symbol defines are too long, handled by preprocessor.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters due to
* AUTOSAR compatibility.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fee_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/** @implements   VendorId_Object */
#define FEE_VENDOR_ID_CFG                    43
/** @implements   ModuleId_Object */
#define FEE_MODULE_ID_CFG                    21
/** @implements   ArReleaseMajorVersion_Object */
#define FEE_AR_RELEASE_MAJOR_VERSION_CFG     4
/** @implements   ArReleaseMinorVersion_Object */
#define FEE_AR_RELEASE_MINOR_VERSION_CFG     2
/** @implements   ArReleaseRevisionVersion_Object */
#define FEE_AR_RELEASE_REVISION_VERSION_CFG  2
/** @implements   SwMajorVersion_Object */
#define FEE_SW_MAJOR_VERSION_CFG             1
/** @implements   SwMinorVersion_Object */
#define FEE_SW_MINOR_VERSION_CFG             0
/** @implements   SwPatchVersion_Object */
#define FEE_SW_PATCH_VERSION_CFG             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MODULENAME configuration header file are of the same vendor */
#if (FEE_VENDOR_ID_CFG != FEE_TYPES_VENDOR_ID)
    #error "Fee_Types.h and Fee_Cfg.h have different vendor ids"
#endif
/* Check if current file and MODULENAME configuration header file are
   of the same Autosar version
*/
#if ((FEE_AR_RELEASE_MAJOR_VERSION_CFG    != FEE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_CFG    != FEE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_CFG != FEE_TYPES_AR_RELEASE_REVISION_VERSION)\
    )
    #error "AutoSar Version Numbers of Fee_Types.h and Fee_Cfg.h are different"
#endif
/* Check if current file and MODULENAME configuration header file are
   of the same software version
*/
#if ((FEE_SW_MAJOR_VERSION_CFG != FEE_TYPES_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_CFG != FEE_TYPES_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_CFG != FEE_TYPES_SW_PATCH_VERSION)\
    )
    #error "Software Version Numbers of Fee_Types.h and Fee_Cfg.h are different"
#endif


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Pre-processor switch to enable and disable development error detection */
/** @implements   FeeDevErrorDetect_Object */
#define FEE_DEV_ERROR_DETECT                (STD_OFF)

/* Pre-processor switch to enable / disable the API to read out the modules
    version information */
/** @implements   FeeVersionInfoApi_Object */
#define FEE_VERSION_INFO_API                (STD_ON)

/* Compiler switch to enable/disable the SetMode functionality of the module */
/** @implements   FeeSetModeSupported_Object */
#define FEE_SETMODE_API_SUPPORTED           (STD_ON)

/* Pre-processor switch to enable /disable the Fls_Cancel function of the module */
#define FEE_CANCEL_API                     (STD_OFF)

/* The size in bytes to which logical blocks shall be aligned */
/** @implements   FeeVirtualPageSize_Object */
#define FEE_VIRTUAL_PAGE_SIZE               16U

/* Job end notification routine provided by the upper layer module (declaration) */
/** @implements   FeeNvmJobEndNotification_Object */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_JOB_END_NOTIFICATION_DECL   extern void NvM_JobEndNotification(void);

/* Job end notification routine provided by the upper layer module */
/** @implements   FeeNvmJobEndNotification_Object */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_JOB_END_NOTIFICATION        NvM_JobEndNotification();

/* Job error notification routine provided by the upper layer module (declaration) */
/** @implements   FeeNvmJobErrorNotification_Object */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_JOB_ERROR_NOTIFICATION_DECL  extern void NvM_JobErrorNotification(void);

/* Job error notification routine provided by the upper layer module */
/** @implements   FeeNvmJobErrorNotification_Object */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_JOB_ERROR_NOTIFICATION       NvM_JobErrorNotification();

/* Job cluster format notification routine provided by the upper layer module (declaration) */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_CLUSTER_FORMAT_NOTIFICATION_DECL  

/* Job cluster format notification routine provided by the upper layer module */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_CLUSTER_FORMAT_NOTIFICATION       

/* Number of configured Fee cluster groups */
#define FEE_NUMBER_OF_CLUSTER_GROUPS        2U

/* Number of configured Fee blocks */
#define FEE_CRT_CFG_NR_OF_BLOCKS                46U

/* Maximum number of Fee blocks in all project versions and configurations */
#define FEE_MAX_NR_OF_BLOCKS        (FEE_CRT_CFG_NR_OF_BLOCKS)
/* Management overhead per logical block in bytes */
/** @implements   FeeBlockOverhead_Object */
#define FEE_BLOCK_OVERHEAD                  48U

/* Management overhead per logical cluster in bytes */
#define FEE_CLUSTER_OVERHEAD                48U

/* Size of the data buffer in bytes */
#define FEE_DATA_BUFFER_SIZE                48U

/* The contents of an erased flash memory cell */
#define FEE_ERASED_VALUE                    0xffU

/* Value of the block and cluster validation flag */
#define FEE_VALIDATED_VALUE                0x81U

/* Value of the block and cluster invalidation flag */
#define FEE_INVALIDATED_VALUE              0x18U

/* If reset, power loss etc. occurs here, neither newly nor previously written data is available */
#define FEE_BLOCK_ALWAYS_AVAILABLE          (STD_ON)

/* Compile switch to enable Legacy mode (original FEE immediate data handling) */
#define FEE_LEGACY_MODE                     (STD_ON)

/* Behavior of Fee_ImmediateBlockErase */
#define FEE_LEGACY_IMM_ERASE_MODE           (STD_OFF)

/* This configuration defines wheather Fee should swap foreign blocks found in flash at swap or not */
#define FEE_SWAP_FOREIGN_BLOCKS_ENABLED          (STD_OFF)

/* This configuration defines for which project the Fee configuration is used  */
#define FEE_BOOTLOADER_CONFIG           (STD_OFF)

/* This configuration defines if the status for the never written blocks must be INVALID or INCONSISTENT */
#define FEE_MARK_EMPTY_BLOCKS_INVALID    (STD_OFF)

/* Symbolic names of configured Fee blocks */
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_CONFIG_ID_1     16U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_CONFIG_ID_2     17U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_DEM_DEFAULT     32U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECC_COUNTERS     48U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_RESET_CAUSE     64U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_SOLENOID_UNLOCK_CONF_PARAM     80U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_AUTOTEST_ENABLE_PARAM     96U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_LOCK_UNLOCK_ECU     112U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_MEAS_FRAME_CONFIG     128U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_PART_NUMBER     144U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_AEE_TRACEABILITY_NUMBER     160U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECU_ASSEMBLY_SERIAL_NUMBER     176U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_PROCESS_MODE     192U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_VARIANT     208U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_RESERVED_1     224U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_ACC_OFFSETS     240U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_BUCKLE_CONFIG     256U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_CODING_VARIANT     272U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_ACC_LPF     288U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_SBS_LAST_STATE     304U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_ALGO_OUTPUT_DELAY     320U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_SENSITIVY_LUT     336U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_SENSITIVITY_OPT     352U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECU_TEMP_CALIBRATION     368U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ALV_NVM_VERSION     384U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_MEAS_FRAME_RAM_ADDR_CFG     400U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ACC_AXIS_ANGLE_CALIBRATION     416U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_EOL_COUNTERS     432U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_RESERVED_4     448U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_AUTOTEST_PARAM     464U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_PHYS_MEASUREMENTS     480U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_SOLENOID_PARAM     496U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_PROFILES     512U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECU_STATE_TIMING_PARAMETERS     528U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_SPARE_PART_NUMBER     544U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_HARDWARE_NUMBER     560U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_SYSTEM_NAME_OR_ENGINE_TYPE     576U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_FBL     592U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ODX_FILE_IDENTIFIER     608U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ODX_FILE_VERSION     624U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECU_SERIAL_NUMBER     640U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_LOGICAL_SW_BLOCK_VERSION     656U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_HARDWARE_VERSION_NUMBER     672U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_APP_SOFTWARE_VERSION_NUMBER     688U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_STEPS     704U
#define FeeConf_FeeBlockConfiguration_FEE_BLOCK_ID_ECS_PARAMETERS     720U


#define FEE_START_SEC_CONST_UNSPECIFIED
/* @violates @ref Fee_cfg_h_REF_1 Repeated include file */
#include "Fee_MemMap.h"

       




       




/* Configuration of cluster group set */
extern CONST(Fee_ClusterGroupType, FEE_CONST) Fee_ClrGrps[ FEE_NUMBER_OF_CLUSTER_GROUPS ];

/* Configuration of Fee blocks */
extern CONST(Fee_BlockConfigType, FEE_CONST) Fee_BlockConfig[ FEE_CRT_CFG_NR_OF_BLOCKS ];

#define FEE_STOP_SEC_CONST_UNSPECIFIED
/* @violates @ref Fee_cfg_h_REF_1 Repeated include file */
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* FEE_CFG_H */
/** @} */
