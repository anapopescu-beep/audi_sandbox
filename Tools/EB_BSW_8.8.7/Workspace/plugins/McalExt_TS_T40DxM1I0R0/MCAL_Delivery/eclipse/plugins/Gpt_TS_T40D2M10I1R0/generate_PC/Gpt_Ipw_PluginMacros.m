[!AUTOSPACING!]
[!NOCODE!]
/**
*   @file    Gpt_Ipw_PluginMacros.m
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - Macros used to generate code template for GPT driver.
*   @details Macros used to generate code template for GPT driver.
*
*   @internal
*   @addtogroup gpt gpt_ipw
*
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Ftm_Srtc_Lptmr_LPit
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
==================================================================================================*/

[!/* Avoid multiple inclusion */!]
[!IF "not(var:defined('GPT_IPW_PLUGIN_MACRO_M'))"!][!//
[!VAR "GPT_IPW_PLUGIN_MACRO_M" = "'true'"!][!//

[!VAR "GptEcucPartitionRefCount" = "num:i(count(as:modconf('Gpt')[1]/GptDriverConfiguration/GptEcucPartitionRef/*))"!]
[!IF "$GptEcucPartitionRefCount != 0 "!]
    [!VAR "GptEcucPartitionRefNum" = "$GptEcucPartitionRefCount"!]
[!ELSE!]
    [!VAR "GptEcucPartitionRefNum" = "1"!]
[!ENDIF!]
[!IF "var:defined('postBuildVariant')"!]
    [!VAR "PBCfg_Variant" = "concat('PB_', $postBuildVariant)"!]
[!ELSE!]
    [!VAR "PBCfg_Variant" = "'PB'"!]
[!ENDIF!]

[!// MACRO for creating the mapping between hardware channels and logical channels
[!// need to be called in the context of each partition where $GptEcucPartitionRefName is available
[!MACRO "GPT_VARIABLES"!][!//
[!NOCODE!]
    [!VAR "MaximumCoreId" = "0"!]
    [!VAR "CurrentCoreId" = "0"!]
    [!VAR "OutRespectiveCoreId" = "0"!]
    [!VAR "OutNumGptChannelsUsingSRtc"  = "0"!]
    [!VAR "OutNumGptChannelsUsingLptmr"  = "0"!]
    [!VAR "OutNumGptChannelsUsingLPit"  = "0"!]
    [!VAR "OutNumGptChannelsUsingFtm"  = "0"!]
    [!VAR "OutNumGptChannels" = "num:i(count(GptChannelConfigSet/GptChannelConfiguration/*))"!]
    [!VAR "OutNumGptChannelsConfiguration" = "num:i(count(GptChannelConfiguration/*))"!]
    [!VAR "OutNumChannelInPartition"  = "0"!]
    [!VAR "OutNumInstancesInPartition"  = "0"!]
    [!VAR "OutNumInstances"  = "0"!]
    [!VAR "OutNumInstancesSRtc"  = "0"!]
    [!VAR "OutNumInstancesFtm"  = "0"!]
    [!VAR "OutNumInstancesLptmr"  = "0"!]
    [!VAR "OutNumInstancesLPit"  = "0"!]
    [!// Count channels and instances in each module that is using for current partition
    [!IF "$GptEcucPartitionRefCount != 0 "!]
        [!// Count instances
        [!LOOP "GptFtm/*"!]
            [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(node:refs(GptModuleRef)/../../GptFtmModule = node:current()/GptFtmModule) and (node:value(./GptChannelEcucPartitionRef/*[1]) = $GptEcucPartitionRefName)])"!]
                [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!]
            [!ENDIF!]
        [!ENDLOOP!]

        [!LOOP "GptLpit/*"!]
            [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(node:refs(GptModuleRef)/../../GptLpitModule = node:current()/GptLpitModule) and (node:value(./GptChannelEcucPartitionRef/*[1]) = $GptEcucPartitionRefName)])"!]
                [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!]
            [!ENDIF!]
        [!ENDLOOP!]        

        [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(GptHwIp = 'SRTC') and (node:value(./GptChannelEcucPartitionRef/*[1]) = $GptEcucPartitionRefName)])"!]
            [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!]
        [!ENDIF!]
        
        [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(GptHwIp = 'LPTMR') and (node:value(./GptChannelEcucPartitionRef/*[1]) = $GptEcucPartitionRefName)])"!]
            [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!]
        [!ENDIF!]        
        [!// Count channels
        [!LOOP "GptChannelConfiguration/*"!]
            [!VAR "HardwareModule" = "./GptHwIp"!]
            [!LOOP "./GptChannelEcucPartitionRef/*"!]
                [!IF "node:value(.) = $GptEcucPartitionRefName"!]
                    [!//Update variables storing number of Gpt channels
                    [!IF "contains($HardwareModule,'FTM')"!]
                        [!VAR "OutNumGptChannelsUsingFtm" = "$OutNumGptChannelsUsingFtm + 1"!]
                    [!ELSEIF "contains($HardwareModule,'SRTC')"!]
                        [!VAR "OutNumGptChannelsUsingSRtc" = "$OutNumGptChannelsUsingSRtc + 1"!]
                    [!ELSEIF "contains($HardwareModule,'LPTMR')"!]
                        [!VAR "OutNumGptChannelsUsingLptmr" = "$OutNumGptChannelsUsingLptmr + 1"!]
                    [!ELSEIF "contains($HardwareModule,'LPIT')"!]
                        [!VAR "OutNumGptChannelsUsingLPit" = "$OutNumGptChannelsUsingLPit + 1"!]                        
                    [!ENDIF!]    
                    [!VAR "OutNumChannelInPartition" = "$OutNumChannelInPartition + 1"!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDLOOP!]
        [!LOOP "../GptDriverConfiguration/GptEcucPartitionRef/*"!]
            [!VAR "GptPartRefName" = "node:value(.)"!]
            [!VAR "GptPartRefShortName" = "substring-after($GptPartRefName, '/')"!]
            [!VAR "GptPartRefShortName" = "substring-after($GptPartRefShortName, '/')"!]
            [!VAR "GptPartRefShortName" = "substring-after($GptPartRefShortName, '/')"!]
            [!VAR "GptPartRefShortName" = "substring-after($GptPartRefShortName, '/')"!]
            [!VAR "GptPartRefShortName" = "text:toupper($GptPartRefShortName)"!]
            [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
                [!IF "$GptPartRefName = node:value(OsAppEcucPartitionRef)"!]
                    [!SELECT "node:ref(OsApplicationCoreRef)"!]
                        [!IF "$GptPartRefName = $GptEcucPartitionRefName"!]
                            [!VAR "OutRespectiveCoreId" = "node:value(./EcucCoreId)"!]
                        [!ENDIF!]
                        [!VAR "CurrentCoreId" = "node:value(./EcucCoreId)"!]
                        [!IF "num:i($MaximumCoreId) < num:i($CurrentCoreId)"!]
                            [!VAR "MaximumCoreId" = "$CurrentCoreId"!]
                        [!ENDIF!]
                    [!ENDSELECT!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDLOOP!]
    [!ELSE!]
        [!// TODO: Count instances

    [!VAR "OutNumInstancesFtm"  = "0"!]
    [!LOOP "GptChannelConfigSet/GptFtm/*"!]
        [!VAR "HardwareModule" = "./GptFtmModule"!]
        [!VAR "chUsed"  = "0"!]
            [!LOOP "../../../GptChannelConfigSet/GptChannelConfiguration/*"!]
                [!IF "contains(GptHwIp,'FTM')"!]
                    [!IF "node:value(node:ref(./GptModuleRef)/../../GptFtmModule) = $HardwareModule"!]
                        [!IF "$chUsed = 0"!]
                            [!VAR "OutNumInstancesFtm"  = "$OutNumInstancesFtm + 1"!]
                            [!VAR "chUsed"  = "1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
    [!ENDLOOP!]

    [!VAR "OutNumInstancesLPit"  = "0"!]
    [!LOOP "GptChannelConfigSet/GptLpit/*"!]
        [!VAR "HardwareModule" = "./GptLpitModule"!]
        [!VAR "chUsed"  = "0"!]
            [!LOOP "../../../GptChannelConfigSet/GptChannelConfiguration/*"!]
                [!IF "contains(GptHwIp,'LPIT')"!]
                    [!IF "node:value(node:ref(./GptModuleRef)/../../GptLpitModule) = $HardwareModule"!]
                        [!IF "$chUsed = 0"!]
                            [!VAR "OutNumInstancesLPit"  = "$OutNumInstancesLPit + 1"!]
                            [!VAR "chUsed"  = "1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
    [!ENDLOOP!]    

    [!LOOP "GptChannelConfigSet/GptSRtc/*"!]
    [!VAR "HardwareModule" = "./GptSRtcModule"!]
    [!VAR "chUsed"  = "0"!]
    [!LOOP "../../../GptChannelConfigSet/GptChannelConfiguration/*"!]
        [!IF "contains(GptHwIp,'SRTC')"!]
            [!IF "node:value(node:ref(./GptModuleRef)/GptSRtcModule) = $HardwareModule"!]
                    [!IF "$chUsed = 0"!]
                        [!VAR "OutNumInstancesSRtc"  = "$OutNumInstancesSRtc + 1"!]
                        [!VAR "chUsed"  = "1"!]
                    [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!ENDLOOP!]
    
    [!LOOP "GptChannelConfigSet/GptLptmr/*"!]
    [!VAR "HardwareModule" = "./GptLptmrModule"!]
    [!VAR "chUsed"  = "0"!]
    [!LOOP "../../../GptChannelConfigSet/GptChannelConfiguration/*"!]
        [!IF "contains(GptHwIp,'LPTMR')"!]
            [!IF "node:value(node:ref(./GptModuleRef)/GptLptmrModule) = $HardwareModule"!]
                    [!IF "$chUsed = 0"!]
                        [!VAR "OutNumInstancesLptmr"  = "$OutNumInstancesLptmr + 1"!]
                        [!VAR "chUsed"  = "1"!]
                    [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!ENDLOOP!]    

    [!VAR "OutNumInstances" = "$OutNumInstancesFtm + $OutNumInstancesSRtc + $OutNumInstancesLptmr + $OutNumInstancesLPit"!]

    [!LOOP "GptFtm/*"!]
        [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(node:refs(GptModuleRef)/../../GptFtmModule = node:current()/GptFtmModule)])"!]
            [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!LOOP "GptLpit/*"!]
        [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(node:refs(GptModuleRef)/../../GptLpitModule = node:current()/GptLpitModule)])"!]
            [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!]
        [!ENDIF!]
    [!ENDLOOP!]    

    [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(GptHwIp = 'SRTC')])"!]
        [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!]
    [!ENDIF!]
    
    [!IF "node:exists(//GptChannelConfigSet/GptChannelConfiguration/*[(GptHwIp = 'LPTMR')])"!]
        [!VAR "OutNumInstancesInPartition" = "$OutNumInstancesInPartition + 1"!]
    [!ENDIF!]            

    [!VAR "OutNumChannelInPartition" = "num:i(count(GptChannelConfiguration/*))"!]
    [!// Count channels and instances
    [!LOOP "GptChannelConfiguration/*"!]
        [!IF "contains(GptHwIp,'FTM')"!]
            [!VAR "OutNumGptChannelsUsingFtm" = "$OutNumGptChannelsUsingFtm + 1"!]
        [!ELSEIF "contains(GptHwIp,'SRTC')"!]
            [!VAR "OutNumGptChannelsUsingSRtc" = "$OutNumGptChannelsUsingSRtc + 1"!]
        [!ELSEIF "contains(GptHwIp,'LPTMR')"!]
            [!VAR "OutNumGptChannelsUsingLptmr" = "$OutNumGptChannelsUsingLptmr + 1"!]
        [!ELSEIF "contains(GptHwIp,'LPIT')"!]
            [!VAR "OutNumGptChannelsUsingLPit" = "$OutNumGptChannelsUsingLPit + 1"!]             
        [!ENDIF!]
    [!ENDLOOP!]
    [!ENDIF!]
[!ENDNOCODE!]
[!ENDMACRO!][!// End of Macro GPT_VARIABLES

[!ENDIF!] /* Avoid multiple inclusion ENDIF */
[!ENDNOCODE!] /*Gpt_Ipw_PluginMacros.m*/
/** @} */