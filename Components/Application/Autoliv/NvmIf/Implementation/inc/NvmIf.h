#ifndef NvmIf_H_
#define NvmIf_H_ 1

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
   by the module NvmIf, part of the component NvmIf.

******************************************************************************/
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.7.3.5 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/NvmIf/Implementation/inc/project.pj $
*/
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Std_Types.h"

#ifdef __cplusplus
extern "C"  {
#endif
/******************************************************************************
DEFINITION OF CONFIGURATION DEFINES
******************************************************************************/
/**
 * \brief
 *       Preprocessor directive used to enable or disable NvmIf_GetCalibBlockLength function.
 */
#define KU8_NVMIF_ENABLE_GET_CALIB_BLOCK_LENGTH_API       STD_OFF
/**
 * \brief
 *       Preprocessor directive used to enable or disable NvmIf_GetNvmBlockLength function.
 */
#define KU8_NVMIF_ENABLE_GET_NVM_BLOCK_LENGTH_API         STD_ON
/**
 * \brief
 *       Preprocessor directive used to enable or disable NvmIf_GetNvmBlockStatus function.
 */
#define KU8_NVMIF_ENABLE_GET_NVM_BLOCKS_STATUS_API        STD_ON
/**
 * \brief
 *       Preprocessor directive used to enable or disable NvmIf_ReadBlockByAddress function.
 */
#define KU8_NVMIF_ENABLE_READ_BLOCK_BY_ADDRESS_API        STD_ON
/**
 * \brief
 *       Preprocessor directive used to enable or disable NvmIf_ReadNvmBlock function.
 */
#define KU8_NVMIF_ENABLE_READ_NVM_BLOCK_API               STD_OFF
/**
 * \brief
 *       Preprocessor directive used to enable or disable NvmIf_WriteBlockByAddress function.
 */
#define KU8_NVMIF_ENABLE_WRITE_BLOCK_BY_ADDRESS_API       STD_ON
/**
 * \brief
 *       Preprocessor directive used to enable or disable NvmIf_WriteNvmBlock function.
 */
#define KU8_NVMIF_ENABLE_WRITE_NVM_BLOCK_API              STD_ON
/**
 * \brief
 *       Preprocessor directive used to enable or disable NvmIf_SynchronousRecord function.
 */
#define KU8_NVMIF_ENABLE_SYNCHRONOUS_RECORD_API           STD_OFF
/**
 * \brief
 *       Preprocessor directive used to enable or disable NvmIf_GetRamAddressByBlockId function.
 */
#define KU8_NVMIF_ENABLE_GET_RAM_ADDRESS_API              STD_ON
/**
 * \brief
 *       Preprocessor directive used to enable or disable NvmIf_SetRamBlockStatus function.
 */
#define KU8_NVMIF_ENABLE_SET_RAM_BLOCK_STATUS_API         STD_ON
/**
 * \brief
 *       Preprocessor directive used to enable or disable NvmIf_RestorePRAMBlockDefaults function.
 */
#define KU8_NVMIF_ENABLE_RESTORE_PRAM_BLOCK_DEFAULTS_API  STD_ON

/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/

/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
#define NvmIf_START_SEC_CODE
#include "NvmIf_MemMap.h"

#if ( KU8_NVMIF_ENABLE_GET_CALIB_BLOCK_LENGTH_API == STD_ON )
extern void NvmIf_GetCalibBlockLength(u16CalibBlockIdType cu16BlockId, u16NvmBlockLengthType * pu16BlockLength);
#endif

#if ( KU8_NVMIF_ENABLE_GET_NVM_BLOCK_LENGTH_API == STD_ON )
extern void NvmIf_GetNvmBlockLength(NvM_ASR42_BlockIdType cu16BlockId, u16NvmBlockLengthType * pu16BlockLength);
#endif

#if ( KU8_NVMIF_ENABLE_GET_NVM_BLOCKS_STATUS_API == STD_ON )
extern void NvmIf_GetNvmBlockStatus(NvM_ASR42_BlockIdType cu16BlockId, NvM_ASR42_RequestResultType * pu8BlockStatus);
#endif

#if ( KU8_NVMIF_ENABLE_READ_BLOCK_BY_ADDRESS_API == STD_ON )
extern void NvmIf_ReadBlockByAddress(uint32 cu32DestAddress, NvM_ASR42_DstPtrType * pvData);
#endif

#if ( KU8_NVMIF_ENABLE_READ_NVM_BLOCK_API == STD_ON )
extern void NvmIf_ReadNvmBlock(NvM_ASR42_BlockIdType BlockId, NvM_DstPtrType * NvM_DstPtr);
#endif

#if ( KU8_NVMIF_ENABLE_WRITE_BLOCK_BY_ADDRESS_API == STD_ON )
extern void NvmIf_WriteBlockByAddress(uint32 cu32DestAddress, NvM_ASR42_DstPtrType * pvData);
#endif

#if ( KU8_NVMIF_ENABLE_WRITE_NVM_BLOCK_API == STD_ON )
extern void NvmIf_WriteNvmBlock (NvM_ASR42_BlockIdType BlockId, NvM_SrcPtrType * NvM_SrcPtr);
#endif

#if ( KU8_NVMIF_ENABLE_SYNCHRONOUS_RECORD_API == STD_ON )
extern void NvmIf_SynchronousRecord(NvM_ASR42_BlockIdType cu16BlockId, NvM_ASR42_RequestResultType * pu8RequestResult);
#endif

#if ( KU8_NVMIF_ENABLE_GET_RAM_ADDRESS_API == STD_ON )
extern void NvmIf_GetRamAddressByBlockId(NvM_ASR42_BlockIdType BlockId, uint32 *pu32BlockRamAddress);
#endif

#if (KU8_NVMIF_ENABLE_SET_RAM_BLOCK_STATUS_API == STD_ON)
extern void NvmIf_SetRamBlockStatus(NvM_ASR42_BlockIdType u16BlockId, boolean bBlockChanged);
#endif

#if (KU8_NVMIF_ENABLE_RESTORE_PRAM_BLOCK_DEFAULTS_API == STD_ON)
extern void NvmIf_RestorePRAMBlockDefaults(NvM_ASR42_BlockIdType u16BlockId);
#endif

#define NvmIf_STOP_SEC_CODE
#include "NvmIf_MemMap.h"

/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
            }
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* NvmIf_H_ */
