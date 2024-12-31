@echo off

echo "***generateCalibration.bat***"
cd /D "%~dp0"

if exist ..\\..\\..\\..\\..\\Tools\\Build_Env\\Workspace\\Outputs\\nvp\\CalibrationFlash.S00 (del ..\\..\\..\\..\\..\\Tools\\Build_Env\\Workspace\\Outputs\\nvp\\CalibrationFlash.S00)
if exist ..\\..\\..\\..\\..\\Tools\\Build_Env\\Workspace\\Outputs\\nvp\\ErrorCalibrationFlashS00.log (del ..\\..\\..\\..\\..\\Tools\\Build_Env\\Workspace\\Outputs\\nvp\\ErrorCalibrationFlashS00.log)
if exist ..\\Implementation\\src\\NVP_Generated_Calibration.c (del ..\\Implementation\\src\\NVP_Generated_Calibration.c)
if exist ..\\Implementation\\src\\NVP_Generated_Calibrationc.log (del ..\\Implementation\\src\\NVP_Generated_Calibrationc.log)
if exist ..\\Implementation\\inc\\NVP_Generated_Calibration.h (del ..\\Implementation\\inc\\NVP_Generated_Calibration.h)
if exist ..\\Implementation\\inc\\NVP_Generated_Calibrationh.log (del ..\\Implementation\\inc\\NVP_Generated_Calibrationh.log)
python generate_CalibrationFlashS00.py
python generate_NVPGeneratedCalibrationc.py
python generate_NVPGeneratedCalibrationh.py
