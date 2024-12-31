/*===============================================================================*/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                               SA layer                                        */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file SA_Cbk.c                        */
/*%%  |                             |  %%  \brief SA layer source plugin file    */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 1.17.0 BL3 */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*===============================================================================*/
/* Copyright 2015 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*===============================================================================*/

/*=============================== FILE INCLUSION ================================*/
/*                                                                               */
#include "EB_Prj.h"
#include "board.h"

/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */

#if (SA_SEED_TYPE != SA_SEED_CSM_RANDOM)
/** \brief API that calculates the security access key
 **
 ** This callback is called on reception of SecurityAccess service to perfom
 ** computation of the security key based on a random seed.
 **
 ** \param[in] aubSeed Address of the seed array
 ** \param[out] aubCalculatedKey Address where the calculated key will be copied
 **/
void SA_CustomCalculateKey(u8 * aubSeed, u8 * aubCalculatedKey)
{
    OSC_PARAM_UNUSED(aubSeed);
    OSC_PARAM_UNUSED(aubCalculatedKey);
}
#endif /*(SA_SEED_TYPE != SA_SEED_CSM_RANDOM)*/



#if (SA_ANTISCANNING_ENABLED == STD_ON)
/** \brief API that stores the security access anti-scanning retry counter
 **
 ** This callback is called on reception of SecurityAccess service in case
 ** anti-scanning feature is activated. The counter value provided as parameter
 ** shall be stored in non-volatile memory.
 **
 ** \param[in] RetryCntValue Value of security access anti-scanning retry counter
 **/
void SA_CustomStoreAsRetryCnt(u8 RetryCntValue)
{
    OSC_PARAM_UNUSED(RetryCntValue);
}
#endif /*(PROG_SA_ANTISCANNING_ENABLE == STD_ON)*/


#if (SA_ANTISCANNING_ENABLED == STD_ON)
/** \brief API that restores the security access anti-scanning retry counter
 **
 ** This callback is called at Bootloader startup (if anti-scanning feature is
 ** activated) to get the retry counter value from non-volatile memory.
 **
 ** \return Value of security access anti-scanning retry counter
 **/
u8 SA_CustomRestoreAsRetryCnt(void)
{
    u8 RetAsRetryCnt = 0;
    /*Fetch from NVM*/
    return RetAsRetryCnt;
}
#endif /*(PROG_SA_ANTISCANNING_ENABLE == STD_ON)*/


