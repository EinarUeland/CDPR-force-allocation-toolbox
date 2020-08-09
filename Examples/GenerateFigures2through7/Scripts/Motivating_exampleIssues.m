% Author: Einar Ueland. Coauthors Roger Skjetne and Thomas Sauder. 
% email: einar.s.ueland@gmail.com
% January 2020;
% Please cite relevant sources as provided in the readme file. 


clearvars -except AdditionalFigures
 if ~exist('AdditionalFigures')
AdditionalFigures=1;
 end
SCALEFACTOR=0.5;
addpath(genpath(pwd))
Double=1;

Init_Motivating_Example
T0=10;
dt=T0/length(Traj.Eta);

XLine=linspace(0,20,length(Traj.Eta));


% Params.fmax=Params.fmax*40
figure('name','Fig2-(a) Geometry')
Print_Geometry_3D(Actuator_Bases,End_effectors,Traj.Eta,2)
view(125,13);set(gca, 'Projection','perspective')
Params.OptimalTension=Params.OptimalTension


%Solve.Quadratic solver (lsqlin)
[Time_RWC,EvalMS_WC,Niter_WC,F_LINES_3,WErr_RWC,Feasible3,Rates_3]=Solve_Over_Traj(5,Params,Traj,SolParam,'Cold','Compiled',0,0,2);
%Solve using the pseudoinverse
[Time_RWC,EvalMS_WC,Niter_WC,F_LINESPINV,WErr_RWC,Feasible,Rates_3]=Solve_Over_Traj(2,Params,Traj,SolParam,'Warm','Compiled',0);
F_LINES_3(:,Feasible3==-1)=nan;%REMOVING INFEASIBLE ONEZ
% plot(F_LINES_3(:,:)')
% a=asl
%FINDING WHERE QUADRATIC AND PSUEODINVERSE FAILS
FMIN=ones(size(F_LINESPINV)).*Params.fmin;
FMAX=ones(size(F_LINESPINV)).*Params.fmax;
H=(min([F_LINESPINV-FMIN;FMAX-F_LINESPINV])<0);
Vc=find(abs(diff(H))>0);
Vc=[1 Vc];
V=XLine(Vc);
V2=find(abs(diff(Feasible3))>0);V2=XLine(V2);

% V=[[0] V];
% close all
%PLOTTING
figure('name','Fig2-(b) Motivating Example')
plot([0 XLine(GridSize) XLine(GridSize) XLine(end)],[Params.fmax(1) Params.fmax(1) Params.fmax(1) Params.fmax(1)],':','color',Colorzcheme{5},'LineWidth',SCALEFACTOR*4); hold on
plot([0 XLine(end)],[Params.OptimalTension(1) Params.OptimalTension(1)],'color',Colorzcheme{4},'LineWidth',SCALEFACTOR*4); hold on

% plot(XLine,F_LINESPINV(:,:),'color','b'); hold on
%  plot(XLine,F_LINES_3(:,:),'color','k');
% a=asl
 
plot(XLine,F_LINES_3(1,:),'color',[0 0 0 1],'LineWidth',SCALEFACTOR*4); hold on;
plot(XLine(Vc(1):Vc(2)),(F_LINESPINV(1,Vc(1):Vc(2))),'color',Colorzcheme{3},'LineWidth',SCALEFACTOR*4);
patch([V(1) V(2) V(2) V(1)], [100 100, 50 50], Colorzcheme{4},'edgecolor',Colorzcheme{2},'FaceAlpha',0.4,'EdgeAlpha',0.1);
patch([V2(1) V2(2) V2(2) V2(1)], [0 0, 50 50], [ 1 0 0],'edgecolor',Colorzcheme{2},'FaceAlpha',0.4,'EdgeAlpha',0.1);
plot([0 XLine(GridSize) XLine(GridSize) XLine(end)],[Params.fmin(1) Params.fmin(1) Params.fmin(1) Params.fmin(1)],':','color',Colorzcheme{5},'LineWidth',SCALEFACTOR*4); hold on

%PATCHING RELEVANT AREAS
patch([V(1) V(2) V(2) V(1)], [0 0, 50 50], Colorzcheme{4},'edgecolor',Colorzcheme{2},'FaceAlpha',0.4,'EdgeAlpha',0.1);
patch([V(3) V(4) V(4) V(3)], [0 0, 50 50], Colorzcheme{4},'edgecolor',Colorzcheme{2},'FaceAlpha',0.4,'EdgeAlpha',0.1);
try
    patch([V(5) XLine(end) XLine(end) V(5)], [0 0, 50 50], Colorzcheme{4},'edgecolor',Colorzcheme{2},'FaceAlpha',0.4,'EdgeAlpha',0.1);
end

% PLOTTING ACCORDING TO PATCHES
for i=1:NACT
    plot(XLine,F_LINES_3(i,:),'color',[0 0 0 1],'LineWidth',SCALEFACTOR*4);
    plot(XLine(1:Vc(1)),F_LINESPINV(i,1:Vc(1)),'--','color',Colorzcheme{3},'LineWidth',SCALEFACTOR*4); hold on
    plot(XLine(Vc(1):Vc(2)),(F_LINESPINV(i,Vc(1):Vc(2))),'color',Colorzcheme{3},'LineWidth',SCALEFACTOR*4)
    plot(XLine(Vc(2):Vc(3)),(F_LINESPINV(i,Vc(2):Vc(3))),'--','color',Colorzcheme{3},'LineWidth',SCALEFACTOR*4)
    plot(XLine(Vc(3):Vc(4)),(F_LINESPINV(i,Vc(3):Vc(4))),'color',Colorzcheme{3},'LineWidth',SCALEFACTOR*4)

    plot(XLine(Vc(4):(end)),(F_LINESPINV(i,Vc(4):(end))),'color',Colorzcheme{3},'LineWidth',SCALEFACTOR*4)

%     plot(XLine(Vc(4):Vc(5)),(F_LINESPINV(i,Vc(4):Vc(5))),'--','color',Colorzcheme{3},'LineWidth',SCALEFACTOR*4)
%     plot(XLine(Vc(5):(end)),(F_LINESPINV(i,Vc(5):(end))),'color',Colorzcheme{3},'LineWidth',SCALEFACTOR*4)

end

H1=legend('{\boldmath $f$}$\mathrm{_{min}}= 5[N]$ , {\boldmath $f$}$\mathrm{_{max}}=40[N]$','{\boldmath $f$}$_{0}=15[N]$','Solved using quadratic programming','Solved using pseudoinverse','Pseudoinverse violates constraints','Equation (2) not feasible');
H1.AutoUpdate=0;
ylabel('\boldmath    $f^*$[N]','interpreter','latex')
xlabel('Time[s]','FontSize',24,'Interpreter','latex')
H1.FontSize=20;
set(H1,'interpreter','latex')

ylim([min(min(F_LINESPINV))-0.5 Params.fmax(1)+0.5])

%BELOW HERE REALY DONE (LABELING LINES)
load Ha
for i=1:NACT
    Hz{i}=text(Ha(i).Position(1),Ha(i).Position(2),['(' num2str(i) ')'],'FontSize',SCALEFACTOR*36,'color',[0.3 0.3 0.3]);
end
 
%PLOTT PROPERTIES
LE.AspectRatio([5 2]); LE.FontSize(40,34,36)
LE.MINBORDER


%BELOW FOLLOWS FIGURES NOT IN PAPER (WARM START AND MORE). 

if AdditionalFigures
pause(1)
fprintf(' \n Printing additional Figures \n')
pause(1)



figure('name','Trajectories Motivating Example')
for i=1:3
    plot(XLine,Traj.Eta(i,:),'LineWidth',SCALEFACTOR*4,'color',Colorzcheme{i}); hold on
end
for i=4:6
    plot(XLine,Traj.Eta(i,:),':','LineWidth',SCALEFACTOR*4,'color',Colorzcheme{i}); hold on
end

[Hv]=legend({'x[m]  \quad ','y[m]   ','z[m]   ','$\phi$[rad] ','$\theta$[rad] ','$\psi$[rad] '},'NumColumns',2);

xlabel('Time[s]','FontSize',24,'Interpreter','latex'); hold on
ylabel('Magnitude','FontSize',24,'Interpreter','latex')

LE.AspectRatio([4 2]);LE.FontSize(40,32,36)


end