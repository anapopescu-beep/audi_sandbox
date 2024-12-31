#ifndef ETS_MACROS_H
#define ETS_MACROS_H
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

/*==================[includes]====================================================================*/

/*==================[macros]======================================================================*/

/* List of DET IDs */
#define ETS_INSTANCE_ID                                  (0xFFU)
#define ETS_INIT_ID                                      (0x00U)
#define ETS_MAIN_ID                                      (0x01U)
#define ETS_ALREADY_INITIALIZED                          (0x00U)
#define ETS_NOT_INITIALIZED                              (0x01U)

/** \brief ETS_ClientServiceCallEchoUINT8Array */
#define ETS_CLI_SER_CALL_ECH_UINT8_ARR                   (0x10U)
/** \brief ETS_ClientServiceActivate */
#define ETS_CLI_SER_ACT                                  (0x11U)
/** \brief ETS_ClientServiceDeactivate */
#define ETS_CLI_SER_DEACT                                (0x12U)
/** \brief ETS_SuspendInterface */
#define ETS_SUS_INT_FACE                                 (0x13U)
/** \brief ETS_ClientServiceSubscribeEventgroup */
#define ETS_CLI_SER_SUB_EVE_GRP                          (0x14U)

/** \brief ETS_TriggerEventUINT8 */
#define ETS_TRIG_EVENT_UINT8                             (0x20U)
/** \brief ETS_xxxx */
#define ETS_TRIG_EVENT_UINT8_ARRAY                       (0x21U)
/** \brief ETS_TriggerEventUINT8E2E */
#define ETS_TRIG_EVENT_UINT8_E2E                         (0x22U)
/** \brief ETS_TriggerEventUINT8Multicast */
#define ETS_TRIG_EVENT_UINT8_MULT_CST                    (0x23U)
/** \brief ETS_TriggerEventUINT8Reliable */
#define ETS_TRIG_EVENT_UINT8_RELIB                       (0x24U)

/** \brief ETS_FieldNotify_UINT8Reliable */
#define ETS_FIEL_NOTIF_UINT8_RELIB                       (0x30U)
/** \brief ETS_FieldNotify_UINT8Array */
#define ETS_FIEL_NOTIF_UINT8_ARRAY                       (0x31U)
/** \brief ETS_FieldNotify_UINT8 */
#define ETS_FIEL_NOTIF_UINT8                             (0x32U)
/** \brief ETS_FieldNotify_InterfaceVersion */
#define ETS_FIEL_NOTIF_INTERF_VER                        (0x33U)

/** \brief ETS_TestEventUINT8 */
#define ETS_TEST_EVT_UINT8                               (0x40U)
/** \brief ETS_TestEventUINT8Reliable */
#define ETS_TEST_EVT_UINT8_REL                           (0x41U)
/** \brief ETS_TestEventUINT8Multicast */
#define ETS_TEST_EVT_UINT8_MULT_CST                      (0x42U)

/** \brief ETS_Action_ClientActivateInterface */
#define ETS_ACT_CLI_ACT_INTERF                           (0x50U)
/** \brief ETS_Action_SuspendInterface */
#define ETS_ACT_SUSP_INTERF                              (0x51U)
/** \brief ETS_Action_ResumeInterface */
#define ETS_ACT_RES_INTERF                               (0x52U)
/** \brief ETS_Action_TriggerEventUINT8 */
#define ETS_ACT_TRIG_EVT_UINT8                           (0x53U)
/** \brief ETS_Action_TriggerEventUINT8Array */
#define ETS_ACT_TRIG_EVT_UINT8_ARRAY                     (0x54U)
/** \brief ETS_Action_TriggerEventUINT8E2E */
#define ETS_ACT_TRIG_EVT_UINT8_E2E                       (0x55U)
/** \brief ETS_Action_TriggerEventUINT8Multicast */
#define ETS_ACT_TRIG_EVT_UINT8_MULTI_CST                 (0x56U)
/** \brief ETS_Action_TriggerEventUINT8Reliable */
#define ETS_ACT_TRIG_EVT_UINT8_RELIAB                    (0x57U)
/** \brief ETS_Action_ClientSubscribeEventgroup */
#define ETS_ACT_CLI_SUB_EVT_GRP                          (0x58U)
/** \brief ETS_Action_ClientUnsubscribeEventgroup */
#define ETS_ACT_CLI_UNSUB_EVT_GRP                        (0x59U)
/** \brief ETS_Action_ClientDeactivateInterface */
#define ETS_ACT_CLI_DE_ACT_INTERF                        (0x5AU)

/** \brief ETS_TestEventUINT8Array */
#define ETS_TEST_EVT_UINT8_ARRAY                         (0x60U)
/** \brief ETS_TestEventUINT8E2E */
#define ETS_TEST_EVT_UINT8_E2E                           (0x61U)


/* List of Methods */
#define ID_CHECK_BYTEORDER                               (0x1FU)

#define ID_RESETINTERFACE                                (0x01U)
#define ID_SUSPENDINTERFACE                              (0x02U)

#define ID_ECHO_COMMONDATATYPES                          (0x23U)
#define ID_ECHO_ENUM                                     (0x17U)
#define ID_ECHO_EXTENDEDDATATYPES                        (0x24U)
#define ID_ECHO_EXTENDEDDATATYPES16BITLENGTHANDTYPEFIELD (0x39U)
#define ID_ECHO_EXTENDEDDATATYPES8BITLENGTHANDTYPEFIELD  (0x38U)
#define ID_ECHO_FLOAT64                                  (0x12U)
#define ID_ECHO_INT64                                    (0x34U)
#define ID_ECHO_INT8                                     (0x0EU)
#define ID_ECHO_STATICUINT8ARRAY                         (0x36U)
#define ID_ECHO_STRUCT                                   (0x18U)
#define ID_ECHO_STRUCTSIMPLE                             (0x40U)
#define ID_ECHO_TYPEDEF                                  (0x1AU)
#define ID_ECHO_UINT64                                   (0x33U)
#define ID_ECHO_UINT8                                    (0x08U)
#define ID_ECHO_UINT8ARRAY                               (0x09U)
#define ID_ECHO_UINT8ARRAY8BITLENGTH                     (0x3EU)
#define ID_ECHO_UINT8ARRAY16BITLENGTH                    (0x3FU)
#define ID_ECHO_UINT8ARRAY2DIM                           (0x35U)
#define ID_ECHO_UINT8ARRAYMINSIZE                        (0x37U)
#define ID_ECHO_UINT8E2E                                 (0x0BU)
#define ID_ECHO_UINT8RELIABLE                            (0x0AU)
#define ID_ECHO_UNION                                    (0x19U)
#define ID_ECHO_UTF16DYNAMIC                             (0x16U)
#define ID_ECHO_UTF16FIXED                               (0x14U)
#define ID_ECHO_UTF8DYNAMIC                              (0x15U)
#define ID_ECHO_UTF8FIXED                                (0x13U)
#define ID_ECHO_BITFIELDS                                (0x41U)

#define ID_TRIGGER_EVENTUINT8                            (0x03U)
#define ID_TRIGGER_EVENTUINT8ARRAY                       (0x04U)
#define ID_TRIGGER_EVENTUINT8E2E                         (0x06U)
#define ID_TRIGGER_EVENTUINT8RELIABLE                    (0x05U)
#define ID_TRIGGER_EVENTUINT8MULTICAST                   (0x3AU)

#define ID_CLIENTSERVICE_ACTIVATE                        (0x2FU)
#define ID_CLIENTSERVICE_DEACTIVATE                      (0x30U)
#define ID_CLIENTSERVICE_CALLECHOUINT8ARRAY              (0x31U)
#define ID_CLIENTSERVICE_SUBSCRIBEEVENTGROUP             (0x32U)
#define ID_CLIENTSERVICE_GETLASTVALUEOFEVENTTCP          (0x3BU)
#define ID_CLIENTSERVICE_GETLASTVALUEOFEVENTUDPUNICAST   (0x3CU)
#define ID_CLIENTSERVICE_GETLASTVALUEOFEVENTUDPMULTICAST (0x3DU)

/* List of Events and fields*/

#define ID_TESTEVENTUINT8                                (0x81U)
#define ID_TESTEVENTUINT8ARRAY                           (0x82U)
#define ID_TESTEVENTUINT8RELIABLE                        (0x83U)
#define ID_TESTEVENTUINT8E2E                             (0x84U)
#define ID_TESTEVENTUINT8MULTICAST                       (0x8BU)

#define ID_INTERFACEVERSION_NOTIFY                       (0x85U)
#define ID_TESTFIELDUINT8_NOTIFY                         (0x86U)
#define ID_TESTFIELDUINT8ARRAY_NOTIFY                    (0x87U)
#define ID_TESTFIELDUINT8RELIABLE_NOTIFY                 (0x88U)
#define ID_INTERFACEVERSION_GETTER                       (0x25U)
#define ID_TESTFIELDUINT8_GETTER                         (0x26U)
#define ID_TESTFIELDUINT8_SETTER                         (0x27U)
#define ID_TESTFIELDUINT8ARRAY_GETTER                    (0x28U)
#define ID_TESTFIELDUINT8ARRAY_SETTER                    (0x29U)
#define ID_TESTFIELDUINT8RELIABLE_GETTER                 (0x2AU)
#define ID_TESTFIELDUINT8RELIABLE_SETTER                 (0x2BU)

/*==================[type definitions]============================================================*/

/*==================[external function declarations]==============================================*/

/*==================[external constants]==========================================================*/

/*==================[external data]===============================================================*/

/*================================================================================================*/

#endif /* #ifndef ETS_MACROS_H */

/*==================[end of file]=================================================================*/
