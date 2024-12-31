#EB_Automotive_Makefile

#################################################################
# REGISTRY
I2c_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/I2c_TS_T40D2M10I1R0/src/CDD_I2c.c
I2c_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/I2c_TS_T40D2M10I1R0/src/Flexio_I2c_Ip.c
I2c_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/I2c_TS_T40D2M10I1R0/src/I2c_Ipw.c
I2c_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/I2c_TS_T40D2M10I1R0/src/Lpi2c_Ip.c
I2c_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/I2c_TS_T40D2M10I1R0/src/Lpi2c_Ip_HwAccess.c
I2c_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/I2c_TS_T40D2M10I1R0/src/Lpi2c_Ip_Irq.c
I2c_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/I2c_*.c)
I2c_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/CDD_I2c_*.c)
I2c_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Flexio_I2c_Ip_*.c)
I2c_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Lpi2c_Ip_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
I2c_src_FILES :=
endif
