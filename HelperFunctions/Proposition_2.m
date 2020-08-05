function [S_Bound, S_Inf,Condhold]=Proposition_2(Traj,SolParam,Params,Slack,FStar_s,Gamma1Solv)
P=Params.P;
Alpha=Params.alpha;
c=Params.c1;
fmax=Params.fmax(1);
fmin=Params.fmin(1);
b=SolParam.b_vector(1);
T=Traj.J;
for i=1:size(T,3)
    if Gamma1Solv==1 %Ginv minimizing norm
        Sigma(i)=norm(ginvMin_1Norm(T(:,:,i)),1);
    else
        Sigma(i)=norm(pinv(T(:,:,i)),1); %PseudoInverse minimizing norm
    end
        S_Inf(i)=max(abs(Slack(:,i)));
end

Lambda=max([Params.fmax-Params.OptimalTension;-Params.OptimalTension-Params.fmin]);

for i=1:size(T,3)
    Delta(i)=min([Params.fmax-FStar_s(:,i);-Params.fmin+FStar_s(:,i)]);
    Gamma(i)=P*Lambda^(P-1)/Alpha^(P)+ c*(1/Delta(i)+1/(fmax-fmin-Delta(i)));
    Condition=b-Sigma(i)*Gamma(i);
    if Condition>0
        Condhold(i)=1;
    else
        Condhold(i)=0;
    end
    SigmaGammaSq=Sigma(i)^2*Gamma(i)^2;

    if Condition>0 %I.e. the assumptions hold;
        S_Bound(i)=sqrt(SolParam.Epsilon*SigmaGammaSq/(b^2-SigmaGammaSq));
    if S_Inf(i)>S_Bound(i)+1e-4
        error('Something weird going on with Proposition 2, please check if the assumptions holds. If not, comment this check out') 
    end
    else
        S_Bound(i)=nan;
    end
end
end
