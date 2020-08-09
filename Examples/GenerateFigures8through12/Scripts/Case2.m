% Author: Einar Ueland
% email: einar.s.ueland@gmail.com
% September 2019;
% Randomize sample Trajectories according to Case 2 in the paper. 

 if ~exist('AdditionalFigures')
AdditionalFigures=1;
end
if ~exist('NSamp')
NSamp=1e4;
end
if ~exist('NRepeat')
NRepeat=1;
end
if ~exist('ColdStart')
    ColdStart=1;
end
%Initializing
Init_Motivating_Example
SolParam.Itermax=500;
N_Eval=GridSize;

EtaLim=[.24;.12;0.24;.3;.3;.3];
WLim=[10;10;10;1;1;1]*2;
KAPActuator_Bases=1;
COUNT=0;InfC=1;A=1;CCount=0; CErr=0;%COUNTERS and dummies
SolParam.NRepeat=NRepeat;
LargeLog=1;
while A==1&&CCount<NSamp
COUNT=COUNT+1;
CCount=CCount+1;
Feasible=0;
AMID=0;
FLAG=0;
InfeasibleFlag=zeros(1,N_Eval);
AMID=AMID+1;
% V(CCount)=AMID;
Eta_Start=((rand(MDIM,1)-0.5)*2).*EtaLim;
Eta_End=((rand(MDIM,1)-0.5)*2).*EtaLim;
W_target_Start=((rand(MDIM,1)-0.5)*2).*WLim;
W_target_End=((rand(MDIM,1)-0.5)*2).*WLim;
SolParam.Itermax=1e4;
Params.fmin=ones(NACT,1)*1;
pause(0.5)

% SolParam.NRepeat=1;
for i=1:MDIM
EtaInt(i,:)=linspace(Eta_Start(i),Eta_End(i),N_Eval);
EtaReduced(i,:)=linspace(Eta_Start(i),Eta_End(i),N_Eval/5);
end
fprintf('.')

%For memory purposes.
if mod(COUNT,10)==0
    fprintf('\n%d\n',COUNT)
        MemClean=0;
    if MemClean==1; %LET US SAVE SOME MEMORY
    W_S_W=[];W_S_C=[];W_S_W2=[];
    end
end

Eta=EtaInt;
Traj.Eta=Eta;
LargeLog=0;
DELTAW=W_target_End-W_target_Start;
Traj.WTargetMat=W_target_Start+0.5*DELTAW*(1-cos(t));
Traj.J=Get_JMatrix_Series(Actuator_Bases,End_effectors,Eta,1);


[T_S_W,E_S_W{COUNT},N_S_W{COUNT},F_S_W,W_S_W{COUNT},Feas2_S_W,R2,Li_S_W{COUNT}]=Solve_Over_Traj(8,Params,Traj,SolParam,'Warm','Compiled',0,0,0);
pause(0.2);

if ColdStart
[T_S_C,E_S_C{COUNT},N_S_C{COUNT},F_S_C,W_S_C{COUNT},Feas2_S_C,R2,Li_S_C{COUNT}]=Solve_Over_Traj(8,Params,Traj,SolParam,'Cold','Compiled',0,0,0);  
end

PropositionCheck=0;
  if PropositionCheck
 Proposition_2(Traj,SolParam,Params,W_S_W{COUNT},F_S_W,1);
  end
end

N_S_WAdd=cell2mat(cellfun(@(x) x(2:N_Eval),N_S_W,'un',0));
EvalTimeWCS=cell2mat(cellfun(@(x) x(2:N_Eval),E_S_W,'un',0));
Li_S_WAdd=cell2mat(cellfun(@(x) x(2:N_Eval),Li_S_W,'un',0));




if ColdStart
N_S_CAdd=cell2mat(N_S_C);
EvalTimeCCS=cell2mat(E_S_C);
Li_S_CAdd=cell2mat(Li_S_C);

Eval_Slack=[EvalTimeWCS EvalTimeCCS ];
L_Iter_Slack=[Li_S_WAdd Li_S_CAdd];
N_Iter_Slack=[N_S_WAdd N_S_CAdd];
end
    
    
for i=1:50
    EVALWC(i)=mean(1./EvalTimeWCS(N_S_WAdd==i));
    if ColdStart
    EVALKCS(i)=mean(1./EvalTimeCCS(N_S_CAdd==i));
    EVALSUM(i)=mean(1./Eval_Slack(N_Iter_Slack==i));
    else
        EVALSUM(i)=mean(1./EvalTimeWCS(N_S_WAdd==i));
    end
end

    
TICZ=[1 1e2 1e4 1e6];


 figure('name','Figure11(a) Histogram warm start, Case 2, slack')%figure('name','Warmstart')
Hist_2(N_S_WAdd,'Slack, Warm start, p=2')
LE.AspectRatio([2 1.7])
LE.FontSize(42,33,32.08)

yticks(TICZ)



TICZZ=[1e-6 1e-4 1e-2 1e0 1e2];



figure('name','Figure11(b) Resulting Slack (Case 2). ')
dH=0.01;

WErr_Slack_WAdd=cell2mat(cellfun(@(x) x(:,2:N_Eval),W_S_W,'un',0));
H=max(abs(WErr_Slack_WAdd)); [a b]=hist(H,0:dH:20);
semilogy(b,a/(dH*sum(a)),'LineWidth',2,'color','b'); hold on

plot(b,a/(0.01*sum(a)),'LineWidth',2,'color','b'); hold on

xlabel('$|${\boldmath $w$}$_{\mathrm{err}}|_\infty$','Interpreter','latex')
ylabel('Normalized frequency','Interpreter','latex')
FiftyPercent=median(H)
sum(H>0.1)/length(H)
LE.AspectRatio([2 1.7])
LE.FontSize(42,33,32.08)

yticks(TICZZ)


if AdditionalFigures

Z=prctile(H,90)
fprintf('10 percent is larger than %d ',Z)

LE.FontSize(16,9.6,14.4)


figure('name',['NITERTIME_Slack (Case 2)' num2str(SolParam.NRepeat)])


dt=1e-3;
plot(EVALSUM,'m'); hold on

if ColdStart
Heat_Scatter3(N_Iter_Slack', 1./Eval_Slack',0:max(N_Iter_Slack),0:dt:max(1./Eval_Slack')); hold on
else
    Heat_Scatter3(N_S_WAdd', 1./EvalTimeWCS',0:max(N_S_WAdd),0:dt:max(1./EvalTimeWCS')); hold on
end
plot(EVALSUM,'m'); hold on
V=legend('Standard formulation, p=2');title(V,'Mean evaluation time')
V.BoxFace.ColorData(4)=100  % 4x1 uint8
set(V.BoxFace, 'ColorType','truecoloralpha', 'ColorData',uint8(255*[1;1;1;.2]));  % [.5,.5,.5] is light gray; 0.8 means 20% transparent

H3=colorbar;
H3.TickLabels{1}=1;
for i=2:length(H3.TickLabels)
 H3.TickLabels{i}=['10^' H3.TickLabels{i}];
end
ylabel(H3,'Instances in vicinity $(\pm 1 \mu  s)$','interpreter','latex');
H3.FontSize=14
ylabel('Evaluation time [ms]','interpreter','latex','FontSize',18)
xlabel('Number of iterations','FontSize',18)
xlim([0 30])

% figure('name','NLITERSLACK')
% Heat_Scatter(N_Iter_Slack', L_Iter_Slack',0:max(N_Iter_Slack),0:max(L_Iter_Slack))
% H3=colorbar;
% H3.TickLabels{1}=1;
% for i=2:length(H3.TickLabels)
%  H3.TickLabels{i}=['10^' H3.TickLabels{i}];
% end
% ylabel(H3,'Instances','interpreter','latex');
% H3.FontSize=14
% ylabel('Number of linesteps','interpreter','latex','FontSize',18)
% xlabel('Number of iterations','FontSize',18)


if ColdStart
  figure('name','SLACKCOLD (Case 2)')
A=Hist_2(N_S_CAdd,'Slack, Cold start, p=2'); hold on
LE.FontSize(40,40,24.08)
LE.AspectRatio([2 1.7])
LE.FontSize(42,33,32.08)
yticks(TICZ)
end


end