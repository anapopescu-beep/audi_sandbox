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
 */

#ifndef OS_KCONFIG_H
#define OS_KCONFIG_H
#ifdef __cplusplus
extern "C" {
#endif

#define OS_GENERATION_ID_OS_KCONF_H  0x1905575eUL

#define OS_AUTOSAROS_VER             6

#define OS_AUTOSAROS_REV             1

#define OS_AUTOSAROS_CORE_BUILD      20230308

#define OS_AUTOSAROS_ARCH_BUILD      20230308

/*===================================================================
 * Configured Modes
 *==================================================================*/
/* The OS TRACER is configured as follows: */
#define OS_USE_TRACE  1

/*===================================================================
 * Core Mapping
 *==================================================================*/
/* OS_INITCORE tells the build process which core the OS uses (singlecore). */
#define OS_INITCORE  0

/*===================================================================
 * Kernel Type
 *==================================================================*/
/* Defines which trapping mechanism the OS shall use. */
#define OS_KERNEL_TYPE  OS_SYSTEM_CALL

/*===================================================================
 * Multicore
 *==================================================================*/
/* Defines the number of CPU cores assigned to EB tresos AutoCore OS. */
#define OS_N_CORES  1
#ifdef __cplusplus
}
#endif
#endif  /* OS_KCONFIG_H */
