[!NOCODE!]
/**
    @file    Dma_Ip_RegOperations.m
    @version 1.0.1

    @brief   AUTOSAR Mcl - Register operations.
    @details Register operations.

    Project RTD AUTOSAR 4.4
    Platform CORTEXM
    Peripheral DMA,CACHE,TRGMUX,FLEXIO
    Dependencies none

    ARVersion 4.4.0
    ARRevision ASR_REL_4_4_REV_0000
    ARConfVariant
    SWVersion 1.0.1
    BuildVersion S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224

    (c) Copyright 2020-2022 NXP Semiconductors
    All Rights Reserved.
 */



[!MACRO "Dma_Ip_Logic_Instance_Config","Type"!][!//
[!NOCODE!][!//
[!CODE!][!//
/* DMA Logic Instance Configuration */
[!LOOP "./MclConfig/dmaLogicInstance_ConfigType/*"!][!//
const Dma_Ip_LogicInstanceConfigType LogicInstance[!"@index"!]Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    {
        /* uint32 logicInstId; */ [!"node:value(dmaLogicInstance_IdName)"!],
        /* uint8 hwVersId;     */ DMA_IP_HARDWARE_VERSION_2,
        /* uint8 hwInst;       */ [!"node:value('dmaLogicInstance_hwId')"!],
    },
    /* boolean EnDebug; */                 (boolean)[!IF "node:value(dmaLogicInstance_enDebug)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    /* boolean EnRoundRobin; */            (boolean)[!IF "node:value(dmaLogicInstance_enRoundRobin)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    /* boolean EnHaltAfterError; */        (boolean)[!IF "node:value(dmaLogicInstance_enHaltAfterError)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    /* boolean EnChLinking; */             (boolean)[!IF "node:value(dmaLogicInstance_enChLinking)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
[!IF "node:exists(dmaLogicInstance_enGlMasterIdReplication)"!][!//
    /* boolean EnGlMasterIdReplication; */ (boolean)[!IF "node:value(dmaLogicInstance_enGlMasterIdReplication)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
[!ELSE!][!//
    /* boolean EnGlMasterIdReplication; */ (boolean)FALSE,
[!ENDIF!][!//
};

[!ENDLOOP!][!//
/* DMA Logic Instance Configuration Array */
const Dma_Ip_LogicInstanceConfigType * const Dma_Ip_paxLogicInstanceConfigArray[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][DMA_IP_NOF_CFG_LOGIC_INSTANCES] =
{
[!LOOP "./MclConfig/dmaLogicInstance_ConfigType/*"!][!//
    &LogicInstance[!"@index"!]Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
[!ENDLOOP!][!//
};
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//



[!MACRO "Dma_Ip_Logic_Channel_Global_Config","Type"!][!//
[!NOCODE!][!//
[!CODE!][!//
/* DMA Logic Channel Configurations */
[!LOOP "./MclConfig/dmaLogicChannel_Type/*"!][!//
[!IF "node:value(dmaLogicChannel_EnableGlobalConfig)"!][!//
/* DMA Logic Channel [!"@index"!] */
const Dma_Ip_GlobalConfigType LogicChannel[!"@index"!]GlobalConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    {
[!IF "node:exists(dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalControlType/dmaGlobalControl_enMasterIdReplication)"!][!//
        /* boolean EnMasterIdReplication; */ (boolean)[!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalControlType/dmaGlobalControl_enMasterIdReplication)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
[!ELSE!][!//
        /* boolean EnMasterIdReplication; */ (boolean)FALSE,
[!ENDIF!][!//
[!IF "node:exists(dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalControlType/dmaGlobalControl_enBufferedWrites)"!][!//
        /* boolean EnBufferedWrites; */      (boolean)[!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalControlType/dmaGlobalControl_enBufferedWrites)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
[!ELSE!][!//
        /* boolean EnBufferedWrites; */      (boolean)FALSE,
[!ENDIF!][!//
    }, /* Control */
    {
[!IF "node:value(dmaLogicChannel_HwInstId) = 'DMA_IP_HW_INST_0'"!][!//
        /* uint8 SourceMux; */               [!IF "substring-after(node:value(dmaLogicChannel_HwChId),'DMA_IP_HW_CH_') > 15"!][!"node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalRequestType/dmaGlobalRequest_Dmamux1HwRequest)"!][!ELSE!][!"node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalRequestType/dmaGlobalRequest_Dmamux0HwRequest)"!][!ENDIF!],
[!ENDIF!][!//
[!IF "node:value(dmaLogicChannel_HwInstId) = 'DMA_IP_HW_INST_1'"!][!//
        /* uint8 SourceMux; */               [!IF "substring-after(node:value(dmaLogicChannel_HwChId),'DMA_IP_HW_CH_') > 15"!][!"node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalRequestType/dmaGlobalRequest_Dmamux3HwRequest)"!][!ELSE!][!"node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalRequestType/dmaGlobalRequest_Dmamux2HwRequest)"!][!ENDIF!],
[!ENDIF!][!//
        /* boolean EnSourceMux; */           (boolean)[!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalRequestType/dmaGlobalRequest_enDmamuxSource)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        /* boolean EnTriggerMux; */          (boolean)[!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalRequestType/dmaGlobalRequest_enDmamuxTrigger)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        /* boolean EnRequest; */             (boolean)[!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalRequestType/dmaGlobalRequest_enDmaRequest)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    }, /* Request */
    {
        /* boolean EnErrorInt; */            (boolean)[!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalInterruptType/dmaGlobalInterrupt_enDmaErrorInterrupt)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    }, /* Interrupt */
    {
[!IF "node:exists(dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalPriorityType/dmaGlobalPriority_GroupPriority)"!][!//
        /* uint8 Group; */                   [!"node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalPriorityType/dmaGlobalPriority_GroupPriority)"!],
[!ELSE!][!//
        /* uint8 Group; */                   0U,
[!ENDIF!][!//
        /* uint8 Level; */                   [!"node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalPriorityType/dmaGlobalPriority_LevelPriority)"!],
        /* boolean EnPreemption; */          (boolean)[!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalPriorityType/dmaGlobalPriority_enPreemption)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        /* boolean DisPreempt; */            (boolean)[!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_GlobalConfigType/dmaLogicChannelConfig_GlobalPriorityType/dmaGlobalPriority_disPreempt)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    }, /* Priority */
};
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//



[!MACRO "Dma_Ip_Logic_Channel_Transfer_Config","Type"!][!//
[!NOCODE!][!//
[!CODE!][!//
[!LOOP "./MclConfig/dmaLogicChannel_Type/*"!][!//
[!IF "node:value(dmaLogicChannel_EnableTransferConfig)"!][!//
/* DMA Logic Channel [!"@index"!] */
const Dma_Ip_TransferConfigType LogicChannel[!"@index"!]TransferConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    {
        /* uint32 ScatterGatherAddr; */    0U,
        /* uint32 DestinationStoreAddr; */ 0U,
        /* uint8 BandwidthControl; */      [!"node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferControlType/dmaLogicChannelConfig_bandwidthControl)"!],
        /* boolean EnStart; */             (boolean)[!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferControlType/dmaLogicChannelConfig_enStart)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        /* boolean EnMajorInt; */          (boolean)[!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferControlType/dmaLogicChannelConfig_enDmaMajorInterrupt)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        /* boolean EnHalfMajorInt; */      (boolean)[!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferControlType/dmaLogicChannelConfig_enDmaHalfMajorInterrupt)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        /* boolean DisAutoHwRequest; */    (boolean)[!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferControlType/dmaLogicChannelConfig_disDmaAutoHwReq)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
[!IF "node:exists(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferControlType/dmaLogicChannelConfig_enEndOfPacketSignal)"!][!//
        /* boolean EnEndOfPacketSignal; */ (boolean)[!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferControlType/dmaLogicChannelConfig_enEndOfPacketSignal)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
[!ELSE!][!//
        /* boolean EnEndOfPacketSignal; */ (boolean)FALSE,
[!ENDIF!][!//
    }, /* Control */
    {
        /* uint32 addr; */         0U,
        /* sint32 lastAddrAdj; */  [!"num:i( node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferSourceType/dmaLogicChannelConfig_SourceLastAddressAdjustmentType) )"!],
        /* sint16 signedOffset; */ [!"num:i( node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferSourceType/dmaLogicChannelConfig_SourceSignedOffsetType) )"!],
        /* uint8 transferSize; */  [!"node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferSourceType/dmaTransferConfig_TransferSizeType)"!],
        /* uint8 modulo; */        [!"num:i( node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferSourceType/dmaLogicChannelConfig_SourceModuloType) )"!]U,
    }, /* Source */
    {
        /* uint32 addr; */         0U,
        /* sint32 lastAddrAdj; */  [!"num:i( node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferDestinationType/dmaLogicChannelConfig_DestinationLastAddressAdjustmentType) )"!],
        /* sint16 signedOffset; */ [!"num:i( node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferDestinationType/dmaLogicChannelConfig_DestinationSignedOffsetType) )"!],
        /* uint8 transferSize; */  [!"node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferDestinationType/dmaTransferConfig_TransferSizeType)"!],
        /* uint8 modulo; */        [!"num:i( node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferDestinationType/dmaLogicChannelConfig_DestinationModuloType) )"!]U,
    }, /* Destination */
    {
        /* uint32 Size; */         [!"num:i( node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferMinorLoopType/dmaLogicChannelConfig_MinorLoopSizeType) )"!]U,
        /* sint32 Offset; */       [!"num:i( node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferMinorLoopType/dmaLogicChannelConfig_OffsetValueType) )"!],
        /* uint8 LogicLinkCh; */   [!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferMinorLoopType/dmaLogicChannelConfig_enMinorLoopLinkCh)"!][!"node:value(node:ref(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferMinorLoopType/dynamic_dmaLogicChannelConfig_MinorLoopLinkChValueType)/dmaLogicChannel_LogicName)"!][!ELSE!]0U[!ENDIF!],
        /* boolean EnLink; */      (boolean)[!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferMinorLoopType/dmaLogicChannelConfig_enMinorLoopLinkCh)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        /* boolean EnSrcOffset; */ (boolean)[!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferMinorLoopType/dmaLogicChannelConfig_enSourceOffset)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        /* boolean EnDstOffset; */ (boolean)[!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferMinorLoopType/dmaLogicChannelConfig_enDestinationOffset)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    }, /* MinorLoop */
    {
        /* uint16 count; */        [!"num:i( node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferMajorLoopType/dmaLogicChannelConfig_MajorLoopCountType) )"!]U,
        /* uint8 LogicLinkCh; */   [!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferMajorLoopType/dmaLogicChannelConfig_enMajorLoopLinkCh)"!][!"node:value(node:ref(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferMajorLoopType/dynamic_dmaLogicChannelConfig_MajorLoopLinkChValueType)/dmaLogicChannel_LogicName)"!][!ELSE!]0U[!ENDIF!],
        /* boolean EnLink; */      (boolean)[!IF "node:value(dmaLogicChannel_ConfigType/dmaLogicChannel_TransferConfigType/dmaLogicChannelConfig_TransferMajorLoopType/dmaLogicChannelConfig_enMajorLoopLinkCh)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    }, /* MajorLoop */
};
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//



[!//
[!MACRO "Dma_Ip_Logic_Channel_Scatter_Gather_Config_STCD","Type"!][!//
[!NOCODE!][!//
[!CODE!][!//
[!LOOP "./MclConfig/dmaLogicChannel_Type/*"!][!//
[!VAR "LogicChannelName"="node:value(dmaLogicChannel_LogicName)"!][!//
[!VAR "LogicChannel" = "@index"!][!//
[!IF "node:value(dmaLogicChannel_EnableScatterGather)"!][!//
/* DMA Logic Channel [!"$LogicChannel"!] */
[!LOOP "./dmaLogicChannel_ConfigType/dmaLogicChannel_ScatterGatherConfigType/dmaLogicChannelConfig_ScatterGatherArrayType/*"!][!//
__attribute__(( aligned(32) )) Dma_Ip_SwTcdRegType LogicChannel[!"$LogicChannel"!]Stcd[!"@index"!][!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//

[!//
[!MACRO "Dma_Ip_Logic_Channel_Scatter_Gather_Config_Extern_Vars","Type"!][!//
[!NOCODE!][!//
[!CODE!][!//
[!LOOP "./MclConfig/dmaLogicChannel_Type/*"!][!//
[!VAR "LogicChannelName"="node:value(dmaLogicChannel_LogicName)"!][!//
[!VAR "LogicChannel" = "@index"!][!//
[!IF "node:value(dmaLogicChannel_EnableScatterGather)"!][!//
/* DMA Logic Channel [!"$LogicChannel"!] */
[!LOOP "./dmaLogicChannel_ConfigType/dmaLogicChannel_ScatterGatherConfigType/dmaLogicChannelConfig_ScatterGatherArrayType/*"!][!//
extern Dma_Ip_ScatterGatherConfigType LogicChannel[!"$LogicChannel"!]SgaElem[!"@index"!]Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//

[!//
[!MACRO "Dma_Ip_Logic_Channel_Scatter_Gather_Config","Type"!][!//
[!NOCODE!][!//
[!CODE!][!//
[!LOOP "./MclConfig/dmaLogicChannel_Type/*"!][!//
[!VAR "LogicChannelName"="node:value(dmaLogicChannel_LogicName)"!][!//
[!VAR "LogicChannel" = "@index"!][!//
[!IF "node:value(dmaLogicChannel_EnableScatterGather)"!][!//
/* DMA Logic Channel [!"$LogicChannel"!] */
[!LOOP "./dmaLogicChannel_ConfigType/dmaLogicChannel_ScatterGatherConfigType/dmaLogicChannelConfig_ScatterGatherArrayType/*"!][!//
[!IF "node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_enScatterGatherConfig)"!][!//

Dma_Ip_TransferConfigType LogicChannel[!"$LogicChannel"!]TransferElem[!"@index"!][!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    {
        /* uint32 ScatterGatherAddr; */    0U,
        /* uint32 DestinationStoreAddr; */ 0U,
        /* uint8 BandwidthControl; */      [!"node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferControlType/dmaLogicChannelConfig_bandwidthControl)"!],
        /* boolean EnStart; */             (boolean)[!IF "node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferControlType/dmaLogicChannelConfig_enStart)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        /* boolean EnMajorInt; */          (boolean)[!IF "node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferControlType/dmaLogicChannelConfig_enDmaMajorInterrupt)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        /* boolean EnHalfMajorInt; */      (boolean)[!IF "node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferControlType/dmaLogicChannelConfig_enDmaHalfMajorInterrupt)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        /* boolean DisAutoHwRequest; */    (boolean)[!IF "node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferControlType/dmaLogicChannelConfig_disDmaAutoHwReq)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
[!IF "node:exists(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferControlType/dmaLogicChannelConfig_enEndOfPacketSignal)"!][!//
        /* boolean EnEndOfPacketSignal; */ (boolean)[!IF "node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferControlType/dmaLogicChannelConfig_enEndOfPacketSignal)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
[!ELSE!]
        /* boolean EnEndOfPacketSignal; */ (boolean)FALSE,
[!ENDIF!]
    }, /* Control */
    {
        /* uint32 Addr; */         0U,
        /* sint32 LastAddrAdj; */  [!"num:i( node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferSourceType/dmaLogicChannelConfig_SourceLastAddressAdjustmentType) )"!],
        /* sint16 SignedOffset; */ [!"num:i( node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferSourceType/dmaLogicChannelConfig_SourceSignedOffsetType) )"!],
        /* uint8 TransferSize; */  [!"node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferSourceType/dmaTransferConfig_TransferSizeType)"!],
        /* uint8 Modulo; */        [!"num:i( node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferSourceType/dmaLogicChannelConfig_SourceModuloType) )"!]U,
    }, /* Source */
    {
        /* uint32 Addr; */         0U,
        /* sint32 LastAddrAdj; */  [!"num:i( node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferDestinationType/dmaLogicChannelConfig_DestinationLastAddressAdjustmentType) )"!],
        /* sint16 SignedOffset; */ [!"num:i( node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferDestinationType/dmaLogicChannelConfig_DestinationSignedOffsetType) )"!],
        /* uint8 TransferSize; */  [!"node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferDestinationType/dmaTransferConfig_TransferSizeType)"!],
        /* uint8 Modulo; */        [!"num:i( node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferDestinationType/dmaLogicChannelConfig_DestinationModuloType) )"!]U,
    }, /* Destination */
    {
        /* uint32 Size; */         [!"num:i( node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferMinorLoopType/dmaLogicChannelConfig_MinorLoopSizeType) )"!]U,
        /* sint32 Offset; */       [!"num:i( node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferMinorLoopType/dmaLogicChannelConfig_OffsetValueType) )"!],
        /* uint8 LogicLinkCh; */   [!IF "node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferMinorLoopType/dmaLogicChannelConfig_enMinorLoopLinkCh)"!][!"node:value(node:ref(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferMinorLoopType/dynamic_dmaLogicChannelConfig_MinorLoopLinkChValueType)/dmaLogicChannel_LogicName)"!][!ELSE!]0U[!ENDIF!],
        /* boolean EnLink; */      (boolean)[!IF "node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferMinorLoopType/dmaLogicChannelConfig_enMinorLoopLinkCh)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        /* boolean EnSrcOffset; */ (boolean)[!IF "node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferMinorLoopType/dmaLogicChannelConfig_enSourceOffset)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        /* boolean EnDstOffset; */ (boolean)[!IF "node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferMinorLoopType/dmaLogicChannelConfig_enDestinationOffset)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    }, /* MinorLoop */
    {
        /* uint16 Count; */        [!"num:i( node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferMajorLoopType/dmaLogicChannelConfig_MajorLoopCountType) )"!]U,
        /* uint8 LogicLinkCh; */   [!IF "node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferMajorLoopType/dmaLogicChannelConfig_enMajorLoopLinkCh)"!][!"node:value(node:ref(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferMajorLoopType/dynamic_dmaLogicChannelConfig_MajorLoopLinkChValueType)/dmaLogicChannel_LogicName)"!][!ELSE!]0U[!ENDIF!],
        /* boolean EnLink; */      (boolean)[!IF "node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_TransferMajorLoopType/dmaLogicChannelConfig_enMajorLoopLinkCh)"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    }, /* MajorLoop */
};
[!ENDIF!][!//

Dma_Ip_ScatterGatherConfigType LogicChannel[!"$LogicChannel"!]SgaElem[!"@index"!]Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Dma_Ip_TransferConfigType * TransferConfig */          [!IF "node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_enScatterGatherConfig)"!]&LogicChannel[!"$LogicChannel"!]TransferElem[!"@index"!][!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!ELSE!]NULL_PTR,[!ENDIF!]
    /* Dma_Ip_SwTcdRegType * Stcd */                          &LogicChannel[!"$LogicChannel"!]Stcd[!"@index"!][!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    /* boolean Loaded; */                                     (boolean)FALSE,
    /* struct Dma_Ip_ScatterGatherConfigType * NextConfig */  [!IF "node:value(dmaLogicChannelConfig_ScatterGatherElementConfigType/dmaLogicChannelConfig_LastElementLink_ScatterGatherType)"!]NULL_PTR,[!ELSE!]&LogicChannel[!"$LogicChannel"!]SgaElem[!"num:i(node:ref(dmaLogicChannelConfig_ScatterGatherElementConfigType/dynamic_dmaLogicChannelConfig_BasicElementLink_ScatterGatherType)/@index)"!]Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!ENDIF!]
};
[!ENDLOOP!][!//

Dma_Ip_ScatterGatherConfigType * LogicChannel[!"$LogicChannel"!]SgaArray[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"$LogicChannelName"!]_NOF_CFG_SGA_ELEMENTS] =
{
[!LOOP "./dmaLogicChannel_ConfigType/dmaLogicChannel_ScatterGatherConfigType/dmaLogicChannelConfig_ScatterGatherArrayType/*"!][!//
    &LogicChannel[!"$LogicChannel"!]SgaElem[!"@index"!]Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
[!ENDLOOP!][!//
};

[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//

[!//
[!MACRO "Dma_Ip_Logic_Channel_Config","Type"!][!//
[!NOCODE!][!//
[!CODE!][!//
[!LOOP "./MclConfig/dmaLogicChannel_Type/*"!][!//
const Dma_Ip_LogicChannelConfigType LogicChannel[!"@index"!]Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    {
        /* uint32 LogicChId; */               [!"node:value(dmaLogicChannel_LogicName)"!],
        /* uint8 HwVersId; */                 DMA_IP_HARDWARE_VERSION_2,
        /* uint8 HwInst; */                   [!"node:value(dmaLogicChannel_HwInstId)"!],
        /* uint8 HwChId; */                   [!"node:value(dmaLogicChannel_HwChId)"!],
        /* Dma_Ip_Callback IntCallback; */    [!"node:value(dmaLogicChannel_InterruptCallback)"!],
        /* Dma_Ip_Callback ErrIntCallback; */ [!"node:value(dmaLogicChannel_ErrorInterruptCallback)"!],
    },  /* Dma_Ip_LogicChannelIdType */
    [!IF "node:value(dmaLogicChannel_EnableGlobalConfig)"!]&LogicChannel[!"@index"!]GlobalConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ELSE!]NULL_PTR[!ENDIF!],
    [!IF "node:value(dmaLogicChannel_EnableTransferConfig)"!]&LogicChannel[!"@index"!]TransferConfig[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ELSE!]NULL_PTR[!ENDIF!],
    [!IF "node:value(dmaLogicChannel_EnableScatterGather)"!](Dma_Ip_ScatterGatherConfigType**)&LogicChannel[!"@index"!]SgaArray[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][0U][!ELSE!]NULL_PTR[!ENDIF!],
};
[!ENDLOOP!][!//

const Dma_Ip_LogicChannelConfigType * const Dma_Ip_paxLogicChannelConfigArray[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][DMA_IP_NOF_CFG_LOGIC_CHANNELS] =
{
[!LOOP "./MclConfig/dmaLogicChannel_Type/*"!][!//
    &LogicChannel[!"@index"!]Config[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
[!ENDLOOP!][!//
};
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "Dma_Ip_Hardware_Channel_State_NoInit","Type"!][!//
[!NOCODE!][!//
[!CODE!][!//
[!LOOP "./MclConfig/dmaLogicChannel_Type/*"!][!//
/* DMA Hardware Channel [!"@index"!] */
Dma_Ip_HwChannelStateType HwChannel[!"@index"!]State[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];
[!ENDLOOP!][!//
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Dma_Ip_Hardware_Channel_State_Init","Type"!][!//
[!NOCODE!][!//
[!CODE!][!//
/* DMA Hardware Channel State and DMA Logic Channel Configuration Array */
Dma_Ip_HwChannelStateType * Dma_Ip_paxHwChannelStateArray[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][DMA_IP_NOF_CFG_LOGIC_CHANNELS] =
{
[!LOOP "./MclConfig/dmaLogicChannel_Type/*"!][!//
    &HwChannel[!"@index"!]State[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
[!ENDLOOP!][!//
};
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//



[!MACRO "Dma_Ip_GetNrOfHwChannels"!][!//
[!NOCODE!][!//
[!VAR "NrOfHwChannel" = "0"!][!//
[!LOOP "./MclConfig/dmaLogicChannel_Type/*"!][!//
[!VAR "NrOfHwChannel" = "num:i($NrOfHwChannel + 1)"!][!//
[!ENDLOOP!][!//
[!CODE!][!"num:i($NrOfHwChannel)"!][!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "Dma_Ip_GetNrOfLogicInstances"!][!//
[!NOCODE!][!//
[!VAR "NrOfLogicInstances" = "0"!][!//
[!LOOP "./MclConfig/dmaLogicInstance_ConfigType/*"!][!//
[!VAR "NrOfLogicInstances" = "num:i($NrOfLogicInstances + 1)"!][!//
[!ENDLOOP!][!//
[!CODE!][!"num:i($NrOfLogicInstances)"!][!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "Dma_Ip_GetNrOfLogicChannels"!][!//
[!NOCODE!][!//
[!VAR "NrOfLogicChannels" = "0"!][!//
[!LOOP "./MclConfig/dmaLogicChannel_Type/*"!][!//
[!VAR "NrOfLogicChannels" = "num:i($NrOfLogicChannels + 1)"!][!//
[!ENDLOOP!][!//
[!CODE!][!"num:i($NrOfLogicChannels)"!][!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "Dma_Ip_GetNrOfSGElements","Channel"!][!//
[!NOCODE!][!//
[!VAR "NrOfSGElements" = "0"!][!//
[!VAR "ChannelPath" = "concat('dmaLogicChannel_Type_',$Channel)"!][!//
[!VAR "ScatterGatherListPath" = "concat('./MclConfig/dmaLogicChannel_Type/',$ChannelPath,'/dmaLogicChannel_ConfigType/dmaLogicChannel_ScatterGatherConfigType/dmaLogicChannelConfig_ScatterGatherArrayType/*')"!][!//
[!LOOP "$ScatterGatherListPath"!][!//
[!VAR "NrOfSGElements" = "num:i($NrOfSGElements + 1)"!][!//
[!ENDLOOP!][!//
[!CODE!][!"num:i($NrOfSGElements)"!][!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "Dma_Ip_GetNrOfSGElements_HardCodedPath"!][!//
[!NOCODE!][!//
[!VAR "NrOfSGElements" = "0"!][!//
[!LOOP "./dmaLogicChannel_ConfigType/dmaLogicChannel_ScatterGatherConfigType/dmaLogicChannelConfig_ScatterGatherArrayType/*"!][!//
[!VAR "NrOfSGElements" = "num:i($NrOfSGElements + 1)"!][!//
[!ENDLOOP!][!//
[!CODE!][!"num:i($NrOfSGElements)"!][!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Dma_Ip_GetNrOfMemSections"!][!//
[!NOCODE!][!//
[!VAR "NrOfMemSections" = "0"!][!//
[!LOOP "./MclConfig/MclVirtualMemorySection/*"!][!//
[!VAR "NrOfMemSections" = "num:i($NrOfMemSections + 1)"!][!//
[!ENDLOOP!][!//
[!CODE!][!"num:i($NrOfMemSections)"!][!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Dma_Ip_Multicore_Config"!][!//
[!VAR "TotalNumberOfPartition"="num:i(0)"!][!//
[!IF "node:exists(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition)"!][!//
[!VAR "TotalNumberOfPartition"="num:i(count(as:modconf("EcuC")[1]/EcucPartitionCollection/*[1]/EcucPartition/*))"!][!//
[!ENDIF!][!//
[!VAR "TotalNumberOfChannel"="num:i(0)"!][!//
[!VAR "TotalNumberOfChannel"="num:i(count(as:modconf('Mcl')[1]/MclConfig/dmaLogicChannel_Type/*))"!][!//
[!VAR "TotalNumberOfInstance"="num:i(count(as:modconf('Mcl')[1]/MclConfig/dmaLogicInstance_ConfigType/*))"!][!//

const Dma_Ip_MultiCoreConfigType Dma_Ip_MultiCoreConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!NOCODE!]
[!VAR "CoreUsed" ="num:i(255)"!][!//
[!VAR "ReturnValue1" = "num:i(0)"!]
[!VAR "ReturnValue2" = "num:i(0)"!]
[!IF "node:exists(MclGeneral/MclEcucPartitionRef)"!][!//
    [!VAR "PartitionRef" = "node:value(MclGeneral/MclEcucPartitionRef)"!][!//
    [!IF "node:exists(as:modconf('Os')[1]/OsApplication)"!][!//
        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
            [!IF "node:refvalid(./OsAppEcucPartitionRef)"!][!//
                [!IF "$PartitionRef = node:value(./OsAppEcucPartitionRef)"!][!//
                    [!IF "node:refvalid(./OsApplicationCoreRef)"!]
                        [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                            [!VAR "CoreUsed" ="node:value(./EcucCoreId)"!][!//
                        [!ENDSELECT!][!//
                        [!VAR "ReturnValue1" = "num:i($ReturnValue1 + 1)"!][!//
                    [!ELSE!]
                        [!VAR "ReturnValue2" = "num:i($ReturnValue2 + 1)"!][!//
                        [!ERROR!]
                        [!CR!] Error when generate core reference for MclEcucPartitionRef
                        [!CR!]1.Why you got this error? [!CR!]-> When enable multi cores feature, OsAppEcucPartitionRef and OsApplicationCoreRef of the OsApplication must be added and configured synchronization with configuration of EcuC component.[!CR!]For now:OsAppEcucPartitionRef ([!"text:split($PartitionRef, '/')[last()]"!]) was added correctly. But OsApplicationCoreRef was not configured.
                        [!CR!]2. How to resolve this error?
                        - Step 1: Go to Os component
                        - Step 2: Select OsApplication
                        - Step 3: Configure OsApplicationCoreRef for OsAppEcucPartitionRef ([!"text:split($PartitionRef, '/')[last()]"!])
                        [!ENDERROR!]
                    [!ENDIF!]
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!IF "($ReturnValue1 = 0) and ($ReturnValue2 = 0)"!]
            [!ERROR!]
            [!CR!] Error when generate core reference for MclEcucPartitionRef
            [!CR!]1.Why you got this error? [!CR!]-> When enable multi cores support, OsAppEcucPartitionRef and OsApplicationCoreRef of the OsApplication must be added and configured synchronization with configuration of EcuC component.[!CR!]For now: Both of OsAppEcucPartitionRef ([!"text:split($PartitionRef, '/')[last()]"!]) and OsApplicationCoreRef were not configured.
            [!CR!]2. How to resolve this error?
            - Step 1: Go to Os component
            - Step 2: Select OsApplication
            - Step 3: Create a new OsApplication configuration (by select + button)
            - Step 4: Configure OsAppEcucPartitionRef ([!"text:split($PartitionRef, '/')[last()]"!]) and OsApplicationCoreRef for the above OsApplication Configuration
            [!ENDERROR!]
        [!ENDIF!]
    [!ELSE!]
        [!ERROR!]
        [!CR!] Error when generate core reference for MclEcucPartitionRef
        [!CR!]1.Why you got this error? [!CR!]-> When enable multi cores feature, the OsApplication must be added and configured synchronization with configuration of EcuC component.[!CR!]For now Os application is not added
        [!CR!]2. How to resolve this error?
        - Step 1: Add Os component
        - Step 2: Select OsApplication
        - Step 3: Create a new OsApplication configuration (by select + button)
        - Step 4: Configure OsAppEcucPartitionRef ([!"text:split($PartitionRef, '/')[last()]"!]) and OsApplicationCoreRef for the above OsApplication Configuration
        [!ENDERROR!]
    [!ENDIF!]
[!ELSE!]
    [!ERROR!]
    [!CR!] Error when generate core reference for Mcl Initialization Multicore Configuration
    [!CR!]1.Why you got this error? [!CR!]-> When enable multi cores feature, users need to configure 'Ecuc Partition Ref' for corresponding Mcl Initialization Multicore Configuration.
    [!CR!]2. How to resolve this error?
    - Step 1: Go to 'Mcl General Configuration'
    - Step 2: Enable 'Mcl Initialization Multicore Configuration' node and Select the ECUC Partition Reference
    [!ENDERROR!]
[!ENDIF!][!//
[!CODE!]    /* Initialization number of core */[!CR!][!ENDCODE!]
[!IF "$CoreUsed != 255"!][!//
[!CODE!]    [!"num:i($CoreUsed + 1)"!],[!ENDCODE!]
[!ELSE!]
[!CODE!]    0,[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
    {
[!NOCODE!]
[!FOR "curModChannel" = "0" TO "$TotalNumberOfChannel - 1"!]
[!VAR "CoreUsed" ="num:i(255)"!]
[!FOR "varCounter" = "0" TO "num:i(count(./MclConfig/dmaLogicChannel_Type/*))"!]
[!LOOP "./MclConfig/dmaLogicChannel_Type/*"!]
[!VAR "LogicChannelIdx" = "@index"!][!//
[!IF "$LogicChannelIdx  =  $curModChannel"!]
    [!IF "node:exists(dmaLogicChannel_EcucPartitionRef)"!][!//
        [!VAR "ReturnValue1" = "num:i(0)"!]
        [!VAR "ReturnValue2" = "num:i(0)"!]
        [!VAR "PartitionRef" = "node:value(dmaLogicChannel_EcucPartitionRef)"!][!//
        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
            [!IF "node:refvalid(./OsAppEcucPartitionRef)"!][!//
                [!IF "$PartitionRef = node:value(./OsAppEcucPartitionRef)"!][!//
                    [!IF "node:refvalid(./OsApplicationCoreRef)"!]
                        [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                            [!VAR "CoreUsed" ="node:value(./EcucCoreId)"!][!//
                        [!ENDSELECT!][!//
                        [!VAR "ReturnValue1" = "num:i($ReturnValue1 + 1)"!][!//
                    [!ELSE!]
                        [!VAR "ReturnValue2" = "num:i($ReturnValue2 + 1)"!][!//
                        [!ERROR!]
                            [!CR!] Error when generate core reference for Logic Channel
                            [!CR!]1.Why you got this error? [!CR!]-> When enable multi cores feature, OsAppEcucPartitionRef and OsApplicationCoreRef of the OsApplication must be added and configured synchronization with configuration of EcuC component.[!CR!]For now:OsAppEcucPartitionRef ([!"text:split($PartitionRef, '/')[last()]"!]) was added correctly. But OsApplicationCoreRef was not configured.
                            [!CR!]2. How to resolve this error?
                            - Step 1: Go to Os component
                            - Step 2: Select OsApplication
                            - Step 3: Configure OsApplicationCoreRef for OsAppEcucPartitionRef ([!"text:split($PartitionRef, '/')[last()]"!])
                        [!ENDERROR!]
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!IF "($ReturnValue1 = 0) and ($ReturnValue2 = 0)"!]
            [!ERROR!]
            [!CR!]1.Why you got this error? [!CR!]-> When enable multi cores support, OsAppEcucPartitionRef and OsApplicationCoreRef of the OsApplication must be added and configured synchronization with configuration of EcuC component.[!CR!]For now: Both of OsAppEcucPartitionRef ([!"text:split($PartitionRef, '/')[last()]"!]) and OsApplicationCoreRef were not configured.
            [!CR!]2. How to resolve this error?
            - Step 1: Go to Os component
            - Step 2: Select OsApplication
            - Step 3: Create a new OsApplication configuration (by select + button)
            - Step 4: Configure OsAppEcucPartitionRef ([!"text:split($PartitionRef, '/')[last()]"!]) and OsApplicationCoreRef for the above OsApplication Configuration
            [!ENDERROR!]
        [!ENDIF!]
    [!ELSE!]
            [!ERROR!]
            [!CR!] Error when generate core reference for Logic Channel
            [!CR!]1. Why you got this error? [!CR!]-> When enable multi cores feature, users need to configure 'Ecuc Partition Ref' for corresponding Logic Channel. [!CR!]For now: 'Ecuc Partition Ref' Node of [!"node:value(./dmaLogicChannel_LogicName)"!] was not configured.
            [!CR!]2. How to resolve this error?
            - Step 1: Go to 'Dma Logic Channel'
            - Step 2: Select configuration has Logic Channel Name is '[!"node:value(./dmaLogicChannel_LogicName)"!]'
            - Step 3: Enable 'Ecuc Partition Ref' node and Select the ECUC Partition Reference
            [!ENDERROR!]
    [!ENDIF!][!//
[!ENDIF!]
[!ENDLOOP!]
[!ENDFOR!]
[!CODE!]/** @brief DMA Channel [!"$curModChannel"!] status core */[!CR!][!ENDCODE!]
[!IF "$CoreUsed != 255"!][!//
    [!IF "$curModChannel = $TotalNumberOfChannel - 1"!]
[!CODE!]        [!"num:i($CoreUsed + 1)"!][!ENDCODE!]
    [!ELSE!]
[!CODE!]        [!"num:i($CoreUsed + 1)"!],[!CR!][!ENDCODE!]
    [!ENDIF!]
[!ELSE!]
    [!IF "$curModChannel = $TotalNumberOfChannel - 1"!]
[!CODE!]        0[!ENDCODE!]
    [!ELSE!]
[!CODE!]        0,[!CR!][!ENDCODE!]
    [!ENDIF!]
[!ENDIF!]
[!ENDFOR!]
[!ENDNOCODE!]
    },
    {
[!NOCODE!]
[!FOR "curModInstance" = "0" TO "$TotalNumberOfInstance - 1"!]
[!VAR "CoreUsed" ="num:i(255)"!]
[!FOR "varCounter" = "0" TO "num:i(count(./MclConfig/dmaLogicInstance_ConfigType/*))"!]
[!LOOP "./MclConfig/dmaLogicInstance_ConfigType/*"!]
[!VAR "LogicInstanceIdx" = "@index"!][!//
[!IF "$LogicInstanceIdx  =  $curModInstance"!]
    [!IF "node:exists(dmaLogicInstance_EcucPartitionRef)"!][!//
        [!VAR "ReturnValue1" = "num:i(0)"!]
        [!VAR "ReturnValue2" = "num:i(0)"!]
        [!VAR "PartitionRef" = "node:value(dmaLogicInstance_EcucPartitionRef)"!][!//
        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!][!//
            [!IF "node:refvalid(./OsAppEcucPartitionRef)"!][!//
                [!IF "$PartitionRef = node:value(./OsAppEcucPartitionRef)"!][!//
                    [!IF "node:refvalid(./OsApplicationCoreRef)"!]
                        [!SELECT "node:ref(./OsApplicationCoreRef)"!][!//
                            [!VAR "CoreUsed" ="node:value(./EcucCoreId)"!][!//
                        [!ENDSELECT!][!//
                        [!VAR "ReturnValue1" = "num:i($ReturnValue1 + 1)"!][!//
                    [!ELSE!]
                        [!VAR "ReturnValue2" = "num:i($ReturnValue2 + 1)"!][!//
                        [!ERROR!]
                            [!CR!] Error when generate core reference for Logic Instance
                            [!CR!]1.Why you got this error? [!CR!]-> When enable multi cores feature, OsAppEcucPartitionRef and OsApplicationCoreRef of the OsApplication must be added and configured synchronization with configuration of EcuC component.[!CR!]For now:OsAppEcucPartitionRef ([!"text:split($PartitionRef, '/')[last()]"!]) was added correctly. But OsApplicationCoreRef was not configured.
                            [!CR!]2. How to resolve this error?
                            - Step 1: Go to Os component
                            - Step 2: Select OsApplication
                            - Step 3: Configure OsApplicationCoreRef for OsAppEcucPartitionRef ([!"text:split($PartitionRef, '/')[last()]"!])
                        [!ENDERROR!]
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!IF "($ReturnValue1 = 0) and ($ReturnValue2 = 0)"!]
            [!ERROR!]
            [!CR!]1.Why you got this error? [!CR!]-> When enable multi cores support, OsAppEcucPartitionRef and OsApplicationCoreRef of the OsApplication must be added and configured synchronization with configuration of EcuC component.[!CR!]For now: Both of OsAppEcucPartitionRef ([!"text:split($PartitionRef, '/')[last()]"!]) and OsApplicationCoreRef were not configured.
            [!CR!]2. How to resolve this error?
            - Step 1: Go to Os component
            - Step 2: Select OsApplication
            - Step 3: Create a new OsApplication configuration (by select + button)
            - Step 4: Configure OsAppEcucPartitionRef ([!"text:split($PartitionRef, '/')[last()]"!]) and OsApplicationCoreRef for the above OsApplication Configuration
            [!ENDERROR!]
        [!ENDIF!]
    [!ELSE!]
            [!ERROR!]
            [!CR!] Error when generate core reference for Logic Instance
            [!CR!]1. Why you got this error? [!CR!]-> When enable multi cores feature, users need to configure 'Ecuc Partition Ref' for corresponding Logic Instance. [!CR!]For now: 'Ecuc Partition Ref' Node of [!"node:value(./dmaLogicInstance_IdName)"!] was not configured.
            [!CR!]2. How to resolve this error?
            - Step 1: Go to 'Dma Logic Instance'
            - Step 2: Select configuration has Logic Instance Name is '[!"node:value(./dmaLogicInstance_IdName)"!]'
            - Step 3: Enable 'Ecuc Partition Ref' node and Select the ECUC Partition Reference
            [!ENDERROR!]
    [!ENDIF!][!//
[!ENDIF!]
[!ENDLOOP!]
[!ENDFOR!]
[!CODE!]/** @brief DMA Instance [!"$curModInstance"!] status core */[!CR!][!ENDCODE!]
[!IF "$CoreUsed != 255"!][!//
    [!IF "$curModInstance = $TotalNumberOfInstance - 1"!]
[!CODE!]        [!"num:i($CoreUsed + 1)"!][!ENDCODE!]
    [!ELSE!]
[!CODE!]        [!"num:i($CoreUsed + 1)"!],[!CR!][!ENDCODE!]
    [!ENDIF!]
[!ELSE!]
    [!IF "$curModInstance = $TotalNumberOfInstance - 1"!]
[!CODE!]        0[!ENDCODE!]
    [!ELSE!]
[!CODE!]        0,[!CR!][!ENDCODE!]
    [!ENDIF!]
[!ENDIF!]
[!ENDFOR!]
[!ENDNOCODE!]
    }
};
[!ENDMACRO!][!//

[!MACRO "Dma_Ip_VirtualMemoryConfig","Type"!][!//
[!NOCODE!][!//
[!VAR "NrOfMemSection"!][!CALL "Dma_Ip_GetNrOfMemSections"!][!ENDVAR!][!//
[!IF "$NrOfMemSection > num:i(0)"!][!//
[!VAR "firstIdxSection" = "0"!]
[!VAR "secondIdxSection" = "0"!]
[!FOR "firstIdxSection" = "0" TO "$NrOfMemSection - 2"!]
    [!FOR "secondIdxSection" = "$firstIdxSection + 1" TO "$NrOfMemSection - 1"!]
        [!VAR "VirtAddrEndFirst" = "node:value(concat(concat('./MclConfig/MclVirtualMemorySection/MclVirtualMemorySection_',$firstIdxSection),'/MclVirtualAddressEnd'))"!]
        [!VAR "VirtAddrStartFirst" = "node:value(concat(concat('./MclConfig/MclVirtualMemorySection/MclVirtualMemorySection_',$firstIdxSection),'/MclVirtualAddressStart'))"!]
        [!VAR "VirtAddrEndSecond" = "node:value(concat(concat('./MclConfig/MclVirtualMemorySection/MclVirtualMemorySection_',$secondIdxSection),'/MclVirtualAddressEnd'))"!]
        [!VAR "VirtAddrStartSecond" = "node:value(concat(concat('./MclConfig/MclVirtualMemorySection/MclVirtualMemorySection_',$secondIdxSection),'/MclVirtualAddressStart'))"!]
        [!VAR "PhysAddrEndFirst" = "node:value(concat(concat('./MclConfig/MclVirtualMemorySection/MclVirtualMemorySection_',$firstIdxSection),'/MclPhysicalAddressEnd'))"!]
        [!VAR "PhysAddrStartFirst" = "node:value(concat(concat('./MclConfig/MclVirtualMemorySection/MclVirtualMemorySection_',$firstIdxSection),'/MclPhysicalAddressStart'))"!]
        [!VAR "PhysAddrEndSecond" = "node:value(concat(concat('./MclConfig/MclVirtualMemorySection/MclVirtualMemorySection_',$secondIdxSection),'/MclPhysicalAddressEnd'))"!]
        [!VAR "PhysAddrStartSecond" = "node:value(concat(concat('./MclConfig/MclVirtualMemorySection/MclVirtualMemorySection_',$secondIdxSection),'/MclPhysicalAddressStart'))"!]

        [!IF "$VirtAddrEndFirst > $VirtAddrStartSecond and $VirtAddrEndFirst <= $VirtAddrEndSecond"!]
            [!ERROR!] [!//
       " Virtual address overlap between MclVirtualMemorySection[!"$firstIdxSection"!] and MclVirtualMemorySection[!"$secondIdxSection"!]  "[!//
            [!ENDERROR!][!//
        [!ELSEIF "$VirtAddrEndSecond > $VirtAddrStartFirst and $VirtAddrEndSecond <= $VirtAddrEndFirst"!]
            [!ERROR!] [!//
       " Virtual address overlap between MclVirtualMemorySection[!"$firstIdxSection"!] and MclVirtualMemorySection[!"$secondIdxSection"!]  "[!//
            [!ENDERROR!][!//
        [!ELSE!]
        [!ENDIF!]
        [!IF "$PhysAddrEndFirst > $PhysAddrStartSecond and $PhysAddrEndFirst <= $PhysAddrEndSecond"!]
            [!ERROR!] [!//
       " Physical address overlap between MclVirtualMemorySection[!"$firstIdxSection"!] and MclVirtualMemorySection[!"$secondIdxSection"!]  "[!//
            [!ENDERROR!][!//
        [!ELSEIF "$PhysAddrEndSecond > $PhysAddrStartFirst and $PhysAddrEndSecond <= $PhysAddrEndFirst"!]
            [!ERROR!] [!//
       " Physical address overlap between MclVirtualMemorySection[!"$firstIdxSection"!] and MclVirtualMemorySection[!"$secondIdxSection"!]  "[!//
            [!ENDERROR!][!//
        [!ELSE!]
        [!ENDIF!]
        [!ENDFOR!]
[!ENDFOR!]
[!CODE!][!//
/**
* @brief        Definition of Virtual Memory sections within the configuration structure.
*
*/
#define DMA_IP_NOF_VIRTUAL_MEMORY_SECTION[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]  [!"$NrOfMemSection"!]U

const Dma_Ip_VirtualSectionConfigType Dma_Ip_VirtualMemorySectionConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][DMA_IP_NOF_VIRTUAL_MEMORY_SECTION[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]] =
{
[!ENDCODE!][!//
[!LOOP "./MclConfig/MclVirtualMemorySection/*"!][!//
[!CODE!][!//
    {
        /* const uint32 VirtualAddrStart; */    [!"num:inttohex(MclVirtualAddressStart,8)"!]U,
        /* const uint32 VirtualAddrEnd; */      [!"num:inttohex(MclVirtualAddressEnd,8)"!]U,
        /* const uint32 PhysicalAddrStart; */   [!"num:inttohex(MclPhysicalAddressStart,8)"!]U,
        /* const uint32 PhysicalAddrEnd; */     [!"num:inttohex(MclPhysicalAddressEnd,8)"!]U,
    },
[!ENDCODE!][!//
[!ENDLOOP!][!//
[!CODE!][!//
};
[!ENDCODE!][!//
[!CODE!][!//
const Dma_Ip_VirtualMemoryConfigType Dma_Ip_VirtualMemoryConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* const uint8 NumOfSection; */                                           [!"$NrOfMemSection"!]U,
    /* const Dma_Ip_VirtualSectionConfigType (* const pSectionConfig)[] */    &Dma_Ip_VirtualMemorySectionConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
};
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Dma_Ip_Init","Type"!][!//
[!NOCODE!][!//
[!VAR "NrOfHwChannels"!][!CALL "Dma_Ip_GetNrOfHwChannels"!][!ENDVAR!][!//
[!VAR "NrOfLogicChannels"!][!CALL "Dma_Ip_GetNrOfLogicChannels"!][!ENDVAR!][!//
[!VAR "NrOfLogicInstances"!][!CALL "Dma_Ip_GetNrOfLogicInstances"!][!ENDVAR!][!//
[!CODE!][!//
/* DMA Initialization Structure */
const Dma_Ip_InitType Dma_Ip_xDmaInit[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!ENDCODE!][!//
    [!IF "$NrOfHwChannels > num:i(0)"!][!//
[!CODE!][!//
    /* Dma_Ip_HwChannelStateType ** HwChStateArray */                          &Dma_Ip_paxHwChannelStateArray[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][0U],          /* Static */
[!ENDCODE!][!//
    [!ELSE!][!//
[!CODE!][!//
    /* Dma_Ip_HwChannelStateType ** HwChStateArray */                          NULL_PTR,
[!ENDCODE!][!//
    [!ENDIF!][!//

    [!IF "$NrOfLogicChannels > 0"!][!//
[!CODE!][!//
    /* const Dma_Ip_LogicChannelConfigType * const LogicChConfigArray   */     &Dma_Ip_xLogicChannelResetConfig,                   /* Static */
    /* const Dma_Ip_LogicChannelConfigType * const * LogicChConfigArray */     &Dma_Ip_paxLogicChannelConfigArray[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][0U],      /* Static */
[!ENDCODE!][!//
    [!ELSE!][!//
[!CODE!][!//
    /* const Dma_Ip_LogicChannelConfigType * const LogicChConfigArray   */     NULL_PTR,
    /* const Dma_Ip_LogicChannelConfigType * const * LogicChConfigArray */     NULL_PTR,
[!ENDCODE!][!//
    [!ENDIF!][!//

    [!IF "$NrOfLogicInstances > 0"!][!//
[!CODE!][!//
    /* const Dma_Ip_LogicInstanceConfigType * const LogicInstConfigArray   */  &Dma_Ip_xLogicInstanceResetConfig,                  /* Static */
    /* const Dma_Ip_LogicInstanceConfigType * const * LogicInstConfigArray */  &Dma_Ip_paxLogicInstanceConfigArray[!"$Type"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][0U],     /* Static */
[!ENDCODE!][!//
    [!ELSE!][!//
[!CODE!][!//
    /* const Dma_Ip_LogicInstanceConfigType * const LogicInstConfigArray   */  NULL_PTR,
    /* const Dma_Ip_LogicInstanceConfigType * const * LogicInstConfigArray */  NULL_PTR,
[!ENDCODE!][!//
    [!ENDIF!][!//
[!CODE!][!//
[!IF "node:value(MclGeneral/MclEnableVirtualAddressMappingSupport)"!][!//
    /* const Dma_Ip_VirtualMemoryConfigType * const pxVirtualMemoryConfig  */  &Dma_Ip_VirtualMemoryConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
[!ENDIF!][!//
[!ENDCODE!][!//
[!CODE!][!//
};
[!ENDCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//




[!ENDNOCODE!]
