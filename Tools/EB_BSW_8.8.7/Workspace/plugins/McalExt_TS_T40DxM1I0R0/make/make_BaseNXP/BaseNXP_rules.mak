#EB_Automotive_Makefile

#################################################################
# REGISTRY
Base_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Base_TS_T40D2M10I1R0/src/OsIf_Interrupts.c
Base_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Base_TS_T40D2M10I1R0/src/OsIf_Timer.c
Base_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Base_TS_T40D2M10I1R0/src/OsIf_Timer_System.c
Base_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Base_TS_T40D2M10I1R0/src/OsIf_Timer_System_Internal_Systick.c
Base_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/OsIf_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Base_src_FILES :=
endif
