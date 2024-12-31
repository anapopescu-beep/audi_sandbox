/**
 * \file
 *
 * \brief AUTOSAR ApplTemplates
 *
 * This file contains the implementation of the AUTOSAR
 * module ApplTemplates.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2015 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef EB_INTGR_BSWM_USERCALLOUTS_H
#define EB_INTGR_BSWM_USERCALLOUTS_H


/*==================[includes]==============================================*/

#include <TSAutosar.h>     /* EB specific standard types */
#include <SchM_EbIntgr.h>
/* to use the RES_SCHEDULER */
#include <Os.h>
#include <Rte_Type.h>
#include <Rte_BswM_Type.h>
#include <Rte_Dem_Type.h>
#include <Dem_Cfg.h>
#include <Nvm_Types.h>



/*==================[macros]================================================*/

/* BswM states:
 * The values assigned to the macros must be less than or equal to the value
 * you have configured in parameter "BswMRequestedModeMax" of the corresponding
 * BswM mode request port (the value of parameter "BswMModeRequestSource" of
 * this mode request port has to be "BswMGenericRequest"). */
#define EB_INTGR_BSWM_BSWM_SM        0u  /* the BswMModeRequesterId of the BswM state
                                          * machine. */

#define EB_INTGR_BSWM_STARTUP_TWO_A  RTE_MODE_BSWM_BswMModeGroup_EB_INTGR_BSWM_STARTUP_TWO_A  /*!< ECU state handled by BswM module. */
#define EB_INTGR_BSWM_STARTUP_TWO_B  RTE_MODE_BSWM_BswMModeGroup_EB_INTGR_BSWM_STARTUP_TWO_B  /*!< ECU state handled by BswM module. */
#define EB_INTGR_BSWM_RUN_TWO        RTE_MODE_BSWM_BswMModeGroup_EB_INTGR_BSWM_RUN_TWO        /*!< ECU state handled by BswM module. */
#define EB_INTGR_BSWM_POST_RUN       RTE_MODE_BSWM_BswMModeGroup_EB_INTGR_BSWM_POST_RUN       /*!< ECU state handled by BswM module. */
#define EB_INTGR_BSWM_SLEEP          RTE_MODE_BSWM_BswMModeGroup_EB_INTGR_BSWM_SLEEP          /*!< ECU state handled by BswM module. */
#define EB_INTGR_BSWM_PRP_SHUTDOWN   RTE_MODE_BSWM_BswMModeGroup_EB_INTGR_BSWM_PRP_SHUTDOWN   /*!< ECU state handled by BswM module. */
#define EB_INTGR_BSWM_WAKEUP_TWO     RTE_MODE_BSWM_BswMModeGroup_EB_INTGR_BSWM_WAKEUP_TWO     /*!< ECU state handled by BswM module. */
#define EB_INTGR_BSWM_GO_OFF_ONE_A   RTE_MODE_BSWM_BswMModeGroup_EB_INTGR_BSWM_GO_OFF_ONE_A   /*!< ECU state handled by BswM module. */
#define EB_INTGR_BSWM_GO_OFF_ONE_B   RTE_MODE_BSWM_BswMModeGroup_EB_INTGR_BSWM_GO_OFF_ONE_B   /*!< ECU state handled by BswM module. */
 
/*Set this define to STD_OFF if the simulated CAN transceiver is not used*/
#define SIMULATED_CANTRCV STD_OFF 


/* SWC_CyclicCounter states:
 * The values assigned to the macros must be less than or equal to the value
 * you have configured in parameter "BswMRequestedModeMax" of the corresponding
 * BswM mode request port (the value of parameter "BswMModeRequestSource" of
 * this mode request port has to be "BswMGenericRequest"). */
#define EB_INTGR_BSWM_SWC_CYCLIC             1u  /* the BswMModeRequesterId of the 
                                                  * SWC_CyclicCounter. */

#define EB_INTGR_BSWM_SWC_CYCLIC_UNINIT      0u  /* SWC_CyclicCounter state */
#define EB_INTGR_BSWM_SWC_CYCLIC_RUN         1u  /* SWC_CyclicCounter state */
#define EB_INTGR_BSWM_SWC_CYCLIC_SHUTDOWN    2u  /* SWC_CyclicCounter state */

 /* NMS data updated from integration code VWMQB308 */
extern const boolean NMS_SEND_BIT_SET;
extern const boolean NMS_SEND_BIT_RESET;


/* This definition is for testing StateMonitor functions where NM user data is tested and sent with NM messages
 * Manual test is performed for each test cases.
 * Please make sure to undef this definition if functions are needed to be tested */

#define STATEMONITOR_IS_NOT_TESTED
/* #undef STATEMONITOR_IS_NOT_TESTED */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/


/* AUTOSAR Memory Mapping - start section for code */
#define BSWM_START_SEC_CODE
#include <MemMap.h>

extern Std_ReturnType Dem_SetOperationCycleState(
  uint8    OperationCycleId,
  uint8 CycleState); 
extern FUNC(void, BSWM_APPL_CODE) Eb_Intgr_BswM_DriverInitTwo(void);
extern FUNC(void, BSWM_APPL_CODE) Eb_Intgr_BswM_OnStartupTwoA(void);
extern FUNC(void, BSWM_APPL_CODE) Eb_Intgr_BswM_DriverInitThree(void);
extern FUNC(void, BSWM_APPL_CODE) Eb_Intgr_BswM_RunTwo(void);
extern FUNC(void, BSWM_APPL_CODE) Eb_Intgr_BswM_GoOffOneA(void);
extern FUNC(void, BSWM_APPL_CODE) Eb_Intgr_BswM_GoOffOneB(void);
extern FUNC(void, BSWM_APPL_CODE) Eb_Intgr_BswM_InitNvMReadAll(void);
extern FUNC(void, BSWM_APPL_CODE) Eb_Intgr_BswM_DeInitNvMWriteAll(void);
extern FUNC(void, BSWM_APPL_CODE) Eb_Intgr_BswM_WaitMemDriverReady(void);
extern FUNC(void, DEM_APPL_CODE) Eb_Intgr_BswM_TriggerMemoryStack(const NvM_BlockIdType BlockId);
extern FUNC(void, BSWM_APPL_CODE) Dummy(void);

#define BSWM_STOP_SEC_CODE
#include <MemMap.h>


/*==================[internal function definitions]=========================*/


#endif /* ifndef EB_INTGR_BSWM_USERCALLOUTS_H */

/*==================[end of file]===========================================*/
