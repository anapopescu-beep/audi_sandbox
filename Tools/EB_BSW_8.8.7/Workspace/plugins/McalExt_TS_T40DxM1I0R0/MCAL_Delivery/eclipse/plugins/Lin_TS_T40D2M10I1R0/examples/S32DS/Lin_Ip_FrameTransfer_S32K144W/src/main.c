/*==================================================================================================
*   Project              : M4_SRC_PROJECT_NAME
*   Platform             : M4_SRC_MCU_FAMILY
*   Peripheral           : M4_SRC_USED_PERIPHERAL
*   Dependencies         : M4_SRC_AR_MODULE_DEPENDENCY
*
*   Autosar Version      : M4_SRC_AR_SPEC_VERSION_MAJOR.M4_SRC_AR_SPEC_VERSION_MINOR.M4_SRC_AR_SPEC_VERSION_PATCH
*   Autosar Revision     : M4_SRC_AR_RELEASE_REVISION
*   Autosar Conf.Variant :
*   SW Version           : M4_SRC_SW_VERSION_MAJOR.M4_SRC_SW_VERSION_MINOR.M4_SRC_SW_VERSION_PATCH
*   Build Version        : M4_SRC_BUILD_ID
*
   (c) Copyright M4_SRC_YEAR_ID M4_SRC_COPYRIGHTED_TO
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file main.c
*
*   @addtogroup main_module main module documentation
*   @{
*/

/* Including necessary configuration files. */
#include "Mcal.h"

volatile int exit_code = 0;

/* User includes */
#include "OsIf.h"
#include "Flexio_Lin_Ip.h"
#include "Lpuart_Lin_Ip.h"
#include "Flexio_Mcl_Ip.h"
#include "Clock_Ip.h"
#include "IntCtrl_Ip.h"
#include "Port_Ci_Port_Ip.h"
#include "check_example.h"

#define BUFFER_SIZE         	(3U)
#define T_LIN_TIME_OUT      	(400000U)
#define PID                  	(0x1A)

#define FLEXIO_INSTANCE 		(0U)

//#define FLEXIO_LIN_MASTER
//#define FLEXIO_LIN_SLAVE
#define LPUART_LIN_MASTER
#define LPUART_LIN_SLAVE


void LpuartSlaveCallback (uint8 Instance, const  Lpuart_Lin_Ip_StateStructType *LpuartStateStruct)
{
    uint8 SduBuf[3U];
	Lpuart_Lin_Ip_PduType LinPdu =
	    {
	                .Pid = LpuartStateStruct->CurrentPid,
	                .Cs = LPUART_LIN_IP_ENHANCED_CS,
	                .SduPtr = &SduBuf[0u],
					.Drc = LPUART_LIN_IP_FRAMERESPONSE_RX,
					.Dl = 3
	    };


		if (LpuartStateStruct->CurrentEventId == LPUART_LIN_IP_RECV_HEADER_OK)
		{
			(void)Lpuart_Lin_Ip_SendFrame(Instance, (const Lpuart_Lin_Ip_PduType *)&LinPdu);
		}

}

void FlexioSlaveCallback (uint8 Instance, const  Flexio_Lin_Ip_StateStructType *FlexioStateStruct)
{
    uint8 SduBuf[3U];
    Flexio_Lin_Ip_PduType LinPdu =
	    {
	                .Pid = FlexioStateStruct->CurrentPid,
	                .Cs = FLEXIO_LIN_IP_ENHANCED_CS,
	                .SduPtr = &SduBuf[0u],
					.Drc = FLEXIO_LIN_IP_FRAMERESPONSE_RX,
					.Dl = 3
	    };


		if (FlexioStateStruct->CurrentEventId == FLEXIO_LIN_IP_RECV_HEADER_OK)
		{
			(void)Flexio_Lin_Ip_SendFrame(Instance, (const Flexio_Lin_Ip_PduType *)&LinPdu);
		}

}

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
	uint8 TxBuff[BUFFER_SIZE] = {0x01, 0x02, 0x03};
	uint8 RemainingBytes[BUFFER_SIZE];
	uint32 timeoutValue = 0u;
#if defined(FLEXIO_LIN_SLAVE)
	Flexio_Lin_Ip_TransferStatusType FlexioSlaveStatus = FLEXIO_LIN_IP_STATUS_OPERATIONAL;
#elif defined(LPUART_LIN_SLAVE)
	Lpuart_Lin_Ip_TransferStatusType LpuartSlaveStatus = LPUART_LIN_IP_STATUS_OPERATIONAL;
#endif

#if defined(FLEXIO_LIN_MASTER)
	Flexio_Lin_Ip_PduType FlexioPduInfo;
	Flexio_Lin_Ip_TransferStatusType FlexioMasterStatus = FLEXIO_LIN_IP_STATUS_OPERATIONAL;
    /* Current frame is using ENHANCED checksum */
	FlexioPduInfo.Cs = FLEXIO_LIN_IP_ENHANCED_CS;
	/* BUFFER_SIZE is the number of bytes sent as a response */
	FlexioPduInfo.Dl = (uint8)BUFFER_SIZE;
	/* The Master node is sending the response */
	FlexioPduInfo.Drc = FLEXIO_LIN_IP_FRAMERESPONSE_TX;
	/* Frame PID */
	FlexioPduInfo.Pid = (uint8)PID;
	/* Buffer address */
	FlexioPduInfo.SduPtr = TxBuff;
#elif defined(LPUART_LIN_MASTER)
	Lpuart_Lin_Ip_PduType LpuartPduInfo;
	Lpuart_Lin_Ip_TransferStatusType LpuartMasterStatus = LPUART_LIN_IP_STATUS_OPERATIONAL;

    /* Current frame is using ENHANCED checksum */
	LpuartPduInfo.Cs = LPUART_LIN_IP_ENHANCED_CS;
	/* BUFFER_SIZE is the number of bytes sent as a response */
	LpuartPduInfo.Dl = (uint8)BUFFER_SIZE;
	/* The Master node is sending the response */
	LpuartPduInfo.Drc = LPUART_LIN_IP_FRAMERESPONSE_TX;
	/* Frame PID */
	LpuartPduInfo.Pid = (uint8)PID;
	/* Buffer address */
	LpuartPduInfo.SduPtr = TxBuff;
#endif

    /* Init clock  */
    Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

    /*Enable Flexio module */
#if defined(FLEXIO_LIN_MASTER) || defined(FLEXIO_LIN_SLAVE)
    /* Init Flexio common Mcl  */
    Flexio_Mcl_Ip_InitDevice(FLEXIO_INSTANCE);
#endif

    /* Initialize all pins */
    Port_Ci_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    /* Initialize IRQs */
    IntCtrl_Ip_Init(&IntCtrlConfig_0);
    IntCtrl_Ip_ConfigIrqRouting(&intRouteConfig);

    OsIf_Init(NULL_PTR);

    /* Wait for the transmission done */
    timeoutValue = 4*T_LIN_TIME_OUT;

    /*Intialize the MASTER - It can be either a Flexio configured MASTER or Lpuart configured MASTER */
#if defined(LPUART_LIN_MASTER)
    Lpuart_Lin_Ip_Init(Lpuart_Lin_Ip_Sa_pHwConfigPB_0_BOARD_INITPERIPHERALS.Instance, &Lpuart_Lin_Ip_Sa_pHwConfigPB_0_BOARD_INITPERIPHERALS);
#elif defined(FLEXIO_LIN_MASTER)
    Flexio_Lin_Ip_Init(Flexio_Lin_Ip_Sa_pHwConfigPB_0_BOARD_INITPERIPHERALS.Instance, &Flexio_Lin_Ip_Sa_pHwConfigPB_0_BOARD_INITPERIPHERALS);
#endif

    /* Intialize the SLAVE - It can be either a Flexio configured SLAVE or Lpuart configured SLAVE */
#if defined(LPUART_LIN_SLAVE)
    Lpuart_Lin_Ip_Init(Lpuart_Lin_Ip_Sa_pHwConfigPB_1_BOARD_INITPERIPHERALS.Instance, &Lpuart_Lin_Ip_Sa_pHwConfigPB_1_BOARD_INITPERIPHERALS);
#elif defined(FLEXIO_LIN_SLAVE)
    Flexio_Lin_Ip_Init(Flexio_Lin_Ip_Sa_pHwConfigPB_1_BOARD_INITPERIPHERALS.Instance, &Flexio_Lin_Ip_Sa_pHwConfigPB_1_BOARD_INITPERIPHERALS);
#endif

#if defined(FLEXIO_LIN_MASTER)
    /* Start of the sending frame */
    (void)Flexio_Lin_Ip_SendFrame(Flexio_Lin_Ip_Sa_pHwConfigPB_0_BOARD_INITPERIPHERALS.Instance, &FlexioPduInfo);
#elif defined (LPUART_LIN_MASTER)
    (void)Lpuart_Lin_Ip_SendFrame(Lpuart_Lin_Ip_Sa_pHwConfigPB_0_BOARD_INITPERIPHERALS.Instance, &LpuartPduInfo);
#endif

#if defined(FLEXIO_LIN_MASTER)
    /*Wait for the transmission done */
     do
     {
     	FlexioMasterStatus = Flexio_Lin_Ip_GetStatus(Flexio_Lin_Ip_Sa_pHwConfigPB_0_BOARD_INITPERIPHERALS.Instance, (uint8 **)&RemainingBytes);
     }
     while ((FLEXIO_LIN_IP_STATUS_TX_OK != FlexioMasterStatus) && (timeoutValue-- > 1));

#elif defined (LPUART_LIN_MASTER)
     /*Wait for the transmission done */
      do
      {
      	LpuartMasterStatus = Lpuart_Lin_Ip_GetStatus(Lpuart_Lin_Ip_Sa_pHwConfigPB_0_BOARD_INITPERIPHERALS.Instance, (uint8 **)&RemainingBytes);
      }
      while ((LPUART_LIN_IP_STATUS_TX_OK != LpuartMasterStatus) && (timeoutValue-- > 1));
#endif

#if defined(FLEXIO_LIN_SLAVE)
    /*Wait for the transmission done */
     do
     {
     	FlexioSlaveStatus = Flexio_Lin_Ip_GetStatus(Flexio_Lin_Ip_Sa_pHwConfigPB_1_BOARD_INITPERIPHERALS.Instance, (uint8 **)&RemainingBytes);
     }
     while ((FLEXIO_LIN_IP_STATUS_RX_OK != FlexioSlaveStatus) && (timeoutValue-- > 1));

#elif defined (LPUART_LIN_SLAVE)
     /*Wait for the transmission done */
      do
      {
      	LpuartSlaveStatus = Lpuart_Lin_Ip_GetStatus(Lpuart_Lin_Ip_Sa_pHwConfigPB_1_BOARD_INITPERIPHERALS.Instance, (uint8 **)&RemainingBytes);
      }
      while ((LPUART_LIN_IP_STATUS_RX_OK != LpuartSlaveStatus) && (timeoutValue-- > 1));
#endif

#if defined(FLEXIO_LIN_MASTER)
    /* Flexio over Lin driver de-initialization*/
    Flexio_Lin_Ip_Deinit(Flexio_Lin_Ip_Sa_pHwConfigPB_0_BOARD_INITPERIPHERALS.Instance);
#elif defined(LPUART_LIN_MASTER)
    Lpuart_Lin_Ip_Deinit(Lpuart_Lin_Ip_Sa_pHwConfigPB_0_BOARD_INITPERIPHERALS.Instance);
#endif

#if defined(FLEXIO_LIN_SLAVE)
    /* Flexio over Lin driver de-initialization*/
    Flexio_Lin_Ip_Deinit(Flexio_Lin_Ip_Sa_pHwConfigPB_1_BOARD_INITPERIPHERALS.Instance);
#elif defined(LPUART_LIN_SLAVE)
    Lpuart_Lin_Ip_Deinit(Lpuart_Lin_Ip_Sa_pHwConfigPB_1_BOARD_INITPERIPHERALS.Instance);
#endif

#if defined(FLEXIO_LIN_MASTER) || defined(FLEXIO_LIN_SLAVE)
    /* Disable Flexio Module*/
    Flexio_Mcl_Ip_DeinitDevice(FLEXIO_INSTANCE);
#endif

#if defined(FLEXIO_LIN_MASTER) && defined(FLEXIO_LIN_SLAVE)
    /* Check status */
    Exit_Example(FLEXIO_LIN_IP_STATUS_TX_OK == FlexioMasterStatus && FLEXIO_LIN_IP_STATUS_RX_OK == FlexioSlaveStatus);
#elif defined(FLEXIO_LIN_MASTER) && defined(LPUART_LIN_SLAVE)
    /* Check status */
	Exit_Example(FLEXIO_LIN_IP_STATUS_TX_OK == FlexioMasterStatus && LPUART_LIN_IP_STATUS_RX_OK == LpuartSlaveStatus);
#elif defined(LPUART_LIN_MASTER) && defined(LPUART_LIN_SLAVE)
     /* Check status */
	Exit_Example(LPUART_LIN_IP_STATUS_TX_OK == LpuartMasterStatus && LPUART_LIN_IP_STATUS_RX_OK == LpuartSlaveStatus);
#elif defined(LPUART_LIN_MASTER) && defined(FLEXIO_LIN_SLAVE)
	 /* Check status */
	Exit_Example(LPUART_LIN_IP_STATUS_TX_OK == LpuartMasterStatus && FLEXIO_LIN_IP_STATUS_RX_OK == FlexioSlaveStatus);
#endif

    return (exit_code);

}

/** @} */
