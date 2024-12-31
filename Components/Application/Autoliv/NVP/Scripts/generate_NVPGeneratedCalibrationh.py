########################################################################################################
#                                       External Function Import                                       #
########################################################################################################
import xml.etree.ElementTree as ET
import datetime
import os
from TagXML_for_python_script import Calibration_Tag_Nb_Block, Calibration_Tag_Nb_Variable, Calibration_Tag_Name_of_Block, Calibration_Tag_Type_of_Variable, Calibration_Tag_Alias_In_RAM, Calibration_Tag_Array, Calibration_Tag_NB_Data, Calibration_Tag_Address_of_Variable

print("***generate_NVPGenerateCalibrationh.py***") 
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

NVP_Generated_Calibration_template_file = open("../../../../../Components/Application/Autoliv/NVP/Scripts/Nvp_Generated_Calibration_template.h", "r")
Template = []
for line in NVP_Generated_Calibration_template_file:
    Template.append(line)
NVP_Generated_Calibration_template_file.close()

for line in Template:
    if line.find("::") != -1:
        StartTag = line.find("::")
        EndTag = line[(StartTag+2):].find("::")
        if line[(StartTag+2):(StartTag+2)+EndTag] == "VARIABLE_DEF":
            Start_of_definition_line = Template.index(line)
            Start_of_definition_Col = StartTag
        elif line[(StartTag+2):(StartTag+2)+EndTag] == "DATE":
            Date_Time_Line = Template.index(line)
            Date_Time_Col = StartTag
        elif line[(StartTag+2):(StartTag+2)+EndTag] == "NB_BLOCK":
            Calib_NB_Block_Line = Template.index(line)
            Calib_NB_Block_Col = StartTag
        elif line[(StartTag+2):(StartTag+2)+EndTag] == "MAJOR":
            Calib_Vers_Major_Line = Template.index(line)
            Calib_Vers_Major_Col = StartTag
        elif line[(StartTag+2):(StartTag+2)+EndTag] == "MINOR":
            Calib_Vers_Minor_Line = Template.index(line)
            Calib_Vers_Minor_Col = StartTag
        elif line[(StartTag+2):(StartTag+2)+EndTag] == "SUB":
            Calib_Vers_Sub_Line = Template.index(line)
            Calib_Vers_Sub_Col = StartTag

TemplateHeader = Template[:Start_of_definition_line-1]
TemplateFooter = Template[Start_of_definition_line+1:]

#Start the .xml parser

# Get Calibration layout version
mydoc = ET.parse('../../../../../Components/Application/Autoliv/NVP/Config/NVP_Layout/GlobalConfiguration.xml')
root = mydoc.getroot()

#import all wanted data from GlobalConfiguration.xml filxe
for child in root:
   if('Version' == child.tag):
      if ('Calib' == child.attrib['name']):
         MajorVersion = child.find('Major').text
         MinorVersion = child.find('Minor').text
         SubversionVersion = child.find('Subversion').text

mydoc = ET.parse("../../../../../Components/Application/Autoliv/NVP/Config/NVP_Layout/Calibration.xml")
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
            Error.append('The number of Variable is not consistency with he number of instanciate Variable, block :' + Block[Calibration_Tag_Name_of_Block].text)
    
else:
    VariableValidity = False
    Error.append('Nb_Block calculate : ' + str(i))
    Error.append('Nb_block in XML file : ' + root[Calibration_Tag_Nb_Block].text)
    Error.append('The number of block is not consistency with he number of instanciate block')

	
#Compute Variable

if VariableValidity == True:

    #Update Number of Block
    TemplateHeader[Calib_NB_Block_Line] = TemplateHeader[Calib_NB_Block_Line][:Calib_NB_Block_Col] + root[Calibration_Tag_Nb_Block].text + 'u\n'

    #Update Calibration layout version
    TemplateHeader[Calib_Vers_Major_Line] = TemplateHeader[Calib_Vers_Major_Line][:Calib_Vers_Major_Col] + "((uint8) "+ MajorVersion + ')\n'
    TemplateHeader[Calib_Vers_Minor_Line] = TemplateHeader[Calib_Vers_Minor_Line][:Calib_Vers_Minor_Col] + "((uint8) "+ MinorVersion + ')\n'
    TemplateHeader[Calib_Vers_Sub_Line] = TemplateHeader[Calib_Vers_Sub_Line][:Calib_Vers_Sub_Col] + "((uint8) "+ SubversionVersion + ')\n'

    #Update Time and Date
    date = datetime.datetime.now()
    SDate = Norm(date.day) + "/" + Norm(date.month) + "/" + str(date.year) + " / " + Norm(date.hour) + ":" + Norm(date.minute) + ":" + Norm(date.second)
    TemplateHeader[Date_Time_Line] = TemplateHeader[Date_Time_Line][:Date_Time_Col] + SDate + "\n"
    
    TemplateVariable = []

    for Block in root.iter('Block'):

        for Variable in Block.iter('Variable'):

            #Write the type
            TemplateVariable.append('\n')
            strVariable = "__no_init const " + Variable[Calibration_Tag_Type_of_Variable].text

            #Write the Name if existing
            if Variable[Calibration_Tag_Alias_In_RAM].text == None:
                Variable_Name = "UNDEFINED"
            else:
                Variable_Name = Variable[Calibration_Tag_Alias_In_RAM].text

            #Write if necessary the size of the array
            if Variable[Calibration_Tag_Array].text == "True":
                Variable_Name = Variable_Name + "[" + Variable[Calibration_Tag_NB_Data].text + "]"
 
            #compute the name to the current line
            strVariable = strVariable + "\t" + Variable_Name
            t=0
            #need to align the address for better visualization
            for nb in range(14 - int(len(Variable_Name)/4)):
                t=t+1
                strVariable = strVariable + '\t'
            
            strVariable = strVariable + ' __AT __CALIBRATION__(0x' + (Variable[Calibration_Tag_Address_of_Variable].text)[5:] + ');'
            strVariable = strVariable + '\n'
            TemplateVariable.append(strVariable)
            

#Write NVP_Generated_Calibration.h File
if (VariableValidity == True and LineConstruction == True):
    NVP_Generated_Calibration_file = open("../../../../../Components/Application/Autoliv/NVP/Implementation/inc/Nvp_Generated_Calibration.h", "w")
    for i in range(len(TemplateHeader)):
        NVP_Generated_Calibration_file.write(TemplateHeader[i])
    for i in range(len(TemplateVariable)):
        NVP_Generated_Calibration_file.write(TemplateVariable[i])
    for i in range(len(TemplateFooter)):
        NVP_Generated_Calibration_file.write(TemplateFooter[i])
    NVP_Generated_Calibration_file.close()
else:
    Errorfile = open("../../../../../Components/Application/Autoliv/NVP/Implementation/inc/Nvp_Generated_Calibrationh.log", "w")
    for i in range(len(Error)):
        Errorfile.write(Error[i])
        Errorfile.write("\n")
    Errorfile.close()

