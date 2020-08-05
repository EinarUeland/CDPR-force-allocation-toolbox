           function [f s lambda N_Iter InfeasibleFlag,LineIter]= Newton_Slack(X0,J_mat,w_ref,fmin,fmax,c1,c2,OptimalTension,Tol,IterMax,KappaMat,Q,epsilon,SqFac,alpha)
%  save INN
% clear
% load AQSLACK
% a=asl
% load INN
% X0=X0*0
%   load INNN
%  load  INN
% load INN
% % X0=0*X0;
% Tol=5e-9
%   load LINEWHAT
%DO ALPHA, probably yeees?
% load LINEWHAT
% alpha=(fmax(1)-fmin(1))/2; % DO NOT BOTHER AT `THIS POINT TO DIFFERENTIATE BETWEEN DIFFERNT TMIN AND TMAX
 alphaP=alpha.^2;
InfeasibleFlag=0;
% [MDIM,NACT]=size(J_mat);
% alphaS=1
% X0=0*X0
% if <0||>1
%    warning('Errorvlaue tan')
%     a=asl
% end
% SqFac=1
% =*SqFac;
% =0;
LineIter=0;
% p=0.1;
% FACDIV=0.51;
% pFac=-2+(1+p^2)/(1.^(1-p));
[MDIM,NACT]=size(J_mat);
J_matKappaMat=[J_mat Q];
% c1=c1/SCALING;
% c2=c2/SCALING;
% tol=1e-8;
 K=length(X0);
 if K<1*NACT
 w=([OptimalTension;ones(MDIM,1)]);
 f=OptimalTension;
 else 
w=X0(1:NACT+MDIM);
f=X0(1:NACT);
 end
 if K<((NACT)+2*MDIM)
lambda=1000*ones(MDIM,1);%*sum((OptimalTension).^2); HOW TO SCALE WITH FORCES?
 else
  lambda=X0(NACT+MDIM+1:end);
  if sum(lambda)==0
  lambda=100*ones(MDIM,1)*mean((OptimalTension).^2); %HOW TO SCALE WITH FORCES?
  end
  end
   if any(([w(1:NACT)-(fmin+1e-5);(fmax-1e-5)-w(1:NACT)])<0) %LETS JUMP TO COLDSTART...
     w=[OptimalTension;zeros(MDIM,1)];
       if any(([w(1:NACT)-(fmin+1e-5);(fmax-1e-5)-w(1:NACT)])<0) %LETS
       w=[(fmin+fmax)/2;zeros(MDIM,1)];
       end
 end
%  a=asl
 %SETTING UP DUMMY VARIABLES
ConditionOld=inf;
Condition=inf;
% beta=0.85;
N_Iter=0;    
% CostS=zeros(MDIM,1);
% dCostS=zeros(MDIM,1);
% ddCostS=zeros(MDIM,1);
% a=Asl
% lambda00=lambda
% s=[1;1;1];
% w=[w;s];
%SQP ITERATIVE SOLVER.
% save  HERE
f=w(1:NACT);
s=w(NACT+1:end);
beta=0.85;
c_1=1;
% a=ASls
% SqFac=1/200;
% KappaMat(4:6,4:6)=eye(3)*1500;
%  c_1=0;
% SqFac=1
% a=Asl
% a=Asls
% Tol=1e-10
while Condition>Tol
%    A2= [[diag([2+c2*1./(fmax-w).^2+c1*1./(w-fmin).^2;2*ones(MDIM,1)])] J_matKappaMat';[J_matKappaMat zeros(MDIM,MDIM)]]
%    T2=[J_matKappaMat zeros(MDIM,MDIM)]
%    T3=[T1;T2];
%     A2= [[diag([2+c2*1./(fmax-w).^2+c1*1./(w-fmin).^2 2*ones(MDIM)])] J_matKappaMat';J_matKappaMat zeros(MDIM,MDIM)];
f=w(1:NACT);
s=w(NACT+1:end);


 
 %%SLACK FROM HERE

% dCostS=KappaMat.*(SqFac*2*s+c_1.*s./(epsilon+s.^2).^0.5;-sign(s).*.*(s.*atan(s)-0.5*log(s.^2+1))./(0.5*pi));
ddCostS=KappaMat.*(SqFac*2+c_1*epsilon./(epsilon+s.^2).^(3/2));%-(sign(s).*.*(atan(s)/(0.5*pi))));
dCostS=KappaMat.*(SqFac*2*s+c_1.*s./(epsilon+s.^2).^0.5);%-sign(s).*.*(s.*atan(s)-0.5*log(s.^2+1))./(0.5*pi));
%INTERESTINGLY ENOUGH WE CAN DIFFER THE FORMULA BY PUTTING STUFF INSIDE THE ATAN THING. 


%% SLACK COST.
% 
%   s2=s(S_2==1);
%  CostS=S_1.*(s).^2+S_2.*abs(s).^(1+p);
%  dCostS=2*s.*S_1;
%  ddCostS=2*(S_1+S_3);
%  dCostS(S_2==1)=s2*(1+p)./(abs(s2).^(1-p));
%  ddCostS(S_2==1)=(1+p^2)./(abs(s2).^(1-p)); 
%    CostS=s.^2+s.^4;
%   dCostS=2*s+4*s.^3;
%   ddCostS=2+12*s.^2;



A2= [[diag([2./alphaP+c2*1./(fmax-f).^2+c1*1./(f-fmin).^2;ddCostS])] J_matKappaMat';[J_matKappaMat zeros(MDIM,MDIM)]];
%     B2= [-[2*(w-OptimalTension)+c2*1./(fmax-w) -  c1*1./(w-fmin)];2*Q ; -[J_matKappaMat*w-w_ref]];
    B2= [-[2./alphaP.*(f-OptimalTension)+c2*1./(fmax-f) -  c1*1./(f-fmin)];-dCostS ; -[J_matKappaMat*[w]-w_ref]];

    x=A2\B2;
    dLambda=x(NACT+MDIM+1:end)-lambda;
    dw=x(1:NACT+MDIM);
    t=1;
    N_Iter=N_Iter+1;
    w=w+(t*dw);
    lambda=lambda+(t*dLambda);
    w0=w;
    lambda0=lambda;
    f=w(1:NACT);
    s=w(NACT+1:end);
    %A SOMEWHAT SIMPLISTIC LINE SEARCH IMPLEMENTATION
        LimitExceed=double(any(([f-fmin;fmax-f])<0));
%       a=ASl
    while LimitExceed==1
        t=t*0.96;
        w=w0-((1-t)*dw);
        lambda=lambda0-((1-t)*dLambda);
        s=w(NACT+1:end);
        f=w(1:NACT);
        if ~any(([f-fmin;fmax-f])<0)
            LimitExceed=0;
            t=t*0.99; %JUST ANOTHER JERK IT A LITTLE AWAY FROM THE LIMIT.
            w=w0-((1-t)*dw); 
            lambda=lambda0-((1-t)*dLambda);
            s=w(NACT+1:end);
            f=w(1:NACT);
        end
    end
    
    
%    
%  S_1=(s<1).*(s>-1).*(s~=0);
%  S_3=(s==0);
%  S_2=ones(MDIM,1)-S_1-S_3;
%  CostS=S_1.*(s).^2+S_2.*abs(s);
%  dCostS=2*s.*S_1+s.*sign(S_2);
%  ddCostS=2*(S_1+S_3);
% 
%   s2=s(S_2==1);
%  CostS=S_1.*(s).^2+S_2.*abs(s).^(1+p);
%  dCostS=2*s.*S_1;
%  ddCostS=2*(S_1+S_3);
%  dCostS(S_2==1)=s2*(1+p)./(abs(s2).^(1-p));
%  ddCostS(S_2==1)=(1+p^2)./(abs(s2).^(1-p));
% 
%  CostS=s.^2+s.^4;
%   dCostS=2*s+4*s.^3;
%   ddCostS=2+12*s.^2;
 
dCostS=KappaMat.*(SqFac*2*s+c_1.*s./(epsilon+s.^2).^0.5);%-sign(s).*.*(s.*atan(s)-0.5*log(s.^2+1))./(0.5*pi));
  
% a=Asl
%  ConditionLog(N_Iter)=Condition
%  LineIterLog(N_Iter)=LineIter;

Condition=max(abs([[[[2./alphaP.*(f-OptimalTension)+c2*1./(fmax-f)-c1*1./(f-fmin)];dCostS]+[lambda'*J_matKappaMat]' ];J_matKappaMat*w-w_ref]));
% if N_Iter==2
%      a=asl
% end
%     ConditionLOG(N_Iter)=Condition;
while ConditionOld<Condition
            t=t*beta;
            w=w0-((1-t)*dw);
            lambda=lambda0-((1-t)*dLambda);
            f=w(1:NACT);
            s=w(NACT+1:end);
            LineIter=LineIter+1;

                
dCostS=KappaMat.*(SqFac*2*s+c_1.*s./(epsilon+s.^2).^0.5);%-sign(s).*.*(s.*atan(s)-0.5*log(s.^2+1))./(0.5*pi));

        Condition=max(abs([[[[2./alphaP.*(f-OptimalTension)+c2*1./(fmax-f)-c1*1./(f-fmin)];dCostS]+[lambda'*J_matKappaMat]' ];J_matKappaMat*w-w_ref]));
%         X(N_Iter)=Condition;    
        if t<1e-8
                InfeasibleFlag=1;
%                 save AQ
%                 a=asl
                Condition=-1;
                break
        end
end
ConditionOld=Condition;
        if N_Iter>IterMax
         InfeasibleFlag=2;
         Condition=-1;
        end
end
% load AQ
% a=asl
% DerS=KappaMat.*(SqFac*2*s+c_1.*s./(epsilon+s.^2).^0.5);%-sign(s).*.*(s.*atan(s)-0.5*log(s.^2+1))./(0.5*pi));
% DerF=2./alphaP*(f-OptimalTension)+c2*1./(fmax-f)-c1*1./(f-fmin)
% DerS'*J_mat-DerF'
% DerF'*pinv(J_mat)-DerS'
% pinv(J_mat)'*DerF-DerS
% 
% J_mat*pinv(J_mat)*zeros(6,1)
% 
% V=sum(abs(DerF'*pinv(J_mat)-DerS'))+sum(abs(pinv(J_mat)'*DerF-DerS))
% save AQ2
% load AQ2
% 
% 
% [lambda'*J_matKappaMat]'
% 
% J_matKappaMat'*lambda-[lambda'*J_matKappaMat]'
% 
% 
% % a=Asl
% a=asl
% if InfeasibleFlag==1||InfeasibleFlag==2
% end
% N_Iter
% if N_Iter==50
% %     a=asl
% X0(end-MDIM+1:end)-lambda
% end
% (X0(1:NACT+MDIM)-w)
% lambda-lambda00
% %
% J_mat*f-(w_ref-s)
% %
% %WERR=S is correctomundo.. 
% N_Iter
% 
% 
% N_Iter=N_Iter
% LineIter=LineIter+1
% % if N_Iter==42
%     save OUT
%     close all
%     plot(ConditionLog)
%     A=Asl
% end