% Author: Einar Ueland. Coauthors Roger Skjetne and Thomas Sauder. 
% email: einar.s.ueland@gmail.com
% January 2020;
% Please cite relevant sources as provided in the readme file. 

clearvars -except AdditionalFigures
if ~exist('AdditionalFigures')
AdditionalFigures=1;
end
ShowCold=0;

COUNT=0;
%ITERATING OVER VARYING GRIDSIZE.
for TSTEP=1:0.1:5
    COUNT=COUNT+1;
    GridSize=1*10^TSTEP;
TLOG(COUNT)=GridSize;
Init_Motivating_Example
[Time_RWC,EvalMS_WC,Niter_WC,F_R,WErr_RWC]=Solve_Over_Traj(1,Params,Traj,SolParam,'Warm','Compiled',0);
[Time_RCC,EvalMS_CC,Niter_CC,F,WErr_RCC]=Solve_Over_Traj(1,Params,Traj,SolParam,'Cold','Compiled',0);
[Time_RWCS,EvalMS_WCS,Niter_WCS,F_RS,WErr_RWCS]=Solve_Over_Traj(8,Params,Traj,SolParam,'Warm','Compiled',0);
[Time_RCCS,EvalMS_CCS,Niter_CCS,FS,WErr_RCCSS]=Solve_Over_Traj(8,Params,Traj,SolParam,'Cold','Compiled',0);

%LOGGING DATA IN EACH TIME-STEP MAX AND AVERAGE.
TIMERLOG(COUNT)=Time_RWC*1e3/GridSize;
TIMERLOGCOLD(COUNT)=Time_RCC*1e3/GridSize;
AvgWarm(COUNT)=mean(Niter_WC(2:end));
MaxWarm(COUNT)=max(Niter_WC(2:end));
AvgCold(COUNT)=mean(Niter_CC(2:end));
MaxCold(COUNT)=max(Niter_CC(2:end));
TIMERLOGS(COUNT)=Time_RWCS*1e3/GridSize;
TIMERLOGCOLDS(COUNT)=Time_RCCS*1e3/GridSize;
AvgWarmS(COUNT)=mean(Niter_WCS(2:end));
MaxWarmS(COUNT)=max(Niter_WCS(2:end));
AvgColdS(COUNT)=mean(Niter_CCS(2:end));
MaxColdS(COUNT)=max(Niter_CCS(2:end));
end



figure('name','Fig7b Number of iterations with changing grid size')

semilogx(TLOG,AvgWarmS,'LineWidth',SCALEFACTOR*4,'color',Colorzcheme{1}); hold on
semilogx(TLOG,AvgWarm,'LineWidth',SCALEFACTOR*4,'color',Colorzcheme{2});
semilogx(TLOG,MaxWarm,':','LineWidth',SCALEFACTOR*4,'color',Colorzcheme{1});
semilogx(TLOG,MaxWarmS,':','LineWidth',SCALEFACTOR*4,'color',Colorzcheme{2});
H4=legend('Mean iterations, standard','Mean iterations, slack','Max iterations, standard','Max iterations, slack');
ylim([0 max([MaxWarm MaxWarmS]+1)])

h=xlabel('Number of evaluations $K$')
set(h,'Interpreter','latex')
ylabel('Number of iterations')
LE.AspectRatio([5 1.4]);LE.FontSize(40,30,36)
LE.MINBORDER
LE.NumColunms(2)
LE.LegendTransparant(0.6)



%BELOW FOLLOWS FIGURES NOT IN PAPER (WARM START AND MORE). 
if AdditionalFigures
figure('name','GridSIZEPRO')
semilogx(TLOG,AvgCold,'LineWidth',SCALEFACTOR*4,'color',Colorzcheme{1}); hold on
semilogx(TLOG,AvgWarm,'LineWidth',SCALEFACTOR*4,'color',Colorzcheme{2});
semilogx(TLOG,MaxCold,':','LineWidth',SCALEFACTOR*4,'color',Colorzcheme{1});
semilogx(TLOG,MaxWarm,':','LineWidth',SCALEFACTOR*4,'color',Colorzcheme{2});
H4=legend('Mean iterations, cold start','Mean iterations, warm start','Max iterations, cold start','Max iterations, warm start');
ylim([0 max([MaxCold]+1)])

h=xlabel('Number of evaluations $K$')
set(h,'Interpreter','latex')
ylabel('Number of iterations')
LE.AspectRatio([5 1.4]);LE.FontSize(40,30,36)
LE.MINBORDER
LE.NumColunms(2)
LE.LegendTransparant(0.6)
end




