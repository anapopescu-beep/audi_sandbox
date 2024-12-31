[!/**
 * \file
 *
 * \brief AUTOSAR Nm
 *
 * This file contains the implementation of the AUTOSAR
 * module Nm.
 *
 * \version 5.12.12
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */!][!//
[!NOCODE!]
[!AUTOSPACING!]

[!/* multiple inclusion protection */!]
[!IF "not(var:defined('NM_FUNCTIONS_M'))"!]
[!VAR "NM_FUNCTIONS_M"="'true'"!]

[!MACRO "SetupSynchronizedPncShutdownVariables"!]

[!VAR "BusNames" = "''"!]
[!VAR "BusNrOfPassiveChannels" = "''"!]
[!VAR "PnInfoLength" = "num:i(0)"!]
[!IF "as:modconf('Nm')[1]/NmGlobalConfig/NmGlobalFeatures/NmMultiCoreSupport='true'"!]
  [!IF "node:exists(as:modconf('Nm')[1]/NmGlobalConfig/NmGlobalFeatures/NmSynchronizedPncShutdownEnabled) and 
       (as:modconf('Nm')[1]/NmGlobalConfig/NmGlobalFeatures/NmSynchronizedPncShutdownEnabled = 'true')"!] 
    [!IF "count(as:modconf('Nm')[1]/NmChannelConfig/*[(node:exists(NmBusType/NmStandardBusType)) and (NmBusType/NmStandardBusType = 'NM_BUSNM_CANNM')]) > 0"!]
      [!VAR "BusNames" = "concat($BusNames,' CanNm')"!]
      [!VAR "TempPassiveChannels" = "num:i(0)"!]
      [!LOOP "as:modconf('Nm')[1]/NmChannelConfig/*"!]
        [!IF "node:exists(NmBusType/NmStandardBusType) and (NmBusType/NmStandardBusType = 'NM_BUSNM_CANNM')"!]
          [!IF "node:exists(node:ref(NmComMChannelRef)/ComMPncGatewayType) and (node:ref(NmComMChannelRef)/ComMPncGatewayType = 'COMM_GATEWAY_TYPE_PASSIVE')"!]
            [!VAR "TempPassiveChannels" = "num:i($TempPassiveChannels + 1)"!]
          [!ENDIF!]
        [!ENDIF!]
      [!ENDLOOP!]
      [!VAR "BusNrOfPassiveChannels" = "concat($BusNrOfPassiveChannels,' ',$TempPassiveChannels)"!]
      [!IF "node:exists(as:modconf('CanNm')[1]/CanNmGlobalConfig/*[1]/CanNmPnInfo/CanNmPnInfoLength)"!]
        [!VAR "PnInfoLength" = "num:i(as:modconf('CanNm')[1]/CanNmGlobalConfig/*[1]/CanNmPnInfo/CanNmPnInfoLength)"!]
      [!ENDIF!]
    [!ENDIF!]
    
    
    [!IF "count(as:modconf('Nm')[1]/NmChannelConfig/*[(node:exists(NmBusType/NmStandardBusType)) and (NmBusType/NmStandardBusType = 'NM_BUSNM_FRNM')]) > 0"!]
      [!VAR "BusNames" = "concat($BusNames,' FrNm')"!]
      [!VAR "TempPassiveChannels" = "num:i(0)"!]
      [!LOOP "as:modconf('Nm')[1]/NmChannelConfig/*"!]
        [!IF "node:exists(NmBusType/NmStandardBusType) and (NmBusType/NmStandardBusType = 'NM_BUSNM_FRNM')"!]
          [!IF "node:exists(node:ref(NmComMChannelRef)/ComMPncGatewayType) and (node:ref(NmComMChannelRef)/ComMPncGatewayType = 'COMM_GATEWAY_TYPE_PASSIVE')"!]
            [!VAR "TempPassiveChannels" = "num:i($TempPassiveChannels + 1)"!]
          [!ENDIF!]
        [!ENDIF!]
      [!ENDLOOP!]
      [!VAR "BusNrOfPassiveChannels" = "concat($BusNrOfPassiveChannels,' ',$TempPassiveChannels)"!]
      [!IF "node:exists(as:modconf('FrNm')[1]/FrNmGlobalConfig/FrNmGlobalFeatures/FrNmPnInfo/FrNmPnInfoLength)"!]
        [!VAR "PnInfoLength" = "num:i(as:modconf('FrNm')[1]/FrNmGlobalConfig/FrNmGlobalFeatures/FrNmPnInfo/FrNmPnInfoLength)"!]
      [!ENDIF!]
    [!ENDIF!]
    
    
    [!IF "count(as:modconf('Nm')[1]/NmChannelConfig/*[(node:exists(NmBusType/NmStandardBusType)) and (NmBusType/NmStandardBusType = 'NM_BUSNM_UDPNM')]) > 0"!]
      [!VAR "BusNames" = "concat($BusNames,' UdpNm')"!]
      [!VAR "TempPassiveChannels" = "num:i(0)"!]
      [!LOOP "as:modconf('Nm')[1]/NmChannelConfig/*"!]
        [!IF "node:exists(NmBusType/NmStandardBusType) and (NmBusType/NmStandardBusType = 'NM_BUSNM_UDPNM')"!]
          [!IF "node:exists(node:ref(NmComMChannelRef)/ComMPncGatewayType) and (node:ref(NmComMChannelRef)/ComMPncGatewayType = 'COMM_GATEWAY_TYPE_PASSIVE')"!]
            [!VAR "TempPassiveChannels" = "num:i($TempPassiveChannels + 1)"!]
          [!ENDIF!]
        [!ENDIF!]
      [!ENDLOOP!]
      [!VAR "BusNrOfPassiveChannels" = "concat($BusNrOfPassiveChannels,' ',$TempPassiveChannels)"!]
      [!IF "node:exists(as:modconf('UdpNm')[1]/UdpNmGlobalConfig/*[1]/UdpNmPnInfo/UdpNmPnInfoLength)"!]
        [!VAR "PnInfoLength" = "num:i(as:modconf('UdpNm')[1]/UdpNmGlobalConfig/*[1]/UdpNmPnInfo/UdpNmPnInfoLength)"!]
      [!ENDIF!]
    [!ENDIF!]
  [!ENDIF!] [!/*[!IF "node:exists(as:modconf('Nm')[1]/NmGlobalConfig/NmGlobalFeatures/NmSynchronizedPncShutdownEnabled) and 
               *      (as:modconf('Nm')[1]/NmGlobalConfig/NmGlobalFeatures/NmSynchronizedPncShutdownEnabled = 'true')"!] 
               */!]
[!ENDIF!] [!/*[!IF "as:modconf('Nm')[1]/NmGlobalConfig/NmGlobalFeatures/NmMultiCoreSupport='true'"!]*/!]               
[!ENDMACRO!]

[!/* end of multiple inclusion protection */!]
[!ENDIF!]

[!ENDNOCODE!]
