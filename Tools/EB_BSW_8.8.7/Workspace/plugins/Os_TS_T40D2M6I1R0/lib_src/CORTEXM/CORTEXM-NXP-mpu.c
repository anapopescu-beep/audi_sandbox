/* CORTEXM-NXP-mpu.c - functions that deal with memory protection.
 *
 * This file contains the CORTEXM-specific functions to enable
 * and (re)program the MPU.
 *
 * (c) Elektrobit Automotive GmbH
 *
 * $Id: CORTEXM-NXP-mpu.c 1.1 2023/04/18 07:06:22CEST Dan Dustinta (dan.dustinta) in_work  $
*/

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 17.2 (required)
 *   Functions shall not call themselves, either directly or indirectly.
 *
 * Reason:
 *   OS_NXPMPU_SetRegion() can call OS_Panic() directly,
 *   OS_DisableDynamicRegions(), OS_SetProtection(), OS_SetIsrProtection() and
 *   OS_SetHookProtection() can call OS_Panic() indirectly.
 *   OS_Panic() detects recursive calls by means of the core-local variable
 *   panicCode. If OS_Panic() is entered a second time, it calls
 *   OS_ShutdownNoHooks() which doesn't call OS_Panic() again. Instead, it
 *   stops the system, and, therefore, the maximum nesting level is two calls.
*/

#include <Os_kernel.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)

#include <CORTEXM/Os_mpu_CORTEXM_NXP.h>

#include <memmap/Os_mm_const_begin.h>
static os_nxpmpu_t * const os_mpu = (os_nxpmpu_t*)OS_NXPMPU_ADDR;
#include <memmap/Os_mm_const_end.h>

#include <memmap/Os_mm_code_begin.h>

/* prototype definitions */
static void OS_CheckMpuSupported(void);
static void OS_SetupStaticRegions(void);
static void OS_DisableDynamicRegions(void);

/* OS_CheckMpuSupported() - Check, if the MPU is supported by the OS */
OS_TOOL_FUNCTION_ATTRIB_PRE
static void OS_CheckMpuSupported(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	/* check the functional definition of the NXP MPU module */
	if (OS_NXPMPU_HRL_VAL == OS_NXPMPU_HRL_GET(os_mpu->cesr))
	{
		/* This NXP MPU is supported */
	}
	else
	{
		(void)OS_Panic(OS_PANIC_SCHK_MpuNotSupported);
		/* NOT REACHED */
	}
}

/* Disable the dynamic regions */
/* Deviation MISRAC2012-1 <1> */
OS_TOOL_FUNCTION_ATTRIB_PRE
static void OS_DisableDynamicRegions(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	/* OS_MPU_USERSTACK_RNR: STACK */
	OS_NXPMPU_SetRegion(OS_MPU_USERSTACK_RNR, 0u, OS_NXPMPU_ALIGN_END(0u), 0u, 0u);
	/* OS_MPU_USERDATA_RNR: DATA */
	OS_NXPMPU_SetRegion(OS_MPU_USERDATA_RNR, 0u, OS_NXPMPU_ALIGN_END(0u), 0u, 0u);
	/* OS_MPU_USERAPPDATA_RNR: APP-DATA */
	OS_NXPMPU_SetRegion(OS_MPU_USERAPPDATA_RNR, 0u, OS_NXPMPU_ALIGN_END(0u), 0u, 0u);
}

/* OS_SetupStaticRegions - program the static regions in the MPU.
 *
 * This functions programs the static regions into the MPU.
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
static void OS_SetupStaticRegions(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_uint32_t accOpts;
	os_reg32_t * const os_nxpmpu_rgdaac = (os_reg32_t *)OS_NXPMPU_RGDAAC_ADDR;

	/* The general rule of NXP MPU states: "Granting permission is a
	 * higher priority than denying access for overlapping regions."
	 * Define a global "background" OS_MPU_BACKGROUD_RNR restricting unnecessary accesses. */
	accOpts  = OS_NXPMPU_ACCBITS_BM03(OS_NXPMPU_BM03_UNSN, 0);	/* Core0:		(--- ---)	*/
	accOpts |= OS_NXPMPU_ACCBITS_BM03(OS_NXPMPU_BM03_UASA, 1);	/* Debugger:	(rwx RWX)	*/
	accOpts |= OS_NXPMPU_ACCBITS_BM03(OS_NXPMPU_BM03_UNSN, 2);	/* DMA:			(--- ---)	*/
	accOpts |= OS_NXPMPU_ACCBITS_BM03(OS_NXPMPU_BM03_UNSN, 3);	/* ENET:		(--- ---)	*/
	accOpts |= OS_NXPMPU_ACCBITS_BM47(OS_NXPMPU_BM47_NO, 4);	/* BM4			(---)		*/
	accOpts |= OS_NXPMPU_ACCBITS_BM47(OS_NXPMPU_BM47_NO, 5);	/* BM5			(---)		*/
	accOpts |= OS_NXPMPU_ACCBITS_BM47(OS_NXPMPU_BM47_NO, 6);	/* BM6			(---)		*/
	accOpts |= OS_NXPMPU_ACCBITS_BM47(OS_NXPMPU_BM47_NO, 7);	/* BM7			(---)		*/

	/* OS_MPU_BACKGROUD_RNR is pre-configured, only the accOpts should to be updated.
	 * This can only be done using the Alternate Access Control Region Descriptor */
	os_nxpmpu_rgdaac[OS_MPU_BACKGROUD_RNR] = accOpts;

	/* OS_MPU_ROM_RNR: FLASH, give permissions (override the "background" region) */
	accOpts  = OS_NXPMPU_ACCBITS_BM03(OS_NXPMPU_BM03_URXSRX, 0);	/* Core0:	(r-x R-X)	*/
	OS_NXPMPU_SetRegion(OS_MPU_ROM_RNR,
						OS_NXPMPU_ALIGN_START((os_uint32_t)OS_romBase),
						OS_NXPMPU_ALIGN_END((os_uint32_t)OS_romLimit),
						accOpts,
						OS_NXPMPU_RGN_ENABLE);

	/* OS_MPU_RAM_RNR: RAM, give permissions (override the "background" region) */
	accOpts  = OS_NXPMPU_ACCBITS_BM03(OS_NXPMPU_BM03_UROSRO, 0);	/* Core0:	(r-- R--)	*/
	accOpts |= OS_NXPMPU_ACCBITS_BM03(OS_NXPMPU_BM03_UROSRO, 2);	/* DMA:		(r-- R--)	*/
	accOpts |= OS_NXPMPU_ACCBITS_BM03(OS_NXPMPU_BM03_UROSRO, 3);	/* ENET:	(r-- R--)	*/
	OS_NXPMPU_SetRegion(OS_MPU_RAM_RNR,
						OS_NXPMPU_ALIGN_START((os_uint32_t)OS_ramBase),
						OS_NXPMPU_ALIGN_END((os_uint32_t)OS_ramLimit),
						accOpts,
						OS_NXPMPU_RGN_ENABLE);

	/* OS_MPU_KERNSTACK_RNR: Kernel Stack, give permissions (override the "background" region) */
	accOpts  = OS_NXPMPU_ACCBITS_BM03(OS_NXPMPU_BM03_SRW, 0);		/* Core0:	(--- RW-)	*/
	OS_NXPMPU_SetRegion(OS_MPU_KERNSTACK_RNR,
						OS_NXPMPU_ALIGN_START((os_uint32_t)OS_GetKernelData()->iStackBase),
						OS_NXPMPU_ALIGN_END((os_uint32_t)OS_GetKernelData()->iSpInitial),
						accOpts,
						OS_NXPMPU_RGN_ENABLE);
}

/* OS_EnterProtectedMode
 *
 * This function initializes memory protection settings.
 * IRQs are handled in handler mode, which is privileged. Therefore,
 * we cannot have privileged regions. Therefore, we keep the MPU disabled
 * while in the kernel (or when executing trusted code).
 *
 * Only for non-trusted OS objects, we enable the MPU during kernel exit.
 * That way, we just need the dynamic regions + a global read-only and a
 * global execute region.
 *
 * Disabling the MPU during kernel entry:
 * NXP's MPU (unlike the ARMv7-M MPU) is not disabled automatically
 * on setting the Fault mask. On a system call (which originates from
 * user-space) the MPU has to be disabled, but it is practically not
 * possible: kernel stack is write-protected, all registers are occupied,
 * 'push' results in an access violation.
 * For this reason a static region, allowing write access in privileged mode
 * to the Kernel stack has to be configured. Taking into account, that IRQs are
 * handled in privileged mode, the following requirements can not be fulfilled
 * using NXP's SMPU on Cortex-M:
 *
 * !LINKSTO Kernel.Autosar.Protection.HardwareProtection.TaskISR.Stack.WriteSameApp, 1
 * !LINKSTO Kernel.Autosar.Protection.HardwareProtection.TaskISR.Stack.WriteOtherApp, 1
 * !LINKSTO Kernel.Autosar.Protection.HardwareProtection.TaskISR.Data.WriteSameApp, 1
 * !LINKSTO Kernel.Autosar.Protection.HardwareProtection.TaskISR.Data.WriteOtherApp, 1
 * !LINKSTO Kernel.Autosar.Protection.HardwareProtection.Peripherals.NontrustedApps, 2
 *
 * ------------------------------------------------------------------------------------
 *
 * Everyone:
 * - entire flash is executable
 * - entire ram is readable
 *
 * All entities running in privileged mode:
 * - kernel stack is writeable
 *
 * Others:
 * - own stack is writeable
 * - own application data is writeable
 * - own task data is writeable
 *
 * This leads to the following configuration for the bus master 0 (CPU Core)
 *
 * Region 0: entire addr.space	(--- ---), static
 * Region 1: entire flash		(r-x R-X), static
 * Region 2: entire ram			(r-- R--), static
 * Region 3: kernel stack		(--- RW-), static
 * Region 4: task/ISR stack		(rw- RW-), dynamic
 * Region 5: task/ISR data		(rw- RW-), dynamic
 * Region 6: task/ISR app data	(rw- RW-), dynamic
 *
 * !LINKSTO Kernel.Autosar.Protection.HardwareProtection, 1
*/
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_EnterProtectedMode(void)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	OS_CheckMpuSupported();
	OS_SetupStaticRegions();
	OS_DisableDynamicRegions();
}

/* OS_NXPMPU_SetRegion - program one MPU region.
 * Parameters:
 *	rgn_num		--	region number
 *	rgn_start	--	32 byte alligned start address of the memory region
 *	rgn_end		--	32 byte alligned end address of the memory region
 *	rgn_ac_opt	--	access control rights of the memory region
 *	rgn_pid_opt	--	pid, pid-mask of the memory region, and the region-enable bit
*/
/* Deviation MISRAC2012-1 <2> */
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_NXPMPU_SetRegion
(
	os_uint32_t rgn_num,
	os_uint32_t rgn_start,
	os_uint32_t rgn_end,
	os_uint32_t rgn_ac_opt,
	os_uint32_t rgn_pid_opt
)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_nxpmpu_rgd_t * const os_mpu_rgd_tab = (os_nxpmpu_rgd_t *)OS_NXPMPU_RGD_ADDR;
	os_boolean_t input_correct = OS_TRUE;

	/* region-start address has to be less than or equal to region-end address */
	if (rgn_start > rgn_end)
	{
		input_correct = OS_FALSE;
	}

	/* check alignment of the start address */
	if (0 != (rgn_start & OS_NXPMPU_ALIGNMASK))
	{
		input_correct = OS_FALSE;
	}

	/* check alignment of the end address */
	if (OS_NXPMPU_ALIGNMASK != (rgn_end & OS_NXPMPU_ALIGNMASK))
	{
		input_correct = OS_FALSE;
	}

	if (OS_TRUE == input_correct)
	{
		/* Writing sequence is important! */
		os_mpu_rgd_tab[rgn_num].w0_start = rgn_start;
		os_mpu_rgd_tab[rgn_num].w1_end	= rgn_end;
		os_mpu_rgd_tab[rgn_num].w2_acr	= rgn_ac_opt;
		os_mpu_rgd_tab[rgn_num].w3_pid	= rgn_pid_opt;
	}
	else
	{
		(void)OS_Panic(OS_PANIC_SCHK_InvalidMpuSetup);
		/* NOT REACHED */
	}
}

/* OS_SetProtection (set task protection)
 *
 * This function configures the dynamic MPU regions for the given task.
 * See OS_EnterProtectedMode() how the regions are separated into static and
 * dynamic.
 *
 * !LINKSTO Kernel.Autosar.Protection.HardwareProtection, 1
*/
/* Deviation MISRAC2012-1 <3> */
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_SetProtection(const os_task_t *t)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_uint32_t accOpts;
	const os_appcontext_t *a = OS_GET_APP(t->app);

	if (OS_AppIsTrusted(a))
	{
		/* Disable dynamic regions */
		OS_DisableDynamicRegions();
		/* Thread mode is privileged. */
		OS_CORTEXM_SetControl(OS_CORTEXM_CONTROL_SP_PROCESS);
	}
	else
	{
		OS_CORTEXM_SetControl(((os_uint32_t)OS_CORTEXM_CONTROL_SP_PROCESS)
							| ((os_uint32_t)OS_CORTEXM_CONTROL_NPRIV));
		/* OS_MPU_USERSTACK_RNR: STACK, non-privileged mode */
		accOpts  = OS_NXPMPU_ACCBITS_BM03(OS_NXPMPU_BM03_URWSRW, 0);		/* Core0: (rw-rw-) */
		OS_NXPMPU_SetRegion(OS_MPU_USERSTACK_RNR,
			OS_NXPMPU_ALIGN_START((os_uint32_t)t->stackBase),
			OS_NXPMPU_ALIGN_END(((os_uint32_t)t->stackBase + (os_uint32_t)t->stackLen) - 1),
			accOpts,
			OS_NXPMPU_RGN_ENABLE);

		/* Task data region. Only if region is not empty */
		if (t->dataStart != t->dataEnd)
		{
			/* OS_MPU_USERDATA_RNR: TASK-DATA */
			accOpts  = OS_NXPMPU_ACCBITS_BM03(OS_NXPMPU_BM03_URWSRW, 0);	/* Core0: (rw-rw-) */
			OS_NXPMPU_SetRegion(OS_MPU_USERDATA_RNR,
				OS_NXPMPU_ALIGN_START((os_uint32_t)t->dataStart),
				OS_NXPMPU_ALIGN_END((os_uint32_t)t->dataEnd - 1),
				accOpts,
				OS_NXPMPU_RGN_ENABLE);
		}
		else
		{
			OS_NXPMPU_SetRegion(OS_MPU_USERDATA_RNR, 0u, OS_NXPMPU_ALIGN_END(0u), 0u, 0u);
		}

		/* Application data region */
		if (a->dataStart != a->dataEnd)
		{
			/* OS_MPU_USERAPPDATA_RNR: APP-DATA */
			accOpts  = OS_NXPMPU_ACCBITS_BM03(OS_NXPMPU_BM03_URWSRW, 0);	/* Core0: (rw-rw-) */
			OS_NXPMPU_SetRegion(OS_MPU_USERAPPDATA_RNR,
				OS_NXPMPU_ALIGN_START((os_uint32_t)a->dataStart),
				OS_NXPMPU_ALIGN_END((os_uint32_t)a->dataEnd - 1),
				accOpts,
				OS_NXPMPU_RGN_ENABLE);
		}
		else
		{
			OS_NXPMPU_SetRegion(OS_MPU_USERAPPDATA_RNR, 0u, OS_NXPMPU_ALIGN_END(0u), 0u, 0u);
		}
	}
}

/* OS_SetIsrProtection
 *
 * This function configures the dynamic MPU regions for the given ISR.
 * See OS_EnterProtectedMode() how the regions are separated into static and
 * dynamic.
 *
 * !LINKSTO Kernel.Autosar.Protection.HardwareProtection, 1
*/
/* Deviation MISRAC2012-1 <4> */
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_SetIsrProtection(const os_isr_t *isr, os_isrdynamic_t *id)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_uint32_t accOpts;
	const os_appcontext_t *a = OS_GET_APP(isr->app);

	if (OS_AppIsTrusted(a))
	{
		/* Disable dynamic regions */
		OS_DisableDynamicRegions();
	}
	else
	{
		/* OS_MPU_USERSTACK_RNR: STACK */
		accOpts  = OS_NXPMPU_ACCBITS_BM03(OS_NXPMPU_BM03_URWSRW, 0);		/* Core0: (rw-rw-) */
		OS_NXPMPU_SetRegion(OS_MPU_USERSTACK_RNR,
			OS_NXPMPU_ALIGN_START((os_uint32_t)(id->c.stackLimit) - (os_uint32_t)(isr->stackLen)),
			OS_NXPMPU_ALIGN_END((os_uint32_t)(id->c.stackLimit) - 1),
			accOpts,
			OS_NXPMPU_RGN_ENABLE);

		/* ISR data region. Only if region is not empty */
		if (isr->dataStart != isr->dataEnd)
		{
			/* OS_MPU_USERDATA_RNR: ISR-DATA */
			accOpts  = OS_NXPMPU_ACCBITS_BM03(OS_NXPMPU_BM03_URWSRW, 0);	/* Core0: (rw-rw-) */
			OS_NXPMPU_SetRegion(OS_MPU_USERDATA_RNR,
				OS_NXPMPU_ALIGN_START((os_uint32_t)isr->dataStart),
				OS_NXPMPU_ALIGN_END((os_uint32_t)isr->dataEnd - 1),
				accOpts,
				OS_NXPMPU_RGN_ENABLE);
		}
		else
		{
			OS_NXPMPU_SetRegion(OS_MPU_USERDATA_RNR, 0u, OS_NXPMPU_ALIGN_END(0u), 0u, 0u);
		}

		/* Application data region */
		if (a->dataStart != a->dataEnd)
		{
			/* OS_MPU_USERAPPDATA_RNR: APP-DATA */
			accOpts  = OS_NXPMPU_ACCBITS_BM03(OS_NXPMPU_BM03_URWSRW, 0);	/* Core0: (rw-rw-) */
			OS_NXPMPU_SetRegion(OS_MPU_USERAPPDATA_RNR,
				OS_NXPMPU_ALIGN_START((os_uint32_t)a->dataStart),
				OS_NXPMPU_ALIGN_END((os_uint32_t)a->dataEnd - 1),
				accOpts,
				OS_NXPMPU_RGN_ENABLE);
		}
		else
		{
			OS_NXPMPU_SetRegion(OS_MPU_USERAPPDATA_RNR, 0u, OS_NXPMPU_ALIGN_END(0u), 0u, 0u);
		}
	}
}

/* OS_SetHookProtection
 *
 * This function configures the dynamic MPU regions for the given hook.
 * See OS_EnterProtectedMode() how the regions are separated into static and
 * dynamic.
 *
 * !LINKSTO Kernel.Autosar.Protection.HardwareProtection, 1
*/
/* Deviation MISRAC2012-1 <5> */
OS_TOOL_FUNCTION_ATTRIB_PRE
void OS_SetHookProtection
(
	const os_appcontext_t *a,
	os_savedcontext_t *savedContext,
	os_size_t stklen
)
OS_TOOL_FUNCTION_ATTRIB_POST
{
	os_uint32_t accOpts;
	OS_PARAM_UNUSED(stklen);

	if (OS_AppIsTrusted(a))
	{
		/* Disable dynamic regions */
		OS_DisableDynamicRegions();
	}
	else
	{
		/* OS_MPU_USERSTACK_RNR: STACK */
		accOpts  = OS_NXPMPU_ACCBITS_BM03(OS_NXPMPU_BM03_URWSRW, 0);		/* Core0: (rw-rw-) */
		OS_NXPMPU_SetRegion(OS_MPU_USERSTACK_RNR,
			OS_NXPMPU_ALIGN_START((os_uint32_t)savedContext->stackLimit),
			OS_NXPMPU_ALIGN_END((os_uint32_t)savedContext->sp - 1),
			accOpts,
			OS_NXPMPU_RGN_ENABLE);

		/* Hooks have no data region. Disable. */
		OS_NXPMPU_SetRegion(OS_MPU_USERDATA_RNR, 0u, OS_NXPMPU_ALIGN_END(0u), 0u, 0u);

		/* Application data region */
		if (a->dataStart != a->dataEnd)
		{
			/* OS_MPU_USERAPPDATA_RNR: APP-DATA */
			accOpts  = OS_NXPMPU_ACCBITS_BM03(OS_NXPMPU_BM03_URWSRW, 0);	/* Core0: (rw-rw-) */
			OS_NXPMPU_SetRegion(OS_MPU_USERAPPDATA_RNR,
				OS_NXPMPU_ALIGN_START((os_uint32_t)a->dataStart),
				OS_NXPMPU_ALIGN_END(((os_uint32_t)a->dataEnd) - 1),
				accOpts,
				OS_NXPMPU_RGN_ENABLE);
		}
		else
		{
			OS_NXPMPU_SetRegion(OS_MPU_USERAPPDATA_RNR, 0u, OS_NXPMPU_ALIGN_END(0u), 0u, 0u);
		}
	}
}

#include <memmap/Os_mm_code_end.h>

#else /* (!(OS_KERNEL_TYPE != OS_MICROKERNEL)) */
const os_uint8_t OS_dummy_CORTEXM_NXP_mpu_c = 0xeb;
#endif /* (OS_KERNEL_TYPE != OS_MICROKERNEL) */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
