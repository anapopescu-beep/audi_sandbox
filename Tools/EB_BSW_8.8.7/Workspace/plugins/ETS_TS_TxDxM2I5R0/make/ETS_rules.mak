#
# \file
#
# \brief AUTOSAR ETS
#
# This file contains the implementation of the AUTOSAR
# module ETS.
#
# \version 2.5.0
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

ETS_lib_FILES                 :=

ETS_src_FILES                 +=                           \
  $(ETS_CORE_PATH)/src/ETS_Services.c                      \
  $(ETS_CORE_PATH)/src/ETS_TriggerAndEvents.c              \
  $(ETS_CORE_PATH)/src/ETS_EchoActions.c                   \
  $(ETS_CORE_PATH)/src/ETS_EventsHandler.c                 \
  $(ETS_CORE_PATH)/src/ETS_FieldsHandler.c                 \
  $(ETS_OUTPUT_PATH)/src/ETS_Cfg.c

LIBRARIES_TO_BUILD            += ETS_src

DIRECTORIES_TO_CREATE         += $(ETS_lib_LIB_OUTPUT_PATH)

CC_FILES_TO_BUILD             +=
CPP_FILES_TO_BUILD            +=
ASM_FILES_TO_BUILD            +=

MAKE_CLEAN_RULES              +=
MAKE_GENERATE_RULES           +=
MAKE_COMPILE_RULES            +=
MAKE_CONFIG_RULES             +=

define defineETSLibOutputPATH
$(1)_OBJ_OUTPUT_PATH          := $(ETS_lib_LIB_OUTPUT_PATH)
endef
$(foreach SRC,$(basename $(notdir $(subst \,/,$(ETS_lib_FILES)))),\
$(eval $(call defineETSLibOutputPATH,$(SRC))))

#################################################################
# DEPENDENCIES (only for assembler files)
#

#################################################################
# RULES

