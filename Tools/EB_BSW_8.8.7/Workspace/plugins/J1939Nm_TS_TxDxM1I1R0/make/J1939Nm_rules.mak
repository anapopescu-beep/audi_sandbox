#
# \file
#
# \brief AUTOSAR J1939Nm
#
# This file contains the implementation of the AUTOSAR
# module J1939Nm.
#
# \version 1.1.7
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

J1939Nm_src_FILES      := $(J1939Nm_CORE_PATH)/src/J1939Nm.c \
                      $(J1939Nm_OUTPUT_PATH)/src/J1939Nm_Cfg.c \

LIBRARIES_TO_BUILD += J1939Nm_src

# J1939Nm_Wrapper_src_FILES      := $(J1939Nm_Wrapper_OUTPUT_PATH)/src/J1939Nm_Wrapper.c

# LIBRARIES_TO_BUILD += J1939Nm_Wrapper_src
#################################################################
# DEPENDENCIES (only for assembler files)
#

#################################################################
# RULES




