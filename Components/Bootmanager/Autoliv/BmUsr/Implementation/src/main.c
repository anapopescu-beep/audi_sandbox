/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

 *******************************************************************************
C-File Template Version:
 ******************************************************************************/
/*
$Revision: 1.3 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Bootmanager/Autoliv/BmUsr/Implementation/src/project.pj $
*/
/*!****************************************************************************

@details
   Bootmanager module for - checking the presence and the validity of the bootloader updater component
                          - checking the presence and the validity of the application component
 *****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
 *****************************************************************************/
#include <Platform_Types.h>
#include <common.h>
/******************************************************************************
MODULE DEFINES
 *****************************************************************************/
/**
 *\brief
 *       Bootloader flag address.
 *
 */
#define BTL_ADDR_FLAG                ((uint32) 0x1FFF0u  )
/**
 *\brief
 *      Bootloader Updater address.
 *
 */
#define APP_START_ADDR              ((uint32) 0x00020004)
/**
 *\brief
 *      Bootloader address.
 *
 */
#define BOOTLOADER_ADDR             ((uint32) 0x00001004)

#define PATTERN_SIZE                ((uint8) 16u)

/******************************************************************************
MODULE TYPES
 *****************************************************************************/
/**
 *\brief
 *       Type definition of void address.
 */
typedef void (*ptAPPL_START_ADDR)(void);
/**
 *\brief
 *       16-size array used for size of pattern array.
 *
 */


/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
 *****************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
 *****************************************************************************/
/**
 *\brief
 *       Variable used for the address of the bootloader updater to jump to.
 *
 */
LOCAL ptAPPL_START_ADDR pAPPL_START_ADDR = KPF_NULL;
/**
 *\brief
 *       Variable used for the address of the bootloader to jump to.
 *
 */
LOCAL ptAPPL_START_ADDR pBTL_START_ADDR = KPF_NULL;
/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
 ******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
 ******************************************************************************/
/**
 *\brief
 *      Bootloader pattern used to check bootloader validity.
 *
 */
LOCAL const uint8 kaucPattern[PATTERN_SIZE] = {(uint8)0xFF, (uint8)0xFF, (uint8)0xFF, (uint8)0xFF, (uint8)0xFF, (uint8)0xFF, (uint8)0xFF, (uint8)0xFF,
      (uint8)0x50, (uint8)0x52, (uint8)0x4F, (uint8)0x47, (uint8)0x52, (uint8)0x41, (uint8)0x4d, (uint8)0x4d};

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
 ******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
 ******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
 ******************************************************************************/

/******************************************************************************
DEFINITION OF APIs
 ******************************************************************************/

/*!****************************************************************************

 ******************************************************************************/

/**
 *\brief
 *      Function used to jump to bootloader updater program or to bootloader.
 *\param
 *      None.
 *\return
 *      None.
 *\dynamiaspectcaller
 *      None.
 *\dynamicaspectdescription
 *      None.
 *\constrains
 *      None.
 */
int main(void)
{
   uint8  u8Index = 0u;
   uint8* const pucAddr = (uint8*)BTL_ADDR_FLAG;
   uint32 u32AppAddress;

   /* Check if the pattern is found */
   for (u8Index = 0u; u8Index < PATTERN_SIZE; u8Index++)
   {
      /* If the pattern isn't found jump to bootloader updater */
      if ((pucAddr[u8Index]) != kaucPattern[u8Index])
      {
         /* Jump to bootloader updater */
         u32AppAddress = *(uint32*)APP_START_ADDR;

         /* Get the address of the bootloader updater to jump in */
         pAPPL_START_ADDR = (ptAPPL_START_ADDR)(u32AppAddress);

         /* Jump in bootloader updater */
         pAPPL_START_ADDR();

      }
      else
      {
      }
   }

   /* Jump to bootloader*/
   u32AppAddress = *(uint32*)BOOTLOADER_ADDR;

   /* Get the address of the bootloader to jump in */
   pBTL_START_ADDR = (ptAPPL_START_ADDR)(u32AppAddress);

   /* Jump to bootloader */
   pBTL_START_ADDR();

   while (1)
   {
   }

   return 0;
}

/******************************************************************************
End Of File
 *****************************************************************************/
