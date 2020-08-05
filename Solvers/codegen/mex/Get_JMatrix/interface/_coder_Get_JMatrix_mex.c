/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Get_JMatrix_mex.c
 *
 * Code generation for function '_coder_Get_JMatrix_mex'
 *
 */

/* Include files */
#include "Get_JMatrix.h"
#include "_coder_Get_JMatrix_mex.h"
#include "Get_JMatrix_terminate.h"
#include "_coder_Get_JMatrix_api.h"
#include "Get_JMatrix_initialize.h"
#include "Get_JMatrix_data.h"

/* Function Declarations */
static void Get_JMatrix_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[3]);

/* Function Definitions */
static void Get_JMatrix_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[3])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        11, "Get_JMatrix");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "Get_JMatrix");
  }

  /* Call the function. */
  Get_JMatrix_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(Get_JMatrix_atexit);

  /* Module initialization. */
  Get_JMatrix_initialize();

  /* Dispatch the entry-point. */
  Get_JMatrix_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  Get_JMatrix_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_Get_JMatrix_mex.c) */
