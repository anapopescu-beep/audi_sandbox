########################################################################################################
#                                       External Function Import                                       #
########################################################################################################
import xml.etree.ElementTree as ET
import datetime
import os
from TagXML_for_python_script import GlobalConfiguration_Tag_StartAddress, GlobalConfiguration_Tag_Version, GlobalConfiguration_Tag_Calibration, GlobalConfiguration_Tag_RamShadow, GlobalConfiguration_Tag_ROM, GlobalConfiguration_Tag_Major, GlobalConfiguration_Tag_Minor, GlobalConfiguration_Tag_Subversion
print("***generate_NVPMemoryMappingh.py***") 
os.chdir(os.path.dirname(os.path.realpath(__file__)))
#################################################################
# Name        : Norm(i)                                         #
# Input       : Number [0,99]                                   #
# Output      : Number in String 2 string                       #
# Description : add a 0 at the string for better presentation	#
#################################################################
def Norm(i):

    if i<10:
        return "0" + str(i)
    else:
        return str(i)

#################################################################################
# Name        : Hex8(s)                                                         #
# Input       : String [0,255]                                                  #
# Output      : "ERROR" or 0x'0'String                                          #
# Description : Format the hexa string for better presentation or set an error  #
#################################################################################
def Hex8(s):
    
    output = ""
    if (int(s) < 256) and (int(s) >= 0):
        if int(s) < 16:
            output = "0" + hex(int(s))[2:].upper()
        else:
            output = hex(int(s))[2:].upper()
    else:
        return "ERROR"

    return "0x" + output + "u"

#################################################################################
# Name        : Hex32(s)                                                        #
# Input       : String [0,FFFFFFFF]                                             #
# Output      : "ERROR" or 0xString                                             #
# Description : Format the hexa string for better presentationor set an error   #
#################################################################################
def Hex32(s):

    if len(s) == 8:
        return "0x" + s
    else:
        return "ERROR"

########################################################################################################
#                                     Constant Variable Definition                                     #
########################################################################################################

########################################################################################################
#                                             Main Function                                            #
########################################################################################################

Error = [] #Stock the Error if the .h file can't be created

#Read the template file and split it to add needed information

NVP_Generated_Calibration_template_file = open("../../../../../Components/Application/Autoliv/NVP/Scripts/Nvp_MemoryMapping_Template.h", "r")
Template = []
for line in NVP_Generated_Calibration_template_file:
    Template.append(line)
NVP_Generated_Calibration_template_file.close()

for line in Template:
    if line.find("::") != -1:
        StartTag = line.find("::")
        EndTag = line[(StartTag+2):].find("::")
        if line[(StartTag+2):(StartTag+2)+EndTag] == "MAJOR_VERSION":
            MAJOR_VERSION_line = Template.index(line)
            MAJOR_VERSION_Col = StartTag
            MAJOR_VERSION_Size = EndTag + 4
        elif line[(StartTag+2):(StartTag+2)+EndTag] == "MINOR_VERSION":
            MINOR_VERSION_line = Template.index(line)
            MINOR_VERSION_Col = StartTag
            MINOR_VERSION_Size = EndTag + 4
        elif line[(StartTag+2):(StartTag+2)+EndTag] == "SUBVERSION":
            SUBVERSION_line = Template.index(line)
            SUBVERSION_Col = StartTag
            SUBVERSION_Size = EndTag + 4
        elif line[(StartTag+2):(StartTag+2)+EndTag] == "ROM_START_ADDRESS":
            ROM_line = Template.index(line)
            ROM_Col = StartTag
            ROM_Size = EndTag + 4
        elif line[(StartTag+2):(StartTag+2)+EndTag] == "CALIBRATION_START_ADDRESS":
            CALIBRATION_line = Template.index(line)
            CALIBRATION_Col = StartTag
            CALIBRATION_Size = EndTag + 4
        elif line[(StartTag+2):(StartTag+2)+EndTag] == "RAM_SHADOW_START_ADDRESS":
            RAM_SHADOW_line = Template.index(line)
            RAM_SHADOW_Col = StartTag
            RAM_SHADOW_Size = EndTag + 4
        elif line[(StartTag+2):(StartTag+2)+EndTag] == "DATE":
            Date_Time_Line = Template.index(line)
            Date_Time_Col = StartTag


#Start the .xml parser

mydoc = ET.parse("../../../../../Components/Application/Autoliv/NVP/Config/NVP_Layout/GlobalConfiguration.xml")
root = mydoc.getroot()

#Extract information

VariableValidity = True

aStartAddress = []

aStartAddress.append(Hex32(root[GlobalConfiguration_Tag_StartAddress][GlobalConfiguration_Tag_Calibration].text))
aStartAddress.append(Hex32(root[GlobalConfiguration_Tag_StartAddress][GlobalConfiguration_Tag_RamShadow].text))
aStartAddress.append(Hex32(root[GlobalConfiguration_Tag_StartAddress][GlobalConfiguration_Tag_ROM].text))

for s in aStartAddress:
    if s == "ERROR":
        if aStartAddress.index(s) == 0:
            Address_in_Error = "Calibration"
        elif aStartAddress.index(s) == 1:
            Address_in_Error = "RamShadow"
        elif aStartAddress.index(s) == 2:
            Address_in_Error = "ROM"
        VariableValidity = False
        Error.append("The address " + Address_in_Error + " in GlobalConfiguration.xml is not conform.")
        Error.append("Address is not a 32 bites string.")

aVersion = []
           
aVersion.append(Hex8(root[GlobalConfiguration_Tag_Version][GlobalConfiguration_Tag_Major].text))
aVersion.append(Hex8(root[GlobalConfiguration_Tag_Version][GlobalConfiguration_Tag_Minor].text))
aVersion.append(Hex8(root[GlobalConfiguration_Tag_Version][GlobalConfiguration_Tag_Subversion].text))

for s in aVersion:
    if s == "ERROR":
        if aVersion.index(s) == 0:
            Version_in_Error = "Major"
        elif aVersion.index(s) == 1:
            Version_in_Error = "Minor"
        elif aVersion.index(s) == 2:
            Version_in_Error = "Subversion"
        VariableValidity = False
        Error.append("The version " + Version_in_Error + " in GlobalConfiguration.xml is not conform.")
        Error.append("Version is not in range [0;255].")

#Compute Variable

if VariableValidity == True:

    #Update Time and Date
    date = datetime.datetime.now()
    SDate = Norm(date.day) + "/" + Norm(date.month) + "/" + str(date.year) + " / " + Norm(date.hour) + ":" + Norm(date.minute) + ":" + Norm(date.second)
    Template[Date_Time_Line] = Template[Date_Time_Line][:Date_Time_Col] + SDate + "\n"

    #Update Version
    Template[MAJOR_VERSION_line] = Template[MAJOR_VERSION_line][:MAJOR_VERSION_Col] + aVersion[GlobalConfiguration_Tag_Major] + Template[MAJOR_VERSION_line][(MAJOR_VERSION_Col + MAJOR_VERSION_Size):]
    Template[MINOR_VERSION_line] = Template[MINOR_VERSION_line][:MINOR_VERSION_Col] + aVersion[GlobalConfiguration_Tag_Minor] + Template[MINOR_VERSION_line][(MINOR_VERSION_Col + MINOR_VERSION_Size):]
    Template[SUBVERSION_line] = Template[SUBVERSION_line][:SUBVERSION_Col] + aVersion[GlobalConfiguration_Tag_Subversion] + Template[SUBVERSION_line][(SUBVERSION_Col + SUBVERSION_Size):]

    #Update StartAdress
    Template[ROM_line] = Template[ROM_line][:ROM_Col] + aStartAddress[GlobalConfiguration_Tag_ROM] + Template[ROM_line][(ROM_Col + ROM_Size):]
    Template[CALIBRATION_line] = Template[CALIBRATION_line][:CALIBRATION_Col] + aStartAddress[GlobalConfiguration_Tag_Calibration] + Template[CALIBRATION_line][(CALIBRATION_Col + CALIBRATION_Size):]
    Template[RAM_SHADOW_line] = Template[RAM_SHADOW_line][:RAM_SHADOW_Col] + aStartAddress[GlobalConfiguration_Tag_RamShadow] + Template[RAM_SHADOW_line][(RAM_SHADOW_Col + RAM_SHADOW_Size):]
    
            
#Write NVP_Generated_Calibration.h File
if (VariableValidity == True):
    NVP_Generated_Calibration_file = open("../../../../../Components/Application/Autoliv/NVP/Implementation/inc/Nvp_MemoryMapping.h", "w")
    for i in range(len(Template)):
        NVP_Generated_Calibration_file.write(Template[i])
    NVP_Generated_Calibration_file.close()
else:
    Errorfile = open("../../../../../Components/Application/Autoliv/NVP/Implementation/inc/Nvp_MemoryMappingh.log", "w")
    for i in range(len(Error)):
        Errorfile.write(Error[i])
        Errorfile.write("\n")
    Errorfile.close()

