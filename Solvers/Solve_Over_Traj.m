  function [Time_Tot,Eval_Per_MS,Niter,F_LINES,W_Error,Feasible,Rates,LineIter,Slog, FF]=Solve_Over_Traj(Method,Params,Traj,SolParam,Init,Compiled,Display,Timing,Return_On_Infeasible)
VerifyIndependent=0;
anyWMax=2e3;
OptimalTension=Params.OptimalTension;
c1=Params.c1;
c2=Params.c2;
fmin=Params.fmin;
fmax=Params.fmax;
Time_Tot=nan;
Eval_Per_MS=nan;
J=Traj.J;
WTargetMat=Traj.WTargetMat;
Feasible=1;
NMax=SolParam.Itermax;
Tol=SolParam.Tol;
NRepeat=SolParam.NRepeat;
Sad=0;

%PREALLOCATION:
[MDIM,NACT,L]=size(J);F_LINES=nan(NACT,L);FF=nan(1,L);W_Error=nan(MDIM,L);
TimeIter=nan(1,L);Niter=nan(1,L);TIMEITITER=nan(1,L);Feasible=nan(1,L);
Slog=nan(MDIM,L);LineIter=nan(1,L);EXITFLAG=nan(1,L);Rates=nan(1,L);
%INITIALIZING
x0=[OptimalTension;zeros(MDIM,1)];
if Method==8||Method==9 %SLACK VERSION
x0=[OptimalTension;zeros(2*MDIM,1)];
end
if strcmp(Init,'Warm')
K=1;
else
K=0;
end
Lambda=[];%DUMMY


%SETTING UP SOLVERS
if Method==3 %FMINCON
    Alpha=(fmax-fmin)/2;
    fun = @(x) ones(1,NACT)*[((x-OptimalTension)./Alpha).^2-(c2*log(-(x-fmax)))-(c1*log(-(-x+fmin)))]  ;
    options = optimoptions('fmincon','Display','off');
end
if Method==4%CASADI- Nonlinear optimal solver, extra packages are needed. 
    import casadi.*
    WTarget=WTargetMat(:,1);
Aeq=J(:,:,1);
[prob,solver]=DesignSolverNoInEq(size(Aeq));
arg = struct('x0', OptimalTension,'lbg',zeros(MDIM,1),'ubg',zeros(MDIM,1),'p', [Aeq(:);WTarget(:);OptimalTension(:);fmin(:);fmax(:);c1;c2],'lam_g0',[],'lam_x0',[]);
end
if Method==5 %LSQ-LION
options = optimoptions('lsqlin','Display','off');
C=diag(ones(NACT,1));
D=OptimalTension;
end






    
%STARTING ITERATIVE SOLVER
for ii=1:L
%     ii=ii;

if Method==1
tic
for w=1:NRepeat
if ~strcmp(Compiled,'Compiled')

    [F_LINES(:,ii), Lambda,Niter(ii),FF(ii),LineIter(ii)]=Newton_Standard(x0*K,J(:,:,ii),WTargetMat(:,ii),fmin,fmax,c1,c2,OptimalTension,Tol,NMax,Params.alpha);
elseif strcmp(Compiled,'Compiled')      
    if MDIM==6&&NACT==8  %CORRECTLY ALLOCATED IS SOMEWHAT FASTER, BUT BY HOW MUCH ONE MIGHT ASK..
        [F_LINES(:,ii), Lambda,Niter(ii),FF(ii),LineIter(ii)]=Newton_Standard3D_mex(x0*K,J(:,:,ii),WTargetMat(:,ii),fmin,fmax,c1,c2,OptimalTension,Tol,NMax,Params.alpha);
    else
            [F_LINES(:,ii), Lambda,Niter(ii),FF(ii),LineIter(ii)]=Newton_Standard_mex(x0*K,J(:,:,ii),WTargetMat(:,ii),fmin,fmax,c1,c2,OptimalTension,Tol,NMax,Params.alpha);
    end
end
end
TimeIter(ii)=toc/NRepeat;

elseif Method==7
tic
        for w=1:NRepeat
if ~strcmp(Compiled,'Compiled')
            [F_LINES(:,ii), Lambda,Niter(ii),FF(ii),LineIter(ii)]=Newton_StandardAnyP(K*x0,J(:,:,ii),WTargetMat(:,ii),fmin,fmax,c1,c2,OptimalTension,Tol,Params.P,NMax,Params.alpha);
    elseif strcmp(Compiled,'Compiled')
     if MDIM==6&&NACT==8
            [F_LINES(:,ii), Lambda,Niter(ii),FF(ii),LineIter(ii)]=Newton_StandardAnyP3D_mex(K*x0,J(:,:,ii),WTargetMat(:,ii),fmin,fmax,c1,c2,OptimalTension,Tol,Params.P,NMax,Params.alpha);
         else
             [F_LINES(:,ii), Lambda,Niter(ii),FF(ii),LineIter(ii)]=Newton_StandardAnyP_mex(K*x0,J(:,:,ii),WTargetMat(:,ii),fmin,fmax,c1,c2,OptimalTension,Tol,Params.P,NMax,Params.alpha);
         end
end
        end
 TimeIter(ii)=toc/NRepeat;

elseif Method==8 %SLACK P=2
    tic
for w=1:NRepeat
    if ~strcmp(Compiled,'Compiled')
[F_LINES(:,ii),s, Lambda,Niter(ii),FF(ii),LineIter(ii)]=Newton_Slack(x0*K,J(:,:,ii),WTargetMat(:,ii),fmin,fmax,c1,c2,OptimalTension,Tol,NMax,SolParam.b_vector,Params.Q,SolParam.Epsilon,SolParam.SqFac,Params.alpha);
elseif strcmp(Compiled,'Compiled')
   if MDIM==6&&NACT==8
        [F_LINES(:,ii),s, Lambda,Niter(ii),FF(ii),LineIter(ii)]=Newton_Slack3D_mex(x0*K,J(:,:,ii),WTargetMat(:,ii),fmin,fmax,c1,c2,OptimalTension,Tol,NMax,SolParam.b_vector,Params.Q,SolParam.Epsilon,SolParam.SqFac,Params.alpha);        
   else
    [F_LINES(:,ii),s, Lambda,Niter(ii),FF(ii),LineIter(ii)]=Newton_Slack_mex(x0*K,J(:,:,ii),WTargetMat(:,ii),fmin,fmax,c1,c2,OptimalTension,Tol,NMax,SolParam.b_vector,Params.Q,SolParam.Epsilon,SolParam.SqFac,Params.alpha);        
   end
end
end
TimeIter(ii)=toc/NRepeat;

  
 elseif Method==9 %SLACK ANY P Norm
         tic
for w=1:NRepeat

     if ~strcmp(Compiled,'Compiled')
    [F_LINES(:,ii),s, Lambda,Niter(ii),FF(ii),LineIter(ii)]=Newton_SlackAnyP(x0*K,J(:,:,ii),WTargetMat(:,ii),fmin,fmax,c1,c2,OptimalTension,Tol,NMax,SolParam.b_vector,Params.Q,SolParam.Epsilon,SolParam.SqFac,Params.P,Params.alpha);
     elseif strcmp(Compiled,'Compiled')
if MDIM==6&&NACT==8
[F_LINES(:,ii),s, Lambda,Niter(ii),FF(ii),LineIter(ii)]=Newton_SlackAnyP3D_mex(x0*K,J(:,:,ii),WTargetMat(:,ii),fmin,fmax,c1,c2,OptimalTension,Tol,NMax,SolParam.b_vector,Params.Q,SolParam.Epsilon,SolParam.SqFac,Params.P,Params.alpha);        
else
         [F_LINES(:,ii),s, Lambda,Niter(ii),FF(ii),LineIter(ii)]=Newton_SlackAnyP_mex(x0*K,J(:,:,ii),WTargetMat(:,ii),fmin,fmax,c1,c2,OptimalTension,Tol,NMax,SolParam.b_vector,Params.Q,SolParam.Epsilon,SolParam.SqFac,Params.P,Params.alpha);        
end
     end
end
TimeIter(ii)=toc/NRepeat;



elseif Method==2% PINV
        tic
        for w=1:NRepeat
    if ~strcmp(Compiled,'Compiled')
            [F_LINES(:,ii)]=pinv(J(:,:,ii))*(WTargetMat(:,ii)-J(:,:,ii)*OptimalTension)+OptimalTension;
      elseif strcmp(Compiled,'Compiled')
         if MDIM==3&&NACT==4
            [F_LINES(:,ii)]=pinv_mex(J(:,:,ii))*(WTargetMat(:,ii)-J(:,:,ii)*OptimalTension)+OptimalTension;
     elseif MDIM==6&&NACT==8
            [F_LINES(:,ii)]=pinv3D_mex(J(:,:,ii))*(WTargetMat(:,ii)-J(:,:,ii)*OptimalTension)+OptimalTension;
         end
    end
    end
    TimeIter(ii)=toc/NRepeat;
elseif Method==3 %FminCon
tic
for w=1:NRepeat
if K==0
    x0=OptimalTension;
end
F_LINES(:,ii)= fmincon(@(x)fun(x),x0(1:NACT),[],[],J(:,:,ii),WTargetMat(:,ii),[],[],[],options);
end
TimeIter(ii)=toc/NRepeat;
elseif Method==20
            if strcmp(Compiled,'Compiled')
F_LINES(:,ii) =   KernelMethodis_mex2(J(:,:,ii),WTargetMat(:,ii),fmin,fmax,OptimalTension);

        else
            F_LINES(:,ii) =   KernelMethodis(J(:,:,ii),WTargetMat(:,ii),fmin,fmax,OptimalTension);
        end

elseif Method==4
tic
for w=1:NRepeat
WTarget=WTargetMat(:,ii);
Aeq=J(:,:,ii);
arg.p=[Aeq(:);WTarget(:);OptimalTension(:);fmin(:);fmax(:);c1;c2];
[Ch,sol1] = evalc('solver.call(arg);');  
arg.x0=full(sol1.x); 
arg.lam_g0=full(sol1.lam_g); 
arg.lam_x0=full(sol1.lam_x); 
F_LINES(:,ii)=arg.x0;

end
TimeIter(ii)=toc/NRepeat;

elseif Method==5
    tic
for w=1:NRepeat
[LSQFLINES,resnorm,residual,EXITFLAG(ii),output,lambda]=lsqlin(C,D,[],[],J(:,:,ii),WTargetMat(:,ii),fmin,fmax,x0(1:NACT),options);

end

TimeIter(ii)=toc/NRepeat;
if length(LSQFLINES)>0
F_LINES(:,ii)=LSQFLINES;
end
TimeIter(ii)=toc/NRepeat;
end

if Method==8||Method==9
   W_Error(:,ii)=J(:,:,ii)*F_LINES(:,ii)-WTargetMat(:,ii);  
Slog(:,ii)=s;
%     if sum(sum(abs((W_Error(:,ii)))))>1e-1
%             Feasible(ii)=-1;
%             save WHY
% % a=asl
%     end
% ii=ii
x0=[F_LINES(:,ii);s; Lambda];
W_Error(:,ii)=J(:,:,ii)*F_LINES(:,ii)-WTargetMat(:,ii);  
% save ASL
% a=Asl
if any(abs(W_Error(:,ii))>anyWMax)
  options = optimoptions('lsqlin','Display','off');
    C2=diag(ones(NACT+MDIM,1));
    D2=[OptimalTension;zeros(MDIM,1)];
    fmin2=[fmin;-anyWMax*SolParam.b_vector^-1*ones(MDIM,1)];
    fmax2=[fmax;anyWMax*SolParam.b_vector^-1*ones(MDIM,1)];
[XDummy, resnorm,residual,exitflag]=lsqlin(C2,D2,[],[],[J(:,:,ii) SolParam.b_vector],WTargetMat(:,ii),[fmin2],[fmax2],x0(1:NACT),options);
% XDummy(1:NACT)-x0(1:NACT)
if exitflag~=1
Feasible(ii)=-2;

else
    Feasible(ii)=0;
end
else
  Feasible(ii)=1;  
end
% Method=Method
% IterdErr(:,ii)=J(:,:,ii)*F_LINES(:,ii)-WTargetMat(:,ii)+(SolParam.b_vector*s);  
% if sum(abs(IterdErr(:,ii)))>1
%     save AQUI
%     a=asl
% end

else
x0=[F_LINES(:,ii); Lambda]; %WARM START GIVES US NOTHING...
W_Error(:,ii)=J(:,:,ii)*F_LINES(:,ii)-WTargetMat(:,ii);  

if sum(sum(abs((W_Error(:,ii)))))>1e-4
            Feasible(ii)=-1;
%             x0=OptimalTension; %CANNOT USE WARMSTART FOSHO...
            
    %RETESTING USING LSQLIN (in order to have verify using a method
    %independent on sqp-solver
%     [XDummy, resnorm,residual,exitflag]=lsqlin(C,D,[],[],J(:,:,ii),WTargetMat(:,ii),fmin,fmax,x0(1:NACT),options);
 
if (VerifyIndependent==1)
options = optimoptions('lsqlin','Display','off');
C=diag(ones(NACT,1));
D=OptimalTension;
DeltaHmin=1e-3;
[XDummy, resnorm,residual,exitflag]=lsqlin(C,D,[],[],J(:,:,ii),WTargetMat(:,ii),fmin+DeltaHmin,fmax-DeltaHmin,x0(1:NACT),options);
% a=ASl
else
exitflag=0;
end
    if exitflag==1 %LSQLIN IS FEASIBLE BUT NOT OTHER... THIS IS THE PROBLEMO..
        save CHC;
        Feasible(ii)=-2; %WE RETURNED FNON-FEASIBLE, BUT IN ReALITY IT IS FEasiBLE...
        a=asl
            if Return_On_Infeasible==1
              a=Asl
            end
        
       
        

    
    end
    
    if exitflag~=1
        

        if Return_On_Infeasible==1
                    if Display==1
        fprintf('Warning, iteratoin %d is not feasible. Returning\n',ii)
                    end
        
        return
        else
        end
    end  
%     else
%         save WHAT
%         a=WRONG
%     end
else
Feasible(ii)=1;

end


end
end



Eval_Per_MS=1e-3./TimeIter;
Eval_Per_MSIJ=1e-3./TIMEITITER;
Time_Tot=sum(TimeIter);
    if any([F_LINES(:,ii)-fmin;fmax-F_LINES(:,ii)]<-10*Tol)
        Feasible(ii)=-1;
    end

if size(F_LINES,2)>1

for i=1:size(F_LINES,1)
RatesA(i,:)=(diff(F_LINES(i,:)));
end
% Rates=([Rates(:,1:end) Rates(:,end)]+[Rates(:,1) Rates(:,1:end) ])/2;
Rates=([RatesA(:,1:end) RatesA(:,end)]+[RatesA(:,1) RatesA(:,1:end) ])/2;

if isfield(Params,'dt')
for i=1:size(F_LINES,1)
DRates(i,:)=(diff(Rates(i,:)));
end
% DRates=([DRates(:,1:end) DRates(:,end)]+[DRates(:,1) DRates(:,1:end) ])/2;
DRates=([DRates(:,1) DRates(:,1:end) ]);

Rates(abs(DRates)>Params.dt*0.1)=nan;
end
end
if Display~=0
fprintf('Total time (MS) %2.2f \n\n\n\n',1000*Time_Tot);
end 
  end
%  end




  