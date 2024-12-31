
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
/*
$Revision: 1.27 $
$ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/LPM/Implementation/src/project.pj $
*/
/******************************************************************************

   This module handles the Ecu in low power states

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "LPM.h"
#include "MyMcuArchClock.h"
#include "SBC.h"
#include "S32K144_LPTMR.h"
#include "S32K144_PORT.h"
#include "S32K144_LPIT.h"
#include "Adc.h"
#include "Dio.h"
#include "DioIf.h"
#include "Mcu.h"
#include "Port.h"
#include "BswM.h"
#include "BswM_Callouts.h"
#include "EcuM.h"
#include "Rte_LPM.h"
#ifndef QAC
#include "T1_AppInterface.h"
#endif
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 *\brief
 *     Macro used to wakeup state none
 */
#define KU8_LPM_WAKEUP_NONE               ((uint8)0u)

/**
 *\brief
 *     Macro used to wakeup state can wakeup
 */
#define KU8_LPM_WAKEUP_CAN                ((uint8)1u)

/**
 *\brief
 *     Macro used to wakeup state seat presence
 */
#define KU8_LPM_WAKEUP_SEAT_PRESENCE      ((uint8)2u)

/**
 *\brief
 *     Macro used to count the sleep timeout
 */
#define KU32_LPM_SLEEP_TIMEOUT            (NVP_u32TLowPower)

/**
 *\brief
 *     Macro used to disable the os timer - set timer enable bit to 0
 */
#define KU8_LPM_LPIT_DISABLE              ((uint8)0x0Eu)

/**
 *\brief
 *     Macro used to define the LPMTR prescaler value - set the prescaler value
 */
#define KU8_LPM_LPTMR_PRESCALE            ((uint8)0x05u)

/**
 *\brief
 *     Macro used to define the LPTMR interrupt - set the enable interrupt bit
 */
#define KU8_LPM_LPMTR_ENABLE_INTERRUPT    ((uint8)0x40u)

/**
 *\brief
 *     Macro used to define the sleep cyclic wakeup value - sets the timer trigger value
 */
#define KU16_LPM_LPTMR_SLEEP_TIMEOUT      ((uint16)0x1F4u)

/**
 *\brief
 *     Macro used to define the port interrupt enable  - sets the interrupt register
 */
#define KU8_LPM_PORT_PIN_INTERRUPT        ((uint8)0x0Au)

/**
 *\brief
 *     Macro used to define the port pullup enable value - sets the pull register
 */
#define KU8_LPM_PORT_PULLUP_ENABLE        ((uint8)0x03u)

/**
 *\brief
 *     Macro used to define the port mux value - sets the mux register
 */
#define KU16_LPM_PORT_MUX_500             ((uint16)0x500u)

/**
 *\brief
 *     Macro used to define the port mux value - sets the mux register
 */
#define KU16_LPM_PORT_MUX_400             ((uint16)0x400u)

/**
 *\brief
 *     Macro used to define the port mux value - sets the mux register
 */
#define KU16_LPM_PORT_MUX_300             ((uint16)0x300u)

/**
 *\brief
 *     Macro used to define the port mux value - sets the mux register to GPIO
 */
#define KU16_LPM_PORT_MUX_100             ((uint16)0x100u)

/**
 *\brief
 *     Macro used to define the delay for the second channel read
 */
#define KU16_LPM_READ_DELAY               ((uint16)700)

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#define LPM_START_SEC_VAR_INIT_8
#include "LPM_MemMap.h"
/**
 *\brief
 *     This variable is used to store the wakeup reason
 */
LOCAL volatile uint8 lpm_u8Wakeup = KU8_ZERO;
#define LPM_STOP_SEC_VAR_INIT_8
#include "LPM_MemMap.h"
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

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
#define LPM_START_SEC_CODE
#include "LPM_MemMap.h"
/**
* \brief
*       Function used to change the ecu mode to a low power state.
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       Bswm Callback.
* \dynamicaspectdescription
*       This function is called when sleep mode is requested.
* \constrains
*       No constraints.
* \ddesignrequirement
*       DSG_LPM_sleepInit
* \archrequirement
*       ARCH_SW_LPM_ptrpLpmServicesBswMIf_LPM_sleepInit
*       ARCH_SW_LPM_pclAdcIfSerrvices_AdcIf_StopConversion
*       ARCH_SW_LPM_pclAdcIfSerrvices_AdcIf_WaitForConversion
*       ARCH_SW_LPM_pclSbcServices_SBC_SetToLowPower
*       ARCH_SW_LPM_pclSbcServices_SBC_sleepTriggerWatchdog
*/
EXPORTED void LPM_sleepInit(void)
{
   uint16 au6TempBuffer[KU8_TWO];
   uint8 u8Temp;
   au6TempBuffer[0u] = KU16_ZERO;
   au6TempBuffer[1u] = KU16_ZERO;
   lpm_u8Wakeup = KU8_LPM_WAKEUP_NONE;

   /* stop adc timer refresh */
   Rte_Call_pclAdcIfServices_StopConversion();

   /* stop scheduler */
   IP_LPIT0->MCR =  IP_LPIT0->MCR & KU8_LPM_LPIT_DISABLE;

   /* disable outputs */
   Dio_WriteChannel(DioConf_DioChannel_Dio_ON_OFF_Power, STD_LOW);
   DioIf_SetSolenoidCurrentSourcesState(STD_LOW);
   Dio_WriteChannel(DioConf_DioChannel_Dio_ACC_RESETN, STD_LOW);
   Dio_WriteChannel(DioConf_DioChannel_Dio_Sleep_Off, STD_LOW);
   
   Dio_WriteChannel(DioConf_DioChannel_Dio_Wake_Cyclic_Power, STD_LOW);

   /* wait for adc sampling to finish */
   Rte_Call_pclAdcIfServices_WaitForConversion();

   /* reset seat detection module */
   (void)Rte_Call_pclHandleSeatCurrentCircuit_IoHwAb_HandleSeatCurrentCircuit(&au6TempBuffer[0u], &au6TempBuffer[1u], &u8Temp, KU8_TRUE);

   /* trigger Wdg */
   Rte_Call_pclSbcServices_SBC_sleepTriggerWatchdog();

   /* enable periodic wakeup */ 
   IP_LPTMR0->CSR |= LPTMR_CSR_TCF_MASK;
   IP_LPTMR0->CSR = 0u;
   IP_LPTMR0->PSR = KU8_LPM_LPTMR_PRESCALE;
   IP_LPTMR0->CMR = KU16_LPM_LPTMR_SLEEP_TIMEOUT;
   

   (void)Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_1);
   (void)Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_2);
   //(void)Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_3);

   Mcu_SetMode(McuConf_McuModeSettingConf_McuModeSettingConf_VLPR);

   /* enable CAN wakeup */
   IP_PORTD->PCR[KU8_FIVE] |= (uint32)KU8_LPM_PORT_PIN_INTERRUPT << PORT_PCR_IRQC_SHIFT;

   /* Set SBC to Stop mode for low power */
   Rte_Call_pclSbcServices_SBC_SetToLowPower();

   /* ACC pins */
   IP_PORTD->PCR[0u] =  0u;
   IP_PORTD->PCR[1u] =  0u;
   IP_PORTD->PCR[KU8_TWO] =  0u;
   IP_PORTE->PCR[1u] =  0u;

   /* SBC pins */
   IP_PORTB->PCR[KU8_FIVE] =  KU8_LPM_PORT_PULLUP_ENABLE;
   IP_PORTB->PCR[KU8_FOUR] =  0u;
}

/**
* \brief
*       Function used to execute actions during the low power mode.
* \exception
*       This function has no exceptions.
* \pre
*       LPM_sleepInit must be called before this function.
* \post
*       LPM_sleepRestore must be called after this function.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       Bswm Callback.
* \dynamicaspectdescription
*       Function called to execute sleep mode.
* \constrains
*       No constraints.
* \ddesignrequirement
*		DSG_LPM_sleepMainLoop
* \archrequirement
*       ARCH_SW_LPM_ptrpLpmServicesBswMIf_LPM_sleepMainLoop
*       ARCH_SW_LPM_pclLowPowerwakeUp_IoHwAb_HandleSeatVariants
*       ARCH_SW_LPM_pclSbcServices_SBC_sleepTriggerWatchdog
*       ARCH_SW_LPM_pclHandleSeatCurrentCircuit_IoHwAb_HandleSeatCurrentCircuit
*/ 
void LPM_sleepMainLoop(void)
{
   static volatile uint32 u32Delay = KU32_ZERO;
   uint32 u32Timer;
   uint16 au16buffer[ADC_CFGSET_TDK_4G_GROUP_0_CHANNELS];
   boolean bAdcWakeup;
   Std_ReturnType u8Ret;
   uint8 u8ReadOK;

   bAdcWakeup = B_FALSE;
   u32Timer = 0u;
   IP_LPTMR0->CSR = KU8_LPM_LPMTR_ENABLE_INTERRUPT;
   IP_LPTMR0->CSR |= 0x1u;
   do{
	   SuspendAllInterrupts();

      /* Sleep mode */
	   Mcu_SetMode(McuConf_McuModeSettingConf_McuModeSettingConf_VLPS);

      /* restart timer */
	  IP_LPTMR0->CSR = KU8_LPM_LPMTR_ENABLE_INTERRUPT;
	  IP_LPTMR0->CSR |= 0x1u;

      u32Timer++;

      Dio_WriteChannel(DioConf_DioChannel_Dio_Wake_Cyclic_Power, STD_HIGH);
      //Dio_WriteChannel(DioConf_DioChannel_Dio_Wake_Sw1, STD_HIGH);
      //Dio_WriteChannel(DioConf_DioChannel_Dio_Wake_Sw2, STD_HIGH);
      /* SBC pins - enable */
      IP_PORTB->PCR[0u] = KU16_LPM_PORT_MUX_500;
      IP_PORTB->PCR[KU8_FOUR] = KU16_LPM_PORT_MUX_300;
      IP_PORTB->PCR[KU8_FIVE] = KU16_LPM_PORT_MUX_400;

	   ResumeAllInterrupts();
	   Rte_Call_pclSbcServices_SBC_sleepTriggerWatchdog();
      /* SBC pins - disable */
            
	  IP_PORTB->PCR[KU8_FIVE] =  KU8_LPM_PORT_PULLUP_ENABLE;
	  IP_PORTB->PCR[0u] =  0u;
	  IP_PORTB->PCR[KU8_FOUR] =  0u;
     
	  Mcu_SetMode(McuConf_McuModeSettingConf_McuModeSettingConf_RUN);

		//(void)Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_3);

      do{
         u32Delay = 0;
         Adc_StartGroupConversion(AdcGroup_0);
         do{
            u8Ret = Adc_ReadGroup(AdcGroup_0, au16buffer);
         }while(E_NOT_OK == u8Ret);
         Rte_Call_pclHandleSeatCurrentCircuit_IoHwAb_HandleSeatCurrentCircuit(&au16buffer[Adc_Wake1], &au16buffer[Adc_Wake2], &u8ReadOK, KU8_FALSE);
         if(KU8_FALSE == u8ReadOK)
         {
            /* wait */
            Port_SetPinDirection(PortConfigSet_PortContainer_A_PTA0_ADC_WAKE_1,PORT_PIN_OUT);
            Port_SetPinDirection(PortConfigSet_PortContainer_A_PTA1_ADC_WAKE_2,PORT_PIN_OUT);
            IP_PORTA->PCR[0u] =  KU16_LPM_PORT_MUX_100;
            IP_PORTA->PCR[1u] =  KU16_LPM_PORT_MUX_100;
            while(u32Delay < KU16_LPM_READ_DELAY)
            {
               u32Delay++;
               if(u32Delay == KU16_FIVE)
               {
            	  IP_PORTA->PCR[0u] =  0u;
            	  IP_PORTA->PCR[1u] =  0u;
                  Port_SetPinDirection(PortConfigSet_PortContainer_A_PTA0_ADC_WAKE_1,PORT_PIN_IN);
                  Port_SetPinDirection(PortConfigSet_PortContainer_A_PTA1_ADC_WAKE_2,PORT_PIN_IN);
               }
            }
         }
      }while(KU8_FALSE == u8ReadOK);
      
      Dio_WriteChannel(DioConf_DioChannel_Dio_Wake_Cyclic_Power, STD_LOW);
      //Dio_WriteChannel(DioConf_DioChannel_Dio_Wake_Sw1, STD_LOW);
      //Dio_WriteChannel(DioConf_DioChannel_Dio_Wake_Sw2, STD_LOW);

      Mcu_SetMode(McuConf_McuModeSettingConf_McuModeSettingConf_VLPR);
      Rte_Call_pclLowPowerWakeUp_HandleSeatVariants(au16buffer[Adc_Wake1], au16buffer[Adc_Wake2], &bAdcWakeup);

      if(B_TRUE == bAdcWakeup)
      {
         lpm_u8Wakeup = KU8_LPM_WAKEUP_SEAT_PRESENCE;
      }

   }while((KU8_LPM_WAKEUP_NONE == lpm_u8Wakeup)&&(u32Timer <= KU32_LPM_SLEEP_TIMEOUT));

   /* Stop timer */
   IP_LPTMR0->CSR = 0u;
   IP_LPTMR0->CSR |= LPTMR_CSR_TCF_MASK;

   Mcu_SetMode(McuConf_McuModeSettingConf_McuModeSettingConf_RUN);

   /* disable CAN wakeup interrupt */
   IP_PORTD->PCR[KU8_FIVE] &= (uint32)(~((uint32)PORT_PCR_IRQC_MASK));
}

/**
* \brief
*       Function used to exit ecu from a low power mode to a normal mode.
* \exception
*       This function has no exceptions.
* \pre
*       This function must be called after LPM_sleepMainLoop.
* \post
*       This function has no postconditions.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       Bswm Callback.
* \dynamicaspectdescription
*       Function is called when low power mode is exited.
* \constrains
*       No constraints.
* \ddesignrequirement
*		DSG_LPM_sleepRestore
* \archrequirement
*       ARCH_SW_LPM_ptrpLpmServicesBswMIf_LPM_sleepRestore 
*       ARCH_SW_LPM_pclAdcIfSerrvices_AdcIf_StartConversion
*       ARCH_SW_LPM_pclAccRestartInit_ACC_RestartInitialization
*       ARCH_SW_LPM_pclSbcServices_SBC_SetToNormal
*/
void LPM_sleepRestore(void)
{
   /* SBC pins - enable */
   IP_PORTB->PCR[0u] = KU16_LPM_PORT_MUX_500;
   IP_PORTB->PCR[KU8_FOUR] = KU16_LPM_PORT_MUX_300;
   IP_PORTB->PCR[KU8_FIVE] = KU16_LPM_PORT_MUX_400;
   
   Rte_Call_pclSbcServices_SBC_SetToNormal();

   MyMcuArchClock_Init();

   /* enable outputs */
   Dio_WriteChannel(DioConf_DioChannel_Dio_Wake_Cyclic_Power, STD_HIGH);

   //Dio_WriteChannel(DioConf_DioChannel_Dio_Wake_Sw1, STD_HIGH);
   //Dio_WriteChannel(DioConf_DioChannel_Dio_Wake_Sw2, STD_HIGH);

   if(KU8_LPM_WAKEUP_SEAT_PRESENCE == lpm_u8Wakeup)
   {
      BswM_RequestMode(KU8_BSWM_PASSANGER_OCCUPANCY_REQUEST_PORT, BSWM_PASSANGER_OCCUPANCY_DETECTED);
      BswM_RequestMode(KU8_BSWM_REQ_WAKEUP_TYPE_REQUEST_PORT, BSWM_ACTIVE_WAKEUP_REQ);
   }
   else if (KU8_LPM_WAKEUP_CAN == lpm_u8Wakeup)
   {
      BswM_RequestMode(KU8_BSWM_REQ_WAKEUP_TYPE_REQUEST_PORT, BSWM_PASSIVE_WAKEUP_REQ);
      EcuM_SetWakeupEvent(EcuM_ECUM_WKSOURCE_CAN);
      EcuM_ValidateWakeupEvent(EcuM_ECUM_WKSOURCE_CAN);
   }
   else
   {
      BswM_RequestMode(KU8_BSWM_PASSANGER_OCCUPANCY_REQUEST_PORT, BSWM_PASSANGER_OCCUPANCY_NOT_DETECTED);
      BswM_RequestMode(KU8_BSWM_REQ_WAKEUP_TYPE_REQUEST_PORT, BSWM_NO_WAKEUP_REQ); 
      /* go to shutdown */
   }

   /* add a bit of a delay for the acc to power on */
   IP_LPTMR0->CMR = KU8_FIVE;
   IP_LPTMR0->CSR = KU8_LPM_LPMTR_ENABLE_INTERRUPT;
   IP_LPTMR0->CSR |= 0x1u;
   while(0u != IP_LPTMR0->CSR)
   {
      ;
   }
   /* Reinit acc init state */
   Rte_Call_pclAccRestartInit_RestartInitialization();
   
   /* restore os timer */
   IP_LPIT0->MCR |= 1u;

   /* restart adc timer */
   Rte_Call_pclAdcIfServices_StartConversion();
}

/**
* \brief
*       Interrupt used for cyclic sleep wakeup.
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       Os module.
* \dynamicaspectdescription
*       Function is called when timer expires.
* \constrains
*       No constraints.
* \ddesignrequirement
*		DSG_LPTMR_ISR
* \archrequirement
*       ARCH_SW_LPM_ptrpLpmServicesAsrOs_LPTMR_ISR 
*/
ISR(LPTMR_ISR)
{
#ifdef T1_CAT1_INTERRUPT_TRACE
   T1_TraceStartNoActNoSuspPC( 0u, T1_LPTMR_ISR_ID );
#endif

   IP_LPTMR0->CSR |= LPTMR_CSR_TCF_MASK;
   IP_LPTMR0->CSR = 0u;

#ifdef T1_CAT1_INTERRUPT_TRACE
   T1_TraceStopNoSuspPC( 0u, T1_LPTMR_ISR_ID );
#endif
}

/**
* \brief
*       Interrupt used for can wakeup.
* \exception
*       This function has no exceptions.
* \pre
*       This function has no preconditions.
* \post
*       This function has no postconditions.
* \return
*       This function has no return.
* \dynamicaspectcaller
*       Os module.
* \dynamicaspectdescription
*       Function is called when a pin toggles its value.
* \constrains
*       No constraints.
* \ddesignrequirement
*		DSG_PORTD_ISR
* \archrequirement
*       ARCH_SW_LPM_ptrpLpmServicesAsrOs_PORTD_ISR 
*/
ISR(PORTD_ISR)
{
#ifdef T1_CAT1_INTERRUPT_TRACE   
   T1_TraceStartNoActNoSuspPC( 0u, T1_PORTD_ISR_ID );
#endif

   IP_PORTD->ISFR = KU16_MAX;
   lpm_u8Wakeup = KU8_LPM_WAKEUP_CAN;

#ifdef T1_CAT1_INTERRUPT_TRACE
   T1_TraceStopNoSuspPC( 0u, T1_PORTD_ISR_ID );
#endif
}

#define LPM_STOP_SEC_CODE
#include "LPM_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
