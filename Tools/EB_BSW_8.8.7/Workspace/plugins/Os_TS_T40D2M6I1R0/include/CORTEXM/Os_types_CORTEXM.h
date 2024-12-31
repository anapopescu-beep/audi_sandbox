/* Os_types_CORTEXM.h
 *
 * This file defines the basic data types for CORTEXM architecture
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_types_CORTEXM.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#ifndef OS_TYPES_CORTEXM_H
#define OS_TYPES_CORTEXM_H

#include <Os_defs.h>

/* Include the appropriate header file for the derivative.
 *
 * CAVEAT:
 * The presence here of an include directive for a particular derivative
 * does not imply support for that derivative, nor does it imply a
 * commitment or intention to support that derivative in the future.
*/
#if (OS_CPU == OS_MV88Q5050)
#include <CORTEXM/MV88Q5050/Os_types_MV88Q5050.h>
#elif (OS_CPU == OS_MV88Q5072)
#include <CORTEXM/MV88Q5072/Os_types_MV88Q5072.h>
#elif (OS_CPU == OS_S32K14X)
#include <CORTEXM/S32K14X/Os_types_S32K14X.h>
#elif (OS_CPU == OS_BCM89107)
#include <CORTEXM/BCM89107/Os_types_BCM89107.h>
#elif (OS_CPU == OS_CYT4BF)
#include <CORTEXM/CYT4BF/Os_types_CYT4BF.h>
#elif (OS_CPU == OS_CYT4BB)
#include <CORTEXM/CYT4BB/Os_types_CYT4BB.h>
#elif (OS_CPU == OS_CYT3DL)
#include <CORTEXM/CYT3DL/Os_types_CYT3DL.h>
#elif (OS_CPU == OS_IMX8QMM4)
#include <CORTEXM/IMX8QMM4/Os_types_IMX8QMM4.h>
#elif (OS_CPU == OS_CYT2B95)
#include <CORTEXM/CYT2B95/Os_types_CYT2B95.h>
#elif (OS_CPU == OS_S32G27X)
#include <CORTEXM/S32G27X/Os_types_S32G27X.h>
#elif (OS_CPU == OS_IMX8DXLM4)
#include <CORTEXM/IMX8DXLM4/Os_types_IMX8DXLM4.h>
#elif (OS_CPU == OS_MV88Q6113)
#include <CORTEXM/MV88Q6113/Os_types_MV88Q6113.h>
#elif (OS_CPU == OS_S32K34X)
#include <CORTEXM/S32K34X/Os_types_S32K34X.h>
#elif (OS_CPU == OS_SAME5X)
#include <CORTEXM/SAME5X/Os_types_SAME5X.h>
#elif (OS_CPU == OS_IMX8QXPM4)
#include <CORTEXM/IMX8QXPM4/Os_types_IMX8QXPM4.h>
#elif (OS_CPU == OS_RTL90XXA)
#include <CORTEXM/RTL90XXA/Os_types_RTL90XXA.h>
#elif (OS_CPU == OS_S32G399)
#include <CORTEXM/S32G399/Os_types_S32G399.h>
#elif (OS_CPU == OS_S32K31X)
#include <CORTEXM/S32K31X/Os_types_S32K31X.h>
#elif (OS_CPU == OS_S32Z27XM33)
#include <CORTEXM/S32Z27XM33/Os_types_S32Z27XM33.h>
#elif (OS_CPU == OS_S32R45X)
#include <CORTEXM/S32R45X/Os_types_S32R45X.h>
#elif (OS_CPU == OS_CYT2B75)
#include <CORTEXM/CYT2B75/Os_types_CYT2B75.h>
#elif (OS_CPU == OS_SAF85XXM7)
#include <CORTEXM/SAF85XXM7/Os_types_SAF85XXM7.h>
#elif (OS_CPU == OS_SR6P6M4)
#include <CORTEXM/SR6P6M4/Os_types_SR6P6M4.h>
#else
#error "Unsupported derivative."
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Sizes for computing struct offsets for assembler
*/
#define OS_SIZEOF_PTR	OS_U(4)
#define OS_SIZEOF_FPTR	OS_SIZEOF_PTR

#ifndef OS_ASM
/* Fixed-length types
*/

typedef unsigned char		os_uint8_t;
typedef signed char			os_int8_t;
typedef unsigned short		os_uint16_t;
typedef signed short		os_int16_t;
typedef unsigned int		os_uint32_t;
typedef signed int			os_int32_t;

/* Types for address/size of memory object
*/
typedef unsigned int		os_address_t;
typedef signed int			os_ptrdiff_t;
typedef unsigned int		os_size_t;

/* Type for a stack element.
*/
typedef unsigned int		os_stackelement_t;

/* Type for a service parameter.
 *
 * An integer type big enough to hold any OS Service parameter.
 * Used for error handling.
*/
typedef os_uint32_t os_paramtype_t;

/* Type for a synchronisation semaphore.
 * Note: Cortex-M may implement a granularity between 2 and 11 address
 * bits. However, Cortex-M7 only stores a single address, so the
 * granularity does not apply.
*/
typedef os_uint32_t os_syncspot_t;

#endif

/* This architecture does not define special os_char_t/os_uchar_t
 * types but perfectly gets by with signed/unsigned char.
*/
#define OS_ARCH_HAS_CHAR_T 0

#define OS_SIZEOF_STACKELEMENT	4

/*!
 * os_intstatus_t, os_oldlevel_t
 *
 * Used for saving and restoring interrupt status.
 *
 * os_intstatus_t is used internally by the kernel.
 *
 * os_oldlevel_t is the type for the old-level locations used by
 * the API interrupt management functions.
 *
*/
#ifndef OS_ASM
typedef os_uint16_t os_intstatus_t;
typedef os_uint16_t os_oldlevel_t;
#endif /* ! OS_ASM */

/* sizeof os_oldlevel_t (must evaluate in context of preprocessor only) */
#define OS_SIZEOF_OLDLEVEL 2

/* CORTEXM-specific system calls.
*/

/* OS_CORTEXM_K_Exception - OS internal system call to handle exceptions.
*/
#ifndef OS_ASM
extern void OS_CORTEXM_K_Exception(void);
#endif

#define OS_K_CPUFAMILY_1	&OS_CORTEXM_K_Exception

/* Additional idle mode for CORTEXM.
 * IDLE_NO_HALT is defined globally to 0, so we add up to 2 idle modes.
*/
#define OS_IDLE_WFI		OS_U(1)
#define OS_N_IDLE_MODES	OS_U(2)

#ifdef __cplusplus
}
#endif

#endif
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
