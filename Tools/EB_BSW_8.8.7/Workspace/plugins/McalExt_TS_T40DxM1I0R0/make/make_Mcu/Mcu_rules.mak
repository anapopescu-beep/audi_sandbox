#EB_Automotive_Makefile

#################################################################
# REGISTRY
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Clock_Ip.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Clock_Ip_Data.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Clock_Ip_Divider.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Clock_Ip_DividerTrigger.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Clock_Ip_ExtOsc.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Clock_Ip_FracDiv.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Clock_Ip_Frequency.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Clock_Ip_Gate.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Clock_Ip_IntOsc.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Clock_Ip_Irq.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Clock_Ip_Monitor.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Clock_Ip_Pll.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Clock_Ip_ProgFreqSwitch.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Clock_Ip_Selector.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Clock_Ip_Specific.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Mcu.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Mcu_Dem_Wrapper.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Mcu_Ipw.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Mcu_Ipw_Irq.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Power_Ip.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Power_Ip_CortexM4.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Power_Ip_PMC.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Power_Ip_PMC_Irq.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Power_Ip_Private.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Power_Ip_RCM.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Power_Ip_RCM_Irq.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Power_Ip_SIM.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Power_Ip_SMC.c
Mcu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcu_TS_T40D2M10I1R0/src/Ram_Ip.c
Mcu_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Mcu_*.c)
Mcu_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Power_Ip_*.c)
Mcu_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Clock_Ip_*.c)
Mcu_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Ram_Ip_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Mcu_src_FILES :=
endif
