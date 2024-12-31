########################################################################################################
#                                       External Function Import                                       #
########################################################################################################
import xml.etree.ElementTree as ET
import datetime
import os
from TagXML_for_python_script import NvmDefault_Tag_Nb_Block, NvmDefault_Tag_Nb_Variable, NvmDefault_Tag_Name_of_Block, NvmDefault_Tag_Fixed_Block, NvmDefault_Tag_ROM_Alias, NvmDefault_Tag_RAM_Alias, NvmDefault_Tag_Address_of_Block

print("***generate_NVPAliash.py***") 
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

########################################################################################################
#                                     Constant Variable Definition                                     #
########################################################################################################

########################################################################################################
#                                             Main Function                                            #
########################################################################################################

Error = [] #Stock the Error if the .h file can't be created


#Read the template file and split it to add needed information

NVP_Alias_template_file = open("../../../../../Components/Application/Autoliv/NVP/Scripts/Nvp_alias_Template.h", "r")
Template = []
for line in NVP_Alias_template_file:
    Template.append(line)
NVP_Alias_template_file.close()

for line in Template:
    if line.find("::") != -1:
        StartTag = line.find("::")
        EndTag = line[(StartTag+2):].find("::")
        if line[(StartTag+2):(StartTag+2)+EndTag] == "TRESOS_ALIAS":
            Start_of_definition_line = Template.index(line)
            Start_of_definition_Col = StartTag
        elif line[(StartTag+2):(StartTag+2)+EndTag] == "DATE":
            Date_Time_Line = Template.index(line)
            Date_Time_Col = StartTag

TemplateHeader = Template[:Start_of_definition_line-1]
TemplateFooter = Template[Start_of_definition_line+1:]

#Start the .xml parser

mydoc = ET.parse("../../../../../Components/Application/Autoliv/NVP/Config/NVP_Layout/NvmDefault.xml")
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

        if Block[NvmDefault_Tag_Fixed_Block].text != "True" :
            
            TemplateVariable.append('\n')

            #Set the Name if existing
            RAMAlias = Block[NvmDefault_Tag_RAM_Alias].text
            ROMAlias = Block[NvmDefault_Tag_ROM_Alias].text
            
            if RAMAlias != None :
                #delete the "(void*)" cast if necessary
                if RAMAlias[0:7]=="(void*)":
                    RAMAlias = RAMAlias [7:]

                #need to align the address for better visualization
                RAMalignement = ""
                for nb in range(16 - int((len(RAMAlias)+1)/4)):
                    RAMalignement = RAMalignement + '\t'

                #Write the type
                if RAMAlias != "NULL_PTR":
                    TemplateVariable.append("#define\t" + RAMAlias + RAMalignement + "__RAM_SHADOW__(0x" + (Block[NvmDefault_Tag_Address_of_Block].text)[5:] + ")\n")
            else:
                TemplateVariable.append("/* RAM Alias is not define for block : " + Block[NvmDefault_Tag_Name_of_Block].text + " */\n")

            if ROMAlias != None :
                #delete the "(void*)" cast if necessary
                if ROMAlias[0:7]=="(void*)":
                    ROMAlias = ROMAlias [7:]

                #need to align the address for better visualization
                ROMalignement = ""
                for nb in range(16 - int((len(ROMAlias)+1)/4)):
                    ROMalignement = ROMalignement + '\t'
                
                #Write the type
                if ROMAlias != "NULL_PTR":
                    TemplateVariable.append("#define\t" + ROMAlias + ROMalignement + "__ROM_DEFAULT__(0x" + (Block[NvmDefault_Tag_Address_of_Block].text)[5:] + ")\n")
            
            else:
                TemplateVariable.append("/* ROM Alias is not define for block : " + Block[NvmDefault_Tag_Name_of_Block].text + " */\n")

#Write NVP_Alais.h File
if (VariableValidity == True and LineConstruction == True):
    NVP_Alais_file = open("../../../../../Components/Application/Autoliv/NVP/Implementation/inc/Nvp_alias.h", "w")
    for i in range(len(TemplateHeader)):
        NVP_Alais_file.write(TemplateHeader[i])
    for i in range(len(TemplateVariable)):
        NVP_Alais_file.write(TemplateVariable[i])
    for i in range(len(TemplateFooter)):
        NVP_Alais_file.write(TemplateFooter[i])
    NVP_Alais_file.close()
else:
    Errorfile = open("../../../../../Components/Application/Autoliv/NVP/Implementation/inc/Nvp_aliash.log", "w")
    for i in range(len(Error)):
        Errorfile.write(Error[i])
        Errorfile.write("\n")
    Errorfile.close()

