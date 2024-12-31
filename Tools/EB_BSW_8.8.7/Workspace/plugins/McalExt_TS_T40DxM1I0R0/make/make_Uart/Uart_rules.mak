#EB_Automotive_Makefile

#################################################################
# REGISTRY
Uart_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Uart_TS_T40D2M10I1R0/src/Flexio_Uart_Ip.c
Uart_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Uart_TS_T40D2M10I1R0/src/Flexio_Uart_Ip_Irq.c
Uart_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Uart_TS_T40D2M10I1R0/src/Lpuart_Uart_Ip.c
Uart_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Uart_TS_T40D2M10I1R0/src/Lpuart_Uart_Ip_Irq.c
Uart_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Uart_TS_T40D2M10I1R0/src/Uart.c
Uart_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Uart_TS_T40D2M10I1R0/src/Uart_Ipw.c
Uart_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Flexio_Uart_Ip_*.c)
Uart_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Lpuart_Uart_Ip_*.c)
Uart_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Uart_Ipw_*.c)
Uart_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Uart_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Uart_src_FILES :=
endif
