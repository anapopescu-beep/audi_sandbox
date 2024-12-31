#EB_Automotive_Makefile

#################################################################
# REGISTRY
Can_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Can_TS_T40D2M10I1R0/src/Can.c
Can_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Can_TS_T40D2M10I1R0/src/Can_Ipw.c
Can_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Can_TS_T40D2M10I1R0/src/Can_Irq.c
Can_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Can_TS_T40D2M10I1R0/src/FlexCAN_Ip.c
Can_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Can_TS_T40D2M10I1R0/src/FlexCAN_Ip_HwAccess.c
Can_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Can_TS_T40D2M10I1R0/src/FlexCAN_Ip_Irq.c
Can_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Can_*.c)
Can_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Can_Ipw_*.c)
Can_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/FlexCAN_Ip_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Can_src_FILES :=
endif
