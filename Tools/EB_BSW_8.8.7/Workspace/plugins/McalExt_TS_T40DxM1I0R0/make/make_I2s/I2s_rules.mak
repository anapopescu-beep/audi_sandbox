#EB_Automotive_Makefile

#################################################################
# REGISTRY
I2s_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/I2s_TS_T40D2M10I1R0/src/CDD_I2s.c
I2s_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/I2s_TS_T40D2M10I1R0/src/Flexio_I2s_Ip.c
I2s_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/I2s_TS_T40D2M10I1R0/src/I2s_Ipw.c
I2s_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/I2s_TS_T40D2M10I1R0/src/Sai_Ip.c
I2s_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/I2s_TS_T40D2M10I1R0/src/Sai_Ip_Isr.c
I2s_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/CDD_I2s_*.c)
I2s_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Flexio_I2s_Ip_*.c)
I2s_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/I2s_Ipw_*.c)
I2s_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Sai_Ip_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
I2s_src_FILES :=
endif
