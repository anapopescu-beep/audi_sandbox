#ifndef FLASH_TYPES_H
#define FLASH_TYPES_H

/*
===============================================================================
                                                                               
                               BOOT layers                                     
                                                                               
 ----------------------------------------------------------------------------- 
                                                                               
                                 FLASH configuration                           
                                                                               
===============================================================================
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        
%%   _____________________________   %%  File: FLASH_Types.h
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

/*============================= PUBLIC DEFINITIONS ==============================*/
/*                                                                               */
/*===============================================================================*/
/* - Public Types                                                                */
/** \brief Define the use of COSMIC compiler*/  
#define COSMIC  0U
/** \brief Define the use of GHS compiler*/  
#define GHS     1U
/** \brief Define the use of IAR compiler*/  
#define IAR     2U
/** \brief Define the use of Other compiler*/  
#define Other   3U

/** \brief Define the compiler used*/ 
[!IF "General/ProjectCompiler = 'COSMIC'"!]
#define FLASH_COMPILER COSMIC
[!ELSEIF "General/ProjectCompiler = 'GHS'"!]
#define FLASH_COMPILER GHS
[!ELSEIF "General/ProjectCompiler = 'IAR'"!]
#define FLASH_COMPILER IAR
[!ELSE!]
[!/* ProjectCompiler field is "Other" */!]
#define FLASH_COMPILER Other
[!ENDIF!]

/** \brief Define how the pointers should be consider according the compiler*/ 
#if (FLASH_COMPILER == COSMIC)
    #define FLASH_FAR_POINTER *
    #define FLASH_FAR_ACCESS 
#elif (FLASH_COMPILER == GHS)
    #define FLASH_FAR_POINTER *
    #define FLASH_FAR_ACCESS 
#elif (FLASH_COMPILER == IAR)
    #define FLASH_FAR_POINTER *__far
    #define FLASH_FAR_ACCESS __far
#else
    #define FLASH_FAR_POINTER *
    #define FLASH_FAR_ACCESS 
#endif
[!VAR "SECTOR_MAX"="num:dectoint(count(FlsSector/*))"!]
[!VAR "FLS_SECTOR_NUMBER_TEMP"="1"!]
[!VAR "FLS_SECTOR_SIZE_TEMP"="num:inttohex(FlsSector/*[1]/Length)"!]
[!VAR "FLS_SECTOR_PROGRAMMABLE_TEMP"="text:tolower(FlsSector/*[1]/Programmable)"!]
[!FOR "SECTOR_IDX" = "2" TO "$SECTOR_MAX"!]
  [!IF "num:inttohex(FlsSector/*[number($SECTOR_IDX)]/Length) != $FLS_SECTOR_SIZE_TEMP or text:tolower(FlsSector/*[number($SECTOR_IDX)]/Programmable) != $FLS_SECTOR_PROGRAMMABLE_TEMP"!]
    [!VAR "FLS_SECTOR_NUMBER_TEMP" = "$FLS_SECTOR_NUMBER_TEMP + 1"!]
    [!VAR "FLS_SECTOR_SIZE_TEMP"="num:inttohex(FlsSector/*[number($SECTOR_IDX)]/Length)"!]
    [!VAR "FLS_SECTOR_PROGRAMMABLE_TEMP"="text:tolower(FlsSector/*[number($SECTOR_IDX)]/Programmable)"!]
  [!ENDIF!]
[!ENDFOR!]
[!IF "General/UseSectorTab = 'true'"!]
/** \brief Define how many sectors are configured*/ 
#define FLASH_MAX_SECTOR        [!"num:dectoint(count(FlsSector/*))"!]U
 /** \brief Define the size of the sector info tab*/
#define FLASH_INFO_SIZE         [!"num:integer($FLS_SECTOR_NUMBER_TEMP)"!]U
[!ELSE!]
/** \brief Define the base adress of the flash memory*/
#define FLASH_BASE_ADDR         [!"num:inttohex(General/Flash_Base_Addr)"!]U
/** \brief Define the size of every memory sectors*/
#define FLASH_SECTOR_SIZE       [!"num:inttohex(General/Flash_Sector_Size)"!]U
/** \brief Define the number of memory sectors configured*/
#define FLASH_MAX_SECTOR        [!"num:dectoint(General/Flash_Max_Sector)"!]U
/** \brief Define the size of the sector info tab*/
#define FLASH_INFO_SIZE        1U
[!ENDIF!]

[!IF "General/ActivateSecurityCheck = 'true'"!]
/** \brief Define how many sectors are configured*/ 
#define FLASH_MAX_PROTECTED_AREA_NB        [!"num:dectoint(count(FlashMemoryAreasProtection/*))"!]U
[!ENDIF!]
/* Different flash status */
/** \brief FLASH functions status is OK*/
#define FLASH_NO_ERROR          0x01U
/** \brief The flash memory cannot be accessed correctly*/
#define FLASH_ACCESS_ERROR      0x02U
/** \brief The flash memory cannot be accessed correctly due to protection error*/
#define FLASH_PROT_ERROR        0x03U
/** \brief The flash memory is blank so the data have not been written correctly*/
#define FLASH_BLANKCHEK_ERROR   0x04U
/** \brief The flash memory is busy*/
#define FLASH_BUSY              0x05U
/** \brief The function is not supported*/
#define FLASH_FUNC_NOT_SUPPORTED 0x06U
/** \brief Error on the initialisation*/
#define FLASH_INIT_ERROR         0x07U
/** \brief Sector error access*/
#define FLASH_SECTOR_ERROR       0x08U
/** \brief Page error access*/
#define FLASH_PAGE_ERROR         0x09U


#define FLASH_PROCESS_WRITE     0x01U
#define FLASH_PROCESS_ERASE     0x02U

#define FLASH_MODE_SLICER_SYNC 1U
#define FLASH_MODE_BLOCKER_SYNC 2U
[!IF "General/Flash_Mode = 'Slicer_Sync'"!]
#define FLASH_MODE  FLASH_MODE_SLICER_SYNC
[!ELSEIF "General/Flash_Mode = 'Blocker_Sync'"!]
#define FLASH_MODE  FLASH_MODE_BLOCKER_SYNC
[!ENDIF!]

/** \brief Status of flash operations of data flash type */
typedef u8 tFlashStatus;

/** \brief Define the data flash type */
typedef u32 tFlashData;

/** \brief Define the flash address type*/
#if (FLASH_COMPILER == COSMIC)
    typedef volatile const @far @gpage tFlashData * tFlashAddress;
#elif (FLASH_COMPILER == GHS)
    typedef u32 tFlashAddress;
#else
    typedef u32 tFlashAddress;
#endif

/** \brief FLASH layer FALSE define used for boolean actions in the layer*/
#define FLASH_FALSE   0U
/** \brief FLASH layer FALSE define used for boolean actions in the layer*/
#define FLASH_TRUE    1U
/** \brief Boolean for FLASH layer*/
typedef u8 tFlashBoolean;

/** \brief Structure of flash sector containing adress, length and programmability information*/
typedef struct 
{
    u32                  Start_Address; /* Start Address of the sector */
    u32                  Length;        /* Length of the sector */
    u16                  Number;        /* Number of consecutive sector with the same size */
    u8                   Programmable;  /* Sector reprogramable or not */ /* Not use for now TO BE keep ???? */
}tFlsInfo;


[!IF "General/ActivateSecurityCheck = 'true'"!]
/** \brief Structure of protected memory areas containing adress and length information*/
typedef struct 
{
    u32                  Start_Address; /* Start Address of the sector */
    u32                  Length;        /* Length of the sector */
}tFlashActivateSecurityCheck;
[!ENDIF!]

/** \brief Define the size of the temporary write buffer*/


#define FLASH_WRITE_BUFFER   (FLASH_PAGES_SIZE_BYTE)

[!IF "General/DifferentProgramAndDataFlashWritePage = 'true'"!]
/** \brief Define if different page sizes shall be managed by the Flash driver for Program and Data Flash*/
#define FLASH_MANAGE_DIFF_PAGE_SIZES
[!ENDIF!]
[!IF "General/CashedAddressConversion = 'true'"!]
/** \brief Define if cashed address conversion shall be managed by the Flash driver */
#define FLASH_MANAGE_CASHED_ADDRESS
[!ENDIF!]
[!IF "General/ActivateSecurityCheck = 'true'"!]
/** \brief Define if memory area protection shall be managed by the Flash driver */
#define FLASH_MANAGE_SECURITY_CHECK
[!ENDIF!]

[!IF "General/ActivateSkipPage = 'true'"!]
/** \brief Define skip page flag */
#define FLASH_MANAGE_SKIP_PAGE
[!ENDIF!]
#endif      /* FLASH_TYPES_H */
