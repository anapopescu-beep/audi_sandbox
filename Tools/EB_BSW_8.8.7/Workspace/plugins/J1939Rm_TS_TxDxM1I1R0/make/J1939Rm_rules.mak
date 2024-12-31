#
# \file
#
# \brief AUTOSAR J1939Rm
#
# This file contains the implementation of the AUTOSAR
# module J1939Rm.
#
# \version 1.1.9
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2022 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.


#################################################################
# DEFINITIONS

#################################################################
# REGISTRY

J1939Rm_src_FILES      := $(J1939Rm_CORE_PATH)/src/J1939Rm.c \
                      $(J1939Rm_OUTPUT_PATH)/src/J1939Rm_Cfg.c \
					  

LIBRARIES_TO_BUILD += J1939Rm_src

# J1939Rm_Wrapper_src_FILES      := $(J1939Rm_Wrapper_OUTPUT_PATH)/src/J1939Rm_Wrapper.c

# LIBRARIES_TO_BUILD += J1939Rm_Wrapper_src
#################################################################
# DEPENDENCIES (only for assembler files)
#

#################################################################
# RULES




