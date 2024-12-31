#EB_Automotive_Makefile

#################################################################
# REGISTRY
Adc_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Adc_TS_T40D2M10I1R0/src/Adc.c
Adc_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Adc_TS_T40D2M10I1R0/src/Adc_Ip.c
Adc_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Adc_TS_T40D2M10I1R0/src/Adc_Ipw.c
Adc_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Adc_TS_T40D2M10I1R0/src/Adc_Ipw_Irq.c
Adc_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Adc_TS_T40D2M10I1R0/src/Adc_Ip_Irq.c
Adc_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Adc_TS_T40D2M10I1R0/src/Pdb_Adc_Ip.c
Adc_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Adc_TS_T40D2M10I1R0/src/Pdb_Adc_Ip_Irq.c
Adc_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Adc_*.c)
Adc_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Adc_Ipw_*.c)
Adc_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Pdb_Adc_Ip_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Adc_src_FILES :=
endif
