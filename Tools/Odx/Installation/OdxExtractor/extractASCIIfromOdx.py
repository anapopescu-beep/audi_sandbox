import sys
import os
def main():
    if len(sys.argv) > 0:
        f = open(sys.argv[1], "r")
        path = os.path.dirname(sys.argv[1])
        #print("path = ", path)
        all = f.read()
        sigstartindex = 0
        sigstopindex = 0
        done = False
        first = True
        while done == False:
           sigstartindex = all.find('<FW-SIGNATURE TYPE="A_BYTEFIELD">', sigstartindex+1)
           #print("Start index = ", sigstartindex)
           if sigstartindex != -1:
              sigstopindex = all.find('</FW-SIGNATURE>', sigstartindex)
              #print("Stop index = ", sigstopindex) 
              if (sigstopindex - sigstartindex + 33 )> 300:
                 #print(all[sigstartindex+33:sigstopindex])
                 sig = all[sigstartindex+33:sigstopindex]
                 crcstartindex = all.find('<FW-CHECKSUM TYPE="A_BYTEFIELD">', sigstopindex)
                 crcstopindex = all.find('</FW-CHECKSUM>', crcstartindex)
                 #print(all[crcstartindex+32:crcstopindex])
                 crc = all[crcstartindex+32:crcstopindex]
                 if len(sys.argv) > 1:
                     if first == True:
                        filename = sys.argv[2]
                        first = False
                     else:
                        filename = sys.argv[3]
                     if path == "":
                        final = "sig_"+filename+".bin"
                     else:
                        final = path +"\\" + "sig_"+filename+".bin"
                 else:
                     if first == True:
                        filename = "app"
                        first = False
                     else:
                        filename = "calib"
                     if path == "":
                        final = "sig_"+filename+".bin"
                     else:
                        final = path +"\\" + "sig_"+filename+".bin"
                 #print(final)
                 dest = open(final, "wb")
                 dest.write(bytes.fromhex(sig))
                 dest.write(bytes.fromhex(crc))
                 dest.close()
           else:
              done = True         

        done = False
        first = True
        startindex = 0
        stopindex = 0
        while done == False:
           startindex = all.find('<DATA>', startindex+1)
           #print("Data Start index = ", startindex)
           if startindex != -1:
              stopindex = all.find('</DATA>',startindex)
              #print("Stop Start index = ", stopindex)
              if (stopindex - startindex + 6 )> 300:
                 #print(all[startindex+6:stopindex])
                 data = all[startindex+6:stopindex]

                 if len(sys.argv) > 1:
                     if first == True:
                        filename = sys.argv[2]
                        first = False
                     else:
                        filename = sys.argv[3]
                     if path == "":
                        final = filename+".bin"
                     else:
                        final = path +"\\" +filename+".bin"
                 else:
                     if first == True:
                        filename = "app"
                        first = False
                     else:
                        filename = "calib"
                     if path == "":
                        final = filename+".bin"
                     else:
                        final = path +"\\" +filename+".bin"
                 #print(final)
                 dest = open(final, "wb")
                 dest.write(bytes.fromhex(data))
                 dest.close()
           else:
              done = True
              
        f.close()

if __name__ == '__main__':
    main()