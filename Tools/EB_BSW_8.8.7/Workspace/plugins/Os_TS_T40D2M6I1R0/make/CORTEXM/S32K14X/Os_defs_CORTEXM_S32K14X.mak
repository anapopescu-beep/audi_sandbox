#################################################################
#
# NAME:      Os_defs_CORTEXM_S32K14X.mak
#
# $Id: Os_defs_CORTEXM_S32K14X.mak 1.1 2023/04/18 07:06:17CEST Dan Dustinta (dan.dustinta) in_work  $
#
# (c) Elektrobit Automotive GmbH
#
#################################################################

OS_CORTEXM_HAS_MPU:=TRUE

OS_CORTEXM_MPU_TYPE:=OS_CORTEXM_NXP_MPU

OS_CORTEXM_HAS_FPU:=TRUE

OS_KLIB_OBJS_DERIVATE = \
	$(addprefix	$(AutosarOS_LIB_SRC_PATH)/CORTEXM/, \
		CORTEXM$(OS_HYPHEN)timer$(OS_HYPHEN)nxp$(OS_HYPHEN)ftm.c \
	)

Os_src_FILES += $(AutosarOS_CORE_PATH)/src/CORTEXM/CORTEXM$(OS_HYPHEN)timer$(OS_HYPHEN)nxp$(OS_HYPHEN)ftm$(OS_HYPHEN)config.c

#
# Editor settings: DO NOT DELETE
# vi:set ts=4:
#
