%Start a targetlink simulation

% Specify Excel file name
file = 'S:/Components/Application/Autoliv/eCS/Design/MBD/20200319_eCS_Simulation_package/Simulation/Simulation_Results.xlsx';

% Start up Excel as an ActiveX server.
try
    % See if there is an existing instance of Excel running.
    % If Excel is NOT running, this will throw an error and send us to the catch block below.
    Excel = actxGetRunningServer('Excel.Application');
    % If there was no error, then we were able to connect to it.
catch
    % No instance of Excel is currently running.  Create a new one.
    % Normally you'll get here (because Excel is not usually running when you run this).
    Excel = actxserver('Excel.Application');   
end

Excel.visible = false;
% Tell it to not ask you for confirmation when resaving or closing the workbooks.
Excel.DisplayAlerts = false;
% Prevent beeps from sounding if we try to do something Excel doesn't like.
% 	Excel.EnableSound = false;
% Open the existing workbook named in the variable fullFileName.
invoke(Excel.Workbooks,'Open', file);

% Get handles to the Workbook and to the Worksheets collection, for convenience.
Workbook = Excel.ActiveWorkbook;
Worksheets = Workbook.sheets;

%Start simulation time measurement
startTime = tic;
tlsystems=get_tlsubsystems(bdroot);
for i=1:length(tlsystems)
   tlSubsysName = get_param(tlsystems{i}, 'Name');
end
% Deactivate 'clean code' option in order to be able to log internal data.
tl_set(bdroot,'codeopt.cleancode',0);

% Start simulation in MIL before switching to SIL
f = waitbar(0,'Simulation Starting...');
pause(.5);
for i = 0: 0
    if isequal(i,0)   
        % set simulation mode
        tlSimMode = 'TL_BLOCKS_HOST';
        tl_set_sim_mode('TlSubsystems',tlSubsysName,'simmode','TL_BLOCKS_HOST','simmode','TL_BLOCKS_HOST');
    else
        % set simulation mode
        tlSimMode = 'TL_CODE_HOST';
        tl_set_sim_mode('TlSubsystems',tlSubsysName,'simmode','TL_CODE_HOST','simmode','TL_CODE_HOST');
    end

    % Build C code in SIL mode
    if isequal(tlSimMode,'TL_CODE_HOST')
        tl_build_host;
    end

    % Run all pulses simulation
    for j = 2:2
        if isequal(tlSimMode,'TL_BLOCKS_HOST')
            waitbar(((20*i)+j)/40,f,sprintf('Pulse %d MIL simulation', j));
        else
            waitbar(((20*i)+j)/40,f,sprintf('Pulse %d SIL simulation', j));
        end
        pulsetype = j;
        diary log.txt;
        diary ON;
        fprintf('*****| Start %s simulation for pulse %d |*****\n\n',tlSimMode, pulsetype);
        tic;
        tl_sim(bdroot);

        disp('End of Simulation');
        %end of simulation time measurement
        toc;

        tic;
        % Write capture workspace data into Excel file
        disp('Write Data to Excel file...')
        %filename = 'S:/Components/Application/Autoliv/eCS/Design/MBD/20200319_eCS_Simulation_package/Simulation/Simulation_Results.xlsx';
        
        % Select the correct sheet
        sheet=pulsetype;
        
        % Activate the selected sheet
        Worksheets.Item(sheet).Activate;
        
        if isequal(tlSimMode,'TL_BLOCKS_HOST')    
            Results_Names={'Time', 's ball Ref','Trigger Ref','s ball TL (MIL)', 'Trigger TL (MIL)','s ball TL (SIL)', 'Trigger TL (SIL)'};
            Results_Values= [time, s_ball_REF, trigger_eCS_REF, ball_a2, trigg_a2];
            xlRange='A2:E9999';
            ActivesheetRange = get(Excel.ActiveSheet,'Range',xlRange);
            set(ActivesheetRange, 'Value', Results_Values);
            xlRange='A1:H1';
            ActivesheetRange = get(Excel.ActiveSheet,'Range',xlRange);
            set(ActivesheetRange, 'Value', Results_Names);
            xlRange='R2:W9999';
            ActivesheetRange = get(Excel.ActiveSheet,'Range',xlRange);
            set(ActivesheetRange, 'Value', RunningProfile);
        else
            Results_Names={'Time', 's ball Ref','Trigger Ref','s ball TL (MIL)', 'Trigger TL (MIL)','s ball TL (SIL)', 'Trigger TL (SIL)', 'Trigg Cnt'};
            Results_Values_ref= [time, s_ball_REF, trigger_eCS_REF];
            Results_Values_SIL = [ball_a2, trigg_a2];
            xlRange='A1';
            xlswrite(file,Results_Names,sheet,xlRange);
            xlRange='A2';
            xlswrite(file,Results_Values_ref,sheet,xlRange);
            xlRange='F2';
            xlswrite(file,Results_Values_SIL,sheet,xlRange);
            xlRange='H2';
            xlswrite(file,triggercounts,sheet,xlRange);
            xlRange='K2';
            xlswrite(file,triggers_times,sheet,xlRange);
        end
        % Save File
        invoke(Excel.ActiveWorkbook,'Save');
        fprintf('*****| All data written |***** \n\n');
        toc;
    end
end
endTime = toc(startTime);
fprintf('Simulation time : %.2f seconds',endTime);
diary OFF;
clear tlSubsysName tlsystems i;

% Close Excel and clean up
Excel.Quit;
Excel.delete;
clear Excel;

delete(f);
