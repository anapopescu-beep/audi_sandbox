%% Sensor Selection
clc;

exist Select var
if  ans==0
	Select = 2;
	% 1:AD, 2:ST, 3:TDK, 4:NXP, 5:TDKIAM20685
end

% General parameters
TemperatureAmp = 0; %0 --> 25°C, 65 --> 90°C, -65 --> -40°C
TempBias = 0;
FreqTemperature = 10;
switch(Select)
    case 1
        fprintf('AD sensor selected\n');
    case 2
        fprintf('ST sensor selected\n');
    case 3
        fprintf('TDK sensor selected\n');
    case 4
        fprintf('NXP sensor selected\n');
    case 5
        fprintf('TDKIAM20685 sensor selected\n');
    otherwise
        fprintf('no sensor selected, selecting AD by default\n');
        Select = 1;
        %break;
end
%% Accelerometers' parameters
% ODR (Hz) Output Data Rate
% F_x,F_y,F_z (Hz) (Bandwidth) cut-off frequency, 2nd order filter 
% 1, AD % 2, ST, % 3, TDK % 4, NXP  % 5, TDKIAM20685
switch(Select)
    case 1
        ODR = 3200; F_x = ODR/2; F_y = ODR/2; F_z = ODR/2;
        Range = 4;        Resolution = 0.001; % 4g range
    case 2
        ODR = 1600; F_x = 400; F_y = 400; F_z = 400; 
        Range = 16;       Resolution = 0.002;
    case 3
        ODR = 1000; F_x = 218; F_y = 218; F_z = 218;
        Range = 16;        Resolution = 0.001;
        %F_x = 1100 % Hz, no LPF (Noise to be increased, ODR to increase)
    case 4
        ODR = 800; F_x = 300; F_y = 300; F_z = 300;
        Range = 8;        Resolution = 0.001;
    case 5
        ODR = 8000; F_x = 60; F_y = 60; F_z = 60; % choose 250 for the next value
        Range = 4;        Resolution = 0.000125; % (4.096/2^15)confirmed with PO on day 15/12/2021
end 
%% Accelerometers' NOISE parameters
% 1:AD, 2:ST, 3:TDK, 4:NXP, 5:TDKIAM20685
switch(Select)
    case 1
        Mean_x_noise = 0;       Mean_y_noise = Mean_x_noise;
        Var_x_noise = 0.005;    Var_y_noise = Var_x_noise;
        
        Mean_z_noise = 0;
        Var_z_noise = 0.01;
        
    case 2
        Mean_x_noise = 0;       Mean_y_noise = Mean_x_noise;
        Var_x_noise = 0.003;    Var_y_noise = Var_x_noise;
        
        Mean_z_noise = 0;
        Var_z_noise = 0.005;      
    case 3
        Mean_x_noise = 0;
        Var_x_noise = 0.005;
        
        Mean_y_noise = Mean_x_noise;
        Var_y_noise = Var_x_noise;

        Mean_z_noise = 0;
        Var_z_noise = 0.01;
    case 4
        Mean_x_noise = 0;       Mean_y_noise = Mean_x_noise;
        Var_x_noise = 0.005;    Var_y_noise = Var_x_noise;

        Mean_z_noise = 0;
        Var_z_noise = 0.01;
    case 5 % The unit is g rms
        Mean_x_noise = 4e-3; % computed as average of averages on 3 batches    
        Mean_y_noise = 4e-3; % idem 
        Mean_z_noise = 4e-3; % idem 
        Var_x_noise = 1.84e-9; % for x: average of sum of square of the standard deviation 'sigma'  
        Var_y_noise = 2.025e-09;  % idem for y
        Var_z_noise = 1.374e-09; % idem for z
end  
%% calculate 2nd order filter parameters
w_x = 2*pi*F_x;
Xi_x = 0.7;

w_y = 2*pi*F_y;
Xi_y = 0.7;

w_z = 2*pi*F_z;
Xi_z = 0.7;
%% Cross axis parameters
% 1:AD, 2:ST, 3:TDK, 4:NXP, 5:TDKIAM20685
switch(Select)
    case 1 % Done
        Cxy = 2*0.01; % 2 * typical values (max not provided)
        Cyx = 2*0.01;
        Cxz = 2*0.01;
        Czx = 2*0.01;
        Cyz = 2*0.01;
        Czy = 2*0.01;
    case 2 % not available in datasheet, Taken as TDK
        Cxy = 2*0.05; %
        Cyx = 2*0.05;
        Cxz = 2*0.05;
        Czx = 2*0.05;
        Cyz = 2*0.05;
        Czy = 2*0.05;
    case 3 % Done
        Cxy = 2*0.05; % 2 * typical values (max not provided) at 25°C
        Cyx = 2*0.05;
        Cxz = 2*0.05;
        Czx = 2*0.05;
        Cyz = 2*0.05;
        Czy = 2*0.05;
    case 4 % not available in datasheet, Taken as TDK
        Cxy = 2*0.05; %
        Cyx = 2*0.05;
        Cxz = 2*0.05;
        Czx = 2*0.05;
        Cyz = 2*0.05;
        Czy = 2*0.05;
    case 5
        % Data from DS-000182 IAM-20685-v1.1 Autoliv
        % page 11/53; 03-031 Cross-axis sensitivity
        Cxy = 1*0.017;
        Cyx = 1*0.017;
        Cxz = 1*0.017;
        Czx = 1*0.017;
        Cyz = 1*0.017;
        Czy = 1*0.017;
end 
%% Drift Parameters
% 1:AD, 2:ST, 3:TDK, 4:NXP, 5:TDKIAM20685
switch(Select)
    case 1 % Done
        % Start to start drift (g) The rest of drift after calibration and
        % trimming
        x_run_to_run_drift = 0.05;
        y_run_to_run_drift = 0.05;
        z_run_to_run_drift = 0.075;
        % drift temp coefficient (g/°C) (Typical
        x_temp_co_drift = 0.0005;
        y_temp_co_drift = 0.0005;
        z_temp_co_drift = 0.00075;
        % (Temperature max drift)
        x_max_temp_drift = 0.125;
        y_max_temp_drift = 0.125;
        z_max_temp_drift = 0.2;
                
    case 2
        % Start to start drift (g)
        x_run_to_run_drift = 0.02;
        y_run_to_run_drift = 0.02;
        z_run_to_run_drift = 0.02;
        % drift temp coefficient (g/°C)
        x_temp_co_drift = 0.0002;
        y_temp_co_drift = 0.0002;
        z_temp_co_drift = 0.0002;
        % (Temperature max drift)
        x_max_temp_drift = 0.300;
        y_max_temp_drift = 0.300;
        z_max_temp_drift = 0.300;
    case 3
        % Start to start drift (g)
        x_run_to_run_drift = 0.05;
        y_run_to_run_drift = 0.05;
        z_run_to_run_drift = 0.05;
        % drift temp coefficient (g/°C)
        x_temp_co_drift = 0.0008; %(+-50mg 25-85°C)
        y_temp_co_drift = 0.0008;
        z_temp_co_drift = 0.0008;
        % (Temperature max drift)
        x_max_temp_drift = 0.130;
        y_max_temp_drift = 0.130;
        z_max_temp_drift = 0.130;
    case 4
        % Start to start drift (g)
        x_run_to_run_drift = 0.03;
        y_run_to_run_drift = 0.03;
        z_run_to_run_drift = 0.03;
        % drift temp coefficient (g/°C)
        x_temp_co_drift = 0.0003; %(+-50mg 25-85°C)
        y_temp_co_drift = 0.0003;
        z_temp_co_drift = 0.0003;
        % (Temperature max drift) (0.08 for 2 g range, 0.125 used for 8g range) 
        x_max_temp_drift = 0.125;
        y_max_temp_drift = 0.125;
        z_max_temp_drift = 0.125;
    case 5
        % Start to start drift (g)
        x_run_to_run_drift = 0.0;
        y_run_to_run_drift = 0.0;
        z_run_to_run_drift = 0.0;
        % drift temp coefficient (g/°C)
        x_temp_co_drift = 0.000; %(+-50mg 25-85°C)
        y_temp_co_drift = 0.000;
        z_temp_co_drift = 0.000;
        % (Temperature max drift) (0.08 for 2 g range, 0.125 used for 8g range) 
        % These data are worst global drift @ 105°C computed from
        % Quadratic sum of Datasheet [03-019] & [03-020] & [03-021], 
        % Board soldering effect included, from -40C to 105C, 
        % over lifetime (10 years)
        x_max_temp_drift = 0.061; % unit is g
        y_max_temp_drift = 0.061; % idem
        z_max_temp_drift = 0.13;  % idem
end  

%% 
%H(s)= w^2/ (s^2+2*Xi*ws+w^2) Low Pass
%H(s)= s^2/ (s^2+2*Xi*ws+w^2) High pass
%H(s)= s^2/ (s^2+2*Xi*Whs+Wh^2) High pass

%Maximum Sensor offset values in g - for software-offset-correction
switch(Select)
    case 1
        MaxSensorOffset=0.3;
    case 2
        MaxSensorOffset=0.3;
    case 3
        MaxSensorOffset=0.3;
    case 4
        MaxSensorOffset=0.3;
    case 5
        MaxSensorOffset=0; % not used in Sensor Simulink model of Ziad
                           % eCS_Algo_Simulation_2016a.slx
    otherwise
        MaxSensorOffset=0.3;
end

%offset-behaviour of sensors on (1) or off (0)
x_offset_enable=0;
y_offset_enable=0;
z_offset_enable=0;