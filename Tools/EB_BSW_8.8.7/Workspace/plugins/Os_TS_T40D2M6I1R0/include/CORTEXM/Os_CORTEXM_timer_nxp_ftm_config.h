/* Os_CORTEXM_timer_nxp_ftm_config.h - configuration for NXP's FTM module
 *
 * This file should be included in
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_CORTEXM_timer_nxp_ftm_config.h 1.1 2023/04/18 07:06:16CEST Dan Dustinta (dan.dustinta) in_work  $
*/
#ifndef OS_CORTEXM_TIMER_NXP_FTM_CONFIG_H
#define OS_CORTEXM_TIMER_NXP_FTM_CONFIG_H

#include <CORTEXM/Os_CORTEXM_timer_nxp_ftm.h>

/* Default value for clock source is FTM clock (i.e. SYS_CLK)
*/
#ifndef OS_CORTEXM_NXP_FTM0_CLKSRC
#define OS_CORTEXM_NXP_FTM0_CLKSRC		OS_FTM_CLKS_FTM
#endif

#ifndef OS_CORTEXM_NXP_FTM1_CLKSRC
#define OS_CORTEXM_NXP_FTM1_CLKSRC		OS_FTM_CLKS_FTM
#endif

#ifndef OS_CORTEXM_NXP_FTM2_CLKSRC
#define OS_CORTEXM_NXP_FTM2_CLKSRC		OS_FTM_CLKS_FTM
#endif

#ifndef OS_CORTEXM_NXP_FTM3_CLKSRC
#define OS_CORTEXM_NXP_FTM3_CLKSRC		OS_FTM_CLKS_FTM
#endif

#ifndef OS_CORTEXM_NXP_FTM4_CLKSRC
#define OS_CORTEXM_NXP_FTM4_CLKSRC		OS_FTM_CLKS_FTM
#endif

#ifndef OS_CORTEXM_NXP_FTM5_CLKSRC
#define OS_CORTEXM_NXP_FTM5_CLKSRC		OS_FTM_CLKS_FTM
#endif

#ifndef OS_CORTEXM_NXP_FTM6_CLKSRC
#define OS_CORTEXM_NXP_FTM6_CLKSRC		OS_FTM_CLKS_FTM
#endif

#ifndef OS_CORTEXM_NXP_FTM7_CLKSRC
#define OS_CORTEXM_NXP_FTM7_CLKSRC		OS_FTM_CLKS_FTM
#endif

/* Default value for prescaler is divide-by-16
*/
#ifndef OS_CORTEXM_NXP_FTM0_PRESCALER
#define OS_CORTEXM_NXP_FTM0_PRESCALER	OS_FTM_PS_16
#elif ( (OS_CORTEXM_NXP_FTM0_PRESCALER < OS_FTM_PS_1) || (OS_CORTEXM_NXP_FTM0_PRESCALER > OS_FTM_PS_128) )
#error "FTM0 prescaler is out of range"
#endif

#ifndef OS_CORTEXM_NXP_FTM1_PRESCALER
#define OS_CORTEXM_NXP_FTM1_PRESCALER	OS_FTM_PS_16
#elif ( (OS_CORTEXM_NXP_FTM1_PRESCALER < OS_FTM_PS_1) || (OS_CORTEXM_NXP_FTM1_PRESCALER > OS_FTM_PS_128) )
#error "FTM1 prescaler is out of range"
#endif

#ifndef OS_CORTEXM_NXP_FTM2_PRESCALER
#define OS_CORTEXM_NXP_FTM2_PRESCALER	OS_FTM_PS_16
#elif ( (OS_CORTEXM_NXP_FTM2_PRESCALER < OS_FTM_PS_1) || (OS_CORTEXM_NXP_FTM2_PRESCALER > OS_FTM_PS_128) )
#error "FTM2 prescaler is out of range"
#endif

#ifndef OS_CORTEXM_NXP_FTM3_PRESCALER
#define OS_CORTEXM_NXP_FTM3_PRESCALER	OS_FTM_PS_16
#elif ( (OS_CORTEXM_NXP_FTM3_PRESCALER < OS_FTM_PS_1) || (OS_CORTEXM_NXP_FTM3_PRESCALER > OS_FTM_PS_128) )
#error "FTM3 prescaler is out of range"
#endif

#ifndef OS_CORTEXM_NXP_FTM4_PRESCALER
#define OS_CORTEXM_NXP_FTM4_PRESCALER	OS_FTM_PS_16
#elif ( (OS_CORTEXM_NXP_FTM4_PRESCALER < OS_FTM_PS_1) || (OS_CORTEXM_NXP_FTM4_PRESCALER > OS_FTM_PS_128) )
#error "FTM4 prescaler is out of range"
#endif

#ifndef OS_CORTEXM_NXP_FTM5_PRESCALER
#define OS_CORTEXM_NXP_FTM5_PRESCALER	OS_FTM_PS_16
#elif ( (OS_CORTEXM_NXP_FTM5_PRESCALER < OS_FTM_PS_1) || (OS_CORTEXM_NXP_FTM5_PRESCALER > OS_FTM_PS_128) )
#error "FTM5 prescaler is out of range"
#endif

#ifndef OS_CORTEXM_NXP_FTM6_PRESCALER
#define OS_CORTEXM_NXP_FTM6_PRESCALER	OS_FTM_PS_16
#elif ( (OS_CORTEXM_NXP_FTM6_PRESCALER < OS_FTM_PS_1) || (OS_CORTEXM_NXP_FTM6_PRESCALER > OS_FTM_PS_128) )
#error "FTM6 prescaler is out of range"
#endif

#ifndef OS_CORTEXM_NXP_FTM7_PRESCALER
#define OS_CORTEXM_NXP_FTM7_PRESCALER	OS_FTM_PS_16
#elif ( (OS_CORTEXM_NXP_FTM7_PRESCALER < OS_FTM_PS_1) || (OS_CORTEXM_NXP_FTM7_PRESCALER > OS_FTM_PS_128) )
#error "FTM7 prescaler is out of range"
#endif

#define OS_NsToTicks_FTM0_0(x)	OS_BoardFtm0NsToTicks(x)
#define OS_NsToTicks_FTM0_1(x)	OS_BoardFtm0NsToTicks(x)
#define OS_NsToTicks_FTM0_2(x)	OS_BoardFtm0NsToTicks(x)
#define OS_NsToTicks_FTM0_3(x)	OS_BoardFtm0NsToTicks(x)

#define OS_TicksToNs_FTM0_0(x)	OS_BoardFtm0TicksToNs(x)
#define OS_TicksToNs_FTM0_1(x)	OS_BoardFtm0TicksToNs(x)
#define OS_TicksToNs_FTM0_2(x)	OS_BoardFtm0TicksToNs(x)
#define OS_TicksToNs_FTM0_3(x)	OS_BoardFtm0TicksToNs(x)

#define OS_NsToTicks_FTM1_0(x)	OS_BoardFtm1NsToTicks(x)
#define OS_NsToTicks_FTM1_1(x)	OS_BoardFtm1NsToTicks(x)
#define OS_NsToTicks_FTM1_2(x)	OS_BoardFtm1NsToTicks(x)
#define OS_NsToTicks_FTM1_3(x)	OS_BoardFtm1NsToTicks(x)

#define OS_TicksToNs_FTM1_0(x)	OS_BoardFtm1TicksToNs(x)
#define OS_TicksToNs_FTM1_1(x)	OS_BoardFtm1TicksToNs(x)
#define OS_TicksToNs_FTM1_2(x)	OS_BoardFtm1TicksToNs(x)
#define OS_TicksToNs_FTM1_3(x)	OS_BoardFtm1TicksToNs(x)

#define OS_NsToTicks_FTM2_0(x)	OS_BoardFtm2NsToTicks(x)
#define OS_NsToTicks_FTM2_1(x)	OS_BoardFtm2NsToTicks(x)
#define OS_NsToTicks_FTM2_2(x)	OS_BoardFtm2NsToTicks(x)
#define OS_NsToTicks_FTM2_3(x)	OS_BoardFtm2NsToTicks(x)

#define OS_TicksToNs_FTM2_0(x)	OS_BoardFtm2TicksToNs(x)
#define OS_TicksToNs_FTM2_1(x)	OS_BoardFtm2TicksToNs(x)
#define OS_TicksToNs_FTM2_2(x)	OS_BoardFtm2TicksToNs(x)
#define OS_TicksToNs_FTM2_3(x)	OS_BoardFtm2TicksToNs(x)

#define OS_NsToTicks_FTM3_0(x)	OS_BoardFtm3NsToTicks(x)
#define OS_NsToTicks_FTM3_1(x)	OS_BoardFtm3NsToTicks(x)
#define OS_NsToTicks_FTM3_2(x)	OS_BoardFtm3NsToTicks(x)
#define OS_NsToTicks_FTM3_3(x)	OS_BoardFtm3NsToTicks(x)

#define OS_TicksToNs_FTM3_0(x)	OS_BoardFtm3TicksToNs(x)
#define OS_TicksToNs_FTM3_1(x)	OS_BoardFtm3TicksToNs(x)
#define OS_TicksToNs_FTM3_2(x)	OS_BoardFtm3TicksToNs(x)
#define OS_TicksToNs_FTM3_3(x)	OS_BoardFtm3TicksToNs(x)

#define OS_NsToTicks_FTM4_0(x)	OS_BoardFtm4NsToTicks(x)
#define OS_NsToTicks_FTM4_1(x)	OS_BoardFtm4NsToTicks(x)
#define OS_NsToTicks_FTM4_2(x)	OS_BoardFtm4NsToTicks(x)
#define OS_NsToTicks_FTM4_3(x)	OS_BoardFtm4NsToTicks(x)

#define OS_TicksToNs_FTM4_0(x)	OS_BoardFtm4TicksToNs(x)
#define OS_TicksToNs_FTM4_1(x)	OS_BoardFtm4TicksToNs(x)
#define OS_TicksToNs_FTM4_2(x)	OS_BoardFtm4TicksToNs(x)
#define OS_TicksToNs_FTM4_3(x)	OS_BoardFtm4TicksToNs(x)

#define OS_NsToTicks_FTM5_0(x)	OS_BoardFtm5NsToTicks(x)
#define OS_NsToTicks_FTM5_1(x)	OS_BoardFtm5NsToTicks(x)
#define OS_NsToTicks_FTM5_2(x)	OS_BoardFtm5NsToTicks(x)
#define OS_NsToTicks_FTM5_3(x)	OS_BoardFtm5NsToTicks(x)

#define OS_TicksToNs_FTM5_0(x)	OS_BoardFtm5TicksToNs(x)
#define OS_TicksToNs_FTM5_1(x)	OS_BoardFtm5TicksToNs(x)
#define OS_TicksToNs_FTM5_2(x)	OS_BoardFtm5TicksToNs(x)
#define OS_TicksToNs_FTM5_3(x)	OS_BoardFtm5TicksToNs(x)

#define OS_NsToTicks_FTM6_0(x)	OS_BoardFtm6NsToTicks(x)
#define OS_NsToTicks_FTM6_1(x)	OS_BoardFtm6NsToTicks(x)
#define OS_NsToTicks_FTM6_2(x)	OS_BoardFtm6NsToTicks(x)
#define OS_NsToTicks_FTM6_3(x)	OS_BoardFtm6NsToTicks(x)

#define OS_TicksToNs_FTM6_0(x)	OS_BoardFtm6TicksToNs(x)
#define OS_TicksToNs_FTM6_1(x)	OS_BoardFtm6TicksToNs(x)
#define OS_TicksToNs_FTM6_2(x)	OS_BoardFtm6TicksToNs(x)
#define OS_TicksToNs_FTM6_3(x)	OS_BoardFtm6TicksToNs(x)

#define OS_NsToTicks_FTM7_0(x)	OS_BoardFtm7NsToTicks(x)
#define OS_NsToTicks_FTM7_1(x)	OS_BoardFtm7NsToTicks(x)
#define OS_NsToTicks_FTM7_2(x)	OS_BoardFtm7NsToTicks(x)
#define OS_NsToTicks_FTM7_3(x)	OS_BoardFtm7NsToTicks(x)

#define OS_TicksToNs_FTM7_0(x)	OS_BoardFtm7TicksToNs(x)
#define OS_TicksToNs_FTM7_1(x)	OS_BoardFtm7TicksToNs(x)
#define OS_TicksToNs_FTM7_2(x)	OS_BoardFtm7TicksToNs(x)
#define OS_TicksToNs_FTM7_3(x)	OS_BoardFtm7TicksToNs(x)

#endif
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
