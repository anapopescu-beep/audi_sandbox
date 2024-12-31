#EB_Automotive_Makefile

#################################################################
# DEFINITIONS
McalExt_GEN_FILES      += $(McalExt_OUTPUT_PATH)/include/modules.h
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/OsIf_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/include/Soc_*.h)
McalExt_GEN_FILES      += $(wildcard $(McalExt_OUTPUT_PATH)/src/OsIf_*.c)
CC_INCLUDE_PATH    += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Base_TS_T40D2M10I1R0/header
CC_INCLUDE_PATH    += $(McalExt_CORE_PATH)/include/BaseNXP

