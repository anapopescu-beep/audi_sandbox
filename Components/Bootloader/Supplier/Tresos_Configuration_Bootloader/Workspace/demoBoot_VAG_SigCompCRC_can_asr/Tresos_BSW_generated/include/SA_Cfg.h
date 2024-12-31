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
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 1.17.0 BL3 */
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

 #define SA_CSMASR43_USED                 STD_OFF
 #define SA_Csm_MainFunction              Csm_MainFunction
 #define SA_CSM_INDEX(job_name)                job_name
 

#define SA_CSM_SETKEY_ENABLED             STD_OFF

 #define SA_CSM_CANCELJOB_ENABLED             STD_OFF

 #define SA_ECB2CTR_ENABLED             STD_OFF


#define SA_CUSTOM_CSMSTARTPREPROCESS_ENABLED             STD_OFF

/* Timer period in milliseconds for the SA periodic task */
/* The minimum value accepted for SA_MANAGE_PERIOD is 1 */
/* Range : (1 .. 100) */
#define SA_MANAGE_PERIOD                1U


#define SA_SECURITY_ALOGORITHM_STANDARD    0X00U
#define SA_SECURITY_ALOGORITHM_CUSTOM      0X01U
#define SA_SECURITY_ALOGORITHM_UNDEFINED   0XFFU
#define SA_COMPRESSION_ENABLED            0x01U
#define SA_COMPRESSION_DISABLED           0x02U
#define SA_COMPRESSION_STATE              SA_COMPRESSION_ENABLED


#define SA_CHALLENGE_BIT 64U /* Size of PROG_SA_CHALLENGE_BYTE in bit, 8*8 = 64 */

#define SA_SEED_STANDARD    0x00U
#define SA_SEED_CSM_RANDOM  0x01U
#define SA_SEED_LEN   (4U)
#define SA_KEY_LEN   (4U)
#define SA_STATIC_KEY_LEN 5U     /* size of the static key */
#define SA_RANDOM_NUMBER_LENGTH           SA_SEED_LEN

#define SA_SEED_TYPE                    SA_SEED_STANDARD
 
#define SA_SECURITY_ALOGORITHM_TYPE                    SA_SECURITY_ALOGORITHM_CUSTOM
#define SA_COMPARE_KEY_STANDARD         0x00U
#define SA_COMPARE_KEY_VERIFY_SIGNATURE 0x01U
#define SA_COMPARE_KEY_AM0001           0x02U

#define SA_COMPARE_KEY_TYPE                     SA_COMPARE_KEY_STANDARD

#define SA_USE_CRYPTO                   STD_OFF


#define SA_REQUEST_SEED_DELAY_TIMER_ENABLED            STD_OFF

#define SA_ANTISCANNING_ENABLED            STD_ON
/* Anti-scanning Timer Load value */
#define  SA_AS_LOCK_TIMER                  600000U
/* Anti-scanning Retry Counter value */
#define SA_AS_MAX_NB_RETRY                 2U


#define SA_LIMIT_NB_REQUEST_SEED_ENABLED            STD_OFF


#define SA_STATIC_SEED_ENABLED            STD_OFF

#define SA_AUTHENTICATION_0001 0x0001U
#define SA_AUTHENTICATION_OFF  0xFFFFU

#define SA_AUTHENTICATION_METHOD             SA_AUTHENTICATION_OFF
#define SA_CSM_AESCTR_ENCRYPTION_USED        STD_OFF
#define SA_CSM_AESCTR_DECRYPTION_USED        STD_OFF
#define SA_CSM_MAC_GENERATION_USED           STD_OFF
#define SA_CSM_MAC_VERIFICATION_USED         STD_OFF

#ifndef SA_SECURITY_ALOGORITHM_TYPE
#define SA_SECURITY_ALOGORITHM_TYPE       SA_SECURITY_ALOGORITHM_UNDEFINED
#endif
#endif      /* SA_CFG_H */
