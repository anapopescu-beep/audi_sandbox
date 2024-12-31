######################################################################################
#
#   File:           T1_UDE.py
#
#   Description:    Script to read T1 trace buffer and write it to text files, for
#                   using with the PLS UDE.
#                   Tested with UDE V5.2.
#
#   $Author: Razvan Badiu (razvan.badiu) $
#
#   $Revision: 1.2 $
#
#   Copyright:      GLIWA embedded systems GmbH & Co. KG
#                   Weilheim i.OB.
#                   All rights reserved
#
######################################################################################

import win32com.client
from datetime import datetime

USE_PER_CORE_DEBUGGER = False

now = datetime.now().strftime('%Y%m%d_%H_%M_%S')

ProgId = "UDERunningInstanceManager"
RunningInstanceManager = win32com.client.Dispatch(ProgId)

# Now we can access the running UDE instance:
if 0 == RunningInstanceManager.InstanceCount:
    print("ERROR: no running UDE instances found !")
    exit()
Ude = RunningInstanceManager.GetInstance(0)  # IUDEApplication
Workspace = Ude.Workspace  # IUDEWorkspace

coreDebuggerObjects = list()
coreDebuggerObjects.append(Workspace.GetCoreDebugger(0))

T1_nOfCores = coreDebuggerObjects[0].ReadVariable("T1_nOfCores")

# Sanity check
if not T1_nOfCores:
    print("Error: Failed reading T1_nOfCores")
    exit()

coreDebuggerCount = Workspace.CoreDebuggerCnt

#Sanity check
if USE_PER_CORE_DEBUGGER and T1_nOfCores > coreDebuggerCount:
    print("Error: T1_nOfCores == {}, but only {} Core Debuggers".format(T1_nOfCores, coreDebuggerCount))
    exit()

for coreIdx in range(1, coreDebuggerCount):
    if USE_PER_CORE_DEBUGGER:
        coreDebuggerObjects.append(Workspace.GetCoreDebugger(coreIdx))  # IUDEDebuggerInterface
    else:
        coreDebuggerObjects.append(Workspace.GetCoreDebugger(0))  # IUDEDebuggerInterface

T1_sid = coreDebuggerObjects[0].ReadVariable("T1_sid")
T1_bid = coreDebuggerObjects[0].ReadVariable("T1_bid")
T1_scopeRevision = (coreDebuggerObjects[0].ReadVariable("((unsigned char *)&T1_scopePluginStruct)[1]") - 3) * 65536
# Not all versions of the UDE will succeed in reading T1_scopePluginStruct,
# T1_scopeRevision will be -3 * 65536 if reading fails
if T1_scopeRevision == -3 * 65536:
    print("Warning: Failed reading T1_scopePluginStruct")
else:
    T1_scopeRevision += coreDebuggerObjects[0].ReadVariable("((unsigned char *)&T1_scopePluginStruct)[2]") * 256
    T1_scopeRevision += coreDebuggerObjects[0].ReadVariable("((unsigned char *)&T1_scopePluginStruct)[3]")

if not USE_PER_CORE_DEBUGGER:
    stateGlobal = Workspace.CheckAllCoresHalted(True)
    if not stateGlobal:
        print("Warning: Not all cores are in halted state, captured T1 trace buffer might be inconsistent")


for coreIdx in range(T1_nOfCores):
    currentCoreId = coreDebuggerObjects[coreIdx].ReadVariable("T1_scopeConstsPC[{}]->coreId".format(coreIdx))
    currentSid = T1_sid + currentCoreId
    filename = "T1.scopeDebugger_{}_core{}.txt".format(now, currentCoreId)
    print("Core {} -> {}".format(currentCoreId, filename))

    if USE_PER_CORE_DEBUGGER:
        state = coreDebuggerObjects[coreIdx].GetState()
        if state != 0:
            print("Warning: Core {} is not in halted state, captured T1 trace buffer might be inconsistent".format(currentCoreId))

    bufferEntriesMinusOne = coreDebuggerObjects[coreIdx].ReadVariable("T1_scopeConstsPC[{}]->bufferEntriesMinusOne".format(coreIdx))
    pTraceBuffer = coreDebuggerObjects[coreIdx].ReadVariable("T1_scopeConstsPC[{}]->pTraceBuffer".format(coreIdx))
    pTraceBufferLast = coreDebuggerObjects[coreIdx].ReadVariable("&(T1_scopeConstsPC[{}]->pTraceBuffer[{}])".format(coreIdx, bufferEntriesMinusOne))
    wrIdx = coreDebuggerObjects[coreIdx].ReadVariable("T1_scopeConstsPC[{}]->_.pScopeGlobals->tB._.wrIdx".format(coreIdx))
    pTraceBufferWr = coreDebuggerObjects[coreIdx].ReadVariable("&(T1_scopeConstsPC[{}]->pTraceBuffer[{}])".format(coreIdx, wrIdx))

    fh = open(
        filename,
        mode="xt",  # open for exclusive creation, text mode
        buffering=8192,
        encoding="ascii"  # ensure that only basic ASCII characters are used
    )

    fh.write("B::v.v_T1_bid\n")
    fh.write("  T1_bid = {}\n".format(T1_bid))

    fh.write("B::v.v_%h_T1_sid+{}\n".format(currentCoreId))
    fh.write("  T1_sid+{} = 0x{:X}\n".format(currentCoreId, currentSid))

    if T1_scopeRevision > 0:
        fh.write("B::v.v_%d_(((((unsigned_char_*)&T1_scopePluginStruct)[1]_-_3)_*_65536)_+_(((unsigned_char_*)&T1_scopePluginStruct)[2]_*_256)_+_((unsigned_char_*)&T1_scopePluginStruct)[3])\n")
        fh.write("  (((((unsigned char *)&T1_scopePluginStruct)[1] - 3) * 65536) + (((unsigned char *)&T1_scopePluginStruct)[2] * 256) + ((unsigned char *)&T1_scopePluginStruct)[3]) = {}\n".format(T1_scopeRevision))

    fh.write("B::v.v_T1_scopeGlobalsPC[{}]->pTraceBufferWr_\n".format(currentCoreId))
    fh.write("  T1_scopeGlobalsPC[{}]->pTraceBufferWr_ = 0x{:08X}\n".format(currentCoreId, pTraceBufferWr))

    fh.write("B::v.v_&T1_traceBuffer{}[0]\n".format(currentCoreId))
    fh.write("  &T1_traceBuffer{}[0] = 0x{:08X}\n".format(currentCoreId, pTraceBuffer))

    fh.write("B::v.v_&T1_traceBuffer{}[1]\n".format(currentCoreId))
    fh.write("  &T1_traceBuffer{}[1] = 0x{:08X}\n".format(currentCoreId, pTraceBuffer + 4))

    fh.write("B::v.v_T1_scopeGlobalsPC[{}]->pTraceBufferLast_\n".format(currentCoreId))
    fh.write("  T1_scopeGlobalsPC[{}]->pTraceBufferLast_ = 0x{:08X}\n".format(currentCoreId,pTraceBufferLast))

    fh.write("B::v.v_%hex_%fixed_%tree.open_T1_traceBuffer{}\n".format(currentCoreId))
    fh.write("  T1_traceBuffer{} = (\n".format(currentCoreId))

    arrayObj = coreDebuggerObjects[coreIdx].CreateArrayObj(  # DIUDEArray
        bufferEntriesMinusOne+1,  # Length
        32  # Size of one entry
    )
    arrayReadSuccess = coreDebuggerObjects[coreIdx].ReadArray(pTraceBuffer, arrayObj)
    if arrayReadSuccess:
        listOfTbEntries = [arrayObj[x] for x in range(bufferEntriesMinusOne + 1)]
        lines = ",\n".join(
            list(map(lambda x: "    0x{:08X}".format(x), listOfTbEntries))
        )
        fh.write(lines + ")\n")
    fh.close()
exit()
