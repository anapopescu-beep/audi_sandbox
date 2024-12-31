#EB_Automotive_Makefile

#################################################################
# DEFINITIONS
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Flexio_Uart_Ip_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Lpuart_Uart_Ip_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Uart_Ipw_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Uart_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Flexio_Uart_Ip_*.c)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Lpuart_Uart_Ip_*.c)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Uart_Ipw_*.c)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Uart_*.c)
CC_INCLUDE_PATH    += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Uart_TS_T40D2M10I1R0/include
