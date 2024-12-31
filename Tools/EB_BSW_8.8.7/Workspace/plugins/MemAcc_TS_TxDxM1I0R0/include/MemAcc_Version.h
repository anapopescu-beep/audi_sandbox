#ifndef MEMACC_VERSION_H
#define MEMACC_VERSION_H
/**
 * \file
 *
 * \brief AUTOSAR MemAcc
 *
 * This file contains the implementation of the AUTOSAR
 * module MemAcc.
 *
 * \version 1.0.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/

/*==================[macros]=================================================*/

/*------------------[AUTOSAR vendor identification]-------------------------*/

#if (defined MEMACC_VENDOR_ID)
#error MEMACC_VENDOR_ID is already defined
#endif
/** \brief AUTOSAR vendor identification: Elektrobit Automotive GmbH */
#define MEMACC_VENDOR_ID         1U

/*------------------[AUTOSAR module identification]-------------------------*/

#if (defined MEMACC_MODULE_ID)
#error MEMACC_MODULE_ID already defined
#endif
/** \brief AUTOSAR module identification */
#define MEMACC_MODULE_ID         41U

/*------------------[AUTOSAR release version identification]----------------*/

#if (defined MEMACC_AR_RELEASE_MAJOR_VERSION)
#error MEMACC_AR_RELEASE_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR release major version */
#define MEMACC_AR_RELEASE_MAJOR_VERSION     4U

#if (defined MEMACC_AR_RELEASE_MINOR_VERSION)
#error MEMACC_AR_RELEASE_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR release minor version */
#define MEMACC_AR_RELEASE_MINOR_VERSION     0U

#if (defined MEMACC_AR_RELEASE_REVISION_VERSION)
#error MEMACC_AR_RELEASE_REVISION_VERSION already defined
#endif
/** \brief AUTOSAR release revision version */
#define MEMACC_AR_RELEASE_REVISION_VERSION  3U

/*------------------[AUTOSAR module version identification]------------------*/

#if (defined MEMACC_SW_MAJOR_VERSION)
#error MEMACC_SW_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR module major version */
#define MEMACC_SW_MAJOR_VERSION             1U

#if (defined MEMACC_SW_MINOR_VERSION)
#error MEMACC_SW_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR module minor version */
#define MEMACC_SW_MINOR_VERSION             0U

#if (defined MEMACC_SW_PATCH_VERSION)
#error MEMACC_SW_PATCH_VERSION already defined
#endif
/** \brief AUTOSAR module patch version */
#define MEMACC_SW_PATCH_VERSION             3U

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* ifndef MEMACC_VERSION_H */
/*==================[end of file]============================================*/
