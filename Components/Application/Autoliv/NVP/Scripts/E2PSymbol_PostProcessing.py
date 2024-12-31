#!/usr/bin/python

# @Git Jarnvidr_Repo17
# 
# Fix bug

# re is the true life
import re

# Temp tuple
_tup = ()
# ARXM input files list
_E2PSymbolFile = "../../../../Tools/Build/Workspace/Script/out/EepSymbol.sym"


# Create / overwrite the Destination file
fOutput = open("../../../../Tools/ARIA/Config/Neeva_Configuration/TestEnvironment_Automation/ProjectLib_Development/SBE_PP4G_E2P_Symbols.ts","w")
	

#print "/***************************************************/"
fOutput.write("/***************************************************\n")
fOutput.write(" * Automatically generates file after E2P symbol generaiton\n")
fOutput.write(" * Do not change it by hand\n")
fOutput.write(" **************************************************/\n")
#print ""
fOutput.write(""+"\n")

try:
	# Load EEPROM symbol file
	fSourceData = open(_E2PSymbolFile,"r")
	fOutput.write("/***************************************************\n")
	fOutput.write(" * @File processing : EepSymbol\n")
	fOutput.write(" **************************************************/\n")
	# Source file has to be parsed
	for line in fSourceData:
		#Test if the line is empty
		if not line.strip():
				print "Empty line"
		else:
			#remove EOF < to be adapted according to system
			sLineData = line.rstrip('\n\r')
			sSubSplit = line.split(',',4)
			rCatchExp= re.compile("NVP_(.*)")
			if re.search(rCatchExp,sSubSplit[1]):
				_tup = re.search(rCatchExp,sSubSplit[1]).groups()
			fOutput.write( "const E2P_"+_tup[0]+" = 0x"+ sSubSplit[0] + ";\n")
			fOutput.write( "const E2P_"+_tup[0]+"_Size = "+ sSubSplit[2] + ";\n")

	fSourceData.close()

finally:
	fOutput.write("/***************************************************\n")
	fOutput.write(" * Post-Processing done\n")
	fOutput.write(" **************************************************/\n")
	# close file streams
	fOutput.close()
	