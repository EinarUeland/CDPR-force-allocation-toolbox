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
set(0, 'DefaultLineLineWidth', 4*SCALEFACTOR);

XLine=linspace(0,10,length(Traj.Eta));

%NumberData
load TEXT TextFslack TextFslack2N

%SETTING UP DIFFERENT PROPERTIES FOR SLACK VERSION
SolParam1=SolParam;SolParam2=SolParam;SolParam3=SolParam; SolParam4=SolParam;
b_Series=[20 20 200 200];
EpsilonSeries=[10e-3 10e-7 10e-3 10e-5];
SolParam1.b_vector=ones(6,1)*b_Series(1); SolParam1.Epsilon=EpsilonSeries(1);
SolParam2.b_vector=ones(6,1)*b_Series(2); SolParam2.Epsilon=EpsilonSeries(2);
SolParam3.b_vector=ones(6,1)*b_Series(3); SolParam3.Epsilon=EpsilonSeries(3);
SolParam4.b_vector=ones(6,1)*b_Series(4); SolParam4.Epsilon=EpsilonSeries(4);
%SETTING UP LEGENDS
for i=1:4
    Legend{i}=['$b=' num2str(b_Series(i)) ', \epsilon=10^{' num2str(log10(EpsilonSeries(i))-1) '}$'];
end
Legend00=Legend;
LEGEND2={Legend{1:2},'{\boldmath $f$} $\mathrm{_{min}}=5[N]$, {\boldmath $f$}$\mathrm{_{max}}=40[N]$', Legend{3:4}};
LEGEND3={Legend{1:2},'{\boldmath $f$}$\mathrm{_{min}}= 7[N]$, {\boldmath $f$}$\mathrm{_{max}}=38[N]$', Legend{3:4}};



%Getting force trajectories with different solver parameters
[T1,E1,N1,Fo1,W1,F1,R1,L1]=Solve_Over_Traj(8,Params,Traj,SolParam1,'Warm','Compiled',0,0,0);
[T2,E2,N2,Fo2,W2,F2,R2,L2]=Solve_Over_Traj(8,Params,Traj,SolParam2,'Warm','Compiled',0,0,0);
[T3,E3,N3,Fo3,W3,F3,R3,L3]=Solve_Over_Traj(8,Params,Traj,SolParam3,'Warm','Compiled',0,0,0);
[T4,E4,N4,Fo4,W4,F4,R4,L4]=Solve_Over_Traj(8,Params,Traj,SolParam4,'Warm','Compiled',0,0,0);

%Verifying when proposition 2 holds
[S_Bound, S_Inf,Prop2_Ass1]=Proposition_2(Traj,SolParam1,Params,W1,Fo1,1);
[S_Bound, S_Inf,Prop2_Ass2]=Proposition_2(Traj,SolParam2,Params,W2,Fo2,1);
[S_Bound, S_Inf,Prop2_Ass3]=Proposition_2(Traj,SolParam3,Params,W3,Fo3,1);
[S_Bound, S_Inf,Prop2_Ass4]=Proposition_2(Traj,SolParam4,Params,W4,Fo4,1);

%PLOTTING RESULTS FIGURE
figure('name','Fig5(a) Resulting forces, slack')
NACT=3;
plot([0 10],[Params.fmin(1) Params.fmin(1)],':','color',Colorzcheme{5},'LineWidth',4*SCALEFACTOR); hold on
plot(XLine,Fo1(NACT,:)','color',Colorzcheme{3}); hold on
plot(XLine,Fo2(NACT,:)','color',Colorzcheme{2}); hold on
plot(XLine,Fo3(NACT,:)','color',Colorzcheme{4}); hold on
plot(XLine,Fo4(NACT,:)','color',Colorzcheme{1}); hold on
plot([0 10],[Params.fmax(1) Params.fmax(1)],':','color',Colorzcheme{5},'LineWidth',4*SCALEFACTOR); hold on
plot(XLine,Fo3(NACT,:)','color',Colorzcheme{4}); hold on
plot(XLine,Fo1([1:NACT-1 NACT+1:end],:)','color',[Colorzcheme{3} 0.25]); hold on
plot(XLine,Fo2([1:NACT-1 NACT+1:end],:)','color',[Colorzcheme{2} 0.25] ); hold on
plot(XLine,Fo4([1:NACT-1 NACT+1:end],:)','color',[Colorzcheme{1} 0.25]); hold on
plot(XLine,Fo3([1:NACT-1 NACT+1:end],:)','color',[Colorzcheme{4} 0.25]); hold on
plot([0 10],[Params.fmax(1) Params.fmax(1)],':','color',Colorzcheme{5},'LineWidth',4*SCALEFACTOR); hold on
plot([0 10],[Params.fmin(1) Params.fmin(1)],':','color',Colorzcheme{5},'LineWidth',4*SCALEFACTOR); hold on
plot(XLine,Fo1(NACT,:)','color',Colorzcheme{3}); hold on
plot(XLine,Fo2(NACT,:)','color',Colorzcheme{2}); hold on
plot(XLine,Fo3(NACT,:)','color',Colorzcheme{4}); hold on
plot(XLine,Fo4(NACT,:)','color',Colorzcheme{1}); hold on
plot(XLine,Fo3(NACT,:)','color',Colorzcheme{4}); hold on

for i=1:8
    Hz2{i}=text(TextFslack{i}.Position(1),TextFslack{i}.Position(2),['(' num2str(i) ')'],'FontSize',36*SCALEFACTOR);
end

xlabel('Time[s]','FontSize',24,'Interpreter','latex') 
ylabel('{\boldmath $f$}$_s^{*}[N]$','Interpreter','latex')
ylim([0 41])
% LE.AspectRatio([6 1.85]);LE.FontSize(40,32,36)
% legend(LEGEND2,'NumColumns',2,'Interpreter','latex')


LEGEND4=[LEGEND2(3) LEGEND2(1:2) LEGEND2(4:5)]
legend(LEGEND4,'NumColumns',2,'Interpreter','latex')
LE.NumColunms(1)
LE.LegendTransparant(0.6)
% LE.AspectRatio([6 1.85]);LE.FontSize(40,32,36)
LE.AspectRatio([5 2]); LE.FontSize(40,34,36); 



figure('name','Fig6(a) slack magnutide')
semilogy([0 0],[0 0],'color',Colorzcheme{3}); hold on
semilogy([0 0],[0 0],'color',Colorzcheme{2})
semilogy([0 0],[0 0],'color',Colorzcheme{4})
semilogy([0 0],[0 0],'color',Colorzcheme{1})

%W1a
W1A=W1;W1B=W1;
W1A(:,Prop2_Ass1<0.5)=nan;
W1B(:,Prop2_Ass1>0.5)=nan;
semilogy(XLine,max(abs(W1A)),'color',Colorzcheme{3}); hold on
semilogy(XLine,max(abs(W1B)),':','color',Colorzcheme{3});
%W1b
W2A=W2;W2B=W2;
W2A(:,Prop2_Ass2<0.5)=nan;
W2B(:,Prop2_Ass2>0.5)=nan;
semilogy(XLine,max(abs(W2A)),'color',Colorzcheme{2}); hold on
semilogy(XLine,max(abs(W2B)),':','color',Colorzcheme{2});
%W2
W1A=W3;W1B=W3;
W1A(:,Prop2_Ass3<0.5)=nan;
W1B(:,Prop2_Ass3>0.5)=nan;
semilogy(XLine,max(abs(W1A)),'color',Colorzcheme{4}); hold on
semilogy(XLine,max(abs(W1B)),':','color',Colorzcheme{4});
%W2b
W1A=W4;W1B=W4;
W1A(:,Prop2_Ass4<0.5)=nan;
W1B(:,Prop2_Ass4>0.5)=nan;
semilogy(XLine,max(abs(W1A)),'color',Colorzcheme{1}); hold on
semilogy(XLine,max(abs(W1B)),':','color',Colorzcheme{1});
semilogy(XLine,max(abs(W2A)),'color',[Colorzcheme{2} 0.6]); hold on

legend({Legend{1:4}},'Interpreter','latex')
ylabel(' $|${\boldmath $s$}$^*|_\infty$ ','Interpreter','latex')   
xlabel('Time[s]','FontSize',24,'Interpreter','latex')
grid on
% LE.FontSize(35,31,31)
% LE.AspectRatio([[6 1.85]])
LE.LegendTransparant(0.6)
% LE.AspectRatio([6 1.85]);LE.FontSize(40,32,36)
LE.AspectRatio([5 1.6]); LE.FontSize(40,40,36); 


%Performing same test, but reducing tmin and tmax limits by 2 N.
Params2=Params;
Params2.fmin=Params.fmin+2;
Params2.fmax=Params.fmax-2;

%Getting force trajectories with different solvers
[T1,E1,N1s,Fo1,W1,F1,R1,L1]=Solve_Over_Traj(8,Params2,Traj,SolParam1,'Warm','Compiled',0,0,0);
[T2,E2,N2s,Fo2,W2,F2,R2,L2]=Solve_Over_Traj(8,Params2,Traj,SolParam2,'Warm','Compiled',0,0,0);
[T3,E3,N3s,Fo3,W3,F3,R3,L3]=Solve_Over_Traj(8,Params2,Traj,SolParam3,'Warm','Compiled',0,0,0);
[T4,E4,N4s,Fo4,W4,F4,R4,L4]=Solve_Over_Traj(8,Params2,Traj,SolParam4,'Warm','Compiled',0,0,0);

%Verifying when proposition 2 holds
[S_Bound, S_Inf,Prop2_Ass1]=Proposition_2(Traj,SolParam1,Params2,W1,Fo1,1);
[S_Bound, S_Inf,Prop2_Ass2]=Proposition_2(Traj,SolParam2,Params2,W2,Fo2,1);
[S_Bound, S_Inf,Prop2_Ass3]=Proposition_2(Traj,SolParam3,Params2,W3,Fo3,1);
[S_Bound, S_Inf,Prop2_Ass4]=Proposition_2(Traj,SolParam4,Params2,W4,Fo4,1);

figure('name','Fig5(b) Resulting forces. Compressed constraints')
NACT=3
plot([0 10],[Params2.fmin(1) Params2.fmin(1)],':','color',Colorzcheme{5},'LineWidth',4*SCALEFACTOR); hold on
plot(XLine,Fo1(NACT,:)','color',Colorzcheme{3}); hold on
plot(XLine,Fo2(NACT,:)','color',Colorzcheme{2}); hold on
plot(XLine,Fo3(NACT,:)','color',Colorzcheme{4}); hold on
plot(XLine,Fo4(NACT,:)','color',Colorzcheme{1}); hold on
plot([0 10],[Params2.fmax(1) Params2.fmax(1)],':','color',Colorzcheme{5},'LineWidth',4*SCALEFACTOR); hold on
plot(XLine,Fo1([1:NACT-1 NACT+1:end],:)','color',[Colorzcheme{3} 0.25]); hold on
plot(XLine,Fo2([1:NACT-1 NACT+1:end],:)','color',[Colorzcheme{2} 0.25]); hold on
plot(XLine,Fo4([1:NACT-1 NACT+1:end],:)','color',[Colorzcheme{1} 0.25]); hold on
plot(XLine,Fo3([1:NACT-1 NACT+1:end],:)','color',[Colorzcheme{4} 0.25]); hold on
plot([0 10],[Params2.fmax(1) Params2.fmax(1)],':','color',Colorzcheme{5},'LineWidth',4*SCALEFACTOR); hold on
plot([0 10],[Params2.fmin(1) Params2.fmin(1)],':','color',Colorzcheme{5},'LineWidth',4*SCALEFACTOR); hold on
plot(XLine,Fo1(NACT,:)','color',Colorzcheme{3}); hold on
plot(XLine,Fo2(NACT,:)','color',Colorzcheme{2}); hold on
plot(XLine,Fo4(NACT,:)','color',Colorzcheme{1}); hold on
plot(XLine,Fo3(NACT,:)','color',Colorzcheme{4}); hold on
xlabel('Time[s]','FontSize',24,'Interpreter','latex') 
ylabel('{\boldmath $f$}$_s^{*}[N]$','Interpreter','latex')
ylim([4 41])
load TEXT TextFslack TextFslack2N
LEGEND4=[LEGEND3(3) LEGEND3(1:2) LEGEND3(4:5)]
legend(LEGEND4,'NumColumns',2,'Interpreter','latex')
LE.NumColunms(1)
LE.LegendTransparant(0.6)
for i=1:8
Hz{i}=text(TextFslack2N{i}.Position(1),TextFslack2N{i}.Position(2),['(' num2str(i) ')'],'FontSize',36*SCALEFACTOR);
end
ylim([4 41])
LE.AspectRatio([5 2]); LE.FontSize(40,38,36); 


LEGEND4=[LEGEND3(3) LEGEND3(1:2) LEGEND3(4:5)]
legend(LEGEND4,'NumColumns',2,'Interpreter','latex')
LE.NumColunms(1)
LE.LegendTransparant(0.6)

% SAVEALLFIG

% a=asl
figure('name','Fig6(b) Slack magnituded, compressed constraints')
% plot(XLine,max(abs(W1))','color',Colorzcheme{3}); hold on
% plot(XLine,max(abs(W2))','color',Colorzcheme{2}); hold on
% plot(XLine,max(abs(W3))','color',Colorzcheme{4}); hold on
% plot(XLine,max(abs(W4))','color',Colorzcheme{1}); hold on
plot([0 0],[0 0],'color',Colorzcheme{3}); hold on
plot([0 0],[0 0],'color',Colorzcheme{2})
plot([0 0],[0 0],'color',Colorzcheme{4})
plot([0 0],[0 0],'color',Colorzcheme{1})



HU=0.4;

%PATCHING INFEASIBLE AREA
[T1,E1,N1,Fo1,W1,F1,R1,L1]=Solve_Over_Traj(8,Params2,Traj,SolParam1,'Warm','Compiled',0,0,0);
[a,b,c,d,e,Feas1]=Solve_Over_Traj(5,Params2,Traj,SolParam1,'Warm','Compiled',0,0,0);

K=diff(Feas1);
H=find(abs(K)>0.5)+1;
H=H*10/length(Traj.Eta);%EVAL NUMBER->TIME
H1=H(1); H2=H(2);
patch([H1 H2 H2 H1], [0 0, HU HU], [0.5 0.5 0.5],'edgecolor','r','FaceAlpha',0.4,'EdgeAlpha',0.1);
patch([0 0 0 0], [0 0, 0 0], [0.5 0.5 0.5],'edgecolor','k','FaceAlpha',0,'EdgeAlpha',1);


%Dashed where theorem does not hold
%W1a
W1A=W1;W1B=W1;
W1A(:,Prop2_Ass1<0.5)=nan;
W1B(:,Prop2_Ass1>0.5)=nan;
plot(XLine,max(abs(W1A)),'color',Colorzcheme{3}); hold on
plot(XLine,max(abs(W1B)),':','color',Colorzcheme{3});
%W1b
W2A=W2;W2B=W2;
W2A(:,Prop2_Ass2<0.5)=nan;
W2B(:,Prop2_Ass2>0.5)=nan;
plot(XLine,max(abs(W2A)),'color',Colorzcheme{2}); hold on
plot(XLine,max(abs(W2B)),':','color',Colorzcheme{2});
%W2
W1A=W3;W1B=W3;
W1A(:,Prop2_Ass3<0.5)=nan;
W1B(:,Prop2_Ass3>0.5)=nan;
plot(XLine,max(abs(W1A)),'color',Colorzcheme{4}); hold on
plot(XLine,max(abs(W1B)),':','color',Colorzcheme{4});
%W2b
W1A=W4;W1B=W4;
W1A(:,Prop2_Ass4<0.5)=nan;
W1B(:,Prop2_Ass4>0.5)=nan;
plot(XLine,max(abs(W1A)),'color',Colorzcheme{1}); hold on
plot(XLine,max(abs(W1B)),':','color',Colorzcheme{1});
plot(XLine,max(abs(W2A)),'color',[Colorzcheme{2} 0.6]); hold on





ylabel(' $|${\boldmath $s$}$^*|_\infty$ ','Interpreter','latex')   
xlabel('Time[s]','FontSize',24,'Interpreter','latex') 

grid on

% LE.FontSize(35,31,31)
% LE.AspectRatio([6 1.85])
ylim([0 0.3])
    
legend({Legend{1:4},'Equation (2) infeasible','Equation (2) feasible'},'Interpreter','latex')
LE.LegendTransparant(0.6)
LE.AspectRatio([5 1.6]); LE.FontSize(40,40,36); 

if AdditionalFigures

figure('name','NF2n')
plot((abs(N1(2:end)))','color',Colorzcheme{3}); hold on
plot((abs(N2(2:end)))','color',Colorzcheme{2}); hold on
plot((abs(N3(2:end)))','color',Colorzcheme{4}); hold on
plot((abs(N4(2:end)))','color',Colorzcheme{1}); hold on
ylabel('Number of iterations','Interpreter','latex')   
xlabel('Time[s]','FontSize',24,'Interpreter','latex') 
legend(Legend00,'NumColumns',4)

LE.FontSize(35,29,31)
LE.AspectRatio([6 1.85])


figure('name','NF')
plot((abs(N1(2:end)))','color',Colorzcheme{3}); hold on
plot((abs(N2(2:end)))','color',Colorzcheme{2}); hold on
plot((abs(N3(2:end)))','color',Colorzcheme{4}); hold on
plot((abs(N4(2:end)))','color',Colorzcheme{1}); hold on
ylabel('Number of iterations','Interpreter','latex')   
xlabel('Time[s]','FontSize',24,'Interpreter','latex') 
legend(Legend00,'NumColumns',4)
LE.FontSize(35,29,31)
LE.AspectRatio([6 1.85])


end