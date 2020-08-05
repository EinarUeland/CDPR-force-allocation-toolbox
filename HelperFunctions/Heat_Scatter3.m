% Author: Einar Ueland1
% email: einar.s.ueland@gmail.com
% September 2019;
% If used, please cite relevant sources as provided in the readme file. 

%In this version, the scatterpoints with higher is kept on the top. 

function [MAXVAL]=Heat_Scatter3(X, Y,Xrange,Yrange,ScatterSize)
if nargin<5
    ScatterSize=74;
end
    [values, centers] = hist3([X Y],'Ctrs',{Xrange Yrange});
    RowCenter=centers{1};
    ColCenter=centers{2};
    [row col]=find(values>0);
    XPos=RowCenter(row);
    YPos=ColCenter(col);
    VAL=log10(values(values>0));
for P=-0.1:0.2:7
    SmallIters=find(VAL>=P&VAL<P+0.2);
    scatter(XPos(SmallIters),YPos(SmallIters),ScatterSize,VAL(SmallIters),'.'); hold on
end
    colormap(flipud(copper));
    colorbar;
    MAXVAL=max(VAL);
end