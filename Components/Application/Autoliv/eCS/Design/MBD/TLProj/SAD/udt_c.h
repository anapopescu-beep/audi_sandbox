/**************************************************************************************************\
 *** 
 *** Simulink model       : eCS_Algo_Simulation_2015b
 *** TargetLink subsystem : eCS_Algo_Simulation_2015b/SAD
 *** Codefile             : udt_c.h
 ***
 *** Generation date: 2022-03-18 16:06:41
 ***
 *** TargetLink version      : 4.2 from 14-Oct-2016
 *** Code generator version  : Build Id 4.2.0.26 from 2016-10-17 16:31:48

\**************************************************************************************************/

#ifndef UDT_C_H
#define UDT_C_H


#include "Rte_Type.h"


typedef struct stStepParam_tag {
   uint16 u16Duration; /* Description: Step duration: 1 lsb = 5ms */
   uint8 u8Order; /* Description: Order type : PWM or current */
   uint8 u8Consign; /* Description: Consign */
   boolean b8IsRamp; /* Description: Ramp option: 0: OFF - 1: ON */
   boolean b8IsPID; /* Description: PID option: 0: OFF - 1: ON */
} stStepParam;

typedef struct stStepParametersType_tag {
   uint16 au16Duration[6]; /* Description: Step duration: 1 lsb = 5ms */
   uint8 au8OrderType[6]; /* Description: Order type : PWM or current */
   uint8 au8Consign[6]; /* Description: Consign */
   boolean ab8IsRamp[6]; /* Description: Ramp option: 0: OFF - 1: ON */
   boolean ab8IsPID[6]; /* Description: PID option: 0: OFF - 1: ON */
} stStepParametersType;

#endif /* UDT_C_H */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
