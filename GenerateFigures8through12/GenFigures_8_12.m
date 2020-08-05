%RUN ME TO PRODUCE FIGURES 12-15 from the paper.
clear; 
%close all
fprintf('For good computational time data: \n-you should set the priority of this computer task to real-time. (in windows set priority to "real-time" in task manager).\n-If You may want to turn internet of to prevent automatic updates interfaring \n\n')

rng('shuffle')
pause(5)
AdditionalFigures=0; %I.E, ONLY PRODUCE FIGURES IN PAPER
NSamp=1e1; %NUMBER OF TRAJECTORIES TO BE TESTED. Set to 10^4 for results in paper (but this takes some time). 
ColdStart=0; %CHECKING COLDSTART ALSO
NRepeat=10; %Number of times to repeat each evaluation. Advices to have atleast 10 if investigating evaluation times on non-real-time computer

%CASE 1-Fixed actuator placement
Case1FixedCables

clearvars -except NIter8WC NIter8CC EvalTime8WCS EvalTime8WCC Liter8_CC Liter8_WC NIter8_P_C EvalTime8_P_C NIter8_P_W...
    EvalTime8_P_W Liter8_P_W Liter8_P_C NIter8_S_C2 EvalTime8_S_C2 NIter8_S_W2 EvalTime8_S_W2 Liter8_S_W Liter8_S_C...
    Feas2_8 Feas3_8 Feas4_8 Feas2W_8 Feas3W_8 Feas4W_8 NLines8 AdditionalFigures F8_PinvN F_PinvN8Add WERR28 ColdStart8...
    EtaFixed Actuator_BasesFixed End_effectorsFixed WTargetMatRand;


pause(5)

NSamp=1e1;
ColdStart=0;
NRepeat=10; %Number of times to repeat each evaluation. Advices to have atleast 10 if investigating evaluation times on non-real-time computer
AdditionalFigures=0; %I.E, ONLY PRODUCE FIGURES IN PAPER

%CASE 1-Randomized actuator placement
Case1RandomizedCables


MergeCase1

pause(10)
rng('shuffle')
NSamp=1e1;
ColdStart=0;
NRepeat=10; %Number of times to repeat each evaluation. Advices to have atleast 10 if investigating evaluation times on non-real-time computer
AdditionalFigures=0; %I.E, ONLY PRODUCE FIGURES IN PAPER
Case2

ScatterPlots
PlotHistograms
