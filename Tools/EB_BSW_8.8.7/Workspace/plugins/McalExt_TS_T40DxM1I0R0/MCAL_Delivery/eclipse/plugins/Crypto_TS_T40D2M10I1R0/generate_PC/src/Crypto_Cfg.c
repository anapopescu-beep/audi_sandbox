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
#include "Crypto_Cfg.h"
#include "Crypto_Private.h"
#include "Crypto.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_VENDOR_ID_CFG_C                      43
#define CRYPTO_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define CRYPTO_AR_RELEASE_MINOR_VERSION_CFG_C       4
#define CRYPTO_AR_RELEASE_REVISION_VERSION_CFG_C    0
#define CRYPTO_SW_MAJOR_VERSION_CFG_C               1
#define CRYPTO_SW_MINOR_VERSION_CFG_C               0
#define CRYPTO_SW_PATCH_VERSION_CFG_C               1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!][!//
[!INCLUDE "Crypto_VersionCheck_Src.m"!][!//
[!ENDNOCODE!][!//
/* Check if Crypto configuration source file and Crypto configuration header file are of the same vendor */
#if (CRYPTO_VENDOR_ID_CFG_C != CRYPTO_VENDOR_ID_CFG)
    #error "Crypto_Cfg.c and Crypto_Cfg.h have different vendor ids"
#endif

/* Check if Crypto configuration source file and Crypto configuration header file are of the same Autosar version */
#if ((CRYPTO_AR_RELEASE_MAJOR_VERSION_CFG_C    != CRYPTO_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (CRYPTO_AR_RELEASE_MINOR_VERSION_CFG_C    != CRYPTO_AR_RELEASE_MINOR_VERSION_CFG) || \
     (CRYPTO_AR_RELEASE_REVISION_VERSION_CFG_C != CRYPTO_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Crypto_Cfg.c and Crypto_Cfg.h are different"
#endif

/* Check if Crypto configuration source file and Crypto configuration header file are of the same Software version */
#if ((CRYPTO_SW_MAJOR_VERSION_CFG_C != CRYPTO_SW_MAJOR_VERSION_CFG) || \
     (CRYPTO_SW_MINOR_VERSION_CFG_C != CRYPTO_SW_MINOR_VERSION_CFG) || \
     (CRYPTO_SW_PATCH_VERSION_CFG_C != CRYPTO_SW_PATCH_VERSION_CFG)    \
    )
    #error "Software Version Numbers of Crypto_Cfg.c and Crypto_Cfg.h are different"
#endif

/* Check if Crypto configuration source file and Crypto private header file are of the same vendor */
#if (CRYPTO_VENDOR_ID_CFG_C != CRYPTO_VENDOR_ID_PRIVATE)
    #error "Crypto_Cfg.c and Crypto_Private.h have different vendor ids"
#endif

/* Check if Crypto configuration source file and Crypto private header file are of the same Autosar version */
#if ((CRYPTO_AR_RELEASE_MAJOR_VERSION_CFG_C    != CRYPTO_AR_RELEASE_MAJOR_VERSION_PRIVATE) || \
     (CRYPTO_AR_RELEASE_MINOR_VERSION_CFG_C    != CRYPTO_AR_RELEASE_MINOR_VERSION_PRIVATE) || \
     (CRYPTO_AR_RELEASE_REVISION_VERSION_CFG_C != CRYPTO_AR_RELEASE_REVISION_VERSION_PRIVATE) \
    )
    #error "AutoSar Version Numbers of Crypto_Cfg.c and Crypto_Private.h are different"
#endif

/* Check if Crypto configuration source file and Crypto private header file are of the same Software version */
#if ((CRYPTO_SW_MAJOR_VERSION_CFG_C != CRYPTO_SW_MAJOR_VERSION_PRIVATE) || \
     (CRYPTO_SW_MINOR_VERSION_CFG_C != CRYPTO_SW_MINOR_VERSION_PRIVATE) || \
     (CRYPTO_SW_PATCH_VERSION_CFG_C != CRYPTO_SW_PATCH_VERSION_PRIVATE)    \
    )
    #error "Software Version Numbers of Crypto_Cfg.c and Crypto_Private.h are different"
#endif

/* Check if Crypto configuration source file and Crypto header file are of the same vendor */
#if (CRYPTO_VENDOR_ID_CFG_C != CRYPTO_VENDOR_ID)
    #error "Crypto_Cfg.c and Crypto.h have different vendor ids"
#endif

/* Check if Crypto configuration source file and Crypto header file are of the same Autosar version */
#if ((CRYPTO_AR_RELEASE_MAJOR_VERSION_CFG_C    != CRYPTO_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_AR_RELEASE_MINOR_VERSION_CFG_C    != CRYPTO_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_AR_RELEASE_REVISION_VERSION_CFG_C != CRYPTO_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crypto_Cfg.c and Crypto.h are different"
#endif

/* Check if Crypto configuration source file and Crypto header file are of the same Software version */
#if ((CRYPTO_SW_MAJOR_VERSION_CFG_C != CRYPTO_SW_MAJOR_VERSION) || \
     (CRYPTO_SW_MINOR_VERSION_CFG_C != CRYPTO_SW_MINOR_VERSION) || \
     (CRYPTO_SW_PATCH_VERSION_CFG_C != CRYPTO_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crypto_Cfg.c and Crypto.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
[!AUTOSPACING!][!//

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

[!IF "node:exists(CryptoKeyElements)"!][!//
#define CRYPTO_START_SEC_CONST_32
#include "Crypto_MemMap.h"

[!IF "node:exists(CryptoKeys)"!][!//
    [!LOOP "node:order(CryptoKeys/CryptoKey/*,'node:value(./CryptoKeyId)')"!][!//
        [!CODE!][!//
        [!INDENT "0"!]
        /* Array of indexes for each Crypto Key Element referred by Crypto Key [!"node:name(.)"!] */
        static const uint32 Crypto_au32KeyElementList_[!"node:name(.)"!][[!"num:i(count(node:ref(node:value(./CryptoKeyTypeRef))/CryptoKeyElementRef/*))"!]U] =
        {
        [!ENDINDENT!]
        [!ENDCODE!][!//
        [!VAR "CryptoLoopIt" = "num:i(count(node:ref(node:value(./CryptoKeyTypeRef))/CryptoKeyElementRef/*))"!][!//
        [!LOOP "node:ref(node:value(./CryptoKeyTypeRef))/CryptoKeyElementRef/*"!]
            [!VAR "CryptoLoopIt" = "$CryptoLoopIt - 1"!][!//
            [!IF "$CryptoLoopIt != 0"!][!//
                [!CODE!][!//
                [!INDENT "4"!]
                [!"node:ref(.)/@index"!]U,
                [!ENDINDENT!][!//
                [!ENDCODE!][!//
            [!ELSE!][!//
                [!CODE!][!//
                [!INDENT "4"!]
                [!"node:ref(.)/@index"!]U
                [!ENDINDENT!][!//
                [!ENDCODE!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!CODE!][!//
        [!INDENT "0"!]
        };
        [!ENDINDENT!]
        [!CR!]
        [!ENDCODE!][!//
    [!ENDLOOP!][!//
[!ENDIF!][!//
#define CRYPTO_STOP_SEC_CONST_32
#include "Crypto_MemMap.h"
[!ENDIF!][!//

#define CRYPTO_START_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

[!LOOP "node:order(CryptoDriverObjects/CryptoDriverObject/*,'node:value(./CryptoDriverObjectId)')"!][!//
    [!INDENT "0"!]
    /* Array storing the Crypto primitives in the Crypto Driver Object [!"node:name(.)"!] */
    static const Crypto_PrimitiveType Crypto_aPrimitives_[!"node:name(.)"!][[!"num:i(count(CryptoPrimitiveRef/*))"!]U] =
    {
    [!ENDINDENT!][!//
    [!VAR "CryptoLoopIt" = "num:i(count(CryptoPrimitiveRef/*))"!][!//
    [!LOOP "node:order(CryptoPrimitiveRef/*)"!][!//
        [!INDENT "4"!]
        {
        [!ENDINDENT!][!//
        [!INDENT "8"!]
        [!"node:value(as:ref(node:value(.))/CryptoPrimitiveService)"!],
        (uint8)[!"node:value(as:ref(node:value(.))/CryptoPrimitiveAlgorithmFamily)"!],
        (uint8)[!"node:value(as:ref(node:value(.))/CryptoPrimitiveAlgorithmMode)"!],
        (uint8)[!"node:value(as:ref(node:value(.))/CryptoPrimitiveAlgorithmSecondaryFamily)"!]
        [!ENDINDENT!]
        [!INDENT "4"!]
        [!IF "$CryptoLoopIt != 1"!][!//
            },
        [!ELSE!][!//
            }
        [!ENDIF!][!//
        [!ENDINDENT!][!//
        [!VAR "CryptoLoopIt" = "$CryptoLoopIt - 1"!][!//
    [!ENDLOOP!][!//
    [!INDENT "0"!]
    };

    [!ENDINDENT!][!//
[!ENDLOOP!]
#define CRYPTO_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
[!NOCODE!][!//
[!IF "node:exists(CryptoKeyElements)"!][!//
    /* Create the uint8 array with the information that needs to be stored for all non-persistent Key Elements (buffers + actual sizes) */
    /* Count first the max size of the information about the non-persistent (volatile) key elements. Need to be known when to append commas after each value */
    [!VAR "sizeOfKeyElemVolatileValues"="0"!][!//
    [!VAR "bKeyElemVolatileValuesHaveAllBytesZero"="'true'"!][!//
    [!LOOP "CryptoKeyElements/CryptoKeyElement/*"!][!//
        [!IF "node:value(./UseCsecKey)='false' and node:value(./CryptoKeyElementPersist) = 'false' "!][!//
            /* The padding of value for CryptoKeyElementSize */
            [!VAR "sizeOfKeyElemVolatilePaddingValues" = "0"!][!//
            [!IF "contains($DerivativeName, 'S32K11')"!][!//
                [!VAR "sizeOfKeyElemVolatilePaddingValues" = "node:value(./CryptoKeyElementSize) mod 4"!][!//
                [!IF "$sizeOfKeyElemVolatilePaddingValues != 0"!][!//
                    [!VAR "sizeOfKeyElemVolatilePaddingValues" = "(4 - $sizeOfKeyElemVolatilePaddingValues)"!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
            /* If the key element does not use a CSEc key, add the max size of the key element buffer + 4 bytes storing the 32bit value of the actual size */
            [!VAR "sizeOfKeyElemVolatileValues" = "$sizeOfKeyElemVolatileValues + node:value(./CryptoKeyElementSize) + num:i(4) + $sizeOfKeyElemVolatilePaddingValues"!][!//
            [!IF "num:i(string-length(node:value(./CryptoKeyElementInitValue)))!=0"!][!//
                [!VAR "bKeyElemVolatileValuesHaveAllBytesZero"="'false'"!][!//
            [!ENDIF!][!//
        [!ELSEIF "node:value(./UseCsecKey)='true' and node:value(./CsecKeySlot)='CSEC_IP_RAM_KEY'"!][!//
            /* If the key element uses a CSEc key and it is a Ram key, add the 4 bytes storing the 32bit value of the actual size */
            [!VAR "sizeOfKeyElemVolatileValues" = "$sizeOfKeyElemVolatileValues + num:i(4)"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$sizeOfKeyElemVolatileValues > 0"!][!//
        [!IF "$bKeyElemVolatileValuesHaveAllBytesZero = 'true'"!][!//
            [!INDENT "0"!]
            [!CODE!][!//
                #define CRYPTO_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
                #include "Crypto_MemMap.h"

                /* Array storing the key element information that is volatile (no need to be persistent across resets) */
                VAR_ALIGN(static uint8 Crypto_au8VolatileKeyElemValues[[!"num:i($sizeOfKeyElemVolatileValues)"!]U], 4U)

                #define CRYPTO_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
                #include "Crypto_MemMap.h"

            [!ENDCODE!][!//
            [!ENDINDENT!][!//
        [!ELSE!][!// IF "$bKeyElemVolatileValuesHaveAllBytesZero = 'true'"
            [!INDENT "0"!]
            [!CODE!][!//
                #define CRYPTO_START_SEC_VAR_INIT_8_NO_CACHEABLE
                #include "Crypto_MemMap.h"

                /* The declaration and set alignment attribute for Crypto_au8VolatileKeyElemValues */
                VAR_ALIGN(static uint8 Crypto_au8VolatileKeyElemValues[[!"num:i($sizeOfKeyElemVolatileValues)"!]U], 4U)

                /* Array storing the key element information that is volatile (no need to be persistent across resets) */
                static uint8 Crypto_au8VolatileKeyElemValues[[!"num:i($sizeOfKeyElemVolatileValues)"!]U] =
                {
            [!ENDCODE!][!//
            [!ENDINDENT!][!//
            [!VAR "curIdx"="0"!][!//
            [!LOOP "CryptoKeyElements/CryptoKeyElement/*"!][!//
                [!IF "node:value(./UseCsecKey)='false' and node:value(./CryptoKeyElementPersist) = 'false' "!][!//
                    /* If the key element does not use a CSEc key, add the 4 bytes storing the 32bit value of the actual size + the max size buffer of the key element */
                    /* The padding of value for CryptoKeyElementSize */
                    !VAR "sizeOfKeyElemVolatilePaddingValues" = "0"!][!//
                    [!IF "contains($DerivativeName, 'S32K11')"!][!//
                        [!VAR "sizeOfKeyElemVolatilePaddingValues" = "node:value(./CryptoKeyElementSize) mod 4"!][!//
                        [!IF "$sizeOfKeyElemVolatilePaddingValues != 0"!][!//
                            [!VAR "sizeOfKeyElemVolatilePaddingValues" = "(4 - $sizeOfKeyElemVolatilePaddingValues)"!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                    [!INDENT "4"!]
                    [!CODE!][!//
                        /* Offset [!"num:i($curIdx)"!] - The following 4 bytes store the actual length of the key element [!"node:name(.)"!] */
                        [!"num:inttohex(bit:and((bit:shr(num:i(string-length(node:value(./CryptoKeyElementInitValue)) div 2),0)),255),2)"!]U,
                        [!"num:inttohex(bit:and((bit:shr(num:i(string-length(node:value(./CryptoKeyElementInitValue)) div 2),8)),255),2)"!]U,
                        [!"num:inttohex(bit:and((bit:shr(num:i(string-length(node:value(./CryptoKeyElementInitValue)) div 2),16)),255),2)"!]U,
                        [!"num:inttohex(bit:and((bit:shr(num:i(string-length(node:value(./CryptoKeyElementInitValue)) div 2),24)),255),2)"!]U,
                    [!ENDCODE!][!//
                    [!VAR "curIdx" = "$curIdx + 4"!][!//
                    [!CODE!][!//
                        /* Offset [!"num:i($curIdx)"!] - The following [!"num:i(node:value(./CryptoKeyElementSize))"!] bytes store the buffer of the key element [!"node:name(.)"!] */
                    [!ENDCODE!][!//
                    [!VAR "index" = "num:i(-1)"!][!//
                    [!FOR "index" = "num:i(1)" TO "num:i(string-length(node:value(./CryptoKeyElementInitValue)))" STEP "num:i(2)"!][!//
                        [!VAR "curIdx" = "$curIdx + 1"!][!//
                        [!CODE!][!//
                            0x[!"substring(node:value(./CryptoKeyElementInitValue), $index, 2)"!]U[!IF "num:i($curIdx) < num:i($sizeOfKeyElemVolatileValues)"!],[!ENDIF!][!CR!]
                        [!ENDCODE!][!//
                    [!ENDFOR!][!//
                    [!VAR "countEl" = "$index"!][!//
                    [!FOR "index" = "num:i($countEl+2)" TO "num:i(2 * (node:value(./CryptoKeyElementSize) + $sizeOfKeyElemVolatilePaddingValues))" STEP "num:i(2)"!][!//
                        [!VAR "curIdx" = "$curIdx + 1"!][!//
                        [!CODE!][!//
                            0x00U[!IF "num:i($curIdx) < num:i($sizeOfKeyElemVolatileValues)"!],[!ENDIF!][!CR!]
                        [!ENDCODE!][!//
                    [!ENDFOR!][!//
                    [!ENDINDENT!][!//
                [!ELSEIF "node:value(./UseCsecKey)='true' and node:value(./CsecKeySlot)='CSEC_IP_RAM_KEY'"!][!//
                    /* If the key element uses a CSEc key and it is a Ram key, add the 4 bytes storing the 32bit value of the actual size */
                    [!"keyElemActualSize = num:i(string-length(node:value(./CryptoKeyElementInitValue)))"!][!//
                    [!INDENT "4"!]
                    [!CODE!][!//
                        /* Offset [!"num:i($curIdx)"!] - The following 4 bytes store the actual length of the key element [!"node:name(.)"!] */
                        [!VAR "curIdx" = "$curIdx + 1"!]0x00U,
                        [!VAR "curIdx" = "$curIdx + 1"!]0x00U,
                        [!VAR "curIdx" = "$curIdx + 1"!]0x00U,
                        [!VAR "curIdx" = "$curIdx + 1"!]0x00U[!IF "num:i($curIdx) < num:i($sizeOfKeyElemVolatileValues)"!],[!ENDIF!][!CR!]
                    [!ENDCODE!][!//
                    [!ENDINDENT!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
            [!INDENT "0"!]
            [!CODE!][!//
                };

                #define CRYPTO_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
                #include "Crypto_MemMap.h"

            [!ENDCODE!][!//
            [!ENDINDENT!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!NOCODE!][!//
[!// Loop first through all Crypto Driver Objects checking if at least one has the jobs queue enabled
[!VAR "bMemMapSectionVarNoInitUnspecifiedNeeded"="'false'"!][!//
[!LOOP "node:order(CryptoDriverObjects/CryptoDriverObject/*,'node:value(./CryptoDriverObjectId)')"!][!//
    [!IF "node:value(./CryptoQueueSize) != 0"!][!//
        [!VAR "bMemMapSectionVarNoInitUnspecifiedNeeded"="'true'"!][!//
    [!ENDIF!][!//
[!ENDLOOP!]
[!IF "$bMemMapSectionVarNoInitUnspecifiedNeeded = 'true'"!][!//
    [!INDENT "0"!][!//
    [!CODE!][!//
    #define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Crypto_MemMap.h"

    [!LOOP "node:order(CryptoDriverObjects/CryptoDriverObject/*,'node:value(./CryptoDriverObjectId)')"!][!//
        [!IF "node:value(./CryptoQueueSize) != 0"!][!//
            /* Array storing the queued jobs for the Crypto Driver Object [!"node:name(.)"!] */
            static Crypto_QueueElementType Crypto_aQueuedJobs_[!"node:name(.)"!][[!"node:value(./CryptoQueueSize)"!]U];
        [!ENDIF!][!//
    [!ENDLOOP!]

    #define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #include "Crypto_MemMap.h"
    [!ENDCODE!][!//
    [!ENDINDENT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define CRYPTO_START_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

[!INDENT "0"!]
    /* Array of structures storing the information about the Crypto Driver Objects */
    const Crypto_ObjectType Crypto_aDriverObjectList[CRYPTO_NUMBER_OF_DRIVER_OBJECTS_U32] =
    {
[!ENDINDENT!][!//
[!VAR "CryptoLoopIt" = "count(CryptoDriverObjects/CryptoDriverObject/*)"!][!//
[!LOOP "node:order(CryptoDriverObjects/CryptoDriverObject/*,'node:value(./CryptoDriverObjectId)')"!][!//
    [!VAR "curCdoName" = "node:name(.)"!][!//
    [!VAR "CryptoLoopIt" = "$CryptoLoopIt - 1"!][!//
    [!INDENT "4"!]
    /* Structure storing the information about Crypto Driver Object [!"node:name(.)"!] */
    {
    [!ENDINDENT!]
    [!INDENT "8"!]
        [!LOOP "CryptoDriverObjectEcucPartitionRef/*"!][!//
            [!VAR "bPartitionMatched" = "'false'"!][!//
            [!VAR "curCdoPartition" = "node:value(.)"!][!//
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
                [!IF "node:refvalid(./OsAppEcucPartitionRef)"!][!//
                    [!IF "$curCdoPartition = node:value(./OsAppEcucPartitionRef)"!][!//
                        [!IF "node:refvalid(./OsApplicationCoreRef)"!][!//
                            [!VAR "bPartitionMatched" = "'true'"!][!//
                            /* Id of the partition that is valid for the Crypto Driver Object */
                            [!"node:value(node:ref(./OsApplicationCoreRef)/EcucCoreId)"!]U,
                            [!BREAK!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
            [!IF "$bPartitionMatched = 'false'"!][!//
                [!ERROR!][!//
                    The referenced ECUC partition '[!"$curCdoPartition"!]' in the CryptoEcucPartitionRef list of the Crypto Driver Object '[!"$curCdoName"!]' is not associated with any OsApplication or the OsApplication does not have a valid OsApplicationCoreRef!
                [!ENDERROR!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        /* Reference to the jobs queue */
        [!IF "node:value(./CryptoQueueSize)!= 0"!][!//
            Crypto_aQueuedJobs_[!"node:name(.)"!],
        [!ELSE!][!//
            NULL_PTR,
        [!ENDIF!][!//
        /* Jobs queue size */
        [!"node:value(./CryptoQueueSize)"!]U,
        /* Reference to the Crypto primitives list */
        Crypto_aPrimitives_[!"node:name(.)"!],
        /* Number of crypto primitives */
        [!"num:i(count(CryptoPrimitiveRef/*))"!]U
        [!INDENT "4"!]
            [!IF "$CryptoLoopIt != 0"!][!//
                },
            [!ELSE!][!//
                }
            [!ENDIF!][!//
        [!ENDINDENT!][!//
    [!ENDINDENT!][!//
[!ENDLOOP!][!//
[!INDENT "0"!]
};
[!ENDINDENT!][!//

[!IF "node:exists(CryptoKeys)"!][!//
    [!INDENT "0"!]
        /* Array of structures storing the information about the Crypto Keys */
        const Crypto_KeyType Crypto_aKeyList[CRYPTO_NUMBER_OF_KEYS_U32] =
        {
    [!ENDINDENT!][!//
    [!VAR "CryptoLoopIt" = "count(CryptoKeys/CryptoKey/*)"!][!//
    [!LOOP "node:order(CryptoKeys/CryptoKey/*,'node:value(./CryptoKeyId)')"!][!//
        [!VAR "CryptoLoopIt" = "$CryptoLoopIt - 1"!][!//
        [!INDENT "4"!]
        {
        [!ENDINDENT!]
        [!INDENT "8"!]
            /* Number of key elements in the key [!"node:name(.)"!] */
            [!"num:i(count(node:ref(node:value(./CryptoKeyTypeRef))/CryptoKeyElementRef/*))"!]U,
            /* Reference to the list of key elements in the key [!"node:name(.)"!] */
            Crypto_au32KeyElementList_[!"node:name(.)"!]
        [!ENDINDENT!][!//
        [!INDENT "4"!]
        [!IF "$CryptoLoopIt != 0"!][!//
            },
        [!ELSE!][!//
            }
        [!ENDIF!][!//
        [!ENDINDENT!][!//
    [!ENDLOOP!][!//
[!INDENT "0"!]
};
[!ENDINDENT!][!//
[!ENDIF!][!//

[!IF "node:exists(CryptoKeyElements)"!][!//
    [!INDENT "0"!]
        /* Array of structures storing the information about the Crypto Key Elements */
        const Crypto_KeyElementType Crypto_aKeyElementList[CRYPTO_NUMBER_OF_KEY_ELEMENTS_U32] =
        {
    [!ENDINDENT!][!//
    [!VAR "CryptoLoopIt" = "count(CryptoKeyElements/CryptoKeyElement/*)"!][!//
    [!VAR "curIdxInPersistentArray"="0"!][!//
    [!VAR "curIdxInVolatileArray"="0"!][!//
    [!LOOP "node:CryptoKeyElements/CryptoKeyElement/*"!][!//
        [!VAR "CryptoLoopIt" = "$CryptoLoopIt - 1"!][!//
        [!INDENT "4"!]
        /* Structure containing information for Key Element [!"node:name(.)"!] */
        {
        [!ENDINDENT!]
        [!INDENT "8"!]
            /* KeyElementId */
            [!"node:value(./CryptoKeyElementId)"!]U,
            /* Allow partial access */
            [!IF "node:value(./CryptoKeyElementAllowPartialAccess)"!][!//
                (boolean)TRUE,
            [!ELSE!][!//
                (boolean)FALSE,
            [!ENDIF!][!//
            /* Key element format */
            [!"node:value(./CryptoKeyElementFormat)"!],
            /* Key element persistent */
            [!IF "node:value(./UseCsecKey)='true'"!][!//
                [!IF "node:value(./CsecKeySlot)!='CSEC_IP_RAM_KEY'"!][!//
                    (boolean)TRUE,
                [!ELSE!][!//
                    (boolean)FALSE,
                [!ENDIF!][!//
            [!ELSE!][!//
                [!IF "node:value(./CryptoKeyElementPersist)"!][!//
                    (boolean)TRUE,
                [!ELSE!][!//
                    (boolean)FALSE,
                [!ENDIF!][!//
            [!ENDIF!][!//
            /* Read access type */
            [!"node:value(./CryptoKeyElementReadAccess)"!],
            /* Key element max size */
            [!"node:value(./CryptoKeyElementSize)"!]U,
            /* Write access type */
            [!"node:value(./CryptoKeyElementWriteAccess)"!],
            [!IF "node:value(./UseCsecKey)='false'"!][!//
                /* The padding of value for CryptoKeyElementSize */
                [!VAR "sizeOfKeyElemPaddingValues" = "0"!][!//
                [!IF "contains($DerivativeName, 'S32K11')"!][!//
                    [!VAR "sizeOfKeyElemPaddingValues" = "node:value(./CryptoKeyElementSize) mod 4"!][!//
                    [!IF "$sizeOfKeyElemPaddingValues != 0"!][!//
                        [!VAR "sizeOfKeyElemPaddingValues" = "(4 - $sizeOfKeyElemPaddingValues)"!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
                [!IF "node:value(./CryptoKeyElementPersist) = 'true' "!][!//
                    /* Pointer to location storing the Key Element actual size */
                    (uint32*)&Crypto_au8NvramBlob1[[!"num:i($curIdxInPersistentArray)"!]U],
                    [!VAR "curIdxInPersistentArray" = "$curIdxInPersistentArray + 4"!][!//
                    /* Pointer to location storing the Key Element value */
                    &Crypto_au8NvramBlob1[[!"num:i($curIdxInPersistentArray)"!]U],
                    [!VAR "curIdxInPersistentArray" = "$curIdxInPersistentArray + node:value(./CryptoKeyElementSize) + $sizeOfKeyElemPaddingValues"!][!//
                [!ELSE!][!//
                    /* Pointer to location storing the Key Element actual size */
                    (uint32*)&Crypto_au8VolatileKeyElemValues[[!"num:i($curIdxInVolatileArray)"!]U],
                    [!VAR "curIdxInVolatileArray" = "$curIdxInVolatileArray + 4"!][!//
                    /* Pointer to location storing the Key Element value */
                    &Crypto_au8VolatileKeyElemValues[[!"num:i($curIdxInVolatileArray)"!]U],
                    [!VAR "curIdxInVolatileArray" = "$curIdxInVolatileArray + node:value(./CryptoKeyElementSize) + $sizeOfKeyElemPaddingValues"!][!//
                [!ENDIF!][!//
            [!ELSE!][!//
                [!IF "node:value(./CsecKeySlot) != 'CSEC_IP_RAM_KEY'"!][!//
                    /* Pointer to location storing the Key Element actual size */
                    (uint32*)&Crypto_au8NvramBlob1[[!"num:i($curIdxInPersistentArray)"!]U],
                    [!VAR "curIdxInPersistentArray" = "$curIdxInPersistentArray + 4"!][!//
                    /* Pointer to location storing the Key Element value */
                    NULL_PTR,
                [!ELSE!][!//
                    /* Pointer to location storing the Key Element actual size */
                    (uint32*)&Crypto_au8VolatileKeyElemValues[[!"num:i($curIdxInVolatileArray)"!]U],
                    [!VAR "curIdxInVolatileArray" = "$curIdxInVolatileArray + 4"!][!//
                    /* Pointer to location storing the Key Element value */
                    NULL_PTR,
                [!ENDIF!][!//
            [!ENDIF!][!//
            /* Identifier of the CSEc key */
            [!IF "node:value(./UseCsecKey) = 'true'"!][!//
                [!"node:value(./CsecKeySlot)"!]
            [!ELSE!][!//
                CSEC_IP_KEY_INVALID
            [!ENDIF!][!//
        [!ENDINDENT!][!//
        [!INDENT "4"!]
        [!IF "$CryptoLoopIt != 0"!][!//
            },
        [!ELSE!][!//
            }
        [!ENDIF!][!//
        [!ENDINDENT!][!//
    [!ENDLOOP!][!//
[!INDENT "0"!]
};
[!ENDINDENT!][!//

    [!IF "node:exists(CryptoGeneral/CryptoUpdateNvramBlobHandler)"!][!//
    [!INDENT "0"!][!//
        /* Pointer to the upper layer handler that will update in Nvram blobs of persistent information */
        const Crypto_UpdateNvramBlobHandlerType pfCryptoUpdateNvramBlobHandler = &[!"CryptoGeneral/CryptoUpdateNvramBlobHandler"!];

    [!ENDINDENT!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
#define CRYPTO_STOP_SEC_CONST_UNSPECIFIED
#include "Crypto_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
[!NOCODE!][!//
/* When key exists but user does not enable the NVM storage, Crypto driver will keep internally in RAM the 2 blobs */
[!IF "node:exists(CryptoKeyElements) and not(node:exists(CryptoGeneral/CryptoUpdateNvramBlobHandler))"!][!//
    [!INDENT "0"!][!//
    [!CODE!][!//
    #define CRYPTO_START_SEC_VAR_CLEARED_8
    #include "Crypto_MemMap.h"

    /* Array of 8 bit blocks storing a bit map of valid flags for each Crypto key */
    uint8 Crypto_au8NvramBlob0[CRYPTO_SIZEOF_NVRAM_BLOB_0];

    #define CRYPTO_STOP_SEC_VAR_CLEARED_8
    #include "Crypto_MemMap.h"


    [!ENDCODE!][!//
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
        [!ELSEIF "node:value(./UseCsecKey)='true' and node:value(./CsecKeySlot) != 'CSEC_IP_RAM_KEY'"!][!//
            /* If the key element uses a CSEc key and it is a Nvm key, add the 4 bytes storing the 32bit value of the actual size */
            [!VAR "sizeOfKeyElemPersistValuesBlob" = "$sizeOfKeyElemPersistValuesBlob + num:i(4)"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$sizeOfKeyElemPersistValuesBlob > 0"!][!//
        [!IF "$bKeyElemPersistBlobHasAllBytesZero = 'true'"!][!//
            [!CODE!][!//
                #define CRYPTO_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
                #include "Crypto_MemMap.h"

                /* Array storing blob 1 containing information that should be persistent between resets */
                VAR_ALIGN(uint8 Crypto_au8NvramBlob1[CRYPTO_SIZEOF_NVRAM_BLOB_1], 4U)

                #define CRYPTO_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
                #include "Crypto_MemMap.h"

            [!ENDCODE!][!//
        [!ELSE!][!// IF "$bKeyElemPersistBlobHasAllBytesZero = 'true'"
            [!CODE!][!//
                #define CRYPTO_START_SEC_VAR_INIT_8_NO_CACHEABLE
                #include "Crypto_MemMap.h"

                /* The declaration and set alignment attribute for Crypto_au8NvramBlob1
                   Array storing blob 1 containing information that should be persistent between resets */
                VAR_ALIGN(uint8 Crypto_au8NvramBlob1[CRYPTO_SIZEOF_NVRAM_BLOB_1] = CRYPTO_NVRAM_BLOB_1_INITIALIZER, 4U)

                #define CRYPTO_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
                #include "Crypto_MemMap.h"

            [!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
    [!ENDINDENT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

#define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"

Crypto_ObjectQueueType Crypto_aObjectQueueList[CRYPTO_NUMBER_OF_DRIVER_OBJECTS_U32];

#define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
