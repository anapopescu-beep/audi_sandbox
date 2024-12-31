#ifndef FLSLOADERWRAPPER_H
#define FLSLOADERWRAPPER_H
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
/*%%   _____________________________   %%  \file FlsLoaderWrapper.h              */
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
#ifdef FLW_CUSTOM_WRAPPER_USED
#ifdef NCS_UNITARY_TEST
#include "appl_Pub.h"
#endif
/*Typedef definitions*/
/* Different FlsLoaderWrapper status */
typedef enum
{
  FLASH_LOADER_WRAPPER_NO_ERROR=0x00U,
  FLASH_LOADER_WRAPPER_INIT_ERROR,
  FLASH_LOADER_WRAPPER_ERASE_ERROR,
  FLASH_LOADER_WRAPPER_WRITE_ERROR,
  FLASH_LOADER_WRAPPER_READ_ERROR,
} eFlsLoaderWrapperStatus;


extern FLW_INIT_ROUTINE_RETURN FlsLoaderWrapper_Init FLW_INIT_ROUTINE_SIGNATURE;
extern FLW_ERASE_ROUTINE_RETURN FlsLoaderWrapper_Erase FLW_ERASE_ROUTINE_SIGNATURE;
extern FLW_WRITE_ROUTINE_RETURN FlsLoaderWrapper_Write FLW_WRITE_ROUTINE_SIGNATURE;
extern FLW_READ_ROUTINE_RETURN FlsLoader_Read FLW_READ_ROUTINE_SIGNATURE;

#endif /*#ifndef FLW_CUSTOM_WRAPPER_USE*/
#endif /*#ifndef FLSLOADERWRAPPER_H*/

