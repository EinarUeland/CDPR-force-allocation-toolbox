/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * qrsolve.c
 *
 * Code generation for function 'qrsolve'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Kernel_Methodis.h"
#include "qrsolve.h"
#include "eml_int_forloop_overflow_check.h"
#include "warning.h"
#include "_coder_Kernel_Methodis_api.h"
#include "xgeqp3.h"
#include "Kernel_Methodis_mexutil.h"
#include "Kernel_Methodis_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo p_emlrtRSI = { 21,  /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 35, /* lineNo */
  "qrsolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 39, /* lineNo */
  "qrsolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 46, /* lineNo */
  "qrsolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 131,/* lineNo */
  "rankFromQR",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo dd_emlrtRSI = { 130,/* lineNo */
  "rankFromQR",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 79, /* lineNo */
  "LSQFromQR",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo fd_emlrtRSI = { 86, /* lineNo */
  "LSQFromQR",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo gd_emlrtRSI = { 96, /* lineNo */
  "LSQFromQR",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo hd_emlrtRSI = { 31, /* lineNo */
  "xunormqr",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 102,/* lineNo */
  "ceval_xunormqr",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m"/* pathName */
};

static emlrtMCInfo e_emlrtMCI = { 53,  /* lineNo */
  19,                                  /* colNo */
  "flt2str",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m"/* pName */
};

static emlrtRSInfo ge_emlrtRSI = { 53, /* lineNo */
  "flt2str",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m"/* pathName */
};

/* Function Declarations */
static void LSQFromQR(const emlrtStack *sp, const real_T A_data[], const int32_T
                      A_size[2], const real_T tau_data[], const int32_T
                      jpvt_data[], real_T B_data[], int32_T B_size[1], int32_T
                      rankA, real_T Y_data[], int32_T Y_size[1]);
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14]);
static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_sprintf_, const char_T *identifier, char_T y[14]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14]);
static int32_T rankFromQR(const emlrtStack *sp, const real_T A_data[], const
  int32_T A_size[2]);

/* Function Definitions */
static void LSQFromQR(const emlrtStack *sp, const real_T A_data[], const int32_T
                      A_size[2], const real_T tau_data[], const int32_T
                      jpvt_data[], real_T B_data[], int32_T B_size[1], int32_T
                      rankA, real_T Y_data[], int32_T Y_size[1])
{
  int32_T loop_ub;
  int32_T j;
  ptrdiff_t nrc_t;
  int32_T Y_data_tmp;
  int32_T b_Y_data_tmp;
  ptrdiff_t info_t;
  boolean_T p;
  boolean_T b_p;
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'o', 'r', 'm', 'q', 'r' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  Y_size[0] = (int8_T)A_size[1];
  loop_ub = (int8_T)A_size[1];
  if (0 <= loop_ub - 1) {
    memset(&Y_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof(real_T)));
  }

  st.site = &ed_emlrtRSI;
  b_st.site = &hd_emlrtRSI;
  if ((A_size[0] != 0) && (A_size[1] != 0) && (B_size[0] != 0)) {
    nrc_t = (ptrdiff_t)B_size[0];
    info_t = LAPACKE_dormqr(102, 'L', 'T', nrc_t, (ptrdiff_t)1, (ptrdiff_t)
      muIntScalarMin_sint32(A_size[0], A_size[1]), &A_data[0], (ptrdiff_t)
      A_size[0], &tau_data[0], &B_data[0], nrc_t);
    loop_ub = (int32_T)info_t;
    c_st.site = &md_emlrtRSI;
    if (loop_ub != 0) {
      p = true;
      b_p = false;
      if (loop_ub == -7) {
        b_p = true;
      } else if (loop_ub == -9) {
        b_p = true;
      } else {
        if (loop_ub == -10) {
          b_p = true;
        }
      }

      if (!b_p) {
        if (loop_ub == -1010) {
          emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI, "MATLAB:nomem",
            "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
            "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, loop_ub);
        }
      }
    } else {
      p = false;
    }

    if (p) {
      loop_ub = B_size[0];
      for (j = 0; j < loop_ub; j++) {
        B_data[j] = rtNaN;
      }
    }
  }

  st.site = &fd_emlrtRSI;
  if ((1 <= rankA) && (rankA > 2147483646)) {
    b_st.site = &p_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (loop_ub = 0; loop_ub < rankA; loop_ub++) {
    Y_data[jpvt_data[loop_ub] - 1] = B_data[loop_ub];
  }

  for (j = rankA; j >= 1; j--) {
    Y_data_tmp = jpvt_data[j - 1] - 1;
    b_Y_data_tmp = A_size[0] * (j - 1);
    Y_data[Y_data_tmp] /= A_data[(j + b_Y_data_tmp) - 1];
    st.site = &gd_emlrtRSI;
    for (loop_ub = 0; loop_ub <= j - 2; loop_ub++) {
      Y_data[jpvt_data[loop_ub] - 1] -= Y_data[Y_data_tmp] * A_data[loop_ub +
        b_Y_data_tmp];
    }
  }
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14])
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m14;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m14, 2, pArrays, "sprintf", true,
    location);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_sprintf_, const char_T *identifier, char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(a__output_of_sprintf_), &thisId, y);
  emlrtDestroyArray(&a__output_of_sprintf_);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2] = { 1, 14 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 14);
  emlrtDestroyArray(&src);
}

static int32_T rankFromQR(const emlrtStack *sp, const real_T A_data[], const
  int32_T A_size[2])
{
  int32_T r;
  real_T tol;
  int32_T minmn;
  int32_T maxmn;
  const mxArray *y;
  const mxArray *m4;
  static const int32_T iv4[2] = { 1, 6 };

  static const char_T rfmt[6] = { '%', '1', '4', '.', '6', 'e' };

  char_T cv0[14];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  r = 0;
  tol = 0.0;
  if (A_size[0] < A_size[1]) {
    minmn = A_size[0];
    maxmn = A_size[1];
  } else {
    minmn = A_size[1];
    maxmn = A_size[0];
  }

  if (minmn > 0) {
    tol = 2.2204460492503131E-15 * (real_T)maxmn * muDoubleScalarAbs(A_data[0]);
    while ((r < minmn) && (!(muDoubleScalarAbs(A_data[r + A_size[0] * r]) <= tol)))
    {
      r++;
    }
  }

  if (r < minmn) {
    st.site = &cd_emlrtRSI;
    y = NULL;
    m4 = emlrtCreateCharArray(2, iv4);
    emlrtInitCharArrayR2013a(&st, 6, m4, &rfmt[0]);
    emlrtAssign(&y, m4);
    b_st.site = &ge_emlrtRSI;
    emlrt_marshallIn(&b_st, b_sprintf(&b_st, y, emlrt_marshallOut(tol),
      &e_emlrtMCI), "<output of sprintf>", cv0);
    st.site = &dd_emlrtRSI;
    b_warning(&st, r, cv0);
  }

  return r;
}

void qrsolve(const emlrtStack *sp, const real_T A_data[], const int32_T A_size[2],
             const real_T B_data[], const int32_T B_size[1], real_T Y_data[],
             int32_T Y_size[1])
{
  int32_T b_A_size[2];
  int32_T rankR;
  real_T b_A_data[576];
  real_T tau_data[24];
  int32_T tau_size[1];
  int32_T jpvt_data[24];
  int32_T jpvt_size[2];
  int32_T b_B_size[1];
  real_T b_B_data[24];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_A_size[0] = A_size[0];
  b_A_size[1] = A_size[1];
  rankR = A_size[0] * A_size[1];
  if (0 <= rankR - 1) {
    memcpy(&b_A_data[0], &A_data[0], (uint32_T)(rankR * (int32_T)sizeof(real_T)));
  }

  st.site = &sc_emlrtRSI;
  xgeqp3(&st, b_A_data, b_A_size, tau_data, tau_size, jpvt_data, jpvt_size);
  st.site = &tc_emlrtRSI;
  rankR = rankFromQR(&st, b_A_data, b_A_size);
  b_B_size[0] = B_size[0];
  if (0 <= B_size[0] - 1) {
    memcpy(&b_B_data[0], &B_data[0], (uint32_T)(B_size[0] * (int32_T)sizeof
            (real_T)));
  }

  st.site = &uc_emlrtRSI;
  LSQFromQR(&st, b_A_data, b_A_size, tau_data, jpvt_data, b_B_data, b_B_size,
            rankR, Y_data, Y_size);
}

/* End of code generation (qrsolve.c) */
