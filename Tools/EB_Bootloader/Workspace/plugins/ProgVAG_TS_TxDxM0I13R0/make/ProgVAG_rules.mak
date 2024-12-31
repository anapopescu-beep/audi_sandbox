# --------{ EB Automotive Makefile }--------

#################################################################
# DEFINITIONS

#################################################################
# REGISTRY

ProgVAG_src_FILES      := \
    $(ProgVAG_CORE_PATH)\src\PROG_Hsm.c \
    $(ProgVAG_CORE_PATH)\src\PROG_HsmPROGData.c \
    $(ProgVAG_CORE_PATH)\src\PROG_HsmPROGFnct.c \
    $(ProgVAG_CORE_PATH)\src\PROG_DowngradeProtection.c

LIBRARIES_TO_BUILD += ProgVAG_src

#################################################################
# DEPENDENCIES (only for assembler files)
#

#################################################################
# RULES
