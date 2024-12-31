/**
 * \file
 *
 * \brief AUTOSAR Dem
 *
 * This file contains the implementation of the AUTOSAR
 * module Dem.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined DEM_INT_EVT_ID_H)
#define DEM_INT_EVT_ID_H

/* This file contains the configuration declarations of the
 * SW-C Event ID symbols for AUTOSAR module Dem. */






/*==================[inclusions]============================================*/

/*==================[macros]================================================*/

/*------------------[Events configuration]----------------------------------*/

/* !LINKSTO Dem115,2 */
/* Symbolic names of configured SW-C event IDs */

#if (defined DemConf_DemEventParameter_EVENT_ADC_OUT_OF_ORDER)
#error DemConf_DemEventParameter_EVENT_ADC_OUT_OF_ORDER already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_ADC_OUT_OF_ORDER          2U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_ADC_OUT_OF_ORDER)
#error Dem_EVENT_ADC_OUT_OF_ORDER already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_ADC_OUT_OF_ORDER          2U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_WARM_RESET)
#error DemConf_DemEventParameter_EVENT_WARM_RESET already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_WARM_RESET                3U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_WARM_RESET)
#error Dem_EVENT_WARM_RESET already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_WARM_RESET                3U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_PFLASH_MEM_CORRUPT)
#error DemConf_DemEventParameter_EVENT_PFLASH_MEM_CORRUPT already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_PFLASH_MEM_CORRUPT        4U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_PFLASH_MEM_CORRUPT)
#error Dem_EVENT_PFLASH_MEM_CORRUPT already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_PFLASH_MEM_CORRUPT        4U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_EXT_WDG_OUT_OF_ORDER)
#error DemConf_DemEventParameter_EVENT_EXT_WDG_OUT_OF_ORDER already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_EXT_WDG_OUT_OF_ORDER      5U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_EXT_WDG_OUT_OF_ORDER)
#error Dem_EVENT_EXT_WDG_OUT_OF_ORDER already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_EXT_WDG_OUT_OF_ORDER      5U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_NVM_NOT_PRG)
#error DemConf_DemEventParameter_EVENT_NVM_NOT_PRG already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_NVM_NOT_PRG               6U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_NVM_NOT_PRG)
#error Dem_EVENT_NVM_NOT_PRG already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_NVM_NOT_PRG               6U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_RAM_MEM_CORRUPT)
#error DemConf_DemEventParameter_EVENT_RAM_MEM_CORRUPT already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_RAM_MEM_CORRUPT           7U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_RAM_MEM_CORRUPT)
#error Dem_EVENT_RAM_MEM_CORRUPT already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_RAM_MEM_CORRUPT           7U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_ADC_CALIB)
#error DemConf_DemEventParameter_EVENT_ADC_CALIB already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_ADC_CALIB                 8U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_ADC_CALIB)
#error Dem_EVENT_ADC_CALIB already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_ADC_CALIB                 8U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_ECU_OVER_TEMPERATURE)
#error DemConf_DemEventParameter_EVENT_ECU_OVER_TEMPERATURE already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_ECU_OVER_TEMPERATURE      9U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_ECU_OVER_TEMPERATURE)
#error Dem_EVENT_ECU_OVER_TEMPERATURE already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_ECU_OVER_TEMPERATURE      9U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_DFLASH_MEM_CORRUPT)
#error DemConf_DemEventParameter_EVENT_DFLASH_MEM_CORRUPT already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_DFLASH_MEM_CORRUPT        10U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_DFLASH_MEM_CORRUPT)
#error Dem_EVENT_DFLASH_MEM_CORRUPT already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_DFLASH_MEM_CORRUPT        10U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_SBC_STATUS_FAILURE)
#error DemConf_DemEventParameter_EVENT_SBC_STATUS_FAILURE already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_SBC_STATUS_FAILURE        11U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_SBC_STATUS_FAILURE)
#error Dem_EVENT_SBC_STATUS_FAILURE already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_SBC_STATUS_FAILURE        11U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_POWER_SUPPLY_OV)
#error DemConf_DemEventParameter_EVENT_POWER_SUPPLY_OV already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_POWER_SUPPLY_OV           12U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_POWER_SUPPLY_OV)
#error Dem_EVENT_POWER_SUPPLY_OV already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_POWER_SUPPLY_OV           12U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_POWER_SUPPLY_UV)
#error DemConf_DemEventParameter_EVENT_POWER_SUPPLY_UV already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_POWER_SUPPLY_UV           13U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_POWER_SUPPLY_UV)
#error Dem_EVENT_POWER_SUPPLY_UV already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_POWER_SUPPLY_UV           13U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_ACTUATOR_STATUS)
#error DemConf_DemEventParameter_EVENT_ACTUATOR_STATUS already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_ACTUATOR_STATUS           14U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_ACTUATOR_STATUS)
#error Dem_EVENT_ACTUATOR_STATUS already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_ACTUATOR_STATUS           14U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_MCU_SELFTEST)
#error DemConf_DemEventParameter_EVENT_MCU_SELFTEST already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_MCU_SELFTEST              15U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_MCU_SELFTEST)
#error Dem_EVENT_MCU_SELFTEST already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_MCU_SELFTEST              15U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_ACTUATOR_OPEN_CIRCUIT)
#error DemConf_DemEventParameter_EVENT_ACTUATOR_OPEN_CIRCUIT already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_ACTUATOR_OPEN_CIRCUIT     16U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_ACTUATOR_OPEN_CIRCUIT)
#error Dem_EVENT_ACTUATOR_OPEN_CIRCUIT already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_ACTUATOR_OPEN_CIRCUIT     16U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_ACTUATOR_SHORT_TO_GND)
#error DemConf_DemEventParameter_EVENT_ACTUATOR_SHORT_TO_GND already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_ACTUATOR_SHORT_TO_GND     17U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_ACTUATOR_SHORT_TO_GND)
#error Dem_EVENT_ACTUATOR_SHORT_TO_GND already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_ACTUATOR_SHORT_TO_GND     17U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_ACTUATOR_SHORT_TO_VBAT)
#error DemConf_DemEventParameter_EVENT_ACTUATOR_SHORT_TO_VBAT already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_ACTUATOR_SHORT_TO_VBAT    18U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_ACTUATOR_SHORT_TO_VBAT)
#error Dem_EVENT_ACTUATOR_SHORT_TO_VBAT already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_ACTUATOR_SHORT_TO_VBAT    18U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_ACC_STATUS_FAILURE)
#error DemConf_DemEventParameter_EVENT_ACC_STATUS_FAILURE already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_ACC_STATUS_FAILURE        19U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_ACC_STATUS_FAILURE)
#error Dem_EVENT_ACC_STATUS_FAILURE already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_ACC_STATUS_FAILURE        19U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_SOLENOID_OVERVOLTAGE)
#error DemConf_DemEventParameter_EVENT_SOLENOID_OVERVOLTAGE already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_SOLENOID_OVERVOLTAGE      21U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_SOLENOID_OVERVOLTAGE)
#error Dem_EVENT_SOLENOID_OVERVOLTAGE already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_SOLENOID_OVERVOLTAGE      21U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_POWER_STAGE_FAILIURE)
#error DemConf_DemEventParameter_EVENT_POWER_STAGE_FAILIURE already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_POWER_STAGE_FAILIURE      22U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_POWER_STAGE_FAILIURE)
#error Dem_EVENT_POWER_STAGE_FAILIURE already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_POWER_STAGE_FAILIURE      22U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_EVENT_MCU_CRC_REGISTERS)
#error DemConf_DemEventParameter_EVENT_MCU_CRC_REGISTERS already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_EVENT_MCU_CRC_REGISTERS         23U

#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_EVENT_MCU_CRC_REGISTERS)
#error Dem_EVENT_MCU_CRC_REGISTERS already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_EVENT_MCU_CRC_REGISTERS         23U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* if !defined( DEM_INT_EVT_ID_H ) */
/*==================[end of file]===========================================*/
