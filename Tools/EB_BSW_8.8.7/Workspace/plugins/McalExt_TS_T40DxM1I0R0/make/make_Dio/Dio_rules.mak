#EB_Automotive_Makefile

#################################################################
# REGISTRY
Dio_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Dio_TS_T40D2M10I1R0/src/Dio.c
Dio_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Dio_TS_T40D2M10I1R0/src/Dio_Ipw.c
Dio_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Dio_TS_T40D2M10I1R0/src/Gpio_Dio_Ip.c
Dio_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Dio_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Dio_src_FILES :=
endif
