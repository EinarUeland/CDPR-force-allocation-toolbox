/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Newton_Slack.c
 *
 * Code generation for function 'Newton_Slack'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Newton_Slack.h"
#include "power.h"
#include "mldivide.h"
#include "any.h"
#include "mean.h"
#include "sum.h"
#include "Newton_Slack_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 15,    /* lineNo */
  "Newton_Slack",                      /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_Slack.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 98,  /* lineNo */
  "Newton_Slack",                      /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_Slack.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 99,  /* lineNo */
  "Newton_Slack",                      /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_Slack.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 121, /* lineNo */
  "Newton_Slack",                      /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_Slack.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 171, /* lineNo */
  "Newton_Slack",                      /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_Slack.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 177, /* lineNo */
  "Newton_Slack",                      /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_Slack.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 191, /* lineNo */
  "Newton_Slack",                      /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_Slack.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 193, /* lineNo */
  "Newton_Slack",                      /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_Slack.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 67,  /* lineNo */
  5,                                   /* colNo */
  "fltpower",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

/* Function Definitions */
void Newton_Slack(const emlrtStack *sp, const real_T X0[10], const real_T Aeq[12],
                  const real_T WTarget[3], const real_T tmin[4], const real_T
                  tmax[4], real_T tau1, real_T tau2, const real_T
                  OptimalTension[4], real_T Tol, real_T IterMax, const real_T
                  KappaMat[3], const real_T Q[9], real_T epsilon, real_T SqFac,
                  real_T alpha, real_T f[4], real_T s[3], real_T lambda[3],
                  real_T *N_Iter, real_T *InfeasibleFlag, real_T *LineIter)
{
  real_T alphaP;
  int32_T LimitExceed;
  real_T AeqKappaMat[21];
  int32_T i;
  real_T w[7];
  real_T dv0[4];
  boolean_T b_X0[8];
  real_T Condition;
  real_T ConditionOld;
  real_T dCostS[3];
  real_T z1[3];
  boolean_T p;
  real_T b_epsilon[3];
  real_T A2_tmp[4];
  real_T dLambda_idx_2;
  real_T t;
  real_T lambda0_idx_0;
  real_T dLambda_idx_0;
  real_T lambda0_idx_1;
  real_T dLambda_idx_1;
  real_T dv1[4];
  real_T w0[7];
  real_T d[49];
  real_T x[10];
  real_T d0;
  real_T b_d[100];
  real_T lambda0_idx_2;
  boolean_T b_x[8];
  int32_T k;
  boolean_T exitg1;
  real_T a[7];
  real_T b_lambda[7];
  real_T c_x[10];
  real_T varargin_1[10];
  boolean_T exitg2;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /*   save INN */
  /*  clear */
  /*  load INN */
  /*  X0=X0*0 */
  /*    load INNN */
  /*   load  INN */
  /*  load INN */
  /*  % X0=0*X0; */
  /*  Tol=5e-9 */
  /*    load LINEWHAT */
  /* DO ALPHA, probably yeees? */
  /*  load LINEWHAT */
  /*  alpha=(tmax(1)-tmin(1))/2; % DO NOT BOTHER AT `THIS POINT TO DIFFERENTIATE BETWEEN DIFFERNT TMIN AND TMAX */
  st.site = &emlrtRSI;
  alphaP = alpha * alpha;
  *InfeasibleFlag = 0.0;

  /*  [MDIM,NACT]=size(Aeq); */
  /*  alphaS=1 */
  /*  X0=0*X0 */
  /*  if <0||>1 */
  /*     warning('Errorvlaue tan') */
  /*      a=asl */
  /*  end */
  /*  SqFac=1 */
  /*  =*SqFac; */
  /*  =0; */
  *LineIter = 0.0;

  /*  p=0.1; */
  /*  FACDIV=0.51; */
  /*  pFac=-2+(1+p^2)/(1.^(1-p)); */
  for (LimitExceed = 0; LimitExceed < 4; LimitExceed++) {
    AeqKappaMat[3 * LimitExceed] = Aeq[3 * LimitExceed];
    i = 1 + 3 * LimitExceed;
    AeqKappaMat[i] = Aeq[i];
    i = 2 + 3 * LimitExceed;
    AeqKappaMat[i] = Aeq[i];
  }

  for (LimitExceed = 0; LimitExceed < 3; LimitExceed++) {
    i = 3 * (LimitExceed + 4);
    AeqKappaMat[i] = Q[3 * LimitExceed];
    AeqKappaMat[1 + i] = Q[1 + 3 * LimitExceed];
    AeqKappaMat[2 + i] = Q[2 + 3 * LimitExceed];
  }

  /*  tau1=tau1/SCALING; */
  /*  tau2=tau2/SCALING; */
  /*  tol=1e-8; */
  for (i = 0; i < 7; i++) {
    w[i] = X0[i];
  }

  lambda[0] = X0[7];
  lambda[1] = X0[8];
  lambda[2] = X0[9];
  if (sum(*(real_T (*)[3])&X0[7]) == 0.0) {
    power(OptimalTension, dv0);
    Condition = mean(dv0);
    lambda[0] = 100.0 * Condition;
    lambda[1] = 100.0 * Condition;
    lambda[2] = 100.0 * Condition;

    /* HOW TO SCALE WITH FORCES? */
  }

  b_X0[0] = (X0[0] - (tmin[0] + 1.0E-5) < 0.0);
  b_X0[4] = ((tmax[0] - 1.0E-5) - X0[0] < 0.0);
  b_X0[1] = (X0[1] - (tmin[1] + 1.0E-5) < 0.0);
  b_X0[5] = ((tmax[1] - 1.0E-5) - X0[1] < 0.0);
  b_X0[2] = (X0[2] - (tmin[2] + 1.0E-5) < 0.0);
  b_X0[6] = ((tmax[2] - 1.0E-5) - X0[2] < 0.0);
  b_X0[3] = (X0[3] - (tmin[3] + 1.0E-5) < 0.0);
  b_X0[7] = ((tmax[3] - 1.0E-5) - X0[3] < 0.0);
  if (any(b_X0)) {
    /* LETS JUMP TO COLDSTART... */
    w[0] = OptimalTension[0];
    w[1] = OptimalTension[1];
    w[2] = OptimalTension[2];
    w[3] = OptimalTension[3];
    w[4] = 0.0;
    w[5] = 0.0;
    w[6] = 0.0;
    b_X0[0] = (OptimalTension[0] - (tmin[0] + 1.0E-5) < 0.0);
    b_X0[4] = ((tmax[0] - 1.0E-5) - OptimalTension[0] < 0.0);
    b_X0[1] = (OptimalTension[1] - (tmin[1] + 1.0E-5) < 0.0);
    b_X0[5] = ((tmax[1] - 1.0E-5) - OptimalTension[1] < 0.0);
    b_X0[2] = (OptimalTension[2] - (tmin[2] + 1.0E-5) < 0.0);
    b_X0[6] = ((tmax[2] - 1.0E-5) - OptimalTension[2] < 0.0);
    b_X0[3] = (OptimalTension[3] - (tmin[3] + 1.0E-5) < 0.0);
    b_X0[7] = ((tmax[3] - 1.0E-5) - OptimalTension[3] < 0.0);
    if (any(b_X0)) {
      /* LETS */
      w[0] = (tmin[0] + tmax[0]) / 2.0;
      w[1] = (tmin[1] + tmax[1]) / 2.0;
      w[2] = (tmin[2] + tmax[2]) / 2.0;
      w[3] = (tmin[3] + tmax[3]) / 2.0;
      w[4] = 0.0;
      w[5] = 0.0;
      w[6] = 0.0;
    }
  }

  /*   a=asl */
  /* SETTING UP DUMMY VARIABLES */
  ConditionOld = rtInf;
  Condition = rtInf;

  /*  beta=0.85; */
  *N_Iter = 0.0;

  /*  CostS=zeros(MDIM,1); */
  /*  dCostS=zeros(MDIM,1); */
  /*  ddCostS=zeros(MDIM,1); */
  /*  a=Asl */
  /*  lambda00=lambda */
  /*  s=[1;1;1]; */
  /*  w=[w;s]; */
  /* SQP ITERATIVE SOLVER. */
  /*  save  HERE */
  f[0] = w[0];
  f[1] = w[1];
  f[2] = w[2];
  f[3] = w[3];
  s[0] = w[4];
  s[1] = w[5];
  s[2] = w[6];

  /*  a=ASls */
  /*  SqFac=1/200; */
  /*  KappaMat(4:6,4:6)=eye(3)*1500; */
  /*   c_1=0; */
  /*  SqFac=1 */
  /*  a=Asl */
  /*  a=Asls */
  /*  Tol=1e-10 */
  while (Condition > Tol) {
    /*     A2= [[diag([2+tau2*1./(tmax-w).^2+tau1*1./(w-tmin).^2;2*ones(MDIM,1)])] AeqKappaMat';[AeqKappaMat zeros(MDIM,MDIM)]] */
    /*     T2=[AeqKappaMat zeros(MDIM,MDIM)] */
    /*     T3=[T1;T2]; */
    /*      A2= [[diag([2+tau2*1./(tmax-w).^2+tau1*1./(w-tmin).^2 2*ones(MDIM)])] AeqKappaMat';AeqKappaMat zeros(MDIM,MDIM)]; */
    /* SLACK FROM HERE */
    /*  dCostS=KappaMat.*(SqFac*2*s+c_1.*s./(epsilon+s.^2).^0.5;-sign(s).*.*(s.*atan(s)-0.5*log(s.^2+1))./(0.5*pi)); */
    st.site = &b_emlrtRSI;
    b_power(*(real_T (*)[3])&w[4], dCostS);
    dCostS[0] += epsilon;
    dCostS[1] += epsilon;
    dCostS[2] += epsilon;
    b_st.site = &i_emlrtRSI;
    z1[0] = muDoubleScalarPower(dCostS[0], 1.5);
    p = (dCostS[0] < 0.0);
    z1[1] = muDoubleScalarPower(dCostS[1], 1.5);
    if (p || (dCostS[1] < 0.0)) {
      p = true;
    } else {
      p = false;
    }

    z1[2] = muDoubleScalarPower(dCostS[2], 1.5);
    if (p || (dCostS[2] < 0.0)) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
        "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
    }

    /* -(sign(s).*.*(atan(s)/(0.5*pi)))); */
    Condition = SqFac * 2.0;
    b_power(*(real_T (*)[3])&w[4], dCostS);
    b_epsilon[0] = epsilon + dCostS[0];
    b_epsilon[1] = epsilon + dCostS[1];
    b_epsilon[2] = epsilon + dCostS[2];
    st.site = &c_emlrtRSI;
    c_power(&st, b_epsilon, dCostS);
    dCostS[0] = KappaMat[0] * (Condition * w[4] + w[4] / dCostS[0]);
    dCostS[1] = KappaMat[1] * (Condition * w[5] + w[5] / dCostS[1]);
    dCostS[2] = KappaMat[2] * (Condition * w[6] + w[6] / dCostS[2]);

    /* -sign(s).*.*(s.*atan(s)-0.5*log(s.^2+1))./(0.5*pi)); */
    /* INTERESTINGLY ENOUGH WE CAN DIFFER THE FORMULA BY PUTTING STUFF INSIDE THE ATAN THING.  */
    /*  SLACK COST. */
    /*   */
    /*    s2=s(S_2==1); */
    /*   CostS=S_1.*(s).^2+S_2.*abs(s).^(1+p); */
    /*   dCostS=2*s.*S_1; */
    /*   ddCostS=2*(S_1+S_3); */
    /*   dCostS(S_2==1)=s2*(1+p)./(abs(s2).^(1-p)); */
    /*   ddCostS(S_2==1)=(1+p^2)./(abs(s2).^(1-p));  */
    /*     CostS=s.^2+s.^4; */
    /*    dCostS=2*s+4*s.^3; */
    /*    ddCostS=2+12*s.^2; */
    A2_tmp[0] = tmax[0] - w[0];
    dLambda_idx_2 = w[0] - tmin[0];
    t = dLambda_idx_2;
    Condition = dLambda_idx_2 * dLambda_idx_2;
    A2_tmp[1] = tmax[1] - w[1];
    dLambda_idx_2 = w[1] - tmin[1];
    lambda0_idx_0 = dLambda_idx_2;
    dLambda_idx_0 = dLambda_idx_2 * dLambda_idx_2;
    A2_tmp[2] = tmax[2] - w[2];
    dLambda_idx_2 = w[2] - tmin[2];
    lambda0_idx_1 = dLambda_idx_2;
    dLambda_idx_1 = dLambda_idx_2 * dLambda_idx_2;
    A2_tmp[3] = tmax[3] - w[3];
    dLambda_idx_2 = w[3] - tmin[3];
    power(A2_tmp, dv1);
    w0[0] = (2.0 / alphaP + tau2 / dv1[0]) + tau1 / Condition;
    w0[1] = (2.0 / alphaP + tau2 / dv1[1]) + tau1 / dLambda_idx_0;
    w0[2] = (2.0 / alphaP + tau2 / dv1[2]) + tau1 / dLambda_idx_1;
    w0[3] = (2.0 / alphaP + tau2 / dv1[3]) + tau1 / (dLambda_idx_2 *
      dLambda_idx_2);
    w0[4] = KappaMat[0] * (SqFac * 2.0 + epsilon / z1[0]);
    w0[5] = KappaMat[1] * (SqFac * 2.0 + epsilon / z1[1]);
    w0[6] = KappaMat[2] * (SqFac * 2.0 + epsilon / z1[2]);
    memset(&d[0], 0, 49U * sizeof(real_T));
    for (i = 0; i < 7; i++) {
      d[i + 7 * i] = w0[i];
    }

    /*      B2= [-[2*(w-OptimalTension)+tau2*1./(tmax-w) -  tau1*1./(w-tmin)];2*Q ; -[AeqKappaMat*w-WTarget]]; */
    Condition = 2.0 / alphaP;
    for (LimitExceed = 0; LimitExceed < 3; LimitExceed++) {
      d0 = 0.0;
      for (i = 0; i < 7; i++) {
        d0 += AeqKappaMat[LimitExceed + 3 * i] * w[i];
      }

      z1[LimitExceed] = -(d0 - WTarget[LimitExceed]);
    }

    x[0] = -((Condition * (w[0] - OptimalTension[0]) + tau2 / A2_tmp[0]) - tau1 /
             t);
    x[1] = -((Condition * (w[1] - OptimalTension[1]) + tau2 / A2_tmp[1]) - tau1 /
             lambda0_idx_0);
    x[2] = -((Condition * (w[2] - OptimalTension[2]) + tau2 / A2_tmp[2]) - tau1 /
             lambda0_idx_1);
    x[3] = -((Condition * (w[3] - OptimalTension[3]) + tau2 / A2_tmp[3]) - tau1 /
             dLambda_idx_2);
    x[4] = -dCostS[0];
    x[7] = z1[0];
    x[5] = -dCostS[1];
    x[8] = z1[1];
    x[6] = -dCostS[2];
    x[9] = z1[2];
    for (LimitExceed = 0; LimitExceed < 7; LimitExceed++) {
      for (i = 0; i < 7; i++) {
        b_d[i + 10 * LimitExceed] = d[i + 7 * LimitExceed];
      }
    }

    for (LimitExceed = 0; LimitExceed < 3; LimitExceed++) {
      for (i = 0; i < 7; i++) {
        b_d[i + 10 * (LimitExceed + 7)] = AeqKappaMat[LimitExceed + 3 * i];
      }
    }

    for (LimitExceed = 0; LimitExceed < 7; LimitExceed++) {
      b_d[10 * LimitExceed + 7] = AeqKappaMat[3 * LimitExceed];
      b_d[10 * LimitExceed + 8] = AeqKappaMat[1 + 3 * LimitExceed];
      b_d[10 * LimitExceed + 9] = AeqKappaMat[2 + 3 * LimitExceed];
    }

    for (LimitExceed = 0; LimitExceed < 3; LimitExceed++) {
      i = 10 * (LimitExceed + 7);
      b_d[i + 7] = 0.0;
      b_d[i + 8] = 0.0;
      b_d[i + 9] = 0.0;
    }

    st.site = &d_emlrtRSI;
    mldivide(&st, b_d, x);
    dLambda_idx_0 = x[7] - lambda[0];
    dLambda_idx_1 = x[8] - lambda[1];
    dLambda_idx_2 = x[9] - lambda[2];
    t = 1.0;
    (*N_Iter)++;
    for (LimitExceed = 0; LimitExceed < 7; LimitExceed++) {
      w[LimitExceed] += x[LimitExceed];
    }

    lambda[0] += dLambda_idx_0;
    lambda[1] += dLambda_idx_1;
    lambda[2] += dLambda_idx_2;
    for (i = 0; i < 7; i++) {
      w0[i] = w[i];
    }

    lambda0_idx_0 = lambda[0];
    lambda0_idx_1 = lambda[1];
    lambda0_idx_2 = lambda[2];
    f[0] = w[0];
    f[1] = w[1];
    f[2] = w[2];
    f[3] = w[3];
    s[0] = w[4];
    s[1] = w[5];
    s[2] = w[6];

    /* A SOMEWHAT SIMPLISTIC LINE SEARCH IMPLEMENTATION */
    b_x[0] = (w[0] - tmin[0] < 0.0);
    b_x[4] = (tmax[0] - w[0] < 0.0);
    b_x[1] = (w[1] - tmin[1] < 0.0);
    b_x[5] = (tmax[1] - w[1] < 0.0);
    b_x[2] = (w[2] - tmin[2] < 0.0);
    b_x[6] = (tmax[2] - w[2] < 0.0);
    b_x[3] = (w[3] - tmin[3] < 0.0);
    b_x[7] = (tmax[3] - w[3] < 0.0);
    p = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (b_x[k]) {
        p = true;
        exitg1 = true;
      } else {
        k++;
      }
    }

    LimitExceed = p;

    /*        a=ASl */
    while (LimitExceed == 1) {
      t *= 0.96;
      for (i = 0; i < 7; i++) {
        w[i] = w0[i] - (1.0 - t) * x[i];
      }

      lambda[0] = lambda0_idx_0 - (1.0 - t) * dLambda_idx_0;
      s[0] = w[4];
      lambda[1] = lambda0_idx_1 - (1.0 - t) * dLambda_idx_1;
      s[1] = w[5];
      lambda[2] = lambda0_idx_2 - (1.0 - t) * dLambda_idx_2;
      s[2] = w[6];
      f[0] = w[0];
      b_x[0] = (w[0] - tmin[0] < 0.0);
      b_x[4] = (tmax[0] - w[0] < 0.0);
      f[1] = w[1];
      b_x[1] = (w[1] - tmin[1] < 0.0);
      b_x[5] = (tmax[1] - w[1] < 0.0);
      f[2] = w[2];
      b_x[2] = (w[2] - tmin[2] < 0.0);
      b_x[6] = (tmax[2] - w[2] < 0.0);
      f[3] = w[3];
      b_x[3] = (w[3] - tmin[3] < 0.0);
      b_x[7] = (tmax[3] - w[3] < 0.0);
      p = false;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 8)) {
        if (b_x[k]) {
          p = true;
          exitg1 = true;
        } else {
          k++;
        }
      }

      if (!p) {
        LimitExceed = 0;
        t *= 0.99;

        /* JUST ANOTHER JERK IT A LITTLE AWAY FROM THE LIMIT. */
        for (i = 0; i < 7; i++) {
          w[i] = w0[i] - (1.0 - t) * x[i];
        }

        lambda[0] = lambda0_idx_0 - (1.0 - t) * dLambda_idx_0;
        s[0] = w[4];
        lambda[1] = lambda0_idx_1 - (1.0 - t) * dLambda_idx_1;
        s[1] = w[5];
        lambda[2] = lambda0_idx_2 - (1.0 - t) * dLambda_idx_2;
        s[2] = w[6];
        f[0] = w[0];
        f[1] = w[1];
        f[2] = w[2];
        f[3] = w[3];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*      */
    /*   S_1=(s<1).*(s>-1).*(s~=0); */
    /*   S_3=(s==0); */
    /*   S_2=ones(MDIM,1)-S_1-S_3; */
    /*   CostS=S_1.*(s).^2+S_2.*abs(s); */
    /*   dCostS=2*s.*S_1+s.*sign(S_2); */
    /*   ddCostS=2*(S_1+S_3); */
    /*   */
    /*    s2=s(S_2==1); */
    /*   CostS=S_1.*(s).^2+S_2.*abs(s).^(1+p); */
    /*   dCostS=2*s.*S_1; */
    /*   ddCostS=2*(S_1+S_3); */
    /*   dCostS(S_2==1)=s2*(1+p)./(abs(s2).^(1-p)); */
    /*   ddCostS(S_2==1)=(1+p^2)./(abs(s2).^(1-p)); */
    /*   */
    /*   CostS=s.^2+s.^4; */
    /*    dCostS=2*s+4*s.^3; */
    /*    ddCostS=2+12*s.^2; */
    Condition = SqFac * 2.0;
    z1[0] = epsilon + s[0] * s[0];
    z1[1] = epsilon + s[1] * s[1];
    z1[2] = epsilon + s[2] * s[2];
    st.site = &e_emlrtRSI;
    c_power(&st, z1, dCostS);
    dCostS[0] = KappaMat[0] * (Condition * s[0] + s[0] / dCostS[0]);
    dCostS[1] = KappaMat[1] * (Condition * s[1] + s[1] / dCostS[1]);
    dCostS[2] = KappaMat[2] * (Condition * s[2] + s[2] / dCostS[2]);

    /* -sign(s).*.*(s.*atan(s)-0.5*log(s.^2+1))./(0.5*pi)); */
    /*  a=Asl */
    /*   ConditionLog(N_Iter)=Condition */
    /*   LineIterLog(N_Iter)=LineIter; */
    Condition = 2.0 / alphaP;
    for (LimitExceed = 0; LimitExceed < 7; LimitExceed++) {
      b_lambda[LimitExceed] = (lambda[0] * AeqKappaMat[3 * LimitExceed] +
        lambda[1] * AeqKappaMat[1 + 3 * LimitExceed]) + lambda[2] * AeqKappaMat
        [2 + 3 * LimitExceed];
    }

    a[0] = (Condition * (f[0] - OptimalTension[0]) + tau2 / (tmax[0] - f[0])) -
      tau1 / (f[0] - tmin[0]);
    a[1] = (Condition * (f[1] - OptimalTension[1]) + tau2 / (tmax[1] - f[1])) -
      tau1 / (f[1] - tmin[1]);
    a[2] = (Condition * (f[2] - OptimalTension[2]) + tau2 / (tmax[2] - f[2])) -
      tau1 / (f[2] - tmin[2]);
    a[3] = (Condition * (f[3] - OptimalTension[3]) + tau2 / (tmax[3] - f[3])) -
      tau1 / (f[3] - tmin[3]);
    for (LimitExceed = 0; LimitExceed < 3; LimitExceed++) {
      a[LimitExceed + 4] = dCostS[LimitExceed];
      d0 = 0.0;
      for (i = 0; i < 7; i++) {
        d0 += AeqKappaMat[LimitExceed + 3 * i] * w[i];
      }

      z1[LimitExceed] = d0 - WTarget[LimitExceed];
    }

    for (LimitExceed = 0; LimitExceed < 7; LimitExceed++) {
      c_x[LimitExceed] = a[LimitExceed] + b_lambda[LimitExceed];
    }

    c_x[7] = z1[0];
    c_x[8] = z1[1];
    c_x[9] = z1[2];
    for (k = 0; k < 10; k++) {
      varargin_1[k] = muDoubleScalarAbs(c_x[k]);
    }

    st.site = &f_emlrtRSI;
    if (!muDoubleScalarIsNaN(varargin_1[0])) {
      i = 1;
    } else {
      i = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 11)) {
        if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
          i = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (i == 0) {
      Condition = varargin_1[0];
    } else {
      Condition = varargin_1[i - 1];
      LimitExceed = i + 1;
      for (k = LimitExceed; k < 11; k++) {
        d0 = varargin_1[k - 1];
        if (Condition < d0) {
          Condition = d0;
        }
      }
    }

    /*  if N_Iter==2 */
    /*       a=asl */
    /*  end */
    /*      ConditionLOG(N_Iter)=Condition; */
    exitg1 = false;
    while ((!exitg1) && (ConditionOld < Condition)) {
      t *= 0.85;
      for (i = 0; i < 7; i++) {
        w[i] = w0[i] - (1.0 - t) * x[i];
      }

      lambda[0] = lambda0_idx_0 - (1.0 - t) * dLambda_idx_0;
      lambda[1] = lambda0_idx_1 - (1.0 - t) * dLambda_idx_1;
      lambda[2] = lambda0_idx_2 - (1.0 - t) * dLambda_idx_2;
      f[0] = w[0];
      f[1] = w[1];
      f[2] = w[2];
      f[3] = w[3];
      (*LineIter)++;
      Condition = SqFac * 2.0;
      s[0] = w[4];
      z1[0] = epsilon + w[4] * w[4];
      s[1] = w[5];
      z1[1] = epsilon + w[5] * w[5];
      s[2] = w[6];
      z1[2] = epsilon + w[6] * w[6];
      st.site = &g_emlrtRSI;
      c_power(&st, z1, dCostS);
      dCostS[0] = KappaMat[0] * (Condition * w[4] + w[4] / dCostS[0]);
      dCostS[1] = KappaMat[1] * (Condition * w[5] + w[5] / dCostS[1]);
      dCostS[2] = KappaMat[2] * (Condition * w[6] + w[6] / dCostS[2]);

      /* -sign(s).*.*(s.*atan(s)-0.5*log(s.^2+1))./(0.5*pi)); */
      Condition = 2.0 / alphaP;
      for (LimitExceed = 0; LimitExceed < 7; LimitExceed++) {
        b_lambda[LimitExceed] = (lambda[0] * AeqKappaMat[3 * LimitExceed] +
          lambda[1] * AeqKappaMat[1 + 3 * LimitExceed]) + lambda[2] *
          AeqKappaMat[2 + 3 * LimitExceed];
      }

      a[0] = (Condition * (w[0] - OptimalTension[0]) + tau2 / (tmax[0] - w[0]))
        - tau1 / (w[0] - tmin[0]);
      a[1] = (Condition * (w[1] - OptimalTension[1]) + tau2 / (tmax[1] - w[1]))
        - tau1 / (w[1] - tmin[1]);
      a[2] = (Condition * (w[2] - OptimalTension[2]) + tau2 / (tmax[2] - w[2]))
        - tau1 / (w[2] - tmin[2]);
      a[3] = (Condition * (w[3] - OptimalTension[3]) + tau2 / (tmax[3] - w[3]))
        - tau1 / (w[3] - tmin[3]);
      for (LimitExceed = 0; LimitExceed < 3; LimitExceed++) {
        a[LimitExceed + 4] = dCostS[LimitExceed];
        d0 = 0.0;
        for (i = 0; i < 7; i++) {
          d0 += AeqKappaMat[LimitExceed + 3 * i] * w[i];
        }

        z1[LimitExceed] = d0 - WTarget[LimitExceed];
      }

      for (LimitExceed = 0; LimitExceed < 7; LimitExceed++) {
        c_x[LimitExceed] = a[LimitExceed] + b_lambda[LimitExceed];
      }

      c_x[7] = z1[0];
      c_x[8] = z1[1];
      c_x[9] = z1[2];
      for (k = 0; k < 10; k++) {
        varargin_1[k] = muDoubleScalarAbs(c_x[k]);
      }

      st.site = &h_emlrtRSI;
      if (!muDoubleScalarIsNaN(varargin_1[0])) {
        i = 1;
      } else {
        i = 0;
        k = 2;
        exitg2 = false;
        while ((!exitg2) && (k < 11)) {
          if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
            i = k;
            exitg2 = true;
          } else {
            k++;
          }
        }
      }

      if (i == 0) {
        Condition = varargin_1[0];
      } else {
        Condition = varargin_1[i - 1];
        LimitExceed = i + 1;
        for (k = LimitExceed; k < 11; k++) {
          d0 = varargin_1[k - 1];
          if (Condition < d0) {
            Condition = d0;
          }
        }
      }

      /*          X(N_Iter)=Condition;     */
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }

      if (t < 1.0E-8) {
        *InfeasibleFlag = 1.0;

        /*                  save AQ */
        /*                  a=asl */
        Condition = -1.0;
        exitg1 = true;
      }
    }

    ConditionOld = Condition;
    if (*N_Iter > IterMax) {
      *InfeasibleFlag = 2.0;
      Condition = -1.0;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  load AQ */
  /*  a=asl */
  /*  DerS=KappaMat.*(SqFac*2*s+c_1.*s./(epsilon+s.^2).^0.5);%-sign(s).*.*(s.*atan(s)-0.5*log(s.^2+1))./(0.5*pi)); */
  /*  DerF=2./alphaP*(f-OptimalTension)+tau2*1./(tmax-f)-tau1*1./(f-tmin) */
  /*  DerS'*Aeq-DerF' */
  /*  DerF'*pinv(Aeq)-DerS' */
  /*  pinv(Aeq)'*DerF-DerS */
  /*   */
  /*  Aeq*pinv(Aeq)*zeros(6,1) */
  /*   */
  /*  V=sum(abs(DerF'*pinv(Aeq)-DerS'))+sum(abs(pinv(Aeq)'*DerF-DerS)) */
  /*  save AQ2 */
  /*  load AQ2 */
  /*   */
  /*   */
  /*  [lambda'*AeqKappaMat]' */
  /*   */
  /*  AeqKappaMat'*lambda-[lambda'*AeqKappaMat]' */
  /*   */
  /*   */
  /*  % a=Asl */
  /*  a=asl */
  /*  if InfeasibleFlag==1||InfeasibleFlag==2 */
  /*  end */
  /*  N_Iter */
  /*  if N_Iter==50 */
  /*  %     a=asl */
  /*  X0(end-MDIM+1:end)-lambda */
  /*  end */
  /*  (X0(1:NACT+MDIM)-w) */
  /*  lambda-lambda00 */
  /*  % */
  /*  Aeq*f-(WTarget-s) */
  /*  % */
  /*  %WERR=S is correctomundo..  */
  /*  N_Iter */
  /*   */
  /*   */
  /*  N_Iter=N_Iter */
  /*  LineIter=LineIter+1 */
  /*  % if N_Iter==42 */
  /*      save OUT */
  /*      close all */
  /*      plot(ConditionLog) */
  /*      A=Asl */
  /*  end */
}

/* End of code generation (Newton_Slack.c) */
