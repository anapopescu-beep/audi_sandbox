DERIVATIVE = S32K144

ifeq ($(BUILD_MODE),RELEASE)
RELEASE_BUILD_DEF := ALV_RELEASE_BUILD=1
else
RELEASE_BUILD_DEF :=
endif

COMP_DEFINES := $(RELEASE_BUILD_DEF) \
                __ICCARM__  \
                OSIARARM  \
                TS_ARCH_FAMILY=TS_CORTEXM \
                TS_ARCH_DERIVATE=TS_S32K14X \
                CANSM_NO_SYMBOLS_WITHOUT_PREFIX \
                ECUM_PROVIDE_LEGACY_SYMBOLIC_NAMES \
                COMM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES \
                NM_DONT_PROVIDE_LEGACY_SYMBOLIC_NAMES \
                DISABLE_MCAL_INTERMODULE_ASR_CHECK \
                COMPILERCFG_EXTENSION_MCAL_FILE \
                OS_TOOL=OS_iar \
                OSB_TOOL=OSB_iar \
                OS_ARCH=OS_CORTEXM \
                OS_KERNEL_TYPE=OS_SYSTEM_CALL \
                OS_DEVELOPMENT_SANITY_CHECKS=0 \
                OS_MEMMAP=0 \
                OS_CPU=OS_S32K14X \
                OS_N_CORES=1 \
                ATOMICS_USE_GENERIC_IMPL=1 \
                OS_INITCORE=0 \
                ATOMICS_USER_MULTICORE_CASE=0 \
                KU8_GLOBAL_NUMBER_OF_SOLENOIDS=$(ECS_NB_OF_SOLENOIDS) \
				S32K144 \
				IAR \
				USE_SW_VECTOR_MODE 
#				MCAL_ENABLE_USER_MODE_SUPPORT 
			
CPP_DEFINES := EMPTY \
               $(subst __ICCARM__,_ICCARM_,$(COMP_DEFINES))

AS_DEFINES := 	OS_KERNEL_TYPE=OS_SYSTEM_CALL \
				OS_TOOL=OS_iar \
				OS_CPU=OS_S32K14X \
				OS_INITCORE=0 \
				OS_N_CORES=1 \
				OS_MEMMAP=0 \
				OS_DEVELOPMENT_SANITY_CHECKS=0 \
				ATOMICS_USE_GENERIC_IMPL=1 \
				TS_ARCH_DERIVATE=TS_S32K14X \
				OS_ARCH=OS_CORTEXM \
				ATOMICS_USER_MULTICORE_CASE=0 \
				TS_ARCH_FAMILY=TS_CORTEXM 

COMP_INCLUDES := $(foreach COMPONENT,$(COMPONENTS_LIST),$(foreach MODULE,$($(COMPONENT)_COMPONENTS_LIST),$(call $(COMPONENT)_INCLUDES_DIR,$(MODULE))))
COMP_INCLUDES_NXPMCAL := $(foreach COMPONENT,$(COMPONENTS_LIST),$(foreach MODULE,$($(COMPONENT)_COMPONENTS_LIST),$(call $(COMPONENT)_INCLUDES_DIR,$(MODULE))))
#COMP_INCLUDES_NXPMCAL := $(foreach COMPONENT,$(COMPONENTS_LIST),$(foreach MODULE,$($(COMPONENT)_COMPONENTS_LIST),$(if $(call seq,$(BASE_VERSION),$(MODULE)),$(call NXPMCAL_INCLUDES_DIR,$(BASE_MCAL_VERSION)),$(call $(COMPONENT)_INCLUDES_DIR,$(MODULE)))))

COMP_OPT_BSW_HIGH_OPTIMIZATION_DBG := --no_cse         \
					                  --no_unroll      \
					                  --no_inline      \
					                  --no_code_motion \
					                  --no_tbaa        \
					                  --no_clustering  \
					                  --no_scheduling  
			                 
COMP_OPT_BSW_HIGH_OPTIMIZATION := --no_code_motion \
                                  --no_size_constraints 
                         
COMP_OPT_BSW_OPTIMIZATION := $(if $(call seq,$(BUILD_MODE),RELEASE),$(COMP_OPT_BSW_HIGH_OPTIMIZATION),$(COMP_OPT_BSW_HIGH_OPTIMIZATION))

COMP_OPT_BSW := -o $(OBJ_DIR)/          \
                --no_wrap_diagnostics   \
                -e                      \
                --cpu Cortex-M4f        \
                --fpu FPv4-SP           \
                --debug                 \
                --dlib_config '$(subst \,/,$(COMPILER_INC)/DLib_Config_Normal.h)' \
                --endian little         \
                --cpu_mode thumb        \
                -Ohs                    \
                $(COMP_OPT_BSW_OPTIMIZATION)     \
                $(if $(call seq,$(GENERATE_LST_FILES),TRUE),-l $(LST_DIR)) \
                $(addprefix -D,$(COMP_DEFINES)) \
                $(addprefix -I,$(COMP_INCLUDES))

COMP_OPT_EBSW := $(COMP_OPT_BSW) \
                $(addprefix -I,$(call NXPMCAL_INCLUDES_DIR,$(BASE_MCAL_VERSION)))

COMP_OPT_TGEN := $(COMP_OPT_BSW)

COMP_OPT_NXPMCAL := -o $(OBJ_DIR)/          \
	                --no_wrap_diagnostics   \
	                -e                      \
	                --cpu Cortex-M4f         \
	                --fpu FPv4-SP              \
	                --debug                 \
	                --dlib_config '$(subst \,/,$(COMPILER_INC)/DLib_Config_Normal.h)' \
	                -I'$(COMPILER_INC)'     \
	                --endian little   \
	                --cpu_mode thumb  \
	                -Ohs              \
	                --no_clustering   \
	                --no_mem_idioms   \
	                --no_code_motion  \
	                --no_explicit_zero_opt  \
	                --no_system_include     \
                    $(if $(call seq,$(GENERATE_LST_FILES),TRUE),-l $(LST_DIR)) \
	                $(addprefix -D,$(COMP_DEFINES)) \
	                $(addprefix -I,$(COMP_INCLUDES_NXPMCAL))
	                
COMP_OPT_TGENMCAL := $(COMP_OPT_NXPMCAL)

COMP_OPT_T1 = $(COMP_OPT_BSW)
COMP_OPT_NXPSCST = $(COMP_OPT_BSW)

DEP_OPT := $(COMP_OPT_BSW)

ASM_OPT_BSW   = --cpu Cortex-M4f \
				--fpu FPv4-SP \
				-s+ \
				-r \
				-g \
				$(addprefix -I,$(COMP_INCLUDES)) \
				$(addprefix -D,$(AS_DEFINES)) \
				-o $@
				
ASM_OPT_EBSW = $(ASM_OPT_BSW)
ASM_OPT_TGEN = $(ASM_OPT_BSW)
ASM_OPT_TGENMCAL = $(ASM_OPT_BSW)
ASM_OPT_NXPMCAL = $(ASM_OPT_BSW)
ASM_OPT_T1 = $(ASM_OPT_BSW)
ASM_OPT_NXPSCST = -DM4_DEVICE_RESERVED_ADDR=0x40080000 \
                  $(ASM_OPT_BSW)

CPP_OPT_BSW = $(addprefix -D,$(CPP_DEFINES)) \
              $(addprefix -I,$(COMP_INCLUDES)) \
              -E \
              -x

CPP_OPT_EBSW := $(CPP_OPT_BSW)
CPP_OPT_TGEN := $(CPP_OPT_BSW)
CPP_OPT_TGENMCAL := $(CPP_OPT_BSW)
CPP_OPT_NXPMCAL := $(CPP_OPT_BSW)
CPP_OPT_T1 := $(CPP_OPT_BSW)
CPP_OPT_NXPSCST := $(CPP_OPT_BSW)
PREPROCESS_AS_IGNORE_NXPSCST := TRUE

LINK_CMD_XCL := $(TMP)/ilinkCommandLine.xcl

LINK_CMD_OPT  = --config "$(VARIANT_TARGET_KEY)/$(LINKER_FILE_STEM).$(LNK_SUFFIX)" \
                --map "$(OUT_DIR)/$(TARGET).$(MAP_SUFFIX)" \
                -o "$(OUT_DIR)/$(TARGET).$(BINARY_SUFFIX)" \
                --no_wrap_diagnostics \
                --entry boardResetStart \
                --semihosting \
                --no_free_heap \
                --cpu Cortex-M4f         \
	            --fpu FPv4-SP              \
                $(SOURCES_DIR)/Supplier/T1/lib/libt1base.a \
                $(SOURCES_DIR)/Supplier/T1/lib/libt1cont.a \
                $(SOURCES_DIR)/Supplier/T1/lib/libt1delay.a \
                $(SOURCES_DIR)/Supplier/T1/lib/libt1flex.a \
                $(SOURCES_DIR)/Supplier/T1/lib/libt1mod.a \
                $(SOURCES_DIR)/Supplier/T1/lib/libt1scope.a \
                --enable_stack_usage 
                
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
