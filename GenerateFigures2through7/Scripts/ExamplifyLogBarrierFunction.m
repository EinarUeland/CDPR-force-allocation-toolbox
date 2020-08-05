% Author: Einar Ueland. Coauthors Roger Skjetne and Thomas Sauder. 
% email: einar.s.ueland@gmail.com
% January 2020;
% Please cite relevant sources as provided in the readme file. 



 clearvars -except AdditionalFigures

LE=LEGENDEINAR;

Colorzcheme={[0 0 0],[0.8500, 0.3250, 0.0980],[0, 0.4470, 0.7410],[0.5 0.5 0.5],[0.4660, 0.6740, 0.1880],[0.9290, 0.6940, 0.1250],[0.4940, 0.1840, 0.5560]}

fmax=40; fmin=5; f0=15;
% close all
x=linspace(fmin(1)+1e-9,fmax(1)-1e-9,1e5)';
c11=1;
c21=1;

c_1=1;
c_2=1;
COST1=-(c11*log(-(x-fmax(1))))-(c21*log(-(-x+fmin(1))));
K1=-min(COST1);
COST1=COST1+K1;

c12=0.1;
c22=0.1;

COST2=-(c22*log(-(x-fmax(1))))-(c22*log(-(-x+fmin(1))));
K2=-min(COST2);
COST2=COST2+K2;

c13=0.02;
c23=0.02;

COST3=-(c13*log(-(x-fmax(1))))-(c23*log(-(-x+fmin(1))));
K3=-min(COST3);
COST3=COST3+K3;

alpha=(fmax-fmin)/2;
COSTf=(f0-x).^2/alpha^2;

figure('name','Fig3- Logarithmic Barriers')
plot(x,COST1,'color',Colorzcheme{6},'LineWidth',2); hold on
plot(x,COST2,'color',Colorzcheme{1},'LineWidth',2); hold on
plot(x,COST3,'color',Colorzcheme{3},'LineWidth',2); hold on
plot(x,COSTf,':','color',Colorzcheme{2},'LineWidth',2)
plot([fmin fmin],[-30 100],':','color',Colorzcheme{5},'LineWidth',2);hold on
plot([fmax fmax],[-30 100],':','color',Colorzcheme{5},'LineWidth',2)
xlabel('$f_i$','interpreter','latex','FontSize',16)
ylabel('y','interpreter','latex','FontSize',16)
xlim([fmin(1)-2 fmax(1)+2]);
ylim([-1 7])
h=text(7.5,1.80,'$y(f_i)=-c_1 \log(f_i-f_{min,i})-c_2 \log(f_{max,i}-f_i)+k$','interpreter','latex','FontSize',36,'BackgroundColor',[1 1 1]);
text(fmin+0.1,-.1,'$\leftarrow f_{min,i}=5 $','interpreter','latex','FontSize',36)
text(fmax-9.75,-.1,'$f_{max,i}=40 \rightarrow$','interpreter','latex','FontSize',36)
plot([fmin fmin],[-30 100],':','color',Colorzcheme{5},'LineWidth',2);hold on
plot([fmax fmax],[-30 100],':','color',Colorzcheme{5},'LineWidth',2)

 h1=legend({['$c_1 = $' num2str(c11) ',           '   ' $\enskip \enskip \mkern5mu c_2 = $' num2str(c21) ,',   $\enskip \enskip \mkern5mu k=$' ' ' num2str(K1,3)]  ['$c_1 = $' num2str(c12) ',   $\enskip c_2 = $' num2str(c22),',   $\enskip k=$' ' ' num2str(K2,2)]  ['$c_1 = $' num2str(c13) ',   $c_2 =$' num2str(c23) ,',   $k=$' ' ' num2str(K3,2)],'$(f_i-f_0)^2/\alpha^2, \enskip \alpha=17.5$'});
 set(h1,'Interpreter','latex')
set(h1.BoxFace, 'ColorType','truecoloralpha', 'ColorData',uint8(255*[1;1;1;.8]));  % [.5,.5,.5] is light gray; 0.8 means 20% transparent
a=gca; set(a,'XTick',[5 15 20 25 30 40]) 
 ylim([-0.3 2])
 LE.AspectRatio([4 1.35]);LE.FontSize(46,36,36);LE.MINBORDER;
LEGENDEINAR
LE=LEGENDEINAR
LE.FontSize(30,30,30)
% LE.
% LE.FontSize(20,16,16)
% SAVEALLFIG
