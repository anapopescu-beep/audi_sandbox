#EB_Automotive_Makefile

#################################################################
# REGISTRY
Rm_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Rm_TS_T40D2M10I1R0/src/CDD_Rm.c
Rm_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Rm_TS_T40D2M10I1R0/src/CDD_Rm_Ipw.c
Rm_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Rm_TS_T40D2M10I1R0/src/Mpu_Ip.c
Rm_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/CDD_Rm_*.c)
Rm_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/CDD_Rm_Ipw_*.c)
Rm_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Mpu_Ip_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Rm_src_FILES :=
endif
