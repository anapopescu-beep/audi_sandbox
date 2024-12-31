@echo off

echo "***generateMainConfiguration.bat***"
cd /D "%~dp0"

if exist ..\\..\\..\\..\\..\\Components\\Application\\Autoliv\\NVP\\Implementation\\inc\\Nvp_MemoryMapping.h (del ..\\..\\..\\..\\..\\Components\\Application\\Autoliv\\NVP\\Implementation\\inc\\Nvp_MemoryMapping.h)
if exist ..\\..\\..\\..\\..\\Components\\Application\\Autoliv\\NVP\\Implementation\\inc\\Nvp_MemoryMappingh.log (del ..\\..\\..\\..\\..\\Components\\Application\\Autoliv\\NVP\\Implementation\\inc\\Nvp_MemoryMappingh.log)
python generate_NVPMemoryMappingh.py
