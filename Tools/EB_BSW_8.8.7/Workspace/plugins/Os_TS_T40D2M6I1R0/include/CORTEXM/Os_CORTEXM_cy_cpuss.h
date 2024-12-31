/* Os_CORTEXM_cy_cpuss.h
 *
 * This file provides support for the Cypress CPU Subsystem.
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_CORTEXM_cy_cpuss.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#ifndef OS_CORTEXM_CY_CPUSS_H
#define OS_CORTEXM_CY_CPUSS_H

#include <Os_defs.h>
#include <CORTEXM/Os_CORTEXM_cpu.h>

#define OS_CY_CPUSS_INT_VALID_MASK		(0x80000000u)
#define OS_CY_CPUSS_INT_SRC_MASK		(0x000003FFu)
#define OS_CY_CPUSS_INT_DISABLED		(0x00000007u)	/* enabled bit cleared, lowest priority */
#define OS_CY_CPUSS_INT_ENABLE_BIT		(0x80000000u)

#define OS_CY_CPUSS_INT_STATUS_OFF		(0x100u)	/* offset to interrupt status register in core control block */

#define OS_CY_CPUSS_IDENTITY_MS_Shift	(8u)		/* bit shift to extract bus master from identity register */
#define OS_CY_CPUSS_CORECTL_Shift		(10u)		/* control blocks are 1 KiB, shift core id by 10 for offset */

#ifndef OS_ASM

#define OS_CY_CPUSS						(*(os_cycpuss_t*)OS_CORTEXM_CPUSS_BASE)

typedef struct os_cycpuss_corectl_s os_cycpuss_corectl_t;
struct os_cycpuss_corectl_s
{
	os_reg32_t identity;			/* 00h Processor type register. Only implemented on 1st core in the main struct */
	os_reg32_t status;				/* 04h Core status */
	os_reg32_t clock_ctl;			/* 08h Fast core clock control */
	os_reg32_t ctl;					/* 0Ch Core control */
	os_reg32_t padding[60];
	os_reg32_t int_status[8];		/* 100h CPU interrupt status */
	os_reg32_t padding2[56];		/* May support up to 64 CPU interrupts in future implementations */
	os_reg32_t vector_base;			/* 200h Vector table base address */
	os_reg32_t padding3[15];
	os_reg32_t nmi_ctl[4];			/* 240h NMI control */
	os_reg32_t padding4[52];		/* May support up to 64 NMIs in future implementations */
	os_reg32_t trc_dbg_clock_ctl;	/* 320h Trace and debug clock control. Only implemented on 1st core */
	os_reg32_t padding5[55];
};

typedef struct os_cycpuss_corepwr_s os_cycpuss_corepwr_t;
struct os_cycpuss_corepwr_s
{
	os_reg32_t	pwr_ctl;			/* 00h Power control of main application core */
	os_reg32_t	delay_ctl;			/* 04h Power delay control of main application core */
	os_reg32_t	padding[2];
};

typedef struct os_cycpuss_coreint_s os_cycpuss_coreint_t;
struct os_cycpuss_coreint_s
{
	os_reg32_t intr[1023];			/* System interrupt control. Highest ID not implemented, used to disable NMIs */
	os_reg32_t padding[1025];		/* Interrupt multiplexer may support 2048(-1) inputs in future implementations */
};

typedef struct os_cycpuss_s os_cycpuss_t;
struct os_cycpuss_s
{
	os_cycpuss_corectl_t maincore[2];	/* 00h CPU control structure of the CM4/CM7 main application cores */
	os_reg32_t padding[512];		/* May support up to 4 main application cores in future implementations */
	os_reg32_t cm0_ctl;				/* 1000h Core control of CM0 boot core */
	os_reg32_t cm0_status;			/* 1004h Core status of CM0 boot core */
	os_reg32_t slow_clock_ctl;		/* 1008h Slow clock Control */
	os_reg32_t peri_clock_ctl;		/* 100Ch Peripheral interconnect clock control */
	os_reg32_t mem_clock_ctl;		/* 1010h Memory clock control */
	os_reg32_t padding2[59];
	os_reg32_t cm0_int_status[8];	/* 1100h CM0 CPU interrupt status */
	os_reg32_t cm0_vector_base;		/* 1120h CM0 Vector table base address */
	os_reg32_t padding3[7];
	os_reg32_t cm0_nmi_ctl[4];		/* 1140h CM0 NMI control */
	os_reg32_t padding4[44];
	os_cycpuss_corepwr_t pwr[2];	/* 1200h Power control registers of CM4/CM7 main application cores */
	os_reg32_t padding5[56];		/* May support up to 4 main application cores in future implementations */
	os_reg32_t ram0_ctl0;			/* 1300h RAM 0 control */
	os_reg32_t ram0_status;			/* 1304h RAM 0 status */
	os_reg32_t padding6[14];
	os_reg32_t ram0_pwr_macro[16];	/* 1340h RAM 0 power control */
	os_reg32_t ram1_ctl0;			/* 1380h RAM 1 control */
	os_reg32_t ram1_status;			/* 1384h RAM 1 status */
	os_reg32_t ram1_pwr_ctl;		/* 1388h RAM 1 power control */
	os_reg32_t padding7[5];
	os_reg32_t ram2_ctl0;			/* 13A0h RAM 2 control */
	os_reg32_t ram2_status;			/* 13A4h RAM 2 status */
	os_reg32_t ram2_pwr_ctl;		/* 13A8h RAM 2 power control */
	os_reg32_t padding8[5];
	os_reg32_t ram_pwr_delay_ctl;	/* 13C0h Power up delay for all SRAM power domains */
	os_reg32_t rom_ctl;				/* 13C4h ROM control */
	os_reg32_t ecc_ctl;				/* 13C8h ECC control */
	os_reg32_t padding9[13];
	os_reg32_t product_id;			/* 1400h Product identifier and version (same as CoreSight RomTables) */
	os_reg32_t padding10[3];
	os_reg32_t dp_status;			/* 1410h Debug port status */
	os_reg32_t ap_ctl;				/* 1414h Access port control */
	os_reg32_t padding11[58];
	os_reg32_t buff_ctl;			/* 1500h Buffer control */
	os_reg32_t padding12[63];
	os_reg32_t systick_ctl;			/* 1600h SysTick timer control */
	os_reg32_t padding13[127];
	os_reg32_t cal_sup_set;			/* 1800h Calibration support set and read */
	os_reg32_t cal_sup_clr;			/* 1804h Calibration support clear and reset */
	os_reg32_t padding14[510];
	os_reg32_t cm0_pc_ctl;			/* 2000h CM0 protection context control */
	os_reg32_t padding15[15];
	os_reg32_t cm0_pc_handler[4];	/* 2040h CM0 protection context handler */
	os_reg32_t padding16[29];
	os_reg32_t protection;			/* 20C4h Protection status */
	os_reg32_t padding17[14];
	os_reg32_t trim_rom_ctl;		/* 2100h ROM trim control */
	os_reg32_t trim_ram_ctl;		/* 2104h RAM trim control for <100MHz SRAM */
	os_reg32_t trim_ram200_ctl;		/* 2108h RAM trim control for >100MHz <200MHz SRAM */
	os_reg32_t trim_ram350_ctl;		/* 210Ch RAM trim control for >200MHz SRAM */
	os_reg32_t padding18[6076];
	os_cycpuss_coreint_t cm0_int_ctl;	/* 8000h CMO system interrupt control */
	os_cycpuss_coreint_t int_ctl[2];	/* A000h main application cores interrupt control */
};

#endif /* OS_ASM */

#endif /* OS_CORTEXM_CY_CPUSS_H */

/* Editor settings: DO NOT DELETE
 * vi: set ts=4:
*/
