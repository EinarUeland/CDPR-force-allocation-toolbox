function [FLINES Aeq FGlob Flag]=KernelMethodis(Aeq,Wt,tmin,tmax,OptimalTension)
%(X0,Aeq,WTarget,tmin,tmax,tau1,tau2,OptimalTension,Tol,IterMax,KappaMat,epsilon,SqFac,TANFAC)
%KernelBased Method for quadratic programming with  n-m=1;
[m n]=size(Aeq);
if n-m~=1
    error('The number of actuators (%d) must be one more than degrees of freedom (%d)',m,n)
end
% FINDING DESIRED
WtBar=Wt-Aeq*OptimalTension;
Flag=0;



Lambdamin=zeros(n,1);
Lambdamax=zeros(n,1);
Vh=null(Aeq);
Vp=Aeq\(WtBar);

LambdaStar=-(Vp'*Vh)/(Vh'*Vh);
K1=tmin-Vp-OptimalTension;
K2=tmax-Vp-OptimalTension;
for z=1:length(OptimalTension)
if Vh(z)<0
    Lambdamin(z)=K2(z)/Vh(z);
    Lambdamax(z)=K1(z)/Vh(z);
else
    Lambdamin(z)=K1(z)/Vh(z);
    Lambdamax(z)=K2(z)/Vh(z);
end
end
Lambdamin=max(Lambdamin);
Lambdamax=min(Lambdamax);
if Lambdamin>Lambdamax
    %#infeasible
FLINES=zeros(n,1);
Flag=1;
%INFEASIBLE, But what we really should is to scale down...
elseif LambdaStar<Lambdamin
FLINES=(Lambdamin*Vh)+Vp+OptimalTension;
elseif LambdaStar>Lambdamax
FLINES=(Lambdamax*Vh)+Vp+OptimalTension;
else
FLINES=(Vh*LambdaStar)+Vp+OptimalTension;
end
FGlob=Aeq*FLINES;
end





