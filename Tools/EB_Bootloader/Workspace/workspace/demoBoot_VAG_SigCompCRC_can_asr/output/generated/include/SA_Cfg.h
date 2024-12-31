/*********************************************************************************/
/*                                                                               */
/*                                 Sa LAYER                                      */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                               Security Access                                 */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file SA_Cfg.h                        */
/*%%  |                             |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 1.6.1 BL-3.X */
/*%%  |   &       &    &            |  %%                                        */
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

#ifndef SA_CFG_H
#define SA_CFG_H

/* Timer period in milliseconds for the SA periodic task */
/* The minimum value accepted for SA_MANAGE_PERIOD is 1 */
/* Range : (1 .. 100) */
#define SA_MANAGE_PERIOD                1U

#define SA_SEED_LEN   (4U)
#define SA_KEY_LEN   (4U)
#define SA_STATIC_KEY_LEN 5U     /* size of the static key */

#define SA_COMPRESSION_ENABLED            0x01U
#define SA_COMPRESSION_DISABLED           0x02U
#define SA_COMPRESSION_STATE        SA_COMPRESSION_ENABLED


#define SA_RANDOM_NUMBER_LENGTH SA_SEED_LEN

#define SA_CHALLENGE_BIT 64U /* Size of PROG_SA_CHALLENGE_BYTE in bit, 8*8 = 64 */

#define SA_SEED_STANDARD    0x00U
#define SA_SEED_CSM_RANDOM  0x01U

#define SA_SEED_TYPE                       SA_SEED_STANDARD


#define SA_SECURITY_ALOGORITHM_STANDARD    0X00U
#define SA_SECURITY_ALOGORITHM_CUSTOM      0X01U
 
#define SA_SECURITY_ALOGORITHM_TYPE       SA_SECURITY_ALOGORITHM_CUSTOM


#define SA_COMPARE_KEY_STANDARD         0x00U
#define SA_COMPARE_KEY_VERIFY_SIGNATURE 0x01U

#define SA_COMPARE_KEY_TYPE                SA_COMPARE_KEY_STANDARD


#define SA_USE_CRYPTO                   STD_OFF



#define SA_ANTISCANNING_ENABLED            STD_ON
/* Anti-scanning Timer Load value */
#define  SA_AS_LOCK_TIMER                  10000U
/* Anti-scanning Retry Counter value */
#define SA_AS_MAX_NB_RETRY                 2U



#define SA_STATIC_SEED_ENABLED            STD_OFF




#endif      /* SA_CFG_H */
