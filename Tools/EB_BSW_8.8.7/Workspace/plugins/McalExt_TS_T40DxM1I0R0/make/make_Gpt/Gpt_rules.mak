#EB_Automotive_Makefile

#################################################################
# REGISTRY
Gpt_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Gpt_TS_T40D2M10I1R0/src/Ftm_Gpt_Ip.c
Gpt_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Gpt_TS_T40D2M10I1R0/src/Gpt.c
Gpt_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Gpt_TS_T40D2M10I1R0/src/Gpt_Ipw.c
Gpt_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Gpt_TS_T40D2M10I1R0/src/LPit_Gpt_Ip.c
Gpt_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Gpt_TS_T40D2M10I1R0/src/Lptmr_Gpt_Ip.c
Gpt_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Gpt_TS_T40D2M10I1R0/src/SRtc_Ip.c
Gpt_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Gpt_*.c)
Gpt_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Gpt_Ipw_*.c)
Gpt_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Ftm_Gpt_Ip_*.c)
Gpt_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/LPit_Gpt_Ip_*.c)
Gpt_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Lptmr_Gpt_Ip_*.c)
Gpt_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/SRtc_Ip_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Gpt_src_FILES :=
endif
