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
/*%%  |   &&&&&   &&&&&             |  %%  Module version: M4_MODULE_VERSION_MAJOR.M4_MODULE_VERSION_MINOR.M4_MODULE_VERSION_PATCH M4_MODULE_VERSION_SUFFIX */
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
#include "Target_Specific_Definition.h"
#include "board.h"

/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */
/*--------------------------------{SA_CustomCalculateKey}------------------------*/
void SA_CustomCalculateKey(u8 * aubSeed, u8 * m_aubCalculatedKey)
{
    m_aubCalculatedKey[0U] = (u8)((aubSeed[0U] + 0x01) & 0xFF);
    m_aubCalculatedKey[1U] = (u8)((aubSeed[1U] + 0x02) & 0xFF);
    m_aubCalculatedKey[2U] = (u8)((aubSeed[2U] + 0x03) & 0xFF);
    m_aubCalculatedKey[3U] = (u8)((aubSeed[3U] + 0x04) & 0xFF);
}
/*------------------------------{end SA_CustomCalculateKey}----------------------*/

/*--------------------------------{SA_CustomStoreAsRetryCnt}---------------------*/
void SA_CustomStoreAsRetryCnt(u8 RetryCntValue)
{
    stNVMBootloaderData.stNVMEcuData.ubAsRetryCnt = RetryCntValue;

}
/*------------------------------{end SA_CustomStoreAsRetryCnt}-------------------*/

/*--------------------------------{SA_CustomRestoreAsRetryCnt}-------------------*/

u8 SA_CustomRestoreAsRetryCnt(void)
{
    return stNVMBootloaderData.stNVMEcuData.ubAsRetryCnt;
}
/*------------------------------{end SA_CustomRestoreAsRetryCnt}-----------------*/

void SA_CustomGetLastRandomNumber(u8* aubDataRandomNumber)
{
    u8 localIdx;
    u32 ulTempSeedData;
    /* Index of byte of the seed */
    u8 ubIdx;
    /* Index of first copied byte of the random seed */
    u8 ubIdxRandom = 3U;

    /* Retrieve a Random value */
    ulTempSeedData = BoardGetRandom();

    /* For each byte of the seed */
    for (ubIdx = 0U; ubIdx < SA_SEED_LEN; ubIdx++)
    {
        /* Copy each byte of the random seed */
        aubDataRandomNumber[ubIdx] = (u8)((u32)(ulTempSeedData >> (8U*ubIdxRandom)) & 0x000000FFU);

        /* If all of the four bytes of the random seed have been copied */
        if (0U == ubIdxRandom)
        {
            /* Set the index to the first copied byte of the random seed */
            ubIdxRandom = 3U;

            /* Generate an other random seed */
            ulTempSeedData = BoardGetRandom();
        }
        else
        {
            /* Decrease the index of the copied byte of the random seed */
            ubIdxRandom--;
        }
    }

    for(localIdx = 0U; localIdx < SA_RANDOM_NUMBER_LENGTH; localIdx++)
    {
      aubDataRandomNumber[localIdx] ^= stNVMBootloaderData.stNVMEcuData.aubRandom[localIdx];
    }
}
void SA_CustomStoreRandomNumber(u8* pubDataRandomNumber)
{
    u8 localIdx;

    for(localIdx = 0U; localIdx < SA_RANDOM_NUMBER_LENGTH; localIdx++)
    {
        stNVMBootloaderData.stNVMEcuData.aubRandom[localIdx] = pubDataRandomNumber[localIdx];
    }

}
