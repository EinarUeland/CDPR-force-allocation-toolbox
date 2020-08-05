/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Kernel_Methodis.h"
#include "mldivide.h"
#include "lusolve.h"
#include "qrsolve.h"

/* Variable Definitions */
static emlrtRSInfo tb_emlrtRSI = { 20, /* lineNo */
  "mldivide",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 42, /* lineNo */
  "mldiv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 44, /* lineNo */
  "mldiv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m"/* pathName */
};

static emlrtRTEInfo f_emlrtRTEI = { 16,/* lineNo */
  19,                                  /* colNo */
  "mldivide",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m"/* pName */
};

/* Function Definitions */
void mldivide(const emlrtStack *sp, const real_T A_data[], const int32_T A_size
              [2], const real_T B_data[], const int32_T B_size[1], real_T
              Y_data[], int32_T Y_size[1])
{
  real_T tmp_data[6];
  int32_T tmp_size[1];
  int32_T loop_ub;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (B_size[0] != A_size[0]) {
    emlrtErrorWithMessageIdR2018a(sp, &f_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  st.site = &tb_emlrtRSI;
  if ((A_size[0] == 0) || (A_size[1] == 0) || (B_size[0] == 0)) {
    Y_size[0] = (int8_T)A_size[1];
    loop_ub = (int8_T)A_size[1];
    if (0 <= loop_ub - 1) {
      memset(&Y_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
    }
  } else if (A_size[0] == A_size[1]) {
    b_st.site = &ub_emlrtRSI;
    lusolve(&b_st, A_data, A_size, B_data, B_size, tmp_data, tmp_size);
    Y_size[0] = tmp_size[0];
    if (0 <= tmp_size[0] - 1) {
      memcpy(&Y_data[0], &tmp_data[0], (uint32_T)(tmp_size[0] * (int32_T)sizeof
              (real_T)));
    }
  } else {
    b_st.site = &vb_emlrtRSI;
    qrsolve(&b_st, A_data, A_size, B_data, B_size, Y_data, Y_size);
  }
}

/* End of code generation (mldivide.c) */
