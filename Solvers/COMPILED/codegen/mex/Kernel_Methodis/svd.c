/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * svd.c
 *
 * Code generation for function 'svd'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Kernel_Methodis.h"
#include "svd.h"
#include "xgesvd.h"
#include "Kernel_Methodis_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo cb_emlrtRSI = { 53, /* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 78, /* lineNo */
  "callLAPACK",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 83, /* lineNo */
  "callLAPACK",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 205,/* lineNo */
  "xgesdd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgesdd.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 28, /* lineNo */
  "xgesvd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgesvd.m"/* pathName */
};

static emlrtRTEInfo e_emlrtRTEI = { 105,/* lineNo */
  5,                                   /* colNo */
  "callLAPACK",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pName */
};

/* Function Definitions */
void svd(const emlrtStack *sp, const real_T A_data[], const int32_T A_size[2],
         real_T U_data[], int32_T U_size[2], real_T s_data[], int32_T s_size[1],
         real_T V_data[], int32_T V_size[2])
{
  int32_T loop_ub_tmp;
  real_T b_A_data[144];
  int32_T info;
  int32_T b_A_size[2];
  int32_T i1;
  int32_T loop_ub;
  int32_T i2;
  real_T Vt_data[576];
  real_T Utmp_data[36];
  ptrdiff_t info_t;
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'g', 'e', 's', 'd', 'd' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &db_emlrtRSI;
  loop_ub_tmp = A_size[0] * A_size[1];
  if (0 <= loop_ub_tmp - 1) {
    memcpy(&b_A_data[0], &A_data[0], (uint32_T)(loop_ub_tmp * (int32_T)sizeof
            (real_T)));
  }

  s_size[0] = muIntScalarMin_sint32(A_size[1], A_size[0]);
  if ((A_size[0] != 0) && (A_size[1] != 0)) {
    info_t = LAPACKE_dgesdd(102, 'A', (ptrdiff_t)A_size[0], (ptrdiff_t)A_size[1],
      &b_A_data[0], (ptrdiff_t)A_size[0], &s_data[0], &Utmp_data[0], (ptrdiff_t)
      A_size[0], &Vt_data[0], (ptrdiff_t)A_size[1]);
    info = (int32_T)info_t;
    c_st.site = &fb_emlrtRSI;
    if (info < 0) {
      if (info == -1010) {
        emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI, "MATLAB:nomem",
          "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
          "Coder:toolbox:LAPACKCallErrorInfo",
          "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, info);
      }
    }
  } else {
    info = 0;
  }

  if (info > 0) {
    b_st.site = &eb_emlrtRSI;
    b_A_size[0] = A_size[0];
    b_A_size[1] = A_size[1];
    if (0 <= loop_ub_tmp - 1) {
      memcpy(&b_A_data[0], &A_data[0], (uint32_T)(loop_ub_tmp * (int32_T)sizeof
              (real_T)));
    }

    c_st.site = &nb_emlrtRSI;
    ceval_xgesvd(&c_st, b_A_data, b_A_size, U_data, U_size, s_data, s_size,
                 V_data, V_size, &info);
  } else {
    V_size[0] = A_size[1];
    V_size[1] = A_size[1];
    loop_ub_tmp = A_size[1];
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      loop_ub = A_size[1];
      for (i2 = 0; i2 < loop_ub; i2++) {
        V_data[i2 + V_size[0] * i1] = Vt_data[i1 + A_size[1] * i2];
      }
    }

    U_size[0] = (int8_T)A_size[0];
    loop_ub_tmp = (int8_T)muIntScalarMin_sint32(A_size[0], A_size[1]);
    U_size[1] = loop_ub_tmp;
    i1 = (int8_T)A_size[0] * loop_ub_tmp;
    if (0 <= i1 - 1) {
      memcpy(&U_data[0], &Utmp_data[0], (uint32_T)(i1 * (int32_T)sizeof(real_T)));
    }
  }

  if (info > 0) {
    emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
      "Coder:MATLAB:svd_NoConvergence", "Coder:MATLAB:svd_NoConvergence", 0);
  }
}

/* End of code generation (svd.c) */
