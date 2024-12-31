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

/*  MISRA-C:2012 Deviation List
 *
 *   MISRAC2012-1) Deviated Rule: Dir 4.5 (Advisory)
 *     Identifiers in the same name space with overlapping visibility should be typographically unambiguous.
 *
 *     Reason:
 *     Identifier name change didin't solve issue.
 *
 */
/* ==================[Includes]=============================================== */

#include <ETS_FieldsHandler.h>
#include <ETS_Types.h>
#include <Rte_ETS.h>
#include <string.h>
#include <TSMem.h>
#include <ETS_Cfg.h>

/*===================[Declaration of internal functions]=======================*/

#define ETS_START_SEC_CODE
#include <ETS_MemMap.h>

#if ( ETS_Fields_InterfaceVersion == TRUE )
STATIC ETS_VersionType ETS_Field_InterfaceVersion = { 1, 0 };
#endif

#if ( ETS_Fields_TestFieldUINT8 == TRUE )
STATIC uint8 ETS_Field_Uint8 = 0;
#endif

#if ( ETS_Fields_TestFieldUINT8Reliable == TRUE )
STATIC uint8 ETS_Field_Uint8Reliable = 0;
#endif

#if ( ETS_Fields_TestFieldUINT8Array == TRUE )
STATIC ETS_Uint8Array ETS_Field_Uint8Array = { 0, {0,1,2,3,4} };
#endif

/* Send field notifications */
#if ( ETS_Fields_TestFieldUINT8 == TRUE )
STATIC FUNC(void, RTE_CODE) ETS_FieldNotify_UINT8(void);
#endif
#if ( ETS_Fields_TestFieldUINT8Reliable == TRUE )
STATIC FUNC(void, RTE_CODE) ETS_FieldNotify_UINT8Reliable(void);
#endif
#if ( ETS_Fields_TestFieldUINT8Array == TRUE )
STATIC FUNC(void, RTE_CODE) ETS_FieldNotify_UINT8Array(void);
#endif
#if ( ETS_Fields_InterfaceVersion == TRUE )
STATIC FUNC(void, RTE_CODE) ETS_FieldNotify_InterfaceVersion(void);
#endif

/**
 * \brief Notification sending when UINT8 field changes.
 *
 * \param[in] none
 *
 * \return none
 *
 */

/* !LINKSTO swdd.EB.ETS.FieldsHandler.3, 1 */
#if ( ETS_Fields_TestFieldUINT8 == TRUE )
STATIC FUNC(void, RTE_CODE) ETS_FieldNotify_UINT8(void)
{
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType ret_Receive;

  ret_Receive = Rte_Write_ETS_NotifyFieldTestFieldUINT8_Notifier(ETS_Field_Uint8);

  if(ret_Receive != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_FIEL_NOTIF_UINT8, ID_TESTFIELDUINT8_NOTIFY);
  }
#else
  (void)Rte_Write_ETS_NotifyFieldTestFieldUINT8_Notifier(ETS_Field_Uint8);
#endif
}
#endif

/**
 * \brief Notification sending when UINT8Reliable field changes.
 *
 * \param[in] none
 *
 * \return none
 *
 */
#if ( ETS_Fields_TestFieldUINT8Reliable == TRUE )
/* !LINKSTO swdd.EB.ETS.FieldsHandler.1, 1 */
STATIC FUNC(void, RTE_CODE) ETS_FieldNotify_UINT8Reliable(void)
{
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType ret_Receive;

  ret_Receive = Rte_Write_ETS_NotifyFieldTestFieldUINT8Reliable_Notifier(ETS_Field_Uint8Reliable);

  if(ret_Receive != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_FIEL_NOTIF_UINT8_RELIB, ID_TESTFIELDUINT8RELIABLE_NOTIFY);
  }
#else
  (void)Rte_Write_ETS_NotifyFieldTestFieldUINT8Reliable_Notifier(ETS_Field_Uint8Reliable);
#endif
}
#endif

/**
 * \brief Notification sending when UINT8Array field changes.
 *
 * \param[in] none
 *
 * \return none
 *
 */

#if ( ETS_Fields_TestFieldUINT8Array == TRUE )
/* !LINKSTO swdd.ETS-0053, 1 */
STATIC FUNC(void, RTE_CODE) ETS_FieldNotify_UINT8Array(void)
{
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType ret_Receive;

  ret_Receive = Rte_Send_ETS_NotifyFieldTestFieldUINT8Array_Notifier(&ETS_Field_Uint8Array);

  if(ret_Receive != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_FIEL_NOTIF_UINT8_ARRAY, ID_TESTFIELDUINT8ARRAY_NOTIFY);
  }
#else
  (void)Rte_Send_ETS_NotifyFieldTestFieldUINT8Array_Notifier(&ETS_Field_Uint8Array);
#endif
}
#endif

/**
 * \brief Notification sending when InterfaceVersion field changes.
 *
 * \param[in] none
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0048, 1 */
#if ( ETS_Fields_InterfaceVersion == TRUE )
STATIC FUNC(void, RTE_CODE) ETS_FieldNotify_InterfaceVersion(void)
{
#if (ETS_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType ret_Receive;

  ret_Receive = Rte_Write_ETS_NotifyFieldsInterfaceVersion_Notifier(&ETS_Field_InterfaceVersion);

  if(ret_Receive != E_OK)
  {
    (void)Rte_Call_Det_ReportError(ETS_INSTANCE_ID, ETS_FIEL_NOTIF_INTERF_VER, ID_INTERFACEVERSION_NOTIFY);
  }
#else
  (void)Rte_Write_ETS_NotifyFieldsInterfaceVersion_Notifier(&ETS_Field_InterfaceVersion);
#endif
}
#endif

/* ==================[Definition of functions with external linkage]========== */

/**
 * \brief Gets stored version information from.
 *
 * \param[out] Getter Reads majorEtsVersion and minorEtsVersion of the field internal
 *             face.
 *
 * \return none
 *
 */
#if ( ETS_Fields_InterfaceVersion == TRUE )
/* !LINKSTO swdd.EB.ETS.FieldsHandler.9, 1 */
/* Deviation MISRAC2012-1 */
FUNC(void, RTE_CODE) ETS_GetField_InterfaceVersion(P2VAR(ETS_VersionType, AUTOMATIC, RTE_APPL_DATA) Getter)
{
  Getter->majorEtsVersion = ETS_Field_InterfaceVersion.majorEtsVersion;
  Getter->minorEtsVersion = ETS_Field_InterfaceVersion.minorEtsVersion;
}
#endif

/**
 * \brief Notify version information change.
 *
 * \param[in] none.
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0048, 1 */
#if ( ETS_Fields_InterfaceVersion == TRUE )
FUNC(void, RTE_CODE) ETS_SetField_InterfaceVersion(void)
{
  ETS_FieldNotify_InterfaceVersion();
}
#endif

/**
 * \brief Sets new value to ETS_Field_Uint8 field and send notify.
 *
 * \param[in] Setter Setted value.
 *
 * \return none
 *
 */
/* !LINKSTO swdd.ETS-0050, 1 */
/* !LINKSTO swdd.EB.ETS.FieldsHandler.4, 1 */
#if ( ETS_Fields_TestFieldUINT8 == TRUE )
FUNC(void, RTE_CODE) ETS_SetField_uint8(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Setter)
{
  ETS_Field_Uint8 = *Setter;
  *Setter = ETS_Field_Uint8;
  ETS_FieldNotify_UINT8();
}
#endif

/**
 * \brief Sets new value to ETS_Field_Uint8Reliable field and send notify.
 *
 * \param[in] Setter Setted value.
 *
 * \return none
 *
 */
#if ( ETS_Fields_TestFieldUINT8Reliable == TRUE )
/* !LINKSTO swdd.ETS-0056, 1 */
/* !LINKSTO swdd.EB.ETS.FieldsHandler.6, 1 */
FUNC(void, RTE_CODE) ETS_SetField_uint8Reliable(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Setter)
{
  ETS_Field_Uint8Reliable = *Setter;
  *Setter = ETS_Field_Uint8Reliable;
  ETS_FieldNotify_UINT8Reliable();
}
#endif

/**
 * \brief Sets new value to ETS_Field_Uint8Array field and send notify.
 *
 * \param[in] Setter Setted value.
 *
 * \return none
 *
 */
#if ( ETS_Fields_TestFieldUINT8Array == TRUE )
/* !LINKSTO swdd.EB.ETS.FieldsHandler.8, 1 */
FUNC(void, RTE_CODE) ETS_SetField_VarArray(P2VAR(ETS_Uint8Array, AUTOMATIC, RTE_APPL_DATA) Setter)
{
  /* Save data */
  ETS_Field_Uint8Array.size = Setter->size;

  TS_MemCpy(ETS_Field_Uint8Array.elem, Setter->elem, Setter->size);

  ETS_FieldNotify_UINT8Array();
}
#endif

/**
 * \brief Gets ETS_Field_Uint8 value.
 *
 * \param[out] Getter Read uint8 value.
 *
 * \return none
 *
 */
#if ( ETS_Fields_TestFieldUINT8 == TRUE )
/* !LINKSTO swdd.EB.ETS.FieldsHandler.5, 1 */
FUNC(void, RTE_CODE) ETS_GetField_uint8(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Getter)
{
  *Getter = ETS_Field_Uint8;
}
#endif

/**
 * \brief Gets ETS_Field_Uint8Reliable value.
 *
 * \param[out] Getter Read uint8 value.
 *
 * \return none
 *
 */
#if ( ETS_Fields_TestFieldUINT8Reliable == TRUE )
/* !LINKSTO swdd.EB.ETS.FieldsHandler.7, 1 */
FUNC(void, RTE_CODE) ETS_GetField_uint8Reliable(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Getter)
{
  *Getter = ETS_Field_Uint8Reliable;
}
#endif

/**
 * \brief Gets ETS_Field_Uint8Array value.
 *
 * \param[out] Getter Read ETS_Uint8Array value.
 *
 * \return none
 *
 */
#if ( ETS_Fields_TestFieldUINT8Array == TRUE )
/* !LINKSTO swdd.EB.ETS.FieldsHandler.10, 1 */
FUNC(void, RTE_CODE) ETS_GetField_VarArray(P2VAR(ETS_Uint8Array, AUTOMATIC, RTE_APPL_DATA) Getter)
{
  Getter->size = ETS_Field_Uint8Array.size;
  TS_MemCpy(Getter->elem, ETS_Field_Uint8Array.elem, ETS_Field_Uint8Array.size);
}
#endif

#define ETS_STOP_SEC_CODE
#include <ETS_MemMap.h>

/*--- End of file ------------------------------------------------------------*/
