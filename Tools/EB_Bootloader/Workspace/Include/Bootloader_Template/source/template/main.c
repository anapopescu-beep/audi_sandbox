/**
 * \file
 *
 * \brief AUTOSAR Demo
 *
 * This file contains the implementation of the AUTOSAR
 * module Demo.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2016 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]============================================*/


#include "EB_prj.h"
#include "board.h"
#include "Csm.h"
#include <Base_Modules.h>   /* Module enable defines and standard config pointer names */
#include <Port.h>   /* Module enable defines and standard config pointer names */
#include "Mcu.h"

/******************************** DEFINES & VARIABLES ****************************/
/*                                                                               */
/*-------------------------------------------------------------------------------*/

void main(void)
{
    /* Initialization of EB Stack */
    Mcu_Init(&McuModuleConfiguration);

    /* ignore return value (always E_NOT_OK). ERAY Pll is not supported for TC22
    * but the function tries to configure it anyway with 0 values. */
    (void)Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig_0);

     /* Wait until the PLL is locked */
    while (MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
    ;
    }

     /* Activate the PLL Clock */
    Mcu_DistributePllClock();

    /* Initialization of Port */
    Port_Init(&PortConfigSet);
    BM_StartUp();


    /* Starting from there we known that the Application is NOT valid OR a Downloading is requested */

    /* Endless loop */
    for(;;)
    {

        /* Scheduler timer */
        if (BoardSchedulingTimer() == 0x01U)
        {
            /* CAN Application cyclic task */
            APP_Manage();
            BlPduR_Manage();
        }
        /* Call the prog_hsm main function */
        PROG_BckdManage();
        Csm_MainFunction();
    }
}
