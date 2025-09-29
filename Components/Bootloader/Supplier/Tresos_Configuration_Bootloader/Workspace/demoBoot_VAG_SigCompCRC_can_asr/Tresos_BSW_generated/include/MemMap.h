/**
 * \file
 *
 * \brief AUTOSAR MemMap
 *
 * This file contains the implementation of the AUTOSAR
 * module MemMap.
 *
 * \version 1.3.8
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/

/*==================[macros]=================================================*/

/*------------------[Autosar vendor identification]--------------------------*/

#ifndef MEM_VENDOR_ID
/** \brief Autosar module vendor identification
 **
 ** Vendor ID of the dedicated implementation of this module according
 ** to the AUTOSAR vendor list. */
#define MEMMAP_VENDOR_ID 1U /* Elektrobit Automotive GmbH */
#endif

/*------------------[AUTOSAR module identification]-------------------------*/

#if (defined MODULE_MODULE_ID)
#error MEMMAP_MODULE_ID already defined
#endif
/** \brief AUTOSAR module identification */
#define MEMMAP_MODULE_ID 195U

/*------------------[AUTOSAR release version identification]----------------*/

#ifndef MEM_AR_MAJOR_VERSION
/** \brief definition of the major version of the specification */
#define MEMMAP_AR_MAJOR_VERSION 4U
#endif

#ifndef MEM_AR_MINOR_VERSION
/** \brief definition of a minor version of the specification */
#define MEMMAP_AR_MINOR_VERSION 0U
#endif

#ifndef MEM_AR_PATCH_VERSION
/** \brief definition of a patch version of the specification */
#define MEMMAP_AR_PATCH_VERSION 3U
#endif

/*------------------[AUTOSAR module version identification]------------------*/

#ifndef MEM_SW_MAJOR_VERSION
/** \brief definition of the major version of this implementation */
#define MEMMAP_SW_MAJOR_VERSION 1U
#endif

#ifndef MEM_SW_MINOR_VERSION
/** \brief definition of a minor version of this implementation */
#define MEMMAP_SW_MINOR_VERSION 3U
#endif

#ifndef MEM_SW_PATCH_VERSION
/** \brief definition of a patch version of this implementation */
#define MEMMAP_SW_PATCH_VERSION 8U
#endif

/*------------------[MemMap error checking]----------------------------------*/

#if (defined MEMMAP_ERROR) /* to prevent double definition */
#error MEMMAP_ERROR defined, wrong MemMap.h usage
#endif /* ifndef MEMMAP_ERROR */

/** \brief Checks if this file has been correctly used
 **
 ** This definition checks if this file has been correctly included
 ** the last time.
 ** We do it here, before the big if-elif. */
#define MEMMAP_ERROR

/*------------------[MemMap extensions]--------------------------------------*/


#ifdef MEMMAP_ERROR
 #include <Atomics_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <BM_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <Base_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <BlPduR_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <Board_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <Cal_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <CanIf_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <CanSM_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <CanTp_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <Can_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <Cpl_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <Crc_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <Cry_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <Csm_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <Det_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <EBStubs_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <EcuC_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <Fee_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <Fls_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <Mcu_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <MemIf_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <NvM_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <PROG_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <PduR_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <Port_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <SA_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <SchM_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <Spi_MemMap.h>
#endif

#ifdef MEMMAP_ERROR
 #include <UDS_MemMap.h>
#endif

/*==================[inclusions]=============================================*/


#ifdef MEMMAP_ERROR
  #undef MEMMAP_ERROR
  #error MEMMAP_ERROR defined, one or more memory sections or pragmas were not defined for any BSW descriptions.
#endif
