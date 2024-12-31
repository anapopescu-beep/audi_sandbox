/**
 * \file
 *
 * \brief AUTOSAR Csm
 *
 * This file contains the implementation of the AUTOSAR
 * module Csm.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2019 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*================================================================================================*/

/* !LINKSTO CSM0003, 1
 */

#ifndef CSM_CFG_H
#define CSM_CFG_H

/*==================[includes]====================================================================*/

/*==================[macros]======================================================================*/

#if (defined CSM_RTE_ENABLED)
#error CSM_RTE_ENABLED is already defined
#endif
/** \brief  tbd */
#define  CSM_RTE_ENABLED             STD_OFF

#if (defined CSM_GETVERSIONINFO_ENABLED)
#error CSM_GETVERSIONINFO_ENABLED is already defined
#endif
/** \brief  tbd */
#define  CSM_GETVERSIONINFO_ENABLED  STD_OFF

/* !LINKSTO CSM0031, 1
 */
#if (defined CSM_SYNCJOBPROCESSING_ENABLED)
#error CSM_SYNCJOBPROCESSING_ENABLED is already defined
#endif
/** \brief  Pre-processor switch that enables or disables availability of synchronous job processing APIs. */
#define  CSM_SYNCJOBPROCESSING_ENABLED  STD_OFF

#if (defined CSM_USEPRIORITIES_ENABLED)
#error CSM_USEPRIORITIES_ENABLED is already defined
#endif
/** \brief  Pre-processor switch that enables or disables priority handling. */
#define  CSM_USEPRIORITIES_ENABLED  STD_ON
#if (defined CSM_ALIGN_BASE_TYPE)
#error CSM_ALIGN_BASE_TYPE is already defined
#endif
/** \brief  The standard type Csm_AlignType base upon. */
#define  CSM_ALIGN_BASE_TYPE         uint32

#if (defined CSM_LEN_IN_ALIGN_TYPE)
#error CSM_LEN_IN_ALIGN_TYPE is already defined
#endif
/** \brief  The length, in elements of type ::Csm_AlignType, of an array which can hold
 **         as many bytes as given as input.
 **/
#define  CSM_LEN_IN_ALIGN_TYPE(ByteLength)     \
(                                              \
   (uint32)                                    \
   (                                           \
      (uint32)                                 \
      (                                        \
         (uint32)                              \
         (                                     \
            (uint32)(ByteLength) - (uint32)1UL \
         ) /                                   \
         (uint32)sizeof(Csm_AlignType)         \
      ) +                                      \
      (uint32)1UL                              \
   )                                           \
)

  /* !LINKSTO EB_CSM0079_01, 1
 */
#if (defined CSM_ASYM_PUB_KEY_MAX_SIZE)
#error CSM_ASYM_PUB_KEY_MAX_SIZE is already defined
#endif
/** \brief  The maximum length of public asymmetric key key data
 **
 ** This length is used for the public asymmetric key of asymmetric cryptographic schemes like
 ** signature verification or asymmetric encryption.
 **/
#define  CSM_ASYM_PUB_KEY_MAX_SIZE   (CSM_LEN_IN_ALIGN_TYPE(780UL))

/* !LINKSTO EB_CSM0080_01, 1
 */
#if (defined CSM_ASYM_PRIV_KEY_MAX_SIZE)
#error CSM_ASYM_PRIV_KEY_MAX_SIZE is already defined
#endif
/** \brief  The maximum length of private asymmetric key key data
 **
 ** This length is used for the private asymmetric key of asymmetric cryptographic schemes like
 ** signature generation or asymmetric decryption.
 **/
#define  CSM_ASYM_PRIV_KEY_MAX_SIZE  (CSM_LEN_IN_ALIGN_TYPE(1UL))

  /* !LINKSTO EB_CSM0082_01, 1
 */
#if (defined CSM_SYM_KEY_MAX_SIZE)
#error CSM_SYM_KEY_MAX_SIZE is already defined
#endif
/** \brief  The maximum length of symmetric key key data
 **
 ** This length is used for the symmetric key of symmetric cryptographic schemes like HMAC
 ** generation.
 **/
#define  CSM_SYM_KEY_MAX_SIZE        (CSM_LEN_IN_ALIGN_TYPE(16UL))

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/

/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #ifndef CSM_CFG_H */

/*==================[end of file]=================================================================*/

