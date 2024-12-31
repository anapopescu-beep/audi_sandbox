/*===============================================================================*/
/*                                                                               */
/*                               BOOT layers                                     */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                             FLASH callbacks                                   */
/*                                                                               */
/*===============================================================================*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file FLASH_Cbk.c                     */
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
/* Copyright 2017 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*===============================================================================*/


/*=============================== FILE INCLUSION ================================*/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Header Files: EB                                                            */
#include "EB_Prj.h"
/*                                                                               */

/*--------------------------------{FLASH_CustomGetPhysicalToLogicalAddress}-------------------------*/
eFlashStatus FLASH_CustomGetPhysicalToLogicalAddress(uint32 PhysicalAddress, uint32* LogicalAddress)
{
  eFlashStatus RetVal = FLASH_NO_ERROR;

  /*By default the LogicalAddress equal the PhysicalAddress*/
  *LogicalAddress = PhysicalAddress;

  /*Return the status*/
  return(RetVal);  
}
/*-------------------------------{end FLASH_CustomGetPhysicalToLogicalAddress}----------------------*/

