/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Newton_Slack_mex.c
 *
 * Code generation for function '_coder_Newton_Slack_mex'
 *
 */

/* Include files */
#include "Newton_Slack.h"
#include "_coder_Newton_Slack_mex.h"
#include "Newton_Slack_terminate.h"
#include "_coder_Newton_Slack_api.h"
#include "Newton_Slack_initialize.h"
#include "Newton_Slack_data.h"

/* Function Declarations */
static void Newton_Slack_mexFunction(int32_T nlhs, mxArray *plhs[6], int32_T
  nrhs, const mxArray *prhs[15]);

/* Function Definitions */
static void Newton_Slack_mexFunction(int32_T nlhs, mxArray *plhs[6], int32_T
  nrhs, const mxArray *prhs[15])
{
  const mxArray *outputs[6];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 15) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 15, 4,
                        12, "Newton_Slack");
  }

  if (nlhs > 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "Newton_Slack");
  }

  /* Call the function. */
  Newton_Slack_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(Newton_Slack_atexit);

  /* Module initialization. */
  Newton_Slack_initialize();

  /* Dispatch the entry-point. */
  Newton_Slack_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  Newton_Slack_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_Newton_Slack_mex.c) */
