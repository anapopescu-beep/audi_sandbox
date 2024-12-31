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
 *    $Revision: 1.5.3.46 $
 *    $ProjectName: e:/MKSProjects/SBE/eCS/AUDI_MCC/Phase_01/View_Development/Components/Application/Autoliv/CIL/Implementation/src/project.pj $
 */

/**
 * Overview of the component :
 *    Communication Interface Layer (CIL) oversees extracting data from the 
 *    network frames (e.g. CAN) and providing the data to the application, and 
 *    packing the outgoing data to the network frames.
 *    The aim of the CIL component is to interpret all received signals on the
 *    communication component and to provide the right information to the application.
 *    Also, it’s purpose is to gather information from the Application and
 *    compute the status signals and sent them to the CAN bus.
 *    CIL oversees:
 *       - Unpacking received data frames from the network (CAN), and providing 
 *         the data to the application
 *       - Packing the outgoing data to data frames for the network (CAN)
 */

/*!****************************************************************************/

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_CIL.h"
#include "Nvp_Cfg.h"
#include "CIL.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *       Constant with the number of support time slots for getting API data
 *       DO NOT CHANGE THIS VALUE -> 10ms cyclic time is assured by 5 TimeSlots
 */
#define KU8_CIL_ATC_NB_OF_SLOTS (KU8_FIVE)

/**
 * \brief
 *       The bit mask for the full range of states of solenoid [0,6]
 */
#define KU8_CIL_SOLENOID_STATE_MASK ((uint8) 0x07)


/**
 * \brief
 *       The constant represents the max time the ECU is allowed to report
 *       INIT on the status frame (e.g. 1000ms)
 */
#define KU32_CIL_INIT_STATUS_FRAME_TIMEOUT_VAL ((uint32) 145u)

/******************************************************************************
MODULE TYPES
******************************************************************************/
/**
 * \brief
 *       Function pointer for addressing TX frames callbacks
 */
typedef void (*cil_pfTxSlotFunction_Type)(void);

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
LOCAL_INLINE void cil_ManagePeriodicData_TimeSlot01(void);
LOCAL_INLINE void cil_ManagePeriodicData_TimeSlot02(void);
LOCAL_INLINE void cil_ManagePeriodicData_TimeSlot03(void);
LOCAL_INLINE void cil_ManagePeriodicData_TimeSlot04(void);
LOCAL_INLINE void cil_ManagePeriodicData_TimeSlot05(void);
LOCAL_INLINE void cil_Manage_eCS_Status_Verr_Reihe1_BFS_1(void);
LOCAL_INLINE void cil_Manage_eCS_Status_Verr_Reihe1_BFS_2(void);
LOCAL_INLINE void cil_Manage_eCS_Status_Verr_Reihe1_FS_1(void);
LOCAL_INLINE void cil_Manage_eCS_Status_Verr_Reihe1_FS_2(void);
LOCAL_INLINE void cil_Manage_eCS_Status_Verr_Reihe2_BFS(void);
LOCAL_INLINE void cil_Manage_eCS_Status_Verr_Reihe2_FS(void);
LOCAL_INLINE void cil_Manage_eCS_Error_Reihe1_BFS_1(void);
LOCAL_INLINE void cil_Manage_eCS_Error_Reihe1_BFS_2(void);
LOCAL_INLINE void cil_Manage_eCS_Error_Reihe1_FS_1(void);
LOCAL_INLINE void cil_Manage_eCS_Error_Reihe1_FS_2(void);
LOCAL_INLINE void cil_Manage_eCS_Error_Reihe2_BFS(void);
LOCAL_INLINE void cil_Manage_eCS_Error_Reihe2_FS(void);
LOCAL_INLINE void cil_Manage_eCS_SBS_LastState_Reihe2_FS(void);
LOCAL_INLINE void cil_Manage_eCS_SBS_LastState_Reihe2_BFS(void);
LOCAL_INLINE void cil_Manage_eCS_SBS_Belegung(void);
LOCAL_INLINE void cil_Manage_eCS_DevKit_Seat_Occupancy_Status(void);
LOCAL_INLINE void cil_Manage_eCS_HW_defekt(void);
LOCAL_INLINE void cil_Manage_eCS_Stoerung(void);
LOCAL_INLINE void cil_Manage_eCS_Status(void);
LOCAL_INLINE void cil_Manage_eCS_Gurtschloss_Status(void);
LOCAL_INLINE void cil_Manage_eCS_DevKit_Buckle_Status(void);
LOCAL_INLINE void cil_Manage_eCS_DevKit_Solenoid_Profiles_States(void);
LOCAL_INLINE void cil_Manage_eCS_DevKit_Acceleration_Output(void);
LOCAL_INLINE void cil_Manage_eCS_DevKit_Algo_Output(void);
LOCAL_INLINE void cil_Manage_eCS_DevKit_Solenoid_Mechanical_Status(void);
LOCAL_INLINE void cil_Manage_eCS_DevKit_Counter_Management(void);

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#define CIL_START_SEC_VAR_INIT_8
#include "CIL_MemMap.h"

/**
 * \brief
 *       This variable is used to store the Dev Frame output to CAN
 * \initialization
 *       KU8_ZERO
 */
LOCAL CIL_stFrameDataBytes cil_u8EcuCanDataOutFrame0Content = { KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, 
                                                                     KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO,
                                                                     KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO,
                                                                     KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO,
                                                                     KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO,
                                                                     KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO,
                                                                     KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO,
                                                                     KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO};

/**
 * \brief
 *       This variable is used to store the time Slot Counter
 * \initialization
 *       KU8_ZERO
 */
LOCAL uint8 cil_u8PeriodicDataTimeSlotID = KU8_ZERO;

/**
 * \brief
 *       This variable is used to signal that ECU is blocked in INIT phase for longer
 *       than allowed timeout without an appropriate error bit.
 * \initialization
 *       KU8_FALSE
 */
LOCAL uint8 cil_u8UnknownStatusFrameError = KU8_FALSE;

#define CIL_STOP_SEC_VAR_INIT_8
#include "CIL_MemMap.h"

#define CIL_START_SEC_VAR_NO_INIT_8
#include "CIL_MemMap.h"

/**
 * \brief
 *       This variable is what is actually sent on the Dev Frame to CAN (8 Byte Chunks)
 */
LOCAL REC_CanDataOut64_Type cil_u8EcuCanDataOutFrame0OnBus;

#define CIL_STOP_SEC_VAR_NO_INIT_8
#include "CIL_MemMap.h"

#define CIL_START_SEC_VAR_INIT_32
#include "CIL_MemMap.h"

/**
 * \brief
 *       This variable is used to monitor the max time the ECU is allowed to report
 *       INIT on the status frame
 * \initialization
 *       KU32_ZERO
 */
LOCAL uint32 cil_u32ReportInitStatusTimeoutCnt = KU32_ZERO;

#define CIL_STOP_SEC_VAR_NO_INIT_32
#include "CIL_MemMap.h"

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
/**
 * \brief
 *       Array of function pointers that manage the CAN outputs from Application
 */
LOCAL const cil_pfTxSlotFunction_Type cil_kapfPerGetDataFunc[KU8_CIL_ATC_NB_OF_SLOTS] =
{
   &cil_ManagePeriodicData_TimeSlot01,
   &cil_ManagePeriodicData_TimeSlot02,
   &cil_ManagePeriodicData_TimeSlot03,
   &cil_ManagePeriodicData_TimeSlot04,
   &cil_ManagePeriodicData_TimeSlot05,
};

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
#define CIL_START_SEC_CODE
#include "CIL_MemMap.h"

/**
* \brief
*        This function is used to gather data necessary to compute the seat occupancy
*        status for seats 1&&2 for the 2nd row
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot04
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \constrains
*        NVP_u8EnableDevFrame must be != KU8_ZERO (DevKit Frame is enabled)
* \ddesignrequirement
*        DSG_cil_Manage_eCS_SBS_Belegung
* \archrequirement
*        ARCH_SW_CIL_SP_IF_eCS_SBS_Belegung_Reihe2_BF_XIX_Grundumfang_XIX_eCS;
*        ARCH_SW_CIL_SP_IF_eCS_SBS_Belegung_Reihe2_FA_XIX_Grundumfang_XIX_eCS;
*        ARCH_SW_CIL_prrSeatOccupancySensorStatus;
**/
LOCAL_INLINE void cil_Manage_eCS_SBS_Belegung(void)
{
   uint8 u8SeatOccupancySensorRx[CIL_NO_OF_SEATS];

   /* initialize seat occupancy Tx array */
   CIL_u8SeatOccupancySensorTx[KU8_ZERO] = (uint8)CM_eCS_SBS_Belegung_Reihe2_BF_Cx0_nicht_verfuegbar;
   CIL_u8SeatOccupancySensorTx[KU8_ONE] = (uint8)CM_eCS_SBS_Belegung_Reihe2_BF_Cx0_nicht_verfuegbar;
   CIL_u8SeatOccupancySensorTx[KU8_TWO] = (uint8)CM_eCS_SBS_Belegung_Reihe2_FA_Cx0_nicht_verfuegbar;
   CIL_u8SeatOccupancySensorTx[KU8_THREE] = (uint8)CM_eCS_SBS_Belegung_Reihe2_BF_Cx0_nicht_verfuegbar;

   /* Get feedback from Seat Occupancy Sensors and map to CAN mapping (values for existing sensor seats will be overwritten) */
   (void)Rte_Read_CIL_prrSeatOccupancySensorStatus_au8SeatOccupancySensorStatus(u8SeatOccupancySensorRx);
   /* Seat Sensor 3 Status */
   if (KUB_eCS_SBS_SEAT_1_NOT_CONFIGURED_VARIANT)
   {
      /* Seat Sensor 3 not coded */
      CIL_u8SeatOccupancySensorTx[KU8_TWO] = (uint8)CM_eCS_SBS_Belegung_Reihe2_FA_Cx0_nicht_verfuegbar;
   }
   else
   {
      switch (u8SeatOccupancySensorRx[KU8_ZERO])
      {
      case KU8_SEAT_OCCUPANCY_NOT_DETECTED:
         CIL_u8SeatOccupancySensorTx[KU8_TWO] = (uint8)CM_eCS_SBS_Belegung_Reihe2_FA_Cx2_nicht_belegt;
         break;
      case KU8_SEAT_OCCUPANCY_DETECTED:
         CIL_u8SeatOccupancySensorTx[KU8_TWO] = (uint8)CM_eCS_SBS_Belegung_Reihe2_FA_Cx3_belegt;
         break;
      default: /* KU8_SEAT_OCCUPANCY_UNKNOWN or random value due to memory corruption */
         if(KB_SEAT_1_REMOVABLE_CONFIG_ACTIVATED)
         {
            CIL_u8SeatOccupancySensorTx[KU8_TWO] = (uint8)CM_eCS_SBS_Belegung_Reihe2_FA_Cx3_belegt;
         }
         else
         {
            CIL_u8SeatOccupancySensorTx[KU8_TWO] = (uint8)CM_eCS_SBS_Belegung_Reihe2_FA_Cx1_Kurzschluss_nach_Masse;
         }
         break;
      }
   }

   /* Seat Sensor 4 Status */
   if (KUB_eCS_SBS_SEAT_2_NOT_CONFIGURED_VARIANT)
   {
      /* Seat Sensor 4 not coded */
      CIL_u8SeatOccupancySensorTx[KU8_THREE] = (uint8)CM_eCS_SBS_Belegung_Reihe2_FA_Cx0_nicht_verfuegbar;
   }
   else
   {
      switch (u8SeatOccupancySensorRx[KU8_ONE])
      {
      case KU8_SEAT_OCCUPANCY_NOT_DETECTED:
         CIL_u8SeatOccupancySensorTx[KU8_THREE] = (uint8)CM_eCS_SBS_Belegung_Reihe2_BF_Cx2_nicht_belegt;
         break;
      case KU8_SEAT_OCCUPANCY_DETECTED:
         CIL_u8SeatOccupancySensorTx[KU8_THREE] = (uint8)CM_eCS_SBS_Belegung_Reihe2_BF_Cx3_belegt;
         break;
      default: /* KU8_SEAT_OCCUPANCY_UNKNOWN or random value due to memory corruption */
         if(KB_SEAT_2_REMOVABLE_CONFIG_ACTIVATED)
         {
            CIL_u8SeatOccupancySensorTx[KU8_THREE] = (uint8)CM_eCS_SBS_Belegung_Reihe2_BF_Cx3_belegt;
         }
         else
         {
            CIL_u8SeatOccupancySensorTx[KU8_THREE] = (uint8)CM_eCS_SBS_Belegung_Reihe2_BF_Cx1_Kurzschluss_nach_Masse;
         }
         break;
      }
   }
   /* Signal: eCS_SBS_Belegung_Reihe2_FA */
   (void)Rte_Write_SP_IF_eCS_SBS_Belegung_Reihe2_FA_XIX_Grundumfang_XIX_eCS_DE_eCS_SBS_Belegung_Reihe2_FA(CIL_u8SeatOccupancySensorTx[KU8_TWO]);
   /* Signal: eCS_SBS_Belegung_Reihe2_BF */
   (void)Rte_Write_SP_IF_eCS_SBS_Belegung_Reihe2_BF_XIX_Grundumfang_XIX_eCS_DE_eCS_SBS_Belegung_Reihe2_BF(CIL_u8SeatOccupancySensorTx[KU8_THREE]);
}


/**
* \brief
*        This function is used to output the current state of the solenoid coresponding
*        to the first solenoid on the front row, seat BF
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot01
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \ddesignrequirement
*        DSG_cil_Manage_eCS_Status_Verr_Reihe1_BFS_1
* \archrequirement
*        ARCH_SW_CIL_SP_IF_eCS_Status_Verr_Reihe1_BFS_1;
*        ARCH_SW_CIL_pclModeManagement;
*        ARCH_SW_CIL_prrSolenoidState;
*        ARCH_SW_CIL_prrEcsAlgoData_u8EcsFlag;
**/
LOCAL_INLINE void cil_Manage_eCS_Status_Verr_Reihe1_BFS_1(void)
{
   uint8 u8InitModeStatus = KU8_FALSE;
   uint8 u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   uint8 u8SolenoidDisabledModeStatus = KU8_FALSE;
   uint8 u8CanInhibitModeStatus = KU8_FALSE;
   uint8 u8SolenoidConfigModeStatus = KU8_FALSE;
   uint8 au8SolenoidStates[KU8_MAX_SOLENOID_NB];
   u8EcsTriggerType u8EcsTrigger;

   /* Get all solenoid state */
   (void)Rte_Read_prrSolenoidState_au8SolenoidState(au8SolenoidStates);

   /* Get eCS algo outputs: Driver trigger */
   (void)Rte_Read_prrEcsAlgoData_u8EcsFlag(&u8EcsTrigger);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_INIT_PHASE_IN_PROGRESS, &u8InitModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_ECU_CAN_INHIB_STATUS, &u8CanInhibitModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus((KU64_SOLENOID_3_ABORTION_ERROR | KU64_SOLENOID_3_INHIB_ERROR), &u8SolenoidDisabledModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_3_CONFIGURED, &u8SolenoidConfigModeStatus);

   /* eCS status computation */
   if(KU8_FALSE == u8SolenoidConfigModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx3_nicht_verbaut;
   }
   else if(KU8_TRUE == u8InitModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   }
   else if(B_TRUE == u8SolenoidDisabledModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   }
   else
   {
      if((KU8_STARTUP_STATE == au8SolenoidStates[KU8_SOLENOID_3]) ||
         (KU8_DIAGNOSTIC_STATE == au8SolenoidStates[KU8_SOLENOID_3]))
      {
         if((KU8_ECS_ALGO_LOCK == u8EcsTrigger) ||
            (B_TRUE == u8CanInhibitModeStatus))
         {
            u8SolenoidStatus = (uint8)Cx1_verriegelt;
         }
         else if(KU8_ECS_ALGO_UNLOCK == u8EcsTrigger)
         {
            u8SolenoidStatus = (uint8)Cx2_entriegelt;
         }
         else
         {
            /* do nothing */
         }
      }
      else if((KU8_UNLOCK_STATE == au8SolenoidStates[KU8_SOLENOID_3]) ||
              (KU8_BACKUP_STATE == au8SolenoidStates[KU8_SOLENOID_3]))
      {
         if (B_TRUE == u8CanInhibitModeStatus)
         {
            u8SolenoidStatus = (uint8)Cx1_verriegelt;
         }
         else
         {
            u8SolenoidStatus = (uint8)Cx2_entriegelt;
         }
      }
      else if (KU8_LOCK_STATE == au8SolenoidStates[KU8_SOLENOID_3])
      {
         u8SolenoidStatus = (uint8)Cx1_verriegelt;
      }
      else if (KU8_DISABLED_STATE == au8SolenoidStates[KU8_SOLENOID_3])
      {
         u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
      }
      else
      {
         /* Can not decide */
      }
   }

   /* Write signal to CAN bus */
   (void)Rte_Write_SP_IF_eCS_Status_Verr_Reihe1_BFS_1_DE_eCS_Status_Verr_Reihe1_BFS_1(u8SolenoidStatus);

}

/**
* \brief
*        This function is used to output the current state of the solenoid coresponding
*        to the second solenoid on the front row, seat BF
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot02
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \ddesignrequirement
*        DSG_cil_Manage_eCS_Status_Verr_Reihe1_BFS_2
* \archrequirement
*        ARCH_SW_CIL_SP_IF_eCS_Status_Verr_Reihe1_BFS_2;
*        ARCH_SW_CIL_pclModeManagement;
*        ARCH_SW_CIL_prrSolenoidState;
*        ARCH_SW_CIL_prrEcsAlgoData_u8EcsFlag;
**/
LOCAL_INLINE void cil_Manage_eCS_Status_Verr_Reihe1_BFS_2(void)
{
   uint8 u8InitModeStatus = KU8_FALSE;
   uint8 u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   uint8 u8SolenoidDisabledModeStatus= KU8_FALSE;
   uint8 u8CanInhibitModeStatus = KU8_FALSE;
   uint8 u8SolenoidConfigModeStatus = KU8_FALSE;
   uint8 au8SolenoidStates[KU8_MAX_SOLENOID_NB];
   u8EcsTriggerType u8EcsTrigger;

   /* Get all solenoid state */
   (void)Rte_Read_prrSolenoidState_au8SolenoidState(au8SolenoidStates);

   /* Get eCS algo outputs: Driver trigger */
   (void)Rte_Read_prrEcsAlgoData_u8EcsFlag(&u8EcsTrigger);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_INIT_PHASE_IN_PROGRESS, &u8InitModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_ECU_CAN_INHIB_STATUS, &u8CanInhibitModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus((KU64_SOLENOID_4_ABORTION_ERROR | KU64_SOLENOID_4_INHIB_ERROR), &u8SolenoidDisabledModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_4_CONFIGURED, &u8SolenoidConfigModeStatus);

   /* eCS status computation */
   if(KU8_FALSE == u8SolenoidConfigModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx3_nicht_verbaut;
   }
   else if(KU8_TRUE == u8InitModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   }
   else if(B_TRUE == u8SolenoidDisabledModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   }
   else
   {
      if((KU8_STARTUP_STATE == au8SolenoidStates[KU8_SOLENOID_4]) ||
         (KU8_DIAGNOSTIC_STATE == au8SolenoidStates[KU8_SOLENOID_4]))
      {
         if((KU8_ECS_ALGO_LOCK == u8EcsTrigger) ||
            (B_TRUE == u8CanInhibitModeStatus))
         {
            u8SolenoidStatus = (uint8)Cx1_verriegelt;
         }
         else if(KU8_ECS_ALGO_UNLOCK == u8EcsTrigger)
         {
            u8SolenoidStatus = (uint8)Cx2_entriegelt;
         }
         else
         {
            /* do nothing */
         }
      }
      else if((KU8_UNLOCK_STATE == au8SolenoidStates[KU8_SOLENOID_4]) ||
              (KU8_BACKUP_STATE == au8SolenoidStates[KU8_SOLENOID_4]))
      {
         if (B_TRUE == u8CanInhibitModeStatus)
         {
            u8SolenoidStatus = (uint8)Cx1_verriegelt;
         }
         else
         {
            u8SolenoidStatus = (uint8)Cx2_entriegelt;
         }
      }
      else if (KU8_LOCK_STATE == au8SolenoidStates[KU8_SOLENOID_4])
      {
         u8SolenoidStatus = (uint8)Cx1_verriegelt;
      }
      else if (KU8_DISABLED_STATE == au8SolenoidStates[KU8_SOLENOID_4])
      {
         u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
      }
      else
      {
         /* Can not decide */
      }
   }

   /* Write signal to CAN bus */
   (void)Rte_Write_SP_IF_eCS_Status_Verr_Reihe1_BFS_2_DE_eCS_Status_Verr_Reihe1_BFS_2(u8SolenoidStatus);
}

/**
* \brief
*        This function is used to output the current state of the solenoid coresponding
*        to the first solenoid on the front row, seat FA
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot02
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \ddesignrequirement
*        DSG_cil_Manage_eCS_Status_Verr_Reihe1_FS_1
* \archrequirement
*        ARCH_SW_CIL_SP_IF_eCS_Status_Verr_Reihe1_FS_1;
*        ARCH_SW_CIL_pclModeManagement;
*        ARCH_SW_CIL_prrSolenoidState;
*        ARCH_SW_CIL_prrEcsAlgoData_u8EcsFlag;
**/
LOCAL_INLINE void cil_Manage_eCS_Status_Verr_Reihe1_FS_1(void)
{
   uint8 u8InitModeStatus = KU8_FALSE;
   uint8 u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   uint8 u8SolenoidDisabledModeStatus = KU8_FALSE;
   uint8 u8CanInhibitModeStatus = KU8_FALSE;
   uint8 u8SolenoidConfigModeStatus = KU8_FALSE;
   uint8 au8SolenoidStates[KU8_MAX_SOLENOID_NB];
   u8EcsTriggerType u8EcsTrigger;

   /* Get all solenoid state */
   (void)Rte_Read_prrSolenoidState_au8SolenoidState(au8SolenoidStates);

   /* Get eCS algo outputs: Driver trigger */
   (void)Rte_Read_prrEcsAlgoData_u8EcsFlag(&u8EcsTrigger);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_INIT_PHASE_IN_PROGRESS, &u8InitModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_ECU_CAN_INHIB_STATUS, &u8CanInhibitModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus((KU64_SOLENOID_1_ABORTION_ERROR | KU64_SOLENOID_1_INHIB_ERROR), &u8SolenoidDisabledModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_1_CONFIGURED, &u8SolenoidConfigModeStatus);

   /* eCS status computation */
   if(KU8_FALSE == u8SolenoidConfigModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx3_nicht_verbaut;
   }
   else if(KU8_TRUE == u8InitModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   }
   else if(B_TRUE == u8SolenoidDisabledModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   }
   else
   {
      if((KU8_STARTUP_STATE == au8SolenoidStates[KU8_SOLENOID_1]) ||
         (KU8_DIAGNOSTIC_STATE == au8SolenoidStates[KU8_SOLENOID_1]))
      {
         if((KU8_ECS_ALGO_LOCK == u8EcsTrigger) ||
            (B_TRUE == u8CanInhibitModeStatus))
         {
            u8SolenoidStatus = (uint8)Cx1_verriegelt;
         }
         else if(KU8_ECS_ALGO_UNLOCK == u8EcsTrigger)
         {
            u8SolenoidStatus = (uint8)Cx2_entriegelt;
         }
         else
         {
            /* do nothing */
         }
      }
      else if((KU8_UNLOCK_STATE == au8SolenoidStates[KU8_SOLENOID_1]) ||
              (KU8_BACKUP_STATE == au8SolenoidStates[KU8_SOLENOID_1]))
      {
         if (B_TRUE == u8CanInhibitModeStatus)
         {
            u8SolenoidStatus = (uint8)Cx1_verriegelt;
         }
         else
         {
            u8SolenoidStatus = (uint8)Cx2_entriegelt;
         }
      }
      else if (KU8_LOCK_STATE == au8SolenoidStates[KU8_SOLENOID_1])
      {
         u8SolenoidStatus = (uint8)Cx1_verriegelt;
      }
      else if (KU8_DISABLED_STATE == au8SolenoidStates[KU8_SOLENOID_1])
      {
         u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
      }
      else
      {
         /* Can not decide */
      }
   }

   /* Write signal to CAN bus */
   (void)Rte_Write_SP_IF_eCS_Status_Verr_Reihe1_FS_1_DE_eCS_Status_Verr_Reihe1_FS_1(u8SolenoidStatus);
}

/**
* \brief
*        This function is used to output the current state of the solenoid coresponding
*        to the second solenoid on the front row, seat FA
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot03
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \ddesignrequirement
*        DSG_cil_Manage_eCS_Status_Verr_Reihe1_FS_2
* \archrequirement
*        ARCH_SW_CIL_SP_IF_eCS_Status_Verr_Reihe1_FS_2;
*        ARCH_SW_CIL_pclModeManagement;
*        ARCH_SW_CIL_prrSolenoidState;
*        ARCH_SW_CIL_prrEcsAlgoData_u8EcsFlag;
**/
LOCAL_INLINE void cil_Manage_eCS_Status_Verr_Reihe1_FS_2(void)
{
   uint8 u8InitModeStatus = KU8_FALSE;
   uint8 u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   uint8 u8SolenoidDisabledModeStatus = KU8_FALSE;
   uint8 u8CanInhibitModeStatus = KU8_FALSE;
   uint8 u8SolenoidConfigModeStatus = KU8_FALSE;
   uint8 au8SolenoidStates[KU8_MAX_SOLENOID_NB];
   u8EcsTriggerType u8EcsTrigger;

   /* Get all solenoid state */
   (void)Rte_Read_prrSolenoidState_au8SolenoidState(au8SolenoidStates);

   /* Get eCS algo outputs: Driver trigger */
   (void)Rte_Read_prrEcsAlgoData_u8EcsFlag(&u8EcsTrigger);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_INIT_PHASE_IN_PROGRESS, &u8InitModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_ECU_CAN_INHIB_STATUS, &u8CanInhibitModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus((KU64_SOLENOID_2_ABORTION_ERROR | KU64_SOLENOID_2_INHIB_ERROR), &u8SolenoidDisabledModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_2_CONFIGURED, &u8SolenoidConfigModeStatus);

   /* eCS status computation */
   if(KU8_FALSE == u8SolenoidConfigModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx3_nicht_verbaut;
   }
   else if(KU8_TRUE == u8InitModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   }
   else if(B_TRUE == u8SolenoidDisabledModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   }
   else
   {
      if((KU8_STARTUP_STATE == au8SolenoidStates[KU8_SOLENOID_2]) ||
         (KU8_DIAGNOSTIC_STATE == au8SolenoidStates[KU8_SOLENOID_2]))
      {
         if((KU8_ECS_ALGO_LOCK == u8EcsTrigger) ||
            (B_TRUE == u8CanInhibitModeStatus))
         {
            u8SolenoidStatus = (uint8)Cx1_verriegelt;
         }
         else if(KU8_ECS_ALGO_UNLOCK == u8EcsTrigger)
         {
            u8SolenoidStatus = (uint8)Cx2_entriegelt;
         }
         else
         {
            /* do nothing */
         }
      }
      else if((KU8_UNLOCK_STATE == au8SolenoidStates[KU8_SOLENOID_2]) ||
              (KU8_BACKUP_STATE == au8SolenoidStates[KU8_SOLENOID_2]))
      {
         if (B_TRUE == u8CanInhibitModeStatus)
         {
            u8SolenoidStatus = (uint8)Cx1_verriegelt;
         }
         else
         {
            u8SolenoidStatus = (uint8)Cx2_entriegelt;
         }
      }
      else if (KU8_LOCK_STATE == au8SolenoidStates[KU8_SOLENOID_2])
      {
         u8SolenoidStatus = (uint8)Cx1_verriegelt;
      }
      else if (KU8_DISABLED_STATE == au8SolenoidStates[KU8_SOLENOID_2])
      {
         u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
      }
      else
      {
         /* Can not decide */
      }
   }

   /* Write signal to CAN bus */
   (void)Rte_Write_SP_IF_eCS_Status_Verr_Reihe1_FS_2_DE_eCS_Status_Verr_Reihe1_FS_2(u8SolenoidStatus);
}

/**
* \brief
*        This function is used to output the current state of the solenoid coresponding
*        to the solenoid on the second row, seat BF
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot03
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \ddesignrequirement
*        DSG_cil_Manage_eCS_Status_Verr_Reihe2_BFS
* \archrequirement
*        ARCH_SW_CIL_SP_IF_eCS_Status_Verr_Reihe2_BFS;
*        ARCH_SW_CIL_pclModeManagement;
*        ARCH_SW_CIL_prrSolenoidState;
*        ARCH_SW_CIL_prrEcsAlgoData_u8EcsFlag;
**/
LOCAL_INLINE void cil_Manage_eCS_Status_Verr_Reihe2_BFS(void)
{
   uint8 u8InitModeStatus = KU8_FALSE;
   uint8 u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   uint8 u8SolenoidDisabledModeStatus = KU8_FALSE;
   uint8 u8CanInhibitModeStatus = KU8_FALSE;
   uint8 u8SolenoidConfigModeStatus = KU8_FALSE;
   uint8 au8SolenoidStates[KU8_MAX_SOLENOID_NB];
   u8EcsTriggerType u8EcsTrigger;

   /* Get all solenoid state */
   (void)Rte_Read_prrSolenoidState_au8SolenoidState(au8SolenoidStates);

   /* Get eCS algo outputs: Driver trigger */
   (void)Rte_Read_prrEcsAlgoData_u8EcsFlag(&u8EcsTrigger);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_INIT_PHASE_IN_PROGRESS, &u8InitModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_ECU_CAN_INHIB_STATUS, &u8CanInhibitModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus((KU64_SOLENOID_6_ABORTION_ERROR | KU64_SOLENOID_6_INHIB_ERROR), &u8SolenoidDisabledModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_6_CONFIGURED, &u8SolenoidConfigModeStatus);

   /* eCS status computation */
   if(KU8_FALSE == u8SolenoidConfigModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx3_nicht_verbaut;
   }
   else if(KU8_TRUE == u8InitModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   }
   else if(B_TRUE == u8SolenoidDisabledModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   }
   else
   {
      if((KU8_STARTUP_STATE == au8SolenoidStates[KU8_SOLENOID_6]) ||
         (KU8_DIAGNOSTIC_STATE == au8SolenoidStates[KU8_SOLENOID_6]))
      {
         if((KU8_ECS_ALGO_LOCK == u8EcsTrigger) ||
            (B_TRUE == u8CanInhibitModeStatus))
         {
            u8SolenoidStatus = (uint8)Cx1_verriegelt;
         }
         else if(KU8_ECS_ALGO_UNLOCK == u8EcsTrigger)
         {
            u8SolenoidStatus = (uint8)Cx2_entriegelt;
         }
         else
         {
            /* do nothing */
         }
      }
      else if((KU8_UNLOCK_STATE == au8SolenoidStates[KU8_SOLENOID_6]) ||
              (KU8_BACKUP_STATE == au8SolenoidStates[KU8_SOLENOID_6]))
      {
         if (B_TRUE == u8CanInhibitModeStatus)
         {
            u8SolenoidStatus = (uint8)Cx1_verriegelt;
         }
         else
         {
            u8SolenoidStatus = (uint8)Cx2_entriegelt;
         }
      }
      else if (KU8_LOCK_STATE == au8SolenoidStates[KU8_SOLENOID_6])
      {
         u8SolenoidStatus = (uint8)Cx1_verriegelt;
      }
      else if (KU8_DISABLED_STATE == au8SolenoidStates[KU8_SOLENOID_6])
      {
         u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
      }
      else
      {
         /* Can not decide */
      }
   }

   /* Write signal to CAN bus */
   (void)Rte_Write_SP_IF_eCS_Status_Verr_Reihe2_BFS_DE_eCS_Status_Verr_Reihe2_BFS(u8SolenoidStatus);
}

/**
* \brief
*        This function is used to output the current state of the solenoid coresponding
*        to the solenoid on the second row, seat FA
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot03
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \ddesignrequirement
*        DSG_cil_Manage_eCS_Status_Verr_Reihe2_FS
* \archrequirement
*        ARCH_SW_CIL_SP_IF_eCS_Status_Verr_Reihe2_FS;
*        ARCH_SW_CIL_pclModeManagement;
*        ARCH_SW_CIL_prrSolenoidState;
*        ARCH_SW_CIL_prrEcsAlgoData_u8EcsFlag;
**/
LOCAL_INLINE void cil_Manage_eCS_Status_Verr_Reihe2_FS(void)
{
   uint8 u8InitModeStatus = KU8_FALSE;
   uint8 u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   uint8 u8SolenoidDisabledModeStatus;
   uint8 u8CanInhibitModeStatus = KU8_ZERO;
   uint8 u8SolenoidConfigModeStatus = KU8_ZERO;
   uint8 au8SolenoidStates[KU8_MAX_SOLENOID_NB];
   u8EcsTriggerType u8EcsTrigger;

   /* Get all solenoid state */
   (void)Rte_Read_prrSolenoidState_au8SolenoidState(au8SolenoidStates);

   /* Get eCS algo outputs: Driver trigger */
   (void)Rte_Read_prrEcsAlgoData_u8EcsFlag(&u8EcsTrigger);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_INIT_PHASE_IN_PROGRESS, &u8InitModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_ECU_CAN_INHIB_STATUS, &u8CanInhibitModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus((KU64_SOLENOID_5_ABORTION_ERROR | KU64_SOLENOID_5_INHIB_ERROR), &u8SolenoidDisabledModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_5_CONFIGURED, &u8SolenoidConfigModeStatus);

   /* eCS status computation */
   if(KU8_FALSE == u8SolenoidConfigModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx3_nicht_verbaut;
   }
   else if(KU8_TRUE == u8InitModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   }
   else if(B_TRUE == u8SolenoidDisabledModeStatus)
   {
      u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
   }
   else
   {
      if((KU8_STARTUP_STATE == au8SolenoidStates[KU8_SOLENOID_5]) ||
         (KU8_DIAGNOSTIC_STATE == au8SolenoidStates[KU8_SOLENOID_5]))
      {
         if((KU8_ECS_ALGO_LOCK == u8EcsTrigger) ||
            (B_TRUE == u8CanInhibitModeStatus))
         {
            u8SolenoidStatus = (uint8)Cx1_verriegelt;
         }
         else if(KU8_ECS_ALGO_UNLOCK == u8EcsTrigger)
         {
            u8SolenoidStatus = (uint8)Cx2_entriegelt;
         }
         else
         {
            /* do nothing */
         }
      }
      else if((KU8_UNLOCK_STATE == au8SolenoidStates[KU8_SOLENOID_5]) ||
              (KU8_BACKUP_STATE == au8SolenoidStates[KU8_SOLENOID_5]))
      {
         if (B_TRUE == u8CanInhibitModeStatus)
         {
            u8SolenoidStatus = (uint8)Cx1_verriegelt;
         }
         else
         {
            u8SolenoidStatus = (uint8)Cx2_entriegelt;
         }
      }
      else if (KU8_LOCK_STATE == au8SolenoidStates[KU8_SOLENOID_5])
      {
         u8SolenoidStatus = (uint8)Cx1_verriegelt;
      }
      else if (KU8_DISABLED_STATE == au8SolenoidStates[KU8_SOLENOID_5])
      {
         u8SolenoidStatus = (uint8)Cx0_Init_oder_Fehler;
      }
      else
      {
         /* Can not decide */
      }
   }

   /* Write signal to CAN bus */
   (void)Rte_Write_SP_IF_eCS_Status_Verr_Reihe2_FS_DE_eCS_Status_Verr_Reihe2_FS(u8SolenoidStatus);
}


/**
* \brief
*        This function is used to output the current error state and error source
*        of the solenoid coresponding to the first solenoid on the front row, seat BF
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot01
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \ddesignrequirement
*        DSG_cil_Manage_eCS_Error_Reihe1_BFS_1
* \archrequirement
*        ARCH_SW_CIL_SP_IF_eCS_Error_Reihe1_BFS_1;
*        ARCH_SW_CIL_prrSolenoidNbOfBackups;
*        ARCH_SW_CIL_prrSolenoidOCStatus;
*        ARCH_SW_CIL_prrSolenoidShortToGndStatus;
*        ARCH_SW_CIL_prrSolenoidShortToVccStatus;
*        ARCH_SW_CIL_prrSolenoidOvervoltageStatus;
*        ARCH_SW_CIL_pclModeManagement;
**/
LOCAL_INLINE void cil_Manage_eCS_Error_Reihe1_BFS_1(void)
{
   uint8 au8SolenoidErrorPresentOpenCircuit[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidErrorPresentShortToGND[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidErrorPresentShortToVBAT[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidOvervoltageStatus[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidIsStuck[KU8_MAX_SOLENOID_NB];
   uint8 u8SolenoidDisabledModeStatus = KU8_FALSE;
   uint8 u8SolenoidConfigModeStatus = KU8_FALSE;
   uint8 u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;

   /* Get Solenoid error status */
   (void)Rte_Read_prrSolenoidOCStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentOpenCircuit);

   (void)Rte_Read_prrSolenoidShortToGndStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentShortToGND);

   (void)Rte_Read_prrSolenoidShortToVccStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentShortToVBAT);

   (void)Rte_Read_prrSolenoidOvervoltageStatus_au8SolenoidOvervoltageStatus(au8SolenoidOvervoltageStatus);

   (void)Rte_Read_prrSolenoidStuckStatus_au8SolenoidIsStuck(au8SolenoidIsStuck);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_3_INHIB_ERROR, &u8SolenoidDisabledModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_3_CONFIGURED, &u8SolenoidConfigModeStatus);

   if(KU8_TRUE == u8SolenoidConfigModeStatus)
   {
      if(KU8_TRUE == u8SolenoidDisabledModeStatus)
      {
         if(KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToVBAT[KU8_SOLENOID_3])
         {
            u8SolenoidErrorStatus = (uint8)Cx2_Kurzschluss_nach_Plus;
         }
         else if((KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOpenCircuit[KU8_SOLENOID_3]) ||
                 (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidOvervoltageStatus[KU8_SOLENOID_3]))
         {
            u8SolenoidErrorStatus = (uint8)Cx3_Open_Circuit;
         }
         else if(KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToGND[KU8_SOLENOID_3])
         {
            u8SolenoidErrorStatus = (uint8)Cx1_Kurzschluss_nach_Masse;
         }
         else if(KU8_TRUE == au8SolenoidIsStuck[KU8_SOLENOID_3])
         {
            u8SolenoidErrorStatus = (uint8)Cx4_Aktor_Spule_Fehler;
         }
         else
         {
            u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
         }
      }
      else
      {
         u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
      }
   }
   else
   {
      u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
   }

   (void)Rte_Write_SP_IF_eCS_Error_Reihe1_BFS_1_DE_eCS_Error_Reihe1_BFS_1(u8SolenoidErrorStatus);
}

/**
* \brief
*        This function is used to output the current error state and error source
*        of the solenoid coresponding to the second solenoid on the front row, seat BF
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot01
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \ddesignrequirement
*        DSG_cil_Manage_eCS_Error_Reihe1_BFS_2
* \archrequirement
*        ARCH_SW_CIL_SP_IF_eCS_Error_Reihe1_BFS_2;
*        ARCH_SW_CIL_prrSolenoidNbOfBackups;
*        ARCH_SW_CIL_prrSolenoidOCStatus;
*        ARCH_SW_CIL_prrSolenoidShortToGndStatus;
*        ARCH_SW_CIL_prrSolenoidShortToVccStatus;
*        ARCH_SW_CIL_prrSolenoidOvervoltageStatus;
*        ARCH_SW_CIL_pclModeManagement;
**/
LOCAL_INLINE void cil_Manage_eCS_Error_Reihe1_BFS_2(void)
{
   uint8 au8SolenoidErrorPresentOpenCircuit[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidErrorPresentShortToGND[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidErrorPresentShortToVBAT[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidOvervoltageStatus[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidIsStuck[KU8_MAX_SOLENOID_NB];
   uint8 u8SolenoidDisabledModeStatus = KU8_FALSE;
   uint8 u8SolenoidConfigModeStatus = KU8_FALSE;
   uint8 u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;

   /* Get Solenoid error status */
   (void)Rte_Read_prrSolenoidOCStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentOpenCircuit);

   (void)Rte_Read_prrSolenoidShortToGndStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentShortToGND);

   (void)Rte_Read_prrSolenoidShortToVccStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentShortToVBAT);

   (void)Rte_Read_prrSolenoidOvervoltageStatus_au8SolenoidOvervoltageStatus(au8SolenoidOvervoltageStatus);

   (void)Rte_Read_prrSolenoidStuckStatus_au8SolenoidIsStuck(au8SolenoidIsStuck);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_4_INHIB_ERROR, &u8SolenoidDisabledModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_4_CONFIGURED, &u8SolenoidConfigModeStatus);

   if(KU8_TRUE == u8SolenoidConfigModeStatus)
   {
      if(KU8_TRUE == u8SolenoidDisabledModeStatus)
      {
         if(KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToVBAT[KU8_SOLENOID_4])
         {
            u8SolenoidErrorStatus = (uint8)Cx2_Kurzschluss_nach_Plus;
         }
         else if((KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOpenCircuit[KU8_SOLENOID_4]) ||
                 (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidOvervoltageStatus[KU8_SOLENOID_4]))
         {
            u8SolenoidErrorStatus = (uint8)Cx3_Open_Circuit;
         }
         else if(KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToGND[KU8_SOLENOID_4])
         {
            u8SolenoidErrorStatus = (uint8)Cx1_Kurzschluss_nach_Masse;
         }
         else if(KU8_TRUE == au8SolenoidIsStuck[KU8_SOLENOID_4])
         {
            u8SolenoidErrorStatus = (uint8)Cx4_Aktor_Spule_Fehler;
         }
         else
         {
            u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
         }
      }
      else
      {
         u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
      }
   }
   else
   {
      u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
   }

   (void)Rte_Write_SP_IF_eCS_Error_Reihe1_BFS_2_DE_eCS_Error_Reihe1_BFS_2(u8SolenoidErrorStatus);
}

/**
* \brief
*        This function is used to output the current error state and error source
*        of the solenoid coresponding to the first solenoid on the front row, seat FA
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot02
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \ddesignrequirement
*        DSG_cil_Manage_eCS_Error_Reihe1_FS_1
* \archrequirement
*        ARCH_SW_CIL_SP_IF_eCS_Error_Reihe1_FS_1;
*        ARCH_SW_CIL_prrSolenoidNbOfBackups;
*        ARCH_SW_CIL_prrSolenoidOCStatus;
*        ARCH_SW_CIL_prrSolenoidShortToGndStatus;
*        ARCH_SW_CIL_prrSolenoidShortToVccStatus;
*        ARCH_SW_CIL_prrSolenoidOvervoltageStatus;
*        ARCH_SW_CIL_pclModeManagement;
**/
LOCAL_INLINE void cil_Manage_eCS_Error_Reihe1_FS_1(void)
{
   uint8 au8SolenoidErrorPresentOpenCircuit[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidErrorPresentShortToGND[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidErrorPresentShortToVBAT[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidOvervoltageStatus[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidIsStuck[KU8_MAX_SOLENOID_NB];
   uint8 u8SolenoidDisabledModeStatus = KU8_FALSE;
   uint8 u8SolenoidConfigModeStatus = KU8_FALSE;
   uint8 u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;

   /* Get Solenoid error status */
   (void)Rte_Read_prrSolenoidOCStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentOpenCircuit);

   (void)Rte_Read_prrSolenoidShortToGndStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentShortToGND);

   (void)Rte_Read_prrSolenoidShortToVccStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentShortToVBAT);

   (void)Rte_Read_prrSolenoidOvervoltageStatus_au8SolenoidOvervoltageStatus(au8SolenoidOvervoltageStatus);

   (void)Rte_Read_prrSolenoidStuckStatus_au8SolenoidIsStuck(au8SolenoidIsStuck);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_1_INHIB_ERROR, &u8SolenoidDisabledModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_1_CONFIGURED, &u8SolenoidConfigModeStatus);

   if(KU8_TRUE == u8SolenoidConfigModeStatus)
   {
      if(KU8_TRUE == u8SolenoidDisabledModeStatus)
      {
         if(KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToVBAT[KU8_SOLENOID_1])
         {
            u8SolenoidErrorStatus = (uint8)Cx2_Kurzschluss_nach_Plus;
         }
         else if((KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOpenCircuit[KU8_SOLENOID_1]) ||
                 (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidOvervoltageStatus[KU8_SOLENOID_1]))
         {
            u8SolenoidErrorStatus = (uint8)Cx3_Open_Circuit;
         }
         else if(KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToGND[KU8_SOLENOID_1])
         {
            u8SolenoidErrorStatus = (uint8)Cx1_Kurzschluss_nach_Masse;
         }
         else if(KU8_TRUE == au8SolenoidIsStuck[KU8_SOLENOID_1])
         {
            u8SolenoidErrorStatus = (uint8)Cx4_Aktor_Spule_Fehler;
         }
         else
         {
            u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
         }
      }
      else
      {
         u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
      }
   }
   else
   {
      u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
   }

   (void)Rte_Write_SP_IF_eCS_Error_Reihe1_FS_1_DE_eCS_Error_Reihe1_FS_1(u8SolenoidErrorStatus);
}

/**
* \brief
*        This function is used to output the current error state and error source
*        of the solenoid coresponding to the second solenoid on the front row, seat FA
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot02
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \ddesignrequirement
*        DSG_cil_Manage_eCS_Error_Reihe1_FS_2
* \archrequirement
*        ARCH_SW_CIL_SP_IF_eCS_Error_Reihe1_FS_2;
*        ARCH_SW_CIL_prrSolenoidNbOfBackups;
*        ARCH_SW_CIL_prrSolenoidOCStatus;
*        ARCH_SW_CIL_prrSolenoidShortToGndStatus;
*        ARCH_SW_CIL_prrSolenoidShortToVccStatus;
*        ARCH_SW_CIL_prrSolenoidOvervoltageStatus;
*        ARCH_SW_CIL_pclModeManagement;
**/
LOCAL_INLINE void cil_Manage_eCS_Error_Reihe1_FS_2(void)
{
   uint8 au8SolenoidErrorPresentOpenCircuit[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidErrorPresentShortToGND[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidErrorPresentShortToVBAT[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidOvervoltageStatus[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidIsStuck[KU8_MAX_SOLENOID_NB];
   uint8 u8SolenoidDisabledModeStatus = KU8_FALSE;
   uint8 u8SolenoidConfigModeStatus = KU8_FALSE;
   uint8 u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;

   /* Get Solenoid error status */
   (void)Rte_Read_prrSolenoidOCStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentOpenCircuit);

   (void)Rte_Read_prrSolenoidShortToGndStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentShortToGND);

   (void)Rte_Read_prrSolenoidShortToVccStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentShortToVBAT);

   (void)Rte_Read_prrSolenoidOvervoltageStatus_au8SolenoidOvervoltageStatus(au8SolenoidOvervoltageStatus);

   (void)Rte_Read_prrSolenoidStuckStatus_au8SolenoidIsStuck(au8SolenoidIsStuck);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_2_INHIB_ERROR, &u8SolenoidDisabledModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_2_CONFIGURED, &u8SolenoidConfigModeStatus);

   if(KU8_TRUE == u8SolenoidConfigModeStatus)
   {
      if(KU8_TRUE == u8SolenoidDisabledModeStatus)
      {
         if(KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToVBAT[KU8_SOLENOID_2])
         {
            u8SolenoidErrorStatus = (uint8)Cx2_Kurzschluss_nach_Plus;
         }
         else if((KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOpenCircuit[KU8_SOLENOID_2]) ||
                 (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidOvervoltageStatus[KU8_SOLENOID_2]))
         {
            u8SolenoidErrorStatus = (uint8)Cx3_Open_Circuit;
         }
         else if(KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToGND[KU8_SOLENOID_2])
         {
            u8SolenoidErrorStatus = (uint8)Cx1_Kurzschluss_nach_Masse;
         }
         else if(KU8_TRUE == au8SolenoidIsStuck[KU8_SOLENOID_2])
         {
            u8SolenoidErrorStatus = (uint8)Cx4_Aktor_Spule_Fehler;
         }
         else
         {
            u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
         }
      }
      else
      {
         u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
      }
   }
   else
   {
      u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
   }

   (void)Rte_Write_SP_IF_eCS_Error_Reihe1_FS_2_DE_eCS_Error_Reihe1_FS_2(u8SolenoidErrorStatus);
}

/**
* \brief
*        This function is used to output the current error state and error source
*        of the solenoid coresponding to the solenoid on the second row, seat BF
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot04
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \ddesignrequirement
*        DSG_cil_Manage_eCS_Error_Reihe2_BFS
* \archrequirement
*        ARCH_SW_CIL_SP_IF_eCS_Error_Reihe2_BFS;
*        ARCH_SW_CIL_prrSolenoidNbOfBackups;
*        ARCH_SW_CIL_prrSolenoidOCStatus;
*        ARCH_SW_CIL_prrSolenoidShortToGndStatus;
*        ARCH_SW_CIL_prrSolenoidShortToVccStatus;
*        ARCH_SW_CIL_prrSolenoidOvervoltageStatus;
*        ARCH_SW_CIL_pclModeManagement;
**/
LOCAL_INLINE void cil_Manage_eCS_Error_Reihe2_BFS(void)
{
   uint8 au8SolenoidErrorPresentOpenCircuit[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidErrorPresentShortToGND[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidErrorPresentShortToVBAT[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidOvervoltageStatus[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidIsStuck[KU8_MAX_SOLENOID_NB];
   uint8 u8SolenoidDisabledModeStatus = KU8_FALSE;
   uint8 u8SolenoidConfigModeStatus = KU8_FALSE;
   uint8 u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;

   /* Get Solenoid error status */
   (void)Rte_Read_prrSolenoidOCStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentOpenCircuit);

   (void)Rte_Read_prrSolenoidShortToGndStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentShortToGND);

   (void)Rte_Read_prrSolenoidShortToVccStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentShortToVBAT);

   (void)Rte_Read_prrSolenoidOvervoltageStatus_au8SolenoidOvervoltageStatus(au8SolenoidOvervoltageStatus);

   (void)Rte_Read_prrSolenoidStuckStatus_au8SolenoidIsStuck(au8SolenoidIsStuck);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_6_INHIB_ERROR, &u8SolenoidDisabledModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_6_CONFIGURED, &u8SolenoidConfigModeStatus);

   if(KU8_TRUE == u8SolenoidConfigModeStatus)
   {
      if(KU8_TRUE == u8SolenoidDisabledModeStatus)
      {
         if(KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToVBAT[KU8_SOLENOID_6])
         {
            u8SolenoidErrorStatus = (uint8)Cx2_Kurzschluss_nach_Plus;
         }
         else if((KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOpenCircuit[KU8_SOLENOID_6]) ||
                 (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidOvervoltageStatus[KU8_SOLENOID_6]))
         {
            u8SolenoidErrorStatus = (uint8)Cx3_Open_Circuit;
         }
         else if(KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToGND[KU8_SOLENOID_6])
         {
            u8SolenoidErrorStatus = (uint8)Cx1_Kurzschluss_nach_Masse;
         }
         else if(KU8_TRUE == au8SolenoidIsStuck[KU8_SOLENOID_6])
         {
            u8SolenoidErrorStatus = (uint8)Cx4_Aktor_Spule_Fehler;
         }
         else
         {
            u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
         }
      }
      else
      {
         u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
      }
   }
   else
   {
      u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
   }

   (void)Rte_Write_SP_IF_eCS_Error_Reihe2_BFS_DE_eCS_Error_Reihe2_BFS(u8SolenoidErrorStatus);
}

/**
* \brief
*        This function is used to output the current error state and error source
*        of the solenoid coresponding to the solenoid on the second row, seat FA
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot04
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \ddesignrequirement
*        DSG_cil_Manage_eCS_Error_Reihe2_FS
* \archrequirement
*        ARCH_SW_CIL_SP_IF_eCS_Error_Reihe2_FS;
*        ARCH_SW_CIL_prrSolenoidNbOfBackups;
*        ARCH_SW_CIL_prrSolenoidOCStatus;
*        ARCH_SW_CIL_prrSolenoidShortToGndStatus;
*        ARCH_SW_CIL_prrSolenoidShortToVccStatus;
*        ARCH_SW_CIL_prrSolenoidOvervoltageStatus;
*        ARCH_SW_CIL_pclModeManagement;
**/
LOCAL_INLINE void cil_Manage_eCS_Error_Reihe2_FS(void)
{
   uint8 au8SolenoidErrorPresentOpenCircuit[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidErrorPresentShortToGND[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidErrorPresentShortToVBAT[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidOvervoltageStatus[KU8_GLOBAL_NUMBER_OF_SOLENOIDS];
   uint8 au8SolenoidIsStuck[KU8_MAX_SOLENOID_NB];
   uint8 u8SolenoidDisabledModeStatus = KU8_FALSE;
   uint8 u8SolenoidConfigModeStatus = KU8_FALSE;
   uint8 u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;

   /* Get Solenoid error status */
   (void)Rte_Read_prrSolenoidOCStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentOpenCircuit);

   (void)Rte_Read_prrSolenoidShortToGndStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentShortToGND);

   (void)Rte_Read_prrSolenoidShortToVccStatus_au8SolenoidAutotestStatus(au8SolenoidErrorPresentShortToVBAT);

   (void)Rte_Read_prrSolenoidOvervoltageStatus_au8SolenoidOvervoltageStatus(au8SolenoidOvervoltageStatus);

   (void)Rte_Read_prrSolenoidStuckStatus_au8SolenoidIsStuck(au8SolenoidIsStuck);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_5_INHIB_ERROR, &u8SolenoidDisabledModeStatus);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(KU64_SOLENOID_5_CONFIGURED, &u8SolenoidConfigModeStatus);

   if(KU8_TRUE == u8SolenoidConfigModeStatus)
   {
      if(KU8_TRUE == u8SolenoidDisabledModeStatus)
      {
         if(KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToVBAT[KU8_SOLENOID_5])
         {
            u8SolenoidErrorStatus = (uint8)Cx2_Kurzschluss_nach_Plus;
         }
         else if((KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentOpenCircuit[KU8_SOLENOID_5]) ||
                 (KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidOvervoltageStatus[KU8_SOLENOID_5]))
         {
            u8SolenoidErrorStatus = (uint8)Cx3_Open_Circuit;
         }
         else if(KU8_SOLENOID_ELECTRICAL_AT_FAILED == au8SolenoidErrorPresentShortToGND[KU8_SOLENOID_5])
         {
            u8SolenoidErrorStatus = (uint8)Cx1_Kurzschluss_nach_Masse;
         }
         else if(KU8_TRUE == au8SolenoidIsStuck[KU8_SOLENOID_5])
         {
            u8SolenoidErrorStatus = (uint8)Cx4_Aktor_Spule_Fehler;
         }
         else
         {
            u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
         }
      }
      else
      {
         u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
      }
   }
   else
   {
      u8SolenoidErrorStatus = (uint8)Cx0_kein_Fehler;
   }

   (void)Rte_Write_SP_IF_eCS_Error_Reihe2_FS_DE_eCS_Error_Reihe2_FS(u8SolenoidErrorStatus);
}

/**
* \brief
*        This function is used to output the last valid state of the seat occupancy
*        sensor coresponding to the first seat on the second row
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot05
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \ddesignrequirement
*        DSG_cil_Manage_eCS_SBS_LastState_Reihe2_FS
* \archrequirement
*        ARCH_SW_CIL_SP_IF_eCS_SBS_LastState_Reihe2_FS
**/
LOCAL_INLINE void cil_Manage_eCS_SBS_LastState_Reihe2_FS(void)
{
   uint8 u8SbsLastStateValue = Cx0_Init;

   if(KB_SBS_LAST_STATE_ENABLED_VARIANT)
   {
      /* Read last saved data from NvM */
      switch(NVP_au8SBSLastState[KU8_ZERO])
      {
         case KU8_SEAT_OCCUPANCY_SHORT_TO_GND:
         {
            /* Translate internal value to CAN signal */
            u8SbsLastStateValue = Cx3_Fehler;
            break;
         }
         case KU8_SEAT_OCCUPANCY_DETECTED:
         {
            /* Translate internal value to CAN signal */
            u8SbsLastStateValue = Cx1_belegt;
            break;
         }
         case KU8_SEAT_OCCUPANCY_NOT_DETECTED:
         {
            /* Translate internal value to CAN signal */
            u8SbsLastStateValue = Cx2_nicht_belegt;
            break;
         }
         case KU8_SEAT_OCCUPANCY_UNKNOWN:
         {
            /* Translate internal value to CAN signal */
            u8SbsLastStateValue = Cx3_Fehler;
            break;
         }
         default:
         {
            break;
         }
      }
   }

   (void)Rte_Write_SP_IF_eCS_SBS_LastState_Reihe2_FS_DE_eCS_SBS_LastState_Reihe2_FS(u8SbsLastStateValue);
}

/**
* \brief
*        This function is used to output the last valid state of the seat occupancy
*        sensor coresponding to the second seat on the second row
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot05
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \ddesignrequirement
*        DSG_cil_Manage_eCS_SBS_LastState_Reihe2_BFS
* \archrequirement
*        ARCH_SW_CIL_SP_IF_eCS_SBS_LastState_Reihe2_BFS
**/
LOCAL_INLINE void cil_Manage_eCS_SBS_LastState_Reihe2_BFS(void)
{
   uint8 u8SbsLastStateValue = Cx0_Init;

   if(KB_SBS_LAST_STATE_ENABLED_VARIANT)
   {
      /* Read last saved data from NvM */
      switch(NVP_au8SBSLastState[KU8_ONE])
      {
         case KU8_SEAT_OCCUPANCY_SHORT_TO_GND:
         {
            /* Translate internal value to CAN signal */
            u8SbsLastStateValue = Cx3_Fehler;
            break;
         }
         case KU8_SEAT_OCCUPANCY_DETECTED:
         {
            /* Translate internal value to CAN signal */
            u8SbsLastStateValue = Cx1_belegt;
            break;
         }
         case KU8_SEAT_OCCUPANCY_NOT_DETECTED:
         {
            /* Translate internal value to CAN signal */
            u8SbsLastStateValue = Cx2_nicht_belegt;
            break;
         }
         case KU8_SEAT_OCCUPANCY_UNKNOWN:
         {
            /* Translate internal value to CAN signal */
            u8SbsLastStateValue = Cx3_Fehler;
            break;
         }
         default:
         {
            break;
         }
      }
   }

   (void)Rte_Write_SP_IF_eCS_SBS_LastState_Reihe2_BFS_DE_eCS_SBS_LastState_Reihe2_BFS(u8SbsLastStateValue);
}

/**
* \brief
*        This function is used to gather data necessary to compute the seat occupancy
*        status
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot04
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \constrains
*        NVP_u8EnableDevFrame must be != KU8_ZERO (DevKit Frame is enabled)
* \ddesignrequirement
*        DSG_cil_Manage_eCS_DevKit_Seat_Occupancy_Status
* \archrequirement
*        ARCH_SW_CIL_P_CAN_CanDataOut_Frame_0
**/
LOCAL_INLINE void cil_Manage_eCS_DevKit_Seat_Occupancy_Status(void)
{
   /* Fill Development Frame with acquisition data */
   cil_u8EcuCanDataOutFrame0Content.u8Byte37 = CIL_u8SeatOccupancySensorTx[KU8_ZERO];
   cil_u8EcuCanDataOutFrame0Content.u8Byte38 = CIL_u8SeatOccupancySensorTx[KU8_ONE];
   cil_u8EcuCanDataOutFrame0Content.u8Byte39 = CIL_u8SeatOccupancySensorTx[KU8_TWO];
   cil_u8EcuCanDataOutFrame0Content.u8Byte40 = CIL_u8SeatOccupancySensorTx[KU8_THREE];
}

/**
* \brief
*        This function is used to gather data necessary to compute the HW Defekt
*        signal
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot04
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \constrains
*        NVP_u8EnableDevFrame must be != KU8_ZERO (DevKit Frame is enabled)
* \ddesignrequirement
*        DSG_cil_Manage_eCS_HW_defekt
* \archrequirement
*        ARCH_SW_CIL_pclModeManagement;
*        ARCH_SW_CIL_SP_IF_eCS_HW_defekt_XIX_Grundumfang_XIX_eCS;
**/
LOCAL_INLINE void cil_Manage_eCS_HW_defekt(void)
{
   register uint64 u64ModesToCheck = KU64_ZERO;
   uint8 u8HwDefektRx = B_FALSE;
   register uint8 u8HwDefektTx = CM_eCS_HW_defekt_Cx1_Defekt;

   u64ModesToCheck = KU64_ECU_PERMANENT_HW_ERROR;
   (void)Rte_Call_pclModeManagement_CheckModeStatus(u64ModesToCheck, &u8HwDefektRx);
   if(B_TRUE == u8HwDefektRx)
   {
      u8HwDefektTx = (uint8)CM_eCS_HW_defekt_Cx1_Defekt;
   }
   else
   {
      u8HwDefektTx = (uint8)CM_eCS_HW_defekt_Cx0_nicht_defekt;
   }

   /* Signal: eCS_HW_defekt */
   (void)Rte_Write_SP_IF_eCS_HW_defekt_XIX_Grundumfang_XIX_eCS_DE_eCS_HW_defekt(u8HwDefektTx);
}

/**
* \brief
*        This function is used to gather data necessary to compute the Stoerung
*        signal
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot04
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \constrains
*        NVP_u8EnableDevFrame must be != KU8_ZERO (DevKit Frame is enabled)
* \ddesignrequirement
*        DSG_cil_Manage_eCS_Stoerung
* \archrequirement
*        ARCH_SW_CIL_pclModeManagement;
*        ARCH_SW_CIL_SP_IF_eCS_Stoerung_XIX_Grundumfang_XIX_eCS;
**/
LOCAL_INLINE void cil_Manage_eCS_Stoerung(void)
{
   register uint64 u64ModesToCheck = KU64_ZERO;
   uint8 u8SporadicErrorRx = B_FALSE;
   register uint8 u8SporadicErrorTx = (uint8)CM_eCS_Stoerung_Cx1_Stoerung;

   u64ModesToCheck = KU64_ECU_SPORADIC_ERROR;
   (void)Rte_Call_pclModeManagement_CheckModeStatus(u64ModesToCheck, &u8SporadicErrorRx);
   if(B_TRUE == u8SporadicErrorRx)
   {
      u8SporadicErrorTx = (uint8)CM_eCS_Stoerung_Cx1_Stoerung;
   }
   else
   {
      if(KU8_TRUE == cil_u8UnknownStatusFrameError)
      {
         u8SporadicErrorTx = (uint8)CM_eCS_Stoerung_Cx1_Stoerung;
      }
      else
      {
         u8SporadicErrorTx = (uint8)CM_eCS_Stoerung_Cx0_keine_Stoerung;
      }
   }

   /* Signal: eCS_Stoerung */
   (void)Rte_Write_SP_IF_eCS_Stoerung_XIX_Grundumfang_XIX_eCS_DE_eCS_Stoerung(u8SporadicErrorTx);
}

/**
* \brief
*        This function is used to gather data necessary to compute the current status
*        of the eCS ECU
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot03
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \constrains
*        NVP_u8EnableDevFrame must be != KU8_ZERO (DevKit Frame is enabled)
* \ddesignrequirement
*        DSG_cil_Manage_eCS_Status
* \archrequirement
*        ARCH_SW_CIL_SP_IF_eCS_Status_XIX_Grundumfang_XIX_eCS;
*        ARCH_SW_CIL_prrEcsAlgoData_u8EcsFlag;
*        ARCH_SW_CIL_pclModeManagement;
**/
LOCAL_INLINE void cil_Manage_eCS_Status(void)
{
   uint8 u8InitModeStatus = KU8_FALSE;
   register uint64 u64ModesToCheck = KU64_ZERO;
   register uint8 u8MergedECSStatus = (uint8)CM_eCS_Status_Cx3_Fehler;
   uint8 u8SolenoidDisabledModeStatus = KU8_FALSE;
   uint8 u8CanInhibitModeStatus = KU8_FALSE;
   u8EcsTriggerType u8EcsTrigger;

   /* Get eCS algo outputs: Driver trigger */
   (void)Rte_Read_prrEcsAlgoData_u8EcsFlag(&u8EcsTrigger);

   u64ModesToCheck = KU64_INIT_PHASE_IN_PROGRESS;
   (void)Rte_Call_pclModeManagement_CheckModeStatus(u64ModesToCheck, &u8InitModeStatus);

   u64ModesToCheck = (KU64_SOLENOID_1_ABORTION_ERROR | KU64_SOLENOID_2_ABORTION_ERROR | KU64_SOLENOID_3_ABORTION_ERROR |
                      KU64_SOLENOID_3_ABORTION_ERROR | KU64_SOLENOID_5_ABORTION_ERROR | KU64_SOLENOID_6_ABORTION_ERROR |
                      KU64_SOLENOID_1_INHIB_ERROR    |    KU64_SOLENOID_2_INHIB_ERROR | KU64_SOLENOID_3_INHIB_ERROR    |
                      KU64_SOLENOID_4_INHIB_ERROR    |    KU64_SOLENOID_5_INHIB_ERROR | KU64_SOLENOID_6_INHIB_ERROR);

   (void)Rte_Call_pclModeManagement_CheckModeStatus(u64ModesToCheck, &u8SolenoidDisabledModeStatus);

   u64ModesToCheck = KU64_ECU_CAN_INHIB_STATUS;
   (void)Rte_Call_pclModeManagement_CheckModeStatus(u64ModesToCheck, &u8CanInhibitModeStatus);

   /* eCS status computation */
   if(KU8_TRUE == u8InitModeStatus)
   {
      if(KU32_CIL_INIT_STATUS_FRAME_TIMEOUT_VAL > cil_u32ReportInitStatusTimeoutCnt)
      {
         cil_u32ReportInitStatusTimeoutCnt += KU32_ONE;

         u8MergedECSStatus = (uint8)CM_eCS_Status_Cx0_Init;
      }
      else if(B_TRUE == u8SolenoidDisabledModeStatus)
      {
         u8MergedECSStatus = (uint8)CM_eCS_Status_Cx3_Fehler;
      }
      else
      {
         cil_u8UnknownStatusFrameError = KU8_TRUE;

         u8MergedECSStatus = (uint8)CM_eCS_Status_Cx3_Fehler;
      }
   }
   else
   {
      if(B_TRUE == u8SolenoidDisabledModeStatus)
      {
         u8MergedECSStatus = (uint8)CM_eCS_Status_Cx3_Fehler;
      }
      else
      {
         if(KU8_ECS_ALGO_UNLOCK == u8EcsTrigger)
         {
            if (B_TRUE == u8CanInhibitModeStatus)
            {
               u8MergedECSStatus = (uint8)CM_eCS_Status_Cx1_verriegelt;
            }
            else
            {
               /* No way to difference between unlock states from feedback point of view */
               u8MergedECSStatus = (uint8)CM_eCS_Status_Cx2_entriegelt;
            }
         }
         else if (KU8_ECS_ALGO_LOCK == u8EcsTrigger)
         {
            u8MergedECSStatus = (uint8)CM_eCS_Status_Cx1_verriegelt;
         }
         else
         {
            /* Can not decide */
         }
      }

      cil_u32ReportInitStatusTimeoutCnt = KU32_ZERO;
   }

   if(KU32_ZERO == cil_u32ReportInitStatusTimeoutCnt)
   {
      cil_u8UnknownStatusFrameError = KU8_FALSE;
   }

   /* Signal: eCS_Status */
   (void)Rte_Write_SP_IF_eCS_Status_XIX_Grundumfang_XIX_eCS_DE_eCS_Status(u8MergedECSStatus);
}

/**
* \brief
*        This function is used to gather data on the current status of the buckles
*        corresponding to seats 1&&2 on the 2nd row
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot01
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \constrains
*        NVP_u8EnableDevFrame must be != KU8_ZERO (DevKit Frame is enabled)
* \ddesignrequirement
*        DSG_cil_Manage_eCS_Gurtschloss_Status
* \archrequirement
*        ARCH_SW_CIL_SP_IF_eCS_Gurtschloss_Status_Reihe2_FA_XIX_Grundumfang_XIX_eCS;
*        ARCH_SW_CIL_SP_IF_eCS_Gurtschloss_Status_Reihe2_BF_XIX_Grundumfang_XIX_eCS;
*        ARCH_SW_CIL_prrBuckleStatus;
*        ARCH_SW_CIL_psrCILData_au8MergedBuckleStatus;
**/
LOCAL_INLINE void cil_Manage_eCS_Gurtschloss_Status(void)
{
   uint8 u8BuckleStatusRx[CIL_NO_OF_BUCKLES];
   uint8 u8MergedBuckleStatus[CIL_NO_OF_BUCKLES];
   register uint8 u8Idx;

   /* Get status for all buckles and map to CAN signal (values read from Airbag_02 for existing buckles will be overwritten) */
   (void)Rte_Read_CIL_prrBuckleStatus_au8BuckleStatus(u8BuckleStatusRx);

   /* Buckle 5 status */
   if (KUB_eCS_BKL_SEAT_1_NOT_CONFIGURED_VARIANT)
   {
      /* Buckle 5 not coded */
       CIL_u8BuckleStatusTx[KU8_FOUR] = (uint8)CM_eCS_Gurtschloss_Status_Reihe2_FA_Cx0_nicht_verbaut;
   }
   else
   {
      switch (u8BuckleStatusRx[KU8_ZERO])
      {
      case KU8_BUCKLE_NOT_LATCHED:
         if(KB_BUCKLE_1_INVERTED_LOGIC_ACTIVATED)
         {
            CIL_u8BuckleStatusTx[KU8_FOUR] = (uint8)CM_eCS_Gurtschloss_Status_Reihe2_FA_Cx3_gesteckt;
         }
         else
         {
            CIL_u8BuckleStatusTx[KU8_FOUR] = (uint8)CM_eCS_Gurtschloss_Status_Reihe2_FA_Cx2_nicht_gesteckt;
         }
         break;
      case KU8_BUCKLE_LATCHED:
         if(KB_BUCKLE_1_INVERTED_LOGIC_ACTIVATED)
         {
            CIL_u8BuckleStatusTx[KU8_FOUR] = (uint8)CM_eCS_Gurtschloss_Status_Reihe2_FA_Cx2_nicht_gesteckt;
         }
         else
         {
            CIL_u8BuckleStatusTx[KU8_FOUR] = (uint8)CM_eCS_Gurtschloss_Status_Reihe2_FA_Cx3_gesteckt;
         }
         break;
      default: /* KU8_BUCKLE_UNKNOWN or random value due to memory corruption */
         CIL_u8BuckleStatusTx[KU8_FOUR] = (uint8)CM_eCS_Gurtschloss_Status_Reihe2_FA_Cx1_nicht_verfuegbar_Fehler_o_Init;
         break;
      }
   }

   /* Buckle 6 status */
   if (KUB_eCS_BKL_SEAT_2_NOT_CONFIGURED_VARIANT)
   {
      /* Buckle 6 not coded */
       CIL_u8BuckleStatusTx[KU8_FIVE] = (uint8)CM_eCS_Gurtschloss_Status_Reihe2_BF_Cx0_nicht_verbaut;
   }
   else
   {
      switch (u8BuckleStatusRx[KU8_ONE])
      {
      case KU8_BUCKLE_NOT_LATCHED:
         if(KB_BUCKLE_2_INVERTED_LOGIC_ACTIVATED)
         {
            CIL_u8BuckleStatusTx[KU8_FIVE] = (uint8)CM_eCS_Gurtschloss_Status_Reihe2_BF_Cx3_gesteckt;
         }
         else
         {
            CIL_u8BuckleStatusTx[KU8_FIVE] = (uint8)CM_eCS_Gurtschloss_Status_Reihe2_BF_Cx2_nicht_gesteckt;
         }
         break;
      case KU8_BUCKLE_LATCHED:
         if(KB_BUCKLE_2_INVERTED_LOGIC_ACTIVATED)
         {
            CIL_u8BuckleStatusTx[KU8_FIVE] = (uint8)CM_eCS_Gurtschloss_Status_Reihe2_BF_Cx2_nicht_gesteckt;
         }
         else
         {
            CIL_u8BuckleStatusTx[KU8_FIVE] = (uint8)CM_eCS_Gurtschloss_Status_Reihe2_BF_Cx3_gesteckt;
         }
         break;
      default: /* KU8_BUCKLE_UNKNOWN or random value due to memory corruption */
         CIL_u8BuckleStatusTx[KU8_FIVE] = (uint8)CM_eCS_Gurtschloss_Status_Reihe2_BF_Cx1_nicht_verfuegbar_Fehler_o_Init;
         break;
      }
   }

   /* Build the merged internal buckle status and make it visible */
   for (u8Idx = KU8_ZERO; u8Idx < CIL_NO_OF_BUCKLES; u8Idx++)
   {
      if((uint8)CM_eCS_Gurtschloss_Status_Reihe2_BF_Cx3_gesteckt == CIL_u8BuckleStatusTx[u8Idx])
      {
         u8MergedBuckleStatus[u8Idx] = (uint8)KU8_BUCKLE_LATCHED;
      }
      else if ((uint8)CM_eCS_Gurtschloss_Status_Reihe2_BF_Cx2_nicht_gesteckt == CIL_u8BuckleStatusTx[u8Idx])
      {
         u8MergedBuckleStatus[u8Idx] = (uint8)KU8_BUCKLE_NOT_LATCHED;
      }
      else
      {
         u8MergedBuckleStatus[u8Idx] = (uint8)KU8_BUCKLE_UNKNOWN;
      }
   }

   /* write merged buckle status to the rest of the Application */
   (void)Rte_Write_CIL_psrCILData_au8MergedBuckleStatus(u8MergedBuckleStatus);

   /* Signal: eCS_Gurtschloss_Status_Reihe2_FA */
   (void)Rte_Write_SP_IF_eCS_Gurtschloss_Status_Reihe2_FA_XIX_Grundumfang_XIX_eCS_DE_eCS_Gurtschloss_Status_Reihe2_FA(CIL_u8BuckleStatusTx[KU8_FOUR]);

   /* Signal: eCS_Gurtschloss_Status_Reihe2_BF */
   (void)Rte_Write_SP_IF_eCS_Gurtschloss_Status_Reihe2_BF_XIX_Grundumfang_XIX_eCS_DE_eCS_Gurtschloss_Status_Reihe2_BF(CIL_u8BuckleStatusTx[KU8_FIVE]);
}

/**
* \brief
*        This function is used to gather data on the current status of the buckles
*        corresponding to seats 1&&2 on the 1st row
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot01
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \constrains
*        NVP_u8EnableDevFrame must be != KU8_ZERO (DevKit Frame is enabled)
* \ddesignrequirement
*        DSG_cil_Manage_eCS_DevKit_Buckle_Status
* \archrequirement
*        ARCH_SW_CIL_P_CAN_CanDataOut_Frame
**/
LOCAL_INLINE void cil_Manage_eCS_DevKit_Buckle_Status(void)
{
   /* write data to CAN frame */
   cil_u8EcuCanDataOutFrame0Content.u8Byte31 = CIL_u8BuckleStatusTx[KU8_ZERO];
   cil_u8EcuCanDataOutFrame0Content.u8Byte32 = CIL_u8BuckleStatusTx[KU8_ONE];
   cil_u8EcuCanDataOutFrame0Content.u8Byte33 = CIL_u8BuckleStatusTx[KU8_TWO];
   cil_u8EcuCanDataOutFrame0Content.u8Byte34 = CIL_u8BuckleStatusTx[KU8_THREE];
   cil_u8EcuCanDataOutFrame0Content.u8Byte35 = CIL_u8BuckleStatusTx[KU8_FOUR];
   cil_u8EcuCanDataOutFrame0Content.u8Byte36 = CIL_u8BuckleStatusTx[KU8_FIVE];
}

/**
* \brief
*        This function is used to gather data what profiles are currently executed
*        on each solenoid
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot01
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \constrains
*        NVP_u8EnableDevFrame must be != KU8_ZERO (DevKit Frame is enabled)
* \ddesignrequirement
*        DSG_cil_Manage_eCS_DevKit_Solenoid_Profiles_States
* \archrequirement
*        ARCH_SW_CIL_pclSolenoidProfile;
*        ARCH_SW_CIL_pclSolenoidStep;
*        ARCH_SW_CIL_prrSolenoidState;
**/
LOCAL_INLINE void cil_Manage_eCS_DevKit_Solenoid_Profiles_States(void)
{
   uint8 au8CurrentStep[sizeof(au8CurrentStepType)];
   uint8 au8SelectedProfile[sizeof(au8SolenoidProfileType)];
   uint8 au8SolenoidStates[KU8_MAX_SOLENOID_NB];
   register uint8 u8SolenoidsStates12;
   register uint8 u8SolenoidsStates34;
   register uint8 u8SolenoidsStates56;

   /* Get solenoid current step */
   (void)Rte_Read_CIL_pclSolenoidStep_au8CurrentStep(au8CurrentStep);

   /* Get solenoid profile */
   (void)Rte_Read_pclSolenoidProfile_au8SelectedProfile(au8SelectedProfile);

   /* Get all solenoid state */
   (void)Rte_Read_prrSolenoidState_au8SolenoidState(au8SolenoidStates);

   /* Concatenates the solenoids 1 and 2 states */
   u8SolenoidsStates12 = (uint8)((au8SolenoidStates[KU8_SOLENOID_2] & KU8_CIL_SOLENOID_STATE_MASK) << KU8_THREE) |
                                 (au8SolenoidStates[KU8_SOLENOID_1] & KU8_CIL_SOLENOID_STATE_MASK);

   /* Concatenates the solenoids 3 and 4 states */
   u8SolenoidsStates34 = (uint8)((au8SolenoidStates[KU8_SOLENOID_4] & KU8_CIL_SOLENOID_STATE_MASK) << KU8_THREE) |
                                 (au8SolenoidStates[KU8_SOLENOID_3] & KU8_CIL_SOLENOID_STATE_MASK);

   /* Concatenates the solenoids 5 and 6 states */
   u8SolenoidsStates56 = (uint8)((au8SolenoidStates[KU8_SOLENOID_6] & KU8_CIL_SOLENOID_STATE_MASK) << KU8_THREE) |
                                 (au8SolenoidStates[KU8_SOLENOID_5] & KU8_CIL_SOLENOID_STATE_MASK);

   /* Fill Development Frame with acquisition data */
   cil_u8EcuCanDataOutFrame0Content.u8Byte28 = u8SolenoidsStates12;
   cil_u8EcuCanDataOutFrame0Content.u8Byte29 = u8SolenoidsStates34;
   cil_u8EcuCanDataOutFrame0Content.u8Byte0 = u8SolenoidsStates56;

   cil_u8EcuCanDataOutFrame0Content.u8Byte10 = au8SelectedProfile[KU8_ZERO];
   cil_u8EcuCanDataOutFrame0Content.u8Byte11 = au8SelectedProfile[KU8_ONE];
   cil_u8EcuCanDataOutFrame0Content.u8Byte12 = au8SelectedProfile[KU8_TWO];
   cil_u8EcuCanDataOutFrame0Content.u8Byte13 = au8SelectedProfile[KU8_THREE];
   cil_u8EcuCanDataOutFrame0Content.u8Byte14 = au8SelectedProfile[KU8_FOUR];
   cil_u8EcuCanDataOutFrame0Content.u8Byte15 = au8SelectedProfile[KU8_FIVE];

   cil_u8EcuCanDataOutFrame0Content.u8Byte22 = au8CurrentStep[KU8_ZERO];
   cil_u8EcuCanDataOutFrame0Content.u8Byte23 = au8CurrentStep[KU8_ONE];
   cil_u8EcuCanDataOutFrame0Content.u8Byte24 = au8CurrentStep[KU8_TWO];
   cil_u8EcuCanDataOutFrame0Content.u8Byte25 = au8CurrentStep[KU8_THREE];
   cil_u8EcuCanDataOutFrame0Content.u8Byte26 = au8CurrentStep[KU8_FOUR];
   cil_u8EcuCanDataOutFrame0Content.u8Byte27 = au8CurrentStep[KU8_FIVE];

}

/**
* \brief
*        This function is used to gather data about acceleration data available
*        on the SPI bus
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot02
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \constrains
*        NVP_u8EnableDevFrame must be != KU8_ZERO (DevKit Frame is enabled)
* \ddesignrequirement
*        DSG_cil_Manage_eCS_DevKit_Acceleration_Output
* \archrequirement
*        ARCH_SW_CIL_prr3DAcceleration;
*        ARCH_SW_CIL_prrAccelMtrPerSecSqd;
**/
LOCAL_INLINE void cil_Manage_eCS_DevKit_Acceleration_Output(void)
{
   /* Raw Acceleration */
   REC_3D_AccelerationType stRaw3AxisAccel;
   REC_3D_AccelMtrPerSecSqdType st3AxisAccel;
   register sint16 s16Ax = KS16_ZERO;
   register sint16 s16Ay = KS16_ZERO;
   register sint16 s16Az = KS16_ZERO;

   /* Get Raw Acceleration in g from SPI communication */
   (void)Rte_Read_prr3DAcceleration_st3DAccel(&stRaw3AxisAccel);
   (void)Rte_Read_prrAccelMtrPerSecSqd_stAccelMtrPerSecSqd(&st3AxisAccel);

   s16Ax = stRaw3AxisAccel.s16Ax + NVP_s16OffsetAx;
   s16Ay = stRaw3AxisAccel.s16Ay + NVP_s16OffsetAy;
   s16Az = stRaw3AxisAccel.s16Az + NVP_s16OffsetAz;

   /* Fill Development Frame with acquisition data */
   cil_u8EcuCanDataOutFrame0Content.u8Byte1 = U16_GET_HIGH_BYTE((uint16)s16Ax);
   cil_u8EcuCanDataOutFrame0Content.u8Byte2 = U16_GET_LOW_BYTE((uint16)s16Ax);
   cil_u8EcuCanDataOutFrame0Content.u8Byte3 = U16_GET_HIGH_BYTE((uint16)s16Ay);
   cil_u8EcuCanDataOutFrame0Content.u8Byte4 = U16_GET_LOW_BYTE((uint16)s16Ay);
   cil_u8EcuCanDataOutFrame0Content.u8Byte5 = U16_GET_HIGH_BYTE((uint16)s16Az);
   cil_u8EcuCanDataOutFrame0Content.u8Byte6 = U16_GET_LOW_BYTE((uint16)s16Az);

   cil_u8EcuCanDataOutFrame0Content.u8Byte16 = U16_GET_HIGH_BYTE((uint16)st3AxisAccel.s16Ax);
   cil_u8EcuCanDataOutFrame0Content.u8Byte17 = U16_GET_LOW_BYTE((uint16)st3AxisAccel.s16Ax);
   cil_u8EcuCanDataOutFrame0Content.u8Byte18 = U16_GET_HIGH_BYTE((uint16)st3AxisAccel.s16Ay);
   cil_u8EcuCanDataOutFrame0Content.u8Byte19 = U16_GET_LOW_BYTE((uint16)st3AxisAccel.s16Ay);
   cil_u8EcuCanDataOutFrame0Content.u8Byte20 = U16_GET_HIGH_BYTE((uint16)st3AxisAccel.s16Az);
   cil_u8EcuCanDataOutFrame0Content.u8Byte21 = U16_GET_LOW_BYTE((uint16)st3AxisAccel.s16Az);
}

/**
* \brief
*        This function is used to gather data about the current output of the
*        ball algorithm
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot02
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \constrains
*        NVP_u8EnableDevFrame must be != KU8_ZERO (DevKit Frame is enabled)
* \ddesignrequirement
*        DSG_cil_Manage_eCS_DevKit_Algo_Output
* \archrequirement
*        ARCH_SW_CIL_prrEcsAlgoData_u8EcsFlag;
*        ARCH_SW_CIL_prrEcsAlgoData_u16BallPosition;
**/
LOCAL_INLINE void cil_Manage_eCS_DevKit_Algo_Output(void)
{
   u16BallPositionType u16BallPosition = KU16_ZERO;
   u8EcsTriggerType u8EcsTrigger;

   /* Get eCS algo outputs: Ball position in mm */
   (void)Rte_Read_prrEcsAlgoData_u16BallPosition(&u16BallPosition);

   /* Get eCS algo outputs: Driver trigger */
   (void)Rte_Read_prrEcsAlgoData_u8EcsFlag(&u8EcsTrigger);

   /* Fill Development Frame with acquisition data */
   cil_u8EcuCanDataOutFrame0Content.u8Byte8 = U16_GET_HIGH_BYTE(u16BallPosition);
   cil_u8EcuCanDataOutFrame0Content.u8Byte9 = U16_GET_LOW_BYTE(u16BallPosition);

   cil_u8EcuCanDataOutFrame0Content.u8Byte7 = u8EcsTrigger;

}

/**
* \brief
*        This function is used to gather data of the current status of the lever(if
*        it has reached the unlock position or not)
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot02
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \constrains
*        NVP_u8EnableDevFrame must be != KU8_ZERO (DevKit Frame is enabled)
* \ddesignrequirement
*        DSG_cil_Manage_eCS_DevKit_Solenoid_Mechanical_Status
* \archrequirement
*        ARCH_SW_CIL_pclModeManagement
**/
LOCAL_INLINE void cil_Manage_eCS_DevKit_Solenoid_Mechanical_Status(void)
{
   register uint64 u64ModesToCheck = KU64_ZERO;
   uint8 u8SolenoidConfirmationModeStatus = KU8_ZERO;
   register uint8 u8MergedSolenoidConfirmationStatus = KU8_ZERO;

   u64ModesToCheck = KU64_SOLENOID_1_UNLOCK_CONFIRMED;
   (void)Rte_Call_pclModeManagement_CheckModeStatus(u64ModesToCheck, &u8SolenoidConfirmationModeStatus);
   if(B_TRUE == u8SolenoidConfirmationModeStatus)
   {
      u8MergedSolenoidConfirmationStatus = u8MergedSolenoidConfirmationStatus | (uint8)(KU8_ONE << KU8_ZERO);
   }
   else
   {
      u8MergedSolenoidConfirmationStatus = u8MergedSolenoidConfirmationStatus & (uint8)(~(uint8)(KU8_ONE << KU8_ZERO));
   }

   u64ModesToCheck = KU64_SOLENOID_2_UNLOCK_CONFIRMED;
   (void)Rte_Call_pclModeManagement_CheckModeStatus(u64ModesToCheck, &u8SolenoidConfirmationModeStatus);
   if(B_TRUE == u8SolenoidConfirmationModeStatus)
   {
      u8MergedSolenoidConfirmationStatus = u8MergedSolenoidConfirmationStatus | (uint8)(KU8_ONE << KU8_ONE);
   }
   else
   {
      u8MergedSolenoidConfirmationStatus = u8MergedSolenoidConfirmationStatus & (uint8)(~(uint8)(KU8_ONE << KU8_ONE));
   }

   u64ModesToCheck = KU64_SOLENOID_3_UNLOCK_CONFIRMED;
   (void)Rte_Call_pclModeManagement_CheckModeStatus(u64ModesToCheck, &u8SolenoidConfirmationModeStatus);
   if(B_TRUE == u8SolenoidConfirmationModeStatus)
   {
      u8MergedSolenoidConfirmationStatus = u8MergedSolenoidConfirmationStatus | (uint8)(KU8_ONE << KU8_TWO);
   }
   else
   {
      u8MergedSolenoidConfirmationStatus = u8MergedSolenoidConfirmationStatus & (uint8)(~(uint8)(KU8_ONE << KU8_TWO));
   }

   u64ModesToCheck = KU64_SOLENOID_4_UNLOCK_CONFIRMED;
   (void)Rte_Call_pclModeManagement_CheckModeStatus(u64ModesToCheck, &u8SolenoidConfirmationModeStatus);
   if(B_TRUE == u8SolenoidConfirmationModeStatus)
   {
      u8MergedSolenoidConfirmationStatus = u8MergedSolenoidConfirmationStatus | (uint8)(KU8_ONE << KU8_THREE);
   }
   else
   {
      u8MergedSolenoidConfirmationStatus = u8MergedSolenoidConfirmationStatus & (uint8)(~(uint8)(KU8_ONE << KU8_THREE));
   }

   u64ModesToCheck = KU64_SOLENOID_5_UNLOCK_CONFIRMED;
   (void)Rte_Call_pclModeManagement_CheckModeStatus(u64ModesToCheck, &u8SolenoidConfirmationModeStatus);
   if(B_TRUE == u8SolenoidConfirmationModeStatus)
   {
      u8MergedSolenoidConfirmationStatus = u8MergedSolenoidConfirmationStatus | (uint8)(KU8_ONE << KU8_FOUR);
   }
   else
   {
      u8MergedSolenoidConfirmationStatus = u8MergedSolenoidConfirmationStatus & (uint8)(~(uint8)(KU8_ONE << KU8_FOUR));
   }

   u64ModesToCheck = KU64_SOLENOID_6_UNLOCK_CONFIRMED;
   (void)Rte_Call_pclModeManagement_CheckModeStatus(u64ModesToCheck, &u8SolenoidConfirmationModeStatus);
   if(B_TRUE == u8SolenoidConfirmationModeStatus)
   {
      u8MergedSolenoidConfirmationStatus = u8MergedSolenoidConfirmationStatus | (uint8)(KU8_ONE << KU8_FIVE);
   }
   else
   {
      u8MergedSolenoidConfirmationStatus = u8MergedSolenoidConfirmationStatus & (uint8)(~(uint8)(KU8_ONE << KU8_FIVE));
   }

   /* Fill Development Frame with acquisition data */
   cil_u8EcuCanDataOutFrame0Content.u8Byte30 = u8MergedSolenoidConfirmationStatus;
}

/**
* \brief
*        This function is used to gather data regarding various counters that
*        will be sent on the CAN bus
*        e.g. execution counters, warm reset counters
* \dynamicaspectcaller
*        cil_ManagePeriodicData_TimeSlot05
* \dynamicaspectdescription
*        Called by local function for better granularity and split between OEM/Internal functions
* \constrains
*        NVP_u8EnableDevFrame must be != KU8_ZERO (DevKit Frame is enabled)
* \ddesignrequirement
*        DSG_cil_Manage_eCS_DevKit_Counter_Management
* \archrequirement
*        ARCH_SW_CIL_P_CAN_CanDataOut_Frame_0
**/
LOCAL_INLINE void cil_Manage_eCS_DevKit_Counter_Management(void)
{
   cil_u8EcuCanDataOutFrame0Content.u8Byte41 = KU8_ZERO;
   cil_u8EcuCanDataOutFrame0Content.u8Byte42 = KU8_ZERO;
   cil_u8EcuCanDataOutFrame0Content.u8Byte43 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_ZERO]; /* Lock */
   cil_u8EcuCanDataOutFrame0Content.u8Byte44 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_ONE]; /* Unlock */
   cil_u8EcuCanDataOutFrame0Content.u8Byte45 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_TWO]; /* Unlock confirmed */
   cil_u8EcuCanDataOutFrame0Content.u8Byte46 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_THREE];
   cil_u8EcuCanDataOutFrame0Content.u8Byte47 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_FOUR];
   cil_u8EcuCanDataOutFrame0Content.u8Byte48 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_FIVE];
   cil_u8EcuCanDataOutFrame0Content.u8Byte49 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_SIX];

   cil_u8EcuCanDataOutFrame0Content.u8Byte50 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_SEVEN];
   cil_u8EcuCanDataOutFrame0Content.u8Byte51 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_EIGHT];
   cil_u8EcuCanDataOutFrame0Content.u8Byte52 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_NINE];
   cil_u8EcuCanDataOutFrame0Content.u8Byte53 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_TEN];
   cil_u8EcuCanDataOutFrame0Content.u8Byte54 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_ELEVEN];
   cil_u8EcuCanDataOutFrame0Content.u8Byte55 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_TWELVE];
   cil_u8EcuCanDataOutFrame0Content.u8Byte56 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_THIRTEEN];
   cil_u8EcuCanDataOutFrame0Content.u8Byte57 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_FOURTEEN];
   cil_u8EcuCanDataOutFrame0Content.u8Byte58 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_FIFTEEN];
   cil_u8EcuCanDataOutFrame0Content.u8Byte59 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_SIXTEEN];

   cil_u8EcuCanDataOutFrame0Content.u8Byte60 = (uint8)NVP_au32ExecutedSolenoidCounters[KU8_SEVENTEEN];
   cil_u8EcuCanDataOutFrame0Content.u8Byte61 = (uint8)NVP_u32WarmResetCounter;
   cil_u8EcuCanDataOutFrame0Content.u8Byte62 = KU8_ZERO;
   cil_u8EcuCanDataOutFrame0Content.u8Byte63 = KU8_ZERO;
}

/**
* \brief
*        This function represents the 1st time slot
*        of managing the CAN outputs from application.
* \dynamicaspectcaller
*        CIL_runAppliToCAN
* \dynamicaspectdescription
*        Called by external function
* \ddesignrequirement
*        DSG_CIL_cil_ManagePeriodicData_TimeSlot01
* \archrequirement
*        ARCH_SW_CIL_P_CAN_CanDataOut_Frame_0
**/
LOCAL_INLINE void cil_ManagePeriodicData_TimeSlot01(void)
{
   cil_Manage_eCS_Gurtschloss_Status();

   cil_Manage_eCS_Status_Verr_Reihe1_BFS_1();

   cil_Manage_eCS_Error_Reihe1_BFS_1();

   cil_Manage_eCS_Error_Reihe1_BFS_2();

   if (KU8_ZERO != NVP_u8EnableDevFrame)
   {
      cil_Manage_eCS_DevKit_Solenoid_Profiles_States();

      cil_Manage_eCS_DevKit_Buckle_Status();
   }
}

/**
* \brief
*        This function represents the 2nd time slot
*        of managing the CAN outputs from application.
* \dynamicaspectcaller
*        CIL_runAppliToCAN
* \dynamicaspectdescription
*        Called by external function
* \ddesignrequirement
*        DSG_CIL_cil_ManagePeriodicData_TimeSlot02
* \archrequirement
*        ARCH_SW_CIL_P_CAN_CanDataOut_Frame_0
**/
LOCAL_INLINE void cil_ManagePeriodicData_TimeSlot02(void)
{
   cil_Manage_eCS_Status_Verr_Reihe1_BFS_2();

   cil_Manage_eCS_Status_Verr_Reihe1_FS_1();

   cil_Manage_eCS_Error_Reihe1_FS_1();

   cil_Manage_eCS_Error_Reihe1_FS_2();

   if (KU8_ZERO != NVP_u8EnableDevFrame)
   {
      cil_Manage_eCS_DevKit_Acceleration_Output();

      cil_Manage_eCS_DevKit_Algo_Output();

      cil_Manage_eCS_DevKit_Solenoid_Mechanical_Status();
   }
}

/**
* \brief
*        This function represents the 3rd time slot
*        of managing the CAN outputs from application.
* \dynamicaspectcaller
*        CIL_runAppliToCAN
* \dynamicaspectdescription
*        Called by external function
* \ddesignrequirement
*        DSG_CIL_cil_ManagePeriodicData_TimeSlot03
* \archrequirement
*        ARCH_SW_CIL_P_CAN_CanDataOut_Frame_0
**/
LOCAL_INLINE void cil_ManagePeriodicData_TimeSlot03(void)
{
   cil_Manage_eCS_Status();

   cil_Manage_eCS_Status_Verr_Reihe1_FS_2();

   cil_Manage_eCS_Status_Verr_Reihe2_BFS();

   cil_Manage_eCS_Status_Verr_Reihe2_FS();
}

/**
* \brief
*        This function represents the 4th time slot
*        of managing the CAN outputs from application.
* \dynamicaspectcaller
*        CIL_runAppliToCAN
* \dynamicaspectdescription
*        Called by external function
* \ddesignrequirement
*        DSG_CIL_cil_ManagePeriodicData_TimeSlot04
* \archrequirement
*        ARCH_SW_CIL_P_CAN_CanDataOut_Frame_0
**/
LOCAL_INLINE void cil_ManagePeriodicData_TimeSlot04(void)
{
   cil_Manage_eCS_SBS_Belegung();

   cil_Manage_eCS_HW_defekt();

   cil_Manage_eCS_Stoerung();

   cil_Manage_eCS_Error_Reihe2_BFS();

   cil_Manage_eCS_Error_Reihe2_FS();

   if (KU8_ZERO != NVP_u8EnableDevFrame)
   {
      cil_Manage_eCS_DevKit_Seat_Occupancy_Status();
   }
}

/**
* \brief
*        This function represents the 5th time slot
*        of managing the CAN outputs from application.
* \inputparam
*        Name: NA.;
*        Type: NA.;
*        Description: NA.;
*        Range: NA.;
* \outputparam
*        Name: NA.;
*        Type: NA.;
*        Description: NA.;
*        Range: NA.;
* \constrains
*        NA.
* \dynamicaspectcaller
*        CIL_runAppliToCAN
* \dynamicaspectdescription
*        Called by external function
* \ddesignrequirement
*        DSG_CIL_cil_ManagePeriodicData_TimeSlot05
* \archrequirement
*        ARCH_SW_CIL_P_CAN_CanDataOut_Frame_0
**/
LOCAL_INLINE void cil_ManagePeriodicData_TimeSlot05(void)
{
   cil_Manage_eCS_SBS_LastState_Reihe2_FS();

   cil_Manage_eCS_SBS_LastState_Reihe2_BFS();

   if (KU8_ZERO != NVP_u8EnableDevFrame)
   {
      cil_Manage_eCS_DevKit_Counter_Management();

      cil_u8EcuCanDataOutFrame0OnBus.u64Byte_0_7   = *(uint64 *)(&cil_u8EcuCanDataOutFrame0Content.u8Byte0);
      cil_u8EcuCanDataOutFrame0OnBus.u64Byte_8_15  = *(uint64 *)(&cil_u8EcuCanDataOutFrame0Content.u8Byte8);
      cil_u8EcuCanDataOutFrame0OnBus.u64Byte_16_23 = *(uint64 *)(&cil_u8EcuCanDataOutFrame0Content.u8Byte16);
      cil_u8EcuCanDataOutFrame0OnBus.u64Byte_24_31 = *(uint64 *)(&cil_u8EcuCanDataOutFrame0Content.u8Byte24);
      cil_u8EcuCanDataOutFrame0OnBus.u64Byte_32_39 = *(uint64 *)(&cil_u8EcuCanDataOutFrame0Content.u8Byte32);
      cil_u8EcuCanDataOutFrame0OnBus.u64Byte_40_47 = *(uint64 *)(&cil_u8EcuCanDataOutFrame0Content.u8Byte40);
      cil_u8EcuCanDataOutFrame0OnBus.u64Byte_48_55 = *(uint64 *)(&cil_u8EcuCanDataOutFrame0Content.u8Byte48);
      cil_u8EcuCanDataOutFrame0OnBus.u64Byte_56_63 = *(uint64 *)(&cil_u8EcuCanDataOutFrame0Content.u8Byte56);

      /* Write data to CAN */
      (void)Rte_Write_CIL_P_CAN_CanDataOut_Frame_0_EcuCanDataOut(&cil_u8EcuCanDataOutFrame0OnBus);
   }
}

#define CIL_STOP_SEC_CODE
#include "CIL_MemMap.h"

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

#define CIL_START_SEC_CODE
#include "CIL_MemMap.h"

/**
* \brief
*        This function represents the CIL periodic main function used to update transmitted frames signals values.
* \dynamicaspectcaller
*        Scheduler.
* \dynamicaspectdescription
*        Called at 2 ms.
* \ddesignrequirement
*        DSG_CIL_runAppliToCAN
* \archrequirement
*        ARCH_SW_CIL_ptrpAsrOsServicesCIL_CIL_runAppliToCAN
*        ARCH_SW_CIL_prrEcsAlgoData_b8EcsFlag
**/
EXPORTED void CIL_runAppliToCAN(void)
{
   /* Execute the current time slot */
   (*(cil_kapfPerGetDataFunc[cil_u8PeriodicDataTimeSlotID]))();

   /* Update Counter */
   cil_u8PeriodicDataTimeSlotID = ((cil_u8PeriodicDataTimeSlotID + KU8_ONE) % KU8_CIL_ATC_NB_OF_SLOTS);
}

#define CIL_STOP_SEC_CODE
#include "CIL_MemMap.h"

/******************************************************************************
Evolution of the component

Created by : F.GILBERT

$Log: CIL_AppliToCAN.c  $
Revision 1.5.3.46 2023/07/20 08:28:18CEST David Puscasu (david.puscasu) 
Update traceability
Revision 1.5.3.45 2023/07/18 09:29:39EEST David Puscasu (david.puscasu) 
Update Traceability on CIL
Revision 1.5.3.44 2023/06/12 09:05:53EEST Mihai Motoc (mihai.motoc) 
Doxygen comments updates
Revision 1.5.3.43 2023/06/08 13:34:18EEST Mihai Motoc (mihai.motoc) 
Doxygen comments updates
Revision 1.5.3.42 2023/06/07 09:09:03EEST Dan Dustinta (dan.dustinta) 
update error mapping for OEM
Revision 1.5.3.41 2023/05/16 15:01:21EEST Dan Dustinta (dan.dustinta) 
update findings after PRWB
Revision 1.5.3.40 2023/05/16 13:28:32EEST Dan Dustinta (dan.dustinta) 
update b8 to u8
Revision 1.5.3.39 2023/05/16 12:43:42EEST Dan Dustinta (dan.dustinta) 
update b8 to u8
Revision 1.5.3.38 2023/05/15 16:20:26EEST Ioan Repede (ioan.repede) 
Update RTE connection for SolenoidStuckStatus prot from FSM.
Revision 1.5.3.37 2023/05/12 09:30:26EEST Dan Dustinta (dan.dustinta) 
update signal strategy
Revision 1.5.3.36 2023/05/11 14:20:17EEST Ioan Repede (ioan.repede) 
Update the CIL singnals based on solenoids errors.
Revision 1.5.3.35 2023/04/25 13:31:26EEST Dan Dustinta (dan.dustinta) 
add handling of timeout of init signal
Revision 1.5.3.34 2023/04/24 09:10:11EEST Gabriel Brasoveanu (gabriel.brasoveanu) 
Code implementation for readout of the last buckle state
Revision 1.5.3.33 2023/04/21 12:59:28EEST Dan Dustinta (dan.dustinta) 
update inverted logic and seat removable
Revision 1.5.3.32 2023/04/20 17:26:46EEST Gabriel Brasoveanu (gabriel.brasoveanu) 
Handle new signals imported from K-matrix
Revision 1.5.3.31 2023/04/19 09:23:30EEST Dan Dustinta (dan.dustinta) 
update traceability
Revision 1.5.3.30 2023/04/18 17:07:29EEST Dan Dustinta (dan.dustinta) 
refactor for consistency with CIL_MF
Revision 1.5.3.28 2023/04/18 15:24:57EEST Dan Dustinta (dan.dustinta) 
add local functions
Revision 1.5.3.27 2023/03/30 13:33:46EEST Dan Dustinta (dan.dustinta) 
add DSG req for SRM
Revision 1.5.3.26 2023/03/30 13:06:07EEST Gabriel Brasoveanu (gabriel.brasoveanu) 
Add new frame MF_Logger used to send on bus current ECU State
Revision 1.5.3.25 2023/03/30 07:49:53EEST Septimiu Vintila (septimiu.vintila) 
Memmap corrected.
Revision 1.5.3.24 2023/03/29 15:52:52EEST Septimiu Vintila (septimiu.vintila) 
Fix after review (memory sections added)
Revision 1.5.3.23 2023/03/27 16:22:41EEST Ioan Repede (ioan.repede) 
Update CAN signal for eCS_Status to stay in Init phase util INIT_PHASE_IN_PROGRESS flag from FSM_ModeStatus is set.
Revision 1.5.3.22 2023/03/24 08:46:26EET Septimiu Vintila (septimiu.vintila) 
Changes after review.
Revision 1.5.3.21 2023/03/23 09:42:42EET Ioan Repede (ioan.repede) 
Update variables and defines related to Mode Mask to 64 bits.
Revision 1.5.3.20 2023/03/15 16:34:44EET Dan Dustinta (dan.dustinta) 
devkit frame fix
Revision 1.5.3.19 2023/03/14 11:39:44EET Gabriel Brasoveanu (gabriel.brasoveanu) 
Measurement frame, Gliwa Out frame and DevKit frame changed from 64 signals of 1 byte to 8 signals of 8 bytes
Revision 1.5.3.18 2023/03/13 09:31:43EET Dan Dustinta (dan.dustinta) 
update naming for clarity
Revision 1.5.3.17 2023/03/10 11:25:32EET Septimiu Vintila (septimiu.vintila) 
MF redesign; cast corrected in CanToAppli
Revision 1.5.3.16 2023/03/09 08:29:29EET Septimiu Vintila (septimiu.vintila) 
Typo corrected.
Revision 1.5.3.15 2023/03/03 12:35:24EET Dan Dustinta (dan.dustinta) 
update MF handling
Revision 1.5.3.14 2023/02/20 13:53:35EET Ioan Repede (ioan.repede) 
Update Solenoid states singnals.
Revision 1.5.3.13 2023/02/15 10:07:34EET Septimiu Vintila (septimiu.vintila) 
QAC related code changes.
Revision 1.5.3.12 2023/01/30 16:00:06EET Septimiu Vintila (septimiu.vintila) 
Read acceleration in m/s^2 added & TX signals updated.
Revision 1.5.3.11 2023/01/25 11:46:21EET Septimiu Vintila (septimiu.vintila) 
Added time-slots mechanism for AppliToCan functionality:
 - main function moved to 2ms
 - functionality splitted in 5 time slots
Revision 1.5.3.10 2023/01/17 15:49:26EET Dan Dustinta (dan.dustinta) 
update CIL runnables
Revision 1.5.3.9 2023/01/17 15:25:06EET Septimiu Vintila (septimiu.vintila) 
Unlock status recieved while crash was detected inhibited.
Revision 1.5.3.8 2023/01/17 15:20:05EET Septimiu Vintila (septimiu.vintila) 
Defines for LOCK/UNLOCK states corrected.
Revision 1.5.3.7 2023/01/16 13:35:02EET Septimiu Vintila (septimiu.vintila) 
Variables name changed.
Revision 1.5.3.6 2023/01/16 11:38:47EET Septimiu Vintila (septimiu.vintila) 
Fixes after review.
Revision 1.5.3.5 2023/01/06 09:30:16EET Septimiu Vintila (septimiu.vintila) 
Gliwa Tx Frame put as direct/immediate.
DevOut Frame put as direct/immediate.
Measurement Frame put as direct/immediate.
Revision 1.5.3.4 2022/12/14 11:35:54EET Septimiu Vintila (septimiu.vintila) 
Integration for Gliwa related Tx/Rx frames.
Revision 1.5.3.3 2022/11/24 10:13:15EET Septimiu Vintila (septimiu.vintila) 
CIL implemantation.
Revision 1.3 2022/03/22 14:37:47EET Pierre-Olivier Pilot (pierre-olivier.pilot) 
eCS_ECUV.007:
* SPIIF: update Accel init sequence: remove filter configuration (we select bank 6 but we configure register from bank 0 => drift issue). Only the full scale register is written
	? Implements a test function to get accelerometer temperautre. Output in MF block 4
* Remove 2g variant configuration. Force accelerometer to use 4g
* Fix SAD following cycle management. A bug was found when going grom lock to unlock, the holding profile was run for 1ms then the unlocking one was triggered.
* DIA RC: update calibration
Revision 1.2 2021/09/24 10:04:31CEST Razvan Badiu (razvan.badiu) 
add offset computation
Revision 1.1 2021/09/14 14:39:09EEST Pierre-Olivier Pilot (pierre-olivier.pilot) 
Initial revision
Member added to project e:/MKSProjects/SBE/Innovation/ECS/Phase_01/Components/Application/Autoliv/CIL/Implementation/src/project.pj
Revision 1.3 2021/06/18 12:20:15CEST Sabrine Bouazizi (sabrine.bouazizi) 
Add Roe Management
Revision 1.2 2021/06/09 11:02:29CEST Sabrine Bouazizi (sabrine.bouazizi) 
AT/DTC MNGT Add ROE Management
Revision 1.1 2020/12/08 14:13:01CET Gaetan Lievre (gaetan.lievre) 
Initial revision

*****************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/
