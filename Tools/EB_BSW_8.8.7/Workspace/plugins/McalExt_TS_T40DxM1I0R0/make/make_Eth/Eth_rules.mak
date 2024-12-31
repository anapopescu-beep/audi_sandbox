#EB_Automotive_Makefile

#################################################################
# REGISTRY
Eth_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Eth_TS_T40D2M10I1R0/src/Enet_Ip.c
Eth_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Eth_TS_T40D2M10I1R0/src/Enet_Ip_Hw_Access.c
Eth_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Eth_TS_T40D2M10I1R0/src/Enet_Ip_Irq.c
Eth_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Eth_TS_T40D2M10I1R0/src/Eth.c
Eth_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Eth_TS_T40D2M10I1R0/src/Eth_Ipw.c
Eth_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Eth_TS_T40D2M10I1R0/src/Eth_Ipw_Irq.c
Eth_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Eth_TS_T40D2M10I1R0/src/Eth_Irq.c
Eth_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Enet_Ip_*.c)
Eth_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Eth_Ipw_*.c)
Eth_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Eth_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Eth_src_FILES :=
endif
