# *****************************************************************************
TOOLPATH_COMPILER ?= 
# *********************Compiler Options******************************************
CC_OPT += --no_wrap_diagnostics 
CC_OPT += -e 
CC_OPT += --cpu Cortex-M4f 
CC_OPT += --fpu FPv4-SP 
CC_OPT += --debug 
CC_OPT += --endian little 
CC_OPT += --cpu_mode thumb 
CC_OPT += --no_clustering 
CC_OPT += -DOSB_TOOL=OSB_iar 
CC_OPT += -Ohz 
CC_OPT += --no_mem_idioms 
CC_OPT += --no_explicit_zero_opt 
CC_OPT += --require_prototypes 
CC_OPT += -DS32K1XX 
CC_OPT += -DS32K144 
CC_OPT += -DIAR 
CC_OPT += -DUSE_SW_VECTOR_MODE 
CC_OPT += -DI_CACHE_ENABLE 
CC_OPT += -DENABLE_FPU 
CC_OPT += -DMCAL_ENABLE_USER_MODE_SUPPORT 
CC_OPT += --diag_suppress=Pa050 
# *********************Linker Options******************************************
LINK_OPT += --no_wrap_diagnostics 
LINK_OPT += --entry boardResetStart 
LINK_OPT += --cpu Cortex-M4f 
LINK_OPT += --fpu FPv4-SP 
LINK_OPT += --enable_stack_usage 
LINK_OPT += --skip_dynamic_initialization 
# *********************Assembler Options******************************************
ASM_OPT += --cpu Cortex-M4f 
ASM_OPT += -r 
ASM_OPT += -g 
