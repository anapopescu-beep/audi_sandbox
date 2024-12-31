


/**
 * \file
 *
 * \brief AUTOSAR Com
 *
 * This file contains the implementation of the AUTOSAR
 * module Com.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 1.3 (required)
 *    There shall be no occurrence of undefined or critical unspecified behaviour.
 *
 *    Reason:
 *    The postbuild macro TS_MAKEREF2CFG requires the usage of the
 *    C standard macro 'offsetof'.
 *    According to the C90 standard, the usage of 'offsetof' produces
 *    an undefined behaviour when the member designator parameter
 *    is a bit-field or when it is an invalid right operator of the
 *    '.' operator for the type parameter.
 *    This is not the case here as the parameter of TS_MAKEREF2CFG
 *    is always a member of TS_PB_CFG_LAYOUT_TYPE and bitfields are
 *    never used when defining the postbuild structure members.
 *
 * MISRAC2012-2) Deviated Rule: 11.4 (advisory)
 *    A cast should not be performed between a pointer type and an integral
 *    type.
 *
 *    Reason:
 *    Relocatable postbuild macro requires the cast between pointer and
 *    integral type.
 *
 * MISRAC2012-3) Deviated Rule: 11.9 (required)
 *    The macro NULL shall be the only permitted form of integer null pointer constant.
 *
 *    Reason:
 *    Macros are used in order to check the alignment for different data types.
 *
 */

/*==================[inclusions]=============================================*/

#include <Com_TDK_4G_PBcfg.h>
#include <TSAutosar.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_NAME Com_TDK_4G_ConfigLayout
#define TS_PB_CFG_LAYOUT_TYPE Com_TDK_4G_ConstConfigLayoutType
#include <TSPBConfig_Init.h>

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define COM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <Com_MemMap.h>

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <START> */
Com_TDK_4G_ConstConfigLayoutType Com_TDK_4G_ConfigLayout = {
    { /* Com_RootConfig */
        UINT32_C( 2147485970 ), /* ComPlatformSignature */
        UINT32_C( 698866352 ), /* ComPublicInfoSignature */
        UINT32_C( 1556512666 ), /* ComCfgSignature */
        UINT32_C( 3080501123 ), /* ComLcfgSignature */
        UINT32_C( 0 ), /* ComConfigurationId */
        TS_MAKEREF2CFG( ComRxTimeoutQueueList[0] ), /* ComRxTimeoutQueueListRef */
        TS_MAKENULLREF2CFG, /* ComRxTimeoutSignalQueueListRef */
        TS_MAKENULLREF2CFG, /* ComRxTimeoutSignalGroupQueueListRef */
        TS_MAKEREF2CFG( ComRxIPdu[0] ), /* ComRxIPduRef */
        TS_MAKEREF2CFG( ComTxIPdu[0] ), /* ComTxIPduRef */
        TS_MAKEREF2CFG( ComTxModeNTimes[0] ), /* ComTxModeNTimesRef */
        TS_MAKEREF2CFG( ComTxModePeriodic[0] ), /* ComTxModePeriodicRef */
        TS_MAKENULLREF2CFG, /* ComTxModeMixedNTimesRef */
        TS_MAKEREF2CFG( ComIPduGroupMask[0] ), /* ComIPduGroupMaskRef */
        TS_MAKENULLREF2CFG, /* ComSigGWRxIPduListRef */
        TS_MAKEREF2CFG( ComRxIPduSignalGroupList[0] ), /* ComRxIPduSignalGroupListRef */
        TS_MAKEREF2CFG( ComTxIPduSignalGroupList[0] ), /* ComTxIPduSignalGroupListRef */
        TS_MAKEREF2CFG( ComRxIPduSignalList[0] ), /* ComRxIPduSignalListRef */
        TS_MAKEREF2CFG( ComTxIPduSignalList[0] ), /* ComTxIPduSignalListRef */
        TS_MAKEREF2CFG( ComRxSignalGroup[0] ), /* ComRxSignalGroupRef */
        TS_MAKEREF2CFG( ComTxSignalGroup[0] ), /* ComTxSignalGroupRef */
        TS_MAKENULLREF2CFG, /* ComTxSignalGroupGroupSignalListRef */
        TS_MAKENULLREF2CFG, /* ComFilter8BitMaskRef */
        TS_MAKENULLREF2CFG, /* ComFilter16BitMaskRef */
        TS_MAKENULLREF2CFG, /* ComFilter32BitMaskRef */
        TS_MAKENULLREF2CFG, /* ComFilter8BitMaskXMinMaxRef */
        TS_MAKENULLREF2CFG, /* ComFilter16BitMaskXMinMaxRef */
        TS_MAKENULLREF2CFG, /* ComFilter32BitMaskXMinMaxRef */
        TS_MAKENULLREF2CFG, /* ComFilterOneEveryNRef */
        TS_MAKEREF2CFG( ComRxSignal[0] ), /* ComRxSignalRef */
        TS_MAKEREF2CFG( ComRxSignalExt[0] ), /* ComRxSignalExtRef */
        TS_MAKEREF2CFG( ComTxSignal[0] ), /* ComTxSignalRef */
        TS_MAKEREF2CFG( ComRxTimeoutNotificationList[0] ), /* ComRxTimeoutNotificationRef */
        TS_MAKENULLREF2CFG, /* ComTxTimeoutNotificationRef */
        TS_MAKENULLREF2CFG, /* ComTxErrorNotificationRef */
        TS_MAKENULLREF2CFG, /* ComTxNotificationRef */
        TS_MAKENULLREF2CFG, /* ComGWSourceRef */
        TS_MAKENULLREF2CFG, /* ComGWDestinationRef */
        UINT16_C( 474 ), /* ComRxIPduStatusBase */
        UINT16_C( 478 ), /* ComTxIPduStatusBase */
        UINT16_C( 16 ), /* ComRxIPduLengthBase */
        UINT16_C( 24 ), /* ComTxIPduLengthBase */
        UINT16_C( 483 ), /* ComTxSignalGroupStatusBase */
        UINT16_C( 0 ), /* ComBufferBaseUInt32 */
        UINT16_C( 0 ), /* ComBufferBaseSInt32 */
        UINT16_C( 0 ), /* ComBufferBaseUInt16 */
        UINT16_C( 0 ), /* ComBufferBaseSInt16 */
        UINT16_C( 0 ), /* ComBufferBaseUInt8 */
        UINT16_C( 0 ), /* ComBufferBaseSInt8 */
        UINT16_C( 0 ), /* ComBufferBaseBool */
        UINT16_C( 0 ), /* ComFilterOneEveryNBase */
        UINT16_C( 0 ), /* ComSigGWRxPduFlagBase */
        UINT16_C( 0 ), /* ComSigGWTxSignalGroupQueueBase */
        UINT16_C( 0 ), /* ComSigGWTxSignalGroupQueueMax */
        UINT16_C( 0 ), /* ComMDTQueueBase */
        UINT16_C( 0 ), /* ComMDTQueueMax */
        UINT16_C( 0 ), /* ComPeriodicQueueBase */
        UINT16_C( 1 ), /* ComPeriodicQueueMax */
        UINT16_C( 2 ), /* ComNTimesQueueBaseNextTime */
        UINT16_C( 486 ), /* ComNTimesQueueBaseRemaining */
        UINT16_C( 4 ), /* ComNTimesQueueMax */
        UINT16_C( 10 ), /* ComRxTimeoutQueueBase */
        UINT16_C( 3 ), /* ComRxTimeoutQueueMax */
        UINT16_C( 0 ), /* ComRxTimeoutSignalQueueBase */
        UINT16_C( 0 ), /* ComRxTimeoutSignalStatusQueueBase */
        UINT16_C( 0 ), /* ComRxTimeoutSignalQueueMax */
        UINT16_C( 0 ), /* ComRxDMInvSignalGroupStatusQueueBase */
        UINT16_C( 0 ), /* ComRxTimeoutSignalGroupQueueBase */
        UINT16_C( 0 ), /* ComRxTimeoutSignalGroupQueueMax */
        UINT16_C( 0 ), /* ComTxTimeoutQueueBase */
        UINT16_C( 0 ), /* ComTxTimeoutQueueMax */
        UINT16_C( 490 ), /* ComCbkTxAckDeferredStatusBase */
        UINT16_C( 1 ), /* ComCbkTxAckDeferredListMax */
        UINT16_C( 4 ), /* ComRxIPduArraySize */
        UINT16_C( 5 ), /* ComTxIPduArraySize */
        UINT16_C( 51 ), /* ComRxSignalArraySize */
        UINT16_C( 46 ), /* ComTxSignalArraySize */
        UINT16_C( 0 ), /* ComFilterOneEveryNArraySize */
        UINT16_C( 32 ), /* ComIPduGroupsNum */
        UINT16_C( 1 ), /* ComRxIpduGroupVectorByteEnd */
        UINT16_C( 3 ), /* ComTxIpduGroupVectorByteStart */
        UINT16_C( 0 ), /* ComSigGWRxIPduArraySize */
        UINT16_C( 3 ), /* ComTxSignalGroupArraySize */
        UINT16_C( 1 ) /* ComRxSignalGroupArraySize */
    },
    { /* ComRxIPdu */
        { /* ComRxIPdu[0] -- PDipdu_Airbag_01_64R */
            TS_MAKEREF2CFG( ComIPduInit[0] ), /* ComInitValueRef */
            TS_MAKEREF2CFG( ComIPduInit[0] ), /* ComTimeoutValueRef */
            UINT16_C( 0 ), /* ComIPduGroupMaskRef */
            UINT16_C( 8 ), /* ComIPduInitSize */
            UINT16_C( 8 ), /* ComIPduSizeMax */
            UINT16_C( 34 ), /* ComIPduValueRef */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefFirst */
            UINT16_C( 31 ), /* ComIPduSignalRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithBufferRefNum */
            UINT16_C( 2 ), /* ComIPduSignalW_F_A_NotiRefNum */
            UINT16_C( 2 ), /* ComIPduSignalWithDMOnly */
            UINT16_C( 0 ), /* ComIPduSignalRefFirst */
            UINT16_C( 65535 ), /* ComIPduCallOutFuncPtrRef */
            UINT16_C( 0 ), /* ComRxTimeoutNotificationFirst */
            UINT16_C( 30 ), /* ComRxTimeoutNotificationNum */
            UINT16_C( 200 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 200 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 0 ), /* RxDMQueueRef */
            UINT16_C( 65535 ), /* ComIPduSigGWFlagBit */
            UINT16_C( 0 ), /* ComIPduGWSourceRefNum */
            UINT16_C( 0 ), /* ComIPduGWSourceRefFirst */
            UINT16_C( 8 ), /* ComIPduTimeoutSize */
            UINT8_C( 2 ) /* ComRxIPduFlags -- COM_DYN_IPDU_OFF | COM_RX_DM_ON | DEFERRED */
        },
        { /* ComRxIPdu[1] -- PDipdu_Airbag_02_1312R */
            TS_MAKEREF2CFG( ComIPduInit[8] ), /* ComInitValueRef */
            TS_MAKEREF2CFG( ComIPduInit[8] ), /* ComTimeoutValueRef */
            UINT16_C( 0 ), /* ComIPduGroupMaskRef */
            UINT16_C( 8 ), /* ComIPduInitSize */
            UINT16_C( 8 ), /* ComIPduSizeMax */
            UINT16_C( 42 ), /* ComIPduValueRef */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefFirst */
            UINT16_C( 6 ), /* ComIPduSignalRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithBufferRefNum */
            UINT16_C( 6 ), /* ComIPduSignalW_F_A_NotiRefNum */
            UINT16_C( 6 ), /* ComIPduSignalWithDMOnly */
            UINT16_C( 31 ), /* ComIPduSignalRefFirst */
            UINT16_C( 65535 ), /* ComIPduCallOutFuncPtrRef */
            UINT16_C( 30 ), /* ComRxTimeoutNotificationFirst */
            UINT16_C( 6 ), /* ComRxTimeoutNotificationNum */
            UINT16_C( 200 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 200 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 1 ), /* RxDMQueueRef */
            UINT16_C( 65535 ), /* ComIPduSigGWFlagBit */
            UINT16_C( 0 ), /* ComIPduGWSourceRefNum */
            UINT16_C( 0 ), /* ComIPduGWSourceRefFirst */
            UINT16_C( 8 ), /* ComIPduTimeoutSize */
            UINT8_C( 2 ) /* ComRxIPduFlags -- COM_DYN_IPDU_OFF | COM_RX_DM_ON | DEFERRED */
        },
        { /* ComRxIPdu[2] -- PDipdu_Airbag_eCS_01_184112401R */
            TS_MAKEREF2CFG( ComIPduInit[16] ), /* ComInitValueRef */
            TS_MAKEREF2CFG( ComIPduInit[16] ), /* ComTimeoutValueRef */
            UINT16_C( 0 ), /* ComIPduGroupMaskRef */
            UINT16_C( 8 ), /* ComIPduInitSize */
            UINT16_C( 8 ), /* ComIPduSizeMax */
            UINT16_C( 50 ), /* ComIPduValueRef */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefFirst */
            UINT16_C( 6 ), /* ComIPduSignalRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithBufferRefNum */
            UINT16_C( 6 ), /* ComIPduSignalW_F_A_NotiRefNum */
            UINT16_C( 6 ), /* ComIPduSignalWithDMOnly */
            UINT16_C( 37 ), /* ComIPduSignalRefFirst */
            UINT16_C( 65535 ), /* ComIPduCallOutFuncPtrRef */
            UINT16_C( 36 ), /* ComRxTimeoutNotificationFirst */
            UINT16_C( 6 ), /* ComRxTimeoutNotificationNum */
            UINT16_C( 200 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 200 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 2 ), /* RxDMQueueRef */
            UINT16_C( 65535 ), /* ComIPduSigGWFlagBit */
            UINT16_C( 0 ), /* ComIPduGWSourceRefNum */
            UINT16_C( 0 ), /* ComIPduGWSourceRefFirst */
            UINT16_C( 8 ), /* ComIPduTimeoutSize */
            UINT8_C( 2 ) /* ComRxIPduFlags -- COM_DYN_IPDU_OFF | COM_RX_DM_ON | DEFERRED */
        },
        { /* ComRxIPdu[3] -- PDIPdu_Gliwa_In_300R */
            TS_MAKEREF2CFG( ComIPduInit[16] ), /* ComInitValueRef */
            TS_MAKEREF2CFG( ComIPduInit[16] ), /* ComTimeoutValueRef */
            UINT16_C( 0 ), /* ComIPduGroupMaskRef */
            UINT16_C( 8 ), /* ComIPduInitSize */
            UINT16_C( 8 ), /* ComIPduSizeMax */
            UINT16_C( 58 ), /* ComIPduValueRef */
            UINT16_C( 1 ), /* ComIPduSignalGroupRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefFirst */
            UINT16_C( 0 ), /* ComIPduSignalRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithBufferRefNum */
            UINT16_C( 0 ), /* ComIPduSignalW_F_A_NotiRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithDMOnly */
            UINT16_C( 43 ), /* ComIPduSignalRefFirst */
            UINT16_C( 65535 ), /* ComIPduCallOutFuncPtrRef */
            UINT16_C( 42 ), /* ComRxTimeoutNotificationFirst */
            UINT16_C( 0 ), /* ComRxTimeoutNotificationNum */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxDMQueueRef */
            UINT16_C( 65535 ), /* ComIPduSigGWFlagBit */
            UINT16_C( 0 ), /* ComIPduGWSourceRefNum */
            UINT16_C( 0 ), /* ComIPduGWSourceRefFirst */
            UINT16_C( 8 ), /* ComIPduTimeoutSize */
            UINT8_C( 1 ) /* ComRxIPduFlags -- COM_DYN_IPDU_OFF | COM_RX_DM_OFF | IMMEDIATE */
        }
    },
    { /* ComTxIPdu */
        { /* ComTxIPdu[0] -- PDIPdu_Gliwa_Out_200T */
            TS_MAKEREF2CFG( ComIPduInit[24] ), /* ComInitValueRef */
            TS_MAKENULLREF2CFG, /* ComIPduTMSFlagsInitValueRef */
            UINT16_C( 1 ), /* ComIPduGroupMaskRef */
            UINT16_C( 64 ), /* ComIPduInitSize */
            UINT16_C( 64 ), /* ComIPduSizeMax */
            UINT16_C( 3 ), /* PduRTxPduId */
            UINT16_C( 74 ), /* ComIPduValueRef */
            UINT16_C( 1 ), /* ComIPduSignalGroupRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefFirst */
            UINT16_C( 0 ), /* ComIPduSignalRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithFilterRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupWithFilterRefNum */
            UINT16_C( 0 ), /* ComIPduTMSFlagsRef */
            UINT16_C( 0 ), /* ComIPduSignalRefFirst */
            UINT16_C( 65535 ), /* ComIPduCallOutFuncPtrRef */
            UINT16_C( 65535 ), /* ComIPduTrigTxCallOutFuncPtrRef */
            UINT16_C( 0 ), /* ComTxIPduMinimumDelayTimeFactorValue */
            UINT16_C( 65535 ), /* MDTQueueRef */
            UINT16_C( 0 ), /* ComTxModeTrueRef */
            UINT16_C( 65535 ), /* ComTxModeFalseRef */
            UINT16_C( 0 ), /* PeriodicQueueRef */
            UINT16_C( 0 ), /* NTimesQueueRef */
            UINT16_C( 0 ), /* ComTxTimeoutNotificationFirst */
            UINT16_C( 0 ), /* ComTxTimeoutNotificationNum */
            UINT16_C( 0 ), /* ComTxTimeoutFactorValue */
            UINT16_C( 65535 ), /* TxDMQueueRef */
            UINT16_C( 0 ), /* ComNotificationFirst */
            UINT16_C( 0 ), /* ComNotificationNum */
            UINT16_C( 0 ), /* ComNotificationDeferredQueueRef */
            UINT8_C( 29 ), /* ComTxIPduFlags -- COM_DYN_IPDU_OFF | COM_CL_UB_NEVER | TM_TRUE | COM_TX_DM_OFF | IMMEDIATE */
            UINT8_C( 5 ) /* ComTxModeModes -- True=N_TIMES,False=<undef> */
        },
        { /* ComTxIPdu[1] -- PDIPdu_Dev_Out_0_256T */
            TS_MAKEREF2CFG( ComIPduInit[24] ), /* ComInitValueRef */
            TS_MAKENULLREF2CFG, /* ComIPduTMSFlagsInitValueRef */
            UINT16_C( 1 ), /* ComIPduGroupMaskRef */
            UINT16_C( 64 ), /* ComIPduInitSize */
            UINT16_C( 64 ), /* ComIPduSizeMax */
            UINT16_C( 0 ), /* PduRTxPduId */
            UINT16_C( 202 ), /* ComIPduValueRef */
            UINT16_C( 1 ), /* ComIPduSignalGroupRefNum */
            UINT16_C( 1 ), /* ComIPduSignalGroupRefFirst */
            UINT16_C( 0 ), /* ComIPduSignalRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithFilterRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupWithFilterRefNum */
            UINT16_C( 0 ), /* ComIPduTMSFlagsRef */
            UINT16_C( 0 ), /* ComIPduSignalRefFirst */
            UINT16_C( 65535 ), /* ComIPduCallOutFuncPtrRef */
            UINT16_C( 65535 ), /* ComIPduTrigTxCallOutFuncPtrRef */
            UINT16_C( 0 ), /* ComTxIPduMinimumDelayTimeFactorValue */
            UINT16_C( 65535 ), /* MDTQueueRef */
            UINT16_C( 0 ), /* ComTxModeTrueRef */
            UINT16_C( 65535 ), /* ComTxModeFalseRef */
            UINT16_C( 0 ), /* PeriodicQueueRef */
            UINT16_C( 1 ), /* NTimesQueueRef */
            UINT16_C( 0 ), /* ComTxTimeoutNotificationFirst */
            UINT16_C( 0 ), /* ComTxTimeoutNotificationNum */
            UINT16_C( 0 ), /* ComTxTimeoutFactorValue */
            UINT16_C( 65535 ), /* TxDMQueueRef */
            UINT16_C( 0 ), /* ComNotificationFirst */
            UINT16_C( 0 ), /* ComNotificationNum */
            UINT16_C( 0 ), /* ComNotificationDeferredQueueRef */
            UINT8_C( 29 ), /* ComTxIPduFlags -- COM_DYN_IPDU_OFF | COM_CL_UB_NEVER | TM_TRUE | COM_TX_DM_OFF | IMMEDIATE */
            UINT8_C( 5 ) /* ComTxModeModes -- True=N_TIMES,False=<undef> */
        },
        { /* ComTxIPdu[2] -- PDIPdu_MFData_1988T */
            TS_MAKEREF2CFG( ComIPduInit[24] ), /* ComInitValueRef */
            TS_MAKENULLREF2CFG, /* ComIPduTMSFlagsInitValueRef */
            UINT16_C( 1 ), /* ComIPduGroupMaskRef */
            UINT16_C( 64 ), /* ComIPduInitSize */
            UINT16_C( 64 ), /* ComIPduSizeMax */
            UINT16_C( 1 ), /* PduRTxPduId */
            UINT16_C( 330 ), /* ComIPduValueRef */
            UINT16_C( 1 ), /* ComIPduSignalGroupRefNum */
            UINT16_C( 2 ), /* ComIPduSignalGroupRefFirst */
            UINT16_C( 0 ), /* ComIPduSignalRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithFilterRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupWithFilterRefNum */
            UINT16_C( 0 ), /* ComIPduTMSFlagsRef */
            UINT16_C( 0 ), /* ComIPduSignalRefFirst */
            UINT16_C( 65535 ), /* ComIPduCallOutFuncPtrRef */
            UINT16_C( 65535 ), /* ComIPduTrigTxCallOutFuncPtrRef */
            UINT16_C( 0 ), /* ComTxIPduMinimumDelayTimeFactorValue */
            UINT16_C( 65535 ), /* MDTQueueRef */
            UINT16_C( 0 ), /* ComTxModeTrueRef */
            UINT16_C( 65535 ), /* ComTxModeFalseRef */
            UINT16_C( 0 ), /* PeriodicQueueRef */
            UINT16_C( 2 ), /* NTimesQueueRef */
            UINT16_C( 0 ), /* ComTxTimeoutNotificationFirst */
            UINT16_C( 0 ), /* ComTxTimeoutNotificationNum */
            UINT16_C( 0 ), /* ComTxTimeoutFactorValue */
            UINT16_C( 65535 ), /* TxDMQueueRef */
            UINT16_C( 0 ), /* ComNotificationFirst */
            UINT16_C( 0 ), /* ComNotificationNum */
            UINT16_C( 0 ), /* ComNotificationDeferredQueueRef */
            UINT8_C( 29 ), /* ComTxIPduFlags -- COM_DYN_IPDU_OFF | COM_CL_UB_NEVER | TM_TRUE | COM_TX_DM_OFF | IMMEDIATE */
            UINT8_C( 5 ) /* ComTxModeModes -- True=N_TIMES,False=<undef> */
        },
        { /* ComTxIPdu[3] -- PDIPdu_MFData_Logger_1989T */
            TS_MAKEREF2CFG( ComIPduInit[80] ), /* ComInitValueRef */
            TS_MAKENULLREF2CFG, /* ComIPduTMSFlagsInitValueRef */
            UINT16_C( 2 ), /* ComIPduGroupMaskRef */
            UINT16_C( 8 ), /* ComIPduInitSize */
            UINT16_C( 8 ), /* ComIPduSizeMax */
            UINT16_C( 4 ), /* PduRTxPduId */
            UINT16_C( 458 ), /* ComIPduValueRef */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefNum */
            UINT16_C( 3 ), /* ComIPduSignalGroupRefFirst */
            UINT16_C( 1 ), /* ComIPduSignalRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithFilterRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupWithFilterRefNum */
            UINT16_C( 0 ), /* ComIPduTMSFlagsRef */
            UINT16_C( 0 ), /* ComIPduSignalRefFirst */
            UINT16_C( 65535 ), /* ComIPduCallOutFuncPtrRef */
            UINT16_C( 65535 ), /* ComIPduTrigTxCallOutFuncPtrRef */
            UINT16_C( 0 ), /* ComTxIPduMinimumDelayTimeFactorValue */
            UINT16_C( 65535 ), /* MDTQueueRef */
            UINT16_C( 0 ), /* ComTxModeTrueRef */
            UINT16_C( 65535 ), /* ComTxModeFalseRef */
            UINT16_C( 0 ), /* PeriodicQueueRef */
            UINT16_C( 3 ), /* NTimesQueueRef */
            UINT16_C( 0 ), /* ComTxTimeoutNotificationFirst */
            UINT16_C( 0 ), /* ComTxTimeoutNotificationNum */
            UINT16_C( 0 ), /* ComTxTimeoutFactorValue */
            UINT16_C( 65535 ), /* TxDMQueueRef */
            UINT16_C( 0 ), /* ComNotificationFirst */
            UINT16_C( 0 ), /* ComNotificationNum */
            UINT16_C( 0 ), /* ComNotificationDeferredQueueRef */
            UINT8_C( 29 ), /* ComTxIPduFlags -- COM_DYN_IPDU_OFF | COM_CL_UB_NEVER | TM_TRUE | COM_TX_DM_OFF | IMMEDIATE */
            UINT8_C( 5 ) /* ComTxModeModes -- True=N_TIMES,False=<undef> */
        },
        { /* ComTxIPdu[4] -- PDipdu_eCS_01_184112400T */
            TS_MAKEREF2CFG( ComIPduInit[88] ), /* ComInitValueRef */
            TS_MAKENULLREF2CFG, /* ComIPduTMSFlagsInitValueRef */
            UINT16_C( 1 ), /* ComIPduGroupMaskRef */
            UINT16_C( 8 ), /* ComIPduInitSize */
            UINT16_C( 8 ), /* ComIPduSizeMax */
            UINT16_C( 2 ), /* PduRTxPduId */
            UINT16_C( 466 ), /* ComIPduValueRef */
            UINT16_C( 0 ), /* ComIPduSignalGroupRefNum */
            UINT16_C( 3 ), /* ComIPduSignalGroupRefFirst */
            UINT16_C( 21 ), /* ComIPduSignalRefNum */
            UINT16_C( 0 ), /* ComIPduSignalWithFilterRefNum */
            UINT16_C( 0 ), /* ComIPduSignalGroupWithFilterRefNum */
            UINT16_C( 0 ), /* ComIPduTMSFlagsRef */
            UINT16_C( 1 ), /* ComIPduSignalRefFirst */
            UINT16_C( 65535 ), /* ComIPduCallOutFuncPtrRef */
            UINT16_C( 65535 ), /* ComIPduTrigTxCallOutFuncPtrRef */
            UINT16_C( 0 ), /* ComTxIPduMinimumDelayTimeFactorValue */
            UINT16_C( 65535 ), /* MDTQueueRef */
            UINT16_C( 0 ), /* ComTxModeTrueRef */
            UINT16_C( 65535 ), /* ComTxModeFalseRef */
            UINT16_C( 0 ), /* PeriodicQueueRef */
            UINT16_C( 0 ), /* NTimesQueueRef */
            UINT16_C( 0 ), /* ComTxTimeoutNotificationFirst */
            UINT16_C( 0 ), /* ComTxTimeoutNotificationNum */
            UINT16_C( 0 ), /* ComTxTimeoutFactorValue */
            UINT16_C( 65535 ), /* TxDMQueueRef */
            UINT16_C( 0 ), /* ComNotificationFirst */
            UINT16_C( 0 ), /* ComNotificationNum */
            UINT16_C( 0 ), /* ComNotificationDeferredQueueRef */
            UINT8_C( 28 ), /* ComTxIPduFlags -- COM_DYN_IPDU_OFF | COM_CL_UB_NEVER | TM_TRUE | COM_TX_DM_OFF | DEFERRED */
            UINT8_C( 1 ) /* ComTxModeModes -- True=PERIODIC,False=<undef> */
        }
    },
    { /* ComTxSignalGroup */
        { /* ComTxSignalGroup[0] -- GRDataOutSignalGroup_0_256T */
            TS_MAKENULLREF2CFG, /* ComSignalGTMSFlagsInitValueRef */
            TS_MAKENULLREF2CFG, /* ComTOCMaskRef */
            TS_MAKENULLREF2CFG, /* ComWriteMaskRef */
            UINT16_C( 1 ), /* ComIPduRef */
            UINT16_C( 0 ), /* ComSignalPositionInByte */
            UINT16_C( 64 ), /* ComByteSize */
            UINT16_C( 266 ), /* ComSignalGroupValueRef */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 0 ), /* ComGroupSignalWithFilterRefNum */
            UINT16_C( 65535 ), /* ComSignalGTMSFlagsRef */
            UINT16_C( 0 ), /* ComPositionOfTMSFlag */
            UINT16_C( 0 ), /* ComGroupSignalRefFirst */
            UINT8_C( 17 ) /* ComTxSignalGroupFlags -- COM_INIT_BUFFER | COM_UPDATE_BIT_ABSENT | TRIGGERED */
        },
        { /* ComTxSignalGroup[1] -- GRMeasurementFrameGroup_1988T */
            TS_MAKENULLREF2CFG, /* ComSignalGTMSFlagsInitValueRef */
            TS_MAKENULLREF2CFG, /* ComTOCMaskRef */
            TS_MAKENULLREF2CFG, /* ComWriteMaskRef */
            UINT16_C( 2 ), /* ComIPduRef */
            UINT16_C( 0 ), /* ComSignalPositionInByte */
            UINT16_C( 64 ), /* ComByteSize */
            UINT16_C( 394 ), /* ComSignalGroupValueRef */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 0 ), /* ComGroupSignalWithFilterRefNum */
            UINT16_C( 65535 ), /* ComSignalGTMSFlagsRef */
            UINT16_C( 0 ), /* ComPositionOfTMSFlag */
            UINT16_C( 0 ), /* ComGroupSignalRefFirst */
            UINT8_C( 17 ) /* ComTxSignalGroupFlags -- COM_INIT_BUFFER | COM_UPDATE_BIT_ABSENT | TRIGGERED */
        },
        { /* ComTxSignalGroup[2] -- GRGliwaOutGroup_200T */
            TS_MAKENULLREF2CFG, /* ComSignalGTMSFlagsInitValueRef */
            TS_MAKENULLREF2CFG, /* ComTOCMaskRef */
            TS_MAKENULLREF2CFG, /* ComWriteMaskRef */
            UINT16_C( 0 ), /* ComIPduRef */
            UINT16_C( 0 ), /* ComSignalPositionInByte */
            UINT16_C( 64 ), /* ComByteSize */
            UINT16_C( 138 ), /* ComSignalGroupValueRef */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 0 ), /* ComGroupSignalWithFilterRefNum */
            UINT16_C( 65535 ), /* ComSignalGTMSFlagsRef */
            UINT16_C( 0 ), /* ComPositionOfTMSFlag */
            UINT16_C( 0 ), /* ComGroupSignalRefFirst */
            UINT8_C( 17 ) /* ComTxSignalGroupFlags -- COM_INIT_BUFFER | COM_UPDATE_BIT_ABSENT | TRIGGERED */
        }
    },
    { /* ComTxModeNTimes */
        { /* ComTxModeNTimes[0] */
            UINT16_C( 200 ), /* ComTxModeRepetitionPeriodFactor */
            UINT8_C( 1 ) /* ComTxModeNumberOfRepetitions */
        }
    },
    { /* ComTxModePeriodic */
        { /* ComTxModePeriodic[0] */
            UINT16_C( 1 ), /* ComTxModeTimeOffsetFactor */
            UINT16_C( 10 ) /* ComTxModeTimePeriodFactor */
        }
    },
    { /* ComRxIPduSignalGroupList */
        UINT16_C( 0 ) /* ComRxIPduSignalGroupList[0] */
    },
    { /* ComTxIPduSignalGroupList */
        UINT16_C( 2 ), /* ComTxIPduSignalGroupList[0] */
        UINT16_C( 0 ), /* ComTxIPduSignalGroupList[1] */
        UINT16_C( 1 ) /* ComTxIPduSignalGroupList[2] */
    },
    { /* ComRxIPduSignalList */
        UINT16_C( 0 ), /* ComRxIPduSignalList[0] */
        UINT16_C( 1 ), /* ComRxIPduSignalList[1] */
        UINT16_C( 2 ), /* ComRxIPduSignalList[2] */
        UINT16_C( 3 ), /* ComRxIPduSignalList[3] */
        UINT16_C( 4 ), /* ComRxIPduSignalList[4] */
        UINT16_C( 5 ), /* ComRxIPduSignalList[5] */
        UINT16_C( 6 ), /* ComRxIPduSignalList[6] */
        UINT16_C( 7 ), /* ComRxIPduSignalList[7] */
        UINT16_C( 8 ), /* ComRxIPduSignalList[8] */
        UINT16_C( 9 ), /* ComRxIPduSignalList[9] */
        UINT16_C( 10 ), /* ComRxIPduSignalList[10] */
        UINT16_C( 11 ), /* ComRxIPduSignalList[11] */
        UINT16_C( 12 ), /* ComRxIPduSignalList[12] */
        UINT16_C( 13 ), /* ComRxIPduSignalList[13] */
        UINT16_C( 14 ), /* ComRxIPduSignalList[14] */
        UINT16_C( 15 ), /* ComRxIPduSignalList[15] */
        UINT16_C( 16 ), /* ComRxIPduSignalList[16] */
        UINT16_C( 17 ), /* ComRxIPduSignalList[17] */
        UINT16_C( 18 ), /* ComRxIPduSignalList[18] */
        UINT16_C( 19 ), /* ComRxIPduSignalList[19] */
        UINT16_C( 20 ), /* ComRxIPduSignalList[20] */
        UINT16_C( 21 ), /* ComRxIPduSignalList[21] */
        UINT16_C( 22 ), /* ComRxIPduSignalList[22] */
        UINT16_C( 23 ), /* ComRxIPduSignalList[23] */
        UINT16_C( 24 ), /* ComRxIPduSignalList[24] */
        UINT16_C( 25 ), /* ComRxIPduSignalList[25] */
        UINT16_C( 26 ), /* ComRxIPduSignalList[26] */
        UINT16_C( 27 ), /* ComRxIPduSignalList[27] */
        UINT16_C( 28 ), /* ComRxIPduSignalList[28] */
        UINT16_C( 29 ), /* ComRxIPduSignalList[29] */
        UINT16_C( 30 ), /* ComRxIPduSignalList[30] */
        UINT16_C( 31 ), /* ComRxIPduSignalList[31] */
        UINT16_C( 32 ), /* ComRxIPduSignalList[32] */
        UINT16_C( 33 ), /* ComRxIPduSignalList[33] */
        UINT16_C( 34 ), /* ComRxIPduSignalList[34] */
        UINT16_C( 35 ), /* ComRxIPduSignalList[35] */
        UINT16_C( 36 ), /* ComRxIPduSignalList[36] */
        UINT16_C( 37 ), /* ComRxIPduSignalList[37] */
        UINT16_C( 38 ), /* ComRxIPduSignalList[38] */
        UINT16_C( 39 ), /* ComRxIPduSignalList[39] */
        UINT16_C( 40 ), /* ComRxIPduSignalList[40] */
        UINT16_C( 42 ), /* ComRxIPduSignalList[41] */
        UINT16_C( 41 ) /* ComRxIPduSignalList[42] */
    },
    { /* ComTxIPduSignalList */
        UINT16_C( 0 ), /* ComTxIPduSignalList[0] */
        UINT16_C( 1 ), /* ComTxIPduSignalList[1] */
        UINT16_C( 2 ), /* ComTxIPduSignalList[2] */
        UINT16_C( 3 ), /* ComTxIPduSignalList[3] */
        UINT16_C( 4 ), /* ComTxIPduSignalList[4] */
        UINT16_C( 5 ), /* ComTxIPduSignalList[5] */
        UINT16_C( 6 ), /* ComTxIPduSignalList[6] */
        UINT16_C( 7 ), /* ComTxIPduSignalList[7] */
        UINT16_C( 8 ), /* ComTxIPduSignalList[8] */
        UINT16_C( 9 ), /* ComTxIPduSignalList[9] */
        UINT16_C( 10 ), /* ComTxIPduSignalList[10] */
        UINT16_C( 11 ), /* ComTxIPduSignalList[11] */
        UINT16_C( 12 ), /* ComTxIPduSignalList[12] */
        UINT16_C( 13 ), /* ComTxIPduSignalList[13] */
        UINT16_C( 14 ), /* ComTxIPduSignalList[14] */
        UINT16_C( 15 ), /* ComTxIPduSignalList[15] */
        UINT16_C( 16 ), /* ComTxIPduSignalList[16] */
        UINT16_C( 17 ), /* ComTxIPduSignalList[17] */
        UINT16_C( 18 ), /* ComTxIPduSignalList[18] */
        UINT16_C( 19 ), /* ComTxIPduSignalList[19] */
        UINT16_C( 20 ), /* ComTxIPduSignalList[20] */
        UINT16_C( 21 ) /* ComTxIPduSignalList[21] */
    },
    { /* ComRxSignalGroup */
        { /* ComRxSignalGroup[0] -- GRGliwaInGroup_300R */
            UINT16_C( 3 ), /* ComIPduRef */
            UINT16_C( 66 ), /* ComSignalGroupValueRef */
            UINT16_C( 0 ), /* ComSignalPositionInByte */
            UINT16_C( 8 ), /* ComByteSize */
            UINT16_C( 43 ) /* ComSignalExtRef */
        }
    },
    { /* ComRxSignal */
        { /* ComRxSignal[0] -- SGis_AB_Anzeige_Fussg1_64R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 35 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 0 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[1] -- SGis_AB_Belegung_VF1_64R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 48 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 1 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[2] -- SGis_AB_Crash_Int1_64R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 23 ), /* ComSignalPositionInBit */
                UINT16_C( 3 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 2 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[3] -- SGis_AB_Deaktiviert1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 25 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 3 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[4] -- SGis_AB_Deaktivierung_HV1_64R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 44 ), /* ComSignalPositionInBit */
                UINT16_C( 3 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 4 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[5] -- SGis_AB_Diagnose1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 28 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 5 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[6] -- SGis_AB_EDR_Trigger1_64R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 46 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 6 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[7] -- SGis_AB_Erh_Auf_VB1_64R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 31 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 7 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[8] -- SGis_AB_Front_Crash1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 16 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 8 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[9] -- SGis_AB_Gurtschloss_FA_ext1_64R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 51 ), /* ComSignalPositionInBit */
                UINT16_C( 3 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 9 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[10] -- SGis_AB_Gurtschloss_FA_ext_aktiv1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 52 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 10 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[11] -- SGis_AB_Gurtwarn_VB1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 33 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 11 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[12] -- SGis_AB_Gurtwarn_VF1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 32 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 12 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[13] -- SGis_AB_Heck_Crash1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 17 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 13 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[14] -- SGis_AB_Lampe1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 24 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 14 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[15] -- SGis_AB_MKB_Anforderung1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 40 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 15 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[16] -- SGis_AB_MKB_gueltig1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 39 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 16 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[17] -- SGis_AB_PAO_Leuchte_Anf1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 38 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 17 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[18] -- SGis_AB_RGS_Anst1_64R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 15 ), /* ComSignalPositionInBit */
                UINT16_C( 4 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 18 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[19] -- SGis_AB_Rollover_Crash1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 20 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 19 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[20] -- SGis_AB_SB_Crash1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 19 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 20 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[21] -- SGis_AB_SF_Crash1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 18 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 21 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[22] -- SGis_AB_Stellgliedtest1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 29 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 22 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[23] -- SGis_AB_Systemfehler1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 27 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 23 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[24] -- SGis_AB_Texte_AKS1_64R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 37 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 24 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[25] -- SGis_AB_VB_deaktiviert1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 26 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 25 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[26] -- SGis_AB_Versorgungsspannung1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 41 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 26 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[27] -- SGis_AB_eCS_Error1_64R */
            { /* ComSignalBase */
                UINT16_C( 650 ), /* ComRxSignalFlags -- UINT32 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_32 */
                UINT16_C( 53 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 27 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[28] -- SGis_ASM_Masterzeit_021_64R */
            { /* ComSignalBase */
                UINT16_C( 809 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_EL */
                UINT16_C( 7 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 28 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[29] -- SGis_Airbag_01_BZ1_64R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 11 ), /* ComSignalPositionInBit */
                UINT16_C( 4 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 29 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[30] -- SGis_Airbag_01_CRC1_64R */
            { /* ComSignalBase */
                UINT16_C( 809 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_EL */
                UINT16_C( 0 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 34 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 30 ), /* ComSignalExtRef */
            UINT16_C( 0 ) /* ComIPduRef */
        },
        { /* ComRxSignal[31] -- SGis_AB_Gurtschloss_BF1_1312R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 43 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 42 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 31 ), /* ComSignalExtRef */
            UINT16_C( 1 ) /* ComIPduRef */
        },
        { /* ComRxSignal[32] -- SGis_AB_Gurtschloss_FA1_1312R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 41 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 42 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 32 ), /* ComSignalExtRef */
            UINT16_C( 1 ) /* ComIPduRef */
        },
        { /* ComRxSignal[33] -- SGis_AB_Gurtschloss_Reihe2_BF1_1312R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 49 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 42 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 33 ), /* ComSignalExtRef */
            UINT16_C( 1 ) /* ComIPduRef */
        },
        { /* ComRxSignal[34] -- SGis_AB_Gurtschloss_Reihe2_FA1_1312R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 45 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 42 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 34 ), /* ComSignalExtRef */
            UINT16_C( 1 ) /* ComIPduRef */
        },
        { /* ComRxSignal[35] -- SGis_AB_Gurtschloss_Reihe3_BF1_1312R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 55 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 42 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 35 ), /* ComSignalExtRef */
            UINT16_C( 1 ) /* ComIPduRef */
        },
        { /* ComRxSignal[36] -- SGis_AB_Gurtschloss_Reihe3_FA1_1312R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 51 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 42 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 36 ), /* ComSignalExtRef */
            UINT16_C( 1 ) /* ComIPduRef */
        },
        { /* ComRxSignal[37] -- SGis_AB_eCS_Aktuatortest_BF1_184112401R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 15 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 50 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 37 ), /* ComSignalExtRef */
            UINT16_C( 2 ) /* ComIPduRef */
        },
        { /* ComRxSignal[38] -- SGis_AB_eCS_Aktuatortest_FA1_184112401R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 13 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 50 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 38 ), /* ComSignalExtRef */
            UINT16_C( 2 ) /* ComIPduRef */
        },
        { /* ComRxSignal[39] -- SGis_AB_eCS_Aktuatortest_Reihe2_BF1_184112401R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 19 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 50 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 39 ), /* ComSignalExtRef */
            UINT16_C( 2 ) /* ComIPduRef */
        },
        { /* ComRxSignal[40] -- SGis_AB_eCS_Aktuatortest_Reihe2_FA1_184112401R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 17 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 50 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 40 ), /* ComSignalExtRef */
            UINT16_C( 2 ) /* ComIPduRef */
        },
        { /* ComRxSignal[41] -- SGis_AB_eCS_Aktuatortest_Reihe3_BF1_184112401R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 9 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 50 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 42 ), /* ComSignalExtRef */
            UINT16_C( 2 ) /* ComIPduRef */
        },
        { /* ComRxSignal[42] -- SGis_AB_eCS_Aktuatortest_Reihe3_FA1_184112401R */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 11 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 50 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 41 ), /* ComSignalExtRef */
            UINT16_C( 2 ) /* ComIPduRef */
        },
        { /* ComRxSignal[43] -- GliwaIn_Byte_0_300R */
            { /* ComSignalBase */
                UINT16_C( 801 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_DL */
                UINT16_C( 0 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 0 ), /* ComSignalGroupRef */
                UINT16_C( 66 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 0 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 65535 ), /* ComSignalExtRef */
            UINT16_C( 3 ) /* ComIPduRef */
        },
        { /* ComRxSignal[44] -- GliwaIn_Byte_1_300R */
            { /* ComSignalBase */
                UINT16_C( 801 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_DL */
                UINT16_C( 1 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 0 ), /* ComSignalGroupRef */
                UINT16_C( 66 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 0 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 65535 ), /* ComSignalExtRef */
            UINT16_C( 3 ) /* ComIPduRef */
        },
        { /* ComRxSignal[45] -- GliwaIn_Byte_2_300R */
            { /* ComSignalBase */
                UINT16_C( 801 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_DL */
                UINT16_C( 2 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 0 ), /* ComSignalGroupRef */
                UINT16_C( 66 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 0 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 65535 ), /* ComSignalExtRef */
            UINT16_C( 3 ) /* ComIPduRef */
        },
        { /* ComRxSignal[46] -- GliwaIn_Byte_3_300R */
            { /* ComSignalBase */
                UINT16_C( 801 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_DL */
                UINT16_C( 3 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 0 ), /* ComSignalGroupRef */
                UINT16_C( 66 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 0 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 65535 ), /* ComSignalExtRef */
            UINT16_C( 3 ) /* ComIPduRef */
        },
        { /* ComRxSignal[47] -- GliwaIn_Byte_4_300R */
            { /* ComSignalBase */
                UINT16_C( 801 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_DL */
                UINT16_C( 4 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 0 ), /* ComSignalGroupRef */
                UINT16_C( 66 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 0 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 65535 ), /* ComSignalExtRef */
            UINT16_C( 3 ) /* ComIPduRef */
        },
        { /* ComRxSignal[48] -- GliwaIn_Byte_5_300R */
            { /* ComSignalBase */
                UINT16_C( 801 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_DL */
                UINT16_C( 5 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 0 ), /* ComSignalGroupRef */
                UINT16_C( 66 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 0 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 65535 ), /* ComSignalExtRef */
            UINT16_C( 3 ) /* ComIPduRef */
        },
        { /* ComRxSignal[49] -- GliwaIn_Byte_6_300R */
            { /* ComSignalBase */
                UINT16_C( 801 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_DL */
                UINT16_C( 6 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 0 ), /* ComSignalGroupRef */
                UINT16_C( 66 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 0 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 65535 ), /* ComSignalExtRef */
            UINT16_C( 3 ) /* ComIPduRef */
        },
        { /* ComRxSignal[50] -- GliwaIn_Byte_7_300R */
            { /* ComSignalBase */
                UINT16_C( 801 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_DL */
                UINT16_C( 7 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 0 ), /* ComSignalGroupRef */
                UINT16_C( 66 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 0 ), /* ComFilterRef */
                    UINT16_C( 0 ), /* ComFilterSignalValueRef */
                    UINT8_C( 1 ) /* ComFilterType */
                }
            },
            UINT16_C( 65535 ), /* ComSignalExtRef */
            UINT16_C( 3 ) /* ComIPduRef */
        }
    },
    { /* ComRxSignalExt */
        { /* ComRxSignalExt[0] -- SGis_AB_Anzeige_Fussg1_64R */
            UINT16_C( 0 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[1] -- SGis_AB_Belegung_VF1_64R */
            UINT16_C( 0 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[2] -- SGis_AB_Crash_Int1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[3] -- SGis_AB_Deaktiviert1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[4] -- SGis_AB_Deaktivierung_HV1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[5] -- SGis_AB_Diagnose1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[6] -- SGis_AB_EDR_Trigger1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[7] -- SGis_AB_Erh_Auf_VB1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[8] -- SGis_AB_Front_Crash1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[9] -- SGis_AB_Gurtschloss_FA_ext1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[10] -- SGis_AB_Gurtschloss_FA_ext_aktiv1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[11] -- SGis_AB_Gurtwarn_VB1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[12] -- SGis_AB_Gurtwarn_VF1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[13] -- SGis_AB_Heck_Crash1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[14] -- SGis_AB_Lampe1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[15] -- SGis_AB_MKB_Anforderung1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[16] -- SGis_AB_MKB_gueltig1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[17] -- SGis_AB_PAO_Leuchte_Anf1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[18] -- SGis_AB_RGS_Anst1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[19] -- SGis_AB_Rollover_Crash1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[20] -- SGis_AB_SB_Crash1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[21] -- SGis_AB_SF_Crash1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[22] -- SGis_AB_Stellgliedtest1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[23] -- SGis_AB_Systemfehler1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[24] -- SGis_AB_Texte_AKS1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[25] -- SGis_AB_VB_deaktiviert1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[26] -- SGis_AB_Versorgungsspannung1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 0 ) /* ComRxSignalExtFlags -- COM_RX_DM_OFF | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[27] -- SGis_AB_eCS_Error1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[28] -- SGis_ASM_Masterzeit_021_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[29] -- SGis_Airbag_01_BZ1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[30] -- SGis_Airbag_01_CRC1_64R */
            UINT16_C( 65535 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[31] -- SGis_AB_Gurtschloss_BF1_1312R */
            UINT16_C( 1 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[32] -- SGis_AB_Gurtschloss_FA1_1312R */
            UINT16_C( 2 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[33] -- SGis_AB_Gurtschloss_Reihe2_BF1_1312R */
            UINT16_C( 3 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[34] -- SGis_AB_Gurtschloss_Reihe2_FA1_1312R */
            UINT16_C( 4 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[35] -- SGis_AB_Gurtschloss_Reihe3_BF1_1312R */
            UINT16_C( 5 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[36] -- SGis_AB_Gurtschloss_Reihe3_FA1_1312R */
            UINT16_C( 5 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[37] -- SGis_AB_eCS_Aktuatortest_BF1_184112401R */
            UINT16_C( 6 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[38] -- SGis_AB_eCS_Aktuatortest_FA1_184112401R */
            UINT16_C( 7 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[39] -- SGis_AB_eCS_Aktuatortest_Reihe2_BF1_184112401R */
            UINT16_C( 8 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[40] -- SGis_AB_eCS_Aktuatortest_Reihe2_FA1_184112401R */
            UINT16_C( 9 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[41] -- SGis_AB_eCS_Aktuatortest_Reihe3_FA1_184112401R */
            UINT16_C( 10 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[42] -- SGis_AB_eCS_Aktuatortest_Reihe3_BF1_184112401R */
            UINT16_C( 10 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 8 ) /* ComRxSignalExtFlags -- COM_RX_DM_ON | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        },
        { /* ComRxSignalExt[43] -- GRGliwaInGroup_300R */
            UINT16_C( 11 ), /* ComNotification */
            UINT16_C( 0 ), /* ComRxTimeoutFactorValue */
            UINT16_C( 0 ), /* ComRxFirstTimeoutFactorValue */
            UINT16_C( 65535 ), /* RxSigDMQueueRef */
            UINT16_C( 65535 ), /* ComRxTimeoutNotification */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT8_C( 0 ) /* ComRxSignalExtFlags -- COM_RX_DM_OFF | COM_RX_SIG_DM_OFF | COM_UPDATE_BIT_ABSENT | COM_RX_DATA_TOUT_ACTION_NONE */
        }
    },
    { /* ComTxSignal */
        { /* ComTxSignal[0] -- SGMF_Logger_Byte_0_1989T */
            { /* ComSignalBase */
                UINT16_C( 809 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Read_A1_EL */
                UINT16_C( 0 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 458 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 26049 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_EXT_BASIC_TYPE | Com_EB_Write_A1_EL_DUB_DOC */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 0 ), /* ComSignalPositionInBit */
            UINT16_C( 3 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[1] -- SGis_eCS_Error_Reihe1_BFS_1_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 41 ), /* ComSignalPositionInBit */
                UINT16_C( 3 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 39 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[2] -- SGis_eCS_Error_Reihe1_BFS_2_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 47 ), /* ComSignalPositionInBit */
                UINT16_C( 3 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 45 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[3] -- SGis_eCS_Error_Reihe1_FS_1_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 38 ), /* ComSignalPositionInBit */
                UINT16_C( 3 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 36 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[4] -- SGis_eCS_Error_Reihe1_FS_2_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 44 ), /* ComSignalPositionInBit */
                UINT16_C( 3 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 42 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[5] -- SGis_eCS_Error_Reihe2_BFS_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 53 ), /* ComSignalPositionInBit */
                UINT16_C( 3 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 51 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[6] -- SGis_eCS_Error_Reihe2_FS_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 50 ), /* ComSignalPositionInBit */
                UINT16_C( 3 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 48 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[7] -- SGis_eCS_SBS_LastState_Reihe2_BFS_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 57 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 56 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[8] -- SGis_eCS_SBS_LastState_Reihe2_FS_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 55 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 54 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[9] -- SGis_eCS_Status_Verr_Reihe1_BFS_1_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 27 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 26 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[10] -- SGis_eCS_Status_Verr_Reihe1_BFS_2_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 31 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 30 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[11] -- SGis_eCS_Status_Verr_Reihe1_FS_1_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 25 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 24 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[12] -- SGis_eCS_Status_Verr_Reihe1_FS_2_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 29 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 28 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[13] -- SGis_eCS_Status_Verr_Reihe2_BFS_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 35 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 34 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[14] -- SGis_eCS_Status_Verr_Reihe2_FS_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 33 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 32 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[15] -- SGis_eCS_Gurtschloss_Status_Reihe2_BF1_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 19 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 18 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[16] -- SGis_eCS_Gurtschloss_Status_Reihe2_FA1_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 17 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 16 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[17] -- SGis_eCS_HW_defekt1_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 15 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 15 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[18] -- SGis_eCS_SBS_Belegung_Reihe2_BF1_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 23 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 22 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[19] -- SGis_eCS_SBS_Belegung_Reihe2_FA1_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 21 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 20 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[20] -- SGis_eCS_Status1_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 13 ), /* ComSignalPositionInBit */
                UINT16_C( 2 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 12 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[21] -- SGis_eCS_Stoerung1_184112400T */
            { /* ComSignalBase */
                UINT16_C( 776 ), /* ComRxSignalFlags -- UINT8 | COM_NO_SIGNALEXT | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_08 */
                UINT16_C( 14 ), /* ComSignalPositionInBit */
                UINT16_C( 1 ), /* ComBitSize */
                UINT16_C( 65535 ), /* ComSignalGroupRef */
                UINT16_C( 466 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 25920 ), /* ComTxSignalFlags -- UINT8 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_TRIG | COM_NO_FILTER | COM_SIGNALEXT | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_08 */
            UINT16_C( 0 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 14 ), /* ComSignalPositionInBit */
            UINT16_C( 4 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[22] -- DataOut_Byte_0_7_256T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 63 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 0 ), /* ComSignalGroupRef */
                UINT16_C( 266 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 0 ), /* ComSignalPositionInBit */
            UINT16_C( 1 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[23] -- DataOut_Byte_16_23_256T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 191 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 0 ), /* ComSignalGroupRef */
                UINT16_C( 266 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 128 ), /* ComSignalPositionInBit */
            UINT16_C( 1 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[24] -- DataOut_Byte_24_31_256T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 255 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 0 ), /* ComSignalGroupRef */
                UINT16_C( 266 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 192 ), /* ComSignalPositionInBit */
            UINT16_C( 1 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[25] -- DataOut_Byte_32_39_256T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 319 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 0 ), /* ComSignalGroupRef */
                UINT16_C( 266 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 256 ), /* ComSignalPositionInBit */
            UINT16_C( 1 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[26] -- DataOut_Byte_40_47_256T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 383 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 0 ), /* ComSignalGroupRef */
                UINT16_C( 266 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 320 ), /* ComSignalPositionInBit */
            UINT16_C( 1 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[27] -- DataOut_Byte_48_55_256T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 447 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 0 ), /* ComSignalGroupRef */
                UINT16_C( 266 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 384 ), /* ComSignalPositionInBit */
            UINT16_C( 1 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[28] -- DataOut_Byte_56_63_256T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 511 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 0 ), /* ComSignalGroupRef */
                UINT16_C( 266 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 448 ), /* ComSignalPositionInBit */
            UINT16_C( 1 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[29] -- DataOut_Byte_8_15_256T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 127 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 0 ), /* ComSignalGroupRef */
                UINT16_C( 266 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 64 ), /* ComSignalPositionInBit */
            UINT16_C( 1 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[30] -- MF_Byte_0_7_1988T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 63 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 1 ), /* ComSignalGroupRef */
                UINT16_C( 394 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 0 ), /* ComSignalPositionInBit */
            UINT16_C( 2 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[31] -- MF_Byte_16_23_1988T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 191 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 1 ), /* ComSignalGroupRef */
                UINT16_C( 394 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 128 ), /* ComSignalPositionInBit */
            UINT16_C( 2 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[32] -- MF_Byte_24_31_1988T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 255 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 1 ), /* ComSignalGroupRef */
                UINT16_C( 394 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 192 ), /* ComSignalPositionInBit */
            UINT16_C( 2 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[33] -- MF_Byte_32_39_1988T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 319 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 1 ), /* ComSignalGroupRef */
                UINT16_C( 394 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 256 ), /* ComSignalPositionInBit */
            UINT16_C( 2 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[34] -- MF_Byte_40_47_1988T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 383 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 1 ), /* ComSignalGroupRef */
                UINT16_C( 394 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 320 ), /* ComSignalPositionInBit */
            UINT16_C( 2 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[35] -- MF_Byte_48_55_1988T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 447 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 1 ), /* ComSignalGroupRef */
                UINT16_C( 394 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 384 ), /* ComSignalPositionInBit */
            UINT16_C( 2 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[36] -- MF_Byte_56_63_1988T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 511 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 1 ), /* ComSignalGroupRef */
                UINT16_C( 394 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 448 ), /* ComSignalPositionInBit */
            UINT16_C( 2 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[37] -- MF_Byte_8_15_1988T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 127 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 1 ), /* ComSignalGroupRef */
                UINT16_C( 394 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 64 ), /* ComSignalPositionInBit */
            UINT16_C( 2 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[38] -- GliwaOut_Byte_0_7_200T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 63 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 2 ), /* ComSignalGroupRef */
                UINT16_C( 138 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 0 ), /* ComSignalPositionInBit */
            UINT16_C( 0 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[39] -- GliwaOut_Byte_16_23_200T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 191 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 2 ), /* ComSignalGroupRef */
                UINT16_C( 138 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 128 ), /* ComSignalPositionInBit */
            UINT16_C( 0 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[40] -- GliwaOut_Byte_24_31_200T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 255 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 2 ), /* ComSignalGroupRef */
                UINT16_C( 138 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 192 ), /* ComSignalPositionInBit */
            UINT16_C( 0 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[41] -- GliwaOut_Byte_32_39_200T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 319 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 2 ), /* ComSignalGroupRef */
                UINT16_C( 138 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 256 ), /* ComSignalPositionInBit */
            UINT16_C( 0 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[42] -- GliwaOut_Byte_40_47_200T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 383 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 2 ), /* ComSignalGroupRef */
                UINT16_C( 138 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 320 ), /* ComSignalPositionInBit */
            UINT16_C( 0 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[43] -- GliwaOut_Byte_48_55_200T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 447 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 2 ), /* ComSignalGroupRef */
                UINT16_C( 138 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 384 ), /* ComSignalPositionInBit */
            UINT16_C( 0 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[44] -- GliwaOut_Byte_56_63_200T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 511 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 2 ), /* ComSignalGroupRef */
                UINT16_C( 138 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 448 ), /* ComSignalPositionInBit */
            UINT16_C( 0 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        },
        { /* ComTxSignal[45] -- GliwaOut_Byte_8_15_200T */
            { /* ComSignalBase */
                UINT16_C( 1195 ), /* ComRxSignalFlags -- UINT64 | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_UNSIGNED | COM_BUFFER_LOCK | COM_LITTLE_ENDIAN | COM_SIG_TYPE_AY */
                UINT16_C( 127 ), /* ComSignalPositionInBit */
                UINT16_C( 64 ), /* ComBitSize */
                UINT16_C( 2 ), /* ComSignalGroupRef */
                UINT16_C( 138 ), /* ComBufferRef */
                { /* ComFilterConf */
                    UINT16_C( 65535 ), /* ComFilterRef */
                    UINT16_C( 65535 ), /* ComFilterSignalValueRef */
                    UINT8_C( 0 ) /* ComFilterType -- NEVER */
                }
            },
            UINT16_C( 37059 ), /* ComTxSignalFlags -- UINT64 | COM_TRANSFER_PPROPERTY_REPS | COM_TRANSFER_PPROPERTY_PENDING | COM_NO_FILTER | COM_NO_SIGNALEXT | COM_EXT_BASIC_TYPE | COM_BUFFER_LOCK | COM_UPDATE_BIT_ABSENT | COM_NO_TOC | COM_LITTLE_ENDIAN | COM_UNSIGNED | COM_SIG_TYPE_AY */
            UINT16_C( 65535 ), /* ComUpdateBitPositionInBit */
            UINT16_C( 64 ), /* ComSignalPositionInBit */
            UINT16_C( 0 ), /* ComIPduRef */
            UINT16_C( 0 ) /* ComPositionOfTMSFlag */
        }
    },
    { /* ComRxTimeoutNotificationList */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[0] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[1] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[2] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[3] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[4] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[5] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[6] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[7] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[8] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[9] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[10] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[11] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[12] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[13] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[14] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[15] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[16] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[17] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[18] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[19] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[20] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[21] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[22] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[23] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[24] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[25] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[26] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[27] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[28] */
        UINT16_C( 0 ), /* ComRxTimeoutNotificationList[29] */
        UINT16_C( 1 ), /* ComRxTimeoutNotificationList[30] */
        UINT16_C( 1 ), /* ComRxTimeoutNotificationList[31] */
        UINT16_C( 1 ), /* ComRxTimeoutNotificationList[32] */
        UINT16_C( 1 ), /* ComRxTimeoutNotificationList[33] */
        UINT16_C( 1 ), /* ComRxTimeoutNotificationList[34] */
        UINT16_C( 1 ), /* ComRxTimeoutNotificationList[35] */
        UINT16_C( 2 ), /* ComRxTimeoutNotificationList[36] */
        UINT16_C( 2 ), /* ComRxTimeoutNotificationList[37] */
        UINT16_C( 2 ), /* ComRxTimeoutNotificationList[38] */
        UINT16_C( 2 ), /* ComRxTimeoutNotificationList[39] */
        UINT16_C( 2 ), /* ComRxTimeoutNotificationList[40] */
        UINT16_C( 2 ) /* ComRxTimeoutNotificationList[41] */
    },
    { /* ComPeriodicQueueList */
        UINT16_C( 4 ) /* ComPeriodicQueueList[0] */
    },
    { /* ComNTimesQueueList */
        UINT16_C( 0 ), /* ComNTimesQueueList[0] */
        UINT16_C( 1 ), /* ComNTimesQueueList[1] */
        UINT16_C( 2 ), /* ComNTimesQueueList[2] */
        UINT16_C( 3 ) /* ComNTimesQueueList[3] */
    },
    { /* ComRxTimeoutQueueList */
        UINT16_C( 0 ), /* ComRxTimeoutQueueList[0] */
        UINT16_C( 1 ), /* ComRxTimeoutQueueList[1] */
        UINT16_C( 2 ) /* ComRxTimeoutQueueList[2] */
    },
    { /* ComCbkTxAckDeferredList */
        UINT16_C( 4 ) /* ComCbkTxAckDeferredList[0] */
    },
    { /* ComIPduGroupMask */
        UINT8_C( 1 ), /* ComIPduGroupMask[0] -- [0][0] IPDUGroupIN_eCS */
        UINT8_C( 0 ), /* ComIPduGroupMask[1] -- [0][1] */
        UINT8_C( 0 ), /* ComIPduGroupMask[2] -- [0][2] */
        UINT8_C( 0 ), /* ComIPduGroupMask[3] -- [0][3] */
        UINT8_C( 0 ), /* ComIPduGroupMask[4] -- [1][0] */
        UINT8_C( 0 ), /* ComIPduGroupMask[5] -- [1][1] */
        UINT8_C( 0 ), /* ComIPduGroupMask[6] -- [1][2] */
        UINT8_C( 64 ), /* ComIPduGroupMask[7] -- [1][3] IPDUGroupOUT_eCS */
        UINT8_C( 0 ), /* ComIPduGroupMask[8] -- [2][0] */
        UINT8_C( 0 ), /* ComIPduGroupMask[9] -- [2][1] */
        UINT8_C( 0 ), /* ComIPduGroupMask[10] -- [2][2] */
        UINT8_C( 128 ) /* ComIPduGroupMask[11] -- [2][3] IPDUGroupOUT_eCS_Comm */
    },
    { /* ComIPduInit */
        UINT8_C( 0 ), /* ComIPduInit[0] */
        UINT8_C( 128 ), /* ComIPduInit[1] */
        UINT8_C( 0 ), /* ComIPduInit[2] */
        UINT8_C( 5 ), /* ComIPduInit[3] */
        UINT8_C( 64 ), /* ComIPduInit[4] */
        UINT8_C( 0 ), /* ComIPduInit[5] */
        UINT8_C( 12 ), /* ComIPduInit[6] */
        UINT8_C( 255 ), /* ComIPduInit[7] */
        UINT8_C( 0 ), /* ComIPduInit[8] */
        UINT8_C( 0 ), /* ComIPduInit[9] */
        UINT8_C( 0 ), /* ComIPduInit[10] */
        UINT8_C( 0 ), /* ComIPduInit[11] */
        UINT8_C( 0 ), /* ComIPduInit[12] */
        UINT8_C( 21 ), /* ComIPduInit[13] */
        UINT8_C( 69 ), /* ComIPduInit[14] */
        UINT8_C( 0 ), /* ComIPduInit[15] */
        UINT8_C( 0 ), /* ComIPduInit[16] */
        UINT8_C( 0 ), /* ComIPduInit[17] */
        UINT8_C( 0 ), /* ComIPduInit[18] */
        UINT8_C( 0 ), /* ComIPduInit[19] */
        UINT8_C( 0 ), /* ComIPduInit[20] */
        UINT8_C( 0 ), /* ComIPduInit[21] */
        UINT8_C( 0 ), /* ComIPduInit[22] */
        UINT8_C( 0 ), /* ComIPduInit[23] */
        UINT8_C( 0 ), /* ComIPduInit[24] */
        UINT8_C( 0 ), /* ComIPduInit[25] */
        UINT8_C( 0 ), /* ComIPduInit[26] */
        UINT8_C( 0 ), /* ComIPduInit[27] */
        UINT8_C( 0 ), /* ComIPduInit[28] */
        UINT8_C( 0 ), /* ComIPduInit[29] */
        UINT8_C( 0 ), /* ComIPduInit[30] */
        UINT8_C( 0 ), /* ComIPduInit[31] */
        UINT8_C( 0 ), /* ComIPduInit[32] */
        UINT8_C( 0 ), /* ComIPduInit[33] */
        UINT8_C( 0 ), /* ComIPduInit[34] */
        UINT8_C( 0 ), /* ComIPduInit[35] */
        UINT8_C( 0 ), /* ComIPduInit[36] */
        UINT8_C( 0 ), /* ComIPduInit[37] */
        UINT8_C( 0 ), /* ComIPduInit[38] */
        UINT8_C( 0 ), /* ComIPduInit[39] */
        UINT8_C( 0 ), /* ComIPduInit[40] */
        UINT8_C( 0 ), /* ComIPduInit[41] */
        UINT8_C( 0 ), /* ComIPduInit[42] */
        UINT8_C( 0 ), /* ComIPduInit[43] */
        UINT8_C( 0 ), /* ComIPduInit[44] */
        UINT8_C( 0 ), /* ComIPduInit[45] */
        UINT8_C( 0 ), /* ComIPduInit[46] */
        UINT8_C( 0 ), /* ComIPduInit[47] */
        UINT8_C( 0 ), /* ComIPduInit[48] */
        UINT8_C( 0 ), /* ComIPduInit[49] */
        UINT8_C( 0 ), /* ComIPduInit[50] */
        UINT8_C( 0 ), /* ComIPduInit[51] */
        UINT8_C( 0 ), /* ComIPduInit[52] */
        UINT8_C( 0 ), /* ComIPduInit[53] */
        UINT8_C( 0 ), /* ComIPduInit[54] */
        UINT8_C( 0 ), /* ComIPduInit[55] */
        UINT8_C( 0 ), /* ComIPduInit[56] */
        UINT8_C( 0 ), /* ComIPduInit[57] */
        UINT8_C( 0 ), /* ComIPduInit[58] */
        UINT8_C( 0 ), /* ComIPduInit[59] */
        UINT8_C( 0 ), /* ComIPduInit[60] */
        UINT8_C( 0 ), /* ComIPduInit[61] */
        UINT8_C( 0 ), /* ComIPduInit[62] */
        UINT8_C( 0 ), /* ComIPduInit[63] */
        UINT8_C( 0 ), /* ComIPduInit[64] */
        UINT8_C( 0 ), /* ComIPduInit[65] */
        UINT8_C( 0 ), /* ComIPduInit[66] */
        UINT8_C( 0 ), /* ComIPduInit[67] */
        UINT8_C( 0 ), /* ComIPduInit[68] */
        UINT8_C( 0 ), /* ComIPduInit[69] */
        UINT8_C( 0 ), /* ComIPduInit[70] */
        UINT8_C( 0 ), /* ComIPduInit[71] */
        UINT8_C( 0 ), /* ComIPduInit[72] */
        UINT8_C( 0 ), /* ComIPduInit[73] */
        UINT8_C( 0 ), /* ComIPduInit[74] */
        UINT8_C( 0 ), /* ComIPduInit[75] */
        UINT8_C( 0 ), /* ComIPduInit[76] */
        UINT8_C( 0 ), /* ComIPduInit[77] */
        UINT8_C( 0 ), /* ComIPduInit[78] */
        UINT8_C( 0 ), /* ComIPduInit[79] */
        UINT8_C( 0 ), /* ComIPduInit[80] */
        UINT8_C( 0 ), /* ComIPduInit[81] */
        UINT8_C( 0 ), /* ComIPduInit[82] */
        UINT8_C( 0 ), /* ComIPduInit[83] */
        UINT8_C( 0 ), /* ComIPduInit[84] */
        UINT8_C( 0 ), /* ComIPduInit[85] */
        UINT8_C( 0 ), /* ComIPduInit[86] */
        UINT8_C( 0 ), /* ComIPduInit[87] */
        UINT8_C( 0 ), /* ComIPduInit[88] */
        UINT8_C( 0 ), /* ComIPduInit[89] */
        UINT8_C( 165 ), /* ComIPduInit[90] */
        UINT8_C( 0 ), /* ComIPduInit[91] */
        UINT8_C( 0 ), /* ComIPduInit[92] */
        UINT8_C( 0 ), /* ComIPduInit[93] */
        UINT8_C( 0 ), /* ComIPduInit[94] */
        UINT8_C( 0 ) /* ComIPduInit[95] */
    }
};

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <STOP> */

#define COM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <Com_MemMap.h>

/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/


/*==================[end of file]============================================*/

