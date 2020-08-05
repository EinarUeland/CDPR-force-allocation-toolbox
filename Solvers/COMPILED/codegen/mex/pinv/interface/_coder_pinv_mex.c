/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_pinv_mex.c
 *
 * Code generation for function '_coder_pinv_mex'
 *
 */

/* Include files */
#include "pinv.h"
#include "_coder_pinv_mex.h"
#include "pinv_terminate.h"
#include "_coder_pinv_api.h"
#include "pinv_initialize.h"
#include "pinv_data.h"

/* Function Declarations */
static void pinv_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const
  mxArray *prhs[1]);

/* Function Definitions */
static void pinv_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const
  mxArray *prhs[1])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4, 4,
                        "pinv");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 4,
                        "pinv");
  }

  /* Call the function. */
  pinv_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(pinv_atexit);

  /* Module initialization. */
  pinv_initialize();

  /* Dispatch the entry-point. */
  pinv_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  pinv_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_pinv_mex.c) */
