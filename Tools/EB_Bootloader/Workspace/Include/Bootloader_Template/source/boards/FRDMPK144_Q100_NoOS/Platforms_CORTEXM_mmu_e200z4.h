/* PLATFORMS_PA_mmu_e200z4.h - header file for e200(z6) MMU
 *
 * This file is actually used to create a initial MMU configuration
 * within reset code. The reset code calls PLATFORMS_PAResetCodeTlbFill() which is
 * located in the same MMU page because safety CPU starts up with a 1KB code
 * page and nothing else.
 *
 * MMU support for z4 core not implemented.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * (c) 2015 Elektrobit Automotive GmbH
 *
*/

#ifndef __PLATFORMS_PA_MMU_E200Z4_H
#define __PLATFORMS_PA_MMU_E200Z4_H

#if (PLATFORMS_PA_VLE==1)
#define PLATFORMS_MMU_MEM_FLASH_FLAGS  (0x0 | PLATFORMS_MAS2_VLE)
#else
#define PLATFORMS_MMU_MEM_FLASH_FLAGS  (0x0)
#endif
#define PLATFORMS_MMU_MEM_RAM_FLAGS    (0x0 | PLATFORMS_MAS2_I)
#define PLATFORMS_MMU_MEM_IO_FLAGS     (0x0 | PLATFORMS_MAS2_W | PLATFORMS_MAS2_I | PLATFORMS_MAS2_M | PLATFORMS_MAS2_G)

#define PLATFORMS_MMU_CREATE_TLB_SET(startAddress,pageSize,accessRights,flags) \
  PLATFORMS_MAS1_VALID|(pageSize),((startAddress)&PLATFORMS_MAS2_EPN)|(flags),((startAddress)&PLATFORMS_MAS3_RPN)|(accessRights)
#define PLATFORMS_MMU_CREATE_TLB_MAP(effectiveAddress,realAddress,pageSize,accessRights,flags) \
  PLATFORMS_MAS1_VALID|(pageSize),((effectiveAddress)&PLATFORMS_MAS2_EPN)|(flags),((realAddress)&PLATFORMS_MAS3_RPN)|(accessRights)
#define PLATFORMS_MMU_MAS0_DEFAULT(tlbIndex) \
  (PLATFORMS_MAS0_TLBSEL|((tlbIndex)<<16)|PLATFORMS_MAS0_NV)
/* Bit fields in MAS0
*/
#define PLATFORMS_MAS0_TLBSEL 0x10000000    /* TLB selection (ignored by e200z6, set to 01 for future compatibility) */
#define PLATFORMS_MAS0_TLB_1  0x10000000
#define PLATFORMS_MAS0_ESEL   0x000f0000    /* Entry select for TLB1 */
#define PLATFORMS_MAS0_ESEL1  0x00010000
#define PLATFORMS_MAS0_NV     0x0000000f    /* Next victim for TLB1 (Copied to ESEL on TLB error) */

/* Bit fields in MAS1
*/
#define PLATFORMS_MAS1_VALID  0x80000000    /* TLB entry is valid (if 1) */
#define PLATFORMS_MAS1_IPROT  0x40000000    /* Protection from invalidation */
#define PLATFORMS_MAS1_TID    0x00ff0000    /* TID (matches against PID, 0 matches all) */
#define PLATFORMS_MAS1_TS    0x00001000     /* Translation space (matches against IS or DS depending on access type) */
#define PLATFORMS_MAS1_TSIZE  0x00000f80    /* Entry page size */

#define PLATFORMS_MAS1_TSIZE_REG_VAL(x)    ((x)<<7)
#define PLATFORMS_MAS1_TSIZE_1K  PLATFORMS_MAS1_TSIZE_REG_VAL(0)
#define PLATFORMS_MAS1_TSIZE_2K  PLATFORMS_MAS1_TSIZE_REG_VAL(1)
#define PLATFORMS_MAS1_TSIZE_4K  PLATFORMS_MAS1_TSIZE_REG_VAL(2)
#define PLATFORMS_MAS1_TSIZE_8K  PLATFORMS_MAS1_TSIZE_REG_VAL(3)
#define PLATFORMS_MAS1_TSIZE_16K  PLATFORMS_MAS1_TSIZE_REG_VAL(4)
#define PLATFORMS_MAS1_TSIZE_32K  PLATFORMS_MAS1_TSIZE_REG_VAL(5)
#define PLATFORMS_MAS1_TSIZE_64K  PLATFORMS_MAS1_TSIZE_REG_VAL(6)
#define PLATFORMS_MAS1_TSIZE_128K  PLATFORMS_MAS1_TSIZE_REG_VAL(7)
#define PLATFORMS_MAS1_TSIZE_256K  PLATFORMS_MAS1_TSIZE_REG_VAL(8)
#define PLATFORMS_MAS1_TSIZE_512K  PLATFORMS_MAS1_TSIZE_REG_VAL(9)
#define PLATFORMS_MAS1_TSIZE_1M  PLATFORMS_MAS1_TSIZE_REG_VAL(10)
#define PLATFORMS_MAS1_TSIZE_2M  PLATFORMS_MAS1_TSIZE_REG_VAL(11)
#define PLATFORMS_MAS1_TSIZE_4M  PLATFORMS_MAS1_TSIZE_REG_VAL(12)
#define PLATFORMS_MAS1_TSIZE_8M  PLATFORMS_MAS1_TSIZE_REG_VAL(13)
#define PLATFORMS_MAS1_TSIZE_16M  PLATFORMS_MAS1_TSIZE_REG_VAL(14)
#define PLATFORMS_MAS1_TSIZE_32M  PLATFORMS_MAS1_TSIZE_REG_VAL(15)
#define PLATFORMS_MAS1_TSIZE_64M  PLATFORMS_MAS1_TSIZE_REG_VAL(16)
#define PLATFORMS_MAS1_TSIZE_128M  PLATFORMS_MAS1_TSIZE_REG_VAL(17)
#define PLATFORMS_MAS1_TSIZE_256M  PLATFORMS_MAS1_TSIZE_REG_VAL(18)
#define PLATFORMS_MAS1_TSIZE_512M  PLATFORMS_MAS1_TSIZE_REG_VAL(19)
#define PLATFORMS_MAS1_TSIZE_1G  PLATFORMS_MAS1_TSIZE_REG_VAL(20)
#define PLATFORMS_MAS1_TSIZE_2G  PLATFORMS_MAS1_TSIZE_REG_VAL(21)
#define PLATFORMS_MAS1_TSIZE_4G  PLATFORMS_MAS1_TSIZE_REG_VAL(22)


/* Bit fields in MAS2
*/
#define PLATFORMS_MAS2_EPN    0xfffffc00  /* Effective page number */
#define PLATFORMS_MAS2_VLE     0x00000020 /* VLE */
#define PLATFORMS_MAS2_W    0x00000010    /* Writethrough */
#define PLATFORMS_MAS2_I    0x00000008    /* Cache-inhibit */
#define PLATFORMS_MAS2_M    0x00000004    /* Memory coherence required (not supported on e200z6) */
#define PLATFORMS_MAS2_G    0x00000002    /* Guarded (for speculative processing, not on e200z6) */
#define PLATFORMS_MAS2_E    0x00000001    /* Endianness (0=big, 1=little) */

/* Bit fields in MAS3
*/
#define PLATFORMS_MAS3_RPN    0xfffffc00    /* Real page number */
#define PLATFORMS_MAS3_U    0x000003c0      /* User bits */
#define PLATFORMS_MAS3_U1    0x00000040     /* User bits with value b0001 */
#define PLATFORMS_MAS3_PERMIS  0x0000003f   /* Permission bits */
#define PLATFORMS_MAS3_UX    0x00000020     /* User execute */
#define PLATFORMS_MAS3_SX    0x00000010     /* Supervisor execute */
#define PLATFORMS_MAS3_UW    0x00000008     /* User write */
#define PLATFORMS_MAS3_SW    0x00000004     /* Supervisor write */
#define PLATFORMS_MAS3_UR    0x00000002     /* User read */
#define PLATFORMS_MAS3_SR    0x00000001     /* Supervisor read */

/* Bit fields in MAS4
*/
#define PLATFORMS_MAS4_TLBSELD  0x30000000  /* Default TLB selected (use 01 for e200z6) */
#define PLATFORMS_MAS4_TIDSELD  0x00030000  /* Default PID# to load TID from (00 = PID0, 11 = zero, 10 & 01 reserved) */
#define PLATFORMS_MAS4_TSIZED  0x00000f80   /* Default TSIZE value */
#define PLATFORMS_MAS4_DWIMGE  0x0000003f   /* Default WIMGE values */

/* Bit fields in MAS6
*/
#define PLATFORMS_MAS6_SPID  0x00ff0000     /* PID value for searches */
#define PLATFORMS_MAS6_SAS    0x00000001    /* AS value for searches */


#endif
/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
