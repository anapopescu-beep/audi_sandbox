/*
** ###################################################################
**     Processor:           S32K142_M4
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K1XX RM Rev.13
**     Version:             rev. 1.0, 2021-02-24
**     Build:               b210224
**
**     Abstract:
**         Peripheral Access Layer for S32K142_M4
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2021 NXP
**
**     NXP Confidential. This software is owned or controlled by NXP and may only be
**     used strictly in accordance with the applicable license terms. By expressly
**     accepting such terms or by downloading, installing, activating and/or otherwise
**     using the software, you are agreeing that you have read, and that you agree to
**     comply with and are bound by, such license terms. If you do not agree to be
**     bound by the applicable license terms, then you may not retain, install,
**     activate or otherwise use the software. The production use license in
**     Section 2.3 is expressly granted for this software.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
** ###################################################################
*/

/*!
 * @file S32K142_CTI.h
 * @version 1.0
 * @date 2021-02-24
 * @brief Peripheral Access Layer for S32K142_CTI
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32K142_CTI_H_)  /* Check if memory map has not been already included */
#define S32K142_CTI_H_

#include "S32K142_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CTI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CTI_Peripheral_Access_Layer CTI Peripheral Access Layer
 * @{
 */

/** CTI - Register Layout Typedef */
typedef struct {
  __IO uint32_t MBIST_COM_CTRL;                    /**< RAMBIST COMMON CONTROL Register, offset: 0x0 */
  __IO uint32_t MBIST_SEL;                         /**< RAMBIST Selection Register, offset: 0x4 */
  __IO uint32_t MBIST_LOOP_CNT;                    /**< RAMBIST Loop Counter Register, offset: 0x8 */
  __I  uint32_t MBIST_STATUS_1;                    /**< The First Group of MBIST Status Register, offset: 0xC */
       uint32_t MBIST_STATUS_2;                    /**< The Second Group of MBIST Status Register, offset: 0x10 */
  __IO uint32_t MBIST_ALGORITHM;                   /**< RAMBIST Algorithm Register, offset: 0x14 */
  uint8_t RESERVED_0[8];
  __IO uint32_t MBIST_REPAIR_CTRL;                 /**< RAMBIST Repair Control Register, offset: 0x20 */
  __I  uint32_t MBIST_REPAIR_STATUS;               /**< RAMBIST REPAIR STATUS Register, offset: 0x24 */
       uint32_t MBIST_REPAIR_INFO_1;               /**< MBIST Repair Info Register, offset: 0x28 */
       uint32_t MBIST_REPAIR_INFO_2;               /**< MBIST Repair Info Register, offset: 0x2C */
       uint32_t MBIST_REPAIR_INFO_3;               /**< MBIST Repair Info Register, offset: 0x30 */
       uint32_t MBIST_REPAIR_INFO_4;               /**< MBIST Repair Info Register, offset: 0x34 */
       uint32_t MBIST_REPAIR_INFO_5;               /**< MBIST Repair Info Register, offset: 0x38 */
       uint32_t MBIST_REPAIR_INFO_6;               /**< MBIST Repair Info Register, offset: 0x3C */
       uint32_t MBIST_REPAIR_INFO_7;               /**< MBIST Repair Info Register, offset: 0x40 */
       uint32_t MBIST_REPAIR_INFO_8;               /**< MBIST Repair Info Register, offset: 0x44 */
  uint8_t RESERVED_1[8];
  __IO uint32_t RAMLOADER_START_ADR;               /**< RAMLOADER START ADDRESS Register, offset: 0x50 */
  uint8_t RESERVED_2[44];
  __IO uint32_t CTI_MODE;                          /**< CTI MODE Register, offset: 0x80 */
  uint8_t RESERVED_3[60];
  __IO uint32_t CTI_MIX_CTRL;                      /**< CTI MIX ControlRegister, offset: 0xC0 */
} CTI_Type, *CTI_MemMapPtr;

/** Number of instances of the CTI module. */
#define CTI_INSTANCE_COUNT                       (1u)

/* CTI - Peripheral instance base addresses */
/** Peripheral CTI base address */
#define IP_CTI_BASE                              (0u)
/** Peripheral CTI base pointer */
#define IP_CTI                                   ((CTI_Type *)IP_CTI_BASE)
/** Array initializer of CTI peripheral base addresses */
#define IP_CTI_BASE_ADDRS                        { IP_CTI_BASE }
/** Array initializer of CTI peripheral base pointers */
#define IP_CTI_BASE_PTRS                         { IP_CTI }

/* ----------------------------------------------------------------------------
   -- CTI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CTI_Register_Masks CTI Register Masks
 * @{
 */

/*! @name MBIST_COM_CTRL - RAMBIST COMMON CONTROL Register */
/*! @{ */

#define CTI_MBIST_COM_CTRL_resume_active_cnt_MASK (0xF0U)
#define CTI_MBIST_COM_CTRL_resume_active_cnt_SHIFT (4U)
#define CTI_MBIST_COM_CTRL_resume_active_cnt_WIDTH (4U)
#define CTI_MBIST_COM_CTRL_resume_active_cnt(x)  (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_COM_CTRL_resume_active_cnt_SHIFT)) & CTI_MBIST_COM_CTRL_resume_active_cnt_MASK)

#define CTI_MBIST_COM_CTRL_mbist_pd_b_MASK       (0x2000000U)
#define CTI_MBIST_COM_CTRL_mbist_pd_b_SHIFT      (25U)
#define CTI_MBIST_COM_CTRL_mbist_pd_b_WIDTH      (1U)
#define CTI_MBIST_COM_CTRL_mbist_pd_b(x)         (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_COM_CTRL_mbist_pd_b_SHIFT)) & CTI_MBIST_COM_CTRL_mbist_pd_b_MASK)

#define CTI_MBIST_COM_CTRL_mbist_pd_sben_MASK    (0x4000000U)
#define CTI_MBIST_COM_CTRL_mbist_pd_sben_SHIFT   (26U)
#define CTI_MBIST_COM_CTRL_mbist_pd_sben_WIDTH   (1U)
#define CTI_MBIST_COM_CTRL_mbist_pd_sben(x)      (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_COM_CTRL_mbist_pd_sben_SHIFT)) & CTI_MBIST_COM_CTRL_mbist_pd_sben_MASK)

#define CTI_MBIST_COM_CTRL_mbist_vlp_MASK        (0x8000000U)
#define CTI_MBIST_COM_CTRL_mbist_vlp_SHIFT       (27U)
#define CTI_MBIST_COM_CTRL_mbist_vlp_WIDTH       (1U)
#define CTI_MBIST_COM_CTRL_mbist_vlp(x)          (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_COM_CTRL_mbist_vlp_SHIFT)) & CTI_MBIST_COM_CTRL_mbist_vlp_MASK)

#define CTI_MBIST_COM_CTRL_mbist_diag_en_MASK    (0x10000000U)
#define CTI_MBIST_COM_CTRL_mbist_diag_en_SHIFT   (28U)
#define CTI_MBIST_COM_CTRL_mbist_diag_en_WIDTH   (1U)
#define CTI_MBIST_COM_CTRL_mbist_diag_en(x)      (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_COM_CTRL_mbist_diag_en_SHIFT)) & CTI_MBIST_COM_CTRL_mbist_diag_en_MASK)

#define CTI_MBIST_COM_CTRL_mbist_resume_MASK     (0x20000000U)
#define CTI_MBIST_COM_CTRL_mbist_resume_SHIFT    (29U)
#define CTI_MBIST_COM_CTRL_mbist_resume_WIDTH    (1U)
#define CTI_MBIST_COM_CTRL_mbist_resume(x)       (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_COM_CTRL_mbist_resume_SHIFT)) & CTI_MBIST_COM_CTRL_mbist_resume_MASK)

#define CTI_MBIST_COM_CTRL_mbist_invoke_MASK     (0x40000000U)
#define CTI_MBIST_COM_CTRL_mbist_invoke_SHIFT    (30U)
#define CTI_MBIST_COM_CTRL_mbist_invoke_WIDTH    (1U)
#define CTI_MBIST_COM_CTRL_mbist_invoke(x)       (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_COM_CTRL_mbist_invoke_SHIFT)) & CTI_MBIST_COM_CTRL_mbist_invoke_MASK)

#define CTI_MBIST_COM_CTRL_mbist_resetb_MASK     (0x80000000U)
#define CTI_MBIST_COM_CTRL_mbist_resetb_SHIFT    (31U)
#define CTI_MBIST_COM_CTRL_mbist_resetb_WIDTH    (1U)
#define CTI_MBIST_COM_CTRL_mbist_resetb(x)       (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_COM_CTRL_mbist_resetb_SHIFT)) & CTI_MBIST_COM_CTRL_mbist_resetb_MASK)
/*! @} */

/*! @name MBIST_SEL - RAMBIST Selection Register */
/*! @{ */

#define CTI_MBIST_SEL_mbist_select0_MASK         (0x80000000U)
#define CTI_MBIST_SEL_mbist_select0_SHIFT        (31U)
#define CTI_MBIST_SEL_mbist_select0_WIDTH        (1U)
#define CTI_MBIST_SEL_mbist_select0(x)           (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_SEL_mbist_select0_SHIFT)) & CTI_MBIST_SEL_mbist_select0_MASK)
/*! @} */

/*! @name MBIST_LOOP_CNT - RAMBIST Loop Counter Register */
/*! @{ */

#define CTI_MBIST_LOOP_CNT_mbist_first_fail_rec_MASK (0xFFFFU)
#define CTI_MBIST_LOOP_CNT_mbist_first_fail_rec_SHIFT (0U)
#define CTI_MBIST_LOOP_CNT_mbist_first_fail_rec_WIDTH (16U)
#define CTI_MBIST_LOOP_CNT_mbist_first_fail_rec(x) (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_LOOP_CNT_mbist_first_fail_rec_SHIFT)) & CTI_MBIST_LOOP_CNT_mbist_first_fail_rec_MASK)

#define CTI_MBIST_LOOP_CNT_mbist_loop_done_cnt_MASK (0xFFFF0000U)
#define CTI_MBIST_LOOP_CNT_mbist_loop_done_cnt_SHIFT (16U)
#define CTI_MBIST_LOOP_CNT_mbist_loop_done_cnt_WIDTH (16U)
#define CTI_MBIST_LOOP_CNT_mbist_loop_done_cnt(x) (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_LOOP_CNT_mbist_loop_done_cnt_SHIFT)) & CTI_MBIST_LOOP_CNT_mbist_loop_done_cnt_MASK)
/*! @} */

/*! @name MBIST_STATUS_1 - The First Group of MBIST Status Register */
/*! @{ */

#define CTI_MBIST_STATUS_1_mbist_fail_0_MASK     (0x20000000U)
#define CTI_MBIST_STATUS_1_mbist_fail_0_SHIFT    (29U)
#define CTI_MBIST_STATUS_1_mbist_fail_0_WIDTH    (1U)
#define CTI_MBIST_STATUS_1_mbist_fail_0(x)       (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_STATUS_1_mbist_fail_0_SHIFT)) & CTI_MBIST_STATUS_1_mbist_fail_0_MASK)

#define CTI_MBIST_STATUS_1_mbist_done_0_MASK     (0x40000000U)
#define CTI_MBIST_STATUS_1_mbist_done_0_SHIFT    (30U)
#define CTI_MBIST_STATUS_1_mbist_done_0_WIDTH    (1U)
#define CTI_MBIST_STATUS_1_mbist_done_0(x)       (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_STATUS_1_mbist_done_0_SHIFT)) & CTI_MBIST_STATUS_1_mbist_done_0_MASK)

#define CTI_MBIST_STATUS_1_mbist_start_ret_MASK  (0x80000000U)
#define CTI_MBIST_STATUS_1_mbist_start_ret_SHIFT (31U)
#define CTI_MBIST_STATUS_1_mbist_start_ret_WIDTH (1U)
#define CTI_MBIST_STATUS_1_mbist_start_ret(x)    (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_STATUS_1_mbist_start_ret_SHIFT)) & CTI_MBIST_STATUS_1_mbist_start_ret_MASK)
/*! @} */

/*! @name MBIST_ALGORITHM - RAMBIST Algorithm Register */
/*! @{ */

#define CTI_MBIST_ALGORITHM_rd_only_bar_MASK     (0x200000U)
#define CTI_MBIST_ALGORITHM_rd_only_bar_SHIFT    (21U)
#define CTI_MBIST_ALGORITHM_rd_only_bar_WIDTH    (1U)
#define CTI_MBIST_ALGORITHM_rd_only_bar(x)       (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_ALGORITHM_rd_only_bar_SHIFT)) & CTI_MBIST_ALGORITHM_rd_only_bar_MASK)

#define CTI_MBIST_ALGORITHM_wr_only_bar_MASK     (0x400000U)
#define CTI_MBIST_ALGORITHM_wr_only_bar_SHIFT    (22U)
#define CTI_MBIST_ALGORITHM_wr_only_bar_WIDTH    (1U)
#define CTI_MBIST_ALGORITHM_wr_only_bar(x)       (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_ALGORITHM_wr_only_bar_SHIFT)) & CTI_MBIST_ALGORITHM_wr_only_bar_MASK)

#define CTI_MBIST_ALGORITHM_rd_only_MASK         (0x800000U)
#define CTI_MBIST_ALGORITHM_rd_only_SHIFT        (23U)
#define CTI_MBIST_ALGORITHM_rd_only_WIDTH        (1U)
#define CTI_MBIST_ALGORITHM_rd_only(x)           (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_ALGORITHM_rd_only_SHIFT)) & CTI_MBIST_ALGORITHM_rd_only_MASK)

#define CTI_MBIST_ALGORITHM_wr_only_MASK         (0x1000000U)
#define CTI_MBIST_ALGORITHM_wr_only_SHIFT        (24U)
#define CTI_MBIST_ALGORITHM_wr_only_WIDTH        (1U)
#define CTI_MBIST_ALGORITHM_wr_only(x)           (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_ALGORITHM_wr_only_SHIFT)) & CTI_MBIST_ALGORITHM_wr_only_MASK)

#define CTI_MBIST_ALGORITHM_retentioncb_MASK     (0x2000000U)
#define CTI_MBIST_ALGORITHM_retentioncb_SHIFT    (25U)
#define CTI_MBIST_ALGORITHM_retentioncb_WIDTH    (1U)
#define CTI_MBIST_ALGORITHM_retentioncb(x)       (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_ALGORITHM_retentioncb_SHIFT)) & CTI_MBIST_ALGORITHM_retentioncb_MASK)

#define CTI_MBIST_ALGORITHM_bit_write_MASK       (0x4000000U)
#define CTI_MBIST_ALGORITHM_bit_write_SHIFT      (26U)
#define CTI_MBIST_ALGORITHM_bit_write_WIDTH      (1U)
#define CTI_MBIST_ALGORITHM_bit_write(x)         (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_ALGORITHM_bit_write_SHIFT)) & CTI_MBIST_ALGORITHM_bit_write_MASK)

#define CTI_MBIST_ALGORITHM_colfast_18n_test_MASK (0x8000000U)
#define CTI_MBIST_ALGORITHM_colfast_18n_test_SHIFT (27U)
#define CTI_MBIST_ALGORITHM_colfast_18n_test_WIDTH (1U)
#define CTI_MBIST_ALGORITHM_colfast_18n_test(x)  (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_ALGORITHM_colfast_18n_test_SHIFT)) & CTI_MBIST_ALGORITHM_colfast_18n_test_MASK)

#define CTI_MBIST_ALGORITHM_rowfast_18n_test_MASK (0x10000000U)
#define CTI_MBIST_ALGORITHM_rowfast_18n_test_SHIFT (28U)
#define CTI_MBIST_ALGORITHM_rowfast_18n_test_WIDTH (1U)
#define CTI_MBIST_ALGORITHM_rowfast_18n_test(x)  (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_ALGORITHM_rowfast_18n_test_SHIFT)) & CTI_MBIST_ALGORITHM_rowfast_18n_test_MASK)

#define CTI_MBIST_ALGORITHM_addressdecode_bg_MASK (0x20000000U)
#define CTI_MBIST_ALGORITHM_addressdecode_bg_SHIFT (29U)
#define CTI_MBIST_ALGORITHM_addressdecode_bg_WIDTH (1U)
#define CTI_MBIST_ALGORITHM_addressdecode_bg(x)  (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_ALGORITHM_addressdecode_bg_SHIFT)) & CTI_MBIST_ALGORITHM_addressdecode_bg_MASK)

#define CTI_MBIST_ALGORITHM_nwrt_test_MASK       (0x40000000U)
#define CTI_MBIST_ALGORITHM_nwrt_test_SHIFT      (30U)
#define CTI_MBIST_ALGORITHM_nwrt_test_WIDTH      (1U)
#define CTI_MBIST_ALGORITHM_nwrt_test(x)         (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_ALGORITHM_nwrt_test_SHIFT)) & CTI_MBIST_ALGORITHM_nwrt_test_MASK)

#define CTI_MBIST_ALGORITHM_burn_in_test_MASK    (0x80000000U)
#define CTI_MBIST_ALGORITHM_burn_in_test_SHIFT   (31U)
#define CTI_MBIST_ALGORITHM_burn_in_test_WIDTH   (1U)
#define CTI_MBIST_ALGORITHM_burn_in_test(x)      (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_ALGORITHM_burn_in_test_SHIFT)) & CTI_MBIST_ALGORITHM_burn_in_test_MASK)
/*! @} */

/*! @name MBIST_REPAIR_CTRL - RAMBIST Repair Control Register */
/*! @{ */

#define CTI_MBIST_REPAIR_CTRL_mbist_cp_enable_MASK (0x40000000U)
#define CTI_MBIST_REPAIR_CTRL_mbist_cp_enable_SHIFT (30U)
#define CTI_MBIST_REPAIR_CTRL_mbist_cp_enable_WIDTH (1U)
#define CTI_MBIST_REPAIR_CTRL_mbist_cp_enable(x) (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_REPAIR_CTRL_mbist_cp_enable_SHIFT)) & CTI_MBIST_REPAIR_CTRL_mbist_cp_enable_MASK)

#define CTI_MBIST_REPAIR_CTRL_mbist_fix_MASK     (0x80000000U)
#define CTI_MBIST_REPAIR_CTRL_mbist_fix_SHIFT    (31U)
#define CTI_MBIST_REPAIR_CTRL_mbist_fix_WIDTH    (1U)
#define CTI_MBIST_REPAIR_CTRL_mbist_fix(x)       (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_REPAIR_CTRL_mbist_fix_SHIFT)) & CTI_MBIST_REPAIR_CTRL_mbist_fix_MASK)
/*! @} */

/*! @name MBIST_REPAIR_STATUS - RAMBIST REPAIR STATUS Register */
/*! @{ */

#define CTI_MBIST_REPAIR_STATUS_repair_data_force_MASK (0x40000000U)
#define CTI_MBIST_REPAIR_STATUS_repair_data_force_SHIFT (30U)
#define CTI_MBIST_REPAIR_STATUS_repair_data_force_WIDTH (1U)
#define CTI_MBIST_REPAIR_STATUS_repair_data_force(x) (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_REPAIR_STATUS_repair_data_force_SHIFT)) & CTI_MBIST_REPAIR_STATUS_repair_data_force_MASK)

#define CTI_MBIST_REPAIR_STATUS_mbist_repairable_MASK (0x80000000U)
#define CTI_MBIST_REPAIR_STATUS_mbist_repairable_SHIFT (31U)
#define CTI_MBIST_REPAIR_STATUS_mbist_repairable_WIDTH (1U)
#define CTI_MBIST_REPAIR_STATUS_mbist_repairable(x) (((uint32_t)(((uint32_t)(x)) << CTI_MBIST_REPAIR_STATUS_mbist_repairable_SHIFT)) & CTI_MBIST_REPAIR_STATUS_mbist_repairable_MASK)
/*! @} */

/*! @name RAMLOADER_START_ADR - RAMLOADER START ADDRESS Register */
/*! @{ */

#define CTI_RAMLOADER_START_ADR_start_addr_ld_en_NVM_MASK (0x4000U)
#define CTI_RAMLOADER_START_ADR_start_addr_ld_en_NVM_SHIFT (14U)
#define CTI_RAMLOADER_START_ADR_start_addr_ld_en_NVM_WIDTH (1U)
#define CTI_RAMLOADER_START_ADR_start_addr_ld_en_NVM(x) (((uint32_t)(((uint32_t)(x)) << CTI_RAMLOADER_START_ADR_start_addr_ld_en_NVM_SHIFT)) & CTI_RAMLOADER_START_ADR_start_addr_ld_en_NVM_MASK)

#define CTI_RAMLOADER_START_ADR_start_addr_ld_en_sys_MASK (0x8000U)
#define CTI_RAMLOADER_START_ADR_start_addr_ld_en_sys_SHIFT (15U)
#define CTI_RAMLOADER_START_ADR_start_addr_ld_en_sys_WIDTH (1U)
#define CTI_RAMLOADER_START_ADR_start_addr_ld_en_sys(x) (((uint32_t)(((uint32_t)(x)) << CTI_RAMLOADER_START_ADR_start_addr_ld_en_sys_SHIFT)) & CTI_RAMLOADER_START_ADR_start_addr_ld_en_sys_MASK)

#define CTI_RAMLOADER_START_ADR_ramloader_start_adr_MASK (0xFFFF0000U)
#define CTI_RAMLOADER_START_ADR_ramloader_start_adr_SHIFT (16U)
#define CTI_RAMLOADER_START_ADR_ramloader_start_adr_WIDTH (16U)
#define CTI_RAMLOADER_START_ADR_ramloader_start_adr(x) (((uint32_t)(((uint32_t)(x)) << CTI_RAMLOADER_START_ADR_ramloader_start_adr_SHIFT)) & CTI_RAMLOADER_START_ADR_ramloader_start_adr_MASK)
/*! @} */

/*! @name CTI_MODE - CTI MODE Register */
/*! @{ */

#define CTI_CTI_MODE_cti_data4_ctrl_MASK         (0xC0U)
#define CTI_CTI_MODE_cti_data4_ctrl_SHIFT        (6U)
#define CTI_CTI_MODE_cti_data4_ctrl_WIDTH        (2U)
#define CTI_CTI_MODE_cti_data4_ctrl(x)           (((uint32_t)(((uint32_t)(x)) << CTI_CTI_MODE_cti_data4_ctrl_SHIFT)) & CTI_CTI_MODE_cti_data4_ctrl_MASK)

#define CTI_CTI_MODE_cti_data3_ctrl_MASK         (0x300U)
#define CTI_CTI_MODE_cti_data3_ctrl_SHIFT        (8U)
#define CTI_CTI_MODE_cti_data3_ctrl_WIDTH        (2U)
#define CTI_CTI_MODE_cti_data3_ctrl(x)           (((uint32_t)(((uint32_t)(x)) << CTI_CTI_MODE_cti_data3_ctrl_SHIFT)) & CTI_CTI_MODE_cti_data3_ctrl_MASK)

#define CTI_CTI_MODE_cti_data2_ctrl_MASK         (0xC00U)
#define CTI_CTI_MODE_cti_data2_ctrl_SHIFT        (10U)
#define CTI_CTI_MODE_cti_data2_ctrl_WIDTH        (2U)
#define CTI_CTI_MODE_cti_data2_ctrl(x)           (((uint32_t)(((uint32_t)(x)) << CTI_CTI_MODE_cti_data2_ctrl_SHIFT)) & CTI_CTI_MODE_cti_data2_ctrl_MASK)

#define CTI_CTI_MODE_cti_data1_ctrl_MASK         (0x3000U)
#define CTI_CTI_MODE_cti_data1_ctrl_SHIFT        (12U)
#define CTI_CTI_MODE_cti_data1_ctrl_WIDTH        (2U)
#define CTI_CTI_MODE_cti_data1_ctrl(x)           (((uint32_t)(((uint32_t)(x)) << CTI_CTI_MODE_cti_data1_ctrl_SHIFT)) & CTI_CTI_MODE_cti_data1_ctrl_MASK)

#define CTI_CTI_MODE_cti_data0_ctrl_MASK         (0xC000U)
#define CTI_CTI_MODE_cti_data0_ctrl_SHIFT        (14U)
#define CTI_CTI_MODE_cti_data0_ctrl_WIDTH        (2U)
#define CTI_CTI_MODE_cti_data0_ctrl(x)           (((uint32_t)(((uint32_t)(x)) << CTI_CTI_MODE_cti_data0_ctrl_SHIFT)) & CTI_CTI_MODE_cti_data0_ctrl_MASK)

#define CTI_CTI_MODE_cti_mode_MASK               (0xFFFF0000U)
#define CTI_CTI_MODE_cti_mode_SHIFT              (16U)
#define CTI_CTI_MODE_cti_mode_WIDTH              (16U)
#define CTI_CTI_MODE_cti_mode(x)                 (((uint32_t)(((uint32_t)(x)) << CTI_CTI_MODE_cti_mode_SHIFT)) & CTI_CTI_MODE_cti_mode_MASK)
/*! @} */

/*! @name CTI_MIX_CTRL - CTI MIX ControlRegister */
/*! @{ */

#define CTI_CTI_MIX_CTRL_tstjtag_dsel_MASK       (0x80000000U)
#define CTI_CTI_MIX_CTRL_tstjtag_dsel_SHIFT      (31U)
#define CTI_CTI_MIX_CTRL_tstjtag_dsel_WIDTH      (1U)
#define CTI_CTI_MIX_CTRL_tstjtag_dsel(x)         (((uint32_t)(((uint32_t)(x)) << CTI_CTI_MIX_CTRL_tstjtag_dsel_SHIFT)) & CTI_CTI_MIX_CTRL_tstjtag_dsel_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CTI_Register_Masks */

/*!
 * @}
 */ /* end of group CTI_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K142_CTI_H_) */
