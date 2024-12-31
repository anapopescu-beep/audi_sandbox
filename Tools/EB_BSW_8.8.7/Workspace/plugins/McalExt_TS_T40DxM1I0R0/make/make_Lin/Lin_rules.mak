#EB_Automotive_Makefile

#################################################################
# REGISTRY
Lin_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Lin_TS_T40D2M10I1R0/src/Flexio_Lin_Ip.c
Lin_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Lin_TS_T40D2M10I1R0/src/Lin.c
Lin_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Lin_TS_T40D2M10I1R0/src/Lin_ASRExt.c
Lin_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Lin_TS_T40D2M10I1R0/src/Lin_Ipw.c
Lin_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Lin_TS_T40D2M10I1R0/src/Lin_Ip_Common.c
Lin_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Lin_TS_T40D2M10I1R0/src/Lpuart_Lin_Ip.c
Lin_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Lin_TS_T40D2M10I1R0/src/Lpuart_Lin_Ip_Hw_Access.c
Lin_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Lin_TS_T40D2M10I1R0/src/Lpuart_Lin_Ip_Irq.c
Lin_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Lin_*.c)
Lin_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Flexio_Lin_Ip_*.c)
Lin_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Lin_Ipw_*.c)
Lin_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Lpuart_Lin_Ip_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Lin_src_FILES :=
endif
