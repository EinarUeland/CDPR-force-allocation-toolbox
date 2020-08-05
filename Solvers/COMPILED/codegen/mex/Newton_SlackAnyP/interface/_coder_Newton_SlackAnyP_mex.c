/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Newton_SlackAnyP_mex.c
 *
 * Code generation for function '_coder_Newton_SlackAnyP_mex'
 *
 */

/* Include files */
#include "Newton_SlackAnyP.h"
#include "_coder_Newton_SlackAnyP_mex.h"
#include "Newton_SlackAnyP_terminate.h"
#include "_coder_Newton_SlackAnyP_api.h"
#include "Newton_SlackAnyP_initialize.h"
#include "Newton_SlackAnyP_data.h"

/* Function Declarations */
static void Newton_SlackAnyP_mexFunction(int32_T nlhs, mxArray *plhs[6], int32_T
  nrhs, const mxArray *prhs[16]);

/* Function Definitions */
static void Newton_SlackAnyP_mexFunction(int32_T nlhs, mxArray *plhs[6], int32_T
  nrhs, const mxArray *prhs[16])
{
  const mxArray *outputs[6];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 16) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 16, 4,
                        16, "Newton_SlackAnyP");
  }

  if (nlhs > 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 16,
                        "Newton_SlackAnyP");
  }

  /* Call the function. */
  Newton_SlackAnyP_api(prhs, nlhs, outputs);

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
  mexAtExit(Newton_SlackAnyP_atexit);

  /* Module initialization. */
  Newton_SlackAnyP_initialize();

  /* Dispatch the entry-point. */
  Newton_SlackAnyP_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  Newton_SlackAnyP_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_Newton_SlackAnyP_mex.c) */
