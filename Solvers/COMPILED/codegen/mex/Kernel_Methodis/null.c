/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * null.c
 *
 * Code generation for function 'null'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Kernel_Methodis.h"
#include "null.h"
#include "anyNonFinite.h"
#include "eps.h"
#include "svd.h"

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = { 20,  /* lineNo */
  "null",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\null.m"/* pathName */
};

static emlrtRTEInfo b_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "null",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\null.m"/* pName */
};

/* Function Definitions */
void null(const emlrtStack *sp, const real_T A_data[], const int32_T A_size[2],
          real_T Z_data[], int32_T Z_size[2])
{
  real_T unusedU0_data[36];
  int32_T unusedU0_size[2];
  real_T s_data[6];
  int32_T s_size[1];
  real_T V_data[576];
  int32_T V_size[2];
  int32_T ns;
  int32_T maxmn;
  int32_T r;
  real_T tol;
  int32_T Z_size_tmp;
  int32_T i0;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (anyNonFinite(A_data, A_size)) {
    Z_size[0] = A_size[1];
    Z_size[1] = A_size[1];
    ns = A_size[1] * A_size[1];
    for (maxmn = 0; maxmn < ns; maxmn++) {
      Z_data[maxmn] = rtNaN;
    }
  } else {
    st.site = &w_emlrtRSI;
    svd(&st, A_data, A_size, unusedU0_data, unusedU0_size, s_data, s_size,
        V_data, V_size);
    if (A_size[0] < A_size[1]) {
      ns = A_size[0];
      maxmn = A_size[1];
    } else {
      ns = A_size[1];
      maxmn = A_size[0];
    }

    r = 1;
    if (ns > 0) {
      tol = (real_T)maxmn * eps(s_data[0]);
      for (maxmn = 0; maxmn < ns; maxmn++) {
        r += (s_data[maxmn] > tol);
      }
    }

    if (r > ns + 1) {
      emlrtErrorWithMessageIdR2018a(sp, &b_emlrtRTEI,
        "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
    }

    if (r > A_size[1]) {
      r = 1;
      maxmn = 0;
    } else {
      maxmn = A_size[1];
    }

    ns = V_size[0];
    Z_size[0] = V_size[0];
    Z_size_tmp = maxmn - r;
    Z_size[1] = Z_size_tmp + 1;
    for (maxmn = 0; maxmn <= Z_size_tmp; maxmn++) {
      for (i0 = 0; i0 < ns; i0++) {
        Z_data[i0 + ns * maxmn] = V_data[i0 + V_size[0] * ((r + maxmn) - 1)];
      }
    }
  }
}

/* End of code generation (null.c) */
