import time
import multiprocessing
from multiprocessing import freeze_support

templateList = ["SAD_Var_Template.xml", "FSM_Var_Template.xml"]
DDList = ["SAD_DD_to_import.xml", "FSM_DD_to_import.xml"]

# Constants declaration
SOLENOID_nb = 8
INIT_val = "0 "
NBR_MAX_THREAD = 4

def parseFile(template, dd):
   fIn = open(template, "r")
   fOut = open(dd, "w")
   fInLines = fIn.readlines()

   # Parse template
   for line in fInLines:
      sCat = ""
      # Search for tags
      if (line.find("SOLENOID_NB") != -1):
         line = line.replace("SOLENOID_NB", str(SOLENOID_nb))
      elif (line.find("INIT_VAL") != -1):
         for idx in range(0, SOLENOID_nb):
            sCat += INIT_val
         line = line.replace("INIT_VAL", sCat)
      # Write into the new file
      fOut.write(line)
   # Close all streams
   fOut.close()
   fIn.close()

# time monitoring for multi processing
start_time = time.time()
# parse all files
# for idx in range(len(templateList)):
#    parseFile(templateList[idx], DDList[idx])
processes = []
nbRunningThread = 0
if __name__ == '__main__':
    freeze_support()
    # Parsing all files
    for idx in range(len(templateList)):
        # Create a process for 1 file
        p = multiprocessing.Process(target=parseFile, args=(templateList[idx], DDList[idx],))
        processes.append(p)
        p.start()
        nbRunningThread = nbRunningThread + 1
    
        print("Thread: ", nbRunningThread , " Processing file:" , templateList[idx])
        # max number of processes reached, wait until they finish before starting a new one
        if nbRunningThread >= NBR_MAX_THREAD:
            for process in processes:
                process.join()

            processes.clear()
            nbRunningThread = 0

print("--- %s seconds ---" % (time.time() - start_time))   