/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xscal.c
 *
 * Code generation for function 'xscal'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "pinv.h"
#include "xscal.h"
#include "eml_int_forloop_overflow_check.h"
#include "pinv_data.h"

/* Function Definitions */
void b_xscal(const emlrtStack *sp, real_T a, real_T x[36], int32_T ix0)
{
  int32_T b;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b = ix0 + 5;
  b_st.site = &ac_emlrtRSI;
  if ((ix0 <= ix0 + 5) && (ix0 + 5 > 2147483646)) {
    c_st.site = &vb_emlrtRSI;
    check_forloop_overflow_error(&c_st, true);
  }

  for (k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

void xscal(const emlrtStack *sp, real_T a, real_T x[48], int32_T ix0)
{
  int32_T b;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b = ix0 + 7;
  b_st.site = &ac_emlrtRSI;
  if ((ix0 <= ix0 + 7) && (ix0 + 7 > 2147483646)) {
    c_st.site = &vb_emlrtRSI;
    check_forloop_overflow_error(&c_st, true);
  }

  for (k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

/* End of code generation (xscal.c) */
