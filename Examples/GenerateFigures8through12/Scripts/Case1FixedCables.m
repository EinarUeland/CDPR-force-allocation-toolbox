% Author: Einar Ueland
% email: einar.s.ueland@gmail.com
% September 2019;
% Randomize sample Trajectories according to Case 1 in the paper. 
% NSamp=1e2;
%  pause(40)
set(0, 'DefaultLineLineWidth', 0.5);
 if ~exist('AdditionalFigures')
AdditionalFigures=1;
end
if ~exist('NSamp')
NSamp=1e3;
end
if ~exist('NRepeat')
NRepeat=1;
end
if ~exist('ColdStart')
ColdStart=1;
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
Params2=Params;Params3=Params;Params4=Params;
Dp2=0.1;Dp3=1e-2;Dp4=0.2;Dp5=0.5;
%%  
%some solver settings
SolParamInitz=SolParam; SolParamInitz.Itermax=500;
SolParam.NRepeat=NRepeat;
SolParam0=SolParam;SolParam0.NRepeat0=1;
SolParam.IterMax=200;
Params.P=5;
% NSamp=1;
% V2=tic
pause(1) %Just want to give the solver som time to get started.
while A==1&&COUNT<NSamp
Feas=0; %Feas becomes 1 once a good trajectory is found. 
CCount=CCount+1; %counting number of excluded trajectories
while Feas==0 %THIS IS AN INITIAL QUICKCHECK OF TRAJECTORY.
% Algorithm2_randomizeAct; %Setting up a randomized trajectory. 
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
Traj.Eta=Eta;
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
ParamsP4=Params;ParamsP4.P=4;
Paramsa2=Params;
Paramsa3=Params;
Paramsa3.alpha=27.5;
Paramsa2.alpha=25;
%%
%%JUST CLEARING SOME DATA for memory purposes
fprintf('.')
if mod(COUNT,10)==0
    fprintf('\n%d\n',COUNT)
    Clear=1;
    MemClean=1;
    if Clear==1&&MemClean==1; %LET US SAVE SOME MEMORY
    F8_WC=[];F8_CN3=[];F8_P_C=[];F8_P_W=[];F8_S_W2=[];F8_S_C2=[];W_CN=[];W_WC=[];W_P_C=[];W_P_W=[];%LET US SAVE SOME MEMORIY
    end
end

if ColdStart
[T_CN(COUNT),E8_CC{COUNT},N8_CC{COUNT},F8_CN3,W_CN{COUNT},Feas2_CN{COUNT},R,Li8_CC{COUNT},s,FF_CC]=Solve_Over_Traj(1,Params,Traj,SolParam,'Cold','Compiled',0,0,0);
[T_P_C(COUNT),E8_P_C{COUNT},N8_P_C{COUNT},F8_P_C,W_P_C,Feas2_P_C{COUNT},R,Li8_P_C{COUNT},s,FF_PC]=Solve_Over_Traj(7,Paramsa2,Traj,SolParam,'Cold','Compiled',0,0,0);
[T_S_C2(COUNT),E8_S_C2{COUNT},N8_S_C2{COUNT},F8_S_C2{COUNT},W_S_C2{COUNT},Feas2_S_C2{COUNT},R2,Li8_S_C2{COUNT}]=Solve_Over_Traj(8,Params,Traj,SolParam,'Cold','Compiled',0,0,0);


end    



[T_WC(COUNT),E8_WC{COUNT},N8_WC{COUNT},F8_WC{COUNT},W_WC{COUNT},Feas2_WC{COUNT},R,Li8_WC{COUNT},s,FF_CW]=Solve_Over_Traj(1,Params,Traj,SolParam,'Warm','Compiled',0,0,1);
[T_P_W(COUNT),E8_P_W{COUNT},N8_P_W{COUNT},F8_P_W,W_P_W,Feas2_P_W{COUNT},R,Li8_P_W{COUNT},s,FF_PW]=Solve_Over_Traj(7,Params,Traj,SolParam,'Warm','Compiled',0,0,0);
[T_S_W2(COUNT),E8_S_W2{COUNT},N8_S_W2{COUNT},F8_S_W2{COUNT},W_S_W2{COUNT},Feas2_S_W2{COUNT},R2,Li8_S_W2{COUNT}]=Solve_Over_Traj(8,Params,Traj,SolParam,'Warm','Compiled',0,0,0);


%VERIFYFEASIBILITY. (I.e., checking if feasible with varying wrench feasiblity margin)
[~,VerifierMS2{COUNT},VerifierITER2{COUNT},~,~,VeriFeas2{COUNT},~,VeriLinez2{COUNT}]=Solve_Over_Traj(1,Params2,Traj,SolParam0,'Warm','Compiled',0,0,0);
[~,VerifierMS3{COUNT},VerifierITER3{COUNT},~,~,VeriFeas3{COUNT},~,VeriLinez3{COUNT}]=Solve_Over_Traj(1,Params3,Traj,SolParam0,'Warm','Compiled',0,0,0);
[~,VerifierMS4{COUNT},VerifierITER4{COUNT},~,~,VeriFeas4{COUNT},~,VeriLinez4{COUNT}]=Solve_Over_Traj(1,Params4,Traj,SolParam0,'Warm','Compiled',0,0,0);
[~,VerifierMS5{COUNT},VerifierITER5{COUNT},~,~,VeriFeas5{COUNT},~,VeriLinez4{COUNT}]=Solve_Over_Traj(1,Params5,Traj,SolParam0,'Warm','Compiled',0,0,0);



%PseudoInverse.
[T_PinvN,E8_PinvN,N8_PinvC,F8_PinvN{COUNT},W_PinvN]=Solve_Over_Traj(2,Params,Traj,SolParam,'Warm','NCompiled',0,0,1);

PropositionCheck=0;
if PropositionCheck
 Proposition_2(Traj,SolParam,Params,W_S_W2{COUNT},F8_S_W2{COUNT},1);
end
NLines8(COUNT)=size(Traj.J,2);
end

%WARMSTART



%STANDARD,P=2
NIter8WC=cell2mat(cellfun(@(x) x(2:GridSize),N8_WC,'un',0));
EvalTime8WCS=cell2mat(cellfun(@(x) x(2:GridSize),E8_WC,'un',0));
Liter8_WC=cell2mat(cellfun(@(x) x(2:GridSize),Li8_WC,'un',0));


%STANDARD,P=5
NIter8_P_W=cell2mat(cellfun(@(x) x(2:GridSize),N8_P_W,'un',0));
EvalTime8_P_W=cell2mat(cellfun(@(x) x(2:GridSize),E8_P_W,'un',0));
Liter8_P_W=cell2mat(cellfun(@(x) x(2:GridSize),Li8_P_W,'un',0));

%SLACK,P=2
NIter8_S_W2=cell2mat(cellfun(@(x) x(2:GridSize),N8_S_W2,'un',0));
EvalTime8_S_W2=cell2mat(cellfun(@(x) x(2:GridSize),E8_S_W2,'un',0));
Liter8_S_W=cell2mat(cellfun(@(x) x(2:GridSize),Li8_S_W2,'un',0));
%JUST WARM

EVALCOLLECT8Warm=[EvalTime8WCS  EvalTime8_P_W EvalTime8_S_W2];
NITERCOLLECT8Warm=[NIter8WC   NIter8_P_W  NIter8_S_W2];
LITERCOLLECT8Warm=[Liter8_WC   Liter8_P_W  Liter8_S_W];


Feas2_8=cell2mat(VeriFeas2);
Feas3_8=cell2mat(VeriFeas3);
Feas4_8=cell2mat(VeriFeas4);
Feas5_8=cell2mat(VeriFeas5);

Feas2W_8=cell2mat(cellfun(@(x) x(2:GridSize),VeriFeas2,'un',0));
Feas3W_8=cell2mat(cellfun(@(x) x(2:GridSize),VeriFeas3,'un',0));
Feas4W_8=cell2mat(cellfun(@(x) x(2:GridSize),VeriFeas4,'un',0));
WERR28=[cell2mat(W_S_W2)]; %COLD = WARM
F_PinvN8Add=cell2mat(cellfun(@(x) (sum(((x'>Params.fmin(1)).*(x'<Params.fmax(1)))'==0)==0),F8_PinvN,'un',0));

% save PrePlot8Act

EtaFixed=Eta;
Actuator_BasesFixed=Actuator_Bases;
End_effectorsFixed=End_effectors;




ColdStart8=ColdStart;

if ColdStart
%COLDSTART
%STANDARD,P=2
NIter8CC=cell2mat(cellfun(@(x) x(1:GridSize),N8_CC,'un',0));
EvalTime8WCC=cell2mat(cellfun(@(x) x(1:GridSize),E8_CC,'un',0));
Liter8_CC=cell2mat(cellfun(@(x) x(1:GridSize),Li8_CC,'un',0));

%STANDARD,P=5
NIter8_P_C=cell2mat(cellfun(@(x) x(1:GridSize),N8_P_C,'un',0));
EvalTime8_P_C=cell2mat(cellfun(@(x) x(1:GridSize),E8_P_C,'un',0));
Liter8_P_C=cell2mat(cellfun(@(x) x(1:GridSize),Li8_P_C,'un',0));

%SLACK,P=2
NIter8_S_C2=cell2mat(cellfun(@(x) x(1:GridSize),N8_S_C2,'un',0));
EvalTime8_S_C2=cell2mat(cellfun(@(x) x(1:GridSize),E8_S_C2,'un',0));
Liter8_S_C=cell2mat(cellfun(@(x) x(1:GridSize),Li8_S_C2,'un',0));



%Mixing Coldstart and warmstart.
EVALCOLLECT8CS=1./[EvalTime8WCS EvalTime8WCC];%NORMAl
EVALCOLLECT8Norm=1./[EvalTime8_P_C EvalTime8_P_W];%P=5
EVALCOLLECT8Slack=1./[EvalTime8_S_C2 EvalTime8_S_W2];%SLACK%
NITERCOLLECT8CS=[NIter8WC NIter8CC];
NITERCOLLECT8Norm=[NIter8_P_C NIter8_P_W];
NITERCOLLECT8Slack=[NIter8_S_C2 NIter8_S_W2];
EVALCOLLECT8=[EvalTime8WCS EvalTime8WCC EvalTime8_P_C EvalTime8_P_W EvalTime8_S_C2 EvalTime8_S_W2];
NITERCOLLECT8=[NIter8WC NIter8CC NIter8_P_C NIter8_P_W NIter8_S_C2 NIter8_S_W2];
LITERCOLLECT8=[Liter8_WC Liter8_CC Liter8_P_C Liter8_P_W Liter8_S_C Liter8_S_W];



plot(Liter8_P_C)

end







if AdditionalFigures


figure('name','sample configuration (Fixed Case 1)')
DrawConfig(EtaFixed,1000,Actuator_BasesFixed,End_effectorsFixed,Colorzcheme,1)


timez=linspace(0,1,1000)
    figure('name','Fig11(a) Sample pose trajectory (Fixed Case 1)')
for i=1:3
    plot(timez,Eta(i,:),'LineWidth',2,'color',Colorzcheme{i}); hold on
end
for i=4:6
    plot(timez,Eta(i,:),':','LineWidth',2,'color',Colorzcheme{i}); hold on
end
    [Hv]=legend({'x[m]  \quad ','y[m]   ','z[m]   ','$\phi$[rad] ','$\theta$[rad] ','$\psi$[rad] '},'NumColumns',2,'Interpreter','latex');

    xlabel('Time[s]','FontSize',24,'Interpreter','latex'); hold on
    ylabel('Magnitude','FontSize',24,'Interpreter','latex')

    figure('name','Fig11(a) Sample wrench trajectory (Fixed Case 1)')
for i=1:3
    plot(timez,Traj.WTargetMat(i,:),'LineWidth',2,'color',Colorzcheme{i}); hold on
end
for i=4:6
    plot(timez,Traj.WTargetMat(i,:)*10,':','LineWidth',2,'color',Colorzcheme{i}); hold on
end


     legend({'$F_x \enskip $','$F_y \enskip $','$F_z \enskip $','$10 M_{x}$','$10M_y$','10$M_z$'},'Interpreter','latex','NumColumns',2)
     xlabel('Time[s]','Interpreter','latex')
     ylabel('Force[N]/Moment[Nm]','Interpreter','latex')'





    
    
    
    
    
    
    
    
    
    
    
    
    


figure('name','NormalWarm (Fixed Case 1)')%figure('name','Warmstart')
K2=Hist_2(NIter8WC(Feas3W_8==1),'',Colorzcheme{3}); hold on
Hist_2(NIter8WC(Feas2W_8==1),'Standard, Warm start,p=2',Colorzcheme{2}); hold on
xlim([0 K2])
H=legend('$\mathrm{min}(h_i)>0.01$','$\mathrm{min}(h_i)>0.1$'); set(H,'interpreter','latex')
LE.FontSize(40,40,24.08)


figure('name','PnormWarm (Fixed Case 1)')%figure('name','P-Warm')
K=Hist_2(NIter8_P_W(Feas3W_8==1),'',Colorzcheme{3}); hold on
Hist_2(NIter8_P_W(Feas2W_8==1),'Standard, Warm start,p=5 ',Colorzcheme{2});
xlim([0 K])
H=legend('$\mathrm{min}(h_i)>10^{-3}$','$\mathrm{min}(h_i)>10^{-2}$'); set(H,'interpreter','latex')
LE.FontSize(40,40,24.08)

figure('name','SlackWarm (Fixed Case 1) ')%figure('name','SlackWarm')
K=Hist_2(NIter8_S_W2,'Slack Warm start, p=2',Colorzcheme{3}); hold on
xlim([0 K])
LE.FontSize(40,40,24.08)



if ColdStart

figure('name','NormalCold (Fixed Case 1)')%figure('name','COldStart')
 K2=Hist_2(NIter8CC(Feas3_8==1),'',Colorzcheme{3}); hold on
Hist_2(NIter8CC(F_PinvN8Add==1),'Standard, Cold start,p=2',Colorzcheme{6});
H=legend('$\mathrm{min}(h_i)>0.01$','Feasible With pseudoinverse'); set(H,'interpreter','latex')
xlim([0 K2])
LE.FontSize(40,40,24.08)


figure('name','PnormCold ($\alpha=25$) (Fixed Case 1)') %figure('name','P-Cold')
K=Hist_2(NIter8_P_C(Feas2_8==1),'Standard, Cold start,p=5',Colorzcheme{3}); hold on
Hist_2(NIter8_P_C(Feas5_8==1),'Standard, Cold start,p=5',Colorzcheme{2}); hold on
xlim([0 K])





figure('name','SlackCold (Fixed Case 1) ')%figure('name','SlackWarm')
K=Hist_2(NIter8_S_C2,'Slack Cold start, p=2',Colorzcheme{3}); hold on
xlim([0 K])
LE.FontSize(40,40,24.08)
end

if ColdStart
AvEnd=25;
for i=1:AvEnd
    EVALSum(i)=mean(1./EVALCOLLECT8(NITERCOLLECT8==i));
    EVAL_NORMAL(i)=mean(EVALCOLLECT8CS(NITERCOLLECT8CS==i));
    EVAL_P5(i)=mean(EVALCOLLECT8Norm(NITERCOLLECT8Norm==i));
    EVAL_Slack(i)=mean(EVALCOLLECT8Slack(NITERCOLLECT8Slack==i)); 
end
else
    AvEnd=7;
for i=1:AvEnd
    EVALSum(i)=mean(1./EVALCOLLECT8Warm(NITERCOLLECT8Warm==i));
    EVAL_NORMAL(i)=mean(1./EvalTime8WCS(NIter8WC==i));
    EVAL_P5(i)=mean(1./EvalTime8_P_W(NIter8_P_W==i));
    EVAL_Slack(i)=mean(1./EvalTime8_S_W2(NIter8_S_W2==i)); 
end
end
    
figure('name','ScatterPlot Eval VS Niter (Fixed Case 1)' )
dt=1e-3;
plot(1:AvEnd,EVAL_NORMAL,'r'); hold on
plot(1:AvEnd,EVAL_P5,'b')
plot(1:AvEnd,EVAL_Slack,'m'); hold on

if ColdStart
Heat_Scatter(NITERCOLLECT8', 1./EVALCOLLECT8',0:max(NITERCOLLECT8),0:dt:max( 1./EVALCOLLECT8')); hold on
xlim([0 max(NITERCOLLECT8)+0.1])
else
Heat_Scatter(NITERCOLLECT8Warm', 1./EVALCOLLECT8Warm',0:max(NITERCOLLECT8Warm),0:dt:max( 1./EVALCOLLECT8Warm')); hold on
xlim([0 max(NITERCOLLECT8Warm)+0.1])
end  

plot(1:AvEnd,EVAL_NORMAL,'r','LineWidth',2)
plot(1:AvEnd,EVAL_P5,'b','LineWidth',2)
plot(1:AvEnd,EVAL_Slack,'m','LineWidth',2); hold on

V=legend('Standard formulation, p=2','Standard formulation, p=5','Slack formulation');title(V,'Mean evaluation time')
V.BoxFace.ColorData(4)=100;  % 4x1 uint8
set(V.BoxFace, 'ColorType','truecoloralpha', 'ColorData',uint8(255*[1;1;1;.2]));  % [.5,.5,.5] is light gray; 0.8 means 20% transparent

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
figure('name','LineIter (Fixed Case 1)')
% Heat_Scatter(NIter8_P_C(Feas4W_8==1)',
% Liter8_P_C(Feas4W_8==1)',0:max(NITERCOLLECT8),0:max([max(LITERCOLLECT8) 1]))i
if ColdStart==1
Heat_Scatter(NITERCOLLECT8', LITERCOLLECT8',0:max(NITERCOLLECT8),0:max([max(LITERCOLLECT8) 1]))
xlim([0 max(NITERCOLLECT8)+0.1])
else
Heat_Scatter(NITERCOLLECT8Warm', LITERCOLLECT8Warm',0:max(NITERCOLLECT8Warm),0:max([max(LITERCOLLECT8Warm) 1]))   
xlim([0 max(NITERCOLLECT8Warm)+0.1])
end
H3=colorbar;
H3.TickLabels{1}=1;
% Feas2_8
% 
% NIter8_P_C
% Liter8_P_C

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






figure('name','Werr ColdStart (Fixed Case 1)') %WERR plot
dH=0.00005;
H=max(abs(WERR28)); [a b]=hist(H,0:0.00005:max(sum(abs(WERR28)))); plot(b,a/(dH*sum(a)),'LineWidth',2); hold on; xlim([0 max(sum(abs(WERR28)))])
xlabel('$|${\boldmath $w$}$_{\mathrm{err}}|_\infty$','Interpreter','latex')
ylabel('Normalized frequency','Interpreter','latex')
max(sum(abs(WERR28)));
LE.FontSize(16,9.6,10.08)



end
% save DATAP
