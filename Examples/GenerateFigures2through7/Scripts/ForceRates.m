% Author: Einar Ueland. Coauthors Roger Skjetne and Thomas Sauder. 
% email: einar.s.ueland@gmail.com
% January 2020;
% Please cite relevant sources as provided in the readme file. 


clearvars -except AdditionalFigures
 
SCALEFACTOR=0.5;
%DECLATIONS ETC.
GridSize=1e4; 
Init_Motivating_Example
T0=10
dt=T0/length(Traj.Eta)
XLine=linspace(0,T0,length(Traj.Eta));


%GENERATING DATA FOR DIFFERENT VALUES OF C. 


Params.c1=0.1
 Params.c2=0.1
[Time_RWC,EvalMS_WC,Niter_WC,F_LINES_1,WErr_RWC,Feasible,Rates1,LineIter,Slog]=Solve_Over_Traj(1,Params,Traj,SolParam,'Warm','Compiled',0,0,0);

 Params.c1=0.02
 Params.c2=0.02
[Time_RWC,EvalMS_WC,Niter_WC,F_LINES_2,WErr_RWC,Feasible,Rates2]=Solve_Over_Traj(1,Params,Traj,SolParam,'Warm','Compiled',0,0,0);
%c=0
[Time_RWC,EvalMS_WC,Niter_WC,F_LINES_3,WErr_RWC,Feasible,Rates3]=Solve_Over_Traj(5,Params,Traj,SolParam,'Cold','Compiled',0,0,0);

figure('name','Fig4(a) Target forces with varying c')
plot([0 XLine(end)],[Params.fmin(1) Params.fmin(1)],':','color',Colorzcheme{5},'LineWidth',4*SCALEFACTOR); hold on
plot([0 XLine(end)],[Params.OptimalTension(1) Params.OptimalTension(1)],'color',Colorzcheme{4},'LineWidth',4*SCALEFACTOR); hold on


i=NACT;
 plot(XLine,F_LINES_1(i,:),'color',Colorzcheme{1},'LineWidth',4*SCALEFACTOR);hold on
 plot(XLine,F_LINES_2(i,:),'color',Colorzcheme{3},'LineWidth',4*SCALEFACTOR);
 plot(XLine,F_LINES_3(i,:),'color',Colorzcheme{2},'LineWidth',4*SCALEFACTOR); 
 plot([0 XLine(end)],[Params.fmax(1) Params.fmax(1)],':','color',Colorzcheme{5},'LineWidth',4*SCALEFACTOR); hold on
 text(5,F_LINES_3(NACT,5/dt)+0.55,['(' num2str(i) ')'],'FontSize',36*SCALEFACTOR)
H1=legend({'{\boldmath $f$}$\mathrm{_{min}}= 5[N]$ , {\boldmath $f$}$\mathrm{_{max}}=40[N]$','{\boldmath $f$}$_{0}=15[N]$','$c_1= 0.1 , c_2= 0.1$','$c_1= 0.02 , c_2= 0.02$','$c_1= 0 , c_2= 0$'},'Interpreter','latex');
 H1.AutoUpdate=0;
 ylabel('{\boldmath $f$}$^*[N]$','Interpreter','latex')

xlabel('Time[s]','FontSize',24,'Interpreter','latex')
  H1.FontSize=20;
set(H1,'interpreter','latex')

for i=1:NACT-1
 plot(XLine,F_LINES_1(i,:),':','color',[Colorzcheme{1} 0.4   ],'LineWidth',4*SCALEFACTOR); hold on
plot(XLine,F_LINES_2(i,:),':','color',[Colorzcheme{3} 0.2],'LineWidth',4*SCALEFACTOR);
plot(XLine,F_LINES_3(i,:),':','color',[Colorzcheme{2} 0.2],'LineWidth',4*SCALEFACTOR);
text(5,F_LINES_3(i,5/dt)+0.55,['(' num2str(i) ')'],'FontSize',36*SCALEFACTOR)

end
 ylim([Params.fmin(1)-0.5 Params.fmax(1)+0.5])
%PLOT PROPERTIES
% LE.AspectRatio([6 1.75]);LE.FontSize(40,32,36)
LE.AspectRatio([5 2]); LE.FontSize(40,40,36); LE.MINBORDER
LE.NumColunms(1)
LE.LegendTransparant(0.6)




% Plotting Rates
for i=1:NACT
DRates3(i,:)=diff(Rates3(i,:));
DRates3d(i,:)=([DRates3(i,1:end) DRates3(i,end)]+[DRates3(i,1) DRates3(i,1:end) ])/2;
Rates3(i,abs(DRates3d(i,:))>0.2*dt)=nan;
end


%PLOTTING
figure('name','Fig.4(b)-Force rates with varying c')

plot(XLine,Rates1(i,:)/dt,'color',Colorzcheme{1},'LineWidth',4*SCALEFACTOR);hold on
 plot(XLine,Rates2(i,:)/dt,'color',Colorzcheme{3},'LineWidth',4*SCALEFACTOR);
  plot(XLine,Rates3(i,:)/dt,'color',Colorzcheme{2},'LineWidth',4*SCALEFACTOR); 
 for i=1:NACT-1
plot(XLine,Rates1(i,:)/dt,':','color',[Colorzcheme{1} 0.4],'LineWidth',4*SCALEFACTOR); hold on
 plot(XLine,Rates2(i,:)/dt,':','color',[Colorzcheme{3} 0.2],'LineWidth',4*SCALEFACTOR);
plot(XLine,Rates3(i,:)/dt,':','color',[Colorzcheme{2} 0.2],'LineWidth',4*SCALEFACTOR);
 end
 
 %MORE PLOTT PROPERTIES
H2=legend('$c_1= 0.1 , c_2= 0.1$','$c_1= 0.02 , c_2= 0.02$','$c_1= 0 , c_2= 0$');
H2.AutoUpdate=0;
H2.FontSize=20;
set(H2,'interpreter','latex')
ylabel('{\boldmath $\dot{f}$}$^* [N/s]$','interpreter','latex','FontSize',16)
xlabel('Time[s]','FontSize',24,'Interpreter','latex')
ylim([-33 24])
LE.AspectRatio([5 2]); LE.FontSize(40,40,36); LE.MINBORDER
LE.NumColunms(1)
LE.LegendTransparant(0.6)

% save Textlog H
load Textlog H
for i=1:NACT
  Hz{i}=text(H{i}.Position(1)*1e-2,H{i}.Position(2),['(' num2str(i) ')'],'FontSize',36*SCALEFACTOR);
end

