function [J]=GetGeoData(Pact,PLC,Eta)
ROTZ= [ cos(Eta(6)) -sin(Eta(6)) 0; sin(Eta(6)) cos(Eta(6)) 0;0 0 1];
ROTY= [ cos(Eta(5)) 0 sin(Eta(5)); 0 1 0;-sin(Eta(5)) 0 cos(Eta(5))];
ROTX= [1 0 0;0  cos(Eta(4)) -sin(Eta(4)); 0 sin(Eta(4)) cos(Eta(4))];
r= ROTX*ROTY*ROTZ*PLC;
a_ei=r+repmat(Eta(1:3),1,size(Pact,2));
a_ai=Pact;
u=(a_ai-a_ei)./repmat(sum((a_ai-a_ei).^2).^0.5,size(Pact,1),1);
J=[u;cross(r,u)];
end