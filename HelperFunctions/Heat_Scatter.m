% Author: Einar Ueland1
% email: einar.s.ueland@gmail.com
% September 2019;
% If used, please cite relevant sources as provided in the readme file. 

function [MAXVAL]=Heat_Scatter(X, Y,Xrange,Yrange,ScatterSize)
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
scatter(XPos,YPos,ScatterSize,VAL,'.');
colormap(flipud(copper));
colorbar
MAXVAL=max(VAL);
end