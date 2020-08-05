% Author: Einar Ueland. Coauthors Roger Skjetne and Thomas Sauder. 
% email: einar.s.ueland@gmail.com
% January 2020;
% Please cite relevant sources as provided in the readme file. 

if ColdStart8&&ColdstartRND
ColdStart=1;
else
ColdStart=0;
end

Feas2Mrg=[Feas2 Feas2_8];
Feas3Mrg=[Feas3 Feas3_8];
Feas4Mrg=[Feas4 Feas4_8];
Feas2WMrg=[Feas2W Feas2W_8];
Feas3WMrg=[Feas3W Feas3W_8];
Feas4WMrg=[Feas4W Feas4W_8];
% WERR2=[WERR2 WERR28];

WERR2Mrg=[WERR2 WERR28];
NLinesRand=NLines;
NLinesMrg=[NLines NLines8];
NIterWCMrg=[NIterWC NIter8WC];
Liter_WCMrg=[Liter_WC Liter8_WC];
EvalTimeWCSMrg=[EvalTimeWCS EvalTime8WCS];

NIter_P_WMrg=[NIter_P_W NIter8_P_W];
EvalTime_P_WMrg=[EvalTime_P_W EvalTime8_P_W];
Liter_P_WMrg=[Liter_P_W Liter8_P_W];
NIter_S_W2Mrg=[NIter_S_W2 NIter8_S_W2];
EvalTime_S_W2Mrg=[EvalTime_S_W2 EvalTime8_S_W2];
Liter_S_WMrg=[Liter_S_W Liter8_S_W];

 
EVALCOLLECTWarmDelta=[EvalTimeWCSMrg(Feas3WMrg==1) EvalTime_P_WMrg(Feas3WMrg==1) EvalTime_S_W2Mrg(Feas3WMrg==1)];
NITERCOLLECTWarmDelta=[NIterWCMrg(Feas3WMrg==1) NIter_P_WMrg(Feas3WMrg==1) NIter_S_W2Mrg(Feas3WMrg==1)];
EVALCOLLECTWarmP2Delta=[EvalTimeWCSMrg(Feas3WMrg==1)];
EVALCOLLECTWarmP5Delta=[EvalTime_P_WMrg(Feas3WMrg==1)];
EVALCOLLECTWarmSLack=[EvalTime_S_W2Mrg(Feas3WMrg==1)];

NITERCOLLECTWarmP2Delta=[NIterWCMrg(Feas3WMrg==1)];
NITERCOLLECTWarmP5Delta=[NIter_P_WMrg(Feas3WMrg==1)];
NITERCOLLECTWarmSLack=[NIter_S_W2Mrg(Feas3WMrg==1)];
NITERCOLLECTWarmDelta=[NIterWCMrg(Feas3WMrg==1) NIter_P_WMrg(Feas3WMrg==1) NIter_S_W2Mrg(Feas3WMrg==1)];
NITERCOLLECTWarm=[NIterWCMrg   NIter_P_WMrg NIter_S_W2Mrg];
% Hist_2(1./EVALCOLLECTWarmDelta

AvEnd=25;

 for i=1:AvEnd
    EVALSumW(i)=mean(1./EVALCOLLECTWarmDelta(NITERCOLLECTWarmDelta==i));
    EVAL_NORMALW(i)=mean(1./EVALCOLLECTWarmP2Delta(NITERCOLLECTWarmP2Delta==i));
    EVAL_P5W(i)=mean(1./EVALCOLLECTWarmP5Delta(NITERCOLLECTWarmP5Delta==i));
    EVAL_SlackW(i)=mean(1./EVALCOLLECTWarmSLack(NITERCOLLECTWarmSLack==i)); 
 end

 
 
 
if ColdStart
    
NIterCCMrg=[NIterCC NIter8CC];
EvalTimeWCCMrg=[EvalTimeWCC EvalTime8WCC];
Liter_CCMrg=[Liter_CC Liter8_CC];

NIter_P_CMrg=[NIter_P_C NIter8_P_C];
EvalTime_P_CMrg=[EvalTime_P_C EvalTime8_P_C];
Liter_P_CMrg=[Liter_P_C Liter8_P_C];

NIter_S_C2Mrg=[NIter_S_C2 NIter8_S_C2];
EvalTime_S_C2Mrg=[EvalTime_S_C2 EvalTime8_S_C2];
Liter_S_CMrg=[Liter_S_C Liter8_S_C];




EVALCOLLECT=[EvalTimeWCSMrg EvalTimeWCCMrg EvalTime_P_CMrg EvalTime_P_WMrg EvalTime_S_C2Mrg EvalTime_S_W2Mrg];

NITERCOLLECT=[NIterWCMrg NIterCCMrg NIter_P_CMrg NIter_P_WMrg NIter_S_C2Mrg NIter_S_W2Mrg];
LITERCOLLECT=[Liter_WCMrg Liter_CCMrg Liter_P_CMrg Liter_P_WMrg Liter_S_CMrg Liter_S_WMrg];

EVALCOLLECT=[EvalTimeWCSMrg EvalTimeWCCMrg EvalTime_P_CMrg EvalTime_P_WMrg EvalTime_S_C2Mrg EvalTime_S_W2Mrg];
EVALCOLLECTWarm=[EvalTimeWCSMrg  EvalTime_P_WMrg EvalTime_S_W2Mrg];
EVALCOLLECTCold=[EvalTimeWCCMrg  EvalTime_P_CMrg EvalTime_S_C2Mrg];
EVALCOLLECTColdDelta=[EvalTimeWCCMrg(Feas3Mrg==1)  EvalTime_P_CMrg(Feas3Mrg==1) EvalTime_S_C2Mrg(Feas3Mrg==1)];
NITERCOLLECTColdDelta=[NIterCCMrg(Feas3Mrg==1) NIter_P_CMrg(Feas3Mrg==1) NIter_S_C2Mrg(Feas3Mrg==1)];


    
NIterCCMrg=[NIterCC NIter8CC];
EvalTimeWCCMrg=[EvalTimeWCC EvalTime8WCC];
Liter_CCMrg=[Liter_CC Liter8_CC];

NIter_P_CMrg=[NIter_P_C NIter8_P_C];
EvalTime_P_CMrg=[EvalTime_P_C EvalTime8_P_C];
Liter_P_CMrg=[Liter_P_C Liter8_P_C];

NIter_S_C2Mrg=[NIter_S_C2 NIter8_S_C2];
EvalTime_S_C2Mrg=[EvalTime_S_C2 EvalTime8_S_C2];
Liter_S_CMrg=[Liter_S_C Liter8_S_C];

    
 for i=1:AvEnd
    EVALSumC(i)=mean(1./EVALCOLLECT(NITERCOLLECT==i));
    EVAL_NORMALC(i)=mean(1./EvalTimeWCCMrg(NIterCCMrg==i));
    EVAL_P5C(i)=mean(1./EvalTime_P_CMrg(NIter_P_CMrg==i));
    EVAL_SlackC(i)=mean(1./EvalTime_S_C2Mrg(NIter_S_C2Mrg==i)); 
 end
 %MIXED- ALL ITERATIONS
 for i=1:AvEnd
    EVALSumWarm(i)=mean(1./EVALCOLLECT);
    EVAL_NORMALWarm(i)=mean(1./EvalTimeWCCMrg(NIterCCMrg==i));
    EVAL_P5Warm(i)=mean(1./EvalTime_P_CMrg(NIter_P_CMrg==i));
    EVAL_SlackWarm(i)=mean(1./EvalTime_S_C2Mrg(NIter_S_C2Mrg==i)); 
 end




 
 
end




    
 
 
 
 
