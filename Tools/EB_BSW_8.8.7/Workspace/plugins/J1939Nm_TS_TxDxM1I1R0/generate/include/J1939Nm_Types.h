/* --------{ EB Automotive Header File }-------- */
/* This file generated from the configuration of J1939Nm module . */

[!INCLUDE "J1939Nm_Vars.m"!][!//
#ifndef J1939NM_TYPES_H
#define J1939NM_TYPES_H
[!//
/*==================[includes]===============================================*/

/* !LINKSTO SWS_J1939Nm_00008,1 */
#include <ComStack_Types.h>   /* Inclusion of ComStack types */
#include <NmStack_Types.h>   /* Inclusion of Nm Stack types */
#include <EcuC.h>			  /* Inclusion of Ecuc module */

/*============================================================================*/
/*                       J1939Nm Type Definitions                             */
/*============================================================================*/

#if (defined J1939NM_NO_TRANSMISSION_PENDING)
#error J1939NM_NO_TRANSMISSION_PENDING already defined
#endif
/** \brief Switch, indicating the status of No pending transmission */
#define J1939NM_NO_TRANSMISSION_PENDING      0U

#if (defined J1939NM_TRANSMISSION_PENDING)
#error J1939NM_TRANSMISSION_PENDING already defined
#endif
/** \brief Switch, indicating the status of pending transmission */
#define J1939NM_TRANSMISSION_PENDING      1U

#if (defined J1939NM_TRANSMISSION_ABORT)
#error J1939NM_TRANSMISSION_ABORT already defined
#endif
/** \brief Switch, indicating the status of transmission abort */
#define J1939NM_TRANSMISSION_ABORT      2U

#if (defined J1939NM_NUMBER_OF_NODES)
#error J1939NM_NUMBER_OF_NODES already defined
#endif
/** \brief Switch, indicating Total Number of Nodes */
#define J1939NM_NUMBER_OF_NODES      [!"$J1939NmMaxNodes"!]U

/*==================[type definitions]=======================================*/

/** \brief Type for the configuration data (place holder because of pre-compile
 **        time configuration support).
 */
 
/*!LINKSTO SWS_J1939Nm_00030,1 */
typedef struct
{
  uint32 Dummy;   /**< Dummy variable to have valid C code */
} J1939Nm_ConfigType;

/* J1939Nm state-machine states */
typedef enum
{
    J1939NM_UNINIT = 0, /* J1939Nm Uninitialized state */
    J1939NM_INIT        /* J1939Nm Initialized state */
} J1939Nm_StateType;

/* J1939Nm Off-line sub-state-machine states */
typedef enum
{
    J1939NM_OFFLINE_CLAIMING = 0, /* OFF-LINE claiming state */
    J1939NM_OFFLINE_ACLOST        /* OFF-LINE Address claim lost state */
} J1939Nm_OfflineStateType;

/* J1939Nm NodeChannel types */
typedef struct
{
    Nm_ModeType                             NodeChannelMode;
    Nm_StateType                            NodeChannelNetworkModeState;
    J1939Nm_OfflineStateType                NodeChannelOfflineSubState;
    uint8                                   NodeID;  /* ID of the NodeChannel related Node */
} J1939Nm_NodeChannelType;

/* J1939Nm Pdu description type */
typedef struct
{
    PduIdType                               PduID;
    EcuC_PduIdType                          Ecuc_PduId;
} J1939Nm_PduDescriptorType;

[!IF "$J1939NmDemEventRefCount != 0"!]
/* J1939Nm Dem Event Description Type */
typedef struct
{
  uint16                                     EventId;
  uint8                                      NodeId;
}J1939Nm_DemEventType;
[!ENDIF!]

/* J1939Nm Channel description type */
typedef struct
{
    J1939Nm_NodeChannelType                  NodeChannel[J1939NM_NUMBER_OF_NODES];
    J1939Nm_PduDescriptorType                TxPdu;
    J1939Nm_PduDescriptorType                RxPdu;
    uint8                                    NumberOfNodesInChannel;
    uint8                                    ChannelUsesAddressArbitration;
[!IF "$J1939NmDemEventRefCount != 0"!]
    uint8                                    NumberOfDemEventsInChannel;
    const J1939Nm_DemEventType               *DemEvent;
[!ENDIF!]
} J1939Nm_ChannelConfigType;

/* J1939Nm Node description type */
typedef struct
{
    uint8                                   NodeID;
    const uint8                             *Name;    /* array of bytes of the <Name> of the Node */
    const uint8                             NodePreferredAddress;
    boolean                                 StartUpDelay;
} J1939Nm_NodeDescriptorType;

/* J1939Nm global parameters */
typedef struct
{
    J1939Nm_ChannelConfigType                * J1939Nm_ChannelConfig;
    const J1939Nm_NodeDescriptorType         * J1939Nm_NodeDescriptor;
    uint8                                    * J1939Nm_CanIfTransmissionState;
} J1939Nm_DescriptorType;

/* definition of pointer to J1939NmUserCallout function  */
typedef void (* J1939Nm_CalloutFunctionPointerType)( VAR(NetworkHandleType, AUTOMATIC) channel,
                                                                        VAR(uint8, AUTOMATIC) sourceAddress,
                                                                        P2CONST(uint8, AUTOMATIC, AUTOMATIC) name
);

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* ifndef J1939NM_TYPES_H */
/*==================[end of file]============================================*/
