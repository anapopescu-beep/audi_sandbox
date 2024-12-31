/* Os_mpu_armv8_CORTEXM.h - MPU header file for ARMv8
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_mpu_armv8_CORTEXM.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_MPU_ARMV8_CORTEXM_H
#define OS_MPU_ARMV8_CORTEXM_H

#include <Os_types.h>

#ifndef OS_ASM

struct os_cortexm_region_s
{
	os_uint32_t rbar;
	os_uint32_t rlar;
};
typedef struct os_cortexm_region_s os_cortexm_region_t;

extern const void * const OS_romBase;
extern const void * const OS_romLimit;

extern const void * const OS_ramBase;
extern const void * const OS_ramLimit;

extern const void * const OS_ioBase;
extern const void * const OS_ioLimit;

#endif

/* Minimum region size (in bytes). */
#define OS_MPU_RXAR_ALIGN			OS_U(32)

/* Mask for addressen in both, RBAR and RLAR registers. */
#define OS_MPU_RXAR_MASK			OS_U(0xffffffe0)
/* Mask for attributes etc. in both, RBAR and RLAR registers. */
#define OS_MPU_RXAR_REST_MASK		OS_U(0x1f)
/* Enable bit in RLAR. */
#define OS_MPU_RLAR_EN				OS_U(0x01)
/* Mask for attribute index in RLAR. */
#define OS_MPU_RLAR_ATTR_MASK		OS_U(0x0e)

/* Region indices for static MPU regions that are used by the OS. */
#define OS_MPU_N_STATIC_REGIONS		OS_U(3)
#define OS_MPU_IO_PRIV_RNR			OS_U(0)
#define OS_MPU_ROM_RNR				OS_U(1)
#define OS_MPU_RAM_RNR				OS_U(2)

/* Macros for dynamic region indices. */
#define OS_MPU_DYNAMIC_REGIONS		OS_U(9)
#define OS_MPU_FIRST_DYN_REGION		OS_U(3)
/* The kernel stack region is the first dynamic region. */
#define OS_MPU_KERNELSTACK_RNR		OS_MPU_FIRST_DYN_REGION
#define OS_MPU_KERNELSTACK_DYN_IDX	OS_U(0)

/* Reset global RAM to read/write permissions for supervisor.
*/
#define OS_CORTEXM_RESETKERNSTACKRW(app) do { } while (0)

#endif /* OS_MPU_ARMV8_CORTEXM_H */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
