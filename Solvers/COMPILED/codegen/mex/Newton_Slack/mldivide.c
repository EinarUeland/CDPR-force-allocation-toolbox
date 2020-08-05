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
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Newton_Slack.h"
#include "mldivide.h"
#include "warning.h"
#include "eml_int_forloop_overflow_check.h"

/* Variable Definitions */
static emlrtRSInfo n_emlrtRSI = { 20,  /* lineNo */
  "mldivide",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 42,  /* lineNo */
  "mldiv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 67,  /* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 109, /* lineNo */
  "lusolveNxN",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 107, /* lineNo */
  "lusolveNxN",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 150, /* lineNo */
  "lusolveNxN",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 152, /* lineNo */
  "lusolveNxN",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 30,  /* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 36,  /* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 50,  /* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 58,  /* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 23,  /* lineNo */
  "ixamax",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\ixamax.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 24, /* lineNo */
  "ixamax",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\ixamax.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 21, /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 45, /* lineNo */
  "xgeru",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 45, /* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 15, /* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xger.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 41, /* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 54, /* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 90, /* lineNo */
  "warn_singular",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 59, /* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 71, /* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 51, /* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xtrsm.m"/* pathName */
};

/* Function Definitions */
void mldivide(const emlrtStack *sp, const real_T A[100], real_T B[10])
{
  real_T b_A[100];
  int32_T iy;
  int32_T info;
  int8_T ipiv[10];
  int32_T j;
  int32_T b;
  int32_T jj;
  int32_T jp1j;
  int32_T n;
  int32_T jA;
  int32_T ix;
  real_T smax;
  int32_T k;
  real_T s;
  int32_T i;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack k_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &n_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  k_st.prev = &j_st;
  k_st.tls = j_st.tls;
  b_st.site = &o_emlrtRSI;
  c_st.site = &p_emlrtRSI;
  d_st.site = &r_emlrtRSI;
  memcpy(&b_A[0], &A[0], 100U * sizeof(real_T));
  e_st.site = &u_emlrtRSI;
  for (iy = 0; iy < 10; iy++) {
    ipiv[iy] = (int8_T)(1 + iy);
  }

  info = 0;
  for (j = 0; j < 9; j++) {
    b = j * 11;
    jj = j * 11;
    jp1j = b + 2;
    n = 10 - j;
    f_st.site = &v_emlrtRSI;
    g_st.site = &y_emlrtRSI;
    jA = 0;
    ix = b;
    smax = muDoubleScalarAbs(b_A[b]);
    h_st.site = &ab_emlrtRSI;
    for (k = 2; k <= n; k++) {
      ix++;
      s = muDoubleScalarAbs(b_A[ix]);
      if (s > smax) {
        jA = k - 1;
        smax = s;
      }
    }

    if (b_A[jj + jA] != 0.0) {
      if (jA != 0) {
        iy = j + jA;
        ipiv[j] = (int8_T)(iy + 1);
        ix = j;
        for (k = 0; k < 10; k++) {
          smax = b_A[ix];
          b_A[ix] = b_A[iy];
          b_A[iy] = smax;
          ix += 10;
          iy += 10;
        }
      }

      jA = (jj - j) + 10;
      f_st.site = &w_emlrtRSI;
      for (i = jp1j; i <= jA; i++) {
        b_A[i - 1] /= b_A[jj];
      }
    } else {
      info = j + 1;
    }

    n = 8 - j;
    iy = b + 10;
    f_st.site = &x_emlrtRSI;
    g_st.site = &cb_emlrtRSI;
    h_st.site = &db_emlrtRSI;
    i_st.site = &eb_emlrtRSI;
    jA = jj + 12;
    j_st.site = &fb_emlrtRSI;
    for (i = 0; i <= n; i++) {
      smax = b_A[iy];
      if (b_A[iy] != 0.0) {
        ix = jj + 1;
        b = (jA - j) + 8;
        j_st.site = &gb_emlrtRSI;
        if ((jA <= b) && (b > 2147483646)) {
          k_st.site = &bb_emlrtRSI;
          check_forloop_overflow_error(&k_st, true);
        }

        for (jp1j = jA; jp1j <= b; jp1j++) {
          b_A[jp1j - 1] += b_A[ix] * -smax;
          ix++;
        }
      }

      iy += 10;
      jA += 10;
    }
  }

  if ((info == 0) && (!(b_A[99] != 0.0))) {
    info = 10;
  }

  if (info > 0) {
    d_st.site = &q_emlrtRSI;
    e_st.site = &hb_emlrtRSI;
    warning(&e_st);
  }

  for (jA = 0; jA < 9; jA++) {
    if (ipiv[jA] != jA + 1) {
      smax = B[jA];
      iy = ipiv[jA] - 1;
      B[jA] = B[iy];
      B[iy] = smax;
    }
  }

  d_st.site = &s_emlrtRSI;
  e_st.site = &ib_emlrtRSI;
  for (k = 0; k < 10; k++) {
    iy = 10 * k;
    if (B[k] != 0.0) {
      f_st.site = &jb_emlrtRSI;
      for (i = k + 2; i < 11; i++) {
        B[i - 1] -= B[k] * b_A[(i + iy) - 1];
      }
    }
  }

  d_st.site = &t_emlrtRSI;
  e_st.site = &ib_emlrtRSI;
  for (k = 9; k >= 0; k--) {
    iy = 10 * k;
    if (B[k] != 0.0) {
      B[k] /= b_A[k + iy];
      f_st.site = &kb_emlrtRSI;
      for (i = 0; i < k; i++) {
        B[i] -= B[k] * b_A[i + iy];
      }
    }
  }
}

/* End of code generation (mldivide.c) */
