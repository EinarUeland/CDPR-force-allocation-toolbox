% Author: Einar Ueland
% email: einar.s.ueland@gmail.com
% September 2019;
% Randomize sample Trajectories according to Case 1 in the paper. 
set(0, 'DefaultLineLineWidth', 0.5);

% AdditionalFigures=0;
% clearvars -except AdditionalFigures NSamp
 if ~exist('AdditionalFigures')
     AdditionalFigures=1;
end
if ~exist('NSamp')
 NSamp=1e4;
end
if ~exist('ColdStart')
 ColdStart=1;
end
if ~exist('NRepeat')
NRepeat=1;
end

zzH=[];
VA=tic
Colorzcheme={'k',[0.8500, 0.3250, 0.0980],[0, 0.4470, 0.7410],[0.5 0.5 0.5],[0.4660, 0.6740, 0.1880],[0.9290, 0.6940, 0.1250],[0.4940, 0.1840, 0.5560]}

Init_Motivating_Example
t=linspace(0,3*pi,GridSize);

COUNT=0;InfC=1;A=1;CCount=0; CErr=0;%Dummy Variables and counters
%Upper and lower limt for position
EtaLim=[.3;.15;.4;.3;.3;.3];
WLim=[10;10;10;0.2;0.2;0.2]*5;

%Setting up a verifyer to later exclude values not feasible with f lower than delta from HISTOgrams
Params2=Params;Params3=Params;Params4=Params;Params5=Params;
Dp2=0.1;Dp3=1e-2;Dp4=0.2;Dp5=0.5;
%%
%some solver settings
SolParamInitz=SolParam; SolParamInitz.Itermax=500;
SolParam.NRepeat=NRepeat;
SolParam0=SolParam;SolParam0.NRepeat0=1;
SolParam.IterMax=200;
Params.P=5;
% NSamp=1;
V2=tic
pause(1) %Just want to give the solver som time to get started.
    while A==1&&COUNT<NSamp
    Feas=0; %Feas becomes 1 once a good trajectory is found. 
    CCount=CCount+1; %counting number of excluded trajectories
    while Feas==0 %THIS IS AN INITIAL QUICKCHECK OF TRAJECTORY.
    Algorithm2_randomizeAct; %Setting up a randomized trajectory. 
    Params.fmin=ones(NACT,1)*1;
    %TRAJECTORY START END
    Eta_Start=((rand(MDIM,1)-0.5)*2).*EtaLim;
    Eta_End=((rand(MDIM,1)-0.5)*2).*EtaLim;
    W_target_Start=((rand(MDIM,1)-0.5)*2).*WLim;
    W_target_End=((rand(MDIM,1)-0.5)*2).*WLim;
    for i=1:MDIM
    EtaInt(i,:)=linspace(Eta_Start(i),Eta_End(i),GridSize);
    end
    Eta=EtaInt;
    DELTAW=W_target_End-W_target_Start;
    Traj.WTargetMat=W_target_Start+0.5*DELTAW*(1-cos(t));
    Traj.J=Get_JMatrix_Series(Actuator_Bases,End_effectors,Eta,1);
    DELTAW=W_target_End-W_target_Start;
    Traj.WTargetMat=W_target_Start+0.5*DELTAW*(1-cos(t));
    Traj0.J=[Traj.J(:,:,[ 1 end])];
    Traj0.WTargetMat=Traj.WTargetMat(:,[1 end]);
    %CHECKING TESTTRAJ Short version first
    [a,b,c,d,e,OutFeas]=Solve_Over_Traj(1,Params,Traj0,SolParamInitz,'Cold','Compiled',0,0,1); %CHECKING FIRST AND LASt
    if sum(sum(OutFeas==-1))>0
        InfC=InfC+1;
    else %CHECKING TESTTRAJ Short full version
    [a,b,c,d,e,FeasTemp,R,f]=Solve_Over_Traj(1,Params,Traj,SolParamInitz,'Warm','Compiled',0,0,1); %CHECKING WHOLE TRAJECTORY
    if sum(sum(FeasTemp<0))>0
    CErr=CErr+1;
    else
        Feas=1;
        COUNT=COUNT+1;
    end
    end
    end

    % Setting up "Delta Verifiers% 
    Params2=Params;Params3=Params;Params4=Params;Params5=Params;
    Params2.fmin=Params.fmin+Dp2;
    Params2.fmax=Params.fmax-Dp2;
    Params3.fmin=Params.fmin+Dp3;
    Params3.fmax=Params.fmax-Dp3;
    Params4.fmin=Params.fmin+Dp4;
    Params4.fmax=Params.fmax-Dp4;
    Params5.fmin=Params.fmin+Dp5;
    Params5.fmax=Params.fmax-Dp5;

    Paramsa2=Params;
    Paramsa2.alpha=25;
    %%

    %%JUST CLEARING SOME DATA for memory purposes
    fprintf('.')
    if mod(COUNT,10)==0
        fprintf('\n%d\n',COUNT)
        Clear=1;
        MemClean=1;
        if Clear==1&&MemClean==1; %LET US SAVE SOME MEMORY
        F_WC=[];F_CN3=[];F_P_C=[];F_P_W=[];F_S_W2=[];F_S_C2=[];W_CN=[];W_WC=[];W_P_C=[];W_P_W=[];%LET US SAVE SOME MEMORIY
        end
    end




    %NEWTON STANDARD P=2
    [T_WC(COUNT),E_WC{COUNT},N_WC{COUNT},F_WC{COUNT},W_WC{COUNT},Feas2_WC{COUNT},R,Li_WC{COUNT}]=Solve_Over_Traj(1,Params,Traj,SolParam,'Warm','Compiled',0,0,1);

    %NEWTON STANDARD,P=5
    [T_P_W(COUNT),E_P_W{COUNT},N_P_W{COUNT},F_P_W,W_P_W,Feas2_P_W{COUNT},R,Li_P_W{COUNT}]=Solve_Over_Traj(7,Paramsa2,Traj,SolParam,'Warm','Compiled',0,0,0);

    %NEWTON SLACKED,P=2
    [T_S_W2(COUNT),E_S_W2{COUNT},N_S_W2{COUNT},F_S_W2{COUNT},W_S_W2{COUNT},Feas2_S_W2{COUNT},R2,Li_S_W2{COUNT}]=Solve_Over_Traj(8,Params,Traj,SolParam,'Warm','Compiled',0,0,0);

    %VERIFYFEASIBILITY. (I.e., checking if feasible with reduced wrench feasiblity margin)
    [~,VerifierMS2{COUNT},VerifierITER2{COUNT},~,~,VeriFeas2{COUNT},~,VeriLinez2{COUNT}]=Solve_Over_Traj(1,Params2,Traj,SolParam0,'Warm','Compiled',0,0,0);
    [~,VerifierMS3{COUNT},VerifierITER3{COUNT},~,~,VeriFeas3{COUNT},~,VeriLinez3{COUNT}]=Solve_Over_Traj(1,Params3,Traj,SolParam0,'Warm','Compiled',0,0,0);
    [~,VerifierMS4{COUNT},VerifierITER4{COUNT},~,~,VeriFeas4{COUNT},~,VeriLinez4{COUNT}]=Solve_Over_Traj(1,Params4,Traj,SolParam0,'Warm','Compiled',0,0,0);
    [~,VerifierMS5{COUNT},VerifierITER5{COUNT},~,~,VeriFeas5{COUNT},~,VeriLinez4{COUNT}]=Solve_Over_Traj(1,Params5,Traj,SolParam0,'Warm','Compiled',0,0,0);

    %PseudoInverse.
    [T_PinvN,E_PinvN,N_PinvC,F_PinvN{COUNT},W_PinvN]=Solve_Over_Traj(2,Params,Traj,SolParam,'Warm','NCompiled',0,0,1);

    %REGISTERING THE NUMBER OF LINES
    NLines(COUNT)=N;

    if ColdStart==1;
[T_CN(COUNT),E_CC{COUNT},N_CC{COUNT},F_CN3,W_CN{COUNT},Feas2_CN{COUNT},R,Li_CC{COUNT}]=Solve_Over_Traj(1,Params,Traj,SolParam,'Cold','Compiled',0,0,0);
 [T_P_C(COUNT),E_P_C{COUNT},N_P_C{COUNT},F_P_C,W_P_C,Feas2_P_C{COUNT},R,Li_P_C{COUNT}]=Solve_Over_Traj(7,Paramsa2,Traj,SolParam,'Cold','Compiled',0,0,0);
[T_S_C2(COUNT),E_S_C2{COUNT},N_S_C2{COUNT},F_S_C2{COUNT},W_S_C2{COUNT},Feas2_S_C2{COUNT},R2,Li_S_C2{COUNT}]=Solve_Over_Traj(8,Params,Traj,SolParam,'Cold','Compiled',0,0,0);

    end

    PropositionCheck=0;
    if PropositionCheck
     Proposition_2(Traj,SolParam,Params,W_S_W2{COUNT},F_S_W2{COUNT},1);
     Proposition_2(Traj,SolParam,Params,W_S_C2{COUNT},F_S_C2{COUNT},1);
    end
    end

%CELL2MATRICES. Excluding 1 iter since it cannot be warm-started.

%WARMSTART
%STANDARD,P=2
NIterWC=cell2mat(cellfun(@(x) x(2:GridSize),N_WC,'un',0));
EvalTimeWCS=cell2mat(cellfun(@(x) x(2:GridSize),E_WC,'un',0));
Liter_WC=cell2mat(cellfun(@(x) x(2:GridSize),Li_WC,'un',0));


%STANDARD,P=5
NIter_P_W=cell2mat(cellfun(@(x) x(2:GridSize),N_P_W,'un',0));
EvalTime_P_W=cell2mat(cellfun(@(x) x(2:GridSize),E_P_W,'un',0));
Liter_P_W=cell2mat(cellfun(@(x) x(2:GridSize),Li_P_W,'un',0));
% NIter_P_Ca2=cell2mat(cellfun(@(x) x(2:GridSize),N_P_Ca2,'un',0));

%SLACK,P=2
NIter_S_W2=cell2mat(cellfun(@(x) x(2:GridSize),N_S_W2,'un',0));
EvalTime_S_W2=cell2mat(cellfun(@(x) x(2:GridSize),E_S_W2,'un',0));
Liter_S_W=cell2mat(cellfun(@(x) x(2:GridSize),Li_S_W2,'un',0));


EVALCOLLECTWarm=[EvalTimeWCS  EvalTime_P_W EvalTime_S_W2];
NITERCOLLECTWarm=[NIterWC   NIter_P_W  NIter_S_W2];
LITERCOLLECTWarm=[Liter_WC   Liter_P_W  Liter_S_W];




%Checking which were not feasible with different values of delta. 
Feas2=cell2mat(VeriFeas2);
Feas3=cell2mat(VeriFeas3);
Feas2W=cell2mat(cellfun(@(x) x(2:GridSize),VeriFeas2,'un',0));
Feas3W=cell2mat(cellfun(@(x) x(2:GridSize),VeriFeas3,'un',0));
Feas4W=cell2mat(cellfun(@(x) x(2:GridSize),VeriFeas4,'un',0));
Feas4=cell2mat(VeriFeas4);
Feas5W=cell2mat(cellfun(@(x) x(2:GridSize),VeriFeas5,'un',0));
Feas5=cell2mat(VeriFeas5);


F_PinvNAdd=cell2mat(cellfun(@(x) (sum(((x'>Params.fmin(1)).*(x'<Params.fmax(1)))'==0)==0),F_PinvN,'un',0));
OnOroffPinv=cell2mat(cellfun(@(x) (sum((sum(((x'>Params.fmin(1)).*(x'<Params.fmax(1)))'==0)==0)==0)==0),F_PinvN,'un',0));
PSTPINV=sum(F_PinvNAdd)/length(F_PinvNAdd);

WERR2=[cell2mat(W_S_W2)];

%SAMPLE
EtaRand=Eta;
Actuator_BasesRand=Actuator_Bases;
End_effectorsRand=End_effectors;
WTargetMatRand=Traj.WTargetMat;
ColdstartRND=ColdStart;

if ColdStart
%COLDSTART
%STANDARD,P=2
NIterCC=cell2mat(cellfun(@(x) x(1:GridSize),N_CC,'un',0));
EvalTimeWCC=cell2mat(cellfun(@(x) x(1:GridSize),E_CC,'un',0));
Liter_CC=cell2mat(cellfun(@(x) x(1:GridSize),Li_CC,'un',0));


%STANDARD,P=5
NIter_P_C=cell2mat(cellfun(@(x) x(1:GridSize),N_P_C,'un',0));
EvalTime_P_C=cell2mat(cellfun(@(x) x(1:GridSize),E_P_C,'un',0));
Liter_P_C=cell2mat(cellfun(@(x) x(1:GridSize),Li_P_C,'un',0));
% NIter_P_Ca2=cell2mat(cellfun(@(x) x(2:GridSize),N_P_Ca2,'un',0));

%SLACK,P=2
NIter_S_C2=cell2mat(cellfun(@(x) x(1:GridSize),N_S_C2,'un',0));
EvalTime_S_C2=cell2mat(cellfun(@(x) x(1:GridSize),E_S_C2,'un',0));
Liter_S_C=cell2mat(cellfun(@(x) x(1:GridSize),Li_S_C2,'un',0));



%COLLECTING ALL TIME DATA FOR SCATTERPLOTS

%PER TYPE
EVALCOLLECTCS=[EvalTimeWCS EvalTimeWCC];%NORMAl
EVALCOLLECTNorm=[EvalTime_P_C EvalTime_P_W];%P=5
EVALCOLLECTSlack=[EvalTime_S_C2 EvalTime_S_W2];%SLACK%
NITERCOLLECTCS=[NIterWC NIterCC];
NITERCOLLECTNorm=[NIter_P_C NIter_P_W];
NITERCOLLECTSlack=[NIter_S_C2 NIter_S_W2];

%ALL TOGETEHER
EVALCOLLECT=[EvalTimeWCS EvalTimeWCC EvalTime_P_C EvalTime_P_W EvalTime_S_C2 EvalTime_S_W2];
NITERCOLLECT=[NIterWC NIterCC NIter_P_C NIter_P_W NIter_S_C2 NIter_S_W2];
LITERCOLLECT=[Liter_WC Liter_CC Liter_P_C Liter_P_W Liter_S_C Liter_S_W];
end
%JUST WARM






%GOTTA GET AVERAGELINES FOR WARM!!.



if AdditionalFigures

    



%TO GENERATE AVERAGELINES
if ColdStart
AvEnd=25;
for i=1:AvEnd
    EVALSum(i)=mean(1./EVALCOLLECT(NITERCOLLECT==i));
    EVAL_NORMAL(i)=mean(1./EVALCOLLECTCS(NITERCOLLECTCS==i));
    EVAL_P5(i)=mean(1./EVALCOLLECTNorm(NITERCOLLECTNorm==i));
    EVAL_Slack(i)=mean(1./EVALCOLLECTSlack(NITERCOLLECTSlack==i)); 
end
else
    AvEnd=7;
for i=1:AvEnd
    EVALSum(i)=mean(1./EVALCOLLECTWarm(NITERCOLLECTWarm==i));
    EVAL_NORMAL(i)=mean(1./EvalTimeWCS(NIterWC==i));
    EVAL_P5(i)=mean(1./EvalTime_P_W(NIter_P_W==i));
    EVAL_Slack(i)=mean(1./EvalTime_S_W2(NIter_S_W2==i)); 
end
end





figure('name','NITERTIME (Randomixed Actuators Case 1)' )
dt=1e-3;
plot(1:AvEnd,EVAL_NORMAL,'r'); hold on
plot(1:AvEnd,EVAL_P5,'b')
plot(1:AvEnd,EVAL_Slack,'m'); hold on

if ColdStart
Heat_Scatter(NITERCOLLECT', 1./EVALCOLLECT',0:max(NITERCOLLECT),0:dt:max( 1./EVALCOLLECT')); hold on
else
Heat_Scatter(NITERCOLLECTWarm', 1./EVALCOLLECTWarm',0:max(NITERCOLLECTWarm),0:dt:max( 1./EVALCOLLECTWarm')); hold on
end  

% Heat_Scatter3(NITERCOLLECT8', 1./EVALCOLLECT8',0:max(NITERCOLLECT8),0:dt:max( 1./EVALCOLLECT8')); hold on


plot(1:AvEnd,EVAL_NORMAL,'r','LineWidth',2)
plot(1:AvEnd,EVAL_P5,'b','LineWidth',2)
plot(1:AvEnd,EVAL_Slack,'m','LineWidth',2); hold on

V=legend('Standard formulation, p=2','Standard formulation, p=5','Slack formulation');title(V,'Mean evaluation time')
V.BoxFace.ColorData(4)=100;  % 4x1 uint8
set(V.BoxFace, 'ColorType','truecoloralpha', 'ColorData',uint8(255*[1;1;1;.2]));  % [.5,.5,.5] is light gray; 0.8 means 20% transparent

% xlim([0 max(NITERCOLLECT)+0.1])
H3=colorbar;
H3.TickLabels{1}=1;
for i=2:length(H3.TickLabels)
 H3.TickLabels{i}=['10^' H3.TickLabels{i}];
end
xlim([0 30])

% H3.TickLabels={'1';'10';'10^2';'10^3';'10^4';'10^5';'10^6'}
ylabel(H3,'Instances in vicinity $(\pm 1 \mu  s)$','interpreter','latex');
H3.FontSize=14
ylabel('Evaluation time [ms]','interpreter','latex','FontSize',18)
xlabel('Number of iterations','FontSize',18)
xlim([0 30])




%LINEITERATIONS
figure('name','LineIter (Randomixed Actuators Case 1)')
if ColdStart==1
Heat_Scatter(NITERCOLLECT', LITERCOLLECT',0:max(NITERCOLLECT),0:max([max(LITERCOLLECT) 1]))
else
Heat_Scatter(NITERCOLLECTWarm', LITERCOLLECTWarm',0:max(NITERCOLLECTWarm),0:max([max(LITERCOLLECTWarm) 1]))   
end


H3=colorbar;
H3.TickLabels{1}=1;

for i=2:length(H3.TickLabels)
 H3.TickLabels{i}=['10^' H3.TickLabels{i}];
end
ylabel(H3,'Instances','interpreter','latex');
H3.FontSize=14
ylabel('Number of linesteps','interpreter','latex','FontSize',18)
xlabel('Number of iterations','FontSize',18)
MFILENAME='All_linesRND5'
xlim([0 25])
% ylim([0 100])






 figure('name','NormalWarm (Randomixed Actuators Case 1)')%figure('name','Warmstart')
K2=Hist_2(NIterWC(Feas3W==1),'',Colorzcheme{3}); hold on
Hist_2(NIterWC(Feas2W==1),'Standard, Warm start,p=2',Colorzcheme{2}); hold on
xlim([0 K2])
H=legend('$\mathrm{min}(h_i)>0.01$','$\mathrm{min}(h_i)>0.1$'); set(H,'interpreter','latex')
LE.FontSize(40,40,24.08)
LE.MINBORDER


figure('name','PnormWarm (Randomixed Actuators Case 1)')%figure('name','P-Warm')
K=Hist_2(NIter_P_W(Feas3W==1),'',Colorzcheme{3}); hold on
Hist_2(NIter_P_W(Feas2W==1),'Standard, Warm start,p=5',Colorzcheme{2});
xlim([0 K])
H=legend('$\mathrm{min}(h_i)>10^{-3}$','$\mathrm{min}(h_i)>10^{-2}$'); set(H,'interpreter','latex')
LE.FontSize(16,9.6,10.08)





figure('name','SlackWarm (Randomixed Actuators Case 1)')%figure('name','SlackWarm')
K=Hist_2(NIter_S_W2,'Slack Warm start, p=2',Colorzcheme{3}); hold on
xlim([0 K])
LE.FontSize(16,9.6,10.08)


figure('name','Werr (Randomixed Actuators Case 1)') %WERR plot
dH=0.00005;
H=max(abs(WERR2)); [a b]=hist(H,0:0.00005:max(sum(abs(WERR2)))); plot(b,a/(dH*sum(a)),'LineWidth',2); hold on; xlim([0 max(sum(abs(WERR2)))])
xlabel('$|${\boldmath $w$}$_{\mathrm{err}}|_\infty$','Interpreter','latex')
ylabel('Normalized frequency','Interpreter','latex')
max(sum(abs(WERR2)))
LE.FontSize(16,9.6,10.08)



ylabel('Normalized frequency (Randomixed Actuators Case 1)','Interpreter','latex')
max(sum(abs(WERR2)))
LE.FontSize(16,9.6,10.08)



figure('name','NLINES (Randomixed Actuators Case 1)')
Hist_2(NLines,'Number of lines',Colorzcheme{3})
xlim([7 25])
LE.FontSize(16,9.6,10.08)


if ColdStart
    
figure('name','PnormCold (Randomixed Actuators Case 1) $\alpha=25$') %figure('name','P-Cold')
K=Hist_2(NIter_P_C(Feas3==1),'Standard, Cold start,p=5',Colorzcheme{3}); hold on
xlim([0 K])
LE.FontSize(16,9.6,10.08)



figure('name','SlackCold (Randomixed Actuators Case 1)')%figure('name','SlackWarm')
K=Hist_2(NIter_S_C2,'Slack Cold start, p=2',Colorzcheme{3}); hold on
xlim([0 K])
LE.FontSize(16,9.6,10.08)

figure('name','NormalCold (Randomixed Actuators Case 1)')%figure('name','COldStart')
 K2=Hist_2(NIterCC(Feas3==1),'',Colorzcheme{3}); hold on
Hist_2(NIterCC(F_PinvNAdd==1),'Standard, Cold start,p=2',Colorzcheme{6});
H=legend('$\mathrm{min}(h_i)>0.01','Feasible With pseudoinverse'); set(H,'interpreter','latex')
xlim([0 K2])
LE.FontSize(16,9.6,10.08)





end
end



