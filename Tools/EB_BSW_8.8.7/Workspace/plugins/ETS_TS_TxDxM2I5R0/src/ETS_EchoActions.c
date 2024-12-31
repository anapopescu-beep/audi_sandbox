/**
 * \file
 *
 * \brief AUTOSAR ETS
 *
 * This file contains the implementation of the AUTOSAR
 * module ETS.
 *
 * \version 2.5.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*  MISRA-C:2012 Deviation List
 *
 *   MISRAC2012-1) Deviated Rule: 1.2 (Advisory)
 *     Language extensions should not be used.
 *
 *     Reason:
 *     Type of variable is defined in ARXML as (s|u| )int64.
 */
/* ==================[Includes]=============================================== */

#include <string.h>
#include <ETS_Services.h>
#include <ETS_Cfg.h>
#include <Rte_Type.h>
#include <Rte_ETS.h>
#include <ETS_Types.h>
#include <TSMem.h>

/*==================[macros]======================================================================*/

/*==================[type definitions]============================================================*/

typedef struct {
  uint8 fctidin;
  uint32 ulValueIn;
  uint8 ucValueOut8;
  uint16 usValueOut16;
  uint32 ulValueOut32;
}ETS_Bitfield_MappingType;

/*==================[external function declarations]==============================================*/

/*==================[internal function declarations]==============================================*/

#define ETS_START_SEC_CODE
#include <ETS_MemMap.h>

#define ETS_STOP_SEC_CODE
#include <ETS_MemMap.h>

/*==================[external constants]==========================================================*/

/*==================[internal constants]==========================================================*/

/*==================[external data]===============================================================*/

/*==================[internal data]===============================================================*/

/*==================[external function definitions]===============================================*/

#define ETS_START_SEC_CODE
#include <ETS_MemMap.h>

/**
 * \brief Echoes common datatypes back to sender.
 *
 * \param[in] bOOLEAN_in boolean
 * \param[in] uINT8_in uint8
 * \param[in] uINT16_in uint16
 * \param[in] uINT32_in uint32
 * \param[in] iNT32_in sint32
 * \param[in] fLOAT32_in float32
 * \param[in] fLOAT64_in float64
 * \param[out] fLOAT64_out float64
 * \param[out] fLOAT32_out float32
 * \param[out] iNT32_out sint32
 * \param[out] iNT16_out sint16
 * \param[out] iNT8_out sint8
 * \param[out] uint32 uint32
 * \param[out] uINT16_out uint16
 * \param[out] uINT8_out uint8
 * \param[out] bOOLEAN_out boolean
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0006, 1 */
#if ( ETS_Echo_CommonDatatypes == TRUE )
FUNC(void, RTE_CODE) ETS_EchoCommonDatatypes 
(boolean bOOLEAN_in, 
uint8 uINT8_in, uint16 uINT16_in, 
uint32 uINT32_in, sint8 iNT8_in, 
sint16 iNT16_in, sint32 iNT32_in, 
float32 fLOAT32_in, float64 fLOAT64_in, 
P2VAR(float64, AUTOMATIC, RTE_APPL_DATA) fLOAT64_out, P2VAR(float32, AUTOMATIC, RTE_APPL_DATA) fLOAT32_out, 
P2VAR(sint32, AUTOMATIC, RTE_APPL_DATA) iNT32_out, P2VAR(sint16, AUTOMATIC, RTE_APPL_DATA) iNT16_out, 
P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) iNT8_out, P2VAR(uint32, AUTOMATIC, RTE_APPL_DATA) uINT32_out, 
P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) uINT16_out, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) uINT8_out, 
P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) bOOLEAN_out)
{
  *fLOAT64_out = fLOAT64_in;
  *fLOAT32_out = fLOAT32_in;
  *iNT32_out = iNT32_in;
  *iNT16_out = iNT16_in;
  *iNT8_out = iNT8_in;
  *uINT32_out = uINT32_in;
  *uINT16_out = uINT16_in;
  *uINT8_out = uINT8_in;
  *bOOLEAN_out = bOOLEAN_in;
}
#endif

/**
 * \brief Echoes uint8 back to sender.
 *
 * \param[in] Uint8Value uint8
 * \param[out] Uint8ReturnValue uint8
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0019, 1 */
#if ( ETS_Echo_UINT8 == TRUE )
FUNC(void, RTE_CODE) ETS_EchoUINT8 (uint8 Uint8Value, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Uint8ReturnValue)
{
  *Uint8ReturnValue = Uint8Value;
}
#endif

/**
 * \brief Echoes uint64 back to sender.
 *
 * \param[in] Uint64Value uint64
 * \param[out] Uint64ReturnValue uint64
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0018, 1 */
#if ( ETS_Echo_UINT64 == TRUE )
/* Deviation MISRAC2012-1 */
FUNC(void, RTE_CODE) ETS_EchoUINT64 (uint64 Uint64Value, P2VAR(uint64, AUTOMATIC, RTE_APPL_DATA) Uint64ReturnValue)
{
  *Uint64ReturnValue = Uint64Value;
}
#endif

/**
 * \brief Echoes int8 back to sender.
 *
 * \param[in] Int8Value sint8
 * \param[out] Int8ReturnValue sint8
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0013, 1 */
#if ( ETS_Echo_INT8 == TRUE )
FUNC(void, RTE_CODE) ETS_EchoINT8 (sint8 Int8Value, P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) Int8ReturnValue)
{
  *Int8ReturnValue = Int8Value;
}
#endif

/**
 * \brief Echoes ENUMValue back to sender.
 *
 * \param[in] ENUMValue uint8
 * \param[out] ENUMReturnValue uint8
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0007, 1 */
#if ( ETS_Echo_ENUM == TRUE )
FUNC(void, RTE_CODE) ETS_EchoENUM (uint8 ENUMValue, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) ENUMReturnValue)
{
  *ENUMReturnValue = ENUMValue;
}
#endif

/**
 * \brief Echoes uint8Array back to sender.
 *
 * \param[out] uint8Array ETS_Uint8Array
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0020, 1 */
#if ( ETS_Echo_UINT8Array == TRUE )
FUNC(void, RTE_CODE) ETS_EchoUINT8Array (P2VAR(ETS_Uint8Array, AUTOMATIC, RTE_APPL_DATA) uint8Array)
{
  /* suppress compiler warnings about unused arguments */
  (void)*uint8Array;
}
#endif

/**
 * \brief Echoes StaticUINT8Array back to sender.
 *
 * \param[in] ES_uINT8Array uint8
 * \param[out] ES_uINT8ArrayReturnValue uint8
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0014, 1 */
#if ( ETS_Echo_StaticUINT8Array == TRUE )
FUNC(void, RTE_CODE) ETS_EchoStaticUINT8Array (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) ES_uINT8Array, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) ES_uINT8ArrayReturnValue)
{
  ES_uINT8ArrayReturnValue[0] = ES_uINT8Array[0];
  ES_uINT8ArrayReturnValue[1] = ES_uINT8Array[1];
  ES_uINT8ArrayReturnValue[2] = ES_uINT8Array[2];
  ES_uINT8ArrayReturnValue[3] = ES_uINT8Array[3];
  ES_uINT8ArrayReturnValue[4] = ES_uINT8Array[4];
}
#endif

/**
 * \brief Echoes bitfield back to sender.
 *
 * \param[in] bitfield8_in ETS_Bitfield_uint8_tr
 * \param[in] bitfield16_in ETS_Bitfield_uint16_tr
 * \param[in] bitfield32_in ETS_Bitfield_uint32_tr
 * \param[out] bitfield8_out ETS_Bitfield_uint8_return_tr
 * \param[out] bitfield16_out ETS_Bitfield_uint16_return_tr
 * \param[out] bitfield32_out ETS_Bitfield_uint32_return_tr
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0042, 1 */
#if ( ETS_Echo_Bitfields == TRUE )
FUNC(void, RTE_CODE) ETS_EchoBitfields (ETS_Bitfield_uint8_tr bitfield8_in, ETS_Bitfield_uint16_tr bitfield16_in, ETS_Bitfield_uint32_tr bitfield32_in, P2VAR(ETS_Bitfield_uint8_return_tr, AUTOMATIC, RTE_APPL_DATA) bitfield8_out, P2VAR(ETS_Bitfield_uint16_return_tr, AUTOMATIC, RTE_APPL_DATA) bitfield16_out, P2VAR(ETS_Bitfield_uint32_return_tr, AUTOMATIC, RTE_APPL_DATA) bitfield32_out)
{
  ETS_Bitfield_MappingType mapping[32] =
  {
    {0U  , 1U          , 128U , 32768U , 2147483648U }  ,
    {1U  , 2U          , 64U  , 16384U , 1073741824U }  ,
    {2U  , 4U          , 32U  , 8192U  , 536870912U  }  ,
    {3U  , 8U          , 16U  , 4096U  , 268435456U  }  ,
    {4U  , 16U         , 8U   , 2048U  , 134217728U  }  ,
    {5U  , 32U         , 4U   , 1024U  , 67108864U   }  ,
    {6U  , 64U         , 2U   , 512U   , 33554432U   }  ,
    {7U  , 128U        , 1U   , 256U   , 16777216U   }  ,
    {8U  , 256U        , 0U   , 128U   , 8388608U    }  ,
    {9U  , 512U        , 0U   , 64U    , 4194304U    }  ,
    {10U , 1024U       , 0U   , 32U    , 2097152U    }  ,
    {11U , 2048U       , 0U   , 16U    , 1048576U    }  ,
    {12U , 4096U       , 0U   , 8U     , 524288U     }  ,
    {13U , 8192U       , 0U   , 4U     , 262144U     }  ,
    {14U , 16384U      , 0U   , 2U     , 131072U     }  ,
    {15U , 32768U      , 0U   , 1U     , 65536U      }  ,
    {16U , 65536U      , 0U   , 0U     , 32768U      }  ,
    {17U , 131072U     , 0U   , 0U     , 16384U      }  ,
    {18U , 262144U     , 0U   , 0U     , 8192U       }  ,
    {19U , 524288U     , 0U   , 0U     , 4096U       }  ,
    {20U , 1048576U    , 0U   , 0U     , 2048U       }  ,
    {21U , 2097152U    , 0U   , 0U     , 1024U       }  ,
    {22U , 4194304U    , 0U   , 0U     , 512U        }  ,
    {23U , 8388608U    , 0U   , 0U     , 256U        }  ,
    {24U , 16777216U   , 0U   , 0U     , 128U        }  ,
    {25U , 33554432U   , 0U   , 0U     , 64U         }  ,
    {26U , 67108864U   , 0U   , 0U     , 32U         }  ,
    {27U , 134217728U  , 0U   , 0U     , 16U         }  ,
    {28U , 268435456U  , 0U   , 0U     , 8U          }  ,
    {29U , 536870912U  , 0U   , 0U     , 4U          }  ,
    {30U , 1073741824U , 0U   , 0U     , 2U          }  ,
    {31U , 2147483648U , 0U   , 0U     , 1U          }  ,
  };
  uint32 index;

  *bitfield8_out = 0;
  *bitfield16_out = 0;
  *bitfield32_out = 0;

  for(index = 0U; index < 32U; index++)
  {
    if(index < 8U)
    {
      *bitfield8_out |= (((bitfield8_in & mapping[index].ulValueIn)!=0U)?mapping[index].ucValueOut8:0U);
    }
    if(index < 16U)
    {
      *bitfield16_out |= (((bitfield16_in & mapping[index].ulValueIn)!=0U)?mapping[index].usValueOut16:0U);
    }
    *bitfield32_out |= (((bitfield32_in & mapping[index].ulValueIn)!=0U)?mapping[index].ulValueOut32:0U);
  }
}
#endif

/**
 * \brief Echoes typeDefElement back to sender.
 *
 * \param[in] typeDefElement uint8
 * \param[out] typeDefreturnElement uint8
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0017, 1 */
#if ( ETS_Echo_TYPEDEF == TRUE )
FUNC(void, RTE_CODE) ETS_EchoTYPEDEF (uint8 typeDefElement, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) typeDefreturnElement)
{
  *typeDefreturnElement = typeDefElement;
}
#endif

/**
 * \brief Echoes 16-bit lenght uint8 array back to sender.
 *
 * \param[out] E_uINT8Array ETS_UINT8Array16Bitlength
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0022, 1 */
#if ( ETS_Echo_UINT8Array16Bitlength == TRUE )
FUNC(void, RTE_CODE) ETS_EchoUINT8Array16Bitlength (P2VAR(ETS_UINT8Array16Bitlength, AUTOMATIC, RTE_APPL_DATA) uINT8Array)
{
  uint8 ucElements = 0u;
  ucElements = uINT8Array->size;
  uINT8Array->size = ucElements;
}
#endif

/**
 * \brief Echoes int64 back to sender.
 *
 * \param[in] int64Value sint64
 * \param[out] int64ReturnValue sint64
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0012, 1 */
#if ( ETS_Echo_INT64 == TRUE )
/* Deviation MISRAC2012-1 */
FUNC(void, RTE_CODE) ETS_EchoINT64 (sint64 int64Value, P2VAR(sint64, AUTOMATIC, RTE_APPL_DATA) int64ReturnValue)
{
  *int64ReturnValue = int64Value;
}
#endif

/**
 * \brief Echoes float64 back to sender.
 *
 * \param[in] float64Value float64
 * \param[out] float64ReturnValue float64
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0011, 1 */
#if ( ETS_Echo_FLOAT64 == TRUE )
FUNC(void, RTE_CODE) ETS_EchoFLOAT64 (float64 float64Value, P2VAR(float64, AUTOMATIC, RTE_APPL_DATA) float64ReturnValue)
{
  *float64ReturnValue = float64Value;
}
#endif

/**
 * \brief Echoes uint8 end to end back to sender.
 *
 * \param[out] cRCId uint32
 * \param[out] alive uint16
 * \param[out] cRC uint32
 * \param[out] uINT8Value uint8
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0025, 1 */
#if ( ETS_Echo_UINT8E2E == TRUE )
FUNC(void, RTE_CODE) ETS_EchoUINT8E2E (P2VAR(uint32, AUTOMATIC, RTE_APPL_DATA) cRCId, P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) alive, P2VAR(uint32, AUTOMATIC, RTE_APPL_DATA) cRC, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) uINT8Value)
{
  /* suppress compiler warnings about unused arguments */
  (void)*cRCId;
  (void)*alive;
  (void)*cRC;
  (void)*uINT8Value;
}
#endif

/**
 * \brief Echoes uint8 reliable back to sender..
 *
 * \param[in] Uint8Value uint8
 * \param[out] Uint8ReturnValue uint8
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0026, 1 */
#if ( ETS_Echo_UINT8RELIABLE == TRUE )
FUNC(void, RTE_CODE) ETS_EchoUINT8RELIABLE (uint8 Uint8Value, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Uint8ReturnValue)
{
  *Uint8ReturnValue = Uint8Value;
}
#endif

/**
 * \brief Echoes simple structure back to sender.
 *
 * \param[in] structElement ETS_SimpleStruct
 * \param[out] structReturnElement ETS_SimpleStruct
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0016, 1 */
#if ( ETS_Echo_STRUCTSimple == TRUE )
FUNC(void, RTE_CODE) ETS_EchoSTRUCTSimple (P2CONST(ETS_SimpleStruct, AUTOMATIC, RTE_APPL_DATA) structElement, P2VAR(ETS_SimpleStruct, AUTOMATIC, RTE_APPL_DATA) structReturnElement)
{
  uint8 ucIndex;

  for (ucIndex=0u;ucIndex<2u;ucIndex++)
  {
    structReturnElement[ucIndex].uint8StructureSimple = structElement[ucIndex].uint8StructureSimple;
    structReturnElement[ucIndex].floatStructureSimple = structElement[ucIndex].floatStructureSimple;
  }
}
#endif

/**
 * \brief Echoes uint8 array back to sender..
 *
 * \param[out] uINT8Array_BL ETS_UINT8Array8Bitlength
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0021, 1 */
#if ( ETS_Echo_UINT8Array8BitLength == TRUE )
FUNC(void, RTE_CODE) ETS_EchoUINT8Array8BitLength (P2VAR(ETS_UINT8Array8Bitlength, AUTOMATIC, RTE_APPL_DATA) uINT8Array_BL)
{
  uint8 ucElements = 0u;
  ucElements = uINT8Array_BL->size;
  uINT8Array_BL->size = ucElements;
}
#endif

/**
 * \brief Echoes uint8 array back to sender.
 *
 * \param[in] uINT8Array_MS ETS_Uint8Array
 * \param[out] uINT8ArrayReturnValue_MS ETS_Uint8Array
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0024, 1 */
#if ( ETS_Echo_UINT8ArrayMinSize == TRUE )
FUNC(void, RTE_CODE) ETS_EchoUINT8ArrayMinSize (P2CONST(ETS_Uint8Array, AUTOMATIC, RTE_APPL_DATA) uINT8Array_MS, P2VAR(ETS_Uint8Array, AUTOMATIC, RTE_APPL_DATA) uINT8ArrayReturnValue_MS)
{
  uINT8ArrayReturnValue_MS->size = uINT8Array_MS->size;

  if(uINT8ArrayReturnValue_MS->size < 3)
  {
    uINT8ArrayReturnValue_MS->size = 3;
    TS_MemSet(&uINT8ArrayReturnValue_MS->elem[uINT8Array_MS->size], 0xAB, 3-uINT8Array_MS->size);
  }

  TS_MemCpy(uINT8ArrayReturnValue_MS->elem, uINT8Array_MS->elem, uINT8Array_MS->size);
}
#endif

/**
 * \brief Echoes uint8 Array2Dim back to sender.
 *
 * \param[in] uINT8Array_2D ETS_TwoDimUint8Array
 * \param[out] uINT8ArrayReturnValue_2D ETS_TwoDimUint8Array
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0023, 1 */
#if ( ETS_Echo_UINT8Array2Dim == TRUE )
FUNC(void, RTE_CODE) ETS_EchoUINT8Array2Dim (P2CONST(ETS_TwoDimUint8Array, AUTOMATIC, RTE_APPL_DATA) uINT8Array_2D, P2VAR(ETS_TwoDimUint8Array, AUTOMATIC, RTE_APPL_DATA) uINT8ArrayReturnValue_2D)
{
  uint8 ucIndex;
  uINT8ArrayReturnValue_2D->size = uINT8Array_2D->size;

  for(ucIndex = 0; ucIndex < uINT8Array_2D->size; ucIndex++)
  {
    uINT8ArrayReturnValue_2D->payload[ucIndex].size = uINT8Array_2D->payload[ucIndex].size;
    TS_MemCpy(uINT8ArrayReturnValue_2D->payload[ucIndex].elem, uINT8Array_2D->payload[ucIndex].elem, uINT8Array_2D->payload[ucIndex].size);
  }
}
#endif

/**
 * \brief Echoes ETS_UNION back to sender.
 *
 * \param[in] uINT8Union ETS_UNION
 * \param[out] uINT8UnionReturnValue ETS_UNION
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0027, 1 */
#if ( ETS_Echo_UNION == TRUE )
FUNC(void, RTE_CODE) ETS_EchoUNION (P2CONST(ETS_UNION, AUTOMATIC, RTE_APPL_DATA) uINT8Union, P2VAR(ETS_UNION, AUTOMATIC, RTE_APPL_DATA) uINT8UnionReturnValue)
{
  uINT8UnionReturnValue->uint8Union = uINT8Union->uint8Union;
}
#endif

/**
 * \brief Echoes UTF8FIXED back to sender.
 *
 * \param[in] uINT8Array_FX uint8
 * \param[out] uINT8ArrayReturnValue uint8
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0031, 1 */
#if ( ETS_Echo_UTF8FIXED == TRUE )
FUNC(void, RTE_CODE) ETS_EchoUTF8FIXED (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) uINT8Array_FX, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) uINT8ArrayReturnValue)
{
  uint8 ucIndex;

  for(ucIndex = 0u; ucIndex<64u; ucIndex++)
  {
    uINT8ArrayReturnValue[ucIndex] = uINT8Array_FX[ucIndex];
  }
}
#endif

/**
 * \brief Echoes UTF16FIXED back to sender.
 *
 * \param[in] uINT16Array uint16
 * \param[out] uINT16ArrayReturnValue uint16
 *
 * \return none
 *
 */

/* !LINKSTO swdd.ETS-0029, 1 */
#if ( ETS_Echo_UTF16FIXED == TRUE )
FUNC(void, RTE_CODE) ETS_EchoUTF16FIXED (P2CONST(uint16, AUTOMATIC, RTE_APPL_DATA) uINT16Array, P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) uINT16ArrayReturnValue)
{
  uint8 ucIndex;

  for(ucIndex = 0u; ucIndex<64u; ucIndex++)
  {
    uINT16ArrayReturnValue[ucIndex] = uINT16Array[ucIndex];
  }
}
#endif

#define ETS_STOP_SEC_CODE
#include <ETS_MemMap.h>

/* ==================[end of file]================================================================ */

