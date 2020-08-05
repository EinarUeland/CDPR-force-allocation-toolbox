/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Newton_SlackAnyP.c
 *
 * Code generation for function 'Newton_SlackAnyP'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Newton_SlackAnyP.h"
#include "any.h"
#include "abs.h"
#include "power.h"
#include "mldivide.h"
#include "diag.h"
#include "Newton_SlackAnyP_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 83,    /* lineNo */
  "Newton_SlackAnyP",                  /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_SlackAnyP.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 84,  /* lineNo */
  "Newton_SlackAnyP",                  /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_SlackAnyP.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 104, /* lineNo */
  "Newton_SlackAnyP",                  /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_SlackAnyP.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 105, /* lineNo */
  "Newton_SlackAnyP",                  /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_SlackAnyP.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 108, /* lineNo */
  "Newton_SlackAnyP",                  /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_SlackAnyP.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 157, /* lineNo */
  "Newton_SlackAnyP",                  /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_SlackAnyP.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 160, /* lineNo */
  "Newton_SlackAnyP",                  /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_SlackAnyP.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 171, /* lineNo */
  "Newton_SlackAnyP",                  /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_SlackAnyP.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 173, /* lineNo */
  "Newton_SlackAnyP",                  /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_SlackAnyP.m"/* pathName */
};

/* Function Definitions */
void Newton_SlackAnyP(const emlrtStack *sp, const real_T X0[10], const real_T
                      Aeq[12], const real_T WTarget[3], const real_T tmin[4],
                      const real_T tmax[4], real_T tau1, real_T tau2, const
                      real_T OptimalTension[4], real_T Tol, real_T IterMax,
                      const real_T KappaMat[3], const real_T Q[9], real_T
                      epsilon, real_T SqFac, real_T P, real_T alpha, real_T f[4],
                      real_T s[3], real_T lambda[3], real_T *N_Iter, real_T
                      *InfeasibleFlag, real_T *LineIter)
{
  int32_T i0;
  real_T AeqKappaMat[21];
  int32_T i;
  real_T w[7];
  boolean_T b_X0[8];
  real_T ConditionOld;
  real_T Condition;
  real_T dCostS[3];
  real_T dLambda_idx_0;
  boolean_T p;
  real_T dLambda_idx_1;
  real_T dLambda_idx_2;
  real_T a;
  real_T b_epsilon[3];
  real_T dv0[4];
  real_T A2_tmp[4];
  real_T b_A2_tmp[4];
  real_T dv1[4];
  real_T b[4];
  real_T y_tmp;
  real_T dv2[4];
  real_T B2[10];
  real_T d0;
  real_T b_a[7];
  real_T dv3[49];
  real_T dv4[100];
  real_T t;
  real_T lambda0_idx_0;
  real_T w0[7];
  real_T lambda0_idx_1;
  real_T lambda0_idx_2;
  int32_T LimitExceed;
  real_T dv5[4];
  real_T b_lambda[7];
  real_T b_P[10];
  real_T varargin_1[10];
  boolean_T exitg1;
  real_T dv6[4];
  boolean_T exitg2;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /*     load LINEWHAT */
  /* DO ALPHA, probably yeees? */
  /*  load LINEWHAT */
  /*  alpha=(tmax(1)-tmin(1))/2; % DO NOT BOTHER AT `THIS POINT TO DIFFERENTIATE BETWEEN DIFFERNT TMIN AND TMAX */
  /*  alphaP=alpha.^2; */
  *InfeasibleFlag = 0.0;

  /*  [MDIM,NACT]=size(Aeq); */
  /*  alphaS=1 */
  /*  X0=0*X0 */
  /*  if TANFAC<0||TANFAC>1 */
  /*     warning('Errorvlaue tan') */
  /*      a=asl */
  /*  end */
  /*  SqFac=1 */
  /*  TANFAC=TANFAC*SqFac; */
  /*  TANFAC=0; */
  *LineIter = 0.0;

  /*  p=0.1; */
  /*  FACDIV=0.51; */
  /*  pFac=-2+(1+p^2)/(1.^(1-p)); */
  /* QDMIN=size(Q,2) */
  for (i0 = 0; i0 < 4; i0++) {
    AeqKappaMat[3 * i0] = Aeq[3 * i0];
    i = 1 + 3 * i0;
    AeqKappaMat[i] = Aeq[i];
    i = 2 + 3 * i0;
    AeqKappaMat[i] = Aeq[i];
  }

  for (i0 = 0; i0 < 3; i0++) {
    i = 3 * (i0 + 4);
    AeqKappaMat[i] = Q[3 * i0];
    AeqKappaMat[1 + i] = Q[1 + 3 * i0];
    AeqKappaMat[2 + i] = Q[2 + 3 * i0];
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

  /*   c_1=0; */
  /*  SqFac=1 */
  /*  Tol=1e-10 */
  while (Condition > Tol) {
    /*     A2= [[diag([2+tau2*1./(tmax-w).^2+tau1*1./(w-tmin).^2;2*ones(MDIM,1)])] AeqKappaMat';[AeqKappaMat zeros(MDIM,MDIM)]] */
    /*     T2=[AeqKappaMat zeros(MDIM,MDIM)] */
    /*     T3=[T1;T2]; */
    /*      A2= [[diag([2+tau2*1./(tmax-w).^2+tau1*1./(w-tmin).^2 2*ones(MDIM)])] AeqKappaMat';AeqKappaMat zeros(MDIM,MDIM)]; */
    /* SLACK FROM HERE */
    /*  dCostS=KappaMat.*(SqFac*2*s+c_1.*s./(epsilon+s.^2).^0.5;-sign(s).*TANFAC.*(s.*atan(s)-0.5*log(s.^2+1))./(0.5*pi)); */
    st.site = &emlrtRSI;
    power(*(real_T (*)[3])&w[4], dCostS);
    dCostS[0] += epsilon;
    dCostS[1] += epsilon;
    dCostS[2] += epsilon;
    b_st.site = &j_emlrtRSI;
    dLambda_idx_0 = muDoubleScalarPower(dCostS[0], 1.5);
    p = (dCostS[0] < 0.0);
    dLambda_idx_1 = muDoubleScalarPower(dCostS[1], 1.5);
    if (p || (dCostS[1] < 0.0)) {
      p = true;
    } else {
      p = false;
    }

    dLambda_idx_2 = muDoubleScalarPower(dCostS[2], 1.5);
    if (p || (dCostS[2] < 0.0)) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
        "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
    }

    /* -(sign(s).*TANFAC.*(atan(s)/(0.5*pi)))); */
    a = SqFac * 2.0;
    power(*(real_T (*)[3])&w[4], dCostS);
    b_epsilon[0] = epsilon + dCostS[0];
    b_epsilon[1] = epsilon + dCostS[1];
    b_epsilon[2] = epsilon + dCostS[2];
    st.site = &b_emlrtRSI;
    b_power(&st, b_epsilon, dCostS);
    dCostS[0] = KappaMat[0] * (a * w[4] + w[4] / dCostS[0]);
    dCostS[1] = KappaMat[1] * (a * w[5] + w[5] / dCostS[1]);
    dCostS[2] = KappaMat[2] * (a * w[6] + w[6] / dCostS[2]);

    /* -sign(s).*TANFAC.*(s.*atan(s)-0.5*log(s.^2+1))./(0.5*pi)); */
    /* INTERESTINGLY ENOUGH WE CAN DIFFER THE FORMULA BY PUTTING STUFF INSIDE THE ATAN THING.  */
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
    dv0[0] = w[0] - OptimalTension[0];
    A2_tmp[0] = tmax[0] - w[0];
    b_A2_tmp[0] = w[0] - tmin[0];
    dv0[1] = w[1] - OptimalTension[1];
    A2_tmp[1] = tmax[1] - w[1];
    b_A2_tmp[1] = w[1] - tmin[1];
    dv0[2] = w[2] - OptimalTension[2];
    A2_tmp[2] = tmax[2] - w[2];
    b_A2_tmp[2] = w[2] - tmin[2];
    dv0[3] = w[3] - OptimalTension[3];
    A2_tmp[3] = tmax[3] - w[3];
    b_A2_tmp[3] = w[3] - tmin[3];
    b_abs(dv0, dv1);
    a = P * (P - 1.0);
    st.site = &c_emlrtRSI;
    c_power(&st, dv1, P - 2.0, b);
    st.site = &c_emlrtRSI;
    b_st.site = &j_emlrtRSI;
    y_tmp = muDoubleScalarPower(alpha, P);
    if ((alpha < 0.0) && (!muDoubleScalarIsNaN(P)) && (muDoubleScalarFloor(P) !=
         P)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
        "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
    }

    st.site = &d_emlrtRSI;
    b_st.site = &j_emlrtRSI;
    if ((alpha < 0.0) && (!muDoubleScalarIsNaN(P)) && (muDoubleScalarFloor(P) !=
         P)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
        "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
    }

    st.site = &d_emlrtRSI;
    c_power(&st, dv1, P - 2.0, dv2);
    for (i0 = 0; i0 < 3; i0++) {
      d0 = 0.0;
      for (i = 0; i < 7; i++) {
        d0 += AeqKappaMat[i0 + 3 * i] * w[i];
      }

      b_epsilon[i0] = -(d0 - WTarget[i0]);
    }

    B2[0] = -((P * dv0[0] * dv2[0] / y_tmp + tau2 / A2_tmp[0]) - tau1 /
              b_A2_tmp[0]);
    B2[1] = -((P * dv0[1] * dv2[1] / y_tmp + tau2 / A2_tmp[1]) - tau1 /
              b_A2_tmp[1]);
    B2[2] = -((P * dv0[2] * dv2[2] / y_tmp + tau2 / A2_tmp[2]) - tau1 /
              b_A2_tmp[2]);
    B2[3] = -((P * dv0[3] * dv2[3] / y_tmp + tau2 / A2_tmp[3]) - tau1 /
              b_A2_tmp[3]);
    B2[4] = -dCostS[0];
    B2[7] = b_epsilon[0];
    B2[5] = -dCostS[1];
    B2[8] = b_epsilon[1];
    B2[6] = -dCostS[2];
    B2[9] = b_epsilon[2];

    /*      B2= [-[2*(w-OptimalTension)+tau2*1./(tmax-w) -  tau1*1./(w-tmin)];2*eye(MDIM) ; -[AeqKappaMat*w-WTarget]]; */
    /*      B2= [-[P.*(f-OptimalTension).*(abs(f-OptimalTension)).^(P-2)./alpha.^P + tau2*1./(tmax-f) -  tau1*1./(f-tmin)];-dCostS ; -[AeqKappaMat*[w]-WTarget]]; */
    d_power(A2_tmp, dv0);
    d_power(b_A2_tmp, dv1);
    Condition = SqFac * 2.0;
    b_a[0] = a * b[0] / y_tmp + (tau2 / dv0[0] + tau1 / dv1[0]);
    b_a[1] = a * b[1] / y_tmp + (tau2 / dv0[1] + tau1 / dv1[1]);
    b_a[2] = a * b[2] / y_tmp + (tau2 / dv0[2] + tau1 / dv1[2]);
    b_a[3] = a * b[3] / y_tmp + (tau2 / dv0[3] + tau1 / dv1[3]);
    b_a[4] = KappaMat[0] * (Condition + epsilon / dLambda_idx_0);
    b_a[5] = KappaMat[1] * (Condition + epsilon / dLambda_idx_1);
    b_a[6] = KappaMat[2] * (Condition + epsilon / dLambda_idx_2);
    diag(b_a, dv3);
    for (i0 = 0; i0 < 7; i0++) {
      for (i = 0; i < 7; i++) {
        dv4[i + 10 * i0] = dv3[i + 7 * i0];
      }
    }

    for (i0 = 0; i0 < 3; i0++) {
      for (i = 0; i < 7; i++) {
        dv4[i + 10 * (i0 + 7)] = AeqKappaMat[i0 + 3 * i];
      }
    }

    for (i0 = 0; i0 < 7; i0++) {
      dv4[10 * i0 + 7] = AeqKappaMat[3 * i0];
      dv4[10 * i0 + 8] = AeqKappaMat[1 + 3 * i0];
      dv4[10 * i0 + 9] = AeqKappaMat[2 + 3 * i0];
    }

    for (i0 = 0; i0 < 3; i0++) {
      i = 10 * (i0 + 7);
      dv4[i + 7] = 0.0;
      dv4[i + 8] = 0.0;
      dv4[i + 9] = 0.0;
    }

    st.site = &e_emlrtRSI;
    mldivide(&st, dv4, B2);
    dLambda_idx_0 = B2[7] - lambda[0];
    dLambda_idx_1 = B2[8] - lambda[1];
    dLambda_idx_2 = B2[9] - lambda[2];
    t = 1.0;
    (*N_Iter)++;
    for (i0 = 0; i0 < 7; i0++) {
      w[i0] += B2[i0];
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
    b_X0[0] = (w[0] - tmin[0] < 0.0);
    b_X0[4] = (tmax[0] - w[0] < 0.0);
    b_X0[1] = (w[1] - tmin[1] < 0.0);
    b_X0[5] = (tmax[1] - w[1] < 0.0);
    b_X0[2] = (w[2] - tmin[2] < 0.0);
    b_X0[6] = (tmax[2] - w[2] < 0.0);
    b_X0[3] = (w[3] - tmin[3] < 0.0);
    b_X0[7] = (tmax[3] - w[3] < 0.0);
    LimitExceed = any(b_X0);
    while (LimitExceed == 1) {
      t *= 0.85;
      for (i = 0; i < 7; i++) {
        w[i] = w0[i] - (1.0 - t) * B2[i];
      }

      lambda[0] = lambda0_idx_0 - (1.0 - t) * dLambda_idx_0;
      s[0] = w[4];
      lambda[1] = lambda0_idx_1 - (1.0 - t) * dLambda_idx_1;
      s[1] = w[5];
      lambda[2] = lambda0_idx_2 - (1.0 - t) * dLambda_idx_2;
      s[2] = w[6];
      f[0] = w[0];
      b_X0[0] = (w[0] - tmin[0] < 0.0);
      b_X0[4] = (tmax[0] - w[0] < 0.0);
      f[1] = w[1];
      b_X0[1] = (w[1] - tmin[1] < 0.0);
      b_X0[5] = (tmax[1] - w[1] < 0.0);
      f[2] = w[2];
      b_X0[2] = (w[2] - tmin[2] < 0.0);
      b_X0[6] = (tmax[2] - w[2] < 0.0);
      f[3] = w[3];
      b_X0[3] = (w[3] - tmin[3] < 0.0);
      b_X0[7] = (tmax[3] - w[3] < 0.0);
      if (!any(b_X0)) {
        LimitExceed = 0;
        t *= 0.98;

        /* JUST JERK IT A LITTLE AWAY FROM THE EDGE. */
        for (i = 0; i < 7; i++) {
          w[i] = w0[i] - (1.0 - t) * B2[i];
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
    a = SqFac * 2.0;
    power(s, dCostS);
    b_epsilon[0] = epsilon + dCostS[0];
    b_epsilon[1] = epsilon + dCostS[1];
    b_epsilon[2] = epsilon + dCostS[2];
    st.site = &f_emlrtRSI;
    b_power(&st, b_epsilon, dCostS);
    dCostS[0] = KappaMat[0] * (a * s[0] + s[0] / dCostS[0]);
    dCostS[1] = KappaMat[1] * (a * s[1] + s[1] / dCostS[1]);
    dCostS[2] = KappaMat[2] * (a * s[2] + s[2] / dCostS[2]);

    /* -sign(s).*TANFAC.*(s.*atan(s)-0.5*log(s.^2+1))./(0.5*pi)); */
    /*  a=Asl */
    dv0[0] = f[0] - OptimalTension[0];
    dv0[1] = f[1] - OptimalTension[1];
    dv0[2] = f[2] - OptimalTension[2];
    dv0[3] = f[3] - OptimalTension[3];
    st.site = &g_emlrtRSI;
    b_st.site = &j_emlrtRSI;
    if ((alpha < 0.0) && (!muDoubleScalarIsNaN(P)) && (muDoubleScalarFloor(P) !=
         P)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
        "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
    }

    b_abs(dv0, dv5);
    st.site = &g_emlrtRSI;
    c_power(&st, dv5, P - 2.0, dv2);
    for (i0 = 0; i0 < 7; i0++) {
      b_lambda[i0] = (lambda[0] * AeqKappaMat[3 * i0] + lambda[1] * AeqKappaMat
                      [1 + 3 * i0]) + lambda[2] * AeqKappaMat[2 + 3 * i0];
    }

    b_a[0] = (P * dv0[0] / y_tmp * dv2[0] + tau2 / (tmax[0] - f[0])) - tau1 /
      (f[0] - tmin[0]);
    b_a[1] = (P * dv0[1] / y_tmp * dv2[1] + tau2 / (tmax[1] - f[1])) - tau1 /
      (f[1] - tmin[1]);
    b_a[2] = (P * dv0[2] / y_tmp * dv2[2] + tau2 / (tmax[2] - f[2])) - tau1 /
      (f[2] - tmin[2]);
    b_a[3] = (P * dv0[3] / y_tmp * dv2[3] + tau2 / (tmax[3] - f[3])) - tau1 /
      (f[3] - tmin[3]);
    for (i0 = 0; i0 < 3; i0++) {
      b_a[i0 + 4] = dCostS[i0];
      d0 = 0.0;
      for (i = 0; i < 7; i++) {
        d0 += AeqKappaMat[i0 + 3 * i] * w[i];
      }

      b_epsilon[i0] = d0 - WTarget[i0];
    }

    for (i0 = 0; i0 < 7; i0++) {
      b_P[i0] = b_a[i0] + b_lambda[i0];
    }

    b_P[7] = b_epsilon[0];
    b_P[8] = b_epsilon[1];
    b_P[9] = b_epsilon[2];
    c_abs(b_P, varargin_1);
    st.site = &g_emlrtRSI;
    if (!muDoubleScalarIsNaN(varargin_1[0])) {
      i = 1;
    } else {
      i = 0;
      LimitExceed = 2;
      exitg1 = false;
      while ((!exitg1) && (LimitExceed < 11)) {
        if (!muDoubleScalarIsNaN(varargin_1[LimitExceed - 1])) {
          i = LimitExceed;
          exitg1 = true;
        } else {
          LimitExceed++;
        }
      }
    }

    if (i == 0) {
      Condition = varargin_1[0];
    } else {
      Condition = varargin_1[i - 1];
      i0 = i + 1;
      for (LimitExceed = i0; LimitExceed < 11; LimitExceed++) {
        d0 = varargin_1[LimitExceed - 1];
        if (Condition < d0) {
          Condition = d0;
        }
      }
    }

    exitg1 = false;
    while ((!exitg1) && (ConditionOld < Condition)) {
      t *= 0.85;
      for (i = 0; i < 7; i++) {
        w[i] = w0[i] - (1.0 - t) * B2[i];
      }

      lambda[0] = lambda0_idx_0 - (1.0 - t) * dLambda_idx_0;
      lambda[1] = lambda0_idx_1 - (1.0 - t) * dLambda_idx_1;
      lambda[2] = lambda0_idx_2 - (1.0 - t) * dLambda_idx_2;
      f[0] = w[0];
      f[1] = w[1];
      f[2] = w[2];
      f[3] = w[3];
      (*LineIter)++;
      a = SqFac * 2.0;
      power(*(real_T (*)[3])&w[4], dCostS);
      s[0] = w[4];
      b_epsilon[0] = epsilon + dCostS[0];
      s[1] = w[5];
      b_epsilon[1] = epsilon + dCostS[1];
      s[2] = w[6];
      b_epsilon[2] = epsilon + dCostS[2];
      st.site = &h_emlrtRSI;
      b_power(&st, b_epsilon, dCostS);
      dCostS[0] = KappaMat[0] * (a * w[4] + w[4] / dCostS[0]);
      dCostS[1] = KappaMat[1] * (a * w[5] + w[5] / dCostS[1]);
      dCostS[2] = KappaMat[2] * (a * w[6] + w[6] / dCostS[2]);

      /* -sign(s).*TANFAC.*(s.*atan(s)-0.5*log(s.^2+1))./(0.5*pi)); */
      dv0[0] = w[0] - OptimalTension[0];
      dv0[1] = w[1] - OptimalTension[1];
      dv0[2] = w[2] - OptimalTension[2];
      dv0[3] = w[3] - OptimalTension[3];
      st.site = &i_emlrtRSI;
      b_st.site = &j_emlrtRSI;
      if ((alpha < 0.0) && (!muDoubleScalarIsNaN(P)) && (muDoubleScalarFloor(P)
           != P)) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError",
          0);
      }

      b_abs(dv0, dv6);
      st.site = &i_emlrtRSI;
      c_power(&st, dv6, P - 2.0, dv2);
      for (i0 = 0; i0 < 7; i0++) {
        b_lambda[i0] = (lambda[0] * AeqKappaMat[3 * i0] + lambda[1] *
                        AeqKappaMat[1 + 3 * i0]) + lambda[2] * AeqKappaMat[2 + 3
          * i0];
      }

      b_a[0] = (P * dv0[0] / y_tmp * dv2[0] + tau2 / (tmax[0] - w[0])) - tau1 /
        (w[0] - tmin[0]);
      b_a[1] = (P * dv0[1] / y_tmp * dv2[1] + tau2 / (tmax[1] - w[1])) - tau1 /
        (w[1] - tmin[1]);
      b_a[2] = (P * dv0[2] / y_tmp * dv2[2] + tau2 / (tmax[2] - w[2])) - tau1 /
        (w[2] - tmin[2]);
      b_a[3] = (P * dv0[3] / y_tmp * dv2[3] + tau2 / (tmax[3] - w[3])) - tau1 /
        (w[3] - tmin[3]);
      for (i0 = 0; i0 < 3; i0++) {
        b_a[i0 + 4] = dCostS[i0];
        d0 = 0.0;
        for (i = 0; i < 7; i++) {
          d0 += AeqKappaMat[i0 + 3 * i] * w[i];
        }

        b_epsilon[i0] = d0 - WTarget[i0];
      }

      for (i0 = 0; i0 < 7; i0++) {
        b_P[i0] = b_a[i0] + b_lambda[i0];
      }

      b_P[7] = b_epsilon[0];
      b_P[8] = b_epsilon[1];
      b_P[9] = b_epsilon[2];
      c_abs(b_P, varargin_1);
      st.site = &i_emlrtRSI;
      if (!muDoubleScalarIsNaN(varargin_1[0])) {
        i = 1;
      } else {
        i = 0;
        LimitExceed = 2;
        exitg2 = false;
        while ((!exitg2) && (LimitExceed < 11)) {
          if (!muDoubleScalarIsNaN(varargin_1[LimitExceed - 1])) {
            i = LimitExceed;
            exitg2 = true;
          } else {
            LimitExceed++;
          }
        }
      }

      if (i == 0) {
        Condition = varargin_1[0];
      } else {
        Condition = varargin_1[i - 1];
        i0 = i + 1;
        for (LimitExceed = i0; LimitExceed < 11; LimitExceed++) {
          d0 = varargin_1[LimitExceed - 1];
          if (Condition < d0) {
            Condition = d0;
          }
        }
      }

      /*          X(N_Iter)=Condition;     */
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }

      if (t < 1.0E-7) {
        *InfeasibleFlag = 1.0;

        /*                  save AQ */
        /*                 a=asl */
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
}

/* End of code generation (Newton_SlackAnyP.c) */
