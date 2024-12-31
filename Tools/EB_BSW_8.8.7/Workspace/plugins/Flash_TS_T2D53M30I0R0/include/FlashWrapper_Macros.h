#ifndef FLASHWRAPPER_MACROS_H
#define FLASHWRAPPER_MACROS_H
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
/*%%   _____________________________   %%  \file FlashWrapper_Macros.h           */
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
/*********************/
/*Macros definitions*/
/*********************/
/*Macro which enables to disable the interrupt for critical section needed*/
#define FLW_START_CRITICAL_SECTION()                  BoardDisableInterrupts()

/*Macro which enables to enable the interrupt for critical section needed*/
#define FLW_END_CRITICAL_SECTION()                    BoardEnableInterrupts()

/*Macro which enables to define the typedef RAM function name*/
#define FLW_TYPEDEF_CB(FCTNAME)                       t##FCTNAME##Cb

/*Retrieve a flash section size*/
#define FLW_GET_SECTION_SIZE(TYPE)                    ((uint32)(((uint8*)(&__Flash_API_##TYPE##_SECTION_END_ADDR)) - ((uint8*)(&__Flash_API_##TYPE##_SECTION_START_ADDR)) + 1))

/*Retrieve the desired address of the desired memory*/
#define FLW_GET_SECTION_ADDR(TYPE,SIDE)               (uint32)((uint8*)(&__Flash_API_##TYPE##_SECTION_##SIDE##_ADDR))

/*Compute the ROM image function address according the ROM function address*/
#define FLW_COMPUTE_FCT_ADDR_IN_ROM(ROMFCT)           (&ROMFCT)

/*
*Compute the RAM image function address according the ROM function address
*Formula:
*<FctAddrInRAM> = __Flash_API_RAM_SECTION_START_ADDR + (<FctAddrInROM> - __Flash_API_ROM_SECTION_START_ADDR)
*Finally, we have to cast the computed address according the right function pointer type
*/
#define FLW_COMPUTE_FCT_ADDR_IN_RAM(ROMFCT)   (FLW_TYPEDEF_CB(ROMFCT))\
                                                ((uint32)(FLW_GET_SECTION_ADDR(RAM,START)) +\
                                                 ((uint32)(&(ROMFCT)) - (uint32)(FLW_GET_SECTION_ADDR(ROM,START))))
#endif

