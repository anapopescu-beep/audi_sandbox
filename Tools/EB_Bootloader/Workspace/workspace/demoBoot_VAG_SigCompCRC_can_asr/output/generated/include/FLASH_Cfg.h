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
#define FLASH_PAGES_SIZE_BYTE  8U

/* This Macro only used in Slicer mode */
#define FLASH_NUMBER_OF_PAGE_PER_SLICER    1U


/** \brief Define the size in word byte of a page in the flash memory*/ 
#define FLASH_PAGES_SIZE_WORD  (FLASH_PAGES_SIZE_BYTE / 4U)

/** \brief Define the the erased state of the Flash cell*/ 
#define FLASH_ERASED_BYTE_VALUE    0xFFU

extern const tFlsInfo Fls_Info[FLASH_INFO_SIZE];

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
/** \brief Define the total size of the flash memory*/ 
#define FLASH_TOTAL_SIZE       0x80000




/** \brief Flash driver does not call APIs to deactivate/activate the Watchdog during memory operations */
#define FLASH_WATCHDOG_CARE     FLASH_FALSE





/*===============================================================================*/
/* - Public Macros                                                               */

/*                                                                               */
/*===============================================================================*/


#endif      /* FLASH_CFG_H */
