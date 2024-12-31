#EB_Automotive_Makefile

#################################################################
# REGISTRY
Fee_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/eclipse/plugins/Fee_TS_T40D2M10I1R0/src/Fee.c
Fee_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Fee_*.c)
ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Fee_src_FILES :=
endif
