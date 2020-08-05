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
#include "Newton_Standard.h"
#include "mldivide.h"
#include "warning.h"
#include "eml_int_forloop_overflow_check.h"

/* Variable Definitions */
static emlrtRSInfo g_emlrtRSI = { 20,  /* lineNo */
  "mldivide",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 42,  /* lineNo */
  "mldiv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 67,  /* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 109, /* lineNo */
  "lusolveNxN",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 107, /* lineNo */
  "lusolveNxN",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 150, /* lineNo */
  "lusolveNxN",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 152, /* lineNo */
  "lusolveNxN",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 30,  /* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 36,  /* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 50,  /* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 58,  /* lineNo */
  "xzgetrf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgetrf.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 23,  /* lineNo */
  "ixamax",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\ixamax.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 24,  /* lineNo */
  "ixamax",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\ixamax.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 21,  /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 45,  /* lineNo */
  "xgeru",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 45,  /* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 15,  /* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xger.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 41,  /* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 54,  /* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 90, /* lineNo */
  "warn_singular",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 59, /* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 71, /* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xtrsm.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 51, /* lineNo */
  "xtrsm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xtrsm.m"/* pathName */
};

/* Function Definitions */
void mldivide(const emlrtStack *sp, const real_T A[49], real_T B[7])
{
  real_T b_A[49];
  int32_T jy;
  int32_T info;
  int8_T ipiv[7];
  int32_T j;
  int32_T b_tmp;
  int32_T jp1j;
  int32_T n;
  int32_T iy;
  int32_T ix;
  real_T smax;
  int32_T k;
  real_T s;
  int32_T b;
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
  st.site = &g_emlrtRSI;
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
  b_st.site = &h_emlrtRSI;
  c_st.site = &i_emlrtRSI;
  d_st.site = &k_emlrtRSI;
  memcpy(&b_A[0], &A[0], 49U * sizeof(real_T));
  e_st.site = &n_emlrtRSI;
  for (jy = 0; jy < 7; jy++) {
    ipiv[jy] = (int8_T)(1 + jy);
  }

  info = 0;
  for (j = 0; j < 6; j++) {
    b_tmp = j << 3;
    jp1j = b_tmp + 2;
    n = 7 - j;
    f_st.site = &o_emlrtRSI;
    g_st.site = &r_emlrtRSI;
    jy = 0;
    ix = b_tmp;
    smax = muDoubleScalarAbs(b_A[b_tmp]);
    h_st.site = &s_emlrtRSI;
    for (k = 2; k <= n; k++) {
      ix++;
      s = muDoubleScalarAbs(b_A[ix]);
      if (s > smax) {
        jy = k - 1;
        smax = s;
      }
    }

    if (b_A[b_tmp + jy] != 0.0) {
      if (jy != 0) {
        iy = j + jy;
        ipiv[j] = (int8_T)(iy + 1);
        ix = j;
        for (k = 0; k < 7; k++) {
          smax = b_A[ix];
          b_A[ix] = b_A[iy];
          b_A[iy] = smax;
          ix += 7;
          iy += 7;
        }
      }

      b = (b_tmp - j) + 7;
      f_st.site = &p_emlrtRSI;
      for (iy = jp1j; iy <= b; iy++) {
        b_A[iy - 1] /= b_A[b_tmp];
      }
    } else {
      info = j + 1;
    }

    n = 5 - j;
    jy = b_tmp + 7;
    f_st.site = &q_emlrtRSI;
    g_st.site = &u_emlrtRSI;
    h_st.site = &v_emlrtRSI;
    i_st.site = &w_emlrtRSI;
    iy = b_tmp + 9;
    j_st.site = &x_emlrtRSI;
    for (jp1j = 0; jp1j <= n; jp1j++) {
      smax = b_A[jy];
      if (b_A[jy] != 0.0) {
        ix = b_tmp + 1;
        b = (iy - j) + 5;
        j_st.site = &y_emlrtRSI;
        if ((iy <= b) && (b > 2147483646)) {
          k_st.site = &t_emlrtRSI;
          check_forloop_overflow_error(&k_st, true);
        }

        for (k = iy; k <= b; k++) {
          b_A[k - 1] += b_A[ix] * -smax;
          ix++;
        }
      }

      jy += 7;
      iy += 7;
    }
  }

  if ((info == 0) && (!(b_A[48] != 0.0))) {
    info = 7;
  }

  if (info > 0) {
    d_st.site = &j_emlrtRSI;
    e_st.site = &ab_emlrtRSI;
    warning(&e_st);
  }

  for (iy = 0; iy < 6; iy++) {
    if (ipiv[iy] != iy + 1) {
      smax = B[iy];
      jy = ipiv[iy] - 1;
      B[iy] = B[jy];
      B[jy] = smax;
    }
  }

  d_st.site = &l_emlrtRSI;
  e_st.site = &bb_emlrtRSI;
  for (k = 0; k < 7; k++) {
    jy = 7 * k;
    if (B[k] != 0.0) {
      f_st.site = &cb_emlrtRSI;
      for (iy = k + 2; iy < 8; iy++) {
        B[iy - 1] -= B[k] * b_A[(iy + jy) - 1];
      }
    }
  }

  d_st.site = &m_emlrtRSI;
  e_st.site = &bb_emlrtRSI;
  for (k = 6; k >= 0; k--) {
    jy = 7 * k;
    if (B[k] != 0.0) {
      B[k] /= b_A[k + jy];
      f_st.site = &db_emlrtRSI;
      for (iy = 0; iy < k; iy++) {
        B[iy] -= B[k] * b_A[iy + jy];
      }
    }
  }
}

/* End of code generation (mldivide.c) */
