/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Newton_StandardAnyP.c
 *
 * Code generation for function 'Newton_StandardAnyP'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Newton_StandardAnyP.h"
#include "power.h"
#include "any.h"
#include "mldivide.h"
#include "mean.h"
#include "sum.h"
#include "Newton_StandardAnyP_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 52,    /* lineNo */
  "Newton_StandardAnyP",               /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_StandardAnyP.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 53,  /* lineNo */
  "Newton_StandardAnyP",               /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_StandardAnyP.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 59,  /* lineNo */
  "Newton_StandardAnyP",               /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_StandardAnyP.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 82,  /* lineNo */
  "Newton_StandardAnyP",               /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_StandardAnyP.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 88,  /* lineNo */
  "Newton_StandardAnyP",               /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_StandardAnyP.m"/* pathName */
};

/* Function Definitions */
void Newton_StandardAnyP(const emlrtStack *sp, const real_T X0[7], const real_T
  Aeq[12], const real_T WTarget[3], const real_T tmin[4], const real_T tmax[4],
  real_T tau1, real_T tau2, const real_T OptimalTension[4], real_T Tol, real_T P,
  real_T IterMax, real_T alpha, real_T w[4], real_T lambda[3], real_T *N_Iter,
  real_T *InfeasibleFlag, real_T *LineIter)
{
  real_T dv0[4];
  boolean_T b_X0[8];
  real_T Condition;
  real_T ConditionOld;
  real_T x_idx_3;
  real_T x_idx_0;
  real_T b_lambda[4];
  real_T w0[4];
  real_T A2_tmp[4];
  real_T x_idx_1;
  real_T x_idx_2;
  real_T b[4];
  real_T y_tmp;
  real_T dv1[4];
  real_T dv2[4];
  real_T d[16];
  int32_T i0;
  real_T B2[7];
  real_T b_Aeq[3];
  int32_T LimitExceed;
  real_T b_d[49];
  real_T dLambda_idx_0;
  real_T dLambda_idx_1;
  real_T dLambda_idx_2;
  real_T t;
  real_T lambda0_idx_0;
  real_T lambda0_idx_1;
  real_T lambda0_idx_2;
  boolean_T x[8];
  boolean_T y;
  int32_T k;
  boolean_T exitg1;
  real_T b_x[7];
  real_T varargin_1[7];
  boolean_T exitg2;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;

  /*  load Inn0; P=2; */
  /*  alpha=(tmax-tmin)/2; % DO NOT BOTHER AT `THIS POINT TO DIFFERENTIATE BETWEEN DIFFERNT TMIN AND TMAX */
  /*   alpha=1; */
  /*  tau1=tau1/alpha;< */
  /*  tau2=tau2/alpha; */
  /*  alpha=1; */
  *InfeasibleFlag = 0.0;
  w[0] = X0[0];
  w[1] = X0[1];
  w[2] = X0[2];
  w[3] = X0[3];
  lambda[0] = X0[4];
  lambda[1] = X0[5];
  lambda[2] = X0[6];
  if (sum(*(real_T (*)[3])&X0[4]) == 0.0) {
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
    b_X0[0] = (OptimalTension[0] - (tmin[0] + 1.0E-5) < 0.0);
    b_X0[4] = ((tmax[0] - 1.0E-5) - OptimalTension[0] < 0.0);
    w[1] = OptimalTension[1];
    b_X0[1] = (OptimalTension[1] - (tmin[1] + 1.0E-5) < 0.0);
    b_X0[5] = ((tmax[1] - 1.0E-5) - OptimalTension[1] < 0.0);
    w[2] = OptimalTension[2];
    b_X0[2] = (OptimalTension[2] - (tmin[2] + 1.0E-5) < 0.0);
    b_X0[6] = ((tmax[2] - 1.0E-5) - OptimalTension[2] < 0.0);
    w[3] = OptimalTension[3];
    b_X0[3] = (OptimalTension[3] - (tmin[3] + 1.0E-5) < 0.0);
    b_X0[7] = ((tmax[3] - 1.0E-5) - OptimalTension[3] < 0.0);
    if (any(b_X0)) {
      /* LETS */
      w[0] = (tmin[0] + tmax[0]) / 2.0;
      w[1] = (tmin[1] + tmax[1]) / 2.0;
      w[2] = (tmin[2] + tmax[2]) / 2.0;
      w[3] = (tmin[3] + tmax[3]) / 2.0;
    }
  }

  /* SETTING UP DUMMY VARIABLES */
  ConditionOld = rtInf;
  Condition = rtInf;
  *N_Iter = 0.0;
  *LineIter = 0.0;

  /*  P*(P-1)*abs((w-OptimalTension).^P./(P-OptimalTension).^2) */
  /*  P=2 */
  /* SQP ITERATIVE SOLVER. */
  /*  save PREWH2 */
  while (Condition > Tol) {
    /*       D1=(P.*(w-OptimalTension)*(abs(w-OptimalTension)).^(P-2)) */
    /*  D2=(P*(P-1)*(abs(w-OptimalTension)).^P)./((P-OptimalTension).^2)      + (+tau2*1./(tmax-w).^2+tau1*1./(w-tmin).^2); */
    /*      */
    /*  B22=[-V1;-[Aeq*w-WTarget]]; */
    x_idx_3 = w[0] - OptimalTension[0];
    x_idx_0 = x_idx_3;
    b_lambda[0] = muDoubleScalarAbs(x_idx_3);
    w0[0] = tmax[0] - w[0];
    A2_tmp[0] = w[0] - tmin[0];
    x_idx_3 = w[1] - OptimalTension[1];
    x_idx_1 = x_idx_3;
    b_lambda[1] = muDoubleScalarAbs(x_idx_3);
    w0[1] = tmax[1] - w[1];
    A2_tmp[1] = w[1] - tmin[1];
    x_idx_3 = w[2] - OptimalTension[2];
    x_idx_2 = x_idx_3;
    b_lambda[2] = muDoubleScalarAbs(x_idx_3);
    w0[2] = tmax[2] - w[2];
    A2_tmp[2] = w[2] - tmin[2];
    x_idx_3 = w[3] - OptimalTension[3];
    b_lambda[3] = muDoubleScalarAbs(x_idx_3);
    w0[3] = tmax[3] - w[3];
    A2_tmp[3] = w[3] - tmin[3];
    Condition = P * (P - 1.0);
    st.site = &emlrtRSI;
    b_power(&st, b_lambda, P - 2.0, b);
    st.site = &emlrtRSI;
    b_st.site = &f_emlrtRSI;
    y_tmp = muDoubleScalarPower(alpha, P);
    if ((alpha < 0.0) && (!muDoubleScalarIsNaN(P)) && (muDoubleScalarFloor(P) !=
         P)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
        "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
    }

    power(w0, dv1);
    power(A2_tmp, dv2);
    b[0] = Condition * b[0] / y_tmp + (tau2 / dv1[0] + tau1 / dv2[0]);
    b[1] = Condition * b[1] / y_tmp + (tau2 / dv1[1] + tau1 / dv2[1]);
    b[2] = Condition * b[2] / y_tmp + (tau2 / dv1[2] + tau1 / dv2[2]);
    b[3] = Condition * b[3] / y_tmp + (tau2 / dv1[3] + tau1 / dv2[3]);
    memset(&d[0], 0, sizeof(real_T) << 4);
    d[0] = b[0];
    d[5] = b[1];
    d[10] = b[2];
    d[15] = b[3];
    st.site = &b_emlrtRSI;
    b_st.site = &f_emlrtRSI;
    if ((alpha < 0.0) && (!muDoubleScalarIsNaN(P)) && (muDoubleScalarFloor(P) !=
         P)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
        "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
    }

    st.site = &b_emlrtRSI;
    b_power(&st, b_lambda, P - 2.0, dv1);
    for (i0 = 0; i0 < 3; i0++) {
      b_Aeq[i0] = -((((Aeq[i0] * w[0] + Aeq[i0 + 3] * w[1]) + Aeq[i0 + 6] * w[2])
                     + Aeq[i0 + 9] * w[3]) - WTarget[i0]);
    }

    B2[0] = -((P * x_idx_0 * dv1[0] / y_tmp + tau2 / w0[0]) - tau1 / A2_tmp[0]);
    B2[1] = -((P * x_idx_1 * dv1[1] / y_tmp + tau2 / w0[1]) - tau1 / A2_tmp[1]);
    B2[2] = -((P * x_idx_2 * dv1[2] / y_tmp + tau2 / w0[2]) - tau1 / A2_tmp[2]);
    B2[3] = -((P * x_idx_3 * dv1[3] / y_tmp + tau2 / w0[3]) - tau1 / A2_tmp[3]);
    B2[4] = b_Aeq[0];
    B2[5] = b_Aeq[1];
    B2[6] = b_Aeq[2];

    /*   A3= [diag(V22) Aeq';Aeq zeros(MDIM,MDIM)]; */
    /*  B2(1:4)-D1P */
    /*  a=Asl */
    /*      B2= [-[P.*(w-OptimalTension).*abs(w-OptimalTension).^(P-2)+tau2*1./(tmax-w) -  tau1*1./(w-tmin)]; -[Aeq*w-WTarget]]; */
    for (i0 = 0; i0 < 4; i0++) {
      LimitExceed = i0 << 2;
      b_d[7 * i0] = d[LimitExceed];
      b_d[1 + 7 * i0] = d[1 + LimitExceed];
      b_d[2 + 7 * i0] = d[2 + LimitExceed];
      b_d[3 + 7 * i0] = d[3 + LimitExceed];
    }

    for (i0 = 0; i0 < 3; i0++) {
      LimitExceed = 7 * (i0 + 4);
      b_d[LimitExceed] = Aeq[i0];
      b_d[1 + LimitExceed] = Aeq[i0 + 3];
      b_d[2 + LimitExceed] = Aeq[i0 + 6];
      b_d[3 + LimitExceed] = Aeq[i0 + 9];
    }

    for (i0 = 0; i0 < 4; i0++) {
      b_d[7 * i0 + 4] = Aeq[3 * i0];
      b_d[7 * i0 + 5] = Aeq[1 + 3 * i0];
      b_d[7 * i0 + 6] = Aeq[2 + 3 * i0];
    }

    for (i0 = 0; i0 < 3; i0++) {
      LimitExceed = 7 * (i0 + 4);
      b_d[LimitExceed + 4] = 0.0;
      b_d[LimitExceed + 5] = 0.0;
      b_d[LimitExceed + 6] = 0.0;
    }

    st.site = &c_emlrtRSI;
    mldivide(&st, b_d, B2);
    dLambda_idx_0 = B2[4] - lambda[0];
    dLambda_idx_1 = B2[5] - lambda[1];
    dLambda_idx_2 = B2[6] - lambda[2];
    t = 1.0;
    (*N_Iter)++;
    w[0] += B2[0];
    w[1] += B2[1];
    w[2] += B2[2];
    w[3] += B2[3];
    lambda[0] += dLambda_idx_0;
    lambda[1] += dLambda_idx_1;
    lambda[2] += dLambda_idx_2;
    w0[0] = w[0];
    w0[1] = w[1];
    w0[2] = w[2];
    w0[3] = w[3];
    lambda0_idx_0 = lambda[0];
    lambda0_idx_1 = lambda[1];
    lambda0_idx_2 = lambda[2];

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
      w[0] = w0[0] - (1.0 - t) * B2[0];
      w[1] = w0[1] - (1.0 - t) * B2[1];
      w[2] = w0[2] - (1.0 - t) * B2[2];
      w[3] = w0[3] - (1.0 - t) * B2[3];
      lambda[0] = lambda0_idx_0 - (1.0 - t) * dLambda_idx_0;
      lambda[1] = lambda0_idx_1 - (1.0 - t) * dLambda_idx_1;
      lambda[2] = lambda0_idx_2 - (1.0 - t) * dLambda_idx_2;
      x[0] = (w[0] - tmin[0] < 0.0);
      x[4] = (tmax[0] - w[0] < 0.0);
      x[1] = (w[1] - tmin[1] < 0.0);
      x[5] = (tmax[1] - w[1] < 0.0);
      x[2] = (w[2] - tmin[2] < 0.0);
      x[6] = (tmax[2] - w[2] < 0.0);
      x[3] = (w[3] - tmin[3] < 0.0);
      x[7] = (tmax[3] - w[3] < 0.0);
      y = false;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 8)) {
        if (x[k]) {
          y = true;
          exitg1 = true;
        } else {
          k++;
        }
      }

      if (!y) {
        LimitExceed = 0;
        t *= 0.98;

        /* JUST JERK IT A LITTLE AWAY FROM THE EDGE. */
        w[0] = w0[0] - (1.0 - t) * B2[0];
        w[1] = w0[1] - (1.0 - t) * B2[1];
        w[2] = w0[2] - (1.0 - t) * B2[2];
        w[3] = w0[3] - (1.0 - t) * B2[3];
        lambda[0] = lambda0_idx_0 - (1.0 - t) * dLambda_idx_0;
        lambda[1] = lambda0_idx_1 - (1.0 - t) * dLambda_idx_1;
        lambda[2] = lambda0_idx_2 - (1.0 - t) * dLambda_idx_2;
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    x_idx_3 = w[0] - OptimalTension[0];
    x_idx_0 = x_idx_3;
    b_lambda[0] = muDoubleScalarAbs(x_idx_3);
    x_idx_3 = w[1] - OptimalTension[1];
    x_idx_1 = x_idx_3;
    b_lambda[1] = muDoubleScalarAbs(x_idx_3);
    x_idx_3 = w[2] - OptimalTension[2];
    x_idx_2 = x_idx_3;
    b_lambda[2] = muDoubleScalarAbs(x_idx_3);
    x_idx_3 = w[3] - OptimalTension[3];
    b_lambda[3] = muDoubleScalarAbs(x_idx_3);
    st.site = &d_emlrtRSI;
    b_st.site = &f_emlrtRSI;
    if ((alpha < 0.0) && (!muDoubleScalarIsNaN(P)) && (muDoubleScalarFloor(P) !=
         P)) {
      emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
        "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
    }

    st.site = &d_emlrtRSI;
    b_power(&st, b_lambda, P - 2.0, dv1);
    for (i0 = 0; i0 < 4; i0++) {
      b_lambda[i0] = (lambda[0] * Aeq[3 * i0] + lambda[1] * Aeq[1 + 3 * i0]) +
        lambda[2] * Aeq[2 + 3 * i0];
    }

    for (i0 = 0; i0 < 3; i0++) {
      b_Aeq[i0] = (((Aeq[i0] * w[0] + Aeq[i0 + 3] * w[1]) + Aeq[i0 + 6] * w[2])
                   + Aeq[i0 + 9] * w[3]) - WTarget[i0];
    }

    b_x[0] = ((P * x_idx_0 / y_tmp * dv1[0] + tau2 / (tmax[0] - w[0])) - tau1 /
              (w[0] - tmin[0])) + b_lambda[0];
    b_x[1] = ((P * x_idx_1 / y_tmp * dv1[1] + tau2 / (tmax[1] - w[1])) - tau1 /
              (w[1] - tmin[1])) + b_lambda[1];
    b_x[2] = ((P * x_idx_2 / y_tmp * dv1[2] + tau2 / (tmax[2] - w[2])) - tau1 /
              (w[2] - tmin[2])) + b_lambda[2];
    b_x[3] = ((P * x_idx_3 / y_tmp * dv1[3] + tau2 / (tmax[3] - w[3])) - tau1 /
              (w[3] - tmin[3])) + b_lambda[3];
    b_x[4] = b_Aeq[0];
    b_x[5] = b_Aeq[1];
    b_x[6] = b_Aeq[2];
    for (k = 0; k < 7; k++) {
      varargin_1[k] = muDoubleScalarAbs(b_x[k]);
    }

    st.site = &d_emlrtRSI;
    if (!muDoubleScalarIsNaN(varargin_1[0])) {
      LimitExceed = 1;
    } else {
      LimitExceed = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 8)) {
        if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
          LimitExceed = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (LimitExceed == 0) {
      Condition = varargin_1[0];
    } else {
      Condition = varargin_1[LimitExceed - 1];
      i0 = LimitExceed + 1;
      for (k = i0; k < 8; k++) {
        x_idx_3 = varargin_1[k - 1];
        if (Condition < x_idx_3) {
          Condition = x_idx_3;
        }
      }
    }

    exitg1 = false;
    while ((!exitg1) && (ConditionOld < Condition)) {
      t *= 0.85;
      w[0] = w0[0] - (1.0 - t) * B2[0];
      w[1] = w0[1] - (1.0 - t) * B2[1];
      w[2] = w0[2] - (1.0 - t) * B2[2];
      w[3] = w0[3] - (1.0 - t) * B2[3];
      lambda[0] = lambda0_idx_0 - (1.0 - t) * dLambda_idx_0;
      lambda[1] = lambda0_idx_1 - (1.0 - t) * dLambda_idx_1;
      lambda[2] = lambda0_idx_2 - (1.0 - t) * dLambda_idx_2;
      (*LineIter)++;
      x_idx_3 = w[0] - OptimalTension[0];
      x_idx_0 = x_idx_3;
      b_lambda[0] = muDoubleScalarAbs(x_idx_3);
      x_idx_3 = w[1] - OptimalTension[1];
      x_idx_1 = x_idx_3;
      b_lambda[1] = muDoubleScalarAbs(x_idx_3);
      x_idx_3 = w[2] - OptimalTension[2];
      x_idx_2 = x_idx_3;
      b_lambda[2] = muDoubleScalarAbs(x_idx_3);
      x_idx_3 = w[3] - OptimalTension[3];
      b_lambda[3] = muDoubleScalarAbs(x_idx_3);
      st.site = &e_emlrtRSI;
      b_st.site = &f_emlrtRSI;
      if ((alpha < 0.0) && (!muDoubleScalarIsNaN(P)) && (muDoubleScalarFloor(P)
           != P)) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError",
          0);
      }

      st.site = &e_emlrtRSI;
      b_power(&st, b_lambda, P - 2.0, dv1);
      for (i0 = 0; i0 < 4; i0++) {
        b_lambda[i0] = (lambda[0] * Aeq[3 * i0] + lambda[1] * Aeq[1 + 3 * i0]) +
          lambda[2] * Aeq[2 + 3 * i0];
      }

      for (i0 = 0; i0 < 3; i0++) {
        b_Aeq[i0] = (((Aeq[i0] * w[0] + Aeq[i0 + 3] * w[1]) + Aeq[i0 + 6] * w[2])
                     + Aeq[i0 + 9] * w[3]) - WTarget[i0];
      }

      b_x[0] = ((P * x_idx_0 / y_tmp * dv1[0] + tau2 / (tmax[0] - w[0])) - tau1 /
                (w[0] - tmin[0])) + b_lambda[0];
      b_x[1] = ((P * x_idx_1 / y_tmp * dv1[1] + tau2 / (tmax[1] - w[1])) - tau1 /
                (w[1] - tmin[1])) + b_lambda[1];
      b_x[2] = ((P * x_idx_2 / y_tmp * dv1[2] + tau2 / (tmax[2] - w[2])) - tau1 /
                (w[2] - tmin[2])) + b_lambda[2];
      b_x[3] = ((P * x_idx_3 / y_tmp * dv1[3] + tau2 / (tmax[3] - w[3])) - tau1 /
                (w[3] - tmin[3])) + b_lambda[3];
      b_x[4] = b_Aeq[0];
      b_x[5] = b_Aeq[1];
      b_x[6] = b_Aeq[2];
      for (k = 0; k < 7; k++) {
        varargin_1[k] = muDoubleScalarAbs(b_x[k]);
      }

      st.site = &e_emlrtRSI;
      if (!muDoubleScalarIsNaN(varargin_1[0])) {
        LimitExceed = 1;
      } else {
        LimitExceed = 0;
        k = 2;
        exitg2 = false;
        while ((!exitg2) && (k < 8)) {
          if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
            LimitExceed = k;
            exitg2 = true;
          } else {
            k++;
          }
        }
      }

      if (LimitExceed == 0) {
        Condition = varargin_1[0];
      } else {
        Condition = varargin_1[LimitExceed - 1];
        i0 = LimitExceed + 1;
        for (k = i0; k < 8; k++) {
          x_idx_3 = varargin_1[k - 1];
          if (Condition < x_idx_3) {
            Condition = x_idx_3;
          }
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }

      if (t < 0.0001) {
        *InfeasibleFlag = 1.0;
        Condition = -1.0;

        /*    a=asl */
        exitg1 = true;
      }
    }

    ConditionOld = Condition;

    /*  ConditionLog(N_Iter)=Condition; */
    if (*N_Iter > IterMax) {
      *InfeasibleFlag = 2.0;
      Condition = -1.0;
    }

    /*  save AFT2 */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  W=(Aeq*w)-WTarget */
  /*  LineIter=LineIter */
}

/* End of code generation (Newton_StandardAnyP.c) */
