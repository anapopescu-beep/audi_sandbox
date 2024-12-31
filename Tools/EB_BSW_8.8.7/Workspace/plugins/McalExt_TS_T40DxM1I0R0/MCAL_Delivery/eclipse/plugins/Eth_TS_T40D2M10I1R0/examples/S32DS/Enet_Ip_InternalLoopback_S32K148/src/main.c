#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Enet_Ip.h"
#include "Port_Ci_Port_Ip.h"
#include "Clock_Ip.h"
#include "OsIf.h"
#include "Mpu_Ip.h"

#include "check_example.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Transmit & receive in internal loopback mode
* @details
*/
int main(void)
{
    Enet_Ip_TxOptionsType txOptions = {FALSE, TRUE, ENET_CHECKSUM_INSERTION_DISABLE};
    Enet_Ip_BufferType txBuffer = {0};
    Enet_Ip_BufferType rxBuffer = {0};
    Enet_Ip_TxInfoType txInfo  = {0};
    Enet_Ip_RxInfoType rxInfo  = {0};
    Enet_Ip_StatusType status;
    uint8 macAddr[6U] = {0U};
    uint8 i;
    uint8 j = 0U;
    boolean result = TRUE;

    Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);
    /*sys_init();*/

    OsIf_Init(NULL_PTR);

    Port_Ci_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    Mpu_Ip_Init(&Mpu_Config_BOARD_INITPERIPHERALS);
    Enet_Ip_Init(INST_ENET_0, &Enet_0_ConfigPB_BOARD_INITPERIPHERALS);

    /* Setup the frame with the Mac address and size */
    Enet_Ip_GetMacAddr(INST_ENET_0, macAddr);

    /* Request a buffer of at least 64 bytes */
    txBuffer.Length = 64U - 4U;
    if ((ENET_STATUS_SUCCESS != Enet_Ip_GetTxBuff(INST_ENET_0, 0U, &txBuffer, NULL_PTR)) || (txBuffer.Length < 64U))
    {
        result = FALSE;
    }

    for (i = 0U; i < 12U; i++)
    {
        *((uint8 *)(&txBuffer.Data[0U] + i)) = macAddr[0 + j];
        if (j < 5U)
        {
            j++;
        }
        else
        {
            j = 0U;
        }
    }

    /* Frame Type = length frame */
    *((uint16 *)(txBuffer.Data + 13U)) = 64U;

    /* Send the ETH frame */
    txBuffer.Length = 60U;     /* Don't count FCS, because it is automatically inserted by the controller in this example */
    if (ENET_STATUS_SUCCESS != Enet_Ip_SendFrame(INST_ENET_0, 0U, &txBuffer, &txOptions))
    {
        result = FALSE;
    }

    /* Wait for the frame to be transmitted */
    do {
        status = Enet_Ip_GetTransmitStatus(INST_ENET_0, 0U, &txBuffer, &txInfo);
    } while (status == ENET_STATUS_BUSY);

    /* Check the frame status */
    if ((ENET_STATUS_SUCCESS != status) || (0U != txInfo.ErrMask))
    {
        result = FALSE;
    }

    /* Wait for the frame to be received */
    do {
        status = Enet_Ip_ReadFrame(INST_ENET_0, 0U, &rxBuffer, &rxInfo);
    } while (status == ENET_STATUS_RX_QUEUE_EMPTY);

    /* Check the frame status */
    if ((ENET_STATUS_SUCCESS != status) || (0U != rxInfo.ErrMask))
    {
        result = FALSE;
    }

    Enet_Ip_ProvideRxBuff(INST_ENET_0, 0U, &rxBuffer);

    Enet_Ip_DisableController(INST_ENET_0);

    Exit_Example(result);
    return 0;
}
#ifdef __cplusplus
}
#endif
