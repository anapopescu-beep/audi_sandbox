#EB_Automotive_Makefile

#################################################################
# REGISTRY
Crypto_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Crypto_TS_T40D2M10I1R0/src/Crypto.c
Crypto_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Crypto_TS_T40D2M10I1R0/src/Crypto_ASRExtension.c
Crypto_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Crypto_TS_T40D2M10I1R0/src/Crypto_Ipw.c
Crypto_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Crypto_TS_T40D2M10I1R0/src/Crypto_KeyManagement.c
Crypto_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Crypto_TS_T40D2M10I1R0/src/Crypto_Util.c
Crypto_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Crypto_TS_T40D2M10I1R0/src/Csec_Ip.c
Crypto_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Crypto_TS_T40D2M10I1R0/src/Csec_Ip_Irq.c
Crypto_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Crypto_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Crypto_src_FILES :=
endif
