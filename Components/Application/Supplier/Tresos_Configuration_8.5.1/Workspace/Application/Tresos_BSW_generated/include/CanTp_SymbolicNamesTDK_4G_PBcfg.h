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
#if (!defined CANTP_SYMBOLICNAMESTDK_4G_PBCFG_H)
#define CANTP_SYMBOLICNAMESTDK_4G_PBCFG_H









    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    

    
    
    
         
         
    
    




 

 
 
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 
     
     
     
          
          
     
     
 





/*==================[includes]==============================================*/

/*==================[macros]================================================*/

/* Generate macros for CanTpRxNSdus */

/*------------------------ DIA_Request---------------------------------- */


#if (defined CanTpConf_CanTpRxNSdu_DIA_Request_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpRxNSdu_DIA_Request_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpRxNSdu_DIA_Request_TDK_4G) */

/** \brief Export symbolic name value for TPC_DIA_DIA_Request */
#define CanTpConf_CanTpRxNSdu_DIA_Request_TDK_4G   0U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_DIA_DIA_Request) /* to prevent double declaration */
#error CanTp_TPC_DIA_DIA_Request is already defined
#endif /* if (defined CanTp_TPC_DIA_DIA_Request) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define CanTp_TPC_DIA_DIA_Request       0U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTpRxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANHS_Flash_DIA_XIX_0x17FC4206_XIX_0x17FE4206_XIX_Physical_DIA_eCS_Req_XIX_Airbag_SUBCANFD_402407942R_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpRxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANHS_Flash_DIA_XIX_0x17FC4206_XIX_0x17FE4206_XIX_Physical_DIA_eCS_Req_XIX_Airbag_SUBCANFD_402407942R_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpRxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANHS_Flash_DIA_XIX_0x17FC4206_XIX_0x17FE4206_XIX_Physical_DIA_eCS_Req_XIX_Airbag_SUBCANFD_402407942R_TDK_4G) */

/** \brief Export symbolic name value for TPC_DIA_DIA_Request_CanTpRxNPdu_TDK_4G */
#define CanTpConf_CanTpRxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANHS_Flash_DIA_XIX_0x17FC4206_XIX_0x17FE4206_XIX_Physical_DIA_eCS_Req_XIX_Airbag_SUBCANFD_402407942R_TDK_4G  0U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_DIA_DIA_Request_CanTpRxNPdu) /* to prevent double declaration */
#error CanTp_TPC_DIA_DIA_Request_CanTpRxNPdu is already defined
#endif /* if (defined CanTp_TPC_DIA_DIA_Request_CanTpRxNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_TPC_DIA_DIA_Request_CanTpRxNPdu       0U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTpTxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANHS_Flash_DIA_XIX_0x17FC4206_XIX_0x17FE4206_XIX_Physical_DIA_eCS_Resp_XIX_Airbag_SUBCANFD_402539014T_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpTxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANHS_Flash_DIA_XIX_0x17FC4206_XIX_0x17FE4206_XIX_Physical_DIA_eCS_Resp_XIX_Airbag_SUBCANFD_402539014T_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpTxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANHS_Flash_DIA_XIX_0x17FC4206_XIX_0x17FE4206_XIX_Physical_DIA_eCS_Resp_XIX_Airbag_SUBCANFD_402539014T_TDK_4G) */

/** \brief Export symbolic name value for TPC_DIA_DIA_Request_CanTpTxFcNPdu_TDK_4G */
#define CanTpConf_CanTpTxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANHS_Flash_DIA_XIX_0x17FC4206_XIX_0x17FE4206_XIX_Physical_DIA_eCS_Resp_XIX_Airbag_SUBCANFD_402539014T_TDK_4G   0U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */

#if (defined CanTp_TPC_DIA_DIA_Request_CanTpTxFcNPdu) /* to prevent double declaration */
#error CanTp_TPC_DIA_DIA_Request_CanTpTxFcNPdu is already defined
#endif /* if (defined CanTp_TPC_DIA_DIA_Request_CanTpTxFcNPdu) */

#define CanTp_TPC_DIA_DIA_Request_CanTpTxFcNPdu       0U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/*------------------------ DIA_FD_Request---------------------------------- */


#if (defined CanTpConf_CanTpRxNSdu_DIA_FD_Request_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpRxNSdu_DIA_FD_Request_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpRxNSdu_DIA_FD_Request_TDK_4G) */

/** \brief Export symbolic name value for TPC_DIA_FD_DIA_FD_Request */
#define CanTpConf_CanTpRxNSdu_DIA_FD_Request_TDK_4G   1U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_DIA_FD_DIA_FD_Request) /* to prevent double declaration */
#error CanTp_TPC_DIA_FD_DIA_FD_Request is already defined
#endif /* if (defined CanTp_TPC_DIA_FD_DIA_FD_Request) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define CanTp_TPC_DIA_FD_DIA_FD_Request       1U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTpRxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Flash_DIA_XIX_0x1C404206_XIX_0x1C424206_XIX_Physical_DIA_eCS_Req_FD_XIX_Airbag_SUBCANFD_473973254R_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpRxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Flash_DIA_XIX_0x1C404206_XIX_0x1C424206_XIX_Physical_DIA_eCS_Req_FD_XIX_Airbag_SUBCANFD_473973254R_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpRxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Flash_DIA_XIX_0x1C404206_XIX_0x1C424206_XIX_Physical_DIA_eCS_Req_FD_XIX_Airbag_SUBCANFD_473973254R_TDK_4G) */

/** \brief Export symbolic name value for TPC_DIA_FD_DIA_FD_Request_CanTpRxNPdu_TDK_4G */
#define CanTpConf_CanTpRxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Flash_DIA_XIX_0x1C404206_XIX_0x1C424206_XIX_Physical_DIA_eCS_Req_FD_XIX_Airbag_SUBCANFD_473973254R_TDK_4G  1U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_DIA_FD_DIA_FD_Request_CanTpRxNPdu) /* to prevent double declaration */
#error CanTp_TPC_DIA_FD_DIA_FD_Request_CanTpRxNPdu is already defined
#endif /* if (defined CanTp_TPC_DIA_FD_DIA_FD_Request_CanTpRxNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_TPC_DIA_FD_DIA_FD_Request_CanTpRxNPdu       1U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTpTxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Flash_DIA_XIX_0x1C404206_XIX_0x1C424206_XIX_Physical_DIA_eCS_Resp_FD_XIX_Airbag_SUBCANFD_474104326T_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpTxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Flash_DIA_XIX_0x1C404206_XIX_0x1C424206_XIX_Physical_DIA_eCS_Resp_FD_XIX_Airbag_SUBCANFD_474104326T_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpTxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Flash_DIA_XIX_0x1C404206_XIX_0x1C424206_XIX_Physical_DIA_eCS_Resp_FD_XIX_Airbag_SUBCANFD_474104326T_TDK_4G) */

/** \brief Export symbolic name value for TPC_DIA_FD_DIA_FD_Request_CanTpTxFcNPdu_TDK_4G */
#define CanTpConf_CanTpTxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Flash_DIA_XIX_0x1C404206_XIX_0x1C424206_XIX_Physical_DIA_eCS_Resp_FD_XIX_Airbag_SUBCANFD_474104326T_TDK_4G   1U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */

#if (defined CanTp_TPC_DIA_FD_DIA_FD_Request_CanTpTxFcNPdu) /* to prevent double declaration */
#error CanTp_TPC_DIA_FD_DIA_FD_Request_CanTpTxFcNPdu is already defined
#endif /* if (defined CanTp_TPC_DIA_FD_DIA_FD_Request_CanTpTxFcNPdu) */

#define CanTp_TPC_DIA_FD_DIA_FD_Request_CanTpTxFcNPdu       1U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/*------------------------ Diag_FD_Request---------------------------------- */


#if (defined CanTpConf_CanTpRxNSdu_Diag_FD_Request_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpRxNSdu_Diag_FD_Request_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpRxNSdu_Diag_FD_Request_TDK_4G) */

/** \brief Export symbolic name value for TPC_Diag_FD_Diag_FD_Request */
#define CanTpConf_CanTpRxNSdu_Diag_FD_Request_TDK_4G   2U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_Diag_FD_Diag_FD_Request) /* to prevent double declaration */
#error CanTp_TPC_Diag_FD_Diag_FD_Request is already defined
#endif /* if (defined CanTp_TPC_Diag_FD_Diag_FD_Request) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define CanTp_TPC_Diag_FD_Diag_FD_Request       2U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTpRxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Diag_XIX_0x1C405206_XIX_0x1C425206_XIX_Physical_Diag_eCS_Req_FD_XIX_Airbag_SUBCANFD_473977350R_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpRxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Diag_XIX_0x1C405206_XIX_0x1C425206_XIX_Physical_Diag_eCS_Req_FD_XIX_Airbag_SUBCANFD_473977350R_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpRxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Diag_XIX_0x1C405206_XIX_0x1C425206_XIX_Physical_Diag_eCS_Req_FD_XIX_Airbag_SUBCANFD_473977350R_TDK_4G) */

/** \brief Export symbolic name value for TPC_Diag_FD_Diag_FD_Request_CanTpRxNPdu_TDK_4G */
#define CanTpConf_CanTpRxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Diag_XIX_0x1C405206_XIX_0x1C425206_XIX_Physical_Diag_eCS_Req_FD_XIX_Airbag_SUBCANFD_473977350R_TDK_4G  2U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_Diag_FD_Diag_FD_Request_CanTpRxNPdu) /* to prevent double declaration */
#error CanTp_TPC_Diag_FD_Diag_FD_Request_CanTpRxNPdu is already defined
#endif /* if (defined CanTp_TPC_Diag_FD_Diag_FD_Request_CanTpRxNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_TPC_Diag_FD_Diag_FD_Request_CanTpRxNPdu       2U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTpTxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Diag_XIX_0x1C405206_XIX_0x1C425206_XIX_Physical_Diag_eCS_Resp_FD_XIX_Airbag_SUBCANFD_474108422T_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpTxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Diag_XIX_0x1C405206_XIX_0x1C425206_XIX_Physical_Diag_eCS_Resp_FD_XIX_Airbag_SUBCANFD_474108422T_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpTxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Diag_XIX_0x1C405206_XIX_0x1C425206_XIX_Physical_Diag_eCS_Resp_FD_XIX_Airbag_SUBCANFD_474108422T_TDK_4G) */

/** \brief Export symbolic name value for TPC_Diag_FD_Diag_FD_Request_CanTpTxFcNPdu_TDK_4G */
#define CanTpConf_CanTpTxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Diag_XIX_0x1C405206_XIX_0x1C425206_XIX_Physical_Diag_eCS_Resp_FD_XIX_Airbag_SUBCANFD_474108422T_TDK_4G   2U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */

#if (defined CanTp_TPC_Diag_FD_Diag_FD_Request_CanTpTxFcNPdu) /* to prevent double declaration */
#error CanTp_TPC_Diag_FD_Diag_FD_Request_CanTpTxFcNPdu is already defined
#endif /* if (defined CanTp_TPC_Diag_FD_Diag_FD_Request_CanTpTxFcNPdu) */

#define CanTp_TPC_Diag_FD_Diag_FD_Request_CanTpTxFcNPdu       2U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/*------------------------ OBDC_SSN_Request---------------------------------- */


#if (defined CanTpConf_CanTpRxNSdu_OBDC_SSN_Request_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpRxNSdu_OBDC_SSN_Request_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpRxNSdu_OBDC_SSN_Request_TDK_4G) */

/** \brief Export symbolic name value for TPC_OBDC_SSN_OBDC_SSN_Request */
#define CanTpConf_CanTpRxNSdu_OBDC_SSN_Request_TDK_4G   3U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_OBDC_SSN_OBDC_SSN_Request) /* to prevent double declaration */
#error CanTp_TPC_OBDC_SSN_OBDC_SSN_Request is already defined
#endif /* if (defined CanTp_TPC_OBDC_SSN_OBDC_SSN_Request) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define CanTp_TPC_OBDC_SSN_OBDC_SSN_Request       3U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTpRxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_OBDC_SSN_Diagnose_XIX_0x1C407206_XIX_0x1C427206_XIX_Physical_OBDC_SSN_eCS_Req_FD_XIX_Airbag_SUBCANFD_473985542R_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpRxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_OBDC_SSN_Diagnose_XIX_0x1C407206_XIX_0x1C427206_XIX_Physical_OBDC_SSN_eCS_Req_FD_XIX_Airbag_SUBCANFD_473985542R_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpRxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_OBDC_SSN_Diagnose_XIX_0x1C407206_XIX_0x1C427206_XIX_Physical_OBDC_SSN_eCS_Req_FD_XIX_Airbag_SUBCANFD_473985542R_TDK_4G) */

/** \brief Export symbolic name value for TPC_OBDC_SSN_OBDC_SSN_Request_CanTpRxNPdu_TDK_4G */
#define CanTpConf_CanTpRxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_OBDC_SSN_Diagnose_XIX_0x1C407206_XIX_0x1C427206_XIX_Physical_OBDC_SSN_eCS_Req_FD_XIX_Airbag_SUBCANFD_473985542R_TDK_4G  3U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_OBDC_SSN_OBDC_SSN_Request_CanTpRxNPdu) /* to prevent double declaration */
#error CanTp_TPC_OBDC_SSN_OBDC_SSN_Request_CanTpRxNPdu is already defined
#endif /* if (defined CanTp_TPC_OBDC_SSN_OBDC_SSN_Request_CanTpRxNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_TPC_OBDC_SSN_OBDC_SSN_Request_CanTpRxNPdu       3U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTpTxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_OBDC_SSN_Diagnose_XIX_0x1C407206_XIX_0x1C427206_XIX_Physical_OBDC_SSN_eCS_Resp_FD_XIX_Airbag_SUBCANFD_474116614T_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpTxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_OBDC_SSN_Diagnose_XIX_0x1C407206_XIX_0x1C427206_XIX_Physical_OBDC_SSN_eCS_Resp_FD_XIX_Airbag_SUBCANFD_474116614T_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpTxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_OBDC_SSN_Diagnose_XIX_0x1C407206_XIX_0x1C427206_XIX_Physical_OBDC_SSN_eCS_Resp_FD_XIX_Airbag_SUBCANFD_474116614T_TDK_4G) */

/** \brief Export symbolic name value for TPC_OBDC_SSN_OBDC_SSN_Request_CanTpTxFcNPdu_TDK_4G */
#define CanTpConf_CanTpTxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_OBDC_SSN_Diagnose_XIX_0x1C407206_XIX_0x1C427206_XIX_Physical_OBDC_SSN_eCS_Resp_FD_XIX_Airbag_SUBCANFD_474116614T_TDK_4G   3U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)
/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */

#if (defined CanTp_TPC_OBDC_SSN_OBDC_SSN_Request_CanTpTxFcNPdu) /* to prevent double declaration */
#error CanTp_TPC_OBDC_SSN_OBDC_SSN_Request_CanTpTxFcNPdu is already defined
#endif /* if (defined CanTp_TPC_OBDC_SSN_OBDC_SSN_Request_CanTpTxFcNPdu) */

#define CanTp_TPC_OBDC_SSN_OBDC_SSN_Request_CanTpTxFcNPdu       3U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/* generate macros for CanTpTxNSdus */


/*------------------------ DIA_Response---------------------------------- */


#if (defined CanTpConf_CanTpTxNSdu_DIA_Response_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpTxNSdu_DIA_Response_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpTxNSdu_DIA_Response_TDK_4G) */

/** \brief Export symbolic name value for TPC_DIA_DIA_Response_TDK_4G */
#define CanTpConf_CanTpTxNSdu_DIA_Response_TDK_4G           0U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_DIA_DIA_Response) /* to prevent double declaration */
#error CanTp_TPC_DIA_DIA_Response is already defined
#endif /* if (defined CanTp_TPC_DIA_DIA_Response) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define CanTp_TPC_DIA_DIA_Response               0U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTpRxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANHS_Flash_DIA_XIX_0x17FE4206_XIX_0x17FC4206_XIX_Physical_DIA_eCS_Req_XIX_Airbag_SUBCANFD_402407942R_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpRxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANHS_Flash_DIA_XIX_0x17FE4206_XIX_0x17FC4206_XIX_Physical_DIA_eCS_Req_XIX_Airbag_SUBCANFD_402407942R_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpRxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANHS_Flash_DIA_XIX_0x17FE4206_XIX_0x17FC4206_XIX_Physical_DIA_eCS_Req_XIX_Airbag_SUBCANFD_402407942R_TDK_4G) */

/** \brief Export symbolic name value for TPC_DIA_DIA_Response_CanTpRxFcNPdu_TDK_4G */
#define CanTpConf_CanTpRxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANHS_Flash_DIA_XIX_0x17FE4206_XIX_0x17FC4206_XIX_Physical_DIA_eCS_Req_XIX_Airbag_SUBCANFD_402407942R_TDK_4G  0U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_DIA_DIA_Response_CanTpRxFcNPdu) /* to prevent double declaration */
#error CanTp_TPC_DIA_DIA_Response_CanTpRxFcNPdu is already defined
#endif /* if (defined CanTp_TPC_DIA_DIA_Response_CanTpRxFcNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_TPC_DIA_DIA_Response_CanTpRxFcNPdu      0U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTpTxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANHS_Flash_DIA_XIX_0x17FE4206_XIX_0x17FC4206_XIX_Physical_DIA_eCS_Resp_XIX_Airbag_SUBCANFD_D_402539014T_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpTxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANHS_Flash_DIA_XIX_0x17FE4206_XIX_0x17FC4206_XIX_Physical_DIA_eCS_Resp_XIX_Airbag_SUBCANFD_D_402539014T_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpTxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANHS_Flash_DIA_XIX_0x17FE4206_XIX_0x17FC4206_XIX_Physical_DIA_eCS_Resp_XIX_Airbag_SUBCANFD_D_402539014T_TDK_4G) */

/** \brief Export symbolic name value for TPC_DIA_DIA_Response_CanTpTxNPdu_TDK_4G */
#define CanTpConf_CanTpTxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANHS_Flash_DIA_XIX_0x17FE4206_XIX_0x17FC4206_XIX_Physical_DIA_eCS_Resp_XIX_Airbag_SUBCANFD_D_402539014T_TDK_4G   4U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_DIA_DIA_Response_CanTpTxNPdu) /* to prevent double declaration */
#error CanTp_TPC_DIA_DIA_Response_CanTpTxNPdu is already defined
#endif /* if (defined CanTp_TPC_DIA_DIA_Response_CanTpTxNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_TPC_DIA_DIA_Response_CanTpTxNPdu       4U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/*------------------------ DIA_FD_Response---------------------------------- */


#if (defined CanTpConf_CanTpTxNSdu_DIA_FD_Response_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpTxNSdu_DIA_FD_Response_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpTxNSdu_DIA_FD_Response_TDK_4G) */

/** \brief Export symbolic name value for TPC_DIA_FD_DIA_FD_Response_TDK_4G */
#define CanTpConf_CanTpTxNSdu_DIA_FD_Response_TDK_4G           1U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_DIA_FD_DIA_FD_Response) /* to prevent double declaration */
#error CanTp_TPC_DIA_FD_DIA_FD_Response is already defined
#endif /* if (defined CanTp_TPC_DIA_FD_DIA_FD_Response) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define CanTp_TPC_DIA_FD_DIA_FD_Response               1U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTpRxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Flash_DIA_XIX_0x1C424206_XIX_0x1C404206_XIX_Physical_DIA_eCS_Req_FD_XIX_Airbag_SUBCANFD_473973254R_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpRxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Flash_DIA_XIX_0x1C424206_XIX_0x1C404206_XIX_Physical_DIA_eCS_Req_FD_XIX_Airbag_SUBCANFD_473973254R_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpRxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Flash_DIA_XIX_0x1C424206_XIX_0x1C404206_XIX_Physical_DIA_eCS_Req_FD_XIX_Airbag_SUBCANFD_473973254R_TDK_4G) */

/** \brief Export symbolic name value for TPC_DIA_FD_DIA_FD_Response_CanTpRxFcNPdu_TDK_4G */
#define CanTpConf_CanTpRxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Flash_DIA_XIX_0x1C424206_XIX_0x1C404206_XIX_Physical_DIA_eCS_Req_FD_XIX_Airbag_SUBCANFD_473973254R_TDK_4G  1U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_DIA_FD_DIA_FD_Response_CanTpRxFcNPdu) /* to prevent double declaration */
#error CanTp_TPC_DIA_FD_DIA_FD_Response_CanTpRxFcNPdu is already defined
#endif /* if (defined CanTp_TPC_DIA_FD_DIA_FD_Response_CanTpRxFcNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_TPC_DIA_FD_DIA_FD_Response_CanTpRxFcNPdu      1U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTpTxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Flash_DIA_XIX_0x1C424206_XIX_0x1C404206_XIX_Physical_DIA_eCS_Resp_FD_XIX_Airbag_SUBCANFD_D_474104326T_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpTxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Flash_DIA_XIX_0x1C424206_XIX_0x1C404206_XIX_Physical_DIA_eCS_Resp_FD_XIX_Airbag_SUBCANFD_D_474104326T_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpTxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Flash_DIA_XIX_0x1C424206_XIX_0x1C404206_XIX_Physical_DIA_eCS_Resp_FD_XIX_Airbag_SUBCANFD_D_474104326T_TDK_4G) */

/** \brief Export symbolic name value for TPC_DIA_FD_DIA_FD_Response_CanTpTxNPdu_TDK_4G */
#define CanTpConf_CanTpTxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Flash_DIA_XIX_0x1C424206_XIX_0x1C404206_XIX_Physical_DIA_eCS_Resp_FD_XIX_Airbag_SUBCANFD_D_474104326T_TDK_4G   5U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_DIA_FD_DIA_FD_Response_CanTpTxNPdu) /* to prevent double declaration */
#error CanTp_TPC_DIA_FD_DIA_FD_Response_CanTpTxNPdu is already defined
#endif /* if (defined CanTp_TPC_DIA_FD_DIA_FD_Response_CanTpTxNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_TPC_DIA_FD_DIA_FD_Response_CanTpTxNPdu       5U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/*------------------------ Diag_FD_Response---------------------------------- */


#if (defined CanTpConf_CanTpTxNSdu_Diag_FD_Response_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpTxNSdu_Diag_FD_Response_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpTxNSdu_Diag_FD_Response_TDK_4G) */

/** \brief Export symbolic name value for TPC_Diag_FD_Diag_FD_Response_TDK_4G */
#define CanTpConf_CanTpTxNSdu_Diag_FD_Response_TDK_4G           2U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_Diag_FD_Diag_FD_Response) /* to prevent double declaration */
#error CanTp_TPC_Diag_FD_Diag_FD_Response is already defined
#endif /* if (defined CanTp_TPC_Diag_FD_Diag_FD_Response) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define CanTp_TPC_Diag_FD_Diag_FD_Response               2U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTpRxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Diag_XIX_0x1C425206_XIX_0x1C405206_XIX_Physical_Diag_eCS_Req_FD_XIX_Airbag_SUBCANFD_473977350R_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpRxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Diag_XIX_0x1C425206_XIX_0x1C405206_XIX_Physical_Diag_eCS_Req_FD_XIX_Airbag_SUBCANFD_473977350R_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpRxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Diag_XIX_0x1C425206_XIX_0x1C405206_XIX_Physical_Diag_eCS_Req_FD_XIX_Airbag_SUBCANFD_473977350R_TDK_4G) */

/** \brief Export symbolic name value for TPC_Diag_FD_Diag_FD_Response_CanTpRxFcNPdu_TDK_4G */
#define CanTpConf_CanTpRxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Diag_XIX_0x1C425206_XIX_0x1C405206_XIX_Physical_Diag_eCS_Req_FD_XIX_Airbag_SUBCANFD_473977350R_TDK_4G  2U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_Diag_FD_Diag_FD_Response_CanTpRxFcNPdu) /* to prevent double declaration */
#error CanTp_TPC_Diag_FD_Diag_FD_Response_CanTpRxFcNPdu is already defined
#endif /* if (defined CanTp_TPC_Diag_FD_Diag_FD_Response_CanTpRxFcNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_TPC_Diag_FD_Diag_FD_Response_CanTpRxFcNPdu      2U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTpTxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Diag_XIX_0x1C425206_XIX_0x1C405206_XIX_Physical_Diag_eCS_Resp_FD_XIX_Airbag_SUBCANFD_D_474108422T_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpTxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Diag_XIX_0x1C425206_XIX_0x1C405206_XIX_Physical_Diag_eCS_Resp_FD_XIX_Airbag_SUBCANFD_D_474108422T_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpTxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Diag_XIX_0x1C425206_XIX_0x1C405206_XIX_Physical_Diag_eCS_Resp_FD_XIX_Airbag_SUBCANFD_D_474108422T_TDK_4G) */

/** \brief Export symbolic name value for TPC_Diag_FD_Diag_FD_Response_CanTpTxNPdu_TDK_4G */
#define CanTpConf_CanTpTxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_Diag_XIX_0x1C425206_XIX_0x1C405206_XIX_Physical_Diag_eCS_Resp_FD_XIX_Airbag_SUBCANFD_D_474108422T_TDK_4G   6U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_Diag_FD_Diag_FD_Response_CanTpTxNPdu) /* to prevent double declaration */
#error CanTp_TPC_Diag_FD_Diag_FD_Response_CanTpTxNPdu is already defined
#endif /* if (defined CanTp_TPC_Diag_FD_Diag_FD_Response_CanTpTxNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_TPC_Diag_FD_Diag_FD_Response_CanTpTxNPdu       6U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/*------------------------ OBDC_SSN_Response---------------------------------- */


#if (defined CanTpConf_CanTpTxNSdu_OBDC_SSN_Response_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpTxNSdu_OBDC_SSN_Response_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpTxNSdu_OBDC_SSN_Response_TDK_4G) */

/** \brief Export symbolic name value for TPC_OBDC_SSN_OBDC_SSN_Response_TDK_4G */
#define CanTpConf_CanTpTxNSdu_OBDC_SSN_Response_TDK_4G           3U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_OBDC_SSN_OBDC_SSN_Response) /* to prevent double declaration */
#error CanTp_TPC_OBDC_SSN_OBDC_SSN_Response is already defined
#endif /* if (defined CanTp_TPC_OBDC_SSN_OBDC_SSN_Response) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
 *         (AUTOSAR 4.0 rev2 <= AUTOSAR version )
 */
#define CanTp_TPC_OBDC_SSN_OBDC_SSN_Response               3U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTpRxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_OBDC_SSN_Diagnose_XIX_0x1C427206_XIX_0x1C407206_XIX_Physical_OBDC_SSN_eCS_Req_FD_XIX_Airbag_SUBCANFD_473985542R_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpRxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_OBDC_SSN_Diagnose_XIX_0x1C427206_XIX_0x1C407206_XIX_Physical_OBDC_SSN_eCS_Req_FD_XIX_Airbag_SUBCANFD_473985542R_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpRxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_OBDC_SSN_Diagnose_XIX_0x1C427206_XIX_0x1C407206_XIX_Physical_OBDC_SSN_eCS_Req_FD_XIX_Airbag_SUBCANFD_473985542R_TDK_4G) */

/** \brief Export symbolic name value for TPC_OBDC_SSN_OBDC_SSN_Response_CanTpRxFcNPdu_TDK_4G */
#define CanTpConf_CanTpRxFcNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_OBDC_SSN_Diagnose_XIX_0x1C427206_XIX_0x1C407206_XIX_Physical_OBDC_SSN_eCS_Req_FD_XIX_Airbag_SUBCANFD_473985542R_TDK_4G  3U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_OBDC_SSN_OBDC_SSN_Response_CanTpRxFcNPdu) /* to prevent double declaration */
#error CanTp_TPC_OBDC_SSN_OBDC_SSN_Response_CanTpRxFcNPdu is already defined
#endif /* if (defined CanTp_TPC_OBDC_SSN_OBDC_SSN_Response_CanTpRxFcNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_TPC_OBDC_SSN_OBDC_SSN_Response_CanTpRxFcNPdu      3U
#endif /* defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES */


#if (defined CanTpConf_CanTpTxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_OBDC_SSN_Diagnose_XIX_0x1C427206_XIX_0x1C407206_XIX_Physical_OBDC_SSN_eCS_Resp_FD_XIX_Airbag_SUBCANFD_D_474116614T_TDK_4G) /* to prevent double declaration */
#error CanTpConf_CanTpTxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_OBDC_SSN_Diagnose_XIX_0x1C427206_XIX_0x1C407206_XIX_Physical_OBDC_SSN_eCS_Resp_FD_XIX_Airbag_SUBCANFD_D_474116614T_TDK_4G is already defined
#endif /* if (defined CanTpConf_CanTpTxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_OBDC_SSN_Diagnose_XIX_0x1C427206_XIX_0x1C407206_XIX_Physical_OBDC_SSN_eCS_Resp_FD_XIX_Airbag_SUBCANFD_D_474116614T_TDK_4G) */

/** \brief Export symbolic name value for TPC_OBDC_SSN_OBDC_SSN_Response_CanTpTxNPdu_TDK_4G */
#define CanTpConf_CanTpTxNPdu_DCM_Airbag_SUBCANFD_XIX_TPCHType_CANFD_OBDC_SSN_Diagnose_XIX_0x1C427206_XIX_0x1C407206_XIX_Physical_OBDC_SSN_eCS_Resp_FD_XIX_Airbag_SUBCANFD_D_474116614T_TDK_4G   7U

#if (defined CANTP_PROVIDE_LEGACY_SYMBOLIC_NAMES)

#if (defined CanTp_TPC_OBDC_SSN_OBDC_SSN_Response_CanTpTxNPdu) /* to prevent double declaration */
#error CanTp_TPC_OBDC_SSN_OBDC_SSN_Response_CanTpTxNPdu is already defined
#endif /* if (defined CanTp_TPC_OBDC_SSN_OBDC_SSN_Response_CanTpTxNPdu) */

/** \brief Export symbolic name value with module abbreviation as prefix only 
           (AUTOSAR 4.0 rev2 <= AUTOSAR version )                               */
#define CanTp_TPC_OBDC_SSN_OBDC_SSN_Response_CanTpTxNPdu       7U
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

#endif /* if !defined( CANTP_SYMBOLICNAMESTDK_4G_PBCFG_H ) */
/*==================[end of file]===========================================*/
