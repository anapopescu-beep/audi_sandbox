#EB_Automotive_Makefile

#################################################################
# DEFINITIONS
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/CDD_Mcl_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Dma_Ip_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Flexio_Mcl_Ip_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Trgmux_Ip_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/CDD_Mcl_*.c)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Dma_Ip_*.c)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Flexio_Mcl_Ip_*.c)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Trgmux_Ip_*.c)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Cache_Ip_Cfg_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/CDD_Mcl_Cfg_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Dma_Ip_Cfg_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Flexio_Mcl_Ip_Cfg_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Ftm_Mcl_Ip_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Ftm_Mcl_Ip_Cfg_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Trgmux_Ip_Cfg_*.h)
CC_INCLUDE_PATH    += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Mcl_TS_T40D2M10I1R0/include
