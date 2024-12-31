%Start a targetlink simulation
%Start simulation time measurement

startTime = tic;
tlsystems=get_tlsubsystems(bdroot);
for i=1:length(tlsystems)
   tlSubsysName = get_param(tlsystems{i}, 'Name');
end

% Start simulation in MIL before switching to SIL
f = waitbar(0,'Simulation Starting...');
pause(.5);

tlSimMode = 'TL_CODE_HOST';
tl_set_sim_mode('TlSubsystems',tlSubsysName,'simmode','TL_BLOCKS_HOST','simmode','TL_BLOCKS_HOST');

% Build C code in SIL mode
if isequal(tlSimMode,'TL_CODE_HOST')
    tl_build_host;
end

fid = fopen('Simulation\\Rotation_Results.txt', 'w' );       
% Run simulation from 40 to 50°
i = 0;
for angle = 40: 40
    for run = 0:1
        Forced_Oscillation = run;
        
        fprintf(fid,'***************************************************************************\n');
        fprintf(fid,'Rotation angle: %d - Oscillations: %d \n', angle, Forced_Oscillation);
        fprintf(fid,'***************************************************************************\n');

        waitbar((41-angle)/2,f,sprintf('MIL simulation with a rotation of %d°', angle));

        phi_pulse_rotation = angle;

        fprintf('*****| Start %s simulation with an angle of %d° |*****\n\n',tlSimMode, angle);
        tic;
        tl_sim(bdroot);

        disp('End of Simulation');
        %end of simulation time measurement
        toc;

        tic;
        % Write capture workspace data into Excel file
        disp('Write Data to file...')
        fprintf(fid,'Triggering time %f \n',triggers_times);
        fprintf(fid,'----------------------------------------\n');
        fprintf(fid,'Triggering position %f \n',triggers_s.Data);
        i = i + 1;

        fprintf('*****| All data written |***** \n\n');
        toc;
    end
end

endTime = toc(startTime);
fprintf('Simulation time : %.2f seconds',endTime);
diary OFF;
clear tlSubsysName tlsystems i;
delete(f);