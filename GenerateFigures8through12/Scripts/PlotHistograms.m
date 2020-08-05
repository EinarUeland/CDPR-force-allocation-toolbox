% Author: Einar Ueland. Coauthors Roger Skjetne and Thomas Sauder. 
% email: einar.s.ueland@gmail.com
% January 2020;
% Please cite relevant sources as provided in the readme file. 


F_PinvNAdd=cell2mat(cellfun(@(x) (sum(((x'>Params.fmin(1)).*(x'<Params.fmax(1)))'==0)==0),F_PinvN,'un',0));
F_PinvNAdd8=cell2mat(cellfun(@(x) (sum(((x'>Params.fmin(1)).*(x'<Params.fmax(1)))'==0)==0),F8_PinvN,'un',0));
F_PinvNAdd=[F_PinvNAdd F_PinvNAdd8];
OnOroffPinv=cell2mat(cellfun(@(x) (sum((sum(((x'>Params.fmin(1)).*(x'<Params.fmax(1)))'==0)==0)==0)==0),F_PinvN,'un',0));
PSTPINV=sum(F_PinvNAdd)/length(F_PinvNAdd);


     TICZ=[1 1e2 1e4 1e6];

    
    
 figure('name','Fig10(a) Standard P=2 Case 1')%figure('name','Warmstart')
K2=Hist_2(NIterWCMrg(Feas3WMrg==1),'',Colorzcheme{3}); hold on
Hist_2(NIterWCMrg(Feas2WMrg==1),'Standard, Warm start,p=2',Colorzcheme{2}); hold on
xlim([0 K2])
H=legend('$\mathrm{min}(h_i)>0.01$','$\mathrm{min}(h_i)>0.1$','Feasible with Pinv'); set(H,'interpreter','latex')
LE.AspectRatio([2 1.7])
LE.FontSize(42,38,32.08)
yticks(TICZ)


figure('name','Fig10(b),Standard P=5 Case 1')%figure('name','P-Warm')
K=Hist_2(NIter_P_WMrg(Feas3WMrg==1),'',Colorzcheme{3}); hold on
Hist_2(NIter_P_WMrg(Feas2WMrg==1),'Standard, Warm start,p=5',Colorzcheme{2});
xlim([0 K])
H=legend('$\mathrm{min}(h_i)>0.01$','$\mathrm{min}(h_i)>0.1$'); set(H,'interpreter','latex')
LE.AspectRatio([2 1.7])
LE.FontSize(42,38,32.08)
yticks(TICZ)


figure('name','Fig10(c),Slack, P=5 Case 1')%figure('name','SlackWarm')
K=Hist_2(NIter_S_W2Mrg,'Slack Warm start, p=2',Colorzcheme{3}); hold on
xlim([0 K])
LE.AspectRatio([2 1.7])
LE.FontSize(42,38,32.08)
yticks(TICZ)




figure('name','Fig10(d), resulting slack, case 1') %WERR plot
dH=0.00005;
H=max(abs(WERR2Mrg)); [a b]=hist(H,0:0.00005:max(max(abs(WERR2)))); loglog(b,a/(dH*sum(a)),'LineWidth',2); hold on; xlim([0 max(max(abs(WERR2)))])
xlabel('$|${\boldmath $w$}$_{\mathrm{err}}|_\infty$','Interpreter','latex')
ylabel('Normalized frequency','Interpreter','latex')
max(max(abs(WERR2)))

LE.AspectRatio([2 1.7])
xticks([1e-4 1e-3 1e-2])
yticks([1e-2 1 1e2 1e4])
% 
LE.FontSize(42,38,32.08)


figure('name','Fig 9. Number of Cables (trajectory instances)')
Hist_2(NLines8,'',Colorzcheme{6}); hold on
Hist_2(NLinesRand,'',Colorzcheme{4})

ylabel(['Number of' char(10) 'trajectories'])
xlabel('Number of cables')
xlim([7 25])
LE.AspectRatio([5 1.4]);	
 ax=gca
 ax.YTick=[1 1e2 1e4];
  ax.XTick=[8:24];
LE.FontSize(40,41,40)
H=legend('Fixed configuration','Randomized configuration'); 



    
timez=linspace(0,1,1000)
    figure('name','Fig8(a) Sample pose trajectory (Case 2)')
for i=1:3
    plot(timez,Eta(i,:),'LineWidth',2,'color',Colorzcheme{i}); hold on
end
for i=4:6
    plot(timez,Eta(i,:),':','LineWidth',2,'color',Colorzcheme{i}); hold on
end
    [Hv]=legend({'x[m]  \quad ','y[m]   ','z[m]   ','$\phi$[rad] ','$\theta$[rad] ','$\psi$[rad] '},'NumColumns',2);

    xlabel('Time[s]','FontSize',24,'Interpreter','latex'); hold on
    ylabel('Magnitude','FontSize',24,'Interpreter','latex')

    figure('name','Fig8(b) Sample wrench trajectory (Case 2)')
for i=1:3
    plot(timez,Traj.WTargetMat(i,:),'LineWidth',2,'color',Colorzcheme{i}); hold on
end
for i=4:6
    plot(timez,Traj.WTargetMat(i,:)*10,':','LineWidth',2,'color',Colorzcheme{i}); hold on
end


    figure('name','Fig8(a) Sample pose trajectory (Case 1)')
for i=1:3
    plot(timez,EtaRand(i,:),'LineWidth',2,'color',Colorzcheme{i}); hold on
end
for i=4:6
    plot(timez,EtaRand(i,:),':','LineWidth',2,'color',Colorzcheme{i}); hold on
end
    [Hv]=legend({'x[m]  \quad ','y[m]   ','z[m]   ','$\phi$[rad] ','$\theta$[rad] ','$\psi$[rad] '},'NumColumns',2);

    xlabel('Time[s]','FontSize',24,'Interpreter','latex'); hold on
    ylabel('Magnitude','FontSize',24,'Interpreter','latex')

    figure('name','Fig8(b) Sample wrench trajectory (Case 1)')
for i=1:3
    plot(timez,WTargetMatRand(i,:),'LineWidth',2,'color',Colorzcheme{i}); hold on
end
for i=4:6
    plot(timez,WTargetMatRand(i,:)*10,':','LineWidth',2,'color',Colorzcheme{i}); hold on
end






     legend({'$F_x \enskip $','$F_y \enskip $','$F_z \enskip $','$10 M_{x}$','$10M_y$','10$M_z$'},'Interpreter','latex','NumColumns',2)
     xlabel('Time[s]','Interpreter','latex')
     ylabel('Force[N]/Moment[Nm]','Interpreter','latex')'


     
         figure('name','Fig11(c) Sample actuator (Fixed mode)')
        DrawConfig(EtaFixed,1000,Actuator_BasesFixed,End_effectorsFixed,Colorzcheme,1)
 
figure('name','Fig8(c) Sample actuator (Randomized mode)')
         DrawConfig(EtaRand,1000,Actuator_BasesRand,End_effectorsRand,Colorzcheme,1)








if AdditionalFigures



figure('name','Scatterplot case 1 warm and cold start')
dt=1e-3;
plot(1:AvEnd,EVAL_NORMAL(1:AvEnd),'r'); hold on
plot(1:AvEnd,EVAL_P5(1:AvEnd),'b')
plot(1:AvEnd,EVAL_Slack(1:AvEnd),'m'); hold on
Heat_Scatter(NITERCOLLECT', 1./EVALCOLLECT',0:max(NITERCOLLECT),0:dt:max( 1./EVALCOLLECT')); hold on

plot(1:AvEnd,EVAL_NORMAL(1:AvEnd),'r'); hold on
plot(1:AvEnd,EVAL_P5(1:AvEnd),'b')
plot(1:AvEnd,EVAL_Slack(1:AvEnd),'m'); hold on

V=legend('Standard formulation, p=2','Standard formulation, p=5','Slack formulation');title(V,'Mean evaluation time')
V.BoxFace.ColorData(4)=100;  % 4x1 uint8
set(V.BoxFace, 'ColorType','truecoloralpha', 'ColorData',uint8(255*[1;1;1;.2]));  % [.5,.5,.5] is light gray; 0.8 means 20% transparent

xlim([0 max(NITERCOLLECT)+0.1])
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
xlabel('Iterations','FontSize',18)
xlim([0 30])




%LINEITERATIONS
figure('name','LineIter')
Heat_Scatter(NITERCOLLECT', LITERCOLLECT',0:max(NITERCOLLECT),0:max([max(LITERCOLLECT) 1]))
H3=colorbar;
H3.TickLabels{1}=1;


for i=2:length(H3.TickLabels)
 H3.TickLabels{i}=['10^' H3.TickLabels{i}];
end
ylabel(H3,'Instances','interpreter','latex');
H3.FontSize=14
ylabel('Number of linesteps','interpreter','latex','FontSize',18)
xlabel('Iterations','FontSize',18)
xlim([0 max(NITERCOLLECT)+0.1])
ylim([-1 max(LITERCOLLECT(NITERCOLLECT<25))+0.1])
MFILENAME='All_linesRND5'
xlim([0 25])
% ylim([0 100])



%Checking which were not feasible with different values of delta. 


%COLDSTART From 1 now.
% NIterCC1=cell2mat(N_CC);
% NIterCCP1=cell2mat(N_P_C);
% N_P_CS1=cell2mat(N_S_C2);

figure('name','Cold Slack, P=2 Case 1')%figure('name','SlackWarm')
K=Hist_2(NIter_S_C2Mrg,'Slack Cold start, p=2',Colorzcheme{3}); hold on
xlim([0 K])
LE.AspectRatio([2 1.7])
LE.FontSize(42,38,32.08)
yticks(TICZ)



figure('name','NormalCold')%figure('name','COldStart')
 K2=Hist_2(NIterCCMrg(Feas3Mrg==1),'',Colorzcheme{3}); hold on
Hist_2(NIterCCMrg(F_PinvNAdd==1),'Standard, Cold start,p=2',Colorzcheme{6});
H=legend('$\mathrm{min}(h_i)>0.01$','Feasible with pseudoinverse'); set(H,'interpreter','latex')
xlim([0 K2])
LE.AspectRatio([2 1.7])
LE.FontSize(42,33,32.08)
ylim([0 1e8])
yticks(TICZ)

figure('name','PnormCold') %figure('name','P-Cold')
K=Hist_2(NIter_P_CMrg(Feas4Mrg==1),'Standard, Cold start,p=5 ($\alpha=25$)',Colorzcheme{3}); hold on
% Hist_2(NIter_P_C(Feas4==1),'Standard, Cold start,p=5',Colorzcheme{2}); hold on
xlim([0 K])

H=legend('$\mathrm{min}(h_i)>0.1$'); set(H,'interpreter','latex')

LE.AspectRatio([2 1.7])
LE.FontSize(42,38,32.08)
yticks(TICZ)





% WERR2=cell2mat(W_S_C);
% LE.AspectRatio([2 1.7])
% 



ylabel('Normalized frequency','Interpreter','latex')
max(sum(abs(WERR2)))
LE.FontSize(40,35,24.08)
% LE=LEGENDEINAR


end