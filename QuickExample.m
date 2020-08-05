
%0, Start by making sure that this folder with subfolders is added to the
%MATLAB path.

%IF NOT ALREADY DONE. START BY ADDING THIS FOOLDER TO THE PATH. 

%START BY ADDING PATH

% Lets specify the actuator locations
End_effectors =...
  5*[ -0.0525 -0.0525 0.0525 0.0525 0.0525 -0.0525 -0.0525 0.0525;...
   -0.0760 -0.0760 -0.0760 -0.0760  0.0760 0.0760 0.0760 0.0760;...
   -.05 .05 .05 -.05  -.05 .05 -.05 .05];


 Actuator_Bases=...
  5*[ -0.4150   -0.4150    0.4150    0.4150    0.4150   -0.4150   -0.4150    0.4150;...
   -0.3150   -0.3150   -0.3150   -0.3150    0.3150    0.3150    0.3150    0.3150;...
   -0.5000    0.5000    0.5000   -0.5000   -0.5000    0.5000   -0.5000    0.5000];

Eta=[0;0;0;0;0;0];

%Let us draw the Figure of the CDPR;
Print_Geometry_3D(Actuator_Bases,End_effectors,Eta,3)


%Specify actuator limitations, prefferred tension, and target force load
%vector 
NACT=size(Actuator_Bases,2);
fmin=3*ones(NACT,1); fmax=100*ones(NACT,1); Optimaltension=10*ones(NACT,1);
w_ref=[0;0;50;0;0;0];
J=Get_JMatrixx(Actuator_Bases,End_effectors,Eta);

%Lets specify problem parameters
c1=0.1; c2=0.1; alpha=Optimaltension;


%Calculate actuator Forces. Standard P=2;
[ActuatorForces]= Newton_Standard([],J,w_ref,fmin,fmax,c1,c2,Optimaltension,1e-7,1e3,alpha)

%WITH P=3;
P=3;
ActuatorForcesP3=Newton_StandardAnyP([],J,w_ref,fmin,fmax,c1,c2,Optimaltension,1e-7,P,1e3,alpha)%2:Specify reference target load vector


%Slack is probably not usefull here, but demonstrated as follows;
Q=eye(6);
Epsilon=1e-3;
KappaMat=200*ones(6,1);
SqFac=0.1;
P=3;
fP3=Newton_SlackAnyP([],J,w_ref,fmin,fmax,c1,c2,Optimaltension,1e-6,1e3,KappaMat,Q,Epsilon,SqFac,P,alpha)


