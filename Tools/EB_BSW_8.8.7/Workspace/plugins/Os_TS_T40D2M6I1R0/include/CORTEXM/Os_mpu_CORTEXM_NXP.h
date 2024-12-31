/* Os_mpu_CORTEXM_NXP.h - NXP implementation of an MPU for CORTEXM
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_mpu_CORTEXM_NXP.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/

#ifndef OS_MPU_CORTEXM_NXP_H
#define OS_MPU_CORTEXM_NXP_H

#include <Os_types.h>

#define OS_NXPMPU_ADDR			0x4000D000u	/* MPU Base address								*/
#define OS_NXPMPU_RGD_ADDR		0x4000D400u	/* Region Descriptor Table Address				*/
#define OS_NXPMPU_RGDAAC_ADDR	0x4000D800u	/* Reg. Desc. Alternate Access Control Address	*/
#define OS_NXPMPU_RGD_N			8u			/* 8x128-bit r.descriptors, 32-bit access only	*/
#define OS_NXPMPU_ALIGNMASK		0x1Fu		/* region addresses must be 32-byte alligned	*/

#define OS_NXPMPU_ALIGN_START(addr) \
	((addr) & (~OS_NXPMPU_ALIGNMASK))		/* Find next lower 32-byte aligned address		*/

#define OS_NXPMPU_ALIGN_END(addr) \
	((addr) | OS_NXPMPU_ALIGNMASK)			/* Find next higher 31-mod-32-byte address		*/

#define OS_NXPMPU_HRL_VAL		1u			/* MPU’s hardware and definition revision level	*/
#define OS_NXPMPU_HRL_GET(reg) \
	(((reg) >> 16u) & 0xfu)					/* Access the NXP MPU HRL */

#define OS_NXPMPU_ENABLE		1u			/* Enable MPU Module */
#define OS_NXPMPU_RGN_ENABLE	1u			/* Enable region */

#define OS_NXPMPU_BM_N			3u			/* Number of BUS-Masters, that are used			*/

#define OS_NXPMPU_BM_COR0		0u			/* BUS-Master 0: Core-0		(6 bit)				*/
#define OS_NXPMPU_BM_DBGR		1u			/* BUS-Master 1: Debugger	(6 bit)				*/
#define OS_NXPMPU_BM_DMA0		2u			/* BUS-Master 2: DMA-0		(6 bit)				*/
#define OS_NXPMPU_BM3			3u			/* BUS-Master 3: None		(6 bit)				*/
#define OS_NXPMPU_BM4			4u			/* BUS-Master 4: None		(2 bit)				*/
#define OS_NXPMPU_BM5			5u			/* BUS-Master 5: None		(2 bit)				*/
#define OS_NXPMPU_BM6			6u			/* BUS-Master 6: None		(2 bit)				*/
#define OS_NXPMPU_BM7			7u			/* BUS-Master 7: None		(2 bit)				*/

#define OS_NXPMPU_BM03_UR		4u			/* non-privileged read from bus-masters 0-3		*/
#define OS_NXPMPU_BM03_UW		2u			/* non-priv. write from bus-masters 0-3			*/
#define OS_NXPMPU_BM03_UX		1u			/* non-priv. exec. access from bus-masters 0-3	*/
#define OS_NXPMPU_BM03_UN		0u			/* non-priv. no access from bus-masters 0-3		*/
#define OS_NXPMPU_BM03_SA		(0u	<< 3u)	/* privileged R+W+X access from bus-masters 0-3	*/
#define OS_NXPMPU_BM03_SRX		(1u << 3u)	/* privileged R+X from bus-masters 0-3			*/
#define OS_NXPMPU_BM03_SRW		(2u << 3u)	/* privileged R+W from bus-masters 0-3			*/
#define OS_NXPMPU_BM03_SU		(3u << 3u)	/* Same rights as of the user, bus-master 0-3	*/
#define OS_NXPMPU_BM47_R		2u			/* Read access, bus-masters 4-7					*/
#define OS_NXPMPU_BM47_W		1u			/* Write access, bus-masters 4-7				*/
#define OS_NXPMPU_BM47_NO		0u			/* No access from bus-masters 4-7				*/
#define OS_NXPMPU_BM01_PID		(1u << 5u)	/* Process-ID enable for bus-masters 0-1		*/

#define OS_NXPMPU_BM03_UA		(OS_NXPMPU_BM03_UR | OS_NXPMPU_BM03_UW | OS_NXPMPU_BM03_UX)
#define OS_NXPMPU_BM03_UNSA		(OS_NXPMPU_BM03_UN | OS_NXPMPU_BM03_SA)
#define OS_NXPMPU_BM03_UASA		(OS_NXPMPU_BM03_UA | OS_NXPMPU_BM03_SA)
#define OS_NXPMPU_BM03_URXSRX	(OS_NXPMPU_BM03_UR | OS_NXPMPU_BM03_UX | OS_NXPMPU_BM03_SU)
#define OS_NXPMPU_BM03_UROSRO	(OS_NXPMPU_BM03_UR | OS_NXPMPU_BM03_SU)
#define OS_NXPMPU_BM03_UNSN		(OS_NXPMPU_BM03_UN | OS_NXPMPU_BM03_SU)
#define OS_NXPMPU_BM03_URWSRW	(OS_NXPMPU_BM03_UR | OS_NXPMPU_BM03_UW | OS_NXPMPU_BM03_SU)
#define OS_NXPMPU_BM03_UNSRW	(OS_NXPMPU_BM03_UN | OS_NXPMPU_BM03_SRW)

/* Preprare (trim and shift) the 'vl' value according to the given bus-master (bm)
 * input:	vl -- access rights, bm -- bus master
 * Access rights for bus masters 0-3 are defined with 6 bits.
 * Access rights for bus masters 4-7 are defined with 2 bits.
 */
#define OS_NXPMPU_ACCBITS_BM03(vl, bm) \
	OS_ShiftLeftU32(((os_reg32_t)(vl) & 0x3Fu), ((bm) * 6u))

#define OS_NXPMPU_ACCBITS_BM47(vl, bm) \
	OS_ShiftLeftU32(((os_reg32_t)(vl) & 0x3u), (24u + (((bm) - 4u) * 2u)))

/* Region indices for all MPU regions that are used by the OS. */
#define OS_MPU_BACKGROUD_RNR		OS_U(0)
#define OS_MPU_ROM_RNR				OS_U(1)
#define OS_MPU_RAM_RNR				OS_U(2)
#define OS_MPU_KERNSTACK_RNR		OS_U(3)
#define OS_MPU_USERSTACK_RNR		OS_U(4)
#define OS_MPU_USERDATA_RNR			OS_U(5)
#define OS_MPU_USERAPPDATA_RNR		OS_U(6)

/* Bit defintions for CESR. */
#define OS_NXPMPU_CESR_VLD			(1 << 0)

#ifndef OS_ASM
typedef struct os_nxpmpu_s os_nxpmpu_t;
struct os_nxpmpu_s							/* control and status registers of the NXP MPU	*/
{
	os_reg32_t  cesr;						/* 0x00 -- Control/Error Status (CESR)			*/
	os_reg32_t  _pad[3];					/* 0x04	-- 3 words padding: 0x04, 0x08, 0x0C	*/
	os_reg32_t  ear0;						/* 0x10	-- Error Address, slave port 0 (EAR0)	*/
	os_reg32_t  edr0;						/* 0x14	-- Error Detail, slave port 0 (EDR0)	*/
	os_reg32_t  ear1;						/* 0x18	-- Error Address, slave port 1 (EAR0)	*/
	os_reg32_t  edr1;						/* 0x1C	-- Error Detail, slave port 1 (EDR0)	*/
	os_reg32_t  ear2;						/* 0x20	-- Error Address, slave port 2 (EAR0)	*/
	os_reg32_t  edr2;						/* 0x24	-- Error Detail, slave port 2 (EDR0)	*/
	os_reg32_t  ear3;						/* 0x28	-- Error Address, slave port 3 (EAR0)	*/
	os_reg32_t  edr3;						/* 0x2C	-- Error Detail, slave port 3 (EDR0)	*/
};

typedef struct os_nxpmpu_rgd_s os_nxpmpu_rgd_t;
struct os_nxpmpu_rgd_s						/* region descriptors of the NXP MPU			*/
{
	os_reg32_t  w0_start;					/* 0xX0	--	32 byte alligned start address		*/
	os_reg32_t  w1_end;						/* 0xX4	--	32 byte alligned end address		*/
	os_reg32_t  w2_acr;						/* 0xX8	--	access control rights				*/
	os_reg32_t  w3_pid;						/* 0xXC	--	pid, pid-mask, valid bit			*/
};

extern const void * const OS_romBase;
extern const void * const OS_romLimit;

extern const void * const OS_ramBase;
extern const void * const OS_ramLimit;

/* Not needed for NXPMPU.
*/
#define OS_CORTEXM_RESETKERNSTACKRW(app)

#endif /* ifndef OS_ASM */

#endif /* OS_MPU_CORTEXM_NXP_H */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
