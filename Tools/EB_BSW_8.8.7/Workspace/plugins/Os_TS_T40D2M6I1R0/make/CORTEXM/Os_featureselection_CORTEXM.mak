#
# \file
#
# \brief AUTOSAR Os
#
# This file contains the implementation of the AUTOSAR
# module Os.
#
# \version 6.1.144
#
# \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
#
# Copyright 1998 - 2023 Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.

#
# This makefile is used from both the plugin build and the user build environment
# It must only include the feature set definitions

DIRMERGE_SETTINGS_TAG_OsFeature_GenericReturnFromCall ?= enabled

# Most Cortex-M are single core so far - for multicore Cortex-M derivatives enable the feature in Os_featureselection_CORTEXM_DERIVATE.mak
DIRMERGE_SETTINGS_TAG_OsFeature_Multicore ?= disabled

