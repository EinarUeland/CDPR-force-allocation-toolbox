/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Newton_Standard_initialize.c
 *
 * Code generation for function 'Newton_Standard_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Newton_Standard.h"
#include "Newton_Standard_initialize.h"
#include "_coder_Newton_Standard_mex.h"
#include "Newton_Standard_data.h"

/* Function Definitions */
void Newton_Standard_initialize(void)
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

/* End of code generation (Newton_Standard_initialize.c) */
