/**
 * \file
 *
 * \brief AUTOSAR Com
 *
 * This file contains the implementation of the AUTOSAR
 * module Com.
 *
 * \version 6.3.54
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef COM_TRACE_INTERNAL_H
#define COM_TRACE_INTERNAL_H
/*==================[inclusions]============================================*/

/*==================[macros]================================================*/
/* Place internal debug instrumentation macros in this file, i.e. all
   macros that are not generated for the public api instrumentation.
*/

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_COM_EB_HANDLEPDUGROUPRX_ENTRY
/** \brief Entry point before function Com_EB_HandlePduGroupRx()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_COM_EB_HANDLEPDUGROUPRX_ENTRY(a,b)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_COM_EB_HANDLEPDUGROUPRX_EXIT
/** \brief Exit point after function Com_EB_HandlePduGroupRx()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_COM_EB_HANDLEPDUGROUPRX_EXIT(a,b)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_COM_EB_HANDLEPDUGROUPTX_ENTRY
/** \brief Entry point before function Com_EB_HandlePduGroupTx()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_COM_EB_HANDLEPDUGROUPTX_ENTRY(a,b)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */

/** @cond
 ** \brief Exclude section from doxygen */
#ifndef DBG_COM_EB_HANDLEPDUGROUPTX_EXIT
/** \brief Exit point after function Com_EB_HandlePduGroupTx()
 **
 ** The macro takes the function arguments as parameters.
 */
#define DBG_COM_EB_HANDLEPDUGROUPTX_EXIT(a,b)
#endif
/** \brief Exclude section from doxygen
 ** @endcond */


/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef COM_TRACE_INTERNAL_H */
/*==================[end of file]===========================================*/
