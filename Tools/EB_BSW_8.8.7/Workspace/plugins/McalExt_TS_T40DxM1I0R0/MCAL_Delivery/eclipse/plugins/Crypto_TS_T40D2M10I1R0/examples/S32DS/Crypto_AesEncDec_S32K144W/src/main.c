/*
*   (c) Copyright 2021 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Crypto.h"
#include "OsIf.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Function-like macros to set and get the status of the example run */
#define App_SetSuccessStatus(value)         (u32NumFailedApiCalls += ((value) ? 0U : 1U))
#define App_GetSuccessStatus()              (0U == u32NumFailedApiCalls)

/* Take the generated value of the Crypto Driver Object Id used for AES128 encryption/decryption from the configuration file */
#define APP_AES128_CDO_ID                   (CryptoConf_CryptoDriverObject_CDO_Symmetric)
/* Take the generated value of the AES128 Encrypt/Decrypt key id from the configuration file */
#define APP_AES128_KEY_ID                   (CryptoConf_CryptoKey_Crypto_Key_AES128_Encrypt_Decrypt)
/* Size in bytes of the AES128 Encrypt/Decrypt key */
#define APP_AES128_KEY_SIZE                 (16U)
/* Size in bytes of the 2 plain texts that will be used to test encryption */
#define APP_AES128_ECB_PLAIN_TEXT_SIZE_1    (16U)
#define APP_AES128_ECB_PLAIN_TEXT_SIZE_2    (64U)
/* Size in bytes of the 2 cipher texts that will be used to test decryption */
#define APP_AES128_ECB_CIPHER_TEXT_SIZE_1   (16U)
#define APP_AES128_ECB_CIPHER_TEXT_SIZE_2   (64U)
/* Size in bytes of the buffer where the Crypto driver will place the result of the encrypt/decrypt operations
   In this sample app, should be large enough to fit encryption/decryption of a 16 byte and respectively 64 bytes blocks of data */
#define APP_AES128_ECB_RESULT_SIZE          (64U)

/* Identifier of the KeyElement that contains the key material */
#define KEY_MATERIAL_ELEMENT_ID_U32         ((uint32)1U)

/* Defines related to the CSEc Hw Ip, depending on the derivative */
#ifdef S32K148
    /* FlexNVM Partition Code (512-64) Kbs Data Flash, 64 Kbs EEPROM backup */
    #define T_DEPART        (0x04U)
#else
    #if (defined S32K116|| defined S32K118)
        /* FlexNVM Partition Code - 8 Kbs Data Flash, 24 Kbs EEPROM backup */
        #define T_DEPART    (0x09U)
    #else
        /* FlexNVM Partition Code - 32 Kbs Data Flash, 32 Kbs EEPROM backup */
        #define T_DEPART    (0x03U)
    #endif
#endif

#if defined(S32K142W) || defined(S32K144W)
    #define KEY_SIZE        (0x07U)
#else
    #define KEY_SIZE        (0x03U)
#endif

#if (defined S32K116|| defined S32K118)
    #define FLASH_FLEXNVM_EEPROM    (0x03U)
#else
    #define FLASH_FLEXNVM_EEPROM    (0x02U)
#endif

#define SFE                         (0x00U)

#if (STD_ON == CSEC_IP_FTFM_MODULE)
    #define APP_CSEC_IP_FCNFG_RAMRDY_MASK         FTFM_FCNFG_RAMRDY_MASK
    #define APP_CSEC_IP_FCNFG_EEERDY_MASK         FTFM_FCNFG_EEERDY_MASK
    #define APP_CSEC_IP_MGSTAT0_MASK              FTFM_FSTAT_MGSTAT0_MASK
#else
    #define APP_CSEC_IP_FCNFG_RAMRDY_MASK         FTFC_FCNFG_RAMRDY_MASK
    #define APP_CSEC_IP_FCNFG_EEERDY_MASK         FTFC_FCNFG_EEERDY_MASK
    #define APP_CSEC_IP_MGSTAT0_MASK              FTFC_FSTAT_MGSTAT0_MASK
#endif

#define APP_CSEC_IP_RAMRDY_IS_SET       ((CSEC_IP_FLASH->FCNFG & APP_CSEC_IP_FCNFG_RAMRDY_MASK) != 0U)
#define APP_CSEC_IP_EEERDY_IS_SET       ((CSEC_IP_FLASH->FCNFG & APP_CSEC_IP_FCNFG_EEERDY_MASK) != 0U)

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
/* ---- Crypto job sub-structures for AES 128 ECB Encrypt ---------------------------------------------------------------------------------- */
static const Crypto_PrimitiveInfoType App_Aes128EcbEncryptPrimitiveInfo = 
{
    APP_AES128_ECB_RESULT_SIZE,         /* resultLength                - Contains the result length in bytes. */
    CRYPTO_ENCRYPT,                     /* service                     - Contains the enum of the used service, e.g. Encrypt */
    {
        CRYPTO_ALGOFAM_AES,             /* family                      - The family of the algorithm */
        CRYPTO_ALGOFAM_NOT_SET,         /* secondaryFamily             - The secondary family of the algorithm  */
        (APP_AES128_KEY_SIZE << 3U),    /* keyLength                   - The key length in bits to be used with that algorithm */
        CRYPTO_ALGOMODE_ECB             /* mode                        - The operation mode to be used with that algorithm */
    }
};

static const Crypto_JobInfoType App_JobAes128EcbEncryptInfo = 
{
    0U,                                 /* jobId                       - The identifier of the job */
    0U                                  /* jobPriority                 - Specifies the importance of the job (the higher, the more important) */
};

/* ---- Crypto job sub-structures for AES 128 ECB Decrypt ---------------------------------------------------------------------------------- */
static const Crypto_PrimitiveInfoType App_Aes128EcbDecryptPrimitiveInfo = 
{
    APP_AES128_ECB_RESULT_SIZE,         /* resultLength                - Contains the result length in bytes. */
    CRYPTO_DECRYPT,                     /* service                     - Contains the enum of the used service, e.g. Encrypt */
    {
        CRYPTO_ALGOFAM_AES,             /* family                      - The family of the algorithm */
        CRYPTO_ALGOFAM_NOT_SET,         /* secondaryFamily             - The secondary family of the algorithm  */
        (APP_AES128_KEY_SIZE << 3U),    /* keyLength                   - The key length in bits to be used with that algorithm */
        CRYPTO_ALGOMODE_ECB             /* mode                        - The operation mode to be used with that algorithm */
    }
};

static const Crypto_JobInfoType App_JobAes128EcbDecryptInfo = 
{
    0U,                                 /* jobId                       - The identifier of the job */
    0U                                  /* jobPriority                 - Specifies the importance of the job (the higher, the more important) */
};

/* ---- Constant information used in the function App_EraseCsecKeys() that restores the Csec to original state after running the example's code */
static const uint8 aMasterEcuKey[16] = 
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
};

static const uint8 aEmptyKey[16] = 
{
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

static const uint8 aEmptyUID[15] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const uint32 u32Counter = 2U;

static const uint8 u8Flags     = 0U;

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
/* --- The following RAM variables need to be put in non-cacheable memory in order to be correctly seen by CSEc -------------------------------------------------- */
#define CRYPTO_START_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Crypto_MemMap.h"

static uint8 App_au8Aes128EcbKey_1[APP_AES128_KEY_SIZE] __attribute__((aligned)) = 
{
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f
};

static uint8 App_au8Aes128EcbKey_2[APP_AES128_KEY_SIZE] __attribute__((aligned)) = 
{
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f
};

static uint8 App_au8Aes128EcbPlaintext_1[APP_AES128_ECB_PLAIN_TEXT_SIZE_1] = 
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
};

static uint8 App_au8Aes128EcbPlaintext_2[APP_AES128_ECB_PLAIN_TEXT_SIZE_2] = 
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f
};

static uint8 App_au8Aes128EcbCiphertext_1[APP_AES128_ECB_CIPHER_TEXT_SIZE_1] = 
{
    0x9c, 0x54, 0xd5, 0x71, 0x70, 0x2c, 0xfa, 0x0f, 0x03, 0xf3, 0x62, 0x15, 0x67, 0x6b, 0xab, 0x78
};

static uint8 App_au8Aes128EcbCiphertext_2[APP_AES128_ECB_CIPHER_TEXT_SIZE_2] = 
{
    0xdb, 0x7c, 0xe6, 0x7a, 0xf1, 0x3d, 0xe5, 0x7a, 0x95, 0xd9, 0x22, 0xe5, 0x32, 0x5a, 0xbf, 0x13,
    0x77, 0x10, 0x98, 0xa6, 0xb7, 0x8c, 0xb4, 0x5c, 0x02, 0x9c, 0xf1, 0xc0, 0xdd, 0xee, 0x0f, 0x1b,
    0xcc, 0x0d, 0xd1, 0x5b, 0x23, 0xe6, 0x82, 0x9e, 0x05, 0xf6, 0xe4, 0x17, 0xf4, 0x64, 0xb6, 0x99,
    0xa7, 0xad, 0xee, 0xae, 0xcc, 0xa5, 0x48, 0x89, 0xb8, 0x62, 0x1b, 0xec, 0x18, 0x52, 0x70, 0x44
};

#define CRYPTO_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Crypto_MemMap.h"

static uint8  App_au8Aes128EcbResult[APP_AES128_ECB_RESULT_SIZE];

#define CRYPTO_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Crypto_MemMap.h"


#define CRYPTO_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Crypto_MemMap.h"

static uint32 App_u32Aes128EcbResultSize;

#define CRYPTO_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Crypto_MemMap.h"


/* ---- Crypto job sub-structures for AES 128 ECB Encrypt ---------------------------------------------------------------------------------- */
static Crypto_JobPrimitiveInfoType App_JobAes128EcbEncryptPrimitiveInfo = 
{
    0U,                                  /* callbackId                 - Identifier of the callback function, to be called, if the configured service finished. */
    &App_Aes128EcbEncryptPrimitiveInfo,  /* primitiveInfo              - Pointer to a structure containing further configuration of the crypto primitives */    
    0U,                                  /* cryIfKeyId                 - Identifier of the CryIf key. */
    CRYPTO_PROCESSING_SYNC,              /* processingType             - Determines the synchronous or asynchronous behavior. */
    (boolean)FALSE                       /* callbackUpdateNotification - Indicates, whether the callback function shall be called, if the UPDATE operation has finished. */
};

/* ---- Crypto job sub-structures for AES 128 ECB Decrypt ---------------------------------------------------------------------------------- */
static Crypto_JobPrimitiveInfoType App_JobAes128EcbDecryptPrimitiveInfo = 
{
    0U,                                  /* callbackId                 - Identifier of the callback function, to be called, if the configured service finished. */
    &App_Aes128EcbDecryptPrimitiveInfo,  /* primitiveInfo              - Pointer to a structure containing further configuration of the crypto primitives */    
    0U,                                  /* cryIfKeyId                 - Identifier of the CryIf key. */
    CRYPTO_PROCESSING_SYNC,              /* processingType             - Determines the synchronous or asynchronous behavior. */
    (boolean)FALSE                       /* callbackUpdateNotification - Indicates, whether the callback function shall be called, if the UPDATE operation has finished. */
};

/* --- Structure of the job to be passed to Crypto driver, requesting Aes128 ECB Encrypt --------------------------------------------------------------------- */
static Crypto_JobType App_JobAes128EcbEncrypt = 
{
    1U,                                     /* jobId                      - Identifier for the job structure */
    CRYPTO_JOBSTATE_IDLE,                   /* jobState                   - Determines the current job state */
    {
        NULL_PTR,                           /* inputPtr                   - Pointer to the input data. */
        0,                                  /* inputLength                - Contains the input length in bytes. */
        NULL_PTR,                           /* secondaryInputPtr          - Pointer to the secondary input data (for MacVerify, SignatureVerify). */
        0U,                                 /* secondaryInputLength       - Contains the secondary input length in bytes. */
        NULL_PTR,                           /* tertiaryInputPtr           - Pointer to the tertiary input data (for MacVerify, SignatureVerify). */
        0U,                                 /* tertiaryInputLength        - Contains the tertiary input length in bytes. */
        NULL_PTR,                           /* outputPtr                  - Pointer to the output data. */
        NULL_PTR,                           /* outputLengthPtr            - Holds a pointer to a memory location containing the output length in bytes. */
        NULL_PTR,                           /* secondaryOutputPtr         - Pointer to the secondary output data. */
        NULL_PTR,                           /* secondaryOutputLengthPtr   - Holds a pointer to a memory location containing the secondary output length in bytes. */
        0U,                                 /* input64                    - Versatile input parameter */
        NULL_PTR,                           /* verifyPtr                  - Output pointer to a memory location holding a Crypto_VerifyResultType */
        NULL_PTR,                           /* output64Ptr                - Output pointer to a memory location holding an uint64. */
        CRYPTO_OPERATIONMODE_SINGLECALL,    /* mode                       - Indicator of the mode(s)/operation(s) to be performed */
        0U,                                 /* cryIfKeyId                 - Holds the CryIf key id for key operation services. */
        0U,                                 /* targetCryIfKeyId           - Holds the target CryIf key id for key operation services. */
    }, 
    &App_JobAes128EcbEncryptPrimitiveInfo,  /* jobPrimitiveInfo           - Pointer to a structure containing further information, which depends on the job and the crypto primitive */
    &App_JobAes128EcbEncryptInfo,           /* jobInfo                    - Pointer to a structure containing further information, which depends on the job and the crypto primitive */
    NULL_PTR                                /* jobRedirectionInfoRef      - Pointer to a structure containing further information on the usage of keys as input and output for jobs. */
#if (STD_ON == CRYPTO_ENABLE_ALTERNATE_MAPPING_FOR_JOB_KEY)
    ,0U                                      /* cryptoKeyId                - Identifier of the Crypto Driver key. The identifier shall be written by the Crypto Interface */
#endif
};

/* --- Structure of the job to be passed to Crypto driver, requesting Aes128 ECB Encrypt --------------------------------------------------------------------- */
static Crypto_JobType App_JobAes128EcbDecrypt = 
{
    2U,                                     /* jobId                      - Identifier for the job structure */
    CRYPTO_JOBSTATE_IDLE,                   /* jobState                   - Determines the current job state */
    {
        NULL_PTR,                           /* inputPtr                   - Pointer to the input data. */
        0,                                  /* inputLength                - Contains the input length in bytes. */
        NULL_PTR,                           /* secondaryInputPtr          - Pointer to the secondary input data (for MacVerify, SignatureVerify). */
        0U,                                 /* secondaryInputLength       - Contains the secondary input length in bytes. */
        NULL_PTR,                           /* tertiaryInputPtr           - Pointer to the tertiary input data (for MacVerify, SignatureVerify). */
        0U,                                 /* tertiaryInputLength        - Contains the tertiary input length in bytes. */
        NULL_PTR,                           /* outputPtr                  - Pointer to the output data. */
        NULL_PTR,                           /* outputLengthPtr            - Holds a pointer to a memory location containing the output length in bytes. */
        NULL_PTR,                           /* secondaryOutputPtr         - Pointer to the secondary output data. */
        NULL_PTR,                           /* secondaryOutputLengthPtr   - Holds a pointer to a memory location containing the secondary output length in bytes. */
        0U,                                 /* input64                    - Versatile input parameter */
        NULL_PTR,                           /* verifyPtr                  - Output pointer to a memory location holding a Crypto_VerifyResultType */
        NULL_PTR,                           /* output64Ptr                - Output pointer to a memory location holding an uint64. */
        CRYPTO_OPERATIONMODE_SINGLECALL,    /* mode                       - Indicator of the mode(s)/operation(s) to be performed */
        0U,                                 /* cryIfKeyId                 - Holds the CryIf key id for key operation services. */
        0U,                                 /* targetCryIfKeyId           - Holds the target CryIf key id for key operation services. */
    }, 
    &App_JobAes128EcbDecryptPrimitiveInfo,  /* jobPrimitiveInfo           - Pointer to a structure containing further information, which depends on the job and the crypto primitive */
    &App_JobAes128EcbDecryptInfo,           /* jobInfo                    - Pointer to a structure containing further information, which depends on the job and the crypto primitive */
    NULL_PTR                                /* jobRedirectionInfoRef      - Pointer to a structure containing further information on the usage of keys as input and output for jobs. */
#if (STD_ON == CRYPTO_ENABLE_ALTERNATE_MAPPING_FOR_JOB_KEY)
    ,0U                                      /* cryptoKeyId                - Identifier of the Crypto Driver key. The identifier shall be written by the Crypto Interface */
#endif
};


/* ---- Variables used in the function App_EraseCsecKeys() that restores the Csec to original state after running the example's code --------------------------- */
static uint8 aChallenge[16]     = { 0x00 };
static uint8 aAuthorization[16] = { 0x00 };
static uint8 aAuthPlain[31]     = { 0x00 };

static uint8 aMAC[16]           = { 0x00 };
static uint8 aUID[15]           = { 0x00 };
static uint8 aKey[16]           = { 0x00 };

static uint8 aKeyPlain[32] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x03, 0x53, 0x48, 0x45, 0x00, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0,  
};

/* Variables used by the function App_LoadCsecKey() that is used to load masterEcuKey in order to be able to erase all CSEc keys at the end of example execution */
static uint8 aK1Plain[32U] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x53, 0x48, 0x45, 0x00, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0
};

static uint8 aK2Plain[32U] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x02, 0x53, 0x48, 0x45, 0x00, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0
};

static const uint8 aEmptyIV[16] = { 0x00 };

static uint8 aK1[16]      = { 0x00 };
static uint8 aK2[16]      = { 0x00 };
static uint8 aK3[16]      = { 0x00 };
static uint8 aK4[16]      = { 0x00 };

static uint8 aM1[16]      = { 0x00 };
static uint8 aM2[32]      = { 0x00 };
static uint8 aM2Plain[32] = { 0x00 };
static uint8 aM3[16]      = { 0x00 };
static uint8 aM4Ref[16]   = { 0x00 };
static uint8 aM4Plain[16] = { 0x00 };
static uint8 aM4[32]      = { 0x00 };
static uint8 aM5[16]      = { 0x00 };
static uint8 aM1M2[48]    = { 0x00 };

/* Variable used to determine if the entire exemple run was successful (should remain set to 0U at the end of example execution) */
static uint32 u32NumFailedApiCalls = 0U;

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void App_PrepareAes128EcbEncryptJob
(
    uint32  u32KeyId,
    uint8*  pPlainText,
    uint32  u32PlainTextSize,
    uint8*  pCipherText,
    uint32* pu32CipherTextSize
);

static void App_PrepareAes128EcbDecryptJob
(
    uint32  u32KeyId,
    uint8*  pCipherText,
    uint32  u32CipherTextSize,
    uint8*  pPlainText,
    uint32* pu32PlainTextSize
);

static Std_ReturnType App_InitCsecHw
(
    uint8 u8KeySize, 
    uint8 u8Sfe
);

static void App_EraseCsecKeys(void);

static void App_LoadCsecKey
(
    uint8  keyId,
    uint8  authKeyId,
    const  uint8* pNewKey,
    const  uint8* pAuthKey,
    uint32 counter,
    uint8  flags,
    const  uint8* pUID
);

/* Utility functions */
static boolean Util_Memcmp
(
    uint8* pSource,
    uint8* pDest,
    uint32 u32Size
);

static void Util_Memset
(
    void*  pDest,
    uint8  u8Value,
    uint32 u32Size
);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
static void App_PrepareAes128EcbEncryptJob
(
    uint32  u32KeyId,             /* IN     - Identifier of the used Crypto key                                                */
    uint8*  pPlainText,           /* IN     - Pointer to the buffer storing the plain text                                     */
    uint32  u32PlainTextSize,     /* IN     - Size of the plain text                                                           */
    uint8*  pCipherText,          /* IN     - Pointer to the buffer where the cipherText will be stored                        */
    uint32* pu32CipherTextSize    /* IN/OUT - IN:  Contains the max size of the app buffer where the cipher text will be stored
                                              OUT: Is updated by the Crypto driver with the actual size of the cipher text     */
)
{
    App_JobAes128EcbEncryptPrimitiveInfo.cryIfKeyId                 = u32KeyId;
    App_JobAes128EcbEncrypt.jobPrimitiveInputOutput.inputPtr        = pPlainText;
    App_JobAes128EcbEncrypt.jobPrimitiveInputOutput.inputLength     = u32PlainTextSize;
    App_JobAes128EcbEncrypt.jobPrimitiveInputOutput.outputPtr       = pCipherText;
    App_JobAes128EcbEncrypt.jobPrimitiveInputOutput.outputLengthPtr = pu32CipherTextSize;
}

static void App_PrepareAes128EcbDecryptJob
(
    uint32  u32KeyId,            /* IN     - Identifier of the used Crypto key                                                 */
    uint8*  pCipherText,         /* IN     - Pointer to the buffer storing the cipher text                                     */
    uint32  u32CipherTextSize,   /* IN     - Size of the cipher text                                                           */
    uint8*  pPlainText,          /* IN     - Pointer to the buffer where the plain text will be stored                         */
    uint32* pu32PlainTextSize    /* IN/OUT - IN:  Contains the max size of the app buffer where the plain text will be stored
                                             OUT: Is updated by the Crypto driver with the actual size of the plain text       */
)
{
    App_JobAes128EcbDecryptPrimitiveInfo.cryIfKeyId                 = u32KeyId;
    App_JobAes128EcbDecrypt.jobPrimitiveInputOutput.inputPtr        = pCipherText;
    App_JobAes128EcbDecrypt.jobPrimitiveInputOutput.inputLength     = u32CipherTextSize;
    App_JobAes128EcbDecrypt.jobPrimitiveInputOutput.outputPtr       = pPlainText;
    App_JobAes128EcbDecrypt.jobPrimitiveInputOutput.outputLengthPtr = pu32PlainTextSize;
}

static Std_ReturnType App_InitCsecHw
(
    uint8 u8KeySize, 
    uint8 u8Sfe
)
{
    Std_ReturnType RetVal  = (Std_ReturnType)E_NOT_OK;
    uint8          u8FStat = 0U;
    
    /* CSEc IP hardware is not initialized if RAMRDY bit is set or EEERDY bit is clear */
    if ((APP_CSEC_IP_RAMRDY_IS_SET) || (!APP_CSEC_IP_EEERDY_IS_SET))
    {
        /* Run PGMPART command to start initialize HW */
        /* PGMPART command */
        CSEC_IP_FLASH->FCCOB[3] = 0x80U;
        /* CSEc Key Size */
        CSEC_IP_FLASH->FCCOB[2] = u8KeySize;
        /* Security Flag Extension */
        CSEC_IP_FLASH->FCCOB[1] = u8Sfe;

        CSEC_IP_FLASH->FCCOB[0] = 0;
        /* EEPROM Data Set Size Code */
        CSEC_IP_FLASH->FCCOB[7] = FLASH_FLEXNVM_EEPROM;
        /* FlexNVM Partition Code - 32 Kbs Data Flash, 32 Kbs EEPROM backup */
        CSEC_IP_FLASH->FCCOB[6] = (uint8)T_DEPART;
        /* Clear CCIF */
        CSEC_IP_FLASH->FSTAT = CSEC_IP_FSTAT_CCIF_MASK;

        /* Wait for command to finish */
        while (!((CSEC_IP_FLASH->FSTAT) & CSEC_IP_FSTAT_CCIF_MASK));
        
        u8FStat = CSEC_IP_FLASH->FSTAT;
        if( 0x00U == ((u8FStat & APP_CSEC_IP_MGSTAT0_MASK) | (u8FStat & CSEC_IP_FSTAT_ACCERR_MASK)) )
        {
           RetVal = (Std_ReturnType)E_OK;
        }
    }
    else
    {
        /* Csec IP hardware is already initialized */
        RetVal = (Std_ReturnType)E_OK;
    }
    
    return RetVal;
}

static void App_EraseCsecKeys(void)
{
    Csec_Ip_ErrorCodeType CsecResponse;
    Csec_Ip_ReqType       CsecIpReq;
    uint8                 u8Status;
    uint8                 u8Idx;
    
    /* Mark the future requests made to Csec Ip as synchronous */
    CsecIpReq.eReqType = CSEC_IP_REQTYPE_SYNC;

    /* Load the MasterEcuKey */
    App_LoadCsecKey(CSEC_IP_MASTER_ECU_KEY, CSEC_IP_MASTER_ECU_KEY, aMasterEcuKey, aEmptyKey, u32Counter, u8Flags, aEmptyUID);

    /* Retrieve the UID */
    CsecResponse = Csec_Ip_GetId(aChallenge, aUID, &u8Status, aMAC);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);

    for (u8Idx = 0; u8Idx < 15; u8Idx++)
    {
        aAuthPlain[u8Idx + 16] = aUID[u8Idx];
    }
    
    /* Derive the debug key K = KDF(MASTER_ECU_KEY, DEBUG_KEY_C) */
    for (u8Idx = 0; u8Idx < 16; u8Idx++) 
    {
        aKeyPlain[u8Idx] = aMasterEcuKey[u8Idx];
    }
    CsecResponse = Csec_Ip_MpCompress(aKeyPlain, 2, aKey);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);

    /* Load K into RAM_KEY slot, to be used in the MAC generation */
    CsecResponse = Csec_Ip_LoadPlainKey(aKey);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);

    /* Generate the debug challenge */
    CsecResponse = Csec_Ip_DbgChal(aChallenge);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
    
    for (u8Idx = 0; u8Idx < 16; u8Idx++)
    {
        aAuthPlain[u8Idx] = aChallenge[u8Idx];
    }
        
    /* Generate the authorization MAC */
    CsecResponse = Csec_Ip_GenerateMac(&CsecIpReq, CSEC_IP_RAM_KEY, aAuthPlain, 248, aAuthorization);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
  
    /* Request the authentication */
    CsecResponse = Csec_Ip_DbgAuth(aAuthorization);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
}


static void App_LoadCsecKey
(
    uint8  keyId,
    uint8  authKeyId,
    const  uint8* pNewKey,
    const  uint8* pAuthKey,
    uint32 counter,
    uint8  flags,
    const  uint8* pUID
)
{

    Csec_Ip_ErrorCodeType CsecResponse;
    uint8                 u8Idx;
    boolean               bValidationStatus = (boolean)TRUE;
    Csec_Ip_ReqType       CsecIpReq;

    /* Mark the future requests made to Csec Ip as synchronous */
    CsecIpReq.eReqType = CSEC_IP_REQTYPE_SYNC;

    /* Generate K1 & K2 */
    for (u8Idx = 0; u8Idx < 16U; u8Idx++) 
    {
        aK1Plain[u8Idx] = pAuthKey[u8Idx];
        aK2Plain[u8Idx] = pAuthKey[u8Idx];
    }
    
    CsecResponse = Csec_Ip_MpCompress(aK1Plain, 2, aK1);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
    
    CsecResponse = Csec_Ip_MpCompress(aK2Plain, 2, aK2);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
    
    /* Prepare M1 */
    for (u8Idx = 0; u8Idx < 15U; u8Idx++)
    {
        aM1[u8Idx] = pUID[u8Idx];
    }
    
    aM1[15] = (authKeyId & 0x0F) | ((keyId & 0x0F) << 4);
    
    /* Generate M2 */
    for (u8Idx = 0; u8Idx < 16; u8Idx++)
    {
        aM2Plain[u8Idx + 16U] = pNewKey[u8Idx];
    }
    
    aM2Plain[0] = ((counter << 0x04) & 0xff000000) >> 0x18;
    aM2Plain[1] = ((counter << 0x04) & 0x00ff0000) >> 0x10;
    aM2Plain[2] = ((counter << 0x04) & 0x0000ff00) >> 0x08;
    aM2Plain[3] = ((counter << 0x04) & 0x000000ff) >> 0x00;
    
    aM2Plain[3] |= (flags & 0x1e) >> 1U;
    aM2Plain[4] |= (flags & 0x01) << 7U;
    
    /* Encrypt M2 */
    CsecResponse = Csec_Ip_LoadPlainKey(aK1);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
    
    CsecResponse = Csec_Ip_EncryptCbc(&CsecIpReq, CSEC_IP_RAM_KEY, aM2Plain, 32, aEmptyIV, aM2);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
    
    /* Generate M3 */    
    for (u8Idx = 0; u8Idx < 16U; u8Idx++) 
    {
        aM1M2[u8Idx]       = aM1[u8Idx];
        aM1M2[u8Idx + 16U] = aM2[u8Idx];
        aM1M2[u8Idx + 32U] = aM2[u8Idx + 16U];
    }
    
    CsecResponse = Csec_Ip_LoadPlainKey(aK2);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
    
    CsecResponse = Csec_Ip_GenerateMac(&CsecIpReq, CSEC_IP_RAM_KEY, aM1M2, 384, aM3);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
    
    /* Load Key */
    CsecResponse = Csec_Ip_LoadKey((Csec_Ip_KeyIdType)keyId, aM1, aM2, aM3, aM4, aM5);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
    
    /* Generate K3 & K4 */
    for (u8Idx = 0; u8Idx < 16; u8Idx++) 
    {
        aK1Plain[u8Idx] = pNewKey[u8Idx];
        aK2Plain[u8Idx] = pNewKey[u8Idx];
    }
    
    CsecResponse = Csec_Ip_MpCompress(aK1Plain, 2, aK3);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
    
    CsecResponse = Csec_Ip_MpCompress(aK2Plain, 2, aK4);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
    
    /* Prepare M4' (aM4Ref) */   
    aM4Plain[0]  = ((counter << 0x04) & 0xff000000) >> 0x18;
    aM4Plain[1]  = ((counter << 0x04) & 0x00ff0000) >> 0x10;
    aM4Plain[2]  = ((counter << 0x04) & 0x0000ff00) >> 0x08;
    aM4Plain[3]  = ((counter << 0x04) & 0x000000ff) >> 0x00;
    aM4Plain[3] |= 0x08;
    
    CsecResponse = Csec_Ip_LoadPlainKey(aK3);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
    
    CsecResponse = Csec_Ip_EncryptEcb(&CsecIpReq, CSEC_IP_RAM_KEY, aM4Plain, 16, aM4Ref);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
    
    /* Validate M4 */
    App_SetSuccessStatus(((aM4[15] & 0xf0) >> 4) == (keyId & 0x0f));
    App_SetSuccessStatus((aM4[15] & 0x0f) == (authKeyId & 0x0f));
    
    for (u8Idx = 0; u8Idx < 16U; u8Idx++)
    {
        if (aM4Ref[u8Idx] != aM4[u8Idx + 16U])
        {
            bValidationStatus = (boolean)FALSE;
        }
    }
    
    App_SetSuccessStatus((boolean)TRUE == bValidationStatus);
    
    /* Generate M5 */
    CsecResponse = Csec_Ip_LoadPlainKey(aK4);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
    
    /* Validate M5 */    
    CsecResponse = Csec_Ip_VerifyMac(&CsecIpReq, CSEC_IP_RAM_KEY, aM4, 256, aM5, 0, &bValidationStatus);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
    App_SetSuccessStatus((boolean)TRUE == bValidationStatus);
}


/* Utility functions */
static boolean Util_Memcmp
(
    uint8* pSource,
    uint8* pDest,
    uint32 u32Size
)
{
    boolean bResult      = (boolean)TRUE;
    uint32  u32InputSize = u32Size;
    
    while (0U < u32InputSize--) 
    {
        if (*pSource == *pDest)
        {
            pSource++;
            pDest++; 
        }
        else
        {
            bResult = (boolean)FALSE;
            break;
        }
    }
    return bResult;
}

static void Util_Memset
(
    void*  pDest,
    uint8  u8Value,
    uint32 u32Size
)
{
    uint32 u32Counter;
    uint8* ptr = (uint8*)pDest;

    for (u32Counter = 0U; u32Counter < u32Size; u32Counter++) 
    {
        *ptr = u8Value;
        ptr++;
    }
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief          Exercises the AES128 ECB Encryption and Decryption features of Cryto driver
*
* @details        Performs 2 synchronous encryption/decryption operations with 2 different values for the key and 2 different plain/cipher texts
*                 Assumes that both the values of the key and the data to encrypt/decrypt can change at run-time, so they are stored in RAM
*                 At the end of the example run, the Csec keys are erased in order to restore the device to its original state
*
*                 Xdm configuration:
*                   - Because the value(Key Material) of the AES128 key that is used is changed at run-time, the key element that stores the key must be stored 
*                 in the RAM key slot so it can be updated for as many times as needed.
*                   - The Crypto Driver Object that is used to process the jobs (CDO_Symmetric) should have the AES128_Encrypt and AES128_Decrypt primitives set
*/
int main(void) 
{
    Std_ReturnType RetVal;

    /* =============================================================================================================================== */
    /*    Initialization                                                                                                               */ 
    /* =============================================================================================================================== */
    /* Initialize CSEc hardware */
    RetVal = App_InitCsecHw(KEY_SIZE,SFE);
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);
    /* Initialize OsIf component. It will be used to measure timeouts while waiting for CSEc to respond to synchronous requests */
    OsIf_Init(NULL_PTR);
    /* Initialize Crypto driver */
    Crypto_Init(NULL_PTR);
    
    /* =============================================================================================================================== */
    /*    Encryption Example 1: Using first key to encrypt 16 bytes of data                                                            */ 
    /* =============================================================================================================================== */
    
    /* ------------------------------------------------------------------------------------------------------------------------------- */
    /*    Key management                                                                                                               */
    /* ------------------------------------------------------------------------------------------------------------------------------- */

    /* Load the value of the first AES128 key into CSEc RAM key slot */
    RetVal = Crypto_KeyElementSet(APP_AES128_KEY_ID, KEY_MATERIAL_ELEMENT_ID_U32, App_au8Aes128EcbKey_1, APP_AES128_KEY_SIZE);
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);

    /* Mark the key as valid, so it can be used by Crypto driver in future job requests */
    RetVal = Crypto_KeySetValid(APP_AES128_KEY_ID);
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);

    /* ------------------------------------------------------------------------------------------------------------------------------- */
    /*    AES128 ECB Encryption                                                                                                        */
    /* ------------------------------------------------------------------------------------------------------------------------------- */

    /* This variable will be used to inform Crypto driver about the max length in bytes of the buffer where it can put the result of the encryption */
    App_u32Aes128EcbResultSize = APP_AES128_ECB_RESULT_SIZE;

    /* Clear the result buffer, in order to be able to check the successful result of encryption */
    Util_Memset(App_au8Aes128EcbResult, 0U, APP_AES128_ECB_RESULT_SIZE);

    /* Prepare the information in the job to be sent to Crypto driver */
    App_PrepareAes128EcbEncryptJob(APP_AES128_KEY_ID, App_au8Aes128EcbPlaintext_1, APP_AES128_ECB_PLAIN_TEXT_SIZE_1, App_au8Aes128EcbResult, &App_u32Aes128EcbResultSize);

    /* Request Crypto driver to perform AES128 Encryption */
    RetVal = Crypto_ProcessJob(APP_AES128_CDO_ID, &App_JobAes128EcbEncrypt);
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);
    App_SetSuccessStatus(App_u32Aes128EcbResultSize == APP_AES128_ECB_CIPHER_TEXT_SIZE_1);
    App_SetSuccessStatus(Util_Memcmp(App_au8Aes128EcbResult, App_au8Aes128EcbCiphertext_1, APP_AES128_ECB_CIPHER_TEXT_SIZE_1));

    /* =============================================================================================================================== */
    /*    Encryption Example 2: Using second key to encrypt 64 bytes of data                                                           */ 
    /* =============================================================================================================================== */
    
    /* ------------------------------------------------------------------------------------------------------------------------------- */
    /*    Key management                                                                                                               */
    /* ------------------------------------------------------------------------------------------------------------------------------- */

    /* Load the value of the second AES128 key into CSEc RAM key slot */
    RetVal = Crypto_KeyElementSet(APP_AES128_KEY_ID, KEY_MATERIAL_ELEMENT_ID_U32, App_au8Aes128EcbKey_2, APP_AES128_KEY_SIZE);
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);

    /* Mark the key as valid, so it can be used by Crypto driver in future job requests */
    RetVal = Crypto_KeySetValid(APP_AES128_KEY_ID);
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);

    /* ------------------------------------------------------------------------------------------------------------------------------- */
    /*    AES128 ECB Encryption                                                                                                        */
    /* ------------------------------------------------------------------------------------------------------------------------------- */

    /* This variable will be used to inform Crypto driver about the max length in bytes of the buffer where it can put the result of the encryption */
    App_u32Aes128EcbResultSize = APP_AES128_ECB_RESULT_SIZE;

    /* Clear the result buffer, in order to be able to check the successful result of encryption */
    Util_Memset(App_au8Aes128EcbResult, 0U, APP_AES128_ECB_RESULT_SIZE);

    /* Prepare the information in the job to be sent to Crypto driver */
    App_PrepareAes128EcbEncryptJob(APP_AES128_KEY_ID, App_au8Aes128EcbPlaintext_2, APP_AES128_ECB_PLAIN_TEXT_SIZE_2, App_au8Aes128EcbResult, &App_u32Aes128EcbResultSize);

    /* Request Crypto driver to perform AES128 Encryption */
    RetVal = Crypto_ProcessJob(APP_AES128_CDO_ID, &App_JobAes128EcbEncrypt);
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);
    App_SetSuccessStatus(App_u32Aes128EcbResultSize == APP_AES128_ECB_CIPHER_TEXT_SIZE_2);
    App_SetSuccessStatus(Util_Memcmp(App_au8Aes128EcbResult, App_au8Aes128EcbCiphertext_2, APP_AES128_ECB_CIPHER_TEXT_SIZE_2));

    /* =============================================================================================================================== */
    /*    Decryption Example 1: Using first key to decrypt 16 bytes of data                                                            */ 
    /* =============================================================================================================================== */
    
    /* ------------------------------------------------------------------------------------------------------------------------------- */
    /*    Key management                                                                                                               */
    /* ------------------------------------------------------------------------------------------------------------------------------- */

    /* Load the value of the first AES128 key into CSEc RAM key slot */
    RetVal = Crypto_KeyElementSet(APP_AES128_KEY_ID, KEY_MATERIAL_ELEMENT_ID_U32, App_au8Aes128EcbKey_1, APP_AES128_KEY_SIZE);
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);

    /* Mark the key as valid, so it can be used by Crypto driver in future job requests */
    RetVal = Crypto_KeySetValid(APP_AES128_KEY_ID);
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);

    /* ------------------------------------------------------------------------------------------------------------------------------- */
    /*    AES128 ECB Decryption                                                                                                        */
    /* ------------------------------------------------------------------------------------------------------------------------------- */

    /* This variable will be used to inform Crypto driver about the max length in bytes of the buffer where it can put the result of the decryption */
    App_u32Aes128EcbResultSize = APP_AES128_ECB_RESULT_SIZE;

    /* Clear the result buffer, in order to be able to check the successful result of decryption */
    Util_Memset(App_au8Aes128EcbResult, 0U, APP_AES128_ECB_RESULT_SIZE);

    /* Prepare the information in the job to be sent to Crypto driver */
    App_PrepareAes128EcbDecryptJob(APP_AES128_KEY_ID, App_au8Aes128EcbCiphertext_1, APP_AES128_ECB_CIPHER_TEXT_SIZE_1, App_au8Aes128EcbResult, &App_u32Aes128EcbResultSize);

    /* Request Crypto driver to perform AES128 Decryption */
    RetVal = Crypto_ProcessJob(APP_AES128_CDO_ID, &App_JobAes128EcbDecrypt);
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);
    App_SetSuccessStatus(App_u32Aes128EcbResultSize == APP_AES128_ECB_PLAIN_TEXT_SIZE_1);
    App_SetSuccessStatus(Util_Memcmp(App_au8Aes128EcbResult, App_au8Aes128EcbPlaintext_1, APP_AES128_ECB_PLAIN_TEXT_SIZE_1));

    /* =============================================================================================================================== */
    /*    Decryption Example 2: Using second key to decrypt 64 bytes of data                                                           */ 
    /* =============================================================================================================================== */
    
    /* ------------------------------------------------------------------------------------------------------------------------------- */
    /*    Key management                                                                                                               */
    /* ------------------------------------------------------------------------------------------------------------------------------- */

    /* Load the value of the second AES128 key into CSEc RAM key slot */
    RetVal = Crypto_KeyElementSet(APP_AES128_KEY_ID, KEY_MATERIAL_ELEMENT_ID_U32, App_au8Aes128EcbKey_2, APP_AES128_KEY_SIZE);
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);

    /* Mark the key as valid, so it can be used by Crypto driver in future job requests */
    RetVal = Crypto_KeySetValid(APP_AES128_KEY_ID);
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);

    /* ------------------------------------------------------------------------------------------------------------------------------- */
    /*    AES128 ECB Decryption                                                                                                        */
    /* ------------------------------------------------------------------------------------------------------------------------------- */

    /* This variable will be used to inform Crypto driver about the max length in bytes of the buffer where it can put the result of the decryption */
    App_u32Aes128EcbResultSize = APP_AES128_ECB_RESULT_SIZE;

    /* Clear the result buffer, in order to be able to check the successful result of decryption */
    Util_Memset(App_au8Aes128EcbResult, 0U, APP_AES128_ECB_RESULT_SIZE);

    /* Prepare the information in the job to be sent to Crypto driver */
    App_PrepareAes128EcbDecryptJob(APP_AES128_KEY_ID, App_au8Aes128EcbCiphertext_2, APP_AES128_ECB_CIPHER_TEXT_SIZE_2, App_au8Aes128EcbResult, &App_u32Aes128EcbResultSize);

    /* Request Crypto driver to perform AES128 Decryption */
    RetVal = Crypto_ProcessJob(APP_AES128_CDO_ID, &App_JobAes128EcbDecrypt);
    App_SetSuccessStatus((Std_ReturnType)E_OK == RetVal);
    App_SetSuccessStatus(App_u32Aes128EcbResultSize == APP_AES128_ECB_PLAIN_TEXT_SIZE_2);
    App_SetSuccessStatus(Util_Memcmp(App_au8Aes128EcbResult, App_au8Aes128EcbPlaintext_2, APP_AES128_ECB_PLAIN_TEXT_SIZE_2));


    /* =============================================================================================================================== */
    /*    Erase keys in order to restore CSEc Hw to its original state                                                                 */ 
    /* =============================================================================================================================== */
    App_EraseCsecKeys();

    /* =============================================================================================================================== */
    /*    Finish application execution, signaling the status                                                                           */ 
    /* =============================================================================================================================== */
    Exit_Example(App_GetSuccessStatus());
    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
