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
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 1.1.7 BL-3.X                */
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

#define BM_CSM_WRAPPER_43_USED              STD_OFF
/* BM Network */
#define BM_CAN_USED                         0U
#define BM_FLEXRAY_USED                     1U
#define BM_ETHERNET_USED                    2U
#define BM_NETWORK_USED                     BM_ETHERNET_USED

/* BM Timeout Check */
#define BM_TIMEOUT_CHECK_OFF                0U
#define BM_TIMEOUT_CHECK_ON                 1U
#define BM_TIMEOUT_CHECK                    BM_TIMEOUT_CHECK_OFF


/* BM Network Management */

#define BM_NETWORK_MANAGEMENT_ENABLE        STD_OFF


/* BM Csm Presence */
#define BM_CSM_PRESENT                      STD_ON

/* Source Address Check status */
#define BM_SOURCE_ADDRESS_CHECK             STD_OFF

/* BM Authenticated Boot/Secure Boot information */
#define BM_AUTHENTICATED_BOOT_ENABLE        STD_OFF
#define BM_SECURE_BOOT_ENABLE               STD_OFF
#define BM_BOOT_CHECKSUM_VERIFICATION       STD_OFF


#define BM_CSM_MAC_USED                     STD_OFF
#define BM_CSM_HASH_USED                    STD_OFF



#endif /* BM_CFG_H */
