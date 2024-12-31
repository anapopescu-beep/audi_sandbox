/**
 * \file
 *
 * \brief AUTOSAR NvM
 *
 * This file contains the implementation of the AUTOSAR
 * module NvM.
 *
 * \version 6.17.29
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */



/* !LINKSTO NVM030,1 */

#ifndef NVM_CFG_H
#define NVM_CFG_H
/* !LINKSTO NVM028,1 */
/*==================[inclusions]============================================*/

/* !LINKSTO NVM689,1 */
#include <NvM_Types.h>        /* contains NvM specific types. NVM689 */
#include <Std_Types.h>




/*==================[macros]================================================*/

#if (defined  NVM_VARIABLE_BLOCK_LENGTH_EN)
#error NVM_VARIABLE_BLOCK_LENGTH_EN is already defined
#endif /* if (defined NVM_VARIABLE_BLOCK_LENGTH_EN) */
/** \brief Variable Block Length is Enabled.  */
#define NVM_VARIABLE_BLOCK_LENGTH_EN   STD_OFF


#if (defined NVM_MEMACC_USAGE)
#error NVM_MEMACC_USAGE is already defined
#endif
/** \brief Macro switch for MemAcc usage */
#define NVM_MEMACC_USAGE                STD_OFF

#if (defined NVM_BUFFER_ALIGNMENT_BITS)
#error NVM_BUFFER_ALIGNMENT_BITS is already defined
#endif
/* !LINKSTO ECUC_NvM_00573,1 */
/** \brief Alignment in bits for NvM Internal buffer
 **/
#define NVM_BUFFER_ALIGNMENT_BITS 8U

#if (defined NVM_DEV_ERROR_DETECT)
#error NVM_DEV_ERROR_DETECT is already defined
#endif
/** \brief Macro switch for DET usage */
#define NVM_DEV_ERROR_DETECT             STD_OFF

#if (defined NVM_INCLUDE_RTE)
#error NVM_INCLUDE_RTE is already defined
#endif
/** \brief Defines whether a Rte module configuration is available.
 **        If it is available then it is automatically used by the NVRAM Manager.
 **        STD_ON:  Rte configuration is available.
 **        STD_OFF: Rte configuration is not available.
 **/
#define NVM_INCLUDE_RTE                  STD_ON

#if (defined NVM_SET_RAM_BLOCK_STATUS_API)
#error NVM_SET_RAM_BLOCK_STATUS_API is already defined
#endif
/** \brief Disables or enables the API NvM_SetRamBlockStatus()
 **/
#define NVM_SET_RAM_BLOCK_STATUS_API     STD_ON

/** \brief Macro to check if Block Checks is configured for any block
 **/
#define NVM_BLOCK_CHECK_ENABLED     STD_ON

/** \brief Number of blocks configured with Block Check.
 **/
#define NVM_BC_NR_OF_BLOCKS     45U

 /** \brief Number of blocks configured with Block Check of type REDUNDANT.
**/
#define NVM_BC_NR_OF_BLOCKS_REDUNDANT     1U

/** \brief Macro to check if Block Id-s are consecutive. Otherwise a redirecting array is needed
 **/
#define NVM_USE_REDIR_BLOCK_ARRAY     STD_OFF

/** \brief Macro to check if Block Id-s are consecutive. Otherwise a binary search is needed
 **/
#define NVM_BLOCK_INDEX_SEARCH     STD_OFF

/** \brief Macro to check if Block Checks Set API is configured for any block
 **/
#define NVM_BLOCK_CHECK_SET_API_ENABLED     STD_OFF

#if (defined NVM_CANCEL_INTERNAL_JOB)
#error NVM_CANCEL_INTERNAL_JOB is already defined
#endif
/** \brief Disables or enables the option to cancel an ongoing internal job.
 **/
#define NVM_CANCEL_INTERNAL_JOB             STD_OFF

#if (defined NVM_VERSION_INFO_API)
#error NVM_VERSION_INFO_API is already defined
#endif
/** \brief Disables or enables the API NvM_VersionInfoApi()
 **/
#define NVM_VERSION_INFO_API             STD_OFF

#if (defined NVM_CLEAR_RAMBLOCK_AFTER_RESET)
#error NVM_CLEAR_RAMBLOCK_AFTER_RESET is already defined
#endif
/** \brief Disables or enables the API NvM_VersionInfoApi()
 **/
#define NVM_CLEAR_RAMBLOCK_AFTER_RESET             STD_OFF

#if (defined NVM_ADVANCED_RECOVERY)
#error NVM_ADVANCED_RECOVERY is already defined
#endif
/** \brief Dis- or enable the recovery of blocks()
 **/
#define NVM_ADVANCED_RECOVERY            STD_ON

#if (defined NVM_PROD_ERR_HANDLING_INTEGRITY_FAILED)
#error NVM_PROD_ERR_HANDLING_INTEGRITY_FAILED already defined
#endif
/** \brief Switch for DEM to DET reporting Integrity Failure
 **/
#define NVM_PROD_ERR_HANDLING_INTEGRITY_FAILED     TS_PROD_ERR_DISABLE

#if (defined NVM_PROD_ERR_HANDLING_REQ_FAILED)
#error NVM_PROD_ERR_HANDLING_REQ_FAILED already defined
#endif
/** \brief Switch for DEM to DET reporting Request Failure
 **/
#define NVM_PROD_ERR_HANDLING_REQ_FAILED           TS_PROD_ERR_DISABLE

#if (defined NVM_PROD_ERR_HANDLING_LOSS_OF_REDUNDANCY)
#error NVM_PROD_ERR_HANDLING_LOSS_OF_REDUNDANCY already defined
#endif
/** \brief Switch for DEM to DET reporting Loss of Redundancy
 **/
#define NVM_PROD_ERR_HANDLING_LOSS_OF_REDUNDANCY   TS_PROD_ERR_DISABLE

#if (defined NVM_PROD_ERR_HANDLING_QUEUE_OVERFLOW)
#error NVM_PROD_ERR_HANDLING_QUEUE_OVERFLOW already defined
#endif
/** \brief Switch for DEM to DET reporting Queue Overflow
 **/
#define NVM_PROD_ERR_HANDLING_QUEUE_OVERFLOW       TS_PROD_ERR_DISABLE

#if (defined NVM_PROD_ERR_HANDLING_VERIFY_FAILED)
#error NVM_PROD_ERR_HANDLING_VERIFY_FAILED already defined
#endif
/** \brief Switch for DEM to DET reporting Verify Failure
 **/
#define NVM_PROD_ERR_HANDLING_VERIFY_FAILED        TS_PROD_ERR_DISABLE

#if (defined NVM_PROD_ERR_HANDLING_WRITE_PROTECTED)
#error NVM_PROD_ERR_HANDLING_WRITE_PROTECTED already defined
#endif
/** \brief Switch for DEM to DET reporting Write Protection
 **/
#define NVM_PROD_ERR_HANDLING_WRITE_PROTECTED      TS_PROD_ERR_DISABLE

#if (defined NVM_PROD_ERR_HANDLING_BLOCK_CHECK)
#error NVM_PROD_ERR_HANDLING_BLOCK_CHECK already defined
#endif
/** \brief Switch for DET reporting Block Check
 **/
#define NVM_PROD_ERR_HANDLING_BLOCK_CHECK      TS_PROD_ERR_DISABLE


#if (defined NVM_PROD_ERR_HANDLING_WRONG_BLOCK_ID)
#error NVM_PROD_ERR_HANDLING_WRONG_BLOCK_ID already defined
#endif
/** \brief Switch for DEM to DET reporting Wrong Block ID
 **/
#define NVM_PROD_ERR_HANDLING_WRONG_BLOCK_ID       TS_PROD_ERR_DISABLE




#if (defined NVM_INVALID_DEM_EVENTID)
#error NVM_INVALID_DEM_EVENTID is already defined
#endif
/** \brief special value: no Dem event id configured
 **        (0 is not a valid value for Dem_EventIdType)
 **/
#define NVM_INVALID_DEM_EVENTID        0U

#if (defined NVM_INTEGRITY_FAILED_DEM_EVENT_ID)
#error NVM_INTEGRITY_FAILED_DEM_EVENT_ID is already defined
#endif
/** \brief Switch for integrity failure Dem event Id
 **/
#define NVM_INTEGRITY_FAILED_DEM_EVENT_ID NVM_INVALID_DEM_EVENTID

#if (defined NVM_REQ_FAILED_DEM_EVENT_ID)
#error NVM_REQ_FAILED_DEM_EVENT_ID is already defined
#endif
/** \brief Switch for request failure Dem event Id
 **/
#define NVM_REQ_FAILED_DEM_EVENT_ID    NVM_INVALID_DEM_EVENTID

#if (defined NVM_REDUNDANCY_LOSS_DEM_EVENT_ID)
#error NVM_REDUNDANCY_LOSS_DEM_EVENT_ID is already defined
#endif
/** \brief Switch for redundancy loss Dem event Id
 **/
#define NVM_REDUNDANCY_LOSS_DEM_EVENT_ID NVM_INVALID_DEM_EVENTID

#if (defined NVM_QUEUE_OVERFLOW_DEM_EVENT_ID)
#error NVM_QUEUE_OVERFLOW_DEM_EVENT_ID is already defined
#endif
/** \brief Switch for queue overflow Dem event Id
 **/
#define NVM_QUEUE_OVERFLOW_DEM_EVENT_ID NVM_INVALID_DEM_EVENTID

#if (defined NVM_VERIFY_FAILED_DEM_EVENT_ID)
#error NVM_VERIFY_FAILED_DEM_EVENT_ID is already defined
#endif
/** \brief Switch for verify failed Dem event Id
 **/
#define NVM_VERIFY_FAILED_DEM_EVENT_ID NVM_INVALID_DEM_EVENTID

#if (defined NVM_WRITE_PROT_DEM_EVENT_ID)
#error NVM_WRITE_PROT_DEM_EVENT_ID is already defined
#endif
/** \brief Switch for write protection failure Dem event Id
 **/
#define NVM_WRITE_PROT_DEM_EVENT_ID    NVM_INVALID_DEM_EVENTID

#define NVM_BLOCK_CHECK_DEM_EVENT_ID    NVM_INVALID_DEM_EVENTID

#if (defined NVM_WRONG_BLOCK_DEM_EVENT_ID)
#error NVM_WRONG_BLOCK_DEM_EVENT_ID is already defined
#endif
/** \brief Switch for wrong block Id Dem event Id
 **/
#define NVM_WRONG_BLOCK_DEM_EVENT_ID   NVM_INVALID_DEM_EVENTID
#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
#error NvM_ENABLE_ASR3_LEGACY_NAMES is already defined
#endif
/** \brief Enable exporting Legacy Symbolic Names without prefix for AUTOSAR version <= 3.1 rev4. */
#define NvM_ENABLE_ASR3_LEGACY_NAMES 1U

#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */
#if (defined NVM_BLOCK_MULTI)
#error NVM_BLOCK_MULTI is already defined
#endif
/** \brief Symbolic name for Block 0.
 **/
#define NVM_BLOCK_MULTI                            0U

#if (defined NvMConf_NvMBlockDescriptor_NvMBlock_ConfigID)
#error NvMConf_NvMBlockDescriptor_NvMBlock_ConfigID already defined
#endif
/** \brief Symbolic name for Block 1 */
#define NvMConf_NvMBlockDescriptor_NvMBlock_ConfigID   1U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined NvMBlock_ConfigID)
#error NvMBlock_ConfigID already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NvMBlock_ConfigID   1U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_NvMBlock_ConfigID)
#error NvM_NvMBlock_ConfigID already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NvMBlock_ConfigID   1U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_NVM_BLOCK_DEM_DEFAULT)
#error NvMConf_NvMBlockDescriptor_NVM_BLOCK_DEM_DEFAULT already defined
#endif
/** \brief Symbolic name for Block 2 */
#define NvMConf_NvMBlockDescriptor_NVM_BLOCK_DEM_DEFAULT   2U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined NVM_BLOCK_DEM_DEFAULT)
#error NVM_BLOCK_DEM_DEFAULT already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define NVM_BLOCK_DEM_DEFAULT   2U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_NVM_BLOCK_DEM_DEFAULT)
#error NvM_NVM_BLOCK_DEM_DEFAULT already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_NVM_BLOCK_DEM_DEFAULT   2U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ECC_COUNTERS)
#error NvMConf_NvMBlockDescriptor_ECC_COUNTERS already defined
#endif
/** \brief Symbolic name for Block 3 */
#define NvMConf_NvMBlockDescriptor_ECC_COUNTERS   3U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ECC_COUNTERS)
#error ECC_COUNTERS already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ECC_COUNTERS   3U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ECC_COUNTERS)
#error NvM_ECC_COUNTERS already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ECC_COUNTERS   3U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_WARM_RESET_COUNTERS)
#error NvMConf_NvMBlockDescriptor_WARM_RESET_COUNTERS already defined
#endif
/** \brief Symbolic name for Block 4 */
#define NvMConf_NvMBlockDescriptor_WARM_RESET_COUNTERS   4U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined WARM_RESET_COUNTERS)
#error WARM_RESET_COUNTERS already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define WARM_RESET_COUNTERS   4U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_WARM_RESET_COUNTERS)
#error NvM_WARM_RESET_COUNTERS already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_WARM_RESET_COUNTERS   4U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_SOLENOID_UNLOCK_CONF_PARAM)
#error NvMConf_NvMBlockDescriptor_SOLENOID_UNLOCK_CONF_PARAM already defined
#endif
/** \brief Symbolic name for Block 5 */
#define NvMConf_NvMBlockDescriptor_SOLENOID_UNLOCK_CONF_PARAM   5U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined SOLENOID_UNLOCK_CONF_PARAM)
#error SOLENOID_UNLOCK_CONF_PARAM already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define SOLENOID_UNLOCK_CONF_PARAM   5U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_SOLENOID_UNLOCK_CONF_PARAM)
#error NvM_SOLENOID_UNLOCK_CONF_PARAM already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_SOLENOID_UNLOCK_CONF_PARAM   5U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_AUTOTEST_ENABLE_PARAM)
#error NvMConf_NvMBlockDescriptor_AUTOTEST_ENABLE_PARAM already defined
#endif
/** \brief Symbolic name for Block 6 */
#define NvMConf_NvMBlockDescriptor_AUTOTEST_ENABLE_PARAM   6U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined AUTOTEST_ENABLE_PARAM)
#error AUTOTEST_ENABLE_PARAM already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define AUTOTEST_ENABLE_PARAM   6U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_AUTOTEST_ENABLE_PARAM)
#error NvM_AUTOTEST_ENABLE_PARAM already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_AUTOTEST_ENABLE_PARAM   6U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_LOCK_UNLOCK_ECU)
#error NvMConf_NvMBlockDescriptor_LOCK_UNLOCK_ECU already defined
#endif
/** \brief Symbolic name for Block 7 */
#define NvMConf_NvMBlockDescriptor_LOCK_UNLOCK_ECU   7U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined LOCK_UNLOCK_ECU)
#error LOCK_UNLOCK_ECU already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define LOCK_UNLOCK_ECU   7U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_LOCK_UNLOCK_ECU)
#error NvM_LOCK_UNLOCK_ECU already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_LOCK_UNLOCK_ECU   7U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_MEASUREMENT_FRAME_CONFIG)
#error NvMConf_NvMBlockDescriptor_MEASUREMENT_FRAME_CONFIG already defined
#endif
/** \brief Symbolic name for Block 8 */
#define NvMConf_NvMBlockDescriptor_MEASUREMENT_FRAME_CONFIG   8U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined MEASUREMENT_FRAME_CONFIG)
#error MEASUREMENT_FRAME_CONFIG already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define MEASUREMENT_FRAME_CONFIG   8U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_MEASUREMENT_FRAME_CONFIG)
#error NvM_MEASUREMENT_FRAME_CONFIG already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_MEASUREMENT_FRAME_CONFIG   8U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_HW_PART_NUMBER)
#error NvMConf_NvMBlockDescriptor_HW_PART_NUMBER already defined
#endif
/** \brief Symbolic name for Block 9 */
#define NvMConf_NvMBlockDescriptor_HW_PART_NUMBER   9U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined HW_PART_NUMBER)
#error HW_PART_NUMBER already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define HW_PART_NUMBER   9U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_HW_PART_NUMBER)
#error NvM_HW_PART_NUMBER already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_HW_PART_NUMBER   9U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_AEE_TRACEABILITY_NUMBER)
#error NvMConf_NvMBlockDescriptor_AEE_TRACEABILITY_NUMBER already defined
#endif
/** \brief Symbolic name for Block 10 */
#define NvMConf_NvMBlockDescriptor_AEE_TRACEABILITY_NUMBER   10U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined AEE_TRACEABILITY_NUMBER)
#error AEE_TRACEABILITY_NUMBER already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define AEE_TRACEABILITY_NUMBER   10U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_AEE_TRACEABILITY_NUMBER)
#error NvM_AEE_TRACEABILITY_NUMBER already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_AEE_TRACEABILITY_NUMBER   10U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ECU_ASSEMBLY_SERIAL_NUMBER)
#error NvMConf_NvMBlockDescriptor_ECU_ASSEMBLY_SERIAL_NUMBER already defined
#endif
/** \brief Symbolic name for Block 11 */
#define NvMConf_NvMBlockDescriptor_ECU_ASSEMBLY_SERIAL_NUMBER   11U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ECU_ASSEMBLY_SERIAL_NUMBER)
#error ECU_ASSEMBLY_SERIAL_NUMBER already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ECU_ASSEMBLY_SERIAL_NUMBER   11U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ECU_ASSEMBLY_SERIAL_NUMBER)
#error NvM_ECU_ASSEMBLY_SERIAL_NUMBER already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ECU_ASSEMBLY_SERIAL_NUMBER   11U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_PROCESS_MODE)
#error NvMConf_NvMBlockDescriptor_PROCESS_MODE already defined
#endif
/** \brief Symbolic name for Block 12 */
#define NvMConf_NvMBlockDescriptor_PROCESS_MODE   12U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined PROCESS_MODE)
#error PROCESS_MODE already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define PROCESS_MODE   12U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_PROCESS_MODE)
#error NvM_PROCESS_MODE already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_PROCESS_MODE   12U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ECS_VARIANT)
#error NvMConf_NvMBlockDescriptor_ECS_VARIANT already defined
#endif
/** \brief Symbolic name for Block 13 */
#define NvMConf_NvMBlockDescriptor_ECS_VARIANT   13U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ECS_VARIANT)
#error ECS_VARIANT already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ECS_VARIANT   13U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ECS_VARIANT)
#error NvM_ECS_VARIANT already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ECS_VARIANT   13U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_RESERVED_1)
#error NvMConf_NvMBlockDescriptor_RESERVED_1 already defined
#endif
/** \brief Symbolic name for Block 14 */
#define NvMConf_NvMBlockDescriptor_RESERVED_1   14U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined RESERVED_1)
#error RESERVED_1 already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define RESERVED_1   14U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_RESERVED_1)
#error NvM_RESERVED_1 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_RESERVED_1   14U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ECS_ACC_OFFSETS)
#error NvMConf_NvMBlockDescriptor_ECS_ACC_OFFSETS already defined
#endif
/** \brief Symbolic name for Block 15 */
#define NvMConf_NvMBlockDescriptor_ECS_ACC_OFFSETS   15U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ECS_ACC_OFFSETS)
#error ECS_ACC_OFFSETS already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ECS_ACC_OFFSETS   15U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ECS_ACC_OFFSETS)
#error NvM_ECS_ACC_OFFSETS already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ECS_ACC_OFFSETS   15U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ECS_BUCKLE_CONFIG)
#error NvMConf_NvMBlockDescriptor_ECS_BUCKLE_CONFIG already defined
#endif
/** \brief Symbolic name for Block 16 */
#define NvMConf_NvMBlockDescriptor_ECS_BUCKLE_CONFIG   16U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ECS_BUCKLE_CONFIG)
#error ECS_BUCKLE_CONFIG already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ECS_BUCKLE_CONFIG   16U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ECS_BUCKLE_CONFIG)
#error NvM_ECS_BUCKLE_CONFIG already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ECS_BUCKLE_CONFIG   16U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ECS_CODING_VARIANT)
#error NvMConf_NvMBlockDescriptor_ECS_CODING_VARIANT already defined
#endif
/** \brief Symbolic name for Block 17 */
#define NvMConf_NvMBlockDescriptor_ECS_CODING_VARIANT   17U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ECS_CODING_VARIANT)
#error ECS_CODING_VARIANT already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ECS_CODING_VARIANT   17U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ECS_CODING_VARIANT)
#error NvM_ECS_CODING_VARIANT already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ECS_CODING_VARIANT   17U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ECS_ACC_LOWPASS)
#error NvMConf_NvMBlockDescriptor_ECS_ACC_LOWPASS already defined
#endif
/** \brief Symbolic name for Block 18 */
#define NvMConf_NvMBlockDescriptor_ECS_ACC_LOWPASS   18U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ECS_ACC_LOWPASS)
#error ECS_ACC_LOWPASS already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ECS_ACC_LOWPASS   18U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ECS_ACC_LOWPASS)
#error NvM_ECS_ACC_LOWPASS already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ECS_ACC_LOWPASS   18U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_SBS_LAST_STATE)
#error NvMConf_NvMBlockDescriptor_SBS_LAST_STATE already defined
#endif
/** \brief Symbolic name for Block 19 */
#define NvMConf_NvMBlockDescriptor_SBS_LAST_STATE   19U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined SBS_LAST_STATE)
#error SBS_LAST_STATE already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define SBS_LAST_STATE   19U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_SBS_LAST_STATE)
#error NvM_SBS_LAST_STATE already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_SBS_LAST_STATE   19U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ECS_ALGO_OUTPUT_DELAY)
#error NvMConf_NvMBlockDescriptor_ECS_ALGO_OUTPUT_DELAY already defined
#endif
/** \brief Symbolic name for Block 20 */
#define NvMConf_NvMBlockDescriptor_ECS_ALGO_OUTPUT_DELAY   20U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ECS_ALGO_OUTPUT_DELAY)
#error ECS_ALGO_OUTPUT_DELAY already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ECS_ALGO_OUTPUT_DELAY   20U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ECS_ALGO_OUTPUT_DELAY)
#error NvM_ECS_ALGO_OUTPUT_DELAY already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ECS_ALGO_OUTPUT_DELAY   20U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ECS_SENSITIVITY_LUT)
#error NvMConf_NvMBlockDescriptor_ECS_SENSITIVITY_LUT already defined
#endif
/** \brief Symbolic name for Block 21 */
#define NvMConf_NvMBlockDescriptor_ECS_SENSITIVITY_LUT   21U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ECS_SENSITIVITY_LUT)
#error ECS_SENSITIVITY_LUT already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ECS_SENSITIVITY_LUT   21U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ECS_SENSITIVITY_LUT)
#error NvM_ECS_SENSITIVITY_LUT already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ECS_SENSITIVITY_LUT   21U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ECS_SENSITIVITY_OPT)
#error NvMConf_NvMBlockDescriptor_ECS_SENSITIVITY_OPT already defined
#endif
/** \brief Symbolic name for Block 22 */
#define NvMConf_NvMBlockDescriptor_ECS_SENSITIVITY_OPT   22U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ECS_SENSITIVITY_OPT)
#error ECS_SENSITIVITY_OPT already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ECS_SENSITIVITY_OPT   22U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ECS_SENSITIVITY_OPT)
#error NvM_ECS_SENSITIVITY_OPT already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ECS_SENSITIVITY_OPT   22U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ECU_TEMP_CALIBRATION)
#error NvMConf_NvMBlockDescriptor_ECU_TEMP_CALIBRATION already defined
#endif
/** \brief Symbolic name for Block 23 */
#define NvMConf_NvMBlockDescriptor_ECU_TEMP_CALIBRATION   23U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ECU_TEMP_CALIBRATION)
#error ECU_TEMP_CALIBRATION already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ECU_TEMP_CALIBRATION   23U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ECU_TEMP_CALIBRATION)
#error NvM_ECU_TEMP_CALIBRATION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ECU_TEMP_CALIBRATION   23U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ALV_NVM_VERSION)
#error NvMConf_NvMBlockDescriptor_ALV_NVM_VERSION already defined
#endif
/** \brief Symbolic name for Block 24 */
#define NvMConf_NvMBlockDescriptor_ALV_NVM_VERSION   24U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ALV_NVM_VERSION)
#error ALV_NVM_VERSION already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ALV_NVM_VERSION   24U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ALV_NVM_VERSION)
#error NvM_ALV_NVM_VERSION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ALV_NVM_VERSION   24U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_MEAS_FRAME_RAM_ADDR_CFG)
#error NvMConf_NvMBlockDescriptor_MEAS_FRAME_RAM_ADDR_CFG already defined
#endif
/** \brief Symbolic name for Block 25 */
#define NvMConf_NvMBlockDescriptor_MEAS_FRAME_RAM_ADDR_CFG   25U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined MEAS_FRAME_RAM_ADDR_CFG)
#error MEAS_FRAME_RAM_ADDR_CFG already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define MEAS_FRAME_RAM_ADDR_CFG   25U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_MEAS_FRAME_RAM_ADDR_CFG)
#error NvM_MEAS_FRAME_RAM_ADDR_CFG already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_MEAS_FRAME_RAM_ADDR_CFG   25U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ACC_AXIS_ANGLE_CALIBRATION)
#error NvMConf_NvMBlockDescriptor_ACC_AXIS_ANGLE_CALIBRATION already defined
#endif
/** \brief Symbolic name for Block 26 */
#define NvMConf_NvMBlockDescriptor_ACC_AXIS_ANGLE_CALIBRATION   26U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ACC_AXIS_ANGLE_CALIBRATION)
#error ACC_AXIS_ANGLE_CALIBRATION already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ACC_AXIS_ANGLE_CALIBRATION   26U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ACC_AXIS_ANGLE_CALIBRATION)
#error NvM_ACC_AXIS_ANGLE_CALIBRATION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ACC_AXIS_ANGLE_CALIBRATION   26U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_EOL_COUNTERS)
#error NvMConf_NvMBlockDescriptor_EOL_COUNTERS already defined
#endif
/** \brief Symbolic name for Block 27 */
#define NvMConf_NvMBlockDescriptor_EOL_COUNTERS   27U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined EOL_COUNTERS)
#error EOL_COUNTERS already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define EOL_COUNTERS   27U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_EOL_COUNTERS)
#error NvM_EOL_COUNTERS already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_EOL_COUNTERS   27U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_RESERVED_4)
#error NvMConf_NvMBlockDescriptor_RESERVED_4 already defined
#endif
/** \brief Symbolic name for Block 28 */
#define NvMConf_NvMBlockDescriptor_RESERVED_4   28U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined RESERVED_4)
#error RESERVED_4 already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define RESERVED_4   28U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_RESERVED_4)
#error NvM_RESERVED_4 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_RESERVED_4   28U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_AUTOTEST_PARAM)
#error NvMConf_NvMBlockDescriptor_AUTOTEST_PARAM already defined
#endif
/** \brief Symbolic name for Block 29 */
#define NvMConf_NvMBlockDescriptor_AUTOTEST_PARAM   29U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined AUTOTEST_PARAM)
#error AUTOTEST_PARAM already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define AUTOTEST_PARAM   29U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_AUTOTEST_PARAM)
#error NvM_AUTOTEST_PARAM already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_AUTOTEST_PARAM   29U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_PHYS_MEASUREMENTS)
#error NvMConf_NvMBlockDescriptor_PHYS_MEASUREMENTS already defined
#endif
/** \brief Symbolic name for Block 30 */
#define NvMConf_NvMBlockDescriptor_PHYS_MEASUREMENTS   30U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined PHYS_MEASUREMENTS)
#error PHYS_MEASUREMENTS already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define PHYS_MEASUREMENTS   30U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_PHYS_MEASUREMENTS)
#error NvM_PHYS_MEASUREMENTS already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_PHYS_MEASUREMENTS   30U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_SOLENOID_PARAM)
#error NvMConf_NvMBlockDescriptor_SOLENOID_PARAM already defined
#endif
/** \brief Symbolic name for Block 31 */
#define NvMConf_NvMBlockDescriptor_SOLENOID_PARAM   31U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined SOLENOID_PARAM)
#error SOLENOID_PARAM already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define SOLENOID_PARAM   31U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_SOLENOID_PARAM)
#error NvM_SOLENOID_PARAM already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_SOLENOID_PARAM   31U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ECS_PROFILES)
#error NvMConf_NvMBlockDescriptor_ECS_PROFILES already defined
#endif
/** \brief Symbolic name for Block 32 */
#define NvMConf_NvMBlockDescriptor_ECS_PROFILES   32U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ECS_PROFILES)
#error ECS_PROFILES already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ECS_PROFILES   32U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ECS_PROFILES)
#error NvM_ECS_PROFILES already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ECS_PROFILES   32U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ECU_STATE_TIMING_PARAMETERS)
#error NvMConf_NvMBlockDescriptor_ECU_STATE_TIMING_PARAMETERS already defined
#endif
/** \brief Symbolic name for Block 33 */
#define NvMConf_NvMBlockDescriptor_ECU_STATE_TIMING_PARAMETERS   33U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ECU_STATE_TIMING_PARAMETERS)
#error ECU_STATE_TIMING_PARAMETERS already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ECU_STATE_TIMING_PARAMETERS   33U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ECU_STATE_TIMING_PARAMETERS)
#error NvM_ECU_STATE_TIMING_PARAMETERS already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ECU_STATE_TIMING_PARAMETERS   33U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_SPARE_PART_NUMBER)
#error NvMConf_NvMBlockDescriptor_SPARE_PART_NUMBER already defined
#endif
/** \brief Symbolic name for Block 34 */
#define NvMConf_NvMBlockDescriptor_SPARE_PART_NUMBER   34U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined SPARE_PART_NUMBER)
#error SPARE_PART_NUMBER already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define SPARE_PART_NUMBER   34U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_SPARE_PART_NUMBER)
#error NvM_SPARE_PART_NUMBER already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_SPARE_PART_NUMBER   34U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_HARDWARE_NUMBER)
#error NvMConf_NvMBlockDescriptor_HARDWARE_NUMBER already defined
#endif
/** \brief Symbolic name for Block 35 */
#define NvMConf_NvMBlockDescriptor_HARDWARE_NUMBER   35U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined HARDWARE_NUMBER)
#error HARDWARE_NUMBER already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define HARDWARE_NUMBER   35U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_HARDWARE_NUMBER)
#error NvM_HARDWARE_NUMBER already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_HARDWARE_NUMBER   35U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_SYSTEM_NAME_OR_ENGINE_TYPE)
#error NvMConf_NvMBlockDescriptor_SYSTEM_NAME_OR_ENGINE_TYPE already defined
#endif
/** \brief Symbolic name for Block 36 */
#define NvMConf_NvMBlockDescriptor_SYSTEM_NAME_OR_ENGINE_TYPE   36U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined SYSTEM_NAME_OR_ENGINE_TYPE)
#error SYSTEM_NAME_OR_ENGINE_TYPE already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define SYSTEM_NAME_OR_ENGINE_TYPE   36U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_SYSTEM_NAME_OR_ENGINE_TYPE)
#error NvM_SYSTEM_NAME_OR_ENGINE_TYPE already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_SYSTEM_NAME_OR_ENGINE_TYPE   36U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_BLOCK_FBL)
#error NvMConf_NvMBlockDescriptor_BLOCK_FBL already defined
#endif
/** \brief Symbolic name for Block 37 */
#define NvMConf_NvMBlockDescriptor_BLOCK_FBL   37U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined BLOCK_FBL)
#error BLOCK_FBL already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define BLOCK_FBL   37U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_BLOCK_FBL)
#error NvM_BLOCK_FBL already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_BLOCK_FBL   37U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ODX_FILE_IDENTIFIER)
#error NvMConf_NvMBlockDescriptor_ODX_FILE_IDENTIFIER already defined
#endif
/** \brief Symbolic name for Block 38 */
#define NvMConf_NvMBlockDescriptor_ODX_FILE_IDENTIFIER   38U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ODX_FILE_IDENTIFIER)
#error ODX_FILE_IDENTIFIER already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ODX_FILE_IDENTIFIER   38U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ODX_FILE_IDENTIFIER)
#error NvM_ODX_FILE_IDENTIFIER already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ODX_FILE_IDENTIFIER   38U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ODX_FILE_VERSION)
#error NvMConf_NvMBlockDescriptor_ODX_FILE_VERSION already defined
#endif
/** \brief Symbolic name for Block 39 */
#define NvMConf_NvMBlockDescriptor_ODX_FILE_VERSION   39U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ODX_FILE_VERSION)
#error ODX_FILE_VERSION already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ODX_FILE_VERSION   39U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ODX_FILE_VERSION)
#error NvM_ODX_FILE_VERSION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ODX_FILE_VERSION   39U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ECU_SERIAL_NUMBER)
#error NvMConf_NvMBlockDescriptor_ECU_SERIAL_NUMBER already defined
#endif
/** \brief Symbolic name for Block 40 */
#define NvMConf_NvMBlockDescriptor_ECU_SERIAL_NUMBER   40U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ECU_SERIAL_NUMBER)
#error ECU_SERIAL_NUMBER already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ECU_SERIAL_NUMBER   40U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ECU_SERIAL_NUMBER)
#error NvM_ECU_SERIAL_NUMBER already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ECU_SERIAL_NUMBER   40U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_LOGICAL_SW_BLOCK_VERSION)
#error NvMConf_NvMBlockDescriptor_LOGICAL_SW_BLOCK_VERSION already defined
#endif
/** \brief Symbolic name for Block 41 */
#define NvMConf_NvMBlockDescriptor_LOGICAL_SW_BLOCK_VERSION   41U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined LOGICAL_SW_BLOCK_VERSION)
#error LOGICAL_SW_BLOCK_VERSION already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define LOGICAL_SW_BLOCK_VERSION   41U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_LOGICAL_SW_BLOCK_VERSION)
#error NvM_LOGICAL_SW_BLOCK_VERSION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_LOGICAL_SW_BLOCK_VERSION   41U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_HARDWARE_VERSION_NUMBER)
#error NvMConf_NvMBlockDescriptor_HARDWARE_VERSION_NUMBER already defined
#endif
/** \brief Symbolic name for Block 42 */
#define NvMConf_NvMBlockDescriptor_HARDWARE_VERSION_NUMBER   42U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined HARDWARE_VERSION_NUMBER)
#error HARDWARE_VERSION_NUMBER already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define HARDWARE_VERSION_NUMBER   42U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_HARDWARE_VERSION_NUMBER)
#error NvM_HARDWARE_VERSION_NUMBER already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_HARDWARE_VERSION_NUMBER   42U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_APP_SOFTWARE_VERSION_NUMBER)
#error NvMConf_NvMBlockDescriptor_APP_SOFTWARE_VERSION_NUMBER already defined
#endif
/** \brief Symbolic name for Block 43 */
#define NvMConf_NvMBlockDescriptor_APP_SOFTWARE_VERSION_NUMBER   43U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined APP_SOFTWARE_VERSION_NUMBER)
#error APP_SOFTWARE_VERSION_NUMBER already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define APP_SOFTWARE_VERSION_NUMBER   43U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_APP_SOFTWARE_VERSION_NUMBER)
#error NvM_APP_SOFTWARE_VERSION_NUMBER already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_APP_SOFTWARE_VERSION_NUMBER   43U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ECS_STEPS)
#error NvMConf_NvMBlockDescriptor_ECS_STEPS already defined
#endif
/** \brief Symbolic name for Block 44 */
#define NvMConf_NvMBlockDescriptor_ECS_STEPS   44U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ECS_STEPS)
#error ECS_STEPS already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ECS_STEPS   44U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ECS_STEPS)
#error NvM_ECS_STEPS already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ECS_STEPS   44U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NvMConf_NvMBlockDescriptor_ECS_PARAMETERS)
#error NvMConf_NvMBlockDescriptor_ECS_PARAMETERS already defined
#endif
/** \brief Symbolic name for Block 45 */
#define NvMConf_NvMBlockDescriptor_ECS_PARAMETERS   45U


#if (defined NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined NvM_ENABLE_ASR3_LEGACY_NAMES)
    
#if (defined ECS_PARAMETERS)
#error ECS_PARAMETERS already defined
#endif
/** \brief Export symbolic name value without prefix (AUTOSAR version <= 3.1 rev4) */
#define ECS_PARAMETERS   45U
#endif /* NvM_ENABLE_ASR3_LEGACY_NAMES */


#if (defined NvM_ECS_PARAMETERS)
#error NvM_ECS_PARAMETERS already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define NvM_ECS_PARAMETERS   45U
#endif /* NVM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS)
#error NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS is already defined
#endif
/** \brief Defines the number of all configured blocks including the reserved Block 0.
 **/
#define NVM_TOTAL_NUMBER_OF_NVRAM_BLOCKS 46U

#if (defined NVM_BLOCK_ID_MAX)
#error NVM_BLOCK_ID_MAX is already defined
#endif
/** \brief Defines the number of all configured blocks including the reserved Block 0.
 **/
#define NVM_BLOCK_ID_MAX 45U



#if (defined NVM_JOB_PRIORITIZATION)
#error NVM_JOB_PRIORITIZATION is already defined
#endif
/** \brief Defines whether the immediate priority queue is used.
 **
 **        Range:
 **        STD_ON  : Immediate priority queue is used.
 **        STD_OFF : Immediate priority queue is not usesd.
 **/
#define NVM_JOB_PRIORITIZATION           STD_ON

#if (defined NVM_INTERNAL_BUFFER_SIZE)
#error NVM_INTERNAL_BUFFER_SIZE is already defined
#endif
/** \brief Defines the size of the internal data buffer
 **/
#define NVM_INTERNAL_BUFFER_SIZE         178U

#if (defined NVM_MIRROR_SIZE)
#error NVM_MIRROR_SIZE is already defined
#endif
/* !LINKSTO NVM512,1, NVM513,1 */
/** \brief Defines the size of the NvM internal mirror for explicit synchronization
 **/
#define NVM_MIRROR_SIZE                  0U
#if (defined NVM_RAMBLOCK_CRC_BUFFER_SIZE)
#error NVM_RAMBLOCK_CRC_BUFFER_SIZE is already defined
#endif
/** \brief Defines the size of the buffer for storing RAM block CRC values.
 **/
#define NVM_RAMBLOCK_CRC_BUFFER_SIZE     2U

#if (defined NVM_NVBLOCK_CRC_BUFFER_SIZE)
#error NVM_NVBLOCK_CRC_BUFFER_SIZE is already defined
#endif
/** \brief Defines the size of the buffer for storing NV block CRC values.
 **/
#define NVM_NVBLOCK_CRC_BUFFER_SIZE     0U

#if (defined NVM_STORED_CRC_SIZE)
#error NVM_STORED_CRC_SIZE is already defined
#endif
/** \brief Defines the size of the buffer for storing CRC values for redundant block.
 **/
#define NVM_STORED_CRC_SIZE              2U

#if (defined NVM_CRYPTO_TIMEOUT)
#error NVM_CRYPTO_TIMEOUT is already defined
#endif
/** \brief Defines the maximum number of calls to the crypto hook for a single block.
**         This is currently hardcoded but is need as a reference to unblock the memory stack in case
**         crypto stack get's stuck.
 **/
#define NVM_CRYPTO_TIMEOUT  1000U

#if (defined NVM_SIZE_STANDARD_JOB_QUEUE)
#error NVM_SIZE_STANDARD_JOB_QUEUE is already defined
#endif
/** \brief The size of the standard job queue.
 **        One entry is reserved for WriteAll or ReadAll or ValidateAll requests,
 **        so the configured value is incremented by one.
 **/
#define NVM_SIZE_STANDARD_JOB_QUEUE      11U

#if (defined NVM_SIZE_IMMEDIATE_JOB_QUEUE)
#error NVM_SIZE_IMMEDIATE_JOB_QUEUE is already defined
#endif
/** \brief The size of the immediate job queue.
 **/
#define NVM_SIZE_IMMEDIATE_JOB_QUEUE     3U

#if (defined NVM_NUM_USED_DEVICES)
#error NVM_NUM_USED_DEVICES is already defined
#endif
/** \brief Number of devices configured in the lower layers that are accessed thru NvM.
 **/
#define NVM_NUM_USED_DEVICES 0x01U

#if (defined NVM_CONFIGURATIONID_SIZE)
#error NVM_CONFIGURATIONID_SIZE is already defined
#endif
#if (defined NVM_CONFIGURATIONID_PLUSCRC_SIZE)
#error NVM_CONFIGURATIONID_PLUSCRC_SIZE is already defined
#endif
/** \brief The RAM data buffer for the configuration Id shall be defined
 **        according the following rules:
 **
 **        if (for block 1:    NvMBlockUseCrc     == TRUE
 **                   && NvMCalcRamBlockCrc == TRUE
 **                   && NvMBlockCrcType    == NVM_CRC_TYPE_8
 **           )
 **        then   'VAR(uint16,NVM_VAR)        NvM_ConfigurationId[2];'
 **        else
 **        if (for block 1:    NvMBlockUseCrc     == TRUE
 **                   && NvMCalcRamBlockCrc == TRUE
 **                   && NvMBlockCrcType    == NVM_CRC_TYPE_16
 **           )
 **        then   'VAR(uint16,NVM_VAR)        NvM_ConfigurationId[2];'
 **        else
 **        if (for block 1:    NvMBlockUseCrc     == TRUE
 **                          && NvMCalcRamBlockCrc == TRUE
 **                          && NvMBlockCrcType    == NVM_CRC_TYPE_32
 **           )
 **        then  'VAR(uint16,NVM_VAR)  NvM_ConfigurationId[3];'
 **        else  'VAR(uint16,NVM_VAR) NvM_ConfigurationId[1];'
 **/

/** \brief Defines the size in Bytes of the compiled configuration Id.
 **/
#define NVM_CONFIGURATIONID_SIZE        2U

/** \brief Defines the RamBlock size of the Block1(ConfigurationId block).
 **/
#define NVM_CONFIGURATIONID_PLUSCRC_SIZE        4U

#if (defined NVM_CRC_NUM_OF_BYTES)
#error NVM_CRC_NUM_OF_BYTES is already defined
#endif
/** \brief Defines the maximum number of user data bytes for which the CRC
 **        calculation is not interrupted.
 **/
#define NVM_CRC_NUM_OF_BYTES             65535U

#if (defined NVM_DATASET_SELECTION_BITS)
#error NVM_DATASET_SELECTION_BITS is already defined
#endif
/** \brief Defines the number of bits set aside for data set selection
 **/
#define NVM_DATASET_SELECTION_BITS       4U

#if (defined NVM_REPEAT_MIRROR_OPERATIONS)
#error NVM_REPEAT_MIRROR_OPERATIONS is already defined
#endif
/** \brief Defines the number of retries to let the application copy data to or from
 **        the NvM module's mirror before postponing the current job.
 **/
#define NVM_REPEAT_MIRROR_OPERATIONS     0U

#if (defined NVM_DRV_MODE_SWITCH)
#error NVM_DRV_MODE_SWITCH is already defined
#endif
/** \brief determines if NvM_WriteAll() and NvM_ReadAll() must switch to fast mode.
 **/
#define NVM_DRV_MODE_SWITCH              STD_ON

#if (defined NVM_NUMBER_OF_NON_RESISTANT_TO_CHANGED_SW_BLOCKS)
#error NVM_NUMBER_OF_NON_RESISTANT_TO_CHANGED_SW_BLOCKS is already defined
#endif
/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMResistantToChangedSw set to false.
 **/
#define NVM_NUMBER_OF_NON_RESISTANT_TO_CHANGED_SW_BLOCKS    45U

#if (defined NVM_NUMBER_OF_SELECT_BLOCK_FOR_READALL_BLOCKS)
#error NVM_NUMBER_OF_SELECT_BLOCK_FOR_READALL_BLOCKS is already defined
#endif
/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMSelectBlockForReadAll set to true.
 **        Block 0 is reserved and independent of this parameter Block 1 is read as part of the NvM_ReadAll.
 **/
#define NVM_NUMBER_OF_SELECT_BLOCK_FOR_READALL_BLOCKS   44U

#if (defined NVM_NUMBER_OF_SELECT_BLOCK_FOR_FIRSTINITALL_BLOCKS)
#error NVM_NUMBER_OF_SELECT_BLOCK_FOR_FIRSTINITALL_BLOCKS is already defined
#endif
/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMSelectBlockForFirstInitAll set to true.
 **/
#define NVM_NUMBER_OF_SELECT_BLOCK_FOR_FIRSTINITALL_BLOCKS   0U

#if (defined NVM_NUMBER_OF_SELECT_BLOCK_FOR_WRITEALL)
#error NVM_NUMBER_OF_SELECT_BLOCK_FOR_WRITEALL is already defined
#endif
/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMSelectBlockForWriteAll set to true.
  **/
#define NVM_NUMBER_OF_SELECT_BLOCK_FOR_WRITEALL   44U

#if (defined NVM_NUMBER_OF_SELECT_BLOCK_FOR_VALIDATEALL)
#error NVM_NUMBER_OF_SELECT_BLOCK_FOR_VALIDATEALL is already defined
#endif
/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMBlockUseAutoValidation set to true.
 **/
#define NVM_NUMBER_OF_SELECT_BLOCK_FOR_VALIDATEALL   0U

#if (defined NVM_NUMBER_OF_DATASET_BLOCKS)
#error NVM_NUMBER_OF_DATASET_BLOCKS is already defined
#endif
/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMBlockManagementType
 **        set to NVM_BLOCK_DATASET.
 **/
#define NVM_NUMBER_OF_DATASET_BLOCKS                    0U

#if (defined NVM_NUMBER_OF_INIT_BLOCK_CALLBACK)
#error NVM_NUMBER_OF_INIT_BLOCK_CALLBACK is already defined
#endif
/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMInitBlockCallback set to not null
 **        NvMProvideRteInitBlockPort is set to true.
 **/
#define NVM_NUMBER_OF_INIT_BLOCK_CALLBACK               0U

#if (defined NVM_NUMBER_OF_SINGLE_BLOCK_CALLBACK)
#error NVM_NUMBER_OF_SINGLE_BLOCK_CALLBACK is already defined
#endif
/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMSingleBlockCallback set to not null.
 **/
#define NVM_NUMBER_OF_SINGLE_BLOCK_CALLBACK             0U

#if (defined NVM_NUMBER_OF_CALC_CRC8_BLOCKS)
#error NVM_NUMBER_OF_CALC_CRC8_BLOCKS is already defined
#endif
/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMBlockUseCrc set to true and
 **        NvMBlockCrcType set to NVM_CRC8.
 **/
#define NVM_NUMBER_OF_CALC_CRC8_BLOCKS                 0

#if (defined NVM_NUMBER_OF_CALC_CRC16_BLOCKS)
#error NVM_NUMBER_OF_CALC_CRC16_BLOCKS is already defined
#endif
/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMBlockUseCrc set to true and
 **        NvMBlockCrcType set to NVM_CRC16.
 **/
#define NVM_NUMBER_OF_CALC_CRC16_BLOCKS                 1

#if (defined NVM_NUMBER_OF_CALC_CRC32_BLOCKS)
#error NVM_NUMBER_OF_CALC_CRC32_BLOCKS is already defined
#endif
/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMBlockUseCrc set to true and
 **        NvMBlockCrcType set to NVM_CRC32.
 **/
#define NVM_NUMBER_OF_CALC_CRC32_BLOCKS                 0

#if (defined NVM_NUMBER_OF_CRC_BLOCKS)
#error NVM_NUMBER_OF_CRC_BLOCKS is already defined
#endif
/** \brief Defines the number of NVRAM Blocks which have
 **        the configuration parameter NvMBlockUseCrc set to true and
 **        NvMBlockCrcType set to NVM_CRC32.
 **/
#define NVM_NUMBER_OF_CRC_BLOCKS                 1

#if (defined NVM_CRC_COMP_MECH)
#error NVM_CRC_COMP_MECH is already defined
#endif
/** \brief Defines whether CRC Compare mechanism is turned ON for any block
 **        by checking the number of NVRAM Blocks having NvMBlockUseCRCCompMechanism set to true.
 **/
#define NVM_CRC_COMP_MECH                          STD_OFF

#if (defined NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFO)
#error NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFO is already defined
#endif
/** \brief Defines whether BswM job status info is enabled/disabled
 **        by checking NvMBswMMultiBlockJobStatusInformation set to true.
 **/
#define NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFO            STD_OFF

#if (defined NVM_BSWM_BLOCK_STATUS_INFO)
#error NVM_BSWM_BLOCK_STATUS_INFO is already defined
#endif
/** \brief Defines whether BswM block status info is enabled/disabled
 **        by checking the number of NVRAM blocks having
 **        NvMBswMBlockStatusInformation set to true.
 **/
#define NVM_BSWM_BLOCK_STATUS_INFO                      STD_OFF

#if (defined NVM_WRITE_VERIFICATION)
#error NVM_WRITE_VERIFICATION is already defined
#endif
/** \brief Defines whether Write verification is turned on or not
 **        by checking the number of NVRAM Blocks having NvMWriteVerification set to true.
 **/
#define NVM_WRITE_VERIFICATION                          STD_OFF

#if (defined NVM_WRITE_VERIFICATION_BUFFER_SIZE)
#error NVM_WRITE_VERIFICATION_BUFFER_SIZE is already defined
#endif
/** \brief Defines the size of the Write verification buffer.
 **       This is used for normal post writing verification and also for pre writing verification.
 **/
#define NVM_WRITE_VERIFICATION_BUFFER_SIZE              178

#if (defined NVM_PRE_WRITE_DATA_COMP)
#error NVM_PRE_WRITE_DATA_COMP is already defined
#endif
/** \brief Defines whether Pre Write Data Comparison is turned on or not
 **        by checking the number of NVRAM Blocks having NvMPreWriteDataComp set to true.
 **/
#define NVM_PRE_WRITE_DATA_COMP                        STD_OFF

#if (defined NVM_STATIC_BLOCKID_CHECK)
#error NVM_STATIC_BLOCKID_CHECK is already defined
#endif
/** \brief Defines whether Static Block Id check is turned on or not
 **        by checking the number of NVRAM Blocks having NvMStaticBlockIDCheck set to true.
 **/
#define NVM_STATIC_BLOCKID_CHECK                        STD_OFF

#if (defined NVM_SYNC_MECHANISM)
#error NVM_SYNC_MECHANISM is already defined
#endif
/** \brief Defines whether Explicit Synchronization is turned on or not
 **        by checking the number of NVRAM Blocks having NvMBlockUseSyncMechanism set to true.
 **/
#define NVM_SYNC_MECHANISM                              STD_OFF

#if (defined NVM_CBK2011ACTIVE)
#error NVM_CBK2011ACTIVE is already defined
#endif
/** \brief Defines whether the init callback function for NVM is required to be
 **        in ASR 20-11 format.
 **/
#define NVM_CBK2011ACTIVE                              STD_OFF

#if (defined NVM_NUMBER_OF_IMMEDIATE_PRIORITY_BLOCKS)
#error NVM_NUMBER_OF_IMMEDIATE_PRIORITY_BLOCKS is already defined
#endif
/** \brief Defines whether any block is configured with immediate priority
 **        by checking the number of NVRAM Blocks having NvMBlockJobPriority set to zero.
 **/
#define NVM_NUMBER_OF_IMMEDIATE_PRIORITY_BLOCKS         0U

#if (defined NVM_WRITE_BLOCK_ONCE)
#error NVM_WRITE_BLOCK_ONCE is already defined
#endif
/** \brief Defines whether any block is configured with write block once
 **        by checking the number of NVRAM Blocks having NvMWriteBlockOnce set to zero.
 **/
#define NVM_WRITE_BLOCK_ONCE                            STD_OFF

#if (defined NVM_NUMBER_OF_WRITE_RETRY_BLOCKS)
#error NVM_NUMBER_OF_WRITE_RETRY_BLOCKS is already defined
#endif
/** \brief Defines whether any block is configured with write retry
 **        by checking the number of NVRAM Blocks having NvMMaxNumOfWriteRetries set to non-zero.
 **/
#define NVM_NUMBER_OF_WRITE_RETRY_BLOCKS                45U

#if (defined NVM_NUMBER_OF_READ_RETRY_BLOCKS)
#error NVM_NUMBER_OF_READ_RETRY_BLOCKS is already defined
#endif
/** \brief Defines whether any block is configured with read retry
 **        by checking the number of NVRAM Blocks having NvMMaxNumOfReadRetries set to non-zero.
 **/
#define NVM_NUMBER_OF_READ_RETRY_BLOCKS                 43U

#if (defined NVM_API_CONFIG_CLASS_1)
#error NVM_API_CONFIG_CLASS_1 is already defined
#endif
/** \brief Defines the NvM Api config class 1.
 **/
#define NVM_API_CONFIG_CLASS_1                          0U

#if (defined NVM_API_CONFIG_CLASS_2)
#error NVM_API_CONFIG_CLASS_2 is already defined
#endif
/** \brief Defines the NvM Api config class 2.
 **/
#define NVM_API_CONFIG_CLASS_2                          1U

#if (defined NVM_API_CONFIG_CLASS_3)
#error NVM_API_CONFIG_CLASS_3 is already defined
#endif
/** \brief Defines the NvM Api config class 3.
 **/
#define NVM_API_CONFIG_CLASS_3                          2U

#if (defined NVM_API_CONFIG_CLASS)
#error NVM_API_CONFIG_CLASS is already defined
#endif
/** \brief Defines API config class
 **        NVM_API_CONFIG_CLASS_3 - all API functions are available
 **        NVM_API_CONFIG_CLASS_2 - an intermediate set API functions is available
 **        NVM_API_CONFIG_CLASS_1 - a minimum set of API functions is available
 **/
#define NVM_API_CONFIG_CLASS                            NVM_API_CONFIG_CLASS_3

#if (defined NVM_POLLING_MODE)
#error NVM_POLLING_MODE is already defined
#endif
/** \brief Preprocessor switch to enable/disable the polling mode in the NVRAM Manager
 **        and at the same time disable/enable the callback functions useable by lower layers.
 **
 **        STD_ON:  Polling mode enabled/callbacks disabled
 **        STD_OFF: Polling mode disabled/callbacks enabled
 **/
#define NVM_POLLING_MODE                 STD_ON

#if (defined NVM_DYNAMIC_CONFIGURATION)
#error NVM_DYNAMIC_CONFIGURATION is already defined
#endif
/** \brief Preprocessor switch to enable the dynamic configuration management handling
 **        by the NvM_ReadAll request.
 **        STD_ON: Dynamic configuration management handling enabled.
 **        STD_OFF: Dynamic configuration management handling disabled.
 **/
#define NVM_DYNAMIC_CONFIGURATION                 STD_ON

#if (defined NVM_USE_COMPILED_CONFIGID)
#error NVM_USE_COMPILED_CONFIGID is already defined
#endif
/** \brief Preprocessor switch to enable the usage of configuration ID block content for
 **        configuration change detection.
 **        STD_ON: The compiled configuration id is compared to the content of block 1.
 **        STD_OFF: The user configured a callout for configuration change detection.
 **/
#define NVM_USE_COMPILED_CONFIGID                 STD_ON

#if (defined NVM_RECOVERY_ON_REQUEST)
#error NVM_RECOVERY_ON_REQUEST is already defined
#endif
/** \brief Defines the NvM recovery of redundant blocks on request
 **/
#define NVM_RECOVERY_ON_REQUEST                         0U

#if (defined NVM_AUTOMATIC_RECOVERY)
#error NVM_AUTOMATIC_RECOVERY is already defined
#endif
/** \brief Defines the NvM automatic recovery of redundant blocks
 **/
#define NVM_AUTOMATIC_RECOVERY                          1U

#if (defined NVM_REDUNDANT_BLOCK_RECOVERY)
#error NVM_REDUNDANT_BLOCK_RECOVERY is already defined
#endif
/** \brief Defines NvM behavior in case loss of redundancy is detected for redundant blocks
 **        NVM_RECOVERY_ON_REQUEST - loss of recovery not visible to the user
 **        NVM_AUTOMATIC_RECOVERY - loss of recovery transparent to the user
 **/
#define NVM_REDUNDANT_BLOCK_RECOVERY                    NVM_AUTOMATIC_RECOVERY

#if (defined NVM_READ_BLOCK_HOOK)
#error NVM_READ_BLOCK_HOOK is already defined
#endif
/** \brief Hook functions macros for ReadBlock and WriteBlock. They are called after
 **        the NvM calls the MemIf_Read and before it calls the NvM MemIf_Write
 **        function respectively.
 **/
#define NVM_READ_BLOCK_HOOK(BlockNum, RamBlockDataAddress, BlockLength) \
  do {} while (0)

#if (defined NVM_WRITE_BLOCK_HOOK)
#error NVM_WRITE_BLOCK_HOOK is already defined
#endif
#define NVM_WRITE_BLOCK_HOOK(BlockNum, RamBlockDataAddress, BlockLength) \
  do {} while (0)

#if (defined NVM_MULTI_BLOCK_CALLBACK)
#error NVM_MULTI_BLOCK_CALLBACK is already defined
#endif
/** \brief Multi block callback function macro. It is called
 **        if the NvM multi request NvM_WriteAll() or NvM_ReadAll() or NvM_ValidateAll is
 **        finished.
 **/
#define NVM_MULTI_BLOCK_CALLBACK(sid,errorStatus) \
  BswM_CB_NfyNvMJobEnd((sid),(errorStatus))

#if (defined NVM_SOFTWARE_CHANGE_CALLOUT)
#error NVM_SOFTWARE_CHANGE_CALLOUT is already defined
#endif
/** \brief Software change function macro. It is called
 **        in order to obtain the user Configuration Id.
 **/





#if(defined(NVM_READBLOCK_CALLOUT) || defined(NVM_WRITEBLOCK_CALLOUT) || defined(NVM_RESTOREBLOCKDEFAULTS_CALLOUT) ||\
    defined(NVM_READPRAMBLOCK_CALLOUT) || defined(NVM_WRITEPRAMBLOCK_CALLOUT) || defined(NVM_RESTOREPRAMBLOCKDEFAULTS_CALLOUT)||\
    defined(NVM_INVALIDATENVBLOCK_CALLOUT) || defined(NVM_ERASENVBLOCK_CALLOUT) || defined(NVM_CANCELJOBS_CALLOUT))
/** \brief Macro to flag that any NvM multicore callout is enabled.
 **/
#define NVM_MULTICORE_ENABLED
#endif
#if (defined NVM_ERASED_BLOCK_INVALID)
#error NVM_ERASED_BLOCK_INVALID is already defined
#endif
/** \brief Defines the NvM behavior if erased/not found blocks are reported as INVALID
 **/
#define NVM_ERASED_BLOCK_INVALID                        0U

#if (defined NVM_ERASED_BLOCK_INCONSISTENT)
#error NVM_ERASED_BLOCK_INCONSISTENT is already defined
#endif
/** \brief Defines the NvM behavior if erased/not found blocks are reported as INCONSISTENT
 **/
#define NVM_ERASED_BLOCK_INCONSISTENT                   1U

#if (defined NVM_RESULT_ERASED_BLOCKS)
#error NVM_RESULT_ERASED_BLOCKS is already defined
#endif
/** \brief Defines the reported block result from lower layer for erased/not found blocks.
 **
 **        Range:
 **        MEMIF_BLOCK_INVALID  :     Erased/Not found blocks are reported as invalid.
 **        MEMIF_BLOCK_INCONSISTENT : Erased/Not found blocks are reported as inconsistent.
 **/
#define NVM_RESULT_ERASED_BLOCKS         NVM_ERASED_BLOCK_INVALID

#if (defined NVM_ADMIN_PORT_USED)
#error NVM_ADMIN_PORT_USED is already defined
#endif
/** \brief Rte admin port macro used for declaring NvM_SetBlockProtection()
 **        when Rte usage is enabled but Rte admin port is disabled for all
 **        configured blocks.
 **/
#define NVM_ADMIN_PORT_USED                       STD_OFF

#if (defined NVM_SERVICE_PORT_USED)
#error NVM_SERVICE_PORT_USED is already defined
#endif
/** \brief Rte service port macro used for declaring NvM_GetErrorStatus()
 **        when Rte usage is enabled but Rte service port is disabled for all
 **        configured blocks.
 **/
#define NVM_SERVICE_PORT_USED                       STD_ON

#if (defined NVM_SERVICE_API_NONE)
#error NVM_SERVICE_API_NONE already defined
#endif
/** \brief Definition that no default service API is set **/
#define NVM_SERVICE_API_NONE   0U

#if (defined NVM_SERVICE_API_ASR32)
#error NVM_SERVICE_API_ASR32 already defined
#endif
/** \brief Definition that AUTOSAR 3.2 service API is set as default **/
#define NVM_SERVICE_API_ASR32   32U

#if (defined NVM_SERVICE_API_ASR40)
#error NVM_SERVICE_API_ASR40 already defined
#endif
/** \brief Definition that AUTOSAR 4.0 service API is set as default **/
#define NVM_SERVICE_API_ASR40   40U

#if (defined NVM_SERVICE_API_ASR42)
#error NVM_SERVICE_API_ASR42 already defined
#endif
/** \brief Definition that AUTOSAR 4.2 service API is set as default **/
#define NVM_SERVICE_API_ASR42   42U

  #if (defined NVM_ENABLE_ASR32_SERVICE_API) /* To prevent double declaration */
#error NVM_ENABLE_ASR32_SERVICE_API already defined
#endif /* if (defined NVM_ENABLE_ASR32_SERVICE_API) */
/** \brief Definition whether AUTOSAR 3.2 service API is enabled **/
#define NVM_ENABLE_ASR32_SERVICE_API                   STD_OFF

#if (defined NVM_ENABLE_ASR40_SERVICE_API) /* To prevent double declaration */
#error NVM_ENABLE_ASR40_SERVICE_API already defined
#endif /* if (defined NVM_ENABLE_ASR40_SERVICE_API) */
/** \brief Definition whether AUTOSAR 4.0 service API is enabled **/
#define NVM_ENABLE_ASR40_SERVICE_API                   STD_OFF

#if (defined NVM_ENABLE_ASR42_SERVICE_API) /* To prevent double declaration */
#error NVM_ENABLE_ASR42_SERVICE_API already defined
#endif /* if (defined NVM_ENABLE_ASR42_SERVICE_API) */
/** \brief Definition whether AUTOSAR 4.2 service API is enabled **/
#define NVM_ENABLE_ASR42_SERVICE_API                   STD_ON

#if (defined NVM_DEFAULT_ASR_SERVICE_API) /* To prevent double declaration */
#error NVM_DEFAULT_ASR_SERVICE_API already defined
#endif /* if (defined NVM_DEFAULT_ASR_SERVICE_API) */
/** \brief Definition of default service API **/
#define NVM_DEFAULT_ASR_SERVICE_API                    NVM_SERVICE_API_ASR42


/*================[constants user application section]================*/

 /** \brief Stores the value of the configuration ID set by the user.
  **/
#define NVM_START_SEC_CONFIG_DATA_16
#include <NvM_MemMap.h>
extern CONST( uint16,NVM_CONST ) NvM_CompiledConfigurationId;
#define NVM_STOP_SEC_CONFIG_DATA_16
#include <NvM_MemMap.h>



 
 /*==================[BC type definitions]======================================*/
/**  \brief Defines the data type BC index can take. It can be uint8 or uint16
           depending on the numbers of blocks configured with BC.
 **/
#if (NVM_BC_NR_OF_BLOCKS < 256)
typedef uint8 uintBC;
#else
typedef uint16 uintBC;
#endif

/*================[variables user application data section]================*/

/** \brief Stores the calculated CRC values in RAM
 **/

#define NVM_START_SEC_VAR_INIT_16
#include <NvM_MemMap.h>
extern VAR(uint16,NVM_APPL_DATA) NvM_CalcCrc_CalcBuffer;
#define NVM_STOP_SEC_VAR_INIT_16
#include <NvM_MemMap.h>


/*===============[end of variables user application data section]==========*/

/*==================[external function declarations]========================*/



/*------------------[Defensive programming]---------------------------------*/

#if (defined NVM_DEFENSIVE_PROGRAMMING_ENABLED)
#error NVM_DEFENSIVE_PROGRAMMING_ENABLED is already defined
#endif
/** \brief Defensive programming usage
 **
 ** En- or disables the usage of the defensive programming */
#define NVM_DEFENSIVE_PROGRAMMING_ENABLED   STD_OFF

#if (defined NVM_PRECONDITION_ASSERT_ENABLED)
#error NVM_PRECONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Precondition assertion usage
 **
 ** En- or disables the usage of precondition assertion checks */
#define NVM_PRECONDITION_ASSERT_ENABLED     STD_OFF

#if (defined NVM_POSTCONDITION_ASSERT_ENABLED)
#error NVM_POSTCONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Postcondition assertion usage
 **
 ** En- or disables the usage of postcondition assertion checks */
#define NVM_POSTCONDITION_ASSERT_ENABLED    STD_OFF

#if (defined NVM_UNREACHABLE_CODE_ASSERT_ENABLED)
#error NVM_UNREACHABLE_CODE_ASSERT_ENABLED is already defined
#endif
/** \brief Unreachable code assertion usage
 **
 ** En- or disables the usage of unreachable code assertion checks */
#define NVM_UNREACHABLE_CODE_ASSERT_ENABLED STD_OFF

#if (defined NVM_INVARIANT_ASSERT_ENABLED)
#error NVM_INVARIANT_ASSERT_ENABLED is already defined
#endif
/** \brief Invariant assertion usage
 **
 ** En- or disables the usage of invariant assertion checks */
#define NVM_INVARIANT_ASSERT_ENABLED        STD_OFF

#if (defined NVM_STATIC_ASSERT_ENABLED)
#error NVM_STATIC_ASSERT_ENABLED is already defined
#endif
/** \brief Static assertion usage
 **
 ** En- or disables the usage of static assertion checks */
#define NVM_STATIC_ASSERT_ENABLED           STD_OFF


/*==================[ end of external function declarations]================*/
#endif /* ifndef NVM_CFG_H */
/*==================[end of file NvM_Cfg.h]==================================*/
