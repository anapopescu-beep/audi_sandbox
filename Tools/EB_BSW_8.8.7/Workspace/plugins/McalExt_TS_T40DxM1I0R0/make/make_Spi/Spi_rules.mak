#EB_Automotive_Makefile

#################################################################
# REGISTRY
Spi_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Spi_TS_T40D2M10I1R0/src/Flexio_Spi_Ip.c
Spi_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Spi_TS_T40D2M10I1R0/src/Flexio_Spi_Ip_Irq.c
Spi_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Spi_TS_T40D2M10I1R0/src/Lpspi_Ip.c
Spi_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Spi_TS_T40D2M10I1R0/src/Lpspi_Ip_Irq.c
Spi_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Spi_TS_T40D2M10I1R0/src/Spi.c
Spi_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Spi_TS_T40D2M10I1R0/src/Spi_Ipw.c
Spi_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Spi_*.c)
Spi_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Spi_Ipw_*.c)
Spi_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Lpspi_Ip_*.c)
Spi_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Flexio_Spi_Ip_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Spi_src_FILES :=
endif
