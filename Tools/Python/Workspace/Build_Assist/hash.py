#!/usr/bin/env python
# _*_ coding:utf-8 _*_
__author__ = 'LS'

import hashlib
import array
import os
import sys
import string

if __name__ == '__main__':
	srcFile = open( sys.argv[1], 'r')
	hex_string = srcFile.readlines()
	srcFile.close();
	hex_str = ''.join(hex_string)
	hex_str = hex_str.strip()
	hex_str = hex_str.replace("\n","")
	
	fvbf=open(sys.argv[2],"rb")
	s=fvbf.read()
	fvbf.close()
    
	allbytes = bytearray(s)
	start_address =  allbytes[s.find(b'verification_block_start') + 29 :s.find(b'verification_block_start')+37]
	block_length =  allbytes[s.find(b'verification_block_length') + 30 :s.find(b'verification_block_length')+38]
	hex_str = start_address.decode() + block_length.decode() + hex_str
#	print("hash bufer" + hex_str)
	verify_bytes = bytearray.fromhex(hex_str)
	m = hashlib.sha256(verify_bytes)
	roothash = m.hexdigest()
#	print(sys.argv[2] + " root hash "+ roothash)

	allbytes[s.find(b'verification_block_root_hash'):s.find(b'verification_block_root_hash')+98] = b'verification_block_root_hash' + b' = 0x' + str(roothash).encode("utf-8") + b';'
	new_filenam = sys.argv[3]
	output_file = open(new_filenam,"wb")
	output_file.write(allbytes)
	output_file.close()


