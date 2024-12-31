DERIVATIVE = S32K144

ifeq ($(BUILD_MODE),RELEASE)
RELEASE_BUILD_DEF := ALV_RELEASE_BUILD=1
else
RELEASE_BUILD_DEF :=
endif

COMP_DEFINES := $(RELEASE_BUILD_DEF) \
_ICCARM_                                              \
OSIARARM                                              \
CANSM_NO_SYMBOLS_WITHOUT_PREFIX                       \
COMM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES               \
NM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES                 \
DISABLE_MCAL_INTERMODULE_ASR_CHECK                    \
COMPILERCFG_EXTENSION_MCAL_FILE                       \
I_KNOW_THAT_THIS_CODE_IS_NOT_FOR_PRODUCTION=1         \
PLATFORMS_TOOLCHAIN=PLATFORMS_iar                     \
ATOMICS_USER_MULTICORE_CASE=0                         \
BOARD_ISR_CAN0=1                                      \
BOARD_ISR_STMTIMER=0                                  \
AUTOSAR_OS_NOT_USED=1                                 \
USE_SW_VECTOR_MODE=1                                  \
AUTOSAR_CAN_INTERRUPT=1                               \
PDUR_PROVIDE_ADJACENT_MODULE_VENDOR_SYMBOLIC_NAMES=1  \
TS_ARCH_FAMILY=TS_CORTEXM                             \
TS_ARCH_DERIVATE=TS_S32K14X                           \
ATOMICS_USE_GENERIC_IMPL=1  
			
CPP_DEFINES := $(COMP_DEFINES) 

AAS_DEFINES := I_KNOW_THAT_THIS_CODE_IS_NOT_FOR_PRODUCTION=1         \
PLATFORMS_TOOLCHAIN=PLATFORMS_iar                     \
ATOMICS_USER_MULTICORE_CASE=0                         \
BOARD_ISR_CAN0=1                                      \
BOARD_ISR_STMTIMER=0                                  \
AUTOSAR_OS_NOT_USED=1                                 \
USE_SW_VECTOR_MODE=1                                  \
AUTOSAR_CAN_INTERRUPT=1                               \
PDUR_PROVIDE_ADJACENT_MODULE_VENDOR_SYMBOLIC_NAMES=1  \
TS_ARCH_FAMILY=TS_CORTEXM                             \
TS_ARCH_DERIVATE=TS_S32K14X                           \
ATOMICS_USE_GENERIC_IMPL=1                            
	

COMP_INCLUDES := $(foreach COMPONENT,$(COMPONENTS_LIST),$(foreach MODULE,$($(COMPONENT)_COMPONENTS_LIST),$(call $(COMPONENT)_INCLUDES_DIR,$(MODULE))))
	   

COMP_OPT_BSW := -o $(OBJ_DIR)/           \
                --no_cse   \
                --no_unroll                      \
                --cpu Cortex-M4         \
                --no_inline                \
                --no_code_motion     \
                --no_tbaa 		\
                --no_clustering  \
                --no_scheduling            \
                --debug       \
                --endian=little      \
                -e \
                --fpu=None      \
                -Ol  \
                $(if $(call seq,$(GENERATE_LST_FILES),TRUE),-l $(LST_DIR)) \
                $(addprefix -D,$(COMP_DEFINES)) \
                $(addprefix -I,$(COMP_INCLUDES))
COMP_OPT_EBSW := $(COMP_OPT_BSW)
COMP_OPT_EBSWAPP := $(COMP_OPT_BSW)
COMP_OPT_TGEN := $(COMP_OPT_BSW)
COMP_OPT_NXPMCAL := -o $(OBJ_DIR)/          \
	                --no_wrap_diagnostics   \
	                -e                      \
	                --cpu Cortex-M4         \
	                --fpu None              \
	                --debug                 \
	                --dlib_config '$(subst \,/,$(COMPILER_INC)/DLib_Config_Normal.h)' \
	                --endian little   \
	                --cpu_mode thumb  \
	                -Ohz              \
	                --no_clustering   \
	                --no_mem_idioms   \
	                --no_code_motion  \
	                --no_explicit_zero_opt  \
	                --require_prototypes    \
	                --no_system_include     \
	                $(if $(call seq,$(GENERATE_LST_FILES),TRUE),-l $(LST_DIR)) \
	                $(addprefix -D,$(COMP_DEFINES)) \
	                $(addprefix -I,$(COMP_INCLUDES))
DEP_OPT := $(COMP_OPT_BSW)

ASM_OPT_BSW   = --cpu \
				Cortex-M4 \
				--fpu None \
				-s+ \
				-r \
				$(addprefix -I,$(COMP_INCLUDES)) \
				$(addprefix -D,$(AS_DEFINES)) \
				-o $@
ASM_OPT_EBSW = $(ASM_OPT_BSW)
ASM_OPT_EBSWAPP = $(ASM_OPT_BSW)
ASM_OPT_TGEN = $(ASM_OPT_BSW)
ASM_OPT_NXPMCAL = $(ASM_OPT_BSW)

CPP_OPT_BSW = $(addprefix -D,$(CPP_DEFINES)) \
              $(addprefix -I,$(COMP_INCLUDES)) \
              -E \
              -x
CPP_OPT_EBSW := $(CPP_OPT_BSW)
CPP_OPT_EBSWAPP := $(CPP_OPT_BSW)
CPP_OPT_TGEN := $(CPP_OPT_BSW)
CPP_OPT_NXPMCAL := $(CPP_OPT_BSW)
LINK_CMD_XCL := $(TMP)/ilinkCommandLine.xcl

LINK_CMD_OPT  = --config "$(VARIANT_TARGET_KEY)/$(LINKER_FILE_STEM).$(LNK_SUFFIX)" \
                --map "$(OUT_DIR)/$(TARGET).$(MAP_SUFFIX)" \
                -o "$(OUT_DIR)/$(TARGET).$(BINARY_SUFFIX)" \
                --no_out_extension	\
                --no_library_search  \
                --entry boardResetStart 	\
                --text_out locale \
                --vfe \
                --redirect _Printf=_PrintfFullNoMb \
                --redirect _Scanf=_ScanfFullNoMb
                
LINK_OPT = -f "$(call getWinDir,$(LINK_CMD_XCL))"  

LINK_LIB_OBJ =

LIB_OPT :=

CHEX_PRE_OPT := --srec \
                --silent
CHEX_POST_OPT = "$@"

DEP_PRE_OPT :=
DEP_POST_OPT = $(DEP_OPT) --dependencies=n $@
DEP_OUT_OPT = >> $(ERR_DIR)/$(basename $(notdir $@)).$(DEP_WARN_SUFFIX) 2>&1
	
ELF_FILE_GENERATION := FALSE
PREPROCESS_AS_SUPPORT := TRUE
GENERATE_LINKER_CMD := TRUE

# filename    : Makefile.compiler.options
# description : Compiler/Assembler/Linker/Librarian options variable setup
# author      : Dan Dustinta
# copyright   : Copyright (c) 2018-2022, Autoliv Romania
# version     : 2.0.0
# email       : dan.dustinta@autoliv.com
# status      : Released
