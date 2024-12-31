/*===============================================================================*/
/*                                                                               */
/*                               BOOT Layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                               BM layer                                        */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file BM_Cbk.c                        */
/*%%  |                             |  %%  \brief PROG layer include plugin file */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 0.0.255 OSC_BOOT                */
/*%%  |   &       &    &            |  %%  Variant: OsekCore                  */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*===============================================================================*/
/* Copyright 2010 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*===============================================================================*/

/*=============================== FILE INCLUSION ================================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Header Files                                                                */

#include "EB_Prj.h"
#include "Target_Specific_Definition.h"
/*                                                                               */
/*===============================================================================*/




/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */

/*-------------------------------------------------------------------------------*/
/* - Public Function Prototypes                                                  */

/*-------------------------------------------------------------------------------*/
/* - Public Callback Prototypes                                                  */

/*                                                                               */
/*===============================================================================*/

/*============================ PRIVATE DEFINITIONS ==============================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Private Constants                                                           */

/*-------------------------------------------------------------------------------*/
/* - Private Variables                                                           */

/*-------------------------------------------------------------------------------*/
/* - Private Macros                                                              */

/*-------------------------------------------------------------------------------*/
/* - Private Function Prototypes                                                 */

/*                                                                               */
/*===============================================================================*/


/*=============================== IMPLEMENTATION ================================*/
/*                                                                               */

/*-------------------------------------------------------------------------------*/
/* - Public Functions                                                            */

/*----------------------------{BM_HardwareInit}----------------------------------*/
void BM_HardwareInit (void)
{

}
/*----------------------------{end BM_HardwareInit}------------------------------*/

/*----------------------------{BM_SoftwareInit}----------------------------------*/
void BM_SoftwareInit(void)
{
    u16 i;
    u16 j;

    if (stNVMBootloaderData.ulInitPattern != NVM_INIT_PATTERN)
    {
        for (i = 0; i < PROG_BLOCK_NBR; i++)
        {
            
            /* Init segment address to 0 */
            /* Init block status info to block invalid */
            for (j = 0; j < PROG_MAX_NBR_SEG; j++)
            {
                stNVMBootloaderData.stNVMBlockData[i].stSegmentList.aulSegProgSize[j] = 0x0U;
            }
            
            /* Init number of segment strored to 0 */
            stNVMBootloaderData.stNVMBlockData[i].stSegmentList.ubNbSegNbr = 0U;
            
            /* Init counter to 0 */
            stNVMBootloaderData.stNVMBlockData[i].uwProgCounter = 0x0000U;
            
            /* Init block status info to block invalid */
            for (j = 0; j < PROG_FINGERPRINT_LENGTH; j++)
            {
                stNVMBootloaderData.stNVMBlockData[i].aubFingerPrintInfo[j] = 0xFFU;
            }
        }

        /* Init ECU information to Inconsistent */
        stNVMBootloaderData.stNVMEcuData.ubECUProgInfo = PROG_ECUPROGINFO_INCONSISTENT;
    
        /* Init As retry count to 0 */
        stNVMBootloaderData.stNVMEcuData.ubAsRetryCnt = 0U;

        for (j = 0; j < SA_RANDOM_NUMBER_LENGTH; j++)
        {
            stNVMBootloaderData.stNVMEcuData.aubRandom[j] = 0x00U;
        }

        stNVMBootloaderData.ulInitPattern = NVM_INIT_PATTERN;
    }

}
/*----------------------------{end BM_SoftwareInit}-----------------------------*/

