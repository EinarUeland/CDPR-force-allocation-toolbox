/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pinv.c
 *
 * Code generation for function 'pinv'
 *
 */

/* Include files */
#include <math.h>
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "pinv.h"
#include "eml_int_forloop_overflow_check.h"
#include "svd.h"
#include "pinv_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 19,    /* lineNo */
  "pinv",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 46,  /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 53,  /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 68,  /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 69,  /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 72,  /* lineNo */
  "eml_pinv",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\matfun\\pinv.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 63, /* lineNo */
  "xgemm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 64, /* lineNo */
  "xgemm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemm.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 127,/* lineNo */
  "xgemm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemm.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 134,/* lineNo */
  "xgemm",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemm.m"/* pathName */
};

/* Function Definitions */
void pinv(const emlrtStack *sp, const real_T A[48], real_T X[48])
{
  int32_T vcol;
  boolean_T p;
  int32_T j;
  int32_T br;
  real_T b_A[48];
  real_T b_X[48];
  real_T U[48];
  real_T s[6];
  real_T V[36];
  real_T absxk;
  int32_T exponent;
  int32_T r;
  int32_T ar;
  int32_T ib;
  int32_T ia;
  int32_T b;
  int32_T ic;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  for (vcol = 0; vcol < 6; vcol++) {
    for (j = 0; j < 8; j++) {
      b_A[j + (vcol << 3)] = A[vcol + 6 * j];
    }
  }

  p = true;
  for (br = 0; br < 48; br++) {
    b_X[br] = 0.0;
    if (p && ((!muDoubleScalarIsInf(b_A[br])) && (!muDoubleScalarIsNaN(b_A[br]))))
    {
      p = true;
    } else {
      p = false;
    }
  }

  if (!p) {
    for (vcol = 0; vcol < 48; vcol++) {
      b_X[vcol] = rtNaN;
    }
  } else {
    b_st.site = &b_emlrtRSI;
    svd(&b_st, b_A, U, s, V);
    b_st.site = &c_emlrtRSI;
    absxk = muDoubleScalarAbs(s[0]);
    if ((!muDoubleScalarIsInf(absxk)) && (!muDoubleScalarIsNaN(absxk))) {
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &exponent);
        absxk = ldexp(1.0, exponent - 53);
      }
    } else {
      absxk = rtNaN;
    }

    absxk *= 8.0;
    r = 0;
    br = 0;
    while ((br < 6) && (s[br] > absxk)) {
      r++;
      br++;
    }

    if (r > 0) {
      vcol = 6;
      b_st.site = &d_emlrtRSI;
      if (r > 2147483646) {
        c_st.site = &vb_emlrtRSI;
        check_forloop_overflow_error(&c_st, true);
      }

      for (j = 0; j < r; j++) {
        absxk = 1.0 / s[j];
        b_st.site = &e_emlrtRSI;
        c_st.site = &yb_emlrtRSI;
        d_st.site = &ac_emlrtRSI;
        if ((vcol - 5 <= vcol) && (vcol > 2147483646)) {
          e_st.site = &vb_emlrtRSI;
          check_forloop_overflow_error(&e_st, true);
        }

        for (br = vcol - 5; br <= vcol; br++) {
          V[br - 1] *= absxk;
        }

        vcol += 6;
      }

      b_st.site = &f_emlrtRSI;
      c_st.site = &jc_emlrtRSI;
      for (exponent = 0; exponent <= 42; exponent += 6) {
        vcol = exponent + 1;
        j = exponent + 6;
        d_st.site = &kc_emlrtRSI;
        if (vcol <= j) {
          memset(&b_X[vcol + -1], 0, (uint32_T)(((j - vcol) + 1) * (int32_T)
                  sizeof(real_T)));
        }
      }

      br = 0;
      for (exponent = 0; exponent <= 42; exponent += 6) {
        ar = -1;
        br++;
        j = br + ((r - 1) << 3);
        d_st.site = &lc_emlrtRSI;
        if ((br <= j) && (j > 2147483639)) {
          e_st.site = &vb_emlrtRSI;
          check_forloop_overflow_error(&e_st, true);
        }

        for (ib = br; ib <= j; ib += 8) {
          ia = ar;
          vcol = exponent + 1;
          b = exponent + 6;
          d_st.site = &mc_emlrtRSI;
          for (ic = vcol; ic <= b; ic++) {
            ia++;
            b_X[ic - 1] += U[ib - 1] * V[ia];
          }

          ar += 6;
        }
      }
    }
  }

  for (vcol = 0; vcol < 6; vcol++) {
    for (j = 0; j < 8; j++) {
      X[j + (vcol << 3)] = b_X[vcol + 6 * j];
    }
  }
}

/* End of code generation (pinv.c) */
