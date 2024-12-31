DERIVATIVE = S32K144

ifeq ($(BUILD_MODE),RELEASE)
RELEASE_BUILD_DEF := ALV_RELEASE_BUILD=1
else
RELEASE_BUILD_DEF :=
endif

COMP_DEFINES := $(RELEASE_BUILD_DEF) \
                __ICCARM__
			
CPP_DEFINES := EMPTY

AS_DEFINES := 	

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
                --fpu=None       \
                -Ol  \
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

CPP_OPT_BSW = $(addprefix -D,$(CPP_DEFINES)) \
              $(addprefix -I,$(COMP_INCLUDES)) \
              -E \
              -x

LINK_CMD_XCL := $(TMP)/ilinkCommandLine.xcl

LINK_CMD_OPT  = --config "$(VARIANT_TARGET_KEY)/$(LINKER_FILE_STEM).$(LNK_SUFFIX)" \
                --map "$(OUT_DIR)/$(TARGET).$(MAP_SUFFIX)" \
                -o "$(OUT_DIR)/$(TARGET).$(BINARY_SUFFIX)" \
                --no_out_extension	\
                --no_library_search  \
                --entry Reset_Handler 	\
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
