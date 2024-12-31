/* Os_mpu_CORTEXM.h - MPU header file for CORTEXM
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_mpu_CORTEXM.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_MPU_CORTEXM_H
#define OS_MPU_CORTEXM_H

#include <Os_types.h>

/* Macros for MPU sizes. */
#define OS_CORTEXM_MPU_SIZE_DISABLED	0u
#define OS_CORTEXM_MPU_SIZE_32			((5u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_64			((6u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_128			((7u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_256			((8u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_512			((9u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_1K			((10u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_2K			((11u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_4K			((12u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_8K			((13u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_16K			((14u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_32K			((15u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_64K			((16u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_128K		((17u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_256K		((18u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_512K		((19u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_1M			((20u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_2M			((21u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_4M			((22u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_8M			((23u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_16M			((24u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_32M			((25u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_64M			((26u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_128M		((27u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_256M		((28u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_512M		((29u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_1G			((30u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_2G			((31u - 1u) << 1u)
#define OS_CORTEXM_MPU_SIZE_4G			((32u - 1u) << 1u)

/* Region indices for all MPU regions that are used by the OS. */
#define OS_MPU_ROM_RNR				OS_U(0)
#define OS_MPU_RAM_RNR				OS_U(1)
#define OS_MPU_KERNSTACK_RNR		OS_U(2)
#define OS_MPU_IO_PRIV_RNR			OS_U(3)
#define OS_MPU_USERSTACK_RNR		OS_U(4)
#define OS_MPU_USERDATA_RNR			OS_U(5)
#define OS_MPU_USERAPPDATA_RNR		OS_U(6)

/* Definitions for bits in RASR. */
#define OS_CORTEXM_MPU_RASR_ENABLE	(1 <<  0)
#define OS_CORTEXM_MPU_RASR_S_RO	(1 << 26)

#ifndef OS_ASM
extern const void * const OS_romBase;
extern const void * const OS_romLimit;

extern const void * const OS_ramBase;
extern const void * const OS_ramLimit;

extern const void * const OS_ioBase;
extern const void * const OS_ioLimit;

extern const os_uint8_t OS_romMpuSize;
extern const os_uint8_t OS_ramMpuSize;
extern const os_uint8_t OS_ioMpuSize;

extern const os_uint8_t OS_eHookMpuSize;
extern const os_uint8_t OS_sHookMpuSize;

extern const os_uint8_t OS_kernStackMpuSize[OS_N_CORES_MAX];

/* Reset global RAM to read/write permissions for supervisor.
*/
#define OS_CORTEXM_RESETKERNSTACKRW(app) OS_DoMemoryProtection(OS_CORTEXM_ResetKernStackRw(app))

#endif	/* OS_ASM */

#endif	/* OS_MPU_CORTEXM_H */
/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
