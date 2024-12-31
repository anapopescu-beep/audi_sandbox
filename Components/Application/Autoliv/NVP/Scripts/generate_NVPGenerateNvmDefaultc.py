########################################################################################################
#                                       External Function Import                                       #
########################################################################################################
import xml.etree.ElementTree as ET
import datetime
import os
from TagXML_for_python_script import NvmDefault_Tag_Nb_Block, NvmDefault_Tag_Nb_Variable, NvmDefault_Tag_Name_of_Block, NvmDefault_Tag_NvM_not_programmed, NvmDefault_Tag_Fixed_Block, NvmDefault_Tag_Address_of_Block, NvmDefault_Tag_Tresos_Size

print("***generate_NVPGenerateNvmDefaultc.py***") 
os.chdir(os.path.dirname(os.path.realpath(__file__)))

#################################################################
# Name        : Norm(i)						#
# Input       : Number [0,99]					#
# Output      : Number in String 2 string			#
# Description : add a 0 at the string for better presentation	#
#################################################################
def Norm(i):

    if i<10:
        return "0" + str(i)
    else:
        return str(i)

########################################################################################################
#                                     Constant Variable Definition                                     #
########################################################################################################

########################################################################################################
#                                             Main Function                                            #
########################################################################################################

Error = [] #Stock the Error if the .c file can't be created

#Read the template file and split it, to add needed information
NVP_Generated_Eeprom_template_file = open("../../../../../Components/Application/Autoliv/NVP/Scripts/Nvp_Generated_NvmDefault_template.c", "r")
Template = []
for line in NVP_Generated_Eeprom_template_file:
    Template.append(line)
NVP_Generated_Eeprom_template_file.close()

for line in Template:
    if line.find("::") != -1:
        StartTag = line.find("::")
        EndTag = line[(StartTag+2):].find("::")
        if line[(StartTag+2):(StartTag+2)+EndTag] == "BLOCK_DEF":
            Start_of_definition_line = Template.index(line)
            Start_of_definition_Col = StartTag
        elif line[(StartTag+2):(StartTag+2)+EndTag] == "DATE":
            Date_Time_Line = Template.index(line)
            Date_Time_Col = StartTag

TemplateHeader = Template[:(Start_of_definition_line-1)]
TemplateFooter = Template[(Start_of_definition_line+1):]

#Start the .xml parser

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

    #Update Time and Date
    date = datetime.datetime.now()
    SDate = Norm(date.day) + "/" + Norm(date.month) + "/" + str(date.year) + " / " + Norm(date.hour) + ":" + Norm(date.minute) + ":" + Norm(date.second)
    TemplateHeader[Date_Time_Line] = TemplateHeader[Date_Time_Line][:Date_Time_Col] + SDate + "\n"

    TemplateVariable = []

    for Block in root.iter('Block'):

        #Add one block definition line by line
        TemplateVariable.append('\n')
        TemplateVariable.append("\t/* " + Block[NvmDefault_Tag_Name_of_Block].text + " */")
        TemplateVariable.append('\n')
        TemplateVariable.append("\t{")
        TemplateVariable.append('\n')

        if Block[NvmDefault_Tag_Fixed_Block].text == "True" : 
            TemplateVariable.append("\t\t0xFFFFFFFFu, /* faked RAM Address */" )
        else:
            TemplateVariable.append("\t\t0x" + Block[NvmDefault_Tag_Address_of_Block].text + "u, /* Block RAM Start Address */" )

        TemplateVariable.append('\n')
        TemplateVariable.append("\t\t" + Block[NvmDefault_Tag_Tresos_Size].text + "u, /* nvCalBlockLength */")
        TemplateVariable.append('\n')
        if Block[NvmDefault_Tag_NvM_not_programmed].text == 'False':
            TemplateVariable.append("\t\tNVP_KU8_NO_AUTO_TEST_MASK")
        else:
            TemplateVariable.append("\t\tNVP_KU8_E2P_NOT_PROGRAMMED_AT_MASK")
        TemplateVariable.append('\n')
        TemplateVariable.append("\t},")
        TemplateVariable.append('\n')

    TemplateVariable[len(TemplateVariable)-2] = "\t}"


#Write NVP_Generated_Calibration.h File
if (VariableValidity == True and LineConstruction == True):
    NVP_Generated_Eeprom_file = open("../../../../../Components/Application/Autoliv/NVP/Implementation/src/Nvp_Generated_NvmDefault.c", "w")
    for i in range(len(TemplateHeader)):
        NVP_Generated_Eeprom_file.write(TemplateHeader[i])
    for i in range(len(TemplateVariable)):
        NVP_Generated_Eeprom_file.write(TemplateVariable[i])
    for i in range(len(TemplateFooter)):
        NVP_Generated_Eeprom_file.write(TemplateFooter[i])
    NVP_Generated_Eeprom_file.close()
else:
    Errorfile = open("../../../../../Components/Application/Autoliv/NVP/Implementation/src/Nvp_Generated_NvmDefaultc.log", "w")
    for i in range(len(Error)):
        Errorfile.write(Error[i])
        Errorfile.write("\n")
    Errorfile.close()

