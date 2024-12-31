#include "__cf_eCS_Algo_Simulation_2015b_opti.h"
#ifndef RTW_HEADER_eCS_Algo_Simulation_2015b_opti_acc_private_h_
#define RTW_HEADER_eCS_Algo_Simulation_2015b_opti_acc_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#if !defined(ss_VALIDATE_MEMORY)
#define ss_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
#include "tmwtypes.h"
#ifndef TL_SPECIFIC_MACROS_AND_TYPES
#define TL_SPECIFIC_MACROS_AND_TYPES
#define ROUND_FP(_p)((_p==0.0)?(0.0):((_p>0.0) ? (_p+0.5):(_p-0.5)))
#define SCALE_FP_FX(_type, _in, _lsb, _offset)   (_type)(ROUND_FP((_in - (real_T)_offset) / (real_T)_lsb))
#define SCALE_FX_FP(_out, _lsb, _offset)    ((real_T)_out * (real_T)_lsb + (real_T)_offset)
#ifndef __DSTYPES_H__
typedef real_T Float64 ; typedef real32_T Float32 ; typedef int8_T Int8 ;
typedef int16_T Int16 ; typedef int32_T Int32 ; typedef uint8_T UInt8 ;
typedef uint16_T UInt16 ; typedef uint32_T UInt32 ; typedef boolean_T Bool ;
#endif
#endif
#ifndef rtInterpolate
#define rtInterpolate(v1,v2,f1,f2)   (((v1)==(v2))?((double)(v1)):  (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif
#ifndef rtRound
#define rtRound(v) ( ((v) >= 0) ?   muDoubleScalarFloor((v) + 0.5) :   muDoubleScalarCeil((v) - 0.5) )
#endif
extern real_T rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) ; extern real_T
rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T * u ) ; void
eCS_Algo_Simulation_2015b_opti_acc_BINARYSEARCH_real_T ( uint32_T * piLeft ,
uint32_T * piRght , real_T u , const real_T * pData , uint32_T iHi ) ; void
eCS_Algo_Simulation_2015b_opti_acc_LookUp_real_T_real_T ( real_T * pY , const
real_T * pYData , real_T u , const real_T * pUData , uint32_T iHi ) ; extern
real_T look1_binlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T table
[ ] , uint32_T maxIndex ) ; extern real_T look1_binlcapw ( real_T u0 , const
real_T bp0 [ ] , const real_T table [ ] , uint32_T maxIndex ) ; extern real_T
look1_linlcapw ( real_T u0 , const real_T bp0 [ ] , const real_T table [ ] ,
uint32_T maxIndex ) ; extern real_T look1_linlcpw ( real_T u0 , const real_T
bp0 [ ] , const real_T table [ ] , uint32_T maxIndex ) ; void pk4vnz4nca (
int8_T pfqpzykylo , kneg2qbwoq * localB , o10tugwmnc * localP ) ;
#endif
