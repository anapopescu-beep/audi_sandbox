#EB_Automotive_Makefile

#################################################################
# REGISTRY
Wdg_43_Instance1_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Wdg_TS_T40D2M10I1R0/src/Ewm_Ip.c
Wdg_43_Instance1_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Wdg_TS_T40D2M10I1R0/src/Ewm_Ip_Irq.c
Wdg_43_Instance1_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Wdg_TS_T40D2M10I1R0/src/Wdg_43_Instance1.c
Wdg_43_Instance1_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Wdg_TS_T40D2M10I1R0/src/Wdg_Channel.c
Wdg_43_Instance1_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Wdg_TS_T40D2M10I1R0/src/Wdg_Ipw.c
Wdg_43_Instance1_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Wdg_TS_T40D2M10I1R0/src/Wdg_Ipw_Irq.c
Wdg_43_Instance1_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Wdg_TS_T40D2M10I1R0/src/Wdog_Ip.c
Wdg_43_Instance1_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Wdg_TS_T40D2M10I1R0/src/Wdog_Ip_Irq.c
Wdg_43_Instance1_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Wdg_43_Instance1_*.c)
Wdg_43_Instance1_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Wdg_43_Instance1_Ipw_*.c)
Wdg_43_Instance1_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Ewm_Ip_*.c)
Wdg_43_Instance1_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Wdog_Ip_*.c)
Wdg_43_Instance1_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Wdg_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Wdg_43_Instance1_src_FILES :=
endif
