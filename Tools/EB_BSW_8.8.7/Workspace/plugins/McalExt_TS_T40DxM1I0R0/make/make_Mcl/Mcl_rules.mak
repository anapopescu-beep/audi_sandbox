#EB_Automotive_Makefile

#################################################################
# REGISTRY
Mcl_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcl_TS_T40D2M10I1R0/src/CDD_Mcl.c
Mcl_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcl_TS_T40D2M10I1R0/src/CDD_Mcl_Ipw.c
Mcl_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcl_TS_T40D2M10I1R0/src/Dma_Ip.c
Mcl_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcl_TS_T40D2M10I1R0/src/Dma_Ip_Driver_State.c
Mcl_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcl_TS_T40D2M10I1R0/src/Dma_Ip_Hw_Access.c
Mcl_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcl_TS_T40D2M10I1R0/src/Dma_Ip_Irq.c
Mcl_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcl_TS_T40D2M10I1R0/src/Dma_Ip_Multicore.c
Mcl_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcl_TS_T40D2M10I1R0/src/Flexio_Mcl_Ip.c
Mcl_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcl_TS_T40D2M10I1R0/src/Flexio_Mcl_Ip_HwAccess.c
Mcl_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcl_TS_T40D2M10I1R0/src/Flexio_Mcl_Ip_Irq.c
Mcl_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcl_TS_T40D2M10I1R0/src/Ftm_Mcl_Ip.c
Mcl_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcl_TS_T40D2M10I1R0/src/Trgmux_Ip.c
Mcl_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcl_TS_T40D2M10I1R0/src/Trgmux_Ip_HwAcc.c
Mcl_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/CDD_Mcl_*.c)
Mcl_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Dma_Ip_*.c)
Mcl_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Trgmux_Ip_*.c)
Mcl_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Flexio_Mcl_Ip_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Mcl_src_FILES :=
endif
