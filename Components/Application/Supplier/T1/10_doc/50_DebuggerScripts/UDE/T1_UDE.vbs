''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'
'   File:           T1_UDE.vbs
'
'   Description:    Script to read T1 trace buffer and write it to text files, for
'                   using with the PLS UDE.
'                   Tested with UDE V5.2.
'
'   $Author: Razvan Badiu (razvan.badiu) $
'
'   $Revision: 1.1 $
'
'   Copyright:      GLIWA embedded systems GmbH & Co. KG
'                   Weilheim i.OB.
'                   All rights reserved
'
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Option Explicit

' The Starter Kit only supports debugging 3 cores, but the KIT_A2G_TC387_3V3_TFT has
' four cores, therefore setting usePerCoreDebugger to False will cause the script to
' use the core 0 debugger to read our the traces for all cores and setting it to True
' will use the respective cores debugger
Private Const usePerCoreDebugger = False

Public Sub readT1TraceBufferCoreAll()
    Dim workspacePath, workspaceFolder, traceFolder, fso
    workspacePath = Workspace.WorkspacePath
    Set fso = CreateObject("Scripting.FileSystemObject")
    workspaceFolder = fso.GetParentFolderName(workspacePath)

    Dim currentDateAndTime, currentDate, currentTime
    currentDateAndTime = Now()
    currentDate = Year(currentDateAndTime) & LPad(Month(currentDateAndTime), "0", 2) & LPad(Day(currentDateAndTime), "0", 2)
    currentTime = LPad(Hour(currentDateAndTime), "0", 2) & LPad(Minute(currentDateAndTime), "0", 2) & LPad(Second(currentDateAndTime), "0", 2)

    traceFolder = workspaceFolder & "\Traces_" & currentDate
    If Not(fso.FolderExists(traceFolder)) Then
        fso.CreateFolder(traceFolder)
    End If

    ReDim coreDebuggerObjects(0)
    Set coreDebuggerObjects(0) = Workspace.CoreDebugger(0)

    Dim T1_nOfCores
    T1_nOfCores = coreDebuggerObjects(0).ReadVariable("T1_nOfCores")

    ' Sanity check
    If IsEmpty(T1_nOfCores) Then
        Workspace.MessageLog.LogError("Failed reading T1_nOfCores")
        Exit Sub
    End If

    Dim coreDebuggerCount
    coreDebuggerCount = Workspace.CoreDebuggerCnt

    ' Sanity check
    If usePerCoreDebugger AND T1_nOfCores <> coreDebuggerCount Then
        Workspace.MessageLog.LogError("T1_nOfCores == " & CStr(T1_nOfCores) & ", but only " & CStr(coreDebuggerCount) & " Core Debuggers")
        Exit Sub
    End If

    ReDim Preserve coreDebuggerObjects(T1_nOfCores - 1)

    Dim coreIdx
    For coreIdx = 1 To T1_nOfCores - 1
        If usePerCoreDebugger Then
            Set coreDebuggerObjects(coreIdx) = Workspace.CoreDebugger(coreIdx)
        Else
            Set coreDebuggerObjects(coreIdx) = Workspace.CoreDebugger(0)
        End If
    Next

    Dim T1_sid, T1_bid, T1_scopeRevision
    T1_sid = coreDebuggerObjects(0).ReadVariable("T1_sid")
    T1_bid = coreDebuggerObjects(0).ReadVariable("T1_bid")
    T1_scopeRevision = (CInt(coreDebuggerObjects(0).ReadVariable("((unsigned char *)&T1_scopePluginStruct)[1]")) - 3) * 65536
    ' Not all versions of the UDE will succeed in reading T1_scopePluginStruct,
    ' T1_scopeRevision will be -3 * 65536 if reading fails
    If T1_scopeRevision = (-3 * 65536) Then
        Workspace.MessageLog.LogWarning("Failed reading T1_scopePluginStruct")
    Else
        T1_scopeRevision = T1_scopeRevision + CInt(coreDebuggerObjects(0).ReadVariable("((unsigned char *)&T1_scopePluginStruct)[2]")) * 256
        T1_scopeRevision = T1_scopeRevision + CInt(coreDebuggerObjects(0).ReadVariable("((unsigned char *)&T1_scopePluginStruct)[3]"))
    End If

    If Not usePerCoreDebugger Then
        Dim stateGlobal
        stateGlobal = Workspace.CheckAllCoresHalted( True )
        If Not stateGlobal Then
             Workspace.MessageLog.LogWarning("Not all cores are in halted state, captured T1 trace buffer might be inconsistent")
        End If
    End If

    For coreIdx = 0 To T1_nOfCores - 1
        Dim currentCoreId, filename, currentSid, filePath
        currentCoreId = coreDebuggerObjects(coreIdx).ReadVariable("T1_scopeConstsPC[" & CStr(coreIdx) & "]->coreId")
        currentSid = T1_sid + currentCoreId
        filePath = traceFolder & "\" & currentDate & "_" & currentTime & "_ScopeTrace_Core" & CStr(currentCoreId) & "_sid" & CStr(currentSid) & ".txt"

        Workspace.MessageLog.LogMessage("Core " & CStr(currentCoreId) & " writing T1 trace buffer to: " & filePath)

        If usePerCoreDebugger Then
            Dim stateSingle
            stateSingle = coreDebuggerObjects(coreIdx).GetState()
            If 0 <> stateSingle Then
                 Workspace.MessageLog.LogWarning("Core " & CStr(currentCoreId) & " is not in halted state, captured T1 trace buffer might be inconsistent")
            End If
        End If

        Dim bufferEntriesMinusOne, pTraceBuffer, pTraceBufferLast, wrIdx, pTraceBufferWr
        bufferEntriesMinusOne = CLng(coreDebuggerObjects(coreIdx).ReadVariable("T1_scopeConstsPC[" & CStr(coreIdx) & "]->bufferEntriesMinusOne"))
        pTraceBuffer = coreDebuggerObjects(coreIdx).ReadVariable("T1_scopeConstsPC[" & CStr(coreIdx) & "]->pTraceBuffer")
        pTraceBufferLast = coreDebuggerObjects(coreIdx).ReadVariable("&(T1_scopeConstsPC[" & CStr(coreIdx) & "]->pTraceBuffer[" & CStr(bufferEntriesMinusOne) & "])")
        wrIdx = coreDebuggerObjects(coreIdx).ReadVariable("T1_scopeConstsPC[" & CStr(coreIdx) & "]->_.pScopeGlobals->tB._.wrIdx")
        pTraceBufferWr = coreDebuggerObjects(coreIdx).ReadVariable("&(T1_scopeConstsPC[" & CStr(coreIdx) & "]->pTraceBuffer[" & CStr(wrIdx) & "])")

        Dim f
        Set f = fso.CreateTextFile(filePath, False, False)
        f.WriteLine("B::v.v_T1_bid")
        f.WriteLine("  T1_bid = " & CStr(T1_bid))

        f.WriteLine("B::v.v_%h_T1_sid+" & CStr(currentCoreId))
        f.WriteLine("  T1_sid+" & CStr(currentCoreId) & " = 0x" & Hex(currentSid))

        If T1_scopeRevision > 0 Then
            f.WriteLine("B::v.v_%d_(((((unsigned_char_*)&T1_scopePluginStruct)[1]_-_3)_*_65536)_+_(((unsigned_char_*)&T1_scopePluginStruct)[2]_*_256)_+_((unsigned_char_*)&T1_scopePluginStruct)[3])")
            f.WriteLine("  (((((unsigned char *)&T1_scopePluginStruct)[1] - 3) * 65536) + (((unsigned char *)&T1_scopePluginStruct)[2] * 256) + ((unsigned char *)&T1_scopePluginStruct)[3]) = " & CStr(T1_scopeRevision))
        End If

        f.WriteLine("B::v.v_T1_scopeGlobalsPC[" & CStr(currentCoreId) & "]->pTraceBufferWr_")
        f.WriteLine("  T1_scopeGlobalsPC[" & CStr(currentCoreId) & "]->pTraceBufferWr_ = 0x" & LPad(Hex(pTraceBufferWr), "0", 8))

        f.WriteLine("B::v.v_&T1_traceBuffer" & CStr(currentCoreId) & "[0]")
        f.WriteLine("  &T1_traceBuffer" & CStr(currentCoreId) & "[0] = 0x" & LPad(Hex(pTraceBuffer), "0", 8))

        f.WriteLine("B::v.v_&T1_traceBuffer" & CStr(currentCoreId) & "[1]")
        f.WriteLine("  &T1_traceBuffer" & CStr(currentCoreId) & "[1] = 0x" & LPad(Hex(pTraceBuffer + 4), "0", 8))

        f.WriteLine("B::v.v_T1_scopeGlobalsPC[" & CStr(currentCoreId) & "]->pTraceBufferLast_")
        f.WriteLine("  T1_scopeGlobalsPC[" & CStr(currentCoreId) & "]->pTraceBufferLast_ = 0x" & LPad(Hex(pTraceBufferLast), "0", 8))

        f.WriteLine("B::v.v_%hex_%fixed_%tree.open_T1_traceBuffer" & CStr(currentCoreId))
        f.WriteLine("  T1_traceBuffer" & CStr(currentCoreId) & " = (")

        Dim arrayObj, arrayReadSuccess
        Set arrayObj = coreDebuggerObjects(coreIdx).CreateArrayObj(bufferEntriesMinusOne+1, 32)
        arrayReadSuccess = coreDebuggerObjects(coreIdx).ReadArray(CLng(pTraceBuffer), arrayObj)
        If arrayReadSuccess Then
            Dim currentTbValue, arrayIdx
            For arrayIdx = 0 To bufferEntriesMinusOne-1
                currentTbValue = arrayObj.Item(arrayIdx)
                f.WriteLine("    0x" & LPad(Hex(currentTbValue), "0", 8) & ",")
            Next
            currentTbValue = arrayObj.Item(bufferEntriesMinusOne)
            f.WriteLine("    0x" & LPad(Hex(currentTbValue), "0", 8) & ")")
        End If
        f.Close

         Workspace.MessageLog.LogSuccess("Core " & CStr(currentCoreId) & " finished reading T1 trace buffer")
    Next
End Sub

Private Function LPad (str, pad, length)
    LPad = String(length - Len(str), pad) & str
End Function
