    function [w lambda N_Iter InfeasibleFlag,LineIter]= Newton_Standard(X0,J_mat,w_ref,fmin,fmax,c1,c2,OptimalTension,Tol,IterMax,alpha)
% save INNStandard
% a=Asl
    % load INn0
% a=Asl
%WE WILL SCALE ALL EXCEPT TAU.. 
%   load Inn0
%  a=asl
%     coder.varsize('OptimalTension', [24 1]);
%     coder.varsize('X0', [24 1]);
%     coder.varsize('fmin', [24 1]);
%     coder.varsize('fmax', [24 1]);
%     coder.varsize('OptimalTension', [24 1]);
%     coder.varsize('J_mat', [6 24]);
%     coder.varsize('w_ref', [24 1]);
%     coder.varsize('X0', [24 1]);
% save Inn0;a=asl
% coder.varsize('fmin', [24 1]);
%   coder.varsize('fmax', [24 1]);
%   coder.varsize('OptimalTension', [24 1]);


 LineIter=0;
% alpha=(fmax(1)-fmin(1))/2; % DO NOT BOTHER AT `THIS POINT TO DIFFERENTIATE BETWEEN DIFFERNT TMIN AND TMAX
% alpha=17.5000;
% % alpha=OptimalTension(1); % DO NOT BOTHER AT `THIS POINT TO DIFFERENTIATE BETWEEN DIFFERNT TMIN AND TMAX


%COMMENT ON HOW Tau1 and Tau2 can be designed with respect to equations of
%such that x/ dominates in 
%  alpha=1;
%  alpha=1;
InfeasibleFlag=0;
%  alpha=8
% alpha=1;
[MDIM,NACT]=size(J_mat);
% X0=zeros(NACT+MDIM,1)

if length(X0)>=NACT
X0(1:NACT)=X0(1:NACT);
end
InfeasibleFlag=0;
 K=length(X0);
 if K<1*NACT
 w=(OptimalTension);
 else 
w=X0(1:NACT);
 end
 if K<((NACT)+MDIM)
lambda=1*ones(MDIM,1);%*sum((OptimalTension).^2); HOW TO SCALE WITH FORCES?
 else
  lambda=X0(NACT+1:end);
  if sum(lambda)==0
  lambda=100*ones(MDIM,1)*mean((OptimalTension).^2); %HOW TO SCALE WITH FORCES?
%  lambda=[J_mat*J_mat']\(J_mat*w);This would be the theoretical way, but not
%   helping to much. 
  end
  end
  if any(([w-(fmin+1e-5);(fmax-1e-5)-w])<0) %LETS JUMP TO COLDSTART...
     w=OptimalTension;
       if any(([w-(fmin+1e-5);(fmax-1e-5)-w])<0) %LETS
       w=(fmin+fmax)/2;
       end
  end

%  w=X0(1:NACT);
%   lambda=X0(NACT+1:end);
% 
 %SETTING UP DUMMY VARIABLES
ConditionOld=inf;
Condition=inf;
beta=0.85;
N_Iter=0;    
%SQP ITERATIVE SOLVER.
% save M2
LimitExceed=0;
% disp(w)



while Condition>Tol
%     save AQ2
    A2= [[diag([2./alpha.^2+c2*1./(fmax-w).^2.+c1*1./(w-fmin).^2])+zeros(NACT,NACT)] J_mat';J_mat zeros(MDIM,MDIM)];
    B2= [-[2./alpha.^2.*(w-OptimalTension)+c2*1./(fmax-w) -  c1*1./(w-fmin)]; -[J_mat*w-w_ref]];
    %     if rcond(A2)<6e-16
%        InfeasibleFlag=3; %TRYING THIS SHITT ALTHOUGH WE HATE IT. 
%        return
%     end
    x=A2\B2;
%     B2-A2*x
    dLambda=x(NACT+1:end)-lambda;
    dw=x(1:NACT);
    t=1;
    N_Iter=N_Iter+1;
    w=w+(t*dw);
    lambda=lambda+(t*dLambda);
    w0=w;
    lambda0=lambda;
    %A SOMEWHAT SIMPLISTIC LINE SEARCH IMPLEMENTATION
    LimitExceed=double(any(([w-fmin;fmax-w])<0));
    while LimitExceed==1
        t=t*beta;
        w=w0-((1-t)*dw);
        lambda=lambda0-((1-t)*dLambda);
        if t<1e-7
                InfeasibleFlag=3; %PROBABLY THIS IS due to rcond error
                Condition=-1;
                w=-ones(NACT,1);
            return
        end
        if ~any(([w-fmin;fmax-w])<0)
            LimitExceed=0;
            t=t*0.98; %JUST JERK IT A LITTLE AWAY FROM THE EDGE.
            w=w0-((1-t)*dw);
            lambda=lambda0-((1-t)*dLambda);
        end
    end
%     t1=t; 
%          t=t*beta;
%          w=w0-((1-t)*dw);
%          lambda=lambda0-((1-t)*dLambda);
        Condition=sum(abs([[[2./alpha.^2.*(w-OptimalTension)+c2*1./(fmax-w)-c1*1./(w-fmin)]+[lambda'*J_mat]'];J_mat*w-w_ref]));
%            C1=Condition; a=asl
        while ConditionOld<Condition;%
            t=t*beta;
            w=w0-((1-t)*dw);
            lambda=lambda0-((1-t)*dLambda);
            Condition=sum(abs([[[2./alpha.^2.*(w-OptimalTension)+c2*1./(fmax-w)-c1*1./(w-fmin)]+[lambda'*J_mat]'];J_mat*w-w_ref]));
            LineIter=LineIter+1;
            if t<1e-5
                InfeasibleFlag=1;
%                 save H1
                Condition=-1;
%                 a=Asl
%HMMM ARE WE GOING TO FAR...
                return
            end
        end
%         Conditionz(N_Iter)=Condition
        ConditionOld=Condition;
if N_Iter>IterMax
   InfeasibleFlag=2;
   Condition=-1;
end
% save INn0
% A=LS
end
%  save HERE2
% w-Av
% if LineIter==1
% %     a=asl
% end
