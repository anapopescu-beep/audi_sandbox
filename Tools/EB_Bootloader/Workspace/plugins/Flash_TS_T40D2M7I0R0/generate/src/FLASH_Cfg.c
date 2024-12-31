/*
===============================================================================
                                                                               
                               BOOT layers                                     
                                                                               
 ----------------------------------------------------------------------------- 
                                                                               
                                 FLASH configuration                           
                                                                               
===============================================================================
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        
%%   _____________________________   %%  File: FLASH_Cfg.c
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
[!AUTOSPACING!]


/******************************** FILE INCLUSION *********************************/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Header Files: PROG                                                          */

#include "EB_Prj.h"
/*                                                                               */
/*********************************************************************************/

const tFlsInfo Fls_Info[FLASH_INFO_SIZE] =
{
    /* Start_Address       Length           Number          Programmable */

[!IF "General/UseSectorTab = 'true'"!]
  [!VAR "SECTOR_MAX"="num:dectoint(count(FlsSector/*))"!]
  [!VAR "FLS_SECTOR_NUMBER_TEMP"="1"!]
  [!VAR "FLS_SECTOR_SIZE_TEMP"="num:inttohex(FlsSector/*[1]/Length)"!]  
  [!VAR "FLS_SECTOR_PROGRAMMABLE_TEMP"="text:tolower(FlsSector/*[1]/Programmable)"!]
  [!VAR "FLS_START_ADDRESS_TEMP"="num:inttohex(FlsSector/*[1]/Start_Address,4)"!]
  [!FOR "SECTOR_IDX" = "2" TO "$SECTOR_MAX"!]
    [!IF "num:inttohex(FlsSector/*[number($SECTOR_IDX)]/Length) = $FLS_SECTOR_SIZE_TEMP and text:tolower(FlsSector/*[number($SECTOR_IDX)]/Programmable) = $FLS_SECTOR_PROGRAMMABLE_TEMP"!]
        [!VAR "FLS_SECTOR_NUMBER_TEMP" = "$FLS_SECTOR_NUMBER_TEMP + 1"!]
    [!ELSE!]
      [!WS "4"!]{[!"$FLS_START_ADDRESS_TEMP"!]U,[!WS "10"!][!"num:inttohex(FlsSector/*[number($SECTOR_IDX)-1]/Length,5)"!]U,[!WS "10"!][!"num:integer($FLS_SECTOR_NUMBER_TEMP)"!]U,[!WS "10"!][!IF "(FlsSector/*[number($SECTOR_IDX)-1]/Programmable='true')"!] TRUE [!ELSE!] FALSE[!ENDIF!]},[!VAR "FLS_SECTOR_NUMBER_TEMP"="1"!] [!CR!]
      [!VAR "FLS_SECTOR_SIZE_TEMP"="num:inttohex(FlsSector/*[number($SECTOR_IDX)]/Length)"!]
      [!VAR "FLS_SECTOR_PROGRAMMABLE_TEMP"="text:tolower(FlsSector/*[number($SECTOR_IDX)]/Programmable)"!]
      [!VAR "FLS_START_ADDRESS_TEMP"="num:inttohex(FlsSector/*[number($SECTOR_IDX)]/Start_Address)"!]
    [!ENDIF!]
  [!ENDFOR!]  
  [!WS "4"!]{[!"$FLS_START_ADDRESS_TEMP"!]U,[!WS "10"!][!"num:inttohex(FlsSector/*[number($SECTOR_IDX)-1]/Length,5)"!]U,[!WS "10"!][!"num:integer($FLS_SECTOR_NUMBER_TEMP)"!]U,[!WS "10"!][!IF "(FlsSector/*[number($SECTOR_IDX)-1]/Programmable='true')"!] TRUE [!ELSE!] FALSE[!ENDIF!]}
};

[!ENDIF!]

[!IF "General/ActivateSecurityCheck = 'true'"!]
const tFlashActivateSecurityCheck astFlashMemoryAreas[FLASH_MAX_PROTECTED_AREA_NB] =
{
    /* Start_Address       Length */

[!VAR "PROTECTED_AREA_MAX"="num:dectoint(count(FlashMemoryAreasProtection/*))"!]
[!FOR "PROTECTED_AREA_IDX" = "1" TO "$PROTECTED_AREA_MAX"!]
[!WS "4"!]{[!"num:inttohex(FlashMemoryAreasProtection/*[number($PROTECTED_AREA_IDX)]/Start_Address,8)"!]U,[!WS "10"!][!"num:inttohex(FlashMemoryAreasProtection/*[number($PROTECTED_AREA_IDX)]/Length,5)"!]U,}, 
[!ENDFOR!]
};
[!ENDIF!]
