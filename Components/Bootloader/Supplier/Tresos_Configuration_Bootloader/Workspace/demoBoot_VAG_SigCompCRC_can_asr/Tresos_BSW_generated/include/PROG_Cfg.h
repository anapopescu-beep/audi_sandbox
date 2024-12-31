/*********************************************************************************/
/*                                                                               */
/*                                BOOT Layers                                    */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                                 PROG configuration                            */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file PROG_Cfg.h                      */
/*%%  |                             |  %%  \brief PROG layer include plugin file */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 2.48.0 BL3              */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*********************************************************************************/
/* Copyright 2010 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*********************************************************************************/
#ifndef PROG_CFG_H
#define PROG_CFG_H

/* to support ASR 4.3 CSM-Demo wrapper for the BL */

/* ASR 4.3 Crypto stack is absent */
#define PROG_CSMASR43_USED                              STD_OFF
#define CSM_INDEX(job_name)                             job_name

#define PROG_CSM_SETKEY_ENABLED                         STD_OFF
#define PROG_CSM_CANCELJOB_ENABLED                      STD_OFF

#define PROG_CUSTOM_CSMSTARTPREPROCESS_ENABLED          STD_OFF


#define PROG_HASHFIN_SENDFRP                            STD_OFF

#define PROG_SIGNFIN_SENDFRP                            STD_OFF

#define PROG_STREAMSTART_ENABLE                         STD_OFF


#define PROG_FLASHWRAPPER_ENABLED      STD_ON
#define PROG_REPROGMEMM_ENABLED        STD_OFF


#define PROG_IMPL_0                                     0U
#define PROG_IMPL_1                                     1U
#define PROG_IMPL_2                                     2U
#define PROG_IMPL_3                                     3U
#define PROG_IMPL_4                                     4U
#define PROG_IMPL_5                                     5U
#define PROG_IMPL_10                                    10U
#define PROG_IMPL_11                                    11U
#define PROG_IMPL_20                                    20U
#define PROG_IMPL_30                                    30U
#define PROG_IMPL_31                                    31U
#define PROG_IMPL_40                                    40U
#define PROG_IMPL_50                                    50U
#define PROG_IMPL_60                                    60U
#define PROG_IMPL_80                                    80U
#define PROG_IMPL_90                                    90U
#define PROG_IMPL_91                                    91U


#define PROG_MSG_BYTE_INDEX(x)                          (u8) (x - PROG_RESPONSE_PARAMETERS_OFFSET)


/* Feature default configuration */
#define PROG_ERASE_ALFI                                 STD_OFF

/* Default compression algo value */
#define PROG_DFI_COMPRESSED_VAL                         0xa0U

/* Default encryption algo value */
#define PROG_DFI_ENCRYPTED_VAL                          0xaU

/* Default compression and encryption algo value */
#define PROG_DFI_COMPRESSED_ENCRYPTED_VAL               0xaaU

#define PROG_NODECRYPTION_NOCOMPRESSION 0x00
/* Verification variant define */

#define PROG_VERIFICATION_CRC                           0U
#define PROG_VERIFICATION_SIGNATURE_WITH_HASH           1U
#define PROG_VERIFICATION_SIGNATURE                     2U
#define PROG_VERIFICATION_SIGNATURE_AND_CRC             3U
#define PROG_VERIFICATION_SIGNATURE_WITH_HASH_AND_CRC   4U
#define PROG_VERIFICATION_HASH                          5U
#define PROG_VERIFICATION_IN_DFI                        6U



#include "PROG_Responses.h"
#include "PROG_Cfg_Impl40.h"
 


#define PROG_NORESET_SECURITYLEVEL        STD_OFF



#define PROG_CALDECOMPRESS_CFGID                        CalDecompressConfig_0




#define PROG_SEC_LEVEL_LOCK                             0U

#define PROG_CRC16_INIT_VAL                             0xFFFFU
#define PROG_CRC32_INIT_VAL                             0xFFFFFFFFU

#define PROG_CRC_CALC_SIZE                              32U

/* max block length for TransferData */
#define PROG_MAX_BYTE_IN_TD                             4090UL


#define PROG_HSM_UPDATE_ENABLE                         STD_OFF


/* ISO 14 229 : */
/* This parameter is used by the requestDownload positive response message to */
/* inform the client how many data bytes (maxNumberOfBlockLength) shall be */
/* included in each TransferData request message from the client. This length */
/* reflects the complete message length, including the service identifier and */
/* the data parameters present in the TransferData request message. This */
/* parameter allows the client to adapt to the receive buffer size of the server */
/* before it starts transferring data to the server. */
#define PROG_SIZE_OF_NB_BLOCK_LEN                       0x20U


#define PROG_MAX_WRITE_SIZE                             0x20U

/* Polynomial for the CRC calculation */
#define PROG_CRC_TAB_SIZE                               256U

#define PROG_FLASH_CONTEXT_OK                           0x01U
#define PROG_FLASH_CONTEXT_NOT_OK                       0x00U

#define PROG_UDS_SESSION_DEFAULT                        UDS_SESSION_DEFAULT
#define PROG_UDS_SESSION_PROGRAMMING                    UDS_SESSION_PROGRAMMING

/* UDS Session parameter record */
#define PROG_UDS_SPREC                                  UDS_SPREC

/* ISO 14229 : The blockSequenceCounter parameter value starts at 01 hex with    */
/* the first TransferData request that follows the RequestDownload (34 hex) or   */
/* RequestUpload (35 hex) service. Its value is incremented by 1 for each        */
/* subsequent TransferData request. At the value of FF hex the                   */
/* blockSequenceCounter rolls over and starts at 00 hex with the next            */
/* TransferData request message.*/
#define PROG_BLOCK_SEQU_REINIT                          0x00U
#define PROG_BLOCK_SEQU_INIT                            0x01U
#define PROG_BLOCK_SEQU_MAX                             0xFFU

#define PROG_ERASE_BY_ADDR                              0x01U
#define PROG_ERASE_BY_BLOCK_ID                          0x02U
#define PROG_ERASE_BY_DYNAMIC_PARTITION_ID              0x03U

#define PROG_CHECKMEMORY_BY_SEGMENT                     0x01U
#define PROG_CHECKMEMORY_BY_BLOCK                       0x02U

/* Define if the sleep management type */
#define PROG_SLEEP_MANAGEMENT_OFF                       0U
#define PROG_SLEEP_MANAGEMENT_TIMEOUT                   1U
#define PROG_SLEEP_MANAGEMENT_IO                        2U

/* PROG_CRC_CALCULATION values */
#define PROG_NO_CRC                                     0x00U
#define PROG_TD_CRC16                                   0x01U
#define PROG_TD_CRC32                                   0x02U
#define PROG_TD_CRC_CUST                                0x03U
#define PROG_CRC32_LENGTH                               0x04U
#define PROG_PARTIAL_SW_ROUTINE_CRC_LEN                 0x0BU

/* PROG_CRC_ALGO values */
#define PROG_CRC32_ETHERNET                             0x00U
#define PROG_CRC32_INT_STD                              0x01U
#define PROG_CRC16                                      0x02U

#define PROG_MANAGE_PERIOD                              1U

#define PROG_TUNABLE_PARAMETERS_DEACTIVATED             0x00U
#define PROG_TUNABLE_PARAMETERS_ACTIVATED               0x01U
#define PROG_TUNABLE_PARAMETERS                         PROG_TUNABLE_PARAMETERS_DEACTIVATED
#define PROG_SA_AUTHENTICATION_OFF                      0x00U
#define PROG_SA_AUTHENTICATION_0001                     0x01U

#define PROG_SA_SEED_LEN                                (4U)
#define PROG_SA_KEY_LEN                                 (4U)

#define PROG_USE_SA_WITH_CRYPTO                         STD_OFF
#define PROG_SA_AUTHENTICATION_METHOD                   PROG_SA_AUTHENTICATION_OFF


#define PROG_DSC02_DENIED_IN_DEF_SESSION                STD_OFF

#define PROG_DSC_02_PROTECTED_BY_SA                     STD_OFF

#define PROG_DECRYPTION_ENABLE                          STD_ON
#define PROG_CSM_DECRYPTION_ENABLE                          STD_ON

#define PROG_AES_BLOCK_SIZE                               16U
/* Compute the size of the encrypted text from the size of plain text */
#define PROG_CIPHERED_TEXT_SIZE(x)                      (x + (PROG_AES_BLOCK_SIZE- (x % PROG_AES_BLOCK_SIZE)))

#define PROG_COMPRESSION_ENABLE                         STD_ON
#define PROG_DECOMP_SLICING_ENABLE                      STD_OFF
#define PROG_COMPRESSED_DATA_SIZE                       0x01U
#define PROG_DECOMPRESSED_DATA_SIZE                     0x02U
#define PROG_RD_DATA_SIZE_TYPE                          PROG_DECOMPRESSED_DATA_SIZE

#define PROG_BLPDUR_SUPPORT_ENABLE                      STD_ON


#define PROG_DOIP_SUPPORT_ENABLE                        STD_OFF


#define PROG_MEMORY_NB                                  1U
#define PROG_SEGMENT_NB                                 3U

/* Define if the auto-control is used or not */
#define PROG_AUTOCONTROL_ENABLE                         STD_OFF

/* Define if NRC78 shall be sent before starting erasing */
#define PROG_NRC78_ON_ERASE_ENABLE                      STD_ON

/* Define if an NRC78 response shall be systematically sent receiving the Erase request */
#define PROG_NRC78_BEFORE_ERASECHECK                    STD_ON

/* Define if Preliminary Erasing is activated or not */
#define PROG_PRELIM_ERASING_ENABLE                      STD_OFF

/* Define if software shall check if memory is already erased before doing an erase */

#define PROG_ERASE_CHECK_TYPE                           PROG_BLOCK_ERASE_CHECK

/* Define number of sector to erase before sending NRC78 */
#define PROG_NB_OF_SECTOR_TO_ERASE_BEFORE_SENDING_NRC78 255U

/* Enable and disable erasing by sector */


#define PROG_SLICED_ERASING_FOR_NRC78_SENDING STD_ON

/* Define if response shall be sent before resetting software */
#define PROG_RESPOND_BEFORE_RESET                       STD_OFF

/* Define if reset is required while switching from default to default session */
#define PROG_RESET_AFTER_DSC01_IN_DEFAULT_SESSION       STD_OFF

/*Enable the reset after S3 timeout coming from the programming session */
#define PROG_RESET_AFTER_S3_TIMEOUT_IN_PROG_SESSION     STD_ON
/*Enable the reset after S3 timeout coming from the extended session */
#define PROG_RESET_AFTER_S3_TIMEOUT_IN_EXT_SESSION      STD_ON


#define PROG_MULTIPLE_TP_CONNECTIONS_ENABLE             STD_OFF

    
    
    

#define PROG_ACTIVE_CURRENT_SESSION_REQUEST_ENABLE              STD_ON
#define PROG_CURRENT_DIAG_APPLICATION_REQUEST_ENABLE            STD_OFF
#define PROG_GET_PSI_REQUEST_ENABLE                             STD_OFF
#define PROG_GET_BOOT_STATUS_REQUEST_ENABLE                     STD_OFF
#define PROG_GET_PEC_REQUEST_ENABLE                             STD_OFF
#define PROG_GET_ECU_ID_REQUEST_ENABLE                          STD_OFF
#define PROG_GET_ECU_ADDR_REQUEST_ENABLE                        STD_OFF
#define PROG_GET_ECU_NAME_REQUEST_ENABLE                        STD_OFF
#define PROG_GET_SBA_TICKET_REQUEST_ENABLE                      STD_OFF
#define PROG_WRITE_FINGERPRINT_ENABLE                           STD_ON
#define PROG_GET_BOOT_INFO_REQUEST_ENABLE                       STD_OFF



#define PROG_ERASE_MEMORY_REQUEST_ENABLE                        STD_ON
#define PROG_ACTIVE_SBL_REQUEST_ENABLE                          STD_OFF
#define PROG_CHECK_VALID_APPLICATION_ENABLE                        STD_OFF
#define PROG_SUBMITSIGNATURE_ENABLE                        STD_OFF
#define PROG_VALIDATE_APPLICATION_ENABLE                        STD_OFF
#define PROG_CHECK_PROGRAMMING_DEPENDENCIES_REQUEST_ENABLE      STD_OFF
#define PROG_AUTO_CONTROL_REQUEST_ENABLE                        STD_OFF
#define PROG_COHERENCY_PRE_CHECK_ENABLE                         STD_OFF




#define PROG_P2_PROG_SESSION_VAL                        (u16)50U
#define PROG_P2STAR_PROG_SESSION_VAL                    (u16)5000U

#define PROG_FAR_POINTER                                *

extern const tCfgMemorytType m_astCfgMemory[PROG_MEMORY_NB];
extern const tCfgSegmentType stConfigSegment[PROG_SEGMENT_NB];
 

/* Algorithm to be used for OemInd implementation: EB/Custom */
#define PROG_APPLI_CHECK_ALGO_EB                        STD_OFF

#define PROG_FLASH_MEMORY_USE                           PROG_TRUE
#define PROG_FLASH_ERASE_VALUE                          255U
#define PROG_FLASH_ADDR_OFFSET                          0U
#define PROG_FLASH_ACCESS_TYPE                          PROG_MEM_ACCESS_TYPE_READ_WRITE
#define PROG_FLASH_MODE                                 PROG_MEMORY_SYNCHRONOUS


#define PROG_FLASH_EXT_MEMORY_USE                       PROG_FALSE
#define PROG_FLASH_EXT_MODE                             PROG_MEMORY_NOTUSED
#define PROG_FLASH_EXT_ACCESS_TYPE                      PROG_MEMORY_NOTUSED


#define PROG_RAM_MEMORY_USE                             PROG_FALSE
#define PROG_RAM_MODE                                   PROG_MEMORY_NOTUSED
#define PROG_RAM_ERASE_VALUE                            0U


#define PROG_CUSTOM_MEMORY_USE                          PROG_FALSE
#define PROG_CUSTOM_MEMORY_MODE                         PROG_MEMORY_NOTUSED
#define PROG_CUSTOM_MEMORY_ACCESS_TYPE                  PROG_MEMORY_NOTUSED

/* Segment Index */
#define PROG_SEG_BOOTLOADER_SEGMENT                    0x0
#define PROG_SEG_APPLICATION_SEGMENT                    0x1
#define PROG_SEG_CALIBRATION_SEGMENT                    0x2

#define PROG_MEMORY_MEMORY_FLASH                  0x0


#define PROG_OTA_DUALBANK_USED                          STD_OFF

/* Network use definition */
#define PROG_BLPDUR_NETWORK_CAN_SUPPORTED      STD_ON
#define PROG_BLPDUR_NETWORK_FLEXRAY_SUPPORTED  STD_OFF
#define PROG_BLPDUR_NETWORK_ETH_SUPPORTED      STD_OFF
#define PROG_BLPDUR_NETWORK_LIN_SUPPORTED      STD_OFF
#define PROG_BLPDUR_ASR_NETWORK_PRESENT        STD_ON

/* use HSM or not */

#define PROG_HSM_MAC_USED                               STD_OFF


#define PROG_BLU_ACTIVE                                 STD_OFF

#define PROG_CHECKMEMORY_TYPE                           PROG_CHECKMEMORY_BY_BLOCK
#endif /* PROG_CFG_H */
