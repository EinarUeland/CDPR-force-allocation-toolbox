/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Newton_StandardAnyP_terminate.c
 *
 * Code generation for function 'Newton_StandardAnyP_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Newton_StandardAnyP.h"
#include "Newton_StandardAnyP_terminate.h"
#include "_coder_Newton_StandardAnyP_mex.h"
#include "Newton_StandardAnyP_data.h"

/* Function Definitions */
void Newton_StandardAnyP_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void Newton_StandardAnyP_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (Newton_StandardAnyP_terminate.c) */
