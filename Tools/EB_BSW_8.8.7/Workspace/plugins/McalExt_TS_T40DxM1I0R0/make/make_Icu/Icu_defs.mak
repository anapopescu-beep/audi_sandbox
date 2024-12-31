#EB_Automotive_Makefile

#################################################################
# DEFINITIONS
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Cmp_Ip_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Ftm_Icu_Ip_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Icu_Ipw_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Icu_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Lpit_Icu_Ip_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Lptmr_Icu_Ip_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Port_Ci_Icu_Ip_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Cmp_Ip_*.c)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Ftm_Icu_Ip_*.c)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Icu_*.c)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Icu_Ipw_*.c)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Lpit_Icu_Ip_*.c)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Lptmr_Icu_Ip_*.c)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/Port_Ci_Icu_Ip_*.c)
CC_INCLUDE_PATH    += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Icu_TS_T40D2M10I1R0/include
