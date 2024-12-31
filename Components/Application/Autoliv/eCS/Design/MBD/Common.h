/*************************************************************************

  AUTOLIV Electronic document.
  -------------------------------------

  DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

               COMPONENT COMMON.GEN
               ----------------

 This file must be included in every component which includes macros,
 types and functions defined by the component COMMON.GEN.

**************************************************************************

 Documentation reference :

 ------------------------------------------------------------------------

 Overview of the component :
    This component contains general definitions of types and macros
    which can be needed by the developper.

 ------------------------------------------------------------------------

 Evolution of the component COMMON.GEN
  (initials, date, modification)

   created by  :  SLY  2012/01/11

   modified by :

         $Log: Common.h  $
         Revision 1.1 2023/05/02 06:49:25CEST Victor Popina (victor.popina) 
         Initial revision
         Member added to project e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/eCS/Design/MBD/project.pj
         Revision 1.1 2021/09/03 15:51:31EEST Pierre-Olivier Pilot (pierre-olivier.pilot) 
         Initial revision
         Member added to project e:/MKSProjects/SBE/Innovation/ECS/Phase_01/Components/Application/Autoliv/TL_Lib/Implementation/inc/project.pj
         Revision 1.2 2021/01/21 14:41:56CET Bayram Ezzayet (bayram.ezzayet) 
         Change common.h place in order to build correctly with buildenv
         Revision 1.2 2021/01/21 11:28:46CET Bayram Ezzayet (bayram.ezzayet) 
         Uncomment functions while NVP parameters are configured.
         Revision 1.1 2020/09/23 13:50:43CEST Gaetan Lievre (gaetan.lievre) 
         Initial revision
         Member added to project e:/MKSProjects/AEM/Frame_Platforms/S32K144/Phase_01/View_Development/Components/Application/Supplier/Tresos_Configuration_8.5.1/Workspace/Tresos_UserFiles/Stub/inc/project.pj
         Revision 1.1 2020/09/23 13:50:43CEST Gaetan Lievre (gaetan.lievre) 
         Initial revision
         Member added to project e:/MKSProjects/DEV_KIT/S32K/Phase_01/Components/Application/Supplier/Tresos_Configuration_8.5.1/Workspace/Tresos_UserFiles/Stub/inc/project.pj
         Revision 1.1 2019/06/25 16:30:32CEST Nicolas Bianchi (nicolas.bianchi) 
         Initial revision
         Member added to project e:/MKSProjects/DEV_KIT/S32K/Phase_01/Tools/Tresos_Configuration_8.5.1/Workspace/Tresos_UserFiles/Stub/inc/project.pj
         Revision 1.2 2017/03/27 16:40:22EEST Charlene Dibourg (charlene.dibourg) 
         Update Common.h with TL_Lib content
         Revision 1.2 2016/05/18 08:22:07CEST Maxime Bourdon (mbourdon)
         Add KU32_ONE define for EOL
         Revision 1.1 2015/10/13 15:53:02CEST Cedric Sauvage (csauvage)
         Initial revision
         Member added to project e:/MKSProjects/err_generic/Exploration/AUTOSAR/RTE_Benchmark/ETAS/Development_View/Source/Application/OPT_GENERIC/inc/project.pj
         Revision 1.9 2015/09/24 11:02:40CEST Pierre-Olivier Pilot (ppilot)
         QAC analysis
         Revision 1.8 2015/08/19 14:32:17CEST Sabine Flechelle (sflechelle)
         Issue 215817 - Motor current in block 5
         Extract correct low bytes to send motor current.
         Rename common macro.
         Revision 1.7 2015/03/12 15:19:19CET Cedric Sauvage (csauvage)
         Implementation of measurement block 12 in CIL + QAC correction
         Revision 1.6 2014/12/10 16:58:46CET Sebastien Claveau (sclaveau)
         Clean common.gen/h and update macro names
         Revision 1.5 2014/10/29 16:09:06CET Sabine Flechelle (sflechelle)
         Issue_167292 - Archi updates for new MMG
         New macros for uint32
         Revision 1.4 2014/06/12 16:58:31CEST Francois.Gilbert (fgilbert)
         New macros for CIL measurement frames
         Revision 1.3 2014/05/05 16:36:13CEST Cedric Sauvage (csauvage)
         Integration of E2P stack
         Revision 1.2 2014/04/15 10:00:41CEST Sabine Flechelle (sflechelle)
         Issue_142496 - MMG and BFE needs
         Add some common define needed by MMG
         Revision 1.1 2014/01/22 07:23:54CET Cedric Sauvage (csauvage)
         Initial revision
         Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/OPT_GENERIC/inc/project.pj


**************************************************************************/
/****** definition for mono-inclusion ******/
#ifndef COMMON_GEN_H
#define COMMON_GEN_H

#include "common.h"
#include "Config.h"

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!            Remaining specific use cases  (to be cleaned)             !!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
#define KB_ZERO                       ((boolean) 0)
#define KU8_MASK_BITS_2_7             ((uint8) 0xFC)

/*************************************************************************
**                  Code's declarations scope macros                    **
**************************************************************************/
#define LOCAL                         static
#define EXPORTED

/*************************************************************************
**                        Build template macros                         **
**   (shall not be modified without updating build tools accordingly)   **
**************************************************************************/

/*************************************************************************
**                        Addressing space macros                       **
**   (shall not be modified without considering application linkage)    **
**************************************************************************/
#ifdef HIDE_IAR_SPECIFIC
#ifndef TESSY
#define __AT =
#else
__AT
#endif
#define __no_init
#define __root
#else
#define __AT        @
#endif
/**************************************************************************
**          Types limits and other remarkables values                    **
**************************************************************************/

#define KU8_MAX_SOLENOID_NB                 ((uint8)  6)
/*************************** Boolean constants ***************************/
#ifndef B_TRUE
#define B_TRUE                        ((boolean)0xAA)
#endif

#ifndef B_FALSE
#define B_FALSE                       ((boolean)0x55)
#endif

#ifndef KU8_TRUE
#define KU8_TRUE                      ((uint8)0xAA)
#endif

#ifndef KU8_FALSE
#define KU8_FALSE                     ((uint8)0x55)
#endif

#ifndef KB_TRUE
#define KB_TRUE                       ((boolean) 0x01)
#endif

#ifndef KB_FALSE
#define KB_FALSE                      ((boolean) 0x00)
#endif

/*********************** Unsigned 8 bits constants ***********************/
#define KU8_MIN                              ((uint8)  0)
#define KU8_MAX                              ((uint8)  255)

#define KU8_ZERO                             ((uint8)  0x00)
#define KU8_ONE                              ((uint8)  0x01)
#define KU8_TWO                              ((uint8)  0x02)
#define KU8_THREE                            ((uint8)  0x03)
#define KU8_FOUR                             ((uint8)  0x04)
#define KU8_FIVE                             ((uint8)  0x05)
#define KU8_SIX                              ((uint8)  0x06)
#define KU8_SEVEN                            ((uint8)  0x07)
#define KU8_EIGHT                            ((uint8)  0x08)
#define KU8_NINE                             ((uint8)  0x09)
#define KU8_TEN                              ((uint8)  0x0A)
#define KU8_ELEVEN                           ((uint8)  0x0B)
#define KU8_TWELVE                           ((uint8)  0x0C)
#define KU8_THIRTEEN                         ((uint8)  0x0D)
#define KU8_FOURTEEN                         ((uint8)  0x0E)
#define KU8_FIFTEEN                          ((uint8)  0x0F)
#define KU8_SIXTEEN                          ((uint8)  0x10)
#define KU8_SEVENTEEN                        ((uint8)  0x11)
#define KU8_EIGHTEEN                         ((uint8)  0x12)
#define KU8_NINETEEN                         ((uint8)  0x13)
#define KU8_TWENTY                           ((uint8)  0x14)
#define KU8_TWENTYONE                        ((uint8)  0x15)
#define KU8_TWENTYTWO                        ((uint8)  0x16)
#define KU8_TWENTYTHREE                      ((uint8)  0x17)
#define KU8_TWENTYFOUR                       ((uint8)  0x18)
#define KU8_TWENTYFIVE                       ((uint8)  0x19)
#define KU8_TWENTYSIX                        ((uint8)  0x1A)
#define KU8_TWENTYEIGHT                      ((uint8)  0x1C)
#define KU8_THIRTYTWO                        ((uint8)  0x20)
#define KU8_THIRTYSIX                        ((uint8)  0x24)
#define KU8_FOURTYSIX                        ((uint8)  0x2E)
#define KU8_SIXTY                            ((uint8)  0x3C)
#define KU8_SIXTYFOUR                        ((uint8)  0x40)
#define KU8_NINETY                           ((uint8)  0x5A)
#define KU8_ONE_HUNDRED                      ((uint8)  100)
#define KU8_ONE_HUNDRED_AND_TWENTYEIGHT      ((uint8)  0x80)
#define KU8_BIT_7_ZERO                       ((uint8)  0x7F)
#define KU8_BIT_6_ZERO                       ((uint8)  0xBF)
#define KU8_BIT_5_ZERO                       ((uint8)  0xDF)
#define KU8_BIT_4_ZERO                       ((uint8)  0xEF)
#define KU8_BIT_3_ZERO                       ((uint8)  0xF7)
#define KU8_BIT_2_ZERO                       ((uint8)  0xFB)
#define KU8_BIT_1_ZERO                       ((uint8)  0xFD)
#define KU8_BIT_0_ZERO                       ((uint8)  0xFE)

/**
 *\brief
 *      Indicate the Solenoid number 1.
 */
#define KU8_SOLENOID_1                      ((uint8)  0)
/**
 *\brief
 *      Indicate the Solenoid number 2.
 */
#define KU8_SOLENOID_2                      ((uint8)  1)
/**
 *\brief
 *      Indicate the Solenoid number 3.
 */
#define KU8_SOLENOID_3                      ((uint8)  2)
/**
 *\brief
 *      Indicate the Solenoid number 4.
 */
#define KU8_SOLENOID_4                      ((uint8)  3)
/**
 *\brief
 *      Indicate the Solenoid number 5.
 */
#define KU8_SOLENOID_5                      ((uint8)  4)
/**
 *\brief
 *      Indicate the Solenoid number 6.
 */
#define KU8_SOLENOID_6                      ((uint8)  5)

/************************ Signed 8 bits constants ************************/
#define KS8_MIN                              ((sint8)  (-127))
#define KS8_MAX                              ((uint8)  127)

#define KS8_ZERO                             ((sint8)  0x00)

/*********************** Unsigned 16 bits constants **********************/
#define KU16_MIN                             ((uint16) 0)
#define KU16_MAX                             ((uint16) 65535)

#define KU16_MAX_U8                          ((uint16) 0xFF)

#define KU16_ZERO                            ((uint16) 0)
#define KU16_ONE                             ((uint16) 0x0001)
#define KU16_TWO                             ((uint16) 0x0002)
#define KU16_THREE                           ((uint16) 0x0003)
#define KU16_FOUR                            ((uint16) 0x0004)
#define KU16_EIGHT                           ((uint16) 0x0008)
#define KU16_TWO_HUNDRED_AND_FIFTYSIX        ((uint16) 0x100)

/************************ Signed 16 bits constants ***********************/
#define KS16_MIN                             ((sint16) (-32767))
#define KS16_MAX                             ((sint16) 32767)

#define KS16_MAX_S8                          ((sint16) 127)        /* 0x007F */
#define KS16_MIN_S8                          ((sint16) -128)       /* 0xFF80 */

#define KS16_ZERO                            ((sint16) 0)

/*********************** Unsigned 32 bits constants **********************/
#define KU32_MIN                             ((uint32) 0)
#define KU32_MAX                             ((uint32) 4294967295uL)

#define KU32_ZERO                            ((uint32) 0)
#define KU32_ONE                             ((uint32) 0x00000001)
#define KU32_TWO                             ((uint32) 0x00000002)
#define KU32_EIGHT                           ((uint32) 0x00000008)
#define KU32_TEN                             ((uint32) 0x0000000A)
#define KU32_SIXTEEN                         ((uint32) 0x00000010)
#define KU32_THIRTYTWO                       ((uint32) 0x00000020)
#define KU32_SIXTYFOUR                       ((uint32) 0x00000040)
#define KU32_ONE_HUNDRED_AND_TWENTYEIGHT     ((uint32) 0x00000080)
#define KU32_TWO_HUNDRED_AND_FIFTYSIX        ((uint32) 0x00000100)

#define KU32_MAX_U8                          ((uint32) 0x000000FF)

#define KU32_MAX_U16                         ((uint32) 0xFFFFuL)

/************************ Signed 32 bits constants ***********************/
#define KS32_MIN                             ((sint32) (-2147483647))
#define KS32_MAX                             ((sint32) 2147483647)

#define KS32_MAX_U8                          ((sint32) 0xFF)

#define KS32_MAX_U16                         ((sint32) 0xFFFF)

#define KS32_MIN_S16                         ((sint32) -32768)
#define KS32_MAX_S16                         ((sint32) 32767)

#define KS32_ZERO                            ((sint32) 0)
#define KS32_TWO                             ((sint32) 2)

/************************ Unsigned 64 bits constants ***********************/
#define KU64_MAX                             ((uint64) 0xFFFFFFFFFFFFFFFF)

#define KU64_ZERO                            ((uint64) 0)

/*************************** pointers constants **************************/
#define KPU8_NULL                            ((uint8*) 0)
#define KPF_NULL                             ((void *) 0)

/**************************************************************************
**          Frequent bit masks and bit-field manipulation macros         **
**************************************************************************/

/************************* Unsigned 8 bits masks *************************/
#define KU8_MASK_HALF_BYTE_LOW               ((uint8) 0x0F)
#define KU8_MASK_HALF_BYTE_HIGH              ((uint8) 0xF0)

#define KU8_MASK_BIT_0                       ((uint8) 0x01)
#define KU8_MASK_BIT_1                       ((uint8) 0x02)
#define KU8_MASK_BIT_2                       ((uint8) 0x04)
#define KU8_MASK_BIT_3                       ((uint8) 0x08)
#define KU8_MASK_BIT_4                       ((uint8) 0x10)
#define KU8_MASK_BIT_5                       ((uint8) 0x20)
#define KU8_MASK_BIT_6                       ((uint8) 0x40)
#define KU8_MASK_BIT_7                       ((uint8) 0x80)

/************************ Unsigned 16 bits masks *************************/

#define KU16_MASK_BYTE_LOW                   ((uint16) 0x00FF)
#define KU16_MASK_BYTE_HIGH                  ((uint16) 0xFF00)

#define KU16_MASK_BIT_0                      ((uint16) 0x0001)
#define KU16_MASK_BIT_1                      ((uint16) 0x0002)
#define KU16_MASK_BIT_2                      ((uint16) 0x0004)
#define KU16_MASK_BIT_3                      ((uint16) 0x0008)
#define KU16_MASK_BIT_4                      ((uint16) 0x0010)
#define KU16_MASK_BIT_5                      ((uint16) 0x0020)
#define KU16_MASK_BIT_6                      ((uint16) 0x0040)
#define KU16_MASK_BIT_7                      ((uint16) 0x0080)
#define KU16_MASK_BIT_8                      ((uint16) 0x0100)
#define KU16_MASK_BIT_9                      ((uint16) 0x0200)
#define KU16_MASK_BIT_10                     ((uint16) 0x0400)
#define KU16_MASK_BIT_11                     ((uint16) 0x0800)
#define KU16_MASK_BIT_12                     ((uint16) 0x1000)
#define KU16_MASK_BIT_13                     ((uint16) 0x2000)
#define KU16_MASK_BIT_14                     ((uint16) 0x4000)
#define KU16_MASK_BIT_15                     ((uint16) 0x8000)

/************************ Unsigned 32 bits masks *************************/

#define KU32_MASK_WORD_LOW                   ((uint32) 0x0000FFFFuL)
#define KU32_MASK_WORD_HIGH                  ((uint32) 0xFFFF0000uL)

#define KU32_MASK_BYTE_LOW                   ((uint32) 0x000000FFuL)
#define KU32_MASK_BYTE_LOW_MIDDLE            ((uint32) 0x0000FF00uL)
#define KU32_MASK_BYTE_HIGH_MIDDLE           ((uint32) 0x00FF0000uL)
#define KU32_MASK_BYTE_HIGH                  ((uint32) 0xFF000000uL)

#define KU32_MASK_BIT_0                      ((uint32) 0x01uL)
#define KU32_MASK_BIT_1                      ((uint32) 0x02uL)
#define KU32_MASK_BIT_2                      ((uint32) 0x04uL)
#define KU32_MASK_BIT_3                      ((uint32) 0x08uL)
#define KU32_MASK_BIT_4                      ((uint32) 0x10uL)
#define KU32_MASK_BIT_5                      ((uint32) 0x20uL)
#define KU32_MASK_BIT_6                      ((uint32) 0x40uL)
#define KU32_MASK_BIT_7                      ((uint32) 0x80uL)
#define KU32_MASK_BIT_8                      ((uint32) 0x100uL)
#define KU32_MASK_BIT_9                      ((uint32) 0x200uL)
#define KU32_MASK_BIT_10                     ((uint32) 0x400uL)
#define KU32_MASK_BIT_11                     ((uint32) 0x800uL)
#define KU32_MASK_BIT_12                     ((uint32) 0x1000uL)
#define KU32_MASK_BIT_13                     ((uint32) 0x2000uL)
#define KU32_MASK_BIT_14                     ((uint32) 0x4000uL)
#define KU32_MASK_BIT_15                     ((uint32) 0x8000uL)
#define KU32_MASK_BIT_16                     ((uint32) 0x10000uL)
#define KU32_MASK_BIT_17                     ((uint32) 0x20000uL)
#define KU32_MASK_BIT_18                     ((uint32) 0x40000uL)
#define KU32_MASK_BIT_19                     ((uint32) 0x80000uL)
#define KU32_MASK_BIT_20                     ((uint32) 0x100000uL)
#define KU32_MASK_BIT_21                     ((uint32) 0x200000uL)
#define KU32_MASK_BIT_22                     ((uint32) 0x400000uL)
#define KU32_MASK_BIT_23                     ((uint32) 0x800000uL)
#define KU32_MASK_BIT_24                     ((uint32) 0x1000000uL)
#define KU32_MASK_BIT_25                     ((uint32) 0x2000000uL)
#define KU32_MASK_BIT_26                     ((uint32) 0x4000000uL)
#define KU32_MASK_BIT_27                     ((uint32) 0x8000000uL)
#define KU32_MASK_BIT_28                     ((uint32) 0x10000000uL)
#define KU32_MASK_BIT_29                     ((uint32) 0x20000000uL)
#define KU32_MASK_BIT_30                     ((uint32) 0x40000000uL)
#define KU32_MASK_BIT_31                     ((uint32) 0x80000000uL)

/****************************** Bit positions ****************************/

#define KU8_BIT_0                            ((uint8) 0)
#define KU8_BIT_1                            ((uint8) 1)
#define KU8_BIT_2                            ((uint8) 2)
#define KU8_BIT_3                            ((uint8) 3)
#define KU8_BIT_4                            ((uint8) 4)
#define KU8_BIT_5                            ((uint8) 5)
#define KU8_BIT_6                            ((uint8) 6)
#define KU8_BIT_7                            ((uint8) 7)
#define KU8_BIT_8                            ((uint8) 8)
#define KU8_BIT_9                            ((uint8) 9)
#define KU8_BIT_10                           ((uint8) 10)
#define KU8_BIT_11                           ((uint8) 11)
#define KU8_BIT_12                           ((uint8) 12)
#define KU8_BIT_13                           ((uint8) 13)
#define KU8_BIT_14                           ((uint8) 14)
#define KU8_BIT_15                           ((uint8) 15)
#define KU8_BIT_16                           ((uint8) 16)
#define KU8_BIT_17                           ((uint8) 17)
#define KU8_BIT_18                           ((uint8) 18)
#define KU8_BIT_19                           ((uint8) 19)
#define KU8_BIT_20                           ((uint8) 20)
#define KU8_BIT_21                           ((uint8) 21)
#define KU8_BIT_22                           ((uint8) 22)
#define KU8_BIT_23                           ((uint8) 23)
#define KU8_BIT_24                           ((uint8) 24)
#define KU8_BIT_25                           ((uint8) 25)
#define KU8_BIT_26                           ((uint8) 26)
#define KU8_BIT_27                           ((uint8) 27)
#define KU8_BIT_28                           ((uint8) 28)
#define KU8_BIT_29                           ((uint8) 29)
#define KU8_BIT_30                           ((uint8) 30)
#define KU8_BIT_31                           ((uint8) 31)

#define KU8_SHIFT_HALF_BYTE                  ((uint8) 4)
#define KU8_SHIFT_FOUR_BITS                  ((uint8) KU8_SHIFT_HALF_BYTE)
#define KU8_SHIFT_TWO_BITS                   ((uint8) 2)

#define KU8_POS_LOW_BYTE                     ((uint8) 0)
#define KU8_POS_HIGH_BYTE                    ((uint8) 8)

#define KU8_POS_L_LOW_BYTE                   ((uint8) 0)
#define KU8_POS_L_LOW_MIDDLE_BYTE            ((uint8) 8)
#define KU8_POS_L_HIGH_MIDDLE_BYTE           ((uint8) 16)
#define KU8_POS_L_HIGH_BYTE                  ((uint8) 24)

/**************************************************************************
**                       Data manipulation macros                        **
**************************************************************************/

/************************** 8 bit results macros *************************/

#define U8_BIT_SET(reg, mask)                   ((reg) |= (mask))
#define U8_BIT_CLEAR(reg, mask)                 ((reg) &= ((mask)^((uint8)0xFF)))

#define U8_COMPLEMENT(val)                     ((val) ^ ((uint8)0xFF))

#define U8_GET_ABSOLUTE_VALUE_FROM_S8(value)    (((value)<((sint8)(0)))?((uint8)-(value)):((uint8)(value)) /* PRQA S 3491 */)

/************************* 16 bit results macros *************************/

#define U16_BIT_SET(reg, mask)                  ((reg) |= (mask))
#define U16_BIT_CLEAR(reg, mask)                ((reg) &= ((mask)^((uint16)0xFFFF)))

#define U16_COMPLEMENT(val)                     ((val) ^ ((uint16)0xFFFF))

#define U16_GET_LOW_BYTE(_word)                 ((uint8)(((_word) & KU16_MASK_BYTE_LOW ) >> KU8_POS_LOW_BYTE ))
#define U16_GET_HIGH_BYTE(_word)  /*  */              ((uint8)(((_word) & KU16_MASK_BYTE_HIGH) >> KU8_POS_HIGH_BYTE))

#define U16_GET_ABSOLUTE_VALUE_FROM_S16(value)  (((value)<((sint16)(0)))?((uint16)-(value)):((uint16)(value)) /* PRQA S 3491 */)
#define U16_GET_SATURATED_VALUE_FROM_U32(value) (((value)>((uint32)(KU16_MAX)))?((uint16)KU16_MAX):((uint16)(value)) /* PRQA S 3491 */)

#define U16_SWAP_BYTE_ORDER(u16ToSwap) \
   ( \
      (uint16)((uint16)((uint16)(u16ToSwap) & (uint16)0x00FF) << KU16_EIGHT) | \
      (uint16)((uint16)((uint16)(u16ToSwap) & (uint16)0xFF00) >> KU16_EIGHT) \
   )

/************************* 32 bit results macros *************************/

#define U32_BIT_SET(reg, mask)                  ((reg) |= (mask))
#define U32_BIT_CLEAR(reg, mask)                ((reg) &= ((mask)^((uint32)0xFFFFFFFFuL)))
#define U32_COMPLEMENT(val)                     ((val)^((uint32)0xFFFFFFFFuL))

#define U32_GET_LOW_BYTE(_long)                 ((uint8)(  (_long) & KU32_MASK_BYTE_LOW))
#define U32_GET_LOW_MIDDLE_BYTE(_long)          ((uint8)(( (_long) & KU32_MASK_BYTE_LOW_MIDDLE) >> KU8_POS_L_LOW_MIDDLE_BYTE))
#define U32_GET_HIGH_MIDDLE_BYTE(_long)         ((uint8)(( (_long) & KU32_MASK_BYTE_HIGH_MIDDLE) >> KU8_POS_L_HIGH_MIDDLE_BYTE))
#define U32_GET_HIGH_BYTE(_long)                ((uint8)(( (_long) & KU32_MASK_BYTE_HIGH)        >> KU8_POS_L_HIGH_BYTE))

#define U32_GET_ABSOLUTE_VALUE_FROM_S32(value)  (((value)<((sint32)(0)))?((uint32)-(value)):((uint32)(value)) /* PRQA S 3491 */)

#define U32_SWAP_BYTE_ORDER(u32ToSwap) \
   ( \
      (((u32ToSwap) & 0x000000FFUL) << 24) | \
      (((u32ToSwap) & 0x0000FF00UL) << 8 ) | \
      (((u32ToSwap) & 0x00FF0000UL) >> 8 ) | \
      (((u32ToSwap) & 0xFF000000UL) >> 24) \
   )

#define U64_BIT_SET(reg, mask)                  ((reg) |= (mask))
#define U64_BIT_CLEAR(reg, mask)                ((reg) &= ((mask)^((uint64)0xFFFFFFFFFFFFFFFF)))
#define U64_COMPLEMENT(val)                     ((val)^((uint64)0xFFFFFFFFFFFFFFFF))

#if defined(ENABLE_DEBUG_PINS)
#include "Dio.h"

#if defined(CAL_KU8_MOCK_UP_HW_CONFIGURATION)

#define DIO_SET_DBG1() Dio_WriteChannel(DioConf_DioChannel_DBG_PTE4, STD_HIGH)
#define DIO_CLR_DBG1() Dio_WriteChannel(DioConf_DioChannel_DBG_PTE4, STD_LOW)
#define DIO_SET_DBG2() Dio_WriteChannel(DioConf_DioChannel_DBG_PTE10, STD_HIGH)
#define DIO_CLR_DBG2() Dio_WriteChannel(DioConf_DioChannel_DBG_PTE10, STD_LOW)
LOCAL uint8 cmn_u8Dbg1State = STD_LOW;
LOCAL uint8 cmn_u8Dbg2State = STD_LOW;
#define DIO_TOGGLE_DBG1() (cmn_u8Dbg1State == STD_LOW ? (DIO_SET_DBG1(), cmn_u8Dbg1State = STD_HIGH) : (DIO_CLR_DBG1(), cmn_u8Dbg1State = STD_LOW))
#define DIO_TOGGLE_DBG2() (cmn_u8Dbg2State == STD_LOW ? (DIO_SET_DBG2(), cmn_u8Dbg2State = STD_HIGH) : (DIO_CLR_DBG2(), cmn_u8Dbg2State = STD_LOW))

#else

#define DIO_SET_DBG1() Dio_WriteChannel(DioConf_DioChannel_DBG_8, STD_HIGH)
#define DIO_CLR_DBG1() Dio_WriteChannel(DioConf_DioChannel_DBG_8, STD_LOW)
#define DIO_SET_DBG2() Dio_WriteChannel(DioConf_DioChannel_DBG_0, STD_HIGH)
#define DIO_CLR_DBG2() Dio_WriteChannel(DioConf_DioChannel_DBG_0, STD_LOW)
LOCAL uint8 cmn_u8Dbg1State = STD_LOW;
LOCAL uint8 cmn_u8Dbg2State = STD_LOW;
#define DIO_TOGGLE_DBG1() (cmn_u8Dbg1State == STD_LOW ? (DIO_SET_DBG1(), cmn_u8Dbg1State = STD_HIGH) : (DIO_CLR_DBG1(), cmn_u8Dbg1State = STD_LOW))
#define DIO_TOGGLE_DBG2() (cmn_u8Dbg2State == STD_LOW ? (DIO_SET_DBG2(), cmn_u8Dbg2State = STD_HIGH) : (DIO_CLR_DBG2(), cmn_u8Dbg2State = STD_LOW))

#endif

#endif

/************************* Variant handling macros *************************/

#define KUB_eCS_LOCK_CUTOFF_VARIANT (((NVP_u32eCSVariant & KU32_ONE) == KU32_ZERO)? KB_TRUE : KB_FALSE)
#define KUB_eCS_LOCK_99_PWM_VARIANT (((NVP_u32eCSVariant & KU32_ONE) == KU32_ONE)? KB_TRUE : KB_FALSE)

#define KUB_eCS_BACK_UP_PROFILE_VARIANT            ((NVP_u32eCSVariant & KU32_TWO) == KU32_TWO)
//#define KUB_eCS_BACK_UP_PROFILE_DISABLED_VARIANT   ((NVP_u32eCSVariant & KU8_TWO) == KU8_ZERO)

#define KUB_eCS_ACC_ON_PCB_BOTTOM_VARIANT ((NVP_u32eCSVariant & KU8_FOUR) == KU8_ZERO)
//#define KUB_eCS_ACC_ON_PCB_TOP_VARIANT    ((NVP_u32eCSVariant & KU8_FOUR) == KU8_FOUR)

#define KUB_eCS_SBS_BKL_RES_CIRCUIT_SEAT_1_VARIANT_1 ((NVP_u32eCSVariant & KU32_EIGHT) == KU32_ZERO)
#define KUB_eCS_SBS_BKL_RES_CIRCUIT_SEAT_1_VARIANT_2 ((NVP_u32eCSVariant & KU32_EIGHT) == KU32_EIGHT)

#define KUB_eCS_SBS_BKL_RES_CIRCUIT_SEAT_2_VARIANT_1 ((NVP_u32eCSVariant & KU32_SIXTEEN) == KU32_ZERO)
#define KUB_eCS_SBS_BKL_RES_CIRCUIT_SEAT_2_VARIANT_2 ((NVP_u32eCSVariant & KU32_SIXTEEN) == KU32_SIXTEEN)

#define KUB_eCS_SBS_SEAT_1_NOT_CONFIGURED_VARIANT  ((NVP_u32eCSVariant & KU32_THIRTYTWO) == KU32_ZERO)
#define KUB_eCS_SBS_SEAT_1_CONFIGURED_VARIANT      ((NVP_u32eCSVariant & KU32_THIRTYTWO) == KU32_THIRTYTWO)

#define KUB_eCS_SBS_SEAT_2_NOT_CONFIGURED_VARIANT  ((NVP_u32eCSVariant & KU32_SIXTYFOUR) == KU32_ZERO)
#define KUB_eCS_SBS_SEAT_2_CONFIGURED_VARIANT      ((NVP_u32eCSVariant & KU32_SIXTYFOUR) == KU32_SIXTYFOUR)

#define KUB_eCS_BKL_SEAT_1_NOT_CONFIGURED_VARIANT  ((NVP_u32eCSVariant & KU32_ONE_HUNDRED_AND_TWENTYEIGHT) == KU32_ZERO)
#define KUB_eCS_BKL_SEAT_1_CONFIGURED_VARIANT      ((NVP_u32eCSVariant & KU32_ONE_HUNDRED_AND_TWENTYEIGHT) == KU32_ONE_HUNDRED_AND_TWENTYEIGHT)

#define KUB_eCS_BKL_SEAT_2_NOT_CONFIGURED_VARIANT  ((NVP_u32eCSVariant & KU32_TWO_HUNDRED_AND_FIFTYSIX) == KU32_ZERO)
#define KUB_eCS_BKL_SEAT_2_CONFIGURED_VARIANT      ((NVP_u32eCSVariant & KU32_TWO_HUNDRED_AND_FIFTYSIX) == KU32_TWO_HUNDRED_AND_FIFTYSIX)

#define KB_eCS_SOLENOID_1_ENABLED_VARIANT   (((NVP_u32eCSVariant & 512u) == KU32_ZERO) ? KB_TRUE : KB_FALSE)
#define KB_eCS_SOLENOID_1_DISABLED_VARIANT  (((NVP_u32eCSVariant & 512u) == 512u) ? KB_TRUE : KB_FALSE)

#define KB_eCS_SOLENOID_2_ENABLED_VARIANT   (((NVP_u32eCSVariant & 1024u) == KU32_ZERO) ? KB_TRUE : KB_FALSE)
#define KB_eCS_SOLENOID_2_DISABLED_VARIANT  (((NVP_u32eCSVariant & 1024u) == 1024u) ? KB_TRUE : KB_FALSE)

#define KB_eCS_SOLENOID_3_ENABLED_VARIANT   (((NVP_u32eCSVariant & 2048u) == KU32_ZERO) ? KB_TRUE : KB_FALSE)
#define KB_eCS_SOLENOID_3_DISABLED_VARIANT  (((NVP_u32eCSVariant & 2048u) == 2048u) ? KB_TRUE : KB_FALSE)

#define KB_eCS_SOLENOID_4_ENABLED_VARIANT   (((NVP_u32eCSVariant & 4096u) == KU32_ZERO) ? KB_TRUE : KB_FALSE)
#define KB_eCS_SOLENOID_4_DISABLED_VARIANT  (((NVP_u32eCSVariant & 4096u) == 4096u) ? KB_TRUE : KB_FALSE)

#define KB_eCS_SOLENOID_5_ENABLED_VARIANT   (((NVP_u32eCSVariant & 8192u) == KU32_ZERO) ? KB_TRUE : KB_FALSE)
#define KB_eCS_SOLENOID_5_DISABLED_VARIANT  (((NVP_u32eCSVariant & 8192u) == 8192u) ? KB_TRUE : KB_FALSE)

#define KB_eCS_SOLENOID_6_ENABLED_VARIANT   (((NVP_u32eCSVariant & 16384u) == KU32_ZERO) ? KB_TRUE : KB_FALSE)
#define KB_eCS_SOLENOID_6_DISABLED_VARIANT  (((NVP_u32eCSVariant & 16384u) == 16384u) ? KB_TRUE : KB_FALSE)

#define KB_BUCKLE_1_INVERTED_LOGIC_DEACTIVATED (((NVP_u32eCSVariant & 32768) == KU32_ZERO) ? KB_TRUE : KB_FALSE)
#define KB_BUCKLE_1_INVERTED_LOGIC_ACTIVATED   (((NVP_u32eCSVariant & 32768) == 32768) ? KB_TRUE : KB_FALSE)

#define KB_BUCKLE_2_INVERTED_LOGIC_DEACTIVATED   (((NVP_u32eCSVariant & 65536) == KU32_ZERO) ? KB_TRUE : KB_FALSE)
#define KB_BUCKLE_2_INVERTED_LOGIC_ACTIVATED  (((NVP_u32eCSVariant & 65536) == 65536) ? KB_TRUE : KB_FALSE)

#define KB_SEAT_1_REMOVABLE_CONFIG_DEACTIVATED   (((NVP_u32eCSVariant & 131072) == KU32_ZERO) ? KB_TRUE : KB_FALSE)
#define KB_SEAT_1_REMOVABLE_CONFIG_ACTIVATED  (((NVP_u32eCSVariant & 131072) == 131072) ? KB_TRUE : KB_FALSE)

#define KB_SEAT_2_REMOVABLE_CONFIG_DEACTIVATED   (((NVP_u32eCSVariant & 262144) == KU32_ZERO) ? KB_TRUE : KB_FALSE)
#define KB_SEAT_2_REMOVABLE_CONFIG_ACTIVATED  (((NVP_u32eCSVariant & 262144) == 262144) ? KB_TRUE : KB_FALSE)

#define KB_SBS_LAST_STATE_ENABLED_VARIANT  (((NVP_u32eCSVariant & 524288) == KU32_ZERO) ? KB_TRUE : KB_FALSE)
#define KB_SBS_LAST_STATE_DISABLED_VARIANT  (((NVP_u32eCSVariant & 524288) == 524288) ? KB_TRUE : KB_FALSE)

/* end of conditional inclusion of COMMON.GEN.h */

#endif   /* COMMON.GEN_H */
