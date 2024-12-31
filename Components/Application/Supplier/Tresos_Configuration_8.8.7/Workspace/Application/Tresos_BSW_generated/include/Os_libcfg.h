/* This file is generated automatically. DO NOT EDIT!!
 * 
 * EB tresos AutoCore OS 6.1.144 CORTEXM/S32K14X
 * (Build 20230308)
 * 
 * (c) 1998-2023 Elektrobit Automotive GmbH
 * Am Wolfsmantel 46
 * 91058 Erlangen
 * GERMANY
 * 
 * 
 * The name of the optimized lib will be : OS_lib_2001af5b88
 */

#ifndef OS_LIBCFG_H
#define OS_LIBCFG_H
#ifdef __cplusplus
extern "C" {
#endif

#define OS_GENERATION_ID_OS_LIBCONF_H  0x1905575eUL

#define OS_AUTOSAROS_VER         6

#define OS_AUTOSAROS_REV         1

#define OS_AUTOSAROS_CORE_BUILD  20230308

#define OS_AUTOSAROS_ARCH_BUILD  20230308

#define OS_USE_OPTIMIZATION_OPTIONS         1
#if OS_USE_OPTIMIZATION_OPTIONS
#define OS_EXCLUDE_EXTRA_CHECK              1
#define OS_EXCLUDE_PRETASKHOOK              1
#define OS_EXCLUDE_POSTTASKHOOK             1
#define OS_EXCLUDE_STARTUPHOOK              1
#define OS_EXCLUDE_PREISRHOOK               1
#define OS_EXCLUDE_POSTISRHOOK              1
#define OS_EXCLUDE_TIMINGPROTECTION         1
#define OS_EXCLUDE_RATEMONITORS             1
#define OS_EXCLUDE_RESOURCEONISR            1
#define OS_EXCLUDE_PARAMETERACCESS          1
#define OS_EXCLUDE_ERRORHOOK_APP            1
#define OS_EXCLUDE_MULTIPLE_ACTIVATIONS     1
#define OS_EXCLUDE_HW_FP                    1
#define OS_EXCLUDE_SWCOUNTER                1
#endif

#ifdef __cplusplus
}
#endif
#endif  /* OS_LIBCFG_H */
