/**
 * \file
 *
 * \brief AUTOSAR Demo_VAG
 *
 * This file contains the implementation of the AUTOSAR
 * module Demo_VAG.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef _PLATFORMS_DEFS_H_
#define _PLATFORMS_DEFS_H_


#ifndef PLATFORMS_TOOLCHAIN
#error "PLATFORMS_TOOLCHAIN is not defined. Check your Makefiles!"
#endif

/*Supported Toolchains */
#define PLATFORMS_gnu           1
#define PLATFORMS_dcc           2
#define PLATFORMS_multi         3
#define PLATFORMS_tasking       4
#define PLATFORMS_softune       5
#define PLATFORMS_mwerks        6
#define PLATFORMS_ccs           7
#define PLATFORMS_ticgt         8
#define PLATFORMS_csp           9


/* exclude typdefs for ASM code */
#ifndef BOARD_ASM

typedef uint8 Platforms_PowerType;
#define PLATFORMS_MCU_IDLE      0x00
#define PLATFORMS_MCU_SLEEP     0x01
#define PLATFORMS_MCU_STANDBY   0x02

typedef uint8 Platforms_ResetType;
#define PLATFORMS_POWER_ON_RESET       0x00U /* Power on reset event. */
#define PLATFORMS_WATCHDOG_RESET       0x01U /* Internal Watchdog Timer reset event. */
#define PLATFORMS_SW_RESET             0x02U /* Software Reset event. */
#define PLATFORMS_RESET_UNDEFINED      0x03U /* Undefined reset source. */
#define PLATFORMS_SOFT_DEST_RESET      0x04U /* Software destructive reset. */
#define PLATFORMS_1_2_LV_RESET         0x05U /* 1.2 V low-voltage detected event. */
#define PLATFORMS_1_2_HV_RESET         0x06U /* 1.2 V high-voltage detected event. */
#define PLATFORMS_2_7_LV_VREG_RESET    0x07U /* 2.7 V low-voltage detected event (VREG). */
#define PLATFORMS_2_7_LV_FLASH_RESET   0x08U /* 2.7 V low-voltage detected event (FLASH). */
#define PLATFORMS_2_7_LV_IO_RESET      0x09U /* 2.7 V low-voltage detected event (I/O). */
#define PLATFORMS_JTAG_RESET           0x0AU /* JTAG initiated reset event. */
#define PLATFORMS_CORE_RESET           0x0BU /* CORE reset event. */
#define PLATFORMS_CWD_RESET            0x0CU /* Watchdog reset event. */
#define PLATFORMS_PLL0_RESET           0x0DU /* PLL0 fail event. */
#define PLATFORMS_CMU_OLR_RESET        0x0EU /* Oscillator frequency lower than reference event. */
#define PLATFORMS_CMU_FHL_RESET        0x0FU /* CMU0 clock frequency higher/lower than reference event. */
#define PLATFORMS_FCCU_SAFE_RESET      0x10U /* FCCU safe mode event. */
#define PLATFORMS_PLL1_RESET           0x11U /* PLL1 fail event. */
#define PLATFORMS_FL_ECC_RCC_RESET     0x12U /* flash, ECC or lock-step error event. */
#define PLATFORMS_CMU12_FHL_RESET      0x13U /* CMU 1/2 clock frequence too high/low event. */
#define PLATFORMS_ST_DONE_RESET        0x14U /* Self-test completed event. */
#define PLATFORMS_FCCU_SOFT_RESET      0x15U /* FCCU soft reaction request event. */
#define PLATFORMS_FCCU_HARD_RESET      0x16U /* FCCU hard reaction request event. */
#define PLATFORMS_EXR_RESET            0x17U /* external reset event. */
#define PLATFORMS_RGM_DES_REG_MASK              ((uint16)0xFFFFU)
#define PLATFORMS_RGM_FES_REG_MASK              ((uint16)0xFFFFU)
#define PLATFORMS_MASK_EXT_RESET                ((uint32)0x80000000UL)
#define PLATFORMS_MASK_ST_NCF_RESET             ((uint32)0x40000000UL)
#define PLATFORMS_MASK_FCCU_HARD_RESET          ((uint32)0x40000000UL)
#define PLATFORMS_MASK_FCCU_SOFT_RESET          ((uint32)0x20000000UL)
#define PLATFORMS_MASK_ST_CF_RESET              ((uint32)0x20000000UL)
#define PLATFORMS_MASK_ST_DONE_RESET            ((uint32)0x10000000UL)
#define PLATFORMS_MASK_CMU12_FHL_RESET          ((uint32)0x08000000UL)
#define PLATFORMS_MASK_FL_ECC_RCC_RESET         ((uint32)0x04000000UL)
#define PLATFORMS_MASK_Z4CORE_RESET             ((uint32)0x04000000UL)
#define PLATFORMS_MASK_PLL1_RESET               ((uint32)0x02000000UL)
#define PLATFORMS_MASK_SWT_F_RESET              ((uint32)0x01000000UL)
#define PLATFORMS_MASK_FLASH_RESET              ((uint32)0x01000000UL)
#define PLATFORMS_MASK_FCCU_SAFE_RESET          ((uint32)0x00800000UL)
#define PLATFORMS_MASK_LVD45_RESET              ((uint32)0x00800000UL)
#define PLATFORMS_MASK_CMU0_FHL_RESET           ((uint32)0x00400000UL)
#define PLATFORMS_MASK_CMU0_OLR_RESET           ((uint32)0x00200000UL)
#define PLATFORMS_MASK_PLL0_RESET               ((uint32)0x00100000UL)
#define PLATFORMS_MASK_CWD_RESET                ((uint32)0x00080000UL)
#define PLATFORMS_MASK_CHECKSTOP_RESET          ((uint32)0x00080000UL)
#define PLATFORMS_MASK_SOFT_FUNC_RESET          ((uint32)0x00040000UL)
#define PLATFORMS_MASK_CORE_RESET               ((uint32)0x00020000UL)
#define PLATFORMS_MASK_JTAG_RESET               ((uint32)0x00010000UL)
#define PLATFORMS_MASK_POR_RESET                ((uint32)0x00008000UL)
#define PLATFORMS_MASK_SOFT_DEST_RESET          ((uint32)0x00004000UL)
#define PLATFORMS_MASK_LVD27_ADC_RESET          ((uint32)0x00000080UL)
#define PLATFORMS_MASK_LVD27_IO_RESET           ((uint32)0x00000040UL)
#define PLATFORMS_MASK_LVD27_FLASH_RESET        ((uint32)0x00000020UL)
#define PLATFORMS_MASK_LVD27_VREG_RESET         ((uint32)0x00000010UL)
#define PLATFORMS_MASK_LVD27_RESET              ((uint32)0x00000008UL)
#define PLATFORMS_MASK_SWT_D_RESET              ((uint32)0x00000004UL)
#define PLATFORMS_MASK_SWT1_D_RESET             ((uint32)0x00000008UL)
#define PLATFORMS_MASK_LVD12_PD1_RESET          ((uint32)0x00000002UL)
#define PLATFORMS_MASK_HVD12_RESET              ((uint32)0x00000002UL)
#define PLATFORMS_MASK_LVD12_PD0_RESET          ((uint32)0x00000001UL)
#define PLATFORMS_MASK_LVD12_RESET              ((uint32)0x00000001UL)
#define PLATFORMS_MASK_COMP_RESET               ((uint32)0x00000080UL)

#endif /* BOARD_ASM */

#endif /* _PLATFORMS_DEFS_H_ */
