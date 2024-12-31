/* Os_CORTEXM_timer_fs_lpit_config.h - configuration of Freescale's LPIT module
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_CORTEXM_timer_fs_lpit_config.h 1.1 2023/01/26 07:13:41CET Gabriel Brasoveanu (gabriel.brasoveanu) in_work  $
*/
#ifndef OS_CORTEXM_TIMER_FS_LPIT_CONFIG_H
#define OS_CORTEXM_TIMER_FS_LPIT_CONFIG_H

#define OS_NsToTicks_LPIT0_0(x) OS_BoardLPITNsToTicks(x)
#define OS_NsToTicks_LPIT0_1(x) OS_BoardLPITNsToTicks(x)
#define OS_NsToTicks_LPIT0_2(x) OS_BoardLPITNsToTicks(x)
#define OS_NsToTicks_LPIT0_3(x) OS_BoardLPITNsToTicks(x)
#define OS_TicksToNs_LPIT0_0(x) OS_BoardLPITTicksToNs(x)
#define OS_TicksToNs_LPIT0_1(x) OS_BoardLPITTicksToNs(x)
#define OS_TicksToNs_LPIT0_2(x) OS_BoardLPITTicksToNs(x)
#define OS_TicksToNs_LPIT0_3(x) OS_BoardLPITTicksToNs(x)

#endif
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/
