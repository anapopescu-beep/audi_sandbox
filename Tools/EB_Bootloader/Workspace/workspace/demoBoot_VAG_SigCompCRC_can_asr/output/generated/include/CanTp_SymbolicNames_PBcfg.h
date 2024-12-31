/**
 * \file
 *
 * \brief AUTOSAR CanTp
 *
 * This file contains the implementation of the AUTOSAR
 * module CanTp.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#if (!defined CANTP_SYMBOLICNAMES_PBCFG_H)
#define CANTP_SYMBOLICNAMES_PBCFG_H









    
    
    
         
         
    
    

    
    
    
         
         
    
    




 

 
 
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 





/*==================[includes]==============================================*/

/*==================[macros]================================================*/

/* Generate macros for CanTpRxNSdus */

/*------------------------ CanTp_Rx_Sdu_Phys---------------------------------- */


#if (defined CanTpConf_CanTpRxNSdu_CanTp_Rx_Sdu_Phys) /* to prevent double declaration */
#error CanTpConf_CanTpRxNSdu_CanTp_Rx_Sdu_Phys is already defined
#endif /* if (defined CanTpConf_CanTpRxNSdu_CanTp_Rx_Sdu_Phys) */

/** \brief Export symbolic name value for CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys */
#define CanTpConf_CanTpRxNSdu_CanTp_Rx_Sdu_Phys   0U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys) /* to prevent double declaration */
#error CanTp_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys is already defined
#endif /* if (defined CanTp_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define CanTp_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys       0U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpRxNPdu) /* to prevent double declaration */
#error CanTpConf_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpRxNPdu is already defined
#endif /* if (defined CanTpConf_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpRxNPdu) */

/** \brief Export symbolic name value for CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpRxNPdu */
#define CanTpConf_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpRxNPdu  0U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpRxNPdu) /* to prevent double declaration */
#error CanTp_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpRxNPdu is already defined
#endif /* if (defined CanTp_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpRxNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpRxNPdu       0U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpTxFcNPdu) /* to prevent double declaration */
#error CanTpConf_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpTxFcNPdu is already defined
#endif /* if (defined CanTpConf_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpTxFcNPdu) */

/** \brief Export symbolic name value for CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpTxFcNPdu */
#define CanTpConf_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpTxFcNPdu   0U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */

#if (defined CanTp_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpTxFcNPdu) /* to prevent double declaration */
#error CanTp_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpTxFcNPdu is already defined
#endif /* if (defined CanTp_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpTxFcNPdu) */

#define CanTp_CanTp_Rx_Phys_CanTp_Rx_Sdu_Phys_CanTpTxFcNPdu       0U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/*------------------------ CanTp_Rx_Sdu_Func---------------------------------- */


#if (defined CanTpConf_CanTpRxNSdu_CanTp_Rx_Sdu_Func) /* to prevent double declaration */
#error CanTpConf_CanTpRxNSdu_CanTp_Rx_Sdu_Func is already defined
#endif /* if (defined CanTpConf_CanTpRxNSdu_CanTp_Rx_Sdu_Func) */

/** \brief Export symbolic name value for CanTp_Rx_Func_CanTp_Rx_Sdu_Func */
#define CanTpConf_CanTpRxNSdu_CanTp_Rx_Sdu_Func   1U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_CanTp_Rx_Func_CanTp_Rx_Sdu_Func) /* to prevent double declaration */
#error CanTp_CanTp_Rx_Func_CanTp_Rx_Sdu_Func is already defined
#endif /* if (defined CanTp_CanTp_Rx_Func_CanTp_Rx_Sdu_Func) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define CanTp_CanTp_Rx_Func_CanTp_Rx_Sdu_Func       1U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTp_Rx_Func_CanTp_Rx_Sdu_Func_CanTpRxNPdu) /* to prevent double declaration */
#error CanTpConf_CanTp_Rx_Func_CanTp_Rx_Sdu_Func_CanTpRxNPdu is already defined
#endif /* if (defined CanTpConf_CanTp_Rx_Func_CanTp_Rx_Sdu_Func_CanTpRxNPdu) */

/** \brief Export symbolic name value for CanTp_Rx_Func_CanTp_Rx_Sdu_Func_CanTpRxNPdu */
#define CanTpConf_CanTp_Rx_Func_CanTp_Rx_Sdu_Func_CanTpRxNPdu  1U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_CanTp_Rx_Func_CanTp_Rx_Sdu_Func_CanTpRxNPdu) /* to prevent double declaration */
#error CanTp_CanTp_Rx_Func_CanTp_Rx_Sdu_Func_CanTpRxNPdu is already defined
#endif /* if (defined CanTp_CanTp_Rx_Func_CanTp_Rx_Sdu_Func_CanTpRxNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_CanTp_Rx_Func_CanTp_Rx_Sdu_Func_CanTpRxNPdu       1U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


/* generate macros for CanTpTxNSdus */


/*------------------------ CanTpTxNSdu_0---------------------------------- */


#if (defined CanTpConf_CanTpTxNSdu_CanTpTxNSdu_0) /* to prevent double declaration */
#error CanTpConf_CanTpTxNSdu_CanTpTxNSdu_0 is already defined
#endif /* if (defined CanTpConf_CanTpTxNSdu_CanTpTxNSdu_0) */

/** \brief Export symbolic name value for CanTp_Rx_Phys_CanTpTxNSdu_0 */
#define CanTpConf_CanTpTxNSdu_CanTpTxNSdu_0           0U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_CanTp_Rx_Phys_CanTpTxNSdu_0) /* to prevent double declaration */
#error CanTp_CanTp_Rx_Phys_CanTpTxNSdu_0 is already defined
#endif /* if (defined CanTp_CanTp_Rx_Phys_CanTpTxNSdu_0) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define CanTp_CanTp_Rx_Phys_CanTpTxNSdu_0               0U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpRxFcNPdu) /* to prevent double declaration */
#error CanTpConf_CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpRxFcNPdu is already defined
#endif /* if (defined CanTpConf_CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpRxFcNPdu) */

/** \brief Export symbolic name value for CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpRxFcNPdu */
#define CanTpConf_CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpRxFcNPdu  0U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpRxFcNPdu) /* to prevent double declaration */
#error CanTp_CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpRxFcNPdu is already defined
#endif /* if (defined CanTp_CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpRxFcNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpRxFcNPdu      0U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpTxNPdu) /* to prevent double declaration */
#error CanTpConf_CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpTxNPdu is already defined
#endif /* if (defined CanTpConf_CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpTxNPdu) */

/** \brief Export symbolic name value for CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpTxNPdu */
#define CanTpConf_CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpTxNPdu   1U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpTxNPdu) /* to prevent double declaration */
#error CanTp_CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpTxNPdu is already defined
#endif /* if (defined CanTp_CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpTxNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_CanTp_Rx_Phys_CanTpTxNSdu_0_CanTpTxNPdu       1U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/


#endif /* if !defined( CANTP_SYMBOLICNAMES_PBCFG_H ) */
/*==================[end of file]===========================================*/
