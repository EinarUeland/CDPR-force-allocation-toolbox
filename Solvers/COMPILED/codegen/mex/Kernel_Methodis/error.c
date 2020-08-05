/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * error.c
 *
 * Code generation for function 'error'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Kernel_Methodis.h"
#include "error.h"
#include "_coder_Kernel_Methodis_api.h"
#include "Kernel_Methodis_mexutil.h"

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = { 27,    /* lineNo */
  5,                                   /* colNo */
  "error",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\lang\\error.m"/* pName */
};

static emlrtRSInfo de_emlrtRSI = { 27, /* lineNo */
  "error",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\lang\\error.m"/* pathName */
};

/* Function Declarations */
static void b_error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    const mxArray *d, emlrtMCInfo *location);

/* Function Definitions */
static void b_error(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  emlrtCallMATLABR2012b(sp, 0, NULL, 3, pArrays, "error", true, location);
}

void error(const emlrtStack *sp, real_T varargin_2, real_T varargin_3)
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 1, 74 };

  static const char_T varargin_1[74] = { 'T', 'h', 'e', ' ', 'n', 'u', 'm', 'b',
    'e', 'r', ' ', 'o', 'f', ' ', 'a', 'c', 't', 'u', 'a', 't', 'o', 'r', 's',
    ' ', '(', '%', 'd', ')', ' ', 'm', 'u', 's', 't', ' ', 'b', 'e', ' ', 'o',
    'n', 'e', ' ', 'm', 'o', 'r', 'e', ' ', 't', 'h', 'a', 'n', ' ', 'd', 'e',
    'g', 'r', 'e', 'e', 's', ' ', 'o', 'f', ' ', 'f', 'r', 'e', 'e', 'd', 'o',
    'm', ' ', '(', '%', 'd', ')' };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  y = NULL;
  m0 = emlrtCreateCharArray(2, iv0);
  emlrtInitCharArrayR2013a(sp, 74, m0, &varargin_1[0]);
  emlrtAssign(&y, m0);
  st.site = &de_emlrtRSI;
  b_error(&st, y, emlrt_marshallOut(varargin_2), emlrt_marshallOut(varargin_3),
          &emlrtMCI);
}

/* End of code generation (error.c) */
