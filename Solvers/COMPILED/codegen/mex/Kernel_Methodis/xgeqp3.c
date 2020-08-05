/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgeqp3.c
 *
 * Code generation for function 'xgeqp3'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Kernel_Methodis.h"
#include "xgeqp3.h"
#include "Kernel_Methodis_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo vc_emlrtRSI = { 14, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo bd_emlrtRSI = { 76, /* lineNo */
  "ceval_xgeqp3",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

/* Function Definitions */
void xgeqp3(const emlrtStack *sp, real_T A_data[], int32_T A_size[2], real_T
            tau_data[], int32_T tau_size[1], int32_T jpvt_data[], int32_T
            jpvt_size[2])
{
  int32_T m;
  int32_T n;
  int32_T tau_size_tmp;
  int32_T jpvt_t_size_idx_0;
  int32_T loop_ub;
  int32_T i12;
  ptrdiff_t jpvt_t_data[24];
  ptrdiff_t m_t;
  ptrdiff_t info_t;
  boolean_T p;
  boolean_T b_p;
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'g', 'e', 'q', 'p', '3' };

  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  m = A_size[0];
  n = A_size[1];
  if ((A_size[0] == 0) || (A_size[1] == 0)) {
    tau_size[0] = 0;
    if (A_size[1] < 1) {
      n = 0;
    } else {
      n = A_size[1];
    }

    jpvt_size[0] = 1;
    jpvt_size[1] = n;
    if (n > 0) {
      jpvt_data[0] = 1;
      m = 1;
      for (jpvt_t_size_idx_0 = 2; jpvt_t_size_idx_0 <= n; jpvt_t_size_idx_0++) {
        m++;
        jpvt_data[jpvt_t_size_idx_0 - 1] = m;
      }
    }
  } else {
    tau_size_tmp = muIntScalarMin_sint32(m, n);
    tau_size[0] = tau_size_tmp;
    jpvt_t_size_idx_0 = A_size[1];
    loop_ub = A_size[1];
    for (i12 = 0; i12 < loop_ub; i12++) {
      jpvt_t_data[i12] = (ptrdiff_t)0;
    }

    m_t = (ptrdiff_t)A_size[0];
    info_t = LAPACKE_dgeqp3(102, m_t, (ptrdiff_t)A_size[1], &A_data[0], m_t,
      &jpvt_t_data[0], &tau_data[0]);
    m = (int32_T)info_t;
    b_st.site = &bd_emlrtRSI;
    if (m != 0) {
      p = true;
      b_p = false;
      if (m == -4) {
        b_p = true;
      }

      if (!b_p) {
        if (m == -1010) {
          emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI, "MATLAB:nomem",
            "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
            "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, m);
        }
      }
    } else {
      p = false;
    }

    if (p) {
      loop_ub = A_size[1];
      for (i12 = 0; i12 < loop_ub; i12++) {
        m = A_size[0];
        for (jpvt_t_size_idx_0 = 0; jpvt_t_size_idx_0 < m; jpvt_t_size_idx_0++)
        {
          A_data[jpvt_t_size_idx_0 + A_size[0] * i12] = rtNaN;
        }
      }

      for (i12 = 0; i12 < tau_size_tmp; i12++) {
        tau_data[i12] = rtNaN;
      }

      if (n < 1) {
        n = 0;
      }

      jpvt_size[0] = 1;
      jpvt_size[1] = n;
      if (n > 0) {
        jpvt_data[0] = 1;
        m = 1;
        for (jpvt_t_size_idx_0 = 2; jpvt_t_size_idx_0 <= n; jpvt_t_size_idx_0++)
        {
          m++;
          jpvt_data[jpvt_t_size_idx_0 - 1] = m;
        }
      }
    } else {
      jpvt_size[0] = 1;
      jpvt_size[1] = jpvt_t_size_idx_0;
      for (i12 = 0; i12 < jpvt_t_size_idx_0; i12++) {
        jpvt_data[i12] = (int32_T)jpvt_t_data[i12];
      }
    }
  }
}

/* End of code generation (xgeqp3.c) */
