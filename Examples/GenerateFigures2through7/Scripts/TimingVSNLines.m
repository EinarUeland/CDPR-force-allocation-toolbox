% Author: Einar Ueland. Coauthors Roger Skjetne and Thomas Sauder. 
% email: einar.s.ueland@gmail.com
% January 2020;
% Please cite relevant sources as provided in the readme file. 

clearvars -except AdditionalFigures
 if ~exist('AdditionalFigures')
AdditionalFigures=1;
 end

Init_Motivating_Example

SolParam.NRepeat=10;
Params.fmin=Params.fminv2;
Count=0; %DUMMY
for z=LinesIter(1):LinesIter(end)
Count=Count+1;
Traj.J=[];
for ii=1:size(Traj.Eta,2)
    [Traj.J(:,:,ii)]=Get_JMatrix_mex(Actuator_Bases_large(:,1:z),End_effectors_large(:,1:z),Traj.Eta(:,ii));
end
    
[MDim NACT]=size(Traj.J(:,:,1));

%Expanding dimensions of parameters
Params.fmin=ones(NACT,1)*Params.fmin(1);
Params.fmax=ones(NACT,1)*Params.fmax(1);
Params.OptimalTension=ones(NACT,1)*Params.OptimalTension(1);

%Standard formulation [Compiled, Warm/Cold]
[Time_RCN(Count),EvalMS_CN,Niter_CN,F_R,WErr_RCN,Feasible]=Solve_Over_Traj(1,Params,Traj,SolParam,'Cold','Compiled',0);
[Time_RWN(Count),EvalMS_WN,Niter_WN,F_RWN,WErr_RWN,Feasible]=Solve_Over_Traj(1,Params,Traj,SolParam,'Warm','Compiled',0); %;returnOnInfeas
% s% [TimeW(p-1),EvalMSW,NiterW,F_W,WErr_W]=Solve_Over_Traj(7,Params,Traj,SolParam,'Warm','Compiled',0);

%Slack formulation [Compiled, Warm/Cold]
[T1S(Count),E1,N1_S,Fo1,W1,F1,R1,L1]=Solve_Over_Traj(8,Params,Traj,SolParam,'Warm','Compiled',0,0,0);
[T1SC(Count),E1,N1_SC,Fo1,W1,F1,R1,L1]=Solve_Over_Traj(8,Params,Traj,SolParam,'Cold','Compiled',0,0,0);


AvgIter_CN(Count)=mean(Niter_CN);
AvgIter_WN(Count)=mean(Niter_WN(2:end));
AvgIter_CNS(Count)=mean(N1_SC);
AvgIter_WNS(Count)=mean(N1_S(2:end));

% try
MaxIter_CN(Count)=max(Niter_CN);
MaxIter_WN(Count)=max(Niter_WN(2:end));
MaxIter_CN_S(Count)=max(N1_SC);
MaxIter_WN_S(Count)=max(N1_S(2:end));

EvalMS_CNLog{z-7}=EvalMS_CN;
EvalMS_WNLog{z-7}=EvalMS_WN;


end


figure('name','Fig7c- Trajectory evaluation time vs number of cables')
 plot(LinesIter,Time_RWN,'LineWidth',4*SCALEFACTOR,'color',[Colorzcheme{1} 1],'MarkerSize',4*SCALEFACTOR,'Marker','o','MarkerFaceColor',Colorzcheme{2}); hold on
 plot(LinesIter,T1S,'LineWidth',4*SCALEFACTOR,'color',[Colorzcheme{2} 1],'MarkerSize',4*SCALEFACTOR,'Marker','o','MarkerFaceColor',Colorzcheme{2}); hold on

 
 
 xlabel('Number of Cables')
ylim([0 0.1]);
ylabel(['Trajectory' char(10) 'evaluation time [s]'])
legend('Warm start','Cold start','pseudoinverse')


[H]=legend({'Standard' ,'Slack '},'NumColumns',2)
H.FontSize=34;
 set(gca,'YColor',Colorzcheme{1}); % Set RGB value to what you want

% LE.AspectRatio([4 2])
% LE.FontSize(36,32,36)
LE.AspectRatio([5 1.4]);LE.FontSize(40,44,36)

%BELOW FOLLOWS FIGURES NOT IN PAPER (WARM START AND MORE). 
if AdditionalFigures

figure('name','NLINZ')
 plot(LinesIter,Time_RWN,'LineWidth',4*SCALEFACTOR,'color',[Colorzcheme{2} 1],'MarkerSize',4*SCALEFACTOR,'Marker','o','MarkerFaceColor',Colorzcheme{2}); hold on
 plot(LinesIter,Time_RCN,'LineWidth',4*SCALEFACTOR,'color',[Colorzcheme{1} 1],'MarkerSize',4*SCALEFACTOR,'Marker','o','MarkerFaceColor',Colorzcheme{1}); hold on
xlabel('Number of Cables')
ylim([0 0.1]);
ylabel(['Trajectory' char(10) 'evaluation time [s]'])
legend('Warm start','Cold start','pseudoinverse')


yyaxis right
plot(LinesIter,AvgIter_WN,':','LineWidth',4*SCALEFACTOR,'color',[Colorzcheme{2} 1],'MarkerSize',4*SCALEFACTOR,'Marker','o','MarkerFaceColor',Colorzcheme{2}); hold on
plot(LinesIter,AvgIter_CN,':','LineWidth',4*SCALEFACTOR,'color',[Colorzcheme{1} 1],'MarkerSize',4*SCALEFACTOR,'Marker','o','MarkerFaceColor',Colorzcheme{1}); hold on
ylim([0 6]);  


ylabel(['{Iterations} per ' char(10) 'evaulation (average)'],'Interpreter','latex','color','k')
[H]=legend({'Warm start (\textit{evaluation time})' ,'Cold start (\textit{evaluation time})','Warm start (\textit{iterations})',' Cold start (\textit{iterations})'},'NumColumns',2)
H.FontSize=34;
 set(gca,'YColor',Colorzcheme{1}); % Set RGB value to what you want

% LE.AspectRatio([4 2])
% LE.FontSize(36,32,36)
LE.AspectRatio([5 1.4]);LE.FontSize(40,38,36)
 
figure('name','NLINZ_SLACK')
 plot(LinesIter,T1S,'LineWidth',4*SCALEFACTOR,'color',[Colorzcheme{2} 1],'MarkerSize',4*SCALEFACTOR,'Marker','o','MarkerFaceColor',Colorzcheme{2}); hold on
 plot(LinesIter,T1SC,'LineWidth',4*SCALEFACTOR,'color',[Colorzcheme{1} 1],'MarkerSize',4*SCALEFACTOR,'Marker','o','MarkerFaceColor',Colorzcheme{1}); hold on
xlabel('Number of Cables')
ylim([0 0.1]);
ylabel(['Trajectory' char(10) 'evaluation time [s]'])
legend('Warm start','Cold start','pseudoinverse')

yyaxis right
plot(LinesIter,AvgIter_WNS,':','LineWidth',4*SCALEFACTOR,'color',[Colorzcheme{2} 1],'MarkerSize',4*SCALEFACTOR,'Marker','o','MarkerFaceColor',Colorzcheme{2}); hold on
plot(LinesIter,AvgIter_CNS,':','LineWidth',4*SCALEFACTOR,'color',[Colorzcheme{1} 1],'MarkerSize',4*SCALEFACTOR,'Marker','o','MarkerFaceColor',Colorzcheme{1}); hold on
ylim([0 6]);  

ylabel(['Number of iterations (average)'],'Interpreter','latex')
[H]=legend({'Warm start (\textit{evaluation time})' ,'Cold start (\textit{evaluation time})','Warm start (\textit{iterations})',' Cold start (\textit{iterations})'},'NumColumns',2)
H.FontSize=34;
 set(gca,'YColor',Colorzcheme{1}); 

LE.AspectRatio([5 1.4]);LE.FontSize(40,35,36)
LE.MINBORDER
LE.NumColunms(2)
LE.LegendTransparant(0.6)
% LE.MINBORDER
end