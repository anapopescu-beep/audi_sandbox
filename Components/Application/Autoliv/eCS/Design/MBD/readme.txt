eCS Simulation model 19.03.2020.

Copy all files to a folder.
Add this folder name (incl. subfolders) to the Matlab Path.

Files in this package:
Acc_Init_SelV1.m				-	Script to set the parameters for the acceleration sensors, not needed to execute directly, will be called by "Parameter_eCS_Algo.m"
eCS_Algo_Simulation.slx		-	Simulink Model for R2018a
eCS_Algo_Simulation_2012b.slx	-	Simulink Model for R2012b
eCS_Algo_Simulation_2016a.slx	-	Simulink Model for R2016a
Parameter_eCS_Algo.m			-	Script to set the parameters (pulse, offsetcorrection etc.). Edit the lines 8-14: substitute the path of the mat-files with the new ones from your folder structure. Then execute the script before starting the Simulink model.
Pulse							-	Folder containing all pulse data, needs to be in the Matlab Path
readme.txt						-	this file...



The eCS algo is contained in a subsystem with name "eCS Algo new", this is the algo part that has to be run on the uC!
Additionally the uC has to take care about i.e. (list not complete!):

- data aquisition and signal processing of the acceleration sensor signals (+ temperature?,--> not considered, yet)
- offset correction for the acceleration sensors (probably a high-pass filter with low cutoff-frequency) -->proposal could be taken from the model as well
- diagnostics
- ...


For additional informations, please call Heiko Hinrichs, ES2, ANG
