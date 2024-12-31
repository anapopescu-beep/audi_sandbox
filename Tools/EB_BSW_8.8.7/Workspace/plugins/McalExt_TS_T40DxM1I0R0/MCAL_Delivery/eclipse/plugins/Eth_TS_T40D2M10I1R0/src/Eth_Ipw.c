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
*   @addtogroup ETH_DRIVER Ethernet Driver
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
#include "Eth_Ipw.h"
#include "Enet_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_IPW_VENDOR_ID_C                      43
#define ETH_IPW_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_IPW_AR_RELEASE_MINOR_VERSION_C       4
#define ETH_IPW_AR_RELEASE_REVISION_VERSION_C    0
#define ETH_IPW_SW_MAJOR_VERSION_C               1
#define ETH_IPW_SW_MINOR_VERSION_C               0
#define ETH_IPW_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Eth_Ipw.h */
#if (ETH_IPW_VENDOR_ID_C != ETH_IPW_VENDOR_ID)
    #error "Eth_Ipw.c and Eth_Ipw.h have different vendor ids"
#endif
#if ((ETH_IPW_AR_RELEASE_MAJOR_VERSION_C    != ETH_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_IPW_AR_RELEASE_MINOR_VERSION_C    != ETH_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ETH_IPW_AR_RELEASE_REVISION_VERSION_C != ETH_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_Ipw.c and Eth_Ipw.h are different"
#endif
#if ((ETH_IPW_SW_MAJOR_VERSION_C != ETH_IPW_SW_MAJOR_VERSION) || \
     (ETH_IPW_SW_MINOR_VERSION_C != ETH_IPW_SW_MINOR_VERSION) || \
     (ETH_IPW_SW_PATCH_VERSION_C != ETH_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_Ipw.c and Eth_Ipw.h are different"
#endif

/* Checks against Enet_Ip.h */
#if (ETH_IPW_VENDOR_ID_C != ENET_IP_VENDOR_ID)
    #error "Eth_Ipw.c and Enet_Ip.h have different vendor ids"
#endif
#if ((ETH_IPW_AR_RELEASE_MAJOR_VERSION_C    != ENET_IP_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_IPW_AR_RELEASE_MINOR_VERSION_C    != ENET_IP_AR_RELEASE_MINOR_VERSION) || \
     (ETH_IPW_AR_RELEASE_REVISION_VERSION_C != ENET_IP_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of Eth_Ipw.c and Enet_Ip.h are different"
#endif
#if ((ETH_IPW_SW_MAJOR_VERSION_C != ENET_IP_SW_MAJOR_VERSION) || \
     (ETH_IPW_SW_MINOR_VERSION_C != ENET_IP_SW_MINOR_VERSION) || \
     (ETH_IPW_SW_PATCH_VERSION_C != ENET_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eth_Ipw.c and Enet_Ip.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define ETH_IPW_TIMEOUT_1MS_U32                 ((uint32)1U)
#define ETH_IPW_MAX_DEM_ERRORS_U32              ((uint32)ETH_NUMBER_OF_DEM_IDS)
/* Assign ENET_CTR_RMON_T_DROP to ETH_IPW_DEM_ERROR_UNUSED_U32 because DemErrorId = 0U never exist */
#define ETH_IPW_DEM_ERROR_UNUSED_U32            (ENET_CTR_NUMBER_OF_COUNTERS)

#if STD_ON == ETH_GLOBAL_TIME_API
    #define ETH_IPW_STONS_U64(u48Seconds)           ((uint64)((uint64)(u48Seconds) * (uint64)1000000000UL))
#endif
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ETH_START_SEC_VAR_CLEARED_32
#include "Eth_MemMap.h"

#if (STD_ON == ETH_DEM_EVENT_DETECT)
    static uint32 Eth_Ipw_au32DemErrorCounters[ETH_MAX_CTRLIDX_SUPPORTED][ETH_IPW_MAX_DEM_ERRORS_U32];
#endif

static Eth_BufIdxType Eth_Ipw_axFirstTxBufferIdxInFifo[ETH_MAX_CTRLIDX_SUPPORTED][ETH_MAX_TXFIFO_SUPPORTED];

#define ETH_STOP_SEC_VAR_CLEARED_32
#include "Eth_MemMap.h"


#define ETH_START_SEC_CONST_32
#include "Eth_MemMap.h"

#if (STD_ON == ETH_DEM_EVENT_DETECT)
    /* Map between Eth_DemErrorIdType and Enet_Ip_CounterType */
    static const Enet_Ip_CounterType Eth_Ipw_au32DemErrIdToMmcCnt[ETH_IPW_MAX_DEM_ERRORS_U32] =
    {
        ETH_IPW_DEM_ERROR_UNUSED_U32,
        ENET_CTR_IEEE_R_DROP,
        ENET_CTR_IEEE_R_CRC,
        ENET_CTR_RMON_R_UNDERSIZE,
        ENET_CTR_RMON_R_OVERSIZE,
        ENET_CTR_IEEE_R_ALIGN,
        ENET_CTR_IEEE_T_1COL,
        ENET_CTR_IEEE_T_MCOL,
        ENET_CTR_IEEE_T_LCOL
    };
#endif

#define ETH_STOP_SEC_CONST_32
#include "Eth_MemMap.h"


#define ETH_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_MemMap.h"

/* Eth_Receive is reentrant for different FIFOs so we need a pair of (Enet_Ip_BufferType, Enet_Ip_RxInfoType) for each FIFO */
static Enet_Ip_BufferType Eth_Ipw_RxFrameBuffer[ETH_MAX_CTRLIDX_SUPPORTED][ETH_MAX_RXFIFO_SUPPORTED];
static Enet_Ip_RxInfoType Eth_Ipw_RxFrameInfo[ETH_MAX_CTRLIDX_SUPPORTED][ETH_MAX_RXFIFO_SUPPORTED];

/* We cannot guarantee reentrancy in Eth_Transmit for different buffer indexes */
/* Make Eth_Transmit reentrant for different FIFOs so we need a pair of (Enet_Ip_BufferType, Enet_Ip_TxInfoType) for each FIFO */
static Enet_Ip_TxInfoType Eth_Ipw_TxFrameInfo[ETH_MAX_CTRLIDX_SUPPORTED][ETH_MAX_TXFIFO_SUPPORTED];

#define ETH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define ETH_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_MemMap.h"

#if ((STD_ON == ETH_DEM_EVENT_DETECT) || (STD_ON == ETH_GLOBAL_TIME_API))
/* Pointers to IPW configuration structures stored for later use */
const Eth_Ipw_CtrlConfigType *Eth_Ipw_apxInternalCfg[ETH_MAX_CTRLIDX_SUPPORTED];
#endif

#define ETH_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Eth_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ETH_START_SEC_CODE
#include "Eth_MemMap.h"

#if (STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER_API)
static inline boolean Eth_Ipw_Local_IsOpenFilterPattern(const uint8 *PhyAddr);
static inline boolean Eth_Ipw_Local_IsCloseFilterPattern(const uint8 *PhyAddr);
static inline boolean Eth_Ipw_Local_IsMulticastAddress(const uint8 *PhyAddr);
/* Check whether address filtering is totally open or not */
static inline boolean Eth_Ipw_Local_IsOpenFilterPattern(const uint8 *PhyAddr)
{
    /* Compare each address byte with 0xFF if all bytes have value of 0xFF then always receive frame */
    return ((PhyAddr[0U] == 0xFFU) && (PhyAddr[1U] == 0xFFU) && (PhyAddr[2U] == 0xFFU) && (PhyAddr[3U] == 0xFFU) && (PhyAddr[4U] == 0xFFU) && (PhyAddr[5U] == 0xFFU));
}
/* Check whether address filtering is totally close or not */
static inline boolean Eth_Ipw_Local_IsCloseFilterPattern(const uint8 *PhyAddr)
{
    /* Compare each address byte with 0 if all bytes have value of 0 then filter close */
    return ((PhyAddr[0U] == 0U) && (PhyAddr[1U] == 0U) && (PhyAddr[2U] == 0U) && (PhyAddr[3U] == 0U) && (PhyAddr[4U] == 0U) && (PhyAddr[5U] == 0U)); 
}

static inline boolean Eth_Ipw_Local_IsMulticastAddress(const uint8 *PhyAddr)
{
    /* Check if I/G bit is set (indicates a multicast address) */
    return (1U == (PhyAddr[0] & 1U));
}
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief         Reads a frame from the given FIFO of the given controller
*
* @param[in]     CtrlIdx       Index of the controller
* @param[in]     FifoIdx       Index of the FIFO from which the frame should be read
* @param[out]    FrameData   Pointer to the frame data
* @param[out]    FrameLength Pointer to the length of the frame
* @param[out]    FrameHasError Pointer to flag signaling if the frame is erroneous
*
* @return        Eth_RxStatusType
* @retval        ETH_NOT_RECEIVED No frame received
* @retval        ETH_RECEIVED     Frame received, no more frames available
* @retval        ETH_RECEIVED_MORE_DATA_AVAILABLE Frame received, more frames are available
*/
Eth_RxStatusType Eth_Ipw_ReceiveFrame ( \
                                           const uint8 CtrlIdx, \
                                           const uint8 FifoIdx, \
                                           uint8 **FrameData, \
                                           uint16 *FrameLength, \
                                           boolean *FrameHasError
                                      )
{
    Eth_RxStatusType RxStatus = ETH_NOT_RECEIVED;

    if (ENET_STATUS_RX_QUEUE_EMPTY != Enet_Ip_ReadFrame(CtrlIdx, FifoIdx, &Eth_Ipw_RxFrameBuffer[CtrlIdx][FifoIdx], &Eth_Ipw_RxFrameInfo[CtrlIdx][FifoIdx]))
    {
        *FrameData   = Eth_Ipw_RxFrameBuffer[CtrlIdx][FifoIdx].Data;
        *FrameLength = Eth_Ipw_RxFrameInfo[CtrlIdx][FifoIdx].PktLen;
        *FrameHasError = ((0U != Eth_Ipw_RxFrameInfo[CtrlIdx][FifoIdx].ErrMask)? ((boolean)TRUE) : ((boolean)FALSE));

        RxStatus = ETH_RECEIVED;

        if (Enet_Ip_IsFrameAvailable(CtrlIdx, FifoIdx))
        {
            RxStatus = ETH_RECEIVED_MORE_DATA_AVAILABLE;
        }
    }

    return RxStatus;
}

/*================================================================================================*/
/**
* @brief         Releases the resources locked by the previous call to function Eth_Ipw_ReceiveFrame
*
* @param[in]     CtrlIdx      Index of the controller
* @param[in]     FifoIdx      Index of the FIFO from which the frame was read
*
* @return        void
*/
void Eth_Ipw_ReleaseResources ( \
                                const uint8 CtrlIdx, \
                                const uint8 FifoIdx  \
                              )
{
    Enet_Ip_ProvideRxBuff(CtrlIdx, FifoIdx, &Eth_Ipw_RxFrameBuffer[CtrlIdx][FifoIdx]);

    /* Mark the buffer as released */
    Eth_Ipw_RxFrameBuffer[CtrlIdx][FifoIdx].Data = NULL_PTR;
}

#if STD_ON == ETH_GET_RXSTATS_API
/*================================================================================================*/
/**
* @brief         Return the list of Receive Statistics.
* @param[in]     CtrlIdx Index of controller within the context of the Ethernet Driver.
* @param[out]    RxStats List of values according to IETF RFC 2819.
* @details       RxStats List of values according to IETF RFC 2819, where the maximal possible value shall
*                denote an invalid value.
*                e.g. if this counter is not available.
*/
Std_ReturnType Eth_Ipw_GetRxStats ( \
                       uint8 CtrlIdx, \
                       Eth_RxStatsType *RxStatsPtr \
                                  )
{
    /* Maximal possible value shall denote an invalid value (e.g. counter not available) */
    /* Warning: All this fumbling on the call stack might have a negative impact on performance.
     *          Execution times shall be measured and compared. */

    RxStatsPtr->RxStatsDropEvents           = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_IEEE_R_DROP);
    RxStatsPtr->RxStatsOctets               = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_IEEE_R_OCTETS_OK);
    RxStatsPtr->RxStatsPkts                 = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_IEEE_R_FRAME_OK);
    RxStatsPtr->RxStatsBroadcastPkts        = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_BC_PKT);
    RxStatsPtr->RxStatsMulticastPkts        = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_MC_PKT);
    RxStatsPtr->RxStatsCrcAlignErrors       = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_CRC_ALIGN);
    RxStatsPtr->RxStatsUndersizePkts        = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_UNDERSIZE);
    RxStatsPtr->RxStatsOversizePkts         = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_OVERSIZE);
    RxStatsPtr->RxStatsFragments            = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_FRAG);
    RxStatsPtr->RxStatsJabbers              = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_JAB);
    RxStatsPtr->RxStatsCollisions           = (uint32)-1;
    RxStatsPtr->RxStatsPkts64Octets         = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_P64);
    RxStatsPtr->RxStatsPkts65to127Octets    = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_P65TO127);
    RxStatsPtr->RxStatsPkts128to255Octets   = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_P128TO255);
    RxStatsPtr->RxStatsPkts256to511Octets   = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_P256TO511);
    RxStatsPtr->RxStatsPkts512to1023Octets  = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_P512TO1023);
    RxStatsPtr->RxStatsPkts1024to1518Octets = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_P1024TO2047);
    RxStatsPtr->RxUnicastFrames             = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_PACKETS);
    RxStatsPtr->RxUnicastFrames             -= Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_BC_PKT);
    RxStatsPtr->RxUnicastFrames             -= Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_MC_PKT);

    return (Std_ReturnType)E_OK;
}
#endif

#if STD_ON == ETH_GET_TXSTATS_API
/*================================================================================================*/
/**
* @brief         Return the list of Transmission Statistics.
* @param[in]     CtrlIdx Index of controller within the context of the Ethernet Driver.
* @param[out]     TxStats List of the controller within the context of the Ethernet Driver.
* @details       Return the list of Transmission Sratistics out of IETF RFC1213
*                defined with Eth_TxStatsType, where the maximal possible value shall
*                denote an invalid value.
*                e.g. this counter is not available..
*/
Std_ReturnType Eth_Ipw_GetTxStats ( \
                       uint8 CtrlIdx, \
                       Eth_TxStatsType * TxStatsPtr \
                                  )
{
    /* Maximal possible value shall denote an invalid value (e.g. counter not available) */
    /* Warning: All this fumbling on the call stack might have a negative impact on performance.
     *          Execution times shall be measured and compared. */

    TxStatsPtr->TxNumberOfOctets  = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_T_OCTETS);
    TxStatsPtr->TxNUcastPkts      = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_T_BC_PKT); 
    TxStatsPtr->TxNUcastPkts      += Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_T_MC_PKT); 
    TxStatsPtr->TxUniCastPkts     = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_T_PACKETS);
    TxStatsPtr->TxUniCastPkts     -= TxStatsPtr->TxNUcastPkts;

    return (Std_ReturnType)E_OK;
}
#endif

#if STD_ON == ETH_GET_TXERROR_COUNTER_API
/*================================================================================================*/
/**
* @brief         Return the list of Transmission Statistics.
* @param[in]     CtrlIdx Index of controller within the context of the Ethernet Driver.
* @param[out]    Eth_TxErrorCounterValuesType List of values to read statistic error values for transmiision.
* @details       Return the list of Transmission Error Counters out of IETF RFC1213 and RFC1643
*                defined with Eth_TxErrorCounterValuesType, where the maximal possible value shall
*                denote an invalid value.
*                e.g. this counter is not available..
*/
Std_ReturnType Eth_Ipw_GetTxErrorCounterValues ( \
                       uint8 CtrlIdx, \
                       Eth_TxErrorCounterValuesType *TxErrorCounterValuesPtr \
                                               )
{
    /* Maximal possible value shall denote an invalid value (e.g. counter not available) */
    /* Warning: All this fumbling on the call stack might have a negative impact on performance.
     *          Execution times shall be measured and compared. */

    TxErrorCounterValuesPtr->TxDroppedNoErrorPkts = (uint32)-1;
    TxErrorCounterValuesPtr->TxDroppedErrorPkts   = (uint32)-1;
    TxErrorCounterValuesPtr->TxDeferredTrans      = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_IEEE_T_DEF);
    TxErrorCounterValuesPtr->TxSingleCollision    = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_IEEE_T_1COL);
    TxErrorCounterValuesPtr->TxMultipleCollision  = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_IEEE_T_MCOL);
    TxErrorCounterValuesPtr->TxLateCollision      = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_IEEE_T_LCOL);
    TxErrorCounterValuesPtr->TxExcessiveCollison  = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_IEEE_T_EXCOL);

    return (Std_ReturnType)E_OK;
}
#endif

#if STD_ON == ETH_GLOBAL_TIME_API
/*================================================================================================*/
/**
* @brief        Allows the Time Master to adjust the global ETH Reference clock in HW.
* @details      We can use this method to set a global time base on ETH in general or to
*               synchronize the global ETH time base with another time base, e.g. FlexRay.
* @param[in]    CtrlIdx Index of the TM controller which time shall be adjusted.
* @param[in]    ClkCfg Clock for TimeStamp
* @param[in]    TimeStampPtr Pointer to new time stamp.
*/
void Eth_Ipw_SetGlobalTime ( \
                      uint8 CtrlIdx, \
                      const Eth_ClockCfgType *ClkCfg, \
                      const Eth_TimeStampType * TimeStampPtr \
                        )
{
    (void)ClkCfg;
    
    Enet_Ip_TimeStampType SysTimeConfig;

    SysTimeConfig.nanoseconds = TimeStampPtr->nanoseconds;
    SysTimeConfig.seconds = TimeStampPtr->seconds;
    SysTimeConfig.secondsHi = TimeStampPtr->secondsHi;
    
    Enet_Ip_TimerSet(CtrlIdx, SysTimeConfig);
}

/*================================================================================================*/
/**
* @brief        Allows the Time Slave to adjust the local ETH Reference clock in HW.
* @details      Only use this function when this controller used as Time Slave.
*              
* @param[in]    CtrlIdx        Index of the controller which time shall be corrected
* @param[in]    timeOffsetPtr  Offset between time stamp grandmaster and time stamp by local 
*               clock.
* @param[in]    RateRatioPtr  Time elements to calculate and to modify the ratio of the frequency of 
*                              the grandmaster in relation to the frequency of the Local Clock
*/
Std_ReturnType Eth_Ipw_SetCorrectionTime ( \
                        uint8 CtrlIdx, \
                        const Eth_ClockCfgType *ClkCfg, \
                        const Eth_TimeIntDiffType *TimeOffsetPtr, \
                        const Eth_RateRatioType* RateRatioPtr \
                            )
{
    uint64 RemoteTime;
    uint64 LocalTime;
    uint32 NormalInc;
    uint32 CorrectInc;
    uint32 NormalTimer;
    uint32 LocalCycleNums;
    Enet_Ip_TimeStampType TimeStamp;
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_OK;

    if ((TimeOffsetPtr->diff.seconds != 0U) || (TimeOffsetPtr->diff.nanoseconds != 0U))
    {
        TimeStamp.secondsHi = TimeOffsetPtr->diff.secondsHi;
        TimeStamp.seconds = TimeOffsetPtr->diff.seconds;
        TimeStamp.nanoseconds = TimeOffsetPtr->diff.nanoseconds;
        Enet_Ip_SetSysTimeCorr(CtrlIdx, ((TimeOffsetPtr->sign == (boolean)TRUE) ? (Enet_Ip_SysTimeCorrOffsetType)ENET_SYS_TIME_CORR_POSITIVE : (Enet_Ip_SysTimeCorrOffsetType)ENET_SYS_TIME_CORR_NEGATIVE), TimeStamp);
    }
    
    RemoteTime = ETH_IPW_STONS_U64(
                           ((uint64)RateRatioPtr->OriginTimeStampDelta.diff.secondsHi << 32U) +
                            (uint64)RateRatioPtr->OriginTimeStampDelta.diff.seconds
                        ) + (uint64)RateRatioPtr->OriginTimeStampDelta.diff.nanoseconds;
                        
    LocalTime  = ETH_IPW_STONS_U64(
                           ((uint64)RateRatioPtr->IngressTimeStampDelta.diff.secondsHi << 32U) +
                            (uint64)RateRatioPtr->IngressTimeStampDelta.diff.seconds
                        ) + (uint64)RateRatioPtr->IngressTimeStampDelta.diff.nanoseconds;
    
    
    if (RemoteTime != LocalTime)
    {
        /* Calculation */
        NormalInc = ClkCfg->TimeStampClockPeriodPs / 1000U;
        LocalCycleNums = (uint32)(LocalTime / NormalInc);
        
        if (Eth_Ipw_apxInternalCfg[CtrlIdx]->CorectionCounter < LocalCycleNums)
        {
            /* The amount of time elapsed with normal increment before trigger correction */
            NormalTimer = Eth_Ipw_apxInternalCfg[CtrlIdx]->CorectionCounter * NormalInc;
            
            /* Calculate correction increment value for each cycle */
            CorrectInc = (uint32)((RemoteTime - NormalTimer) / (LocalCycleNums - Eth_Ipw_apxInternalCfg[CtrlIdx]->CorectionCounter));
            
            if (RemoteTime < NormalTimer)
            {
                ReturnStatus = (Std_ReturnType)E_NOT_OK;
            }
            
            Enet_Ip_TimerSetCorrection(CtrlIdx, (uint32)CorrectInc, Eth_Ipw_apxInternalCfg[CtrlIdx]->CorectionCounter);
        } 
        else
        {
            ReturnStatus = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        Enet_Ip_TimerSetCorrection(CtrlIdx, 0U, 0U);
    }
    
    return ReturnStatus;
}

/*================================================================================================*/
/**
* @brief        Get values of timer at this time.
* @details      Returns a time value out of the HW registers according to the capability of the HW.
*               Is the HW resolution is lower than the Eth_TimeStampType resolution resp.
*               Range, than an the remaining bits will be filled with 0.
* @param[in]    CtrlIdx Index of controller to be update the filter
* @param[out]   TimeQualPtr Quality of HW time stamp, e.g. based on current drift.
* @param[out]   TimeStampPtr current time stamp.
*/
Std_ReturnType Eth_Ipw_GetCurrentTime    ( \
                      uint8 CtrlIdx, \
                      Eth_TimeStampQualType *TimeQualPtr, \
                      Eth_TimeStampType *TimeStampPtr \
                               )
{
    Enet_Ip_TimeStampType TimeStamp;
    
    Enet_Ip_TimerGet(CtrlIdx, &TimeStamp);
    
    TimeStampPtr->nanoseconds = TimeStamp.nanoseconds;
    TimeStampPtr->seconds = TimeStamp.seconds;
    TimeStampPtr->secondsHi = TimeStamp.secondsHi;
    
    *TimeQualPtr = ETH_VALID;
    
    return (Std_ReturnType)E_OK;
}

/*================================================================================================*/
/**
* @brief        Enable egress time stamping on a trsnsmission message.
* @details      Activates egress time stamping on a dedicated message object.
*               Some HW does store once the egress time stamp merker and some HW needs it always before transmission.
*               There will be no "disable" functionality, due to the fact, that the message type is always "time stamped" by network design.
* @param[in]    CtrlIdx Index of controller to be update the filter
* @param[in]    BufIdx Index of the message buffer, where Application expects egress time stamping.
*/
void Eth_Ipw_EnableEgressTimeStamp   ( \
                                uint8 CtrlIdx, \
                                Eth_BufIdxType BufIdx \
                                     )
{
    /* Prevent misra, compiler warnings */
    (void)CtrlIdx;
    (void)BufIdx;
}

/*================================================================================================*/
/**
* @brief        Get values of timer at the time transmit a message.
* @details      Reads back the egress time stamp on a dedicated message object.
*               It must be called within the TxConfirmation() function.
* @param[in]    CtrlIdx Index of controller to be update the filter
* @param[out]   TimeQual Quality of HW time stamp, e.g. based on current drift.
* @param[out]   TimeStamp current time stamp.
*/
void Eth_Ipw_GetEgressTimeStamp  ( \
                                    const uint8 CtrlIdx, \
                                    const uint8 FifoIdx, \
                                    Eth_TimeStampQualType *TimeQual, \
                                    Eth_TimeStampType *TimeStamp \
                                 )
{
    if (0U == Eth_Ipw_TxFrameInfo[CtrlIdx][FifoIdx].TimeStamp.nanoseconds)
    {
        *TimeQual= ETH_INVALID;
    }
    else
    {
        TimeStamp->nanoseconds = Eth_Ipw_TxFrameInfo[CtrlIdx][FifoIdx].TimeStamp.nanoseconds;
        TimeStamp->seconds     = Eth_Ipw_TxFrameInfo[CtrlIdx][FifoIdx].TimeStamp.seconds;
        TimeStamp->secondsHi   = Eth_Ipw_TxFrameInfo[CtrlIdx][FifoIdx].TimeStamp.secondsHi;

        *TimeQual = ETH_VALID;
    }
}

/*================================================================================================*/
/**
* @brief        Get values of timer at the time receive a message.
* @details      Reads back the ingress time stamp on a dedicated message object.
*               It must be called within the RxIndication() function.
* @param[in]    CtrlIdx Index of controller to be update the filter
* @param[out]   TimeQualPtr Quality of HW time stamp, e.g. based on current drift.
* @param[out]   TimeStampPtr current time stamp.
*/
void Eth_Ipw_GetIngressTimeStamp ( \
                                    const uint8 CtrlIdx, \
                                    const uint8 FifoIdx, \
                                    const uint8 *FrameData, \
                                    Eth_TimeStampQualType *TimeQual, \
                                    Eth_TimeStampType *TimeStamp \
                                 )
{
    if (FrameData == Eth_Ipw_RxFrameBuffer[CtrlIdx][FifoIdx].Data)
    {
        if (0U == Eth_Ipw_RxFrameInfo[CtrlIdx][FifoIdx].TimeStamp.nanoseconds)
        {
            *TimeQual = ETH_INVALID;
        }
        else
        {
            TimeStamp->nanoseconds = Eth_Ipw_RxFrameInfo[CtrlIdx][FifoIdx].TimeStamp.nanoseconds;
            TimeStamp->seconds     = Eth_Ipw_RxFrameInfo[CtrlIdx][FifoIdx].TimeStamp.seconds;
            TimeStamp->secondsHi   = Eth_Ipw_RxFrameInfo[CtrlIdx][FifoIdx].TimeStamp.secondsHi;

            *TimeQual = ETH_VALID;
        }
    }
}
#endif

#if (STD_ON == ETH_DEM_EVENT_DETECT)
/*================================================================================================*/
/**
* @brief        Get errors and lost frames.
* @details      This function is only called by "Eth_MainFunction"
*/
boolean Eth_Ipw_ErrorDetected( \
                            const uint8 CtrlIdx, \
                            const Eth_DemErrorIdType DemErrorId \
                             )
{
    uint32 OldValue;
    Enet_Ip_CounterType MmcCounter;

    OldValue = Eth_Ipw_au32DemErrorCounters[CtrlIdx][(uint32)DemErrorId];
    MmcCounter  = Eth_Ipw_au32DemErrIdToMmcCnt[(uint32)DemErrorId];
    Eth_Ipw_au32DemErrorCounters[CtrlIdx][(uint32)DemErrorId] = Enet_Ip_GetCounter(CtrlIdx, MmcCounter);

    return ((Eth_Ipw_au32DemErrorCounters[CtrlIdx][(uint32)DemErrorId] > OldValue) ? ((boolean)TRUE) : ((boolean)FALSE));
}
#endif

/*================================================================================================*/
/**
* @brief         Checks the access to the controller
* @details       Function is intended to be used only after the Ethernet
*                controller reset. It checks the reset value of one register
*                and checks whether it agrees with the datasheet value.
*                Controller is claimed as accessible if the value agrees.
* @param[in]     CtrlIdx Index of controller which will be checked the access
* @return        Controller accessibility
* @retval        TRUE Controller is accessible, value in register agrees.
* @retval        FALSE Controller access failed, different value read.
*/
boolean Eth_Ipw_CheckAccessToController(const uint8 CtrlIdx)
{
    /* This check only makes sense for Ethernet controllers that are not accessed directly
     * through a bus interface (e.g. AXI/AHB/APB), but through a communication interface
     * (e.g. SPI) */

    (void)CtrlIdx;

    return (boolean)TRUE;
}
/*================================================================================================*/
/**
* @brief         Control frame transmitted in a duration time.
* @details       Function will initialize duration time with open or close to enable
*                frame can be transmitted or not in that duration time.               
* @param[in]     CtrlIdx Index of controller which will be checked the access
* @param[in]     IpwCtrlCfg parameters of controller will be used.
* @return        Std_ReturnType
*/
Std_ReturnType Eth_Ipw_TxTimeAwareShaperInit ( \
                                    uint8 CtrlIdx, \
                                    const Eth_Ipw_CtrlConfigType *IpwCtrlCfg \
                                    )
{
    (void)CtrlIdx;
    (void)IpwCtrlCfg;
    
    /* Hardware doesn't support this feature */
    return (Std_ReturnType)E_NOT_OK;
    
}

/*================================================================================================*/
/**
* @brief         Configures the controller
* @details       Function
*                -# enables/disables Received frame interrupts
*                -# enables/disables Transmitted frame interrupts
*                -# clears MAC addresses hash tables
*                -# configures the controller MAC address
*                -# configures the MII
*                -# configures RCR and TCR registers
*                -# configures the maximal received frame length
*                -# configures all other registers including unused ones
*                   to prevent corrupted values staying there forever
* @param[in]     CtrlIdx Index of controller which will be configured
*/
Std_ReturnType Eth_Ipw_ConfigureController  ( \
                                    const uint8 CtrlIdx, \
                                    const Eth_Ipw_CtrlConfigType *IpwCtrlCfg, \
                                    const Eth_ClockCfgType *ClkCfg \
                                         )
{
    uint32 Counter;
#if (STD_ON == ETH_GLOBAL_TIME_API)
    Enet_Ip_TimerConfigType SysTimeConfig;
#endif
   
#if ((STD_ON == ETH_DEM_EVENT_DETECT) || (STD_ON == ETH_GLOBAL_TIME_API))
    Eth_Ipw_apxInternalCfg[CtrlIdx] = IpwCtrlCfg;
#endif

#if (STD_ON == ETH_DEM_EVENT_DETECT)
    for (Counter = 0U; Counter < ETH_IPW_MAX_DEM_ERRORS_U32; ++Counter)
    {
        Eth_Ipw_au32DemErrorCounters[CtrlIdx][Counter] = 0U;
    }
#endif

    for (Counter = 0U; Counter < ETH_MAX_RXFIFO_SUPPORTED; ++Counter)
    {
        Eth_Ipw_RxFrameBuffer[CtrlIdx][Counter].Data = NULL_PTR;
    }

    Eth_Ipw_axFirstTxBufferIdxInFifo[CtrlIdx][0U] = 0U;
#if (ETH_MAX_TXFIFO_SUPPORTED > 1U)
    for (Counter = 1U; Counter < IpwCtrlCfg->Eth_Ipw_pEnetCtrlConfig->Enet_pCtrlConfig->TxRingCount; ++Counter)
    {
        Eth_Ipw_axFirstTxBufferIdxInFifo[CtrlIdx][Counter] = Eth_Ipw_axFirstTxBufferIdxInFifo[CtrlIdx][Counter - 1U] +
                                                                   IpwCtrlCfg->Eth_Ipw_pEnetCtrlConfig->Enet_paCtrlTxRingConfig[Counter - 1U].RingSize;
    }
#endif

    Enet_Ip_Init(CtrlIdx, IpwCtrlCfg->Eth_Ipw_pEnetCtrlConfig);

#if (STD_ON == ETH_GLOBAL_TIME_API)
    SysTimeConfig.TimerInc          = (uint8)(ClkCfg->TimeStampClockPeriodPs / 1000U);
    SysTimeConfig.TimerPeriod       = 1000000000U;
    SysTimeConfig.CorrectionPeriod  = 0U;
    SysTimeConfig.CorrectionInc     = 0U;
    Enet_Ip_TimerInit(CtrlIdx, &SysTimeConfig);
#endif

    Enet_Ip_EnableMDIO(CtrlIdx, FALSE, ClkCfg->ModuleClock);
    
#if ((STD_ON == ETH_ENABLE_OFFLOAD_CRC_ICMP) || (STD_ON == ETH_ENABLE_OFFLOAD_CRC_TCP) || (STD_ON == ETH_ENABLE_OFFLOAD_CRC_UDP) || (STD_ON == ETH_ENABLE_OFFLOAD_CRC_IPV4))
    Enet_Ip_EnableTxStoreAndForward(CtrlIdx);
#endif   
 
    return (Std_ReturnType)E_OK;
}

/*================================================================================================*/
/**
* @brief         Starts the controller
* @param[in]     CtrlIdx Index of controller which will be enabled
* @details       Function enables the controller after that it activates receive
*                and transmit buffer descriptors rings.
*/
Std_ReturnType Eth_Ipw_EnableController(const uint8 CtrlIdx)
{
    Enet_Ip_EnableController(CtrlIdx);

    return (Std_ReturnType)E_OK;
}

/*================================================================================================*/
/**
*//*!
* @brief         Safely disables the controller
* @param[in]     u8Ctrl Index of the controller to disable
* @details       Function disables the Ethernet controller and clears all
*                buffers to ensure safe start in the future i.e. no buffer is
*                retransmitted and all received frames are discarded - nothing
*                is received after the controller is disabled.
* @warning       Transmission which is in progress is terminated and frame
*                being transmitted is appended by bad CRC when the
*                Eth_Ipw_DisableController function is called.
*/
Std_ReturnType Eth_Ipw_DisableController(const uint8 CtrlIdx)
{
    Enet_Ip_DisableController(CtrlIdx);
    
    return (Std_ReturnType)E_OK;
}

/*================================================================================================*/
/**
* @brief         Check whether the controller is running
* @details       Function checks the ECR[ETHER_EN] bit to determine whether
*                the controller has been stopped or whether it is running.
* @param[in]     CtrlIdx Index of controller which will be checked active status
* @return        The current controller mode.
* @retval        ETH_MODE_ACTIVE The controller is running.
* @retval        ETH_MODE_DOWN The controller is stopped.
*/
Eth_ModeType Eth_Ipw_GetControllerMode(const uint8 CtrlIdx)
{
    return ((ENET_PSTATE_ACTIVE == Enet_Ip_GetPowerState(CtrlIdx))? (ETH_MODE_ACTIVE) : (ETH_MODE_DOWN));
}

/*================================================================================================*/
/**
* @brief         Returns the indexed controller's MAC address in network byte order.
* @param[in]     CtrlIdx Index of controller to get the PhysAddr
* @return        First four bytes of the MAC address.
*/
void Eth_Ipw_GetPhysicalAddress  ( \
                const uint8 CtrlIdx, \
                uint8 *PhysAddrPtr \
                                 )
{
    Enet_Ip_GetMacAddr(CtrlIdx, PhysAddrPtr);
}

/*================================================================================================*/
/**
* @brief         Update physical address of the controller.
* @param[in]     PhysAddrPtr Pointer to MAC address which should set to
*                controller. The address in network byte order stored into 6
*                bytes of memory.
* @param[in]     CtrlIdx Index of controller to set the PhysAddr
*/
void Eth_Ipw_SetPhysicalAddress ( \
                    const uint8 CtrlIdx, \
                    const uint8 *PhysAddrPtr \
                                )
{
    Enet_Ip_SetMacAddr(CtrlIdx, PhysAddrPtr);
}

/*================================================================================================*/
/**
* @brief         Finds empty Tx buffer and prepares it for loading with data
* @param[in]     CtrlIdx Index of controller to be borrowed buffer
* @param[out]    FifoIdx Fifo Index of the fifo
* @param[out]    BufferIdx DA Index of the buffer
* @param[out]    FrameBuffer data frame's address  
* @param[out]    FrameLength Granted buffer length
* @return        The search status
* @retval        BUFREQ_OK An empty buffer was found and granted.
* @retval        BUFREQ_E_BUSY There is not empty buffer available at the moment.
* @retval        BUFREQ_E_OVFL Length of frame want to transmit over buffer length configured.
*/
BufReq_ReturnType Eth_Ipw_ProvideTxBuffer (  \
                                    const uint8 CtrlIdx, \
                                    const uint8 FifoIdx, \
                                    Eth_BufIdxType * const BufferIdx, \
                                    uint8 **FrameBuffer, \
                                    uint16 * const FrameLength \
                                          )
{
    Enet_Ip_BufferType TxFrameBuffer;
    uint16 u16BufferIdxWithinFifo;
    Enet_Ip_StatusType Status;
    BufReq_ReturnType bufReqStatus;

    /* Populate buffer information */
    TxFrameBuffer.Data   = NULL_PTR;
    TxFrameBuffer.Length = *FrameLength;

    /* Warning: Function "Enet_Ip_GetTxBuff" is not reentrant */
    Status = Enet_Ip_GetTxBuff(CtrlIdx, FifoIdx, &TxFrameBuffer, &u16BufferIdxWithinFifo);
    if (ENET_STATUS_SUCCESS == Status)
    {
        /* Generate a unique buffer id */
        *BufferIdx = Eth_Ipw_axFirstTxBufferIdxInFifo[CtrlIdx][FifoIdx] + u16BufferIdxWithinFifo;
        *FrameBuffer = TxFrameBuffer.Data;
    }

    /* Return available buffer length even in case of BUSY or OVERFLOW */
    *FrameLength = TxFrameBuffer.Length;

    switch (Status)
    {
        case ENET_STATUS_SUCCESS:
        {
            bufReqStatus = BUFREQ_OK;
            break;
        }

        case ENET_STATUS_TX_BUFF_BUSY:
        {
            bufReqStatus = BUFREQ_E_BUSY;
            break;
        }

        case ENET_STATUS_TX_BUFF_OVERFLOW:
        {
            bufReqStatus = BUFREQ_E_OVFL;
            break;
        }

        default:
        {
            bufReqStatus = BUFREQ_E_NOT_OK;
            break;
        }
    }
    
    return bufReqStatus;
}

/*================================================================================================*/
/**
* @brief         Triggers the transmission of the given buffer
* @param[in]     CtrlIdx Index of controller which will be triggered the transmission
* @param[in]     FifoIdx Fifo Index of the fifo to be transmitted
* @param[in]     Length Payload length
*                be confirmed or not
*/
Std_ReturnType Eth_Ipw_Transmit ( \
                                const uint8 CtrlIdx, \
                                const uint8 FifoIdx,  \
                                uint8 *Buffer, \
                                const uint16 Length \
                                )
{
    /* This is only reentrant for different FIFOs, not for different buffer indexes */
    Enet_Ip_BufferType TxFrameBuffer;
    Enet_Ip_StatusType Status;
    Enet_Ip_TxOptionsType TxOptions = {FALSE, FALSE, ENET_CHECKSUM_INSERTION_DISABLE};

    TxFrameBuffer.Data   = Buffer;
    TxFrameBuffer.Length = Length;
    
#if ((((STD_ON == ETH_ENABLE_OFFLOAD_CRC_ICMP) || (STD_ON == ETH_ENABLE_OFFLOAD_CRC_TCP) || (STD_ON == ETH_ENABLE_OFFLOAD_CRC_UDP))) && (STD_ON == ETH_ENABLE_OFFLOAD_CRC_IPV4))
    TxOptions.ChecksumIns = ENET_CHECKSUM_INSERTION_IP_PROTO;
#elif ((STD_ON == ETH_ENABLE_OFFLOAD_CRC_ICMP) || (STD_ON == ETH_ENABLE_OFFLOAD_CRC_TCP) || (STD_ON == ETH_ENABLE_OFFLOAD_CRC_UDP))
    TxOptions.ChecksumIns = ENET_CHECKSUM_INSERTION_PROTO;
#elif (STD_ON == ETH_ENABLE_OFFLOAD_CRC_IPV4)
    TxOptions.ChecksumIns = ENET_CHECKSUM_INSERTION_IP;
#else
    TxOptions.ChecksumIns = ENET_CHECKSUM_INSERTION_DISABLE;
#endif  
   
    Status = Enet_Ip_SendFrame(CtrlIdx, FifoIdx, &TxFrameBuffer, &TxOptions);
    
    return ((ENET_STATUS_SUCCESS == Status)? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK));
}

/*================================================================================================*/
/**
* @brief         Triggers the transmission of the given buffer
* @param[in]     CtrlIdx Index of controller which will be triggered the transmission
* @param[in]     FifoIdx Fifo Index of the fifo
* @param[in]     Buffer Buffer address to be transmitted
* @param[in]     FrameHasError Frame status
*/
Std_ReturnType Eth_Ipw_GetTransmissionStatus(
                                const uint8 CtrlIdx, \
                                const uint8 FifoIdx, \
                                uint8 *Buffer, \
                                boolean *FrameHasError
                            )
{
    Enet_Ip_StatusType Status;
    Enet_Ip_BufferType TxFrameBuffer;

    /* Populate buffer information */
    TxFrameBuffer.Data   = Buffer;

    Status = Enet_Ip_GetTransmitStatus(CtrlIdx, FifoIdx, &TxFrameBuffer, &Eth_Ipw_TxFrameInfo[CtrlIdx][FifoIdx]);
    if (ENET_STATUS_SUCCESS == Status)
    {
        *FrameHasError = ((0U == Eth_Ipw_TxFrameInfo[CtrlIdx][FifoIdx].ErrMask)? ((boolean)FALSE) : ((boolean)TRUE));
    }

    return ((ENET_STATUS_SUCCESS == Status)? ((Std_ReturnType)E_OK) : ((Std_ReturnType)E_NOT_OK));
}

#if STD_ON == ETH_GET_COUNTER_API 
/*================================================================================================*/
/**
* @brief         Reads a list with drop counter values of the corresponding controller.
* @param[in]     CtrlIdx Index of controller within the context of the Ethernet Driver.
* @param[out]    CounterPtr Counter values according to IETF RFC 1757, RFC 1643 and RFC 2233.
* @details       Reads a list with drop counter values of the corresponding controller.
*                The meaning of these values is described at Eth_CounterType.
*/
Std_ReturnType Eth_Ipw_GetCounterValues  ( \
                               uint8 CtrlIdx, \
                               Eth_CounterType *CounterPtr \
                                         )
{
    /* Maximal possible value shall denote an invalid value (e.g. counter not available) */
    /* Warning: All this fumbling on the call stack might have a negative impact on performance.
     *          Execution times shall be measured and compared. */

    CounterPtr->DropPktBufOverrun = (uint32)-1;
    CounterPtr->DropPktCrc        = (uint32)-1;
    CounterPtr->UndersizePkt      = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_UNDERSIZE);
    CounterPtr->OversizePkt       = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_OVERSIZE);
    CounterPtr->AlgnmtErr         = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_RMON_R_CRC_ALIGN);
    CounterPtr->SqeTestErr        = (uint32)-1;
    CounterPtr->DiscInbdPkt       = (uint32)-1;
    CounterPtr->ErrInbdPkt        = (uint32)-1;
    CounterPtr->DiscOtbdPkt       = (uint32)-1;
    CounterPtr->ErrOtbdPkt        = (uint32)-1;
    CounterPtr->SnglCollPkt       = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_IEEE_T_1COL);
    CounterPtr->MultCollPkt       = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_IEEE_T_MCOL);
    CounterPtr->DfrdPkt           = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_IEEE_T_DEF);
    CounterPtr->LatCollPkt        = Enet_Ip_GetCounter(CtrlIdx, ENET_CTR_IEEE_T_LCOL);
    CounterPtr->HwDepCtr0         = (uint32)-1;
    CounterPtr->HwDepCtr1         = (uint32)-1;
    CounterPtr->HwDepCtr2         = (uint32)-1;
    CounterPtr->HwDepCtr3         = (uint32)-1;

    return (Std_ReturnType)E_OK;
}
#endif

#if STD_ON == ETH_MDIO_CLAUSE22_API
/*================================================================================================*/
/**
* @brief         Transfers management data over the MII
* @param[in]     CtrlIdx Index of controller to be transferred
* @param[in]     Trcv Transceiver to communicate with
* @param[in]     Reg Register which shall be accessed
* @param[in,out] Data Written data
* @return        Failure status
* @retval        TRUE Success, no error has occurred.
* @retval        FALSE Failure, no response from the hardware within a timeout.
*/
boolean Eth_Ipw_WriteMii    ( \
                    const uint8 CtrlIdx, \
                    const uint8 Trcv, \
                    const uint8 Reg, \
                    const uint16 Data
                            )
{
    /* 1 millisecond is enough to transfer about 16 MDIO frames at an MDC frequency of 1MHz. */
    return ((ENET_STATUS_SUCCESS == Enet_Ip_MDIOWrite(CtrlIdx, Trcv, Reg, Data, ETH_IPW_TIMEOUT_1MS_U32))? (TRUE) : (FALSE));
}

/*================================================================================================*/
/**
* @brief         Transfers management data over the MII
* @param[in]     CtrlIdx Index of controller to be transferred
* @param[in]     Trcv Transceiver to communicate with
* @param[in]     Reg Register which shall be accessed
* @param[in,out] Data Read data
* @return        Failure status
* @retval        TRUE Success, no error has occurred.
* @retval        FALSE Failure, no response from the hardware within a timeout.
*/
boolean Eth_Ipw_ReadMii ( \
                        const uint8 CtrlIdx, \
                        const uint8 Trcv, \
                        const uint8 Reg, \
                        uint16 * const Data
                        )
{ 
    /* 1 millisecond is enough to transfer about 16 MDIO frames at an MDC frequency of 1MHz. */
    return ((ENET_STATUS_SUCCESS == Enet_Ip_MDIORead(CtrlIdx, Trcv, Reg, Data, ETH_IPW_TIMEOUT_1MS_U32))? (TRUE) : (FALSE));
}
#endif

#if STD_ON == ETH_MDIO_CLAUSE45_API
/*================================================================================================*/
/**
* @brief         Transfers management data over the MII
* @param[in]     CtrlIdx Index of controller to be transferred
* @param[in]     TrcvIdx Transceiver/Port to communicate with
* @param[in]     Mmd Device which shall be accessed
* @param[in]     RegAddress Register address which shall be accessed
* @param[in,out] RegValPtr Readed data from register
* @return        Failure status
* @retval        TRUE Success, no error has occurred.
* @retval        FALSE Failure, no response from the hardware within a timeout.
*/
boolean Eth_Ipw_ReadMmd ( \
                             const uint8 CtrlIdx,\
                             const uint8 TrcvIdx, \
                             const uint8 Mmd, \
                             const uint16 RegAddress,\
                             uint16 * RegValPtr
                        )
{
    /* 1 millisecond is enough to transfer about 8 MMD frames at an MDC frequency of 1MHz. */
    return ((ENET_STATUS_SUCCESS == Enet_Ip_MDIOReadMMD(CtrlIdx, TrcvIdx, Mmd, RegAddress, RegValPtr, ETH_IPW_TIMEOUT_1MS_U32))? (TRUE) : (FALSE));
}

/*================================================================================================*/
/**
* @brief         Transfers management data over the MII
* @param[in]     CtrlIdx Index of controller to be transferred
* @param[in]     TrcvIdx Transceiver/Port to communicate with
* @param[in]     Mmd Device which shall be accessed
* @param[in]     RegAddress Register address which shall be accessed
* @param[in,out] RegVal Data to be written to register
* @return        Failure status
* @retval        TRUE Success, no error has occurred.
* @retval        FALSE Failure, no response from the hardware within a timeout.
*/
boolean Eth_Ipw_WriteMmd ( \
                              const uint8 CtrlIdx,\
                              const uint8 TrcvIdx, \
                              const uint8 Mmd, \
                              const uint16 RegAddress,\
                              const uint16 RegVal
                         )
{
    /* 1 millisecond is enough to transfer about 8 MMD frames at an MDC frequency of 1MHz. */
    return ((ENET_STATUS_SUCCESS == Enet_Ip_MDIOWriteMMD(CtrlIdx, TrcvIdx, Mmd, RegAddress, RegVal, ETH_IPW_TIMEOUT_1MS_U32))? (TRUE) : (FALSE));
}
#endif


/*================================================================================================*/
/**
* @brief         Adds or removes the specified PhysAddr address to or from
*                a multicast address pool in the controller specified by CtrlIdx.
* @param[in]     CtrlIdx Index of controller to be transferred
* @param[in]     PhysAddr Pointer to PHY address which shall be added
*                or removed to or from multicast pool.
*                The address in network byte order stored into 6 bytes of
*                memory.
*/
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER_API

Std_ReturnType Eth_Ipw_UpdatePhysAddrFilter ( \
                                    uint8 CtrlIdx, \
                                    const uint8 *PhysAddr, \
                                    Eth_FilterActionType Action \
                                    )
{
    Std_ReturnType ReturnStatus = (Std_ReturnType)E_NOT_OK;
    
    if (Eth_Ipw_Local_IsOpenFilterPattern(PhysAddr))
    {
        /* Completely opens the physical address filter. */
        if (ETH_ADD_TO_FILTER == Action)
        {
            Enet_Ip_SetMulticastForwardAll(CtrlIdx, TRUE);
        }
        else    /* Don't allow pass all multicast addresses. Recover the filtering. */
        {
            Enet_Ip_RecoverFilter(CtrlIdx);
        }
        ReturnStatus = (Std_ReturnType)E_OK;
    }
    else if (Eth_Ipw_Local_IsCloseFilterPattern(PhysAddr))
    {
        /* Completely closes the physical address filter. */
        if (ETH_ADD_TO_FILTER == Action)
        {
            Enet_Ip_SetMulticastForwardAll(CtrlIdx, FALSE);
        }
        else /* Allow the multicast filtering by hash table. */
        {
            Enet_Ip_RecoverFilter(CtrlIdx);
        }
        ReturnStatus = (Std_ReturnType)E_OK;
    }
    else
    {
        if (Eth_Ipw_Local_IsMulticastAddress(PhysAddr))
        {
            /* Adds a destination address to the physical address filter. */
            if (ETH_ADD_TO_FILTER == Action)
            {
                Enet_Ip_AddDstAddrToHashFilter(CtrlIdx, PhysAddr);
                ReturnStatus = (Std_ReturnType)E_OK;
            }
            else  /* Removes a destination address from the physical address filter. */
            {
                Enet_Ip_RemoveDstAddrFromHashFilter(CtrlIdx, PhysAddr);
                ReturnStatus = (Std_ReturnType)E_OK;
            }
        }
    }
    
    return ReturnStatus;
}
#endif

#define ETH_STOP_SEC_CODE
#include "Eth_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
