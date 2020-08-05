% Author: Einar Ueland. Coauthors Roger Skjetne and Thomas Sauder. 
% email: einar.s.ueland@gmail.com
% January 2020;
% Please cite relevant sources as provided in the readme file. 


clearvars -except AdditionalFigures
 if ~exist('AdditionalFigures')
AdditionalFigures=1;
 end
pause(5)
GridSize=1e3
Init_Motivating_Example
fprintf('For good computational time data: \n-you should set the priority of this computer task to real-time. (in windows set priority to "real-time" in task manager).\n-If You may want to turn internet of to prevent automatic updates interfaring \n\n')
SolParamSlow=SolParam;
SolParamSlow.NRepeat=1;
Params.P=2;
SolParam.NRepeat=25; %REPEATING MULTIPLE TIMES FOR MORE STABLE TIME ESTIMATES.
WErr_Ca=nan*ones(6,1000);Time_Ca=nan;

M=2; 


%GOING through the motivating example using varying solver setups. 
 %StandardFormulation, [Compiled/Noncompile, Warm/Cold]
[Time_RWN,EvalMS_WN,Niter_WN,F_RWN,WErr_RWN,Feasible,Rates,LineIter]=Solve_Over_Traj(1,Params,Traj,SolParam,'Warm','NonCompiled',0);pause(1)
[Time_RCN,EvalMS_CN,Niter_CN,F_R,WErr_RCN,Feasible]=Solve_Over_Traj(1,Params,Traj,SolParam,'Cold','NonCompiled',0);pause(1)
[Time_RWC,EvalMS_WC,Niter_WC,F_RC,WErr_RWC]=Solve_Over_Traj(1,Params,Traj,SolParam,'Warm','Compiled',0);pause(1)
[Time_RCC,EvalMS_CC,Niter_CC,F,WErr_RCC]=Solve_Over_Traj(1,Params,Traj,SolParam,'Cold','Compiled',0);pause(1)

%Slack Formulation [Compiled, Warm/Cold]
[Time_TotSW,EvalMS_WCS,Niter_WCS,F_LINES2,W_Error,Feasible,Rates,LineIterSW,Slog]=Solve_Over_Traj(8,Params,Traj,SolParam,'Warm','Compiled',0);pause(1)
[Time_TotSC,EvalMS_CCS,Niter_CCS,F_LINES,W_Error,Feasible,Rates,LineIterSC,Slog]=Solve_Over_Traj(8,Params,Traj,SolParam,'Cold','Compiled',0);pause(1)

%Pseudouinverse [Compiled/NonCompiled]
[Time_PinvN,EvalMS_PinvN,Niter_PinvN,F_PinvN,WErr_PinvN]=Solve_Over_Traj(2,Params,Traj,SolParam,'Cold','NonCompiled',0);pause(1)
[Time_PinvC,EvalMS_PinvC,Niter_PinvC,F_PinvC,WErr_PinvC]=Solve_Over_Traj(2,Params,Traj,SolParam,'Cold','Compiled',0);pause(1)

%Fmincon 
[Time_Fmin,EvalMS_Fmin,Niter_Fmin,F_Fmin,WErr_Fmin]=Solve_Over_Traj(3,Params,Traj,SolParamSlow,'Warm','Compiled',0);pause(1)

%LsqLin
[Time_Lsq,EvalMS_Lsq,Niter_Lsq,F_Lsq,WErr_Lsq]=Solve_Over_Traj(5,Params,Traj,SolParamSlow,'Warm','Compiled',0);    pause(1)
    

LW=3*SCALEFACTOR;




%PLOTTING FIGURES.

figure('name','Fig7a- Computation Time over trajectory') %
plot(EvalMS_WC(2:end),'LineWidth',LW,'color',Colorzcheme{1}); hold on
plot(EvalMS_WCS(2:end),'LineWidth',LW,'color',Colorzcheme{2});
plot(EvalMS_PinvC(2:end),'LineWidth',LW,'color',Colorzcheme{3});
% [H]=legend({'Alg.1,warm start','Alg.1,compiled,warm start','Alg.1,cold start','Alg.1,compiled,cold start','Pseudoinverse$^*$','Pseudoinverse$^*$,compiled','Alg.1,slack,compiled,warm start','Alg.1,slack,compiled,cold start'},'NumColumns',4);

[H]=legend({'Standard','Slack','Pseudo-inverse'},'NumColumns',3);


set(H,'interpreter','latex')
ylim([0 150])
xlabel('Evaluation number')
ylabel(['Evaluations' char(10) 'per millisecond'])

LE.AspectRatio([6 1.85])

if AdditionalFigures

%BELOW FOLLOWS FIGURES NOT IN PAPER (WARM START AND MORE). 
pause(1)
fprintf(' \n Printing additional Figures \n')
pause(1)


figure('name','Computation Time over trajectory BIG Version') %EVAL per Millisecond
plot(EvalMS_WN(2:end),'LineWidth',LW*1.4,'color',Colorzcheme{1},'LineStyle',':'); hold on;
plot(EvalMS_WC(2:end),'LineWidth',LW,'color',Colorzcheme{1});
plot(EvalMS_CN(2:end),'LineWidth',LW*1.4,'color',Colorzcheme{2},'LineStyle',':') ;
plot(EvalMS_CC(2:end),'LineWidth',LW,'color',Colorzcheme{2});
plot(EvalMS_PinvN(2:end),'LineWidth',LW*1.4,'color',Colorzcheme{3},'LineStyle',':'); 
plot(EvalMS_PinvC(2:end),'LineWidth',LW,'color',Colorzcheme{3});
plot(EvalMS_WCS(2:end),'LineWidth',LW,'color',Colorzcheme{4});
plot(EvalMS_CCS(2:end),'color',Colorzcheme{5},'LineWidth',LW);
 plot(EvalMS_WN(2:end),'LineWidth',LW*1.4,'color',Colorzcheme{1},'LineStyle',':'); hold on; plot(EvalMS_CN(2:end),'LineWidth',LW*1.4,'color',Colorzcheme{2},'LineStyle',':') ;
 plot(EvalMS_PinvN(2:end),'LineWidth',LW*1.4,'color',Colorzcheme{3},'LineStyle',':');
[H]=legend({'Alg.1,warm start','Alg.1,compiled,warm start','Alg.1,cold start','Alg.1,compiled,cold start','Pseudoinverse$^*$','Pseudoinverse$^*$,compiled','Alg.1,slack,compiled,warm start','Alg.1,slack,compiled,cold start'},'NumColumns',4);

    LE.AspectRatio([6 1.85])

set(H,'interpreter','latex')
ylim([0 150])
xlabel('Evaluation number')
ylabel(['Evaluations' char(10) 'per millisecond'])

%NUMBER OF ITERATIONS
figure('name','NITERUS')
plot(Niter_CN,'LineWidth',4,'color',Colorzcheme{1}); hold on; plot(Niter_WN,'LineWidth',4,'color',Colorzcheme{2});
plot(Niter_CCS,'--','LineWidth',4,'color',[0.5 0.5 0.5]); hold on; plot(Niter_WCS,'--','LineWidth',4,'color',Colorzcheme{7});

H=legend('Cold start','Warm start','Cold start,slack','Warm start,slack');
H.ItemTokenSize = [45,30];
xlabel('Evaluation number');
ylabel('Number of Iterations');
LE.AspectRatio([6 1.85]);LE.FontSize(40,38,36)

figure('name','NITERUSWarm')
 plot(Niter_WN,'LineWidth',4,'color',Colorzcheme{1}); hold on
plot(Niter_WCS,'--','LineWidth',4,'color',Colorzcheme{2});

H=legend('Standard','Slacked');
H.ItemTokenSize = [45,30];
xlabel('Evaluation number');
ylabel('Number of Iterations');
LE.AspectRatio([6 1.85]);LE.FontSize(40,45,36)
xlim([2.3 1000])



%FOLLOWING NOTATION OF XXX.
% a=Asl
figure('name','NITERUS')
plot(Niter_CN,'LineWidth',4,'color',Colorzcheme{1}); hold on; plot(Niter_WN,'LineWidth',4,'color',Colorzcheme{2});
plot(Niter_CCS,'--','LineWidth',4,'color',[0.5 0.5 0.5]); hold on; plot(Niter_WCS,'--','LineWidth',4,'color',Colorzcheme{7});

H=legend('Cold start','Warm start','Cold start,slack','Warm start,slack');
H.ItemTokenSize = [45,30];
xlabel('Evaluation number');
ylabel('Number of Iterations');
LE.AspectRatio([6 1.85]);LE.FontSize(40,38,36)
%BELOW FOLLOWS FIGURES NOT USED IN PAPER:
K=[-5:0.1:5];
for k=1:length(K)
    TAUMAT(k)=10^K(k);
  Params.c1=TAUMAT(k);
  Params.c2=TAUMAT(k);
[TimeTau(k)]=Solve_Over_Traj(1,Params,Traj,SolParamSlow,'Warm','Compiled',0,0,0);
end






%If this is not relatively close to zero, then some of the sovlers have failed...
WerrorSum=sum(sum(abs([WErr_RWN;WErr_RCN;WErr_RWC;WErr_RCC;WErr_PinvN;WErr_PinvC;WErr_Fmin;WErr_Ca;WErr_Lsq])));
H=abs([WErr_RWN;WErr_RCN;WErr_RWC;WErr_RCC;WErr_PinvN;WErr_PinvC;WErr_Fmin;WErr_Ca;WErr_Lsq]);
if WerrorSum>1e-3
    error('Werr is larger than expected')
end


figure('name','Trajectory times')
TIMEZ=[Time_PinvC Time_PinvN Time_RWC Time_RCC Time_RWN Time_RCN Time_Ca Time_Fmin Time_Lsq];
Colorz={'y',Colorzcheme{7},'c',Colorzcheme{2},'g','b','w',Colorzcheme{1},[0.5 0.5 0.5]}
for i=1:9
    semilogy(i,[TIMEZ(i)],'o','MarkerFaceColor',Colorzcheme{i}) ;hold on
end
legend('1 Compiled -Pseudoinverse','2- Pseudo Inverse','3-Alg.1 WC ','4-Alg.1 NC','5Alg.1 WN','6-Alg.1 CN','7- IPOPT solver, MATLAB implementation','8- fmincon V1','9 lsqmin','x pinvImproved')
title(['Time running ' num2str(length(Traj.Eta)) ' iterations']); hold on
ylabel('Time  [seconds]')
H=ylim;
ylim([H(1)/2 H(2)*2]);





figure(4) %VERIFYING WERR PLOT
% M1=max(max(abs(F_RWN-F_Ca)));
M2=max(max(abs(F_RWN-F_Fmin)));
% M3=max(max(abs(F_Ca-F_Fmin)));
if M2>1e-3
warning('Different methods dont yield same result')
end

figure(5) %FEASIBLITY PLOT
yyaxis left


hold on
%FEASIBILITY:
plot(sum(abs(WErr_RWN)),'LineWidth',2,'color','b'); hold on
plot(sum(abs(WErr_Ca)),'LineWidth',2,'color',Colorzcheme{2});
plot(sum(abs(WErr_Fmin)),'LineWidth',2,'color',Colorzcheme{7});
title('Feasibility: Werr=  $\left| \textbf{W}_t - \textbf{J} \textbf{f}_t \right|$','interpreter','latex'); hold on
ylabel('$\textbf{W}_{err}$','interpreter','latex')

% plot(EXITFLAG,'LineWidth',4,'color',Colorzcheme{1})

HU=2*max(max(abs([WErr_RWN WErr_Fmin])));

  patch([-10 -10 -10 -10], [0 0, HU HU], 'g','edgecolor','g','FaceAlpha',0.2,'EdgeAlpha',0.1);
  patch([-10 -10 -10 -10], [0 0, HU HU], Colorzcheme{2},'edgecolor',Colorzcheme{2},'FaceAlpha',0.2,'EdgeAlpha',0.1);
k1=legend('Custom Alg.1 Solver','IPOPT solver implementation','fmincon','Feasibile condition','Infeasible Condition');
k1.AutoUpdate='off';
EXITFLAG=ones(1,GridSize);
for i=1:length(EXITFLAG)
    if EXITFLAG(i)==1
   patch([i i+1 i+1 i], [0 0, HU HU], 'g','edgecolor','g','FaceAlpha',0.2,'EdgeAlpha',0.1);
    else
patch([i i+1 i+1 i], [0 0, HU HU], Colorzcheme{2},'edgecolor',Colorzcheme{2},'FaceAlpha',0.2,'EdgeAlpha',0.1)  ;  
    end
end
xlim([0 GridSize])
ylim([0 HU])

end
