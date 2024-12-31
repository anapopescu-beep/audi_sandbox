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
#include "Csec_Ip.h"
#include "OsIf.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/* Enumeration storing the type of encryption requests performed in this example */
typedef enum
{
    ENCRYPT_SYNC = 0UL,
    ENCRYPT_ASYNC_POLL,
}App_EncryptionType;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Function-like macros to set and get the status of the example run */
#define App_SetSuccessStatus(value)         (u32NumFailedApiCalls += ((value) ? 0U : 1U))
#define App_GetSuccessStatus()              (0U == u32NumFailedApiCalls)

/* Timeout for the CSEc_Ip layer while waiting for a response from CSEc for a synchronous request.
   As the CSEc component is configured in this example to have the type of Timeout Counter set to 'OSIF_COUNTER_DUMMY',
the timeout in the variable below will be expressed in ticks */
#define TIMEOUT_TICKS_U32                   ((uint32)1000000U)

/* Size in bytes of the AES128 Encrypt/Decrypt key */
#define APP_SHE_KEY_SIZE                    (16U)

/* Size in bytes of the plain text that will be used to test encryption */
#define APP_AES128_ECB_PLAIN_TEXT_SIZE      (16U)

/* Size in bytes of the cipher text that will result after encryption */
#define APP_AES128_ECB_CIPHER_TEXT_SIZE     (16U)

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
/* Array storing the expected cipherText resulted when encrypting the plainText stored in App_au8Aes128EcbPlaintext[] array with
the key stored in App_au8SheRamKey[] array */
static const uint8 App_au8Aes128ExpectedEcbCiphertext[APP_AES128_ECB_CIPHER_TEXT_SIZE] =
{
    0x9c, 0x54, 0xd5, 0x71, 0x70, 0x2c, 0xfa, 0x0f, 0x03, 0xf3, 0x62, 0x15, 0x67, 0x6b, 0xab, 0x78
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
/* Variable that will store the internal state machine of the CSEc Ip layer.
   The address of the variable storing the internal state machine should be provided as parameter when the CSEc Ip layer is initialized. */
static Csec_Ip_StateType Csec_Ip_State;

/* Variable used to store the application request to CSEc Ip layer. This example uses both synchronous and asynchronous calls to CSEc Ip */
static Csec_Ip_ReqType Csec_Ip_Request;

/* Variable storing the number of successful responses received from CSEc for asynchronous requests using interrupts. */
static uint8 u8NumSuccessfulCsecResponses = 0;


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
/* The following RAM variables need to be put in non-cacheable memory in order to be correctly seen by CSEc */
#define CRYPTO_START_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Crypto_MemMap.h"

/* Array storing the value of the key */
uint8 App_au8SheRamKey[APP_SHE_KEY_SIZE] __attribute__((aligned)) =
{
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f
};

/* Array storing the value of the plainText to encrypt */
uint8 App_au8Aes128EcbPlaintext[APP_AES128_ECB_PLAIN_TEXT_SIZE] =
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
};

#define CRYPTO_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#include "Crypto_MemMap.h"


/* The following RAM variables need to be put in non-cacheable memory in order to be correctly seen by CSEc */
#define CRYPTO_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Crypto_MemMap.h"

/* Array storing the value of the cipherText resulted after an encryption request */
uint8  App_au8Aes128EcbCipherText[APP_AES128_ECB_CIPHER_TEXT_SIZE];

#define CRYPTO_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Crypto_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void Csec_Ip_RxCallback
(
    Csec_Ip_ErrorCodeType ErrCode, 
    Csec_Ip_CmdType       eCompletedCmd,
    void*                 pCallbackParam
);

static Csec_Ip_ErrorCodeType App_Aes128EncryptEcb
(
    App_EncryptionType encryptionType
);

static boolean App_InitCsecHw
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

static void Util_DelayTicks
(
    uint32 numTicks
);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/* Callback for asynchronous requests sent by Csec_Ip layer */
static void Csec_Ip_RxCallback
(
    Csec_Ip_ErrorCodeType ErrCode, 
    Csec_Ip_CmdType       eCompletedCmd,
    void*                 pCallbackParam
)
{
    if((CSEC_IP_ERC_NO_ERROR == ErrCode) &&
       (Util_Memcmp((uint8*)App_au8Aes128EcbCipherText, (uint8*)App_au8Aes128ExpectedEcbCiphertext, APP_AES128_ECB_CIPHER_TEXT_SIZE)))
    {
        u8NumSuccessfulCsecResponses++;
    }

    /* Clear the buffer where the cipherText will be updated by Csec */
    Util_Memset(App_au8Aes128EcbCipherText, 0U, APP_AES128_ECB_CIPHER_TEXT_SIZE);

    /* Ignore compiler warning for not used parameters */
    (void)eCompletedCmd;
    (void)pCallbackParam;
}

static Csec_Ip_ErrorCodeType App_Aes128EncryptEcb
(
    App_EncryptionType encryptionType
)
{
    Csec_Ip_ErrorCodeType RetVal = CSEC_IP_ERC_NO_ERROR;

    switch(encryptionType)
    {
        case ENCRYPT_SYNC:
            /* Build the request to be sent to Csec Ip layer */
            Csec_Ip_Request.eReqType = CSEC_IP_REQTYPE_SYNC;
            break;

        case ENCRYPT_ASYNC_POLL:
            /* Build the request to be sent to Csec Ip layer */
            Csec_Ip_Request.eReqType   = CSEC_IP_REQTYPE_ASYNC_POLL;
            Csec_Ip_Request.pfCallback = Csec_Ip_RxCallback;
            break;

        default:
            break;
    }

    /* Send the request to Csec Ip layer */
    RetVal = Csec_Ip_EncryptEcb(&Csec_Ip_Request,
                                CSEC_IP_RAM_KEY,
                                App_au8Aes128EcbPlaintext,
                                APP_AES128_ECB_PLAIN_TEXT_SIZE,
                                App_au8Aes128EcbCipherText
                               );

    return RetVal;
}

static boolean App_InitCsecHw
(
    uint8 u8KeySize, 
    uint8 u8Sfe
)
{
    boolean bRetVal = (boolean)FALSE;
    uint8   u8FStat = 0U;
    
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
            bRetVal = (boolean)TRUE;
        }
    }
    else
    {
        /* Csec IP hardware is already initialized */
        bRetVal = (boolean)TRUE;
    }
    
    return bRetVal;
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

static void Util_DelayTicks
(
    uint32 numTicks
)
{
    static volatile uint32 u32NumTicks;
    uint32                 u32Counter;

    u32NumTicks = numTicks;

    for (u32Counter = 0; u32Counter < u32NumTicks; u32Counter++);
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief          Initializes the CSEc Ip, imports a SHE RAM key and sends synchronous and asynchronous encryption requests to CSEc
*
* @details        The code in the main function of the application performs the following steps:
                   - Initializes the CSEc hardware
*                  - Initializes the OsIf component. It is used by Csec_Ip layer to determine the timeout while waiting for responses from CSEc for synchronous requests
*                  - Initializes the Csec Ip layer
*                  - Initializes the Csec random number generator
*                  - Imports the material of the SHE key in the SHE Ram Key slot
*                  - Initiates a synchronous AES128 encryption request and checks that the cipherText is the expected one
*                  - Initiates an asynchronous AES128 encryption request and checks that the cipherText is the expected one
*                  - At the end of the example run, the Csec keys are erased in order to restore the device to its original state
*/
int main(void)
{
    boolean                bRetVal;
    Csec_Ip_ErrorCodeType  CsecResponse;
    static volatile uint8  u8NumSuccessfulCsecRequests = 0;

    /* =============================================================================================================================== */
    /*    Initialize CSEc hardware                                                                                                     */
    /* =============================================================================================================================== */
    bRetVal = App_InitCsecHw(KEY_SIZE,SFE);
    App_SetSuccessStatus((boolean)TRUE == bRetVal);

    /* =============================================================================================================================== */
    /*    Initialize OsIf component. It will be used to measure timeouts while waiting for Csec to respond to synchronous requests     */
    /* =============================================================================================================================== */
    OsIf_Init(NULL_PTR);

    /* =============================================================================================================================== */
    /*    Initialize Csec Ip layer                                                                                                     */
    /* =============================================================================================================================== */
    Csec_Ip_Init(&Csec_Ip_State);

    /* =============================================================================================================================== */
    /*    Initialize the random number generator                                                                                       */
    /* =============================================================================================================================== */
    CsecResponse = Csec_Ip_InitRng();
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
    
    /* =============================================================================================================================== */
    /*    Configure timeout for all synchronous operations                                                                             */
    /* =============================================================================================================================== */
    Csec_Ip_SetSynchronousCmdTimeout(TIMEOUT_TICKS_U32);

    /* =============================================================================================================================== */
    /*    Import a key in the SHE RAM key slot                                                                                         */
    /* =============================================================================================================================== */
    CsecResponse = Csec_Ip_LoadPlainKey(App_au8SheRamKey);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);

    /* =============================================================================================================================== */
    /*    Perform a synchronous AES128 encryption                                                                                      */
    /* =============================================================================================================================== */
    /* Clear the buffer where the cipherText will be updated by CSEc */
    Util_Memset(App_au8Aes128EcbCipherText, 0U, APP_AES128_ECB_CIPHER_TEXT_SIZE);

    CsecResponse = App_Aes128EncryptEcb(ENCRYPT_SYNC);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
    App_SetSuccessStatus(Util_Memcmp((uint8*)App_au8Aes128EcbCipherText, (uint8*)App_au8Aes128ExpectedEcbCiphertext, APP_AES128_ECB_CIPHER_TEXT_SIZE));

    /* =============================================================================================================================== */
    /*    Perform an asynchronous AES128 encryption request                                                                            */
    /* =============================================================================================================================== */
    CsecResponse = App_Aes128EncryptEcb(ENCRYPT_ASYNC_POLL);
    App_SetSuccessStatus(CSEC_IP_ERC_NO_ERROR == CsecResponse);
    if(CSEC_IP_ERC_NO_ERROR == CsecResponse)
    {
        u8NumSuccessfulCsecRequests++;
    }
    /* Allow some time (counted in ticks) for the requests to be processed */
    Util_DelayTicks(1000000);
    /* Call the main function */
    Csec_Ip_MainFunction();
    /* Check that the number of successfully sent requests have been received successful responses */
    App_SetSuccessStatus(u8NumSuccessfulCsecRequests == u8NumSuccessfulCsecResponses);

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
