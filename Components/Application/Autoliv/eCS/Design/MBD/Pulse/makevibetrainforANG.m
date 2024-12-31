A=which('autolivsteeringwheeltimehistoryprocess');
if isempty(A)
    % Add "standard CDM tools" to the end of user's PATH
    addpath(genpath('\\na.autoliv.int\common$\ATCCommon\Matlab\Christopher Morgan'), '-end');
end
clear A
% do not remove anything above here.  Its purpose is to make sure the $PATH
% is adequate
ccc
bpx=gmw14011_sb_faft; % X direction is assumed fore/aft
bpy=gmw14011_sb_lat;  % Y direction is assumed to be lateral
bpz=gmw14011_sb_vert; % Z direction is assumed to be vertical
samplerate=5000; % 5000 samples/second.  Feel free to increase or decrease as needed
maxT=30; % 30 seconds of time history!

[signalx, time, samplerate]=bp2signal(bpx, samplerate, maxT);
[signaly]=bp2signal(bpx, samplerate, maxT);
[signalz]=bp2signal(bpx, samplerate, maxT);

whos % make sure columns and rows are correct!
signal=[time' signalx signaly signalz];

writecsvrawdatafile(signal, 'gmw_road.csv',{'time','foreAft','lateral','vertical'});