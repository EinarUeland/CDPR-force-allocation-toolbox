/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Newton_StandardAnyP.h"
#include "power.h"
#include "Newton_StandardAnyP_data.h"

/* Function Definitions */
void b_power(const emlrtStack *sp, const real_T a[4], real_T b, real_T y[4])
{
  boolean_T p;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &f_emlrtRSI;
  y[0] = muDoubleScalarPower(a[0], b);
  y[1] = muDoubleScalarPower(a[1], b);
  y[2] = muDoubleScalarPower(a[2], b);
  y[3] = muDoubleScalarPower(a[3], b);
  if ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarFloor(b) != b)) {
    p = (a[0] < 0.0);
    if (p || (a[1] < 0.0)) {
      p = true;
    } else {
      p = false;
    }

    if (p || (a[2] < 0.0)) {
      p = true;
    } else {
      p = false;
    }

    if (p || (a[3] < 0.0)) {
      p = true;
    } else {
      p = false;
    }
  } else {
    p = false;
  }

  if (p) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }
}

void power(const real_T a[4], real_T y[4])
{
  y[0] = a[0] * a[0];
  y[1] = a[1] * a[1];
  y[2] = a[2] * a[2];
  y[3] = a[3] * a[3];
}

/* End of code generation (power.c) */
