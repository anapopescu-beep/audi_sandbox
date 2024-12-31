/**
 * \file
 *
 * \brief AUTOSAR Det
 *
 * This file contains the implementation of the AUTOSAR
 * module Det.
 *
 * \version 6.5.10
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef DET_INT_CFG_H
#define DET_INT_CFG_H

/*==[Includes]================================================================*/

[!IF "node:exists(DetNotification)"!][!//
[!LOOP "DetNotification/DetHeaderFile/*"!][!//
/* Include declaration of user defined callback function */
#include <[!"."!]>
[!ENDLOOP!][!//
[!ENDIF!][!//

/*==[Macros]==================================================================*/

/* !LINKSTO EB_Ref.SWS_Det_00180.Signature,1 */
/* !LINKSTO EB_Ref.SWS_Det_00180.ID,1 */

#if (defined DET_NOTIFICATIONS_DEVELOPMENT_ERROR)
#error DET_NOTIFICATIONS_DEVELOPMENT_ERROR is already defined
#endif

/* !LINKSTO Det.SWS_Det_00018,1 */
/* !LINKSTO Det.SWS_Det_00181,1 */
/** \brief Call user defined notification functions */
#define DET_NOTIFICATIONS_DEVELOPMENT_ERROR(a,b,c,d)              \
          do                                    \
          {                                     \
[!IF "node:exists(DetNotification)"!][!//
[!LOOP "DetNotification/DetErrorHook/*"!][!//
            [!"."!](a,b,c,d); \
[!ENDLOOP!][!//
[!ENDIF!][!//
          } while (0)

/* !LINKSTO Det.SWS_Det_00184,1 */
#if (defined DET_NOTIFICATIONS_RUNTIME_ERROR)
#error DET_NOTIFICATIONS_RUNTIME_ERROR is already defined
#endif

/** \brief Call user defined notification functions */
#define DET_NOTIFICATIONS_RUNTIME_ERROR(a,b,c,d)              \
          do                                    \
          {                                     \
[!IF "node:exists(DetNotification)"!][!//
[!LOOP "DetNotification/DetReportRuntimeErrorCallout/*"!][!//
            [!"."!](a,b,c,d); \
[!ENDLOOP!][!//
[!ENDIF!][!//
          } while (0)

/* !LINKSTO Det.SWS_Det_00187,1 */
#if (defined DET_NOTIFICATIONS_TRANSIENT_FAULT)
#error DET_NOTIFICATIONS_TRANSIENT_FAULT is already defined
#endif

/** \brief Call user defined notification functions */
#define DET_NOTIFICATIONS_TRANSIENT_FAULT(a,b,c,d)              \
          do                                    \
          {                                     \
[!IF "node:exists(DetNotification)"!][!//
[!LOOP "DetNotification/DetReportTransientFaultCallout/*"!][!//
            transientFaultRetVal |= [!"."!](a,b,c,d); \
[!ENDLOOP!][!//
[!ENDIF!][!//
          } while (0)

/*==[Types]===================================================================*/

/*==[Constants with external linkage]=========================================*/

/*==[Variables with external linkage]=========================================*/

/*==[Functions with external linkage]=========================================*/

#endif /* ifndef DET_INT_CFG_H */

