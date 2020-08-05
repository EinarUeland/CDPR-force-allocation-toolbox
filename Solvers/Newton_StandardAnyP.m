 function [w lambda N_Iter InfeasibleFlag,LineIter]= Newton_StandardAnyP(X0,J_mat,w_ref,fmin,fmax,c1,c2,OptimalTension,Tol,P,IterMax,alpha)
%  load Inn0; 

% P=2;
% alpha=(fmax-fmin)/2; % DO NOT BOTHER AT `THIS POINT TO DIFFERENTIATE BETWEEN DIFFERNT TMIN AND TMAX
%  alpha=1;
% c1=c1/alpha;<
% c2=c2/alpha;
% alpha=1;
c1=0.5;
c2=0.5;
[MDIM,NACT]=size(J_mat);
InfeasibleFlag=0;
 K=length(X0);
 if K<1*NACT
 w=(OptimalTension);
 else 
w=X0(1:NACT);
 end
 if K<((NACT)+MDIM)
lambda=1000*ones(MDIM,1);%*sum((OptimalTension).^2); HOW TO SCALE WITH FORCES?
 else
  lambda=X0(NACT+1:end);
   if sum(lambda)==0
  lambda=100*ones(MDIM,1)*mean((OptimalTension).^2); %HOW TO SCALE WITH FORCES?
   end
 end
 
  if any(([w-(fmin+1e-5);(fmax-1e-5)-w])<0) %LETS JUMP TO COLDSTART...
     w=OptimalTension;
       if any(([w-(fmin+1e-5);(fmax-1e-5)-w])<0) %LETS
       w=(fmin+fmax)/2;
       end
 end

 %SETTING UP DUMMY VARIABLES
ConditionOld=inf;
Condition=inf;
beta=0.85;
N_Iter=0;    
LineIter=0;



% P*(P-1)*abs((w-OptimalTension).^P./(P-OptimalTension).^2)
% P=2
%SQP ITERATIVE SOLVER.
% save PREWH2
while Condition>Tol
     
%      D1=(P.*(w-OptimalTension)*(abs(w-OptimalTension)).^(P-2))
% D2=(P*(P-1)*(abs(w-OptimalTension)).^P)./((P-OptimalTension).^2)      + (+c2*1./(fmax-w).^2+c1*1./(w-fmin).^2);
     %    
% B22=[-V1;-[J_mat*w-w_ref]];
    
    A2= [[diag([P*(P-1)*(abs(w-OptimalTension)).^(P-2)./alpha.^P+ (+c2*1./(fmax-w).^2+c1*1./(w-fmin).^2)])+zeros(NACT,NACT)] J_mat';J_mat zeros(MDIM,MDIM)];
    B2= [-[P.*(w-OptimalTension).*(abs(w-OptimalTension)).^(P-2)./alpha.^P + c2*1./(fmax-w) -  c1*1./(w-fmin)]; -[J_mat*w-w_ref]];

%  A3= [diag(V22) J_mat';J_mat zeros(MDIM,MDIM)];
% B2(1:4)-D1P
% a=Asl
 %     B2= [-[P.*(w-OptimalTension).*abs(w-OptimalTension).^(P-2)+c2*1./(fmax-w) -  c1*1./(w-fmin)]; -[J_mat*w-w_ref]];
x=A2\B2;
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
        if ~any(([w-fmin;fmax-w])<0)
            LimitExceed=0;
            t=t*0.98; %JUST JERK IT A LITTLE AWAY FROM THE EDGE.
            w=w0-((1-t)*dw);
            lambda=lambda0-((1-t)*dLambda);
        end
    end

        Condition=max(abs([[[P.*(w-OptimalTension)./alpha.^P.*abs(w-OptimalTension).^(P-2)+c2*1./(fmax-w)-c1*1./(w-fmin)]+[lambda'*J_mat]'];J_mat*w-w_ref]));
       while ConditionOld<Condition
            t=t*beta;
            w=w0-((1-t)*dw);
            lambda=lambda0-((1-t)*dLambda);
            LineIter=LineIter+1;
            Condition=max(abs([[[P.*(w-OptimalTension)./alpha.^P.*abs(w-OptimalTension).^(P-2)+c2*1./(fmax-w)-c1*1./(w-fmin)]+[lambda'*J_mat]'];J_mat*w-w_ref]));
            if t<1e-4
                InfeasibleFlag=1;
                Condition=-1;
        %   a=asl
                break
                
            end
        end
        ConditionOld=Condition;
% ConditionLog(N_Iter)=Condition;
if N_Iter>IterMax
   InfeasibleFlag=2;
   Condition=-1;
end
% save AFT2

end
% W=(J_mat*w)-w_ref
% LineIter=LineIter
% N_Iter