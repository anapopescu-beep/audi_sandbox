/**
 * \file
 *
 * \brief AUTOSAR Dem
 *
 * This file contains the implementation of the AUTOSAR
 * module Dem.
 *
 * \version 6.4.7
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* This file contains all definitions of the configuration of the AUTOSAR
 * module Dem that are target independent. */

/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 11.1 (required)
 *     Conversions shall not be performed between a pointer to a function and
 *     any other type.
 *
 *     Reason:
 *     In order to save memory, the function pointers necessary for Read Callbacks are generated
 *     as an array of unions (union type which contains all such possible function pointers),
 *     instead of an array of structures containing all possible pointer types.
 *     The array containing the function pointers is initialized using brace-enclosed initializer
 *     list and C90 standard allow only the initialization of the first union member.
 *     The solution is to use a "generic function pointer" and use that type to define the array,
 *     and use explicit casts for each initialized member.
 *     Casting one function pointer type to the general type at initialization and then back again
 *     to the original type is guaranteed to preserve the correct data.
 */



/*==================[inclusions]============================================*/
/* !LINKSTO dsn.Dem.IncludeStr,1 */

#include <TSAutosar.h>                    /* EB specific standard types */
#include <Std_Types.h>                    /* AUTOSAR standard types */
#include <Dem_Int.h>                      /* API and internal declarations,
                                           * dependent and static part */
/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

#define DEM_START_SEC_CONST_8
#include <Dem_MemMap.h>

CONST(Dem_ConfigType, DEM_CONST) Dem_Config_0 = {0U};

#define DEM_STOP_SEC_CONST_8
#include <Dem_MemMap.h>



/*------------------[Freeze frame classes configuration]--------------------*/

/*------------------[Freeze frame record number classes configuration]------*/

/*------------------[Extended data classes configuration]-------------------*/

/*------------------[Data element classes configuration]--------------------*/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

/*------------------[DTC groups configuration]------------------------------*/


/*------------------[Events Class configuration]----------------------------*/

#define DEM_START_SEC_CALIB_UNSPECIFIED
#include <Dem_MemMap.h>


#define DEM_STOP_SEC_CALIB_UNSPECIFIED
#include <Dem_MemMap.h>

/*------------------[Events configuration]----------------------------------*/

#define DEM_START_SEC_CALIB_32
#include <Dem_MemMap.h>

/** \brief Event configuration description table (uses 'bit packing scheme) */
CONST(Dem_EventDescType, DEM_CONST) Dem_EventDesc[DEM_NUMBER_OF_EVENTS] =
{
  { 0U, 0U, 0U },                                 /* invalid event id entry */
  { /* event: EVENT_CANSM_E_BUS_OFF */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is BSW */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 0U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_ADC_OUT_OF_ORDER */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 1U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_WARM_RESET */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 2U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_PFLASH_MEM_CORRUPT */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 3U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_EXT_WDG_OUT_OF_ORDER */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 4U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_NVM_NOT_PRG */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 5U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_RAM_MEM_CORRUPT */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 6U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_ADC_CALIB */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 7U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_ECU_OVER_TEMPERATURE */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 8U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_DFLASH_MEM_CORRUPT */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 9U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_SBC_STATUS_FAILURE */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 10U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_POWER_SUPPLY_OV */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 11U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_POWER_SUPPLY_UV */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 12U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_ACTUATOR_STATUS */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 13U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_MCU_SELFTEST */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 14U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_ACTUATOR_OPEN_CIRCUIT */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 15U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_ACTUATOR_SHORT_TO_GND */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 16U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_ACTUATOR_SHORT_TO_VBAT */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 17U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_ACC_STATUS_FAILURE */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 18U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_SPI_E_HW_ERROR */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is BSW */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_BSW) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 19U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_SOLENOID_OVERVOLTAGE */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 20U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_POWER_STAGE_FAILIURE */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 21U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
  { /* event: EVENT_MCU_CRC_REGISTERS */
    /* No UDS-DTC value */
    ( (uint32)(DEM_NO_DTC) )
    /* Origin of DTC */
    | ( (uint32) (DEM_DTCORIGIN_MASK & (DEM_DTC_ORIGIN_PRIMARY_MEMORY - 1U)) << DEM_DTCORIGIN_OFFSET )
    /* No severity specified for DTC */
    | ( (uint32)(DEM_DTCSEVERITY_MASK & 0U) << DEM_DTCSEVERITY_OFFSET )
    /* Prestorage disabled */
    /* Event kind is SWC */
    | ( (uint32)(DEM_EVENTKIND_MASK & DEM_EVENT_KIND_SWC) << DEM_EVENTKIND_OFFSET )
    /* No warning indicator used */
    /* Immediate storage disabled */
    ,
    /* DTC Significance */
    ( (uint32)(DEM_EVENTSIGNIFICANCE_MASK & DEM_EVENT_SIGNIFICANCE_FAULT) << DEM_EVENTSIGNIFICANCE_OFFSET )
    /* No freeze frame class */
    | ( (uint32)(DEM_FFCLASSIDX_MASK & DEM_FFCLS_NULL_IDX) << DEM_FFCLASSIDX_OFFSET )
    /* No freeze frame records */
    | ( (uint32)(DEM_FFRECINFO_MASK & 0U) << DEM_FFRECINFO_OFFSET )
    /* No extended data class */
    | ( (uint32)(DEM_EDCLASSIDX_MASK & DEM_EDCLS_NULL_IDX) << DEM_EDCLASSIDX_OFFSET )
    /* Operation cycle Id */
    | ( (uint32)(DEM_OPCYCLEIDX_MASK & DEM_OPCYC_POWER) << DEM_OPCYCLEIDX_OFFSET )
    /* Aging disabled (AgingCycles = 0) */
    | ( (uint32)0U << DEM_AGINGCTRTHRESHOLD_OFFSET )
    /* No group of DTC */
    | ( (uint32)(DEM_DTCGROUP_MASK & DEM_DTCGRP_IDX_NO_DTC) << DEM_DTCGROUP_OFFSET )
    ,
    /* No enable condition group referenced */
    ( (uint32)(DEM_ENCONDGRPIDX_MASK & DEM_ENCONDITIONGROUP_UNUSED) << DEM_ENCONDGRPIDX_OFFSET )
    /* Fault confirmation not configured */
    | ( (uint32)(DEM_EVENTFAILURECLASSIDX_MASK & DEM_NO_FAULT_CONFIRMATION) << DEM_EVENTFAILURECLASSIDX_OFFSET )
    /* No event priority used as event displacement is disabled */
    | ( (uint32)0U << DEM_PRIORITY_OFFSET )
    /* Counter based event debouncing */
    | ( (uint32)(DEM_DEBOUNCEALGO_MASK & ((uint32)DEM_DEBOUNCE_COUNTERBASED)) << DEM_DEBOUNCEALGO_OFFSET )
    /* Index of debouncing configuration/status */
    | ( (uint32)(DEM_DEBOUNCEIDX_MASK & 22U) << DEM_DEBOUNCEIDX_OFFSET )
    /* No DTC Functional Unit */
    | ( (uint32)(DEM_DTCFUNCTIONALUNIT_MASK & DEM_NO_DTC_FUNCTIONAL_UNIT) << DEM_DTCFUNCTIONALUNIT_OFFSET )
    /* No aging cycle Id */
    | ( (uint32)(DEM_AGINGCYCLEIDX_MASK & DEM_NUM_AGINGCYCLES) << DEM_AGINGCYCLEIDX_OFFSET )
  },
};

#define DEM_STOP_SEC_CALIB_32
#include <Dem_MemMap.h>



#define DEM_START_SEC_CONST_8
#include <Dem_MemMap.h>
#if (DEM_STATUS_BIT_STORAGE_TF_PER_EVENT_SUPPORT == STD_ON)
/** \brief Generate the const array Dem_StatusBitStorageTF[],
 ** only if not all configured events do have the same
 ** DemStatusBitStorageTestFailedPerEvent value. */
CONST(uint8, DEM_CONST) Dem_StatusBitStorageTF[DEM_STATUS_BIT_STORAGE_TF_ARRAY_SIZE] =
{
  0x00U,
  0x00U,
  0x00U,
};
#endif

#define DEM_STOP_SEC_CONST_8
#include <Dem_MemMap.h>






/*------------------[Enable conditions configuration]-----------------------*/

#define DEM_START_SEC_VAR_INIT_8
#include <Dem_MemMap.h>


#define DEM_STOP_SEC_VAR_INIT_8
#include <Dem_MemMap.h>


/*------------------[Multi event triggering configuration]------------------*/


/*------------------[Warning indicators configuration]----------------------*/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>




#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

#define DEM_START_SEC_CONST_8
#include <Dem_MemMap.h>



#define DEM_STOP_SEC_CONST_8
#include <Dem_MemMap.h>


/*------------------[Debouncing configuration]------------------------------*/

/** \brief Counter based debouncing configuration description table */
#define DEM_START_SEC_CALIB_16
#include <Dem_MemMap.h>

CONST(Dem_DebounceCounterClassType, DEM_CONST)
  Dem_DebounceCounterClass[DEM_NUM_DEBOUNCE_COUNTER_CLASSES] =
{
  { /* 0 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -11, /* DemDebounceCounterPassedThreshold */
    5, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    FALSE, /* DemDebounceCounterJumpDown */
    FALSE, /* DemDebounceCounterJumpUp */
  },
  { /* 1 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -200, /* DemDebounceCounterPassedThreshold */
    5, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
  { /* 2 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -1, /* DemDebounceCounterPassedThreshold */
    10, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
  { /* 3 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -1, /* DemDebounceCounterPassedThreshold */
    1, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
  { /* 4 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -20, /* DemDebounceCounterPassedThreshold */
    10, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
  { /* 5 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -90, /* DemDebounceCounterPassedThreshold */
    40, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
  { /* 6 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -40, /* DemDebounceCounterPassedThreshold */
    30, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
  { /* 7 */
    1U, /* DemDebounceCounterDecrementStepSize */
    1U, /* DemDebounceCounterIncrementStepSize */
    -1, /* DemDebounceCounterPassedThreshold */
    1, /* DemDebounceCounterFailedThreshold */
    0, /* DemDebounceCounterJumpDownValue */
    0, /* DemDebounceCounterJumpUpValue */
    DEM_DEBOUNCE_FREEZE, /* DemDebounceBehavior */
    TRUE, /* DemDebounceCounterJumpDown */
    TRUE, /* DemDebounceCounterJumpUp */
  },
};

/** \brief Counter based debouncing class index table */
CONST(Dem_DebounceCounterClassIdxType, DEM_CONST)
  Dem_DebounceCounterClassIdx[DEM_NUM_DEBOUNCE_COUNTER] =
{
  DEM_DEBOUNCE_COUNTER_NVSTORAGE_MASK, /* 1 */
  1U, /* 2 */
  2U, /* 3 */
  3U, /* 4 */
  3U, /* 5 */
  3U, /* 6 */
  3U, /* 7 */
  3U, /* 8 */
  4U, /* 9 */
  3U, /* 10 */
  4U, /* 11 */
  5U, /* 12 */
  5U, /* 13 */
  3U, /* 14 */
  3U, /* 15 */
  6U, /* 16 */
  6U, /* 17 */
  1U, /* 18 */
  1U, /* 19 */
  7U | DEM_DEBOUNCE_COUNTER_NVSTORAGE_MASK, /* 20 */
  4U, /* 21 */
  4U, /* 22 */
  3U, /* 23 */
};

#define DEM_STOP_SEC_CALIB_16
#include <Dem_MemMap.h>

/** \brief Time based debouncing configuration description table */
/* !LINKSTO Dem.Calibration.DemTimeBasedDebounceClassConcept,1 */
/* none */

#define DEM_START_SEC_CONST_16
#include <Dem_MemMap.h>

/** \brief Time based debouncing configuration description table */
/* none */

/** \brief Frequency based debouncing configuration description table */
/* none */

#define DEM_STOP_SEC_CONST_16
#include <Dem_MemMap.h>

/*------------------[Fault confirmation configuration]----------------------*/

/* none */


/*------------------[ Event Availability ]------------------------*/

#define DEM_START_SEC_CALIB_8
#include <Dem_MemMap.h>


#define DEM_STOP_SEC_CALIB_8
#include <Dem_MemMap.h>

/*------------------[RTE / C-callback notifications]------------------------*/

#define DEM_START_SEC_CONST_8
#include <Dem_MemMap.h>

/** \brief Event callback property table */
CONST(Dem_CbPropertyType, DEM_CONST) Dem_CbProperty[DEM_NUMBER_OF_EVENTS] =
{
  0U,
  /* invalid event id entry */
  /* event: EVENT_CANSM_E_BUS_OFF */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_ADC_OUT_OF_ORDER */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_WARM_RESET */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_PFLASH_MEM_CORRUPT */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_EXT_WDG_OUT_OF_ORDER */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_NVM_NOT_PRG */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_RAM_MEM_CORRUPT */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_ADC_CALIB */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_ECU_OVER_TEMPERATURE */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_DFLASH_MEM_CORRUPT */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_SBC_STATUS_FAILURE */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_POWER_SUPPLY_OV */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_POWER_SUPPLY_UV */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_ACTUATOR_STATUS */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_MCU_SELFTEST */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_ACTUATOR_OPEN_CIRCUIT */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_ACTUATOR_SHORT_TO_GND */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_ACTUATOR_SHORT_TO_VBAT */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_ACC_STATUS_FAILURE */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_SPI_E_HW_ERROR */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_SOLENOID_OVERVOLTAGE */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_POWER_STAGE_FAILIURE */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
  /* event: EVENT_MCU_CRC_REGISTERS */
  /* no init monitor callback */
DEM_C_CB_TRIG_ON_EVST |   /* no trigger on event data changed callback */
  /* no clearEventAllowed callback */
  /* DEM-internal fault detection counter */
  DEM_ZERO_END,
};
/*---------------[Operation cycle automatic end enabled masks]-------------*/

/* Array contains masks for automatic ending of operation cycles. */
/* One mask groups 8 operation cycles to keep the numerical value of */
/* the masks small. Every mask is a bitfield, containing the auto end */
/* enabled information of 8 consecutive operation cycles. */
CONST(uint8, DEM_CONST)
  Dem_OpCycAutoEndEnabledMasks[DEM_OPCYC_NUM_OF_AUTO_END_ENABLED_MASKS] =
{
  /* Automatic end enabled mask for operation cycles 0 .. 0 */
  0x1U,
};
#define DEM_STOP_SEC_CONST_8
#include <Dem_MemMap.h>

/*---[INIT_MONITOR]---*/



/*---[TRIGGER_ON_EVENT_STATUS]---*/

#if (DEM_C_CALLBACK_TABLE_TRIG_ON_EVST_SIZE != 0U)
#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

/** \brief C-Callback function pointer table for TriggerOnEventStatus */
CONST(Dem_CbFuncPtrTrigOnEvStType, DEM_CONST)
  Dem_CbFuncPtrTrigOnEvSt[DEM_C_CALLBACK_TABLE_TRIG_ON_EVST_SIZE] =
{
  &Dem_Callback_EventStatusChanged,
};

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>
#endif

#if (DEM_C_LOOKUP_TABLE_TRIG_ON_EVST_SIZE != 0U)
#define DEM_START_SEC_CONST_16
#include <Dem_MemMap.h>

/** \brief C-Lookup table for TriggerOnEventStatus */
CONST(Dem_CbLookupTableType, DEM_CONST)
  Dem_CbLookupTableTrigOnEvSt[DEM_C_LOOKUP_TABLE_TRIG_ON_EVST_SIZE] =
{
  { DemConf_DemEventParameter_EVENT_CANSM_E_BUS_OFF, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_ADC_OUT_OF_ORDER, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_WARM_RESET, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_PFLASH_MEM_CORRUPT, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_EXT_WDG_OUT_OF_ORDER, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_NVM_NOT_PRG, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_RAM_MEM_CORRUPT, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_ADC_CALIB, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_ECU_OVER_TEMPERATURE, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_DFLASH_MEM_CORRUPT, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_SBC_STATUS_FAILURE, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_POWER_SUPPLY_OV, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_POWER_SUPPLY_UV, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_ACTUATOR_STATUS, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_MCU_SELFTEST, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_ACTUATOR_OPEN_CIRCUIT, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_ACTUATOR_SHORT_TO_GND, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_ACTUATOR_SHORT_TO_VBAT, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_ACC_STATUS_FAILURE, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_SPI_E_HW_ERROR, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_SOLENOID_OVERVOLTAGE, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_POWER_STAGE_FAILIURE, 0U }, /* -> Dem_Callback_EventStatusChanged() */
  { DemConf_DemEventParameter_EVENT_MCU_CRC_REGISTERS, 0U }, /* -> Dem_Callback_EventStatusChanged() */
};

#define DEM_STOP_SEC_CONST_16
#include <Dem_MemMap.h>
#endif

#if (DEM_RTE_CALLBACK_TABLE_TRIG_ON_EVST_SIZE != 0U)
#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

/** \brief RTE-Callback function pointer table
** for TriggerOnEventStatus
**/
CONST(Dem_RteFuncPtrTrigOnEvStType, DEM_CONST)
  Dem_RteFuncPtrTrigOnEvSt[DEM_RTE_CALLBACK_TABLE_TRIG_ON_EVST_SIZE] =
{
};

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>
#endif

#if (DEM_RTE_LOOKUP_TABLE_TRIG_ON_EVST_SIZE != 0U)
#define DEM_START_SEC_CONST_16
#include <Dem_MemMap.h>

/** \brief RTE-Lookup table for TriggerOnEventStatus */
CONST(Dem_EventIdType, DEM_CONST)
  Dem_RteLookupTableTrigOnEvSt[DEM_RTE_LOOKUP_TABLE_TRIG_ON_EVST_SIZE] =
{
};

#define DEM_STOP_SEC_CONST_16
#include <Dem_MemMap.h>
#endif

/*---[TRIGGER_ON_DTC_STATUS]---*/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>


/*---[TRIGGER_ON_EVENT_DATA_CHANGED]---*/

#if (DEM_C_CB_TABLE_TRIG_ON_EVDAT_SIZE != 0U)
/** \brief C-Callback function pointer table for TriggerOnEventDataChanged */
CONST(Dem_CbFuncPtrTrigOnEvDatType, DEM_CONST)
  Dem_CbFuncPtrTrigOnEvDat[DEM_C_CB_TABLE_TRIG_ON_EVDAT_SIZE] =
{
};
#endif

#if (DEM_RTE_CB_TABLE_TRIG_ON_EVDAT_SIZE != 0U)
/** \brief RTE-Callback function pointer table for TriggerOnEventDataChanged */
CONST(Dem_RteFuncPtrTrigOnEvDatType, DEM_CONST)
  Dem_RteFuncPtrTrigOnEvDat[DEM_RTE_CB_TABLE_TRIG_ON_EVDAT_SIZE] =
{
};
#endif

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

#define DEM_START_SEC_CONST_16
#include <Dem_MemMap.h>

#if (DEM_C_LOOKUP_TABLE_TRIG_ON_EVDAT_SIZE != 0U)
/** \brief C-Lookup table for TriggerOnEventDataChanged */
CONST(Dem_CbLookupTableType, DEM_CONST)
  Dem_CbLookupTableTrigOnEvDat[DEM_C_LOOKUP_TABLE_TRIG_ON_EVDAT_SIZE] =
{
};
#endif

#if (DEM_RTE_LOOKUP_TABLE_TRIG_ON_EVDAT_SIZE != 0U)
/** \brief RTE-Lookup table for TriggerOnEventDataChanged */
CONST(Dem_EventIdType, DEM_CONST)
  Dem_RteLookupTableTrigOnEvDat[DEM_RTE_LOOKUP_TABLE_TRIG_ON_EVDAT_SIZE] =
{
};
#endif

#define DEM_STOP_SEC_CONST_16
#include <Dem_MemMap.h>






/*---[CLEAR_EVENT_ALLOWED]---*/

#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

#if (DEM_C_CB_TABLE_CLEAR_EVENT_ALLOWED_SIZE != 0U)
/** \brief C-Callback function pointer table for ClearEventAllowed */
CONST(Dem_CbFuncPtrClearEventAllowedType, DEM_CONST)
  Dem_CbFuncPtrClearEventAllowed[DEM_C_CB_TABLE_CLEAR_EVENT_ALLOWED_SIZE] =
{
};
#endif

#if (DEM_C_LOOKUP_TABLE_CLEAR_EVENT_ALLOWED_SIZE != 0U)
/** \brief C-Lookup table for ClearEventAllowed
 ** also Clear Event Behavior info is packed in EventId */
CONST(Dem_CbLookupTableType, DEM_CONST)
  Dem_CbLookupTableClearEventAllowed
    [DEM_C_LOOKUP_TABLE_CLEAR_EVENT_ALLOWED_SIZE] =
{
};
#endif

#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

#if (DEM_RTE_LOOKUP_TABLE_CLEAR_EVENT_ALLOWED_SIZE != 0U)
#define DEM_START_SEC_CONST_16
#include <Dem_MemMap.h>

/** \brief RTE-Lookup table for ClearEventAllowed
 ** also Clear Event Behavior info is packed in EventId */
CONST(Dem_EventIdType, DEM_CONST)
  Dem_RteLookupTableClearEventAllowed
    [DEM_RTE_LOOKUP_TABLE_CLEAR_EVENT_ALLOWED_SIZE] =
{
};

#define DEM_STOP_SEC_CONST_16
#include <Dem_MemMap.h>
#endif

#define DEM_START_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

#if (DEM_RTE_CB_TABLE_CLEAR_EVENT_ALLOWED_SIZE != 0U)
/** \brief RTE-Callback function pointer table for ClearEventAllowed */
CONST(Dem_CbFuncPtrClearEventAllowedType, DEM_CONST)
  Dem_RteFuncPtrClearEventAllowed[DEM_RTE_CB_TABLE_CLEAR_EVENT_ALLOWED_SIZE] =
{
};
#endif

/*---[GET_FDC]---*/


#define DEM_STOP_SEC_CONST_UNSPECIFIED
#include <Dem_MemMap.h>

/*------------------[OBD Readiness Groups force complete]-------------------*/

/* !LINKSTO dsn.Dem.OBDPidSupport.Dem_ReadinessForceStatus_01,1 */
#define DEM_START_SEC_CALIB_8
#include <Dem_MemMap.h>


/*------------------[OBD Readiness Groups PID41 ByteB Pre-set value]---------*/

#define DEM_STOP_SEC_CALIB_8
#include <Dem_MemMap.h>

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
