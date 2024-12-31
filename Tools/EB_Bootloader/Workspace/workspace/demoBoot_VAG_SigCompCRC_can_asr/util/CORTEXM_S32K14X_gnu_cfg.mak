# \file
#
# \brief AUTOSAR Os
#
# This file contains the implementation of the AUTOSAR
# module Os.
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 1998 - 2016 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.


#################################################################
# TOOLPATH_COMPILER:
# The root directory (prefix) of the GNU C Compiler for ARM chain must
# be set by the help of the variable TOOLPATH_COMPILER.
# If an environment is defined, the value of this variable will be
# used.
#
TOOLPATH_COMPILER ?= C:\tools\gcc\gcc-arm-none-eabi-6-2017-q2-update-win32

#################################################################
# CC_OPT:
# The variable CC_OPT contains all default compiler switches.

# optimisation (O2=speed, Os=size)
CC_OPT += -o2

# select target cpu
CC_OPT += -mcpu=cortex-m4

# generate 16-bit code (aka thumb)
CC_OPT += -mthumb

# select endianess
CC_OPT += -mlittle-endian

# select target fpu
CC_OPT += -mfpu=fpv4-sp-d16
CC_OPT += -mfloat-abi=hard

# enable all warnings
CC_OPT += -Wall


CC_OPT += -c
CC_OPT += -ggdb3
CC_OPT += -fomit-frame-pointer
CC_OPT += -fno-common
CC_OPT += -Wextra
CC_OPT += -Wstrict-prototypes
CC_OPT += -Wno-sign-compare
CC_OPT += -fstack-usage
CC_OPT += -fdump-ipa-all
CC_OPT += -Wimplicit-function-declaration 


#################################################################
# ASM_OPT:
# The variable ASM_OPT contains the switches for the assembler call.

# select target cpu
ASM_OPT += -mcpu=cortex-m4

# generate 16-bit code (aka thumb)
ASM_OPT += -mthumb

ASM_OPT += -x assembler-with-cpp
ASM_OPT += -c
ASM_OPT += -mfpu=fpv4-sp-d16

#################################################################
# CPP_OPT:
# The variable CPP_OPT contains the switches for the cpp compiler call.
#

#################################################################
# LINK_OPT:
# The variable LINK_OPT contains the switches for the linker call.
#

# generate a map file
LINK_OPT += -Wl,-Map=$(BIN_OUTPUT_PATH)\$(PROJECT).$(MAP_FILE_SUFFIX)

# search link libraries and linker script include files here
LINK_OPT += -L $(BOARD_PROJECT_PATH)


LINK_OPT += -nostdlib


#################################################################
# LINK_LIBS:
# The variable LINK_LIBS tells the linker which libraries it
# should link against. The order is significant. Providers must
# be specified after the consumer(s).
#

# link against libgcc, which contains builtins like __udiv.
LIBRARIES_LINK_ONLY += -lgcc

#################################################################
# The Application Makefile (Makefile.mak) contains the variable
# COMPILER_MODE. This variable defines, how the include paths and
# the flags (parameters) will be passed to the compiler. Normally,
# all parameters are passed by the windows command line but
# Windows 2000 has a restriction of 2048 characters
# (Windows XP - 8192). Therefore the Customer Build Environment
# supports up to three different compiler parameter modes.
#
# GLOBAL_OPTION_FILE:
# Before calling the compiler, a global parameter file is
# created by the Compiler Makefile Plugin. This file contains
# all include paths and the compiler flags. It is used
# for all source files. This means that the options
# <source_file>_CC_OPT and <source_file>_INCLUDE have no effect.
# This is the default compiler mode.
#
# NO_OPTION_FILE mode:
# All parameters are passed using the command line. If the include
# paths are longer than the limitations of the command line,
# the make run will abort with an error message.
#
# LOCAL_OPTION_FILE:
# If the value LOCAL_OPTION_FILE is set, a parameter file with
# the include paths and compiler flags will be created for each
# source file. The make process will be VERY slow when this option
# is used. The advantage is, that different include path and
# parameters can be defined for every source file. If you do not
# need this feature, you should not use this option.

COMPILER_MODE := GLOBAL_OPTION_FILE

################################################################
# AR_OPT:
# The variable AR_OPT contains the options for the library call.
#
# Default: -r (added elsewhere).

# create archive if it doesn't exist
AR_OPT += -c

# replace only newer files
AR_OPT += -u

# write an object file index
AR_OPT += -s

#################################################################
# EXT_LOCATOR_FILE:
# This variable specifies the name for an external locator/linker file.
# If the variable is empty, the board makefile will generate a default
# locator/linker file.
#
EXT_LOCATOR_FILE +=

#################################################################
# CREATE_PREPROCESSOR_FILE:
# This variable allows to define if a secial preprocessor file
# (output/obj/*.pre) shall be created or not.
CREATE_PREPROCESSOR_FILE = NO
