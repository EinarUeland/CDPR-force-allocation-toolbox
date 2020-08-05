% Author: Einar Ueland. Coauthors Roger Skjetne and Thomas Sauder. 
% email: einar.s.ueland@gmail.com
% January 2020;
% Please cite relevant sources as provided in the readme file. 



clearvars -except AdditionalFigures
 if ~exist('AdditionalFigures')
AdditionalFigures=1;
 end



GridSize=1e3;
Init_Motivating_Example
SolParam.NRepeat=10;SolParam.Itermax=1e5;
PEND=10;
 for p=2:1:PEND
  Params.P=p;
 [TimeC(p-1),EvalMSC{p},NiterC{p},F_C{p},WErr_C{p}]=Solve_Over_Traj(7,Params,Traj,SolParam,'Cold','Compiled',0);
  [TimeW(p-1),EvalMSW{p},NiterW{p},F_W{p},WErr_W{p}]=Solve_Over_Traj(7,Params,Traj,SolParam,'Warm','Compiled',0);
  [TimeCS(p-1),EvalMSCS{p},NiterCS{p},F_CS{p},WErr_CS{p}]=Solve_Over_Traj(9,Params,Traj,SolParam,'Cold','Compiled',0);
  [TimeWS(p-1),EvalMSWS{p},NiterWS{p},F_WS{p},WErr_WS{p}]=Solve_Over_Traj(9,Params,Traj,SolParam,'Warm','Compiled',0);
 end
 
 figure('name','Fig.7d Trajectory evaluation time as function of changing p')  
plot(2:PEND,TimeW,'LineWidth',SCALEFACTOR*4,'color',Colorzcheme{1},'MarkerSize',SCALEFACTOR*4,'Marker','o','MarkerFaceColor',Colorzcheme{2}); hold on
plot(2:PEND,TimeWS,'LineWidth',SCALEFACTOR*4,'color',Colorzcheme{2},'MarkerSize',SCALEFACTOR*4,'Marker','o','MarkerFaceColor',Colorzcheme{2}); hold on
ylim([0 .1])
H3=legend({'Standard','Slack'},'NumColumns',2);
 xlabel('$\mathbf{p}$','interpreter','latex')
ylabel(['Trajectory' char(10) 'evaluation time [s]'])

LE.SCALEFACTOR=SCALEFACTOR;
LE.AspectRatio([5 1.4]);LE.FontSize(40,45,36)
LE.MINBORDER


if AdditionalFigures


figure('name','PEFFECTSLACK')  
plot(2:PEND,TimeW,'LineWidth',SCALEFACTOR*4,'color',Colorzcheme{2},'MarkerSize',SCALEFACTOR*4,'Marker','o','MarkerFaceColor',Colorzcheme{2}); hold on
plot(2:PEND,TimeC,'LineWidth',SCALEFACTOR*4,'color',Colorzcheme{1},'MarkerSize',SCALEFACTOR*4,'Marker','o','MarkerFaceColor',Colorzcheme{1}); hold on
plot(2:PEND,TimeWS,':','LineWidth',SCALEFACTOR*4,'color',Colorzcheme{2},'MarkerSize',SCALEFACTOR*4,'Marker','o','MarkerFaceColor',Colorzcheme{2}); hold on
plot(2:PEND,TimeCS,':','LineWidth',SCALEFACTOR*4,'color',Colorzcheme{1},'MarkerSize',SCALEFACTOR*4,'Marker','o','MarkerFaceColor',Colorzcheme{1}); hold on
 ylim([0 .1])
H3=legend({'Warm start','Cold start','Warm start, slack','Cold start, slack'},'NumColumns',2);
 xlabel('$\mathbf{p}$','interpreter','latex')
ylabel(['Trajectory' char(10) 'evaluation time [s]'])

LE.AspectRatio([5 1.4]);LE.FontSize(40,38,36)


end

