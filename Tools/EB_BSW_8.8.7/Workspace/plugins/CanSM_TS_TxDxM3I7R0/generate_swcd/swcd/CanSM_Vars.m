[!/**
 * \file
 *
 * \brief AUTOSAR CanSM
 *
 * This file contains the implementation of the AUTOSAR
 * module CanSM.
 *
 * \version 3.7.13
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */!][!//
[!NOCODE!]
[!IF "not(var:defined('CANSM_VARS_M'))"!]
[!VAR "CANSM_VARS_M"="'true'"!]

[!VAR "multiCoreSupport"="as:modconf('CanSM')[1]/CanSMGeneral/CanSMMultiCoreSupport"!]
[!IF "$multiCoreSupport = 'true'"!]
  [!VAR "ChannelsDistributionSupport"="as:modconf('CanSM')[1]/CanSMGeneral/CanSMDistributedChannelProcessingSupport"!]
[!ENDIF!]

[!ENDIF!]
[!ENDNOCODE!][!//
