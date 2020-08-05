% Author: Einar Ueland
% email: einar.s.ueland@gmail.com
% September 2019;
% If used, please cite relevant sources as provided in the readme file. 

function []=Print_Geometry3D(PACT,P_LC,Eta,PrintMode)
Colorzcheme={[0 0 0],[0.8500, 0.3250, 0.0980],[0, 0.4470, 0.7410],[0.5 0.5 0.5],[0.4660, 0.6740, 0.1880],[0.9290, 0.6940, 0.1250],[0.4940, 0.1840, 0.5560]};
if PrintMode==1
P_LC =[P_LC [ -0.0525 0.0525  0 ;   -0.0760  -0.0760 0;   0 0 0]];
end %JUST FOR THE VIZUALITY, to finalize the hull. 

if PrintMode~=3 %if printmode=3, we do not print trajectory or line-number.
    if size(Eta,1)>3
        plot3(Eta(1,:),Eta(2,:),Eta(3,:),':','LineWidth',0.5)
    elseif size(Eta,1)>1
        plot(Eta(1,:),Eta(2,:),':','LineWidth',0.5)
    end
end
if size(Eta,1)==6 %FOR [X,Y,Z,\PHI,\THETA,\PSI]
    PHI2=Eta(4,1);
    THETA2=Eta(5,1);
    PSI2=Eta(6,1);
    ROTZ= [ cos(PSI2) -sin(PSI2) 0; sin(PSI2) cos(PSI2) 0;0 0 1];
    ROTY= [ cos(THETA2) 0 sin(THETA2); 0 1 0;-sin(THETA2) 0 cos(THETA2)];
    ROTX= [1 0 0;0  cos(PHI2) -sin(PHI2); 0 sin(PHI2) cos(PHI2)];
    ROT= ROTZ*ROTY*ROTX;
    P_LC=ROT*P_LC;
    P_LC(1:3,:)=P_LC(1:3,:)+ [Eta(1:3,1)];
elseif size(Eta,1)==3 %FOR [X,Y,\PSI]
    PSI2=Eta(3,1);
    ROTZ= [ cos(PSI2) -sin(PSI2) 0; sin(PSI2) cos(PSI2) 0;0 0 1];
    P_LC=ROTZ*P_LC;
    P_LC(1:2,:)=P_LC(1:2,:)+ [Eta(1:2,1)];
end
XX=P_LC(1,:);
YY=P_LC(2,:);
ZZ=P_LC(3,:);


%A SOMEWHAT MESSY WAY OF PLOTING THE GEOMETRY (Can take 2D and 3D
%geometries)
try
    K = convhull(XX,YY,ZZ);
    EmhpLine=1;
    % save AE
    H=trisurf(K,XX,YY,ZZ,'FaceColor',Colorzcheme{5},'EdgeAlpha',0.1); hold on;
catch
    K = convhull(XX,YY);
    % H=patch('XData',P_LCm(1,K),'YData',P_LCm(2,K),'ZData',P_LCm(3,K),'FaceColor',Colorzcheme{5});
    % save AE
    if PrintMode==2
        H=patch('XData',XX(K),'YData',YY(K),'ZData',ZZ(K),'FaceColor',Colorzcheme{5},'EdgeColor','r','LineWidth',1); hold on
    else
        H=patch('XData',XX(K),'YData',YY(K),'ZData',ZZ(K),'FaceColor',Colorzcheme{5}); hold on
    end
end

%PLOTTING CABLES
for i=1:length(PACT)
    LineP{i}=  plot3( [PACT(1,i) P_LC(1,i)], [PACT(2,i) P_LC(2,i)], [PACT(3,i) P_LC(3,i)],'color','k')  ; 
    hold on
end

if size(Eta,1)==6 %3D
for i=1:length(PACT)
    if PrintMode==2
        text(0.5*(PACT(1,i)+P_LC(1,i)),0.5*(PACT(2,i)+P_LC(2,i)),0.5*(PACT(3,i)+P_LC(3,i))+0.0734,['(' num2str(i) ')'],'FontSize',12)
    end
end
else
for i=1:length(PACT)
    if PrintMode==2
       text(0.5*(PACT(1,i)+P_LC(1,i))+0.25,0.5*(PACT(2,i)+P_LC(2,i)),['(' num2str(i) ')'],'FontSize',12)
    end
end  
end
legend('Trajectory','Platform','Cables (numbered)')
if PrintMode~=3
    legend('Trajectory','Platform','Cables')
else
    legend('Platform','Cables')
end

axis equal
xlabel('x','FontSize',24,'Interpreter','latex')
ylabel('y','FontSize',24,'Interpreter','latex')
zlabel('z','FontSize',24,'Interpreter','latex')

