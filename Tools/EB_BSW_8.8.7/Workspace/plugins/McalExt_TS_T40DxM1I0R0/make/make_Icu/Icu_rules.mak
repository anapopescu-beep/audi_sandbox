#EB_Automotive_Makefile

#################################################################
# REGISTRY
Icu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Icu_TS_T40D2M10I1R0/src/Cmp_Ip.c
Icu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Icu_TS_T40D2M10I1R0/src/Ftm_Icu_Ip.c
Icu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Icu_TS_T40D2M10I1R0/src/Ftm_Icu_Ip_Irq.c
Icu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Icu_TS_T40D2M10I1R0/src/Icu.c
Icu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Icu_TS_T40D2M10I1R0/src/Icu_Ipw.c
Icu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Icu_TS_T40D2M10I1R0/src/Lpit_Icu_Ip.c
Icu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Icu_TS_T40D2M10I1R0/src/Lpit_Icu_Ip_Irq.c
Icu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Icu_TS_T40D2M10I1R0/src/Lptmr_Icu_Ip.c
Icu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Icu_TS_T40D2M10I1R0/src/Lptmr_Icu_Ip_Irq.c
Icu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Icu_TS_T40D2M10I1R0/src/Port_Ci_Icu_Ip.c
Icu_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Icu_TS_T40D2M10I1R0/src/Port_Ci_Icu_Ip_Irq.c
Icu_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Icu_*.c)
Icu_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Cmp_Ip_*.c)
Icu_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Ftm_Icu_Ip_*.c)
Icu_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Icu_Ipw_*.c)
Icu_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Lpit_Icu_Ip_*.c)
Icu_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Lptmr_Icu_Ip_*.c)
Icu_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Port_Ci_Icu_Ip_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Icu_src_FILES :=
endif
