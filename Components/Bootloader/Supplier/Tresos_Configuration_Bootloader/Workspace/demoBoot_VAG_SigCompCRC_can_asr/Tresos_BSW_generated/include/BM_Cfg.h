/*********************************************************************************/
/*                                                                               */
/*                                BOOT Layers                                    */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                                 BM configuration                              */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file BM_Cfg.h                        */
/*%%  |                             |  %%  \brief BM layer include plugin file   */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 1.13.0 BL3                */
/*%%  |   &       &    &            |  %%  Variant: OsekCore                  */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*********************************************************************************/
/* Copyright 2010 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*********************************************************************************/

#ifndef BM_CFG_H
#define BM_CFG_H

#define BM_IMPL_10                          10U
#define BM_IMPL_NOT_DEFINED                 255U


#define BM_IMPL_VARIANT                     BM_IMPL_NOT_DEFINED


#define BM_EXECUTE_TESTAPPL                 STD_OFF


#define BM_BOOT_MANAGER_VARIANT             BM_BOOT_MANAGER


  /* BM Csm Presence */
#define BM_CSM_PRESENT                      STD_ON
/* Crypto stack ASR version used is below ASR 4.3 */
#define BM_CSM_ASR43_USED                   STD_OFF
#define BM_Csm_Mainfunction                 Csm_MainFunction

#define BM_CRYSHE_PRESENT                                STD_OFF


/* BM Network Management */
#define BM_NETWORK_MANAGEMENT_ENABLE        STD_OFF
 /*Network Selection for BL-3.x(when BLPDUR module used)*/
#define BM_NETWORK_FLEXRAY_SUPPORTED              STD_OFF
#define BM_NETWORK_CAN_SUPPORTED              STD_ON

#define BM_NETWORK_ETH_SUPPORTED              STD_OFF

#define BM_NETWORK_LIN_SUPPORTED              STD_OFF
/* BM Timeout Check */
#define BM_TIMEOUT_CHECK_OFF                0U
#define BM_TIMEOUT_CHECK_ON                 1U
#define BM_TIMEOUT_CHECK                    BM_TIMEOUT_CHECK_OFF


/* Source Address Check status */
#define BM_SOURCE_ADDRESS_CHECK             STD_OFF

#define BM_OTA_DUALBANK_USED                          STD_OFF

  
  
  

/* BM Authenticated Boot/Secure Boot information */
#define BM_AUTHENTICATED_BOOT_ENABLE        STD_OFF
#define BM_SECURE_BOOT_ENABLE               STD_OFF
#define BM_BOOT_CHECKSUM_VERIFICATION       STD_OFF


#define BM_CSM_MAC_USED                     STD_OFF
#define BM_CSM_HASH_USED                    STD_OFF


#define BM_HSM_MAC_USED                     STD_OFF


#endif /* BM_CFG_H */
