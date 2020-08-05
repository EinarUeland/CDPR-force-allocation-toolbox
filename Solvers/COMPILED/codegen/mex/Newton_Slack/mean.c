/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean.c
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Newton_Slack.h"
#include "mean.h"

/* Function Definitions */
real_T mean(const real_T x[4])
{
  return (((x[0] + x[1]) + x[2]) + x[3]) / 4.0;
}

/* End of code generation (mean.c) */
