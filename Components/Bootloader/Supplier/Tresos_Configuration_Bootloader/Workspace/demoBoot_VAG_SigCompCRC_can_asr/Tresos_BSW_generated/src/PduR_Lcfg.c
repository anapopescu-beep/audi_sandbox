/**
 * \file
 *
 * \brief AUTOSAR PduR
 *
 * This file contains the implementation of the AUTOSAR
 * module PduR.
 *
 * \version 5.3.44
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2020 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


/*==================[includes]==============================================*/

#include <PduR_Cfg.h> /* Pre compile time configuration header */
#include <PduR_Lcfg.h> /* Link time configuration header  */
#include <BlPduR_Prj.h> /* Adjacent layer header */
#include <CanTp.h> /* Adjacent layer header */

#if ((PDUR_TPGATEWAY_SUPPORT == STD_ON) \
    || (PDUR_IFGATEWAY_SUPPORT == STD_ON) \
    || (PDUR_MULTICAST_TOIF_SUPPORT == STD_ON) \
    || (PDUR_MULTICAST_FROMIF_SUPPORT == STD_ON) \
    || (PDUR_MULTICAST_UPTOLOTP_SUPPORT == STD_ON) \
    || (PDUR_MULTICAST_LOTPTOUP_SUPPORT == STD_ON))

#include <PduR_Internal_Static.h>

#endif /* ((PDUR_TPGATEWAY_SUPPORT == STD_ON) \
    || (PDUR_IFGATEWAY_SUPPORT == STD_ON) \
    || (PDUR_MULTICAST_TOIF_SUPPORT == STD_ON) \
    || (PDUR_MULTICAST_FROMIF_SUPPORT == STD_ON) \
    || (PDUR_MULTICAST_UPTOLOTP_SUPPORT == STD_ON) \
    || (PDUR_MULTICAST_LOTPTOUP_SUPPORT == STD_ON)) */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/* start data section declaration */
#define PDUR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <PduR_MemMap.h>

/* Internal memory statically allocated upon link-time. Size depends on
 * post build configuration. Memory requirements of post build configuration
 * must be smaller than PDUR_MEM_SIZE_MAX in order to avoid buffer
 * overflows. Memory is aligned to the most stringent alignment requirement
 * of any simple data type available on the respective platform, e.g. uint32.
 */
#if (PDUR_MEM_SIZE > 0) /* To prevent empty arrays */
static TS_DefMaxAlignedByteArray(PduR_Mem, PDUR, VAR_CLEARED, PDUR_MEM_SIZE);
#endif /* (PDUR_MEM_SIZE > 0) */

/* stop data section declaration */
#define PDUR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <PduR_MemMap.h>


/* start const section declaration */
#define PDUR_START_SEC_CONST_UNSPECIFIED
#include <PduR_MemMap.h>

/**
 * Pointer to internal memory
 */
#if (PDUR_MEM_SIZE > 0) /* To prevent empty arrays */
CONSTP2VAR(uint8, PDUR_CONST, PDUR_VAR_CLEARED) PduR_GMemPtr =
  (P2VAR(uint8, PDUR_CONST, PDUR_VAR_CLEARED))
  ((P2VAR(void, PDUR_CONST, PDUR_VAR_CLEARED)) PduR_Mem);
#else /* (PDUR_MEM_SIZE > 0) */
CONSTP2VAR(uint8, PDUR_CONST, PDUR_VAR_CLEARED) PduR_GMemPtr = NULL_PTR;
#endif /* (PDUR_MEM_SIZE > 0) */

/* stop const section declaration */
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include <PduR_MemMap.h>

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/* start const section declaration */
#define PDUR_START_SEC_CONST_8
#include <PduR_MemMap.h>

/* Index referring to the configuration of a module */
CONST(uint8, PDUR_CONST) PduR_CanTpRTabLoTpConfigIdx = 0U;
CONST(uint8, PDUR_CONST) PduR_BlPduRRTabUpTpConfigIdx = 0U;

/* stop const section declaration */
#define PDUR_STOP_SEC_CONST_8
#include <PduR_MemMap.h>

/* start data section declaration */
#define PDUR_START_SEC_CONST_16
#include <PduR_MemMap.h>

/* Target module API reference */
CONST(PduR_RefToModuleAPI, PDUR_CONST) PduR_BlPduRTargetModuleAPIRef = 1U;

/* stop const section declaration */
#define PDUR_STOP_SEC_CONST_16
#include <PduR_MemMap.h>

/* start data section declaration */
#define PDUR_START_SEC_CONST_32
#include <PduR_MemMap.h>

/* value used to validate post build configuration against link time configuration */
CONST(uint32, PDUR_CONST) PduR_LcfgSignature = 3958107115U;

/* stop data section declaration */
#define PDUR_STOP_SEC_CONST_32
#include <PduR_MemMap.h>

/* start const section declaration */
#define PDUR_START_SEC_CONST_UNSPECIFIED
#include <PduR_MemMap.h>


/**
 * API function pointer table for modules with transport protocol module archetype
 */
CONST(PduR_TpModuleAPIType, PDUR_CONST) PduR_TpModuleAPI[] =
{
    { /* [0] CanTp */
        &CanTp_Transmit /* TpTransmit */
        , NULL_PTR /* TpCopyTxData */
        , NULL_PTR /* TpTxConfirmation */
        , NULL_PTR /* TpCopyRxData */
        , NULL_PTR /* TpStartOfReception */
        , NULL_PTR /* TpRxIndication */
        , &CanTp_ChangeParameter /* TpChangeParameter */
    }
    , { /* [1] BlPduR */
        NULL_PTR /* TpTransmit */
        , &BlPduR_CopyTxData /* TpCopyTxData */
        , &BlPduR_TpTxConfirmation /* TpTxConfirmation */
        , &BlPduR_CopyRxData /* TpCopyRxData */
        , &BlPduR_StartOfReception /* TpStartOfReception */
        , &BlPduR_TpRxIndication /* TpRxIndication */
        , NULL_PTR /* TpChangeParameter */
    }
};

/* stop const section declaration */
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
#include <PduR_MemMap.h>

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/
