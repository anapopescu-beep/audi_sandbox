#ifndef FLASH_CFG_H
#define FLASH_CFG_H

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
/*%%   _____________________________   %%  \file FLASH_Cfg.h                     */
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
/*===============================================================================*/

/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/*===============================================================================*/
/* - Configuration Constants                                                     */

/*===============================================================================*/
/* - Configuration Variable or Register Aliases                                  */

/*===============================================================================*/
/* - Public Constants                                                            */
[!AUTOSPACING!]
#define FLASH_PAGE_SIZE                   [!"Write/Configurations/FlashPageSize"!]U
#define FLASH_PAGE_PADDING_VALUE          [!"Write/Configurations/FlashPagePaddingValue"!]U
#define FLASH_SECTORS_TABLE_NB_ELEMENTS   [!"num:dectoint(count(FlashSectors/FlashSectors/*))"!]
[!IF "Erase/Configurations/EraseMode = 'Synchrone'"!]
#define FLASH_ERASE_MODE   FLASH_SYNCHRONE_MODE
[!ELSE!]
#define FLASH_ERASE_MODE   FLASH_ASYNCHRONE_MODE
[!ENDIF!]

[!IF "Write/Configurations/WriteMode = 'Synchrone'"!]
#define FLASH_WRITE_MODE   FLASH_SYNCHRONE_MODE
[!ELSE!]
#define FLASH_WRITE_MODE   FLASH_ASYNCHRONE_MODE
[!ENDIF!]

[!IF "Read/Configurations/ReadMode = 'Synchrone'"!]
#define FLASH_READ_MODE    FLASH_SYNCHRONE_MODE
[!ELSE!]
#define FLASH_READ_MODE    FLASH_ASYNCHRONE_MODE
[!ENDIF!]




/*===============================================================================*/
/* - Public Macros                                                               */

/*                                                                               */
/*===============================================================================*/

#endif      /* FLASH_CFG_H */
