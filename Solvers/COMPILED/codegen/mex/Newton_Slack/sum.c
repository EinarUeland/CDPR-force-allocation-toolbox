/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Newton_Slack.h"
#include "sum.h"

/* Function Definitions */
real_T sum(const real_T x[3])
{
  return (x[0] + x[1]) + x[2];
}

/* End of code generation (sum.c) */
