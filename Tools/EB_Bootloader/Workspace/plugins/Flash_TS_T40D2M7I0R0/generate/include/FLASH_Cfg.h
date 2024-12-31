#ifndef FLASH_CFG_H
#define FLASH_CFG_H

/*
===============================================================================
                                                                               
                               BOOT layers                                     
                                                                               
 ----------------------------------------------------------------------------- 
                                                                               
                                 FLASH configuration                           
                                                                               
===============================================================================
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        
%%   _____________________________   %%  File: FLASH_Cfg.h
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

/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/*===============================================================================*/
/* - Configuration Constants                                                     */

/*===============================================================================*/
/* - Configuration Variable or Register Aliases                                  */

/*===============================================================================*/
/* - Public Constants                                                            */

/** \brief Define the size in byte of a page in the flash memory*/ 
#define FLASH_PAGES_SIZE_BYTE  [!"num:dectoint(General/FLASH_Page_Size)"!]U

/* This Macro only used in Slicer mode */
#define FLASH_NUMBER_OF_PAGE_PER_SLICER    [!"General/FLASH_Number_Of_Page_Per_Slicer"!]U


/** \brief Define the size in word byte of a page in the flash memory*/ 
#define FLASH_PAGES_SIZE_WORD  (FLASH_PAGES_SIZE_BYTE / 4U)

/** \brief Define the the erased state of the Flash cell*/ 
#define FLASH_ERASED_BYTE_VALUE    0xFFU

extern const tFlsInfo Fls_Info[FLASH_INFO_SIZE];

[!VAR "currentConfiguredSize" = "0"!][!//
[!LOOP "FlsSector/*"!][!//
  [!VAR "sectorSize" = "node:value(./Length)"!][!//
  [!VAR "currentConfiguredSize" = "$currentConfiguredSize + ($sectorSize)"!][!//
[!ENDLOOP!][!//
[!/* FIXME: The sector list (Autosar 3.1) items defines the current configured flash size
            but we use FLS_TOTAL_SIZE in the driver configuration structure
            for DET API parameter checking of TargetAddress and Length.
            replaced:
              #define FLS_TOTAL_SIZE       [!"num:i(FlsGeneral/FlsTotalSize)"!]
*/!]
/** \brief Define the total size of the flash memory*/ 
#define FLASH_TOTAL_SIZE       [!"num:inttohex($currentConfiguredSize)"!]

[!IF "General/ActivateSecurityCheck = 'true'"!]
/** \brief Array of structure containing all memory area to be protected against erase and write*/ 
extern const tFlashActivateSecurityCheck astFlashMemoryAreas[FLASH_MAX_PROTECTED_AREA_NB];
[!ENDIF!]

[!IF "General/Watchdog_care = 'true'"!]
/** \brief Flash driver calls APIs to deactivate/activate the Watchdog during memory operations */
#define FLASH_WATCHDOG_CARE     FLASH_TRUE
[!ELSE!]
/** \brief Flash driver does not call APIs to deactivate/activate the Watchdog during memory operations */
#define FLASH_WATCHDOG_CARE     FLASH_FALSE
[!ENDIF!]

[!IF "General/Operation_Callback != 'NULL_CALLBACK'"!]
#define FLASH_OPERATION_CBK   [!"General/Operation_Callback"!]
[!ELSE!]
[!ENDIF!]

/*===============================================================================*/
/* - Public Macros                                                               */

/*                                                                               */
/*===============================================================================*/


#endif      /* FLASH_CFG_H */
