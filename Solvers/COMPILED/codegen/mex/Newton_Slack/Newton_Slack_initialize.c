/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Newton_Slack_initialize.c
 *
 * Code generation for function 'Newton_Slack_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Newton_Slack.h"
#include "Newton_Slack_initialize.h"
#include "_coder_Newton_Slack_mex.h"
#include "Newton_Slack_data.h"

/* Function Definitions */
void Newton_Slack_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (Newton_Slack_initialize.c) */
