/*********************************************************************************/
/*                                                                               */
/*                                  CAN Stack                                    */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/*                               UDS configuration                               */
/*                                                                               */
/*********************************************************************************/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*%%   _____________________________   %%  \file UDS_Cfg.c                       */
/*%%  |                             |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%  Module version: 3.9.1 BL-3.X */
/*%%  |   &       &    &            |  %%  Variant: ISO                  */
/*%%  |   &&&&    &&&&&             |  %%                                        */
/*%%  |   &       &    &            |  %%                                        */
/*%%  |   &&&&&   &&&&&             |  %%                                        */
/*%%  |_____________________________|  %%                                        */
/*%%                                   %%                                        */
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                        */
/*********************************************************************************/
/* Copyright 2010 by Elektrobit Automotive GmbH                                  */
/* All rights exclusively reserved for Elektrobit Automotive GmbH,               */
/* unless expressly agreed to otherwise.                                         */
/*********************************************************************************/




/******************************** FILE INCLUSION *********************************/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Header Files: UDS                                                           */
#include "EB_Prj.h"
/*                                                                               */
/*********************************************************************************/




/****************************** PUBLIC DEFINITIONS *******************************/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Public Variables                                                            */

/*-------------------------------------------------------------------------------*/
/* - Public Function Prototypes                                                  */

/*-------------------------------------------------------------------------------*/
/* - Public Callback Prototypes                                                  */

/*                                                                               */
/*********************************************************************************/


/***************************** PRIVATE DEFINITIONS *******************************/
/*                                                                               */
/*-------------------------------------------------------------------------------*/
/* - Private Constants                                                           */

/*-------------------------------------------------------------------------------*/
/* - Private Types                                                               */

/*-------------------------------------------------------------------------------*/
/* - Private Variables                                                           */



/* Diagnostic services configuration 1, stored in Read-Only memory */
const tUdsSrvCfg1 m_astDiagSrvCfg1[UDS_SRV_CFG1_MAX] =
{
    {UDS_SRV_DSC, 0x01U, 0x7U, 2U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_PROGRAMMING_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_DSC, 0x02U, 0x7U, 2U, 0U, UDS_ADDR_PHYSICAL, &APP_ProgSession},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_PROGRAMMING_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_DSC, 0x03U, 0x7U, 2U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_PROGRAMMING_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_ER, 0x01U, 0x7U, 2U, 0U, UDS_ADDR_PHYSICAL, &APP_EcuReset},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_PROGRAMMING_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_TP, 0x00U, 0x3U, 2U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_PROGRAMMING_MASK */
    {UDS_SRV_CDTCS, 0x02U, 0x4U, 5U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, &APP_ControlDTCSetting},    /*  UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_CDTCS, 0x01U, 0x4U, 5U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, &APP_ControlDTCSetting},    /*  UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_CC, 0x03U, 0x4U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, &APP_CommunicationControl},    /*  UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_CC, 0x01U, 0x4U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, &APP_CommunicationControl},    /*  UDS_SESSION_EXTENDED_DIAG_MASK */
};

/* Diagnostic services configuration 2, stored in Read-Only memory */
const tUdsSrvCfg2 m_astDiagSrvCfg2[UDS_SRV_CFG2_MAX] =
{
    {UDS_SRV_RDBI, 0x1008U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0x1009U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf186U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0x2003U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0x2008U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0x2009U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0x200aU, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0x200bU, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0x200cU, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0x200fU, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0x2010U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf180U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf181U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf182U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf183U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf184U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf185U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf187U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf18cU, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, &UDS_ReadDataByIdentifier},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf190U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf192U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf193U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf194U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf195U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf196U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf1a0U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf1a4U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf1a5U, 0x5U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, NULL},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RDBI, 0xf1aaU, 0x7U, 3U, 0U, UDS_ADDR_PHYSICAL_FUNCTIONAL, &UDS_ReadDataByIdentifier},    /* UDS_SESSION_DEFAULT_MASK | UDS_SESSION_PROGRAMMING_MASK | UDS_SESSION_EXTENDED_DIAG_MASK */

};


/* Diagnostic services configuration 3, stored in Read-Only memory */
const tUdsSrvCfg3 m_astDiagSrvCfg3[UDS_SRV_CFG3_MAX] =
{
    {UDS_SRV_RC, 0x01U, 0x0203U, 0x4U, 4U, 0U, UDS_ADDR_PHYSICAL, &APP_ReqCheckProgPreCondition},    /*  UDS_SESSION_EXTENDED_DIAG_MASK */
    {UDS_SRV_RC, 0x01U, 0xf001U, 0x4U, 4U, 0U, UDS_ADDR_PHYSICAL, &APP_ClearProgCounter},    /*  UDS_SESSION_EXTENDED_DIAG_MASK */
};



/* Structure storing sessions and associated NRC_78 timings (P2 and P2Star) */
const tUdsSessionInfo m_stSessionInfo[UDS_CONFIGURABLE_SESSION_MAX] = 
{
  
  {1, 50, 5000, UDS_SESSION_PROT_DEFAULT, UDS_SESSION_PROT_DEFAULT_MASK},
  {2, 50, 5000, UDS_SESSION_PROT_PROGRAMMING, UDS_SESSION_PROT_PROGRAMMING_MASK},
  {3, 50, 5000, UDS_SESSION_PROT_EXTENDED_DIAG, UDS_SESSION_PROT_EXTENDED_DIAG_MASK},
  {96, 50, 5000, UDS_SESSION_PROT_SUPPLIER, UDS_SESSION_PROT_SUPPLIER_MASK},
  {64, 50, 5000, UDS_SESSION_PROT_OTHER_01, UDS_SESSION_PROT_OTHER_01_MASK},
  {65, 50, 5000, UDS_SESSION_PROT_OTHER_02, UDS_SESSION_PROT_OTHER_02_MASK},
  {66, 50, 5000, UDS_SESSION_PROT_OTHER_03, UDS_SESSION_PROT_OTHER_03_MASK},
  {67, 50, 5000, UDS_SESSION_PROT_OTHER_04, UDS_SESSION_PROT_OTHER_04_MASK}
};

/*-------------------------------------------------------------------------------*/
/* - Private Macros                                                              */

/*-------------------------------------------------------------------------------*/
/* - Private Function Prototypes                                                 */

/*                                                                               */
/*********************************************************************************/




/******************************** IMPLEMENTATION *********************************/
/*                                                                               */

/*-------------------------------------------------------------------------------*/
/* - Public Functions                                                            */

/*-------------------------------------------------------------------------------*/
/* - Private Functions                                                           */

/*-------------------------------------------------------------------------------*/
/* - Public Callbacks                                                            */

/*                                                                               */
/*********************************************************************************/

