#EB_Automotive_Makefile

#################################################################
# DEFINITIONS
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Flexio_Lin_Ip_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Lin_Ipw_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Lin_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Lpuart_Lin_Ip_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Flexio_Lin_Ip_*.c)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Lin_Ipw_*.c)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Lin_*.c)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Lpuart_Lin_Ip_*.c)
CC_INCLUDE_PATH    += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Lin_TS_T40D2M10I1R0/include
