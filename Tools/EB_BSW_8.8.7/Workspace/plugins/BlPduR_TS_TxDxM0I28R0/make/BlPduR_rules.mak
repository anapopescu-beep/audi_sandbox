# --------{ EB Automotive Makefile }--------

#################################################################
# DEFINITIONS

#################################################################
# REGISTRY

BlPduR_src_FILES      := \
     $(BlPduR_OUTPUT_PATH)\src\BlPduR_Cfg.c \
     $(BlPduR_CORE_PATH)\src\BlPduR_Prg.c \
     $(BlPduR_CORE_PATH)\src\BlPduR_Lin.c

LIBRARIES_TO_BUILD += BlPduR_src

#################################################################
# DEPENDENCIES (only for assembler files)
#

#################################################################
# RULES




