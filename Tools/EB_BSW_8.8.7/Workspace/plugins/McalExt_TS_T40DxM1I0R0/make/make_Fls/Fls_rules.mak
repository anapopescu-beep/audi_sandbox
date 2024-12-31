#EB_Automotive_Makefile

#################################################################
# REGISTRY
Fls_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Fls_TS_T40D2M10I1R0/src/Fls.c
Fls_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Fls_TS_T40D2M10I1R0/src/Fls_IPW.c
Fls_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Fls_TS_T40D2M10I1R0/src/Ftfc_Fls_Ip.c
Fls_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Fls_TS_T40D2M10I1R0/src/Ftfc_Fls_Ip_Ac.c
Fls_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Fls_TS_T40D2M10I1R0/src/Qspi_Ip.c
Fls_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Fls_TS_T40D2M10I1R0/src/Qspi_Ip_Controller.c
Fls_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Fls_TS_T40D2M10I1R0/src/Qspi_Ip_Sfdp.c
Fls_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Fls_*.c)
Fls_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Ftfc_Fls_Ip_*.c)
Fls_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Qspi_Ip_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Fls_src_FILES :=
endif
