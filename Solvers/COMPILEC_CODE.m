
%SETTING UP 2D MEX FILES

Eta_CS1=[0;0;0];
Nact_CS1=4;
Mdim_CS1=3;
X0_CS1_slack=ones(Nact_CS1+2*Mdim_CS1,1);
X0_CS1=ones(Nact_CS1+Mdim_CS1,1);

Aeq_CS1=rand(Mdim_CS1,Nact_CS1);
WTarget_CS1=(rand(Mdim_CS1,1));
tmin_CS1=ones(Nact_CS1,1);
tmax_CS1=2*ones(Nact_CS1,1);
OptimalTension_CS1=tmin_CS1/2+tmax_CS1/2;
KappaMat_CS1=zeros(3,1);

Nact=8;
Mdim=6;
Eta_CS2=[0;0;0];
Aeq_CS2=rand(Mdim,Nact);
WTarget_CS2=(rand(Mdim,1));
tmin_CS2=ones(Nact,1);
tmax_CS2=2*ones(Nact,1);
OptimalTension_CS2=tmin_CS2/2+tmax_CS2/2;
KappaMat_CS2=zeros(6,1);
%SLACK: 
INT=0;
X0_CS2=ones(Nact+Mdim,1);
X0_CS2_slack=ones(Nact+Mdim*2,1);
tau1=0.1;
tau2=0.1;
P=1;
Q1=eye(3);
Q2=eye(6);
%A little faster if we specify size afront... Three versions are sizes [3x4],[6x8],[mxn].
%SLACK NEW KAPPA STRAT
codegen Newton_Slack  -o Newton_Slack_mex -args {coder.typeof(0, [36, 1],1),coder.typeof(0, [6, 24],1),coder.typeof(0, [6, 1],1),coder.typeof(0, [24, 1],1),coder.typeof(0, [24, 1],1),1,1,coder.typeof(0, [24, 1],1),1e-6,100,coder.typeof(0, [6, 1],1),coder.typeof(0, [6, 6],1),1,1,1} 
codegen Newton_Slack  -o Newton_Slack3D_mex -args {X0_CS2_slack,Aeq_CS2,WTarget_CS2,tmin_CS2,tmax_CS2,0,0,OptimalTension_CS2,0,0,KappaMat_CS2,Q2,0,0,1} 
codegen Newton_Slack  -o Newton_Slack2D_mex -args {X0_CS1_slack,Aeq_CS1,WTarget_CS1,tmin_CS1,tmax_CS1,0,0,OptimalTension_CS1,0,0,KappaMat_CS1,Q1,0,0,1} 
fprintf('.')
%SLACK ANYP
codegen  Newton_SlackAnyP  -o  Newton_SlackAnyP_mex -args {coder.typeof(0, [36, 1],1),coder.typeof(0, [6, 24],1),coder.typeof(0, [6, 1],1),coder.typeof(0, [24, 1],1),coder.typeof(0, [24, 1],1),1,1,coder.typeof(0, [24, 1],1),1e-6,100,coder.typeof(0, [6, 1],1),coder.typeof(0, [6, 6],1),1,1,1,1} 
codegen  Newton_SlackAnyP  -o  Newton_SlackAnyP3D_mex -args {X0_CS2_slack,Aeq_CS2,WTarget_CS2,tmin_CS2,tmax_CS2,0,0,OptimalTension_CS2,0,0,KappaMat_CS2,Q2,0,0,1,1} 
codegen  Newton_SlackAnyP  -o  Newton_SlackAnyP2D_mex -args {X0_CS1_slack,Aeq_CS1,WTarget_CS1,tmin_CS1,tmax_CS1,0,0,OptimalTension_CS1,0,0,KappaMat_CS1,Q1,0,0,1,1} 
fprintf('.')

%NORMAL SCALED
codegen Newton_Standard  -o Newton_Standard_mex -args {coder.typeof(0, [32, 1],1),coder.typeof(0, [6, 24],1),coder.typeof(0, [6, 1],1),coder.typeof(0, [24, 1],1),coder.typeof(0, [24, 1],1),tau1,tau2,coder.typeof(0, [24, 1],1),1e-6,100,1} 
codegen Newton_Standard  -o Newton_Standard3D_mex -args {X0_CS2,Aeq_CS2,WTarget_CS2,tmin_CS2,tmax_CS2,0.1,0.1,OptimalTension_CS2,1e-6,100,1} 
codegen Newton_Standard  -o Newton_Standard2D_mex -args {X0_CS1,Aeq_CS1,WTarget_CS1,tmin_CS1,tmax_CS1,0.1,0.1,OptimalTension_CS1,1e-6,100,1} 
fprintf('.')

%P-LICIOUS SCALED                            
codegen Newton_StandardAnyP  -o Newton_StandardAnyP_mex -args {coder.typeof(0, [32, 1],1),coder.typeof(0, [6, 24],1),coder.typeof(0, [6, 1],1),coder.typeof(0, [24, 1],1),coder.typeof(0, [24, 1],1),tau1,tau2,coder.typeof(0, [24, 1],1),1e-6,100,P,1} 
codegen Newton_StandardAnyP  -o Newton_StandardAnyP3D_mex -args {X0_CS2,Aeq_CS2,WTarget_CS2,tmin_CS2,tmax_CS2,0.1,0.1,OptimalTension_CS2,1e-6,100,P,1} 
codegen Newton_StandardAnyP  -o Newton_StandardAnyP2D_mex -args {X0_CS1,Aeq_CS1,WTarget_CS1,tmin_CS1,tmax_CS1,0.1,0.1,OptimalTension_CS1,1e-6,100,P,1} 

%PINV
codegen pinv  -o pinv3D_mex -args {Aeq_CS2} 


%KERNELMETHOD
codegen  Kernel_Methodis  -o  KernelMethodis_mex2 -args {coder.typeof(0, [6, 24],1),coder.typeof(0, [6, 1],1),coder.typeof(0, [24, 1],1),coder.typeof(0, [24, 1],1),coder.typeof(0, [24, 1],1)}


% METHOD FOR SOLV
codegen  Get_JMatrix  -o  Get_JMatrix_mex -args {coder.typeof(0, [3, 24],1),coder.typeof(0, [3, 24],1),coder.typeof(0, [6, 1],1)}

[Traj.J(:,:,ii)]=Get_JMatrix(Actuator_Bases,End_effectors,Traj.Eta(:,ii));


fprintf('.\n')


