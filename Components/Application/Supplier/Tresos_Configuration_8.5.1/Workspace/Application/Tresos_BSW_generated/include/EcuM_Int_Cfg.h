/**
 * \file
 *
 * \brief AUTOSAR EcuM
 *
 * This file contains the implementation of the AUTOSAR
 * module EcuM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2018 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#if (!defined ECUM_INT_CFG_H)
#define ECUM_INT_CFG_H

/*==================[includes]==============================================*/

/*==================[macros]================================================*/

/*------------------[EcuM Multi-Core implementation macros]-----------------------*/








#define ECUM_AL_DRIVERINITZERO()



#define ECUM_AL_DRIVERINITONE() EcuM_AL_DriverInitOne(EcuM_ConfigPtr)


#if (defined ECUM_NUM_CORES)
#error ECUM_NUM_CORES already defined
#endif
/** \brief Preprocessor macro defining the number of cores configured. */
#define ECUM_NUM_CORES 1U

#if (defined ECUM_CORE_ID_MASTER)
#error ECUM_CORE_ID_MASTER already defined
#endif
/** \brief Preprocessor macro defining the core configured as master core. */
#define ECUM_CORE_ID_MASTER 0U




/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* if !defined( ECUM_INT_CFG_H ) */
/*==================[end of file]===========================================*/
