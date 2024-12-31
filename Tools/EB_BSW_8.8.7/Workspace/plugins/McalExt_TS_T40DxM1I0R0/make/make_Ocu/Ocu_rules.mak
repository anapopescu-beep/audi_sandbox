#EB_Automotive_Makefile

#################################################################
# REGISTRY
Ocu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Ocu_TS_T40D2M10I1R0/src/Ftm_Ocu_Ip.c
Ocu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Ocu_TS_T40D2M10I1R0/src/Ftm_Ocu_Ip_Irq.c
Ocu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Ocu_TS_T40D2M10I1R0/src/Ocu.c
Ocu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Ocu_TS_T40D2M10I1R0/src/Ocu_Ipw.c
Ocu_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Ocu_*.c)
Ocu_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Ocu_Ipw_*.c)
Ocu_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Ftm_Ocu_Ip_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Ocu_src_FILES :=
endif
