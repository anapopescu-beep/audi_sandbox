from ctypes import *
import os
import time
import random
file_path = os.path.abspath(os.path.dirname(__file__)) + "\\"
print(file_path)
#mydll = cdll.LoadLibrary('./libSimulyzer.so')
mydll = cdll.LoadLibrary('C:/MKS/Autoliv_PythonTest/Simulyzer_64.dll')
print(mydll)
sekRetVal = mydll.StartLogging("simu.log".encode(),c_int(0x1A),c_int(0x3))
mydll.InitializeSystem() # Initialize Simulyzer API System
print("StartLogging return code: " + str(sekRetVal))
devhnd = c_void_p() #device handle
sekRetVal = mydll.GetSpiDeviceBySerialNumber(271,byref(devhnd))
#sekRetVal = mydll.GetSpiDevice(0,byref(devhnd))
if sekRetVal != 0: #if GetSpiDevice fails
    print ("GetSpiDevice return code: " + str(sekRetVal))
    os._exit(-1)

sekRetVal = mydll.OpenSimulyzer(devhnd)
if sekRetVal != 0: #if OpenSimulyzer fails
    print ("OpenSimulyzer return code: " + str(sekRetVal))
    os._exit(-1)
    
sekRetVal = mydll.SetTempDirectoryPath(devhnd, file_path.encode())    
sekRetVal = mydll.SetMaxStorageValues(devhnd, 0x10000000, 0x10000000, 0)    

sekRetVal = mydll.LoadConfiguration(devhnd, "Autoliv_IAM20685_fault_free.spf".encode())
if sekRetVal != 0: #if LoadConfiguration fails
    print ("LoadConfiguration return code: " + str(sekRetVal))
    os._exit(-1)
    
sekRetVal = mydll.AnalogSampleEnable(devhnd, 0 )    
if sekRetVal != 0: #if AnalogSampleEnable fails
    print ("AnalogSampleEnable return code: " + str(sekRetVal))
    os._exit(-1)

sekRetVal = mydll.StartSensorSampling(devhnd, 0x40000, 0x40000, 0, 0, 0)
if sekRetVal != 0: #if StartSensorSampling fails
    print ("StartSensorSampling return code: " + str(sekRetVal))
    os._exit(-1)	
	
'''simulate acceleration values via SPI'''
# for index in range(50):	
	# time.sleep(5.0)
	# sekRetVal = mydll.SPI_WriteSimulationSensorRegister(devhnd, 0, 0x6, 0x1F00) #reg Z axis writen to ~0.9g// simulating a tilt of ~ 25degrees on X axis
	# sekRetVal = mydll.SPI_WriteSimulationSensorRegister(devhnd, 0, 0x5, 0x0)    #reg Y axis writen to 0g 
	# sekRetVal = mydll.SPI_WriteSimulationSensorRegister(devhnd, 0, 0x4, 0x0CAC) #reg X axis writen to ~0.4g 		 

'''simulate faults via SPI'''
sekRetVal = mydll.SPI_WriteSimulationSensorRegister(devhnd, 0, 0x12, 0x3002) #fault generated. 3 flags set to bit registry 0x12 for vrefshieldz_alarm, vrefshieldxy_alarm, accel_cp_alarm

time.sleep(20)

sekRetVal = mydll.SPI_WriteSimulationSensorRegister(devhnd, 0, 0x12, 0x0) #dequalify all flags

time.sleep(3)

sekRetVal = mydll.StopSensorSampling(devhnd)
if sekRetVal != 0: #if StopSensorSampling fails
    print ("StopSensorSampling return code: " + str(sekRetVal))
    os._exit(-1)
    
sekRetVal = mydll.StoreProject(devhnd)
if sekRetVal != 0: #if StoreProject fails
    print ("StoreProject return code: " + str(sekRetVal))
    os._exit(-1)
   

    
sekRetVal = mydll.ReleaseSimulyzer(devhnd)
if sekRetVal != 0: #if ReleaseSimulyzer fails
    print ("ReleaseSimulyzer return code: " + str(sekRetVal))
    os._exit(-1)
   
sekRetVal = mydll.DestroySystem() # clean up