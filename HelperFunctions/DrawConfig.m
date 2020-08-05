% Author: Einar Ueland
% email: einar.s.ueland@gmail.com
% September 2019;
% If used, please cite relevant sources as provided in the readme file. 

function []= DrawConfig(Eta,L,PA,PLC,Colorzcheme,PlotFlag)
Print_Geometry_3D(PA,PLC,Eta(:,1),1); hold on
axis equal
view(12,40)
MFILENAME='RNDME';
legend off
r = 0.02;
t2=linspace(0,2*pi);
xr = r*cos(t2);
yr = r*sin(t2);
ONE=ones(1,100);
c=ones(1,100);
vert = [-1 -1 -1;1 -1 -1;1 1 -1;-1 1 -1;-1 -1 1;1 -1 1;1 1 1;-1 1 1];
vert(:,1)=vert(:,1)*0.415;
vert(:,2)=vert(:,2)*0.314;
vert(:,3)=vert(:,3)*0.500;
fac = [1 2 6 5;2 3 7 6;3 4 8 7;4 1 5 8;1 2 3 4;5 6 7 8];
fC=[1 0.2 0.2;1 0.5 0.5;1 0.2 0.2;1 0.2 0.2;1 0.4 0.4;1 0.2 0.22];
Patch=1;
if Patch==1
for i=1:size(fC,1)
patch('Vertices',vert,'Faces',fac(i,:),'Facecolor',fC(i,:),'FaceAlpha',0.1); hold on
end
end


for i=1:size(PA,2)
    if PA(1,i)==0.4150||PA(1,i)==-0.4150
        plot3(ONE*PA(1,i),xr+PA(2,i),yr+PA(3,i),'color',[0.5 0.5 0.5],'LineWidth',1); hold on
    elseif PA(2,i)==-0.3150||PA(2,i)==0.3150
        plot3(yr+PA(1,i),ONE*PA(2,i),xr+PA(3,i),'color',[0.5 0.5 0.5],'LineWidth',1); hold on

    elseif PA(3,i)==0.5||PA(3,i)==-0.5
        plot3(xr+PA(1,i),yr+PA(2,i),ONE*PA(3,i),'color',[0.5 0.5 0.5],'LineWidth',1); hold on
    else 
    error('Invalid setting. This version is not adapted to configurations other than the one studied in the paper. Check the github')
    end
end
legend off
end