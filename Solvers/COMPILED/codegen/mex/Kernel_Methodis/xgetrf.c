/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgetrf.c
 *
 * Code generation for function 'xgetrf'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Kernel_Methodis.h"
#include "xgetrf.h"
#include "Kernel_Methodis_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo dc_emlrtRSI = { 27, /* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 90, /* lineNo */
  "ceval_xgetrf",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 82, /* lineNo */
  "ceval_xgetrf",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 78, /* lineNo */
  "ceval_xgetrf",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 58, /* lineNo */
  "ceval_xgetrf",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 57, /* lineNo */
  "ceval_xgetrf",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 50, /* lineNo */
  "ceval_xgetrf",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtMCInfo b_emlrtMCI = { 46,  /* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRSInfo ee_emlrtRSI = { 46, /* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

/* Function Declarations */
static void c_error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location);

/* Function Definitions */
static void c_error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

void xgetrf(const emlrtStack *sp, int32_T m, int32_T n, real_T A_data[], int32_T
            A_size[2], int32_T lda, int32_T ipiv_data[], int32_T ipiv_size[2],
            int32_T *info)
{
  int32_T i11;
  int32_T varargin_1;
  const mxArray *y;
  const mxArray *m16;
  static const int32_T iv14[2] = { 1, 15 };

  static const char_T u[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm', 'a',
    'x', 's', 'i', 'z', 'e' };

  ptrdiff_t info_t;
  ptrdiff_t ipiv_t_data[24];
  static const char_T fname[19] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'g', 'e', 't', 'r', 'f', '_', 'w', 'o', 'r', 'k' };

  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &dc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &jc_emlrtRSI;
  if ((A_size[0] == 0) || (A_size[1] == 0)) {
    ipiv_size[0] = 1;
    ipiv_size[1] = 0;
    *info = 0;
  } else {
    b_st.site = &ic_emlrtRSI;
    i11 = muIntScalarMin_sint32(m, n);
    varargin_1 = muIntScalarMax_sint32(i11, 1);
    b_st.site = &ic_emlrtRSI;
    if ((int8_T)varargin_1 != varargin_1) {
      y = NULL;
      m16 = emlrtCreateCharArray(2, iv14);
      emlrtInitCharArrayR2013a(&b_st, 15, m16, &u[0]);
      emlrtAssign(&y, m16);
      c_st.site = &ee_emlrtRSI;
      c_error(&c_st, y, &b_emlrtMCI);
    }

    b_st.site = &hc_emlrtRSI;
    b_st.site = &gc_emlrtRSI;
    b_st.site = &fc_emlrtRSI;
    info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)m, (ptrdiff_t)n, &A_data[0],
      (ptrdiff_t)lda, &ipiv_t_data[0]);
    *info = (int32_T)info_t;
    ipiv_size[0] = 1;
    ipiv_size[1] = (int8_T)varargin_1;
    b_st.site = &ec_emlrtRSI;
    if (*info < 0) {
      if (*info == -1010) {
        emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI, "MATLAB:nomem",
          "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
          "Coder:toolbox:LAPACKCallErrorInfo",
          "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 19, fname, 12, *info);
      }
    }

    varargin_1 = (int8_T)varargin_1 - 1;
    for (k = 0; k <= varargin_1; k++) {
      ipiv_data[k] = (int32_T)ipiv_t_data[k];
    }
  }
}

/* End of code generation (xgetrf.c) */
