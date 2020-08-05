% Author: Einar Ueland
% email: einar.s.ueland@gmail.com
% September 2019;
% If used, please cite relevant sources as provided in the readme file. 

function J=Get_JMatrix_Series(Actuator_Bases,End_effectors,Eta,Compiled)
if nargin<4
    Compiled=1
end
[~, NACT]=size(Actuator_Bases);
J=zeros(6,NACT,size(Eta,2));


for ii=1:size(Eta,2)
if Compiled==1
    J(:,:,ii)=Get_JMatrix_mex(Actuator_Bases,End_effectors,Eta(:,ii));
else
    J(:,:,ii)=Get_JMatrixx(Actuator_Bases,End_effectors,Eta(:,ii));
end
end
end