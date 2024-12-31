/*********************************************************************************/
/*===============================================================================*/
/*                                                                               */
/*                               FLASH layers                                    */
/*                                                                               */
/* ------------------------------------------------------------------------------*/
/*                                                                               */
/*                              FLASH  configuration                             */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file FlashWrapper_Generated.h        */
/*%%  |                             |  %%  \brief FLASH layer implementation     */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 30.0.2                 */
/*%%  |   &       &    &            |  %%  Variant: Autosar                  */
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
/*********************************************************************************/




/******************************** FILE INCLUSION *********************************/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Header Files:                                                               */
#include "EB_Prj.h"

/*                                                                               */
/*********************************************************************************/
[!AUTOSPACING!]
const tFLASHSectorsTable FlashSectorsTable[FLASH_SECTORS_TABLE_NB_ELEMENTS] =
{
[!VAR "NB_RANGE_SECTOR_DECLARATION"="num:dectoint(count(FlashSectors/FlashSectors/*))"!]
[!IF "$NB_RANGE_SECTOR_DECLARATION = 0"!]
[!ERROR "At least one range sector address must be configured!!!"!]
[!ENDIF!]
  /*Start_Address        Length              Sector_Size           Programmable */
[!FOR "RANGE_SECTOR_IDX" = "1" TO "$NB_RANGE_SECTOR_DECLARATION"!]
  {[!"num:inttohex(FlashSectors/FlashSectors/*[number($RANGE_SECTOR_IDX)]/Start_Address,8)"!]U,[!WS "8"!][!"num:inttohex(FlashSectors/FlashSectors/*[number($RANGE_SECTOR_IDX)]/Length,8)"!]U,[!WS "10"!][!"num:inttohex(FlashSectors/FlashSectors/*[number($RANGE_SECTOR_IDX)]/Sector_Size,8)"!]U,[!WS "10"!][!IF "(FlashSectors/FlashSectors/*[number($RANGE_SECTOR_IDX)]/Programmable='true')"!] TRUE[!ELSE!] FALSE[!ENDIF!]},
[!ENDFOR!]
};


/***************************** PRIVATE DEFINITIONS *******************************/
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
/*********************************************************************************/
