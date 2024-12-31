import sys
from USBMultimeter import *

filePath = r'c:\MKS\AUDI_MCC\Phase_01\View_Test\Tools\CANoe\Config\ECS_AUDI_VERIF\Includes\HW_Modules\DMM\sMeasureFile.txt'

_sMultimeter = 'USB::0x164E::0x0DAD::TW00034249::INSTR'

sDMM = DMM(_sMultimeter)

try:
        if sys.argv[1] == 'sMeasureCurrent':
                sMeasureCurrent = sDMM.SingleReadCurrentDC()
                f = open(filePath, 'w+')
                f.write(sMeasureCurrent)
                f.close()
        elif sys.argv[1] == 'sMeasureVoltage':
                sMeasureVoltage = sDMM.SingleReadVoltageDC()
                f = open(filePath, 'w+')
                f.write(sMeasureVoltage)
                f.close()
        elif sys.argv[1] == 'sMeasureCurrentAC':
                sMeasureCurrentAC = sDMM.SingleReadCurrentAC()
                f = open(filePath, 'w+')
                f.write(sMeasureCurrentAC)
                f.close()
        elif sys.argv[1] == 'sMeasureVoltageAC':
                sMeasureVoltageAC = sDMM.SingleReadVoltageAC()
                f = open(filePath, 'w+')
                f.write(sMeasureVoltageAC)
                f.close()
        elif sys.argv[1] == 'sMeasureTemp':
                sMeasureTemp = sDMM.SingleReadTemperature()
                f = open(filePath, 'w+')
                f.write(sMeasureTemp)
                f.close()
        elif sys.argv[1] == 'sMeasureTemperatureTC':
                sMeasureTemperatureTC = sDMM.ReadMultipleThermocouples()
                f = open(filePath, 'w+')
                f.write(sMeasureTemperatureTC)
                f.close()
        elif sys.argv[1]== 'sGetTerminalsPos':
                sGetTerminalPos = sDMM.ReadTerminalPos()
                f = open(filePath, 'w+')
                f.write(sGetTerminalPos)
                f.close()
        else:
                f = open(filePath, 'w+')
                f.write('Wrong argument given!')
                f.close()
except:
        f = open(filePath, 'w+')
        f.write('Error occurred!')
        f.close()
