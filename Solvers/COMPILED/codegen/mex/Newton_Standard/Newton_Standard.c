/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Newton_Standard.c
 *
 * Code generation for function 'Newton_Standard'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Newton_Standard.h"
#include "mldivide.h"
#include "Newton_Standard_data.h"

/* Variable Definitions */
static emlrtRSInfo c_emlrtRSI = { 87,  /* lineNo */
  "Newton_Standard",                   /* fcnName */
  "C:\\Users\\einarsu\\OneDrive - NTNU\\PHD STATE OF THE ART\\PublishableCDPR_TOOLBOX\\Solvers\\Newton_Standard.m"/* pathName */
};

/* Function Definitions */
void Newton_Standard(const emlrtStack *sp, const real_T X0[7], const real_T Aeq
                     [12], const real_T WTarget[3], const real_T tmin[4], const
                     real_T tmax[4], real_T tau1, real_T tau2, const real_T
                     OptimalTension[4], real_T Tol, real_T IterMax, real_T alpha,
                     real_T w[4], real_T lambda[3], real_T *N_Iter, real_T
                     *InfeasibleFlag, real_T *LineIter)
{
  real_T Condition;
  boolean_T x[8];
  boolean_T y;
  int32_T k;
  boolean_T exitg1;
  real_T ConditionOld;
  real_T A2_tmp_idx_0;
  real_T dLambda_idx_0;
  real_T dLambda_idx_1;
  real_T dLambda_idx_2;
  real_T t;
  real_T lambda0_idx_0;
  real_T lambda0_idx_1;
  real_T a;
  real_T d[16];
  real_T b_x[7];
  real_T b_Aeq[3];
  int32_T LimitExceed;
  real_T b_d[49];
  real_T w0[4];
  real_T lambda0_idx_2;
  boolean_T exitg4;
  int32_T exitg3;
  real_T b_lambda[4];
  real_T c_x[7];
  real_T b_y[7];
  int32_T exitg2;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /*  load INn0 */
  /*  a=Asl */
  /* WE WILL SCALE ALL EXCEPT TAU..  */
  /*    load Inn0 */
  /*   a=asl */
  /*      coder.varsize('OptimalTension', [24 1]); */
  /*      coder.varsize('X0', [24 1]); */
  /*      coder.varsize('tmin', [24 1]); */
  /*      coder.varsize('tmax', [24 1]); */
  /*      coder.varsize('OptimalTension', [24 1]); */
  /*      coder.varsize('Aeq', [6 24]); */
  /*      coder.varsize('WTarget', [24 1]); */
  /*      coder.varsize('X0', [24 1]); */
  /*  save Inn0;a=asl */
  /*  coder.varsize('tmin', [24 1]); */
  /*    coder.varsize('tmax', [24 1]); */
  /*    coder.varsize('OptimalTension', [24 1]); */
  *LineIter = 0.0;

  /*  alpha=(tmax(1)-tmin(1))/2; % DO NOT BOTHER AT `THIS POINT TO DIFFERENTIATE BETWEEN DIFFERNT TMIN AND TMAX */
  /*  alpha=17.5000; */
  /*  % alpha=OptimalTension(1); % DO NOT BOTHER AT `THIS POINT TO DIFFERENTIATE BETWEEN DIFFERNT TMIN AND TMAX */
  /* COMMENT ON HOW Tau1 and Tau2 can be designed with respect to equations of */
  /* such that x/ dominates in  */
  /*   alpha=1; */
  /*   alpha=1; */
  /*   alpha=8 */
  /*  alpha=1; */
  /*  X0=zeros(NACT+MDIM,1) */
  *InfeasibleFlag = 0.0;
  w[0] = X0[0];
  w[1] = X0[1];
  w[2] = X0[2];
  w[3] = X0[3];
  lambda[0] = X0[4];
  lambda[1] = X0[5];
  lambda[2] = X0[6];
  if ((X0[4] + X0[5]) + X0[6] == 0.0) {
    Condition = (((OptimalTension[0] * OptimalTension[0] + OptimalTension[1] *
                   OptimalTension[1]) + OptimalTension[2] * OptimalTension[2]) +
                 OptimalTension[3] * OptimalTension[3]) / 4.0;
    lambda[0] = 100.0 * Condition;
    lambda[1] = 100.0 * Condition;
    lambda[2] = 100.0 * Condition;

    /* HOW TO SCALE WITH FORCES? */
    /*   lambda=[Aeq*Aeq']\(Aeq*w);This would be the theoretical way, but not */
    /*    helping to much.  */
  }

  x[0] = (X0[0] - (tmin[0] + 1.0E-5) < 0.0);
  x[4] = ((tmax[0] - 1.0E-5) - X0[0] < 0.0);
  x[1] = (X0[1] - (tmin[1] + 1.0E-5) < 0.0);
  x[5] = ((tmax[1] - 1.0E-5) - X0[1] < 0.0);
  x[2] = (X0[2] - (tmin[2] + 1.0E-5) < 0.0);
  x[6] = ((tmax[2] - 1.0E-5) - X0[2] < 0.0);
  x[3] = (X0[3] - (tmin[3] + 1.0E-5) < 0.0);
  x[7] = ((tmax[3] - 1.0E-5) - X0[3] < 0.0);
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

  if (y) {
    /* LETS JUMP TO COLDSTART... */
    w[0] = OptimalTension[0];
    x[0] = (OptimalTension[0] - (tmin[0] + 1.0E-5) < 0.0);
    x[4] = ((tmax[0] - 1.0E-5) - OptimalTension[0] < 0.0);
    w[1] = OptimalTension[1];
    x[1] = (OptimalTension[1] - (tmin[1] + 1.0E-5) < 0.0);
    x[5] = ((tmax[1] - 1.0E-5) - OptimalTension[1] < 0.0);
    w[2] = OptimalTension[2];
    x[2] = (OptimalTension[2] - (tmin[2] + 1.0E-5) < 0.0);
    x[6] = ((tmax[2] - 1.0E-5) - OptimalTension[2] < 0.0);
    w[3] = OptimalTension[3];
    x[3] = (OptimalTension[3] - (tmin[3] + 1.0E-5) < 0.0);
    x[7] = ((tmax[3] - 1.0E-5) - OptimalTension[3] < 0.0);
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

    if (y) {
      /* LETS */
      w[0] = (tmin[0] + tmax[0]) / 2.0;
      w[1] = (tmin[1] + tmax[1]) / 2.0;
      w[2] = (tmin[2] + tmax[2]) / 2.0;
      w[3] = (tmin[3] + tmax[3]) / 2.0;
    }
  }

  /*   w=X0(1:NACT); */
  /*    lambda=X0(NACT+1:end); */
  /*   */
  /* SETTING UP DUMMY VARIABLES */
  ConditionOld = rtInf;
  Condition = rtInf;
  *N_Iter = 0.0;

  /* SQP ITERATIVE SOLVER. */
  /*  save M2 */
  /*  disp(w) */
  exitg1 = false;
  while ((!exitg1) && (Condition > Tol)) {
    /*      save AQ2 */
    Condition = tmax[0] - w[0];
    A2_tmp_idx_0 = w[0] - tmin[0];
    dLambda_idx_0 = tmax[1] - w[1];
    dLambda_idx_1 = w[1] - tmin[1];
    dLambda_idx_2 = tmax[2] - w[2];
    t = w[2] - tmin[2];
    lambda0_idx_0 = tmax[3] - w[3];
    lambda0_idx_1 = w[3] - tmin[3];
    a = 2.0 / (alpha * alpha);
    memset(&d[0], 0, sizeof(real_T) << 4);
    d[0] = (a + tau2 / (Condition * Condition)) + tau1 / (A2_tmp_idx_0 *
      A2_tmp_idx_0);
    d[5] = (a + tau2 / (dLambda_idx_0 * dLambda_idx_0)) + tau1 / (dLambda_idx_1 *
      dLambda_idx_1);
    d[10] = (a + tau2 / (dLambda_idx_2 * dLambda_idx_2)) + tau1 / (t * t);
    d[15] = (a + tau2 / (lambda0_idx_0 * lambda0_idx_0)) + tau1 / (lambda0_idx_1
      * lambda0_idx_1);

    /*      if rcond(A2)<6e-16 */
    /*         InfeasibleFlag=3; %TRYING THIS SHITT ALTHOUGH WE HATE IT.  */
    /*         return */
    /*      end */
    for (k = 0; k < 3; k++) {
      b_Aeq[k] = -((((Aeq[k] * w[0] + Aeq[k + 3] * w[1]) + Aeq[k + 6] * w[2]) +
                    Aeq[k + 9] * w[3]) - WTarget[k]);
    }

    b_x[0] = -((a * (w[0] - OptimalTension[0]) + tau2 / Condition) - tau1 /
               A2_tmp_idx_0);
    b_x[1] = -((a * (w[1] - OptimalTension[1]) + tau2 / dLambda_idx_0) - tau1 /
               dLambda_idx_1);
    b_x[2] = -((a * (w[2] - OptimalTension[2]) + tau2 / dLambda_idx_2) - tau1 /
               t);
    b_x[3] = -((a * (w[3] - OptimalTension[3]) + tau2 / lambda0_idx_0) - tau1 /
               lambda0_idx_1);
    b_x[4] = b_Aeq[0];
    b_x[5] = b_Aeq[1];
    b_x[6] = b_Aeq[2];
    for (k = 0; k < 4; k++) {
      LimitExceed = k << 2;
      b_d[7 * k] = d[LimitExceed];
      b_d[1 + 7 * k] = d[1 + LimitExceed];
      b_d[2 + 7 * k] = d[2 + LimitExceed];
      b_d[3 + 7 * k] = d[3 + LimitExceed];
    }

    for (k = 0; k < 3; k++) {
      LimitExceed = 7 * (k + 4);
      b_d[LimitExceed] = Aeq[k];
      b_d[1 + LimitExceed] = Aeq[k + 3];
      b_d[2 + LimitExceed] = Aeq[k + 6];
      b_d[3 + LimitExceed] = Aeq[k + 9];
    }

    for (k = 0; k < 4; k++) {
      b_d[7 * k + 4] = Aeq[3 * k];
      b_d[7 * k + 5] = Aeq[1 + 3 * k];
      b_d[7 * k + 6] = Aeq[2 + 3 * k];
    }

    for (k = 0; k < 3; k++) {
      LimitExceed = 7 * (k + 4);
      b_d[LimitExceed + 4] = 0.0;
      b_d[LimitExceed + 5] = 0.0;
      b_d[LimitExceed + 6] = 0.0;
    }

    st.site = &c_emlrtRSI;
    mldivide(&st, b_d, b_x);

    /*      B2-A2*x */
    dLambda_idx_0 = b_x[4] - lambda[0];
    dLambda_idx_1 = b_x[5] - lambda[1];
    dLambda_idx_2 = b_x[6] - lambda[2];
    t = 1.0;
    (*N_Iter)++;
    w[0] += b_x[0];
    w[1] += b_x[1];
    w[2] += b_x[2];
    w[3] += b_x[3];
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
    exitg4 = false;
    while ((!exitg4) && (k < 8)) {
      if (x[k]) {
        y = true;
        exitg4 = true;
      } else {
        k++;
      }
    }

    LimitExceed = y;
    do {
      exitg3 = 0;
      if (LimitExceed == 1) {
        t *= 0.85;
        w[0] = w0[0] - (1.0 - t) * b_x[0];
        w[1] = w0[1] - (1.0 - t) * b_x[1];
        w[2] = w0[2] - (1.0 - t) * b_x[2];
        w[3] = w0[3] - (1.0 - t) * b_x[3];
        lambda[0] = lambda0_idx_0 - (1.0 - t) * dLambda_idx_0;
        lambda[1] = lambda0_idx_1 - (1.0 - t) * dLambda_idx_1;
        lambda[2] = lambda0_idx_2 - (1.0 - t) * dLambda_idx_2;
        if (t < 1.0E-7) {
          *InfeasibleFlag = 3.0;

          /* PROBABLY THIS IS due to rcond error */
          w[0] = -1.0;
          w[1] = -1.0;
          w[2] = -1.0;
          w[3] = -1.0;
          exitg3 = 1;
        } else {
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
          exitg4 = false;
          while ((!exitg4) && (k < 8)) {
            if (x[k]) {
              y = true;
              exitg4 = true;
            } else {
              k++;
            }
          }

          if (!y) {
            LimitExceed = 0;
            t *= 0.98;

            /* JUST JERK IT A LITTLE AWAY FROM THE EDGE. */
            w[0] = w0[0] - (1.0 - t) * b_x[0];
            w[1] = w0[1] - (1.0 - t) * b_x[1];
            w[2] = w0[2] - (1.0 - t) * b_x[2];
            w[3] = w0[3] - (1.0 - t) * b_x[3];
            lambda[0] = lambda0_idx_0 - (1.0 - t) * dLambda_idx_0;
            lambda[1] = lambda0_idx_1 - (1.0 - t) * dLambda_idx_1;
            lambda[2] = lambda0_idx_2 - (1.0 - t) * dLambda_idx_2;
          }

          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }
      } else {
        /*      t1=t;  */
        /*           t=t*beta; */
        /*           w=w0-((1-t)*dw); */
        /*           lambda=lambda0-((1-t)*dLambda); */
        for (k = 0; k < 4; k++) {
          b_lambda[k] = (lambda[0] * Aeq[3 * k] + lambda[1] * Aeq[1 + 3 * k]) +
            lambda[2] * Aeq[2 + 3 * k];
        }

        for (k = 0; k < 3; k++) {
          b_Aeq[k] = (((Aeq[k] * w[0] + Aeq[k + 3] * w[1]) + Aeq[k + 6] * w[2])
                      + Aeq[k + 9] * w[3]) - WTarget[k];
        }

        c_x[0] = ((a * (w[0] - OptimalTension[0]) + tau2 / (tmax[0] - w[0])) -
                  tau1 / (w[0] - tmin[0])) + b_lambda[0];
        c_x[1] = ((a * (w[1] - OptimalTension[1]) + tau2 / (tmax[1] - w[1])) -
                  tau1 / (w[1] - tmin[1])) + b_lambda[1];
        c_x[2] = ((a * (w[2] - OptimalTension[2]) + tau2 / (tmax[2] - w[2])) -
                  tau1 / (w[2] - tmin[2])) + b_lambda[2];
        c_x[3] = ((a * (w[3] - OptimalTension[3]) + tau2 / (tmax[3] - w[3])) -
                  tau1 / (w[3] - tmin[3])) + b_lambda[3];
        c_x[4] = b_Aeq[0];
        c_x[5] = b_Aeq[1];
        c_x[6] = b_Aeq[2];
        for (k = 0; k < 7; k++) {
          b_y[k] = muDoubleScalarAbs(c_x[k]);
        }

        Condition = b_y[0];
        for (k = 0; k < 6; k++) {
          Condition += b_y[k + 1];
        }

        /*             C1=Condition; a=asl */
        exitg3 = 2;
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
      exitg1 = true;
    } else {
      do {
        exitg2 = 0;
        if (ConditionOld < Condition) {
          /*  */
          t *= 0.85;
          w[0] = w0[0] - (1.0 - t) * b_x[0];
          w[1] = w0[1] - (1.0 - t) * b_x[1];
          w[2] = w0[2] - (1.0 - t) * b_x[2];
          w[3] = w0[3] - (1.0 - t) * b_x[3];
          lambda[0] = lambda0_idx_0 - (1.0 - t) * dLambda_idx_0;
          Condition = lambda0_idx_1 - (1.0 - t) * dLambda_idx_1;
          lambda[1] = lambda0_idx_1 - (1.0 - t) * dLambda_idx_1;
          A2_tmp_idx_0 = lambda0_idx_2 - (1.0 - t) * dLambda_idx_2;
          lambda[2] = lambda0_idx_2 - (1.0 - t) * dLambda_idx_2;
          for (k = 0; k < 4; k++) {
            b_lambda[k] = (lambda[0] * Aeq[3 * k] + Condition * Aeq[1 + 3 * k])
              + A2_tmp_idx_0 * Aeq[2 + 3 * k];
          }

          for (k = 0; k < 3; k++) {
            b_Aeq[k] = (((Aeq[k] * w[0] + Aeq[k + 3] * w[1]) + Aeq[k + 6] * w[2])
                        + Aeq[k + 9] * w[3]) - WTarget[k];
          }

          c_x[0] = ((a * (w[0] - OptimalTension[0]) + tau2 / (tmax[0] - w[0])) -
                    tau1 / (w[0] - tmin[0])) + b_lambda[0];
          c_x[1] = ((a * (w[1] - OptimalTension[1]) + tau2 / (tmax[1] - w[1])) -
                    tau1 / (w[1] - tmin[1])) + b_lambda[1];
          c_x[2] = ((a * (w[2] - OptimalTension[2]) + tau2 / (tmax[2] - w[2])) -
                    tau1 / (w[2] - tmin[2])) + b_lambda[2];
          c_x[3] = ((a * (w[3] - OptimalTension[3]) + tau2 / (tmax[3] - w[3])) -
                    tau1 / (w[3] - tmin[3])) + b_lambda[3];
          c_x[4] = b_Aeq[0];
          c_x[5] = b_Aeq[1];
          c_x[6] = b_Aeq[2];
          for (k = 0; k < 7; k++) {
            b_y[k] = muDoubleScalarAbs(c_x[k]);
          }

          Condition = b_y[0];
          for (k = 0; k < 6; k++) {
            Condition += b_y[k + 1];
          }

          (*LineIter)++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }

          if (t < 1.0E-5) {
            *InfeasibleFlag = 1.0;

            /*                  save H1 */
            /*                  a=Asl */
            /* HMMM ARE WE GOING TO FAR... */
            exitg2 = 1;
          }
        } else {
          /*          Conditionz(N_Iter)=Condition */
          ConditionOld = Condition;
          if (*N_Iter > IterMax) {
            *InfeasibleFlag = 2.0;
            Condition = -1.0;
          }

          /*  save INn0 */
          /*  A=LS */
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }

          exitg2 = 2;
        }
      } while (exitg2 == 0);

      if (exitg2 == 1) {
        exitg1 = true;
      }
    }
  }

  /*   save HERE2 */
  /*  w-Av */
  /*  if LineIter==1 */
  /*  %     a=asl */
  /*  end */
}

/* End of code generation (Newton_Standard.c) */
