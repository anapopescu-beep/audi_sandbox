###########################################################################
## Makefile generated for Simulink model 'eCS_Algo_Simulation_2015b_opti'. 
## 
## Makefile     : eCS_Algo_Simulation_2015b_opti.mk
## Generated on : Wed Sep 21 15:30:06 2022
##  version:  
## 
## Build Info:
## 
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/eCS_Algo_Simulation_2015b_opti_acc.mexw64
## Product type : MEX function
## Build type   : Accelerator
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPUTER                Computer type. See the MATLAB "computer" command.
# MODELREF_LINK_RSPFILE   Include paths for the model reference build
# MEX_SRC                 MEX source file
# PERL                    PERL Tool
# GEN_LNK_SCRIPT          Perl script to generate the command file
# CMD_FILE                Command file
# MEX_OPTS_FLAG           MEX options

PRODUCT_NAME              = eCS_Algo_Simulation_2015b_opti
MAKEFILE                  = eCS_Algo_Simulation_2015b_opti.mk
COMPUTER                  = PCWIN64
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2015b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2015b/bin
MATLAB_ARCH_BIN           = C:/PROGRA~1/MATLAB/R2015b/bin/win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = C:/Git/eCS_Platform_Git/Components/Application/Autoliv/eCS/Design/MBD
ARCH                      = win64
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 1
TGT_FCN_LIB               = None
MODELREF_LINK_RSPFILE_NAME = eCS_Algo_Simulation_2015b_opti_ref.rsp
RELATIVE_PATH_TO_ANCHOR   = ../../..
MODELREF_LINK_RSPFILE     = eCS_Algo_Simulation_2015b_opti_ref.rsp
MEX_SRC                   = eCS_Algo_Simulation_2015b_opti_acc.c
PERL                      = $(MATLAB_ROOT)/sys/perl/win32/bin/perl.exe
GEN_LNK_SCRIPT            = $(MATLAB_ROOT)/rtw/c/tools/mkvc_lnk.pl
CMD_FILE                  = $(PRODUCT_NAME).lnk
ANSI_OPTS                 = -ansi -pedantic -Wno-long-long -fwrapv
CPP_ANSI_OPTS             = -std=c++98 -pedantic -Wno-long-long -fwrapv
MEX_OPTS_FLAG             = -f "$(MATLAB_ROOT)/bin/win64/mexopts/mingw64.xml"

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 v4.x | gmake (64-bit Windows)
# Supported Version(s):    4.x
# ToolchainInfo Version:   R2015b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# ANSI_OPTS
# CPP_ANSI_OPTS
# MINGW_ROOT

#-----------
# MACROS
#-----------

WARN_FLAGS         = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX     = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS     = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MEX_OPTS_FILE      = $(MATLAB_ROOT)/bin/win64/mexopts/mingw64.xml
MW_EXTERNLIB_DIR   = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL              = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = $(CC_PATH)/gcc

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = $(LD_PATH)/gcc

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = $(CPP_PATH)/g++

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = $(CPP_LD_PATH)/g++

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = $(AR_PATH)/ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_BIN)
MEX = $(MEX_PATH)/mex

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/win64
MAKE = $(MAKE_PATH)/gmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(ANSI_OPTS) \
                       -O0
CPPFLAGS             = -c $(CPP_ANSI_OPTS) \
                       -O0
CPP_LDFLAGS          = -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)"
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -Wl,--no-undefined \
                         -Wl,--out-implib,$(basename $(PRODUCT))$(STATICLIB_EXT)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)"
MEX_CFLAGS           = -MATLAB_ARCH=$(ARCH) $(INCLUDES) \
                         \
                       COPTIMFLAGS="$(ANSI_OPTS)  \
                       -O0 \
                        $(DEFINES)" \
                         \
                       -silent
MEX_LDFLAGS          = LDFLAGS=='$$LDFLAGS'
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -Wl,--no-undefined \
                       -Wl,--out-implib,$(basename $(PRODUCT))$(STATICLIB_EXT)

#--------------------
# File extensions
#--------------------

H_EXT               = .h
OBJ_EXT             = .obj
C_EXT               = .c
EXE_EXT             = .exe
SHAREDLIB_EXT       = .dll
HPP_EXT             = .hpp
OBJ_EXT             = .obj
CPP_EXT             = .cpp
EXE_EXT             = .exe
SHAREDLIB_EXT       = .dll
STATICLIB_EXT       = .lib
MEX_EXT             = .mexw64
MAKE_EXT            = .mk


###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/eCS_Algo_Simulation_2015b_opti_acc.mexw64
PRODUCT_TYPE = "MEX function"
BUILD_TYPE = "Accelerator"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/slprj/accel/eCS_Algo_Simulation_2015b_opti -I$(START_DIR) -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DINTEGER_CODE=0 -DCLASSIC_INTERFACE=1 -DALLOCATIONFCN=0 -DONESTEPFCN=0 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=0
DEFINES_IMPLIED = -DTID01EQ=1
DEFINES_STANDARD = -DNDEBUG -DMODEL=eCS_Algo_Simulation_2015b_opti -DNUMST=8 -DNCSTATES=6 -DHAVESTDIO

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_IMPLIED) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/slprj/accel/eCS_Algo_Simulation_2015b_opti/eCS_Algo_Simulation_2015b_opti_acc_data.c $(START_DIR)/slprj/accel/eCS_Algo_Simulation_2015b_opti/rtGetInf.c $(START_DIR)/slprj/accel/eCS_Algo_Simulation_2015b_opti/rtGetNaN.c $(START_DIR)/slprj/accel/eCS_Algo_Simulation_2015b_opti/rt_nonfinite.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = eCS_Algo_Simulation_2015b_opti_acc_data.obj rtGetInf.obj rtGetNaN.obj rt_nonfinite.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =  -L$(MATLAB_ROOT)/bin/win64 -L$(MATLAB_ROOT)/extern/lib/win64/mingw64 -llibmwipp -llibut -llibmwmathutil -llibmwsl_fileio -llibmwsigstream -llibmwsl_AsyncioQueue -llibmwsimulink

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : build


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a MEX function                     
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(MEX_SRC)
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	@echo "### Creating MEX function "$(PRODUCT)" ..."
	$(MEX) $(MEX_OPTS_FLAG) $(MEX_CFLAGS) -outdir $(RELATIVE_PATH_TO_ANCHOR) $(MEX_SRC) @$(CMD_FILE) $(SYSTEM_LIBS)
	$(RM) $(CMD_FILE)


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(MEX) $(MEX_OPTS_FLAG) -c $(MEX_CFLAGS) -outdir "$(dir $@)" "$<"


%.obj : %.cpp
	$(MEX) $(MEX_OPTS_FLAG) -c $(MEX_CFLAGS) -outdir "$(dir $@)" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(MEX) $(MEX_OPTS_FLAG) -c $(MEX_CFLAGS) -outdir "$(dir $@)" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(MEX) $(MEX_OPTS_FLAG) -c $(MEX_CFLAGS) -outdir "$(dir $@)" "$<"


%.obj : $(START_DIR)/slprj/accel/eCS_Algo_Simulation_2015b_opti/%.c
	$(MEX) $(MEX_OPTS_FLAG) -c $(MEX_CFLAGS) -outdir "$(dir $@)" "$<"


%.obj : $(START_DIR)/slprj/accel/eCS_Algo_Simulation_2015b_opti/%.cpp
	$(MEX) $(MEX_OPTS_FLAG) -c $(MEX_CFLAGS) -outdir "$(dir $@)" "$<"


%.obj : $(START_DIR)/%.c
	$(MEX) $(MEX_OPTS_FLAG) -c $(MEX_CFLAGS) -outdir "$(dir $@)" "$<"


%.obj : $(START_DIR)/%.cpp
	$(MEX) $(MEX_OPTS_FLAG) -c $(MEX_CFLAGS) -outdir "$(dir $@)" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(MEX) $(MEX_OPTS_FLAG) -c $(MEX_CFLAGS) -outdir "$(dir $@)" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(MEX) $(MEX_OPTS_FLAG) -c $(MEX_CFLAGS) -outdir "$(dir $@)" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.c
	$(MEX) $(MEX_OPTS_FLAG) -c $(MEX_CFLAGS) -outdir "$(dir $@)" "$<"


%.obj : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(MEX) $(MEX_OPTS_FLAG) -c $(MEX_CFLAGS) -outdir "$(dir $@)" "$<"


%.obj : C:/PROGRA~1/DSPACE~1.2/Matlab/Tl/TLSAMP~1/%.c
	$(MEX) $(MEX_OPTS_FLAG) -c $(MEX_CFLAGS) -outdir "$(dir $@)" "$<"


%.obj : C:/PROGRA~1/DSPACE~1.2/Matlab/Tl/TLSAMP~1/%.cpp
	$(MEX) $(MEX_OPTS_FLAG) -c $(MEX_CFLAGS) -outdir "$(dir $@)" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : $(MAKEFILE) rtw_proj.tmw


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


