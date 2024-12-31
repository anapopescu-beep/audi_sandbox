######################################################################################
#
#   File:           T1_winIDEA.py
#
#   Description:    Script to read T1 trace buffer and write it to text files, for
#                   using with winIDEA.
#
#   Author:         Hwanjoon Kang
#
#   Copyright:      GLIWA embedded systems GmbH & Co. KG
#                   Weilheim i.OB.
#                   All rights reserved
#
######################################################################################

from __future__ import print_function

try:
    input = raw_input  # to work in Python 2 and Python 3
except NameError:
    pass

import os
import isystem.connect as ic
from isystem.connect import IConnectDebug
from datetime import datetime


cmgr = ic.ConnectionMgr()
cmgr.connectMRU('')


dbgCtrl = ic.CDebugFacade(cmgr)


try:

    #get sid
    rd_sid = dbgCtrl.evaluate(ic.IConnectDebug.fRealTime, '"T1_configGen.c"#T1_sid')
    value_sid = rd_sid.getLong()

    #get nofCore
    nofCores = dbgCtrl.evaluate(ic.IConnectDebug.fRealTime, '"T1_configGen.c"#T1_nOfCores')
    value_nofCores = nofCores.getLong()

    now = datetime.now().strftime('%Y%m%d_%H_%M_%S')
    for index in range(0,value_nofCores,1):
        txtTraceFileName = "T1scopeDebugger_{}_core{}.txt".format(now, index)
        T1_traceBufferCoreX = open(txtTraceFileName,"w")
        # get trace buffer size
        traceBufferAddStr = 'T1_scopeConstsPC[{}]->pTraceBuffer'.format(index)
        rd_pTraceBuffer = dbgCtrl.evaluate(ic.IConnectDebug.fRealTime, traceBufferAddStr)
        value_pTraceBuffer = "0x%0.8X" %(rd_pTraceBuffer.getAddress().m_aAddress)
        traceBufferLastIdxStr = 'T1_scopeConstsPC[{}]->bufferEntriesMinusOne'.format(index)
        rd_pTraceBufferLastIdx = dbgCtrl.evaluate(ic.IConnectDebug.fRealTime, traceBufferLastIdxStr)
        value_pTraceBufferLastIdx = rd_pTraceBufferLastIdx.getLong()
        traceBufferLastAddStr = '&T1_scopeConstsPC[{}]->pTraceBuffer[{}]'.format(index, value_pTraceBufferLastIdx)
        rd_pTraceBufferLast = dbgCtrl.evaluate(ic.IConnectDebug.fRealTime, traceBufferLastAddStr)
        value_pTraceBufferLast = "0x%0.8X" %(rd_pTraceBufferLast.getAddress().m_aAddress)
        traceBuffersize = int((int(value_pTraceBufferLast, 16) - int(value_pTraceBuffer, 16)) / 4 + 1)
        #print (traceBuffersize)

        #sid
        curentSID = value_sid + index
        str_sid = str(curentSID)
        T1_traceBufferCoreX.write('B::v.v_%h_T1_sid\n')
        T1_traceBufferCoreX.write('  T1_sid = 0x' + str_sid + '\n')

        #get tracebufferWr_
        T1_traceBufferCoreX.write('B::v.v_T1_scopeGlobals' + str(index) + '.pTraceBufferWr_\n')
        traceBufferWrIdxStr = 'T1_scopeGlobals' + str(index) + '.tB._.wrIdx'
        rd_pTraceBufferWrIdx = dbgCtrl.evaluate(ic.IConnectDebug.fRealTime, traceBufferWrIdxStr)
        value_pTraceBufferWrIdx = rd_pTraceBufferWrIdx.getLong() & 0xFFFF
        traceBufferWrAddStr = '&T1_scopeConstsPC[{}]->pTraceBuffer[{}]'.format(index, value_pTraceBufferWrIdx)
        rd_pTraceBufferWr = dbgCtrl.evaluate(ic.IConnectDebug.fRealTime, traceBufferWrAddStr)
        value_pTraceBufferWr = "0x%0.8X" %(rd_pTraceBufferWr.getAddress().m_aAddress)
        T1_traceBufferCoreX.write('  T1_scopeGlobals' + str(index) + '.pTraceBufferWr_ = %.10s\n' %value_pTraceBufferWr)

        #traceBuffer[0]
        T1_traceBufferCoreX.write('B::v.v_&T1_traceBuffer' + str(index) + '[0]\n')
        T1_traceBufferAddStr = '&T1_scopeConstsPC[{}]->pTraceBuffer[0]'.format(index)
        rd_T1_traceBufferX_addr = dbgCtrl.getExpressionAddress(T1_traceBufferAddStr)
        addr_T1_traceBufferX = "0x%0.8X" %(rd_T1_traceBufferX_addr.getAddress())
        T1_traceBufferCoreX.write('  &T1_traceBuffer' + str(index) + '[0] = %.10s\n' %addr_T1_traceBufferX)

        #traceBuffer[1]
        T1_traceBufferCoreX.write('B::v.v_&T1_traceBuffer' + str(index) + '[1]\n')
        T1_traceBuffer1AddStr = '&T1_scopeConstsPC[{}]->pTraceBuffer[1]'.format(index)
        rd_T1_traceBufferX_1_addr = dbgCtrl.getExpressionAddress(T1_traceBuffer1AddStr)
        addr_T1_traceBufferX_1 = "0x%0.8X" %(rd_T1_traceBufferX_1_addr.getAddress())
        T1_traceBufferCoreX.write('  &T1_traceBuffer' + str(index) + '[1] = %.10s\n' %addr_T1_traceBufferX_1)

        #tracebufferLast
        T1_traceBufferCoreX.write('B::v.v_T1_scopeGlobals' + str(index) + '.pTraceBufferLast_\n')
        T1_traceBufferCoreX.write('  T1_scopeGlobals' + str(index) + '.pTraceBufferLast_ = %.10s\n' %value_pTraceBufferLast)

        #tracebuffer begin
        T1_traceBufferCoreX.write('B::v.v_%h_%fixed_%tree.open_T1_traceBuffer' + str(index) + '\n')
        T1_traceBufferCoreX.write('  T1_traceBuffer' + str(index) + ' = (\n')
        for i in range(0,traceBuffersize,1):

            Buf0 = dbgCtrl.evaluate(ic.IConnectDebug.fRealTime, 'T1_scopeConstsPC[{}]->pTraceBuffer[{}]'.format(index, i))
            Buf0_addr = "0x%0.8X" %(Buf0.getLong())


            if i < (traceBuffersize-1):

                T1_traceBufferCoreX.flush()
                T1_traceBufferCoreX.write('    %.10s,\n' %Buf0_addr)
            else:

                T1_traceBufferCoreX.flush()
                T1_traceBufferCoreX.write('    %.10s)' %Buf0_addr)
                T1_traceBufferCoreX.close()

    print('T1_winIDEA.py: FINISHED TRACE DOWNLOAD')
    input('Press Enter to quit...')

except Exception as ex:
    print(ex)

#input('Press Enter to quit...')
