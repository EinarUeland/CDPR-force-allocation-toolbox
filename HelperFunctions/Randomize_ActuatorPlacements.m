% Author: Einar Ueland
% email: einar.s.ueland@gmail.com
% September 2019;
% Randomize configurations according to Algorithm 2 (Case 1)



N=7+randi(17);
[Actuator_Bases End_effectors]=  GETRNDACT();

for i=2:N
[Actuator_Bases1 End_effectors1]=GETRNDACT();
Actuator_Bases=[Actuator_Bases Actuator_Bases1];
End_effectors=[End_effectors End_effectors1];
end
Eta=zeros(6,3);



function [Actuator_Bases1 End_effectors1]=  GETRNDACT()
Area=randi(6);
X_half=0.4150;
Y_half=0.3150;
Z_half=0.5000;

if Area==1
X=-X_half;
Y=((rand-0.5)*2)*Y_half;
Z=((rand-0.5)*2)*Z_half;
elseif Area==6
X=X_half;
Y=((rand-0.5)*2)*Y_half;
Z=((rand-0.5)*2)*Z_half;
elseif Area==2
Z=-Z_half;
Y=((rand-0.5)*2)*Y_half;
X=((rand-0.5)*2)*X_half;
elseif Area==5
Z=Z_half;
Y=((rand-0.5)*2)*Y_half;
X=((rand-0.5)*2)*X_half;
elseif Area==4
Y=-Y_half;
Z=((rand-0.5)*2)*Z_half;
X=((rand-0.5)*2)*X_half;
elseif Area==3
Y=Y_half;
Z=((rand-0.5)*2)*Z_half;
X=((rand-0.5)*2)*X_half;
end
Actuator_Bases1=[X;Y;Z];

L1=(2*0.0525);
L2=(0.0525^2+0.0760^2)^0.5;
L3=L2;
LTOT=L1+L2+L3;

Lchoose=rand*LTOT;
if Lchoose<L1
    Y=-0.0760;
    X=(rand-0.5)*2*0.0525;
elseif Lchoose<L1+L2
RND=rand;
    X=0.0525+(0-0.0525)*RND;
    Y=-0.0760+0.0760*RND;
elseif Lchoose<L1+L2+L3
RND=rand;
    X=-0.0525+(0.0525)*RND;
    Y=-0.0760+0.0760*RND;
end

End_effectors1=[X;Y;0];

 end
