/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : ENET
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
*   used strictly in accordance with the applicable license teENET_BUFFDESCR_IS_ALIGNEDrms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup ENET_DRIVER ENET Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Enet_Ip.h"
#include "Enet_Ip_TrustedFunctions.h"
#include "Enet_Ip_Hw_Access.h"
#include "Mcal.h"

#if (STD_ON == ENET_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif /* (STD_ON == ENET_DEV_ERROR_DETECT) */ 

#if (STD_ON == ENET_SET_USER_ACCESS_ALLOWED_AVAILABLE)
    #define USER_MODE_REG_PROT_ENABLED      (STD_ON)
    #include "RegLockMacros.h"
#endif /* (STD_ON == ENET_SET_USER_ACCESS_ALLOWED_AVAILABLE) */

/*==================================================================================================
*                              SOURCE FILE VERSION InfoRMATION
==================================================================================================*/
#define ENET_IP_VENDOR_ID_C                      43
#define ENET_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define ENET_IP_AR_RELEASE_MINOR_VERSION_C       4
#define ENET_IP_AR_RELEASE_REVISION_VERSION_C    0
#define ENET_IP_SW_MAJOR_VERSION_C               1
#define ENET_IP_SW_MINOR_VERSION_C               0
#define ENET_IP_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Enet_Ip.h */
#if (ENET_IP_VENDOR_ID_C !=  ENET_IP_VENDOR_ID)
    #error "Enet_Ip.c and Enet_Ip.h have different vendor ids"
#endif
#if (( ENET_IP_AR_RELEASE_MAJOR_VERSION_C    !=  ENET_IP_AR_RELEASE_MAJOR_VERSION) || \
     ( ENET_IP_AR_RELEASE_MINOR_VERSION_C    !=  ENET_IP_AR_RELEASE_MINOR_VERSION) || \
     ( ENET_IP_AR_RELEASE_REVISION_VERSION_C !=  ENET_IP_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip.c and Enet_Ip.h are different"
#endif
#if (( ENET_IP_SW_MAJOR_VERSION_C !=  ENET_IP_SW_MAJOR_VERSION) || \
     ( ENET_IP_SW_MINOR_VERSION_C !=  ENET_IP_SW_MINOR_VERSION) || \
     ( ENET_IP_SW_PATCH_VERSION_C !=  ENET_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Enet_Ip.c and Enet_Ip.h are different"
#endif

/* Checks against Enet_Ip_Hw_Access.h */
#if (ENET_IP_VENDOR_ID_C !=  ENET_IP_HW_ACCESS_VENDOR_ID)
    #error "Enet_Ip.c and Enet_Ip_Hw_Access.h have different vendor ids"
#endif
#if (( ENET_IP_AR_RELEASE_MAJOR_VERSION_C    !=  ENET_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     ( ENET_IP_AR_RELEASE_MINOR_VERSION_C    !=  ENET_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     ( ENET_IP_AR_RELEASE_REVISION_VERSION_C !=  ENET_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip.c and Enet_Ip_Hw_Access.h are different"
#endif
#if (( ENET_IP_SW_MAJOR_VERSION_C !=  ENET_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     ( ENET_IP_SW_MINOR_VERSION_C !=  ENET_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     ( ENET_IP_SW_PATCH_VERSION_C !=  ENET_IP_HW_ACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Enet_Ip.c and Enet_Ip_Hw_Access.h are different"
#endif

/* Checks against Enet_Ip_TrustedFunctions.h */
#if (ENET_IP_VENDOR_ID_C !=  ENET_IP_TRUSTEDFUNCTIONS_VENDOR_ID)
    #error "Enet_Ip.c and Enet_Ip_TrustedFunctions.h have different vendor ids"
#endif
#if (( ENET_IP_AR_RELEASE_MAJOR_VERSION_C    !=  ENET_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION) || \
     ( ENET_IP_AR_RELEASE_MINOR_VERSION_C    !=  ENET_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION) || \
     ( ENET_IP_AR_RELEASE_REVISION_VERSION_C !=  ENET_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Enet_Ip.c and Enet_Ip_TrustedFunctions.h are different"
#endif
#if (( ENET_IP_SW_MAJOR_VERSION_C !=  ENET_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION) || \
     ( ENET_IP_SW_MINOR_VERSION_C !=  ENET_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION) || \
     ( ENET_IP_SW_PATCH_VERSION_C !=  ENET_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Enet_Ip.c and Enet_Ip_TrustedFunctions.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((ENET_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ENET_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Enet_Ip.h and Mcal.h are different"
    #endif

    #if (STD_ON == ENET_SET_USER_ACCESS_ALLOWED_AVAILABLE)
        /* Checks against RegLockMacros.h */
        #if ((ENET_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
             (ENET_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR Version Numbers of Enet_Ip.h and RegLockMacros.h are different"
        #endif
    #endif /* (STD_ON == ENET_SET_USER_ACCESS_ALLOWED_AVAILABLE) */
    
    /* Checks against Devassert.h*/
    #if (STD_ON == ENET_DEV_ERROR_DETECT)
        #if (( ENET_IP_AR_RELEASE_MAJOR_VERSION_C    !=  DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            ( ENET_IP_AR_RELEASE_MINOR_VERSION_C     !=  DEVASSERT_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR Version Numbers of Enet_Ip.c and Devassert.h are different"
        #endif
    #endif
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
 
 #define MAC_BYTE_MASK              (0xFFU)

#define ENET_BYTE_5_IN_ADDR_SHIFT   (16U)
#define ENET_BYTE_4_IN_ADDR_SHIFT   (24U)
#define ENET_BYTE_3_IN_ADDR_SHIFT   (0U)
#define ENET_BYTE_2_IN_ADDR_SHIFT   (8U)
#define ENET_BYTE_1_IN_ADDR_SHIFT   (16U)
#define ENET_BYTE_0_IN_ADDR_SHIFT   (24U)

#define ENET_BD_LENGTH_MASK   (0x0000FFFFU)

#define ENET_MDIO_MIN_HOLD_TIME_NS  (10U)
#define ENET_NS_IN_SECOND           (1000000000U)
#define ENET_MDC_MAX_FREQUENCY      ((uint32)5U / (uint32)2U)
#define ENET_ROUNDED_UP_DIV(a, b)   (((uint32)(a) + (uint32)b) / (uint32)(b))

#define ENET_ENH1_CPC(x)            ((uint32)((uint32)(x) << 27U) & 0x18000000U)

#define ENET_PAUR_TYPE_VALUE   (0x00008808U)

#define ENET_BUFFDESCR_IS_ALIGNED(x)            (((uint32)(x) & (uint32)((uint32)FEATURE_ENET_BUFFDESCR_ALIGNMENT_BYTES - 1UL)) == 0UL)
#define ENET_BUFFLEN_IS_ALIGNED(x)              (((uint32)(x) & (uint32)((uint32)FEATURE_ENET_BUFFLEN_ALIGNMENT_BYTES - 1UL)) == 0UL)
#define ENET_BUFF_IS_ALIGNED(x)                 (((uint32)(x) & (uint32)((uint32)FEATURE_ENET_BUFFDATA_ALIGNMENT_BYTES - 1UL)) == 0UL)

#if (ENET_DEV_ERROR_DETECT == STD_ON)
    #define ENET_DEV_ASSERT(x)      DevAssert(x)
#else
    #define ENET_DEV_ASSERT(x)      
#endif

#define ENET_RMON_REG_READ(Base, Offset)                (*(volatile uint32*)((Base) + (uint32)((uint32)(Offset) << 2U)))

#define ENET_THRESHOLD_REG_WRITE(Base, Offset, Value)   ((*(volatile uint32*)((Base) + (uint32)((uint32)(Offset) << 2U))) = (Value))
/*******************************************************************************
 * Variables
 ******************************************************************************/
#define ETH_START_SEC_VAR_CLEARED_32
#include "Eth_MemMap.h"

/* Get value from GALR value */
static uint32 Enet_au32FirstHashTable[FEATURE_ENET_NUM_INSTANCES];
/* Get value from GAUR value */
static uint32 Enet_au32SecondHashTable[FEATURE_ENET_NUM_INSTANCES];

#define ETH_STOP_SEC_VAR_CLEARED_32
#include "Eth_MemMap.h"

#define ETH_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_MemMap.h"


/*! @brief Pointers to ENET internal driver state for each instance. */
Enet_Ip_StateType *Enet_apxState[FEATURE_ENET_NUM_INSTANCES] = {NULL_PTR};


#define ETH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_MemMap.h"

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"

static uint32 Enet_Ip_ComputeCRC32(const uint8 *Mac, uint8 Size);

static void Enet_Ip_GetTimeStamp(uint8 Instance,
                                 const Enet_Ip_BufferDescriptorType * Bd,
                                 Enet_Ip_TimeStampType * TimeStamp);
static void Enet_Ip_Reset(ENET_Type *Base);

static void Enet_Ip_SetTxBufferDescriptors(
                                            ENET_Type * Base,
                                            const Enet_CtrlConfigType *Config,
                                            const Enet_Ip_BufferConfigType TxRingConfig[]
                                            );
static void Enet_Ip_SetRxBufferDescriptors(
                                            ENET_Type * Base,
                                            const Enet_CtrlConfigType *Config,
                                            const Enet_Ip_BufferConfigType RxRingConfig[]
                                            );
static uint32 Enet_Ip_ReadTimerValue(uint8 Instance);
static void Enet_Ip_InitStateStruct(uint8 Instance,
                                    const Enet_CtrlConfigType *Config
                                    );
static void Enet_Ip_InitRegCtrl(ENET_Type * Base, 
                                const Enet_CtrlConfigType *Config
                                );
                                
/*FUNCTION**********************************************************************
 *
 * Function Name : ENET_DRV_ComputeCRC32
 * Description   : Computes the CRC32 of a given Mac address.
 *
 *END**************************************************************************/
static uint32 Enet_Ip_ComputeCRC32(const uint8 *Mac, uint8 Size)
{
    uint32 Crc = 0xFFFFFFFFUL;
    uint8 i;
    uint8 j;

    for (i = 0; i < Size; i++)
    {
        Crc = Crc ^ Mac[i];
        for (j = 0; j < 8U; j++)
        {
            if ((Crc & 0x1U) != 0U)
            {
                Crc = (Crc >> 1U) ^ 0xEDB88320U;
            }
            else
            {
                Crc = (Crc >> 1U);
            }
        }
    }

    return Crc;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_InitStateStruct
 * Description   : Initialize value for state structure.
 *END**************************************************************************/
static void Enet_Ip_InitStateStruct(uint8 Instance,
                                    const Enet_CtrlConfigType *Config
                                    )
{
    uint32 i;
    
    Config->Enet_pCtrlState->Callback    = Config->Enet_pCtrlConfig->Callback;
    Config->Enet_pCtrlState->RxRingCount = Config->Enet_pCtrlConfig->RxRingCount;
    Config->Enet_pCtrlState->TxRingCount = Config->Enet_pCtrlConfig->TxRingCount;
    Config->Enet_pCtrlState->TimerCallback = Config->Enet_pCtrlConfig->TimerCallback;
    for (i = 0; i < Config->Enet_pCtrlConfig->RxRingCount; i++)
    {
        Config->Enet_pCtrlState->RxChCallback[i]  = Config->Enet_paCtrlRxRingConfig[i].Callback;
        Config->Enet_pCtrlState->RxCurrentDesc[i] = Config->Enet_paCtrlRxRingConfig[i].RingDesc;
        Config->Enet_pCtrlState->RxBdAlloc[i]     = Config->Enet_paCtrlRxRingConfig[i].RingDesc;
        Config->Enet_pCtrlState->RxBdBase[i]      = Config->Enet_paCtrlRxRingConfig[i].RingDesc;
        Config->Enet_pCtrlState->RxBuffNums[i]    = Config->Enet_paCtrlRxRingConfig[i].RingSize;
        Config->Enet_pCtrlState->RxBuffLen[i]     = Config->Enet_paCtrlRxRingConfig[i].BufferLen;
        Config->Enet_pCtrlState->RxDataBuffer[i]  = Config->Enet_paCtrlRxRingConfig[i].Buffer;
    }
    for (i = 0; i < Config->Enet_pCtrlConfig->TxRingCount; i++)
    {
        Config->Enet_pCtrlState->TxChCallback[i]  = Config->Enet_paCtrlTxRingConfig[i].Callback;
        Config->Enet_pCtrlState->TxCurrentDesc[i] = Config->Enet_paCtrlTxRingConfig[i].RingDesc;
        Config->Enet_pCtrlState->TxTransmitDesc[i] = Config->Enet_paCtrlTxRingConfig[i].RingDesc;
        Config->Enet_pCtrlState->TxBdBase[i]      = Config->Enet_paCtrlTxRingConfig[i].RingDesc;
        Config->Enet_pCtrlState->TxBuffNums[i]    = Config->Enet_paCtrlTxRingConfig[i].RingSize;
        Config->Enet_pCtrlState->TxBuffLen[i]     = Config->Enet_paCtrlTxRingConfig[i].BufferLen;
        Config->Enet_pCtrlState->TxDataBuffer[i]  = Config->Enet_paCtrlTxRingConfig[i].Buffer;
    }
    
    Enet_apxState[Instance] = Config->Enet_pCtrlState;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_InitStateStruct
 * Description   : Initialize register's value to control transmit and receive.
 *END**************************************************************************/
static void Enet_Ip_InitRegCtrl(ENET_Type * Base, 
                                const Enet_CtrlConfigType *Config
                                )
{
    Base->RCR = Config->Enet_pCtrlConfig->RxConfig;
    Base->RCR |= ENET_RCR_RMII_MODE((Config->Enet_pCtrlConfig->MiiMode == ENET_RMII_MODE) ? 1UL : 0UL);
    Base->RCR |= ENET_RCR_MII_MODE(1U);
    Base->RCR |= ENET_RCR_RMII_10T((Config->Enet_pCtrlConfig->MiiSpeed == ENET_MII_SPEED_10M) ? 1UL : 0UL);
    if (Config->Enet_pCtrlConfig->MiiDuplex == ENET_MII_HALF_DUPLEX)
    {
        Base->RCR |= ENET_RCR_DRT(1U);
    }
    
    if ((Config->Enet_pCtrlConfig->RxConfig & ((uint32)ENET_RCR_LOOP_MASK)) != 0U)
    {
        Base->RCR &= ~ENET_RCR_DRT_MASK;
    }
    Base->RCR |= ENET_RCR_MAX_FL(Config->Enet_pCtrlConfig->MaxFameLen);
    
    Base->TCR = Config->Enet_pCtrlConfig->TxConfig;
    if (Config->Enet_pCtrlConfig->MiiDuplex == ENET_MII_FULL_DUPLEX)
    {
        Base->TCR |= ENET_TCR_FDEN_MASK;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_ReadTimerValue
 * Description   : Read timer in nanoseconds
 *END**************************************************************************/
static uint32 Enet_Ip_ReadTimerValue(uint8 Instance)
{
    ENET_Type *Base;
    uint32 u32Capture;
    uint32 StartTime; 
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    
    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    
    Base = Enet_apxBases[Instance];
    
    Base->ATCR |= ENET_ATCR_CAPTURE_MASK;
    
    /* Wait for completion */
    ENET_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, ENET_TIMEOUT_VALUE_US);
    
    do
    {
        if (0U == (Base->ATCR & ENET_ATCR_CAPTURE_MASK))
        {
            break;
        }
    }
    while (!ENET_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));
   
    u32Capture = Base->ATVR;

    return u32Capture;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_Reset
 * Description   : Ethernet MAC reset.
 *
 *END**************************************************************************/
static void Enet_Ip_Reset(ENET_Type *Base)
{
    Base->ECR = ENET_ECR_RESET_MASK;
    
    Base->ECR |= ENET_ECR_DBSWP_MASK;
    
    Base->ECR |= ENET_ECR_EN1588_MASK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_ConfigReceiveAccelerator
 * Description   : Configures receive accelerator functions..
 *
 *END**************************************************************************/
static void Enet_Ip_ConfigReceiveAccelerator(ENET_Type * Base,
                                             uint32 RxAccelerConfig)
{
    Base->RACC = RxAccelerConfig;

    /* Enable store and forward when accelerator is enabled */
    if ((RxAccelerConfig & ((uint32)ENET_RX_ACCEL_ENABLE_IP_CHECK | (uint32)ENET_RX_ACCEL_ENABLE_PROTO_CHECK)) != 0U)
    {
        Base->RSFL = 0;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_GetTimeStamp
 * Description   : Gets the TimeStamp from a buffer descriptor
 *
 *END**************************************************************************/
static void Enet_Ip_GetTimeStamp(uint8 Instance,
                                 const Enet_Ip_BufferDescriptorType * Bd,
                                 Enet_Ip_TimeStampType * TimeStamp)
{
    uint32 BdTimeStamp;
    uint32 CurrTimeStamp;
    uint32 CurrSeconds;
    uint16 CurrSecondsHi;
    
    /* Reading Time stamp from Buffer Descriptor */
    BdTimeStamp = Bd->TimeStamp;
    
    /* Store current time for preventing timer-wrap event occurred */
    CurrSeconds = Enet_axLocalTime[Instance].seconds;
    CurrSecondsHi = Enet_axLocalTime[Instance].secondsHi;
    
    CurrTimeStamp = Enet_Ip_ReadTimerValue(Instance);
    
    /* Wrap was occurred before buffer was TimeStamps. */
    if (CurrTimeStamp > BdTimeStamp)
    {
        TimeStamp->seconds = CurrSeconds;
        TimeStamp->secondsHi = CurrSecondsHi;
    }
    else
    {
        CurrSeconds = Enet_axLocalTime[Instance].seconds;
        CurrSecondsHi = Enet_axLocalTime[Instance].secondsHi;
        
        if (0U == CurrSeconds)
        {
            CurrSecondsHi--;
            CurrSeconds = 0xFFFFFFFFU;
        }
        else
        {
            CurrSeconds--;
        }
        TimeStamp->secondsHi = CurrSecondsHi;
        TimeStamp->seconds = CurrSeconds;
    }
    
    TimeStamp->nanoseconds = BdTimeStamp;
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_ConfigTransmitAccelerator
 * Description   : Configures transmit accelerator functions.
 *
 *END**************************************************************************/
static inline void Enet_Ip_ConfigTransmitAccelerator(ENET_Type * Base,
                                                     uint32 TxAccelerConfig)
{
    Base->TACC = TxAccelerConfig;

    /* Enable store and forward when accelerator is enabled */
    if (((uint32)TxAccelerConfig & ((uint32)ENET_TX_ACCEL_INSERT_IP_CHECKSUM | (uint32)ENET_TX_ACCEL_INSERT_PROTO_CHECKSUM)) != 0U)
    {
        Base->TFWR = ENET_TFWR_STRFWD_MASK;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_SetTxBufferDescriptors
 * Description   : Configures the software transmit buffer descriptors.
 *
 *END**************************************************************************/
static void Enet_Ip_SetTxBufferDescriptors(
                                            ENET_Type * Base,
                                            const Enet_CtrlConfigType *Config,
                                            const Enet_Ip_BufferConfigType TxRingConfig[]
                                            )
{
    uint8 i;
    uint16 j;
    
    for (i = 0U; i < Config->Enet_pCtrlConfig->TxRingCount; i++)
    {
        for (j = 0U; j < Config->Enet_paCtrlTxRingConfig[i].RingSize; j++)
        {
            TxRingConfig[i].RingDesc[j].Length = TxRingConfig[i].BufferLen & ENET_BD_LENGTH_MASK;
            TxRingConfig[i].RingDesc[j].Control = 0U;
            TxRingConfig[i].RingDesc[j].Buffer = (TxRingConfig[i].Buffer != NULL_PTR)? (&TxRingConfig[i].Buffer[TxRingConfig[i].BufferLen * j]) : NULL_PTR;
            TxRingConfig[i].RingDesc[j].Enh1 = ENET_TX_ENH1_INT_MASK;
            TxRingConfig[i].RingDesc[j].Enh2 = 0U;
            TxRingConfig[i].RingDesc[j].Enh3 = 0U;
            TxRingConfig[i].RingDesc[j].TimeStamp = 0U;
            TxRingConfig[i].RingDesc[j].Reserved1 = 0U;
            TxRingConfig[i].RingDesc[j].Reserved2 = 0U;
            if (j == (Config->Enet_paCtrlTxRingConfig[i].RingSize - 1U))
            {
                TxRingConfig[i].RingDesc[j].Control |= ENET_BUFFDESCR_TX_WRAP_MASK;
            }
        }
        
        /* Initialize start address of Buffer descriptor for queue 0. Because SoC just support only one queue */
        Base->TDSR = (uint32)Config->Enet_paCtrlTxRingConfig[i].RingDesc;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_SetRxBufferDescriptors
 * Description   : Configures the software transmit buffer descriptors.
 *
 *END**************************************************************************/
static void Enet_Ip_SetRxBufferDescriptors(
                                            ENET_Type * Base,
                                            const Enet_CtrlConfigType *Config,
                                            const Enet_Ip_BufferConfigType RxRingConfig[]
                                            )
{
    uint8 i; 
    uint16 j;
    
    for (i = 0U; i < Config->Enet_pCtrlConfig->RxRingCount; i++)
    {
        for (j = 0U; j < Config->Enet_paCtrlRxRingConfig[i].RingSize; j++)
        {
            RxRingConfig[i].RingDesc[j].Length = 0U;
            RxRingConfig[i].RingDesc[j].Control = (RxRingConfig[i].Buffer != NULL_PTR)? ENET_BUFFDESCR_RX_EMPTY_MASK : 0U;
            RxRingConfig[i].RingDesc[j].Buffer = (RxRingConfig[i].Buffer != NULL_PTR)? (&RxRingConfig[i].Buffer[RxRingConfig[i].BufferLen * j]) : NULL_PTR;
            if ((uint32)ENET_RX_FRAME_INTERRUPT == (Config->Enet_paCtrlRxRingConfig[i].Interrupts & (uint32)ENET_RX_FRAME_INTERRUPT))
            {
                RxRingConfig[i].RingDesc[j].Enh1 = ENET_RX_ENH1_INT_MASK;
            }
            RxRingConfig[i].RingDesc[j].Enh2 = 0U;
            RxRingConfig[i].RingDesc[j].Enh3 = 0U;
            RxRingConfig[i].RingDesc[j].TimeStamp = 0U;
            RxRingConfig[i].RingDesc[j].Reserved1 = 0U;
            RxRingConfig[i].RingDesc[j].Reserved2 = 0U;
            if (j == (Config->Enet_paCtrlRxRingConfig[i].RingSize - 1U))
            {
                RxRingConfig[i].RingDesc[j].Control |= ENET_BUFFDESCR_RX_WRAP_MASK;
            }
        }
        
        /* Initialize start address of Buffer descriptor for queue 0. Because SoC just support only one queue */
        Base->RDSR = (uint32)Config->Enet_paCtrlRxRingConfig[i].RingDesc;
        
        /*Initialize buffer length for Rx*/
        Base->MRBR = Config->Enet_paCtrlRxRingConfig[i].BufferLen;
    }
}
/*******************************************************************************
 * Code
 ******************************************************************************/

#if (STD_ON == ENET_SET_USER_ACCESS_ALLOWED_AVAILABLE)                                            
/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_SetUserAccessAllowed
 * Description   : Sets the UAA bit in REG_PROT to make the Instance accessible in user mode.
 *
 *END**************************************************************************/
void Enet_Ip_SetUserAccessAllowed(const ENET_Type *Base)
{
    SET_USER_ACCESS_ALLOWED((uint32)Base, ENET_PROT_MEM_U32);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_ClrUserAccessAllowed
 * Description   : Clears the UAA bit in REG_PROT to make the instance unaccessible in user mode.
 *
 *END**************************************************************************/
void Enet_Ip_ClrUserAccessAllowed(const ENET_Type *Base)
{
    CLR_USER_ACCESS_ALLOWED((uint32)Base, ENET_PROT_MEM_U32);
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_Init
 * Description   : Initializes the ENET module
 * implements     Enet_Ip_Init_Activity 
 *END**************************************************************************/
void Enet_Ip_Init(uint8 Instance,
                    const Enet_CtrlConfigType *Config)
{
    ENET_Type *Base;
    uint32 i;
    uint32 TxPoolSize = 0U;
    uint32 RxPoolSize = 0U;
    
    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(Config                          != NULL_PTR);
    ENET_DEV_ASSERT(Config->Enet_pCtrlState         != NULL_PTR);
    ENET_DEV_ASSERT(Config->Enet_pCtrlConfig        != NULL_PTR);
    ENET_DEV_ASSERT(Config->Enet_paCtrlRxRingConfig != NULL_PTR);
    ENET_DEV_ASSERT(Config->Enet_paCtrlTxRingConfig != NULL_PTR);
    ENET_DEV_ASSERT(Config->Enet_pau8CtrlPhysAddr   != NULL_PTR);
    ENET_DEV_ASSERT((Config->Enet_pCtrlConfig->RxRingCount > 0U) && (Config->Enet_pCtrlConfig->RxRingCount <= FEATURE_ENET_NUM_RINGS));
    ENET_DEV_ASSERT((Config->Enet_pCtrlConfig->TxRingCount > 0U) && (Config->Enet_pCtrlConfig->TxRingCount <= FEATURE_ENET_NUM_RINGS));

    for (i = 0U; i < Config->Enet_pCtrlConfig->RxRingCount; ++i)
    {
#if (ENET_DEV_ERROR_DETECT == STD_ON)
        ENET_DEV_ASSERT(Config->Enet_paCtrlRxRingConfig[i].RingDesc != NULL_PTR);
        ENET_DEV_ASSERT(Config->Enet_paCtrlRxRingConfig[i].RingSize > 0U);
        ENET_DEV_ASSERT(ENET_BUFFDESCR_IS_ALIGNED((uint32)Config->Enet_paCtrlRxRingConfig[i].RingDesc));
        ENET_DEV_ASSERT((Config->Enet_paCtrlRxRingConfig[i].Buffer == NULL_PTR) || ENET_BUFF_IS_ALIGNED(Config->Enet_paCtrlRxRingConfig[i].Buffer));
        ENET_DEV_ASSERT(ENET_BUFFLEN_IS_ALIGNED((uint32)Config->Enet_paCtrlRxRingConfig[i].BufferLen));
#endif        
        RxPoolSize += ((uint32)Config->Enet_paCtrlRxRingConfig[i].RingSize * Config->Enet_paCtrlRxRingConfig[i].BufferLen);
    }
    
#if (ENET_DEV_ERROR_DETECT == STD_ON)   
    ENET_DEV_ASSERT(RxPoolSize <= FEATURE_ENET_RX_POOL_SIZE);
#endif     

    for (i = 0U; i < Config->Enet_pCtrlConfig->TxRingCount; ++i)
    {
#if (ENET_DEV_ERROR_DETECT == STD_ON)
        ENET_DEV_ASSERT(Config->Enet_paCtrlTxRingConfig[i].RingDesc != NULL_PTR);
        ENET_DEV_ASSERT(Config->Enet_paCtrlTxRingConfig[i].RingSize > 0U);
        ENET_DEV_ASSERT(ENET_BUFFDESCR_IS_ALIGNED((uint32)Config->Enet_paCtrlTxRingConfig[i].RingDesc));
        ENET_DEV_ASSERT((Config->Enet_paCtrlTxRingConfig[i].Buffer == NULL_PTR) || ENET_BUFF_IS_ALIGNED(Config->Enet_paCtrlTxRingConfig[i].Buffer));
        ENET_DEV_ASSERT(ENET_BUFFLEN_IS_ALIGNED((uint32)Config->Enet_paCtrlTxRingConfig[i].BufferLen));
#endif        
        TxPoolSize += ((uint32)Config->Enet_paCtrlTxRingConfig[i].RingSize * Config->Enet_paCtrlTxRingConfig[i].BufferLen);
    }
#if (ENET_DEV_ERROR_DETECT == STD_ON)    
    ENET_DEV_ASSERT(TxPoolSize <= FEATURE_ENET_TX_POOL_SIZE);
#endif

    Base = Enet_apxBases[Instance];

    Enet_Ip_Reset(Base);
   
#if (STD_ON == ENET_SET_USER_ACCESS_ALLOWED_AVAILABLE)
    /* Set the UAA bit in REG_PROT to make the Instance accessible in user mode */
    OsIf_Trusted_Call1param(Enet_Ip_SetUserAccessAllowed, Base);
#endif
    
    Enet_Ip_SetMacAddr(Instance, Config->Enet_pau8CtrlPhysAddr);
    
    /* Configure receive and transmit control. */
    Enet_Ip_InitRegCtrl(Base, Config);
    
    /* Configure Fifo registers */
    Base->RAEM = ENET_RAEM_RX_ALMOST_EMPTY(4U);
    
    RxPoolSize = FEATURE_ENET_RX_POOL_SIZE - (RxPoolSize / FEATURE_ENET_MTL_FIFO_BLOCK_SIZE);
    Base->RAFL = ENET_RAFL_RX_ALMOST_FULL(RxPoolSize);
    
    Base->TAEM = ENET_TAEM_TX_ALMOST_EMPTY(4U);
    
    TxPoolSize = TxPoolSize / FEATURE_ENET_MTL_FIFO_BLOCK_SIZE;
    Base->TAFL = ENET_TAFL_TX_ALMOST_FULL(TxPoolSize);
    
    /* Configure receive and transmit accelerators. */
    Enet_Ip_ConfigReceiveAccelerator(Base, (uint32)Config->Enet_pCtrlConfig->RxAccelerConfig);
    
    Enet_Ip_ConfigTransmitAccelerator(Base, (uint32)Config->Enet_pCtrlConfig->TxAccelerConfig);
    
    /* Enable Ethernet interrupts. */
    
    /* Configure Transmit Ring*/
    Enet_Ip_SetTxBufferDescriptors(Base, Config, Config->Enet_paCtrlTxRingConfig);
    
    /* Configure Receive Ring*/
    Enet_Ip_SetRxBufferDescriptors(Base, Config, Config->Enet_paCtrlRxRingConfig);
    
    /* Enable interrupts*/
    Base->EIMR = Config->Enet_pCtrlConfig->Interrupts;
    
    /* Initialize state structure. */
    Enet_Ip_InitStateStruct(Instance, Config);

    Enet_Ip_ConfigCounters(Instance, (boolean)TRUE);
    
    if (Config->Enet_pCtrlConfig->EnableCtrl)
    {
        /* Enable Ethernet module*/
        Base->ECR |= ((uint32)ENET_ECR_ETHEREN_MASK | ENET_ECR_DBSWP_MASK);
        Base->ECR |= ((uint32)1U << ENET_ECR_EN1588_SHIFT);
        
        /*Active transmit and Receive*/
        Base->TDAR |= ENET_TDAR_TDAR_MASK;
        Base->RDAR |= ENET_RDAR_RDAR_MASK;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_EnableTxStoreAndForward
 * Description   : Enables the store and forward feature on the transmit path.
 *
 * implements     Enet_Ip_EnableTxStoreAndForward_Activity
 *END**************************************************************************/
void Enet_Ip_EnableTxStoreAndForward(uint8 Instance)
{
    ENET_Type *Base;

    ENET_DEV_ASSERT(Instance < FEATURE_ENET_NUM_INSTANCES);

    Base = Enet_apxBases[Instance];

    Base->TFWR |= ENET_TFWR_STRFWD_MASK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_SetFIFOThreshold
 * Description   : Sets FIFO threshold levels.
 *
 * implements     Enet_Ip_SetFIFOThreshold_Activity
 *END**************************************************************************/
void Enet_Ip_SetFIFOThreshold(uint8 Instance,
                              Enet_Ip_FifoThresholdType ThresholdType,
                              uint8 ThresholdValue)
{

    const ENET_Type *Base;
    volatile uint32 ThresholdAddr;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);

    Base = Enet_apxBases[Instance];
    
    ThresholdAddr = (uint32)(&(Base->RSFL));

    ENET_THRESHOLD_REG_WRITE(ThresholdAddr, ThresholdType, ThresholdValue);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_SetTxFIFOWatermark
 * Description   : Sets the transmit FIFO watermark.
 *
 * implements     Enet_Ip_SetTxFIFOWatermark_Activity
 *END**************************************************************************/
void Enet_Ip_SetTxFIFOWatermark(uint8 Instance,
                                uint16 Watermark)
{
    ENET_Type *Base;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);

    Base = Enet_apxBases[Instance];

    Base->TFWR = ENET_TFWR_TFWR(Watermark);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_GetPowerState
 * Description   : Gets the current power state of the ENET module
 * implements     Enet_Ip_GetPowerState_Activity
 *END**************************************************************************/
Enet_Ip_PowerStateType Enet_Ip_GetPowerState(uint8 Instance)
{
    const ENET_Type *Base;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);

    Base = Enet_apxBases[Instance];
    
    return ENET_GetPowerState(Base);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_GetMacAddr
 * Description   : Gets the physical address of the MAC
 * implements     Enet_Ip_GetMacAddr_Activity
 *END**************************************************************************/
void Enet_Ip_GetMacAddr(uint8 Instance,
                        uint8 *MacAddr)
{
    const ENET_Type *Base;
    uint32 Address;
    
    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(MacAddr != NULL_PTR);
    
    Base = Enet_apxBases[Instance];
    
    /* Get from physical address lower register. */
    Address = Base->PALR;
    MacAddr[0] = (uint8)(MAC_BYTE_MASK & (Address >> ENET_BYTE_0_IN_ADDR_SHIFT));
    MacAddr[1] = (uint8)(MAC_BYTE_MASK & (Address >> ENET_BYTE_1_IN_ADDR_SHIFT));
    MacAddr[2] = (uint8)(MAC_BYTE_MASK & (Address >> ENET_BYTE_2_IN_ADDR_SHIFT));
    MacAddr[3] = (uint8)(MAC_BYTE_MASK & (Address >> ENET_BYTE_3_IN_ADDR_SHIFT));
    
    /* Get from physical Address high register. */
    Address = Base->PAUR & ENET_PAUR_PADDR2_MASK;
    MacAddr[4] = (uint8)(MAC_BYTE_MASK & (Address >> ENET_BYTE_4_IN_ADDR_SHIFT));
    MacAddr[5] = (uint8)(MAC_BYTE_MASK & (Address >> ENET_BYTE_5_IN_ADDR_SHIFT));
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_SetMacAddr
 * Description   : Configures the physical Address of the MAC
 * implements     Enet_Ip_SetMacAddr_Activity
 *END**************************************************************************/
void Enet_Ip_SetMacAddr(uint8 Instance,
                        const uint8 *MacAddr)
{
    uint32 Address;
    ENET_Type *Base;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(MacAddr != NULL_PTR);

    Base = Enet_apxBases[Instance];

    /* Set physical Address high register. */
    Base->PAUR = ((uint32)MacAddr[5] << ENET_BYTE_5_IN_ADDR_SHIFT) |
                              ((uint32)MacAddr[4] << ENET_BYTE_4_IN_ADDR_SHIFT) |
                              ENET_PAUR_TYPE_VALUE;

    /* Set physical Address lower register. */
    Address = ((uint32)MacAddr[3] << ENET_BYTE_3_IN_ADDR_SHIFT) |
              ((uint32)MacAddr[2] << ENET_BYTE_2_IN_ADDR_SHIFT) |
              ((uint32)MacAddr[1] << ENET_BYTE_1_IN_ADDR_SHIFT) |
              ((uint32)MacAddr[0] << ENET_BYTE_0_IN_ADDR_SHIFT);
    Base->PALR = Address;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_EnableController
 * Description   : Enables all Configured transmit and receive buffers and then enables the controller
 *END**************************************************************************/
void Enet_Ip_EnableController(uint8 Instance)
{
    ENET_Type *Base;
    
    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    
    Base = Enet_apxBases[Instance];
    
    Base->ECR |= ((uint32)ENET_ECR_ETHEREN_MASK | ENET_ECR_DBSWP_MASK);
    Base->ECR |= ((uint32)1U << ENET_ECR_EN1588_SHIFT);
    
    /*Active transmit and Receive*/
    Base->TDAR |= ENET_TDAR_TDAR_MASK;
    Base->RDAR |= ENET_RDAR_RDAR_MASK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_DisableController
 * Description   : Disables the controller and resets all the Configured transmit and receive buffers
 *END**************************************************************************/
void Enet_Ip_DisableController(uint8 Instance)
{
    ENET_Type *Base;
    Enet_Ip_BufferDescriptorType *ListBd;
    uint8 i; 
    uint16 j;
    
    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    
    Base = Enet_apxBases[Instance];
    
    /* Disable controller */
    Base->ECR &= ~ENET_ECR_ETHEREN_MASK;
    
    /* Restore all Tx buffer addresses, clear all pending Tx requests and unlock all Tx buffers */
    for (i = 0U; i < Enet_apxState[Instance]->TxRingCount; i++)
    {
        ListBd = Enet_apxState[Instance]->TxBdBase[i];
        /* Reset current address to base address */
        Enet_apxState[Instance]->TxTransmitDesc[i] = Enet_apxState[Instance]->TxBdBase[i];
        Enet_apxState[Instance]->TxCurrentDesc[i] = Enet_apxState[Instance]->TxBdBase[i];
        
        for (j = 0U; j < Enet_apxState[Instance]->TxBuffNums[i]; ++j)
        {
            ListBd[j].Control  &= ~((uint16)ENET_BUFFDESCR_TX_READY_MASK | (uint16)ENET_BUFFDESCR_TX_LOCKED_MASK);
            ListBd[j].Buffer = (Enet_apxState[Instance]->TxDataBuffer[i] != NULL_PTR)? (&Enet_apxState[Instance]->TxDataBuffer[i][Enet_apxState[Instance]->TxBuffLen[i] * j]) : NULL_PTR;
        }
        if (j == (Enet_apxState[Instance]->TxBuffNums[i] - 1U))
        {
            ListBd[j].Control |= ENET_BUFFDESCR_TX_WRAP_MASK;
        }
        
        /* Initialize start address of Buffer descriptor for queue 0. Because SoC just support only one queue */
        Base->TDSR = (uint32)ListBd;
    }
    
    
    /* Restore all Rx buffer addreses and clear all pending Rx requests */
    for (i = 0U; i < Enet_apxState[Instance]->RxRingCount; i++)
    {
        ListBd = Enet_apxState[Instance]->RxBdBase[i];
        
        /* Reset current address to base address */
        Enet_apxState[Instance]->RxCurrentDesc[i] = Enet_apxState[Instance]->RxBdBase[i];
        Enet_apxState[Instance]->RxBdAlloc[i]     = Enet_apxState[Instance]->RxBdBase[i]; 
        
        for (j = 0U; j < Enet_apxState[Instance]->RxBuffNums[i]; ++j)
        {
            ListBd[j].Control = (Enet_apxState[Instance]->RxDataBuffer[i] != NULL_PTR)? (uint16)ENET_BUFFDESCR_RX_EMPTY_MASK : 0U;
            ListBd[j].Buffer = (Enet_apxState[Instance]->RxDataBuffer[i] != NULL_PTR)? (&Enet_apxState[Instance]->RxDataBuffer[i][Enet_apxState[Instance]->RxBuffLen[i] * j]) : NULL_PTR;
            ListBd[j].Enh1 = ENET_RX_ENH1_INT_MASK; 
            ListBd[j].Control &= ~(uint16)ENET_BUFFDESCR_RX_CONSUMED_MASK;
        }
        if (j == (Enet_apxState[Instance]->RxBuffNums[i] - 1U))
        {
            ListBd[j].Control |= (uint16)ENET_BUFFDESCR_RX_WRAP_MASK;
        }
        
        /* Initialize start address of Buffer descriptor for queue 0. Because SoC just support only one queue */
        Base->RDSR = (uint32)ListBd;
        
        /* Restore Rx buffer length */ 
        Base->MRBR = (uint32)Enet_apxState[Instance]->RxBuffLen[i];
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_Deinit
 * Description   : Deinitializes the ENET module
 * implements     Enet_Ip_Deinit_Activity
 *END**************************************************************************/
void Enet_Ip_Deinit(uint8 Instance)
{
    ENET_Type *Base;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);

    Base = Enet_apxBases[Instance];
    
    /* Disable ethernet */
    Base->ECR &= ~ENET_ECR_ETHEREN_MASK;

#if (STD_ON == ENET_SET_USER_ACCESS_ALLOWED_AVAILABLE)
    /* Clear the UAA bit in REG_PROT to reset the elevation requirement */
    OsIf_Trusted_Call1param(Enet_Ip_ClrUserAccessAllowed, Base);
#endif

    /* Reset state variables */
    Enet_apxState[Instance] = NULL_PTR;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_SetSpeed
 * Description   : Sets the speed of the MII interface
 * implements     Enet_Ip_SetSpeed_Activity
 *END**************************************************************************/
void Enet_Ip_SetSpeed(uint8 Instance, Enet_Ip_MiiSpeedType Speed)
{
    ENET_Type *Base;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);

    Base = Enet_apxBases[Instance];
    ENET_SetSpeed(Base, Speed);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_GetTxBuff
 * Description   : Provides a transmit buffer to be used by the application for transmission.
 *END**************************************************************************/
Enet_Ip_StatusType Enet_Ip_GetTxBuff(uint8 Instance,
                                     uint8 Ring,
                                     Enet_Ip_BufferType * Buff,
                                     uint16 * BuffId)
{
    Enet_Ip_BufferDescriptorType *Bd;
    Enet_Ip_StatusType Status = ENET_STATUS_SUCCESS;
    uint8* BufAddr;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(Enet_apxState[Instance] != NULL_PTR);
    ENET_DEV_ASSERT(Ring < Enet_apxState[Instance]->TxRingCount);
    ENET_DEV_ASSERT(Buff != NULL_PTR);
    
    /* Get current descriptor buffer address */
    Bd = Enet_apxState[Instance]->TxCurrentDesc[Ring];
    /* Get base data buffer address */
    BufAddr = Enet_apxState[Instance]->TxDataBuffer[Ring];
    
    if (((Bd->Control & ENET_BUFFDESCR_TX_READY_MASK) != 0U) ||
        ((Bd->Control & ENET_BUFFDESCR_TX_LOCKED_MASK) != 0U))
    {
        Status = ENET_STATUS_TX_BUFF_BUSY;
    }
    else
    {
        if (Buff->Length > (Enet_apxState[Instance]->TxBuffLen[Ring]))
        {
            Status = ENET_STATUS_TX_BUFF_OVERFLOW;
            Buff->Length = Enet_apxState[Instance]->TxBuffLen[Ring];
        }
        else
        {
            if (BuffId != NULL_PTR)
            {
                *BuffId = (uint16)((sint32)(Bd - Enet_apxState[Instance]->TxBdBase[Ring]));
            }
            
            Buff->Length = Enet_apxState[Instance]->TxBuffLen[Ring];
            
            /* According to the requirement CPR_RTD_00286.eth */
            /* Relies on function "Enet_Ip_GetTransmitStatus" to restore the buffer address pointer */
            Buff->Data   =  &BufAddr[Enet_apxState[Instance]->TxBuffLen[Ring] * (uint16)((sint32)(Bd - Enet_apxState[Instance]->TxBdBase[Ring]))];
            
            Bd->Control |= ENET_BUFFDESCR_TX_LOCKED_MASK;

            if (ENET_BUFFDESCR_TX_WRAP_MASK == (Bd->Control & ENET_BUFFDESCR_TX_WRAP_MASK))
            {
                Enet_apxState[Instance]->TxCurrentDesc[Ring] = Enet_apxState[Instance]->TxBdBase[Ring];
            }
            else
            {
                ++Bd;
                Enet_apxState[Instance]->TxCurrentDesc[Ring] = Bd;
            }
        }
    }
    
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_SendFrame
 * Description   : Sends an Ethernet frame
 * implements     Enet_Ip_SendFrame_Activity
 *END**************************************************************************/
Enet_Ip_StatusType Enet_Ip_SendFrame(uint8 Instance,
                                     uint8 Ring,
                                     const Enet_Ip_BufferType * Buff,
                                     const Enet_Ip_TxOptionsType * Options)
{
    ENET_Type *Base;
    Enet_Ip_BufferDescriptorType *Bd;
    Enet_Ip_StatusType Status = ENET_STATUS_SUCCESS;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(Enet_apxState[Instance] != NULL_PTR);
    ENET_DEV_ASSERT(Ring < Enet_apxState[Instance]->TxRingCount);
    ENET_DEV_ASSERT(Buff != NULL_PTR);

    Base = Enet_apxBases[Instance];

    Bd = Enet_apxState[Instance]->TxTransmitDesc[Ring];

    if ((Bd->Control & ENET_BUFFDESCR_TX_READY_MASK) != 0U)
    {
        Status = ENET_STATUS_TX_QUEUE_FULL;
    }
    else
    {
        Bd->Buffer = Buff->Data;
        Bd->Length = Buff->Length;
        Bd->Control |= (uint16)(ENET_BUFFDESCR_TX_READY_MASK | ENET_BUFFDESCR_TX_LAST_MASK | ENET_BUFFDESCR_TX_TRANSMITCRC_MASK);
        Bd->Enh1 |= ENET_TX_ENH1_INT_MASK;

        if (Options != NULL_PTR)
        {
            if (Options->NoInt)
            {
                Bd->Enh1 &= ~ENET_TX_ENH1_INT_MASK;
            }
            if (Options->NoCRC)
            {
                Bd->Control &= ~(uint16)ENET_BUFFDESCR_TX_TRANSMITCRC_MASK;
            }
            Bd->Enh1 |= ENET_ENH1_CPC(Options->ChecksumIns);
        }
        
        if (0U != (Base->ATCR & ENET_ATCR_EN_MASK))
        {
            Bd->Enh1 |= ENET_TX_ENH1_TS_MASK;
        }
        
        ENET_ActivateTransmit(Base, Ring);
        
        if (ENET_BUFFDESCR_TX_WRAP_MASK == (Bd->Control & ENET_BUFFDESCR_TX_WRAP_MASK))
        {
            Enet_apxState[Instance]->TxTransmitDesc[Ring] = Enet_apxState[Instance]->TxBdBase[Ring];
        }
        else
        {
            ++Bd;
            Enet_apxState[Instance]->TxTransmitDesc[Ring] = Bd;
        }
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_ReadFrame
 * Description   : Reads a received Ethernet frame
 * implements     Enet_Ip_ReadFrame_Activity
 *END**************************************************************************/
Enet_Ip_StatusType Enet_Ip_ReadFrame(uint8 Instance,
                                     uint8 Ring,
                                     Enet_Ip_BufferType * Buff,
                                     Enet_Ip_RxInfoType * Info)
{
    Enet_Ip_BufferDescriptorType *Bd;
    Enet_Ip_StatusType Status = ENET_STATUS_SUCCESS;
    uint16 BufIdx;
    uint8 *BufData;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(Enet_apxState[Instance] != NULL_PTR);
    ENET_DEV_ASSERT(Ring < Enet_apxState[Instance]->RxRingCount);
    ENET_DEV_ASSERT(Buff != NULL_PTR);
    
    /* Get current BD adress */
    Bd = Enet_apxState[Instance]->RxCurrentDesc[Ring];
    /* Get base data buffer address*/
    BufData = Enet_apxState[Instance]->RxDataBuffer[Ring];
    
    if (((Bd->Control & ENET_BUFFDESCR_RX_EMPTY_MASK) != 0U) ||
        ((Bd->Control & ENET_BUFFDESCR_RX_CONSUMED_MASK) != 0U))
    {
        Status = ENET_STATUS_RX_QUEUE_EMPTY;
    }
    else
    {
        BufIdx = (uint16)((sint32)(Bd - Enet_apxState[Instance]->RxBdBase[Ring]));
        /* According to the requirement CPR_RTD_00286.eth */
        Buff->Data = &BufData[Enet_apxState[Instance]->RxBuffLen[Ring] * BufIdx];
        Buff->Length = Bd->Length;
        #ifdef MCAL_ENABLE_FAULT_INJECTION
            MCAL_FAULT_INJECTION_POINT(ETH_CHANGE_BUffER_LENGTH_FIP_1);
        #endif
        /* The length must be incorrect, it is greater than maximal allowed length */
        /* According to the requirement CPR_RTD_00284.eth, Return maximal length instead */
        if (Buff->Length > Enet_apxState[Instance]->RxBuffLen[Ring])
        {
            Buff->Length = Enet_apxState[Instance]->RxBuffLen[Ring];
        }
        Bd->Control |= ENET_BUFFDESCR_RX_CONSUMED_MASK;

        if (Info != NULL_PTR)
        {
            Info->ErrMask = (uint32)((uint32)Bd->Control & ENET_BUFFDESCR_RX_CTRL_ERR_MASK);
            Info->ErrMask |= (Bd->Enh1 & ENET_RX_ENH_ERR_MASK);
            Info->Ipv4Frag = ((Bd->Enh1 & ENET_RX_ENH1_FRAG_MASK) != 0UL);
            Info->Ipv6 = ((Bd->Enh1 & ENET_RX_ENH1_IPV6_MASK) != 0UL);
            Info->Unicast = ((Bd->Enh1 & ENET_RX_ENH1_UNICAST_MASK) != 0UL);
            Info->VlanPrio = (uint8)((Bd->Enh1 & ENET_RX_ENH1_VPCP_MASK) >> ENET_RX_ENH1_VPCP_SHIFT);
            Info->Checksum = (uint16)((Bd->Enh2 & ENET_RX_ENH2_CSUM_MASK));
            Info->HeaderLen = (uint8)((Bd->Enh2 & ENET_RX_ENH2_HLEN_MASK) >> ENET_RX_ENH2_HLEN_SHIFT);
            Info->Proto = (uint8)((Bd->Enh2 & ENET_RX_ENH2_PROTO_MASK) >> ENET_RX_ENH2_PROTO_SHIFT);
            Info->PktLen = Bd->Length;
            if (Bd->TimeStamp != 0U)
            {
                Enet_Ip_GetTimeStamp(Instance, Bd, &Info->TimeStamp);
            }
            else
            {
                Info->TimeStamp.nanoseconds = 0U;
                Info->TimeStamp.seconds = 0U;
                Info->TimeStamp.secondsHi = 0U;
            }
        }

        /* Update the current buffer descriptor. */
        if (ENET_BUFFDESCR_RX_WRAP_MASK == (Bd->Control & ENET_BUFFDESCR_RX_WRAP_MASK))
        {
            Enet_apxState[Instance]->RxCurrentDesc[Ring] = Enet_apxState[Instance]->RxBdBase[Ring];
        }
        else
        {
            ++Bd;
            Enet_apxState[Instance]->RxCurrentDesc[Ring] = Bd;
        }
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_ProvideRxBuff
 * Description   : Provides a receive buffer to be used by the driver for reception.
 * implements     Enet_Ip_ProvideRxBuff_Activity 
 *END**************************************************************************/
void Enet_Ip_ProvideRxBuff(uint8 Instance,
                           uint8 Ring,
                           const Enet_Ip_BufferType * Buff)
{
    ENET_Type *Base = Enet_apxBases[Instance];
    Enet_Ip_BufferDescriptorType *Bd;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(Enet_apxState[Instance] != NULL_PTR);
    ENET_DEV_ASSERT(Ring < Enet_apxState[Instance]->RxRingCount);
    ENET_DEV_ASSERT(Buff != NULL_PTR);

    Bd = Enet_apxState[Instance]->RxBdAlloc[Ring];

    ENET_DEV_ASSERT((Bd->Control & ENET_BUFFDESCR_RX_EMPTY_MASK) == 0U);

    Bd->Buffer = Buff->Data;
    
    Bd->Control &= ENET_BUFFDESCR_RX_WRAP_MASK;
    Bd->Control |= ENET_BUFFDESCR_RX_EMPTY_MASK;
    
    Bd->Enh1 &= ENET_TX_ENH1_INT_MASK;
    
    if (ENET_BUFFDESCR_RX_WRAP_MASK == (Bd->Control & ENET_BUFFDESCR_RX_WRAP_MASK))
    {
        Enet_apxState[Instance]->RxBdAlloc[Ring] = Enet_apxState[Instance]->RxBdBase[Ring];
    }
    else
    {
        ++Bd;
        Enet_apxState[Instance]->RxBdAlloc[Ring] = Bd;
    }
    
    /* New empty buffers have been produced */
    ENET_ActivateReceive(Base, Ring);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_IsFrameAvailable
 * Description   : Checks if there are more frames available in the given queue
 *END**************************************************************************/
boolean Enet_Ip_IsFrameAvailable(uint8 Instance,
                                 uint8 Ring)
{
    const Enet_Ip_BufferDescriptorType *Bd;
    boolean isFrameAvailable = FALSE;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(Enet_apxState[Instance] != NULL_PTR);
    ENET_DEV_ASSERT(Ring < Enet_apxState[Instance]->RxRingCount);

    Bd = Enet_apxState[Instance]->RxCurrentDesc[Ring];

    if (((Bd->Control & ENET_BUFFDESCR_RX_EMPTY_MASK) == 0U) &&
        ((Bd->Control & ENET_BUFFDESCR_RX_CONSUMED_MASK) == 0U))
    {
        isFrameAvailable = TRUE;
    }

    return isFrameAvailable;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_GetTransmitStatus
 * Description   : Checks if the transmission of a buffer is complete.
 * implements     Enet_Ip_GetTransmitStatus_Activity
 *END**************************************************************************/
Enet_Ip_StatusType Enet_Ip_GetTransmitStatus(uint8 Instance,
                                             uint8 Ring,
                                             const Enet_Ip_BufferType * Buff,
                                             Enet_Ip_TxInfoType * Info)
{
    Enet_Ip_BufferDescriptorType *Bd;
    Enet_Ip_StatusType Status = ENET_STATUS_BUFF_NOT_FOUND;
    uint32 i;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(Enet_apxState[Instance] != NULL_PTR);
    ENET_DEV_ASSERT(Ring < Enet_apxState[Instance]->TxRingCount);
    ENET_DEV_ASSERT(Buff != NULL_PTR);

    Bd = Enet_apxState[Instance]->TxBdBase[Ring];

    /* Search for the buffer descriptor associated with the given buffer. */
    for (i = 0; i < Enet_apxState[Instance]->TxBuffNums[Ring]; i++)
    {
        if (Bd->Buffer == Buff->Data)
        {
            /* Check if the buffer descriptor is still in use. */
            if ((Bd->Control & ENET_BUFFDESCR_TX_READY_MASK) != 0U)
            {
                Status = ENET_STATUS_BUSY;
            }
            else
            {
                Status = ENET_STATUS_SUCCESS;
                if (Info != NULL_PTR)
                {
                    Info->ErrMask = Bd->Enh1 & ENET_TX_ENH_ERR_MASK;
                    if ((Bd->Enh1 & ENET_TX_ENH1_TS_MASK) != 0U)
                    {
                        Enet_Ip_GetTimeStamp(Instance, Bd, &Info->TimeStamp);
                    }
                    else
                    {
                        Enet_axLocalTime[Instance].seconds = 0U;
                        Enet_axLocalTime[Instance].nanoseconds = 0U;
                        Enet_axLocalTime[Instance].secondsHi = 0U;
                    }
                }

                /* Clear lock flag after the status was read. */
                Bd->Control &= ~(uint16)ENET_BUFFDESCR_TX_LOCKED_MASK;
            }
            break;
        }
        Bd++;
    }

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_ConfigCounters
 * Description   : Enables/Disables the MIB counters
 * implements     Enet_Ip_ConfigCounters_Activity
 *END**************************************************************************/
void Enet_Ip_ConfigCounters(uint8 Instance,
                         boolean Enable)
{
    ENET_Type *base;
    
    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    
    base = Enet_apxBases[Instance];

    if (Enable)
    {
        /* Clear counters - MIB_CLEAR bit needs to be set, then cleared */
        base->MIBC |= ENET_MIBC_MIB_CLEAR_MASK;

        base->MIBC &= ~ENET_MIBC_MIB_CLEAR_MASK;

        base->MIBC &= ~ENET_MIBC_MIB_DIS_MASK;
    }
    else
    {
        base->MIBC |= ENET_MIBC_MIB_DIS_MASK;
    }
}
 
/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_GetCounter
 * Description   : Gets statistics from the specified counter.
 * implements     Enet_Ip_GetCounter_Activity
 *END**************************************************************************/
uint32 Enet_Ip_GetCounter(uint8 Instance,
                          Enet_Ip_CounterType Counter)
{
    const ENET_Type *Base;
    volatile uint32 RmonAdrr;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);

    Base = Enet_apxBases[Instance];
    RmonAdrr = (uint32)(&Base->RMON_T_DROP);
    
    return (ENET_RMON_REG_READ(RmonAdrr, Counter));
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_EnableMDIO
 * Description   : Enables the MDIO interface
 * implements     Enet_Ip_EnableMDIO_Activity
 *END**************************************************************************/
void Enet_Ip_EnableMDIO(uint8 Instance,
                         boolean MiiPreambleDisabled,
                         uint32 ModuleClk)
{
    ENET_Type *Base;
    uint32 HoldTime;
    uint32 MiiSpeed;
    
    ENET_DEV_ASSERT(Instance < FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(ModuleClk != 0U);

    Base = Enet_apxBases[Instance];

    HoldTime = ENET_ROUNDED_UP_DIV(ENET_MDIO_MIN_HOLD_TIME_NS * ModuleClk, ENET_NS_IN_SECOND) - 1U;
    MiiSpeed = ENET_ROUNDED_UP_DIV(ModuleClk/1000000U, (ENET_MDC_MAX_FREQUENCY * 2U)) - 1U;
    
    Base->MSCR = ENET_MSCR_DIS_PRE(MiiPreambleDisabled ? 1UL : 0UL) | ENET_MSCR_HOLDTIME(HoldTime) | ENET_MSCR_MII_SPEED(MiiSpeed);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_MDIORead
 * Description   : Reads the selected register of the PHY
 * implements     Enet_Ip_MDIORead_Activity
 *END**************************************************************************/
Enet_Ip_StatusType Enet_Ip_MDIORead(uint8 Instance,
                                    uint8 PhyAddr,
                                    uint8 PhyReg,
                                    uint16 *Data,
                                    uint32 TimeoutMs)
{
    ENET_Type *Base;
    Enet_Ip_StatusType Status;
    Enet_Ip_ManagementInfo ManageInfo;

    ENET_DEV_ASSERT(Instance < FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(Data != NULL_PTR);

    Base = Enet_apxBases[Instance];
    ManageInfo.PhysAddr = PhyAddr;
    ManageInfo.PhysReg = PhyReg;
    ManageInfo.MmdAddr = 0U;
    ManageInfo.OpFrameType = ENET_MMFR_OP_READ;
    ManageInfo.FrameData = 0U;
    ManageInfo.SupportedClause45 = FALSE;
    
    /* Write management frame */
    Status = ENET_WriteManagementFrame(Base, &ManageInfo, TimeoutMs * 1000U);

    if (Status == ENET_STATUS_SUCCESS)
    {
        *Data = ENET_ReadManagementFrameData(Base);
    }
    
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_MDIOWrite
 * Description   : Writes the selected register of the PHY
 * implements     Enet_Ip_MDIOWrite_Activity
 *END**************************************************************************/
Enet_Ip_StatusType Enet_Ip_MDIOWrite(uint8 Instance,
                                     uint8 PhyAddr,
                                     uint8 PhyReg,
                                     uint16 Data,
                                     uint32 TimeoutMs)
{
    ENET_Type *Base;
    Enet_Ip_StatusType Status;
    Enet_Ip_ManagementInfo ManageInfo;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);

    Base = Enet_apxBases[Instance];
    
    ManageInfo.PhysAddr = PhyAddr;
    ManageInfo.PhysReg = PhyReg;
    ManageInfo.MmdAddr = 0U;
    ManageInfo.OpFrameType = ENET_MMFR_OP_WRITE;
    ManageInfo.FrameData = Data;
    ManageInfo.SupportedClause45 = FALSE;
    
    /* Write management frame */
    Status = ENET_WriteManagementFrame(Base, &ManageInfo, TimeoutMs * 1000U);

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_MDIOReadMMD
 * Description   : Reads a register of the specified MMD in a PHY device
 * implements     Enet_Ip_MDIOReadMMD_Activity
 *END**************************************************************************/
Enet_Ip_StatusType Enet_Ip_MDIOReadMMD(uint8 Instance,
                                       uint8 PhyAddr,
                                       uint8 Mmd,
                                       uint16 PhyReg,
                                       uint16 *Data,
                                       uint32 TimeoutMs)
{
    ENET_Type *Base;
    Enet_Ip_StatusType Status;
    Enet_Ip_ManagementInfo ManageInfo;

    ENET_DEV_ASSERT(Instance < FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(Data != NULL_PTR);

    Base = Enet_apxBases[Instance];
    
    ManageInfo.PhysAddr = PhyAddr;
    ManageInfo.PhysReg = PhyReg;
    ManageInfo.MmdAddr = Mmd;
    ManageInfo.SupportedClause45 = TRUE;
    
    ManageInfo.OpFrameType = ENET_MMFR_OP_ADDR;
    ManageInfo.FrameData = PhyReg;
    
    /* Write management frame containing PHY register address */
    Status = ENET_WriteManagementFrame(Base, &ManageInfo, TimeoutMs * 1000U);
    if (ENET_STATUS_SUCCESS == Status)
    {
        ManageInfo.OpFrameType = ENET_MMFR_OP_READ_45;
        ManageInfo.FrameData = 0U;
        
        /* Write management frame to read data */
        Status = ENET_WriteManagementFrame(Base, &ManageInfo, TimeoutMs * 1000U);

        if (Status == ENET_STATUS_SUCCESS)
        {
            *Data = ENET_ReadManagementFrameData(Base);
        }
    }
    
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_MDIOWriteMMD
 * Description   : Writes a register of the specified MMD in a PHY device
 * implements     Enet_Ip_MDIOWriteMMD_Activity
 *END**************************************************************************/
Enet_Ip_StatusType Enet_Ip_MDIOWriteMMD(uint8 Instance,
                                        uint8 PhyAddr,
                                        uint8 Mmd,
                                        uint16 PhyReg,
                                        uint16 Data,
                                        uint32 TimeoutMs)
{
    ENET_Type *Base;
    Enet_Ip_StatusType Status;
    Enet_Ip_ManagementInfo ManageInfo;
    
    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);

    Base = Enet_apxBases[Instance];
    
    ManageInfo.PhysAddr = PhyAddr;
    ManageInfo.PhysReg = PhyReg;
    ManageInfo.MmdAddr = Mmd;    
    ManageInfo.SupportedClause45 = TRUE;
    
    ManageInfo.OpFrameType = ENET_MMFR_OP_ADDR;
    ManageInfo.FrameData = PhyReg;
    
    /* Write management frame containing PHY register address */
    Status = ENET_WriteManagementFrame(Base, &ManageInfo, TimeoutMs * 1000U);
    
    if (ENET_STATUS_SUCCESS == Status)
    {
        ManageInfo.OpFrameType = ENET_MMFR_OP_WRITE;
        ManageInfo.FrameData = Data;
        
        /* Write management frame containing data */
        Status = ENET_WriteManagementFrame(Base, &ManageInfo, TimeoutMs * 1000U);
    }    

    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_SetBroadcastForwardAll
 * Description   : Enables/Disables forwarding of the broadcast traffic.
 * implements     Enet_Ip_SetBroadcastForwardAll_Activity
 *END**************************************************************************/
void Enet_Ip_SetBroadcastForwardAll(uint8 Instance,
                                     boolean Enable)
{
    ENET_Type *Base;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);

    Base = Enet_apxBases[Instance];

    if (Enable)
    {
        Base->RCR &= ~ENET_RCR_BC_REJ_MASK;
    }
    else
    {
        /* Disable promiscuous modes. */
        Base->RCR &= ~ENET_RCR_PROM_MASK;

        Base->RCR |= ENET_RCR_BC_REJ_MASK;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_SetMulticastForwardAll
 * Description   : Enables/Disables forwarding of the multicast traffic,
 * irrespective of the destination MAC address.
 * implements     Enet_Ip_SetMulticastForwardAll_Activity
 *END**************************************************************************/
void Enet_Ip_SetMulticastForwardAll(uint8 Instance,
                                     boolean Enable)
{
    ENET_Type *Base;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);

    Base = Enet_apxBases[Instance];
    
    /* Disable promiscuous mode*/
    Base->RCR &= ~ENET_RCR_PROM_MASK;
    
    /* Restore hash table values to use later*/
    if ((0xFFFFFFFFU != Base->GALR) && (0U != Base->GALR))
    {
        Enet_au32FirstHashTable[Instance] = Base->GALR;
    }
    if ((0xFFFFFFFFU != Base->GAUR) && (0U != Base->GAUR))
    {
        Enet_au32SecondHashTable[Instance] = Base->GAUR;
    }

    if (Enable)
    {
        Base->GAUR = 0xFFFFFFFFU;
        Base->GALR = 0xFFFFFFFFU;
    }
    else
    {
        Base->GAUR = 0x0U;
        Base->GALR = 0x0U;
    }
    
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_RecoverFilter
 * Description   : Recover the hash table filteRing.
 *END**************************************************************************/
void Enet_Ip_RecoverFilter(uint8 Instance)
{
    ENET_Type *Base;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);

    Base = Enet_apxBases[Instance];
    
    Base->GAUR = Enet_au32SecondHashTable[Instance];
    Base->GALR = Enet_au32FirstHashTable[Instance];
    
    /* Disable promiscuous mode*/
    Base->RCR &= ~ENET_RCR_PROM_MASK;
}

#if FEATURE_ENET_HAS_SLEEP_WAKEUP
/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_SetSleepMode
 * Description   : Sets the MAC in sleep mode or normal mode
 *
 * implements     Enet_Ip_SetSleepMode_Activity
 *END**************************************************************************/
void Enet_Ip_SetSleepMode(uint8 Instance,
                           boolean Enable)
{
    ENET_Type *Base;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);

    Base  = Enet_apxBases[Instance];

    if (Enable)
    {
        Base->ECR |= ENET_ECR_SLEEP_MASK | ENET_ECR_MAGICEN_MASK;
    }
    else
    {
        Base->ECR &= ~(ENET_ECR_SLEEP_MASK | ENET_ECR_MAGICEN_MASK);
    }
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_AddDstAddrToHashFilter
 * Description   : Adds a hardware address to the hash filter.
 * implements     Enet_Ip_AddDstAddrToHashFilter_Activity 
 *END**************************************************************************/
void Enet_Ip_AddDstAddrToHashFilter(uint8 Instance,
                                     const uint8 *MacAddr)
{
    ENET_Type *Base;
    uint32 Crc;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(MacAddr != NULL_PTR);

    Base = Enet_apxBases[Instance];
    Crc = Enet_Ip_ComputeCRC32(MacAddr, 6U);
    
    /* Disable promiscuous mode*/
    Base->RCR &= ~ENET_RCR_PROM_MASK;

    ENET_AddToHashTable(Base, Crc);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_RemoveDstAddrFromHashFilter
 * Description   : Removes a hardware address from the hash filter.
 * implements     Enet_Ip_RemoveDstAddrFromHashFilter_Activity
 *END**************************************************************************/
void Enet_Ip_RemoveDstAddrFromHashFilter(uint8 Instance,
                                          const uint8 *MacAddr)
{
    ENET_Type *Base;
    uint32 Crc;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(MacAddr != NULL_PTR);

    Base = Enet_apxBases[Instance];
    Crc = Enet_Ip_ComputeCRC32(MacAddr, 6U);
    
    /* Disable promiscuous mode*/
    Base->RCR &= ~ENET_RCR_PROM_MASK;

    ENET_RemoveFromHashTable(Base, Crc);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_TimerStart
 * Description   : Starts the timer.
 *
 * implements    Enet_Ip_TimerStart_Activity
 *END**************************************************************************/
void Enet_Ip_TimerStart(uint8 Instance)
{
    ENET_Type *Base;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);

    Base = Enet_apxBases[Instance];

    Base->ATCR |= ENET_ATCR_EN_MASK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_TimerStop
 * Description   : Stops the timer.
 *
 * implements     Enet_Ip_TimerStop_Activity
 *END**************************************************************************/
void Enet_Ip_TimerStop(uint8 Instance)
{
    ENET_Type *Base;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);

    Base = Enet_apxBases[Instance];

    Base->ATCR &= ~ENET_ATCR_EN_MASK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_TimerEnableChannel
 * Description   : Configures and enables a specific timer channel.
 *
 * implements     Enet_Ip_TimerEnableChannel_Activity
 *END**************************************************************************/
Enet_Ip_StatusType Enet_Ip_TimerEnableChannel(uint8 Instance,
                                              uint8 Channel,
                                              const Enet_Ip_TimerChannelConfigType *Config)
{
    Enet_Ip_StatusType Status = ENET_STATUS_TIMEOUT;
    uint32 StartTime; 
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    ENET_Type *Base;

    ENET_DEV_ASSERT(Instance < FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(Channel < FEATURE_ENET_CHANNEL_COUNT);
    ENET_DEV_ASSERT(Config != NULL_PTR);

    Base = Enet_apxBases[Instance];

    /* Disable channel, interrupt, DMA and clear flag */
    Base->TC[Channel].TCSR = ENET_TCSR_TF_MASK;
    /* Add fault label for testing */
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        MCAL_FAULT_INJECTION_POINT(ETH_TIMER_ENABLE_CHANNEL_TIMEOUT);
    #endif    
    /* Wait for completion */
    ENET_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, ENET_TIMEOUT_VALUE_US);
    
    do
    {
        if (0U == (Base->TC[Channel].TCSR & ENET_TCSR_TMODE_MASK))
        {
            Status = ENET_STATUS_SUCCESS;
            break;
        }
    }
    while (!ENET_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks));

    Base->TC[Channel].TCSR |= ENET_TCSR_TIE(Config->IrqEnable ? 1UL : 0UL) |
                                   ENET_TCSR_TDRE(Config->DmaEnable ? 1UL : 0UL) |
                                   ENET_TCSR_TMODE(Config->Mode);
                                   
    return Status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_TimerSetCompare
 * Description   : Sets the compare value for a channel Configured as output compare.
 *
 * implements     Enet_Ip_TimerSetCompare_Activity
 *END**************************************************************************/
void Enet_Ip_TimerSetCompare(uint8 Instance,
                             uint8 Channel,
                             uint32 Value)
{
    ENET_Type *Base;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(Channel < FEATURE_ENET_CHANNEL_COUNT);

    Base = Enet_apxBases[Instance];

    Base->TC[Channel].TCCR = Value;
}

#if FEATURE_ENET_HAS_INPUT_CAPTURE
/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_TimerGetCapture
 * Description   : Gets the last value captured on a specific Channel Configured as
 * input capture.
 *
 * implements     Enet_Ip_TimerGetCapture_Activity
 *END**************************************************************************/
void Enet_Ip_TimerGetCapture(uint8 Instance,
                              uint8 Channel,
                              uint32 *Capture)
{
    ENET_Type *Base;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(Channel < FEATURE_ENET_CHANNEL_COUNT);
    ENET_DEV_ASSERT(Capture != NULL_PTR);

    Base = Enet_apxBases[Instance];

    *Capture = Base->TC[Channel].TCCR;

    Base->TC[Channel].TCSR |= ENET_TCSR_TF_MASK;
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_TimerInit
 * Description   : Initializes the adjustable timer using the given Configuration
 * and enables it.
 *
 * implements     Enet_Ip_TimerInit_Activity
 *END**************************************************************************/
void Enet_Ip_TimerInit(uint8 Instance,
                       const Enet_Ip_TimerConfigType *TimerConfig)
{
    ENET_Type *Base;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(TimerConfig != NULL_PTR);
    ENET_DEV_ASSERT(Enet_apxState[Instance] != NULL_PTR);

    Base = Enet_apxBases[Instance];

    Base->ATVR  = 0U;
    Base->ATPER = ENET_ATPER_PERIOD(TimerConfig->TimerPeriod);
    Base->ATCOR = ENET_ATCOR_COR(TimerConfig->CorrectionPeriod);
    Base->ATINC = ENET_ATINC_INC(TimerConfig->TimerInc) | ENET_ATINC_INC_CORR(TimerConfig->CorrectionInc);
    Base->ATCR |= ENET_ATCR_EN_MASK | ENET_ATCR_PEREN(1UL);
    
    Enet_axLocalTime[Instance].nanoseconds = 0U;
    Enet_axLocalTime[Instance].seconds = 0U;
    Enet_axLocalTime[Instance].secondsHi = 0U;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_TimerSet
 * Description   : Sets the value of the timer.
 *
 * implements    Enet_Ip_TimerSet_Activity
 *END**************************************************************************/
void Enet_Ip_TimerSet(uint8 Instance,
                      Enet_Ip_TimeStampType TimerValue)
{
    ENET_Type *Base;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);

    Base = Enet_apxBases[Instance];
    
    Enet_axLocalTime[Instance].seconds = TimerValue.seconds;
    Enet_axLocalTime[Instance].secondsHi = TimerValue.secondsHi;
    
    /* Clear wrap flag */
    Base->EIR |= ENET_EIR_TS_TIMER_MASK;
    Base->ATVR = TimerValue.nanoseconds; 
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_SetSysTimeCorr
 * Description   : Sets the system time correction by either adding or subtracting
 *                 the selected value from the current system time.
 * implements     Enet_Ip_SetSysTimeCorr_Activity 
 *END**************************************************************************/
void Enet_Ip_SetSysTimeCorr(uint8 Instance,
                          Enet_Ip_SysTimeCorrOffsetType Offset,
                          Enet_Ip_TimeStampType DiffTimeStamp)
{
    sint32 TempNanosecond;
    sint32 TempSecond;
    uint8 CarryNs = 0U;
    uint8 Carry = 0U;
    
    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    
    if ((Enet_Ip_SysTimeCorrOffsetType)ENET_SYS_TIME_CORR_POSITIVE != Offset)
    {
        TempNanosecond = (sint32)Enet_Ip_ReadTimerValue(Instance) - (sint32)DiffTimeStamp.nanoseconds;
        if (0 > TempNanosecond)
        {
            TempNanosecond = TempNanosecond + 1000000000;
            CarryNs = 1U;
        }
        Enet_axLocalTime[Instance].nanoseconds = (uint32)TempNanosecond;
        TempSecond = (sint32)Enet_axLocalTime[Instance].seconds - (sint32)DiffTimeStamp.seconds - (sint32)CarryNs;
        if (0 > TempSecond)
        {
            TempSecond = TempSecond + 1000000000;
            Carry = 1U;
        }
        Enet_axLocalTime[Instance].seconds = (uint32)TempSecond;
        Enet_axLocalTime[Instance].secondsHi = (uint16)(Enet_axLocalTime[Instance].secondsHi - DiffTimeStamp.secondsHi - Carry);

        Enet_Ip_TimerSet(Instance, Enet_axLocalTime[Instance]);
        
    }
    else
    {
        Enet_axLocalTime[Instance].nanoseconds = Enet_Ip_ReadTimerValue(Instance) + DiffTimeStamp.nanoseconds;
        if (1000000000U < Enet_axLocalTime[Instance].nanoseconds)
        {
            Enet_axLocalTime[Instance].nanoseconds = Enet_axLocalTime[Instance].nanoseconds - 1000000000U;
            CarryNs = 1U;
        }
        Enet_axLocalTime[Instance].seconds = DiffTimeStamp.seconds + Enet_axLocalTime[Instance].seconds + CarryNs;
        if (1000000000U < Enet_axLocalTime[Instance].seconds)
        {
            Enet_axLocalTime[Instance].seconds = Enet_axLocalTime[Instance].seconds - 1000000000U;
            Carry = 1U;
        }
        
        Enet_axLocalTime[Instance].secondsHi = DiffTimeStamp.secondsHi + Enet_axLocalTime[Instance].secondsHi + Carry;
        
        Enet_Ip_TimerSet(Instance, Enet_axLocalTime[Instance]);
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : ENET_DRV_TimerSetCorrection
 * Description   : Sets the timer correction period and correction increment value.
 *
 * implements     Enet_Ip_TimerSetCorrection_Activity
 *END**************************************************************************/
void Enet_Ip_TimerSetCorrection(uint8 Instance,
                                 uint32 CorrectValue,
                                 uint32 CorrectPeriod)
{
    ENET_Type *Base;

    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);

    Base = Enet_apxBases[Instance];

    Base->ATCOR = ENET_ATCOR_COR(CorrectPeriod);
    Base->ATINC &= ~ENET_ATINC_INC_CORR_MASK;
    Base->ATINC |= ENET_ATINC_INC_CORR(CorrectValue);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Enet_Ip_TimerGet
 * Description   : Gets the value of the timer.
 *
 * implements     Enet_Ip_TimerGet_Activity
 *END**************************************************************************/
void Enet_Ip_TimerGet(uint8 Instance,
                       Enet_Ip_TimeStampType *TimeStamp)
{
    uint32 Currentnanoseconds;
    uint32 Nextnanoseconds;
   
    ENET_DEV_ASSERT(Instance <  FEATURE_ENET_NUM_INSTANCES);
    ENET_DEV_ASSERT(TimeStamp !=  NULL_PTR);
    
    /* Read timer 2 times to check when the timer wrapped */
    Currentnanoseconds = Enet_Ip_ReadTimerValue(Instance);
    
    TimeStamp->secondsHi = Enet_axLocalTime[Instance].secondsHi;
    TimeStamp->seconds = Enet_axLocalTime[Instance].seconds;
    
    Nextnanoseconds = Enet_Ip_ReadTimerValue(Instance);

    /* If the wrap was between 2 reads, then decrease the value for second part. */
    if (Currentnanoseconds > Nextnanoseconds)
    {
        if (0U == TimeStamp->seconds)
        {
            TimeStamp->secondsHi--;
            TimeStamp->seconds = 0xFFFFFFFFU;
        }
        else
        {
            TimeStamp->seconds--;
        }
    }
    TimeStamp->nanoseconds = Currentnanoseconds;
}

#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */
