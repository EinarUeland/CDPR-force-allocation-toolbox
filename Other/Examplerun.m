%THESE ARE SOME CLOSED FORM ALTERNATIVES THAT WAS IMPLEMENTED TO UNDERSTAND
%ALTERNATIVE METHODS.

% Lets specify the actuator locations
End_effectors =...
  [-0.1750 -0.1750 0.1750 0.1750 ;-0.950 0.950 0.950 -0.950;0.00 0 0.00 0];
 Actuator_Bases=...
  [-3.25   -3.25   3.25    3.25; 3.25 -3.25 -3.25 3.25;0 0 0 0];
Eta6=[0.2 0 0 0 0 0.1]';
Selector=[1 2 6]';
Eta3=Eta6(Selector);
Print_Geometry_3D(Actuator_Bases,End_effectors,Eta6,3)




%Specify actuator limitations, prefferred tension, and target force load
%vector 
NACT=size(Actuator_Bases,2);
fmin=3*ones(NACT,1); fmax=100*ones(NACT,1); Optimaltension=10*ones(NACT,1);
w_ref=[0;0;50];
J=Get_JMatrixx(Actuator_Bases,End_effectors,Eta6);
J=J(Selector,:);


%WITH Kernel method (CLOSED FORM)
[ActuatorForcesK]= Kernel_Methodis(J,w_ref,fmin,fmax,Optimaltension)
%WITH Redistributive Pseudoinverse (CLOSED FORM, almost always provide optimal solutions)
ActuatorForcesPinv=PINVIMPROVED_2(J,w_ref,fmin,fmax,Optimaltension)



%COMPARISION
%Calculate actuator Forces. Standard P=2;
c1=0.001; c2=0.001; alpha=Optimaltension;
[ActuatorForces lambda N_Iter InfeasibleFlag,LineIter]= Newton_Standard([],J,w_ref,fmin,fmax,c1,c2,Optimaltension,1e-7,1e3,alpha)
