% Author: Einar Ueland. Coauthors Roger Skjetne and Thomas Sauder. 
% email: einar.s.ueland@gmail.com
% January 2020;
% Please cite relevant sources as provided in the readme file. 



xWarm=[NITERCOLLECTWarmDelta'; N_S_WAdd'];
yWarm=[ 1./EVALCOLLECTWarmDelta';1./EvalTimeWCS'];
% zWarm=[LITERCOLLECT' ;L_Iter_Slack'];




% xWarm=[ N_S_WAdd'];
% yWarm=[1./EvalTimeWCS'];


% Heat_Scatter(N_Iter_Slack', L_Iter_Slack',0:max(x),0:max(z)); hold on
% Heat_Scatter(NITERCOLLECT', LITERCOLLECT',0:max(x),0:max(z)); hold on

dt=1e-3;
xWarmMax=5;
xWarmMaxS=10;
xWarmMaxP=5




figure('name','Fig12. Scatterplot Evaltime vs Niter')
plot(1:xWarmMax,EVAL_NORMALW(1:xWarmMax),'color',Colorzcheme{1},'LineWidth',1.5); hold on
plot(1:xWarmMaxP,EVAL_P5W(1:xWarmMaxP),'color',Colorzcheme{3},'LineWidth',1.5); hold on
plot(1:xWarmMax,EVAL_SlackW(1:xWarmMax),'color',Colorzcheme{2},'LineWidth',1.5); hold on
plot(1:xWarmMaxS,EVALWC(1:xWarmMaxS),'color',Colorzcheme{4},'LineWidth',1.5); hold on

Heat_Scatter3(xWarm, yWarm,0:max(xWarm),0:dt:max(yWarm)); hold on
plot(1:xWarmMax,EVAL_NORMALW(1:xWarmMax),'color',Colorzcheme{1},'LineWidth',1.5); hold on
plot(1:xWarmMaxP,EVAL_P5W(1:xWarmMaxP),'color',Colorzcheme{3},'LineWidth',1.5); hold on
plot(1:xWarmMax,EVAL_SlackW(1:xWarmMax),'color',Colorzcheme{2},'LineWidth',1.5); hold on
plot(1:xWarmMaxS,EVALWC(1:xWarmMaxS),'color',Colorzcheme{4},'LineWidth',1.5); hold on

    % ,':',
V=legend('Standard, p=2','Standard, p=5','Slack, Case 1','Slack, Case 2');title(V,'Mean evaluation time')
V.NumColumns=2;
V.BoxFace.ColorData(4)=100;  % 4x1 uint8
set(V.BoxFace, 'ColorType','truecoloralpha', 'ColorData',uint8(255*[1;1;1;.2]));  % [.5,.5,.5] is light gray; 0.8 means 20% transparent

H3=colorbar;
H3.TickLabels{1}=1;
for i=2:length(H3.TickLabels)
 H3.TickLabels{i}=['10^' H3.TickLabels{i}];
end
% xlim([0.5 40])
% xlim([0.5 100])
ylabel(H3,'Instances in vicinity $(\pm 1 \mu  s)$','interpreter','latex');
ylabel('Evaluation time [ms]','interpreter','latex','FontSize',18)
xlabel('Number of iterations','FontSize',18)
xlim([0.5 max(xWarm)])
ylim([0 0.40])
xlim([0.5 17])
V.FontSize=12
ylim([0 0.55])
V.FontSize=10
FontSize=20;LegendSize=20;TickSize=20;



if AdditionalFigures

if ColdStart
x=[NITERCOLLECT'; N_Iter_Slack'];
y=[ 1./EVALCOLLECT';1./Eval_Slack'];
z=[LITERCOLLECT' ;L_Iter_Slack'];



% Heat_Scatter(N_Iter_Slack', L_Iter_Slack',0:max(x),0:max(z)); hold on
% Heat_Scatter(NITERCOLLECT', LITERCOLLECT',0:max(x),0:max(z)); hold on

dt=1e-3;

figure('name','Evaluation time vs Iteraitons (Including cold-start)')
plot(1:length(EVAL_NORMAL),EVAL_NORMAL,'color',Colorzcheme{1},'LineWidth',1.5); hold on
plot(1:length(EVAL_P5),EVAL_P5,'color',Colorzcheme{3},'LineWidth',1.5); hold on
plot(1:length(EVAL_Slack),EVAL_Slack,'color',Colorzcheme{2},'LineWidth',1.5); hold on
plot(1:length(EVALKCS),EVALKCS,'color',Colorzcheme{4},'LineWidth',1.5); hold on
Heat_Scatter3(x, y,0:max(x),0:dt:max(y)); hold on
plot(1:length(EVAL_NORMAL),EVAL_NORMAL,'color',Colorzcheme{1},'LineWidth',1.5); hold on
plot(1:length(EVAL_P5),EVAL_P5,'color',Colorzcheme{3},'LineWidth',1.5); hold on
plot(1:length(EVAL_Slack),EVAL_Slack,'color',Colorzcheme{2},'LineWidth',1.5); hold on
plot(1:length(EVALKCS),EVALKCS,'color',Colorzcheme{4},'LineWidth',1.5); hold on
% ,':',
V=legend('Standard, p=2','Standard, p=5','Slack, Case 1','Slack, Case 2');title(V,'Mean evaluation time')
 
V.BoxFace.ColorData(4)=100;  % 4x1 uint8
set(V.BoxFace, 'ColorType','truecoloralpha', 'ColorData',uint8(255*[1;1;1;.2]));  % [.5,.5,.5] is light gray; 0.8 means 20% transparent

xlim([0 max(NITERCOLLECT)+0.1])

H3=colorbar;
H3.TickLabels{1}=1;
for i=2:length(H3.TickLabels)
 H3.TickLabels{i}=['10^' H3.TickLabels{i}];
end
xlim([0.5 40])
xlim([0.5 100])
ylabel(H3,'Instances in vicinity $(\pm 1 \mu  s)$','interpreter','latex');
H3.FontSize=14
ylabel('Evaluation time [ms]','interpreter','latex','FontSize',18)
xlabel('Number of iterations','FontSize',18)
FontSize=40*0.4;LegendSize=32*0.3;TickSize=36*0.4;

LE=LEGENDEINAR
FontSize=40*0.4;LegendSize=32*0.3;TickSize=36*0.4;

LE.FontSize(FontSize,12,TickSize)

LE.FontSize(FontSize,15,TickSize)
figure('name','Line steps time vs Iteraitons (Including cold-start)')
Heat_Scatter3(x, z,0:max(x),0:max(z)); hold on
H3=colorbar;
H3.TickLabels{1}=1;
for i=2:length(H3.TickLabels)
 H3.TickLabels{i}=['10^' H3.TickLabels{i}];
end
ylabel(H3,'Instances','interpreter','latex');
H3.FontSize=14
ylabel('Number of linesteps','interpreter','latex','FontSize',18)
xlabel('Number of iterations','FontSize',18)
xlim([0.5 90])

%%
ylabel(H3,'Instances','interpreter','latex','FontSize',18);


    xCold=[NITERCOLLECTColdDelta'];
    yCold=[ 1./EVALCOLLECTColdDelta'];
%     Heat_Scatter3(xCold, yCold,0:max(xCold),0:dt:max(yCold)); hold 



    xColdMax=20;
    xColdMaxS=20;
    xColdMaxP=20;

figure('name','Evaluation time vs Iteraitons (Only cold-start),')
    plot(1:xColdMax,EVAL_NORMAL(1:xColdMax),'color',Colorzcheme{1},'LineWidth',1.5); hold on
    plot(1:xColdMaxP,EVAL_P5(1:xColdMaxP),'color',Colorzcheme{3},'LineWidth',1.5); hold on
    plot(1:xColdMaxS,EVALKCS(1:xColdMaxS),'color',Colorzcheme{4},'LineWidth',1.5); hold on
    Heat_Scatter3(xCold, yCold,0:max(xCold),0:dt:max(yCold)); hold on
    plot(1:xColdMax,EVAL_NORMAL(1:xColdMax),'color',Colorzcheme{1},'LineWidth',1.5); hold on
    plot(1:xColdMaxP,EVAL_P5(1:xColdMaxP),'color',Colorzcheme{3},'LineWidth',1.5); hold on
    plot(1:xColdMaxS,EVALKCS(1:xColdMaxS),'color',Colorzcheme{4},'LineWidth',1.5); hold on

    V=legend('Standard, p=2','Standard, p=5','Slack, Case 1');title(V,'Mean evaluation time')

    V.BoxFace.ColorData(4)=100;  % 4x1 uint8
    set(V.BoxFace, 'ColorType','truecoloralpha', 'ColorData',uint8(255*[1;1;1;.2]));  % [.5,.5,.5] is light gray; 0.8 means 20% transparent

    xlim([0 max(NITERCOLLECT)+0.1])
    H3=colorbar;
    H3.TickLabels{1}=1;
    for i=2:length(H3.TickLabels)
     H3.TickLabels{i}=['10^' H3.TickLabels{i}];
    end
    % xlim([0.5 40])
    % xlim([0.5 100])
    ylabel(H3,'Instances in vicinity $(\pm 1 \mu  s)$','interpreter','latex');
    ylabel('Evaluation time [ms]','interpreter','latex','FontSize',18)
    xlabel('Number of iterations','FontSize',18)
    xlim([0.5 max(xWarm)])
    ylim([0 1])
    xlim([0.5 35])
    V.FontSize=12

    FontSize=40*0.4;LegendSize=32*0.3;TickSize=36*0.4;

    LE.FontSize(FontSize,13,TickSize)

end
end