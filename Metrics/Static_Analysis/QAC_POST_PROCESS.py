# -----------------------------------------
# Post Process script of QAC Analisys tool
# Written by Lucian Ardeleanu
# -----------------------------------------

import os
import sys
import re

# Get current dir path
current_dir = os.getcwd()

# Get local project path
project_path = 'S:\\'


# ================ REPLACE BACK S: DRIVE  ==================
#read input file
fin = open("PP4G_QAC_Analysis.py", "rt")

#read file contents to string
data = fin.read()

#replace all occurrences of the required string
data = data.replace(re.escape(project_path) + r'\\', r'S:\\')

#close the input file
fin.close()

print('Script QAC Post Process run successfully!')
