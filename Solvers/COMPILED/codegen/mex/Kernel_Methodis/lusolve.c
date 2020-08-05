/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * lusolve.c
 *
 * Code generation for function 'lusolve'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Kernel_Methodis.h"
#include "lusolve.h"
#include "xtrsm.h"
#include "warning.h"
#include "xgetrf.h"

/* Variable Definitions */
static emlrtRSInfo wb_emlrtRSI = { 67, /* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 109,/* lineNo */
  "lusolveNxN",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 107,/* lineNo */
  "lusolveNxN",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 90, /* lineNo */
  "warn_singular",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

/* Function Declarations */
static void warn_singular(const emlrtStack *sp);

/* Function Definitions */
static void warn_singular(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &lc_emlrtRSI;
  warning(&st);
}

void b_lusolve(const emlrtStack *sp, const real_T A_data[], const int32_T
               A_size[2], const real_T B_data[], const int32_T B_size[2], real_T
               X_data[], int32_T X_size[2])
{
  int32_T b_A_size[2];
  int32_T loop_ub;
  real_T b_A_data[576];
  int32_T ipiv_data[24];
  int32_T ipiv_size[2];
  int32_T i7;
  int32_T xj;
  real_T temp;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_A_size[0] = A_size[0];
  b_A_size[1] = A_size[1];
  loop_ub = A_size[0] * A_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&b_A_data[0], &A_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  b_st.site = &yb_emlrtRSI;
  xgetrf(&b_st, A_size[1], A_size[1], b_A_data, b_A_size, A_size[1], ipiv_data,
         ipiv_size, &loop_ub);
  if (((A_size[0] != 1) || (A_size[1] != 1)) && (loop_ub > 0)) {
    b_st.site = &xb_emlrtRSI;
    warn_singular(&b_st);
  }

  X_size[0] = 1;
  X_size[1] = B_size[1];
  loop_ub = B_size[0] * B_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&X_data[0], &B_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  c_xtrsm(A_size[1], b_A_data, A_size[1], X_data);
  d_xtrsm(A_size[1], b_A_data, A_size[1], X_data);
  i7 = A_size[1] - 1;
  for (xj = i7; xj >= 1; xj--) {
    loop_ub = ipiv_data[xj - 1];
    if (loop_ub != xj) {
      temp = X_data[xj - 1];
      loop_ub--;
      X_data[xj - 1] = X_data[loop_ub];
      X_data[loop_ub] = temp;
    }
  }
}

void lusolve(const emlrtStack *sp, const real_T A_data[], const int32_T A_size[2],
             const real_T B_data[], const int32_T B_size[1], real_T X_data[],
             int32_T X_size[1])
{
  int32_T b_A_size[2];
  int32_T loop_ub;
  real_T b_A_data[576];
  int32_T ipiv_data[24];
  int32_T ipiv_size[2];
  real_T b_X_data[24];
  int32_T xi;
  real_T tmp_data[6];
  real_T temp;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_A_size[0] = A_size[0];
  b_A_size[1] = A_size[1];
  loop_ub = A_size[0] * A_size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&b_A_data[0], &A_data[0], (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  b_st.site = &yb_emlrtRSI;
  xgetrf(&b_st, A_size[1], A_size[1], b_A_data, b_A_size, A_size[1], ipiv_data,
         ipiv_size, &loop_ub);
  if (((A_size[0] != 1) || (A_size[1] != 1)) && (loop_ub > 0)) {
    b_st.site = &xb_emlrtRSI;
    warn_singular(&b_st);
  }

  if (0 <= B_size[0] - 1) {
    memcpy(&b_X_data[0], &B_data[0], (uint32_T)(B_size[0] * (int32_T)sizeof
            (real_T)));
  }

  loop_ub = A_size[1];
  for (xi = 0; xi <= loop_ub - 2; xi++) {
    if (ipiv_data[xi] != xi + 1) {
      temp = b_X_data[xi];
      b_X_data[xi] = b_X_data[ipiv_data[xi] - 1];
      b_X_data[ipiv_data[xi] - 1] = temp;
    }
  }

  if (0 <= B_size[0] - 1) {
    memcpy(&tmp_data[0], &b_X_data[0], (uint32_T)(B_size[0] * (int32_T)sizeof
            (real_T)));
  }

  xtrsm(A_size[1], b_A_data, A_size[1], tmp_data, A_size[1]);
  if (0 <= B_size[0] - 1) {
    memcpy(&b_X_data[0], &tmp_data[0], (uint32_T)(B_size[0] * (int32_T)sizeof
            (real_T)));
    memcpy(&tmp_data[0], &b_X_data[0], (uint32_T)(B_size[0] * (int32_T)sizeof
            (real_T)));
  }

  b_xtrsm(A_size[1], b_A_data, A_size[1], tmp_data, A_size[1]);
  if (0 <= B_size[0] - 1) {
    memcpy(&b_X_data[0], &tmp_data[0], (uint32_T)(B_size[0] * (int32_T)sizeof
            (real_T)));
  }

  X_size[0] = B_size[0];
  if (0 <= B_size[0] - 1) {
    memcpy(&X_data[0], &b_X_data[0], (uint32_T)(B_size[0] * (int32_T)sizeof
            (real_T)));
  }
}

/* End of code generation (lusolve.c) */
