/* Os_types_S32K14X.h - Properties and types of S32K14X
 *
 * This file contains the public properties and types that are S32K14X
 * specific.
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_types_S32K14X.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_TYPES_S32K14X_H
#define OS_TYPES_S32K14X_H

#ifdef __cplusplus
extern "C" {
#endif

/* Data type characteristics:
 *
 * - OS_ENDIAN:			either OS_LITTLEENDIAN or OS_BIGENDIAN, as necessary.
 * - OS_ARCH_HAS_64BIT:	0 (64 bit data type not supported) or 1 (64 bit data type supported).
*/
#define OS_ENDIAN				OS_LITTLEENDIAN
#define OS_ARCH_HAS_64BIT		0

/* This derivative has no internal timestamp timer. */
#define OS_HAS_TB_INTERNAL 0

#ifdef __cplusplus
}
#endif

#endif
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
