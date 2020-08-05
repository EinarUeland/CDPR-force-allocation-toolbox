/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdotc.c
 *
 * Code generation for function 'xdotc'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "pinv.h"
#include "xdotc.h"
#include "eml_int_forloop_overflow_check.h"
#include "pinv_data.h"

/* Variable Definitions */
static emlrtRSInfo bc_emlrtRSI = { 32, /* lineNo */
  "xdotc",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdotc.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 35, /* lineNo */
  "xdot",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xdot.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 15, /* lineNo */
  "xdot",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xdot.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 42, /* lineNo */
  "xdotx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xdotx.m"/* pathName */
};

/* Function Definitions */
real_T b_xdotc(const emlrtStack *sp, int32_T n, const real_T x[36], int32_T ix0,
               const real_T y[36], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &cc_emlrtRSI;
  c_st.site = &dc_emlrtRSI;
  d = 0.0;
  if (n >= 1) {
    ix = ix0;
    iy = iy0;
    d_st.site = &ec_emlrtRSI;
    if (n > 2147483646) {
      e_st.site = &vb_emlrtRSI;
      check_forloop_overflow_error(&e_st, true);
    }

    for (k = 0; k < n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

real_T xdotc(const emlrtStack *sp, int32_T n, const real_T x[48], int32_T ix0,
             const real_T y[48], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &cc_emlrtRSI;
  c_st.site = &dc_emlrtRSI;
  d = 0.0;
  if (n >= 1) {
    ix = ix0;
    iy = iy0;
    d_st.site = &ec_emlrtRSI;
    if (n > 2147483646) {
      e_st.site = &vb_emlrtRSI;
      check_forloop_overflow_error(&e_st, true);
    }

    for (k = 0; k < n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

/* End of code generation (xdotc.c) */
