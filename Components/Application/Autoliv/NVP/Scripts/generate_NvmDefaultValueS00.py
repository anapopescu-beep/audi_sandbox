########################################################################################################
#                                       External Function Import                                       #
########################################################################################################
import xml.etree.ElementTree as ET
import os
import subprocess
import sys
from Project_Configuration_for_Python_script import *
from TagXML_for_python_script import GlobalConfiguration_Tag_StartAddress, GlobalConfiguration_Tag_ROM, NvmDefault_Tag_Nb_Block, NvmDefault_Tag_Name_of_Block, NvmDefault_Tag_Fixed_Block, NvmDefault_Tag_Type_of_Variable, NvmDefault_Tag_Value, NvmDefault_Tag_Nb_Variable, NvmDefault_Tag_Address_of_Block, NvmDefault_Tag_Alias_In_RAM, NvmDefault_Tag_CKS, NvmDefault_Tag_Size_of_Block, NvmDefault_Tag_NB_Data
print("***generate_NvmDefaultValueS00.py***") 
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
# Name        : CheksumComputation(tab)                                             #
# Input       : Array with decimal Variable                                         #
# Output      : Cheksum (1 byte)                                                    #
# Description : Compute a the sum of the Variable and make the complement to FF     #
#####################################################################################
def CheksumComputation(tab):

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

# Byte per line for split blocks
SPLIT_BLOCK_SIZE = 32
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

firstline = 'S0' + hexadecimal(NB_char) + Name_in_ASCII + CheksumComputation( First_Address + Name_in_Dec_tab )


#Construction of the last line of the .S00 files

lastline = 'S70500000000FA' #This line is fixed because we use S3 standard of the S-Record, need to be update if 

##Start the GlobalConfiguration.xml parser

mydoc = ET.parse('../../../../../Components/Application/Autoliv/NVP/Config/NVP_Layout/GlobalConfiguration.xml')
root = mydoc.getroot()

#import all wanted data from GlobalConfiguration.xml filxe
EepromStartAddress = root[GlobalConfiguration_Tag_StartAddress][GlobalConfiguration_Tag_ROM].text


##Start the Calibration.xml parser

mydoc = ET.parse('../../../../../Components/Application/Autoliv/NVP/Config/NVP_Layout/NvmDefault.xml')
root = mydoc.getroot()


#Check integrity of Variable

VariableValidity = True
LineConstruction = True
i = 0
for Block in root.iter('Block'):
    i = i + 1

if root[NvmDefault_Tag_Nb_Block].text == str(i):

    for Block in root.iter('Block'):
        i = 0
        for Variable in Block.iter('Variable'):
            i = i + 1
        if Block[NvmDefault_Tag_Nb_Variable].text != str(i):
            VariableValidity = False
            Error.append('Nb_Variable calculate : ' + str(i))
            Error.append('Nb_Variable in XML file : ' + Block[NvmDefault_Tag_Nb_Variable].text)
            Error.append('The number of Variable is not consistency with he number of instanciate Variable, block :' + Block[NvmDefault_Tag_Name_of_Block].text)

else:
    VariableValidity = False
    Error.append('Nb_Block calculate : ' + str(i))
    Error.append('Nb_block in XML file : ' + root[NvmDefault_Tag_Nb_Block].text)
    Error.append('The number of block is not consistency with he number of instanciate block')

    
#Compute Variable
    
if VariableValidity == True:

    line = []
    #Construct line by line the .S00, each line correspond to one block
    for Block in root.iter('Block'):

        if Block[NvmDefault_Tag_Fixed_Block].text != "True" :
            Variable_in_hexa = "" #the Variable in string and in little endian except for the address
            Variable_in_deci = [] #Each word of the Variable use to compute the Cheksum

            #Start by the address
            Block_address = Block[NvmDefault_Tag_Address_of_Block].text

            #Recompute the address with the ROM address and not with the RAM shadow
            #we take only the 3 last digit in hexadecimal display
            Digit = 3
            Block_address = EepromStartAddress[0:len(EepromStartAddress)-Digit] + Block_address[len(Block_address)-Digit:len(Block_address)]

            for i in range(int(len(Block_address)/2)):
                Variable_in_hexa = Variable_in_hexa + Block_address[(2*i):(2*i+2)]
                Variable_in_deci.append( int( Block_address[(2*i):(2*i+2)], 16))

            #Import and compute each Variable, expression in Little Endian
            for Variable in Block.iter('Variable'):
                for Data in Variable.iter('Data'):
                    if Variable[NvmDefault_Tag_Type_of_Variable].text[1:] == 'int8':
                        Variable_in_hexa = Variable_in_hexa + Data[NvmDefault_Tag_Value].text
                        Variable_in_deci.append( int( Data[NvmDefault_Tag_Value].text, 16))
                    elif Variable[NvmDefault_Tag_Type_of_Variable].text[1:] == 'int16':
                        Variable_in_hexa = Variable_in_hexa + (Data[NvmDefault_Tag_Value].text)[2:4]
                        Variable_in_deci.append( int( ((Data[NvmDefault_Tag_Value]).text)[2:4], 16))
                        Variable_in_hexa = Variable_in_hexa + (Data[NvmDefault_Tag_Value].text)[0:2]
                        Variable_in_deci.append( int( (Data[NvmDefault_Tag_Value].text)[0:2], 16))
                    elif Variable[NvmDefault_Tag_Type_of_Variable].text[1:] == 'int32':
                        Variable_in_hexa = Variable_in_hexa + (Data[NvmDefault_Tag_Value].text)[6:8]
                        Variable_in_deci.append( int( (Data[NvmDefault_Tag_Value].text)[6:8], 16))
                        Variable_in_hexa = Variable_in_hexa + (Data[NvmDefault_Tag_Value].text)[4:6]
                        Variable_in_deci.append( int( (Data[NvmDefault_Tag_Value].text)[4:6], 16))
                        Variable_in_hexa = Variable_in_hexa + (Data[NvmDefault_Tag_Value].text)[2:4]
                        Variable_in_deci.append( int( (Data[NvmDefault_Tag_Value].text)[2:4], 16))
                        Variable_in_hexa = Variable_in_hexa + (Data[NvmDefault_Tag_Value].text)[0:2]
                        Variable_in_deci.append( int( (Data[NvmDefault_Tag_Value].text)[0:2], 16))
                    else:
                        Error.append('Size of Variable are not consistent with 8, 16 or 32 bit word in Variable : ' + Variable[NvmDefault_Tag_Alias_In_RAM].text)
                        LineConstruction = False

            SpareAdd = 0

            if Block[NvmDefault_Tag_CKS].text != "None":
                if Variable[NvmDefault_Tag_Type_of_Variable].text[1:] == 'int8':
                    Error.append('Size of Cheksum is not computable')
                    LineConstruction = False
                elif Variable[NvmDefault_Tag_Type_of_Variable].text[1:] == 'int16':
                    if Variable[NvmDefault_Tag_NB_Data].text == "1":
                        while int(len(Variable_in_hexa))%8 != 0:
                            Variable_in_hexa = Variable_in_hexa[0:int(len(Variable_in_hexa))-4] + "00" + Variable_in_hexa[int(len(Variable_in_hexa))-4:int(len(Variable_in_hexa))]
                            Variable_in_deci.insert(len(Variable_in_deci)-2,0)
                            SpareAdd = SpareAdd +1
                    else:
                        Error.append('NB_Data is not align with checksum')
                        LineConstruction = False
                elif Variable[NvmDefault_Tag_Type_of_Variable].text[1:] == 'int32':
                    Error.append('Size of Cheksum is not computable')
                    LineConstruction = False

            #Check Size of Data
            if (int(Block[NvmDefault_Tag_Size_of_Block].text) + SpareAdd) != (len(Variable_in_deci)-4):
                Error.append('Size of Block is not align with lenght of S00 line : ' + Block[NvmDefault_Tag_Name_of_Block].text)
                LineConstruction = False

            # check block size
            BlockSize = int(Block[NvmDefault_Tag_Size_of_Block].text)
            if (BlockSize > SPLIT_BLOCK_SIZE):
                dataLen = BlockSize
                lineAddr = (int(Variable_in_deci[0]) << 24) + (int(Variable_in_deci[1]) << 16) + (int(Variable_in_deci[2]) << 8) + int(Variable_in_deci[3])
                for subLineIdx in range(int(BlockSize / SPLIT_BLOCK_SIZE)):
                    subLineDec = []
                    subLineHex = ""
                    subLineDec.append((lineAddr >> 24) & 0xFF)
                    subLineDec.append((lineAddr >> 16) & 0xFF)
                    subLineDec.append((lineAddr >> 8) & 0xFF)
                    subLineDec.append(lineAddr & 0xFF)
                    subLineDec.extend(Variable_in_deci[(4 + (SPLIT_BLOCK_SIZE * subLineIdx)):(SPLIT_BLOCK_SIZE + 4 + (SPLIT_BLOCK_SIZE * subLineIdx))])

                    subLineHex = subLineHex + hexadecimal((lineAddr >> 24) & 0xFF)
                    subLineHex = subLineHex + hexadecimal((lineAddr >> 16) & 0xFF)
                    subLineHex = subLineHex + hexadecimal((lineAddr >> 8) & 0xFF)
                    subLineHex = subLineHex + hexadecimal(lineAddr & 0xFF)
                    subLineHex += Variable_in_hexa[(8 + ((SPLIT_BLOCK_SIZE * 2) * subLineIdx)):(8 + (SPLIT_BLOCK_SIZE*2) + ((SPLIT_BLOCK_SIZE*2) * subLineIdx) )]

                    line.append( 'S3' + hexadecimal(SPLIT_BLOCK_SIZE + 5) + subLineHex + CheksumComputation( subLineDec ))
                    lineAddr += SPLIT_BLOCK_SIZE
                    dataLen -= SPLIT_BLOCK_SIZE

                # Check if there are some remaining data to store
                if dataLen != 0 :
                    subLineDec = []
                    subLineHex = ""
                    subLineDec.append((lineAddr >> 24) & 0xFF)
                    subLineDec.append((lineAddr >> 16) & 0xFF)
                    subLineDec.append((lineAddr >> 8) & 0xFF)
                    subLineDec.append(lineAddr & 0xFF)
                    subLineDec.extend(Variable_in_deci[-dataLen:])

                    subLineHex = subLineHex + hexadecimal((lineAddr >> 24) & 0xFF)
                    subLineHex = subLineHex + hexadecimal((lineAddr >> 16) & 0xFF)
                    subLineHex = subLineHex + hexadecimal((lineAddr >> 8) & 0xFF)
                    subLineHex = subLineHex + hexadecimal(lineAddr & 0xFF)
                    subLineHex += Variable_in_hexa[-(dataLen*2):]

                    line.append( 'S3' + hexadecimal(dataLen + 5) + subLineHex + CheksumComputation( subLineDec ))
            else:
            	line.append( 'S3' + hexadecimal(len(Variable_in_deci)+1) + Variable_in_hexa + CheksumComputation( Variable_in_deci ))


##Start the GlobalConfiguration.xml parser

mydoc = ET.parse('../../../../../Components/Application/Autoliv/NVP/Config/NVP_Layout/GlobalConfiguration.xml')
root = mydoc.getroot()

#import all wanted data from GlobalConfiguration.xml filxe
Size_of_the_last_line = 4
Size_of_the_address = 4

for child in root:
   if('Version' == child.tag):
      if ('E2P' == child.attrib['name']):
         MajorVersion = child.find('Major').text
         MinorVersion = child.find('Minor').text
         SubversionVersion = child.find('Subversion').text
   elif ('StartAddress' == child.tag):
      E2PdefaultStartAddress = child.find('ROM').text
   elif ('MemorySize' == child.tag):
      E2PdefaultMemSize = child.find('RomSize').text

data_for_cks = []

#Compute the penultimate line of .s00 file, with the calibration version
penultimateline = "S3"

#Compute len of data
Len = hexadecimal(Size_of_the_last_line + Size_of_the_address + 1)

#Compute the address
address = hexadecimal(int(E2PdefaultStartAddress,16) + int(E2PdefaultMemSize) - Size_of_the_last_line - CRC_Size - FBL_BlockHeader_Size - FBL_Pattern_Size)

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

penultimateline = penultimateline + Len + address + Data + CheksumComputation(data_for_cks)


##Write .s00 File
if (VariableValidity == True and LineConstruction == True):
    Eeprom_file = open("../../../../../Tools/Build_Env/Workspace/Outputs/nvp/NvmDefaultValue.S00", "w")
    Eeprom_file.write(firstline)
    Eeprom_file.write("\n")
    for i in range(len(line)):
        Eeprom_file.write(line[i])
        Eeprom_file.write("\n")
    Eeprom_file.write(penultimateline)
    Eeprom_file.write("\n")
    Eeprom_file.write(lastline)
    Eeprom_file.close()
else:
    Errorfile = open("../../../../../Tools/Build_Env/Workspace/Outputs/nvp/ErrorNvmDefaultValueS00.log", "w")
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
