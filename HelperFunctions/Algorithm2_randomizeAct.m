% Author: Einar Ueland
% email: einar.s.ueland@gmail.com
% September 2019;
% Randomize configurations according to Algorithm 2 (Case 1)

close all
if ~exist('GridSize')
GridSize=1e3; %DEFAULT
end
% clear
Randomize_ActuatorPlacements


% %#INPUT
% tz=linspace(0,1*1*pi,GridSize);
% X=sin(tz)*0.1;
% Y=cos(tz)*0.1;
% Z=sin(tz).*cos(2*tz)*0.1*3.4;
% PSI=Z*0.1;
% Eta=[X;Y;Z;X*0;X*0;-Z*0.5];
% 
%  WTargetMat=[-X+Y; Y;-Y;X*0;X*0;X*0]; %TARGET FORCES
% 
% 
% %25:
% 
% J=Get_JMatrix_Series(Actuator_Bases,End_effectors,Eta);
% 
% 
% 
NACT=size(Actuator_Bases,2);
MDim=6;
Params.fmin=ones(NACT,1)*Params.fmin(1);
Params.fmax=ones(NACT,1)*Params.fmax(1);
Params.OptimalTension=Params.OptimalTension(1)*ones(NACT,1);
L=GridSize;