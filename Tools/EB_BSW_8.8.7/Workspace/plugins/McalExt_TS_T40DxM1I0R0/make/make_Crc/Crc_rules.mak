#EB_Automotive_Makefile

#################################################################
# REGISTRY
Crc_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Crc_TS_T40D2M10I1R0/src/CDD_Crc.c
Crc_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Crc_TS_T40D2M10I1R0/src/Crc_Ip.c
Crc_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Crc_TS_T40D2M10I1R0/src/Crc_Ip_Hardware.c
Crc_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Crc_TS_T40D2M10I1R0/src/Crc_Ip_Lookup_Tables.c
Crc_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Crc_TS_T40D2M10I1R0/src/Crc_Ip_Software.c
Crc_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Crc_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Crc_src_FILES :=
endif
