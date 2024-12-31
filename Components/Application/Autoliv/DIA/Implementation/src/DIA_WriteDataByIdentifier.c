/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

 *******************************************************************************
C-File Template Version: 
Template version: AEM_PROCESS_1.25.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2022-09
 ******************************************************************************/
/**
 *    $Revision: 1.3.11.48 $
 *    $ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/DIA/Implementation/src/project.pj $
 */

/******************************************************************************

details
	This file is intended to handle Write Data By Identifier services.

 ******************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "Rte_DIA.h"
#include "DIA.h"
#include "Dcm.h"
/******************************************************************************
MODULE DEFINES
 ******************************************************************************/
/**
 * \brief
 *    Constant used to check the write status of eCS coding variant.
 */
#define KU32_DIA_BIT_MASK_023E                                 (KU32_MASK_BIT_6)
/**
 * \brief
 *    Constant used to check the write status of eCS parameters.
 */
#define KU32_DIA_BIT_MASK_0236                                 (KU32_MASK_BIT_7)
/**
 * \brief
 *    Constant used to check the write status of mesurement frame config.
 */
#define KU32_DIA_BIT_MASK_MEASUREMENT_FRAME_CONFIG            (KU32_MASK_BIT_8)
/**
 * \brief
 *    Constant used to check the write status of part number.
 */
#define KU32_DIA_BIT_MASK_HW_PART_NUMBER                      (KU32_MASK_BIT_9)
/**
 * \brief
 *    Constant used to check the write status of Acc angles offset calibration.
 */
#define KU32_DIA_BIT_MASK_ACC_ANGLE_OFFSET                    (KU32_MASK_BIT_10)
/**
 * \brief
 *    Constant used to check the write status of ecu assembly serial number.
 */
#define KU32_DIA_BIT_MASK_ECU_ASSEMBLY_SERIAL_NUMBER          (KU32_MASK_BIT_11)
/**
 * \brief
 *    Constant used to check the write status of manufacturing date.
 */
#define KU32_DIA_BIT_MASK_FD8B                                (KU32_MASK_BIT_12)
/**
 * \brief
 *    Constant used to check the write status of ecs variant.
 */
#define KU32_DIA_BIT_MASK_ECS_VARIANT                         (KU32_MASK_BIT_13)
/**
 * \brief
 *    Constant used to check the write status of ecs parameters.
 */
#define KU32_DIA_BIT_MASK_ECS_PARAMETERS                      (KU32_MASK_BIT_14)
/**
 * \brief
 *    Constant used to check the write status of ecs acc offsets.
 */
#define KU32_DIA_BIT_MASK_ECS_ACC_OFFSETS                     (KU32_MASK_BIT_15)
/**
 * \brief
 *    Constant used to check the write status of ecs profiles.
 */
#define KU32_DIA_BIT_MASK_ECS_PROFILES                        (KU32_MASK_BIT_16)
/**
 * \brief
 *    Constant used to check the write status of ecs steps.
 */
#define KU32_DIA_BIT_MASK_ECS_STEPS                           (KU32_MASK_BIT_17)
/**
 * \brief
 *    Constant used to check the write status of ecs acc lowpass.
 */
#define KU32_DIA_BIT_MASK_ECS_ACC_LOWPASS                     (KU32_MASK_BIT_18)
/**
 * \brief
 *    Constant used to check the write status of Ecu serial number.
 */
#define KU32_DIA_BIT_MASK_F18C                                (KU32_MASK_BIT_19)
/**
 * \brief
 *    Constant used to check the write status of ecs algo output delay.
 */
#define KU32_DIA_BIT_MASK_ECS_ALGO_OUTPUT_DELAY               (KU32_MASK_BIT_20)
/**
 * \brief
 *    Constant used to check the write status of ecs sensitivity lut.
 */
#define KU32_DIA_BIT_MASK_ECS_SENSITIVITY_LUT                 (KU32_MASK_BIT_21)
/**
 * \brief
 *    Constant used to check the write status of ecs sensitivity opt.
 */
#define KU32_DIA_BIT_MASK_ECS_SENSITIVITY_OPT                 (KU32_MASK_BIT_22)
/**
 * \brief
 *    Constant used to check the write status of Ecu Hw version number.
 */
#define KU32_DIA_BIT_MASK_F1A3                                (KU32_MASK_BIT_23)
/**
 * \brief
 *    Constant used to check the write status of Ecu Hw version number.
 */
#define KU32_DIA_BIT_MASK_FD03                                (KU32_MASK_BIT_24)
/**
 * \brief
 *    Constant used to check the write status of measurement frame ram config.
 */
#define KU32_DIA_BIT_MASK_MEAS_FRAME_RAM_ADDR_CFG             (KU32_MASK_BIT_25)
/**
 * \brief
 *    Constant used to check the write status of spare part number.
 */
#define KU32_DIA_BIT_MASK_F187                                (KU32_MASK_BIT_26)
/**
 * \brief
 *    Constant used to check the write status of application Sw version number.
 */
#define KU32_DIA_BIT_MASK_F189                                (KU32_MASK_BIT_27)
/**
 * \brief
 *    Constant used to check the write status of Ecu Hw number.
 */
#define KU32_DIA_BIT_MASK_F191                                (KU32_MASK_BIT_28)
/**
 * \brief
 *    Constant used to check the write status of system name.
 */
#define KU32_DIA_BIT_MASK_F197                                (KU32_MASK_BIT_29)
/**
 * \brief
 *    Constant used to check the write status of ASAM ODX file identifier.
 */
#define KU32_DIA_BIT_MASK_F19E                                (KU32_MASK_BIT_30)
/**
 * \brief
 *    Constant used to check the write status of ASAM ODX file version.
 */
#define KU32_DIA_BIT_MASK_F1A2                                (KU32_MASK_BIT_31)

/* ASCII codes constants */
/**
 * \brief
 *    ASCII value 0.
 */
#define KU8_DIA_ASCII_0               ((uint8)'0')
/**
 * \brief
 *    ASCII value 1.
 */
#define KU8_DIA_ASCII_1               ((uint8)'1')
/**
 * \brief
 *    ASCII value 9.
 */
#define KU8_DIA_ASCII_9               ((uint8)'9')
/**
 * \brief
 *    ASCII value A.
 */
#define KU8_DIA_ASCII_A               ((uint8)'A')
/**
 * \brief
 *    ASCII value Z.
 */
#define KU8_DIA_ASCII_Z               ((uint8)'Z')
/**
 * \brief
 *    ASCII value for space.
 */
#define KU8_DIA_ASCII_SPACE           ((uint8)' ')
/**
 * \brief
 *    ASCII value for hyphen.
 */
#define KU8_DIA_ASCII_HYPHEN          ((uint8)'-')
/**
 * \brief
 *    ASCII value E.
 */
#define KU8_DIA_ASCII_E               ((uint8)'E')
/**
 * \brief
 *    ASCII value V.
 */
#define KU8_DIA_ASCII_V               ((uint8)'V')
/**
 * \brief
 *    ASCII value underscore.
 */
#define KU8_DIA_ASCII_UNDERSCORE      ((uint8)'_')
/**
 * \brief
 *    Maximum ASCII value.
 */
#define KU8_DIA_ASCII_MAX             ((uint8)0x7F)
/**
 * \brief
 *    Constant used as parameter for bIsAsciiCharAllowedAUDI function to check F1A3 service restrictions.
 */
#define KU8_DIA_DID_F1A3              ((uint8)0x01)
/**
 * \brief
 *    Constant used as parameter for bIsAsciiCharAllowedAUDI function to check F191 and F187 services restrictions.
 */
#define KU8_DIA_DID_F187_DID_F191     ((uint8)0x02)
/**
 * \brief
 *    Constant used as parameter for bIsAsciiCharAllowedAUDI function to check F197 and F18C services restrictions.
 */
#define KU8_DIA_DID_F18C_DID_F197     ((uint8)0x03)
/**
 * \brief
 *    Constant used as parameter for bIsAsciiCharAllowedAUDI function to check F19E service restrictions.
 */
#define KU8_DIA_DID_F19E              ((uint8)0x04)
/**
 * \brief
 *    Constant used as parameter for bIsAsciiCharAllowedAUDI function to check F1A2 service restrictions.
 */
#define KU8_DIA_DID_F1A2              ((uint8)0x05)
/**
 * \brief
 *    Constant used as parameter for bIsAsciiCharAllowedAUDI function to check F189 service restrictions.
 */
#define KU8_DIA_DID_F189              ((uint8)0x06)
/**
 * \brief
 *    Maximum value for LSB in BCD format.
 */
#define KU8_DIA_LSB_BCD_DIGIT_MAX_VALUE  ((uint8)0x09)
/**
 * \brief
 *    Maximum value for MSB in BCD format.
 */
#define KU8_DIA_MSB_BCD_DIGIT_MAX_VALUE  ((uint8)0x90)
/**
 * \brief
 *    Manufacturing date year index.
 */
#define KU8_DIA_MANUFACTURING_DATE_YEAR_INDEX        ((uint8)0)
/**
 * \brief
 *    Manufacturing date month index.
 */
#define KU8_DIA_MANUFACTURING_DATE_MONTH_INDEX       ((uint8)1)
/**
 * \brief
 *    Manufacturing date day index.
 */
#define KU8_DIA_MANUFACTURING_DATE_DAY_INDEX         ((uint8)2)
/**
 * \brief
 *    Manufacturing date day maximum value.
 */
#define KU8_DIA_MANUFACTURING_DATE_MAX_DAY_VALUE     ((uint8)0x31)
/**
 * \brief
 *    Manufacturing date month maximum value.
 */
#define KU8_DIA_MANUFACTURING_DATE_MAX_MONTH_VALUE   ((uint8)0x12)
/**
 * \brief
 *    NVP_au16Var1AdcRange and NVP_au16Var2AdcRange size.
 */
#define KU8_DIA_NVP_VAR_ADC_RANGE_ARRAY_SIZE         (KU8_TWENTY)
/**
 * \brief
 *    NVP_au16Angle2_Idx block size.
 */
#define KU8_DIA_NVP_ANGLE_2_IDX_BLOCK_SIZE           ((uint8) 4)
/**
 * \brief
 *    NVP_au16Angle1_Idx block size.
 */
#define KU8_DIA_NVP_ANGLE_1_IDX_BLOCK_SIZE           ((uint8) 3)
/**
 * \brief
 *    NVP_AEE_TRACEABILITY_NUMBER block size.
 */
#define KU8_DIA_NVP_AEE_TRACEABILITY_NB_BLOCK_SIZE   ((uint8) 12)
/******************************************************************************
MODULE TYPES
 ******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
 ******************************************************************************/
LOCAL boolean dia_IsAsciiCharAllowedAUDI(const uint8* kpu8Data , const uint16 ku16Length, const uint8 ku8DiaAsciiToCheck);
LOCAL boolean dia_CheckBCD (const uint8 ku8Value);
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
 ******************************************************************************/
#define DIA_START_SEC_VAR_INIT_32
#include "DIA_MemMap.h"

/**
 * \brief
 *    Variable used to avoid multiple writing in the NVM buffer.
 * \initialization
 *    KU32_ZERO (0)
 * \range
 *    0..KU32_MAX
 */
LOCAL uint32 dia_u32WriteNVPBlockStatusFlag = KU32_ZERO;
/**
 * \brief
 *    Variable used to write the eCS variant.
 * \initialization
 *    KU32_ZERO (0)
 * \range
 *    0..KU32_MAX
 */
LOCAL uint32 dia_u32eCSVariantData = KU32_ZERO;
/**
 * \brief
 *    Variable used to write the eCS variant.
 * \initialization
 *    KU32_ZERO (0)
 * \range
 *    0..KU32_MAX
 */
LOCAL uint32 dia_u32eCSVariantConfigData = KU32_ZERO;
#define DIA_STOP_SEC_VAR_INIT_32
#include "DIA_MemMap.h"

#define DIA_START_SEC_VAR_INIT_8
#include "DIA_MemMap.h"

/**
 * \brief
 *    Variable used to check the writing status for NVPAccAxis Block
 * \initialization
 *    E_NOT_OK
 * \range
 *    E_NOT_OK
 *    NVM_REQ_OK
 *    NVM_REQ_PENDING;
 */
LOCAL uint8 dia_u8ManageNVPAccAxisBlockWritingResult = E_NOT_OK;
/**
 * \brief
 *    Variable used to check the writing status for NVPeCSVariant Block
 * \initialization
 *    E_NOT_OK
 * \range
 *    E_NOT_OK
 *    NVM_REQ_OK
 *    NVM_REQ_PENDING;
 */
LOCAL uint8 dia_u8ManageNVPeCSVariantBlockWritingResult = E_NOT_OK;
/**
 * \brief
 *    Variable used to check the writing status for NVPEcuTimingParameters Block
 * \initialization
 *    E_NOT_OK
 * \range
 *    E_NOT_OK
 *    NVM_REQ_OK
 *    NVM_REQ_PENDING;
 */
LOCAL uint8 dia_u8ManageNVPEcuTimingParametersBlockWritingResult = E_NOT_OK;

#define DIA_STOP_SEC_VAR_INIT_8
#include "DIA_MemMap.h"
/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
 ******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
 ******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
 ******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
 ******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
 ******************************************************************************/
#define DIA_START_SEC_CODE
#include "DIA_MemMap.h"
/**
 * \brief
 *       Function used to check if a data set contains only ASCII values for
         letters, digits, point, hyphen, underscore or space.
 * \inputparam
 *       Name: kpu8Data;
 *       Type: const uint8*;
 *       Description: Data set;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: ku16Length;
 *       Type: const uint16;
 *       Description: Length of the data set;
 *       Range: 0..KU16_MAX;
 * \inputparam
 *       Name: ku8DiaAsciiToCheck;
 *       Type: const uint8;
 *       Description: Diagnostic service;
 *       Range: 0..KU8_MAX;
 * \return
 *       bCr:
 *          o KB_TRUE - all bytes are ASCII values for supported characters;
 *          o KB_FALSE - one or several bytes aren't ASCII values for supported characters;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \dynamicaspectcaller
 *       Called by WriteDataByIdentifier functions.
 * \dynamicaspectdescription
 *       Functions used to write data by 2E service.
 * \ddesignrequirement
 *		   DSG_DIA_dia_IsAsciiCharAllowedAUDI
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F187_VWSparePartNumber_WriteData
 *       DIA_runDidF189_VWApplicationSoftwareVersionNumberWrite
 *       ARCH_SW_DIA_pseDID_F189_VWApplicationSoftwareVersionNumber_WriteData
 *       ARCH_SW_DIA_pseDID_F191_VWECUHardwareNumber_WriteData
 *       ARCH_SW_DIA_pseDID_F197_VWSystemNameOrEngineType_WriteData
 *       ARCH_SW_DIA_pseDID_F19E_ASAMODXFileIdentifier_WriteData
 *       ARCH_SW_DIA_pseDID_F1A2_ASAMODXFileVersion_WriteData
 *       ARCH_SW_DIA_pseDID_F18C_ECUSerialNumberData_WriteData
 *       ARCH_SW_DIA_pseDID_F1A3_VWECUHardwareVersionNumber_WriteData
 **/
LOCAL boolean dia_IsAsciiCharAllowedAUDI(const uint8* kpu8Data , const uint16 ku16Length, const uint8 ku8DiaAsciiToCheck)
{
   uint16 u16Idx;
   boolean bCr;

   /* Check that there are some bytes to analyze. */
   if (KU8_ZERO < ku16Length)
   {
      bCr = KB_TRUE;

      /* Switch case to write restrictions for Identification services */
      switch (ku8DiaAsciiToCheck)
      {
      /* This case covers DID F1A3 */
      case KU8_DIA_DID_F1A3:
         /*  Byte 0 should be: H, X, Y, Z or in the interval 0-9 (ASCII) */
         if (((KU8_DIA_ASCII_0 > *(kpu8Data + KU8_ZERO))  || (KU8_DIA_ASCII_9 < *(kpu8Data + KU8_ZERO))) &&
               ((KU8_DIA_ASCII_A > *(kpu8Data + KU8_ZERO))  || (KU8_DIA_ASCII_Z < *(kpu8Data + KU8_ZERO))))
         {
            bCr= KB_FALSE;
         }
         /*  Byte 1 should be in the interval 0-9 (ASCII) */
         else if ((KU8_DIA_ASCII_0 > *(kpu8Data + KU8_ONE)) ||
               (KU8_DIA_ASCII_9 < *(kpu8Data + KU8_ONE)))
         {
            bCr= KB_FALSE;
         }
         /*  Byte 2 should be in the interval 1-9 (ASCII) */
         else if ((KU8_DIA_ASCII_1 > *(kpu8Data + KU8_TWO)) ||
               (KU8_DIA_ASCII_9 < *(kpu8Data + KU8_TWO)))
         {
            bCr= KB_FALSE;
         }
         else
         {
            /* do nothing */
         }
         break;

         /* This case covers DIDs F187 and F191 */
      case KU8_DIA_DID_F187_DID_F191:
         /* Roll over all bytes of the buffer. */
         for (u16Idx = KU8_ZERO; u16Idx < ku16Length; u16Idx++)
         {
            /* For the first 3 bytes of the buffer check if bytes are either:
				   digit or upper case letter */
            if (u16Idx < KU8_THREE)
            {
               if (((KU8_DIA_ASCII_0 > *(kpu8Data + u16Idx))  ||
                   (KU8_DIA_ASCII_9 < *(kpu8Data + u16Idx))) &&
                   ((KU8_DIA_ASCII_A > *(kpu8Data + u16Idx))  ||
                   (KU8_DIA_ASCII_Z < *(kpu8Data + u16Idx))))
               {
                  bCr = KB_FALSE;
               }
            }
            /* The following six bytes should be digits */
            else if ((KU8_TWO < u16Idx) && (KU8_EIGHT >= u16Idx))
            {
               if ((KU8_DIA_ASCII_0 > *(kpu8Data + u16Idx)) ||
                     (KU8_DIA_ASCII_9 < *(kpu8Data + u16Idx)))
               {
                  bCr = KB_FALSE;
               }
            }
            /* The last two bytes should be either upper case letters or space */
            else
            {
               if (((KU8_DIA_ASCII_A > *(kpu8Data + u16Idx))  ||
                     (KU8_DIA_ASCII_Z < *(kpu8Data + u16Idx))) &&
                     (KU8_DIA_ASCII_SPACE != *(kpu8Data + u16Idx)))
               {
                  bCr = KB_FALSE;
               }
            }
         }
         break;

         /* This case covers DIDs F18C and F197 */
      case KU8_DIA_DID_F18C_DID_F197:
         /* Roll over all bytes of the buffer. */
         for (u16Idx = KU8_ZERO; u16Idx < ku16Length; u16Idx++)
         {
            /* The bytes of the buffer should be ASCII characters with values between '0'-'DEL' */
            if (KU8_DIA_ASCII_MAX < *(kpu8Data + u16Idx))
            {
               bCr = KB_FALSE;
            }
         }
         break;

         /* This case covers DID F19E */
      case KU8_DIA_DID_F19E:
         /* Roll over all bytes of the buffer. */
         for (u16Idx = KU8_ZERO; u16Idx < ku16Length; u16Idx++)
         {
            /* The first byte of the buffer should be 'E' */
            if (KU8_ZERO == u16Idx)
            {
               if (KU8_DIA_ASCII_E != *(kpu8Data + u16Idx))
               {
                  bCr = KB_FALSE;
               }
            }
            /* The second byte of the buffer should be 'V' */
            else if (KU8_ONE == u16Idx)
            {
               if (KU8_DIA_ASCII_V != *(kpu8Data + u16Idx))
               {
                  bCr = KB_FALSE;
               }
            }
            /* The third byte of the buffer should be '_' */
            else if (KU8_TWO == u16Idx)
            {
               if (KU8_DIA_ASCII_UNDERSCORE != *(kpu8Data + u16Idx))
               {
                  bCr = KB_FALSE;
               }
            }
            /* The last byte of the buffer should be 0x00 */
            else if (KU8_TWENTYTHREE == u16Idx)
            {
               if (KU16_ZERO != *(kpu8Data + u16Idx))
               {
                  bCr = KB_FALSE;
               }
            }
            /* The rest of bytes should be ASCII characters with values between '0'-'DEL' */
            else
            {
               if (KU8_DIA_ASCII_MAX < *(kpu8Data + u16Idx))
               {
                  bCr = KB_FALSE;
               }
            }

         }
         break;

         /* This case covers DID F1A2 */
      case KU8_DIA_DID_F1A2:
         /* Roll over all bytes of the buffer. */
         for (u16Idx = KU8_ZERO; u16Idx < KU8_SIX; u16Idx++)
         {
            /*  Byte 3 and byte 6 should be in the interval 1-9 (ASCII) */
            if((KU8_TWO == u16Idx) || (KU8_FIVE == u16Idx))
            {
               if ((KU8_DIA_ASCII_1 > *(kpu8Data + u16Idx)) ||
                     (KU8_DIA_ASCII_9 < *(kpu8Data + u16Idx)))
               {
                  bCr = KB_FALSE;
               }
            }
            else
            {
               /*  The rest of bytes should be in the interval 0-9 (ASCII) */
               if((KU8_DIA_ASCII_0 > *(kpu8Data + u16Idx)) ||
                     (KU8_DIA_ASCII_9 < *(kpu8Data + u16Idx)))
               {
                  bCr = KB_FALSE;
               }
            }
         }
         break;

         /* This case covers DID F189 */
      case KU8_DIA_DID_F189:
         /* Roll over all bytes of the buffer. */
         for (u16Idx = KU8_ZERO; u16Idx < ku16Length; u16Idx++)
         {
            /* The bytes of the buffer should be ASCII characters with values between 0-9, A-Z and hyphen */
            if(((KU8_DIA_ASCII_0 > *(kpu8Data + u16Idx))  ||
                  (KU8_DIA_ASCII_9 < *(kpu8Data + u16Idx))) &&
                  ((KU8_DIA_ASCII_A > *(kpu8Data + u16Idx)) ||
                        (KU8_DIA_ASCII_Z < *(kpu8Data + u16Idx))) &&
                        (KU8_DIA_ASCII_HYPHEN != *(kpu8Data + u16Idx)))
            {
               bCr = KB_FALSE;
            }
         }
         break;

         /* byte value is not part of allowed range */  /*should never happen*/
      default:
         bCr= KB_FALSE;
         break;
      }
   }
   else
   {
      /* byte value is not part of allowed range */
      bCr= KB_FALSE;
   }
   return (bCr);
}

/**
 * \brief
 *       Function used to check if a data set is in BCD format.
 * \inputparam
 *       Name: ku8Data;
 *       Type: const uint8;
 *       Description: Data set;
 *       Range: 0..KU8_MAX;
 * \return
 *       bReturn:
 *          o KB_TRUE - all bytes are in BCD format;
 *          o KB_FALSE - one or several bytes aren't in BCD format;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \dynamicaspectcaller
 *       Called by DIA_runDidFD8B_ECUManufacturingDateWrite function.
 * \dynamicaspectdescription
 *       Function used to write data by 2E service.
 * \ddesignrequirement
 *       DSG_DIA_dia_CheckBCD
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FD8B_ECUManufacturingDateWrite
 **/
LOCAL boolean dia_CheckBCD (const uint8 ku8Value)
{
   /* The value to return */
   boolean bReturn;

   /* Check if both quartets of the value are BCD (in the range [0..9]) */
   if
   (
         /* Check the right digit */
         (KU8_DIA_LSB_BCD_DIGIT_MAX_VALUE < (ku8Value & KU8_MASK_HALF_BYTE_LOW)) ||
         /* Check the left digit */
         (KU8_DIA_MSB_BCD_DIGIT_MAX_VALUE < (ku8Value & KU8_MASK_HALF_BYTE_HIGH))
   )
   {
      /* The value is not in BCD format */
      bReturn = KB_FALSE;
   }
   else
   {
      /* The value is in BCD format */
      bReturn = KB_TRUE;
   }

   return bReturn;
}
/******************************************************************************
DEFINITION OF APIs
 ******************************************************************************/
/**
 * \brief
 *       Write Hardware Version Number.
 * \inputparam
 *       Name: kpu8Data;
 *       Type: const uint8*;
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FD00_HWVersionData_WriteData
 * \dynamicaspectdescription
 *       Write Hardware Version Number.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidFD00_HWVersionWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FD00_HWVersion_WriteData
 **/
EXPORTED Std_ReturnType DIA_runDidFD00_HWVersionWrite(const uint8 * kpu8Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;

   /* Check if ECU is locked. */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_HW_PART_NUMBER))
      {
         U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_HW_PART_NUMBER);
         /* Set the parameter in NVM buffer*/
         DIA_CopyData((uint8*)NVP_au8HWPartNumber, kpu8Data, KU8_TEN);

      }

      /* Set the block ID */
      u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_HW_PART_NUMBER, (uint8*)&NVP_au8HWPartNumber);

      if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_PENDING;
      }
      else
      {
         if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
         {
            u8Result = E_OK;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_HW_PART_NUMBER);
         }
         else
         {
            u8Result = E_NOT_OK;
            *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_HW_PART_NUMBER);
         }
      }
   }

   return u8Result;
}

/**
 * \brief
 *       Function used to write Measurement Frames RAM parameters.
 * \inputparam
 *       Name: pu8Data;
 *       Type: const uint8*;
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDFF_MeasurementFrameConfDataRam_WriteData
 * \dynamicaspectdescription
 *       Read Measurement Frames parameters.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidFDFF_MeasurementFrameRamConfWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDFF_MeasurementFrameRamConf_WriteData
 **/

EXPORTED Std_ReturnType DIA_runDidFDFF_MeasurementFrameRamConfWrite(const uint8 * pu8Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;
   uint8 u8Index = KU8_ZERO;
   uint8 u8NvpIndex = KU8_ZERO;
   u8Result = E_NOT_OK;

   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_MEAS_FRAME_RAM_ADDR_CFG))
      {
         U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_MEAS_FRAME_RAM_ADDR_CFG);
         /* Write Data in RAM */
         /* Cast 4 uint8 to an uint32 */
         for(u8NvpIndex = KU8_ZERO; u8NvpIndex < KU8_FIFTEEN; u8NvpIndex++)
         {
            NVP_au32RequestedRamAddressArray[u8NvpIndex] = (uint32)(
                  ((uint32)(pu8Data[u8Index + KU8_THREE])) |
                  ((uint32)(pu8Data[u8Index + KU8_TWO]) << KU8_POS_L_LOW_MIDDLE_BYTE) |
                  ((uint32)(pu8Data[u8Index + KU8_ONE]) << KU8_POS_L_HIGH_MIDDLE_BYTE) |
                  ((uint32)(pu8Data[u8Index]) << KU8_POS_L_HIGH_BYTE));

            NVP_au8RequestedRamSizeArray[u8NvpIndex] = pu8Data[u8NvpIndex + KU8_DIA_OFFSET_REQUESTED_RAM_SIZE_ARRAY];

            u8Index+= KU8_FOUR;
         }
      }

      /* Write Data in EEPROM */
      u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_MEAS_FRAME_RAM_ADDR_CFG, (uint8*)&NVP_au32RequestedRamAddressArray);

      if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_PENDING;
      }
      else if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
      {
         u8Result = E_OK;
         U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_MEAS_FRAME_RAM_ADDR_CFG);
      }
      else
      {
         u8Result = E_NOT_OK;
         U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_MEAS_FRAME_RAM_ADDR_CFG);
         *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;

         /* Retrieve initial status of Measurement Frame RAM Config Block */
         for(u8Index = KU8_ZERO; u8Index < KU8_FIFTEEN; u8Index++)
         {
            NVP_au32RequestedRamAddressArray[u8Index] = K_NVP_au32RequestedRamAddressArray[u8Index];
            NVP_au8RequestedRamSizeArray[u8Index] = K_NVP_au8RequestedRamSizeArray[u8Index];
         }
      }
   }

   return u8Result;
}


/**
 * \brief
 *       Function used to write Measurement Frames parameters.
 * \inputparam
 *       Name: pu8Data;
 *       Type: const uint8*;
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FEFF_MeasurementFramesConfData_WriteData
 * \dynamicaspectdescription
 *       Function used to write Measurement Frames parameters.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidFEFF_MeasurementFramesConfWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FEFF_MeasurementFramesConf_WriteData
 **/
EXPORTED Std_ReturnType DIA_runDidFEFF_MeasurementFramesConfWrite(const uint8 * pu8Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
   /* data signification; 8 cfg blocks of 4 bytes each */
   /* block0_cfg, block1_cfg...block7_cfg */
   /* each blockx_cfg contains 4 bytes => total 32 bytes */

   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;

   u8Result = E_NOT_OK;

   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_MEASUREMENT_FRAME_CONFIG))
      {
         U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_MEASUREMENT_FRAME_CONFIG);
         /* Write Data in RAM */
         NVP_u8EnableDevFrame = pu8Data[KU8_ZERO];
         NVP_u8MeasFrameTiming = pu8Data[KU8_ONE];
         NVP_au8MeasFrameBlockConfig[KU8_ZERO] = pu8Data[KU8_TWO];
         NVP_au8MeasFrameBlockConfig[KU8_ONE] = pu8Data[KU8_THREE];
         NVP_au8MeasFrameBlockConfig[KU8_TWO] = pu8Data[KU8_FOUR];

      }

      /* Write Data in EEPROM */
      u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_MEASUREMENT_FRAME_CONFIG, &NVP_u8EnableDevFrame);

      if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_PENDING;
      }
      else if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
      {
         u8Result = E_OK;
         U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_MEASUREMENT_FRAME_CONFIG);
      }
      else
      {
         u8Result = E_NOT_OK;
         U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_MEASUREMENT_FRAME_CONFIG);
         *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;

         /* Retrieve initial status of Measurement Frame Config Block */
         NVP_u8EnableDevFrame = K_NVP_u8EnableDevFrame;
         NVP_u8MeasFrameTiming = K_NVP_u8MeasFrameTiming;
         NVP_au8MeasFrameBlockConfig[KU8_ZERO] = K_NVP_au8MeasFrameBlockConfig[KU8_ZERO];
         NVP_au8MeasFrameBlockConfig[KU8_ONE] = K_NVP_au8MeasFrameBlockConfig[KU8_ONE];
         NVP_au8MeasFrameBlockConfig[KU8_TWO] = K_NVP_au8MeasFrameBlockConfig[KU8_TWO];
      }
   }

   return u8Result;
}

/**
 * \brief
 *       Function used to write the ECU Assembly Serial Number
 * \inputparam
 *       Name: pu8Data;
 *       Type: const uint8*;
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: Dcm_NegativeResponseCodeType* (uint8*);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F18C_AssemblySerialNumber_WriteData
 * \dynamicaspectdescription
 *       Function used to write the ECU Assembly Serial Number.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidF18C_AssemblySerialNumberWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F18C_AssemblySerialNumber_WriteData
 **/
EXPORTED Std_ReturnType DIA_runDidFD8C_AssemblySerialNumberWrite(const uint8 * pu8Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;

   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      /* Verify that no writing is already ongoing */
      if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_ECU_ASSEMBLY_SERIAL_NUMBER))
      {
         U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECU_ASSEMBLY_SERIAL_NUMBER);
         /* Copy coming data to the NVP assembly serial number pointer */
         DIA_CopyData((uint8*)NVP_au8AssemblySerialNumber, pu8Data, KU8_TWENTY);
      }

      /* launch writing data to ram shadow*/
      u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ECU_ASSEMBLY_SERIAL_NUMBER, (uint8*)NVP_u8AssemblyManufacturingYear);

      /* Writing return parse*/
      if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_PENDING;
      }
      else
      {
         if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
         {
            u8Result = E_OK;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECU_ASSEMBLY_SERIAL_NUMBER);
         }
         else
         {
            u8Result = E_NOT_OK;
            *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECU_ASSEMBLY_SERIAL_NUMBER);
         }
      }

   }

   return u8Result;
}

/**
 * \brief
 *       Function used to write the eCS variant used.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDE0_EcsVariantData_WriteData
 * \dynamicaspectdescription
 *       Function used to write the eCS variant used.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidFDE0_EcsVariantWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDE0_EcsVariant_WriteData
 **/
EXPORTED Std_ReturnType DIA_runDidFDE0_EcsVariantWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;
   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      /* Verify that no writing is already ongoing */
      if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_ECS_VARIANT))
      {
         U32_BIT_SET (dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_VARIANT);
         /* update RAM */
         dia_u32eCSVariantData = U32_SWAP_BYTE_ORDER(*(uint32*)Data);
      }

      /* launch writing data to ram shadow*/
      u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ECS_VARIANT, (uint8*)&dia_u32eCSVariantData);

      /* Writing return parse*/
      if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_PENDING;
      }
      else
      {
         if (NVM_REQ_OK == u8ManageNVPBlockWritingResult)
         {
            u8Result = E_OK;
            U32_BIT_CLEAR (dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_VARIANT);
         }
         else
         {
            u8Result = E_NOT_OK;
            *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            U32_BIT_CLEAR (dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_VARIANT);
         }
      }
   }

   return u8Result;
}

/**
 * \brief
 *       Function used to write the eCS parameters.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDE1_EcsParametersData_WriteData
 * \dynamicaspectdescription
 *       Function used to write the eCS parameters.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidFDE1_EcsParametersWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDE1_EcsParameters_WriteData
 **/
EXPORTED Std_ReturnType DIA_runDidFDE1_EcsParametersWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;
   uint8 u8Counter = KU8_ZERO;
   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {

      if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_ECS_PARAMETERS))
      {
         U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_PARAMETERS);

         for(u8Counter = KU8_ZERO; u8Counter < KU8_DIA_NVP_ANGLE_2_IDX_BLOCK_SIZE; u8Counter++)
         {
            if(u8Counter < KU8_DIA_NVP_ANGLE_1_IDX_BLOCK_SIZE)
            {
               NVP_au16Angle1_Idx[u8Counter] = ((uint16)((uint16)((uint16)Data[u8Counter*KU8_TWO] << KU8_EIGHT) | ((uint16)Data[(u8Counter*KU8_TWO) + KU8_ONE])));
               NVP_au16Angle1_Fact[u8Counter] = ((uint16)((uint16)((uint16)Data[(u8Counter*KU8_TWO) + KU8_SIX] << KU8_EIGHT) | ((uint16)Data[((u8Counter*KU8_TWO) + KU8_ONE)+ KU8_SIX])));
            }

            NVP_au16Angle2_Idx[u8Counter] = ((uint16)((uint16)((uint16)Data[((u8Counter*KU8_TWO) + KU8_SIX) + KU8_SIX] << KU8_EIGHT) | ((uint16)Data[(((u8Counter*KU8_TWO) + KU8_ONE) + KU8_SIX) + KU8_SIX])));
            NVP_au16Angle2_Fact[u8Counter] = ((uint16)((uint16)((uint16)Data[(((u8Counter*KU8_TWO) + KU8_SIX) + KU8_SIX) + KU8_EIGHT] << KU8_EIGHT) | ((uint16)Data[((((u8Counter*KU8_TWO) + KU8_ONE) + KU8_SIX) + KU8_SIX) + KU8_EIGHT])));

            if(u8Counter == KU8_THREE)
            {
               NVP_u16eCSTriggON = ((uint16)((uint16)((uint16)Data[((((u8Counter*KU8_TWO) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_TWO] << KU8_EIGHT) | ((uint16)Data[(((((u8Counter*KU8_TWO) + KU8_ONE) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_TWO])));
               NVP_u16eCSTriggOFF = ((uint16)((uint16)((uint16)Data[((((u8Counter*KU8_TWO) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_FOUR] << KU8_EIGHT) | ((uint16)Data[(((((u8Counter*KU8_TWO) + KU8_ONE) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_FOUR])));
               NVP_s16BallDamper = (sint16)((uint16)((uint16)((uint16)Data[((((u8Counter*KU8_TWO) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_SIX] << KU8_EIGHT) | ((uint16)Data[(((((u8Counter*KU8_TWO) + KU8_ONE) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_SIX])));

               NVP_s16PositionLimit = (sint16)((uint16)((uint16)((uint16)Data[((((u8Counter*KU8_TWO) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_EIGHT] << KU8_EIGHT) | ((uint16)Data[(((((u8Counter*KU8_TWO) + KU8_ONE) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_EIGHT])));
               NVP_u16CrashTmr = ((uint16)((uint16)((uint16)Data[((((u8Counter*KU8_TWO) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_TEN] << KU8_EIGHT) | ((uint16)Data[(((((u8Counter*KU8_TWO) + KU8_ONE) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_TEN])));
               NVP_s16Angle1 = (sint16)((uint16)((uint16)((uint16)Data[((((u8Counter*KU8_TWO) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_TWELVE] << KU8_EIGHT) | ((uint16)Data[(((((u8Counter*KU8_TWO) + KU8_ONE) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_TWELVE])));
               NVP_s16Angle2 = (sint16)((uint16)((uint16)((uint16)Data[((((u8Counter*KU8_TWO) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_FOURTEEN] << KU8_EIGHT) | ((uint16)Data[(((((u8Counter*KU8_TWO) + KU8_ONE) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_FOURTEEN])));
               NVP_u16LatchTmr = ((uint16)((uint16)((uint16)Data[((((u8Counter*KU8_TWO) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_SIXTEEN] << KU8_EIGHT) | ((uint16)Data[(((((u8Counter*KU8_TWO) + KU8_ONE) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_SIXTEEN])));

               NVP_u16LatchTmrLong = ((uint16)((uint16)((uint16)Data[((((u8Counter*KU8_TWO) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_EIGHTEEN] << KU8_EIGHT) | ((uint16)Data[(((((u8Counter*KU8_TWO) + KU8_ONE) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_EIGHTEEN])));
               NVP_u16DelayBetweenUnlocks = ((uint16)((uint16)((uint16)Data[((((u8Counter*KU8_TWO) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_TWENTY] << KU8_EIGHT) | ((uint16)Data[(((((u8Counter*KU8_TWO) + KU8_ONE) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_TWENTY])));

               NVP_u8CrashSample = Data[((((u8Counter*KU8_TWO) + KU8_SIX) + KU8_SIX) + KU8_EIGHT) + KU8_TWENTYTWO];
            }
         }
      }

      /* launch writing data to ram shadow*/
      u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ECS_PARAMETERS, (uint8*)&Data);

      /* Writing return parse*/
      if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_PENDING;
      }
      else
      {
         if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
         {
            u8Result = E_OK;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_PARAMETERS);
         }
         else
         {
            u8Result = E_NOT_OK;
            *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_PARAMETERS);
         }
      }

   }

   return u8Result;
}

/**
 * \brief
 *       Function used to write the eCS ACC offsets
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDE2_AccOffsetData_WriteData
 * \dynamicaspectdescription
 *       Function used to write the eCS ACC offsets.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidFDE2_EcsAccOffsetsWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDE2_EcsAccOffsets_WriteData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidFDE2_EcsAccOffsetsWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   uint16 u16BlockSize;
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;

   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      /* Verify that no writing is already ongoing */
      if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_ECS_ACC_OFFSETS))
      {
         U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_ACC_OFFSETS);
         /* Update RAM */
         Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ECS_ACC_OFFSETS, &u16BlockSize);
         NVP_s16OffsetAx = (sint16)((uint16)((uint16)((uint16)Data[KU8_ZERO] << KU8_EIGHT) | ((uint16)Data[KU8_ONE])));
         NVP_s16OffsetAy = (sint16)((uint16)((uint16)((uint16)Data[KU8_TWO] << KU8_EIGHT) | ((uint16)Data[KU8_THREE])));
         NVP_s16OffsetAz = (sint16)((uint16)((uint16)((uint16)Data[KU8_FOUR] << KU8_EIGHT) | ((uint16)Data[KU8_FIVE])));
      }

      /* launch writing data to ram shadow*/
      u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ECS_ACC_OFFSETS, (uint8*)&NVP_s16OffsetAx);

      /* Writing return parse*/
      if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_PENDING;
      }
      else
      {
         if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
         {
            u8Result = E_OK;
            U32_BIT_CLEAR (dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_ACC_OFFSETS);
         }
         else
         {
            u8Result = E_NOT_OK;
            *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            U32_BIT_CLEAR (dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_ACC_OFFSETS);
         }
      }
   }

   return u8Result;
}

/**
 * \brief
 *       Function used to write the eCS profiles definition.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDE3_EcsProfilesData_WriteData
 * \dynamicaspectdescription
 *       Function used to write the eCS profiles definition.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidFDE3_EcsProfilesWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDE3_EcsProfiles_WriteData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 *       ARCH_SW_DIA_pclFsmServices
 **/
EXPORTED Std_ReturnType DIA_runDidFDE3_EcsProfilesWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   uint16 u16BlockSize;
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;
   uint8 u8ProfileTimeoutResult;

   u8Result = E_NOT_OK;
   u8ProfileTimeoutResult = KU8_FALSE;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      /* Verify that no writing is already ongoing */
      if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_ECS_PROFILES))
      {
         U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_PROFILES);
         /* Update RAM */
         Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ECS_PROFILES, &u16BlockSize);
         DIA_CopyData((uint8 *)&NVP_au8EcsProfile_0,Data, u16BlockSize);

      }

      /* launch writing data to ram shadow*/
      u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ECS_PROFILES, (uint8*)&NVP_au8EcsProfile_0);

      /* Writing return parse*/
      if (NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_PENDING;
      }
      else
      {
         if (NVM_REQ_OK == u8ManageNVPBlockWritingResult)
         {
            u8Result = E_OK;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_PROFILES);

            Rte_Call_pclFsmServices_calculateProfileTimeout(&u8ProfileTimeoutResult);
         }
         else
         {
            u8Result = E_NOT_OK;
            *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_PROFILES);
         }
      }
   }

   return (u8Result);
}

/**
 * \brief
 *       Function used to write the eCS steps definition.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType (uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDE4_EcsStepsData_WriteData
 * \dynamicaspectdescription
 *       Function used to write the eCS steps definition.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidFDE4_EcsStepsWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDE4_EcsSteps_WriteData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 *       ARCH_SW_DIA_pclFsmServices
 **/
EXPORTED Std_ReturnType DIA_runDidFDE4_EcsStepsWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   uint16 u16BlockSize;
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;
   uint8 u8ProfileTimeoutResult;

   u8Result = E_NOT_OK;
   u8ProfileTimeoutResult = KU8_FALSE;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      /* Verify that no writing is already ongoing */
      if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_ECS_STEPS))
      {
         U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_STEPS);
         /* Update RAM */
         Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ECS_STEPS, &u16BlockSize);
         DIA_CopyData((uint8 *)&NVP_au8Step_0,Data, u16BlockSize);

      }

      /* launch writing data to ram shadow*/
      u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ECS_STEPS, (uint8*)&NVP_au8Step_0);

      /* Writing return parse*/
      if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_PENDING;
      }
      else
      {
         if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
         {
            u8Result = E_OK;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_STEPS);
            Rte_Call_pclFsmServices_calculateProfileTimeout(&u8ProfileTimeoutResult);
         }
         else
         {
            u8Result = E_NOT_OK;
            *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_STEPS);
         }
      }
   }

   return (u8Result);
}

/**
 * \brief
 *       Function used to write the eCS XYZ lowpass filter.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDE5_EcsAccLowPassData_WriteData
 * \dynamicaspectdescription
 *       Function used to write the eCS XYZ lowpass filter.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidFDE5_EcsAccLowPassWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDE5_EcsAccLowPass_WriteData
 **/
EXPORTED Std_ReturnType DIA_runDidFDE5_EcsAccLowPassWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;

   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      /* Verify that no writing is already ongoing */
      if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_ECS_ACC_LOWPASS))
      {
         U32_BIT_SET (dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_ACC_LOWPASS);
         /* Update RAM */
         NVP_u8XaxisLowPass = Data[KU8_ZERO];
         NVP_u8YaxisLowPass = Data[KU8_ONE];
         NVP_u8ZaxisLowPass = Data[KU8_TWO];
      }

      /* launch writing data to ram shadow*/
      u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ECS_ACC_LOWPASS, (uint8*)&NVP_u8XaxisLowPass);

      /* Writing return parse*/
      if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_PENDING;
      }
      else
      {
         if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
         {
            u8Result = E_OK;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_ACC_LOWPASS);
         }
         else
         {
            u8Result = E_NOT_OK;
            *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_ACC_LOWPASS);
         }
      }
   }

   return u8Result;
}

/**
 * \brief
 *       Write the algo output delay (1 lsb = 1 ms).
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDE7_AlgoOutputDelayData_WriteData
 * \dynamicaspectdescription
 *       Write the algo output delay (1 lsb = 1 ms).
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDIDFDE7_EcsAlgoOutputDelayWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDE7_EcsAlgoOutputDelay_WriteData
 **/
EXPORTED Std_ReturnType DIA_runDIDFDE7_EcsAlgoOutputDelayWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;

   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      /* Verify that no writing is already ongoing */
      if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_ECS_ALGO_OUTPUT_DELAY))
      {
         U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_ALGO_OUTPUT_DELAY);
         /* Update RAM */
         NVP_u16AlgoDelay = (uint16)((uint16)((uint16)Data[KU8_ZERO] << KU8_EIGHT) | (uint16)(Data[KU8_ONE]));
      }

      /* launch writing data to ram shadow*/
      u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ECS_ALGO_OUTPUT_DELAY, (uint8*)&NVP_u16AlgoDelay);

      /* Writing return parse*/
      if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_PENDING;
      }
      else
      {
         if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
         {
            u8Result = E_OK;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_ALGO_OUTPUT_DELAY);
         }
         else
         {
            u8Result = E_NOT_OK;
            *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_ALGO_OUTPUT_DELAY);
         }
      }
   }

   return (u8Result);
}

/**
 * \brief
 *       Function used to write the eCS sensitivity LuT.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDE9_SensitivityLutData_WriteData
 * \dynamicaspectdescription
 *       Function used to write the eCS sensitivity LuT.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		DSG_DIA_runDidFDE9_EcsSensitivityLutWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDE9_EcsSensitivityLut_WriteData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidFDE9_EcsSensitivityLutWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   uint16 u16BlockSize;
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;

   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      /* Verify that no writing is already ongoing */
      if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_ECS_SENSITIVITY_LUT))
      {
         U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_SENSITIVITY_LUT);
         /* Update RAM */
         Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ECS_SENSITIVITY_LUT, &u16BlockSize);
         DIA_CopyDataSwap((uint8 *)&NVP_au16SensitivityIdx[KU8_ZERO],Data, u16BlockSize);

      }

      /* launch writing data to ram shadow*/
      u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ECS_SENSITIVITY_LUT, (uint8*)&NVP_au16SensitivityIdx);

      /* Writing return parse*/
      if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_PENDING;
      }
      else
      {
         if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
         {
            u8Result = E_OK;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_SENSITIVITY_LUT);
         }
         else
         {
            u8Result = E_NOT_OK;
            *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_SENSITIVITY_LUT);
         }
      }
   }

   return (u8Result);
}

/**
 * \brief
 *       Function used to write the eCS sensitivity optimization.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FDEA_SensitivityOptData_WriteData
 * \dynamicaspectdescription
 *       Function used to write the eCS sensitivity optimization.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidFDEA_EcsSensitivityOptWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FDEA_EcsSensitivityOpt_WriteData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidFDEA_EcsSensitivityOptWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;

   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      /* Verify that no writing is already ongoing */
      if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_ECS_SENSITIVITY_OPT))
      {
         U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_SENSITIVITY_OPT);
         /* Update RAM */
         NVP_b8SensitivityOpt = *Data;

      }

      /* launch writing data to ram shadow*/
      u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ECS_SENSITIVITY_OPT, (uint8*)&NVP_b8SensitivityOpt);

      /* Writing return parse*/
      if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_PENDING;
      }
      else
      {
         if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
         {
            u8Result = E_OK;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_SENSITIVITY_OPT);
         }
         else
         {
            u8Result = E_NOT_OK;
            *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_ECS_SENSITIVITY_OPT);
         }
      }
   }

   return (u8Result);
}
/**
 * \brief
 *       Function used to write the VW Spare Part Number.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F187_VWSparePartNumberData_WriteData
 * \dynamicaspectdescription
 *       Write the VW Spare Part Number.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidF187_VWSparePartNumberWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F187_VWSparePartNumber_WriteData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidF187_VWSparePartNumberWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;
   uint16 u16BlockSize;
   boolean ubAsciiResult;

   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      ubAsciiResult = dia_IsAsciiCharAllowedAUDI(Data, sizeof(NVP_au8SparePartNumber), KU8_DIA_DID_F187_DID_F191);
      /* Verify if all the values are in ASCII codes interval */
      if(KB_FALSE == ubAsciiResult)
      {
         u8Result = E_NOT_OK;
         *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      }
      else
      {
         /* Verify that no writing is already ongoing */
         if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_F187))
         {

            U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F187);
            /* Update RAM */

            Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_SPARE_PART_NUMBER, &u16BlockSize);

            DIA_CopyData((uint8 *)&NVP_au8SparePartNumber, Data, u16BlockSize);

         }

         /* launch writing data to ram shadow*/
         u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_SPARE_PART_NUMBER, (uint8*)&NVP_au8SparePartNumber);

         /* Writing return parse*/
         if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
         {
            u8Result = DCM_E_PENDING;
         }
         else
         {
            if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
            {
               u8Result = E_OK;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F187);
            }
            else
            {
               u8Result = E_NOT_OK;
               *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F187);
            }
         }
      }
   }

   return (u8Result);

}
/**
 * \brief
 *       Function used to write the VW Application SW Version Number.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F189_VWApplicationSoftwareVersionNumberData_WriteData
 * \dynamicaspectdescription
 *       Write the VW Application SW Version Number.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidF189_VWApplicationSoftwareVersionNumberWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F189_VWApplicationSoftwareVersionNumber_WriteData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidF189_VWApplicationSoftwareVersionNumberWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;
   uint16 u16BlockSize;
   boolean ubAsciiResult;

   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      ubAsciiResult = dia_IsAsciiCharAllowedAUDI(Data, sizeof(NVP_au8AppSwVersionNumber), KU8_DIA_DID_F189);
      /* Verify if all the values are in ASCII codes interval */
      if(KB_FALSE == ubAsciiResult)
      {
         u8Result = E_NOT_OK;
         *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      }
      else
      {
         /* Verify that no writing is already ongoing */
         if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_F189))
         {
            U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F189);
            /* Update RAM */

            Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_APP_SOFTWARE_VERSION_NUMBER, &u16BlockSize);

            DIA_CopyData((uint8 *)&NVP_au8AppSwVersionNumber, Data, u16BlockSize);

         }

         /* launch writing data to ram shadow*/
         u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_APP_SOFTWARE_VERSION_NUMBER, (uint8*)&NVP_au8AppSwVersionNumber);

         /* Writing return parse*/
         if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
         {
            u8Result = DCM_E_PENDING;
         }
         else
         {
            if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
            {
               u8Result = E_OK;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F189);
            }
            else
            {
               u8Result = E_NOT_OK;
               *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F189);
            }
         }
      }
   }
   return (u8Result);
}
/**
 * \brief
 *       Function used to write the VW ECU Hardware Number.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F191_VWECUHardwareNumberData_WriteData
 * \dynamicaspectdescription
 *       Write VW ECU Hardware Number.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidF191_VWECUHardwareNumberWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F191_VWECUHardwareNumber_WriteData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidF191_VWECUHardwareNumberWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;
   uint16 u16BlockSize;
   boolean ubAsciiResult;

   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      ubAsciiResult = dia_IsAsciiCharAllowedAUDI(Data, sizeof(NVP_au8HardwareNumber), KU8_DIA_DID_F187_DID_F191);
      /* Verify if all the values are in ASCII codes interval */
      if(KB_FALSE == ubAsciiResult)
      {
         u8Result = E_NOT_OK;
         *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      }
      else
      {
         /* Verify that no writing is already ongoing */
         if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_F191))
         {
            U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F191);
            /* Update RAM */

            Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_HARDWARE_NUMBER, &u16BlockSize);

            DIA_CopyData((uint8 *)&NVP_au8HardwareNumber, Data, u16BlockSize);

         }

         /* launch writing data to ram shadow*/
         u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_HARDWARE_NUMBER, (uint8*)&NVP_au8HardwareNumber);

         /* Writing return parse*/
         if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
         {
            u8Result = DCM_E_PENDING;
         }
         else
         {
            if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
            {
               u8Result = E_OK;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F191);
            }
            else
            {
               u8Result = E_NOT_OK;
               *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F191);
            }
         }
      }
   }

   return (u8Result);
}
/**
 * \brief
 *       Function used to write the VW System Name.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F197_VWSystemNameOrEngineTypeData_WriteData
 * \dynamicaspectdescription
 *       Write VW System Name.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidF197_VWSystemNameOrEngineTypeWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F197_VWSystemNameOrEngineType_WriteData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidF197_VWSystemNameOrEngineTypeWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;
   uint16 u16BlockSize;
   boolean ubAsciiResult;

   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      ubAsciiResult = dia_IsAsciiCharAllowedAUDI(Data, sizeof(NVP_au8SystemName), KU8_DIA_DID_F18C_DID_F197);
      /* Verify if all the values are in ASCII codes interval */
      if(KB_FALSE == ubAsciiResult)
      {
         u8Result = E_NOT_OK;
         *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      }
      else
      {
         /* Verify that no writing is already ongoing */
         if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_F197))
         {
            U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F197);
            /* Update RAM */

            Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_SYSTEM_NAME_OR_ENGINE_TYPE, &u16BlockSize);

            DIA_CopyData((uint8 *)&NVP_au8SystemName, Data, u16BlockSize);

         }

         /* launch writing data to ram shadow*/
         u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_SYSTEM_NAME_OR_ENGINE_TYPE, (uint8*)&NVP_au8SystemName);

         /* Writing return parse*/
         if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
         {
            u8Result = DCM_E_PENDING;
         }
         else
         {
            if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
            {
               u8Result = E_OK;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F197);
            }
            else
            {
               u8Result = E_NOT_OK;
               *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F197);
            }
         }
      }
   }

   return (u8Result);
}
/**
 * \brief
 *       Function used to write the Bootloader TP size.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_0410_BootloaderTPBlocksizeData_WriteData
 * \dynamicaspectdescription
 *       Write Bootloader TP size.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDid0410_BootloaderTPBlocksizeWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_0410_BootloaderTPBlocksize_WriteData
 **/
EXPORTED Std_ReturnType DIA_runDid0410_BootloaderTPBlocksizeWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   DIA_u8BootTpSize = *Data;

   return ((Std_ReturnType)RTE_E_OK);
}
/**
 * \brief
 *       Function used to write the ASAM ODX file identifier.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F19E_ASAMODXFileIdentifierData_WriteData
 * \dynamicaspectdescription
 *       Write ASAM ODX file identifier.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidF19E_ASAMODXFileIdentifierWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F19E_ASAMODXFileIdentifier_WriteData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidF19E_ASAMODXFileIdentifierWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;
   uint16 u16BlockSize;
   boolean ubAsciiResult;

   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      ubAsciiResult = dia_IsAsciiCharAllowedAUDI(Data, sizeof(NVP_au8ODXFileIdentifier), KU8_DIA_DID_F19E);
      /* Verify if all the values are in ASCII codes interval */
      if(KB_FALSE == ubAsciiResult)
      {
         u8Result = E_NOT_OK;
         *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      }
      else
      {
         /* Verify that no writing is already ongoing */
         if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_F19E))
         {
            U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F19E);
            /* Update RAM */

            Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ODX_FILE_IDENTIFIER, &u16BlockSize);

            DIA_CopyData((uint8 *)&NVP_au8ODXFileIdentifier, Data, u16BlockSize);

         }

         /* launch writing data to ram shadow*/
         u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ODX_FILE_IDENTIFIER, (uint8*)&NVP_au8ODXFileIdentifier);

         /* Writing return parse*/
         if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
         {
            u8Result = DCM_E_PENDING;
         }
         else
         {
            if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
            {
               u8Result = E_OK;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F19E);
            }
            else
            {
               u8Result = E_NOT_OK;
               *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F19E);
            }
         }
      }
   }

   return (u8Result);
}
/**
 * \brief
 *       Function used to write the ASAM ODX file version.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F1A2_ASAMODXFileVersionData_WriteData
 * \dynamicaspectdescription
 *       Write ASAM ODX file version.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidF1A2_ASAMODXFileVersionWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F1A2_ASAMODXFileVersion_WriteData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidF1A2_ASAMODXFileVersionWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;
   uint16 u16BlockSize;
   boolean ubAsciiResult;

   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      ubAsciiResult = dia_IsAsciiCharAllowedAUDI(Data, sizeof(NVP_au8ODXFileVersion), KU8_DIA_DID_F1A2);
      /* Verify if all the values are in ASCII codes interval */
      if(KB_FALSE == ubAsciiResult)
      {
         u8Result = E_NOT_OK;
         *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      }
      else
      {
         /* Verify that no writing is already ongoing */
         if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_F1A2))
         {
            U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F1A2);
            /* Update RAM */

            Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ODX_FILE_VERSION, &u16BlockSize);

            DIA_CopyData((uint8 *)&NVP_au8ODXFileVersion, Data, u16BlockSize);

         }

         /* launch writing data to ram shadow*/
         u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ODX_FILE_VERSION, (uint8*)&NVP_au8ODXFileVersion);

         /* Writing return parse*/
         if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
         {
            u8Result = DCM_E_PENDING;
         }
         else
         {
            if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
            {
               u8Result = E_OK;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F1A2);
            }
            else
            {
               u8Result = E_NOT_OK;
               *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F1A2);
            }
         }
      }
   }

   return (u8Result);
}
/**
 * \brief
 *       Function used to write the ECU Serial Number.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F18C_ECUSerialNumberData_WriteData
 * \dynamicaspectdescription
 *       Write ECU Serial Number.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidF18C_ECUSerialNumberWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F18C_ECUSerialNumberData_WriteData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidF18C_ECUSerialNumberWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;
   uint16 u16BlockSize;
   boolean ubAsciiResult;

   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      ubAsciiResult = dia_IsAsciiCharAllowedAUDI(Data, sizeof(NVP_au8ECUSerialNumber), KU8_DIA_DID_F18C_DID_F197);
      /* Verify if all the values are in ASCII codes interval */
      if(KB_FALSE == ubAsciiResult)
      {
         u8Result = E_NOT_OK;
         *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      }
      else
      {
         /* Verify that no writing is already ongoing */
         if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_F18C))
         {
            U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F18C);
            /* Update RAM */

            Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_ECU_SERIAL_NUMBER, &u16BlockSize);

            DIA_CopyData((uint8 *)&NVP_au8ECUSerialNumber, Data, u16BlockSize);

         }

         /* launch writing data to ram shadow*/
         u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ECU_SERIAL_NUMBER, (uint8*)&NVP_au8ECUSerialNumber);

         /* Writing return parse*/
         if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
         {
            u8Result = DCM_E_PENDING;
         }
         else
         {
            if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
            {
               u8Result = E_OK;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F18C);
            }
            else
            {
               u8Result = E_NOT_OK;
               *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F18C);
            }
         }
      }
   }

   return (u8Result);
}
/**
 * \brief
 *       Function used to write the HW version number.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_F1A3_VWECUHardwareVersionNumberData_WriteData
 * \dynamicaspectdescription
 *       Write HW version number.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *		   DSG_DIA_runDidF1A3_VWECUHardwareVersionNumberWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_F1A3_VWECUHardwareVersionNumber_WriteData
 *       ARCH_SW_DIA_pclNvmIfServices_GetNvmBlockLength
 **/
EXPORTED Std_ReturnType DIA_runDidF1A3_VWECUHardwareVersionNumberWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;
   uint16 u16BlockSize;
   boolean ubAsciiResult;
   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      ubAsciiResult = dia_IsAsciiCharAllowedAUDI(Data, sizeof(NVP_au8HardwareVersionNumber), KU8_DIA_DID_F1A3);
      /* Verify if all the values are in ASCII codes interval */
      if(KB_FALSE == ubAsciiResult)
      {
         u8Result = E_NOT_OK;
         *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      }
      else
      {
         /* Verify that no writing is already ongoing */
         if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_F1A3))
         {
            U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F1A3);
            /* Update RAM */

            Rte_Call_pclNvmIfServices_GetNvmBlockLength(NvMConf_NvMBlockDescriptor_HARDWARE_VERSION_NUMBER, &u16BlockSize);

            DIA_CopyData((uint8 *)&NVP_au8HardwareVersionNumber, Data, u16BlockSize);

         }

         /* launch writing data to ram shadow*/
         u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_HARDWARE_VERSION_NUMBER, (uint8*)&NVP_au8HardwareVersionNumber);

         /* Writing return parse*/
         if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
         {
            u8Result = DCM_E_PENDING;
         }
         else
         {
            if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
            {
               u8Result = E_OK;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F1A3);
            }
            else
            {
               u8Result = E_NOT_OK;
               *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_F1A3);
            }
         }
      }
   }

   return (u8Result);
}

/**
 * \brief
 *       Function used to write the Manufacturing Date.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FD8B_ECUManufacturingDateData_WriteData
 * \dynamicaspectdescription
 *       Write HW version number.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *       DSG_DIA_runDidFD8B_ECUManufacturingDateWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FD8B_ECUManufacturingDateWrite
 **/
EXPORTED Std_ReturnType DIA_runDidFD8B_ECUManufacturingDateWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;
   boolean ubBCDYearResult;
   boolean ubBCDMonthResult;
   boolean ubBCDDayResult;
   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      ubBCDYearResult = dia_CheckBCD(*(Data + KU8_DIA_MANUFACTURING_DATE_YEAR_INDEX));
      ubBCDMonthResult = dia_CheckBCD(*(Data + KU8_DIA_MANUFACTURING_DATE_MONTH_INDEX));
      ubBCDDayResult = dia_CheckBCD(*(Data + KU8_DIA_MANUFACTURING_DATE_DAY_INDEX));
      /* Verify if the format of date is in BCD format */
      if((KB_TRUE != ubBCDYearResult) ||
            (KU8_ONE > *(Data + KU8_DIA_MANUFACTURING_DATE_MONTH_INDEX)) ||
            (KU8_DIA_MANUFACTURING_DATE_MAX_MONTH_VALUE < *(Data + KU8_DIA_MANUFACTURING_DATE_MONTH_INDEX)) ||
            (KB_TRUE != ubBCDMonthResult) ||
            (KU8_ONE > *(Data + KU8_DIA_MANUFACTURING_DATE_DAY_INDEX)) ||
            (KU8_DIA_MANUFACTURING_DATE_MAX_DAY_VALUE < *(Data + KU8_DIA_MANUFACTURING_DATE_DAY_INDEX)) ||
            (KB_TRUE != ubBCDDayResult))
      {
         u8Result = E_NOT_OK;
         *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      }
      else
      {
         /* Verify that no writing is already ongoing */
         if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_FD8B))
         {
            U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_FD8B);
            /* Update RAM */
            DIA_CopyData((uint8 *)&NVP_u8AssemblyManufacturingYear, Data, KU8_THREE);

         }

         /* launch writing data to ram shadow*/
         u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ECU_ASSEMBLY_SERIAL_NUMBER, (uint8*)&NVP_u8AssemblyManufacturingYear);

         /* Writing return parse*/
         if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
         {
            u8Result = DCM_E_PENDING;
         }
         else
         {
            if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
            {
               u8Result = E_OK;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_FD8B);
            }
            else
            {
               u8Result = E_NOT_OK;
               *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
               U32_BIT_CLEAR(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_FD8B);
            }
         }
      }
   }

   return (u8Result);
}

/**
 * \brief
 *       Function used to write the AEE Traceability Nb.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_FD03_AEETraceabilityNumberData_WriteData
 * \dynamicaspectdescription
 *       Write AEE traceability number.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *       DSG_DIA_runDidFD03_AEETraceabilityNumberWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_FD03_AEETraceabilityNumberWrite
 **/
EXPORTED Std_ReturnType DIA_runDidFD03_AEETraceabilityNumberWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   /* Counter to go through all the Serial Number bytes */
   uint8 u8ByteIndex;
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;

   u8Result = E_NOT_OK;

   /* Check ECU LOCK before processing */
   if(KU8_ECU_UNLOCK != NVP_u8ECUUnlock)
   {
      u8Result = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   else
   {
      /* Verify that no writing is already ongoing */
      if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_FD03))
      {
         U32_BIT_SET(dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_FD03);

         /* Complete the array with the received number*/
         for (u8ByteIndex = KU8_ZERO ; u8ByteIndex < KU8_DIA_NVP_AEE_TRACEABILITY_NB_BLOCK_SIZE; u8ByteIndex++)
         {
            NVP_au8AEE_TRACEABILITY_NUM[u8ByteIndex] = *(Data + u8ByteIndex);
         }
      }

      /* launch writing data to ram shadow*/
      u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_AEE_TRACEABILITY_NUMBER, (uint8*)&NVP_au8AEE_TRACEABILITY_NUM);

      /* Writing return parse*/
      if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
      {
         u8Result = DCM_E_PENDING;
      }
      else
      {
         if(NVM_REQ_OK == u8ManageNVPBlockWritingResult)
         {
            u8Result = E_OK;
            U32_BIT_CLEAR (dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_FD03);
         }
         else
         {
            u8Result = E_NOT_OK;
            *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            U32_BIT_CLEAR (dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_FD03);
         }
      }
   }

   return u8Result;

}

/**
 * \brief
 *       Function used to write the eCS parameters.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_0236_ProgrammingDataElockEcuData_WriteData
 * \dynamicaspectdescription
 *       Write eCS parameters.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *       DSG_DIA_run_Did0236_ProgrammingDataElockEcuWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_0236_ProgrammingDataElockEcu_WriteData
 **/
EXPORTED Std_ReturnType DIA_run_Did0236_ProgrammingDataElockEcuWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint32 u32pWakeupReqValue;
   uint8 u8Index;


   u8Result = E_NOT_OK;

   /* Verify that no writing is already ongoing */
   if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_0236))
   {
      U32_BIT_SET (dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_0236);

      /* Get data what is necessary to be written */
      /* NVM_BLOCK_ACC_AXIS_ANGLE_CALIBRATION Block */
      NVP_u16XAxisAngleCalib = (uint16)((uint16)((uint16)Data[KU8_ZERO] << KU8_EIGHT) | (uint16)(Data[KU8_ONE]));
      NVP_u16YAxisAngleCalib = (uint16)((uint16)((uint16)Data[KU8_TWO] << KU8_EIGHT) | (uint16)(Data[KU8_THREE]));

      /* NVM_BLOCK_ECS_VARIANT */
      dia_u32eCSVariantConfigData = NVP_u32eCSVariant;

      for(u8Index = KU8_FOUR; u8Index < KU8_TWENTYONE; u8Index++)
      {
         if(KU8_ONE == (Data[u8Index] & KU8_ONE))
         {
            dia_u32eCSVariantConfigData |= (uint32)((uint32)KU8_ONE << (u8Index - KU8_TWO));
         }
         else
         {
            dia_u32eCSVariantConfigData &= (uint32)(~((uint32)KU8_ONE << (u8Index - KU8_TWO)));
         }

      }

      /* NVM_BLOCK_ECU_STATE_TIMING_PARAMETERS */
      NVP_u32TLowPower = (uint32)(((uint32)(Data[KU8_THIRTYTWO])) |
            ((uint32)(Data[KU8_THIRTYONE]) << KU8_POS_L_LOW_MIDDLE_BYTE) |
            ((uint32)(Data[KU8_THIRTY]) << KU8_POS_L_HIGH_MIDDLE_BYTE) |
            ((uint32)(Data[KU8_TWENTYNINE]) << KU8_POS_L_HIGH_BYTE));

      /* Compute TPW */
      u32pWakeupReqValue = (uint32)(((uint32)(Data[KU8_TWENTYEIGHT])) |
            ((uint32)(Data[KU8_TWENTYSEVEN]) << KU8_POS_L_LOW_MIDDLE_BYTE) |
            ((uint32)(Data[KU8_TWENTYSIX]) << KU8_POS_L_HIGH_MIDDLE_BYTE) |
            ((uint32)(Data[KU8_TWENTYFIVE]) << KU8_POS_L_HIGH_BYTE));

      NVP_u32TPostRun = u32pWakeupReqValue - KU32_DIA_TX_TIMEOUT;

      NVP_u32TPassengerWakeup = (uint32)(((uint32)(Data[KU8_TWENTYFOUR])) |
            ((uint32)(Data[KU8_TWENTYTHREE]) << KU8_POS_L_LOW_MIDDLE_BYTE) |
            ((uint32)(Data[KU8_TWENTYTWO]) << KU8_POS_L_HIGH_MIDDLE_BYTE) |
            ((uint32)(Data[KU8_TWENTYONE]) << KU8_POS_L_HIGH_BYTE));
   }

   /* launch writing data to ram shadow*/
   if(NVM_REQ_OK != dia_u8ManageNVPAccAxisBlockWritingResult)
   {
      dia_u8ManageNVPAccAxisBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ACC_AXIS_ANGLE_CALIBRATION, (uint8*)&NVP_u16XAxisAngleCalib);
   }

   /* Writing return parse*/
   if(NVM_REQ_PENDING == dia_u8ManageNVPAccAxisBlockWritingResult)
   {
      u8Result = DCM_E_PENDING;
   }
   else
   {
      if(NVM_REQ_OK == dia_u8ManageNVPAccAxisBlockWritingResult)
      {
         if(NVM_REQ_OK != dia_u8ManageNVPeCSVariantBlockWritingResult)
         {
            /* NVM_BLOCK_ACC_AXIS_ANGLE_CALIBRATION write done, continue with the next block */
            dia_u8ManageNVPeCSVariantBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ECS_VARIANT, (uint8*)&dia_u32eCSVariantConfigData);
         }

         /* Writing return parse*/
         if(NVM_REQ_PENDING == dia_u8ManageNVPeCSVariantBlockWritingResult)
         {
            u8Result = DCM_E_PENDING;
         }
         else
         {
            if(NVM_REQ_OK == dia_u8ManageNVPeCSVariantBlockWritingResult)
            {
               /*trigger last block*/
               if(NVM_REQ_OK != dia_u8ManageNVPEcuTimingParametersBlockWritingResult)
               {
                  /* NVM_BLOCK_ACC_AXIS_ANGLE_CALIBRATION write done, continue with the next block */
                  dia_u8ManageNVPEcuTimingParametersBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ECU_STATE_TIMING_PARAMETERS, (uint8*)&NVP_u32TPostRun);
               }
               /* Writing return parse*/
               if(NVM_REQ_PENDING == dia_u8ManageNVPEcuTimingParametersBlockWritingResult)
               {
                  u8Result = DCM_E_PENDING;
               }
               else
               {
                  if(NVM_REQ_OK == dia_u8ManageNVPEcuTimingParametersBlockWritingResult)
                  {
                     u8Result = E_OK;
                     U32_BIT_CLEAR (dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_0236);
                     dia_u8ManageNVPEcuTimingParametersBlockWritingResult = E_NOT_OK;
                     dia_u8ManageNVPeCSVariantBlockWritingResult = E_NOT_OK;
                     dia_u8ManageNVPAccAxisBlockWritingResult = E_NOT_OK;
                  }
                  else
                  {
                     u8Result = E_NOT_OK;
                     *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                     U32_BIT_CLEAR (dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_0236);
                     dia_u8ManageNVPeCSVariantBlockWritingResult = E_NOT_OK;
                     dia_u8ManageNVPAccAxisBlockWritingResult = E_NOT_OK;
                  }
               }

            }
            else
            {
               u8Result = E_NOT_OK;
               *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
               U32_BIT_CLEAR (dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_0236);
               dia_u8ManageNVPAccAxisBlockWritingResult = E_NOT_OK;
            }
         }
      }
      else
      {
         u8Result = E_NOT_OK;
         *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
         U32_BIT_CLEAR (dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_0236);
      }
   }

   return u8Result;
}

/**
 * \brief
 *       Function used to Function used to write the eCS variant.
 * \inputparam
 *       Name: Data;
 *       Type: P2CONST (uint8*);
 *       Description: Data to be written;
 *       Range: 0..KU8_MAX;
 * \inputparam
 *       Name: OpStatus;
 *       Type: Dcm_OpStatusType(uint8);
 *       Description: This parameter is not used (default generated by autosar);
 *       Range: 0..KU8_MAX;
 * \outputparam
 *       Name: ErrorCode;
 *       Type: P2VAR (uint8);
 *       Description: DCM error code;
 *       Range: 0..KU8_MAX;
 * \exception
 *       This function has no exceptions.
 * \pre
 *       This function has no preconditions.
 * \post
 *       This function has no postconditions.
 * \return
 *       Service result.
 * \dynamicaspectcaller
 *       Rte_Call_Dcm_DataServices_DID_023E_WSCForProgrammingElockEcuData_WriteData
 * \dynamicaspectdescription
 *       Write eCS variant.
 * \constrains
 *       Service result is:
 *          o E_OK;
 *          o E_NOT_OK;
 *          o DCM_E_PENDING;
 * \ddesignrequirement
 *       DSG_DIA_run_Did023E_WSCForProgrammingElockEcuWrite
 * \archrequirement
 *       ARCH_SW_DIA_pseDID_023E_WSCForProgrammingElockEcu_WriteData
 **/
EXPORTED Std_ReturnType DIA_run_Did023E_WSCForProgrammingElockEcuWrite (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{
   Std_ReturnType u8Result;
   uint8 u8ManageNVPBlockWritingResult;
   u8Result = E_NOT_OK;

   /* Verify that no writing is already ongoing */
   if(KU32_ZERO == (dia_u32WriteNVPBlockStatusFlag & KU32_DIA_BIT_MASK_023E))
   {
      U32_BIT_SET (dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_023E);
      /* update RAM */
      NVP_u32eCSCodingVariant = (uint32)(((uint32)(Data[KU8_FIVE])) |
                                ((uint32)(Data[KU8_FOUR]) << KU8_POS_L_LOW_MIDDLE_BYTE) |
                                ((uint32)(Data[KU8_THREE]) << KU8_POS_L_HIGH_MIDDLE_BYTE) |
                                ((uint32)(Data[KU8_TWO]) << KU8_POS_L_HIGH_BYTE));
      NVP_u8Reserved[KU8_ZERO] = KU8_ZERO;
      NVP_u8Reserved[KU8_ONE] = KU8_ZERO;
   }

   /* launch writing data to ram shadow*/
   u8ManageNVPBlockWritingResult = DIA_ManageNVPBlockWriting(NvMConf_NvMBlockDescriptor_ECS_CODING_VARIANT, (uint8*)&NVP_u32eCSCodingVariant);

   /* Writing return parse*/
   if(NVM_REQ_PENDING == u8ManageNVPBlockWritingResult)
   {
      u8Result = DCM_E_PENDING;
   }
   else
   {
      if (NVM_REQ_OK == u8ManageNVPBlockWritingResult)
      {
         u8Result = E_OK;
         U32_BIT_CLEAR (dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_023E);
      }
      else
      {
         u8Result = E_NOT_OK;
         *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
         U32_BIT_CLEAR (dia_u32WriteNVPBlockStatusFlag, KU32_DIA_BIT_MASK_023E);
      }
   }


   return u8Result;
}

#define DIA_STOP_SEC_CODE
#include "DIA_MemMap.h"

/*************************************************************************
 Evolution of the component

 created by : T. DEMIREL

 $Log: DIA_WriteDataByIdentifier.c  $
 Revision 1.3.11.48 2023/08/01 10:09:23CEST Gabriel Brasoveanu (gabriel.brasoveanu) 
 Update code after integration of new EB packages
 Revision 1.3.11.47 2023/07/17 13:35:57EEST Andreea Suiu (andreea.suiu) 
 update traceability
 Revision 1.3.11.46 2023/07/14 14:50:18EEST Andreea Suiu (andreea.suiu) 
 remove unused variables
 Revision 1.3.11.45 2023/07/11 16:59:55EEST Andreea Suiu (andreea.suiu) 
 update comments, update 0236 write
 Revision 1.3.11.44 2023/06/29 12:47:18EEST Andreea Suiu (andreea.suiu) 
 change indentation
 Revision 1.3.11.43 2023/06/28 16:00:26EEST Andreea Suiu (andreea.suiu) 
 change block id for 023e
 Revision 1.3.11.42 2023/06/28 15:17:21EEST Andreea Suiu (andreea.suiu) 
 change NVP variable for 023e did
 Revision 1.3.11.41 2023/06/28 10:44:20EEST Andreea Suiu (andreea.suiu) 
 fix fd8c did
 Revision 1.3.11.40 2023/06/27 10:43:18EEST Andreea Suiu (andreea.suiu) 
 add 2 variables for ECS_PARAMETERS block
 Revision 1.3.11.39 2023/06/22 14:07:13EEST Andreea Suiu (andreea.suiu) 
 update src files (fix findings) after review
 Revision 1.3.11.38 2023/06/21 14:45:51EEST Andreea Suiu (andreea.suiu) 
 cast to uint32 to avoid the qac warnings
 Revision 1.3.11.37 2023/06/21 14:14:52EEST Andreea Suiu (andreea.suiu) 
 add write for dids 0236, 023e
 Revision 1.3.11.35 2023/06/15 16:13:19EEST Andreea Suiu (andreea.suiu) 
 add AEE traceability Nb for write
 change AEE traceability Nb for read
 Revision 1.3.11.34 2023/06/12 09:17:02EEST Mihai Motoc (mihai.motoc) 
 Doxygen comments updates
 Revision 1.3.11.33 2023/06/08 09:35:46EEST Mihai Motoc (mihai.motoc) 
 Doxygen comments updates
 Revision 1.3.11.32 2023/05/11 14:21:27EEST Ioan Repede (ioan.repede) 
 Delete pragma optimize
 Revision 1.3.11.31 2023/05/03 10:03:10EEST Andreea Suiu (andreea.suiu) 
 change data access interface for fd8b
 Revision 1.3.11.30 2023/05/02 15:34:25EEST Andreea Suiu (andreea.suiu) 
 change B_TRUE/B_FALSE to KB_TRUE/KB_FALSE
 Revision 1.3.11.29 2023/05/02 13:55:07EEST Andreea Suiu (andreea.suiu) 
 add write subfunction for did fd8b, add local functin to check if data is BCD fomrat
 Revision 1.3.11.28 2023/04/28 14:59:12EEST Andreea Suiu (andreea.suiu) 
 update fd10 did
 Revision 1.3.11.27 2023/04/25 09:13:03EEST Andreea Suiu (andreea.suiu) 
 Fix DIA after review
 Revision 1.3.11.26 2023/04/18 18:22:01EEST Andreea Suiu (andreea.suiu) 
 Update DIA module according to the coding rules
 Revision 1.3.11.25 2023/04/18 18:08:09EEST Andreea Suiu (andreea.suiu) 
 Update DIA module according to the coding rules
 Revision 1.3.11.24 2023/04/18 16:39:04EEST Andreea Suiu (andreea.suiu) 
 Fix DIA module after review
 Revision 1.3.11.23 2023/04/18 14:22:05EEST Andreea Suiu (andreea.suiu) 
 add parantheses to fix qac warning
 Revision 1.3.11.22 2023/04/13 16:44:17EEST Andreea Suiu (andreea.suiu) 
 add byte swapping
 Revision 1.3.11.21 2023/04/10 15:51:59EEST Andreea Suiu (andreea.suiu) 
 - change SW version
 - change ascii conditions for F1A3, F189
 Revision 1.3.11.20 2023/04/06 13:26:31EEST Andreea Suiu (andreea.suiu) 
 Add ascii restrictions (first version)
 Revision 1.3.11.18 2023/03/30 07:43:41EEST Dan Dustinta (dan.dustinta) 
 fix variable definition
 Revision 1.3.11.17 2023/03/16 14:25:32EET Andreea Suiu (andreea.suiu) 
 Update F1A2 DID
 Revision 1.3.11.16 2023/03/16 14:22:05EET Andreea Suiu (andreea.suiu) 
 Update F1A3 DID
 Revision 1.3.11.15 2023/03/16 10:45:12EET Andreea Suiu (andreea.suiu) 
 Update F18C DID
 Revision 1.3.11.14 2023/03/15 10:15:20EET Andreea Suiu (andreea.suiu) 
 Add OEM diagnostics
 Revision 1.3.11.13 2023/02/28 18:06:43EET Septimiu Vintila (septimiu.vintila) 
 FuSa section reverted to normal one.
 Revision 1.3.11.12 2023/02/28 17:15:02EET Septimiu Vintila (septimiu.vintila) 
 Data sections changed to FuSa data sections.
 Revision 1.3.11.11 2023/02/28 16:35:52EET Septimiu Vintila (septimiu.vintila) 
 Code sections changed to FuSa code sections.
 Revision 1.3.11.10 2023/02/24 13:58:54EET Andreea Suiu (andreea.suiu) 
 Update DIA after QAC
 Revision 1.3.11.9 2023/02/23 16:17:51EET Andreea Suiu (andreea.suiu) 
 Update diagnostic services (add NRCs)
 Revision 1.3.11.8 2023/01/23 16:10:26EET Denis Folea (denis.folea) 
 DIA fix after review
 Revision 1.3.11.7 2023/01/20 15:24:05EET Denis Folea (denis.folea) 
 DIA fix after review
 Revision 1.3.11.6 2023/01/13 09:08:39EET Dan Dustinta (dan.dustinta) 
 update byte swap
 Revision 1.3.11.5 2023/01/12 13:54:27EET Ioan Repede (ioan.repede) 
 Add RTE callback to FSM_runCalculateProfileTimeout from FSM in FDE3 and FDE4.
 Revision 1.3.11.4 2022/12/22 16:28:53EET Andrei Anca (andrei.anca) 
 Dia cleanup
 Revision 1.3.11.3 2022/11/25 12:47:57EET Dan Dustinta (dan.dustinta) 
 update DCM integration code
 Revision 1.1 2021/09/06 10:17:26EEST Pierre-Olivier Pilot (pierre-olivier.pilot) 
 Initial revision


 *************************************************************************/

/******************************************************************************
End Of File
 *****************************************************************************/
