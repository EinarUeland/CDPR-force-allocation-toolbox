% Author: Einar Ueland. Coauthors Roger Skjetne and Thomas Sauder. 
% email: einar.s.ueland@gmail.com
% January 2020;
% Please cite relevant sources as provided in the readme file. 


%ACTUATOR PLACMENTS
End_effectors =...
  [ -0.0525 -0.0525 0.0525 0.0525 0 0 0 0;...
   -0.0760 -0.0760 -0.0760 -0.0760 0.1240 0.1240 0.1240 0.1240;...
   0 0 0 0 0 0 0 0];

 Actuator_Bases=...
  [ -0.4150   -0.4150    0.4150    0.4150    0.4150   -0.4150   -0.4150    0.4150;...
   -0.3150   -0.3150   -0.3150   -0.3150    0.3150    0.3150    0.3150    0.3150;...
   -0.5000    0.5000    0.5000   -0.5000   -0.5000    0.5000   -0.5000    0.5000];


 Actuator_BasesSq=...
  [ -0.4150   -0.4150    0.4150    0.4150    0.4150   -0.4150   -0.4150    0.4150;...
   -0.3150   -0.3150   -0.3150   -0.3150    0.3150    0.3150    0.3150    0.3150;...
   -0.5000    0.5000    0.5000   -0.5000   -0.5000    0.5000   -0.5000    0.5000];

% close all
End_effectorsSquare =[End_effectors(:,1:4) [End_effectors(1,4) End_effectors(1,1) End_effectors(1,2) End_effectors(1,3) ; -End_effectors(2,1:4); End_effectors(3,1:4)]]; 
% Actuator_Bases-End_effectorsSquare

%  addpath(genpath(pwd))
if ~exist('GridSize')
GridSize=1e3; %DEFAULT
end

%TRAJECTORY LENGTH
if exist('Double')
t=linspace(0,2*pi,2*GridSize);
% a=Asl
else
t=linspace(0,1*pi,1*GridSize);
end

%DUMMY PLOT PROPERTIES
LE=LEGENDEINAR;
SCALEFACTOR=0.5;
LE.SCALEFACTOR=SCALEFACTOR;
Colorzcheme={[0 0 0],[0.8500, 0.3250, 0.0980],[0, 0.4470, 0.7410],[0.5 0.5 0.5],[0.4660, 0.6740, 0.1880],[0.9290, 0.6940, 0.1250],[0.4940, 0.1840, 0.5560],'m','y'};

%TRAJECTORY
X=sin(t)*0.1;
Y=cos(t)*0.1;
Z=sin(t).*cos(2*t)*0.1*3.4;
Traj.Eta=[X;Y;Z-0.052;-Y.*2.*t./(pi);0*X;-Z*0.5];

%YOU DO NOT HAVE TO DO IT WITH MATLAB 2019a. 
Traj.J=Get_JMatrix_Series(Actuator_Bases,End_effectors,Traj.Eta,1)


 %DO THIS AS A COMPILED FUNCTION FOR THE WIN
[MDIM NACT]=size(Traj.J(:,:,1));

Traj.WTargetMat=zeros(MDIM,size(Traj.J,3)); %TARGET FORCE
Traj.WTargetMat(3,:)=5;

%ACTUATOR LIMITATIONS
Params.fmin=ones(NACT,1)*5;
Params.fmax=ones(NACT,1)*40;

%ACTUATOR LOG BARRIER SCALING
Params.c1=0.1;
Params.c2=0.1;

%P-Norm
Params.P=2;%DEFAULT

%Optimal tension
Params.OptimalTension=ones(NACT,1)*15;
Params.alpha=(Params.fmax(1)-Params.fmin(1))/2;

%SLACK Actuator_BasesRAMETERS
Params.Q=eye(MDIM);
SolParam.Epsilon=1e-3;
SolParam.b_vector=200*ones(MDIM,1);
SolParam.SqFac=0.005;


%Solver Parameters.
SolParam.Tol=5e-5;
SolParam.Itermax=5e2;
SolParam.NRepeat=1;



%Actuator_BasesCTLARGE IS FOR MULTIPLE LINEZ
Actuator_Bases_large=[Actuator_Bases Actuator_Bases Actuator_Bases];
End_effectors_large=[End_effectors [End_effectors(:,5:8) End_effectors(:,4:-1:1)]  [End_effectors(:,4:-1:1) End_effectors(:,1:4,:)] ];
LinesIter=8:24;
% Params.fminv2=1;
Params.fminv2=1;
