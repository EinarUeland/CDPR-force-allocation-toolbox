/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Newton_StandardAnyP_mex.c
 *
 * Code generation for function '_coder_Newton_StandardAnyP_mex'
 *
 */

/* Include files */
#include "Newton_StandardAnyP.h"
#include "_coder_Newton_StandardAnyP_mex.h"
#include "Newton_StandardAnyP_terminate.h"
#include "_coder_Newton_StandardAnyP_api.h"
#include "Newton_StandardAnyP_initialize.h"
#include "Newton_StandardAnyP_data.h"

/* Function Declarations */
static void Newton_StandardAnyP_mexFunction(int32_T nlhs, mxArray *plhs[5],
  int32_T nrhs, const mxArray *prhs[12]);

/* Function Definitions */
static void Newton_StandardAnyP_mexFunction(int32_T nlhs, mxArray *plhs[5],
  int32_T nrhs, const mxArray *prhs[12])
{
  const mxArray *outputs[5];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 12) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 12, 4,
                        19, "Newton_StandardAnyP");
  }

  if (nlhs > 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 19,
                        "Newton_StandardAnyP");
  }

  /* Call the function. */
  Newton_StandardAnyP_api(prhs, nlhs, outputs);

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
  mexAtExit(Newton_StandardAnyP_atexit);

  /* Module initialization. */
  Newton_StandardAnyP_initialize();

  /* Dispatch the entry-point. */
  Newton_StandardAnyP_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  Newton_StandardAnyP_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_Newton_StandardAnyP_mex.c) */
