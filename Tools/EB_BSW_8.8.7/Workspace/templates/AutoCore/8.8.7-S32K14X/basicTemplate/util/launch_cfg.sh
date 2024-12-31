#!/bin/bash

# PROJECT_ROOT is only used for passing to Tresos Studio (mostly via Make)
# hence it's still in DOS format
export	PROJECT_ROOT=$(cygpath -am ..)
export	PROJECT_ROOT=${PROJECT_ROOT%%/}\
	WORK_BASE=$(cygpath -am C:/work/workspace/ACP-8.8.7_S32K14x_33267)\

# dependent on WORK_BASE and PROJECT_ROOT
export	TEST_SEQUENCE=${PROJECT_ROOT##*/}\
	TRESOS_BASE=${TRESOS_BASE:=B:/ACP-8.8.7_S32K14x_33267/Tresos}\
	TOOLS_BASE=${TOOLS_BASE:=${WORK_BASE}/tools}\
	TEST_BASE=${WORK_BASE}/tests\
	LOG_BASE=${WORK_BASE}/TestProtocols/LogBase\
	TESTPROTOCOLS_PATH=${WORK_BASE}/TestProtocols\

# dependent on TRESOS_BASE + the rest
export	PLUGINS_BASE=${PLUGINS_BASE:=${TRESOS_BASE}/plugins}\
	TARGET=${TARGET:=CORTEXM}\
	DERIVATE=${DERIVATE:=S32K14X}\
	TOOLCHAIN=${TOOLCHAIN:=iar}\
	TOOLPATH_COMPILER=${TOOLPATH_COMPILER:=C:/work/workspace/ACP-8.8.7_S32K14x_33267/tools/toolchain}\
	MISRA_MODULE=ApplTemplates\
	MODULE_NAME=ApplTemplates\
	INTERNAL_MODULE_NAME=asc_ApplTemplates\
	MODULE_VARIANT=TS_TxDxM6I8R0\
	MODULE_ID=ApplTemplates_TS_TxDxM6I8R0\
	MAKEFILES=Makefile.mak\

USERBUILD_SHELL=C:/Windows/system32/cmd.exe
MAKE_BASE="$(cygpath -am ${PLUGINS_BASE}/Make_TS_TxDxM*)"\
export	PATH="${MAKE_BASE}/tools/GNU_Make:${MAKE_BASE}/tools/GNU_Utils:${PATH}:${TRESOS_BASE}/bin"
[[ -z "${TOOLPATH_COMPILER}" ]] || export PATH="${PATH}:${TOOLPATH_COMPILER}/bin:${TOOLPATH_COMPILER}/lib"
[[ -n "${EB_VERBOSE}" ]] || echo launch_cfg: TEST_SEQUENCE=${TEST_SEQUENCE}   PROJECT_ROOT=${PROJECT_ROOT}  WORK_BASE=${WORK_BASE}

