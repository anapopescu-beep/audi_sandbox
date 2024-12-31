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


#define FLASH_COMPILER Other

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
/** \brief Define how many sectors are configured*/ 
#define FLASH_MAX_SECTOR        128U
 /** \brief Define the size of the sector info tab*/
#define FLASH_INFO_SIZE         1U

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

#define FLASH_MODE  FLASH_MODE_BLOCKER_SYNC

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



/** \brief Define the size of the temporary write buffer*/


#define FLASH_WRITE_BUFFER   (FLASH_PAGES_SIZE_BYTE)


#endif      /* FLASH_TYPES_H */
