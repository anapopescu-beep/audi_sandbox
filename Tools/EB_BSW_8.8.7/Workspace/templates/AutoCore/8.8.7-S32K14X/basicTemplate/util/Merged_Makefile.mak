

# separate compiler options file for Ts5Atl files for removing optimization
TS5ATL_MAKE_INC := $(subst \,/,$(PROJECT_ROOT))/output/make/Ts5Atl_options.inc
Ts5Atl_src_OPTMAP := $(TS5ATL_MAKE_INC)
Ts5Atl_OPTMAP := $(TS5ATL_MAKE_INC)
# all target must be the first target
.PHONY: default
default: all
 
ifeq ($(TOOLCHAIN),multi)
# create compiler options file for Ts5Atl files and remove optimizations
$(TS5ATL_MAKE_INC):
        @echo Building $(notdir $@)
        @$(foreach i,$(CC_OPT) $(ALL_INC_DIR) $(cppGetPreProcessorDefines), $(file >>$@,$(subst \,/,$(subst -Ointerproc,,$(subst -OI,,$i))))))
        $(shell $(DOS2UNIX) $@)
 
$(subst \,/,$(PROJECT_ROOT))/output/make/compiler.inc: $(TS5ATL_MAKE_INC)
endif
ifeq ($(TOOLCHAIN),dcc)
# create compiler options file for Ts5Atl files and remove optimizations
$(TS5ATL_MAKE_INC):
        @echo Building $(notdir $@)
        @$(foreach i,$(CC_OPT) $(ALL_INC_DIR) $(cppGetPreProcessorDefines), $(file >>$@,$(subst \,/,$(subst -XO,,$i))))
        $(shell $(DOS2UNIX) $@)
 
$(subst \,/,$(PROJECT_ROOT))/output/make/compiler.inc: $(TS5ATL_MAKE_INC)       
endif
ifeq ($(TOOLCHAIN),tasking)
# create compiler options file for Ts5Atl files and remove optimizations
CC_OPT_TO_REMOVE := -O3
$(TS5ATL_MAKE_INC):
        @echo Building $(notdir $@)
        @$(foreach i,$(CC_OPT) $(ALL_INC_DIR) $(cppGetPreProcessorDefines), $(file >>$@,$(subst \,/,$(subst $(CC_OPT_TO_REMOVE),,$i))))
        $(shell $(DOS2UNIX) $@) 
$(subst \,/,$(PROJECT_ROOT))/output/make/compiler.inc: $(TS5ATL_MAKE_INC)       
endif
ifeq ($(TOOLCHAIN),iar)
# create compiler options file for Ts5Atl files and remove optimizations
CC_OPT_TO_REMOVE := -Ohz
$(TS5ATL_MAKE_INC):
	@echo Building $(notdir $@)
	@$(foreach i,$(CC_OPT) $(ALL_INC_DIR) $(cppGetPreProcessorDefines), $(file >>$@,$(subst \,/,$(subst $(CC_OPT_TO_REMOVE),,$i))))
	$(shell $(DOS2UNIX) $@) 
$(subst \,/,$(PROJECT_ROOT))/output/make/compiler.inc: $(TS5ATL_MAKE_INC)       
endif

#################################################################################################################

### merged from Platforms_MemMap
#include Merged_Makefile.mak from TARGET and TARGET/DERIVATE
-include $(PROJECT_ROOT)/util/$(TARGET)/Merged_Makefile.mak
-include $(PROJECT_ROOT)/util/$(TARGET)/$(DERIVATE)/Merged_Makefile.mak

#################################################################
# CC_INCLUDE_PATH, CPP_INCLUDE_PATH and ASM_INCLUDE_PATH:
# The paths to own user include files. The paths must be preceded
# by no option . If more than one path is used, you will have
# to separate them by spaces.
#
USER_INCLUDE_PATH  += $(PROJECT_ROOT)/source/config \
                      $(PROJECT_ROOT)/source/config/$(TARGET) \
                      $(PROJECT_ROOT)/source/config/$(TARGET)/$(DERIVATE)


# don't generate code for Os_Test Os_MemoryProtection snippets
TRESOS2_NOGEN_PLUGINS += Os_Test Os_MemoryProtection

### merged from Platforms_Os/SinglecoreOs
# Singlecore OS has the suffix _SCOS for board files
BOARD_SUFFIX := _SCOS


#################################################################
# For GNU Make we must explicitly set SHELL to cmd.exe,
# since otherwise it would try to use sh.exe.
SHELL := cmd.exe

####################################################################
# On WinCore, we copy all relevant dlls to the folder containing the
# executable. This way, the dlls are always found automatically and
# the user does not have to adjust the system's %PATH% variable.

# Only on WinCore...
ifeq ($(DERIVATE), WIN32X86)

# We need the Platforms_VARIANT variable, is included from generated
# make file, but may also be overwritte by the project specific
# settings
-include $(PROJECT_ROOT)/output/generated/make/Make_cfg.mak
-include project_settings.mak

# The Platforms plugin
PLATFORMS_DIR := $(TRESOS_BASE)/plugins/Platforms_$(Platforms_VARIANT)
# The compiler binaries and dlls
COMPILER_DIR := $(PLATFORMS_DIR)/tools/mingw-gcc-6.2.0/bin
# The self-extracting compiler archive
COMPILER_ARCH := $(abspath $(COMPILER_DIR)/../MinGW.exe)

# Add the copy rule to the "all" target, so that it is executed during
# compilation (it does not matter when exactly). Specifying this as the
# first rule here also keeps the "all" target the default target.
all: copy_wincore_dlls

# Copy all dlls from the compiler and the platforms plugin to the output/bin folder;
# COMPILER_DIR is definded by makefiles of Compiler plugin
.PHONY: copy_wincore_dlls
copy_wincore_dlls: $(COMPILER_DIR)/gcc.exe
	$(MKDIR) $(BIN_OUTPUT_PATH) && $(CP) -u -t $(BIN_OUTPUT_PATH) $(COMPILER_DIR)/*.dll $(COMPILER_DIR)/../lib/*.dll

# Extract the compiler if it does not yet exist
$(COMPILER_DIR)/gcc.exe:
	$(COMPILER_ARCH)

endif

PROJECT_NAME := basicTemplate
TRESOS2_PROJECT_NAME := basicTemplate

# Use generic implementation of Atomics
# Please set this to 0 if the generic implementation conflicts with
# the settings of your Os (e.g. memory protection)
ATOMICS_USE_GENERIC_IMPL ?= 1

# If ATOMICS_USER_MULTICORE_CASE not found in PREPROCESSOR_DEFINES
# add the default value for generic atomics implementation
ifeq (,$(findstring ATOMICS_USER_MULTICORE_CASE,$(PREPROCESSOR_DEFINES)))
# Assume single core case for complatibility to all targets
PREPROCESSOR_DEFINES += TS_ATOMICS_USER_MULTICORE_CASE
TS_ATOMICS_USER_MULTICORE_CASE_KEY = ATOMICS_USER_MULTICORE_CASE
TS_ATOMICS_USER_MULTICORE_CASE_VALUE ?= 0
endif

