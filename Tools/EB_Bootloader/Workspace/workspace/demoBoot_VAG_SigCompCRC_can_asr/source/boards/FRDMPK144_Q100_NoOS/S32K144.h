/* CHECK: RULE 502 OFF */
/* CHECK: RULE 203 OFF */
/* CHECK: RULE 501 OFF */
/* CHECK: RULE 505 OFF */
/* CHECK: RULE 205 OFF */

/*  MISRA-C:2004 Deviation List
 *
 *  MISRA-1) Deviated Rule: 18.4 (required)
 *   "Unions shall not be used."
 *
 *   Reason:
 *   NXP source code.
 */

/*
** ###################################################################
**     Processor:           S32K144_100
**     Reference manual:    S32K14XRM Rev. 2, 02/2017
**     Version:             rev. 2.8, 2017-03-27
**     Build:               b170328
**
**     Abstract:
**         Peripheral Access Layer for S32K144
**
**     Copyright (c) 1997 - 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2017 NXP
**     All rights reserved.
**
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-04-09) - Iulian Talpiga
**         Initial version.
**     - rev. 1.1 (2015-05-19) - Bogdan Nitu
**         Updated interrupts table
**         Removed SIM_CHIPCTL_DAC2CMP
**         Compacted PORT_PCR registers
**         Compacted PCC registers
**     - rev. 1.2 (2015-06-02) - Bogdan Nitu
**         Added 'U' suffix to all integer constants
**         Use "" instead of <> for Platform type inclusion
**         CNT register from WDOG module is RW
**     - rev. 1.3 (2015-08-05) - Iulian Talpiga
**         Synchronized with latest RDP
**         Removed OSC32 module
**         Removed reserved registers
**         Incorporated bit band acces macros
**         Switched to standard C99 data types
**         Added 'u' to constants
**         Added size defines for register arrays
**         Define peripheral instance count
**     - rev. 1.4 (2015-08-10) - Iulian Talpiga
**         Compacted TRGMUX registers
**         Defined array index offsets for PCC and TRGMUX
**         Added FPU registers
**         Group FTM channel registers
**         Added interrupt information to peripherals
**         Renamed CAN interrupts according  to the reference manual
**         Added author information to revisions
**     - rev. 1.5 (2015-09-16) - Iulian Talpiga
**         Renamed NVIC and SCB to avoid conflict
**         Compacted CAN Wake-up Message buffers
**         Added CAN embedded RAM
**         Updated interrupts: LPIT, FTFE, LPUART,ACMP
**         Corrected ADC_SC1_ADCH_WIDTH
**         Compacted PDB registers
**         Corrected CAN, FTM, and PDB count defines
**         Guarding register acces macro against redefintion
**     - rev. 1.6 (2015-09-29) - Iulian Talpiga
**         Added WATER and FIFO registers to LPUART.
**     - rev. 1.7 (2015-10-21) - Iulian Talpiga
**         Updated ADC, AIPS, CMP, LMEM, LPTMR, PMC, PORT, RCM, RTC, SCG, SIM
**         Compacted MPU and LPIT
**         Added FSL_SysTick
**         Updated doxygen documentation grouping
**         Updated interrupts: RCM
**     - rev. 1.8 (2016-01-06) - Iulian Talpiga
**         Updated DMA, compacted TCD registers
**         Updated SCG, removed SC2P - SC16P
**         Added 8 and 16 bit access to DATA register, CRC module
**     - rev. 1.9 (2016-02-15) - Iulian Talpiga
**         Updated CRC, renamed DATA union
**         Updated PMC, added CLKBIASDIS bitfield
**         Added FSL_NVIC registers to SVD
**     - rev. 2.0 (2016-04-07) - Iulian Talpiga
**         Updated support for Rev2.0 silicon (0N47T)
**         Updated ADC, AIPS, DMA, FlexIO, FTM, GPIO, LPI2C, LPIT, LPSPI, MCM, MPU, MSCM, PMC, RTC, RCM, PCC, RTC, SCG, SIM, TRGMUX and WDOG  module
**         Updated interrupts
**         Added EIM and ERM modules
**         Added EIM and ERM modules
**     - rev. 2.1 (2016-06-10) - Iulian Talpiga
**         Updated to latest RM
**         Minor changes to: CAN, EIM, LPI2C, MPU, PCC, PMC, RTC, SIM and TRGMUX
**     - rev. 2.2 (2016-08-02) - Iulian Talpiga
**         Updated to latest RM
**         Minor changes to: ADC, CAN, CRC, FTFC, LMEM, LPI2C, MCM, MSCM, PCC, RTC, SIM
**         Added CSE_PRAM
**     - rev. 2.3 (2016-09-09) - Iulian Talpiga
**         Updated to latest RM
**         Minor changes to: PCC, FSL_NVIC and FTM
**     - rev. 2.4 (2016-09-28) - Iulian Talpiga
**         Fix RAMn array size in FlexCAN
**         Fix FCSESTAT bit order
**         Added CP0CFG0, CP0CFG1,CP0CFG2 and CP0CFG3 in MSCM
**         Fixed STIR register in FSL_NVIC
**         Fixed SHPR3 and ACTLR registers in FSL_SCB
**     - rev. 2.5 (2016-11-25) - Iulian Talpiga
**         Fix FRAC bit-field in PCC module
**         Removed BITBAND_ACCESS macros
**         Added MISRA declarations
**         Updated copyright
**         Changed prefix of NVIC, SCB and SysTick to S32_
**     - rev. 2.6 (2017-01-09) - Iulian Talpiga
**         Fix interrupts for CAN, LPUART, FTFC
**     - rev. 2.7 (2017-02-22) - Iulian Talpiga
**         Update header as per rev S32K14XRM Rev. 2, 02/2017
**         Updated modules AIPS, CAN, LPI2C, LPSPI, MCM, MPU, SCG and SIM
**     - rev. 2.8 (2017-03-27) - Iulian Talpiga
**         Synchronized PCC_FlexIO on S32K Family
**
** ###################################################################
*/

/*!
 * @file S32K144.h
 * @version 2.8
 * @date 2017-03-27
 * @brief Peripheral Access Layer for S32K144
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

/* ----------------------------------------------------------------------------
   -- MCU activation
   ---------------------------------------------------------------------------- */

/* Prevention from multiple including the same memory map */
#if !defined(S32K144_H_)  /* Check if memory map has not been already included */
#define S32K144_H_
#define MCU_S32K144

/* Check if another memory map has not been also included */
#if (defined(MCU_ACTIVE))
  #error S32K144 memory map: There is already included another memory map. Only one memory map can be included.
#endif /* (defined(MCU_ACTIVE)) */
#define MCU_ACTIVE

#include <ncs.h>

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0200u
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0008u

/* ----------------------------------------------------------------------------
   -- Generic macros
   ---------------------------------------------------------------------------- */

/* IO definitions (access restrictions to peripheral registers) */
/**
*   IO Type Qualifiers are used
*   \li to specify the access to peripheral variables.
*   \li for automatic generation of peripheral register debug information.
*/
#ifndef __IO
#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions                 */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions                 */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions                */
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */
#endif


/**
* @brief 32 bits memory read macro.
*/
#if !defined(REG_READ32)
  #define REG_READ32(address)               (*(volatile uint32*)(address))
#endif

/**
* @brief 32 bits memory write macro.
*/
#if !defined(REG_WRITE32)
  #define REG_WRITE32(address, value)       ((*(volatile uint32*)(address))= (uint32)(value))
#endif

/**
* @brief 32 bits bits setting macro.
*/
#if !defined(REG_BIT_SET32)
  #define REG_BIT_SET32(address, mask)      ((*(volatile uint32*)(address))|= (uint32)(mask))
#endif

/**
* @brief 32 bits bits clearing macro.
*/
#if !defined(REG_BIT_CLEAR32)
  #define REG_BIT_CLEAR32(address, mask)    ((*(volatile uint32*)(address))&= ((uint32)~((uint32)(mask))))
#endif

/**
* @brief 32 bit clear bits and set with new value
* @note It is user's responsability to make sure that value has only "mask" bits set - (value&~mask)==0
*/
#if !defined(REG_RMW32)
  #define REG_RMW32(address, mask, value)   (REG_WRITE32((address), ((REG_READ32(address)& ((uint32)~((uint32)(mask))))| ((uint32)(value)))))
#endif



/* ----------------------------------------------------------------------------
   -- FTFC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFC_Peripheral_Access_Layer FTFC Peripheral Access Layer
 * @{
 */


/** FTFC - Size of Registers Arrays */
#define FTFC_FCCOB_COUNT                         12u
#define FTFC_FPROT_COUNT                         4u

/** FTFC - Register Layout Typedef */
typedef struct {
  __IO uint8 FSTAT;                              /**< Flash Status Register, offset: 0x0 */
  __IO uint8 FCNFG;                              /**< Flash Configuration Register, offset: 0x1 */
  __I  uint8 FSEC;                               /**< Flash Security Register, offset: 0x2 */
  __I  uint8 FOPT;                               /**< Flash Option Register, offset: 0x3 */
  __IO uint8 FCCOB[FTFC_FCCOB_COUNT];            /**< Flash Common Command Object Registers, array offset: 0x4, array step: 0x1 */
  __IO uint8 FPROT[FTFC_FPROT_COUNT];            /**< Program Flash Protection Registers, array offset: 0x10, array step: 0x1 */
       uint8 RESERVED_0[2];
  __IO uint8 FEPROT;                             /**< EEPROM Protection Register, offset: 0x16 */
  __IO uint8 FDPROT;                             /**< Data Flash Protection Register, offset: 0x17 */
       uint8 RESERVED_1[20];
  __I  uint8 FCSESTAT;                           /**< Flash CSEc Status Register, offset: 0x2C */
       uint8 RESERVED_2[1];
  __IO uint8 FERSTAT;                            /**< Flash Error Status Register, offset: 0x2E */
  __IO uint8 FERCNFG;                            /**< Flash Error Configuration Register, offset: 0x2F */
} FTFC_Type, *FTFC_MemMapPtr;

 /** Number of instances of the FTFC module. */
#define FTFC_INSTANCE_COUNT                      (1u)


/* FTFC - Peripheral instance base addresses */
/** Peripheral FTFC base address */
#define FTFC_BASE                                (0x40020000u)
/** Peripheral FTFC base pointer */
#define FTFC                                     ((FTFC_Type *)FTFC_BASE)
/** Array initializer of FTFC peripheral base addresses */
#define FTFC_BASE_ADDRS                          { FTFC_BASE }
/** Array initializer of FTFC peripheral base pointers */
#define FTFC_BASE_PTRS                           { FTFC }
 /** Number of interrupt vector arrays for the FTFC module. */
#define FTFC_IRQS_ARR_COUNT                      (2u)
 /** Number of interrupt channels for the COMMAND_COMPLETE type of FTFC module. */
#define FTFC_COMMAND_COMPLETE_IRQS_CH_COUNT      (1u)
 /** Number of interrupt channels for the READ_COLLISION type of FTFC module. */
#define FTFC_READ_COLLISION_IRQS_CH_COUNT        (1u)
/** Interrupt vectors for the FTFC peripheral type */
#define FTFC_COMMAND_COMPLETE_IRQS               { FTFC_IRQn }
#define FTFC_READ_COLLISION_IRQS                 { Read_Collision_IRQn }

/* ----------------------------------------------------------------------------
   -- FTFC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFC_Register_Masks FTFC Register Masks
 * @{
 */

/* FSTAT Bit Fields */
#define FTFC_FSTAT_MGSTAT0_MASK                  0x1u
#define FTFC_FSTAT_MGSTAT0_SHIFT                 0u
#define FTFC_FSTAT_MGSTAT0_WIDTH                 1u
#define FTFC_FSTAT_MGSTAT0(x)                    (((uint8)(((uint8)(x))<<FTFC_FSTAT_MGSTAT0_SHIFT))&FTFC_FSTAT_MGSTAT0_MASK)
#define FTFC_FSTAT_FPVIOL_MASK                   0x10u
#define FTFC_FSTAT_FPVIOL_SHIFT                  4u
#define FTFC_FSTAT_FPVIOL_WIDTH                  1u
#define FTFC_FSTAT_FPVIOL(x)                     (((uint8)(((uint8)(x))<<FTFC_FSTAT_FPVIOL_SHIFT))&FTFC_FSTAT_FPVIOL_MASK)
#define FTFC_FSTAT_ACCERR_MASK                   0x20u
#define FTFC_FSTAT_ACCERR_SHIFT                  5u
#define FTFC_FSTAT_ACCERR_WIDTH                  1u
#define FTFC_FSTAT_ACCERR(x)                     (((uint8)(((uint8)(x))<<FTFC_FSTAT_ACCERR_SHIFT))&FTFC_FSTAT_ACCERR_MASK)
#define FTFC_FSTAT_RDCOLERR_MASK                 0x40u
#define FTFC_FSTAT_RDCOLERR_SHIFT                6u
#define FTFC_FSTAT_RDCOLERR_WIDTH                1u
#define FTFC_FSTAT_RDCOLERR(x)                   (((uint8)(((uint8)(x))<<FTFC_FSTAT_RDCOLERR_SHIFT))&FTFC_FSTAT_RDCOLERR_MASK)
#define FTFC_FSTAT_CCIF_MASK                     0x80u
#define FTFC_FSTAT_CCIF_SHIFT                    7u
#define FTFC_FSTAT_CCIF_WIDTH                    1u
#define FTFC_FSTAT_CCIF(x)                       (((uint8)(((uint8)(x))<<FTFC_FSTAT_CCIF_SHIFT))&FTFC_FSTAT_CCIF_MASK)
/* FCNFG Bit Fields */
#define FTFC_FCNFG_EEERDY_MASK                   0x1u
#define FTFC_FCNFG_EEERDY_SHIFT                  0u
#define FTFC_FCNFG_EEERDY_WIDTH                  1u
#define FTFC_FCNFG_EEERDY(x)                     (((uint8)(((uint8)(x))<<FTFC_FCNFG_EEERDY_SHIFT))&FTFC_FCNFG_EEERDY_MASK)
#define FTFC_FCNFG_RAMRDY_MASK                   0x2u
#define FTFC_FCNFG_RAMRDY_SHIFT                  1u
#define FTFC_FCNFG_RAMRDY_WIDTH                  1u
#define FTFC_FCNFG_RAMRDY(x)                     (((uint8)(((uint8)(x))<<FTFC_FCNFG_RAMRDY_SHIFT))&FTFC_FCNFG_RAMRDY_MASK)
#define FTFC_FCNFG_ERSSUSP_MASK                  0x10u
#define FTFC_FCNFG_ERSSUSP_SHIFT                 4u
#define FTFC_FCNFG_ERSSUSP_WIDTH                 1u
#define FTFC_FCNFG_ERSSUSP(x)                    (((uint8)(((uint8)(x))<<FTFC_FCNFG_ERSSUSP_SHIFT))&FTFC_FCNFG_ERSSUSP_MASK)
#define FTFC_FCNFG_ERSAREQ_MASK                  0x20u
#define FTFC_FCNFG_ERSAREQ_SHIFT                 5u
#define FTFC_FCNFG_ERSAREQ_WIDTH                 1u
#define FTFC_FCNFG_ERSAREQ(x)                    (((uint8)(((uint8)(x))<<FTFC_FCNFG_ERSAREQ_SHIFT))&FTFC_FCNFG_ERSAREQ_MASK)
#define FTFC_FCNFG_RDCOLLIE_MASK                 0x40u
#define FTFC_FCNFG_RDCOLLIE_SHIFT                6u
#define FTFC_FCNFG_RDCOLLIE_WIDTH                1u
#define FTFC_FCNFG_RDCOLLIE(x)                   (((uint8)(((uint8)(x))<<FTFC_FCNFG_RDCOLLIE_SHIFT))&FTFC_FCNFG_RDCOLLIE_MASK)
#define FTFC_FCNFG_CCIE_MASK                     0x80u
#define FTFC_FCNFG_CCIE_SHIFT                    7u
#define FTFC_FCNFG_CCIE_WIDTH                    1u
#define FTFC_FCNFG_CCIE(x)                       (((uint8)(((uint8)(x))<<FTFC_FCNFG_CCIE_SHIFT))&FTFC_FCNFG_CCIE_MASK)
/* FSEC Bit Fields */
#define FTFC_FSEC_SEC_MASK                       0x3u
#define FTFC_FSEC_SEC_SHIFT                      0u
#define FTFC_FSEC_SEC_WIDTH                      2u
#define FTFC_FSEC_SEC(x)                         (((uint8)(((uint8)(x))<<FTFC_FSEC_SEC_SHIFT))&FTFC_FSEC_SEC_MASK)
#define FTFC_FSEC_FSLACC_MASK                    0xCu
#define FTFC_FSEC_FSLACC_SHIFT                   2u
#define FTFC_FSEC_FSLACC_WIDTH                   2u
#define FTFC_FSEC_FSLACC(x)                      (((uint8)(((uint8)(x))<<FTFC_FSEC_FSLACC_SHIFT))&FTFC_FSEC_FSLACC_MASK)
#define FTFC_FSEC_MEEN_MASK                      0x30u
#define FTFC_FSEC_MEEN_SHIFT                     4u
#define FTFC_FSEC_MEEN_WIDTH                     2u
#define FTFC_FSEC_MEEN(x)                        (((uint8)(((uint8)(x))<<FTFC_FSEC_MEEN_SHIFT))&FTFC_FSEC_MEEN_MASK)
#define FTFC_FSEC_KEYEN_MASK                     0xC0u
#define FTFC_FSEC_KEYEN_SHIFT                    6u
#define FTFC_FSEC_KEYEN_WIDTH                    2u
#define FTFC_FSEC_KEYEN(x)                       (((uint8)(((uint8)(x))<<FTFC_FSEC_KEYEN_SHIFT))&FTFC_FSEC_KEYEN_MASK)
/* FOPT Bit Fields */
#define FTFC_FOPT_OPT_MASK                       0xFFu
#define FTFC_FOPT_OPT_SHIFT                      0u
#define FTFC_FOPT_OPT_WIDTH                      8u
#define FTFC_FOPT_OPT(x)                         (((uint8)(((uint8)(x))<<FTFC_FOPT_OPT_SHIFT))&FTFC_FOPT_OPT_MASK)
/* FCCOB Bit Fields */
#define FTFC_FCCOB_CCOBn_MASK                    0xFFu
#define FTFC_FCCOB_CCOBn_SHIFT                   0u
#define FTFC_FCCOB_CCOBn_WIDTH                   8u
#define FTFC_FCCOB_CCOBn(x)                      (((uint8)(((uint8)(x))<<FTFC_FCCOB_CCOBn_SHIFT))&FTFC_FCCOB_CCOBn_MASK)
/* FPROT Bit Fields */
#define FTFC_FPROT_PROT_MASK                     0xFFu
#define FTFC_FPROT_PROT_SHIFT                    0u
#define FTFC_FPROT_PROT_WIDTH                    8u
#define FTFC_FPROT_PROT(x)                       (((uint8)(((uint8)(x))<<FTFC_FPROT_PROT_SHIFT))&FTFC_FPROT_PROT_MASK)
/* FEPROT Bit Fields */
#define FTFC_FEPROT_EPROT_MASK                   0xFFu
#define FTFC_FEPROT_EPROT_SHIFT                  0u
#define FTFC_FEPROT_EPROT_WIDTH                  8u
#define FTFC_FEPROT_EPROT(x)                     (((uint8)(((uint8)(x))<<FTFC_FEPROT_EPROT_SHIFT))&FTFC_FEPROT_EPROT_MASK)
/* FDPROT Bit Fields */
#define FTFC_FDPROT_DPROT_MASK                   0xFFu
#define FTFC_FDPROT_DPROT_SHIFT                  0u
#define FTFC_FDPROT_DPROT_WIDTH                  8u
#define FTFC_FDPROT_DPROT(x)                     (((uint8)(((uint8)(x))<<FTFC_FDPROT_DPROT_SHIFT))&FTFC_FDPROT_DPROT_MASK)
/* FCSESTAT Bit Fields */
#define FTFC_FCSESTAT_BSY_MASK                   0x1u
#define FTFC_FCSESTAT_BSY_SHIFT                  0u
#define FTFC_FCSESTAT_BSY_WIDTH                  1u
#define FTFC_FCSESTAT_BSY(x)                     (((uint8)(((uint8)(x))<<FTFC_FCSESTAT_BSY_SHIFT))&FTFC_FCSESTAT_BSY_MASK)
#define FTFC_FCSESTAT_SB_MASK                    0x2u
#define FTFC_FCSESTAT_SB_SHIFT                   1u
#define FTFC_FCSESTAT_SB_WIDTH                   1u
#define FTFC_FCSESTAT_SB(x)                      (((uint8)(((uint8)(x))<<FTFC_FCSESTAT_SB_SHIFT))&FTFC_FCSESTAT_SB_MASK)
#define FTFC_FCSESTAT_BIN_MASK                   0x4u
#define FTFC_FCSESTAT_BIN_SHIFT                  2u
#define FTFC_FCSESTAT_BIN_WIDTH                  1u
#define FTFC_FCSESTAT_BIN(x)                     (((uint8)(((uint8)(x))<<FTFC_FCSESTAT_BIN_SHIFT))&FTFC_FCSESTAT_BIN_MASK)
#define FTFC_FCSESTAT_BFN_MASK                   0x8u
#define FTFC_FCSESTAT_BFN_SHIFT                  3u
#define FTFC_FCSESTAT_BFN_WIDTH                  1u
#define FTFC_FCSESTAT_BFN(x)                     (((uint8)(((uint8)(x))<<FTFC_FCSESTAT_BFN_SHIFT))&FTFC_FCSESTAT_BFN_MASK)
#define FTFC_FCSESTAT_BOK_MASK                   0x10u
#define FTFC_FCSESTAT_BOK_SHIFT                  4u
#define FTFC_FCSESTAT_BOK_WIDTH                  1u
#define FTFC_FCSESTAT_BOK(x)                     (((uint8)(((uint8)(x))<<FTFC_FCSESTAT_BOK_SHIFT))&FTFC_FCSESTAT_BOK_MASK)
#define FTFC_FCSESTAT_RIN_MASK                   0x20u
#define FTFC_FCSESTAT_RIN_SHIFT                  5u
#define FTFC_FCSESTAT_RIN_WIDTH                  1u
#define FTFC_FCSESTAT_RIN(x)                     (((uint8)(((uint8)(x))<<FTFC_FCSESTAT_RIN_SHIFT))&FTFC_FCSESTAT_RIN_MASK)
#define FTFC_FCSESTAT_EDB_MASK                   0x40u
#define FTFC_FCSESTAT_EDB_SHIFT                  6u
#define FTFC_FCSESTAT_EDB_WIDTH                  1u
#define FTFC_FCSESTAT_EDB(x)                     (((uint8)(((uint8)(x))<<FTFC_FCSESTAT_EDB_SHIFT))&FTFC_FCSESTAT_EDB_MASK)
#define FTFC_FCSESTAT_IDB_MASK                   0x80u
#define FTFC_FCSESTAT_IDB_SHIFT                  7u
#define FTFC_FCSESTAT_IDB_WIDTH                  1u
#define FTFC_FCSESTAT_IDB(x)                     (((uint8)(((uint8)(x))<<FTFC_FCSESTAT_IDB_SHIFT))&FTFC_FCSESTAT_IDB_MASK)
/* FERSTAT Bit Fields */
#define FTFC_FERSTAT_DFDIF_MASK                  0x2u
#define FTFC_FERSTAT_DFDIF_SHIFT                 1u
#define FTFC_FERSTAT_DFDIF_WIDTH                 1u
#define FTFC_FERSTAT_DFDIF(x)                    (((uint8)(((uint8)(x))<<FTFC_FERSTAT_DFDIF_SHIFT))&FTFC_FERSTAT_DFDIF_MASK)
/* FERCNFG Bit Fields */
#define FTFC_FERCNFG_DFDIE_MASK                  0x2u
#define FTFC_FERCNFG_DFDIE_SHIFT                 1u
#define FTFC_FERCNFG_DFDIE_WIDTH                 1u
#define FTFC_FERCNFG_DFDIE(x)                    (((uint8)(((uint8)(x))<<FTFC_FERCNFG_DFDIE_SHIFT))&FTFC_FERCNFG_DFDIE_MASK)
#define FTFC_FERCNFG_FDFD_MASK                   0x20u
#define FTFC_FERCNFG_FDFD_SHIFT                  5u
#define FTFC_FERCNFG_FDFD_WIDTH                  1u
#define FTFC_FERCNFG_FDFD(x)                     (((uint8)(((uint8)(x))<<FTFC_FERCNFG_FDFD_SHIFT))&FTFC_FERCNFG_FDFD_MASK)

/*!
 * @}
 */ /* end of group FTFC_Register_Masks */


/*!
 * @}
 */ /* end of group FTFC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- FTM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Peripheral_Access_Layer FTM Peripheral Access Layer
 * @{
 */


/** FTM - Size of Registers Arrays */
#define FTM_CONTROLS_COUNT                       8u

/** FTM - Register Layout Typedef */
typedef struct {
  __IO uint32 SC;                                /**< Status And Control, offset: 0x0 */
  __IO uint32 CNT;                               /**< Counter, offset: 0x4 */
  __IO uint32 MOD;                               /**< Modulo, offset: 0x8 */
  struct {                                         /* offset: 0xC, array step: 0x8 */
    __IO uint32 CnSC;                              /**< Channel (n) Status And Control, array offset: 0xC, array step: 0x8 */
    __IO uint32 CnV;                               /**< Channel (n) Value, array offset: 0x10, array step: 0x8 */
  } CONTROLS[FTM_CONTROLS_COUNT];
  __IO uint32 CNTIN;                             /**< Counter Initial Value, offset: 0x4C */
  __IO uint32 STATUS;                            /**< Capture And Compare Status, offset: 0x50 */
  __IO uint32 MODE;                              /**< Features Mode Selection, offset: 0x54 */
  __IO uint32 SYNC;                              /**< Synchronization, offset: 0x58 */
  __IO uint32 OUTINIT;                           /**< Initial State For Channels Output, offset: 0x5C */
  __IO uint32 OUTMASK;                           /**< Output Mask, offset: 0x60 */
  __IO uint32 COMBINE;                           /**< Function For Linked Channels, offset: 0x64 */
  __IO uint32 DEADTIME;                          /**< Deadtime Configuration, offset: 0x68 */
  __IO uint32 EXTTRIG;                           /**< FTM External Trigger, offset: 0x6C */
  __IO uint32 POL;                               /**< Channels Polarity, offset: 0x70 */
  __IO uint32 FMS;                               /**< Fault Mode Status, offset: 0x74 */
  __IO uint32 FILTER;                            /**< Input Capture Filter Control, offset: 0x78 */
  __IO uint32 FLTCTRL;                           /**< Fault Control, offset: 0x7C */
  __IO uint32 QDCTRL;                            /**< Quadrature Decoder Control And Status, offset: 0x80 */
  __IO uint32 CONF;                              /**< Configuration, offset: 0x84 */
  __IO uint32 FLTPOL;                            /**< FTM Fault Input Polarity, offset: 0x88 */
  __IO uint32 SYNCONF;                           /**< Synchronization Configuration, offset: 0x8C */
  __IO uint32 INVCTRL;                           /**< FTM Inverting Control, offset: 0x90 */
  __IO uint32 SWOCTRL;                           /**< FTM Software Output Control, offset: 0x94 */
  __IO uint32 PWMLOAD;                           /**< FTM PWM Load, offset: 0x98 */
  __IO uint32 HCR;                               /**< Half Cycle Register, offset: 0x9C */
  __IO uint32 PAIR0DEADTIME;                     /**< Pair 0 Deadtime Configuration, offset: 0xA0 */
       uint8 RESERVED_0[4];
  __IO uint32 PAIR1DEADTIME;                     /**< Pair 1 Deadtime Configuration, offset: 0xA8 */
       uint8 RESERVED_1[4];
  __IO uint32 PAIR2DEADTIME;                     /**< Pair 2 Deadtime Configuration, offset: 0xB0 */
       uint8 RESERVED_2[4];
  __IO uint32 PAIR3DEADTIME;                     /**< Pair 3 Deadtime Configuration, offset: 0xB8 */
} FTM_Type, *FTM_MemMapPtr;

 /** Number of instances of the FTM module. */
#define FTM_INSTANCE_COUNT                       (4u)


/* FTM - Peripheral instance base addresses */
/** Peripheral FTM0 base address */
#define FTM0_BASE                                (0x40038000u)
/** Peripheral FTM0 base pointer */
#define FTM0                                     ((FTM_Type *)FTM0_BASE)
/** Peripheral FTM1 base address */
#define FTM1_BASE                                (0x40039000u)
/** Peripheral FTM1 base pointer */
#define FTM1                                     ((FTM_Type *)FTM1_BASE)
/** Peripheral FTM2 base address */
#define FTM2_BASE                                (0x4003A000u)
/** Peripheral FTM2 base pointer */
#define FTM2                                     ((FTM_Type *)FTM2_BASE)
/** Peripheral FTM3 base address */
#define FTM3_BASE                                (0x40026000u)
/** Peripheral FTM3 base pointer */
#define FTM3                                     ((FTM_Type *)FTM3_BASE)
/** Array initializer of FTM peripheral base addresses */
#define FTM_BASE_ADDRS                           { FTM0_BASE, FTM1_BASE, FTM2_BASE, FTM3_BASE }
/** Array initializer of FTM peripheral base pointers */
#define FTM_BASE_PTRS                            { FTM0, FTM1, FTM2, FTM3 }
 /** Number of interrupt vector arrays for the FTM module. */
#define FTM_IRQS_ARR_COUNT                       (4u)
 /** Number of interrupt channels for the FTM module. */
#define FTM_IRQS_CH_COUNT                        (8u)
 /** Number of interrupt channels for the Fault type of FTM module. */
#define FTM_Fault_IRQS_CH_COUNT                  (1u)
 /** Number of interrupt channels for the Overflow type of FTM module. */
#define FTM_Overflow_IRQS_CH_COUNT               (1u)
 /** Number of interrupt channels for the Reload type of FTM module. */
#define FTM_Reload_IRQS_CH_COUNT                 (1u)
/** Interrupt vectors for the FTM peripheral type */
#define FTM_IRQS                                 { { FTM0_Ch0_Ch1_IRQn, FTM0_Ch0_Ch1_IRQn, FTM0_Ch2_Ch3_IRQn, FTM0_Ch2_Ch3_IRQn, FTM0_Ch4_Ch5_IRQn, FTM0_Ch4_Ch5_IRQn, FTM0_Ch6_Ch7_IRQn, FTM0_Ch6_Ch7_IRQn }, \
                                                   { FTM1_Ch0_Ch1_IRQn, FTM1_Ch0_Ch1_IRQn, FTM1_Ch2_Ch3_IRQn, FTM1_Ch2_Ch3_IRQn, FTM1_Ch4_Ch5_IRQn, FTM1_Ch4_Ch5_IRQn, FTM1_Ch6_Ch7_IRQn, FTM1_Ch6_Ch7_IRQn }, \
                                                   { FTM2_Ch0_Ch1_IRQn, FTM2_Ch0_Ch1_IRQn, FTM2_Ch2_Ch3_IRQn, FTM2_Ch2_Ch3_IRQn, FTM2_Ch4_Ch5_IRQn, FTM2_Ch4_Ch5_IRQn, FTM2_Ch6_Ch7_IRQn, FTM2_Ch6_Ch7_IRQn }, \
                                                   { FTM3_Ch0_Ch1_IRQn, FTM3_Ch0_Ch1_IRQn, FTM3_Ch2_Ch3_IRQn, FTM3_Ch2_Ch3_IRQn, FTM3_Ch4_Ch5_IRQn, FTM3_Ch4_Ch5_IRQn, FTM3_Ch6_Ch7_IRQn, FTM3_Ch6_Ch7_IRQn } }
#define FTM_Fault_IRQS                           { FTM0_Fault_IRQn, FTM1_Fault_IRQn, FTM2_Fault_IRQn, FTM3_Fault_IRQn }
#define FTM_Overflow_IRQS                        { FTM0_Ovf_Reload_IRQn, FTM1_Ovf_Reload_IRQn, FTM2_Ovf_Reload_IRQn, FTM3_Ovf_Reload_IRQn }
#define FTM_Reload_IRQS                          { FTM0_Ovf_Reload_IRQn, FTM1_Ovf_Reload_IRQn, FTM2_Ovf_Reload_IRQn, FTM3_Ovf_Reload_IRQn }

/* ----------------------------------------------------------------------------
   -- FTM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Register_Masks FTM Register Masks
 * @{
 */

/* SC Bit Fields */
#define FTM_SC_PS_MASK                           0x7u
#define FTM_SC_PS_SHIFT                          0u
#define FTM_SC_PS_WIDTH                          3u
#define FTM_SC_PS(x)                             (((uint32)(((uint32)(x))<<FTM_SC_PS_SHIFT))&FTM_SC_PS_MASK)
#define FTM_SC_CLKS_MASK                         0x18u
#define FTM_SC_CLKS_SHIFT                        3u
#define FTM_SC_CLKS_WIDTH                        2u
#define FTM_SC_CLKS(x)                           (((uint32)(((uint32)(x))<<FTM_SC_CLKS_SHIFT))&FTM_SC_CLKS_MASK)
#define FTM_SC_CPWMS_MASK                        0x20u
#define FTM_SC_CPWMS_SHIFT                       5u
#define FTM_SC_CPWMS_WIDTH                       1u
#define FTM_SC_CPWMS(x)                          (((uint32)(((uint32)(x))<<FTM_SC_CPWMS_SHIFT))&FTM_SC_CPWMS_MASK)
#define FTM_SC_RIE_MASK                          0x40u
#define FTM_SC_RIE_SHIFT                         6u
#define FTM_SC_RIE_WIDTH                         1u
#define FTM_SC_RIE(x)                            (((uint32)(((uint32)(x))<<FTM_SC_RIE_SHIFT))&FTM_SC_RIE_MASK)
#define FTM_SC_RF_MASK                           0x80u
#define FTM_SC_RF_SHIFT                          7u
#define FTM_SC_RF_WIDTH                          1u
#define FTM_SC_RF(x)                             (((uint32)(((uint32)(x))<<FTM_SC_RF_SHIFT))&FTM_SC_RF_MASK)
#define FTM_SC_TOIE_MASK                         0x100u
#define FTM_SC_TOIE_SHIFT                        8u
#define FTM_SC_TOIE_WIDTH                        1u
#define FTM_SC_TOIE(x)                           (((uint32)(((uint32)(x))<<FTM_SC_TOIE_SHIFT))&FTM_SC_TOIE_MASK)
#define FTM_SC_TOF_MASK                          0x200u
#define FTM_SC_TOF_SHIFT                         9u
#define FTM_SC_TOF_WIDTH                         1u
#define FTM_SC_TOF(x)                            (((uint32)(((uint32)(x))<<FTM_SC_TOF_SHIFT))&FTM_SC_TOF_MASK)
#define FTM_SC_PWMEN0_MASK                       0x10000u
#define FTM_SC_PWMEN0_SHIFT                      16u
#define FTM_SC_PWMEN0_WIDTH                      1u
#define FTM_SC_PWMEN0(x)                         (((uint32)(((uint32)(x))<<FTM_SC_PWMEN0_SHIFT))&FTM_SC_PWMEN0_MASK)
#define FTM_SC_PWMEN1_MASK                       0x20000u
#define FTM_SC_PWMEN1_SHIFT                      17u
#define FTM_SC_PWMEN1_WIDTH                      1u
#define FTM_SC_PWMEN1(x)                         (((uint32)(((uint32)(x))<<FTM_SC_PWMEN1_SHIFT))&FTM_SC_PWMEN1_MASK)
#define FTM_SC_PWMEN2_MASK                       0x40000u
#define FTM_SC_PWMEN2_SHIFT                      18u
#define FTM_SC_PWMEN2_WIDTH                      1u
#define FTM_SC_PWMEN2(x)                         (((uint32)(((uint32)(x))<<FTM_SC_PWMEN2_SHIFT))&FTM_SC_PWMEN2_MASK)
#define FTM_SC_PWMEN3_MASK                       0x80000u
#define FTM_SC_PWMEN3_SHIFT                      19u
#define FTM_SC_PWMEN3_WIDTH                      1u
#define FTM_SC_PWMEN3(x)                         (((uint32)(((uint32)(x))<<FTM_SC_PWMEN3_SHIFT))&FTM_SC_PWMEN3_MASK)
#define FTM_SC_PWMEN4_MASK                       0x100000u
#define FTM_SC_PWMEN4_SHIFT                      20u
#define FTM_SC_PWMEN4_WIDTH                      1u
#define FTM_SC_PWMEN4(x)                         (((uint32)(((uint32)(x))<<FTM_SC_PWMEN4_SHIFT))&FTM_SC_PWMEN4_MASK)
#define FTM_SC_PWMEN5_MASK                       0x200000u
#define FTM_SC_PWMEN5_SHIFT                      21u
#define FTM_SC_PWMEN5_WIDTH                      1u
#define FTM_SC_PWMEN5(x)                         (((uint32)(((uint32)(x))<<FTM_SC_PWMEN5_SHIFT))&FTM_SC_PWMEN5_MASK)
#define FTM_SC_PWMEN6_MASK                       0x400000u
#define FTM_SC_PWMEN6_SHIFT                      22u
#define FTM_SC_PWMEN6_WIDTH                      1u
#define FTM_SC_PWMEN6(x)                         (((uint32)(((uint32)(x))<<FTM_SC_PWMEN6_SHIFT))&FTM_SC_PWMEN6_MASK)
#define FTM_SC_PWMEN7_MASK                       0x800000u
#define FTM_SC_PWMEN7_SHIFT                      23u
#define FTM_SC_PWMEN7_WIDTH                      1u
#define FTM_SC_PWMEN7(x)                         (((uint32)(((uint32)(x))<<FTM_SC_PWMEN7_SHIFT))&FTM_SC_PWMEN7_MASK)
#define FTM_SC_FLTPS_MASK                        0xF000000u
#define FTM_SC_FLTPS_SHIFT                       24u
#define FTM_SC_FLTPS_WIDTH                       4u
#define FTM_SC_FLTPS(x)                          (((uint32)(((uint32)(x))<<FTM_SC_FLTPS_SHIFT))&FTM_SC_FLTPS_MASK)
/* CNT Bit Fields */
#define FTM_CNT_COUNT_MASK                       0xFFFFu
#define FTM_CNT_COUNT_SHIFT                      0u
#define FTM_CNT_COUNT_WIDTH                      16u
#define FTM_CNT_COUNT(x)                         (((uint32)(((uint32)(x))<<FTM_CNT_COUNT_SHIFT))&FTM_CNT_COUNT_MASK)
/* MOD Bit Fields */
#define FTM_MOD_MOD_MASK                         0xFFFFu
#define FTM_MOD_MOD_SHIFT                        0u
#define FTM_MOD_MOD_WIDTH                        16u
#define FTM_MOD_MOD(x)                           (((uint32)(((uint32)(x))<<FTM_MOD_MOD_SHIFT))&FTM_MOD_MOD_MASK)
/* CnSC Bit Fields */
#define FTM_CnSC_DMA_MASK                        0x1u
#define FTM_CnSC_DMA_SHIFT                       0u
#define FTM_CnSC_DMA_WIDTH                       1u
#define FTM_CnSC_DMA(x)                          (((uint32)(((uint32)(x))<<FTM_CnSC_DMA_SHIFT))&FTM_CnSC_DMA_MASK)
#define FTM_CnSC_ICRST_MASK                      0x2u
#define FTM_CnSC_ICRST_SHIFT                     1u
#define FTM_CnSC_ICRST_WIDTH                     1u
#define FTM_CnSC_ICRST(x)                        (((uint32)(((uint32)(x))<<FTM_CnSC_ICRST_SHIFT))&FTM_CnSC_ICRST_MASK)
#define FTM_CnSC_ELSA_MASK                       0x4u
#define FTM_CnSC_ELSA_SHIFT                      2u
#define FTM_CnSC_ELSA_WIDTH                      1u
#define FTM_CnSC_ELSA(x)                         (((uint32)(((uint32)(x))<<FTM_CnSC_ELSA_SHIFT))&FTM_CnSC_ELSA_MASK)
#define FTM_CnSC_ELSB_MASK                       0x8u
#define FTM_CnSC_ELSB_SHIFT                      3u
#define FTM_CnSC_ELSB_WIDTH                      1u
#define FTM_CnSC_ELSB(x)                         (((uint32)(((uint32)(x))<<FTM_CnSC_ELSB_SHIFT))&FTM_CnSC_ELSB_MASK)
#define FTM_CnSC_MSA_MASK                        0x10u
#define FTM_CnSC_MSA_SHIFT                       4u
#define FTM_CnSC_MSA_WIDTH                       1u
#define FTM_CnSC_MSA(x)                          (((uint32)(((uint32)(x))<<FTM_CnSC_MSA_SHIFT))&FTM_CnSC_MSA_MASK)
#define FTM_CnSC_MSB_MASK                        0x20u
#define FTM_CnSC_MSB_SHIFT                       5u
#define FTM_CnSC_MSB_WIDTH                       1u
#define FTM_CnSC_MSB(x)                          (((uint32)(((uint32)(x))<<FTM_CnSC_MSB_SHIFT))&FTM_CnSC_MSB_MASK)
#define FTM_CnSC_CHIE_MASK                       0x40u
#define FTM_CnSC_CHIE_SHIFT                      6u
#define FTM_CnSC_CHIE_WIDTH                      1u
#define FTM_CnSC_CHIE(x)                         (((uint32)(((uint32)(x))<<FTM_CnSC_CHIE_SHIFT))&FTM_CnSC_CHIE_MASK)
#define FTM_CnSC_CHF_MASK                        0x80u
#define FTM_CnSC_CHF_SHIFT                       7u
#define FTM_CnSC_CHF_WIDTH                       1u
#define FTM_CnSC_CHF(x)                          (((uint32)(((uint32)(x))<<FTM_CnSC_CHF_SHIFT))&FTM_CnSC_CHF_MASK)
#define FTM_CnSC_TRIGMODE_MASK                   0x100u
#define FTM_CnSC_TRIGMODE_SHIFT                  8u
#define FTM_CnSC_TRIGMODE_WIDTH                  1u
#define FTM_CnSC_TRIGMODE(x)                     (((uint32)(((uint32)(x))<<FTM_CnSC_TRIGMODE_SHIFT))&FTM_CnSC_TRIGMODE_MASK)
#define FTM_CnSC_CHIS_MASK                       0x200u
#define FTM_CnSC_CHIS_SHIFT                      9u
#define FTM_CnSC_CHIS_WIDTH                      1u
#define FTM_CnSC_CHIS(x)                         (((uint32)(((uint32)(x))<<FTM_CnSC_CHIS_SHIFT))&FTM_CnSC_CHIS_MASK)
#define FTM_CnSC_CHOV_MASK                       0x400u
#define FTM_CnSC_CHOV_SHIFT                      10u
#define FTM_CnSC_CHOV_WIDTH                      1u
#define FTM_CnSC_CHOV(x)                         (((uint32)(((uint32)(x))<<FTM_CnSC_CHOV_SHIFT))&FTM_CnSC_CHOV_MASK)
/* CnV Bit Fields */
#define FTM_CnV_VAL_MASK                         0xFFFFu
#define FTM_CnV_VAL_SHIFT                        0u
#define FTM_CnV_VAL_WIDTH                        16u
#define FTM_CnV_VAL(x)                           (((uint32)(((uint32)(x))<<FTM_CnV_VAL_SHIFT))&FTM_CnV_VAL_MASK)
/* CNTIN Bit Fields */
#define FTM_CNTIN_INIT_MASK                      0xFFFFu
#define FTM_CNTIN_INIT_SHIFT                     0u
#define FTM_CNTIN_INIT_WIDTH                     16u
#define FTM_CNTIN_INIT(x)                        (((uint32)(((uint32)(x))<<FTM_CNTIN_INIT_SHIFT))&FTM_CNTIN_INIT_MASK)
/* STATUS Bit Fields */
#define FTM_STATUS_CH0F_MASK                     0x1u
#define FTM_STATUS_CH0F_SHIFT                    0u
#define FTM_STATUS_CH0F_WIDTH                    1u
#define FTM_STATUS_CH0F(x)                       (((uint32)(((uint32)(x))<<FTM_STATUS_CH0F_SHIFT))&FTM_STATUS_CH0F_MASK)
#define FTM_STATUS_CH1F_MASK                     0x2u
#define FTM_STATUS_CH1F_SHIFT                    1u
#define FTM_STATUS_CH1F_WIDTH                    1u
#define FTM_STATUS_CH1F(x)                       (((uint32)(((uint32)(x))<<FTM_STATUS_CH1F_SHIFT))&FTM_STATUS_CH1F_MASK)
#define FTM_STATUS_CH2F_MASK                     0x4u
#define FTM_STATUS_CH2F_SHIFT                    2u
#define FTM_STATUS_CH2F_WIDTH                    1u
#define FTM_STATUS_CH2F(x)                       (((uint32)(((uint32)(x))<<FTM_STATUS_CH2F_SHIFT))&FTM_STATUS_CH2F_MASK)
#define FTM_STATUS_CH3F_MASK                     0x8u
#define FTM_STATUS_CH3F_SHIFT                    3u
#define FTM_STATUS_CH3F_WIDTH                    1u
#define FTM_STATUS_CH3F(x)                       (((uint32)(((uint32)(x))<<FTM_STATUS_CH3F_SHIFT))&FTM_STATUS_CH3F_MASK)
#define FTM_STATUS_CH4F_MASK                     0x10u
#define FTM_STATUS_CH4F_SHIFT                    4u
#define FTM_STATUS_CH4F_WIDTH                    1u
#define FTM_STATUS_CH4F(x)                       (((uint32)(((uint32)(x))<<FTM_STATUS_CH4F_SHIFT))&FTM_STATUS_CH4F_MASK)
#define FTM_STATUS_CH5F_MASK                     0x20u
#define FTM_STATUS_CH5F_SHIFT                    5u
#define FTM_STATUS_CH5F_WIDTH                    1u
#define FTM_STATUS_CH5F(x)                       (((uint32)(((uint32)(x))<<FTM_STATUS_CH5F_SHIFT))&FTM_STATUS_CH5F_MASK)
#define FTM_STATUS_CH6F_MASK                     0x40u
#define FTM_STATUS_CH6F_SHIFT                    6u
#define FTM_STATUS_CH6F_WIDTH                    1u
#define FTM_STATUS_CH6F(x)                       (((uint32)(((uint32)(x))<<FTM_STATUS_CH6F_SHIFT))&FTM_STATUS_CH6F_MASK)
#define FTM_STATUS_CH7F_MASK                     0x80u
#define FTM_STATUS_CH7F_SHIFT                    7u
#define FTM_STATUS_CH7F_WIDTH                    1u
#define FTM_STATUS_CH7F(x)                       (((uint32)(((uint32)(x))<<FTM_STATUS_CH7F_SHIFT))&FTM_STATUS_CH7F_MASK)
/* MODE Bit Fields */
#define FTM_MODE_FTMEN_MASK                      0x1u
#define FTM_MODE_FTMEN_SHIFT                     0u
#define FTM_MODE_FTMEN_WIDTH                     1u
#define FTM_MODE_FTMEN(x)                        (((uint32)(((uint32)(x))<<FTM_MODE_FTMEN_SHIFT))&FTM_MODE_FTMEN_MASK)
#define FTM_MODE_INIT_MASK                       0x2u
#define FTM_MODE_INIT_SHIFT                      1u
#define FTM_MODE_INIT_WIDTH                      1u
#define FTM_MODE_INIT(x)                         (((uint32)(((uint32)(x))<<FTM_MODE_INIT_SHIFT))&FTM_MODE_INIT_MASK)
#define FTM_MODE_WPDIS_MASK                      0x4u
#define FTM_MODE_WPDIS_SHIFT                     2u
#define FTM_MODE_WPDIS_WIDTH                     1u
#define FTM_MODE_WPDIS(x)                        (((uint32)(((uint32)(x))<<FTM_MODE_WPDIS_SHIFT))&FTM_MODE_WPDIS_MASK)
#define FTM_MODE_PWMSYNC_MASK                    0x8u
#define FTM_MODE_PWMSYNC_SHIFT                   3u
#define FTM_MODE_PWMSYNC_WIDTH                   1u
#define FTM_MODE_PWMSYNC(x)                      (((uint32)(((uint32)(x))<<FTM_MODE_PWMSYNC_SHIFT))&FTM_MODE_PWMSYNC_MASK)
#define FTM_MODE_CAPTEST_MASK                    0x10u
#define FTM_MODE_CAPTEST_SHIFT                   4u
#define FTM_MODE_CAPTEST_WIDTH                   1u
#define FTM_MODE_CAPTEST(x)                      (((uint32)(((uint32)(x))<<FTM_MODE_CAPTEST_SHIFT))&FTM_MODE_CAPTEST_MASK)
#define FTM_MODE_FAULTM_MASK                     0x60u
#define FTM_MODE_FAULTM_SHIFT                    5u
#define FTM_MODE_FAULTM_WIDTH                    2u
#define FTM_MODE_FAULTM(x)                       (((uint32)(((uint32)(x))<<FTM_MODE_FAULTM_SHIFT))&FTM_MODE_FAULTM_MASK)
#define FTM_MODE_FAULTIE_MASK                    0x80u
#define FTM_MODE_FAULTIE_SHIFT                   7u
#define FTM_MODE_FAULTIE_WIDTH                   1u
#define FTM_MODE_FAULTIE(x)                      (((uint32)(((uint32)(x))<<FTM_MODE_FAULTIE_SHIFT))&FTM_MODE_FAULTIE_MASK)
/* SYNC Bit Fields */
#define FTM_SYNC_CNTMIN_MASK                     0x1u
#define FTM_SYNC_CNTMIN_SHIFT                    0u
#define FTM_SYNC_CNTMIN_WIDTH                    1u
#define FTM_SYNC_CNTMIN(x)                       (((uint32)(((uint32)(x))<<FTM_SYNC_CNTMIN_SHIFT))&FTM_SYNC_CNTMIN_MASK)
#define FTM_SYNC_CNTMAX_MASK                     0x2u
#define FTM_SYNC_CNTMAX_SHIFT                    1u
#define FTM_SYNC_CNTMAX_WIDTH                    1u
#define FTM_SYNC_CNTMAX(x)                       (((uint32)(((uint32)(x))<<FTM_SYNC_CNTMAX_SHIFT))&FTM_SYNC_CNTMAX_MASK)
#define FTM_SYNC_REINIT_MASK                     0x4u
#define FTM_SYNC_REINIT_SHIFT                    2u
#define FTM_SYNC_REINIT_WIDTH                    1u
#define FTM_SYNC_REINIT(x)                       (((uint32)(((uint32)(x))<<FTM_SYNC_REINIT_SHIFT))&FTM_SYNC_REINIT_MASK)
#define FTM_SYNC_SYNCHOM_MASK                    0x8u
#define FTM_SYNC_SYNCHOM_SHIFT                   3u
#define FTM_SYNC_SYNCHOM_WIDTH                   1u
#define FTM_SYNC_SYNCHOM(x)                      (((uint32)(((uint32)(x))<<FTM_SYNC_SYNCHOM_SHIFT))&FTM_SYNC_SYNCHOM_MASK)
#define FTM_SYNC_TRIG0_MASK                      0x10u
#define FTM_SYNC_TRIG0_SHIFT                     4u
#define FTM_SYNC_TRIG0_WIDTH                     1u
#define FTM_SYNC_TRIG0(x)                        (((uint32)(((uint32)(x))<<FTM_SYNC_TRIG0_SHIFT))&FTM_SYNC_TRIG0_MASK)
#define FTM_SYNC_TRIG1_MASK                      0x20u
#define FTM_SYNC_TRIG1_SHIFT                     5u
#define FTM_SYNC_TRIG1_WIDTH                     1u
#define FTM_SYNC_TRIG1(x)                        (((uint32)(((uint32)(x))<<FTM_SYNC_TRIG1_SHIFT))&FTM_SYNC_TRIG1_MASK)
#define FTM_SYNC_TRIG2_MASK                      0x40u
#define FTM_SYNC_TRIG2_SHIFT                     6u
#define FTM_SYNC_TRIG2_WIDTH                     1u
#define FTM_SYNC_TRIG2(x)                        (((uint32)(((uint32)(x))<<FTM_SYNC_TRIG2_SHIFT))&FTM_SYNC_TRIG2_MASK)
#define FTM_SYNC_SWSYNC_MASK                     0x80u
#define FTM_SYNC_SWSYNC_SHIFT                    7u
#define FTM_SYNC_SWSYNC_WIDTH                    1u
#define FTM_SYNC_SWSYNC(x)                       (((uint32)(((uint32)(x))<<FTM_SYNC_SWSYNC_SHIFT))&FTM_SYNC_SWSYNC_MASK)
/* OUTINIT Bit Fields */
#define FTM_OUTINIT_CH0OI_MASK                   0x1u
#define FTM_OUTINIT_CH0OI_SHIFT                  0u
#define FTM_OUTINIT_CH0OI_WIDTH                  1u
#define FTM_OUTINIT_CH0OI(x)                     (((uint32)(((uint32)(x))<<FTM_OUTINIT_CH0OI_SHIFT))&FTM_OUTINIT_CH0OI_MASK)
#define FTM_OUTINIT_CH1OI_MASK                   0x2u
#define FTM_OUTINIT_CH1OI_SHIFT                  1u
#define FTM_OUTINIT_CH1OI_WIDTH                  1u
#define FTM_OUTINIT_CH1OI(x)                     (((uint32)(((uint32)(x))<<FTM_OUTINIT_CH1OI_SHIFT))&FTM_OUTINIT_CH1OI_MASK)
#define FTM_OUTINIT_CH2OI_MASK                   0x4u
#define FTM_OUTINIT_CH2OI_SHIFT                  2u
#define FTM_OUTINIT_CH2OI_WIDTH                  1u
#define FTM_OUTINIT_CH2OI(x)                     (((uint32)(((uint32)(x))<<FTM_OUTINIT_CH2OI_SHIFT))&FTM_OUTINIT_CH2OI_MASK)
#define FTM_OUTINIT_CH3OI_MASK                   0x8u
#define FTM_OUTINIT_CH3OI_SHIFT                  3u
#define FTM_OUTINIT_CH3OI_WIDTH                  1u
#define FTM_OUTINIT_CH3OI(x)                     (((uint32)(((uint32)(x))<<FTM_OUTINIT_CH3OI_SHIFT))&FTM_OUTINIT_CH3OI_MASK)
#define FTM_OUTINIT_CH4OI_MASK                   0x10u
#define FTM_OUTINIT_CH4OI_SHIFT                  4u
#define FTM_OUTINIT_CH4OI_WIDTH                  1u
#define FTM_OUTINIT_CH4OI(x)                     (((uint32)(((uint32)(x))<<FTM_OUTINIT_CH4OI_SHIFT))&FTM_OUTINIT_CH4OI_MASK)
#define FTM_OUTINIT_CH5OI_MASK                   0x20u
#define FTM_OUTINIT_CH5OI_SHIFT                  5u
#define FTM_OUTINIT_CH5OI_WIDTH                  1u
#define FTM_OUTINIT_CH5OI(x)                     (((uint32)(((uint32)(x))<<FTM_OUTINIT_CH5OI_SHIFT))&FTM_OUTINIT_CH5OI_MASK)
#define FTM_OUTINIT_CH6OI_MASK                   0x40u
#define FTM_OUTINIT_CH6OI_SHIFT                  6u
#define FTM_OUTINIT_CH6OI_WIDTH                  1u
#define FTM_OUTINIT_CH6OI(x)                     (((uint32)(((uint32)(x))<<FTM_OUTINIT_CH6OI_SHIFT))&FTM_OUTINIT_CH6OI_MASK)
#define FTM_OUTINIT_CH7OI_MASK                   0x80u
#define FTM_OUTINIT_CH7OI_SHIFT                  7u
#define FTM_OUTINIT_CH7OI_WIDTH                  1u
#define FTM_OUTINIT_CH7OI(x)                     (((uint32)(((uint32)(x))<<FTM_OUTINIT_CH7OI_SHIFT))&FTM_OUTINIT_CH7OI_MASK)
/* OUTMASK Bit Fields */
#define FTM_OUTMASK_CH0OM_MASK                   0x1u
#define FTM_OUTMASK_CH0OM_SHIFT                  0u
#define FTM_OUTMASK_CH0OM_WIDTH                  1u
#define FTM_OUTMASK_CH0OM(x)                     (((uint32)(((uint32)(x))<<FTM_OUTMASK_CH0OM_SHIFT))&FTM_OUTMASK_CH0OM_MASK)
#define FTM_OUTMASK_CH1OM_MASK                   0x2u
#define FTM_OUTMASK_CH1OM_SHIFT                  1u
#define FTM_OUTMASK_CH1OM_WIDTH                  1u
#define FTM_OUTMASK_CH1OM(x)                     (((uint32)(((uint32)(x))<<FTM_OUTMASK_CH1OM_SHIFT))&FTM_OUTMASK_CH1OM_MASK)
#define FTM_OUTMASK_CH2OM_MASK                   0x4u
#define FTM_OUTMASK_CH2OM_SHIFT                  2u
#define FTM_OUTMASK_CH2OM_WIDTH                  1u
#define FTM_OUTMASK_CH2OM(x)                     (((uint32)(((uint32)(x))<<FTM_OUTMASK_CH2OM_SHIFT))&FTM_OUTMASK_CH2OM_MASK)
#define FTM_OUTMASK_CH3OM_MASK                   0x8u
#define FTM_OUTMASK_CH3OM_SHIFT                  3u
#define FTM_OUTMASK_CH3OM_WIDTH                  1u
#define FTM_OUTMASK_CH3OM(x)                     (((uint32)(((uint32)(x))<<FTM_OUTMASK_CH3OM_SHIFT))&FTM_OUTMASK_CH3OM_MASK)
#define FTM_OUTMASK_CH4OM_MASK                   0x10u
#define FTM_OUTMASK_CH4OM_SHIFT                  4u
#define FTM_OUTMASK_CH4OM_WIDTH                  1u
#define FTM_OUTMASK_CH4OM(x)                     (((uint32)(((uint32)(x))<<FTM_OUTMASK_CH4OM_SHIFT))&FTM_OUTMASK_CH4OM_MASK)
#define FTM_OUTMASK_CH5OM_MASK                   0x20u
#define FTM_OUTMASK_CH5OM_SHIFT                  5u
#define FTM_OUTMASK_CH5OM_WIDTH                  1u
#define FTM_OUTMASK_CH5OM(x)                     (((uint32)(((uint32)(x))<<FTM_OUTMASK_CH5OM_SHIFT))&FTM_OUTMASK_CH5OM_MASK)
#define FTM_OUTMASK_CH6OM_MASK                   0x40u
#define FTM_OUTMASK_CH6OM_SHIFT                  6u
#define FTM_OUTMASK_CH6OM_WIDTH                  1u
#define FTM_OUTMASK_CH6OM(x)                     (((uint32)(((uint32)(x))<<FTM_OUTMASK_CH6OM_SHIFT))&FTM_OUTMASK_CH6OM_MASK)
#define FTM_OUTMASK_CH7OM_MASK                   0x80u
#define FTM_OUTMASK_CH7OM_SHIFT                  7u
#define FTM_OUTMASK_CH7OM_WIDTH                  1u
#define FTM_OUTMASK_CH7OM(x)                     (((uint32)(((uint32)(x))<<FTM_OUTMASK_CH7OM_SHIFT))&FTM_OUTMASK_CH7OM_MASK)
/* COMBINE Bit Fields */
#define FTM_COMBINE_COMBINE0_MASK                0x1u
#define FTM_COMBINE_COMBINE0_SHIFT               0u
#define FTM_COMBINE_COMBINE0_WIDTH               1u
#define FTM_COMBINE_COMBINE0(x)                  (((uint32)(((uint32)(x))<<FTM_COMBINE_COMBINE0_SHIFT))&FTM_COMBINE_COMBINE0_MASK)
#define FTM_COMBINE_COMP0_MASK                   0x2u
#define FTM_COMBINE_COMP0_SHIFT                  1u
#define FTM_COMBINE_COMP0_WIDTH                  1u
#define FTM_COMBINE_COMP0(x)                     (((uint32)(((uint32)(x))<<FTM_COMBINE_COMP0_SHIFT))&FTM_COMBINE_COMP0_MASK)
#define FTM_COMBINE_DECAPEN0_MASK                0x4u
#define FTM_COMBINE_DECAPEN0_SHIFT               2u
#define FTM_COMBINE_DECAPEN0_WIDTH               1u
#define FTM_COMBINE_DECAPEN0(x)                  (((uint32)(((uint32)(x))<<FTM_COMBINE_DECAPEN0_SHIFT))&FTM_COMBINE_DECAPEN0_MASK)
#define FTM_COMBINE_DECAP0_MASK                  0x8u
#define FTM_COMBINE_DECAP0_SHIFT                 3u
#define FTM_COMBINE_DECAP0_WIDTH                 1u
#define FTM_COMBINE_DECAP0(x)                    (((uint32)(((uint32)(x))<<FTM_COMBINE_DECAP0_SHIFT))&FTM_COMBINE_DECAP0_MASK)
#define FTM_COMBINE_DTEN0_MASK                   0x10u
#define FTM_COMBINE_DTEN0_SHIFT                  4u
#define FTM_COMBINE_DTEN0_WIDTH                  1u
#define FTM_COMBINE_DTEN0(x)                     (((uint32)(((uint32)(x))<<FTM_COMBINE_DTEN0_SHIFT))&FTM_COMBINE_DTEN0_MASK)
#define FTM_COMBINE_SYNCEN0_MASK                 0x20u
#define FTM_COMBINE_SYNCEN0_SHIFT                5u
#define FTM_COMBINE_SYNCEN0_WIDTH                1u
#define FTM_COMBINE_SYNCEN0(x)                   (((uint32)(((uint32)(x))<<FTM_COMBINE_SYNCEN0_SHIFT))&FTM_COMBINE_SYNCEN0_MASK)
#define FTM_COMBINE_FAULTEN0_MASK                0x40u
#define FTM_COMBINE_FAULTEN0_SHIFT               6u
#define FTM_COMBINE_FAULTEN0_WIDTH               1u
#define FTM_COMBINE_FAULTEN0(x)                  (((uint32)(((uint32)(x))<<FTM_COMBINE_FAULTEN0_SHIFT))&FTM_COMBINE_FAULTEN0_MASK)
#define FTM_COMBINE_MCOMBINE0_MASK               0x80u
#define FTM_COMBINE_MCOMBINE0_SHIFT              7u
#define FTM_COMBINE_MCOMBINE0_WIDTH              1u
#define FTM_COMBINE_MCOMBINE0(x)                 (((uint32)(((uint32)(x))<<FTM_COMBINE_MCOMBINE0_SHIFT))&FTM_COMBINE_MCOMBINE0_MASK)
#define FTM_COMBINE_COMBINE1_MASK                0x100u
#define FTM_COMBINE_COMBINE1_SHIFT               8u
#define FTM_COMBINE_COMBINE1_WIDTH               1u
#define FTM_COMBINE_COMBINE1(x)                  (((uint32)(((uint32)(x))<<FTM_COMBINE_COMBINE1_SHIFT))&FTM_COMBINE_COMBINE1_MASK)
#define FTM_COMBINE_COMP1_MASK                   0x200u
#define FTM_COMBINE_COMP1_SHIFT                  9u
#define FTM_COMBINE_COMP1_WIDTH                  1u
#define FTM_COMBINE_COMP1(x)                     (((uint32)(((uint32)(x))<<FTM_COMBINE_COMP1_SHIFT))&FTM_COMBINE_COMP1_MASK)
#define FTM_COMBINE_DECAPEN1_MASK                0x400u
#define FTM_COMBINE_DECAPEN1_SHIFT               10u
#define FTM_COMBINE_DECAPEN1_WIDTH               1u
#define FTM_COMBINE_DECAPEN1(x)                  (((uint32)(((uint32)(x))<<FTM_COMBINE_DECAPEN1_SHIFT))&FTM_COMBINE_DECAPEN1_MASK)
#define FTM_COMBINE_DECAP1_MASK                  0x800u
#define FTM_COMBINE_DECAP1_SHIFT                 11u
#define FTM_COMBINE_DECAP1_WIDTH                 1u
#define FTM_COMBINE_DECAP1(x)                    (((uint32)(((uint32)(x))<<FTM_COMBINE_DECAP1_SHIFT))&FTM_COMBINE_DECAP1_MASK)
#define FTM_COMBINE_DTEN1_MASK                   0x1000u
#define FTM_COMBINE_DTEN1_SHIFT                  12u
#define FTM_COMBINE_DTEN1_WIDTH                  1u
#define FTM_COMBINE_DTEN1(x)                     (((uint32)(((uint32)(x))<<FTM_COMBINE_DTEN1_SHIFT))&FTM_COMBINE_DTEN1_MASK)
#define FTM_COMBINE_SYNCEN1_MASK                 0x2000u
#define FTM_COMBINE_SYNCEN1_SHIFT                13u
#define FTM_COMBINE_SYNCEN1_WIDTH                1u
#define FTM_COMBINE_SYNCEN1(x)                   (((uint32)(((uint32)(x))<<FTM_COMBINE_SYNCEN1_SHIFT))&FTM_COMBINE_SYNCEN1_MASK)
#define FTM_COMBINE_FAULTEN1_MASK                0x4000u
#define FTM_COMBINE_FAULTEN1_SHIFT               14u
#define FTM_COMBINE_FAULTEN1_WIDTH               1u
#define FTM_COMBINE_FAULTEN1(x)                  (((uint32)(((uint32)(x))<<FTM_COMBINE_FAULTEN1_SHIFT))&FTM_COMBINE_FAULTEN1_MASK)
#define FTM_COMBINE_MCOMBINE1_MASK               0x8000u
#define FTM_COMBINE_MCOMBINE1_SHIFT              15u
#define FTM_COMBINE_MCOMBINE1_WIDTH              1u
#define FTM_COMBINE_MCOMBINE1(x)                 (((uint32)(((uint32)(x))<<FTM_COMBINE_MCOMBINE1_SHIFT))&FTM_COMBINE_MCOMBINE1_MASK)
#define FTM_COMBINE_COMBINE2_MASK                0x10000u
#define FTM_COMBINE_COMBINE2_SHIFT               16u
#define FTM_COMBINE_COMBINE2_WIDTH               1u
#define FTM_COMBINE_COMBINE2(x)                  (((uint32)(((uint32)(x))<<FTM_COMBINE_COMBINE2_SHIFT))&FTM_COMBINE_COMBINE2_MASK)
#define FTM_COMBINE_COMP2_MASK                   0x20000u
#define FTM_COMBINE_COMP2_SHIFT                  17u
#define FTM_COMBINE_COMP2_WIDTH                  1u
#define FTM_COMBINE_COMP2(x)                     (((uint32)(((uint32)(x))<<FTM_COMBINE_COMP2_SHIFT))&FTM_COMBINE_COMP2_MASK)
#define FTM_COMBINE_DECAPEN2_MASK                0x40000u
#define FTM_COMBINE_DECAPEN2_SHIFT               18u
#define FTM_COMBINE_DECAPEN2_WIDTH               1u
#define FTM_COMBINE_DECAPEN2(x)                  (((uint32)(((uint32)(x))<<FTM_COMBINE_DECAPEN2_SHIFT))&FTM_COMBINE_DECAPEN2_MASK)
#define FTM_COMBINE_DECAP2_MASK                  0x80000u
#define FTM_COMBINE_DECAP2_SHIFT                 19u
#define FTM_COMBINE_DECAP2_WIDTH                 1u
#define FTM_COMBINE_DECAP2(x)                    (((uint32)(((uint32)(x))<<FTM_COMBINE_DECAP2_SHIFT))&FTM_COMBINE_DECAP2_MASK)
#define FTM_COMBINE_DTEN2_MASK                   0x100000u
#define FTM_COMBINE_DTEN2_SHIFT                  20u
#define FTM_COMBINE_DTEN2_WIDTH                  1u
#define FTM_COMBINE_DTEN2(x)                     (((uint32)(((uint32)(x))<<FTM_COMBINE_DTEN2_SHIFT))&FTM_COMBINE_DTEN2_MASK)
#define FTM_COMBINE_SYNCEN2_MASK                 0x200000u
#define FTM_COMBINE_SYNCEN2_SHIFT                21u
#define FTM_COMBINE_SYNCEN2_WIDTH                1u
#define FTM_COMBINE_SYNCEN2(x)                   (((uint32)(((uint32)(x))<<FTM_COMBINE_SYNCEN2_SHIFT))&FTM_COMBINE_SYNCEN2_MASK)
#define FTM_COMBINE_FAULTEN2_MASK                0x400000u
#define FTM_COMBINE_FAULTEN2_SHIFT               22u
#define FTM_COMBINE_FAULTEN2_WIDTH               1u
#define FTM_COMBINE_FAULTEN2(x)                  (((uint32)(((uint32)(x))<<FTM_COMBINE_FAULTEN2_SHIFT))&FTM_COMBINE_FAULTEN2_MASK)
#define FTM_COMBINE_MCOMBINE2_MASK               0x800000u
#define FTM_COMBINE_MCOMBINE2_SHIFT              23u
#define FTM_COMBINE_MCOMBINE2_WIDTH              1u
#define FTM_COMBINE_MCOMBINE2(x)                 (((uint32)(((uint32)(x))<<FTM_COMBINE_MCOMBINE2_SHIFT))&FTM_COMBINE_MCOMBINE2_MASK)
#define FTM_COMBINE_COMBINE3_MASK                0x1000000u
#define FTM_COMBINE_COMBINE3_SHIFT               24u
#define FTM_COMBINE_COMBINE3_WIDTH               1u
#define FTM_COMBINE_COMBINE3(x)                  (((uint32)(((uint32)(x))<<FTM_COMBINE_COMBINE3_SHIFT))&FTM_COMBINE_COMBINE3_MASK)
#define FTM_COMBINE_COMP3_MASK                   0x2000000u
#define FTM_COMBINE_COMP3_SHIFT                  25u
#define FTM_COMBINE_COMP3_WIDTH                  1u
#define FTM_COMBINE_COMP3(x)                     (((uint32)(((uint32)(x))<<FTM_COMBINE_COMP3_SHIFT))&FTM_COMBINE_COMP3_MASK)
#define FTM_COMBINE_DECAPEN3_MASK                0x4000000u
#define FTM_COMBINE_DECAPEN3_SHIFT               26u
#define FTM_COMBINE_DECAPEN3_WIDTH               1u
#define FTM_COMBINE_DECAPEN3(x)                  (((uint32)(((uint32)(x))<<FTM_COMBINE_DECAPEN3_SHIFT))&FTM_COMBINE_DECAPEN3_MASK)
#define FTM_COMBINE_DECAP3_MASK                  0x8000000u
#define FTM_COMBINE_DECAP3_SHIFT                 27u
#define FTM_COMBINE_DECAP3_WIDTH                 1u
#define FTM_COMBINE_DECAP3(x)                    (((uint32)(((uint32)(x))<<FTM_COMBINE_DECAP3_SHIFT))&FTM_COMBINE_DECAP3_MASK)
#define FTM_COMBINE_DTEN3_MASK                   0x10000000u
#define FTM_COMBINE_DTEN3_SHIFT                  28u
#define FTM_COMBINE_DTEN3_WIDTH                  1u
#define FTM_COMBINE_DTEN3(x)                     (((uint32)(((uint32)(x))<<FTM_COMBINE_DTEN3_SHIFT))&FTM_COMBINE_DTEN3_MASK)
#define FTM_COMBINE_SYNCEN3_MASK                 0x20000000u
#define FTM_COMBINE_SYNCEN3_SHIFT                29u
#define FTM_COMBINE_SYNCEN3_WIDTH                1u
#define FTM_COMBINE_SYNCEN3(x)                   (((uint32)(((uint32)(x))<<FTM_COMBINE_SYNCEN3_SHIFT))&FTM_COMBINE_SYNCEN3_MASK)
#define FTM_COMBINE_FAULTEN3_MASK                0x40000000u
#define FTM_COMBINE_FAULTEN3_SHIFT               30u
#define FTM_COMBINE_FAULTEN3_WIDTH               1u
#define FTM_COMBINE_FAULTEN3(x)                  (((uint32)(((uint32)(x))<<FTM_COMBINE_FAULTEN3_SHIFT))&FTM_COMBINE_FAULTEN3_MASK)
#define FTM_COMBINE_MCOMBINE3_MASK               0x80000000u
#define FTM_COMBINE_MCOMBINE3_SHIFT              31u
#define FTM_COMBINE_MCOMBINE3_WIDTH              1u
#define FTM_COMBINE_MCOMBINE3(x)                 (((uint32)(((uint32)(x))<<FTM_COMBINE_MCOMBINE3_SHIFT))&FTM_COMBINE_MCOMBINE3_MASK)
/* DEADTIME Bit Fields */
#define FTM_DEADTIME_DTVAL_MASK                  0x3Fu
#define FTM_DEADTIME_DTVAL_SHIFT                 0u
#define FTM_DEADTIME_DTVAL_WIDTH                 6u
#define FTM_DEADTIME_DTVAL(x)                    (((uint32)(((uint32)(x))<<FTM_DEADTIME_DTVAL_SHIFT))&FTM_DEADTIME_DTVAL_MASK)
#define FTM_DEADTIME_DTPS_MASK                   0xC0u
#define FTM_DEADTIME_DTPS_SHIFT                  6u
#define FTM_DEADTIME_DTPS_WIDTH                  2u
#define FTM_DEADTIME_DTPS(x)                     (((uint32)(((uint32)(x))<<FTM_DEADTIME_DTPS_SHIFT))&FTM_DEADTIME_DTPS_MASK)
#define FTM_DEADTIME_DTVALEX_MASK                0xF0000u
#define FTM_DEADTIME_DTVALEX_SHIFT               16u
#define FTM_DEADTIME_DTVALEX_WIDTH               4u
#define FTM_DEADTIME_DTVALEX(x)                  (((uint32)(((uint32)(x))<<FTM_DEADTIME_DTVALEX_SHIFT))&FTM_DEADTIME_DTVALEX_MASK)
/* EXTTRIG Bit Fields */
#define FTM_EXTTRIG_CH2TRIG_MASK                 0x1u
#define FTM_EXTTRIG_CH2TRIG_SHIFT                0u
#define FTM_EXTTRIG_CH2TRIG_WIDTH                1u
#define FTM_EXTTRIG_CH2TRIG(x)                   (((uint32)(((uint32)(x))<<FTM_EXTTRIG_CH2TRIG_SHIFT))&FTM_EXTTRIG_CH2TRIG_MASK)
#define FTM_EXTTRIG_CH3TRIG_MASK                 0x2u
#define FTM_EXTTRIG_CH3TRIG_SHIFT                1u
#define FTM_EXTTRIG_CH3TRIG_WIDTH                1u
#define FTM_EXTTRIG_CH3TRIG(x)                   (((uint32)(((uint32)(x))<<FTM_EXTTRIG_CH3TRIG_SHIFT))&FTM_EXTTRIG_CH3TRIG_MASK)
#define FTM_EXTTRIG_CH4TRIG_MASK                 0x4u
#define FTM_EXTTRIG_CH4TRIG_SHIFT                2u
#define FTM_EXTTRIG_CH4TRIG_WIDTH                1u
#define FTM_EXTTRIG_CH4TRIG(x)                   (((uint32)(((uint32)(x))<<FTM_EXTTRIG_CH4TRIG_SHIFT))&FTM_EXTTRIG_CH4TRIG_MASK)
#define FTM_EXTTRIG_CH5TRIG_MASK                 0x8u
#define FTM_EXTTRIG_CH5TRIG_SHIFT                3u
#define FTM_EXTTRIG_CH5TRIG_WIDTH                1u
#define FTM_EXTTRIG_CH5TRIG(x)                   (((uint32)(((uint32)(x))<<FTM_EXTTRIG_CH5TRIG_SHIFT))&FTM_EXTTRIG_CH5TRIG_MASK)
#define FTM_EXTTRIG_CH0TRIG_MASK                 0x10u
#define FTM_EXTTRIG_CH0TRIG_SHIFT                4u
#define FTM_EXTTRIG_CH0TRIG_WIDTH                1u
#define FTM_EXTTRIG_CH0TRIG(x)                   (((uint32)(((uint32)(x))<<FTM_EXTTRIG_CH0TRIG_SHIFT))&FTM_EXTTRIG_CH0TRIG_MASK)
#define FTM_EXTTRIG_CH1TRIG_MASK                 0x20u
#define FTM_EXTTRIG_CH1TRIG_SHIFT                5u
#define FTM_EXTTRIG_CH1TRIG_WIDTH                1u
#define FTM_EXTTRIG_CH1TRIG(x)                   (((uint32)(((uint32)(x))<<FTM_EXTTRIG_CH1TRIG_SHIFT))&FTM_EXTTRIG_CH1TRIG_MASK)
#define FTM_EXTTRIG_INITTRIGEN_MASK              0x40u
#define FTM_EXTTRIG_INITTRIGEN_SHIFT             6u
#define FTM_EXTTRIG_INITTRIGEN_WIDTH             1u
#define FTM_EXTTRIG_INITTRIGEN(x)                (((uint32)(((uint32)(x))<<FTM_EXTTRIG_INITTRIGEN_SHIFT))&FTM_EXTTRIG_INITTRIGEN_MASK)
#define FTM_EXTTRIG_TRIGF_MASK                   0x80u
#define FTM_EXTTRIG_TRIGF_SHIFT                  7u
#define FTM_EXTTRIG_TRIGF_WIDTH                  1u
#define FTM_EXTTRIG_TRIGF(x)                     (((uint32)(((uint32)(x))<<FTM_EXTTRIG_TRIGF_SHIFT))&FTM_EXTTRIG_TRIGF_MASK)
#define FTM_EXTTRIG_CH6TRIG_MASK                 0x100u
#define FTM_EXTTRIG_CH6TRIG_SHIFT                8u
#define FTM_EXTTRIG_CH6TRIG_WIDTH                1u
#define FTM_EXTTRIG_CH6TRIG(x)                   (((uint32)(((uint32)(x))<<FTM_EXTTRIG_CH6TRIG_SHIFT))&FTM_EXTTRIG_CH6TRIG_MASK)
#define FTM_EXTTRIG_CH7TRIG_MASK                 0x200u
#define FTM_EXTTRIG_CH7TRIG_SHIFT                9u
#define FTM_EXTTRIG_CH7TRIG_WIDTH                1u
#define FTM_EXTTRIG_CH7TRIG(x)                   (((uint32)(((uint32)(x))<<FTM_EXTTRIG_CH7TRIG_SHIFT))&FTM_EXTTRIG_CH7TRIG_MASK)
/* POL Bit Fields */
#define FTM_POL_POL0_MASK                        0x1u
#define FTM_POL_POL0_SHIFT                       0u
#define FTM_POL_POL0_WIDTH                       1u
#define FTM_POL_POL0(x)                          (((uint32)(((uint32)(x))<<FTM_POL_POL0_SHIFT))&FTM_POL_POL0_MASK)
#define FTM_POL_POL1_MASK                        0x2u
#define FTM_POL_POL1_SHIFT                       1u
#define FTM_POL_POL1_WIDTH                       1u
#define FTM_POL_POL1(x)                          (((uint32)(((uint32)(x))<<FTM_POL_POL1_SHIFT))&FTM_POL_POL1_MASK)
#define FTM_POL_POL2_MASK                        0x4u
#define FTM_POL_POL2_SHIFT                       2u
#define FTM_POL_POL2_WIDTH                       1u
#define FTM_POL_POL2(x)                          (((uint32)(((uint32)(x))<<FTM_POL_POL2_SHIFT))&FTM_POL_POL2_MASK)
#define FTM_POL_POL3_MASK                        0x8u
#define FTM_POL_POL3_SHIFT                       3u
#define FTM_POL_POL3_WIDTH                       1u
#define FTM_POL_POL3(x)                          (((uint32)(((uint32)(x))<<FTM_POL_POL3_SHIFT))&FTM_POL_POL3_MASK)
#define FTM_POL_POL4_MASK                        0x10u
#define FTM_POL_POL4_SHIFT                       4u
#define FTM_POL_POL4_WIDTH                       1u
#define FTM_POL_POL4(x)                          (((uint32)(((uint32)(x))<<FTM_POL_POL4_SHIFT))&FTM_POL_POL4_MASK)
#define FTM_POL_POL5_MASK                        0x20u
#define FTM_POL_POL5_SHIFT                       5u
#define FTM_POL_POL5_WIDTH                       1u
#define FTM_POL_POL5(x)                          (((uint32)(((uint32)(x))<<FTM_POL_POL5_SHIFT))&FTM_POL_POL5_MASK)
#define FTM_POL_POL6_MASK                        0x40u
#define FTM_POL_POL6_SHIFT                       6u
#define FTM_POL_POL6_WIDTH                       1u
#define FTM_POL_POL6(x)                          (((uint32)(((uint32)(x))<<FTM_POL_POL6_SHIFT))&FTM_POL_POL6_MASK)
#define FTM_POL_POL7_MASK                        0x80u
#define FTM_POL_POL7_SHIFT                       7u
#define FTM_POL_POL7_WIDTH                       1u
#define FTM_POL_POL7(x)                          (((uint32)(((uint32)(x))<<FTM_POL_POL7_SHIFT))&FTM_POL_POL7_MASK)
/* FMS Bit Fields */
#define FTM_FMS_FAULTF0_MASK                     0x1u
#define FTM_FMS_FAULTF0_SHIFT                    0u
#define FTM_FMS_FAULTF0_WIDTH                    1u
#define FTM_FMS_FAULTF0(x)                       (((uint32)(((uint32)(x))<<FTM_FMS_FAULTF0_SHIFT))&FTM_FMS_FAULTF0_MASK)
#define FTM_FMS_FAULTF1_MASK                     0x2u
#define FTM_FMS_FAULTF1_SHIFT                    1u
#define FTM_FMS_FAULTF1_WIDTH                    1u
#define FTM_FMS_FAULTF1(x)                       (((uint32)(((uint32)(x))<<FTM_FMS_FAULTF1_SHIFT))&FTM_FMS_FAULTF1_MASK)
#define FTM_FMS_FAULTF2_MASK                     0x4u
#define FTM_FMS_FAULTF2_SHIFT                    2u
#define FTM_FMS_FAULTF2_WIDTH                    1u
#define FTM_FMS_FAULTF2(x)                       (((uint32)(((uint32)(x))<<FTM_FMS_FAULTF2_SHIFT))&FTM_FMS_FAULTF2_MASK)
#define FTM_FMS_FAULTF3_MASK                     0x8u
#define FTM_FMS_FAULTF3_SHIFT                    3u
#define FTM_FMS_FAULTF3_WIDTH                    1u
#define FTM_FMS_FAULTF3(x)                       (((uint32)(((uint32)(x))<<FTM_FMS_FAULTF3_SHIFT))&FTM_FMS_FAULTF3_MASK)
#define FTM_FMS_FAULTIN_MASK                     0x20u
#define FTM_FMS_FAULTIN_SHIFT                    5u
#define FTM_FMS_FAULTIN_WIDTH                    1u
#define FTM_FMS_FAULTIN(x)                       (((uint32)(((uint32)(x))<<FTM_FMS_FAULTIN_SHIFT))&FTM_FMS_FAULTIN_MASK)
#define FTM_FMS_WPEN_MASK                        0x40u
#define FTM_FMS_WPEN_SHIFT                       6u
#define FTM_FMS_WPEN_WIDTH                       1u
#define FTM_FMS_WPEN(x)                          (((uint32)(((uint32)(x))<<FTM_FMS_WPEN_SHIFT))&FTM_FMS_WPEN_MASK)
#define FTM_FMS_FAULTF_MASK                      0x80u
#define FTM_FMS_FAULTF_SHIFT                     7u
#define FTM_FMS_FAULTF_WIDTH                     1u
#define FTM_FMS_FAULTF(x)                        (((uint32)(((uint32)(x))<<FTM_FMS_FAULTF_SHIFT))&FTM_FMS_FAULTF_MASK)
/* FILTER Bit Fields */
#define FTM_FILTER_CH0FVAL_MASK                  0xFu
#define FTM_FILTER_CH0FVAL_SHIFT                 0u
#define FTM_FILTER_CH0FVAL_WIDTH                 4u
#define FTM_FILTER_CH0FVAL(x)                    (((uint32)(((uint32)(x))<<FTM_FILTER_CH0FVAL_SHIFT))&FTM_FILTER_CH0FVAL_MASK)
#define FTM_FILTER_CH1FVAL_MASK                  0xF0u
#define FTM_FILTER_CH1FVAL_SHIFT                 4u
#define FTM_FILTER_CH1FVAL_WIDTH                 4u
#define FTM_FILTER_CH1FVAL(x)                    (((uint32)(((uint32)(x))<<FTM_FILTER_CH1FVAL_SHIFT))&FTM_FILTER_CH1FVAL_MASK)
#define FTM_FILTER_CH2FVAL_MASK                  0xF00u
#define FTM_FILTER_CH2FVAL_SHIFT                 8u
#define FTM_FILTER_CH2FVAL_WIDTH                 4u
#define FTM_FILTER_CH2FVAL(x)                    (((uint32)(((uint32)(x))<<FTM_FILTER_CH2FVAL_SHIFT))&FTM_FILTER_CH2FVAL_MASK)
#define FTM_FILTER_CH3FVAL_MASK                  0xF000u
#define FTM_FILTER_CH3FVAL_SHIFT                 12u
#define FTM_FILTER_CH3FVAL_WIDTH                 4u
#define FTM_FILTER_CH3FVAL(x)                    (((uint32)(((uint32)(x))<<FTM_FILTER_CH3FVAL_SHIFT))&FTM_FILTER_CH3FVAL_MASK)
/* FLTCTRL Bit Fields */
#define FTM_FLTCTRL_FAULT0EN_MASK                0x1u
#define FTM_FLTCTRL_FAULT0EN_SHIFT               0u
#define FTM_FLTCTRL_FAULT0EN_WIDTH               1u
#define FTM_FLTCTRL_FAULT0EN(x)                  (((uint32)(((uint32)(x))<<FTM_FLTCTRL_FAULT0EN_SHIFT))&FTM_FLTCTRL_FAULT0EN_MASK)
#define FTM_FLTCTRL_FAULT1EN_MASK                0x2u
#define FTM_FLTCTRL_FAULT1EN_SHIFT               1u
#define FTM_FLTCTRL_FAULT1EN_WIDTH               1u
#define FTM_FLTCTRL_FAULT1EN(x)                  (((uint32)(((uint32)(x))<<FTM_FLTCTRL_FAULT1EN_SHIFT))&FTM_FLTCTRL_FAULT1EN_MASK)
#define FTM_FLTCTRL_FAULT2EN_MASK                0x4u
#define FTM_FLTCTRL_FAULT2EN_SHIFT               2u
#define FTM_FLTCTRL_FAULT2EN_WIDTH               1u
#define FTM_FLTCTRL_FAULT2EN(x)                  (((uint32)(((uint32)(x))<<FTM_FLTCTRL_FAULT2EN_SHIFT))&FTM_FLTCTRL_FAULT2EN_MASK)
#define FTM_FLTCTRL_FAULT3EN_MASK                0x8u
#define FTM_FLTCTRL_FAULT3EN_SHIFT               3u
#define FTM_FLTCTRL_FAULT3EN_WIDTH               1u
#define FTM_FLTCTRL_FAULT3EN(x)                  (((uint32)(((uint32)(x))<<FTM_FLTCTRL_FAULT3EN_SHIFT))&FTM_FLTCTRL_FAULT3EN_MASK)
#define FTM_FLTCTRL_FFLTR0EN_MASK                0x10u
#define FTM_FLTCTRL_FFLTR0EN_SHIFT               4u
#define FTM_FLTCTRL_FFLTR0EN_WIDTH               1u
#define FTM_FLTCTRL_FFLTR0EN(x)                  (((uint32)(((uint32)(x))<<FTM_FLTCTRL_FFLTR0EN_SHIFT))&FTM_FLTCTRL_FFLTR0EN_MASK)
#define FTM_FLTCTRL_FFLTR1EN_MASK                0x20u
#define FTM_FLTCTRL_FFLTR1EN_SHIFT               5u
#define FTM_FLTCTRL_FFLTR1EN_WIDTH               1u
#define FTM_FLTCTRL_FFLTR1EN(x)                  (((uint32)(((uint32)(x))<<FTM_FLTCTRL_FFLTR1EN_SHIFT))&FTM_FLTCTRL_FFLTR1EN_MASK)
#define FTM_FLTCTRL_FFLTR2EN_MASK                0x40u
#define FTM_FLTCTRL_FFLTR2EN_SHIFT               6u
#define FTM_FLTCTRL_FFLTR2EN_WIDTH               1u
#define FTM_FLTCTRL_FFLTR2EN(x)                  (((uint32)(((uint32)(x))<<FTM_FLTCTRL_FFLTR2EN_SHIFT))&FTM_FLTCTRL_FFLTR2EN_MASK)
#define FTM_FLTCTRL_FFLTR3EN_MASK                0x80u
#define FTM_FLTCTRL_FFLTR3EN_SHIFT               7u
#define FTM_FLTCTRL_FFLTR3EN_WIDTH               1u
#define FTM_FLTCTRL_FFLTR3EN(x)                  (((uint32)(((uint32)(x))<<FTM_FLTCTRL_FFLTR3EN_SHIFT))&FTM_FLTCTRL_FFLTR3EN_MASK)
#define FTM_FLTCTRL_FFVAL_MASK                   0xF00u
#define FTM_FLTCTRL_FFVAL_SHIFT                  8u
#define FTM_FLTCTRL_FFVAL_WIDTH                  4u
#define FTM_FLTCTRL_FFVAL(x)                     (((uint32)(((uint32)(x))<<FTM_FLTCTRL_FFVAL_SHIFT))&FTM_FLTCTRL_FFVAL_MASK)
#define FTM_FLTCTRL_FSTATE_MASK                  0x8000u
#define FTM_FLTCTRL_FSTATE_SHIFT                 15u
#define FTM_FLTCTRL_FSTATE_WIDTH                 1u
#define FTM_FLTCTRL_FSTATE(x)                    (((uint32)(((uint32)(x))<<FTM_FLTCTRL_FSTATE_SHIFT))&FTM_FLTCTRL_FSTATE_MASK)
/* QDCTRL Bit Fields */
#define FTM_QDCTRL_QUADEN_MASK                   0x1u
#define FTM_QDCTRL_QUADEN_SHIFT                  0u
#define FTM_QDCTRL_QUADEN_WIDTH                  1u
#define FTM_QDCTRL_QUADEN(x)                     (((uint32)(((uint32)(x))<<FTM_QDCTRL_QUADEN_SHIFT))&FTM_QDCTRL_QUADEN_MASK)
#define FTM_QDCTRL_TOFDIR_MASK                   0x2u
#define FTM_QDCTRL_TOFDIR_SHIFT                  1u
#define FTM_QDCTRL_TOFDIR_WIDTH                  1u
#define FTM_QDCTRL_TOFDIR(x)                     (((uint32)(((uint32)(x))<<FTM_QDCTRL_TOFDIR_SHIFT))&FTM_QDCTRL_TOFDIR_MASK)
#define FTM_QDCTRL_QUADIR_MASK                   0x4u
#define FTM_QDCTRL_QUADIR_SHIFT                  2u
#define FTM_QDCTRL_QUADIR_WIDTH                  1u
#define FTM_QDCTRL_QUADIR(x)                     (((uint32)(((uint32)(x))<<FTM_QDCTRL_QUADIR_SHIFT))&FTM_QDCTRL_QUADIR_MASK)
#define FTM_QDCTRL_QUADMODE_MASK                 0x8u
#define FTM_QDCTRL_QUADMODE_SHIFT                3u
#define FTM_QDCTRL_QUADMODE_WIDTH                1u
#define FTM_QDCTRL_QUADMODE(x)                   (((uint32)(((uint32)(x))<<FTM_QDCTRL_QUADMODE_SHIFT))&FTM_QDCTRL_QUADMODE_MASK)
#define FTM_QDCTRL_PHBPOL_MASK                   0x10u
#define FTM_QDCTRL_PHBPOL_SHIFT                  4u
#define FTM_QDCTRL_PHBPOL_WIDTH                  1u
#define FTM_QDCTRL_PHBPOL(x)                     (((uint32)(((uint32)(x))<<FTM_QDCTRL_PHBPOL_SHIFT))&FTM_QDCTRL_PHBPOL_MASK)
#define FTM_QDCTRL_PHAPOL_MASK                   0x20u
#define FTM_QDCTRL_PHAPOL_SHIFT                  5u
#define FTM_QDCTRL_PHAPOL_WIDTH                  1u
#define FTM_QDCTRL_PHAPOL(x)                     (((uint32)(((uint32)(x))<<FTM_QDCTRL_PHAPOL_SHIFT))&FTM_QDCTRL_PHAPOL_MASK)
#define FTM_QDCTRL_PHBFLTREN_MASK                0x40u
#define FTM_QDCTRL_PHBFLTREN_SHIFT               6u
#define FTM_QDCTRL_PHBFLTREN_WIDTH               1u
#define FTM_QDCTRL_PHBFLTREN(x)                  (((uint32)(((uint32)(x))<<FTM_QDCTRL_PHBFLTREN_SHIFT))&FTM_QDCTRL_PHBFLTREN_MASK)
#define FTM_QDCTRL_PHAFLTREN_MASK                0x80u
#define FTM_QDCTRL_PHAFLTREN_SHIFT               7u
#define FTM_QDCTRL_PHAFLTREN_WIDTH               1u
#define FTM_QDCTRL_PHAFLTREN(x)                  (((uint32)(((uint32)(x))<<FTM_QDCTRL_PHAFLTREN_SHIFT))&FTM_QDCTRL_PHAFLTREN_MASK)
/* CONF Bit Fields */
#define FTM_CONF_LDFQ_MASK                       0x1Fu
#define FTM_CONF_LDFQ_SHIFT                      0u
#define FTM_CONF_LDFQ_WIDTH                      5u
#define FTM_CONF_LDFQ(x)                         (((uint32)(((uint32)(x))<<FTM_CONF_LDFQ_SHIFT))&FTM_CONF_LDFQ_MASK)
#define FTM_CONF_BDMMODE_MASK                    0xC0u
#define FTM_CONF_BDMMODE_SHIFT                   6u
#define FTM_CONF_BDMMODE_WIDTH                   2u
#define FTM_CONF_BDMMODE(x)                      (((uint32)(((uint32)(x))<<FTM_CONF_BDMMODE_SHIFT))&FTM_CONF_BDMMODE_MASK)
#define FTM_CONF_GTBEEN_MASK                     0x200u
#define FTM_CONF_GTBEEN_SHIFT                    9u
#define FTM_CONF_GTBEEN_WIDTH                    1u
#define FTM_CONF_GTBEEN(x)                       (((uint32)(((uint32)(x))<<FTM_CONF_GTBEEN_SHIFT))&FTM_CONF_GTBEEN_MASK)
#define FTM_CONF_GTBEOUT_MASK                    0x400u
#define FTM_CONF_GTBEOUT_SHIFT                   10u
#define FTM_CONF_GTBEOUT_WIDTH                   1u
#define FTM_CONF_GTBEOUT(x)                      (((uint32)(((uint32)(x))<<FTM_CONF_GTBEOUT_SHIFT))&FTM_CONF_GTBEOUT_MASK)
#define FTM_CONF_ITRIGR_MASK                     0x800u
#define FTM_CONF_ITRIGR_SHIFT                    11u
#define FTM_CONF_ITRIGR_WIDTH                    1u
#define FTM_CONF_ITRIGR(x)                       (((uint32)(((uint32)(x))<<FTM_CONF_ITRIGR_SHIFT))&FTM_CONF_ITRIGR_MASK)
/* FLTPOL Bit Fields */
#define FTM_FLTPOL_FLT0POL_MASK                  0x1u
#define FTM_FLTPOL_FLT0POL_SHIFT                 0u
#define FTM_FLTPOL_FLT0POL_WIDTH                 1u
#define FTM_FLTPOL_FLT0POL(x)                    (((uint32)(((uint32)(x))<<FTM_FLTPOL_FLT0POL_SHIFT))&FTM_FLTPOL_FLT0POL_MASK)
#define FTM_FLTPOL_FLT1POL_MASK                  0x2u
#define FTM_FLTPOL_FLT1POL_SHIFT                 1u
#define FTM_FLTPOL_FLT1POL_WIDTH                 1u
#define FTM_FLTPOL_FLT1POL(x)                    (((uint32)(((uint32)(x))<<FTM_FLTPOL_FLT1POL_SHIFT))&FTM_FLTPOL_FLT1POL_MASK)
#define FTM_FLTPOL_FLT2POL_MASK                  0x4u
#define FTM_FLTPOL_FLT2POL_SHIFT                 2u
#define FTM_FLTPOL_FLT2POL_WIDTH                 1u
#define FTM_FLTPOL_FLT2POL(x)                    (((uint32)(((uint32)(x))<<FTM_FLTPOL_FLT2POL_SHIFT))&FTM_FLTPOL_FLT2POL_MASK)
#define FTM_FLTPOL_FLT3POL_MASK                  0x8u
#define FTM_FLTPOL_FLT3POL_SHIFT                 3u
#define FTM_FLTPOL_FLT3POL_WIDTH                 1u
#define FTM_FLTPOL_FLT3POL(x)                    (((uint32)(((uint32)(x))<<FTM_FLTPOL_FLT3POL_SHIFT))&FTM_FLTPOL_FLT3POL_MASK)
/* SYNCONF Bit Fields */
#define FTM_SYNCONF_HWTRIGMODE_MASK              0x1u
#define FTM_SYNCONF_HWTRIGMODE_SHIFT             0u
#define FTM_SYNCONF_HWTRIGMODE_WIDTH             1u
#define FTM_SYNCONF_HWTRIGMODE(x)                (((uint32)(((uint32)(x))<<FTM_SYNCONF_HWTRIGMODE_SHIFT))&FTM_SYNCONF_HWTRIGMODE_MASK)
#define FTM_SYNCONF_CNTINC_MASK                  0x4u
#define FTM_SYNCONF_CNTINC_SHIFT                 2u
#define FTM_SYNCONF_CNTINC_WIDTH                 1u
#define FTM_SYNCONF_CNTINC(x)                    (((uint32)(((uint32)(x))<<FTM_SYNCONF_CNTINC_SHIFT))&FTM_SYNCONF_CNTINC_MASK)
#define FTM_SYNCONF_INVC_MASK                    0x10u
#define FTM_SYNCONF_INVC_SHIFT                   4u
#define FTM_SYNCONF_INVC_WIDTH                   1u
#define FTM_SYNCONF_INVC(x)                      (((uint32)(((uint32)(x))<<FTM_SYNCONF_INVC_SHIFT))&FTM_SYNCONF_INVC_MASK)
#define FTM_SYNCONF_SWOC_MASK                    0x20u
#define FTM_SYNCONF_SWOC_SHIFT                   5u
#define FTM_SYNCONF_SWOC_WIDTH                   1u
#define FTM_SYNCONF_SWOC(x)                      (((uint32)(((uint32)(x))<<FTM_SYNCONF_SWOC_SHIFT))&FTM_SYNCONF_SWOC_MASK)
#define FTM_SYNCONF_SYNCMODE_MASK                0x80u
#define FTM_SYNCONF_SYNCMODE_SHIFT               7u
#define FTM_SYNCONF_SYNCMODE_WIDTH               1u
#define FTM_SYNCONF_SYNCMODE(x)                  (((uint32)(((uint32)(x))<<FTM_SYNCONF_SYNCMODE_SHIFT))&FTM_SYNCONF_SYNCMODE_MASK)
#define FTM_SYNCONF_SWRSTCNT_MASK                0x100u
#define FTM_SYNCONF_SWRSTCNT_SHIFT               8u
#define FTM_SYNCONF_SWRSTCNT_WIDTH               1u
#define FTM_SYNCONF_SWRSTCNT(x)                  (((uint32)(((uint32)(x))<<FTM_SYNCONF_SWRSTCNT_SHIFT))&FTM_SYNCONF_SWRSTCNT_MASK)
#define FTM_SYNCONF_SWWRBUF_MASK                 0x200u
#define FTM_SYNCONF_SWWRBUF_SHIFT                9u
#define FTM_SYNCONF_SWWRBUF_WIDTH                1u
#define FTM_SYNCONF_SWWRBUF(x)                   (((uint32)(((uint32)(x))<<FTM_SYNCONF_SWWRBUF_SHIFT))&FTM_SYNCONF_SWWRBUF_MASK)
#define FTM_SYNCONF_SWOM_MASK                    0x400u
#define FTM_SYNCONF_SWOM_SHIFT                   10u
#define FTM_SYNCONF_SWOM_WIDTH                   1u
#define FTM_SYNCONF_SWOM(x)                      (((uint32)(((uint32)(x))<<FTM_SYNCONF_SWOM_SHIFT))&FTM_SYNCONF_SWOM_MASK)
#define FTM_SYNCONF_SWINVC_MASK                  0x800u
#define FTM_SYNCONF_SWINVC_SHIFT                 11u
#define FTM_SYNCONF_SWINVC_WIDTH                 1u
#define FTM_SYNCONF_SWINVC(x)                    (((uint32)(((uint32)(x))<<FTM_SYNCONF_SWINVC_SHIFT))&FTM_SYNCONF_SWINVC_MASK)
#define FTM_SYNCONF_SWSOC_MASK                   0x1000u
#define FTM_SYNCONF_SWSOC_SHIFT                  12u
#define FTM_SYNCONF_SWSOC_WIDTH                  1u
#define FTM_SYNCONF_SWSOC(x)                     (((uint32)(((uint32)(x))<<FTM_SYNCONF_SWSOC_SHIFT))&FTM_SYNCONF_SWSOC_MASK)
#define FTM_SYNCONF_HWRSTCNT_MASK                0x10000u
#define FTM_SYNCONF_HWRSTCNT_SHIFT               16u
#define FTM_SYNCONF_HWRSTCNT_WIDTH               1u
#define FTM_SYNCONF_HWRSTCNT(x)                  (((uint32)(((uint32)(x))<<FTM_SYNCONF_HWRSTCNT_SHIFT))&FTM_SYNCONF_HWRSTCNT_MASK)
#define FTM_SYNCONF_HWWRBUF_MASK                 0x20000u
#define FTM_SYNCONF_HWWRBUF_SHIFT                17u
#define FTM_SYNCONF_HWWRBUF_WIDTH                1u
#define FTM_SYNCONF_HWWRBUF(x)                   (((uint32)(((uint32)(x))<<FTM_SYNCONF_HWWRBUF_SHIFT))&FTM_SYNCONF_HWWRBUF_MASK)
#define FTM_SYNCONF_HWOM_MASK                    0x40000u
#define FTM_SYNCONF_HWOM_SHIFT                   18u
#define FTM_SYNCONF_HWOM_WIDTH                   1u
#define FTM_SYNCONF_HWOM(x)                      (((uint32)(((uint32)(x))<<FTM_SYNCONF_HWOM_SHIFT))&FTM_SYNCONF_HWOM_MASK)
#define FTM_SYNCONF_HWINVC_MASK                  0x80000u
#define FTM_SYNCONF_HWINVC_SHIFT                 19u
#define FTM_SYNCONF_HWINVC_WIDTH                 1u
#define FTM_SYNCONF_HWINVC(x)                    (((uint32)(((uint32)(x))<<FTM_SYNCONF_HWINVC_SHIFT))&FTM_SYNCONF_HWINVC_MASK)
#define FTM_SYNCONF_HWSOC_MASK                   0x100000u
#define FTM_SYNCONF_HWSOC_SHIFT                  20u
#define FTM_SYNCONF_HWSOC_WIDTH                  1u
#define FTM_SYNCONF_HWSOC(x)                     (((uint32)(((uint32)(x))<<FTM_SYNCONF_HWSOC_SHIFT))&FTM_SYNCONF_HWSOC_MASK)
/* INVCTRL Bit Fields */
#define FTM_INVCTRL_INV0EN_MASK                  0x1u
#define FTM_INVCTRL_INV0EN_SHIFT                 0u
#define FTM_INVCTRL_INV0EN_WIDTH                 1u
#define FTM_INVCTRL_INV0EN(x)                    (((uint32)(((uint32)(x))<<FTM_INVCTRL_INV0EN_SHIFT))&FTM_INVCTRL_INV0EN_MASK)
#define FTM_INVCTRL_INV1EN_MASK                  0x2u
#define FTM_INVCTRL_INV1EN_SHIFT                 1u
#define FTM_INVCTRL_INV1EN_WIDTH                 1u
#define FTM_INVCTRL_INV1EN(x)                    (((uint32)(((uint32)(x))<<FTM_INVCTRL_INV1EN_SHIFT))&FTM_INVCTRL_INV1EN_MASK)
#define FTM_INVCTRL_INV2EN_MASK                  0x4u
#define FTM_INVCTRL_INV2EN_SHIFT                 2u
#define FTM_INVCTRL_INV2EN_WIDTH                 1u
#define FTM_INVCTRL_INV2EN(x)                    (((uint32)(((uint32)(x))<<FTM_INVCTRL_INV2EN_SHIFT))&FTM_INVCTRL_INV2EN_MASK)
#define FTM_INVCTRL_INV3EN_MASK                  0x8u
#define FTM_INVCTRL_INV3EN_SHIFT                 3u
#define FTM_INVCTRL_INV3EN_WIDTH                 1u
#define FTM_INVCTRL_INV3EN(x)                    (((uint32)(((uint32)(x))<<FTM_INVCTRL_INV3EN_SHIFT))&FTM_INVCTRL_INV3EN_MASK)
/* SWOCTRL Bit Fields */
#define FTM_SWOCTRL_CH0OC_MASK                   0x1u
#define FTM_SWOCTRL_CH0OC_SHIFT                  0u
#define FTM_SWOCTRL_CH0OC_WIDTH                  1u
#define FTM_SWOCTRL_CH0OC(x)                     (((uint32)(((uint32)(x))<<FTM_SWOCTRL_CH0OC_SHIFT))&FTM_SWOCTRL_CH0OC_MASK)
#define FTM_SWOCTRL_CH1OC_MASK                   0x2u
#define FTM_SWOCTRL_CH1OC_SHIFT                  1u
#define FTM_SWOCTRL_CH1OC_WIDTH                  1u
#define FTM_SWOCTRL_CH1OC(x)                     (((uint32)(((uint32)(x))<<FTM_SWOCTRL_CH1OC_SHIFT))&FTM_SWOCTRL_CH1OC_MASK)
#define FTM_SWOCTRL_CH2OC_MASK                   0x4u
#define FTM_SWOCTRL_CH2OC_SHIFT                  2u
#define FTM_SWOCTRL_CH2OC_WIDTH                  1u
#define FTM_SWOCTRL_CH2OC(x)                     (((uint32)(((uint32)(x))<<FTM_SWOCTRL_CH2OC_SHIFT))&FTM_SWOCTRL_CH2OC_MASK)
#define FTM_SWOCTRL_CH3OC_MASK                   0x8u
#define FTM_SWOCTRL_CH3OC_SHIFT                  3u
#define FTM_SWOCTRL_CH3OC_WIDTH                  1u
#define FTM_SWOCTRL_CH3OC(x)                     (((uint32)(((uint32)(x))<<FTM_SWOCTRL_CH3OC_SHIFT))&FTM_SWOCTRL_CH3OC_MASK)
#define FTM_SWOCTRL_CH4OC_MASK                   0x10u
#define FTM_SWOCTRL_CH4OC_SHIFT                  4u
#define FTM_SWOCTRL_CH4OC_WIDTH                  1u
#define FTM_SWOCTRL_CH4OC(x)                     (((uint32)(((uint32)(x))<<FTM_SWOCTRL_CH4OC_SHIFT))&FTM_SWOCTRL_CH4OC_MASK)
#define FTM_SWOCTRL_CH5OC_MASK                   0x20u
#define FTM_SWOCTRL_CH5OC_SHIFT                  5u
#define FTM_SWOCTRL_CH5OC_WIDTH                  1u
#define FTM_SWOCTRL_CH5OC(x)                     (((uint32)(((uint32)(x))<<FTM_SWOCTRL_CH5OC_SHIFT))&FTM_SWOCTRL_CH5OC_MASK)
#define FTM_SWOCTRL_CH6OC_MASK                   0x40u
#define FTM_SWOCTRL_CH6OC_SHIFT                  6u
#define FTM_SWOCTRL_CH6OC_WIDTH                  1u
#define FTM_SWOCTRL_CH6OC(x)                     (((uint32)(((uint32)(x))<<FTM_SWOCTRL_CH6OC_SHIFT))&FTM_SWOCTRL_CH6OC_MASK)
#define FTM_SWOCTRL_CH7OC_MASK                   0x80u
#define FTM_SWOCTRL_CH7OC_SHIFT                  7u
#define FTM_SWOCTRL_CH7OC_WIDTH                  1u
#define FTM_SWOCTRL_CH7OC(x)                     (((uint32)(((uint32)(x))<<FTM_SWOCTRL_CH7OC_SHIFT))&FTM_SWOCTRL_CH7OC_MASK)
#define FTM_SWOCTRL_CH0OCV_MASK                  0x100u
#define FTM_SWOCTRL_CH0OCV_SHIFT                 8u
#define FTM_SWOCTRL_CH0OCV_WIDTH                 1u
#define FTM_SWOCTRL_CH0OCV(x)                    (((uint32)(((uint32)(x))<<FTM_SWOCTRL_CH0OCV_SHIFT))&FTM_SWOCTRL_CH0OCV_MASK)
#define FTM_SWOCTRL_CH1OCV_MASK                  0x200u
#define FTM_SWOCTRL_CH1OCV_SHIFT                 9u
#define FTM_SWOCTRL_CH1OCV_WIDTH                 1u
#define FTM_SWOCTRL_CH1OCV(x)                    (((uint32)(((uint32)(x))<<FTM_SWOCTRL_CH1OCV_SHIFT))&FTM_SWOCTRL_CH1OCV_MASK)
#define FTM_SWOCTRL_CH2OCV_MASK                  0x400u
#define FTM_SWOCTRL_CH2OCV_SHIFT                 10u
#define FTM_SWOCTRL_CH2OCV_WIDTH                 1u
#define FTM_SWOCTRL_CH2OCV(x)                    (((uint32)(((uint32)(x))<<FTM_SWOCTRL_CH2OCV_SHIFT))&FTM_SWOCTRL_CH2OCV_MASK)
#define FTM_SWOCTRL_CH3OCV_MASK                  0x800u
#define FTM_SWOCTRL_CH3OCV_SHIFT                 11u
#define FTM_SWOCTRL_CH3OCV_WIDTH                 1u
#define FTM_SWOCTRL_CH3OCV(x)                    (((uint32)(((uint32)(x))<<FTM_SWOCTRL_CH3OCV_SHIFT))&FTM_SWOCTRL_CH3OCV_MASK)
#define FTM_SWOCTRL_CH4OCV_MASK                  0x1000u
#define FTM_SWOCTRL_CH4OCV_SHIFT                 12u
#define FTM_SWOCTRL_CH4OCV_WIDTH                 1u
#define FTM_SWOCTRL_CH4OCV(x)                    (((uint32)(((uint32)(x))<<FTM_SWOCTRL_CH4OCV_SHIFT))&FTM_SWOCTRL_CH4OCV_MASK)
#define FTM_SWOCTRL_CH5OCV_MASK                  0x2000u
#define FTM_SWOCTRL_CH5OCV_SHIFT                 13u
#define FTM_SWOCTRL_CH5OCV_WIDTH                 1u
#define FTM_SWOCTRL_CH5OCV(x)                    (((uint32)(((uint32)(x))<<FTM_SWOCTRL_CH5OCV_SHIFT))&FTM_SWOCTRL_CH5OCV_MASK)
#define FTM_SWOCTRL_CH6OCV_MASK                  0x4000u
#define FTM_SWOCTRL_CH6OCV_SHIFT                 14u
#define FTM_SWOCTRL_CH6OCV_WIDTH                 1u
#define FTM_SWOCTRL_CH6OCV(x)                    (((uint32)(((uint32)(x))<<FTM_SWOCTRL_CH6OCV_SHIFT))&FTM_SWOCTRL_CH6OCV_MASK)
#define FTM_SWOCTRL_CH7OCV_MASK                  0x8000u
#define FTM_SWOCTRL_CH7OCV_SHIFT                 15u
#define FTM_SWOCTRL_CH7OCV_WIDTH                 1u
#define FTM_SWOCTRL_CH7OCV(x)                    (((uint32)(((uint32)(x))<<FTM_SWOCTRL_CH7OCV_SHIFT))&FTM_SWOCTRL_CH7OCV_MASK)
/* PWMLOAD Bit Fields */
#define FTM_PWMLOAD_CH0SEL_MASK                  0x1u
#define FTM_PWMLOAD_CH0SEL_SHIFT                 0u
#define FTM_PWMLOAD_CH0SEL_WIDTH                 1u
#define FTM_PWMLOAD_CH0SEL(x)                    (((uint32)(((uint32)(x))<<FTM_PWMLOAD_CH0SEL_SHIFT))&FTM_PWMLOAD_CH0SEL_MASK)
#define FTM_PWMLOAD_CH1SEL_MASK                  0x2u
#define FTM_PWMLOAD_CH1SEL_SHIFT                 1u
#define FTM_PWMLOAD_CH1SEL_WIDTH                 1u
#define FTM_PWMLOAD_CH1SEL(x)                    (((uint32)(((uint32)(x))<<FTM_PWMLOAD_CH1SEL_SHIFT))&FTM_PWMLOAD_CH1SEL_MASK)
#define FTM_PWMLOAD_CH2SEL_MASK                  0x4u
#define FTM_PWMLOAD_CH2SEL_SHIFT                 2u
#define FTM_PWMLOAD_CH2SEL_WIDTH                 1u
#define FTM_PWMLOAD_CH2SEL(x)                    (((uint32)(((uint32)(x))<<FTM_PWMLOAD_CH2SEL_SHIFT))&FTM_PWMLOAD_CH2SEL_MASK)
#define FTM_PWMLOAD_CH3SEL_MASK                  0x8u
#define FTM_PWMLOAD_CH3SEL_SHIFT                 3u
#define FTM_PWMLOAD_CH3SEL_WIDTH                 1u
#define FTM_PWMLOAD_CH3SEL(x)                    (((uint32)(((uint32)(x))<<FTM_PWMLOAD_CH3SEL_SHIFT))&FTM_PWMLOAD_CH3SEL_MASK)
#define FTM_PWMLOAD_CH4SEL_MASK                  0x10u
#define FTM_PWMLOAD_CH4SEL_SHIFT                 4u
#define FTM_PWMLOAD_CH4SEL_WIDTH                 1u
#define FTM_PWMLOAD_CH4SEL(x)                    (((uint32)(((uint32)(x))<<FTM_PWMLOAD_CH4SEL_SHIFT))&FTM_PWMLOAD_CH4SEL_MASK)
#define FTM_PWMLOAD_CH5SEL_MASK                  0x20u
#define FTM_PWMLOAD_CH5SEL_SHIFT                 5u
#define FTM_PWMLOAD_CH5SEL_WIDTH                 1u
#define FTM_PWMLOAD_CH5SEL(x)                    (((uint32)(((uint32)(x))<<FTM_PWMLOAD_CH5SEL_SHIFT))&FTM_PWMLOAD_CH5SEL_MASK)
#define FTM_PWMLOAD_CH6SEL_MASK                  0x40u
#define FTM_PWMLOAD_CH6SEL_SHIFT                 6u
#define FTM_PWMLOAD_CH6SEL_WIDTH                 1u
#define FTM_PWMLOAD_CH6SEL(x)                    (((uint32)(((uint32)(x))<<FTM_PWMLOAD_CH6SEL_SHIFT))&FTM_PWMLOAD_CH6SEL_MASK)
#define FTM_PWMLOAD_CH7SEL_MASK                  0x80u
#define FTM_PWMLOAD_CH7SEL_SHIFT                 7u
#define FTM_PWMLOAD_CH7SEL_WIDTH                 1u
#define FTM_PWMLOAD_CH7SEL(x)                    (((uint32)(((uint32)(x))<<FTM_PWMLOAD_CH7SEL_SHIFT))&FTM_PWMLOAD_CH7SEL_MASK)
#define FTM_PWMLOAD_HCSEL_MASK                   0x100u
#define FTM_PWMLOAD_HCSEL_SHIFT                  8u
#define FTM_PWMLOAD_HCSEL_WIDTH                  1u
#define FTM_PWMLOAD_HCSEL(x)                     (((uint32)(((uint32)(x))<<FTM_PWMLOAD_HCSEL_SHIFT))&FTM_PWMLOAD_HCSEL_MASK)
#define FTM_PWMLOAD_LDOK_MASK                    0x200u
#define FTM_PWMLOAD_LDOK_SHIFT                   9u
#define FTM_PWMLOAD_LDOK_WIDTH                   1u
#define FTM_PWMLOAD_LDOK(x)                      (((uint32)(((uint32)(x))<<FTM_PWMLOAD_LDOK_SHIFT))&FTM_PWMLOAD_LDOK_MASK)
#define FTM_PWMLOAD_GLEN_MASK                    0x400u
#define FTM_PWMLOAD_GLEN_SHIFT                   10u
#define FTM_PWMLOAD_GLEN_WIDTH                   1u
#define FTM_PWMLOAD_GLEN(x)                      (((uint32)(((uint32)(x))<<FTM_PWMLOAD_GLEN_SHIFT))&FTM_PWMLOAD_GLEN_MASK)
#define FTM_PWMLOAD_GLDOK_MASK                   0x800u
#define FTM_PWMLOAD_GLDOK_SHIFT                  11u
#define FTM_PWMLOAD_GLDOK_WIDTH                  1u
#define FTM_PWMLOAD_GLDOK(x)                     (((uint32)(((uint32)(x))<<FTM_PWMLOAD_GLDOK_SHIFT))&FTM_PWMLOAD_GLDOK_MASK)
/* HCR Bit Fields */
#define FTM_HCR_HCVAL_MASK                       0xFFFFu
#define FTM_HCR_HCVAL_SHIFT                      0u
#define FTM_HCR_HCVAL_WIDTH                      16u
#define FTM_HCR_HCVAL(x)                         (((uint32)(((uint32)(x))<<FTM_HCR_HCVAL_SHIFT))&FTM_HCR_HCVAL_MASK)
/* PAIR0DEADTIME Bit Fields */
#define FTM_PAIR0DEADTIME_DTVAL_MASK             0x3Fu
#define FTM_PAIR0DEADTIME_DTVAL_SHIFT            0u
#define FTM_PAIR0DEADTIME_DTVAL_WIDTH            6u
#define FTM_PAIR0DEADTIME_DTVAL(x)               (((uint32)(((uint32)(x))<<FTM_PAIR0DEADTIME_DTVAL_SHIFT))&FTM_PAIR0DEADTIME_DTVAL_MASK)
#define FTM_PAIR0DEADTIME_DTPS_MASK              0xC0u
#define FTM_PAIR0DEADTIME_DTPS_SHIFT             6u
#define FTM_PAIR0DEADTIME_DTPS_WIDTH             2u
#define FTM_PAIR0DEADTIME_DTPS(x)                (((uint32)(((uint32)(x))<<FTM_PAIR0DEADTIME_DTPS_SHIFT))&FTM_PAIR0DEADTIME_DTPS_MASK)
#define FTM_PAIR0DEADTIME_DTVALEX_MASK           0xF0000u
#define FTM_PAIR0DEADTIME_DTVALEX_SHIFT          16u
#define FTM_PAIR0DEADTIME_DTVALEX_WIDTH          4u
#define FTM_PAIR0DEADTIME_DTVALEX(x)             (((uint32)(((uint32)(x))<<FTM_PAIR0DEADTIME_DTVALEX_SHIFT))&FTM_PAIR0DEADTIME_DTVALEX_MASK)
/* PAIR1DEADTIME Bit Fields */
#define FTM_PAIR1DEADTIME_DTVAL_MASK             0x3Fu
#define FTM_PAIR1DEADTIME_DTVAL_SHIFT            0u
#define FTM_PAIR1DEADTIME_DTVAL_WIDTH            6u
#define FTM_PAIR1DEADTIME_DTVAL(x)               (((uint32)(((uint32)(x))<<FTM_PAIR1DEADTIME_DTVAL_SHIFT))&FTM_PAIR1DEADTIME_DTVAL_MASK)
#define FTM_PAIR1DEADTIME_DTPS_MASK              0xC0u
#define FTM_PAIR1DEADTIME_DTPS_SHIFT             6u
#define FTM_PAIR1DEADTIME_DTPS_WIDTH             2u
#define FTM_PAIR1DEADTIME_DTPS(x)                (((uint32)(((uint32)(x))<<FTM_PAIR1DEADTIME_DTPS_SHIFT))&FTM_PAIR1DEADTIME_DTPS_MASK)
#define FTM_PAIR1DEADTIME_DTVALEX_MASK           0xF0000u
#define FTM_PAIR1DEADTIME_DTVALEX_SHIFT          16u
#define FTM_PAIR1DEADTIME_DTVALEX_WIDTH          4u
#define FTM_PAIR1DEADTIME_DTVALEX(x)             (((uint32)(((uint32)(x))<<FTM_PAIR1DEADTIME_DTVALEX_SHIFT))&FTM_PAIR1DEADTIME_DTVALEX_MASK)
/* PAIR2DEADTIME Bit Fields */
#define FTM_PAIR2DEADTIME_DTVAL_MASK             0x3Fu
#define FTM_PAIR2DEADTIME_DTVAL_SHIFT            0u
#define FTM_PAIR2DEADTIME_DTVAL_WIDTH            6u
#define FTM_PAIR2DEADTIME_DTVAL(x)               (((uint32)(((uint32)(x))<<FTM_PAIR2DEADTIME_DTVAL_SHIFT))&FTM_PAIR2DEADTIME_DTVAL_MASK)
#define FTM_PAIR2DEADTIME_DTPS_MASK              0xC0u
#define FTM_PAIR2DEADTIME_DTPS_SHIFT             6u
#define FTM_PAIR2DEADTIME_DTPS_WIDTH             2u
#define FTM_PAIR2DEADTIME_DTPS(x)                (((uint32)(((uint32)(x))<<FTM_PAIR2DEADTIME_DTPS_SHIFT))&FTM_PAIR2DEADTIME_DTPS_MASK)
#define FTM_PAIR2DEADTIME_DTVALEX_MASK           0xF0000u
#define FTM_PAIR2DEADTIME_DTVALEX_SHIFT          16u
#define FTM_PAIR2DEADTIME_DTVALEX_WIDTH          4u
#define FTM_PAIR2DEADTIME_DTVALEX(x)             (((uint32)(((uint32)(x))<<FTM_PAIR2DEADTIME_DTVALEX_SHIFT))&FTM_PAIR2DEADTIME_DTVALEX_MASK)
/* PAIR3DEADTIME Bit Fields */
#define FTM_PAIR3DEADTIME_DTVAL_MASK             0x3Fu
#define FTM_PAIR3DEADTIME_DTVAL_SHIFT            0u
#define FTM_PAIR3DEADTIME_DTVAL_WIDTH            6u
#define FTM_PAIR3DEADTIME_DTVAL(x)               (((uint32)(((uint32)(x))<<FTM_PAIR3DEADTIME_DTVAL_SHIFT))&FTM_PAIR3DEADTIME_DTVAL_MASK)
#define FTM_PAIR3DEADTIME_DTPS_MASK              0xC0u
#define FTM_PAIR3DEADTIME_DTPS_SHIFT             6u
#define FTM_PAIR3DEADTIME_DTPS_WIDTH             2u
#define FTM_PAIR3DEADTIME_DTPS(x)                (((uint32)(((uint32)(x))<<FTM_PAIR3DEADTIME_DTPS_SHIFT))&FTM_PAIR3DEADTIME_DTPS_MASK)
#define FTM_PAIR3DEADTIME_DTVALEX_MASK           0xF0000u
#define FTM_PAIR3DEADTIME_DTVALEX_SHIFT          16u
#define FTM_PAIR3DEADTIME_DTVALEX_WIDTH          4u
#define FTM_PAIR3DEADTIME_DTVALEX(x)             (((uint32)(((uint32)(x))<<FTM_PAIR3DEADTIME_DTVALEX_SHIFT))&FTM_PAIR3DEADTIME_DTVALEX_MASK)

/*!
 * @}
 */ /* end of group FTM_Register_Masks */


/*!
 * @}
 */ /* end of group FTM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- GPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO Peripheral Access Layer
 * @{
 */


/** GPIO - Size of Registers Arrays */

/** GPIO - Register Layout Typedef */
typedef struct {
  __IO uint32 PDOR;                              /**< Port Data Output Register, offset: 0x0 */
  __O  uint32 PSOR;                              /**< Port Set Output Register, offset: 0x4 */
  __O  uint32 PCOR;                              /**< Port Clear Output Register, offset: 0x8 */
  __O  uint32 PTOR;                              /**< Port Toggle Output Register, offset: 0xC */
  __I  uint32 PDIR;                              /**< Port Data Input Register, offset: 0x10 */
  __IO uint32 PDDR;                              /**< Port Data Direction Register, offset: 0x14 */
  __IO uint32 PIDR;                              /**< Port Input Disable Register, offset: 0x18 */
} GPIO_Type, *GPIO_MemMapPtr;

 /** Number of instances of the GPIO module. */
#define GPIO_INSTANCE_COUNT                      (5u)


/* GPIO - Peripheral instance base addresses */
/** Peripheral PTA base address */
#define PTA_BASE                                 (0x400FF000u)
/** Peripheral PTA base pointer */
#define PTA                                      ((GPIO_Type *)PTA_BASE)
/** Peripheral PTB base address */
#define PTB_BASE                                 (0x400FF040u)
/** Peripheral PTB base pointer */
#define PTB                                      ((GPIO_Type *)PTB_BASE)
/** Peripheral PTC base address */
#define PTC_BASE                                 (0x400FF080u)
/** Peripheral PTC base pointer */
#define PTC                                      ((GPIO_Type *)PTC_BASE)
/** Peripheral PTD base address */
#define PTD_BASE                                 (0x400FF0C0u)
/** Peripheral PTD base pointer */
#define PTD                                      ((GPIO_Type *)PTD_BASE)
/** Peripheral PTE base address */
#define PTE_BASE                                 (0x400FF100u)
/** Peripheral PTE base pointer */
#define PTE                                      ((GPIO_Type *)PTE_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { PTA_BASE, PTB_BASE, PTC_BASE, PTD_BASE, PTE_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { PTA, PTB, PTC, PTD, PTE }

/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/* PDOR Bit Fields */
#define GPIO_PDOR_PDO_MASK                       0xFFFFFFFFu
#define GPIO_PDOR_PDO_SHIFT                      0u
#define GPIO_PDOR_PDO_WIDTH                      32u
#define GPIO_PDOR_PDO(x)                         (((uint32)(((uint32)(x))<<GPIO_PDOR_PDO_SHIFT))&GPIO_PDOR_PDO_MASK)
/* PSOR Bit Fields */
#define GPIO_PSOR_PTSO_MASK                      0xFFFFFFFFu
#define GPIO_PSOR_PTSO_SHIFT                     0u
#define GPIO_PSOR_PTSO_WIDTH                     32u
#define GPIO_PSOR_PTSO(x)                        (((uint32)(((uint32)(x))<<GPIO_PSOR_PTSO_SHIFT))&GPIO_PSOR_PTSO_MASK)
/* PCOR Bit Fields */
#define GPIO_PCOR_PTCO_MASK                      0xFFFFFFFFu
#define GPIO_PCOR_PTCO_SHIFT                     0u
#define GPIO_PCOR_PTCO_WIDTH                     32u
#define GPIO_PCOR_PTCO(x)                        (((uint32)(((uint32)(x))<<GPIO_PCOR_PTCO_SHIFT))&GPIO_PCOR_PTCO_MASK)
/* PTOR Bit Fields */
#define GPIO_PTOR_PTTO_MASK                      0xFFFFFFFFu
#define GPIO_PTOR_PTTO_SHIFT                     0u
#define GPIO_PTOR_PTTO_WIDTH                     32u
#define GPIO_PTOR_PTTO(x)                        (((uint32)(((uint32)(x))<<GPIO_PTOR_PTTO_SHIFT))&GPIO_PTOR_PTTO_MASK)
/* PDIR Bit Fields */
#define GPIO_PDIR_PDI_MASK                       0xFFFFFFFFu
#define GPIO_PDIR_PDI_SHIFT                      0u
#define GPIO_PDIR_PDI_WIDTH                      32u
#define GPIO_PDIR_PDI(x)                         (((uint32)(((uint32)(x))<<GPIO_PDIR_PDI_SHIFT))&GPIO_PDIR_PDI_MASK)
/* PDDR Bit Fields */
#define GPIO_PDDR_PDD_MASK                       0xFFFFFFFFu
#define GPIO_PDDR_PDD_SHIFT                      0u
#define GPIO_PDDR_PDD_WIDTH                      32u
#define GPIO_PDDR_PDD(x)                         (((uint32)(((uint32)(x))<<GPIO_PDDR_PDD_SHIFT))&GPIO_PDDR_PDD_MASK)
/* PIDR Bit Fields */
#define GPIO_PIDR_PID_MASK                       0xFFFFFFFFu
#define GPIO_PIDR_PID_SHIFT                      0u
#define GPIO_PIDR_PID_WIDTH                      32u
#define GPIO_PIDR_PID(x)                         (((uint32)(((uint32)(x))<<GPIO_PIDR_PID_SHIFT))&GPIO_PIDR_PID_MASK)

/*!
 * @}
 */ /* end of group GPIO_Register_Masks */


/*!
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LMEM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LMEM_Peripheral_Access_Layer LMEM Peripheral Access Layer
 * @{
 */


/** LMEM - Size of Registers Arrays */

/** LMEM - Register Layout Typedef */
typedef struct {
  __IO uint32 PCCCR;                             /**< Cache control register, offset: 0x0 */
  __IO uint32 PCCLCR;                            /**< Cache line control register, offset: 0x4 */
  __IO uint32 PCCSAR;                            /**< Cache search address register, offset: 0x8 */
  __IO uint32 PCCCVR;                            /**< Cache read/write value register, offset: 0xC */
       uint8 RESERVED_0[16];
  __IO uint32 PCCRMR;                            /**< Cache regions mode register, offset: 0x20 */
} LMEM_Type, *LMEM_MemMapPtr;

 /** Number of instances of the LMEM module. */
#define LMEM_INSTANCE_COUNT                      (1u)


/* LMEM - Peripheral instance base addresses */
/** Peripheral LMEM base address */
#define LMEM_BASE                                (0xE0082000u)
/** Peripheral LMEM base pointer */
#define LMEM                                     ((LMEM_Type *)LMEM_BASE)
/** Array initializer of LMEM peripheral base addresses */
#define LMEM_BASE_ADDRS                          { LMEM_BASE }
/** Array initializer of LMEM peripheral base pointers */
#define LMEM_BASE_PTRS                           { LMEM }

/* ----------------------------------------------------------------------------
   -- LMEM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LMEM_Register_Masks LMEM Register Masks
 * @{
 */

/* PCCCR Bit Fields */
#define LMEM_PCCCR_ENCACHE_MASK                  0x1u
#define LMEM_PCCCR_ENCACHE_SHIFT                 0u
#define LMEM_PCCCR_ENCACHE_WIDTH                 1u
#define LMEM_PCCCR_ENCACHE(x)                    (((uint32)(((uint32)(x))<<LMEM_PCCCR_ENCACHE_SHIFT))&LMEM_PCCCR_ENCACHE_MASK)
#define LMEM_PCCCR_PCCR2_MASK                    0x4u
#define LMEM_PCCCR_PCCR2_SHIFT                   2u
#define LMEM_PCCCR_PCCR2_WIDTH                   1u
#define LMEM_PCCCR_PCCR2(x)                      (((uint32)(((uint32)(x))<<LMEM_PCCCR_PCCR2_SHIFT))&LMEM_PCCCR_PCCR2_MASK)
#define LMEM_PCCCR_PCCR3_MASK                    0x8u
#define LMEM_PCCCR_PCCR3_SHIFT                   3u
#define LMEM_PCCCR_PCCR3_WIDTH                   1u
#define LMEM_PCCCR_PCCR3(x)                      (((uint32)(((uint32)(x))<<LMEM_PCCCR_PCCR3_SHIFT))&LMEM_PCCCR_PCCR3_MASK)
#define LMEM_PCCCR_INVW0_MASK                    0x1000000u
#define LMEM_PCCCR_INVW0_SHIFT                   24u
#define LMEM_PCCCR_INVW0_WIDTH                   1u
#define LMEM_PCCCR_INVW0(x)                      (((uint32)(((uint32)(x))<<LMEM_PCCCR_INVW0_SHIFT))&LMEM_PCCCR_INVW0_MASK)
#define LMEM_PCCCR_PUSHW0_MASK                   0x2000000u
#define LMEM_PCCCR_PUSHW0_SHIFT                  25u
#define LMEM_PCCCR_PUSHW0_WIDTH                  1u
#define LMEM_PCCCR_PUSHW0(x)                     (((uint32)(((uint32)(x))<<LMEM_PCCCR_PUSHW0_SHIFT))&LMEM_PCCCR_PUSHW0_MASK)
#define LMEM_PCCCR_INVW1_MASK                    0x4000000u
#define LMEM_PCCCR_INVW1_SHIFT                   26u
#define LMEM_PCCCR_INVW1_WIDTH                   1u
#define LMEM_PCCCR_INVW1(x)                      (((uint32)(((uint32)(x))<<LMEM_PCCCR_INVW1_SHIFT))&LMEM_PCCCR_INVW1_MASK)
#define LMEM_PCCCR_PUSHW1_MASK                   0x8000000u
#define LMEM_PCCCR_PUSHW1_SHIFT                  27u
#define LMEM_PCCCR_PUSHW1_WIDTH                  1u
#define LMEM_PCCCR_PUSHW1(x)                     (((uint32)(((uint32)(x))<<LMEM_PCCCR_PUSHW1_SHIFT))&LMEM_PCCCR_PUSHW1_MASK)
#define LMEM_PCCCR_GO_MASK                       0x80000000u
#define LMEM_PCCCR_GO_SHIFT                      31u
#define LMEM_PCCCR_GO_WIDTH                      1u
#define LMEM_PCCCR_GO(x)                         (((uint32)(((uint32)(x))<<LMEM_PCCCR_GO_SHIFT))&LMEM_PCCCR_GO_MASK)
/* PCCLCR Bit Fields */
#define LMEM_PCCLCR_LGO_MASK                     0x1u
#define LMEM_PCCLCR_LGO_SHIFT                    0u
#define LMEM_PCCLCR_LGO_WIDTH                    1u
#define LMEM_PCCLCR_LGO(x)                       (((uint32)(((uint32)(x))<<LMEM_PCCLCR_LGO_SHIFT))&LMEM_PCCLCR_LGO_MASK)
#define LMEM_PCCLCR_CACHEADDR_MASK               0x3FFCu
#define LMEM_PCCLCR_CACHEADDR_SHIFT              2u
#define LMEM_PCCLCR_CACHEADDR_WIDTH              12u
#define LMEM_PCCLCR_CACHEADDR(x)                 (((uint32)(((uint32)(x))<<LMEM_PCCLCR_CACHEADDR_SHIFT))&LMEM_PCCLCR_CACHEADDR_MASK)
#define LMEM_PCCLCR_WSEL_MASK                    0x4000u
#define LMEM_PCCLCR_WSEL_SHIFT                   14u
#define LMEM_PCCLCR_WSEL_WIDTH                   1u
#define LMEM_PCCLCR_WSEL(x)                      (((uint32)(((uint32)(x))<<LMEM_PCCLCR_WSEL_SHIFT))&LMEM_PCCLCR_WSEL_MASK)
#define LMEM_PCCLCR_TDSEL_MASK                   0x10000u
#define LMEM_PCCLCR_TDSEL_SHIFT                  16u
#define LMEM_PCCLCR_TDSEL_WIDTH                  1u
#define LMEM_PCCLCR_TDSEL(x)                     (((uint32)(((uint32)(x))<<LMEM_PCCLCR_TDSEL_SHIFT))&LMEM_PCCLCR_TDSEL_MASK)
#define LMEM_PCCLCR_LCIVB_MASK                   0x100000u
#define LMEM_PCCLCR_LCIVB_SHIFT                  20u
#define LMEM_PCCLCR_LCIVB_WIDTH                  1u
#define LMEM_PCCLCR_LCIVB(x)                     (((uint32)(((uint32)(x))<<LMEM_PCCLCR_LCIVB_SHIFT))&LMEM_PCCLCR_LCIVB_MASK)
#define LMEM_PCCLCR_LCIMB_MASK                   0x200000u
#define LMEM_PCCLCR_LCIMB_SHIFT                  21u
#define LMEM_PCCLCR_LCIMB_WIDTH                  1u
#define LMEM_PCCLCR_LCIMB(x)                     (((uint32)(((uint32)(x))<<LMEM_PCCLCR_LCIMB_SHIFT))&LMEM_PCCLCR_LCIMB_MASK)
#define LMEM_PCCLCR_LCWAY_MASK                   0x400000u
#define LMEM_PCCLCR_LCWAY_SHIFT                  22u
#define LMEM_PCCLCR_LCWAY_WIDTH                  1u
#define LMEM_PCCLCR_LCWAY(x)                     (((uint32)(((uint32)(x))<<LMEM_PCCLCR_LCWAY_SHIFT))&LMEM_PCCLCR_LCWAY_MASK)
#define LMEM_PCCLCR_LCMD_MASK                    0x3000000u
#define LMEM_PCCLCR_LCMD_SHIFT                   24u
#define LMEM_PCCLCR_LCMD_WIDTH                   2u
#define LMEM_PCCLCR_LCMD(x)                      (((uint32)(((uint32)(x))<<LMEM_PCCLCR_LCMD_SHIFT))&LMEM_PCCLCR_LCMD_MASK)
#define LMEM_PCCLCR_LADSEL_MASK                  0x4000000u
#define LMEM_PCCLCR_LADSEL_SHIFT                 26u
#define LMEM_PCCLCR_LADSEL_WIDTH                 1u
#define LMEM_PCCLCR_LADSEL(x)                    (((uint32)(((uint32)(x))<<LMEM_PCCLCR_LADSEL_SHIFT))&LMEM_PCCLCR_LADSEL_MASK)
#define LMEM_PCCLCR_LACC_MASK                    0x8000000u
#define LMEM_PCCLCR_LACC_SHIFT                   27u
#define LMEM_PCCLCR_LACC_WIDTH                   1u
#define LMEM_PCCLCR_LACC(x)                      (((uint32)(((uint32)(x))<<LMEM_PCCLCR_LACC_SHIFT))&LMEM_PCCLCR_LACC_MASK)
/* PCCSAR Bit Fields */
#define LMEM_PCCSAR_LGO_MASK                     0x1u
#define LMEM_PCCSAR_LGO_SHIFT                    0u
#define LMEM_PCCSAR_LGO_WIDTH                    1u
#define LMEM_PCCSAR_LGO(x)                       (((uint32)(((uint32)(x))<<LMEM_PCCSAR_LGO_SHIFT))&LMEM_PCCSAR_LGO_MASK)
#define LMEM_PCCSAR_PHYADDR_MASK                 0xFFFFFFFCu
#define LMEM_PCCSAR_PHYADDR_SHIFT                2u
#define LMEM_PCCSAR_PHYADDR_WIDTH                30u
#define LMEM_PCCSAR_PHYADDR(x)                   (((uint32)(((uint32)(x))<<LMEM_PCCSAR_PHYADDR_SHIFT))&LMEM_PCCSAR_PHYADDR_MASK)
/* PCCCVR Bit Fields */
#define LMEM_PCCCVR_DATA_MASK                    0xFFFFFFFFu
#define LMEM_PCCCVR_DATA_SHIFT                   0u
#define LMEM_PCCCVR_DATA_WIDTH                   32u
#define LMEM_PCCCVR_DATA(x)                      (((uint32)(((uint32)(x))<<LMEM_PCCCVR_DATA_SHIFT))&LMEM_PCCCVR_DATA_MASK)
/* PCCRMR Bit Fields */
#define LMEM_PCCRMR_R15_MASK                     0x3u
#define LMEM_PCCRMR_R15_SHIFT                    0u
#define LMEM_PCCRMR_R15_WIDTH                    2u
#define LMEM_PCCRMR_R15(x)                       (((uint32)(((uint32)(x))<<LMEM_PCCRMR_R15_SHIFT))&LMEM_PCCRMR_R15_MASK)
#define LMEM_PCCRMR_R14_MASK                     0xCu
#define LMEM_PCCRMR_R14_SHIFT                    2u
#define LMEM_PCCRMR_R14_WIDTH                    2u
#define LMEM_PCCRMR_R14(x)                       (((uint32)(((uint32)(x))<<LMEM_PCCRMR_R14_SHIFT))&LMEM_PCCRMR_R14_MASK)
#define LMEM_PCCRMR_R13_MASK                     0x30u
#define LMEM_PCCRMR_R13_SHIFT                    4u
#define LMEM_PCCRMR_R13_WIDTH                    2u
#define LMEM_PCCRMR_R13(x)                       (((uint32)(((uint32)(x))<<LMEM_PCCRMR_R13_SHIFT))&LMEM_PCCRMR_R13_MASK)
#define LMEM_PCCRMR_R12_MASK                     0xC0u
#define LMEM_PCCRMR_R12_SHIFT                    6u
#define LMEM_PCCRMR_R12_WIDTH                    2u
#define LMEM_PCCRMR_R12(x)                       (((uint32)(((uint32)(x))<<LMEM_PCCRMR_R12_SHIFT))&LMEM_PCCRMR_R12_MASK)
#define LMEM_PCCRMR_R11_MASK                     0x300u
#define LMEM_PCCRMR_R11_SHIFT                    8u
#define LMEM_PCCRMR_R11_WIDTH                    2u
#define LMEM_PCCRMR_R11(x)                       (((uint32)(((uint32)(x))<<LMEM_PCCRMR_R11_SHIFT))&LMEM_PCCRMR_R11_MASK)
#define LMEM_PCCRMR_R10_MASK                     0xC00u
#define LMEM_PCCRMR_R10_SHIFT                    10u
#define LMEM_PCCRMR_R10_WIDTH                    2u
#define LMEM_PCCRMR_R10(x)                       (((uint32)(((uint32)(x))<<LMEM_PCCRMR_R10_SHIFT))&LMEM_PCCRMR_R10_MASK)
#define LMEM_PCCRMR_R9_MASK                      0x3000u
#define LMEM_PCCRMR_R9_SHIFT                     12u
#define LMEM_PCCRMR_R9_WIDTH                     2u
#define LMEM_PCCRMR_R9(x)                        (((uint32)(((uint32)(x))<<LMEM_PCCRMR_R9_SHIFT))&LMEM_PCCRMR_R9_MASK)
#define LMEM_PCCRMR_R8_MASK                      0xC000u
#define LMEM_PCCRMR_R8_SHIFT                     14u
#define LMEM_PCCRMR_R8_WIDTH                     2u
#define LMEM_PCCRMR_R8(x)                        (((uint32)(((uint32)(x))<<LMEM_PCCRMR_R8_SHIFT))&LMEM_PCCRMR_R8_MASK)
#define LMEM_PCCRMR_R7_MASK                      0x30000u
#define LMEM_PCCRMR_R7_SHIFT                     16u
#define LMEM_PCCRMR_R7_WIDTH                     2u
#define LMEM_PCCRMR_R7(x)                        (((uint32)(((uint32)(x))<<LMEM_PCCRMR_R7_SHIFT))&LMEM_PCCRMR_R7_MASK)
#define LMEM_PCCRMR_R6_MASK                      0xC0000u
#define LMEM_PCCRMR_R6_SHIFT                     18u
#define LMEM_PCCRMR_R6_WIDTH                     2u
#define LMEM_PCCRMR_R6(x)                        (((uint32)(((uint32)(x))<<LMEM_PCCRMR_R6_SHIFT))&LMEM_PCCRMR_R6_MASK)
#define LMEM_PCCRMR_R5_MASK                      0x300000u
#define LMEM_PCCRMR_R5_SHIFT                     20u
#define LMEM_PCCRMR_R5_WIDTH                     2u
#define LMEM_PCCRMR_R5(x)                        (((uint32)(((uint32)(x))<<LMEM_PCCRMR_R5_SHIFT))&LMEM_PCCRMR_R5_MASK)
#define LMEM_PCCRMR_R4_MASK                      0xC00000u
#define LMEM_PCCRMR_R4_SHIFT                     22u
#define LMEM_PCCRMR_R4_WIDTH                     2u
#define LMEM_PCCRMR_R4(x)                        (((uint32)(((uint32)(x))<<LMEM_PCCRMR_R4_SHIFT))&LMEM_PCCRMR_R4_MASK)
#define LMEM_PCCRMR_R3_MASK                      0x3000000u
#define LMEM_PCCRMR_R3_SHIFT                     24u
#define LMEM_PCCRMR_R3_WIDTH                     2u
#define LMEM_PCCRMR_R3(x)                        (((uint32)(((uint32)(x))<<LMEM_PCCRMR_R3_SHIFT))&LMEM_PCCRMR_R3_MASK)
#define LMEM_PCCRMR_R2_MASK                      0xC000000u
#define LMEM_PCCRMR_R2_SHIFT                     26u
#define LMEM_PCCRMR_R2_WIDTH                     2u
#define LMEM_PCCRMR_R2(x)                        (((uint32)(((uint32)(x))<<LMEM_PCCRMR_R2_SHIFT))&LMEM_PCCRMR_R2_MASK)
#define LMEM_PCCRMR_R1_MASK                      0x30000000u
#define LMEM_PCCRMR_R1_SHIFT                     28u
#define LMEM_PCCRMR_R1_WIDTH                     2u
#define LMEM_PCCRMR_R1(x)                        (((uint32)(((uint32)(x))<<LMEM_PCCRMR_R1_SHIFT))&LMEM_PCCRMR_R1_MASK)
#define LMEM_PCCRMR_R0_MASK                      0xC0000000u
#define LMEM_PCCRMR_R0_SHIFT                     30u
#define LMEM_PCCRMR_R0_WIDTH                     2u
#define LMEM_PCCRMR_R0(x)                        (((uint32)(((uint32)(x))<<LMEM_PCCRMR_R0_SHIFT))&LMEM_PCCRMR_R0_MASK)

/*!
 * @}
 */ /* end of group LMEM_Register_Masks */


/*!
 * @}
 */ /* end of group LMEM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPI2C Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPI2C_Peripheral_Access_Layer LPI2C Peripheral Access Layer
 * @{
 */


/** LPI2C - Size of Registers Arrays */

/** LPI2C - Register Layout Typedef */
typedef struct {
  __I  uint32 VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32 PARAM;                             /**< Parameter Register, offset: 0x4 */
       uint8 RESERVED_0[8];
  __IO uint32 MCR;                               /**< Master Control Register, offset: 0x10 */
  __IO uint32 MSR;                               /**< Master Status Register, offset: 0x14 */
  __IO uint32 MIER;                              /**< Master Interrupt Enable Register, offset: 0x18 */
  __IO uint32 MDER;                              /**< Master DMA Enable Register, offset: 0x1C */
  __IO uint32 MCFGR0;                            /**< Master Configuration Register 0, offset: 0x20 */
  __IO uint32 MCFGR1;                            /**< Master Configuration Register 1, offset: 0x24 */
  __IO uint32 MCFGR2;                            /**< Master Configuration Register 2, offset: 0x28 */
  __IO uint32 MCFGR3;                            /**< Master Configuration Register 3, offset: 0x2C */
       uint8 RESERVED_1[16];
  __IO uint32 MDMR;                              /**< Master Data Match Register, offset: 0x40 */
       uint8 RESERVED_2[4];
  __IO uint32 MCCR0;                             /**< Master Clock Configuration Register 0, offset: 0x48 */
       uint8 RESERVED_3[4];
  __IO uint32 MCCR1;                             /**< Master Clock Configuration Register 1, offset: 0x50 */
       uint8 RESERVED_4[4];
  __IO uint32 MFCR;                              /**< Master FIFO Control Register, offset: 0x58 */
  __I  uint32 MFSR;                              /**< Master FIFO Status Register, offset: 0x5C */
  __IO uint32 MTDR;                              /**< Master Transmit Data Register, offset: 0x60 */
       uint8 RESERVED_5[12];
  __I  uint32 MRDR;                              /**< Master Receive Data Register, offset: 0x70 */
       uint8 RESERVED_6[156];
  __IO uint32 SCR;                               /**< Slave Control Register, offset: 0x110 */
  __IO uint32 SSR;                               /**< Slave Status Register, offset: 0x114 */
  __IO uint32 SIER;                              /**< Slave Interrupt Enable Register, offset: 0x118 */
  __IO uint32 SDER;                              /**< Slave DMA Enable Register, offset: 0x11C */
       uint8 RESERVED_7[4];
  __IO uint32 SCFGR1;                            /**< Slave Configuration Register 1, offset: 0x124 */
  __IO uint32 SCFGR2;                            /**< Slave Configuration Register 2, offset: 0x128 */
       uint8 RESERVED_8[20];
  __IO uint32 SAMR;                              /**< Slave Address Match Register, offset: 0x140 */
       uint8 RESERVED_9[12];
  __I  uint32 SASR;                              /**< Slave Address Status Register, offset: 0x150 */
  __IO uint32 STAR;                              /**< Slave Transmit ACK Register, offset: 0x154 */
       uint8 RESERVED_10[8];
  __IO uint32 STDR;                              /**< Slave Transmit Data Register, offset: 0x160 */
       uint8 RESERVED_11[12];
  __I  uint32 SRDR;                              /**< Slave Receive Data Register, offset: 0x170 */
} LPI2C_Type, *LPI2C_MemMapPtr;

 /** Number of instances of the LPI2C module. */
#define LPI2C_INSTANCE_COUNT                     (1u)


/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C0 base address */
#define LPI2C0_BASE                              (0x40066000u)
/** Peripheral LPI2C0 base pointer */
#define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { LPI2C0_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { LPI2C0 }
 /** Number of interrupt vector arrays for the LPI2C module. */
#define LPI2C_IRQS_ARR_COUNT                     (2u)
 /** Number of interrupt channels for the MASTER type of LPI2C module. */
#define LPI2C_MASTER_IRQS_CH_COUNT               (1u)
 /** Number of interrupt channels for the SLAVE type of LPI2C module. */
#define LPI2C_SLAVE_IRQS_CH_COUNT                (1u)
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_MASTER_IRQS                        { LPI2C0_Master_IRQn }
#define LPI2C_SLAVE_IRQS                         { LPI2C0_Slave_IRQn }

/* ----------------------------------------------------------------------------
   -- LPI2C Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPI2C_Register_Masks LPI2C Register Masks
 * @{
 */

/* VERID Bit Fields */
#define LPI2C_VERID_FEATURE_MASK                 0xFFFFu
#define LPI2C_VERID_FEATURE_SHIFT                0u
#define LPI2C_VERID_FEATURE_WIDTH                16u
#define LPI2C_VERID_FEATURE(x)                   (((uint32)(((uint32)(x))<<LPI2C_VERID_FEATURE_SHIFT))&LPI2C_VERID_FEATURE_MASK)
#define LPI2C_VERID_MINOR_MASK                   0xFF0000u
#define LPI2C_VERID_MINOR_SHIFT                  16u
#define LPI2C_VERID_MINOR_WIDTH                  8u
#define LPI2C_VERID_MINOR(x)                     (((uint32)(((uint32)(x))<<LPI2C_VERID_MINOR_SHIFT))&LPI2C_VERID_MINOR_MASK)
#define LPI2C_VERID_MAJOR_MASK                   0xFF000000u
#define LPI2C_VERID_MAJOR_SHIFT                  24u
#define LPI2C_VERID_MAJOR_WIDTH                  8u
#define LPI2C_VERID_MAJOR(x)                     (((uint32)(((uint32)(x))<<LPI2C_VERID_MAJOR_SHIFT))&LPI2C_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define LPI2C_PARAM_MTXFIFO_MASK                 0xFu
#define LPI2C_PARAM_MTXFIFO_SHIFT                0u
#define LPI2C_PARAM_MTXFIFO_WIDTH                4u
#define LPI2C_PARAM_MTXFIFO(x)                   (((uint32)(((uint32)(x))<<LPI2C_PARAM_MTXFIFO_SHIFT))&LPI2C_PARAM_MTXFIFO_MASK)
#define LPI2C_PARAM_MRXFIFO_MASK                 0xF00u
#define LPI2C_PARAM_MRXFIFO_SHIFT                8u
#define LPI2C_PARAM_MRXFIFO_WIDTH                4u
#define LPI2C_PARAM_MRXFIFO(x)                   (((uint32)(((uint32)(x))<<LPI2C_PARAM_MRXFIFO_SHIFT))&LPI2C_PARAM_MRXFIFO_MASK)
/* MCR Bit Fields */
#define LPI2C_MCR_MEN_MASK                       0x1u
#define LPI2C_MCR_MEN_SHIFT                      0u
#define LPI2C_MCR_MEN_WIDTH                      1u
#define LPI2C_MCR_MEN(x)                         (((uint32)(((uint32)(x))<<LPI2C_MCR_MEN_SHIFT))&LPI2C_MCR_MEN_MASK)
#define LPI2C_MCR_RST_MASK                       0x2u
#define LPI2C_MCR_RST_SHIFT                      1u
#define LPI2C_MCR_RST_WIDTH                      1u
#define LPI2C_MCR_RST(x)                         (((uint32)(((uint32)(x))<<LPI2C_MCR_RST_SHIFT))&LPI2C_MCR_RST_MASK)
#define LPI2C_MCR_DOZEN_MASK                     0x4u
#define LPI2C_MCR_DOZEN_SHIFT                    2u
#define LPI2C_MCR_DOZEN_WIDTH                    1u
#define LPI2C_MCR_DOZEN(x)                       (((uint32)(((uint32)(x))<<LPI2C_MCR_DOZEN_SHIFT))&LPI2C_MCR_DOZEN_MASK)
#define LPI2C_MCR_DBGEN_MASK                     0x8u
#define LPI2C_MCR_DBGEN_SHIFT                    3u
#define LPI2C_MCR_DBGEN_WIDTH                    1u
#define LPI2C_MCR_DBGEN(x)                       (((uint32)(((uint32)(x))<<LPI2C_MCR_DBGEN_SHIFT))&LPI2C_MCR_DBGEN_MASK)
#define LPI2C_MCR_RTF_MASK                       0x100u
#define LPI2C_MCR_RTF_SHIFT                      8u
#define LPI2C_MCR_RTF_WIDTH                      1u
#define LPI2C_MCR_RTF(x)                         (((uint32)(((uint32)(x))<<LPI2C_MCR_RTF_SHIFT))&LPI2C_MCR_RTF_MASK)
#define LPI2C_MCR_RRF_MASK                       0x200u
#define LPI2C_MCR_RRF_SHIFT                      9u
#define LPI2C_MCR_RRF_WIDTH                      1u
#define LPI2C_MCR_RRF(x)                         (((uint32)(((uint32)(x))<<LPI2C_MCR_RRF_SHIFT))&LPI2C_MCR_RRF_MASK)
/* MSR Bit Fields */
#define LPI2C_MSR_TDF_MASK                       0x1u
#define LPI2C_MSR_TDF_SHIFT                      0u
#define LPI2C_MSR_TDF_WIDTH                      1u
#define LPI2C_MSR_TDF(x)                         (((uint32)(((uint32)(x))<<LPI2C_MSR_TDF_SHIFT))&LPI2C_MSR_TDF_MASK)
#define LPI2C_MSR_RDF_MASK                       0x2u
#define LPI2C_MSR_RDF_SHIFT                      1u
#define LPI2C_MSR_RDF_WIDTH                      1u
#define LPI2C_MSR_RDF(x)                         (((uint32)(((uint32)(x))<<LPI2C_MSR_RDF_SHIFT))&LPI2C_MSR_RDF_MASK)
#define LPI2C_MSR_EPF_MASK                       0x100u
#define LPI2C_MSR_EPF_SHIFT                      8u
#define LPI2C_MSR_EPF_WIDTH                      1u
#define LPI2C_MSR_EPF(x)                         (((uint32)(((uint32)(x))<<LPI2C_MSR_EPF_SHIFT))&LPI2C_MSR_EPF_MASK)
#define LPI2C_MSR_SDF_MASK                       0x200u
#define LPI2C_MSR_SDF_SHIFT                      9u
#define LPI2C_MSR_SDF_WIDTH                      1u
#define LPI2C_MSR_SDF(x)                         (((uint32)(((uint32)(x))<<LPI2C_MSR_SDF_SHIFT))&LPI2C_MSR_SDF_MASK)
#define LPI2C_MSR_NDF_MASK                       0x400u
#define LPI2C_MSR_NDF_SHIFT                      10u
#define LPI2C_MSR_NDF_WIDTH                      1u
#define LPI2C_MSR_NDF(x)                         (((uint32)(((uint32)(x))<<LPI2C_MSR_NDF_SHIFT))&LPI2C_MSR_NDF_MASK)
#define LPI2C_MSR_ALF_MASK                       0x800u
#define LPI2C_MSR_ALF_SHIFT                      11u
#define LPI2C_MSR_ALF_WIDTH                      1u
#define LPI2C_MSR_ALF(x)                         (((uint32)(((uint32)(x))<<LPI2C_MSR_ALF_SHIFT))&LPI2C_MSR_ALF_MASK)
#define LPI2C_MSR_FEF_MASK                       0x1000u
#define LPI2C_MSR_FEF_SHIFT                      12u
#define LPI2C_MSR_FEF_WIDTH                      1u
#define LPI2C_MSR_FEF(x)                         (((uint32)(((uint32)(x))<<LPI2C_MSR_FEF_SHIFT))&LPI2C_MSR_FEF_MASK)
#define LPI2C_MSR_PLTF_MASK                      0x2000u
#define LPI2C_MSR_PLTF_SHIFT                     13u
#define LPI2C_MSR_PLTF_WIDTH                     1u
#define LPI2C_MSR_PLTF(x)                        (((uint32)(((uint32)(x))<<LPI2C_MSR_PLTF_SHIFT))&LPI2C_MSR_PLTF_MASK)
#define LPI2C_MSR_DMF_MASK                       0x4000u
#define LPI2C_MSR_DMF_SHIFT                      14u
#define LPI2C_MSR_DMF_WIDTH                      1u
#define LPI2C_MSR_DMF(x)                         (((uint32)(((uint32)(x))<<LPI2C_MSR_DMF_SHIFT))&LPI2C_MSR_DMF_MASK)
#define LPI2C_MSR_MBF_MASK                       0x1000000u
#define LPI2C_MSR_MBF_SHIFT                      24u
#define LPI2C_MSR_MBF_WIDTH                      1u
#define LPI2C_MSR_MBF(x)                         (((uint32)(((uint32)(x))<<LPI2C_MSR_MBF_SHIFT))&LPI2C_MSR_MBF_MASK)
#define LPI2C_MSR_BBF_MASK                       0x2000000u
#define LPI2C_MSR_BBF_SHIFT                      25u
#define LPI2C_MSR_BBF_WIDTH                      1u
#define LPI2C_MSR_BBF(x)                         (((uint32)(((uint32)(x))<<LPI2C_MSR_BBF_SHIFT))&LPI2C_MSR_BBF_MASK)
/* MIER Bit Fields */
#define LPI2C_MIER_TDIE_MASK                     0x1u
#define LPI2C_MIER_TDIE_SHIFT                    0u
#define LPI2C_MIER_TDIE_WIDTH                    1u
#define LPI2C_MIER_TDIE(x)                       (((uint32)(((uint32)(x))<<LPI2C_MIER_TDIE_SHIFT))&LPI2C_MIER_TDIE_MASK)
#define LPI2C_MIER_RDIE_MASK                     0x2u
#define LPI2C_MIER_RDIE_SHIFT                    1u
#define LPI2C_MIER_RDIE_WIDTH                    1u
#define LPI2C_MIER_RDIE(x)                       (((uint32)(((uint32)(x))<<LPI2C_MIER_RDIE_SHIFT))&LPI2C_MIER_RDIE_MASK)
#define LPI2C_MIER_EPIE_MASK                     0x100u
#define LPI2C_MIER_EPIE_SHIFT                    8u
#define LPI2C_MIER_EPIE_WIDTH                    1u
#define LPI2C_MIER_EPIE(x)                       (((uint32)(((uint32)(x))<<LPI2C_MIER_EPIE_SHIFT))&LPI2C_MIER_EPIE_MASK)
#define LPI2C_MIER_SDIE_MASK                     0x200u
#define LPI2C_MIER_SDIE_SHIFT                    9u
#define LPI2C_MIER_SDIE_WIDTH                    1u
#define LPI2C_MIER_SDIE(x)                       (((uint32)(((uint32)(x))<<LPI2C_MIER_SDIE_SHIFT))&LPI2C_MIER_SDIE_MASK)
#define LPI2C_MIER_NDIE_MASK                     0x400u
#define LPI2C_MIER_NDIE_SHIFT                    10u
#define LPI2C_MIER_NDIE_WIDTH                    1u
#define LPI2C_MIER_NDIE(x)                       (((uint32)(((uint32)(x))<<LPI2C_MIER_NDIE_SHIFT))&LPI2C_MIER_NDIE_MASK)
#define LPI2C_MIER_ALIE_MASK                     0x800u
#define LPI2C_MIER_ALIE_SHIFT                    11u
#define LPI2C_MIER_ALIE_WIDTH                    1u
#define LPI2C_MIER_ALIE(x)                       (((uint32)(((uint32)(x))<<LPI2C_MIER_ALIE_SHIFT))&LPI2C_MIER_ALIE_MASK)
#define LPI2C_MIER_FEIE_MASK                     0x1000u
#define LPI2C_MIER_FEIE_SHIFT                    12u
#define LPI2C_MIER_FEIE_WIDTH                    1u
#define LPI2C_MIER_FEIE(x)                       (((uint32)(((uint32)(x))<<LPI2C_MIER_FEIE_SHIFT))&LPI2C_MIER_FEIE_MASK)
#define LPI2C_MIER_PLTIE_MASK                    0x2000u
#define LPI2C_MIER_PLTIE_SHIFT                   13u
#define LPI2C_MIER_PLTIE_WIDTH                   1u
#define LPI2C_MIER_PLTIE(x)                      (((uint32)(((uint32)(x))<<LPI2C_MIER_PLTIE_SHIFT))&LPI2C_MIER_PLTIE_MASK)
#define LPI2C_MIER_DMIE_MASK                     0x4000u
#define LPI2C_MIER_DMIE_SHIFT                    14u
#define LPI2C_MIER_DMIE_WIDTH                    1u
#define LPI2C_MIER_DMIE(x)                       (((uint32)(((uint32)(x))<<LPI2C_MIER_DMIE_SHIFT))&LPI2C_MIER_DMIE_MASK)
/* MDER Bit Fields */
#define LPI2C_MDER_TDDE_MASK                     0x1u
#define LPI2C_MDER_TDDE_SHIFT                    0u
#define LPI2C_MDER_TDDE_WIDTH                    1u
#define LPI2C_MDER_TDDE(x)                       (((uint32)(((uint32)(x))<<LPI2C_MDER_TDDE_SHIFT))&LPI2C_MDER_TDDE_MASK)
#define LPI2C_MDER_RDDE_MASK                     0x2u
#define LPI2C_MDER_RDDE_SHIFT                    1u
#define LPI2C_MDER_RDDE_WIDTH                    1u
#define LPI2C_MDER_RDDE(x)                       (((uint32)(((uint32)(x))<<LPI2C_MDER_RDDE_SHIFT))&LPI2C_MDER_RDDE_MASK)
/* MCFGR0 Bit Fields */
#define LPI2C_MCFGR0_HREN_MASK                   0x1u
#define LPI2C_MCFGR0_HREN_SHIFT                  0u
#define LPI2C_MCFGR0_HREN_WIDTH                  1u
#define LPI2C_MCFGR0_HREN(x)                     (((uint32)(((uint32)(x))<<LPI2C_MCFGR0_HREN_SHIFT))&LPI2C_MCFGR0_HREN_MASK)
#define LPI2C_MCFGR0_HRPOL_MASK                  0x2u
#define LPI2C_MCFGR0_HRPOL_SHIFT                 1u
#define LPI2C_MCFGR0_HRPOL_WIDTH                 1u
#define LPI2C_MCFGR0_HRPOL(x)                    (((uint32)(((uint32)(x))<<LPI2C_MCFGR0_HRPOL_SHIFT))&LPI2C_MCFGR0_HRPOL_MASK)
#define LPI2C_MCFGR0_HRSEL_MASK                  0x4u
#define LPI2C_MCFGR0_HRSEL_SHIFT                 2u
#define LPI2C_MCFGR0_HRSEL_WIDTH                 1u
#define LPI2C_MCFGR0_HRSEL(x)                    (((uint32)(((uint32)(x))<<LPI2C_MCFGR0_HRSEL_SHIFT))&LPI2C_MCFGR0_HRSEL_MASK)
#define LPI2C_MCFGR0_CIRFIFO_MASK                0x100u
#define LPI2C_MCFGR0_CIRFIFO_SHIFT               8u
#define LPI2C_MCFGR0_CIRFIFO_WIDTH               1u
#define LPI2C_MCFGR0_CIRFIFO(x)                  (((uint32)(((uint32)(x))<<LPI2C_MCFGR0_CIRFIFO_SHIFT))&LPI2C_MCFGR0_CIRFIFO_MASK)
#define LPI2C_MCFGR0_RDMO_MASK                   0x200u
#define LPI2C_MCFGR0_RDMO_SHIFT                  9u
#define LPI2C_MCFGR0_RDMO_WIDTH                  1u
#define LPI2C_MCFGR0_RDMO(x)                     (((uint32)(((uint32)(x))<<LPI2C_MCFGR0_RDMO_SHIFT))&LPI2C_MCFGR0_RDMO_MASK)
/* MCFGR1 Bit Fields */
#define LPI2C_MCFGR1_PRESCALE_MASK               0x7u
#define LPI2C_MCFGR1_PRESCALE_SHIFT              0u
#define LPI2C_MCFGR1_PRESCALE_WIDTH              3u
#define LPI2C_MCFGR1_PRESCALE(x)                 (((uint32)(((uint32)(x))<<LPI2C_MCFGR1_PRESCALE_SHIFT))&LPI2C_MCFGR1_PRESCALE_MASK)
#define LPI2C_MCFGR1_AUTOSTOP_MASK               0x100u
#define LPI2C_MCFGR1_AUTOSTOP_SHIFT              8u
#define LPI2C_MCFGR1_AUTOSTOP_WIDTH              1u
#define LPI2C_MCFGR1_AUTOSTOP(x)                 (((uint32)(((uint32)(x))<<LPI2C_MCFGR1_AUTOSTOP_SHIFT))&LPI2C_MCFGR1_AUTOSTOP_MASK)
#define LPI2C_MCFGR1_IGNACK_MASK                 0x200u
#define LPI2C_MCFGR1_IGNACK_SHIFT                9u
#define LPI2C_MCFGR1_IGNACK_WIDTH                1u
#define LPI2C_MCFGR1_IGNACK(x)                   (((uint32)(((uint32)(x))<<LPI2C_MCFGR1_IGNACK_SHIFT))&LPI2C_MCFGR1_IGNACK_MASK)
#define LPI2C_MCFGR1_TIMECFG_MASK                0x400u
#define LPI2C_MCFGR1_TIMECFG_SHIFT               10u
#define LPI2C_MCFGR1_TIMECFG_WIDTH               1u
#define LPI2C_MCFGR1_TIMECFG(x)                  (((uint32)(((uint32)(x))<<LPI2C_MCFGR1_TIMECFG_SHIFT))&LPI2C_MCFGR1_TIMECFG_MASK)
#define LPI2C_MCFGR1_MATCFG_MASK                 0x70000u
#define LPI2C_MCFGR1_MATCFG_SHIFT                16u
#define LPI2C_MCFGR1_MATCFG_WIDTH                3u
#define LPI2C_MCFGR1_MATCFG(x)                   (((uint32)(((uint32)(x))<<LPI2C_MCFGR1_MATCFG_SHIFT))&LPI2C_MCFGR1_MATCFG_MASK)
#define LPI2C_MCFGR1_PINCFG_MASK                 0x7000000u
#define LPI2C_MCFGR1_PINCFG_SHIFT                24u
#define LPI2C_MCFGR1_PINCFG_WIDTH                3u
#define LPI2C_MCFGR1_PINCFG(x)                   (((uint32)(((uint32)(x))<<LPI2C_MCFGR1_PINCFG_SHIFT))&LPI2C_MCFGR1_PINCFG_MASK)
/* MCFGR2 Bit Fields */
#define LPI2C_MCFGR2_BUSIDLE_MASK                0xFFFu
#define LPI2C_MCFGR2_BUSIDLE_SHIFT               0u
#define LPI2C_MCFGR2_BUSIDLE_WIDTH               12u
#define LPI2C_MCFGR2_BUSIDLE(x)                  (((uint32)(((uint32)(x))<<LPI2C_MCFGR2_BUSIDLE_SHIFT))&LPI2C_MCFGR2_BUSIDLE_MASK)
#define LPI2C_MCFGR2_FILTSCL_MASK                0xF0000u
#define LPI2C_MCFGR2_FILTSCL_SHIFT               16u
#define LPI2C_MCFGR2_FILTSCL_WIDTH               4u
#define LPI2C_MCFGR2_FILTSCL(x)                  (((uint32)(((uint32)(x))<<LPI2C_MCFGR2_FILTSCL_SHIFT))&LPI2C_MCFGR2_FILTSCL_MASK)
#define LPI2C_MCFGR2_FILTSDA_MASK                0xF000000u
#define LPI2C_MCFGR2_FILTSDA_SHIFT               24u
#define LPI2C_MCFGR2_FILTSDA_WIDTH               4u
#define LPI2C_MCFGR2_FILTSDA(x)                  (((uint32)(((uint32)(x))<<LPI2C_MCFGR2_FILTSDA_SHIFT))&LPI2C_MCFGR2_FILTSDA_MASK)
/* MCFGR3 Bit Fields */
#define LPI2C_MCFGR3_PINLOW_MASK                 0xFFF00u
#define LPI2C_MCFGR3_PINLOW_SHIFT                8u
#define LPI2C_MCFGR3_PINLOW_WIDTH                12u
#define LPI2C_MCFGR3_PINLOW(x)                   (((uint32)(((uint32)(x))<<LPI2C_MCFGR3_PINLOW_SHIFT))&LPI2C_MCFGR3_PINLOW_MASK)
/* MDMR Bit Fields */
#define LPI2C_MDMR_MATCH0_MASK                   0xFFu
#define LPI2C_MDMR_MATCH0_SHIFT                  0u
#define LPI2C_MDMR_MATCH0_WIDTH                  8u
#define LPI2C_MDMR_MATCH0(x)                     (((uint32)(((uint32)(x))<<LPI2C_MDMR_MATCH0_SHIFT))&LPI2C_MDMR_MATCH0_MASK)
#define LPI2C_MDMR_MATCH1_MASK                   0xFF0000u
#define LPI2C_MDMR_MATCH1_SHIFT                  16u
#define LPI2C_MDMR_MATCH1_WIDTH                  8u
#define LPI2C_MDMR_MATCH1(x)                     (((uint32)(((uint32)(x))<<LPI2C_MDMR_MATCH1_SHIFT))&LPI2C_MDMR_MATCH1_MASK)
/* MCCR0 Bit Fields */
#define LPI2C_MCCR0_CLKLO_MASK                   0x3Fu
#define LPI2C_MCCR0_CLKLO_SHIFT                  0u
#define LPI2C_MCCR0_CLKLO_WIDTH                  6u
#define LPI2C_MCCR0_CLKLO(x)                     (((uint32)(((uint32)(x))<<LPI2C_MCCR0_CLKLO_SHIFT))&LPI2C_MCCR0_CLKLO_MASK)
#define LPI2C_MCCR0_CLKHI_MASK                   0x3F00u
#define LPI2C_MCCR0_CLKHI_SHIFT                  8u
#define LPI2C_MCCR0_CLKHI_WIDTH                  6u
#define LPI2C_MCCR0_CLKHI(x)                     (((uint32)(((uint32)(x))<<LPI2C_MCCR0_CLKHI_SHIFT))&LPI2C_MCCR0_CLKHI_MASK)
#define LPI2C_MCCR0_SETHOLD_MASK                 0x3F0000u
#define LPI2C_MCCR0_SETHOLD_SHIFT                16u
#define LPI2C_MCCR0_SETHOLD_WIDTH                6u
#define LPI2C_MCCR0_SETHOLD(x)                   (((uint32)(((uint32)(x))<<LPI2C_MCCR0_SETHOLD_SHIFT))&LPI2C_MCCR0_SETHOLD_MASK)
#define LPI2C_MCCR0_DATAVD_MASK                  0x3F000000u
#define LPI2C_MCCR0_DATAVD_SHIFT                 24u
#define LPI2C_MCCR0_DATAVD_WIDTH                 6u
#define LPI2C_MCCR0_DATAVD(x)                    (((uint32)(((uint32)(x))<<LPI2C_MCCR0_DATAVD_SHIFT))&LPI2C_MCCR0_DATAVD_MASK)
/* MCCR1 Bit Fields */
#define LPI2C_MCCR1_CLKLO_MASK                   0x3Fu
#define LPI2C_MCCR1_CLKLO_SHIFT                  0u
#define LPI2C_MCCR1_CLKLO_WIDTH                  6u
#define LPI2C_MCCR1_CLKLO(x)                     (((uint32)(((uint32)(x))<<LPI2C_MCCR1_CLKLO_SHIFT))&LPI2C_MCCR1_CLKLO_MASK)
#define LPI2C_MCCR1_CLKHI_MASK                   0x3F00u
#define LPI2C_MCCR1_CLKHI_SHIFT                  8u
#define LPI2C_MCCR1_CLKHI_WIDTH                  6u
#define LPI2C_MCCR1_CLKHI(x)                     (((uint32)(((uint32)(x))<<LPI2C_MCCR1_CLKHI_SHIFT))&LPI2C_MCCR1_CLKHI_MASK)
#define LPI2C_MCCR1_SETHOLD_MASK                 0x3F0000u
#define LPI2C_MCCR1_SETHOLD_SHIFT                16u
#define LPI2C_MCCR1_SETHOLD_WIDTH                6u
#define LPI2C_MCCR1_SETHOLD(x)                   (((uint32)(((uint32)(x))<<LPI2C_MCCR1_SETHOLD_SHIFT))&LPI2C_MCCR1_SETHOLD_MASK)
#define LPI2C_MCCR1_DATAVD_MASK                  0x3F000000u
#define LPI2C_MCCR1_DATAVD_SHIFT                 24u
#define LPI2C_MCCR1_DATAVD_WIDTH                 6u
#define LPI2C_MCCR1_DATAVD(x)                    (((uint32)(((uint32)(x))<<LPI2C_MCCR1_DATAVD_SHIFT))&LPI2C_MCCR1_DATAVD_MASK)
/* MFCR Bit Fields */
#define LPI2C_MFCR_TXWATER_MASK                  0x3u
#define LPI2C_MFCR_TXWATER_SHIFT                 0u
#define LPI2C_MFCR_TXWATER_WIDTH                 2u
#define LPI2C_MFCR_TXWATER(x)                    (((uint32)(((uint32)(x))<<LPI2C_MFCR_TXWATER_SHIFT))&LPI2C_MFCR_TXWATER_MASK)
#define LPI2C_MFCR_RXWATER_MASK                  0x30000u
#define LPI2C_MFCR_RXWATER_SHIFT                 16u
#define LPI2C_MFCR_RXWATER_WIDTH                 2u
#define LPI2C_MFCR_RXWATER(x)                    (((uint32)(((uint32)(x))<<LPI2C_MFCR_RXWATER_SHIFT))&LPI2C_MFCR_RXWATER_MASK)
/* MFSR Bit Fields */
#define LPI2C_MFSR_TXCOUNT_MASK                  0x7u
#define LPI2C_MFSR_TXCOUNT_SHIFT                 0u
#define LPI2C_MFSR_TXCOUNT_WIDTH                 3u
#define LPI2C_MFSR_TXCOUNT(x)                    (((uint32)(((uint32)(x))<<LPI2C_MFSR_TXCOUNT_SHIFT))&LPI2C_MFSR_TXCOUNT_MASK)
#define LPI2C_MFSR_RXCOUNT_MASK                  0x70000u
#define LPI2C_MFSR_RXCOUNT_SHIFT                 16u
#define LPI2C_MFSR_RXCOUNT_WIDTH                 3u
#define LPI2C_MFSR_RXCOUNT(x)                    (((uint32)(((uint32)(x))<<LPI2C_MFSR_RXCOUNT_SHIFT))&LPI2C_MFSR_RXCOUNT_MASK)
/* MTDR Bit Fields */
#define LPI2C_MTDR_DATA_MASK                     0xFFu
#define LPI2C_MTDR_DATA_SHIFT                    0u
#define LPI2C_MTDR_DATA_WIDTH                    8u
#define LPI2C_MTDR_DATA(x)                       (((uint32)(((uint32)(x))<<LPI2C_MTDR_DATA_SHIFT))&LPI2C_MTDR_DATA_MASK)
#define LPI2C_MTDR_CMD_MASK                      0x700u
#define LPI2C_MTDR_CMD_SHIFT                     8u
#define LPI2C_MTDR_CMD_WIDTH                     3u
#define LPI2C_MTDR_CMD(x)                        (((uint32)(((uint32)(x))<<LPI2C_MTDR_CMD_SHIFT))&LPI2C_MTDR_CMD_MASK)
/* MRDR Bit Fields */
#define LPI2C_MRDR_DATA_MASK                     0xFFu
#define LPI2C_MRDR_DATA_SHIFT                    0u
#define LPI2C_MRDR_DATA_WIDTH                    8u
#define LPI2C_MRDR_DATA(x)                       (((uint32)(((uint32)(x))<<LPI2C_MRDR_DATA_SHIFT))&LPI2C_MRDR_DATA_MASK)
#define LPI2C_MRDR_RXEMPTY_MASK                  0x4000u
#define LPI2C_MRDR_RXEMPTY_SHIFT                 14u
#define LPI2C_MRDR_RXEMPTY_WIDTH                 1u
#define LPI2C_MRDR_RXEMPTY(x)                    (((uint32)(((uint32)(x))<<LPI2C_MRDR_RXEMPTY_SHIFT))&LPI2C_MRDR_RXEMPTY_MASK)
/* SCR Bit Fields */
#define LPI2C_SCR_SEN_MASK                       0x1u
#define LPI2C_SCR_SEN_SHIFT                      0u
#define LPI2C_SCR_SEN_WIDTH                      1u
#define LPI2C_SCR_SEN(x)                         (((uint32)(((uint32)(x))<<LPI2C_SCR_SEN_SHIFT))&LPI2C_SCR_SEN_MASK)
#define LPI2C_SCR_RST_MASK                       0x2u
#define LPI2C_SCR_RST_SHIFT                      1u
#define LPI2C_SCR_RST_WIDTH                      1u
#define LPI2C_SCR_RST(x)                         (((uint32)(((uint32)(x))<<LPI2C_SCR_RST_SHIFT))&LPI2C_SCR_RST_MASK)
#define LPI2C_SCR_FILTEN_MASK                    0x10u
#define LPI2C_SCR_FILTEN_SHIFT                   4u
#define LPI2C_SCR_FILTEN_WIDTH                   1u
#define LPI2C_SCR_FILTEN(x)                      (((uint32)(((uint32)(x))<<LPI2C_SCR_FILTEN_SHIFT))&LPI2C_SCR_FILTEN_MASK)
#define LPI2C_SCR_FILTDZ_MASK                    0x20u
#define LPI2C_SCR_FILTDZ_SHIFT                   5u
#define LPI2C_SCR_FILTDZ_WIDTH                   1u
#define LPI2C_SCR_FILTDZ(x)                      (((uint32)(((uint32)(x))<<LPI2C_SCR_FILTDZ_SHIFT))&LPI2C_SCR_FILTDZ_MASK)
/* SSR Bit Fields */
#define LPI2C_SSR_TDF_MASK                       0x1u
#define LPI2C_SSR_TDF_SHIFT                      0u
#define LPI2C_SSR_TDF_WIDTH                      1u
#define LPI2C_SSR_TDF(x)                         (((uint32)(((uint32)(x))<<LPI2C_SSR_TDF_SHIFT))&LPI2C_SSR_TDF_MASK)
#define LPI2C_SSR_RDF_MASK                       0x2u
#define LPI2C_SSR_RDF_SHIFT                      1u
#define LPI2C_SSR_RDF_WIDTH                      1u
#define LPI2C_SSR_RDF(x)                         (((uint32)(((uint32)(x))<<LPI2C_SSR_RDF_SHIFT))&LPI2C_SSR_RDF_MASK)
#define LPI2C_SSR_AVF_MASK                       0x4u
#define LPI2C_SSR_AVF_SHIFT                      2u
#define LPI2C_SSR_AVF_WIDTH                      1u
#define LPI2C_SSR_AVF(x)                         (((uint32)(((uint32)(x))<<LPI2C_SSR_AVF_SHIFT))&LPI2C_SSR_AVF_MASK)
#define LPI2C_SSR_TAF_MASK                       0x8u
#define LPI2C_SSR_TAF_SHIFT                      3u
#define LPI2C_SSR_TAF_WIDTH                      1u
#define LPI2C_SSR_TAF(x)                         (((uint32)(((uint32)(x))<<LPI2C_SSR_TAF_SHIFT))&LPI2C_SSR_TAF_MASK)
#define LPI2C_SSR_RSF_MASK                       0x100u
#define LPI2C_SSR_RSF_SHIFT                      8u
#define LPI2C_SSR_RSF_WIDTH                      1u
#define LPI2C_SSR_RSF(x)                         (((uint32)(((uint32)(x))<<LPI2C_SSR_RSF_SHIFT))&LPI2C_SSR_RSF_MASK)
#define LPI2C_SSR_SDF_MASK                       0x200u
#define LPI2C_SSR_SDF_SHIFT                      9u
#define LPI2C_SSR_SDF_WIDTH                      1u
#define LPI2C_SSR_SDF(x)                         (((uint32)(((uint32)(x))<<LPI2C_SSR_SDF_SHIFT))&LPI2C_SSR_SDF_MASK)
#define LPI2C_SSR_BEF_MASK                       0x400u
#define LPI2C_SSR_BEF_SHIFT                      10u
#define LPI2C_SSR_BEF_WIDTH                      1u
#define LPI2C_SSR_BEF(x)                         (((uint32)(((uint32)(x))<<LPI2C_SSR_BEF_SHIFT))&LPI2C_SSR_BEF_MASK)
#define LPI2C_SSR_FEF_MASK                       0x800u
#define LPI2C_SSR_FEF_SHIFT                      11u
#define LPI2C_SSR_FEF_WIDTH                      1u
#define LPI2C_SSR_FEF(x)                         (((uint32)(((uint32)(x))<<LPI2C_SSR_FEF_SHIFT))&LPI2C_SSR_FEF_MASK)
#define LPI2C_SSR_AM0F_MASK                      0x1000u
#define LPI2C_SSR_AM0F_SHIFT                     12u
#define LPI2C_SSR_AM0F_WIDTH                     1u
#define LPI2C_SSR_AM0F(x)                        (((uint32)(((uint32)(x))<<LPI2C_SSR_AM0F_SHIFT))&LPI2C_SSR_AM0F_MASK)
#define LPI2C_SSR_AM1F_MASK                      0x2000u
#define LPI2C_SSR_AM1F_SHIFT                     13u
#define LPI2C_SSR_AM1F_WIDTH                     1u
#define LPI2C_SSR_AM1F(x)                        (((uint32)(((uint32)(x))<<LPI2C_SSR_AM1F_SHIFT))&LPI2C_SSR_AM1F_MASK)
#define LPI2C_SSR_GCF_MASK                       0x4000u
#define LPI2C_SSR_GCF_SHIFT                      14u
#define LPI2C_SSR_GCF_WIDTH                      1u
#define LPI2C_SSR_GCF(x)                         (((uint32)(((uint32)(x))<<LPI2C_SSR_GCF_SHIFT))&LPI2C_SSR_GCF_MASK)
#define LPI2C_SSR_SARF_MASK                      0x8000u
#define LPI2C_SSR_SARF_SHIFT                     15u
#define LPI2C_SSR_SARF_WIDTH                     1u
#define LPI2C_SSR_SARF(x)                        (((uint32)(((uint32)(x))<<LPI2C_SSR_SARF_SHIFT))&LPI2C_SSR_SARF_MASK)
#define LPI2C_SSR_SBF_MASK                       0x1000000u
#define LPI2C_SSR_SBF_SHIFT                      24u
#define LPI2C_SSR_SBF_WIDTH                      1u
#define LPI2C_SSR_SBF(x)                         (((uint32)(((uint32)(x))<<LPI2C_SSR_SBF_SHIFT))&LPI2C_SSR_SBF_MASK)
#define LPI2C_SSR_BBF_MASK                       0x2000000u
#define LPI2C_SSR_BBF_SHIFT                      25u
#define LPI2C_SSR_BBF_WIDTH                      1u
#define LPI2C_SSR_BBF(x)                         (((uint32)(((uint32)(x))<<LPI2C_SSR_BBF_SHIFT))&LPI2C_SSR_BBF_MASK)
/* SIER Bit Fields */
#define LPI2C_SIER_TDIE_MASK                     0x1u
#define LPI2C_SIER_TDIE_SHIFT                    0u
#define LPI2C_SIER_TDIE_WIDTH                    1u
#define LPI2C_SIER_TDIE(x)                       (((uint32)(((uint32)(x))<<LPI2C_SIER_TDIE_SHIFT))&LPI2C_SIER_TDIE_MASK)
#define LPI2C_SIER_RDIE_MASK                     0x2u
#define LPI2C_SIER_RDIE_SHIFT                    1u
#define LPI2C_SIER_RDIE_WIDTH                    1u
#define LPI2C_SIER_RDIE(x)                       (((uint32)(((uint32)(x))<<LPI2C_SIER_RDIE_SHIFT))&LPI2C_SIER_RDIE_MASK)
#define LPI2C_SIER_AVIE_MASK                     0x4u
#define LPI2C_SIER_AVIE_SHIFT                    2u
#define LPI2C_SIER_AVIE_WIDTH                    1u
#define LPI2C_SIER_AVIE(x)                       (((uint32)(((uint32)(x))<<LPI2C_SIER_AVIE_SHIFT))&LPI2C_SIER_AVIE_MASK)
#define LPI2C_SIER_TAIE_MASK                     0x8u
#define LPI2C_SIER_TAIE_SHIFT                    3u
#define LPI2C_SIER_TAIE_WIDTH                    1u
#define LPI2C_SIER_TAIE(x)                       (((uint32)(((uint32)(x))<<LPI2C_SIER_TAIE_SHIFT))&LPI2C_SIER_TAIE_MASK)
#define LPI2C_SIER_RSIE_MASK                     0x100u
#define LPI2C_SIER_RSIE_SHIFT                    8u
#define LPI2C_SIER_RSIE_WIDTH                    1u
#define LPI2C_SIER_RSIE(x)                       (((uint32)(((uint32)(x))<<LPI2C_SIER_RSIE_SHIFT))&LPI2C_SIER_RSIE_MASK)
#define LPI2C_SIER_SDIE_MASK                     0x200u
#define LPI2C_SIER_SDIE_SHIFT                    9u
#define LPI2C_SIER_SDIE_WIDTH                    1u
#define LPI2C_SIER_SDIE(x)                       (((uint32)(((uint32)(x))<<LPI2C_SIER_SDIE_SHIFT))&LPI2C_SIER_SDIE_MASK)
#define LPI2C_SIER_BEIE_MASK                     0x400u
#define LPI2C_SIER_BEIE_SHIFT                    10u
#define LPI2C_SIER_BEIE_WIDTH                    1u
#define LPI2C_SIER_BEIE(x)                       (((uint32)(((uint32)(x))<<LPI2C_SIER_BEIE_SHIFT))&LPI2C_SIER_BEIE_MASK)
#define LPI2C_SIER_FEIE_MASK                     0x800u
#define LPI2C_SIER_FEIE_SHIFT                    11u
#define LPI2C_SIER_FEIE_WIDTH                    1u
#define LPI2C_SIER_FEIE(x)                       (((uint32)(((uint32)(x))<<LPI2C_SIER_FEIE_SHIFT))&LPI2C_SIER_FEIE_MASK)
#define LPI2C_SIER_AM0IE_MASK                    0x1000u
#define LPI2C_SIER_AM0IE_SHIFT                   12u
#define LPI2C_SIER_AM0IE_WIDTH                   1u
#define LPI2C_SIER_AM0IE(x)                      (((uint32)(((uint32)(x))<<LPI2C_SIER_AM0IE_SHIFT))&LPI2C_SIER_AM0IE_MASK)
#define LPI2C_SIER_AM1F_MASK                     0x2000u
#define LPI2C_SIER_AM1F_SHIFT                    13u
#define LPI2C_SIER_AM1F_WIDTH                    1u
#define LPI2C_SIER_AM1F(x)                       (((uint32)(((uint32)(x))<<LPI2C_SIER_AM1F_SHIFT))&LPI2C_SIER_AM1F_MASK)
#define LPI2C_SIER_GCIE_MASK                     0x4000u
#define LPI2C_SIER_GCIE_SHIFT                    14u
#define LPI2C_SIER_GCIE_WIDTH                    1u
#define LPI2C_SIER_GCIE(x)                       (((uint32)(((uint32)(x))<<LPI2C_SIER_GCIE_SHIFT))&LPI2C_SIER_GCIE_MASK)
#define LPI2C_SIER_SARIE_MASK                    0x8000u
#define LPI2C_SIER_SARIE_SHIFT                   15u
#define LPI2C_SIER_SARIE_WIDTH                   1u
#define LPI2C_SIER_SARIE(x)                      (((uint32)(((uint32)(x))<<LPI2C_SIER_SARIE_SHIFT))&LPI2C_SIER_SARIE_MASK)
/* SDER Bit Fields */
#define LPI2C_SDER_TDDE_MASK                     0x1u
#define LPI2C_SDER_TDDE_SHIFT                    0u
#define LPI2C_SDER_TDDE_WIDTH                    1u
#define LPI2C_SDER_TDDE(x)                       (((uint32)(((uint32)(x))<<LPI2C_SDER_TDDE_SHIFT))&LPI2C_SDER_TDDE_MASK)
#define LPI2C_SDER_RDDE_MASK                     0x2u
#define LPI2C_SDER_RDDE_SHIFT                    1u
#define LPI2C_SDER_RDDE_WIDTH                    1u
#define LPI2C_SDER_RDDE(x)                       (((uint32)(((uint32)(x))<<LPI2C_SDER_RDDE_SHIFT))&LPI2C_SDER_RDDE_MASK)
#define LPI2C_SDER_AVDE_MASK                     0x4u
#define LPI2C_SDER_AVDE_SHIFT                    2u
#define LPI2C_SDER_AVDE_WIDTH                    1u
#define LPI2C_SDER_AVDE(x)                       (((uint32)(((uint32)(x))<<LPI2C_SDER_AVDE_SHIFT))&LPI2C_SDER_AVDE_MASK)
/* SCFGR1 Bit Fields */
#define LPI2C_SCFGR1_ADRSTALL_MASK               0x1u
#define LPI2C_SCFGR1_ADRSTALL_SHIFT              0u
#define LPI2C_SCFGR1_ADRSTALL_WIDTH              1u
#define LPI2C_SCFGR1_ADRSTALL(x)                 (((uint32)(((uint32)(x))<<LPI2C_SCFGR1_ADRSTALL_SHIFT))&LPI2C_SCFGR1_ADRSTALL_MASK)
#define LPI2C_SCFGR1_RXSTALL_MASK                0x2u
#define LPI2C_SCFGR1_RXSTALL_SHIFT               1u
#define LPI2C_SCFGR1_RXSTALL_WIDTH               1u
#define LPI2C_SCFGR1_RXSTALL(x)                  (((uint32)(((uint32)(x))<<LPI2C_SCFGR1_RXSTALL_SHIFT))&LPI2C_SCFGR1_RXSTALL_MASK)
#define LPI2C_SCFGR1_TXDSTALL_MASK               0x4u
#define LPI2C_SCFGR1_TXDSTALL_SHIFT              2u
#define LPI2C_SCFGR1_TXDSTALL_WIDTH              1u
#define LPI2C_SCFGR1_TXDSTALL(x)                 (((uint32)(((uint32)(x))<<LPI2C_SCFGR1_TXDSTALL_SHIFT))&LPI2C_SCFGR1_TXDSTALL_MASK)
#define LPI2C_SCFGR1_ACKSTALL_MASK               0x8u
#define LPI2C_SCFGR1_ACKSTALL_SHIFT              3u
#define LPI2C_SCFGR1_ACKSTALL_WIDTH              1u
#define LPI2C_SCFGR1_ACKSTALL(x)                 (((uint32)(((uint32)(x))<<LPI2C_SCFGR1_ACKSTALL_SHIFT))&LPI2C_SCFGR1_ACKSTALL_MASK)
#define LPI2C_SCFGR1_GCEN_MASK                   0x100u
#define LPI2C_SCFGR1_GCEN_SHIFT                  8u
#define LPI2C_SCFGR1_GCEN_WIDTH                  1u
#define LPI2C_SCFGR1_GCEN(x)                     (((uint32)(((uint32)(x))<<LPI2C_SCFGR1_GCEN_SHIFT))&LPI2C_SCFGR1_GCEN_MASK)
#define LPI2C_SCFGR1_SAEN_MASK                   0x200u
#define LPI2C_SCFGR1_SAEN_SHIFT                  9u
#define LPI2C_SCFGR1_SAEN_WIDTH                  1u
#define LPI2C_SCFGR1_SAEN(x)                     (((uint32)(((uint32)(x))<<LPI2C_SCFGR1_SAEN_SHIFT))&LPI2C_SCFGR1_SAEN_MASK)
#define LPI2C_SCFGR1_TXCFG_MASK                  0x400u
#define LPI2C_SCFGR1_TXCFG_SHIFT                 10u
#define LPI2C_SCFGR1_TXCFG_WIDTH                 1u
#define LPI2C_SCFGR1_TXCFG(x)                    (((uint32)(((uint32)(x))<<LPI2C_SCFGR1_TXCFG_SHIFT))&LPI2C_SCFGR1_TXCFG_MASK)
#define LPI2C_SCFGR1_RXCFG_MASK                  0x800u
#define LPI2C_SCFGR1_RXCFG_SHIFT                 11u
#define LPI2C_SCFGR1_RXCFG_WIDTH                 1u
#define LPI2C_SCFGR1_RXCFG(x)                    (((uint32)(((uint32)(x))<<LPI2C_SCFGR1_RXCFG_SHIFT))&LPI2C_SCFGR1_RXCFG_MASK)
#define LPI2C_SCFGR1_IGNACK_MASK                 0x1000u
#define LPI2C_SCFGR1_IGNACK_SHIFT                12u
#define LPI2C_SCFGR1_IGNACK_WIDTH                1u
#define LPI2C_SCFGR1_IGNACK(x)                   (((uint32)(((uint32)(x))<<LPI2C_SCFGR1_IGNACK_SHIFT))&LPI2C_SCFGR1_IGNACK_MASK)
#define LPI2C_SCFGR1_HSMEN_MASK                  0x2000u
#define LPI2C_SCFGR1_HSMEN_SHIFT                 13u
#define LPI2C_SCFGR1_HSMEN_WIDTH                 1u
#define LPI2C_SCFGR1_HSMEN(x)                    (((uint32)(((uint32)(x))<<LPI2C_SCFGR1_HSMEN_SHIFT))&LPI2C_SCFGR1_HSMEN_MASK)
#define LPI2C_SCFGR1_ADDRCFG_MASK                0x70000u
#define LPI2C_SCFGR1_ADDRCFG_SHIFT               16u
#define LPI2C_SCFGR1_ADDRCFG_WIDTH               3u
#define LPI2C_SCFGR1_ADDRCFG(x)                  (((uint32)(((uint32)(x))<<LPI2C_SCFGR1_ADDRCFG_SHIFT))&LPI2C_SCFGR1_ADDRCFG_MASK)
/* SCFGR2 Bit Fields */
#define LPI2C_SCFGR2_CLKHOLD_MASK                0xFu
#define LPI2C_SCFGR2_CLKHOLD_SHIFT               0u
#define LPI2C_SCFGR2_CLKHOLD_WIDTH               4u
#define LPI2C_SCFGR2_CLKHOLD(x)                  (((uint32)(((uint32)(x))<<LPI2C_SCFGR2_CLKHOLD_SHIFT))&LPI2C_SCFGR2_CLKHOLD_MASK)
#define LPI2C_SCFGR2_DATAVD_MASK                 0x3F00u
#define LPI2C_SCFGR2_DATAVD_SHIFT                8u
#define LPI2C_SCFGR2_DATAVD_WIDTH                6u
#define LPI2C_SCFGR2_DATAVD(x)                   (((uint32)(((uint32)(x))<<LPI2C_SCFGR2_DATAVD_SHIFT))&LPI2C_SCFGR2_DATAVD_MASK)
#define LPI2C_SCFGR2_FILTSCL_MASK                0xF0000u
#define LPI2C_SCFGR2_FILTSCL_SHIFT               16u
#define LPI2C_SCFGR2_FILTSCL_WIDTH               4u
#define LPI2C_SCFGR2_FILTSCL(x)                  (((uint32)(((uint32)(x))<<LPI2C_SCFGR2_FILTSCL_SHIFT))&LPI2C_SCFGR2_FILTSCL_MASK)
#define LPI2C_SCFGR2_FILTSDA_MASK                0xF000000u
#define LPI2C_SCFGR2_FILTSDA_SHIFT               24u
#define LPI2C_SCFGR2_FILTSDA_WIDTH               4u
#define LPI2C_SCFGR2_FILTSDA(x)                  (((uint32)(((uint32)(x))<<LPI2C_SCFGR2_FILTSDA_SHIFT))&LPI2C_SCFGR2_FILTSDA_MASK)
/* SAMR Bit Fields */
#define LPI2C_SAMR_ADDR0_MASK                    0x7FEu
#define LPI2C_SAMR_ADDR0_SHIFT                   1u
#define LPI2C_SAMR_ADDR0_WIDTH                   10u
#define LPI2C_SAMR_ADDR0(x)                      (((uint32)(((uint32)(x))<<LPI2C_SAMR_ADDR0_SHIFT))&LPI2C_SAMR_ADDR0_MASK)
#define LPI2C_SAMR_ADDR1_MASK                    0x7FE0000u
#define LPI2C_SAMR_ADDR1_SHIFT                   17u
#define LPI2C_SAMR_ADDR1_WIDTH                   10u
#define LPI2C_SAMR_ADDR1(x)                      (((uint32)(((uint32)(x))<<LPI2C_SAMR_ADDR1_SHIFT))&LPI2C_SAMR_ADDR1_MASK)
/* SASR Bit Fields */
#define LPI2C_SASR_RADDR_MASK                    0x7FFu
#define LPI2C_SASR_RADDR_SHIFT                   0u
#define LPI2C_SASR_RADDR_WIDTH                   11u
#define LPI2C_SASR_RADDR(x)                      (((uint32)(((uint32)(x))<<LPI2C_SASR_RADDR_SHIFT))&LPI2C_SASR_RADDR_MASK)
#define LPI2C_SASR_ANV_MASK                      0x4000u
#define LPI2C_SASR_ANV_SHIFT                     14u
#define LPI2C_SASR_ANV_WIDTH                     1u
#define LPI2C_SASR_ANV(x)                        (((uint32)(((uint32)(x))<<LPI2C_SASR_ANV_SHIFT))&LPI2C_SASR_ANV_MASK)
/* STAR Bit Fields */
#define LPI2C_STAR_TXNACK_MASK                   0x1u
#define LPI2C_STAR_TXNACK_SHIFT                  0u
#define LPI2C_STAR_TXNACK_WIDTH                  1u
#define LPI2C_STAR_TXNACK(x)                     (((uint32)(((uint32)(x))<<LPI2C_STAR_TXNACK_SHIFT))&LPI2C_STAR_TXNACK_MASK)
/* STDR Bit Fields */
#define LPI2C_STDR_DATA_MASK                     0xFFu
#define LPI2C_STDR_DATA_SHIFT                    0u
#define LPI2C_STDR_DATA_WIDTH                    8u
#define LPI2C_STDR_DATA(x)                       (((uint32)(((uint32)(x))<<LPI2C_STDR_DATA_SHIFT))&LPI2C_STDR_DATA_MASK)
/* SRDR Bit Fields */
#define LPI2C_SRDR_DATA_MASK                     0xFFu
#define LPI2C_SRDR_DATA_SHIFT                    0u
#define LPI2C_SRDR_DATA_WIDTH                    8u
#define LPI2C_SRDR_DATA(x)                       (((uint32)(((uint32)(x))<<LPI2C_SRDR_DATA_SHIFT))&LPI2C_SRDR_DATA_MASK)
#define LPI2C_SRDR_RXEMPTY_MASK                  0x4000u
#define LPI2C_SRDR_RXEMPTY_SHIFT                 14u
#define LPI2C_SRDR_RXEMPTY_WIDTH                 1u
#define LPI2C_SRDR_RXEMPTY(x)                    (((uint32)(((uint32)(x))<<LPI2C_SRDR_RXEMPTY_SHIFT))&LPI2C_SRDR_RXEMPTY_MASK)
#define LPI2C_SRDR_SOF_MASK                      0x8000u
#define LPI2C_SRDR_SOF_SHIFT                     15u
#define LPI2C_SRDR_SOF_WIDTH                     1u
#define LPI2C_SRDR_SOF(x)                        (((uint32)(((uint32)(x))<<LPI2C_SRDR_SOF_SHIFT))&LPI2C_SRDR_SOF_MASK)

/*!
 * @}
 */ /* end of group LPI2C_Register_Masks */


/*!
 * @}
 */ /* end of group LPI2C_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPIT_Peripheral_Access_Layer LPIT Peripheral Access Layer
 * @{
 */


/** LPIT - Size of Registers Arrays */
#define LPIT_TMR_COUNT                           4u

/** LPIT - Register Layout Typedef */
typedef struct {
  __I  uint32 VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32 PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32 MCR;                               /**< Module Control Register, offset: 0x8 */
  __IO uint32 MSR;                               /**< Module Status Register, offset: 0xC */
  __IO uint32 MIER;                              /**< Module Interrupt Enable Register, offset: 0x10 */
  __IO uint32 SETTEN;                            /**< Set Timer Enable Register, offset: 0x14 */
  __IO uint32 CLRTEN;                            /**< Clear Timer Enable Register, offset: 0x18 */
       uint8 RESERVED_0[4];
  struct {                                         /* offset: 0x20, array step: 0x10 */
    __IO uint32 TVAL;                              /**< Timer Value Register, array offset: 0x20, array step: 0x10 */
    __I  uint32 CVAL;                              /**< Current Timer Value, array offset: 0x24, array step: 0x10 */
    __IO uint32 TCTRL;                             /**< Timer Control Register, array offset: 0x28, array step: 0x10 */
         uint8 RESERVED_0[4];
  } TMR[LPIT_TMR_COUNT];
} LPIT_Type, *LPIT_MemMapPtr;

 /** Number of instances of the LPIT module. */
#define LPIT_INSTANCE_COUNT                      (1u)


/* LPIT - Peripheral instance base addresses */
/** Peripheral LPIT0 base address */
#define LPIT0_BASE                               (0x40037000u)
/** Peripheral LPIT0 base pointer */
#define LPIT0                                    ((LPIT_Type *)LPIT0_BASE)
/** Array initializer of LPIT peripheral base addresses */
#define LPIT_BASE_ADDRS                          { LPIT0_BASE }
/** Array initializer of LPIT peripheral base pointers */
#define LPIT_BASE_PTRS                           { LPIT0 }
 /** Number of interrupt vector arrays for the LPIT module. */
#define LPIT_IRQS_ARR_COUNT                      (1u)
 /** Number of interrupt channels for the LPIT module. */
#define LPIT_IRQS_CH_COUNT                       (4u)
/** Interrupt vectors for the LPIT peripheral type */
#define LPIT_IRQS                                { LPIT0_Ch0_IRQn, LPIT0_Ch1_IRQn, LPIT0_Ch2_IRQn, LPIT0_Ch3_IRQn }

/* ----------------------------------------------------------------------------
   -- LPIT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPIT_Register_Masks LPIT Register Masks
 * @{
 */

/* VERID Bit Fields */
#define LPIT_VERID_FEATURE_MASK                  0xFFFFu
#define LPIT_VERID_FEATURE_SHIFT                 0u
#define LPIT_VERID_FEATURE_WIDTH                 16u
#define LPIT_VERID_FEATURE(x)                    (((uint32)(((uint32)(x))<<LPIT_VERID_FEATURE_SHIFT))&LPIT_VERID_FEATURE_MASK)
#define LPIT_VERID_MINOR_MASK                    0xFF0000u
#define LPIT_VERID_MINOR_SHIFT                   16u
#define LPIT_VERID_MINOR_WIDTH                   8u
#define LPIT_VERID_MINOR(x)                      (((uint32)(((uint32)(x))<<LPIT_VERID_MINOR_SHIFT))&LPIT_VERID_MINOR_MASK)
#define LPIT_VERID_MAJOR_MASK                    0xFF000000u
#define LPIT_VERID_MAJOR_SHIFT                   24u
#define LPIT_VERID_MAJOR_WIDTH                   8u
#define LPIT_VERID_MAJOR(x)                      (((uint32)(((uint32)(x))<<LPIT_VERID_MAJOR_SHIFT))&LPIT_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define LPIT_PARAM_CHANNEL_MASK                  0xFFu
#define LPIT_PARAM_CHANNEL_SHIFT                 0u
#define LPIT_PARAM_CHANNEL_WIDTH                 8u
#define LPIT_PARAM_CHANNEL(x)                    (((uint32)(((uint32)(x))<<LPIT_PARAM_CHANNEL_SHIFT))&LPIT_PARAM_CHANNEL_MASK)
#define LPIT_PARAM_EXT_TRIG_MASK                 0xFF00u
#define LPIT_PARAM_EXT_TRIG_SHIFT                8u
#define LPIT_PARAM_EXT_TRIG_WIDTH                8u
#define LPIT_PARAM_EXT_TRIG(x)                   (((uint32)(((uint32)(x))<<LPIT_PARAM_EXT_TRIG_SHIFT))&LPIT_PARAM_EXT_TRIG_MASK)
/* MCR Bit Fields */
#define LPIT_MCR_M_CEN_MASK                      0x1u
#define LPIT_MCR_M_CEN_SHIFT                     0u
#define LPIT_MCR_M_CEN_WIDTH                     1u
#define LPIT_MCR_M_CEN(x)                        (((uint32)(((uint32)(x))<<LPIT_MCR_M_CEN_SHIFT))&LPIT_MCR_M_CEN_MASK)
#define LPIT_MCR_SW_RST_MASK                     0x2u
#define LPIT_MCR_SW_RST_SHIFT                    1u
#define LPIT_MCR_SW_RST_WIDTH                    1u
#define LPIT_MCR_SW_RST(x)                       (((uint32)(((uint32)(x))<<LPIT_MCR_SW_RST_SHIFT))&LPIT_MCR_SW_RST_MASK)
#define LPIT_MCR_DOZE_EN_MASK                    0x4u
#define LPIT_MCR_DOZE_EN_SHIFT                   2u
#define LPIT_MCR_DOZE_EN_WIDTH                   1u
#define LPIT_MCR_DOZE_EN(x)                      (((uint32)(((uint32)(x))<<LPIT_MCR_DOZE_EN_SHIFT))&LPIT_MCR_DOZE_EN_MASK)
#define LPIT_MCR_DBG_EN_MASK                     0x8u
#define LPIT_MCR_DBG_EN_SHIFT                    3u
#define LPIT_MCR_DBG_EN_WIDTH                    1u
#define LPIT_MCR_DBG_EN(x)                       (((uint32)(((uint32)(x))<<LPIT_MCR_DBG_EN_SHIFT))&LPIT_MCR_DBG_EN_MASK)
/* MSR Bit Fields */
#define LPIT_MSR_TIF0_MASK                       0x1u
#define LPIT_MSR_TIF0_SHIFT                      0u
#define LPIT_MSR_TIF0_WIDTH                      1u
#define LPIT_MSR_TIF0(x)                         (((uint32)(((uint32)(x))<<LPIT_MSR_TIF0_SHIFT))&LPIT_MSR_TIF0_MASK)
#define LPIT_MSR_TIF1_MASK                       0x2u
#define LPIT_MSR_TIF1_SHIFT                      1u
#define LPIT_MSR_TIF1_WIDTH                      1u
#define LPIT_MSR_TIF1(x)                         (((uint32)(((uint32)(x))<<LPIT_MSR_TIF1_SHIFT))&LPIT_MSR_TIF1_MASK)
#define LPIT_MSR_TIF2_MASK                       0x4u
#define LPIT_MSR_TIF2_SHIFT                      2u
#define LPIT_MSR_TIF2_WIDTH                      1u
#define LPIT_MSR_TIF2(x)                         (((uint32)(((uint32)(x))<<LPIT_MSR_TIF2_SHIFT))&LPIT_MSR_TIF2_MASK)
#define LPIT_MSR_TIF3_MASK                       0x8u
#define LPIT_MSR_TIF3_SHIFT                      3u
#define LPIT_MSR_TIF3_WIDTH                      1u
#define LPIT_MSR_TIF3(x)                         (((uint32)(((uint32)(x))<<LPIT_MSR_TIF3_SHIFT))&LPIT_MSR_TIF3_MASK)
/* MIER Bit Fields */
#define LPIT_MIER_TIE0_MASK                      0x1u
#define LPIT_MIER_TIE0_SHIFT                     0u
#define LPIT_MIER_TIE0_WIDTH                     1u
#define LPIT_MIER_TIE0(x)                        (((uint32)(((uint32)(x))<<LPIT_MIER_TIE0_SHIFT))&LPIT_MIER_TIE0_MASK)
#define LPIT_MIER_TIE1_MASK                      0x2u
#define LPIT_MIER_TIE1_SHIFT                     1u
#define LPIT_MIER_TIE1_WIDTH                     1u
#define LPIT_MIER_TIE1(x)                        (((uint32)(((uint32)(x))<<LPIT_MIER_TIE1_SHIFT))&LPIT_MIER_TIE1_MASK)
#define LPIT_MIER_TIE2_MASK                      0x4u
#define LPIT_MIER_TIE2_SHIFT                     2u
#define LPIT_MIER_TIE2_WIDTH                     1u
#define LPIT_MIER_TIE2(x)                        (((uint32)(((uint32)(x))<<LPIT_MIER_TIE2_SHIFT))&LPIT_MIER_TIE2_MASK)
#define LPIT_MIER_TIE3_MASK                      0x8u
#define LPIT_MIER_TIE3_SHIFT                     3u
#define LPIT_MIER_TIE3_WIDTH                     1u
#define LPIT_MIER_TIE3(x)                        (((uint32)(((uint32)(x))<<LPIT_MIER_TIE3_SHIFT))&LPIT_MIER_TIE3_MASK)
/* SETTEN Bit Fields */
#define LPIT_SETTEN_SET_T_EN_0_MASK              0x1u
#define LPIT_SETTEN_SET_T_EN_0_SHIFT             0u
#define LPIT_SETTEN_SET_T_EN_0_WIDTH             1u
#define LPIT_SETTEN_SET_T_EN_0(x)                (((uint32)(((uint32)(x))<<LPIT_SETTEN_SET_T_EN_0_SHIFT))&LPIT_SETTEN_SET_T_EN_0_MASK)
#define LPIT_SETTEN_SET_T_EN_1_MASK              0x2u
#define LPIT_SETTEN_SET_T_EN_1_SHIFT             1u
#define LPIT_SETTEN_SET_T_EN_1_WIDTH             1u
#define LPIT_SETTEN_SET_T_EN_1(x)                (((uint32)(((uint32)(x))<<LPIT_SETTEN_SET_T_EN_1_SHIFT))&LPIT_SETTEN_SET_T_EN_1_MASK)
#define LPIT_SETTEN_SET_T_EN_2_MASK              0x4u
#define LPIT_SETTEN_SET_T_EN_2_SHIFT             2u
#define LPIT_SETTEN_SET_T_EN_2_WIDTH             1u
#define LPIT_SETTEN_SET_T_EN_2(x)                (((uint32)(((uint32)(x))<<LPIT_SETTEN_SET_T_EN_2_SHIFT))&LPIT_SETTEN_SET_T_EN_2_MASK)
#define LPIT_SETTEN_SET_T_EN_3_MASK              0x8u
#define LPIT_SETTEN_SET_T_EN_3_SHIFT             3u
#define LPIT_SETTEN_SET_T_EN_3_WIDTH             1u
#define LPIT_SETTEN_SET_T_EN_3(x)                (((uint32)(((uint32)(x))<<LPIT_SETTEN_SET_T_EN_3_SHIFT))&LPIT_SETTEN_SET_T_EN_3_MASK)
/* CLRTEN Bit Fields */
#define LPIT_CLRTEN_CLR_T_EN_0_MASK              0x1u
#define LPIT_CLRTEN_CLR_T_EN_0_SHIFT             0u
#define LPIT_CLRTEN_CLR_T_EN_0_WIDTH             1u
#define LPIT_CLRTEN_CLR_T_EN_0(x)                (((uint32)(((uint32)(x))<<LPIT_CLRTEN_CLR_T_EN_0_SHIFT))&LPIT_CLRTEN_CLR_T_EN_0_MASK)
#define LPIT_CLRTEN_CLR_T_EN_1_MASK              0x2u
#define LPIT_CLRTEN_CLR_T_EN_1_SHIFT             1u
#define LPIT_CLRTEN_CLR_T_EN_1_WIDTH             1u
#define LPIT_CLRTEN_CLR_T_EN_1(x)                (((uint32)(((uint32)(x))<<LPIT_CLRTEN_CLR_T_EN_1_SHIFT))&LPIT_CLRTEN_CLR_T_EN_1_MASK)
#define LPIT_CLRTEN_CLR_T_EN_2_MASK              0x4u
#define LPIT_CLRTEN_CLR_T_EN_2_SHIFT             2u
#define LPIT_CLRTEN_CLR_T_EN_2_WIDTH             1u
#define LPIT_CLRTEN_CLR_T_EN_2(x)                (((uint32)(((uint32)(x))<<LPIT_CLRTEN_CLR_T_EN_2_SHIFT))&LPIT_CLRTEN_CLR_T_EN_2_MASK)
#define LPIT_CLRTEN_CLR_T_EN_3_MASK              0x8u
#define LPIT_CLRTEN_CLR_T_EN_3_SHIFT             3u
#define LPIT_CLRTEN_CLR_T_EN_3_WIDTH             1u
#define LPIT_CLRTEN_CLR_T_EN_3(x)                (((uint32)(((uint32)(x))<<LPIT_CLRTEN_CLR_T_EN_3_SHIFT))&LPIT_CLRTEN_CLR_T_EN_3_MASK)
/* TMR_TVAL Bit Fields */
#define LPIT_TMR_TVAL_TMR_VAL_MASK               0xFFFFFFFFu
#define LPIT_TMR_TVAL_TMR_VAL_SHIFT              0u
#define LPIT_TMR_TVAL_TMR_VAL_WIDTH              32u
#define LPIT_TMR_TVAL_TMR_VAL(x)                 (((uint32)(((uint32)(x))<<LPIT_TMR_TVAL_TMR_VAL_SHIFT))&LPIT_TMR_TVAL_TMR_VAL_MASK)
/* TMR_CVAL Bit Fields */
#define LPIT_TMR_CVAL_TMR_CUR_VAL_MASK           0xFFFFFFFFu
#define LPIT_TMR_CVAL_TMR_CUR_VAL_SHIFT          0u
#define LPIT_TMR_CVAL_TMR_CUR_VAL_WIDTH          32u
#define LPIT_TMR_CVAL_TMR_CUR_VAL(x)             (((uint32)(((uint32)(x))<<LPIT_TMR_CVAL_TMR_CUR_VAL_SHIFT))&LPIT_TMR_CVAL_TMR_CUR_VAL_MASK)
/* TMR_TCTRL Bit Fields */
#define LPIT_TMR_TCTRL_T_EN_MASK                 0x1u
#define LPIT_TMR_TCTRL_T_EN_SHIFT                0u
#define LPIT_TMR_TCTRL_T_EN_WIDTH                1u
#define LPIT_TMR_TCTRL_T_EN(x)                   (((uint32)(((uint32)(x))<<LPIT_TMR_TCTRL_T_EN_SHIFT))&LPIT_TMR_TCTRL_T_EN_MASK)
#define LPIT_TMR_TCTRL_CHAIN_MASK                0x2u
#define LPIT_TMR_TCTRL_CHAIN_SHIFT               1u
#define LPIT_TMR_TCTRL_CHAIN_WIDTH               1u
#define LPIT_TMR_TCTRL_CHAIN(x)                  (((uint32)(((uint32)(x))<<LPIT_TMR_TCTRL_CHAIN_SHIFT))&LPIT_TMR_TCTRL_CHAIN_MASK)
#define LPIT_TMR_TCTRL_MODE_MASK                 0xCu
#define LPIT_TMR_TCTRL_MODE_SHIFT                2u
#define LPIT_TMR_TCTRL_MODE_WIDTH                2u
#define LPIT_TMR_TCTRL_MODE(x)                   (((uint32)(((uint32)(x))<<LPIT_TMR_TCTRL_MODE_SHIFT))&LPIT_TMR_TCTRL_MODE_MASK)
#define LPIT_TMR_TCTRL_TSOT_MASK                 0x10000u
#define LPIT_TMR_TCTRL_TSOT_SHIFT                16u
#define LPIT_TMR_TCTRL_TSOT_WIDTH                1u
#define LPIT_TMR_TCTRL_TSOT(x)                   (((uint32)(((uint32)(x))<<LPIT_TMR_TCTRL_TSOT_SHIFT))&LPIT_TMR_TCTRL_TSOT_MASK)
#define LPIT_TMR_TCTRL_TSOI_MASK                 0x20000u
#define LPIT_TMR_TCTRL_TSOI_SHIFT                17u
#define LPIT_TMR_TCTRL_TSOI_WIDTH                1u
#define LPIT_TMR_TCTRL_TSOI(x)                   (((uint32)(((uint32)(x))<<LPIT_TMR_TCTRL_TSOI_SHIFT))&LPIT_TMR_TCTRL_TSOI_MASK)
#define LPIT_TMR_TCTRL_TROT_MASK                 0x40000u
#define LPIT_TMR_TCTRL_TROT_SHIFT                18u
#define LPIT_TMR_TCTRL_TROT_WIDTH                1u
#define LPIT_TMR_TCTRL_TROT(x)                   (((uint32)(((uint32)(x))<<LPIT_TMR_TCTRL_TROT_SHIFT))&LPIT_TMR_TCTRL_TROT_MASK)
#define LPIT_TMR_TCTRL_TRG_SRC_MASK              0x800000u
#define LPIT_TMR_TCTRL_TRG_SRC_SHIFT             23u
#define LPIT_TMR_TCTRL_TRG_SRC_WIDTH             1u
#define LPIT_TMR_TCTRL_TRG_SRC(x)                (((uint32)(((uint32)(x))<<LPIT_TMR_TCTRL_TRG_SRC_SHIFT))&LPIT_TMR_TCTRL_TRG_SRC_MASK)
#define LPIT_TMR_TCTRL_TRG_SEL_MASK              0xF000000u
#define LPIT_TMR_TCTRL_TRG_SEL_SHIFT             24u
#define LPIT_TMR_TCTRL_TRG_SEL_WIDTH             4u
#define LPIT_TMR_TCTRL_TRG_SEL(x)                (((uint32)(((uint32)(x))<<LPIT_TMR_TCTRL_TRG_SEL_SHIFT))&LPIT_TMR_TCTRL_TRG_SEL_MASK)

/*!
 * @}
 */ /* end of group LPIT_Register_Masks */


/*!
 * @}
 */ /* end of group LPIT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPSPI_Peripheral_Access_Layer LPSPI Peripheral Access Layer
 * @{
 */


/** LPSPI - Size of Registers Arrays */

/** LPSPI - Register Layout Typedef */
typedef struct {
  __I  uint32 VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32 PARAM;                             /**< Parameter Register, offset: 0x4 */
       uint8 RESERVED_0[8];
  __IO uint32 CR;                                /**< Control Register, offset: 0x10 */
  __IO uint32 SR;                                /**< Status Register, offset: 0x14 */
  __IO uint32 IER;                               /**< Interrupt Enable Register, offset: 0x18 */
  __IO uint32 DER;                               /**< DMA Enable Register, offset: 0x1C */
  __IO uint32 CFGR0;                             /**< Configuration Register 0, offset: 0x20 */
  __IO uint32 CFGR1;                             /**< Configuration Register 1, offset: 0x24 */
       uint8 RESERVED_1[8];
  __IO uint32 DMR0;                              /**< Data Match Register 0, offset: 0x30 */
  __IO uint32 DMR1;                              /**< Data Match Register 1, offset: 0x34 */
       uint8 RESERVED_2[8];
  __IO uint32 CCR;                               /**< Clock Configuration Register, offset: 0x40 */
       uint8 RESERVED_3[20];
  __IO uint32 FCR;                               /**< FIFO Control Register, offset: 0x58 */
  __I  uint32 FSR;                               /**< FIFO Status Register, offset: 0x5C */
  __IO uint32 TCR;                               /**< Transmit Command Register, offset: 0x60 */
  __O  uint32 TDR;                               /**< Transmit Data Register, offset: 0x64 */
       uint8 RESERVED_4[8];
  __I  uint32 RSR;                               /**< Receive Status Register, offset: 0x70 */
  __I  uint32 RDR;                               /**< Receive Data Register, offset: 0x74 */
} LPSPI_Type, *LPSPI_MemMapPtr;

 /** Number of instances of the LPSPI module. */
#define LPSPI_INSTANCE_COUNT                     (3u)


/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI0 base address */
#define LPSPI0_BASE                              (0x4002C000u)
/** Peripheral LPSPI0 base pointer */
#define LPSPI0                                   ((LPSPI_Type *)LPSPI0_BASE)
/** Peripheral LPSPI1 base address */
#define LPSPI1_BASE                              (0x4002D000u)
/** Peripheral LPSPI1 base pointer */
#define LPSPI1                                   ((LPSPI_Type *)LPSPI1_BASE)
/** Peripheral LPSPI2 base address */
#define LPSPI2_BASE                              (0x4002E000u)
/** Peripheral LPSPI2 base pointer */
#define LPSPI2                                   ((LPSPI_Type *)LPSPI2_BASE)
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         { LPSPI0_BASE, LPSPI1_BASE, LPSPI2_BASE }
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          { LPSPI0, LPSPI1, LPSPI2 }
 /** Number of interrupt vector arrays for the LPSPI module. */
#define LPSPI_IRQS_ARR_COUNT                     (1u)
 /** Number of interrupt channels for the LPSPI module. */
#define LPSPI_IRQS_CH_COUNT                      (1u)
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { LPSPI0_IRQn, LPSPI1_IRQn, LPSPI2_IRQn }

/* ----------------------------------------------------------------------------
   -- LPSPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPSPI_Register_Masks LPSPI Register Masks
 * @{
 */

/* VERID Bit Fields */
#define LPSPI_VERID_FEATURE_MASK                 0xFFFFu
#define LPSPI_VERID_FEATURE_SHIFT                0u
#define LPSPI_VERID_FEATURE_WIDTH                16u
#define LPSPI_VERID_FEATURE(x)                   (((uint32)(((uint32)(x))<<LPSPI_VERID_FEATURE_SHIFT))&LPSPI_VERID_FEATURE_MASK)
#define LPSPI_VERID_MINOR_MASK                   0xFF0000u
#define LPSPI_VERID_MINOR_SHIFT                  16u
#define LPSPI_VERID_MINOR_WIDTH                  8u
#define LPSPI_VERID_MINOR(x)                     (((uint32)(((uint32)(x))<<LPSPI_VERID_MINOR_SHIFT))&LPSPI_VERID_MINOR_MASK)
#define LPSPI_VERID_MAJOR_MASK                   0xFF000000u
#define LPSPI_VERID_MAJOR_SHIFT                  24u
#define LPSPI_VERID_MAJOR_WIDTH                  8u
#define LPSPI_VERID_MAJOR(x)                     (((uint32)(((uint32)(x))<<LPSPI_VERID_MAJOR_SHIFT))&LPSPI_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define LPSPI_PARAM_TXFIFO_MASK                  0xFFu
#define LPSPI_PARAM_TXFIFO_SHIFT                 0u
#define LPSPI_PARAM_TXFIFO_WIDTH                 8u
#define LPSPI_PARAM_TXFIFO(x)                    (((uint32)(((uint32)(x))<<LPSPI_PARAM_TXFIFO_SHIFT))&LPSPI_PARAM_TXFIFO_MASK)
#define LPSPI_PARAM_RXFIFO_MASK                  0xFF00u
#define LPSPI_PARAM_RXFIFO_SHIFT                 8u
#define LPSPI_PARAM_RXFIFO_WIDTH                 8u
#define LPSPI_PARAM_RXFIFO(x)                    (((uint32)(((uint32)(x))<<LPSPI_PARAM_RXFIFO_SHIFT))&LPSPI_PARAM_RXFIFO_MASK)
/* CR Bit Fields */
#define LPSPI_CR_MEN_MASK                        0x1u
#define LPSPI_CR_MEN_SHIFT                       0u
#define LPSPI_CR_MEN_WIDTH                       1u
#define LPSPI_CR_MEN(x)                          (((uint32)(((uint32)(x))<<LPSPI_CR_MEN_SHIFT))&LPSPI_CR_MEN_MASK)
#define LPSPI_CR_RST_MASK                        0x2u
#define LPSPI_CR_RST_SHIFT                       1u
#define LPSPI_CR_RST_WIDTH                       1u
#define LPSPI_CR_RST(x)                          (((uint32)(((uint32)(x))<<LPSPI_CR_RST_SHIFT))&LPSPI_CR_RST_MASK)
#define LPSPI_CR_DOZEN_MASK                      0x4u
#define LPSPI_CR_DOZEN_SHIFT                     2u
#define LPSPI_CR_DOZEN_WIDTH                     1u
#define LPSPI_CR_DOZEN(x)                        (((uint32)(((uint32)(x))<<LPSPI_CR_DOZEN_SHIFT))&LPSPI_CR_DOZEN_MASK)
#define LPSPI_CR_DBGEN_MASK                      0x8u
#define LPSPI_CR_DBGEN_SHIFT                     3u
#define LPSPI_CR_DBGEN_WIDTH                     1u
#define LPSPI_CR_DBGEN(x)                        (((uint32)(((uint32)(x))<<LPSPI_CR_DBGEN_SHIFT))&LPSPI_CR_DBGEN_MASK)
#define LPSPI_CR_RTF_MASK                        0x100u
#define LPSPI_CR_RTF_SHIFT                       8u
#define LPSPI_CR_RTF_WIDTH                       1u
#define LPSPI_CR_RTF(x)                          (((uint32)(((uint32)(x))<<LPSPI_CR_RTF_SHIFT))&LPSPI_CR_RTF_MASK)
#define LPSPI_CR_RRF_MASK                        0x200u
#define LPSPI_CR_RRF_SHIFT                       9u
#define LPSPI_CR_RRF_WIDTH                       1u
#define LPSPI_CR_RRF(x)                          (((uint32)(((uint32)(x))<<LPSPI_CR_RRF_SHIFT))&LPSPI_CR_RRF_MASK)
/* SR Bit Fields */
#define LPSPI_SR_TDF_MASK                        0x1u
#define LPSPI_SR_TDF_SHIFT                       0u
#define LPSPI_SR_TDF_WIDTH                       1u
#define LPSPI_SR_TDF(x)                          (((uint32)(((uint32)(x))<<LPSPI_SR_TDF_SHIFT))&LPSPI_SR_TDF_MASK)
#define LPSPI_SR_RDF_MASK                        0x2u
#define LPSPI_SR_RDF_SHIFT                       1u
#define LPSPI_SR_RDF_WIDTH                       1u
#define LPSPI_SR_RDF(x)                          (((uint32)(((uint32)(x))<<LPSPI_SR_RDF_SHIFT))&LPSPI_SR_RDF_MASK)
#define LPSPI_SR_WCF_MASK                        0x100u
#define LPSPI_SR_WCF_SHIFT                       8u
#define LPSPI_SR_WCF_WIDTH                       1u
#define LPSPI_SR_WCF(x)                          (((uint32)(((uint32)(x))<<LPSPI_SR_WCF_SHIFT))&LPSPI_SR_WCF_MASK)
#define LPSPI_SR_FCF_MASK                        0x200u
#define LPSPI_SR_FCF_SHIFT                       9u
#define LPSPI_SR_FCF_WIDTH                       1u
#define LPSPI_SR_FCF(x)                          (((uint32)(((uint32)(x))<<LPSPI_SR_FCF_SHIFT))&LPSPI_SR_FCF_MASK)
#define LPSPI_SR_TCF_MASK                        0x400u
#define LPSPI_SR_TCF_SHIFT                       10u
#define LPSPI_SR_TCF_WIDTH                       1u
#define LPSPI_SR_TCF(x)                          (((uint32)(((uint32)(x))<<LPSPI_SR_TCF_SHIFT))&LPSPI_SR_TCF_MASK)
#define LPSPI_SR_TEF_MASK                        0x800u
#define LPSPI_SR_TEF_SHIFT                       11u
#define LPSPI_SR_TEF_WIDTH                       1u
#define LPSPI_SR_TEF(x)                          (((uint32)(((uint32)(x))<<LPSPI_SR_TEF_SHIFT))&LPSPI_SR_TEF_MASK)
#define LPSPI_SR_REF_MASK                        0x1000u
#define LPSPI_SR_REF_SHIFT                       12u
#define LPSPI_SR_REF_WIDTH                       1u
#define LPSPI_SR_REF(x)                          (((uint32)(((uint32)(x))<<LPSPI_SR_REF_SHIFT))&LPSPI_SR_REF_MASK)
#define LPSPI_SR_DMF_MASK                        0x2000u
#define LPSPI_SR_DMF_SHIFT                       13u
#define LPSPI_SR_DMF_WIDTH                       1u
#define LPSPI_SR_DMF(x)                          (((uint32)(((uint32)(x))<<LPSPI_SR_DMF_SHIFT))&LPSPI_SR_DMF_MASK)
#define LPSPI_SR_MBF_MASK                        0x1000000u
#define LPSPI_SR_MBF_SHIFT                       24u
#define LPSPI_SR_MBF_WIDTH                       1u
#define LPSPI_SR_MBF(x)                          (((uint32)(((uint32)(x))<<LPSPI_SR_MBF_SHIFT))&LPSPI_SR_MBF_MASK)
/* IER Bit Fields */
#define LPSPI_IER_TDIE_MASK                      0x1u
#define LPSPI_IER_TDIE_SHIFT                     0u
#define LPSPI_IER_TDIE_WIDTH                     1u
#define LPSPI_IER_TDIE(x)                        (((uint32)(((uint32)(x))<<LPSPI_IER_TDIE_SHIFT))&LPSPI_IER_TDIE_MASK)
#define LPSPI_IER_RDIE_MASK                      0x2u
#define LPSPI_IER_RDIE_SHIFT                     1u
#define LPSPI_IER_RDIE_WIDTH                     1u
#define LPSPI_IER_RDIE(x)                        (((uint32)(((uint32)(x))<<LPSPI_IER_RDIE_SHIFT))&LPSPI_IER_RDIE_MASK)
#define LPSPI_IER_WCIE_MASK                      0x100u
#define LPSPI_IER_WCIE_SHIFT                     8u
#define LPSPI_IER_WCIE_WIDTH                     1u
#define LPSPI_IER_WCIE(x)                        (((uint32)(((uint32)(x))<<LPSPI_IER_WCIE_SHIFT))&LPSPI_IER_WCIE_MASK)
#define LPSPI_IER_FCIE_MASK                      0x200u
#define LPSPI_IER_FCIE_SHIFT                     9u
#define LPSPI_IER_FCIE_WIDTH                     1u
#define LPSPI_IER_FCIE(x)                        (((uint32)(((uint32)(x))<<LPSPI_IER_FCIE_SHIFT))&LPSPI_IER_FCIE_MASK)
#define LPSPI_IER_TCIE_MASK                      0x400u
#define LPSPI_IER_TCIE_SHIFT                     10u
#define LPSPI_IER_TCIE_WIDTH                     1u
#define LPSPI_IER_TCIE(x)                        (((uint32)(((uint32)(x))<<LPSPI_IER_TCIE_SHIFT))&LPSPI_IER_TCIE_MASK)
#define LPSPI_IER_TEIE_MASK                      0x800u
#define LPSPI_IER_TEIE_SHIFT                     11u
#define LPSPI_IER_TEIE_WIDTH                     1u
#define LPSPI_IER_TEIE(x)                        (((uint32)(((uint32)(x))<<LPSPI_IER_TEIE_SHIFT))&LPSPI_IER_TEIE_MASK)
#define LPSPI_IER_REIE_MASK                      0x1000u
#define LPSPI_IER_REIE_SHIFT                     12u
#define LPSPI_IER_REIE_WIDTH                     1u
#define LPSPI_IER_REIE(x)                        (((uint32)(((uint32)(x))<<LPSPI_IER_REIE_SHIFT))&LPSPI_IER_REIE_MASK)
#define LPSPI_IER_DMIE_MASK                      0x2000u
#define LPSPI_IER_DMIE_SHIFT                     13u
#define LPSPI_IER_DMIE_WIDTH                     1u
#define LPSPI_IER_DMIE(x)                        (((uint32)(((uint32)(x))<<LPSPI_IER_DMIE_SHIFT))&LPSPI_IER_DMIE_MASK)
/* DER Bit Fields */
#define LPSPI_DER_TDDE_MASK                      0x1u
#define LPSPI_DER_TDDE_SHIFT                     0u
#define LPSPI_DER_TDDE_WIDTH                     1u
#define LPSPI_DER_TDDE(x)                        (((uint32)(((uint32)(x))<<LPSPI_DER_TDDE_SHIFT))&LPSPI_DER_TDDE_MASK)
#define LPSPI_DER_RDDE_MASK                      0x2u
#define LPSPI_DER_RDDE_SHIFT                     1u
#define LPSPI_DER_RDDE_WIDTH                     1u
#define LPSPI_DER_RDDE(x)                        (((uint32)(((uint32)(x))<<LPSPI_DER_RDDE_SHIFT))&LPSPI_DER_RDDE_MASK)
/* CFGR0 Bit Fields */
#define LPSPI_CFGR0_HREN_MASK                    0x1u
#define LPSPI_CFGR0_HREN_SHIFT                   0u
#define LPSPI_CFGR0_HREN_WIDTH                   1u
#define LPSPI_CFGR0_HREN(x)                      (((uint32)(((uint32)(x))<<LPSPI_CFGR0_HREN_SHIFT))&LPSPI_CFGR0_HREN_MASK)
#define LPSPI_CFGR0_HRPOL_MASK                   0x2u
#define LPSPI_CFGR0_HRPOL_SHIFT                  1u
#define LPSPI_CFGR0_HRPOL_WIDTH                  1u
#define LPSPI_CFGR0_HRPOL(x)                     (((uint32)(((uint32)(x))<<LPSPI_CFGR0_HRPOL_SHIFT))&LPSPI_CFGR0_HRPOL_MASK)
#define LPSPI_CFGR0_HRSEL_MASK                   0x4u
#define LPSPI_CFGR0_HRSEL_SHIFT                  2u
#define LPSPI_CFGR0_HRSEL_WIDTH                  1u
#define LPSPI_CFGR0_HRSEL(x)                     (((uint32)(((uint32)(x))<<LPSPI_CFGR0_HRSEL_SHIFT))&LPSPI_CFGR0_HRSEL_MASK)
#define LPSPI_CFGR0_CIRFIFO_MASK                 0x100u
#define LPSPI_CFGR0_CIRFIFO_SHIFT                8u
#define LPSPI_CFGR0_CIRFIFO_WIDTH                1u
#define LPSPI_CFGR0_CIRFIFO(x)                   (((uint32)(((uint32)(x))<<LPSPI_CFGR0_CIRFIFO_SHIFT))&LPSPI_CFGR0_CIRFIFO_MASK)
#define LPSPI_CFGR0_RDMO_MASK                    0x200u
#define LPSPI_CFGR0_RDMO_SHIFT                   9u
#define LPSPI_CFGR0_RDMO_WIDTH                   1u
#define LPSPI_CFGR0_RDMO(x)                      (((uint32)(((uint32)(x))<<LPSPI_CFGR0_RDMO_SHIFT))&LPSPI_CFGR0_RDMO_MASK)
/* CFGR1 Bit Fields */
#define LPSPI_CFGR1_MASTER_MASK                  0x1u
#define LPSPI_CFGR1_MASTER_SHIFT                 0u
#define LPSPI_CFGR1_MASTER_WIDTH                 1u
#define LPSPI_CFGR1_MASTER(x)                    (((uint32)(((uint32)(x))<<LPSPI_CFGR1_MASTER_SHIFT))&LPSPI_CFGR1_MASTER_MASK)
#define LPSPI_CFGR1_SAMPLE_MASK                  0x2u
#define LPSPI_CFGR1_SAMPLE_SHIFT                 1u
#define LPSPI_CFGR1_SAMPLE_WIDTH                 1u
#define LPSPI_CFGR1_SAMPLE(x)                    (((uint32)(((uint32)(x))<<LPSPI_CFGR1_SAMPLE_SHIFT))&LPSPI_CFGR1_SAMPLE_MASK)
#define LPSPI_CFGR1_AUTOPCS_MASK                 0x4u
#define LPSPI_CFGR1_AUTOPCS_SHIFT                2u
#define LPSPI_CFGR1_AUTOPCS_WIDTH                1u
#define LPSPI_CFGR1_AUTOPCS(x)                   (((uint32)(((uint32)(x))<<LPSPI_CFGR1_AUTOPCS_SHIFT))&LPSPI_CFGR1_AUTOPCS_MASK)
#define LPSPI_CFGR1_NOSTALL_MASK                 0x8u
#define LPSPI_CFGR1_NOSTALL_SHIFT                3u
#define LPSPI_CFGR1_NOSTALL_WIDTH                1u
#define LPSPI_CFGR1_NOSTALL(x)                   (((uint32)(((uint32)(x))<<LPSPI_CFGR1_NOSTALL_SHIFT))&LPSPI_CFGR1_NOSTALL_MASK)
#define LPSPI_CFGR1_PCSPOL_MASK                  0xF00u
#define LPSPI_CFGR1_PCSPOL_SHIFT                 8u
#define LPSPI_CFGR1_PCSPOL_WIDTH                 4u
#define LPSPI_CFGR1_PCSPOL(x)                    (((uint32)(((uint32)(x))<<LPSPI_CFGR1_PCSPOL_SHIFT))&LPSPI_CFGR1_PCSPOL_MASK)
#define LPSPI_CFGR1_MATCFG_MASK                  0x70000u
#define LPSPI_CFGR1_MATCFG_SHIFT                 16u
#define LPSPI_CFGR1_MATCFG_WIDTH                 3u
#define LPSPI_CFGR1_MATCFG(x)                    (((uint32)(((uint32)(x))<<LPSPI_CFGR1_MATCFG_SHIFT))&LPSPI_CFGR1_MATCFG_MASK)
#define LPSPI_CFGR1_PINCFG_MASK                  0x3000000u
#define LPSPI_CFGR1_PINCFG_SHIFT                 24u
#define LPSPI_CFGR1_PINCFG_WIDTH                 2u
#define LPSPI_CFGR1_PINCFG(x)                    (((uint32)(((uint32)(x))<<LPSPI_CFGR1_PINCFG_SHIFT))&LPSPI_CFGR1_PINCFG_MASK)
#define LPSPI_CFGR1_OUTCFG_MASK                  0x4000000u
#define LPSPI_CFGR1_OUTCFG_SHIFT                 26u
#define LPSPI_CFGR1_OUTCFG_WIDTH                 1u
#define LPSPI_CFGR1_OUTCFG(x)                    (((uint32)(((uint32)(x))<<LPSPI_CFGR1_OUTCFG_SHIFT))&LPSPI_CFGR1_OUTCFG_MASK)
#define LPSPI_CFGR1_PCSCFG_MASK                  0x8000000u
#define LPSPI_CFGR1_PCSCFG_SHIFT                 27u
#define LPSPI_CFGR1_PCSCFG_WIDTH                 1u
#define LPSPI_CFGR1_PCSCFG(x)                    (((uint32)(((uint32)(x))<<LPSPI_CFGR1_PCSCFG_SHIFT))&LPSPI_CFGR1_PCSCFG_MASK)
/* DMR0 Bit Fields */
#define LPSPI_DMR0_MATCH0_MASK                   0xFFFFFFFFu
#define LPSPI_DMR0_MATCH0_SHIFT                  0u
#define LPSPI_DMR0_MATCH0_WIDTH                  32u
#define LPSPI_DMR0_MATCH0(x)                     (((uint32)(((uint32)(x))<<LPSPI_DMR0_MATCH0_SHIFT))&LPSPI_DMR0_MATCH0_MASK)
/* DMR1 Bit Fields */
#define LPSPI_DMR1_MATCH1_MASK                   0xFFFFFFFFu
#define LPSPI_DMR1_MATCH1_SHIFT                  0u
#define LPSPI_DMR1_MATCH1_WIDTH                  32u
#define LPSPI_DMR1_MATCH1(x)                     (((uint32)(((uint32)(x))<<LPSPI_DMR1_MATCH1_SHIFT))&LPSPI_DMR1_MATCH1_MASK)
/* CCR Bit Fields */
#define LPSPI_CCR_SCKDIV_MASK                    0xFFu
#define LPSPI_CCR_SCKDIV_SHIFT                   0u
#define LPSPI_CCR_SCKDIV_WIDTH                   8u
#define LPSPI_CCR_SCKDIV(x)                      (((uint32)(((uint32)(x))<<LPSPI_CCR_SCKDIV_SHIFT))&LPSPI_CCR_SCKDIV_MASK)
#define LPSPI_CCR_DBT_MASK                       0xFF00u
#define LPSPI_CCR_DBT_SHIFT                      8u
#define LPSPI_CCR_DBT_WIDTH                      8u
#define LPSPI_CCR_DBT(x)                         (((uint32)(((uint32)(x))<<LPSPI_CCR_DBT_SHIFT))&LPSPI_CCR_DBT_MASK)
#define LPSPI_CCR_PCSSCK_MASK                    0xFF0000u
#define LPSPI_CCR_PCSSCK_SHIFT                   16u
#define LPSPI_CCR_PCSSCK_WIDTH                   8u
#define LPSPI_CCR_PCSSCK(x)                      (((uint32)(((uint32)(x))<<LPSPI_CCR_PCSSCK_SHIFT))&LPSPI_CCR_PCSSCK_MASK)
#define LPSPI_CCR_SCKPCS_MASK                    0xFF000000u
#define LPSPI_CCR_SCKPCS_SHIFT                   24u
#define LPSPI_CCR_SCKPCS_WIDTH                   8u
#define LPSPI_CCR_SCKPCS(x)                      (((uint32)(((uint32)(x))<<LPSPI_CCR_SCKPCS_SHIFT))&LPSPI_CCR_SCKPCS_MASK)
/* FCR Bit Fields */
#define LPSPI_FCR_TXWATER_MASK                   0x3u
#define LPSPI_FCR_TXWATER_SHIFT                  0u
#define LPSPI_FCR_TXWATER_WIDTH                  2u
#define LPSPI_FCR_TXWATER(x)                     (((uint32)(((uint32)(x))<<LPSPI_FCR_TXWATER_SHIFT))&LPSPI_FCR_TXWATER_MASK)
#define LPSPI_FCR_RXWATER_MASK                   0x30000u
#define LPSPI_FCR_RXWATER_SHIFT                  16u
#define LPSPI_FCR_RXWATER_WIDTH                  2u
#define LPSPI_FCR_RXWATER(x)                     (((uint32)(((uint32)(x))<<LPSPI_FCR_RXWATER_SHIFT))&LPSPI_FCR_RXWATER_MASK)
/* FSR Bit Fields */
#define LPSPI_FSR_TXCOUNT_MASK                   0x7u
#define LPSPI_FSR_TXCOUNT_SHIFT                  0u
#define LPSPI_FSR_TXCOUNT_WIDTH                  3u
#define LPSPI_FSR_TXCOUNT(x)                     (((uint32)(((uint32)(x))<<LPSPI_FSR_TXCOUNT_SHIFT))&LPSPI_FSR_TXCOUNT_MASK)
#define LPSPI_FSR_RXCOUNT_MASK                   0x70000u
#define LPSPI_FSR_RXCOUNT_SHIFT                  16u
#define LPSPI_FSR_RXCOUNT_WIDTH                  3u
#define LPSPI_FSR_RXCOUNT(x)                     (((uint32)(((uint32)(x))<<LPSPI_FSR_RXCOUNT_SHIFT))&LPSPI_FSR_RXCOUNT_MASK)
/* TCR Bit Fields */
#define LPSPI_TCR_FRAMESZ_MASK                   0xFFFu
#define LPSPI_TCR_FRAMESZ_SHIFT                  0u
#define LPSPI_TCR_FRAMESZ_WIDTH                  12u
#define LPSPI_TCR_FRAMESZ(x)                     (((uint32)(((uint32)(x))<<LPSPI_TCR_FRAMESZ_SHIFT))&LPSPI_TCR_FRAMESZ_MASK)
#define LPSPI_TCR_WIDTH_MASK                     0x30000u
#define LPSPI_TCR_WIDTH_SHIFT                    16u
#define LPSPI_TCR_WIDTH_WIDTH                    2u
#define LPSPI_TCR_WIDTH(x)                       (((uint32)(((uint32)(x))<<LPSPI_TCR_WIDTH_SHIFT))&LPSPI_TCR_WIDTH_MASK)
#define LPSPI_TCR_TXMSK_MASK                     0x40000u
#define LPSPI_TCR_TXMSK_SHIFT                    18u
#define LPSPI_TCR_TXMSK_WIDTH                    1u
#define LPSPI_TCR_TXMSK(x)                       (((uint32)(((uint32)(x))<<LPSPI_TCR_TXMSK_SHIFT))&LPSPI_TCR_TXMSK_MASK)
#define LPSPI_TCR_RXMSK_MASK                     0x80000u
#define LPSPI_TCR_RXMSK_SHIFT                    19u
#define LPSPI_TCR_RXMSK_WIDTH                    1u
#define LPSPI_TCR_RXMSK(x)                       (((uint32)(((uint32)(x))<<LPSPI_TCR_RXMSK_SHIFT))&LPSPI_TCR_RXMSK_MASK)
#define LPSPI_TCR_CONTC_MASK                     0x100000u
#define LPSPI_TCR_CONTC_SHIFT                    20u
#define LPSPI_TCR_CONTC_WIDTH                    1u
#define LPSPI_TCR_CONTC(x)                       (((uint32)(((uint32)(x))<<LPSPI_TCR_CONTC_SHIFT))&LPSPI_TCR_CONTC_MASK)
#define LPSPI_TCR_CONT_MASK                      0x200000u
#define LPSPI_TCR_CONT_SHIFT                     21u
#define LPSPI_TCR_CONT_WIDTH                     1u
#define LPSPI_TCR_CONT(x)                        (((uint32)(((uint32)(x))<<LPSPI_TCR_CONT_SHIFT))&LPSPI_TCR_CONT_MASK)
#define LPSPI_TCR_BYSW_MASK                      0x400000u
#define LPSPI_TCR_BYSW_SHIFT                     22u
#define LPSPI_TCR_BYSW_WIDTH                     1u
#define LPSPI_TCR_BYSW(x)                        (((uint32)(((uint32)(x))<<LPSPI_TCR_BYSW_SHIFT))&LPSPI_TCR_BYSW_MASK)
#define LPSPI_TCR_LSBF_MASK                      0x800000u
#define LPSPI_TCR_LSBF_SHIFT                     23u
#define LPSPI_TCR_LSBF_WIDTH                     1u
#define LPSPI_TCR_LSBF(x)                        (((uint32)(((uint32)(x))<<LPSPI_TCR_LSBF_SHIFT))&LPSPI_TCR_LSBF_MASK)
#define LPSPI_TCR_PCS_MASK                       0x3000000u
#define LPSPI_TCR_PCS_SHIFT                      24u
#define LPSPI_TCR_PCS_WIDTH                      2u
#define LPSPI_TCR_PCS(x)                         (((uint32)(((uint32)(x))<<LPSPI_TCR_PCS_SHIFT))&LPSPI_TCR_PCS_MASK)
#define LPSPI_TCR_PRESCALE_MASK                  0x38000000u
#define LPSPI_TCR_PRESCALE_SHIFT                 27u
#define LPSPI_TCR_PRESCALE_WIDTH                 3u
#define LPSPI_TCR_PRESCALE(x)                    (((uint32)(((uint32)(x))<<LPSPI_TCR_PRESCALE_SHIFT))&LPSPI_TCR_PRESCALE_MASK)
#define LPSPI_TCR_CPHA_MASK                      0x40000000u
#define LPSPI_TCR_CPHA_SHIFT                     30u
#define LPSPI_TCR_CPHA_WIDTH                     1u
#define LPSPI_TCR_CPHA(x)                        (((uint32)(((uint32)(x))<<LPSPI_TCR_CPHA_SHIFT))&LPSPI_TCR_CPHA_MASK)
#define LPSPI_TCR_CPOL_MASK                      0x80000000u
#define LPSPI_TCR_CPOL_SHIFT                     31u
#define LPSPI_TCR_CPOL_WIDTH                     1u
#define LPSPI_TCR_CPOL(x)                        (((uint32)(((uint32)(x))<<LPSPI_TCR_CPOL_SHIFT))&LPSPI_TCR_CPOL_MASK)
/* TDR Bit Fields */
#define LPSPI_TDR_DATA_MASK                      0xFFFFFFFFu
#define LPSPI_TDR_DATA_SHIFT                     0u
#define LPSPI_TDR_DATA_WIDTH                     32u
#define LPSPI_TDR_DATA(x)                        (((uint32)(((uint32)(x))<<LPSPI_TDR_DATA_SHIFT))&LPSPI_TDR_DATA_MASK)
/* RSR Bit Fields */
#define LPSPI_RSR_SOF_MASK                       0x1u
#define LPSPI_RSR_SOF_SHIFT                      0u
#define LPSPI_RSR_SOF_WIDTH                      1u
#define LPSPI_RSR_SOF(x)                         (((uint32)(((uint32)(x))<<LPSPI_RSR_SOF_SHIFT))&LPSPI_RSR_SOF_MASK)
#define LPSPI_RSR_RXEMPTY_MASK                   0x2u
#define LPSPI_RSR_RXEMPTY_SHIFT                  1u
#define LPSPI_RSR_RXEMPTY_WIDTH                  1u
#define LPSPI_RSR_RXEMPTY(x)                     (((uint32)(((uint32)(x))<<LPSPI_RSR_RXEMPTY_SHIFT))&LPSPI_RSR_RXEMPTY_MASK)
/* RDR Bit Fields */
#define LPSPI_RDR_DATA_MASK                      0xFFFFFFFFu
#define LPSPI_RDR_DATA_SHIFT                     0u
#define LPSPI_RDR_DATA_WIDTH                     32u
#define LPSPI_RDR_DATA(x)                        (((uint32)(((uint32)(x))<<LPSPI_RDR_DATA_SHIFT))&LPSPI_RDR_DATA_MASK)

/*!
 * @}
 */ /* end of group LPSPI_Register_Masks */


/*!
 * @}
 */ /* end of group LPSPI_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPTMR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPTMR_Peripheral_Access_Layer LPTMR Peripheral Access Layer
 * @{
 */


/** LPTMR - Size of Registers Arrays */

/** LPTMR - Register Layout Typedef */
typedef struct {
  __IO uint32 CSR;                               /**< Low Power Timer Control Status Register, offset: 0x0 */
  __IO uint32 PSR;                               /**< Low Power Timer Prescale Register, offset: 0x4 */
  __IO uint32 CMR;                               /**< Low Power Timer Compare Register, offset: 0x8 */
  __IO uint32 CNR;                               /**< Low Power Timer Counter Register, offset: 0xC */
} LPTMR_Type, *LPTMR_MemMapPtr;

 /** Number of instances of the LPTMR module. */
#define LPTMR_INSTANCE_COUNT                     (1u)


/* LPTMR - Peripheral instance base addresses */
/** Peripheral LPTMR0 base address */
#define LPTMR0_BASE                              (0x40040000u)
/** Peripheral LPTMR0 base pointer */
#define LPTMR0                                   ((LPTMR_Type *)LPTMR0_BASE)
/** Array initializer of LPTMR peripheral base addresses */
#define LPTMR_BASE_ADDRS                         { LPTMR0_BASE }
/** Array initializer of LPTMR peripheral base pointers */
#define LPTMR_BASE_PTRS                          { LPTMR0 }
 /** Number of interrupt vector arrays for the LPTMR module. */
#define LPTMR_IRQS_ARR_COUNT                     (1u)
 /** Number of interrupt channels for the LPTMR module. */
#define LPTMR_IRQS_CH_COUNT                      (1u)
/** Interrupt vectors for the LPTMR peripheral type */
#define LPTMR_IRQS                               { LPTMR0_IRQn }

/* ----------------------------------------------------------------------------
   -- LPTMR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPTMR_Register_Masks LPTMR Register Masks
 * @{
 */

/* CSR Bit Fields */
#define LPTMR_CSR_TEN_MASK                       0x1u
#define LPTMR_CSR_TEN_SHIFT                      0u
#define LPTMR_CSR_TEN_WIDTH                      1u
#define LPTMR_CSR_TEN(x)                         (((uint32)(((uint32)(x))<<LPTMR_CSR_TEN_SHIFT))&LPTMR_CSR_TEN_MASK)
#define LPTMR_CSR_TMS_MASK                       0x2u
#define LPTMR_CSR_TMS_SHIFT                      1u
#define LPTMR_CSR_TMS_WIDTH                      1u
#define LPTMR_CSR_TMS(x)                         (((uint32)(((uint32)(x))<<LPTMR_CSR_TMS_SHIFT))&LPTMR_CSR_TMS_MASK)
#define LPTMR_CSR_TFC_MASK                       0x4u
#define LPTMR_CSR_TFC_SHIFT                      2u
#define LPTMR_CSR_TFC_WIDTH                      1u
#define LPTMR_CSR_TFC(x)                         (((uint32)(((uint32)(x))<<LPTMR_CSR_TFC_SHIFT))&LPTMR_CSR_TFC_MASK)
#define LPTMR_CSR_TPP_MASK                       0x8u
#define LPTMR_CSR_TPP_SHIFT                      3u
#define LPTMR_CSR_TPP_WIDTH                      1u
#define LPTMR_CSR_TPP(x)                         (((uint32)(((uint32)(x))<<LPTMR_CSR_TPP_SHIFT))&LPTMR_CSR_TPP_MASK)
#define LPTMR_CSR_TPS_MASK                       0x30u
#define LPTMR_CSR_TPS_SHIFT                      4u
#define LPTMR_CSR_TPS_WIDTH                      2u
#define LPTMR_CSR_TPS(x)                         (((uint32)(((uint32)(x))<<LPTMR_CSR_TPS_SHIFT))&LPTMR_CSR_TPS_MASK)
#define LPTMR_CSR_TIE_MASK                       0x40u
#define LPTMR_CSR_TIE_SHIFT                      6u
#define LPTMR_CSR_TIE_WIDTH                      1u
#define LPTMR_CSR_TIE(x)                         (((uint32)(((uint32)(x))<<LPTMR_CSR_TIE_SHIFT))&LPTMR_CSR_TIE_MASK)
#define LPTMR_CSR_TCF_MASK                       0x80u
#define LPTMR_CSR_TCF_SHIFT                      7u
#define LPTMR_CSR_TCF_WIDTH                      1u
#define LPTMR_CSR_TCF(x)                         (((uint32)(((uint32)(x))<<LPTMR_CSR_TCF_SHIFT))&LPTMR_CSR_TCF_MASK)
#define LPTMR_CSR_TDRE_MASK                      0x100u
#define LPTMR_CSR_TDRE_SHIFT                     8u
#define LPTMR_CSR_TDRE_WIDTH                     1u
#define LPTMR_CSR_TDRE(x)                        (((uint32)(((uint32)(x))<<LPTMR_CSR_TDRE_SHIFT))&LPTMR_CSR_TDRE_MASK)
/* PSR Bit Fields */
#define LPTMR_PSR_PCS_MASK                       0x3u
#define LPTMR_PSR_PCS_SHIFT                      0u
#define LPTMR_PSR_PCS_WIDTH                      2u
#define LPTMR_PSR_PCS(x)                         (((uint32)(((uint32)(x))<<LPTMR_PSR_PCS_SHIFT))&LPTMR_PSR_PCS_MASK)
#define LPTMR_PSR_PBYP_MASK                      0x4u
#define LPTMR_PSR_PBYP_SHIFT                     2u
#define LPTMR_PSR_PBYP_WIDTH                     1u
#define LPTMR_PSR_PBYP(x)                        (((uint32)(((uint32)(x))<<LPTMR_PSR_PBYP_SHIFT))&LPTMR_PSR_PBYP_MASK)
#define LPTMR_PSR_PRESCALE_MASK                  0x78u
#define LPTMR_PSR_PRESCALE_SHIFT                 3u
#define LPTMR_PSR_PRESCALE_WIDTH                 4u
#define LPTMR_PSR_PRESCALE(x)                    (((uint32)(((uint32)(x))<<LPTMR_PSR_PRESCALE_SHIFT))&LPTMR_PSR_PRESCALE_MASK)
/* CMR Bit Fields */
#define LPTMR_CMR_COMPARE_MASK                   0xFFFFu
#define LPTMR_CMR_COMPARE_SHIFT                  0u
#define LPTMR_CMR_COMPARE_WIDTH                  16u
#define LPTMR_CMR_COMPARE(x)                     (((uint32)(((uint32)(x))<<LPTMR_CMR_COMPARE_SHIFT))&LPTMR_CMR_COMPARE_MASK)
/* CNR Bit Fields */
#define LPTMR_CNR_COUNTER_MASK                   0xFFFFu
#define LPTMR_CNR_COUNTER_SHIFT                  0u
#define LPTMR_CNR_COUNTER_WIDTH                  16u
#define LPTMR_CNR_COUNTER(x)                     (((uint32)(((uint32)(x))<<LPTMR_CNR_COUNTER_SHIFT))&LPTMR_CNR_COUNTER_MASK)

/*!
 * @}
 */ /* end of group LPTMR_Register_Masks */


/*!
 * @}
 */ /* end of group LPTMR_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPUART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPUART_Peripheral_Access_Layer LPUART Peripheral Access Layer
 * @{
 */


/** LPUART - Size of Registers Arrays */

/** LPUART - Register Layout Typedef */
typedef struct {
  __I  uint32 VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32 PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32 GLOBAL;                            /**< LPUART Global Register, offset: 0x8 */
  __IO uint32 PINCFG;                            /**< LPUART Pin Configuration Register, offset: 0xC */
  __IO uint32 BAUD;                              /**< LPUART Baud Rate Register, offset: 0x10 */
  __IO uint32 STAT;                              /**< LPUART Status Register, offset: 0x14 */
  __IO uint32 CTRL;                              /**< LPUART Control Register, offset: 0x18 */
  __IO uint32 DATA;                              /**< LPUART Data Register, offset: 0x1C */
  __IO uint32 MATCH;                             /**< LPUART Match Address Register, offset: 0x20 */
  __IO uint32 MODIR;                             /**< LPUART Modem IrDA Register, offset: 0x24 */
  __IO uint32 FIFO;                              /**< LPUART FIFO Register, offset: 0x28 */
  __IO uint32 WATER;                             /**< LPUART Watermark Register, offset: 0x2C */
} LPUART_Type, *LPUART_MemMapPtr;

 /** Number of instances of the LPUART module. */
#define LPUART_INSTANCE_COUNT                    (3u)


/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART0 base address */
#define LPUART0_BASE                             (0x4006A000u)
/** Peripheral LPUART0 base pointer */
#define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)
/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0x4006B000u)
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)
/** Peripheral LPUART2 base address */
#define LPUART2_BASE                             (0x4006C000u)
/** Peripheral LPUART2 base pointer */
#define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        { LPUART0_BASE, LPUART1_BASE, LPUART2_BASE }
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         { LPUART0, LPUART1, LPUART2 }
 /** Number of interrupt vector arrays for the LPUART module. */
#define LPUART_IRQS_ARR_COUNT                    (1u)
 /** Number of interrupt channels for the RX_TX type of LPUART module. */
#define LPUART_RX_TX_IRQS_CH_COUNT               (1u)
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART0_RxTx_IRQn, LPUART1_RxTx_IRQn, LPUART2_RxTx_IRQn }

/* ----------------------------------------------------------------------------
   -- LPUART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPUART_Register_Masks LPUART Register Masks
 * @{
 */

/* VERID Bit Fields */
#define LPUART_VERID_FEATURE_MASK                0xFFFFu
#define LPUART_VERID_FEATURE_SHIFT               0u
#define LPUART_VERID_FEATURE_WIDTH               16u
#define LPUART_VERID_FEATURE(x)                  (((uint32)(((uint32)(x))<<LPUART_VERID_FEATURE_SHIFT))&LPUART_VERID_FEATURE_MASK)
#define LPUART_VERID_MINOR_MASK                  0xFF0000u
#define LPUART_VERID_MINOR_SHIFT                 16u
#define LPUART_VERID_MINOR_WIDTH                 8u
#define LPUART_VERID_MINOR(x)                    (((uint32)(((uint32)(x))<<LPUART_VERID_MINOR_SHIFT))&LPUART_VERID_MINOR_MASK)
#define LPUART_VERID_MAJOR_MASK                  0xFF000000u
#define LPUART_VERID_MAJOR_SHIFT                 24u
#define LPUART_VERID_MAJOR_WIDTH                 8u
#define LPUART_VERID_MAJOR(x)                    (((uint32)(((uint32)(x))<<LPUART_VERID_MAJOR_SHIFT))&LPUART_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define LPUART_PARAM_TXFIFO_MASK                 0xFFu
#define LPUART_PARAM_TXFIFO_SHIFT                0u
#define LPUART_PARAM_TXFIFO_WIDTH                8u
#define LPUART_PARAM_TXFIFO(x)                   (((uint32)(((uint32)(x))<<LPUART_PARAM_TXFIFO_SHIFT))&LPUART_PARAM_TXFIFO_MASK)
#define LPUART_PARAM_RXFIFO_MASK                 0xFF00u
#define LPUART_PARAM_RXFIFO_SHIFT                8u
#define LPUART_PARAM_RXFIFO_WIDTH                8u
#define LPUART_PARAM_RXFIFO(x)                   (((uint32)(((uint32)(x))<<LPUART_PARAM_RXFIFO_SHIFT))&LPUART_PARAM_RXFIFO_MASK)
/* GLOBAL Bit Fields */
#define LPUART_GLOBAL_RST_MASK                   0x2u
#define LPUART_GLOBAL_RST_SHIFT                  1u
#define LPUART_GLOBAL_RST_WIDTH                  1u
#define LPUART_GLOBAL_RST(x)                     (((uint32)(((uint32)(x))<<LPUART_GLOBAL_RST_SHIFT))&LPUART_GLOBAL_RST_MASK)
/* PINCFG Bit Fields */
#define LPUART_PINCFG_TRGSEL_MASK                0x3u
#define LPUART_PINCFG_TRGSEL_SHIFT               0u
#define LPUART_PINCFG_TRGSEL_WIDTH               2u
#define LPUART_PINCFG_TRGSEL(x)                  (((uint32)(((uint32)(x))<<LPUART_PINCFG_TRGSEL_SHIFT))&LPUART_PINCFG_TRGSEL_MASK)
/* BAUD Bit Fields */
#define LPUART_BAUD_SBR_MASK                     0x1FFFu
#define LPUART_BAUD_SBR_SHIFT                    0u
#define LPUART_BAUD_SBR_WIDTH                    13u
#define LPUART_BAUD_SBR(x)                       (((uint32)(((uint32)(x))<<LPUART_BAUD_SBR_SHIFT))&LPUART_BAUD_SBR_MASK)
#define LPUART_BAUD_SBNS_MASK                    0x2000u
#define LPUART_BAUD_SBNS_SHIFT                   13u
#define LPUART_BAUD_SBNS_WIDTH                   1u
#define LPUART_BAUD_SBNS(x)                      (((uint32)(((uint32)(x))<<LPUART_BAUD_SBNS_SHIFT))&LPUART_BAUD_SBNS_MASK)
#define LPUART_BAUD_RXEDGIE_MASK                 0x4000u
#define LPUART_BAUD_RXEDGIE_SHIFT                14u
#define LPUART_BAUD_RXEDGIE_WIDTH                1u
#define LPUART_BAUD_RXEDGIE(x)                   (((uint32)(((uint32)(x))<<LPUART_BAUD_RXEDGIE_SHIFT))&LPUART_BAUD_RXEDGIE_MASK)
#define LPUART_BAUD_LBKDIE_MASK                  0x8000u
#define LPUART_BAUD_LBKDIE_SHIFT                 15u
#define LPUART_BAUD_LBKDIE_WIDTH                 1u
#define LPUART_BAUD_LBKDIE(x)                    (((uint32)(((uint32)(x))<<LPUART_BAUD_LBKDIE_SHIFT))&LPUART_BAUD_LBKDIE_MASK)
#define LPUART_BAUD_RESYNCDIS_MASK               0x10000u
#define LPUART_BAUD_RESYNCDIS_SHIFT              16u
#define LPUART_BAUD_RESYNCDIS_WIDTH              1u
#define LPUART_BAUD_RESYNCDIS(x)                 (((uint32)(((uint32)(x))<<LPUART_BAUD_RESYNCDIS_SHIFT))&LPUART_BAUD_RESYNCDIS_MASK)
#define LPUART_BAUD_BOTHEDGE_MASK                0x20000u
#define LPUART_BAUD_BOTHEDGE_SHIFT               17u
#define LPUART_BAUD_BOTHEDGE_WIDTH               1u
#define LPUART_BAUD_BOTHEDGE(x)                  (((uint32)(((uint32)(x))<<LPUART_BAUD_BOTHEDGE_SHIFT))&LPUART_BAUD_BOTHEDGE_MASK)
#define LPUART_BAUD_MATCFG_MASK                  0xC0000u
#define LPUART_BAUD_MATCFG_SHIFT                 18u
#define LPUART_BAUD_MATCFG_WIDTH                 2u
#define LPUART_BAUD_MATCFG(x)                    (((uint32)(((uint32)(x))<<LPUART_BAUD_MATCFG_SHIFT))&LPUART_BAUD_MATCFG_MASK)
#define LPUART_BAUD_RIDMAE_MASK                  0x100000u
#define LPUART_BAUD_RIDMAE_SHIFT                 20u
#define LPUART_BAUD_RIDMAE_WIDTH                 1u
#define LPUART_BAUD_RIDMAE(x)                    (((uint32)(((uint32)(x))<<LPUART_BAUD_RIDMAE_SHIFT))&LPUART_BAUD_RIDMAE_MASK)
#define LPUART_BAUD_RDMAE_MASK                   0x200000u
#define LPUART_BAUD_RDMAE_SHIFT                  21u
#define LPUART_BAUD_RDMAE_WIDTH                  1u
#define LPUART_BAUD_RDMAE(x)                     (((uint32)(((uint32)(x))<<LPUART_BAUD_RDMAE_SHIFT))&LPUART_BAUD_RDMAE_MASK)
#define LPUART_BAUD_TDMAE_MASK                   0x800000u
#define LPUART_BAUD_TDMAE_SHIFT                  23u
#define LPUART_BAUD_TDMAE_WIDTH                  1u
#define LPUART_BAUD_TDMAE(x)                     (((uint32)(((uint32)(x))<<LPUART_BAUD_TDMAE_SHIFT))&LPUART_BAUD_TDMAE_MASK)
#define LPUART_BAUD_OSR_MASK                     0x1F000000u
#define LPUART_BAUD_OSR_SHIFT                    24u
#define LPUART_BAUD_OSR_WIDTH                    5u
#define LPUART_BAUD_OSR(x)                       (((uint32)(((uint32)(x))<<LPUART_BAUD_OSR_SHIFT))&LPUART_BAUD_OSR_MASK)
#define LPUART_BAUD_M10_MASK                     0x20000000u
#define LPUART_BAUD_M10_SHIFT                    29u
#define LPUART_BAUD_M10_WIDTH                    1u
#define LPUART_BAUD_M10(x)                       (((uint32)(((uint32)(x))<<LPUART_BAUD_M10_SHIFT))&LPUART_BAUD_M10_MASK)
#define LPUART_BAUD_MAEN2_MASK                   0x40000000u
#define LPUART_BAUD_MAEN2_SHIFT                  30u
#define LPUART_BAUD_MAEN2_WIDTH                  1u
#define LPUART_BAUD_MAEN2(x)                     (((uint32)(((uint32)(x))<<LPUART_BAUD_MAEN2_SHIFT))&LPUART_BAUD_MAEN2_MASK)
#define LPUART_BAUD_MAEN1_MASK                   0x80000000u
#define LPUART_BAUD_MAEN1_SHIFT                  31u
#define LPUART_BAUD_MAEN1_WIDTH                  1u
#define LPUART_BAUD_MAEN1(x)                     (((uint32)(((uint32)(x))<<LPUART_BAUD_MAEN1_SHIFT))&LPUART_BAUD_MAEN1_MASK)
/* STAT Bit Fields */
#define LPUART_STAT_MA2F_MASK                    0x4000u
#define LPUART_STAT_MA2F_SHIFT                   14u
#define LPUART_STAT_MA2F_WIDTH                   1u
#define LPUART_STAT_MA2F(x)                      (((uint32)(((uint32)(x))<<LPUART_STAT_MA2F_SHIFT))&LPUART_STAT_MA2F_MASK)
#define LPUART_STAT_MA1F_MASK                    0x8000u
#define LPUART_STAT_MA1F_SHIFT                   15u
#define LPUART_STAT_MA1F_WIDTH                   1u
#define LPUART_STAT_MA1F(x)                      (((uint32)(((uint32)(x))<<LPUART_STAT_MA1F_SHIFT))&LPUART_STAT_MA1F_MASK)
#define LPUART_STAT_PF_MASK                      0x10000u
#define LPUART_STAT_PF_SHIFT                     16u
#define LPUART_STAT_PF_WIDTH                     1u
#define LPUART_STAT_PF(x)                        (((uint32)(((uint32)(x))<<LPUART_STAT_PF_SHIFT))&LPUART_STAT_PF_MASK)
#define LPUART_STAT_FE_MASK                      0x20000u
#define LPUART_STAT_FE_SHIFT                     17u
#define LPUART_STAT_FE_WIDTH                     1u
#define LPUART_STAT_FE(x)                        (((uint32)(((uint32)(x))<<LPUART_STAT_FE_SHIFT))&LPUART_STAT_FE_MASK)
#define LPUART_STAT_NF_MASK                      0x40000u
#define LPUART_STAT_NF_SHIFT                     18u
#define LPUART_STAT_NF_WIDTH                     1u
#define LPUART_STAT_NF(x)                        (((uint32)(((uint32)(x))<<LPUART_STAT_NF_SHIFT))&LPUART_STAT_NF_MASK)
#define LPUART_STAT_OR_MASK                      0x80000u
#define LPUART_STAT_OR_SHIFT                     19u
#define LPUART_STAT_OR_WIDTH                     1u
#define LPUART_STAT_OR(x)                        (((uint32)(((uint32)(x))<<LPUART_STAT_OR_SHIFT))&LPUART_STAT_OR_MASK)
#define LPUART_STAT_IDLE_MASK                    0x100000u
#define LPUART_STAT_IDLE_SHIFT                   20u
#define LPUART_STAT_IDLE_WIDTH                   1u
#define LPUART_STAT_IDLE(x)                      (((uint32)(((uint32)(x))<<LPUART_STAT_IDLE_SHIFT))&LPUART_STAT_IDLE_MASK)
#define LPUART_STAT_RDRF_MASK                    0x200000u
#define LPUART_STAT_RDRF_SHIFT                   21u
#define LPUART_STAT_RDRF_WIDTH                   1u
#define LPUART_STAT_RDRF(x)                      (((uint32)(((uint32)(x))<<LPUART_STAT_RDRF_SHIFT))&LPUART_STAT_RDRF_MASK)
#define LPUART_STAT_TC_MASK                      0x400000u
#define LPUART_STAT_TC_SHIFT                     22u
#define LPUART_STAT_TC_WIDTH                     1u
#define LPUART_STAT_TC(x)                        (((uint32)(((uint32)(x))<<LPUART_STAT_TC_SHIFT))&LPUART_STAT_TC_MASK)
#define LPUART_STAT_TDRE_MASK                    0x800000u
#define LPUART_STAT_TDRE_SHIFT                   23u
#define LPUART_STAT_TDRE_WIDTH                   1u
#define LPUART_STAT_TDRE(x)                      (((uint32)(((uint32)(x))<<LPUART_STAT_TDRE_SHIFT))&LPUART_STAT_TDRE_MASK)
#define LPUART_STAT_RAF_MASK                     0x1000000u
#define LPUART_STAT_RAF_SHIFT                    24u
#define LPUART_STAT_RAF_WIDTH                    1u
#define LPUART_STAT_RAF(x)                       (((uint32)(((uint32)(x))<<LPUART_STAT_RAF_SHIFT))&LPUART_STAT_RAF_MASK)
#define LPUART_STAT_LBKDE_MASK                   0x2000000u
#define LPUART_STAT_LBKDE_SHIFT                  25u
#define LPUART_STAT_LBKDE_WIDTH                  1u
#define LPUART_STAT_LBKDE(x)                     (((uint32)(((uint32)(x))<<LPUART_STAT_LBKDE_SHIFT))&LPUART_STAT_LBKDE_MASK)
#define LPUART_STAT_BRK13_MASK                   0x4000000u
#define LPUART_STAT_BRK13_SHIFT                  26u
#define LPUART_STAT_BRK13_WIDTH                  1u
#define LPUART_STAT_BRK13(x)                     (((uint32)(((uint32)(x))<<LPUART_STAT_BRK13_SHIFT))&LPUART_STAT_BRK13_MASK)
#define LPUART_STAT_RWUID_MASK                   0x8000000u
#define LPUART_STAT_RWUID_SHIFT                  27u
#define LPUART_STAT_RWUID_WIDTH                  1u
#define LPUART_STAT_RWUID(x)                     (((uint32)(((uint32)(x))<<LPUART_STAT_RWUID_SHIFT))&LPUART_STAT_RWUID_MASK)
#define LPUART_STAT_RXINV_MASK                   0x10000000u
#define LPUART_STAT_RXINV_SHIFT                  28u
#define LPUART_STAT_RXINV_WIDTH                  1u
#define LPUART_STAT_RXINV(x)                     (((uint32)(((uint32)(x))<<LPUART_STAT_RXINV_SHIFT))&LPUART_STAT_RXINV_MASK)
#define LPUART_STAT_MSBF_MASK                    0x20000000u
#define LPUART_STAT_MSBF_SHIFT                   29u
#define LPUART_STAT_MSBF_WIDTH                   1u
#define LPUART_STAT_MSBF(x)                      (((uint32)(((uint32)(x))<<LPUART_STAT_MSBF_SHIFT))&LPUART_STAT_MSBF_MASK)
#define LPUART_STAT_RXEDGIF_MASK                 0x40000000u
#define LPUART_STAT_RXEDGIF_SHIFT                30u
#define LPUART_STAT_RXEDGIF_WIDTH                1u
#define LPUART_STAT_RXEDGIF(x)                   (((uint32)(((uint32)(x))<<LPUART_STAT_RXEDGIF_SHIFT))&LPUART_STAT_RXEDGIF_MASK)
#define LPUART_STAT_LBKDIF_MASK                  0x80000000u
#define LPUART_STAT_LBKDIF_SHIFT                 31u
#define LPUART_STAT_LBKDIF_WIDTH                 1u
#define LPUART_STAT_LBKDIF(x)                    (((uint32)(((uint32)(x))<<LPUART_STAT_LBKDIF_SHIFT))&LPUART_STAT_LBKDIF_MASK)
/* CTRL Bit Fields */
#define LPUART_CTRL_PT_MASK                      0x1u
#define LPUART_CTRL_PT_SHIFT                     0u
#define LPUART_CTRL_PT_WIDTH                     1u
#define LPUART_CTRL_PT(x)                        (((uint32)(((uint32)(x))<<LPUART_CTRL_PT_SHIFT))&LPUART_CTRL_PT_MASK)
#define LPUART_CTRL_PE_MASK                      0x2u
#define LPUART_CTRL_PE_SHIFT                     1u
#define LPUART_CTRL_PE_WIDTH                     1u
#define LPUART_CTRL_PE(x)                        (((uint32)(((uint32)(x))<<LPUART_CTRL_PE_SHIFT))&LPUART_CTRL_PE_MASK)
#define LPUART_CTRL_ILT_MASK                     0x4u
#define LPUART_CTRL_ILT_SHIFT                    2u
#define LPUART_CTRL_ILT_WIDTH                    1u
#define LPUART_CTRL_ILT(x)                       (((uint32)(((uint32)(x))<<LPUART_CTRL_ILT_SHIFT))&LPUART_CTRL_ILT_MASK)
#define LPUART_CTRL_WAKE_MASK                    0x8u
#define LPUART_CTRL_WAKE_SHIFT                   3u
#define LPUART_CTRL_WAKE_WIDTH                   1u
#define LPUART_CTRL_WAKE(x)                      (((uint32)(((uint32)(x))<<LPUART_CTRL_WAKE_SHIFT))&LPUART_CTRL_WAKE_MASK)
#define LPUART_CTRL_M_MASK                       0x10u
#define LPUART_CTRL_M_SHIFT                      4u
#define LPUART_CTRL_M_WIDTH                      1u
#define LPUART_CTRL_M(x)                         (((uint32)(((uint32)(x))<<LPUART_CTRL_M_SHIFT))&LPUART_CTRL_M_MASK)
#define LPUART_CTRL_RSRC_MASK                    0x20u
#define LPUART_CTRL_RSRC_SHIFT                   5u
#define LPUART_CTRL_RSRC_WIDTH                   1u
#define LPUART_CTRL_RSRC(x)                      (((uint32)(((uint32)(x))<<LPUART_CTRL_RSRC_SHIFT))&LPUART_CTRL_RSRC_MASK)
#define LPUART_CTRL_DOZEEN_MASK                  0x40u
#define LPUART_CTRL_DOZEEN_SHIFT                 6u
#define LPUART_CTRL_DOZEEN_WIDTH                 1u
#define LPUART_CTRL_DOZEEN(x)                    (((uint32)(((uint32)(x))<<LPUART_CTRL_DOZEEN_SHIFT))&LPUART_CTRL_DOZEEN_MASK)
#define LPUART_CTRL_LOOPS_MASK                   0x80u
#define LPUART_CTRL_LOOPS_SHIFT                  7u
#define LPUART_CTRL_LOOPS_WIDTH                  1u
#define LPUART_CTRL_LOOPS(x)                     (((uint32)(((uint32)(x))<<LPUART_CTRL_LOOPS_SHIFT))&LPUART_CTRL_LOOPS_MASK)
#define LPUART_CTRL_IDLECFG_MASK                 0x700u
#define LPUART_CTRL_IDLECFG_SHIFT                8u
#define LPUART_CTRL_IDLECFG_WIDTH                3u
#define LPUART_CTRL_IDLECFG(x)                   (((uint32)(((uint32)(x))<<LPUART_CTRL_IDLECFG_SHIFT))&LPUART_CTRL_IDLECFG_MASK)
#define LPUART_CTRL_M7_MASK                      0x800u
#define LPUART_CTRL_M7_SHIFT                     11u
#define LPUART_CTRL_M7_WIDTH                     1u
#define LPUART_CTRL_M7(x)                        (((uint32)(((uint32)(x))<<LPUART_CTRL_M7_SHIFT))&LPUART_CTRL_M7_MASK)
#define LPUART_CTRL_MA2IE_MASK                   0x4000u
#define LPUART_CTRL_MA2IE_SHIFT                  14u
#define LPUART_CTRL_MA2IE_WIDTH                  1u
#define LPUART_CTRL_MA2IE(x)                     (((uint32)(((uint32)(x))<<LPUART_CTRL_MA2IE_SHIFT))&LPUART_CTRL_MA2IE_MASK)
#define LPUART_CTRL_MA1IE_MASK                   0x8000u
#define LPUART_CTRL_MA1IE_SHIFT                  15u
#define LPUART_CTRL_MA1IE_WIDTH                  1u
#define LPUART_CTRL_MA1IE(x)                     (((uint32)(((uint32)(x))<<LPUART_CTRL_MA1IE_SHIFT))&LPUART_CTRL_MA1IE_MASK)
#define LPUART_CTRL_SBK_MASK                     0x10000u
#define LPUART_CTRL_SBK_SHIFT                    16u
#define LPUART_CTRL_SBK_WIDTH                    1u
#define LPUART_CTRL_SBK(x)                       (((uint32)(((uint32)(x))<<LPUART_CTRL_SBK_SHIFT))&LPUART_CTRL_SBK_MASK)
#define LPUART_CTRL_RWU_MASK                     0x20000u
#define LPUART_CTRL_RWU_SHIFT                    17u
#define LPUART_CTRL_RWU_WIDTH                    1u
#define LPUART_CTRL_RWU(x)                       (((uint32)(((uint32)(x))<<LPUART_CTRL_RWU_SHIFT))&LPUART_CTRL_RWU_MASK)
#define LPUART_CTRL_RE_MASK                      0x40000u
#define LPUART_CTRL_RE_SHIFT                     18u
#define LPUART_CTRL_RE_WIDTH                     1u
#define LPUART_CTRL_RE(x)                        (((uint32)(((uint32)(x))<<LPUART_CTRL_RE_SHIFT))&LPUART_CTRL_RE_MASK)
#define LPUART_CTRL_TE_MASK                      0x80000u
#define LPUART_CTRL_TE_SHIFT                     19u
#define LPUART_CTRL_TE_WIDTH                     1u
#define LPUART_CTRL_TE(x)                        (((uint32)(((uint32)(x))<<LPUART_CTRL_TE_SHIFT))&LPUART_CTRL_TE_MASK)
#define LPUART_CTRL_ILIE_MASK                    0x100000u
#define LPUART_CTRL_ILIE_SHIFT                   20u
#define LPUART_CTRL_ILIE_WIDTH                   1u
#define LPUART_CTRL_ILIE(x)                      (((uint32)(((uint32)(x))<<LPUART_CTRL_ILIE_SHIFT))&LPUART_CTRL_ILIE_MASK)
#define LPUART_CTRL_RIE_MASK                     0x200000u
#define LPUART_CTRL_RIE_SHIFT                    21u
#define LPUART_CTRL_RIE_WIDTH                    1u
#define LPUART_CTRL_RIE(x)                       (((uint32)(((uint32)(x))<<LPUART_CTRL_RIE_SHIFT))&LPUART_CTRL_RIE_MASK)
#define LPUART_CTRL_TCIE_MASK                    0x400000u
#define LPUART_CTRL_TCIE_SHIFT                   22u
#define LPUART_CTRL_TCIE_WIDTH                   1u
#define LPUART_CTRL_TCIE(x)                      (((uint32)(((uint32)(x))<<LPUART_CTRL_TCIE_SHIFT))&LPUART_CTRL_TCIE_MASK)
#define LPUART_CTRL_TIE_MASK                     0x800000u
#define LPUART_CTRL_TIE_SHIFT                    23u
#define LPUART_CTRL_TIE_WIDTH                    1u
#define LPUART_CTRL_TIE(x)                       (((uint32)(((uint32)(x))<<LPUART_CTRL_TIE_SHIFT))&LPUART_CTRL_TIE_MASK)
#define LPUART_CTRL_PEIE_MASK                    0x1000000u
#define LPUART_CTRL_PEIE_SHIFT                   24u
#define LPUART_CTRL_PEIE_WIDTH                   1u
#define LPUART_CTRL_PEIE(x)                      (((uint32)(((uint32)(x))<<LPUART_CTRL_PEIE_SHIFT))&LPUART_CTRL_PEIE_MASK)
#define LPUART_CTRL_FEIE_MASK                    0x2000000u
#define LPUART_CTRL_FEIE_SHIFT                   25u
#define LPUART_CTRL_FEIE_WIDTH                   1u
#define LPUART_CTRL_FEIE(x)                      (((uint32)(((uint32)(x))<<LPUART_CTRL_FEIE_SHIFT))&LPUART_CTRL_FEIE_MASK)
#define LPUART_CTRL_NEIE_MASK                    0x4000000u
#define LPUART_CTRL_NEIE_SHIFT                   26u
#define LPUART_CTRL_NEIE_WIDTH                   1u
#define LPUART_CTRL_NEIE(x)                      (((uint32)(((uint32)(x))<<LPUART_CTRL_NEIE_SHIFT))&LPUART_CTRL_NEIE_MASK)
#define LPUART_CTRL_ORIE_MASK                    0x8000000u
#define LPUART_CTRL_ORIE_SHIFT                   27u
#define LPUART_CTRL_ORIE_WIDTH                   1u
#define LPUART_CTRL_ORIE(x)                      (((uint32)(((uint32)(x))<<LPUART_CTRL_ORIE_SHIFT))&LPUART_CTRL_ORIE_MASK)
#define LPUART_CTRL_TXINV_MASK                   0x10000000u
#define LPUART_CTRL_TXINV_SHIFT                  28u
#define LPUART_CTRL_TXINV_WIDTH                  1u
#define LPUART_CTRL_TXINV(x)                     (((uint32)(((uint32)(x))<<LPUART_CTRL_TXINV_SHIFT))&LPUART_CTRL_TXINV_MASK)
#define LPUART_CTRL_TXDIR_MASK                   0x20000000u
#define LPUART_CTRL_TXDIR_SHIFT                  29u
#define LPUART_CTRL_TXDIR_WIDTH                  1u
#define LPUART_CTRL_TXDIR(x)                     (((uint32)(((uint32)(x))<<LPUART_CTRL_TXDIR_SHIFT))&LPUART_CTRL_TXDIR_MASK)
#define LPUART_CTRL_R9T8_MASK                    0x40000000u
#define LPUART_CTRL_R9T8_SHIFT                   30u
#define LPUART_CTRL_R9T8_WIDTH                   1u
#define LPUART_CTRL_R9T8(x)                      (((uint32)(((uint32)(x))<<LPUART_CTRL_R9T8_SHIFT))&LPUART_CTRL_R9T8_MASK)
#define LPUART_CTRL_R8T9_MASK                    0x80000000u
#define LPUART_CTRL_R8T9_SHIFT                   31u
#define LPUART_CTRL_R8T9_WIDTH                   1u
#define LPUART_CTRL_R8T9(x)                      (((uint32)(((uint32)(x))<<LPUART_CTRL_R8T9_SHIFT))&LPUART_CTRL_R8T9_MASK)
/* DATA Bit Fields */
#define LPUART_DATA_R0T0_MASK                    0x1u
#define LPUART_DATA_R0T0_SHIFT                   0u
#define LPUART_DATA_R0T0_WIDTH                   1u
#define LPUART_DATA_R0T0(x)                      (((uint32)(((uint32)(x))<<LPUART_DATA_R0T0_SHIFT))&LPUART_DATA_R0T0_MASK)
#define LPUART_DATA_R1T1_MASK                    0x2u
#define LPUART_DATA_R1T1_SHIFT                   1u
#define LPUART_DATA_R1T1_WIDTH                   1u
#define LPUART_DATA_R1T1(x)                      (((uint32)(((uint32)(x))<<LPUART_DATA_R1T1_SHIFT))&LPUART_DATA_R1T1_MASK)
#define LPUART_DATA_R2T2_MASK                    0x4u
#define LPUART_DATA_R2T2_SHIFT                   2u
#define LPUART_DATA_R2T2_WIDTH                   1u
#define LPUART_DATA_R2T2(x)                      (((uint32)(((uint32)(x))<<LPUART_DATA_R2T2_SHIFT))&LPUART_DATA_R2T2_MASK)
#define LPUART_DATA_R3T3_MASK                    0x8u
#define LPUART_DATA_R3T3_SHIFT                   3u
#define LPUART_DATA_R3T3_WIDTH                   1u
#define LPUART_DATA_R3T3(x)                      (((uint32)(((uint32)(x))<<LPUART_DATA_R3T3_SHIFT))&LPUART_DATA_R3T3_MASK)
#define LPUART_DATA_R4T4_MASK                    0x10u
#define LPUART_DATA_R4T4_SHIFT                   4u
#define LPUART_DATA_R4T4_WIDTH                   1u
#define LPUART_DATA_R4T4(x)                      (((uint32)(((uint32)(x))<<LPUART_DATA_R4T4_SHIFT))&LPUART_DATA_R4T4_MASK)
#define LPUART_DATA_R5T5_MASK                    0x20u
#define LPUART_DATA_R5T5_SHIFT                   5u
#define LPUART_DATA_R5T5_WIDTH                   1u
#define LPUART_DATA_R5T5(x)                      (((uint32)(((uint32)(x))<<LPUART_DATA_R5T5_SHIFT))&LPUART_DATA_R5T5_MASK)
#define LPUART_DATA_R6T6_MASK                    0x40u
#define LPUART_DATA_R6T6_SHIFT                   6u
#define LPUART_DATA_R6T6_WIDTH                   1u
#define LPUART_DATA_R6T6(x)                      (((uint32)(((uint32)(x))<<LPUART_DATA_R6T6_SHIFT))&LPUART_DATA_R6T6_MASK)
#define LPUART_DATA_R7T7_MASK                    0x80u
#define LPUART_DATA_R7T7_SHIFT                   7u
#define LPUART_DATA_R7T7_WIDTH                   1u
#define LPUART_DATA_R7T7(x)                      (((uint32)(((uint32)(x))<<LPUART_DATA_R7T7_SHIFT))&LPUART_DATA_R7T7_MASK)
#define LPUART_DATA_R8T8_MASK                    0x100u
#define LPUART_DATA_R8T8_SHIFT                   8u
#define LPUART_DATA_R8T8_WIDTH                   1u
#define LPUART_DATA_R8T8(x)                      (((uint32)(((uint32)(x))<<LPUART_DATA_R8T8_SHIFT))&LPUART_DATA_R8T8_MASK)
#define LPUART_DATA_R9T9_MASK                    0x200u
#define LPUART_DATA_R9T9_SHIFT                   9u
#define LPUART_DATA_R9T9_WIDTH                   1u
#define LPUART_DATA_R9T9(x)                      (((uint32)(((uint32)(x))<<LPUART_DATA_R9T9_SHIFT))&LPUART_DATA_R9T9_MASK)
#define LPUART_DATA_IDLINE_MASK                  0x800u
#define LPUART_DATA_IDLINE_SHIFT                 11u
#define LPUART_DATA_IDLINE_WIDTH                 1u
#define LPUART_DATA_IDLINE(x)                    (((uint32)(((uint32)(x))<<LPUART_DATA_IDLINE_SHIFT))&LPUART_DATA_IDLINE_MASK)
#define LPUART_DATA_RXEMPT_MASK                  0x1000u
#define LPUART_DATA_RXEMPT_SHIFT                 12u
#define LPUART_DATA_RXEMPT_WIDTH                 1u
#define LPUART_DATA_RXEMPT(x)                    (((uint32)(((uint32)(x))<<LPUART_DATA_RXEMPT_SHIFT))&LPUART_DATA_RXEMPT_MASK)
#define LPUART_DATA_FRETSC_MASK                  0x2000u
#define LPUART_DATA_FRETSC_SHIFT                 13u
#define LPUART_DATA_FRETSC_WIDTH                 1u
#define LPUART_DATA_FRETSC(x)                    (((uint32)(((uint32)(x))<<LPUART_DATA_FRETSC_SHIFT))&LPUART_DATA_FRETSC_MASK)
#define LPUART_DATA_PARITYE_MASK                 0x4000u
#define LPUART_DATA_PARITYE_SHIFT                14u
#define LPUART_DATA_PARITYE_WIDTH                1u
#define LPUART_DATA_PARITYE(x)                   (((uint32)(((uint32)(x))<<LPUART_DATA_PARITYE_SHIFT))&LPUART_DATA_PARITYE_MASK)
#define LPUART_DATA_NOISY_MASK                   0x8000u
#define LPUART_DATA_NOISY_SHIFT                  15u
#define LPUART_DATA_NOISY_WIDTH                  1u
#define LPUART_DATA_NOISY(x)                     (((uint32)(((uint32)(x))<<LPUART_DATA_NOISY_SHIFT))&LPUART_DATA_NOISY_MASK)
/* MATCH Bit Fields */
#define LPUART_MATCH_MA1_MASK                    0x3FFu
#define LPUART_MATCH_MA1_SHIFT                   0u
#define LPUART_MATCH_MA1_WIDTH                   10u
#define LPUART_MATCH_MA1(x)                      (((uint32)(((uint32)(x))<<LPUART_MATCH_MA1_SHIFT))&LPUART_MATCH_MA1_MASK)
#define LPUART_MATCH_MA2_MASK                    0x3FF0000u
#define LPUART_MATCH_MA2_SHIFT                   16u
#define LPUART_MATCH_MA2_WIDTH                   10u
#define LPUART_MATCH_MA2(x)                      (((uint32)(((uint32)(x))<<LPUART_MATCH_MA2_SHIFT))&LPUART_MATCH_MA2_MASK)
/* MODIR Bit Fields */
#define LPUART_MODIR_TXCTSE_MASK                 0x1u
#define LPUART_MODIR_TXCTSE_SHIFT                0u
#define LPUART_MODIR_TXCTSE_WIDTH                1u
#define LPUART_MODIR_TXCTSE(x)                   (((uint32)(((uint32)(x))<<LPUART_MODIR_TXCTSE_SHIFT))&LPUART_MODIR_TXCTSE_MASK)
#define LPUART_MODIR_TXRTSE_MASK                 0x2u
#define LPUART_MODIR_TXRTSE_SHIFT                1u
#define LPUART_MODIR_TXRTSE_WIDTH                1u
#define LPUART_MODIR_TXRTSE(x)                   (((uint32)(((uint32)(x))<<LPUART_MODIR_TXRTSE_SHIFT))&LPUART_MODIR_TXRTSE_MASK)
#define LPUART_MODIR_TXRTSPOL_MASK               0x4u
#define LPUART_MODIR_TXRTSPOL_SHIFT              2u
#define LPUART_MODIR_TXRTSPOL_WIDTH              1u
#define LPUART_MODIR_TXRTSPOL(x)                 (((uint32)(((uint32)(x))<<LPUART_MODIR_TXRTSPOL_SHIFT))&LPUART_MODIR_TXRTSPOL_MASK)
#define LPUART_MODIR_RXRTSE_MASK                 0x8u
#define LPUART_MODIR_RXRTSE_SHIFT                3u
#define LPUART_MODIR_RXRTSE_WIDTH                1u
#define LPUART_MODIR_RXRTSE(x)                   (((uint32)(((uint32)(x))<<LPUART_MODIR_RXRTSE_SHIFT))&LPUART_MODIR_RXRTSE_MASK)
#define LPUART_MODIR_TXCTSC_MASK                 0x10u
#define LPUART_MODIR_TXCTSC_SHIFT                4u
#define LPUART_MODIR_TXCTSC_WIDTH                1u
#define LPUART_MODIR_TXCTSC(x)                   (((uint32)(((uint32)(x))<<LPUART_MODIR_TXCTSC_SHIFT))&LPUART_MODIR_TXCTSC_MASK)
#define LPUART_MODIR_TXCTSSRC_MASK               0x20u
#define LPUART_MODIR_TXCTSSRC_SHIFT              5u
#define LPUART_MODIR_TXCTSSRC_WIDTH              1u
#define LPUART_MODIR_TXCTSSRC(x)                 (((uint32)(((uint32)(x))<<LPUART_MODIR_TXCTSSRC_SHIFT))&LPUART_MODIR_TXCTSSRC_MASK)
#define LPUART_MODIR_RTSWATER_MASK               0x300u
#define LPUART_MODIR_RTSWATER_SHIFT              8u
#define LPUART_MODIR_RTSWATER_WIDTH              2u
#define LPUART_MODIR_RTSWATER(x)                 (((uint32)(((uint32)(x))<<LPUART_MODIR_RTSWATER_SHIFT))&LPUART_MODIR_RTSWATER_MASK)
#define LPUART_MODIR_TNP_MASK                    0x30000u
#define LPUART_MODIR_TNP_SHIFT                   16u
#define LPUART_MODIR_TNP_WIDTH                   2u
#define LPUART_MODIR_TNP(x)                      (((uint32)(((uint32)(x))<<LPUART_MODIR_TNP_SHIFT))&LPUART_MODIR_TNP_MASK)
#define LPUART_MODIR_IREN_MASK                   0x40000u
#define LPUART_MODIR_IREN_SHIFT                  18u
#define LPUART_MODIR_IREN_WIDTH                  1u
#define LPUART_MODIR_IREN(x)                     (((uint32)(((uint32)(x))<<LPUART_MODIR_IREN_SHIFT))&LPUART_MODIR_IREN_MASK)
/* FIFO Bit Fields */
#define LPUART_FIFO_RXFIFOSIZE_MASK              0x7u
#define LPUART_FIFO_RXFIFOSIZE_SHIFT             0u
#define LPUART_FIFO_RXFIFOSIZE_WIDTH             3u
#define LPUART_FIFO_RXFIFOSIZE(x)                (((uint32)(((uint32)(x))<<LPUART_FIFO_RXFIFOSIZE_SHIFT))&LPUART_FIFO_RXFIFOSIZE_MASK)
#define LPUART_FIFO_RXFE_MASK                    0x8u
#define LPUART_FIFO_RXFE_SHIFT                   3u
#define LPUART_FIFO_RXFE_WIDTH                   1u
#define LPUART_FIFO_RXFE(x)                      (((uint32)(((uint32)(x))<<LPUART_FIFO_RXFE_SHIFT))&LPUART_FIFO_RXFE_MASK)
#define LPUART_FIFO_TXFIFOSIZE_MASK              0x70u
#define LPUART_FIFO_TXFIFOSIZE_SHIFT             4u
#define LPUART_FIFO_TXFIFOSIZE_WIDTH             3u
#define LPUART_FIFO_TXFIFOSIZE(x)                (((uint32)(((uint32)(x))<<LPUART_FIFO_TXFIFOSIZE_SHIFT))&LPUART_FIFO_TXFIFOSIZE_MASK)
#define LPUART_FIFO_TXFE_MASK                    0x80u
#define LPUART_FIFO_TXFE_SHIFT                   7u
#define LPUART_FIFO_TXFE_WIDTH                   1u
#define LPUART_FIFO_TXFE(x)                      (((uint32)(((uint32)(x))<<LPUART_FIFO_TXFE_SHIFT))&LPUART_FIFO_TXFE_MASK)
#define LPUART_FIFO_RXUFE_MASK                   0x100u
#define LPUART_FIFO_RXUFE_SHIFT                  8u
#define LPUART_FIFO_RXUFE_WIDTH                  1u
#define LPUART_FIFO_RXUFE(x)                     (((uint32)(((uint32)(x))<<LPUART_FIFO_RXUFE_SHIFT))&LPUART_FIFO_RXUFE_MASK)
#define LPUART_FIFO_TXOFE_MASK                   0x200u
#define LPUART_FIFO_TXOFE_SHIFT                  9u
#define LPUART_FIFO_TXOFE_WIDTH                  1u
#define LPUART_FIFO_TXOFE(x)                     (((uint32)(((uint32)(x))<<LPUART_FIFO_TXOFE_SHIFT))&LPUART_FIFO_TXOFE_MASK)
#define LPUART_FIFO_RXIDEN_MASK                  0x1C00u
#define LPUART_FIFO_RXIDEN_SHIFT                 10u
#define LPUART_FIFO_RXIDEN_WIDTH                 3u
#define LPUART_FIFO_RXIDEN(x)                    (((uint32)(((uint32)(x))<<LPUART_FIFO_RXIDEN_SHIFT))&LPUART_FIFO_RXIDEN_MASK)
#define LPUART_FIFO_RXFLUSH_MASK                 0x4000u
#define LPUART_FIFO_RXFLUSH_SHIFT                14u
#define LPUART_FIFO_RXFLUSH_WIDTH                1u
#define LPUART_FIFO_RXFLUSH(x)                   (((uint32)(((uint32)(x))<<LPUART_FIFO_RXFLUSH_SHIFT))&LPUART_FIFO_RXFLUSH_MASK)
#define LPUART_FIFO_TXFLUSH_MASK                 0x8000u
#define LPUART_FIFO_TXFLUSH_SHIFT                15u
#define LPUART_FIFO_TXFLUSH_WIDTH                1u
#define LPUART_FIFO_TXFLUSH(x)                   (((uint32)(((uint32)(x))<<LPUART_FIFO_TXFLUSH_SHIFT))&LPUART_FIFO_TXFLUSH_MASK)
#define LPUART_FIFO_RXUF_MASK                    0x10000u
#define LPUART_FIFO_RXUF_SHIFT                   16u
#define LPUART_FIFO_RXUF_WIDTH                   1u
#define LPUART_FIFO_RXUF(x)                      (((uint32)(((uint32)(x))<<LPUART_FIFO_RXUF_SHIFT))&LPUART_FIFO_RXUF_MASK)
#define LPUART_FIFO_TXOF_MASK                    0x20000u
#define LPUART_FIFO_TXOF_SHIFT                   17u
#define LPUART_FIFO_TXOF_WIDTH                   1u
#define LPUART_FIFO_TXOF(x)                      (((uint32)(((uint32)(x))<<LPUART_FIFO_TXOF_SHIFT))&LPUART_FIFO_TXOF_MASK)
#define LPUART_FIFO_RXEMPT_MASK                  0x400000u
#define LPUART_FIFO_RXEMPT_SHIFT                 22u
#define LPUART_FIFO_RXEMPT_WIDTH                 1u
#define LPUART_FIFO_RXEMPT(x)                    (((uint32)(((uint32)(x))<<LPUART_FIFO_RXEMPT_SHIFT))&LPUART_FIFO_RXEMPT_MASK)
#define LPUART_FIFO_TXEMPT_MASK                  0x800000u
#define LPUART_FIFO_TXEMPT_SHIFT                 23u
#define LPUART_FIFO_TXEMPT_WIDTH                 1u
#define LPUART_FIFO_TXEMPT(x)                    (((uint32)(((uint32)(x))<<LPUART_FIFO_TXEMPT_SHIFT))&LPUART_FIFO_TXEMPT_MASK)
/* WATER Bit Fields */
#define LPUART_WATER_TXWATER_MASK                0x3u
#define LPUART_WATER_TXWATER_SHIFT               0u
#define LPUART_WATER_TXWATER_WIDTH               2u
#define LPUART_WATER_TXWATER(x)                  (((uint32)(((uint32)(x))<<LPUART_WATER_TXWATER_SHIFT))&LPUART_WATER_TXWATER_MASK)
#define LPUART_WATER_TXCOUNT_MASK                0x700u
#define LPUART_WATER_TXCOUNT_SHIFT               8u
#define LPUART_WATER_TXCOUNT_WIDTH               3u
#define LPUART_WATER_TXCOUNT(x)                  (((uint32)(((uint32)(x))<<LPUART_WATER_TXCOUNT_SHIFT))&LPUART_WATER_TXCOUNT_MASK)
#define LPUART_WATER_RXWATER_MASK                0x30000u
#define LPUART_WATER_RXWATER_SHIFT               16u
#define LPUART_WATER_RXWATER_WIDTH               2u
#define LPUART_WATER_RXWATER(x)                  (((uint32)(((uint32)(x))<<LPUART_WATER_RXWATER_SHIFT))&LPUART_WATER_RXWATER_MASK)
#define LPUART_WATER_RXCOUNT_MASK                0x7000000u
#define LPUART_WATER_RXCOUNT_SHIFT               24u
#define LPUART_WATER_RXCOUNT_WIDTH               3u
#define LPUART_WATER_RXCOUNT(x)                  (((uint32)(((uint32)(x))<<LPUART_WATER_RXCOUNT_SHIFT))&LPUART_WATER_RXCOUNT_MASK)

/*!
 * @}
 */ /* end of group LPUART_Register_Masks */


/*!
 * @}
 */ /* end of group LPUART_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Peripheral_Access_Layer MCM Peripheral Access Layer
 * @{
 */


/** MCM - Size of Registers Arrays */
#define MCM_LMDR_COUNT                           2u

/** MCM - Register Layout Typedef */
typedef struct {
       uint8 RESERVED_0[8];
  __I  uint16 PLASC;                             /**< Crossbar Switch (AXBS) Slave Configuration, offset: 0x8 */
  __I  uint16 PLAMC;                             /**< Crossbar Switch (AXBS) Master Configuration, offset: 0xA */
  __IO uint32 CPCR;                              /**< Core Platform Control Register, offset: 0xC */
  __IO uint32 ISCR;                              /**< Interrupt Status and Control Register, offset: 0x10 */
       uint8 RESERVED_1[28];
  __IO uint32 PID;                               /**< Process ID Register, offset: 0x30 */
       uint8 RESERVED_2[12];
  __IO uint32 CPO;                               /**< Compute Operation Control Register, offset: 0x40 */
       uint8 RESERVED_3[956];
  __IO uint32 LMDR[MCM_LMDR_COUNT];              /**< Local Memory Descriptor Register, array offset: 0x400, array step: 0x4 */
  __IO uint32 LMDR2;                             /**< Local Memory Descriptor Register2, offset: 0x408 */
       uint8 RESERVED_4[116];
  __IO uint32 LMPECR;                            /**< LMEM Parity and ECC Control Register, offset: 0x480 */
       uint8 RESERVED_5[4];
  __IO uint32 LMPEIR;                            /**< LMEM Parity and ECC Interrupt Register, offset: 0x488 */
       uint8 RESERVED_6[4];
  __I  uint32 LMFAR;                             /**< LMEM Fault Address Register, offset: 0x490 */
  __I  uint32 LMFATR;                            /**< LMEM Fault Attribute Register, offset: 0x494 */
       uint8 RESERVED_7[8];
  __I  uint32 LMFDHR;                            /**< LMEM Fault Data High Register, offset: 0x4A0 */
  __I  uint32 LMFDLR;                            /**< LMEM Fault Data Low Register, offset: 0x4A4 */
} MCM_Type, *MCM_MemMapPtr;

 /** Number of instances of the MCM module. */
#define MCM_INSTANCE_COUNT                       (1u)


/* MCM - Peripheral instance base addresses */
/** Peripheral MCM base address */
#define MCM_BASE                                 (0xE0080000u)
/** Peripheral MCM base pointer */
#define MCM                                      ((MCM_Type *)MCM_BASE)
/** Array initializer of MCM peripheral base addresses */
#define MCM_BASE_ADDRS                           { MCM_BASE }
/** Array initializer of MCM peripheral base pointers */
#define MCM_BASE_PTRS                            { MCM }
 /** Number of interrupt vector arrays for the MCM module. */
#define MCM_IRQS_ARR_COUNT                       (1u)
 /** Number of interrupt channels for the MCM module. */
#define MCM_IRQS_CH_COUNT                        (1u)
/** Interrupt vectors for the MCM peripheral type */
#define MCM_IRQS                                 { MCM_IRQn }

/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Masks MCM Register Masks
 * @{
 */

/* PLASC Bit Fields */
#define MCM_PLASC_ASC_MASK                       0xFFu
#define MCM_PLASC_ASC_SHIFT                      0u
#define MCM_PLASC_ASC_WIDTH                      8u
#define MCM_PLASC_ASC(x)                         (((uint16)(((uint16)(x))<<MCM_PLASC_ASC_SHIFT))&MCM_PLASC_ASC_MASK)
/* PLAMC Bit Fields */
#define MCM_PLAMC_AMC_MASK                       0xFFu
#define MCM_PLAMC_AMC_SHIFT                      0u
#define MCM_PLAMC_AMC_WIDTH                      8u
#define MCM_PLAMC_AMC(x)                         (((uint16)(((uint16)(x))<<MCM_PLAMC_AMC_SHIFT))&MCM_PLAMC_AMC_MASK)
/* CPCR Bit Fields */
#define MCM_CPCR_HLT_FSM_ST_MASK                 0x3u
#define MCM_CPCR_HLT_FSM_ST_SHIFT                0u
#define MCM_CPCR_HLT_FSM_ST_WIDTH                2u
#define MCM_CPCR_HLT_FSM_ST(x)                   (((uint32)(((uint32)(x))<<MCM_CPCR_HLT_FSM_ST_SHIFT))&MCM_CPCR_HLT_FSM_ST_MASK)
#define MCM_CPCR_AXBS_HLT_REQ_MASK               0x4u
#define MCM_CPCR_AXBS_HLT_REQ_SHIFT              2u
#define MCM_CPCR_AXBS_HLT_REQ_WIDTH              1u
#define MCM_CPCR_AXBS_HLT_REQ(x)                 (((uint32)(((uint32)(x))<<MCM_CPCR_AXBS_HLT_REQ_SHIFT))&MCM_CPCR_AXBS_HLT_REQ_MASK)
#define MCM_CPCR_AXBS_HLTD_MASK                  0x8u
#define MCM_CPCR_AXBS_HLTD_SHIFT                 3u
#define MCM_CPCR_AXBS_HLTD_WIDTH                 1u
#define MCM_CPCR_AXBS_HLTD(x)                    (((uint32)(((uint32)(x))<<MCM_CPCR_AXBS_HLTD_SHIFT))&MCM_CPCR_AXBS_HLTD_MASK)
#define MCM_CPCR_FMC_PF_IDLE_MASK                0x10u
#define MCM_CPCR_FMC_PF_IDLE_SHIFT               4u
#define MCM_CPCR_FMC_PF_IDLE_WIDTH               1u
#define MCM_CPCR_FMC_PF_IDLE(x)                  (((uint32)(((uint32)(x))<<MCM_CPCR_FMC_PF_IDLE_SHIFT))&MCM_CPCR_FMC_PF_IDLE_MASK)
#define MCM_CPCR_PBRIDGE_IDLE_MASK               0x40u
#define MCM_CPCR_PBRIDGE_IDLE_SHIFT              6u
#define MCM_CPCR_PBRIDGE_IDLE_WIDTH              1u
#define MCM_CPCR_PBRIDGE_IDLE(x)                 (((uint32)(((uint32)(x))<<MCM_CPCR_PBRIDGE_IDLE_SHIFT))&MCM_CPCR_PBRIDGE_IDLE_MASK)
#define MCM_CPCR_CBRR_MASK                       0x200u
#define MCM_CPCR_CBRR_SHIFT                      9u
#define MCM_CPCR_CBRR_WIDTH                      1u
#define MCM_CPCR_CBRR(x)                         (((uint32)(((uint32)(x))<<MCM_CPCR_CBRR_SHIFT))&MCM_CPCR_CBRR_MASK)
#define MCM_CPCR_SRAMUAP_MASK                    0x3000000u
#define MCM_CPCR_SRAMUAP_SHIFT                   24u
#define MCM_CPCR_SRAMUAP_WIDTH                   2u
#define MCM_CPCR_SRAMUAP(x)                      (((uint32)(((uint32)(x))<<MCM_CPCR_SRAMUAP_SHIFT))&MCM_CPCR_SRAMUAP_MASK)
#define MCM_CPCR_SRAMUWP_MASK                    0x4000000u
#define MCM_CPCR_SRAMUWP_SHIFT                   26u
#define MCM_CPCR_SRAMUWP_WIDTH                   1u
#define MCM_CPCR_SRAMUWP(x)                      (((uint32)(((uint32)(x))<<MCM_CPCR_SRAMUWP_SHIFT))&MCM_CPCR_SRAMUWP_MASK)
#define MCM_CPCR_SRAMLAP_MASK                    0x30000000u
#define MCM_CPCR_SRAMLAP_SHIFT                   28u
#define MCM_CPCR_SRAMLAP_WIDTH                   2u
#define MCM_CPCR_SRAMLAP(x)                      (((uint32)(((uint32)(x))<<MCM_CPCR_SRAMLAP_SHIFT))&MCM_CPCR_SRAMLAP_MASK)
#define MCM_CPCR_SRAMLWP_MASK                    0x40000000u
#define MCM_CPCR_SRAMLWP_SHIFT                   30u
#define MCM_CPCR_SRAMLWP_WIDTH                   1u
#define MCM_CPCR_SRAMLWP(x)                      (((uint32)(((uint32)(x))<<MCM_CPCR_SRAMLWP_SHIFT))&MCM_CPCR_SRAMLWP_MASK)
/* ISCR Bit Fields */
#define MCM_ISCR_FIOC_MASK                       0x100u
#define MCM_ISCR_FIOC_SHIFT                      8u
#define MCM_ISCR_FIOC_WIDTH                      1u
#define MCM_ISCR_FIOC(x)                         (((uint32)(((uint32)(x))<<MCM_ISCR_FIOC_SHIFT))&MCM_ISCR_FIOC_MASK)
#define MCM_ISCR_FDZC_MASK                       0x200u
#define MCM_ISCR_FDZC_SHIFT                      9u
#define MCM_ISCR_FDZC_WIDTH                      1u
#define MCM_ISCR_FDZC(x)                         (((uint32)(((uint32)(x))<<MCM_ISCR_FDZC_SHIFT))&MCM_ISCR_FDZC_MASK)
#define MCM_ISCR_FOFC_MASK                       0x400u
#define MCM_ISCR_FOFC_SHIFT                      10u
#define MCM_ISCR_FOFC_WIDTH                      1u
#define MCM_ISCR_FOFC(x)                         (((uint32)(((uint32)(x))<<MCM_ISCR_FOFC_SHIFT))&MCM_ISCR_FOFC_MASK)
#define MCM_ISCR_FUFC_MASK                       0x800u
#define MCM_ISCR_FUFC_SHIFT                      11u
#define MCM_ISCR_FUFC_WIDTH                      1u
#define MCM_ISCR_FUFC(x)                         (((uint32)(((uint32)(x))<<MCM_ISCR_FUFC_SHIFT))&MCM_ISCR_FUFC_MASK)
#define MCM_ISCR_FIXC_MASK                       0x1000u
#define MCM_ISCR_FIXC_SHIFT                      12u
#define MCM_ISCR_FIXC_WIDTH                      1u
#define MCM_ISCR_FIXC(x)                         (((uint32)(((uint32)(x))<<MCM_ISCR_FIXC_SHIFT))&MCM_ISCR_FIXC_MASK)
#define MCM_ISCR_FIDC_MASK                       0x8000u
#define MCM_ISCR_FIDC_SHIFT                      15u
#define MCM_ISCR_FIDC_WIDTH                      1u
#define MCM_ISCR_FIDC(x)                         (((uint32)(((uint32)(x))<<MCM_ISCR_FIDC_SHIFT))&MCM_ISCR_FIDC_MASK)
#define MCM_ISCR_FIOCE_MASK                      0x1000000u
#define MCM_ISCR_FIOCE_SHIFT                     24u
#define MCM_ISCR_FIOCE_WIDTH                     1u
#define MCM_ISCR_FIOCE(x)                        (((uint32)(((uint32)(x))<<MCM_ISCR_FIOCE_SHIFT))&MCM_ISCR_FIOCE_MASK)
#define MCM_ISCR_FDZCE_MASK                      0x2000000u
#define MCM_ISCR_FDZCE_SHIFT                     25u
#define MCM_ISCR_FDZCE_WIDTH                     1u
#define MCM_ISCR_FDZCE(x)                        (((uint32)(((uint32)(x))<<MCM_ISCR_FDZCE_SHIFT))&MCM_ISCR_FDZCE_MASK)
#define MCM_ISCR_FOFCE_MASK                      0x4000000u
#define MCM_ISCR_FOFCE_SHIFT                     26u
#define MCM_ISCR_FOFCE_WIDTH                     1u
#define MCM_ISCR_FOFCE(x)                        (((uint32)(((uint32)(x))<<MCM_ISCR_FOFCE_SHIFT))&MCM_ISCR_FOFCE_MASK)
#define MCM_ISCR_FUFCE_MASK                      0x8000000u
#define MCM_ISCR_FUFCE_SHIFT                     27u
#define MCM_ISCR_FUFCE_WIDTH                     1u
#define MCM_ISCR_FUFCE(x)                        (((uint32)(((uint32)(x))<<MCM_ISCR_FUFCE_SHIFT))&MCM_ISCR_FUFCE_MASK)
#define MCM_ISCR_FIXCE_MASK                      0x10000000u
#define MCM_ISCR_FIXCE_SHIFT                     28u
#define MCM_ISCR_FIXCE_WIDTH                     1u
#define MCM_ISCR_FIXCE(x)                        (((uint32)(((uint32)(x))<<MCM_ISCR_FIXCE_SHIFT))&MCM_ISCR_FIXCE_MASK)
#define MCM_ISCR_FIDCE_MASK                      0x80000000u
#define MCM_ISCR_FIDCE_SHIFT                     31u
#define MCM_ISCR_FIDCE_WIDTH                     1u
#define MCM_ISCR_FIDCE(x)                        (((uint32)(((uint32)(x))<<MCM_ISCR_FIDCE_SHIFT))&MCM_ISCR_FIDCE_MASK)
/* PID Bit Fields */
#define MCM_PID_PID_MASK                         0xFFu
#define MCM_PID_PID_SHIFT                        0u
#define MCM_PID_PID_WIDTH                        8u
#define MCM_PID_PID(x)                           (((uint32)(((uint32)(x))<<MCM_PID_PID_SHIFT))&MCM_PID_PID_MASK)
/* CPO Bit Fields */
#define MCM_CPO_CPOREQ_MASK                      0x1u
#define MCM_CPO_CPOREQ_SHIFT                     0u
#define MCM_CPO_CPOREQ_WIDTH                     1u
#define MCM_CPO_CPOREQ(x)                        (((uint32)(((uint32)(x))<<MCM_CPO_CPOREQ_SHIFT))&MCM_CPO_CPOREQ_MASK)
#define MCM_CPO_CPOACK_MASK                      0x2u
#define MCM_CPO_CPOACK_SHIFT                     1u
#define MCM_CPO_CPOACK_WIDTH                     1u
#define MCM_CPO_CPOACK(x)                        (((uint32)(((uint32)(x))<<MCM_CPO_CPOACK_SHIFT))&MCM_CPO_CPOACK_MASK)
#define MCM_CPO_CPOWOI_MASK                      0x4u
#define MCM_CPO_CPOWOI_SHIFT                     2u
#define MCM_CPO_CPOWOI_WIDTH                     1u
#define MCM_CPO_CPOWOI(x)                        (((uint32)(((uint32)(x))<<MCM_CPO_CPOWOI_SHIFT))&MCM_CPO_CPOWOI_MASK)
/* LMDR Bit Fields */
#define MCM_LMDR_CF0_MASK                        0xFu
#define MCM_LMDR_CF0_SHIFT                       0u
#define MCM_LMDR_CF0_WIDTH                       4u
#define MCM_LMDR_CF0(x)                          (((uint32)(((uint32)(x))<<MCM_LMDR_CF0_SHIFT))&MCM_LMDR_CF0_MASK)
#define MCM_LMDR_CF1_MASK                        0xF0u
#define MCM_LMDR_CF1_SHIFT                       4u
#define MCM_LMDR_CF1_WIDTH                       4u
#define MCM_LMDR_CF1(x)                          (((uint32)(((uint32)(x))<<MCM_LMDR_CF1_SHIFT))&MCM_LMDR_CF1_MASK)
#define MCM_LMDR_MT_MASK                         0xE000u
#define MCM_LMDR_MT_SHIFT                        13u
#define MCM_LMDR_MT_WIDTH                        3u
#define MCM_LMDR_MT(x)                           (((uint32)(((uint32)(x))<<MCM_LMDR_MT_SHIFT))&MCM_LMDR_MT_MASK)
#define MCM_LMDR_LOCK_MASK                       0x10000u
#define MCM_LMDR_LOCK_SHIFT                      16u
#define MCM_LMDR_LOCK_WIDTH                      1u
#define MCM_LMDR_LOCK(x)                         (((uint32)(((uint32)(x))<<MCM_LMDR_LOCK_SHIFT))&MCM_LMDR_LOCK_MASK)
#define MCM_LMDR_DPW_MASK                        0xE0000u
#define MCM_LMDR_DPW_SHIFT                       17u
#define MCM_LMDR_DPW_WIDTH                       3u
#define MCM_LMDR_DPW(x)                          (((uint32)(((uint32)(x))<<MCM_LMDR_DPW_SHIFT))&MCM_LMDR_DPW_MASK)
#define MCM_LMDR_WY_MASK                         0xF00000u
#define MCM_LMDR_WY_SHIFT                        20u
#define MCM_LMDR_WY_WIDTH                        4u
#define MCM_LMDR_WY(x)                           (((uint32)(((uint32)(x))<<MCM_LMDR_WY_SHIFT))&MCM_LMDR_WY_MASK)
#define MCM_LMDR_LMSZ_MASK                       0xF000000u
#define MCM_LMDR_LMSZ_SHIFT                      24u
#define MCM_LMDR_LMSZ_WIDTH                      4u
#define MCM_LMDR_LMSZ(x)                         (((uint32)(((uint32)(x))<<MCM_LMDR_LMSZ_SHIFT))&MCM_LMDR_LMSZ_MASK)
#define MCM_LMDR_LMSZH_MASK                      0x10000000u
#define MCM_LMDR_LMSZH_SHIFT                     28u
#define MCM_LMDR_LMSZH_WIDTH                     1u
#define MCM_LMDR_LMSZH(x)                        (((uint32)(((uint32)(x))<<MCM_LMDR_LMSZH_SHIFT))&MCM_LMDR_LMSZH_MASK)
#define MCM_LMDR_V_MASK                          0x80000000u
#define MCM_LMDR_V_SHIFT                         31u
#define MCM_LMDR_V_WIDTH                         1u
#define MCM_LMDR_V(x)                            (((uint32)(((uint32)(x))<<MCM_LMDR_V_SHIFT))&MCM_LMDR_V_MASK)
/* LMDR2 Bit Fields */
#define MCM_LMDR2_CF1_MASK                       0xF0u
#define MCM_LMDR2_CF1_SHIFT                      4u
#define MCM_LMDR2_CF1_WIDTH                      4u
#define MCM_LMDR2_CF1(x)                         (((uint32)(((uint32)(x))<<MCM_LMDR2_CF1_SHIFT))&MCM_LMDR2_CF1_MASK)
#define MCM_LMDR2_MT_MASK                        0xE000u
#define MCM_LMDR2_MT_SHIFT                       13u
#define MCM_LMDR2_MT_WIDTH                       3u
#define MCM_LMDR2_MT(x)                          (((uint32)(((uint32)(x))<<MCM_LMDR2_MT_SHIFT))&MCM_LMDR2_MT_MASK)
#define MCM_LMDR2_LOCK_MASK                      0x10000u
#define MCM_LMDR2_LOCK_SHIFT                     16u
#define MCM_LMDR2_LOCK_WIDTH                     1u
#define MCM_LMDR2_LOCK(x)                        (((uint32)(((uint32)(x))<<MCM_LMDR2_LOCK_SHIFT))&MCM_LMDR2_LOCK_MASK)
#define MCM_LMDR2_DPW_MASK                       0xE0000u
#define MCM_LMDR2_DPW_SHIFT                      17u
#define MCM_LMDR2_DPW_WIDTH                      3u
#define MCM_LMDR2_DPW(x)                         (((uint32)(((uint32)(x))<<MCM_LMDR2_DPW_SHIFT))&MCM_LMDR2_DPW_MASK)
#define MCM_LMDR2_WY_MASK                        0xF00000u
#define MCM_LMDR2_WY_SHIFT                       20u
#define MCM_LMDR2_WY_WIDTH                       4u
#define MCM_LMDR2_WY(x)                          (((uint32)(((uint32)(x))<<MCM_LMDR2_WY_SHIFT))&MCM_LMDR2_WY_MASK)
#define MCM_LMDR2_LMSZ_MASK                      0xF000000u
#define MCM_LMDR2_LMSZ_SHIFT                     24u
#define MCM_LMDR2_LMSZ_WIDTH                     4u
#define MCM_LMDR2_LMSZ(x)                        (((uint32)(((uint32)(x))<<MCM_LMDR2_LMSZ_SHIFT))&MCM_LMDR2_LMSZ_MASK)
#define MCM_LMDR2_LMSZH_MASK                     0x10000000u
#define MCM_LMDR2_LMSZH_SHIFT                    28u
#define MCM_LMDR2_LMSZH_WIDTH                    1u
#define MCM_LMDR2_LMSZH(x)                       (((uint32)(((uint32)(x))<<MCM_LMDR2_LMSZH_SHIFT))&MCM_LMDR2_LMSZH_MASK)
#define MCM_LMDR2_V_MASK                         0x80000000u
#define MCM_LMDR2_V_SHIFT                        31u
#define MCM_LMDR2_V_WIDTH                        1u
#define MCM_LMDR2_V(x)                           (((uint32)(((uint32)(x))<<MCM_LMDR2_V_SHIFT))&MCM_LMDR2_V_MASK)
/* LMPECR Bit Fields */
#define MCM_LMPECR_ERNCR_MASK                    0x1u
#define MCM_LMPECR_ERNCR_SHIFT                   0u
#define MCM_LMPECR_ERNCR_WIDTH                   1u
#define MCM_LMPECR_ERNCR(x)                      (((uint32)(((uint32)(x))<<MCM_LMPECR_ERNCR_SHIFT))&MCM_LMPECR_ERNCR_MASK)
#define MCM_LMPECR_ER1BR_MASK                    0x100u
#define MCM_LMPECR_ER1BR_SHIFT                   8u
#define MCM_LMPECR_ER1BR_WIDTH                   1u
#define MCM_LMPECR_ER1BR(x)                      (((uint32)(((uint32)(x))<<MCM_LMPECR_ER1BR_SHIFT))&MCM_LMPECR_ER1BR_MASK)
#define MCM_LMPECR_ECPR_MASK                     0x100000u
#define MCM_LMPECR_ECPR_SHIFT                    20u
#define MCM_LMPECR_ECPR_WIDTH                    1u
#define MCM_LMPECR_ECPR(x)                       (((uint32)(((uint32)(x))<<MCM_LMPECR_ECPR_SHIFT))&MCM_LMPECR_ECPR_MASK)
/* LMPEIR Bit Fields */
#define MCM_LMPEIR_ENC_MASK                      0xFFu
#define MCM_LMPEIR_ENC_SHIFT                     0u
#define MCM_LMPEIR_ENC_WIDTH                     8u
#define MCM_LMPEIR_ENC(x)                        (((uint32)(((uint32)(x))<<MCM_LMPEIR_ENC_SHIFT))&MCM_LMPEIR_ENC_MASK)
#define MCM_LMPEIR_E1B_MASK                      0xFF00u
#define MCM_LMPEIR_E1B_SHIFT                     8u
#define MCM_LMPEIR_E1B_WIDTH                     8u
#define MCM_LMPEIR_E1B(x)                        (((uint32)(((uint32)(x))<<MCM_LMPEIR_E1B_SHIFT))&MCM_LMPEIR_E1B_MASK)
#define MCM_LMPEIR_PE_MASK                       0xFF0000u
#define MCM_LMPEIR_PE_SHIFT                      16u
#define MCM_LMPEIR_PE_WIDTH                      8u
#define MCM_LMPEIR_PE(x)                         (((uint32)(((uint32)(x))<<MCM_LMPEIR_PE_SHIFT))&MCM_LMPEIR_PE_MASK)
#define MCM_LMPEIR_PEELOC_MASK                   0x1F000000u
#define MCM_LMPEIR_PEELOC_SHIFT                  24u
#define MCM_LMPEIR_PEELOC_WIDTH                  5u
#define MCM_LMPEIR_PEELOC(x)                     (((uint32)(((uint32)(x))<<MCM_LMPEIR_PEELOC_SHIFT))&MCM_LMPEIR_PEELOC_MASK)
#define MCM_LMPEIR_V_MASK                        0x80000000u
#define MCM_LMPEIR_V_SHIFT                       31u
#define MCM_LMPEIR_V_WIDTH                       1u
#define MCM_LMPEIR_V(x)                          (((uint32)(((uint32)(x))<<MCM_LMPEIR_V_SHIFT))&MCM_LMPEIR_V_MASK)
/* LMFAR Bit Fields */
#define MCM_LMFAR_EFADD_MASK                     0xFFFFFFFFu
#define MCM_LMFAR_EFADD_SHIFT                    0u
#define MCM_LMFAR_EFADD_WIDTH                    32u
#define MCM_LMFAR_EFADD(x)                       (((uint32)(((uint32)(x))<<MCM_LMFAR_EFADD_SHIFT))&MCM_LMFAR_EFADD_MASK)
/* LMFATR Bit Fields */
#define MCM_LMFATR_PEFPRT_MASK                   0xFu
#define MCM_LMFATR_PEFPRT_SHIFT                  0u
#define MCM_LMFATR_PEFPRT_WIDTH                  4u
#define MCM_LMFATR_PEFPRT(x)                     (((uint32)(((uint32)(x))<<MCM_LMFATR_PEFPRT_SHIFT))&MCM_LMFATR_PEFPRT_MASK)
#define MCM_LMFATR_PEFSIZE_MASK                  0x70u
#define MCM_LMFATR_PEFSIZE_SHIFT                 4u
#define MCM_LMFATR_PEFSIZE_WIDTH                 3u
#define MCM_LMFATR_PEFSIZE(x)                    (((uint32)(((uint32)(x))<<MCM_LMFATR_PEFSIZE_SHIFT))&MCM_LMFATR_PEFSIZE_MASK)
#define MCM_LMFATR_PEFW_MASK                     0x80u
#define MCM_LMFATR_PEFW_SHIFT                    7u
#define MCM_LMFATR_PEFW_WIDTH                    1u
#define MCM_LMFATR_PEFW(x)                       (((uint32)(((uint32)(x))<<MCM_LMFATR_PEFW_SHIFT))&MCM_LMFATR_PEFW_MASK)
#define MCM_LMFATR_PEFMST_MASK                   0xFF00u
#define MCM_LMFATR_PEFMST_SHIFT                  8u
#define MCM_LMFATR_PEFMST_WIDTH                  8u
#define MCM_LMFATR_PEFMST(x)                     (((uint32)(((uint32)(x))<<MCM_LMFATR_PEFMST_SHIFT))&MCM_LMFATR_PEFMST_MASK)
#define MCM_LMFATR_OVR_MASK                      0x80000000u
#define MCM_LMFATR_OVR_SHIFT                     31u
#define MCM_LMFATR_OVR_WIDTH                     1u
#define MCM_LMFATR_OVR(x)                        (((uint32)(((uint32)(x))<<MCM_LMFATR_OVR_SHIFT))&MCM_LMFATR_OVR_MASK)
/* LMFDHR Bit Fields */
#define MCM_LMFDHR_PEFDH_MASK                    0xFFFFFFFFu
#define MCM_LMFDHR_PEFDH_SHIFT                   0u
#define MCM_LMFDHR_PEFDH_WIDTH                   32u
#define MCM_LMFDHR_PEFDH(x)                      (((uint32)(((uint32)(x))<<MCM_LMFDHR_PEFDH_SHIFT))&MCM_LMFDHR_PEFDH_MASK)
/* LMFDLR Bit Fields */
#define MCM_LMFDLR_PEFDL_MASK                    0xFFFFFFFFu
#define MCM_LMFDLR_PEFDL_SHIFT                   0u
#define MCM_LMFDLR_PEFDL_WIDTH                   32u
#define MCM_LMFDLR_PEFDL(x)                      (((uint32)(((uint32)(x))<<MCM_LMFDLR_PEFDL_SHIFT))&MCM_LMFDLR_PEFDL_MASK)

/*!
 * @}
 */ /* end of group MCM_Register_Masks */


/*!
 * @}
 */ /* end of group MCM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MPU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MPU_Peripheral_Access_Layer MPU Peripheral Access Layer
 * @{
 */


/** MPU - Size of Registers Arrays */
#define MPU_EAR_EDR_COUNT                        4u
#define MPU_RGD_COUNT                            8u
#define MPU_RGDAAC_COUNT                         8u

/** MPU - Register Layout Typedef */
typedef struct {
  __IO uint32 CESR;                              /**< Control/Error Status Register, offset: 0x0 */
       uint8 RESERVED_0[12];
  struct {                                         /* offset: 0x10, array step: 0x8 */
    __I  uint32 EAR;                               /**< Error Address Register, slave port
                  0..Error Address Register, slave port
                  3, array offset: 0x10, array step: 0x8 */
    __I  uint32 EDR;                               /**< Error Detail Register, slave port
                  0..Error Detail Register, slave port
                  3, array offset: 0x14, array step: 0x8 */
  } EAR_EDR[MPU_EAR_EDR_COUNT];
       uint8 RESERVED_1[976];
  struct {                                         /* offset: 0x400, array step: 0x10 */
    __IO uint32 WORD0;                             /**< Region Descriptor 0, Word 0..Region Descriptor 7, Word 0, array offset: 0x400, array step: 0x10 */
    __IO uint32 WORD1;                             /**< Region Descriptor 0, Word 1..Region Descriptor 7, Word 1, array offset: 0x404, array step: 0x10 */
    __IO uint32 WORD2;                             /**< Region Descriptor 0, Word 2..Region Descriptor 7, Word 2, array offset: 0x408, array step: 0x10 */
    __IO uint32 WORD3;                             /**< Region Descriptor 0, Word 3..Region Descriptor 7, Word 3, array offset: 0x40C, array step: 0x10 */
  } RGD[MPU_RGD_COUNT];
       uint8 RESERVED_2[896];
  __IO uint32 RGDAAC[MPU_RGDAAC_COUNT];          /**< Region Descriptor Alternate Access Control
                0..Region Descriptor Alternate Access Control
                7, array offset: 0x800, array step: 0x4 */
} MPU_Type, *MPU_MemMapPtr;

 /** Number of instances of the MPU module. */
#define MPU_INSTANCE_COUNT                       (1u)


/* MPU - Peripheral instance base addresses */
/** Peripheral MPU base address */
#define MPU_BASE                                 (0x4000D000u)
/** Peripheral MPU base pointer */
#define MPU                                      ((MPU_Type *)MPU_BASE)
/** Array initializer of MPU peripheral base addresses */
#define MPU_BASE_ADDRS                           { MPU_BASE }
/** Array initializer of MPU peripheral base pointers */
#define MPU_BASE_PTRS                            { MPU }

/* ----------------------------------------------------------------------------
   -- MPU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MPU_Register_Masks MPU Register Masks
 * @{
 */

/* CESR Bit Fields */
#define MPU_CESR_VLD_MASK                        0x1u
#define MPU_CESR_VLD_SHIFT                       0u
#define MPU_CESR_VLD_WIDTH                       1u
#define MPU_CESR_VLD(x)                          (((uint32)(((uint32)(x))<<MPU_CESR_VLD_SHIFT))&MPU_CESR_VLD_MASK)
#define MPU_CESR_NRGD_MASK                       0xF00u
#define MPU_CESR_NRGD_SHIFT                      8u
#define MPU_CESR_NRGD_WIDTH                      4u
#define MPU_CESR_NRGD(x)                         (((uint32)(((uint32)(x))<<MPU_CESR_NRGD_SHIFT))&MPU_CESR_NRGD_MASK)
#define MPU_CESR_NSP_MASK                        0xF000u
#define MPU_CESR_NSP_SHIFT                       12u
#define MPU_CESR_NSP_WIDTH                       4u
#define MPU_CESR_NSP(x)                          (((uint32)(((uint32)(x))<<MPU_CESR_NSP_SHIFT))&MPU_CESR_NSP_MASK)
#define MPU_CESR_HRL_MASK                        0xF0000u
#define MPU_CESR_HRL_SHIFT                       16u
#define MPU_CESR_HRL_WIDTH                       4u
#define MPU_CESR_HRL(x)                          (((uint32)(((uint32)(x))<<MPU_CESR_HRL_SHIFT))&MPU_CESR_HRL_MASK)
#define MPU_CESR_SPERR3_MASK                     0x10000000u
#define MPU_CESR_SPERR3_SHIFT                    28u
#define MPU_CESR_SPERR3_WIDTH                    1u
#define MPU_CESR_SPERR3(x)                       (((uint32)(((uint32)(x))<<MPU_CESR_SPERR3_SHIFT))&MPU_CESR_SPERR3_MASK)
#define MPU_CESR_SPERR2_MASK                     0x20000000u
#define MPU_CESR_SPERR2_SHIFT                    29u
#define MPU_CESR_SPERR2_WIDTH                    1u
#define MPU_CESR_SPERR2(x)                       (((uint32)(((uint32)(x))<<MPU_CESR_SPERR2_SHIFT))&MPU_CESR_SPERR2_MASK)
#define MPU_CESR_SPERR1_MASK                     0x40000000u
#define MPU_CESR_SPERR1_SHIFT                    30u
#define MPU_CESR_SPERR1_WIDTH                    1u
#define MPU_CESR_SPERR1(x)                       (((uint32)(((uint32)(x))<<MPU_CESR_SPERR1_SHIFT))&MPU_CESR_SPERR1_MASK)
#define MPU_CESR_SPERR0_MASK                     0x80000000u
#define MPU_CESR_SPERR0_SHIFT                    31u
#define MPU_CESR_SPERR0_WIDTH                    1u
#define MPU_CESR_SPERR0(x)                       (((uint32)(((uint32)(x))<<MPU_CESR_SPERR0_SHIFT))&MPU_CESR_SPERR0_MASK)
/* EAR Bit Fields */
#define MPU_EAR_EADDR_MASK                       0xFFFFFFFFu
#define MPU_EAR_EADDR_SHIFT                      0u
#define MPU_EAR_EADDR_WIDTH                      32u
#define MPU_EAR_EADDR(x)                         (((uint32)(((uint32)(x))<<MPU_EAR_EADDR_SHIFT))&MPU_EAR_EADDR_MASK)
/* EDR Bit Fields */
#define MPU_EDR_ERW_MASK                         0x1u
#define MPU_EDR_ERW_SHIFT                        0u
#define MPU_EDR_ERW_WIDTH                        1u
#define MPU_EDR_ERW(x)                           (((uint32)(((uint32)(x))<<MPU_EDR_ERW_SHIFT))&MPU_EDR_ERW_MASK)
#define MPU_EDR_EATTR_MASK                       0xEu
#define MPU_EDR_EATTR_SHIFT                      1u
#define MPU_EDR_EATTR_WIDTH                      3u
#define MPU_EDR_EATTR(x)                         (((uint32)(((uint32)(x))<<MPU_EDR_EATTR_SHIFT))&MPU_EDR_EATTR_MASK)
#define MPU_EDR_EMN_MASK                         0xF0u
#define MPU_EDR_EMN_SHIFT                        4u
#define MPU_EDR_EMN_WIDTH                        4u
#define MPU_EDR_EMN(x)                           (((uint32)(((uint32)(x))<<MPU_EDR_EMN_SHIFT))&MPU_EDR_EMN_MASK)
#define MPU_EDR_EPID_MASK                        0xFF00u
#define MPU_EDR_EPID_SHIFT                       8u
#define MPU_EDR_EPID_WIDTH                       8u
#define MPU_EDR_EPID(x)                          (((uint32)(((uint32)(x))<<MPU_EDR_EPID_SHIFT))&MPU_EDR_EPID_MASK)
#define MPU_EDR_EACD_MASK                        0xFFFF0000u
#define MPU_EDR_EACD_SHIFT                       16u
#define MPU_EDR_EACD_WIDTH                       16u
#define MPU_EDR_EACD(x)                          (((uint32)(((uint32)(x))<<MPU_EDR_EACD_SHIFT))&MPU_EDR_EACD_MASK)
/* RGD_WORD0 Bit Fields */
#define MPU_RGD_WORD0_SRTADDR_MASK               0xFFFFFFE0u
#define MPU_RGD_WORD0_SRTADDR_SHIFT              5u
#define MPU_RGD_WORD0_SRTADDR_WIDTH              27u
#define MPU_RGD_WORD0_SRTADDR(x)                 (((uint32)(((uint32)(x))<<MPU_RGD_WORD0_SRTADDR_SHIFT))&MPU_RGD_WORD0_SRTADDR_MASK)
/* RGD_WORD1 Bit Fields */
#define MPU_RGD_WORD1_ENDADDR_MASK               0xFFFFFFE0u
#define MPU_RGD_WORD1_ENDADDR_SHIFT              5u
#define MPU_RGD_WORD1_ENDADDR_WIDTH              27u
#define MPU_RGD_WORD1_ENDADDR(x)                 (((uint32)(((uint32)(x))<<MPU_RGD_WORD1_ENDADDR_SHIFT))&MPU_RGD_WORD1_ENDADDR_MASK)
/* RGD_WORD2 Bit Fields */
#define MPU_RGD_WORD2_M0UM_MASK                  0x7u
#define MPU_RGD_WORD2_M0UM_SHIFT                 0u
#define MPU_RGD_WORD2_M0UM_WIDTH                 3u
#define MPU_RGD_WORD2_M0UM(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M0UM_SHIFT))&MPU_RGD_WORD2_M0UM_MASK)
#define MPU_RGD_WORD2_M0SM_MASK                  0x18u
#define MPU_RGD_WORD2_M0SM_SHIFT                 3u
#define MPU_RGD_WORD2_M0SM_WIDTH                 2u
#define MPU_RGD_WORD2_M0SM(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M0SM_SHIFT))&MPU_RGD_WORD2_M0SM_MASK)
#define MPU_RGD_WORD2_M0PE_MASK                  0x20u
#define MPU_RGD_WORD2_M0PE_SHIFT                 5u
#define MPU_RGD_WORD2_M0PE_WIDTH                 1u
#define MPU_RGD_WORD2_M0PE(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M0PE_SHIFT))&MPU_RGD_WORD2_M0PE_MASK)
#define MPU_RGD_WORD2_M1UM_MASK                  0x1C0u
#define MPU_RGD_WORD2_M1UM_SHIFT                 6u
#define MPU_RGD_WORD2_M1UM_WIDTH                 3u
#define MPU_RGD_WORD2_M1UM(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M1UM_SHIFT))&MPU_RGD_WORD2_M1UM_MASK)
#define MPU_RGD_WORD2_M1SM_MASK                  0x600u
#define MPU_RGD_WORD2_M1SM_SHIFT                 9u
#define MPU_RGD_WORD2_M1SM_WIDTH                 2u
#define MPU_RGD_WORD2_M1SM(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M1SM_SHIFT))&MPU_RGD_WORD2_M1SM_MASK)
#define MPU_RGD_WORD2_M1PE_MASK                  0x800u
#define MPU_RGD_WORD2_M1PE_SHIFT                 11u
#define MPU_RGD_WORD2_M1PE_WIDTH                 1u
#define MPU_RGD_WORD2_M1PE(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M1PE_SHIFT))&MPU_RGD_WORD2_M1PE_MASK)
#define MPU_RGD_WORD2_M2UM_MASK                  0x7000u
#define MPU_RGD_WORD2_M2UM_SHIFT                 12u
#define MPU_RGD_WORD2_M2UM_WIDTH                 3u
#define MPU_RGD_WORD2_M2UM(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M2UM_SHIFT))&MPU_RGD_WORD2_M2UM_MASK)
#define MPU_RGD_WORD2_M2SM_MASK                  0x18000u
#define MPU_RGD_WORD2_M2SM_SHIFT                 15u
#define MPU_RGD_WORD2_M2SM_WIDTH                 2u
#define MPU_RGD_WORD2_M2SM(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M2SM_SHIFT))&MPU_RGD_WORD2_M2SM_MASK)
#define MPU_RGD_WORD2_M3UM_MASK                  0x1C0000u
#define MPU_RGD_WORD2_M3UM_SHIFT                 18u
#define MPU_RGD_WORD2_M3UM_WIDTH                 3u
#define MPU_RGD_WORD2_M3UM(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M3UM_SHIFT))&MPU_RGD_WORD2_M3UM_MASK)
#define MPU_RGD_WORD2_M3SM_MASK                  0x600000u
#define MPU_RGD_WORD2_M3SM_SHIFT                 21u
#define MPU_RGD_WORD2_M3SM_WIDTH                 2u
#define MPU_RGD_WORD2_M3SM(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M3SM_SHIFT))&MPU_RGD_WORD2_M3SM_MASK)
#define MPU_RGD_WORD2_M4WE_MASK                  0x1000000u
#define MPU_RGD_WORD2_M4WE_SHIFT                 24u
#define MPU_RGD_WORD2_M4WE_WIDTH                 1u
#define MPU_RGD_WORD2_M4WE(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M4WE_SHIFT))&MPU_RGD_WORD2_M4WE_MASK)
#define MPU_RGD_WORD2_M4RE_MASK                  0x2000000u
#define MPU_RGD_WORD2_M4RE_SHIFT                 25u
#define MPU_RGD_WORD2_M4RE_WIDTH                 1u
#define MPU_RGD_WORD2_M4RE(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M4RE_SHIFT))&MPU_RGD_WORD2_M4RE_MASK)
#define MPU_RGD_WORD2_M5WE_MASK                  0x4000000u
#define MPU_RGD_WORD2_M5WE_SHIFT                 26u
#define MPU_RGD_WORD2_M5WE_WIDTH                 1u
#define MPU_RGD_WORD2_M5WE(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M5WE_SHIFT))&MPU_RGD_WORD2_M5WE_MASK)
#define MPU_RGD_WORD2_M5RE_MASK                  0x8000000u
#define MPU_RGD_WORD2_M5RE_SHIFT                 27u
#define MPU_RGD_WORD2_M5RE_WIDTH                 1u
#define MPU_RGD_WORD2_M5RE(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M5RE_SHIFT))&MPU_RGD_WORD2_M5RE_MASK)
#define MPU_RGD_WORD2_M6WE_MASK                  0x10000000u
#define MPU_RGD_WORD2_M6WE_SHIFT                 28u
#define MPU_RGD_WORD2_M6WE_WIDTH                 1u
#define MPU_RGD_WORD2_M6WE(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M6WE_SHIFT))&MPU_RGD_WORD2_M6WE_MASK)
#define MPU_RGD_WORD2_M6RE_MASK                  0x20000000u
#define MPU_RGD_WORD2_M6RE_SHIFT                 29u
#define MPU_RGD_WORD2_M6RE_WIDTH                 1u
#define MPU_RGD_WORD2_M6RE(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M6RE_SHIFT))&MPU_RGD_WORD2_M6RE_MASK)
#define MPU_RGD_WORD2_M7WE_MASK                  0x40000000u
#define MPU_RGD_WORD2_M7WE_SHIFT                 30u
#define MPU_RGD_WORD2_M7WE_WIDTH                 1u
#define MPU_RGD_WORD2_M7WE(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M7WE_SHIFT))&MPU_RGD_WORD2_M7WE_MASK)
#define MPU_RGD_WORD2_M7RE_MASK                  0x80000000u
#define MPU_RGD_WORD2_M7RE_SHIFT                 31u
#define MPU_RGD_WORD2_M7RE_WIDTH                 1u
#define MPU_RGD_WORD2_M7RE(x)                    (((uint32)(((uint32)(x))<<MPU_RGD_WORD2_M7RE_SHIFT))&MPU_RGD_WORD2_M7RE_MASK)
/* RGD_WORD3 Bit Fields */
#define MPU_RGD_WORD3_VLD_MASK                   0x1u
#define MPU_RGD_WORD3_VLD_SHIFT                  0u
#define MPU_RGD_WORD3_VLD_WIDTH                  1u
#define MPU_RGD_WORD3_VLD(x)                     (((uint32)(((uint32)(x))<<MPU_RGD_WORD3_VLD_SHIFT))&MPU_RGD_WORD3_VLD_MASK)
#define MPU_RGD_WORD3_PIDMASK_MASK               0xFF0000u
#define MPU_RGD_WORD3_PIDMASK_SHIFT              16u
#define MPU_RGD_WORD3_PIDMASK_WIDTH              8u
#define MPU_RGD_WORD3_PIDMASK(x)                 (((uint32)(((uint32)(x))<<MPU_RGD_WORD3_PIDMASK_SHIFT))&MPU_RGD_WORD3_PIDMASK_MASK)
#define MPU_RGD_WORD3_PID_MASK                   0xFF000000u
#define MPU_RGD_WORD3_PID_SHIFT                  24u
#define MPU_RGD_WORD3_PID_WIDTH                  8u
#define MPU_RGD_WORD3_PID(x)                     (((uint32)(((uint32)(x))<<MPU_RGD_WORD3_PID_SHIFT))&MPU_RGD_WORD3_PID_MASK)
/* RGDAAC Bit Fields */
#define MPU_RGDAAC_M0UM_MASK                     0x7u
#define MPU_RGDAAC_M0UM_SHIFT                    0u
#define MPU_RGDAAC_M0UM_WIDTH                    3u
#define MPU_RGDAAC_M0UM(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M0UM_SHIFT))&MPU_RGDAAC_M0UM_MASK)
#define MPU_RGDAAC_M0SM_MASK                     0x18u
#define MPU_RGDAAC_M0SM_SHIFT                    3u
#define MPU_RGDAAC_M0SM_WIDTH                    2u
#define MPU_RGDAAC_M0SM(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M0SM_SHIFT))&MPU_RGDAAC_M0SM_MASK)
#define MPU_RGDAAC_M0PE_MASK                     0x20u
#define MPU_RGDAAC_M0PE_SHIFT                    5u
#define MPU_RGDAAC_M0PE_WIDTH                    1u
#define MPU_RGDAAC_M0PE(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M0PE_SHIFT))&MPU_RGDAAC_M0PE_MASK)
#define MPU_RGDAAC_M1UM_MASK                     0x1C0u
#define MPU_RGDAAC_M1UM_SHIFT                    6u
#define MPU_RGDAAC_M1UM_WIDTH                    3u
#define MPU_RGDAAC_M1UM(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M1UM_SHIFT))&MPU_RGDAAC_M1UM_MASK)
#define MPU_RGDAAC_M1SM_MASK                     0x600u
#define MPU_RGDAAC_M1SM_SHIFT                    9u
#define MPU_RGDAAC_M1SM_WIDTH                    2u
#define MPU_RGDAAC_M1SM(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M1SM_SHIFT))&MPU_RGDAAC_M1SM_MASK)
#define MPU_RGDAAC_M1PE_MASK                     0x800u
#define MPU_RGDAAC_M1PE_SHIFT                    11u
#define MPU_RGDAAC_M1PE_WIDTH                    1u
#define MPU_RGDAAC_M1PE(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M1PE_SHIFT))&MPU_RGDAAC_M1PE_MASK)
#define MPU_RGDAAC_M2UM_MASK                     0x7000u
#define MPU_RGDAAC_M2UM_SHIFT                    12u
#define MPU_RGDAAC_M2UM_WIDTH                    3u
#define MPU_RGDAAC_M2UM(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M2UM_SHIFT))&MPU_RGDAAC_M2UM_MASK)
#define MPU_RGDAAC_M2SM_MASK                     0x18000u
#define MPU_RGDAAC_M2SM_SHIFT                    15u
#define MPU_RGDAAC_M2SM_WIDTH                    2u
#define MPU_RGDAAC_M2SM(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M2SM_SHIFT))&MPU_RGDAAC_M2SM_MASK)
#define MPU_RGDAAC_M3UM_MASK                     0x1C0000u
#define MPU_RGDAAC_M3UM_SHIFT                    18u
#define MPU_RGDAAC_M3UM_WIDTH                    3u
#define MPU_RGDAAC_M3UM(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M3UM_SHIFT))&MPU_RGDAAC_M3UM_MASK)
#define MPU_RGDAAC_M3SM_MASK                     0x600000u
#define MPU_RGDAAC_M3SM_SHIFT                    21u
#define MPU_RGDAAC_M3SM_WIDTH                    2u
#define MPU_RGDAAC_M3SM(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M3SM_SHIFT))&MPU_RGDAAC_M3SM_MASK)
#define MPU_RGDAAC_M4WE_MASK                     0x1000000u
#define MPU_RGDAAC_M4WE_SHIFT                    24u
#define MPU_RGDAAC_M4WE_WIDTH                    1u
#define MPU_RGDAAC_M4WE(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M4WE_SHIFT))&MPU_RGDAAC_M4WE_MASK)
#define MPU_RGDAAC_M4RE_MASK                     0x2000000u
#define MPU_RGDAAC_M4RE_SHIFT                    25u
#define MPU_RGDAAC_M4RE_WIDTH                    1u
#define MPU_RGDAAC_M4RE(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M4RE_SHIFT))&MPU_RGDAAC_M4RE_MASK)
#define MPU_RGDAAC_M5WE_MASK                     0x4000000u
#define MPU_RGDAAC_M5WE_SHIFT                    26u
#define MPU_RGDAAC_M5WE_WIDTH                    1u
#define MPU_RGDAAC_M5WE(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M5WE_SHIFT))&MPU_RGDAAC_M5WE_MASK)
#define MPU_RGDAAC_M5RE_MASK                     0x8000000u
#define MPU_RGDAAC_M5RE_SHIFT                    27u
#define MPU_RGDAAC_M5RE_WIDTH                    1u
#define MPU_RGDAAC_M5RE(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M5RE_SHIFT))&MPU_RGDAAC_M5RE_MASK)
#define MPU_RGDAAC_M6WE_MASK                     0x10000000u
#define MPU_RGDAAC_M6WE_SHIFT                    28u
#define MPU_RGDAAC_M6WE_WIDTH                    1u
#define MPU_RGDAAC_M6WE(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M6WE_SHIFT))&MPU_RGDAAC_M6WE_MASK)
#define MPU_RGDAAC_M6RE_MASK                     0x20000000u
#define MPU_RGDAAC_M6RE_SHIFT                    29u
#define MPU_RGDAAC_M6RE_WIDTH                    1u
#define MPU_RGDAAC_M6RE(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M6RE_SHIFT))&MPU_RGDAAC_M6RE_MASK)
#define MPU_RGDAAC_M7WE_MASK                     0x40000000u
#define MPU_RGDAAC_M7WE_SHIFT                    30u
#define MPU_RGDAAC_M7WE_WIDTH                    1u
#define MPU_RGDAAC_M7WE(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M7WE_SHIFT))&MPU_RGDAAC_M7WE_MASK)
#define MPU_RGDAAC_M7RE_MASK                     0x80000000u
#define MPU_RGDAAC_M7RE_SHIFT                    31u
#define MPU_RGDAAC_M7RE_WIDTH                    1u
#define MPU_RGDAAC_M7RE(x)                       (((uint32)(((uint32)(x))<<MPU_RGDAAC_M7RE_SHIFT))&MPU_RGDAAC_M7RE_MASK)

/*!
 * @}
 */ /* end of group MPU_Register_Masks */


/*!
 * @}
 */ /* end of group MPU_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MSCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCM_Peripheral_Access_Layer MSCM Peripheral Access Layer
 * @{
 */


/** MSCM - Size of Registers Arrays */
#define MSCM_OCMDR_COUNT                         4u

/** MSCM - Register Layout Typedef */
typedef struct {
  __I  uint32 CPxTYPE;                           /**< Processor X Type Register, offset: 0x0 */
  __I  uint32 CPxNUM;                            /**< Processor X Number Register, offset: 0x4 */
  __I  uint32 CPxMASTER;                         /**< Processor X Master Register, offset: 0x8 */
  __I  uint32 CPxCOUNT;                          /**< Processor X Count Register, offset: 0xC */
  __I  uint32 CPxCFG0;                           /**< Processor X Configuration Register 0, offset: 0x10 */
  __I  uint32 CPxCFG1;                           /**< Processor X Configuration Register 1, offset: 0x14 */
  __I  uint32 CPxCFG2;                           /**< Processor X Configuration Register 2, offset: 0x18 */
  __I  uint32 CPxCFG3;                           /**< Processor X Configuration Register 3, offset: 0x1C */
  __I  uint32 CP0TYPE;                           /**< Processor 0 Type Register, offset: 0x20 */
  __I  uint32 CP0NUM;                            /**< Processor 0 Number Register, offset: 0x24 */
  __I  uint32 CP0MASTER;                         /**< Processor 0 Master Register, offset: 0x28 */
  __I  uint32 CP0COUNT;                          /**< Processor 0 Count Register, offset: 0x2C */
  __I  uint32 CP0CFG0;                           /**< Processor 0 Configuration Register 0, offset: 0x30 */
  __I  uint32 CP0CFG1;                           /**< Processor 0 Configuration Register 1, offset: 0x34 */
  __I  uint32 CP0CFG2;                           /**< Processor 0 Configuration Register 2, offset: 0x38 */
  __I  uint32 CP0CFG3;                           /**< Processor 0 Configuration Register 3, offset: 0x3C */
       uint8 RESERVED_0[960];
  __IO uint32 OCMDR[MSCM_OCMDR_COUNT];           /**< On-Chip Memory Descriptor Register, array offset: 0x400, array step: 0x4 */
} MSCM_Type, *MSCM_MemMapPtr;

 /** Number of instances of the MSCM module. */
#define MSCM_INSTANCE_COUNT                      (1u)


/* MSCM - Peripheral instance base addresses */
/** Peripheral MSCM base address */
#define MSCM_BASE                                (0x40001000u)
/** Peripheral MSCM base pointer */
#define MSCM                                     ((MSCM_Type *)MSCM_BASE)
/** Array initializer of MSCM peripheral base addresses */
#define MSCM_BASE_ADDRS                          { MSCM_BASE }
/** Array initializer of MSCM peripheral base pointers */
#define MSCM_BASE_PTRS                           { MSCM }

/* ----------------------------------------------------------------------------
   -- MSCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCM_Register_Masks MSCM Register Masks
 * @{
 */

/* CPxTYPE Bit Fields */
#define MSCM_CPxTYPE_RYPZ_MASK                   0xFFu
#define MSCM_CPxTYPE_RYPZ_SHIFT                  0u
#define MSCM_CPxTYPE_RYPZ_WIDTH                  8u
#define MSCM_CPxTYPE_RYPZ(x)                     (((uint32)(((uint32)(x))<<MSCM_CPxTYPE_RYPZ_SHIFT))&MSCM_CPxTYPE_RYPZ_MASK)
#define MSCM_CPxTYPE_PERSONALITY_MASK            0xFFFFFF00u
#define MSCM_CPxTYPE_PERSONALITY_SHIFT           8u
#define MSCM_CPxTYPE_PERSONALITY_WIDTH           24u
#define MSCM_CPxTYPE_PERSONALITY(x)              (((uint32)(((uint32)(x))<<MSCM_CPxTYPE_PERSONALITY_SHIFT))&MSCM_CPxTYPE_PERSONALITY_MASK)
/* CPxNUM Bit Fields */
#define MSCM_CPxNUM_CPN_MASK                     0x1u
#define MSCM_CPxNUM_CPN_SHIFT                    0u
#define MSCM_CPxNUM_CPN_WIDTH                    1u
#define MSCM_CPxNUM_CPN(x)                       (((uint32)(((uint32)(x))<<MSCM_CPxNUM_CPN_SHIFT))&MSCM_CPxNUM_CPN_MASK)
/* CPxMASTER Bit Fields */
#define MSCM_CPxMASTER_PPMN_MASK                 0x3Fu
#define MSCM_CPxMASTER_PPMN_SHIFT                0u
#define MSCM_CPxMASTER_PPMN_WIDTH                6u
#define MSCM_CPxMASTER_PPMN(x)                   (((uint32)(((uint32)(x))<<MSCM_CPxMASTER_PPMN_SHIFT))&MSCM_CPxMASTER_PPMN_MASK)
/* CPxCOUNT Bit Fields */
#define MSCM_CPxCOUNT_PCNT_MASK                  0x3u
#define MSCM_CPxCOUNT_PCNT_SHIFT                 0u
#define MSCM_CPxCOUNT_PCNT_WIDTH                 2u
#define MSCM_CPxCOUNT_PCNT(x)                    (((uint32)(((uint32)(x))<<MSCM_CPxCOUNT_PCNT_SHIFT))&MSCM_CPxCOUNT_PCNT_MASK)
/* CPxCFG0 Bit Fields */
#define MSCM_CPxCFG0_DCWY_MASK                   0xFFu
#define MSCM_CPxCFG0_DCWY_SHIFT                  0u
#define MSCM_CPxCFG0_DCWY_WIDTH                  8u
#define MSCM_CPxCFG0_DCWY(x)                     (((uint32)(((uint32)(x))<<MSCM_CPxCFG0_DCWY_SHIFT))&MSCM_CPxCFG0_DCWY_MASK)
#define MSCM_CPxCFG0_DCSZ_MASK                   0xFF00u
#define MSCM_CPxCFG0_DCSZ_SHIFT                  8u
#define MSCM_CPxCFG0_DCSZ_WIDTH                  8u
#define MSCM_CPxCFG0_DCSZ(x)                     (((uint32)(((uint32)(x))<<MSCM_CPxCFG0_DCSZ_SHIFT))&MSCM_CPxCFG0_DCSZ_MASK)
#define MSCM_CPxCFG0_ICWY_MASK                   0xFF0000u
#define MSCM_CPxCFG0_ICWY_SHIFT                  16u
#define MSCM_CPxCFG0_ICWY_WIDTH                  8u
#define MSCM_CPxCFG0_ICWY(x)                     (((uint32)(((uint32)(x))<<MSCM_CPxCFG0_ICWY_SHIFT))&MSCM_CPxCFG0_ICWY_MASK)
#define MSCM_CPxCFG0_ICSZ_MASK                   0xFF000000u
#define MSCM_CPxCFG0_ICSZ_SHIFT                  24u
#define MSCM_CPxCFG0_ICSZ_WIDTH                  8u
#define MSCM_CPxCFG0_ICSZ(x)                     (((uint32)(((uint32)(x))<<MSCM_CPxCFG0_ICSZ_SHIFT))&MSCM_CPxCFG0_ICSZ_MASK)
/* CPxCFG1 Bit Fields */
#define MSCM_CPxCFG1_L2WY_MASK                   0xFF0000u
#define MSCM_CPxCFG1_L2WY_SHIFT                  16u
#define MSCM_CPxCFG1_L2WY_WIDTH                  8u
#define MSCM_CPxCFG1_L2WY(x)                     (((uint32)(((uint32)(x))<<MSCM_CPxCFG1_L2WY_SHIFT))&MSCM_CPxCFG1_L2WY_MASK)
#define MSCM_CPxCFG1_L2SZ_MASK                   0xFF000000u
#define MSCM_CPxCFG1_L2SZ_SHIFT                  24u
#define MSCM_CPxCFG1_L2SZ_WIDTH                  8u
#define MSCM_CPxCFG1_L2SZ(x)                     (((uint32)(((uint32)(x))<<MSCM_CPxCFG1_L2SZ_SHIFT))&MSCM_CPxCFG1_L2SZ_MASK)
/* CPxCFG2 Bit Fields */
#define MSCM_CPxCFG2_TMUSZ_MASK                  0xFF00u
#define MSCM_CPxCFG2_TMUSZ_SHIFT                 8u
#define MSCM_CPxCFG2_TMUSZ_WIDTH                 8u
#define MSCM_CPxCFG2_TMUSZ(x)                    (((uint32)(((uint32)(x))<<MSCM_CPxCFG2_TMUSZ_SHIFT))&MSCM_CPxCFG2_TMUSZ_MASK)
#define MSCM_CPxCFG2_TMLSZ_MASK                  0xFF000000u
#define MSCM_CPxCFG2_TMLSZ_SHIFT                 24u
#define MSCM_CPxCFG2_TMLSZ_WIDTH                 8u
#define MSCM_CPxCFG2_TMLSZ(x)                    (((uint32)(((uint32)(x))<<MSCM_CPxCFG2_TMLSZ_SHIFT))&MSCM_CPxCFG2_TMLSZ_MASK)
/* CPxCFG3 Bit Fields */
#define MSCM_CPxCFG3_FPU_MASK                    0x1u
#define MSCM_CPxCFG3_FPU_SHIFT                   0u
#define MSCM_CPxCFG3_FPU_WIDTH                   1u
#define MSCM_CPxCFG3_FPU(x)                      (((uint32)(((uint32)(x))<<MSCM_CPxCFG3_FPU_SHIFT))&MSCM_CPxCFG3_FPU_MASK)
#define MSCM_CPxCFG3_SIMD_MASK                   0x2u
#define MSCM_CPxCFG3_SIMD_SHIFT                  1u
#define MSCM_CPxCFG3_SIMD_WIDTH                  1u
#define MSCM_CPxCFG3_SIMD(x)                     (((uint32)(((uint32)(x))<<MSCM_CPxCFG3_SIMD_SHIFT))&MSCM_CPxCFG3_SIMD_MASK)
#define MSCM_CPxCFG3_JAZ_MASK                    0x4u
#define MSCM_CPxCFG3_JAZ_SHIFT                   2u
#define MSCM_CPxCFG3_JAZ_WIDTH                   1u
#define MSCM_CPxCFG3_JAZ(x)                      (((uint32)(((uint32)(x))<<MSCM_CPxCFG3_JAZ_SHIFT))&MSCM_CPxCFG3_JAZ_MASK)
#define MSCM_CPxCFG3_MMU_MASK                    0x8u
#define MSCM_CPxCFG3_MMU_SHIFT                   3u
#define MSCM_CPxCFG3_MMU_WIDTH                   1u
#define MSCM_CPxCFG3_MMU(x)                      (((uint32)(((uint32)(x))<<MSCM_CPxCFG3_MMU_SHIFT))&MSCM_CPxCFG3_MMU_MASK)
#define MSCM_CPxCFG3_TZ_MASK                     0x10u
#define MSCM_CPxCFG3_TZ_SHIFT                    4u
#define MSCM_CPxCFG3_TZ_WIDTH                    1u
#define MSCM_CPxCFG3_TZ(x)                       (((uint32)(((uint32)(x))<<MSCM_CPxCFG3_TZ_SHIFT))&MSCM_CPxCFG3_TZ_MASK)
#define MSCM_CPxCFG3_CMP_MASK                    0x20u
#define MSCM_CPxCFG3_CMP_SHIFT                   5u
#define MSCM_CPxCFG3_CMP_WIDTH                   1u
#define MSCM_CPxCFG3_CMP(x)                      (((uint32)(((uint32)(x))<<MSCM_CPxCFG3_CMP_SHIFT))&MSCM_CPxCFG3_CMP_MASK)
#define MSCM_CPxCFG3_BB_MASK                     0x40u
#define MSCM_CPxCFG3_BB_SHIFT                    6u
#define MSCM_CPxCFG3_BB_WIDTH                    1u
#define MSCM_CPxCFG3_BB(x)                       (((uint32)(((uint32)(x))<<MSCM_CPxCFG3_BB_SHIFT))&MSCM_CPxCFG3_BB_MASK)
#define MSCM_CPxCFG3_SBP_MASK                    0x300u
#define MSCM_CPxCFG3_SBP_SHIFT                   8u
#define MSCM_CPxCFG3_SBP_WIDTH                   2u
#define MSCM_CPxCFG3_SBP(x)                      (((uint32)(((uint32)(x))<<MSCM_CPxCFG3_SBP_SHIFT))&MSCM_CPxCFG3_SBP_MASK)
/* CP0TYPE Bit Fields */
#define MSCM_CP0TYPE_RYPZ_MASK                   0xFFu
#define MSCM_CP0TYPE_RYPZ_SHIFT                  0u
#define MSCM_CP0TYPE_RYPZ_WIDTH                  8u
#define MSCM_CP0TYPE_RYPZ(x)                     (((uint32)(((uint32)(x))<<MSCM_CP0TYPE_RYPZ_SHIFT))&MSCM_CP0TYPE_RYPZ_MASK)
#define MSCM_CP0TYPE_PERSONALITY_MASK            0xFFFFFF00u
#define MSCM_CP0TYPE_PERSONALITY_SHIFT           8u
#define MSCM_CP0TYPE_PERSONALITY_WIDTH           24u
#define MSCM_CP0TYPE_PERSONALITY(x)              (((uint32)(((uint32)(x))<<MSCM_CP0TYPE_PERSONALITY_SHIFT))&MSCM_CP0TYPE_PERSONALITY_MASK)
/* CP0NUM Bit Fields */
#define MSCM_CP0NUM_CPN_MASK                     0x1u
#define MSCM_CP0NUM_CPN_SHIFT                    0u
#define MSCM_CP0NUM_CPN_WIDTH                    1u
#define MSCM_CP0NUM_CPN(x)                       (((uint32)(((uint32)(x))<<MSCM_CP0NUM_CPN_SHIFT))&MSCM_CP0NUM_CPN_MASK)
/* CP0MASTER Bit Fields */
#define MSCM_CP0MASTER_PPMN_MASK                 0x3Fu
#define MSCM_CP0MASTER_PPMN_SHIFT                0u
#define MSCM_CP0MASTER_PPMN_WIDTH                6u
#define MSCM_CP0MASTER_PPMN(x)                   (((uint32)(((uint32)(x))<<MSCM_CP0MASTER_PPMN_SHIFT))&MSCM_CP0MASTER_PPMN_MASK)
/* CP0COUNT Bit Fields */
#define MSCM_CP0COUNT_PCNT_MASK                  0x3u
#define MSCM_CP0COUNT_PCNT_SHIFT                 0u
#define MSCM_CP0COUNT_PCNT_WIDTH                 2u
#define MSCM_CP0COUNT_PCNT(x)                    (((uint32)(((uint32)(x))<<MSCM_CP0COUNT_PCNT_SHIFT))&MSCM_CP0COUNT_PCNT_MASK)
/* CP0CFG0 Bit Fields */
#define MSCM_CP0CFG0_DCWY_MASK                   0xFFu
#define MSCM_CP0CFG0_DCWY_SHIFT                  0u
#define MSCM_CP0CFG0_DCWY_WIDTH                  8u
#define MSCM_CP0CFG0_DCWY(x)                     (((uint32)(((uint32)(x))<<MSCM_CP0CFG0_DCWY_SHIFT))&MSCM_CP0CFG0_DCWY_MASK)
#define MSCM_CP0CFG0_DCSZ_MASK                   0xFF00u
#define MSCM_CP0CFG0_DCSZ_SHIFT                  8u
#define MSCM_CP0CFG0_DCSZ_WIDTH                  8u
#define MSCM_CP0CFG0_DCSZ(x)                     (((uint32)(((uint32)(x))<<MSCM_CP0CFG0_DCSZ_SHIFT))&MSCM_CP0CFG0_DCSZ_MASK)
#define MSCM_CP0CFG0_ICWY_MASK                   0xFF0000u
#define MSCM_CP0CFG0_ICWY_SHIFT                  16u
#define MSCM_CP0CFG0_ICWY_WIDTH                  8u
#define MSCM_CP0CFG0_ICWY(x)                     (((uint32)(((uint32)(x))<<MSCM_CP0CFG0_ICWY_SHIFT))&MSCM_CP0CFG0_ICWY_MASK)
#define MSCM_CP0CFG0_ICSZ_MASK                   0xFF000000u
#define MSCM_CP0CFG0_ICSZ_SHIFT                  24u
#define MSCM_CP0CFG0_ICSZ_WIDTH                  8u
#define MSCM_CP0CFG0_ICSZ(x)                     (((uint32)(((uint32)(x))<<MSCM_CP0CFG0_ICSZ_SHIFT))&MSCM_CP0CFG0_ICSZ_MASK)
/* CP0CFG1 Bit Fields */
#define MSCM_CP0CFG1_L2WY_MASK                   0xFF0000u
#define MSCM_CP0CFG1_L2WY_SHIFT                  16u
#define MSCM_CP0CFG1_L2WY_WIDTH                  8u
#define MSCM_CP0CFG1_L2WY(x)                     (((uint32)(((uint32)(x))<<MSCM_CP0CFG1_L2WY_SHIFT))&MSCM_CP0CFG1_L2WY_MASK)
#define MSCM_CP0CFG1_L2SZ_MASK                   0xFF000000u
#define MSCM_CP0CFG1_L2SZ_SHIFT                  24u
#define MSCM_CP0CFG1_L2SZ_WIDTH                  8u
#define MSCM_CP0CFG1_L2SZ(x)                     (((uint32)(((uint32)(x))<<MSCM_CP0CFG1_L2SZ_SHIFT))&MSCM_CP0CFG1_L2SZ_MASK)
/* CP0CFG2 Bit Fields */
#define MSCM_CP0CFG2_TMUSZ_MASK                  0xFF00u
#define MSCM_CP0CFG2_TMUSZ_SHIFT                 8u
#define MSCM_CP0CFG2_TMUSZ_WIDTH                 8u
#define MSCM_CP0CFG2_TMUSZ(x)                    (((uint32)(((uint32)(x))<<MSCM_CP0CFG2_TMUSZ_SHIFT))&MSCM_CP0CFG2_TMUSZ_MASK)
#define MSCM_CP0CFG2_TMLSZ_MASK                  0xFF000000u
#define MSCM_CP0CFG2_TMLSZ_SHIFT                 24u
#define MSCM_CP0CFG2_TMLSZ_WIDTH                 8u
#define MSCM_CP0CFG2_TMLSZ(x)                    (((uint32)(((uint32)(x))<<MSCM_CP0CFG2_TMLSZ_SHIFT))&MSCM_CP0CFG2_TMLSZ_MASK)
/* CP0CFG3 Bit Fields */
#define MSCM_CP0CFG3_FPU_MASK                    0x1u
#define MSCM_CP0CFG3_FPU_SHIFT                   0u
#define MSCM_CP0CFG3_FPU_WIDTH                   1u
#define MSCM_CP0CFG3_FPU(x)                      (((uint32)(((uint32)(x))<<MSCM_CP0CFG3_FPU_SHIFT))&MSCM_CP0CFG3_FPU_MASK)
#define MSCM_CP0CFG3_SIMD_MASK                   0x2u
#define MSCM_CP0CFG3_SIMD_SHIFT                  1u
#define MSCM_CP0CFG3_SIMD_WIDTH                  1u
#define MSCM_CP0CFG3_SIMD(x)                     (((uint32)(((uint32)(x))<<MSCM_CP0CFG3_SIMD_SHIFT))&MSCM_CP0CFG3_SIMD_MASK)
#define MSCM_CP0CFG3_JAZ_MASK                    0x4u
#define MSCM_CP0CFG3_JAZ_SHIFT                   2u
#define MSCM_CP0CFG3_JAZ_WIDTH                   1u
#define MSCM_CP0CFG3_JAZ(x)                      (((uint32)(((uint32)(x))<<MSCM_CP0CFG3_JAZ_SHIFT))&MSCM_CP0CFG3_JAZ_MASK)
#define MSCM_CP0CFG3_MMU_MASK                    0x8u
#define MSCM_CP0CFG3_MMU_SHIFT                   3u
#define MSCM_CP0CFG3_MMU_WIDTH                   1u
#define MSCM_CP0CFG3_MMU(x)                      (((uint32)(((uint32)(x))<<MSCM_CP0CFG3_MMU_SHIFT))&MSCM_CP0CFG3_MMU_MASK)
#define MSCM_CP0CFG3_TZ_MASK                     0x10u
#define MSCM_CP0CFG3_TZ_SHIFT                    4u
#define MSCM_CP0CFG3_TZ_WIDTH                    1u
#define MSCM_CP0CFG3_TZ(x)                       (((uint32)(((uint32)(x))<<MSCM_CP0CFG3_TZ_SHIFT))&MSCM_CP0CFG3_TZ_MASK)
#define MSCM_CP0CFG3_CMP_MASK                    0x20u
#define MSCM_CP0CFG3_CMP_SHIFT                   5u
#define MSCM_CP0CFG3_CMP_WIDTH                   1u
#define MSCM_CP0CFG3_CMP(x)                      (((uint32)(((uint32)(x))<<MSCM_CP0CFG3_CMP_SHIFT))&MSCM_CP0CFG3_CMP_MASK)
#define MSCM_CP0CFG3_BB_MASK                     0x40u
#define MSCM_CP0CFG3_BB_SHIFT                    6u
#define MSCM_CP0CFG3_BB_WIDTH                    1u
#define MSCM_CP0CFG3_BB(x)                       (((uint32)(((uint32)(x))<<MSCM_CP0CFG3_BB_SHIFT))&MSCM_CP0CFG3_BB_MASK)
#define MSCM_CP0CFG3_SBP_MASK                    0x300u
#define MSCM_CP0CFG3_SBP_SHIFT                   8u
#define MSCM_CP0CFG3_SBP_WIDTH                   2u
#define MSCM_CP0CFG3_SBP(x)                      (((uint32)(((uint32)(x))<<MSCM_CP0CFG3_SBP_SHIFT))&MSCM_CP0CFG3_SBP_MASK)
/* OCMDR Bit Fields */
#define MSCM_OCMDR_OCM0_MASK                     0xFu
#define MSCM_OCMDR_OCM0_SHIFT                    0u
#define MSCM_OCMDR_OCM0_WIDTH                    4u
#define MSCM_OCMDR_OCM0(x)                       (((uint32)(((uint32)(x))<<MSCM_OCMDR_OCM0_SHIFT))&MSCM_OCMDR_OCM0_MASK)
#define MSCM_OCMDR_OCM1_MASK                     0xF0u
#define MSCM_OCMDR_OCM1_SHIFT                    4u
#define MSCM_OCMDR_OCM1_WIDTH                    4u
#define MSCM_OCMDR_OCM1(x)                       (((uint32)(((uint32)(x))<<MSCM_OCMDR_OCM1_SHIFT))&MSCM_OCMDR_OCM1_MASK)
#define MSCM_OCMDR_OCM2_MASK                     0xF00u
#define MSCM_OCMDR_OCM2_SHIFT                    8u
#define MSCM_OCMDR_OCM2_WIDTH                    4u
#define MSCM_OCMDR_OCM2(x)                       (((uint32)(((uint32)(x))<<MSCM_OCMDR_OCM2_SHIFT))&MSCM_OCMDR_OCM2_MASK)
#define MSCM_OCMDR_OCMPU_MASK                    0x1000u
#define MSCM_OCMDR_OCMPU_SHIFT                   12u
#define MSCM_OCMDR_OCMPU_WIDTH                   1u
#define MSCM_OCMDR_OCMPU(x)                      (((uint32)(((uint32)(x))<<MSCM_OCMDR_OCMPU_SHIFT))&MSCM_OCMDR_OCMPU_MASK)
#define MSCM_OCMDR_OCMT_MASK                     0xE000u
#define MSCM_OCMDR_OCMT_SHIFT                    13u
#define MSCM_OCMDR_OCMT_WIDTH                    3u
#define MSCM_OCMDR_OCMT(x)                       (((uint32)(((uint32)(x))<<MSCM_OCMDR_OCMT_SHIFT))&MSCM_OCMDR_OCMT_MASK)
#define MSCM_OCMDR_RO_MASK                       0x10000u
#define MSCM_OCMDR_RO_SHIFT                      16u
#define MSCM_OCMDR_RO_WIDTH                      1u
#define MSCM_OCMDR_RO(x)                         (((uint32)(((uint32)(x))<<MSCM_OCMDR_RO_SHIFT))&MSCM_OCMDR_RO_MASK)
#define MSCM_OCMDR_OCMW_MASK                     0xE0000u
#define MSCM_OCMDR_OCMW_SHIFT                    17u
#define MSCM_OCMDR_OCMW_WIDTH                    3u
#define MSCM_OCMDR_OCMW(x)                       (((uint32)(((uint32)(x))<<MSCM_OCMDR_OCMW_SHIFT))&MSCM_OCMDR_OCMW_MASK)
#define MSCM_OCMDR_OCMSZ_MASK                    0xF000000u
#define MSCM_OCMDR_OCMSZ_SHIFT                   24u
#define MSCM_OCMDR_OCMSZ_WIDTH                   4u
#define MSCM_OCMDR_OCMSZ(x)                      (((uint32)(((uint32)(x))<<MSCM_OCMDR_OCMSZ_SHIFT))&MSCM_OCMDR_OCMSZ_MASK)
#define MSCM_OCMDR_OCMSZH_MASK                   0x10000000u
#define MSCM_OCMDR_OCMSZH_SHIFT                  28u
#define MSCM_OCMDR_OCMSZH_WIDTH                  1u
#define MSCM_OCMDR_OCMSZH(x)                     (((uint32)(((uint32)(x))<<MSCM_OCMDR_OCMSZH_SHIFT))&MSCM_OCMDR_OCMSZH_MASK)
#define MSCM_OCMDR_V_MASK                        0x80000000u
#define MSCM_OCMDR_V_SHIFT                       31u
#define MSCM_OCMDR_V_WIDTH                       1u
#define MSCM_OCMDR_V(x)                          (((uint32)(((uint32)(x))<<MSCM_OCMDR_V_SHIFT))&MSCM_OCMDR_V_MASK)

/*!
 * @}
 */ /* end of group MSCM_Register_Masks */


/*!
 * @}
 */ /* end of group MSCM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PCC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC_Peripheral_Access_Layer PCC Peripheral Access Layer
 * @{
 */


/** PCC - Size of Registers Arrays */
#define PCC_PCCn_COUNT                           116u

/** PCC - Register Layout Typedef */
typedef struct {
  __IO uint32 PCCn[PCC_PCCn_COUNT];              /**< PCC Reserved Register 0..PCC CMP0 Register, array offset: 0x0, array step: 0x4 */
} PCC_Type, *PCC_MemMapPtr;

 /** Number of instances of the PCC module. */
#define PCC_INSTANCE_COUNT                       (1u)


/* PCC - Peripheral instance base addresses */
/** Peripheral PCC base address */
#define PCC_BASE                                 (0x40065000u)
/** Peripheral PCC base pointer */
#define PCC                                      ((PCC_Type *)PCC_BASE)
/** Array initializer of PCC peripheral base addresses */
#define PCC_BASE_ADDRS                           { PCC_BASE }
/** Array initializer of PCC peripheral base pointers */
#define PCC_BASE_PTRS                            { PCC }

/* PCC index offsets */
#define PCC_FTFC_INDEX                           32
#define PCC_DMAMUX_INDEX                         33
#define PCC_FlexCAN0_INDEX                       36
#define PCC_FlexCAN1_INDEX                       37
#define PCC_FTM3_INDEX                           38
#define PCC_ADC1_INDEX                           39
#define PCC_FlexCAN2_INDEX                       43
#define PCC_LPSPI0_INDEX                         44
#define PCC_LPSPI1_INDEX                         45
#define PCC_LPSPI2_INDEX                         46
#define PCC_PDB1_INDEX                           49
#define PCC_CRC_INDEX                            50
#define PCC_PDB0_INDEX                           54
#define PCC_LPIT_INDEX                           55
#define PCC_FTM0_INDEX                           56
#define PCC_FTM1_INDEX                           57
#define PCC_FTM2_INDEX                           58
#define PCC_ADC0_INDEX                           59
#define PCC_RTC_INDEX                            61
#define PCC_LPTMR0_INDEX                         64
#define PCC_PORTA_INDEX                          73
#define PCC_PORTB_INDEX                          74
#define PCC_PORTC_INDEX                          75
#define PCC_PORTD_INDEX                          76
#define PCC_PORTE_INDEX                          77
#define PCC_FlexIO_INDEX                         90
#define PCC_EWM_INDEX                            97
#define PCC_LPI2C0_INDEX                         102
#define PCC_LPUART0_INDEX                        106
#define PCC_LPUART1_INDEX                        107
#define PCC_LPUART2_INDEX                        108
#define PCC_CMP0_INDEX                           115

/* ----------------------------------------------------------------------------
   -- PCC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC_Register_Masks PCC Register Masks
 * @{
 */

/* PCCn Bit Fields */
#define PCC_PCCn_PCD_MASK                        0x7u
#define PCC_PCCn_PCD_SHIFT                       0u
#define PCC_PCCn_PCD_WIDTH                       3u
#define PCC_PCCn_PCD(x)                          (((uint32)(((uint32)(x))<<PCC_PCCn_PCD_SHIFT))&PCC_PCCn_PCD_MASK)
#define PCC_PCCn_FRAC_MASK                       0x8u
#define PCC_PCCn_FRAC_SHIFT                      3u
#define PCC_PCCn_FRAC_WIDTH                      1u
#define PCC_PCCn_FRAC(x)                         (((uint32)(((uint32)(x))<<PCC_PCCn_FRAC_SHIFT))&PCC_PCCn_FRAC_MASK)
#define PCC_PCCn_PCS_MASK                        0x7000000u
#define PCC_PCCn_PCS_SHIFT                       24u
#define PCC_PCCn_PCS_WIDTH                       3u
#define PCC_PCCn_PCS(x)                          (((uint32)(((uint32)(x))<<PCC_PCCn_PCS_SHIFT))&PCC_PCCn_PCS_MASK)
#define PCC_PCCn_CGC_MASK                        0x40000000u
#define PCC_PCCn_CGC_SHIFT                       30u
#define PCC_PCCn_CGC_WIDTH                       1u
#define PCC_PCCn_CGC(x)                          (((uint32)(((uint32)(x))<<PCC_PCCn_CGC_SHIFT))&PCC_PCCn_CGC_MASK)
#define PCC_PCCn_PR_MASK                         0x80000000u
#define PCC_PCCn_PR_SHIFT                        31u
#define PCC_PCCn_PR_WIDTH                        1u
#define PCC_PCCn_PR(x)                           (((uint32)(((uint32)(x))<<PCC_PCCn_PR_SHIFT))&PCC_PCCn_PR_MASK)

/*!
 * @}
 */ /* end of group PCC_Register_Masks */


/*!
 * @}
 */ /* end of group PCC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PDB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDB_Peripheral_Access_Layer PDB Peripheral Access Layer
 * @{
 */


/** PDB - Size of Registers Arrays */
#define PDB_CH_COUNT                             2u
#define PDB_DLY_COUNT                            8u
#define PDB_POnDLY_COUNT                         1u

/** PDB - Register Layout Typedef */
typedef struct {
  __IO uint32 SC;                                /**< Status and Control register, offset: 0x0 */
  __IO uint32 MOD;                               /**< Modulus register, offset: 0x4 */
  __I  uint32 CNT;                               /**< Counter register, offset: 0x8 */
  __IO uint32 IDLY;                              /**< Interrupt Delay register, offset: 0xC */
  struct {                                         /* offset: 0x10, array step: 0x28 */
    __IO uint32 C1;                                /**< Channel n Control register 1, array offset: 0x10, array step: 0x28 */
    __IO uint32 S;                                 /**< Channel n Status register, array offset: 0x14, array step: 0x28 */
    __IO uint32 DLY[PDB_DLY_COUNT];                /**< Channel n Delay 0 register..Channel n Delay 7 register, array offset: 0x18, array step: index*0x28, index2*0x4 */
  } CH[PDB_CH_COUNT];
       uint8 RESERVED_0[304];
  __IO uint32 POEN;                              /**< Pulse-Out n Enable register, offset: 0x190 */
  /* Deviation MISRA-1 */
  union {                                          /* offset: 0x194, array step: 0x4 */
    __IO uint32 PODLY;                             /**< Pulse-Out n Delay register, array offset: 0x194, array step: 0x4 */
    struct {                                         /* offset: 0x194, array step: 0x4 */
      __IO uint16 DLY2;                              /**< PDB1_DLY2 register...PDB0_DLY2 register., array offset: 0x194, array step: 0x4 */
      __IO uint16 DLY1;                              /**< PDB1_DLY1 register...PDB0_DLY1 register., array offset: 0x196, array step: 0x4 */
    } ACCESS16BIT;
  } POnDLY[PDB_POnDLY_COUNT];
} PDB_Type, *PDB_MemMapPtr;

 /** Number of instances of the PDB module. */
#define PDB_INSTANCE_COUNT                       (2u)


/* PDB - Peripheral instance base addresses */
/** Peripheral PDB0 base address */
#define PDB0_BASE                                (0x40036000u)
/** Peripheral PDB0 base pointer */
#define PDB0                                     ((PDB_Type *)PDB0_BASE)
/** Peripheral PDB1 base address */
#define PDB1_BASE                                (0x40031000u)
/** Peripheral PDB1 base pointer */
#define PDB1                                     ((PDB_Type *)PDB1_BASE)
/** Array initializer of PDB peripheral base addresses */
#define PDB_BASE_ADDRS                           { PDB0_BASE, PDB1_BASE }
/** Array initializer of PDB peripheral base pointers */
#define PDB_BASE_PTRS                            { PDB0, PDB1 }
 /** Number of interrupt vector arrays for the PDB module. */
#define PDB_IRQS_ARR_COUNT                       (1u)
 /** Number of interrupt channels for the PDB module. */
#define PDB_IRQS_CH_COUNT                        (1u)
/** Interrupt vectors for the PDB peripheral type */
#define PDB_IRQS                                 { PDB0_IRQn, PDB1_IRQn }

/* ----------------------------------------------------------------------------
   -- PDB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDB_Register_Masks PDB Register Masks
 * @{
 */

/* SC Bit Fields */
#define PDB_SC_LDOK_MASK                         0x1u
#define PDB_SC_LDOK_SHIFT                        0u
#define PDB_SC_LDOK_WIDTH                        1u
#define PDB_SC_LDOK(x)                           (((uint32)(((uint32)(x))<<PDB_SC_LDOK_SHIFT))&PDB_SC_LDOK_MASK)
#define PDB_SC_CONT_MASK                         0x2u
#define PDB_SC_CONT_SHIFT                        1u
#define PDB_SC_CONT_WIDTH                        1u
#define PDB_SC_CONT(x)                           (((uint32)(((uint32)(x))<<PDB_SC_CONT_SHIFT))&PDB_SC_CONT_MASK)
#define PDB_SC_MULT_MASK                         0xCu
#define PDB_SC_MULT_SHIFT                        2u
#define PDB_SC_MULT_WIDTH                        2u
#define PDB_SC_MULT(x)                           (((uint32)(((uint32)(x))<<PDB_SC_MULT_SHIFT))&PDB_SC_MULT_MASK)
#define PDB_SC_PDBIE_MASK                        0x20u
#define PDB_SC_PDBIE_SHIFT                       5u
#define PDB_SC_PDBIE_WIDTH                       1u
#define PDB_SC_PDBIE(x)                          (((uint32)(((uint32)(x))<<PDB_SC_PDBIE_SHIFT))&PDB_SC_PDBIE_MASK)
#define PDB_SC_PDBIF_MASK                        0x40u
#define PDB_SC_PDBIF_SHIFT                       6u
#define PDB_SC_PDBIF_WIDTH                       1u
#define PDB_SC_PDBIF(x)                          (((uint32)(((uint32)(x))<<PDB_SC_PDBIF_SHIFT))&PDB_SC_PDBIF_MASK)
#define PDB_SC_PDBEN_MASK                        0x80u
#define PDB_SC_PDBEN_SHIFT                       7u
#define PDB_SC_PDBEN_WIDTH                       1u
#define PDB_SC_PDBEN(x)                          (((uint32)(((uint32)(x))<<PDB_SC_PDBEN_SHIFT))&PDB_SC_PDBEN_MASK)
#define PDB_SC_TRGSEL_MASK                       0xF00u
#define PDB_SC_TRGSEL_SHIFT                      8u
#define PDB_SC_TRGSEL_WIDTH                      4u
#define PDB_SC_TRGSEL(x)                         (((uint32)(((uint32)(x))<<PDB_SC_TRGSEL_SHIFT))&PDB_SC_TRGSEL_MASK)
#define PDB_SC_PRESCALER_MASK                    0x7000u
#define PDB_SC_PRESCALER_SHIFT                   12u
#define PDB_SC_PRESCALER_WIDTH                   3u
#define PDB_SC_PRESCALER(x)                      (((uint32)(((uint32)(x))<<PDB_SC_PRESCALER_SHIFT))&PDB_SC_PRESCALER_MASK)
#define PDB_SC_DMAEN_MASK                        0x8000u
#define PDB_SC_DMAEN_SHIFT                       15u
#define PDB_SC_DMAEN_WIDTH                       1u
#define PDB_SC_DMAEN(x)                          (((uint32)(((uint32)(x))<<PDB_SC_DMAEN_SHIFT))&PDB_SC_DMAEN_MASK)
#define PDB_SC_SWTRIG_MASK                       0x10000u
#define PDB_SC_SWTRIG_SHIFT                      16u
#define PDB_SC_SWTRIG_WIDTH                      1u
#define PDB_SC_SWTRIG(x)                         (((uint32)(((uint32)(x))<<PDB_SC_SWTRIG_SHIFT))&PDB_SC_SWTRIG_MASK)
#define PDB_SC_PDBEIE_MASK                       0x20000u
#define PDB_SC_PDBEIE_SHIFT                      17u
#define PDB_SC_PDBEIE_WIDTH                      1u
#define PDB_SC_PDBEIE(x)                         (((uint32)(((uint32)(x))<<PDB_SC_PDBEIE_SHIFT))&PDB_SC_PDBEIE_MASK)
#define PDB_SC_LDMOD_MASK                        0xC0000u
#define PDB_SC_LDMOD_SHIFT                       18u
#define PDB_SC_LDMOD_WIDTH                       2u
#define PDB_SC_LDMOD(x)                          (((uint32)(((uint32)(x))<<PDB_SC_LDMOD_SHIFT))&PDB_SC_LDMOD_MASK)
/* MOD Bit Fields */
#define PDB_MOD_MOD_MASK                         0xFFFFu
#define PDB_MOD_MOD_SHIFT                        0u
#define PDB_MOD_MOD_WIDTH                        16u
#define PDB_MOD_MOD(x)                           (((uint32)(((uint32)(x))<<PDB_MOD_MOD_SHIFT))&PDB_MOD_MOD_MASK)
/* CNT Bit Fields */
#define PDB_CNT_CNT_MASK                         0xFFFFu
#define PDB_CNT_CNT_SHIFT                        0u
#define PDB_CNT_CNT_WIDTH                        16u
#define PDB_CNT_CNT(x)                           (((uint32)(((uint32)(x))<<PDB_CNT_CNT_SHIFT))&PDB_CNT_CNT_MASK)
/* IDLY Bit Fields */
#define PDB_IDLY_IDLY_MASK                       0xFFFFu
#define PDB_IDLY_IDLY_SHIFT                      0u
#define PDB_IDLY_IDLY_WIDTH                      16u
#define PDB_IDLY_IDLY(x)                         (((uint32)(((uint32)(x))<<PDB_IDLY_IDLY_SHIFT))&PDB_IDLY_IDLY_MASK)
/* C1 Bit Fields */
#define PDB_C1_EN_MASK                           0xFFu
#define PDB_C1_EN_SHIFT                          0u
#define PDB_C1_EN_WIDTH                          8u
#define PDB_C1_EN(x)                             (((uint32)(((uint32)(x))<<PDB_C1_EN_SHIFT))&PDB_C1_EN_MASK)
#define PDB_C1_TOS_MASK                          0xFF00u
#define PDB_C1_TOS_SHIFT                         8u
#define PDB_C1_TOS_WIDTH                         8u
#define PDB_C1_TOS(x)                            (((uint32)(((uint32)(x))<<PDB_C1_TOS_SHIFT))&PDB_C1_TOS_MASK)
#define PDB_C1_BB_MASK                           0xFF0000u
#define PDB_C1_BB_SHIFT                          16u
#define PDB_C1_BB_WIDTH                          8u
#define PDB_C1_BB(x)                             (((uint32)(((uint32)(x))<<PDB_C1_BB_SHIFT))&PDB_C1_BB_MASK)
/* S Bit Fields */
#define PDB_S_ERR_MASK                           0xFFu
#define PDB_S_ERR_SHIFT                          0u
#define PDB_S_ERR_WIDTH                          8u
#define PDB_S_ERR(x)                             (((uint32)(((uint32)(x))<<PDB_S_ERR_SHIFT))&PDB_S_ERR_MASK)
#define PDB_S_CF_MASK                            0xFF0000u
#define PDB_S_CF_SHIFT                           16u
#define PDB_S_CF_WIDTH                           8u
#define PDB_S_CF(x)                              (((uint32)(((uint32)(x))<<PDB_S_CF_SHIFT))&PDB_S_CF_MASK)
/* DLY Bit Fields */
#define PDB_DLY_DLY_MASK                         0xFFFFu
#define PDB_DLY_DLY_SHIFT                        0u
#define PDB_DLY_DLY_WIDTH                        16u
#define PDB_DLY_DLY(x)                           (((uint32)(((uint32)(x))<<PDB_DLY_DLY_SHIFT))&PDB_DLY_DLY_MASK)
/* POEN Bit Fields */
#define PDB_POEN_POEN_MASK                       0xFFu
#define PDB_POEN_POEN_SHIFT                      0u
#define PDB_POEN_POEN_WIDTH                      8u
#define PDB_POEN_POEN(x)                         (((uint32)(((uint32)(x))<<PDB_POEN_POEN_SHIFT))&PDB_POEN_POEN_MASK)
/* POnDLY_PODLY Bit Fields */
#define PDB_POnDLY_PODLY_DLY2_MASK               0xFFFFu
#define PDB_POnDLY_PODLY_DLY2_SHIFT              0u
#define PDB_POnDLY_PODLY_DLY2_WIDTH              16u
#define PDB_POnDLY_PODLY_DLY2(x)                 (((uint32)(((uint32)(x))<<PDB_POnDLY_PODLY_DLY2_SHIFT))&PDB_POnDLY_PODLY_DLY2_MASK)
#define PDB_POnDLY_PODLY_DLY1_MASK               0xFFFF0000u
#define PDB_POnDLY_PODLY_DLY1_SHIFT              16u
#define PDB_POnDLY_PODLY_DLY1_WIDTH              16u
#define PDB_POnDLY_PODLY_DLY1(x)                 (((uint32)(((uint32)(x))<<PDB_POnDLY_PODLY_DLY1_SHIFT))&PDB_POnDLY_PODLY_DLY1_MASK)
/* POnDLY_ACCESS16BIT_DLY2 Bit Fields */
#define PDB_POnDLY_ACCESS16BIT_DLY2_DLY2_MASK    0xFFFFu
#define PDB_POnDLY_ACCESS16BIT_DLY2_DLY2_SHIFT   0u
#define PDB_POnDLY_ACCESS16BIT_DLY2_DLY2_WIDTH   16u
#define PDB_POnDLY_ACCESS16BIT_DLY2_DLY2(x)      (((uint16)(((uint16)(x))<<PDB_POnDLY_ACCESS16BIT_DLY2_DLY2_SHIFT))&PDB_POnDLY_ACCESS16BIT_DLY2_DLY2_MASK)
/* POnDLY_ACCESS16BIT_DLY1 Bit Fields */
#define PDB_POnDLY_ACCESS16BIT_DLY1_DLY1_MASK    0xFFFFu
#define PDB_POnDLY_ACCESS16BIT_DLY1_DLY1_SHIFT   0u
#define PDB_POnDLY_ACCESS16BIT_DLY1_DLY1_WIDTH   16u
#define PDB_POnDLY_ACCESS16BIT_DLY1_DLY1(x)      (((uint16)(((uint16)(x))<<PDB_POnDLY_ACCESS16BIT_DLY1_DLY1_SHIFT))&PDB_POnDLY_ACCESS16BIT_DLY1_DLY1_MASK)

/*!
 * @}
 */ /* end of group PDB_Register_Masks */


/*!
 * @}
 */ /* end of group PDB_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Peripheral_Access_Layer PMC Peripheral Access Layer
 * @{
 */


/** PMC - Size of Registers Arrays */

/** PMC - Register Layout Typedef */
typedef struct {
  __IO uint8 LVDSC1;                             /**< Low Voltage Detect Status and Control 1 Register, offset: 0x0 */
  __IO uint8 LVDSC2;                             /**< Low Voltage Detect Status and Control 2 Register, offset: 0x1 */
  __IO uint8 REGSC;                              /**< Regulator Status and Control Register, offset: 0x2 */
       uint8 RESERVED_0[1];
  __IO uint8 LPOTRIM;                            /**< Low Power Oscillator Trim Register, offset: 0x4 */
} PMC_Type, *PMC_MemMapPtr;

 /** Number of instances of the PMC module. */
#define PMC_INSTANCE_COUNT                       (1u)


/* PMC - Peripheral instance base addresses */
/** Peripheral PMC base address */
#define PMC_BASE                                 (0x4007D000u)
/** Peripheral PMC base pointer */
#define PMC                                      ((PMC_Type *)PMC_BASE)
/** Array initializer of PMC peripheral base addresses */
#define PMC_BASE_ADDRS                           { PMC_BASE }
/** Array initializer of PMC peripheral base pointers */
#define PMC_BASE_PTRS                            { PMC }
 /** Number of interrupt vector arrays for the PMC module. */
#define PMC_IRQS_ARR_COUNT                       (1u)
 /** Number of interrupt channels for the PMC module. */
#define PMC_IRQS_CH_COUNT                        (1u)
/** Interrupt vectors for the PMC peripheral type */
#define PMC_IRQS                                 { LVD_LVW_IRQn }

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/* LVDSC1 Bit Fields */
#define PMC_LVDSC1_LVDRE_MASK                    0x10u
#define PMC_LVDSC1_LVDRE_SHIFT                   4u
#define PMC_LVDSC1_LVDRE_WIDTH                   1u
#define PMC_LVDSC1_LVDRE(x)                      (((uint8)(((uint8)(x))<<PMC_LVDSC1_LVDRE_SHIFT))&PMC_LVDSC1_LVDRE_MASK)
#define PMC_LVDSC1_LVDIE_MASK                    0x20u
#define PMC_LVDSC1_LVDIE_SHIFT                   5u
#define PMC_LVDSC1_LVDIE_WIDTH                   1u
#define PMC_LVDSC1_LVDIE(x)                      (((uint8)(((uint8)(x))<<PMC_LVDSC1_LVDIE_SHIFT))&PMC_LVDSC1_LVDIE_MASK)
#define PMC_LVDSC1_LVDACK_MASK                   0x40u
#define PMC_LVDSC1_LVDACK_SHIFT                  6u
#define PMC_LVDSC1_LVDACK_WIDTH                  1u
#define PMC_LVDSC1_LVDACK(x)                     (((uint8)(((uint8)(x))<<PMC_LVDSC1_LVDACK_SHIFT))&PMC_LVDSC1_LVDACK_MASK)
#define PMC_LVDSC1_LVDF_MASK                     0x80u
#define PMC_LVDSC1_LVDF_SHIFT                    7u
#define PMC_LVDSC1_LVDF_WIDTH                    1u
#define PMC_LVDSC1_LVDF(x)                       (((uint8)(((uint8)(x))<<PMC_LVDSC1_LVDF_SHIFT))&PMC_LVDSC1_LVDF_MASK)
/* LVDSC2 Bit Fields */
#define PMC_LVDSC2_LVWIE_MASK                    0x20u
#define PMC_LVDSC2_LVWIE_SHIFT                   5u
#define PMC_LVDSC2_LVWIE_WIDTH                   1u
#define PMC_LVDSC2_LVWIE(x)                      (((uint8)(((uint8)(x))<<PMC_LVDSC2_LVWIE_SHIFT))&PMC_LVDSC2_LVWIE_MASK)
#define PMC_LVDSC2_LVWACK_MASK                   0x40u
#define PMC_LVDSC2_LVWACK_SHIFT                  6u
#define PMC_LVDSC2_LVWACK_WIDTH                  1u
#define PMC_LVDSC2_LVWACK(x)                     (((uint8)(((uint8)(x))<<PMC_LVDSC2_LVWACK_SHIFT))&PMC_LVDSC2_LVWACK_MASK)
#define PMC_LVDSC2_LVWF_MASK                     0x80u
#define PMC_LVDSC2_LVWF_SHIFT                    7u
#define PMC_LVDSC2_LVWF_WIDTH                    1u
#define PMC_LVDSC2_LVWF(x)                       (((uint8)(((uint8)(x))<<PMC_LVDSC2_LVWF_SHIFT))&PMC_LVDSC2_LVWF_MASK)
/* REGSC Bit Fields */
#define PMC_REGSC_BIASEN_MASK                    0x1u
#define PMC_REGSC_BIASEN_SHIFT                   0u
#define PMC_REGSC_BIASEN_WIDTH                   1u
#define PMC_REGSC_BIASEN(x)                      (((uint8)(((uint8)(x))<<PMC_REGSC_BIASEN_SHIFT))&PMC_REGSC_BIASEN_MASK)
#define PMC_REGSC_CLKBIASDIS_MASK                0x2u
#define PMC_REGSC_CLKBIASDIS_SHIFT               1u
#define PMC_REGSC_CLKBIASDIS_WIDTH               1u
#define PMC_REGSC_CLKBIASDIS(x)                  (((uint8)(((uint8)(x))<<PMC_REGSC_CLKBIASDIS_SHIFT))&PMC_REGSC_CLKBIASDIS_MASK)
#define PMC_REGSC_REGFPM_MASK                    0x4u
#define PMC_REGSC_REGFPM_SHIFT                   2u
#define PMC_REGSC_REGFPM_WIDTH                   1u
#define PMC_REGSC_REGFPM(x)                      (((uint8)(((uint8)(x))<<PMC_REGSC_REGFPM_SHIFT))&PMC_REGSC_REGFPM_MASK)
#define PMC_REGSC_LPOSTAT_MASK                   0x40u
#define PMC_REGSC_LPOSTAT_SHIFT                  6u
#define PMC_REGSC_LPOSTAT_WIDTH                  1u
#define PMC_REGSC_LPOSTAT(x)                     (((uint8)(((uint8)(x))<<PMC_REGSC_LPOSTAT_SHIFT))&PMC_REGSC_LPOSTAT_MASK)
#define PMC_REGSC_LPODIS_MASK                    0x80u
#define PMC_REGSC_LPODIS_SHIFT                   7u
#define PMC_REGSC_LPODIS_WIDTH                   1u
#define PMC_REGSC_LPODIS(x)                      (((uint8)(((uint8)(x))<<PMC_REGSC_LPODIS_SHIFT))&PMC_REGSC_LPODIS_MASK)
/* LPOTRIM Bit Fields */
#define PMC_LPOTRIM_LPOTRIM_MASK                 0x1Fu
#define PMC_LPOTRIM_LPOTRIM_SHIFT                0u
#define PMC_LPOTRIM_LPOTRIM_WIDTH                5u
#define PMC_LPOTRIM_LPOTRIM(x)                   (((uint8)(((uint8)(x))<<PMC_LPOTRIM_LPOTRIM_SHIFT))&PMC_LPOTRIM_LPOTRIM_MASK)

/*!
 * @}
 */ /* end of group PMC_Register_Masks */


/*!
 * @}
 */ /* end of group PMC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PORT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Peripheral_Access_Layer PORT Peripheral Access Layer
 * @{
 */


/** PORT - Size of Registers Arrays */
#define PORT_PCR_COUNT                           32u

/** PORT - Register Layout Typedef */
typedef struct {
  __IO uint32 PCR[PORT_PCR_COUNT];               /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
  __O  uint32 GPCLR;                             /**< Global Pin Control Low Register, offset: 0x80 */
  __O  uint32 GPCHR;                             /**< Global Pin Control High Register, offset: 0x84 */
       uint8 RESERVED_0[24];
  __IO uint32 ISFR;                              /**< Interrupt Status Flag Register, offset: 0xA0 */
       uint8 RESERVED_1[28];
  __IO uint32 DFER;                              /**< Digital Filter Enable Register, offset: 0xC0 */
  __IO uint32 DFCR;                              /**< Digital Filter Clock Register, offset: 0xC4 */
  __IO uint32 DFWR;                              /**< Digital Filter Width Register, offset: 0xC8 */
} PORT_Type, *PORT_MemMapPtr;

 /** Number of instances of the PORT module. */
#define PORT_INSTANCE_COUNT                      (5u)


/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base address */
#define PORTA_BASE                               (0x40049000u)
/** Peripheral PORTA base pointer */
#define PORTA                                    ((PORT_Type *)PORTA_BASE)
/** Peripheral PORTB base address */
#define PORTB_BASE                               (0x4004A000u)
/** Peripheral PORTB base pointer */
#define PORTB                                    ((PORT_Type *)PORTB_BASE)
/** Peripheral PORTC base address */
#define PORTC_BASE                               (0x4004B000u)
/** Peripheral PORTC base pointer */
#define PORTC                                    ((PORT_Type *)PORTC_BASE)
/** Peripheral PORTD base address */
#define PORTD_BASE                               (0x4004C000u)
/** Peripheral PORTD base pointer */
#define PORTD                                    ((PORT_Type *)PORTD_BASE)
/** Peripheral PORTE base address */
#define PORTE_BASE                               (0x4004D000u)
/** Peripheral PORTE base pointer */
#define PORTE                                    ((PORT_Type *)PORTE_BASE)
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORTA_BASE, PORTB_BASE, PORTC_BASE, PORTD_BASE, PORTE_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORTA, PORTB, PORTC, PORTD, PORTE }
 /** Number of interrupt vector arrays for the PORT module. */
#define PORT_IRQS_ARR_COUNT                      (1u)
 /** Number of interrupt channels for the PORT module. */
#define PORT_IRQS_CH_COUNT                       (1u)
/** Interrupt vectors for the PORT peripheral type */
#define PORT_IRQS                                { PORTA_IRQn, PORTB_IRQn, PORTC_IRQn, PORTD_IRQn, PORTE_IRQn }

/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Masks PORT Register Masks
 * @{
 */

/* PCR Bit Fields */
#define PORT_PCR_PS_MASK                         0x1u
#define PORT_PCR_PS_SHIFT                        0u
#define PORT_PCR_PS_WIDTH                        1u
#define PORT_PCR_PS(x)                           (((uint32)(((uint32)(x))<<PORT_PCR_PS_SHIFT))&PORT_PCR_PS_MASK)
#define PORT_PCR_PE_MASK                         0x2u
#define PORT_PCR_PE_SHIFT                        1u
#define PORT_PCR_PE_WIDTH                        1u
#define PORT_PCR_PE(x)                           (((uint32)(((uint32)(x))<<PORT_PCR_PE_SHIFT))&PORT_PCR_PE_MASK)
#define PORT_PCR_PFE_MASK                        0x10u
#define PORT_PCR_PFE_SHIFT                       4u
#define PORT_PCR_PFE_WIDTH                       1u
#define PORT_PCR_PFE(x)                          (((uint32)(((uint32)(x))<<PORT_PCR_PFE_SHIFT))&PORT_PCR_PFE_MASK)
#define PORT_PCR_DSE_MASK                        0x40u
#define PORT_PCR_DSE_SHIFT                       6u
#define PORT_PCR_DSE_WIDTH                       1u
#define PORT_PCR_DSE(x)                          (((uint32)(((uint32)(x))<<PORT_PCR_DSE_SHIFT))&PORT_PCR_DSE_MASK)
#define PORT_PCR_MUX_MASK                        0x700u
#define PORT_PCR_MUX_SHIFT                       8u
#define PORT_PCR_MUX_WIDTH                       3u
#define PORT_PCR_MUX(x)                          (((uint32)(((uint32)(x))<<PORT_PCR_MUX_SHIFT))&PORT_PCR_MUX_MASK)
#define PORT_PCR_LK_MASK                         0x8000u
#define PORT_PCR_LK_SHIFT                        15u
#define PORT_PCR_LK_WIDTH                        1u
#define PORT_PCR_LK(x)                           (((uint32)(((uint32)(x))<<PORT_PCR_LK_SHIFT))&PORT_PCR_LK_MASK)
#define PORT_PCR_IRQC_MASK                       0xF0000u
#define PORT_PCR_IRQC_SHIFT                      16u
#define PORT_PCR_IRQC_WIDTH                      4u
#define PORT_PCR_IRQC(x)                         (((uint32)(((uint32)(x))<<PORT_PCR_IRQC_SHIFT))&PORT_PCR_IRQC_MASK)
#define PORT_PCR_ISF_MASK                        0x1000000u
#define PORT_PCR_ISF_SHIFT                       24u
#define PORT_PCR_ISF_WIDTH                       1u
#define PORT_PCR_ISF(x)                          (((uint32)(((uint32)(x))<<PORT_PCR_ISF_SHIFT))&PORT_PCR_ISF_MASK)
/* GPCLR Bit Fields */
#define PORT_GPCLR_GPWD_MASK                     0xFFFFu
#define PORT_GPCLR_GPWD_SHIFT                    0u
#define PORT_GPCLR_GPWD_WIDTH                    16u
#define PORT_GPCLR_GPWD(x)                       (((uint32)(((uint32)(x))<<PORT_GPCLR_GPWD_SHIFT))&PORT_GPCLR_GPWD_MASK)
#define PORT_GPCLR_GPWE_MASK                     0xFFFF0000u
#define PORT_GPCLR_GPWE_SHIFT                    16u
#define PORT_GPCLR_GPWE_WIDTH                    16u
#define PORT_GPCLR_GPWE(x)                       (((uint32)(((uint32)(x))<<PORT_GPCLR_GPWE_SHIFT))&PORT_GPCLR_GPWE_MASK)
/* GPCHR Bit Fields */
#define PORT_GPCHR_GPWD_MASK                     0xFFFFu
#define PORT_GPCHR_GPWD_SHIFT                    0u
#define PORT_GPCHR_GPWD_WIDTH                    16u
#define PORT_GPCHR_GPWD(x)                       (((uint32)(((uint32)(x))<<PORT_GPCHR_GPWD_SHIFT))&PORT_GPCHR_GPWD_MASK)
#define PORT_GPCHR_GPWE_MASK                     0xFFFF0000u
#define PORT_GPCHR_GPWE_SHIFT                    16u
#define PORT_GPCHR_GPWE_WIDTH                    16u
#define PORT_GPCHR_GPWE(x)                       (((uint32)(((uint32)(x))<<PORT_GPCHR_GPWE_SHIFT))&PORT_GPCHR_GPWE_MASK)
/* ISFR Bit Fields */
#define PORT_ISFR_ISF_MASK                       0xFFFFFFFFu
#define PORT_ISFR_ISF_SHIFT                      0u
#define PORT_ISFR_ISF_WIDTH                      32u
#define PORT_ISFR_ISF(x)                         (((uint32)(((uint32)(x))<<PORT_ISFR_ISF_SHIFT))&PORT_ISFR_ISF_MASK)
/* DFER Bit Fields */
#define PORT_DFER_DFE_MASK                       0xFFFFFFFFu
#define PORT_DFER_DFE_SHIFT                      0u
#define PORT_DFER_DFE_WIDTH                      32u
#define PORT_DFER_DFE(x)                         (((uint32)(((uint32)(x))<<PORT_DFER_DFE_SHIFT))&PORT_DFER_DFE_MASK)
/* DFCR Bit Fields */
#define PORT_DFCR_CS_MASK                        0x1u
#define PORT_DFCR_CS_SHIFT                       0u
#define PORT_DFCR_CS_WIDTH                       1u
#define PORT_DFCR_CS(x)                          (((uint32)(((uint32)(x))<<PORT_DFCR_CS_SHIFT))&PORT_DFCR_CS_MASK)
/* DFWR Bit Fields */
#define PORT_DFWR_FILT_MASK                      0x1Fu
#define PORT_DFWR_FILT_SHIFT                     0u
#define PORT_DFWR_FILT_WIDTH                     5u
#define PORT_DFWR_FILT(x)                        (((uint32)(((uint32)(x))<<PORT_DFWR_FILT_SHIFT))&PORT_DFWR_FILT_MASK)

/*!
 * @}
 */ /* end of group PORT_Register_Masks */


/*!
 * @}
 */ /* end of group PORT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Peripheral_Access_Layer RCM Peripheral Access Layer
 * @{
 */


/** RCM - Size of Registers Arrays */

/** RCM - Register Layout Typedef */
typedef struct {
  __I  uint32 VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32 PARAM;                             /**< Parameter Register, offset: 0x4 */
  __I  uint32 SRS;                               /**< System Reset Status Register, offset: 0x8 */
  __IO uint32 RPC;                               /**< Reset Pin Control register, offset: 0xC */
       uint8 RESERVED_0[8];
  __IO uint32 SSRS;                              /**< Sticky System Reset Status Register, offset: 0x18 */
  __IO uint32 SRIE;                              /**< System Reset Interrupt Enable Register, offset: 0x1C */
} RCM_Type, *RCM_MemMapPtr;

 /** Number of instances of the RCM module. */
#define RCM_INSTANCE_COUNT                       (1u)


/* RCM - Peripheral instance base addresses */
/** Peripheral RCM base address */
#define RCM_BASE                                 (0x4007F000u)
/** Peripheral RCM base pointer */
#define RCM                                      ((RCM_Type *)RCM_BASE)
/** Array initializer of RCM peripheral base addresses */
#define RCM_BASE_ADDRS                           { RCM_BASE }
/** Array initializer of RCM peripheral base pointers */
#define RCM_BASE_PTRS                            { RCM }
 /** Number of interrupt vector arrays for the RCM module. */
#define RCM_IRQS_ARR_COUNT                       (1u)
 /** Number of interrupt channels for the RCM module. */
#define RCM_IRQS_CH_COUNT                        (1u)
/** Interrupt vectors for the RCM peripheral type */
#define RCM_IRQS                                 { RCM_IRQn }

/* ----------------------------------------------------------------------------
   -- RCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Register_Masks RCM Register Masks
 * @{
 */

/* VERID Bit Fields */
#define RCM_VERID_FEATURE_MASK                   0xFFFFu
#define RCM_VERID_FEATURE_SHIFT                  0u
#define RCM_VERID_FEATURE_WIDTH                  16u
#define RCM_VERID_FEATURE(x)                     (((uint32)(((uint32)(x))<<RCM_VERID_FEATURE_SHIFT))&RCM_VERID_FEATURE_MASK)
#define RCM_VERID_MINOR_MASK                     0xFF0000u
#define RCM_VERID_MINOR_SHIFT                    16u
#define RCM_VERID_MINOR_WIDTH                    8u
#define RCM_VERID_MINOR(x)                       (((uint32)(((uint32)(x))<<RCM_VERID_MINOR_SHIFT))&RCM_VERID_MINOR_MASK)
#define RCM_VERID_MAJOR_MASK                     0xFF000000u
#define RCM_VERID_MAJOR_SHIFT                    24u
#define RCM_VERID_MAJOR_WIDTH                    8u
#define RCM_VERID_MAJOR(x)                       (((uint32)(((uint32)(x))<<RCM_VERID_MAJOR_SHIFT))&RCM_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define RCM_PARAM_EWAKEUP_MASK                   0x1u
#define RCM_PARAM_EWAKEUP_SHIFT                  0u
#define RCM_PARAM_EWAKEUP_WIDTH                  1u
#define RCM_PARAM_EWAKEUP(x)                     (((uint32)(((uint32)(x))<<RCM_PARAM_EWAKEUP_SHIFT))&RCM_PARAM_EWAKEUP_MASK)
#define RCM_PARAM_ELVD_MASK                      0x2u
#define RCM_PARAM_ELVD_SHIFT                     1u
#define RCM_PARAM_ELVD_WIDTH                     1u
#define RCM_PARAM_ELVD(x)                        (((uint32)(((uint32)(x))<<RCM_PARAM_ELVD_SHIFT))&RCM_PARAM_ELVD_MASK)
#define RCM_PARAM_ELOC_MASK                      0x4u
#define RCM_PARAM_ELOC_SHIFT                     2u
#define RCM_PARAM_ELOC_WIDTH                     1u
#define RCM_PARAM_ELOC(x)                        (((uint32)(((uint32)(x))<<RCM_PARAM_ELOC_SHIFT))&RCM_PARAM_ELOC_MASK)
#define RCM_PARAM_ELOL_MASK                      0x8u
#define RCM_PARAM_ELOL_SHIFT                     3u
#define RCM_PARAM_ELOL_WIDTH                     1u
#define RCM_PARAM_ELOL(x)                        (((uint32)(((uint32)(x))<<RCM_PARAM_ELOL_SHIFT))&RCM_PARAM_ELOL_MASK)
#define RCM_PARAM_EWDOG_MASK                     0x20u
#define RCM_PARAM_EWDOG_SHIFT                    5u
#define RCM_PARAM_EWDOG_WIDTH                    1u
#define RCM_PARAM_EWDOG(x)                       (((uint32)(((uint32)(x))<<RCM_PARAM_EWDOG_SHIFT))&RCM_PARAM_EWDOG_MASK)
#define RCM_PARAM_EPIN_MASK                      0x40u
#define RCM_PARAM_EPIN_SHIFT                     6u
#define RCM_PARAM_EPIN_WIDTH                     1u
#define RCM_PARAM_EPIN(x)                        (((uint32)(((uint32)(x))<<RCM_PARAM_EPIN_SHIFT))&RCM_PARAM_EPIN_MASK)
#define RCM_PARAM_EPOR_MASK                      0x80u
#define RCM_PARAM_EPOR_SHIFT                     7u
#define RCM_PARAM_EPOR_WIDTH                     1u
#define RCM_PARAM_EPOR(x)                        (((uint32)(((uint32)(x))<<RCM_PARAM_EPOR_SHIFT))&RCM_PARAM_EPOR_MASK)
#define RCM_PARAM_EJTAG_MASK                     0x100u
#define RCM_PARAM_EJTAG_SHIFT                    8u
#define RCM_PARAM_EJTAG_WIDTH                    1u
#define RCM_PARAM_EJTAG(x)                       (((uint32)(((uint32)(x))<<RCM_PARAM_EJTAG_SHIFT))&RCM_PARAM_EJTAG_MASK)
#define RCM_PARAM_ELOCKUP_MASK                   0x200u
#define RCM_PARAM_ELOCKUP_SHIFT                  9u
#define RCM_PARAM_ELOCKUP_WIDTH                  1u
#define RCM_PARAM_ELOCKUP(x)                     (((uint32)(((uint32)(x))<<RCM_PARAM_ELOCKUP_SHIFT))&RCM_PARAM_ELOCKUP_MASK)
#define RCM_PARAM_ESW_MASK                       0x400u
#define RCM_PARAM_ESW_SHIFT                      10u
#define RCM_PARAM_ESW_WIDTH                      1u
#define RCM_PARAM_ESW(x)                         (((uint32)(((uint32)(x))<<RCM_PARAM_ESW_SHIFT))&RCM_PARAM_ESW_MASK)
#define RCM_PARAM_EMDM_AP_MASK                   0x800u
#define RCM_PARAM_EMDM_AP_SHIFT                  11u
#define RCM_PARAM_EMDM_AP_WIDTH                  1u
#define RCM_PARAM_EMDM_AP(x)                     (((uint32)(((uint32)(x))<<RCM_PARAM_EMDM_AP_SHIFT))&RCM_PARAM_EMDM_AP_MASK)
#define RCM_PARAM_ESACKERR_MASK                  0x2000u
#define RCM_PARAM_ESACKERR_SHIFT                 13u
#define RCM_PARAM_ESACKERR_WIDTH                 1u
#define RCM_PARAM_ESACKERR(x)                    (((uint32)(((uint32)(x))<<RCM_PARAM_ESACKERR_SHIFT))&RCM_PARAM_ESACKERR_MASK)
#define RCM_PARAM_ETAMPER_MASK                   0x8000u
#define RCM_PARAM_ETAMPER_SHIFT                  15u
#define RCM_PARAM_ETAMPER_WIDTH                  1u
#define RCM_PARAM_ETAMPER(x)                     (((uint32)(((uint32)(x))<<RCM_PARAM_ETAMPER_SHIFT))&RCM_PARAM_ETAMPER_MASK)
#define RCM_PARAM_ECORE1_MASK                    0x10000u
#define RCM_PARAM_ECORE1_SHIFT                   16u
#define RCM_PARAM_ECORE1_WIDTH                   1u
#define RCM_PARAM_ECORE1(x)                      (((uint32)(((uint32)(x))<<RCM_PARAM_ECORE1_SHIFT))&RCM_PARAM_ECORE1_MASK)
/* SRS Bit Fields */
#define RCM_SRS_LVD_MASK                         0x2u
#define RCM_SRS_LVD_SHIFT                        1u
#define RCM_SRS_LVD_WIDTH                        1u
#define RCM_SRS_LVD(x)                           (((uint32)(((uint32)(x))<<RCM_SRS_LVD_SHIFT))&RCM_SRS_LVD_MASK)
#define RCM_SRS_LOC_MASK                         0x4u
#define RCM_SRS_LOC_SHIFT                        2u
#define RCM_SRS_LOC_WIDTH                        1u
#define RCM_SRS_LOC(x)                           (((uint32)(((uint32)(x))<<RCM_SRS_LOC_SHIFT))&RCM_SRS_LOC_MASK)
#define RCM_SRS_LOL_MASK                         0x8u
#define RCM_SRS_LOL_SHIFT                        3u
#define RCM_SRS_LOL_WIDTH                        1u
#define RCM_SRS_LOL(x)                           (((uint32)(((uint32)(x))<<RCM_SRS_LOL_SHIFT))&RCM_SRS_LOL_MASK)
#define RCM_SRS_WDOG_MASK                        0x20u
#define RCM_SRS_WDOG_SHIFT                       5u
#define RCM_SRS_WDOG_WIDTH                       1u
#define RCM_SRS_WDOG(x)                          (((uint32)(((uint32)(x))<<RCM_SRS_WDOG_SHIFT))&RCM_SRS_WDOG_MASK)
#define RCM_SRS_PIN_MASK                         0x40u
#define RCM_SRS_PIN_SHIFT                        6u
#define RCM_SRS_PIN_WIDTH                        1u
#define RCM_SRS_PIN(x)                           (((uint32)(((uint32)(x))<<RCM_SRS_PIN_SHIFT))&RCM_SRS_PIN_MASK)
#define RCM_SRS_POR_MASK                         0x80u
#define RCM_SRS_POR_SHIFT                        7u
#define RCM_SRS_POR_WIDTH                        1u
#define RCM_SRS_POR(x)                           (((uint32)(((uint32)(x))<<RCM_SRS_POR_SHIFT))&RCM_SRS_POR_MASK)
#define RCM_SRS_JTAG_MASK                        0x100u
#define RCM_SRS_JTAG_SHIFT                       8u
#define RCM_SRS_JTAG_WIDTH                       1u
#define RCM_SRS_JTAG(x)                          (((uint32)(((uint32)(x))<<RCM_SRS_JTAG_SHIFT))&RCM_SRS_JTAG_MASK)
#define RCM_SRS_LOCKUP_MASK                      0x200u
#define RCM_SRS_LOCKUP_SHIFT                     9u
#define RCM_SRS_LOCKUP_WIDTH                     1u
#define RCM_SRS_LOCKUP(x)                        (((uint32)(((uint32)(x))<<RCM_SRS_LOCKUP_SHIFT))&RCM_SRS_LOCKUP_MASK)
#define RCM_SRS_SW_MASK                          0x400u
#define RCM_SRS_SW_SHIFT                         10u
#define RCM_SRS_SW_WIDTH                         1u
#define RCM_SRS_SW(x)                            (((uint32)(((uint32)(x))<<RCM_SRS_SW_SHIFT))&RCM_SRS_SW_MASK)
#define RCM_SRS_MDM_AP_MASK                      0x800u
#define RCM_SRS_MDM_AP_SHIFT                     11u
#define RCM_SRS_MDM_AP_WIDTH                     1u
#define RCM_SRS_MDM_AP(x)                        (((uint32)(((uint32)(x))<<RCM_SRS_MDM_AP_SHIFT))&RCM_SRS_MDM_AP_MASK)
#define RCM_SRS_SACKERR_MASK                     0x2000u
#define RCM_SRS_SACKERR_SHIFT                    13u
#define RCM_SRS_SACKERR_WIDTH                    1u
#define RCM_SRS_SACKERR(x)                       (((uint32)(((uint32)(x))<<RCM_SRS_SACKERR_SHIFT))&RCM_SRS_SACKERR_MASK)
/* RPC Bit Fields */
#define RCM_RPC_RSTFLTSRW_MASK                   0x3u
#define RCM_RPC_RSTFLTSRW_SHIFT                  0u
#define RCM_RPC_RSTFLTSRW_WIDTH                  2u
#define RCM_RPC_RSTFLTSRW(x)                     (((uint32)(((uint32)(x))<<RCM_RPC_RSTFLTSRW_SHIFT))&RCM_RPC_RSTFLTSRW_MASK)
#define RCM_RPC_RSTFLTSS_MASK                    0x4u
#define RCM_RPC_RSTFLTSS_SHIFT                   2u
#define RCM_RPC_RSTFLTSS_WIDTH                   1u
#define RCM_RPC_RSTFLTSS(x)                      (((uint32)(((uint32)(x))<<RCM_RPC_RSTFLTSS_SHIFT))&RCM_RPC_RSTFLTSS_MASK)
#define RCM_RPC_RSTFLTSEL_MASK                   0x1F00u
#define RCM_RPC_RSTFLTSEL_SHIFT                  8u
#define RCM_RPC_RSTFLTSEL_WIDTH                  5u
#define RCM_RPC_RSTFLTSEL(x)                     (((uint32)(((uint32)(x))<<RCM_RPC_RSTFLTSEL_SHIFT))&RCM_RPC_RSTFLTSEL_MASK)
/* SSRS Bit Fields */
#define RCM_SSRS_SLVD_MASK                       0x2u
#define RCM_SSRS_SLVD_SHIFT                      1u
#define RCM_SSRS_SLVD_WIDTH                      1u
#define RCM_SSRS_SLVD(x)                         (((uint32)(((uint32)(x))<<RCM_SSRS_SLVD_SHIFT))&RCM_SSRS_SLVD_MASK)
#define RCM_SSRS_SLOC_MASK                       0x4u
#define RCM_SSRS_SLOC_SHIFT                      2u
#define RCM_SSRS_SLOC_WIDTH                      1u
#define RCM_SSRS_SLOC(x)                         (((uint32)(((uint32)(x))<<RCM_SSRS_SLOC_SHIFT))&RCM_SSRS_SLOC_MASK)
#define RCM_SSRS_SLOL_MASK                       0x8u
#define RCM_SSRS_SLOL_SHIFT                      3u
#define RCM_SSRS_SLOL_WIDTH                      1u
#define RCM_SSRS_SLOL(x)                         (((uint32)(((uint32)(x))<<RCM_SSRS_SLOL_SHIFT))&RCM_SSRS_SLOL_MASK)
#define RCM_SSRS_SWDOG_MASK                      0x20u
#define RCM_SSRS_SWDOG_SHIFT                     5u
#define RCM_SSRS_SWDOG_WIDTH                     1u
#define RCM_SSRS_SWDOG(x)                        (((uint32)(((uint32)(x))<<RCM_SSRS_SWDOG_SHIFT))&RCM_SSRS_SWDOG_MASK)
#define RCM_SSRS_SPIN_MASK                       0x40u
#define RCM_SSRS_SPIN_SHIFT                      6u
#define RCM_SSRS_SPIN_WIDTH                      1u
#define RCM_SSRS_SPIN(x)                         (((uint32)(((uint32)(x))<<RCM_SSRS_SPIN_SHIFT))&RCM_SSRS_SPIN_MASK)
#define RCM_SSRS_SPOR_MASK                       0x80u
#define RCM_SSRS_SPOR_SHIFT                      7u
#define RCM_SSRS_SPOR_WIDTH                      1u
#define RCM_SSRS_SPOR(x)                         (((uint32)(((uint32)(x))<<RCM_SSRS_SPOR_SHIFT))&RCM_SSRS_SPOR_MASK)
#define RCM_SSRS_SJTAG_MASK                      0x100u
#define RCM_SSRS_SJTAG_SHIFT                     8u
#define RCM_SSRS_SJTAG_WIDTH                     1u
#define RCM_SSRS_SJTAG(x)                        (((uint32)(((uint32)(x))<<RCM_SSRS_SJTAG_SHIFT))&RCM_SSRS_SJTAG_MASK)
#define RCM_SSRS_SLOCKUP_MASK                    0x200u
#define RCM_SSRS_SLOCKUP_SHIFT                   9u
#define RCM_SSRS_SLOCKUP_WIDTH                   1u
#define RCM_SSRS_SLOCKUP(x)                      (((uint32)(((uint32)(x))<<RCM_SSRS_SLOCKUP_SHIFT))&RCM_SSRS_SLOCKUP_MASK)
#define RCM_SSRS_SSW_MASK                        0x400u
#define RCM_SSRS_SSW_SHIFT                       10u
#define RCM_SSRS_SSW_WIDTH                       1u
#define RCM_SSRS_SSW(x)                          (((uint32)(((uint32)(x))<<RCM_SSRS_SSW_SHIFT))&RCM_SSRS_SSW_MASK)
#define RCM_SSRS_SMDM_AP_MASK                    0x800u
#define RCM_SSRS_SMDM_AP_SHIFT                   11u
#define RCM_SSRS_SMDM_AP_WIDTH                   1u
#define RCM_SSRS_SMDM_AP(x)                      (((uint32)(((uint32)(x))<<RCM_SSRS_SMDM_AP_SHIFT))&RCM_SSRS_SMDM_AP_MASK)
#define RCM_SSRS_SSACKERR_MASK                   0x2000u
#define RCM_SSRS_SSACKERR_SHIFT                  13u
#define RCM_SSRS_SSACKERR_WIDTH                  1u
#define RCM_SSRS_SSACKERR(x)                     (((uint32)(((uint32)(x))<<RCM_SSRS_SSACKERR_SHIFT))&RCM_SSRS_SSACKERR_MASK)
/* SRIE Bit Fields */
#define RCM_SRIE_DELAY_MASK                      0x3u
#define RCM_SRIE_DELAY_SHIFT                     0u
#define RCM_SRIE_DELAY_WIDTH                     2u
#define RCM_SRIE_DELAY(x)                        (((uint32)(((uint32)(x))<<RCM_SRIE_DELAY_SHIFT))&RCM_SRIE_DELAY_MASK)
#define RCM_SRIE_LOC_MASK                        0x4u
#define RCM_SRIE_LOC_SHIFT                       2u
#define RCM_SRIE_LOC_WIDTH                       1u
#define RCM_SRIE_LOC(x)                          (((uint32)(((uint32)(x))<<RCM_SRIE_LOC_SHIFT))&RCM_SRIE_LOC_MASK)
#define RCM_SRIE_LOL_MASK                        0x8u
#define RCM_SRIE_LOL_SHIFT                       3u
#define RCM_SRIE_LOL_WIDTH                       1u
#define RCM_SRIE_LOL(x)                          (((uint32)(((uint32)(x))<<RCM_SRIE_LOL_SHIFT))&RCM_SRIE_LOL_MASK)
#define RCM_SRIE_WDOG_MASK                       0x20u
#define RCM_SRIE_WDOG_SHIFT                      5u
#define RCM_SRIE_WDOG_WIDTH                      1u
#define RCM_SRIE_WDOG(x)                         (((uint32)(((uint32)(x))<<RCM_SRIE_WDOG_SHIFT))&RCM_SRIE_WDOG_MASK)
#define RCM_SRIE_PIN_MASK                        0x40u
#define RCM_SRIE_PIN_SHIFT                       6u
#define RCM_SRIE_PIN_WIDTH                       1u
#define RCM_SRIE_PIN(x)                          (((uint32)(((uint32)(x))<<RCM_SRIE_PIN_SHIFT))&RCM_SRIE_PIN_MASK)
#define RCM_SRIE_GIE_MASK                        0x80u
#define RCM_SRIE_GIE_SHIFT                       7u
#define RCM_SRIE_GIE_WIDTH                       1u
#define RCM_SRIE_GIE(x)                          (((uint32)(((uint32)(x))<<RCM_SRIE_GIE_SHIFT))&RCM_SRIE_GIE_MASK)
#define RCM_SRIE_JTAG_MASK                       0x100u
#define RCM_SRIE_JTAG_SHIFT                      8u
#define RCM_SRIE_JTAG_WIDTH                      1u
#define RCM_SRIE_JTAG(x)                         (((uint32)(((uint32)(x))<<RCM_SRIE_JTAG_SHIFT))&RCM_SRIE_JTAG_MASK)
#define RCM_SRIE_LOCKUP_MASK                     0x200u
#define RCM_SRIE_LOCKUP_SHIFT                    9u
#define RCM_SRIE_LOCKUP_WIDTH                    1u
#define RCM_SRIE_LOCKUP(x)                       (((uint32)(((uint32)(x))<<RCM_SRIE_LOCKUP_SHIFT))&RCM_SRIE_LOCKUP_MASK)
#define RCM_SRIE_SW_MASK                         0x400u
#define RCM_SRIE_SW_SHIFT                        10u
#define RCM_SRIE_SW_WIDTH                        1u
#define RCM_SRIE_SW(x)                           (((uint32)(((uint32)(x))<<RCM_SRIE_SW_SHIFT))&RCM_SRIE_SW_MASK)
#define RCM_SRIE_MDM_AP_MASK                     0x800u
#define RCM_SRIE_MDM_AP_SHIFT                    11u
#define RCM_SRIE_MDM_AP_WIDTH                    1u
#define RCM_SRIE_MDM_AP(x)                       (((uint32)(((uint32)(x))<<RCM_SRIE_MDM_AP_SHIFT))&RCM_SRIE_MDM_AP_MASK)
#define RCM_SRIE_SACKERR_MASK                    0x2000u
#define RCM_SRIE_SACKERR_SHIFT                   13u
#define RCM_SRIE_SACKERR_WIDTH                   1u
#define RCM_SRIE_SACKERR(x)                      (((uint32)(((uint32)(x))<<RCM_SRIE_SACKERR_SHIFT))&RCM_SRIE_SACKERR_MASK)

/*!
 * @}
 */ /* end of group RCM_Register_Masks */


/*!
 * @}
 */ /* end of group RCM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Peripheral_Access_Layer RTC Peripheral Access Layer
 * @{
 */


/** RTC - Size of Registers Arrays */

/** RTC - Register Layout Typedef */
typedef struct {
  __IO uint32 TSR;                               /**< RTC Time Seconds Register, offset: 0x0 */
  __IO uint32 TPR;                               /**< RTC Time Prescaler Register, offset: 0x4 */
  __IO uint32 TAR;                               /**< RTC Time Alarm Register, offset: 0x8 */
  __IO uint32 TCR;                               /**< RTC Time Compensation Register, offset: 0xC */
  __IO uint32 CR;                                /**< RTC Control Register, offset: 0x10 */
  __IO uint32 SR;                                /**< RTC Status Register, offset: 0x14 */
  __IO uint32 LR;                                /**< RTC Lock Register, offset: 0x18 */
  __IO uint32 IER;                               /**< RTC Interrupt Enable Register, offset: 0x1C */
} RTC_Type, *RTC_MemMapPtr;

 /** Number of instances of the RTC module. */
#define RTC_INSTANCE_COUNT                       (1u)


/* RTC - Peripheral instance base addresses */
/** Peripheral RTC base address */
#define RTC_BASE                                 (0x4003D000u)
/** Peripheral RTC base pointer */
#define RTC                                      ((RTC_Type *)RTC_BASE)
/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                           { RTC_BASE }
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            { RTC }
 /** Number of interrupt vector arrays for the RTC module. */
#define RTC_IRQS_ARR_COUNT                       (2u)
 /** Number of interrupt channels for the RTC module. */
#define RTC_IRQS_CH_COUNT                        (1u)
 /** Number of interrupt channels for the SECONDS type of RTC module. */
#define RTC_SECONDS_IRQS_CH_COUNT                (1u)
/** Interrupt vectors for the RTC peripheral type */
#define RTC_IRQS                                 { RTC_IRQn }
#define RTC_SECONDS_IRQS                         { RTC_Seconds_IRQn }

/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Masks RTC Register Masks
 * @{
 */

/* TSR Bit Fields */
#define RTC_TSR_TSR_MASK                         0xFFFFFFFFu
#define RTC_TSR_TSR_SHIFT                        0u
#define RTC_TSR_TSR_WIDTH                        32u
#define RTC_TSR_TSR(x)                           (((uint32)(((uint32)(x))<<RTC_TSR_TSR_SHIFT))&RTC_TSR_TSR_MASK)
/* TPR Bit Fields */
#define RTC_TPR_TPR_MASK                         0xFFFFu
#define RTC_TPR_TPR_SHIFT                        0u
#define RTC_TPR_TPR_WIDTH                        16u
#define RTC_TPR_TPR(x)                           (((uint32)(((uint32)(x))<<RTC_TPR_TPR_SHIFT))&RTC_TPR_TPR_MASK)
/* TAR Bit Fields */
#define RTC_TAR_TAR_MASK                         0xFFFFFFFFu
#define RTC_TAR_TAR_SHIFT                        0u
#define RTC_TAR_TAR_WIDTH                        32u
#define RTC_TAR_TAR(x)                           (((uint32)(((uint32)(x))<<RTC_TAR_TAR_SHIFT))&RTC_TAR_TAR_MASK)
/* TCR Bit Fields */
#define RTC_TCR_TCR_MASK                         0xFFu
#define RTC_TCR_TCR_SHIFT                        0u
#define RTC_TCR_TCR_WIDTH                        8u
#define RTC_TCR_TCR(x)                           (((uint32)(((uint32)(x))<<RTC_TCR_TCR_SHIFT))&RTC_TCR_TCR_MASK)
#define RTC_TCR_CIR_MASK                         0xFF00u
#define RTC_TCR_CIR_SHIFT                        8u
#define RTC_TCR_CIR_WIDTH                        8u
#define RTC_TCR_CIR(x)                           (((uint32)(((uint32)(x))<<RTC_TCR_CIR_SHIFT))&RTC_TCR_CIR_MASK)
#define RTC_TCR_TCV_MASK                         0xFF0000u
#define RTC_TCR_TCV_SHIFT                        16u
#define RTC_TCR_TCV_WIDTH                        8u
#define RTC_TCR_TCV(x)                           (((uint32)(((uint32)(x))<<RTC_TCR_TCV_SHIFT))&RTC_TCR_TCV_MASK)
#define RTC_TCR_CIC_MASK                         0xFF000000u
#define RTC_TCR_CIC_SHIFT                        24u
#define RTC_TCR_CIC_WIDTH                        8u
#define RTC_TCR_CIC(x)                           (((uint32)(((uint32)(x))<<RTC_TCR_CIC_SHIFT))&RTC_TCR_CIC_MASK)
/* CR Bit Fields */
#define RTC_CR_SWR_MASK                          0x1u
#define RTC_CR_SWR_SHIFT                         0u
#define RTC_CR_SWR_WIDTH                         1u
#define RTC_CR_SWR(x)                            (((uint32)(((uint32)(x))<<RTC_CR_SWR_SHIFT))&RTC_CR_SWR_MASK)
#define RTC_CR_SUP_MASK                          0x4u
#define RTC_CR_SUP_SHIFT                         2u
#define RTC_CR_SUP_WIDTH                         1u
#define RTC_CR_SUP(x)                            (((uint32)(((uint32)(x))<<RTC_CR_SUP_SHIFT))&RTC_CR_SUP_MASK)
#define RTC_CR_UM_MASK                           0x8u
#define RTC_CR_UM_SHIFT                          3u
#define RTC_CR_UM_WIDTH                          1u
#define RTC_CR_UM(x)                             (((uint32)(((uint32)(x))<<RTC_CR_UM_SHIFT))&RTC_CR_UM_MASK)
#define RTC_CR_CPS_MASK                          0x20u
#define RTC_CR_CPS_SHIFT                         5u
#define RTC_CR_CPS_WIDTH                         1u
#define RTC_CR_CPS(x)                            (((uint32)(((uint32)(x))<<RTC_CR_CPS_SHIFT))&RTC_CR_CPS_MASK)
#define RTC_CR_LPOS_MASK                         0x80u
#define RTC_CR_LPOS_SHIFT                        7u
#define RTC_CR_LPOS_WIDTH                        1u
#define RTC_CR_LPOS(x)                           (((uint32)(((uint32)(x))<<RTC_CR_LPOS_SHIFT))&RTC_CR_LPOS_MASK)
#define RTC_CR_CPE_MASK                          0x1000000u
#define RTC_CR_CPE_SHIFT                         24u
#define RTC_CR_CPE_WIDTH                         1u
#define RTC_CR_CPE(x)                            (((uint32)(((uint32)(x))<<RTC_CR_CPE_SHIFT))&RTC_CR_CPE_MASK)
/* SR Bit Fields */
#define RTC_SR_TIF_MASK                          0x1u
#define RTC_SR_TIF_SHIFT                         0u
#define RTC_SR_TIF_WIDTH                         1u
#define RTC_SR_TIF(x)                            (((uint32)(((uint32)(x))<<RTC_SR_TIF_SHIFT))&RTC_SR_TIF_MASK)
#define RTC_SR_TOF_MASK                          0x2u
#define RTC_SR_TOF_SHIFT                         1u
#define RTC_SR_TOF_WIDTH                         1u
#define RTC_SR_TOF(x)                            (((uint32)(((uint32)(x))<<RTC_SR_TOF_SHIFT))&RTC_SR_TOF_MASK)
#define RTC_SR_TAF_MASK                          0x4u
#define RTC_SR_TAF_SHIFT                         2u
#define RTC_SR_TAF_WIDTH                         1u
#define RTC_SR_TAF(x)                            (((uint32)(((uint32)(x))<<RTC_SR_TAF_SHIFT))&RTC_SR_TAF_MASK)
#define RTC_SR_TCE_MASK                          0x10u
#define RTC_SR_TCE_SHIFT                         4u
#define RTC_SR_TCE_WIDTH                         1u
#define RTC_SR_TCE(x)                            (((uint32)(((uint32)(x))<<RTC_SR_TCE_SHIFT))&RTC_SR_TCE_MASK)
/* LR Bit Fields */
#define RTC_LR_TCL_MASK                          0x8u
#define RTC_LR_TCL_SHIFT                         3u
#define RTC_LR_TCL_WIDTH                         1u
#define RTC_LR_TCL(x)                            (((uint32)(((uint32)(x))<<RTC_LR_TCL_SHIFT))&RTC_LR_TCL_MASK)
#define RTC_LR_CRL_MASK                          0x10u
#define RTC_LR_CRL_SHIFT                         4u
#define RTC_LR_CRL_WIDTH                         1u
#define RTC_LR_CRL(x)                            (((uint32)(((uint32)(x))<<RTC_LR_CRL_SHIFT))&RTC_LR_CRL_MASK)
#define RTC_LR_SRL_MASK                          0x20u
#define RTC_LR_SRL_SHIFT                         5u
#define RTC_LR_SRL_WIDTH                         1u
#define RTC_LR_SRL(x)                            (((uint32)(((uint32)(x))<<RTC_LR_SRL_SHIFT))&RTC_LR_SRL_MASK)
#define RTC_LR_LRL_MASK                          0x40u
#define RTC_LR_LRL_SHIFT                         6u
#define RTC_LR_LRL_WIDTH                         1u
#define RTC_LR_LRL(x)                            (((uint32)(((uint32)(x))<<RTC_LR_LRL_SHIFT))&RTC_LR_LRL_MASK)
/* IER Bit Fields */
#define RTC_IER_TIIE_MASK                        0x1u
#define RTC_IER_TIIE_SHIFT                       0u
#define RTC_IER_TIIE_WIDTH                       1u
#define RTC_IER_TIIE(x)                          (((uint32)(((uint32)(x))<<RTC_IER_TIIE_SHIFT))&RTC_IER_TIIE_MASK)
#define RTC_IER_TOIE_MASK                        0x2u
#define RTC_IER_TOIE_SHIFT                       1u
#define RTC_IER_TOIE_WIDTH                       1u
#define RTC_IER_TOIE(x)                          (((uint32)(((uint32)(x))<<RTC_IER_TOIE_SHIFT))&RTC_IER_TOIE_MASK)
#define RTC_IER_TAIE_MASK                        0x4u
#define RTC_IER_TAIE_SHIFT                       2u
#define RTC_IER_TAIE_WIDTH                       1u
#define RTC_IER_TAIE(x)                          (((uint32)(((uint32)(x))<<RTC_IER_TAIE_SHIFT))&RTC_IER_TAIE_MASK)
#define RTC_IER_TSIE_MASK                        0x10u
#define RTC_IER_TSIE_SHIFT                       4u
#define RTC_IER_TSIE_WIDTH                       1u
#define RTC_IER_TSIE(x)                          (((uint32)(((uint32)(x))<<RTC_IER_TSIE_SHIFT))&RTC_IER_TSIE_MASK)
#define RTC_IER_TSIC_MASK                        0x70000u
#define RTC_IER_TSIC_SHIFT                       16u
#define RTC_IER_TSIC_WIDTH                       3u
#define RTC_IER_TSIC(x)                          (((uint32)(((uint32)(x))<<RTC_IER_TSIC_SHIFT))&RTC_IER_TSIC_MASK)

/*!
 * @}
 */ /* end of group RTC_Register_Masks */


/*!
 * @}
 */ /* end of group RTC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- S32_NVIC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S32_NVIC_Peripheral_Access_Layer S32_NVIC Peripheral Access Layer
 * @{
 */


/** S32_NVIC - Size of Registers Arrays */
#define S32_NVIC_ISER_COUNT                      4u
#define S32_NVIC_ICER_COUNT                      4u
#define S32_NVIC_ISPR_COUNT                      4u
#define S32_NVIC_ICPR_COUNT                      4u
#define S32_NVIC_IABR_COUNT                      4u
#define S32_NVIC_IP_COUNT                        123u

/** S32_NVIC - Register Layout Typedef */
typedef struct {
  __IO uint32 ISER[S32_NVIC_ISER_COUNT];         /**< Interrupt Set Enable Register n, array offset: 0x0, array step: 0x4 */
       uint8 RESERVED_0[112];
  __IO uint32 ICER[S32_NVIC_ICER_COUNT];         /**< Interrupt Clear Enable Register n, array offset: 0x80, array step: 0x4 */
       uint8 RESERVED_1[112];
  __IO uint32 ISPR[S32_NVIC_ISPR_COUNT];         /**< Interrupt Set Pending Register n, array offset: 0x100, array step: 0x4 */
       uint8 RESERVED_2[112];
  __IO uint32 ICPR[S32_NVIC_ICPR_COUNT];         /**< Interrupt Clear Pending Register n, array offset: 0x180, array step: 0x4 */
       uint8 RESERVED_3[112];
  __IO uint32 IABR[S32_NVIC_IABR_COUNT];         /**< Interrupt Active bit Register n, array offset: 0x200, array step: 0x4 */
       uint8 RESERVED_4[240];
  __IO uint8 IP[S32_NVIC_IP_COUNT];              /**< Interrupt Priority Register n, array offset: 0x300, array step: 0x1 */
       uint8 RESERVED_5[2693];
  __O  uint32 STIR;                              /**< Software Trigger Interrupt Register, offset: 0xE00 */
} S32_NVIC_Type, *S32_NVIC_MemMapPtr;

 /** Number of instances of the S32_NVIC module. */
#define S32_NVIC_INSTANCE_COUNT                  (1u)


/* S32_NVIC - Peripheral instance base addresses */
/** Peripheral S32_NVIC base address */
#define S32_NVIC_BASE                            (0xE000E100u)
/** Peripheral S32_NVIC base pointer */
#define S32_NVIC                                 ((S32_NVIC_Type *)S32_NVIC_BASE)
/** Array initializer of S32_NVIC peripheral base addresses */
#define S32_NVIC_BASE_ADDRS                      { S32_NVIC_BASE }
/** Array initializer of S32_NVIC peripheral base pointers */
#define S32_NVIC_BASE_PTRS                       { S32_NVIC }
 /** Number of interrupt vector arrays for the S32_NVIC module. */
#define S32_NVIC_IRQS_ARR_COUNT                  (1u)
 /** Number of interrupt channels for the S32_NVIC module. */
#define S32_NVIC_IRQS_CH_COUNT                   (1u)
/** Interrupt vectors for the S32_NVIC peripheral type */
#define S32_NVIC_IRQS                            { SWI_IRQn }

/* ----------------------------------------------------------------------------
   -- S32_NVIC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S32_NVIC_Register_Masks S32_NVIC Register Masks
 * @{
 */

/* ISER Bit Fields */
#define S32_NVIC_ISER_SETENA_MASK                0xFFFFFFFFu
#define S32_NVIC_ISER_SETENA_SHIFT               0u
#define S32_NVIC_ISER_SETENA_WIDTH               32u
#define S32_NVIC_ISER_SETENA(x)                  (((uint32)(((uint32)(x))<<S32_NVIC_ISER_SETENA_SHIFT))&S32_NVIC_ISER_SETENA_MASK)
/* ICER Bit Fields */
#define S32_NVIC_ICER_CLRENA_MASK                0xFFFFFFFFu
#define S32_NVIC_ICER_CLRENA_SHIFT               0u
#define S32_NVIC_ICER_CLRENA_WIDTH               32u
#define S32_NVIC_ICER_CLRENA(x)                  (((uint32)(((uint32)(x))<<S32_NVIC_ICER_CLRENA_SHIFT))&S32_NVIC_ICER_CLRENA_MASK)
/* ISPR Bit Fields */
#define S32_NVIC_ISPR_SETPEND_MASK               0xFFFFFFFFu
#define S32_NVIC_ISPR_SETPEND_SHIFT              0u
#define S32_NVIC_ISPR_SETPEND_WIDTH              32u
#define S32_NVIC_ISPR_SETPEND(x)                 (((uint32)(((uint32)(x))<<S32_NVIC_ISPR_SETPEND_SHIFT))&S32_NVIC_ISPR_SETPEND_MASK)
/* ICPR Bit Fields */
#define S32_NVIC_ICPR_CLRPEND_MASK               0xFFFFFFFFu
#define S32_NVIC_ICPR_CLRPEND_SHIFT              0u
#define S32_NVIC_ICPR_CLRPEND_WIDTH              32u
#define S32_NVIC_ICPR_CLRPEND(x)                 (((uint32)(((uint32)(x))<<S32_NVIC_ICPR_CLRPEND_SHIFT))&S32_NVIC_ICPR_CLRPEND_MASK)
/* IABR Bit Fields */
#define S32_NVIC_IABR_ACTIVE_MASK                0xFFFFFFFFu
#define S32_NVIC_IABR_ACTIVE_SHIFT               0u
#define S32_NVIC_IABR_ACTIVE_WIDTH               32u
#define S32_NVIC_IABR_ACTIVE(x)                  (((uint32)(((uint32)(x))<<S32_NVIC_IABR_ACTIVE_SHIFT))&S32_NVIC_IABR_ACTIVE_MASK)
/* IP Bit Fields */
#define S32_NVIC_IP_PRI0_MASK                    0xFFu
#define S32_NVIC_IP_PRI0_SHIFT                   0u
#define S32_NVIC_IP_PRI0_WIDTH                   8u
#define S32_NVIC_IP_PRI0(x)                      (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI0_SHIFT))&S32_NVIC_IP_PRI0_MASK)
#define S32_NVIC_IP_PRI1_MASK                    0xFFu
#define S32_NVIC_IP_PRI1_SHIFT                   0u
#define S32_NVIC_IP_PRI1_WIDTH                   8u
#define S32_NVIC_IP_PRI1(x)                      (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI1_SHIFT))&S32_NVIC_IP_PRI1_MASK)
#define S32_NVIC_IP_PRI2_MASK                    0xFFu
#define S32_NVIC_IP_PRI2_SHIFT                   0u
#define S32_NVIC_IP_PRI2_WIDTH                   8u
#define S32_NVIC_IP_PRI2(x)                      (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI2_SHIFT))&S32_NVIC_IP_PRI2_MASK)
#define S32_NVIC_IP_PRI3_MASK                    0xFFu
#define S32_NVIC_IP_PRI3_SHIFT                   0u
#define S32_NVIC_IP_PRI3_WIDTH                   8u
#define S32_NVIC_IP_PRI3(x)                      (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI3_SHIFT))&S32_NVIC_IP_PRI3_MASK)
#define S32_NVIC_IP_PRI4_MASK                    0xFFu
#define S32_NVIC_IP_PRI4_SHIFT                   0u
#define S32_NVIC_IP_PRI4_WIDTH                   8u
#define S32_NVIC_IP_PRI4(x)                      (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI4_SHIFT))&S32_NVIC_IP_PRI4_MASK)
#define S32_NVIC_IP_PRI5_MASK                    0xFFu
#define S32_NVIC_IP_PRI5_SHIFT                   0u
#define S32_NVIC_IP_PRI5_WIDTH                   8u
#define S32_NVIC_IP_PRI5(x)                      (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI5_SHIFT))&S32_NVIC_IP_PRI5_MASK)
#define S32_NVIC_IP_PRI6_MASK                    0xFFu
#define S32_NVIC_IP_PRI6_SHIFT                   0u
#define S32_NVIC_IP_PRI6_WIDTH                   8u
#define S32_NVIC_IP_PRI6(x)                      (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI6_SHIFT))&S32_NVIC_IP_PRI6_MASK)
#define S32_NVIC_IP_PRI7_MASK                    0xFFu
#define S32_NVIC_IP_PRI7_SHIFT                   0u
#define S32_NVIC_IP_PRI7_WIDTH                   8u
#define S32_NVIC_IP_PRI7(x)                      (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI7_SHIFT))&S32_NVIC_IP_PRI7_MASK)
#define S32_NVIC_IP_PRI8_MASK                    0xFFu
#define S32_NVIC_IP_PRI8_SHIFT                   0u
#define S32_NVIC_IP_PRI8_WIDTH                   8u
#define S32_NVIC_IP_PRI8(x)                      (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI8_SHIFT))&S32_NVIC_IP_PRI8_MASK)
#define S32_NVIC_IP_PRI9_MASK                    0xFFu
#define S32_NVIC_IP_PRI9_SHIFT                   0u
#define S32_NVIC_IP_PRI9_WIDTH                   8u
#define S32_NVIC_IP_PRI9(x)                      (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI9_SHIFT))&S32_NVIC_IP_PRI9_MASK)
#define S32_NVIC_IP_PRI10_MASK                   0xFFu
#define S32_NVIC_IP_PRI10_SHIFT                  0u
#define S32_NVIC_IP_PRI10_WIDTH                  8u
#define S32_NVIC_IP_PRI10(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI10_SHIFT))&S32_NVIC_IP_PRI10_MASK)
#define S32_NVIC_IP_PRI11_MASK                   0xFFu
#define S32_NVIC_IP_PRI11_SHIFT                  0u
#define S32_NVIC_IP_PRI11_WIDTH                  8u
#define S32_NVIC_IP_PRI11(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI11_SHIFT))&S32_NVIC_IP_PRI11_MASK)
#define S32_NVIC_IP_PRI12_MASK                   0xFFu
#define S32_NVIC_IP_PRI12_SHIFT                  0u
#define S32_NVIC_IP_PRI12_WIDTH                  8u
#define S32_NVIC_IP_PRI12(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI12_SHIFT))&S32_NVIC_IP_PRI12_MASK)
#define S32_NVIC_IP_PRI13_MASK                   0xFFu
#define S32_NVIC_IP_PRI13_SHIFT                  0u
#define S32_NVIC_IP_PRI13_WIDTH                  8u
#define S32_NVIC_IP_PRI13(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI13_SHIFT))&S32_NVIC_IP_PRI13_MASK)
#define S32_NVIC_IP_PRI14_MASK                   0xFFu
#define S32_NVIC_IP_PRI14_SHIFT                  0u
#define S32_NVIC_IP_PRI14_WIDTH                  8u
#define S32_NVIC_IP_PRI14(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI14_SHIFT))&S32_NVIC_IP_PRI14_MASK)
#define S32_NVIC_IP_PRI15_MASK                   0xFFu
#define S32_NVIC_IP_PRI15_SHIFT                  0u
#define S32_NVIC_IP_PRI15_WIDTH                  8u
#define S32_NVIC_IP_PRI15(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI15_SHIFT))&S32_NVIC_IP_PRI15_MASK)
#define S32_NVIC_IP_PRI16_MASK                   0xFFu
#define S32_NVIC_IP_PRI16_SHIFT                  0u
#define S32_NVIC_IP_PRI16_WIDTH                  8u
#define S32_NVIC_IP_PRI16(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI16_SHIFT))&S32_NVIC_IP_PRI16_MASK)
#define S32_NVIC_IP_PRI17_MASK                   0xFFu
#define S32_NVIC_IP_PRI17_SHIFT                  0u
#define S32_NVIC_IP_PRI17_WIDTH                  8u
#define S32_NVIC_IP_PRI17(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI17_SHIFT))&S32_NVIC_IP_PRI17_MASK)
#define S32_NVIC_IP_PRI18_MASK                   0xFFu
#define S32_NVIC_IP_PRI18_SHIFT                  0u
#define S32_NVIC_IP_PRI18_WIDTH                  8u
#define S32_NVIC_IP_PRI18(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI18_SHIFT))&S32_NVIC_IP_PRI18_MASK)
#define S32_NVIC_IP_PRI19_MASK                   0xFFu
#define S32_NVIC_IP_PRI19_SHIFT                  0u
#define S32_NVIC_IP_PRI19_WIDTH                  8u
#define S32_NVIC_IP_PRI19(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI19_SHIFT))&S32_NVIC_IP_PRI19_MASK)
#define S32_NVIC_IP_PRI20_MASK                   0xFFu
#define S32_NVIC_IP_PRI20_SHIFT                  0u
#define S32_NVIC_IP_PRI20_WIDTH                  8u
#define S32_NVIC_IP_PRI20(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI20_SHIFT))&S32_NVIC_IP_PRI20_MASK)
#define S32_NVIC_IP_PRI21_MASK                   0xFFu
#define S32_NVIC_IP_PRI21_SHIFT                  0u
#define S32_NVIC_IP_PRI21_WIDTH                  8u
#define S32_NVIC_IP_PRI21(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI21_SHIFT))&S32_NVIC_IP_PRI21_MASK)
#define S32_NVIC_IP_PRI22_MASK                   0xFFu
#define S32_NVIC_IP_PRI22_SHIFT                  0u
#define S32_NVIC_IP_PRI22_WIDTH                  8u
#define S32_NVIC_IP_PRI22(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI22_SHIFT))&S32_NVIC_IP_PRI22_MASK)
#define S32_NVIC_IP_PRI23_MASK                   0xFFu
#define S32_NVIC_IP_PRI23_SHIFT                  0u
#define S32_NVIC_IP_PRI23_WIDTH                  8u
#define S32_NVIC_IP_PRI23(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI23_SHIFT))&S32_NVIC_IP_PRI23_MASK)
#define S32_NVIC_IP_PRI24_MASK                   0xFFu
#define S32_NVIC_IP_PRI24_SHIFT                  0u
#define S32_NVIC_IP_PRI24_WIDTH                  8u
#define S32_NVIC_IP_PRI24(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI24_SHIFT))&S32_NVIC_IP_PRI24_MASK)
#define S32_NVIC_IP_PRI25_MASK                   0xFFu
#define S32_NVIC_IP_PRI25_SHIFT                  0u
#define S32_NVIC_IP_PRI25_WIDTH                  8u
#define S32_NVIC_IP_PRI25(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI25_SHIFT))&S32_NVIC_IP_PRI25_MASK)
#define S32_NVIC_IP_PRI26_MASK                   0xFFu
#define S32_NVIC_IP_PRI26_SHIFT                  0u
#define S32_NVIC_IP_PRI26_WIDTH                  8u
#define S32_NVIC_IP_PRI26(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI26_SHIFT))&S32_NVIC_IP_PRI26_MASK)
#define S32_NVIC_IP_PRI27_MASK                   0xFFu
#define S32_NVIC_IP_PRI27_SHIFT                  0u
#define S32_NVIC_IP_PRI27_WIDTH                  8u
#define S32_NVIC_IP_PRI27(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI27_SHIFT))&S32_NVIC_IP_PRI27_MASK)
#define S32_NVIC_IP_PRI28_MASK                   0xFFu
#define S32_NVIC_IP_PRI28_SHIFT                  0u
#define S32_NVIC_IP_PRI28_WIDTH                  8u
#define S32_NVIC_IP_PRI28(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI28_SHIFT))&S32_NVIC_IP_PRI28_MASK)
#define S32_NVIC_IP_PRI29_MASK                   0xFFu
#define S32_NVIC_IP_PRI29_SHIFT                  0u
#define S32_NVIC_IP_PRI29_WIDTH                  8u
#define S32_NVIC_IP_PRI29(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI29_SHIFT))&S32_NVIC_IP_PRI29_MASK)
#define S32_NVIC_IP_PRI30_MASK                   0xFFu
#define S32_NVIC_IP_PRI30_SHIFT                  0u
#define S32_NVIC_IP_PRI30_WIDTH                  8u
#define S32_NVIC_IP_PRI30(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI30_SHIFT))&S32_NVIC_IP_PRI30_MASK)
#define S32_NVIC_IP_PRI31_MASK                   0xFFu
#define S32_NVIC_IP_PRI31_SHIFT                  0u
#define S32_NVIC_IP_PRI31_WIDTH                  8u
#define S32_NVIC_IP_PRI31(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI31_SHIFT))&S32_NVIC_IP_PRI31_MASK)
#define S32_NVIC_IP_PRI32_MASK                   0xFFu
#define S32_NVIC_IP_PRI32_SHIFT                  0u
#define S32_NVIC_IP_PRI32_WIDTH                  8u
#define S32_NVIC_IP_PRI32(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI32_SHIFT))&S32_NVIC_IP_PRI32_MASK)
#define S32_NVIC_IP_PRI33_MASK                   0xFFu
#define S32_NVIC_IP_PRI33_SHIFT                  0u
#define S32_NVIC_IP_PRI33_WIDTH                  8u
#define S32_NVIC_IP_PRI33(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI33_SHIFT))&S32_NVIC_IP_PRI33_MASK)
#define S32_NVIC_IP_PRI34_MASK                   0xFFu
#define S32_NVIC_IP_PRI34_SHIFT                  0u
#define S32_NVIC_IP_PRI34_WIDTH                  8u
#define S32_NVIC_IP_PRI34(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI34_SHIFT))&S32_NVIC_IP_PRI34_MASK)
#define S32_NVIC_IP_PRI35_MASK                   0xFFu
#define S32_NVIC_IP_PRI35_SHIFT                  0u
#define S32_NVIC_IP_PRI35_WIDTH                  8u
#define S32_NVIC_IP_PRI35(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI35_SHIFT))&S32_NVIC_IP_PRI35_MASK)
#define S32_NVIC_IP_PRI36_MASK                   0xFFu
#define S32_NVIC_IP_PRI36_SHIFT                  0u
#define S32_NVIC_IP_PRI36_WIDTH                  8u
#define S32_NVIC_IP_PRI36(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI36_SHIFT))&S32_NVIC_IP_PRI36_MASK)
#define S32_NVIC_IP_PRI37_MASK                   0xFFu
#define S32_NVIC_IP_PRI37_SHIFT                  0u
#define S32_NVIC_IP_PRI37_WIDTH                  8u
#define S32_NVIC_IP_PRI37(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI37_SHIFT))&S32_NVIC_IP_PRI37_MASK)
#define S32_NVIC_IP_PRI38_MASK                   0xFFu
#define S32_NVIC_IP_PRI38_SHIFT                  0u
#define S32_NVIC_IP_PRI38_WIDTH                  8u
#define S32_NVIC_IP_PRI38(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI38_SHIFT))&S32_NVIC_IP_PRI38_MASK)
#define S32_NVIC_IP_PRI39_MASK                   0xFFu
#define S32_NVIC_IP_PRI39_SHIFT                  0u
#define S32_NVIC_IP_PRI39_WIDTH                  8u
#define S32_NVIC_IP_PRI39(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI39_SHIFT))&S32_NVIC_IP_PRI39_MASK)
#define S32_NVIC_IP_PRI40_MASK                   0xFFu
#define S32_NVIC_IP_PRI40_SHIFT                  0u
#define S32_NVIC_IP_PRI40_WIDTH                  8u
#define S32_NVIC_IP_PRI40(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI40_SHIFT))&S32_NVIC_IP_PRI40_MASK)
#define S32_NVIC_IP_PRI41_MASK                   0xFFu
#define S32_NVIC_IP_PRI41_SHIFT                  0u
#define S32_NVIC_IP_PRI41_WIDTH                  8u
#define S32_NVIC_IP_PRI41(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI41_SHIFT))&S32_NVIC_IP_PRI41_MASK)
#define S32_NVIC_IP_PRI42_MASK                   0xFFu
#define S32_NVIC_IP_PRI42_SHIFT                  0u
#define S32_NVIC_IP_PRI42_WIDTH                  8u
#define S32_NVIC_IP_PRI42(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI42_SHIFT))&S32_NVIC_IP_PRI42_MASK)
#define S32_NVIC_IP_PRI43_MASK                   0xFFu
#define S32_NVIC_IP_PRI43_SHIFT                  0u
#define S32_NVIC_IP_PRI43_WIDTH                  8u
#define S32_NVIC_IP_PRI43(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI43_SHIFT))&S32_NVIC_IP_PRI43_MASK)
#define S32_NVIC_IP_PRI44_MASK                   0xFFu
#define S32_NVIC_IP_PRI44_SHIFT                  0u
#define S32_NVIC_IP_PRI44_WIDTH                  8u
#define S32_NVIC_IP_PRI44(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI44_SHIFT))&S32_NVIC_IP_PRI44_MASK)
#define S32_NVIC_IP_PRI45_MASK                   0xFFu
#define S32_NVIC_IP_PRI45_SHIFT                  0u
#define S32_NVIC_IP_PRI45_WIDTH                  8u
#define S32_NVIC_IP_PRI45(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI45_SHIFT))&S32_NVIC_IP_PRI45_MASK)
#define S32_NVIC_IP_PRI46_MASK                   0xFFu
#define S32_NVIC_IP_PRI46_SHIFT                  0u
#define S32_NVIC_IP_PRI46_WIDTH                  8u
#define S32_NVIC_IP_PRI46(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI46_SHIFT))&S32_NVIC_IP_PRI46_MASK)
#define S32_NVIC_IP_PRI47_MASK                   0xFFu
#define S32_NVIC_IP_PRI47_SHIFT                  0u
#define S32_NVIC_IP_PRI47_WIDTH                  8u
#define S32_NVIC_IP_PRI47(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI47_SHIFT))&S32_NVIC_IP_PRI47_MASK)
#define S32_NVIC_IP_PRI48_MASK                   0xFFu
#define S32_NVIC_IP_PRI48_SHIFT                  0u
#define S32_NVIC_IP_PRI48_WIDTH                  8u
#define S32_NVIC_IP_PRI48(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI48_SHIFT))&S32_NVIC_IP_PRI48_MASK)
#define S32_NVIC_IP_PRI49_MASK                   0xFFu
#define S32_NVIC_IP_PRI49_SHIFT                  0u
#define S32_NVIC_IP_PRI49_WIDTH                  8u
#define S32_NVIC_IP_PRI49(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI49_SHIFT))&S32_NVIC_IP_PRI49_MASK)
#define S32_NVIC_IP_PRI50_MASK                   0xFFu
#define S32_NVIC_IP_PRI50_SHIFT                  0u
#define S32_NVIC_IP_PRI50_WIDTH                  8u
#define S32_NVIC_IP_PRI50(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI50_SHIFT))&S32_NVIC_IP_PRI50_MASK)
#define S32_NVIC_IP_PRI51_MASK                   0xFFu
#define S32_NVIC_IP_PRI51_SHIFT                  0u
#define S32_NVIC_IP_PRI51_WIDTH                  8u
#define S32_NVIC_IP_PRI51(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI51_SHIFT))&S32_NVIC_IP_PRI51_MASK)
#define S32_NVIC_IP_PRI52_MASK                   0xFFu
#define S32_NVIC_IP_PRI52_SHIFT                  0u
#define S32_NVIC_IP_PRI52_WIDTH                  8u
#define S32_NVIC_IP_PRI52(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI52_SHIFT))&S32_NVIC_IP_PRI52_MASK)
#define S32_NVIC_IP_PRI53_MASK                   0xFFu
#define S32_NVIC_IP_PRI53_SHIFT                  0u
#define S32_NVIC_IP_PRI53_WIDTH                  8u
#define S32_NVIC_IP_PRI53(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI53_SHIFT))&S32_NVIC_IP_PRI53_MASK)
#define S32_NVIC_IP_PRI54_MASK                   0xFFu
#define S32_NVIC_IP_PRI54_SHIFT                  0u
#define S32_NVIC_IP_PRI54_WIDTH                  8u
#define S32_NVIC_IP_PRI54(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI54_SHIFT))&S32_NVIC_IP_PRI54_MASK)
#define S32_NVIC_IP_PRI55_MASK                   0xFFu
#define S32_NVIC_IP_PRI55_SHIFT                  0u
#define S32_NVIC_IP_PRI55_WIDTH                  8u
#define S32_NVIC_IP_PRI55(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI55_SHIFT))&S32_NVIC_IP_PRI55_MASK)
#define S32_NVIC_IP_PRI56_MASK                   0xFFu
#define S32_NVIC_IP_PRI56_SHIFT                  0u
#define S32_NVIC_IP_PRI56_WIDTH                  8u
#define S32_NVIC_IP_PRI56(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI56_SHIFT))&S32_NVIC_IP_PRI56_MASK)
#define S32_NVIC_IP_PRI57_MASK                   0xFFu
#define S32_NVIC_IP_PRI57_SHIFT                  0u
#define S32_NVIC_IP_PRI57_WIDTH                  8u
#define S32_NVIC_IP_PRI57(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI57_SHIFT))&S32_NVIC_IP_PRI57_MASK)
#define S32_NVIC_IP_PRI58_MASK                   0xFFu
#define S32_NVIC_IP_PRI58_SHIFT                  0u
#define S32_NVIC_IP_PRI58_WIDTH                  8u
#define S32_NVIC_IP_PRI58(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI58_SHIFT))&S32_NVIC_IP_PRI58_MASK)
#define S32_NVIC_IP_PRI59_MASK                   0xFFu
#define S32_NVIC_IP_PRI59_SHIFT                  0u
#define S32_NVIC_IP_PRI59_WIDTH                  8u
#define S32_NVIC_IP_PRI59(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI59_SHIFT))&S32_NVIC_IP_PRI59_MASK)
#define S32_NVIC_IP_PRI60_MASK                   0xFFu
#define S32_NVIC_IP_PRI60_SHIFT                  0u
#define S32_NVIC_IP_PRI60_WIDTH                  8u
#define S32_NVIC_IP_PRI60(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI60_SHIFT))&S32_NVIC_IP_PRI60_MASK)
#define S32_NVIC_IP_PRI61_MASK                   0xFFu
#define S32_NVIC_IP_PRI61_SHIFT                  0u
#define S32_NVIC_IP_PRI61_WIDTH                  8u
#define S32_NVIC_IP_PRI61(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI61_SHIFT))&S32_NVIC_IP_PRI61_MASK)
#define S32_NVIC_IP_PRI62_MASK                   0xFFu
#define S32_NVIC_IP_PRI62_SHIFT                  0u
#define S32_NVIC_IP_PRI62_WIDTH                  8u
#define S32_NVIC_IP_PRI62(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI62_SHIFT))&S32_NVIC_IP_PRI62_MASK)
#define S32_NVIC_IP_PRI63_MASK                   0xFFu
#define S32_NVIC_IP_PRI63_SHIFT                  0u
#define S32_NVIC_IP_PRI63_WIDTH                  8u
#define S32_NVIC_IP_PRI63(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI63_SHIFT))&S32_NVIC_IP_PRI63_MASK)
#define S32_NVIC_IP_PRI64_MASK                   0xFFu
#define S32_NVIC_IP_PRI64_SHIFT                  0u
#define S32_NVIC_IP_PRI64_WIDTH                  8u
#define S32_NVIC_IP_PRI64(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI64_SHIFT))&S32_NVIC_IP_PRI64_MASK)
#define S32_NVIC_IP_PRI65_MASK                   0xFFu
#define S32_NVIC_IP_PRI65_SHIFT                  0u
#define S32_NVIC_IP_PRI65_WIDTH                  8u
#define S32_NVIC_IP_PRI65(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI65_SHIFT))&S32_NVIC_IP_PRI65_MASK)
#define S32_NVIC_IP_PRI66_MASK                   0xFFu
#define S32_NVIC_IP_PRI66_SHIFT                  0u
#define S32_NVIC_IP_PRI66_WIDTH                  8u
#define S32_NVIC_IP_PRI66(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI66_SHIFT))&S32_NVIC_IP_PRI66_MASK)
#define S32_NVIC_IP_PRI67_MASK                   0xFFu
#define S32_NVIC_IP_PRI67_SHIFT                  0u
#define S32_NVIC_IP_PRI67_WIDTH                  8u
#define S32_NVIC_IP_PRI67(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI67_SHIFT))&S32_NVIC_IP_PRI67_MASK)
#define S32_NVIC_IP_PRI68_MASK                   0xFFu
#define S32_NVIC_IP_PRI68_SHIFT                  0u
#define S32_NVIC_IP_PRI68_WIDTH                  8u
#define S32_NVIC_IP_PRI68(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI68_SHIFT))&S32_NVIC_IP_PRI68_MASK)
#define S32_NVIC_IP_PRI69_MASK                   0xFFu
#define S32_NVIC_IP_PRI69_SHIFT                  0u
#define S32_NVIC_IP_PRI69_WIDTH                  8u
#define S32_NVIC_IP_PRI69(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI69_SHIFT))&S32_NVIC_IP_PRI69_MASK)
#define S32_NVIC_IP_PRI70_MASK                   0xFFu
#define S32_NVIC_IP_PRI70_SHIFT                  0u
#define S32_NVIC_IP_PRI70_WIDTH                  8u
#define S32_NVIC_IP_PRI70(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI70_SHIFT))&S32_NVIC_IP_PRI70_MASK)
#define S32_NVIC_IP_PRI71_MASK                   0xFFu
#define S32_NVIC_IP_PRI71_SHIFT                  0u
#define S32_NVIC_IP_PRI71_WIDTH                  8u
#define S32_NVIC_IP_PRI71(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI71_SHIFT))&S32_NVIC_IP_PRI71_MASK)
#define S32_NVIC_IP_PRI72_MASK                   0xFFu
#define S32_NVIC_IP_PRI72_SHIFT                  0u
#define S32_NVIC_IP_PRI72_WIDTH                  8u
#define S32_NVIC_IP_PRI72(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI72_SHIFT))&S32_NVIC_IP_PRI72_MASK)
#define S32_NVIC_IP_PRI73_MASK                   0xFFu
#define S32_NVIC_IP_PRI73_SHIFT                  0u
#define S32_NVIC_IP_PRI73_WIDTH                  8u
#define S32_NVIC_IP_PRI73(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI73_SHIFT))&S32_NVIC_IP_PRI73_MASK)
#define S32_NVIC_IP_PRI74_MASK                   0xFFu
#define S32_NVIC_IP_PRI74_SHIFT                  0u
#define S32_NVIC_IP_PRI74_WIDTH                  8u
#define S32_NVIC_IP_PRI74(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI74_SHIFT))&S32_NVIC_IP_PRI74_MASK)
#define S32_NVIC_IP_PRI75_MASK                   0xFFu
#define S32_NVIC_IP_PRI75_SHIFT                  0u
#define S32_NVIC_IP_PRI75_WIDTH                  8u
#define S32_NVIC_IP_PRI75(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI75_SHIFT))&S32_NVIC_IP_PRI75_MASK)
#define S32_NVIC_IP_PRI76_MASK                   0xFFu
#define S32_NVIC_IP_PRI76_SHIFT                  0u
#define S32_NVIC_IP_PRI76_WIDTH                  8u
#define S32_NVIC_IP_PRI76(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI76_SHIFT))&S32_NVIC_IP_PRI76_MASK)
#define S32_NVIC_IP_PRI77_MASK                   0xFFu
#define S32_NVIC_IP_PRI77_SHIFT                  0u
#define S32_NVIC_IP_PRI77_WIDTH                  8u
#define S32_NVIC_IP_PRI77(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI77_SHIFT))&S32_NVIC_IP_PRI77_MASK)
#define S32_NVIC_IP_PRI78_MASK                   0xFFu
#define S32_NVIC_IP_PRI78_SHIFT                  0u
#define S32_NVIC_IP_PRI78_WIDTH                  8u
#define S32_NVIC_IP_PRI78(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI78_SHIFT))&S32_NVIC_IP_PRI78_MASK)
#define S32_NVIC_IP_PRI79_MASK                   0xFFu
#define S32_NVIC_IP_PRI79_SHIFT                  0u
#define S32_NVIC_IP_PRI79_WIDTH                  8u
#define S32_NVIC_IP_PRI79(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI79_SHIFT))&S32_NVIC_IP_PRI79_MASK)
#define S32_NVIC_IP_PRI80_MASK                   0xFFu
#define S32_NVIC_IP_PRI80_SHIFT                  0u
#define S32_NVIC_IP_PRI80_WIDTH                  8u
#define S32_NVIC_IP_PRI80(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI80_SHIFT))&S32_NVIC_IP_PRI80_MASK)
#define S32_NVIC_IP_PRI81_MASK                   0xFFu
#define S32_NVIC_IP_PRI81_SHIFT                  0u
#define S32_NVIC_IP_PRI81_WIDTH                  8u
#define S32_NVIC_IP_PRI81(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI81_SHIFT))&S32_NVIC_IP_PRI81_MASK)
#define S32_NVIC_IP_PRI82_MASK                   0xFFu
#define S32_NVIC_IP_PRI82_SHIFT                  0u
#define S32_NVIC_IP_PRI82_WIDTH                  8u
#define S32_NVIC_IP_PRI82(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI82_SHIFT))&S32_NVIC_IP_PRI82_MASK)
#define S32_NVIC_IP_PRI83_MASK                   0xFFu
#define S32_NVIC_IP_PRI83_SHIFT                  0u
#define S32_NVIC_IP_PRI83_WIDTH                  8u
#define S32_NVIC_IP_PRI83(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI83_SHIFT))&S32_NVIC_IP_PRI83_MASK)
#define S32_NVIC_IP_PRI84_MASK                   0xFFu
#define S32_NVIC_IP_PRI84_SHIFT                  0u
#define S32_NVIC_IP_PRI84_WIDTH                  8u
#define S32_NVIC_IP_PRI84(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI84_SHIFT))&S32_NVIC_IP_PRI84_MASK)
#define S32_NVIC_IP_PRI85_MASK                   0xFFu
#define S32_NVIC_IP_PRI85_SHIFT                  0u
#define S32_NVIC_IP_PRI85_WIDTH                  8u
#define S32_NVIC_IP_PRI85(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI85_SHIFT))&S32_NVIC_IP_PRI85_MASK)
#define S32_NVIC_IP_PRI86_MASK                   0xFFu
#define S32_NVIC_IP_PRI86_SHIFT                  0u
#define S32_NVIC_IP_PRI86_WIDTH                  8u
#define S32_NVIC_IP_PRI86(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI86_SHIFT))&S32_NVIC_IP_PRI86_MASK)
#define S32_NVIC_IP_PRI87_MASK                   0xFFu
#define S32_NVIC_IP_PRI87_SHIFT                  0u
#define S32_NVIC_IP_PRI87_WIDTH                  8u
#define S32_NVIC_IP_PRI87(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI87_SHIFT))&S32_NVIC_IP_PRI87_MASK)
#define S32_NVIC_IP_PRI88_MASK                   0xFFu
#define S32_NVIC_IP_PRI88_SHIFT                  0u
#define S32_NVIC_IP_PRI88_WIDTH                  8u
#define S32_NVIC_IP_PRI88(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI88_SHIFT))&S32_NVIC_IP_PRI88_MASK)
#define S32_NVIC_IP_PRI89_MASK                   0xFFu
#define S32_NVIC_IP_PRI89_SHIFT                  0u
#define S32_NVIC_IP_PRI89_WIDTH                  8u
#define S32_NVIC_IP_PRI89(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI89_SHIFT))&S32_NVIC_IP_PRI89_MASK)
#define S32_NVIC_IP_PRI90_MASK                   0xFFu
#define S32_NVIC_IP_PRI90_SHIFT                  0u
#define S32_NVIC_IP_PRI90_WIDTH                  8u
#define S32_NVIC_IP_PRI90(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI90_SHIFT))&S32_NVIC_IP_PRI90_MASK)
#define S32_NVIC_IP_PRI91_MASK                   0xFFu
#define S32_NVIC_IP_PRI91_SHIFT                  0u
#define S32_NVIC_IP_PRI91_WIDTH                  8u
#define S32_NVIC_IP_PRI91(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI91_SHIFT))&S32_NVIC_IP_PRI91_MASK)
#define S32_NVIC_IP_PRI92_MASK                   0xFFu
#define S32_NVIC_IP_PRI92_SHIFT                  0u
#define S32_NVIC_IP_PRI92_WIDTH                  8u
#define S32_NVIC_IP_PRI92(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI92_SHIFT))&S32_NVIC_IP_PRI92_MASK)
#define S32_NVIC_IP_PRI93_MASK                   0xFFu
#define S32_NVIC_IP_PRI93_SHIFT                  0u
#define S32_NVIC_IP_PRI93_WIDTH                  8u
#define S32_NVIC_IP_PRI93(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI93_SHIFT))&S32_NVIC_IP_PRI93_MASK)
#define S32_NVIC_IP_PRI94_MASK                   0xFFu
#define S32_NVIC_IP_PRI94_SHIFT                  0u
#define S32_NVIC_IP_PRI94_WIDTH                  8u
#define S32_NVIC_IP_PRI94(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI94_SHIFT))&S32_NVIC_IP_PRI94_MASK)
#define S32_NVIC_IP_PRI95_MASK                   0xFFu
#define S32_NVIC_IP_PRI95_SHIFT                  0u
#define S32_NVIC_IP_PRI95_WIDTH                  8u
#define S32_NVIC_IP_PRI95(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI95_SHIFT))&S32_NVIC_IP_PRI95_MASK)
#define S32_NVIC_IP_PRI96_MASK                   0xFFu
#define S32_NVIC_IP_PRI96_SHIFT                  0u
#define S32_NVIC_IP_PRI96_WIDTH                  8u
#define S32_NVIC_IP_PRI96(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI96_SHIFT))&S32_NVIC_IP_PRI96_MASK)
#define S32_NVIC_IP_PRI97_MASK                   0xFFu
#define S32_NVIC_IP_PRI97_SHIFT                  0u
#define S32_NVIC_IP_PRI97_WIDTH                  8u
#define S32_NVIC_IP_PRI97(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI97_SHIFT))&S32_NVIC_IP_PRI97_MASK)
#define S32_NVIC_IP_PRI98_MASK                   0xFFu
#define S32_NVIC_IP_PRI98_SHIFT                  0u
#define S32_NVIC_IP_PRI98_WIDTH                  8u
#define S32_NVIC_IP_PRI98(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI98_SHIFT))&S32_NVIC_IP_PRI98_MASK)
#define S32_NVIC_IP_PRI99_MASK                   0xFFu
#define S32_NVIC_IP_PRI99_SHIFT                  0u
#define S32_NVIC_IP_PRI99_WIDTH                  8u
#define S32_NVIC_IP_PRI99(x)                     (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI99_SHIFT))&S32_NVIC_IP_PRI99_MASK)
#define S32_NVIC_IP_PRI100_MASK                  0xFFu
#define S32_NVIC_IP_PRI100_SHIFT                 0u
#define S32_NVIC_IP_PRI100_WIDTH                 8u
#define S32_NVIC_IP_PRI100(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI100_SHIFT))&S32_NVIC_IP_PRI100_MASK)
#define S32_NVIC_IP_PRI101_MASK                  0xFFu
#define S32_NVIC_IP_PRI101_SHIFT                 0u
#define S32_NVIC_IP_PRI101_WIDTH                 8u
#define S32_NVIC_IP_PRI101(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI101_SHIFT))&S32_NVIC_IP_PRI101_MASK)
#define S32_NVIC_IP_PRI102_MASK                  0xFFu
#define S32_NVIC_IP_PRI102_SHIFT                 0u
#define S32_NVIC_IP_PRI102_WIDTH                 8u
#define S32_NVIC_IP_PRI102(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI102_SHIFT))&S32_NVIC_IP_PRI102_MASK)
#define S32_NVIC_IP_PRI103_MASK                  0xFFu
#define S32_NVIC_IP_PRI103_SHIFT                 0u
#define S32_NVIC_IP_PRI103_WIDTH                 8u
#define S32_NVIC_IP_PRI103(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI103_SHIFT))&S32_NVIC_IP_PRI103_MASK)
#define S32_NVIC_IP_PRI104_MASK                  0xFFu
#define S32_NVIC_IP_PRI104_SHIFT                 0u
#define S32_NVIC_IP_PRI104_WIDTH                 8u
#define S32_NVIC_IP_PRI104(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI104_SHIFT))&S32_NVIC_IP_PRI104_MASK)
#define S32_NVIC_IP_PRI105_MASK                  0xFFu
#define S32_NVIC_IP_PRI105_SHIFT                 0u
#define S32_NVIC_IP_PRI105_WIDTH                 8u
#define S32_NVIC_IP_PRI105(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI105_SHIFT))&S32_NVIC_IP_PRI105_MASK)
#define S32_NVIC_IP_PRI106_MASK                  0xFFu
#define S32_NVIC_IP_PRI106_SHIFT                 0u
#define S32_NVIC_IP_PRI106_WIDTH                 8u
#define S32_NVIC_IP_PRI106(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI106_SHIFT))&S32_NVIC_IP_PRI106_MASK)
#define S32_NVIC_IP_PRI107_MASK                  0xFFu
#define S32_NVIC_IP_PRI107_SHIFT                 0u
#define S32_NVIC_IP_PRI107_WIDTH                 8u
#define S32_NVIC_IP_PRI107(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI107_SHIFT))&S32_NVIC_IP_PRI107_MASK)
#define S32_NVIC_IP_PRI108_MASK                  0xFFu
#define S32_NVIC_IP_PRI108_SHIFT                 0u
#define S32_NVIC_IP_PRI108_WIDTH                 8u
#define S32_NVIC_IP_PRI108(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI108_SHIFT))&S32_NVIC_IP_PRI108_MASK)
#define S32_NVIC_IP_PRI109_MASK                  0xFFu
#define S32_NVIC_IP_PRI109_SHIFT                 0u
#define S32_NVIC_IP_PRI109_WIDTH                 8u
#define S32_NVIC_IP_PRI109(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI109_SHIFT))&S32_NVIC_IP_PRI109_MASK)
#define S32_NVIC_IP_PRI110_MASK                  0xFFu
#define S32_NVIC_IP_PRI110_SHIFT                 0u
#define S32_NVIC_IP_PRI110_WIDTH                 8u
#define S32_NVIC_IP_PRI110(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI110_SHIFT))&S32_NVIC_IP_PRI110_MASK)
#define S32_NVIC_IP_PRI111_MASK                  0xFFu
#define S32_NVIC_IP_PRI111_SHIFT                 0u
#define S32_NVIC_IP_PRI111_WIDTH                 8u
#define S32_NVIC_IP_PRI111(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI111_SHIFT))&S32_NVIC_IP_PRI111_MASK)
#define S32_NVIC_IP_PRI112_MASK                  0xFFu
#define S32_NVIC_IP_PRI112_SHIFT                 0u
#define S32_NVIC_IP_PRI112_WIDTH                 8u
#define S32_NVIC_IP_PRI112(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI112_SHIFT))&S32_NVIC_IP_PRI112_MASK)
#define S32_NVIC_IP_PRI113_MASK                  0xFFu
#define S32_NVIC_IP_PRI113_SHIFT                 0u
#define S32_NVIC_IP_PRI113_WIDTH                 8u
#define S32_NVIC_IP_PRI113(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI113_SHIFT))&S32_NVIC_IP_PRI113_MASK)
#define S32_NVIC_IP_PRI114_MASK                  0xFFu
#define S32_NVIC_IP_PRI114_SHIFT                 0u
#define S32_NVIC_IP_PRI114_WIDTH                 8u
#define S32_NVIC_IP_PRI114(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI114_SHIFT))&S32_NVIC_IP_PRI114_MASK)
#define S32_NVIC_IP_PRI115_MASK                  0xFFu
#define S32_NVIC_IP_PRI115_SHIFT                 0u
#define S32_NVIC_IP_PRI115_WIDTH                 8u
#define S32_NVIC_IP_PRI115(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI115_SHIFT))&S32_NVIC_IP_PRI115_MASK)
#define S32_NVIC_IP_PRI116_MASK                  0xFFu
#define S32_NVIC_IP_PRI116_SHIFT                 0u
#define S32_NVIC_IP_PRI116_WIDTH                 8u
#define S32_NVIC_IP_PRI116(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI116_SHIFT))&S32_NVIC_IP_PRI116_MASK)
#define S32_NVIC_IP_PRI117_MASK                  0xFFu
#define S32_NVIC_IP_PRI117_SHIFT                 0u
#define S32_NVIC_IP_PRI117_WIDTH                 8u
#define S32_NVIC_IP_PRI117(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI117_SHIFT))&S32_NVIC_IP_PRI117_MASK)
#define S32_NVIC_IP_PRI118_MASK                  0xFFu
#define S32_NVIC_IP_PRI118_SHIFT                 0u
#define S32_NVIC_IP_PRI118_WIDTH                 8u
#define S32_NVIC_IP_PRI118(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI118_SHIFT))&S32_NVIC_IP_PRI118_MASK)
#define S32_NVIC_IP_PRI119_MASK                  0xFFu
#define S32_NVIC_IP_PRI119_SHIFT                 0u
#define S32_NVIC_IP_PRI119_WIDTH                 8u
#define S32_NVIC_IP_PRI119(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI119_SHIFT))&S32_NVIC_IP_PRI119_MASK)
#define S32_NVIC_IP_PRI120_MASK                  0xFFu
#define S32_NVIC_IP_PRI120_SHIFT                 0u
#define S32_NVIC_IP_PRI120_WIDTH                 8u
#define S32_NVIC_IP_PRI120(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI120_SHIFT))&S32_NVIC_IP_PRI120_MASK)
#define S32_NVIC_IP_PRI121_MASK                  0xFFu
#define S32_NVIC_IP_PRI121_SHIFT                 0u
#define S32_NVIC_IP_PRI121_WIDTH                 8u
#define S32_NVIC_IP_PRI121(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI121_SHIFT))&S32_NVIC_IP_PRI121_MASK)
#define S32_NVIC_IP_PRI122_MASK                  0xFFu
#define S32_NVIC_IP_PRI122_SHIFT                 0u
#define S32_NVIC_IP_PRI122_WIDTH                 8u
#define S32_NVIC_IP_PRI122(x)                    (((uint8)(((uint8)(x))<<S32_NVIC_IP_PRI122_SHIFT))&S32_NVIC_IP_PRI122_MASK)
/* STIR Bit Fields */
#define S32_NVIC_STIR_INTID_MASK                 0x1FFu
#define S32_NVIC_STIR_INTID_SHIFT                0u
#define S32_NVIC_STIR_INTID_WIDTH                9u
#define S32_NVIC_STIR_INTID(x)                   (((uint32)(((uint32)(x))<<S32_NVIC_STIR_INTID_SHIFT))&S32_NVIC_STIR_INTID_MASK)

/*!
 * @}
 */ /* end of group S32_NVIC_Register_Masks */


/*!
 * @}
 */ /* end of group S32_NVIC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- S32_SCB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S32_SCB_Peripheral_Access_Layer S32_SCB Peripheral Access Layer
 * @{
 */


/** S32_SCB - Size of Registers Arrays */

/** S32_SCB - Register Layout Typedef */
typedef struct {
       uint8 RESERVED_0[8];
  __IO uint32 ACTLR;                             /**< Auxiliary Control Register,, offset: 0x8 */
       uint8 RESERVED_1[3316];
  __I  uint32 CPUID;                             /**< CPUID Base Register, offset: 0xD00 */
  __IO uint32 ICSR;                              /**< Interrupt Control and State Register, offset: 0xD04 */
  __IO uint32 VTOR;                              /**< Vector Table Offset Register, offset: 0xD08 */
  __IO uint32 AIRCR;                             /**< Application Interrupt and Reset Control Register, offset: 0xD0C */
  __IO uint32 SCR;                               /**< System Control Register, offset: 0xD10 */
  __IO uint32 CCR;                               /**< Configuration and Control Register, offset: 0xD14 */
  __IO uint32 SHPR1;                             /**< System Handler Priority Register 1, offset: 0xD18 */
  __IO uint32 SHPR2;                             /**< System Handler Priority Register 2, offset: 0xD1C */
  __IO uint32 SHPR3;                             /**< System Handler Priority Register 3, offset: 0xD20 */
  __IO uint32 SHCSR;                             /**< System Handler Control and State Register, offset: 0xD24 */
  __IO uint32 CFSR;                              /**< Configurable Fault Status Registers, offset: 0xD28 */
  __IO uint32 HFSR;                              /**< HardFault Status register, offset: 0xD2C */
  __IO uint32 DFSR;                              /**< Debug Fault Status Register, offset: 0xD30 */
  __IO uint32 MMFAR;                             /**< MemManage Address Register, offset: 0xD34 */
  __IO uint32 BFAR;                              /**< BusFault Address Register, offset: 0xD38 */
  __IO uint32 AFSR;                              /**< Auxiliary Fault Status Register, offset: 0xD3C */
       uint8 RESERVED_2[72];
  __IO uint32 CPACR;                             /**< Coprocessor Access Control Register, offset: 0xD88 */
       uint8 RESERVED_3[424];
  __IO uint32 FPCCR;                             /**< Floating-point Context Control Register, offset: 0xF34 */
  __IO uint32 FPCAR;                             /**< Floating-point Context Address Register, offset: 0xF38 */
  __IO uint32 FPDSCR;                            /**< Floating-point Default Status Control Register, offset: 0xF3C */
} S32_SCB_Type, *S32_SCB_MemMapPtr;

 /** Number of instances of the S32_SCB module. */
#define S32_SCB_INSTANCE_COUNT                   (1u)


/* S32_SCB - Peripheral instance base addresses */
/** Peripheral S32_SCB base address */
#define S32_SCB_BASE                             (0xE000E000u)
/** Peripheral S32_SCB base pointer */
#define S32_SCB                                  ((S32_SCB_Type *)S32_SCB_BASE)
/** Array initializer of S32_SCB peripheral base addresses */
#define S32_SCB_BASE_ADDRS                       { S32_SCB_BASE }
/** Array initializer of S32_SCB peripheral base pointers */
#define S32_SCB_BASE_PTRS                        { S32_SCB }

/* ----------------------------------------------------------------------------
   -- S32_SCB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S32_SCB_Register_Masks S32_SCB Register Masks
 * @{
 */

/* ACTLR Bit Fields */
#define S32_SCB_ACTLR_DISMCYCINT_MASK            0x1u
#define S32_SCB_ACTLR_DISMCYCINT_SHIFT           0u
#define S32_SCB_ACTLR_DISMCYCINT_WIDTH           1u
#define S32_SCB_ACTLR_DISMCYCINT(x)              (((uint32)(((uint32)(x))<<S32_SCB_ACTLR_DISMCYCINT_SHIFT))&S32_SCB_ACTLR_DISMCYCINT_MASK)
#define S32_SCB_ACTLR_DISDEFWBUF_MASK            0x2u
#define S32_SCB_ACTLR_DISDEFWBUF_SHIFT           1u
#define S32_SCB_ACTLR_DISDEFWBUF_WIDTH           1u
#define S32_SCB_ACTLR_DISDEFWBUF(x)              (((uint32)(((uint32)(x))<<S32_SCB_ACTLR_DISDEFWBUF_SHIFT))&S32_SCB_ACTLR_DISDEFWBUF_MASK)
#define S32_SCB_ACTLR_DISFOLD_MASK               0x4u
#define S32_SCB_ACTLR_DISFOLD_SHIFT              2u
#define S32_SCB_ACTLR_DISFOLD_WIDTH              1u
#define S32_SCB_ACTLR_DISFOLD(x)                 (((uint32)(((uint32)(x))<<S32_SCB_ACTLR_DISFOLD_SHIFT))&S32_SCB_ACTLR_DISFOLD_MASK)
#define S32_SCB_ACTLR_DISFPCA_MASK               0x100u
#define S32_SCB_ACTLR_DISFPCA_SHIFT              8u
#define S32_SCB_ACTLR_DISFPCA_WIDTH              1u
#define S32_SCB_ACTLR_DISFPCA(x)                 (((uint32)(((uint32)(x))<<S32_SCB_ACTLR_DISFPCA_SHIFT))&S32_SCB_ACTLR_DISFPCA_MASK)
#define S32_SCB_ACTLR_DISOOFP_MASK               0x200u
#define S32_SCB_ACTLR_DISOOFP_SHIFT              9u
#define S32_SCB_ACTLR_DISOOFP_WIDTH              1u
#define S32_SCB_ACTLR_DISOOFP(x)                 (((uint32)(((uint32)(x))<<S32_SCB_ACTLR_DISOOFP_SHIFT))&S32_SCB_ACTLR_DISOOFP_MASK)
/* CPUID Bit Fields */
#define S32_SCB_CPUID_REVISION_MASK              0xFu
#define S32_SCB_CPUID_REVISION_SHIFT             0u
#define S32_SCB_CPUID_REVISION_WIDTH             4u
#define S32_SCB_CPUID_REVISION(x)                (((uint32)(((uint32)(x))<<S32_SCB_CPUID_REVISION_SHIFT))&S32_SCB_CPUID_REVISION_MASK)
#define S32_SCB_CPUID_PARTNO_MASK                0xFFF0u
#define S32_SCB_CPUID_PARTNO_SHIFT               4u
#define S32_SCB_CPUID_PARTNO_WIDTH               12u
#define S32_SCB_CPUID_PARTNO(x)                  (((uint32)(((uint32)(x))<<S32_SCB_CPUID_PARTNO_SHIFT))&S32_SCB_CPUID_PARTNO_MASK)
#define S32_SCB_CPUID_VARIANT_MASK               0xF00000u
#define S32_SCB_CPUID_VARIANT_SHIFT              20u
#define S32_SCB_CPUID_VARIANT_WIDTH              4u
#define S32_SCB_CPUID_VARIANT(x)                 (((uint32)(((uint32)(x))<<S32_SCB_CPUID_VARIANT_SHIFT))&S32_SCB_CPUID_VARIANT_MASK)
#define S32_SCB_CPUID_IMPLEMENTER_MASK           0xFF000000u
#define S32_SCB_CPUID_IMPLEMENTER_SHIFT          24u
#define S32_SCB_CPUID_IMPLEMENTER_WIDTH          8u
#define S32_SCB_CPUID_IMPLEMENTER(x)             (((uint32)(((uint32)(x))<<S32_SCB_CPUID_IMPLEMENTER_SHIFT))&S32_SCB_CPUID_IMPLEMENTER_MASK)
/* ICSR Bit Fields */
#define S32_SCB_ICSR_VECTACTIVE_MASK             0x1FFu
#define S32_SCB_ICSR_VECTACTIVE_SHIFT            0u
#define S32_SCB_ICSR_VECTACTIVE_WIDTH            9u
#define S32_SCB_ICSR_VECTACTIVE(x)               (((uint32)(((uint32)(x))<<S32_SCB_ICSR_VECTACTIVE_SHIFT))&S32_SCB_ICSR_VECTACTIVE_MASK)
#define S32_SCB_ICSR_RETTOBASE_MASK              0x800u
#define S32_SCB_ICSR_RETTOBASE_SHIFT             11u
#define S32_SCB_ICSR_RETTOBASE_WIDTH             1u
#define S32_SCB_ICSR_RETTOBASE(x)                (((uint32)(((uint32)(x))<<S32_SCB_ICSR_RETTOBASE_SHIFT))&S32_SCB_ICSR_RETTOBASE_MASK)
#define S32_SCB_ICSR_VECTPENDING_MASK            0x3F000u
#define S32_SCB_ICSR_VECTPENDING_SHIFT           12u
#define S32_SCB_ICSR_VECTPENDING_WIDTH           6u
#define S32_SCB_ICSR_VECTPENDING(x)              (((uint32)(((uint32)(x))<<S32_SCB_ICSR_VECTPENDING_SHIFT))&S32_SCB_ICSR_VECTPENDING_MASK)
#define S32_SCB_ICSR_ISRPENDING_MASK             0x400000u
#define S32_SCB_ICSR_ISRPENDING_SHIFT            22u
#define S32_SCB_ICSR_ISRPENDING_WIDTH            1u
#define S32_SCB_ICSR_ISRPENDING(x)               (((uint32)(((uint32)(x))<<S32_SCB_ICSR_ISRPENDING_SHIFT))&S32_SCB_ICSR_ISRPENDING_MASK)
#define S32_SCB_ICSR_ISRPREEMPT_MASK             0x800000u
#define S32_SCB_ICSR_ISRPREEMPT_SHIFT            23u
#define S32_SCB_ICSR_ISRPREEMPT_WIDTH            1u
#define S32_SCB_ICSR_ISRPREEMPT(x)               (((uint32)(((uint32)(x))<<S32_SCB_ICSR_ISRPREEMPT_SHIFT))&S32_SCB_ICSR_ISRPREEMPT_MASK)
#define S32_SCB_ICSR_PENDSTCLR_MASK              0x2000000u
#define S32_SCB_ICSR_PENDSTCLR_SHIFT             25u
#define S32_SCB_ICSR_PENDSTCLR_WIDTH             1u
#define S32_SCB_ICSR_PENDSTCLR(x)                (((uint32)(((uint32)(x))<<S32_SCB_ICSR_PENDSTCLR_SHIFT))&S32_SCB_ICSR_PENDSTCLR_MASK)
#define S32_SCB_ICSR_PENDSTSET_MASK              0x4000000u
#define S32_SCB_ICSR_PENDSTSET_SHIFT             26u
#define S32_SCB_ICSR_PENDSTSET_WIDTH             1u
#define S32_SCB_ICSR_PENDSTSET(x)                (((uint32)(((uint32)(x))<<S32_SCB_ICSR_PENDSTSET_SHIFT))&S32_SCB_ICSR_PENDSTSET_MASK)
#define S32_SCB_ICSR_PENDSVCLR_MASK              0x8000000u
#define S32_SCB_ICSR_PENDSVCLR_SHIFT             27u
#define S32_SCB_ICSR_PENDSVCLR_WIDTH             1u
#define S32_SCB_ICSR_PENDSVCLR(x)                (((uint32)(((uint32)(x))<<S32_SCB_ICSR_PENDSVCLR_SHIFT))&S32_SCB_ICSR_PENDSVCLR_MASK)
#define S32_SCB_ICSR_PENDSVSET_MASK              0x10000000u
#define S32_SCB_ICSR_PENDSVSET_SHIFT             28u
#define S32_SCB_ICSR_PENDSVSET_WIDTH             1u
#define S32_SCB_ICSR_PENDSVSET(x)                (((uint32)(((uint32)(x))<<S32_SCB_ICSR_PENDSVSET_SHIFT))&S32_SCB_ICSR_PENDSVSET_MASK)
#define S32_SCB_ICSR_NMIPENDSET_MASK             0x80000000u
#define S32_SCB_ICSR_NMIPENDSET_SHIFT            31u
#define S32_SCB_ICSR_NMIPENDSET_WIDTH            1u
#define S32_SCB_ICSR_NMIPENDSET(x)               (((uint32)(((uint32)(x))<<S32_SCB_ICSR_NMIPENDSET_SHIFT))&S32_SCB_ICSR_NMIPENDSET_MASK)
/* VTOR Bit Fields */
#define S32_SCB_VTOR_TBLOFF_MASK                 0xFFFFFF80u
#define S32_SCB_VTOR_TBLOFF_SHIFT                7u
#define S32_SCB_VTOR_TBLOFF_WIDTH                25u
#define S32_SCB_VTOR_TBLOFF(x)                   (((uint32)(((uint32)(x))<<S32_SCB_VTOR_TBLOFF_SHIFT))&S32_SCB_VTOR_TBLOFF_MASK)
/* AIRCR Bit Fields */
#define S32_SCB_AIRCR_VECTRESET_MASK             0x1u
#define S32_SCB_AIRCR_VECTRESET_SHIFT            0u
#define S32_SCB_AIRCR_VECTRESET_WIDTH            1u
#define S32_SCB_AIRCR_VECTRESET(x)               (((uint32)(((uint32)(x))<<S32_SCB_AIRCR_VECTRESET_SHIFT))&S32_SCB_AIRCR_VECTRESET_MASK)
#define S32_SCB_AIRCR_VECTCLRACTIVE_MASK         0x2u
#define S32_SCB_AIRCR_VECTCLRACTIVE_SHIFT        1u
#define S32_SCB_AIRCR_VECTCLRACTIVE_WIDTH        1u
#define S32_SCB_AIRCR_VECTCLRACTIVE(x)           (((uint32)(((uint32)(x))<<S32_SCB_AIRCR_VECTCLRACTIVE_SHIFT))&S32_SCB_AIRCR_VECTCLRACTIVE_MASK)
#define S32_SCB_AIRCR_SYSRESETREQ_MASK           0x4u
#define S32_SCB_AIRCR_SYSRESETREQ_SHIFT          2u
#define S32_SCB_AIRCR_SYSRESETREQ_WIDTH          1u
#define S32_SCB_AIRCR_SYSRESETREQ(x)             (((uint32)(((uint32)(x))<<S32_SCB_AIRCR_SYSRESETREQ_SHIFT))&S32_SCB_AIRCR_SYSRESETREQ_MASK)
#define S32_SCB_AIRCR_PRIGROUP_MASK              0x700u
#define S32_SCB_AIRCR_PRIGROUP_SHIFT             8u
#define S32_SCB_AIRCR_PRIGROUP_WIDTH             3u
#define S32_SCB_AIRCR_PRIGROUP(x)                (((uint32)(((uint32)(x))<<S32_SCB_AIRCR_PRIGROUP_SHIFT))&S32_SCB_AIRCR_PRIGROUP_MASK)
#define S32_SCB_AIRCR_ENDIANNESS_MASK            0x8000u
#define S32_SCB_AIRCR_ENDIANNESS_SHIFT           15u
#define S32_SCB_AIRCR_ENDIANNESS_WIDTH           1u
#define S32_SCB_AIRCR_ENDIANNESS(x)              (((uint32)(((uint32)(x))<<S32_SCB_AIRCR_ENDIANNESS_SHIFT))&S32_SCB_AIRCR_ENDIANNESS_MASK)
#define S32_SCB_AIRCR_VECTKEY_MASK               0xFFFF0000u
#define S32_SCB_AIRCR_VECTKEY_SHIFT              16u
#define S32_SCB_AIRCR_VECTKEY_WIDTH              16u
#define S32_SCB_AIRCR_VECTKEY(x)                 (((uint32)(((uint32)(x))<<S32_SCB_AIRCR_VECTKEY_SHIFT))&S32_SCB_AIRCR_VECTKEY_MASK)
/* SCR Bit Fields */
#define S32_SCB_SCR_SLEEPONEXIT_MASK             0x2u
#define S32_SCB_SCR_SLEEPONEXIT_SHIFT            1u
#define S32_SCB_SCR_SLEEPONEXIT_WIDTH            1u
#define S32_SCB_SCR_SLEEPONEXIT(x)               (((uint32)(((uint32)(x))<<S32_SCB_SCR_SLEEPONEXIT_SHIFT))&S32_SCB_SCR_SLEEPONEXIT_MASK)
#define S32_SCB_SCR_SLEEPDEEP_MASK               0x4u
#define S32_SCB_SCR_SLEEPDEEP_SHIFT              2u
#define S32_SCB_SCR_SLEEPDEEP_WIDTH              1u
#define S32_SCB_SCR_SLEEPDEEP(x)                 (((uint32)(((uint32)(x))<<S32_SCB_SCR_SLEEPDEEP_SHIFT))&S32_SCB_SCR_SLEEPDEEP_MASK)
#define S32_SCB_SCR_SEVONPEND_MASK               0x10u
#define S32_SCB_SCR_SEVONPEND_SHIFT              4u
#define S32_SCB_SCR_SEVONPEND_WIDTH              1u
#define S32_SCB_SCR_SEVONPEND(x)                 (((uint32)(((uint32)(x))<<S32_SCB_SCR_SEVONPEND_SHIFT))&S32_SCB_SCR_SEVONPEND_MASK)
/* CCR Bit Fields */
#define S32_SCB_CCR_NONBASETHRDENA_MASK          0x1u
#define S32_SCB_CCR_NONBASETHRDENA_SHIFT         0u
#define S32_SCB_CCR_NONBASETHRDENA_WIDTH         1u
#define S32_SCB_CCR_NONBASETHRDENA(x)            (((uint32)(((uint32)(x))<<S32_SCB_CCR_NONBASETHRDENA_SHIFT))&S32_SCB_CCR_NONBASETHRDENA_MASK)
#define S32_SCB_CCR_USERSETMPEND_MASK            0x2u
#define S32_SCB_CCR_USERSETMPEND_SHIFT           1u
#define S32_SCB_CCR_USERSETMPEND_WIDTH           1u
#define S32_SCB_CCR_USERSETMPEND(x)              (((uint32)(((uint32)(x))<<S32_SCB_CCR_USERSETMPEND_SHIFT))&S32_SCB_CCR_USERSETMPEND_MASK)
#define S32_SCB_CCR_UNALIGN_TRP_MASK             0x8u
#define S32_SCB_CCR_UNALIGN_TRP_SHIFT            3u
#define S32_SCB_CCR_UNALIGN_TRP_WIDTH            1u
#define S32_SCB_CCR_UNALIGN_TRP(x)               (((uint32)(((uint32)(x))<<S32_SCB_CCR_UNALIGN_TRP_SHIFT))&S32_SCB_CCR_UNALIGN_TRP_MASK)
#define S32_SCB_CCR_DIV_0_TRP_MASK               0x10u
#define S32_SCB_CCR_DIV_0_TRP_SHIFT              4u
#define S32_SCB_CCR_DIV_0_TRP_WIDTH              1u
#define S32_SCB_CCR_DIV_0_TRP(x)                 (((uint32)(((uint32)(x))<<S32_SCB_CCR_DIV_0_TRP_SHIFT))&S32_SCB_CCR_DIV_0_TRP_MASK)
#define S32_SCB_CCR_BFHFNMIGN_MASK               0x100u
#define S32_SCB_CCR_BFHFNMIGN_SHIFT              8u
#define S32_SCB_CCR_BFHFNMIGN_WIDTH              1u
#define S32_SCB_CCR_BFHFNMIGN(x)                 (((uint32)(((uint32)(x))<<S32_SCB_CCR_BFHFNMIGN_SHIFT))&S32_SCB_CCR_BFHFNMIGN_MASK)
#define S32_SCB_CCR_STKALIGN_MASK                0x200u
#define S32_SCB_CCR_STKALIGN_SHIFT               9u
#define S32_SCB_CCR_STKALIGN_WIDTH               1u
#define S32_SCB_CCR_STKALIGN(x)                  (((uint32)(((uint32)(x))<<S32_SCB_CCR_STKALIGN_SHIFT))&S32_SCB_CCR_STKALIGN_MASK)
/* SHPR1 Bit Fields */
#define S32_SCB_SHPR1_PRI_4_MASK                 0xFFu
#define S32_SCB_SHPR1_PRI_4_SHIFT                0u
#define S32_SCB_SHPR1_PRI_4_WIDTH                8u
#define S32_SCB_SHPR1_PRI_4(x)                   (((uint32)(((uint32)(x))<<S32_SCB_SHPR1_PRI_4_SHIFT))&S32_SCB_SHPR1_PRI_4_MASK)
#define S32_SCB_SHPR1_PRI_5_MASK                 0xFF00u
#define S32_SCB_SHPR1_PRI_5_SHIFT                8u
#define S32_SCB_SHPR1_PRI_5_WIDTH                8u
#define S32_SCB_SHPR1_PRI_5(x)                   (((uint32)(((uint32)(x))<<S32_SCB_SHPR1_PRI_5_SHIFT))&S32_SCB_SHPR1_PRI_5_MASK)
#define S32_SCB_SHPR1_PRI_6_MASK                 0xFF0000u
#define S32_SCB_SHPR1_PRI_6_SHIFT                16u
#define S32_SCB_SHPR1_PRI_6_WIDTH                8u
#define S32_SCB_SHPR1_PRI_6(x)                   (((uint32)(((uint32)(x))<<S32_SCB_SHPR1_PRI_6_SHIFT))&S32_SCB_SHPR1_PRI_6_MASK)
/* SHPR2 Bit Fields */
#define S32_SCB_SHPR2_PRI_11_MASK                0xFF000000u
#define S32_SCB_SHPR2_PRI_11_SHIFT               24u
#define S32_SCB_SHPR2_PRI_11_WIDTH               8u
#define S32_SCB_SHPR2_PRI_11(x)                  (((uint32)(((uint32)(x))<<S32_SCB_SHPR2_PRI_11_SHIFT))&S32_SCB_SHPR2_PRI_11_MASK)
/* SHPR3 Bit Fields */
#define S32_SCB_SHPR3_PRI_12_MASK                0xFFu
#define S32_SCB_SHPR3_PRI_12_SHIFT               0u
#define S32_SCB_SHPR3_PRI_12_WIDTH               8u
#define S32_SCB_SHPR3_PRI_12(x)                  (((uint32)(((uint32)(x))<<S32_SCB_SHPR3_PRI_12_SHIFT))&S32_SCB_SHPR3_PRI_12_MASK)
#define S32_SCB_SHPR3_PRI_14_MASK                0xFF0000u
#define S32_SCB_SHPR3_PRI_14_SHIFT               16u
#define S32_SCB_SHPR3_PRI_14_WIDTH               8u
#define S32_SCB_SHPR3_PRI_14(x)                  (((uint32)(((uint32)(x))<<S32_SCB_SHPR3_PRI_14_SHIFT))&S32_SCB_SHPR3_PRI_14_MASK)
#define S32_SCB_SHPR3_PRI_15_MASK                0xFF000000u
#define S32_SCB_SHPR3_PRI_15_SHIFT               24u
#define S32_SCB_SHPR3_PRI_15_WIDTH               8u
#define S32_SCB_SHPR3_PRI_15(x)                  (((uint32)(((uint32)(x))<<S32_SCB_SHPR3_PRI_15_SHIFT))&S32_SCB_SHPR3_PRI_15_MASK)
/* SHCSR Bit Fields */
#define S32_SCB_SHCSR_MEMFAULTACT_MASK           0x1u
#define S32_SCB_SHCSR_MEMFAULTACT_SHIFT          0u
#define S32_SCB_SHCSR_MEMFAULTACT_WIDTH          1u
#define S32_SCB_SHCSR_MEMFAULTACT(x)             (((uint32)(((uint32)(x))<<S32_SCB_SHCSR_MEMFAULTACT_SHIFT))&S32_SCB_SHCSR_MEMFAULTACT_MASK)
#define S32_SCB_SHCSR_BUSFAULTACT_MASK           0x2u
#define S32_SCB_SHCSR_BUSFAULTACT_SHIFT          1u
#define S32_SCB_SHCSR_BUSFAULTACT_WIDTH          1u
#define S32_SCB_SHCSR_BUSFAULTACT(x)             (((uint32)(((uint32)(x))<<S32_SCB_SHCSR_BUSFAULTACT_SHIFT))&S32_SCB_SHCSR_BUSFAULTACT_MASK)
#define S32_SCB_SHCSR_USGFAULTACT_MASK           0x8u
#define S32_SCB_SHCSR_USGFAULTACT_SHIFT          3u
#define S32_SCB_SHCSR_USGFAULTACT_WIDTH          1u
#define S32_SCB_SHCSR_USGFAULTACT(x)             (((uint32)(((uint32)(x))<<S32_SCB_SHCSR_USGFAULTACT_SHIFT))&S32_SCB_SHCSR_USGFAULTACT_MASK)
#define S32_SCB_SHCSR_SVCALLACT_MASK             0x80u
#define S32_SCB_SHCSR_SVCALLACT_SHIFT            7u
#define S32_SCB_SHCSR_SVCALLACT_WIDTH            1u
#define S32_SCB_SHCSR_SVCALLACT(x)               (((uint32)(((uint32)(x))<<S32_SCB_SHCSR_SVCALLACT_SHIFT))&S32_SCB_SHCSR_SVCALLACT_MASK)
#define S32_SCB_SHCSR_MONITORACT_MASK            0x100u
#define S32_SCB_SHCSR_MONITORACT_SHIFT           8u
#define S32_SCB_SHCSR_MONITORACT_WIDTH           1u
#define S32_SCB_SHCSR_MONITORACT(x)              (((uint32)(((uint32)(x))<<S32_SCB_SHCSR_MONITORACT_SHIFT))&S32_SCB_SHCSR_MONITORACT_MASK)
#define S32_SCB_SHCSR_PENDSVACT_MASK             0x400u
#define S32_SCB_SHCSR_PENDSVACT_SHIFT            10u
#define S32_SCB_SHCSR_PENDSVACT_WIDTH            1u
#define S32_SCB_SHCSR_PENDSVACT(x)               (((uint32)(((uint32)(x))<<S32_SCB_SHCSR_PENDSVACT_SHIFT))&S32_SCB_SHCSR_PENDSVACT_MASK)
#define S32_SCB_SHCSR_SYSTICKACT_MASK            0x800u
#define S32_SCB_SHCSR_SYSTICKACT_SHIFT           11u
#define S32_SCB_SHCSR_SYSTICKACT_WIDTH           1u
#define S32_SCB_SHCSR_SYSTICKACT(x)              (((uint32)(((uint32)(x))<<S32_SCB_SHCSR_SYSTICKACT_SHIFT))&S32_SCB_SHCSR_SYSTICKACT_MASK)
#define S32_SCB_SHCSR_USGFAULTPENDED_MASK        0x1000u
#define S32_SCB_SHCSR_USGFAULTPENDED_SHIFT       12u
#define S32_SCB_SHCSR_USGFAULTPENDED_WIDTH       1u
#define S32_SCB_SHCSR_USGFAULTPENDED(x)          (((uint32)(((uint32)(x))<<S32_SCB_SHCSR_USGFAULTPENDED_SHIFT))&S32_SCB_SHCSR_USGFAULTPENDED_MASK)
#define S32_SCB_SHCSR_MEMFAULTPENDED_MASK        0x2000u
#define S32_SCB_SHCSR_MEMFAULTPENDED_SHIFT       13u
#define S32_SCB_SHCSR_MEMFAULTPENDED_WIDTH       1u
#define S32_SCB_SHCSR_MEMFAULTPENDED(x)          (((uint32)(((uint32)(x))<<S32_SCB_SHCSR_MEMFAULTPENDED_SHIFT))&S32_SCB_SHCSR_MEMFAULTPENDED_MASK)
#define S32_SCB_SHCSR_BUSFAULTPENDED_MASK        0x4000u
#define S32_SCB_SHCSR_BUSFAULTPENDED_SHIFT       14u
#define S32_SCB_SHCSR_BUSFAULTPENDED_WIDTH       1u
#define S32_SCB_SHCSR_BUSFAULTPENDED(x)          (((uint32)(((uint32)(x))<<S32_SCB_SHCSR_BUSFAULTPENDED_SHIFT))&S32_SCB_SHCSR_BUSFAULTPENDED_MASK)
#define S32_SCB_SHCSR_SVCALLPENDED_MASK          0x8000u
#define S32_SCB_SHCSR_SVCALLPENDED_SHIFT         15u
#define S32_SCB_SHCSR_SVCALLPENDED_WIDTH         1u
#define S32_SCB_SHCSR_SVCALLPENDED(x)            (((uint32)(((uint32)(x))<<S32_SCB_SHCSR_SVCALLPENDED_SHIFT))&S32_SCB_SHCSR_SVCALLPENDED_MASK)
#define S32_SCB_SHCSR_MEMFAULTENA_MASK           0x10000u
#define S32_SCB_SHCSR_MEMFAULTENA_SHIFT          16u
#define S32_SCB_SHCSR_MEMFAULTENA_WIDTH          1u
#define S32_SCB_SHCSR_MEMFAULTENA(x)             (((uint32)(((uint32)(x))<<S32_SCB_SHCSR_MEMFAULTENA_SHIFT))&S32_SCB_SHCSR_MEMFAULTENA_MASK)
#define S32_SCB_SHCSR_BUSFAULTENA_MASK           0x20000u
#define S32_SCB_SHCSR_BUSFAULTENA_SHIFT          17u
#define S32_SCB_SHCSR_BUSFAULTENA_WIDTH          1u
#define S32_SCB_SHCSR_BUSFAULTENA(x)             (((uint32)(((uint32)(x))<<S32_SCB_SHCSR_BUSFAULTENA_SHIFT))&S32_SCB_SHCSR_BUSFAULTENA_MASK)
#define S32_SCB_SHCSR_USGFAULTENA_MASK           0x40000u
#define S32_SCB_SHCSR_USGFAULTENA_SHIFT          18u
#define S32_SCB_SHCSR_USGFAULTENA_WIDTH          1u
#define S32_SCB_SHCSR_USGFAULTENA(x)             (((uint32)(((uint32)(x))<<S32_SCB_SHCSR_USGFAULTENA_SHIFT))&S32_SCB_SHCSR_USGFAULTENA_MASK)
/* CFSR Bit Fields */
#define S32_SCB_CFSR_IACCVIOL_MASK               0x1u
#define S32_SCB_CFSR_IACCVIOL_SHIFT              0u
#define S32_SCB_CFSR_IACCVIOL_WIDTH              1u
#define S32_SCB_CFSR_IACCVIOL(x)                 (((uint32)(((uint32)(x))<<S32_SCB_CFSR_IACCVIOL_SHIFT))&S32_SCB_CFSR_IACCVIOL_MASK)
#define S32_SCB_CFSR_DACCVIOL_MASK               0x2u
#define S32_SCB_CFSR_DACCVIOL_SHIFT              1u
#define S32_SCB_CFSR_DACCVIOL_WIDTH              1u
#define S32_SCB_CFSR_DACCVIOL(x)                 (((uint32)(((uint32)(x))<<S32_SCB_CFSR_DACCVIOL_SHIFT))&S32_SCB_CFSR_DACCVIOL_MASK)
#define S32_SCB_CFSR_MUNSTKERR_MASK              0x8u
#define S32_SCB_CFSR_MUNSTKERR_SHIFT             3u
#define S32_SCB_CFSR_MUNSTKERR_WIDTH             1u
#define S32_SCB_CFSR_MUNSTKERR(x)                (((uint32)(((uint32)(x))<<S32_SCB_CFSR_MUNSTKERR_SHIFT))&S32_SCB_CFSR_MUNSTKERR_MASK)
#define S32_SCB_CFSR_MSTKERR_MASK                0x10u
#define S32_SCB_CFSR_MSTKERR_SHIFT               4u
#define S32_SCB_CFSR_MSTKERR_WIDTH               1u
#define S32_SCB_CFSR_MSTKERR(x)                  (((uint32)(((uint32)(x))<<S32_SCB_CFSR_MSTKERR_SHIFT))&S32_SCB_CFSR_MSTKERR_MASK)
#define S32_SCB_CFSR_MLSPERR_MASK                0x20u
#define S32_SCB_CFSR_MLSPERR_SHIFT               5u
#define S32_SCB_CFSR_MLSPERR_WIDTH               1u
#define S32_SCB_CFSR_MLSPERR(x)                  (((uint32)(((uint32)(x))<<S32_SCB_CFSR_MLSPERR_SHIFT))&S32_SCB_CFSR_MLSPERR_MASK)
#define S32_SCB_CFSR_MMARVALID_MASK              0x80u
#define S32_SCB_CFSR_MMARVALID_SHIFT             7u
#define S32_SCB_CFSR_MMARVALID_WIDTH             1u
#define S32_SCB_CFSR_MMARVALID(x)                (((uint32)(((uint32)(x))<<S32_SCB_CFSR_MMARVALID_SHIFT))&S32_SCB_CFSR_MMARVALID_MASK)
#define S32_SCB_CFSR_IBUSERR_MASK                0x100u
#define S32_SCB_CFSR_IBUSERR_SHIFT               8u
#define S32_SCB_CFSR_IBUSERR_WIDTH               1u
#define S32_SCB_CFSR_IBUSERR(x)                  (((uint32)(((uint32)(x))<<S32_SCB_CFSR_IBUSERR_SHIFT))&S32_SCB_CFSR_IBUSERR_MASK)
#define S32_SCB_CFSR_PRECISERR_MASK              0x200u
#define S32_SCB_CFSR_PRECISERR_SHIFT             9u
#define S32_SCB_CFSR_PRECISERR_WIDTH             1u
#define S32_SCB_CFSR_PRECISERR(x)                (((uint32)(((uint32)(x))<<S32_SCB_CFSR_PRECISERR_SHIFT))&S32_SCB_CFSR_PRECISERR_MASK)
#define S32_SCB_CFSR_IMPRECISERR_MASK            0x400u
#define S32_SCB_CFSR_IMPRECISERR_SHIFT           10u
#define S32_SCB_CFSR_IMPRECISERR_WIDTH           1u
#define S32_SCB_CFSR_IMPRECISERR(x)              (((uint32)(((uint32)(x))<<S32_SCB_CFSR_IMPRECISERR_SHIFT))&S32_SCB_CFSR_IMPRECISERR_MASK)
#define S32_SCB_CFSR_UNSTKERR_MASK               0x800u
#define S32_SCB_CFSR_UNSTKERR_SHIFT              11u
#define S32_SCB_CFSR_UNSTKERR_WIDTH              1u
#define S32_SCB_CFSR_UNSTKERR(x)                 (((uint32)(((uint32)(x))<<S32_SCB_CFSR_UNSTKERR_SHIFT))&S32_SCB_CFSR_UNSTKERR_MASK)
#define S32_SCB_CFSR_STKERR_MASK                 0x1000u
#define S32_SCB_CFSR_STKERR_SHIFT                12u
#define S32_SCB_CFSR_STKERR_WIDTH                1u
#define S32_SCB_CFSR_STKERR(x)                   (((uint32)(((uint32)(x))<<S32_SCB_CFSR_STKERR_SHIFT))&S32_SCB_CFSR_STKERR_MASK)
#define S32_SCB_CFSR_LSPERR_MASK                 0x2000u
#define S32_SCB_CFSR_LSPERR_SHIFT                13u
#define S32_SCB_CFSR_LSPERR_WIDTH                1u
#define S32_SCB_CFSR_LSPERR(x)                   (((uint32)(((uint32)(x))<<S32_SCB_CFSR_LSPERR_SHIFT))&S32_SCB_CFSR_LSPERR_MASK)
#define S32_SCB_CFSR_BFARVALID_MASK              0x8000u
#define S32_SCB_CFSR_BFARVALID_SHIFT             15u
#define S32_SCB_CFSR_BFARVALID_WIDTH             1u
#define S32_SCB_CFSR_BFARVALID(x)                (((uint32)(((uint32)(x))<<S32_SCB_CFSR_BFARVALID_SHIFT))&S32_SCB_CFSR_BFARVALID_MASK)
#define S32_SCB_CFSR_UNDEFINSTR_MASK             0x10000u
#define S32_SCB_CFSR_UNDEFINSTR_SHIFT            16u
#define S32_SCB_CFSR_UNDEFINSTR_WIDTH            1u
#define S32_SCB_CFSR_UNDEFINSTR(x)               (((uint32)(((uint32)(x))<<S32_SCB_CFSR_UNDEFINSTR_SHIFT))&S32_SCB_CFSR_UNDEFINSTR_MASK)
#define S32_SCB_CFSR_INVSTATE_MASK               0x20000u
#define S32_SCB_CFSR_INVSTATE_SHIFT              17u
#define S32_SCB_CFSR_INVSTATE_WIDTH              1u
#define S32_SCB_CFSR_INVSTATE(x)                 (((uint32)(((uint32)(x))<<S32_SCB_CFSR_INVSTATE_SHIFT))&S32_SCB_CFSR_INVSTATE_MASK)
#define S32_SCB_CFSR_INVPC_MASK                  0x40000u
#define S32_SCB_CFSR_INVPC_SHIFT                 18u
#define S32_SCB_CFSR_INVPC_WIDTH                 1u
#define S32_SCB_CFSR_INVPC(x)                    (((uint32)(((uint32)(x))<<S32_SCB_CFSR_INVPC_SHIFT))&S32_SCB_CFSR_INVPC_MASK)
#define S32_SCB_CFSR_NOCP_MASK                   0x80000u
#define S32_SCB_CFSR_NOCP_SHIFT                  19u
#define S32_SCB_CFSR_NOCP_WIDTH                  1u
#define S32_SCB_CFSR_NOCP(x)                     (((uint32)(((uint32)(x))<<S32_SCB_CFSR_NOCP_SHIFT))&S32_SCB_CFSR_NOCP_MASK)
#define S32_SCB_CFSR_UNALIGNED_MASK              0x1000000u
#define S32_SCB_CFSR_UNALIGNED_SHIFT             24u
#define S32_SCB_CFSR_UNALIGNED_WIDTH             1u
#define S32_SCB_CFSR_UNALIGNED(x)                (((uint32)(((uint32)(x))<<S32_SCB_CFSR_UNALIGNED_SHIFT))&S32_SCB_CFSR_UNALIGNED_MASK)
#define S32_SCB_CFSR_DIVBYZERO_MASK              0x2000000u
#define S32_SCB_CFSR_DIVBYZERO_SHIFT             25u
#define S32_SCB_CFSR_DIVBYZERO_WIDTH             1u
#define S32_SCB_CFSR_DIVBYZERO(x)                (((uint32)(((uint32)(x))<<S32_SCB_CFSR_DIVBYZERO_SHIFT))&S32_SCB_CFSR_DIVBYZERO_MASK)
/* HFSR Bit Fields */
#define S32_SCB_HFSR_VECTTBL_MASK                0x2u
#define S32_SCB_HFSR_VECTTBL_SHIFT               1u
#define S32_SCB_HFSR_VECTTBL_WIDTH               1u
#define S32_SCB_HFSR_VECTTBL(x)                  (((uint32)(((uint32)(x))<<S32_SCB_HFSR_VECTTBL_SHIFT))&S32_SCB_HFSR_VECTTBL_MASK)
#define S32_SCB_HFSR_FORCED_MASK                 0x40000000u
#define S32_SCB_HFSR_FORCED_SHIFT                30u
#define S32_SCB_HFSR_FORCED_WIDTH                1u
#define S32_SCB_HFSR_FORCED(x)                   (((uint32)(((uint32)(x))<<S32_SCB_HFSR_FORCED_SHIFT))&S32_SCB_HFSR_FORCED_MASK)
#define S32_SCB_HFSR_DEBUGEVT_MASK               0x80000000u
#define S32_SCB_HFSR_DEBUGEVT_SHIFT              31u
#define S32_SCB_HFSR_DEBUGEVT_WIDTH              1u
#define S32_SCB_HFSR_DEBUGEVT(x)                 (((uint32)(((uint32)(x))<<S32_SCB_HFSR_DEBUGEVT_SHIFT))&S32_SCB_HFSR_DEBUGEVT_MASK)
/* DFSR Bit Fields */
#define S32_SCB_DFSR_HALTED_MASK                 0x1u
#define S32_SCB_DFSR_HALTED_SHIFT                0u
#define S32_SCB_DFSR_HALTED_WIDTH                1u
#define S32_SCB_DFSR_HALTED(x)                   (((uint32)(((uint32)(x))<<S32_SCB_DFSR_HALTED_SHIFT))&S32_SCB_DFSR_HALTED_MASK)
#define S32_SCB_DFSR_BKPT_MASK                   0x2u
#define S32_SCB_DFSR_BKPT_SHIFT                  1u
#define S32_SCB_DFSR_BKPT_WIDTH                  1u
#define S32_SCB_DFSR_BKPT(x)                     (((uint32)(((uint32)(x))<<S32_SCB_DFSR_BKPT_SHIFT))&S32_SCB_DFSR_BKPT_MASK)
#define S32_SCB_DFSR_DWTTRAP_MASK                0x4u
#define S32_SCB_DFSR_DWTTRAP_SHIFT               2u
#define S32_SCB_DFSR_DWTTRAP_WIDTH               1u
#define S32_SCB_DFSR_DWTTRAP(x)                  (((uint32)(((uint32)(x))<<S32_SCB_DFSR_DWTTRAP_SHIFT))&S32_SCB_DFSR_DWTTRAP_MASK)
#define S32_SCB_DFSR_VCATCH_MASK                 0x8u
#define S32_SCB_DFSR_VCATCH_SHIFT                3u
#define S32_SCB_DFSR_VCATCH_WIDTH                1u
#define S32_SCB_DFSR_VCATCH(x)                   (((uint32)(((uint32)(x))<<S32_SCB_DFSR_VCATCH_SHIFT))&S32_SCB_DFSR_VCATCH_MASK)
#define S32_SCB_DFSR_EXTERNAL_MASK               0x10u
#define S32_SCB_DFSR_EXTERNAL_SHIFT              4u
#define S32_SCB_DFSR_EXTERNAL_WIDTH              1u
#define S32_SCB_DFSR_EXTERNAL(x)                 (((uint32)(((uint32)(x))<<S32_SCB_DFSR_EXTERNAL_SHIFT))&S32_SCB_DFSR_EXTERNAL_MASK)
/* MMFAR Bit Fields */
#define S32_SCB_MMFAR_ADDRESS_MASK               0xFFFFFFFFu
#define S32_SCB_MMFAR_ADDRESS_SHIFT              0u
#define S32_SCB_MMFAR_ADDRESS_WIDTH              32u
#define S32_SCB_MMFAR_ADDRESS(x)                 (((uint32)(((uint32)(x))<<S32_SCB_MMFAR_ADDRESS_SHIFT))&S32_SCB_MMFAR_ADDRESS_MASK)
/* BFAR Bit Fields */
#define S32_SCB_BFAR_ADDRESS_MASK                0xFFFFFFFFu
#define S32_SCB_BFAR_ADDRESS_SHIFT               0u
#define S32_SCB_BFAR_ADDRESS_WIDTH               32u
#define S32_SCB_BFAR_ADDRESS(x)                  (((uint32)(((uint32)(x))<<S32_SCB_BFAR_ADDRESS_SHIFT))&S32_SCB_BFAR_ADDRESS_MASK)
/* AFSR Bit Fields */
#define S32_SCB_AFSR_AUXFAULT_MASK               0xFFFFFFFFu
#define S32_SCB_AFSR_AUXFAULT_SHIFT              0u
#define S32_SCB_AFSR_AUXFAULT_WIDTH              32u
#define S32_SCB_AFSR_AUXFAULT(x)                 (((uint32)(((uint32)(x))<<S32_SCB_AFSR_AUXFAULT_SHIFT))&S32_SCB_AFSR_AUXFAULT_MASK)
/* CPACR Bit Fields */
#define S32_SCB_CPACR_CP10_MASK                  0x300000u
#define S32_SCB_CPACR_CP10_SHIFT                 20u
#define S32_SCB_CPACR_CP10_WIDTH                 2u
#define S32_SCB_CPACR_CP10(x)                    (((uint32)(((uint32)(x))<<S32_SCB_CPACR_CP10_SHIFT))&S32_SCB_CPACR_CP10_MASK)
#define S32_SCB_CPACR_CP11_MASK                  0xC00000u
#define S32_SCB_CPACR_CP11_SHIFT                 22u
#define S32_SCB_CPACR_CP11_WIDTH                 2u
#define S32_SCB_CPACR_CP11(x)                    (((uint32)(((uint32)(x))<<S32_SCB_CPACR_CP11_SHIFT))&S32_SCB_CPACR_CP11_MASK)
/* FPCCR Bit Fields */
#define S32_SCB_FPCCR_LSPACT_MASK                0x1u
#define S32_SCB_FPCCR_LSPACT_SHIFT               0u
#define S32_SCB_FPCCR_LSPACT_WIDTH               1u
#define S32_SCB_FPCCR_LSPACT(x)                  (((uint32)(((uint32)(x))<<S32_SCB_FPCCR_LSPACT_SHIFT))&S32_SCB_FPCCR_LSPACT_MASK)
#define S32_SCB_FPCCR_USER_MASK                  0x2u
#define S32_SCB_FPCCR_USER_SHIFT                 1u
#define S32_SCB_FPCCR_USER_WIDTH                 1u
#define S32_SCB_FPCCR_USER(x)                    (((uint32)(((uint32)(x))<<S32_SCB_FPCCR_USER_SHIFT))&S32_SCB_FPCCR_USER_MASK)
#define S32_SCB_FPCCR_THREAD_MASK                0x8u
#define S32_SCB_FPCCR_THREAD_SHIFT               3u
#define S32_SCB_FPCCR_THREAD_WIDTH               1u
#define S32_SCB_FPCCR_THREAD(x)                  (((uint32)(((uint32)(x))<<S32_SCB_FPCCR_THREAD_SHIFT))&S32_SCB_FPCCR_THREAD_MASK)
#define S32_SCB_FPCCR_HFRDY_MASK                 0x10u
#define S32_SCB_FPCCR_HFRDY_SHIFT                4u
#define S32_SCB_FPCCR_HFRDY_WIDTH                1u
#define S32_SCB_FPCCR_HFRDY(x)                   (((uint32)(((uint32)(x))<<S32_SCB_FPCCR_HFRDY_SHIFT))&S32_SCB_FPCCR_HFRDY_MASK)
#define S32_SCB_FPCCR_MMRDY_MASK                 0x20u
#define S32_SCB_FPCCR_MMRDY_SHIFT                5u
#define S32_SCB_FPCCR_MMRDY_WIDTH                1u
#define S32_SCB_FPCCR_MMRDY(x)                   (((uint32)(((uint32)(x))<<S32_SCB_FPCCR_MMRDY_SHIFT))&S32_SCB_FPCCR_MMRDY_MASK)
#define S32_SCB_FPCCR_BFRDY_MASK                 0x40u
#define S32_SCB_FPCCR_BFRDY_SHIFT                6u
#define S32_SCB_FPCCR_BFRDY_WIDTH                1u
#define S32_SCB_FPCCR_BFRDY(x)                   (((uint32)(((uint32)(x))<<S32_SCB_FPCCR_BFRDY_SHIFT))&S32_SCB_FPCCR_BFRDY_MASK)
#define S32_SCB_FPCCR_MONRDY_MASK                0x100u
#define S32_SCB_FPCCR_MONRDY_SHIFT               8u
#define S32_SCB_FPCCR_MONRDY_WIDTH               1u
#define S32_SCB_FPCCR_MONRDY(x)                  (((uint32)(((uint32)(x))<<S32_SCB_FPCCR_MONRDY_SHIFT))&S32_SCB_FPCCR_MONRDY_MASK)
#define S32_SCB_FPCCR_LSPEN_MASK                 0x40000000u
#define S32_SCB_FPCCR_LSPEN_SHIFT                30u
#define S32_SCB_FPCCR_LSPEN_WIDTH                1u
#define S32_SCB_FPCCR_LSPEN(x)                   (((uint32)(((uint32)(x))<<S32_SCB_FPCCR_LSPEN_SHIFT))&S32_SCB_FPCCR_LSPEN_MASK)
#define S32_SCB_FPCCR_ASPEN_MASK                 0x80000000u
#define S32_SCB_FPCCR_ASPEN_SHIFT                31u
#define S32_SCB_FPCCR_ASPEN_WIDTH                1u
#define S32_SCB_FPCCR_ASPEN(x)                   (((uint32)(((uint32)(x))<<S32_SCB_FPCCR_ASPEN_SHIFT))&S32_SCB_FPCCR_ASPEN_MASK)
/* FPCAR Bit Fields */
#define S32_SCB_FPCAR_ADDRESS_MASK               0xFFFFFFF8u
#define S32_SCB_FPCAR_ADDRESS_SHIFT              3u
#define S32_SCB_FPCAR_ADDRESS_WIDTH              29u
#define S32_SCB_FPCAR_ADDRESS(x)                 (((uint32)(((uint32)(x))<<S32_SCB_FPCAR_ADDRESS_SHIFT))&S32_SCB_FPCAR_ADDRESS_MASK)
/* FPDSCR Bit Fields */
#define S32_SCB_FPDSCR_RMode_MASK                0xC00000u
#define S32_SCB_FPDSCR_RMode_SHIFT               22u
#define S32_SCB_FPDSCR_RMode_WIDTH               2u
#define S32_SCB_FPDSCR_RMode(x)                  (((uint32)(((uint32)(x))<<S32_SCB_FPDSCR_RMode_SHIFT))&S32_SCB_FPDSCR_RMode_MASK)
#define S32_SCB_FPDSCR_FZ_MASK                   0x1000000u
#define S32_SCB_FPDSCR_FZ_SHIFT                  24u
#define S32_SCB_FPDSCR_FZ_WIDTH                  1u
#define S32_SCB_FPDSCR_FZ(x)                     (((uint32)(((uint32)(x))<<S32_SCB_FPDSCR_FZ_SHIFT))&S32_SCB_FPDSCR_FZ_MASK)
#define S32_SCB_FPDSCR_DN_MASK                   0x2000000u
#define S32_SCB_FPDSCR_DN_SHIFT                  25u
#define S32_SCB_FPDSCR_DN_WIDTH                  1u
#define S32_SCB_FPDSCR_DN(x)                     (((uint32)(((uint32)(x))<<S32_SCB_FPDSCR_DN_SHIFT))&S32_SCB_FPDSCR_DN_MASK)
#define S32_SCB_FPDSCR_AHP_MASK                  0x4000000u
#define S32_SCB_FPDSCR_AHP_SHIFT                 26u
#define S32_SCB_FPDSCR_AHP_WIDTH                 1u
#define S32_SCB_FPDSCR_AHP(x)                    (((uint32)(((uint32)(x))<<S32_SCB_FPDSCR_AHP_SHIFT))&S32_SCB_FPDSCR_AHP_MASK)

/*!
 * @}
 */ /* end of group S32_SCB_Register_Masks */


/*!
 * @}
 */ /* end of group S32_SCB_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- S32_SysTick Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S32_SysTick_Peripheral_Access_Layer S32_SysTick Peripheral Access Layer
 * @{
 */


/** S32_SysTick - Size of Registers Arrays */

/** S32_SysTick - Register Layout Typedef */
typedef struct {
  __IO uint32 CSR;                               /**< SysTick Control and Status Register, offset: 0x0 */
  __IO uint32 RVR;                               /**< SysTick Reload Value Register, offset: 0x4 */
  __IO uint32 CVR;                               /**< SysTick Current Value Register, offset: 0x8 */
  __I  uint32 CALIB;                             /**< SysTick Calibration Value Register, offset: 0xC */
} S32_SysTick_Type, *S32_SysTick_MemMapPtr;

 /** Number of instances of the S32_SysTick module. */
#define S32_SysTick_INSTANCE_COUNT               (1u)


/* S32_SysTick - Peripheral instance base addresses */
/** Peripheral S32_SysTick base address */
#define S32_SysTick_BASE                         (0xE000E010u)
/** Peripheral S32_SysTick base pointer */
#define S32_SysTick                              ((S32_SysTick_Type *)S32_SysTick_BASE)
/** Array initializer of S32_SysTick peripheral base addresses */
#define S32_SysTick_BASE_ADDRS                   { S32_SysTick_BASE }
/** Array initializer of S32_SysTick peripheral base pointers */
#define S32_SysTick_BASE_PTRS                    { S32_SysTick }
 /** Number of interrupt vector arrays for the S32_SysTick module. */
#define S32_SysTick_IRQS_ARR_COUNT               (1u)
 /** Number of interrupt channels for the S32_SysTick module. */
#define S32_SysTick_IRQS_CH_COUNT                (1u)
/** Interrupt vectors for the S32_SysTick peripheral type */
#define S32_SysTick_IRQS                         { SysTick_IRQn }

/* ----------------------------------------------------------------------------
   -- S32_SysTick Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S32_SysTick_Register_Masks S32_SysTick Register Masks
 * @{
 */

/* CSR Bit Fields */
#define S32_SysTick_CSR_ENABLE_MASK              0x1u
#define S32_SysTick_CSR_ENABLE_SHIFT             0u
#define S32_SysTick_CSR_ENABLE_WIDTH             1u
#define S32_SysTick_CSR_ENABLE(x)                (((uint32)(((uint32)(x))<<S32_SysTick_CSR_ENABLE_SHIFT))&S32_SysTick_CSR_ENABLE_MASK)
#define S32_SysTick_CSR_TICKINT_MASK             0x2u
#define S32_SysTick_CSR_TICKINT_SHIFT            1u
#define S32_SysTick_CSR_TICKINT_WIDTH            1u
#define S32_SysTick_CSR_TICKINT(x)               (((uint32)(((uint32)(x))<<S32_SysTick_CSR_TICKINT_SHIFT))&S32_SysTick_CSR_TICKINT_MASK)
#define S32_SysTick_CSR_CLKSOURCE_MASK           0x4u
#define S32_SysTick_CSR_CLKSOURCE_SHIFT          2u
#define S32_SysTick_CSR_CLKSOURCE_WIDTH          1u
#define S32_SysTick_CSR_CLKSOURCE(x)             (((uint32)(((uint32)(x))<<S32_SysTick_CSR_CLKSOURCE_SHIFT))&S32_SysTick_CSR_CLKSOURCE_MASK)
#define S32_SysTick_CSR_COUNTFLAG_MASK           0x10000u
#define S32_SysTick_CSR_COUNTFLAG_SHIFT          16u
#define S32_SysTick_CSR_COUNTFLAG_WIDTH          1u
#define S32_SysTick_CSR_COUNTFLAG(x)             (((uint32)(((uint32)(x))<<S32_SysTick_CSR_COUNTFLAG_SHIFT))&S32_SysTick_CSR_COUNTFLAG_MASK)
/* RVR Bit Fields */
#define S32_SysTick_RVR_RELOAD_MASK              0xFFFFFFu
#define S32_SysTick_RVR_RELOAD_SHIFT             0u
#define S32_SysTick_RVR_RELOAD_WIDTH             24u
#define S32_SysTick_RVR_RELOAD(x)                (((uint32)(((uint32)(x))<<S32_SysTick_RVR_RELOAD_SHIFT))&S32_SysTick_RVR_RELOAD_MASK)
/* CVR Bit Fields */
#define S32_SysTick_CVR_CURRENT_MASK             0xFFFFFFu
#define S32_SysTick_CVR_CURRENT_SHIFT            0u
#define S32_SysTick_CVR_CURRENT_WIDTH            24u
#define S32_SysTick_CVR_CURRENT(x)               (((uint32)(((uint32)(x))<<S32_SysTick_CVR_CURRENT_SHIFT))&S32_SysTick_CVR_CURRENT_MASK)
/* CALIB Bit Fields */
#define S32_SysTick_CALIB_TENMS_MASK             0xFFFFFFu
#define S32_SysTick_CALIB_TENMS_SHIFT            0u
#define S32_SysTick_CALIB_TENMS_WIDTH            24u
#define S32_SysTick_CALIB_TENMS(x)               (((uint32)(((uint32)(x))<<S32_SysTick_CALIB_TENMS_SHIFT))&S32_SysTick_CALIB_TENMS_MASK)
#define S32_SysTick_CALIB_SKEW_MASK              0x40000000u
#define S32_SysTick_CALIB_SKEW_SHIFT             30u
#define S32_SysTick_CALIB_SKEW_WIDTH             1u
#define S32_SysTick_CALIB_SKEW(x)                (((uint32)(((uint32)(x))<<S32_SysTick_CALIB_SKEW_SHIFT))&S32_SysTick_CALIB_SKEW_MASK)
#define S32_SysTick_CALIB_NOREF_MASK             0x80000000u
#define S32_SysTick_CALIB_NOREF_SHIFT            31u
#define S32_SysTick_CALIB_NOREF_WIDTH            1u
#define S32_SysTick_CALIB_NOREF(x)               (((uint32)(((uint32)(x))<<S32_SysTick_CALIB_NOREF_SHIFT))&S32_SysTick_CALIB_NOREF_MASK)

/*!
 * @}
 */ /* end of group S32_SysTick_Register_Masks */


/*!
 * @}
 */ /* end of group S32_SysTick_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SCG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCG_Peripheral_Access_Layer SCG Peripheral Access Layer
 * @{
 */


/** SCG - Size of Registers Arrays */

/** SCG - Register Layout Typedef */
typedef struct {
  __I  uint32 VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32 PARAM;                             /**< Parameter Register, offset: 0x4 */
       uint8 RESERVED_0[8];
  __I  uint32 CSR;                               /**< Clock Status Register, offset: 0x10 */
  __IO uint32 RCCR;                              /**< Run Clock Control Register, offset: 0x14 */
  __IO uint32 VCCR;                              /**< VLPR Clock Control Register, offset: 0x18 */
  __IO uint32 HCCR;                              /**< HSRUN Clock Control Register, offset: 0x1C */
  __IO uint32 CLKOUTCNFG;                        /**< SCG CLKOUT Configuration Register, offset: 0x20 */
       uint8 RESERVED_1[220];
  __IO uint32 SOSCCSR;                           /**< System OSC Control Status Register, offset: 0x100 */
  __IO uint32 SOSCDIV;                           /**< System OSC Divide Register, offset: 0x104 */
  __IO uint32 SOSCCFG;                           /**< System Oscillator Configuration Register, offset: 0x108 */
       uint8 RESERVED_2[244];
  __IO uint32 SIRCCSR;                           /**< Slow IRC Control Status Register, offset: 0x200 */
  __IO uint32 SIRCDIV;                           /**< Slow IRC Divide Register, offset: 0x204 */
  __IO uint32 SIRCCFG;                           /**< Slow IRC Configuration Register, offset: 0x208 */
       uint8 RESERVED_3[244];
  __IO uint32 FIRCCSR;                           /**< Fast IRC Control Status Register, offset: 0x300 */
  __IO uint32 FIRCDIV;                           /**< Fast IRC Divide Register, offset: 0x304 */
  __IO uint32 FIRCCFG;                           /**< Fast IRC Configuration Register, offset: 0x308 */
       uint8 RESERVED_4[756];
  __IO uint32 SPLLCSR;                           /**< System PLL Control Status Register, offset: 0x600 */
  __IO uint32 SPLLDIV;                           /**< System PLL Divide Register, offset: 0x604 */
  __IO uint32 SPLLCFG;                           /**< System PLL Configuration Register, offset: 0x608 */
} SCG_Type, *SCG_MemMapPtr;

 /** Number of instances of the SCG module. */
#define SCG_INSTANCE_COUNT                       (1u)


/* SCG - Peripheral instance base addresses */
/** Peripheral SCG base address */
#define SCG_BASE                                 (0x40064000u)
/** Peripheral SCG base pointer */
#define SCG                                      ((SCG_Type *)SCG_BASE)
/** Array initializer of SCG peripheral base addresses */
#define SCG_BASE_ADDRS                           { SCG_BASE }
/** Array initializer of SCG peripheral base pointers */
#define SCG_BASE_PTRS                            { SCG }
 /** Number of interrupt vector arrays for the SCG module. */
#define SCG_IRQS_ARR_COUNT                       (1u)
 /** Number of interrupt channels for the SCG module. */
#define SCG_IRQS_CH_COUNT                        (1u)
/** Interrupt vectors for the SCG peripheral type */
#define SCG_IRQS                                 { SCG_IRQn }

/* ----------------------------------------------------------------------------
   -- SCG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCG_Register_Masks SCG Register Masks
 * @{
 */

/* VERID Bit Fields */
#define SCG_VERID_VERSION_MASK                   0xFFFFFFFFu
#define SCG_VERID_VERSION_SHIFT                  0u
#define SCG_VERID_VERSION_WIDTH                  32u
#define SCG_VERID_VERSION(x)                     (((uint32)(((uint32)(x))<<SCG_VERID_VERSION_SHIFT))&SCG_VERID_VERSION_MASK)
/* PARAM Bit Fields */
#define SCG_PARAM_CLKPRES_MASK                   0xFFu
#define SCG_PARAM_CLKPRES_SHIFT                  0u
#define SCG_PARAM_CLKPRES_WIDTH                  8u
#define SCG_PARAM_CLKPRES(x)                     (((uint32)(((uint32)(x))<<SCG_PARAM_CLKPRES_SHIFT))&SCG_PARAM_CLKPRES_MASK)
#define SCG_PARAM_DIVPRES_MASK                   0xF8000000u
#define SCG_PARAM_DIVPRES_SHIFT                  27u
#define SCG_PARAM_DIVPRES_WIDTH                  5u
#define SCG_PARAM_DIVPRES(x)                     (((uint32)(((uint32)(x))<<SCG_PARAM_DIVPRES_SHIFT))&SCG_PARAM_DIVPRES_MASK)
/* CSR Bit Fields */
#define SCG_CSR_DIVSLOW_MASK                     0xFu
#define SCG_CSR_DIVSLOW_SHIFT                    0u
#define SCG_CSR_DIVSLOW_WIDTH                    4u
#define SCG_CSR_DIVSLOW(x)                       (((uint32)(((uint32)(x))<<SCG_CSR_DIVSLOW_SHIFT))&SCG_CSR_DIVSLOW_MASK)
#define SCG_CSR_DIVBUS_MASK                      0xF0u
#define SCG_CSR_DIVBUS_SHIFT                     4u
#define SCG_CSR_DIVBUS_WIDTH                     4u
#define SCG_CSR_DIVBUS(x)                        (((uint32)(((uint32)(x))<<SCG_CSR_DIVBUS_SHIFT))&SCG_CSR_DIVBUS_MASK)
#define SCG_CSR_DIVCORE_MASK                     0xF0000u
#define SCG_CSR_DIVCORE_SHIFT                    16u
#define SCG_CSR_DIVCORE_WIDTH                    4u
#define SCG_CSR_DIVCORE(x)                       (((uint32)(((uint32)(x))<<SCG_CSR_DIVCORE_SHIFT))&SCG_CSR_DIVCORE_MASK)
#define SCG_CSR_SCS_MASK                         0xF000000u
#define SCG_CSR_SCS_SHIFT                        24u
#define SCG_CSR_SCS_WIDTH                        4u
#define SCG_CSR_SCS(x)                           (((uint32)(((uint32)(x))<<SCG_CSR_SCS_SHIFT))&SCG_CSR_SCS_MASK)
/* RCCR Bit Fields */
#define SCG_RCCR_DIVSLOW_MASK                    0xFu
#define SCG_RCCR_DIVSLOW_SHIFT                   0u
#define SCG_RCCR_DIVSLOW_WIDTH                   4u
#define SCG_RCCR_DIVSLOW(x)                      (((uint32)(((uint32)(x))<<SCG_RCCR_DIVSLOW_SHIFT))&SCG_RCCR_DIVSLOW_MASK)
#define SCG_RCCR_DIVBUS_MASK                     0xF0u
#define SCG_RCCR_DIVBUS_SHIFT                    4u
#define SCG_RCCR_DIVBUS_WIDTH                    4u
#define SCG_RCCR_DIVBUS(x)                       (((uint32)(((uint32)(x))<<SCG_RCCR_DIVBUS_SHIFT))&SCG_RCCR_DIVBUS_MASK)
#define SCG_RCCR_DIVCORE_MASK                    0xF0000u
#define SCG_RCCR_DIVCORE_SHIFT                   16u
#define SCG_RCCR_DIVCORE_WIDTH                   4u
#define SCG_RCCR_DIVCORE(x)                      (((uint32)(((uint32)(x))<<SCG_RCCR_DIVCORE_SHIFT))&SCG_RCCR_DIVCORE_MASK)
#define SCG_RCCR_SCS_MASK                        0xF000000u
#define SCG_RCCR_SCS_SHIFT                       24u
#define SCG_RCCR_SCS_WIDTH                       4u
#define SCG_RCCR_SCS(x)                          (((uint32)(((uint32)(x))<<SCG_RCCR_SCS_SHIFT))&SCG_RCCR_SCS_MASK)
/* VCCR Bit Fields */
#define SCG_VCCR_DIVSLOW_MASK                    0xFu
#define SCG_VCCR_DIVSLOW_SHIFT                   0u
#define SCG_VCCR_DIVSLOW_WIDTH                   4u
#define SCG_VCCR_DIVSLOW(x)                      (((uint32)(((uint32)(x))<<SCG_VCCR_DIVSLOW_SHIFT))&SCG_VCCR_DIVSLOW_MASK)
#define SCG_VCCR_DIVBUS_MASK                     0xF0u
#define SCG_VCCR_DIVBUS_SHIFT                    4u
#define SCG_VCCR_DIVBUS_WIDTH                    4u
#define SCG_VCCR_DIVBUS(x)                       (((uint32)(((uint32)(x))<<SCG_VCCR_DIVBUS_SHIFT))&SCG_VCCR_DIVBUS_MASK)
#define SCG_VCCR_DIVCORE_MASK                    0xF0000u
#define SCG_VCCR_DIVCORE_SHIFT                   16u
#define SCG_VCCR_DIVCORE_WIDTH                   4u
#define SCG_VCCR_DIVCORE(x)                      (((uint32)(((uint32)(x))<<SCG_VCCR_DIVCORE_SHIFT))&SCG_VCCR_DIVCORE_MASK)
#define SCG_VCCR_SCS_MASK                        0xF000000u
#define SCG_VCCR_SCS_SHIFT                       24u
#define SCG_VCCR_SCS_WIDTH                       4u
#define SCG_VCCR_SCS(x)                          (((uint32)(((uint32)(x))<<SCG_VCCR_SCS_SHIFT))&SCG_VCCR_SCS_MASK)
/* HCCR Bit Fields */
#define SCG_HCCR_DIVSLOW_MASK                    0xFu
#define SCG_HCCR_DIVSLOW_SHIFT                   0u
#define SCG_HCCR_DIVSLOW_WIDTH                   4u
#define SCG_HCCR_DIVSLOW(x)                      (((uint32)(((uint32)(x))<<SCG_HCCR_DIVSLOW_SHIFT))&SCG_HCCR_DIVSLOW_MASK)
#define SCG_HCCR_DIVBUS_MASK                     0xF0u
#define SCG_HCCR_DIVBUS_SHIFT                    4u
#define SCG_HCCR_DIVBUS_WIDTH                    4u
#define SCG_HCCR_DIVBUS(x)                       (((uint32)(((uint32)(x))<<SCG_HCCR_DIVBUS_SHIFT))&SCG_HCCR_DIVBUS_MASK)
#define SCG_HCCR_DIVCORE_MASK                    0xF0000u
#define SCG_HCCR_DIVCORE_SHIFT                   16u
#define SCG_HCCR_DIVCORE_WIDTH                   4u
#define SCG_HCCR_DIVCORE(x)                      (((uint32)(((uint32)(x))<<SCG_HCCR_DIVCORE_SHIFT))&SCG_HCCR_DIVCORE_MASK)
#define SCG_HCCR_SCS_MASK                        0xF000000u
#define SCG_HCCR_SCS_SHIFT                       24u
#define SCG_HCCR_SCS_WIDTH                       4u
#define SCG_HCCR_SCS(x)                          (((uint32)(((uint32)(x))<<SCG_HCCR_SCS_SHIFT))&SCG_HCCR_SCS_MASK)
/* CLKOUTCNFG Bit Fields */
#define SCG_CLKOUTCNFG_CLKOUTSEL_MASK            0xF000000u
#define SCG_CLKOUTCNFG_CLKOUTSEL_SHIFT           24u
#define SCG_CLKOUTCNFG_CLKOUTSEL_WIDTH           4u
#define SCG_CLKOUTCNFG_CLKOUTSEL(x)              (((uint32)(((uint32)(x))<<SCG_CLKOUTCNFG_CLKOUTSEL_SHIFT))&SCG_CLKOUTCNFG_CLKOUTSEL_MASK)
/* SOSCCSR Bit Fields */
#define SCG_SOSCCSR_SOSCEN_MASK                  0x1u
#define SCG_SOSCCSR_SOSCEN_SHIFT                 0u
#define SCG_SOSCCSR_SOSCEN_WIDTH                 1u
#define SCG_SOSCCSR_SOSCEN(x)                    (((uint32)(((uint32)(x))<<SCG_SOSCCSR_SOSCEN_SHIFT))&SCG_SOSCCSR_SOSCEN_MASK)
#define SCG_SOSCCSR_SOSCCM_MASK                  0x10000u
#define SCG_SOSCCSR_SOSCCM_SHIFT                 16u
#define SCG_SOSCCSR_SOSCCM_WIDTH                 1u
#define SCG_SOSCCSR_SOSCCM(x)                    (((uint32)(((uint32)(x))<<SCG_SOSCCSR_SOSCCM_SHIFT))&SCG_SOSCCSR_SOSCCM_MASK)
#define SCG_SOSCCSR_SOSCCMRE_MASK                0x20000u
#define SCG_SOSCCSR_SOSCCMRE_SHIFT               17u
#define SCG_SOSCCSR_SOSCCMRE_WIDTH               1u
#define SCG_SOSCCSR_SOSCCMRE(x)                  (((uint32)(((uint32)(x))<<SCG_SOSCCSR_SOSCCMRE_SHIFT))&SCG_SOSCCSR_SOSCCMRE_MASK)
#define SCG_SOSCCSR_LK_MASK                      0x800000u
#define SCG_SOSCCSR_LK_SHIFT                     23u
#define SCG_SOSCCSR_LK_WIDTH                     1u
#define SCG_SOSCCSR_LK(x)                        (((uint32)(((uint32)(x))<<SCG_SOSCCSR_LK_SHIFT))&SCG_SOSCCSR_LK_MASK)
#define SCG_SOSCCSR_SOSCVLD_MASK                 0x1000000u
#define SCG_SOSCCSR_SOSCVLD_SHIFT                24u
#define SCG_SOSCCSR_SOSCVLD_WIDTH                1u
#define SCG_SOSCCSR_SOSCVLD(x)                   (((uint32)(((uint32)(x))<<SCG_SOSCCSR_SOSCVLD_SHIFT))&SCG_SOSCCSR_SOSCVLD_MASK)
#define SCG_SOSCCSR_SOSCSEL_MASK                 0x2000000u
#define SCG_SOSCCSR_SOSCSEL_SHIFT                25u
#define SCG_SOSCCSR_SOSCSEL_WIDTH                1u
#define SCG_SOSCCSR_SOSCSEL(x)                   (((uint32)(((uint32)(x))<<SCG_SOSCCSR_SOSCSEL_SHIFT))&SCG_SOSCCSR_SOSCSEL_MASK)
#define SCG_SOSCCSR_SOSCERR_MASK                 0x4000000u
#define SCG_SOSCCSR_SOSCERR_SHIFT                26u
#define SCG_SOSCCSR_SOSCERR_WIDTH                1u
#define SCG_SOSCCSR_SOSCERR(x)                   (((uint32)(((uint32)(x))<<SCG_SOSCCSR_SOSCERR_SHIFT))&SCG_SOSCCSR_SOSCERR_MASK)
/* SOSCDIV Bit Fields */
#define SCG_SOSCDIV_SOSCDIV1_MASK                0x7u
#define SCG_SOSCDIV_SOSCDIV1_SHIFT               0u
#define SCG_SOSCDIV_SOSCDIV1_WIDTH               3u
#define SCG_SOSCDIV_SOSCDIV1(x)                  (((uint32)(((uint32)(x))<<SCG_SOSCDIV_SOSCDIV1_SHIFT))&SCG_SOSCDIV_SOSCDIV1_MASK)
#define SCG_SOSCDIV_SOSCDIV2_MASK                0x700u
#define SCG_SOSCDIV_SOSCDIV2_SHIFT               8u
#define SCG_SOSCDIV_SOSCDIV2_WIDTH               3u
#define SCG_SOSCDIV_SOSCDIV2(x)                  (((uint32)(((uint32)(x))<<SCG_SOSCDIV_SOSCDIV2_SHIFT))&SCG_SOSCDIV_SOSCDIV2_MASK)
/* SOSCCFG Bit Fields */
#define SCG_SOSCCFG_EREFS_MASK                   0x4u
#define SCG_SOSCCFG_EREFS_SHIFT                  2u
#define SCG_SOSCCFG_EREFS_WIDTH                  1u
#define SCG_SOSCCFG_EREFS(x)                     (((uint32)(((uint32)(x))<<SCG_SOSCCFG_EREFS_SHIFT))&SCG_SOSCCFG_EREFS_MASK)
#define SCG_SOSCCFG_HGO_MASK                     0x8u
#define SCG_SOSCCFG_HGO_SHIFT                    3u
#define SCG_SOSCCFG_HGO_WIDTH                    1u
#define SCG_SOSCCFG_HGO(x)                       (((uint32)(((uint32)(x))<<SCG_SOSCCFG_HGO_SHIFT))&SCG_SOSCCFG_HGO_MASK)
#define SCG_SOSCCFG_RANGE_MASK                   0x30u
#define SCG_SOSCCFG_RANGE_SHIFT                  4u
#define SCG_SOSCCFG_RANGE_WIDTH                  2u
#define SCG_SOSCCFG_RANGE(x)                     (((uint32)(((uint32)(x))<<SCG_SOSCCFG_RANGE_SHIFT))&SCG_SOSCCFG_RANGE_MASK)
/* SIRCCSR Bit Fields */
#define SCG_SIRCCSR_SIRCEN_MASK                  0x1u
#define SCG_SIRCCSR_SIRCEN_SHIFT                 0u
#define SCG_SIRCCSR_SIRCEN_WIDTH                 1u
#define SCG_SIRCCSR_SIRCEN(x)                    (((uint32)(((uint32)(x))<<SCG_SIRCCSR_SIRCEN_SHIFT))&SCG_SIRCCSR_SIRCEN_MASK)
#define SCG_SIRCCSR_SIRCSTEN_MASK                0x2u
#define SCG_SIRCCSR_SIRCSTEN_SHIFT               1u
#define SCG_SIRCCSR_SIRCSTEN_WIDTH               1u
#define SCG_SIRCCSR_SIRCSTEN(x)                  (((uint32)(((uint32)(x))<<SCG_SIRCCSR_SIRCSTEN_SHIFT))&SCG_SIRCCSR_SIRCSTEN_MASK)
#define SCG_SIRCCSR_SIRCLPEN_MASK                0x4u
#define SCG_SIRCCSR_SIRCLPEN_SHIFT               2u
#define SCG_SIRCCSR_SIRCLPEN_WIDTH               1u
#define SCG_SIRCCSR_SIRCLPEN(x)                  (((uint32)(((uint32)(x))<<SCG_SIRCCSR_SIRCLPEN_SHIFT))&SCG_SIRCCSR_SIRCLPEN_MASK)
#define SCG_SIRCCSR_LK_MASK                      0x800000u
#define SCG_SIRCCSR_LK_SHIFT                     23u
#define SCG_SIRCCSR_LK_WIDTH                     1u
#define SCG_SIRCCSR_LK(x)                        (((uint32)(((uint32)(x))<<SCG_SIRCCSR_LK_SHIFT))&SCG_SIRCCSR_LK_MASK)
#define SCG_SIRCCSR_SIRCVLD_MASK                 0x1000000u
#define SCG_SIRCCSR_SIRCVLD_SHIFT                24u
#define SCG_SIRCCSR_SIRCVLD_WIDTH                1u
#define SCG_SIRCCSR_SIRCVLD(x)                   (((uint32)(((uint32)(x))<<SCG_SIRCCSR_SIRCVLD_SHIFT))&SCG_SIRCCSR_SIRCVLD_MASK)
#define SCG_SIRCCSR_SIRCSEL_MASK                 0x2000000u
#define SCG_SIRCCSR_SIRCSEL_SHIFT                25u
#define SCG_SIRCCSR_SIRCSEL_WIDTH                1u
#define SCG_SIRCCSR_SIRCSEL(x)                   (((uint32)(((uint32)(x))<<SCG_SIRCCSR_SIRCSEL_SHIFT))&SCG_SIRCCSR_SIRCSEL_MASK)
/* SIRCDIV Bit Fields */
#define SCG_SIRCDIV_SIRCDIV1_MASK                0x7u
#define SCG_SIRCDIV_SIRCDIV1_SHIFT               0u
#define SCG_SIRCDIV_SIRCDIV1_WIDTH               3u
#define SCG_SIRCDIV_SIRCDIV1(x)                  (((uint32)(((uint32)(x))<<SCG_SIRCDIV_SIRCDIV1_SHIFT))&SCG_SIRCDIV_SIRCDIV1_MASK)
#define SCG_SIRCDIV_SIRCDIV2_MASK                0x700u
#define SCG_SIRCDIV_SIRCDIV2_SHIFT               8u
#define SCG_SIRCDIV_SIRCDIV2_WIDTH               3u
#define SCG_SIRCDIV_SIRCDIV2(x)                  (((uint32)(((uint32)(x))<<SCG_SIRCDIV_SIRCDIV2_SHIFT))&SCG_SIRCDIV_SIRCDIV2_MASK)
/* SIRCCFG Bit Fields */
#define SCG_SIRCCFG_RANGE_MASK                   0x1u
#define SCG_SIRCCFG_RANGE_SHIFT                  0u
#define SCG_SIRCCFG_RANGE_WIDTH                  1u
#define SCG_SIRCCFG_RANGE(x)                     (((uint32)(((uint32)(x))<<SCG_SIRCCFG_RANGE_SHIFT))&SCG_SIRCCFG_RANGE_MASK)
/* FIRCCSR Bit Fields */
#define SCG_FIRCCSR_FIRCEN_MASK                  0x1u
#define SCG_FIRCCSR_FIRCEN_SHIFT                 0u
#define SCG_FIRCCSR_FIRCEN_WIDTH                 1u
#define SCG_FIRCCSR_FIRCEN(x)                    (((uint32)(((uint32)(x))<<SCG_FIRCCSR_FIRCEN_SHIFT))&SCG_FIRCCSR_FIRCEN_MASK)
#define SCG_FIRCCSR_FIRCREGOFF_MASK              0x8u
#define SCG_FIRCCSR_FIRCREGOFF_SHIFT             3u
#define SCG_FIRCCSR_FIRCREGOFF_WIDTH             1u
#define SCG_FIRCCSR_FIRCREGOFF(x)                (((uint32)(((uint32)(x))<<SCG_FIRCCSR_FIRCREGOFF_SHIFT))&SCG_FIRCCSR_FIRCREGOFF_MASK)
#define SCG_FIRCCSR_LK_MASK                      0x800000u
#define SCG_FIRCCSR_LK_SHIFT                     23u
#define SCG_FIRCCSR_LK_WIDTH                     1u
#define SCG_FIRCCSR_LK(x)                        (((uint32)(((uint32)(x))<<SCG_FIRCCSR_LK_SHIFT))&SCG_FIRCCSR_LK_MASK)
#define SCG_FIRCCSR_FIRCVLD_MASK                 0x1000000u
#define SCG_FIRCCSR_FIRCVLD_SHIFT                24u
#define SCG_FIRCCSR_FIRCVLD_WIDTH                1u
#define SCG_FIRCCSR_FIRCVLD(x)                   (((uint32)(((uint32)(x))<<SCG_FIRCCSR_FIRCVLD_SHIFT))&SCG_FIRCCSR_FIRCVLD_MASK)
#define SCG_FIRCCSR_FIRCSEL_MASK                 0x2000000u
#define SCG_FIRCCSR_FIRCSEL_SHIFT                25u
#define SCG_FIRCCSR_FIRCSEL_WIDTH                1u
#define SCG_FIRCCSR_FIRCSEL(x)                   (((uint32)(((uint32)(x))<<SCG_FIRCCSR_FIRCSEL_SHIFT))&SCG_FIRCCSR_FIRCSEL_MASK)
#define SCG_FIRCCSR_FIRCERR_MASK                 0x4000000u
#define SCG_FIRCCSR_FIRCERR_SHIFT                26u
#define SCG_FIRCCSR_FIRCERR_WIDTH                1u
#define SCG_FIRCCSR_FIRCERR(x)                   (((uint32)(((uint32)(x))<<SCG_FIRCCSR_FIRCERR_SHIFT))&SCG_FIRCCSR_FIRCERR_MASK)
/* FIRCDIV Bit Fields */
#define SCG_FIRCDIV_FIRCDIV1_MASK                0x7u
#define SCG_FIRCDIV_FIRCDIV1_SHIFT               0u
#define SCG_FIRCDIV_FIRCDIV1_WIDTH               3u
#define SCG_FIRCDIV_FIRCDIV1(x)                  (((uint32)(((uint32)(x))<<SCG_FIRCDIV_FIRCDIV1_SHIFT))&SCG_FIRCDIV_FIRCDIV1_MASK)
#define SCG_FIRCDIV_FIRCDIV2_MASK                0x700u
#define SCG_FIRCDIV_FIRCDIV2_SHIFT               8u
#define SCG_FIRCDIV_FIRCDIV2_WIDTH               3u
#define SCG_FIRCDIV_FIRCDIV2(x)                  (((uint32)(((uint32)(x))<<SCG_FIRCDIV_FIRCDIV2_SHIFT))&SCG_FIRCDIV_FIRCDIV2_MASK)
/* FIRCCFG Bit Fields */
#define SCG_FIRCCFG_RANGE_MASK                   0x3u
#define SCG_FIRCCFG_RANGE_SHIFT                  0u
#define SCG_FIRCCFG_RANGE_WIDTH                  2u
#define SCG_FIRCCFG_RANGE(x)                     (((uint32)(((uint32)(x))<<SCG_FIRCCFG_RANGE_SHIFT))&SCG_FIRCCFG_RANGE_MASK)
/* SPLLCSR Bit Fields */
#define SCG_SPLLCSR_SPLLEN_MASK                  0x1u
#define SCG_SPLLCSR_SPLLEN_SHIFT                 0u
#define SCG_SPLLCSR_SPLLEN_WIDTH                 1u
#define SCG_SPLLCSR_SPLLEN(x)                    (((uint32)(((uint32)(x))<<SCG_SPLLCSR_SPLLEN_SHIFT))&SCG_SPLLCSR_SPLLEN_MASK)
#define SCG_SPLLCSR_SPLLCM_MASK                  0x10000u
#define SCG_SPLLCSR_SPLLCM_SHIFT                 16u
#define SCG_SPLLCSR_SPLLCM_WIDTH                 1u
#define SCG_SPLLCSR_SPLLCM(x)                    (((uint32)(((uint32)(x))<<SCG_SPLLCSR_SPLLCM_SHIFT))&SCG_SPLLCSR_SPLLCM_MASK)
#define SCG_SPLLCSR_SPLLCMRE_MASK                0x20000u
#define SCG_SPLLCSR_SPLLCMRE_SHIFT               17u
#define SCG_SPLLCSR_SPLLCMRE_WIDTH               1u
#define SCG_SPLLCSR_SPLLCMRE(x)                  (((uint32)(((uint32)(x))<<SCG_SPLLCSR_SPLLCMRE_SHIFT))&SCG_SPLLCSR_SPLLCMRE_MASK)
#define SCG_SPLLCSR_LK_MASK                      0x800000u
#define SCG_SPLLCSR_LK_SHIFT                     23u
#define SCG_SPLLCSR_LK_WIDTH                     1u
#define SCG_SPLLCSR_LK(x)                        (((uint32)(((uint32)(x))<<SCG_SPLLCSR_LK_SHIFT))&SCG_SPLLCSR_LK_MASK)
#define SCG_SPLLCSR_SPLLVLD_MASK                 0x1000000u
#define SCG_SPLLCSR_SPLLVLD_SHIFT                24u
#define SCG_SPLLCSR_SPLLVLD_WIDTH                1u
#define SCG_SPLLCSR_SPLLVLD(x)                   (((uint32)(((uint32)(x))<<SCG_SPLLCSR_SPLLVLD_SHIFT))&SCG_SPLLCSR_SPLLVLD_MASK)
#define SCG_SPLLCSR_SPLLSEL_MASK                 0x2000000u
#define SCG_SPLLCSR_SPLLSEL_SHIFT                25u
#define SCG_SPLLCSR_SPLLSEL_WIDTH                1u
#define SCG_SPLLCSR_SPLLSEL(x)                   (((uint32)(((uint32)(x))<<SCG_SPLLCSR_SPLLSEL_SHIFT))&SCG_SPLLCSR_SPLLSEL_MASK)
#define SCG_SPLLCSR_SPLLERR_MASK                 0x4000000u
#define SCG_SPLLCSR_SPLLERR_SHIFT                26u
#define SCG_SPLLCSR_SPLLERR_WIDTH                1u
#define SCG_SPLLCSR_SPLLERR(x)                   (((uint32)(((uint32)(x))<<SCG_SPLLCSR_SPLLERR_SHIFT))&SCG_SPLLCSR_SPLLERR_MASK)
/* SPLLDIV Bit Fields */
#define SCG_SPLLDIV_SPLLDIV1_MASK                0x7u
#define SCG_SPLLDIV_SPLLDIV1_SHIFT               0u
#define SCG_SPLLDIV_SPLLDIV1_WIDTH               3u
#define SCG_SPLLDIV_SPLLDIV1(x)                  (((uint32)(((uint32)(x))<<SCG_SPLLDIV_SPLLDIV1_SHIFT))&SCG_SPLLDIV_SPLLDIV1_MASK)
#define SCG_SPLLDIV_SPLLDIV2_MASK                0x700u
#define SCG_SPLLDIV_SPLLDIV2_SHIFT               8u
#define SCG_SPLLDIV_SPLLDIV2_WIDTH               3u
#define SCG_SPLLDIV_SPLLDIV2(x)                  (((uint32)(((uint32)(x))<<SCG_SPLLDIV_SPLLDIV2_SHIFT))&SCG_SPLLDIV_SPLLDIV2_MASK)
/* SPLLCFG Bit Fields */
#define SCG_SPLLCFG_PREDIV_MASK                  0x700u
#define SCG_SPLLCFG_PREDIV_SHIFT                 8u
#define SCG_SPLLCFG_PREDIV_WIDTH                 3u
#define SCG_SPLLCFG_PREDIV(x)                    (((uint32)(((uint32)(x))<<SCG_SPLLCFG_PREDIV_SHIFT))&SCG_SPLLCFG_PREDIV_MASK)
#define SCG_SPLLCFG_MULT_MASK                    0x1F0000u
#define SCG_SPLLCFG_MULT_SHIFT                   16u
#define SCG_SPLLCFG_MULT_WIDTH                   5u
#define SCG_SPLLCFG_MULT(x)                      (((uint32)(((uint32)(x))<<SCG_SPLLCFG_MULT_SHIFT))&SCG_SPLLCFG_MULT_MASK)

/*!
 * @}
 */ /* end of group SCG_Register_Masks */


/*!
 * @}
 */ /* end of group SCG_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Peripheral_Access_Layer SIM Peripheral Access Layer
 * @{
 */


/** SIM - Size of Registers Arrays */

/** SIM - Register Layout Typedef */
typedef struct {
       uint8 RESERVED_0[4];
  __IO uint32 CHIPCTL;                           /**< Chip Control register, offset: 0x4 */
       uint8 RESERVED_1[4];
  __IO uint32 FTMOPT0;                           /**< FTM Option Register 0, offset: 0xC */
  __IO uint32 LPOCLKS;                           /**< LPO Clock Select Register, offset: 0x10 */
       uint8 RESERVED_2[4];
  __IO uint32 ADCOPT;                            /**< ADC Options Register, offset: 0x18 */
  __IO uint32 FTMOPT1;                           /**< FTM Option Register 1, offset: 0x1C */
  __IO uint32 MISCTRL0;                          /**< Miscellaneous control register 0, offset: 0x20 */
  __I  uint32 SDID;                              /**< System Device Identification Register, offset: 0x24 */
       uint8 RESERVED_3[24];
  __IO uint32 PLATCGC;                           /**< Platform Clock Gating Control Register, offset: 0x40 */
       uint8 RESERVED_4[8];
  __IO uint32 FCFG1;                             /**< Flash Configuration Register 1, offset: 0x4C */
       uint8 RESERVED_5[4];
  __I  uint32 UIDH;                              /**< Unique Identification Register High, offset: 0x54 */
  __I  uint32 UIDMH;                             /**< Unique Identification Register Mid-High, offset: 0x58 */
  __I  uint32 UIDML;                             /**< Unique Identification Register Mid Low, offset: 0x5C */
  __I  uint32 UIDL;                              /**< Unique Identification Register Low, offset: 0x60 */
       uint8 RESERVED_6[4];
  __IO uint32 CLKDIV4;                           /**< System Clock Divider Register 4, offset: 0x68 */
  __IO uint32 MISCTRL1;                          /**< Miscellaneous Control register 1, offset: 0x6C */
} SIM_Type, *SIM_MemMapPtr;

 /** Number of instances of the SIM module. */
#define SIM_INSTANCE_COUNT                       (1u)


/* SIM - Peripheral instance base addresses */
/** Peripheral SIM base address */
#define SIM_BASE                                 (0x40048000u)
/** Peripheral SIM base pointer */
#define SIM                                      ((SIM_Type *)SIM_BASE)
/** Array initializer of SIM peripheral base addresses */
#define SIM_BASE_ADDRS                           { SIM_BASE }
/** Array initializer of SIM peripheral base pointers */
#define SIM_BASE_PTRS                            { SIM }

/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Masks SIM Register Masks
 * @{
 */

/* CHIPCTL Bit Fields */
#define SIM_CHIPCTL_ADC_INTERLEAVE_EN_MASK       0xFu
#define SIM_CHIPCTL_ADC_INTERLEAVE_EN_SHIFT      0u
#define SIM_CHIPCTL_ADC_INTERLEAVE_EN_WIDTH      4u
#define SIM_CHIPCTL_ADC_INTERLEAVE_EN(x)         (((uint32)(((uint32)(x))<<SIM_CHIPCTL_ADC_INTERLEAVE_EN_SHIFT))&SIM_CHIPCTL_ADC_INTERLEAVE_EN_MASK)
#define SIM_CHIPCTL_CLKOUTSEL_MASK               0xF0u
#define SIM_CHIPCTL_CLKOUTSEL_SHIFT              4u
#define SIM_CHIPCTL_CLKOUTSEL_WIDTH              4u
#define SIM_CHIPCTL_CLKOUTSEL(x)                 (((uint32)(((uint32)(x))<<SIM_CHIPCTL_CLKOUTSEL_SHIFT))&SIM_CHIPCTL_CLKOUTSEL_MASK)
#define SIM_CHIPCTL_CLKOUTDIV_MASK               0x700u
#define SIM_CHIPCTL_CLKOUTDIV_SHIFT              8u
#define SIM_CHIPCTL_CLKOUTDIV_WIDTH              3u
#define SIM_CHIPCTL_CLKOUTDIV(x)                 (((uint32)(((uint32)(x))<<SIM_CHIPCTL_CLKOUTDIV_SHIFT))&SIM_CHIPCTL_CLKOUTDIV_MASK)
#define SIM_CHIPCTL_CLKOUTEN_MASK                0x800u
#define SIM_CHIPCTL_CLKOUTEN_SHIFT               11u
#define SIM_CHIPCTL_CLKOUTEN_WIDTH               1u
#define SIM_CHIPCTL_CLKOUTEN(x)                  (((uint32)(((uint32)(x))<<SIM_CHIPCTL_CLKOUTEN_SHIFT))&SIM_CHIPCTL_CLKOUTEN_MASK)
#define SIM_CHIPCTL_TRACECLK_SEL_MASK            0x1000u
#define SIM_CHIPCTL_TRACECLK_SEL_SHIFT           12u
#define SIM_CHIPCTL_TRACECLK_SEL_WIDTH           1u
#define SIM_CHIPCTL_TRACECLK_SEL(x)              (((uint32)(((uint32)(x))<<SIM_CHIPCTL_TRACECLK_SEL_SHIFT))&SIM_CHIPCTL_TRACECLK_SEL_MASK)
#define SIM_CHIPCTL_PDB_BB_SEL_MASK              0x2000u
#define SIM_CHIPCTL_PDB_BB_SEL_SHIFT             13u
#define SIM_CHIPCTL_PDB_BB_SEL_WIDTH             1u
#define SIM_CHIPCTL_PDB_BB_SEL(x)                (((uint32)(((uint32)(x))<<SIM_CHIPCTL_PDB_BB_SEL_SHIFT))&SIM_CHIPCTL_PDB_BB_SEL_MASK)
#define SIM_CHIPCTL_ADC_SUPPLY_MASK              0x70000u
#define SIM_CHIPCTL_ADC_SUPPLY_SHIFT             16u
#define SIM_CHIPCTL_ADC_SUPPLY_WIDTH             3u
#define SIM_CHIPCTL_ADC_SUPPLY(x)                (((uint32)(((uint32)(x))<<SIM_CHIPCTL_ADC_SUPPLY_SHIFT))&SIM_CHIPCTL_ADC_SUPPLY_MASK)
#define SIM_CHIPCTL_ADC_SUPPLYEN_MASK            0x80000u
#define SIM_CHIPCTL_ADC_SUPPLYEN_SHIFT           19u
#define SIM_CHIPCTL_ADC_SUPPLYEN_WIDTH           1u
#define SIM_CHIPCTL_ADC_SUPPLYEN(x)              (((uint32)(((uint32)(x))<<SIM_CHIPCTL_ADC_SUPPLYEN_SHIFT))&SIM_CHIPCTL_ADC_SUPPLYEN_MASK)
#define SIM_CHIPCTL_SRAMU_RETEN_MASK             0x100000u
#define SIM_CHIPCTL_SRAMU_RETEN_SHIFT            20u
#define SIM_CHIPCTL_SRAMU_RETEN_WIDTH            1u
#define SIM_CHIPCTL_SRAMU_RETEN(x)               (((uint32)(((uint32)(x))<<SIM_CHIPCTL_SRAMU_RETEN_SHIFT))&SIM_CHIPCTL_SRAMU_RETEN_MASK)
#define SIM_CHIPCTL_SRAML_RETEN_MASK             0x200000u
#define SIM_CHIPCTL_SRAML_RETEN_SHIFT            21u
#define SIM_CHIPCTL_SRAML_RETEN_WIDTH            1u
#define SIM_CHIPCTL_SRAML_RETEN(x)               (((uint32)(((uint32)(x))<<SIM_CHIPCTL_SRAML_RETEN_SHIFT))&SIM_CHIPCTL_SRAML_RETEN_MASK)
/* FTMOPT0 Bit Fields */
#define SIM_FTMOPT0_FTM0FLTxSEL_MASK             0x7u
#define SIM_FTMOPT0_FTM0FLTxSEL_SHIFT            0u
#define SIM_FTMOPT0_FTM0FLTxSEL_WIDTH            3u
#define SIM_FTMOPT0_FTM0FLTxSEL(x)               (((uint32)(((uint32)(x))<<SIM_FTMOPT0_FTM0FLTxSEL_SHIFT))&SIM_FTMOPT0_FTM0FLTxSEL_MASK)
#define SIM_FTMOPT0_FTM1FLTxSEL_MASK             0x70u
#define SIM_FTMOPT0_FTM1FLTxSEL_SHIFT            4u
#define SIM_FTMOPT0_FTM1FLTxSEL_WIDTH            3u
#define SIM_FTMOPT0_FTM1FLTxSEL(x)               (((uint32)(((uint32)(x))<<SIM_FTMOPT0_FTM1FLTxSEL_SHIFT))&SIM_FTMOPT0_FTM1FLTxSEL_MASK)
#define SIM_FTMOPT0_FTM2FLTxSEL_MASK             0x700u
#define SIM_FTMOPT0_FTM2FLTxSEL_SHIFT            8u
#define SIM_FTMOPT0_FTM2FLTxSEL_WIDTH            3u
#define SIM_FTMOPT0_FTM2FLTxSEL(x)               (((uint32)(((uint32)(x))<<SIM_FTMOPT0_FTM2FLTxSEL_SHIFT))&SIM_FTMOPT0_FTM2FLTxSEL_MASK)
#define SIM_FTMOPT0_FTM3FLTxSEL_MASK             0x7000u
#define SIM_FTMOPT0_FTM3FLTxSEL_SHIFT            12u
#define SIM_FTMOPT0_FTM3FLTxSEL_WIDTH            3u
#define SIM_FTMOPT0_FTM3FLTxSEL(x)               (((uint32)(((uint32)(x))<<SIM_FTMOPT0_FTM3FLTxSEL_SHIFT))&SIM_FTMOPT0_FTM3FLTxSEL_MASK)
#define SIM_FTMOPT0_FTM0CLKSEL_MASK              0x3000000u
#define SIM_FTMOPT0_FTM0CLKSEL_SHIFT             24u
#define SIM_FTMOPT0_FTM0CLKSEL_WIDTH             2u
#define SIM_FTMOPT0_FTM0CLKSEL(x)                (((uint32)(((uint32)(x))<<SIM_FTMOPT0_FTM0CLKSEL_SHIFT))&SIM_FTMOPT0_FTM0CLKSEL_MASK)
#define SIM_FTMOPT0_FTM1CLKSEL_MASK              0xC000000u
#define SIM_FTMOPT0_FTM1CLKSEL_SHIFT             26u
#define SIM_FTMOPT0_FTM1CLKSEL_WIDTH             2u
#define SIM_FTMOPT0_FTM1CLKSEL(x)                (((uint32)(((uint32)(x))<<SIM_FTMOPT0_FTM1CLKSEL_SHIFT))&SIM_FTMOPT0_FTM1CLKSEL_MASK)
#define SIM_FTMOPT0_FTM2CLKSEL_MASK              0x30000000u
#define SIM_FTMOPT0_FTM2CLKSEL_SHIFT             28u
#define SIM_FTMOPT0_FTM2CLKSEL_WIDTH             2u
#define SIM_FTMOPT0_FTM2CLKSEL(x)                (((uint32)(((uint32)(x))<<SIM_FTMOPT0_FTM2CLKSEL_SHIFT))&SIM_FTMOPT0_FTM2CLKSEL_MASK)
#define SIM_FTMOPT0_FTM3CLKSEL_MASK              0xC0000000u
#define SIM_FTMOPT0_FTM3CLKSEL_SHIFT             30u
#define SIM_FTMOPT0_FTM3CLKSEL_WIDTH             2u
#define SIM_FTMOPT0_FTM3CLKSEL(x)                (((uint32)(((uint32)(x))<<SIM_FTMOPT0_FTM3CLKSEL_SHIFT))&SIM_FTMOPT0_FTM3CLKSEL_MASK)
/* LPOCLKS Bit Fields */
#define SIM_LPOCLKS_LPO1KCLKEN_MASK              0x1u
#define SIM_LPOCLKS_LPO1KCLKEN_SHIFT             0u
#define SIM_LPOCLKS_LPO1KCLKEN_WIDTH             1u
#define SIM_LPOCLKS_LPO1KCLKEN(x)                (((uint32)(((uint32)(x))<<SIM_LPOCLKS_LPO1KCLKEN_SHIFT))&SIM_LPOCLKS_LPO1KCLKEN_MASK)
#define SIM_LPOCLKS_LPO32KCLKEN_MASK             0x2u
#define SIM_LPOCLKS_LPO32KCLKEN_SHIFT            1u
#define SIM_LPOCLKS_LPO32KCLKEN_WIDTH            1u
#define SIM_LPOCLKS_LPO32KCLKEN(x)               (((uint32)(((uint32)(x))<<SIM_LPOCLKS_LPO32KCLKEN_SHIFT))&SIM_LPOCLKS_LPO32KCLKEN_MASK)
#define SIM_LPOCLKS_LPOCLKSEL_MASK               0xCu
#define SIM_LPOCLKS_LPOCLKSEL_SHIFT              2u
#define SIM_LPOCLKS_LPOCLKSEL_WIDTH              2u
#define SIM_LPOCLKS_LPOCLKSEL(x)                 (((uint32)(((uint32)(x))<<SIM_LPOCLKS_LPOCLKSEL_SHIFT))&SIM_LPOCLKS_LPOCLKSEL_MASK)
#define SIM_LPOCLKS_RTCCLKSEL_MASK               0x30u
#define SIM_LPOCLKS_RTCCLKSEL_SHIFT              4u
#define SIM_LPOCLKS_RTCCLKSEL_WIDTH              2u
#define SIM_LPOCLKS_RTCCLKSEL(x)                 (((uint32)(((uint32)(x))<<SIM_LPOCLKS_RTCCLKSEL_SHIFT))&SIM_LPOCLKS_RTCCLKSEL_MASK)
/* ADCOPT Bit Fields */
#define SIM_ADCOPT_ADC0TRGSEL_MASK               0x1u
#define SIM_ADCOPT_ADC0TRGSEL_SHIFT              0u
#define SIM_ADCOPT_ADC0TRGSEL_WIDTH              1u
#define SIM_ADCOPT_ADC0TRGSEL(x)                 (((uint32)(((uint32)(x))<<SIM_ADCOPT_ADC0TRGSEL_SHIFT))&SIM_ADCOPT_ADC0TRGSEL_MASK)
#define SIM_ADCOPT_ADC0SWPRETRG_MASK             0xEu
#define SIM_ADCOPT_ADC0SWPRETRG_SHIFT            1u
#define SIM_ADCOPT_ADC0SWPRETRG_WIDTH            3u
#define SIM_ADCOPT_ADC0SWPRETRG(x)               (((uint32)(((uint32)(x))<<SIM_ADCOPT_ADC0SWPRETRG_SHIFT))&SIM_ADCOPT_ADC0SWPRETRG_MASK)
#define SIM_ADCOPT_ADC0PRETRGSEL_MASK            0x30u
#define SIM_ADCOPT_ADC0PRETRGSEL_SHIFT           4u
#define SIM_ADCOPT_ADC0PRETRGSEL_WIDTH           2u
#define SIM_ADCOPT_ADC0PRETRGSEL(x)              (((uint32)(((uint32)(x))<<SIM_ADCOPT_ADC0PRETRGSEL_SHIFT))&SIM_ADCOPT_ADC0PRETRGSEL_MASK)
#define SIM_ADCOPT_ADC1TRGSEL_MASK               0x100u
#define SIM_ADCOPT_ADC1TRGSEL_SHIFT              8u
#define SIM_ADCOPT_ADC1TRGSEL_WIDTH              1u
#define SIM_ADCOPT_ADC1TRGSEL(x)                 (((uint32)(((uint32)(x))<<SIM_ADCOPT_ADC1TRGSEL_SHIFT))&SIM_ADCOPT_ADC1TRGSEL_MASK)
#define SIM_ADCOPT_ADC1SWPRETRG_MASK             0xE00u
#define SIM_ADCOPT_ADC1SWPRETRG_SHIFT            9u
#define SIM_ADCOPT_ADC1SWPRETRG_WIDTH            3u
#define SIM_ADCOPT_ADC1SWPRETRG(x)               (((uint32)(((uint32)(x))<<SIM_ADCOPT_ADC1SWPRETRG_SHIFT))&SIM_ADCOPT_ADC1SWPRETRG_MASK)
#define SIM_ADCOPT_ADC1PRETRGSEL_MASK            0x3000u
#define SIM_ADCOPT_ADC1PRETRGSEL_SHIFT           12u
#define SIM_ADCOPT_ADC1PRETRGSEL_WIDTH           2u
#define SIM_ADCOPT_ADC1PRETRGSEL(x)              (((uint32)(((uint32)(x))<<SIM_ADCOPT_ADC1PRETRGSEL_SHIFT))&SIM_ADCOPT_ADC1PRETRGSEL_MASK)
/* FTMOPT1 Bit Fields */
#define SIM_FTMOPT1_FTM0SYNCBIT_MASK             0x1u
#define SIM_FTMOPT1_FTM0SYNCBIT_SHIFT            0u
#define SIM_FTMOPT1_FTM0SYNCBIT_WIDTH            1u
#define SIM_FTMOPT1_FTM0SYNCBIT(x)               (((uint32)(((uint32)(x))<<SIM_FTMOPT1_FTM0SYNCBIT_SHIFT))&SIM_FTMOPT1_FTM0SYNCBIT_MASK)
#define SIM_FTMOPT1_FTM1SYNCBIT_MASK             0x2u
#define SIM_FTMOPT1_FTM1SYNCBIT_SHIFT            1u
#define SIM_FTMOPT1_FTM1SYNCBIT_WIDTH            1u
#define SIM_FTMOPT1_FTM1SYNCBIT(x)               (((uint32)(((uint32)(x))<<SIM_FTMOPT1_FTM1SYNCBIT_SHIFT))&SIM_FTMOPT1_FTM1SYNCBIT_MASK)
#define SIM_FTMOPT1_FTM2SYNCBIT_MASK             0x4u
#define SIM_FTMOPT1_FTM2SYNCBIT_SHIFT            2u
#define SIM_FTMOPT1_FTM2SYNCBIT_WIDTH            1u
#define SIM_FTMOPT1_FTM2SYNCBIT(x)               (((uint32)(((uint32)(x))<<SIM_FTMOPT1_FTM2SYNCBIT_SHIFT))&SIM_FTMOPT1_FTM2SYNCBIT_MASK)
#define SIM_FTMOPT1_FTM3SYNCBIT_MASK             0x8u
#define SIM_FTMOPT1_FTM3SYNCBIT_SHIFT            3u
#define SIM_FTMOPT1_FTM3SYNCBIT_WIDTH            1u
#define SIM_FTMOPT1_FTM3SYNCBIT(x)               (((uint32)(((uint32)(x))<<SIM_FTMOPT1_FTM3SYNCBIT_SHIFT))&SIM_FTMOPT1_FTM3SYNCBIT_MASK)
#define SIM_FTMOPT1_FTM1CH0SEL_MASK              0x30u
#define SIM_FTMOPT1_FTM1CH0SEL_SHIFT             4u
#define SIM_FTMOPT1_FTM1CH0SEL_WIDTH             2u
#define SIM_FTMOPT1_FTM1CH0SEL(x)                (((uint32)(((uint32)(x))<<SIM_FTMOPT1_FTM1CH0SEL_SHIFT))&SIM_FTMOPT1_FTM1CH0SEL_MASK)
#define SIM_FTMOPT1_FTM2CH0SEL_MASK              0xC0u
#define SIM_FTMOPT1_FTM2CH0SEL_SHIFT             6u
#define SIM_FTMOPT1_FTM2CH0SEL_WIDTH             2u
#define SIM_FTMOPT1_FTM2CH0SEL(x)                (((uint32)(((uint32)(x))<<SIM_FTMOPT1_FTM2CH0SEL_SHIFT))&SIM_FTMOPT1_FTM2CH0SEL_MASK)
#define SIM_FTMOPT1_FTM2CH1SEL_MASK              0x100u
#define SIM_FTMOPT1_FTM2CH1SEL_SHIFT             8u
#define SIM_FTMOPT1_FTM2CH1SEL_WIDTH             1u
#define SIM_FTMOPT1_FTM2CH1SEL(x)                (((uint32)(((uint32)(x))<<SIM_FTMOPT1_FTM2CH1SEL_SHIFT))&SIM_FTMOPT1_FTM2CH1SEL_MASK)
#define SIM_FTMOPT1_FTMGLDOK_MASK                0x8000u
#define SIM_FTMOPT1_FTMGLDOK_SHIFT               15u
#define SIM_FTMOPT1_FTMGLDOK_WIDTH               1u
#define SIM_FTMOPT1_FTMGLDOK(x)                  (((uint32)(((uint32)(x))<<SIM_FTMOPT1_FTMGLDOK_SHIFT))&SIM_FTMOPT1_FTMGLDOK_MASK)
#define SIM_FTMOPT1_FTM0_OUTSEL_MASK             0xFF0000u
#define SIM_FTMOPT1_FTM0_OUTSEL_SHIFT            16u
#define SIM_FTMOPT1_FTM0_OUTSEL_WIDTH            8u
#define SIM_FTMOPT1_FTM0_OUTSEL(x)               (((uint32)(((uint32)(x))<<SIM_FTMOPT1_FTM0_OUTSEL_SHIFT))&SIM_FTMOPT1_FTM0_OUTSEL_MASK)
#define SIM_FTMOPT1_FTM3_OUTSEL_MASK             0xFF000000u
#define SIM_FTMOPT1_FTM3_OUTSEL_SHIFT            24u
#define SIM_FTMOPT1_FTM3_OUTSEL_WIDTH            8u
#define SIM_FTMOPT1_FTM3_OUTSEL(x)               (((uint32)(((uint32)(x))<<SIM_FTMOPT1_FTM3_OUTSEL_SHIFT))&SIM_FTMOPT1_FTM3_OUTSEL_MASK)
/* MISCTRL0 Bit Fields */
#define SIM_MISCTRL0_FTM0_OBE_CTRL_MASK          0x10000u
#define SIM_MISCTRL0_FTM0_OBE_CTRL_SHIFT         16u
#define SIM_MISCTRL0_FTM0_OBE_CTRL_WIDTH         1u
#define SIM_MISCTRL0_FTM0_OBE_CTRL(x)            (((uint32)(((uint32)(x))<<SIM_MISCTRL0_FTM0_OBE_CTRL_SHIFT))&SIM_MISCTRL0_FTM0_OBE_CTRL_MASK)
#define SIM_MISCTRL0_FTM1_OBE_CTRL_MASK          0x20000u
#define SIM_MISCTRL0_FTM1_OBE_CTRL_SHIFT         17u
#define SIM_MISCTRL0_FTM1_OBE_CTRL_WIDTH         1u
#define SIM_MISCTRL0_FTM1_OBE_CTRL(x)            (((uint32)(((uint32)(x))<<SIM_MISCTRL0_FTM1_OBE_CTRL_SHIFT))&SIM_MISCTRL0_FTM1_OBE_CTRL_MASK)
#define SIM_MISCTRL0_FTM2_OBE_CTRL_MASK          0x40000u
#define SIM_MISCTRL0_FTM2_OBE_CTRL_SHIFT         18u
#define SIM_MISCTRL0_FTM2_OBE_CTRL_WIDTH         1u
#define SIM_MISCTRL0_FTM2_OBE_CTRL(x)            (((uint32)(((uint32)(x))<<SIM_MISCTRL0_FTM2_OBE_CTRL_SHIFT))&SIM_MISCTRL0_FTM2_OBE_CTRL_MASK)
#define SIM_MISCTRL0_FTM3_OBE_CTRL_MASK          0x80000u
#define SIM_MISCTRL0_FTM3_OBE_CTRL_SHIFT         19u
#define SIM_MISCTRL0_FTM3_OBE_CTRL_WIDTH         1u
#define SIM_MISCTRL0_FTM3_OBE_CTRL(x)            (((uint32)(((uint32)(x))<<SIM_MISCTRL0_FTM3_OBE_CTRL_SHIFT))&SIM_MISCTRL0_FTM3_OBE_CTRL_MASK)
/* SDID Bit Fields */
#define SIM_SDID_FEATURES_MASK                   0xFFu
#define SIM_SDID_FEATURES_SHIFT                  0u
#define SIM_SDID_FEATURES_WIDTH                  8u
#define SIM_SDID_FEATURES(x)                     (((uint32)(((uint32)(x))<<SIM_SDID_FEATURES_SHIFT))&SIM_SDID_FEATURES_MASK)
#define SIM_SDID_PACKAGE_MASK                    0xF00u
#define SIM_SDID_PACKAGE_SHIFT                   8u
#define SIM_SDID_PACKAGE_WIDTH                   4u
#define SIM_SDID_PACKAGE(x)                      (((uint32)(((uint32)(x))<<SIM_SDID_PACKAGE_SHIFT))&SIM_SDID_PACKAGE_MASK)
#define SIM_SDID_REVID_MASK                      0xF000u
#define SIM_SDID_REVID_SHIFT                     12u
#define SIM_SDID_REVID_WIDTH                     4u
#define SIM_SDID_REVID(x)                        (((uint32)(((uint32)(x))<<SIM_SDID_REVID_SHIFT))&SIM_SDID_REVID_MASK)
#define SIM_SDID_RAMSIZE_MASK                    0xF0000u
#define SIM_SDID_RAMSIZE_SHIFT                   16u
#define SIM_SDID_RAMSIZE_WIDTH                   4u
#define SIM_SDID_RAMSIZE(x)                      (((uint32)(((uint32)(x))<<SIM_SDID_RAMSIZE_SHIFT))&SIM_SDID_RAMSIZE_MASK)
#define SIM_SDID_DERIVATE_MASK                   0xF00000u
#define SIM_SDID_DERIVATE_SHIFT                  20u
#define SIM_SDID_DERIVATE_WIDTH                  4u
#define SIM_SDID_DERIVATE(x)                     (((uint32)(((uint32)(x))<<SIM_SDID_DERIVATE_SHIFT))&SIM_SDID_DERIVATE_MASK)
#define SIM_SDID_SUBSERIES_MASK                  0xF000000u
#define SIM_SDID_SUBSERIES_SHIFT                 24u
#define SIM_SDID_SUBSERIES_WIDTH                 4u
#define SIM_SDID_SUBSERIES(x)                    (((uint32)(((uint32)(x))<<SIM_SDID_SUBSERIES_SHIFT))&SIM_SDID_SUBSERIES_MASK)
#define SIM_SDID_GENERATION_MASK                 0xF0000000u
#define SIM_SDID_GENERATION_SHIFT                28u
#define SIM_SDID_GENERATION_WIDTH                4u
#define SIM_SDID_GENERATION(x)                   (((uint32)(((uint32)(x))<<SIM_SDID_GENERATION_SHIFT))&SIM_SDID_GENERATION_MASK)
/* PLATCGC Bit Fields */
#define SIM_PLATCGC_CGCMSCM_MASK                 0x1u
#define SIM_PLATCGC_CGCMSCM_SHIFT                0u
#define SIM_PLATCGC_CGCMSCM_WIDTH                1u
#define SIM_PLATCGC_CGCMSCM(x)                   (((uint32)(((uint32)(x))<<SIM_PLATCGC_CGCMSCM_SHIFT))&SIM_PLATCGC_CGCMSCM_MASK)
#define SIM_PLATCGC_CGCMPU_MASK                  0x2u
#define SIM_PLATCGC_CGCMPU_SHIFT                 1u
#define SIM_PLATCGC_CGCMPU_WIDTH                 1u
#define SIM_PLATCGC_CGCMPU(x)                    (((uint32)(((uint32)(x))<<SIM_PLATCGC_CGCMPU_SHIFT))&SIM_PLATCGC_CGCMPU_MASK)
#define SIM_PLATCGC_CGCDMA_MASK                  0x4u
#define SIM_PLATCGC_CGCDMA_SHIFT                 2u
#define SIM_PLATCGC_CGCDMA_WIDTH                 1u
#define SIM_PLATCGC_CGCDMA(x)                    (((uint32)(((uint32)(x))<<SIM_PLATCGC_CGCDMA_SHIFT))&SIM_PLATCGC_CGCDMA_MASK)
#define SIM_PLATCGC_CGCERM_MASK                  0x8u
#define SIM_PLATCGC_CGCERM_SHIFT                 3u
#define SIM_PLATCGC_CGCERM_WIDTH                 1u
#define SIM_PLATCGC_CGCERM(x)                    (((uint32)(((uint32)(x))<<SIM_PLATCGC_CGCERM_SHIFT))&SIM_PLATCGC_CGCERM_MASK)
#define SIM_PLATCGC_CGCEIM_MASK                  0x10u
#define SIM_PLATCGC_CGCEIM_SHIFT                 4u
#define SIM_PLATCGC_CGCEIM_WIDTH                 1u
#define SIM_PLATCGC_CGCEIM(x)                    (((uint32)(((uint32)(x))<<SIM_PLATCGC_CGCEIM_SHIFT))&SIM_PLATCGC_CGCEIM_MASK)
/* FCFG1 Bit Fields */
#define SIM_FCFG1_DEPART_MASK                    0xF000u
#define SIM_FCFG1_DEPART_SHIFT                   12u
#define SIM_FCFG1_DEPART_WIDTH                   4u
#define SIM_FCFG1_DEPART(x)                      (((uint32)(((uint32)(x))<<SIM_FCFG1_DEPART_SHIFT))&SIM_FCFG1_DEPART_MASK)
#define SIM_FCFG1_EEERAMSIZE_MASK                0xF0000u
#define SIM_FCFG1_EEERAMSIZE_SHIFT               16u
#define SIM_FCFG1_EEERAMSIZE_WIDTH               4u
#define SIM_FCFG1_EEERAMSIZE(x)                  (((uint32)(((uint32)(x))<<SIM_FCFG1_EEERAMSIZE_SHIFT))&SIM_FCFG1_EEERAMSIZE_MASK)
/* UIDH Bit Fields */
#define SIM_UIDH_UID127_96_MASK                  0xFFFFFFFFu
#define SIM_UIDH_UID127_96_SHIFT                 0u
#define SIM_UIDH_UID127_96_WIDTH                 32u
#define SIM_UIDH_UID127_96(x)                    (((uint32)(((uint32)(x))<<SIM_UIDH_UID127_96_SHIFT))&SIM_UIDH_UID127_96_MASK)
/* UIDMH Bit Fields */
#define SIM_UIDMH_UID95_64_MASK                  0xFFFFFFFFu
#define SIM_UIDMH_UID95_64_SHIFT                 0u
#define SIM_UIDMH_UID95_64_WIDTH                 32u
#define SIM_UIDMH_UID95_64(x)                    (((uint32)(((uint32)(x))<<SIM_UIDMH_UID95_64_SHIFT))&SIM_UIDMH_UID95_64_MASK)
/* UIDML Bit Fields */
#define SIM_UIDML_UID63_32_MASK                  0xFFFFFFFFu
#define SIM_UIDML_UID63_32_SHIFT                 0u
#define SIM_UIDML_UID63_32_WIDTH                 32u
#define SIM_UIDML_UID63_32(x)                    (((uint32)(((uint32)(x))<<SIM_UIDML_UID63_32_SHIFT))&SIM_UIDML_UID63_32_MASK)
/* UIDL Bit Fields */
#define SIM_UIDL_UID31_0_MASK                    0xFFFFFFFFu
#define SIM_UIDL_UID31_0_SHIFT                   0u
#define SIM_UIDL_UID31_0_WIDTH                   32u
#define SIM_UIDL_UID31_0(x)                      (((uint32)(((uint32)(x))<<SIM_UIDL_UID31_0_SHIFT))&SIM_UIDL_UID31_0_MASK)
/* CLKDIV4 Bit Fields */
#define SIM_CLKDIV4_TRACEFRAC_MASK               0x1u
#define SIM_CLKDIV4_TRACEFRAC_SHIFT              0u
#define SIM_CLKDIV4_TRACEFRAC_WIDTH              1u
#define SIM_CLKDIV4_TRACEFRAC(x)                 (((uint32)(((uint32)(x))<<SIM_CLKDIV4_TRACEFRAC_SHIFT))&SIM_CLKDIV4_TRACEFRAC_MASK)
#define SIM_CLKDIV4_TRACEDIV_MASK                0xEu
#define SIM_CLKDIV4_TRACEDIV_SHIFT               1u
#define SIM_CLKDIV4_TRACEDIV_WIDTH               3u
#define SIM_CLKDIV4_TRACEDIV(x)                  (((uint32)(((uint32)(x))<<SIM_CLKDIV4_TRACEDIV_SHIFT))&SIM_CLKDIV4_TRACEDIV_MASK)
#define SIM_CLKDIV4_TRACEDIVEN_MASK              0x10000000u
#define SIM_CLKDIV4_TRACEDIVEN_SHIFT             28u
#define SIM_CLKDIV4_TRACEDIVEN_WIDTH             1u
#define SIM_CLKDIV4_TRACEDIVEN(x)                (((uint32)(((uint32)(x))<<SIM_CLKDIV4_TRACEDIVEN_SHIFT))&SIM_CLKDIV4_TRACEDIVEN_MASK)
/* MISCTRL1 Bit Fields */
#define SIM_MISCTRL1_SW_TRG_MASK                 0x1u
#define SIM_MISCTRL1_SW_TRG_SHIFT                0u
#define SIM_MISCTRL1_SW_TRG_WIDTH                1u
#define SIM_MISCTRL1_SW_TRG(x)                   (((uint32)(((uint32)(x))<<SIM_MISCTRL1_SW_TRG_SHIFT))&SIM_MISCTRL1_SW_TRG_MASK)

/*!
 * @}
 */ /* end of group SIM_Register_Masks */


/*!
 * @}
 */ /* end of group SIM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Peripheral_Access_Layer SMC Peripheral Access Layer
 * @{
 */


/** SMC - Size of Registers Arrays */

/** SMC - Register Layout Typedef */
typedef struct {
  __I  uint32 VERID;                             /**< SMC Version ID Register, offset: 0x0 */
  __I  uint32 PARAM;                             /**< SMC Parameter Register, offset: 0x4 */
  __IO uint32 PMPROT;                            /**< Power Mode Protection register, offset: 0x8 */
  __IO uint32 PMCTRL;                            /**< Power Mode Control register, offset: 0xC */
  __IO uint32 STOPCTRL;                          /**< Stop Control Register, offset: 0x10 */
  __I  uint32 PMSTAT;                            /**< Power Mode Status register, offset: 0x14 */
} SMC_Type, *SMC_MemMapPtr;

 /** Number of instances of the SMC module. */
#define SMC_INSTANCE_COUNT                       (1u)


/* SMC - Peripheral instance base addresses */
/** Peripheral SMC base address */
#define SMC_BASE                                 (0x4007E000u)
/** Peripheral SMC base pointer */
#define SMC                                      ((SMC_Type *)SMC_BASE)
/** Array initializer of SMC peripheral base addresses */
#define SMC_BASE_ADDRS                           { SMC_BASE }
/** Array initializer of SMC peripheral base pointers */
#define SMC_BASE_PTRS                            { SMC }

/* ----------------------------------------------------------------------------
   -- SMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Register_Masks SMC Register Masks
 * @{
 */

/* VERID Bit Fields */
#define SMC_VERID_FEATURE_MASK                   0xFFFFu
#define SMC_VERID_FEATURE_SHIFT                  0u
#define SMC_VERID_FEATURE_WIDTH                  16u
#define SMC_VERID_FEATURE(x)                     (((uint32)(((uint32)(x))<<SMC_VERID_FEATURE_SHIFT))&SMC_VERID_FEATURE_MASK)
#define SMC_VERID_MINOR_MASK                     0xFF0000u
#define SMC_VERID_MINOR_SHIFT                    16u
#define SMC_VERID_MINOR_WIDTH                    8u
#define SMC_VERID_MINOR(x)                       (((uint32)(((uint32)(x))<<SMC_VERID_MINOR_SHIFT))&SMC_VERID_MINOR_MASK)
#define SMC_VERID_MAJOR_MASK                     0xFF000000u
#define SMC_VERID_MAJOR_SHIFT                    24u
#define SMC_VERID_MAJOR_WIDTH                    8u
#define SMC_VERID_MAJOR(x)                       (((uint32)(((uint32)(x))<<SMC_VERID_MAJOR_SHIFT))&SMC_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define SMC_PARAM_EHSRUN_MASK                    0x1u
#define SMC_PARAM_EHSRUN_SHIFT                   0u
#define SMC_PARAM_EHSRUN_WIDTH                   1u
#define SMC_PARAM_EHSRUN(x)                      (((uint32)(((uint32)(x))<<SMC_PARAM_EHSRUN_SHIFT))&SMC_PARAM_EHSRUN_MASK)
#define SMC_PARAM_ELLS_MASK                      0x8u
#define SMC_PARAM_ELLS_SHIFT                     3u
#define SMC_PARAM_ELLS_WIDTH                     1u
#define SMC_PARAM_ELLS(x)                        (((uint32)(((uint32)(x))<<SMC_PARAM_ELLS_SHIFT))&SMC_PARAM_ELLS_MASK)
#define SMC_PARAM_ELLS2_MASK                     0x20u
#define SMC_PARAM_ELLS2_SHIFT                    5u
#define SMC_PARAM_ELLS2_WIDTH                    1u
#define SMC_PARAM_ELLS2(x)                       (((uint32)(((uint32)(x))<<SMC_PARAM_ELLS2_SHIFT))&SMC_PARAM_ELLS2_MASK)
#define SMC_PARAM_EVLLS0_MASK                    0x40u
#define SMC_PARAM_EVLLS0_SHIFT                   6u
#define SMC_PARAM_EVLLS0_WIDTH                   1u
#define SMC_PARAM_EVLLS0(x)                      (((uint32)(((uint32)(x))<<SMC_PARAM_EVLLS0_SHIFT))&SMC_PARAM_EVLLS0_MASK)
/* PMPROT Bit Fields */
#define SMC_PMPROT_AVLP_MASK                     0x20u
#define SMC_PMPROT_AVLP_SHIFT                    5u
#define SMC_PMPROT_AVLP_WIDTH                    1u
#define SMC_PMPROT_AVLP(x)                       (((uint32)(((uint32)(x))<<SMC_PMPROT_AVLP_SHIFT))&SMC_PMPROT_AVLP_MASK)
#define SMC_PMPROT_AHSRUN_MASK                   0x80u
#define SMC_PMPROT_AHSRUN_SHIFT                  7u
#define SMC_PMPROT_AHSRUN_WIDTH                  1u
#define SMC_PMPROT_AHSRUN(x)                     (((uint32)(((uint32)(x))<<SMC_PMPROT_AHSRUN_SHIFT))&SMC_PMPROT_AHSRUN_MASK)
/* PMCTRL Bit Fields */
#define SMC_PMCTRL_STOPM_MASK                    0x7u
#define SMC_PMCTRL_STOPM_SHIFT                   0u
#define SMC_PMCTRL_STOPM_WIDTH                   3u
#define SMC_PMCTRL_STOPM(x)                      (((uint32)(((uint32)(x))<<SMC_PMCTRL_STOPM_SHIFT))&SMC_PMCTRL_STOPM_MASK)
#define SMC_PMCTRL_VLPSA_MASK                    0x8u
#define SMC_PMCTRL_VLPSA_SHIFT                   3u
#define SMC_PMCTRL_VLPSA_WIDTH                   1u
#define SMC_PMCTRL_VLPSA(x)                      (((uint32)(((uint32)(x))<<SMC_PMCTRL_VLPSA_SHIFT))&SMC_PMCTRL_VLPSA_MASK)
#define SMC_PMCTRL_RUNM_MASK                     0x60u
#define SMC_PMCTRL_RUNM_SHIFT                    5u
#define SMC_PMCTRL_RUNM_WIDTH                    2u
#define SMC_PMCTRL_RUNM(x)                       (((uint32)(((uint32)(x))<<SMC_PMCTRL_RUNM_SHIFT))&SMC_PMCTRL_RUNM_MASK)
/* STOPCTRL Bit Fields */
#define SMC_STOPCTRL_STOPO_MASK                  0xC0u
#define SMC_STOPCTRL_STOPO_SHIFT                 6u
#define SMC_STOPCTRL_STOPO_WIDTH                 2u
#define SMC_STOPCTRL_STOPO(x)                    (((uint32)(((uint32)(x))<<SMC_STOPCTRL_STOPO_SHIFT))&SMC_STOPCTRL_STOPO_MASK)
/* PMSTAT Bit Fields */
#define SMC_PMSTAT_PMSTAT_MASK                   0xFFu
#define SMC_PMSTAT_PMSTAT_SHIFT                  0u
#define SMC_PMSTAT_PMSTAT_WIDTH                  8u
#define SMC_PMSTAT_PMSTAT(x)                     (((uint32)(((uint32)(x))<<SMC_PMSTAT_PMSTAT_SHIFT))&SMC_PMSTAT_PMSTAT_MASK)

/*!
 * @}
 */ /* end of group SMC_Register_Masks */


/*!
 * @}
 */ /* end of group SMC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- TRGMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Peripheral_Access_Layer TRGMUX Peripheral Access Layer
 * @{
 */


/** TRGMUX - Size of Registers Arrays */
#define TRGMUX_TRGMUXn_COUNT                     26u

/** TRGMUX - Register Layout Typedef */
typedef struct {
  __IO uint32 TRGMUXn[TRGMUX_TRGMUXn_COUNT];     /**< TRGMUX DMAMUX0 Register..TRGMUX LPTMR0 Register, array offset: 0x0, array step: 0x4 */
} TRGMUX_Type, *TRGMUX_MemMapPtr;

 /** Number of instances of the TRGMUX module. */
#define TRGMUX_INSTANCE_COUNT                    (1u)


/* TRGMUX - Peripheral instance base addresses */
/** Peripheral TRGMUX base address */
#define TRGMUX_BASE                              (0x40063000u)
/** Peripheral TRGMUX base pointer */
#define TRGMUX                                   ((TRGMUX_Type *)TRGMUX_BASE)
/** Array initializer of TRGMUX peripheral base addresses */
#define TRGMUX_BASE_ADDRS                        { TRGMUX_BASE }
/** Array initializer of TRGMUX peripheral base pointers */
#define TRGMUX_BASE_PTRS                         { TRGMUX }

/* TRGMUX index offsets */
#define TRGMUX_DMAMUX0_INDEX                     0
#define TRGMUX_EXTOUT0_INDEX                     1
#define TRGMUX_EXTOUT1_INDEX                     2
#define TRGMUX_ADC0_INDEX                        3
#define TRGMUX_ADC1_INDEX                        4
#define TRGMUX_CMP0_INDEX                        7
#define TRGMUX_FTM0_INDEX                        10
#define TRGMUX_FTM1_INDEX                        11
#define TRGMUX_FTM2_INDEX                        12
#define TRGMUX_FTM3_INDEX                        13
#define TRGMUX_PDB0_INDEX                        14
#define TRGMUX_PDB1_INDEX                        15
#define TRGMUX_FLEXIO_INDEX                      17
#define TRGMUX_LPIT0_INDEX                       18
#define TRGMUX_LPUART0_INDEX                     19
#define TRGMUX_LPUART1_INDEX                     20
#define TRGMUX_LPI2C0_INDEX                      21
#define TRGMUX_LPSPI0_INDEX                      23
#define TRGMUX_LPSPI1_INDEX                      24
#define TRGMUX_LPTMR0_INDEX                      25

/* ----------------------------------------------------------------------------
   -- TRGMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Register_Masks TRGMUX Register Masks
 * @{
 */

/* TRGMUXn Bit Fields */
#define TRGMUX_TRGMUXn_SEL0_MASK                 0x3Fu
#define TRGMUX_TRGMUXn_SEL0_SHIFT                0u
#define TRGMUX_TRGMUXn_SEL0_WIDTH                6u
#define TRGMUX_TRGMUXn_SEL0(x)                   (((uint32)(((uint32)(x))<<TRGMUX_TRGMUXn_SEL0_SHIFT))&TRGMUX_TRGMUXn_SEL0_MASK)
#define TRGMUX_TRGMUXn_SEL1_MASK                 0x3F00u
#define TRGMUX_TRGMUXn_SEL1_SHIFT                8u
#define TRGMUX_TRGMUXn_SEL1_WIDTH                6u
#define TRGMUX_TRGMUXn_SEL1(x)                   (((uint32)(((uint32)(x))<<TRGMUX_TRGMUXn_SEL1_SHIFT))&TRGMUX_TRGMUXn_SEL1_MASK)
#define TRGMUX_TRGMUXn_SEL2_MASK                 0x3F0000u
#define TRGMUX_TRGMUXn_SEL2_SHIFT                16u
#define TRGMUX_TRGMUXn_SEL2_WIDTH                6u
#define TRGMUX_TRGMUXn_SEL2(x)                   (((uint32)(((uint32)(x))<<TRGMUX_TRGMUXn_SEL2_SHIFT))&TRGMUX_TRGMUXn_SEL2_MASK)
#define TRGMUX_TRGMUXn_SEL3_MASK                 0x3F000000u
#define TRGMUX_TRGMUXn_SEL3_SHIFT                24u
#define TRGMUX_TRGMUXn_SEL3_WIDTH                6u
#define TRGMUX_TRGMUXn_SEL3(x)                   (((uint32)(((uint32)(x))<<TRGMUX_TRGMUXn_SEL3_SHIFT))&TRGMUX_TRGMUXn_SEL3_MASK)
#define TRGMUX_TRGMUXn_LK_MASK                   0x80000000u
#define TRGMUX_TRGMUXn_LK_SHIFT                  31u
#define TRGMUX_TRGMUXn_LK_WIDTH                  1u
#define TRGMUX_TRGMUXn_LK(x)                     (((uint32)(((uint32)(x))<<TRGMUX_TRGMUXn_LK_SHIFT))&TRGMUX_TRGMUXn_LK_MASK)

/*!
 * @}
 */ /* end of group TRGMUX_Register_Masks */


/*!
 * @}
 */ /* end of group TRGMUX_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- WDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Peripheral_Access_Layer WDOG Peripheral Access Layer
 * @{
 */


/** WDOG - Size of Registers Arrays */

/** WDOG - Register Layout Typedef */
typedef struct {
  __IO uint32 CS;                                /**< Watchdog Control and Status Register, offset: 0x0 */
  __IO uint32 CNT;                               /**< Watchdog Counter Register, offset: 0x4 */
  __IO uint32 TOVAL;                             /**< Watchdog Timeout Value Register, offset: 0x8 */
  __IO uint32 WIN;                               /**< Watchdog Window Register, offset: 0xC */
} WDOG_Type, *WDOG_MemMapPtr;

 /** Number of instances of the WDOG module. */
#define WDOG_INSTANCE_COUNT                      (1u)


/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG base address */
#define WDOG_BASE                                (0x40052000u)
/** Peripheral WDOG base pointer */
#define WDOG                                     ((WDOG_Type *)WDOG_BASE)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { WDOG_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { WDOG }
 /** Number of interrupt vector arrays for the WDOG module. */
#define WDOG_IRQS_ARR_COUNT                      (1u)
 /** Number of interrupt channels for the WDOG module. */
#define WDOG_IRQS_CH_COUNT                       (1u)
/** Interrupt vectors for the WDOG peripheral type */
#define WDOG_IRQS                                { WDOG_EWM_IRQn }

/* ----------------------------------------------------------------------------
   -- WDOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Masks WDOG Register Masks
 * @{
 */

/* CS Bit Fields */
#define WDOG_CS_STOP_MASK                        0x1u
#define WDOG_CS_STOP_SHIFT                       0u
#define WDOG_CS_STOP_WIDTH                       1u
#define WDOG_CS_STOP(x)                          (((uint32)(((uint32)(x))<<WDOG_CS_STOP_SHIFT))&WDOG_CS_STOP_MASK)
#define WDOG_CS_WAIT_MASK                        0x2u
#define WDOG_CS_WAIT_SHIFT                       1u
#define WDOG_CS_WAIT_WIDTH                       1u
#define WDOG_CS_WAIT(x)                          (((uint32)(((uint32)(x))<<WDOG_CS_WAIT_SHIFT))&WDOG_CS_WAIT_MASK)
#define WDOG_CS_DBG_MASK                         0x4u
#define WDOG_CS_DBG_SHIFT                        2u
#define WDOG_CS_DBG_WIDTH                        1u
#define WDOG_CS_DBG(x)                           (((uint32)(((uint32)(x))<<WDOG_CS_DBG_SHIFT))&WDOG_CS_DBG_MASK)
#define WDOG_CS_TST_MASK                         0x18u
#define WDOG_CS_TST_SHIFT                        3u
#define WDOG_CS_TST_WIDTH                        2u
#define WDOG_CS_TST(x)                           (((uint32)(((uint32)(x))<<WDOG_CS_TST_SHIFT))&WDOG_CS_TST_MASK)
#define WDOG_CS_UPDATE_MASK                      0x20u
#define WDOG_CS_UPDATE_SHIFT                     5u
#define WDOG_CS_UPDATE_WIDTH                     1u
#define WDOG_CS_UPDATE(x)                        (((uint32)(((uint32)(x))<<WDOG_CS_UPDATE_SHIFT))&WDOG_CS_UPDATE_MASK)
#define WDOG_CS_INT_MASK                         0x40u
#define WDOG_CS_INT_SHIFT                        6u
#define WDOG_CS_INT_WIDTH                        1u
#define WDOG_CS_INT(x)                           (((uint32)(((uint32)(x))<<WDOG_CS_INT_SHIFT))&WDOG_CS_INT_MASK)
#define WDOG_CS_EN_MASK                          0x80u
#define WDOG_CS_EN_SHIFT                         7u
#define WDOG_CS_EN_WIDTH                         1u
#define WDOG_CS_EN(x)                            (((uint32)(((uint32)(x))<<WDOG_CS_EN_SHIFT))&WDOG_CS_EN_MASK)
#define WDOG_CS_CLK_MASK                         0x300u
#define WDOG_CS_CLK_SHIFT                        8u
#define WDOG_CS_CLK_WIDTH                        2u
#define WDOG_CS_CLK(x)                           (((uint32)(((uint32)(x))<<WDOG_CS_CLK_SHIFT))&WDOG_CS_CLK_MASK)
#define WDOG_CS_RCS_MASK                         0x400u
#define WDOG_CS_RCS_SHIFT                        10u
#define WDOG_CS_RCS_WIDTH                        1u
#define WDOG_CS_RCS(x)                           (((uint32)(((uint32)(x))<<WDOG_CS_RCS_SHIFT))&WDOG_CS_RCS_MASK)
#define WDOG_CS_ULK_MASK                         0x800u
#define WDOG_CS_ULK_SHIFT                        11u
#define WDOG_CS_ULK_WIDTH                        1u
#define WDOG_CS_ULK(x)                           (((uint32)(((uint32)(x))<<WDOG_CS_ULK_SHIFT))&WDOG_CS_ULK_MASK)
#define WDOG_CS_PRES_MASK                        0x1000u
#define WDOG_CS_PRES_SHIFT                       12u
#define WDOG_CS_PRES_WIDTH                       1u
#define WDOG_CS_PRES(x)                          (((uint32)(((uint32)(x))<<WDOG_CS_PRES_SHIFT))&WDOG_CS_PRES_MASK)
#define WDOG_CS_CMD32EN_MASK                     0x2000u
#define WDOG_CS_CMD32EN_SHIFT                    13u
#define WDOG_CS_CMD32EN_WIDTH                    1u
#define WDOG_CS_CMD32EN(x)                       (((uint32)(((uint32)(x))<<WDOG_CS_CMD32EN_SHIFT))&WDOG_CS_CMD32EN_MASK)
#define WDOG_CS_FLG_MASK                         0x4000u
#define WDOG_CS_FLG_SHIFT                        14u
#define WDOG_CS_FLG_WIDTH                        1u
#define WDOG_CS_FLG(x)                           (((uint32)(((uint32)(x))<<WDOG_CS_FLG_SHIFT))&WDOG_CS_FLG_MASK)
#define WDOG_CS_WIN_MASK                         0x8000u
#define WDOG_CS_WIN_SHIFT                        15u
#define WDOG_CS_WIN_WIDTH                        1u
#define WDOG_CS_WIN(x)                           (((uint32)(((uint32)(x))<<WDOG_CS_WIN_SHIFT))&WDOG_CS_WIN_MASK)
/* CNT Bit Fields */
#define WDOG_CNT_CNTLOW_MASK                     0xFFu
#define WDOG_CNT_CNTLOW_SHIFT                    0u
#define WDOG_CNT_CNTLOW_WIDTH                    8u
#define WDOG_CNT_CNTLOW(x)                       (((uint32)(((uint32)(x))<<WDOG_CNT_CNTLOW_SHIFT))&WDOG_CNT_CNTLOW_MASK)
#define WDOG_CNT_CNTHIGH_MASK                    0xFF00u
#define WDOG_CNT_CNTHIGH_SHIFT                   8u
#define WDOG_CNT_CNTHIGH_WIDTH                   8u
#define WDOG_CNT_CNTHIGH(x)                      (((uint32)(((uint32)(x))<<WDOG_CNT_CNTHIGH_SHIFT))&WDOG_CNT_CNTHIGH_MASK)
/* TOVAL Bit Fields */
#define WDOG_TOVAL_TOVALLOW_MASK                 0xFFu
#define WDOG_TOVAL_TOVALLOW_SHIFT                0u
#define WDOG_TOVAL_TOVALLOW_WIDTH                8u
#define WDOG_TOVAL_TOVALLOW(x)                   (((uint32)(((uint32)(x))<<WDOG_TOVAL_TOVALLOW_SHIFT))&WDOG_TOVAL_TOVALLOW_MASK)
#define WDOG_TOVAL_TOVALHIGH_MASK                0xFF00u
#define WDOG_TOVAL_TOVALHIGH_SHIFT               8u
#define WDOG_TOVAL_TOVALHIGH_WIDTH               8u
#define WDOG_TOVAL_TOVALHIGH(x)                  (((uint32)(((uint32)(x))<<WDOG_TOVAL_TOVALHIGH_SHIFT))&WDOG_TOVAL_TOVALHIGH_MASK)
/* WIN Bit Fields */
#define WDOG_WIN_WINLOW_MASK                     0xFFu
#define WDOG_WIN_WINLOW_SHIFT                    0u
#define WDOG_WIN_WINLOW_WIDTH                    8u
#define WDOG_WIN_WINLOW(x)                       (((uint32)(((uint32)(x))<<WDOG_WIN_WINLOW_SHIFT))&WDOG_WIN_WINLOW_MASK)
#define WDOG_WIN_WINHIGH_MASK                    0xFF00u
#define WDOG_WIN_WINHIGH_SHIFT                   8u
#define WDOG_WIN_WINHIGH_WIDTH                   8u
#define WDOG_WIN_WINHIGH(x)                      (((uint32)(((uint32)(x))<<WDOG_WIN_WINHIGH_SHIFT))&WDOG_WIN_WINHIGH_MASK)

/*!
 * @}
 */ /* end of group WDOG_Register_Masks */


/*!
 * @}
 */ /* end of group WDOG_Peripheral_Access_Layer */


/*!
 * @}
 */ /* end of group Peripheral_access_layer_S32K144 */


/* ----------------------------------------------------------------------------
   -- Backward Compatibility for S32K144
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Backward_Compatibility_Symbols_S32K144 Backward Compatibility for S32K144
 * @{
 */

/* No backward compatibility issues. */

/*!
 * @}
 */ /* end of group Backward_Compatibility_Symbols_S32K144 */


#else /* #if !defined(S32K144_H_) */
  /* There is already included the same memory map. Check if it is compatible (has the same major version) */
  #if (MCU_MEM_MAP_VERSION != 0x0200u)
    #if (!defined(MCU_MEM_MAP_SUPPRESS_VERSION_WARNING))
      #warning There are included two not compatible versions of memory maps. Please check possible differences.
    #endif /* (!defined(MCU_MEM_MAP_SUPPRESS_VERSION_WARNING)) */
  #endif /* (MCU_MEM_MAP_VERSION != 0x0200u) */
#endif  /* #if !defined(S32K144_H_) */

/* S32K144.h, eof. */


/* CHECK: RULE 205 ON */
/* CHECK: RULE 505 ON */
/* CHECK: RULE 501 ON */
/* CHECK: RULE 203 ON */
/* CHECK: RULE 502 ON */
