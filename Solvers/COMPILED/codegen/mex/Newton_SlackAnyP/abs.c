/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Newton_SlackAnyP.h"
#include "abs.h"

/* Function Definitions */
void b_abs(const real_T x[4], real_T y[4])
{
  y[0] = muDoubleScalarAbs(x[0]);
  y[1] = muDoubleScalarAbs(x[1]);
  y[2] = muDoubleScalarAbs(x[2]);
  y[3] = muDoubleScalarAbs(x[3]);
}

void c_abs(const real_T x[10], real_T y[10])
{
  int32_T k;
  for (k = 0; k < 10; k++) {
    y[k] = muDoubleScalarAbs(x[k]);
  }
}

/* End of code generation (abs.c) */
