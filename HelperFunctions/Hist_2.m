% Author: Einar Ueland1
% email: einar.s.ueland@gmail.com
% September 2019;
% If used, please cite relevant sources as provided in the readme file. 


function [K YMAX] = Hist_2(Value,TITLE,Color,FaceAlpha)
if nargin<3
    [n, xout] = hist(Value,0:max(Value));
    bar(xout, n, 'barwidth', 1, 'basevalue', 0.1);
    set(gca,'YScale','log')
    xlabel('Iterations','Interpreter','latex')
    ylabel('Instances','Interpreter','latex')
    ylim([10^-1 5*max(n)])
    YMAX=5*max(n);
    xlim([0 max(Value)+1])
    K=max(Value)+1;
else 
    [n, xout] = hist(Value,0:max(Value));
    bar(xout, n, 'barwidth', 1, 'basevalue', 0.1,'FaceColor',Color);
    set(gca,'YScale','log')
    xlabel('Iterations','Interpreter','latex')
    ylabel('Instances','Interpreter','latex')
    ylim([10^-1 5*max(n)])
    YMAX=5*max(n);
    xlim([0 max(Value)+1])
    K=max(Value)+1;
end
if nargin>1
if length(TITLE)>0
    title(TITLE,'Interpreter','latex','FontSize',16); hold on;
end
end
end