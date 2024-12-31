########################################################################################################
#                                       External Function Import                                       #
########################################################################################################
import os
import subprocess
import sys
import xml.etree.ElementTree as ET
from Project_Configuration_for_Python_script import *
from TagXML_for_python_script import Calibration_Tag_Nb_Block, Calibration_Tag_Nb_Variable, Calibration_Tag_Name_of_Block, Calibration_Tag_Address_of_Block, Calibration_Tag_Type_of_Variable, Calibration_Tag_Value, Calibration_Tag_Alias_In_RAM, Calibration_Tag_CKS, Calibration_Tag_NB_Data, Calibration_Tag_Size_of_Block
print("***generate_CalibrationFlash00.py***") 
os.chdir(os.path.dirname(os.path.realpath(__file__)))

########################################################################################################
#                                       Local Function Definition                                      #
########################################################################################################

#################################################################
# Name        : hexadecimal(integer)                            #
# Input       : Integer in range of 32 bit                      #
# Output      : hexa (1 byte)                                   #
# Description : Convert an integer in hexa with byte expression #
#################################################################
def hexadecimal(integer):

    hexa = ''
    if (integer < 16):
        hexa = '0' + hex(integer)[2:].upper()
    elif (integer < 256):
        hexa = hex(integer)[2:].upper()
    elif (integer < 4096):
        hexa = '0' + hex(integer)[2:].upper()
    elif (integer < 62536):
        hexa = hex(integer)[2:].upper()
    elif (integer < 1048576):
        hexa = '0' + hex(integer)[2:].upper()
    elif (integer < 16777216):
        hexa = hex(integer)[2:].upper()
    elif (integer < 268435456):
        hexa = '0' + hex(integer)[2:].upper()
    else:
        hexa = hex(integer)[2:]
    return hexa

#####################################################################################
# Name        : ChecksumComputation(tab)                                             #
# Input       : Array with decimal Variable                                         #
# Output      : Checksum (1 byte)                                                    #
# Description : Compute a the sum of the Variable and make the complement to FF     #
#####################################################################################
def ChecksumComputation(tab):

    CKS = 0
    for i in range(len(tab)):
        CKS = CKS + tab[i]
    return hexadecimal(255-((CKS+len(tab)+1)%256))

    
########################################################################################################
#                                     Constant Variable Definition                                     #
########################################################################################################

# CRC size ( 2 = 16, 4 = 32 bits). The CRC is stored at the end of the block, after the versioning
CRC_Size = 4
# FBL block header size
FBL_BlockHeader_Size = 64
# FBL Presence pattern size
FBL_Pattern_Size = 32
########################################################################################################
#                                             Main Function                                            #
########################################################################################################

Error = [] #Stock the Error if the .S00 file can't be created

#Construction of the first line of the .S00 files 

Name = "EMULATED_EEPROM_STUB"
Name_in_ASCII_tab = [hexadecimal(ord(c)) for c in Name]     #All character of the Name in Hexadecimal Ascii without 0x  "EMU" => ["45","4D","55"]
Name_in_Dec_tab = [ord(c) for c in Name]                    #All character of the Name in Decimal                       "EMU" => [69,77,85]
First_Address = [0,0]                                       #First Adress on 2 byte in decimal
Name_in_ASCII = ''                                          #String for the Name in ASCII
NB_char = len(First_Address) + len(Name_in_ASCII_tab) + 1   #compute the "count" value of S-Record norm 

for i in range(len(First_Address)):
    Name_in_ASCII = Name_in_ASCII + hexadecimal(First_Address[i])

for i in range(len(Name_in_ASCII_tab)):
    Name_in_ASCII = Name_in_ASCII + Name_in_ASCII_tab[i]

firstline = 'S0' + hexadecimal(NB_char) + Name_in_ASCII + ChecksumComputation( First_Address + Name_in_Dec_tab )


#Construction of the last line of the .S00 files

lastline = 'S70500000000FA' #This line is fixed because we use S3 standard of the S-Record, need to be update if 


##Start the Calibration.xml parser

mydoc = ET.parse('../../../../../Components/Application/Autoliv/NVP/Config/NVP_Layout/Calibration.xml')
root = mydoc.getroot()


#Check integrity of Variable

VariableValidity = True
LineConstruction = True
i = 0
for Block in root.iter('Block'):
    i = i + 1

if root[Calibration_Tag_Nb_Block].text == str(i):

    for Block in root.iter('Block'):
        i = 0
        for Variable in Block.iter('Variable'):
            i = i + 1
        if Block[Calibration_Tag_Nb_Variable].text != str(i):
            VariableValidity = False
            Error.append('Nb_Variable calculate : ' + str(i))
            Error.append('Nb_Variable in XML file : ' + Block[Calibration_Tag_Nb_Variable].text)
            Error.append('The number of Variable is not consistency with he number of instantiate Variable, block :' + Block[Calibration_Tag_Name_of_Block].text)
    
else:
    VariableValidity = False
    Error.append('Nb_Block calculate : ' + str(i))
    Error.append('Nb_block in XML file : ' + root[Calibration_Tag_Nb_Block].text)
    Error.append('The number of block is not consistency with he number of instantiate block')

    
#Compute Variable
    
if VariableValidity == True:

    line = []
    #Construct line by line the .S00, each line correspond to one block
    for Block in root.iter('Block'):
        
        Variable_in_hexa = "" #the Variable in string and in little endian except for the address
        Variable_in_deci = [] #Each word of the Variable use to compute the Checksum
        
        #Start by the address
        Block_address = Block[Calibration_Tag_Address_of_Block].text
        for i in range(int(len(Block_address)/2)):
            Variable_in_hexa = Variable_in_hexa + Block_address[(2*i):(2*i+2)]
            Variable_in_deci.append( int( Block_address[(2*i):(2*i+2)], 16))

        #Import and compute each Variable, expression in Little Endian
        for Variable in Block.iter('Variable'):
            for Data in Variable.iter('Data'):
                if Variable[Calibration_Tag_Type_of_Variable].text[1:] == 'int8':
                    Variable_in_hexa = Variable_in_hexa + Data[Calibration_Tag_Value].text
                    Variable_in_deci.append( int( Data[Calibration_Tag_Value].text, 16))
                elif Variable[Calibration_Tag_Type_of_Variable].text[1:] == 'int16':
                    Variable_in_hexa = Variable_in_hexa + (Data[Calibration_Tag_Value].text)[2:4]
                    Variable_in_deci.append( int( ((Data[Calibration_Tag_Value]).text)[2:4], 16))
                    Variable_in_hexa = Variable_in_hexa + (Data[Calibration_Tag_Value].text)[0:2]
                    Variable_in_deci.append( int( (Data[Calibration_Tag_Value].text)[0:2], 16))
                elif Variable[Calibration_Tag_Type_of_Variable].text[1:] == 'int32':
                    Variable_in_hexa = Variable_in_hexa + (Data[Calibration_Tag_Value].text)[6:8]
                    Variable_in_deci.append( int( (Data[Calibration_Tag_Value].text)[6:8], 16))
                    Variable_in_hexa = Variable_in_hexa + (Data[Calibration_Tag_Value].text)[4:6]
                    Variable_in_deci.append( int( (Data[Calibration_Tag_Value].text)[4:6], 16))
                    Variable_in_hexa = Variable_in_hexa + (Data[Calibration_Tag_Value].text)[2:4]
                    Variable_in_deci.append( int( (Data[Calibration_Tag_Value].text)[2:4], 16))
                    Variable_in_hexa = Variable_in_hexa + (Data[Calibration_Tag_Value].text)[0:2]
                    Variable_in_deci.append( int( (Data[Calibration_Tag_Value].text)[0:2], 16))
                else:
                    Error.append('Size of Variable are not consistent with 8, 16 or 32 bit word in Variable : ' + Variable[Calibration_Tag_Alias_In_RAM].text)
                    LineConstruction = False
        
        SpareAdd = 0

        if Block[Calibration_Tag_CKS].text != "None":
            if Variable[Calibration_Tag_Type_of_Variable].text[1:] == 'int8':
                Error.append('Size of Cheksum is not computable')
                LineConstruction = False
            elif Variable[Calibration_Tag_Type_of_Variable].text[1:] == 'int16':
                if Variable[Calibration_Tag_NB_Data].text == "1":
                    while int(len(Variable_in_hexa))%8 != 0:
                        Variable_in_hexa = Variable_in_hexa[0:int(len(Variable_in_hexa))-4] + "00" + Variable_in_hexa[int(len(Variable_in_hexa))-4:int(len(Variable_in_hexa))]
                        Variable_in_deci.insert(len(Variable_in_deci)-2,0)
                        SpareAdd = SpareAdd +1
                else:
                    Error.append('NB_Data is not align with checksum')
                    LineConstruction = False

            elif Variable[Calibration_Tag_Type_of_Variable].text[1:] == 'int32':
                Error.append('Size of Cheksum is not computable')
                LineConstruction = False

        #Check Size of Data
        if (int(Block[Calibration_Tag_Size_of_Block].text) + SpareAdd) != (len(Variable_in_deci)-4):
            Error.append('Size of Block is not align with lenght of S00 line : ' + Block[Calibration_Tag_Name_of_Block].text)
            LineConstruction = False

        line.append( 'S3' + hexadecimal(len(Variable_in_deci)+1) + Variable_in_hexa + ChecksumComputation( Variable_in_deci ))


##Start the GlobalConfiguration.xml parser

mydoc = ET.parse('../../../../../Components/Application/Autoliv/NVP/Config/NVP_Layout/GlobalConfiguration.xml')
root = mydoc.getroot()

#import all wanted data from GlobalConfiguration.xml filxe
Size_of_the_last_line = 4
Size_of_the_address = 4

for child in root:
   if('Version' == child.tag):
      if ('Calib' == child.attrib['name']):
         MajorVersion = child.find('Major').text
         MinorVersion = child.find('Minor').text
         SubversionVersion = child.find('Subversion').text
   elif ('StartAddress' == child.tag):
      CalibStartAddress = child.find('Calibration').text
   elif ('MemorySize' == child.tag):
      CalibMemorySize = child.find('CalibrationSize').text

data_for_cks = []

#Compute the penultimate line of .s00 file, with the calibration version
penultimateline = "S3"

#Compute len of data
Len = hexadecimal(Size_of_the_last_line + Size_of_the_address + 1)

#Compute the address
address = hexadecimal(int(CalibStartAddress,16) + int(CalibMemorySize) - Size_of_the_last_line - CRC_Size - FBL_BlockHeader_Size - FBL_Pattern_Size)

for i in range(len(address),8):
    address = '0' + address

for i in range(0,Size_of_the_address):
    data_for_cks.append(int(address[2*i:2*i+2],16))

#Compute data
Data = "FF" + hexadecimal(int(MajorVersion)) + hexadecimal(int(MinorVersion)) + hexadecimal(int(SubversionVersion))
data_for_cks.append(255)
data_for_cks.append(int(MajorVersion))
data_for_cks.append(int(MinorVersion))
data_for_cks.append(int(SubversionVersion))

penultimateline = penultimateline + Len + address + Data + ChecksumComputation(data_for_cks)


##Write .s00 File
if (VariableValidity == True and LineConstruction == True):
	Calibration_file = open("../../../../../Tools/Build_Env/Workspace/Outputs/nvp/CalibrationFlash.S00", "w")
	Calibration_file.write(firstline)
	Calibration_file.write("\n")
	for i in range(len(line)):
		Calibration_file.write(line[i])
		Calibration_file.write("\n")
	Calibration_file.write(penultimateline)
	Calibration_file.write("\n")
	Calibration_file.write(lastline)
	Calibration_file.close()
else:
    Errorfile = open("../../../../../Tools/Build_Env/Workspace/Outputs/nvp/ErrorCalibrationFlashS00.log", "w")
    for i in range(len(Error)):
        Errorfile.write(Error[i])
        Errorfile.write("\n")
    Errorfile.close()

try:
   # Called by makefile, no need to run the vbf target
   print("Called from makefile")   
except:
   print("No arg passed - called from tool")
   try:
      # Execute make vbf  
      result = subprocess.Popen("make.bat", stdout=subprocess.PIPE)
      output, error = result.communicate()
      print(output)
   except OSError:
      print("Cannot run make (Environment not loaded ?)")
