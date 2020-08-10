
%FIX ME!....



  function [F_T, infeasibilityFlag,StepLog, NPINV]= PINVIMPROVED_2(J,W_O,tmin_0,tmax_0,OptimalTension_0)
Wt=W_O-J*OptimalTension_0;
tmin=tmin_0-OptimalTension_0;
tmax=tmax_0-OptimalTension_0;
% a=Asl


NPINV=0;
infeasibilityFlag=0;
tmin0=tmin;
tmax0=tmax;
F_T=pinv(J)*(Wt);
NPINV=NPINV+1;
NACT=length(F_T);
F_TOrg=F_T;
iReg=[];
TREg=[];
LINDEX=[[1:NACT]' F_T];
NLindex=[];
StepLog=[];
% if any(F_T<tmin0)||any(LINDEX(:,2)>tmax0)
while any(LINDEX(:,2)<tmin0)||any(LINDEX(:,2)>tmax0)
A=1:NACT;

[a ii]=min([LINDEX(:,2)-tmin0;tmax0-LINDEX(:,2)]);
if ii>length(tmax0)
ii=mod(ii,length(tmax0));
if ii==0
    ii=ii+length(tmax0);
end
    T0=tmax0(ii);
else
    ii=mod(ii,length(tmax0));
if ii==0
    ii=ii+length(tmax0);
end
    T0=tmin0(ii);
end
NLindex=[NLindex; [LINDEX(ii,1) T0]];
LINDEX(ii,:)=[];% WE HAVE REMOVED IT. 
if rank(J)<size(J,1)
    infeasibilityFlag=1;
%     a=asl
end
F_T=pinv(J(:,LINDEX(:,1)))*(Wt-J(:,NLindex(:,1))*NLindex(:,2));
NPINV=NPINV+1;

LINDEX(:,2)=F_T;
tmin0=tmin(LINDEX(:,1));
tmax0=tmax(LINDEX(:,1));
K=zeros(NACT,1);
K(1:length(tmin0))=LINDEX(:,1);
StepLog=[StepLog  K];
end
X0(LINDEX(:,1))=LINDEX(:,2)
if length(NLindex)>0
X0(NLindex(:,1))=NLindex(:,2);
end
F_T=X0';
%CHECK FOR INCONSISTENCY...
if sum(abs(J*F_T-Wt))>1e-2
    infeasibilityFlag=1;
end
F_T=F_T+OptimalTension_0;
end
