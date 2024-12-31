/*
===============================================================================

                               BOOT layers

 -----------------------------------------------------------------------------

                                 FLASH configuration

===============================================================================
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%   _____________________________   %%  File: FLASH_LLD.C
%%  |                             |  %%  Purpose: FLASH layer implementation
%%  |   &&&&&   &&&&&             |  %%  Module version: 7.0.2
%%  |   &       &    &            |  %%  Target: CORTEXM
%%  |   &&&&    &&&&&             |  %%  Derivate: S32K14X
%%  |   &       &    &            |  %%  Variant: OsekCore
%%  |   &&&&&   &&&&&             |  %%
%%  |_____________________________|  %%
%%                                   %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
===============================================================================
 Copyright 2010 by Elektrobit Automotive GmbH
 All rights exclusively reserved for Elektrobit Automotive GmbH,
 unless expressly agreed to otherwise.
===============================================================================
*/ 

/*=============================== FILE INCLUSION ================================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Header Files:                                                               */
#include "EB_Prj.h"
#include "Flash_LLD.h"
#if (FLASH_WATCHDOG_CARE == FLASH_TRUE)
#include "Watchdog.h"
#endif
#include "FLS_S32K14X.h"

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
/* - Private Types                                                               */

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
/*-------------------------------{FLASH_LLD_Init}--------------------------------*/
void FLASH_LLD_Init(void)
{
  /*Initialise the flash driver*/
  FLS_Init();

  /*Start the flash driver*/
  FLS_Start();
}
/*--------------------------------{end FLASH_LLD_Init}---------------------------*/

/*----------------------------{FLASH_LLD_EraseSector}----------------------------*/
tFlashStatus FLASH_LLD_EraseSector(u16 ulSectorNo)
{
    tFlashStatus    eFlashStatus;
    u8 ebStatus=0;
    eFlashStatus = FLASH_NO_ERROR;

#if (FLASH_WATCHDOG_CARE == FLASH_TRUE)
    /* Deactivate the watchdog before Flash operation */
    Watchdog_WdgDeactivate();
#endif

    ebStatus = APP_InterruptDisable();

    /*Call the Erase routine from RAM code*/
    eFlashStatus = FLS_Status_T.EraseSectorCbInRAM(ulSectorNo);

    APP_InterruptEnable (ebStatus);

#if (FLASH_WATCHDOG_CARE == FLASH_TRUE)
    /* Reactivate the watchdog after Flash operation */
    Watchdog_WdgActivate();
#endif

    return eFlashStatus;
}
/*--------------------------------end FLASH_LLD_EraseSector-----------------------*/
/*---------------------------{FLASH_LLD_WriteBuffer}-----------------------------*/
tFlashStatus FLASH_LLD_WriteBuffer(tFlashAddress uAddr,
                                   u16 uwLen,
                                   const u8 FLASH_FAR_POINTER aubData)
{
    tFlashStatus    eFlashStatus;
    u8 ebStatus=0;
    u16 uwWriteLength = 0U;

    eFlashStatus = FLASH_NO_ERROR;

#if (FLASH_WATCHDOG_CARE == FLASH_TRUE)
    /* Deactivate the watchdog before Flash operation */
    Watchdog_WdgDeactivate();
#endif

    ebStatus = APP_InterruptDisable();

    /*Call the Program routine from RAM code*/
    while((uwLen > uwWriteLength) && (eFlashStatus == FLASH_NO_ERROR))
    {
        eFlashStatus = FLS_Status_T.ProgramPhraseCbInRAM(uAddr, FLASH_PAGES_SIZE_BYTE, aubData);
        /* CHECK: NOPARSE */
        /* NOCOV-DEFENSIVE*/
        if(eFlashStatus != FLASH_NO_ERROR)
        {
        /* CHECK: PARSE */
            eFlashStatus =  FLASH_ACCESS_ERROR;
        }
        uwWriteLength += FLASH_PAGES_SIZE_BYTE;
        uAddr += FLASH_PAGES_SIZE_BYTE;
    }

    APP_InterruptEnable (ebStatus);

#if (FLASH_WATCHDOG_CARE == FLASH_TRUE)
    /* Reactivate the watchdog after Flash operation */
    Watchdog_WdgActivate();
#endif

    return eFlashStatus;
}
/*-----------------------------{end FLASH_LLD_WriteBuffer}-----------------------*/
