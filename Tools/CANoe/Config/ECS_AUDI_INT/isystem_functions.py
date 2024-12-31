###########################
##  PYTHON & CAPL TEST  ###
###########################
from __future__ import print_function
from file import Parser
import isystem.connect as ic
import time

# GLOBALS #
newCommandFlag = False
iSYSInit = False
memory_accessFlag = ic.IConnectDebug.fRealTime
path = "c:\\Projects\\eCS_Platform_Git\\Tools\\Canoe_int\\Config\\"
fin_name = "isystem_commands.INI"
fin_path = path + fin_name
fout_name = "isystem_response.INI"
fout_path = path + fout_name
parse = Parser(fin_path, fout_path)


xCManager = ic.ConnectionMgr()
xCManager.connectMRU('')
xDebug = ic.CDebugFacade(xCManager)
xLoaderController = ic.CLoaderController(xCManager)
xWorkSpaceController = ic.CWorkspaceController(xCManager)
xCBreakPointController = ic.CBreakpointController(xCManager)
xCExecutionController = ic.CExecutionController(xCManager)
xCDataController = ic.CDataController(xCManager)
xCAddressController = ic.CAddressController(xCManager)


# Debugger initializations #

def ISYSTEM_INIT():
    """
    Initialize all winIDEA objects used by the API
    :return:
    """
    if xCManager and xDebug and xWorkSpaceController and xLoaderController:
        iSYSInit = True
    else:
        iSYSInit = False
    return iSYSInit


# Functions used in CANOE to control the debugger. Input will be the .INI file #
def debugger_run():
    """
    This function runs the target.
    :return: true if successful
    """
    ret = False
    if ISYSTEM_INIT() == True:
        result = xDebug.run()
        ret = True
    return ret


def debugger_reset():
    """
    This function resets the target.
    :return: true if successful
    """
    ret = False
    if ISYSTEM_INIT() == True:
        result = xDebug.reset()
        ret = True
    return ret


def debugger_download():
    """
    This function downloads the files defined in winIDEA on the target.
    :return: true if successful
    """
    ret = False
    if ISYSTEM_INIT() == True:
        result = xDebug.download()
        ret = True
    return ret


def debugger_stop():
    """
    This function stops the target.
    :return: true if successful
    """
    ret = False
    if ISYSTEM_INIT() == True:
        xDebug.stop()
        ret = True
    return ret


def debugger_step():
    """
    This function steps one statement in the source code.
    :return: true if successful
    """
    ret = False
    if ISYSTEM_INIT() == True:
        xDebug.stepHigh()
        ret = True
    return ret


def debugger_stepOver():
    """
    This function steps one statement in the source code, does not enter functions.
    :return: true if successful
    """
    ret = False
    if ISYSTEM_INIT() == True:
        xDebug.stepOverHigh()
        ret = True
    return ret


def debugger_setBreakPointAtLine(lineNumber, sfileName):
    ret = False
    if iSYSInit == False:
        try:
            xCBreakPointController.setBP(lineNumber, sfileName)
            ret = True
        except:
            ret = "Could not set breakpoint at line."
    return ret


def debugger_getAddress(lineNumber, sfileName):
    address = xCAddressController.getAddressOfSourceLine(sfileName, lineNumber)
    return address


def debugger_setRelativeFunctionBpAtLine(functionName, lineOffset):
    ret = False
    if ISYSTEM_INIT() == True:
        ret_add_val = xDebug.getFunctionAddress(functionName)
        if ret_add_val:
            xCLineLocation = xCAddressController.getSourceLineAtAddress(ret_add_val.getAddress())
            functionLineNumber = xCLineLocation.getLineNumber()
            sourceFile = xCLineLocation.getFileName()
            if functionLineNumber and sourceFile:
                abs_line_num = functionLineNumber + int(lineOffset)
                bp_status = debugger_setBreakPointAtLine(abs_line_num, sourceFile)
                if bp_status == True:
                    ret = True
                else:
                    ret = "The breakpoint was not set to following line: " + f"{abs_line_num}" + " (function line: " + f"{functionLineNumber}" + " offset: " + f"{lineOffset}" + ")"
            else:
                ret = "Invalid line number or file name. LN: " + f"{functionLineNumber}" + " FN: " + f"{sourceFile}"
        else:
            ret = "The function address can`t be read. Please check function name!"
    else:
        ret = "The iSYSTEM class is not initialized"
    return ret


def debugger_readVariable(variableType, variableName, offset):
    ret = False
    if iSYSInit == False:
        xCMemAddress = xCAddressController.getVariableAddress(f"{variableName}")
        varMemArea = xCMemAddress.getMemArea()
        varAddress = xCMemAddress.getAddress()
        vType = ic.SType()
        if variableType == "uint8":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 8
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress + (1 * int(offset)), vType)
            ret = xCValueType.getLong()
        elif variableType == "sint8":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 8
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress + (1 * int(offset)), vType)
            ret = xCValueType.getInt()
        elif variableType == "uint16":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 16
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress + (2 * int(offset)), vType)
            ret = xCValueType.getLong()
        elif variableType == "sint16":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 16
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress + (2 * int(offset)), vType)
            ret = xCValueType.getInt()
        elif variableType == "uint32":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 32
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress + (4 * int(offset)), vType)
            ret = xCValueType.getLong()
        elif variableType == "sint32":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 32
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress + (4 * int(offset)), vType)
            ret = xCValueType.getInt()
        elif variableType == "uint64":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 64
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress + (8 * int(offset)), vType)
            ret = xCValueType.getLong()
        elif variableType == "sint64":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 64
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress + (8 * int(offset)), vType)
            ret = xCValueType.getInt()
        elif variableType == "float":
            vType.m_byType = ic.SType.tFloat
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress, vType)
            ret = xCValueType.getFloat()
        elif variableType == "compound":
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress, vType)
            ret = xCValueType.getResult()
        elif variableType == "address":
            vType.m_byType = ic.SType.tAddress
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress, vType)
            ret = xCValueType.getResult()
        else:
            ret = "Incorrect type. Supported types are: uint8/int8, uint16/int16, uint32/int32,float ,address, compound"
    else:
        ret = "The iSYSTEM class is not initialized"
    return ret


def debugger_writeVariable(variableType, variableName, value, offset):
    ret = False
    if iSYSInit == False:
        xCMemAddress = xCAddressController.getVariableAddress(f"{variableName}")
        varMemArea = xCMemAddress.getMemArea()
        varAddress = xCMemAddress.getAddress()
        vType = ic.SType()
        if variableType == "uint8":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 8
            cValue = ic.CValueType(vType, value)
            xDebug.writeValue(memory_accessFlag, varMemArea, varAddress + (1 * int(offset)), cValue)
            ret = "true"
        elif variableType == "sint8":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 8
            cValue = ic.CValueType(vType, value)
            xDebug.writeValue(memory_accessFlag, varMemArea, varAddress + (1 * int(offset)), cValue)
            ret = "true"
        elif variableType == "uint16":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 16
            cValue = ic.CValueType(vType, value)
            xDebug.writeValue(memory_accessFlag, varMemArea, varAddress + (2 * int(offset)), cValue)
            ret = "true"
        elif variableType == "sint16":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 16
            cValue = ic.CValueType(vType, value)
            xDebug.writeValue(memory_accessFlag, varMemArea, varAddress + (2 * int(offset)), cValue)
            ret = "true"
        elif variableType == "uint32":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 32
            cValue = ic.CValueType(vType, value)
            xDebug.writeValue(memory_accessFlag, varMemArea, varAddress + (4 * int(offset)), cValue)
            ret = "true"
        elif variableType == "sint32":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 32
            cValue = ic.CValueType(vType, value)
            xDebug.writeValue(memory_accessFlag, varMemArea, varAddress + (4 * int(offset)), cValue)
            ret = "true"
        else:
            ret = "Incorrect type. Supported types are: uint8/int8, uint16/int16, uint32/int32"
    else:
        ret = "The iSYSTEM class is not initialized"
    return ret


def debugger_deleteAllBreakpoints():
    ret = False
    if iSYSInit == False:
        res = xCBreakPointController.deleteAll()
        if res == 1:
            ret = "No breakpoints were deleted because none existed."
        elif res == 0:
            ret = True
    else:
        ret = "The iSYSTEM class is not initialized"
    return ret


def debugger_deleteFunctionBreakpoint(functionName):
    print(functionName)
    ret = False
    if iSYSInit == False:
        res = xCBreakPointController.deleteBP(f"{functionName}")
        # res = xCBreakPointController.deleteBP("atm_PlayCyclicTests")
        if res == 1:
            ret = "No breakpoints were deleted at this symbol " + functionName
        elif res == 0:
            ret = True
    else:
        ret = "The iSYSTEM class is not initialized "
    return ret


debugger_commands = {
    'run': [debugger_run, []],
    'reset': [debugger_reset, []],
    'download': [debugger_download, []],
    'stop': [debugger_stop, []],
    'step': [debugger_step, []],
    'stepOver': [debugger_stepOver, []],
    'setBreakPointAtLine': [debugger_setBreakPointAtLine, []],
    'getAddress': [debugger_getAddress, []],
    'setRelativeFunctionBpAtLine': [debugger_setRelativeFunctionBpAtLine, []],
    'readVariable': [debugger_readVariable, []],
    'writeVariable': [debugger_writeVariable, []],
    'deleteAllBreakpoints': [debugger_deleteAllBreakpoints, []],
    'deleteFunctionBreakpoint': [debugger_deleteFunctionBreakpoint, []]
}

parse.debugger_instructions(debugger_commands)
