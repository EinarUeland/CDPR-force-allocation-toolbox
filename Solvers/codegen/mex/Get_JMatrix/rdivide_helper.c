/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rdivide_helper.c
 *
 * Code generation for function 'rdivide_helper'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Get_JMatrix.h"
#include "rdivide_helper.h"

/* Variable Definitions */
static emlrtRTEInfo i_emlrtRTEI = { 19,/* lineNo */
  15,                                  /* colNo */
  "rdivide_helper",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\rdivide_helper.m"/* pName */
};

/* Function Definitions */
void rdivide_helper(const emlrtStack *sp, const real_T x_data[], const int32_T
                    x_size[2], const real_T y_data[], const int32_T y_size[2],
                    real_T z_data[], int32_T z_size[2])
{
  int8_T varargin_1[2];
  int8_T varargin_2[2];
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  boolean_T exitg1;
  int32_T i4;
  varargin_1[0] = (int8_T)x_size[0];
  varargin_2[0] = (int8_T)y_size[0];
  varargin_1[1] = (int8_T)x_size[1];
  varargin_2[1] = (int8_T)y_size[1];
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (varargin_1[k] != varargin_2[k]) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(sp, &i_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  z_size[0] = 3;
  z_size[1] = x_size[1];
  k = x_size[0] * x_size[1];
  for (i4 = 0; i4 < k; i4++) {
    z_data[i4] = x_data[i4] / y_data[i4];
  }
}

/* End of code generation (rdivide_helper.c) */
