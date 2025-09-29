# don't generate code for Os_Test Os_SingleCore Os_MemoryProtection snippets
TRESOS2_NOGEN_PLUGINS += Os_Test Os_SingleCore Os_MultiCore

# Set available size for ACG tests
PREPROCESSOR_DEFINES += TS_PLATFORM_MEM_SIZE_KB
TS_PLATFORM_MEM_SIZE_KB_KEY = TS_PLATFORM_MEM_SIZE_KB
TS_PLATFORM_MEM_SIZE_KB_VALUE = 60

# Select single-core case.
PREPROCESSOR_DEFINES += TS_ATOMICS_USER_MULTICORE_CASE
TS_ATOMICS_USER_MULTICORE_CASE_KEY = ATOMICS_USER_MULTICORE_CASE
TS_ATOMICS_USER_MULTICORE_CASE_VALUE = 0

# Set ATOMICS_USE_GENERIC_IMPL_OVERRIDE to 1 to override.
ATOMICS_USE_GENERIC_IMPL_OVERRIDE = 1

# Select generic implementation provided by Atomics module.
ATOMICS_USE_GENERIC_IMPL = 1
### from ProjectMode_CommonSettings
# provide variant of Testing plugin for project mode tests
Testing_VARIANT := TS_TxDxM1I0R0
# from common\Include\Platforms_MemMap\util\Merged_Makefile.mak
#################################################################
# Add the toolchain specific MemMap configuration to the list of
# config files and make sure that tresos does not expect a
# module of that name.
#
TRESOS2_NOGEN_PLUGINS += MemMap_MCAL


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

