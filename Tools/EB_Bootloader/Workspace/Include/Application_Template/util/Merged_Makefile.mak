

#################################################################
# CC_INCLUDE_PATH, CPP_INCLUDE_PATH and ASM_INCLUDE_PATH:
# The paths to own user include files. The paths must be preceded
# by no option . If more than one path is used, you will have
# to separate them by spaces.
#
USER_INCLUDE_PATH  += $(PROJECT_ROOT)\source\config \
                      $(PROJECT_ROOT)\source\config\$(TARGET) \
                      $(PROJECT_ROOT)\source\config\$(TARGET)\$(DERIVATE)
#################################################################
# include merged makefile if they exist
-include $(PROJECT_ROOT)\util\$(TARGET)\Merged_Makefile.mak
-include $(PROJECT_ROOT)\util\$(DERIVATE)\Merged_Makefile.mak

# don't generate code for Compiler plugin
TRESOS2_NOGEN_PLUGINS += Compiler

# enable Compiler plugin
ENABLED_PLUGINS += Compiler

# from common\Include\Platforms_MemMap\util\Merged_Makefile.mak
#################################################################
# Add the toolchain specific MemMap configuration to the list of
# config files and make sure that tresos does not expect a
# module of that name.
#
TRESOS2_NOGEN_PLUGINS += MemMap_MCAL


# Select single-core case.
PREPROCESSOR_DEFINES += TS_ATOMICS_USER_MULTICORE_CASE
TS_ATOMICS_USER_MULTICORE_CASE_KEY = ATOMICS_USER_MULTICORE_CASE
TS_ATOMICS_USER_MULTICORE_CASE_VALUE = 0

# Select generic implementation provided by Atomics module.
ATOMICS_USE_GENERIC_IMPL = 1

# define ECUM_PROVIDE_LEGACY_SYMBOLIC_NAMES
CC_OPT += -DECUM_PROVIDE_LEGACY_SYMBOLIC_NAMES 
####################################################################
# On WinCore, we copy all relevant dlls to the folder containing the
# executable. This way, the dlls are always found automatically and
# the user does not have to adjust the system's %PATH% variable.

# Only on WinCore...
ifeq ($(DERIVATE), WIN32X86)

# We need the Platforms_VARIANT variable, is included from generated
# make file, but may also be overwritte by the project specific
# settings
-include $(PROJECT_ROOT)\output\generated\make\Make_cfg.mak
-include project_settings.mak

# The destination folder containing the executable
OUTPUT_BIN := $(PROJECT_ROOT)\output\bin
# The Platforms plugin
PLATFORMS_DIR := $(TRESOS_BASE)\plugins\Platforms_$(Platforms_VARIANT)
# The compiler binaries and dlls
COMPILER_BIN := $(PLATFORMS_DIR)\tools\mingw-gcc-6.2.0\bin
# The self-extracting compiler archive
COMPILER_ARCH := $(COMPILER_BIN)\..\MinGW.exe

# Add the copy rule to the "all" target, so that it is executed during
# compilation (it does not matter when exactly). Specifying this as the
# first rule here also keeps the "all" target the default target.
all: copy_wincore_dlls

# Copy all dlls from the compiler and the platforms plugin to the
# output/bin folder
.PHONY: copy_wincore_dlls

# Use source and destination folders as prerequisites and create them
# if not existing. This way, we are independent from the execution order
# imposed by the build environment.
copy_wincore_dlls: $(OUTPUT_BIN) $(COMPILER_BIN)
	$(CP) $(COMPILER_BIN)\*.dll $(OUTPUT_BIN)

# Create the output/bin folder if it does not yet exist
$(OUTPUT_BIN):
	mkdir $(OUTPUT_BIN)

# Extract the compiler if it does not yet exist
$(COMPILER_BIN):
	$(COMPILER_ARCH)

endif
