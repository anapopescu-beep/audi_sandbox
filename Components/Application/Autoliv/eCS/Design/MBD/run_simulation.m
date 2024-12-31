%Start a targetlink simulation
%Start simulation time measurement
delete log.txt;

% Specify Excel file name
file = 'S:/Components/Application/Autoliv/eCS/Design/MBD/20200319_eCS_Simulation_package/Simulation/Simulation_Results.xlsx';

% Open Excel Automation server
% Excel = actxserver('Excel.Application');
% Workbooks = Excel.Workbooks;
% % Make Excel invisible
% Excel.Visible=0;
% % Open Excel file
% Workbook=Workbooks.Open(file);

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

%     fid = fopen('Simulation\\Accel_For_CAN.txt', 'w' );
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
        
        % Make the first sheet active
%         Sheets = Excel.ActiveWorkBook.Sheets;
%         sheet1 = get(Sheets, 'Item', sheet);
%         invoke(sheet1, 'Activate');
%         Activesheet = Excel.Activesheet;
        
        if isequal(tlSimMode,'TL_BLOCKS_HOST')    
            Results_Names={'Time', 's ball Ref','Trigger Ref','s ball TL (MIL)', 'Trigger TL (MIL)','s ball TL (SIL)', 'Trigger TL (SIL)'};
            Results_Values= [time, s_ball_REF, trigger_eCS_REF, ball_a2, trigg_a2];
            xlRange='A2';
%             ActivesheetRange = get(Activesheet,'Range',xlRange);
%             set(ActivesheetRange, 'Value', Results_Values);
            xlswrite(file,Results_Values,sheet,xlRange);
%             xlRange='A1';
%             xlswrite(file,Results_Names,sheet,xlRange);
%             xlRange='R2';
%             xlswrite(file,RunningProfile,sheet,xlRange);
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
%         invoke(Workbook,'Save');
        %fprintf(fid, 'unsigned short u16Pulse_%d_ax[%d] = {',pulsetype, size(ax_g)); 
%         fprintf(fid,'Pulse %d \n',j);
%         for k = 1: size(ax_g)
%             fprintf(fid, '%d, ', ax_g(k));
%         end
%         fprintf(fid, '\n');
%         for k = 1: size(ay_g)
%             fprintf(fid, '%d, ', ay_g(k));
%         end
%         fprintf(fid, '\n\n'); 
        fprintf('*****| All data written |***** \n\n');
        toc;
    end
    %fclose(fid);
end
endTime = toc(startTime);
fprintf('Simulation time : %.2f seconds',endTime);
diary OFF;
clear tlSubsysName tlsystems i;

% Close Excel and clean up
% invoke(Excel,'Quit');
% delete(Excel);
% clear Excel;

delete(f);
