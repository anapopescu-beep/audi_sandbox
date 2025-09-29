# \file
#
# \brief AUTOSAR Fee
#
# This file contains the implementation of the AUTOSAR
# module Fee.
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 2005 - 2019 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.

#################################################################
# REGISTRY

LIBRARIES_TO_BUILD     += Fee_src

Fee_src_FILES += $(Fee_CORE_PATH)/src/Fee.c
Fee_src_FILES += $(wildcard $(Fee_OUTPUT_PATH)/src/Fee_*.c)

ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built 
# do not compile any files other then the postbuild files.
Fee_src_FILES :=
Fee_src_FILES += $(wildcard $(Fee_OUTPUT_PATH)/src/Fee_*PB*.c)
endif

.PHONY : complete_MCAL_origin Fee_MCAL_origin 

complete_MCAL_origin: Fee_MCAL_origin

Fee_MCAL_origin: remove_Eclipse_cache
	@${ECHO} * Preparing MCAL module Fee into vendor origin version
	@$(Fee_CORE_PATH)\perform_MCAL_change.bat origin

.PHONY : complete_MCAL_EB_update Fee_MCAL_EB_update

complete_MCAL_EB_update: Fee_MCAL_EB_update

Fee_MCAL_EB_update: remove_Eclipse_cache
	@${ECHO} * Preparing MCAL module Fee into EB updated version
	@$(Fee_CORE_PATH)\perform_MCAL_change.bat EB_update

