 function [FOut]=NONRecursivePinv(J,W_O,tmin_0,tmax_0,OptimalTension_0)
W=W_O-J*OptimalTension_0;
tmin=tmin_0-OptimalTension_0;
tmax=tmax_0-OptimalTension_0;
 

[MDIM NACT]=size(J);
L=2^NACT;
MAT=nan(L,size(tmin,1));
INDX=ff2n(3).*HA(:,2)';
MAT(:,HA(:,1))=INDX

FOff=pinv(J)*(W);
if any(FOff<tmin)||any(FOff>tmax)
else
    return
end

for i=1:L-1
SatIndex=find(isnan(MAT(i+1,:))==0)
Offindex=find(isnan(MAT(i+1,:))==1)


%CONSIDER TO MAKE A SIMPLE IF FEASIBLE TEST (i.e. log feasible
%configurations that are not on lowest depth). 





FOff=pinv(J(:,Offindex))*(W-J(:,SatIndex)*MAT(i,SatIndex)');
if any(FOff<tmin(Offindex))||any(FOff>tmax(Offindex))
FOff=FOff*inf;
end

LOGF(SatIndex,i)=FOff;
LOGF(Offindex,i)=MAT(i,SatIndex)';
[a z]=min(sum([LOGF].^2));
FOut=LOGF(:,z);
end

% end
