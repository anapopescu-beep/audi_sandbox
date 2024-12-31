/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Crypto
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224
*
*   (c) Copyright 2020-2022 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef CRYPTO_CFG_H
#define CRYPTO_CFG_H

/**
*   @file
*
*   @addtogroup CRYPTO
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

[!INDENT "0"!][!//
[!IF "node:exists(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative)"!][!//
    [!VAR "DerivativeName" = "text:toupper(substring-before(as:modconf("Resource")[1]/ResourceGeneral/ResourceSubderivative,'_'))"!][!//
[!ENDIF!][!//
[!ENDINDENT!][!//
/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Crypto_Types.h"
#include "Csec_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_VENDOR_ID_CFG                       43
#define CRYPTO_AR_RELEASE_MAJOR_VERSION_CFG        4
#define CRYPTO_AR_RELEASE_MINOR_VERSION_CFG        4
#define CRYPTO_AR_RELEASE_REVISION_VERSION_CFG     0
#define CRYPTO_SW_MAJOR_VERSION_CFG                1
#define CRYPTO_SW_MINOR_VERSION_CFG                0
#define CRYPTO_SW_PATCH_VERSION_CFG                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!][!//
[!INCLUDE "Crypto_VersionCheck_Inc.m"!][!//
[!ENDNOCODE!][!//
[!AUTOSPACING!][!//
/* Check if Crypto Cfg header file and Crypto Types header file are of the same vendor */
#if (CRYPTO_VENDOR_ID_CFG != CRYPTO_VENDOR_ID_TYPES)
    #error "Crypto_Cfg.h and Crypto_Types.h have different vendor ids"
#endif

/* Check if Crypto Cfg header file and Crypto Types header file are of the same Autosar version */
#if ((CRYPTO_AR_RELEASE_MAJOR_VERSION_CFG    != CRYPTO_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (CRYPTO_AR_RELEASE_MINOR_VERSION_CFG    != CRYPTO_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (CRYPTO_AR_RELEASE_REVISION_VERSION_CFG != CRYPTO_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
    #error "AutoSar Version Numbers of Crypto_Cfg.h and Crypto_Types.h are different"
#endif

/* Check if Crypto Cfg header file and Crypto Types header file are of the same Software version */
#if ((CRYPTO_SW_MAJOR_VERSION_CFG != CRYPTO_SW_MAJOR_VERSION_TYPES) || \
     (CRYPTO_SW_MINOR_VERSION_CFG != CRYPTO_SW_MINOR_VERSION_TYPES) || \
     (CRYPTO_SW_PATCH_VERSION_CFG != CRYPTO_SW_PATCH_VERSION_TYPES)    \
    )
    #error "Software Version Numbers of Crypto_Cfg.h and Crypto_Types.h are different"
#endif


/* Check if Crypto Cfg header file and Csec Ip header file are of the same vendor */
#if (CRYPTO_VENDOR_ID_CFG != CSEC_IP_VENDOR_ID_H)
    #error "Crypto_Cfg.h and Csec_Ip.h have different vendor ids"
#endif

/* Check if Crypto Cfg header file and Csec Ip header file are of the same Software version */
#if ((CRYPTO_SW_MAJOR_VERSION_CFG != CSEC_IP_SW_MAJOR_VERSION_H) || \
     (CRYPTO_SW_MINOR_VERSION_CFG != CSEC_IP_SW_MINOR_VERSION_H) || \
     (CRYPTO_SW_PATCH_VERSION_CFG != CSEC_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Crypto_Cfg.h and Csec_Ip.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!INDENT "0"!][!//
/* Pre-processor switch to enable/disable development error detection for Crypto API */
#define CRYPTO_DEV_ERROR_DETECT                         ([!IF "CryptoGeneral/CryptoDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable/disable the API to read out the modules version information */
#define CRYPTO_VERSION_INFO_API                         ([!IF "CryptoGeneral/CryptoVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Crypto instance ID value */
#define CRYPTO_INSTANCE_ID                              ((uint8)[!"node:value(CryptoGeneral/CryptoInstanceId)"!])

[!IF "node:exists(CryptoGeneral/CryptoMainFunctionPeriod)"!][!//
    /* Crypto main function period */
    #define CRYPTO_MAIN_FUNCTION_PERIOD                     ([!"node:value(CryptoGeneral/CryptoMainFunctionPeriod)"!])

[!ENDIF!][!//
/* Set asynchronous job process method */
#define CRYPTO_USE_INTERRUPTS_FOR_ASYNC_JOBS            ([!IF "node:value(CryptoGeneral/CryptoAsyncJobProcessMethod) = 'INTERRUPT'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable/disable the support in Crypto_ProcessJob() for handling key management services */
[!IF "node:exists(CryptoKeys)"!][!//
    #define CRYPTO_JOB_KEY_MANAGEMENT_SUPPORT               ([!IF "CryptoGeneral/CryptoJobKeyManagement"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!][!//
    #define CRYPTO_JOB_KEY_MANAGEMENT_SUPPORT               (STD_OFF)
[!ENDIF!][!//

/* Pre-processor switch to disable multicore support in Crypto driver */
#define CRYPTO_ENABLE_MULTICORE_SUPPORT                 (STD_OFF)

/* Max number of partitions configured from the application */
#define CRYPTO_MAX_NUMBER_PARTITIONS_U8                 ((uint8)1U)

/* Number of configured Crypto driver objects */
#define CRYPTO_NUMBER_OF_DRIVER_OBJECTS_U32             ((uint32)[!"num:i(count(CryptoDriverObjects/CryptoDriverObject/*))"!]U)

[!IF "node:exists(CryptoKeys)"!][!//
    /* Compile time switch stating that there is at least one configured key */
    #define CRYPTO_KEYS_EXIST                               (STD_ON)

    /* Number of Crypto keys */
    #define CRYPTO_NUMBER_OF_KEYS_U32                       ((uint32)[!"num:i(count(CryptoKeys/CryptoKey/*))"!]U)

    /* Number of Crypto key elements */
    #define CRYPTO_NUMBER_OF_KEY_ELEMENTS_U32               ((uint32)[!"num:i(count(CryptoKeyElements/CryptoKeyElement/*))"!]U)

    /* Support for enabling alternate mapping of crypto job keys.
    *       STD_ON:  the Crypto driver will read the key related information of Csm jobs from an alternate location which is the cryptoKeyId member of the Crypto_JobType structure.
    *       STD_OFF: the Crypto driver will read the key related information of Csm jobs from the cryIfKeyId member of Crypto_JobPrimitiveInfoType substructure of the Crypto_JobType structure. */
    #define CRYPTO_ENABLE_ALTERNATE_MAPPING_FOR_JOB_KEY     ([!IF "CryptoGeneral/CryptoAlternateJobKeyMapping"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

    /* Identifiers for the blobs of information that need to be stored in NVRAM used by the Crypto driver */
    #define CRYPTO_NVRAM_BLOB_0_ID                          (0U)
    #define CRYPTO_NVRAM_BLOB_1_ID                          (1U)

    /* Sizes for the blobs of information used by the Crypto driver */
    #define CRYPTO_SIZEOF_NVRAM_BLOB_0                      ([!IF "num:i(count(CryptoKeys/CryptoKey/*) mod 8) = 0"!][!"num:i(count(CryptoKeys/CryptoKey/*) div 8 )"!][!ELSE!][!"num:i((count(CryptoKeys/CryptoKey/*) div 8) + 1)"!][!ENDIF!]U)
[!NOCODE!][!//
    [!VAR "sizeOfKeyElemPersistValuesBlob"="0"!][!//
    [!VAR "bKeyElemPersistBlobHasAllBytesZero"="'true'"!][!//
    [!LOOP "CryptoKeyElements/CryptoKeyElement/*"!][!//
        [!IF "node:value(./UseCsecKey)='false' and node:value(./CryptoKeyElementPersist) = 'true' "!][!//
            /* The padding of value for CryptoKeyElementSize */
            [!VAR "sizeOfKeyElemPersistPaddingValuesBlob" = "0"!][!//
            [!IF "contains($DerivativeName, 'S32K11')"!][!//
                [!VAR "sizeOfKeyElemPersistPaddingValuesBlob" = "node:value(./CryptoKeyElementSize) mod 4"!][!//
                [!IF "$sizeOfKeyElemPersistPaddingValuesBlob != 0"!][!//
                    [!VAR "sizeOfKeyElemPersistPaddingValuesBlob" = "(4 - $sizeOfKeyElemPersistPaddingValuesBlob)"!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
            /* If the key element does not use a CSEc key, add the max size of the key element buffer + 4 bytes storing the 32bit value of the actual size */
            [!VAR "sizeOfKeyElemPersistValuesBlob" = "$sizeOfKeyElemPersistValuesBlob + node:value(./CryptoKeyElementSize) + num:i(4) + $sizeOfKeyElemPersistPaddingValuesBlob"!][!//
            [!IF "num:i(string-length(node:value(./CryptoKeyElementInitValue)))!=0"!][!//
                [!VAR "bKeyElemPersistBlobHasAllBytesZero"="'false'"!][!//
            [!ENDIF!][!//
        [!ELSEIF "node:value(./UseCsecKey)='true' and node:value(./CsecKeySlot) != 'CSEC_IP_RAM_KEY'"!][!//
            /* If the key element uses a CSEc key, add the 4 bytes storing the 32bit value of the actual size */
            [!VAR "sizeOfKeyElemPersistValuesBlob" = "$sizeOfKeyElemPersistValuesBlob + num:i(4)"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//
    #define CRYPTO_SIZEOF_NVRAM_BLOB_1                      ([!"num:i($sizeOfKeyElemPersistValuesBlob)"!]U)

[!NOCODE!][!//
    /* Create the initializer for the array with the information that needs to be stored in Nvram for all persistent Key Elements (buffers + actual sizes) */
    [!IF "$sizeOfKeyElemPersistValuesBlob > 0"!][!//
        [!IF "$bKeyElemPersistBlobHasAllBytesZero = 'false'"!][!//
            [!CODE!][!//
            [!INDENT "0"!]
                /* Initializer of NVRAM Blob1 */
                #define CRYPTO_NVRAM_BLOB_1_INITIALIZER                 {        \
            [!ENDINDENT!][!//
            [!ENDCODE!][!//
            [!VAR "curIdx"="0"!][!//
            [!LOOP "CryptoKeyElements/CryptoKeyElement/*"!][!//
                [!IF "node:value(./UseCsecKey)='false' and node:value(./CryptoKeyElementPersist) = 'true' "!][!//
                    /* The padding of value for CryptoKeyElementSize */
                    [!VAR "sizeOfKeyElemPersistPaddingValuesBlob" = "0"!][!//
                    [!IF "contains($DerivativeName, 'S32K11')"!][!//
                        [!VAR "sizeOfKeyElemPersistPaddingValuesBlob" = "node:value(./CryptoKeyElementSize) mod 4"!][!//
                        [!IF "$sizeOfKeyElemPersistPaddingValuesBlob != 0"!][!//
                            [!VAR "sizeOfKeyElemPersistPaddingValuesBlob" = "(4 - $sizeOfKeyElemPersistPaddingValuesBlob)"!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                    /* If the key element does not use a CSEc key, add the 4 bytes storing the 32bit value of the actual size + the max size buffer of the key element */
                    [!INDENT "58"!]
                    [!CODE!][!//
                        /* Offset [!"num:i($curIdx)"!] - Length of [!"node:name(.)"!] */ \
                        [!"num:inttohex(bit:and((bit:shr(num:i(string-length(node:value(./CryptoKeyElementInitValue)) div 2),0)),255),2)"!]U, \
                        [!"num:inttohex(bit:and((bit:shr(num:i(string-length(node:value(./CryptoKeyElementInitValue)) div 2),8)),255),2)"!]U, \
                        [!"num:inttohex(bit:and((bit:shr(num:i(string-length(node:value(./CryptoKeyElementInitValue)) div 2),16)),255),2)"!]U, \
                        [!"num:inttohex(bit:and((bit:shr(num:i(string-length(node:value(./CryptoKeyElementInitValue)) div 2),24)),255),2)"!]U, \
                    [!ENDCODE!][!//
                    [!VAR "curIdx" = "$curIdx + 4"!][!//
                    [!CODE!][!//
                     /* Offset [!"num:i($curIdx)"!] - Buffer of [!"node:name(.)"!] */ \
                    [!ENDCODE!][!//
                    [!VAR "index" = "num:i(-1)"!][!//
                    [!FOR "index" = "num:i(1)" TO "num:i(string-length(node:value(./CryptoKeyElementInitValue)))" STEP "num:i(2)"!][!//
                        [!VAR "curIdx" = "$curIdx + 1"!][!//
                        [!CODE!][!//
                            0x[!"substring(node:value(./CryptoKeyElementInitValue), $index, 2)"!]U[!IF "num:i($curIdx) < num:i($sizeOfKeyElemPersistValuesBlob)"!], \[!ELSE!][!WS!] \[!ENDIF!][!CR!]
                        [!ENDCODE!][!//
                    [!ENDFOR!][!//
                    [!VAR "countEl" = "$index"!][!//
                    [!FOR "index" = "num:i($countEl+2)" TO "num:i(2 * (node:value(./CryptoKeyElementSize) + $sizeOfKeyElemPersistPaddingValuesBlob))" STEP "num:i(2)"!][!//
                        [!VAR "curIdx" = "$curIdx + 1"!][!//
                        [!CODE!][!//
                            0x00U[!IF "num:i($curIdx) < num:i($sizeOfKeyElemPersistValuesBlob)"!], \[!ELSE!][!WS!] \[!ENDIF!][!CR!][!//
                        [!ENDCODE!][!//
                    [!ENDFOR!][!//
                    [!ENDINDENT!][!//
                [!ELSEIF "node:value(./UseCsecKey)='true' and node:value(./CsecKeySlot) != 'CSEC_IP_RAM_KEY'"!][!//
                    [!INDENT "58"!]
                    /* If the key element uses a CSEc key and it is a Nvm key, add the 4 bytes storing the 32bit value of the actual size */
                    [!"keyElemActualSize = num:i(string-length(node:value(./CryptoKeyElementInitValue)))"!][!//
                    [!CODE!][!//
                        /* Offset [!"num:i($curIdx)"!] - Length of [!"node:name(.)"!] */ \
                        [!VAR "curIdx" = "$curIdx + 1"!]0x00U, \
                        [!VAR "curIdx" = "$curIdx + 1"!]0x00U, \
                        [!VAR "curIdx" = "$curIdx + 1"!]0x00U, \
                        [!VAR "curIdx" = "$curIdx + 1"!]0x00U[!IF "num:i($curIdx) < num:i($sizeOfKeyElemPersistValuesBlob)"!], \[!ELSE!] \[!ENDIF!][!CR!]
                    [!ENDCODE!][!//
                    [!ENDINDENT!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
            [!INDENT "56"!]
            [!CODE!][!//
                }

            [!ENDCODE!][!//
            [!ENDINDENT!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
    /* Compile time switch stating that support for Nvram read/write operations is enabled or disabled */
    #define CRYPTO_ENABLE_NVRAM_READ_WRITE_SUPPORT          ([!IF "node:exists(CryptoGeneral/CryptoUpdateNvramBlobHandler)"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!][!//
    /* Compile time switch stating that there is no configured key */
    #define CRYPTO_KEYS_EXIST                               (STD_OFF)
[!ENDIF!][!//

/* Pre-processor switch to enable/disable support in Crypto driver for job redirection feature */
[!IF "node:exists(CryptoKeys)"!][!//
    #define CRYPTO_ENABLE_REDIRECTION_SUPPORT               ([!IF "CryptoGeneral/CryptoEnableRedirection"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!][!//
    #define CRYPTO_ENABLE_REDIRECTION_SUPPORT               (STD_OFF)
[!ENDIF!][!//

/* Support for TLS1.2 key derivation in Crypto_KeyDerive() API */
#define CRYPTO_ENABLE_TLS12_DERIVE_SUPPORT              (STD_OFF)

/* Support for User mode.
*       STD_ON:  the Crypto driver can be executed from both supervisor and user mode
*       STD_OFF: the Crypto driver can be executed only from supervisor mode */
#define CRYPTO_ENABLE_USER_MODE_SUPPORT                 ([!IF "CryptoGeneral/CryptoEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!INDENT "0"!]#ifndef MCAL_ENABLE_USER_MODE_SUPPORT[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#ifdef CRYPTO_ENABLE_USER_MODE_SUPPORT[!CR!][!ENDINDENT!][!//
[!INDENT "8"!]#if (STD_ON == CRYPTO_ENABLE_USER_MODE_SUPPORT)[!CR!][!ENDINDENT!][!//
[!INDENT "12"!]#error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Crypto driver in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.[!CR!][!ENDINDENT!][!//
[!INDENT "8"!]#endif /* (STD_ON == CRYPTO_ENABLE_USER_MODE_SUPPORT) */[!CR!][!ENDINDENT!][!//
[!INDENT "4"!]#endif /* ifndef CRYPTO_ENABLE_USER_MODE_SUPPORT */[!CR!][!ENDINDENT!][!//
[!INDENT "0"!]#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT*/[!CR!][!ENDINDENT!][!//

/* Support for SHE */
#define CRYPTO_SPT_SHE                                  (STD_ON)
[!INDENT "4"!]#define CRYPTO_SPT_SHE_KEY_IMPORT                   (STD_ON)[!CR!][!ENDINDENT!][!//

/* Support for key derivation */
#define CRYPTO_SPT_KEY_DERIVE                           (STD_OFF)
#define CRYPTO_SPT_PBKDF2                               (STD_OFF)

[!NOCODE!][!//
    /* The Tresos generator code below creates the symbolic name defines for CryptoDriverObjectId, CryptoKeyId and CryptoKeyElementId attributes from their
    corresponding lists, making sure that all the values are written on the same column of the generated Crypto_Cfg.h file */
    [!VAR "MaxLength" = "0"!][!//
    [!LOOP "CryptoDriverObjects/CryptoDriverObject/*"!][!//
        [!IF "string-length(concat('CryptoConf_CryptoDriverObject_', node:name(.))) > $MaxLength"!][!//
            [!VAR "MaxLength" = "string-length(concat('CryptoConf_CryptoDriverObject_', node:name(.)))"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "node:exists(CryptoKeys)"!][!//
        [!LOOP "CryptoKeys/CryptoKey/*"!][!//
            [!IF "string-length(concat('CryptoConf_CryptoKey_', node:name(.))) > $MaxLength"!][!//
                [!VAR "MaxLength" = "string-length(concat('CryptoConf_CryptoKey_', node:name(.)))"!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDIF!][!//
    [!IF "node:exists(CryptoKeyElements)"!][!//
        [!LOOP "CryptoKeyElements/CryptoKeyElement/*"!][!//
            [!IF "string-length(concat('CryptoConf_CryptoKeyElement_', node:name(.))) > $MaxLength"!][!//
                [!VAR "MaxLength" = "string-length(concat('CryptoConf_CryptoKeyElement_', node:name(.)))"!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDIF!][!//

    [!CODE!]/* Symbolic names for the CryptoDriverObjectId attribute of all the Crypto Driver Objects */[!ENDCODE!][!CR!][!//
    [!LOOP "CryptoDriverObjects/CryptoDriverObject/*"!][!//
        [!CODE!]#define CryptoConf_CryptoDriverObject_[!"node:name(.)"!][!ENDCODE!][!//
        [!FOR "LoopCounter" = "1" TO "$MaxLength + 2 - string-length(concat('CryptoConf_CryptoDriverObject_', node:name(.)))"!][!//
            [!CODE!] [!ENDCODE!][!//
        [!ENDFOR!][!//
        [!CODE!]((uint32)[!"CryptoDriverObjectId"!]U)[!ENDCODE!][!CR!][!//
    [!ENDLOOP!][!//

    [!IF "node:exists(CryptoKeys)"!][!//
        [!CR!][!CODE!]/* Symbolic names for the CryptoKeyId attribute of all the Crypto keys */[!ENDCODE!][!CR!][!//
        [!LOOP "CryptoKeys/CryptoKey/*"!][!//
            [!CODE!]#define CryptoConf_CryptoKey_[!"node:name(.)"!][!ENDCODE!][!//
            [!FOR "LoopCounter" = "1" TO "$MaxLength + 2 - string-length(concat('CryptoConf_CryptoKey_', node:name(.)))"!][!//
                [!CODE!] [!ENDCODE!][!//
            [!ENDFOR!][!//
            [!CODE!]((uint32)[!"CryptoKeyId"!]U)[!ENDCODE!][!CR!][!//
        [!ENDLOOP!][!//
    [!ENDIF!][!//

    [!IF "node:exists(CryptoKeyElements)"!][!//
        [!CR!][!CODE!]/* Symbolic names for the CryptoKeyElementId attribute of all the Crypto key elements */[!ENDCODE!][!CR!][!//
        [!LOOP "CryptoKeyElements/CryptoKeyElement/*"!][!//
            [!CODE!]#define CryptoConf_CryptoKeyElement_[!"node:name(.)"!][!ENDCODE!][!//
            [!FOR "LoopCounter" = "1" TO "$MaxLength + 2 - string-length(concat('CryptoConf_CryptoKeyElement_', node:name(.)))"!][!//
                [!CODE!] [!ENDCODE!][!//
            [!ENDFOR!][!//
            [!CODE!]((uint32)[!"CryptoKeyElementId"!]U)[!ENDCODE!][!CR!][!//
        [!ENDLOOP!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDINDENT!][!//

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* Structure storing information about a Crypto Key Element */
typedef struct
{
    /* Members storing Autosar required information */
    const   uint32                           u32CryptoKeyElementId;
    const   boolean                          bCryptoKeyElementAllowPartialAccess;
    const   Crypto_KeyFormatType             eCryptoKeyFormat;
    const   boolean                          bCryptoKeyElementPersist;
    const   Crypto_KeyElementReadAccessType  eCryptoKeyElementReadAccess;
    const   uint32                           u32CryptoKeyElementMaxSize;
    const   Crypto_KeyElementWriteAccessType eCryptoKeyElementWriteAccess;
    uint32* const                            pu32CryptoElementActualSize;
    uint8*  const                            pCryptoElementArray;
    const   Csec_Ip_KeyIdType                eKeyId;
} Crypto_KeyElementType;

[!IF "node:exists(CryptoGeneral/CryptoUpdateNvramBlobHandler)"!][!//
/* Pointer type to the upper layer handler that will update in Nvram blobs of persistent information */
typedef Std_ReturnType (*Crypto_UpdateNvramBlobHandlerType)(uint32 u32BlobId, uint32 u32BlobLength);

[!ENDIF!][!//

/* Structure storing information about a Crypto Driver Object */
typedef struct
{
[!IF "num:i(count(CryptoGeneral/CryptoEcucPartitionRef/*)) > 0"!][!//
    const uint32                      u32ValidPartitionId;
[!ENDIF!][!//
    Crypto_QueueElementType* const    pQueuedJobs;
    const uint32                      u32CryptoQueueSize;
    const Crypto_PrimitiveType* const pCryptoKeyPrimitives;
    const uint32                      u32NoCryptoPrimitives;
} Crypto_ObjectType;

/*==================================================================================================
*                                  GLOBAL CONSTANTS DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
[!IF "node:exists(CryptoKeyElements)"!][!//
#define CRYPTO_START_SEC_VAR_CLEARED_8
#include "Crypto_MemMap.h"

/* Array storing blob 0 containing information that should be persistent between resets */
extern uint8 Crypto_au8NvramBlob0[CRYPTO_SIZEOF_NVRAM_BLOB_0];

#define CRYPTO_STOP_SEC_VAR_CLEARED_8
#include "Crypto_MemMap.h"


    [!NOCODE!][!//
    /* Create the uint8 array with the information that needs to be stored in Nvram for all persistent Key Elements (buffers + actual sizes) */
    /* Count first the max size of the blob storing information about the persistent key elements. Need to be known when to append commas after each value */
    [!VAR "sizeOfKeyElemPersistValuesBlob"="0"!][!//
    [!VAR "bKeyElemPersistBlobHasAllBytesZero"="'true'"!][!//
    [!LOOP "CryptoKeyElements/CryptoKeyElement/*"!][!//
        [!IF "node:value(./UseCsecKey)='false' and node:value(./CryptoKeyElementPersist) = 'true' "!][!//
            /* If the key element does not use a CSEc key, add the max size of the key element buffer + 4 bytes storing the 32bit value of the actual size */
            [!VAR "sizeOfKeyElemPersistValuesBlob" = "$sizeOfKeyElemPersistValuesBlob + node:value(./CryptoKeyElementSize) + num:i(4)"!][!//
            [!IF "num:i(string-length(node:value(./CryptoKeyElementInitValue)))!=0"!][!//
                [!VAR "bKeyElemPersistBlobHasAllBytesZero"="'false'"!][!//
            [!ENDIF!][!//
        [!ELSEIF "node:value(./UseCsecKey)='true' and node:value(./CsecKeySlot) != 'CSEC_IP_RAM_KEY' "!][!//
            /* If the key element uses a CSEc key and it is a Nvm key, add the 4 bytes storing the 32bit value of the actual size */
            [!VAR "sizeOfKeyElemPersistValuesBlob" = "$sizeOfKeyElemPersistValuesBlob + num:i(4)"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$sizeOfKeyElemPersistValuesBlob > 0"!][!//
        [!IF "$bKeyElemPersistBlobHasAllBytesZero = 'true'"!][!//
            [!INDENT "0"!]
            [!CODE!][!//
                #define CRYPTO_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
                #include "Crypto_MemMap.h"

                /* Array storing blob 1 containing information that should be persistent between resets */
                extern uint8 Crypto_au8NvramBlob1[CRYPTO_SIZEOF_NVRAM_BLOB_1];

                #define CRYPTO_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
                #include "Crypto_MemMap.h"

            [!ENDCODE!][!//
            [!ENDINDENT!][!//
        [!ELSE!][!//
            [!INDENT "0"!]
            [!CODE!][!//
                #define CRYPTO_START_SEC_VAR_INIT_8_NO_CACHEABLE
                #include "Crypto_MemMap.h"

                /* Array storing blob 1 containing information that should be persistent between resets */
                extern uint8 Crypto_au8NvramBlob1[CRYPTO_SIZEOF_NVRAM_BLOB_1];

                #define CRYPTO_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
                #include "Crypto_MemMap.h"

            [!ENDCODE!][!//
            [!ENDINDENT!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
    [!ENDNOCODE!][!//
[!ENDIF!][!//
/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
[!IF "node:exists(CryptoGeneral/CryptoUpdateNvramBlobHandler)"!][!//
/**
* @brief            Handler to be implemented in the upper layer, for updating the information of the blob pointed by Crypto into Nvram.
*
* @param[in]        u32BlobId        Holds the identifier of the blob the Crypto driver is requesting the upper layer to save to NVRAM
*                                    Can have one of the 2 possible following values:
*                                       - CRYPTO_NVRAM_BLOB_0_ID,
*                                         When the u32BlobId handler parameter has the value above, the length of the blob will always be equal to the value of the define CRYPTO_SIZEOF_NVRAM_BLOB_0
*                                       - CRYPTO_NVRAM_BLOB_1_ID
*                                         When the u32BlobId handler parameter has the value above, the length of the blob will always be equal to the value of the define CRYPTO_SIZEOF_NVRAM_BLOB_1
* @param[in]        u32BlobLength    Holds the length of the blob the Crypto driver is requesting the upper layer to update to NVRAM
*
* @return           Result of the operation. Upper layer should respond with one of the following return values:
* @retval           E_OK                        Request was successful, upper layer updated successfully the blob into NVRAM
* @retval           E_NOT_OK                    Request failed, blob data was not successfully updated into NVRAM
*
*/
extern Std_ReturnType [!"CryptoGeneral/CryptoUpdateNvramBlobHandler"!]
(
    uint32 u32BlobId,
    uint32 u32BlobLength
);
[!ENDIF!][!//


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CRYPTO_CFG_H */
