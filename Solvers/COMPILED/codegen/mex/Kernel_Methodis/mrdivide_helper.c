/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mrdivide_helper.c
 *
 * Code generation for function 'mrdivide_helper'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Kernel_Methodis.h"
#include "mrdivide_helper.h"
#include "lusolve.h"
#include "qrsolve.h"

/* Variable Definitions */
static emlrtRSInfo od_emlrtRSI = { 20, /* lineNo */
  "mrdivide_helper",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_helper.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 42, /* lineNo */
  "mrdiv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_helper.m"/* pathName */
};

static emlrtRSInfo qd_emlrtRSI = { 44, /* lineNo */
  "mrdiv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_helper.m"/* pathName */
};

static emlrtRTEInfo g_emlrtRTEI = { 16,/* lineNo */
  19,                                  /* colNo */
  "mrdivide_helper",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_helper.m"/* pName */
};

/* Function Definitions */
void mrdivide_helper(const emlrtStack *sp, const real_T A_data[], const int32_T
                     A_size[2], const real_T B_data[], const int32_T B_size[2],
                     real_T Y_data[], int32_T Y_size[2])
{
  int32_T b_B_size[2];
  int32_T loop_ub;
  int32_T i5;
  int32_T b_A_size[1];
  int32_T b_loop_ub;
  int32_T i6;
  real_T b_A_data[24];
  real_T b_B_data[576];
  real_T tmp_data[24];
  int32_T tmp_size[1];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (B_size[1] != A_size[1]) {
    emlrtErrorWithMessageIdR2018a(sp, &g_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  st.site = &od_emlrtRSI;
  if ((A_size[1] == 0) || ((B_size[0] == 0) || (B_size[1] == 0))) {
    Y_size[0] = 1;
    Y_size[1] = (int8_T)B_size[0];
    loop_ub = (int8_T)B_size[0];
    if (0 <= loop_ub - 1) {
      memset(&Y_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
    }
  } else if (B_size[0] == B_size[1]) {
    b_st.site = &pd_emlrtRSI;
    b_lusolve(&b_st, B_data, B_size, A_data, A_size, Y_data, Y_size);
  } else {
    b_B_size[0] = B_size[1];
    b_B_size[1] = B_size[0];
    loop_ub = B_size[0];
    for (i5 = 0; i5 < loop_ub; i5++) {
      b_loop_ub = B_size[1];
      for (i6 = 0; i6 < b_loop_ub; i6++) {
        b_B_data[i6 + b_B_size[0] * i5] = B_data[i5 + B_size[0] * i6];
      }
    }

    b_A_size[0] = A_size[1];
    if (0 <= A_size[1] - 1) {
      memcpy(&b_A_data[0], &A_data[0], (uint32_T)(A_size[1] * (int32_T)sizeof
              (real_T)));
    }

    b_st.site = &qd_emlrtRSI;
    qrsolve(&b_st, b_B_data, b_B_size, b_A_data, b_A_size, tmp_data, tmp_size);
    Y_size[0] = 1;
    Y_size[1] = tmp_size[0];
    if (0 <= tmp_size[0] - 1) {
      memcpy(&Y_data[0], &tmp_data[0], (uint32_T)(tmp_size[0] * (int32_T)sizeof
              (real_T)));
    }
  }
}

/* End of code generation (mrdivide_helper.c) */
