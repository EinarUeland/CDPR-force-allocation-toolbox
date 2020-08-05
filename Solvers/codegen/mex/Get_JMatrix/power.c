/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Get_JMatrix.h"
#include "power.h"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = { 55,  /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 64,  /* lineNo */
  "fltpower",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 65,  /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 188, /* lineNo */
  "flatIter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 124, /* lineNo */
  "scalar_float_power",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRTEInfo g_emlrtRTEI = { 12,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 67,/* lineNo */
  5,                                   /* colNo */
  "fltpower",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2019a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

/* Function Definitions */
void b_power(const emlrtStack *sp, const real_T a_data[], const int32_T a_size[2],
             real_T y_data[], int32_T y_size[2])
{
  int32_T nx;
  int32_T k;
  boolean_T p;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &l_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &m_emlrtRSI;
  y_size[0] = 1;
  y_size[1] = (int8_T)a_size[1];
  c_st.site = &n_emlrtRSI;
  nx = (int8_T)a_size[1];
  for (k = 0; k < nx; k++) {
    d_st.site = &o_emlrtRSI;
    e_st.site = &p_emlrtRSI;
    if (a_data[k] < 0.0) {
      emlrtErrorWithMessageIdR2018a(&e_st, &g_emlrtRTEI,
        "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
        4, "sqrt");
    }

    y_data[k] = muDoubleScalarSqrt(a_data[k]);
  }

  if (a_size[1] == 1) {
    p = (a_data[0] < 0.0);
  } else {
    nx = a_size[1];
    p = false;
    for (k = 0; k < nx; k++) {
      if (p || (a_data[k] < 0.0)) {
        p = true;
      } else {
        p = false;
      }
    }
  }

  if (p) {
    emlrtErrorWithMessageIdR2018a(&st, &h_emlrtRTEI,
      "Coder:toolbox:power_domainError", "Coder:toolbox:power_domainError", 0);
  }
}

void power(const real_T a_data[], const int32_T a_size[2], real_T y_data[],
           int32_T y_size[2])
{
  int32_T nx;
  int32_T k;
  y_size[0] = 3;
  y_size[1] = (int8_T)a_size[1];
  nx = 3 * (int8_T)a_size[1];
  for (k = 0; k < nx; k++) {
    y_data[k] = a_data[k] * a_data[k];
  }
}

/* End of code generation (power.c) */
