/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Newton_Standard_mex.c
 *
 * Code generation for function '_coder_Newton_Standard_mex'
 *
 */

/* Include files */
#include "Newton_Standard.h"
#include "_coder_Newton_Standard_mex.h"
#include "Newton_Standard_terminate.h"
#include "_coder_Newton_Standard_api.h"
#include "Newton_Standard_initialize.h"
#include "Newton_Standard_data.h"

/* Function Declarations */
static void Newton_Standard_mexFunction(int32_T nlhs, mxArray *plhs[5], int32_T
  nrhs, const mxArray *prhs[11]);

/* Function Definitions */
static void Newton_Standard_mexFunction(int32_T nlhs, mxArray *plhs[5], int32_T
  nrhs, const mxArray *prhs[11])
{
  const mxArray *outputs[5];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 11) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 11, 4,
                        15, "Newton_Standard");
  }

  if (nlhs > 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 15,
                        "Newton_Standard");
  }

  /* Call the function. */
  Newton_Standard_api(prhs, nlhs, outputs);

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
  mexAtExit(Newton_Standard_atexit);

  /* Module initialization. */
  Newton_Standard_initialize();

  /* Dispatch the entry-point. */
  Newton_Standard_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  Newton_Standard_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_Newton_Standard_mex.c) */
