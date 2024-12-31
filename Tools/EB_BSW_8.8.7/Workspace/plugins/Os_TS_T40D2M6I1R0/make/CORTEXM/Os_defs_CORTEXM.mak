#################################################################
#
# $Id: Os_defs_CORTEXM.mak 1.1 2023/04/18 07:06:17CEST Dan Dustinta (dan.dustinta) in_work  $
#
# This makefile contains derivative-specific definitions for building the OS.
#
# Copyright Elektrobit Automotive GmbH
# All rights exclusively reserved for Elektrobit Automotive GmbH,
# unless expressly agreed to otherwise.
#
#################################################################

ifneq ($(ASM_FILE_SUFFIX),s)
$(error ASM_FILE_SUFFIX does not match file names - expected 's', got $(ASM_FILE_SUFFIX))
endif

ifeq ($(OS_KERNEL_TYPE),FUNCTION_CALL)
$(error "Kernel type FUNCTION_CALL unsupported.")
endif

OS_CORTEXM_PREFIX=$(OS_ARCH_PREFIX)

include $(OS_SSC_ROOT)/make/$(OS_ARCH)/$(OS_CPU)/Os_defs_$(OS_ARCH)_$(OS_CPU).mak

Os_src_FILES += $(addprefix $(AutosarOS_SRC_PATH)/CORTEXM/,						\
		Os_timers_configuration_CORTEXM.c)

ifneq ($(OS_KERNEL_TYPE),MICROKERNEL)
Os_src_FILES +=																	\
	$(addprefix $(AutosarOS_SRC_PATH)/CORTEXM/,									\
		Os_configuration_CORTEXM.c												\
		CORTEXM$(OS_HYPHEN)call.s												\
		CORTEXM$(OS_HYPHEN)contextload.s										\
		CORTEXM$(OS_HYPHEN)exceptiontable_C0.s									\
		CORTEXM$(OS_HYPHEN)exceptionhandler.s									\
		CORTEXM$(OS_HYPHEN)interruptvectors_C0.s								\
		CORTEXM$(OS_HYPHEN)returnfrominterrupt.s								\
		CORTEXM$(OS_HYPHEN)starttask.s											\
		CORTEXM$(OS_HYPHEN)syscall.s											\
		CORTEXM$(OS_HYPHEN)dispatchunknowninterrupt.s							\
	)

OS_KLIB_OBJS_ARCH =																\
	$(addprefix $(AutosarOS_LIB_SRC_PATH)/CORTEXM/,								\
		CORTEXM$(OS_HYPHEN)cat1exit.s											\
		CORTEXM$(OS_HYPHEN)cat2exit.s											\
		CORTEXM$(OS_HYPHEN)getcurirqsource.s									\
		CORTEXM$(OS_HYPHEN)getirqprio.s											\
		CORTEXM$(OS_HYPHEN)idle.s												\
		CORTEXM$(OS_HYPHEN)killcalledcontext.s									\
		CORTEXM$(OS_HYPHEN)savecontextanddispatch.s								\
		CORTEXM$(OS_HYPHEN)setirqprio.s											\
		CORTEXM$(OS_HYPHEN)disableirq.s											\
		CORTEXM$(OS_HYPHEN)disableirqgetstate.s									\
		CORTEXM$(OS_HYPHEN)dispatch.c											\
		CORTEXM$(OS_HYPHEN)exceptions.c											\
		CORTEXM$(OS_HYPHEN)helpers.s											\
		CORTEXM$(OS_HYPHEN)initarch.c											\
		CORTEXM$(OS_HYPHEN)setstate.s											\
	)

OS_ULIB_OBJS_ARCH = \
	$(OS_ULIB_OBJS_ARCH_COMMON)													\
	$(addprefix $(AutosarOS_LIB_SRC_PATH)/CORTEXM/,								\
		CORTEXM$(OS_HYPHEN)$(OS_USER_PREFIX)taskreturn.s						\
		CORTEXM$(OS_HYPHEN)$(OS_USER_PREFIX)returnfromcall.s					\
	)

ifneq ($(OS_N_CORES),1)

OS_ULIB_OBJS_ARCH += \
	$(addprefix $(AutosarOS_LIB_SRC_PATH)/CORTEXM/,								\
		CORTEXM$(OS_HYPHEN)$(OS_USER_PREFIX)shutdownallcores.$(ASM_FILE_SUFFIX)	\
	)

ifeq ($(OS_AUTOSAR_SPINLOCKS),TRUE)
OS_ULIB_OBJS_ARCH += \
	$(addprefix $(AutosarOS_LIB_SRC_PATH)/CORTEXM/,								\
		CORTEXM$(OS_HYPHEN)$(OS_USER_PREFIX)releasespinlock.$(ASM_FILE_SUFFIX)	\
		CORTEXM$(OS_HYPHEN)$(OS_USER_PREFIX)trytogetspinlock.$(ASM_FILE_SUFFIX)	\
	)
endif
endif # OS_N_CORES > 1

OS_ELIB_OBJS_ARCH = \
	$(addprefix $(AutosarOS_LIB_SRC_PATH)/CORTEXM/,								\
		CORTEXM$(OS_HYPHEN)$(OS_ERROR_INFIX)$(OS_HYPHEN)ArchTrapHandler.c		\
	)

ifneq ($(OBJ_OUTPUT_PATH),)
OS_OBJ_DIR = $(OBJ_OUTPUT_PATH)
else
OS_OBJ_DIR = $(OBJ_DIR)
endif

ifeq ($(OS_CORTEXM_HAS_MPU),TRUE)
ifeq ($(OS_CORTEXM_MPU_TYPE),OS_CORTEXM_ARM_CORE_MPU)
OS_KLIB_OBJS_ARCH +=															\
	$(addprefix $(AutosarOS_LIB_SRC_PATH)/CORTEXM/,								\
		CORTEXM$(OS_HYPHEN)mpu.c												\
	)
else ifeq ($(OS_CORTEXM_MPU_TYPE),OS_CORTEXM_NXP_MPU)
OS_KLIB_OBJS_ARCH +=															\
	$(addprefix $(AutosarOS_LIB_SRC_PATH)/CORTEXM/,								\
		CORTEXM$(OS_HYPHEN)NXP$(OS_HYPHEN)mpu.c									\
	)
else ifeq ($(OS_CORTEXM_MPU_TYPE),OS_CORTEXM_ARMV8_MPU)
OS_KLIB_OBJS_ARCH +=															\
	$(addprefix $(AutosarOS_LIB_SRC_PATH)/CORTEXM/,								\
		CORTEXM$(OS_HYPHEN)mpu$(OS_HYPHEN)armv8.c								\
	)
else
	$(error "MPU not supported, check OS_CORTEXM_MPU_TYPE")
endif
endif

ifeq ($(OS_CORTEXM_HAS_FPU),TRUE)
OS_KLIB_OBJS_ARCH +=															\
	$(addprefix $(AutosarOS_LIB_SRC_PATH)/CORTEXM/,								\
		CORTEXM$(OS_HYPHEN)savefpcontextanddispatch.s							\
		CORTEXM$(OS_HYPHEN)FPU_ARMV7.s											\
	)

Os_src_FILES +=																	\
	$(addprefix $(AutosarOS_SRC_PATH)/CORTEXM/,									\
		CORTEXM$(OS_HYPHEN)fpcontextload.s										\
	)
endif

# Cypress derivatives with a CPUSS-based interrupt multiplexer require a customized NVIC driver
ifeq ($(DIRMERGE_SETTINGS_TAG_OsFeature_CM_CPUSS),enabled)
OS_KLIB_OBJS_ARCH +=															\
	$(addprefix $(AutosarOS_LIB_SRC_PATH)/CORTEXM/,								\
		CORTEXM$(OS_HYPHEN)int$(OS_HYPHEN)nvic$(OS_HYPHEN)cy$(OS_HYPHEN)mux.c	\
	)
else
OS_KLIB_OBJS_ARCH +=															\
	$(addprefix $(AutosarOS_LIB_SRC_PATH)/CORTEXM/,								\
		CORTEXM$(OS_HYPHEN)int$(OS_HYPHEN)nvic.c								\
	)
endif

endif # !MICROKERNEL

ifeq ($(DIRMERGE_SETTINGS_TAG_OsFeature_CM_EXACCESS_MONITOR),enabled)
# OS_Atomic*() functions work with the EB tresos Safety OS, because the provided hardware features
# enable these operations even in environments with restricted access (e.g., user mode threads
# with memory protection enabled). They do not pose additional safety risks, because they are
# subject to memory protection like non-atomic (or ordinary) memory accesses.
# The same argument applies to EB tresos AutoCore OS as well.
OS_KLIB_OBJS_ARCH +=															\
	$(addprefix $(AutosarOS_LIB_SRC_PATH)/CORTEXM/,								\
		CORTEXM$(OS_HYPHEN)atomicadd.s											\
		CORTEXM$(OS_HYPHEN)atomicand.s											\
		CORTEXM$(OS_HYPHEN)atomicclearflag.s									\
		CORTEXM$(OS_HYPHEN)atomiccompareexchange.s								\
		CORTEXM$(OS_HYPHEN)atomicexchange.s										\
		CORTEXM$(OS_HYPHEN)atomicor.s											\
		CORTEXM$(OS_HYPHEN)atomicsub.s											\
		CORTEXM$(OS_HYPHEN)atomictestandsetflag.s								\
		CORTEXM$(OS_HYPHEN)atomicxor.s											\
	)

endif # OsFeature_CM_EXACCESS_MONITOR enabled

# The fence operation is always required: by those derivates with proper hardware
# support (DIRMERGE_SETTINGS_TAG_OsFeature_CM_EXACCESS_MONITOR == enabled), and by those,
# which contain a SEMA4 module.
OS_KLIB_OBJS_ARCH +=															\
	$(addprefix $(AutosarOS_LIB_SRC_PATH)/CORTEXM/,								\
		CORTEXM$(OS_HYPHEN)atomicthreadfence.s									\
	)

OS_KLIB_OBJS_ARCH += $(OS_KLIB_OBJS_DERIVATE)

# Editor settings: DO NOT DELETE
# vi:set ts=4:
