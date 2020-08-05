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
#include "pinv.h"
#include "svd.h"
#include "xaxpy.h"
#include "xrotg.h"
#include "xrot.h"
#include "sqrt.h"
#include "xswap.h"
#include "xscal.h"
#include "xdotc.h"
#include "xnrm2.h"

/* Variable Definitions */
static emlrtRSInfo g_emlrtRSI = { 53,  /* lineNo */
  "svd",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 101, /* lineNo */
  "callLAPACK",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 31,  /* lineNo */
  "xgesvd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgesvd.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 73,  /* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 90,  /* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 110, /* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 180, /* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 211,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 236,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 247,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 376,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 424,/* lineNo */
  "xzsvdc",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 265, /* lineNo */
  13,                                  /* colNo */
  "xzsvdc",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzsvdc.m"/* pName */
};

/* Function Definitions */
void svd(const emlrtStack *sp, const real_T A[48], real_T U[48], real_T s[6],
         real_T V[36])
{
  real_T b_A[48];
  int32_T i;
  real_T work[8];
  real_T b_s[6];
  real_T e[6];
  real_T Vf[36];
  int32_T q;
  int32_T m;
  int32_T qp1;
  int32_T qp1jj;
  int32_T qq_tmp;
  int32_T qq;
  boolean_T apply_transform;
  real_T nrm;
  int32_T iter;
  int32_T k;
  real_T snorm;
  real_T rt;
  boolean_T exitg1;
  int32_T exitg2;
  boolean_T exitg3;
  real_T scale;
  real_T sm;
  real_T sqds;
  real_T b;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &g_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &h_emlrtRSI;
  c_st.site = &i_emlrtRSI;
  memcpy(&b_A[0], &A[0], 48U * sizeof(real_T));
  for (i = 0; i < 6; i++) {
    b_s[i] = 0.0;
    e[i] = 0.0;
  }

  memset(&work[0], 0, sizeof(real_T) << 3);
  memset(&U[0], 0, 48U * sizeof(real_T));
  memset(&Vf[0], 0, 36U * sizeof(real_T));
  for (q = 0; q < 6; q++) {
    qp1 = q + 2;
    qp1jj = q << 3;
    qq_tmp = q + qp1jj;
    qq = qq_tmp + 1;
    apply_transform = false;
    d_st.site = &j_emlrtRSI;
    nrm = xnrm2(&d_st, 8 - q, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq - 1] < 0.0) {
        nrm = -nrm;
      }

      b_s[q] = nrm;
      if (muDoubleScalarAbs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        i = (qq - q) + 7;
        for (k = qq; k <= i; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        i = (qq - q) + 7;
        for (k = qq; k <= i; k++) {
          b_A[k - 1] /= b_s[q];
        }
      }

      b_A[qq - 1]++;
      b_s[q] = -b_s[q];
    } else {
      b_s[q] = 0.0;
    }

    for (iter = qp1; iter < 7; iter++) {
      i = q + ((iter - 1) << 3);
      if (apply_transform) {
        d_st.site = &m_emlrtRSI;
        nrm = xdotc(&d_st, 8 - q, b_A, qq, b_A, i + 1);
        nrm = -(nrm / b_A[qq_tmp]);
        xaxpy(8 - q, nrm, qq, b_A, i + 1);
      }

      e[iter - 1] = b_A[i];
    }

    for (k = q + 1; k < 9; k++) {
      i = (k + qp1jj) - 1;
      U[i] = b_A[i];
    }

    if (q + 1 <= 4) {
      d_st.site = &p_emlrtRSI;
      nrm = b_xnrm2(&d_st, 5 - q, e, q + 2);
      if (nrm == 0.0) {
        e[q] = 0.0;
      } else {
        if (e[q + 1] < 0.0) {
          e[q] = -nrm;
        } else {
          e[q] = nrm;
        }

        nrm = e[q];
        if (muDoubleScalarAbs(e[q]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[q];
          for (k = qp1; k < 7; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 7; k++) {
            e[k - 1] /= nrm;
          }
        }

        e[q + 1]++;
        e[q] = -e[q];
        for (k = qp1; k < 9; k++) {
          work[k - 1] = 0.0;
        }

        for (iter = qp1; iter < 7; iter++) {
          b_xaxpy(7 - q, e[iter - 1], b_A, (q + ((iter - 1) << 3)) + 2, work, q
                  + 2);
        }

        for (iter = qp1; iter < 7; iter++) {
          c_xaxpy(7 - q, -e[iter - 1] / e[q + 1], work, q + 2, b_A, (q + ((iter
                     - 1) << 3)) + 2);
        }
      }

      for (k = qp1; k < 7; k++) {
        Vf[(k + 6 * q) - 1] = e[k - 1];
      }
    }
  }

  m = 4;
  e[4] = b_A[44];
  e[5] = 0.0;
  for (q = 5; q >= 0; q--) {
    qp1 = q + 2;
    qq_tmp = q << 3;
    qq = q + qq_tmp;
    if (b_s[q] != 0.0) {
      for (iter = qp1; iter < 7; iter++) {
        i = (q + ((iter - 1) << 3)) + 1;
        d_st.site = &y_emlrtRSI;
        nrm = xdotc(&d_st, 8 - q, U, qq + 1, U, i);
        nrm = -(nrm / U[qq]);
        xaxpy(8 - q, nrm, qq + 1, U, i);
      }

      for (k = q + 1; k < 9; k++) {
        i = (k + qq_tmp) - 1;
        U[i] = -U[i];
      }

      U[qq]++;
      for (k = 0; k < q; k++) {
        U[k + qq_tmp] = 0.0;
      }
    } else {
      memset(&U[q << 3], 0, sizeof(real_T) << 3);
      U[qq] = 1.0;
    }
  }

  for (q = 5; q >= 0; q--) {
    if ((q + 1 <= 4) && (e[q] != 0.0)) {
      qp1 = q + 2;
      i = (q + 6 * q) + 2;
      for (iter = qp1; iter < 7; iter++) {
        qp1jj = (q + 6 * (iter - 1)) + 2;
        d_st.site = &eb_emlrtRSI;
        nrm = b_xdotc(&d_st, 5 - q, Vf, i, Vf, qp1jj);
        nrm = -(nrm / Vf[i - 1]);
        d_xaxpy(5 - q, nrm, i, Vf, qp1jj);
      }
    }

    for (k = 0; k < 6; k++) {
      Vf[k + 6 * q] = 0.0;
    }

    Vf[q + 6 * q] = 1.0;
  }

  for (q = 0; q < 6; q++) {
    if (b_s[q] != 0.0) {
      rt = muDoubleScalarAbs(b_s[q]);
      nrm = b_s[q] / rt;
      b_s[q] = rt;
      if (q + 1 < 6) {
        e[q] /= nrm;
      }

      d_st.site = &gb_emlrtRSI;
      xscal(&d_st, nrm, U, 1 + (q << 3));
    }

    if ((q + 1 < 6) && (e[q] != 0.0)) {
      rt = muDoubleScalarAbs(e[q]);
      nrm = rt / e[q];
      e[q] = rt;
      b_s[q + 1] *= nrm;
      d_st.site = &hb_emlrtRSI;
      b_xscal(&d_st, nrm, Vf, 1 + 6 * (q + 1));
    }
  }

  iter = 0;
  snorm = 0.0;
  for (k = 0; k < 6; k++) {
    snorm = muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(b_s[k]),
      muDoubleScalarAbs(e[k])));
  }

  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (iter >= 75) {
      emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
        "Coder:MATLAB:svd_NoConvergence", "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      k = m;
      do {
        exitg2 = 0;
        q = k + 1;
        if (k + 1 == 0) {
          exitg2 = 1;
        } else {
          nrm = muDoubleScalarAbs(e[k]);
          if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(b_s[k]) +
                muDoubleScalarAbs(b_s[k + 1]))) || (nrm <=
               1.0020841800044864E-292) || ((iter > 20) && (nrm <=
                2.2204460492503131E-16 * snorm))) {
            e[k] = 0.0;
            exitg2 = 1;
          } else {
            k--;
          }
        }
      } while (exitg2 == 0);

      if (k + 1 == m + 1) {
        i = 4;
      } else {
        qp1jj = m + 2;
        i = m + 2;
        exitg3 = false;
        while ((!exitg3) && (i >= k + 1)) {
          qp1jj = i;
          if (i == k + 1) {
            exitg3 = true;
          } else {
            nrm = 0.0;
            if (i < m + 2) {
              nrm = muDoubleScalarAbs(e[i - 1]);
            }

            if (i > k + 2) {
              nrm += muDoubleScalarAbs(e[i - 2]);
            }

            rt = muDoubleScalarAbs(b_s[i - 1]);
            if ((rt <= 2.2204460492503131E-16 * nrm) || (rt <=
                 1.0020841800044864E-292)) {
              b_s[i - 1] = 0.0;
              exitg3 = true;
            } else {
              i--;
            }
          }
        }

        if (qp1jj == k + 1) {
          i = 3;
        } else if (qp1jj == m + 2) {
          i = 1;
        } else {
          i = 2;
          q = qp1jj;
        }
      }

      switch (i) {
       case 1:
        rt = e[m];
        e[m] = 0.0;
        i = m + 1;
        for (k = i; k >= q + 1; k--) {
          xrotg(&b_s[k - 1], &rt, &sm, &sqds);
          if (k > q + 1) {
            rt = -sqds * e[k - 2];
            e[k - 2] *= sm;
          }

          xrot(Vf, 1 + 6 * (k - 1), 1 + 6 * (m + 1), sm, sqds);
        }
        break;

       case 2:
        rt = e[q - 1];
        e[q - 1] = 0.0;
        for (k = q + 1; k <= m + 2; k++) {
          xrotg(&b_s[k - 1], &rt, &sm, &sqds);
          b = e[k - 1];
          rt = -sqds * b;
          e[k - 1] = b * sm;
          b_xrot(U, 1 + ((k - 1) << 3), 1 + ((q - 1) << 3), sm, sqds);
        }
        break;

       case 3:
        i = m + 1;
        nrm = b_s[m + 1];
        scale = muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarMax
          (muDoubleScalarMax(muDoubleScalarAbs(nrm), muDoubleScalarAbs(b_s[m])),
           muDoubleScalarAbs(e[m])), muDoubleScalarAbs(b_s[q])),
          muDoubleScalarAbs(e[q]));
        sm = nrm / scale;
        nrm = b_s[m] / scale;
        rt = e[m] / scale;
        sqds = b_s[q] / scale;
        b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
        nrm = sm * rt;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          rt = b * b + nrm;
          d_st.site = &ob_emlrtRSI;
          b_sqrt(&d_st, &rt);
          if (b < 0.0) {
            rt = -rt;
          }

          rt = nrm / (b + rt);
        } else {
          rt = 0.0;
        }

        rt += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[q] / scale);
        for (k = q + 1; k <= i; k++) {
          xrotg(&rt, &nrm, &sm, &sqds);
          if (k > q + 1) {
            e[k - 2] = rt;
          }

          b = e[k - 1];
          nrm = b_s[k - 1];
          e[k - 1] = sm * b - sqds * nrm;
          rt = sqds * b_s[k];
          b_s[k] *= sm;
          xrot(Vf, 1 + 6 * (k - 1), 1 + 6 * k, sm, sqds);
          b_s[k - 1] = sm * nrm + sqds * b;
          xrotg(&b_s[k - 1], &rt, &sm, &sqds);
          b = e[k - 1];
          rt = sm * b + sqds * b_s[k];
          b_s[k] = -sqds * b + sm * b_s[k];
          nrm = sqds * e[k];
          e[k] *= sm;
          b_xrot(U, 1 + ((k - 1) << 3), 1 + (k << 3), sm, sqds);
        }

        e[m] = rt;
        iter++;
        break;

       default:
        if (b_s[q] < 0.0) {
          b_s[q] = -b_s[q];
          d_st.site = &sb_emlrtRSI;
          b_xscal(&d_st, -1.0, Vf, 1 + 6 * q);
        }

        qp1 = q + 1;
        while ((q + 1 < 6) && (b_s[q] < b_s[qp1])) {
          rt = b_s[q];
          b_s[q] = b_s[qp1];
          b_s[qp1] = rt;
          xswap(Vf, 1 + 6 * q, 1 + 6 * (q + 1));
          b_xswap(U, 1 + (q << 3), 1 + ((q + 1) << 3));
          q = qp1;
          qp1++;
        }

        iter = 0;
        m--;
        break;
      }
    }
  }

  for (k = 0; k < 6; k++) {
    s[k] = b_s[k];
    for (i = 0; i < 6; i++) {
      qp1jj = i + 6 * k;
      V[qp1jj] = Vf[qp1jj];
    }
  }
}

/* End of code generation (svd.c) */
