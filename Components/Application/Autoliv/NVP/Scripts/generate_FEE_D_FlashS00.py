########################################################################################################
#                                       External Function Import                                       #
########################################################################################################
import xml.etree.ElementTree as ET
import re
import os
from Project_Configuration_for_Python_script import *
from TagXML_for_python_script import NvmDefault_Tag_Nb_Block, NvmDefault_Tag_Name_of_Block, NvmDefault_Tag_Nb_Variable, NvmDefault_Tag_Type_of_Variable, NvmDefault_Tag_Value
print("***generate_FEE_D_Flash00.py***") 
os.chdir(os.path.dirname(os.path.realpath(__file__)))

########################################################################################################
#                                     Constant Variable Definition                                     #
########################################################################################################
# D-FLASH 
KI_DFLASH_ADDR_BASE = 0x10000000


# Cluster 1 #
Ki_Target_Address_1   = 268468224 #0x1000 8000  ##FEE Target cluster Address
Ki_BlockHdr_Address_1 = 268435456 #0x1000 0000  ##FEE Start Block Address
Ki_Cluster_Start_1    = 268435456 #0x1000 0000  ##FEE Start cluster Address
Ki_Cluster_Stop_1     = 268468223 #0x1000 7FFF  ##FEE Stop  cluster Address

# Cluster 2 #
Ki_Target_Address_2   = 268500992 #0x1001 0000  ##FEE Start Block Address
Ki_BlockHdr_Address_2 = 268468224 #0x1000 8000  ##FEE Start cluster Address
Ki_Cluster_Start_2    = 268468224 #0x1000 8000  ##FEE Target cluster Address
Ki_Cluster_Stop_2     = 268500991 #0x1000 FFFF  ##FEE Stop  cluster Address

# Cluster parameter
Ki_Cluster_Id = 1
Ki_Cluster_logical_start_address = 0

# Constant for file construction #
Ki_FreeData = 255
Ki_EmptyData = 0
Ki_ValidFlag = 129
Ks_lastline = 'S70500000000FA' # This line is fixed because we use S3 standard of the S-Record
Ki_FEE_Header_Size = 48
Ki_Size_of_1_Line = 16
Kai_Config_Block_id_default_value = [1, 0, 62, 46, 80, 7, 110, 10, 176, 4, 7, 0, 0, 0, 79, 8]
Kai_LineFreeData = [Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData]
Kh_Polynomial_CRC = 0x1021

# Reference file path
PathFile_Fee_Cfg_h = "../../../../../Components/Application/Supplier/Tresos_Configuration_8.5.1//Workspace//" + Ks_Tresos_Project_Name + "/Tresos_BSW_generated/include/Fee_Cfg.h"
PathFile_Fee_Cfg_c = "../../../../../Components/Application/Supplier/Tresos_Configuration_8.5.1//Workspace//" + Ks_Tresos_Project_Name + "/Tresos_BSW_generated/src/Fee_Cfg.c"
PathFile_NvM_Cfg_c = "../../../../../Components/Application/Supplier/Tresos_Configuration_8.5.1//Workspace//" + Ks_Tresos_Project_Name + "/Tresos_BSW_generated/src/NvM_Cfg.c"
PathFile_NvmDefault_xml = '../../../../../Components/Application/Autoliv/NVP/Config/NVP_Layout/NvmDefault.xml'


########################################################################################################
#                                            Global Variable                                           #
########################################################################################################

# Check integrity of different file
b_ExistingFile = True
b_VariableValidity = True
b_LineConstruction = True
as_Error = [] # Array use to catch all error and stock this in log file at the end of the generation

# Data variable
ai_Memory_Block_ID = []
ai_Memory_Block_Size = []
bi_Memory_Block_CRC16 = []

# Cluster dictionary [ group, startAddress, size]
clusterList = []
# block dictionary [ group, size]
blockList = []
blockIdx = 0
nbrOfClusters = 0
clusterIdx = 0
clusterGroupIdx = 0

NbrOfFEEBlocks = 0

# Block of Data write in S00 file
as_ClusterHdrLst = []
asClusterDataList = []
as_Cluster1_Header = []
as_Block_Header = []
as_Free_Cluster1 = []
as_Block_Data = []
as_Free_Cluster2 = []

########################################################################################################
#                                           Internal Function                                          #
########################################################################################################

#################################################################
# Name        : hexadecimal(integer, Size)                       #
# Input       : Integer in range of 32 bit, Target size of      #
#               the result express in byte                      #
# Output      : hexa on syze byte                               #
# Description : Convert an integer in hexa with byte expression #
#################################################################
def hexadecimal(integer, Size):

    hexa = ''
    if (integer < 16 and integer >= 0):
        hexa = '0' + hex(integer)[2:]
    elif (integer < 256):
        hexa = hex(integer)[2:]
    elif (integer < 4096):
        hexa = '0' + hex(integer)[2:]
    elif (integer < 65536):
        hexa = hex(integer)[2:]
    elif (integer < 1048576):
        hexa = '0' + hex(integer)[2:]
    elif (integer < 16777216):
        hexa = hex(integer)[2:]
    elif (integer < 268435456):
        hexa = '0' + hex(integer)[2:]
    else:
        hexa = hex(integer)[2:]

    while(len(hexa) < Size * 2):
        hexa = '0' + hexa

    return hexa.upper()

#################################################################
# Name        : LittleEndian_formatting(integer,size)           #
# Input       : Integer in range of 32 bit, Target size of      #
#               the result express in byte                      #
# Output      : hexa (1 byte)                                   #
# Description : Convert an integer in hexa with byte expression #
#################################################################
def LittleEndian_formatting(Data, Size):

    hexa = hexadecimal(Data, Size)
    Data_in_little_endian = []
    if (len(hexa) == (Size * 2)):
        for i in range(Size):
            Data_in_little_endian.append(int(hexa[Size * 2 - (2*i+2): Size * 2 - (2*i)], 16))
    
    return Data_in_little_endian

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
    return hexadecimal((255 - (CKS + len(tab) + 1) % 256), 1)

#####################################################################################
# Name        : ComputeOneS00lineinS3(int, int[])                                   #
# Input       : Address on 32 bit, Data array of 16 byte                            #
# Output      : Target Address (1 byte)                                             #
# Description : Compute the target Address of Fee Block                             #
#####################################################################################
def ComputeOneS00lineinS3(Address, Data):
    s_ReturnLine = "S315"
    ai_allDatainDeci = [] # Variable use to compute the cheksum of S00 file

    # Check Address and Data are in a good range : Address in [0x00000000;0xFFFFFFFF] and Data[i] in [0x00;0xFF]
    if (Address >= 0 and Address < 4294967295):
        if (len(Data) == 16 and max(Data) < 256 and min(Data) >= 0):
            s_Address_in_hexa = hexadecimal(Address, 4)
            for i in range(4):
                ai_allDatainDeci.append(int(s_Address_in_hexa[i*2: 2 + i*2], 16))
            ai_allDatainDeci += Data
            
            for i in range(len(ai_allDatainDeci)):
                s_ReturnLine += hexadecimal(ai_allDatainDeci[i], 1)
            
            s_ReturnLine += CheksumComputation(ai_allDatainDeci)
        else:
            s_ReturnLine = s_ReturnLine + "ERROR_IN_DATA_AT_ADDRESS_0x" + hexadecimal(Address, 4) #set an invalid value, this could not be flashed
    else:
        s_ReturnLine = s_ReturnLine + "ERROR_IN_ADDRESS_NOT_IN_RANGE" #set an invalid value, this could not be flashed     

    return (s_ReturnLine + "\n") 

#####################################################################################
# Name        : ComputeOneS00lineinS3(int[])                                        #
# Input       : Data array of 16 byte                                               #
# Output      : CRC16                                                               #
# Description : Compute the CRC16 of the Data Array, Used Polynomial is 0x1021      #
#####################################################################################
def Compute_CRC_16(Data):
    i_CRC_16 = 65535

    for LoopOnData in range(len(Data)):

        Crc_16_Polynome_Value = ((int(i_CRC_16/256)^Data[LoopOnData])<<8)
        for bit in range (8):
            if ((Crc_16_Polynome_Value &0x8000) ==0):
                Crc_16_Polynome_Value <<=1 
            else:
                Crc_16_Polynome_Value = (Crc_16_Polynome_Value << 1) ^ Kh_Polynomial_CRC
                
        Crc_16_Polynome_Value = Crc_16_Polynome_Value%65536

        i_CRC_16 = (Crc_16_Polynome_Value^((i_CRC_16*256)%65536))

    return i_CRC_16

#####################################################################################
# Name        : GetFirstClusterInGroup(int)                                         #
# Input       : groupId                                                             #
# Output      : iClusterIdx                                                         #
# Description : Returns the first cluster index in clusterList                      #
#               for the specified group                                             #
#####################################################################################
def GetFirstClusterInGroup(groupId):
    i_ClusterIdx = 0

    for cluster in clusterList:
        if cluster.get('group') == groupId : 
            return i_ClusterIdx
        i_ClusterIdx += 1

#####################################################################################
# Name        : GetNumberOfClusterInGroup(int)                                      #
# Input       : groupId                                                             #
# Output      : iClusterNbr                                                         #
# Description : Returns the number of cluster(s) in the specified group             #
#####################################################################################
def GetNumberOfClusterInGroup(groupId):
   i_ClusterNbr = 0
   for cluster in clusterList:
        if cluster.get('group') == groupId:
           i_ClusterNbr += 1
   return (i_ClusterNbr)

#####################################################################################
# Name        : GetNumberOfGroups()                                                 #
# Input       : none                                                                #
# Output      : iNbrGroup                                                           #
# Description : Returns the number of group(s) configured                           #
#####################################################################################
def GetNumberOfGroups():
    iNbrGroup = 0
    iPrevGroupId = 0xDEAD

    for cluster in clusterList:
        if cluster.get('group') != iPrevGroupId:
            iNbrGroup += 1
            iPrevGroupId = cluster.get('group')
    return (iNbrGroup)

#####################################################################################
# Name        : GetNumberOfClusterInGroup(int)                                      #
# Input       : groupId                                                             #
# Output      : iClusterNbr                                                         #
# Description : Assumption : all groups have the same number of cluster             #
#               In our case: 2 clusters per group.                                  #
#               formula: (n * groupSize) + m,                                       #
#               with n = nbr of groups, groupSize = 2,                              #
#               m cluster Id in group (0,1,2 etc)                                   #
#####################################################################################
def GetClusterIndex(groupId, clusterId):
   return((groupId * GetNumberOfClusterInGroup(groupId)) + clusterId)

#####################################################################################
# Name        : CreateClusterHeader(int)                                            #
# Input       : groupId                                                             #
# Output      : list(string)                                                        #
# Description : Returns the formated cluster header                                 #
#####################################################################################
def CreateClusterHeader(groupId):
    tmpHdr = []
    iCurrCluster = GetFirstClusterInGroup(groupId)
    # Compute Address for position of data block and block header
    i_Current_Header_Address = KI_DFLASH_ADDR_BASE + clusterList[iCurrCluster].get('startAddr')
    
    # cluster header checksum
    iChecksum = Ki_Cluster_Id + clusterList[iCurrCluster].get('startAddr') + clusterList[iCurrCluster].get('size')

    # Create Cluster header
    tmpHdr.append(ComputeOneS00lineinS3(i_Current_Header_Address,LittleEndian_formatting(Ki_Cluster_Id,4) + LittleEndian_formatting(clusterList[iCurrCluster].get('startAddr'),4) + LittleEndian_formatting(clusterList[iCurrCluster].get('size'),4) + LittleEndian_formatting(iChecksum,4)))
    i_Current_Header_Address += Ki_Size_of_1_Line
    tmpHdr.append(ComputeOneS00lineinS3(i_Current_Header_Address,[Ki_ValidFlag,Ki_FreeData,Ki_FreeData,Ki_FreeData,Ki_FreeData,Ki_FreeData,Ki_FreeData,Ki_FreeData,Ki_FreeData,Ki_FreeData,Ki_FreeData,Ki_FreeData,Ki_FreeData,Ki_FreeData,Ki_FreeData,Ki_FreeData]))
    i_Current_Header_Address += Ki_Size_of_1_Line
    tmpHdr.append(ComputeOneS00lineinS3(i_Current_Header_Address, Kai_LineFreeData))
    return(tmpHdr)

#####################################################################################
# Name        : CreateEmptyCluster(int, int)                                        #
# Input       : GroupId and clusterID                                               #
# Output      : none                                                                #
# Description : Fill a cluster with empty data (0xFF)                               #
#####################################################################################
def CreateEmptyCluster(groupId, clusterId):
   iClusterIdx = GetClusterIndex(groupId, clusterId)
   iRemainingSize = clusterList[iClusterIdx].get('size')
   iFloatingPtrAddr = KI_DFLASH_ADDR_BASE + clusterList[iClusterIdx].get('startAddr')
   tmpData = []
   
   # Fill data buffer with empty lines
   while (iRemainingSize > 0):
      tmpData.append(ComputeOneS00lineinS3(iFloatingPtrAddr, Kai_LineFreeData))
      iFloatingPtrAddr += Ki_Size_of_1_Line
      iRemainingSize -= Ki_Size_of_1_Line

   # copy data buffer to the cluster data list
   asClusterDataList.insert(iClusterIdx, tmpData)

#####################################################################################
# Name        : AddBlock(int, dict, list, int, int, list)                           #
# Input       :                                                                     #
# Output      : none                                                                #
# Description : Add block header and data to the buffer passed in parameter         #
#####################################################################################
def AddBlock(cluster, block, dataBuff, pBlockHdrAddr, pDataAddr, defaultValues):
   AddBlockHeader(cluster, block, dataBuff, pBlockHdrAddr, pDataAddr)
   AddBlockData(block, dataBuff, pDataAddr, defaultValues)

#####################################################################################
# Name        : AddConfigIdBlock(int, dict, list, int, int)                         #
# Input       : groupId                                                             #
# Output      : iClusterNbr                                                         #
# Description : Add block header and specific ConfidID data                         #
#####################################################################################
def AddConfigIdBlock(cluster, block, dataBuff, pBlockHdrAddr, pDataAddr):
   ai_Data = []
   
   AddBlockHeader(cluster, block, dataBuff, pBlockHdrAddr, pDataAddr)
   # Create data Array
   ai_Data = Kai_Config_Block_id_default_value

   # align Data Array on 16 byte
   while len(ai_Data) != block.get('size') :
      ai_Data.append(Ki_FreeData)

   AddBlockData(block, dataBuff, pDataAddr, ai_Data)

#####################################################################################
# Name        : AddDemBlock(int, dict, list, int, int)                              #
# Input       : groupId                                                             #
# Output      : iClusterNbr                                                         #
# Description : Add block header and specific ConfidID data                         #
#####################################################################################
def AddDemBlock(cluster, block, dataBuff, pBlockHdrAddr, pDataAddr):
   ai_Data = []

   AddBlockHeader(cluster, block, dataBuff, pBlockHdrAddr, pDataAddr)
   # Create data Array default value for all the block
   while len(ai_Data) !=  block.get('size') :
      ai_Data.append(Ki_EmptyData)

   # align Data Array on 16 byte
   while len(ai_Data) != block.get('size') :
      ai_Data.append(Ki_FreeData)

   AddBlockData(block, dataBuff, pDataAddr, ai_Data)
      
#####################################################################################
# Name        : AddBlockHeader(int, dict, list, int, int)                           #
# Input       : groupId                                                             #
# Output      : iClusterNbr                                                         #
# Description : Create a block header and copy it to the provided buffer            #
#####################################################################################
def AddBlockHeader(cluster, block, dataBuff, pBlockHdrAddr, pDataAddr):
   ai_Block_header_Data = []
   ai_Block_header_Data = LittleEndian_formatting(block.get('id'), 2)
   ai_Block_header_Data += LittleEndian_formatting(block.get('size'), 2)
   ai_Block_header_Data += LittleEndian_formatting((pDataAddr - KI_DFLASH_ADDR_BASE), 4)
   ai_Block_header_Data += LittleEndian_formatting(block.get('id') + block.get('size') + (pDataAddr - KI_DFLASH_ADDR_BASE), 4)
   ai_Block_header_Data += [Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData]

   dataBuff.append(ComputeOneS00lineinS3(pBlockHdrAddr, ai_Block_header_Data))
   pBlockHdrAddr += Ki_Size_of_1_Line
   dataBuff.append(ComputeOneS00lineinS3(pBlockHdrAddr, [Ki_ValidFlag, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData, Ki_FreeData]))
   pBlockHdrAddr += Ki_Size_of_1_Line
   dataBuff.append(ComputeOneS00lineinS3(pBlockHdrAddr, Kai_LineFreeData))

#####################################################################################
# Name        : AddBlockData(int, dict, list, int, int)                             #
# Input       : groupId                                                             #
# Output      : iClusterNbr                                                         #
# Description : Add default data for a block to the provided buffer                 #
#####################################################################################
def AddBlockData (block, dataBuff, pDataAddr, defaultValues):
   # Write data in block
   for lineIdx in range(int(block.get('size') / 16)):
      dataBuff.append(ComputeOneS00lineinS3(pDataAddr + (Ki_Size_of_1_Line * lineIdx), defaultValues[Ki_Size_of_1_Line * lineIdx:Ki_Size_of_1_Line * lineIdx + Ki_Size_of_1_Line]))

#####################################################################################
# Name        : FillClusterWithEmptyData(int)                                       #
# Input       : groupId                                                             #
# Output      : iClusterNbr                                                         #
# Description : Fill the gap between the last block header and its data with 0xFF   #
#####################################################################################
def FillClusterWithEmptyData(dataBuff, pBlockHdrAddr, pDataAddr):
   iRemainingSize = (pDataAddr - pBlockHdrAddr) + Ki_Size_of_1_Line
   while (iRemainingSize > 0):
      dataBuff.append(ComputeOneS00lineinS3(pDataAddr, Kai_LineFreeData))
      pDataAddr -= Ki_Size_of_1_Line
      iRemainingSize -= Ki_Size_of_1_Line

#####################################################################################
# Name        : CreateSrecFile()                                                    #
# Input       : None                                                                #
# Output      : None                                                                #
# Description : Generates Srecord file                                              #
#####################################################################################
def CreateSrecFile():
   if (b_VariableValidity == True and b_LineConstruction == True and b_ExistingFile == True):
      D_Flash_file = open("../../../../../Tools/Build_Env/Workspace/Outputs/nvp/Fee_D_Flash.srec", "w")
      
      for cluster in asClusterDataList:
         D_Flash_file.writelines(cluster)

      D_Flash_file.write(Ks_lastline)
      D_Flash_file.write("\n")
      D_Flash_file.close()
   else:
      Errorfile = open("../../../../../Tools/Build_Env/Workspace/Outputs/nvp/ErrorFee_D_FlashS00.log", "w")
      for i in range(len(as_Error)):
         Errorfile.write(as_Error[i])
         Errorfile.write("\n")
      Errorfile.close()

#####################################################################################
# Name        : GetDefaultValuesForAllBlocks()                                      #
# Input       : None                                                                #
# Output      : List example: [[0,0,0,],[0,65,45]                                   #
# Description : Returns a list with all blocks default data                         #
#####################################################################################
def GetDefaultValuesForAllBlocks():
   ai_BlockDataList = []
   iBlockIdx = 0

   # Get all default values for blocks
   for Block in root_NvmDefault_xml.iter('Block'):
      ai_Data = []
      # Create data Array default value for all the block
      for Variable in Block.iter('Variable'):
         for Data in Variable.iter('Data'):
            if (Variable[NvmDefault_Tag_Type_of_Variable].text[1:] == 'int32') :
               ai_Data += LittleEndian_formatting(int(Data[NvmDefault_Tag_Value].text,16), 4)
            elif (Variable[NvmDefault_Tag_Type_of_Variable].text[1:] == 'int16') :
               ai_Data += LittleEndian_formatting(int(Data[NvmDefault_Tag_Value].text,16), 2)
            else:
               ai_Data += LittleEndian_formatting(int(Data[NvmDefault_Tag_Value].text, 16), 1)
      #Add CRC16 if needed, define in TRESOS configuration
      if (bi_Memory_Block_CRC16[iBlockIdx]):
         ai_Data += LittleEndian_formatting(Compute_CRC_16(ai_Data), 2)

      # align Data Array on 16 byte
      while len(ai_Data) != blockList[iBlockIdx].get('size') :
            ai_Data.append(Ki_FreeData)
      ai_BlockDataList.insert(iBlockIdx, ai_Data)
      iBlockIdx += 1
   
   return(ai_BlockDataList)

############################################################################################################
#############################            Main Function                   ###################################
############################################################################################################

####################################################
## Extract Block ID ################################
####################################################
if(os.path.exists(PathFile_Fee_Cfg_h)):

    file = open (PathFile_Fee_Cfg_h, 'r')
    lines = file.read().splitlines()

    for Parse_file_line in range(0, len(lines)):
        if '/* Symbolic names of configured Fee blocks */' in lines[Parse_file_line]:
            Start_Line_for_Block_ID = Parse_file_line
            for Parse_block_in_file in range(Start_Line_for_Block_ID + 1, len(lines)):
                if '#define FeeConf' in lines[Parse_block_in_file]:
                    ai_Memory_Block_ID.append(int(re.findall(r'\d+', lines[Parse_block_in_file])[-1]))
        # Look for number of configured blocks
        if '/* Number of configured Fee blocks */' in lines[Parse_file_line]:
            NbrOfFEEBlocks = int(re.findall(r'\d+', lines[Parse_file_line + 1])[0])


    file.close()

else:
    b_ExistingFile = False
    as_Error.append("File : " + PathFile_Fee_Cfg_h + " does not exist.")
    as_Error.append("       ! Check 'Project Variable' at the start of this script ")
    as_Error.append("       ! Check Tresos Workspace")

####################################################
## Extract Block Size ##############################
####################################################


if(os.path.exists(PathFile_Fee_Cfg_c)):

    file = open (PathFile_Fee_Cfg_c, 'r')
    lines = file.read().splitlines()

    for Parse_file_line in range(0, len(lines)):
        if (lines[Parse_file_line].find("Fee_ClusterType") != -1):
            nbrOfClusters =  int(re.findall(r'\[([0-9]*?)\]',lines[Parse_file_line])[0])
            # Get cluster group, start address and size
            for cluster in range(0, nbrOfClusters):
                clusterList.insert(clusterIdx, {'group': clusterGroupIdx, 'startAddr': int(re.findall(r'\d+', lines[Parse_file_line + 4 + (4 * cluster)])[0]), 'size': int(re.findall(r'\d+', lines[Parse_file_line + 5 + (4 * cluster)])[0])})
                clusterIdx += 1
            clusterGroupIdx +=1
        if '/* Configuration of cluster group set */' in lines[Parse_file_line]:
            Start_Line_for_Block_Size = Parse_file_line
            for Parse_block_in_file in range(Start_Line_for_Block_Size + 1, len(lines)):
                if '/* FeeBlockSize */' in lines[Parse_block_in_file]:
                    ai_Memory_Block_Size.append(int(re.findall(r'\d+', lines[Parse_block_in_file])[0]))
        if (lines[Parse_file_line].find('Fee_BlockConfigType') != -1):
            # Block configuration, loop through all
            for block in range(0, NbrOfFEEBlocks):
                blockList.insert(blockIdx, {'group': int(re.findall(r'\d+', lines[Parse_file_line + 6 + (12 * block)])[0]), 'size': int(re.findall(r'\d+', lines[Parse_file_line + 5 + (12 * block)])[0]), 'name': lines[Parse_file_line + 2 + (12 * block)], 'id': ai_Memory_Block_ID[blockIdx]})
                blockIdx += 1
    file.close()

else:
    b_ExistingFile = False
    as_Error.append("File : " + PathFile_Fee_Cfg_c + " does not exist.")
    as_Error.append("       ! Check 'Project Variable' at the start of this script ")
    as_Error.append("       ! Check Tresos Workspace")

####################################################
## Extract Block CRC ###############################
####################################################

if(os.path.exists(PathFile_NvM_Cfg_c)):

    file = open (PathFile_NvM_Cfg_c, 'r')
    lines = file.read().splitlines()

    ai_Memory_Block_Num = []
    si_Memory_Block_Desc = []
    for Parse_file_line in range(0, len(lines)):
        if 'NvM_BlockDescriptorTable' in lines[Parse_file_line]:
            Start_Line_for_Block_Size = Parse_file_line
            for Parse_block_in_file in range(Start_Line_for_Block_Size + 1, len(lines)):
                if '/* blockDesc */' in lines[Parse_block_in_file]:
                    si_Memory_Block_Desc.append(lines[Parse_block_in_file][lines[Parse_block_in_file].find('0'):lines[Parse_block_in_file].find('U')])
                if '/* nvBlockNum */' in lines[Parse_block_in_file]:
                    ai_Memory_Block_Num.append(int(re.findall(r'\d+', lines[Parse_block_in_file])[0]))
    
    #Check bit 2 of the last BlockDesc's Byte
    for i in range(len(ai_Memory_Block_Num)):
        for j in range(ai_Memory_Block_Num[i]):
            if (int(si_Memory_Block_Desc[i][-1],16)&2 == 0):
                bi_Memory_Block_CRC16.append(False)
            else :
                bi_Memory_Block_CRC16.append(True)
    file.close()

else:
    b_ExistingFile = False
    as_Error.append("File : " + PathFile_NvM_Cfg_c + " does not exist.")
    as_Error.append("       ! Check 'Project Variable' at the start of this script ")
    as_Error.append("       ! Check Tresos Workspace")

####################################################
## Extract Block Data ##############################
####################################################

if(os.path.exists(PathFile_NvmDefault_xml)):

    # parse the xml file
    File_NvmDefault_xml = ET.parse(PathFile_NvmDefault_xml)
    root_NvmDefault_xml = File_NvmDefault_xml.getroot()

else:
    b_ExistingFile = False
    as_Error.append("File : " + PathFile_NvmDefault_xml + " does not exist.")
    as_Error.append("       ! Check 'Project Variable' at the start of this script ")
    as_Error.append("       ! Check NVP Layout Workspace")

####################################################
## Check all data are align ########################
####################################################

if b_ExistingFile == True:
    Total_Number_of_block = 0
    Number_of_block_needed_in_fee = 0

    # Check NvmDefault.xml file
    for Block in root_NvmDefault_xml.iter('Block'):
        Total_Number_of_block = Total_Number_of_block + 1
        if ((Block[NvmDefault_Tag_Name_of_Block].text) == "block 0: NvM internal block") :
            Number_of_block_needed_in_fee = Number_of_block_needed_in_fee
        elif ((Block[NvmDefault_Tag_Name_of_Block].text) == "NVM_BLOCK_NvMBlock_ConfigID") :
            Number_of_block_needed_in_fee += 2
        else:
            Number_of_block_needed_in_fee += 1
        
    if root_NvmDefault_xml[NvmDefault_Tag_Nb_Block].text == str(Total_Number_of_block):
        for Block in root_NvmDefault_xml.iter('Block'):
            Number_of_variable_in_block = 0
            for Variable in Block.iter('Variable'):
                Number_of_variable_in_block = Number_of_variable_in_block + 1
            if Block[NvmDefault_Tag_Nb_Variable].text != str(Number_of_variable_in_block):
                b_VariableValidity = False

                as_Error.append('Nb_Variable calculate : ' + str(Number_of_variable_in_block))
                as_Error.append('Nb_Variable in XML file : ' + Block[NvmDefault_Tag_Nb_Variable].text)
                as_Error.append('The number of Variable is not consistency with he number of instanciate Variable, block :' + Block[NvmDefault_Tag_Name_of_Block].text)
                as_Error.append("       ! Make a generation by the NVP_Layout tool")

    else:
        b_VariableValidity = False
        as_Error.append('Nb_Block calculate : ' + str(Total_Number_of_block))
        as_Error.append('Nb_block in XML file : ' + root_NvmDefault_xml[NvmDefault_Tag_Nb_Block].text)
        as_Error.append('The number of block is not consistency with he number of instanciate block')
        as_Error.append("       ! Make a generation by the NVP_Layout tool")

    # Check consistency between Tresos file
    if (len(ai_Memory_Block_ID) != len(ai_Memory_Block_Size)):
        b_VariableValidity = False
        as_Error.append("Nb block ID in " + PathFile_Fee_Cfg_h + " is : " + len(ai_Memory_Block_ID))
        as_Error.append("Nb block Size in " + PathFile_Fee_Cfg_c + " is : " + len(ai_Memory_Block_Size))
        as_Error.append("The number of block is not consistency In Tresos file.")
        as_Error.append("       ! Check Tresos File / Generation")

    # Check consistency between Tresos and NVP_layout file
    if (len(ai_Memory_Block_ID) != Number_of_block_needed_in_fee):
        b_VariableValidity = False
        as_Error.append("Nb block ID in " + PathFile_Fee_Cfg_h + " is : " + str(len(ai_Memory_Block_ID)))
        as_Error.append("Nb block needed in fee for " + PathFile_NvmDefault_xml + " is : " + str(Number_of_block_needed_in_fee))
        as_Error.append("The number of block is not consistent between Tresos and NVP_layout file.")
        as_Error.append("       ! Make a full generation")
        as_Error.append("       ! Check NVP layout File / Generation")
        as_Error.append("       ! Check Tresos File / Generation")

    # Check All data can be write in cluster 1
    if ((sum(ai_Memory_Block_Size) + len(ai_Memory_Block_Size) * Ki_FEE_Header_Size) >= (Ki_Cluster_Stop_1 - Ki_Cluster_Start_1)):
        b_VariableValidity = False
        as_Error.append("Needed Size in cluster in " + PathFile_Fee_Cfg_c + " is : " + sum(ai_Memory_Block_Size))
        as_Error.append("Nb block needed in fee for " + PathFile_NvmDefault_xml + " is : " + Number_of_block_needed_in_fee)
        as_Error.append("The number of block is not consistency between Tresos and NVP_layout file.")
        as_Error.append("       ! Make a full generation")
        as_Error.append("       ! Check NVP layout File / Generation")
        as_Error.append("       ! Check Tresos File / Generation")

    ####################################################
    ## Compute Data ####################################
    ####################################################
                
    # Get default values for all blocks
    aiDfltDataBlockList = GetDefaultValuesForAllBlocks()

# Parse all groups
for group in range(0, GetNumberOfGroups()):
   for cluster in range(0, GetNumberOfClusterInGroup(group)):
      # Only 1 cluster per group shall be initialized
      if (0 == cluster):
         dataBuff = []
         CurrentBlock = 0
         # Initialize @ "pointers"
         pBlockHdrAddr = KI_DFLASH_ADDR_BASE + clusterList[GetClusterIndex(group, cluster)].get('startAddr')
         pBlockDataAddr = KI_DFLASH_ADDR_BASE + clusterList[GetClusterIndex(group, cluster)].get('startAddr') + clusterList[GetClusterIndex(group, cluster)].get('size')
         dataBuff = CreateClusterHeader(group)
         # Parse all blocks
         for block in blockList:
            # Check if block shall be stored in current group cluster
            if (group == block.get('group')):
               # Update block header address
               pBlockHdrAddr += 48
               # update Data address based on block size
               pBlockDataAddr -= block.get('size')
               # Check for specific blocks
               if (block.get('name').find("CONFIG_ID_1") != -1):
                  AddConfigIdBlock(cluster, block, dataBuff, pBlockHdrAddr, pBlockDataAddr)
               elif (block.get('name').find("CONFIG_ID_2") != -1):
                  AddConfigIdBlock(cluster, block, dataBuff, pBlockHdrAddr, pBlockDataAddr)
               elif (block.get('name').find("DEM_DEFAULT") != -1):
                  AddDemBlock(cluster, block, dataBuff, pBlockHdrAddr, pBlockDataAddr)
               else:
                  AddBlock(cluster, block, dataBuff, pBlockHdrAddr, pBlockDataAddr, aiDfltDataBlockList[CurrentBlock])
            # Go to next block for the default values
            CurrentBlock += 1
         # Last block added into the cluster, update block header address to fill the cluster
         pBlockHdrAddr += 48
         pBlockDataAddr -= Ki_Size_of_1_Line
         # Fill rest of the cluster with empty data
         FillClusterWithEmptyData(dataBuff, pBlockHdrAddr, pBlockDataAddr)
         # Sort block header and data
         dataBuff.sort()
         # copy data buffer to the cluster data list
         asClusterDataList.insert(GetClusterIndex(group, cluster), dataBuff)
      else:
         CreateEmptyCluster(group,cluster)

# Generate the final file
CreateSrecFile()

