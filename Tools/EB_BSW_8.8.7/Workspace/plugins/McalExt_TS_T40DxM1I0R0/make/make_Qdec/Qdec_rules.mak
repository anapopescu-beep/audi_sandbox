#EB_Automotive_Makefile

#################################################################
# REGISTRY
Qdec_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Qdec_TS_T40D2M10I1R0/src/Ftm_Qdec_Ip.c
Qdec_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Qdec_TS_T40D2M10I1R0/src/Ftm_Qdec_Ip_Irq.c
Qdec_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Qdec_TS_T40D2M10I1R0/src/Qdec.c
Qdec_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Qdec_TS_T40D2M10I1R0/src/Qdec_Ipw.c
Qdec_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Qdec_*.c)
Qdec_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Qdec_Ipw_*.c)
Qdec_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Ftm_Qdec_Ip_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Qdec_src_FILES :=
endif
