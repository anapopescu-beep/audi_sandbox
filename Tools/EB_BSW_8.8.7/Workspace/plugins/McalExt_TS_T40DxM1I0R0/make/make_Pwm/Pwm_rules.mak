#EB_Automotive_Makefile

#################################################################
# REGISTRY
Pwm_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Pwm_TS_T40D2M10I1R0/src/Flexio_Pwm_Ip.c
Pwm_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Pwm_TS_T40D2M10I1R0/src/Flexio_Pwm_Ip_Irq.c
Pwm_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Pwm_TS_T40D2M10I1R0/src/Ftm_Pwm_Ip.c
Pwm_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Pwm_TS_T40D2M10I1R0/src/Ftm_Pwm_Ip_Irq.c
Pwm_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Pwm_TS_T40D2M10I1R0/src/Pwm.c
Pwm_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Pwm_TS_T40D2M10I1R0/src/Pwm_Ipw.c
Pwm_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Pwm_TS_T40D2M10I1R0/src/Pwm_Ipw_Notif.c
Pwm_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Pwm_*.c)
Pwm_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Flexio_Pwm_Ip_*.c)
Pwm_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Ftm_Pwm_Ip_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Pwm_src_FILES :=
endif
